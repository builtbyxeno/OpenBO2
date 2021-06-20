#include "threads.h"
#include <universal/q_shared.h>
#include <gfx_d3d/r_pix_profile.h>

#include <windows.h>

#define MS_VC_EXCEPTION 0x406D1388

enum
{
	THREAD_CONTEXT_MAIN = 0x0,
	THREAD_CONTEXT_BACKEND = 0x1,
	THREAD_CONTEXT_WORKER0 = 0x2,
	THREAD_CONTEXT_WORKER1 = 0x3,
	THREAD_CONTEXT_WORKER2 = 0x4,
	THREAD_CONTEXT_WORKER3 = 0x5,
	THREAD_CONTEXT_WORKER4 = 0x6,
	THREAD_CONTEXT_WORKER5 = 0x7,
	THREAD_CONTEXT_WORKER6 = 0x8,
	THREAD_CONTEXT_WORKER7 = 0x9,
	THREAD_CONTEXT_SERVER = 0xA,
	THREAD_CONTEXT_TITLE_SERVER = 0xB,
	THREAD_CONTEXT_DATABASE = 0xC,
	THREAD_CONTEXT_TRACE_COUNT = 0xD,
	THREAD_CONTEXT_TRACE_LAST = 0xC,
	THREAD_CONTEXT_STREAM = 0xD,
	THREAD_CONTEXT_SOUND_MIX = 0xE,
	THREAD_CONTEXT_SOUND_DECODE = 0xF,
	THREAD_CONTEXT_WEBM_DEC_DECODE = 0x10,
	THREAD_CONTEXT_COUNT = 0x11,
	THREAD_CONTEXT_INVALID = 0xFFFFFFFF,
};

__declspec(thread) void** g_dwTlsIndex;
__declspec(thread) unsigned int g_currentThreadId;
#pragma comment (linker, "/INCLUDE:__tls_used")
#pragma data_seg(".CRT$XLB")
#pragma data_seg()

unsigned int s_cpuCount;
unsigned int s_affinityMaskForProcess;
unsigned int s_affinityMaskForCpu[8];

void* webmStreamingReady;
void* backendEvent[2];
void* g_threadValues[17][5];
void* threadHandle[17];
unsigned int threadId[17];
void(*threadFunc[17])(unsigned int);

static HANDLE allowServerNetworkEvent, databaseCompletedEvent, databaseCompletedEvent2, demoStreamingReady, d3dShutdownEvent, gumpFlushedEvent, gumpLoadedEvent, renderCompletedEvent, renderEvent, rendererRunningEvent, resumedDatabaseEvent, rgRegisteredEvent, serverCompletedEvent, serverNetworkCompletedEvent, sndInitializedEvent, streamCompletedEvent, streamDatabasePausedReading, streamEvent, wakeDatabaseEvent, wakeServerEvent, win32QuitEvent;

const char* s_threadNames[17] = { "Main", "Backend", "Worker0", "Worker1", "Worker2", "Worker3", "Worker4", "Worker5", "Worker6", "Worker7", "Server", "TitleServer", "Database", "Sound Mix", "Sound Decode", "WebM Decode" };

bool g_databaseStopServer;
unsigned int g_networkOverrideThread;
bool g_supress_db_prints;
bool g_gump_load_in_progress;
void* volatile smpData;

enum BackendEventType {
	BACKEND_EVENT_WORKER_CMD = 0x0,
	BACKEND_EVENT_GENERIC = 0x1,
	BACKEND_EVENT_COUNT = 0x2,
};

#pragma pack(push,8)
typedef struct tagTHREADNAME_INFO
{
	DWORD dwType; // Must be 0x1000.
	LPCSTR szName; // Pointer to name (in user addr space).
	DWORD dwThreadID; // Thread ID (-1=caller thread).
	DWORD dwFlags; // Reserved for future use, must be zero.
} THREADNAME_INFO;
#pragma pack(pop)

void SetThreadName(unsigned int dwThreadID, char const* szThreadName)
{
	tagTHREADNAME_INFO info;

	info.dwType = 4096;
	info.szName = szThreadName;
	info.dwThreadID = dwThreadID;
	info.dwFlags = 0;
#pragma warning(push)
#pragma warning(disable: 6320 6322)
	__try {
		RaiseException(MS_VC_EXCEPTION, 0, sizeof(info) / sizeof(ULONG_PTR), (ULONG_PTR*)&info);
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
	}
#pragma warning(pop)
}

void Sys_Sleep(int)
{
}

void NET_Sleep(unsigned int timeInMs)
{
	Sleep(timeInMs);
}

