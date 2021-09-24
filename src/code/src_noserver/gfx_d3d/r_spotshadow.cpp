#include "types.h"

/*
==============
R_SetViewParmsForLight
==============
*/
void R_SetViewParmsForLight(const GfxLight *light, GfxViewParms *viewParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetSpotShadowLookupMatrix
==============
*/
void R_GetSpotShadowLookupMatrix(const GfxViewParms *shadowViewParms, int usingGridTiling, int usingFullShadowBuffer, unsigned int spotShadowIndex, unsigned int tileCount, GfxMatrix *lookupMatrix)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddSpotShadowModelEntities
==============
*/
void R_AddSpotShadowModelEntities(LocalClientNum_t localClientNum, unsigned int primaryLightIndex, const GfxLight *light)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_EmitSpotShadowMapSurfs
==============
*/
void R_EmitSpotShadowMapSurfs(const char *a1, GfxViewInfo *viewInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GenerateAllSortedSpotShadowDrawSurfs
==============
*/
void R_GenerateAllSortedSpotShadowDrawSurfs(GfxViewInfo *viewInfo, int viewIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddSpotShadowsForLight
==============
*/
char __cdecl R_AddSpotShadowsForLight(GfxViewInfo *viewInfo, GfxLight *light, unsigned int shadowableLightIndex, unsigned int totalSpotLightCount, float spotShadowFade)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

