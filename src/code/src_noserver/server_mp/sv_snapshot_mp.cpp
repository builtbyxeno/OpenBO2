#include "types.h"

/*
==============
SV_GetNextEnt
==============
*/
const entityState_s *SV_GetNextEnt(const int entCount, const int firstEntIndex, int curIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_EntLinkedToEnt
==============
*/
bool SV_EntLinkedToEnt(const entityState_s *childEnt, int parentEntIndex, const int entCount, const int firstEntityIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_ShouldEntityGoToClient
==============
*/
bool SV_ShouldEntityGoToClient(const entityState_s *ent, const int clientNum, const int entCount, const int firstEntityIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_EmitPacketEntities_Debug
==============
*/
void SV_EmitPacketEntities_Debug(SnapshotInfo_s *snapInfo, int *quickBits, msg_t *msg, const char *str, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_EmitPacketEntities
==============
*/
void SV_EmitPacketEntities(SnapshotInfo_s *snapInfo, const int viewClientNum, const int oldFrameViewClientNum, const int oldEntCount, const int firstOldEntityIndex, const int oldFrameTimeDelta, const int newEntCount, const int firstNewEntityIndex, const int newFrameTimeDelta, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_WritePerformanceData
==============
*/
void SV_WritePerformanceData(const ClientNum_t clientNum, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_WriteSnapshotToClient
==============
*/
void SV_WriteSnapshotToClient(char *a1, client_t *client, msg_t *msg, const bool sendEntities, const bool writeClientsAndOtherData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_RateMsec
==============
*/
int SV_RateMsec()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_SetServerStaticHeader_Project
==============
*/
void SV_SetServerStaticHeader_Project()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_GetServerStaticHeader_Project
==============
*/
void SV_GetServerStaticHeader_Project()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SendClientMessages
==============
*/
void SV_SendClientMessages(int a1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

