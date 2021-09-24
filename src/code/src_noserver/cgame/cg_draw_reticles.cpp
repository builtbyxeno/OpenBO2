#include "types.h"

/*
==============
CG_CalcCrosshairPosition
==============
*/
void CG_CalcCrosshairPosition(const cg_t *cgameGlob, float *x, float *y)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetWeapReticleZoom
==============
*/
char CG_GetWeapReticleZoom(const cg_t *cgameGlob, float *zoom)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawFrameOverlay
==============
*/
void CG_DrawFrameOverlay(float innerLeft, float innerRight, float innerTop, float innerBottom, const vec4_t *color, Material *material, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawNightVisionOverlay
==============
*/
void CG_DrawNightVisionOverlay(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UsingLowResViewPort
==============
*/
bool CG_UsingLowResViewPort(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_UpdateScissorViewport
==============
*/
void CG_UpdateScissorViewport(refdef_t *refdef, vec2_t *drawPos, vec2_t *drawSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawAdsOverlay
==============
*/
void CG_DrawAdsOverlay(LocalClientNum_t localClientNum, Weapon weapon, const vec4_t *color, const vec2_t *crosshairPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawWeapReticle
==============
*/
void CG_DrawWeapReticle(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalcCrosshairColor
==============
*/
void CG_CalcCrosshairColor(const LocalClientNum_t localClientNum, float alpha, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawTurretCrossHair
==============
*/
void CG_DrawTurretCrossHair(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetVehicleCrossHairAlpha
==============
*/
float CG_GetVehicleCrossHairAlpha(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ShouldShowCrosshairOnVehicle
==============
*/
bool ShouldShowCrosshairOnVehicle(const cg_t *cgameGlob, const WeaponDef *weapDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawVehicleCrossHair
==============
*/
bool CG_DrawVehicleCrossHair(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AllowedToDrawCrosshair
==============
*/
bool AllowedToDrawCrosshair(LocalClientNum_t localClientNum, const playerState_s *predictedPlayerState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawAdsAimIndicator
==============
*/
void CG_DrawAdsAimIndicator(LocalClientNum_t localClientNum, const WeaponDef *weapDef, const vec4_t *color, float centerX, float centerY, float transScale)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_TransitionToAds
==============
*/
void CG_TransitionToAds(const cg_t *cgameGlob, const WeaponDef *weapDef, float posLerp, float *transScale, float *transShift)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawReticleCenter
==============
*/
bool CG_DrawReticleCenter(LocalClientNum_t localClientNum, const Weapon weapon, const vec4_t *color, float centerX, float centerY, float centerW, float transScale)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CalcReticleSpread
==============
*/
void CG_CalcReticleSpread(const cg_t *cgameGlob, const Weapon weapon, const vec2_t *drawSize, float transScale, vec2_t *spread)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalcReticleColor
==============
*/
void CG_CalcReticleColor(LocalClientNum_t localClientNum, const vec4_t *baseColor, float alpha, float aimSpreadScale, vec4_t *reticleColor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawReticleSides
==============
*/
void CG_DrawReticleSides(LocalClientNum_t localClientNum, Weapon weapon, const vec4_t *baseColor, float centerX, float centerY, float centerW, float transScale)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ShouldDrawCrosshair
==============
*/
bool ShouldDrawCrosshair(const cg_t *cgameGlob, const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawCrosshair
==============
*/
bool CG_DrawCrosshair(unsigned int a1, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

