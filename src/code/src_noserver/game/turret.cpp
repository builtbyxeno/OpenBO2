#include "types.h"
#include "functions.h"

/*
==============
Turret_RegisterDvars
==============
*/
void Turret_RegisterDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_InitTurrets
==============
*/
void G_InitTurrets()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Turret_SetMinimapVisible
==============
*/
void Turret_SetMinimapVisible(gentity_t *self, int isVisible)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Fire_Lead
==============
*/
void Fire_Lead(gentity_t *ent, gentity_t *activator, int bUseAccuracy)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_shoot_internal
==============
*/
void turret_shoot_internal(gentity_t *self, gentity_t *other)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_UpdateSound
==============
*/
void turret_UpdateSound(gentity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_CalculateConvergenceAngularVelocity
==============
*/
void turret_CalculateConvergenceAngularVelocity(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Turret_ScanStart
==============
*/
void Turret_ScanStart(gentity_t *self, const WeaponDef *weapDef, float deltaYaw)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Turret_ScanStop
==============
*/
void Turret_ScanStop(gentity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Turret_ScanForEnemies
==============
*/
void Turret_ScanForEnemies(gentity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_UpdateTargetAngles
==============
*/
int turret_UpdateTargetAngles(gentity_t *self, const vec2_t *desiredAngles, int bManned)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
turret_IsFiring
==============
*/
BOOL turret_IsFiring(gentity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
turret_SetState
==============
*/
void turret_SetState(gentity_t *self, int state)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_ClearTargetEnt
==============
*/
void turret_ClearTargetEnt(gentity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_SetDefaultDropPitch
==============
*/
void turret_SetDefaultDropPitch(gentity_t *self, float pitch)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_SetScanningPitch
==============
*/
void turret_SetScanningPitch(gentity_t *self, float pitch)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_shoot
==============
*/
/*void turret_shoot(gentity_t *a1@<edx>, gentity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
turret_CanTargetPoint
==============
*/
int turret_CanTargetPoint(const gentity_t *self, const vec3_t *vPoint, vec3_t *vSource, vec2_t *localAngles)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Turret_PredictPosition
==============
*/
void Turret_PredictPosition(const gentity_t *ent, const playerState_s *ps, vec3_t *vPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_CanTargetSentient
==============
*/
/*int turret_CanTargetSentient@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
turret_aimat_vector_internal
==============
*/
void turret_aimat_vector_internal(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_aimat_vector
==============
*/
int turret_aimat_vector(gentity_t *self, vec3_t *origin, int bShoot, vec2_t *desiredAngles)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
turret_SetTargetEnt
==============
*/
void turret_SetTargetEnt(gentity_t *self, gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_aimat_Sentient_Internal
==============
*/
int turret_aimat_Sentient_Internal(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
turret_aimat_Sentient
==============
*/
int turret_aimat_Sentient(gentity_t *self, sentient_t *enemy, int bShoot, int missTime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
turret_aimat_Ent
==============
*/
int turret_aimat_Ent(gentity_t *self, gentity_t *ent, int bShoot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
turret_SightTrace
==============
*/
int turret_SightTrace(const vec3_t *start, const vec3_t *end, int passEnt1, int passEnt2, gentity_t *turret)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
turret_isTargetVisible
==============
*/
int turret_isTargetVisible(gentity_t *self, const gentity_t *target, float *distSqr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
turret_findBestKillstreakTarget
==============
*/
gentity_t *turret_findBestKillstreakTarget(gentity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
turret_findBestGroundKillstreakTarget
==============
*/
gentity_t *turret_findBestGroundKillstreakTarget(gentity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
turret_findBestTarget
==============
*/
sentient_t *turret_findBestTarget(gentity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
turret_target_sentry
==============
*/
void turret_target_sentry(gentity_t *self, TurretInfo *turretInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_target_killstreak
==============
*/
void turret_target_killstreak(gentity_t *self, TurretInfo *turretInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_think_auto_nonai
==============
*/
void turret_think_auto_nonai(gentity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_RestoreDefaultDropPitch
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
turret_UpdateOverheating
==============
*/
void turret_UpdateOverheating(gentity_t *self, gentity_t *owner)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_think
==============
*/
void turret_think(gentity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_controller
==============
*/
void turret_controller(const gentity_t *self, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_behind
==============
*/
int turret_behind(gentity_t *self, gentity_t *other)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_IsTurretUsable
==============
*/
/*BOOL G_IsTurretUsable@<eax>(gentity_t *a1@<edx>, gentity_t *a2@<ecx>, gentity_t *self, gentity_t *owner)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
G_DeactivateTurret
==============
*/
void G_DeactivateTurret(gentity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_find_max_angles
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
SP_turret
==============
*/
void SP_turret(gentity_t *self, SpawnVar *spawnVar)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Turret_SetTurretCarried
==============
*/
void Turret_SetTurretCarried(gentity_t *self, int carried)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Turret_SetTurretOwner
==============
*/
void Turret_SetTurretOwner(gentity_t *self, gentity_t *owner)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_PlayerTurretPositionAndBlend
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
turret_clientaim
==============
*/
void turret_clientaim(gentity_t *self, gentity_t *other)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_track
==============
*/
void turret_track(gentity_t *self, gentity_t *other)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_ClientStopUsingTurret
==============
*/
void G_ClientStopUsingTurret(gentity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_think_client
==============
*/
void turret_think_client(gentity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_think_init
==============
*/
void turret_think_init(gentity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_FreeTurret
==============
*/
void G_FreeTurret(gentity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
turret_use
==============
*/
void turret_use(gentity_t *self, gentity_t *owner)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Turret_ScrRemoteUse
==============
*/
void Turret_ScrRemoteUse(gentity_t *self, gentity_t *owner)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Turret_ScrStopRemoteUse
==============
*/
void Turret_ScrStopRemoteUse(gentity_t *self, gentity_t *owner)
{
	UNIMPLEMENTED(__FUNCTION__);
}

