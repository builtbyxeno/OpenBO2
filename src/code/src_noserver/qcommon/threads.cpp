#include "types.h"
#include "vars.h"
#include "qcommon_public.h"
#include <qcommon/qcommon_public.h>
#include <gfx_d3d/r_pix_profile.h>
#include <gfx_d3d/gfx_d3d_public.h>
#include <win32/win32_public.h>

unsigned long threadId[THREAD_CONTEXT_COUNT];
void* threadHandle[THREAD_CONTEXT_COUNT];
void* g_threadValues[THREAD_CONTEXT_COUNT][5];
__declspec(thread) void* g_dwTlsIndex[THREAD_CONTEXT_COUNT];
__declspec(thread) DWORD g_currentThreadId;

void* volatile smpData;

unsigned int s_affinityMaskForCpu[8];
unsigned int s_affinityMaskForProcess;
unsigned int s_cpuCount;
unsigned int g_networkOverrideThread;

int g_databaseStopServer;

const char* s_threadNames[17] =
{
  "Main",
  "Backend",
  "Worker0",
  "Worker1",
  "Worker2",
  "Worker3",
  "Worker4",
  "Worker5",
  "Worker6",
  "Worker7",
  "Server",
  "TitleServer",
  "Database",
  "Stream",
  "Sound Mix",
  "Sound Decode",
  "WebM Decode"
};

typedef void (*threadFunction_t)(unsigned int);
threadFunction_t threadFunc[THREAD_CONTEXT_COUNT];

HANDLE databaseCompletedEvent;
HANDLE wakeDatabaseEvent;
HANDLE databaseCompletedEvent2;
HANDLE resumedDatabaseEvent;

HANDLE wakeServerEvent;
HANDLE serverCompletedEvent;
HANDLE allowServerNetworkEvent;
HANDLE serverNetworkCompletedEvent;

HANDLE renderPausedEvent;
HANDLE renderCompletedEvent;
HANDLE resourcesFlushedEvent;
HANDLE resourcesQueuedEvent;
HANDLE rendererRunningEvent;
HANDLE updateSpotLightEffectEvent;
HANDLE updateEffectsEvent;
HANDLE d3dDeviceOKEvent;
HANDLE d3dDeviceHardStartEvent;
HANDLE d3dShutdownEvent;
HANDLE d3dDeviceWinMessageEvent;
HANDLE win32QuitEvent;
HANDLE win32ScriptDebuggerDrawEvent;
HANDLE rgRegisteredEvent;
HANDLE renderEvent;
HANDLE gumpFlushedEvent;
HANDLE gumpLoadedEvent;
HANDLE demoStreamingReady;
HANDLE webmStreamingReady;
HANDLE backendEvent[BACKEND_EVENT_COUNT];
HANDLE sndInitializedEvent;
HANDLE streamCompletedEvent;
HANDLE streamDatabasePausedReading;
HANDLE streamEvent;

/*
==============
NET_Sleep
==============
*/
void NET_Sleep(unsigned int timeInMs)
{
	Sleep(timeInMs);
}

/*
==============
Sys_SetEvent
==============
*/
void Sys_SetEvent(void **event)
{
	SetEvent(*event);
}

/*
==============
Sys_ResetEvent
==============
*/
void Sys_ResetEvent(void **event)
{
	ResetEvent(*event);
}

/*
==============
Sys_CreateEvent
==============
*/
void Sys_CreateEvent(int manualReset, int initialState, void **evt)
{
	*evt = CreateEvent(NULL, manualReset, initialState, NULL);
	if (!evt)
	{
		Com_Printf(CON_CHANNEL_ERROR, "error %d while creating event\n", GetLastError());
	}
}

/*
==============
Sys_WaitForSingleObjectTimeout
==============
*/
BOOL Sys_WaitForSingleObjectTimeout(void **event, unsigned int msec)
{
	assert(msec != INFINITE);
	return WaitForSingleObject(*event, msec) == 0;
}

/*
==============
Sys_WaitForSingleObject
==============
*/
void Sys_WaitForSingleObject(void **event)
{
	unsigned int result;
	result = WaitForSingleObject(*event, INFINITE);
	assertMsg((result == ((((DWORD)0x00000000L)) + 0)), "(result) = %i", result);
}

/*
==============
Sys_GetCpuCount
==============
*/
unsigned int Sys_GetCpuCount()
{
	return s_cpuCount;
}

