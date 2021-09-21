#include "types.h"
#include "functions.h"

/*
==============
CG_ShutdownEntity
==============
*/
void CG_ShutdownEntity(LocalClientNum_t localClientNum, centity_t *cent, bool shutdown_script_for_local_client)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_TeleportEntity
==============
*/
void CG_TeleportEntity(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ResetEntity_EventSequence
==============
*/
void ResetEntity_EventSequence(centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ResetEntity_Internal
==============
*/
void ResetEntity_Internal(LocalClientNum_t localClientNum, centity_t *cent, int newEntity, int killcamEndingTransition)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ShutdownEntities
==============
*/
void CG_ShutdownEntities(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateKillcamForEntity
==============
*/
int CG_UpdateKillcamForEntity(LocalClientNum_t localClientNum, int newKillCamEntity)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_UpdateClientFlags
==============
*/
void CG_UpdateClientFlags(LocalClientNum_t localClientNum, centity_t *cent, int oldEFlags2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_TransitionKillcam
==============
*/
void CG_TransitionKillcam(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UnpackMatchState
==============
*/
void CG_UnpackMatchState(LocalClientNum_t localClientNum, MatchState *matchState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CopyScoreFromClientState
==============
*/
void CG_CopyScoreFromClientState(LocalClientNum_t localClientNum, clientInfo_t *ci, clientState_s *cs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateScoreData
==============
*/
void CG_UpdateScoreData(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_LocalPlayerRespawned
==============
*/
bool CG_LocalPlayerRespawned(LocalClientNum_t localClientNum, snapshot_s *snap)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_SetNextSnap
==============
*/
void CG_SetNextSnap(LocalClientNum_t localClientNum, snapshot_s *snap)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ReadNextSnapshot
==============
*/
snapshot_s *CG_ReadNextSnapshot(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_SetInitialSnapshot
==============
*/
void CG_SetInitialSnapshot(LocalClientNum_t localClientNum, snapshot_s *snap)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_TransitionSnapshot
==============
*/
void CG_TransitionSnapshot(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ProcessSnapshots
==============
*/
void CG_ProcessSnapshots(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

