#include "types.h"

/*
==============
CL_GetMilestoneRowNum
==============
*/
int CL_GetMilestoneRowNum(const StringTable **stringTable, int *tableNumber, const int comparisonColumn1, const char *value1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_GetChallengeType
==============
*/
int CL_GetChallengeType(const char *statsType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ParseItemIndex
==============
*/
int ParseItemIndex(challengeTableRow_t *challengeRow, const char *reference)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CountNonWeaponChallenges
==============
*/
void CountNonWeaponChallenges(int challengeType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CountWeaponChallenges
==============
*/
void CountWeaponChallenges(int challengeType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FindFirstChallengeRowBSearch
==============
*/
challengeTableRow_t *FindFirstChallengeRowBSearch(int startEntry, int numEntries, int statNameHash)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_FindFirstChallengeRow
==============
*/
challengeTableRow_t *CL_FindFirstChallengeRow(int a1, int challengeType, int statNameHash, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_FindFirstWeaponChallengeRow
==============
*/
challengeTableRow_t *__cdecl CL_FindFirstWeaponChallengeRow(int challengeType, int statNameHash, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_IsChallengeLocked
==============
*/
bool CL_IsChallengeLocked(challengeTableRow_t *challengeRow, int rank, int pLevel)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FindNextCompletedChallenge
==============
*/
challengeTableRow_t *FindNextCompletedChallenge(challengeTableRow_t *challengeRow, int nameHash, int oldValue, int currentValue, int rank, int pLevel, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_GetNextCompletedChallenge
==============
*/
challengeTableRow_t *__cdecl CL_GetNextCompletedChallenge(int oldValue, int currentValue, int rank, int pLevel, challengeTableRow_t *challengeRow, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_GetChallengeRowByIndex
==============
*/
challengeTableRow_t *CL_GetChallengeRowByIndex(unsigned __int16 index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_FindChallegeRowForWeaponOption
==============
*/
challengeTableRow_t *CL_FindChallegeRowForWeaponOption(int itemIndex, int weaponOption)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_GetUniqueChallengeRow
==============
*/
challengeTableRow_t *CL_GetUniqueChallengeRow(unsigned int challengeIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CheckNameCollision
==============
*/
void CheckNameCollision(const char *name1, const char *name2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_GetChallengeRowData
==============
*/
const char *CL_GetChallengeRowData(challengeTableRow_t *challengeRow, milestoneTableColumns_t column)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_GetChallengeStatNameByName
==============
*/
const char *CL_GetChallengeStatNameByName(const char *statName, int itemIndex, hashName_t *hashNames, challengeHashLookup_t *challengeHashLookup)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_GetItemChallengeStatNameByName
==============
*/
const char *CL_GetItemChallengeStatNameByName(const char *statName, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_GetGroupChallengeStatNameByName
==============
*/
const char *CL_GetGroupChallengeStatNameByName(const char *statName, int groupIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_GetAttachmentChallengeStatNameByName
==============
*/
const char *CL_GetAttachmentChallengeStatNameByName(const char *statName, int attachmentIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_GetGameTypeChallengeStatNameByName
==============
*/
const char *CL_GetGameTypeChallengeStatNameByName(const char *statName, int gameTypeIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_GetChallengeStatName
==============
*/
const char *CL_GetChallengeStatName(milestoneTableColumns_t a1, challengeTableRow_t *a2, challengeTableRow_t *challengeRow, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
ParseChallengeExceptions
==============
*/
void ParseChallengeExceptions(milestoneTableColumns_t a1, challengeTableRow_t *a2, challengeTableRow_t *challengeRow)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CompareChallengeEntries
==============
*/
challengeTableRow_t *CompareChallengeEntries(milestoneTableColumns_t a1, const void *a, const void *b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GetChallengeStatNameSuffix
==============
*/
const char *GetChallengeStatNameSuffix(challengeTableRow_t *challengeRow)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CheckStatNames
==============
*/
void CheckStatNames(challengeTableRow_t *challengeRow, hashName_t *hashNames, int numHashNames, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BuildChallengeTable
==============
*/
void BuildChallengeTable()
{
	UNIMPLEMENTED(__FUNCTION__);
}

