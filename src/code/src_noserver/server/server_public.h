#pragma once

#include "types.h"

//t6/code/src_noserver/server/sv_client.cpp
bool SV_DoWeHaveAllStatsPackets(client_t *cl, int numCompressedPackets);
void SV_ReceiveStats(netadr_t from, msg_t *msg);
void SV_CacheClientStatChange(ClientNum_t clientNum, ddlState_t *searchState);
void SV_SetClientStat(ClientNum_t clientNum, ddlState_t *searchState, ddlValue_t value);
void SV_SetClientInt64Stat(ClientNum_t clientNum, ddlState_t *searchState, unsigned __int64 value);
void SV_SetClientFixedPointStat(ClientNum_t clientNum, ddlState_t *searchState, float value);
void SV_SetClientStringStat(ClientNum_t clientNum, ddlState_t *searchState, const char *value);
int SV_GetClientStat(ClientNum_t clientNum, ddlState_t *searchState, ddlValue_t *result);
int SV_GetClientIntStat(ClientNum_t clientNum, ddlState_t *searchState);
const GfxViewParms *SV_GetClientStringStat(ClientNum_t clientNum, ddlState_t *searchState);
ddlValue_t SV_GetClientInt64Stat(ClientNum_t clientNum, ddlState_t *searchState);
double SV_GetClientFixedPointStat(ClientNum_t clientNum, ddlState_t *searchState);
void SV_UploadStatsForClient(ClientNum_t clientNum);
void SV_UploadStats();
void SV_AuthClient(netadr_t from, msg_t *msg);
void SV_LogConfigStrings();
void SV_WriteConfigStrings(msg_t *msg);

