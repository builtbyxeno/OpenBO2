#include "types.h"
#include "vars.h"
#include <csetjmp>
#include <time.h>
#include <client/client_public.h>
#include <win32/win32_public.h>
#include <qcommon/qcommon_public.h>
#include <ui_mp/ui_mp_public.h>
#include <ui/ui_public.h>
#include <qcommon/cmd.h>
#include <database/database_public.h>
#include <gfx_d3d/gfx_d3d_public.h>

int logfile;

static char com_consoleBuffer[100][256];
int com_consoleBufferCurLine;
char* rd_buffer;
unsigned int rd_buffersize;
void(__cdecl* rd_flush)(char*);

int com_frameNumber;
int com_lastFrameIndex;
int com_frameTime;

char com_errorMessage[4096];

int com_consoleLogOpenFailed;
int opening_qconsole;

int com_errorPrintsCount;

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
	if (Cmd_Argc() == 1)
	{
		NTP_Sync("10.150.2.138");
	}
	else
	{
		NTP_Sync(Cmd_Argv(1));
	}
}

/*
==============
Com_IsRunningMenuLevel
==============
*/
bool Com_IsRunningMenuLevel(const char *name)
{
	if (!name)
	{
		if (!sv_mapname)
		{
			return 0;
		}
		name = Dvar_GetString(sv_mapname);
	}

	if (!Dvar_GetBool(com_sv_running))
	{
		return 0;
	}

	if (I_strnicmp(name, "menu_", 5))
	{
		return I_strcmp(name, "ui") == 0;
	}

	return 1;
}

/*
==============
Com_IsMenuLevel
==============
*/
char Com_IsMenuLevel(const char *name)
{
	if (!name)
		return DB_IsZoneTypeLoaded(0x2000000);
	return !I_strcmp(name, "ui_mp") || !I_strcmp(name, "ui_zm");
}

/*
==============
Com_BeginRedirect
==============
*/
void Com_BeginRedirect(char *buffer, unsigned int buffersize, void (*flush)(char *))
{
	if (buffer && buffersize)
	{
		if (flush)
		{
			rd_buffer = buffer;
			rd_buffersize = buffersize;
			rd_flush = flush;
			*buffer = 0;
		}
	}
}

/*
==============
Com_EndRedirect
==============
*/
void Com_EndRedirect()
{
	if (rd_flush)
	{
		rd_flush(rd_buffer);
	}
	rd_buffer = NULL;
	rd_buffersize = 0;
	rd_flush = NULL;
}

/*
==============
Com_OpenLogFile
==============
*/
void Com_OpenLogFile()
{
	__int64 aclock;
	tm* newtime;

	if (Sys_IsMainThread() && !opening_qconsole)
	{
		opening_qconsole = 1;
		_time64(&aclock);
		newtime = localtime(&aclock);
		if (log_append && Dvar_GetBool(log_append))
		{
			logfile = FS_FOpenFileAppend("console_mp.log");
		}
		else
		{
			logfile = FS_FOpenTextFileWrite("console_mp.log");
		}

		com_consoleLogOpenFailed = logfile == 0;
		Com_Printf(CON_CHANNEL_SYSTEM, "Build %d\nlogfile opened on %s\n", Com_GetBuildNumber(), asctime(newtime));
		opening_qconsole = 0;
	}
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
	if (channel >= CON_FIRST_DEBUG_CHANNEL && !Con_IsChannelVisible(CON_DEST_CONSOLE, channel, 0) && error != 2 && error != 3)
	{
		return;
	}

	Sys_EnterCriticalSection(CRITSECT_CONSOLE);
	if (strlen(msg) + 1 <= 256)
	{
		strcpy(com_consoleBuffer[com_consoleBufferCurLine], msg);
	}
	else
	{
		strncpy(com_consoleBuffer[com_consoleBufferCurLine], (char*)msg, sizeof(com_consoleBuffer[com_consoleBufferCurLine]) - 1);
		com_consoleBuffer[com_consoleBufferCurLine][255] = 0;
	}

	com_consoleBufferCurLine++;
	if (com_consoleBufferCurLine >= 100)
	{
		com_consoleBufferCurLine = 0;
	}

	Sys_LeaveCriticalSection(CRITSECT_CONSOLE);
	if (rd_buffer)
	{
		if (channel != CON_CHANNEL_LOGFILEONLY)
		{
			Sys_EnterCriticalSection(CRITSECT_RD_BUFFER);
			if (strlen(rd_buffer) + strlen(msg) > rd_buffersize - 1)
			{
				rd_flush(rd_buffer);
				*rd_buffer = 0;
			}
			I_strncat(rd_buffer, rd_buffersize, msg);
			Sys_LeaveCriticalSection(CRITSECT_RD_BUFFER);
		}
	}
	else
	{
		if (msg[0] == '^' && msg[1] != '\0')
		{
			msg += 2;
		}

		if (channel != CON_CHANNEL_LOGFILEONLY
			&& (!Dvar_GetBool(com_filter_output) || Con_IsChannelVisible(CON_DEST_CONSOLE, channel, 3)))
		{
			// echo to dedicated console and early console
			Sys_Print(msg);
		}

		// logfile
		if (channel != CON_CHANNEL_CONSOLEONLY && com_logfile && Dvar_GetInt(com_logfile))
		{
			Com_LogPrintMessage(channel, msg);
		}
	}
}

