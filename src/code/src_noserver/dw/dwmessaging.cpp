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
/*void dwLobbyEventHandler::onNewNotification(dwLobbyEventHandler *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
dwLobbyEventHandler::onTeamProposal
==============
*/
/*void dwLobbyEventHandler::onTeamProposal(dwLobbyEventHandler *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
dwLobbyEventHandler::onPlayerBanned
==============
*/
/*void dwLobbyEventHandler::onPlayerBanned(dwLobbyEventHandler *notthis, unsigned __int64 userID, unsigned int reputationLevel)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
dwLobbyEventHandler::onMultipleLogon
==============
*/
/*void dwLobbyEventHandler::onMultipleLogon(dwLobbyEventHandler *notthis, unsigned __int64 userID)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
dwLobbyEventHandler::onYouTubeRegistration
==============
*/
/*void dwLobbyEventHandler::onYouTubeRegistration(dwLobbyEventHandler *notthis, const bdYouTubeRegistrationResult *registrationResult)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
dwLobbyEventHandler::onGlobalInstantMessage
==============
*/
/*void dwLobbyEventHandler::onGlobalInstantMessage(dwLobbyEventHandler *notthis, unsigned __int64 senderID, char *senderName, void *message, unsigned int messageSize)
{
	UNIMPLEMENTED(__FUNCTION__);
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
/*void dwLobbyEventHandler::onChallengesReceived(dwLobbyEventHandler *notthis, unsigned __int64 userID, bdReference<bdAntiCheatChallenges> challenges)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

