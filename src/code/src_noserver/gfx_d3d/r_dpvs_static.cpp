#include "types.h"

/*
==============
R_CullBoxLeaf
==============
*/
int R_CullBoxLeaf(const vec3_t *mins, const vec3_t *maxs, DpvsClipPlanes *planes)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TestOccluders
==============
*/
char TestOccluders(const vec3_t *bounds, int numOccluders, vec4_t *plane)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TestOccludersPartial
==============
*/
vec4_t *TestOccludersPartial(const vec3_t *bounds, int *numOccludersPtr, vec4_t *plane)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_AddAabbTreeSurfacesInFrustum_r
==============
*/
int R_AddAabbTreeSurfacesInFrustum_r(int a1, DpvsClipPlanes *a2, DpvsClipPlanes *tree, const GfxAabbTree *planes, const DpvsClipPlanes *treeDepth, int numOccluders, int occluderPlanes, vec4_t *a8)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AddCellStaticSurfacesInFrustum
==============
*/
int R_AddCellStaticSurfacesInFrustum(const DpvsPlanes *planes)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AddCellStaticSurfacesInFrustumCmd
==============
*/
void R_AddCellStaticSurfacesInFrustumCmd(void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
}

