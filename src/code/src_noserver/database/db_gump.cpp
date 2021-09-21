#include "types.h"
#include "functions.h"

/*
==============
DB_GumpPrint
==============
*/
void DB_GumpPrint(const char *fmt, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_GumpSizeForBlockIndex
==============
*/
unsigned int DB_GumpSizeForBlockIndex(int bi)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_GetGumpUnused
==============
*/
unsigned int DB_GetGumpUnused(unsigned int budget)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_GumpBeginAlloc
==============
*/
void DB_GumpBeginAlloc(const char *name, unsigned int allocType, EMemTrack memTrack)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_GumpEndAlloc
==============
*/
void DB_GumpEndAlloc(const char *name, unsigned int allocType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_GumpMemAlloc
==============
*/
unsigned __int8 *DB_GumpMemAlloc(unsigned int size, unsigned int blockIndex, unsigned int location, unsigned int allocType, const char *filename)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DB_GumpMemFreeAll
==============
*/
void DB_GumpMemFreeAll()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_GumpShouldFree
==============
*/
bool DB_GumpShouldFree(XBlock *blocks)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_GumpMemFree
==============
*/
void DB_GumpMemFree(unsigned __int8 *data, unsigned int blockIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_GetGumpZoneName
==============
*/
char *DB_GetGumpZoneName(int flags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DB_AllocZoneForSlot
==============
*/
int DB_AllocZoneForSlot(int slot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_FlushGump
==============
*/
void DB_FlushGump(int slot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_FlushGumps
==============
*/
void DB_FlushGumps()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_LoadGump
==============
*/
void DB_LoadGump(const char *fastfileName, unsigned int slot, int sync)
{
	UNIMPLEMENTED(__FUNCTION__);
}

