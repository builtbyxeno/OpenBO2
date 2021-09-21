#include "types.h"
#include "functions.h"

/*
==============
Ragdoll_CopyMirrorQuat
==============
*/
void Ragdoll_CopyMirrorQuat(const vec4_t *src, bool mirror, vec4_t *dest)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_GetDObjWorldBoneOriginQuat
==============
*/
bool Ragdoll_GetDObjWorldBoneOriginQuat(LocalClientNum_t localClientNum, const cpose_t *pose, DObj *obj, unsigned __int8 boneIndex, vec3_t *origin, vec4_t *quat)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Ragdoll_PoseInvAxis
==============
*/
void Ragdoll_PoseInvAxis(const cpose_t *pose, vec3_t *invAxis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_AnimMatToMat43
==============
*/
void Ragdoll_AnimMatToMat43(const DObjAnimMat *mat, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_SnapshotBaseLerpBones
==============
*/
void Ragdoll_SnapshotBaseLerpBones(RagdollBody *body, BoneOrientation *snapshot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_SnapshotBonePositions
==============
*/
void Ragdoll_SnapshotBonePositions(RagdollBody *body, BoneOrientation *boneSnapshot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_SetCurrentPoseFromSnapshot
==============
*/
void Ragdoll_SetCurrentPoseFromSnapshot(RagdollBody *body, BoneOrientation *snapshot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_ValidateBodyObj
==============
*/
char Ragdoll_ValidateBodyObj(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Ragdoll_DestroyPhysObjs
==============
*/
void Ragdoll_DestroyPhysObjs(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_SnapshotBaseLerpOffsets
==============
*/
void Ragdoll_SnapshotBaseLerpOffsets(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_RemoveBodyPhysics
==============
*/
void Ragdoll_RemoveBodyPhysics(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_RebindBody
==============
*/
char Ragdoll_RebindBody(int ragdollHandle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Ragdoll_ValidatePrecalcBoneDef
==============
*/
bool Ragdoll_ValidatePrecalcBoneDef(RagdollDef *def, BoneDef *bone)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Ragdoll_Launch
==============
*/
void Ragdoll_Launch(const LocalClientNum_t localClientNum, int ragdollHandle, const vec3_t *force, const hitLocation_t hitloc)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_SetInitialVelocities
==============
*/
void Ragdoll_SetInitialVelocities(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_EstimateInitialVelocities
==============
*/
void Ragdoll_EstimateInitialVelocities(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_Attach
==============
*/
void Ragdoll_Attach(const LocalClientNum_t localClientNum, int ragdollHandle, int attachEnt, const hitLocation_t hitloc)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_BoneTrace
==============
*/
bool Ragdoll_BoneTrace(trace_t *trace, trace_t *revTrace, const vec3_t *start, const vec3_t *end)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Ragdoll_PrintTunnelFail
==============
*/
void Ragdoll_PrintTunnelFail(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_DebugRender
==============
*/
void Ragdoll_DebugRender(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_CheckIdle
==============
*/
bool Ragdoll_CheckIdle(RagdollBody *body, int msec)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Ragdoll_EnterDead
==============
*/
char Ragdoll_EnterDead(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Ragdoll_ExitDead
==============
*/
char Ragdoll_ExitDead(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Ragdoll_ExitDObjWait
==============
*/
char Ragdoll_ExitDObjWait(RagdollBody *body, RagdollBodyState prevState, RagdollBodyState curState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Ragdoll_BodyNewState
==============
*/
char Ragdoll_BodyNewState(RagdollBody *body, RagdollBodyState state)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Ragdoll_BodyUpdate
==============
*/
void Ragdoll_BodyUpdate(int msec, RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_SnapshotAnimOrientations
==============
*/
void Ragdoll_SnapshotAnimOrientations(RagdollBody *body, BoneOrientation *snapshot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_CreatePhysObj
==============
*/
bool Ragdoll_CreatePhysObj(RagdollBody *body, BoneDef *boneDef, Bone *bone)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Ragdoll_CreatePhysJoints
==============
*/
bool Ragdoll_CreatePhysJoints(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Ragdoll_CreatePhysObjs
==============
*/
char Ragdoll_CreatePhysObjs(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Ragdoll_CreateBodyPhysics
==============
*/
bool Ragdoll_CreateBodyPhysics(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Ragdoll_LaunchUpdate
==============
*/
void Ragdoll_LaunchUpdate(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_TunnelTest
==============
*/
bool Ragdoll_TunnelTest(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Ragdoll_EnterTunnelTest
==============
*/
char Ragdoll_EnterTunnelTest(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Ragdoll_UpdateVelocityCapture
==============
*/
void Ragdoll_UpdateVelocityCapture(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_UpdateFriction
==============
*/
void Ragdoll_UpdateFriction(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_ExitIdle
==============
*/
char Ragdoll_ExitIdle(RagdollBody *body, RagdollBodyState curState, RagdollBodyState newState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Ragdoll_EnterIdle
==============
*/
char Ragdoll_EnterIdle(int a1, RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Ragdoll_UpdateDObjWait
==============
*/
void Ragdoll_UpdateDObjWait(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_EnterDobjWait
==============
*/
char Ragdoll_EnterDobjWait(RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Ragdoll_UpdateRunning
==============
*/
void Ragdoll_UpdateRunning(int a1, RagdollBody *a2, RagdollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_Update
==============
*/
void Ragdoll_Update(int msec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_RemoveConstraintsForRope
==============
*/
void Ragdoll_RemoveConstraintsForRope(int rope_id)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_GetRBForBone
==============
*/
/*phys_free_list<RagdollBody>::T_internal_base *Ragdoll_GetRBForBone(int entnum, unsigned int boneName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
Ragdoll_ExplosionEvent
==============
*/
void Ragdoll_ExplosionEvent(const char *a1, const char *a2, LocalClientNum_t localClientNum, bool isCylinder, const vec3_t *origin, float innerRadius, float outerRadius, const vec3_t *impulse, float inScale)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Ragdoll_JetThrustEvent
==============
*/
void Ragdoll_JetThrustEvent(LocalClientNum_t localClientNum, const vec3_t *origin, const vec3_t *forward, float outerRadius, float dotLimit)
{
	UNIMPLEMENTED(__FUNCTION__);
}

