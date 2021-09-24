#include "types.h"

/*
==============
IK_AllocateLocalClientMemory
==============
*/
void IK_AllocateLocalClientMemory(void *ikStatesBuf, int localClientIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IK_InitSystem
==============
*/
void IK_InitSystem()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IK_IsCalcBone
==============
*/
BOOL IK_IsCalcBone(IKState *ikState, int ikBoneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IK_UpdateTimeAll
==============
*/
void IK_UpdateTimeAll(int time, int localClientIndex, bool inViewer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IK_ResetTime
==============
*/
void IK_ResetTime()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IK_UpdateDvarValues
==============
*/
void IK_UpdateDvarValues(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IK_UpdateLayerLerps
==============
*/
void IK_UpdateLayerLerps(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IK_UpdateStatusFunctions
==============
*/
void IK_UpdateStatusFunctions(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IK_GetBoneParents
==============
*/
IKBoneNames *IK_GetBoneParents(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
IK_GetJoints
==============
*/
IKJointBones *IK_GetJoints(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
IK_GetEssentialBones
==============
*/
bool *IK_GetEssentialBones(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
IK_InitializeIKState
==============
*/
void IK_InitializeIKState(IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IK_CreateIKForEntity
==============
*/
IKState *IK_CreateIKForEntity(int entityNum, unsigned __int8 *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
IK_GetJointVars
==============
*/
void IK_GetJointVars(int a1, IKState *ikState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IK_GetIKStateForEntity
==============
*/
IKState *IK_GetIKStateForEntity(int entityNum, unsigned __int8 *model, bool bScanAll)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
IK_UpdateEntity
==============
*/
void IK_UpdateEntity(int entityNum, unsigned __int8 *model, bool isLocalBones, int *calcBoneBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

