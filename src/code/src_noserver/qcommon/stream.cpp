#include "types.h"
#include "vars.h"
#include <qcommon/qcommon_public.h>
#include <win32/win32_public.h>

int s_nextFreeFileID;
stream_fh s_fileIDs[MAX_FILE_IDS];
streamInfo s_streamInfoArray[64];
int lastClumpFileHandle;
int clumpFilesTOCIndex;
ClumpFile clumpFiles[1024];

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
	assert(id >= 0 && id < MAX_FILE_IDS);
	s_fileIDs[id].inUse = NULL;
	s_fileIDs[id].name[0] = NULL;
	s_fileIDs[id].readOffset = NULL;
	s_fileIDs[id].easyOffset = NULL;
	s_fileIDs[id].h = INVALID_HANDLE_VALUE;
	s_fileIDs[id].fileSize = -1;
}

/*
==============
Stream_GetStatus
==============
*/
stream_status Stream_GetStatus(int id)
{
	int index;

	index = id & 0x3F;
	assert((unsigned)(index) < (unsigned)(64));
	if (s_streamInfoArray[index].id == id)
	{
		return s_streamInfoArray[index].status;
	}
	return STREAM_STATUS_INVALID;
}

streamInfo* s_firstInQueue;
int s_numStreamsInQueue;
int s_currentExtensionAsInt;

/*
==============
Stream_AddToQueue
==============
*/
void Stream_AddToQueue(streamInfo *newStreamInfo)
{
	int i;
	unsigned int streamTime;
	streamInfo* p, *q, *firstInQueue, *prevInQueue;
	int numItemsInQueue;

	if (s_firstInQueue)
	{
		streamTime = Sys_Milliseconds();
		if (s_numStreamsInQueue > 0)
		{
			for (i = 0; i < s_numStreamsInQueue; ++i)
			{
				if (q->file == newStreamInfo->file && newStreamInfo->start_offset < q->start_offset && q->status != STREAM_STATUS_INPROGRESS || (prevInQueue = q->prevInQueue, newStreamInfo->file == prevInQueue->file) && (newStreamInfo->start_offset > prevInQueue->start_offset || prevInQueue->status == STREAM_STATUS_INPROGRESS))
				{
					firstInQueue = q;
				}
				if (q->startDeadline >= (signed int)(streamTime + newStreamInfo->estMsToFinish))
				{
					if (s_fileIDs[newStreamInfo->file].extAsInt != s_currentExtensionAsInt || s_fileIDs[s_firstInQueue->file].extAsInt == s_currentExtensionAsInt)
					{
						continue;
					}
					else
					{
						break;
					}
				}
				else
				{
					firstInQueue = 0;
				}
				streamTime += q->estMsToFinish;
				q = q->nextInQueue;

			}
			firstInQueue = q;
			if (firstInQueue == s_firstInQueue)
			{
				s_firstInQueue = newStreamInfo;
			}
			else if (!firstInQueue)
			{
				firstInQueue = s_firstInQueue;
			}
			newStreamInfo->nextInQueue = firstInQueue;
			newStreamInfo->prevInQueue = firstInQueue->prevInQueue;
			firstInQueue->prevInQueue = newStreamInfo;
			newStreamInfo->prevInQueue->nextInQueue = newStreamInfo;
			assert(newStreamInfo->nextInQueue->prevInQueue == newStreamInfo);
			assert(newStreamInfo->prevInQueue->nextInQueue == newStreamInfo);
			assert(newStreamInfo->nextInQueue->nextInQueue->prevInQueue == newStreamInfo->nextInQueue);
		}
	}
	else
	{
		assert((s_numStreamsInQueue == 0));
		newStreamInfo->prevInQueue = newStreamInfo;
		newStreamInfo->nextInQueue = newStreamInfo;
		s_firstInQueue = newStreamInfo;
		Sys_WakeStream();
	}
	++s_numStreamsInQueue;
	assert(s_firstInQueue);

	for (p = s_firstInQueue, numItemsInQueue = 0; p != s_firstInQueue; ++numItemsInQueue)
	{
		assert(p->nextInQueue->prevInQueue == p);
		assert(p->prevInQueue->nextInQueue == p);
		p = p->nextInQueue;
	}
	assertMsg((numItemsInQueue == s_numStreamsInQueue), "(numItemsInQueue) = %i", numItemsInQueue);
}

