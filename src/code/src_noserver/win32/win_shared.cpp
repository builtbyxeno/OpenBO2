#include "types.h"
#include "vars.h"

#include <timeapi.h>

int sys_timeBase;
int initialized_1;

/*
==============
Sys_Milliseconds
==============
*/
DWORD Sys_Milliseconds()
{
	if (!initialized_1)
	{
		sys_timeBase = timeGetTime();
		initialized_1 = 1;
	}
	return timeGetTime() - sys_timeBase;
}

/*
==============
Sys_MillisecondsRaw
==============
*/
DWORD Sys_MillisecondsRaw()
{
	return timeGetTime();
}

/*
==============
Sys_SnapVector
==============
*/
void Sys_SnapVector(float *v)
{
	v[0] = (float)(int)v[0];
	v[1] = (float)(int)v[1];
	v[2] = (float)(int)v[2];
}

