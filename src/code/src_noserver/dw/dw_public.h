#pragma once

#include "types.h"

//t6/code/src_noserver/dw/dwmatchmaking.cpp
void checkForBadGeoInfo(MatchMakingInfo *sessionInfo, TaskRecord *task);
void dwCreateSession(TaskRecord *task, MatchMakingInfo *const sessionInfo);
void dwUpdateSession(TaskRecord *task, MatchMakingInfo *const sessionInfo);
void dwDeleteSession(ControllerIndex_t controllerIndex, TaskRecord *task);

//t6/code/src_noserver/dw/dwmessaging.cpp
char dwInstantHandleTestMessage(unsigned __int64 senderID, const ControllerIndex_t controllerIndex, msg_t *msg);
bool dwInstantHandlePartyMessage(;
bool dwInstantHandleFriendMessage(;
bool dwInstantDispatchMessage_Internal(;
// void __thiscall dwLobbyEventHandler::onNewNotification(dwLobbyEventHandler *this);
// void __thiscall dwLobbyEventHandler::onTeamProposal(dwLobbyEventHandler *this);
// void __thiscall dwLobbyEventHandler::onPlayerBanned(;
// void __thiscall dwLobbyEventHandler::onMultipleLogon(dwLobbyEventHandler *this, unsigned __int64 userID);
// void __thiscall dwLobbyEventHandler::onYouTubeRegistration(;
// void __thiscall dwLobbyEventHandler::onGlobalInstantMessage(;
void dwInitMessaging(ControllerIndex_t controllerIndex);
TaskRecord *dwInstantSendMessage(;
void dwInstantSendTestMessage();
char dwProcessNotifications(TaskRecord *task);
// void __thiscall dwLobbyEventHandler::onChallengesReceived(;

//t6/code/src_noserver/dw/dwnet.cpp
bdSecurityID *FindCommonAddrGroup(const bdSecurityID *id);
unsigned int CommonAddrToInAddr(CommonAddrGroup *group, CommonAddr *addr);
const char *PacketSummaryString(const void *dataVoid, int length);
bool InAddrToCommonAddr(unsigned int inaddr, CommonAddrGroup **resultGroup, CommonAddr **resultAddr);
int dwCheckConnections();
// bdReference<bdAddrHandle> *dwNetadrToAddrHandle(;
char dwNetadrToCommonAddr(;
unsigned int dwCommonAddrToString(;
in_addr dwCommonAddrToInAddr(const unsigned __int8 *commonAddrBuf, const unsigned int commonAddrBufSize);
int dwGetConnectionTaskStatus(netadr_t *const netadr);
void dwPrintAddrGroups();
void dwNetInit();
const char *RegisterCommonAddrGroup(const bdSecurityID *id);
const char *UnregisterCommonAddrGroup(const bdSecurityID *id);
unsigned int RegisterEndpoint(const bdEndpoint *endpoint, const char **errorMsg);
const char *DeregisterEndpoint(const bdEndpoint *endpoint);
bool dwRegisterSecIDAndKey(const bdSecurityID *id, const bdSecurityKey *key);
int dwSendTo(const unsigned int length, const void *data, const netadr_t to);
int dwRecvFrom(netadr_t *const from, void *const data, const unsigned int size);
char dwCommonAddrToNetadr(;
void dwUnregisterSecIDAndKey(const bdSecurityID *id);
char dwCloseConnection(netadr_t *const netadr);
void ClearCommonAddrGroups();
void dwNetStop();
void dwNetPump();
void dwNetStart(const bool online);

//t6/code/src_noserver/dw/dwqos.cpp
// LocalTaskState __thiscall dwQoSMultiProbeListener::complete(dwQoSMultiProbeListener *this);
void dwClearQoSProbes();
// void __thiscall dwQoSMultiProbeListener::onQoSProbeFail(dwQoSMultiProbeListener *this, bdReference<bdCommonAddr> addr);
// void __thiscall dwQoSMultiProbeListener::clean(dwQoSMultiProbeListener *this);
// void __thiscall dwQoSMultiProbeListener::dwQoSMultiProbeListener(dwQoSMultiProbeListener *this);
// void __thiscall dwQoSMultiProbeListener::addProbe(dwQoSMultiProbeListener *this, const bdQoSRemoteAddr addr);
// void __thiscall dwQoSMultiProbeListener::onQoSProbeSuccess(dwQoSMultiProbeListener *this, const bdQoSProbeInfo *info);
void dwStartQoSProbes(;

//t6/code/src_noserver/dw/dwrecordevent.cpp
bdRemoteTask *dwRecordEventMixed(;
bdRemoteTask *dwRecordEvent(;
bdRemoteTask *dwRecordEventString(ControllerIndex_t controllerIndex, RecordEventType type, const char *event);
bdRemoteTask *dwRecordEventFormat(ControllerIndex_t controllerIndex, RecordEventType type, const char *fmt, ...);

//t6/code/src_noserver/dw/dwstats.cpp
TaskRecord *dwWriteStats(;
TaskRecord *dwReadStatsByRank(;
TaskRecord *dwReadStatsForUsersFromLbs(;

//t6/code/src_noserver/dw/dwstorage.cpp
void dwFileShareGetProgress(;
void dwFileShareAbortOperation(ControllerIndex_t localControllerIndex, fileShareLocation location);
bool dwFileShareIsReady(const ControllerIndex_t localControllerIndex);
int dwFileShareGetLastHTTPError(ControllerIndex_t localControllerIndex, fileShareLocation location);
TaskRecord *dwGetFileMetadata(const ControllerIndex_t controllerIndex, dwFileMetadata *metadata);
char dwReadFileFailure(TaskRecord *task);
char dwReadFileSuccess(TaskRecord *task);
TaskRecord *dwReadFileInternal(;
// TaskRecord *dwReadFile@<eax>(;
// TaskRecord *dwReadUserFile@<eax>(;
TaskRecord *dwReadUserFileByUserID(;
char dwDeleteFileFailure(TaskRecord *task);
char dwWriteFileFailure(TaskRecord *task);
TaskRecord *dwWriteFile(;
TaskRecord *dwFileShareGetListing(ControllerIndex_t localControllerIndex, dwFileShareListTask *const fsTask);
TaskRecord *dwFileShareGetDescriptorsFromPooledStorage(;
TaskRecord *dwFileShareGetDescriptorsFromUserStorage(;
// TaskRecord *dwFileShareGetDescriptors@<eax>(;
TaskRecord *dwFileShareReadPooledStorageFile(;
TaskRecord *dwFileShareReadUserStorageFile(;
TaskRecord *dwFileShareReadPublisherStorageFile(;
// TaskRecord *dwFileShareReadFile@<eax>(;
TaskRecord *dwFileShareRemoveFile(ControllerIndex_t controllerIndex, dwFileShareRemoveTask *const fsTask);
TaskRecord *dwFileShareTransferFile(ControllerIndex_t controllerIndex, dwFileShareTransferTask *const fsTask);
TaskRecord *dwFileShareGetPooledSummary(;
TaskRecord *dwFileShareGetUserSummary(;
// TaskRecord *dwFileShareGetSummary@<eax>(;
TaskRecord *dwFileShareSetPooledSummary(;
TaskRecord *dwFileShareSetUserSummary(ControllerIndex_t controllerIndex, dwFileShareSummaryTask *const fsTask);
TaskRecord *dwFileShareSetSummary(ControllerIndex_t controllerIndex, dwFileShareSummaryTask *const fsTask);
TaskRecord *dwFileShareWritePooledStorageFile(;
TaskRecord *dwFileShareWriteUserStorageFile(;
// TaskRecord *dwFileShareWriteFile@<eax>(;
TaskRecord *dwKeyArchiveRead(;

//t6/code/src_noserver/dw/dwteam.cpp
TaskRecord *dwTeamClanLeave(const ControllerIndex_t localControllerIndex, dwTeamClanLeaveTask *const teamTask);
TaskRecord *dwTeamClanCreate(;
TaskRecord *dwTeamSetPublicProfile(;
TaskRecord *dwTeamSetPrivateProfile(;

//t6/code/src_noserver/dw/dwtwitch.cpp
TaskRecord *dwTwitchRegisterAccount(ControllerIndex_t localControllerIndex, dwTwitchRegisterTask *const twTask);
TaskRecord *dwTwitchUnregisterAccount(ControllerIndex_t localControllerIndex);

//t6/code/src_noserver/dw/dwutils.cpp
bool dwGetOnlineUserID(const ControllerIndex_t controllerIndex, unsigned __int64 *userID);
bool dwGetOnlineUserName(ControllerIndex_t controllerIndex, char *buf, const unsigned int bufsize);
bdLobbyService *dwGetLobby(ControllerIndex_t controllerIndex);
bdMatchMaking *dwGetMatchmaking(ControllerIndex_t controllerIndex);
bdGroup *dwGetGroup(ControllerIndex_t controllerIndex);
bdContentStreaming *dwGetContentStreaming(ControllerIndex_t controllerIndex);
bdPooledStorage *dwGetPooledStorage(ControllerIndex_t controllerIndex);
bdTwitch *dwGetTwitchService(ControllerIndex_t controllerIndex);
bdLeague *dwGetLeagueService(ControllerIndex_t controllerIndex);
bdVoteRank *dwGetVoteRankService(ControllerIndex_t controllerIndex);
bdYouTube *dwGetYouTubeService(ControllerIndex_t controllerIndex);
bdStorage *dwGetStorage(ControllerIndex_t controllerIndex);
bdAntiCheat *dwGetAntiCheat(ControllerIndex_t controllerIndex);
bdKeyArchive *dwGetKeyArchive(ControllerIndex_t controllerIndex);
bdStats *dwGetStats(ControllerIndex_t controllerIndex);
bdTeams *dwGetTeams(ControllerIndex_t controllerIndex);
bdAuthService *dwGetAuthService(;
bdTitleUtilities *dwGetTitleUtilities(ControllerIndex_t controllerIndex);
bdEventLog *dwGetEventLog(ControllerIndex_t controllerIndex);
bdMessaging *dwGetMessaging(ControllerIndex_t controllerIndex);
const char *dwLobbyErrorCodeToString(const bdLobbyErrorCode code);
void dwConnectionErrorHandler(int error_context);
bool dwRecordIPAddressSuccess(TaskRecord *task);
bool dwRecordIPAddressComplete();
char dwRecordIPAddressFailure(TaskRecord *task);
void dwCreateLobby(ControllerIndex_t controllerIndex);
// void dwCloseRemoteTask(bdReference<bdRemoteTask> *remoteTask);
void dwLobbyErrorCodeToString(const bdLobbyErrorCode code, char *const buffer, const unsigned int bufferSize);
void dwRecordIPAddressRequest(const ControllerIndex_t controllerIndex, unsigned __int8 *ipArray);
void dwRecordIPAddress(const ControllerIndex_t controllerIndex);
bdSocketRouter *dwGetSocketRouter();
bdAddressMap *dwGetAddressMap();
bdQoSProbe *dwGetQoSProbe();
// bdReference<bdCommonAddr> *dwGetLocalCommonAddr(bdReference<bdCommonAddr> *result);
bdSecurityKeyMap *dwGetSecurityKeyMap();

//t6/code/src_noserver/dw/dwvote.cpp
bool dwVoteGetRatio(;
TaskRecord *dwVoteSubmitRating(;

//t6/code/src_noserver/dw/dwyoutube.cpp
TaskRecord *dwYouTubeRegisterAccount(;
TaskRecord *dwYouTubeUnregisterAccount(const ControllerIndex_t localControllerIndex);
TaskRecord *dwYouTubeIsRegistered(;
TaskRecord *dwYouTubeUpload(const ControllerIndex_t localControllerIndex, dwYouTubeUploadTask_t *ytTask);

//t6/code/src_noserver/dw/leaderboardinfo.cpp
// void __thiscall LeaderboardFileShareRow::LeaderboardFileShareRow(LeaderboardFileShareRow *this);
// char LeaderboardFileShareRow::setColumnCount(int columnCount);
// unsigned int __thiscall LeaderboardFileShareRow::sizeOf(LeaderboardFileShareRow *this);
// bool __thiscall LeaderboardFileShareRow::deserialize(LeaderboardFileShareRow *this, bdReference<bdByteBuffer> buffer);

//#include "dw/leaderboardinfo.h"

//t6/code/src_noserver/dw/matchmakinginfo.cpp
// void __thiscall MatchMakingInfo::MatchMakingInfo(MatchMakingInfo *this);
// void __thiscall MatchMakingInfo::serialize(MatchMakingInfo *this, bdByteBuffer *buffer);
// char __thiscall MatchMakingInfo::setSecurityID(MatchMakingInfo *this, const bdSecurityID *secID);
// char __thiscall MatchMakingInfo::getSecurityID(MatchMakingInfo *this, bdSecurityID *secID);
// char __thiscall MatchMakingInfo::setSecurityKey(MatchMakingInfo *this, const bdSecurityKey *secKey);
// char __thiscall MatchMakingInfo::getSecurityKey(MatchMakingInfo *this, bdSecurityKey *secKey);
// unsigned int __thiscall MatchMakingInfo::sizeOf(MatchMakingInfo *this);
// bool __thiscall MatchMakingInfo::doUpdate(;
// bool __thiscall MatchMakingInfo::deserialize(MatchMakingInfo *this, bdReference<bdByteBuffer> buffer);

//t6/code/src_noserver/dw/matchrecorder.cpp
void MatchRecorderDDLSetFloat(ddlState_t *searchState, const char *name, float value);
void MatchRecorderDDLSetInt(ddlState_t *searchState, const char *name, unsigned int value);
unsigned int MatchRecorderDDLGetInt(ddlState_t *searchState, const char *name);
void MatchRecorderDDLSetInt64(ddlState_t *searchState, const char *name, unsigned __int64 value);
unsigned __int64 MatchRecorderDDLGetInt64(ddlState_t *searchState, const char *name);
void MatchRecorderDDLSetString(ddlState_t *searchState, const char *name, const char *value);
void MatchRecordCopyExternalIP(ddlState_t playerState, ClientNum_t clientNum);
int GetCurrentMapIndexByUIMapname();
int GetCurrentMapIndex();
void setWeaponHashValue(const char *statName, int limit, int index);
char isTrackableWeapon(int index, int currentMapIndex);
bool MatchRecord_IsHeatMapDataGenerated();
int GetMaxLivesOrDowns();
unsigned int MatchRecord_GetMapIndex();
void MatchRecord_SetPlayerCount(__int16 currentPlayers);
unsigned int MatchRecord_GetLifeCount();
void MatchRecord_SetLifeCount(__int16 currentLives);
void MatchRecord_SetDownCount(__int16 currentLives);
bool MatchRecord_GetPlayerInSlot(int playerSlot, ddlState_t *playerSlotState);
int MatchRecord_SearchForPlayerSlotByXUID(unsigned __int64 xuid);
unsigned __int64 MatchRecord_GetXUIDForPlayerSlot(int playerSlot);
bool MatchRecord_GetLifeInSlot(int lifeSlot, ddlState_t *lifeSlotState);
bool MatchRecord_GetDownInSlot(int downSlot, ddlState_t *downSlotState);
void MatchRecorder_UpdateSubparties();
int MatchRecord_SearchCreateForPlayer(gclient_t *client, ddlState_t *playerState);
;
void FindBitchForPlayer(int attackingPlayerSlot);
void FindNemesisForPlayer(int attackingPlayerSlot);
void SaveTeamScores();
void MatchRecorder_RecordGameResult(team_t winner, bool isDraw);
void GetWorldLocation(;
void MatchRecord_ReviveZombie(gclient_t *client, gclient_t *reviver);
void MatchRecordSpawn(gclient_t *client);
void MatchRecordSetHitStat(;
void MatchRecordHit(gclient_t *attackerClient, hitLocation_t hitLocation);
void MatchRecordDeath(;
void MatchRecordEnd(gclient_t *client);
void MatchRecordBegin();
void MatchRecordPlayerDetails(gclient_t *client, const char *reason);
void MatchRecordSetPlayerStat(gclient_t *client, const char *statName, int statValue);
char MatchRecordEventFailure();
void MatchRecorder_TagXuids(int *numTags, bdTag *tags, int maxTags);
void MatchRecorder_RecordKillstreakEvent(;
void MatchRecorder_RecordKillstreakEndEvent(;
void MatchRecorder_RecordGameEvent(;
void MatchRecorder_RecordKillModifier(;
void MatchRecorder_RecordScoreEvent(;
void MatchRecorder_RecordLoadoutAndPerks(;
void MatchRecorder_RecordNumZombieRounds(ddlState_t *a1, const char *a2);
void MatchRecorder_RecordMultiKill(;
void MatchRecord_WriteItemStats(;
// void MatchRecorder_IncrementHeaderStat(const char *a1@<edx>, ddlState_t *a2@<ecx>, const char *statName);
void MatchRecorder_RecordZombieGameInfoEnd(;
void MatchRecorder_RecordZombiePlayerDeath();
// void MatchRecorder_RecordZombiePlayerDown(float a1@<ebx>, unsigned __int8 *a2@<edi>, gclient_t *client);
bool IsPlayerInRound(unsigned __int64 xuid, ddlState_t *roundState);
bool GetPlayerRoundSlot(unsigned __int64 xuid, ddlState_t *playerRoundSlot);
void MatchRecord_ZombieRoundStart(ddlState_t *a1, const char *a2);
void MatchRecord_ZombieRoundEnd(ddlState_t *a1, const char *a2);
void MatchRecorder_IncrementPlayerStat(gclient_t *client, const char *statName);
int MatchRecord_InitMatchDataInternal(char *inputBuffer, int buffSize);
void MatchRecord_InitMatchData();
void GenerateBinaryMatchSummary(unsigned int titleID, const char *gameMode, unsigned __int64 fileID);
void GenerateRecordedMatchData(;
// BOOL MatchRecord_ParseDownloadedMatchData@<eax>(;
void MatchRecordPointsSpent(;
char MatchRecordEventSuccess(TaskRecord *task);

//t6/code/src_noserver/dw/teamprofile.cpp
// void __thiscall PublicTeamProfile::PublicTeamProfile(PublicTeamProfile *this);
// void __thiscall PublicTeamProfile::serialize(PublicTeamProfile *this, bdByteBuffer *buffer);
// void __thiscall PrivateTeamProfile::PrivateTeamProfile(PrivateTeamProfile *this);
// void __thiscall PrivateTeamProfile::serialize(PrivateTeamProfile *this, bdByteBuffer *buffer);
// unsigned int __thiscall PublicTeamProfile::sizeOf(PublicTeamProfile *this);
// unsigned int __thiscall PrivateTeamProfile::sizeOf(PrivateTeamProfile *this);
// bool __thiscall PublicTeamProfile::deserialize(PublicTeamProfile *this, bdReference<bdByteBuffer> buffer);
// bool __thiscall PrivateTeamProfile::deserialize(PrivateTeamProfile *this, bdReference<bdByteBuffer> buffer);

