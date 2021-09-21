#include "types.h"
#include "functions.h"

/*
==============
SV_FrameIsStillInArchivedSnapshotBuffer
==============
*/
bool SV_FrameIsStillInArchivedSnapshotBuffer(const int frameStart)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_GetCachedSnapshotInternal
==============
*/
cachedSnapshot_t *SV_GetCachedSnapshotInternal(int archivedFrame, int depth, bool expectedToSucceed)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_GetCachedSnapshot
==============
*/
cachedSnapshot_t *SV_GetCachedSnapshot(int *pArchiveTime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_GetCurrentClientInfo
==============
*/
int SV_GetCurrentClientInfo(ClientNum_t clientNum, playerState_s *ps, clientState_s *cs, bool allowLastActive)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_GetClientPositionsFromCachedSnap
==============
*/
void SV_GetClientPositionsFromCachedSnap(const cachedSnapshot_t *cachedFrame, vec3_t *pos, vec3_t *angles, bool *success)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_GetClientPositionsAtTimeInternal
==============
*/
bool SV_GetClientPositionsAtTimeInternal(int gametime, vec3_t *pos, vec3_t *angles, bool *success, int *flags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_GetClientPositionsAtTimeFromClientPositionArchive
==============
*/
bool SV_GetClientPositionsAtTimeFromClientPositionArchive(int gametime, vec3_t *pos, vec3_t *angles, bool *success, int *flags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_GetClientPositionsAtTime
==============
*/
bool SV_GetClientPositionsAtTime(vec3_t *a1, int a2, int gametime, vec3_t *pos, vec3_t *angles, bool *success)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_GetArchivedClientInfo
==============
*/
int SV_GetArchivedClientInfo(ClientNum_t clientNum, playerState_s *allowLastActive, int *pArchiveTime, playerState_s *ps, clientState_s *cs, vec3_t *origin, int *health, int *otherFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_HasCachedSnapshotInternal
==============
*/
char SV_HasCachedSnapshotInternal(int archivedFrame, int callDepth)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_GetEarliestArchivedClientInfoTime
==============
*/
int SV_GetEarliestArchivedClientInfoTime()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

