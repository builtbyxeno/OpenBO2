#include "types.h"
#include "functions.h"

/*
==============
TRACK_sv_main
==============
*/
void TRACK_sv_main()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_ExpandNewlines
==============
*/
char *SV_ExpandNewlines(char *in)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_IsFirstTokenEqual
==============
*/
int SV_IsFirstTokenEqual(const char *str1, const char *str2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_CanReplaceServerCommand
==============
*/
/*int SV_CanReplaceServerCommand@<eax>(const char *a1@<edx>, client_t *client, const char *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
SV_CullIgnorableServerCommands
==============
*/
void SV_CullIgnorableServerCommands(client_t *client)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_AddServerCommand
==============
*/
void SV_AddServerCommand(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SendServerCommand
==============
*/
void SV_SendServerCommand(client_t *cl, svscmd_type type, const char *fmt, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_FindClientByAddress
==============
*/
client_t *SV_FindClientByAddress(netadr_t from, int qport)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SVC_Status
==============
*/
void SVC_Status(netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SVC_Ping
==============
*/
char SVC_Ping(netadr_t from, msg_t *payload)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SVC_Status
==============
*/
char SVC_Status(netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SVC_StatusScoreBoard
==============
*/
/*char SVC_StatusScoreBoard@<al>(const char *a1@<edi>, netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
SVC_ClientUIDs
==============
*/
char SVC_ClientUIDs(netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_ConnectionlessPacket
==============
*/
void SV_ConnectionlessPacket(netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_PacketEvent
==============
*/
void SV_PacketEvent(netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_CalcPings
==============
*/
void SV_CalcPings()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_DoISuckAsHost
==============
*/
bool SV_DoISuckAsHost()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_ReportClientPings
==============
*/
void SV_ReportClientPings()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_UpdateServerBoostingStats
==============
*/
void SV_UpdateServerBoostingStats()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_PrintRateBoostingDebugScores
==============
*/
void SV_PrintRateBoostingDebugScores(bool boostWasEnabled)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_DoISuckSoMuchIShouldQuit
==============
*/
bool SV_DoISuckSoMuchIShouldQuit()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_FreeClientScriptId
==============
*/
void SV_FreeClientScriptId(client_t *cl)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_CheckPaused
==============
*/
int SV_CheckPaused()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_UpdatePerformanceFrame
==============
*/
void SV_UpdatePerformanceFrame(int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_RunFrame
==============
*/
void SV_RunFrame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_RunEventLoop
==============
*/
void SV_RunEventLoop()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_Perf_RecordPings
==============
*/
int SV_Perf_RecordPings()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_InitSnapshot
==============
*/
void SV_InitSnapshot()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_KillLocalServer
==============
*/
void SV_KillLocalServer()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_CheckOverflow
==============
*/
char SV_CheckOverflow()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_PreFrame
==============
*/
void SV_PreFrame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_AllowPackets
==============
*/
void SV_AllowPackets(const bool allow)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_GetAssignedTeam
==============
*/
unsigned int SV_GetAssignedTeam(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_SetAssignedTeam
==============
*/
void SV_SetAssignedTeam(ClientNum_t clientNum, int team)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_GetCustomTeamName
==============
*/
const char *SV_GetCustomTeamName(int team)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_Live_RemoveAllClientsFromAddress
==============
*/
void SV_Live_RemoveAllClientsFromAddress(client_t *cl, const char *reason)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_CheckTimeouts
==============
*/
void SV_CheckTimeouts()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_PostFrame
==============
*/
void SV_PostFrame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_WaitServer
==============
*/
void SV_WaitServer()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_FrameInternal
==============
*/
void SV_FrameInternal(ControllerIndex_t controllerIndex, int msec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_Frame
==============
*/
int SV_Frame(ControllerIndex_t controllerIndex, int msec)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_UpdateBots
==============
*/
void SV_UpdateBots()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_ServerThread
==============
*/
void __noreturn SV_ServerThread(unsigned int threadContext)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_InitServerThread
==============
*/
void SV_InitServerThread()
{
	UNIMPLEMENTED(__FUNCTION__);
}

