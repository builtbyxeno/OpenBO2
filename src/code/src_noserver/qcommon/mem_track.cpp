#include "types.h"
#include "vars.h"
#include <qcommon/qcommon_public.h>
#include <clientscript/clientscript_public.h>
#include <xanim/xanim_public.h>
#include <server_mp/server_mp_public.h>
#include <effectscore/effectscore_public.h>
#include <win32/win32_public.h>
#include <win32/win32_public.h>
#include <game/game_public.h>
#include <devgui/devgui_public.h>
#include <database/database_public.h>
#include <dynentity/dynentity_public.h>
#include <ragdoll/ragdoll_public.h>
#include <cgame/cgame_public.h>
#include <ui/ui_public.h>
#include <gfx_d3d/gfx_d3d_public.h>
#include <flame/flame_public.h>
#include <zlib/zutil.h>
#include <client/client_public.h>

#define MAX_MEM_TRACK 2048
#define MAX_TEMPMEM_INFO 1500
#define MAX_USERHUNK_TRACK 256
#define MAX_HUNK_TRACK 524288
#define MAX_LOWHUNK_TRACK 65536
#define MEM_TRACK_HEADER_SIZE 164

int g_staticsMemTrackCount;
int g_physicalMemInfoCount;
mem_track_t g_staticsMemTrack[MAX_MEM_TRACK];
TempMemInfo g_physicalMemInfoArray[MAX_TEMPMEM_INFO];
const char* g_mem_track_filename;
meminfo_t g_info;

int g_mallocMemInfoCount;
mem_track_node_s* g_ZMallocMemTrackList;
TempMemInfo g_mallocMemInfoArray[MAX_TEMPMEM_INFO];
int g_malloc_mem_size;
int g_malloc_mem_high;

meminfo_t g_virtualMemInfo;

TempMemInfo g_tempMemInfoArray[MAX_TEMPMEM_INFO];
int g_tempMemInfoCount;

TempMemInfo g_tempHighMemInfoArray[MAX_TEMPMEM_INFO];
int g_tempHighMemInfoCount;

mem_track_t g_userhunk_track[MAX_USERHUNK_TRACK];
int g_userhunk_track_count;

mem_track_t g_hunk_track[MAX_HUNK_TRACK];
int g_hunk_track_count;

mem_track_t g_hunklow_track[MAX_LOWHUNK_TRACK];
int g_hunklow_track_count;

const char* projName[4] = { "exe", "cgame", "game", "renderer" };

static bool inited_0;

/*
==============
track_addbasicmeminfo
==============
*/
void track_addbasicmeminfo(meminfo_t *sum, meminfo_t *in)
{
	int j;
	int type;

	for (j = 0; j < 2; ++j)
	{
		for (type = 0; type < 54; ++type)
		{
			sum->typeTotal[type][j] += in->typeTotal[type][j];
		}
		sum->total[j] += in->total[j];
	}
	sum->nonSwapTotal += in->nonSwapTotal;
	sum->nonSwapMinSpecTotal += in->nonSwapMinSpecTotal;
}

inline void track_addbasicinfo(meminfo_t* info, int type, int location, int size)
{
	info->typeTotal[type][location] += size;
	info->total[location] += size;
	switch (type)
	{
	case 0:
	case 1:
	case 3:
	case 39:
	case 55:
		break;
	default:
		g_info.nonSwapTotal += size;
		g_info.nonSwapMinSpecTotal += size;
		break;
	}
}

/*
==============
track_static_alloc_internal_simple
==============
*/
void track_static_alloc_internal_simple(void *ptr, int size, const char *name, int memTrack)
{
	mem_track_t* mem_track;

	track_init();
	assert(g_staticsMemTrackCount < MAX_MEM_TRACK);
	assert(size > 0);
	mem_track = &g_staticsMemTrack[g_staticsMemTrackCount];
	mem_track->size[0] = size;
	assert(name[0]);
	strcpy(mem_track->name, name);
	mem_track->usageType = 0;
	mem_track->type = memTrack;
	mem_track->filename = g_mem_track_filename;
	track_addbasicinfo(&g_info, memTrack, 0, size);
	++g_staticsMemTrackCount;
}