/*
==============
Stream_RemoveFromQueue
==============
*/
void Stream_RemoveFromQueue(streamInfo *stream, stream_status reason, callbackInfo *callbacks, int *numCallbacks)
{
	streamInfo* prevInQueue;
	streamInfo* nextInQueue;
	callbackInfo* callback;
	unsigned int buffer_size;

	Sys_EnterCriticalSection(CRITSECT_IO_SCHEDULER);

	assert(stream->id != (-1));
	assert(stream->status != STREAM_STATUS_INVALID);

	switch (reason)
	{
	case STREAM_STATUS_FINISHED:
		Com_Printf(CON_CHANNEL_SCHEDULER, "SCHEDULER\t%d\tfinish\t%s\t%d\t%d\n", stream->id, &s_fileIDs[stream->file], stream->start_offset, stream->bytes_read);
		break;
	case STREAM_STATUS_EOF:
		Com_Printf(CON_CHANNEL_SCHEDULER, "SCHEDULER\t%d\tEOF\t%s\t%d\n", stream->id, s_fileIDs[stream->file].name, stream->start_offset);
		break;
	case STREAM_STATUS_CANCELLED:
		if (stream->status != STREAM_STATUS_INPROGRESS)
		{
			Com_Printf(CON_CHANNEL_SCHEDULER, "SCHEDULER\t%d\t%scancel\t%s\t%d\n", stream->id, "immediately", &s_fileIDs[stream->file], stream->start_offset);
		}
		else
		{
			Com_Printf(CON_CHANNEL_SCHEDULER, "SCHEDULER\t%d\t%scancel\t%s\t%d\n", stream->id, "request", &s_fileIDs[stream->file], stream->start_offset);
		}
		break;
	}

	if (stream->status == STREAM_STATUS_INPROGRESS && reason == STREAM_STATUS_CANCELLED)
	{
		stream->status = STREAM_STATUS_CANCELLED;
		Sys_LeaveCriticalSection(CRITSECT_IO_SCHEDULER);
	}
	else
	{
		if (s_firstInQueue == stream)
		{
			s_firstInQueue = stream != stream->nextInQueue ? stream->nextInQueue : 0;
		}
		stream->nextInQueue->prevInQueue = stream->prevInQueue;
		prevInQueue = stream->prevInQueue;
		nextInQueue = stream->nextInQueue;
		--s_numStreamsInQueue;
		prevInQueue->nextInQueue = nextInQueue;
		stream->nextInQueue = 0;
		stream->prevInQueue = 0;
		assertMsg(s_numStreamsInQueue >= 0, "(s_numStreamsInQueue) = %i", s_numStreamsInQueue);

		if (stream->genericCallback)
		{
			assert(*numCallbacks < 64);
			callback = &callbacks[(*numCallbacks)++];
			callback->callback = stream->callback;
			callback->user = stream->callbackUser;
			callback->reason = reason;
			callback->id = stream->id;

			buffer_size = stream->buffer_size;
			if (buffer_size >= stream->bytes_read)
			{
				buffer_size = stream->bytes_read;
			}
			callback->bytes = buffer_size;
		}
		stream->status = STREAM_STATUS_INVALID;
		stream->id = -1;
		Sys_LeaveCriticalSection(CRITSECT_IO_SCHEDULER);
	}
}

/*
==============
Stream_IsCancelledReadInProgress
==============
*/
char Stream_IsCancelledReadInProgress()
{
	Sys_EnterCriticalSection(CRITSECT_IO_SCHEDULER);
	if (s_firstInQueue && s_firstInQueue->status == STREAM_STATUS_CANCELLED)
	{
		Sys_LeaveCriticalSection(CRITSECT_IO_SCHEDULER);
		return 1;
	}
	else
	{
		Sys_LeaveCriticalSection(CRITSECT_IO_SCHEDULER);
		return 0;
	}
}

