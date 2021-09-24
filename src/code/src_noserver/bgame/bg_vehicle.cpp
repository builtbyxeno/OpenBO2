#include "types.h"

/*
==============
BG_GetVehicleDef
==============
*/
VehicleDef *BG_GetVehicleDef(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_IsVehicleAircraftRemote
==============
*/
BOOL BG_IsVehicleAircraftRemote(const VehicleDef *info)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_VehicleUsesCylinderGJK
==============
*/
bool BG_VehicleUsesCylinderGJK(const VehicleDef *vehDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_VehicleUsesGJK
==============
*/
bool BG_VehicleUsesGJK(const VehicleDef *vehDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_VEH_GetCollmap
==============
*/
PhysGeomList *G_VEH_GetCollmap(LocalClientNum_t localClientNum, const int entNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_VEH_GetCollmap
==============
*/
PhysGeomList *CG_VEH_GetCollmap(LocalClientNum_t localClientNum, const int entNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_GetVehicleProximityCache
==============
*/
/*colgeom_visitor_inlined_t<300> *G_GetVehicleProximityCache(LocalClientNum_t localClientNum, const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
CG_GetVehicleProximityCache
==============
*/
/*colgeom_visitor_inlined_t<300> *CG_GetVehicleProximityCache(LocalClientNum_t localClientNum, const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
G_GetVehicleDef
==============
*/
VehicleDef *G_GetVehicleDef(LocalClientNum_t localClientNum, const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_GetVehicleDef
==============
*/
VehicleDef *CG_GetVehicleDef(LocalClientNum_t localClientNum, const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_GetWheelOrigin
==============
*/
int CG_GetWheelOrigin(const pmove_t *pm, int wheelIndex, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_GetWheelOrigin
==============
*/
int G_GetWheelOrigin(const pmove_t *pm, int wheelIndex, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetVehicleDef
==============
*/
const VehicleDef *BG_GetVehicleDef(const pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_GetWheelOrigin
==============
*/
int BG_GetWheelOrigin(const pmove_t *pm, int wheelIndex, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetVehicleBounds
==============
*/
void BG_GetVehicleBounds(const pmove_t *pm, vec3_t *mins, vec3_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_VehicleClipVelocity
==============
*/
void BG_VehicleClipVelocity(const vec3_t *velocity, const vec3_t *normal, vec3_t *clippedVelocity)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_VehicleGroundPlant
==============
*/
int BG_VehicleGroundPlant(pmove_t *pm, VehicleState *vehicleState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_PlayerStateToVehicleState
==============
*/
void BG_PlayerStateToVehicleState(LocalClientNum_t localClientNum, const playerState_s *ps, entityState_s *s, int snap, unsigned __int8 handler)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_VehicleCorrectAllSolid
==============
*/
int BG_VehicleCorrectAllSolid(pmove_t *pm, VehicleState *vehicleState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_VehicleGroundTrace
==============
*/
void BG_VehicleGroundTrace(pmove_t *pm, VehicleState *vehicleState, GroundTrace *groundTrace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_VehicleSlideMove
==============
*/
bool BG_VehicleSlideMove(unsigned int a1, pmove_t *pm, VehicleState *vehicleState, const GroundTrace *groundTrace, int gravity, float dt)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_VehicleStepSlideMove
==============
*/
void BG_VehicleStepSlideMove(VehicleState *vehicleState, const GroundTrace *groundTrace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_VehicleGroundMove
==============
*/
void BG_VehicleGroundMove(pmove_t *pm, VehicleState *vehicleState, const GroundTrace *groundTrace, int gravity, float dt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_VehicleSteerMove
==============
*/
void BG_VehicleSteerMove(unsigned int a1, pmove_t *pm, const pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_VehicleStrafeMove
==============
*/
void BG_VehicleStrafeMove(unsigned int a1, pmove_t *pm, const pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_VehicleMove
==============
*/
void BG_VehicleMove(pmove_t *pm, const pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

