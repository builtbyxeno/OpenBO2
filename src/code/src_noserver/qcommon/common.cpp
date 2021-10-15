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
#include <gfx_d3d/r_pix_profile.h>
#include <game_mp/game_mp_public.h>
#include <physics/phys_colgeom.h>
#include <server/server_public.h>
#include <glass/glass_public.h>
#include <flame/flame_public.h>

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

LaunchData g_launchData;

int com_fixedConsolePosition;
int weaponInfoSource;
int com_quitAfterHostMigrates;

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
	z_stream_s stream;

	stream.avail_in = inSizeBytes;
	stream.next_in = (unsigned __int8*)from;
	stream.next_out = to;
	stream.avail_out = outSizeBytes;
	memset(&stream.zalloc, 0, 16);
	if (deflateInit2_(&stream, 9, 8, -13, 1, 0, "1.2.3", 52))
		return 0;
	if (deflate(&stream, 4) != 1)
	{
		deflateEnd(&stream);
		return 0;
	}
	if (deflateEnd(&stream))
		return 0;
	return stream.total_out;
}

/*
==============
Com_DecompressWithZLib
==============
*/
unsigned int Com_DecompressWithZLib(const unsigned __int8 *from, int inSizeBytes, unsigned __int8 *to, int outSizeBytes)
{
	z_stream_s stream;

	stream.avail_in = inSizeBytes;
	stream.next_in = (unsigned __int8*)from;
	stream.next_out = to;
	stream.avail_out = outSizeBytes;
	memset(&stream.zalloc, 0, 16);
	if (inflateInit2_(&stream, -13, "1.2.3", 52))
		return 0;
	if (inflate(&stream, 4) != 1)
	{
		inflateEnd(&stream);
		return 0;
	}
	if (inflateEnd(&stream))
		return 0;
	return stream.total_out;
}

