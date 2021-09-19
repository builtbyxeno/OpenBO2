#include "types.h"
#include "functions.h"

/*
==============
CG_AntiBurnInHUD_RegisterDvars
==============
*/
void CG_AntiBurnInHUD_RegisterDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_NewDraw_RegisterDvars
==============
*/
void CG_NewDraw_RegisterDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ShouldDrawHud
==============
*/
BOOL CG_ShouldDrawHud(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_FadeHudMenu
==============
*/
double CG_FadeHudMenu(LocalClientNum_t localClientNum, float fadeVal, int displayStartTime, int duration)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CheckPlayerForLowAmmoSpecific
==============
*/
bool CG_CheckPlayerForLowAmmoSpecific(const cg_t *cgameGlob, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CheckPlayerForLowAmmo
==============
*/
bool CG_CheckPlayerForLowAmmo(const cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CheckForLowClip
==============
*/
bool CG_CheckForLowClip(const playerState_s *ps, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CheckPlayerForLowClipSpecific
==============
*/
bool CG_CheckPlayerForLowClipSpecific(const cg_t *cgameGlob, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CheckPlayerForLowClip
==============
*/
bool CG_CheckPlayerForLowClip(const cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawPlayerAmmoBackdrop
==============
*/
void CG_DrawPlayerAmmoBackdrop(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerAmmoValue
==============
*/
void CG_DrawPlayerAmmoValue(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerHeatValue
==============
*/
void CG_DrawPlayerHeatValue(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerFuelAmmoValue
==============
*/
void CG_DrawPlayerFuelAmmoValue(LocalClientNum_t localClientNum, const rectDef_s *rect, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerReloadValue
==============
*/
void CG_DrawPlayerReloadValue(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerReloadedValue
==============
*/
void CG_DrawPlayerReloadedValue(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerWeaponName
==============
*/
void CG_DrawPlayerWeaponName(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerWeaponNameBack
==============
*/
void CG_DrawPlayerWeaponNameBack(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalcPlayerSprintColor
==============
*/
void CG_CalcPlayerSprintColor(const cg_t *cgameGlob, const playerState_s *ps, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CalcSplitScreenStanceOffset
==============
*/
void CalcSplitScreenStanceOffset(float *x, float *y)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawStanceHintPrints
==============
*/
void CG_DrawStanceHintPrints(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerStance
==============
*/
void CG_DrawPlayerStance(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerSprintBack
==============
*/
void CG_DrawPlayerSprintBack(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerSprintMeter
==============
*/
void CG_DrawPlayerSprintMeter(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalcPlayerHealth
==============
*/
double CG_CalcPlayerHealth(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawPlayerBarHealth
==============
*/
void CG_DrawPlayerBarHealth(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerBarHealthBack
==============
*/
void CG_DrawPlayerBarHealthBack(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_FadeLowHealthOverlay
==============
*/
float CG_FadeLowHealthOverlay(const cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_PulseLowHealthOverlay
==============
*/
void CG_PulseLowHealthOverlay(cg_t *cgameGlob, float healthRatio)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ResetLowHealthOverlay
==============
*/
void CG_ResetLowHealthOverlay(cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerLowHealthOverlay
==============
*/
/*double CG_DrawPlayerLowHealthOverlay@<st0>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
CG_DrawPlayerDirectionalHitIndicator
==============
*/
void CG_DrawPlayerDirectionalHitIndicator(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ResetDirectionalDamageIndicators
==============
*/
void CG_ResetDirectionalDamageIndicators(LocalClientNum_t localClientNum, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ServerMaterialName
==============
*/
int CG_ServerMaterialName(LocalClientNum_t localClientNum, int index, char *materialName, unsigned int maxLen)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_ObjectiveIcon
==============
*/
Material *CG_ObjectiveIcon(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_UpdateCursorHints
==============
*/
void CG_UpdateCursorHints(cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetWeaponUseString
==============
*/
const char *CG_GetWeaponUseString(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_GetUseString
==============
*/
const char *CG_GetUseString(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_DrawCursorhint
==============
*/
void CG_DrawCursorhint(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawHoldBreathHint
==============
*/
void CG_DrawHoldBreathHint(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawHoldBreathZoomHint
==============
*/
void CG_DrawHoldBreathZoomHint(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawAirburstMarkHint
==============
*/
void CG_DrawAirburstMarkHint(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawRCBombHints
==============
*/
void CG_DrawRCBombHints(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawGuidedMissileBoostHint
==============
*/
void CG_DrawGuidedMissileBoostHint(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawGuidedMissileDetonateHint
==============
*/
void CG_DrawGuidedMissileDetonateHint(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawRemoteMissileSteerHint
==============
*/
void CG_DrawRemoteMissileSteerHint(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawRemoteMissileBoostHint
==============
*/
void CG_DrawRemoteMissileBoostHint(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetClosestTargetToGuidedMissile
==============
*/
float CG_GetClosestTargetToGuidedMissile(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetDistanceGuidedMissileAndOwner
==============
*/
float CG_GetDistanceGuidedMissileAndOwner(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawGuidedMissileInfo
==============
*/
void CG_DrawGuidedMissileInfo(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawTurretPlaceHint
==============
*/
void CG_DrawTurretPlaceHint(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawMantleHint
==============
*/
void CG_DrawMantleHint(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ScriptMainMenu
==============
*/
char *CG_ScriptMainMenu(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_DrawInvalidCmdHint
==============
*/
void CG_DrawInvalidCmdHint(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawTalkerNum
==============
*/
void CG_DrawTalkerNum(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
get_tank_hud_health_tint_color
==============
*/
void get_tank_hud_health_tint_color(float health_fraction, vec4_t *rgba, float black_when_dead)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
draw_tank_turret_component
==============
*/
void draw_tank_turret_component(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawWarMomentumProgress
==============
*/
void CG_DrawWarMomentumProgress(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawWarMomentumMultiplier
==============
*/
void CG_DrawWarMomentumMultiplier(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawWarMomentumMultiplierDetail
==============
*/
void CG_DrawWarMomentumMultiplierDetail(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawWarMomentumMultiplierBlitzkrieg
==============
*/
void CG_DrawWarMomentumMultiplierBlitzkrieg(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawWarText
==============
*/
void CG_DrawWarText(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawWristWatch
==============
*/
void CG_DrawWristWatch(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawAirburstDistance
==============
*/
void DrawAirburstDistance(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawAirburstCurrentDistance
==============
*/
void CG_DrawAirburstCurrentDistance(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawAirburstMarkDistance
==============
*/
void CG_DrawAirburstMarkDistance(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawAirburstMarkTimer
==============
*/
void CG_DrawAirburstMarkTimer(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawDemoControls
==============
*/
void CG_DrawDemoControls(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ShouldDrawPlayerTargetHighlightsFriendlies
==============
*/
bool ShouldDrawPlayerTargetHighlightsFriendlies(LocalClientNum_t localClientNum, const cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ShouldDrawPlayerTargetHighlights
==============
*/
bool ShouldDrawPlayerTargetHighlights(LocalClientNum_t localClientNum, const cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ShouldDrawPlayerLineOfSightTargetHighlights
==============
*/
bool ShouldDrawPlayerLineOfSightTargetHighlights(LocalClientNum_t localClientNum, const cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawTarget
==============
*/
void CG_DrawTarget(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerTargetHighlights
==============
*/
void CG_DrawPlayerTargetHighlights(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerTargetHighlightsLineOfSight
==============
*/
void CG_DrawPlayerTargetHighlightsLineOfSight(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerTargetHighlightsFriendly
==============
*/
void CG_DrawPlayerTargetHighlightsFriendly(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawTargetHighlightsForEntity
==============
*/
void CG_DrawTargetHighlightsForEntity(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawVehicleTargetHighlights
==============
*/
void CG_DrawVehicleTargetHighlights(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawTurretTargetHighlights
==============
*/
void CG_DrawTurretTargetHighlights(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawDogTargetHighlights
==============
*/
void CG_DrawDogTargetHighlights(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawTargetHighlights
==============
*/
void CG_DrawTargetHighlights(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawTargetHighlightsFriendly
==============
*/
void CG_DrawTargetHighlightsFriendly(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawGuidedMissileFuel
==============
*/
void CG_DrawGuidedMissileFuel(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawChargeShotBulletCounter
==============
*/
void CG_DrawChargeShotBulletCounter(LocalClientNum_t localClientNum, rectDef_s *rect, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_OwnerDraw
==============
*/
void CG_OwnerDraw(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_OwnerDrawText
==============
*/
void CG_OwnerDrawText(
{
	UNIMPLEMENTED(__FUNCTION__);
}

