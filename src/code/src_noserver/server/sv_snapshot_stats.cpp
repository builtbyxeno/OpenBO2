#include "types.h"

/*
==============
SV_AddModifiedStatsWithinOffset
==============
*/
int SV_AddModifiedStatsWithinOffset(ClientNum_t clientNum, int startOffset, int *endOffset, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_StatSign_Init
==============
*/
void SV_StatSign_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_CalcStatsHash
==============
*/
void SV_CalcStatsHash(unsigned int rankxp, unsigned int plevel, unsigned __int64 xuid, unsigned __int8 (*hash)[24], unsigned int *hashSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
getCachedStatsHashForClient
==============
*/
unsigned __int8 (*getCachedStatsHashForClient(client_t *client))[24]
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
getCachedSignedStatsHashForClient
==============
*/
signedStatsHash_t *getCachedSignedStatsHashForClient(client_t *client)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_StatSign_SetCheckSumForClient
==============
*/
char SV_StatSign_SetCheckSumForClient(client_t *client)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
actionOnBadStats
==============
*/
void actionOnBadStats(client_t *client, const unsigned __int64 clientXUID, const dvar_t *dvar, const char *bbstring)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SignedStats_Breadcrumb
==============
*/
void SV_SignedStats_Breadcrumb(client_t *client)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SignedStats_VerifyClient
==============
*/
bool SV_SignedStats_VerifyClient(char *a1, client_t *client)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_AddModifiedStats
==============
*/
void SV_AddModifiedStats(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

