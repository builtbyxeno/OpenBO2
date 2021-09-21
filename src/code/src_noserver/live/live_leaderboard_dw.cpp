#include "types.h"
#include "functions.h"

/*
==============
LiveLeaderboard_SetupNestedTask
==============
*/
TaskRecord *LiveLeaderboard_SetupNestedTask(const TaskDefinition *taskdef, ControllerIndex_t localControllerIndex, TaskRecord *nestedTask, void *payload)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LiveLeaderboard_RowDebugPrint
==============
*/
/*void LiveLeaderboard_RowDebugPrint(const ControllerIndex_t localControllerIndex, const unsigned __int64 userID, const LeaderboardDef *lbDef, int trackType, LeaderboardRow<10> *lbRow, bool isWriting)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
LiveLeaderboard_ReadStatsDataFailure
==============
*/
char LiveLeaderboard_ReadStatsDataFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_ReadGhostLBFailure
==============
*/
char LiveLeaderboard_ReadGhostLBFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_IsGhostLBFetchingFinished
==============
*/
BOOL LiveLeaderboard_IsGhostLBFetchingFinished()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_GetGhostLBReadBeginTime
==============
*/
int LiveLeaderboard_GetGhostLBReadBeginTime()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_CalculatePlayerLbRowValue
==============
*/
int LiveLeaderboard_CalculatePlayerLbRowValue(const ControllerIndex_t localControllerIndex, const LeaderboardDef *lbDef, int colIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_UploadPlayerDataExecuteTask
==============
*/
/*char LiveLeaderboard_UploadPlayerDataExecuteTask(const ControllerIndex_t localControllerIndex, const TaskDefinition *taskDef, LeaderboardRow<10> *lbRows, const int uploadRows)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
LiveLeaderboard_WriteStatsDataSuccess
==============
*/
char LiveLeaderboard_WriteStatsDataSuccess()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_CanUserAccessLeaderboard
==============
*/
char LiveLeaderboard_CanUserAccessLeaderboard(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_IsUploadedZombie
==============
*/
bool LiveLeaderboard_IsUploadedZombie(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_SetUploadedStatusZombie
==============
*/
void LiveLeaderboard_SetUploadedStatusZombie(const ControllerIndex_t localControllerIndex, bool isUploaded)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveLeaderboard_SetWriteLeaderboards
==============
*/
void LiveLeaderboard_SetWriteLeaderboards(const LocalClientNum_t localClientNum, const char *lbConfigStr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveLeaderboard_CompareXUserStatsRowRanks
==============
*/
int LiveLeaderboard_CompareXUserStatsRowRanks(const void *r1, const void *r2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_SortXUserStatsByRank
==============
*/
void LiveLeaderboard_SortXUserStatsByRank(Leaderboard *lb)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveLeaderboard_ReadStatsSuccess
==============
*/
void LiveLeaderboard_ReadStatsSuccess(ControllerIndex_t localControllerIndex, Leaderboard *lb)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveLeaderboard_GetStatsByXuidsFailure
==============
*/
char LiveLeaderboard_GetStatsByXuidsFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_GetByRank
==============
*/
char __cdecl LiveLeaderboard_GetByRank(Leaderboard *lb, const ControllerIndex_t localControllerIndex, const unsigned int rankIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_GetByRankFailure
==============
*/
char LiveLeaderboard_GetByRankFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_GetByPlayerFailure
==============
*/
char LiveLeaderboard_GetByPlayerFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboards_GetResetLeaderboards
==============
*/
bool LiveLeaderboards_GetResetLeaderboards(const char *resetFile, const char **leaderboards, int *leaderboardCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_SortMultiSearchResults
==============
*/
ControllerIndex_t LiveLeaderboard_SortMultiSearchResults(ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	ControllerIndex_t tmp;
	return tmp;
}

/*
==============
LiveLeaderboard_lbGetCache
==============
*/
int LiveLeaderboard_lbGetCache(const ControllerIndex_t controllerIndex, const int colIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_ReadStatsDataSuccess
==============
*/
char LiveLeaderboard_ReadStatsDataSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_ReadGhostLBSuccess
==============
*/
char LiveLeaderboard_ReadGhostLBSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_ColumnIDToValue
==============
*/
/*int LiveLeaderboard_ColumnIDToValue(const LeaderboardDef *lbDef, LeaderboardRow<10> *row, int colId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
LiveLeaderboard_MakeRow
==============
*/
/*int LiveLeaderboard_MakeRow(const ControllerIndex_t localControllerIndex, const LeaderboardDef *lbDef, LeaderboardRow<10> *const row, LbAggType aggType, unsigned __int64 userID)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
LiveLeaderboard_RankUpdate
==============
*/
/*bool LiveLeaderboard_RankUpdate(const ControllerIndex_t localControllerIndex, const unsigned __int64 userID, const LeaderboardDef *lbDef, LeaderboardRow<10> *lbRow, const int aggType, const int trackType, int *uploadRows)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
LiveLeaderboard_CombineUpdate
==============
*/
/*bool LiveLeaderboard_CombineUpdate(const ControllerIndex_t localControllerIndex, const unsigned __int64 userID, const LeaderboardDef *lbDef, LeaderboardRow<10> *lbRow, const int trackType, int *uploadRows)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
LiveLeaderboard_UploadPlayerDataExecuteBlockingTask
==============
*/
/*char LiveLeaderboard_UploadPlayerDataExecuteBlockingTask(const ControllerIndex_t localControllerIndex, LeaderboardRow<10> *lbRows, const int uploadRows)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
LiveLeaderboard_WriteStatsDataFailure
==============
*/
char LiveLeaderboard_WriteStatsDataFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_UploadPlayerStatsExecute
==============
*/
char LiveLeaderboard_UploadPlayerStatsExecute(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_UploadPlayerStats
==============
*/
char LiveLeaderboard_UploadPlayerStats(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_GetStatsSuccess
==============
*/
char LiveLeaderboard_GetStatsSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_GetStatsByXuidsSuccess
==============
*/
char LiveLeaderboard_GetStatsByXuidsSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboard_GetByPlayerSuccess
==============
*/
char LiveLeaderboard_GetByPlayerSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboards_ResetLeaderboardsClearRows
==============
*/
char LiveLeaderboards_ResetLeaderboardsClearRows(const ControllerIndex_t controllerIndex, const char **leaderboards, int leaderboardCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LiveLeaderboards_ResetLeaderboards
==============
*/
void LiveLeaderboards_ResetLeaderboards(const char **a1, char *a2, const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveLeaderboards_ResetLeaderboards_f
==============
*/
void LiveLeaderboards_ResetLeaderboards_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveLeaderboard_Init
==============
*/
void LiveLeaderboard_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LiveLeaderboard_GetMiniLbsSuccess
==============
*/
char LiveLeaderboard_GetMiniLbsSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