/*
==============
Com_InitDvars
==============
*/
void Com_InitDvars()
{
	int i;
	const char* war_names[5];

	com_maxclients = _Dvar_RegisterInt("com_maxclients", 18, 1, 18, 4u, "Maximum amount of clients on  the server");
	if (Com_SessionMode_IsZombiesGame())
	{
		Dvar_SetInt(com_maxclients, 8);
	}
	com_freemoveScale = _Dvar_RegisterFloat("com_freemoveScale", 1.0, 0.0, 5.0, 0x80u, "Scale how fast you move in com_freemove mode");
	disconnected_ctrls = _Dvar_RegisterString("disconnected_ctrls", "", 0, "String representing the disconnected controllers");
	com_maxfps = _Dvar_RegisterInt("com_maxfps", 60, 0, 1000, 1u, "Cap frames per second");
	grenade_indicators_enabled = _Dvar_RegisterBool("grenade_indicators_enabled", 1, 0x4000u, "Enables grenade indicators");
	throwback_enabled = _Dvar_RegisterBool("throwback_enabled", 1, 0x4000u, "Enables throwbacks");
	disable_vcs = _Dvar_RegisterBool("disable_vcs", 0, 0x20000u, "Disables VCS");
	disable_vcs_viewmodel = _Dvar_RegisterBool("disable_vcs_viewmodel", 0, 0x20000u, "Disables VCS viewmodel in the VCS UI menu");
	vcs_timelimit = _Dvar_RegisterInt("vcs_timelimit", 120, 0, 0x7FFFFFFF, 0x20000u, "Sets the timelimit for the VCS easter egg");
	com_report_syserrors = _Dvar_RegisterBool("com_report_syserrors", 1, 0x20000u, "Enable syserror reporting");
	gts_validation_enabled = _Dvar_RegisterBool("gts_validation_enabled", 0, 0x20000u, "Enables gametype settings validation in online modes");
	lui_enabled = _Dvar_RegisterBool("lui_enabled", 1, 0, "Enables LUI");
	lui_checksum_enabled = _Dvar_RegisterBool("lui_checksum_enabled", 0, 0x20000u, "Enables LUI checksums");
	lui_error_report = _Dvar_RegisterBool("lui_error_report", 1, 0x20000u, "Enable LUI error reporting");
	lui_error_report_delay = _Dvar_RegisterInt("lui_error_report_delay", 1000, 0, 0x7FFFFFFF, 0x20000u, "Number of ms to wait for error report to send before restarting the EXE");
	lui_timescale = _Dvar_RegisterFloat("lui_timescale", 1.0, 0.001, 10.0, 0x80u, "Scale time of each frame of LUI animation");
	lui_disable_blur = _Dvar_RegisterBool("lui_disable_blur", 0, 0, "Disable LUI blur");
	tu7_restoreBlur = _Dvar_RegisterBool("tu7_restoreBlur", 1, 0x20000u, "Restore blur on com_error");
	tu11_luiCompleteAnimationFix = _Dvar_RegisterBool("tu11_luiCompleteAnimationFix", 1, 0x20000u, "Enable fix for lui for completeAnimation setting the duration and time left to zero");
	zombiemode_path_minz_bias = _Dvar_RegisterFloat("zombiemode_path_minz_bias", 0x82000000, 0x82000000, 0x82000000, 4096, "Bias to prevent missing valid cells below the origin");
	zombieStopSplitScreen = _Dvar_RegisterBool("zombieStopSplitScreen", 0, 0x40u, "Force Split Screen to Fullscreen (for HUD)");
	zombie_devgui = _Dvar_RegisterString("zombie_devgui", "", 0, "");
	spmode = _Dvar_RegisterBool("spmode", 0, 0x100u, "Current game is a sp game");
	onlinegame = _Dvar_RegisterBool("onlinegame", 0, 0, "Current game is an online game with stats, custom classes, unlocks");
	xblive_rankedmatch = _Dvar_RegisterBool("xblive_rankedmatch", 0, 0, "Current game is a ranked match");
	xblive_privatematch = _Dvar_RegisterBool("xblive_privatematch", 0, 0, "Current game is a private match");
	sv_fakeServerLoad = _Dvar_RegisterInt("sv_fakeServerLoad", 0, 0, 500, 0, "Artificially load the server by this time in MS");
	sv_fakeServerLoadRand = _Dvar_RegisterInt("sv_fakeServerLoadRand", 0, 0, 500, 0, "Additional server load to add randomly each frame");
	sv_forceunranked = _Dvar_RegisterBool("sv_forceunranked", 0, 0, "");
	if (Com_IsClientConsole())
		consoleGame = _Dvar_RegisterString("consoleGame", "true", 0x40u, "True if running on a console");
	if (Com_GetClientPlatform() == CLIENT_PLATFORM_XENON)
		xenonGame = _Dvar_RegisterString("xenonGame", "true", 0x40u, "True if running on XBox 360");
	if (Com_GetClientPlatform() == CLIENT_PLATFORM_PS3)
		ps3Game = _Dvar_RegisterString("ps3Game", "true", 0x40u, "True if running on PS3");
	if (Com_GetClientPlatform() == CLIENT_PLATFORM_WIIU)
		wiiuGame = _Dvar_RegisterString("wiiuGame", "true", 0x40u, "True if running on WiiU");
	com_masterServerName = _Dvar_RegisterString("masterServerName", "cod4master.activision.com", 0x80u, "Master server name for listing public inet games");
	com_authServerName = _Dvar_RegisterString("authServerName", "cod4master.activision.com", 0x80u, "Authentication server name for listing public inet games");
	com_masterPort = _Dvar_RegisterInt("masterPort", 20810, 0, 0xFFFF, 0x80u, "Master server port");
	com_authPort = _Dvar_RegisterInt("authPort", 20800, 0, 0xFFFF, 0x80u, "Auth server port");
	com_useConfig = _Dvar_RegisterBool("com_useConfig", 1, 1u, "Use configuration files");
	fastfile_allowNoAuth = _Dvar_RegisterBool("fastfile_allowNoAuth", 0, 0x10u, "Enables loading data from non-authenticated fast files.");
	com_developer = _Dvar_RegisterInt("developer", 0, 0, 2, 0, "Enable development options");
	com_developer_script = _Dvar_RegisterBool("developer_script", Com_SessionMode_IsZombiesGame(), 0, "Enable developer script comments");
	Dvar_SetBool(com_developer_script, 1);
	Dvar_SetInt(com_developer, 1);
	com_logfile = _Dvar_RegisterInt("logfile", 1, 0, 2, 0, "Write to log file - 0 = disabled, 1 = async file write, 2 = Sync every write");
	com_statmon = _Dvar_RegisterBool("com_statmon", 0, 0, "Draw stats monitor");
	com_timescale = _Dvar_RegisterFloat("com_timescale", 1.0, 0.001, 10.0, 0x11C0u, "Scale time of each frame");
	dev_timescale = _Dvar_RegisterFloat("timescale", 1.0, 0.001, 10.0, 0x180u, "Scale time of each frame");
	com_fixedtime = _Dvar_RegisterInt("fixedtime", 0, 0, 1000, 0x80u, "Use a fixed time rate for each frame");
	com_fixedtime_float = _Dvar_RegisterFloat("fixedtime_float", 0.0, 0.0, 1000.0, 0x80u, "Use a fixed time rate for each frame");
	long_blocking_call = _Dvar_RegisterBool("long_blocking_call", 0, 0, "Enable SCR_DrawPleaseWait dialog");
	sv_network_warning = _Dvar_RegisterBool("sv_network_warning", 0, 0, "Alternative enable SCR_DrawPleaseWait dialog");
	cl_network_warning = _Dvar_RegisterBool("cl_network_warning", 0, 0, "Alternative enable SCR_DrawPleaseWait dialog");
	sv_paused = _Dvar_RegisterInt("sv_paused", 0, 0, 2, 0x40u, "Pause the server");
	cl_paused = _Dvar_RegisterInt("cl_paused", 0, 0, 2, 0, "Pause the client");
	cl_useMapPreloading = _Dvar_RegisterBool("useMapPreloading", 1, 1u, "Whether to start loading the map before connecting to server");
	sv_useMapPreloading = _Dvar_RegisterBool("useSvMapPreloading", 1, 1u, "Whether to start loading the map before starting the server");
	cl_paused_simple = _Dvar_RegisterBool("cl_paused_simple", 0, 0, "Toggling pause won't do any additional special processing if true.");
	com_voip_resume_time = _Dvar_RegisterInt("com_voip_resume_time", 0, 0, 0x7FFFFFFF, 0, "Time at which voip can resume");
	com_voip_bandwidth_restricted = _Dvar_RegisterBool("com_voip_bandwidth_restricted", 1, 0x40u, "Use VOIP inhibitor during high bandwidth usage");
	com_voip_disable_threshold = _Dvar_RegisterInt("com_voip_disable_threshold", 1200, 0, 0x7FFFFFFF, 0, "Message size at which voip becomes disabled");
	com_filter_output = _Dvar_RegisterBool("com_filter_output", 0, 0, "Use console filters for filtering output.");
	com_introPlayed = _Dvar_RegisterBool("com_introPlayed", 0, 1u, "Intro movie has been played");
	com_startupIntroPlayed = _Dvar_RegisterBool("com_startupIntroPlayed", 1, 1u, "Game startup intro movie(s) has been played");
	com_desiredMenu = _Dvar_RegisterInt("com_desiredMenu", 0, 0, 0x7FFFFFFF, 0, "Target menu to navigate to when possible");
	com_skipMovies = _Dvar_RegisterBool("com_skipMovies", 0, 0, "Skip intro movies");
	com_animCheck = _Dvar_RegisterBool("com_animCheck", 0, 0, "Check anim tree");
	com_hiDef = _Dvar_RegisterBool("hiDef", 1, 0x40u, "True if the game video is running in high-def.");
	com_wideScreen = _Dvar_RegisterBool("wideScreen", 1, 0x40u, "True if the game video is running in 16x9 aspect, false if 4x3.");
	doublesided_raycasts = _Dvar_RegisterBool("doublesided_raycasts", 0, 0x80u, "turn on double sided ray casts");
	log_append = _Dvar_RegisterBool("log_append", 0, 1u, "Open log file in append mode");
	com_walkpathnodes = _Dvar_RegisterBool("useWalkPathnodesMode", 0, 0x40u, "Walk path nodes and log static (map) texture streaming memory usage");
	com_waitForStreamer = _Dvar_RegisterInt("waitForStreamer", 1, 0, 2, 0, "1) wait for initial lowmips, 2) wait for full initial texture load.");
	recorder_enableRec = _Dvar_RegisterBool("recorder_enableRec", 0, 0x80u, "Turn on/off Recorder recording");
	recorder_streamDObjects = _Dvar_RegisterBool("recorder_streamDObjects", 1, 0x80u, "Turn on/off recorder file streaming");
	recorder_debugMemory = _Dvar_RegisterBool("recorder_debugMemory", 0, 0x80u, "Turn on/off Recorder memory debugging");
	recorder_bufferSize = _Dvar_RegisterInt("recorder_bufferSize", 0, 0, 128, 0x80u, "Additional Recorder memory");
	recorder_channelAccuracy = _Dvar_RegisterEnum("recorder_channelAccuracy", recorderModeNames, 0, 0x80u, "Accuracy Channel Replay Mode");
	recorder_channelAiCode = _Dvar_RegisterEnum("recorder_channelAiCode", recorderModeNames, 0, 0x80u, "Ai Code Channel Replay Mode");
	recorder_channelAnimation = _Dvar_RegisterEnum("recorder_channelAnimation", recorderModeNames, 0, 0x80u, "Animation Channel Replay Mode");
	recorder_channelAnimscript = _Dvar_RegisterEnum("recorder_channelAnimscript", recorderModeNames, 0, 0x80u, "Animscript Channel Replay Mode");
	recorder_channelAlex = _Dvar_RegisterEnum("recorder_channelAlex", recorderModeNames, 0, 0x80u, "Alex Channel Replay Mode");
	recorder_channelCover = _Dvar_RegisterEnum("recorder_channelCover", recorderModeNames, 0, 0x80u, "Cover Channel Replay Mode");
	recorder_channelGrenades = _Dvar_RegisterEnum("recorder_channelGrenades", recorderModeNames, 0, 0x80u, "Grenades Channel Replay Mode");
	recorder_channelMessaging = _Dvar_RegisterEnum("recorder_channelMessaging", recorderModeNames, 0, 0x80u, "Messaging Channel Replay Mode");
	recorder_channelNone = _Dvar_RegisterEnum("recorder_channelNone", recorderModeNames, 0, 0x80u, "No Channel Replay Mode");
	recorder_channelPathFind = _Dvar_RegisterEnum("recorder_channelPathFind", recorderModeNames, 0, 0x80u, "Path Find Channel Replay Mode");
	recorder_channelPerception = _Dvar_RegisterEnum("recorder_channelPerception", recorderModeNames, 0, 0x80u, "Perception Channel Replay Mode");
	recorder_channelPhysics = _Dvar_RegisterEnum("recorder_channelPhysics", recorderModeNames, 0, 0x80u, "Physics Channel Replay Mode");
	recorder_channelSuppression = _Dvar_RegisterEnum("recorder_channelSuppression", recorderModeNames, 0, 0x80u, "Suppression Channel Replay Mode");
	recorder_channelScript = _Dvar_RegisterEnum("recorder_channelScript", recorderModeNames, 0, 0x80u, "Script Channel Replay Mode");
	recorder_channelScriptedAnim = _Dvar_RegisterEnum("recorder_channelScriptedAnim", recorderModeNames, 0, 0x80u, "Scripted Anim Channel Replay Mode");
	recorder_channelThreat = _Dvar_RegisterEnum("recorder_channelThreat", recorderModeNames, 0, 0x80u, "Threat Channel Replay Mode");
	ui_mapname = _Dvar_RegisterString("ui_mapname", "", 0, "Current map name");
	ui_gametype = _Dvar_RegisterString("ui_gametype", "", 0, "Current game type");
	ui_levelEra = _Dvar_RegisterInt("ui_levelEra", 2020, 0, 2020, 0, "Int for the year/era of the current level. Default is 2020.");
	ui_aarmapname = _Dvar_RegisterString("ui_aarmapname", "", 0, "Map to use in the aar");
	all_players_are_connected = _Dvar_RegisterInt("all_players_are_connected", 0, 0, 0x7FFFFFFF, 0x4000u, "");
	if (Com_SessionMode_IsZombiesGame())
	{
		ui_zm_mapstartlocation = _Dvar_RegisterString("ui_zm_mapstartlocation", "", 0, "Current zombie map start location");
		tu6_startMovieEarly = _Dvar_RegisterBool("tu6_startMovieEarly", 1, 0x20000u, "start zm_highrise load movie earlier");
	}
	ui_combatCurrScrollBarPos = _Dvar_RegisterInt("ui_combatCurrScrollBarPos", 0, 0x80000000, 0x7FFFFFFF, 0, "");
	ui_deadquote = _Dvar_RegisterString("ui_deadquote", "", 0x4000u, "");
	ui_mapCount = _Dvar_RegisterInt("ui_mapCount", 0, 0, 0x7FFFFFFF, 0, "Number of maps the player has");
	ui_errorTitle = _Dvar_RegisterString("ui_errorTitle", "", 0x40u, "Title of the most recent error message");
	ui_errorMessage = _Dvar_RegisterString("ui_errorMessage", "", 0x40u, "Most recent error message");
	ui_errorMessageDebug = _Dvar_RegisterString("ui_errorMessageDebug", "", 0x40u, "Most recent debug error message");
	ui_autoContinue = _Dvar_RegisterBool("ui_autoContinue", 0, 0, "Automatically 'click to continue' after loading a level");
	ui_creditsScrollScale = _Dvar_RegisterFloat("creditsScrollScale", 1.0, 0.0, 100.0, 0, "credits scroll speed");
	ui_drawSpinnerAfterMovie = _Dvar_RegisterInt("ui_drawSpinnerAfterMovie", 0, 0, 1, 0, "True");
	all_players_are_connected = _Dvar_RegisterInt("all_players_are_connected", 0, 0, 0x7FFFFFFF, 0x4000u, "");
	dec20_Enabled = _Dvar_RegisterBool("dec20_Enabled", 0, 0x5000u, "enable dec20 terminal");
	dec20_inuse = _Dvar_RegisterInt("dec20_inuse", 0, 0, 1, 0, "");
	ui_keyboard_focus = _Dvar_RegisterString("ui_keyboard_focus", "", 0, "");
	ui_keyboard_focus_key = _Dvar_RegisterString("ui_keyboard_focus_key", "", 0, "");
	profile_reset = _Dvar_RegisterBool("profile_reset", 0, 0, "");
	scr_hostmigrationtest = _Dvar_RegisterBool("scr_hostmigrationtest", 0, 0, "");
	quit_on_error = _Dvar_RegisterBool("quit_on_error", 0, 0, "");
	modPrvUseAnimDump = _Dvar_RegisterBool("modPrvUseAnimDump", 0, 0, "");
	cheapSpawns = _Dvar_RegisterBool("cheapSpawns", 0, 0, "");
	noCheapSpawns = _Dvar_RegisterBool("noCheapSpawns", 0, 0, "");
	debug_show_viewpos = _Dvar_RegisterInt("debug_show_viewpos", 0, 0, 1, 0, "");
	scr_wagerTier = _Dvar_RegisterInt("scr_wagerTier", 0, 0, 0x7FFFFFFF, 0, "");
	scr_killcam = _Dvar_RegisterInt("scr_killcam", 0, 0, 0x7FFFFFFF, 0, "");
	scr_numLives = _Dvar_RegisterInt("scr_numLives", 0, 0, 0x7FFFFFFF, 0, "");
	modPrvAnimDumpInTime = _Dvar_RegisterInt("modPrvAnimDumpInTime", 0, 0, 0x7FFFFFFF, 0, "");
	modPrvAnimDumpOutTime = _Dvar_RegisterInt("modPrvAnimDumpOutTime", 0, 0, 0x7FFFFFFF, 0, "");
	fudgefactor = _Dvar_RegisterFloat("fudgefactor", 0, 0x82000000, 0x82000000, 0, "");
	debug_protocol = _Dvar_RegisterString("debug_protocol", "", 0, "");
	modPrvCurrAndMaxFrameIndexes = _Dvar_RegisterString("modPrvCurrAndMaxFrameIndexes", "", 0x4000u, "");
	sidebet_made = _Dvar_RegisterString("sidebet_made", "", 0, "");
	nextarena = _Dvar_RegisterString("nextarena", "", 0, "");
	ClickToContinue = _Dvar_RegisterBool("ClickToContinue", 0, 0, "");
	sv_forcelicensetype = _Dvar_RegisterInt("sv_forcelicensetype", 0, 0, 0x7FFFFFFF, 0, "");
	credits_active = _Dvar_RegisterBool("credits_active", 0, 0x4000u, "");
	demoname = _Dvar_RegisterString("demoname", "", 0, "");
	createfx = _Dvar_RegisterString("createfx", "", 0, "");
	saved_gameskill = _Dvar_RegisterString("saved_gameskill", "", 0x4000u, "");
	war_sb = _Dvar_RegisterString("war_sb", "", 0, "");
	scr_allies = _Dvar_RegisterString("scr_allies", "", 0, "");
	scr_axis = _Dvar_RegisterString("scr_axis", "", 0, "");
	next_menu_name = _Dvar_RegisterString("next_menu_name", "", 0, "");
	scr_wagerBet = _Dvar_RegisterInt("scr_wagerBet", 0, 0, 0x7FFFFFFF, 0, "");
	ui_mapCount = _Dvar_RegisterInt("ui_mapCount", 0, 0, 0x7FFFFFFF, 1u, "Number of maps the player has");
	miniscoreboardhide = _Dvar_RegisterBool("miniscoreboardhide", 0, 0, "");
	missingCommandWillError = _Dvar_RegisterBool("missingCommandWillError", 1, 0, "When true a missing command or config file will cause an ERR_DROP.");
	war_names[0] = "war_a";
	war_names[1] = "war_b";
	war_names[2] = "war_c";
	war_names[3] = "war_d";
	war_names[4] = "war_e";
	for (i = 0; i < 5; ++i)
	{
		war[i] = _Dvar_RegisterString(war_names[i], "", 0, "");
	}
	Dvar_SetInt(debug_show_viewpos, 1);
	com_overviewProfile = _Dvar_RegisterInt("com_overviewProfile", 0, 0, 1, 0x4000u, "Display the overview profile.");
	band_demosystem = _Dvar_RegisterInt("band_demosystem", 64000, 0, 0x7FFFFFFF, 0, "demo system bandwidth req'd");
	band_2players = _Dvar_RegisterInt("band_2players", 64000, 0, 0x7FFFFFFF, 0, "2 player bandwidth req'd");
	band_4players = _Dvar_RegisterInt("band_4players", 128000, 0, 0x7FFFFFFF, 0, "4 player bandwidth req'd");
	band_6players = _Dvar_RegisterInt("band_6players", 192000, 0, 0x7FFFFFFF, 0, "8 player bandwidth req'd");
	band_8players = _Dvar_RegisterInt("band_8players", 256000, 0, 0x7FFFFFFF, 0, "8 player bandwidth req'd");
	band_12players = _Dvar_RegisterInt("band_12players", 384000, 0, 0x7FFFFFFF, 0, "12 player bandwidth req'd");
	band_18players = _Dvar_RegisterInt("band_18players", 580000, 0, 0x7FFFFFFF, 0, "18 player bandwidth req'd");
	com_isNotice = _Dvar_RegisterBool("com_isNotice", 0, 0, "");
	error_menu_info = _Dvar_RegisterString("error_menu_info", "", 0, "");
	tu9_testMissingContentPacks = _Dvar_RegisterBool("tu9_testMissingContentPacks", 1, 0x20000u, "When the DLC flag changes for a player, sent the result to Demonware.");
	tu11_AddMapPackFlagsUserInfo = _Dvar_RegisterBool("tu11_AddMapPackFlagsUserInfo", 1, 0x20000u, "Send availableMappackFlags out with the User info.");
	tu11_use_animscripted_blends = _Dvar_RegisterBool("tu11_use_animscripted_blends", 1, 0x20000u, "Use a 0.2 second blend time when playing animscripted anims (only used by zombies).");
	tu12_zombies_allow_hint_weapon_from_script = _Dvar_RegisterBool("tu12_zombies_allow_hint_weapon_from_script", Com_SessionMode_IsZombiesGame(), 0x20000u, "Allow zombies scripts to call SetCursorHint(HINT_WEAPON,weapon).");
	tu12_validate_bonus_cards_on_server = _Dvar_RegisterBool("tu12_validate_bonus_cards_on_server", 0, 0x20000u, "Validate that a player has the necessary bonus card(s) equipped when giving loadout items.");
	tu13_allow_no_player_melee_blood = _Dvar_RegisterBool("tu13_allow_no_player_melee_blood", Com_SessionMode_IsZombiesGame(), 0x20000u, "Allow no player melee blood effect");
	tu15_zombie_local_player_test_honors_client_server_divide = _Dvar_RegisterBool("tu15_zombie_local_player_test_honors_client_server_divide", Com_SessionMode_IsZombiesGame(), 0x20000u, "Use sv_ cg_ appropriate means of determining if all players are local");
	G_RegisterRegisterToolDvars();
	// Not used, but I'm keeping it.
	fake_dvar0 = _Dvar_RegisterBool("sv_EnableDevCheats", 0, 0x4000u, "Enable dev only cheats options");
	fake_dvar1 = _Dvar_RegisterBool("sv_NoClip", 0, 0x4000u, "enable server side no-clipping");
	fake_dvar2 = _Dvar_RegisterBool("sv_FullAmmo", 0, 0x4000u, "Set server side ammo recharge");
	fake_dvar3 = _Dvar_RegisterBool("sv_InfiniteSprint", 0, 0x4000u, "Set server side sprint recharge");
	fake_dvar4 = _Dvar_RegisterBool("sv_RadarAlwaysOn", 0, 0x4000u, "Disable anti-radar events");
	fake_dvar5 = _Dvar_RegisterBool("sv_Invisible", 0, 0x4000u, "Don't render client on other systems");
	fake_dvar6 = _Dvar_RegisterBool("sv_SuperPenetrate", 0, 0x4000u, "Bullets ignore armor");
	fake_dvar7 = _Dvar_RegisterBool("sv_TripleBullet", 0, 0x4000u, "Fire 3 bullets instead of the usual 2 for double tap");
	fake_dvar8 = _Dvar_RegisterBool("sv_QuickHealthRecharge", 0, 0x4000u, "Restore health at 4x the usual rate");
	fake_dvar9 = _Dvar_RegisterBool("sv_InstantReload", 0, 0x4000u, "Reload instantly");
	fake_dvar10 = _Dvar_RegisterBool("sv_3xEXP", 0, 0x4000u, "3X multiplier for experience earned");
	fake_dvar11 = _Dvar_RegisterBool("sv_UnlockAllIntel", 0, 0x4000u, "Unlock all intel pieces");
	fake_dvar12 = _Dvar_RegisterBool("sv_UnlockAllSlots", 0, 0x4000u, "Unlock all custom slots");
	fake_dvar13 = _Dvar_RegisterBool("sv_DoubleCodPoints", 0, 0x4000u, "Double cod point earnings");
	fake_dvar14 = _Dvar_RegisterBool("sv_SetAllFree", 0, 0x4000u, "Don't charge for any purchases");
	fake_dvar15 = _Dvar_RegisterBool("sv_EnableSuperuser", 0, 0x4000u, "Enable super user features");
	fake_dvar16 = _Dvar_RegisterBool("sv_MakeMeHost", 0, 0x4000u, "Forces client to become host in game lobby");
	fake_dvar17 = _Dvar_RegisterBool("sv_DisableTheatre", 0, 0x4000u, "Remove this client from all theater captures");
	fake_dvar18 = _Dvar_RegisterBool("sv_BigHeadMode", 0, 0x4000u, "Double sized heads");
}

