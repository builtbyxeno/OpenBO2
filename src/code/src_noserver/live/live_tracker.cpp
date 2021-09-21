#include "types.h"
#include "functions.h"

/*
==============
LiveTracker_GetColType
==============
*/
unsigned int LiveTracker_GetColType(trackerColumn_e col)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveTracker_SetItem
==============
*/
int LiveTracker_SetItem(int queuePos, trackerColumn_e col, unsigned __int64 ent, int val)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveTracker_GetColumnByName
==============
*/
int LiveTracker_GetColumnByName(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveTracker_WriteByID
==============
*/
int __cdecl LiveTracker_WriteByID(trackerColumn_e col, unsigned __int64 ent, int val)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveTracker_WriteByName
==============
*/
const StringTable *LiveTracker_WriteByName(const char *colName, unsigned __int64 ent, int val)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveTracker_WriteForAllLocalUsers
==============
*/
BOOL LiveTracker_WriteForAllLocalUsers(trackerColumn_e col, int val)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveTracker_WriteForUserAndHost
==============
*/
BOOL LiveTracker_WriteForUserAndHost(const ControllerIndex_t controllerIndex, trackerColumn_e userCol, trackerColumn_e hostCol, int val)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveTracker_UpdateCmd
==============
*/
void LiveTracker_UpdateCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveTracker_ReportUser
==============
*/
void LiveTracker_ReportUser()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveTracker_StressTestCmd
==============
*/
void LiveTracker_StressTestCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveTracker_Init
==============
*/
void LiveTracker_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

