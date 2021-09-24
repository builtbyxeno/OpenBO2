#include "types.h"

/*
==============
Demo_GetKeyboardTitle
==============
*/
const char *Demo_GetKeyboardTitle()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_GetKeyboardDefaultText
==============
*/
const char *Demo_GetKeyboardDefaultText()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_GetKeyboardTextSize
==============
*/
int Demo_GetKeyboardTextSize()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_GetStartAndEndTime
==============
*/
void Demo_GetStartAndEndTime(int *startTime, int *endTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_GetDuration
==============
*/
void Demo_GetDuration(char *outputText, int duration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_GetAuthor
==============
*/
char *Demo_GetAuthor()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_GetTitleName
==============
*/
char *Demo_GetTitleName()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_GetTitleDescription
==============
*/
char *Demo_GetTitleDescription()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_GetTimeInfo
==============
*/
char *Demo_GetTimeInfo()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_GetDuration
==============
*/
char *Demo_GetDuration()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_GetSaveScreenName
==============
*/
char *Demo_GetSaveScreenName(const char *type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_GetSaveScreenDescription
==============
*/
char *Demo_GetSaveScreenDescription(const char *type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_GetConnectionTimeInfoForPlayer
==============
*/
void Demo_GetConnectionTimeInfoForPlayer(LocalClientNum_t localClientNum, int *connectTime, int *disconnectTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_GetPlayerIndexForClientNum
==============
*/
int Demo_GetPlayerIndexForClientNum(ClientNum_t clientNum, int serverTime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_GetNextDefaultBookmarkForPlayer
==============
*/
int Demo_GetNextDefaultBookmarkForPlayer(int playerIndex, ClientNum_t clientNum, int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_GetNextDefaultBookmarkForPlayer
==============
*/
int Demo_GetNextDefaultBookmarkForPlayer(LocalClientNum_t localClientNum, int index, int *type, int *time, vec4_t *color, bool *useBottomHalfColor, vec4_t *bottomHalfColor)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_GetDebugNameForBookmarkType
==============
*/
const char *Demo_GetDebugNameForBookmarkType(demoBookmarkType type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_GetFreeCamModeName
==============
*/
const char *Demo_GetFreeCamModeName()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_GetNextDollyCamMarker
==============
*/
int Demo_GetNextDollyCamMarker(LocalClientNum_t localClientNum, int index, int *time, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_GetTimeScaleModeNameForDollyCamMarker
==============
*/
const char *Demo_GetTimeScaleModeNameForDollyCamMarker(int marker)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_OpenDollyCamMarkerPopUp
==============
*/
void Demo_OpenDollyCamMarkerPopUp(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_IsDollyCamMarkerDialogOpen
==============
*/
bool Demo_IsDollyCamMarkerDialogOpen(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_GetActivatedColorForButton
==============
*/
void Demo_GetActivatedColorForButton(demoControlsButton demoControlButtonType, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_DrawVerticalLine
==============
*/
void Demo_DrawVerticalLine(const ScreenPlacement *scrPlace, float x, float y, float w, float h, int horzAlign, int vertAlign, float s1, float t1, float s2, float t2, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_GetSegmentTransition
==============
*/
char *Demo_GetSegmentTransition(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_GetSegmentInformation
==============
*/
clipSegment *Demo_GetSegmentInformation(int index, const char *s)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_IsPauseMenuOpen
==============
*/
char Demo_IsPauseMenuOpen(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_OpenSavePopUp
==============
*/
void Demo_OpenSavePopUp(LocalClientNum_t localClientNum, demoSavePopup type)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_IsSaveDialogOpen
==============
*/
bool Demo_IsSaveDialogOpen(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_Error
==============
*/
void Demo_Error(LocalClientNum_t localClientNum, const char *errorTitle, const char *errorMessage)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_IsErrorDialogOpen
==============
*/
bool Demo_IsErrorDialogOpen(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_ShouldDrawDemoControlsHUD
==============
*/
bool Demo_ShouldDrawDemoControlsHUD(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_KeyboardComplete
==============
*/
void Demo_KeyboardComplete(LocalClientNum_t localClientNum, char *string, bool errorReported, const char *errorString)
{
	UNIMPLEMENTED(__FUNCTION__);
}