/*
==============
Com_CheckForInvites_f
==============
*/
void Com_CheckForInvites_f()
{
	unsigned __int64 acceptingCrossExeInviteFrom;

	acceptingCrossExeInviteFrom = 0i64;
	StringToXUIDDecimal(Dvar_GetString(FriendXuidToJoinOnBoot), &acceptingCrossExeInviteFrom);
	if (acceptingCrossExeInviteFrom)
	{
		GamerProfile_SetString(PROFILE_INVITE_XUID_DECIMAL, CONTROLLER_INDEX_FIRST, va("%llu", acceptingCrossExeInviteFrom));
		Dvar_SetString(FriendXuidToJoinOnBoot, va("%lld", 0i64));
		g_launchData.gameInviteAccepted = 1;
	}
	else
	{
		StringToXUIDDecimal(GamerProfile_GetString(PROFILE_INVITE_XUID_DECIMAL, CONTROLLER_INDEX_FIRST), &acceptingCrossExeInviteFrom);
		if (acceptingCrossExeInviteFrom)
			g_launchData.gameInviteAccepted = 1;
	}
}

/*
==============
Com_RunAutoExec
==============
*/
void Com_RunAutoExec(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex)
{
	if (localClientNum >= LOCAL_CLIENT_FIRST)
	{
		Dvar_SetInAutoExec(1);
		Cmd_ExecuteSingleCommand(localClientNum, controllerIndex, "exec autoexec_dev_mp.cfg", 0);
		Dvar_SetInAutoExec(0);
	}
}

