#include "types.h"
#include "functions.h"

/*
==============
ParseKVPFileFloatKVP
==============
*/
bool ParseKVPFileFloatKVP(char *kvpFile, char *kvp, vec3_t *vec)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ParseKVPFileVec3KVP
==============
*/
bool ParseKVPFileVec3KVP(char *kvpFile, char *kvp, vec3_t *vec)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TRACK_r_bsp_load_obj
==============
*/
void TRACK_r_bsp_load_obj()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetBspMaterial
==============
*/
Material *R_GetBspMaterial(unsigned int materialIndex, GfxSurface *surface)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_CreateWorldVertexBuffer
==============
*/
void R_CreateWorldVertexBuffer(ID3D11Buffer **vb, const void *srcData, unsigned int sizeInBytes)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UpdateDiskSurfaces_Version14
==============
*/
const DiskTriangleSoup *R_UpdateDiskSurfaces_Version14(const DiskTriangleSoup *oldSurfs, int surfCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_UpdateDiskSurfaces_Version12
==============
*/
const DiskTriangleSoup *R_UpdateDiskSurfaces_Version12(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_UpdateDiskSurfaces_Version8
==============
*/
const DiskTriangleSoup *R_UpdateDiskSurfaces_Version8(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_LoadTriangleSurfaces
==============
*/
void R_LoadTriangleSurfaces(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DetermineLightmapCoupling
==============
*/
int R_DetermineLightmapCoupling(GfxBspLoad *load, long double (*coupling)[30], LumpType lumpType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_BuildLightmapMergability
==============
*/
int R_BuildLightmapMergability(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_LoadLightmaps
==============
*/
void R_LoadLightmaps(GfxBspLoad *load)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AssertLightGridValid
==============
*/
void R_AssertLightGridValid(const GfxLightGrid *lightGrid)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LoadLightGridHeader
==============
*/
void R_LoadLightGridHeader()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LoadLightGridColors
==============
*/
void R_LoadLightGridColors(unsigned int bspVersion)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LoadLightGridEntries
==============
*/
GfxLightGridEntry *R_LoadLightGridEntries()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_LoadReflectionProbes
==============
*/
void R_LoadReflectionProbes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_HeroLightSorter
==============
*/
int R_HeroLightSorter(const void *a, const void *b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_BuildHeroLightTree
==============
*/
void R_BuildHeroLightTree(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LoadHeroOnlyLights
==============
*/
void R_LoadHeroOnlyLights(unsigned int bspVersion)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LoadCoronas
==============
*/
GfxLightCorona *R_LoadCoronas()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_LoadOccluders
==============
*/
unsigned __int8 *R_LoadOccluders()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_LoadShadowMapVolumes
==============
*/
unsigned __int8 *R_LoadShadowMapVolumes()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_LoadExposureVolumes
==============
*/
unsigned __int8 *R_LoadExposureVolumes()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_LoadWorldFogVolumes
==============
*/
void R_LoadWorldFogVolumes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LoadWorldFogModifierVolumes
==============
*/
void R_LoadWorldFogModifierVolumes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LoadLutVolumes
==============
*/
void R_LoadLutVolumes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CalculateSurfaceBounds
==============
*/
void R_CalculateSurfaceBounds(GfxSurface *surface, const DiskGfxVertex *vertsDisk, int vertCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_MergeSurfaceLightMapCoords
==============
*/
void R_MergeSurfaceLightMapCoords(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CalculateOutdoorBounds
==============
*/
void R_CalculateOutdoorBounds(GfxBspLoad *load, const DiskTriangleSoup *diskSurfaces)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CompareSurfaces
==============
*/
bool R_CompareSurfaces(const GfxSurface *surf0, const GfxSurface *surf1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SortSurfacesOnAxis_PosX
==============
*/
BOOL R_SortSurfacesOnAxis_PosX(const GfxSurface *surf0, const GfxSurface *surf1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SortSurfacesOnAxis_NegX
==============
*/
BOOL R_SortSurfacesOnAxis_NegX(const GfxSurface *surf0, const GfxSurface *surf1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SortSurfacesOnAxis_PosY
==============
*/
BOOL R_SortSurfacesOnAxis_PosY(const GfxSurface *surf0, const GfxSurface *surf1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SortSurfacesOnAxis_NegY
==============
*/
BOOL R_SortSurfacesOnAxis_NegY(const GfxSurface *surf0, const GfxSurface *surf1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_PackPosition
==============
*/
void R_PackPosition(const vec3_t dataDisk, vec3_t *dataMem)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_PackWorldVertex0
==============
*/
void R_PackWorldVertex0(const GfxSurface *surface, unsigned __int8 *out, const GfxWorldVertex *worldVert)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_PackWorldVertex1
==============
*/
void R_PackWorldVertex1(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ValidateSurfaceLightmapUsage
==============
*/
void R_ValidateSurfaceLightmapUsage(const GfxSurface *surface)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CalculateTriangleGroupTexCoordExtents
==============
*/
void R_CalculateTriangleGroupTexCoordExtents(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LoadSubmodels
==============
*/
void R_LoadSubmodels()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FloatForKey
==============
*/
float R_FloatForKey(const char *key, float defaultValue, char *(*spawnVars)[2], int spawnVarCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_IntForKey
==============
*/
int R_IntForKey(const char *key, int defaultValue, char *(*spawnVars)[2], int spawnVarCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_VectorForKey
==============
*/
bool R_VectorForKey(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_LoadStaticModelData
==============
*/
void R_LoadStaticModelData(int bspVersion)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LoadSkyGridVolumes
==============
*/
void R_LoadSkyGridVolumes(int bspVersion)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_PrefixStaticModelName
==============
*/
void R_PrefixStaticModelName(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CheckValidStaticModel
==============
*/
bool R_CheckValidStaticModel(char *(*spawnVars)[2], int spawnVarCount, XModel **model, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetStaticModelsLightmapData
==============
*/
void R_SetStaticModelsLightmapData()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LoadMiscModel
==============
*/
/*void R_LoadMiscModel(int a1@<edx>, char *(*spawnVars)[2], int spawnVarCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
R_ParseSunLight
==============
*/
char *R_ParseSunLight(SunLightParseParams *params, const char *text)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_LoadPrimaryLights
==============
*/
void R_LoadPrimaryLights(unsigned int bspVersion)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LoadLightRegions
==============
*/
void R_LoadLightRegions()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetStaticModelSortIndex
==============
*/
unsigned int R_GetStaticModelSortIndex(const XModel *model)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_StaticModelCompare
==============
*/
bool R_StaticModelCompare(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AabbTreeChildrenCount_r
==============
*/
int R_AabbTreeChildrenCount_r(GfxAabbTree *tree)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AabbTreeFixAABBSizes_r
==============
*/
void R_AabbTreeFixAABBSizes_r(GfxAabbTree *tree)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AabbTreeMove_r
==============
*/
GfxAabbTree *R_AabbTreeMove_r(GfxAabbTree *tree, GfxAabbTree *newTree, GfxAabbTree *newChildren)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_FixupGfxAabbTrees
==============
*/
void R_FixupGfxAabbTrees(GfxCell *cell)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SortStaticModelsOnAxis_NegX
==============
*/
BOOL R_SortStaticModelsOnAxis_NegX(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SortStaticModelsOnAxis_PosY
==============
*/
BOOL R_SortStaticModelsOnAxis_PosY(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SortStaticModelsOnAxis_NegY
==============
*/
BOOL R_SortStaticModelsOnAxis_NegY(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_CompareStaticModelSortModels
==============
*/
bool R_CompareStaticModelSortModels(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_LoadEntities
==============
*/
void R_LoadEntities()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FinishLoadingAabbTrees_r
==============
*/
int R_FinishLoadingAabbTrees_r(GfxAabbTree *tree, int totalTreesUsed)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_LoadAabbTrees
==============
*/
unsigned int R_LoadAabbTrees()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_LoadCells
==============
*/
void R_LoadCells(unsigned int bspVersion)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LoadPortals
==============
*/
GfxPortal *R_LoadPortals()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_SetParentAndCell_r
==============
*/
void R_SetParentAndCell_r(mnode_load_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CountNodes_r
==============
*/
unsigned int R_CountNodes_r(mnode_load_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SortNodes_r
==============
*/
mnode_t *R_SortNodes_r(mnode_load_t *node, mnode_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_LoadNodesAndLeafs
==============
*/
void R_LoadNodesAndLeafs(unsigned int bspVersion)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AllocPrimaryLightBuffers
==============
*/
unsigned __int8 *R_AllocPrimaryLightBuffers()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_LoadWorldRuntime
==============
*/
unsigned __int8 *R_LoadWorldRuntime()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_SetStaticModelReflectionProbes
==============
*/
void R_SetStaticModelReflectionProbes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_IncrementShadowGeometryCount
==============
*/
void R_IncrementShadowGeometryCount(GfxWorld *world, unsigned int primaryLightIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetUpSunLight
==============
*/
void R_SetUpSunLight(const vec3_t *sunColor, const vec3_t *sunDirection, GfxLight *light)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InterpretSunLightParseParamsIntoLights
==============
*/
void R_InterpretSunLightParseParamsIntoLights(SunLightParseParams *sunParse, GfxLight *sunLight)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitPrimaryLights
==============
*/
void R_InitPrimaryLights(GfxLight *primaryLights)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ForEachPrimaryLightAffectingSurface
==============
*/
void R_ForEachPrimaryLightAffectingSurface(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetSurfaceVertexLayerDataStride
==============
*/
MaterialTechniqueSet *R_GetSurfaceVertexLayerDataStride(const GfxSurface *surface)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_GetSurfaceVertexPosition
==============
*/
void R_GetSurfaceVertexPosition(const GfxSurface *surface, int vertIndex, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetSurfaceVertexLmapCoord
==============
*/
void R_GetSurfaceVertexLmapCoord(const GfxSurface *surface, int vertIndex, vec2_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetSurfaceVertexNormal
==============
*/
void R_GetSurfaceVertexNormal(const GfxSurface *surface, int vertIndex, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_RecenterSurfaceTexCoords
==============
*/
void R_RecenterSurfaceTexCoords(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LoadSurfaces
==============
*/
/*void R_LoadSurfaces(const DiskTriangleSoup **a1@<edx>, unsigned int a2@<ecx>, GfxBspLoad *load)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
R_LoadSunSettings
==============
*/
void R_LoadSunSettings()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ForEachShadowCastingSurfaceOnEachLight
==============
*/
void R_ForEachShadowCastingSurfaceOnEachLight(void (*Callback)(GfxWorld *, unsigned int, unsigned int))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddShadowSurfaceToPrimaryLight
==============
*/
void R_AddShadowSurfaceToPrimaryLight(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitShadowGeometryArrays
==============
*/
void R_InitShadowGeometryArrays()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SpatialSortSurfaceSubArray_r
==============
*/
void R_SpatialSortSurfaceSubArray_r(GfxSurface *beginSurf, GfxSurface *endSurf, unsigned int predIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SpatialSortAllSurfaces
==============
*/
void R_SpatialSortAllSurfaces(int surfaceCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SortSurfaces
==============
*/
void R_SortSurfaces()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SpatialSortStaticModelSubArray_r
==============
*/
void R_SpatialSortStaticModelSubArray_r(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SpatialSortAllStaticModels
==============
*/
void R_SpatialSortAllStaticModels(GfxStaticModelCombinedInst *smodelCombinedInsts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitSortStaticModelsByModel
==============
*/
void R_InitSortStaticModelsByModel()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_PostLoadEntities
==============
*/
void R_PostLoadEntities()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LoadWorldInternal
==============
*/
GfxWorld *R_LoadWorldInternal(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

