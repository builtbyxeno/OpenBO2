#include "types.h"
#include "vars.h"
#include <qcommon/qcommon_public.h>

char g_largeLocalBuf[524288];
int g_largeLocalPos;
int g_largeLocalRightPos = 524288;

/*
==============
LargeLocalEnd
==============
*/
void LargeLocalEnd(int startPos)
{
	assert(Sys_IsMainThread());
	g_largeLocalPos = startPos;
	assert(g_largeLocalPos <= g_largeLocalRightPos);
}

/*
==============
LargeLocalEndRight
==============
*/
void LargeLocalEndRight(int startPos)
{
	assert(Sys_IsServerThread());
	g_largeLocalRightPos = startPos;
	assert(g_largeLocalRightPos > g_largeLocalPos);
}

/*
==============
LargeLocal::~LargeLocal
==============
*/
LargeLocal::~LargeLocal()
{
	assert(Sys_IsMainThread() || Sys_IsServerThread());

	if (Sys_IsMainThread())
	{
		LargeLocalEnd(startPos);
	}
	else
	{
		LargeLocalEndRight(startPos);
	}
}

/*
==============
LargeLocalReset
==============
*/
void LargeLocalReset()
{
	assert(Sys_IsMainThread() || Sys_IsServerThread());
	g_largeLocalPos = 0;
	g_largeLocalRightPos = 0x80000;
}

/*
==============
LargeLocalBegin
==============
*/
int LargeLocalBegin(int size)
{
	int startPos;

	assert(Sys_IsMainThread());
	size = LargeLocalRoundSize(size);
	startPos = g_largeLocalPos;
	g_largeLocalPos += size;

	assert(g_largeLocalPos <= static_cast<int>(sizeof(g_largeLocalBuf)));
	assert(g_largeLocalPos <= g_largeLocalRightPos);

	return startPos;
}

/*
==============
LargeLocalRoundSize

==============
*/
unsigned int LargeLocalRoundSize(int size)
{
	return (size + 3) & ~3;
}


/*
==============
LargeLocalBeginRight
==============
*/
int LargeLocalBeginRight(int size)
{
	int startPos;

	assert(Sys_IsServerThread());

	size = LargeLocalRoundSize(size);
	assert(g_largeLocalRightPos - size > g_largeLocalPos);

	startPos = g_largeLocalRightPos;
	g_largeLocalRightPos -= size;

	return startPos;
}

/*
==============
LargeLocalGetBuf
==============
*/
void *LargeLocalGetBuf(int startPos, int size)
{
	int startIndex;

	assert(Sys_IsMainThread() || Sys_IsServerThread());
	if (Sys_IsMainThread())
	{
		return &g_largeLocalBuf[startPos];
	}

	startIndex = startPos - LargeLocalRoundSize(size);
	assert(startIndex >= 0);

	return &g_largeLocalBuf[startIndex];
}

/*
==============
LargeLocal::LargeLocal
==============
*/
LargeLocal::LargeLocal(int sizeParam)
{
	assert(Sys_IsMainThread() || Sys_IsServerThread());
	if (Sys_IsMainThread())
	{
		startPos = LargeLocalBegin(sizeParam);
	}
	else
	{
		startPos = LargeLocalBeginRight(sizeParam);
	}

	size = sizeParam;
}

/*
==============
LargeLocal::GetBuf
==============
*/
void *LargeLocal::GetBuf()
{
	assert(Sys_IsMainThread() || Sys_IsServerThread());
	return LargeLocalGetBuf(startPos, size);
}

