#include "types.h"
#include "functions.h"

/*
==============
IKImport_InitVars
==============
*/
void IKImport_InitVars(IKSystem *ikSystem)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_GetVar_IK_Enable
==============
*/
bool IKImport_GetVar_IK_Enable()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_GetVar_IK_Foot_Test
==============
*/
bool IKImport_GetVar_IK_Foot_Test()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_GetVar_IK_Debug
==============
*/
int IKImport_GetVar_IK_Debug()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_GetVar_IK_Hand_Get_Data
==============
*/
bool IKImport_GetVar_IK_Hand_Get_Data()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_GetVar_IK_Enable
==============
*/
bool IKImport_GetVar_IK_Enable(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_GetVar_IK_Debug
==============
*/
int IKImport_GetVar_IK_Debug(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_GetVar_IK_Hand_Tuning
==============
*/
int IKImport_GetVar_IK_Hand_Tuning(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_GetVar_IK_Hand_Offset_Vec
==============
*/
void IKImport_GetVar_IK_Hand_Offset_Vec(IKState *ikState, vec3_t *offset)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_GetVar_IK_Hand_Rotation_Vec
==============
*/
void IKImport_GetVar_IK_Hand_Rotation_Vec(IKState *ikState, vec3_t *rotation)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_GetBoneStrings
==============
*/
void IKImport_GetBoneStrings()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_CalcAnimatedIKBonesBits
==============
*/
char IKImport_CalcAnimatedIKBonesBits(IKState *ikState, unsigned __int8 *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_RecurseSetIKPartBits
==============
*/
void IKImport_RecurseSetIKPartBits(const DObj *obj, int boneIndex, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_GetMinBoneExtents
==============
*/
IKBoneNames *IKImport_GetMinBoneExtents(IKState *ikState, int *boneCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
IKImport_SetIKPartBits
==============
*/
void IKImport_SetIKPartBits(const DObj *obj, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_CheckIKPartBits
==============
*/
char IKImport_CheckIKPartBits(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_ApplyIKToSkeletonLocalBones
==============
*/
void IKImport_ApplyIKToSkeletonLocalBones(unsigned int a1, IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_ApplyIKToSkeleton
==============
*/
void IKImport_ApplyIKToSkeleton(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_FetchDObjIKState
==============
*/
IKState *IKImport_FetchDObjIKState(const unsigned __int8 *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
IKImport_SetDObjIKState
==============
*/
void IKImport_SetDObjIKState(const unsigned __int8 *model, const IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_EntityNumToIndex
==============
*/
int IKImport_EntityNumToIndex(int entityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_ApplyLeftHandIK
==============
*/
char IKImport_ApplyLeftHandIK(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_ApplyRightHandIK
==============
*/
bool IKImport_ApplyRightHandIK(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_DrawAxisOrigin
==============
*/
void IKImport_DrawAxisOrigin(const vec3_t *a1, vec4_t *mat44, float colorScale)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_DrawLine
==============
*/
void IKImport_DrawLine(clientDebugLineInfo_t *a1, vec3_t *start, vec3_t *end, int colorType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_DrawDebugSkeleton
==============
*/
void IKImport_DrawDebugSkeleton(int a1, IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_GetFrameNum
==============
*/
int IKImport_GetFrameNum()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_IsMainThread
==============
*/
BOOL __cdecl IKImport_IsMainThread()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_GetLocalClientIndexForModel
==============
*/
LocalClientNum_t IKImport_GetLocalClientIndexForModel(unsigned __int8 *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	LocalClientNum_t tmp;
	return tmp;
}

/*
==============
IKImport_IsServerModel
==============
*/
BOOL IKImport_IsServerModel(unsigned __int8 *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_IsClient
==============
*/
BOOL IKImport_IsClient(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_GetLerpEntityState
==============
*/
LerpEntityState *IKImport_GetLerpEntityState(IKState *ikState, const int inEntityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
IKImport_GetEntityState
==============
*/
gentity_t *IKImport_GetEntityState(IKState *ikState, const int inEntityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
IKImport_IsVehicleRemoteControl
==============
*/
bool IKImport_IsVehicleRemoteControl(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_GetGunnerCrouch
==============
*/
double IKImport_GetGunnerCrouch(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_IsMountedTurret
==============
*/
BOOL IKImport_IsMountedTurret(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_IsFiring
==============
*/
int IKImport_IsFiring(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_IsCrouching
==============
*/
unsigned int IKImport_IsCrouching(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_IsProne
==============
*/
unsigned int IKImport_IsProne(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_GetBoneControllers
==============
*/
bool IKImport_GetBoneControllers(IKState *ikState, float *outAngles)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_GetVelocity
==============
*/
void IKImport_GetVelocity(IKState *ikState, vec3_t *velocity)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_IsSpectating
==============
*/
bool IKImport_IsSpectating(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_IsMoving
==============
*/
char IKImport_IsMoving(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_GetActorNum
==============
*/
/*LerpEntityStateActor::<unnamed_type_index> IKImport_GetActorNum(unsigned __int8 *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	LerpEntityStateActor::<unnamed_type_index> tmp;
	return tmp;
}*/

/*
==============
IKImport_IsValidEntityType
==============
*/
bool IKImport_IsValidEntityType(const unsigned __int8 *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_IsValidEntityNum
==============
*/
BOOL IKImport_IsValidEntityNum(int entityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_Profiler
==============
*/
void IKImport_Profiler(int a1, IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_IsOnGround
==============
*/
bool IKImport_IsOnGround(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_ActorIKEnabled
==============
*/
bool IKImport_ActorIKEnabled(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_IsServerRunning
==============
*/
bool IKImport_IsServerRunning()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_GetBoneLookups
==============
*/
char IKImport_GetBoneLookups(IKState *ikState, IKBoneNames ikBoneName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_AccumulateParentObjBones
==============
*/
void IKImport_AccumulateParentObjBones(IKState *ikState, const unsigned __int8 *parentList, int numRootBones, float *transArray, int objBoneIndex, DObjAnimMat *matArray, DObjAnimMat *localMat)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_GetBoneMatrixArrayLocalBones
==============
*/
void IKImport_GetBoneMatrixArrayLocalBones(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_GetBoneMatrixArray
==============
*/
void IKImport_GetBoneMatrixArray(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_IsIKEntity
==============
*/
char IKImport_IsIKEntity(const unsigned __int8 *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_BypassTerrainMapping
==============
*/
char IKImport_BypassTerrainMapping(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_ApplyTerrainMapping
==============
*/
bool IKImport_ApplyTerrainMapping(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_GetEntityXform
==============
*/
void IKImport_GetEntityXform(int a1, IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_UpdateCollisionCache
==============
*/
void IKImport_UpdateCollisionCache(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_TraceBox
==============
*/
char IKImport_TraceBox(int a1, IKState *ikState, vec3_t *startPos, vec3_t *endPos, float boxRadius, vec3_t *tracePos, vec3_t *outNormal, int hintIndexListItem, float *outTraceFraction, bool bIgnoreStartSolid)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_GetClientInfo
==============
*/
clientInfo_t *IKImport_GetClientInfo(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
IKImport_GetWeapon
==============
*/
Weapon IKImport_GetWeapon(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
IKImport_GetWeaponVariantDef
==============
*/
const WeaponVariantDef *IKImport_GetWeaponVariantDef(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
IKImport_GetWeaponDef
==============
*/
const WeaponDef *IKImport_GetWeaponDef(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
IKImport_GetLayerLerp
==============
*/
double IKImport_GetLayerLerp(IKState *ikState, IKLayerNames layerName, float layerLerpTime, LerpEntityState *lerpEntity)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_GetLayerLerp
==============
*/
double IKImport_GetLayerLerp(IKState *ikState, IKLayerNames layerName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_SetWeaponOffsetType
==============
*/
void IKImport_SetWeaponOffsetType(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_UpdateWeaponClass
==============
*/
void IKImport_UpdateWeaponClass(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_GetPitchWeaponOffset
==============
*/
void IKImport_GetPitchWeaponOffset(IKState *ikState, bool bIsPitchDirectionUp, vec3_t *weapOfsOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IKImport_GetMaxLayerLerp
==============
*/
double IKImport_GetMaxLayerLerp(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IKImport_InitCollisionCache
==============
*/
void IKImport_InitCollisionCache(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