/*
==============
Com_ExecStartupConfigs
==============
*/
void Com_ExecStartupConfigs(LocalClientNum_t localClientNum, const char *configFile)
{
	Cbuf_AddText(localClientNum, "exec default_mp.cfg\n");
	if (configFile)
	{
		Cbuf_AddText(localClientNum, va("exec %s\n", configFile));
	}
	Cbuf_Execute(localClientNum, Com_LocalClient_GetControllerIndex(localClientNum));
	if (localClientNum >= LOCAL_CLIENT_FIRST)
	{
		Dvar_SetInAutoExec(1);
		Cmd_ExecuteSingleCommand(localClientNum, Com_LocalClient_GetControllerIndex(localClientNum), "exec autoexec_mp.cfg", 0);
		Dvar_SetInAutoExec(0);
	}
	if (Com_SafeMode())
		Cbuf_AddText(localClientNum, "exec safemode_mp.cfg\n");
	Cbuf_Execute(localClientNum, Com_LocalClient_GetControllerIndex(localClientNum));
}

/*
==============
Com_WriteConfigToFile
==============
*/
void Com_WriteConfigToFile(LocalClientNum_t localClientNum, const char *filename)
{
	fileHandle_t configHandle;

	configHandle = FS_FOpenFileWriteToDir(filename, "players");
	if (configHandle)
	{
		FS_Printf(configHandle, "// generated by Call of Duty, do not modify\n");
#if !DEDICATED
		FS_Printf(configHandle, "unbindall\n");
		Key_WriteBindings(localClientNum, configHandle);
		Gamepad_WriteBindings(localClientNum, configHandle);
#endif
		Dvar_WriteVariables(configHandle);
		Con_WriteFilterConfigString(configHandle);
		FS_FCloseFile(configHandle);
	}
	else
	{
		Com_Printf(CON_CHANNEL_SYSTEM, "Couldn't write %s.\n", filename);
	}
}

