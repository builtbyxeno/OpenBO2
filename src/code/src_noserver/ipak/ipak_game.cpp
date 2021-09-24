#include "types.h"

/*
==============
IPak_FindPackfile
==============
*/
IPakLoadedPackfile *IPak_FindPackfile(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
IPak_MarkAdjacencyInfoAsStale
==============
*/
void IPak_MarkAdjacencyInfoAsStale()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IPak_RemovePackfile
==============
*/
int IPak_RemovePackfile(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IPak_IndexReadCallback
==============
*/
void IPak_IndexReadCallback(int id, stream_status result, unsigned int numBytesRead, void *user)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IPak_ReadIndexData
==============
*/
void IPak_ReadIndexData(IPakWorkData *work, int buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IPak_WaitReadIndexData
==============
*/
void IPak_WaitReadIndexData(IPakWorkData *work, int buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IPak_BeginIndexRead
==============
*/
void IPak_BeginIndexRead(IPakWorkData *work, IPakLoadedPackfile *pak)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IPak_CurrentIndexEntry
==============
*/
char IPak_CurrentIndexEntry(int a1, IPakWorkData *work, IPakIndexEntry *entry)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IPak_NextIndexEntry
==============
*/
char IPak_NextIndexEntry(int a1, IPakWorkData *work, IPakIndexEntry *entry)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IPak_EndIndexRead
==============
*/
void IPak_EndIndexRead(IPakWorkData *work)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IPak_CompareImagePartHashes
==============
*/
int IPak_CompareImagePartHashes(const void *A, const void *B)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IPak_CompareImageOffsets
==============
*/
int IPak_CompareImageOffsets(const void *A, const void *B)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IPak_BuildAdjacencyInfo
==============
*/
void IPak_BuildAdjacencyInfo(const char *a1, unsigned __int8 *workBuffer, int workBufferSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IPak_InvalidateImages
==============
*/
void IPak_InvalidateImages()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IPak_RemovePackfilesForZone
==============
*/
void IPak_RemovePackfilesForZone(const char *zoneName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

