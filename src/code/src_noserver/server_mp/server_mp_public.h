#pragma once

#include "types.h"

//t6/code/src_noserver/server_mp/sv_archive_mp.cpp
int GetFollowPlayerStateLocal(ClientNum_t clientNum, playerState_s *ps);
void SV_ArchiveSnapshot(msg_t *msg);

//t6/code/src_noserver/server_mp/sv_ccmds_mp.cpp
char SV_CheckMapExists(const char *map);
client_t *SV_GetPlayerByName();
client_t *SV_GetPlayerByNum();
char *SV_GetMapBaseName(const char *mapname);
void ShowLoadErrorsSummary(const char *mapName, unsigned int count);
void SV_Map_f(char *a1);
void SV_ReconnectClients(int savepersist);
void SV_MapRestart(int fast_restart);
void SV_MapRestart_f();
void SV_FastRestart_f();
int SV_KickClient(client_t *cl, char *playerName, int maxPlayerNameLen);
int SV_KickUser_f(char *a1, char *playerName, int maxPlayerNameLen);
client_t *SV_KickClient_f(char *a1, char *playerName, int maxPlayerNameLen);
void SV_KickClientForReason_f();
void SV_TempBan_f(char *a1, char *a2);
void SV_Ban_f();
void SV_BanNum_f();
void SV_Drop_f(char *a1, char *a2);
void SV_DropNum_f(char *a1, char *a2);
void SV_TempBanNum_f(char *a1, char *a2);
void SV_Status_f();
void SV_AssembleConSayMessage(int firstArg, char *text, int sizeofText);
void SV_ConSay_f(int a1);
void SV_TeamStatus_f();
void SV_ConTell_f(char *a1);
void SV_Heartbeat_f();
void SV_Serverinfo_f();
void SV_Systeminfo_f();
void SV_DumpUser_f();
void SV_KillServer_f();
void SV_ScriptUsage_f();
void SV_ScriptVarUsage_f_usage();
void SV_ScriptVarUsage_f();
void __cdecl SV_StringUsage_f();
void SV_SetPerk_f();
void SV_HostMigrationStart_f();
void SV_SendNoDelta_f();
void SV_SendNewBaseline_f();
void SV_AddDedicatedCommands();
void SV_AddOperatorCommands();

//t6/code/src_noserver/server_mp/sv_client_mp.cpp
int SV_CountClients();
void SV_GetChallenge(netadr_t from);
void SV_UpdateSplitscreenStateForAddr(netadr_t addr);
int SV_GetPlayerXuid(ClientNum_t clientNum);
void SV_FreeClientScriptPers();
void SV_SendDisconnect(client_t *client, int state, const char *reason);
void SV_DelayDropClient(client_t *drop, const char *reason);
void SV_ClientEnterWorld(client_t *client, usercmd_s *cmd);
void SV_VerifyIwds_f(char *a1, client_t *cl);
void SV_ResetPureClient_f(client_t *cl);
void SV_SynchronizePlayerInfoForClients();
char SV_ValidateName(client_t *newcl, const char *name);
BOOL SV_SanitizeName(const char *name, char *sanitizedName, int size);
bool SegmentIntersectsSphere(const vec3_t *point1, const vec3_t *point2, const vec3_t *center, const float *radius);
double SV_FX_GetVisibility(const vec3_t *start, const vec3_t *end);
void SV_FX_SetVisBlocker(const gentity_t *ent, float radius);
void SV_FX_FreeVisBlocker(const gentity_t *ent);
void SV_ExecuteClientCommand(char *a1, client_t *cl, const char *s, int clientOK, int fromOldServer);
void SV_ClientThink(client_t *cl, usercmd_s *cmd);
BOOL SV_IsTestClient(ClientNum_t clientNum);
void SV_FreeClient(client_t *cl);
void SV_FreeClients();
void SV_DropClient(client_t *drop, const char *reason, bool tellThem);
void SV_SendClientGameState(client_t *client);
void SV_Disconnect_f(client_t *cl);
void SV_UserinfoChanged(client_t *cl);
void SV_UpdateUserinfo_f(client_t *cl);
int SV_ProcessClientCommands(client_t *cl, msg_t *msg, int fromOldServer, int *lastCommand);
void SV_BanClient(client_t *cl);
void ReconnectMigratedClient(client_t *cl, netadr_t from, const int qport, const int challenge, int playerGuid, const char *userinfo);
void SV_DirectConnect(netadr_t from);
void SV_MigrateTestClient(client_t *cl);
gentity_t *SV_AddTestClient(unsigned int a1);
void SV_UserMove(client_t *cl, msg_t *msg, int delta);
void SV_ExecuteClientMessage(client_t *cl, msg_t *msg);

