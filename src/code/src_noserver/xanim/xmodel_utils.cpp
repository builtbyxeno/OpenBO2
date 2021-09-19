#include "types.h"
#include "functions.h"

/*
==============
XModelGetName
==============
*/
const char *XModelGetName(const XModel *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XModelGetSurfaces
==============
*/
int XModelGetSurfaces(const XModel *model, XSurface **surfaces, int submodel)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XModelGetLodInfo
==============
*/
XModelLodInfo *XModelGetLodInfo(const XModel *model, int lod)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XModelGetSurfCount
==============
*/
unsigned int XModelGetSurfCount(const XModel *model, int lod)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XModelGetSkins
==============
*/
Material **XModelGetSkins(const XModel *model, int lod)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XModelGetLodRampType
==============
*/
XModelLodRampType XModelGetLodRampType(const XModel *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	XModelLodRampType tmp;
	return tmp;
}

/*
==============
XModelGetNumLods
==============
*/
int XModelGetNumLods(const XModel *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XModelGetLodOutDist
==============
*/
double XModelGetLodOutDist(const XModel *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XModelNumBones
==============
*/
LocalClientNum_t XModelNumBones(const cpose_t *pose)
{
	UNIMPLEMENTED(__FUNCTION__);
	LocalClientNum_t tmp;
	return tmp;
}

/*
==============
XModelGetBoneIndex
==============
*/
int XModelGetBoneIndex(const XModel *model, unsigned int name, unsigned int offset, unsigned __int8 *index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XModelGetParentBoneName
==============
*/
int XModelGetParentBoneName(const XModel *model, unsigned int name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XModelGetBasePose
==============
*/
DObjAnimMat *XModelGetBasePose(const XModel *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XModelGetLodForDist_Internal
==============
*/
int XModelGetLodForDist_Internal(const XModel *model, float dist)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XModelGetLodForDist
==============
*/
int XModelGetLodForDist(const XModel *model, float adjustedDist, float baseDist, int noLodCullOut)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XModelSetTestLods
==============
*/
void XModelSetTestLods(int lodLevel, float dist)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XModelGetContents
==============
*/
int XModelGetContents(const XModel *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XModelHasCollmap
==============
*/
BOOL XModelHasCollmap(const XModel *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XModelHasCollision
==============
*/
BOOL XModelHasCollision(const XModel *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XModelGetCollmap
==============
*/
PhysGeomList *XModelGetCollmap(const XModel *model, int collMapIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XModelGetCollmapForBoneIndex
==============
*/
PhysGeomList *XModelGetCollmapForBoneIndex(const XModel *model, int boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XModelGetBoneIndex
==============
*/
int XModelGetBoneIndex(const XModel *model, unsigned int name, unsigned __int8 *index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

