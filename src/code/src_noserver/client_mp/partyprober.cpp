#include "types.h"

/*
==============
PartyInfo_SetFlag
==============
*/
void PartyInfo_SetFlag(PartyInfo *party, int flag, bool enable)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyInfo_GetFlag
==============
*/
bool PartyInfo_GetFlag(PartyInfo *party, int flag)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyInfo_GetGeoMatch
==============
*/
int PartyInfo_GetGeoMatch(const PartyInfo *host)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PrettyFlags
==============
*/
char *PrettyFlags(int flags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
PartyProber_SetState
==============
*/
void PartyProber_SetState(PartyProber *prober, ProberState state, const char *reason)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyProber_GetStateAsString
==============
*/
const char *PartyProber_GetStateAsString(PartyProber *prober)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
PartyProber_SetAcceptInfo
==============
*/
void PartyProber_SetAcceptInfo(PartyProber *prober, int partyId, int challenge, int hostNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyProber_MarkReceived
==============
*/
void PartyProber_MarkReceived(PartyProber *prober)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyProber_GetHostCount
==============
*/
int PartyProber_GetHostCount(PartyProber *prober, int matchingFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyProber_ClearHosts
==============
*/
void PartyProber_ClearHosts(PartyProber *prober)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyProber_Clear
==============
*/
void __cdecl PartyProber_Clear(PartyProber *prober)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyProber_StartInvite
==============
*/
void __cdecl PartyProber_StartInvite(PartyProber *prober, ControllerIndex_t controllerIndex, XSESSION_INFO *hostInfo, int numPublicSlots, int occupiedPublicSlots, bool isDedicated)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyProber_StartNewlobby
==============
*/
void __cdecl PartyProber_StartNewlobby(PartyProber *prober, ControllerIndex_t controllerIndex, XSESSION_INFO *hostInfo, int challenge, int hostNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyProber_FindByXNAddr
==============
*/
int PartyProber_FindByXNAddr(PartyProber *prober, const XNADDR *key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyProber_AddHost
==============
*/
void PartyProber_AddHost(const XNADDR *a1, PartyProber *prober, const XSESSION_INFO *info, const int publicSlots, const int occupiedPublicSlots, const float skill, const int geo1, const int geo2, const int geo3, const int geo4, int mapPacks)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyProber_StoreQoSResult
==============
*/
char PartyProber_StoreQoSResult(PartyProber *prober, const XNADDR *addr, int ping, int uploadBandwidth, const qosPayload_t *qosPayload)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyProber_Connect
==============
*/
bool PartyProber_Connect(XSESSION_INFO *info, bool dedicated, netadr_t *addr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyProber_HandlePartyAccept
==============
*/
bool PartyProber_HandlePartyAccept(PartyProber *prober, int partyId, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyProber_HandlePartyJoinFailed
==============
*/
bool PartyProber_HandlePartyJoinFailed(PartyProber *prober, int partyId, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyProber_HandleEchoReply
==============
*/
bool PartyProber_HandleEchoReply(PartyProber *prober, int partyId, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyProber_HandleMasterRequest
==============
*/
bool PartyProber_HandleMasterRequest(PartyProber *prober, const int partyId, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyProber_HandleMasterReply
==============
*/
char PartyProber_HandleMasterReply(PartyProber *prober, int partyId, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyProber_HandlePacket
==============
*/
char __cdecl PartyProber_HandlePacket(PartyProber *prober, const char *c, ControllerIndex_t localControllerIndex, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyProber_GetStatus
==============
*/
PartyProberStatus PartyProber_GetStatus(PartyProber *prober, int partyId)
{
	UNIMPLEMENTED(__FUNCTION__);
	PartyProberStatus tmp;
	return tmp;
}

/*
==============
PartyProber_GetSearchStartUTC
==============
*/
int PartyProber_GetSearchStartUTC(PartyProber *prober)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyProber_IsSearching
==============
*/
BOOL PartyProber_IsSearching(PartyProber *prober)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PartyProber_StartQoS
==============
*/
void PartyProber_StartQoS(PartyProber *prober)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PartyProber_QoSComplete
==============
*/
void PartyProber_QoSComplete(ProberState a1, PartyProber *a2, PartyProber *prober)
{
	UNIMPLEMENTED(__FUNCTION__);
}