/*
==============
Win_InitThreads
==============
*/
void Win_InitThreads()
{
	unsigned int cpuCount;
	unsigned int systemAffinityMask;
	unsigned int threadAffinityMask;
	unsigned int affinityMaskBits[32];
	unsigned int processAffinityMask;

	GetProcessAffinityMask(GetCurrentProcess(), (PDWORD_PTR)&processAffinityMask, (PDWORD_PTR)&systemAffinityMask);
	s_affinityMaskForProcess = processAffinityMask;
	cpuCount = 0;
	for (threadAffinityMask = 1; processAffinityMask & -threadAffinityMask; threadAffinityMask *= 2)
	{
		if (processAffinityMask & threadAffinityMask)
		{
			affinityMaskBits[cpuCount++] = threadAffinityMask;
			if (cpuCount == 32)
			{
				break;
			}
		}
	}
	if (cpuCount && cpuCount != 1)
	{
		s_cpuCount = cpuCount;
		s_affinityMaskForCpu[0] = affinityMaskBits[0];
		s_affinityMaskForCpu[1] = affinityMaskBits[s_cpuCount];
		if (cpuCount != 2)
		{
			if (cpuCount == 3)
			{
				s_affinityMaskForCpu[2] = affinityMaskBits[1];
			}
			else if (cpuCount == 4)
			{
				s_affinityMaskForCpu[2] = affinityMaskBits[1];
				s_affinityMaskForCpu[3] = affinityMaskBits[2];
			}
			else
			{
				s_affinityMaskForCpu[0] = -1;
				s_affinityMaskForCpu[1] = -1;
				s_affinityMaskForCpu[2] = -1;
				s_affinityMaskForCpu[3] = -1;
				s_affinityMaskForCpu[4] = -1;
				s_affinityMaskForCpu[5] = -1;
				s_affinityMaskForCpu[6] = -1;
				s_affinityMaskForCpu[7] = -1;
				if (s_cpuCount >= 8)
				{
					s_cpuCount = 8;
				}
			}
		}
	}
	else
	{
		s_cpuCount = 1;
		s_affinityMaskForCpu[0] = -1;
	}
}

/*
==============
Sys_InitMainThread
==============
*/
void Sys_InitMainThread()
{
	HANDLE CurrentProcess;
	HANDLE CurrentThread;

	threadId[THREAD_CONTEXT_MAIN] = GetCurrentThreadId();
	CurrentProcess = GetCurrentProcess();
	CurrentThread = GetCurrentThread();
	DuplicateHandle(CurrentProcess, CurrentThread, CurrentProcess, threadHandle, 0, 0, 2);
	Win_InitThreads();
	SetThreadIdealProcessor(threadHandle[THREAD_CONTEXT_MAIN], 0);
	*g_dwTlsIndex = g_threadValues;
	Com_InitThreadData(0);
}

/*
==============
Sys_InitThread
==============
*/
void Sys_InitThread(int threadContext)
{
	*g_dwTlsIndex = g_threadValues[threadContext];
	Com_InitThreadData(threadContext);
}

/*
==============
Sys_ThreadMain
==============
*/
unsigned int Sys_ThreadMain(void *parameter)
{
	unsigned int threadContext;

	threadContext = (unsigned int)parameter;
	assertIn(threadContext, THREAD_CONTEXT_COUNT);
	assert(threadFunc[threadContext]);

	// TODO SetThreadName(-1, s_threadNames[threadContext]);
	Sys_InitThread(threadContext);
	threadFunc[threadContext](threadContext);

	return 0;
}

/*
==============
Sys_CreateThread
==============
*/
void Sys_CreateThread(void (*function)(unsigned int), unsigned int threadContext)
{
	assert(threadFunc[threadContext] == NULL);
	assert(threadContext < THREAD_CONTEXT_COUNT);

	threadFunc[threadContext] = function;
	threadHandle[threadContext] = CreateThread(
		NULL,
		0,
		(LPTHREAD_START_ROUTINE)Sys_ThreadMain,
		(LPVOID)threadContext,
		4,
		&threadId[threadContext]);

	assert(threadHandle[threadContext] != NULL);
	if (!threadHandle[threadContext])
	{
		Com_Printf(CON_CHANNEL_ERROR, "error %d while creating thread %d\n", GetLastError(), threadContext);
	}

	// TODO SetThreadName(threadId[threadContext], s_threadNames[threadContext]);
}

