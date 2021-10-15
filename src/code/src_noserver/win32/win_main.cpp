#include "types.h"
#include "functions.h"
#include "vars.h"

#include "win32_public.h"
#include <client/client_public.h>
#include <clientscript/clientscript_public.h>
#include <live/live_public.h>
#include <gfx_d3d/gfx_d3d_public.h>
#include <game/game_public.h>
#include <qcommon/qcommon_public.h>
#include <universal/universal_public.h>
#include <server_mp/server_mp_public.h>

bool g_pc_nosnd;
bool g_quitRequested;
bool g_dwUseDevLSG;
bool g_pc_snd_defaultdevice;

bool enable_OutputDebugString = true;

char errPtr[4096];
char sys_cmdline[1024];
char theOtherExeName[256];
char g_identityParams[7][256];

SysInfo sys_info;

/*
==============
Sys_FindInfo
==============
*/
void Sys_FindInfo()
{
	sys_info.logicalCpuCount = Sys_GetCpuCount();
	sys_info.cpuGHz = 1.0 / (((double)1i64 - (double)0i64) * msecPerRawTimerTick * 1000000.0);
	sys_info.sysMB = Sys_SystemMemoryMB();
	Sys_DetectVideoCard(512, sys_info.gpuDescription);
	Sys_DetectCpuVendorAndName(sys_info.cpuVendor, sys_info.cpuName);
	Sys_SetAutoConfigureGHz(&sys_info);
}

/*
==============
Sys_OutOfMemErrorInternal
==============
*/
void Sys_OutOfMemErrorInternal(const char *filename, int line)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_QuitAndStartProcess
==============
*/
void Sys_QuitAndStartProcess(const char *exeName, const char *parameters)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_SpawnQuitProcess
==============
*/
void Sys_SpawnQuitProcess()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_Error
==============
*/
void Sys_Error(const char *error, ...)
{
	tagMSG Msg;
	char string[4096];
	va_list ap;

	va_start(ap, error);
	_vsnprintf(string, 0x1000u, error, ap);
	string[4095] = 0;
	Com_PrintStackTrace(0, 0);
	Com_PrintError(10, "\nSys_Error: %s\n\n", string);
	//BB_Alert(__FILE__, __LINE__, "sys_error", string);
	FixWindowsDesktop();
	if (IsDebuggerConnected())
		__debugbreak();
	SV_SysLog_LogMessage(0, string);
	SV_SysLog_ForceFlush();
	if (Sys_IsMainThread())
	{
		LiveSteam_Shutdown();
		Sys_ShowConsole();
		Conbuf_AppendText("\n\n");
		Conbuf_AppendText(string);
		Conbuf_AppendText("\n");
		Sys_SetErrorText(string);
		while (GetMessageA(&Msg, 0, 0, 0))
		{
			TranslateMessage(&Msg);
			DispatchMessageA(&Msg);
		}
		exit(0);
	}
	if (Sys_IsServerThread())
		Sys_ServerCompleted();
	I_strncpyz(errPtr, string, 4096);
	if (Sys_IsMainThread())
	{
		if (errPtr[0])
			Sys_Error(errPtr);
		Sys_Error("Error quit was requested in the main thread\n");
	}
	g_quitRequested = 1;
	while (1)
		NET_Sleep(0x64u);
}

/*
==============
Sys_Print
==============
*/
void Sys_Print(const char *msg)
{
	if (enable_OutputDebugString)
		OutputDebugString(msg);
	Conbuf_AppendTextInMainThread(msg);
	SV_SysLog_LogMessage(0, msg);
}