/*
==============
Stream_CloseFile
==============
*/
void Stream_CloseFile(int handle)
{
	assert(handle >= 0 && handle < MAX_FILE_IDS);
	Sys_EnterCriticalSection(CRITSECT_FILE_ID_ARRAY);
	if (s_fileIDs[handle].shouldOpen)
	{
		Stream_DoneWithFileID(handle);
	}
	else
	{
		s_fileIDs[handle].shouldClose = 1;
		Sys_WakeStream();
	}
	Sys_LeaveCriticalSection(CRITSECT_FILE_ID_ARRAY);
}

bool g_streamReadThreadSpawned;
unsigned int s_streamRequestIds[64];
char lastClumpFile[256];

/*
==============
Stream_AddRequest
==============
*/
bool Stream_AddRequest(int handle, unsigned int offs, unsigned int bufferSize, void *buf, int msUntilRequired, stream_priority priority, void (*callback)(int, stream_status, unsigned int, void *), void *user, int *outId)
{
	unsigned int startMS;
	int index;
	streamInfo* newStreamInfo;

	if (handle < 0)
	{
		assert(((handle) >= 0));
		return 0;
	}

	if (handle >= 64 || s_fileIDs[handle].error || !g_streamReadThreadSpawned)
	{
		return 0;
	}
	assertMsg((msUntilRequired >= 0), "(msUntilRequired) = %i", msUntilRequired);
	assertMsg((((bufferSize > 0) && (bufferSize < 512 * 1024 * 1024))), "(bufferSize) = %i", bufferSize);
	assert(buf);
	
	startMS = Sys_Milliseconds();
	Sys_EnterCriticalSection(CRITSECT_IO_SCHEDULER);

	if (s_streamInfoArray[0].id == -1)
	{
		newStreamInfo = &s_streamInfoArray[0];
		newStreamInfo->id = s_streamRequestIds[0];
		if (outId)
		{
			*outId = s_streamInfoArray[0].id;
		}
		newStreamInfo->id &= 0x3F;
		assertMsg((((newStreamInfo->id) & (64 - 1))) == (index), "( (newStreamInfo->id) & STREAM_INDEX_MASK ) == index\n\t%i, %i", newStreamInfo->id, index);
		newStreamInfo->start_offset = offs;
		newStreamInfo->destination = (unsigned char*)buf;
		newStreamInfo->estMsToFinish = bufferSize / 0x20C4 + 240;
		newStreamInfo->buffer_size = bufferSize;
		newStreamInfo->genericCallback = (void(__cdecl*)(int, void*, int))callback;
		newStreamInfo->bytes_read = 0;
		newStreamInfo->startDeadline = msUntilRequired + startMS - newStreamInfo->estMsToFinish;
		newStreamInfo->callbackUser = user;
		newStreamInfo->status = STREAM_STATUS_QUEUED;
		newStreamInfo->file = handle;
		newStreamInfo->callbackOnly = 0;
		Stream_AddToQueue(&s_streamInfoArray[0]);
		s_streamRequestIds[0] = (s_streamRequestIds[0] + 64) & 0x1FFFFFF;
		Sys_LeaveCriticalSection(CRITSECT_IO_SCHEDULER);
		return 1;
	}
	else
	{
		for (index = 0; &s_streamInfoArray[index] != (streamInfo*)lastClumpFile; ++index)
		{
			if (s_streamInfoArray[index].id == -1)
			{
				newStreamInfo = &s_streamInfoArray[0];
				newStreamInfo->id = s_streamRequestIds[0];
				if (outId)
				{
					*outId = s_streamInfoArray[0].id;
				}
				newStreamInfo->id &= 0x3F;
				assertMsg((((newStreamInfo->id) & (64 - 1))) == (index), "( (newStreamInfo->id) & STREAM_INDEX_MASK ) == index\n\t%i, %i", newStreamInfo->id, index);
				newStreamInfo->start_offset = offs;
				newStreamInfo->destination = (unsigned char*)buf;
				newStreamInfo->estMsToFinish = bufferSize / 0x20C4 + 240;
				newStreamInfo->buffer_size = bufferSize;
				newStreamInfo->genericCallback = (void(__cdecl*)(int, void*, int))callback;
				newStreamInfo->bytes_read = 0;
				newStreamInfo->startDeadline = msUntilRequired + startMS - newStreamInfo->estMsToFinish;
				newStreamInfo->callbackUser = user;
				newStreamInfo->status = STREAM_STATUS_QUEUED;
				newStreamInfo->file = handle;
				newStreamInfo->callbackOnly = 0;
				Stream_AddToQueue(&s_streamInfoArray[0]);
				s_streamRequestIds[0] = (s_streamRequestIds[0] + 64) & 0x1FFFFFF;
				Sys_LeaveCriticalSection(CRITSECT_IO_SCHEDULER);
				return 1;
			}
		}
		if (outId)
		{
			*outId = -1;
		}
		Sys_LeaveCriticalSection(CRITSECT_IO_SCHEDULER);
		return 0;
	}
}

