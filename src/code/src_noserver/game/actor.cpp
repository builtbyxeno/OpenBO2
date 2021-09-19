#include "types.h"
#include "functions.h"

/*
==============
TRACK_actor
==============
*/
void TRACK_actor()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VisCache_Update
==============
*/
void VisCache_Update(vis_cache_t *pCache, bool bVisible)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SentientInfo_Clear
==============
*/
void SentientInfo_Clear(sentient_info_t *pInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_droptofloor
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Actor_DropPointToFloor
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
G_InitActors
==============
*/
void G_InitActors()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetActorIndex
==============
*/
int G_GetActorIndex(actor_t *actor)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_GetActorAnimTree
==============
*/
XAnimTree_s *G_GetActorAnimTree(actor_t *actor)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Actor_FinishSpawning
==============
*/
void Actor_FinishSpawning(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_InitAnimScript
==============
*/
void Actor_InitAnimScript(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_FirstActor
==============
*/
actor_t *Actor_FirstActor(const int iTeamFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Actor_NextActor
==============
*/
actor_t *Actor_NextActor(actor_t *pPrevActor, const int iTeamFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Actor_NumFreeActors
==============
*/
int Actor_NumFreeActors()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_NumActors
==============
*/
int Actor_NumActors(const int iTeamFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_ClearArrivalPos
==============
*/
void Actor_ClearArrivalPos(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_UpdateActorInfo
==============
*/
int Actor_UpdateActorInfo(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_UpdateMoverRecord
==============
*/
void SV_UpdateMoverRecord(gentity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Spawner_Think
==============
*/
void Spawner_Think(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_Touch
==============
*/
void Actor_Touch(gentity_t *self, gentity_t *other)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_InScriptedState
==============
*/
bool Actor_InScriptedState(const actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_Die
==============
*/
void Actor_Die(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_IsDying
==============
*/
bool Actor_IsDying(const actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
usingCodeGoal
==============
*/
BOOL usingCodeGoal(actor_t *actor)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_DebugDrawNodesInVolume
==============
*/
void Actor_DebugDrawNodesInVolume(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_GetTargetEntity
==============
*/
gentity_t *Actor_GetTargetEntity(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Actor_GetTargetSentient
==============
*/
sentient_t *Actor_GetTargetSentient(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Actor_AllSecondaryTargetsForward
==============
*/
char Actor_AllSecondaryTargetsForward(const actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_GetTargetPosition
==============
*/
void Actor_GetTargetPosition(actor_t *self, vec3_t *position)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_GetTargetLookPosition
==============
*/
void Actor_GetTargetLookPosition(actor_t *self, vec3_t *position)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_GetScriptTargetEntity
==============
*/
gentity_t *Actor_GetScriptTargetEntity(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Actor_IsDodgeEntity
==============
*/
BOOL Actor_IsDodgeEntity(actor_t *self, int entnum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_Physics_GetLeftOrRightDodge
==============
*/
int Actor_Physics_GetLeftOrRightDodge(actor_t *self, bool dodgeRight, float length)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_PhysicsRestoreInputs
==============
*/
void Actor_PhysicsRestoreInputs(actor_t *self, PhysicsInputs *inputs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_CalcultatePlayerPushDelta
==============
*/
float Actor_CalcultatePlayerPushDelta(const actor_t *self, const gentity_t *pusher, vec2_t *pushDir)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_ShouldMoveAwayFromCloseEnt
==============
*/
bool Actor_ShouldMoveAwayFromCloseEnt(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
actor_controller
==============
*/
void actor_controller(const gentity_t *self, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_PointNear
==============
*/
bool Actor_PointNear(const vec3_t *vPoint, const vec3_t *vGoalPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_PointNearNode
==============
*/
bool Actor_PointNearNode(const vec3_t *vPoint, const pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_PointNearClaimNode
==============
*/
bool Actor_PointNearClaimNode(const actor_t *self, const vec3_t *vPoint)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_PointAtGoal
==============
*/
bool Actor_PointAtGoal(const vec3_t *vPoint, const actor_goal_s *goal)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_PointNearPoint
==============
*/
bool Actor_PointNearPoint(const vec3_t *vPoint, const vec3_t *vGoalPos, float buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_PointNearPointSqDist
==============
*/
bool Actor_PointNearPointSqDist(const vec3_t *vPoint, const vec3_t *vGoalPos, float bufferSq)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_PointAt
==============
*/
bool Actor_PointAt(const vec3_t *vPoint, const vec3_t *vGoalPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_ExitingClaimNode
==============
*/
bool Actor_ExitingClaimNode(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_HandleInvalidPath
==============
*/
void Actor_HandleInvalidPath(actor_t *self, vec3_t goal)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_GetNodeOffset
==============
*/
void Actor_GetNodeOffset(actor_t *self, const pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_ShouldHoldGroundAgainstEnemy
==============
*/
bool Actor_ShouldHoldGroundAgainstEnemy(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_EnemyInPathFightDist
==============
*/
bool Actor_EnemyInPathFightDist(actor_t *self, sentient_t *enemy)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_IsKnownEnemyInRegion
==============
*/
gentity_t *Actor_IsKnownEnemyInRegion(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Actor_HasPath
==============
*/
bool Actor_HasPath(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_HadPath
==============
*/
BOOL Actor_HadPath(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_InitPath
==============
*/
void Actor_InitPath(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_ClearPath
==============
*/
void Actor_ClearPath(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_GetAnimDeltas
==============
*/
void Actor_GetAnimDeltas(actor_t *self, vec2_t *rotation, vec3_t *translation)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_IsMovingToMeleeAttack
==============
*/
BOOL Actor_IsMovingToMeleeAttack(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_SkipPathEndActions
==============
*/
bool Actor_SkipPathEndActions(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_PathEndActions
==============
*/
void Actor_PathEndActions(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_SimulateChildrenPhysics
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Actor_AtClaimNode
==============
*/
BOOL Actor_AtClaimNode(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_AtClaimNodeAndAngle
==============
*/
BOOL Actor_AtClaimNodeAndAngle(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_NearClaimNode
==============
*/
BOOL Actor_NearClaimNode(actor_t *self, float dist)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_IsValidClaimNode
==============
*/
int Actor_IsValidClaimNode(actor_t *self, const pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_PredictAnim
==============
*/
void Actor_PredictAnim(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_UseChokePoints
==============
*/
BOOL Actor_UseChokePoints(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_CheckCollisions
==============
*/
void Actor_CheckCollisions(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_ClearPileUp
==============
*/
void Actor_ClearPileUp(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_ClipPathToGoal
==============
*/
void Actor_ClipPathToGoal(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_BeginTrimPath
==============
*/
void Actor_BeginTrimPath(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_TrimPathToAttack
==============
*/
int Actor_TrimPathToAttack(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_MayReacquireMove
==============
*/
BOOL Actor_MayReacquireMove(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_ClearMoveHistory
==============
*/
void Actor_ClearMoveHistory(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_GetMoveHistoryAverage
==============
*/
void Actor_GetMoveHistoryAverage(actor_t *self, vec3_t *vDir)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_UpdateMoveHistory
==============
*/
void Actor_UpdateMoveHistory(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_UpdateLeanAmount
==============
*/
void Path_UpdateLeanAmount(actor_t *self, vec2_t *vWishDir)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_UpdateMomentum
==============
*/
float Path_UpdateMomentum(actor_t *self, vec2_t *vWishDir, float fMoveDist)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_UpdateMovementDelta
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Actor_AddStationaryMoveHistory
==============
*/
void Actor_AddStationaryMoveHistory(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_IsMoving
==============
*/
BOOL Actor_IsMoving(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_SetFlashed
==============
*/
void Actor_SetFlashed(actor_t *self, int flashed, float strength)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_SetGoalRadius
==============
*/
void Actor_SetGoalRadius(actor_goal_s *goal, float radius)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_SetGoalHeight
==============
*/
void Actor_SetGoalHeight(actor_goal_s *goal, float height)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_IsInsideArc
==============
*/
bool Actor_IsInsideArc(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SentientInfo_Copy
==============
*/
void SentientInfo_Copy(actor_t *pTo, const actor_t *pFrom, int index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_InitActorState
==============
*/
void Actor_InitActorState(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_Alloc
==============
*/
actor_t *Actor_Alloc()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Actor_Free
==============
*/
void Actor_Free(actor_t *actor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_FreeExpendable
==============
*/
void Actor_FreeExpendable()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_FinishSpawningAll
==============
*/
void Actor_FinishSpawningAll(bool bRestart)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_DissociateSentient
==============
*/
void Actor_DissociateSentient(actor_t *self, sentient_t *other)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_NodeClaimRevoked
==============
*/
void Actor_NodeClaimRevoked(actor_t *self, int invalidTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_CheckClearNodeClaimCloseEnt
==============
*/
void Actor_CheckClearNodeClaimCloseEnt(actor_t *selfa)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_KeepClaimedNode
==============
*/
char Actor_KeepClaimedNode(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_ClearKeepClaimedNode
==============
*/
void Actor_ClearKeepClaimedNode(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_CheckNodeClaim
==============
*/
void Actor_CheckNodeClaim(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_PreThink
==============
*/
void Actor_PreThink(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_UpdatePlayerPush
==============
*/
void Actor_UpdatePlayerPush(actor_t *self, gentity_t *player)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_UpdateCloseEnt
==============
*/
void Actor_UpdateCloseEnt(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_CallThink
==============
*/
actor_think_result_t Actor_CallThink(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	actor_think_result_t tmp;
	return tmp;
}

/*
==============
Actor_UpdatePathNodes
==============
*/
void Actor_UpdatePathNodes(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_Pain
==============
*/
void Actor_Pain(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_EntInfo
==============
*/
void Actor_EntInfo(gentity_t *self, vec3_t *source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_MoveAwayNoWorse
==============
*/
int Actor_MoveAwayNoWorse(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_PhysicsCheckMoveAwayNoWorse
==============
*/
int Actor_PhysicsCheckMoveAwayNoWorse(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_PhysicsMoveAway
==============
*/
int Actor_PhysicsMoveAway(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_IsAtScriptGoal
==============
*/
bool Actor_IsAtScriptGoal(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_ShouldKeepClaimedNode
==============
*/
bool Actor_ShouldKeepClaimedNode(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_IsNearClaimedNode
==============
*/
bool Actor_IsNearClaimedNode(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_ResetLookahead
==============
*/
void Actor_ResetLookahead(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_FindClaimedNode
==============
*/
pathnode_t *Actor_FindClaimedNode(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Actor_IsAlongPath
==============
*/
bool Actor_IsAlongPath(actor_t *self, vec2_t *origin, vec2_t *pathPoint)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_CheckStopOnGoalChange
==============
*/
bool Actor_CheckStopOnGoalChange(actor_t *self, checkStopParams_t *params)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_IsFixedNodeUseable
==============
*/
bool Actor_IsFixedNodeUseable(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_FindPath
==============
*/
bool Actor_FindPath(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_RecalcPath
==============
*/
void Actor_RecalcPath(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_FindPathToNode
==============
*/
bool Actor_FindPathToNode(actor_t *self, pathnode_t *pGoalNode, int bSuppressable, int bIgnoreBadplaces)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_FindPathToSentient
==============
*/
bool Actor_FindPathToSentient(actor_t *self, sentient_t *pGoalEnt, int bSuppressable)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_FindPathInGoalWithLOS
==============
*/
void Actor_FindPathInGoalWithLOS(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_BadPlacesChanged
==============
*/
void Actor_BadPlacesChanged()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_UpdateAnglesAndDelta
==============
*/
void Actor_UpdateAnglesAndDelta(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_UpdatePileUp
==============
*/
void Actor_UpdatePileUp(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_UpdateGoalPos
==============
*/
void Actor_UpdateGoalPos(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_ClearUseEnemyGoal
==============
*/
void Actor_ClearUseEnemyGoal(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_CheckGoalNotify
==============
*/
bool Actor_CheckGoalNotify(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_CheckNotify
==============
*/
void Actor_CheckNotify(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_Think
==============
*/
void Actor_Think(gentity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_PhysicsAndDodge
==============
*/
int Actor_PhysicsAndDodge(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_DoMove
==============
*/
void Actor_DoMove(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_IsAtGoal
==============
*/
bool Actor_IsAtGoal(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_FindPathToGoalDirectInternal
==============
*/
bool Actor_FindPathToGoalDirectInternal(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_FindPathToGoalDirect
==============
*/
void Actor_FindPathToGoalDirect(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_FindPathToClaimNode
==============
*/
bool Actor_FindPathToClaimNode(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_CheckStop
==============
*/
bool Actor_CheckStop(actor_t *self, int canUseEnemyGoal, pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_TryPathToArrivalPos
==============
*/
void Actor_TryPathToArrivalPos(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_FindPathToFixedNode
==============
*/
void Actor_FindPathToFixedNode(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_SetupFindPathToGoal
==============
*/
bool Actor_SetupFindPathToGoal(actor_t *self, int *canUseEnemyGoal)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_TryPathToNode
==============
*/
bool Actor_TryPathToNode(actor_t *self, pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_FindPathToGoal
==============
*/
void Actor_FindPathToGoal(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_FixedLinkPhysicsFallback
==============
*/
void Actor_FixedLinkPhysicsFallback(actor_t *self, vec3_t *targetOrigin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_UpdateOriginAndAngles
==============
*/
void Actor_UpdateOriginAndAngles(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_PredictOriginAndAngles
==============
*/
void Actor_PredictOriginAndAngles(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_PostThink
==============
*/
void Actor_PostThink(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_InitMove
==============
*/
void Actor_InitMove(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SP_actor
==============
*/
int SP_actor(gentity_t *ent, SpawnVar *spawnVar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

