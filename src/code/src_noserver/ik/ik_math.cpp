#include "types.h"
#include "functions.h"

/*
==============
ikMatrixIdentity44
==============
*/
void ikMatrixIdentity44(vec4_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatrixSet44
==============
*/
void MatrixSet44(vec4_t *out, const vec3_t *origin, const vec3_t *axis, float scale)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ikQuatTransToMatrix44
==============
*/
void ikQuatTransToMatrix44(const float *quat, const float *trans, vec4_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ikAxisToQuat
==============
*/
void ikAxisToQuat(const vec3_t *mat, vec4_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IK_FlipHack
==============
*/
void IK_FlipHack(vec4_t *mat)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ikNormalizedMatrixAssert_func
==============
*/
void ikNormalizedMatrixAssert_func(vec4_t *mat)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ikQuatToAxis
==============
*/
void ikQuatToAxis(const vec4_t *quat, vec3_t *axis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ikMatrix44ToQuatTrans
==============
*/
void ikMatrix44ToQuatTrans(vec4_t *mat, vec4_t *quat, vec3_t *trans)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ikCalcBoneModelMatrix_r
==============
*/
void ikCalcBoneModelMatrix_r(int a1, IKState *ikState, int boneNum, float *inMatArray, vec4_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ikCalcBoneModelMatrix
==============
*/
void ikCalcBoneModelMatrix()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ikMap2DTo3D
==============
*/
void ikMap2DTo3D(int a1, float UpperLimbLength, float SinUpper, float CosUpper, float SinLower, float CosLower, const vec3_t *ModelBaseJoint, const vec3_t *ModelTargetDir, const vec3_t *ModelMidJointDir, float sinTwist, float cosTwist, vec4_t *UpperLocalToModel, vec4_t *LowerLocalToModel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ikSolveLegJoint
==============
*/
void ikSolveLegJoint(int a1, IKState *ikState, IKJointBones *jointBones, IKJointVars *jointVars, vec3_t *footPos, vec4_t *outParentMat, vec4_t *outJointMat, bool flipHack)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ikSolveArmJoint
==============
*/
void ikSolveArmJoint(int a1, IKState *ikState, IKJointBones *jointBones, IKJointVars *jointVars, vec3_t *handPos, vec4_t *outParentMat, vec4_t *outJointMat, bool flipHack)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ikRotateBone
==============
*/
void ikRotateBone(int a1, IKState *ikState, IKBoneNames boneName, vec3_t *rot, bool local)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ikMatrixLerp44
==============
*/
void ikMatrixLerp44(vec4_t *from, vec4_t *to, float lerp, vec4_t *res)
{
	UNIMPLEMENTED(__FUNCTION__);
}

