#include "types.h"
#include "vars.h"
#include "universal_public.h"

#include <win32/win32_public.h>
#include <qcommon/qcommon_public.h>
#include <xanim/xanim_public.h>
#include <gfx_d3d/gfx_d3d_public.h>
#include <database/database_public.h>
#include <clientscript/clientscript_public.h>

unsigned char* s_hunkData;
unsigned char* s_origHunkData;
int s_hunkTotal;
hunkUsed_t hunk_high;
hunkUsed_t hunk_low;
fileData_s* com_hunkData;
fileData_s* com_fileDataHashTable[1024];

static cmd_function_s Com_AllMemInfo_f_VAR;
static cmd_function_s Com_TempMeminfo_f_VAR;

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
	assertMsg((size >= 0), "(size) = %i", size);
	return VirtualAlloc(ptr, size, (size > 0x20000 ? 0 : 0x100000) | 0x1000, 4) != NULL;
}

/*
==============
Com_AllMemInfo_f
==============
*/
void Com_AllMemInfo_f()
{
	track_PrintAllInfo();
}

/*
==============
Hunk_FindDataForFileInternal
==============
*/
void *Hunk_FindDataForFileInternal(int type, const char *name, int hash)
{
	fileData_s* searchFileData;

	for (searchFileData = com_fileDataHashTable[hash]; searchFileData; searchFileData = searchFileData->next)
	{
		if (searchFileData->type == type && !I_stricmp(searchFileData->name, name))
		{
			return searchFileData->data;
		}
	}
	return 0;
}

/*
==============
Hunk_ClearDataFor
==============
*/
void Hunk_ClearDataFor(fileData_s **pFileData, unsigned __int8 *low, unsigned __int8 *high)
{
	void* data;
	fileData_s* fileData;

	assert(Sys_IsMainThread());
	while (*pFileData)
	{
		fileData = *pFileData;
		if (*pFileData >= (fileData_s*)low && fileData < (fileData_s*)high)
		{
			*pFileData = fileData->next;
			data = fileData->data;

			switch (fileData->type)
			{
			case 2:
				XAnimFreeList((XAnim_s*)data);
				break;
			case 4:
				XModelPartsFree((XModelPartsLoad*)data);
				break;
			case 6:
				XAnimFree((XAnimParts*)data);
				break;
			}
		}
		else
		{
			pFileData = &fileData->next;
		}
	}
}

/*
==============
Hunk_ClearData
==============
*/
void Hunk_ClearData()
{
	unsigned char* low;
	unsigned int hash;
	unsigned char* high;

	assert(Sys_IsMainThread());
	low = &s_hunkData[hunk_low.permanent];
	high = &s_hunkData[s_hunkTotal - hunk_high.permanent];
	for (hash = 0; hash < 0x400; ++hash)
	{
		Hunk_ClearDataFor(com_fileDataHashTable + hash, low, high);
	}
	Hunk_ClearDataFor(&com_hunkData, low, high);
}

/*
==============
DB_EnumXAssets_LoadObj
==============
*/
void DB_EnumXAssets_LoadObj(XAssetType type, void (*func)(XAssetHeader, void *), void *inData, bool includeOverride)
{
	unsigned int hash;

	switch (type)
	{
	case 5:
		for (hash = 0; hash < 0x400; ++hash)
		{
			DB_EnumXAssetsFor(com_fileDataHashTable[hash], 5, func, inData);
		}
		break;
	case 6:
		R_EnumMaterials(func, inData);
		break;
	case 7:
		R_EnumTechniqueSets(func, inData);
		break;
	case 8:
		R_EnumImages(func, inData);
		break;
	}
}

/*
==============
DB_EnumXAssetsFor
==============
*/
void DB_EnumXAssetsFor(fileData_s* fileData, int fileDataType, void (*func)(XAssetHeader, void*), void* inData)
{
	while (fileData)
	{
		if (fileData->type == fileDataType && fileData->type == 5)
		{
			func(*(XAssetHeader*)fileData->data, inData);
		}
		fileData = fileData->next;
	}
}

