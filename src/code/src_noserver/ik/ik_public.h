#pragma once

#include "types.h"

//t6/code/src_noserver/ik/ik.cpp
void IK_AllocateLocalClientMemory(void *ikStatesBuf, int localClientIndex);
void IK_InitSystem();
BOOL IK_IsCalcBone(IKState *ikState, int ikBoneIndex);
void IK_UpdateTimeAll(int time, int localClientIndex, bool inViewer);
void IK_ResetTime();
void IK_UpdateDvarValues(IKState *ikState);
void IK_UpdateLayerLerps(IKState *ikState);
void IK_UpdateStatusFunctions(IKState *ikState);
IKBoneNames *IK_GetBoneParents(IKState *ikState);
IKJointBones *IK_GetJoints(IKState *ikState);
bool *IK_GetEssentialBones(IKState *ikState);
void IK_InitializeIKState(IKState *ikState);
IKState *IK_CreateIKForEntity(int entityNum, unsigned __int8 *model);
void IK_GetJointVars(int a1, IKState *ikState);
IKState *IK_GetIKStateForEntity(int entityNum, unsigned __int8 *model, bool bScanAll);
void IK_UpdateEntity(int entityNum, unsigned __int8 *model, bool isLocalBones, int *calcBoneBits);

//t6/code/src_noserver/ik/ik_import.cpp
void IKImport_InitVars(IKSystem *ikSystem);
bool IKImport_GetVar_IK_Enable();
bool IKImport_GetVar_IK_Foot_Test();
int IKImport_GetVar_IK_Debug();
bool IKImport_GetVar_IK_Hand_Get_Data();
bool IKImport_GetVar_IK_Enable(IKState *ikState);
int IKImport_GetVar_IK_Debug(IKState *ikState);
int IKImport_GetVar_IK_Hand_Tuning(IKState *ikState);
void IKImport_GetVar_IK_Hand_Offset_Vec(IKState *ikState, vec3_t *offset);
void IKImport_GetVar_IK_Hand_Rotation_Vec(IKState *ikState, vec3_t *rotation);
void IKImport_GetBoneStrings();
char IKImport_CalcAnimatedIKBonesBits(IKState *ikState, unsigned __int8 *model);
void IKImport_RecurseSetIKPartBits(const DObj *obj, int boneIndex, int *partBits);
IKBoneNames *IKImport_GetMinBoneExtents(IKState *ikState, int *boneCount);
void IKImport_SetIKPartBits(const DObj *obj, int *partBits);
char IKImport_CheckIKPartBits(IKState *ikState);
void IKImport_ApplyIKToSkeletonLocalBones(unsigned int a1, IKState *ikState);
void IKImport_ApplyIKToSkeleton(IKState *ikState);
IKState *IKImport_FetchDObjIKState(const unsigned __int8 *model);
void IKImport_SetDObjIKState(const unsigned __int8 *model, const IKState *ikState);
int IKImport_EntityNumToIndex(int entityNum);
char IKImport_ApplyLeftHandIK(IKState *ikState);
bool IKImport_ApplyRightHandIK(IKState *ikState);
void IKImport_DrawAxisOrigin(const vec3_t *a1, vec4_t *mat44, float colorScale);
void IKImport_DrawLine(clientDebugLineInfo_t *a1, vec3_t *start, vec3_t *end, int colorType);
void IKImport_DrawDebugSkeleton(int a1, IKState *ikState);
int IKImport_GetFrameNum();
BOOL __cdecl IKImport_IsMainThread();
LocalClientNum_t IKImport_GetLocalClientIndexForModel(unsigned __int8 *model);
BOOL IKImport_IsServerModel(unsigned __int8 *model);
BOOL IKImport_IsClient(IKState *ikState);
LerpEntityState *IKImport_GetLerpEntityState(IKState *ikState, const int inEntityNum);
gentity_t *IKImport_GetEntityState(IKState *ikState, const int inEntityNum);
bool IKImport_IsVehicleRemoteControl(IKState *ikState);
double IKImport_GetGunnerCrouch(IKState *ikState);
BOOL IKImport_IsMountedTurret(IKState *ikState);
int IKImport_IsFiring(IKState *ikState);
unsigned int IKImport_IsCrouching(IKState *ikState);
unsigned int IKImport_IsProne(IKState *ikState);
bool IKImport_GetBoneControllers(IKState *ikState, float *outAngles);
void IKImport_GetVelocity(IKState *ikState, vec3_t *velocity);
bool IKImport_IsSpectating(IKState *ikState);
char IKImport_IsMoving(IKState *ikState);
// LerpEntityStateActor::<unnamed_type_index> IKImport_GetActorNum(unsigned __int8 *model);
bool IKImport_IsValidEntityType(const unsigned __int8 *model);
BOOL IKImport_IsValidEntityNum(int entityNum);
void IKImport_Profiler(int a1, IKState *ikState);
bool IKImport_IsOnGround(IKState *ikState);
bool IKImport_ActorIKEnabled(const DObj *obj);
bool IKImport_IsServerRunning();
char IKImport_GetBoneLookups(IKState *ikState, IKBoneNames ikBoneName);
void IKImport_AccumulateParentObjBones(IKState *ikState, const unsigned __int8 *parentList, int numRootBones, float *transArray, int objBoneIndex, DObjAnimMat *matArray, DObjAnimMat *localMat);
void IKImport_GetBoneMatrixArrayLocalBones(IKState *ikState);
void IKImport_GetBoneMatrixArray(IKState *ikState);
char IKImport_IsIKEntity(const unsigned __int8 *model);
char IKImport_BypassTerrainMapping(IKState *ikState);
bool IKImport_ApplyTerrainMapping(IKState *ikState);
void IKImport_GetEntityXform(int a1, IKState *ikState);
void IKImport_UpdateCollisionCache(IKState *ikState);
char IKImport_TraceBox(int a1, IKState *ikState, vec3_t *startPos, vec3_t *endPos, float boxRadius, vec3_t *tracePos, vec3_t *outNormal, int hintIndexListItem, float *outTraceFraction, bool bIgnoreStartSolid);
clientInfo_t *IKImport_GetClientInfo(IKState *ikState);
Weapon IKImport_GetWeapon(IKState *ikState);
const WeaponVariantDef *IKImport_GetWeaponVariantDef(IKState *ikState);
const WeaponDef *IKImport_GetWeaponDef(IKState *ikState);
double IKImport_GetLayerLerp(IKState *ikState, IKLayerNames layerName, float layerLerpTime, LerpEntityState *lerpEntity);
double IKImport_GetLayerLerp(IKState *ikState, IKLayerNames layerName);
void IKImport_SetWeaponOffsetType(IKState *ikState);
void IKImport_UpdateWeaponClass(IKState *ikState);
void IKImport_GetPitchWeaponOffset(IKState *ikState, bool bIsPitchDirectionUp, vec3_t *weapOfsOut);
double IKImport_GetMaxLayerLerp(IKState *ikState);
void IKImport_InitCollisionCache(IKState *ikState);

