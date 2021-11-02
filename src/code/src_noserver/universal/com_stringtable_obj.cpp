#include "types.h"

/*
==============
StringTable_HashString
==============
*/
int StringTable_HashString(const char *string)
{
    const char* v1 = string;

    if (!string)
        return 0;

    char v3 = *string;
    int v4 = 5381;

    if (*string)
    {
        do
        {
            ++v1;
            v4 = 33 * v4 + tolower(v3);
            v3 = *v1;
        } while (*v1);
    }

    return v4;
}

/*
==============
StringTable_Alloc
==============
*/
unsigned __int8 *StringTable_Alloc(int size)
{
    return Hunk_Alloc(size, "StringTable", 12);
}

/*
==============
StringTable_ParseFileIntoTable
==============
*/
void StringTable_ParseFileIntoTable(const char *filename, StringTable *table)
{
    UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
StringTable_GetAsset_LoadObj
==============
*/
void StringTable_GetAsset_LoadObj(const char *filename, const StringTable **tablePtr)
{
    const StringTable* DataForFile = (const StringTable*)Hunk_FindDataForFile(13, filename);

    if (DataForFile)
    {
        *tablePtr = DataForFile;
    }

    else
    {
        StringTable* v3 = (StringTable*)Hunk_Alloc(20, "StringTable", 12);
        v3->name = 0;
        v3->rowCount = 0;
        v3->cellIndex = 0;
        StringTable_ParseFileIntoTable(filename, v3);
        Hunk_SetDataForFile(13, filename, v3, StringTable_Alloc);
        *tablePtr = v3;
    }
}

