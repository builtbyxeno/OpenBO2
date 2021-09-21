#include "types.h"
#include "functions.h"

/*
==============
CG_Obituary
==============
*/
void CG_Obituary(LocalClientNum_t localClientNum, const entityState_s *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RemoteMissileBoostEvent
==============
*/
void RemoteMissileBoostEvent(LocalClientNum_t localClientNum, centity_t *cent, int eventParm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ObituaryRevive
==============
*/
void CG_ObituaryRevive(LocalClientNum_t localClientNum, const entityState_s *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DirectionalHitIndicator
==============
*/
void CG_DirectionalHitIndicator(LocalClientNum_t localClientNum, const entityState_s *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ItemPickup
==============
*/
void CG_ItemPickup(LocalClientNum_t localClientNum, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetWetness
==============
*/
void CG_SetWetness(LocalClientNum_t localClientNum, int entNum, float wetness, int invert)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ExplosionEvent
==============
*/
void CG_ExplosionEvent(LocalClientNum_t localClientNum, centity_t *eventEnt, const vec3_t *origin, const float damageInner, const float damageOuter, float radius, int mod, const char *weaponName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ProjectileExplosionEvent
==============
*/
void CG_ProjectileExplosionEvent(LocalClientNum_t localClientNum, centity_t *cent, Weapon weapon, const vec3_t *position, int mod)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetBoneIndex
==============
*/
const DObj *CG_GetBoneIndex(LocalClientNum_t localClientNum, const int dobjHandle, unsigned int boneName, unsigned __int8 *boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_PlayBoltedEffect
==============
*/
unsigned int CG_PlayBoltedEffect(LocalClientNum_t localClientNum, const FxEffectDef *fxDef, int dobjHandle, unsigned int boneName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_PlayBoltedEffectRelative
==============
*/
unsigned int CG_PlayBoltedEffectRelative(LocalClientNum_t localClientNum, const FxEffectDef *fxDef, int dobjHandle, unsigned int boneName, const vec3_t *offset, const vec3_t *offsetaxis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_PlayFx
==============
*/
void CG_PlayFx(LocalClientNum_t localClientNum, centity_t *cent, const vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PlayFxOnTag
==============
*/
void CG_PlayFxOnTag(LocalClientNum_t localClientNum, centity_t *cent, int eventParm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetInvalidCmdHint
==============
*/
void CG_SetInvalidCmdHint(cg_t *cgameGlob, InvalidCmdHintType hintType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetInvalidStanceHint
==============
*/
void CG_SetInvalidStanceHint(cg_t *cgameGlob, invalid_cmd_hint_t type)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_StopWeaponSound
==============
*/
void CG_StopWeaponSound(const LocalClientNum_t localClientNum, bool isPlayerView, const WeaponDef *weaponDef, const int entitynum, weaponstate_t weaponstate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_IsSoundEventLouder
==============
*/
bool CG_IsSoundEventLouder(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DoJumpEvent
==============
*/
void CG_DoJumpEvent(LocalClientNum_t localClientNum, centity_t *cent, bool isPlayerView, int surfaceType, bool quiet)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DoLandEvent
==============
*/
void CG_DoLandEvent(LocalClientNum_t localClientNum, centity_t *cent, bool isPlayerView, int surfaceType, bool quiet, bool damagePlayer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GibEvent
==============
*/
void CG_GibEvent(LocalClientNum_t localClientNum, centity_t *cent, unsigned int eventParm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GrabWeapon
==============
*/
void __cdecl CG_GrabWeapon(LocalClientNum_t localClientNum, int entityNum, int event, const Weapon weapon, bool isPlayerView)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PhysLaunch
==============
*/
void CG_PhysLaunch(LocalClientNum_t localClientNum, centity_t *cent, const entityState_s *es)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CheckIfDualWieldEmpty
==============
*/
bool CG_CheckIfDualWieldEmpty(playerState_s *ps, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_EntityEvent
==============
*/
void CG_EntityEvent(unsigned int a1, int a2, LocalClientNum_t localClientNum, centity_t *cent, int event)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CheckEvents
==============
*/
void CG_CheckEvents(char *a1, LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CheckEntEvents
==============
*/
void CG_CheckEntEvents(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

