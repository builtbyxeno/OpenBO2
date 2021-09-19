#include "types.h"
#include "functions.h"

/*
==============
DObjGetRotTransArray
==============
*/
DObjAnimMat *DObjGetRotTransArray(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DObjGetRotTransArrayMain
==============
*/
DObjAnimMat *DObjGetRotTransArrayMain(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DObjGetNumModels
==============
*/
int DObjGetNumModels(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjGetEntNum
==============
*/
unsigned __int16 DObjGetEntNum(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjGetSurfaces
==============
*/
int DObjGetSurfaces(const DObj *obj, int *partBits, const char *lods)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjGetBoneInfo
==============
*/
void DObjGetBoneInfo(const DObj *obj, XBoneInfo **boneInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjNumBones
==============
*/
int DObjNumBones(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjGetSetBones
==============
*/
void DObjGetSetBones(const DObj *obj, int *setPartBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjSetRotTransIndex
==============
*/
int DObjSetRotTransIndex(const DObj *obj, const int *partBits, int boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjSetSkelRotTransIndex
==============
*/
char DObjSetSkelRotTransIndex(const DObj *obj, const int *partBits, int boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjGetModel
==============
*/
XModel *DObjGetModel(const DObj *obj, int modelIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DObjHasCollision
==============
*/
int DObjHasCollision(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjGetModelRemote
==============
*/
XModel *DObjGetModelRemote(const DObj *obj, int modelIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DObjSetAngles
==============
*/
void DObjSetAngles(DObjAnimMat *rotTrans, const vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjSetTrans
==============
*/
void DObjSetTrans(DObjAnimMat *rotTrans, const vec3_t *trans)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjCompleteHierarchyBits
==============
*/
void DObjCompleteHierarchyBits(const DObj *obj, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjSetControlRotTransIndex
==============
*/
int DObjSetControlRotTransIndex(const DObj *obj, const int *partBits, int boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjSkelExists
==============
*/
BOOL DObjSkelExists(const DObj *obj, int timeStamp)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjClearSkel
==============
*/
void DObjClearSkel(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjSkelAreBonesUpToDate
==============
*/
int DObjSkelAreBonesUpToDate(const DObj *obj, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjSkelSetSkel
==============
*/
void DObjSkelSetSkel(const DObj *obj, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjGetAllocSkelSize
==============
*/
int DObjGetAllocSkelSize(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjCreateSkel
==============
*/
void DObjCreateSkel(const DObj *obj, char *buf, int timeStamp)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
I_dmaGetDObjSkel
==============
*/
DObjAnimMat *I_dmaGetDObjSkel(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DObjGetHidePartBits
==============
*/
void DObjGetHidePartBits(const DObj *obj, unsigned int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjGetBoneIndex
==============
*/
int DObjGetBoneIndex(const DObj *obj, unsigned int name, unsigned __int8 *index, int modelNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjGetParentBone
==============
*/
int DObjGetParentBone(const DObj *obj, unsigned __int8 childBoneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjGetChildBones
==============
*/
int DObjGetChildBones(const DObj *obj, unsigned __int8 parentBone, unsigned __int8 *children, int maxChildren)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjLock
==============
*/
void DObjLock(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjUnlock
==============
*/
void DObjUnlock(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjIsRecorded
==============
*/
int DObjIsRecorded(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjGetSurfaceData
==============
*/
void DObjGetSurfaceData(const DObj *obj, const vec3_t *origin, const float scale, char *lods)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjGetRootBoneCount
==============
*/
unsigned int DObjGetRootBoneCount(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjSetLocalTagInternal
==============
*/
void DObjSetLocalTagInternal(const DObj *obj, const vec3_t *trans, const vec3_t *angles, int boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjSetControlTagAngles
==============
*/
void DObjSetControlTagAngles(const DObj *obj, int *partBits, unsigned int boneIndex, vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjSetLocalTag
==============
*/
void DObjSetLocalTag(
{
	UNIMPLEMENTED(__FUNCTION__);
}

