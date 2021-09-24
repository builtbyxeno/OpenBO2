#include "types.h"

/*
==============
TRACK_g_combat
==============
*/
void TRACK_g_combat()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_ParseHitLocDmgTable
==============
*/
void G_ParseHitLocDmgTable()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LookAtKiller
==============
*/
void LookAtKiller(gentity_t *self, gentity_t *inflictor, gentity_t *attacker)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_MeansOfDeathFromScriptParam
==============
*/
meansOfDeath_t G_MeansOfDeathFromScriptParam(int scrParam)
{
	UNIMPLEMENTED(__FUNCTION__);
	meansOfDeath_t tmp;
	return tmp;
}

/*
==============
DeathGrenadeDrop
==============
*/
void DeathGrenadeDrop(gentity_t *self, int meansOfDeath)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
player_die
==============
*/
void player_die(gentity_t *self, gentity_t *inflictor, gentity_t *attacker, int damage, int meansOfDeath, Weapon iWeapon, const vec3_t *vDir, const hitLocation_t hitLoc, int psTimeOffset)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetWeaponHitLocationMultiplier
==============
*/
double G_GetWeaponHitLocationMultiplier(hitLocation_t hitLoc, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_GetWeaponForEntity
==============
*/
Weapon G_GetWeaponForEntity(const gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
G_DetectLaggedDamage
==============
*/
void G_DetectLaggedDamage(gentity_t *targ, gentity_t *inflictor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_DamageClient
==============
*/
void G_DamageClient(gentity_t *targ, gentity_t *inflictor, gentity_t *attacker, const vec3_t *dir, const vec3_t *point, int damage, int dflags, int mod, Weapon weapon, hitLocation_t hitLoc, int timeOffset, unsigned __int16 boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_DamageActor
==============
*/
void G_DamageActor(gentity_t *targ, gentity_t *inflictor, gentity_t *attacker, const vec3_t *dir, const vec3_t *point, int damage, int dflags, int mod, Weapon weapon, hitLocation_t hitLoc, int timeOffset, unsigned __int16 boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_DamageVehicle
==============
*/
void G_DamageVehicle(gentity_t *targ, gentity_t *inflictor, gentity_t *attacker, const vec3_t *dir, const vec3_t *point, int damage, int dflags, int mod, Weapon weapon, hitLocation_t hitLoc, int timeOffset, unsigned int modelIndex, unsigned int partName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_DamageNotify
==============
*/
void G_DamageNotify(unsigned __int16 notify, gentity_t *targ, gentity_t *attacker, const vec3_t *dir, const vec3_t *point, int damage, int mod, int dFlags, unsigned int modelIndex, unsigned int partName, const char *weaponName, gentity_t *inflictor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_Damage
==============
*/
void G_Damage(gentity_t *targ, gentity_t *inflictor, gentity_t *attacker, const vec3_t *dir, const vec3_t *point, int damage, int dFlags, int mod, Weapon weapon, hitLocation_t hitLoc, unsigned int modelIndex, unsigned int partName, int timeOffset, unsigned __int16 boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_ShieldNotifyAndDamage
==============
*/
void G_ShieldNotifyAndDamage(gentity_t *targ, gentity_t *inflictor, gentity_t *attacker, const vec3_t *dir, const vec3_t *point, int damage, int dFlags, int mod, Weapon iWeapon, int timeOffset)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CanDamage
==============
*/
double CanDamage(gentity_t *targ, gentity_t *inflictor, const vec3_t *centerPos, float coneAngleCos, vec3_t *coneDirection, int contentMask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
EntDistToPoint
==============
*/
float EntDistToPoint(const vec3_t *origin, gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AddScrTeamName
==============
*/
void AddScrTeamName(team_t team)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetFlashbangViewPos
==============
*/
void GetFlashbangViewPos(gentity_t *ent, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetFlashbangViewDirection
==============
*/
void GetFlashbangViewDirection(gentity_t *ent, vec3_t *dir)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FlashbangBlastEnt
==============
*/
void FlashbangBlastEnt(gentity_t *ent, const vec3_t *blastOrigin, float radius_max, float radius_min, gentity_t *attacker, team_t team)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_FlashbangBlast
==============
*/
void G_FlashbangBlast(const vec3_t *origin, float radius_max, float radius_min, gentity_t *attacker, team_t team)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetRadiusDamageDistanceSquared
==============
*/
float G_GetRadiusDamageDistanceSquared(const vec3_t *damageOrigin, gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_WithinDamageRadius
==============
*/
double G_WithinDamageRadius(gentity_t *a1, const vec3_t *a2, const vec3_t *damageOrigin, float radiusSquared, gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_RadiusDamage
==============
*/
gentity_t *G_RadiusDamage(const vec3_t *origin, gentity_t *inflictor, gentity_t *attacker, float fInnerDamage, float fOuterDamage, float radius, float coneAngleCos, vec3_t *coneDirection, gentity_t *ignore, int mod, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_GetHitLocationString
==============
*/
unsigned __int16 G_GetHitLocationString(hitLocation_t hitLoc)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_GetHitLocationIndexFromString
==============
*/
hitLocation_t G_GetHitLocationIndexFromString(unsigned __int16 sString)
{
	UNIMPLEMENTED(__FUNCTION__);
	hitLocation_t tmp;
	return tmp;
}

/*
==============
G_SensorGrenadeDetonate
==============
*/
void G_SensorGrenadeDetonate(gentity_t *grenadeEnt, const WeaponDef *weapDef, gentity_t *grenadeOwnerEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MurderLine
==============
*/
void MurderLine(int a1, gentity_t *attacker, const Weapon weapon, vec3_t from, vec3_t to)
{
	UNIMPLEMENTED(__FUNCTION__);
}