/*
==============
Sys_TitleServerThreadData
==============
*/
void Sys_TitleServerThreadData()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_InitDemoStreamingEvent
==============
*/
void Sys_InitDemoStreamingEvent()
{
	Sys_CreateEvent(0, 0, &demoStreamingReady);
}

/*
==============
Sys_WaitForDemoStreamingEvent
==============
*/
void Sys_WaitForDemoStreamingEvent()
{
	Sys_WaitForSingleObject(&demoStreamingReady);
}

/*
==============
Sys_WaitForDemoStreamingEventTimeout
==============
*/
BOOL Sys_WaitForDemoStreamingEventTimeout(unsigned int msec)
{
	assertEq(msec == INFINITE);
	return WaitForSingleObject(demoStreamingReady, msec) == 0;
}

/*
==============
Sys_SetDemoStreamingEvent
==============
*/
void Sys_SetDemoStreamingEvent()
{
	Sys_SetEvent(&demoStreamingReady);
}

/*
==============
Sys_InitWebMStreamingEvent
==============
*/
void Sys_InitWebMStreamingEvent()
{
	Sys_CreateEvent(0, 0, &webmStreamingReady);
}

/*
==============
Sys_InitServerEvents
==============
*/
void Sys_InitServerEvents()
{
	Sys_ResetEvent(&wakeServerEvent);
	Sys_ResetEvent(&serverCompletedEvent);
	Sys_SetEvent(&allowServerNetworkEvent);
	Sys_SetEvent(&serverNetworkCompletedEvent);
	g_networkOverrideThread = 0;
}

/*
==============
Sys_NotifyRenderer
==============
*/
void Sys_NotifyRenderer()
{
	Sys_SetEvent(&backendEvent[BACKEND_EVENT_GENERIC]);
}

/*
==============
Sys_WaitServer
==============
*/
BOOL Sys_WaitServer(int timeout)
{
	return Sys_WaitForSingleObjectTimeout(&serverCompletedEvent, timeout);
}

/*
==============
Sys_IsDBPrintingSuppressed
==============
*/
int Sys_IsDBPrintingSuppressed()
{
	return g_supress_db_prints;
}

/*
==============
Sys_StartGumpLoading
==============
*/
void Sys_StartGumpLoading()
{
	g_gump_load_in_progress = 1;
	g_supress_db_prints = 1;
}

/*
==============
Sys_IsLoadingGump
==============
*/
int Sys_IsLoadingGump()
{
	return g_gump_load_in_progress;
}

/*
==============
Sys_WaitForGumpLoad
==============
*/
BOOL Sys_WaitForGumpLoad(int timeout)
{
	return Sys_WaitForSingleObjectTimeout(&gumpLoadedEvent, timeout);
}

/*
==============
Sys_WaitForGumpFlush
==============
*/
BOOL Sys_WaitForGumpFlush(int timeout)
{
	return Sys_WaitForSingleObjectTimeout(&gumpFlushedEvent, timeout);
}

/*
==============
Sys_WakeServer
==============
*/
void Sys_WakeServer()
{
	Sys_SetEvent(&wakeServerEvent);
}

/*
==============
Sys_ServerCompleted
==============
*/
void Sys_ServerCompleted()
{
	Sys_SetEvent(&serverCompletedEvent);
}

/*
==============
Sys_WaitStartServer
==============
*/
BOOL Sys_WaitStartServer(int timeout)
{
	int start;

	start = Sys_WaitForSingleObjectTimeout(&wakeServerEvent, timeout);
	if (start)
	{
		Sys_ResetEvent(&serverCompletedEvent);
	}

	if (g_databaseStopServer)
	{
		start = 0;
	}

	return start;
}

/*
==============
Sys_IsServerThread
==============
*/
BOOL Sys_IsServerThread()
{
	return GetCurrentThreadId() == threadId[THREAD_CONTEXT_SERVER];
}

/*
==============
Sys_IsDatabaseThread
==============
*/
BOOL Sys_IsDatabaseThread()
{
	return GetCurrentThreadId() == threadId[THREAD_CONTEXT_DATABASE];
}

/*
==============
Sys_DatabaseCompleted
==============
*/
void Sys_DatabaseCompleted()
{
	g_databaseStopServer = 1;
	if (serverCompletedEvent)
	{
		Sys_WaitForSingleObject(&serverCompletedEvent);
	}
	Sys_SetEvent(&databaseCompletedEvent);
}

