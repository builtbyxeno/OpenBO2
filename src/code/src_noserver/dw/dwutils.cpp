#include "types.h"
#include "functions.h"

/*
==============
dwGetOnlineUserID
==============
*/
bool dwGetOnlineUserID(const ControllerIndex_t controllerIndex, unsigned __int64 *userID)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwGetOnlineUserName
==============
*/
bool dwGetOnlineUserName(ControllerIndex_t controllerIndex, char *buf, const unsigned int bufsize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwGetLobby
==============
*/
bdLobbyService *dwGetLobby(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetMatchmaking
==============
*/
bdMatchMaking *dwGetMatchmaking(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetGroup
==============
*/
bdGroup *dwGetGroup(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetContentStreaming
==============
*/
bdContentStreaming *dwGetContentStreaming(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetPooledStorage
==============
*/
bdPooledStorage *dwGetPooledStorage(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetTwitchService
==============
*/
bdTwitch *dwGetTwitchService(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetLeagueService
==============
*/
bdLeague *dwGetLeagueService(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetVoteRankService
==============
*/
bdVoteRank *dwGetVoteRankService(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetYouTubeService
==============
*/
bdYouTube *dwGetYouTubeService(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetStorage
==============
*/
bdStorage *dwGetStorage(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetAntiCheat
==============
*/
bdAntiCheat *dwGetAntiCheat(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetKeyArchive
==============
*/
bdKeyArchive *dwGetKeyArchive(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetStats
==============
*/
bdStats *dwGetStats(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetTeams
==============
*/
bdTeams *dwGetTeams(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetAuthService
==============
*/
bdAuthService *dwGetAuthService(const bdInetAddr authAddr, unsigned __int16 authPort, const unsigned int titleID)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetTitleUtilities
==============
*/
bdTitleUtilities *dwGetTitleUtilities(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetEventLog
==============
*/
bdEventLog *dwGetEventLog(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetMessaging
==============
*/
bdMessaging *dwGetMessaging(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwLobbyErrorCodeToString
==============
*/
const char *dwLobbyErrorCodeToString(const bdLobbyErrorCode code)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwConnectionErrorHandler
==============
*/
void dwConnectionErrorHandler(int error_context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
dwRecordIPAddressSuccess
==============
*/
bool dwRecordIPAddressSuccess(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwRecordIPAddressComplete
==============
*/
bool dwRecordIPAddressComplete()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwRecordIPAddressFailure
==============
*/
char dwRecordIPAddressFailure(TaskRecord *task)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
dwCreateLobby
==============
*/
void dwCreateLobby(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
dwCloseRemoteTask
==============
*/
/*void dwCloseRemoteTask(bdReference<bdRemoteTask> *remoteTask)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
dwLobbyErrorCodeToString
==============
*/
void dwLobbyErrorCodeToString(const bdLobbyErrorCode code, char *const buffer, const unsigned int bufferSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
dwRecordIPAddressRequest
==============
*/
void dwRecordIPAddressRequest(const ControllerIndex_t controllerIndex, unsigned __int8 *ipArray)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
dwRecordIPAddress
==============
*/
void dwRecordIPAddress(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
dwGetSocketRouter
==============
*/
bdSocketRouter *dwGetSocketRouter()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetAddressMap
==============
*/
bdAddressMap *dwGetAddressMap()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetQoSProbe
==============
*/
bdQoSProbe *dwGetQoSProbe()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwGetLocalCommonAddr
==============
*/
/*bdReference<bdCommonAddr> *dwGetLocalCommonAddr(bdReference<bdCommonAddr> *result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
dwGetSecurityKeyMap
==============
*/
bdSecurityKeyMap *dwGetSecurityKeyMap()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