void Sys_SetEvent(void** event)
{
	SetEvent(*event);
}

void Sys_ResetEvent(void** event)
{
	ResetEvent(*event);
}

void Sys_CreateEvent(int manualReset, int initialState, void** evt)
{
	HANDLE evtHandle; // eax

	evtHandle = CreateEventA(0, manualReset, initialState, 0);
	if (evtHandle)
	{
		*evt = evtHandle;
	}
	else
	{
		DWORD lastErr = GetLastError();
		//Com_Printf(1, "error %d while creating event\n", v4);
		*evt = 0;
	}
}

int Sys_WaitForSingleObjectTimeout(void** event, unsigned int msec)
{
	return WaitForSingleObject(*event, msec) == 0;
}

void Sys_WaitForSingleObject(void** event)
{
	WaitForSingleObject(*event, 0xFFFFFFFF);
}

unsigned int Sys_GetCpuCount(void)
{
	return s_cpuCount;
}

void Win_InitThreads(void)
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

void Sys_InitMainThread(void)
{
	if (!g_currentThreadId)
	{
		g_currentThreadId = GetCurrentThreadId();
	}
	threadId[0] = g_currentThreadId;
	DuplicateHandle(GetCurrentProcess(), GetCurrentThread(), GetCurrentProcess(), threadHandle, 0, 0, 2u);
	Win_InitThreads();
	*g_dwTlsIndex = g_threadValues;
	Com_InitThreadData(0);
}

void Sys_InitThread(int threadContext)
{
	*g_dwTlsIndex = g_threadValues[threadContext];
	Com_InitThreadData(threadContext);
}

unsigned long Sys_ThreadMain(void* parameter)
{
	unsigned int threadContext = (unsigned int)parameter;

	SetThreadName(0xFFFFFFFF, s_threadNames[threadContext]);
	*g_dwTlsIndex = g_threadValues[threadContext];
	Com_InitThreadData(threadContext);
	threadFunc[threadContext](threadContext);
	return 0;
}

void Sys_CreateThread(unsigned int threadContext, void(__cdecl* function)(unsigned int))
{
	HANDLE newThread;
	DWORD lastError;

	threadFunc[threadContext] = function;
	newThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Sys_ThreadMain, (LPVOID)threadContext, 4u, (LPDWORD)(4 * threadContext + 125788032));
	threadHandle[threadContext] = newThread;

	if (!threadHandle[threadContext])
	{
		lastError = GetLastError();
		//Com_Printf(1, "error %d while creating thread %d\n", lastError, threadContext);
	}
	SetThreadName(threadId[threadContext], s_threadNames[threadContext]);
}

void Sys_TitleServerThreadData(void)
{
	if (!g_currentThreadId)
		g_currentThreadId = GetCurrentThreadId();
	Com_InitThreadData(THREAD_CONTEXT_TITLE_SERVER);
}

void Sys_InitDemoStreamingEvent(void)
{
	HANDLE event = CreateEventA(0, 0, 0, 0);

	if (!event) {
		//Com_Printf(1, "error %d while creating event\n", GetLastError());
	}
	demoStreamingReady = event;
}

void Sys_WaitForDemoStreamingEvent(void)
{
	WaitForSingleObject(demoStreamingReady, -1);
}

int Sys_WaitForDemoStreamingEventTimeout(unsigned int msec)
{
	return WaitForSingleObject(demoStreamingReady, msec);
}

void Sys_SetDemoStreamingEvent(void)
{
	SetEvent(demoStreamingReady);
}

void Sys_InitWebMStreamingEvent(void)
{
	HANDLE event = CreateEventA(0, 0, 0, 0);

	if (!event) {
		//Com_Printf(1, "error %d while creating event\n", GetLastError());
	}
	webmStreamingReady = event;
}

void Sys_InitServerEvents(void)
{
	ResetEvent(wakeServerEvent);
	ResetEvent(serverCompletedEvent);
	SetEvent(allowServerNetworkEvent);
	SetEvent(serverNetworkCompletedEvent);
	g_networkOverrideThread = 0;
}

void Sys_NotifyRenderer(void)
{
	SetEvent(backendEvent[1]);
}

int Sys_WaitServer(int timeout)
{
	return WaitForSingleObject(serverCompletedEvent, timeout) == 0;
}

bool Sys_IsDBPrintingSuppressed(void)
{
	return g_supress_db_prints;
}

void Sys_StartGumpLoading(void)
{
	g_gump_load_in_progress = true;
	g_supress_db_prints = true;
}

