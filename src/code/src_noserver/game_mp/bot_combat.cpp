#include "types.h"

/*
==============
Bot_KickAngles
==============
*/
void Bot_KickAngles(bot_t *bot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_IsFacingEnemy
==============
*/
bool Bot_IsFacingEnemy(const bot_t *bot, const gentity_t *enemy, float *dot, float *distSq, float fov)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_ClientValidThreat
==============
*/
bool Bot_ClientValidThreat(const bot_t *bot, const client_t *cl, int team)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_CompareThreats
==============
*/
int Bot_CompareThreats(const bot_threat_t *t1, const bot_threat_t *t2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_UpdateWeapon
==============
*/
void Bot_UpdateWeapon(const bot_t *bot, usercmd_s *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_FireRecoil
==============
*/
void Bot_FireRecoil(int clientNum, vec3_t *kickAVel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_ProjectileArcTrace
==============
*/
bool Bot_ProjectileArcTrace(const vec3_t *vOrigin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_ProjectilePredict
==============
*/
bool Bot_ProjectilePredict(const vec3_t *vDir, const vec3_t *vOrigin, const vec3_t *vTarget, const float time, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_ProjectileTrajectory
==============
*/
bool Bot_ProjectileTrajectory(const vec3_t *vOrigin, vec3_t *vDir, const vec3_t *vTarget, const vec3_t *vGravity, float speed, float time0, float time1, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_ProjectileTry
==============
*/
bool Bot_ProjectileTry(bot_t *bot, const vec3_t *target, Weapon weapon, vec3_t *outDir)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_TryThrowGrenade
==============
*/
bool Bot_TryThrowGrenade(const client_t *cl, vec3_t *target, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_SightCheck
==============
*/
bool Bot_SightCheck(int a1, const vec3_t *start, const vec3_t *end, int botNum, int enemyNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_TossGrenade
==============
*/
bool Bot_TossGrenade(bot_t *bot, usercmd_s *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_GetThreats
==============
*/
int Bot_GetThreats(int a1, const bot_t *bot, float fov, bot_threat_t *threatList, int maxCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

