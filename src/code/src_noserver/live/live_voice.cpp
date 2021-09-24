#include "types.h"

/*
==============
Voice_FindUser
==============
*/
int Voice_FindUser(const SessionData *session, const unsigned __int64 xuid)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Voice_UnregisterRemotePlayer
==============
*/
char Voice_UnregisterRemotePlayer(SessionData *session, const ClientNum_t slot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_GetConnectedPlayerList
==============
*/
int Live_GetConnectedPlayerList(const SessionData *session, unsigned __int64 *playerList)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Voice_IncomingVoiceData
==============
*/
int Voice_IncomingVoiceData(SessionData *session, ClientNum_t clientNum, unsigned __int8 *data, int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Voice_IsMemberMuted
==============
*/
int Voice_IsMemberMuted(ControllerIndex_t localControllerIndex, const unsigned __int64 playerXuid)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Voice_MuteMemberByXuid
==============
*/
void Voice_MuteMemberByXuid(const unsigned __int64 playerXuid)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Voice_UnmuteMemberByXuid
==============
*/
void Voice_UnmuteMemberByXuid(const unsigned __int64 playerXuid)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Voice_GetTalkingCount
==============
*/
int Voice_GetTalkingCount(SessionData *session, const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Voice_ClearRemoteTalkers
==============
*/
void Voice_ClearRemoteTalkers(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Voice_EnableMicIfAllowed
==============
*/
void Voice_EnableMicIfAllowed(SessionData *session)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Voice_RegisterRemotePlayer
==============
*/
char Voice_RegisterRemotePlayer(ControllerIndex_t localControllerIndex, SessionData *session, const unsigned __int64 player, const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

