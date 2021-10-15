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
#include <client_mp/client_mp_public.h>
#include <live/live_public.h>
#include <server_mp/server_mp_public.h>
#include <game/game_public.h>
#include <ik/ik_public.h>
#include <sound/sound_public.h>
#include <stringed/stringed_public.h>
#include <clientscript/clientscript_public.h>
#include <xanim/xanim_public.h>
#include <cgame/cgame_public.h>
#include <demo/demo_public.h>
#include <vcs/vcs_public.h>
#include <mjpeg/mjpeg_public.h>

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

float com_codeTimeScale;

cmd_function_s Com_CheckForInvites_f_VAR;
cmd_function_s BG_EmblemsInit_VAR;
cmd_function_s Com_LoadCommonFastFile_VAR;
cmd_function_s Com_WriteDefaults_f_VAR;
cmd_function_s Com_WriteKeyConfig_f_VAR;
cmd_function_s Com_WriteConfig_f_VAR;
cmd_function_s Com_Quit_f_VAR;
cmd_function_s Com_NTPSync_f_VAR;
cmd_function_s Com_Assert_f_VAR;
cmd_function_s Com_Freeze_f_VAR;
cmd_function_s Com_Crash_f_VAR;
cmd_function_s Com_Error_f_VAR;

SlowMotionCommon g_slowmoCommon;

