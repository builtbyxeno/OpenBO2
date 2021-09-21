#include "types.h"
#include "functions.h"

/*
==============
Actor_SightTrace
==============
*/
bool Actor_SightTrace(actor_t *self, const vec3_t *start, const vec3_t *end, int passEntNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_CanSeePointFrom
==============
*/
bool Actor_CanSeePointFrom(actor_t *self, const vec3_t *vStart, const vec3_t *vEnd, float fMaxDistSqrd, int ignoreEntityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_UpdateVisCache
==============
*/
void Actor_UpdateVisCache(actor_t *self, const gentity_t *ent, sentient_info_t *pInfo, bool bVisible)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_ShouldDoFOVCheck
==============
*/
bool Actor_ShouldDoFOVCheck(actor_t *self, sentient_t *sentient)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_KnowAboutEnemy
==============
*/
bool Actor_KnowAboutEnemy(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
compare_sentient_sort
==============
*/
int compare_sentient_sort(const void *pe1, const void *pe2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_UpdateLastKnownPos
==============
*/
void Actor_UpdateLastKnownPos(actor_t *self, sentient_t *other, const vec3_t *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_UpdateLastEnemySightPos
==============
*/
void Actor_UpdateLastEnemySightPos(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_GetLastKnownEnemyPosWithDuration
==============
*/
void Actor_GetLastKnownEnemyPosWithDuration(actor_t *self, const gentity_t *enemy, int cheatDuration, vec3_t *lastKnownPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_GetLastKnownEnemyPos
==============
*/
void Actor_GetLastKnownEnemyPos(actor_t *self, const gentity_t *enemy, vec3_t *lastKnownPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_UpdateEyeInformation
==============
*/
void Actor_UpdateEyeInformation(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_GetEyePosition
==============
*/
void Actor_GetEyePosition(actor_t *self, vec3_t *vEyePosOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_GetDebugEyePosition
==============
*/
void Actor_GetDebugEyePosition(actor_t *self, vec3_t *vEyePosOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_GetEyeDirection
==============
*/
void Actor_GetEyeDirection(actor_t *self, vec3_t *vEyeDir)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_GetEyeOffset
==============
*/
void Actor_GetEyeOffset(actor_t *self, vec3_t *vEyePosOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_PointInFov
==============
*/
BOOL Actor_PointInFov(actor_t *self, const vec3_t *vPoint)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_GetMuzzleInfo
==============
*/
int Actor_GetMuzzleInfo(actor_t *self, vec3_t *vOrigin, vec3_t *vForward)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_CanSeePointExInternal
==============
*/
bool Actor_CanSeePointExInternal(actor_t *self, const vec3_t *vPoint, float fovDot, float fMaxDistSqrd, int ignoreEntityNum, vec3_t *vViewPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_CanSeePointEx
==============
*/
bool Actor_CanSeePointEx(actor_t *self, const vec3_t *vPoint, float fovDot, float fMaxDistSqrd, int ignoreEntityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_CanSeeEntityEx
==============
*/
char Actor_CanSeeEntityEx(actor_t *self, const gentity_t *ent, float fovDot, float fMaxDistSqrd)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_CanShootFrom
==============
*/
BOOL Actor_CanShootFrom(actor_t* self, const vec3_t* vTarget, const vec3_t* vFrom)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_CanShootEnemy
==============
*/
bool Actor_CanShootEnemy(actor_t *self, const int cacheDuration)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_CanSeeEntity
==============
*/
char Actor_CanSeeEntity(actor_t *self, const gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_RecentlySeeSentient
==============
*/
char Actor_RecentlySeeSentient(actor_t *self, sentient_t *sentient, int latency)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_CanSeeSentient
==============
*/
char Actor_CanSeeSentient(actor_t *self, sentient_t *sentient, int iMaxLatency)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_CanSeeEnemy
==============
*/
char Actor_CanSeeEnemy(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_CanSeeEnemyExtended
==============
*/
char Actor_CanSeeEnemyExtended(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_CheckSurprisedBySentient
==============
*/
void Actor_CheckSurprisedBySentient(actor_t *self, sentient_t *other)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_GetPerfectInfo
==============
*/
void Actor_GetPerfectInfo(actor_t *self, sentient_t *other)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_RecentlySeeEnemy
==============
*/
char Actor_RecentlySeeEnemy(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_UpdateNearbyEnemyInfo
==============
*/
void Actor_UpdateNearbyEnemyInfo(actor_t *self, sentient_sort_t *enemyList, int enemyCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_UpdateSight
==============
*/
void Actor_UpdateSight(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

