#include "types.h"
#include "functions.h"

/*
==============
TRACK_fx_system
==============
*/
void TRACK_fx_system()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GetSystem
==============
*/
FxSystemContainer *FX_GetSystem(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
FX_LinkSystemBuffers
==============
*/
void FX_LinkSystemBuffers(FxSystem *system, FxSystemBuffers *systemBuffers)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_PrintMatchingEffects
==============
*/
int FX_PrintMatchingEffects(LocalClientNum_t clientNum, unsigned int testOffset, unsigned int testValue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_CullElemForSpawn
==============
*/
bool FX_CullElemForSpawn(const FxCamera *camera, const FxElemDef *elemDef, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_EffectHasSideEffects
==============
*/
bool FX_EffectHasSideEffects(const FxElemDef *elemDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_DelRefToOwnerEffect
==============
*/
void FX_DelRefToOwnerEffect(const FxSystem *system, unsigned int ownerEffect, unsigned int stackCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_RunGarbageCollection_FreeSpotLight
==============
*/
void FX_RunGarbageCollection_FreeSpotLight(const FxSystem *system, unsigned __int16 effectHandle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_RingBufferAllocate
==============
*/
char FX_RingBufferAllocate(volatile int *firstFree, const volatile int *firstActive, int bufferCapacity, int *outAllocIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_RingBufferCommit
==============
*/
void FX_RingBufferCommit(volatile int *firstNew, const volatile int *firstFree, int allocIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_EffectAffectsGameplay
==============
*/
char FX_EffectAffectsGameplay(const FxEffectDef *remoteEffectDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_SetEffectRandomSeed
==============
*/
void FX_SetEffectRandomSeed(FxEffect *effect, const FxEffectDef *remoteDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SpawnEffect_AllocSpotLightEffect
==============
*/
bool FX_SpawnEffect_AllocSpotLightEffect(const FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_SetWarningPriority
==============
*/
void FX_SetWarningPriority(const FxSystem *system, unsigned __int8 priority)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_InvalidateFrameWarningPriority
==============
*/
void FX_InvalidateFrameWarningPriority(const FxSystem *system)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GetFrameWarningPriority
==============
*/
int FX_GetFrameWarningPriority(const FxSystem *system)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_Priority_Begin
==============
*/
void FX_Priority_Begin(FxSystem *system)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_AddRefToOwnerEffect
==============
*/
void FX_AddRefToOwnerEffect(const FxSystem *system, unsigned int owner, FxEffect *newEffect)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_InitEffectGroundEntity
==============
*/
void FX_InitEffectGroundEntity(const FxSystem *system, FxEffect *effect, const vec3_t *origin, const vec3_t *axis, int groundEntityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SpawnEffectDeferred
==============
*/
unsigned int FX_SpawnEffectDeferred(const FxSystem *system, FxSpawnEffectCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_SpawnWorkerShouldBeHeld
==============
*/
BOOL FX_SpawnWorkerShouldBeHeld(const FxSpawnEffectCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_AssertAllocatedEffect
==============
*/
void FX_AssertAllocatedEffect(LocalClientNum_t localClientNum, unsigned int hEffect, const char *error_msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GetEffectPlayedTime
==============
*/
int FX_GetEffectPlayedTime(LocalClientNum_t localClientNum, unsigned int hEffect)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_IsEffectDone
==============
*/
BOOL FX_IsEffectDone(LocalClientNum_t localClientNum, unsigned int hEffect)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_HideEffectInExtracam
==============
*/
void FX_HideEffectInExtracam(LocalClientNum_t localClientNum, unsigned int hEffect, bool hide)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_RandomlyRotateAxis
==============
*/
void FX_RandomlyRotateAxis(const vec3_t *axisIn, int randomSeed, vec3_t *axisOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SpawnRunner
==============
*/
void FX_SpawnRunner(const FxSystem *system, FxEffect *effect, const FxElemDef *elemDef, const FxSpatialFrame *effectFrameWhenPlayed, int randomSeed, int msecWhenPlayed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GetOriginForElem
==============
*/
void FX_GetOriginForElem(FxEffect *effect, const FxElemDef *elemDef, const FxSpatialFrame *effectFrameWhenPlayed, int randomSeed, vec3_t *outOrigin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SpawnSound
==============
*/
void FX_SpawnSound(const FxSystem *system, FxEffect *effect, const FxElemDef *elemDef, const FxSpatialFrame *effectFrameWhenPlayed, int randomSeed, int msecWhenPlayed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ElemSpawnVisBits
==============
*/
unsigned __int8 FX_ElemSpawnVisBits(const FxSystem *system, const FxElemDef *elemDef, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_ImpactMarkWithinRange
==============
*/
bool FX_ImpactMarkWithinRange(const FxSystem *system, const vec3_t *markLocation)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_GetClientVisibility
==============
*/
double FX_GetClientVisibility(LocalClientNum_t localClientNum, const vec3_t *start, const vec3_t *end)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_ClientVisibilityTest
==============
*/
bool FX_ClientVisibilityTest(LocalClientNum_t localClientNum, const vec3_t *start, const vec3_t *end)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_FxSpawnWorkersAreOnHold
==============
*/
BOOL FX_FxSpawnWorkersAreOnHold(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_ShouldHideMatureContent
==============
*/
BOOL FX_ShouldHideMatureContent()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_ResetSystem
==============
*/
void FX_ResetSystem(FxSystem *system)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_InitSystem
==============
*/
void FX_InitSystem(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ShutdownSystem
==============
*/
void FX_ShutdownSystem(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_CullEffectForSpawn
==============
*/
bool FX_CullEffectForSpawn(const FxCamera *camera, const FxEffectDef *effectDef, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_RunGarbageCollection_FreeTrails
==============
*/
void FX_RunGarbageCollection_FreeTrails(const FxSystem *system, FxEffect *effect)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_EffectRemoveBaseRef
==============
*/
void FX_EffectRemoveBaseRef(const FxSystem *system, FxEffect *remoteEffect)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_RunGarbageCollection
==============
*/
void FX_RunGarbageCollection(const FxSystem *system)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SpawnEffect_AllocTrails
==============
*/
void FX_SpawnEffect_AllocTrails(const FxSystem *system, FxEffect *effect, FxEffect *remoteEffect)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SpawnEffect
==============
*/
unsigned int FX_SpawnEffect(float system, const FxSystem *a2, const FxEffectDef *remoteDef, int msecBegin, const vec3_t *origin, const vec3_t *axis, int dobjHandle, int boneIndex, int runnerSortOrder, unsigned int owner, unsigned int markEntnum, const orientation_t *boneOffset, bool markViewmodel, unsigned int preAllocatedUniqueHandle, int groundEntityNum, float primaryLightFraction, int lightingOriginOffset)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_WaitForFxSpawnWorkers
==============
*/
void FX_WaitForFxSpawnWorkers(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SpawnOrientedEffect
==============
*/
unsigned int FX_SpawnOrientedEffect(char *a1, LocalClientNum_t localClientNum, const FxEffectDef *def, int msecBegin, const vec3_t *origin, const vec3_t *axis, unsigned int markEntnum, unsigned int markViewmodel, int groundEntity)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_PlayOrientedEffectWithMarkEntity
==============
*/
unsigned int FX_PlayOrientedEffectWithMarkEntity(LocalClientNum_t localClientNum, const FxEffectDef *def, int startMsec, const vec3_t *origin, const vec3_t *axis, unsigned int markEntnum, int groundEntity)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_PlayOrientedEffectWithMarkViewmodel
==============
*/
unsigned int FX_PlayOrientedEffectWithMarkViewmodel(LocalClientNum_t localClientNum, const FxEffectDef *def, int startMsec, const vec3_t *origin, const vec3_t *axis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_PlayOrientedEffect
==============
*/
unsigned int FX_PlayOrientedEffect(LocalClientNum_t localClientNum, const FxEffectDef *def, int startMsec, const vec3_t *origin, const vec3_t *axis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_PlayOrientedEffectWithLightingParams
==============
*/
unsigned int FX_PlayOrientedEffectWithLightingParams(LocalClientNum_t localClientNum, const FxEffectDef *def, int startMsec, const vec3_t *origin, const vec3_t *axis, float primaryLightFraction)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_NeedsBoltUpdate
==============
*/
bool FX_NeedsBoltUpdate(const FxEffectDef *def)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_SpawnBoltedEffect
==============
*/
unsigned int FX_SpawnBoltedEffect(LocalClientNum_t localClientNum, const FxEffectDef *def, int msecBegin, int dobjHandle, int boneIndex, const vec3_t *origin, const vec3_t *axis, int groundEntity)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_SpawnBoltedEffect
==============
*/
unsigned int FX_SpawnBoltedEffect(LocalClientNum_t localClientNum, const FxEffectDef *def, int msecBegin, int dobjHandle, int boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_SpawnBoltedEffectBoltRelative
==============
*/
unsigned int FX_SpawnBoltedEffectBoltRelative(LocalClientNum_t localClientNum, const FxEffectDef *def, int msecBegin, int dobjHandle, int boneIndex, const vec3_t *origin, const vec3_t *axis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_PlayBoltedEffect_DynEnt
==============
*/
unsigned int FX_PlayBoltedEffect_DynEnt(LocalClientNum_t localClientNum, const FxEffectDef *def, int startMsec, int absDynEntId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_PlayBoltedEffect
==============
*/
unsigned int FX_PlayBoltedEffect(LocalClientNum_t localClientNum, const FxEffectDef *def, int startMsec, int dobjHandle, int boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_PlayBoltedEffect
==============
*/
unsigned int FX_PlayBoltedEffect(LocalClientNum_t localClientNum, const FxEffectDef *def, int startMsec, int dobjHandle, int boneIndex, const vec3_t *origin, const vec3_t *axis, int groundEntity)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_PlayBoltedEffectBoltRelative
==============
*/
unsigned int FX_PlayBoltedEffectBoltRelative(LocalClientNum_t localClientNum, const FxEffectDef *def, int startMsec, int dobjHandle, int boneIndex, const vec3_t *origin, const vec3_t *axis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_GetTrailHandleList_Last
==============
*/
void FX_GetTrailHandleList_Last(FxSystem *system, FxEffect *effect, unsigned __int16 *outHandleList, int *outTrailCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_StopEffectNonRecursive
==============
*/
void FX_StopEffectNonRecursive(const FxSystem *system, FxEffect *effect)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SpawnModelPhysics
==============
*/
bool FX_SpawnModelPhysics(int randomSeed, FxElem *elem)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_SpawnTrailElem_NoCull
==============
*/
void FX_SpawnTrailElem_NoCull(const FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, FxTrail *trail, const FxElemDef *trailElemDef, const FxSpatialFrame *effectFrameWhenPlayed, int msecWhenPlayed, float distanceWhenPlayed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SpawnTrailElem_Cull
==============
*/
void FX_SpawnTrailElem_Cull(const FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, FxTrail *trail, const FxElemDef *trailElemDef, const FxSpatialFrame *effectFrameWhenPlayed, int msecWhenPlayed, float distanceWhenPlayed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SpawnSpotLightElem
==============
*/
void FX_SpawnSpotLightElem(const FxSystem *system, FxElem *elem)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_FreeTrailElem
==============
*/
void FX_FreeTrailElem(const FxSystem *system, unsigned __int16 trailElemHandle, FxEffect *effect, FxEffect *remoteEffect, FxTrail *trail)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_FreeSpotLightElem
==============
*/
void FX_FreeSpotLightElem(const FxSystem *system, unsigned __int16 elemHandle, FxEffect *effect)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ProcessCmd_SpawnEffect
==============
*/
void FX_ProcessCmd_SpawnEffect(FxSpawnEffectCmd *data)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_StopEffect
==============
*/
void FX_StopEffect(const FxSystem *system, FxEffect *effect)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_RemoveAllEffectElems
==============
*/
void FX_RemoveAllEffectElems(const FxSystem *system, FxEffect *effect, FxEffect *localEffect, const FxEffectDef *effectDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_KillEffect
==============
*/
void FX_KillEffect(const FxSystem *system, FxEffect *effect, FxEffect *localEffect, const FxEffectDef *effectDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_KillEffectDef
==============
*/
void FX_KillEffectDef(LocalClientNum_t localClientNum, const FxEffectDef *def)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_KillAllEffects
==============
*/
void FX_KillAllEffects(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_RetriggerEffect
==============
*/
void FX_RetriggerEffect(LocalClientNum_t localClientNum, FxEffect *effect, int msecBegin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_RetriggerEffect
==============
*/
void FX_RetriggerEffect(LocalClientNum_t localClientNum, unsigned int hEffect, int msecBegin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ThroughWithEffect
==============
*/
void FX_ThroughWithEffect(const FxSystem *system, FxEffect *effect, bool forcekill)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_FreeElem
==============
*/
void FX_FreeElem(const FxSystem *system, unsigned __int16 elemHandle, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, unsigned int elemClass)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ThroughWithEffect
==============
*/
void FX_ThroughWithEffect(LocalClientNum_t localClientNum, unsigned int hEffect, bool forcekill)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SpawnElem
==============
*/
void FX_SpawnElem(float system, const FxSystem *a2, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, const FxElemDef *elemDef, int elemDefIndex, const FxSpatialFrame *effectFrameWhenPlayed, int msecWhenPlayed, float distanceWhenPlayed, int sequence)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_RunPrioritySorting
==============
*/
void FX_RunPrioritySorting(const FxSystem *system)
{
	UNIMPLEMENTED(__FUNCTION__);
}