//t6/code/src_noserver/server_mp/sv_connection_log.cpp
void SV_ConnectionLog_SetMatchID(unsigned __int64 matchID);
ClientRecord *SV_ConnectionLog_NewClient(int clientNum);
int SV_ConnectionLog_NewSample(int clientNum, unsigned __int64 xuid, int avgPing, int minPing, int maxPing, int unackCount);
void SV_ConnectionLog_Init();
void SV_ConnectionLog_Upload();

//t6/code/src_noserver/server_mp/sv_init_mp.cpp
void SV_GetConfigstring(int index, char *buffer, int bufferSize);
unsigned int SV_GetConfigstringConst(int index);
void SV_SetUserinfo(int index, const char *val);
void SV_GetUserinfo(int index, char *buffer, int bufferSize);
void SV_BoundMaxClients(int minimum);
void SV_Startup();
void SV_ChangeMaxClients();
void SV_SetExpectedHunkUsage(char *mapname);
void SV_ClearServer();
void SV_InitArchivedSnapshot();
void SV_AllocateClientMemory(HunkUser *hunk, int maxLocalClients, int maxClients, int allocFlags);
void SV_FreeClientMemory(HunkUser *hunk);
BOOL SV_Loaded();
void SV_Init();
void SV_FinalMessage(const char *message);
void SV_DropAllClients();
void SV_Shutdown(const char *finalmsg);
void SV_ClearServerThreadOwnsGame();
void SV_IncServerThreadOwnsGame();
void SV_DecServerThreadOwnsGame();
void SV_CheckThread();
void SV_SetConfigstring(int index, const char *val);
void SV_SetConfigValueForKey(int start, int max, const char *key, const char *value);
void SV_SetXUIDConfigStrings();
void SV_SaveSystemInfo();
void SV_SpawnServer(char *a1, ControllerIndex_t controllerIndex, const char *server, int mapIsPreloaded, int savegame);

//t6/code/src_noserver/server_mp/sv_main_mp.cpp
void TRACK_sv_main();
char *SV_ExpandNewlines(char *in);
int SV_IsFirstTokenEqual(const char *str1, const char *str2);
int SV_CanReplaceServerCommand(const char *a1, client_t *client, const char *cmd);
void SV_CullIgnorableServerCommands(client_t *client);
void SV_AddServerCommand(const char *a1, client_t *a2, client_t *client, svscmd_type type, const char *cmd);
void SV_SendServerCommand(client_t *cl, svscmd_type type, const char *fmt, ...);
client_t *SV_FindClientByAddress(netadr_t from, int qport);
void SVC_Status(netadr_t from);
char SVC_Ping(netadr_t from, msg_t *payload);
char SVC_StatusScoreBoard(const char *a1, netadr_t from);
char SVC_ClientUIDs(netadr_t from);
void SV_ConnectionlessPacket(char *a1, netadr_t from, msg_t *msg);
void SV_PacketEvent(netadr_t from, msg_t *msg);
void SV_CalcPings();
bool SV_DoISuckAsHost();
void SV_ReportClientPings();
void SV_UpdateServerBoostingStats();
void SV_PrintRateBoostingDebugScores(bool boostWasEnabled);
bool SV_DoISuckSoMuchIShouldQuit();
void SV_FreeClientScriptId(client_t *cl);
int SV_CheckPaused();
void SV_UpdatePerformanceFrame(int time);
void SV_RunFrame();
void SV_RunEventLoop();
int SV_Perf_RecordPings();
void SV_InitSnapshot();
void SV_KillLocalServer();
char SV_CheckOverflow();
void SV_PreFrame();
void SV_AllowPackets(const bool allow);
unsigned int SV_GetAssignedTeam(ClientNum_t clientNum);
void SV_SetAssignedTeam(ClientNum_t clientNum, int team);
const char *SV_GetCustomTeamName(int team);
void SV_Live_RemoveAllClientsFromAddress(client_t *cl, const char *reason);
void SV_CheckTimeouts();
void SV_PostFrame();
void SV_WaitServer();
void SV_FrameInternal(ControllerIndex_t controllerIndex, int msec);
int SV_Frame(ControllerIndex_t controllerIndex, int msec);
void SV_UpdateBots();
void SV_ServerThread(unsigned int threadContext);
void SV_InitServerThread();

