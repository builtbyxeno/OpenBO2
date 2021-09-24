#include "types.h"

/*
==============
CL_CanWeConnectToClient
==============
*/
int CL_CanWeConnectToClient(SessionData *session, const ClientNum_t ourClientNum, const ClientNum_t theirClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_CanClientTalkToAllClientsInList
==============
*/
char CL_CanClientTalkToAllClientsInList(SessionData *session, const int sender, const int clientBits)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_GetConnectivityBitsForAddr
==============
*/
int Session_GetConnectivityBitsForAddr(SessionData *session, const netadr_t from, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_GetConnectivityBitsForClientAddress
==============
*/
int __cdecl Session_GetConnectivityBitsForClientAddress(SessionData *session, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_GetConnectivityBitsForLocalClients
==============
*/
int Session_GetConnectivityBitsForLocalClients(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_UpdateConnectivityBits
==============
*/
void CL_UpdateConnectivityBits(LocalClientNum_t localClientNum, SessionData *session, int connectivityBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_WeNowCantHearSomeone
==============
*/
void CL_WeNowCantHearSomeone(char *a1, LocalClientNum_t localClientNum, SessionData *session, ClientNum_t remoteClient)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SendPeerConnectivityTest
==============
*/
void CL_SendPeerConnectivityTest(const LocalClientNum_t localClientNum, SessionData *session, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SendVoiceTestPackets
==============
*/
void CL_SendVoiceTestPackets(ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_FindGoodRouteForClientList
==============
*/
ClientNum_t CL_FindGoodRouteForClientList(SessionData *session, int *routeList, const int clientBits)
{
	UNIMPLEMENTED(__FUNCTION__);
	ClientNum_t tmp;
	return tmp;
}

/*
==============
CL_FindGoodRouteForClientNum
==============
*/
ClientNum_t CL_FindGoodRouteForClientNum(SessionData *session, int *routeList, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	ClientNum_t tmp;
	return tmp;
}

/*
==============
CL_BuildRouteList
==============
*/
void CL_BuildRouteList(SessionData *session, LocalClientNum_t localClientNum, ClientNum_t ourClientNum, int *routeList)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_VoiceConnectionTestPacket
==============
*/
void __cdecl CL_VoiceConnectionTestPacket(LocalClientNum_t localClientNum, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_RemoveLocalClientsFromRelayList
==============
*/
int CL_RemoveLocalClientsFromRelayList(SessionData *session, int relayList)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_ShouldIgnorePlayer
==============
*/
bool CL_ShouldIgnorePlayer(SessionData *session, LocalClientNum_t localClientNum, ClientNum_t talker)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_FindRouteForClientNum
==============
*/
ClientNum_t CL_FindRouteForClientNum(SessionData *session, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	ClientNum_t tmp;
	return tmp;
}

/*
==============
CL_IsPlayerTalking
==============
*/
bool CL_IsPlayerTalking(SessionData *session, LocalClientNum_t localClientNum, ClientNum_t talkingClientIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_CheckMutes
==============
*/
void CL_CheckMutes(SessionData *session, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_TogglePlayerMuteForUI
==============
*/
void CL_TogglePlayerMuteForUI(LocalClientNum_t localClientNum, unsigned __int64 playerXuid)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Voice_SendVoiceData
==============
*/
bool Voice_SendVoiceData()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_ClientVoiceEvent
==============
*/
int Com_ClientVoiceEvent()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_RebuildConnectionToClient
==============
*/
char CL_RebuildConnectionToClient(SessionData *session, LocalClientNum_t localClientNum, ClientNum_t ourClientNum, ClientNum_t destClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_SendPeerData_Real
==============
*/
char CL_SendPeerData_Real(SessionData *session, const LocalClientNum_t localClientNum, const netsrc_t sock, const ClientNum_t clientNum, msg_t *msg, PeerDataPacketType dataType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_SendPeerData
==============
*/
char CL_SendPeerData(SessionData *session, const LocalClientNum_t localClientNum, const netsrc_t sock, const ClientNum_t clientNum, msg_t *msg, PeerDataPacketType dataType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_WriteVoicePacket
==============
*/
void CL_WriteVoicePacket(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_VoicePacket
==============
*/
void CL_VoicePacket(LocalClientNum_t localClientNum, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SendRelayPacket
==============
*/
char CL_SendRelayPacket(SessionData *session, ControllerIndex_t localControllerIndex, ClientNum_t relayClientNum, ClientNum_t destinationClientNum, const char *message)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_WritePeerToPeerOOBString
==============
*/
char CL_WritePeerToPeerOOBString(SessionData *session, ControllerIndex_t localControllerIndex, ClientNum_t clientNum, netsrc_t remoteLocalNetID, const char *message)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_VoiceTransmit
==============
*/
void CL_VoiceTransmit(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Client_SendVoiceData
==============
*/
int Client_SendVoiceData(int bytes, char *enc_buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_VoiceFrame
==============
*/
void CL_VoiceFrame(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_RenderVoiceFrame
==============
*/
void Com_RenderVoiceFrame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

