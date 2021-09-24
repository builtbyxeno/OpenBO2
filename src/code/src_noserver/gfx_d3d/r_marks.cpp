#include "types.h"

/*
==============
R_ChopPolyBehindPlane
==============
*/
int R_ChopPolyBehindPlane(int inPointCount, const FxModelMarkPoint *inPoints, FxModelMarkPoint *outPoints, const vec4_t *plane)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ChopWorldPolyBehindPlane
==============
*/
int R_ChopWorldPolyBehindPlane(int inPointCount, const FxWorldMarkPoint *inPoints, FxWorldMarkPoint *outPoints, const vec4_t *plane, float epsilon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_Mark_MaterialAllowsMarks
==============
*/
bool R_Mark_MaterialAllowsMarks(const Material *markReceiverMaterialHandle, const Material *markMaterialHandle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AllowMarks
==============
*/
BOOL R_AllowMarks()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AABBTreeBoxSurfaces_r
==============
*/
void R_AABBTreeBoxSurfaces_r(GfxAabbTree *treeEA, const vec3_t *mins, const vec3_t *maxs, int (*allowSurf)(int, void *), void *callbackContext, GfxSurface **surfList, unsigned int surfListSize, unsigned int *surfCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AABBTreeBoxSurfacesTwoLists_r
==============
*/
void R_AABBTreeBoxSurfacesTwoLists_r(GfxAabbTree *treeEA, const vec3_t *mins, const vec3_t *maxs, int (**allowSurf)(int, void *), void *callbackContext, GfxSurface ***surfLists, unsigned int surfListSize, unsigned int *surfCounts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddStaticModelToList
==============
*/
void R_AddStaticModelToList(int smodelIndex, unsigned __int16 *smodelList, int *smodelCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AABBTreeBoxStaticModels_r
==============
*/
void R_AABBTreeBoxStaticModels_r(GfxAabbTree *treeEA, const vec3_t *mins, const vec3_t *maxs, int (*allowSModel)(int), unsigned __int16 *smodelList, int smodelListSize, int *smodelCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AABBTreeFrustumSurfaces_r
==============
*/
void R_AABBTreeFrustumSurfaces_r(GfxAabbTree *treeEA, const vec3_t *mins, const vec3_t *maxs, const vec4_t *planes, unsigned int numPlanes, int (*allowSurf)(int), GfxSurface **surfList, int surfListSize, int *surfCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AABBTreeFrustumStaticModels_r
==============
*/
void R_AABBTreeFrustumStaticModels_r(int *a1, GfxAabbTree *treeEA, const vec3_t *mins, const vec3_t *maxs, const vec4_t *planes, unsigned int numPlanes, int (*allowSModel)(int), unsigned __int16 *smodelList, int smodelListSize, int *smodelCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CellBoxSurfaces
==============
*/
void R_CellBoxSurfaces(int cellIndex, const vec3_t *mins, const vec3_t *maxs, int (*allowSurf)(int, void *), void *callbackContext, GfxSurface **surfList, unsigned int surfListSize, unsigned int *surfCount, unsigned __int8 *cellBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CellBoxSurfacesTwoLists
==============
*/
void R_CellBoxSurfacesTwoLists(int cellIndex, const vec3_t *mins, const vec3_t *maxs, int (**allowSurf)(int, void *), void *callbackContext, GfxSurface ***surfLists, unsigned int surfListSize, unsigned int *surfCounts, unsigned __int8 *cellBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_BoxSurfaces_r
==============
*/
void __cdecl R_BoxSurfaces_r(mnode_t *node, const vec3_t *mins, const vec3_t *maxs, int (__cdecl **allowSurf)(int, void *), void *callbackContext, GfxSurface ***surfLists, unsigned int surfListSize, unsigned int *surfCounts, unsigned int listCount, unsigned __int8 *cellBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_BoxStaticModels_r
==============
*/
void R_BoxStaticModels_r(mnode_t *node, const vec3_t *mins, const vec3_t *maxs, int (*allowSModel)(int), unsigned __int16 *smodelList, int smodelListSize, int *smodelCount, unsigned __int8 *cellBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FrustumSurfaces_r
==============
*/
void R_FrustumSurfaces_r(mnode_t *node, const vec3_t *mins, const vec3_t *maxs, const vec4_t *planes, unsigned int numPlanes, int (*allowSurf)(int), GfxSurface **surfList, int surfListSize, int *surfCount, unsigned __int8 *cellBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FrustumStaticModels_r
==============
*/
void R_FrustumStaticModels_r(mnode_t *node, const vec3_t *mins, const vec3_t *maxs, const vec4_t *planes, unsigned int numPlanes, int (*allowSModel)(int), unsigned __int16 *smodelList, int smodelListSize, int *smodelCount, unsigned __int8 *cellBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_BoxSurfaces
==============
*/
void R_BoxSurfaces(int a1, const vec3_t *mins, const vec3_t *maxs, int (**allowSurf)(int, void *), void *callbackContext, GfxSurface ***surfLists, unsigned int surfListSize, unsigned int *surfCounts, unsigned int listCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_BoxStaticModels
==============
*/
int R_BoxStaticModels(int a1, const vec3_t *mins, const vec3_t *maxs, int (*allowSModel)(int), unsigned __int16 *smodelList, int smodelListSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_FrustumSurfaces
==============
*/
int R_FrustumSurfaces(int a1, const vec3_t *mins, const vec3_t *maxs, const vec4_t *planes, unsigned int numPlanes, int (*allowSurf)(int), GfxSurface **surfList, int surfListSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_FrustumStaticModels
==============
*/
int R_FrustumStaticModels(int a1, const vec3_t *mins, const vec3_t *maxs, const vec4_t *planes, unsigned int numPlanes, int (*allowSModel)(int), unsigned __int16 *smodelList, int smodelListSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_GetMarkFragmentClipPlanes
==============
*/
void R_GetMarkFragmentClipPlanes(const vec3_t *origin, const vec3_t *axis, float radius, MarkClipPlaneSet *clipPlanes)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_MarkFragments_BrushSurface
==============
*/
bool R_MarkFragments_BrushSurface(MarkInfo *markInfo, GfxMarkContext *markContext, const MarkClipPlaneSet *clipPlanes, const vec3_t *markDir, const GfxSurface *remoteSurface, bool *anyMarks)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_MarkFragments_WorldBrushes
==============
*/
bool R_MarkFragments_WorldBrushes(MarkInfo *markInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_Mark_TransformClipPlanes
==============
*/
void R_Mark_TransformClipPlanes(const MarkClipPlaneSet *inClipPlanes, vec3_t *matrix, MarkClipPlaneSet *outClipPlanes)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_MarkFragments_EntBrushes
==============
*/
char R_MarkFragments_EntBrushes(MarkInfo *markInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_MarkFragments_Glass
==============
*/
bool R_MarkFragments_Glass(MarkInfo *markInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_MarkUtil_GetDObjAnimMatAndHideParts
==============
*/
void R_MarkUtil_GetDObjAnimMatAndHideParts(const DObj *dobj, const cpose_t *pose, const DObjAnimMat **outBoneMtxList, unsigned int *outHidePartBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_MarkFragments_Begin
==============
*/
void __cdecl R_MarkFragments_Begin(MarkInfo *markInfo, MarkFragmentsAgainstEnum markAgainst, const vec3_t *origin, const vec3_t *axis, float radius, const vec3_t *viewOffset, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_MarkFragments_AddDObj
==============
*/
bool R_MarkFragments_AddDObj(MarkInfo *markInfo, DObj *dObj, cpose_t *pose, unsigned __int16 entityIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_MarkFragments_AddViewModelDObj
==============
*/
char R_MarkFragments_AddViewModelDObj(MarkInfo *markInfo, DObj *dObj, cpose_t *pose)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_MarkFragments_AddBModel
==============
*/
bool R_MarkFragments_AddBModel(MarkInfo *markInfo, GfxBrushModel *brushModel, cpose_t *pose, unsigned __int16 entityIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_MarkFragments_XModelSurface_Basic
==============
*/
char R_MarkFragments_XModelSurface_Basic(GfxMarkContext *a1, __int64 *a2, float surfaceEA, const XSurface *modelAxis, const vec3_t *modelOrigin, const vec3_t *a6)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_MarkFragments_EntirelyRigidXModel
==============
*/
bool R_MarkFragments_EntirelyRigidXModel(MarkInfo *markInfo, const XModel *xmodelEA, const vec3_t *modelAxis, const vec3_t *modelOrigin, float modelScale, GfxMarkContext *markContext)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_MarkFragments_AnimatedXModel_VertList
==============
*/
bool R_MarkFragments_AnimatedXModel_VertList(GfxMarkContext *markContext, XSurface *surfaceEA)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_MarkFragments_AnimatedXModel
==============
*/
bool R_MarkFragments_AnimatedXModel(MarkInfo *markInfo, const XModel *model, const unsigned int *hidePartBits, int boneIndex, const DObjAnimMat *boneMtxList, int boneCount, GfxMarkContext *markContext)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_MarkFragments_SceneDObjs
==============
*/
bool R_MarkFragments_SceneDObjs(MarkInfo *markInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_MarkFragments_ViewmodelDObjs
==============
*/
bool R_MarkFragments_ViewmodelDObjs(MarkInfo *markInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_MarkFragments_StaticModels
==============
*/
bool R_MarkFragments_StaticModels(MarkInfo *markInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_MarkFragments_Models
==============
*/
bool R_MarkFragments_Models(MarkInfo *markInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_MarkFragments_Go
==============
*/
void R_MarkFragments_Go(MarkInfo *markInfo, void (*callback)(void *, int, FxMarkTri *, int, FxMarkPoint *, const vec3_t *, const vec3_t *), void *callbackContext, int maxTris, FxMarkTri *tris, int maxPoints, FxMarkPoint *points)
{
	UNIMPLEMENTED(__FUNCTION__);
}