/*
==============
Sys_WaitStartDatabase
==============
*/
void Sys_WaitStartDatabase()
{
	Sys_WaitForSingleObject(&wakeDatabaseEvent);
}

/*
==============
Sys_IsDatabaseReady
==============
*/
BOOL Sys_IsDatabaseReady()
{
	return Sys_WaitForSingleObjectTimeout(&databaseCompletedEvent, 0) == 0;
}

/*
==============
Sys_WakeDatabase
==============
*/
void Sys_WakeDatabase()
{
	Sys_ResetEvent(&databaseCompletedEvent);
}

/*
==============
Sys_NotifyDatabase
==============
*/
void Sys_NotifyDatabase()
{
	Sys_SetEvent(&wakeDatabaseEvent);
}

/*
==============
Sys_DatabaseCompleted2
==============
*/
void Sys_DatabaseCompleted2()
{
	g_databaseStopServer = 0;
	Sys_SetEvent(&databaseCompletedEvent2);
}

/*
==============
Sys_IsDatabaseReady2
==============
*/
BOOL Sys_IsDatabaseReady2()
{
	return Sys_WaitForSingleObjectTimeout(&databaseCompletedEvent2, 0) == 0;
}

/*
==============
Sys_WakeDatabase2
==============
*/
void Sys_WakeDatabase2()
{
	Sys_ResetEvent(&databaseCompletedEvent2);
}

/*
==============
Sys_IsRenderThread
==============
*/
BOOL Sys_IsRenderThread()
{
	return GetCurrentThreadId() == threadId[THREAD_CONTEXT_BACKEND];
}

/*
==============
Sys_IsMainThread
==============
*/
BOOL Sys_IsMainThread()
{
	return GetCurrentThreadId() == threadId[THREAD_CONTEXT_MAIN];
}

/*
==============
Sys_GetThreadContext
==============
*/
int Sys_GetThreadContext()
{
	int i;
	unsigned int currThread;

	currThread = GetCurrentThreadId();
	for (i = 0; i < 17; ++i)
	{
		if (threadId[i] == currThread)
		{
			return i;
		}
	}

	Com_Printf(CON_CHANNEL_ERROR, "Current thread is not in thread table\n");
	assert(0);

	return 15;
}

/*
==============
Sys_SetValue
==============
*/
void Sys_SetValue(int valueIndex, void *data)
{
	g_dwTlsIndex[valueIndex] = data;
}

/*
==============
Sys_GetValue
==============
*/
void *Sys_GetValue(int valueIndex)
{
	return g_dwTlsIndex[valueIndex];
}

/*
==============
Sys_SetWin32QuitEvent
==============
*/
void Sys_SetWin32QuitEvent()
{
	Sys_SetEvent(&win32QuitEvent);
}

/*
==============
Sys_QueryWin32QuitEvent
==============
*/
BOOL Sys_QueryWin32QuitEvent()
{
	return Sys_WaitForSingleObjectTimeout(&win32QuitEvent, 0) == 0;
}

/*
==============
Sys_SetRGRegisteredEvent
==============
*/
void Sys_SetRGRegisteredEvent()
{
	Sys_SetEvent(&rgRegisteredEvent);
}

/*
==============
Sys_QueryRGRegisteredEvent
==============
*/
BOOL Sys_QueryRGRegisteredEvent()
{
	return Sys_WaitForSingleObjectTimeout(&rgRegisteredEvent, 0) == 0;
}

/*
==============
Sys_ResetRGRegisteredEvent
==============
*/
void Sys_ResetRGRegisteredEvent()
{
	Sys_ResetEvent(&rgRegisteredEvent);
}

/*
==============
Sys_WaitRGRegisteredEvent
==============
*/
void Sys_WaitRGRegisteredEvent()
{
	Sys_WaitForSingleObject(&rgRegisteredEvent);
}

/*
==============
Sys_SetRenderEvent
==============
*/
void Sys_SetRenderEvent()
{
	Sys_SetEvent(&renderEvent);
}

/*
==============
Sys_SetD3DShutdownEvent
==============
*/
void Sys_SetD3DShutdownEvent()
{
	Sys_SetEvent(&d3dShutdownEvent);
}

