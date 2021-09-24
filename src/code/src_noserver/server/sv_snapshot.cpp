#include "types.h"

/*
==============
SV_EmitPacketClients
==============
*/
void SV_EmitPacketClients(SnapshotInfo_s *snapInfo, const int from_num_clients, const int from_first_client, const int to_num_clients, const int to_first_client, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_EmitPacketActors
==============
*/
void SV_EmitPacketActors(SnapshotInfo_s *snapInfo, const int from_num_actors, const int from_first_actor, const int to_num_actors, const int to_first_actor, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_UpdateServerCommandsToClient
==============
*/
void SV_UpdateServerCommandsToClient(client_t *client, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_UpdateServerCommandsToClient_PreventOverflow
==============
*/
void SV_UpdateServerCommandsToClient_PreventOverflow(client_t *client, msg_t *msg, int iMsgSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_PrintServerCommandsForClient
==============
*/
void SV_PrintServerCommandsForClient(client_t *client)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SnapshotRateHeuristic
==============
*/
int SV_SnapshotRateHeuristic()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_AdjustRateForClient
==============
*/
int SV_AdjustRateForClient(client_t *client, int rateMsec)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_ResetRecordMessageSize
==============
*/
void SV_ResetRecordMessageSize()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_RecordMessageSize
==============
*/
void SV_RecordMessageSize(int compressedSize, int uncompressedSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SendMessageToClient
==============
*/
void SV_SendMessageToClient(msg_t *msg, client_t *client, bool reliable)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_BeginClientSnapshot
==============
*/
void SV_BeginClientSnapshot(client_t *client, msg_t *msg, unsigned __int8 *buffer, int bufferSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_EndClientSnapshot
==============
*/
void SV_EndClientSnapshot(client_t *client, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SetServerStaticHeader
==============
*/
void SV_SetServerStaticHeader()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_GetServerStaticHeader
==============
*/
void SV_GetServerStaticHeader()
{
	UNIMPLEMENTED(__FUNCTION__);
}

