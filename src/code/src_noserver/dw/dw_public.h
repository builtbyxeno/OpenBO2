#pragma once

#include "types.h"

//t6/code/src_noserver/dw/dwmatchmaking.cpp
void checkForBadGeoInfo(MatchMakingInfo *sessionInfo, TaskRecord *task);
void dwCreateSession(TaskRecord *task, MatchMakingInfo *const sessionInfo);
void dwUpdateSession(TaskRecord *task, MatchMakingInfo *const sessionInfo);
void dwDeleteSession(ControllerIndex_t controllerIndex, TaskRecord *task);

//t6/code/src_noserver/dw/dwmessaging.cpp
char dwInstantHandleTestMessage(unsigned __int64 senderID, const ControllerIndex_t controllerIndex, msg_t *msg);
bool dwInstantHandlePartyMessage(unsigned __int64 senderID, const ControllerIndex_t controllerIndex, msg_t *msg);
bool dwInstantHandleFriendMessage(unsigned __int64 senderID, const ControllerIndex_t controllerIndex, msg_t *msg);
bool dwInstantDispatchMessage_Internal(unsigned __int64 senderID, const ControllerIndex_t controllerIndex, void *message, unsigned int messageSize);
// void __thiscall dwLobbyEventHandler::onNewNotification(dwLobbyEventHandler *this);
// void __thiscall dwLobbyEventHandler::onTeamProposal(dwLobbyEventHandler *this);
// void __thiscall dwLobbyEventHandler::onPlayerBanned(dwLobbyEventHandler *this, unsigned __int64 userID, unsigned int reputationLevel);
// void __thiscall dwLobbyEventHandler::onMultipleLogon(dwLobbyEventHandler *this, unsigned __int64 userID);
// void __thiscall dwLobbyEventHandler::onYouTubeRegistration(dwLobbyEventHandler *this, const bdYouTubeRegistrationResult *registrationResult);
// ;
void dwInitMessaging(ControllerIndex_t controllerIndex);
TaskRecord *dwInstantSendMessage(ControllerIndex_t controllerIndex, const unsigned __int64 *recipientUIDs, unsigned int numRecipients, char msgType, const void *message, unsigned int msgSize);
void dwInstantSendTestMessage();
char dwProcessNotifications(TaskRecord *task);
// void __thiscall dwLobbyEventHandler::onChallengesReceived(dwLobbyEventHandler *this, unsigned __int64 userID, bdReference<bdAntiCheatChallenges> challenges);

//t6/code/src_noserver/dw/dwnet.cpp
bdSecurityID *FindCommonAddrGroup(const bdSecurityID *id);
unsigned int CommonAddrToInAddr(CommonAddrGroup *group, CommonAddr *addr);
const char *PacketSummaryString(const void *dataVoid, int length);
bool InAddrToCommonAddr(unsigned int inaddr, CommonAddrGroup **resultGroup, CommonAddr **resultAddr);
int dwCheckConnections();
// bdReference<bdAddrHandle> *dwNetadrToAddrHandle(bdReference<bdAddrHandle> *result, const netadr_t *const netadr);
char dwNetadrToCommonAddr(char *a1, netadr_t netadr, unsigned __int8 *commonAddrBuf, const unsigned int commonAddrBufSize, bdSecurityID *const id);
unsigned int dwCommonAddrToString(const unsigned __int8 *commonAddrBuf, const unsigned int commonAddrBufSize, char *buf, const unsigned int length);
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
char dwCommonAddrToNetadr(netadr_t *const netadr, const unsigned __int8 *const commonAddrBuf, const bdSecurityID *secID);
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
void dwStartQoSProbes(dwQoSMultiProbeListener *listener, const unsigned int numProbes, XSESSION_INFO *xenonsInfo);

//t6/code/src_noserver/dw/dwrecordevent.cpp
bdRemoteTask *dwRecordEventMixed(ControllerIndex_t controllerIndex, RecordEventType type, bool isBinary, unsigned __int8 *buff, int buffSize);
bdRemoteTask *dwRecordEvent(ControllerIndex_t controllerIndex, RecordEventType type, const void *buff, int buffSize);
bdRemoteTask *dwRecordEventString(ControllerIndex_t controllerIndex, RecordEventType type, const char *event);
bdRemoteTask *dwRecordEventFormat(ControllerIndex_t controllerIndex, RecordEventType type, const char *fmt, ...);

//t6/code/src_noserver/dw/dwstats.cpp
TaskRecord *dwWriteStats(const ControllerIndex_t controllerIndex, bdStatsInfo **statsInfo, const unsigned int numStats);
TaskRecord *dwReadStatsByRank(const ControllerIndex_t controllerIndex, const unsigned int leaderboardID, const unsigned int topRank, const unsigned int maxResults, bdStatsInfo *statsInfo, int timeOut);
TaskRecord *dwReadStatsForUsersFromLbs(const ControllerIndex_t controllerIndex, const unsigned int *leaderboardIDs, const unsigned int numLeaderboards, const unsigned __int64 *entityIDs, const unsigned int numEntityIDs, bdStatsInfoEx **statsInfo, int timeOut);

