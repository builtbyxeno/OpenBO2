#include "types.h"
#include "functions.h"

/*
==============
CM_IsEdgeWalkable
==============
*/
bool CM_IsEdgeWalkable(int triIndex, int edgeIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_TracePointThroughTriangle
==============
*/
void CM_TracePointThroughTriangle(const traceWork_t *tw, const unsigned __int16 *indices, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TraceSphereThroughEdge
==============
*/
SphereEdgeTraceResult CM_TraceSphereThroughEdge(const traceWork_t *tw, const vec3_t *sphereStart, const vec3_t *v0, const vec3_t *v0_v1, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	SphereEdgeTraceResult tmp;
	return tmp;
}

/*
==============
CM_TraceSphereThroughVertex
==============
*/
void CM_TraceSphereThroughVertex(const traceWork_t *tw, bool isWalkable, const vec3_t *sphereStart, const vec3_t *v, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TraceCapsuleThroughTriangle
==============
*/
void CM_TraceCapsuleThroughTriangle(const traceWork_t *tw, int triIndex, const unsigned __int16 *indices, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_ClosestPointOnTri
==============
*/
void CM_ClosestPointOnTri(const vec3_t *pt, const vec3_t *v0, const vec3_t *e0, const vec3_t *e1, float a01, vec3_t *ptOnTri)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_DistanceSquaredBetweenSegments
==============
*/
float CM_DistanceSquaredBetweenSegments(const vec3_t *start0, const vec3_t *start1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_DoesCapsuleIntersectTriangle
==============
*/
bool CM_DoesCapsuleIntersectTriangle(const vec3_t *start, const vec3_t *end, float radiusSq, const unsigned __int16 *indices)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CM_PositionTestCapsuleInTriangle
==============
*/
void CM_PositionTestCapsuleInTriangle(const traceWork_t *tw, const unsigned __int16 *indices, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TraceThroughAabbTree_work
==============
*/
void CM_TraceThroughAabbTree_work(const traceWork_t *tw, const CollisionAabbTree *aabbTree, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TraceThroughAabbTree_r
==============
*/
void CM_TraceThroughAabbTree_r(const traceWork_t *tw, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TraceThroughPartition
==============
*/
void CM_TraceThroughPartition(int a1, const traceWork_t *tw, int partitionIndex, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_PositionTestInAabbTree_r
==============
*/
void CM_PositionTestInAabbTree_r(const traceWork_t *tw, CollisionAabbTree *aabbTree, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_TraceThroughAabbTree
==============
*/
void CM_TraceThroughAabbTree(const traceWork_t *tw, const CollisionAabbTree *aabbTree, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_MeshTestInLeaf
==============
*/
void CM_MeshTestInLeaf(const traceWork_t *tw, cLeaf_s *leaf, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_MeshTest
==============
*/
void __cdecl CM_MeshTest(const traceWork_t *tw, const CollisionAabbTree *tree, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

