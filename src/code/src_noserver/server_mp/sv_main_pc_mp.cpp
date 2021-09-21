#include "types.h"
#include "functions.h"

/*
==============
SV_GetSlotForPasswordIfFree
==============
*/
int SV_GetSlotForPasswordIfFree(const char *password)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_FreeReservedSlot
==============
*/
void SV_FreeReservedSlot(int slot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_IsServerRanked
==============
*/
bool SV_IsServerRanked(int licensetype)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SVC_RemoteCommand
==============
*/
void SVC_RemoteCommand(netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SetGroupCountsComplete
==============
*/
char SV_SetGroupCountsComplete()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_GetGroupCountsComplete
==============
*/
char SV_GetGroupCountsComplete()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_GroupsFailure
==============
*/
char SV_GroupsFailure()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_IsClientConsole
==============
*/
bool Com_IsClientConsole()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_GetClientPlatform
==============
*/
clientplatform_t Com_GetClientPlatform()
{
	UNIMPLEMENTED(__FUNCTION__);
	clientplatform_t tmp;
	return tmp;
}

/*
==============
SV_SysLog_Init
==============
*/
void SV_SysLog_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SysLog_ForceFlush
==============
*/
void SV_SysLog_ForceFlush()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
enqueueSyslogMessage
==============
*/
void enqueueSyslogMessage(const char *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SysLog_LogMessage
==============
*/
void SV_SysLog_LogMessage(int severity, const char *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SysLog_LogMessage_f
==============
*/
void SV_SysLog_LogMessage_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
checkHandlersAreInited
==============
*/
void checkHandlersAreInited()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
validateAndGetCmd
==============
*/
int validateAndGetCmd(msg_t *pktMsg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_Query_Pump
==============
*/
void SV_Query_Pump(int a1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_Query_SendTo
==============
*/
int SV_Query_SendTo(int a1, unsigned __int8 *payload, int paylen, int cmd, netadr_t *to)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_Perf_GetPerfVals
==============
*/
void SV_Perf_GetPerfVals(unsigned int perfBits, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_Perf_Update
==============
*/
void SV_Perf_Update(perfValType_t perfValType, unsigned int value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
resetPerfCounters
==============
*/
perfVal_t *resetPerfCounters()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_Perf_Frame
==============
*/
void SV_Perf_Frame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SVC_Perf
==============
*/
char SVC_Perf(int a1, netadr_t from, msg_t *payload)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_AutoShutdown_Init
==============
*/
void SV_AutoShutdown_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_AutoShutdown_Frame
==============
*/
void SV_AutoShutdown_Frame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_MarkServerForShutdown
==============
*/
void SV_MarkServerForShutdown()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_GetLicenseType
==============
*/
int SV_GetLicenseType()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_GetGroupCounts
==============
*/
void SV_GetGroupCounts()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_Groups_ParseGeos
==============
*/
void SV_Groups_ParseGeos(const char *geoblob)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_Query_Init
==============
*/
void SV_Query_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

