#include "types.h"
#include "functions.h"

/*
==============
IsServerRunning
==============
*/
char IsServerRunning()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_GetCurrentSession
==============
*/
SessionData *Live_GetCurrentSession()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Live_ControllerIndex_GetClientName
==============
*/
char *Live_ControllerIndex_GetClientName(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Live_ControllerIndex_GetXuidString
==============
*/
char *Live_ControllerIndex_GetXuidString(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_ControllerIndex_GetSignInState
==============
*/
int CL_ControllerIndex_GetSignInState(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_GetFirstActiveSignedInControllerIndex
==============
*/
int CL_GetFirstActiveSignedInControllerIndex()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_FakeDWDisconnect_f
==============
*/
void Live_FakeDWDisconnect_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_TestNotification_f
==============
*/
void Live_TestNotification_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_UpdateInfoForInGameList_f
==============
*/
void Live_UpdateInfoForInGameList_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_InitPlatform
==============
*/
void Live_InitPlatform()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_XUIDIsLocalPlayer
==============
*/
char Live_XUIDIsLocalPlayer(const unsigned __int64 player)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_GetControllerFromXUID
==============
*/
ControllerIndex_t Live_GetControllerFromXUID(const unsigned __int64 player)
{
	UNIMPLEMENTED(__FUNCTION__);
	ControllerIndex_t tmp;
	return tmp;
}

/*
==============
Live_GiveAchievement
==============
*/
void Live_GiveAchievement(ControllerIndex_t localControllerIndex, const char *achievementName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_AreWeAcceptingInvite
==============
*/
bool Live_AreWeAcceptingInvite()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_AcceptInvite
==============
*/
void Live_AcceptInvite(ControllerIndex_t controllerIndex, InviteMessage *message, unsigned __int64 fromXuid)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_UserGetName
==============
*/
char Live_UserGetName(ControllerIndex_t controllerIndex, char *buf, const int bufsize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_UserSignedInToLive
==============
*/
bool Live_UserSignedInToLive(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_GetTier
==============
*/
EUserTier Live_GetTier(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	EUserTier tmp;
	return tmp;
}

/*
==============
Live_SetTier
==============
*/
void Live_SetTier(ControllerIndex_t controllerIndex, EUserTier tier)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_IsSystemUiActive
==============
*/
bool Live_IsSystemUiActive()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_ShowFriendsList
==============
*/
bool __thiscall Live_ShowFriendsList(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_GetUploadSpeed
==============
*/
int Live_GetUploadSpeed()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_BandwidthTestSuccess
==============
*/
char Live_BandwidthTestSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_BandwidthTestFailure
==============
*/
char Live_BandwidthTestFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_RunBandwidthTest
==============
*/
int Live_RunBandwidthTest(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_QoSProbeEarlyComplete
==============
*/
bool Live_QoSProbeEarlyComplete(dwQoSMultiProbeListener *listener)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_EstimateQoSPercentage
==============
*/
void Live_EstimateQoSPercentage(dwQoSMultiProbeListener *listener)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_QoSProbeSuccess
==============
*/
char Live_QoSProbeSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_QoSProbeFailure
==============
*/
char Live_QoSProbeFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_CleanUpQoSProbes
==============
*/
void Live_CleanUpQoSProbes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_QoSInProgress
==============
*/
BOOL Live_QoSInProgress()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_InitSigninState
==============
*/
void Live_InitSigninState()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
JoinMessageReplyCriteriaError
==============
*/
char *JoinMessageReplyCriteriaError(JoinSessionMessage *message)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Live_AreWeJoinable
==============
*/
char Live_AreWeJoinable(bool fromInvite, e_JoinRejectionReason *reason)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_ShowPlayerProfile
==============
*/
char Live_ShowPlayerProfile(ControllerIndex_t localControllerIndex, unsigned __int64 xuid)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_IsUserBlocked
==============
*/
char Live_IsUserBlocked(ControllerIndex_t controllerIndex, unsigned __int64 xuid)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_GetLocalNatType
==============
*/
bdNATType Live_GetLocalNatType()
{
	UNIMPLEMENTED(__FUNCTION__);
	bdNATType tmp;
	return tmp;
}

/*
==============
Live_RunQoSProbe
==============
*/
LocalTaskState Live_RunQoSProbe(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	LocalTaskState tmp;
	return tmp;
}

/*
==============
Live_StartQoSProbe
==============
*/
void Live_StartQoSProbe(ControllerIndex_t localControllerIndex, int numXenons, XSESSION_INFO *xenonsInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_SendJoinInfo
==============
*/
void Live_SendJoinInfo(ControllerIndex_t controllerIndex, unsigned __int64 recepient, JoinSessionMessage joinRequestMessage)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_JoinMessageAction
==============
*/
void Live_JoinMessageAction(ControllerIndex_t localControllerIndex, JoinSessionMessage message, unsigned __int64 from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_ProcessFriendInstantMessage
==============
*/
char Live_ProcessFriendInstantMessage(unsigned __int64 senderID, const ControllerIndex_t destIndex, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

