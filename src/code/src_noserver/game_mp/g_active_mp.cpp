#include "types.h"
#include "functions.h"

/*
==============
G_PlayerStateToEntityStateExtrapolate
==============
*/
void G_PlayerStateToEntityStateExtrapolate(playerState_s *ps, entityState_s *s, int time, int snap)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_AddPlayerMantleBlockage
==============
*/
void G_AddPlayerMantleBlockage(vec3_t *endPos, int duration, pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_DrawServerAiming
==============
*/
void G_DrawServerAiming(const gclient_t *client)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_BuildWeaponState
==============
*/
void G_BuildWeaponState(gclient_t *client, const viewState_t *vs, weaponState_t *ws, usercmd_s *ucmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SaveWeaponState
==============
*/
void G_SaveWeaponState(const weaponState_t *ws, gclient_t *client)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_UpdateClientControlledMissile
==============
*/
void G_UpdateClientControlledMissile(const playerState_s *ps, const usercmd_s *cmd, int msec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_UpdateVehicleControlledEntity
==============
*/
void G_UpdateVehicleControlledEntity(gentity_t *player)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ClientThink_ShouldUpdateAngleFromViewangle
==============
*/
bool ClientThink_ShouldUpdateAngleFromViewangle(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IntermissionClientEndFrame
==============
*/
void IntermissionClientEndFrame(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_ClientCanSpectateTeamOrLocalPlayer
==============
*/
BOOL G_ClientCanSpectateTeamOrLocalPlayer(gclient_t *client, clientState_s *cs)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_ClientCanOnlySpectateLocalPlayer
==============
*/
BOOL G_ClientCanOnlySpectateLocalPlayer(gclient_t *client)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_UpdateClientInfo
==============
*/
int G_UpdateClientInfo(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_AddClientKnife
==============
*/
void G_AddClientKnife(clientInfo_t *ci, playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UpdateViewAngleLerp
==============
*/
void UpdateViewAngleLerp(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ClientVehicleInteraction
==============
*/
void ClientVehicleInteraction(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_PlayerVehiclePositionAndBlend
==============
*/
void G_PlayerVehiclePositionAndBlend(gentity_t *ent, gentity_t *pTurretEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ClientEndFrame
==============
*/
void ClientEndFrame(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ClientThink_real
==============
*/
void ClientThink_real(gentity_t *ent, usercmd_s *ucmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_RunClient
==============
*/
void G_RunClient(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

