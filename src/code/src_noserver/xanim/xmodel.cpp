#include "types.h"
#include "functions.h"

/*
==============
XModelBad
==============
*/
BOOL XModelBad(const XModel *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TRACK_xmodel
==============
*/
void TRACK_xmodel()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XModelReleaseResources
==============
*/
void XModelReleaseResources(XModel *model)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XModelPartsFree
==============
*/
void XModelPartsFree(XModelPartsLoad *modelParts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XModelMakeDefault
==============
*/
void XModelMakeDefault(XModel *model)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XModelPartsFindData
==============
*/
XModelPartsLoad *XModelPartsFindData(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XModelPartsSetData
==============
*/
void XModelPartsSetData(const char *name, XModelPartsLoad *modelParts, void *(*Alloc)(int))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XModelPrecache_LoadObj
==============
*/
XModel *XModelPrecache_LoadObj(const char *name, void *(*Alloc)(int), void *(*AllocColl)(int))
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XModelPrecache_FastFile
==============
*/
XModel *XModelPrecache_FastFile(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XModelPrecache
==============
*/
XModel *XModelPrecache()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XModelBoneNames
==============
*/
unsigned __int16 *XModelBoneNames(XModel *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XModelGetRadius
==============
*/
double XModelGetRadius(const XModel *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XModelGetBounds
==============
*/
void XModelGetBounds(const XModel *model, vec3_t *mins, vec3_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XModelRenderString
==============
*/
void XModelRenderString(const vec3_t *pos, const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XModelTraceLineAnimated
==============
*/
int XModelTraceLineAnimated(unsigned int a1, const DObj *obj, unsigned int modelIndex, int baseBoneIndex, trace_t *results, const DObjAnimMat *boneMtxList, vec3_t *localStart, vec3_t *localEnd, int contentmask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XModelTraceLineAnimatedPartBits
==============
*/
void XModelTraceLineAnimatedPartBits(const DObj *obj, unsigned int modelIndex, int baseBoneIndex, int contentmask, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XSurfaceVisitTrianglesInAabb_ConvertAabb
==============
*/
void XSurfaceVisitTrianglesInAabb_ConvertAabb(const XSurfaceCollisionTree *tree, const vec3_t *aabbMins, const vec3_t *aabbMaxs, int *mins, int *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XSurfaceVisitTrianglesInAabb_ProcessVertices
==============
*/
bool XSurfaceVisitTrianglesInAabb_ProcessVertices(XSurfaceGetTriCandidatesLocals *locals)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XSurfaceVisitTrianglesInAabb_ProcessTriangles
==============
*/
bool XSurfaceVisitTrianglesInAabb_ProcessTriangles(XSurfaceGetTriCandidatesLocals *locals)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XModelTraceLine
==============
*/
int XModelTraceLine(int a1, const XModel *model, trace_t *results, const vec3_t *localStart, const vec3_t *localEnd, int contentmask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XSurfaceVisitTrianglesInAabb_ProcessLeaf
==============
*/
bool XSurfaceVisitTrianglesInAabb_ProcessLeaf(XSurfaceGetTriCandidatesLocals *locals)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XSurfaceVisitTrianglesInAabb_ProcessNode
==============
*/
char XSurfaceVisitTrianglesInAabb_ProcessNode(XSurfaceGetTriCandidatesLocals *locals)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XSurfaceVisitTrianglesInAabb
==============
*/
char XSurfaceVisitTrianglesInAabb(const XSurface *surface, unsigned int vertListIndex, const vec3_t *aabbMins, const vec3_t *aabbMaxs, bool (*visitorFunc)(void *, const unsigned __int8 **, const unsigned __int8 **), void *visitorContext)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