/*
==============
Sys_QueryD3DShutdownEvent
==============
*/
BOOL Sys_QueryD3DShutdownEvent()
{
	return Sys_WaitForSingleObjectTimeout(&d3dShutdownEvent, 0) == 0;
}

/*
==============
Sys_ResetD3DShutdownEvent
==============
*/
void Sys_ResetD3DShutdownEvent()
{
	Sys_ResetEvent(&d3dShutdownEvent);
}

/*
==============
Sys_SpawnStreamThread
==============
*/
bool Sys_SpawnStreamThread(void(__cdecl* function)(unsigned int))
{
	Sys_CreateEvent(1, 0, &sndInitializedEvent);
	Sys_CreateEvent(1, 0, &streamCompletedEvent);
	Sys_CreateEvent(1, 0, &streamDatabasePausedReading);
	Sys_CreateEvent(0, 0, &streamEvent);
	Sys_CreateThread(function, THREAD_CONTEXT_STREAM);
	if (!threadHandle[THREAD_CONTEXT_STREAM])
	{
		return false;
	}
	ResumeThread(threadHandle[THREAD_CONTEXT_STREAM]);
	return true;
}

/*
==============
Sys_StreamSleep
==============
*/
void Sys_StreamSleep()
{
	Sys_SetEvent(&streamCompletedEvent);
	Sys_SetEvent(&streamDatabasePausedReading);
	Sys_WaitForSingleObject(&streamEvent);
	Sys_ResetEvent(&streamCompletedEvent);
	Sys_ResetEvent(&streamDatabasePausedReading);
}

/*
==============
Sys_ResetSndInitializedEvent
==============
*/
void Sys_ResetSndInitializedEvent()
{
	Sys_ResetEvent(&sndInitializedEvent);
}

/*
==============
Sys_QueryStreamPaused
==============
*/
BOOL Sys_QueryStreamPaused()
{
	return Sys_WaitForSingleObjectTimeout(&streamDatabasePausedReading, 1) == 0;
}

/*
==============
Sys_WakeStream
==============
*/
void Sys_WakeStream()
{
	Sys_SetEvent(&streamEvent);
}

/*
==============
Sys_IsStreamThread
==============
*/
BOOL Sys_IsStreamThread()
{
	return GetCurrentThreadId() == threadId[THREAD_CONTEXT_STREAM];
}

/*
==============
Sys_SetServerAllowNetworkEvent
==============
*/
void Sys_SetServerAllowNetworkEvent()
{
	Sys_SetEvent(&allowServerNetworkEvent);
}

/*
==============
Sys_ResetServerAllowNetworkEvent
==============
*/
void Sys_ResetServerAllowNetworkEvent()
{
	Sys_ResetEvent(&allowServerNetworkEvent);
}

/*
==============
Sys_SetServerNetworkCompletedEvent
==============
*/
void Sys_SetServerNetworkCompletedEvent()
{
	Sys_EnterCriticalSection(CRITSECT_NETTHREAD_OVERRIDE);

	assert(g_networkOverrideThread == GetCurrentThreadId());
	g_networkOverrideThread = 0;
	Sys_SetEvent(&serverNetworkCompletedEvent);
	Sys_LeaveCriticalSection(CRITSECT_NETTHREAD_OVERRIDE);
}

/*
==============
Sys_ResetServerNetworkCompletedEvent
==============
*/
void Sys_ResetServerNetworkCompletedEvent()
{
	assert(Sys_IsServerThread());
	Sys_WaitForSingleObject(&allowServerNetworkEvent);
}

/*
==============
Sys_WaitServerNetworkCompleted
==============
*/
void Sys_WaitServerNetworkCompleted()
{
	assert(Sys_IsMainThread());
	Sys_WaitForSingleObject(&serverNetworkCompletedEvent);
}

/*
==============
Sys_GetDefaultWorkerThreadsCount
==============
*/
unsigned int Sys_GetDefaultWorkerThreadsCount()
{
	if (s_cpuCount <= 2)
		return 1;
	if (s_cpuCount <= 4)
		return 2;
	if (s_cpuCount > 10)
		return 8;
	return s_cpuCount - 2;
}

