#include "types.h"
#include "functions.h"

/*
==============
Vehicle_CheckIgnore
==============
*/
BOOL Vehicle_CheckIgnore(sentient_t *self, sentient_t *enemy)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DebugResetThreatStrings
==============
*/
void DebugResetThreatStrings(const vehicle_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DebugThreatStringAll
==============
*/
void DebugThreatStringAll(const vehicle_t *self, sentient_t *enemy, int threat)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DebugThreatStringSimple
==============
*/
void DebugThreatStringSimple(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DebugThreatNodes
==============
*/
void DebugThreatNodes(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Vehicle_ThreatFromScariness
==============
*/
/*int Vehicle_ThreatFromScariness@<eax>(float a1@<xmm0>)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
Vehicle_ThreatFromDistance
==============
*/
int Vehicle_ThreatFromDistance(const float fDistance)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vehicle_IsFullyAware
==============
*/
int Vehicle_IsFullyAware(vehicle_t *self, sentient_t *enemy, int isCurrentEnemy)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vehicle_ThreatFromVisibilityAndAwareness
==============
*/
int Vehicle_ThreatFromVisibilityAndAwareness(int isVisible, int isFullyAware, int friendlyTimingOut)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vehicle_ThreatBonusForCurrentEnemy
==============
*/
int Vehicle_ThreatBonusForCurrentEnemy(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vehicle_IncrementThreatTime
==============
*/
void Vehicle_IncrementThreatTime(vehicle_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Vehicle_InitPotentialTarget
==============
*/
void Vehicle_InitPotentialTarget(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SentientInfo
==============
*/
sentient_info_t *SentientInfo(vehicle_t *self, const sentient_t *enemy)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Vehicle_GetScriptTargetEntity
==============
*/
gentity_t *Vehicle_GetScriptTargetEntity(vehicle_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Vehicle_GetTargetEntity
==============
*/
gentity_t *Vehicle_GetTargetEntity(vehicle_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Vehicle_GetTargetSentient
==============
*/
sentient_t *Vehicle_GetTargetSentient(vehicle_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Vehicle_PotentialThreat_Debug
==============
*/
void Vehicle_PotentialThreat_Debug(vehicle_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Vehicle_GetPerfectInfo
==============
*/
void Vehicle_GetPerfectInfo(vehicle_t *self, sentient_t *other)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Vehicle_UpdateNearbyEnemyInfo
==============
*/
void Vehicle_UpdateNearbyEnemyInfo(vehicle_t *self, sentient_sort_t *enemyList, int enemyCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetVehicleLookAtPosition
==============
*/
void GetVehicleLookAtPosition(const gentity_t *ent, const vec3_t *viewPos, vec3_t *lookAtPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PointInFovAndRange
==============
*/
int PointInFovAndRange(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vehicle_SightTrace
==============
*/
bool Vehicle_SightTrace(vehicle_t *self, const vec3_t *start, const vec3_t *end, int passEntNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vehicle_CanSeePointExInternal
==============
*/
bool Vehicle_CanSeePointExInternal(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vehicle_CanSeePointEx
==============
*/
bool Vehicle_CanSeePointEx(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vehicle_UpdateVisCache
==============
*/
void Vehicle_UpdateVisCache(vehicle_t *self, const gentity_t *ent, sentient_info_t *pInfo, bool bVisible)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Vehicle_CanSeeEntityEx
==============
*/
char Vehicle_CanSeeEntityEx(vehicle_t *self, const gentity_t *ent, float fovDot, float fMaxDistSqrd)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vehicle_CanSeeEntity
==============
*/
char Vehicle_CanSeeEntity(vehicle_t *self, const gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vehicle_CanSeeSentient
==============
*/
char Vehicle_CanSeeSentient(vehicle_t *self, sentient_t *sentient, int iMaxLatency)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vehicle_RecentlySeeSentient
==============
*/
char Vehicle_RecentlySeeSentient(vehicle_t *self, sentient_t *sentient, int latency)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vehicle_UpdateSight
==============
*/
void Vehicle_UpdateSight(vehicle_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Vehicle_DissociateSentient
==============
*/
void Vehicle_DissociateSentient(vehicle_t *self, sentient_t *other)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DebugLastKnownEnemyPositions
==============
*/
void DebugLastKnownEnemyPositions(vehicle_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Vehicle_UpdateSingleThreat
==============
*/
int Vehicle_UpdateSingleThreat(vehicle_t *self, sentient_t *enemy, float enemyDist)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vehicle_UpdateThreat
==============
*/
void Vehicle_UpdateThreat(vehicle_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SentientInfo
==============
*/
sentient_info_t *SentientInfo(actor_t *self, const sentient_t *enemy)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