/*
==============
Stream_AddCallbackOnlyRequest
==============
*/
char Stream_AddCallbackOnlyRequest(int estMsNeeded, int msUntilRequired, stream_priority priority, void (*callback)(int, void *, int), void *user, int *outId)
{
	unsigned int startMS;
	streamInfo* newStreamInfo;
	int index = 0;

	if (!g_streamReadThreadSpawned)
	{
		return 0;
	}

	startMS = Sys_Milliseconds();
	assertMsg((msUntilRequired >= 0), "(msUntilRequired) = %i", msUntilRequired);
	assertMsg((msUntilRequired) >= (estMsNeeded), "msUntilRequired >= estMsNeeded\n\t%i, %i", msUntilRequired, estMsNeeded);

	Sys_EnterCriticalSection(CRITSECT_IO_SCHEDULER);

	if (s_streamInfoArray[0].id == -1)
	{
		newStreamInfo = &s_streamInfoArray[0];
		newStreamInfo->id = s_streamRequestIds[0];
		if (outId)
		{
			*outId = s_streamInfoArray[0].id;
		}
		newStreamInfo->id &= 0x3F;
		assertMsg((((newStreamInfo->id) & (64 - 1))) == (index), "( (newStreamInfo->id) & STREAM_INDEX_MASK ) == index\n\t%i, %i", newStreamInfo->id, index);
		newStreamInfo->start_offset = 0;
		newStreamInfo->destination = 0;
		newStreamInfo->estMsToFinish = estMsNeeded;
		newStreamInfo->buffer_size = 0;
		newStreamInfo->genericCallback = callback;
		newStreamInfo->bytes_read = 0;
		newStreamInfo->startDeadline = msUntilRequired + startMS - estMsNeeded;
		newStreamInfo->callbackUser = user;
		newStreamInfo->status = STREAM_STATUS_QUEUED;
		newStreamInfo->file = -1;
		newStreamInfo->callbackOnly = 1;
		Stream_AddToQueue(&s_streamInfoArray[0]);
		s_streamRequestIds[0] = (s_streamRequestIds[0] + 64) & 0x1FFFFFF;
		Sys_LeaveCriticalSection(CRITSECT_IO_SCHEDULER);
		return 1;
	}
	else
	{
		for (index = 0; &s_streamInfoArray[index] != (streamInfo*)lastClumpFile; ++index)
		{
			if (s_streamInfoArray[index].id == -1)
			{
				newStreamInfo = &s_streamInfoArray[0];
				newStreamInfo->id = s_streamRequestIds[0];
				if (outId)
				{
					*outId = s_streamInfoArray[0].id;
				}
				newStreamInfo->id &= 0x3F;
				assertMsg((((newStreamInfo->id) & (64 - 1))) == (index), "( (newStreamInfo->id) & STREAM_INDEX_MASK ) == index\n\t%i, %i", newStreamInfo->id, index);
				newStreamInfo->start_offset = 0;
				newStreamInfo->destination = 0;
				newStreamInfo->estMsToFinish = estMsNeeded;
				newStreamInfo->buffer_size = 0;
				newStreamInfo->genericCallback = callback;
				newStreamInfo->bytes_read = 0;
				newStreamInfo->startDeadline = msUntilRequired + startMS - estMsNeeded;
				newStreamInfo->callbackUser = user;
				newStreamInfo->status = STREAM_STATUS_QUEUED;
				newStreamInfo->file = -1;
				newStreamInfo->callbackOnly = 1;
				Stream_AddToQueue(&s_streamInfoArray[0]);
				s_streamRequestIds[0] = (s_streamRequestIds[0] + 64) & 0x1FFFFFF;
				Sys_LeaveCriticalSection(CRITSECT_IO_SCHEDULER);
				return 1;
			}
		}
		if (outId)
		{
			*outId = -1;
		}
		Sys_LeaveCriticalSection(CRITSECT_IO_SCHEDULER);
		return 0;
	}
}

