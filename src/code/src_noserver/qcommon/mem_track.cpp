#include "types.h"
#include "functions.h"

/*
==============
track_addbasicmeminfo
==============
*/
void track_addbasicmeminfo(meminfo_t *sum, meminfo_t *in)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_static_alloc_internal_simple
==============
*/
void track_static_alloc_internal_simple(void *ptr, int size, const char *name, int memTrack)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetTempMemInfo
==============
*/
TempMemInfo *GetTempMemInfo(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
track_flush_physical_alloc
==============
*/
void track_flush_physical_alloc(const char *name, int type)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_z_alloc
==============
*/
void track_z_alloc(int size, const char *name, int type, void *pos, int project, int overhead)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_z_free
==============
*/
void track_z_free(int type, void *pos, int overhead)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_z_commit
==============
*/
void track_z_commit(int size, int type)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_temp_alloc
==============
*/
void track_temp_alloc(int size, int hunkSize, int permanent, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_temp_free
==============
*/
void track_temp_free(int size, int permanent, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_temp_clear
==============
*/
void track_temp_clear(int permanent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_temp_high_alloc
==============
*/
void track_temp_high_alloc(int size, int hunkSize, int permanent, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_temp_high_clear
==============
*/
void track_temp_high_clear(int permanent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_userhunk_freerange
==============
*/
void track_userhunk_freerange(void *low, unsigned int size)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_userhunk_free
==============
*/
void track_userhunk_free(void *ptr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_userhunk_alloc
==============
*/
void track_userhunk_alloc(int size, int pos, const char *name, int type)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_hunk_alloc
==============
*/
void track_hunk_alloc(int size, int pos, const char *name, int type)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_hunk_allocLow
==============
*/
void track_hunk_allocLow(int size, int pos, const char *name, int type)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_set_hunk_size
==============
*/
void track_set_hunk_size(int size)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_hunk_ClearToMarkHigh
==============
*/
void track_hunk_ClearToMarkHigh(int mark)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_hunk_ClearToMarkLow
==============
*/
void track_hunk_ClearToMarkLow(int mark)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_hunk_ClearToStart
==============
*/
void track_hunk_ClearToStart()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
mem_track_compare
==============
*/
int mem_track_compare(const void *elem1, const void *elem2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
track_getbasicinfo
==============
*/
void track_getbasicinfo(meminfo_t *info)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_printf
==============
*/
void track_printf(const char *fmt, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_shutdown
==============
*/
void track_shutdown(int project)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TRACK_memtrack
==============
*/
void TRACK_memtrack()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_init
==============
*/
void track_init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
track_physical_alloc
==============
*/
void track_physical_alloc(int size, const char *name, int type, int location)
{
	UNIMPLEMENTED(__FUNCTION__);
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
	UNIMPLEMENTED(__FUNCTION__);
}

