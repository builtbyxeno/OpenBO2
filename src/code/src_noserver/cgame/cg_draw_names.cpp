#include "types.h"

/*
==============
TRACK_cg_draw_names
==============
*/
void TRACK_cg_draw_names()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ClearOverheadFade
==============
*/
void CG_ClearOverheadFade()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetOverheadFade
==============
*/
OverheadFade *CG_GetOverheadFade(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_ClearPlayerDetails
==============
*/
void CG_ClearPlayerDetails()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_InitPlayerDetails
==============
*/
void CG_InitPlayerDetails(LocalClientNum_t localClientNum, int targetClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalcNamePosition
==============
*/
bool CG_CalcNamePosition(LocalClientNum_t localClientNum, const vec3_t *origin, float *xOut, float *yOut)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetZombiePlayerColorIndex
==============
*/
int CG_GetZombiePlayerColorIndex(LocalClientNum_t localClientNum, ClientNum_t currentClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawOverheadNames
==============
*/
void CG_DrawOverheadNames(LocalClientNum_t localClientNum, const centity_t *cent, float alpha, int mode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CanSeeFriendlyHeadInView
==============
*/
bool CG_CanSeeFriendlyHeadInView(LocalClientNum_t localClientNum, const centity_t *cent, const vec3_t *start, const vec3_t *end)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetFriendlyHeadPos
==============
*/
void CG_GetFriendlyHeadPos(LocalClientNum_t localClientNum, const centity_t *cent, vec3_t *end)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CheckIfDrivingRemoteControlVehicle
==============
*/
int CG_CheckIfDrivingRemoteControlVehicle(LocalClientNum_t localClientNum, unsigned __int16 EntId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_ScanForCrosshairEntityInternal
==============
*/
void CG_ScanForCrosshairEntityInternal(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ScanForCrosshairEntity
==============
*/
void CG_ScanForCrosshairEntity(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
compareEntityDist
==============
*/
int compareEntityDist(const void *v1, const void *v2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_AddDrawName
==============
*/
void CG_AddDrawName(LocalClientNum_t localClientNum, int entnum, float alpha, team_indicator teamIndicator)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawNames
==============
*/
void CG_DrawNames(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_IsValidCrosshairEntity
==============
*/
bool CG_IsValidCrosshairEntity(LocalClientNum_t localClientNum, const cg_t *cgameGlob, const centity_t *cent, int entNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ShouldDrawCrosshairNames
==============
*/
bool ShouldDrawCrosshairNames(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawCrosshairNames
==============
*/
void CG_DrawCrosshairNames(LocalClientNum_t a1, int a2, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
activeKillstreakWithLineOfSightOverlay
==============
*/
bool activeKillstreakWithLineOfSightOverlay(LocalClientNum_t localClientNum, const cg_t *cgameGlob, int entnum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PlayerCanSeeEnemyNames
==============
*/
bool PlayerCanSeeEnemyNames(LocalClientNum_t localClientNum, int entnum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ShouldDrawPlayerName
==============
*/
bool ShouldDrawPlayerName(LocalClientNum_t localClientNum, int entnum, int team)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ShouldDrawFriendlyName
==============
*/
bool ShouldDrawFriendlyName(LocalClientNum_t localClientNum, const centity_t *cent, int entnum, int team)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetVehicleDriverEntNum
==============
*/
int GetVehicleDriverEntNum(const cg_t *cgameGlob, const centity_t *cent, int entnum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CanSeeFriendlyHeadTrace
==============
*/
bool CG_CanSeeFriendlyHeadTrace(const centity_t *cent, const vec3_t *start, const vec3_t *end)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CanSeeFriendlyHead
==============
*/
bool CG_CanSeeFriendlyHead(vec3_t *a1, LocalClientNum_t localClientNum, const centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawActorName
==============
*/
void CG_DrawActorName(LocalClientNum_t localClientNum, const centity_t *cent, bool flashed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawFriendlyName
==============
*/
void CG_DrawFriendlyName(LocalClientNum_t a1, vec3_t *a2, LocalClientNum_t localClientNum, const cg_t *cgameGlob, const centity_t *cent, int team, int friendlyNameFadeIn, int friendlyNameFadeOut, int enemyNameFadeIn, int enemyNameFadeOut, bool flashed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawFriendlyNames
==============
*/
void CG_DrawFriendlyNames(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawVisibleNames
==============
*/
void CG_DrawVisibleNames(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

