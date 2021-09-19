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
void R_FrustumClipPlanes(
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
void R_ProjectPortal(
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
unsigned int R_AddBevelPlanes(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_PortalClipPlanes
==============
*/
unsigned int R_PortalClipPlanes(
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
const vec3_t *R_ChopPortalWinding(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_GetLightingMask_Box
==============
*/
unsigned int R_GetLightingMask_Box(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_GetLightingMask_Sphere
==============
*/
unsigned int R_GetLightingMask_Sphere(
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
void R_InitSceneEntDrawSurfs(
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
void R_AddAllSceneEntSurfacesCamera(
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
void R_AddAllSceneEntSurfacesSpotShadow(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DrawBModel
==============
*/
int R_DrawBModel(
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
void R_FilterEntIntoCells_r(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FilterDynEntIntoCells_r
==============
*/
void R_FilterDynEntIntoCells_r(
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
void R_FilterDObjIntoCells(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FilterBModelIntoCells
==============
*/
void R_FilterBModelIntoCells(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FilterDynEntIntoCells
==============
*/
void R_FilterDynEntIntoCells(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DpvsBoxIsVisible
==============
*/
int R_DpvsBoxIsVisible(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_FilterXModelIntoScene
==============
*/
void R_FilterXModelIntoScene(
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
void R_GetStaticModelsAabb(
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
void R_AddDpvsDynamicBatch(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCellSurfacesInFrustumDelayed
==============
*/
void R_AddCellSurfacesInFrustumDelayed(
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
void R_AddCellSurfaces(
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
/*void R_EnqueuePortal(const vec3_t *a1@<ecx>, const DpvsPlane *a2@<edi>, float a3@<xmm0>, GfxPortal *portal)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

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
int R_ChopPortal(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ChopPortalAndAddHullPoints
==============
*/
bool R_ChopPortalAndAddHullPoints(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ChopPortalAndAddHullPointsNoFrustum
==============
*/
bool R_ChopPortalAndAddHullPointsNoFrustum(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_GetFurtherCellList_r
==============
*/
int R_GetFurtherCellList_r(
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
void R_VisitAllFurtherCells(
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
int R_VisitPortalsForCell(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_VisitPortals
==============
*/
void R_VisitPortals(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_VisitPortalsForCellNoFrustum
==============
*/
void R_VisitPortalsForCellNoFrustum(
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
void R_SetupShadowSurfacesDpvs(
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
int R_CullBoxCurDpvs_SceneSelect(
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
unsigned int R_ExtraCam_SaveDpvsData(
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

