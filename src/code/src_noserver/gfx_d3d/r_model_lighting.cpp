#include "types.h"

/*
==============
R_ModelLightingIndexFromHandle
==============
*/
unsigned int R_ModelLightingIndexFromHandle(unsigned __int16 handle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetModelLightingConsts
==============
*/
void R_SetModelLightingConsts(unsigned __int16 handle, vec4_t *coordsAndVis, vec4_t *sh0, vec4_t *sh1, vec4_t *sh2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetStaticModelLightingConsts
==============
*/
void R_SetStaticModelLightingConsts(unsigned __int16 handle, unsigned __int8 visibility, const GfxLightingSHQuantized *encodedLightingSH, vec4_t *coordsAndVis, vec4_t *sh0, vec4_t *sh1, vec4_t *sh2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AllocModelLightingPixel
==============
*/
unsigned int R_AllocModelLightingPixel(float lightGlobEA, GfxModelLightGlob *a2, GfxModelLightGlob *lightGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ToggleModelLightingFrame
==============
*/
void R_ToggleModelLightingFrame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetStaticModelLightingForSource
==============
*/
void R_SetStaticModelLightingForSource(const GfxStaticModelDrawInst *smodelDrawInst, GfxCmdBufSourceState *source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_BeginAllStaticModelLighting
==============
*/
void R_BeginAllStaticModelLighting()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetupDynamicModelLighting
==============
*/
void R_SetupDynamicModelLighting(GfxCmdBufInput *input)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitModelLightingGlobals
==============
*/
void R_InitModelLightingGlobals()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ResetModelLighting
==============
*/
void R_ResetModelLighting()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitStaticModelLighting
==============
*/
void R_InitStaticModelLighting()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetModelLightingForSource
==============
*/
void R_SetModelLightingForSource(unsigned __int16 handle, GfxCmdBufSourceState *source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AllocStaticModelLighting
==============
*/
char R_AllocStaticModelLighting(const GfxStaticModelDrawInst *smodelDrawInst, unsigned int smodelIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_CalcModelLighting
==============
*/
void R_CalcModelLighting(unsigned int entryIndex, const vec3_t *lightingOrigin, GfxModelLightExtrapolation extrapolateBehavior, bool useHeroLighting, unsigned __int8 *primaryLightIndex1, unsigned __int8 *primaryLightIndex2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetStaticModelLighting
==============
*/
void R_SetStaticModelLighting(unsigned int smodelIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetAllStaticModelLighting
==============
*/
void R_SetAllStaticModelLighting()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AllocModelLighting
==============
*/
unsigned int R_AllocModelLighting(float z, const vec3_t *lightingOrigin, float lightingOriginToleranceSq, unsigned __int8 *useHeroLighting, unsigned __int16 *cachedLightingHandle, GfxLightingInfo *lightingInfoOut)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