/*
==============
Stream_FreeRequest
==============
*/
char Stream_FreeRequest(int id, bool freeEvenIfLoadInProgress)
{
	stream_status status;
	streamInfo* stream;
	streamInfo* prevInQueue;
	streamInfo* nextInQueue;
	bool isCallback;
	unsigned int buffer_size;
	int callbackId;
	void* callbackUser;
	void(__cdecl * callback)(int, void*, int);

	if (id == -1)
	{
		return 0;
	}
	Sys_EnterCriticalSection(CRITSECT_IO_SCHEDULER);
	stream = &s_streamInfoArray[id & 0x3F];
	if (s_streamInfoArray[id & 0x3F].id != id)
	{
		Sys_LeaveCriticalSection(CRITSECT_IO_SCHEDULER);
		return 0;
	}
	status = stream->status;
	if (status == STREAM_STATUS_CANCELLED)
	{
		Sys_LeaveCriticalSection(CRITSECT_IO_SCHEDULER);
		return 0;
	}
	if (!freeEvenIfLoadInProgress && status == STREAM_STATUS_INPROGRESS)
	{
		Com_Printf(CON_CHANNEL_SCHEDULER, "SCHEDULER\t%d nocancel %s (in progress)\n", stream->id, s_fileIDs[stream->file].name);
		Sys_LeaveCriticalSection(CRITSECT_IO_SCHEDULER);
		return 0;
	}

	Sys_EnterCriticalSection(CRITSECT_IO_SCHEDULER);
	assert(stream->id != (-1));
	assert(stream->status != STREAM_STATUS_INVALID);

	if (stream->status != STREAM_STATUS_INPROGRESS)
	{
		Com_Printf(CON_CHANNEL_SCHEDULER, "SCHEDULER\t%d\t%scancel\t%s\t%d\n", stream->id, "immediately", s_fileIDs[stream->file].name, stream->start_offset);
	}
	else
	{
		Com_Printf(CON_CHANNEL_SCHEDULER, "SCHEDULER\t%d\t%scancel\t%s\t%d\n", stream->id, "request", s_fileIDs[stream->file].name, stream->start_offset);
	}

	if (stream->status == STREAM_STATUS_INPROGRESS)
	{
		stream->status = STREAM_STATUS_CANCELLED;
		Sys_LeaveCriticalSection(CRITSECT_IO_SCHEDULER);
	}
	else
	{
		if (s_firstInQueue == stream)
		{
			s_firstInQueue = stream != stream->nextInQueue ? stream->nextInQueue : 0;
		}
		stream->nextInQueue->prevInQueue = stream->prevInQueue;
		prevInQueue = stream->prevInQueue;
		nextInQueue = stream->nextInQueue;
		prevInQueue->nextInQueue = nextInQueue;
		stream->nextInQueue = 0;
		stream->prevInQueue = 0;

		assert((s_numStreamsInQueue >= 0));
		if (stream->genericCallback)
		{
			callback = stream->genericCallback;
			callbackId = stream->id;
			buffer_size = stream->buffer_size;
			isCallback = 1;
			callbackUser = stream->callbackUser;
			if (buffer_size >= stream->bytes_read)
			{
				buffer_size = stream->bytes_read;
			}
		}
		stream->status = STREAM_STATUS_INVALID;
		stream->id = -1;
		Sys_LeaveCriticalSection(CRITSECT_IO_SCHEDULER);
	}
	Sys_LeaveCriticalSection(CRITSECT_IO_SCHEDULER);
	if (isCallback)
	{
		if (!stream->callbackOnly)
		{
			stream->callback(callbackId, stream->status, buffer_size, callbackUser);
		}
	}
	return 1;
}