int com_fullyInitialized;

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
Com_AssetLoadUI
==============
*/
void Com_AssetLoadUI(const char* name)
{
	Com_LoadCommonFastFile();
	Com_LoadUiFastFile();

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
	R_UI3D_OnetimeInit(512, 512, IsZoneTypeLoaded, 0);
	R_ExtraCam_Init(IsZoneTypeLoaded);
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
void Com_StartupVariable(const char *match)
{
	UNIMPLEMENTED(__FUNCTION__);
}

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
Com_LoadUiFastFile
==============
*/
void Com_LoadUiFastFile()
{
	void* webmAlloc;

	Com_UnloadLevelFastFiles();
	CL_AllocatePerLocalClientMemory(UI_FAST_FILE_NAME, 0);
	PMem_BeginAlloc("WebM Playback", 1, TRACK_UI);
	webmAlloc = _PMem_AllocNamed(20971520, 4, 4, 1, "WebM Playback", TRACK_UI);
	//WebM_Init(webmAlloc, 0x1400000);
	PMem_EndAlloc("WebM Playback", 1);
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
Com_InitUIAndCommonXAssets
==============
*/
void Com_InitUIAndCommonXAssets()
{
	UNIMPLEMENTED(__FUNCTION__);
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
void Com_Init_Try_Block_Function(char* commandLine)
{
	const char* BuildName;
	char* BuildVersion;
	int initStartTime, isDev;
	bool devScript, abrtOnErr;
	XZoneInfo zoneInfo;
	int i;
	LARGE_INTEGER PerformanceCount;

	if (!Com_SessionMode_IsZombiesGame())
		ARCHIVED_SNAPSHOT_BUFFER_SIZE = 0x200000;
	else
		ARCHIVED_SNAPSHOT_BUFFER_SIZE = 0x20000;
	Live_Base_Pump();
	BuildName = Com_GetBuildName();
	BuildVersion = Com_GetBuildVersion();
	Com_Printf(CON_CHANNEL_SYSTEM, "%s %s build %s %s\n", BuildVersion, BuildName, "win-x86", __DATE__);
	Com_ParseCommandLine(commandLine);
	CL_RegisterDvars();
	Swap_Init();
	Cbuf_Init();
	Cmd_Init();
	GamerProfile_InitOnce();
	Com_StartupVariable(0);
	Com_InitDvars();
	Live_Base_Pump();
	BB_Init();
	IK_InitSystem();
	SND_Init();
#if XENON
	qr_Init();
#endif
	query_Init();
	initStartTime = 0;
	if (Dvar_GetBool(useFastFile))
	{
		DB_SetInitializing(1);
		initStartTime = Sys_Milliseconds();
		PMem_BeginAlloc("$init", 1u, TRACK_MISC);
	}
	Live_Base_Pump();
	Stream_Init();
#if XENON
	FS_InitRemotePCPaths();
	FS_InitLogThread();
	Com_DevhostInit();
#endif
	R_RegisterDvars();
#if XENON
	Sys_InitCmdEvents();
#endif
	// LUI::LUI_CoD_InitMemory()
#if XENON
	R_InitDisplayInfo();
	R_SetIsMultiplayer(1);
	R_InitDevice();
#endif
	if (Dvar_GetBool(useFastFile))
	{
		DB_InitFastFileNames();
		DB_InitThread();
		if (!DB_IsMinimumFastFileLoaded())
		{
			zoneInfo.name = CODE_PRE_GFX_FAST_FILE_NAME;
			zoneInfo.allocFlags = 1;
			zoneInfo.freeFlags = 0;
			DB_LoadXAssets(&zoneInfo, 1u, 0);
			DB_SyncXAssets();
		}
	}
	Live_Base_Pump();
	CL_InitKeyCommands();
	CL_InitGamepadCommands();
	CL_InitGamepadAxisBindings();
	FS_InitFilesystem(1);
	Live_Base_Pump();
	Com_InitClientGameStates();
#if XENON
	for (i = 0; i < 4; ++i)
	{
		Com_LocalClient_SetControllerIndex((LocalClientNum_t)i, (ControllerIndex_t)i);
		Com_ExecStartupConfigs((LocalClientNum_t)i, "config_mp.cfg");
	}
#else
	Com_LocalClient_SetControllerIndex(LOCAL_CLIENT_FIRST, CONTROLLER_INDEX_FIRST);
	if (Com_IsClientConsole())
	{
		Com_ExecStartupConfigs(LOCAL_CLIENT_FIRST, va("dedicated_%s.cfg", Sys_GetIdentityParam(IDENTITY_PLATFORM)));
	}
	else
	{
		Cbuf_AddText(LOCAL_CLIENT_FIRST, "exec default_dedicated.cfg\n");
		Cbuf_Execute(LOCAL_CLIENT_FIRST, Com_LocalClient_GetControllerIndex(LOCAL_CLIENT_FIRST));
		Dvar_SetInAutoExec(1);
		Cmd_ExecuteSingleCommand(LOCAL_CLIENT_FIRST, Com_LocalClient_GetControllerIndex(LOCAL_CLIENT_FIRST), "exec autoexec_dev_mp.cfg", 0);
		Dvar_SetInAutoExec(0);
		if (Com_SafeMode())
			Cbuf_AddText(LOCAL_CLIENT_FIRST, "exec safemode_mp.cfg\n");
		Cbuf_Execute(LOCAL_CLIENT_FIRST, Com_LocalClient_GetControllerIndex(LOCAL_CLIENT_FIRST));
	}
#endif
	Live_Base_Pump();
	Cbuf_Execute(Com_LocalClients_GetPrimaryDefault(), Com_LocalClient_GetControllerIndex(Com_LocalClients_GetPrimaryDefault()));
	Com_StartupVariable(0);
	if (!Dvar_GetBool(useFastFile))
	{
		SEH_UpdateLanguageInfo();
	}
#if DEDICATED
	CL_InitDedicated();
#endif
	Live_Base_Pump();
	Com_InitHunkMemory();
	Hunk_UserStartup();
	Live_Base_Pump();
	if ((g_dvar_modifiedFlags & 0x20) != 0)
		Com_InitDvars();
#if DEDICATED
	CL_InitOnceForAllClients();
#endif
	com_codeTimeScale = 1.0;
	Live_Init();
	if (Com_SessionMode_IsZombiesGame())
		Cbuf_AddText(LOCAL_CLIENT_FIRST, "exec default_zm_gamesettings.cfg\n");
	else
		Cbuf_AddText(LOCAL_CLIENT_FIRST, "exec default_mp_gamesettings.cfg\n");
	Cbuf_Execute(LOCAL_CLIENT_FIRST, Com_LocalClient_GetControllerIndex(LOCAL_CLIENT_FIRST));
	Content_Init();
	Live_Base_Pump();
	scr_xpscale = _Dvar_RegisterFloat("scr_xpscale", 1.0, 0.0, 10000.0, 0x20000u, "");
	ui_xpscale = _Dvar_RegisterFloat("ui_xpscale", 1.0, 0.0, 3.0, 0, "Used by pc clients to show scr_xpscale in the UI");
	scr_gunxpscale = _Dvar_RegisterFloat("scr_gunxpscale", 1.0, 0.0, 3.0, 0x20000u, "");
	scr_rankXpCap = _Dvar_RegisterInt("scr_rankXpCap", 0x7FFFFFFF, 0, 0x7FFFFFFF, 0x20000u, "");
	scr_codpointsxpscale = _Dvar_RegisterFloat("scr_codpointsxpscale", 0.1, 0.0, 1.0, 0, "");
	scr_codpointsmatchscale = _Dvar_RegisterFloat("scr_codpointsmatchscale", 0.1, 0.0, 1.0, 0, "");
	scr_codpointsperchallenge = _Dvar_RegisterFloat("scr_codpointsperchallenge", 0.1, 0.0, 1.0, 0, "");
	scr_scorestreaks = _Dvar_RegisterInt("scr_scorestreaks", 1, 0, 1, 0x20000u, "");
	scr_scorestreaks_maxstacking = _Dvar_RegisterInt("scr_scorestreaks_maxstacking", 1, 1, 64, 0x20000u, "");
	scr_rampagebonusscale = _Dvar_RegisterFloat("scr_rampagebonusscale", 0.75, 0.0, 10.0, 0x20000u, "");
	scr_disableChallenges = _Dvar_RegisterBool("scr_disableChallenges", 0, 0x20000u, "");
	scr_disableStatTracking = _Dvar_RegisterBool("scr_disableStatTracking", 0, 0x20000u, "");
	scr_disableSetDStat = _Dvar_RegisterBool("scr_disableSetDStat", 0, 0x20000u, "");
	ProfLoad_Init();
	if (Dvar_GetInt(com_developer))
	{
		Cmd_AddCommandInternal("error", Com_Error_f, &Com_Error_f_VAR);
		Cmd_AddCommandInternal("crash", Com_Crash_f, &Com_Crash_f_VAR);
		Cmd_AddCommandInternal("freeze", Com_Freeze_f, &Com_Freeze_f_VAR);
		Cmd_AddCommandInternal("assert", nullptr, &Com_Assert_f_VAR);
	}
	Cmd_AddCommandInternal("ntpsync", Com_NTPSync_f, &Com_NTPSync_f_VAR);
	Cmd_AddCommandInternal("quit", Com_Quit_f, &Com_Quit_f_VAR);
	Cmd_AddCommandInternal("writeconfig", Com_WriteConfig_f, &Com_WriteConfig_f_VAR);
	Cmd_AddCommandInternal("writekeyconfig", Com_WriteKeyConfig_f, &Com_WriteKeyConfig_f_VAR);
	Cmd_AddCommandInternal("writedefaults", Com_WriteDefaults_f, &Com_WriteDefaults_f_VAR);
	Cmd_AddCommandInternal("loadcommonff", Com_LoadCommonFastFile, &Com_LoadCommonFastFile_VAR);
	Cmd_AddCommandInternal("init_emblems_backings", (void(__cdecl*)())BG_EmblemsInit, &BG_EmblemsInit_VAR);
	Cmd_AddCommandInternal("checkforinvites", Com_CheckForInvites_f, &Com_CheckForInvites_f_VAR);
	char* s = va("%s %s build %s %s", Com_GetBuildDisplayName(), Com_GetBuildName(), Com_GetBuildVersion(), "win-x86");
	version = _Dvar_RegisterString("version", "", 0x40u, "Game version");
	Dvar_SetString(version, s);
	shortversion = _Dvar_RegisterString("shortversion", "1", 0x44u, "Short game version");
	Live_Base_Pump();
	Sys_Init();
	QueryPerformanceCounter(&PerformanceCount);
	Netchan_Init(PerformanceCount.LowPart); //?????
	Scr_InitVariables(SCRIPTINSTANCE_SERVER);
	Scr_Init(SCRIPTINSTANCE_SERVER);
	isDev = Dvar_GetInt(com_developer);
	devScript = Dvar_GetBool(com_developer_script);
	if (isDev || (abrtOnErr = 0, Dvar_GetInt(com_logfile)))
		abrtOnErr = 1;
	Scr_Settings(SCRIPTINSTANCE_SERVER, isDev, devScript, abrtOnErr);
	Scr_Settings(SCRIPTINSTANCE_CLIENT, isDev, devScript, abrtOnErr);
	XAnimInit();
	DObjInit();
	SV_Init();
	NET_Init();
	Live_Base_Pump();
	RMsg_Init();
	com_frameTime = Sys_Milliseconds();
	g_slowmoCommon.enable = 0;
	g_slowmoCommon.viewEnable = 0;
	g_slowmoCommon.viewTimescale = 1.0;
	g_slowmoCommon.delayMsec = 0;
	Com_StartupVariable(0);
#if !DEDICATED
	ScrPlace_Init();
	CL_InitOnceForAllClients();
	for (int j = 0; j < 4; ++j)
		CL_Init((LocalClientNum_t)j);
	R_InitThreads();
	R_InitOnce();
	CL_InitRenderer();
	Expression_Init();
#if XENON
	Com_ExecPlatformSpecificDefaultConfigs();
#endif
	assert(!cls.soundStarted);
	SND_Init();
	cls.soundStarted = 1;
	CG_SndGameReset();
	Voice_Init();
	mjpeg_initonce();
#endif
	Live_Base_Pump();
	Sys_LoadingKeepAlive();
	Live_InitSigninState();
	R_BeginRemoteScreenUpdate();
	BG_EmblemsInit();
	SV_InitServerThread();
	Demo_InitFileShareTaskHandler();
	Demo_InitFileHandlerSystem();
	Live_Base_Pump();
	if (IsFastFileLoad())
	{
		PMem_EndAlloc("$init", 1u);
		DB_SetInitializing(0);
		Com_Printf(CON_CHANNEL_SYSTEM, "end $init %d ms\n", Sys_Milliseconds() - initStartTime);
	}
	Live_Base_Pump();
	R_EndRemoteScreenUpdate();
	com_fullyInitialized = 1;
	Com_Printf(CON_CHANNEL_SYSTEM, "--- Common Initialization Complete ---\n");
	Com_DvarDump(8, 0);
#if !XENON
	VCS_Init();
#endif
}

/*
==============
Com_Frame
==============
*/
void Com_Frame()
{
	// cdl_proftimer::reset(&proftimer_physics_frame_advance);
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
#if !DEDICATED
			CL_InitRenderer();
			Com_StartHunkUsers();
#endif
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
Com_ShutdownInternal
==============
*/
void Com_ShutdownInternal(const char* finalmsg)
{
	int localClientNum;

	for (localClientNum = 0; localClientNum < MAX_LOCAL_CLIENTS; ++localClientNum)
	{
		CL_Disconnect((LocalClientNum_t)localClientNum, 0);
	}

	SV_AllowPackets(0);
	CL_ShutdownAll();
	SV_Shutdown(finalmsg);
	Dvar_ResetDvars(8, DVAR_SOURCE_INTERNAL);
	Dvar_ResetDvars(0x100u, DVAR_SOURCE_INTERNAL);
	Com_Restart();
	Com_UnloadFrontEnd();
	CL_FreePerLocalClientMemory(1);
}

/*
==============
Com_Shutdown
==============
*/
void Com_Shutdown(const char *finalmsg)
{
	Com_ShutdownInternal(finalmsg);
	CL_InitRenderer();
	Com_AssetLoadUI(finalmsg);
}

/*
==============
Com_Init
==============
*/
void Com_Init(char *commandLine)
{
	if (setjmp((int*)Sys_GetValue(THREAD_VALUE_COM_ERROR)))
	{
		Sys_Error(va("Error during initialization:\n%s\n", com_errorMessage));
	}

	Com_Init_Try_Block_Function(commandLine);

	if (!setjmp((int*)Sys_GetValue(THREAD_VALUE_COM_ERROR)))
	{
		Com_AddStartupCommands();
	}

	if (!I_strcmp(Dvar_GetString(sv_mapname), ""))
	{
#if DEDICATED
		DB_InitFrontendXAssets(0);
#else
		Com_InitUIAndCommonXAssets();
#endif
	}

	Live_Base_Pump();

	if (com_errorEntered)
	{
		Com_ErrorCleanup();
	}

	if (!Dvar_GetBool(com_sv_running))
	{
		if (setjmp((int*)Sys_GetValue(THREAD_VALUE_COM_ERROR)))
		{
			Sys_Error(va("Error during initialization:\n%s\n", com_errorMessage));
		}
#if !DEDICATED
		if (!cls.rendererStarted)
		{
			CL_InitRenderer();
		}
		R_BeginRemoteScreenUpdate();
		CL_StartHunkUsers();
		Live_Base_Pump();
		R_EndRemoteScreenUpdate();
		if (*Dvar_GetString(ui_errorMessage))
		{
			Com_LoadUiFastFile();
		}
		Session_ChangeAdvertisedStatus(1, 1);
#if XENON
		Dvar_SetBool(xblive_matchEndingSoon, 0);
#endif
		CL_SetupClientsForFrontend();
#endif
		Live_Base_Pump();
	}
	UI_LoadCustomMatchGameTypes();
}

