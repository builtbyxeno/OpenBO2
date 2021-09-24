#include "types.h"

/*
==============
GetFollowPlayerState
==============
*/
int GetFollowPlayerState(ClientNum_t clientNum, playerState_s *ps, bool allowLastActive)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
StuckInClient
==============
*/
int StuckInClient(gentity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_PlayerEvent
==============
*/
void G_PlayerEvent(int clientNum, int event)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
P_DamageFeedback
==============
*/
void P_DamageFeedback(gentity_t *player)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Player_WaterUpdate
==============
*/
void Player_WaterUpdate(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_TouchEnts
==============
*/
void G_TouchEnts(gentity_t *ent, int numtouch, int *touchents)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ClientImpacts
==============
*/
void ClientImpacts(gentity_t *ent, pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_DoTouchTriggers
==============
*/
void G_DoTouchTriggers(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_ClientCanSpectateTeam
==============
*/
BOOL G_ClientCanSpectateTeam(gclient_t *client, team_t team)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_ClientCanSpectateAnyTeams
==============
*/
int G_ClientCanSpectateAnyTeams(gclient_t *client, int teamsMask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_ClientCanSpectateDead
==============
*/
BOOL G_ClientCanSpectateDead(gclient_t *client)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NotifyGrenadePullback
==============
*/
void NotifyGrenadePullback(gentity_t *ent, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IsLiveGrenade
==============
*/
bool IsLiveGrenade(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AttemptLiveGrenadePickup
==============
*/
void AttemptLiveGrenadePickup(gentity_t *clientEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NotifyWeaponSwitchStarted
==============
*/
void NotifyWeaponSwitchStarted(gentity_t *ent, const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SetLastServerTime
==============
*/
void G_SetLastServerTime(ClientNum_t clientNum, int lastServerTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SetClientContents
==============
*/
void G_SetClientContents(gentity_t *pEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpectatorClientEndFrame
==============
*/
void SpectatorClientEndFrame(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ClientThink
==============
*/
void ClientThink(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_PlayerController
==============
*/
void G_PlayerController(const gentity_t *self, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetPlayer
==============
*/
gentity_t *G_GetPlayer(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
ClientInactivityTimer
==============
*/
int ClientInactivityTimer(gclient_t *client)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ClientEvents
==============
*/
void ClientEvents(gentity_t *ent, int oldEventSequence)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpectatorThink
==============
*/
void SpectatorThink(gentity_t *ent, usercmd_s *ucmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ClientIntermissionThink
==============
*/
void ClientIntermissionThink(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

