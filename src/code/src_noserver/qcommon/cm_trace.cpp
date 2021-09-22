#include "types.h"
#include "functions.h"

/*
==============
col_context_t::col_context_t
==============
*/
/*void col_context_t::col_context_t(col_context_t *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
col_context_t::col_context_t
==============
*/
/*void col_context_t::col_context_t(col_context_t *notthis, int _mask)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
col_context_t::init_locational
==============
*/
/*void col_context_t::init_locational(col_context_t *notthis, int ent0)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
col_context_t::init_locational
==============
*/
/*void col_context_t::init_locational(col_context_t *notthis, int ent0, int ent1)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Trace_GetEntityHitId
==============
*/
int Trace_GetEntityHitId(const trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Trace_GetDynEntHitId
==============
*/
unsigned __int16 Trace_GetDynEntHitId(const trace_t *trace, DynEntityDrawType *drawType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Trace_GetGlassHitId
==============
*/
int Trace_GetGlassHitId(const trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_GetTraceThreadInfo
==============
*/
void CM_GetTraceThreadInfo(TraceThreadInfo *threadInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_GetClipMap
==============
*/
clipMap_t *CM_GetClipMap()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CM_GetBox
==============
*/
void CM_GetBox(cbrush_t **box_brush, cmodel_t **box_model, PhysGeomList ***geoms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TempBoxModel
==============
*/
unsigned int CM_TempBoxModel(cmodel_t **a1, const vec3_t *mins, const vec3_t *maxs, int contents)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_TempBrushModel
==============
*/
unsigned int CM_TempBrushModel(cmodel_t **a1, PhysGeomList *geoms)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_ClipHandleIsValid
==============
*/
bool CM_ClipHandleIsValid(unsigned int handle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_ClipHandleToModel
==============
*/
cmodel_t *CM_ClipHandleToModel(cmodel_t **a1, unsigned int handle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CM_ContentsOfModel
==============
*/
int CM_ContentsOfModel(cmodel_t **a1, unsigned int handle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_TestBoxInBrush
==============
*/
void CM_TestBoxInBrush(const traceWork_t *tw, const cbrush_t *brush, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TestInLeafBrushNode_r
==============
*/
void CM_TestInLeafBrushNode_r(const traceWork_t *tw, cLeafBrushNode_s *node, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TestInLeafBrushNode
==============
*/
int CM_TestInLeafBrushNode(traceWork_t *tw, cLeaf_s *leaf, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_TestCapsuleInCapsule
==============
*/
void CM_TestCapsuleInCapsule(const traceWork_t *tw, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_PositionTest
==============
*/
void CM_PositionTest(traceWork_t *tw, trace_t *trace, col_context_t *context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TraceThroughBrush
==============
*/
void CM_TraceThroughBrush(const traceWork_t *tw, const cbrush_t *brush, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TraceThroughLeafBrushNode_r
==============
*/
void CM_TraceThroughLeafBrushNode_r(const traceWork_t *tw, cLeafBrushNode_s *node, const vec4_t *p1_, const vec4_t *p2, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TraceThroughLeafBrushNode
==============
*/
bool CM_TraceThroughLeafBrushNode(const traceWork_t *tw, cLeaf_s *leaf, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_TraceThroughLeaf
==============
*/
void CM_TraceThroughLeaf(const traceWork_t *tw, cLeaf_s *leaf, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TestInTempBrush
==============
*/
void CM_TestInTempBrush(const traceWork_t *tw, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TraceThroughTempBrush
==============
*/
void __cdecl CM_TraceThroughTempBrush(const traceWork_t *tw, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TraceSphereThroughSphere
==============
*/
int CM_TraceSphereThroughSphere(const traceWork_t *tw, const vec3_t *vStart, const vec3_t *vEnd, const vec3_t *vStationary, float radius, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_TraceCylinderThroughCylinder
==============
*/
int CM_TraceCylinderThroughCylinder(const traceWork_t *tw, const vec3_t *vStationary, float fStationaryHalfHeight, float radius, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_TraceCapsuleThroughCapsule
==============
*/
void CM_TraceCapsuleThroughCapsule(const traceWork_t *tw, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TraceThroughTree
==============
*/
void CM_TraceThroughTree(const traceWork_t *tw, int num, const vec4_t *p1_, const vec4_t *p2, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TraceThroughPrimitives
==============
*/
void CM_TraceThroughPrimitives(const traceWork_t *tw, trace_t *trace, col_context_t *context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_SightTraceThroughBrush
==============
*/
int CM_SightTraceThroughBrush(const traceWork_t *tw, const cbrush_t *brush, int brushNum, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_SightTracePointThroughBrush
==============
*/
int CM_SightTracePointThroughBrush(const TraceExtents *extents, const cbrush_t *brush)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_SightTraceThroughLeafBrushNode_r
==============
*/
int CM_SightTraceThroughLeafBrushNode_r(const traceWork_t *tw, cLeafBrushNode_s *remoteNode, const vec3_t *p1_, const vec3_t *p2, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_SightTraceThroughLeafBrushNode
==============
*/
int CM_SightTraceThroughLeafBrushNode(const traceWork_t *tw, const cLeaf_s *leaf, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_SightTraceThroughLeaf
==============
*/
int CM_SightTraceThroughLeaf(const traceWork_t *tw, const cLeaf_s *leaf, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_SightTraceSphereThroughSphere
==============
*/
int CM_SightTraceSphereThroughSphere(const traceWork_t *tw, const vec3_t *vStart, const vec3_t *vEnd, const vec3_t *vStationary, float radius, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_SightTraceCylinderThroughCylinder
==============
*/
int CM_SightTraceCylinderThroughCylinder(const traceWork_t *tw, const vec3_t *vStationary, float fStationaryHalfHeight, float radius, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_SightTraceCapsuleThroughCapsule
==============
*/
int CM_SightTraceCapsuleThroughCapsule(const traceWork_t *tw, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_SightTraceThroughTree
==============
*/
int CM_SightTraceThroughTree(const traceWork_t *tw, int num, const vec3_t *p1_, const vec3_t *p2, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
calc_closest
==============
*/
void calc_closest(const vec3_t *v0, const vec3_t *v1, const vec3_t *v2, const vec3_t *p, vec3_t *res)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
is_inside
==============
*/
bool is_inside(const vec3_t *a, const vec3_t *b, const vec3_t *n, const vec3_t *p)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
point_in_triangle
==============
*/
bool point_in_triangle(const vec3_t *p, const vec3_t *v0, const vec3_t *v1, const vec3_t *v2, const vec3_t *n)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
trace_sphere_through_triangle
==============
*/
char trace_sphere_through_triangle(const vec3_t *c0, const vec3_t *dir, float *t, float r, const vec3_t *v0, const vec3_t *v1, const vec3_t *v2, const vec3_t *n)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
trace_sphere_through_partition
==============
*/
void trace_sphere_through_partition(const vec3_t *c, const vec3_t *dir, float *t, const float r, const CollisionAabbTree *tree, vec3_t *hitn, int *sflags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
trace_sphere_through_brush
==============
*/
void trace_sphere_through_brush(const vec3_t *c0, const vec3_t *dir, float *t, const float r, const cbrush_t *brush, vec3_t *hitn, int *sflags, bool *startSolid)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
trace_point_through_brush
==============
*/
void trace_point_through_brush(const vec3_t *c0, const vec3_t *dir, float *t, const cbrush_t *brush, vec3_t *hitn, int *sflags, bool *startSolid)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
trace_point_through_triangle
==============
*/
char trace_point_through_triangle(const vec3_t *p0, const vec3_t *u0, const vec3_t *v0, const vec3_t *v1, const vec3_t *v2, const float cur_t, float *t)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
trace_sphere_through_partition
==============
*/
void trace_sphere_through_partition(const vec3_t *p, const vec3_t *dir, float *t, const float r, const CollisionPartition *partition, vec3_t *hitn, int *hint, clipMap_t *pClipMap)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
trace_point_through_partition
==============
*/
void trace_point_through_partition(const vec3_t *p, const vec3_t *dir, float *t, const CollisionPartition *partition, vec3_t *hitn, int *hint, clipMap_t *pClipMap)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
trace_point_vs_env
==============
*/
void trace_point_vs_env(trace_t *trace, const vec3_t *start, const vec3_t *end, col_context_t *context, int *index_hint, clipMap_t *pClipMap)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
trace_point_vs_env
==============
*/
void trace_point_vs_env(trace_t *trace, const vec3_t *start, const vec3_t *end, col_context_t *context, int *index_hint)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
trace_point_vs_env
==============
*/
void trace_point_vs_env(trace_t *trace, const vec3_t *start, const vec3_t *end, col_context_t *context, int *index_hint, unsigned __int8 *pClipMap)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
trace_sphere_vs_env
==============
*/
void trace_sphere_vs_env(trace_t *trace, const vec3_t *start, const vec3_t *end, const float radius, col_context_t *context, int *index_hint, clipMap_t *pClipMap)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
trace_sphere_vs_env
==============
*/
void trace_sphere_vs_env(trace_t *trace, const vec3_t *start, const vec3_t *end, const float radius, col_context_t *context, int *index_hint, unsigned __int8 *pClipMap)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
collide_segment_brush
==============
*/
int collide_segment_brush(const vec3_t *p0, const vec3_t *p1, const cbrush_t *brush)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
collide_segment_triangle
==============
*/
BOOL collide_segment_triangle(const vec3_t *p0, const vec3_t *u0, const vec3_t *v0, const vec3_t *v1, const vec3_t *v2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
collide_segment
==============
*/
int collide_segment(const vec3_t *p0, const vec3_t *p1, col_context_t *context)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_GetWaterForce
==============
*/
bool CM_GetWaterForce(cmodel_t **plane, const vec3_t *pt, vec3_t *dir, float *force)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_GetClosestPointToBrush
==============
*/
void CM_GetClosestPointToBrush(const vec3_t *p, const cbrush_t *brush, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_SightTraceThroughTempBrush
==============
*/
int CM_SightTraceThroughTempBrush(const traceWork_t *tw, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_BoxSightTrace
==============
*/
int CM_BoxSightTrace(int a1, int oldHitNum, const vec3_t *start, const vec3_t *end, const vec3_t *mins, const vec3_t *maxs, unsigned int model, int brushmask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_SightTracePoint
==============
*/
int CM_SightTracePoint(int a1, int oldHitNum, const vec3_t *start, const vec3_t *end, col_context_t *context)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_TransformedBoxSightTrace
==============
*/
int CM_TransformedBoxSightTrace(int hitNum, const vec3_t *start, const vec3_t *end, const vec3_t *mins, const vec3_t *maxs, unsigned int model, int brushmask, const vec3_t *origin, const vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_TracePointDown
==============
*/
int CM_TracePointDown(int a1, const vec3_t *start, const vec3_t *end, int contentmask, int surf_type, vec3_t *endpos, float *fraction, vec3_t *normal)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_GetWaterHeight
==============
*/
double CM_GetWaterHeight(unsigned int a1, const vec3_t *pos, float z_up, float z_down)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_Trace
==============
*/
void CM_Trace(unsigned int a1, col_context_t *a2, trace_t *results, const vec3_t *start, const vec3_t *end, const vec3_t *mins, const vec3_t *maxs, unsigned int model, int brushmask, col_context_t *context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_BoxTrace
==============
*/
void CM_BoxTrace(col_context_t *a1, trace_t *results, const vec3_t *start, const vec3_t *end, const vec3_t *mins, const vec3_t *maxs, int brushmask, col_context_t *context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TransformedBoxTraceRotated
==============
*/
void CM_TransformedBoxTraceRotated(trace_t *results, const vec3_t *start, const vec3_t *end, const vec3_t *mins, const vec3_t *maxs, unsigned int model, int brushmask, const vec3_t *origin, const vec3_t *matrix)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TransformedBoxTrace
==============
*/
void CM_TransformedBoxTrace(trace_t *results, const vec3_t *start, const vec3_t *end, const vec3_t *mins, const vec3_t *maxs, unsigned int model, int brushmask, const vec3_t *origin, const vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TransformedBoxTraceExternal
==============
*/
void CM_TransformedBoxTraceExternal(trace_t *results, const vec3_t *start, const vec3_t *end, const vec3_t *mins, const vec3_t *maxs, unsigned int model, int brushmask, const vec3_t *origin, const vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_GetHeliHeight
==============
*/
char CM_GetHeliHeight(unsigned int a1, const vec3_t *pt, const float checkdist, float *result, const bool checkDisabledPatches)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

