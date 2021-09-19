#include "types.h"
#include "functions.h"

/*
==============
VP_AddDebugLine
==============
*/
void VP_AddDebugLine(const vec3_t *start, const vec3_t *end, int forceDraw)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_DebugArrow
==============
*/
void VP_DebugArrow(const vec3_t *pos, const vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_SetScriptVariable
==============
*/
void VP_SetScriptVariable(const char *key, const char *value, vehicle_node_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_ParseFields
==============
*/
void VP_ParseFields(vehicle_node_t *node, const SpawnVar *spawnVar, const bool setScriptVariable)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_ClearNode
==============
*/
void VP_ClearNode(vehicle_node_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_InitNode
==============
*/
void VP_InitNode(vehicle_node_t *node, __int16 nodeIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_CopyNode
==============
*/
void VP_CopyNode(const vehicle_node_t *src, vehicle_node_t *dst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_GetNodeByIndex
==============
*/
vehicle_node_t *VP_GetNodeByIndex(__int16 index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
VP_GetNextNodeIndex
==============
*/
int VP_GetNextNodeIndex(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VP_GetNodeIndex
==============
*/
__int16 VP_GetNodeIndex(unsigned __int16 name, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	__int16 tmp;
	return tmp;
}

/*
==============
VP_CalcNodeSpeed
==============
*/
void VP_CalcNodeSpeed(__int16 nodeIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_CalcNodeTension
==============
*/
void VP_CalcNodeTension(__int16 nodeIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_CalcNodeLookAhead
==============
*/
void VP_CalcNodeLookAhead(__int16 nodeIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_CalcNodeRadius
==============
*/
void VP_CalcNodeRadius(__int16 nodeIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_CalcNodeAngles
==============
*/
void VP_CalcNodeAngles(__int16 nodeIdx, vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_GetSlide
==============
*/
float VP_GetSlide(const vehicle_pathpos_t *vpp)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VP_GetAngles
==============
*/
void VP_GetAngles(const vehicle_pathpos_t *vpp, vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_GetLookAheadXYZCustom
==============
*/
void VP_GetLookAheadXYZCustom(const vehicle_pathpos_t *vpp, vec3_t *lookXYZ)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_GetLookAheadXYZ
==============
*/
void VP_GetLookAheadXYZ(const vehicle_pathpos_t *vpp, vec3_t *lookXYZ)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_UpdatePathPosCustom
==============
*/
int VP_UpdatePathPosCustom(vehicle_pathpos_t *vpp)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VP_UpdatePathPos
==============
*/
int VP_UpdatePathPos(vehicle_pathpos_t *vpp, const vec3_t *dir)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VP_FindClosestPathNode
==============
*/
int VP_FindClosestPathNode(const vec3_t *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VP_GetFreeAIPath
==============
*/
path_t *VP_GetFreeAIPath(int entityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
VP_FreeAIPath
==============
*/
void VP_FreeAIPath(path_t *path)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_GetAIPath
==============
*/
path_t *VP_GetAIPath(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
VP_UpdateAIPath
==============
*/
void VP_UpdateAIPath(const vec3_t *origin, vehicle_pathpos_t *vpp)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_DrawAIPath
==============
*/
void VP_DrawAIPath(const vec3_t *origin, const vehicle_pathpos_t *vpp)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_GetFreeCustomPath
==============
*/
vehicle_custom_path_t *VP_GetFreeCustomPath()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
VP_FreeCustomPath
==============
*/
void VP_FreeCustomPath(vehicle_custom_path_t *path)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_GetCustomPath
==============
*/
vehicle_custom_path_t *VP_GetCustomPath(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
VP_DrawCustomPath
==============
*/
void VP_DrawCustomPath(vehicle_custom_path_t *customPath)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_LoadVehiclePaths
==============
*/
void G_LoadVehiclePaths(MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_LoadVehicleHeightMeshes
==============
*/
void G_LoadVehicleHeightMeshes(MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetCurrNode
==============
*/
vehicle_node_t *GetCurrNode(vehicle_pathpos_t *vpp)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
VP_CalcPos
==============
*/
void VP_CalcPos(vehicle_pathpos_t *vpp)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_Advance
==============
*/
void VP_Advance(vehicle_pathpos_t *vpp, float dt, int use_spline_speed, int drivePath)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_DrawPath
==============
*/
/*void VP_DrawPath(vec3_t *p_origin@<edi>, vehicle_pathpos_t *vpp)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
G_InitVehiclePaths
==============
*/
void G_InitVehiclePaths()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_FreeVehiclePaths
==============
*/
void G_FreeVehiclePaths()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_FreeVehiclePathsScriptInfo
==============
*/
void G_FreeVehiclePathsScriptInfo()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SetupSplinePaths
==============
*/
/*void G_SetupSplinePaths(float speed@<xmm0>, bool scriptConnect)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
G_ConnectVehiclePaths
==============
*/
void G_ConnectVehiclePaths()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SetupVehiclePaths
==============
*/
/*void G_SetupVehiclePaths(float a1@<xmm0>, bool scriptConnect)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
G_VehInitPathPos
==============
*/
void G_VehInitPathPos(vehicle_pathpos_t *vpp)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_VehFreePathPos
==============
*/
void G_VehFreePathPos(vehicle_pathpos_t *vpp)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_VehSetUpPathPos
==============
*/
void G_VehSetUpPathPos(vehicle_pathpos_t *vpp, __int16 nodeIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_VehUpdatePathPos
==============
*/
int G_VehUpdatePathPos(vehicle_pathpos_t *vpp)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_VehSetSwitchNode
==============
*/
void G_VehSetSwitchNode(vehicle_pathpos_t *vpp, __int16 srcNodeIdx, __int16 dstNodeIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TRACK_g_vehicle_path
==============
*/
void TRACK_g_vehicle_path()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SP_info_vehicle_node
==============
*/
void SP_info_vehicle_node(const SpawnVar *spawnVar, int rotated, int radiantLiveUpdate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_ClearSelectedVehicleNode
==============
*/
void G_ClearSelectedVehicleNode()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_FindVehicleNode
==============
*/
vehicle_node_t *G_FindVehicleNode(int guid)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GScr_GetVehicleNodeIndex
==============
*/
__int16 GScr_GetVehicleNodeIndex(unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	__int16 tmp;
	return tmp;
}

/*
==============
GScr_AddFieldsForVehicleNode
==============
*/
void GScr_AddFieldsForVehicleNode()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GScr_GetVehicleNodeField
==============
*/
void GScr_GetVehicleNodeField(int entnum, int offset)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GScr_GetVehicleNode
==============
*/
void GScr_GetVehicleNode()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GScr_GetVehicleNodeArray
==============
*/
void GScr_GetVehicleNodeArray()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GScr_GetAllVehicleNodes
==============
*/
void GScr_GetAllVehicleNodes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GScr_GetTimeFromVehicleNodeToNode
==============
*/
void GScr_GetTimeFromVehicleNodeToNode()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GScr_ReconnectVehicleNodes
==============
*/
/*void GScr_ReconnectVehicleNodes(float a1@<xmm0>)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GScr_SetVehicleNodeEnabled
==============
*/
void GScr_SetVehicleNodeEnabled()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SpawnHeliHeightLock
==============
*/
void G_SpawnHeliHeightLock(SpawnVar *spawnVar)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VP_FindAIPath
==============
*/
int VP_FindAIPath(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VP_FindCustomPath
==============
*/
int VP_FindCustomPath(const vec3_t *start, const vec3_t *end, vehicle_pathpos_t *vpp)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VP_TraversePath
==============
*/
double VP_TraversePath(const vehicle_pathpos_t *vpp, const bool draw)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VP_DrawRaceTrack
==============
*/
void VP_DrawRaceTrack(__int16 nodeIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_DrawVehiclePaths
==============
*/
/*void G_DrawVehiclePaths(vec3_t *a1@<edi>)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
G_ProcessVehicleNodeCommand
==============
*/
/*void G_ProcessVehicleNodeCommand(float a1@<xmm0>, const RadiantCommand *command, SpawnVar *spawnVar)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
GScr_CreateTrack
==============
*/
void GScr_CreateTrack()
{
	UNIMPLEMENTED(__FUNCTION__);
}

