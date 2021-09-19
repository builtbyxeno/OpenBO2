#include "types.h"
#include "functions.h"

/*
==============
FX_OffsetSpawnOrigin
==============
*/
void FX_OffsetSpawnOrigin(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GetSpawnOrigin
==============
*/
void FX_GetSpawnOrigin(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SpatialFrameToOrientation
==============
*/
void FX_SpatialFrameToOrientation(const FxSpatialFrame *frame, orientation_t *orient)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_OrientationToSpatialFrame
==============
*/
void FX_OrientationToSpatialFrame(const orientation_t *orient, FxSpatialFrame *frame)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GetOrientation_RunRelativeToOffset
==============
*/
void FX_GetOrientation_RunRelativeToOffset(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GetOrientation
==============
*/
void FX_GetOrientation(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GetVelocityAtTime
==============
*/
void FX_GetVelocityAtTime(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_OrientationPosToWorldPos
==============
*/
void FX_OrientationPosToWorldPos(const orientation_t *orient, const vec3_t *pos, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_OrientationPosFromWorldPos
==============
*/
void FX_OrientationPosFromWorldPos(const orientation_t *orient, const vec3_t *pos, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_AddVisBlocker
==============
*/
void FX_AddVisBlocker(FxSystem *system, const vec3_t *posWorld, float radius, float opacity)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ToggleVisBlockerFrame
==============
*/
void FX_ToggleVisBlockerFrame(FxSystem *system)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_CullSphere
==============
*/
char FX_CullSphere(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_CullBox
==============
*/
char FX_CullBox(const FxCamera *camera, unsigned int frustumPlaneCount, const vec3_t *mins, const vec3_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_AnglesToOrientedAxis
==============
*/
void FX_AnglesToOrientedAxis(const vec3_t *anglesInRad, const orientation_t *orient, vec3_t *axisOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GetElemAxis
==============
*/
void FX_GetElemAxis(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GetElemLifeSpanMsec
==============
*/
int FX_GetElemLifeSpanMsec(int elemRandomSeed, float elemWindInterpolate, const FxElemDef *elemDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_GetOriginForTrailElem
==============
*/
void FX_GetOriginForTrailElem(
{
	UNIMPLEMENTED(__FUNCTION__);
}

