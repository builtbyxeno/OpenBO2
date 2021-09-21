#include "types.h"
#include "functions.h"

/*
==============
TRACK_com_memory
==============
*/
void TRACK_com_memory()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Z_TryVirtualCommitInternal
==============
*/
int Z_TryVirtualCommitInternal(void *ptr, int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_AllMemInfo_f
==============
*/
void __cdecl Com_AllMemInfo_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Hunk_FindDataForFileInternal
==============
*/
void *Hunk_FindDataForFileInternal(int type, const char *name, int hash)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Hunk_ClearDataFor
==============
*/
void Hunk_ClearDataFor(fileData_s **pFileData, unsigned __int8 *low, unsigned __int8 *high)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Hunk_ClearData
==============
*/
void Hunk_ClearData()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_EnumXAssets_LoadObj
==============
*/
void DB_EnumXAssets_LoadObj(XAssetType type, void (*func)(XAssetHeader, void *), void *inData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_EnumXAssetsTimeout_LoadObj
==============
*/
char DB_EnumXAssetsTimeout_LoadObj(XAssetType type, void (*func)(XAssetHeader, void *), void *inData)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Hunk_AddAsset
==============
*/
void Hunk_AddAsset(XAssetHeader header, void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_EnumXAssets
==============
*/
void DB_EnumXAssets()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_EnumXAssetsTimeout
==============
*/
int DB_EnumXAssetsTimeout()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_TempMeminfo_f
==============
*/
void Com_TempMeminfo_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_GetAllXAssetOfType_LoadObj
==============
*/
int DB_GetAllXAssetOfType_LoadObj(XAssetType type, XAssetHeader *assets, int maxCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_GetAllXAssetOfType
==============
*/
int DB_GetAllXAssetOfType()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Hunk_AllocAlign
==============
*/
unsigned __int8 *Hunk_AllocAlign(int size, int alignment, const char *name, int type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Hunk_AllocLowAlign
==============
*/
unsigned __int8 *Hunk_AllocLowAlign(int size, int alignment, const char *name, int type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Hunk_Alloc
==============
*/
unsigned __int8 *Hunk_Alloc(int size, const char *name, int type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Hunk_AllocLow
==============
*/
unsigned __int8 *Hunk_AllocLow(int size, const char *name, int type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

