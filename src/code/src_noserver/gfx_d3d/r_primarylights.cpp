#include "types.h"

/*
==============
R_AddPotentiallyShadowedLight
==============
*/
unsigned int R_AddPotentiallyShadowedLight(const GfxViewInfo *viewInfo, unsigned int shadowableLightIndex, GfxCandidateShadowedLight *candidateLights, unsigned int candidateLightCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AddShadowedLightToShadowHistory
==============
*/
void R_AddShadowedLightToShadowHistory(GfxShadowedLightHistory *shadowHistory, unsigned int shadowableLightIndex, float fadeDelta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FadeOutShadowHistoryEntries
==============
*/
void R_FadeOutShadowHistoryEntries(GfxShadowedLightHistory *shadowHistory, float fadeDelta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ClearShadowedPrimaryLightHistory
==============
*/
void R_ClearShadowedPrimaryLightHistory(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddDynamicShadowableLight
==============
*/
unsigned int R_AddDynamicShadowableLight(GfxViewInfo *viewInfo, const GfxLight *visibleLight)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_IsDynamicShadowedLight
==============
*/
BOOL R_IsDynamicShadowedLight(unsigned int shadowableLightIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_IsPrimaryLight
==============
*/
BOOL R_IsPrimaryLight(unsigned int shadowableLightIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ChooseShadowedLights
==============
*/
void R_ChooseShadowedLights(unsigned __int8 *shadowableLightIsUsed, GfxViewInfo *viewInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetPrimaryLightEntityShadowBit
==============
*/
unsigned int R_GetPrimaryLightEntityShadowBit(LocalClientNum_t localClientNum, unsigned int entnum, unsigned int primaryLightIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_GetPrimaryLightDynEntShadowBit
==============
*/
unsigned int R_GetPrimaryLightDynEntShadowBit(unsigned int entnum, unsigned int primaryLightIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_LinkSphereEntityToPrimaryLights
==============
*/
void R_LinkSphereEntityToPrimaryLights(LocalClientNum_t localClientNum, unsigned int entityNum, const vec3_t *origin, float radius)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LinkBoxEntityToPrimaryLights
==============
*/
void R_LinkBoxEntityToPrimaryLights(LocalClientNum_t localClientNum, unsigned int entityNum, const vec3_t *mins, const vec3_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LinkDynEntToPrimaryLights
==============
*/
void R_LinkDynEntToPrimaryLights(unsigned int dynEntId, DynEntityDrawType drawType, const vec3_t *mins, const vec3_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UnlinkEntityFromPrimaryLights
==============
*/
void R_UnlinkEntityFromPrimaryLights(GfxWorld *world, LocalClientNum_t a2, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UnlinkDynEntFromPrimaryLights
==============
*/
void R_UnlinkDynEntFromPrimaryLights(GfxWorld *world, unsigned int a2, unsigned int dynEntId, DynEntityDrawType drawType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_IsEntityVisibleToPrimaryLight
==============
*/
BOOL R_IsEntityVisibleToPrimaryLight(unsigned int a1, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_IsDynEntVisibleToPrimaryLight
==============
*/
BOOL R_IsDynEntVisibleToPrimaryLight(unsigned int a1, unsigned int a2, unsigned int dynEntId, DynEntityDrawType drawType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_IsEntityVisibleToAnyShadowedLight
==============
*/
int R_IsEntityVisibleToAnyShadowedLight(const GfxViewInfo *viewInfo, unsigned int entityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_IsDynEntVisibleToAnyShadowedLight
==============
*/
BOOL R_IsDynEntVisibleToAnyShadowedLight(const GfxViewInfo *viewInfo, unsigned int dynEntIndex, DynEntityDrawType drawType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ShowPrimaryLightDebugLine
==============
*/
void R_ShowPrimaryLightDebugLine(const vec3_t *origin, const vec3_t *axis, const vec3_t *lightingOrigin, unsigned int primaryLightIndex, int context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ShowPrimaryLightBsp
==============
*/
void R_ShowPrimaryLightBsp(const GfxSurface *surface, unsigned int primaryLightIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