int Sys_IsLoadingGump(void)
{
	return g_gump_load_in_progress;
}

int Sys_WaitForGumpLoad(int timeout)
{
	return WaitForSingleObject(gumpLoadedEvent, timeout) == 0;
}

int Sys_WaitForGumpFlush(int timeout)
{
	return WaitForSingleObject(gumpFlushedEvent, timeout) == 0;
}

void Sys_WakeServer(void)
{
	SetEvent(wakeServerEvent);
}

void Sys_ServerCompleted(void)
{
	SetEvent(serverCompletedEvent);
}

int Sys_WaitStartServer(int timeout)
{
	DWORD eventReturn = WaitForSingleObject(wakeServerEvent, timeout);
	bool isWaiting = eventReturn == 0;
	if (!eventReturn)
		ResetEvent(serverCompletedEvent);
	if (g_databaseStopServer)
		return 0;
	else
		return isWaiting;
}

bool Sys_IsServerThread(void)
{
	if (!g_currentThreadId)
		g_currentThreadId = GetCurrentThreadId();
	return g_currentThreadId == threadId[THREAD_CONTEXT_SERVER];
}

void Sys_DatabaseCompleted(void)
{
	g_databaseStopServer = 1;
	if (serverCompletedEvent)
	{
		DWORD eventReturn = WaitForSingleObject(serverCompletedEvent, -1);
		if (eventReturn)
		{
			//Assert
		}
	}
	SetEvent(databaseCompletedEvent);
}

void Sys_WaitStartDatabase(void)
{
	WaitForSingleObject(wakeDatabaseEvent, 0xFFFFFFFF);
}

int Sys_IsDatabaseReady(void)
{
	return WaitForSingleObject(databaseCompletedEvent, 0) == 0;
}

void Sys_WakeDatabase(void)
{
	ResetEvent(databaseCompletedEvent);
}

void Sys_NotifyDatabase(void)
{
	SetEvent(wakeDatabaseEvent);
}

void Sys_DatabaseCompleted2(void)
{
	g_databaseStopServer = 0;
	SetEvent(databaseCompletedEvent2);
}

int Sys_IsDatabaseReady2(void)
{
	return WaitForSingleObject(databaseCompletedEvent2, 0) == 0;
}

void Sys_WakeDatabase2(void)
{
	ResetEvent(databaseCompletedEvent2);
}

bool Sys_IsRenderThread(void)
{
	if (!g_currentThreadId)
		g_currentThreadId = GetCurrentThreadId();
	return g_currentThreadId == threadId[THREAD_CONTEXT_BACKEND];
}

bool _Sys_IsDatabaseThread()
{
	if (!g_currentThreadId)
		g_currentThreadId = GetCurrentThreadId();
	return g_currentThreadId == threadId[THREAD_CONTEXT_DATABASE];
}

bool Sys_IsMainThread(void)
{
	if (!g_currentThreadId)
		g_currentThreadId = GetCurrentThreadId();
	return g_currentThreadId == threadId[THREAD_CONTEXT_MAIN];
}

int Sys_GetThreadContext(void)
{
	if (!g_currentThreadId)
		g_currentThreadId = GetCurrentThreadId();
	for (int i = 0; i < 17; ++i)
	{
		if (threadId[i] == g_currentThreadId)
			return i;
	}
	//Com_Printf(1, "Current thread is not in thread table\n");
	return 17;
}

void Sys_SetValue(int valueIndex, void* data)
{
	g_dwTlsIndex[valueIndex] = data;
}

void* Sys_GetValue(int valueIndex)
{
	return g_dwTlsIndex[valueIndex];
}

void Sys_SetWin32QuitEvent(void)
{
	SetEvent(win32QuitEvent);
}

int Sys_QueryWin32QuitEvent(void)
{
	return WaitForSingleObject(win32QuitEvent, 0) == 0;
}

void Sys_SetRGRegisteredEvent(void)
{
	SetEvent(rgRegisteredEvent);
}

int Sys_QueryRGRegisteredEvent(void)
{
	return WaitForSingleObject(rgRegisteredEvent, 0) == 0;
}

void Sys_SetRenderEvent(void)
{
	SetEvent(renderEvent);
}

void Sys_SetD3DShutdownEvent(void)
{
	SetEvent(d3dShutdownEvent);
}

int Sys_QueryD3DShutdownEvent(void)
{
	return WaitForSingleObject(d3dShutdownEvent, 0) == 0;
}

