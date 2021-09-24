#include "types.h"

/*
==============
FX_IsDemoPlaying
==============
*/
bool FX_IsDemoPlaying()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_SpawnTrailLoopingElems
==============
*/
void FX_SpawnTrailLoopingElems(const FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, FxTrail *trail, const FxElemDef *trailElemDef, const FxSpatialFrame *frameBegin, const FxSpatialFrame *frameEnd, int msecWhenPlayed, int msecUpdateBegin, int msecUpdateEnd, float distanceTravelledBegin, float distanceTravelledEnd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_LimitStabilizeTimeForEffectDef_Recurse
==============
*/
int FX_LimitStabilizeTimeForEffectDef_Recurse(const FxEffectDef *remoteEffectDef, int originalUpdateTime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_LimitStabilizeTimeForElemDef_Recurse
==============
*/
int FX_LimitStabilizeTimeForElemDef_Recurse(const FxElemDef *elemDef, bool needToSpawnSystem, int originalUpdateTime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_SpawnLoopingElems
==============
*/
void FX_SpawnLoopingElems(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, const FxElemDef *elemDef, int elemDefIndex, const FxSpatialFrame *frameBegin, const FxSpatialFrame *frameEnd, int msecWhenPlayed, int msecUpdateBegin, int msecUpdateEnd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SpawnAllFutureLooping
==============
*/
void FX_SpawnAllFutureLooping(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, const FxSpatialFrame *frameBegin, const FxSpatialFrame *frameEnd, int msecWhenPlayed, int msecUpdateBegin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_TriggerOneShot
==============
*/
void FX_TriggerOneShot(const FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, const FxSpatialFrame *frameWhenPlayed, int msecWhenPlayed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_IntegrateVelocityAcrossSegments
==============
*/
void FX_IntegrateVelocityAcrossSegments(int elemDefFlags, const orientation_t *orient, const FxElemVelStateSample *velState0, const FxElemVelStateSample *velState1, float t0, float t1, const vec3_t *amplitudeScale, float integralScale, vec3_t *posLocal, vec3_t *posWorld)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_IntegrateVelocityInSegment
==============
*/
void FX_IntegrateVelocityInSegment(int elemDefFlags, const orientation_t *orient, const FxElemVelStateSample *velState, float t0, float t1, const vec3_t *amplitudeScale, float integralScale, vec3_t *posLocal, vec3_t *posWorld)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_IntegrateVelocity
==============
*/
void FX_IntegrateVelocity(int a1, vec3_t *a2, float t1, const vec3_t *posLocal)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_NextElementPosition_NoExternalForces
==============
*/
void FX_NextElementPosition_NoExternalForces(FxUpdateElem *update, int msecUpdateBegin, int msecUpdateEnd, vec3_t *posLocal, vec3_t *posWorld)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GetAtRestFraction
==============
*/
double FX_GetAtRestFraction(int a1, float a2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_GetQuatForOrientation
==============
*/
void FX_GetQuatForOrientation(const FxEffect *effect, const FxElemDef *elemDef, const FxSpatialFrame *frameNow, const orientation_t *orient, vec4_t *quat)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_UpdateElement_SetupUpdate
==============
*/
bool FX_UpdateElement_SetupUpdate(FxEffect *effect, const FxEffectDef *effectDef, int msecUpdateBegin, int msecUpdateEnd, int elemDefIndex, int elemAtRestFraction, int elemMsecBegin, int elemSequence, float *elemOrigin, float elemWindInterp, FxUpdateElem *update)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_PlayElementSpawnSound
==============
*/
void FX_PlayElementSpawnSound(const FxSystem *system, const FxElemDef *elemDef, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_UpdateElement_TruncateToElemBegin
==============
*/
bool FX_UpdateElement_TruncateToElemBegin(FxUpdateElem *update, FxUpdateResult *outUpdateResult)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_GetBoltTemporalBits
==============
*/
int FX_GetBoltTemporalBits(LocalClientNum_t localClientNum, int dobjHandle, unsigned int ignoreTeleporting)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_GetBoneOrientation_IsDObjEntityValid
==============
*/
bool FX_GetBoneOrientation_IsDObjEntityValid(LocalClientNum_t localClientNum, int dobjHandle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_GetBoneOrientation
==============
*/
char FX_GetBoneOrientation(LocalClientNum_t localClientNum, int dobjHandle, int boneIndex, orientation_t *orient)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_CanKillImmediate
==============
*/
bool FX_CanKillImmediate(const FxEffectDef *def)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_UpdateEffectBolt
==============
*/
int FX_UpdateEffectBolt(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_GetWorldBoundingBox
==============
*/
void FX_GetWorldBoundingBox(const vec3_t *origin, const vec3_t *orient, const vec3_t *boxCentre, const vec3_t *boxDim, unsigned int effectDefFlags, vec3_t *boxMin, vec3_t *boxMax)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_TestEffectBoundingBoxMinMaxAgainstFrustum
==============
*/
int FX_TestEffectBoundingBoxMinMaxAgainstFrustum(const FxSystem *system, const vec3_t *boxMin, const vec3_t *boxMax, unsigned int effectFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_ShouldProcessEffect
==============
*/
bool FX_ShouldProcessEffect(FxSystem *system, FxEffect *remoteEffect, FxUpdateEffectType updateEffectType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_BeginUpdate
==============
*/
void FX_BeginUpdate(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_EndUpdate
==============
*/
void FX_EndUpdate(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SaveGfxCloudCount
==============
*/
void FX_SaveGfxCloudCount(LocalClientNum_t localClientNum, int count)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SortEffectsForDraw
==============
*/
void FX_SortEffectsForDraw(FxSystem *system)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_AddNonSpriteDrawSurfs
==============
*/
void FX_AddNonSpriteDrawSurfs(FxCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_RestartEffects_Begin
==============
*/
void DB_RestartEffects_Begin()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SetupCamera
==============
*/
void FX_SetupCamera(FxCamera *camera, const vec3_t *vieworg, const vec3_t *viewaxis, const float tanHalfFovX, const float tanHalfFovY, const float zfar)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GetCameraUpdateFromRefdefAndZFar
==============
*/
void FX_GetCameraUpdateFromRefdefAndZFar(FxCameraUpdate *cameraUpdate, const refdef_t *refdef, float zfar)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SetExtraCamera
==============
*/
void __cdecl FX_SetExtraCamera(LocalClientNum_t localClientNum, const FxCameraUpdate *cameraUpdate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SetNextUpdateCamera
==============
*/
void __cdecl FX_SetNextUpdateCamera(LocalClientNum_t localClientNum, const FxCameraUpdate *cameraUpdate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SetNextUpdateTime
==============
*/
void FX_SetNextUpdateTime(LocalClientNum_t localClientNum, int time, int timeDelta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_FillUpdateCmd
==============
*/
void FX_FillUpdateCmd(LocalClientNum_t localClientNum, FxCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_InitFxSpawnEffectCmd
==============
*/
void FX_InitFxSpawnEffectCmd(FxSpawnEffectCmd *cmd, LocalClientNum_t clientNum, const FxEffectDef *effectDef, int msecBegin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ProcessLooping
==============
*/
void FX_ProcessLooping(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, const FxSpatialFrame *frameBegin, const FxSpatialFrame *frameEnd, int msecWhenPlayed, int msecUpdateBegin, int msecUpdateEnd, float distanceTravelledBegin, float distanceTravelledEnd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_BeginLooping
==============
*/
void __cdecl FX_BeginLooping(const FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, const FxSpatialFrame *frameWhenPlayed, const FxSpatialFrame *frameNow, int msecWhenPlayed, int msecNow)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_StartNewEffect
==============
*/
void FX_StartNewEffect(const FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ProcessEmitting
==============
*/
unsigned __int8 FX_ProcessEmitting(FxSystem *system, const FxUpdateElem *update, unsigned __int8 emitResidual, const FxSpatialFrame *frameBegin, const FxSpatialFrame *frameEnd)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_NextElementPosition
==============
*/
void FX_NextElementPosition(FxUpdateElem *update, int msecUpdateBegin, int msecUpdateEnd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SpawnImpactEffect
==============
*/
void FX_SpawnImpactEffect(FxSystem *system, const FxUpdateElem *update, const FxEffectDef *impactEffect, int msecOnImpact, const vec3_t *impactNormal)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_CollisionResponse
==============
*/
int FX_CollisionResponse(FxSystem *system, FxUpdateElem *update, const trace_t *trace, int msecUpdateBegin, int msecUpdateEnd, vec3_t *xyzWorldOld)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_UpdateElementPosition_CollidingStep
==============
*/
FxUpdateResult FX_UpdateElementPosition_CollidingStep(FxUpdateElem *update, vec3_t *xyzWorldOld)
{
	UNIMPLEMENTED(__FUNCTION__);
	FxUpdateResult tmp;
	return tmp;
}

/*
==============
FX_UpdateElementPosition_Colliding
==============
*/
FxUpdateResult FX_UpdateElementPosition_Colliding(FxUpdateElem *update)
{
	UNIMPLEMENTED(__FUNCTION__);
	FxUpdateResult tmp;
	return tmp;
}

/*
==============
FX_UpdateElementPosition_Local
==============
*/
FxUpdateResult FX_UpdateElementPosition_Local(FxUpdateElem *update)
{
	UNIMPLEMENTED(__FUNCTION__);
	FxUpdateResult tmp;
	return tmp;
}

/*
==============
FX_UpdateElementPosition
==============
*/
FxUpdateResult FX_UpdateElementPosition(FxSystem *system, FxUpdateElem *update)
{
	UNIMPLEMENTED(__FUNCTION__);
	FxUpdateResult tmp;
	return tmp;
}

/*
==============
FX_SpawnDeathEffect
==============
*/
void FX_SpawnDeathEffect(FxSystem *system, FxUpdateElem *update)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_UpdateElement_HandleEmitting
==============
*/
void FX_UpdateElement_HandleEmitting(FxSystem *system, FxElem *elem, const FxUpdateElem *update, const vec3_t *elemOriginPrev, FxUpdateResult *outUpdateResult)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_UpdateElement_HandleAttachedEffect
==============
*/
void FX_UpdateElement_HandleAttachedEffect(FxSystem *system, FxElem *elem, const FxUpdateElem *update, FxUpdateResult updateResult)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_UpdateTrailElement
==============
*/
FxUpdateResult FX_UpdateTrailElement(FxSystem *system, FxEffect *effect, const FxEffectDef *effectDef, const FxTrail *trail, FxTrailElem *trailElem, int msecUpdateBegin, int msecUpdateEnd)
{
	UNIMPLEMENTED(__FUNCTION__);
	FxUpdateResult tmp;
	return tmp;
}

/*
==============
FX_UpdateEffectPartialTrail
==============
*/
bool FX_UpdateEffectPartialTrail(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, FxTrail *trail, int msecUpdateBegin, int msecUpdateEnd, float distanceTravelledBegin, float distanceTravelledEnd, unsigned __int16 trailElemHandleStart, unsigned __int16 trailElemHandleStop, FxSpatialFrame *frameNow)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_RewindTo
==============
*/
void FX_RewindTo(LocalClientNum_t localClientNum, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_RestartEffects_Finish
==============
*/
void DB_RestartEffects_Finish()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_UpdateSpotLightEffectPartial
==============
*/
void FX_UpdateSpotLightEffectPartial(FxSystem *system, FxEffect *localEffect, FxEffect *effect, const FxEffectDef *effectDef, int msecUpdateBegin, int msecUpdateEnd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_UpdateEffectPartialForClass
==============
*/
unsigned int FX_UpdateEffectPartialForClass(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, int msecUpdateBegin, int msecUpdateEnd, unsigned __int16 elemHandleStart, unsigned __int16 elemHandleStop, unsigned int elemClass, bool OFFSCREEN)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_UpdateEffectPartial<1>
==============
*/
/*void FX_UpdateEffectPartial<1>(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, int msecUpdateBegin, int msecUpdateEnd, float distanceTravelledBegin, float distanceTravelledEnd, unsigned __int16 *elemHandleStart, unsigned __int16 *elemHandleStop)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
FX_UpdateEffectPartial<0>
==============
*/
/*void __cdecl FX_UpdateEffectPartial<0>(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, int msecUpdateBegin, int msecUpdateEnd, float distanceTravelledBegin, float distanceTravelledEnd, unsigned __int16 *elemHandleStart, unsigned __int16 *elemHandleStop, volatile unsigned __int16 *trailElemStart, volatile unsigned __int16 *trailElemStop)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
FX_UpdateCulledEffect
==============
*/
void FX_UpdateCulledEffect(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_UpdateEffect
==============
*/
void FX_UpdateEffect(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_UpdateSpotLightEffect
==============
*/
void FX_UpdateSpotLightEffect(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_UpdateBatch
==============
*/
void FX_UpdateBatch(FxSystem *system, FxSystem *remoteSystem, int firstEffect, int lastEffect, FxUpdateEffectType updateEffectType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_UpdateSpotLight
==============
*/
void FX_UpdateSpotLight(char *a1, FxCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_UpdateNonSprite
==============
*/
void __cdecl FX_UpdateNonSprite(FxCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_UpdateNonDependent
==============
*/
void __cdecl FX_UpdateNonDependent(FxCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_UpdatePortalled
==============
*/
void __cdecl FX_UpdatePortalled(FxCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_UpdateRemaining
==============
*/
void __cdecl FX_UpdateRemaining(FxCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

