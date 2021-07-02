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

#include "physicalmemory.h"

#include <universal/q_shared.h>

enum EMemTrack : __int32
{
	TRACK_DEBUG = 0x0,
	TRACK_HUNK = 0x1,
	TRACK_BINARIES = 0x2,
	TRACK_MISC_SWAP = 0x3,
	TRACK_DELIMITER1 = 0x4,
	TRACK_AI = 0x5,
	TRACK_AI_NODES = 0x6,
	TRACK_SCRIPT = 0x7,
	TRACK_SCRIPT_DEBUG = 0x8,
	TRACK_FX = 0x9,
	TRACK_GLASS = 0xA,
	TRACK_NETWORK_ENTITY = 0xB,
	TRACK_MISC = 0xC,
	TRACK_FASTFILE = 0xD,
	TRACK_ANIMATION = 0xE,
	TRACK_ANIMCACHE = 0xF,
	TRACK_WORLD_GLOBALS = 0x10,
	TRACK_SOUND_GLOBALS = 0x11,
	TRACK_CLIENT_ANIMSCRIPT = 0x12,
	TRACK_SOUND = 0x13,
	TRACK_DELIMITER2 = 0x14,
	TRACK_RENDERER_GLOBALS = 0x15,
	TRACK_RENDERER_IMAGES = 0x16,
	TRACK_RENDERER_WORLD = 0x17,
	TRACK_RENDERER_MODELS = 0x18,
	TRACK_RENDERER_MISC = 0x19,
	TRACK_RENDERER_SIEGE = 0x1A,
	TRACK_CINEMATICS = 0x1B,
	TRACK_DELIMITER3 = 0x1C,
	TRACK_COLLISION_MISC = 0x1D,
	TRACK_COLLISION_BRUSH = 0x1E,
	TRACK_COLLISION_MODEL_TRI = 0x1F,
	TRACK_COLLISION_TERRAIN = 0x20,
	TRACK_PHYSICS = 0x21,
	TRACK_MAP_ENTS = 0x22,
	TRACK_TEMP = 0x23,
	TRACK_DELIMITER4 = 0x24,
	TRACK_LOCALIZATION = 0x25,
	TRACK_FLAME = 0x26,
	TRACK_UI = 0x27,
	TRACK_TL = 0x28,
	TRACK_ZMEM = 0x29,
	TRACK_FIREMANAGER = 0x2A,
	TRACK_PROFILE = 0x2B,
	TRACK_CLIENT = 0x2C,
	TRACK_RECORDER = 0x2D,
	TRACK_RSTREAM = 0x2E,
	TRACK_RENDERER_STREAMBUFFER = 0x2F,
	TRACK_RENDERER_STREAMBUFFER_EXTRA = 0x30,
	TRACK_GEOSTREAM = 0x31,
	TRACK_DDL = 0x32,
	TRACK_ONLINE = 0x33,
	TRACK_EMBLEM = 0x34,
	TRACK_VEHICLEDEF = 0x35,
	TRACK_THREAD_LOCAL = 0x36,
	TRACK_MINSPEC_IMAGES = 0x37,
	TRACK_DELIMITER5 = 0x38,
	TRACK_NONE = 0x39,
	TRACK_COUNT = 0x3A,
};

typedef struct PhysicalMemoryAllocation
{
	const char* name;
	unsigned int pos;
} PhysicalMemoryAllocation;

typedef struct PhysicalMemoryPrim
{
	const char* allocName;
	unsigned int allocListCount;
	unsigned int pos;
	PhysicalMemoryAllocation allocList[80];
	EMemTrack memTrack;
} PhysicalMemoryPrim;

typedef struct PhysicalMemory
{
	const char* name;
	unsigned __int8* buf;
	PhysicalMemoryPrim prim[2];
	unsigned int size;
} PhysicalMemory;

static bool g_physicalMemoryInit;
__declspec(thread) unsigned int g_alloc_type;
static PhysicalMemory g_mem;

void PMem_InitPhysicalMemory(PhysicalMemory* pmem, unsigned int memorySize, char const* name, void* memory)
{
	memset(pmem, 0, sizeof(PhysicalMemory));
	pmem->name = name;
	pmem->buf = (unsigned __int8*)memory;
	pmem->prim[1].pos = memorySize;
	pmem->size = memorySize;
}

void PMem_Init(void)
{
	void* memory;
	g_physicalMemoryInit = true;
	memory = VirtualAlloc(NULL, 0x10000000u, 0x1000u, 4u);
	PMem_InitPhysicalMemory(&g_mem, 0x10000000u, "main", memory);
}

void PMem_BeginAllocInPrim(PhysicalMemoryPrim* prim, char const* name, EMemTrack memTrack)
{
	PhysicalMemoryAllocation* allocEntry;

	prim->allocName = name;
	prim->memTrack = memTrack;
	allocEntry = &prim->allocList[prim->allocListCount++];
	allocEntry->name = name;
	allocEntry->pos = prim->pos;
}

void PMem_BeginAlloc(char const* name, unsigned int allocType, EMemTrack memTrack)
{
	g_alloc_type = allocType;
	assertIn(allocType, PHYS_ALLOC_COUNT);
	PMem_BeginAllocInPrim(&g_mem.prim[allocType], name, memTrack);
}

void PMem_EndAlloc(char const* name, unsigned int allocType)
{

}

void PMem_FreeIndex(PhysicalMemory*, unsigned int, int, int)
{
}

void PMem_Free(char const*)
{
}

int PMem_GetOverAllocatedSize(void)
{
	return 0;
}

void* PMem_AllocNamed(unsigned int, unsigned int, unsigned int, unsigned int, char const*, EMemTrack, char const*, int)
{
	return nullptr;
}

void* PMem_Alloc(unsigned int, unsigned int, unsigned int, unsigned int, EMemTrack, char const*, int)
{
	return nullptr;
}
