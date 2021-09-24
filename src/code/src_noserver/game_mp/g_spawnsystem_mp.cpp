#include "types.h"

/*
==============
SpawnSystem_ArchiveClientPosData
==============
*/
void SpawnSystem_ArchiveClientPosData(ClientNum_t clientNum, SpawnClientData *sc)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_GetPlayerSpawnId
==============
*/
int SpawnSystem_GetPlayerSpawnId(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SpawnSystem_ArchiveInfluencer
==============
*/
void SpawnSystem_ArchiveInfluencer(SpawnInfluencer *influencer, int sortedIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_ArchiveInfluencersPrepData
==============
*/
void SpawnSystem_ArchiveInfluencersPrepData(gentity_t *ent, bool bManualSpawn)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_RegisterDvars
==============
*/
void SpawnSystem_RegisterDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_Init
==============
*/
void SpawnSystem_Init(bool restart)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_Demo_ClearClientBuffer
==============
*/
void SpawnSystem_Demo_ClearClientBuffer(int clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_Demo_SendClientBuffer
==============
*/
void SpawnSystem_Demo_SendClientBuffer(int clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_ClearPoints
==============
*/
void SpawnSystem_ClearPoints()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_GetEntity
==============
*/
gentity_t *SpawnSystem_GetEntity(const unsigned __int16 *targetname)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SpawnSystem_AddPoint
==============
*/
char SpawnSystem_AddPoint(int team, gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SpawnSystem_ClearPointsBaseWeight
==============
*/
void SpawnSystem_ClearPointsBaseWeight(int teammask)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_SetPointsBaseWeight
==============
*/
void SpawnSystem_SetPointsBaseWeight(float teammask, int a2, vec3_t *objective_position, float angle, float score)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_InsertSortedInfluencer
==============
*/
void SpawnSystem_InsertSortedInfluencer(SpawnInfluencer *influencer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_RemoveSortedInfluencer
==============
*/
void SpawnSystem_RemoveSortedInfluencer(SpawnInfluencer *influencer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_CalculateCylinderAxis
==============
*/
void SpawnSystem_CalculateCylinderAxis(SpawnInfluencer *influencer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_CalculateCylinderAxisMidpoint
==============
*/
void SpawnSystem_CalculateCylinderAxisMidpoint(SpawnInfluencer *influencer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_FindPreset
==============
*/
SpawnInfluencerPreset *SpawnSystem_FindPreset(eInfluencerType type, eInfluencerShape shape, float length, float radius, float score, eInfluencerScoreCurve score_curve, const char *description)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SpawnSystem_SetPresetData
==============
*/
SpawnInfluencerPreset *SpawnSystem_SetPresetData(int influencerIndex, eInfluencerType type, eInfluencerShape shape, float length, float radius, float score, eInfluencerScoreCurve score_curve, const char *description)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SpawnSystem_InitInfluencer
==============
*/
void SpawnSystem_InitInfluencer(SpawnInfluencer *influencer, eInfluencerType type, eInfluencerShape shape, const vec3_t *origin, const vec3_t *forward, const vec3_t *up, float radius, float axis_length, float score, eInfluencerScoreCurve score_curve, int teamMask, int entNum, int timeout, const char *description)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_AddSphereInfluencer
==============
*/
int SpawnSystem_AddSphereInfluencer(eInfluencerType type, vec3_t *origin, float radius, float score, eInfluencerScoreCurve score_curve, int teamMask, int entNum, int timeout, const char *description)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SpawnSystem_RemoveInfluencer
==============
*/
char SpawnSystem_RemoveInfluencer(int influencer_index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SpawnSystem_EnableInfluencer
==============
*/
char SpawnSystem_EnableInfluencer(int influencer_index, bool enabled)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SpawnSystem_SetInfluencerTeamMask
==============
*/
char SpawnSystem_SetInfluencerTeamMask(int influencer_index, int team_mask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SpawnSystem_ClearEntityInfluencers
==============
*/
void SpawnSystem_ClearEntityInfluencers(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_ClearTimedOutInfluencers
==============
*/
void SpawnSystem_ClearTimedOutInfluencers(SpawnInfluencer *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_InfluenceWeight
==============
*/
double SpawnSystem_InfluenceWeight(eInfluencerScoreCurve curve_type, float influencer_radius_sq, float distance_sq, float score)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SpawnSystem_ComputeSphereInfluence
==============
*/
double SpawnSystem_ComputeSphereInfluence(SpawnInfluencer *influencer, SpawnPoint *point)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SpawnSystem_ComputeCylinderInfluence
==============
*/
double SpawnSystem_ComputeCylinderInfluence(SpawnInfluencer *influencer, SpawnPoint *point)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SpawnSystem_ComputePointWeight
==============
*/
bool SpawnSystem_ComputePointWeight(gentity_t *player, int point_team, int influencer_team, SpawnPoint *point, bool noScoreCull, bool noDangerCull, bool bIsArchiveCall)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SpawnSystem_ComputePointWeights
==============
*/
int SpawnSystem_ComputePointWeights(gentity_t *player, int point_team, int influencer_team, bool allSpawns, bool noDangerCull)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SpawnSystem_DisableLowestScorePoints
==============
*/
void SpawnSystem_DisableLowestScorePoints(int team, int shouldDisable)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_SpotWouldTelefrag
==============
*/
bool SpawnSystem_SpotWouldTelefrag(vec3_t *vPos, vec3_t *otherPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SpawnSystem_ArchiveManualSpawn
==============
*/
void SpawnSystem_ArchiveManualSpawn(bool a1, gentity_t *a2, gentity_t *ent, vec3_t *spawn_origin, vec3_t *spawn_angles, const char *reason)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_GetSortedPointCount
==============
*/
int SpawnSystem_GetSortedPointCount(int team)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SpawnSystem_GetSortedPointEntNum
==============
*/
int SpawnSystem_GetSortedPointEntNum(int team, int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SpawnSystem_DebugRenderVisibilityCheck
==============
*/
void SpawnSystem_DebugRenderVisibilityCheck(vec3_t *point2, gentity_t *ignore_entity)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_IsSpawnPointVisible
==============
*/
char SpawnSystem_IsSpawnPointVisible(vec3_t *origin, vec3_t *angles, int vis_teams_mask, gentity_t *ignore_entity, bool render_mode_success, vec3_t *enemyPos, vec3_t *sightPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SpawnSystem_IsSpawnPointVisible
==============
*/
char SpawnSystem_IsSpawnPointVisible(vec3_t *origin, vec3_t *angles, int vis_teams_mask, gentity_t *ignore_entity)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SpawnSystem_SetSpawnClientFlag
==============
*/
void SpawnSystem_SetSpawnClientFlag(int clientNum, int flags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_DemoBadSpawn
==============
*/
void SpawnSystem_DemoBadSpawn(int playerEntityNum, int enemyEntityNum, int playerTeam, int pointTeam, int influencerTeam)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_RegisterPlayerDamage
==============
*/
void SpawnSystem_RegisterPlayerDamage(gentity_t *ent, gentity_t *enemy, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_ArchiveInfluencers
==============
*/
void SpawnSystem_ArchiveInfluencers(gentity_t *ent, int point_team, int influencer_team)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_CalculateCylinderLength
==============
*/
void SpawnSystem_CalculateCylinderLength(SpawnInfluencer *influencer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_UpdateCylinderInfluencer
==============
*/
void SpawnSystem_UpdateCylinderInfluencer(SpawnInfluencer *influencer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_AddCylinderInfluencer
==============
*/
int SpawnSystem_AddCylinderInfluencer(eInfluencerType type, vec3_t *origin, vec3_t *forward, vec3_t *up, float radius, float axis_length, float score, eInfluencerScoreCurve score_curve, int teamMask, int entNum, int timeout, const char *description)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SpawnSystem_UpdateInfluencerBounds
==============
*/
void SpawnSystem_UpdateInfluencerBounds()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_UpdateInfluencerOriginAngles
==============
*/
void SpawnSystem_UpdateInfluencerOriginAngles()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_CheckDangerousPoints
==============
*/
int SpawnSystem_CheckDangerousPoints(gentity_t *ent, int point_team, int vis_teams_mask, int maxDangerousChecks, bool bUseFirstNonTelefragWhenAllPointsDangerous)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SpawnSystem_Cmd_User_BadSpawn
==============
*/
void SpawnSystem_Cmd_User_BadSpawn(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_SortPoints
==============
*/
void SpawnSystem_SortPoints()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_Update
==============
*/
void SpawnSystem_Update(SpawnInfluencer *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_SortPointsByScore
==============
*/
void SpawnSystem_SortPointsByScore(int team)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpawnSystem_UpdateSpawnPointsForPlayer
==============
*/
int SpawnSystem_UpdateSpawnPointsForPlayer(bool a1, gentity_t *a2, char *allSpawns, gentity_t *ent, int point_team, int influencer_team, int vis_teams_mask, bool skipRecording)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SpawnSystem_Load
==============
*/
void SpawnSystem_Load(MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

