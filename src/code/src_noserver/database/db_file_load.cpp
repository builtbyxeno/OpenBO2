#include "types.h"

/*
==============
DB_Init_Reading
==============
*/
void DB_Init_Reading()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_GetLoadedFraction
==============
*/
double DB_GetLoadedFraction()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_Reliable_FsOpen_ReadOnly
==============
*/
int DB_Reliable_FsOpen_ReadOnly(const char *path, unsigned int *outClumpSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_FileReadCompletionCallback
==============
*/
void DB_FileReadCompletionCallback(int id, stream_status result, unsigned int numBytesRead, void *user)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_SetZoneSizeLevelCount
==============
*/
void DB_SetZoneSizeLevelCount(int levelZoneCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_ResetZoneSize
==============
*/
void DB_ResetZoneSize(int trackLoadProgress)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_IsMinimumFastFileLoaded
==============
*/
bool DB_IsMinimumFastFileLoaded()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_ResetMinimumFastFileLoaded
==============
*/
void DB_ResetMinimumFastFileLoaded()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_ReadData
==============
*/
int DB_ReadData()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RecomputeLocks
==============
*/
void RecomputeLocks()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_WaitXFileStage
==============
*/
void DB_WaitXFileStage(int buffer_index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_CancelLoadXFile
==============
*/
void DB_CancelLoadXFile()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_DecompressIOStream
==============
*/
void DB_DecompressIOStream(DBDecompressCmd_t *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_WaitWorkerCmd
==============
*/
void DB_WaitWorkerCmd(DB_LOAD_STREAM *stream)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TestBoundryCondition
==============
*/
char TestBoundryCondition(unsigned __int8 *pos, int len)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AdvanceRead
==============
*/
void AdvanceRead(bool advance)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CopyFromDecompressBufferNullTerminal
==============
*/
void CopyFromDecompressBufferNullTerminal(unsigned __int8 *pos, int *size_copied)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_LoadXFileData
==============
*/
void DB_LoadXFileData(unsigned __int8 *pos, int size)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_LoadXFileDataNullTerminated
==============
*/
int DB_LoadXFileDataNullTerminated(unsigned __int8 *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ValidateFileHeader
==============
*/
char *ValidateFileHeader(bool *fileIsSecure, int *fileVersion)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DB_LoadedExternalData
==============
*/
void DB_LoadedExternalData(int size)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_DecompressIOStreamWorkerCallback
==============
*/
int DB_DecompressIOStreamWorkerCallback(jqBatch *batch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_LoadXFile
==============
*/
BOOL DB_LoadXFile(const char *path, int f, const char *filename, XBlock *blocks, void (*interrupt)(), unsigned __int8 *buf, int allocType, int flags, int requiredVersion, unsigned int desiredReadBytes)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