/*
==============
DB_EnumXAssetsTimeout_LoadObj
==============
*/
char DB_EnumXAssetsTimeout_LoadObj(XAssetType type, void (*func)(XAssetHeader, void *), void *inData, bool includeOverride)
{
	DB_EnumXAssets_LoadObj(type, func, inData, includeOverride);
	return 1;
}

/*
==============
Hunk_AddAsset
==============
*/
void Hunk_AddAsset(XAssetHeader header, void *data)
{
	AssetList* assetList;

	assert(data);
	assetList = (AssetList*)data;

	assert(assetList->assetCount < assetList->maxCount);
	assetList->assets[assetList->assetCount++] = header;
}

/*
==============
DB_EnumXAssets
==============
*/
void DB_EnumXAssets(XAssetType type, void (*func)(XAssetHeader, void*), void* inData, bool includeOverride)
{
	if (IsFastFileLoad())
	{
		DB_EnumXAssets_FastFile(type, func, inData, includeOverride);
	}
	else
	{
		DB_EnumXAssets_LoadObj(type, func, inData, includeOverride);
	}
}

/*
==============
DB_EnumXAssetsTimeout
==============
*/
int DB_EnumXAssetsTimeout(XAssetType type, void (*func)(XAssetHeader, void*), void* inData, bool includeOverride, int msec)
{
	if (IsFastFileLoad())
	{
		return DB_EnumXAssetsTimeout_FastFile(type, func, inData, includeOverride, msec);
	}
	else
	{
		return DB_EnumXAssetsTimeout_LoadObj(type, func, inData, includeOverride);
	}
}

/*
==============
Com_TempMeminfo_f
==============
*/
void Com_TempMeminfo_f()
{
	assert(Sys_IsMainThread());
	Com_Printf(0, "Related commands: meminfo, imagelist, gfx_world, gfx_model, cg_drawfps, com_statmon, tempmeminfo\n");
}

/*
==============
DB_GetAllXAssetOfType_LoadObj
==============
*/
int DB_GetAllXAssetOfType_LoadObj(XAssetType type, XAssetHeader *assets, int maxCount)
{
	AssetList assetList;

	assetList.assets = assets;
	assetList.assetCount = 0;
	assetList.maxCount = maxCount;
	DB_EnumXAssets(type, Hunk_AddAsset, &assetList, 0);

	return assetList.assetCount;
}

/*
==============
DB_GetAllXAssetOfType
==============
*/
int DB_GetAllXAssetOfType(XAssetType type, XAssetHeader* assets, int maxCount)
{
	if (IsFastFileLoad())
	{
		return DB_GetAllXAssetOfType_FastFile(type, assets, maxCount);
	}

	return DB_GetAllXAssetOfType_LoadObj(type, assets, maxCount);
}

#define Hunk_CheckTempMemoryClear() assert(Sys_IsMainThread() || Sys_IsRenderThread()); \
									assert(s_hunkData); \
									assert(hunk_low.temp == hunk_low.permanent);
/*
==============
Hunk_AllocAlign
==============
*/
unsigned __int8 *Hunk_AllocAlign(int size, int alignment, const char *name, int type)
{
	int old_permanent;
	byte* buf;
	byte* endBuf;

	assert(Sys_IsMainThread() || Sys_IsRenderThread());
	assert(s_hunkData);
	assert(!(alignment & (alignment - 1)));
	assert(alignment <= HUNK_MAX_ALIGNMENT);

	alignment--;
	Hunk_CheckTempMemoryClear();
	old_permanent = hunk_high.permanent;
	endBuf = (byte*)((psize_int)&s_hunkData[s_hunkTotal - hunk_high.permanent] & ~4095);

	hunk_high.permanent += size;
	hunk_high.permanent = ~alignment & (alignment + hunk_high.permanent);
	hunk_high.temp = hunk_high.permanent;
	if (hunk_high.permanent + hunk_low.temp > s_hunkTotal)
	{
		track_PrintAllInfo();
		Com_Error(ERR_DROP, "Hunk_AllocAlign failed on %i bytes (total %i MB, low %i MB, high %i MB)",
			size, s_hunkTotal / 0x100000, hunk_low.temp / 0x100000, hunk_high.temp / 0x100000);
	}

	buf = &s_hunkData[s_hunkTotal - hunk_high.permanent];
	assert(!(((psize_int)buf) & alignment));

	if (endBuf != (byte*)((psize_int)buf & ~4095))
	{
		Z_VirtualCommit((void*)((psize_int)buf & ~4095), (int)&endBuf[-((psize_int)buf & ~4095)]);
	}

	track_hunk_alloc(hunk_high.permanent - old_permanent, hunk_high.temp, name, type);
	memset(buf, 0, size);

	return buf;
}

