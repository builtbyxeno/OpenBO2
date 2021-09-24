#include "types.h"

/*
==============
IsOffHandDisplayVisible
==============
*/
bool IsOffHandDisplayVisible(LocalClientNum_t localClientNum, const cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CalcOffHandAmmo
==============
*/
int CalcOffHandAmmo(const playerState_s *predictedPlayerState, int weaponType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
OffHandFlash
==============
*/
void OffHandFlash(const cg_t *cgameGlob, const vec4_t *base_color, vec4_t *out_color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawOffHandHighlight
==============
*/
void CG_DrawOffHandHighlight(char *a1, LocalClientNum_t localClientNum, const rectDef_s *rect, const vec4_t *color, Material *material, OffhandSlot weaponType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawOffHandAmmo
==============
*/
void CG_DrawOffHandAmmo(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float scale, const vec4_t *color, int textStyle, OffhandSlot weaponType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawOffHandName
==============
*/
void CG_DrawOffHandName(LocalClientNum_t localClientNum, const rectDef_s *rect, Font_s *font, float scale, const vec4_t *color, int textStyle, OffhandSlot weaponType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PrepOffHand
==============
*/
void CG_PrepOffHand(LocalClientNum_t localClientNum, const entityState_s *ent, Weapon weapon, bool isPlayerView)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UseOffHand
==============
*/
void CG_UseOffHand(LocalClientNum_t localClientNum, const centity_t *cent, Weapon weapon, bool isPlayerView)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetEquippedOffHand
==============
*/
void CG_SetEquippedOffHand(LocalClientNum_t localClientNum, Weapon offHandWeapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawOffHandIcon
==============
*/
void CG_DrawOffHandIcon(LocalClientNum_t localClientNum, const rectDef_s *rect, const vec4_t *color, Material *material, OffhandSlot weaponType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SwitchOffHandCmd
==============
*/
void CG_SwitchOffHandCmd(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

