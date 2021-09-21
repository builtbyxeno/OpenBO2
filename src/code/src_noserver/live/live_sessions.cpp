#include "types.h"
#include "functions.h"

/*
==============
Session_BuildQoSPayload
==============
*/
int Session_BuildQoSPayload(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_GetQosPayloadBuffer
==============
*/
unsigned __int8 *Session_GetQosPayloadBuffer()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Session_UpdateQoSPayload
==============
*/
void Session_UpdateQoSPayload(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetQoSPayload
==============
*/
char GetQoSPayload(unsigned __int8 *data, int dataSize, qosPayload_t *qosPayload)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_HostNum
==============
*/
ClientNum_t Session_HostNum(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
	ClientNum_t tmp;
	return tmp;
}

/*
==============
Session_IsLocalMember
==============
*/
bool Session_IsLocalMember(SessionData *session, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_CloseJoinSessionPopup
==============
*/
void Session_CloseJoinSessionPopup(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_GetPlayerAddr
==============
*/
netadr_t *Live_GetPlayerAddr(netadr_t *result, SessionData *session, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Live_PlayerHasLoopbackAddr
==============
*/
BOOL Live_PlayerHasLoopbackAddr(SessionData *session, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_FindRegisteredUser
==============
*/
ClientNum_t Session_FindRegisteredUser(const SessionData *session, const unsigned __int64 xuid)
{
	UNIMPLEMENTED(__FUNCTION__);
	ClientNum_t tmp;
	return tmp;
}

/*
==============
Session_IsUserRegistered
==============
*/
bool Session_IsUserRegistered(const SessionData *session, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_GetXuid
==============
*/
unsigned __int64 Session_GetXuid(const SessionData *session, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_GetXuidEvenIfInactive
==============
*/
unsigned __int64 Session_GetXuidEvenIfInactive(const SessionData *session, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_GetPlayerNetAddr
==============
*/
netadr_t *Live_GetPlayerNetAddr(netadr_t *result, const SessionData *session, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Live_IsClientRegistered
==============
*/
bool Live_IsClientRegistered(const SessionData *session, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_GetOurClientNum
==============
*/
ClientNum_t Live_GetOurClientNum(ControllerIndex_t controllerIndex, SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
	ClientNum_t tmp;
	return tmp;
}

/*
==============
Session_CurrentFlags
==============
*/
int Session_CurrentFlags(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_PublicSlots
==============
*/
int Session_PublicSlots(const SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_PrivateSlots
==============
*/
int Session_PrivateSlots(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_GetNonce
==============
*/
unsigned __int64 Session_GetNonce(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_SetNonce
==============
*/
void Session_SetNonce(SessionData *session, unsigned __int64 nonce)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_GetXNKId
==============
*/
XSESSION_INFO *Session_GetXNKId(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Session_Started
==============
*/
bool Session_Started(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_UpdatePlayerNetAddr
==============
*/
void Live_UpdatePlayerNetAddr(SessionData *session, const ClientNum_t clientNum, const netadr_t *addr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_UpdatePlayerInAddr
==============
*/
void Live_UpdatePlayerInAddr(SessionData *session, const ClientNum_t clientNum, const in_addr inaddr, const unsigned __int16 port)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_UpdatePlayerAddr
==============
*/
void Live_UpdatePlayerAddr(SessionData *session, const ClientNum_t clientNum, const netadr_t addr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_Init
==============
*/
void Session_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_QoSListenStart
==============
*/
void Session_QoSListenStart(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_IsControllerValidForCreatingSession
==============
*/
bool Session_IsControllerValidForCreatingSession(ControllerIndex_t controllerIndex, int requiredSigninState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_GetSessionCreateController
==============
*/
int Session_GetSessionCreateController(int requiredSigninState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_StartClient
==============
*/
char Session_StartClient(SessionData *session, const ControllerIndex_t localControllerIndex, const int flags, XSESSION_INFO *hostInfo, unsigned __int64 sessionNonce, int numPublicSlots, int numPrivateSlots)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_NeedToSyncParams
==============
*/
bool Session_NeedToSyncParams(SessionData *session, const int numPublic, const int numPrivate, const int flags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_ModifyInProgress
==============
*/
bool Session_ModifyInProgress()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_CreateInProgress
==============
*/
bool Session_CreateInProgress()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_SearchInProgress
==============
*/
bool Session_SearchInProgress()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_CheckSessionTaskBySession
==============
*/
void Session_CheckSessionTaskBySession(TaskRecord *task, void *inData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_SessionTasksInProgress
==============
*/
char Session_SessionTasksInProgress(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_CreateInProgress
==============
*/
bool Session_CreateInProgress(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_CancelIndividualSessionTasks
==============
*/
void Session_CancelIndividualSessionTasks(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_CancelSessionTasks
==============
*/
void Session_CancelSessionTasks(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_WaitOnSessionTasks
==============
*/
void Session_WaitOnSessionTasks(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_WaitForTaskToComplete
==============
*/
void Session_WaitForTaskToComplete(TaskRecord *sessionTask, int startTime, int timeOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_FinishOngoingSessionJoinTasksForXUID
==============
*/
void Session_FinishOngoingSessionJoinTasksForXUID(const char *a1, SessionData *session, unsigned __int64 player)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_GetCurrentSession
==============
*/
SessionData *Session_GetCurrentSession()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Session_UnregisterRemotePlayer
==============
*/
void Session_UnregisterRemotePlayer(SessionData *session, const ClientNum_t slot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_EndGameSession
==============
*/
void Session_EndGameSession(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_GetFreeSessionGraveYardSlot
==============
*/
int Session_GetFreeSessionGraveYardSlot()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_DeleteSession
==============
*/
void Session_DeleteSession(SessionData *session, bool deleteNow)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_DeleteSession
==============
*/
void Session_DeleteSession(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_StartHost
==============
*/
void Session_StartHost(SessionData *session, int sessionFlags, int numPrivateSlots, int numPublicSlots, bool silentFail)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_FinishModify
==============
*/
void Session_FinishModify(void)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_StartGameSession
==============
*/
void Session_StartGameSession(const ControllerIndex_t localControllerIndex, SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_RemoveAllPlayersFromSession
==============
*/
void Session_RemoveAllPlayersFromSession(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_CleanUpSearches
==============
*/
void Session_CleanUpSearches(const char *a1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_EmptyGraveYard
==============
*/
void Session_EmptyGraveYard()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_EndOngoingSessionTasksForLeave
==============
*/
void Session_EndOngoingSessionTasksForLeave(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
}

