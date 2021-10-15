#include "types.h"
#include "vars.h"

#pragma comment(lib,"Ws2_32.lib")

#include <win32/win32_public.h>

static bool s_syslogInited;
_RTL_CRITICAL_SECTION s_sysLogCritSec;
static sockaddr_in s_sysLogAddr;
static SOCKET s_syslogSocket;

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
	return (g_clientPlatform - 1) <= 2;
}

/*
==============
Com_GetClientPlatform
==============
*/
clientplatform_t Com_GetClientPlatform()
{
	return g_clientPlatform;
}

/*
==============
SV_SysLog_Init
==============
*/
void SV_SysLog_Init()
{
	int Error;
	const char* String;
	u_short Int;

	if (Dvar_GetBool(sv_syslog_enabled))
	{
		InitializeCriticalSection(&s_sysLogCritSec);
		s_syslogSocket = WSASocket(2, 2, 17, 0, 0, 0);
		if (s_syslogSocket == -1)
		{
			Error = WSAGetLastError();
			Sys_Error("Couldn't open syslog socket - error %u", Error);
		}
		String = Dvar_GetString(sv_syslog_address);
		Int = Dvar_GetInt(sv_syslog_port);
		s_sysLogAddr.sin_family = 2;
		s_sysLogAddr.sin_port = htons(Int);
		s_sysLogAddr.sin_addr.S_un.S_addr = inet_addr(String);
		s_syslogInited = 1;
	}
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
	const char* String;
	char syslogMsg[1264];

	if (s_syslogInited && Dvar_GetBool(sv_syslog_enabled))
	{
		memset(syslogMsg, 0, sizeof(syslogMsg));
		String = Dvar_GetString(sv_hostname);
		Com_sprintf(syslogMsg, 1263, "<%u>%s: %s", severity + 128, String, msg);
		enqueueSyslogMessage(syslogMsg);
	}
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

