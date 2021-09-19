#include "types.h"
#include "functions.h"

/*
==============
LiveStorage_CorrectStatsError
==============
*/
void LiveStorage_CorrectStatsError(const char *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_VerifyCorrectStats
==============
*/
void LiveStorage_VerifyCorrectStats(persistentStats *stats, statsLocation location)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_GetPersStatsBuffer
==============
*/
persistentStats *LiveStorage_GetPersStatsBuffer(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_GetStatsBufferForDownload
==============
*/
/*persistentStats *LiveStorage_GetStatsBufferForDownload@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
LiveStorage_GetStatsBufferSize
==============
*/
int LiveStorage_GetStatsBufferSize()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_GetClassSetsBuffer
==============
*/
classSets_t *LiveStorage_GetClassSetsBuffer(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_GetStatsChecksumValid
==============
*/
/*bool LiveStorage_GetStatsChecksumValid@<al>(statsLocation a1@<edx>, const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
LiveStorage_SetStatsChecksumValid
==============
*/
void LiveStorage_SetStatsChecksumValid(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_AreStatsDDLValidated
==============
*/
/*bool LiveStorage_AreStatsDDLValidated@<al>(statsLocation a1@<edx>, const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
LiveStorage_SetStatsDDLValidated
==============
*/
void LiveStorage_SetStatsDDLValidated(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_StatsBackupFetchCompleted
==============
*/
void LiveStorage_StatsBackupFetchCompleted(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_DoWeHaveStats
==============
*/
/*bool LiveStorage_DoWeHaveStats@<al>(statsLocation a1@<edx>, const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
LiveStorage_DoWeHaveCurrentStats
==============
*/
bool LiveStorage_DoWeHaveCurrentStats(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_DoWeHaveAllStats
==============
*/
bool LiveStorage_DoWeHaveAllStats(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_SetStatsFetched
==============
*/
void LiveStorage_SetStatsFetched(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_DisableStatsUpload
==============
*/
void LiveStorage_DisableStatsUpload(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_IsStatsUploadDisabled
==============
*/
bool LiveStorage_IsStatsUploadDisabled(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
getTierForGamertag
==============
*/
EUserTier getTierForGamertag(const char *gamertag, unsigned __int64 xuid)
{
	UNIMPLEMENTED(__FUNCTION__);
	EUserTier tmp;
	return tmp;
}

/*
==============
LiveStorage_ParseUserTiers
==============
*/
void LiveStorage_ParseUserTiers()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_CanGamertagUseRestrictedClanTag
==============
*/
bool Live_CanGamertagUseRestrictedClanTag(const char *gamertag, unsigned __int64 xuid)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_SetupNestedTask
==============
*/
TaskRecord *LiveStorage_SetupNestedTask(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_ResetFileInfo
==============
*/
void LiveStorage_ResetFileInfo(dwFileOperationInfo *fileInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_UpdateFileTryData
==============
*/
void LiveStorage_UpdateFileTryData(fileRetryInfo *retryInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_TryFile
==============
*/
char LiveStorage_TryFile(fileRetryInfo *retryInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_DeleteUserFileFailure
==============
*/
char LiveStorage_DeleteUserFileFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_DeleteUserFileSuccess
==============
*/
char LiveStorage_DeleteUserFileSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_WriteUserFileFailure
==============
*/
char LiveStorage_WriteUserFileFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_WriteUserFileSuccess
==============
*/
char LiveStorage_WriteUserFileSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_WriteDWUserFile
==============
*/
TaskRecord *LiveStorage_WriteDWUserFile(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_GetUserFileFailure
==============
*/
char LiveStorage_GetUserFileFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_ReadDWFile
==============
*/
TaskRecord *LiveStorage_ReadDWFile(const ControllerIndex_t controllerIndex, dwFileOperationInfo *fileInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_ReadDWFileByUserID
==============
*/
TaskRecord *LiveStorage_ReadDWFileByUserID(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_CopyClassSetsFromSponsor
==============
*/
void LiveStorage_CopyClassSetsFromSponsor(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_SetClassSetsWriteNeeded
==============
*/
void LiveStorage_SetClassSetsWriteNeeded(const ControllerIndex_t controllerIndex, bool writeNeeded)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_WriteClassSetsFailure
==============
*/
bool LiveStorage_WriteClassSetsFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_TrackUsedClassSets
==============
*/
void LiveStorage_TrackUsedClassSets(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_WriteClassSets
==============
*/
TaskRecord *LiveStorage_WriteClassSets(const ControllerIndex_t controllerIndex, char *customFileName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_PlayerStatsFileNotFound
==============
*/
int LiveStorage_PlayerStatsFileNotFound(const ControllerIndex_t controllerIndex, void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_KeyArchiveWriteComplete
==============
*/
char LiveStorage_KeyArchiveWriteComplete(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_KeyArchiveWriteFailed
==============
*/
char LiveStorage_KeyArchiveWriteFailed(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_KeyArchiveReadComplete
==============
*/
char LiveStorage_KeyArchiveReadComplete(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_KeyArchiveReadFailed
==============
*/
char LiveStorage_KeyArchiveReadFailed(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_GetXPGroupsKeyArchive
==============
*/
TaskRecord *LiveStorage_GetXPGroupsKeyArchive(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_GetServerTimeComplete
==============
*/
bool LiveStorage_GetServerTimeComplete()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_GetServerTimeFailed
==============
*/
char LiveStorage_GetServerTimeFailed()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_GetUTC
==============
*/
int LiveStorage_GetUTC()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_GetUTCOffset
==============
*/
int LiveStorage_GetUTCOffset()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_IsTimeSynced
==============
*/
bool LiveStorage_IsTimeSynced()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_WriteMetPlayerListSuccessful
==============
*/
void LiveStorage_WriteMetPlayerListSuccessful(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_WriteMetPlayerList
==============
*/
TaskRecord *LiveStorage_WriteMetPlayerList(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_OtherPlayerStatsFileNotFound
==============
*/
int LiveStorage_OtherPlayerStatsFileNotFound(const ControllerIndex_t controllerIndex, void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_ReadCommonStats
==============
*/
TaskRecord *LiveStorage_ReadCommonStats(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_CalculateParity
==============
*/
int LiveStorage_CalculateParity(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_CheckParityBits
==============
*/
void LiveStorage_CheckParityBits(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_AppendParityToStats
==============
*/
void LiveStorage_AppendParityToStats(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_WriteBackupStatsInternal
==============
*/
TaskRecord *LiveStorage_WriteBackupStatsInternal(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_BackupCorruptedStatsDecompressError
==============
*/
void LiveStorage_BackupCorruptedStatsDecompressError(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_SetAllStatsNotFetched
==============
*/
void LiveStorage_SetAllStatsNotFetched(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_FileShare_GetCurrentHTTPLocation
==============
*/
fileShareLocation LiveStorage_FileShare_GetCurrentHTTPLocation(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	fileShareLocation tmp;
	return tmp;
}

/*
==============
LiveStorage_FileShare_GetDownloadProgress
==============
*/
void LiveStorage_FileShare_GetDownloadProgress(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_FileShare_GetUploadProgress
==============
*/
void LiveStorage_FileShare_GetUploadProgress(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_FileShare_IsReady
==============
*/
BOOL LiveStorage_FileShare_IsReady(const ControllerIndex_t controllerIndex, bool allowRead)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_AbortOperation
==============
*/
void LiveStorage_FileShare_AbortOperation(const ControllerIndex_t controllerIndex, fileShareLocation location)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_FileShare_ReadListing
==============
*/
TaskRecord *LiveStorage_FileShare_ReadListing(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_FileShare_ReadListingFailure
==============
*/
char LiveStorage_FileShare_ReadListingFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShareSortComparator_MostRecent
==============
*/
int LiveStorage_FileShareSortComparator_MostRecent(const void *arg0, const void *arg1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_LoadBlockSuccessAction
==============
*/
void LiveStorage_FileShare_LoadBlockSuccessAction(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_FileShare_DownloadFile_f
==============
*/
void LiveStorage_FileShare_DownloadFile_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_FileShare_SearchFailure
==============
*/
char LiveStorage_FileShare_SearchFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_ReadFileData
==============
*/
unsigned int LiveStorage_FileShare_ReadFileData(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_GetDownloadingFileTotalSize
==============
*/
unsigned int LiveStorage_FileShare_GetDownloadingFileTotalSize(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_GetUploadingFileTotalSize
==============
*/
ControllerIndex_t LiveStorage_FileShare_GetUploadingFileTotalSize(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	ControllerIndex_t tmp;
	return tmp;
}

/*
==============
fileShareDownloadInterceptor::handleDownload
==============
*/
/*unsigned int __thiscall fileShareDownloadInterceptor::handleDownload(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
LiveStorage_FileShare_ReadFileFailure
==============
*/
char LiveStorage_FileShare_ReadFileFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_ReadFileSuccess
==============
*/
char LiveStorage_FileShare_ReadFileSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_GetDWDownloadBuffer
==============
*/
char *LiveStorage_GetDWDownloadBuffer()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_GetDWDownloadBufferSize
==============
*/
int LiveStorage_GetDWDownloadBufferSize()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_WriteFileData
==============
*/
unsigned int LiveStorage_FileShare_WriteFileData(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
fileShareUploadInterceptor::handleUpload
==============
*/
/*unsigned int __thiscall fileShareUploadInterceptor::handleUpload(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
LiveStorage_FileShare_ReadFileIsInProgress
==============
*/
BOOL LiveStorage_FileShare_ReadFileIsInProgress(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_WriteFileIsInProgress
==============
*/
BOOL LiveStorage_FileShare_WriteFileIsInProgress(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_WriteFileFailure
==============
*/
char LiveStorage_FileShare_WriteFileFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_WriteFileSuccess
==============
*/
char LiveStorage_FileShare_WriteFileSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_ParseDownloadedMatchData
==============
*/
BOOL LiveStorage_FileShare_ParseDownloadedMatchData(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_WriteSummary
==============
*/
TaskRecord *LiveStorage_FileShare_WriteSummary(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_FileShare_WriteSummaryFailure
==============
*/
char LiveStorage_FileShare_WriteSummaryFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_WriteSummarySuccess
==============
*/
char LiveStorage_FileShare_WriteSummarySuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_ReadSummaryInProgress
==============
*/
BOOL LiveStorage_FileShare_ReadSummaryInProgress()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_ReadSummary
==============
*/
TaskRecord *LiveStorage_FileShare_ReadSummary(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_FileShare_ReadSummaryFailure
==============
*/
char LiveStorage_FileShare_ReadSummaryFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_ReadSummarySuccess
==============
*/
char LiveStorage_FileShare_ReadSummarySuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_ReadMetaDataByID
==============
*/
TaskRecord *LiveStorage_FileShare_ReadMetaDataByID(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_FileShare_ReadMetaDataByIDFailure
==============
*/
char LiveStorage_FileShare_ReadMetaDataByIDFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_ReadMetaDataByIDSuccess
==============
*/
char LiveStorage_FileShare_ReadMetaDataByIDSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_RemoveFile
==============
*/
TaskRecord *LiveStorage_FileShare_RemoveFile(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_FileShare_RemoveFileFailure
==============
*/
char LiveStorage_FileShare_RemoveFileFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_RemoveFileSuccess
==============
*/
char LiveStorage_FileShare_RemoveFileSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_TransferFile
==============
*/
TaskRecord *LiveStorage_FileShare_TransferFile(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_FileShare_TransferFileFailure
==============
*/
char LiveStorage_FileShare_TransferFileFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_TransferFileSuccess
==============
*/
char LiveStorage_FileShare_TransferFileSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_ReadTopRatedFailure
==============
*/
char LiveStorage_FileShare_ReadTopRatedFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_UserFileListAvailable
==============
*/
bool LiveStorage_UserFileListAvailable(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_AssertDWConnectionCmd
==============
*/
void LiveStorage_AssertDWConnectionCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_GeneratePopulationDataCmd
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
LiveStorage_FakeComErrorCmd
==============
*/
void LiveStorage_FakeComErrorCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_CopyStatsBuffer
==============
*/
void LiveStorage_CopyStatsBuffer(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_VerifyStatsPresent
==============
*/
/*char LiveStorage_VerifyStatsPresent@<al>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
LiveStorage_GetStatsBufferWithCaller
==============
*/
persistentStats *LiveStorage_GetStatsBufferWithCaller(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_GetStatsWriteNeeded
==============
*/
/*bool LiveStorage_GetStatsWriteNeeded@<al>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
LiveStorage_SetStatsWriteNeeded
==============
*/
void LiveStorage_SetStatsWriteNeeded(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_ValidateWithDDL
==============
*/
int LiveStorage_ValidateWithDDL(ControllerIndex_t controllerIndex, statsLocation location)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FetchRequiredFiles
==============
*/
void LiveStorage_FetchRequiredFiles(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_GetUserFileDecompressError
==============
*/
void LiveStorage_GetUserFileDecompressError(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_GetUserFileSuccess
==============
*/
char LiveStorage_GetUserFileSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_IsPublicStatsCorrectState
==============
*/
char LiveStorage_IsPublicStatsCorrectState(const ControllerIndex_t controllerIndex, statsLocation location)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_ResetClassSets
==============
*/
void LiveStorage_ResetClassSets(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_ClassSetsFileNotFound
==============
*/
int __thiscall LiveStorage_ClassSetsFileNotFound(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_ReadClassSetsSuccessful
==============
*/
void LiveStorage_ReadClassSetsSuccessful(const ControllerIndex_t controllerIndex, void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_ReadClassSets
==============
*/
TaskRecord *LiveStorage_ReadClassSets(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_ReadOtherPlayerStatsSuccessful
==============
*/
void LiveStorage_ReadOtherPlayerStatsSuccessful(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_CheckEmptyStats
==============
*/
void LiveStorage_CheckEmptyStats(const ControllerIndex_t controllerIndex, int decompressedSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_SyncTime
==============
*/
TaskRecord *LiveStorage_SyncTime(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_ReadOtherPlayerStats
==============
*/
TaskRecord *LiveStorage_ReadOtherPlayerStats(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_WriteStats
==============
*/
TaskRecord *LiveStorage_WriteStats(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_WritePlayerStatsFailure
==============
*/
bool LiveStorage_WritePlayerStatsFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_WritePlayerStats
==============
*/
TaskRecord *LiveStorage_WritePlayerStats(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_WriteBackupStats
==============
*/
void LiveStorage_WriteBackupStats(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_BackupStatsToFile
==============
*/
void LiveStorage_BackupStatsToFile(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_FileShare_ReadListingSuccess
==============
*/
char LiveStorage_FileShare_ReadListingSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_LoadBlockFailure
==============
*/
char LiveStorage_FileShare_LoadBlockFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_LoadBlockSuccess
==============
*/
char LiveStorage_FileShare_LoadBlockSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_SearchSuccess
==============
*/
char LiveStorage_FileShare_SearchSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_FileShare_ReadTopRatedSuccess
==============
*/
char LiveStorage_FileShare_ReadTopRatedSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_UploadStatsForController
==============
*/
void LiveStorage_UploadStatsForController(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_UploadStats
==============
*/
void LiveStorage_UploadStats()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_WriteBackupStatsCmd
==============
*/
void LiveStorage_WriteBackupStatsCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_GetFriendStatsCmd
==============
*/
void LiveStorage_GetFriendStatsCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_GetUserFileListSuccess
==============
*/
char LiveStorage_GetUserFileListSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_GetUserFileListFailure
==============
*/
char LiveStorage_GetUserFileListFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_UserFileListGetFileDetails
==============
*/
bdFileInfo *LiveStorage_UserFileListGetFileDetails(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_RestoreStatsFromBackup
==============
*/
void LiveStorage_RestoreStatsFromBackup(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_RestoreCorrectPublicStatsState
==============
*/
void LiveStorage_RestoreCorrectPublicStatsState(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_StatsBackupReadSuccessful
==============
*/
void LiveStorage_StatsBackupReadSuccessful(const ControllerIndex_t controllerIndex, void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_StatsBackupFileNotFound
==============
*/
int LiveStorage_StatsBackupFileNotFound(const ControllerIndex_t controllerIndex, void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_ReadPlayerStatsSuccessful
==============
*/
void LiveStorage_ReadPlayerStatsSuccessful(const ControllerIndex_t controllerIndex, void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_ReadStatsBackup
==============
*/
TaskRecord *LiveStorage_ReadStatsBackup(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_ReadPlayerStats
==============
*/
/*TaskRecord *LiveStorage_ReadPlayerStats@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
LiveStorage_ReadStats
==============
*/
void LiveStorage_ReadStats(const ControllerIndex_t controllerIndex, bool validate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_FileShare_LoadPage
==============
*/
TaskRecord *LiveStorage_FileShare_LoadPage(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_FileShare_ReadFile
==============
*/
TaskRecord *LiveStorage_FileShare_ReadFile(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_FileShare_WriteFile
==============
*/
TaskRecord *LiveStorage_FileShare_WriteFile(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStorage_ReadStatsBackupCmd
==============
*/
void LiveStorage_ReadStatsBackupCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_RestoreStatsFromBackupCmd
==============
*/
void LiveStorage_RestoreStatsFromBackupCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStorage_Init
==============
*/
char LiveStorage_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStorage_WaitOnStats
==============
*/
char LiveStorage_WaitOnStats(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

