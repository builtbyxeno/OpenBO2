#include "types.h"
#include "client_public.h"

/*
==============
CL_SavePredictedPlayerInformationForServerTime
==============
*/
void CL_SavePredictedPlayerInformationForServerTime(clientActive_t *cl, const int serverTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_GetClientArchiveIndexForServerTime
==============
*/
char CL_GetClientArchiveIndexForServerTime(clientActive_t *cl, const int serverTime, int *resultIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_GetPredictedPlayerInformationForServerTime
==============
*/
char CL_GetPredictedPlayerInformationForServerTime(clientActive_t *cl, const int serverTime, playerState_s *to)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_SavePredictedVehicleForServerTime
==============
*/
void CL_SavePredictedVehicleForServerTime(clientActive_t *cl, const int serverTime, const PlayerVehicleState *predictedPlayerVehState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_GetPredictedVehicleForServerTime
==============
*/
int CL_GetPredictedVehicleForServerTime(clientActive_t *cl, const int serverTime, PlayerVehicleState *predictedPlayerVehState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_CopyOldEntity
==============
*/
void CL_CopyOldEntity(clientActive_t *cl, clSnapshot_t *frame, entityState_s *old)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ParsePacketMatchState
==============
*/
void CL_ParsePacketMatchState(clientActive_t *cl, msg_t *msg, const int time, clSnapshot_t *oldframe, clSnapshot_t *newframe)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DeltaClient
==============
*/
void CL_DeltaClient(clientActive_t *cl, msg_t *msg, const int time, clSnapshot_t *frame, int newnum, clientState_s *old, int unchanged)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ParsePacketClients
==============
*/
void CL_ParsePacketClients(clientActive_t *cl, msg_t *msg, const int time, clSnapshot_t *oldframe, clSnapshot_t *newframe)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ParsePacketActors
==============
*/
void CL_ParsePacketActors(clientActive_t *cl, msg_t *msg, const int time, clSnapshot_t *oldframe, clSnapshot_t *newframe)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ServerIdChanged
==============
*/
void CL_ServerIdChanged(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SystemInfoChanged
==============
*/
void CL_SystemInfoChanged(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ParseMapCenter
==============
*/
void CL_ParseMapCenter()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
StoreConfigString
==============
*/
void StoreConfigString(int index, const char *s)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ParseConfigStrings_Internal
==============
*/
void CL_ParseConfigStrings_Internal(LocalClientNum_t localClientNum, msg_t *msg, void (*storeHandler)(int, const char *))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_CheckBSPCheckSum
==============
*/
void CL_CheckBSPCheckSum(unsigned int serverChecksum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ParseGamestate_Checksums
==============
*/
void CL_ParseGamestate_Checksums(LocalClientNum_t localClientNum, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ParseGamestate
==============
*/
void CL_ParseGamestate(LocalClientNum_t localClientNum, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ParseServerMessage
==============
*/
void CL_ParseServerMessage(LocalClientNum_t localClientNum, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TRACK_cl_parse
==============
*/
void TRACK_cl_parse()
{
	UNIMPLEMENTED(__FUNCTION__);
}

