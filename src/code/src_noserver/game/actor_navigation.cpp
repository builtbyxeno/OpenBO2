#include "types.h"
#include "functions.h"

/*
==============
Path_GetPathDir
==============
*/
float Path_GetPathDir(vec2_t *delta, const vec2_t *vFrom, const vec2_t *vTo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_IncrementNodeUserCount
==============
*/
void Path_IncrementNodeUserCount(path_t *pPath)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_DecrementNodeUserCount
==============
*/
void Path_DecrementNodeUserCount(path_t *pPath)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_Backup
==============
*/
void Path_Backup(const path_t *path)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_GetDistToPathSegment
==============
*/
float Path_GetDistToPathSegment(const vec2_t *vStartPos, const pathpoint_t *pt)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_LookaheadNeedsReset
==============
*/
BOOL Path_LookaheadNeedsReset(path_t *pPath)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_AddTrimmedAmount
==============
*/
void Path_AddTrimmedAmount(path_t *pPath, const vec3_t *vStartPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_SubtractTrimmedAmount
==============
*/
void Path_SubtractTrimmedAmount(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_SetLookaheadToStart
==============
*/
void Path_SetLookaheadToStart(path_t *pPath, const vec3_t *vStartPos, int bTrimAmount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_NearDangerousNode
==============
*/
bool Path_NearDangerousNode(const pathnode_t *pNode, const team_t team)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_SmoothPath
==============
*/
void Path_SmoothPath(pathnode_t *pNodeFrom, pathnode_t *pNodeTo, team_t team)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_NodeOccupiedByOther
==============
*/
bool Path_NodeOccupiedByOther(int searchEntNum, const pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_CheckFromAndToNodesNoHeightCheck
==============
*/
BOOL Path_CheckFromAndToNodesNoHeightCheck(PathFindInput *pathFindInput)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_CheckFromAndToNodes
==============
*/
int Path_CheckFromAndToNodes(PathFindInput *pathFindInput, PathBlockPlanes *blockPlanes)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CustomSearchInfo_FindPath::CustomSearchInfo_FindPath
==============
*/
/*void __thiscall CustomSearchInfo_FindPath::CustomSearchInfo_FindPath(
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Path_InitFindInput
==============
*/
void Path_InitFindInput(PathFindInput *pathFindInput, actor_t *actor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_GetPathRandomness
==============
*/
int Path_GetPathRandomness(PathFindInput *pathFindInput)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_TrimLastNodes
==============
*/
void Path_TrimLastNodes(path_t *pPath, const int iNodeCount, bool bMaintainGoalPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_ClipToGoal
==============
*/
int Path_ClipToGoal(path_t *pPath, const actor_goal_s *goal)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_BeginTrim
==============
*/
void Path_BeginTrim(path_t *pPath, path_trim_t *pTrim)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_TrimToSeePoint
==============
*/
int Path_TrimToSeePoint(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_Begin
==============
*/
void Path_Begin(path_t *pPath)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_Clear
==============
*/
void Path_Clear(path_t *pPath)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_Exists
==============
*/
BOOL Path_Exists(const path_t *pPath)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_CompleteLookahead
==============
*/
int Path_CompleteLookahead(const path_t *pPath)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_AttemptedCompleteLookahead
==============
*/
unsigned int Path_AttemptedCompleteLookahead(const path_t *pPath)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_UsesObstacleNegotiation
==============
*/
BOOL Path_UsesObstacleNegotiation(const path_t *pPath)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_HasNegotiationNode
==============
*/
bool Path_HasNegotiationNode(const path_t *path)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_AllowsObstacleNegotiation
==============
*/
unsigned int Path_AllowsObstacleNegotiation(const path_t *pPath)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_GetObstacleNegotiationScript
==============
*/
void Path_GetObstacleNegotiationScript(const path_t *pPath, scr_animscript_t *animscript)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_CurrentLinkDisconnected
==============
*/
int Path_CurrentLinkDisconnected(const path_t *pPath)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_NeedsReevaluation
==============
*/
bool Path_NeedsReevaluation(const path_t *pPath)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_GoingDown
==============
*/
BOOL Path_GoingDown(const path_t *pPath)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_DistanceGreaterThan
==============
*/
int Path_DistanceGreaterThan(path_t *pPath, float fDist)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_ReduceLookaheadAmount
==============
*/
void Path_ReduceLookaheadAmount(path_t *pPath, float maxLookaheadAmountIfReduce)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_FailedLookahead
==============
*/
BOOL Path_FailedLookahead(path_t *pPath)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_IncreaseLookaheadAmount
==============
*/
void Path_IncreaseLookaheadAmount(path_t *pPath)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
skip_avoidance_ents
==============
*/
BOOL skip_avoidance_ents(int entnum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_IsTrimmed
==============
*/
BOOL Path_IsTrimmed(path_t *pPath)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_RemoveCompletedPathPoints
==============
*/
void Path_RemoveCompletedPathPoints(path_t *pPath, int pathPointIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_TrimCompletedPath
==============
*/
void Path_TrimCompletedPath(path_t *pPath, const vec3_t *vStartPos, const vec3_t *vStartPosa)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_BackTrack
==============
*/
void Path_BackTrack(path_t *pPath, int newPathLength, float lookaheadIncreaseAmount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_BacktrackCompletedPath
==============
*/
void Path_BacktrackCompletedPath(path_t *pPath, const vec3_t *vStartPos, const vec3_t *vStartPosa)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PathCalcLookahead_CheckMinLookaheadNodes
==============
*/
void PathCalcLookahead_CheckMinLookaheadNodes(path_t *pPath, const pathpoint_t *pt, int currentNode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_GetForwardStartPos
==============
*/
int Path_GetForwardStartPos(path_t *pPath, const vec2_t *vStartPos, vec2_t *vForwardStartPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_DebugDraw
==============
*/
void Path_DebugDraw(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_WithinApproxDist
==============
*/
bool Path_WithinApproxDist(path_t *pPath, float checkDist)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_AllowedStancesForPath
==============
*/
ai_stance_e Path_AllowedStancesForPath(path_t *pPath)
{
	UNIMPLEMENTED(__FUNCTION__);
	ai_stance_e tmp;
	return tmp;
}

/*
==============
Path_CheckNodeCountForDodge
==============
*/
void Path_CheckNodeCountForDodge(path_t *pPath, int numNeeded, pathpoint_t **pt, int *startIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_DodgeDrawRaisedLine
==============
*/
void Path_DodgeDrawRaisedLine(const vec3_t *start, const vec3_t *end, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_MayFaceEnemy
==============
*/
BOOL Path_MayFaceEnemy(path_t *pPath, vec3_t *vEnemyDir, vec3_t *vOrg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_GetStepHeightForRadius
==============
*/
double Path_GetStepHeightForRadius(const float radius)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_TrimToBadPlaceLink
==============
*/
void Path_TrimToBadPlaceLink(path_t *pPath, team_t eTeam)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BotSearchInfo::GetNodeCost
==============
*/
/*double __thiscall BotSearchInfo::GetNodeCost(BotSearchInfo *this, const pathnode_t *pSuccessor, const vec3_t *vGoalPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
Path_Restore
==============
*/
void Path_Restore(path_t *path)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_FindPath
==============
*/
int Path_FindPath(PathFindInput *pathFindInput)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_PredictionTrace
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Path_PredictionTraceCheckForEntities
==============
*/
int Path_PredictionTraceCheckForEntities(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_LookaheadPredictionTrace
==============
*/
int Path_LookaheadPredictionTrace(path_t *pPath, const vec3_t *vStartPos, const vec3_t *vEndPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_UpdateLookaheadAmount
==============
*/
void Path_UpdateLookaheadAmount(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_CalcLookahead_Completed
==============
*/
void Path_CalcLookahead_Completed(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_CalcLookahead
==============
*/
void Path_CalcLookahead(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_UpdateLookahead
==============
*/
void Path_UpdateLookahead(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_TransferLookahead
==============
*/
void Path_TransferLookahead(path_t *pPath, const vec3_t *vStartPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_GeneratePath
==============
*/
BOOL Path_GeneratePath(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_UpdateLookahead_NonCodeMove
==============
*/
void Path_UpdateLookahead_NonCodeMove(path_t *pPath, const vec3_t *vPrevPos, const vec3_t *vStartPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_AttemptDodge
==============
*/
char Path_AttemptDodge(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_FindCloseNode
==============
*/
pathnode_t *Path_FindCloseNode(team_t eTeam, pathnode_t *pNodeFrom, const vec3_t *vGoalPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Path_FindPathWithWidth
==============
*/
int Path_FindPathWithWidth(PathFindInput *pathFindInput, float width, vec2_t *perp)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_FindPathNotCrossPlanes
==============
*/
int Path_FindPathNotCrossPlanes(PathFindInput *pathFindInput, PathBlockPlanes *blockPlanes)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_FindPathInCylinderWithLOS
==============
*/
int Path_FindPathInCylinderWithLOS(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_FindFacingNode
==============
*/
pathnode_t *Path_FindFacingNode(pathnode_t *node, sentient_t *pOther, sentient_info_t *pInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Path_FindPathGetCloseAsPossible
==============
*/
int Path_FindPathGetCloseAsPossible(PathFindInput *pathFindInput)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_FindPath
==============
*/
int Bot_FindPath(PathFindInput *pathFindInput)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