/*
==============
GetTempMemInfo
==============
*/
TempMemInfo *GetTempMemInfo(int permanent, const char *name, int type, int usageType, TempMemInfo *tempMemInfoArray, int *tempMemInfoCount, bool add_if_missing)
{
	TempMemInfo foundTempMemInfo;
	int i;
	TempMemInfo* tempMemInfo;
	int count;

	count = *tempMemInfoCount;
	i = 0;
	tempMemInfo = tempMemInfoArray;
	for (i = 0; i < count; ++i, ++tempMemInfo)
	{
		tempMemInfo = &tempMemInfoArray[i];
		if ((!name || !_stricmp(tempMemInfo->data.name, name))
			&& tempMemInfo->permanent == permanent
			&& (unsigned char)tempMemInfo->data.usageType == usageType)
		{
			if (!i)
			{
				return tempMemInfo;
			}

			memcpy(&foundTempMemInfo, tempMemInfo, sizeof(foundTempMemInfo));
			for  (; i > 0; --i)
			{
				memcpy(&tempMemInfoArray[i], &tempMemInfoArray[i - 1], sizeof(TempMemInfo));
			}

			memcpy(tempMemInfoArray, &foundTempMemInfo, sizeof(TempMemInfo));
			return tempMemInfoArray;
		}
	}

	if (!add_if_missing)
	{
		return 0;
	}

	assert(name);
	++* tempMemInfoCount;
	assertMsg(((*tempMemInfoCount) < 1500), "(*tempMemInfoCount) = %i", *tempMemInfoCount);
	tempMemInfo->permanent = permanent;
	strcpy(tempMemInfo->data.name, name);
	tempMemInfo->data.type = type;
	tempMemInfo->data.usageType = usageType;
	tempMemInfo->data.size[0] = 0;
	tempMemInfo->data.size[1] = 0;
	tempMemInfo->data.filename = "";
	tempMemInfo->data.count = 0;
	tempMemInfo->high = 0;
	tempMemInfo->low = 0;
	tempMemInfo->hunkSize = 0;
	tempMemInfo->highExtra = 0;

	memcpy(&foundTempMemInfo, tempMemInfo, sizeof(foundTempMemInfo));
	for (; i > 0; --i)
	{
		memcpy(&tempMemInfoArray[i], &tempMemInfoArray[i - 1], sizeof(TempMemInfo));
	}

	memcpy(tempMemInfoArray, &foundTempMemInfo, sizeof(TempMemInfo));
	return tempMemInfoArray;
}

/*
==============
track_flush_physical_alloc
==============
*/
void track_flush_physical_alloc(const char *name, int type)
{
	char test_name[128];
	TempMemInfo* mainTempMemInfo;
	TempMemInfo* tempMemInfo;
	int i, j, k, test_nameLen;
	int* size;

	sprintf(test_name, "%s::", name);
	test_nameLen = strlen(test_name);
	mainTempMemInfo = GetTempMemInfo(0, name, type, 7, g_physicalMemInfoArray, &g_physicalMemInfoCount, 0);
	for (i = 0; i < g_physicalMemInfoCount; ++i, ++tempMemInfo)
	{
		tempMemInfo = &g_physicalMemInfoArray[i];
		if (!I_strnicmp(tempMemInfo->data.name, test_name, test_nameLen))
		{
			if (mainTempMemInfo)
			{
				for (j = 0; j < 2; ++j)
				{
					mainTempMemInfo->data.size[j] += tempMemInfo->data.size[j];
				}
			}
			for (k = 0; k < 2; ++k)
			{
				tempMemInfo->data.size[k] = 0;
			}
		}
	}
}

/*
==============
CheckHighMemInfo
==============
*/
inline void CheckHighMemInfo(TempMemInfo* tempMemInfo, int hunkSize, int location)
{
	int size;

	size = tempMemInfo->data.size[location];
	if (tempMemInfo->high < size)
	{
		tempMemInfo->high = size;
	}
	if (tempMemInfo->hunkSize < hunkSize)
	{
		tempMemInfo->hunkSize = hunkSize;
		tempMemInfo->highExtra = size;
	}
}

