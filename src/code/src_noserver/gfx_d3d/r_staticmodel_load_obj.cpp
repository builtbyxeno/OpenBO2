#include "types.h"
#include "functions.h"

/*
==============
R_CellForPoint
==============
*/
int R_CellForPoint(const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_FindNearestReflectionProbeInCell
==============
*/
unsigned int R_FindNearestReflectionProbeInCell(int cellIndex, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_FindNearestReflectionProbe
==============
*/
unsigned int R_FindNearestReflectionProbe(const GfxWorldDraw *worldDraw, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_FindProbeFromVolume
==============
*/
unsigned int R_FindProbeFromVolume(const GfxWorldDraw *worldDraw, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_CalcReflectionProbeIndex
==============
*/
unsigned int R_CalcReflectionProbeIndex(const vec3_t *a1, const GfxWorldDraw *a2, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AllocStaticModels
==============
*/
void R_AllocStaticModels(GfxAabbTree *tree)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SortGfxAabbTreeChildren
==============
*/
int R_SortGfxAabbTreeChildren(GfxWorld *world, vec3_t *mins, vec3_t *maxs, unsigned __int16 *staticModels, int staticModelCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CompareStaticModels
==============
*/
int CompareStaticModels(const void *smodel0, const void *smodel1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SortGfxAabbTree
==============
*/
void R_SortGfxAabbTree(GfxWorld *world, GfxAabbTree *tree)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddStaticModelToAabbTree_r
==============
*/
void R_AddStaticModelToAabbTree_r(GfxWorld *world, GfxAabbTree *tree, int smodelIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddStaticModelToCell
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
GetNameFromStaticModelInst
==============
*/
const char *GetNameFromStaticModelInst(const GfxStaticModelInst *smodelInst)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_FilterStaticModelIntoCells_r
==============
*/
void R_FilterStaticModelIntoCells_r(float world, const cplane_s *a2, float node, GfxWorld *a4, mnode_t *smodelInst, GfxStaticModelInst *mins, const vec3_t *maxs, const vec3_t *a8)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CellForPoint
==============
*/
int R_CellForPoint(const GfxWorld *world, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_CalcReflectionProbeIndex
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
R_SetStaticModelReflectionProbe
==============
*/
void R_SetStaticModelReflectionProbe(const vec3_t *a1, const GfxWorld *world, const GfxStaticModelInst *smodelInst, GfxStaticModelDrawInst *smodelDrawInst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CreateStaticModel
==============
*/
void R_CreateStaticModel(XModel *model, const vec3_t *origin, const vec3_t *axis, float scale, GfxStaticModelDrawInst *smodelDrawInst, GfxStaticModelInst *smodelInst, unsigned int staticModelFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

