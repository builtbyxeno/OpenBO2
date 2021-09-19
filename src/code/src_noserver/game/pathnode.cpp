#include "types.h"
#include "functions.h"

/*
==============
Path_GetPillarStandOverOffset
==============
*/
vec3_t *Path_GetPillarStandOverOffset()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
TRACK_pathnode
==============
*/
void TRACK_pathnode()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Node_DangerousCount
==============
*/
int Node_DangerousCount(const pathnode_t *pNode, const team_t team)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Node_IsDangerous
==============
*/
BOOL Node_IsDangerous(const pathnode_t *pNode, const team_t team)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Node_IsFriendly
==============
*/
BOOL Node_IsFriendly(const pathnode_t *pNode, const team_t team)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Node_MarkDangerous
==============
*/
void Node_MarkDangerous(pathnode_t *pNode, const team_t team, const int dangerous)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_FindPath
==============
*/
void Scr_FindPath()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_GetType
==============
*/
void Path_GetType(pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_SetPathnodeField
==============
*/
void Scr_SetPathnodeField(int entnum, int offset)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetPathnodeField
==============
*/
void Scr_GetPathnodeField(int entnum, int offset)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_CallFunctionForNodes
==============
*/
void Path_CallFunctionForNodes(scriptInstance_t inst, void (*function)(scriptInstance_t, pathnode_t *))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PathNode_UpdateStringField
==============
*/
void PathNode_UpdateStringField(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PathNode_UpdateFloatField
==============
*/
void PathNode_UpdateFloatField(const char *destKey, float *destFloat, const char *key, const char *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
parented_pathnode_list_delete
==============
*/
void parented_pathnode_list_delete(gentity_t *gent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_UpdateTrackExtraNodes
==============
*/
void G_UpdateTrackExtraNodes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GScr_AddFieldsForPathnode
==============
*/
void GScr_AddFieldsForPathnode()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ScrCmd_SetDangerousNode
==============
*/
void ScrCmd_SetDangerousNode(scr_entref_t entref)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ScrCmd_IsDangerousNode
==============
*/
void ScrCmd_IsDangerousNode(scr_entref_t entref)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetPathnode
==============
*/
pathnode_t *Scr_GetPathnode(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_FreePathnodesScriptInfo
==============
*/
void G_FreePathnodesScriptInfo()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_CompareNodesIncreasing
==============
*/
bool Path_CompareNodesIncreasing(const pathsort_t *ps1, const pathsort_t *ps2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_ConvertNodeToIndex
==============
*/
unsigned int Path_ConvertNodeToIndex(const pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_ConvertIndexToNode
==============
*/
pathnode_t *Path_ConvertIndexToNode(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Path_Init
==============
*/
void Path_Init(int restart)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NodeSmoothCacheEntry
==============
*/
int NodeSmoothCacheEntry(int i, int j)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_NodesSmooth
==============
*/
BOOL Path_NodesSmooth(const pathnode_t *node0, const pathnode_t *node1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_NodesInCylinder_process
==============
*/
void Path_NodesInCylinder_process(pathnode_t *pnode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_IsDynamicBlockingEntity
==============
*/
int Path_IsDynamicBlockingEntity(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_IsBadPlaceLink
==============
*/
int Path_IsBadPlaceLink(int nodeNumFrom, int nodeNumTo, team_t eTeam)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_InitLinkCounts
==============
*/
void Path_InitLinkCounts()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_InitLinkInfoArray
==============
*/
int Path_InitLinkInfoArray()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_InitNodesDynamic
==============
*/
GameWorldMp *Path_InitNodesDynamic()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Path_PreSpawnInitPaths
==============
*/
void Path_PreSpawnInitPaths()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_CheckSpawnExitNodesConnectivity
==============
*/
void Path_CheckSpawnExitNodesConnectivity()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_DrawDebugNoLinks
==============
*/
void Path_DrawDebugNoLinks(const pathnode_t *node, const vec4_t *color, int duration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_DrawDebugLink
==============
*/
void Path_DrawDebugLink(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_GetCornerNodeCheckOffset
==============
*/
void Path_GetCornerNodeCheckOffset(const pathnode_t *node, vec3_t *offset)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_GetPeekOutLine
==============
*/
void Path_GetPeekOutLine(const pathnode_t *node, const vec3_t *offset, vec3_t *start, vec3_t *end)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_DrawDebugPeekOuts
==============
*/
void Path_DrawDebugPeekOuts(const pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_DrawDebugFindPath
==============
*/
void Path_DrawDebugFindPath(const vec3_t *vOrigin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_NodeActorAngle
==============
*/
double Path_NodeActorAngle(const pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_NodesVisible
==============
*/
BOOL Path_NodesVisible(const pathnode_t *node0, const pathnode_t *node1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_ExpandedNodeVisible
==============
*/
BOOL Path_ExpandedNodeVisible(const pathnode_t *node0, const pathnode_t *node1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_NodeSafeFrom
==============
*/
BOOL Path_NodeSafeFrom(const pathnode_t *node0, const pathnode_t *node1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_FirstNode
==============
*/
pathnode_t *Path_FirstNode(int typeFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Path_IsDynamicallySpawnedNode
==============
*/
bool Path_IsDynamicallySpawnedNode(pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_NextNode
==============
*/
pathnode_t *Path_NextNode(pathnode_t *prevNode, int typeFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Path_IsOnlyOwner
==============
*/
int Path_IsOnlyOwner(const pathnode_t *node, const sentient_t *owner)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_GetNodeOwner
==============
*/
sentient_t *Path_GetNodeOwner(const pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Path_CanStealPriorityNode
==============
*/
int Path_CanStealPriorityNode(const pathnode_t *node, sentient_t *claimer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_CanStealNode
==============
*/
bool Path_CanStealNode(const pathnode_t *node, sentient_t *claimer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_ClaimNodeInternal
==============
*/
void Path_ClaimNodeInternal(pathnode_t *node, sentient_t *claimer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_MarkNodeOverlap
==============
*/
void Path_MarkNodeOverlap(pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_ClaimNode
==============
*/
void Path_ClaimNode(pathnode_t *node, sentient_t *claimer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_RevokeClaim
==============
*/
void Path_RevokeClaim(pathnode_t *node, sentient_t *pNewClaimer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_RelinquishNode
==============
*/
void Path_RelinquishNode(sentient_t *claimer, int timeUntilRelinquished)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_IsReallyDangerousNode
==============
*/
BOOL Path_IsReallyDangerousNode(const pathnode_t *node, team_t eTeam)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_IsNodeNegotiationHint
==============
*/
unsigned int Path_IsNodeNegotiationHint(const pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_AllowedStancesForNode
==============
*/
int Path_AllowedStancesForNode(pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_LoadNode
==============
*/
pathnode_t *Path_LoadNode(unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Path_ValidateNode
==============
*/
void Path_ValidateNode(pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_ValidateAllNodes
==============
*/
void Path_ValidateAllNodes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_CheckLinkLeaks
==============
*/
void Path_CheckLinkLeaks()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_CheckUserCountLeaks
==============
*/
void Path_CheckUserCountLeaks()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_DisconnectPath
==============
*/
void Path_DisconnectPath(pathnode_t *node, pathlink_s *link)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_ConnectPath
==============
*/
void Path_ConnectPath(pathnode_t *node, pathlink_s *link)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_UpdateBadPlaceCountForLink
==============
*/
void Path_UpdateBadPlaceCountForLink(pathlink_s *link, int teamflags, int delta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_UpdateHasBadPlaceLink
==============
*/
void Path_UpdateHasBadPlaceLink(pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_UpdateArcBadPlaceCount
==============
*/
/*void Path_UpdateArcBadPlaceCount(float a1@<esi>, badplace_arc_t *arc, int teamflags, int delta)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Path_CheckForInwardLinks
==============
*/
void Path_CheckForInwardLinks(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_IsNodeInArc
==============
*/
int Path_IsNodeInArc(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ReadEntityDisconnectedLinks
==============
*/
void ReadEntityDisconnectedLinks(gentity_t *ent, MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IsNodeEnabled
==============
*/
BOOL IsNodeEnabled(const pathnode_t *pNode)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_DeleteRunTimePathnode
==============
*/
void G_DeleteRunTimePathnode(pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_FindPathNode
==============
*/
pathnode_t *G_FindPathNode(int guid)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_ClearSelectedPathNode
==============
*/
void G_ClearSelectedPathNode()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_SetNodePriority
==============
*/
void Scr_SetNodePriority()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_IsNodeOccupied
==============
*/
void Scr_IsNodeOccupied()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetNodeOwner
==============
*/
void Scr_GetNodeOwner()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_SetTurretNode
==============
*/
void Scr_SetTurretNode()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_UnsetTurretNode
==============
*/
void Scr_UnsetTurretNode()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
parented_pathnode_list_add
==============
*/
void parented_pathnode_list_add(pathnode_parent_t *node_parent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
parented_pathnode_list_update
==============
*/
void parented_pathnode_list_update(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
parented_pathnode_lists_reset_position
==============
*/
void parented_pathnode_lists_reset_position(generic_avl_map_node_t *gamn)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
pathnode_is_resized
==============
*/
bool pathnode_is_resized(pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
get_pathnode_parent
==============
*/
pathnode_parent_t *get_pathnode_parent(const pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
get_pathnode_parent_entity
==============
*/
int get_pathnode_parent_entity(const unsigned int pathnode_i)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Node_DoesLink
==============
*/
int Node_DoesLink(const pathnode_t *nodeA, const pathnode_t *nodeB)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_NodeValidLink
==============
*/
int G_NodeValidLink(const pathnode_t *pNode)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_MarkBadPathnodes
==============
*/
void G_MarkBadPathnodes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_AddPathnode
==============
*/
void Scr_AddPathnode(scriptInstance_t inst, pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetNode
==============
*/
void Scr_GetNode()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetNodeArray
==============
*/
void Scr_GetNodeArray()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetAllNodes
==============
*/
void Scr_GetAllNodes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetVisibleNode
==============
*/
void Scr_GetVisibleNode()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_NodesVisible
==============
*/
void Scr_NodesVisible()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetVisibleNodes
==============
*/
void Scr_GetVisibleNodes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_NodesCanPath
==============
*/
void Scr_NodesCanPath()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_CanClaimNode
==============
*/
void Scr_CanClaimNode()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_SetEnableNode
==============
*/
void Scr_SetEnableNode()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_DeletePathNode
==============
*/
void Scr_DeletePathNode()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_Shutdown
==============
*/
void Path_Shutdown()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_NodesInCylinder_r
==============
*/
void Path_NodesInCylinder_r(pathnode_tree_t *tree)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_MovingNodesInCylinder
==============
*/
void Path_MovingNodesInCylinder()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_NodesInCylinder
==============
*/
int Path_NodesInCylinder(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_NodesInRadius
==============
*/
int Path_NodesInRadius(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_InitPaths
==============
*/
void Path_InitPaths()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_DrawDebugNodeBox
==============
*/
void Path_DrawDebugNodeBox(const pathnode_t *node, float size, const vec4_t *color_, int depthTest)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_DrawDebugNodeBox
==============
*/
void Path_DrawDebugNodeBox(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_DrawDebugNode
==============
*/
void Path_DrawDebugNode(const vec3_t *cameraPos, const pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_DrawVisData
==============
*/
void Path_DrawVisData()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_RelinquishNodeNow
==============
*/
void Path_RelinquishNodeNow(sentient_t *claimer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_MarkNodeInvalid
==============
*/
void Path_MarkNodeInvalid(pathnode_t *node, team_t eTeam, int invalidTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_MarkAllConnectedNodesDangerous
==============
*/
void Path_MarkAllConnectedNodesDangerous(pathnode_t *node, team_t eTeam)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_ConnectPathsForEntity
==============
*/
void Path_ConnectPathsForEntity(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_DisconnectPathsForEntity
==============
*/
void Path_DisconnectPathsForEntity(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_UpdateBrushBadPlaceCount
==============
*/
void Path_UpdateBrushBadPlaceCount(gentity_t *brushEnt, int teamflags, int delta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SetPathnodeScriptVariable
==============
*/
void G_SetPathnodeScriptVariable(const char *key, const char *value, pathnode_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_ParsePathnodeScriptFields
==============
*/
void G_ParsePathnodeScriptFields(pathnode_t *node, SpawnVar *spawnVar)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
parented_pathnode_lists_construct
==============
*/
void parented_pathnode_lists_construct()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
destroy_pathnode_resized_links
==============
*/
void destroy_pathnode_resized_links(void *prl_)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
pathnode_resized_links_get
==============
*/
pathnode_resized_links_t *pathnode_resized_links_get(pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Path_AreNodesLinked
==============
*/
int Path_AreNodesLinked(pathnode_t *node_from, pathnode_t *node_to)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
pathnode_resized_links_add
==============
*/
void pathnode_resized_links_add(pathnode_t *node_from, pathnode_t *node_to, bool bWarnAboutDupeLinks)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
pathnode_resized_links_remove
==============
*/
void pathnode_resized_links_remove(pathnode_t *node_from, pathnode_t *node_to)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
destroy_pathnode_parent
==============
*/
void destroy_pathnode_parent(void *node_parent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
setup_pathnode_parent
==============
*/
void setup_pathnode_parent(pathnode_t *node, const int entnum, const vec3_t *origin_loc)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
level_init_pathnode_parernt_system
==============
*/
void level_init_pathnode_parernt_system(int restart)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
pathnode_resized_links_load
==============
*/
void pathnode_resized_links_load(MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
pathnode_parent_load
==============
*/
void pathnode_parent_load(MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
pathnode_load
==============
*/
void pathnode_load(MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
node_droptofloor
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
G_DropPathNodeToFloor
==============
*/
void G_DropPathNodeToFloor(unsigned int nodeIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_DropPathnodesToFloor
==============
*/
void G_DropPathnodesToFloor()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SpawnPathnodeDynamic
==============
*/
void G_SpawnPathnodeDynamic(SpawnVar *spawnVar, pathnode_t *spawnedNode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_DrawNode
==============
*/
void Scr_DrawNode()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_LinkNodes
==============
*/
void Scr_LinkNodes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_UnLinkNodes
==============
*/
void Scr_UnLinkNodes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_NodesAreLinked
==============
*/
void Scr_NodesAreLinked()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_DropNodeToFloor
==============
*/
/*void Scr_DropNodeToFloor(int a1@<ebp>)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Path_AutoDisconnectPaths
==============
*/
void Path_AutoDisconnectPaths()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_CanClaimNode
==============
*/
int Path_CanClaimNode(const pathnode_t *node, sentient_t *claimer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_ForceClaimNode
==============
*/
void Path_ForceClaimNode(pathnode_t *node, sentient_t *claimer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_ProcessPathnodeCommand
==============
*/
void G_ProcessPathnodeCommand(const RadiantCommand *command, SpawnVar *spawnVar)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_SpawnPathNode
==============
*/
void Scr_SpawnPathNode()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetNodesInRadius
==============
*/
void GetNodesInRadius(int sorted)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetNodesInRadius
==============
*/
void Scr_GetNodesInRadius()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetNodesInRadiusSorted
==============
*/
void Scr_GetNodesInRadiusSorted()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_NearestNodeNotCrossPlanes
==============
*/
pathnode_t *Path_NearestNodeNotCrossPlanes(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Path_UpdateLimitedDepthArcBadPlaceCount
==============
*/
void Path_UpdateLimitedDepthArcBadPlaceCount(badplace_arc_t *arc, int teamflags, int delta, int depth)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetNodeArraySorted
==============
*/
void Scr_GetNodeArraySorted()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetCoverNodeArray
==============
*/
void Scr_GetCoverNodeArray()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetAnyNodeArray
==============
*/
void Scr_GetAnyNodeArray()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_DrawDebugNearestNode
==============
*/
void Path_DrawDebugNearestNode(const vec3_t *vOrigin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_NearestNodeNoHeightCheck
==============
*/
pathnode_t *Path_NearestNodeNoHeightCheck(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Path_NearestNode
==============
*/
pathnode_t *Path_NearestNode(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_GetNearestNode
==============
*/
void Scr_GetNearestNode()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_InitializeSpawns
==============
*/
bool Path_InitializeSpawns(pathnode_t **spawns)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_FlagUnconnectedNode
==============
*/
void Path_FlagUnconnectedNode(pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_DrawDebugUnconnected
==============
*/
void Path_DrawDebugUnconnected(pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_DrawDebug
==============
*/
void Path_DrawDebug()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_Update
==============
*/
void Path_Update()
{
	UNIMPLEMENTED(__FUNCTION__);
}

