#include "types.h"
#include "functions.h"

/*
==============
CG_AmmoCounterRegisterDvars
==============
*/
void CG_AmmoCounterRegisterDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetBaseRectPos
==============
*/
void GetBaseRectPos(LocalClientNum_t localClientNum, const rectDef_s *rect, vec2_t *base)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetWeaponAltIndex
==============
*/
Weapon GetWeaponAltIndex(const cg_t *cgameGlob, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
AmmoColor
==============
*/
void AmmoColor(cg_t *cgameGlob, vec3_t *color, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AmmoCounterFadeAlpha
==============
*/
float AmmoCounterFadeAlpha(LocalClientNum_t localClientNum, cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DrawClipAmmoMagazine
==============
*/
void DrawClipAmmoMagazine(cg_t *cgameGlob, const vec2_t *base, Weapon weapon, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawClipAmmoShortMagazine
==============
*/
void DrawClipAmmoShortMagazine(cg_t *cgameGlob, const vec2_t *base, Weapon weapon, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawClipAmmoShotgunShells
==============
*/
void DrawClipAmmoShotgunShells(cg_t *cgameGlob, const vec2_t *base, Weapon weapon, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawClipAmmoRockets
==============
*/
void DrawClipAmmoRockets(cg_t *cgameGlob, const vec2_t *base, Weapon weapon, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawClipAmmoBeltfed
==============
*/
void DrawClipAmmoBeltfed(cg_t *cgameGlob, const vec2_t *base, Weapon weapon, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawClipAmmo
==============
*/
void DrawClipAmmo(const vec2_t *a1, char *a2, cg_t *cgameGlob, const vec2_t *base, Weapon weapon, const WeaponDef *weapDef, const WeaponVariantDef *weapVarDef, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawAmmoCounterSingle
==============
*/
void CG_DrawAmmoCounterSingle(LocalClientNum_t localClientNum, rectDef_s *rect, vec4_t *color, bool last)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerWeaponAmmoStock
==============
*/
void CG_DrawPlayerWeaponAmmoStock(char *a1, LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float scale, vec4_t *color, Material *material, int textStyle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawFuelTankPercentage
==============
*/
void CG_DrawFuelTankPercentage(char *a1, LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float scale, vec4_t *color, Material *material, int textStyle, float text_x, float text_y)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerWeaponAmmoClip
==============
*/
void CG_DrawPlayerWeaponAmmoClip(char *a1, LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float scale, vec4_t *color, Material *material, int textStyle, float text_x, float text_y, int textAlignMode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerWeaponAmmoClipDualWield
==============
*/
void CG_DrawPlayerWeaponAmmoClipDualWield(char *a1, LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float scale, vec4_t *color, Material *material, int textStyle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DpadIconDims
==============
*/
void DpadIconDims(const rectDef_s *rect, unsigned int slotIdx, weaponIconRatioType_t dpadIconRatio, float *x, float *y, float *w, float *h)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DpadTextPos
==============
*/
void DpadTextPos(LocalClientNum_t localClientNum, const rectDef_s *rect, unsigned int slotIdx, weaponIconRatioType_t dpadIconRatio, float *x, float *y)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ActionSlotIsActive
==============
*/
bool ActionSlotIsActive(LocalClientNum_t localClientNum, unsigned int slotIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DpadFadeAlpha
==============
*/
float DpadFadeAlpha(LocalClientNum_t localClientNum, cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetHudAlphaDPad
==============
*/
double CG_GetHudAlphaDPad(cg_t *a1, LocalClientNum_t a2, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetHudAlphaAmmoCounter
==============
*/
double CG_GetHudAlphaAmmoCounter(cg_t *a1, LocalClientNum_t a2, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_ActionSlotIsUsable
==============
*/
char CG_ActionSlotIsUsable(const LocalClientNum_t localClientNum, unsigned int slotIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawPlayerActionSlotDpad
==============
*/
void CG_DrawPlayerActionSlotDpad(LocalClientNum_t localClientNum, const rectDef_s *rect, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerActionSlotCarousel
==============
*/
void CG_DrawPlayerActionSlotCarousel(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float scale, vec4_t color, int textStyle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerActionSlotBack
==============
*/
void CG_DrawPlayerActionSlotBack(LocalClientNum_t localClientNum, const rectDef_s *rect, unsigned int slotIdx, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerActionSlotArrow
==============
*/
void CG_DrawPlayerActionSlotArrow(LocalClientNum_t localClientNum, const rectDef_s *rect, unsigned int slotIdx, vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerActionSlot
==============
*/
void CG_DrawPlayerActionSlot(LocalClientNum_t localClientNum, const rectDef_s *rect, unsigned int slotIdx, vec4_t *color, Font_s *textFont, float textScale, int textStyle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerWeaponBackground
==============
*/
void CG_DrawPlayerWeaponBackground(LocalClientNum_t localClientNum, const rectDef_s *rect, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerWeaponAmmoClipGraphic
==============
*/
void CG_DrawPlayerWeaponAmmoClipGraphic(cg_t *a1, LocalClientNum_t a2, LocalClientNum_t localClientNum, const rectDef_s *rect, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerWeaponAmmoClipGraphicDualWield
==============
*/
void CG_DrawPlayerWeaponAmmoClipGraphicDualWield(cg_t *a1, LocalClientNum_t a2, LocalClientNum_t localClientNum, const rectDef_s *rect, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawStretchPicGun
==============
*/
void DrawStretchPicGun(const ScreenPlacement *scrPlace, const rectDef_s *rect, const vec4_t *color, Material *material, weaponIconRatioType_t ratio)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerWeaponIcon
==============
*/
void CG_DrawPlayerWeaponIcon(cg_t *a1, LocalClientNum_t a2, LocalClientNum_t localClientNum, const rectDef_s *rect, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawPlayerWeaponLowAmmoWarning
==============
*/
void CG_DrawPlayerWeaponLowAmmoWarning(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float textScale, int textStyle, float text_x, float text_y, int textAlignMode, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

