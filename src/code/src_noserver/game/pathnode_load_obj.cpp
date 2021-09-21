#include "types.h"
#include "functions.h"

/*
==============
Path_CreateNodes
==============
*/
void Path_CreateNodes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_InitStatic
==============
*/
void Path_InitStatic(int restart)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_ShutdownStatic
==============
*/
void Path_ShutdownStatic()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_ParsePathnodeField
==============
*/
void G_ParsePathnodeField(const char *key, const char *value, pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_ParsePathnodeFields
==============
*/
void G_ParsePathnodeFields(SpawnVar *a1, SpawnVar *spawnVar, pathnode_t *node, nodeType type)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SP_spawn_node
==============
*/
/*void SP_spawn_node(const char *a1@<esi>, SpawnVar *spawnVar, nodeType type)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
SP_spawn_node_dynamic
==============
*/
/*pathnode_t *SP_spawn_node_dynamic@<eax>(const char *a1@<esi>, SpawnVar *spawnVar, nodeType type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
G_GetNodeTypeFromClassname
==============
*/
int G_GetNodeTypeFromClassname(const char *classname)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_SpawnPathnodeStatic
==============
*/
void G_SpawnPathnodeStatic(SpawnVar *spawnVar, const char *classname)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SpawnPathnodeStaticRunTime
==============
*/
pathnode_t *G_SpawnPathnodeStaticRunTime(SpawnVar *spawnVar, const char *classname)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_FreePathnodeFields
==============
*/
void Scr_FreePathnodeFields(pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_ErasePaths
==============
*/
void Path_ErasePaths(const char *pathsError)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_AreBackToBackCornerNodes
==============
*/
bool Path_AreBackToBackCornerNodes(pathnode_t *node, pathnode_t *otherNode)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_FindOverlappingNodes
==============
*/
BOOL Path_FindOverlappingNodes()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_BuildNodeBsp_r
==============
*/
pathnode_tree_t *Path_BuildNodeBsp_r(unsigned __int16 *nodes, int numNodes)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Path_DisconnectChokeLinks
==============
*/
void Path_DisconnectChokeLinks(unsigned int nodeAIndex, unsigned int nodeBIndex, unsigned int nodeALink, unsigned __int16 *newLinkCounts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_DisconnectNodeForChokePoint
==============
*/
bool Path_DisconnectNodeForChokePoint(unsigned int nodeAIndex, unsigned int chokeIndex, unsigned __int16 *newLinkCounts)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_DisconnectNodesOnOppositeSideOfChokeNode
==============
*/
pathlink_s *Path_DisconnectNodesOnOppositeSideOfChokeNode(pathlink_s *pSourceLinks, unsigned int *totalLinkCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Path_LinkIsDynamic
==============
*/
bool Path_LinkIsDynamic(unsigned __int16 from, unsigned __int16 to)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_TwoWayLink
==============
*/
bool Path_TwoWayLink(unsigned __int16 from, unsigned __int16 to)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_FindLinkToNode_r
==============
*/
char Path_FindLinkToNode_r(const pathnode_t *searchNode, unsigned __int16 searchIndex, unsigned __int16 fromIndex, unsigned __int16 goalIndex, int *currentDepth, const int maxDepth)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_RemoveRedundantLink
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Path_DisconnectLink
==============
*/
void Path_DisconnectLink(pathnode_t *nodeA, pathnode_t *nodeB, bool removeRedundantLinks)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_OptimizeGraph
==============
*/
pathlink_s *Path_OptimizeGraph(char *a1, pathlink_s *pSourceLinks, unsigned int *totalLinkCount, bool removeRedundantLinks)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Path_IsSafeToMoveBetweenNodes
==============
*/
bool Path_IsSafeToMoveBetweenNodes(const pathnode_t *nodeFrom, const pathnode_t *nodeTo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_CornerSafeLinkCheck
==============
*/
bool Path_CornerSafeLinkCheck(pathnode_t *nodeFrom, pathnode_t *nodeTo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_MarkSafeShuffleLinks
==============
*/
void Path_MarkSafeShuffleLinks()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
isDeflectionOK
==============
*/
bool isDeflectionOK(float *a1, float *a2, float movedir, const vec2_t *a4)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_NodeCanBeDoubleWide
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Path_NodeCanBeQuadrotorNode
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
GetNodeAttackPoint
==============
*/
void GetNodeAttackPoint(const pathnode_t *node, vec3_t *attackPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_GetExpandedNodeNums_r
==============
*/
int Path_GetExpandedNodeNums_r(int iNodeStart, float fDistLeft, int *iNodeNums, int iNodeCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_CheckExpandedNodeVis
==============
*/
int Path_CheckExpandedNodeVis(int (*iNodeNums)[8192], int *iNodeCount, unsigned __int8 *visbuf)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_BuildNodeVis
==============
*/
void Path_BuildNodeVis(unsigned __int8 *visbuf, int iVisCacheSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_SmoothPathIsFloating
==============
*/
bool Path_SmoothPathIsFloating(const vec3_t *vStart, const vec3_t *vEnd)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_BuildSmoothCache
==============
*/
void Path_BuildSmoothCache(unsigned __int8 *smoothBuf, int smoothSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_SavePaths
==============
*/
void Path_SavePaths()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_CornerNodeCheck
==============
*/
bool Path_CornerNodeCheck(pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_MarkValidCoverNodePeekOuts
==============
*/
void Path_MarkValidCoverNodePeekOuts()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetNextAvailableTempLinks
==============
*/
pathlink_s *G_GetNextAvailableTempLinks()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Path_MakePathDataPermanent
==============
*/
void Path_MakePathDataPermanent(pathlink_s *pSourceLinks, unsigned int totalLinkCount, unsigned __int8 *pVis, int visBytes, unsigned __int8 *pSmooth, int smoothBytes)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_LoadPathsInternal
==============
*/
int Path_LoadPathsInternal()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_LoadPaths
==============
*/
void Path_LoadPaths()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_CanLinkQuadrotorNodes
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Path_CanLinkNodes
==============
*/
int Path_CanLinkNodes(pathnode_t *pNodeFrom, int *pbNegotiationLink)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_AttemptLink1
==============
*/
bool Path_AttemptLink1(pathnode_t *pNodeFrom, pathnode_t *pNodeTo, pathlink_s *pLinks, int iMaxLinks)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_AttemptLink
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Path_ConnectPaths
==============
*/
void Path_ConnectPaths()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_ConnectPathsForSingleNode
==============
*/
void Path_ConnectPathsForSingleNode(pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

