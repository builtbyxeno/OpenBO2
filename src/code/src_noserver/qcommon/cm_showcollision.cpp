#include "types.h"

/*
==============
TRACK_cm_showcollision
==============
*/
void TRACK_cm_showcollision()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_BrushInView
==============
*/
bool CM_BrushInView(const cbrush_t *brush, cplane_s *frustumPlanes, int frustumPlaneCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_AddSimpleBrushPoint
==============
*/
int CM_AddSimpleBrushPoint(const cbrush_t *brush, const vec4_t *axialPlanes, const __int16 *sideIndices, const vec3_t *xyz, int ptCount, ShowCollisionBrushPt *brushPts)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_GetPlaneVec4Form
==============
*/
void CM_GetPlaneVec4Form(const cbrushside_t *sides, const vec4_t *axialPlanes, int index, vec4_t *expandedPlane)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_ForEachBrushPlaneIntersection
==============
*/
int CM_ForEachBrushPlaneIntersection(const cbrush_t *brush, const vec4_t *axialPlanes, ShowCollisionBrushPt *brushPts)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_GetXyzList
==============
*/
int CM_GetXyzList(int sideIndex, const ShowCollisionBrushPt *pts, int ptCount, vec3_t *xyz, int xyzLimit)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_AddColinearExteriorPointToWindingProjected
==============
*/
void CM_AddColinearExteriorPointToWindingProjected(winding_t *w, const vec3_t *pt, int i, int j, int index0, int index1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_AddExteriorPointToWindingProjected
==============
*/
void CM_AddExteriorPointToWindingProjected(winding_t *w, const vec3_t *pt, int i, int j)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_RepresentativeTriangleFromWinding
==============
*/
float CM_RepresentativeTriangleFromWinding(const winding_t *w, const vec3_t *normal, int *i0, int *i1, int *i2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_ReverseWinding
==============
*/
void CM_ReverseWinding(winding_t *w)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_BuildBrushWindingForSide
==============
*/
bool CM_BuildBrushWindingForSide(winding_t *winding, vec3_t *planeNormal, int sideIndex, const ShowCollisionBrushPt *pts, int ptCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_ShowSingleBrushCollision
==============
*/
void CM_ShowSingleBrushCollision(const cbrush_t *brush, const vec4_t *color, void (*drawCollisionPoly)(int, vec3_t *, const vec4_t *))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_ShowBrushCollision
==============
*/
void CM_ShowBrushCollision(int contentMask, cplane_s *frustumPlanes, int frustumPlaneCount, void (*drawCollisionPoly)(int, vec3_t *, const vec4_t *))
{
	UNIMPLEMENTED(__FUNCTION__);
}

