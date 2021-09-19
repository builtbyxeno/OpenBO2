#include "types.h"
#include "functions.h"

/*
==============
CL_CanWeConnectToClient
==============
*/
int CL_CanWeConnectToClient(
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
int Session_GetConnectivityBitsForAddr(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_GetConnectivityBitsForClientAddress
==============
*/
int Session_GetConnectivityBitsForClientAddress(SessionData *session, const ClientNum_t clientNum)
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
void CL_WeNowCantHearSomeone(LocalClientNum_t localClientNum, SessionData *session, ClientNum_t remoteClient)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SendPeerConnectivityTest
==============
*/
void CL_SendPeerConnectivityTest(
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
void CL_BuildRouteList(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_VoiceConnectionTestPacket
==============
*/
void CL_VoiceConnectionTestPacket(LocalClientNum_t localClientNum, msg_t *msg)
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
char CL_RebuildConnectionToClient(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_SendPeerData_Real
==============
*/
char CL_SendPeerData_Real(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_SendPeerData
==============
*/
char CL_SendPeerData(
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
char CL_SendRelayPacket(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_WritePeerToPeerOOBString
==============
*/
char CL_WritePeerToPeerOOBString(
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

