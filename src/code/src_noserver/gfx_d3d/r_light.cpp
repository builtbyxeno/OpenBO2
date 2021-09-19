#include "types.h"
#include "functions.h"

/*
==============
R_RegisterLightDef_LoadObj
==============
*/
GfxLightDef *R_RegisterLightDef_LoadObj(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_RegisterLightDef_FastFile
==============
*/
GfxLightDef *R_RegisterLightDef_FastFile(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_RegisterLightDef
==============
*/
GfxLightDef *R_RegisterLightDef()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_InitFlashlight
==============
*/
void R_InitFlashlight()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LightImportanceGreaterEqual
==============
*/
bool R_LightImportanceGreaterEqual(const GfxLight *light0, const GfxLight *light1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_MostImportantLights
==============
*/
/*void R_MostImportantLights(const GfxLight *a1@<edx>, const GfxLight **lights, int lightCount, int keepCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
R_GetPointLightPartitions
==============
*/
/*int R_GetPointLightPartitions@<eax>(GfxLight *visibleLights)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
R_ComputeSpotLightCrossDirs
==============
*/
void R_ComputeSpotLightCrossDirs(const GfxLight *light, vec3_t *crossDirs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CalcSpotLightPlanes
==============
*/
void R_CalcSpotLightPlanes(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetSceneEntLightSurfs
==============
*/
void R_GetSceneEntLightSurfs(const GfxLight *visibleLights, int visibleCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SortSceneEntLightSurfs
==============
*/
void R_SortSceneEntLightSurfs(const GfxLight *visibleLights, int visibleCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AllowBspSpotLightShadows
==============
*/
BOOL R_AllowBspSpotLightShadows(int surfIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SortBspLightSurfaces
==============
*/
BOOL R_SortBspLightSurfaces(GfxSurface *surface0, GfxSurface *surface1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AllowStaticModelSpotLight
==============
*/
BOOL R_AllowStaticModelSpotLight(int smodelIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_GetStaticModelLightSurfs
==============
*/
void R_GetStaticModelLightSurfs(int viewIndex, const GfxLight *visibleLights, int visibleCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SortStaticModelLightSurfs
==============
*/
void R_SortStaticModelLightSurfs(const GfxLight *visibleLights, int visibleCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetBspLightSurfs
==============
*/
void R_GetBspLightSurfs(const GfxLight *visibleLights, int visibleCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

