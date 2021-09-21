#include "types.h"
#include "functions.h"

/*
==============
LiveStats_IsUsingLoadoutStats
==============
*/
bool LiveStats_IsUsingLoadoutStats()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetDDLHeaderVersion
==============
*/
unsigned int LiveStats_GetDDLHeaderVersion(unsigned __int8 *statsBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_CanPerformStatOperation
==============
*/
int LiveStats_CanPerformStatOperation(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetStat
==============
*/
int LiveStats_GetStat(const ControllerIndex_t controllerIndex, ddlState_t *searchState, statsLocation location, ddlValue_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetUIntStat
==============
*/
int LiveStats_GetUIntStat(const ControllerIndex_t controllerIndex, ddlState_t *searchState, statsLocation location)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetInt64Stat
==============
*/
ddlValue_t LiveStats_GetInt64Stat(const ControllerIndex_t controllerIndex, ddlState_t *searchState, statsLocation location)
{
	UNIMPLEMENTED(__FUNCTION__);
	ddlValue_t tmp;
	return tmp;
}

/*
==============
LiveStats_GetStringStat
==============
*/
const GfxViewParms *LiveStats_GetStringStat(const ControllerIndex_t controllerIndex, ddlState_t *searchState, statsLocation location)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStats_GetStatsDDLSizeByFile
==============
*/
bool LiveStats_GetStatsDDLSizeByFile(const char *ddlFileName, int version, int *size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_ChecksumGamerStats
==============
*/
unsigned int LiveStats_ChecksumGamerStats(unsigned __int8 *buffer, const int len)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_SetDInt64StatFromBuffer
==============
*/
void LiveStats_SetDInt64StatFromBuffer(unsigned __int8 *buffer, ddlState_t *searchState, const unsigned __int64 value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetDInt64Stat
==============
*/
void LiveStats_SetDInt64Stat(char *a1, const ControllerIndex_t controllerIndex, ddlState_t *searchState, const unsigned __int64 value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_IsStableStatsBufferInitialized
==============
*/
bool LiveStats_IsStableStatsBufferInitialized(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_SetItemStat
==============
*/
void LiveStats_SetItemStat(ddlState_t *searchStateStats, const char *statMember, unsigned __int8 *buffer, unsigned int value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GetItemStat
==============
*/
unsigned int LiveStats_GetItemStat(ddlState_t *searchStateStats, const char *statMember, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GameHistory_GetModeName
==============
*/
const char *LiveStats_GameHistory_GetModeName()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStats_GameHistory_GetMatchStatUInt
==============
*/
unsigned int LiveStats_GameHistory_GetMatchStatUInt(ddlState_t *searchState, unsigned __int8 *liveStatsBuffer, matchHistoryKeyIndex_t key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GameHistory_SetMatchStatUInt
==============
*/
bool LiveStats_GameHistory_SetMatchStatUInt(ddlState_t *searchState, unsigned __int8 *liveStatsBuffer, matchHistoryKeyIndex_t key, unsigned int value, ddlState_t *searchState2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GameHistory_SetMatchStatFloat
==============
*/
bool LiveStats_GameHistory_SetMatchStatFloat(ddlState_t *searchState, unsigned __int8 *liveStatsBuffer, matchHistoryKeyIndex_t key, float value, ddlState_t *searchState2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GameHistory_InitializeHitLocationsArray
==============
*/
void LiveStats_GameHistory_InitializeHitLocationsArray(ClientNum_t clientNum, ddlState_t *recentHitLocSearchState, unsigned __int8 *liveStatsBuffer, const char *arrayName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_Probation_GetProbationQuitTypeCost
==============
*/
void LiveStats_Probation_GetProbationQuitTypeCost(eGameModes gamemode, float (*quitTypeCost)[5])
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
StringBeginsWith
==============
*/
bool StringBeginsWith(const char *prefix, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetNumRecentlyUnlockedItems
==============
*/
int LiveStats_GetNumRecentlyUnlockedItems(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetRecentlyUnlockedItemIndex
==============
*/
int LiveStats_GetRecentlyUnlockedItemIndex(ControllerIndex_t controllerIndex, unsigned int itemNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_CompressStats
==============
*/
unsigned int LiveStats_CompressStats(const ControllerIndex_t controllerIndex, unsigned __int8 *compressedBuffer, int compressedBufferSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_DecompressStats
==============
*/
void LiveStats_DecompressStats(unsigned __int8 *statsDestBuffer, int numCompressedPackets)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ValidateChecksum
==============
*/
BOOL LiveStats_ValidateChecksum(unsigned __int8 *buffer, const int len)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_ValidateBuffer
==============
*/
BOOL LiveStats_ValidateBuffer(unsigned __int8 *buffer, int bufferSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_ParsePathToState
==============
*/
char LiveStats_ParsePathToState(const char *path, ddlState_t *destState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetRecentUnlocks
==============
*/
unsigned __int8 LiveStats_GetRecentUnlocks(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_UpdateSkillAndVariance_Score
==============
*/
double LiveStats_UpdateSkillAndVariance_Score(int count, PlayerSkill *players)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_SkillTestCmd
==============
*/
void LiveStats_SkillTestCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_CheckValidDelta
==============
*/
bool LiveStats_CheckValidDelta(statsDelta_t *delta, int currentDelta)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_CheckForModUnlocks
==============
*/
void LiveStats_CheckForModUnlocks(const ControllerIndex_t controllerIndex, int itemNumber, unsigned __int8 *liveStatsBuffer, unsigned __int8 *oldStatsBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_CheckForTokenUnlocks
==============
*/
void LiveStats_CheckForTokenUnlocks(const ControllerIndex_t controllerIndex, int startingRank, int endingRank)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_HasRecentItemAttachmentsUnlocked
==============
*/
bool LiveStats_HasRecentItemAttachmentsUnlocked(const ControllerIndex_t controllerIndex, unsigned int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_IsItemAttachmentRecentlyUnlocked
==============
*/
bool LiveStats_IsItemAttachmentRecentlyUnlocked(const ControllerIndex_t controllerIndex, unsigned int itemIndex, eAttachment attachment)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_StatReadDDLCommand
==============
*/
void LiveStats_StatReadDDLCommand(int cmdArgcStartPos, statsLocation statsLoc)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_StatReadDDLExtCmd
==============
*/
void LiveStats_StatReadDDLExtCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_StatReadDDLCmd
==============
*/
void LiveStats_StatReadDDLCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_StatWriteDDLCmdInternal
==============
*/
void LiveStats_StatWriteDDLCmdInternal(bool localize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_StatWriteDDLCmd
==============
*/
void LiveStats_StatWriteDDLCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_StatWriteFromLocalizedStrCmd
==============
*/
void LiveStats_StatWriteFromLocalizedStrCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ClearCustomClassWarning
==============
*/
void LiveStats_ClearCustomClassWarning(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ClearStatsWarning
==============
*/
void LiveStats_ClearStatsWarning(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_CheckClassVersion
==============
*/
bool LiveStats_CheckClassVersion(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetRootDDLState
==============
*/
ddlState_t *LiveStats_GetRootDDLState()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStats_GetStatsDDL
==============
*/
ddlDef_t *LiveStats_GetStatsDDL()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStats_GetClassSetsDDL
==============
*/
ddlDef_t *LiveStats_GetClassSetsDDL()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStats_GetCACRoot
==============
*/
const CACRoot *LiveStats_GetCACRoot(const CACRoot *result, const ControllerIndex_t controllerIndex, statsLocation playerStatsLocation)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStats_GetCACRoot
==============
*/
const CACRoot *LiveStats_GetCACRoot(const CACRoot *result, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStats_GetCustomMatchCACRoot
==============
*/
const CACRoot *LiveStats_GetCustomMatchCACRoot(const CACRoot *result, const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStats_GetLeagueCACRoot
==============
*/
const CACRoot *LiveStats_GetLeagueCACRoot(const CACRoot *result, const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStats_WriteXUIDToStats
==============
*/
char LiveStats_WriteXUIDToStats(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_ClearXUIDInStableStats
==============
*/
void LiveStats_ClearXUIDInStableStats(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ReadXUIDFromStatsBuffer
==============
*/
unsigned int LiveStats_ReadXUIDFromStatsBuffer(unsigned __int8 *buff)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_SetBufferInitialised
==============
*/
void LiveStats_SetBufferInitialised(const ControllerIndex_t controllerIndex, bool isInitialised)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetOnlineRankedState
==============
*/
void LiveStats_SetOnlineRankedState(unsigned __int8 *buffer, bool value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GetOnlineRankedState
==============
*/
bool LiveStats_GetOnlineRankedState(unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_SetOnlineZombieState
==============
*/
void LiveStats_SetOnlineZombieState(unsigned __int8 *buffer, bool value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GetOnlineZombieState
==============
*/
bool LiveStats_GetOnlineZombieState(unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_IsSettingOnlineStatsAllowed
==============
*/
BOOL LiveStats_IsSettingOnlineStatsAllowed()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetNemesisXuid
==============
*/
void LiveStats_GetNemesisXuid(const ControllerIndex_t controllerIndex, unsigned __int64 *nemesisXuid)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_MoveToDemonwareFlags
==============
*/
int LiveStats_MoveToDemonwareFlags(ddlState_t *searchState, demonwareFlags_e flags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_SetDemonwareFlag
==============
*/
void LiveStats_SetDemonwareFlag(const ControllerIndex_t controllerIndex, demonwareFlags_e flags, int value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_CheckPrestigeFiles
==============
*/
void LiveStats_CheckPrestigeFiles(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_BackupAllStats
==============
*/
void LiveStats_BackupAllStats(unsigned __int8 *inBuffer, unsigned __int8 *outBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_PrestigeAddCACCmd
==============
*/
void LiveStats_PrestigeAddCACCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ParsePathToDeltaState
==============
*/
bool LiveStats_ParsePathToDeltaState(const char *path, int currentDelta)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_BuildStatsDeltaTable
==============
*/
void LiveStats_BuildStatsDeltaTable()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GetGameTypeString
==============
*/
char *LiveStats_GetGameTypeString()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStats_MoveToPlayerStatPath
==============
*/
int LiveStats_MoveToPlayerStatPath(ddlState_t *resultState, const char *statName, const char *statType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_MoveToCurrentGameTypeStatPath
==============
*/
int LiveStats_MoveToCurrentGameTypeStatPath(ddlState_t *resultState, const char *statName, const char *statType, bool isGroup)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_MoveToWeaponStatPathZombie
==============
*/
int LiveStats_MoveToWeaponStatPathZombie(ddlState_t *resultState, int weaponStatIndex, const char *statName, const char *statType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_MoveToWeaponStatPath
==============
*/
int LiveStats_MoveToWeaponStatPath(ddlState_t *resultState, int weaponStatIndex, const char *statName, const char *statType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_MoveToWeaponXPPath
==============
*/
int LiveStats_MoveToWeaponXPPath(ddlState_t *resultState, int weaponStatIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_MoveToAttachmentStatPathZombie
==============
*/
int LiveStats_MoveToAttachmentStatPathZombie(ddlState_t *resultState, int attachmentIndex, const char *statName, const char *statType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_MoveToAttachmentStatPath
==============
*/
int LiveStats_MoveToAttachmentStatPath(ddlState_t *resultState, int attachmentIndex, const char *statName, const char *statType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_MoveToGroupStatPathZombie
==============
*/
int LiveStats_MoveToGroupStatPathZombie(ddlState_t *resultState, int groupIndex, const char *statName, const char *statType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_MoveToGroupStatPath
==============
*/
int LiveStats_MoveToGroupStatPath(ddlState_t *resultState, int groupIndex, const char *statName, const char *statType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_MoveToUnlockPath
==============
*/
int LiveStats_MoveToUnlockPath(ddlState_t *resultState, int tokenIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ddlTestFixedPoint_f
==============
*/
void ddlTestFixedPoint_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ddlTestFloat_f
==============
*/
void ddlTestFloat_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ddlTestBool_f
==============
*/
void ddlTestBool_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GetRankXPState
==============
*/
ddlState_t *LiveStats_GetRankXPState()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStats_SetMOTDViewed
==============
*/
void LiveStats_SetMOTDViewed(const ControllerIndex_t controllerIndex, int viewTime, int viewVersion)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetMOTDViewedCmd
==============
*/
void LiveStats_SetMOTDViewedCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetVotingDemonwareFlags
==============
*/
void LiveStats_SetVotingDemonwareFlags(const ControllerIndex_t controllerIndex, demonwareFlags_e flags, int value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_IncrementVotingMenuViewedCount
==============
*/
void LiveStats_IncrementVotingMenuViewedCount(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetDemonwareFlagsWithUTCTime
==============
*/
void LiveStats_SetDemonwareFlagsWithUTCTime(ControllerIndex_t controllerIndex, int demonwareFlagsStartIndex, int demonwareFlagsEndIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetVotingMenuViewedCmd
==============
*/
void __cdecl LiveStats_SetVotingMenuViewedCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetVoteCmd
==============
*/
void LiveStats_SetVoteCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetVoteOptOutCmd
==============
*/
void LiveStats_SetVoteOptOutCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetDSPPromotionOptOutCmd
==============
*/
void __cdecl LiveStats_SetDSPPromotionOptOutCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetDSPPromotionViewedCmd
==============
*/
void LiveStats_SetDSPPromotionViewedCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetGhostUpsellOptOutCmd
==============
*/
void __cdecl LiveStats_SetGhostUpsellOptOutCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetGhostUpsellViewedCmd
==============
*/
void LiveStats_SetGhostUpsellViewedCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetSPReminderViewedCmd
==============
*/
void LiveStats_SetSPReminderViewedCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetupStates
==============
*/
void LiveStats_SetupStates()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_InitGameTypes
==============
*/
void LiveStats_InitGameTypes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GetGameTypeIndex
==============
*/
int LiveStats_GetGameTypeIndex(const char *gameTypeRef, bool isHardcore)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetGameTypeIndexFromRef
==============
*/
int LiveStats_GetGameTypeIndexFromRef(const char *gameTypeRef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetGameTypeNameHash
==============
*/
int LiveStats_GetGameTypeNameHash(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetGameTypeName
==============
*/
char *LiveStats_GetGameTypeName(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStats_UpdateContentData
==============
*/
void LiveStats_UpdateContentData(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GetStatsDDLSize
==============
*/
int LiveStats_GetStatsDDLSize()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_ShouldSetStats
==============
*/
char LiveStats_ShouldSetStats()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetIntPlayerStatInternal
==============
*/
int LiveStats_GetIntPlayerStatInternal(int pathDepth, const char **statPath, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetIntStatFromPath
==============
*/
int LiveStats_GetIntStatFromPath(const char *statPath, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetIntPlayerStatFromBuffer
==============
*/
int LiveStats_GetIntPlayerStatFromBuffer(const char *statName, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetIntPlayerStatFromPath
==============
*/
int LiveStats_GetIntPlayerStatFromPath(const ControllerIndex_t controllerIndex, const char *statPath)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetIntPlayerStat
==============
*/
int LiveStats_GetIntPlayerStat(const ControllerIndex_t controllerIndex, const char *statName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetIntPlayerStatByMap
==============
*/
int LiveStats_GetIntPlayerStatByMap(const ControllerIndex_t controllerIndex, const char *map, const char *statName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetIntPlayerStatByKey
==============
*/
int LiveStats_GetIntPlayerStatByKey(const ControllerIndex_t controllerIndex, playerStatsKeyIndex_t keyIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_SetIntPlayerStatInternal
==============
*/
bool LiveStats_SetIntPlayerStatInternal(const ControllerIndex_t controllerIndex, int pathDepth, const char **path, unsigned __int8 *buffer, unsigned int statValue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetIntPlayerStatMatchDelta
==============
*/
int LiveStats_GetIntPlayerStatMatchDelta(const ControllerIndex_t controllerIndex, const char *statName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetIntPlayerStatMatchDeltaFromPath
==============
*/
int LiveStats_GetIntPlayerStatMatchDeltaFromPath(const ControllerIndex_t controllerIndex, const char *statPath)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_SetIntPlayerStat
==============
*/
bool LiveStats_SetIntPlayerStat(const ControllerIndex_t controllerIndex, const char *statName, unsigned int statValue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_SetIntPlayerStatByMap
==============
*/
bool LiveStats_SetIntPlayerStatByMap(const ControllerIndex_t controllerIndex, const char *map, const char *statName, unsigned int statValue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetPlayerStatByKeyFromBuffer
==============
*/
int LiveStats_GetPlayerStatByKeyFromBuffer(playerStatsKeyIndex_t key, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetStatsVersion
==============
*/
int LiveStats_GetStatsVersion(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_RestoreStatsFromStable
==============
*/
void LiveStats_RestoreStatsFromStable(const ControllerIndex_t controllerIndex, statsLocation initialStats, statsLocation currentStats)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SecurityErrorDetected
==============
*/
void LiveStats_SecurityErrorDetected(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetStatByKey
==============
*/
void LiveStats_SetStatByKey(unsigned int a1, const ControllerIndex_t controllerIndex, playerStatsKeyIndex_t keyIndex, const int value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_StatSetByNameCmd
==============
*/
void LiveStats_StatSetByNameCmd(unsigned int a1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_StatAddByNameCmd
==============
*/
void LiveStats_StatAddByNameCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_StatGetByNameInDvarCmd
==============
*/
void LiveStats_StatGetByNameInDvarCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_CheckXUIDAndReport
==============
*/
char LiveStats_CheckXUIDAndReport(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetPlayerStat
==============
*/
unsigned int LiveStats_GetPlayerStat(const char *statsList, const char *statName, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetLastGameWeaponStat
==============
*/
int LiveStats_GetLastGameWeaponStat(unsigned __int8 *liveStatsBuffer, unsigned __int8 *oldStatsBuffer, const char *weaponStatType, int itemNumber)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_UpdateBestWeaponIndexAAR
==============
*/
void __cdecl LiveStats_UpdateBestWeaponIndexAAR(unsigned __int8 *liveStatsBuffer, unsigned __int8 *oldStatsBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetPlayerStat
==============
*/
void LiveStats_SetPlayerStat(const char *statsList, const char *statName, unsigned __int8 *buffer, unsigned int statValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_UpdatetBestMatchAccuracy
==============
*/
bool LiveStats_UpdatetBestMatchAccuracy(unsigned __int8 *liveStatsBuffer, unsigned __int8 *oldStatsBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_UpdatetBestMatchKdRatio
==============
*/
bool LiveStats_UpdatetBestMatchKdRatio(unsigned __int8 *liveStatsBuffer, unsigned __int8 *oldStatsBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GameHistory_GetCompletionInfo
==============
*/
void LiveStats_GameHistory_GetCompletionInfo(const ControllerIndex_t localControllerIndex, const char *gamemode, const char *hostedType, unsigned int *started, unsigned int *completed, unsigned int *quit, unsigned int *timeout, unsigned int *dashboard)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GameHistory_IncCompletionStat
==============
*/
bool LiveStats_GameHistory_IncCompletionStat(const ControllerIndex_t localControllerIndex, const char *gamemode, const char *hostedOrPlayed, const char *statName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GameHistory_AddMatchHistory
==============
*/
void LiveStats_GameHistory_AddMatchHistory(const ControllerIndex_t localControllerIndex, const char *statName, bool hosted)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GameHistory_AddMatchCompleted
==============
*/
void LiveStats_GameHistory_AddMatchCompleted(const ControllerIndex_t localControllerIndex, bool hosted)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GameHistory_AddMatchTimeout
==============
*/
void LiveStats_GameHistory_AddMatchTimeout(const ControllerIndex_t localControllerIndex, bool hosted)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GameHistory_InitializeMatchHistory
==============
*/
void __cdecl LiveStats_GameHistory_InitializeMatchHistory(ClientNum_t clientNum, unsigned int gameTypeIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GameHistory_InitializeHitLocations
==============
*/
void LiveStats_GameHistory_InitializeHitLocations(char *a1, ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GameHistory_StartMatch
==============
*/
void LiveStats_GameHistory_StartMatch(ClientNum_t clientNum, unsigned int gameTypeIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GameHistory_MoveToCurrentHistory
==============
*/
bool LiveStats_GameHistory_MoveToCurrentHistory(unsigned __int8 *liveStatsBuffer, ddlState_t *matchHistorySearchState, unsigned int *matchHistoryIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GameHistory_MoveToHistory
==============
*/
bool LiveStats_GameHistory_MoveToHistory(unsigned __int8 *liveStatsBuffer, const char *gamemode, ddlState_t *matchHistorySearchState, unsigned int matchHistoryIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GameHistory_FinishMatch
==============
*/
void LiveStats_GameHistory_FinishMatch(char *a1, unsigned int a2, ClientNum_t clientNum, int finishType, int kills, int deaths, int score, int scoreboardPosition, float teamScoreRatio)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GameHistory_FinishMatch
==============
*/
void LiveStats_GameHistory_FinishMatch(ddlState_t *a1, const ControllerIndex_t controllerIndex, int finishType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_Probation_GiveProbation
==============
*/
char LiveStats_Probation_GiveProbation(const ControllerIndex_t controllerIndex, eGameModes gamemode, float time)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_Probation_MoveToMatchHistory
==============
*/
bool LiveStats_Probation_MoveToMatchHistory(const ControllerIndex_t controllerIndex, const char *gameModeString, ddlState_t *matchHistorySearchState, unsigned int *firstIndex, unsigned int *totalCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GameHistory_ClearMatchStats
==============
*/
void LiveStats_GameHistory_ClearMatchStats(const ControllerIndex_t controllerIndex, const char *gamemode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_Probation_ValidateProbationVersion
==============
*/
void LiveStats_Probation_ValidateProbationVersion(const ControllerIndex_t controllerIndex, eGameModes gamemode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_Probation_CheckInProbation
==============
*/
bool LiveStats_Probation_CheckInProbation(const ControllerIndex_t controllerIndex, eGameModes gamemode, bool report)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_Probation_ShouldCheckProbation
==============
*/
bool LiveStats_Probation_ShouldCheckProbation(const ControllerIndex_t controllerIndex, eGameModes gamemode)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_Probation_GetProbationPoints
==============
*/
float LiveStats_Probation_GetProbationPoints(const ControllerIndex_t controllerIndex, eGameModes gamemode, ddlState_t *matchHistorySearchState, unsigned int *probationMatchCount, unsigned int (*probationMatchs)[32])
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_Probation_CheckGettingProbation
==============
*/
bool LiveStats_Probation_CheckGettingProbation(eGameModes a1, ControllerIndex_t a2, float controllerIndex, const ControllerIndex_t gamemode, eGameModes a5)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_Probation_ForgiveProbation
==============
*/
void LiveStats_Probation_ForgiveProbation(const ControllerIndex_t controllerIndex, eGameModes gamemode, ddlState_t *matchHistorySearchState, unsigned int *probationMatchCount, unsigned int (*probationMatchs)[32])
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_Probation_ReportProbationStats
==============
*/
void LiveStats_Probation_ReportProbationStats(const ControllerIndex_t controllerIndex, eGameModes gamemode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_Probation_CheckForProbation
==============
*/
bool LiveStats_Probation_CheckForProbation(double controllerIndex, float noPopups, const ControllerIndex_t a3, eGameModes gamemode, bool a5)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_Theater_IncrementStat
==============
*/
void LiveStats_Theater_IncrementStat(const ControllerIndex_t controllerIndex, playerStatsKeyIndex_t statKeyIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GameHistory_DumpMatchStats
==============
*/
void LiveStats_GameHistory_DumpMatchStats(const ControllerIndex_t controllerIndex, const char *gamemode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GameHistory_ClearProbation
==============
*/
void LiveStats_GameHistory_ClearProbation(const ControllerIndex_t controllerIndex, const char *gamemode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GameHistory_GiveProbation
==============
*/
void LiveStats_GameHistory_GiveProbation(const ControllerIndex_t controllerIndex, const char *gamemode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GameHistory_FinishMatch
==============
*/
void LiveStats_GameHistory_FinishMatch(ddlState_t *a1, const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GameHistory_TimeoutMatch
==============
*/
void LiveStats_GameHistory_TimeoutMatch(ddlState_t *a1, const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GetTotalMatchesPlayed
==============
*/
int LiveStats_GetTotalMatchesPlayed(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_DumpMatchStatsCmd
==============
*/
void LiveStats_DumpMatchStatsCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ClearMatchStatsCmd
==============
*/
void LiveStats_ClearMatchStatsCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ClearProbationCmd
==============
*/
void LiveStats_ClearProbationCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GiveProbationCmd
==============
*/
void LiveStats_GiveProbationCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetLobbyPopup
==============
*/
void LiveStats_SetLobbyPopup(const ControllerIndex_t controllerIndex, const char *menuName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ValidateStatsBackup
==============
*/
char LiveStats_ValidateStatsBackup(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_MoveToSkillAndVariance
==============
*/
bool LiveStats_MoveToSkillAndVariance(ddlState_t *skillState, ddlState_t *varianceState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetSkillAndVariance
==============
*/
bool LiveStats_GetSkillAndVariance(const ControllerIndex_t controllerIndex, float *skill, float *variance)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_StoreOriginalValues
==============
*/
void LiveStats_StoreOriginalValues(const ControllerIndex_t controllerIndex, unsigned __int8 *statsBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_CheckVsOriginalValues
==============
*/
void LiveStats_CheckVsOriginalValues(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_AreStatsDeltasValid
==============
*/
statsValidation_t LiveStats_AreStatsDeltasValid(const ControllerIndex_t controllerIndex, statsLocation initialStats, statsLocation currentStats)
{
	UNIMPLEMENTED(__FUNCTION__);
	statsValidation_t tmp;
	return tmp;
}

/*
==============
LiveStats_CheckScoreInfoTable
==============
*/
void LiveStats_CheckScoreInfoTable()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ResetAttachmentChallenges
==============
*/
void LiveStats_ResetAttachmentChallenges(const ControllerIndex_t controllerIndex, const char *statName, const char *statType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ResetGroupChallenges
==============
*/
void LiveStats_ResetGroupChallenges(const ControllerIndex_t controllerIndex, const char *statName, const char *statType, challengeTableRow_t *challengeRow)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ResetGlobalChallenges
==============
*/
void LiveStats_ResetGlobalChallenges(const ControllerIndex_t controllerIndex, const char *statName, const char *statType, challengeTableRow_t *challengeRow)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ResetWeaponChallenges
==============
*/
void LiveStats_ResetWeaponChallenges(const ControllerIndex_t controllerIndex, const char *statName, const char *statType, challengeTableRow_t *challengeRow)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_PushMatchesPlayedMilestonesToElite
==============
*/
void LiveStats_PushMatchesPlayedMilestonesToElite(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_IncrementPlayerLeanMatchesCount
==============
*/
void LiveStats_IncrementPlayerLeanMatchesCount(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GetClanTagFeature
==============
*/
unsigned int LiveStats_GetClanTagFeature(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_SetClanTagText
==============
*/
char LiveStats_SetClanTagText(const ControllerIndex_t controllerIndex, const char *clanName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetPrestige
==============
*/
int LiveStats_GetPrestige(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetGametypeBan
==============
*/
BOOL LiveStats_GetGametypeBan(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetCurrency
==============
*/
int LiveStats_GetCurrency(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetIntZombieStatByKey
==============
*/
int LiveStats_GetIntZombieStatByKey(const ControllerIndex_t controllerIndex, zombieStatsKeyIndex_t keyIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetZombieWeightedRoundsPlayed
==============
*/
int LiveStats_GetZombieWeightedRoundsPlayed(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetZombieWeightedDowns
==============
*/
int LiveStats_GetZombieWeightedDowns(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetZombieTimePlayedTotal
==============
*/
int LiveStats_GetZombieTimePlayedTotal(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetIntPlayerStatByLocationGameType
==============
*/
int LiveStats_GetIntPlayerStatByLocationGameType(const ControllerIndex_t controllerIndex, const char *startLocation, const char *gameType, const char *statName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_TrackSpending
==============
*/
void LiveStats_TrackSpending(const ControllerIndex_t controllerIndex, int currencyAmount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SpendCurrency
==============
*/
char LiveStats_SpendCurrency(int a1, ControllerIndex_t a2, const ControllerIndex_t controllerIndex, int currencyAmount, pointsSpent_t reasonType, int reasonIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_DoXUIDsMatch
==============
*/
bool LiveStats_DoXUIDsMatch(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_InitStatsBuffer
==============
*/
void LiveStats_InitStatsBuffer(unsigned int a1, statsLocation a2, const ControllerIndex_t controllerIndex, statsResetReason_t reason)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ResetStats
==============
*/
void LiveStats_ResetStats(unsigned int a1, const ControllerIndex_t controllerIndex, bool versionChanged, statsResetReason_t reason)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GetConsoleDetails
==============
*/
char LiveStats_GetConsoleDetails(unsigned __int8 *consoleLocalIP, unsigned __int8 *consoleExternalIP)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_CheckUnlockTokens
==============
*/
void LiveStats_CheckUnlockTokens(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_DoSecurityChecks
==============
*/
void LiveStats_DoSecurityChecks(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_DoSecurityChecksCmd
==============
*/
void LiveStats_DoSecurityChecksCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_PrestigeStatsResetAllCmd
==============
*/
void LiveStats_PrestigeStatsResetAllCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_PrestigeRespecCmd
==============
*/
void LiveStats_PrestigeRespecCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_MoveToGameTypeStatPath
==============
*/
char *LiveStats_MoveToGameTypeStatPath(ddlState_t *resultState, const char *statName, const char *statType, int gameTypeIndex, bool isGroup)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStats_SetRankXP
==============
*/
void LiveStats_SetRankXP(unsigned int a1, ControllerIndex_t controllerIndex, unsigned int rankXP)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetRankXPCmd
==============
*/
void LiveStats_SetRankXPCmd(unsigned int a1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetZombieRank
==============
*/
void __cdecl LiveStats_SetZombieRank(ControllerIndex_t controllerIndex, unsigned int rank, unsigned int daysPlayed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetZombieRankCmd
==============
*/
void LiveStats_SetZombieRankCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetStatChangedInternal
==============
*/
void LiveStats_SetStatChangedInternal(const ControllerIndex_t controllerIndex, unsigned __int8 *statsMsg, int msgLen, int isMoreComing)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetStatChanged
==============
*/
void LiveStats_SetStatChanged(const ControllerIndex_t controllerIndex, const char *hexMsg, int isMoreComing)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetStatChangedNoCache
==============
*/
void LiveStats_SetStatChangedNoCache(const ControllerIndex_t controllerIndex, const char *hexMsg, int isMoreComing)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_PreGame
==============
*/
void LiveStats_PreGame(unsigned int a1, const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_MakeStableStatsBuffer
==============
*/
void LiveStats_MakeStableStatsBuffer(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_CopyFromSponsor
==============
*/
void LiveStats_CopyFromSponsor(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ResetGametypeChallenges
==============
*/
void LiveStats_ResetGametypeChallenges(const ControllerIndex_t controllerIndex, const char *statName, const char *statType, challengeTableRow_t *challengeRow)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GetRank
==============
*/
int LiveStats_GetRank(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetZombieLastDaysPlayed
==============
*/
int LiveStats_GetZombieLastDaysPlayed(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_SetLeaderboardCombinedRankZombie
==============
*/
bool LiveStats_SetLeaderboardCombinedRankZombie(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_SetCheckSumFromServer
==============
*/
void LiveStats_SetCheckSumFromServer(const char *checkSumMsg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_PublishNews
==============
*/
void LiveStats_PublishNews(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ShowStatsError
==============
*/
void LiveStats_ShowStatsError(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ValidateStats
==============
*/
void LiveStats_ValidateStats(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_PrestigeResetChallenges
==============
*/
void LiveStats_PrestigeResetChallenges(char *a1, const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GetCurrentChallengeIndex
==============
*/
int LiveStats_GetCurrentChallengeIndex(const ControllerIndex_t controllerIndex, int inputChallengeIndex, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetCurrentchallengeRowCmd
==============
*/
void LiveStats_GetCurrentchallengeRowCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_CheckAchievements
==============
*/
void LiveStats_CheckAchievements(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_CompareStatsVsStableBuffer
==============
*/
char LiveStats_CompareStatsVsStableBuffer(const ControllerIndex_t controllerIndex, bool onlyCheckValidStats)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_PrestigeStatsResetCmd
==============
*/
void LiveStats_PrestigeStatsResetCmd(unsigned int a1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_CompareStatsVsStableBufferCmd
==============
*/
void LiveStats_CompareStatsVsStableBufferCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_Init
==============
*/
void LiveStats_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

