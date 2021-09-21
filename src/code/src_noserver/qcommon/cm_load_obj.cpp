#include "types.h"
#include "functions.h"

/*
==============
CMod_LoadMaterials
==============
*/
unsigned int CMod_LoadMaterials()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CMod_LoadSubmodels
==============
*/
void CMod_LoadSubmodels()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CMod_GetPartitionScore
==============
*/
float CMod_GetPartitionScore(unsigned __int16 *leafBrushes, int numLeafBrushes, int axis, const vec3_t *mins, const vec3_t *maxs, float *dist)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CMod_PartionLeafBrushes_r
==============
*/
cLeafBrushNode_s *CMod_PartionLeafBrushes_r(char *a1, unsigned __int16 *leafBrushes, int numLeafBrushes, const vec3_t *mins, const vec3_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CMod_PartionLeafBrushes
==============
*/
void CMod_PartionLeafBrushes(unsigned __int16 *leafBrushes, int numLeafBrushes, cLeaf_s *leaf)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CMod_LoadSubmodelBrushNodes
==============
*/
unsigned int CMod_LoadSubmodelBrushNodes(char *a1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CMod_LoadNodes
==============
*/
cNode_t *CMod_LoadNodes()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CMod_LoadBrushes
==============
*/
vec3_t *CMod_LoadBrushes()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CMod_LoadLeafs
==============
*/
void CMod_LoadLeafs(bool usePvs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CMod_LoadLeafs_Version14
==============
*/
void CMod_LoadLeafs_Version14(bool usePvs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CMod_LoadLeafBrushNodes
==============
*/
int *CMod_LoadLeafBrushNodes(char *a1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CMod_LoadLeafBrushNodes_Version14
==============
*/
int *CMod_LoadLeafBrushNodes_Version14(char *a1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CMod_LoadPlanes
==============
*/
void CMod_LoadPlanes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CMod_LoadLeafBrushes
==============
*/
unsigned __int16 *CMod_LoadLeafBrushes()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CMod_LoadCollisionPartitions
==============
*/
CollisionPartition *CMod_LoadCollisionPartitions()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CMod_LoadCollisionAabbTrees
==============
*/
CollisionAabbTree *CMod_LoadCollisionAabbTrees()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
MapEnts_CanPurgeEntity
==============
*/
bool MapEnts_CanPurgeEntity(const char *classname, void *userData, const char *(*GetKeyCallback)(void *, const char *))
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CMod_GetSpawnString
==============
*/
const char *CMod_GetSpawnString(void *userData, const char *key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
MapEnts_GetFromString
==============
*/
MapEnts *MapEnts_GetFromString(const char *name, const char *entityString)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CMod_LoadVisibility
==============
*/
void CMod_LoadVisibility()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EmitTechniqueSetName
==============
*/
unsigned int EmitTechniqueSetName(const char *techSetName, char **emittedTechSetNames, unsigned int emittedCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AppendTechniqueSetName
==============
*/
unsigned int AppendTechniqueSetName(char *name, unsigned int nameLen, const char *append, char lyrToken)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FindLayeredTechniqueSetNameInTable
==============
*/
LayeredTechniqueSetName *FindLayeredTechniqueSetNameInTable(const char *techSetName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GetLayeredTechniqueSetName
==============
*/
const LayeredTechniqueSetName *GetLayeredTechniqueSetName(const char *mtlName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
AssembleLayeredMaterial
==============
*/
unsigned int AssembleLayeredMaterial(const dmaterial_t *diskMtl, const LayeredTechniqueSetName **lyrTechSetName, const char *lyrMtlName, char **emittedTechSetNames, unsigned int emittedCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CompareTechSetNames
==============
*/
int CompareTechSetNames(const void *e0, const void *e1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_InitBoxHull
==============
*/
unsigned int CM_InitBoxHull()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_GetPlanes
==============
*/
cplane_s *CM_GetPlanes()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CM_GetPlaneCount
==============
*/
int CM_GetPlaneCount()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_EntityString
==============
*/
char *CM_EntityString()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CMod_LoadBrushRelated
==============
*/
void CMod_LoadBrushRelated(unsigned int version, bool usePvs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RunPIMP
==============
*/
/*void RunPIMP(const std::string *MaterialSubset)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
AssembleBspLayeredMaterials
==============
*/
void AssembleBspLayeredMaterials(char *a1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_LoadMapFromBsp
==============
*/
void CM_LoadMapFromBsp(const char *name, char usePvs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

