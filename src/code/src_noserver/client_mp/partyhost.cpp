#include "types.h"
#include "functions.h"

/*
==============
Party_PrintTeams
==============
*/
void Party_PrintTeams(SubpartyInfo *subparties, int subpartyCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_AddAllPlayersToPresenceSession
==============
*/
void PartyHost_AddAllPlayersToPresenceSession(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_PrintConnectivity
==============
*/
void PartyHost_PrintConnectivity(PartyData_s *party, const ClientNum_t clientNum, const int bits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ClearMember
==============
*/
void ClearMember(PartyData_s *party, const int memberIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_ClearMembers
==============
*/
void PartyHost_ClearMembers(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_SetLeagueDataState
==============
*/
void PartyHost_SetLeagueDataState(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_CountMembers
==============
*/
int PartyHost_CountMembers(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_FindOldestZombieSlot
==============
*/
int PartyHost_FindOldestZombieSlot(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_CountUninvitedPlayers
==============
*/
int PartyHost_CountUninvitedPlayers(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_CountInvitedPlayers
==============
*/
int PartyHost_CountInvitedPlayers(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_CountOpenPublicSlots
==============
*/
int PartyHost_CountOpenPublicSlots(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_CountAnonymousPlayers
==============
*/
int PartyHost_CountAnonymousPlayers(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_CanFormTeams
==============
*/
char PartyHost_CanFormTeams(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AssignmentFitness
==============
*/
bool AssignmentFitness(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CompareFitness
==============
*/
int CompareFitness(const void *a, const void *b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_FindTeams
==============
*/
bool PartyHost_FindTeams(SubpartyInfo *parties, const int partyCount, const int teamCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
StackRankSort
==============
*/
int StackRankSort(const void *_a, const void *_b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_FindSubparties
==============
*/
void PartyHost_FindSubparties(PartyData_s *party, int flags, SubpartyInfo *subparties, int *subpartyCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_UpdateSubpartyIndex
==============
*/
void PartyHost_UpdateSubpartyIndex(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_GetPlayingTeamCount
==============
*/
int PartyHost_GetPlayingTeamCount(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_GetSmallestTeamCount
==============
*/
int PartyHost_GetSmallestTeamCount(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_GetLargestTeamCount
==============
*/
int PartyHost_GetLargestTeamCount(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_GetSmallestTeam
==============
*/
team_t PartyHost_GetSmallestTeam(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	team_t tmp;
	return tmp;
}

/*
==============
PartyHost_BuildRandomChallengeId
==============
*/
int PartyHost_BuildRandomChallengeId()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_ComparePartyConnection
==============
*/
bool PartyHost_ComparePartyConnection(PartyData_s *party, int ping)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_CompareSubpartySkill
==============
*/
int PartyHost_CompareSubpartySkill(SubpartyInfo *setA, int setACount, SubpartyInfo *setB, int setBCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_AnyClientsPresentOrConnecting
==============
*/
char PartyHost_AnyClientsPresentOrConnecting(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_MapIsAcceptable
==============
*/
bool PartyHost_MapIsAcceptable(PartyData_s *party, const char *mapname)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_AssignTeam
==============
*/
int PartyHost_AssignTeam(PartyData_s *party, const ClientNum_t slot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_SetMatchmakingInfo
==============
*/
void PartyHost_SetMatchmakingInfo(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_SetAllowedTeams
==============
*/
void PartyHost_SetAllowedTeams(PartyData_s *party, const char *gametype)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_SetBeginTime
==============
*/
void PartyHost_SetBeginTime(PartyData_s *party, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_GetFirstEmptySlot
==============
*/
ClientNum_t PartyHost_GetFirstEmptySlot(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	ClientNum_t tmp;
	return tmp;
}

/*
==============
compareClientAddrs
==============
*/
int compareClientAddrs(netadr_t a, netadr_t b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_RemoveLocalHost
==============
*/
void PartyHost_RemoveLocalHost(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_GetMemberName
==============
*/
char *PartyHost_GetMemberName(PartyData_s *party, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
PartyHost_MarkMemberInfoDirty
==============
*/
void PartyHost_MarkMemberInfoDirty(PartyData_s *party, int dirtyMemberSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_UpdatePlayerHiding
==============
*/
void PartyHost_UpdatePlayerHiding(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_MemberInfoChanged
==============
*/
void PartyHost_MemberInfoChanged(PartyData_s *party, ClientNum_t memberSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_ResetClientTimeouts
==============
*/
void PartyHost_ResetClientTimeouts(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_SyncVoiceDataForAllPlayers
==============
*/
void PartyHost_SyncVoiceDataForAllPlayers(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_UpdateBitsIfNeeded
==============
*/
bool PartyHost_UpdateBitsIfNeeded(int *voiceConnectivityBits, int connectivityBits)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_UpdateVoiceConnectivityBits
==============
*/
void PartyHost_UpdateVoiceConnectivityBits(PartyData_s *party, ClientNum_t memberIndex, int connectivityBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_AddVoiceConnectivityToAllLocalPlayers
==============
*/
void PartyHost_AddVoiceConnectivityToAllLocalPlayers(PartyData_s *party, ClientNum_t memberIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_SendGo
==============
*/
void PartyHost_SendGo(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_SendPlayDemo
==============
*/
void PartyHost_SendPlayDemo(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_SendStopDemo
==============
*/
void PartyHost_SendStopDemo(PartyData_s *party, ControllerIndex_t localControllerIndex, int partyMemberSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_TeamsAreReady
==============
*/
bool PartyHost_TeamsAreReady(PartyData_s *party, int memberCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_MakeTeams
==============
*/
char PartyHost_MakeTeams(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_StartDemo
==============
*/
void PartyHost_StartDemo(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_StopDemo
==============
*/
void PartyHost_StopDemo(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_RemoveTestClient
==============
*/
void PartyHost_RemoveTestClient(PartyData_s *party, ClientNum_t slot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_RemoveTestClient_f
==============
*/
void Party_RemoveTestClient_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_CloseDWConnectionIfDone
==============
*/
void Party_CloseDWConnectionIfDone(PartyData_s *party, netadr_t addr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_WritePartyStateMembers
==============
*/
void PartyHost_WritePartyStateMembers(PartyData_s *party, int destinationMemberSlot, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_WritePartyState
==============
*/
void PartyHost_WritePartyState(PartyData_s *party, int destinationMemberSlot, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
recordBadFlags
==============
*/
void recordBadFlags(int oldFlags, int newFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
recordBadSlots
==============
*/
void recordBadSlots(int maxplayers, int privateslots)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_SendDemoHeartbeats
==============
*/
void PartyHost_SendDemoHeartbeats(PartyData_s *party, const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_CloseDWConnectionOnDvar
==============
*/
void PartyHost_CloseDWConnectionOnDvar(PartyData_s *party, netadr_t addr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_TellClientToRejoin
==============
*/
void PartyHost_TellClientToRejoin(PartyData_s *party, netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_GenerateNewLobbyMessage
==============
*/
void Party_GenerateNewLobbyMessage(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_SendNewLobbyToAddr
==============
*/
void Party_SendNewLobbyToAddr(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_SetupParty
==============
*/
void PartyHost_SetupParty(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_CreatePartyPresenceComplete
==============
*/
void PartyHost_CreatePartyPresenceComplete(ControllerIndex_t localControllerIndex, PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_HandleEchoRequest
==============
*/
void PartyHost_HandleEchoRequest(PartyData_s *party, ControllerIndex_t localControllerIndex, netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_GenerateClientBitfield
==============
*/
int PartyHost_GenerateClientBitfield(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_AreAllClientsUpToDate
==============
*/
bool PartyHost_AreAllClientsUpToDate(PartyData_s *party, int sinceMS)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_IsJoinInProgressAllowed
==============
*/
bool PartyHost_IsJoinInProgressAllowed(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_ValidateTeams
==============
*/
void PartyHost_ValidateTeams(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_HandleIHearMsg
==============
*/
void PartyHost_HandleIHearMsg(PartyData_s *party, ControllerIndex_t localControllerIndex, netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_HandleCantHearMsg
==============
*/
void PartyHost_HandleCantHearMsg(PartyData_s *party, ControllerIndex_t localControllerIndex, netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_SendPartyAwakeMsgToParty
==============
*/
char PartyHost_SendPartyAwakeMsgToParty(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_HandleProfileMsg
==============
*/
void PartyHost_HandleProfileMsg(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_HandleProfilesAckMsg
==============
*/
void PartyHost_HandleProfilesAckMsg(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_HashLeagueValues
==============
*/
int PartyHost_HashLeagueValues(int visiblePoints, int hiddenPoints, float skill, unsigned __int64 teamID)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_HandleLeagueOutcomesAck
==============
*/
void PartyHost_HandleLeagueOutcomesAck(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_HandleLeagueEmblemUpdate
==============
*/
void PartyHost_HandleLeagueEmblemUpdate(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_RequestLeagueStats
==============
*/
void PartyHost_RequestLeagueStats(PartyData_s *party, int memberIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_SendLeagueOutcomes
==============
*/
void PartyHost_SendLeagueOutcomes(PartyData_s *party, int memberIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_HandleChallenge
==============
*/
void PartyHost_HandleChallenge(PartyData_s *party, ControllerIndex_t localControllerIndex, netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_CanHandlePacket
==============
*/
int PartyHost_CanHandlePacket(PartyData_s *party, const char *c)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_HandlePacket
==============
*/
int PartyHost_HandlePacket(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_CalculateLeagueOutcomes
==============
*/
void PartyHost_CalculateLeagueOutcomes(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_EnforceLeagueTeams
==============
*/
bool PartyHost_EnforceLeagueTeams(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_UpdateLeague
==============
*/
void PartyHost_UpdateLeague(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_LeaguesReady
==============
*/
bool PartyHost_LeaguesReady(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_InitLeagueState
==============
*/
void PartyHost_InitLeagueState(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_ClearReadies
==============
*/
void PartyHost_ClearReadies(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_ClearVetoes
==============
*/
void PartyHost_ClearVetoes(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_SanityCheck
==============
*/
void PartyHost_SanityCheck(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_DetermineVoteWinner
==============
*/
int PartyHost_DetermineVoteWinner(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_StoreMapVoteStats
==============
*/
void PartyHost_StoreMapVoteStats(const ControllerIndex_t localControllerIndex, const char *mapName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_UpdateLocalClient
==============
*/
void PartyHost_UpdateLocalClient(PartyData_s *party, const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_PrintDetails
==============
*/
void PartyHost_PrintDetails(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_GetMaxFreeSlots
==============
*/
int PartyHost_GetMaxFreeSlots(PartyData_s *party, int memberCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_ClearConnectivityBitForClient
==============
*/
void PartyHost_ClearConnectivityBitForClient(PartyData_s *party, const ClientNum_t slot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_AddLocalPlayer
==============
*/
int PartyHost_AddLocalPlayer(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_RemovePlayer
==============
*/
void PartyHost_RemovePlayer(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_RemoveLocalPlayer
==============
*/
void PartyHost_RemoveLocalPlayer(PartyData_s *party, const ClientNum_t memberIndex, bool removePartyToNotify)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_GamestateChanged
==============
*/
void PartyHost_GamestateChanged(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_SetRoundScores
==============
*/
void PartyHost_SetRoundScores(PartyData_s *party, const int memberIndex, const int score, const int deaths)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_SwapPlayer
==============
*/
void PartyHost_SwapPlayer(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_StartTeamMatch
==============
*/
void PartyHost_StartTeamMatch(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_TimeoutMembers
==============
*/
void PartyHost_TimeoutMembers(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_SendPartyStateToPlayer
==============
*/
void PartyHost_SendPartyStateToPlayer(PartyData_s *party, ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_SendPartyStates
==============
*/
void PartyHost_SendPartyStates(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_AddLocalClientsToNewLobby
==============
*/
void PartyHost_AddLocalClientsToNewLobby(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_AddLocalClientsToNewLobby
==============
*/
void PartyHost_AddLocalClientsToNewLobby(PartyData_s *party, const ControllerIndex_t ignoreControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_AddMissingLocalClientsToLobby
==============
*/
void PartyHost_AddMissingLocalClientsToLobby(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_RefreshParty
==============
*/
void PartyHost_RefreshParty(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_SendHeartbeats
==============
*/
void PartyHost_SendHeartbeats(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_DropPlayersToMatchSlots
==============
*/
void PartyHost_DropPlayersToMatchSlots(PartyData_s *party, const int publicSlots)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_StartParty
==============
*/
void PartyHost_StartParty(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_HandleClientPartyStateAck
==============
*/
void PartyHost_HandleClientPartyStateAck(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_HandleClientDisconnect
==============
*/
void PartyHost_HandleClientDisconnect(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_HandleClientLeaderDisconnect
==============
*/
void PartyHost_HandleClientLeaderDisconnect(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_HandleProposedGamestate
==============
*/
void PartyHost_HandleProposedGamestate(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_UpdateLeague_Private
==============
*/
void PartyHost_UpdateLeague_Private(const ControllerIndex_t controllerIndex, PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_StartLeagueMatch
==============
*/
void PartyHost_StartLeagueMatch(PartyData_s *party, ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_EnterStartReadyState
==============
*/
void PartyHost_EnterStartReadyState(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_ClientsAreReady
==============
*/
bool PartyHost_ClientsAreReady(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_AddAnonymousMemberAtSlot
==============
*/
void PartyHost_AddAnonymousMemberAtSlot(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_AddAnonymousMember
==============
*/
bool PartyHost_AddAnonymousMember(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_AnonymousAddRequest
==============
*/
bool PartyHost_AnonymousAddRequest(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_PlayerJustConnected
==============
*/
bool PartyHost_PlayerJustConnected(PartyData_s *party, const ClientNum_t slot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_AddPlayerAtSlot
==============
*/
int PartyHost_AddPlayerAtSlot(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_AddPlayer
==============
*/
int PartyHost_AddPlayer(PartyData_s *party, const netadr_t addr, PartyMember *newMember)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_ClaimAnonymousSpot
==============
*/
PartyMemberAddResult PartyHost_ClaimAnonymousSpot(
{
	UNIMPLEMENTED(__FUNCTION__);
	PartyMemberAddResult tmp;
	return tmp;
}

/*
==============
PartyHost_RemoveAllPartyMembersAtSlotAddress
==============
*/
void PartyHost_RemoveAllPartyMembersAtSlotAddress(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_MarkPacketReceivedForClients
==============
*/
void PartyHost_MarkPacketReceivedForClients(PartyData_s *party, const netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_HandleFinishedLoadingDemoMsg
==============
*/
void PartyHost_HandleFinishedLoadingDemoMsg(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_SortParty
==============
*/
void PartyHost_SortParty(PartyData_s *party, SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_PreMatch
==============
*/
void PartyHost_PreMatch(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_StartMatch
==============
*/
void PartyHost_StartMatch(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_AddTestClient
==============
*/
void PartyHost_AddTestClient(PartyData_s *party, ClientNum_t slot, int privatePartyId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_AddTestClients_f
==============
*/
void Party_AddTestClients_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_SwitchLobby
==============
*/
char PartyHost_SwitchLobby(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_StartPartyComplete
==============
*/
void PartyHost_StartPartyComplete(ControllerIndex_t localControllerIndex, SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_ShouldAutoStart
==============
*/
bool PartyHost_ShouldAutoStart(PartyData_s *party, ControllerIndex_t localControllerIndex, int memberCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_AutoStart
==============
*/
void PartyHost_AutoStart(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_HandleHeartbeatAck
==============
*/
void PartyHost_HandleHeartbeatAck(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_AttemptJoinParty
==============
*/
bool PartyHost_AttemptJoinParty(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyHost_HandleJoinPartyRequest
==============
*/
void PartyHost_HandleJoinPartyRequest(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_HandleLocalJoin
==============
*/
void PartyHost_HandleLocalJoin(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_KickPlayer
==============
*/
void PartyHost_KickPlayer(PartyData_s *party, const ClientNum_t memberIndex, const char *reason)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_TestTeamCreation_f
==============
*/
void Party_TestTeamCreation_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_HandleMemberMsg
==============
*/
void PartyHost_HandleMemberMsg(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_HandleProposedKick
==============
*/
void PartyHost_HandleProposedKick(PartyData_s *party, ControllerIndex_t localControllerIndex, netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_HandleLeagueStats
==============
*/
void PartyHost_HandleLeagueStats(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_CheckForInsufficientWagerFunds
==============
*/
void PartyHost_CheckForInsufficientWagerFunds(const ControllerIndex_t localControllerIndex, PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_UpdateWagerCheckFundsState
==============
*/
void PartyHost_UpdateWagerCheckFundsState(const ControllerIndex_t localControllerIndex, PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_Frame
==============
*/
void PartyHost_Frame(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_HandleClientHandshake
==============
*/
void PartyHost_HandleClientHandshake(
{
	UNIMPLEMENTED(__FUNCTION__);
}