/*
==============
Com_isFullyInitialized
==============
*/
BOOL Com_isFullyInitialized()
{
	return com_fullyInitialized != 0;
}

/*
==============
Com_WriteConfig_f
==============
*/
void Com_WriteConfig_f()
{
	char filename[128];

	if (Cmd_Argc() == 2)
	{
		I_strncpyz(filename, Cmd_Argv(1), 128);
		Com_DefaultExtension(filename, 128, ".cfg");
		Com_Printf(CON_CHANNEL_DONT_FILTER, "Writing %s.\n", filename);
		Com_WriteConfigToFile((LocalClientNum_t)0, filename);
	}
	else
	{
		Com_Printf(CON_CHANNEL_DONT_FILTER, "Usage: writeconfig <filename>\n");
	}
}

/*
==============
Com_WriteKeyConfig_f
==============
*/
void Com_WriteKeyConfig_f()
{
	char filename[128];
	int configHandle;

	if (Cmd_Argc() == 2)
	{
		I_strncpyz(filename, Cmd_Argv(1), 128);
		Com_DefaultExtension(filename, 128, ".cfg");
		Com_Printf(CON_CHANNEL_DONT_FILTER, "Writing %s.\n", filename);
		configHandle = FS_FOpenFileWriteToDir(filename, "players");
		if (configHandle)
		{
			FS_Printf(configHandle, "// generated by Call of Duty, do not modify\n");
			FS_FCloseFile(configHandle);
		}
		else
		{
			Com_Printf(CON_CHANNEL_SYSTEM, "Couldn't write %s.\n", filename);
		}
	}
	else
	{
		Com_Printf(CON_CHANNEL_DONT_FILTER, "Usage: writekeyconfig <filename>\n");
	}
}

/*
==============
Com_WriteDefaults_f
==============
*/
void Com_WriteDefaults_f()
{
	char filename[128];
	int configHandle;

	if (Cmd_Argc() == 2)
	{
		I_strncpyz(filename, Cmd_Argv(1), 128);
		Com_DefaultExtension(filename, 128, ".cfg");
		Com_Printf(CON_CHANNEL_DONT_FILTER, "Writing %s.\n", filename);
		configHandle = FS_FOpenFileWrite(filename);
		if (configHandle)
		{
			FS_Printf(configHandle, "// generated by Call of Duty, do not modify\n");
			Dvar_WriteDefaults(configHandle);
			FS_FCloseFile(configHandle);
		}
		else
		{
			Com_Printf(CON_CHANNEL_SYSTEM, "Couldn't write %s.\n", filename);
		}
	}
	else
	{
		Com_Printf(CON_CHANNEL_DONT_FILTER, "Usage: writedefaults <filename>\n");
	}
}

/*
==============
Com_GetTimescaleForSnd
==============
*/
double Com_GetTimescaleForSnd()
{
	int fixedtime_i;
	float fixedtime_f;

	fixedtime_i = Dvar_GetInt(com_fixedtime);
	if (fixedtime_i)
	{
		return fixedtime_i;
	}
	fixedtime_f = Dvar_GetFloat(com_fixedtime_float);
	if (fixedtime_f == 0.0)
	{
		fixedtime_f = Dvar_GetFloat(dev_timescale);
		return Dvar_GetFloat(com_timescale) * fixedtime_f * com_codeTimeScale;
	}
	return fixedtime_f;
}

/*
==============
Com_SetSlowMotion
==============
*/
void Com_SetSlowMotion(const float startTimescale, const float endTimescale, const int deltaMsec)
{
	g_slowmoCommon.delayMsec = 0;
	if (endTimescale == startTimescale)
	{
		com_codeTimeScale = endTimescale;
		g_slowmoCommon.enable = 0;
		g_slowmoCommon.viewTimescale = endTimescale;
		g_slowmoCommon.viewEnable = 0;
	}
	else
	{
		g_slowmoCommon.startTimescale = startTimescale;
		g_slowmoCommon.viewStartTimescale = startTimescale;
		g_slowmoCommon.type = 0;
		g_slowmoCommon.viewType = 0;
		g_slowmoCommon.endTimescale = endTimescale;
		g_slowmoCommon.startMsec = com_frameTime + (((startTimescale - com_codeTimeScale) * deltaMsec) / (endTimescale - startTimescale));
		g_slowmoCommon.viewEndTimescale = endTimescale;
		g_slowmoCommon.viewStartMsec = com_frameTime + (((startTimescale - g_slowmoCommon.viewTimescale) * deltaMsec) / (endTimescale - startTimescale));
		g_slowmoCommon.endMsec = com_frameTime + (((endTimescale - com_codeTimeScale) * deltaMsec) / (endTimescale - startTimescale));
		g_slowmoCommon.enable = 1;
		g_slowmoCommon.viewEndMsec = com_frameTime + (((endTimescale - g_slowmoCommon.viewTimescale) * deltaMsec) / (endTimescale - startTimescale));
		g_slowmoCommon.viewEnable = 1;
	}
}

