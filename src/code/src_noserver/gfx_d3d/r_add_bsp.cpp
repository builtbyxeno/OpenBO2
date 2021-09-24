#include "types.h"

/*
==============
R_GetVisLightsMask
==============
*/
unsigned int R_GetVisLightsMask(const GfxSurface *surface, const vec4_t *dynamicSpotLightPlanes, const GfxLight *visibleLights, int visibleLightCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_InitBspDrawSurfRegions
==============
*/
void R_InitBspDrawSurfRegions(BspSurfRegions *regions, BspSurfRegionSetupInfo *setupInfo, int setupInfoCount, const GfxViewParms *viewParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddAllBspDrawSurfacesRangeCamera
==============
*/
void R_AddAllBspDrawSurfacesRangeCamera(unsigned int beginSurface, unsigned int endSurface, BspSurfRegions *bspSurfRegions, LocalClientNum_t localClientNum, const GfxLight *visibleLights, int visibleLightCount, TestForSunShadowList sunShadowListTest)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddAllBspDrawSurfacesCameraNonlit
==============
*/
void R_AddAllBspDrawSurfacesCameraNonlit(unsigned int beginSurface, unsigned int endSurface, unsigned int stage, unsigned int maxDrawSurfCount, const GfxViewParms *viewParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddAllBspDrawSurfacesCamera
==============
*/
void R_AddAllBspDrawSurfacesCamera(char *a1, LocalClientNum_t localClientNum, int addAllList, const GfxLight *visibleLights, int visibleLightCount, bool hasSunShadowVisData, const GfxViewParms *viewParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SortAllBspSurfacesCamera
==============
*/
void R_SortAllBspSurfacesCamera(int addAllList)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddAllBspDrawSurfacesRangeSunShadow
==============
*/
void R_AddAllBspDrawSurfacesRangeSunShadow(GfxBspDrawSurfData *surfData, unsigned int partitionIndex, unsigned int beginSurface, unsigned int endSurface)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SortAllBspSurfacesSunShadow
==============
*/
void R_SortAllBspSurfacesSunShadow()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitBspDrawSurfSunShadow
==============
*/
void R_InitBspDrawSurfSunShadow(GfxBspDrawSurfData *surfData, unsigned int partitionIndex, unsigned int maxDrawSurfCount, const GfxViewParms *shadowViewParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddAllBspDrawSurfacesSunShadow
==============
*/
void R_AddAllBspDrawSurfacesSunShadow(unsigned int a1, GfxBspDrawSurfData *a2, LocalClientNum_t localClientNum, const GfxSunShadow *sunShadow)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddAllBspDrawSurfacesSpotShadow
==============
*/
void R_AddAllBspDrawSurfacesSpotShadow(unsigned int spotShadowIndex, unsigned int primaryLightIndex, const GfxViewParms *shadowViewParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

