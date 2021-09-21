#include "types.h"
#include "functions.h"

/*
==============
InitClientDeltaAngles
==============
*/
void InitClientDeltaAngles(gclient_t *client)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SetClientViewAngle
==============
*/
void SetClientViewAngle(gentity_t *ent, const vec3_t *angle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ClientCleanName
==============
*/
void ClientCleanName(const char *in, char *out, int outSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ClientUserinfoChanged
==============
*/
void ClientUserinfoChanged(char *name, ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ClientBegin
==============
*/
void ClientBegin(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ClientDisconnect
==============
*/
void ClientDisconnect(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetNonPVSPlayerInfo
==============
*/
unsigned int G_GetNonPVSPlayerInfo(gentity_t *pSelf, vec3_t *vPosition, int iLastUpdateEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
OnSameTeam
==============
*/
BOOL OnSameTeam(gentity_t *ent1, gentity_t *ent2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_GetViewOriginMissingTag
==============
*/
void G_GetViewOriginMissingTag(const playerState_s *ps, vec3_t *origin, const char *type)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_Player3rdPersonVehicle_GetDampedSpringDistance
==============
*/
float G_Player3rdPersonVehicle_GetDampedSpringDistance(const gentity_t *vehicle, const VehicleDef *info, float camDefaultDist)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_GetPlayerVehicleViewOrigin_Internal
==============
*/
void G_GetPlayerVehicleViewOrigin_Internal(const playerState_s *ps, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_Player3rdPersonVehicle_GetViewAngles
==============
*/
void G_Player3rdPersonVehicle_GetViewAngles(const playerState_s *ps, const gentity_t *vehicle, const VehicleDef *info, vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_Player3rdPersonVehicle_GetLookAtPosition
==============
*/
void G_Player3rdPersonVehicle_GetLookAtPosition(const gentity_t *vehicle, const VehicleDef *info, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ClientConnect
==============
*/
const char *ClientConnect(char *a1, ClientNum_t clientNum, unsigned __int16 scriptPersId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_GetPlayer3rdPersonVehicleViewOrigin
==============
*/
void G_GetPlayer3rdPersonVehicleViewOrigin(unsigned int a1, const playerState_s *ps, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetPlayerVehicleViewOrigin
==============
*/
void G_GetPlayerVehicleViewOrigin(const playerState_s *ps, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ClientSpawn
==============
*/
void ClientSpawn(gentity_t *ent, const vec3_t *spawn_origin, const vec3_t *spawn_angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

