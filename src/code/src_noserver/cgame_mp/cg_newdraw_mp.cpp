#include "types.h"

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
void CG_DrawPlayerAmmoBackdrop(LocalClientNum_t localClientNum, const rectDef_s *rect, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerAmmoValue
==============
*/
void CG_DrawPlayerAmmoValue(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float scale, vec4_t *color, Material *material, int textStyle, int type)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerHeatValue
==============
*/
void CG_DrawPlayerHeatValue(LocalClientNum_t localClientNum, const rectDef_s *rect, vec4_t *color, bool drawVehicleTurretVersion)
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
void CG_DrawPlayerReloadValue(LocalClientNum_t localClientNum, const rectDef_s *rect, vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerReloadedValue
==============
*/
void CG_DrawPlayerReloadedValue(LocalClientNum_t localClientNum, const rectDef_s *rect, vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerWeaponName
==============
*/
void CG_DrawPlayerWeaponName(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float scale, vec4_t *color, int textStyle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerWeaponNameBack
==============
*/
void CG_DrawPlayerWeaponNameBack(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float scale, const vec4_t *color, Material *material)
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
void CG_DrawStanceHintPrints(LocalClientNum_t localClientNum, const rectDef_s *rect, float x, const vec4_t *color, float fadeAlpha, Font_s *font, float scale, int textStyle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerStance
==============
*/
void CG_DrawPlayerStance(LocalClientNum_t localClientNum, const rectDef_s *rect, const vec4_t *color, Font_s *font, float scale, int textStyle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerSprintBack
==============
*/
void CG_DrawPlayerSprintBack(LocalClientNum_t localClientNum, const rectDef_s *rect, Material *material, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerSprintMeter
==============
*/
void CG_DrawPlayerSprintMeter(LocalClientNum_t localClientNum, const rectDef_s *rect, Material *material, vec4_t *color)
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
void CG_DrawPlayerBarHealth(LocalClientNum_t localClientNum, const rectDef_s *rect, Material *material, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerBarHealthBack
==============
*/
void CG_DrawPlayerBarHealthBack(LocalClientNum_t localClientNum, const rectDef_s *rect, Material *material, vec4_t *color)
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
void CG_DrawPlayerLowHealthOverlay(cg_t *a1, char *a2, double localClientNum, LocalClientNum_t material, const rectDef_s *rect, Material *a6, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerDirectionalHitIndicator
==============
*/
void CG_DrawPlayerDirectionalHitIndicator(LocalClientNum_t localClientNum, const rectDef_s *rect, Material *material, vec4_t *color)
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
Material *CG_ObjectiveIcon(LocalClientNum_t localClientNum, const objective_t *objective, int type, ObjectIconType compassMapType, int isClientObjective)
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
const char *CG_GetWeaponUseString(LocalClientNum_t localClientNum, const char **secondaryString, char *fullWeaponName, unsigned int maxStringLen)
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
void CG_DrawCursorhint(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float fontscale, vec4_t *color, int textStyle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawHoldBreathHint
==============
*/
void CG_DrawHoldBreathHint(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float fontscale, int textStyle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawHoldBreathZoomHint
==============
*/
void CG_DrawHoldBreathZoomHint(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float fontscale, int textStyle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawAirburstMarkHint
==============
*/
void CG_DrawAirburstMarkHint(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float fontscale, int textStyle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawRCBombHints
==============
*/
void CG_DrawRCBombHints(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float fontscale, int textStyle, int hintType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawGuidedMissileBoostHint
==============
*/
void CG_DrawGuidedMissileBoostHint(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float fontscale, int textStyle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawGuidedMissileDetonateHint
==============
*/
void CG_DrawGuidedMissileDetonateHint(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float fontscale, int textStyle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawRemoteMissileSteerHint
==============
*/
void CG_DrawRemoteMissileSteerHint(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float fontscale, int textStyle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawRemoteMissileBoostHint
==============
*/
void CG_DrawRemoteMissileBoostHint(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float fontscale, int textStyle)
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
void CG_DrawGuidedMissileInfo(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float fontscale, int textStyle, eGuidedMissileInfo infoType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawTurretPlaceHint
==============
*/
void CG_DrawTurretPlaceHint(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float fontscale, const vec4_t *color, int textStyle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawMantleHint
==============
*/
void CG_DrawMantleHint(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float fontscale, const vec4_t *color, int textStyle)
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
void CG_DrawInvalidCmdHint(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float fontscale, vec4_t *color, int textStyle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawTalkerNum
==============
*/
void CG_DrawTalkerNum(LocalClientNum_t localClientNum, const int num, rectDef_s *rect, Font_s *font, vec4_t *color, float textScale, int style)
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
void draw_tank_turret_component(LocalClientNum_t localClientNum, const rectDef_s *rect, Material *material, const vec4_t *color, e_tank_hud_component component)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawWarMomentumProgress
==============
*/
void CG_DrawWarMomentumProgress(LocalClientNum_t localClientNum, const rectDef_s *rect, vec4_t *color, Material *material, int ownerDraw)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawWarMomentumMultiplier
==============
*/
void CG_DrawWarMomentumMultiplier(LocalClientNum_t localClientNum, const rectDef_s *rect, vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawWarMomentumMultiplierDetail
==============
*/
void CG_DrawWarMomentumMultiplierDetail(LocalClientNum_t localClientNum, const rectDef_s *rect, vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawWarMomentumMultiplierBlitzkrieg
==============
*/
void CG_DrawWarMomentumMultiplierBlitzkrieg(LocalClientNum_t localClientNum, const rectDef_s *rect, vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawWarText
==============
*/
void CG_DrawWarText(const cg_t *cgameGlob, rectDef_s *rect, Font_s *font, float fontscale, vec4_t *color, int textStyle, float text_x, float text_y)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawWristWatch
==============
*/
void CG_DrawWristWatch(LocalClientNum_t localClientNum, const rectDef_s *parentRect, const rectDef_s *rect, Material *material, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawAirburstDistance
==============
*/
void DrawAirburstDistance(unsigned int distance, LocalClientNum_t localClientNum, const rectDef_s *rect, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawAirburstCurrentDistance
==============
*/
void CG_DrawAirburstCurrentDistance(LocalClientNum_t localClientNum, const rectDef_s *rect, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawAirburstMarkDistance
==============
*/
void CG_DrawAirburstMarkDistance(LocalClientNum_t localClientNum, const rectDef_s *rect, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawAirburstMarkTimer
==============
*/
void CG_DrawAirburstMarkTimer(LocalClientNum_t localClientNum, const rectDef_s *rect, Material *material, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawDemoControls
==============
*/
void CG_DrawDemoControls(LocalClientNum_t localClientNum, const rectDef_s *rect, Material *material, vec4_t *color)
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
void CG_DrawTarget(LocalClientNum_t localClientNum, const vec2_t *screenPos, float targetSize, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerTargetHighlights
==============
*/
void CG_DrawPlayerTargetHighlights(LocalClientNum_t localClientNum, const rectDef_s *rect, Material *material, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerTargetHighlightsLineOfSight
==============
*/
void CG_DrawPlayerTargetHighlightsLineOfSight(LocalClientNum_t localClientNum, const rectDef_s *rect, Material *material, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerTargetHighlightsFriendly
==============
*/
void CG_DrawPlayerTargetHighlightsFriendly(LocalClientNum_t localClientNum, const rectDef_s *rect, Material *material, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawTargetHighlightsForEntity
==============
*/
void CG_DrawTargetHighlightsForEntity(LocalClientNum_t localClientNum, cg_t *cgameGlob, centity_t *cent, const rectDef_s *rect, Material *material, vec4_t *color, TargetHighlightParam *params)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawVehicleTargetHighlights
==============
*/
void CG_DrawVehicleTargetHighlights(TargetHighlightParam *a1, LocalClientNum_t localClientNum, const rectDef_s *rect, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawTurretTargetHighlights
==============
*/
void CG_DrawTurretTargetHighlights(TargetHighlightParam *a1, LocalClientNum_t localClientNum, const rectDef_s *rect, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawDogTargetHighlights
==============
*/
void CG_DrawDogTargetHighlights(TargetHighlightParam *a1, LocalClientNum_t localClientNum, const rectDef_s *rect, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawTargetHighlights
==============
*/
void CG_DrawTargetHighlights(LocalClientNum_t localClientNum, const rectDef_s *rect, Material *material, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawTargetHighlightsFriendly
==============
*/
void CG_DrawTargetHighlightsFriendly(LocalClientNum_t localClientNum, const rectDef_s *rect, Material *material, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawGuidedMissileFuel
==============
*/
void CG_DrawGuidedMissileFuel(LocalClientNum_t localClientNum, const rectDef_s *rect, Material *material, vec4_t *color)
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
void CG_OwnerDraw(double localClientNum, LocalClientNum_t a2, rectDef_s parentRect, float x, float y, float w, float h, int horzAlign, int vertAlign, int ownerDraw, int ownerDrawFlags, vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_OwnerDrawText
==============
*/
void CG_OwnerDrawText(Material *a1, LocalClientNum_t localClientNum, rectDef_s parentRect, float x, float y, float w, float h, int horzAlign, int vertAlign, float text_x, float text_y, int ownerDraw, int ownerDrawFlags, int align, Font_s *font, float scale, vec4_t *color, Material *material, int textStyle, int textAlignMode, itemDef_s *item, const char *text)
{
	UNIMPLEMENTED(__FUNCTION__);
}

