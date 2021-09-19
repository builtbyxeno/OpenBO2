#include "types.h"
#include "functions.h"

/*
==============
BG_RegisterDvars
==============
*/
void BG_RegisterDvars(int a1, dvarType_t a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetFallDamageMaxHeight
==============
*/
double BG_GetFallDamageMaxHeight()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetFallDamageMinHeight
==============
*/
double BG_GetFallDamageMinHeight()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetSprintSpeedScale
==============
*/
double BG_GetSprintSpeedScale()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetSprintUnlimited
==============
*/
bool BG_GetSprintUnlimited()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetSprintMinTime
==============
*/
double BG_GetSprintMinTime()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetSprintStrafeSpeedScale
==============
*/
double BG_GetSprintStrafeSpeedScale()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetFriction
==============
*/
double BG_GetFriction()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetEntityTypeName
==============
*/
char *BG_GetEntityTypeName(const int eType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_FindItem
==============
*/
Weapon G_FindItem(const char *pickupName)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
HaveRoomForAmmo
==============
*/
char HaveRoomForAmmo(const playerState_s *ps, const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_PlayerCanPickUpWeaponType
==============
*/
bool BG_PlayerCanPickUpWeaponType(const WeaponDef *weapDef, const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
WeaponEntCanBeGrabbed
==============
*/
bool WeaponEntCanBeGrabbed(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_CanItemBeGrabbed
==============
*/
BOOL BG_CanItemBeGrabbed(const entityState_s *ent, const playerState_s *ps, int touched)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_PlayerHasRoomForEntAllAmmoTypes
==============
*/
BOOL BG_PlayerHasRoomForEntAllAmmoTypes(const entityState_s *ent, const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_EvaluateTrajectoryInternal
==============
*/
/*void BG_EvaluateTrajectoryInternal(float a1@<ebx>, const trajectory_t *tr, int atTime, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
BG_EvaluateTrajectoryDelta
==============
*/
/*void BG_EvaluateTrajectoryDelta(float a1@<edi>, const trajectory_t *tr, int atTime, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
BG_ValidateOrigin
==============
*/
bool BG_ValidateOrigin(const vec3_t *pos, unsigned int xyBits, unsigned int zBits, const vec3_t *mapCenter)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_ValidateOrigin
==============
*/
bool BG_ValidateOrigin(int a1, unsigned int a2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_ValidateZOriginValue
==============
*/
bool BG_ValidateZOriginValue(const float val, const float mapCenterValue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_PlayerToEntitySetPitchAngles
==============
*/
void BG_PlayerToEntitySetPitchAngles(playerState_s *ps, entityState_s *s)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_PlayerToEntitySetTrajectory
==============
*/
void BG_PlayerToEntitySetTrajectory(playerState_s *ps, entityState_s *s, int snap)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetPlayerViewDirection
==============
*/
void BG_GetPlayerViewDirection(const playerState_s *ps, vec3_t *forward, vec3_t *right, vec3_t *up)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetPlayerGunDirection
==============
*/
void BG_GetPlayerGunDirection(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_ApplyLinkAngles
==============
*/
void BG_ApplyLinkAngles(const vec3_t *linkAngles, vec3_t *viewangles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_LerpFontScale
==============
*/
void BG_LerpFontScale(const hudelem_s *elem, int time, float *toScale)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_LerpHudColors
==============
*/
void BG_LerpHudColors(const hudelem_s *elem, int time, hudelem_color_t *toColor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_LoadShellShockDvars
==============
*/
int BG_LoadShellShockDvars(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_SetShellShockParmsFromDvars
==============
*/
void BG_SetShellShockParmsFromDvars(shellshock_parms_t *parms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_SaveShellShockDvars
==============
*/
int BG_SaveShellShockDvars(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetShellshockParms
==============
*/
shellshock_parms_t *BG_GetShellshockParms(const int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_IsShellshockAnim
==============
*/
BOOL BG_IsShellshockAnim(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_CreateXAnim
==============
*/
void BG_CreateXAnim(XAnim_s *anims, unsigned int animIndex, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_CheckThread
==============
*/
void BG_CheckThread()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetMaxSprintTime
==============
*/
int BG_GetMaxSprintTime(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_ClipMoveToDobj
==============
*/
bool BG_ClipMoveToDobj(const entityState_s *es)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetFriendlyFireStatus
==============
*/
int BG_GetFriendlyFireStatus()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_DisplayName
==============
*/
const char *BG_DisplayName(const clientInfo_t *ci, int type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UpdateClientControlledMissile
==============
*/
void BG_UpdateClientControlledMissile(vec3_t *angles, const usercmd_s *cmd, int msec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_ShieldHitEncode
==============
*/
unsigned __int8 BG_ShieldHitEncode(const vec3_t *hitPos, bool fromTheFront)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_ShieldHitDecode
==============
*/
void BG_ShieldHitDecode(unsigned int encoded, vec3_t *result, bool *resultHitFront)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_ShieldHitDecode
==============
*/
void BG_ShieldHitDecode(unsigned int encoded, int *segY, int *segZ, bool *resultHitFront)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_ClipCameraToHeliPatch
==============
*/
void BG_ClipCameraToHeliPatch(vec3_t *origin, vec3_t *oldpos, vec3_t *velocity, vec3_t *breachPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_PlayerTouchesItem
==============
*/
BOOL BG_PlayerTouchesItem(const playerState_s *ps, const entityState_s *item, int atTime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_AddPredictableEventToPlayerstate
==============
*/
void BG_AddPredictableEventToPlayerstate(int newEvent, unsigned int eventParm, playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_AddUnpredictableEventToPlayerstate
==============
*/
void BG_AddUnpredictableEventToPlayerstate(int newEvent, unsigned int eventParm, playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_AddEntityStateEvent
==============
*/
void BG_AddEntityStateEvent(int newEvent, unsigned int eventParm, entityState_s *es, const int eventTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_AddSentinelEventToEntityState
==============
*/
void BG_AddSentinelEventToEntityState(entityState_s *es, const int eventTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_PlayerToEntityProcessEvents_Internal
==============
*/
void BG_PlayerToEntityProcessEvents_Internal(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_PlayerToEntityProcessEvents
==============
*/
void BG_PlayerToEntityProcessEvents(playerState_s *ps, entityState_s *s, unsigned __int8 handler)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_PlayerToEntitySetMisc
==============
*/
void BG_PlayerToEntitySetMisc(playerState_s *ps, entityState_s *s)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_PlayerStateToEntityState
==============
*/
void BG_PlayerStateToEntityState(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_CheckProne
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
BG_GetPlayerViewOrigin
==============
*/
void BG_GetPlayerViewOrigin(const playerState_s *ps, vec3_t *origin, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