//#include "ik/ik_import.h"

//t6/code/src_noserver/ik/ik_layers.cpp
void IK_Layer_ApplyFootIK(int a1, IKState *ikState, IKJointBones *jointBones, IKJointVars *jointVars, vec4_t *childMat, bool flipBones);
void IK_Layer_ApplyHandIK(int a1, IKState *ikState, IKJointBones *jointBones, IKJointVars *jointVars, vec4_t *childMat, bool flipBones);
void IK_Layer_LeftHandOnGun(int a1, IKState *ikState);
void IK_Layer_LeftHandOnGunTuningDisplay(int a1, IKState *ikState);
void IK_Layer_PlayerControllers(IKState *ikState);
void IK_Layer_PlayerPitch(int a1, long double ikState, IKState *a3, bool preControllers);
void IK_Layer_PreventHeadClip(int a1, IKState *ikState);
void IK_Layer_TerrainMapping(int a1, IKState *ikState);
void IK_ProcessLayers(int a1, IKState *ikState);

//t6/code/src_noserver/ik/ik_math.cpp
void ikMatrixIdentity44(vec4_t *out);
void MatrixSet44(vec4_t *out, const vec3_t *origin, const vec3_t *axis, float scale);
void ikQuatTransToMatrix44(const float *quat, const float *trans, vec4_t *out);
void ikAxisToQuat(const vec3_t *mat, vec4_t *out);
void IK_FlipHack(vec4_t *mat);
void ikNormalizedMatrixAssert_func(vec4_t *mat);
void ikQuatToAxis(const vec4_t *quat, vec3_t *axis);
void ikMatrix44ToQuatTrans(vec4_t *mat, vec4_t *quat, vec3_t *trans);
void ikCalcBoneModelMatrix_r(int a1, IKState *ikState, int boneNum, float *inMatArray, vec4_t *out);
void ikCalcBoneModelMatrix();
void ikMap2DTo3D(int a1, float UpperLimbLength, float SinUpper, float CosUpper, float SinLower, float CosLower, const vec3_t *ModelBaseJoint, const vec3_t *ModelTargetDir, const vec3_t *ModelMidJointDir, float sinTwist, float cosTwist, vec4_t *UpperLocalToModel, vec4_t *LowerLocalToModel);
void ikSolveLegJoint(int a1, IKState *ikState, IKJointBones *jointBones, IKJointVars *jointVars, vec3_t *footPos, vec4_t *outParentMat, vec4_t *outJointMat, bool flipHack);
void ikSolveArmJoint(int a1, IKState *ikState, IKJointBones *jointBones, IKJointVars *jointVars, vec3_t *handPos, vec4_t *outParentMat, vec4_t *outJointMat, bool flipHack);
void ikRotateBone(int a1, IKState *ikState, IKBoneNames boneName, vec3_t *rot, bool local);
void ikMatrixLerp44(vec4_t *from, vec4_t *to, float lerp, vec4_t *res);

//t6/code/src_noserver/ik/ik_process.cpp
void IK_GenerateIKXformMatrices(int a1, IKState *ikState);
void IK_Process(int a1, IKState *ikState);

