#include "types.h"
#include "vars.h"
#include "qcommon_public.h"
#include <qcommon/qcommon_public.h>

unsigned long threadId[THREAD_CONTEXT_COUNT];
void* threadHandle[THREAD_CONTEXT_COUNT];
void* g_threadValues[THREAD_CONTEXT_COUNT][5];
__declspec(thread) void* g_dwTlsIndex[THREAD_CONTEXT_COUNT];

unsigned int s_affinityMaskForCpu[8];
unsigned int s_affinityMaskForProcess;
unsigned int s_cpuCount;

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
HANDLE backendEvent[BACKEND_EVENT_COUNT];

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
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_WaitForDemoStreamingEvent
==============
*/
void Sys_WaitForDemoStreamingEvent()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_WaitForDemoStreamingEventTimeout
==============
*/
BOOL Sys_WaitForDemoStreamingEventTimeout(unsigned int msec)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_SetDemoStreamingEvent
==============
*/
void Sys_SetDemoStreamingEvent()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_InitWebMStreamingEvent
==============
*/
void Sys_InitWebMStreamingEvent()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_InitServerEvents
==============
*/
void Sys_InitServerEvents()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_NotifyRenderer
==============
*/
void Sys_NotifyRenderer()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_WaitServer
==============
*/
BOOL Sys_WaitServer(int timeout)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_IsDBPrintingSuppressed
==============
*/
int Sys_IsDBPrintingSuppressed()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_StartGumpLoading
==============
*/
void Sys_StartGumpLoading()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_IsLoadingGump
==============
*/
int Sys_IsLoadingGump()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_WaitForGumpLoad
==============
*/
BOOL Sys_WaitForGumpLoad(int timeout)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_WaitForGumpFlush
==============
*/
BOOL Sys_WaitForGumpFlush(int timeout)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_WakeServer
==============
*/
void Sys_WakeServer()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_ServerCompleted
==============
*/
void Sys_ServerCompleted()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_WaitStartServer
==============
*/
BOOL Sys_WaitStartServer(int timeout)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
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
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_DatabaseCompleted
==============
*/
void Sys_DatabaseCompleted()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_WaitStartDatabase
==============
*/
void Sys_WaitStartDatabase()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_IsDatabaseReady
==============
*/
BOOL Sys_IsDatabaseReady()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_WakeDatabase
==============
*/
void Sys_WakeDatabase()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_NotifyDatabase
==============
*/
void Sys_NotifyDatabase()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_DatabaseCompleted2
==============
*/
void Sys_DatabaseCompleted2()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_IsDatabaseReady2
==============
*/
BOOL Sys_IsDatabaseReady2()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_WakeDatabase2
==============
*/
void Sys_WakeDatabase2()
{
	UNIMPLEMENTED(__FUNCTION__);
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
	for (i = 0; i < 15; ++i)
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
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_QueryWin32QuitEvent
==============
*/
BOOL Sys_QueryWin32QuitEvent()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_SetRGRegisteredEvent
==============
*/
void Sys_SetRGRegisteredEvent()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_QueryRGRegisteredEvent
==============
*/
BOOL Sys_QueryRGRegisteredEvent()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_SetRenderEvent
==============
*/
void Sys_SetRenderEvent()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_SetD3DShutdownEvent
==============
*/
void Sys_SetD3DShutdownEvent()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_QueryD3DShutdownEvent
==============
*/
BOOL Sys_QueryD3DShutdownEvent()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_SpawnStreamThread
==============
*/
char Sys_SpawnStreamThread()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_StreamSleep
==============
*/
void Sys_StreamSleep()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_ResetSndInitializedEvent
==============
*/
void Sys_ResetSndInitializedEvent()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_QueryStreamPaused
==============
*/
BOOL Sys_QueryStreamPaused()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_WakeStream
==============
*/
void Sys_WakeStream()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_IsStreamThread
==============
*/
BOOL Sys_IsStreamThread()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_SetServerAllowNetworkEvent
==============
*/
void Sys_SetServerAllowNetworkEvent()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_ResetServerAllowNetworkEvent
==============
*/
void Sys_ResetServerAllowNetworkEvent()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_SetServerNetworkCompletedEvent
==============
*/
void Sys_SetServerNetworkCompletedEvent()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_ResetServerNetworkCompletedEvent
==============
*/
void Sys_ResetServerNetworkCompletedEvent()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_WaitServerNetworkCompleted
==============
*/
void Sys_WaitServerNetworkCompleted()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_GetDefaultWorkerThreadsCount
==============
*/
unsigned int Sys_GetDefaultWorkerThreadsCount()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_SpawnServerThread
==============
*/
char Sys_SpawnServerThread()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_SpawnDatabaseThread
==============
*/
char Sys_SpawnDatabaseThread()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_InitWorkerThreadContext
==============
*/
void Sys_InitWorkerThreadContext()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_RenderCompleted
==============
*/
void Sys_RenderCompleted()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_FrontEndSleep
==============
*/
void Sys_FrontEndSleep()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_WakeRenderer
==============
*/
void Sys_WakeRenderer(void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_SleepServer
==============
*/
void Sys_SleepServer()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_SyncDatabase
==============
*/
void Sys_SyncDatabase()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_GetCurrentThreadName
==============
*/
const char *Sys_GetCurrentThreadName()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Sys_WaitAllowServerNetworkLoop
==============
*/
void Sys_WaitAllowServerNetworkLoop()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_GumpPrint
==============
*/
void Sys_GumpPrint(const char *fmt, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_GumpLoaded
==============
*/
void Sys_GumpLoaded()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_GumpFlushed
==============
*/
void Sys_GumpFlushed()
{
	UNIMPLEMENTED(__FUNCTION__);
}

