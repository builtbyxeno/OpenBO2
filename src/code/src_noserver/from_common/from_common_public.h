#pragma once

#include "types.h"

//t6/code/src_noserver/from_common/brush_edges.cpp
float RepresentativeTriangleFromWinding(const vec3_t *xyz, int pointCount, const vec3_t *normal, int *i0, int *i1, int *i2);
int GetPointListAllowDupes(int planeIndex, const SimplePlaneIntersection *pts, int ptCount, const SimplePlaneIntersection **xyz, int xyzLimit);
char PlaneInCommonExcluding(const SimplePlaneIntersection *pt1, const SimplePlaneIntersection *pt2, int excludePlane, int *result);
int ThirdPlane(const SimplePlaneIntersection *point, int plane1, int plane2);
int NumberOfOccurancesOfPlane(int planeIndex, const SimplePlaneIntersection **pts, int ptCount);
bool FindCycleBFS(int basePlane, const SimplePlaneIntersection **pts, int ptsCount, const SimplePlaneIntersection *start, const SimplePlaneIntersection *end, int connectingPlane, const SimplePlaneIntersection **resultCycle, int *resultCycleCount);
int RemovePtsWithPlanesThatOccurLessThanTwice(const SimplePlaneIntersection **pts, int ptsCount);
int GetPtsFormedByPlane(int planeIndex, const SimplePlaneIntersection **pts, int ptCount, const SimplePlaneIntersection **result, int maxResults);
float CyclePerimiter(const SimplePlaneIntersection **pts, int ptsCount);
bool IsConvex(const vec3_t *pts, unsigned int ptCount);
bool TestConvexWithoutNearPoints(const SimplePlaneIntersection **pts, unsigned int ptCount);
int ChooseEdgeToRemove(int basePlane, int connectingPlane, const SimplePlaneIntersection **pts, int ptsCount, const SimplePlaneIntersection **edges);
int PartitionEdges(int basePlane, int connectingPlane, const SimplePlaneIntersection **pts, int ptsCount, const SimplePlaneIntersection **edges, int edgeCount, int *partition);
int ReduceToACycle(int basePlane, const SimplePlaneIntersection **pts, int ptsCount);
int NumberOfUniquePoints(const SimplePlaneIntersection **pts, int ptsCount);
adjacencyWinding_t *BuildBrushdAdjacencyWindingForSide(float a1, const char *name, const vec3_t *sideNormal, int basePlaneIndex, const SimplePlaneIntersection *InPts, int InPtCount, adjacencyWinding_t *optionalOutWinding, int optionalOutWindingCount);