bool Sys_SpawnStreamThread(void(*function)(unsigned int))
{
	HANDLE m_sndInitializedEvent, m_streamCompletedEvent, m_streamDatabaseEventPausedReading, m_streamEvent;

	m_sndInitializedEvent = CreateEventA(0, 1, 0, 0);
	if (!m_sndInitializedEvent)
	{
		//Com_Printf(1, "error %d while creating event\n", GetLastError());
	}
	sndInitializedEvent = m_sndInitializedEvent;
	m_streamCompletedEvent = CreateEventA(0, 1, 0, 0);
	if (!m_streamCompletedEvent)
	{
		//Com_Printf(1, "error %d while creating event\n", GetLastError());
	}
	streamCompletedEvent = m_streamCompletedEvent;
	m_streamDatabaseEventPausedReading = CreateEventA(0, 1, 0, 0);
	if (!m_streamDatabaseEventPausedReading)
	{
		//Com_Printf(1, "error %d while creating event\n", GetLastError());
	}
	streamDatabasePausedReading = m_streamDatabaseEventPausedReading;
	m_streamEvent = CreateEventA(0, 0, 0, 0);
	if (!m_streamEvent)
	{
		//Com_Printf(1, "error %d while creating event\n", GetLastError());
	}
	streamEvent = m_streamEvent;
	Sys_CreateThread(THREAD_CONTEXT_STREAM, function);
	if (!threadHandle[THREAD_CONTEXT_STREAM])
		return 0;
	ResumeThread(threadHandle[THREAD_CONTEXT_STREAM]);
	return 1;
}

void Sys_StreamSleep(void)
{
	SetEvent(streamCompletedEvent);
	SetEvent(streamDatabasePausedReading);
	DWORD eventReturn = WaitForSingleObject(streamEvent, 0xFFFFFFFF);
	ResetEvent(streamCompletedEvent);
	ResetEvent(streamDatabasePausedReading);
}

void Sys_ResetSndInitializedEvent(void)
{
	ResetEvent(sndInitializedEvent);
}

int Sys_QueryStreamPaused(void)
{
	return WaitForSingleObject(streamDatabasePausedReading, 1u) == 0;
}

void Sys_WakeStream(void)
{
	SetEvent(streamEvent);
}

bool Sys_IsStreamThread(void)
{
	if (!g_currentThreadId)
		g_currentThreadId = GetCurrentThreadId();
	return g_currentThreadId == threadId[THREAD_CONTEXT_STREAM];
}

void Sys_SetServerAllowNetworkEvent(void)
{
	SetEvent(allowServerNetworkEvent);
}

void Sys_ResetServerAllowNetworkEvent(void)
{
	ResetEvent(allowServerNetworkEvent);
}

void Sys_SetServerNetworkCompletedEvent(void)
{
	//Sys_EnterCriticalSection(CRITSECT_NETTHREAD_OVERRIDE);
	if (!g_currentThreadId)
		g_currentThreadId = GetCurrentThreadId();
	g_networkOverrideThread = 0;
	SetEvent(serverNetworkCompletedEvent);
	//Sys_LeaveCriticalSection(CRITSECT_NETTHREAD_OVERRIDE);
}

void Sys_ResetServerNetworkCompletedEvent(void)
{
	//Sys_EnterCriticalSection(CRITSECT_NETTHREAD_OVERRIDE);
	if (!g_currentThreadId)
		g_currentThreadId = GetCurrentThreadId();
	g_networkOverrideThread = g_currentThreadId;
	ResetEvent(serverNetworkCompletedEvent);
	//Sys_LeaveCriticalSection(CRITSECT_NETTHREAD_OVERRIDE);
}

void Sys_WaitServerNetworkCompleted(void)
{
	if (!g_currentThreadId)
		g_currentThreadId = GetCurrentThreadId();
	WaitForSingleObject(serverNetworkCompletedEvent, -1);
}

unsigned int Sys_GetDefaultWorkerThreadsCount(void)
{
	if (s_cpuCount <= 2)
		return 1;
	if (s_cpuCount <= 4)
		return 2;
	if (s_cpuCount > 10)
		return 8;
	return s_cpuCount - 2;
}

bool Sys_SpawnServerThread(void(*function)(unsigned int))
{
	Sys_CreateEvent(1, 0, &wakeServerEvent);
	Sys_CreateEvent(1, 0, &serverCompletedEvent);
	Sys_CreateEvent(1, 1, &allowServerNetworkEvent);
	Sys_CreateEvent(1, 1, &serverNetworkCompletedEvent);
	Sys_CreateThread(THREAD_CONTEXT_SERVER, function);
	if (!threadHandle[THREAD_CONTEXT_SERVER])
		return 0;
	ResumeThread(threadHandle[THREAD_CONTEXT_SERVER]);
	return 1;
}

