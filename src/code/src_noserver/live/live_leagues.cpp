#include "types.h"
#include "functions.h"

/*
==============
ParseError
==============
*/
void ParseError(jsmntok_t *token, const char *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DataError
==============
*/
void DataError(jsmntok_t *token, const char *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetNextToken
==============
*/
jsmntok_t *GetNextToken(jsmntok_t **token, jsmntok_t *end)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GetEndToken
==============
*/
jsmntok_t *GetEndToken(jsmntok_t *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GetNextKeyValue
==============
*/
char GetNextKeyValue(jsmntok_t **token, jsmntok_t *end, jsmntok_t **key, jsmntok_t **value)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IsTokenEqual
==============
*/
bool IsTokenEqual(jsmntok_t *token, const char *str)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetTokenString
==============
*/
char *GetTokenString(jsmntok_t *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CopyTokenString
==============
*/
const GfxViewParms *CopyTokenString(jsmntok_t *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CopyTokenLocalizedString
==============
*/
const GfxViewParms *CopyTokenLocalizedString(jsmntok_t *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GetTokenInt
==============
*/
int GetTokenInt(jsmntok_t *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetTokenFloat
==============
*/
float GetTokenFloat(jsmntok_t *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetTokenBool
==============
*/
bool GetTokenBool(jsmntok_t *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetTokenTime
==============
*/
int GetTokenTime(jsmntok_t *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ParseSeasons
==============
*/
char ParseSeasons(League *league, jsmntok_t *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ParseIcons
==============
*/
char ParseIcons(LeagueDivision *division, jsmntok_t *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ParseAwards
==============
*/
char ParseAwards(League *league, jsmntok_t *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ParseNouns
==============
*/
char ParseNouns(jsmntok_t *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ParseNumbers
==============
*/
char ParseNumbers(jsmntok_t *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ParseLeagues
==============
*/
char ParseLeagues(jsmntok_t *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ParseDivisions
==============
*/
char ParseDivisions(jsmntok_t *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ResetLeagueInfo
==============
*/
void ResetLeagueInfo()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ValidateLeagueInfo
==============
*/
bool ValidateLeagueInfo()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CheckTokenizerError
==============
*/
bool CheckTokenizerError(jsmnerr_t result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ParseLeagueInfo
==============
*/
bool ParseLeagueInfo(const char *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_GetCurrentID
==============
*/
int League_GetCurrentID()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_ParseInfo
==============
*/
char League_ParseInfo(const char *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_GetTeamSize
==============
*/
int League_GetTeamSize(int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_GetSeasonByID
==============
*/
LeagueSeason *League_GetSeasonByID(int leagueID, int seasonID)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
League_GetActiveSeason
==============
*/
LeagueSeason *League_GetActiveSeason(int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
League_GetNextActiveSeason
==============
*/
LeagueSeason *League_GetNextActiveSeason(int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
League_FindDivision
==============
*/
LeagueDivision *League_FindDivision(int id, int divisionID)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
League_GetTeamIDFailure
==============
*/
char League_GetTeamIDFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_Backoff
==============
*/
void League_Backoff(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
League_SetupDefaultStats
==============
*/
void League_SetupDefaultStats(StatsLookup *lookup)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
League_PushStats
==============
*/
void League_PushStats(LeagueStats *stats, bdLeagueStatsInfo *dwStats)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
League_MSGWriteStats
==============
*/
void League_MSGWriteStats(msg_t *msg, const LeagueStats *stats)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
League_MSGReadStats
==============
*/
void League_MSGReadStats(msg_t *msg, LeagueStats *stats)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
League_GetStatsFailure
==============
*/
char League_GetStatsFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchTeamsListFailure
==============
*/
char League_FetchTeamsListFailure()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LeagueFetchSoloTeamIDFailure
==============
*/
char LeagueFetchSoloTeamIDFailure()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchTeamSubdivisionsSuccess
==============
*/
char League_FetchTeamSubdivisionsSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchTeamSubdivisionsFailure
==============
*/
char League_FetchTeamSubdivisionsFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchTeamInfoFailure
==============
*/
char League_FetchTeamInfoFailure()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchLbTeamMemberInfoFailure
==============
*/
char League_FetchLbTeamMemberInfoFailure()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchTeamMemberInfoSuccess
==============
*/
char League_FetchTeamMemberInfoSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchTeamMemberInfoFailure
==============
*/
char League_FetchTeamMemberInfoFailure()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SortSubdivisionInfosBySeasonDate
==============
*/
int SortSubdivisionInfosBySeasonDate(const void *a, const void *b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchHistorySubdivisionInfosFailure
==============
*/
char League_FetchHistorySubdivisionInfosFailure()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchLeagueHistoryFailure
==============
*/
char League_FetchLeagueHistoryFailure()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ParseMetaData
==============
*/
bool ParseMetaData(unsigned __int8 *metaData, int metaDataLength, int *divisionID, int *nameID, bool *isSolo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchSubdivisionFailure
==============
*/
char League_FetchSubdivisionFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_RefetchSubdivisionSuccess
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
League_RefetchSubdivisionFailure
==============
*/
char League_RefetchSubdivisionFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_ClearTeamTasks
==============
*/
void League_ClearTeamTasks(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
League_GetCurrentTeamID
==============
*/
char League_GetCurrentTeamID(const ControllerIndex_t controllerIndex, unsigned __int64 *teamID, int *memberCount, unsigned __int64 *subdivisionID, int *divisionID)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_SetOutcomes
==============
*/
bool League_SetOutcomes(const ControllerIndex_t controllerIndex, const LeagueOutcomes *outcomes)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_SetMatchDelta
==============
*/
void League_SetMatchDelta(StatsLookup *lookup, LeagueStats *outcomeStats, LeagueStats *baseStats)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
League_AreWeFetchingStats
==============
*/
char League_AreWeFetchingStats(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchLbDataFailure
==============
*/
char League_FetchLbDataFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FindTeamAndLeagueInFetchedData
==============
*/
char League_FindTeamAndLeagueInFetchedData(const ControllerIndex_t controllerIndex, unsigned __int64 teamID, int leagueID, unsigned __int64 *subdivisionID, bool *inPlacement)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchAllInfoForTeamInLeagueFailure
==============
*/
char League_FetchAllInfoForTeamInLeagueFailure()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_RecordEvent
==============
*/
void League_RecordEvent(const ControllerIndex_t controllerIndex, const char *eventName, unsigned __int64 uniqueID)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
League_GetCurrentTeamName
==============
*/
const GfxViewParms *League_GetCurrentTeamName(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
League_Status
==============
*/
void League_Status(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
League_GetSkillAndVariance
==============
*/
bool League_GetSkillAndVariance(const ControllerIndex_t controllerIndex, float *skill, float *variance)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_GetCurrentStats
==============
*/
char League_GetCurrentStats(const ControllerIndex_t controllerIndex, LeagueStats *stats)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_Status_f
==============
*/
void League_Status_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
League_Refresh_f
==============
*/
void League_Refresh_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
League_HandleInstantMessage
==============
*/
char League_HandleInstantMessage(ControllerIndex_t controllerIndex, const char *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_CalculateScore
==============
*/
void League_CalculateScore(League *league, int count, LeagueTeam *teams)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
League_CalculateMatchResult
==============
*/
void League_CalculateMatchResult(int count, LeagueTeam *teams)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
League_GetTeamID
==============
*/
char League_GetTeamID(const ControllerIndex_t controllerIndex, const unsigned __int64 *members, int memberCount, unsigned __int64 *result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_UpdateBonusAllocation
==============
*/
void League_UpdateBonusAllocation(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
League_GetStatsSuccess
==============
*/
char League_GetStatsSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchTeamsListInternal
==============
*/
bool League_FetchTeamsListInternal(const ControllerIndex_t controllerIndex, int offset, int numResultsToFetch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LeagueFetchSoloTeamIDSuccess
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
League_FetchSoloTeamID
==============
*/
bool League_FetchSoloTeamID(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchTeamsList
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
League_FetchTeamInfo
==============
*/
char League_FetchTeamInfo(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchTeamMemberInfo
==============
*/
char League_FetchTeamMemberInfo(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchHistorySubdivisionInfosSuccess
==============
*/
char League_FetchHistorySubdivisionInfosSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchLeagueHistorySubdivisionInfos
==============
*/
void League_FetchLeagueHistorySubdivisionInfos(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
League_FetchLeagueHistoryInternal
==============
*/
char League_FetchLeagueHistoryInternal(const ControllerIndex_t controllerIndex, unsigned __int64 teamID, __int16 currLeagueIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchLeagueHistorySuccess
==============
*/
char League_FetchLeagueHistorySuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchSubdivisionSuccess
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
League_UploadStatsSuccess
==============
*/
char League_UploadStatsSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_UploadStatsFailure
==============
*/
char League_UploadStatsFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_SetCurrentTeamID
==============
*/
void League_SetCurrentTeamID(const ControllerIndex_t controllerIndex, int leagueID, unsigned __int64 teamID, int memberCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
League_ApplyOutcome
==============
*/
char League_ApplyOutcome(bdLeagueStatsInfo *a1, StatsLookup *a2, const ControllerIndex_t controllerIndex, LeagueOutcome outcome, int leagueHash)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchLbDataSuccess
==============
*/
char League_FetchLbDataSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchLbDataByPivot
==============
*/
char League_FetchLbDataByPivot(const ControllerIndex_t controllerIndex, unsigned __int64 teamID, unsigned __int64 subdivisionID, int numResults)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchLbDataByRank
==============
*/
char League_FetchLbDataByRank(const ControllerIndex_t controllerIndex, unsigned __int64 subdivisionID, int numResults, int offset)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_SetCurrentTeamEmblem
==============
*/
bool League_SetCurrentTeamEmblem(const ControllerIndex_t controllerIndex, CompositeEmblemLayer *layers, int layerCount, unsigned __int64 teamID)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_Force_f
==============
*/
void League_Force_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
League_Fake_f
==============
*/
void League_Fake_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
League_FetchTeamsListSuccess
==============
*/
char League_FetchTeamsListSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchLbData
==============
*/
char League_FetchLbData(const ControllerIndex_t controllerIndex, unsigned __int64 teamID, unsigned __int64 subdivisionID, int numResults, int offset)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchAllInfoForTeamInLeagueSuccess
==============
*/
char League_FetchAllInfoForTeamInLeagueSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
League_FetchLbData_f
==============
*/
void League_FetchLbData_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
League_Init
==============
*/
void League_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ParseError
==============
*/
void ParseError(const char *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

