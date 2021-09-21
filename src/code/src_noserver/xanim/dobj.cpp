#include "types.h"
#include "functions.h"

/*
==============
DObjInit
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
DObjShutdown
==============
*/
void DObjShutdown()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjDumpCreationInfo
==============
*/
void DObjDumpCreationInfo(DObjModel_s *dobjModels, unsigned int numModels)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjGetHierarchyBits
==============
*/
void DObjGetHierarchyBits(const DObj *obj, int boneIndex, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjSkelIsBoneUpToDate
==============
*/
BOOL DObjSkelIsBoneUpToDate(DObj *obj, int boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjComputeBounds
==============
*/
void DObjComputeBounds(DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjCalcBounds
==============
*/
void DObjCalcBounds(DObj *dobj, vec3_t *mins, vec3_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjSkelClear
==============
*/
void DObjSkelClear(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjGetLocalClientIndex
==============
*/
LocalClientNum_t DObjGetLocalClientIndex(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	LocalClientNum_t tmp;
	return tmp;
}

/*
==============
DObjGetBounds
==============
*/
void DObjGetBounds(const DObj *obj, vec3_t *mins, vec3_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjPhysicsGetBounds
==============
*/
void DObjPhysicsGetBounds(const DObj *obj, vec3_t *mins, vec3_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjGetRadius
==============
*/
double DObjGetRadius(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjGetPhysPreset
==============
*/
PhysPreset *DObjGetPhysPreset(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DObjGetName
==============
*/
const char *DObjGetName(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DObjGetBoneName
==============
*/
const char *DObjGetBoneName(const DObj *obj, int boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DObjGetModelParentBoneName
==============
*/
const char *DObjGetModelParentBoneName(const DObj *obj, int modelIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DObjGetTree
==============
*/
XAnimTree_s *DObjGetTree(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DObjBad
==============
*/
int DObjBad(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjTracelinePartBits
==============
*/
void DObjTracelinePartBits(DObj *obj, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjGeomTraceline
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
DObjGeomTracelinePartBits
==============
*/
void DObjGeomTracelinePartBits(DObj *obj, int contentmask, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjHasContents
==============
*/
int DObjHasContents(DObj *obj, int contentmask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjGetContents
==============
*/
int DObjGetContents(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjHasCollmap
==============
*/
BOOL DObjHasCollmap(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjGetCollmap
==============
*/
PhysGeomList *DObjGetCollmap(DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DObjGetXModel
==============
*/
XModel *DObjGetXModel(DObj *obj, int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DObjSetLocalBoneIndex
==============
*/
int DObjSetLocalBoneIndex(DObj *obj, int *partBits, int boneIndex, const vec3_t *trans, const vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjGetModelBoneIndex
==============
*/
int DObjGetModelBoneIndex(const DObj *obj, const char *modelName, unsigned int name, unsigned __int8 *index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjGetBasePoseMatrix
==============
*/
void DObjGetBasePoseMatrix(const DObj *obj, unsigned __int8 boneIndex, DObjAnimMat *outMat)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjSetHidePartBits
==============
*/
void DObjSetHidePartBits(DObj *obj, const unsigned int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjHasFlag
==============
*/
BOOL DObjHasFlag(const DObj *obj, unsigned __int8 flag)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjSetFlag
==============
*/
void DObjSetFlag(DObj *obj, unsigned __int8 flag, int val)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjHasIKActiveFlag
==============
*/
int DObjHasIKActiveFlag(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjSetIKActiveFlag
==============
*/
void DObjSetIKActiveFlag(DObj *obj, int val)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjSetIKBypassFlag
==============
*/
void DObjSetIKBypassFlag(DObj *obj, int val)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjSetIKState
==============
*/
void DObjSetIKState(DObj *obj, const unsigned __int8 *pIKState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjDumpInfo
==============
*/
void DObjDumpInfo(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjCreateDuplicateParts
==============
*/
void DObjCreateDuplicateParts(DObj *obj, DObjModel_s *dobjModels, unsigned int numModels)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjFree
==============
*/
void DObjFree(DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjIsServer
==============
*/
BOOL DObjIsServer(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjIsLocalPlayer
==============
*/
int DObjIsLocalPlayer(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjIsPlayerShadow
==============
*/
int DObjIsPlayerShadow(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjIsLeftHandGripIKActive
==============
*/
BOOL DObjIsLeftHandGripIKActive(const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjTraceline
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
DObjSetTree
==============
*/
void DObjSetTree(DObj *obj, XAnimTree_s *tree)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjCreate
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
DObjCreateExt
==============
*/
void DObjCreateExt(DObjModel_s *dobjModels, unsigned int numModels, XAnimTree_s *tree, void *buf, unsigned int entnum, bool isServer, bool isLocalPlayer, LocalClientNum_t localClientIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjGetModelBoneIndex
==============
*/
int DObjGetModelBoneIndex(const DObj *obj, int model_index, unsigned int name, unsigned __int8 *index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

