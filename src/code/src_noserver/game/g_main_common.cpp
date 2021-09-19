#include "types.h"
#include "functions.h"

/*
==============
TRACK_g_main
==============
*/
void TRACK_g_main()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetSavePersist
==============
*/
int G_GetSavePersist()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_SetSavePersist
==============
*/
void G_SetSavePersist(int savepersist)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetClientScore
==============
*/
int G_GetClientScore(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_GetClientDeaths
==============
*/
int G_GetClientDeaths(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_GetClientArchiveTime
==============
*/
int G_GetClientArchiveTime(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_SetClientArchiveTime
==============
*/
void G_SetClientArchiveTime(ClientNum_t clientNum, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetClientState
==============
*/
clientState_s *G_GetClientState(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_GetPlayerState
==============
*/
gclient_t *G_GetPlayerState(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Hunk_AllocActorXAnimServer
==============
*/
void *Hunk_AllocActorXAnimServer(int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_GetActorState
==============
*/
actorState_s *G_GetActorState(int actorNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_GetClientSize
==============
*/
int G_GetClientSize()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_GetActorSize
==============
*/
int G_GetActorSize()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_CreateDObj
==============
*/
void G_CreateDObj(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetDObj
==============
*/
DObj *G_GetDObj(int handle, LocalClientNum_t unusedLocalClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_SafeDObjFree
==============
*/
void G_SafeDObjFree(int handle, LocalClientNum_t unusedLocalClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Hunk_AllocXAnimServer
==============
*/
void *Hunk_AllocXAnimServer(int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_IsServerGameSystem
==============
*/
int G_IsServerGameSystem(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_AttachWeapon
==============
*/
unsigned __int16 G_AttachWeapon(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SortRanks
==============
*/
int SortRanks(const void *a, const void *b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_ExitAfterConnectPaths
==============
*/
bool G_ExitAfterConnectPaths()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_ExitOnComError
==============
*/
bool G_ExitOnComError(int code)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CalculateRanks
==============
*/
void CalculateRanks()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_IsEntWalkable
==============
*/
BOOL G_IsEntWalkable(LocalClientNum_t localClientNum, int entityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_GetEntityOriginAngles
==============
*/
bool G_GetEntityOriginAngles(LocalClientNum_t localClientNum, int entityNum, vec3_t *origin, vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_GetVelocity
==============
*/
char G_GetVelocity(LocalClientNum_t localClientNum, int entIndex, vec3_t *outVelocity)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_EntityLinkFromPMove
==============
*/
void G_EntityLinkFromPMove(int entityNum, int parentEntityNum, const int tagName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_LogPrintf
==============
*/
void G_LogPrintf(const char *fmt, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ExitLevel
==============
*/
void ExitLevel()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SafeDObjFree
==============
*/
void G_SafeDObjFree(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

