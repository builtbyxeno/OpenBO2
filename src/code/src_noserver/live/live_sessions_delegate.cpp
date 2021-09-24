#include "types.h"

/*
==============
HostDelegate_UpdateState
==============
*/
void HostDelegate_UpdateState(hostDelegationState_t newState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HostDelegate_AreWeSessionOwner
==============
*/
BOOL HostDelegate_AreWeSessionOwner()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
HostDelegate_ShouldSendPartyState
==============
*/
BOOL HostDelegate_ShouldSendPartyState()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
HostDelegate_RegisterPlayer
==============
*/
void HostDelegate_RegisterPlayer(unsigned __int64 playerXUID, netadr_t playerAddr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HostDelegate_CurrentlyDelegating
==============
*/
char HostDelegate_CurrentlyDelegating()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
anyPotentialDelegates
==============
*/
char anyPotentialDelegates()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
cleanupSessionDetails
==============
*/
void cleanupSessionDetails()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HostDelegate_UnregisterPlayer
==============
*/
void HostDelegate_UnregisterPlayer(unsigned __int64 playerXUID)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HostDelegate_Choose
==============
*/
char HostDelegate_Choose()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
HostDelegate_IsCurrentHostValid
==============
*/
BOOL HostDelegate_IsCurrentHostValid()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
sendHostDelegateCmd
==============
*/
bool sendHostDelegateCmd(netadr_t to)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
HostDelegate_ResendDelegateCmd
==============
*/
char HostDelegate_ResendDelegateCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
HostDelegate_Frame
==============
*/
void HostDelegate_Frame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
packetIsFromDelegate
==============
*/
BOOL packetIsFromDelegate(netadr_t from)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
hostDelegateHandleSessionCreate
==============
*/
void hostDelegateHandleSessionCreate(netadr_t from, const ControllerIndex_t controllerIndex, msg_t *msg, unsigned __int8 flags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HostDelegate_Init
==============
*/
void HostDelegate_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HostDelegate_HandlePacket
==============
*/
void HostDelegate_HandlePacket(LocalClientNum_t clientNum, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

