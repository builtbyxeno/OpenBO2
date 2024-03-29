#include "types.h"

/*
==============
Party_MemberStatusString
==============
*/
const char *Party_MemberStatusString(int status)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Party_LobbyFlagsString
==============
*/
char *Party_LobbyFlagsString(unsigned __int8 lobbyFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Party_UpdateMostRecentPlaylistEntry
==============
*/
void Party_UpdateMostRecentPlaylistEntry(unsigned __int8 playlistEntry)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_ValidateAddr
==============
*/
void Party_ValidateAddr(netadr_t addr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_PlayerHasLoopbackAddr
==============
*/
BOOL Party_PlayerHasLoopbackAddr(PartyMember *member)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_GetClientTimeout
==============
*/
int Party_GetClientTimeout()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_CurrentLocalMapPackFlags
==============
*/
int Live_CurrentLocalMapPackFlags()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_CurrentFullPartyMapPackFlags
==============
*/
int Live_CurrentFullPartyMapPackFlags(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_GetPartyTotalMapPackFlags
==============
*/
int Live_GetPartyTotalMapPackFlags(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_GetDLC0HackContentFlag
==============
*/
int Live_GetDLC0HackContentFlag()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_MemberMissingMapPacks
==============
*/
int Party_MemberMissingMapPacks(const PartyData_s *party, const int member, const int neededPacks, int *mapPackIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_ClearLastEntries
==============
*/
void Party_ClearLastEntries(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RandomPermute
==============
*/
void RandomPermute(int *arr, int size)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RandomizeParty
==============
*/
void RandomizeParty()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_GetLobbyState_f
==============
*/
void Party_GetLobbyState_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_ToggleMute_f
==============
*/
void Party_ToggleMute_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_IsMemberDedicated
==============
*/
BOOL Party_IsMemberDedicated(const PartyMember *partyMember)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_CountMembersEvenIfInactive
==============
*/
int Party_CountMembersEvenIfInactive(const PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyClient_CountMembers
==============
*/
int PartyClient_CountMembers(const PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyClient_CountLocalMembersEvenIfInactive
==============
*/
int PartyClient_CountLocalMembersEvenIfInactive(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyClient_CountLocalMembers
==============
*/
int PartyClient_CountLocalMembers(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyClient_IsMemberLocal
==============
*/
bool PartyClient_IsMemberLocal(PartyData_s *party, ClientNum_t slot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_CountMembersAtAddr
==============
*/
int Party_CountMembersAtAddr(PartyData_s *party, netadr_t addr, int startSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyClient_GetLargestSplitscreenMemberCount
==============
*/
int PartyClient_GetLargestSplitscreenMemberCount(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_FindMemberByXUID
==============
*/
ClientNum_t Party_FindMemberByXUID(PartyData_s *party, const unsigned __int64 player)
{
	UNIMPLEMENTED(__FUNCTION__);
	ClientNum_t tmp;
	return tmp;
}

/*
==============
Party_FindMemberByController
==============
*/
int Party_FindMemberByController(PartyData_s *party, ControllerIndex_t controller)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_SetVeto
==============
*/
void Party_SetVeto(PartyData_s *party, int vote)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_ClearVotePossible
==============
*/
void Party_ClearVotePossible(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_GetVetoCount
==============
*/
int Party_GetVetoCount(PartyData_s *party, voteWinner_e voteType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_GetReadyCount
==============
*/
int Party_GetReadyCount(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_EnoughClientsAreReady
==============
*/
bool Party_EnoughClientsAreReady(const int ready, const int notReady)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_SetReady
==============
*/
void Party_SetReady(PartyData_s *party, bool ready)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_HowManyReadiesNeeded
==============
*/
int Party_HowManyReadiesNeeded(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_GetPlayerInfoFromMutePlayerList
==============
*/
s_mutePlayerInfo *Party_GetPlayerInfoFromMutePlayerList(unsigned __int64 playerXuid, s_mutePlayerInfo **previousPlayer, s_mutePlayerInfo **previousToPreviousPlayer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Party_AddXuidIntoMutePlayerList
==============
*/
void Party_AddXuidIntoMutePlayerList(unsigned __int64 playerXuid, bool isMuted)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_GetMuteStatusFromMutePlayerList
==============
*/
bool Party_GetMuteStatusFromMutePlayerList(unsigned __int64 playerXuid)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_SetMuteStatusInMutePlayerList
==============
*/
void Party_SetMuteStatusInMutePlayerList(unsigned __int64 playerXuid, bool isMuted)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_ReAddAllPlayers_Internal
==============
*/
void Party_ReAddAllPlayers_Internal(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_MsgPrint
==============
*/
void Party_MsgPrint(netsrc_t sock, netadr_t adr, const char *data, bool doubleSend)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_ShouldDisableLiveStream
==============
*/
bool Party_ShouldDisableLiveStream()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_NetAdrToPlatformNetAdr
==============
*/
char Party_NetAdrToPlatformNetAdr(const netadr_t netAddr, platformNetAdr *platNetAddr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_CompareMemberAdrToPlatformNetAdr
==============
*/
char Party_CompareMemberAdrToPlatformNetAdr(const PartyMember *member, const platformNetAdr *platNetAddr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_FindMember
==============
*/
int Party_FindMember(PartyData_s *party, const platformNetAdr playerAddr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_GetVoiceConnectivityBits
==============
*/
int Party_GetVoiceConnectivityBits(PartyData_s *party, ClientNum_t memberIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_GetAssignedTeam
==============
*/
int Party_GetAssignedTeam(PartyData_s *party, const unsigned __int64 player)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_SetAssignedTeam
==============
*/
void Party_SetAssignedTeam(PartyData_s *party, const unsigned __int64 player, int team)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_GetCustomTeamName
==============
*/
const char *Party_GetCustomTeamName(PartyData_s *party, int team)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Party_SetPlaylistEntryAlways
==============
*/
void Party_SetPlaylistEntryAlways(PartyData_s *party, const int playlistEntry)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_SetPreviousPlaylistEntry
==============
*/
void Party_SetPreviousPlaylistEntry(PartyData_s *party, const int previousPlaylistEntry)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_GetPlaylistEntry
==============
*/
unsigned __int8 Party_GetPlaylistEntry(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_GetPreviousPlaylistEntry
==============
*/
unsigned __int8 Party_GetPreviousPlaylistEntry(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_BlacklistSession
==============
*/
void Party_BlacklistSession(const bdSecurityID *sessionID)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_IsSessionBlacklisted
==============
*/
char Party_IsSessionBlacklisted(const bdSecurityID *sessionID)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_AddSessionToRecentSessionsList
==============
*/
void Party_AddSessionToRecentSessionsList(const bdSecurityID *sessionID)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_IsRecentlyEnteredSession
==============
*/
char Party_IsRecentlyEnteredSession(const bdSecurityID *sessionID)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_ConnectingToDedicated
==============
*/
BOOL Party_ConnectingToDedicated()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_GetLobbySessionFlags
==============
*/
int Party_GetLobbySessionFlags(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_SetDisplayMapName
==============
*/
void Party_SetDisplayMapName(const char *rawmapname)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_SetDisplayGameType
==============
*/
void Party_SetDisplayGameType(const char *rawgametype)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_SetMapPackFlags
==============
*/
void Party_SetMapPackFlags(PartyData_s *party, const int flags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_IsSameNetworkAddress
==============
*/
bool Party_IsSameNetworkAddress(PartyData_s *party, int slot1, int slot2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_CRCPartyFields
==============
*/
int Party_CRCPartyFields(int checksum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_MemberFieldToString
==============
*/
const char *Party_MemberFieldToString(PartyMember *a, PartyField *field)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Party_WriteMemberField
==============
*/
void Party_WriteMemberField(PartyMember *partyMember, msg_t *msg, PartyField *field)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_MemberEqual
==============
*/
char Party_MemberEqual(PartyMember *a, PartyMember *b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_ReadMemberField
==============
*/
void Party_ReadMemberField(PartyMember *partyMember, msg_t *msg, PartyField *field)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_WriteMember
==============
*/
char Party_WriteMember(PartyMember *partyMember, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_ReadMember
==============
*/
bool Party_ReadMember(PartyMember *partyMember, msg_t *msg, bool check)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_SendLeagueStats
==============
*/
void Party_SendLeagueStats(PartyData_s *party, const ControllerIndex_t controllerIndex, int timestamp)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_SetQoSProgress
==============
*/
void Party_SetQoSProgress(PartyData_s *party, float percent, int successfulProbes, int numProbes)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_SwitchToLobby
==============
*/
void PartyClient_SwitchToLobby(ControllerIndex_t localControllerIndex, int menu, bool resetDvars, bool runRules, char *primaryCFG, char *secondaryCFG)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_SwitchLobbiesIfNeeded
==============
*/
void __cdecl PartyClient_SwitchLobbiesIfNeeded(ControllerIndex_t localControllerIndex, PartyData_s *party, ControllerIndex_t resetDvars)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_HasDLCForItem
==============
*/
bool Party_HasDLCForItem(const ClientNum_t clientNum, const int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_ShouldDisplayChangelistWarning
==============
*/
BOOL Party_ShouldDisplayChangelistWarning(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_CheckGivenProbation
==============
*/
void Party_CheckGivenProbation(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_KickIfHasProbation
==============
*/
void Party_KickIfHasProbation(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_ShouldUseLobbyMerging
==============
*/
BOOL Party_ShouldUseLobbyMerging(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyClient_SendPartyStateAck
==============
*/
bool PartyClient_SendPartyStateAck(PartyData_s *party, LocalClientNum_t localClientNum, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyClient_PreParsePartyState
==============
*/
void PartyClient_PreParsePartyState(PartyData_s *party, ControllerIndex_t localControllerIndex, msg_t *msg, netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_IsRunning
==============
*/
BOOL Party_IsRunning(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_InParty
==============
*/
BOOL Party_InParty(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_AreWeHost
==============
*/
int Party_AreWeHost(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_AreWeHostEvenIfInactive
==============
*/
BOOL Party_AreWeHostEvenIfInactive(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_IsHostController
==============
*/
bool Party_IsHostController(PartyData_s *party, ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyClient_MarkPacketReceived
==============
*/
void PartyClient_MarkPacketReceived(PartyData_s *party, PartyHostDetails *partyHost)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_PacketIsFromAcceptedHost
==============
*/
int Party_PacketIsFromAcceptedHost(PartyData_s *party, const netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_GetConnectivityBitsForAddr
==============
*/
int Party_GetConnectivityBitsForAddr(PartyData_s *party, const netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_GetConnectivityBitsForClientAddress
==============
*/
int Party_GetConnectivityBitsForClientAddress(PartyData_s *party, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_RebuildConnectionToClient
==============
*/
char Party_RebuildConnectionToClient(PartyData_s *party, ClientNum_t destClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyClient_GenerateHeartBeatAckMessage
==============
*/
void PartyClient_GenerateHeartBeatAckMessage(PartyData_s *party, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_HandleReconnect
==============
*/
void PartyClient_HandleReconnect(PartyData_s *party, ControllerIndex_t localControllerIndex, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_HandleVoiceFailMsg
==============
*/
void Party_HandleVoiceFailMsg(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_ResetReportedConnStates
==============
*/
void Party_ResetReportedConnStates()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_SendFinishedLoadingDemoMsg
==============
*/
void Party_SendFinishedLoadingDemoMsg(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_HandleStopDemoMsg
==============
*/
void PartyClient_HandleStopDemoMsg(PartyData_s *party, const ControllerIndex_t localControllerIndex, netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_HandleDemoHeartbeatMsg
==============
*/
void PartyClient_HandleDemoHeartbeatMsg(PartyData_s *party, const ControllerIndex_t localControllerIndex, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_HandleLeagueStatsRequest
==============
*/
void Party_HandleLeagueStatsRequest(PartyData_s *party, const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_HandleLeagueOutcomes
==============
*/
void Party_HandleLeagueOutcomes(PartyData_s *party, const ControllerIndex_t localControllerIndex, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_HandleChallengeAck
==============
*/
void PartyClient_HandleChallengeAck(PartyData_s *party, ControllerIndex_t localControllerIndex, netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_HandlePacket
==============
*/
BOOL Party_HandlePacket(PartyData_s *party, const char *c, ControllerIndex_t localControllerIndex, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_SwitchLobbiesIfNeeded_f
==============
*/
void Party_SwitchLobbiesIfNeeded_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_StateChanged_f
==============
*/
void Party_StateChanged_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_MinLobbyTime
==============
*/
int Party_MinLobbyTime()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_UpdateLobbyStatusRequired
==============
*/
char Party_UpdateLobbyStatusRequired(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_GetPreGameStartTimerLength
==============
*/
int Party_GetPreGameStartTimerLength()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_GetGameStartTimerLength
==============
*/
int Party_GetGameStartTimerLength()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_GetRestartMatchmakingTimer
==============
*/
int Party_GetRestartMatchmakingTimer()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_IsPostGameLobby
==============
*/
BOOL Party_IsPostGameLobby(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_GetAffinityBits
==============
*/
void Party_GetAffinityBits(PartyData_s *party, const ControllerIndex_t localControllerIndex, unsigned int *affinityBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_UpdateLocalClient
==============
*/
void Party_UpdateLocalClient(PartyData_s *party, const ControllerIndex_t localControllerIndex, int memberIndex, PartyMember *member)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FindFreeTempBanSlot
==============
*/
int FindFreeTempBanSlot()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_ClearTempBannedXuidList
==============
*/
void Party_ClearTempBannedXuidList()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_IsInTempBannedXuidList
==============
*/
int Party_IsInTempBannedXuidList(unsigned __int64 xuid)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_AddToTempBannedXuidList
==============
*/
void Party_AddToTempBannedXuidList(unsigned __int64 xuid)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_IsPrivateOnlineGame
==============
*/
bool __cdecl Party_IsPrivateOnlineGame()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_IsGameLobbyHost
==============
*/
int Party_IsGameLobbyHost()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_IsTeamAllowed
==============
*/
bool Party_IsTeamAllowed(PartyData_s *party, team_t team, bool isSplitscreenClient)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_GetPartyData
==============
*/
PartyData_s *Party_GetPartyData()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Party_SetWeAreHost
==============
*/
void Party_SetWeAreHost(PartyData_s *party, bool weAreHost)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_GetMaxPlayers
==============
*/
int Party_GetMaxPlayers()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_GetMaxLocalPlayers
==============
*/
int Party_GetMaxLocalPlayers()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_SetMaxPlayers
==============
*/
void Party_SetMaxPlayers(PartyData_s *party, int count)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_SetMaxLocalPlayers
==============
*/
void Party_SetMaxLocalPlayers(PartyData_s *party, int count)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_IsUserRegistered
==============
*/
BOOL Party_IsUserRegistered(PartyData_s *party, ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_DispatchInstantMessage
==============
*/
bool Party_DispatchInstantMessage(unsigned __int64 senderID, const ControllerIndex_t destIndex, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_GetPartyAverageSkill
==============
*/
double Party_GetPartyAverageSkill(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_BroadcastLeagueEmblemChange
==============
*/
void Party_BroadcastLeagueEmblemChange(ControllerIndex_t controllerIndex, unsigned __int64 teamID)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_CurrentDesiredLobbyMapPackFlags
==============
*/
int Live_CurrentDesiredLobbyMapPackFlags(const int playlistId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_PartyMembersMissingMapPack
==============
*/
char Party_PartyMembersMissingMapPack(PartyData_s *party, int neededPacks, int *playerSlot, int *mapPackIndex, bool requireAtleastTwoPeople)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_IsAnyMemberMissingMapPack
==============
*/
char Party_IsAnyMemberMissingMapPack()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyClient_RemovePartyMember
==============
*/
void PartyClient_RemovePartyMember(PartyData_s *party, ClientNum_t slot, bool swapped)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_RemoveAllPartyMembersAtSlotAddress
==============
*/
void PartyClient_RemoveAllPartyMembersAtSlotAddress(PartyData_s *party, ClientNum_t slot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_ReRegisterAllPlayersVoice
==============
*/
void Party_ReRegisterAllPlayersVoice(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_ReAddAllPlayers
==============
*/
void Party_ReAddAllPlayers(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_DisconnectLocalPlayerFromHost
==============
*/
void PartyClient_DisconnectLocalPlayerFromHost(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_ProposeNewGamestate
==============
*/
void PartyClient_ProposeNewGamestate(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_FindMember
==============
*/
int Party_FindMember(PartyData_s *party, const netadr_t playerAddr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyClient_HandleLocalJoinFailed
==============
*/
void PartyClient_HandleLocalJoinFailed(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_RequestLocalJoin
==============
*/
void PartyClient_RequestLocalJoin(PartyData_s *party, int partyId, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_JoinLocalClientsToParty_Internal
==============
*/
void PartyClient_JoinLocalClientsToParty_Internal(PartyData_s *party, netadr_t partyHost, unsigned int challenge)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_IsChangeTeamAllowed
==============
*/
bool Party_IsChangeTeamAllowed(PartyData_s *party, team_t team, bool isSplitscreenClient)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_UpdateTeamSwitch
==============
*/
void Party_UpdateTeamSwitch(team_t a1, PartyData_s *a2, char *party, PartyData_s *memberIndex, ClientNum_t a5)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_MemberProfileChanged
==============
*/
void Party_MemberProfileChanged(PartyData_s *party, const ControllerIndex_t localControllerIndex, ClientNum_t memberIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Part_PartyState_SetMaxPlayers
==============
*/
void Part_PartyState_SetMaxPlayers(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyHost_ResetState
==============
*/
void PartyHost_ResetState(PartyData_s *party, const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_BecomePartyHost
==============
*/
void PartyClient_BecomePartyHost(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_ShowMatchBeginTimer
==============
*/
bool Party_ShowMatchBeginTimer(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Party_GetStatus_ZombiePublicSoloMatch
==============
*/
const char *Party_GetStatus_ZombiePublicSoloMatch(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Party_GetStatus
==============
*/
const char *Party_GetStatus(PartyData_s *party, int *timeRemaining)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Party_ClearJoinParty
==============
*/
void Party_ClearJoinParty(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_CleanUpInviteSessions
==============
*/
void PartyClient_CleanUpInviteSessions(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_DisconnectFromHost
==============
*/
void PartyClient_DisconnectFromHost(PartyData_s *party, ControllerIndex_t localControllerIndex, const char *reason, bool keepPartyTogether, bool createParty)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_StopParty
==============
*/
void Party_StopParty(PartyData_s *party, bool keepPartyTogether, bool deleteSessionImmediately)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_StopParty
==============
*/
void Party_StopParty(bool a1, PartyData_s *a2, PartyData_s *party, bool keepPartyTogether)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_JoinAttemptFailed
==============
*/
void Party_JoinAttemptFailed(PartyData_s *party, const ControllerIndex_t localControllerIndex, const char *errorMsg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_CheckPlaylistRules
==============
*/
char Party_CheckPlaylistRules(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyClient_ParsePartyStateHeaderData
==============
*/
void PartyClient_ParsePartyStateHeaderData(PartyData_s *party, ControllerIndex_t localControllerIndex, msg_t *msg, netadr_t from, bool migrateHost)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_ParseMemberList
==============
*/
void PartyClient_ParseMemberList(PartyData_s *party, ControllerIndex_t localControllerIndex, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_SetUpPartyForHost
==============
*/
void PartyClient_SetUpPartyForHost(PartyData_s *party, const ControllerIndex_t localControllerIndex, PartyHostDetails *hostInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_HandleBadLeague
==============
*/
void __cdecl PartyClient_HandleBadLeague(PartyData_s *party, const ControllerIndex_t localControllerIndex, netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_HandleKicked
==============
*/
void PartyClient_HandleKicked(PartyData_s *party, const ControllerIndex_t localControllerIndex, netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_PartyAwakeMsg
==============
*/
void PartyClient_PartyAwakeMsg(int a1, PartyData_s *party, ControllerIndex_t localControllerIndex, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_LeaderLeftMsg
==============
*/
void PartyClient_LeaderLeftMsg(PartyData_s *party, ControllerIndex_t localControllerIndex, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_CheckPlaylistCmd
==============
*/
void Party_CheckPlaylistCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_Init
==============
*/
void Party_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_Sleep
==============
*/
void __cdecl Party_Sleep(PartyData_s *party)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_SetupPlayList
==============
*/
void Party_SetupPlayList(const ControllerIndex_t localControllerIndex, int entryNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_ChooseNextPlaylist
==============
*/
void Party_ChooseNextPlaylist(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_ChooseNextAndPreviousPlaylist
==============
*/
void Party_ChooseNextAndPreviousPlaylist(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_ChoosePreviousPlaylist
==============
*/
void Party_ChoosePreviousPlaylist()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_HostTimedOut
==============
*/
void PartyClient_HostTimedOut(PartyData_s *party, ControllerIndex_t localControllerIndex, const char *reason)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_HostTimedOutMidGame
==============
*/
void __cdecl PartyClient_HostTimedOutMidGame(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_DoneParsingPartyState
==============
*/
void PartyClient_DoneParsingPartyState(PartyData_s *party, ControllerIndex_t localControllerIndex, msg_t *msg, netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_SendHeartbeatAck
==============
*/
void PartyClient_SendHeartbeatAck(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_AllLocalClientsSendHeartbeatAck
==============
*/
void PartyClient_AllLocalClientsSendHeartbeatAck(PartyData_s *party, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_HandleHeartbeat
==============
*/
void PartyClient_HandleHeartbeat(PartyData_s *party, ControllerIndex_t localControllerIndex, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_HandleNewLobby
==============
*/
void PartyClient_HandleNewLobby(PartyData_s *party, ControllerIndex_t localControllerIndex, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_HandleEndParty
==============
*/
void __cdecl PartyClient_HandleEndParty(PartyData_s *party, const ControllerIndex_t localControllerIndex, netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_HandleEndPartyKeepPartyTogether
==============
*/
void __cdecl PartyClient_HandleEndPartyKeepPartyTogether(PartyData_s *party, const ControllerIndex_t localControllerIndex, netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_ParsePartyStateMsg
==============
*/
bool PartyClient_ParsePartyStateMsg(PartyData_s *party, const ControllerIndex_t localControllerIndex, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyClient_HandlePartyStateMsg
==============
*/
void PartyClient_HandlePartyStateMsg(char *a1, PartyData_s *party, const ControllerIndex_t localControllerIndex, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_HandleGoMsg
==============
*/
void PartyClient_HandleGoMsg(PartyData_s *party, const ControllerIndex_t localControllerIndex, netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyClient_HandlePlayDemoMsg
==============
*/
void PartyClient_HandlePlayDemoMsg(PartyData_s *party, const ControllerIndex_t localControllerIndex, netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Party_Awake
==============
*/
void Party_Awake(PartyData_s *party, const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

