#include "types.h"

/*
==============
G_RegisterMissileDvars
==============
*/
void G_RegisterMissileDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IsZombiesValuableItem
==============
*/
BOOL IsZombiesValuableItem(const WeaponDef *weapDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_IsClientControlledMissile
==============
*/
BOOL G_IsClientControlledMissile(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IsMissileClientControlled
==============
*/
int IsMissileClientControlled(const gentity_t *missile)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_ClearMissileClientControlled
==============
*/
int G_ClearMissileClientControlled(const gentity_t *missile)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MissileLandAngles
==============
*/
void MissileLandAngles(gentity_t *ent, trace_t *trace, vec3_t *vAngles, int bForceAlign, int bKeepSpeed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MissileLandAnglesFlat
==============
*/
void MissileLandAnglesFlat(gentity_t *ent, trace_t *trace, vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MissileLandAnglesFlatMaintainingDirection
==============
*/
void MissileLandAnglesFlatMaintainingDirection(gentity_t *ent, trace_t *trace, vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CheckCrumpleMissile
==============
*/
int CheckCrumpleMissile(gentity_t *ent, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CheckGrenadeDanger
==============
*/
void CheckGrenadeDanger(gentity_t *grenadeEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
skip_horses
==============
*/
BOOL skip_horses(int entnum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_MissileTrace
==============
*/
void G_MissileTrace(trace_t *results, const vec3_t *start, const vec3_t *end, int passEntityNum, int contentmask, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GrenadeBounceVelocity
==============
*/
char GrenadeBounceVelocity(const vec3_t *preBounceVelocity, float dot, const vec3_t *normal, int surfType, const WeaponDef *weapDef, trajectory_t *pos, float *rollSlideSpeed, vec3_t *rollSlideDir, bool isDud)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GrenadeDud
==============
*/
bool GrenadeDud(gentity_t *ent, const WeaponDef *weapDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
JavelinProjectile
==============
*/
bool JavelinProjectile(gentity_t *ent, const WeaponDef *weapDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
JavelinDud
==============
*/
bool JavelinDud(gentity_t *ent, const WeaponDef *weapDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetSplashMethodOfDeath
==============
*/
int GetSplashMethodOfDeath(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
isDud
==============
*/
bool isDud(gentity_t *ent, const WeaponDef *weapDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_UnlinkPlayerToRocket
==============
*/
void G_UnlinkPlayerToRocket(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AttachMissileToEntity
==============
*/
void AttachMissileToEntity(gentity_t *missile, int entnum, int boneName, int hitLocation, vec3_t *velocity)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
StickMissile
==============
*/
int StickMissile(gentity_t *ent, gentity_t *other, const WeaponDef *weapDef, trace_t *trace, hitLocation_t hitLocation, vec3_t *velocity)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
isBounceProjectile
==============
*/
bool isBounceProjectile(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
createRetrieveableProjectile
==============
*/
void createRetrieveableProjectile(gentity_t *ent, gentity_t *other, const WeaponDef *weapDef, trace_t *trace, hitLocation_t hitLocation, vec3_t *dir, vec3_t *endpos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GrenadeCanApplyImpactDamage
==============
*/
bool GrenadeCanApplyImpactDamage(gentity_t *missile, gentity_t *hitEnt, const WeaponDef *weapDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_TimedObjectThink
==============
*/
void G_TimedObjectThink(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetSurfaceType
==============
*/
int GetSurfaceType(gentity_t *ent, bool inWater)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Missile_PenetrateGlass
==============
*/
void Missile_PenetrateGlass(trace_t *results, gentity_t *ent, const vec3_t *start, const vec3_t *end, int damage, bool predicted)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawMissileDebug
==============
*/
void DrawMissileDebug(vec3_t *start, vec3_t *end)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TRACK_missile_attractors
==============
*/
void TRACK_missile_attractors()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Missile_InitAttractors
==============
*/
void Missile_InitAttractors()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Missile_FreeAttractorRefs
==============
*/
void Missile_FreeAttractorRefs(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Missile_GetFreeAttractor
==============
*/
int Missile_GetFreeAttractor()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_MissileCreateAttractorEnt
==============
*/
void Scr_MissileCreateAttractorEnt()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_MissileCreateAttractorOrigin
==============
*/
void Scr_MissileCreateAttractorOrigin()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_MissileCreateRepulsorEnt
==============
*/
void Scr_MissileCreateRepulsorEnt()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_MissileCreateRepulsorOrigin
==============
*/
void Scr_MissileCreateRepulsorOrigin()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_MissileDeleteAttractor
==============
*/
void Scr_MissileDeleteAttractor()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Missile_ApplyAttractorsRepulsors
==============
*/
void Missile_ApplyAttractorsRepulsors(gentity_t *missile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RunMissile_Destabilize
==============
*/
void RunMissile_Destabilize(gentity_t *missile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RunMissile_BroadcastActorEvents
==============
*/
void RunMissile_BroadcastActorEvents(gentity_t *missile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IsMissileLockedOn
==============
*/
bool IsMissileLockedOn(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetTargetPosition
==============
*/
void GetTargetPosition(gentity_t *ent, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MissileVerticalSteerToTarget
==============
*/
void MissileVerticalSteerToTarget(gentity_t *ent, const vec2_t *toTargetHorzRelDir, float horzDistToTarg, float vertDistToTarg, float currentHorzSpeed, vec3_t *steer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MissileVerticalSteering
==============
*/
void MissileVerticalSteering(gentity_t *ent, const vec3_t *toTargetRelative, float currentHorzSpeed, vec3_t *steer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MissileIsReadyForSteering
==============
*/
bool MissileIsReadyForSteering(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DroneClimbExceededAngle
==============
*/
bool DroneClimbExceededAngle(gentity_t *ent, const vec3_t *targetPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DroneClimbExceededDistance
==============
*/
bool DroneClimbExceededDistance(gentity_t *ent, const vec3_t *targetPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DroneClimbOffset
==============
*/
void DroneClimbOffset(gentity_t *ent, vec3_t *targetPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DroneMaxDPS
==============
*/
float DroneMaxDPS(gentity_t *ent, bool impactAvoidance)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DroneRotateDir
==============
*/
float DroneRotateDir(gentity_t *ent, const vec3_t *currentDir, const vec3_t *targetDir, vec3_t *resultDir, float currentRoll, bool avoidImpact)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DroneRotateVelocity
==============
*/
void DroneRotateVelocity(gentity_t *ent, vec3_t *resultVel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DroneClimbCeiling
==============
*/
float DroneClimbCeiling(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DroneClimbIsAboveCeiling
==============
*/
bool DroneClimbIsAboveCeiling(gentity_t *ent, const vec3_t *targetPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DroneSteering
==============
*/
void DroneSteering(gentity_t *ent, const WeaponDef *weapDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
JavelinClimbExceededAngle
==============
*/
bool JavelinClimbExceededAngle(gentity_t *ent, const vec3_t *targetPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
JavelinClimbWithinDistance
==============
*/
bool JavelinClimbWithinDistance(gentity_t *ent, const vec3_t *targetPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
JavelinClimbOffset
==============
*/
void JavelinClimbOffset(gentity_t *ent, vec3_t *targetPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
JavelinMaxDPS
==============
*/
float JavelinMaxDPS(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
JavelinRotateDir
==============
*/
float JavelinRotateDir(gentity_t *ent, const vec3_t *currentDir, const vec3_t *targetDir, vec3_t *resultDir)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
JavelinRotateVelocity
==============
*/
void JavelinRotateVelocity(gentity_t *ent, const vec3_t *currentVel, const vec3_t *targetDir, vec3_t *resultVel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
JavelinClimbCeiling
==============
*/
float JavelinClimbCeiling(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
JavelinClimbIsAboveCeiling
==============
*/
bool JavelinClimbIsAboveCeiling(gentity_t *ent, const vec3_t *targetPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
JavelinSteering
==============
*/
void JavelinSteering(char *a1, gentity_t *ent, const WeaponDef *weapDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HeatSeekingSteering
==============
*/
void HeatSeekingSteering(gentity_t *ent, const WeaponDef *weapDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_MakeMissilePickupItem
==============
*/
void G_MakeMissilePickupItem(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PredictBounceMissile
==============
*/
void PredictBounceMissile(gentity_t *ent, trajectory_t *pos, trace_t *trace, int time, int velocityTime, vec3_t *origin, vec3_t *endpos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_PredictMissile
==============
*/
int G_PredictMissile(unsigned int a1, gentity_t *ent, int duration, vec3_t *vLandPos, int allowBounce, int *timeAtRest)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_InitGrenadeEntity
==============
*/
void G_InitGrenadeEntity(gentity_t *parent, gentity_t *grenade)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_InitGrenadeMovement
==============
*/
void G_InitGrenadeMovement(gentity_t *grenade, const vec3_t *start, const vec3_t *dir, int rotate, WeapRotateType rotateType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
InitGrenadeTimer
==============
*/
void InitGrenadeTimer(const gentity_t *parent, gentity_t *grenade, const WeaponDef *weapDef, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_FireGrenade
==============
*/
gentity_t *G_FireGrenade(gentity_t *parent, vec3_t *start, vec3_t *dir, Weapon grenadeWPID, unsigned __int8 grenModel, int rotate, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_SetMissileClientControlled
==============
*/
int G_SetMissileClientControlled(const gentity_t *missile)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BounceMissile
==============
*/
int BounceMissile(gentity_t *ent, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_LinkPlayerToRocket
==============
*/
void G_LinkPlayerToRocket(gentity_t *ent, gentity_t *player)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AttachBoltGrenade
==============
*/
void AttachBoltGrenade(gentity_t *ent, gentity_t *hitEnt, trace_t *trace, hitLocation_t hitLocation)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MissileImpact
==============
*/
void MissileImpact(gentity_t *ent, trace_t *trace, vec3_t *dir, vec3_t *endpos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_ExplodeMissile
==============
*/
void G_ExplodeMissile(unsigned int a1, float ent, gentity_t *a3)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RunMissile_CreateWaterSplash
==============
*/
void RunMissile_CreateWaterSplash(const gentity_t *missile, const vec3_t *hitPos, const trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MissileHorzSteerToTarget
==============
*/
void MissileHorzSteerToTarget(gentity_t *ent, const vec2_t *currentRight, const vec2_t *toTargetRelative, float currentHorzSpeed, vec3_t *steer, bool tvGuided)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MissileTrajectoryClientControlled
==============
*/
void MissileTrajectoryClientControlled(gentity_t *ent, vec3_t *result, gentity_t *owner)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TVMissileTrajectoryClientControlled
==============
*/
void TVMissileTrajectoryClientControlled(gentity_t *ent, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GuidedMissileSteering
==============
*/
void GuidedMissileSteering(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MissileTrajectory
==============
*/
void MissileTrajectory(gentity_t *ent, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CheckForMissileClientControlledDetonation
==============
*/
bool CheckForMissileClientControlledDetonation(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UpdateGuidedMissileFuelTime
==============
*/
bool UpdateGuidedMissileFuelTime(gentity_t *ent, bool initTimer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_RunMissileInternal
==============
*/
void G_RunMissileInternal(unsigned int a1, char *a2, gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_RunMissile
==============
*/
void G_RunMissile(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
InitRocketTimer
==============
*/
void InitRocketTimer(gentity_t *bolt, const WeaponDef *weapDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_FireRocket
==============
*/
gentity_t *G_FireRocket(gentity_t *parent, Weapon weapon, vec3_t *start, vec3_t *dir, const vec3_t *gunVel, gentity_t *target, const vec3_t *targetOffset)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_DropBomb
==============
*/
gentity_t *G_DropBomb(gentity_t *parent, Weapon weapon, vec3_t *start, vec3_t *dir, const vec3_t *gunVel, gentity_t *target, const vec3_t *targetOffset)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

