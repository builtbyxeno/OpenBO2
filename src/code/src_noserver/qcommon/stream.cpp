#include "types.h"
#include "functions.h"

/*
==============
Stream_GetNextFileID
==============
*/
int Stream_GetNextFileID()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Stream_DoneWithFileID
==============
*/
void Stream_DoneWithFileID(int id)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Stream_GetStatus
==============
*/
stream_status Stream_GetStatus(int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	stream_status tmp;
	return tmp;
}

/*
==============
Stream_AddToQueue
==============
*/
void Stream_AddToQueue(streamInfo *newStreamInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Stream_RemoveFromQueue
==============
*/
void Stream_RemoveFromQueue(streamInfo *stream, stream_status reason, callbackInfo *callbacks, int *numCallbacks)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Stream_IsCancelledReadInProgress
==============
*/
char Stream_IsCancelledReadInProgress()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Stream_CloseFile
==============
*/
void Stream_CloseFile(int handle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Stream_AddRequest
==============
*/
bool Stream_AddRequest(int handle, unsigned int offs, unsigned int bufferSize, void *buf, int msUntilRequired, stream_priority priority, void (*callback)(int, stream_status, unsigned int, void *), void *user, int *outId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Stream_AddCallbackOnlyRequest
==============
*/
char Stream_AddCallbackOnlyRequest(int estMsNeeded, int msUntilRequired, stream_priority priority, void (*callback)(int, void *, int), void *user, int *outId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Stream_FreeRequest
==============
*/
char Stream_FreeRequest(int id, bool freeEvenIfLoadInProgress)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Stream_LoadFileSynchronously
==============
*/
bool Stream_LoadFileSynchronously(streamInfo *stream)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Stream_ProcessOpenRequests
==============
*/
void Stream_ProcessOpenRequests(callbackInfo *callbacks, int *numCallbacks)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Stream_GetNextStreamToLoad
==============
*/
streamInfo *Stream_GetNextStreamToLoad()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Stream_Thread
==============
*/
void Stream_Thread(char *id, unsigned int threadContext)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Stream_Shutdown
==============
*/
void Stream_Shutdown()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Stream_InternalSyncCallback
==============
*/
void Stream_InternalSyncCallback(int id, stream_status result, unsigned int numBytesRead, void *user)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Stream_Easy_Read
==============
*/
unsigned int Stream_Easy_Read(int handle, void *buf, unsigned int bufferSize, unsigned int *bytesRead)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Stream_Easy_Tell
==============
*/
unsigned int Stream_Easy_Tell(int handle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Stream_Easy_FileSize
==============
*/
unsigned int Stream_Easy_FileSize(int handle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Stream_ClumpCloseFile
==============
*/
void Stream_ClumpCloseFile(int fhandle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Stream_ClumpSeekToFile
==============
*/
char Stream_ClumpSeekToFile(int fhandle, const char *filename, unsigned int *fileSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Stream_ClumpReadFile
==============
*/
void *Stream_ClumpReadFile(int fhandle, const char *filename, HunkUser *hunk, unsigned int *bytesRead)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SplitPath
==============
*/
unsigned int SplitPath(const char *path, PathItem *items)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PathItem_Path_r
==============
*/
int PathItem_Path_r(PathItem *item, char **output, int outputLen)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Stream_FindOverridePath
==============
*/
int Stream_FindOverridePath(const char *original, char *result, int resultLength)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Stream_OpenFile
==============
*/
int Stream_OpenFile(const char *name, int flags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Stream_Init
==============
*/
bool Stream_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Stream_ClumpOpenFile
==============
*/
int Stream_ClumpOpenFile(const char *clump)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

