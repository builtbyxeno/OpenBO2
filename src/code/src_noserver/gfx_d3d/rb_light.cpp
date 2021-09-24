#include "types.h"

/*
==============
R_CalculateLightGridColorFromCoeffs
==============
*/
void R_CalculateLightGridColorFromCoeffs(const __m128 *coeffs, const vec3_t *dir, vec4_t *energy)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DecodeLightGridCoeffsWeighted
==============
*/
void R_DecodeLightGridCoeffsWeighted(const GfxCompressedLightGridCoeffs *compressedCoeffs, GfxDecodedLightGridColors *decodedColors, float weight)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DecodeLightGridColorsWeighted
==============
*/
unsigned __int8 *R_DecodeLightGridColorsWeighted(int a1, int a2, float a3)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_ComputeLightGridAverageAndVisibility
==============
*/
void R_ComputeLightGridAverageAndVisibility(const GfxDecodedLightGridColors *colors, float primaryWeight, vec4_t *destAvgAndVis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ShowGridBox
==============
*/
void R_ShowGridBox(const unsigned int *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ShowGridCorner
==============
*/
void R_ShowGridCorner(const GfxLightGrid *lightGrid, unsigned int x, unsigned int y, unsigned int z, float halfSize, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ShowLightGrid
==============
*/
void R_ShowLightGrid(const GfxLightGrid *lightGrid, const unsigned int *pos, const vec3_t *samplePos, const GfxLightGridEntry **cornerEntry, bool *suppressEntry, bool honorSuppression)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetLightGridColorsFromIndex
==============
*/
void R_SetLightGridColorsFromIndex(const GfxLightGrid *lightGrid, unsigned int colorsIndex, const vec3_t *heroPos, unsigned __int16 dest, GfxLightingSH *destSH)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_BlendAndSetLightGridColors
==============
*/
void R_BlendAndSetLightGridColors(const GfxLightGrid *lightGrid, const unsigned __int16 *colorsIndex, const float *colorsWeight, unsigned int colorsCount, const vec3_t *heroPos, float weightNormalizeScale, unsigned __int16 dest, GfxLightingSH *destSH)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetBlackLightGridColors
==============
*/
void R_SetBlackLightGridColors(unsigned __int16 dest, float *destVis, GfxLightingSH *destSH)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetDebugLightGridColors
==============
*/
void R_SetDebugLightGridColors(unsigned __int16 dest, float *destVis, GfxLightingSH *destSH)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LookupSkyGridVolumesAtPoint
==============
*/
bool R_LookupSkyGridVolumesAtPoint(const GfxLightGrid *lightGrid, const vec3_t *samplePos, unsigned __int16 *colorsIndex, float *visibility, unsigned __int8 *primaryLightIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ExtrapolateLightingAtPoint
==============
*/
unsigned __int8 R_ExtrapolateLightingAtPoint(const GfxLightGrid *lightGrid, const vec3_t *samplePos, const vec3_t *heroPos, unsigned __int16 dest, float *destVis, GfxLightingSH *destSH, GfxModelLightExtrapolation extrapolateBehavior, unsigned int defaultGridEntry)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ExtrapolateAverageLightingAtPoint
==============
*/
unsigned __int8 R_ExtrapolateAverageLightingAtPoint(const GfxLightGrid *lightGrid, const vec3_t *samplePos, unsigned int defaultGridEntry, vec4_t *colorWithPrimaryWeight)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_GetLightGridSampleEntryQuad
==============
*/
void R_GetLightGridSampleEntryQuad(const GfxLightGrid *lightGrid, const unsigned int *pos, const GfxLightGridEntry **entries, unsigned int *defaultGridEntry)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_IsValidLightGridSample
==============
*/
bool R_IsValidLightGridSample(const GfxLightGrid *lightGrid, const GfxLightGridEntry *entry, int cornerIndex, const unsigned int *pos, const vec3_t *samplePos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_LightGridLookup
==============
*/
unsigned __int8 R_LightGridLookup(const GfxLightGrid *lightGrid, const vec3_t *samplePos, float *cornerWeight, const GfxLightGridEntry **cornerEntry, unsigned int *defaultGridEntry)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_GetLightingAtPoint
==============
*/
unsigned int R_GetLightingAtPoint(const GfxLightGrid *remoteLightGrid, const vec3_t *samplePos, unsigned __int16 dest, float *destVis, GfxLightingSH *destSH, GfxModelLightExtrapolation extrapolateBehavior, bool useHeroLighting)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_GetAverageLightingAtPoint
==============
*/
void R_GetAverageLightingAtPoint(unsigned int *a1, const vec3_t *samplePos, float primaryLightFraction, vec3_t *outColor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

