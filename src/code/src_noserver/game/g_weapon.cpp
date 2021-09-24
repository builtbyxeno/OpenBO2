#include "types.h"

/*
==============
Weapon_SetWeaponParamsWeapon
==============
*/
void Weapon_SetWeaponParamsWeapon(weaponParms *wp, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_AntiLagRewindClientPos
==============
*/
void G_AntiLagRewindClientPos(int gameTime, AntilagClientStore *antilagStore)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_AntiLagRewindClientIndexPos
==============
*/
void G_AntiLagRewindClientIndexPos(int clientNum, AntilagClientStore *antilagClients)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_AntiLag_RestoreClientPos
==============
*/
void G_AntiLag_RestoreClientPos(AntilagClientStore *antilagStore)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetActorAntilagFrame
==============
*/
actorAntilagFrame_t *G_GetActorAntilagFrame(int *time)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_GetActorPositionsFromCache
==============
*/
void G_GetActorPositionsFromCache(actorAntilagFrame_t *frame, vec3_t **pos, vec3_t **angles, bool *success)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetActorPositionsAtTime
==============
*/
bool G_GetActorPositionsAtTime(int gametime, vec3_t *pos, vec3_t *angles, bool *success)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_AntiLag_RewindActorPos
==============
*/
void G_AntiLag_RewindActorPos(int gameTime, antilagActorStore_t *antilagStore)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_AntiLag_RestoreActorPos
==============
*/
void G_AntiLag_RestoreActorPos(antilagActorStore_t *antilagStore)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_ArchiveActorAntilagFrame
==============
*/
void G_ArchiveActorAntilagFrame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetVehicleAntilagFrame
==============
*/
vehicleAntilagFrame_t *G_GetVehicleAntilagFrame(int *time)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_GetVehiclePositionsFromCache
==============
*/
void G_GetVehiclePositionsFromCache(vehicleAntilagFrame_t *frame, vec3_t **pos, vec3_t **angles, bool *success)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetVehiclePositionsAtTime
==============
*/
bool G_GetVehiclePositionsAtTime(int gametime, vec3_t *pos, vec3_t *angles, bool *success)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_AntiLag_RewindVehiclePos
==============
*/
void G_AntiLag_RewindVehiclePos(char *a1, int gameTime, antilagVehicleStore_t *antilagStore)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_AntiLag_RestoreVehiclePos
==============
*/
void G_AntiLag_RestoreVehiclePos(antilagVehicleStore_t *antilagStore)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_ArchiveVehicleAntilagFrame
==============
*/
void G_ArchiveVehicleAntilagFrame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Weapon_Throw_Grenade
==============
*/
gentity_t *Weapon_Throw_Grenade(gentity_t *ent, Weapon grenType, unsigned __int8 grenModel, weaponParms *wp, bool pumpScripts)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Weapon_GrenadeLauncher_Fire
==============
*/
gentity_t *Weapon_GrenadeLauncher_Fire(gentity_t *ent, Weapon grenType, unsigned __int8 grenModel, weaponParms *wp, bool pumpScripts)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Weapon_RocketLauncher_Fire
==============
*/
gentity_t *Weapon_RocketLauncher_Fire(gentity_t *ent, Weapon weapon, float spread, weaponParms *wp, const vec3_t *gunVel, gentity_t *target, const vec3_t *targetOffset, bool pumpScripts)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Weapon_BombDrop_Fire
==============
*/
gentity_t *Weapon_BombDrop_Fire(gentity_t *ent, Weapon weapon, float spread, weaponParms *wp, const vec3_t *gunVel, gentity_t *target, const vec3_t *targetOffset)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Weapon_Overheat_Update
==============
*/
void Weapon_Overheat_Update(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Weapon_Flamethrower_Update
==============
*/
void Weapon_Flamethrower_Update(gentity_t *ent, weaponParms *wp)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Weapon_Flamethrower_Fire
==============
*/
void Weapon_Flamethrower_Fire(gentity_t *ent, weaponParms *wp)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LogAccuracyHit
==============
*/
BOOL LogAccuracyHit(gentity_t *target, gentity_t *attacker)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_CalcMuzzlePoints
==============
*/
void G_CalcMuzzlePoints(const gentity_t *ent, weaponParms *wp, int shotCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetWeaponDefBasedOnNumberOfBullets
==============
*/
Weapon G_GetWeaponDefBasedOnNumberOfBullets(int numBulletsQueued, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
FireWeapon
==============
*/
void FireWeapon(gentity_t *ent, int gametime, int shotCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DeployWeapon
==============
*/
void DeployWeapon(unsigned int a1, clientDebugLineInfo_t *a2, gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BreakDownWeapon
==============
*/
void BreakDownWeapon(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_UseOffHand
==============
*/
void G_UseOffHand(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_UpdatePlayerWeaponOptions
==============
*/
void G_UpdatePlayerWeaponOptions(playerState_s *pPS, Weapon weapon, renderOptions_s weaponOptions)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetWeaponForName_Internal
==============
*/
Weapon G_GetWeaponForName_Internal(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
G_GetWeaponForName
==============
*/
Weapon G_GetWeaponForName(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
G_GetBaseWeaponItemIndex
==============
*/
int G_GetBaseWeaponItemIndex(const char *pszWeaponName, int *attachmentBits, int *weaponIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_SelectWeapon
==============
*/
void G_SelectWeapon(ClientNum_t clientNum, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SetEquippedOffHand
==============
*/
void G_SetEquippedOffHand(ClientNum_t clientNum, Weapon offHandWeapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_PlayerTurretWeapon
==============
*/
Weapon G_PlayerTurretWeapon(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
G_GetPlayerVehicleWeapon
==============
*/
Weapon G_GetPlayerVehicleWeapon(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
G_GetPlayerWeapon
==============
*/
Weapon G_GetPlayerWeapon(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
G_GetShieldTagName
==============
*/
unsigned int G_GetShieldTagName(const gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_GetShieldTagMatrix
==============
*/
char G_GetShieldTagMatrix(const gentity_t *ent, vec3_t *resultMatrix)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_AddShieldSplashDamageEvent
==============
*/
void G_AddShieldSplashDamageEvent(gentity_t *ent, float originalDamageRawPoints, float originalDamageScale, float shieldProtection)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Melee_Trace
==============
*/
bool Melee_Trace(gentity_t *ent, vec3_t *hitOrigin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Weapon_Melee_NotifyClient
==============
*/
void Weapon_Melee_NotifyClient(gentity_t *attacker, gentity_t *victim, int eventType, const Weapon weapon, vec3_t *hitOrigin, vec3_t *hitDir, unsigned __int16 boneIndex, bool shieldHit)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Weapon_Melee_internal
==============
*/
gentity_t *Weapon_Melee_internal(gentity_t *ent, weaponParms *wp)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Weapon_Melee
==============
*/
gentity_t *Weapon_Melee(gentity_t *ent, weaponParms *wp, float range, float width, float height, int gametime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Weapon_Napalm_Flame
==============
*/
void Weapon_Napalm_Flame(gentity_t *ent, trace_t *trace, int count)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FireWeaponMelee
==============
*/
void FireWeaponMelee(gentity_t *ent, int gametime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GivePlayerWeapon
==============
*/
int G_GivePlayerWeapon(playerState_s *pPS, Weapon weapon, unsigned __int8 altModelIndex, renderOptions_s weaponOptions)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_SetupWeaponDef
==============
*/
void G_SetupWeaponDef()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetShieldCosOfAngleToPoint
==============
*/
double G_GetShieldCosOfAngleToPoint(const gentity_t *shieldHolder, const vec3_t *point)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_GetShieldTagNormal
==============
*/
void G_GetShieldTagNormal(const gentity_t *ent, vec3_t *resultNormal)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetShieldBlastDamageProtection
==============
*/
double G_GetShieldBlastDamageProtection(gentity_t *ent, const vec3_t *blastOrigin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

