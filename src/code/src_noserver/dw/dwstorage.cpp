#include "types.h"
#include "functions.h"

/*
==============
dwFileShareGetProgress
==============
*/
void dwFileShareGetProgress(ControllerIndex_t localControllerIndex, unsigned int *bytes, float *dataRate, fileShareLocation location)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
dwFileShareAbortOperation
==============
*/
void dwFileShareAbortOperation(ControllerIndex_t localControllerIndex, fileShareLocation location)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
dwFileShareIsReady
==============
*/
bool dwFileShareIsReady(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwFileShareGetLastHTTPError
==============
*/
int dwFileShareGetLastHTTPError(ControllerIndex_t localControllerIndex, fileShareLocation location)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwGetFileMetadata
==============
*/
TaskRecord *dwGetFileMetadata(const ControllerIndex_t controllerIndex, dwFileMetadata *metadata)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwReadFileFailure
==============
*/
char dwReadFileFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwReadFileSuccess
==============
*/
char dwReadFileSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwReadFileInternal
==============
*/
TaskRecord *dwReadFileInternal(ControllerIndex_t localControllerIndex, dwFileTask *const fileTask, bool userFile, unsigned __int64 ownerUID)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwReadFile
==============
*/
TaskRecord *dwReadFile(dwFileTask *a1, ControllerIndex_t a2, ControllerIndex_t localControllerIndex, dwFileTask *const fileTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwReadUserFile
==============
*/
TaskRecord *dwReadUserFile(dwFileTask *a1, ControllerIndex_t a2, ControllerIndex_t localControllerIndex, dwFileTask *const fileTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwReadUserFileByUserID
==============
*/
TaskRecord *__cdecl dwReadUserFileByUserID(ControllerIndex_t localControllerIndex, dwFileTask *const fileTask, unsigned __int64 xuid)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwDeleteFileFailure
==============
*/
char dwDeleteFileFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwWriteFileFailure
==============
*/
char dwWriteFileFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwWriteFile
==============
*/
TaskRecord *dwWriteFile(ControllerIndex_t localControllerIndex, const char *const filename, void *data, const unsigned int dataSize, bdFileInfo *fileInfo, unsigned __int64 ownerID)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwFileShareGetListing
==============
*/
TaskRecord *dwFileShareGetListing(ControllerIndex_t localControllerIndex, dwFileShareListTask *const fsTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwFileShareGetDescriptorsFromPooledStorage
==============
*/
TaskRecord *dwFileShareGetDescriptorsFromPooledStorage(ControllerIndex_t localControllerIndex, dwFileShareDescriptorsTask *const fsTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwFileShareGetDescriptorsFromUserStorage
==============
*/
TaskRecord *dwFileShareGetDescriptorsFromUserStorage(ControllerIndex_t localControllerIndex, dwFileShareDescriptorsTask *const fsTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwFileShareGetDescriptors
==============
*/
TaskRecord *dwFileShareGetDescriptors(dwFileShareDescriptorsTask *a1, ControllerIndex_t localControllerIndex, dwFileShareDescriptorsTask *const fsTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwFileShareReadPooledStorageFile
==============
*/
TaskRecord *dwFileShareReadPooledStorageFile(ControllerIndex_t controllerIndex, dwFileShareReadFileTask *const fsTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwFileShareReadUserStorageFile
==============
*/
TaskRecord *dwFileShareReadUserStorageFile(ControllerIndex_t controllerIndex, dwFileShareReadFileTask *const fsTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwFileShareReadPublisherStorageFile
==============
*/
TaskRecord *dwFileShareReadPublisherStorageFile(ControllerIndex_t controllerIndex, dwFileShareReadFileTask *const fsTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwFileShareReadFile
==============
*/
TaskRecord *dwFileShareReadFile(dwFileShareReadFileTask *a1, ControllerIndex_t a2, ControllerIndex_t controllerIndex, dwFileShareReadFileTask *const fsTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwFileShareRemoveFile
==============
*/
TaskRecord *dwFileShareRemoveFile(ControllerIndex_t controllerIndex, dwFileShareRemoveTask *const fsTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwFileShareTransferFile
==============
*/
TaskRecord *dwFileShareTransferFile(ControllerIndex_t controllerIndex, dwFileShareTransferTask *const fsTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwFileShareGetPooledSummary
==============
*/
TaskRecord *dwFileShareGetPooledSummary(ControllerIndex_t controllerIndex, dwFileShareSummaryTask *const fsTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwFileShareGetUserSummary
==============
*/
TaskRecord *dwFileShareGetUserSummary(ControllerIndex_t controllerIndex, dwFileShareSummaryTask *const fsTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwFileShareGetSummary
==============
*/
TaskRecord *dwFileShareGetSummary(dwFileShareSummaryTask *a1, ControllerIndex_t a2, ControllerIndex_t controllerIndex, dwFileShareSummaryTask *const fsTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwFileShareSetPooledSummary
==============
*/
TaskRecord *dwFileShareSetPooledSummary(ControllerIndex_t controllerIndex, dwFileShareSummaryTask *const fsTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwFileShareSetUserSummary
==============
*/
TaskRecord *dwFileShareSetUserSummary(ControllerIndex_t controllerIndex, dwFileShareSummaryTask *const fsTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwFileShareSetSummary
==============
*/
TaskRecord *dwFileShareSetSummary(ControllerIndex_t controllerIndex, dwFileShareSummaryTask *const fsTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwFileShareWritePooledStorageFile
==============
*/
TaskRecord *dwFileShareWritePooledStorageFile(ControllerIndex_t controllerIndex, dwFileShareWriteFileTask *const fsTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwFileShareWriteUserStorageFile
==============
*/
TaskRecord *dwFileShareWriteUserStorageFile(ControllerIndex_t controllerIndex, dwFileShareWriteFileTask *const fsTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwFileShareWriteFile
==============
*/
TaskRecord *dwFileShareWriteFile(dwFileShareWriteFileTask *a1, ControllerIndex_t a2, ControllerIndex_t controllerIndex, dwFileShareWriteFileTask *const fsTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwKeyArchiveRead
==============
*/
TaskRecord *dwKeyArchiveRead(const ControllerIndex_t localControllerIndex, dwKeyArchiveReadTask *const keyArchiveTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

