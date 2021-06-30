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

#ifndef COM_MEMORY_H
#define COM_MEMORY_H

typedef void* LPVOID;

struct __declspec(align(4)) fileData_s
{
	LPVOID data;
	fileData_s* next;
	unsigned __int8 type;
	char name[1];
};

extern fileData_s *com_fileDataHashTable[1024];

void TRACK_com_memory(void);
LPVOID Z_VirtualReserve(int);
int Z_TryVirtualCommitInternal(LPVOID, int);
void Z_VirtualCommitInternal(LPVOID, int);
void Com_AllMemInfo_f(void);
void Com_TouchMemory();
int Hunk_CheckTempMemoryClear();
int Hunk_CheckTempMemoryHighClear();
LPVOID Hunk_FindDataForFileInternal(int, char const*, int);
void Hunk_FindDataForFile(int type, const char* name);
bool Hunk_DataOnHunk(LPVOID data);
char* Hunk_SetDataForFile(int type, const char* name, LPVOID data, LPVOID(__cdecl* alloc)(int));
void Hunk_AddData(int type, LPVOID data, LPVOID(__cdecl* alloc)(int));
void Hunk_ClearDataFor(struct fileData_s** pFileData, unsigned char* low, unsigned char* high);
void Hunk_ClearData(void);
void Hunk_OverrideDataForFile(int type, const char* name, LPVOID data);
void DB_EnumXAssets_LoadObj(enum XAssetType type, void(__cdecl* func)(union XAssetHeader, LPVOID), LPVOID inData);
bool DB_EnumXAssetsTimeout_LoadObj(enum XAssetType type, void (*)(union XAssetHeader, LPVOID), LPVOID inData);
void Hunk_AddAsset(union XAssetHeader type, LPVOID data);
void DB_EnumXAssets();
bool DB_EnumXAssetsTimeout();
int Hunk_SetMark();
int Hunk_Used();
void Com_TempMeminfo_f(void);
void Z_VirtualCommit(LPVOID ptr, int size);
void Z_VirtualFree(LPVOID ptr);
void Z_VirtualDecommit(LPVOID ptr, int size);
void Z_Free(LPVOID ptr, int type);
LPVOID Z_Malloc(int size, const char* name, int type);
LPVOID Z_MallocGarbage(int size, const char* name, int type);
const char* CopyString(const char* in);
void FreeString(const char* str);
int DB_GetAllXAssetOfType_LoadObj(enum XAssetType type, union XAssetHeader* assets, int maxCount);
int DB_GetAllXAssetOfType();
void Hunk_ClearToMark(int mark);
void Hunk_ClearToMarkLow(int mark);
void Hunk_Clear();
LPVOID Hunk_AllocAlign(int size, int alignment, char const* name, int type);
unsigned int Hunk_AllocateTempMemoryHigh(int size, const char* name);
void Hunk_ClearTempMemoryHigh();
LPVOID Hunk_AllocLowAlign(int size, int alignment, char const* name, int type);
LPVOID Hunk_AllocateTempMemory(int size, const char* name);
void Hunk_FreeTempMemory(LPVOID buf);
void Hunk_ClearTempMemory();
LPVOID Z_TryVirtualAlloc(int size, const char* name, int type);
LPVOID Z_VirtualAlloc(int size, const char* name, int type);
void ReplaceString(const char** str, const char* in);
void Com_InitHunkMemory();
LPVOID Hunk_Alloc(int size, char const* name, int type);
LPVOID Hunk_AllocLow(int size, char const* name, int type);

#endif