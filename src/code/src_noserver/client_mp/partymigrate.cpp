#include "types.h"
#include "functions.h"

/*
==============
PartyMigrate_CanAnyoneTalkToThisGuy
==============
*/
bool PartyMigrate_CanAnyoneTalkToThisGuy(SessionData *session, int destClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyMigrate_CanWeTalkToAllClients
==============
*/
bool PartyMigrate_CanWeTalkToAllClients(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyMigrate_GetClientConnectivity
==============
*/
unsigned int PartyMigrate_GetClientConnectivity(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyMigrate_DoWeHaveNecessaryMapPacks
==============
*/
bool PartyMigrate_DoWeHaveNecessaryMapPacks(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyMigrate_CanWeHost
==============
*/
bool PartyMigrate_CanWeHost(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyMigrate_IsEnabled
==============
*/
bool PartyMigrate_IsEnabled(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyMigrate_SendSessionInfo
==============
*/
void PartyMigrate_SendSessionInfo(PartyData_s *party, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_RestartServer
==============
*/
void PartyMigrate_RestartServer(PartyData_s *party, const int oldHost)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_FindNextMemberAtAddrInternal
==============
*/
ClientNum_t Party_FindNextMemberAtAddrInternal(
{
	UNIMPLEMENTED(__FUNCTION__);
	ClientNum_t tmp;
	return tmp;
}

/*
==============
Party_UpdateHostAddr
==============
*/
void Party_UpdateHostAddr(PartyData_s *party, netadr_t addr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_CheckBeforeContinuingToHost
==============
*/
void PartyMigrate_CheckBeforeContinuingToHost(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
migrateClient_UpdateState
==============
*/
void migrateClient_UpdateState(migrateClientState_t newState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_MigrateActive
==============
*/
BOOL PartyMigrate_MigrateActive(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_SetMigrateActive
==============
*/
void Party_SetMigrateActive(PartyData_s *party, bool state)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
parseBandwidthTestPacketSyn
==============
*/
int parseBandwidthTestPacketSyn(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
sendTestPacketAck
==============
*/
void sendTestPacketAck(ControllerIndex_t localControllerIndex, const netadr_t from, int fromMS, int seq)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
updateMeanForPeer
==============
*/
void updateMeanForPeer(peerResults_t *peerResults, unsigned int latency)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
getStdDevForPeer
==============
*/
float getStdDevForPeer(peerResults_t *peerResults)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
handleTestPacketAck
==============
*/
void handleTestPacketAck(__int64 localControllerIndex, __int64 from_8, int from_16, msg_t *msga, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_HandleTestPacket
==============
*/
void PartyMigrate_HandleTestPacket(ControllerIndex_t localControllerIndex, const netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
peerResultCompare
==============
*/
int peerResultCompare(const void *a, const void *b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
recalculateNominees
==============
*/
void recalculateNominees(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_HostRead
==============
*/
void PartyMigrate_HostRead(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_HostWrite
==============
*/
void PartyMigrate_HostWrite(PartyData_s *party, ControllerIndex_t localControllerIndex, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_ClientRead
==============
*/
void PartyMigrate_ClientRead(PartyData_s *party, ControllerIndex_t localControllerIndex, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_ClientWrite
==============
*/
void PartyMigrate_ClientWrite(PartyData_s *party, ControllerIndex_t localControllerIndex, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_ClearData
==============
*/
void PartyMigrate_ClearData(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_HandleFindBestCommand
==============
*/
void PartyMigrate_HandleFindBestCommand(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_SwapHostAndClient
==============
*/
void PartyMigrate_SwapHostAndClient(PartyData_s *party, ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_RequestFindBestHost
==============
*/
void PartyMigrate_RequestFindBestHost(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_ComErrorCleanup
==============
*/
void PartyMigrate_ComErrorCleanup()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_IsDebugEnabled
==============
*/
bool PartyMigrate_IsDebugEnabled()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyMigrate_HandleHostAnnounce
==============
*/
void PartyMigrate_HandleHostAnnounce(PartyData_s *party, ControllerIndex_t localControllerIndex, netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_HandlePacket
==============
*/
char PartyMigrate_HandlePacket(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyMigrate_GetDebugInfoAsString
==============
*/
char *PartyMigrate_GetDebugInfoAsString(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
PartyMigrate_GetLastNomineeCalcTime
==============
*/
int PartyMigrate_GetLastNomineeCalcTime()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyMigrate_MatchStarted
==============
*/
void PartyMigrate_MatchStarted()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_HandleSessionInfoMsg
==============
*/
void PartyMigrate_HandleSessionInfoMsg(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_To
==============
*/
void PartyMigrate_To(PartyData_s *party, const ClientNum_t newHost)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_HandleToMsg
==============
*/
void PartyMigrate_HandleToMsg(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_HostFrame
==============
*/
void PartyMigrate_HostFrame(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_Test
==============
*/
void PartyMigrate_Test()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyMigrate_Init
==============
*/
void PartyMigrate_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