/*
==============
Hunk_AllocLowAlign
==============
*/
unsigned __int8 *Hunk_AllocLowAlign(int size, int alignment, const char *name, int type)
{
	int old_permanent;
	byte* buf;
	byte* beginBuf;

	assert(Sys_IsMainThread());
	assert(s_hunkData);
	assert(!(alignment & (alignment - 1)));
	assert(alignment <= HUNK_MAX_ALIGNMENT);

	alignment--;
	Hunk_CheckTempMemoryClear();
	old_permanent = hunk_low.permanent;
	beginBuf = (byte*)((psize_int)&s_hunkData[hunk_low.permanent + 4095] & ~4095);
	hunk_low.permanent = ~alignment & (alignment + hunk_low.permanent);
	buf = &s_hunkData[hunk_low.permanent];

	assert(!(((psize_int)buf) & alignment));
	hunk_low.permanent += size;
	hunk_low.temp = hunk_low.permanent;
	if (hunk_high.temp + hunk_low.permanent > s_hunkTotal)
	{
		track_PrintAllInfo();
		Com_Error(ERR_DROP, "Hunk_AllocLowAlign failed on %i bytes (total %i MB, low %i MB, high %i MB)",
			size, s_hunkTotal / 0x100000, hunk_low.temp / 0x100000, hunk_high.temp / 0x100000);
	}

	if ((byte*)((psize_int)&s_hunkData[hunk_low.permanent + 4095] & ~4095) != beginBuf)
	{
		Z_VirtualCommit(
			beginBuf,
			((psize_int)&s_hunkData[hunk_low.permanent + 4095] & ~4095) - (psize_int)beginBuf);
	}

	track_hunk_allocLow(hunk_low.permanent - old_permanent, hunk_low.permanent, name, type);
	memset(buf, 0, size);

	return buf;
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
	assert(Sys_IsMainThread());
	return Hunk_AllocLowAlign(size, 32, name, type);
}

/*
==============
Hunk_AllocateTempMemory
==============
*/
void* Hunk_AllocateTempMemory(int size, const char* name)
{
	hunkHeader_t* hdr;
	unsigned char* buf;
	int prev_temp;
	unsigned char* beginBuf;

	assert(Sys_IsMainThread() || Sys_IsRenderThread());

	if (!s_hunkData)
	{
		return Z_Malloc(size, name, 11);
	}

	assert(s_hunkData);
	size += 16;
	prev_temp = hunk_low.temp;
	beginBuf = (unsigned char*)((unsigned int)&s_hunkData[hunk_low.temp + 4095] & ~4095);
	hunk_low.temp = (hunk_low.temp + 15) & ~15;

	buf = &s_hunkData[hunk_low.temp];
	hunk_low.temp += size;

	if (hunk_high.temp + hunk_low.temp > s_hunkTotal)
	{
		track_PrintAllInfo();
		Com_Error(
			ERR_DROP,
			"\x15" "Hunk_AllocateTempMemory: failed on %i bytes (total %i MB, low %i MB, high %iMB), needs %i more hunk bytes",
			size,
			s_hunkTotal / 0x100000,
			hunk_low.temp / 0x100000,
			hunk_high.temp / 0x100000,
			hunk_high.temp + hunk_low.temp - s_hunkTotal);
	}

	hdr = (hunkHeader_t*)buf;
	buf = (buf + 16);
	assert(!(((psize_int)buf) & 15));

	if ((unsigned char*)((unsigned int)&s_hunkData[hunk_low.temp + 4095] & ~4095) != beginBuf)
	{
		Z_VirtualCommit(beginBuf, ((unsigned int)&s_hunkData[hunk_low.temp + 4095] & ~4095) - (DWORD)beginBuf);
	}

	hdr->magic = -1991018350;
	hdr->size = hunk_low.temp - prev_temp;
	track_temp_alloc(hdr->size, hunk_high.temp + hunk_low.temp, hunk_low.permanent, name);
	hdr->name = name;

	return (void*)buf;
}

