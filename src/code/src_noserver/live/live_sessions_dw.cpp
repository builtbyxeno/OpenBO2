#include "types.h"

/*
==============
Session_DeleteDWSession
==============
*/
void Session_DeleteDWSession()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_DeleteSessionSuccess
==============
*/
char Session_DeleteSessionSuccess()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_DeleteSessionFailure
==============
*/
char Session_DeleteSessionFailure()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_QoSUpdate_Platform
==============
*/
void Session_QoSUpdate_Platform()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_QoSListenStart_Platform
==============
*/
void Session_QoSListenStart_Platform(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_QoSListenStop
==============
*/
void Session_QoSListenStop(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_CreateHostSessionFailure
==============
*/
char Session_CreateHostSessionFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_CreateNonMatchmakingSessionFailure
==============
*/
char Session_CreateNonMatchmakingSessionFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_CreateNonMatchmakingSessionSuccess
==============
*/
char Session_CreateNonMatchmakingSessionSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_StartClient_Platform
==============
*/
bool Session_StartClient_Platform(SessionData *session, const ControllerIndex_t localControllerIndex, const int flags, XSESSION_INFO *hostInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_Modify
==============
*/
void Session_Modify(const ControllerIndex_t localControllerIndex, SessionData *session, const int flags, const int publicSlots, const int privateSlots)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_ModifySessionSuccess
==============
*/
char Session_ModifySessionSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_JoinSession
==============
*/
void Session_JoinSession(const ControllerIndex_t localControllerIndex, SessionData *session, const int slot, const unsigned __int64 player, bool privateSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_LeaveSession
==============
*/
void Session_LeaveSession(SessionData *session, const ClientNum_t registeredUserSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_RegisterRemotePlayer
==============
*/
void Session_RegisterRemotePlayer(const ControllerIndex_t localControllerIndex, SessionData *session, const unsigned __int64 player, bool privateSlot, const ClientNum_t clientNum, const int natType, const netadr_t addr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_EveryoneLeaveSessionAsync
==============
*/
void Session_EveryoneLeaveSessionAsync(const ControllerIndex_t localControllerIndex, SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_StartHostCreateTask_Platform
==============
*/
TaskRecord *Session_StartHostCreateTask_Platform(ControllerIndex_t controllerIndex, int sessionFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Session_StartHost_Platform_DW
==============
*/
int Session_StartHost_Platform_DW(SessionData *session, int sessionFlags, int numPrivateSlots, int numPublicSlots, ControllerIndex_t controllerIndex, TaskRecord *sessionCreateTask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_ChangeAdvertisedStatus
==============
*/
void Session_ChangeAdvertisedStatus(bool onOff, bool force)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_SetSkill
==============
*/
void Live_SetSkill(const float skill)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_StartDeleteHandle
==============
*/
void Session_StartDeleteHandle(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Session_CreateHostSessionSuccess
==============
*/
char Session_CreateHostSessionSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_CreateNonMatchmakingSession
==============
*/
int Session_CreateNonMatchmakingSession(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_ModifySessionFailure
==============
*/
char Session_ModifySessionFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_FindSessionsFailure
==============
*/
char Session_FindSessionsFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Session_FindSessionsSuccess
==============
*/
char Session_FindSessionsSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

