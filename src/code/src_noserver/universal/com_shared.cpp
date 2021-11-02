#include "types.h"
#include "vars.h"
#include "universal_public.h"

/*
==============
Com_Filter
==============
*/
char Com_Filter(const char *filter, const char *name, int casesensitive)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_FilterPath
==============
*/
char Com_FilterPath(const char *filter, const char *name, int casesensitive)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_HashKey
==============
*/
const char *Com_HashKey(const char *string, int maxlen)
{
	const char* result = string;
	int v3 = 0;

	result = string;
	if (string)
	{
		for (int i = 0; i < maxlen; ++result)
		{
			if (!*result)
				break;

			++i;
			v3 += *result * (DWORD)&result[119 - (DWORD)string];
		}
		
		return (const char*)(v3 ^ ((v3 ^ (v3 >> 10)) >> 10));
	}

	return result;
}

/*
==============
Com_GetQTime
==============
*/
void Com_GetQTime(int time, qtime_s *qtime, bool useLocalTime)
{
	tm* localizedTime;
	__int64 t;

	if (qtime)
	{
		t = time;
		if (useLocalTime)
			localizedTime = _localtime64(&t);
		else
			localizedTime = _gmtime64(&t);
		if (localizedTime)
			*qtime = *(qtime_s*)&localizedTime;
	}
}

/*
==============
Com_RealTime
==============
*/
int Com_RealTime(qtime_s *qtime, bool useLocalTime)
{
	int time;

	time = _time64(0);
	if (qtime)
		Com_GetQTime(time, qtime, useLocalTime);
	return time;
}

/*
==============
Com_Memset
==============
*/
void Com_Memset(void *dest, const int val, int count)
{
	memset(dest, val, count);
}

/*
==============
Com_Memcpy
==============
*/
void Com_Memcpy(void* dest, const void* src, int count)
{
	memcpy(dest, src, count);
}

