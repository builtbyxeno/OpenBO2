#include "types.h"
#include "functions.h"

/*
==============
SV_DoWeHaveAllStatsPackets
==============
*/
bool SV_DoWeHaveAllStatsPackets(client_t *cl, int numCompressedPackets)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_ReceiveStats
==============
*/
void SV_ReceiveStats(netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_CacheClientStatChange
==============
*/
void SV_CacheClientStatChange(ClientNum_t clientNum, ddlState_t *searchState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SetClientStat
==============
*/
void SV_SetClientStat(ClientNum_t clientNum, ddlState_t *searchState, ddlValue_t value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SetClientInt64Stat
==============
*/
void SV_SetClientInt64Stat(ClientNum_t clientNum, ddlState_t *searchState, unsigned __int64 value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SetClientFixedPointStat
==============
*/
void SV_SetClientFixedPointStat(ClientNum_t clientNum, ddlState_t *searchState, float value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SetClientStringStat
==============
*/
void SV_SetClientStringStat(ClientNum_t clientNum, ddlState_t *searchState, const char *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_GetClientStat
==============
*/
int SV_GetClientStat(ClientNum_t clientNum, ddlState_t *searchState, ddlValue_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_GetClientIntStat
==============
*/
int SV_GetClientIntStat(ClientNum_t clientNum, ddlState_t *searchState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_GetClientStringStat
==============
*/
const GfxViewParms *SV_GetClientStringStat(ClientNum_t clientNum, ddlState_t *searchState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_GetClientInt64Stat
==============
*/
ddlValue_t SV_GetClientInt64Stat(ClientNum_t clientNum, ddlState_t *searchState)
{
	UNIMPLEMENTED(__FUNCTION__);
	ddlValue_t tmp;
	return tmp;
}

/*
==============
SV_GetClientFixedPointStat
==============
*/
double SV_GetClientFixedPointStat(ClientNum_t clientNum, ddlState_t *searchState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_UploadStatsForClient
==============
*/
void SV_UploadStatsForClient(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_UploadStats
==============
*/
void SV_UploadStats()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_AuthClient
==============
*/
void SV_AuthClient(netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_LogConfigStrings
==============
*/
void SV_LogConfigStrings()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_WriteConfigStrings
==============
*/
void SV_WriteConfigStrings(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