/*
==============
Com_ResetSlowMotion
==============
*/
void Com_ResetSlowMotion()
{
	g_slowmoCommon.enable = 0;
	g_slowmoCommon.viewEnable = 0;
	g_slowmoCommon.viewTimescale = 1.0;
	g_slowmoCommon.delayMsec = 0;
}

/*
==============
Com_SetSlowMotionDelayed
==============
*/
void Com_SetSlowMotionDelayed(const float startTimescale, const float endTimescale, const int deltaMsec, const int delayMsec)
{
	Com_SetSlowMotion(startTimescale, endTimescale, deltaMsec);
	g_slowmoCommon.delayMsec = delayMsec;
}

/*
==============
Com_ViewScaleMsec
==============
*/
double Com_ViewScaleMsec(float sec)
{
	float msConv;
	float newMs;
	float viewEndTimescale;

	msConv = sec * 1000.0;
	if (g_slowmoCommon.viewEnable)
	{
		if (g_slowmoCommon.viewEndMsec == g_slowmoCommon.viewStartMsec || (viewEndTimescale = (((g_slowmoCommon.viewEndTimescale - g_slowmoCommon.viewStartTimescale) * msConv) / (g_slowmoCommon.viewEndMsec - g_slowmoCommon.viewStartMsec)) + g_slowmoCommon.viewTimescale, g_slowmoCommon.viewTimescale = viewEndTimescale, g_slowmoCommon.viewEndTimescale > g_slowmoCommon.viewStartTimescale) && viewEndTimescale >= g_slowmoCommon.viewEndTimescale || g_slowmoCommon.viewStartTimescale > g_slowmoCommon.viewEndTimescale && g_slowmoCommon.viewEndTimescale >= viewEndTimescale || g_slowmoCommon.viewStartTimescale == g_slowmoCommon.viewEndTimescale)
		{
			viewEndTimescale = g_slowmoCommon.viewEndTimescale;
			g_slowmoCommon.viewTimescale = g_slowmoCommon.viewEndTimescale;
			g_slowmoCommon.viewEnable = 0;
		}
	}
	else
	{
		viewEndTimescale = g_slowmoCommon.viewTimescale;
	}
	newMs = (viewEndTimescale * msConv) * 0.001;
	if ((newMs - 0.001) < 0.0)
		return 0.001;
	else
		return newMs;
}

