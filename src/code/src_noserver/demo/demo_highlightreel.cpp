#include "types.h"
#include "functions.h"

/*
==============
Demo_SetupHighlightReelInformationDefines
==============
*/
demoPlayback *Demo_SetupHighlightReelInformationDefines()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_SetupHighlightReelStarLevels
==============
*/
demoPlayback *Demo_SetupHighlightReelStarLevels()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_InitializeHighlightReelSystem
==============
*/
void Demo_InitializeHighlightReelSystem()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_GetHighlightReelInformationDefine
==============
*/
demoHighlightReelInformationDefine *Demo_GetHighlightReelInformationDefine(demoHighlightReelInformationType type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_GetHighlightReelInformationDefineFromBookmarkType
==============
*/
demoHighlightReelInformationDefine *Demo_GetHighlightReelInformationDefineFromBookmarkType(demoBookmarkType bookmarkType, __int16 eType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_GetEntityLookAtForBookmark
==============
*/
int Demo_GetEntityLookAtForBookmark(const demoDefaultBookmark *bookmark)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_BookmarkMatchesForClientNum
==============
*/
bool Demo_BookmarkMatchesForClientNum(ClientNum_t clientNum, const demoDefaultBookmark *bookmark)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_CompareHighlightReelTimelineEventsByStartTime
==============
*/
int Demo_CompareHighlightReelTimelineEventsByStartTime(const void *event1, const void *event2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_CompareHighlightReelTimelineEventsByMultipleParameters
==============
*/
int Demo_CompareHighlightReelTimelineEventsByMultipleParameters(const void *event1, const void *event2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_HighlightReelFinalizePlayerDeathInformation
==============
*/
void Demo_HighlightReelFinalizePlayerDeathInformation(demoHighlightReelInformationDefine *infoDefine, demoHighlightReelPreparingInformation *information, demoDefaultBookmark *bookmark, ClientNum_t clientNum, demoHighlightReelPlayerPriority playerPriority)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_HighlightReelPrepareFirstPersonInformation
==============
*/
void Demo_HighlightReelPrepareFirstPersonInformation(int a1, demoDefaultBookmark *a2, demoHighlightReelInformationDefine *infoDefine, demoHighlightReelPreparingInformation *information, int bookmarkIndex, demoDefaultBookmark *bookmark, ClientNum_t clientNum, demoHighlightReelPlayerPriority playerPriority, demoDefaultBookmark *previousDeathBookmark)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_HighlightReelPrepareSingleEventInformation
==============
*/
void Demo_HighlightReelPrepareSingleEventInformation(demoHighlightReelInformationDefine *infoDefine, demoHighlightReelPreparingInformation *information, int bookmarkIndex, demoDefaultBookmark *bookmark, ClientNum_t clientNum, demoHighlightReelPlayerPriority playerPriority)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_FinishPendingHighlightReelTimelineUpdates
==============
*/
int Demo_FinishPendingHighlightReelTimelineUpdates()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_HighlightReelShouldFilterPlayer
==============
*/
bool Demo_HighlightReelShouldFilterPlayer(ControllerIndex_t controllerIndex, int playerIndex, int demoUserPlayerIndex, bool isFFAGame)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_HighlightReelShouldFilterByStyle_MP
==============
*/
bool Demo_HighlightReelShouldFilterByStyle_MP(demoBookmarkType type, __int16 eType, bool overrideEntityCamera)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_SetupHighlightReelKillcam
==============
*/
void Demo_SetupHighlightReelKillcam(LocalClientNum_t localClientNum, int currentProcessingHighlightReelTimelineIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_UpdateHighlightReelKillcamEntityValidity
==============
*/
void Demo_UpdateHighlightReelKillcamEntityValidity(LocalClientNum_t localClientNum, int currentProcessingHighlightReelTimelineIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_ResetHighlightReelKillcam
==============
*/
void Demo_ResetHighlightReelKillcam(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_UpdateHighlightReelTimeScale
==============
*/
void Demo_UpdateHighlightReelTimeScale(LocalClientNum_t localClientNum, int currentProcessingHighlightReelTimelineIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SetHighlightReelTransition
==============
*/
void Demo_SetHighlightReelTransition(demoClipTransition *transition)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_HandleBody
==============
*/
const cpose_t *Ragdoll_HandleBody(const cpose_t *pose)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_GetHighlightReelStarsForPriority
==============
*/
double Demo_GetHighlightReelStarsForPriority(int priority)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_CancelHighlightReelCreation
==============
*/
void Demo_CancelHighlightReelCreation()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_ProcessAndFinalizeHighlightReelMoments
==============
*/
void Demo_ProcessAndFinalizeHighlightReelMoments(int numberOfSegmentsToRetain)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SetupHighlightReelTimeline
==============
*/
void Demo_SetupHighlightReelTimeline(int a1, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_HighlightReelUpdate
==============
*/
void Demo_HighlightReelUpdate(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