//t6/code/src_noserver/server_mp/sv_main_pc_mp.cpp
int SV_GetSlotForPasswordIfFree(const char *password);
void SV_FreeReservedSlot(int slot);
bool SV_IsServerRanked(int licensetype);
void SVC_RemoteCommand(netadr_t from);
char SV_SetGroupCountsComplete();
char SV_GetGroupCountsComplete();
char SV_GroupsFailure();
bool Com_IsClientConsole();
clientplatform_t Com_GetClientPlatform();
void SV_SysLog_Init();
void SV_SysLog_ForceFlush();
void enqueueSyslogMessage(const char *msg);
void SV_SysLog_LogMessage(int severity, const char *msg);
void SV_SysLog_LogMessage_f();
void checkHandlersAreInited();
int validateAndGetCmd(msg_t *pktMsg);
void SV_Query_Pump(int a1);
int SV_Query_SendTo(int a1, unsigned __int8 *payload, int paylen, int cmd, netadr_t *to);
void SV_Perf_GetPerfVals(unsigned int perfBits, msg_t *msg);
void SV_Perf_Update(perfValType_t perfValType, unsigned int value);
perfVal_t *resetPerfCounters();
void SV_Perf_Frame();
char SVC_Perf(int a1, netadr_t from, msg_t *payload);
void SV_AutoShutdown_Init();
void SV_AutoShutdown_Frame();
void SV_MarkServerForShutdown();
int SV_GetLicenseType();
void SV_GetGroupCounts();
void SV_Groups_ParseGeos(const char *geoblob);
void SV_Query_Init();

//t6/code/src_noserver/server_mp/sv_net_chan_mp.cpp
bool SV_Netchan_TransmitNextFragment(client_t *client, netchan_t *chan);
bool SV_Netchan_Transmit(client_t *client, unsigned __int8 *data, int length, bool reliable);
void SV_Netchan_AddOOBProfilePacket(int iLength);

//t6/code/src_noserver/server_mp/sv_snapshot_build_mp.cpp
void SV_ClearBaselineFlagForAllClients();
int SV_AddEntitiesClientsCanSee();
int SV_CreateBaseline();
void SV_SaveSnapshotForTime(const int serverTime);
int SV_AddCachedEntitiesClientsCanSee(const int entCount, int firstEntityIndex);
bool SV_SaveSnapshotForArchivedTime(const int archiveTime);
void SV_BuildClientSnapshot(client_t *client);