/*
==============
Com_Frame_Try_Block_Function
==============
*/
void Com_Frame_Try_Block_Function()
{
	AssertEq(Cmd_Args()->nesting, -1);
	PIXBeginNamedEvent(-1, "Com_Frame");
#if !DEDICATED
	Com_WriteConfiguration(LOCAL_CLIENT_FIRST);
#endif
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_WriteConfiguration
==============
*/
void Com_WriteConfiguration(LocalClientNum_t localClientNum)
{
	char configFile[64];
	if (Com_isFullyInitialized() && (g_dvar_modifiedFlags & 1) != 0)
	{
		g_dvar_modifiedFlags &= -1;
		I_strncpyz(configFile, "config_mp.cfg", sizeof(configFile));
		if (Dvar_GetBool(com_useConfig))
		{
			Com_WriteConfigToFile(localClientNum, configFile);
		}
		else
		{
			FS_Delete(configFile);
		}
	}
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
	XZoneInfo zoneInfo[1];

	if (!DB_IsZoneTypeLoaded(128) && !DB_IsZoneTypeLoading(128))
	{
		DB_ResetZoneSize(0);
		if (Dvar_GetBool(useFastFile))
			DB_ReleaseXAssets();
		if (!DB_IsZoneTypeLoaded(128))
		{
			zoneInfo[0].name = COMMON_FAST_FILE_NAME;
			zoneInfo[0].allocFlags = 128;
			zoneInfo[0].freeFlags = 0;
			DB_LoadXAssets(zoneInfo, 1u, 0);
		}
	}
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
	XZoneInfo zoneInfo[2];
	int zoneCount;

	if (Dvar_GetBool(useFastFile))
	{
		zoneCount = 0;
		if (Com_SessionMode_IsZombiesGame())
		{
			zoneInfo[0].name = 0;
			zoneInfo[0].allocFlags = 0;
			zoneInfo[0].freeFlags = 0x40000;
			zoneCount = 1;
		}
		zoneInfo[zoneCount].name = 0;
		zoneInfo[zoneCount].allocFlags = 0;
		zoneInfo[zoneCount].freeFlags = 0x1C400;
		DB_LoadXAssets(zoneInfo, zoneCount + 1, 0);
	}
}

/*
==============
Com_LoadLevelFastFiles
==============
*/
void Com_LoadLevelFastFiles(const char *mapName)
{
	int zoneCount = 0;
	const char* LevelSharedFastFile;
	const char* String;
	const char* baseMapName;
	XZoneInfo zoneInfo[6];
	char axis[64];
	char addon_filename[64];
	char allies[64];

	DB_ResetZoneSize(0);
	if (!mapName)
	{
		if (DB_IsZoneTypeLoaded(0x2000000))
		{
			while (R_Is3DOn())
			{
				if (mapName)
				{
					if (!I_strcmp(mapName, "ui_mp") || !I_strcmp(mapName, "ui_zm"))
					{
						break;
					}
				}
				else if (DB_IsZoneTypeLoaded(0x2000000))
				{
					break;
				}
				DB_LoadLoadFastfilesForNewContent();
				DB_SyncXAssets();
				NET_Sleep(1u);
			}
		}
		Com_LoadCommonFastFile();
	}
	if (I_strcmp(mapName, "ui_mp") && I_strcmp(mapName, "ui_zm"))
	{
		Com_LoadCommonFastFile();
	}
	while (R_Is3DOn())
	{
		if (mapName)
		{
			if (!I_strcmp(mapName, "ui_mp") || !I_strcmp(mapName, "ui_zm"))
				break;
		}
		else if (DB_IsZoneTypeLoaded(0x2000000))
		{
			break;
		}
		DB_LoadLoadFastfilesForNewContent();
		DB_SyncXAssets();
		NET_Sleep(1u);
	}
	Phys_ReEvalPriority();
	zoneInfo[zoneCount].name = 0;
	zoneInfo[zoneCount].allocFlags = 0;
	zoneInfo[zoneCount++].freeFlags = 167772160;
	LevelSharedFastFile = Com_GetLevelSharedFastFile(mapName);
	if (LevelSharedFastFile)
	{
		zoneInfo[zoneCount].name = LevelSharedFastFile;
		zoneInfo[zoneCount].allocFlags = 4096;
		zoneInfo[zoneCount++].freeFlags = 0;
	}
	if (Com_IsAddonMap(mapName, &baseMapName))
	{
		zoneInfo[zoneCount].name = baseMapName;
		zoneInfo[zoneCount].allocFlags = 0x8000;
		zoneInfo[zoneCount++].freeFlags = 0;
		zoneInfo[zoneCount].name = mapName;
		zoneInfo[zoneCount].allocFlags = 0x40000;
		zoneInfo[zoneCount++].freeFlags = 0;
	}
	else
	{
		zoneInfo[zoneCount].name = mapName;
		zoneInfo[zoneCount].allocFlags = 0x8000;
		zoneInfo[zoneCount++].freeFlags = -2147385344;
		if (Com_SessionMode_IsZombiesGame())
		{
			if (DB_ZoneLoadsOverlays(mapName))
			{
				_snprintf(addon_filename, 0x40u, "so_%s_%s", Dvar_GetString(ui_zm_gamemodegroup), mapName);
				zoneInfo[zoneCount].name = addon_filename;
				zoneInfo[zoneCount].allocFlags = 0x40000;
				zoneInfo[zoneCount++].freeFlags = 0x80000000;
			}
			if (Dvar_GetBool(tu6_startMovieEarly) && Dvar_GetBool(ui_zm_useloadingmovie))
			{
				R_Cinematic_StartPlayback(va("%s_load", mapName), 0, 1.0, 0, 0);
			}
		}
		else
		{
			if (Com_FactionFastFileAllies(mapName, allies, 64))
			{
				zoneInfo[zoneCount].name = allies;
				zoneInfo[zoneCount].allocFlags = 0x8000;
				zoneInfo[zoneCount++].freeFlags = 0;
			}
			if (Com_FactionFastFileAxis(mapName, axis, 64))
			{
				zoneInfo[zoneCount].name = axis;
				zoneInfo[zoneCount].allocFlags = 0x8000;
				zoneInfo[zoneCount++].freeFlags = 0;
			}
		}
	}
	R_BeginRemoteScreenUpdate();
	DB_LoadXAssets(zoneInfo, zoneCount, 0);
	R_EndRemoteScreenUpdate();
}

/*
==============
Com_LoadLevelFastFiles_BlockForOverlay
==============
*/
void Com_LoadLevelFastFiles_BlockForOverlay(const char *mapName)
{
	if (Com_IsAddonMap(mapName, 0))
	{
		DB_SyncXAssets();
	}
}

/*
==============
Com_UnloadFrontEnd
==============
*/
void Com_UnloadFrontEnd()
{
	XZoneInfo zoneInfo[1];

	LiveFileshare_Mem_Shutdown();
#if XENON
	for (int i = 0; i < 4; ++i)
	{
		UI_CloseAll(i);
	}
#else
	UI_CloseAll(LOCAL_CLIENT_FIRST);
#endif
	if (Dvar_GetBool(useFastFile))
	{
		DB_ReleaseXAssets();
		zoneInfo[0].name = 0;
		zoneInfo[0].allocFlags = 0;
#if XENON
		zoneInfo[0].freeFlags = 0x14000000;
#else
		zoneInfo[0].freeFlags = 0x1E000000;
#endif
		DB_LoadXAssets(zoneInfo, 1u, 0);
	}
	R_UI3D_Shutdown();
}

/*
==============
Com_ResetFrametime
==============
*/
void Com_ResetFrametime()
{
	com_frameTime = Sys_Milliseconds();
}

/*
==============
Com_CheckSyncFrame
==============
*/
void Com_CheckSyncFrame()
{
#if XENON
	SV_WaitSaveGame();
	DB_Update();
#else
	DB_Update();
	if (Sys_WaitForGumpLoad(0) && Scr_IsSystemActive(SCRIPTINSTANCE_CLIENT))
	{
		Sys_GumpPrint("send gump_flushed notify to script\n");
		Scr_AddInt(SCRIPTINSTANCE_CLIENT, 1);
		CScr_NotifyLevel(Com_LocalClients_GetPrimaryDefault(), "gump_loaded");
	}
	if (Sys_WaitForGumpFlush(0))
	{
		if (Scr_IsSystemActive(SCRIPTINSTANCE_CLIENT))
		{
			Sys_GumpPrint("send gump_flushed notify to script\n");
			Scr_AddInt(SCRIPTINSTANCE_CLIENT, 1);
			CScr_NotifyLevel(Com_LocalClients_GetPrimaryDefault(), "gump_flushed");
		}
	}
#endif
}

/*
==============
Com_LogFileOpen
==============
*/
BOOL Com_LogFileOpen()
{
	return logfile != 0;
}

/*
==============
Field_Clear
==============
*/
void Field_Clear(field_t *edit)
{
#if XENON
	XMemSet(edit->buffer, 0, sizeof(edit->buffer));
#else
	memset(edit->buffer, 0, sizeof(edit->buffer));
	edit->cursor = 0;
	edit->scroll = 0;
	edit->drawWidth = 256;
#endif
}

/*
==============
Com_Restart
==============
*/
void Com_Restart()
{
	XZoneInfo zoneInfo[1];

	com_codeTimeScale = 1.0;
	BB_Send(INVALID_CONTROLLER_PORT, 1, 0);
	CL_ShutdownHunkUsers();
	SV_ShutdownGameProgs();
	Com_ShutdownDObj();
	DObjShutdown();
	XAnimShutdown();
	CL_FlushGumps();
	Demo_DeallocatePlaybackMemory();
	GlassCl_FreeMemory();
	R_UI3D_Shutdown();
	R_ExtraCam_Shutdown();
	BB_ResetHighWaterMarks();
	if (Dvar_GetBool(useFastFile))
	{
		zoneInfo[0].name = 0;
		zoneInfo[0].allocFlags = 0;
		zoneInfo[0].freeFlags = 0x1000000;
		DB_LoadXAssets(zoneInfo, 1u, 0);
	}
	Com_ShutdownWorld();
	CM_Shutdown();
	Hunk_Clear();
	Hunk_UserReset(g_ScriptDebugHunk);
	CL_ShutdownDebugData();
	if (Dvar_GetBool(useFastFile))
	{
		DB_ReleaseXAssets();
	}
	Scr_Settings(SCRIPTINSTANCE_SERVER, Dvar_GetInt(com_developer), Dvar_GetBool(com_developer_script), 0);
	Scr_Settings(SCRIPTINSTANCE_CLIENT, Dvar_GetInt(com_developer), Dvar_GetBool(com_developer_script), 0);
	com_fixedConsolePosition = 0;
	XAnimInit();
	DObjInit();
	Com_InitDObj();
	com_codeTimeScale = 1.0;
	g_slowmoCommon.enable = 0;
	g_slowmoCommon.viewEnable = 0;
	g_slowmoCommon.viewTimescale = 1.0;
	g_slowmoCommon.delayMsec = 0;
	Flame_Init();
}

/*
==============
CG_AllocAnimTree
==============
*/
void *CG_AllocAnimTree(int size)
{
	return MT_Alloc(size, 5);
}

/*
==============
Com_XAnimCreateSmallTree
==============
*/
XAnimTree_s *Com_XAnimCreateSmallTree(XAnim_s *anims)
{
	return XAnimCreateTree(anims, CG_AllocAnimTree);
}

/*
==============
Com_XAnimFreeSmallTree
==============
*/
void Com_XAnimFreeSmallTree(XAnimTree_s *animtree)
{
	XAnimFreeTree(animtree, MT_Free);
}

/*
==============
Com_SetWeaponInfoMemory
==============
*/
void Com_SetWeaponInfoMemory(int source)
{
	weaponInfoSource = source;
}

/*
==============
Com_FreeWeaponInfoMemory
==============
*/
void Com_FreeWeaponInfoMemory(int source)
{
	if (source == weaponInfoSource)
	{
		weaponInfoSource = 0;
		BG_ShutdownWeaponDefFiles();
	}
}

/*
==============
Com_GetWeaponInfoMemory
==============
*/
int Com_GetWeaponInfoMemory()
{
	return weaponInfoSource;
}

/*
==============
Com_AddToString
==============
*/
int Com_AddToString(const char *add, char *msg, int len, int maxlen, int mayAddQuotes)
{
	int addQuotes;
	int i;

	addQuotes = 0;
	if (mayAddQuotes)
	{
		if (*add)
		{
			for (i = 0; i < maxlen - len && add[i]; ++i)
			{
				if (add[i] <= 32)
				{
					addQuotes = 1;
					break;
				}
			}
		}
		else
		{
			addQuotes = 1;
		}
	}
	if (addQuotes && len < maxlen)
	{
		msg[len++] = 34;
	}
	for (i = 0; len < maxlen && add[i]; ++i)
	{
		msg[len++] = add[i];
	}
	if (addQuotes && len < maxlen)
	{
		msg[len++] = 34;
	}
	return len;
}

/*
==============
Com_GetDecimalDelimiter
==============
*/
char Com_GetDecimalDelimiter()
{
	return '.';
}

/*
==============
Com_LocalizedFloatToString
==============
*/
void Com_LocalizedFloatToString(float f, char *buffer, unsigned int maxlen, unsigned int numDecimalPlaces)
{
	_snprintf(buffer, maxlen - 1, "%.*f", numDecimalPlaces, f);
	buffer[maxlen - 1] = 0;
}

/*
==============
Com_SyncThreads
==============
*/
void Com_SyncThreads()
{
	R_SyncRenderThread();
	if (Dvar_GetBool(com_sv_running))
	{
		SV_WaitServer();
		SV_AllowPackets(0);
	}
}

/*
==============
Com_DisplayName
==============
*/
const char *Com_DisplayName(const char *name, const char *clanAbbrev, int type)
{
	if (clanAbbrev[0])
		type &= ~2;
	switch (type)
	{
	case 3u:
		return va("%c%s%c%s", '[', clanAbbrev, ']', name);
	case 1u:
		return name;
	case 2u:
		return va("%c%s%c", '[', clanAbbrev, ']');
	}
	return "";
}

/*
==============
CS_DisplayName
==============
*/
char *CS_DisplayName(const clientState_s *cs, int type)
{
	if (!cs->clanAbbrev[0])
		type &= ~2;
	if (type == 3)
		return va("%c%s%c%s", '[', cs->clanAbbrev, ']', cs->name);
	if (type != 1)
	{
		if (type == 2)
			return va("%c%s%c", '[', cs->clanAbbrev, ']');
		else
			return "";
	}
	return (char*)cs->name;;
}

/*
==============
Com_GetPrivateClients
==============
*/
int Com_GetPrivateClients()
{
	int privateClients;

	if (!Dvar_GetInt(com_maxclients))
	{
		privateClients = Dvar_GetInt(com_maxclients);
		AssertMsg("privateClients doesn't index Dvar_GetInt( com_maxclients )\n\t%i not in [0, %i)", 0, privateClients);
	}
	return 0;
}

/*
==============
Com_InitUIAndCommonXAssets
==============
*/
void Com_InitUIAndCommonXAssets()
{
	Com_UnloadLevelFastFiles();
}

/*
==============
NetAdr_SetType
==============
*/
void NetAdr_SetType(netadr_t *addr, netadrtype_t type)
{
	addr->type = type;
	if (type == NA_LOOPBACK)
		addr->inaddr = 0x100007F;
}

/*
==============
Com_UseRawUDP
==============
*/
bool Com_UseRawUDP()
{
	return Com_GetClientPlatform() == CLIENT_PLATFORM_XENON;
}

/*
==============
Com_Quit_f
==============
*/
void Com_Quit_f()
{
	if (!Dvar_GetBool(com_sv_running) || !Com_SessionMode_IsPublicOnlineGame())
	{
		Com_Printf(CON_CHANNEL_DONT_FILTER, "quitting...\n");
		DB_SyncXAssets();
		R_PopRemoteScreenUpdate();
		R_SyncRenderThread();
		if (Dvar_GetBool(com_sv_running))
		{
			SV_WaitServer();
			SV_AllowPackets(0);
		}
		BG_EvalVehicleName();
		Sys_EnterCriticalSection(CRITSECT_COM_ERROR);
		com_quitInProgress = 1;
		GScr_Shutdown();
		if (!com_errorEntered)
		{
			Hunk_ClearTempMemory();
			Hunk_ClearTempMemoryHigh();
			Sys_DestroySplashWindow();
			Voice_ClearRemoteTalkers(&g_serverSession);
			Voice_ClearRemoteTalkers(&g_partySession);
			Voice_ClearRemoteTalkers(&g_partyPresenceSession);
			CL_Disconnect(LOCAL_CLIENT_FIRST, 1);
			clientUIActives[0].flags &= ~2u;
			CL_ShutdownDebugData();
			CL_ShutdownHunkUsers();
			Voice_Shutdown();
			Stream_Shutdown();
			SND_Shutdown();
			CL_ShutdownInput();
			CL_RemoveCommands();
			LiveFileshare_Mem_Shutdown();
			SV_Shutdown("EXE_SERVERQUIT");
			Session_EmptyGraveYard();
			CL_ShutdownRef();
			memset(&cls, 0, sizeof(cls));
			SL_ShutdownSystem(1u);
			Com_ShutdownDObj();
			DObjShutdown();
			XAnimShutdown();
			Com_ShutdownWorld();
			CM_Shutdown();
			Live_FileShare_CacheShutdown();
			Hunk_Clear();
			if (Dvar_GetBool(useFastFile))
				DB_ShutdownXAssets();
			Scr_Shutdown(SCRIPTINSTANCE_SERVER);
			Scr_Shutdown(SCRIPTINSTANCE_CLIENT);
			NET_ShutdownDebug();
			Hunk_UserShutdown();
			CL_FreePerLocalClientMemory(0);
			Com_LocalClients_GetPrimary();
			if (logfile)
			{
				FS_FCloseLogFile(logfile);
				logfile = 0;
			}
			FS_Shutdown();
			FS_ShutDownIwdPureCheckReferences();
			FS_ShutdownServerIwdNames();
			FS_ShutdownServerReferencedIwds();
			FS_ShutdownServerReferencedFFs();
			BG_EvalVehicleName();
		}
		Sys_Quit();
	}
	if (!SV_IsMigrating())
	{
		Cbuf_AddText(Com_LocalClients_GetPrimary(), "hostmigration_start\n");
	}
	com_quitAfterHostMigrates = 1;
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