//t6/code/src_noserver/dw/dwstorage.cpp
void dwFileShareGetProgress(ControllerIndex_t localControllerIndex, unsigned int *bytes, float *dataRate, fileShareLocation location);
void dwFileShareAbortOperation(ControllerIndex_t localControllerIndex, fileShareLocation location);
bool dwFileShareIsReady(const ControllerIndex_t localControllerIndex);
int dwFileShareGetLastHTTPError(ControllerIndex_t localControllerIndex, fileShareLocation location);
TaskRecord *dwGetFileMetadata(const ControllerIndex_t controllerIndex, dwFileMetadata *metadata);
char dwReadFileFailure(TaskRecord *task);
char dwReadFileSuccess(TaskRecord *task);
TaskRecord *dwReadFileInternal(ControllerIndex_t localControllerIndex, dwFileTask *const fileTask, bool userFile, unsigned __int64 ownerUID);
;
;
;
char dwDeleteFileFailure(TaskRecord *task);
char dwWriteFileFailure(TaskRecord *task);
TaskRecord *dwWriteFile(ControllerIndex_t localControllerIndex, const char *const filename, void *data, const unsigned int dataSize, bdFileInfo *fileInfo, unsigned __int64 ownerID);
TaskRecord *dwFileShareGetListing(ControllerIndex_t localControllerIndex, dwFileShareListTask *const fsTask);
TaskRecord *dwFileShareGetDescriptorsFromPooledStorage(ControllerIndex_t localControllerIndex, dwFileShareDescriptorsTask *const fsTask);
TaskRecord *dwFileShareGetDescriptorsFromUserStorage(ControllerIndex_t localControllerIndex, dwFileShareDescriptorsTask *const fsTask);
TaskRecord *dwFileShareGetDescriptors(dwFileShareDescriptorsTask *a1, ControllerIndex_t localControllerIndex, dwFileShareDescriptorsTask *const fsTask);
TaskRecord *dwFileShareReadPooledStorageFile(ControllerIndex_t controllerIndex, dwFileShareReadFileTask *const fsTask);
TaskRecord *dwFileShareReadUserStorageFile(ControllerIndex_t controllerIndex, dwFileShareReadFileTask *const fsTask);
TaskRecord *dwFileShareReadPublisherStorageFile(ControllerIndex_t controllerIndex, dwFileShareReadFileTask *const fsTask);
TaskRecord *dwFileShareReadFile(dwFileShareReadFileTask *a1, ControllerIndex_t a2, ControllerIndex_t controllerIndex, dwFileShareReadFileTask *const fsTask);
TaskRecord *dwFileShareRemoveFile(ControllerIndex_t controllerIndex, dwFileShareRemoveTask *const fsTask);
TaskRecord *dwFileShareTransferFile(ControllerIndex_t controllerIndex, dwFileShareTransferTask *const fsTask);
TaskRecord *dwFileShareGetPooledSummary(ControllerIndex_t controllerIndex, dwFileShareSummaryTask *const fsTask);
TaskRecord *dwFileShareGetUserSummary(ControllerIndex_t controllerIndex, dwFileShareSummaryTask *const fsTask);
TaskRecord *dwFileShareGetSummary(dwFileShareSummaryTask *a1, ControllerIndex_t a2, ControllerIndex_t controllerIndex, dwFileShareSummaryTask *const fsTask);
TaskRecord *dwFileShareSetPooledSummary(ControllerIndex_t controllerIndex, dwFileShareSummaryTask *const fsTask);
TaskRecord *dwFileShareSetUserSummary(ControllerIndex_t controllerIndex, dwFileShareSummaryTask *const fsTask);
TaskRecord *dwFileShareSetSummary(ControllerIndex_t controllerIndex, dwFileShareSummaryTask *const fsTask);
TaskRecord *dwFileShareWritePooledStorageFile(ControllerIndex_t controllerIndex, dwFileShareWriteFileTask *const fsTask);
TaskRecord *dwFileShareWriteUserStorageFile(ControllerIndex_t controllerIndex, dwFileShareWriteFileTask *const fsTask);
TaskRecord *dwFileShareWriteFile(dwFileShareWriteFileTask *a1, ControllerIndex_t a2, ControllerIndex_t controllerIndex, dwFileShareWriteFileTask *const fsTask);
TaskRecord *dwKeyArchiveRead(const ControllerIndex_t localControllerIndex, dwKeyArchiveReadTask *const keyArchiveTask);

