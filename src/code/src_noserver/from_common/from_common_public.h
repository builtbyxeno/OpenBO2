#pragma once

#include "types.h"

//t6/code/src_noserver/from_common/brush_edges.cpp
float RepresentativeTriangleFromWinding(;
int GetPointListAllowDupes(;
char PlaneInCommonExcluding(;
int ThirdPlane(const SimplePlaneIntersection *point, int plane1, int plane2);
int NumberOfOccurancesOfPlane(int planeIndex, const SimplePlaneIntersection **pts, int ptCount);
bool FindCycleBFS(;
int RemovePtsWithPlanesThatOccurLessThanTwice(const SimplePlaneIntersection **pts, int ptsCount);
int GetPtsFormedByPlane(;
float CyclePerimiter(const SimplePlaneIntersection **pts, int ptsCount);
bool IsConvex(const vec3_t *pts, unsigned int ptCount);
bool TestConvexWithoutNearPoints(const SimplePlaneIntersection **pts, unsigned int ptCount);
int ChooseEdgeToRemove(;
int PartitionEdges(;
int ReduceToACycle(int basePlane, const SimplePlaneIntersection **pts, int ptsCount);
int NumberOfUniquePoints(const SimplePlaneIntersection **pts, int ptsCount);
adjacencyWinding_t *BuildBrushdAdjacencyWindingForSide(;

