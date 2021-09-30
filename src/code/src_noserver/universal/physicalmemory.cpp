#include "types.h"
#include "vars.h"
#include <qcommon/qcommon_public.h>
#include <win32/win32_public.h>

PhysicalMemory g_mem;

__declspec(thread) unsigned int g_alloc_type;

int g_overAllocatedSize;
bool g_physicalMemoryInit;
unsigned int freeTot;

#define MAX_PHYSICAL_ALLOCATIONS 0x20

/*
==============
PMem_InitPhysicalMemory
==============
*/
void PMem_InitPhysicalMemory(PhysicalMemory *pmem, unsigned int memorySize, const char* name, void* memory)
{
	assert(pmem);
	assert(memory);
	memset((void*)pmem, 0, sizeof(PhysicalMemory));
	pmem->buf = (unsigned char*)memory;
	pmem->name = name;
	pmem->prim[1].pos = memorySize;
	pmem->size = memorySize;
}

/*
==============
PMem_Init
==============
*/
void PMem_Init()
{
	void* memoryAlloc;

	g_physicalMemoryInit = 1;
	memoryAlloc = VirtualAlloc(0, 0x10000000, 0x1000, 4);
	PMem_InitPhysicalMemory(&g_mem, 0x10000000, "main", memoryAlloc);
}

/*
==============
PMem_BeginAllocInPrim
==============
*/
void PMem_BeginAllocInPrim(PhysicalMemoryPrim *prim, const char *name, EMemTrack memTrack)
{
	unsigned int allocListCount;
	prim->memTrack = memTrack;
	allocListCount = prim->allocListCount;
	prim->allocName = name;
	prim->allocListCount = allocListCount + 1;
	prim->allocList[allocListCount].name = name;
	prim->allocList[allocListCount].pos = prim->pos;
}

/*
==============
PMem_BeginAlloc
==============
*/
void PMem_BeginAlloc(const char *name, unsigned int allocType, EMemTrack memTrack)
{
	g_alloc_type = allocType;
	PMem_BeginAllocInPrim(&g_mem.prim[allocType], name, memTrack);
}

/*
==============
PMem_EndAlloc
==============
*/
void PMem_EndAlloc(const char *name, unsigned int allocType)
{
	assert(I_stricmp(g_mem.prim[allocType].allocName, name) == 0);
	g_mem.prim[allocType].allocName = NULL;
}

/*
==============
PMem_FreeIndex
==============
*/
void PMem_FreeIndex(PhysicalMemory *pmem, unsigned int allocIndex, int allocType, int location)
{
	PhysicalMemoryAllocation* allocEntry;
	PhysicalMemoryPrim* prim;
	const char* name;

	prim = &pmem->prim[allocType];
	assert(!prim->allocName);
	name = allocEntry->name;

	assert(name);
	allocEntry->name = NULL;
	track_flush_physical_alloc(name, prim->memTrack);
	if (allocIndex != prim->allocListCount - 1)
	{
		track_PrintInfo();
		Com_Error(ERR_FATAL, "free does not match allocation");
		return;
	}

	track_physical_alloc(-abs((int)(prim->pos - prim->allocList[allocIndex].pos)), name, prim->memTrack, location);

	do
	{
		prim->pos = allocEntry->pos;
		assert(prim->allocListCount);
		--prim->allocListCount;

		if (!prim->allocListCount)
		{
			break;
		}
		allocEntry = &prim->allocList[prim->allocListCount - 1];
	} while (!allocEntry->name);
}

/*
==============
PMem_Free
==============
*/
void PMem_Free(const char* name)
{
	PhysicalMemoryPrim* prim;

	if (!com_quitInProgress)
	{
		for (int i = 0; i < 2; ++i)
		{
			if (i)
			{
				Com_Printf(CON_CHANNEL_SYSTEM, "PMem_Free( %s, %s )\n", name, "High");
			}
			else
			{
				Com_Printf(CON_CHANNEL_SYSTEM, "PMem_Free( %s, %s )\n", name, "Low");
			}
			prim = &g_mem.prim[i];
			for (int allocIndex = 0; allocIndex < prim->allocListCount; ++allocIndex)
			{
				if (prim->allocList[allocIndex].name == name)
				{
					PMem_FreeIndex(&g_mem, allocIndex, i, 0);
					return;
				}
			}
		}
	}
}

/*
==============
PMem_GetOverAllocatedSize
==============
*/
int PMem_GetOverAllocatedSize()
{
	return g_overAllocatedSize;
}

/*
==============
_PMem_AllocNamed
==============
*/
void *_PMem_AllocNamed(unsigned int size, unsigned int alignment, unsigned int type, unsigned int allocType, const char *name, EMemTrack memTrack)
{
	int alignedSize;
	unsigned int highPos, lowPos;
	unsigned int allocatedSize;
	int location;

	location = 0;
	PMem_Init();
	if ((type & INT_MAX) != 0)
	{
		location = 1;
	}
	assert(size);
	assert(alignment);
	if (allocType)
	{
		assert(allocType == PHYS_ALLOC_HIGH);
		lowPos = ~alignment & (g_mem.prim[allocType].pos - size);
		g_overAllocatedSize = g_mem.prim[0].pos - lowPos;
		if (g_overAllocatedSize > 0)
		{
			Com_Printf(CON_CHANNEL_SYSTEM, "requested size:  %d  over allocation:  %d\n", size, g_overAllocatedSize);
			Sys_OutOfMemErrorInternal(__FILE__, __LINE__);
		}
		allocatedSize = g_mem.prim[allocType].pos - lowPos;
		g_mem.prim[allocType].pos = lowPos;
	}
	else
	{
		lowPos = ~alignment & (alignment + g_mem.prim[allocType].pos);
		highPos = size + lowPos;
		alignedSize = size + lowPos - g_mem.prim[allocType].pos;
		g_overAllocatedSize = size + lowPos - g_mem.prim[1].pos;
		if (g_overAllocatedSize > 0)
		{
			Com_PrintError(CON_CHANNEL_SYSTEM, "Need %i more bytes of '%s' physical ram for alloc to succeed\n", g_overAllocatedSize, g_mem.name);
			Sys_OutOfMemErrorInternal(__FILE__, __LINE__);
		}
		allocatedSize = highPos - g_mem.prim[allocType].pos;
		g_mem.prim[allocType].pos = highPos;
	}

	track_physical_alloc(allocatedSize, name, memTrack, location);
	return &g_mem.buf[lowPos];
}

/*
==============
_PMem_Alloc
==============
*/
void *_PMem_Alloc(unsigned int size, unsigned int alignment, unsigned int type, unsigned int allocType, EMemTrack memTrack, const char *file, int lineNum)
{
	char allocIdBuf[256];

	sprintf(allocIdBuf, "%s::%s %d", g_mem.prim[allocType].allocName, file, lineNum);
	return _PMem_AllocNamed(size, alignment, type, allocType, allocIdBuf, memTrack);
}

