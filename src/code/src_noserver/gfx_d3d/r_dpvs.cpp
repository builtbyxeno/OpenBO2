#include "types.h"
#include "functions.h"

/*
==============
DpvsCachedCell::Compare
==============
*/
/*int DpvsCachedCell::Compare(const void *lhs, const void *rhs)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
TRACK_r_dpvs
==============
*/
void TRACK_r_dpvs()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetSidePlaneNormals
==============
*/
void R_GetSidePlaneNormals(const vec3_t *winding, unsigned int vertexCount, vec3_t *normals)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FurthestPointOnWinding
==============
*/
float R_FurthestPointOnWinding(const vec3_t *points, int pointCount, const DpvsPlane *plane)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_NearestPointOnWinding
==============
*/
float R_NearestPointOnWinding(const vec3_t *points, int pointCount, const DpvsPlane *plane)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_FrustumClipPlanes
==============
*/
void R_FrustumClipPlanes(const GfxMatrix *viewProjMtx, const vec4_t *sidePlanes, int sidePlaneCount, DpvsPlane *frustumPlanes)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_PortalAssertMsg
==============
*/
char *R_PortalAssertMsg()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_ProjectPortal
==============
*/
void R_ProjectPortal(int vertexCount, const vec3_t *winding, vec2_t *mins, vec2_t *maxs, DpvsClipChildren *clipChildren)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UnprojectPoint
==============
*/
void R_UnprojectPoint(GfxViewParms *viewParms, const vec2_t *projected, vec4_t *unprojected)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddBevelPlanes
==============
*/
unsigned int R_AddBevelPlanes(DpvsPlane *planes, unsigned int vertexCount, const vec3_t *windingNormals, const vec2_t *mins, const vec2_t *maxs, DpvsForceBevels forceBevels)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_PortalClipPlanes
==============
*/
unsigned int R_PortalClipPlanes(DpvsPlane *planes, unsigned int vertexCount, const vec3_t *winding, DpvsClipChildren *clipChildren)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_PortalClipPlanesNoFrustum
==============
*/
unsigned int R_PortalClipPlanesNoFrustum(DpvsPlane *planes, unsigned int vertexCount, const vec3_t *winding)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_PortalBehindAnyPlane
==============
*/
bool R_PortalBehindAnyPlane(const GfxPortal *portal, const DpvsPlane *planes, int planeCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ChopPortalWinding
==============
*/
const vec3_t *R_ChopPortalWinding(const vec3_t *vertsIn, int *vertexCount, const DpvsPlane *plane, vec3_t *vertsOut)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_GetLightingMask_Box
==============
*/
unsigned int R_GetLightingMask_Box(const GfxLight *visibleLights, int visibleLightCount, const vec4_t *dynamicSpotLightPlanes, const vec3_t *mins, const vec3_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_GetLightingMask_Sphere
==============
*/
unsigned int R_GetLightingMask_Sphere(const GfxLight *visibleLights, int visibleLightCount, const vec4_t *dynamicSpotLightPlanes, const vec3_t *origin, float baseRadius)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AddSceneEntSurfs_SceneDObjs
==============
*/
void R_AddSceneEntSurfs_SceneDObjs(AddSceneEntSurfsCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddSceneEntSurfs_SceneModels
==============
*/
void R_AddSceneEntSurfs_SceneModels(AddSceneEntSurfsCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddSceneEntSurfs_SceneDynEnts
==============
*/
void R_AddSceneEntSurfs_SceneDynEnts(AddSceneEntSurfsCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddSceneEntSurfs_SceneBrush
==============
*/
void R_AddSceneEntSurfs_SceneBrush(AddSceneEntSurfsCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddSceneEntSurfs_SceneGlassBrush
==============
*/
void R_AddSceneEntSurfs_SceneGlassBrush(AddSceneEntSurfsCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddSceneEntSurfs_SceneDynBrush
==============
*/
void R_AddSceneEntSurfs_SceneDynBrush(AddSceneEntSurfsCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitSceneEntDrawSurfs
==============
*/
void R_InitSceneEntDrawSurfs(GfxDrawSurf **drawSurfs, unsigned int drawSurfsByteSize, GfxDrawSurf **lastDrawSurfs, unsigned int lastDrawSurfsByteSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FinishSceneEntDrawSurfs
==============
*/
void R_FinishSceneEntDrawSurfs(GfxDrawSurf **drawSurfs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddAllSceneEntSurfacesCamera
==============
*/
void R_AddAllSceneEntSurfacesCamera(const GfxViewInfo *viewInfo, GfxDrawSurf **drawSurfs, GfxDrawSurf **lastDrawSurfs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddAllSceneEntSurfacesRangeSunShadow
==============
*/
void R_AddAllSceneEntSurfacesRangeSunShadow(unsigned int partitionIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddAllSceneEntSurfacesSunShadow
==============
*/
void R_AddAllSceneEntSurfacesSunShadow()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddAllSceneEntSurfacesSpotShadow
==============
*/
void R_AddAllSceneEntSurfacesSpotShadow(const GfxViewInfo *viewInfo, unsigned int spotShadowIndex, unsigned int primaryLightIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DrawBModel
==============
*/
int R_DrawBModel(BModelDrawInfo *bmodelInfo, const GfxBrushModel *bmodel, const GfxPlacement *placement, const ShaderConstantSet *constSet)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_CullDynBrushInCell
==============
*/
void R_CullDynBrushInCell(unsigned int cellIndex, const DpvsPlane *planes, int planeCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DrawAllSceneEnt
==============
*/
void R_DrawAllSceneEnt(const GfxViewInfo *viewInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DrawAllDynEnt
==============
*/
void R_DrawAllDynEnt(const GfxViewInfo *viewInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FilterEntIntoCells_r
==============
*/
void R_FilterEntIntoCells_r(float entInfo, const cplane_s *a2, float node, FilterEntInfo *a4, mnode_t *mins, const vec3_t *maxs, const vec3_t *a7)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FilterDynEntIntoCells_r
==============
*/
void R_FilterDynEntIntoCells_r(float node, const cplane_s *a2, float dynEntIndex, mnode_t *a4, unsigned int drawType, DynEntityDrawType mins, const vec3_t *maxs, const vec3_t *a8)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UnfilterEntFromCells
==============
*/
void R_UnfilterEntFromCells(LocalClientNum_t localClientNum, unsigned int entnum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UnfilterDynEntFromCells
==============
*/
void R_UnfilterDynEntFromCells(unsigned int dynEntId, DynEntityDrawType drawType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FilterDObjIntoCells
==============
*/
void R_FilterDObjIntoCells(float localClientNum, LocalClientNum_t a2, unsigned int entnum, vec3_t *origin, float radius)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FilterBModelIntoCells
==============
*/
void R_FilterBModelIntoCells(float localClientNum, LocalClientNum_t a2, unsigned int entnum, GfxBrushModel *bmodel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FilterDynEntIntoCells
==============
*/
void R_FilterDynEntIntoCells(float dynEntId, unsigned int a2, DynEntityDrawType drawType, vec3_t *mins, vec3_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DpvsBoxIsVisible
==============
*/
int R_DpvsBoxIsVisible(const vec3_t *mins, const vec3_t *maxs, LocalClientNum_t localClientNum, unsigned int view)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_FilterXModelIntoScene
==============
*/
void R_FilterXModelIntoScene(const XModel *model, const GfxScaledPlacement *placement, unsigned int renderFxFlags, unsigned __int16 *cachedLightingHandle, float lightToleranceSq)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitialEntityCulling
==============
*/
void R_InitialEntityCulling()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetStaticModelsAabb
==============
*/
void R_GetStaticModelsAabb(const GfxAabbTree *tree, const vec3_t *mins, const vec3_t *maxs, int *models, int *models_count, int max_models)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetStaticModels
==============
*/
void R_GetStaticModels(const vec3_t *mins, const vec3_t *maxs, int *models, int *models_count, int max_models)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCellDynBrushSurfacesInFrustumCmd
==============
*/
void R_AddCellDynBrushSurfacesInFrustumCmd(void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FinishDpvsDynamicBatch
==============
*/
void R_FinishDpvsDynamicBatch(DpvsDynamicCellCmd *dpvsDynamicBatch, bool bRunCmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddDpvsDynamicBatch
==============
*/
void R_AddDpvsDynamicBatch(DpvsDynamicCellCmd *dpvsDynamicBatch, int cellIndex, const DpvsPlane *planes, int planeCount, int frustumPlaneCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCellSurfacesInFrustumDelayed
==============
*/
void R_AddCellSurfacesInFrustumDelayed(const GfxCell *cell, const DpvsPlane *planes, int planeCount, int frustumPlaneCount, DpvsDynamicCellCmd *dpvsDynamicBatch)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CacheCell
==============
*/
void R_CacheCell(int cellIndex, int planeIndex, int planeCount, int frustumPlaneCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCellSurfaces
==============
*/
void R_AddCellSurfaces(int cellIndex, const DpvsPlane *planes, int planeCount, int frustumPlaneCount, DpvsDynamicCellCmd *dpvsDynamicBatch)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AssertValidQueue
==============
*/
void R_AssertValidQueue()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_EnqueuePortal
==============
*/
void R_EnqueuePortal(const vec3_t *a1, const DpvsPlane *a2, float dist, GfxPortal *portal)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_NextQueuedPortal
==============
*/
GfxPortal *R_NextQueuedPortal()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_AddVertToPortalHullPoints
==============
*/
void R_AddVertToPortalHullPoints(GfxPortal *portal, const vec3_t *v)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ChopPortal
==============
*/
int R_ChopPortal(const GfxPortal *portal, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, vec3_t (*v)[128], const vec3_t **finalVerts)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ChopPortalAndAddHullPoints
==============
*/
bool R_ChopPortalAndAddHullPoints(GfxPortal *portal, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ChopPortalAndAddHullPointsNoFrustum
==============
*/
bool R_ChopPortalAndAddHullPointsNoFrustum(GfxPortal *portal, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_GetFurtherCellList_r
==============
*/
int __cdecl R_GetFurtherCellList_r(const GfxCell *cell, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, vec3_t (*v)[128], const GfxCell **list, int count)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetCellVisible
==============
*/
void R_SetCellVisible(unsigned int cellIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_VisitAllFurtherCells
==============
*/
void R_VisitAllFurtherCells(const GfxCell *cell, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, int frustumPlaneCount, DpvsDynamicCellCmd *dpvsDynamicBatch)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetAncestorListStatus
==============
*/
void R_SetAncestorListStatus(GfxPortal *portal, bool isAncestor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_VisitPortalsForCell
==============
*/
int R_VisitPortalsForCell(const GfxCell *cell, GfxPortal *parentPortal, const DpvsPlane *parentPlane, DpvsPlane *planes, unsigned int maxPlaneCount, unsigned int planeCount, int frustumPlaneCount, unsigned int recursionDepth, DpvsClipChildren clipChildren, DpvsDynamicCellCmd *dpvsDynamicBatch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_VisitPortals
==============
*/
void R_VisitPortals(const GfxCell *cell, const DpvsPlane *parentPlane, DpvsPlane *planes, int planeCount, DpvsDynamicCellCmd *dpvsDynamicBatch)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_VisitPortalsForCellNoFrustum
==============
*/
void R_VisitPortalsForCellNoFrustum(const GfxCell *cell, GfxPortal *parentPortal, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, unsigned int recursionDepth)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_VisitPortalsNoFrustum
==============
*/
void R_VisitPortalsNoFrustum(const GfxCell *cell)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GenerateShadowMapCasterCells
==============
*/
void R_GenerateShadowMapCasterCells()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddSunShadowSurfacesFrustumOnly
==============
*/
void R_AddSunShadowSurfacesFrustumOnly(unsigned int viewIndex, bool cache)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ShowCull
==============
*/
void R_ShowCull(const vec3_t *viewOrigin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitSceneData
==============
*/
void R_InitSceneData(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_InitFilter
==============
*/
void DynEntCl_InitFilter()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitSceneBuffers
==============
*/
void R_InitSceneBuffers()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ClearDpvsScene
==============
*/
void R_ClearDpvsScene(LocalClientNum_t previousLocalClientNum, bool bIsExtraCam)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CullDynamicPointLightsInCameraView
==============
*/
void R_CullDynamicPointLightsInCameraView()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_EnableOccluder
==============
*/
void R_EnableOccluder(const char *name, bool enable)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetViewFrustumPlanes
==============
*/
void R_SetViewFrustumPlanes(GfxViewInfo *viewInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddWorldSurfacesPortalWalk
==============
*/
void R_AddWorldSurfacesPortalWalk(int cameraCellIndex, DpvsDynamicCellCmd *pDynamicBatch)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DpvsClearCellVisibility
==============
*/
void R_DpvsClearCellVisibility()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_StartCachedDpvsBatches
==============
*/
void R_StartCachedDpvsBatches(unsigned int view, unsigned int batchMask)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetupShadowSurfacesDpvs
==============
*/
void R_SetupShadowSurfacesDpvs(const GfxViewParms *viewParms, const vec4_t *sidePlanes, unsigned int sidePlaneCount, int partitionIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetFarPlaneDist
==============
*/
double R_GetFarPlaneDist()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetCullDist
==============
*/
void R_SetCullDist(float dist)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CullBoxCurDpvs_SceneSelect
==============
*/
int R_CullBoxCurDpvs_SceneSelect(const vec3_t *mins, const vec3_t *maxs, unsigned int viewIndex, unsigned int sceneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_CullBoxCurDpvs
==============
*/
int R_CullBoxCurDpvs(const vec3_t *mins, const vec3_t *maxs, unsigned int viewIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_CullPoint
==============
*/
int R_CullPoint(LocalClientNum_t localClient, const vec3_t *p0, float cutoff)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_CullPoint
==============
*/
int R_CullPoint(int max_local_clients, const vec3_t *point, float cutoff)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_CullLine
==============
*/
int R_CullLine(int localClient, const vec3_t *p0, const vec3_t *p1, float cutoff)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ExtraCam_SaveDpvsData
==============
*/
unsigned int R_ExtraCam_SaveDpvsData(LocalClientNum_t localClientNum, unsigned __int8 *buffer, unsigned int bufferByteSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ExtraCam_RestoreDpvsData
==============
*/
void R_ExtraCam_RestoreDpvsData(LocalClientNum_t localClientNum, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_PerMap_DpvsGlobInit
==============
*/
void R_PerMap_DpvsGlobInit()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
r_sceneents_dobjCallback
==============
*/
int r_sceneents_dobjCallback(jqBatch *batch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
r_sceneents_modelCallback
==============
*/
int r_sceneents_modelCallback(jqBatch *batch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
r_sceneents_dynentCallback
==============
*/
int r_sceneents_dynentCallback(jqBatch *batch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
r_sceneents_brushCallback
==============
*/
int r_sceneents_brushCallback(jqBatch *batch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
r_sceneents_glassbrushCallback
==============
*/
int r_sceneents_glassbrushCallback(jqBatch *batch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
r_sceneents_dynbrushCallback
==============
*/
int r_sceneents_dynbrushCallback(jqBatch *batch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_DpvsStartCachedShadowBatches
==============
*/
void R_DpvsStartCachedShadowBatches(unsigned int viewIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetupWorldSurfacesDpvs
==============
*/
void R_SetupWorldSurfacesDpvs(const GfxViewParms *viewParms, unsigned int renderCullFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddWorldSurfacesDpvs
==============
*/
void R_AddWorldSurfacesDpvs()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DpvsGetVisibleCells
==============
*/
void R_DpvsGetVisibleCells(int cameraCellIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

