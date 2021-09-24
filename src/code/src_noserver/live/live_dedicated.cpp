#include "types.h"

/*
==============
dwSelectLSGAddress
==============
*/
char *dwSelectLSGAddress()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
dwSelectAuthAddress
==============
*/
char *dwSelectAuthAddress()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Live_SetTitleIDFromCommandLine
==============
*/
void Live_SetTitleIDFromCommandLine()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_SetAuthAddrFromCommandLine
==============
*/
void Live_SetAuthAddrFromCommandLine()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_SetLsgAddrFromCommandLine
==============
*/
void Live_SetLsgAddrFromCommandLine()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_GetTitleID
==============
*/
int Live_GetTitleID()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_SwitchPlaylists
==============
*/
void SV_SwitchPlaylists(const int newplaylist)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_PlaylistDvarChanged
==============
*/
void SV_PlaylistDvarChanged(const dvar_t *playlistdvar)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_OnDWConnect
==============
*/
void Live_OnDWConnect(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_OnDWDisconnect
==============
*/
void Live_OnDWDisconnect(const ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_DedicatedReadDWKey
==============
*/
const char *Live_DedicatedReadDWKey()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Live_Base_AuthorizeLicenseWithDW
==============
*/
bool Live_Base_AuthorizeLicenseWithDW(const ControllerIndex_t controllerIndex, dediUserData_t *userData)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_Base_HandleAuthServiceReady
==============
*/
bool Live_Base_HandleAuthServiceReady(const ControllerIndex_t controllerIndex, dediUserData_t *userData, bdAuthService *authService)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_Base_StateAuthorizing
==============
*/
void Live_Base_StateAuthorizing(const ControllerIndex_t controllerIndex, dediUserData_t *userData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_Base_StateConnecting
==============
*/
void Live_Base_StateConnecting(const ControllerIndex_t controllerIndex, dediUserData_t *userData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_Base_StateError
==============
*/
void Live_Base_StateError(const ControllerIndex_t controllerIndex, dediUserData_t *userData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_Base_Init
==============
*/
void Live_Base_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_Base_UserGetName
==============
*/
char Live_Base_UserGetName(const ControllerIndex_t controllerIndex, char *buff, int buffSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_Base_UserGetXuid
==============
*/
char Live_Base_UserGetXuid(const ControllerIndex_t controllerIndex, unsigned __int64 *xuid)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_Base_GetControllerFromXUID
==============
*/
ControllerIndex_t Live_Base_GetControllerFromXUID(const unsigned __int64 xuid)
{
	UNIMPLEMENTED(__FUNCTION__);
	ControllerIndex_t tmp;
	return tmp;
}

/*
==============
Live_IsSignedInToLive
==============
*/
bool Live_IsSignedInToLive(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_GetXuid
==============
*/
unsigned __int64 Live_GetXuid(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_SetAddressForDedicatedServer
==============
*/
void Live_SetAddressForDedicatedServer(MatchMakingInfo *sessionInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_GetLSPID
==============
*/
const char *SV_GetLSPID()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_GetLSPPort
==============
*/
int SV_GetLSPPort()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_FakeDLC_ClientDisconnect
==============
*/
void Live_FakeDLC_ClientDisconnect()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_FakeDLC_ClientJoin
==============
*/
void Live_FakeDLC_ClientJoin(unsigned int contentFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_FakeDLC_GetFlags
==============
*/
unsigned int Live_FakeDLC_GetFlags()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MatchmakingHopper_UpdateState
==============
*/
void MatchmakingHopper_UpdateState(matchmakingHopperState_t newState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchmakingHopper_Init
==============
*/
void MatchmakingHopper_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchmakingHopper_ClientJoin
==============
*/
char MatchmakingHopper_ClientJoin(int memberPlaylist)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MatchmakingHopper_Frame
==============
*/
void MatchmakingHopper_Frame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatchmakingHopper_isParked
==============
*/
BOOL MatchmakingHopper_isParked()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Live_SetPingTestKey
==============
*/
void Live_SetPingTestKey()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_Base_StateConnected
==============
*/
void Live_Base_StateConnected(const ControllerIndex_t controllerIndex, dediUserData_t *userData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_Base_PumpForController
==============
*/
void Live_Base_PumpForController(dediUserData_t *a1, ControllerIndex_t a2, const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_Base_Pump
==============
*/
void Live_Base_Pump()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_HandleDemonwareLSP
==============
*/
void Live_HandleDemonwareLSP(dediUserData_t *a1, ControllerIndex_t a2, ControllerIndex_t localControllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Live_DedicatedFrame
==============
*/
/*void Live_DedicatedFrame(int a1@<ebp>)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

