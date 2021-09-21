#include "types.h"
#include "functions.h"

/*
==============
CG_AddPlayerSpriteDrawSurf
==============
*/
void CG_AddPlayerSpriteDrawSurf(LocalClientNum_t localClientNum, const centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AddPlayerSpriteDrawSurfs
==============
*/
void CG_AddPlayerSpriteDrawSurfs(LocalClientNum_t localClientNum, const centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AddAllPlayerSpriteDrawSurfs
==============
*/
void CG_AddAllPlayerSpriteDrawSurfs(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Player_ApplyVehicleAnimOffsets
==============
*/
char CG_Player_ApplyVehicleAnimOffsets(LocalClientNum_t localClientNum, const entityState_s *es, centity_t *cent, clientInfo_t *ci)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_PlayerUpdateUserRigidBody
==============
*/
void CG_PlayerUpdateUserRigidBody(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdatePerkSounds
==============
*/
void CG_UpdatePerkSounds(LocalClientNum_t localClientNum, const cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetPlayerVelocity
==============
*/
void CG_GetPlayerVelocity(LocalClientNum_t localClientNum, centity_t *cent, vec3_t *velocity_out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DropWeaponClip
==============
*/
void CG_DropWeaponClip(LocalClientNum_t localClientNum, clientInfo_t *ci, centity_t *cent, const Weapon weapon, DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ClearDropWeaponClip
==============
*/
void CG_ClearDropWeaponClip(LocalClientNum_t localClientNum, int clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdatePlayerDObj
==============
*/
void CG_UpdatePlayerDObj(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ResetPlayerEntity
==============
*/
void CG_ResetPlayerEntity(LocalClientNum_t localClientNum, cg_t *cgameGlob, centity_t *cent, int resetAnimation)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PlayerDobjChanging
==============
*/
void CG_PlayerDobjChanging(LocalClientNum_t localClientNum, clientInfo_t *ci, const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetFFATeamName
==============
*/
const char *CG_GetFFATeamName(ffa_team_t team)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_GetOpposingTeamName
==============
*/
const char *CG_GetOpposingTeamName(team_t team)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_GetPlayerTeamName
==============
*/
const char *CG_GetPlayerTeamName(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_GetPlayerOpposingTeamName
==============
*/
const char *CG_GetPlayerOpposingTeamName(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_GetClientInfo
==============
*/
clientInfo_t *CG_GetClientInfo(const LocalClientNum_t localClientNum, ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_IsPlayerDead
==============
*/
bool CG_IsPlayerDead(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetPlayerClipAmmoCount
==============
*/
int CG_GetPlayerClipAmmoCount(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_ShouldSendPeerVoiceData
==============
*/
char CG_ShouldSendPeerVoiceData(SessionData *session, const LocalClientNum_t localClientNum, const ClientNum_t player)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_IsWeaponVisible
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_UpdateWeaponVisibilityInternal
==============
*/
void CG_UpdateWeaponVisibilityInternal(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateWeaponVisibilityImmediate
==============
*/
void CG_UpdateWeaponVisibilityImmediate(centity_t *a1, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PlayerInViewFrustum
==============
*/
bool CG_PlayerInViewFrustum(LocalClientNum_t localClientNum, const centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_ClientHasPerk
==============
*/
bool CG_ClientHasPerk(LocalClientNum_t localClientNum, ClientNum_t clientNum, unsigned int perkIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CopyPerks
==============
*/
void CG_CopyPerks(LocalClientNum_t localClientNum, ClientNum_t clientNum, unsigned int *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PlayerTurretPositionAndBlend
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_PlayerInfrared
==============
*/
int CG_PlayerInfrared(LocalClientNum_t localClientNum, centity_t *cent, clientInfo_t *ci, DObj *obj, bool corpse, int *textureOverrideIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_PlayerSonar
==============
*/
unsigned int CG_PlayerSonar(LocalClientNum_t localClientNum, centity_t *cent, clientInfo_t *ci, bool corpse)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Player
==============
*/
void CG_Player(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Corpse
==============
*/
void CG_Corpse(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