/*
==============
Hunk_FreeTempMemory
==============
*/
void Hunk_FreeTempMemory(void* buf)
{
	hunkHeader_t* hdr;
	char* endBuf;
	char* beginBuf;

	assert(Sys_IsMainThread() || Sys_IsRenderThread());
	if (s_hunkData)
	{
		assert(s_hunkData);
		assert(buf);
		hdr = (hunkHeader_t*)((char*)buf - 16);
		if (*((DWORD*)buf - 4) != -1991018350)
		{
			Com_Error(ERR_FATAL, "\x15" "Hunk_FreeTempMemory: bad magic");
		}

		hdr->magic = -1991018349;
		assert(hdr == (void*)(s_hunkData + ((hunk_low.temp - hdr->size + 15) & ~15)));
		endBuf = (char*)((unsigned int)&s_hunkData[hunk_low.temp + 4095] & ~4095);
		hunk_low.temp -= hdr->size;

		track_temp_free(hdr->size, hunk_low.permanent, hdr->name);

		beginBuf = (char*)((unsigned int)&s_hunkData[hunk_low.temp + 4095] & ~4095);
		if (endBuf != beginBuf)
		{
			Z_VirtualDecommit(beginBuf, endBuf - beginBuf);
		}
	}
	else
	{
		Z_Free(buf, 11);
	}
}

/*
==============
Hunk_Clear
==============
*/
void Hunk_Clear()
{
	assert(Sys_IsMainThread());
	hunk_low.permanent = 0;
	hunk_low.temp = 0;
	hunk_high.permanent = 0;
	hunk_high.temp = 0;
	Hunk_ClearData();
	assertMsg(!((s_hunkTotal & 0x80000000) != 0), "((size >= 0))", "(size) = %i", s_hunkTotal);
	VirtualFree(s_hunkData, s_hunkTotal, 0x4000u);
	track_hunk_ClearToMarkLow(0);
	track_hunk_ClearToMarkHigh(0);
	track_hunk_ClearToStart();
	BB_ResetHighWaterMark("hunk_mem");
}

/*
==============
Hunk_ClearTempMemory
==============
*/
void Hunk_ClearTempMemory()
{
	unsigned char* endBuf;
	unsigned char* beginBuf;

	assert(Sys_IsMainThread());
	assert(s_hunkData);
	endBuf = (unsigned char*)((unsigned int)&s_hunkData[hunk_low.temp + 4095] & ~4095);
	hunk_low.temp = hunk_low.permanent;
	beginBuf = (unsigned char*)((unsigned int)&s_hunkData[hunk_low.permanent + 4095] & ~4095);

	if (endBuf != beginBuf)
	{
		Z_VirtualDecommit(beginBuf, endBuf - beginBuf);
	}
	track_temp_clear(hunk_low.permanent);
}

/*
==============
Hunk_ClearTempMemoryHigh
==============
*/
void Hunk_ClearTempMemoryHigh()
{
	int commitSize;
	unsigned char* beginBuf;

	assert(Sys_IsMainThread());
	beginBuf = (unsigned char*)((unsigned int)&s_hunkData[s_hunkTotal - hunk_high.temp] & ~4095);
	hunk_high.temp = hunk_high.permanent;
	commitSize = ((int)&s_hunkData[s_hunkTotal - hunk_high.permanent] & ~4095) - (int)beginBuf;

	if (commitSize)
	{
		Z_VirtualDecommit(beginBuf, commitSize);
	}
	track_temp_high_clear(hunk_high.permanent);
}

