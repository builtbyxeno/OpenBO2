#include "types.h"
#include "functions.h"

/*
==============
R_GetScene
==============
*/
GfxScene *R_GetScene()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_AllocSceneDObj
==============
*/
unsigned int R_AllocSceneDObj()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AllocSceneModel
==============
*/
unsigned int R_AllocSceneModel()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AllocTextureOverride
==============
*/
char R_AllocTextureOverride(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AllocTextureOverride
==============
*/
char R_AllocTextureOverride(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AllocTextureOverride
==============
*/
char R_AllocTextureOverride(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AllocTextureOverride
==============
*/
char R_AllocTextureOverride(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AllocTextureOverride
==============
*/
char R_AllocTextureOverride(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AllocSceneBrush
==============
*/
unsigned int R_AllocSceneBrush()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_TryToValidateBrushModel
==============
*/
void R_TryToValidateBrushModel(unsigned int modelIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetBrushModel
==============
*/
GfxBrushModel *R_GetBrushModel(unsigned int modelIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_AddBrushModelToSceneFromAngles
==============
*/
void R_AddBrushModelToSceneFromAngles(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddGlassBrushToScene
==============
*/
void R_AddGlassBrushToScene(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddDObjToScene
==============
*/
void R_AddDObjToScene(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AllocParticleCloud
==============
*/
int R_AllocParticleCloud()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_GetGfxParticleCloud
==============
*/
GfxParticleCloud *R_GetGfxParticleCloud(unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_PrepareXModelRigidCullInfo
==============
*/
void R_PrepareXModelRigidCullInfo(XModelRigidCullInfoContext *cullInfoContext)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CloneAndSetupXModelDrawSurf
==============
*/
void R_CloneAndSetupXModelDrawSurf(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddOmniLightToScene
==============
*/
void R_AddOmniLightToScene(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddSpotLightToScene
==============
*/
void R_AddSpotLightToScene(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddFlashLightToScene
==============
*/
void R_AddFlashLightToScene(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UpdateFrameFog
==============
*/
void R_UpdateFrameFog(refdef_t *refdef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetupViewProjectionMatrices
==============
*/
void R_SetupViewProjectionMatrices(GfxViewParms *viewParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetAllowShadowMaps
==============
*/
void R_SetAllowShadowMaps(const bool allowShadowMaps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddBModelSurfacesCamera
==============
*/
void R_AddBModelSurfacesCamera(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddBModelSurfaces
==============
*/
GfxDrawSurf *R_AddBModelSurfaces(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_GetXSurface
==============
*/
const XSurface *R_GetXSurface(const void *modelSurf, surfaceType_t surfType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_SetEnablePlayerShadowFlag
==============
*/
void R_SetEnablePlayerShadowFlag(bool flag)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_MaterialOverride
==============
*/
Material *R_MaterialOverride(unsigned int modelIndex, int textureOverrideIdx, Material *drawMaterial)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_AddXModelSurfacesCamera
==============
*/
void R_AddXModelSurfacesCamera(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddXModelSurfaces
==============
*/
GfxDrawSurf *R_AddXModelSurfaces(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_AddDObjSurfaces
==============
*/
GfxDrawSurf *R_AddDObjSurfaces(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_SetSceneComposition
==============
*/
void R_SetSceneComposition(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CheckShadowMapVolumes
==============
*/
void R_CheckShadowMapVolumes(const vec3_t *position)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CheckShadowMapVolume
==============
*/
char R_CheckShadowMapVolume(const vec3_t *position, unsigned int volumeIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_CheckWorldFogModifierVolumes
==============
*/
int R_CheckWorldFogModifierVolumes(vec3_t *position, unsigned int bankMask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_UpdateWorldFrameFog
==============
*/
void R_UpdateWorldFrameFog(refdef_t *refdef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CheckExposureVolumes
==============
*/
int R_CheckExposureVolumes(vec3_t *position, float *feather)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_UpdateExposureValue
==============
*/
void R_UpdateExposureValue
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetExposure
==============
*/
void R_SetExposure
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitModifierVolumes
==============
*/
/*void R_InitModifierVolumes(float *a1@<edx>, vec3_t *a2@<ecx>, refdef_t *refdef)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
R_SetDepthOfField
==============
*/
void R_SetDepthOfField(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetDoubleVision
==============
*/
void R_SetDoubleVision(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetWaterSheetingFx
==============
*/
void R_SetWaterSheetingFx(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetFlameFx
==============
*/
void R_SetFlameFx(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetElectrifiedFx
==============
*/
void R_SetElectrifiedFx(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetTransportedFx
==============
*/
void R_SetTransportedFx(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetReviveFx
==============
*/
void R_SetReviveFx(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetRimIntensity
==============
*/
void R_SetRimIntensity(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetGenericSceneVectors
==============
*/
void R_SetGenericSceneVectors(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetPoisonFx
==============
*/
void R_SetPoisonFx(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_TestLutVolumes
==============
*/
__int16 R_TestLutVolumes(vec3_t *position, unsigned __int16 bankMask)
{
	UNIMPLEMENTED(__FUNCTION__);
	__int16 tmp;
	return tmp;
}

/*
==============
R_SetFilmInfo
==============
*/
void R_SetFilmInfo(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms, refdef_t *refdef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetBloomInfo
==============
*/
void R_SetBloomInfo(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetCharacterPrimaryLightScaleInfo
==============
*/
void R_SetCharacterPrimaryLightScaleInfo(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetFullSceneViewMesh
==============
*/
void R_SetFullSceneViewMesh(int viewInfoIndex, GfxViewInfo *viewInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddDrawLitCall
==============
*/
void R_AddDrawLitCall(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddDrawLitBspCall
==============
*/
void R_AddDrawLitBspCall(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddDrawLitStaticModelCall
==============
*/
void R_AddDrawLitStaticModelCall(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddEmissiveSpotLight
==============
*/
void R_AddEmissiveSpotLight(GfxViewInfo *viewInfo, GfxLight *visibleLights, int visibleLightCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetSunShadowConstants
==============
*/
void R_SetSunShadowConstants(GfxCmdBufInput *input, const GfxSunShadowProjection *sunProj)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetSkyConstants
==============
*/
void R_SetSkyConstants(GfxCmdBufInput *input, const GfxViewInfo *viewInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetSunConstants
==============
*/
void R_SetSunConstants(GfxCmdBufInput *input, float sunVisibility)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetHeroLighting
==============
*/
void R_SetHeroLighting(GfxCmdBufInput *input, GfxViewInfo *viewInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetSkyColorMatrix
==============
*/
void R_SetSkyColorMatrix(GfxCmdBufInput *input)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetHDRControlConstants
==============
*/
void R_SetHDRControlConstants(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetDLightsConstants
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
R_SplitDrawSurfacesPrimarySortKeyScanRev
==============
*/
void R_SplitDrawSurfacesPrimarySortKeyScanRev(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawLightDebug
==============
*/
void DrawLightDebug(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawSunDirectionDebug
==============
*/
void DrawSunDirectionDebug(const vec3_t *viewOrg, const vec3_t *viewForward)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DrawFogParams
==============
*/
void R_DrawFogParams(const refdef_t *refdef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetSkyDynamicIntensity
==============
*/
/*void R_SetSkyDynamicIntensity(float a1@<edi>, const vec3_t *viewForward, GfxCmdBufInput *input)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
R_WaitForFXUpdateWorkerCmds
==============
*/
int R_WaitForFXUpdateWorkerCmds()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_WaitForFXNonSpriteWorkerCmds
==============
*/
int R_WaitForFXNonSpriteWorkerCmds()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetupDrawSurfListInfos
==============
*/
void R_SetupDrawSurfListInfos(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SplitAndMergeDrawLists
==============
*/
void R_SplitAndMergeDrawLists(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_MergeAndEmitDrawSurfListsIntoList
==============
*/
void R_MergeAndEmitDrawSurfListsIntoList(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FinishDecalAndEmissiveDrawSurfs
==============
*/
void R_FinishDecalAndEmissiveDrawSurfs(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DrawRecordFrame
==============
*/
void R_DrawRecordFrame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddDrawRecord
==============
*/
void R_AddDrawRecord(GfxViewInfo *viewInfo, GfxBackEndData *data, unsigned int viewInfoIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetDrawRecordFrame
==============
*/
unsigned int R_GetDrawRecordFrame()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_InvalidateShadowableLightCache
==============
*/
void R_InvalidateShadowableLightCache()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UpdateCachedLightUsage
==============
*/
int R_UpdateCachedLightUsage()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_InitCachedVisibleLights
==============
*/
void R_InitCachedVisibleLights()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetCachedVisibleLights
==============
*/
void R_GetCachedVisibleLights(GfxViewInfo *viewInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetupVisibility
==============
*/
void R_SetupVisibility(GfxViewInfo *viewInfo, const GfxViewParms *viewParmsDpvs, bool recalculateShadows)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetupNeedResolve
==============
*/
void R_SetupNeedResolve(GfxViewInfo *viewInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AllocViewInfo
==============
*/
GfxViewInfo *R_AllocViewInfo()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_SetupSunShadowGlobals
==============
*/
void R_SetupSunShadowGlobals()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GenerateSortedDrawSurfs
==============
*/
void R_GenerateSortedDrawSurfs(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddDrawCalls
==============
*/
void R_AddDrawCalls()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ClearScene
==============
*/
void R_ClearScene(LocalClientNum_t localClientNum, bool forStereoRightEyeView, bool forExtraCam)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetLocalClientNum
==============
*/
LocalClientNum_t R_GetLocalClientNum()
{
	UNIMPLEMENTED(__FUNCTION__);
	LocalClientNum_t tmp;
	return tmp;
}

/*
==============
R_SetViewParmsForScene
==============
*/
void R_SetViewParmsForScene(const refdef_t *refdef, GfxViewParms *viewParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetSceneParms
==============
*/
void R_SetSceneParms(const refdef_t *refdef, GfxSceneParms *sceneParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ExtraCam_SetSceneParms
==============
*/
void R_ExtraCam_SetSceneParms(const refdef_t *refdef, GfxSceneParms *sceneParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LerpDir
==============
*/
void R_LerpDir(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UpdateFrameSun
==============
*/
int R_UpdateFrameSun()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_LodScaleForSkinCacheOverflow
==============
*/
double R_LodScaleForSkinCacheOverflow(unsigned int viewIndex, float currentScale)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_UpdateLodParms
==============
*/
void R_UpdateLodParms(const refdef_t *refdef, GfxLodParms *lodParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetLodOrigin
==============
*/
void R_SetLodOrigin(const refdef_t *refdef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetupRenderSceneViewParms
==============
*/
GfxViewParms *R_SetupRenderSceneViewParms(const refdef_t *refdef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_RenderScene
==============
*/
void R_RenderScene(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LinkDObjEntity
==============
*/
void R_LinkDObjEntity(LocalClientNum_t localClientNum, unsigned int entnum, vec3_t *origin, float radius)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LinkBModelEntity
==============
*/
void R_LinkBModelEntity(LocalClientNum_t localClientNum, unsigned int entnum, GfxBrushModel *bmodel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UnlinkEntity
==============
*/
void R_UnlinkEntity(LocalClientNum_t localClientNum, unsigned int entnum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LinkDynEnt
==============
*/
void R_LinkDynEnt(unsigned int dynEntId, DynEntityDrawType drawType, vec3_t *mins, vec3_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UnlinkDynEnt
==============
*/
void R_UnlinkDynEnt(unsigned int dynEntId, DynEntityDrawType drawType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_PvsLock_GetViewOrigin
==============
*/
void R_PvsLock_GetViewOrigin(vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_PvsLock_GetViewAxis
==============
*/
void R_PvsLock_GetViewAxis(vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_PvsLock_GetViewParms
==============
*/
GfxViewParms *R_PvsLock_GetViewParms()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
ShowLodInfo
==============
*/
void ShowLodInfo(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_PerMap_Init
==============
*/
void R_PerMap_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddDObjSurfacesCamera
==============
*/
void R_AddDObjSurfacesCamera(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetupVisibilityEarly
==============
*/
void R_SetupVisibilityEarly(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
r_add_draw_callsCallback
==============
*/
int r_add_draw_callsCallback(jqBatch *batch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_RenderExtraCam
==============
*/
void R_RenderExtraCam(
{
	UNIMPLEMENTED(__FUNCTION__);
}

