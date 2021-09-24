#include "types.h"

/*
==============
PMem_InitPhysicalMemory
==============
*/
void PMem_InitPhysicalMemory(PhysicalMemory *pmem, const char *name, void *memory, unsigned int memorySize, bool giveToStreamer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PMem_Init
==============
*/
void PMem_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PMem_BeginAllocInPrim
==============
*/
void PMem_BeginAllocInPrim(PhysicalMemoryPrim *prim, const char *name, EMemTrack memTrack)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PMem_BeginAlloc
==============
*/
void PMem_BeginAlloc(char *a1, const char *name, unsigned int allocType, EMemTrack memTrack)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PMem_EndAlloc
==============
*/
void PMem_EndAlloc(const char *name, unsigned int allocType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PMem_FreeIndex
==============
*/
void PMem_FreeIndex(PhysicalMemory *pmem, unsigned int allocIndex, int allocType, int location)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PMem_Free
==============
*/
void PMem_Free(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PMem_GetOverAllocatedSize
==============
*/
int PMem_GetOverAllocatedSize()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
_PMem_AllocNamed
==============
*/
unsigned __int8 *_PMem_AllocNamed(unsigned int size, unsigned int alignment, unsigned int type, unsigned int allocType, const char *name, EMemTrack memTrack)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
_PMem_Alloc
==============
*/
unsigned __int8 *_PMem_Alloc(unsigned int size, unsigned int alignment, unsigned int type, unsigned int allocType, EMemTrack memTrack, const char *file, int lineNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