//t6/code/src_noserver/dw/dwteam.cpp
TaskRecord *dwTeamClanLeave(const ControllerIndex_t localControllerIndex, dwTeamClanLeaveTask *const teamTask);
TaskRecord *dwTeamClanCreate(const ControllerIndex_t localControllerIndex, dwTeamClanCreateTask *const teamTask);
TaskRecord *dwTeamSetPublicProfile(const ControllerIndex_t localControllerIndex, dwTeamSetPublicProfileTask *const teamTask);
TaskRecord *dwTeamSetPrivateProfile(const ControllerIndex_t localControllerIndex, dwTeamSetPrivateProfileTask *const teamTask);

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
bdAuthService *dwGetAuthService(const bdInetAddr authAddr, unsigned __int16 authPort, const unsigned int titleID);
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
bool dwVoteGetRatio(const ControllerIndex_t localControllerIndex, bdVoteRankStatsInfo *rating, unsigned int *outLikes, unsigned int *outDislikes);
TaskRecord *dwVoteSubmitRating(const ControllerIndex_t localControllerIndex, dwVoteSubmitTask_t *voteTask, bool isUserStorageVote);

//t6/code/src_noserver/dw/dwyoutube.cpp
TaskRecord *dwYouTubeRegisterAccount(const ControllerIndex_t localControllerIndex, dwYouTubeRegistrationTask_t *ytTask);
TaskRecord *dwYouTubeUnregisterAccount(const ControllerIndex_t localControllerIndex);
TaskRecord *dwYouTubeIsRegistered(const ControllerIndex_t localControllerIndex, dwYouTubeIsRegisteredTask_t *ytTask);
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
// bool __thiscall MatchMakingInfo::doUpdate(MatchMakingInfo *this, const int msec, const unsigned int updateIntervalMsec, const unsigned int forceUpdateIntervalMsec);
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
;
;
void FindBitchForPlayer(int attackingPlayerSlot);
void FindNemesisForPlayer(int attackingPlayerSlot);
void SaveTeamScores();
void MatchRecorder_RecordGameResult(team_t winner, bool isDraw);
void GetWorldLocation(float xPos, float yPos, float zPos, unsigned __int8 *xWorld, unsigned __int8 *yWorld, unsigned __int8 *zWorld);
;
;
void MatchRecordSetHitStat(ddlState_t playerState, gclient_t *attackerClient, const hitLocation_t hitLocation, const char *hitLocStatName);
void MatchRecordHit(gclient_t *attackerClient, hitLocation_t hitLocation);
;
void MatchRecordEnd(gclient_t *client);
;
void MatchRecordPlayerDetails(gclient_t *client, const char *reason);
void MatchRecordSetPlayerStat(gclient_t *client, const char *statName, int statValue);
char MatchRecordEventFailure();
void MatchRecorder_TagXuids(int *numTags, bdTag *tags, int maxTags);
void MatchRecorder_RecordKillstreakEvent(ddlState_t *a1, unsigned __int8 *a2, float client, gclient_t *killstreakIndex, int a5);
void MatchRecorder_RecordKillstreakEndEvent(ddlState_t *a1, gclient_t *a2, gclient_t *client, int killstreakIndex);
void MatchRecorder_RecordGameEvent(ddlState_t *a1, gclient_t *a2, float client, gclient_t *gameEvent, const char *a5);
void MatchRecorder_RecordKillModifier(ddlState_t *a1, gclient_t *a2, gclient_t *client, const char *killModifier);
void MatchRecorder_RecordScoreEvent(ddlState_t *a1, gclient_t *a2, gclient_t *client, const char *scoreEvent);
;
;
void MatchRecorder_RecordMultiKill(ddlState_t *a1, gclient_t *a2, gclient_t *client, int killCount);
void MatchRecord_WriteItemStats(char *a1, gentity_t *playerEnt, ClientNum_t clientNum, int weaponStatIndex, int weaponIndex, int attachmentBits, const char *weapName, const char *statName, unsigned int addValue, int statNameHash);
;
void MatchRecorder_RecordZombieGameInfoEnd(const char *a1, ddlState_t *a2, const char *gameModeGroup, const char *gameMode, const char *mapLocation, int numRounds);
void MatchRecorder_RecordZombiePlayerDeath();
void MatchRecorder_RecordZombiePlayerDown(float client, gclient_t *a2);
bool IsPlayerInRound(unsigned __int64 xuid, ddlState_t *roundState);
bool GetPlayerRoundSlot(unsigned __int64 xuid, ddlState_t *playerRoundSlot);
void MatchRecord_ZombieRoundStart(ddlState_t *a1, const char *a2);
void MatchRecord_ZombieRoundEnd(ddlState_t *a1, const char *a2);
void MatchRecorder_IncrementPlayerStat(gclient_t *client, const char *statName);
;
void MatchRecord_InitMatchData();
;
void GenerateRecordedMatchData(ControllerIndex_t controllerIndex, const char *gameMode, char **matchRecordBuffer, int *matchRecordBufferSize, unsigned __int64 fileID);
BOOL MatchRecord_ParseDownloadedMatchData(int a1, char *a2, const ControllerIndex_t controllerIndex, char *inputBuffer, int buffsize);
void MatchRecordPointsSpent(ControllerIndex_t controllerIndex, int amount, pointsSpent_t reasonType, int reasonIndex);
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

