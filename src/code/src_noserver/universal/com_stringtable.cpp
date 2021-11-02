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
const char *StringTable_Lookup(const StringTable *table, const int comparisonColumn, const char *value, const int valueColumn)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
StringTable_Lookup
==============
*/
const char *StringTable_Lookup(const StringTable *table, const int comparisonColumn1, const char *value1, const int comparisonColumn2, const char *value2, const int valueColumn)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
StringTable_Lookup
==============
*/
const char *StringTable_Lookup(const StringTable *table, const int comparisonColumn1, const char *value1, const int comparisonColumn2, const char *value2, const int comparisonColumn3, const char *value3, const int valueColumn)
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
    void (*GetAsset)(void) = (void (*)(void))StringTable_GetAsset_FastFile;

    if (!Dvar_GetBool(useFastFile))
        GetAsset = (void (*)(void))StringTable_GetAsset_LoadObj;

    GetAsset();
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
    assert(s_sortTable != 0);

    const short cellIndexA = *(WORD*)a;
    const short cellIndexB = *(WORD*)b;

    assert(cellIndexA < (s_sortTable->rowCount * s_sortTable->columnCount));
    assert(cellIndexB < (s_sortTable->rowCount * s_sortTable->columnCount));

    const StringTableCell* values = s_sortTable->values;
    const int hash[2] = { values[cellIndexA].hash, values[cellIndexB].hash };

    if (hash[0] == hash[1])
        return cellIndexA % s_sortTable->columnCount - cellIndexB % s_sortTable->columnCount;

    return 2 * (hash >= hash[1]) - 1;
}

/*
==============
StringTable_ResortHashTable
==============
*/
void StringTable_ResortHashTable(StringTable *table)
{
    assert(s_sortTable == 0);

    int matrix = table->rowCount * table->columnCount;
    short *cellIndex = table->cellIndex;

    s_sortTable = table;

    qsort(cellIndex, table->rowCount * table->columnCount, CellCompare);

    matrix = table->rowCount * table->columnCount;
    int i = 0;
    s_sortTable = 0;
    signed int previousHash = INT_MAX + 1;

    if (matrix > 0)
    {
        do
        {
            assert(table->values[table->cellIndex[i]].hash >= previousHash);
            previousHash = table->values[table->cellIndex[i++]].hash;
        } while (i < matrix);
    }
}

/*
==============
Scr_GetAssetFromScriptParam
==============
*/
bool Scr_GetAssetFromScriptParam(scriptInstance_t inst, const StringTable **tablePtr)
{
    const int Type = Scr_GetType(inst, 0);

    if (Type == 7)
    {
        const CoreStringTable Int = Scr_GetInt(inst, 0);
        StringTable_GetCoreAsset(Int, tablePtr);

        return true;
    }

    else if (Type == 2)
    {
        void (*Get_Asset)(const char*, const StringTable**) = StringTable_GetAsset_FastFile;

        if (!Dvar_GetBool(useFastFile))
            GetAsset = StringTable_GetAsset_LoadObj;

        GetAsset(Scr_GetString(inst, 0), tablePtr);

        return true;
    }

    else
    {
        Com_Printf(10, "Invalid argument to stringtable lookup - either a filename or an ID\n");
        Scr_AddString(inst, "");

        return false;
    }
}

/*
==============
Scr_TableLookupFindCoreAsset
==============
*/
void Scr_TableLookupFindCoreAsset(scriptInstance_t inst)
{
    if (Dvar_GetBool(useFastFile))
    {
        const char* String = Scr_GetString(inst, 0);
        const int CoreAssetIndex = StringTable_FindCoreAssetIndex(String);

        if (CoreAssetIndex < 17)
            Scr_AddInt(inst, CoreAssetIndex);

        else
        {
            Scr_AddUndefined(inst);
            Com_PrintError(10, "Core stringtable asset %s not found\n", String);
        }
    }

    else
    {
        Com_Printf(10, "You cannot do table lookups without fastfiles.\n");
        Scr_AddUndefined(inst);
    }
}

