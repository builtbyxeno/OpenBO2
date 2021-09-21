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
int __cdecl GetCurrentPlaylistIndex()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
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
void GetWorldLocation(float xPos, float yPos, float zPos, unsigned __int8 *xWorld, unsigned __int8 *yWorld, unsigned __int8 *zWorld)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecord_ReviveZombie
==============
*/
void __cdecl MatchRecord_ReviveZombie(gclient_t *client, gclient_t *reviver)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecordSpawn
==============
*/
void __cdecl MatchRecordSpawn(gclient_t *client)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecordSetHitStat
==============
*/
void MatchRecordSetHitStat(ddlState_t playerState, gclient_t *attackerClient, const hitLocation_t hitLocation, const char *hitLocStatName)
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
void __cdecl MatchRecordDeath(gclient_t *client, gclient_t *attackerClient, const char *weaponName, hitLocation_t hitLocation)
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
void __cdecl MatchRecordBegin()
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
void MatchRecorder_RecordKillstreakEvent(ddlState_t *a1, unsigned __int8 *a2, float client, gclient_t *killstreakIndex, int a5)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_RecordKillstreakEndEvent
==============
*/
void MatchRecorder_RecordKillstreakEndEvent(ddlState_t *a1, gclient_t *a2, gclient_t *client, int killstreakIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_RecordGameEvent
==============
*/
void MatchRecorder_RecordGameEvent(ddlState_t *a1, gclient_t *a2, float client, gclient_t *gameEvent, const char *a5)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_RecordKillModifier
==============
*/
void MatchRecorder_RecordKillModifier(ddlState_t *a1, gclient_t *a2, gclient_t *client, const char *killModifier)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_RecordScoreEvent
==============
*/
void MatchRecorder_RecordScoreEvent(ddlState_t *a1, gclient_t *a2, gclient_t *client, const char *scoreEvent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_RecordLoadoutAndPerks
==============
*/
void MatchRecorder_RecordLoadoutAndPerks(ddlState_t *a1, gclient_t *a2, gclient_t *client, int primaryWeaponIndex, int attachmentBitsPrimary, int secondaryWeaponIndex, int attachmentBitsSecondary, int grenadeTypePrimary, int grenadeTypeSecondary, int killstreak1, int killstreak2, int killstreak3)
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
void MatchRecorder_RecordMultiKill(ddlState_t *a1, gclient_t *a2, gclient_t *client, int killCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecord_WriteItemStats
==============
*/
void MatchRecord_WriteItemStats(char *a1, gentity_t *playerEnt, ClientNum_t clientNum, int weaponStatIndex, int weaponIndex, int attachmentBits, const char *weapName, const char *statName, unsigned int addValue, int statNameHash)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_IncrementHeaderStat
==============
*/
void MatchRecorder_IncrementHeaderStat(const char *a1, ddlState_t *a2, const char *statName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecorder_RecordZombieGameInfoEnd
==============
*/
void MatchRecorder_RecordZombieGameInfoEnd(const char *a1, ddlState_t *a2, const char *gameModeGroup, const char *gameMode, const char *mapLocation, int numRounds)
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
void MatchRecorder_RecordZombiePlayerDown(float client, gclient_t *a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

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
void GenerateRecordedMatchData(ControllerIndex_t controllerIndex, const char *gameMode, char **matchRecordBuffer, int *matchRecordBufferSize, unsigned __int64 fileID)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchRecord_ParseDownloadedMatchData
==============
*/
BOOL MatchRecord_ParseDownloadedMatchData(int a1, char *a2, const ControllerIndex_t controllerIndex, char *inputBuffer, int buffsize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MatchRecordPointsSpent
==============
*/
void MatchRecordPointsSpent(ControllerIndex_t controllerIndex, int amount, pointsSpent_t reasonType, int reasonIndex)
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

