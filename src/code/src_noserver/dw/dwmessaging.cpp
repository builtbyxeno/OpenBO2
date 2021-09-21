#include "types.h"
#include "functions.h"

/*
==============
dwInstantHandleTestMessage
==============
*/
char dwInstantHandleTestMessage(unsigned __int64 senderID, const ControllerIndex_t controllerIndex, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwInstantHandlePartyMessage
==============
*/
bool dwInstantHandlePartyMessage(unsigned __int64 senderID, const ControllerIndex_t controllerIndex, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwInstantHandleFriendMessage
==============
*/
bool dwInstantHandleFriendMessage(unsigned __int64 senderID, const ControllerIndex_t controllerIndex, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwInstantDispatchMessage_Internal
==============
*/
bool dwInstantDispatchMessage_Internal(unsigned __int64 senderID, const ControllerIndex_t controllerIndex, void *message, unsigned int messageSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwLobbyEventHandler::onNewNotification
==============
*/
/*void __thiscall dwLobbyEventHandler::onNewNotification(dwLobbyEventHandler *this)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
dwLobbyEventHandler::onTeamProposal
==============
*/
/*void __thiscall dwLobbyEventHandler::onTeamProposal(dwLobbyEventHandler *this)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
dwLobbyEventHandler::onPlayerBanned
==============
*/
/*void __thiscall dwLobbyEventHandler::onPlayerBanned(dwLobbyEventHandler *this, unsigned __int64 userID, unsigned int reputationLevel)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
dwLobbyEventHandler::onMultipleLogon
==============
*/
/*void __thiscall dwLobbyEventHandler::onMultipleLogon(dwLobbyEventHandler *this, unsigned __int64 userID)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
dwLobbyEventHandler::onYouTubeRegistration
==============
*/
/*void __thiscall dwLobbyEventHandler::onYouTubeRegistration(dwLobbyEventHandler *this, const bdYouTubeRegistrationResult *registrationResult)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
dwLobbyEventHandler::onGlobalInstantMessage
==============
*/
/*
{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}*/

/*
==============
dwInitMessaging
==============
*/
void dwInitMessaging(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
dwInstantSendMessage
==============
*/
TaskRecord *dwInstantSendMessage(ControllerIndex_t controllerIndex, const unsigned __int64 *recipientUIDs, unsigned int numRecipients, char msgType, const void *message, unsigned int msgSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwInstantSendTestMessage
==============
*/
void dwInstantSendTestMessage()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
dwProcessNotifications
==============
*/
char dwProcessNotifications(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwLobbyEventHandler::onChallengesReceived
==============
*/
/*void __thiscall dwLobbyEventHandler::onChallengesReceived(dwLobbyEventHandler *this, unsigned __int64 userID, bdReference<bdAntiCheatChallenges> challenges)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

