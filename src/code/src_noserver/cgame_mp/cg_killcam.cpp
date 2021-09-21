#include "types.h"
#include "functions.h"

/*
==============
CG_KillcamRegisterDvars
==============
*/
void CG_KillcamRegisterDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateKillCamEntityViewOffset
==============
*/
void CG_UpdateKillCamEntityViewOffset(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetPlayerKillCamEntityLookAt
==============
*/
void CG_GetPlayerKillCamEntityLookAt(LocalClientNum_t localClientNum, vec3_t *lookAtPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetKillCamEntityOrgAngles
==============
*/
void CG_GetKillCamEntityOrgAngles(LocalClientNum_t localClientNum, vec3_t *origin, vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LookAtAxisAndDistance
==============
*/
float LookAtAxisAndDistance(const vec3_t *origin, const vec3_t *lookAt, vec3_t *axis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LookAtBothPoints
==============
*/
float LookAtBothPoints(const vec3_t *point1, const vec3_t *point2, const vec3_t *campos, vec3_t *lookaxis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_UpdateTurretKillCam
==============
*/
void CG_UpdateTurretKillCam(float distance, GfxDepthOfField *dof)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetTurretEntityOrgAngles
==============
*/
void CG_GetTurretEntityOrgAngles(LocalClientNum_t localClientNum, vec3_t *origin, vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetTurretKillcamHeightIncrease
==============
*/
float CG_GetTurretKillcamHeightIncrease(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetTurretKillcamFOV
==============
*/
float CG_GetTurretKillcamFOV(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetTurretKillcamBackOffset
==============
*/
float CG_GetTurretKillcamBackOffset(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_UpdateVehicleKillCamDof
==============
*/
void CG_UpdateVehicleKillCamDof(const VehicleDef *info, float distance, GfxDepthOfField *dof)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateHelicopterKillCamDof
==============
*/
void CG_UpdateHelicopterKillCamDof(float distance, GfxDepthOfField *dof)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateHelicopterKillCam
==============
*/
void CG_UpdateHelicopterKillCam(KillCamEntityType killCamEntityType, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateScriptedKillCamDof
==============
*/
void CG_UpdateScriptedKillCamDof(float distance, GfxDepthOfField *dof)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateScriptedKillCam
==============
*/
void CG_UpdateScriptedKillCam(vec3_t *a1, LocalClientNum_t a2, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateDestructibleKillCamDof
==============
*/
void CG_UpdateDestructibleKillCamDof(float distance, GfxDepthOfField *dof)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateDestructibleKillCam
==============
*/
void CG_UpdateDestructibleKillCam(vec3_t *a1, LocalClientNum_t a2, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateArtilleryKillCam
==============
*/
void CG_UpdateArtilleryKillCam(unsigned int a1, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateDogKillCam
==============
*/
void CG_UpdateDogKillCam(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_KillCamEntityEnabled
==============
*/
bool CG_KillCamEntityEnabled(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CacheKillCamEntityPose
==============
*/
void CG_CacheKillCamEntityPose(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CacheKillCamLookAtEntityOrigin
==============
*/
void CG_CacheKillCamLookAtEntityOrigin(char *a1, const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateKillCamEntityCache
==============
*/
void CG_UpdateKillCamEntityCache(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_LerpKillCamView
==============
*/
void CG_LerpKillCamView(vec3_t *a1, LocalClientNum_t a2, unsigned int localClientNum, LocalClientNum_t a4)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetKillCamVehicleDef
==============
*/
const VehicleDef *CG_GetKillCamVehicleDef(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_UpdateVehicleKillCam
==============
*/
void CG_UpdateVehicleKillCam(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_KillcamCameraTrace
==============
*/
bool CG_KillcamCameraTrace(const vec3_t *desiredCamPos, vec3_t *campos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_UpdateExplosiveKillCam
==============
*/
void CG_UpdateExplosiveKillCam(vec3_t *a1, LocalClientNum_t a2, unsigned int localClientNum, vec3_t *killCamEntityType, LocalClientNum_t upDist, KillCamEntityType backDist, float outDist, float sideDist)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateTurretKillCam
==============
*/
void CG_UpdateTurretKillCam(vec3_t *a1, LocalClientNum_t a2, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateKillCamEntity
==============
*/
void CG_UpdateKillCamEntity(vec3_t *a1, LocalClientNum_t a2, vec3_t *killCamEntityType, KillCamEntityType localClientNum, LocalClientNum_t a5)
{
	UNIMPLEMENTED(__FUNCTION__);
}

