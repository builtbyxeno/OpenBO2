#include "types.h"
#include "functions.h"

/*
==============
Demo_StartStreaming
==============
*/
void Demo_StartStreaming(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SetUploadFileID
==============
*/
void Demo_SetUploadFileID()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_GetUploadFileID
==============
*/
unsigned __int64 Demo_GetUploadFileID()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_BBPostDemoStreamStatsForGame
==============
*/
void Demo_BBPostDemoStreamStatsForGame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_BBPostDemoStreamStatsForInterval
==============
*/
void Demo_BBPostDemoStreamStatsForInterval()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_StopStreaming
==============
*/
void Demo_StopStreaming()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SetupDWStreamingSocketParams
==============
*/
void Demo_SetupDWStreamingSocketParams(int sendSocketBuffSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SetLeagueTags
==============
*/
void Demo_SetLeagueTags(ControllerIndex_t controllerIndex, int *numTags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SetTags
==============
*/
void Demo_SetTags(ControllerIndex_t controllerIndex, int *numTags, bdTag *tags, demoDefaultMetaInfo *info, fileshareCategory_e category, void *optionalParam1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SetStreamingParameters
==============
*/
void Demo_SetStreamingParameters(int svTotalBytesSent, int svMaxBytesPerFrame)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_GetCurrUsedBuffer
==============
*/
int Demo_GetCurrUsedBuffer()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_CurrAvailableBuffer
==============
*/
int Demo_CurrAvailableBuffer()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_GetMaxBufferSize
==============
*/
int Demo_GetMaxBufferSize()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_IsStreamingActive
==============
*/
bool Demo_IsStreamingActive()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_IsStreamingOverflowed
==============
*/
bool Demo_IsStreamingOverflowed()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_IsStreamingFinished
==============
*/
bool Demo_IsStreamingFinished()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_BBPostDemoStreamStatsForRound
==============
*/
void Demo_BBPostDemoStreamStatsForRound(int roundNumber)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_GetEstimatedTimeToFinishStreaming
==============
*/
int Demo_GetEstimatedTimeToFinishStreaming(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_SetMetaData
==============
*/
bool Demo_SetMetaData(ControllerIndex_t controllerIndex, unsigned __int8 *metaData, int metaDataSize, demoDefaultMetaInfo *info, int duration, bool isPooled)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_WriteSummary_SuccessCallback
==============
*/
void Demo_WriteSummary_SuccessCallback(ControllerIndex_t controllerIndex, unsigned __int64 fileID)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_StreamingSuccessCallback
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Demo_StreamingFailureCallback
==============
*/
void Demo_StreamingFailureCallback()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_UploadMatchRecordData
==============
*/
void Demo_UploadMatchRecordData()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_ThrottleStream
==============
*/
unsigned int Demo_ThrottleStream(unsigned int dataSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_AppendToStreamingHistory
==============
*/
void Demo_AppendToStreamingHistory(int val, bool isAdded)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_RecordSentPacket
==============
*/
void Demo_RecordSentPacket(unsigned int size)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_WriteToStream
==============
*/
unsigned int Demo_WriteToStream(void *data, unsigned int dataSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_SetupStreamingForRecording
==============
*/
void Demo_SetupStreamingForRecording(ControllerIndex_t controllerIndex, char *demoName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SaveToStreamBuffer
==============
*/
void Demo_SaveToStreamBuffer(const void *data, int dataSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SaveScreenshotSummarySuccess
==============
*/
void Demo_SaveScreenshotSummarySuccess(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SaveScreenshotFailure
==============
*/
void Demo_SaveScreenshotFailure()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SaveScreenshotSuccessful
==============
*/
void Demo_SaveScreenshotSuccessful(ControllerIndex_t controllerIndex, unsigned __int64 fileID)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SaveScreenshotToContentServer
==============
*/
void Demo_SaveScreenshotToContentServer(LocalClientNum_t localClientNum, int fileSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_UploadClipSummarySuccess
==============
*/
void Demo_UploadClipSummarySuccess(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_UploadClipFailure
==============
*/
void Demo_UploadClipFailure()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_UploadClipSuccess
==============
*/
void Demo_UploadClipSuccess(ControllerIndex_t controllerIndex, unsigned __int64 fileID)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_MoveToNextClipStreamingPhase
==============
*/
int Demo_MoveToNextClipStreamingPhase()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_SetupClipStreamingState
==============
*/
int Demo_SetupClipStreamingState()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_SendClipToStreamingBuffer
==============
*/
int Demo_SendClipToStreamingBuffer(void *data, unsigned int dataSize, unsigned int bytesUploaded)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_WriteRecordedClipToContentServer
==============
*/
void Demo_WriteRecordedClipToContentServer(LocalClientNum_t localClientNum, int slot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_IsDemoDownloading
==============
*/
bool Demo_IsDemoDownloading()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_DownloadFileCallback
==============
*/
void Demo_DownloadFileCallback(void *data, unsigned int dataSize, unsigned int bytesDownloaded, unsigned int fileSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_DownloadNextFileSegment
==============
*/
unsigned __int8 Demo_DownloadNextFileSegment()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_ShouldRetryDownloadOfFileSegment
==============
*/
bool Demo_ShouldRetryDownloadOfFileSegment()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_RetryDownloadOfFileSegment
==============
*/
void Demo_RetryDownloadOfFileSegment()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SetNextDownloadPhase
==============
*/
void Demo_SetNextDownloadPhase(bool success)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_DownloadFileSuccess
==============
*/
void Demo_DownloadFileSuccess()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_DownloadFileFailure
==============
*/
void Demo_DownloadFileFailure()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_DownloadFile
==============
*/
void Demo_DownloadFile(ControllerIndex_t controllerIndex, char *filmName, unsigned __int64 fileId, int fileSize, bool isUserFile, const char *demoMode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_GetStreamedDownloadProgress
==============
*/
double Demo_GetStreamedDownloadProgress()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_IsReadyForStreamedDemoPlayback
==============
*/
bool Demo_IsReadyForStreamedDemoPlayback()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_ResetReadyForStreamedDemoPlayback
==============
*/
void Demo_ResetReadyForStreamedDemoPlayback()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_HaveWeDownloadedNextFileSegmentData
==============
*/
bool Demo_HaveWeDownloadedNextFileSegmentData()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_AreWeStreamingFileDownload
==============
*/
bool Demo_AreWeStreamingFileDownload()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_DownloadAndPlaySuccess
==============
*/
void Demo_DownloadAndPlaySuccess()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_DownloadAndPlay
==============
*/
void Demo_DownloadAndPlay(ControllerIndex_t controllerIndex, unsigned __int64 fileID)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_ShouldResumeAbortedDemoDownload
==============
*/
bool Demo_ShouldResumeAbortedDemoDownload()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_ResumeAbortedDemoDownload
==============
*/
void Demo_ResumeAbortedDemoDownload()
{
	UNIMPLEMENTED(__FUNCTION__);
}