/*
==============
Sys_SpawnServerThread
==============
*/
bool Sys_SpawnServerThread(void (*function)(unsigned int))
{
	Sys_CreateEvent(1, 0, &wakeServerEvent);
	Sys_CreateEvent(1, 0, &serverCompletedEvent);
	Sys_CreateEvent(1, 1, &allowServerNetworkEvent);
	Sys_CreateEvent(1, 1, &serverNetworkCompletedEvent);
	Sys_CreateThread(function, THREAD_CONTEXT_SERVER);
	if (!threadHandle[THREAD_CONTEXT_SERVER])
	{
		return 0;
	}

	ResumeThread(threadHandle[THREAD_CONTEXT_SERVER]);

	return 1;
}

/*
==============
Sys_SpawnDatabaseThread
==============
*/
bool Sys_SpawnDatabaseThread(void(__cdecl* function)(unsigned int))
{
	Sys_CreateEvent(0, 0, &wakeDatabaseEvent);
	Sys_CreateEvent(1, 1, &databaseCompletedEvent);
	Sys_CreateEvent(1, 1, &databaseCompletedEvent2);
	Sys_CreateEvent(1, 1, &resumedDatabaseEvent);
	Sys_CreateEvent(0, 0, &gumpLoadedEvent);
	Sys_CreateEvent(0, 0, &gumpFlushedEvent);

	Sys_CreateThread(function, THREAD_CONTEXT_DATABASE);
	if (!threadHandle[THREAD_CONTEXT_DATABASE])
		return false;
	ResumeThread(threadHandle[THREAD_CONTEXT_DATABASE]);
	return true;
}

bool Sys_SpawnRenderThread(void(*function)(unsigned int))
{
	Sys_CreateEvent(0, 0, &renderPausedEvent);
	Sys_CreateEvent(1, 1, &renderCompletedEvent);
	Sys_CreateEvent(1, 1, &rendererRunningEvent);
	Sys_CreateEvent(0, 0, &backendEvent[BACKEND_EVENT_GENERIC]);
	Sys_CreateEvent(1, 0, &backendEvent[BACKEND_EVENT_WORKER_CMD]);
	Sys_CreateEvent(1, 0, &d3dShutdownEvent);
	Sys_CreateEvent(1, 0, &win32QuitEvent);
	Sys_CreateEvent(1, 0, &win32ScriptDebuggerDrawEvent);
	Sys_CreateEvent(1, 0, &rgRegisteredEvent);
	Sys_CreateEvent(1, 0, &renderEvent);
	Sys_CreateThread(function, THREAD_CONTEXT_BACKEND);
	if (!threadHandle[THREAD_CONTEXT_BACKEND])
		return false;
	ResumeThread(threadHandle[THREAD_CONTEXT_BACKEND]);
	return true;
}

/*
==============
Sys_InitWorkerThreadContext
==============
*/
void Sys_InitWorkerThreadContext()
{
	threadId[2] = jqWorkers[1].ThreadId;
	threadId[3] = jqWorkers[2].ThreadId;
	if (s_cpuCount > 2 && s_cpuCount > 4 && (s_cpuCount > 0xA || s_cpuCount - 2 >= 4))
	{
		threadId[4] = jqWorkers[3].ThreadId;
		threadId[5] = jqWorkers[4].ThreadId;
		threadId[6] = jqWorkers[5].ThreadId;
	}
}

/*
==============
Sys_RendererSleep
==============
*/
LONG Sys_RendererSleep()
{
	return InterlockedExchange((volatile LONG*)&smpData, 0);
}

/*
==============
Sys_RendererReady
==============
*/
bool Sys_RendererReady()
{
	return smpData != NULL;
}

/*
==============
Sys_RenderCompleted
==============
*/
void Sys_RenderCompleted()
{
	Sys_SetEvent(&renderCompletedEvent);
	Sys_SetEvent(&backendEvent[BACKEND_EVENT_WORKER_CMD]);
}

/*
==============
Sys_RenderCompleted
==============
*/
void Sys_StopRenderer()
{
	Sys_ResetEvent(&rendererRunningEvent);
	Sys_SetEvent(&renderPausedEvent);
}

/*
==============
Sys_RenderCompleted
==============
*/
void Sys_StartRenderer()
{
	Sys_SetEvent(&rendererRunningEvent);
}

/*
==============
Sys_FrontEndSleep
==============
*/
void Sys_FrontEndSleep()
{
	PIXBeginNamedEvent(-1, "frontend sleep");
	Sys_WaitForSingleObject(&rendererRunningEvent);
	if (!g_currentThreadId)
	{
		g_currentThreadId = GetCurrentThreadId();
	}
	if (g_currentThreadId == threadId[THREAD_CONTEXT_BACKEND])
	{
		D3DPERF_EndEvent();
	}
}

