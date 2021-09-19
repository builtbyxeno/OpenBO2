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
int LiveStats_GetStat(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetUIntStat
==============
*/
int LiveStats_GetUIntStat(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GetInt64Stat
==============
*/
ddlValue_t LiveStats_GetInt64Stat(
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
const GfxViewParms *LiveStats_GetStringStat(
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
void LiveStats_SetDInt64StatFromBuffer(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetDInt64Stat
==============
*/
void LiveStats_SetDInt64Stat(
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
void LiveStats_SetItemStat(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GetItemStat
==============
*/
unsigned int LiveStats_GetItemStat(
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
unsigned int LiveStats_GameHistory_GetMatchStatUInt(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GameHistory_SetMatchStatUInt
==============
*/
bool LiveStats_GameHistory_SetMatchStatUInt(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GameHistory_SetMatchStatFloat
==============
*/
bool LiveStats_GameHistory_SetMatchStatFloat(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GameHistory_InitializeHitLocationsArray
==============
*/
void LiveStats_GameHistory_InitializeHitLocationsArray(
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
unsigned int LiveStats_CompressStats(
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
void LiveStats_CheckForModUnlocks(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_CheckForTokenUnlocks
==============
*/
void LiveStats_CheckForTokenUnlocks(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_HasRecentItemAttachmentsUnlocked
==============
*/
bool LiveStats_HasRecentItemAttachmentsUnlocked(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_IsItemAttachmentRecentlyUnlocked
==============
*/
bool LiveStats_IsItemAttachmentRecentlyUnlocked(
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
const CACRoot *LiveStats_GetCACRoot(
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
int LiveStats_MoveToCurrentGameTypeStatPath(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_MoveToWeaponStatPathZombie
==============
*/
int LiveStats_MoveToWeaponStatPathZombie(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_MoveToWeaponStatPath
==============
*/
int LiveStats_MoveToWeaponStatPath(
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
int LiveStats_MoveToAttachmentStatPathZombie(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_MoveToAttachmentStatPath
==============
*/
int LiveStats_MoveToAttachmentStatPath(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_MoveToGroupStatPathZombie
==============
*/
int LiveStats_MoveToGroupStatPathZombie(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_MoveToGroupStatPath
==============
*/
int LiveStats_MoveToGroupStatPath(
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
void LiveStats_SetVotingDemonwareFlags(
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
void LiveStats_SetDemonwareFlagsWithUTCTime(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetVotingMenuViewedCmd
==============
*/
void LiveStats_SetVotingMenuViewedCmd()
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
void LiveStats_SetDSPPromotionOptOutCmd()
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
void LiveStats_SetGhostUpsellOptOutCmd()
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
int LiveStats_GetIntPlayerStatByMap(
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
bool LiveStats_SetIntPlayerStatInternal(
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
bool LiveStats_SetIntPlayerStat(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_SetIntPlayerStatByMap
==============
*/
bool LiveStats_SetIntPlayerStatByMap(
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
void LiveStats_RestoreStatsFromStable(
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
void LiveStats_SetStatByKey(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_StatSetByNameCmd
==============
*/
/*void LiveStats_StatSetByNameCmd(unsigned int a1@<edi>)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

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
int LiveStats_GetLastGameWeaponStat(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_UpdateBestWeaponIndexAAR
==============
*/
void LiveStats_UpdateBestWeaponIndexAAR(unsigned __int8 *liveStatsBuffer, unsigned __int8 *oldStatsBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_SetPlayerStat
==============
*/
void LiveStats_SetPlayerStat(
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
void LiveStats_GameHistory_GetCompletionInfo(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GameHistory_IncCompletionStat
==============
*/
bool LiveStats_GameHistory_IncCompletionStat(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GameHistory_AddMatchHistory
==============
*/
void LiveStats_GameHistory_AddMatchHistory(
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
void LiveStats_GameHistory_InitializeMatchHistory(ClientNum_t clientNum, unsigned int gameTypeIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GameHistory_InitializeHitLocations
==============
*/
void LiveStats_GameHistory_InitializeHitLocations(ClientNum_t clientNum)
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
bool LiveStats_GameHistory_MoveToCurrentHistory(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GameHistory_MoveToHistory
==============
*/
bool LiveStats_GameHistory_MoveToHistory(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_GameHistory_FinishMatch
==============
*/
void LiveStats_GameHistory_FinishMatch(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GameHistory_FinishMatch
==============
*/
void LiveStats_GameHistory_FinishMatch(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_Probation_GiveProbation
==============
*/
char LiveStats_Probation_GiveProbation(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_Probation_MoveToMatchHistory
==============
*/
bool LiveStats_Probation_MoveToMatchHistory(
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
bool LiveStats_Probation_CheckInProbation(
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
float LiveStats_Probation_GetProbationPoints(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveStats_Probation_CheckGettingProbation
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
LiveStats_Probation_ForgiveProbation
==============
*/
void LiveStats_Probation_ForgiveProbation(
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
LiveStats_Theater_IncrementStat
==============
*/
void LiveStats_Theater_IncrementStat(
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
/*void LiveStats_GameHistory_FinishMatch(ddlState_t *a1@<edi>, const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
LiveStats_GameHistory_TimeoutMatch
==============
*/
/*void LiveStats_GameHistory_TimeoutMatch(ddlState_t *a1@<edi>, const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

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
statsValidation_t LiveStats_AreStatsDeltasValid(
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
void LiveStats_ResetAttachmentChallenges(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ResetGroupChallenges
==============
*/
void LiveStats_ResetGroupChallenges(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ResetGlobalChallenges
==============
*/
void LiveStats_ResetGlobalChallenges(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ResetWeaponChallenges
==============
*/
void LiveStats_ResetWeaponChallenges(
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
int LiveStats_GetIntPlayerStatByLocationGameType(
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
/*char LiveStats_SpendCurrency@<al>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

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
void LiveStats_InitStatsBuffer(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_ResetStats
==============
*/
void LiveStats_ResetStats(
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
char *LiveStats_MoveToGameTypeStatPath(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveStats_SetRankXP
==============
*/
/*void LiveStats_SetRankXP(unsigned int a1@<esi>, ControllerIndex_t controllerIndex, unsigned int rankXP)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
LiveStats_SetRankXPCmd
==============
*/
/*void LiveStats_SetRankXPCmd(unsigned int a1@<esi>)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
LiveStats_SetZombieRank
==============
*/
void LiveStats_SetZombieRank(ControllerIndex_t controllerIndex, unsigned int rank, unsigned int daysPlayed)
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
void LiveStats_SetStatChangedInternal(
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
void LiveStats_SetStatChangedNoCache(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_PreGame
==============
*/
/*void LiveStats_PreGame(unsigned int a1@<edi>, const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

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
void LiveStats_ResetGametypeChallenges(
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
void LiveStats_PrestigeResetChallenges(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveStats_GetCurrentChallengeIndex
==============
*/
int LiveStats_GetCurrentChallengeIndex(
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
/*void LiveStats_PrestigeStatsResetCmd(unsigned int a1@<edi>)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

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

