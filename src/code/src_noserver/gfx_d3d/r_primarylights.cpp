#include "types.h"
#include "functions.h"

/*
==============
R_AddPotentiallyShadowedLight
==============
*/
unsigned int R_AddPotentiallyShadowedLight(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AddShadowedLightToShadowHistory
==============
*/
void R_AddShadowedLightToShadowHistory(
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
unsigned int R_GetPrimaryLightEntityShadowBit(
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
void R_LinkSphereEntityToPrimaryLights(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LinkBoxEntityToPrimaryLights
==============
*/
void R_LinkBoxEntityToPrimaryLights(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LinkDynEntToPrimaryLights
==============
*/
void R_LinkDynEntToPrimaryLights(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UnlinkEntityFromPrimaryLights
==============
*/
void R_UnlinkEntityFromPrimaryLights(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UnlinkDynEntFromPrimaryLights
==============
*/
void R_UnlinkDynEntFromPrimaryLights(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_IsEntityVisibleToPrimaryLight
==============
*/
/*BOOL R_IsEntityVisibleToPrimaryLight@<eax>(unsigned int a1@<edx>, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
R_IsDynEntVisibleToPrimaryLight
==============
*/
/*BOOL R_IsDynEntVisibleToPrimaryLight@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

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
BOOL R_IsDynEntVisibleToAnyShadowedLight(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ShowPrimaryLightDebugLine
==============
*/
void R_ShowPrimaryLightDebugLine(
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