#define MAXPRINTMSG 4096

/*
==============
Com_Printf
==============
*/
void Com_Printf(int channel, const char *fmt, ...)
{
	char msg[MAXPRINTMSG];
	va_list va;

	va_start(va, fmt);
	if (channel < 31 || Con_IsChannelVisible(CON_DEST_CONSOLE, channel, 0))
	{
		vsprintf(msg, fmt, va);
		Com_PrintMessage(channel, msg, 0);
	}
	va_end(va);
}

/*
==============
Com_DPrintf
==============
*/
void Com_DPrintf(int channel, const char *fmt, ...)
{
	char msg[MAXPRINTMSG];
	va_list va;

	if (!com_developer || !Dvar_GetBool(com_developer))
	{
		return;         // don't confuse non-developers with techie stuff...
	}

	if (channel < 31 || Con_IsChannelVisible(CON_DEST_CONSOLE, channel, 0))
	{
		va_start(va, fmt);
		_vsnprintf(msg, sizeof(msg), fmt, va);
		va_end(va);

		Com_Printf(channel, "%s", msg);
	}
}

/*
==============
Com_PrintError
==============
*/
void Com_PrintError(int channel, const char *fmt, ...)
{
	char msg[4096];
	int offset;
	va_list va;

	va_start(va, fmt);
	if (I_stristr(fmt, "error"))
	{
		I_strncpyz(msg, "^1", sizeof(msg));
	}
	else
	{
		I_strncpyz(msg, "^1Error: ", sizeof(msg));
	}

	offset = strlen(msg);
	_vsnprintf(&msg[offset], sizeof(msg) - offset, fmt, va);
	va_end(va);

	++com_errorPrintsCount;
	Com_PrintMessage(channel, msg, 3);
}

/*
==============
Com_PrintWarning
==============
*/
void Com_PrintWarning(int channel, const char *fmt, ...)
{
	char msg[4096];
	int offset;
	va_list va;

	va_start(va, fmt);
	I_strncpyz(msg, "^3", sizeof(msg));
	offset = strlen(msg);
	_vsnprintf(&msg[offset], sizeof(msg) - offset, fmt, va);
	va_end(va);

	Com_PrintMessage(channel, msg, 2);
}

/*
==============
Com_InitDynamicRender
==============
*/
void Com_InitDynamicRender()
{
	bool IsZoneTypeLoaded = DB_IsZoneTypeLoaded(0x2000000);
	R_ExtraCam_Init(Com_IsMenuLevel(NULL) != 0);
	R_UI3D_OnetimeInit(0x80u, 0x80u, 0, Com_IsMenuLevel(NULL) != 0, 0);
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
Com_StartHunkUsers
==============
*/
void Com_StartHunkUsers()
{
	if (setjmp((int*)Sys_GetValue(THREAD_VALUE_COM_ERROR)))
	{
		Sys_Error("Error during initialization:\n%s\n", com_errorMessage);
		return;
	}

	Com_AssetLoadUI(NULL);
	UI_SetActiveMenu(Com_LocalClients_GetPrimary(), UI_GetMenuScreen());
	IN_Frame();
	Com_EventLoop();
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
void Com_ErrorAbort()
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
void Com_StartupVariable(const char *a1, const char *match)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_AddStartupCommands
==============
*/
void Com_AddStartupCommands(char *a1, const char *a2)
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
char Com_ClientPacketEvent(int a1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
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
unsigned int Com_CompressWithZLib(const unsigned __int8 *from, int inSizeBytes, unsigned __int8 *to, int outSizeBytes)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_DecompressWithZLib
==============
*/
unsigned int Com_DecompressWithZLib(const unsigned __int8 *from, int inSizeBytes, unsigned __int8 *to, int outSizeBytes)
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
void Com_SetSlowMotionDelayed(const float startTimescale, const float endTimescale, const int deltaMsec, const int delayMsec)
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
	if (!setjmp((int*)Sys_GetValue(THREAD_VALUE_COM_ERROR)))
	{
		Com_CheckSyncFrame();
		Com_Frame_Try_Block_Function();
		++com_frameNumber;
	}

	Sys_EnterCriticalSection(CRITSECT_COM_ERROR);
	if (com_errorEntered)
	{
		Com_ErrorCleanup();
		Sys_LeaveCriticalSection(CRITSECT_COM_ERROR);
		if (!DEDICATED)
		{
			CL_InitRenderer();
			Com_StartHunkUsers();
		}
	}
	else
	{
		Sys_LeaveCriticalSection(CRITSECT_COM_ERROR);
	}
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

