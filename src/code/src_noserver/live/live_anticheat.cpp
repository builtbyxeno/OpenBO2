#include "types.h"

/*
==============
LiveAntiCheat_BanDoConnected
==============
*/
void LiveAntiCheat_BanDoConnected()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveAntiCheat_DWPlayerBanned
==============
*/
void LiveAntiCheat_DWPlayerBanned(unsigned __int64 userID, unsigned int reputationLevel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveAntiCheat_GenerateCRC32Checksum
==============
*/
void LiveAntiCheat_GenerateCRC32Checksum(const unsigned __int8 *data, int length, unsigned int *key)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveAntiCheat_GenerateCRC32ChecksumSplit
==============
*/
unsigned int LiveAntiCheat_GenerateCRC32ChecksumSplit(const unsigned __int8 *data, int length, unsigned __int64 key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveAntiCheat_StartHash
==============
*/
HashInfo *LiveAntiCheat_StartHash(challengeTest_t type, unsigned int start, unsigned int length, unsigned int blockSize, unsigned __int64 key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveAntiCheat_ContinueHash
==============
*/
bool LiveAntiCheat_ContinueHash(void *handle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveAntiCheat_CompleteHash
==============
*/
char LiveAntiCheat_CompleteHash(void *handle, unsigned __int64 *result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveAntiCheat_AnswerChallengesRetry
==============
*/
void LiveAntiCheat_AnswerChallengesRetry(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveAntiCheat_AnswerChallengesFailure
==============
*/
char LiveAntiCheat_AnswerChallengesFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveAntiCheat_ResetChallengeResponse
==============
*/
void LiveAntiCheat_ResetChallengeResponse(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveAntiCheat_ClearGameReport
==============
*/
void LiveAntiCheat_ClearGameReport()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveAntiCheat_SetThresholdExceeded
==============
*/
void LiveAntiCheat_SetThresholdExceeded(int threshold)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveAntiCheat_ReportLaggedDamage
==============
*/
void LiveAntiCheat_ReportLaggedDamage()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveAntiCheat_SetGameReportTags
==============
*/
void LiveAntiCheat_SetGameReportTags(int *numTags, bdTag *tags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveAntiCheat_AnswerChallenges
==============
*/
TaskRecord *LiveAntiCheat_AnswerChallenges(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveAntiCheat_AnswerChallengesSuccess
==============
*/
char LiveAntiCheat_AnswerChallengesSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveAntiCheat_OnChallengesReceived
==============
*/
/*void LiveAntiCheat_OnChallengesReceived(unsigned __int64 userID, bdReference<bdAntiCheatChallenges> challenges)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
LiveAntiCheat_AnswerChecksumRequest
==============
*/
/*bool LiveAntiCheat_AnswerChecksumRequest(const ControllerIndex_t controllerIndex, const bdArray<bdAntiCheatChallengeParam> *params, __int64 *checksum, challengeTest_t checksumType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
LiveAntiCheat_AnswerDvarRequest
==============
*/
/*bool LiveAntiCheat_AnswerDvarRequest(const ControllerIndex_t controllerIndex, const bdArray<bdAntiCheatChallengeParam> *params, __int64 *response)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
LiveAntiCheat_AnswerDvarFloatRequest
==============
*/
/*bool LiveAntiCheat_AnswerDvarFloatRequest(const ControllerIndex_t controllerIndex, const bdArray<bdAntiCheatChallengeParam> *params, __int64 *response)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
LiveAntiCheat_AnswerExpressionRequest
==============
*/
/*bool LiveAntiCheat_AnswerExpressionRequest(const ControllerIndex_t controllerIndex, const bdArray<bdAntiCheatChallengeParam> *params, __int64 *response)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
LiveAntiCheat_GetChallengeResponse
==============
*/
/*bool __cdecl LiveAntiCheat_GetChallengeResponse(const ControllerIndex_t controllerIndex, unsigned __int16 functionID, const bdArray<bdAntiCheatChallengeParam> *params, __int64 *response)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
LiveAntiCheat_ProcessChallenges
==============
*/
void LiveAntiCheat_ProcessChallenges(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