/*
==============
Stream_LoadFileSynchronously
==============
*/
bool Stream_LoadFileSynchronously(streamInfo *stream)
{
	bool readSuccess;
	unsigned int buffer_size;
	unsigned int bytes_read;
	unsigned int start_offset;
	unsigned __int64 bytesRead;
	int file;

	buffer_size = stream->buffer_size;
	if (stream->callbackOnly)
	{
		stream->genericCallback(stream->estMsToFinish, stream->callbackUser, stream->id);
		stream->genericCallback = 0;
		return 1;
	}
	if (!buffer_size)
	{
		bytes_read = stream->bytes_read;
		stream->estMsToFinish = 0;

		assert((stream->bytes_read == 0));
		stream->bytes_read = 0;
		return 1;
	}
	assert(stream->bytes_read == 0);

	start_offset = stream->start_offset;
	file = stream->file;
	if (s_fileIDs[file].readOffset != start_offset)
	{
		Stream_SeekInternal(s_fileIDs[file].h, start_offset);
		s_fileIDs[stream->file].readOffset = start_offset;
	}
	readSuccess = Stream_ReadInternal(s_fileIDs[stream->file].h, start_offset, stream->destination, buffer_size, &bytesRead);
	if (readSuccess)
	{
		s_fileIDs[stream->file].readOffset += bytesRead;
	LABEL_11:
		bytes_read = stream->bytes_read;
		stream->estMsToFinish = 0;
		assert((stream->bytes_read == 0));
		stream->bytes_read = bytesRead;
		return 1;
	}
	return readSuccess;
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
	streamInfo* nextStream;

	Sys_EnterCriticalSection(CRITSECT_IO_SCHEDULER);
	nextStream = s_firstInQueue;
	if (s_firstInQueue)
	{
		if (s_firstInQueue->status != STREAM_STATUS_QUEUED)
		{
			assert((s_firstInQueue->status == STREAM_STATUS_QUEUED));
			nextStream = s_firstInQueue;
		}
		Com_Printf(CON_CHANNEL_SCHEDULER, "SCHEDULER\t%d\tbegin\t%s\t0x%x\n", nextStream->id, s_fileIDs[nextStream->file].name, nextStream->destination);
		nextStream = s_firstInQueue;
		s_firstInQueue->status = STREAM_STATUS_INPROGRESS;
		Sys_LeaveCriticalSection(CRITSECT_IO_SCHEDULER);
		return nextStream;
	}
	else
	{
		Sys_LeaveCriticalSection(CRITSECT_IO_SCHEDULER);
		return 0;
	}
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
	if (g_streamReadThreadSpawned)
	{
		g_streamReadThreadSpawned = 0;
		Sys_ResetSndInitializedEvent();
		while (!Sys_QueryStreamPaused())
		{
			NET_Sleep(1u);
		}
	}
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
	unsigned int numBytesRead;
	unsigned int easyOffset;
	InternalSync is;

	numBytesRead = 0;
	easyOffset = s_fileIDs[handle].easyOffset;
	is.finished = 0;
	is.result = STREAM_STATUS_INVALID;
	is.numBytesRead = 0;
	if (Stream_AddRequest(handle, easyOffset, bufferSize, buf, 0, STREAM_PRIO_NORMAL, Stream_InternalSyncCallback, &is, 0))
	{
		while (!is.finished)
			Sleep(0);
		numBytesRead = is.numBytesRead;
	}
	s_fileIDs[handle].easyOffset += numBytesRead;
	if (bytesRead)
		*bytesRead = numBytesRead;
	return numBytesRead;
}