/*
==============
Sys_GetClipboardData
==============
*/
char *Sys_GetClipboardData()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Sys_FreeClipboardData
==============
*/
void Sys_FreeClipboardData(char *text)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_QueEvent
==============
*/
void Sys_QueEvent(int time, sysEventType_t type, int value, int value2, int ptrLength, void *ptr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_ShutdownEvents
==============
*/
void Sys_ShutdownEvents()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Win_GetEvent
==============
*/
sysEvent_t *Win_GetEvent(WinQuitBehavior quitBehavior)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Sys_LoadingKeepAlive
==============
*/
void Sys_LoadingKeepAlive()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_GetEvent
==============
*/
sysEvent_t *Sys_GetEvent(sysEvent_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Sys_Net_Restart_f
==============
*/
void __cdecl Sys_Net_Restart_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_Init
==============
*/
void Sys_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PrivateUnhandledExceptionFilter
==============
*/
int PrivateUnhandledExceptionFilter(_EXCEPTION_POINTERS *ExceptionInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_ReadIdentity
==============
*/
char Sys_ReadIdentity(const char *id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_GetIdentityParam
==============
*/
char *Sys_GetIdentityParam(IdentityParam p)
{
	return g_identityParams[p];
}

/*
==============
getArgFromString
==============
*/
char *getArgFromString(const char *src, const char *marker, char *dst, unsigned int dstSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
checkcmdlineValid
==============
*/
void checkcmdlineValid()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DedicatedInit
==============
*/
void DedicatedInit(const char *cmdline)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
InitMiniDumper
==============
*/
void InitMiniDumper(char *lpCmdLine)
{
	if (I_stristr(lpCmdLine, "autodump"))
	{
		Sys_StartMiniDump(0);
	}
	else if (I_stristr(lpCmdLine, "minidump") || !I_stristr(lpCmdLine, "nodump"))
	{
		Sys_StartMiniDump(1);
	}
	else
	{
		SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)PrivateUnhandledExceptionFilter);
	}
}

/*
==============
Win_GetTheOtherExeName
==============
*/
char *Win_GetTheOtherExeName(const char *mode)
{
	bool zm;
	char fullpath[260];
	char ext[256];
	char filename[256];
	char* filenameMode;
	const char* m_mode;
	int namesize;
	int otherExeSize;

	if (tolower(*mode) != 'z' || (zm = 1, tolower(mode[1]) != 'm'))
		zm = 0;
	GetModuleFileNameA(0, fullpath, 0x104u);
	_splitpath(fullpath, 0, 0, filename, ext);
	filenameMode = strrchr(filename, '_');
	if (filenameMode)
		namesize = filenameMode - filename;
	else
		namesize = strlen(filename);
	otherExeSize = namesize - 1;
	if (namesize - 1 > 256)
		otherExeSize = 256;
	I_strncpyz(theOtherExeName, filename, otherExeSize);
	m_mode = "mp";
	if (!zm)
		m_mode = mode;
	I_strncat(theOtherExeName, 256, m_mode);
	if (filenameMode)
		I_strncat(theOtherExeName, 256, filenameMode);
	I_strncat(theOtherExeName, 256, ext);
	return theOtherExeName;
}

/*
==============
Win_CheckForEnv
==============
*/
void Win_CheckForEnv(const char *cmdline)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Win_CheckForZombieMode
==============
*/
bool Win_CheckForZombieMode(const char *cmdline)
{
	char fullpath[260];
	char filename[256];

	GetModuleFileNameA(0, fullpath, 0x104u);
	_splitpath(fullpath, 0, 0, filename, 0);
	return !I_strcmp(filename, "t6zm") || I_stristr(cmdline, "+zm");
}

/*
==============
Sys_CheckQuitRequest
==============
*/
void Sys_CheckQuitRequest()
{
	if (g_quitRequested && Sys_IsMainThread())
	{
		if (errPtr[0])
			Sys_Error(errPtr);
		Sys_Error("Error quit was not requested in the main thread\n");
	}
}

/*
==============
Sys_Quit
==============
*/
void Sys_Quit()
{
	Sys_EnterCriticalSection(CRITSECT_COM_ERROR);
	timeEndPeriod(1);
	Sys_SpawnQuitProcess();
	IN_Shutdown();
	Key_Shutdown();
	Sys_DestroyConsole();
	Win_ShutdownLocalization();
	RefreshQuitOnErrorCondition();
	Dvar_Shutdown();
	Cmd_Shutdown();
	//BG_EvalVehicleName();
	//BG_EvalVehicleName();
	Sys_ShutdownEvents();
	SL_Shutdown();
	if (!com_errorEntered)
		track_shutdown(0);
	Con_ShutdownChannels();
	LiveSteam_Shutdown();
	ExitProcess(0);
}

/*
==============
WinMain
==============
*/
int WinMain(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *lpCmdLine, int nCmdShow)
{
	HMODULE USER32;
	BOOL isZombies;
	BOOL(__stdcall * SetProcessDPIAware)();
	char pnbuf[256];

	USER32 = LoadLibrary("user32.dll");
	if (USER32)
	{
		SetProcessDPIAware = GetProcAddress(USER32, "SetProcessDPIAware");
		if (SetProcessDPIAware)
			SetProcessDPIAware();
		FreeLibrary(USER32);
	}
	InitMiniDumper(lpCmdLine);
	Sys_CreateConsole(hInstance);
	Sys_ShowConsole();
	if (I_stristr(lpCmdLine, "usedevlsg"))
	{
		g_dwUseDevLSG = 1;
	}
	else if (I_stristr(lpCmdLine, "useprodlsg"))
	{
		g_dwUseDevLSG = 0;
	}
	Sys_InitializeCriticalSections();
	Sys_InitMainThread();
	g_quitRequested = 0;
	Com_InitParse();
	if (DEDICATED)
		DedicatedInit(lpCmdLine);
	PMem_Init();
	track_init();
	isZombies = Win_CheckForZombieMode(lpCmdLine);
	R_SetIsMultiplayer(1);
	R_SetIsZombie(isZombies);
	Win_InitLocalization(isZombies);
	if (G_ExitAfterConnectPaths())
	{
		g_pc_nosnd = 1;
	}
	else if (GetSystemMetrics(4096))
	{
		g_pc_nosnd = 1;
	}
	else if (I_stristr(lpCmdLine, "nosnd"))
	{
		g_pc_nosnd = 1;
	}
	else if (I_stristr(lpCmdLine, "shield"))
	{
		g_pc_snd_defaultdevice = 1;
	}
	if (!hPrevInstance)
	{
		SL_Init();
		Dvar_Init();
		InitTiming();
		Sys_FindInfo();
		I_strncpyz(sys_cmdline, lpCmdLine, 1024);
		SetErrorMode(1u);
		Sys_Milliseconds();
		//tlPrintf("Hello from the wonderful world of TL\n");
		Sys_SetupTLCallbacks(9437184);
		Con_InitChannels();
		TaskManager2_Init();
		if (isZombies)
		{
			Com_Printf(10, "----> Zombie Session Mode Set! <----\n");
			Com_SessionMode_SetMode(SESSIONMODE_ZOMBIES, 1);
		}
		Win_CheckForEnv(lpCmdLine);
		Live_Base_Init();
		Live_Base_Pump();
		assert(Sys_IsMainThread());
		Com_Init(sys_cmdline);
		Live_Base_Pump();
		_getcwd(pnbuf, 256);
		Com_Printf(10, "Working directory: %s\n", pnbuf);
		if (Dvar_GetBool(com_script_debugger_smoke_test))
			exit(31415);
		while (1)
		{
			Sleep(5u);
			if (g_quitRequested && Sys_IsMainThread())
				break;
			Com_Frame();
		}
		if (errPtr[0])
			Sys_Error(errPtr);
		Sys_Error("Error quit was not requested in the main thread\n");
	}
	Win_ShutdownLocalization();
	track_shutdown(0);
	return 0;
}

