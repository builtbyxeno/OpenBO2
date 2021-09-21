#include "types.h"
#include "functions.h"

/*
==============
BG_HeliCmdScale
==============
*/
void BG_HeliCmdScale(bool scaleMovement, const char *move, vec4_t *outFracs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_HeliCalcAccelFromTilt
==============
*/
void BG_HeliCalcAccelFromTilt(const pmove_t *pm, const pml_t *pml, VehicleState *vehicleState, vec4_t *moveRequest, vec3_t *bodyAccel, vec3_t *rotAccel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_HelicopterHeightTrace
==============
*/
void BG_HelicopterHeightTrace(pmove_t *pm, VehicleState *vehicleState, trace_t *trace, vec3_t *hitOrigin, float dt, float trace_offset)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_HelicopterGroundTrace
==============
*/
void BG_HelicopterGroundTrace(pmove_t *pm, VehicleState *vehicleState, GroundTrace *groundTrace, float dt, float trace_offset)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_VehicleHeliLockHeight
==============
*/
int BG_VehicleHeliLockHeight(const vec3_t *a1, const char *a2, VehicleState *vehicleState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_CalculateRotorArms
==============
*/
void BG_CalculateRotorArms(const VehicleDef *vehDef, const vec3_t *velocity, const vec3_t *angles, const vec3_t *angVelocity, entityState_s *s, const float scale)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_HeliCalcAccel
==============
*/
void BG_HeliCalcAccel(const pmove_t *pm, const pml_t *pml, VehicleState *vehicleState, vec4_t *moveRequest, vec3_t *bodyAccel, vec3_t *rotAccel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_HeliMaintainHeight_UpdateHeight
==============
*/
void BG_HeliMaintainHeight_UpdateHeight(pmove_t *pm, const pml_t *pml, VehicleState *vehicleState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_PlayerStateToVehicleStateHelicopter
==============
*/
void BG_PlayerStateToVehicleStateHelicopter(LocalClientNum_t localClientNum, const playerState_s *ps, entityState_s *s, const VehicleDef *vehDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_HeliMaintainHeight_CalcAccel
==============
*/
double BG_HeliMaintainHeight_CalcAccel(int a1, pmove_t *pm, const pml_t *pml, VehicleState *vehicleState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_VehicleHelicopterVerticalMove
==============
*/
char BG_VehicleHelicopterVerticalMove(const vec3_t *a1, const char *a2, pmove_t *pm, const pml_t *pml, VehicleState *vehicleState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_VehicleHelicopterMove
==============
*/
void BG_VehicleHelicopterMove(unsigned int a1, pmove_t *pm, const pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

