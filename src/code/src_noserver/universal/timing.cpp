#include "types.h"
#include "vars.h"

/*
==============
InitTiming
==============
*/
void InitTiming()
{
	LARGE_INTEGER Frequency;

	Sleep(0);
	QueryPerformanceFrequency(&Frequency);
	msecPerRawTimerTick = 1.0 / (double)Frequency.QuadPart * 1000.0;
	Sleep(0);
	QueryPerformanceFrequency(&Frequency);
	usecPerRawTimerTick = 1.0 / (double)Frequency.QuadPart * 1000.0 * 1000.0;
}

/*
==============
NTP_hton
==============
*/
void NTP_hton(const NTPMessage *src, NTPMessage *dest)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NTP_Milliseconds
==============
*/
unsigned __int64 NTP_Milliseconds()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NTP_Sync
==============
*/
char NTP_Sync(const char *server)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

