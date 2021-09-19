#include "types.h"
#include "functions.h"

/*
==============
NET_Sleep
==============
*/
void NET_Sleep(unsigned int timeInMs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_SetEvent
==============
*/
void Sys_SetEvent(void **event)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_ResetEvent
==============
*/
void Sys_ResetEvent(void **event)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_CreateEvent
==============
*/
void Sys_CreateEvent(int manualReset, int initialState, void **evt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_WaitForSingleObjectTimeout
==============
*/
BOOL Sys_WaitForSingleObjectTimeout(void **event, unsigned int msec)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_WaitForSingleObject
==============
*/
void Sys_WaitForSingleObject(void **event)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_GetCpuCount
==============
*/
unsigned int Sys_GetCpuCount()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Win_InitThreads
==============
*/
unsigned int Win_InitThreads()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_InitMainThread
==============
*/
void Sys_InitMainThread()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_InitThread
==============
*/
void Sys_InitThread(int threadContext)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_ThreadMain
==============
*/
unsigned int Sys_ThreadMain(void *parameter)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_CreateThread
==============
*/
void Sys_CreateThread(void (*function)(unsigned int), unsigned int threadContext)
{
	UNIMPLEMENTED(__FUNCTION__);
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
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_IsMainThread
==============
*/
BOOL Sys_IsMainThread()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_GetThreadContext
==============
*/
int Sys_GetThreadContext()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sys_SetValue
==============
*/
void Sys_SetValue(int valueIndex, void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_GetValue
==============
*/
void *Sys_GetValue(int valueIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
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