/*
==============
Sys_WakeRenderer
==============
*/
void Sys_WakeRenderer(void *data)
{
	Sys_ResetEvent(&renderCompletedEvent);
	smpData = data;
	PIXSetMarker(-1, "set smpData");
	Sys_SetEvent(&backendEvent[BACKEND_EVENT_GENERIC]);
	Sys_SetEvent(&backendEvent[BACKEND_EVENT_WORKER_CMD]);
}

/*
==============
Sys_SleepServer
==============
*/
void Sys_SleepServer()
{
	int wakeServerResponse;

	PIXBeginNamedEvent(-1, "sleep server");
	wakeServerResponse = Sys_WaitForSingleObjectTimeout(&wakeServerEvent, 0);
	if (!g_currentThreadId)
	{
		g_currentThreadId = GetCurrentThreadId();
	}
	if (g_currentThreadId == threadId[THREAD_CONTEXT_BACKEND])
	{
		D3DPERF_EndEvent();
	}
	if (wakeServerResponse)
	{
		Sys_ResetEvent(&wakeServerEvent);
	}
}

/*
==============
Sys_SyncDatabase
==============
*/
void Sys_SyncDatabase()
{
	PIXBeginNamedEvent(-1, "Sys_SyncDatabase()");
	if (Sys_WaitForSingleObjectTimeout(&databaseCompletedEvent, 0))
	{
		while (Sys_WaitForSingleObjectTimeout(&databaseCompletedEvent, 1000))
		{
			R_Cinematic_ForceRelinquishIO();
			Sys_CheckQuitRequest();
		}
		if (!g_currentThreadId)
		{
			g_currentThreadId = GetCurrentThreadId();
		}
		if (g_currentThreadId == threadId[THREAD_CONTEXT_BACKEND])
		{
			D3DPERF_EndEvent();
		}
	}
	else
	{
		if (!g_currentThreadId)
		{
			g_currentThreadId = GetCurrentThreadId();
		}
		if (g_currentThreadId == threadId[THREAD_CONTEXT_BACKEND])
		{
			D3DPERF_EndEvent();
		}
	}
}

/*
==============
Sys_GetCurrentThreadName
==============
*/
const char *Sys_GetCurrentThreadName()
{
	return s_threadNames[Sys_GetThreadContext()];
}

/*
==============
Sys_WaitBackendEvent
==============
*/
int Sys_WaitBackendEvent(int msec)
{
	return Sys_WaitForSingleObjectTimeout(&backendEvent[BACKEND_EVENT_GENERIC], msec) == 0;
}

/*
==============
Sys_WaitAllowServerNetworkLoop
==============
*/
void Sys_WaitAllowServerNetworkLoop()
{
	PIXBeginNamedEvent(-1, "Sys_WaitAllowServerNetworkLoop");
	if (!g_currentThreadId)
	{
		g_currentThreadId = GetCurrentThreadId();
	}
	Sys_WaitForSingleObject(&allowServerNetworkEvent);
	if (!g_currentThreadId)
	{
		g_currentThreadId = GetCurrentThreadId();
	}
	if (g_currentThreadId == threadId[THREAD_CONTEXT_BACKEND])
	{
		D3DPERF_EndEvent();
	}
}

/*
==============
Sys_GumpPrint
==============
*/
void Sys_GumpPrint(const char *fmt, ...)
{
	char msg[512];
	va_list ap;

	va_start(ap, fmt);
	if (Dvar_GetBool(gump_verbose))
	{
		_vsnprintf(msg, 0x200u, fmt, ap);
		msg[511] = 0;
		Com_Printf(CON_CHANNEL_FILES, "GUMP(%s): %s\n", s_threadNames[Sys_GetThreadContext()], msg);
	}
}

/*
==============
Sys_GumpLoaded
==============
*/
void Sys_GumpLoaded()
{
	Sys_GumpPrint("Sys_GumpLoaded set gumpLoadedEvent\n");
	g_gump_load_in_progress = 0;
	g_supress_db_prints = 0;
	SetEvent(gumpLoadedEvent);
}

/*
==============
Sys_GumpFlushed
==============
*/
void Sys_GumpFlushed()
{
	Sys_GumpPrint("Sys_GumpFlushed set gumpFlushedEvent\n");
	SetEvent(gumpFlushedEvent);
}