/*
==============
AddTempMemInfo
==============
*/
inline void AddTempMemInfo(int size, int hunkSize, int permanent, const char* name, int type, int location, int usageType, TempMemInfo* tempMemInfoArray, int* tempMemInfoCount)
{
	TempMemInfo* tempMemInfo;

	tempMemInfo = GetTempMemInfo(permanent, name, type, usageType, tempMemInfoArray, tempMemInfoCount, 1);
	tempMemInfo->data.size[location] += size;
	++tempMemInfo->data.count;
	CheckHighMemInfo(tempMemInfo, hunkSize, location);
}

/*
==============
track_z_alloc
==============
*/
void track_z_alloc(int size, const char *name, int type, void *pos, int project, int overhead)
{
	mem_track_node_s* node;

	assert(size >= 0);
	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	g_staticsMemTrack[0].size[0] += overhead;
	g_info.typeTotal[0][0] += overhead;
	g_info.total[0] += overhead;
	if (type != 55)
	{
		AddTempMemInfo(size, 0, 0, name, type, 0, 2, g_mallocMemInfoArray, &g_mallocMemInfoCount);
		g_malloc_mem_size += size;
		if (g_malloc_mem_high < g_malloc_mem_size)
		{
			g_malloc_mem_high = g_malloc_mem_size;
		}
	}
	// Subtract the start of the data to the mem_track_node_s start
	node = (mem_track_node_s*)((char*)pos - MEM_TRACK_HEADER_SIZE);
	assert(name[0]);
	strcpy(node->data.name, name);
	node->data.filename = "";
	node->data.size[0] = size;
	node->data.size[1] = 0;
	node->data.type = type;
	node->data.usageType = 2;
	node->next = g_ZMallocMemTrackList;
	node->prev = NULL;
	node->project = project;
	if (g_ZMallocMemTrackList)
	{
		g_ZMallocMemTrackList->prev = node;
	}
	g_ZMallocMemTrackList = node;
	track_addbasicinfo(&g_info, type, 0, size);
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
CheckLowMemInfo
==============
*/
inline void CheckLowMemInfo(TempMemInfo* tempMemInfo, int location)
{
	if (tempMemInfo->low > tempMemInfo->data.size[location])
	{
		tempMemInfo->low = tempMemInfo->data.size[location];
	}
}

/*
==============
RemoveTempMemInfo
==============
*/
inline void RemoveTempMemInfo(int size, int permanent, const char* name, int type, int location, int usageType, TempMemInfo* tempMemInfoArray, int* tempMemInfoCount)
{
	TempMemInfo* tempMemInfo;

	tempMemInfo = GetTempMemInfo(permanent, name, type, usageType, tempMemInfoArray, tempMemInfoCount, 0);
	if (tempMemInfo)
	{
		tempMemInfo->data.size[location] -= size;
		--tempMemInfo->data.count;
		CheckLowMemInfo(tempMemInfo, location);
	}
}

/*
==============
track_z_free
==============
*/
void track_z_free(int type, void *pos, int overhead)
{
	mem_track_node_s* node;

	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	node = (mem_track_node_s*)((char*)pos - MEM_TRACK_HEADER_SIZE);

	g_staticsMemTrack[0].size[0] -= overhead;
	track_addbasicinfo(&g_info, 0, 0, -overhead);
	if (type != 55)
	{
		g_malloc_mem_size -= node->data.size[0];
		if (g_malloc_mem_size < 0)
		{
			g_malloc_mem_size = 0;
		}
		RemoveTempMemInfo(node->data.size[0], 0, node->data.name, type, 0, 2, g_mallocMemInfoArray, &g_mallocMemInfoCount);
	}

	track_addbasicinfo(&g_info, type, 0, -node->data.size[0]);
	if (node == g_ZMallocMemTrackList)
	{
		g_ZMallocMemTrackList = node->next;
		if (g_ZMallocMemTrackList)
		{
			g_ZMallocMemTrackList->prev = NULL;
		}
	}
	else
	{
		assert(node->prev);
		node->prev->next = node->next;
		if (node->next)
		{
			node->next->prev = node->prev;
		}
	}
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
track_z_commit
==============
*/
void track_z_commit(int size, int type)
{
	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	track_addbasicinfo(&g_virtualMemInfo, type, 0, size);
	track_addbasicinfo(&g_info, type, 0, size);
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
track_temp_alloc
==============
*/
void track_temp_alloc(int size, int hunkSize, int permanent, const char *name)
{
	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	AddTempMemInfo(size, hunkSize, permanent, name, 11, 0, 6, g_tempMemInfoArray, &g_tempMemInfoCount);
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
track_temp_free
==============
*/
void track_temp_free(int size, int permanent, const char *name)
{
	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	RemoveTempMemInfo(size, permanent, name, 11, 0, 6, g_tempMemInfoArray, &g_tempMemInfoCount);
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
track_temp_clear
==============
*/
void track_temp_clear(int permanent)
{
	int i;

	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	for (i = 0; i < g_tempMemInfoCount; ++i)
	{
		if (g_tempMemInfoArray[i].permanent == permanent)
		{
			g_tempMemInfoArray[i].data.size[0] = 0;
		}
	}
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
track_temp_high_alloc
==============
*/
void track_temp_high_alloc(int size, int hunkSize, int permanent, const char *name)
{
	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	AddTempMemInfo(size, hunkSize, permanent, name, 11, 0, 6, g_tempHighMemInfoArray, &g_tempHighMemInfoCount);
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
track_temp_high_clear
==============
*/
void track_temp_high_clear(int permanent)
{
	int i;

	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	for (i = 0; i < g_tempHighMemInfoCount; ++i)
	{
		if (g_tempHighMemInfoArray[i].permanent == permanent)
		{
			g_tempHighMemInfoArray[i].data.size[0] = 0;
		}
	}
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
track_userhunk_freerange
==============
*/
void track_userhunk_freerange(void *low, unsigned int size)
{
	int i;

	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	for (i = 0; i < g_userhunk_track_count; ++i)
	{
		if (g_userhunk_track[i].pos >= (int)low && g_userhunk_track[i].pos < (int)((int)low + size))
		{
			memcpy(&g_userhunk_track[i], &g_userhunk_track[g_userhunk_track_count - 1], sizeof(mem_track_t));
			memset(g_userhunk_track[g_userhunk_track_count - 1].name, 0, 0x98u);
			--g_userhunk_track_count;
			--i;
		}
	}
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
track_userhunk_free
==============
*/
void track_userhunk_free(void *ptr)
{
	int i;

	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	for (i = 0; i < g_userhunk_track_count; ++i)
	{
		if ((void*)g_userhunk_track[i].pos == ptr)
		{
			if (i != g_userhunk_track_count - 1)
			{
				memcpy(&g_userhunk_track[i], &g_userhunk_track[g_userhunk_track_count - 1], sizeof(mem_track_t));
			}
			break;
		}
	}
	g_userhunk_track_count--;
	assert(g_userhunk_track_count >= 0);
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
track_userhunk_alloc
==============
*/
void track_userhunk_alloc(int size, int pos, const char *name, int type)
{
	mem_track_t* mem_track;

	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	assert(g_userhunk_track_count < MAX_USERHUNK_TRACK);
	mem_track = &g_userhunk_track[g_userhunk_track_count];
	mem_track->size[0] = size;

	assert(name[0]);
	strcpy(mem_track->name, name);
	mem_track->type = type;
	mem_track->usageType = 8;
	mem_track->filename = "";
	mem_track->pos = pos;
	track_addbasicinfo(&g_info, type, 0, size);
	++g_userhunk_track_count;
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
track_hunk_alloc
==============
*/
void track_hunk_alloc(int size, int pos, const char *name, int type)
{
	mem_track_t* mem_track;

	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	g_staticsMemTrack[1].size[0] -= size;
	track_addbasicinfo(&g_info, 1, 0, -size);
	//assert(g_hunk_track_count < MAX_HUNK_TRACK);
	mem_track = &g_hunk_track[g_hunk_track_count];
	mem_track->size[0] = size;

	assert(name[0]);
	strcpy(mem_track->name, name);
	mem_track->type = type;
	mem_track->usageType = 3;
	mem_track->filename = "";
	mem_track->pos = pos;
	track_addbasicinfo(&g_info, type, 0, size);
	++g_hunk_track_count;
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
track_hunk_allocLow
==============
*/
void track_hunk_allocLow(int size, int pos, const char *name, int type)
{
	mem_track_t* mem_track;

	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	g_staticsMemTrack[1].size[0] -= size;
	track_addbasicinfo(&g_info, 1, 0, -size);
	//assert(g_staticsMemTrack[TRACK_HUNK].size[TRACK_LOCATION_MRAM] >= 0);
	//assert(g_hunklow_track_count < MAX_HUNKLOW_TRACK);
	mem_track = &g_hunklow_track[g_hunklow_track_count];
	mem_track->size[0] = size;

	assert(name[0]);
	strcpy(mem_track->name, name);
	mem_track->type = type;
	mem_track->usageType = 3;
	mem_track->filename = "";
	mem_track->pos = pos;
	track_addbasicinfo(&g_info, type, 0, size);
	++g_hunklow_track_count;
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
track_set_hunk_size
==============
*/
void track_set_hunk_size(int size)
{
	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	g_staticsMemTrack[1].size[0] = size;
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
track_hunk_ClearToMarkHigh
==============
*/
void track_hunk_ClearToMarkHigh(int mark)
{
	int size;
	mem_track_t* info;

	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	while (g_hunk_track_count)
	{
		info = &g_hunk_track[g_hunk_track_count - 1];
		if (info->pos <= mark)
		{
			break;
		}
		--g_hunk_track_count;
		size = info->size[0];
		track_addbasicinfo(&g_info, info->type, 0, -size);
		track_addbasicinfo(&g_info, 1, 0, size);
		g_staticsMemTrack[1].size[0] += size;
	}
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
track_hunk_ClearToMarkLow
==============
*/
void track_hunk_ClearToMarkLow(int mark)
{
	int size;
	mem_track_t* info;

	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	while (g_hunklow_track_count)
	{
		info = &g_hunklow_track[g_hunklow_track_count - 1];
		if (info->pos <= mark)
		{
			break;
		}
		--g_hunklow_track_count;
		size = info->size[0];
		track_addbasicinfo(&g_info, info->type, 0, -size);
		track_addbasicinfo(&g_info, 1, 0, size);
		g_staticsMemTrack[1].size[0] += size;
	}
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
track_hunk_ClearToStart
==============
*/
void track_hunk_ClearToStart()
{
	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	g_tempMemInfoCount = 0;
	g_tempHighMemInfoCount = 0;
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
mem_track_compare
==============
*/
int mem_track_compare(const void *elem1, const void *elem2)
{
	mem_track_node_s* elem1Header;
	mem_track_node_s* elem2Header;
	int* size;
	int i;

	elem1Header = (mem_track_node_s*)((char*)elem1 - MEM_TRACK_HEADER_SIZE);
	elem2Header = (mem_track_node_s*)((char*)elem2 - MEM_TRACK_HEADER_SIZE);
	size = elem1Header->data.size;

	for (i = 0; i < 2; ++i)
	{
		if (size[i] != (size[i] + elem2Header->data.size[i] - elem2Header->data.size[i]))
			return elem1Header->data.size[i] - elem2Header->data.size[i];
	}
	if (elem1Header->data.type < elem2Header->data.type)
		return -1;
	if (elem1Header->data.type > elem2Header->data.type)
		return 1;
	if (elem1Header->data.usageType < elem2Header->data.usageType)
		return -1;
	if (elem1Header->data.usageType > elem2Header->data.usageType)
		return 1;
	else
		return strcmp(elem1Header->data.name, elem2Header->data.name);
}

/*
==============
track_getbasicinfo
==============
*/
void track_getbasicinfo(meminfo_t *info)
{
	assert(info);
	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	memset(info, 0, sizeof(meminfo_t));
	track_addbasicmeminfo(info, &g_info);
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
track_printf
==============
*/
void track_printf(const char *fmt, ...)
{
	char string[4096];
	va_list ap;

	va_start(ap, fmt);
	_vsnprintf(string, 0x1000u, fmt, ap);
	string[4095] = 0;
	Com_PrintMessage(0, string, 0);
}

/*
==============
track_shutdown
==============
*/
void track_shutdown(int project)
{
	mem_track_node_s* node;
	int leak_size;

	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	leak_size = 0;
	for (node = g_ZMallocMemTrackList; node; node = node->next)
	{
		if (node->project == project && !project && !I_stricmp(node->data.name, "MSS_MallocCallback"))
		{
			leak_size += node->data.size[0];
			track_printf("Error: memory leak of '%s' in %s", node, projName[0]);
		}
	}
	if (leak_size)
	{
		assertMsg(va("Total memory leak in '%s': %d", projName[project], leak_size));
	}
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
track_static_alloc_internal
==============
*/
void track_static_alloc_internal(void* ptr, int size, const char* name, int type)
{
	Sys_InitializeCriticalSections();
	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	track_static_alloc_internal_simple(ptr, size, name, type);
	Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

/*
==============
TRACK_memtrack
==============
*/
void TRACK_memtrack()
{
	track_static_alloc_internal(g_staticsMemTrack, 311296, "g_staticsMemTrack", 0);
	track_static_alloc_internal(g_userhunk_track, 38912, "g_userhunk_track", 0);
	track_static_alloc_internal(g_mallocMemInfoArray, 258000, "g_mallocMemInfoArray", 0);
	track_static_alloc_internal(g_hunk_track, 79691776, "g_hunk_track", 0);
	track_static_alloc_internal(g_hunklow_track, 9961472, "g_hunklow_track", 0);
	track_static_alloc_internal(g_tempMemInfoArray, 258000, "g_tempMemInfoArray", 0);
	track_static_alloc_internal(g_tempHighMemInfoArray, 258000, "g_tempHighMemInfoArray", 0);
	track_static_alloc_internal(g_physicalMemInfoArray, 258000, "g_physicalMemInfoArray", 0);
	g_mem_track_filename = "";
}

/*
==============
track_init
==============
*/
void track_init()
{
	int i, j;

	Sys_InitializeCriticalSections();
	Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
	if (inited_0)
	{
		Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
	}
	else
	{
		inited_0 = true;
		memset(&g_info, 0, sizeof(g_info));
		memset(&g_virtualMemInfo, 0, sizeof(g_virtualMemInfo));
		for (i = 0; i < 58; ++i)
		{
			g_staticsMemTrack[i].size[0] = 0;
			g_staticsMemTrack[i].size[1] = 0;
			strcpy(g_staticsMemTrack[i].name, "internal");
			g_staticsMemTrack[i].type = 0;
			g_staticsMemTrack[i].usageType = 4;
			g_staticsMemTrack[i].filename = "";
		}
		g_staticsMemTrackCount = i;
		strcpy(g_staticsMemTrack[1].name, "(hunk memory)");
		strcpy(g_staticsMemTrack[25].name, "(agp memory)");
		g_userhunk_track_count = 0;
		g_hunk_track_count = 0;
		g_hunklow_track_count = 0;
#if XENON
		g_mem_track_filename = "xenon_remote";
		TRACK_xenon_remote();
#endif
		g_mem_track_filename = "scr_memorytree";
		TRACK_scr_memorytree();
		g_mem_track_filename = "scr_debugger";
		TRACK_scr_debugger();
		g_mem_track_filename = "scr_evaluate";
		TRACK_scr_evaluate();
		g_mem_track_filename = "scr_variable";
		TRACK_scr_variable();
		g_mem_track_filename = "scr_compiler";
		TRACK_scr_compiler();
		g_mem_track_filename = "scr_parser";
		TRACK_scr_parser();
		g_mem_track_filename = "scr_animtree";
		TRACK_scr_animtree();
		g_mem_track_filename = "scr_stringlist";
		TRACK_scr_stringlist();
		g_mem_track_filename = "scr_vm";
		TRACK_scr_vm();
		g_mem_track_filename = "net_chan";
		TRACK_net_chan();
		g_mem_track_filename = "xmodel";
		TRACK_xmodel();
		g_mem_track_filename = "sv_main";
		TRACK_sv_main();
		g_mem_track_filename = "cm_load";
		TRACK_cm_load();
		g_mem_track_filename = "cm_showcollision";
		TRACK_cm_showcollision();
		g_mem_track_filename = "cm_world";
		TRACK_cm_world();
		g_mem_track_filename = "cmd";
		TRACK_cmd();
		g_mem_track_filename = "com_files";
		TRACK_com_files();
		g_mem_track_filename = "com_math";
		TRACK_com_math();
		g_mem_track_filename = "fx_draw";
		BG_EvalVehicleName();
		g_mem_track_filename = "fx_random";
		TRACK_fx_random();
		g_mem_track_filename = "fx_marks";
		TRACK_fx_marks();
		g_mem_track_filename = "fx_system";
		TRACK_fx_system();
		g_mem_track_filename = "dvar";
		TRACK_dvar();
		g_mem_track_filename = "dvar_cmds";
		TRACK_dvar_cmds();
		g_mem_track_filename = "msg";
		TRACK_msg();
		g_mem_track_filename = "q_parse";
		TRACK_q_parse();
		g_mem_track_filename = "win_common";
		TRACK_win_common();
		g_mem_track_filename = "win_syscon";
		TRACK_win_syscon();
		g_mem_track_filename = "win_net";
		TRACK_win_net();
		g_mem_track_filename = "g_vehicle_path";
		TRACK_g_vehicle_path();
		g_mem_track_filename = "gamerprofile";
		TRACK_gamerprofile();
		g_mem_track_filename = "q_shared";
		TRACK_q_shared();
		g_mem_track_filename = "common";
		TRACK_common();
		g_mem_track_filename = "dobj_management";
		TRACK_dobj_management();
		g_mem_track_filename = "files";
		TRACK_files();
		g_mem_track_filename = "memtrack";
		TRACK_memtrack();
		g_mem_track_filename = "cl_main";
		TRACK_cl_main();
		g_mem_track_filename = "cl_console";
		TRACK_cl_console();
		g_mem_track_filename = "cl_input";
		TRACK_cl_input();
		g_mem_track_filename = "cl_keys";
		TRACK_cl_keys();
		g_mem_track_filename = "cl_parse";
		TRACK_cl_parse();
		g_mem_track_filename = "scr_animtree";
		TRACK_scr_animtree();
		g_mem_track_filename = "com_memory";
		TRACK_com_memory();
		g_mem_track_filename = "sv_init";
		NULL();
		g_mem_track_filename = "zutil";
		TRACK_zutil();
		g_mem_track_filename = "memfile";
		NULL();
		g_mem_track_filename = "devgui";
		TRACK_devgui();
		g_mem_track_filename = "win_gamepad";
		TRACK_win_gamepad();
		g_mem_track_filename = "assertive";
		TRACK_assertive();
		g_mem_track_filename = "db_registry";
		TRACK_db_registry();
		g_mem_track_filename = "com_profilemapload";
		TRACK_com_profilemapload();
		g_mem_track_filename = "profileMem";
		TRACK_profileMem();
		g_mem_track_filename = "missile_attractors";
		TRACK_missile_attractors();
		g_mem_track_filename = "DynEntityCollWorld";
		TRACK_DynEntityCollWorld();
		g_mem_track_filename = "ragdoll";
		TRACK_ragdoll();
		g_mem_track_filename = "flame_system";
		TRACK_flame_system();
		CG_track_init();
		G_track_init();
		UI_track_init();
		R_Track_Init();
		g_mem_track_filename = "";
		Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
	}
}

/*
==============
track_physical_alloc
==============
*/
void track_physical_alloc(int size, const char *name, int type, int location)
{
	track_init();
	if (size)
	{
		Sys_EnterCriticalSection(CRITSECT_MEMTRACK);

		assert(g_physicalMemInfoCount < MAX_TEMPMEM_INFO);
		if (size <= 0)
		{
			RemoveTempMemInfo(-size, 0, name, type, location, 7, g_physicalMemInfoArray, &g_physicalMemInfoCount);
		}
		else
		{
			AddTempMemInfo(size, 0, 0, name, type, location, 7, g_physicalMemInfoArray, &g_physicalMemInfoCount);
		}

		track_addbasicinfo(&g_info, type, location, size);
		Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
	}
}

/*
==============
track_PrintInfo
==============
*/
void track_PrintInfo()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_PrintAllInfo
==============
*/
void track_PrintAllInfo()
{
	if (Sys_IsMainThread())
		track_PrintInfo();
}

