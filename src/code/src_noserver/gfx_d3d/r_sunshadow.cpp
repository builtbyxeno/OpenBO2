#include "types.h"

/*
==============
R_CalcBoxVsCylinderRayMinBox
==============
*/
void R_CalcBoxVsCylinderRayMinBox(const vec3_t *box0, const vec3_t *box1, const vec3_t *origin, const vec3_t *forward, float radius, vec3_t *outBox0, vec3_t *outBox1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetSceneExtentsAlongDir
==============
*/
void R_GetSceneExtentsAlongDir(const vec3_t *cameraOrigin, const vec3_t *origin, const vec3_t *forward, float *nearCap, float *farCap)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetSunAxes
==============
*/
void R_GetSunAxes(vec3_t *sunAxis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ClipSpaceToWorldSpace
==============
*/
void R_ClipSpaceToWorldSpace(const GfxMatrix *invViewProjMtx, const vec3_t *clipSpacePoints, int pointCount, vec3_t *worldSpacePoints)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetupSunShadowBoundingPoly
==============
*/
void R_SetupSunShadowBoundingPoly(const vec2_t *frustumPointsInSunProj, const vec2_t *viewOrgInSunProj, const vec2_t *snappedViewOrgInSunProj, float maxSizeInSunProj, const vec2_t *snappedViewOrgInClipSpace, GfxSunShadowBoundingPoly *boundingPoly, unsigned int pointCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SunShadowMapBoundingPoly
==============
*/
void R_SunShadowMapBoundingPoly(const GfxSunShadowBoundingPoly *boundingPoly, float sampleSize, vec2_t *polyInClipSpace, int *pointIsNear, unsigned int partitionRes)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SunShadowMapClipSpaceClipPlanes
==============
*/
unsigned int R_SunShadowMapClipSpaceClipPlanes(const GfxSunShadowBoundingPoly *a1, float partitionIndex, int a3, vec4_t *boundingPolyClipSpacePlanes, unsigned int partitionRes)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SunShadowMapProjectionMatrix
==============
*/
void R_SunShadowMapProjectionMatrix(const vec2_t *snappedViewOrgInClipSpace, float shadowSampleSize, float nearClip, float farClip, GfxViewParms *shadowViewParms, unsigned int partitionRes)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetupSunShadowMapPartitionFraction
==============
*/
void R_SetupSunShadowMapPartitionFraction(const GfxViewParms *viewParms, float scaleToFitUsable, GfxSunShadowProjection *sunProj, vec4_t *partitionFraction)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetupNearRegionPlane
==============
*/
void R_SetupNearRegionPlane(const vec4_t *partitionFraction)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetupSunShadowMapProjection
==============
*/
void R_SetupSunShadowMapProjection(const GfxViewParms *viewParms, const vec3_t *sunAxis, GfxSunShadow *sunShadow, vec2_t *snappedViewOrgInClipSpace, vec4_t *partitionFraction, unsigned int partitionRes)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetSunShadowLookupMatrix
==============
*/
void R_GetSunShadowLookupMatrix(const GfxViewParms *shadowViewParms, const GfxSunShadowProjection *sunProj, const vec4_t *partitionFraction, GfxMatrix *lookupMatrix)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SunShadowMaps
==============
*/
void R_SunShadowMaps(bool cache)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FinishSunShadowMaps
==============
*/
void R_FinishSunShadowMaps()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_MergeAndEmitSunShadowMapsSurfs
==============
*/
void R_MergeAndEmitSunShadowMapsSurfs(GfxViewInfo *viewInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetupSunShadowMaps
==============
*/
void R_SetupSunShadowMaps(const GfxViewParms *viewParms, GfxSunShadow *sunShadow)
{
	UNIMPLEMENTED(__FUNCTION__);
}