//t6/code/src_noserver/server/sv_game.cpp
playerState_s *SV_GameClientNum(int num);
svEntity_s *SV_SvEntityForGentity(const gentity_t *gEnt);
void SV_GameSendServerCommand(ClientNum_t clientNum, svscmd_type type, const char *text);
void SV_GameDropClient(ClientNum_t clientNum, const char *reason);
void SV_SetMapCenter(vec3_t *mapCenter);
vec3_t *SV_GetMapCenter();
void SV_SetGameEndTime(int gameEndTime);
bool SV_SetBrushModel(gentity_t *ent);
BOOL SV_inSnapshot(const vec3_t *origin, int iEntityNum);
void SV_GetServerinfo(char *buffer, int bufferSize);
void SV_LocateGameData(;
void SV_GetUsercmd(ClientNum_t clientNum, usercmd_s *cmd);
void *SV_AllocXModelPrecache(int size);
void *SV_AllocXModelPrecacheColl(int size);
XModel *SV_XModelGet(const char *name);
void SV_DObjDumpInfo(gentity_t *ent);
void SV_ResetSkeletonCache();
char *SV_AllocSkelMemory(unsigned int size);
int SV_DObjCreateSkelForBone(DObj *obj, int boneIndex);
int SV_DObjCreateSkelForBones(DObj *obj, int *partBits);
void SV_DObjUpdateServerTime(gentity_t *ent, float dtime, int bNotify);
void SV_DObjInitServerTime(gentity_t *ent, float dtime);
int SV_DObjGetBoneIndex(const gentity_t *ent, unsigned int boneName);
int SV_DObjGetParentBoneIndex(const gentity_t *ent, int childBoneIndex);
DObjAnimMat *SV_DObjGetMatrixArray(const gentity_t *ent);
void SV_DObjDisplayAnim(gentity_t *ent, const char *header);
DObjAnimMat *SV_DObjGetRotTransArray(const gentity_t *ent);
int SV_DObjSetRotTransIndex(const gentity_t *ent, int *partBits, int boneIndex);
void SV_DObjGetBounds(gentity_t *ent, vec3_t *mins, vec3_t *maxs);
XAnimTree_s *SV_DObjGetTree(gentity_t *ent);
BOOL SV_MapExists(const char *name);
BOOL SV_DObjExists(gentity_t *ent);
void SV_track_shutdown();
void SV_SavePaths(unsigned __int8 *buf, int size);
int SV_GetGuid(ClientNum_t clientNum);
int SV_GetClientPing(ClientNum_t clientNum);
BOOL SV_IsLocalClient(ClientNum_t clientNum);
char SV_AllClientsAreLocal();
void SV_SetGametype();
void SV_InitGameVM(int restart, int registerDvars, int savegame);
void SV_ShutdownGameVM(int clearScripts);
void SV_RestartGameProgs(int savepersist);
void SV_InitGameProgs(int savepersist, int savegame);
int SV_GameCommand();
const char *SV_Archived_Dvar_GetVariantString(const char *dvarName);
int SV_Archived_Dvar_GetInt(int dvarHash);
double SV_Archived_Dvar_GetFloat(int dvarHash);
;
void SV_ShutdownGameProgs();

//t6/code/src_noserver/server/sv_main.cpp
void SV_MatchEnd();
void SVC_Info(;
void SVC_Info(netadr_t from);
char SVC_Info(netadr_t from);

//t6/code/src_noserver/server/sv_main_dw.cpp
void SV_Live_RemoveClient(client_t *cl, const char *reason);

//t6/code/src_noserver/server/sv_migration.cpp
bool SV_IsMigrating();
int SV_MigrationIsWaitingForPlayers();
void SV_MigrationReset();
void SV_MigrationInit();
netadr_t *ClientRemoteAddr(const ClientNum_t clientNum);
bool IsClientConnected(const ClientNum_t clientNum);
bool SendToClient(const ClientNum_t clientNum, const unsigned __int8 *data, int len);
void SendStartMessage(const ClientNum_t clientNum);
void CreateBlock(const int blockNum, Block *block);
bool SendBlock(const ClientNum_t clientNum, Block *block);
void SendSave();
void SendMigrateTo(const ClientNum_t clientNum);
void SendHeader();
void PickNewHost();
int SV_GetMigrationCount();
void SV_MigrationStart(const char *reason);
bool HasTimedOut(const ClientNum_t clientNum);
void TimedOut(const ClientNum_t clientNum);
void __thiscall CheckTimeouts(void *this);
void SendMigrateToMessages();
void SendFrame();
void SV_MigrationUpdateCount(const int count);
void SV_MigrationFrame();
void HandleRatingMsg(const ClientNum_t clientNum, msg_t *msg);
void HandleSaveAckMsg(const ClientNum_t clientNum, msg_t *msg);
void HandleHeaderAckMsg(const ClientNum_t clientNum);
void HandleMigrateToAckMsg(const ClientNum_t clientNum);
char SV_MigrationPacket(const char *cmd, netadr_t from, msg_t *msg);
void SV_MigrationEnd();

//t6/code/src_noserver/server/sv_snapshot.cpp
void SV_EmitPacketClients(;
void SV_EmitPacketActors(;
void SV_UpdateServerCommandsToClient(client_t *client, msg_t *msg);
void SV_UpdateServerCommandsToClient_PreventOverflow(client_t *client, msg_t *msg, int iMsgSize);
void SV_PrintServerCommandsForClient(client_t *client);
int SV_SnapshotRateHeuristic();
int SV_AdjustRateForClient(client_t *client, int rateMsec);
void SV_ResetRecordMessageSize();
void SV_RecordMessageSize(int compressedSize, int uncompressedSize);
void SV_SendMessageToClient(msg_t *msg, client_t *client, bool reliable);
void SV_BeginClientSnapshot(client_t *client, msg_t *msg, unsigned __int8 *buffer, int bufferSize);
void SV_EndClientSnapshot(client_t *client, msg_t *msg);
void SV_SetServerStaticHeader();
void SV_GetServerStaticHeader();

//t6/code/src_noserver/server/sv_snapshot_stats.cpp
int SV_AddModifiedStatsWithinOffset(ClientNum_t clientNum, int startOffset, int *endOffset, msg_t *msg);
void SV_StatSign_Init();
void SV_CalcStatsHash(;
unsigned __int8 (*getCachedStatsHashForClient(client_t *client))[24];
signedStatsHash_t *getCachedSignedStatsHashForClient(client_t *client);
char SV_StatSign_SetCheckSumForClient(client_t *client);
void actionOnBadStats(;
void SV_SignedStats_Breadcrumb(client_t *client);
;
void SV_AddModifiedStats(ClientNum_t clientNum);

//t6/code/src_noserver/server/sv_world.cpp
unsigned int SV_ClipHandleForEntity(const gentity_t *ent);
void SV_UnlinkEntity(gentity_t *gEnt);
void SV_TraceCapsuleToEntity(const moveclip_t *clip, svEntity_s *check, trace_t *trace);
void SV_TracePointToEntity(const pointtrace_t *clip, svEntity_s *check, trace_t *trace);
int SV_SightTraceCapsuleToEntity(const sightclip_t *clip, int entnum);
void SV_SetupIgnoreEntParams(IgnoreEntParams *ignoreEntParams, int baseEntity);
BOOL SV_SightTraceCapsule(;
BOOL SV_SightTracePoint(int *hitNum, const vec3_t *start, const vec3_t *end, col_context_t *context);
int SV_PointContents(const vec3_t *p, int passEntityNum, int contentmask);
;
;
;
void SV_TraceCapsule(;
void G_TraceCapsule(;
void G_LocationalTrace(;
void G_LocationalTraceAllowChildren(;