/*
==============
Com_InitHunkMemory
==============
*/
void Com_InitHunkMemory()
{
	assert(Sys_IsMainThread());
	assert(!s_hunkData);
	if (FS_LoadStack())
	{
		Com_Error(ERR_FATAL, "\x15", "Hunk initialization failed. File system load stack not zero\n");
	}
	if (!IsFastFileLoad())
	{
		s_hunkTotal = 167772160;
	}
	else
	{
		s_hunkTotal = 3145728;
		if (Com_SessionMode_IsZombiesGame())
		{
			s_hunkTotal = 15728640;
		}
	}
	s_hunkData = (unsigned char*)Z_VirtualReserve(s_hunkTotal);
	if (!s_hunkData)
	{
		Sys_OutOfMemErrorInternal(__FILE__, __LINE__);
	}
	s_origHunkData = s_hunkData;
	track_set_hunk_size(s_hunkTotal);
	track_physical_alloc(s_hunkTotal, "hunk", 1, 0);
	Hunk_Clear();
	Cmd_AddCommandInternal("meminfo", Com_AllMemInfo_f, &Com_AllMemInfo_f_VAR);
	Cmd_AddCommandInternal("tempmeminfo", Com_TempMeminfo_f, &Com_TempMeminfo_f_VAR);
}

/*
==============
Z_Malloc
==============
*/
void* Z_Malloc(int size, const char* name, int type)
{
	char* buf;

	buf = (char*)malloc(size + 164);
	if (!buf || (buf += 164, track_z_alloc(size + 72, name, type, buf, 0, 164), !buf))
	{
		Com_PrintError(10, "Failed to Z_Malloc %i bytes\n", size + 164);
		Sys_OutOfMemErrorInternal(__FILE__, __LINE__);
	}
	Com_Memset(buf, 0, size);
	return buf;
}

/*
==============
Z_Free
==============
*/
void Z_Free(void* ptr, int type)
{
	if (ptr)
	{
		track_z_free(type, ptr, 164);
		free((char*)ptr - 164);
	}
}

/*
==============
Z_VirtualFree
==============
*/
void Z_VirtualFree(void* ptr)
{
	VirtualFree(ptr, 0, 0x8000u);
}

/*
==============
CopyString
==============
*/
const char* CopyString(const char* string)
{
	return SL_ConvertToString(SL_GetString(string, 0, 22));
}

/*
==============
Z_VirtualDecommit
==============
*/
void Z_VirtualDecommit(void* ptr, int size)
{
	VirtualFree(ptr, size, 0x4000u);
}

/*
==============
FreeString
==============
*/
void FreeString(const char* str)
{
	unsigned int String;

	assert(str);
	String = SL_FindString(str);
	assert(String);
	SL_RemoveRefToString(String);
}

/*
==============
Z_VirtualAlloc
==============
*/
void* Z_VirtualAlloc(int size, const char* name, int type)
{
	void* buf;

	buf = Z_VirtualReserve(size);

	if (!buf)
	{
		Sys_OutOfMemErrorInternal(__FILE__, __LINE__);
	}
	if (Z_TryVirtualCommitInternal(buf, size))
	{
		VirtualFree(buf, 0, 0x8000u);
		Sys_OutOfMemErrorInternal(__FILE__, __LINE__);
	}
	track_z_commit((size + 4095) & 0xFFFFF000, type);
	return buf;
}

/*
==============
Z_VirtualCommit
==============
*/
void Z_VirtualCommit(void* ptr, int size)
{
	if (!VirtualAlloc(ptr, size, (size > 0x20000 ? 0 : 0x100000) | 0x1000, 4u))
		Sys_OutOfMemErrorInternal(__FILE__, __LINE__);
}

/*
==============
Z_VirtualReserve
==============
*/
void* Z_VirtualReserve(int size)
{
	void* alloc = VirtualAlloc(0, size, (size > 0x20000 ? 0 : 0x100000) | 0x2000, 4u);
	assert(alloc);
	return alloc;
}

