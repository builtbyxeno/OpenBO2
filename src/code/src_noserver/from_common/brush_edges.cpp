#include "types.h"

/*
==============
RepresentativeTriangleFromWinding
==============
*/
float RepresentativeTriangleFromWinding(const vec3_t *xyz, int pointCount, const vec3_t *normal, int *i0, int *i1, int *i2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetPointListAllowDupes
==============
*/
int GetPointListAllowDupes(int planeIndex, const SimplePlaneIntersection *pts, int ptCount, const SimplePlaneIntersection **xyz, int xyzLimit)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PlaneInCommonExcluding
==============
*/
char PlaneInCommonExcluding(const SimplePlaneIntersection *pt1, const SimplePlaneIntersection *pt2, int excludePlane, int *result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ThirdPlane
==============
*/
int ThirdPlane(const SimplePlaneIntersection *point, int plane1, int plane2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NumberOfOccurancesOfPlane
==============
*/
int NumberOfOccurancesOfPlane(int planeIndex, const SimplePlaneIntersection **pts, int ptCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FindCycleBFS
==============
*/
bool FindCycleBFS(int basePlane, const SimplePlaneIntersection **pts, int ptsCount, const SimplePlaneIntersection *start, const SimplePlaneIntersection *end, int connectingPlane, const SimplePlaneIntersection **resultCycle, int *resultCycleCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RemovePtsWithPlanesThatOccurLessThanTwice
==============
*/
int RemovePtsWithPlanesThatOccurLessThanTwice(const SimplePlaneIntersection **pts, int ptsCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetPtsFormedByPlane
==============
*/
int GetPtsFormedByPlane(int planeIndex, const SimplePlaneIntersection **pts, int ptCount, const SimplePlaneIntersection **result, int maxResults)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CyclePerimiter
==============
*/
float CyclePerimiter(const SimplePlaneIntersection **pts, int ptsCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IsConvex
==============
*/
bool IsConvex(const vec3_t *pts, unsigned int ptCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TestConvexWithoutNearPoints
==============
*/
bool TestConvexWithoutNearPoints(const SimplePlaneIntersection **pts, unsigned int ptCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ChooseEdgeToRemove
==============
*/
int ChooseEdgeToRemove(int basePlane, int connectingPlane, const SimplePlaneIntersection **pts, int ptsCount, const SimplePlaneIntersection **edges)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartitionEdges
==============
*/
int PartitionEdges(int basePlane, int connectingPlane, const SimplePlaneIntersection **pts, int ptsCount, const SimplePlaneIntersection **edges, int edgeCount, int *partition)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ReduceToACycle
==============
*/
int ReduceToACycle(int basePlane, const SimplePlaneIntersection **pts, int ptsCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NumberOfUniquePoints
==============
*/
int NumberOfUniquePoints(const SimplePlaneIntersection **pts, int ptsCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BuildBrushdAdjacencyWindingForSide
==============
*/
adjacencyWinding_t *BuildBrushdAdjacencyWindingForSide(float a1, const char *name, const vec3_t *sideNormal, int basePlaneIndex, const SimplePlaneIntersection *InPts, int InPtCount, adjacencyWinding_t *optionalOutWinding, int optionalOutWindingCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

