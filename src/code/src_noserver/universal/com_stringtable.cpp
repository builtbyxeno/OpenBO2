#include "types.h"

/*
==============
StringTable_FirstHashIndex
==============
*/
int StringTable_FirstHashIndex(const StringTable *table, int hash)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
StringTable_LookupNearestRowNumForValue
==============
*/
int StringTable_LookupNearestRowNumForValue(const StringTable *table, const int comparisonColumn, const char *value, const int row)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
StringTable_LookupRowNumForValue
==============
*/
int StringTable_LookupRowNumForValue(const StringTable *table, const int comparisonColumn, const char *value)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
StringTable_LookupRowNumForValue
==============
*/
int StringTable_LookupRowNumForValue(const StringTable *table, const int comparisonColumn1, const char *value1, const int comparisonColumn2, const char *value2, const int comparisonColumn3, const char *value3)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
StringTable_GetColumnValueForRow
==============
*/
const GfxViewParms *StringTable_GetColumnValueForRow(const StringTable *table, const int row, const int column)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
StringTable_Lookup
==============
*/
const GfxViewParms *StringTable_Lookup(const StringTable *table, const int comparisonColumn, const char *value, const int valueColumn)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
StringTable_Lookup
==============
*/
const GfxViewParms *StringTable_Lookup(const StringTable *table, const int comparisonColumn1, const char *value1, const int comparisonColumn2, const char *value2, const int valueColumn)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
StringTable_Lookup
==============
*/
const GfxViewParms *StringTable_Lookup(const StringTable *table, const int comparisonColumn1, const char *value1, const int comparisonColumn2, const char *value2, const int comparisonColumn3, const char *value3, const int valueColumn)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
StringTable_Find
==============
*/
int StringTable_Find(const StringTable *table, int *results, int maxResults, const int comparisonColumn1, const char *value1, const int comparisonColumn2, const char *value2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
StringTable_RowCount
==============
*/
int StringTable_RowCount(const StringTable *table)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
StringTable_Checksum
==============
*/
unsigned int StringTable_Checksum(const StringTable *table, unsigned int initialCrc)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
StringTable_GetAsset_FastFile
==============
*/
void StringTable_GetAsset_FastFile(const char *filename, const StringTable **tablePtr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
StringTable_GetAsset
==============
*/
void StringTable_GetAsset()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
StringTable_GetCoreAsset
==============
*/
void StringTable_GetCoreAsset(CoreStringTable id, const StringTable **tablePtr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
StringTable_FindCoreAssetIndex
==============
*/
int StringTable_FindCoreAssetIndex(const char *stringTableName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CellCompare
==============
*/
int CellCompare(const void *a, const void *b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
StringTable_ResortHashTable
==============
*/
void StringTable_ResortHashTable(StringTable *table)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetAssetFromScriptParam
==============
*/
bool Scr_GetAssetFromScriptParam(scriptInstance_t inst, const StringTable **tablePtr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_TableLookupFindCoreAsset
==============
*/
void Scr_TableLookupFindCoreAsset(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_TableLookupRowNum
==============
*/
void Scr_TableLookupRowNum(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_TableLookupColumnForRow
==============
*/
void Scr_TableLookupColumnForRow(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_TableLookup
==============
*/
void Scr_TableLookup(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_TableLookupIString
==============
*/
void Scr_TableLookupIString(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