/*
==============
Scr_TableLookupRowNum
==============
*/
void Scr_TableLookupRowNum(scriptInstance_t inst)
{
    const StringTable* tablePtr;

    if (Dvar_GetBool(useFastFile))
    {
        if (Scr_GetAssetFromScriptParam(inst, &tablePtr))
        {
            const int Int = Scr_GetInt(inst, 1u);
            const char* String = Scr_GetString(inst, 2u);
            Scr_AddInt(inst, StringTable_LookupRowNumForValue(tablePtr, Int, String));
        }
    }

    else
    {
        Com_Printf(10, "You cannot do table lookups without fastfiles.\n");
        Scr_AddString(inst, "");
    }
}

/*
==============
Scr_TableLookupColumnForRow
==============
*/
void Scr_TableLookupColumnForRow(scriptInstance_t inst)
{
    const char* string;
    const StringTable* tablePtr;

    if (Dvar_GetBool(useFastFile))
    {
        if (Scr_GetAssetFromScriptParam(inst, &tablePtr))
        {
            const int Int = Scr_GetInt(inst, 1u);
            const int v2 = Scr_GetInt(inst, 2u);
            const int columnCount = tablePtr->columnCount;

            if (v2 >= columnCount
                || Int >= tablePtr->rowCount
                || Int < 0
                || v2 < 0
                || (string = tablePtr->values[v2 + Int * columnCount].string) == 0)
                string = "";

            Scr_AddString(inst, string);
        }
    }

    else
    {
        Com_Printf(10, "You cannot do table lookups without fastfiles.\n");
        Scr_AddString(inst, "");
    }
}

/*
==============
Scr_TableLookup
==============
*/
void Scr_TableLookup(scriptInstance_t inst)
{
    const StringTable* tablePtr;
    int comparisonColumn2;
    const char* stringValue2;

    if (Dvar_GetBool(useFastFile))
    {
        if (Scr_GetAssetFromScriptParam(inst, &tablePtr))
        {
            const int Int = Scr_GetInt(inst, 1u);
            const char* String = Scr_GetString(inst, 2u);
            const unsigned int v3 = Scr_GetNumParam(inst) - 4;

            if (v3)
            {
                const unsigned int v4 = v3 - 2;

                if (v4)
                {
                    if (v4 == 2)
                    {
                        comparisonColumn2 = Scr_GetInt(inst, 3u);
                        stringValue2 = Scr_GetString(inst, 4u);
                        const int comparisonColumn3 = Scr_GetInt(inst, 5u);
                        const char* stringValue3 = Scr_GetString(inst, 6u);

                        Scr_AddString(inst, StringTable_Lookup(
                            tablePtr,
                            Int,
                            String,
                            comparisonColumn2,
                            stringValue2,
                            comparisonColumn3,
                            stringValue3,
                            Scr_GetInt(inst, 7u)));
                    }

                    else
                    {
                        const unsigned int NumParam = Scr_GetNumParam(inst);
                        Scr_Error(inst, va("Incorrect number of arguments (%d) passed to TableLookup!\n", NumParam), 0);
                        Scr_AddString(inst, "");
                    }
                }

                else
                {
                    comparisonColumn2 = Scr_GetInt(inst, 3u);
                    stringValue2 = Scr_GetString(inst, 4u);
                    Scr_AddString(inst, StringTable_Lookup(tablePtr, Int, String, comparisonColumn2, stringValue2, Scr_GetInt(inst, 5u)));
                }
            }

            else
            {
                Scr_AddString(inst, StringTable_Lookup(tablePtr, Int, String, Scr_GetInt(inst, 3u)));
            }
        }
    }

    else
    {
        Com_Printf(10, "You cannot do table lookups without fastfiles.\n");
        Scr_AddString(inst, "");
    }
}

/*
==============
Scr_TableLookupIString
==============
*/
void Scr_TableLookupIString(scriptInstance_t inst)
{
	if (Dvar_GetBool(useFastFile))
	{
		if (Scr_GetAssetFromScriptParam(inst, &tablePtr))
		{
			const int Int = Scr_GetInt(inst, 1u);
			const char* String = Scr_GetString(inst, 2u);
			const int v3 = Scr_GetInt(inst, 3u);
			const char* v4 = StringTable_Lookup(tablePtr, Int, String, v3);
			Scr_AddIString(inst, v4);
		}
	}

	else
	{
		Com_Printf(10, "You cannot do table lookups without fastfiles.\n");
		Scr_AddIString(inst, "");
	}
}

