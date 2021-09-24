#include "types.h"

/*
==============
R_SetPrimaryLightShadowSurfaces
==============
*/
GfxWorld *R_SetPrimaryLightShadowSurfaces()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_GetWorldDrawSurf
==============
*/
int R_GetWorldDrawSurf(GfxSurface *worldSurf)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SortWorldSurfaces
==============
*/
void R_SortWorldSurfaces()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AllocFxDrawSurf
==============
*/
GfxDrawSurf *R_AllocFxDrawSurf(unsigned int region)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_GetDrawSurfRegionForSortKey
==============
*/
unsigned int R_GetDrawSurfRegionForSortKey(const Material *material, unsigned int baseRegion)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AddCodeMeshDrawSurf
==============
*/
void R_AddCodeMeshDrawSurf(float material, Material *a2, r_double_index_t *indices, unsigned int indexCount, unsigned int argOffset, unsigned int argCount, const char *fxName, unsigned int region, bool enableDepthHack)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCodeMeshDrawSurf_UseIndices
==============
*/
void R_AddCodeMeshDrawSurf_UseIndices(float material, Material *a2, r_double_index_t *indices, unsigned int indexCount, unsigned int argOffset, unsigned int argCount, const char *fxName, unsigned int region, bool enableDepthHack, bool superflare)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddRopeCodeMeshDrawSurf
==============
*/
void R_AddRopeCodeMeshDrawSurf(float material, const Material *a2, r_double_index_t *indices, unsigned int indexCount, unsigned int argOffset, unsigned int argCount, unsigned int primaryLightIndex, unsigned int reflectionProbeIndex, unsigned int drawsurfRegion)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddGlassDrawSurf
==============
*/
FxCodeMeshData *R_AddGlassDrawSurf(float material, Material *a2, unsigned __int16 *indices, unsigned int indexCount, GfxDrawSurf **retDrawSurf)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_AddMarkMeshDrawSurf
==============
*/
void R_AddMarkMeshDrawSurf(float refLitTechType, Material *material, const GfxMarkContext *context, unsigned __int16 *indices, unsigned int indexCount, unsigned int visLightsMask)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddParticleCloudDrawSurf
==============
*/
char R_AddParticleCloudDrawSurf(float cloudIndex, unsigned int a2, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_BeginCodeMeshVerts
==============
*/
void R_BeginCodeMeshVerts()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_EndCodeMeshVerts
==============
*/
void R_EndCodeMeshVerts()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_BeginMarkMeshVerts
==============
*/
void R_BeginMarkMeshVerts()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_EndMarkMeshVerts
==============
*/
void R_EndMarkMeshVerts()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ReserveCodeMeshIndices
==============
*/
char R_ReserveCodeMeshIndices(float indexCount, int a2, r_double_index_t **indicesOut)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ReserveCodeMeshVerts
==============
*/
char R_ReserveCodeMeshVerts(float vertCount, int a2, unsigned __int16 *baseVertex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ReserveCodeMeshArgs
==============
*/
char R_ReserveCodeMeshArgs(float argCount, int a2, unsigned int *argOffsetOut)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ReserveMarkMeshIndices
==============
*/
char R_ReserveMarkMeshIndices(float indexCount, int a2, r_double_index_t **indicesOut)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ReserveMarkMeshVerts
==============
*/
char R_ReserveMarkMeshVerts(float vertCount, int a2, unsigned __int16 *baseVertex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_GetCodeMeshArgs
==============
*/
vec4_t *R_GetCodeMeshArgs(unsigned int argOffset)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_GetCodeMeshVerts
==============
*/
GfxPackedVertex *R_GetCodeMeshVerts(unsigned __int16 baseVertex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_GetMarkMeshVerts
==============
*/
GfxWorldVertex *R_GetMarkMeshVerts(unsigned __int16 baseVertex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_SortDrawSurfs
==============
*/
void R_SortDrawSurfs(int a1, GfxDrawSurf *drawSurfList)
{
	UNIMPLEMENTED(__FUNCTION__);
}

