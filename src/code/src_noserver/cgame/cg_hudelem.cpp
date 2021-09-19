#include "types.h"
#include "functions.h"

/*
==============
CG_HudElemRegisterDvars
==============
*/
void CG_HudElemRegisterDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DirectiveFakeIntroSeconds
==============
*/
void DirectiveFakeIntroSeconds(LocalClientNum_t localClientNum, const char *arg0, char *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ParseDirective
==============
*/
void ParseDirective(const char *directive, char *resultName, char *resultArg0)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetHudelemDirective
==============
*/
void GetHudelemDirective(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ReplaceDirective
==============
*/
char ReplaceDirective(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_TranslateHudElemMessage
==============
*/
void CG_TranslateHudElemMessage(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SafeTranslateHudElemString
==============
*/
void SafeTranslateHudElemString(LocalClientNum_t localClientNum, int index, char *hudElemString)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HudElemStringWidth
==============
*/
float HudElemStringWidth(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetHudElemTime
==============
*/
int GetHudElemTime(const hudelem_s *elem, int timeNow)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
HudElemTimerString
==============
*/
const char *HudElemTimerString(const hudelem_s *elem, int timeNow)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
HudElemTenthsTimerString
==============
*/
const char *HudElemTenthsTimerString(const hudelem_s *elem, int timeNow)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
HudElemMaterialWidth
==============
*/
float HudElemMaterialWidth(const ScreenPlacement *scrPlace, const hudelem_s *elem, const cg_hudelem_t *cghe)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
HudElemMaterialHeight
==============
*/
float HudElemMaterialHeight(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
HudElemWidth
==============
*/
float HudElemWidth(const ScreenPlacement *scrPlace, const hudelem_s *elem, const cg_hudelem_t *cghe)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
HudElemHeight
==============
*/
float HudElemHeight(const ScreenPlacement *scrPlace, const hudelem_s *elem, const cg_hudelem_t *cghe)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetHudElemOrg
==============
*/
void GetHudElemOrg(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SetHudElemPos
==============
*/
void SetHudElemPos(const ScreenPlacement *scrPlace, const hudelem_s *elem, cg_hudelem_t *cghe)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
OffsetHudElemY
==============
*/
float OffsetHudElemY(const hudelem_s *elem, const cg_hudelem_t *cghe, float offsetY)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ConsolidateHudElemText
==============
*/
void ConsolidateHudElemText(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CopyStringToHudElemString
==============
*/
void CopyStringToHudElemString(const char *string, char *hudElemString)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetHudElemInfo
==============
*/
void GetHudElemInfo(LocalClientNum_t localClientNum, const hudelem_s *elem, cg_hudelem_t *cghe)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HudElemColorToVec4
==============
*/
void HudElemColorToVec4(const hudelem_color_t *hudElemColor, vec4_t *resultColor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawHudElemString
==============
*/
void DrawHudElemString(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawHudElemClock
==============
*/
void DrawHudElemClock(LocalClientNum_t localClientNum, const hudelem_s *elem, const cg_hudelem_t *cghe)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawHudElemMaterial
==============
*/
void DrawHudElemMaterial(LocalClientNum_t localClientNum, const hudelem_s *elem, cg_hudelem_t *cghe)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HudElemWaypointHeight
==============
*/
float HudElemWaypointHeight(LocalClientNum_t localClientNum, const hudelem_s *elem)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
WorldPosToScreenPos
==============
*/
char WorldPosToScreenPos(LocalClientNum_t localClientNum, const vec3_t *worldPos, vec2_t *outScreenPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
WorldPosToExtraCamScreenPos
==============
*/
char WorldPosToExtraCamScreenPos(LocalClientNum_t localClientNum, const vec3_t *worldPos, vec2_t *outScreenPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ClampScreenPosToEdges
==============
*/
BOOL ClampScreenPosToEdges(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetScaleForDistance
==============
*/
float GetScaleForDistance(LocalClientNum_t localClientNum, const vec3_t *worldPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
WaypointFadeGetTimeFrac
==============
*/
float WaypointFadeGetTimeFrac(const cg_t *cgameGlob, int currentTime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
WaypointTargetFade
==============
*/
void WaypointTargetFade(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawOffscreenViewableWaypoint
==============
*/
void DrawOffscreenViewableWaypoint(LocalClientNum_t localClientNum, const hudelem_s *elem)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawHudElemPerk
==============
*/
float DrawHudElemPerk(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DrawHudElemPerkName
==============
*/
void DrawHudElemPerkName(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawHudElemPerks
==============
*/
void DrawHudElemPerks(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawSingleHudElem2d
==============
*/
void DrawSingleHudElem2d(LocalClientNum_t localClientNum, const hudelem_s *elem)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
compare_hudelems
==============
*/
int compare_hudelems(const void *pe0, const void *pe1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetSortedHudElems
==============
*/
int GetSortedHudElems(LocalClientNum_t localClientNum, hudelem_s **elems)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetSortedDebugHudElems
==============
*/
int GetSortedDebugHudElems(hudelem_s **elems)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Draw2dHudElemList
==============
*/
void CG_Draw2dHudElemList(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Draw2dHudElems
==============
*/
void CG_Draw2dHudElems(LocalClientNum_t localClientNum, int foreground)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AddDrawSurfForHudElemWaypoint
==============
*/
void AddDrawSurfForHudElemWaypoint(LocalClientNum_t localClientNum, const hudelem_s *elem)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_AddWaypoint
==============
*/
bool RB_AddWaypoint(LocalClientNum_t localClientNum, const hudelem_s *elem, int slot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RB_AddWaypoints
==============
*/
void RB_AddWaypoints(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_ClearWaypoints
==============
*/
void RB_ClearWaypoints(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AddDrawSurfsFor3dHudElems
==============
*/
void CG_AddDrawSurfsFor3dHudElems(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AddWaypoint
==============
*/
void CG_AddWaypoint(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_NumDrawWaypoints
==============
*/
int RB_NumDrawWaypoints(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