//t6/code/src_noserver/server_mp/sv_snapshot_caching_mp.cpp
bool SV_FrameIsStillInArchivedSnapshotBuffer(const int frameStart);
cachedSnapshot_t *SV_GetCachedSnapshotInternal(int archivedFrame, int depth, bool expectedToSucceed);
cachedSnapshot_t *SV_GetCachedSnapshot(int *pArchiveTime);
int SV_GetCurrentClientInfo(ClientNum_t clientNum, playerState_s *ps, clientState_s *cs, bool allowLastActive);
void SV_GetClientPositionsFromCachedSnap(const cachedSnapshot_t *cachedFrame, vec3_t *pos, vec3_t *angles, bool *success);
bool SV_GetClientPositionsAtTimeInternal(int gametime, vec3_t *pos, vec3_t *angles, bool *success, int *flags);
bool SV_GetClientPositionsAtTimeFromClientPositionArchive(int gametime, vec3_t *pos, vec3_t *angles, bool *success, int *flags);
bool SV_GetClientPositionsAtTime(vec3_t *a1, int a2, int gametime, vec3_t *pos, vec3_t *angles, bool *success);
int SV_GetArchivedClientInfo(ClientNum_t clientNum, playerState_s *allowLastActive, int *pArchiveTime, playerState_s *ps, clientState_s *cs, vec3_t *origin, int *health, int *otherFlags);
char SV_HasCachedSnapshotInternal(int archivedFrame, int callDepth);
int SV_GetEarliestArchivedClientInfoTime();

//t6/code/src_noserver/server_mp/sv_snapshot_mp.cpp
const entityState_s *SV_GetNextEnt(const int entCount, const int firstEntIndex, int curIndex);
bool SV_EntLinkedToEnt(const entityState_s *childEnt, int parentEntIndex, const int entCount, const int firstEntityIndex);
bool SV_ShouldEntityGoToClient(const entityState_s *ent, const int clientNum, const int entCount, const int firstEntityIndex);
void SV_EmitPacketEntities_Debug(SnapshotInfo_s *snapInfo, int *quickBits, msg_t *msg, const char *str, ...);
void SV_EmitPacketEntities(SnapshotInfo_s *snapInfo, const int viewClientNum, const int oldFrameViewClientNum, const int oldEntCount, const int firstOldEntityIndex, const int oldFrameTimeDelta, const int newEntCount, const int firstNewEntityIndex, const int newFrameTimeDelta, msg_t *msg);
void SV_WritePerformanceData(const ClientNum_t clientNum, msg_t *msg);
void SV_WriteSnapshotToClient(char *a1, client_t *client, msg_t *msg, const bool sendEntities, const bool writeClientsAndOtherData);
int SV_RateMsec();
void SV_SetServerStaticHeader_Project();
void SV_GetServerStaticHeader_Project();
void SV_SendClientMessages(int a1);

//t6/code/src_noserver/server_mp/sv_snapshot_profile_mp.cpp
void MSG_PacketAnalyze_SetPacketEntityType(SnapshotInfo_s *snapInfo, PacketEntityType packetEntityType, bool archived);
const char *SV_GetEntityTypeString(const int packetEntityType);
void SV_PacketAnalyze_TrackETypeBytes(int eType, int number, int bits, bool archived, const NetFieldList *fieldList);
void SV_PacketAnalyze_TrackPS_ClearBits(int bits);
void SV_PacketAnalyze_TrackPS_FieldDeltasBits(int bits);
void SV_PacketAnalyze_TrackPS_HudelemBits(int bits);
void SV_PacketAnalyze_TrackPS_StatsBits(int bits);
void SV_PacketAnalyze_TrackPS_WeaponBits(int bits);
void SV_PacketAnalyze_TrackPS_AmmoPoolBits(int bits);
void SV_PacketAnalyze_TrackPS_AmmoClipBits(int bits);
void SV_PacketAnalyze_TrackPS_ObjectivesBits(int bits);
void SV_PacketAnalyze_AddVOIPWrittenBits(int bits);
void SV_PacketAnalyze_AddVOIPReadBits(int bits);
int SV_PacketAnalyze_GetVOIPWrittenBits();
int SV_PacketAnalyze_GetVOIPReadBits();
void SV_PacketAnalyze_ClearVoipBits();
void SV_PacketAnalyze_AddDemoUploadBits(int bits);
int SV_PacketAnalyze_GetDemoUploadBits();
void SV_PacketAnalyze_ClearDemoUploadBits();
void SV_PacketAnalyze_AddClientUploadBits(ClientNum_t clientNum, int bits);
int SV_PacketAnalyze_GetClientUploadBits(ClientNum_t clientNum);
void SV_PacketAnalyze_ClearClientUploadBits();

