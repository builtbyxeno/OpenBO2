#include "threads.h"

#include <windows.h>

#define MS_VC_EXCEPTION 0x406D1388

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
	HANDLE v0; // eax
	unsigned int v1; // edx
	unsigned int v2; // eax
	unsigned int v3; // ecx
	unsigned int v4; // ecx
	unsigned int systemAffinityMask; // [esp+0h] [ebp-8Ch] BYREF
	unsigned int processAffinityMask; // [esp+4h] [ebp-88h] BYREF
	unsigned int affinityMaskBits[32]; // [esp+8h] [ebp-84h]

	v0 = GetCurrentProcess();
	GetProcessAffinityMask(v0, (PDWORD_PTR)&processAffinityMask, (PDWORD_PTR)&systemAffinityMask);
	v1 = processAffinityMask;
	v2 = 0;
	s_affinityMaskForProcess = processAffinityMask;
	v3 = 1;
	if (!processAffinityMask) {
		s_cpuCount = 1;
		s_affinityMaskForCpu[0] = -1;
	}
	do
	{
		if ((v3 & v1) != 0)
		{
			affinityMaskBits[v2++] = v3;
			if (v2 == 32)
				break;
		}
		v3 *= 2;
	}   while ((-v3 & v1) != 0);
	if (v2 && v2 != 1)
	{
		v4 = *(&processAffinityMask + v2);
		s_cpuCount = v2;
		s_affinityMaskForCpu[0] = affinityMaskBits[0];
		s_affinityMaskForCpu[1] = v4;
		if (v2 != 2)
		{
			if (v2 == 3)
			{
				s_affinityMaskForCpu[2] = affinityMaskBits[1];
			}
			else if (v2 == 4)
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
				if (v2 >= 8)
					s_cpuCount = 8;
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
}

void Sys_InitThread(int)
{
}

unsigned long Sys_ThreadMain(void*)
{
	return 0;
}

void Sys_CreateThread(void(*)(unsigned int), unsigned int)
{
}

void Sys_TitleServerThreadData(void)
{
}

void Sys_InitDemoStreamingEvent(void)
{
}

void Sys_WaitForDemoStreamingEvent(void)
{
}

int Sys_WaitForDemoStreamingEventTimeout(unsigned int)
{
	return 0;
}

void Sys_SetDemoStreamingEvent(void)
{
}

void Sys_InitWebMStreamingEvent(void)
{
}

void Sys_InitServerEvents(void)
{
}

void Sys_NotifyRenderer(void)
{
}

int Sys_WaitServer(int)
{
	return 0;
}

int Sys_IsDBPrintingSuppressed(void)
{
	return 0;
}

void Sys_StartGumpLoading(void)
{
}

int Sys_IsLoadingGump(void)
{
	return 0;
}

int Sys_WaitForGumpLoad(int)
{
	return 0;
}

int Sys_WaitForGumpFlush(int)
{
	return 0;
}

void Sys_WakeServer(void)
{
}

void Sys_ServerCompleted(void)
{
}

int Sys_WaitStartServer(int)
{
	return 0;
}

bool Sys_IsServerThread(void)
{
	return false;
}

void Sys_DatabaseCompleted(void)
{
}

void Sys_WaitStartDatabase(void)
{
}

int Sys_IsDatabaseReady(void)
{
	return 0;
}

void Sys_WakeDatabase(void)
{
}

void Sys_NotifyDatabase(void)
{
}

void Sys_DatabaseCompleted2(void)
{
}

int Sys_IsDatabaseReady2(void)
{
	return 0;
}

void Sys_WakeDatabase2(void)
{
}

bool Sys_IsRenderThread(void)
{
	return false;
}

bool _Sys_IsDatabaseThread()
{
	return false;
}

bool Sys_IsMainThread(void)
{
	return false;
}

int Sys_GetThreadContext(void)
{
	return 0;
}

void Sys_SetValue(int, void*)
{
}

void* Sys_GetValue(int)
{
	return nullptr;
}

void Sys_SetWin32QuitEvent(void)
{
}

int Sys_QueryWin32QuitEvent(void)
{
	return 0;
}

void Sys_SetRGRegisteredEvent(void)
{
}

int Sys_QueryRGRegisteredEvent(void)
{
	return 0;
}

void Sys_SetRenderEvent(void)
{
}

void Sys_SetD3DShutdownEvent(void)
{
}

int Sys_QueryD3DShutdownEvent(void)
{
	return 0;
}

bool Sys_SpawnStreamThread(void(*)(unsigned int))
{
	return false;
}

void Sys_StreamSleep(void)
{
}

void Sys_ResetSndInitializedEvent(void)
{
}

int Sys_QueryStreamPaused(void)
{
	return 0;
}

void Sys_WakeStream(void)
{
}

bool Sys_IsStreamThread(void)
{
	return false;
}

void Sys_SetServerAllowNetworkEvent(void)
{
}

void Sys_ResetServerAllowNetworkEvent(void)
{
}

void Sys_SetServerNetworkCompletedEvent(void)
{
}

void Sys_ResetServerNetworkCompletedEvent(void)
{
}

void Sys_WaitServerNetworkCompleted(void)
{
}

unsigned int Sys_GetDefaultWorkerThreadsCount(void)
{
	return 0;
}

bool Sys_SpawnServerThread(void(*)(unsigned int))
{
	return false;
}

bool Sys_SpawnDatabaseThread(void(*)(unsigned int))
{
	return false;
}

void Sys_InitWorkerThreadContext(void)
{
}

void Sys_RenderCompleted(void)
{
}

void Sys_FrontEndSleep(void)
{
}

void Sys_WakeRenderer(void*)
{
}

void Sys_SleepServer(void)
{
}

void Sys_SyncDatabase(void)
{
}

char const* Sys_GetCurrentThreadName(void)
{
	return nullptr;
}

void Sys_WaitAllowServerNetworkLoop(void)
{
}

void Sys_GumpPrint(char const*, ...)
{
}

void Sys_GumpLoaded(void)
{
}

void Sys_GumpFlushed(void)
{
}
