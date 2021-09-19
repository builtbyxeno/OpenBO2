#include "types.h"
#include "functions.h"

/*
==============
TRACK_common
==============
*/
void TRACK_common()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_NTPSync_f
==============
*/
void Com_NTPSync_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_IsRunningMenuLevel
==============
*/
bool Com_IsRunningMenuLevel(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_IsMenuLevel
==============
*/
char Com_IsMenuLevel(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_BeginRedirect
==============
*/
void Com_BeginRedirect(char *buffer, unsigned int buffersize, void (*flush)(char *))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_EndRedirect
==============
*/
void Com_EndRedirect()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_OpenLogFile
==============
*/
void Com_OpenLogFile()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_LogPrintMessage
==============
*/
void Com_LogPrintMessage(int channel, const char *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_PrintMessage
==============
*/
void Com_PrintMessage(int channel, const char *msg, int error)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_Printf
==============
*/
void Com_Printf(int channel, const char *fmt, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_DPrintf
==============
*/
void Com_DPrintf(int channel, const char *fmt, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_PrintError
==============
*/
void Com_PrintError(int channel, const char *fmt, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_PrintWarning
==============
*/
void Com_PrintWarning(int channel, const char *fmt, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_InitDynamicRender
==============
*/
void Com_InitDynamicRender()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_ShutdownDynamicMemorySystems
==============
*/
void Com_ShutdownDynamicMemorySystems()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GetTimeScale
==============
*/
double Com_GetTimeScale()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_SetTimeScale
==============
*/
void Com_SetTimeScale(float timescale)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_ErrorIsNotice
==============
*/
bool Com_ErrorIsNotice(const char *errorMessage)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_SetLocalizedErrorMessage
==============
*/
void Com_SetLocalizedErrorMessage(const char *localizedErrorMessage, const char *titleToken)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_SetErrorMessage
==============
*/
void Com_SetErrorMessage(const char *errorMessage)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_PrintStackTrace
==============
*/
void Com_PrintStackTrace(int code, void (*cb)(const char *))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_ErrorAbort
==============
*/
void __noreturn Com_ErrorAbort()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_Error
==============
*/
void Com_Error(errorParm_t code, const char *fmt, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_ParseCommandLine
==============
*/
void Com_ParseCommandLine(char *commandLine)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_SafeMode
==============
*/
int Com_SafeMode()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_StartupProcessSetCommand
==============
*/
bool Com_StartupProcessSetCommand(int lineIndex, const char *match)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_StartupVariable
==============
*/
/*void Com_StartupVariable(const char *a1@<edx>, const char *match)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Com_AddStartupCommands
==============
*/
void Com_AddStartupCommands()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Info_Print
==============
*/
void Info_Print(const char *s)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_AllocEvent
==============
*/
void *Com_AllocEvent(int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_PacketEventLoop
==============
*/
void Com_PacketEventLoop(LocalClientNum_t localClientNum, msg_t *netmsg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_ClientPacketEvent
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Com_ServerPacketEvent
==============
*/
void Com_ServerPacketEvent()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_EventLoop
==============
*/
void Com_EventLoop()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_Error_f
==============
*/
void Com_Error_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_Freeze_f
==============
*/
void Com_Freeze_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_Crash_f
==============
*/
void Com_Crash_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_CompressWithZLib
==============
*/
unsigned int Com_CompressWithZLib(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_DecompressWithZLib
==============
*/
unsigned int Com_DecompressWithZLib(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_InitDvars
==============
*/
const dvar_t *Com_InitDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_CheckForInvites_f
==============
*/
void Com_CheckForInvites_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_RunAutoExec
==============
*/
void Com_RunAutoExec(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_ExecStartupConfigs
==============
*/
void Com_ExecStartupConfigs(LocalClientNum_t localClientNum, const char *configFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_WriteConfigToFile
==============
*/
void Com_WriteConfigToFile(LocalClientNum_t localClientNum, const char *filename)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_isFullyInitialized
==============
*/
BOOL Com_isFullyInitialized()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_WriteConfig_f
==============
*/
void Com_WriteConfig_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_WriteKeyConfig_f
==============
*/
void Com_WriteKeyConfig_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_WriteDefaults_f
==============
*/
void Com_WriteDefaults_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GetTimescaleForSnd
==============
*/
double Com_GetTimescaleForSnd()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_SetSlowMotion
==============
*/
void Com_SetSlowMotion(const float startTimescale, const float endTimescale, const int deltaMsec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_ResetSlowMotion
==============
*/
void Com_ResetSlowMotion()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_SetSlowMotionDelayed
==============
*/
void Com_SetSlowMotionDelayed(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_ViewScaleMsec
==============
*/
double Com_ViewScaleMsec(float sec)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_Frame_Try_Block_Function
==============
*/
void Com_Frame_Try_Block_Function()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GetLevelSharedFastFile
==============
*/
char *Com_GetLevelSharedFastFile(const char *mapName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_LoadCommonFastFile
==============
*/
void Com_LoadCommonFastFile()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_UnloadLevelFastFiles
==============
*/
void Com_UnloadLevelFastFiles()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_LoadLevelFastFiles
==============
*/
void Com_LoadLevelFastFiles(const char *mapName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_LoadLevelFastFiles_BlockForOverlay
==============
*/
void Com_LoadLevelFastFiles_BlockForOverlay(const char *mapName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_UnloadFrontEnd
==============
*/
void Com_UnloadFrontEnd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_ResetFrametime
==============
*/
void Com_ResetFrametime()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_CheckSyncFrame
==============
*/
void Com_CheckSyncFrame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_LogFileOpen
==============
*/
BOOL Com_LogFileOpen()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Field_Clear
==============
*/
void Field_Clear(field_t *edit)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_Restart
==============
*/
void Com_Restart()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AllocAnimTree
==============
*/
void *CG_AllocAnimTree(int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_XAnimCreateSmallTree
==============
*/
XAnimTree_s *Com_XAnimCreateSmallTree(XAnim_s *anims)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_XAnimFreeSmallTree
==============
*/
void Com_XAnimFreeSmallTree(XAnimTree_s *animtree)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_SetWeaponInfoMemory
==============
*/
void Com_SetWeaponInfoMemory(int source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_FreeWeaponInfoMemory
==============
*/
void Com_FreeWeaponInfoMemory(int source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GetWeaponInfoMemory
==============
*/
int Com_GetWeaponInfoMemory()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_AddToString
==============
*/
int Com_AddToString(const char *add, char *msg, int len, int maxlen, int mayAddQuotes)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_GetDecimalDelimiter
==============
*/
char Com_GetDecimalDelimiter()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_LocalizedFloatToString
==============
*/
void Com_LocalizedFloatToString(float f, char *buffer, unsigned int maxlen, unsigned int numDecimalPlaces)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_SyncThreads
==============
*/
void Com_SyncThreads()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_DisplayName
==============
*/
const char *Com_DisplayName(const char *name, const char *clanAbbrev, int type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CS_DisplayName
==============
*/
char *CS_DisplayName(const clientState_s *cs, int type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_GetPrivateClients
==============
*/
int Com_GetPrivateClients()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NetAdr_SetType
==============
*/
void NetAdr_SetType(netadr_t *addr, netadrtype_t type)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_UseRawUDP
==============
*/
bool Com_UseRawUDP()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_Quit_f
==============
*/
void Com_Quit_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_InitDynamicMemorySystems
==============
*/
void Com_InitDynamicMemorySystems()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_ErrorCleanup
==============
*/
void Com_ErrorCleanup()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_Init_Try_Block_Function
==============
*/
void Com_Init_Try_Block_Function(ControllerIndex_t a1, dediUserData_t *a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_Frame
==============
*/
void Com_Frame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_SetPrivateClients
==============
*/
bool Com_SetPrivateClients()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_Shutdown
==============
*/
void Com_Shutdown(const char *finalmsg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_Init
==============
*/
void Com_Init(char *commandLine)
{
	UNIMPLEMENTED(__FUNCTION__);
}