bool Sys_SpawnDatabaseThread(void(*function)(unsigned int))
{
	Sys_CreateEvent(0, 0, &wakeDatabaseEvent);
	Sys_CreateEvent(1, 1, &databaseCompletedEvent);
	Sys_CreateEvent(1, 1, &databaseCompletedEvent2);
	Sys_CreateEvent(1, 1, &resumedDatabaseEvent);
	Sys_CreateEvent(0, 0, &gumpLoadedEvent);
	Sys_CreateEvent(0, 0, &gumpFlushedEvent);
	Sys_CreateThread(THREAD_CONTEXT_DATABASE, function);
	if (!threadHandle[THREAD_CONTEXT_DATABASE])
		return false;
	ResumeThread(threadHandle[THREAD_CONTEXT_DATABASE]);
	return true;
}

void Sys_InitWorkerThreadContext(void)
{

}

void Sys_RenderCompleted(void)
{
	SetEvent(renderCompletedEvent);
	SetEvent(backendEvent[0]);
}

void Sys_FrontEndSleep(void)
{
	PIXBeginNamedEvent(-1, "frontend sleep");
	WaitForSingleObject(rendererRunningEvent, -1);
	if (!g_currentThreadId)
		g_currentThreadId = GetCurrentThreadId();
	if (threadId[1])
		D3DPERF_EndEvent();
}

void Sys_WakeRenderer(void* data)
{
	ResetEvent(renderCompletedEvent);
	smpData = data;
	PIXSetMarker(-1, "set smpData");
	SetEvent(backendEvent[1]);
	SetEvent(backendEvent[0]);
}

void Sys_SleepServer(void)
{
	PIXBeginNamedEvent(-1, "sleep server");
	int result = Sys_WaitForSingleObjectTimeout(&wakeServerEvent, 0);
	if (!g_currentThreadId)
		g_currentThreadId = GetCurrentThreadId();
	if (g_currentThreadId == threadId[1])
		D3DPERF_EndEvent();
	if (result + 1)
		ResetEvent(wakeServerEvent);
}

void Sys_SyncDatabase(void)
{
	PIXBeginNamedEvent(-1, "Sys_SyncDatabase()");
	if (WaitForSingleObject(databaseCompletedEvent, 0)) {
		while (WaitForSingleObject(databaseCompletedEvent, 1000u))
		{
			//R_Cinematic_ForceRelinquishIO();
			//Sys_CheckQuitRequest();
		}
		if (!g_currentThreadId)
			g_currentThreadId = GetCurrentThreadId();
		if (g_currentThreadId == threadId[1]) {
			D3DPERF_EndEvent();
			return;
		}
	}
	else
	{
		if (!g_currentThreadId)
			g_currentThreadId = GetCurrentThreadId();
		if (g_currentThreadId == threadId[1]) {
			D3DPERF_EndEvent();
			return;
		}
	}
}

char const* Sys_GetCurrentThreadName(void)
{
	return s_threadNames[Sys_GetThreadContext()];
}

void Sys_WaitAllowServerNetworkLoop(void)
{
	PIXBeginNamedEvent(-1, "Sys_WaitAllowServerNetworkLoop");
	if (!g_currentThreadId)
		g_currentThreadId = GetCurrentThreadId();
	Sys_WaitForSingleObject(&allowServerNetworkEvent);
	if (!g_currentThreadId)
		g_currentThreadId = GetCurrentThreadId();
	if (g_currentThreadId == threadId[1])
		D3DPERF_EndEvent();
}

void Sys_GumpPrint(char const* fmt, ...)
{
	char msg[512];
	va_list ap;

	va_start(ap, fmt);
	//if (Dvar_GetBool(gump_verbose))
	//{
	//	_vsnprintf(msg, 0x200u, fmt, ap);
	//	msg[511] = 0;
	//	//Com_Printf(15, "GUMP(%s): %s\n", s_threadNames[Sys_GetThreadContext()], msg);
	//}
}

void Sys_GumpLoaded(void)
{
	Sys_GumpPrint("Sys_GumpLoaded set gumpLoadedEvent\n");
	g_gump_load_in_progress = 0;
	g_supress_db_prints = 0;
	SetEvent(gumpLoadedEvent);
}

void Sys_GumpFlushed(void)
{
	Sys_GumpPrint("Sys_GumpFlushed set gumpFlushedEvent\n");
	SetEvent(gumpFlushedEvent);
}
