#include "types.h"
#include "functions.h"

/*
==============
CG_VehicleComputeTurretRotationState
==============
*/
cgVehicleTurretLoopState_t CG_VehicleComputeTurretRotationState(float angularVel, cgVehicle_t *vehicle)
{
	UNIMPLEMENTED(__FUNCTION__);
	cgVehicleTurretLoopState_t tmp;
	return tmp;
}

/*
==============
CG_Vehicle_UpdateTurretRotateSounds
==============
*/
void CG_Vehicle_UpdateTurretRotateSounds(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ShouldLockTurretToPlayerView
==============
*/
bool CG_ShouldLockTurretToPlayerView(const centity_t *cent, const VehicleDef *info, const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_UpdateVehicleSoundOrigins
==============
*/
void CG_UpdateVehicleSoundOrigins(centity_t *cent, const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_InitAntenna
==============
*/
void CG_InitAntenna(centity_t *cent, const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetSoundInfoForVehicle
==============
*/
int GetSoundInfoForVehicle(LocalClientNum_t localClientNum, const centity_t *cent, float *slideRate)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CrossFadeVehicleMaterialEffects
==============
*/
void CG_CrossFadeVehicleMaterialEffects(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateWheeledSurfaceSounds
==============
*/
void CG_UpdateWheeledSurfaceSounds(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateSurfaceSounds
==============
*/
void CG_UpdateSurfaceSounds(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateVehicleNotifies
==============
*/
void CG_UpdateVehicleNotifies(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_VehicleOccupiedByPlayer
==============
*/
char CG_VehicleOccupiedByPlayer(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Vehicle_GetSoundOriginForGun
==============
*/
void CG_Vehicle_GetSoundOriginForGun(centity_t *cent, int gunIndex, vec3_t *sndOrigin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CircleLineIntersect
==============
*/
bool CircleLineIntersect(vec3_t *p1, vec3_t *p2, vec3_t *center, float radius, float *t0, float *t1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Vehicle_GetWheelBone
==============
*/
bool CG_Vehicle_GetWheelBone(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Vehicle_GetBoneOrigin
==============
*/
void CG_Vehicle_GetBoneOrigin(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Vehicle_GetVehicleDefIndex
==============
*/
int CG_Vehicle_GetVehicleDefIndex(const centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Vehicle_GetVehicleDef
==============
*/
const VehicleDef *CG_Vehicle_GetVehicleDef(const centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_Vehicle_IsDefRemoteControl
==============
*/
bool CG_Vehicle_IsDefRemoteControl(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Vehicle_IsRemoteControl
==============
*/
bool CG_Vehicle_IsRemoteControl(const centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Vehicle_IsGunnerTurretFiring
==============
*/
BOOL CG_Vehicle_IsGunnerTurretFiring(const centity_t *cent, int gunnerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Vehicle_IsGunFiring
==============
*/
bool CG_Vehicle_IsGunFiring(const centity_t *cent, int gunIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Vehicle_RegisterMaterials
==============
*/
void CG_Vehicle_RegisterMaterials()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Vehicle_UpdateEngine
==============
*/
void CG_Vehicle_UpdateEngine(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Vehicle_UpdateMaterialTime
==============
*/
void CG_Vehicle_UpdateMaterialTime(centity_t *cent, int dt, float speed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_VehicleDebug
==============
*/
void CG_VehicleDebug(centity_t *cent, const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Vehicle_UpdateAntennas
==============
*/
void CG_Vehicle_UpdateAntennas(LocalClientNum_t localClientNum, const DObj *obj, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Vehicle_UpdateMinigun
==============
*/
void CG_Vehicle_UpdateMinigun(LocalClientNum_t localClientNum, const DObj *obj, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AllocClientVehicle
==============
*/
void CG_AllocClientVehicle(LocalClientNum_t localClientNum, const DObj *obj, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateVehicleEngineSounds
==============
*/
void CG_UpdateVehicleEngineSounds(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateVehicleTags
==============
*/
void CG_UpdateVehicleTags(centity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_TriggerLoopingVehFire
==============
*/
void CG_TriggerLoopingVehFire(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateLoopingVehicleFireSounds
==============
*/
void CG_UpdateLoopingVehicleFireSounds(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateDriveBySounds
==============
*/
void CG_UpdateDriveBySounds(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateVehicleSounds
==============
*/
void CG_UpdateVehicleSounds(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Vehicle_Init
==============
*/
void CG_Vehicle_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Vehicle_SetupCollisionCache
==============
*/
void CG_Vehicle_SetupCollisionCache(cg_t *cgameGlob, centity_t *cent, bool uses_vehicle_cache)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Vehicle_PreControllersAir
==============
*/
void CG_Vehicle_PreControllersAir(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Vehicle_PreControllersGround
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_Vehicle_PreControllers
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

