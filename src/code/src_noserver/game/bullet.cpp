#include "types.h"
#include "functions.h"

/*
==============
Bullet_RandomDir
==============
*/
void Bullet_RandomDir(unsigned int *randSeed, float *x, float *y)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bullet_Endpos
==============
*/
void Bullet_Endpos(float randSeed, char *a2, unsigned int *a3, float spread, vec3_t *end, vec3_t *dir, const weaponParms *wp, float maxRange, int shotIndex, int maxShotIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bullet_GetDamage
==============
*/
int Bullet_GetDamage(const BulletFireParams *bp, const BulletTraceResults *br, const Weapon weapon, gentity_t *attacker)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bullet_NofifyActor
==============
*/
void Bullet_NofifyActor(const BulletFireParams *bp, gentity_t *attacker, const vec3_t *start, const vec3_t *end, gentity_t *hitEnt, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SetTempEventEntNormal
==============
*/
void SetTempEventEntNormal(gentity_t *ent, const vec3_t *normal)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EncodeShieldHitPos
==============
*/
unsigned __int8 EncodeShieldHitPos(int entNum, const vec3_t *hitPos, const vec3_t *startPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bullet_IgnoreHitEntity
==============
*/
bool Bullet_IgnoreHitEntity(const BulletFireParams *bp, const BulletTraceResults *br, gentity_t *attacker)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bullet_Trace
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CalcRicochet
==============
*/
void CalcRicochet(const vec3_t *incoming, const vec3_t *normal, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_BulletCalcBounce
==============
*/
char BG_BulletCalcBounce(const vec3_t *incoming, const vec3_t *normal, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_WeaponBulletFire_ShouldBounce
==============
*/
bool BG_WeaponBulletFire_ShouldBounce(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_WeaponBulletFire_ShouldPenetrate
==============
*/
bool BG_WeaponBulletFire_ShouldPenetrate(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bullet_AddBBInfo
==============
*/
void Bullet_AddBBInfo(BulletTraceResults *br)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bullet_ReportBBInfo
==============
*/
void Bullet_ReportBBInfo(int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BroadcastShieldHitEvent
==============
*/
void BroadcastShieldHitEvent(const vec3_t *hitPos, const vec3_t *hitNormal, const vec3_t *startPos, int surfType, const Weapon weapon, int attackerEntNum, int victimEntNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BroadcastShieldHitEventToVictim
==============
*/
void BroadcastShieldHitEventToVictim(unsigned int *randSeed, const vec3_t *hitPos, const vec3_t *hitNormal, const vec3_t *startPos, const Weapon weapon, int attackerEntNum, int victimEntNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bullet_ImpactEffect
==============
*/
void Bullet_ImpactEffect(unsigned int *randSeed, const BulletFireParams *bp, const BulletTraceResults *br, const vec3_t *normal, const Weapon weapon, gentity_t *attacker, int impactEffectFlags, gentity_t **outTempEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BulletRicochet
==============
*/
void BulletRicochet(unsigned int *randSeed, gentity_t *hitEnt, gentity_t *attacker, const Weapon weapon, const vec3_t *contactPoint, const vec3_t *surfaceNormal, const vec3_t *incomingNormal, int gameTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bullet_ProcessShieldHit
==============
*/
bool Bullet_ProcessShieldHit(unsigned int *randSeed, BulletFireParams *bp, BulletTraceResults *br, const Weapon weapon, gentity_t *attacker, int gameTime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bullet_Process
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Bullet_HitNothing
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
G_WeaponBounceShot
==============
*/
bool G_WeaponBounceShot(Weapon weapon, BulletFireParams *incomingbp, BulletTraceResults *br, gentity_t *attacker, unsigned int *randSeed, int gameTime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bullet_FirePenetrate
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Bullet_FireExtended
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Bullet_Fire
==============
*/
void Bullet_Fire(gentity_t *attacker, float spread, const weaponParms *wp, const gentity_t *weaponEnt, int gameTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