/*
==============
Stream_Easy_Tell
==============
*/
unsigned int Stream_Easy_Tell(int handle)
{
	if ((unsigned int)handle > 0x3F)
	{
		return 0;
	}
	else
	{
		return s_fileIDs[handle].easyOffset;
	}
}

/*
==============
Stream_Easy_FileSize
==============
*/
unsigned int Stream_Easy_FileSize(int handle)
{
	if ((unsigned int)handle > 0x3F)
	{
		return 0;
	}
	else
	{
		return s_fileIDs[handle].fileSize;
	}
}

/*
==============
Stream_ClumpCloseFile
==============
*/
void Stream_ClumpCloseFile(int fhandle)
{
	Stream_CloseFile(fhandle);
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
	unsigned int* p_bytesRead;
	void* streamAlloc;
	int v7;
	unsigned int _bytesRead;

	p_bytesRead = bytesRead;
	if (!bytesRead)
		p_bytesRead = &_bytesRead;
	if (!Stream_ClumpSeekToFile(fhandle, filename, p_bytesRead))
		return 0;
	bytesRead = 0;
	streamAlloc = Hunk_UserAlloc(hunk, *p_bytesRead, 4, 0);
	Stream_Easy_Read(fhandle, streamAlloc, *p_bytesRead, (unsigned int*)&bytesRead);
	if (bytesRead != (unsigned int*)*p_bytesRead)
	{
		Hunk_UserFree(hunk, streamAlloc);
		return 0;
	}
	return streamAlloc;
}

/*
==============
SplitPath
==============
*/
unsigned int SplitPath(const char *path, PathItem *items)
{
	unsigned int pathLen;
	int i; 
	const char* ppath;
	int size;

	pathLen = strlen(path);
	if (pathLen)
	{
		i = 0;
		ppath = &path[strlen(path)];
		for (path = ppath; ppath != path; --ppath)
		{
			if (*ppath == '\\' || *ppath == '/')
			{
				size = path - ppath;
				if (size > 1)
				{
					I_strncpyz(items->name, ppath + 1, size);
					++i;
					++items;
				}
				path = ppath;
			}
		}
		size = path - ppath;
		if (size > 1)
			I_strncpyz(items[i++].name, ppath, size + 1);
		return i;
	}
	return pathLen;
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
	if (!g_streamReadThreadSpawned)
	{
		g_streamReadThreadSpawned = 1;
		return Sys_SpawnStreamThread((void(__cdecl*)(unsigned int))Stream_Thread);
	}
	return false;
}

/*
==============
Stream_ClumpOpenFile
==============
*/
int Stream_ClumpOpenFile(const char *clump)
{
	unsigned int handle;
	unsigned int bytesRead;

	handle = Stream_OpenFile(clump, 9);
	if (handle != -1)
	{
		Sys_EnterCriticalSection(CRITSECT_CLUMP);
		lastClumpFileHandle = handle;
		if (clumpFilesTOCIndex || strcmp(lastClumpFile, clump))
		{
			strcpy(lastClumpFile, clump);
			clumpFilesTOCIndex = 0;
			if (handle <= 0x3F)
			{
				s_fileIDs[handle].easyOffset = 0;
			}
			Stream_Easy_Read(handle, clumpFiles, 0x4000u, &bytesRead);
			if (bytesRead != 0x4000)
			{
				Stream_CloseFile(handle);
			}
		}
		Sys_LeaveCriticalSection(CRITSECT_CLUMP);
	}
	return handle;
}

