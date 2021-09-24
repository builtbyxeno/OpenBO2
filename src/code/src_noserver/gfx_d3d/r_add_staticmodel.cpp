#include "types.h"

/*
==============
R_SkinStaticModelsShadowForLod
==============
*/
void R_SkinStaticModelsShadowForLod(const XModel *model, unsigned __int16 *list, unsigned int count, unsigned int surfType, unsigned int lod, GfxSModelDrawSurfData *surfData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SkinStaticModelsShadow
==============
*/
void R_SkinStaticModelsShadow(const XModel *model, unsigned __int16 (*staticModelLodList)[4][128], unsigned __int16 (*staticModelLodCount)[4], GfxSModelDrawSurfData *surfData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ShowCountsStaticModel
==============
*/
void R_ShowCountsStaticModel(int smodelIndex, int lod)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetStaticModelId
==============
*/
GfxStaticModelId R_GetStaticModelId(int smodelIndex, int lod)
{
	UNIMPLEMENTED(__FUNCTION__);
	GfxStaticModelId tmp;
	return tmp;
}

/*
==============
R_StaticModelWriteInfoHeader
==============
*/
void R_StaticModelWriteInfoHeader(int fileHandle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_StaticModelWriteInfo
==============
*/
void R_StaticModelWriteInfo(int fileHandle, const GfxStaticModelDrawInst *smodelDrawInst, const float dist)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DumpStaticModelLodInfo
==============
*/
void R_DumpStaticModelLodInfo(const GfxStaticModelDrawInst *smodelDrawInst, const float dist)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetSModelDLightMask
==============
*/
unsigned int R_GetSModelDLightMask(const GfxStaticModelInst *smodelInst, const vec4_t *dynamicSpotLightPlanes, const GfxLight *visibleLights, int visibleLightCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetupSModelDrawSurfLightingDataForCamera
==============
*/
void R_SetupSModelDrawSurfLightingDataForCamera(GfxSModelDrawSurfLightingData *surfData, const GfxViewParms *viewParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_StaticModelDebugAids
==============
*/
void R_StaticModelDebugAids(unsigned int smodelIndex, const XModel *localModel, const GfxStaticModelDrawInst *smodelDrawInst, int lod, float lodDist, float lodScale, const vec3_t *eyePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SortAllStaticModelSurfacesCamera
==============
*/
void R_SortAllStaticModelSurfacesCamera()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddAllStaticModelSurfacesRangeSunShadow
==============
*/
void R_AddAllStaticModelSurfacesRangeSunShadow(int viewIndex, unsigned int partitionIndex, unsigned int maxDrawSurfCount, const GfxViewParms *shadowViewParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SortAllStaticModelSurfacesSunShadow
==============
*/
void R_SortAllStaticModelSurfacesSunShadow()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddAllStaticModelSurfacesSunShadow
==============
*/
void R_AddAllStaticModelSurfacesSunShadow(unsigned int a1, int viewIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddAllStaticModelSurfacesSpotShadow
==============
*/
void R_AddAllStaticModelSurfacesSpotShadow(int viewIndex, unsigned int spotShadowIndex, unsigned int primaryLightIndex, const GfxViewParms *shadowViewParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FixupSmodelCullOutDists
==============
*/
void R_FixupSmodelCullOutDists()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FixupSmodelCullOutDists
==============
*/
void R_FixupSmodelCullOutDists(const XModel *model, const vec3_t *origin, float newCullDist)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_StaticModelCameraDistSort
==============
*/
void R_StaticModelCameraDistSort(unsigned __int16 *list, float *dists, unsigned int count)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SkinStaticModelsCameraForLod
==============
*/
void R_SkinStaticModelsCameraForLod(const XModel *model, unsigned int primaryLightIndex, unsigned __int16 *list, float *dists, unsigned int count, unsigned int surfType, unsigned int lod, GfxSModelDrawSurfLightingData *surfData, unsigned int visLightsMask)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SkinStaticModelsCamera
==============
*/
void R_SkinStaticModelsCamera(const XModel *model, unsigned int primaryLightIndex, unsigned __int16 (*staticModelLodList)[4][128], float (*staticModelLodDists)[4][128], unsigned __int16 (*staticModelLodCount)[4], GfxSModelDrawSurfLightingData *surfData, unsigned int visLightsMask)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddStaticModelSurfacesCamera
==============
*/
void R_AddStaticModelSurfacesCamera(int viewIndex, int viewInfoIndex, int teleported, const GfxLight *visibleLights, int visibleLightCount, int noLodCullOut, GfxSModelDrawSurfLightingData *surfData, TestForSunShadowList sunShadowTest)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddAllStaticModelSurfacesCamera
==============
*/
void R_AddAllStaticModelSurfacesCamera(int viewIndex, int viewInfoIndex, int teleported, const GfxLight *visibleLights, int visibleLightCount, int noLodCullOut, bool hasSunShadowVisData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

