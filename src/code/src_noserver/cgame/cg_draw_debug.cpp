#include "types.h"

/*
==============
CG_DrawScriptUsage
==============
*/
void CG_DrawScriptUsage(const ScreenPlacement *scrPlace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CompareSndInfoChannel
==============
*/
int CG_CompareSndInfoChannel(const void *va, const void *vb)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CompareSndInfoPriority
==============
*/
int CG_CompareSndInfoPriority(const void *va, const void *vb)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CompareSndInfoAlias
==============
*/
int CG_CompareSndInfoAlias(const void *va, const void *vb)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CompareSndInfoDryLevel
==============
*/
int CG_CompareSndInfoDryLevel(const void *va, const void *vb)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CompareSndInfoDistance
==============
*/
int CG_CompareSndInfoDistance(const void *va, const void *vb)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CompareSndInfoEntity
==============
*/
int CG_CompareSndInfoEntity(const void *va, const void *vb)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawSoundOverlay
==============
*/
void CG_DrawSoundOverlay(const ScreenPlacement *scrPlace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPerformanceWarnings
==============
*/
void CG_DrawPerformanceWarnings(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawModelBoneAxis
==============
*/
void CG_DrawModelBoneAxis(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawFxText
==============
*/
void CG_DrawFxText(const char *text, vec2_t *profilePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawFxPriorityText
==============
*/
void CG_DrawFxPriorityText(const char *text, vec2_t *profilePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawDebugPlayerHealth
==============
*/
void CG_DrawDebugPlayerHealth(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawDebugPlayerSprint
==============
*/
void CG_DrawDebugPlayerSprint(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawEntDObjBoneDebug
==============
*/
void CG_DrawEntDObjBoneDebug(LocalClientNum_t localClientNum, int entNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawDebugOverlays
==============
*/
void CG_DrawDebugOverlays(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawFullScreenDebugOverlays
==============
*/
void CG_DrawFullScreenDebugOverlays(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawGfxStatsLine
==============
*/
void CG_DrawGfxStatsLine(const ScreenPlacement *scrPlace, float line, const char *header, const vec4_t *color, int surfs, int mats, int prims, int tris)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawGfxStatsMatrix
==============
*/
void CG_DrawGfxStatsMatrix(const ScreenPlacement *scrPlace, GfxPrimStatsCounters counter)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawGfxStats
==============
*/
void CG_DrawGfxStats(int a1, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawVersion
==============
*/
void CG_DrawVersion(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_QuickPrintFlush
==============
*/
void CG_QuickPrintFlush()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetCornerDebugPrintScale_X
==============
*/
double CG_GetCornerDebugPrintScale_X()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetCornerDebugPrintScale_Y
==============
*/
double CG_GetCornerDebugPrintScale_Y()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CornerDebugPrint
==============
*/
double CG_CornerDebugPrint(LocalClientNum_t localClientNum, const ScreenPlacement *sP, float posX, float posY, float labelWidth, const char *text, const char *label, const vec4_t *color, Font_s *font)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DebugSessionInfo
==============
*/
char *DebugSessionInfo()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_DrawTaskErrorDebugInfo
==============
*/
void CG_DrawTaskErrorDebugInfo(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawHostDebugInfo
==============
*/
void CG_DrawHostDebugInfo(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawChangelistMismatch
==============
*/
void CG_DrawChangelistMismatch(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DebugLineVertical
==============
*/
void CG_DebugLineVertical(const vec3_t *p, const vec4_t *color, int depthTest, int duration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DebugStarWithText
==============
*/
void CG_DebugStarWithText(const vec3_t *point, const vec4_t *starColor, const vec4_t *textColor, const char *string, float fontsize, int duration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DebugBox
==============
*/
void CG_DebugBox(const vec3_t *origin, const vec3_t *mins, const vec3_t *maxs, float yaw, const vec4_t *color, int depthTest, int duration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DebugBoxOriented
==============
*/
void CG_DebugBoxOriented(const vec3_t *origin, const vec3_t *mins, const vec3_t *maxs, const vec3_t *rotation, const vec4_t *color, int depthTest, int duration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CornerDebugPrintCaption
==============
*/
float CG_CornerDebugPrintCaption(LocalClientNum_t localClientNum, const ScreenPlacement *sP, float posX, float posY, float labelWidth, const char *text, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawSnapshot
==============
*/
float CG_DrawSnapshot(LocalClientNum_t localClientNum, float posY)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawViewpos
==============
*/
float CG_DrawViewpos(const ScreenPlacement *scrPlace, float y, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawCullDistDebugText
==============
*/
float CG_DrawCullDistDebugText(const ScreenPlacement *scrPlace, float y, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawShadowMapDebugText
==============
*/
float CG_DrawShadowMapDebugText(const ScreenPlacement *scrPlace, float y, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DrawEntityCounts
==============
*/
float DrawEntityCounts(LocalClientNum_t localClientNum, const ScreenPlacement *scrPlace, float posY)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawAnimTagInfo
==============
*/
double CG_DrawAnimTagInfo(LocalClientNum_t localClientNum, const ScreenPlacement *scrPlace, float posY)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawFPS
==============
*/
double CG_DrawFPS(LocalClientNum_t localClientNum, const ScreenPlacement *scrPlace, float y, meminfo_t *meminfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_QuickPrint
==============
*/
void CG_QuickPrint(const char *fmt, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawUpperRightDebugInfo
==============
*/
void CG_DrawUpperRightDebugInfo(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

