#include "types.h"
#include "functions.h"

/*
==============
CL_DeltaEntity
==============
*/
int CL_DeltaEntity(clientActive_t *cl, msg_t *msg, const int time, clSnapshot_t *frame, int newnum, entityState_s *old)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_GetEntityStateForFrame
==============
*/
entityState_s *CL_GetEntityStateForFrame(clientActive_t *cl, const clSnapshot_t *frame, const int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_ParsePacketEntities
==============
*/
int CL_ParsePacketEntities(clientActive_t *cl, msg_t *msg, const int time, clSnapshot_t *oldframe, clSnapshot_t *newframe, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_ReadPerformanceData
==============
*/
void CL_ReadPerformanceData(clientActive_t *cl, msg_t *msg, int numChangedEnts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_CheckForSnapshotValidity
==============
*/
bool CL_CheckForSnapshotValidity(clientActive_t *cl, clSnapshot_t *old, int deltaNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_ParseSnapshot
==============
*/
void __cdecl CL_ParseSnapshot(LocalClientNum_t localClientNum, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

