#include "types.h"
#include "functions.h"

/*
==============
XDoll_GetUnusedBody
==============
*/
int XDoll_GetUnusedBody()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XDoll_SnapshotBonePositions
==============
*/
void XDoll_SnapshotBonePositions(XDollBody *body, XDollBoneOrientation *boneSnapshot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XDoll_DestroyConstraint
==============
*/
void XDoll_DestroyConstraint(XDoll_ConstraintInfo *cinfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XDoll_CreateHingeConstraint
==============
*/
rigid_body_constraint_hinge *XDoll_CreateHingeConstraint(rigid_body *rb1, rigid_body *rb2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XDoll_CreatePointConstraint
==============
*/
rigid_body_constraint_point *XDoll_CreatePointConstraint(rigid_body *rb1, rigid_body *rb2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XDoll_CreateActuatorConstraint
==============
*/
rigid_body_constraint_angular_actuator *XDoll_CreateActuatorConstraint(rigid_body *rb1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XDoll_Activate
==============
*/
bool XDoll_Activate(const PhysConstraints *constraintsDef, int health)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XDoll_SetCollides
==============
*/
void XDoll_SetCollides(XDollBone *bone, bool collides)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XDoll_SetCollides
==============
*/
void XDoll_SetCollides(XDollBody *body, bool collides)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XDoll_UpdateTimers
==============
*/
void XDoll_UpdateTimers(XDollBody *body, int msec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XDoll_UpdateStability
==============
*/
void XDoll_UpdateStability(XDollBody *body, int msec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XDoll_GetRigidBody
==============
*/
rigid_body *XDoll_GetRigidBody(XDollBody *body, const char *bone_name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XDoll_DestroyXDoll
==============
*/
void XDoll_DestroyXDoll(XDollBody *body)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XDoll_HandleBody
==============
*/
XDollBody *XDoll_HandleBody(int xdollHandle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XDoll_DoControllers
==============
*/
void XDoll_DoControllers(int xdoll_handle, int *partBits, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XDoll_SetCollides
==============
*/
void XDoll_SetCollides(int xdoll_handle, bool collides)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XDoll_CreatePhysObj
==============
*/
bool XDoll_CreatePhysObj(XDollBody *body, XDollBone *bone, XModel *model, const cpose_t *pose, PhysPreset *physPreset, bool collide)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XDoll_Update
==============
*/
void XDoll_Update(int msec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XDoll_CreateConstraint
==============
*/
void XDoll_CreateConstraint(const PhysConstraint *constraint)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XDoll_DestroyXDoll
==============
*/
void XDoll_DestroyXDoll(int xdoll_handle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XDoll_CreateXDollForBoneLaunch
==============
*/
int XDoll_CreateXDollForBoneLaunch(LocalClientNum_t localClientNum, int entity_index, int piece_index, int bone_name, PhysPreset *physPreset)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XDoll_CreateXDollForConstraints
==============
*/
int XDoll_CreateXDollForConstraints(LocalClientNum_t localClientNum, int entity_index, int piece_index, int health, PhysConstraints *constraints, PhysPreset *physPreset)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XDoll_UpdateHealth
==============
*/
void XDoll_UpdateHealth(int xdoll_handle, int health)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XDoll_ApplyForce
==============
*/
void __cdecl XDoll_ApplyForce(int xdoll_handle, const vec3_t *hitp, const vec3_t *hitd, const int mod)
{
	UNIMPLEMENTED(__FUNCTION__);
}

