#pragma once

#include "types.h"

//t6/code/src_noserver/ragdoll/ragdoll.cpp
void TRACK_ragdoll();
RagdollDef *Ragdoll_BodyDef(RagdollBody *body);
DObj *Ragdoll_BodyDObj(RagdollBody *body);
centity_t *Ragdoll_BodyPose(RagdollBody *body);
void Ragdoll_BodyRootOrigin(RagdollBody *body, vec3_t *origin);
void Ragdoll_GetRootOrigin(int ragdollHandle, vec3_t *origin);
void Ragdoll_SetFlag(int ragdollHandle, int flag, bool val);
bool Ragdoll_BindDef(int ragdollDef);
void Ragdoll_TransferBody(centity_t *from, centity_t *to);
void Ragdoll_InitDvars();
void Ragdoll_Register();
void Ragdoll_Init();
void Ragdoll_Shutdown();
;
int *Ragdoll_ReferenceDObjBody(int dobj);
int Ragdoll_CountPhysicsBodies();
RagdollBody *Ragdoll_GetUnusedBody();
void Ragdoll_FreeBody(int ragdollBody);
RagdollBody *Ragdoll_CreateRagdollForDObj(;
void Ragdoll_Remove(int ragdoll);

//#include "ragdoll/ragdoll.h"

//t6/code/src_noserver/ragdoll/ragdoll_cmds.cpp
bool Ragdoll_ReadAxis(int arg, vec3_t *dest);
bool Ragdoll_ReadGeomType(int arg, BoneDef *bone);
bool Ragdoll_ReadJointType(int arg, JointDef *joint);
void Ragdoll_BaseLerpBone_f();
void Ragdoll_PinBone_f();
void Ragdoll_ResetBodiesUsingDef();
void Ragdoll_Clear_f();
void Ragdoll_Bone_f();
void Ragdoll_Joint_f();
void Ragdoll_Limit_f();
void Ragdoll_Selfpair_f();
void Ragdoll_InitCommands();

//t6/code/src_noserver/ragdoll/ragdoll_controller.cpp
BoneOrientation *Ragdoll_BodyBoneOrientations(RagdollBody *body);
BoneOrientation *Ragdoll_BodyPrevBoneOrientations(RagdollBody *body);
void Ragdoll_DoControllers(const cpose_t *pose, const DObj *obj, int *partBits);

//t6/code/src_noserver/ragdoll/ragdoll_quat.cpp
void Ragdoll_QuatMul(const vec4_t *qa, const vec4_t *qb, vec4_t *dest);
void Ragdoll_QuatInverse(const vec4_t *src, vec4_t *dest);
void Ragdoll_QuatPointRotate(const vec3_t *p, const vec4_t *q, vec3_t *dest);
void Ragdoll_Mat33ToQuat(const vec3_t *axis, vec4_t *quat);
void Ragdoll_QuatToAxisAngle(const vec4_t *quat, vec3_t *axisAngle);
void Ragdoll_QuatLerp(const vec4_t *qa, const vec4_t *qb, const float t, vec4_t *dest);
void Ragdoll_QuatMulInvSecond(const vec4_t *qa, const vec4_t *qb, vec4_t *dest);

//t6/code/src_noserver/ragdoll/ragdoll_update.cpp
void Ragdoll_CopyMirrorQuat(const vec4_t *src, bool mirror, vec4_t *dest);
bool Ragdoll_GetDObjWorldBoneOriginQuat(;
void Ragdoll_PoseInvAxis(const cpose_t *pose, vec3_t *invAxis);
void Ragdoll_AnimMatToMat43(const DObjAnimMat *mat, vec3_t *out);
void Ragdoll_SnapshotBaseLerpBones(RagdollBody *body, BoneOrientation *snapshot);
void Ragdoll_SnapshotBonePositions(RagdollBody *body, BoneOrientation *boneSnapshot);
void Ragdoll_SetCurrentPoseFromSnapshot(RagdollBody *body, BoneOrientation *snapshot);
char Ragdoll_ValidateBodyObj(RagdollBody *body);
void Ragdoll_DestroyPhysObjs(RagdollBody *body);
void Ragdoll_SnapshotBaseLerpOffsets(RagdollBody *body);
void Ragdoll_RemoveBodyPhysics(RagdollBody *body);
char Ragdoll_RebindBody(int ragdollHandle);
bool Ragdoll_ValidatePrecalcBoneDef(RagdollDef *def, BoneDef *bone);
void Ragdoll_Launch(;
void Ragdoll_SetInitialVelocities(RagdollBody *body);
void Ragdoll_EstimateInitialVelocities(RagdollBody *body);
void Ragdoll_Attach(;
bool Ragdoll_BoneTrace(trace_t *trace, trace_t *revTrace, const vec3_t *start, const vec3_t *end);
void Ragdoll_PrintTunnelFail(RagdollBody *body);
void Ragdoll_DebugRender(RagdollBody *body);
bool Ragdoll_CheckIdle(RagdollBody *body, int msec);
char Ragdoll_EnterDead(RagdollBody *body);
char Ragdoll_ExitDead(RagdollBody *body);
char Ragdoll_ExitDObjWait(RagdollBody *body, RagdollBodyState prevState, RagdollBodyState curState);
char Ragdoll_BodyNewState(RagdollBody *body, RagdollBodyState state);
void Ragdoll_BodyUpdate(int msec, RagdollBody *body);
void Ragdoll_SnapshotAnimOrientations(RagdollBody *body, BoneOrientation *snapshot);
bool Ragdoll_CreatePhysObj(RagdollBody *body, BoneDef *boneDef, Bone *bone);
bool Ragdoll_CreatePhysJoints(RagdollBody *body);
char Ragdoll_CreatePhysObjs(RagdollBody *body);
bool Ragdoll_CreateBodyPhysics(RagdollBody *body);
void Ragdoll_LaunchUpdate(RagdollBody *body);
;
char Ragdoll_EnterTunnelTest(RagdollBody *body);
void Ragdoll_UpdateVelocityCapture(RagdollBody *body);
void Ragdoll_UpdateFriction(RagdollBody *body);
char Ragdoll_ExitIdle(RagdollBody *body, RagdollBodyState curState, RagdollBodyState newState);
// char Ragdoll_EnterIdle@<al>(RagdollBody *body);
void Ragdoll_UpdateDObjWait(RagdollBody *body);
char Ragdoll_EnterDobjWait(RagdollBody *body);
// void Ragdoll_UpdateRunning(int a1@<edx>, RagdollBody *a2@<ecx>, RagdollBody *body);
void Ragdoll_Update(int msec);
void Ragdoll_RemoveConstraintsForRope(int rope_id);
// phys_free_list<RagdollBody>::T_internal_base *Ragdoll_GetRBForBone(int entnum, unsigned int boneName);
void Ragdoll_ExplosionEvent(;
void Ragdoll_JetThrustEvent(;

