/*
 * Copyright (c) 2020-2021 OpenIW
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "com_memory.h"
#include <universal/q_shared.h>
#include <win32/win_shared.h>

typedef struct hunkUsed_t
{
	int permanent;
	int temp;
} hunkUsed_t;

hunkUsed_t hunk_low, hunk_high;

static SIZE_T s_hunkTotal;
static unsigned __int8* s_hunkData;

void TRACK_com_memory(void)
{
}

LPVOID Z_VirtualReserve(int size)
{
	return VirtualAlloc(0, size, (size > 0x20000 ? 0 : 0x100000) | 0x2000, 4u);
}

int Z_TryVirtualCommitInternal(LPVOID ptr, int size)
{
	return VirtualAlloc(ptr, size, (size > 0x20000 ? 0 : 0x100000) | 0x1000, 4u) != 0;
}

void Z_VirtualCommitInternal(LPVOID ptr, int size)
{
	if (!VirtualAlloc(ptr, size, (size > 0x20000 ? 0 : 0x100000) | 0x1000, 4u))
	{
		//Sys_OutOfMemErrorInternal(__FILE__, __LINE__);
	}
}

void Com_AllMemInfo_f(void)
{
}

void Com_TouchMemory()
{
	int start, end;
	int i, j;
	int sum;

	start = Sys_Milliseconds();

	sum = 0;

	j = hunk_low.permanent >> 2;
	for (i = 0; i < j; i += 64)         // only need to touch each page
	{
		sum += ((int*)s_hunkData)[i];
	}

	i = (s_hunkTotal - hunk_high.permanent) >> 2;
	j = hunk_high.permanent >> 2;
	for (; i < j; i += 64)         // only need to touch each page
	{
		sum += ((int*)s_hunkData)[i];
	}

	end = Sys_Milliseconds();

	Com_Printf(CON_CHANNEL_SYSTEM, "Com_TouchMemory: %i msec. Using sum: %d\n", end - start, sum);
}

int Hunk_CheckTempMemoryClear()
{
	if (hunk_low.temp != hunk_low.permanent)
		return 0;
	return 1;
}

int Hunk_CheckTempMemoryHighClear()
{
	if (hunk_high.temp != hunk_high.permanent)
		return 0;
	return 1;
}

LPVOID Hunk_FindDataForFileInternal(int type, char const* name, int hash)
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

void Hunk_FindDataForFile(int type, const char* name)
{
}

bool Hunk_DataOnHunk(LPVOID data)
{
	return false;
}

char* Hunk_SetDataForFile(int type, const char* name, LPVOID data, LPVOID(__cdecl* alloc)(int))
{
	return nullptr;
}

void Hunk_AddData(int type, LPVOID data, LPVOID(__cdecl* alloc)(int))
{
}

void Hunk_ClearDataFor(fileData_s** pFileData, unsigned char* low, unsigned char* high)
{
}

void Hunk_ClearData(void)
{
}

void Hunk_OverrideDataForFile(int type, const char* name, LPVOID data)
{
}

void Hunk_AddAsset(XAssetHeader type, LPVOID data)
{
}

void DB_EnumXAssets()
{
}

bool DB_EnumXAssetsTimeout()
{
	return false;
}

int Hunk_SetMark()
{
	return 0;
}

int Hunk_Used()
{
	return 0;
}

void Com_TempMeminfo_f(void)
{
}

void Z_VirtualCommit(LPVOID ptr, int size)
{
}

void Z_VirtualFree(LPVOID ptr)
{
}

void Z_VirtualDecommit(LPVOID ptr, int size)
{
}

void Z_Free(LPVOID ptr, int type)
{
}

LPVOID Z_Malloc(int size, const char* name, int type)
{
	return LPVOID();
}

LPVOID Z_MallocGarbage(int size, const char* name, int type)
{
	return LPVOID();
}

const char* CopyString(const char* in)
{
	return nullptr;
}

void FreeString(const char* str)
{
}

int DB_GetAllXAssetOfType()
{
	return 0;
}

void Hunk_ClearToMark(int mark)
{
}

void Hunk_ClearToMarkLow(int mark)
{
}

void Hunk_Clear()
{
}

LPVOID Hunk_AllocAlign(int size, int alignment, char const* name, int type)
{
	return LPVOID();
}

unsigned int Hunk_AllocateTempMemoryHigh(int size, const char* name)
{
	return 0;
}

void Hunk_ClearTempMemoryHigh()
{
}

LPVOID Hunk_AllocLowAlign(int size, int alignment, char const* name, int type)
{
	return LPVOID();
}

LPVOID Hunk_AllocateTempMemory(int size, const char* name)
{
	return LPVOID();
}

void Hunk_FreeTempMemory(LPVOID buf)
{
}

void Hunk_ClearTempMemory()
{
}

LPVOID Z_TryVirtualAlloc(int size, const char* name, int type)
{
	return LPVOID();
}

LPVOID Z_VirtualAlloc(int size, const char* name, int type)
{
	return LPVOID();
}

void ReplaceString(const char** str, const char* in)
{
}

void Com_InitHunkMemory()
{
}

LPVOID Hunk_Alloc(int size, char const* name, int type)
{
	return LPVOID();
}

LPVOID Hunk_AllocLow(int size, char const* name, int type)
{
	return LPVOID();
}

int DB_GetAllXAssetOfType_LoadObj(XAssetType type, XAssetHeader* assets, int maxCount)
{
	return 0;
}

bool DB_EnumXAssetsTimeout_LoadObj(XAssetType type, void(*)(XAssetHeader, LPVOID), LPVOID inData)
{
	return false;
}

void DB_EnumXAssets_LoadObj(XAssetType type, void(__cdecl* func)(XAssetHeader, LPVOID), LPVOID inData)
{
}
