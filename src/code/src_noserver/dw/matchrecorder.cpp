#include "types.h"
#include "functions.h"

/*
==============
MatchRecorderDDLSetFloat
==============
*/
void MatchRecorderDDLSetFloat(ddlState_t *searchState, const char *name, float value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorderDDLSetInt
==============
*/
void MatchRecorderDDLSetInt(ddlState_t *searchState, const char *name, unsigned int value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorderDDLGetInt
==============
*/
unsigned int MatchRecorderDDLGetInt(ddlState_t *searchState, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MatchRecorderDDLSetInt64
==============
*/
void MatchRecorderDDLSetInt64(ddlState_t *searchState, const char *name, unsigned __int64 value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorderDDLGetInt64
==============
*/
unsigned __int64 MatchRecorderDDLGetInt64(ddlState_t *searchState, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MatchRecorderDDLSetString
==============
*/
void MatchRecorderDDLSetString(ddlState_t *searchState, const char *name, const char *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecordCopyExternalIP
==============
*/
void MatchRecordCopyExternalIP(ddlState_t playerState, ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetCurrentMapIndexByUIMapname
==============
*/
int GetCurrentMapIndexByUIMapname()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetCurrentMapIndex
==============
*/
int GetCurrentMapIndex()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
setWeaponHashValue
==============
*/
void setWeaponHashValue(const char *statName, int limit, int index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
isTrackableWeapon
==============
*/
char isTrackableWeapon(int index, int currentMapIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MatchRecord_IsHeatMapDataGenerated
==============
*/
bool MatchRecord_IsHeatMapDataGenerated()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetMaxLivesOrDowns
==============
*/
int GetMaxLivesOrDowns()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MatchRecord_GetMapIndex
==============
*/
unsigned int MatchRecord_GetMapIndex()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MatchRecord_SetPlayerCount
==============
*/
void MatchRecord_SetPlayerCount(__int16 currentPlayers)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecord_GetLifeCount
==============
*/
unsigned int MatchRecord_GetLifeCount()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MatchRecord_SetLifeCount
==============
*/
void MatchRecord_SetLifeCount(__int16 currentLives)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecord_SetDownCount
==============
*/
void MatchRecord_SetDownCount(__int16 currentLives)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecord_GetPlayerInSlot
==============
*/
bool MatchRecord_GetPlayerInSlot(int playerSlot, ddlState_t *playerSlotState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MatchRecord_SearchForPlayerSlotByXUID
==============
*/
int MatchRecord_SearchForPlayerSlotByXUID(unsigned __int64 xuid)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MatchRecord_GetXUIDForPlayerSlot
==============
*/
unsigned __int64 MatchRecord_GetXUIDForPlayerSlot(int playerSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MatchRecord_GetLifeInSlot
==============
*/
bool MatchRecord_GetLifeInSlot(int lifeSlot, ddlState_t *lifeSlotState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MatchRecord_GetDownInSlot
==============
*/
bool MatchRecord_GetDownInSlot(int downSlot, ddlState_t *downSlotState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MatchRecorder_UpdateSubparties
==============
*/
void MatchRecorder_UpdateSubparties()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecord_SearchCreateForPlayer
==============
*/
int MatchRecord_SearchCreateForPlayer(gclient_t *client, ddlState_t *playerState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetCurrentPlaylistIndex
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
FindBitchForPlayer
==============
*/
void FindBitchForPlayer(int attackingPlayerSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FindNemesisForPlayer
==============
*/
void FindNemesisForPlayer(int attackingPlayerSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SaveTeamScores
==============
*/
void SaveTeamScores()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_RecordGameResult
==============
*/
void MatchRecorder_RecordGameResult(team_t winner, bool isDraw)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetWorldLocation
==============
*/
void GetWorldLocation(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecord_ReviveZombie
==============
*/
void MatchRecord_ReviveZombie(gclient_t *client, gclient_t *reviver)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecordSpawn
==============
*/
void MatchRecordSpawn(gclient_t *client)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecordSetHitStat
==============
*/
void MatchRecordSetHitStat(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecordHit
==============
*/
void MatchRecordHit(gclient_t *attackerClient, hitLocation_t hitLocation)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecordDeath
==============
*/
void MatchRecordDeath(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecordEnd
==============
*/
void MatchRecordEnd(gclient_t *client)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecordBegin
==============
*/
void MatchRecordBegin()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecordPlayerDetails
==============
*/
void MatchRecordPlayerDetails(gclient_t *client, const char *reason)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecordSetPlayerStat
==============
*/
void MatchRecordSetPlayerStat(gclient_t *client, const char *statName, int statValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecordEventFailure
==============
*/
char MatchRecordEventFailure()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MatchRecorder_TagXuids
==============
*/
void MatchRecorder_TagXuids(int *numTags, bdTag *tags, int maxTags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_RecordKillstreakEvent
==============
*/
void MatchRecorder_RecordKillstreakEvent(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_RecordKillstreakEndEvent
==============
*/
void MatchRecorder_RecordKillstreakEndEvent(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_RecordGameEvent
==============
*/
void MatchRecorder_RecordGameEvent(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_RecordKillModifier
==============
*/
void MatchRecorder_RecordKillModifier(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_RecordScoreEvent
==============
*/
void MatchRecorder_RecordScoreEvent(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_RecordLoadoutAndPerks
==============
*/
void MatchRecorder_RecordLoadoutAndPerks(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_RecordNumZombieRounds
==============
*/
void MatchRecorder_RecordNumZombieRounds(ddlState_t *a1, const char *a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_RecordMultiKill
==============
*/
void MatchRecorder_RecordMultiKill(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecord_WriteItemStats
==============
*/
void MatchRecord_WriteItemStats(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_IncrementHeaderStat
==============
*/
/*void MatchRecorder_IncrementHeaderStat(const char *a1@<edx>, ddlState_t *a2@<ecx>, const char *statName)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
MatchRecorder_RecordZombieGameInfoEnd
==============
*/
void MatchRecorder_RecordZombieGameInfoEnd(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_RecordZombiePlayerDeath
==============
*/
void MatchRecorder_RecordZombiePlayerDeath()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_RecordZombiePlayerDown
==============
*/
/*void MatchRecorder_RecordZombiePlayerDown(float a1@<ebx>, unsigned __int8 *a2@<edi>, gclient_t *client)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
IsPlayerInRound
==============
*/
bool IsPlayerInRound(unsigned __int64 xuid, ddlState_t *roundState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetPlayerRoundSlot
==============
*/
bool GetPlayerRoundSlot(unsigned __int64 xuid, ddlState_t *playerRoundSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MatchRecord_ZombieRoundStart
==============
*/
void MatchRecord_ZombieRoundStart(ddlState_t *a1, const char *a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecord_ZombieRoundEnd
==============
*/
void MatchRecord_ZombieRoundEnd(ddlState_t *a1, const char *a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_IncrementPlayerStat
==============
*/
void MatchRecorder_IncrementPlayerStat(gclient_t *client, const char *statName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecord_InitMatchDataInternal
==============
*/
int MatchRecord_InitMatchDataInternal(char *inputBuffer, int buffSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MatchRecord_InitMatchData
==============
*/
void MatchRecord_InitMatchData()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GenerateBinaryMatchSummary
==============
*/
void GenerateBinaryMatchSummary(unsigned int titleID, const char *gameMode, unsigned __int64 fileID)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GenerateRecordedMatchData
==============
*/
void GenerateRecordedMatchData(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecord_ParseDownloadedMatchData
==============
*/
/*BOOL MatchRecord_ParseDownloadedMatchData@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
MatchRecordPointsSpent
==============
*/
void MatchRecordPointsSpent(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecordEventSuccess
==============
*/
char MatchRecordEventSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

