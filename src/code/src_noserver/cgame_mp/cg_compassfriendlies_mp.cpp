#include "types.h"
#include "functions.h"

/*
==============
TRACK_cg_compassfriendlies
==============
*/
void TRACK_cg_compassfriendlies()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ClearCompassPingData
==============
*/
void CG_ClearCompassPingData()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetRadarLineMargin
==============
*/
float GetRadarLineMargin(cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DoesMovementCrossRadar
==============
*/
bool DoesMovementCrossRadar(cg_t *cgameGlob, float radarProgress, const vec2_t *p1, const vec2_t *p2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DoLinesSurroundPoint
==============
*/
bool DoLinesSurroundPoint(cg_t *cgameGlob, vec3_t *radarLine1, vec3_t *radarLine2, vec2_t *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RadarPingEnemyPlayer
==============
*/
void RadarPingEnemyPlayer(LocalClientNum_t localClientNum, CompassActor *actor, int time, int PerkToIgnore)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SatellitePingEnemyPlayer
==============
*/
void SatellitePingEnemyPlayer(LocalClientNum_t localClientNum, CompassActor *actor, int time, int PerkToIgnore)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CanLocalPlayerHearActorFootsteps
==============
*/
bool CanLocalPlayerHearActorFootsteps(LocalClientNum_t localClientNum, const vec3_t *actorPos, int actorClientIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ActorUpdatePos
==============
*/
void ActorUpdatePos(LocalClientNum_t localClientNum, CompassActor *actor, const vec3_t *newPos, int actorClientIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetVehicle
==============
*/
CompassVehicle *GetVehicle(LocalClientNum_t localClientNum, int entityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GetHelicopter
==============
*/
CompassHelicopter *GetHelicopter(LocalClientNum_t localClientNum, int entityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GetGuidedMissile
==============
*/
CompassGuidedMissile *GetGuidedMissile(LocalClientNum_t localClientNum, int entityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GetDogs
==============
*/
CompassDogs *GetDogs(LocalClientNum_t localClientNum, int entityNum, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GetZombie
==============
*/
CompassZombie *GetZombie(LocalClientNum_t localClientNum, int entityNum, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GetCompassTurrets
==============
*/
CompassTurrets *GetCompassTurrets(LocalClientNum_t localClientNum, int entityNum, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_CompassUpdateVehicleDef
==============
*/
void CG_CompassUpdateVehicleDef(LocalClientNum_t localClientNum, int entityIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CompassUpdateHelicopterInfo
==============
*/
void CG_CompassUpdateHelicopterInfo(LocalClientNum_t localClientNum, int entityIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CompassUpdateGuidedMissileInfo
==============
*/
void CG_CompassUpdateGuidedMissileInfo(LocalClientNum_t localClientNum, const centity_t *missile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CompassUpdateVehicleOccupantInfo
==============
*/
void CG_CompassUpdateVehicleOccupantInfo(LocalClientNum_t localClientNum, int entityIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CompassUpdateDogInfo
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_CompassUpdateZombieInfo
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_CompassUpdateTurretInfo
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_CompassRadarPingEnemyVehicles
==============
*/
void CG_CompassRadarPingEnemyVehicles(LocalClientNum_t localClientNum, float oldRadarProgress, float newRadarProgress, float oldLocalRadarProgress, float newLocalRadarProgress)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CompassRadarPingEnemyTurrets
==============
*/
void CG_CompassRadarPingEnemyTurrets(LocalClientNum_t localClientNum, float oldRadarProgress, float newRadarProgress, float oldLocalRadarProgress, float newLocalRadarProgress)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CompassRadarPingEnemyPlayers
==============
*/
void CG_CompassRadarPingEnemyPlayers(LocalClientNum_t localClientNum, float oldRadarProgress, float newRadarProgress, float oldLocalRadarProgress, float newLocalRadarProgress)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CompassIncreaseRadarTime
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_SensorGrenadePingPlayer
==============
*/
void CG_SensorGrenadePingPlayer(LocalClientNum_t localClientNum, const clientInfo_t *ci, int time, bool explosionTag)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AddTurretWeaponPingInfo
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_CompassAddWeaponPingInfoInternal
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_CompassAddWeaponPingInfo
==============
*/
void CG_CompassAddWeaponPingInfo(LocalClientNum_t localClientNum, const centity_t *cent, const vec3_t *origin, int msec, bool isSuppressedFire)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CompassAddVehicleWeaponPingInfo
==============
*/
void CG_CompassAddVehicleWeaponPingInfo(LocalClientNum_t localClientNum, const centity_t *cent, const vec3_t *origin, int msec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_FindFakeFireActor
==============
*/
CompassFakeFire *CG_FindFakeFireActor(LocalClientNum_t localClientNum, const int playerIndex, const int entNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_CompassAddFakeFirePingInfo
==============
*/
void CG_CompassAddFakeFirePingInfo(LocalClientNum_t localClientNum, const int ownerNum, const int entNum, const vec3_t *origin, const vec3_t *dir, int msec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AddEnemyScrambler
==============
*/
void CG_AddEnemyScrambler(LocalClientNum_t localClientNum, centity_t *scramblerEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ClearNearestEnemyScrambler
==============
*/
void CG_ClearNearestEnemyScrambler(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AddFriendlyScrambler
==============
*/
void CG_AddFriendlyScrambler(LocalClientNum_t localClientNum, float x, float y, int handle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RemoveFriendlyScrambler
==============
*/
void CG_RemoveFriendlyScrambler(LocalClientNum_t localClientNum, int handle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RemoveAllFriendlyScramblers
==============
*/
void CG_RemoveAllFriendlyScramblers(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CompassUpdateActors
==============
*/
void CG_CompassUpdateActors(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AddArtilleryPing
==============
*/
void CG_AddArtilleryPing(LocalClientNum_t localClientNum, vec3_t *position)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateCompassObituary
==============
*/
void CG_UpdateCompassObituary(LocalClientNum_t localClientNum, int client)
{
	UNIMPLEMENTED(__FUNCTION__);
}

