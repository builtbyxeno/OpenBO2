#include "types.h"

/*
==============
Actor_InitThreatBiasGroups
==============
*/
void Actor_InitThreatBiasGroups()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_GetThreatBias
==============
*/
int Actor_GetThreatBias(int groupSelf, int groupEnemy)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_FlagEnemyUnattackable
==============
*/
void Actor_FlagEnemyUnattackable(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_CaresAboutInfo
==============
*/
BOOL Actor_CaresAboutInfo(actor_t *self, sentient_t *pOther)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_ThreatFromScariness
==============
*/
int Actor_ThreatFromScariness(float a1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_ThreatFromCover
==============
*/
int Actor_ThreatFromCover(actor_t *self, sentient_t *enemy, float distance)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_ThreatFromDistance
==============
*/
int Actor_ThreatFromDistance(const float fDistance)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sentient_GetScarinessForDistance
==============
*/
double Sentient_GetScarinessForDistance(sentient_t *self, sentient_t *enemy, float fDist)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_CanBePathedTo
==============
*/
bool Actor_CanBePathedTo(actor_t *self, sentient_t *enemy, int isCurrentEnemy)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_ShouldIgnoreFromAttackerCount
==============
*/
bool Actor_ShouldIgnoreFromAttackerCount(actor_t *self, sentient_t *enemy, int isCurrentEnemy)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_IsFullyAware
==============
*/
int Actor_IsFullyAware(actor_t *self, sentient_t *enemy, int isCurrentEnemy)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_ThreatFromVisibilityAndAwareness
==============
*/
int Actor_ThreatFromVisibilityAndAwareness(int friendlyTimingOut, int isFullyAwarea, int friendlyTimingOuta)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_ThreatFromAttackerCount
==============
*/
int Actor_ThreatFromAttackerCount(actor_t *self, sentient_t *enemy, int isCurrentEnemy)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_ThreatBonusForCurrentEnemy
==============
*/
int Actor_ThreatBonusForCurrentEnemy(int isCurrentEnemy, int isFullyAware, int friendlyTimingOut, int isPlayer, int isDamaged)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_ThreatCoveringFire
==============
*/
int Actor_ThreatCoveringFire(actor_t *self, sentient_t *enemy)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_ThreatFlashed
==============
*/
int Actor_ThreatFlashed(sentient_t *enemy)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_UpdateSingleThreat
==============
*/
int Actor_UpdateSingleThreat(char *a1, float enemyDist, sentient_t *enemya, float enemyDista)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_InitThreatUpdateInterval
==============
*/
void Actor_InitThreatUpdateInterval(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_IncrementThreatTime
==============
*/
void Actor_IncrementThreatTime(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_InitPotentialTarget
==============
*/
void Actor_InitPotentialTarget(PotentialTargetData *potentialTarget, gentity_t *entity, float dist, const vec3_t *dirToEnemy)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_InitSecondaryTarget
==============
*/
void Actor_InitSecondaryTarget(actor_t *self, ActorSecondaryTarget *secondary, const PotentialTargetData *potentialTarget)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_IsSimilarTarget
==============
*/
bool Actor_IsSimilarTarget(const vec2_t *dirToFirst, const vec2_t *dirToSecond, float distToFirst, float distToSecond)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_GetClosestDirectionSecondary
==============
*/
int Actor_GetClosestDirectionSecondary(const actor_t *self, const PotentialTargetData *potential)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_UpdateSecondaryTargets
==============
*/
void Actor_UpdateSecondaryTargets(actor_t *self, PotentialTargetData *potentialTargets, int numPotentialTargets)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_FullyAwareOfEnemy
==============
*/
BOOL Actor_FullyAwareOfEnemy(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_SetPotentialThreat
==============
*/
void Actor_SetPotentialThreat(potential_threat_t *self, float yaw, float a3)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_ClearPotentialThreat
==============
*/
void Actor_ClearPotentialThreat(potential_threat_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_PotentialThreat_Debug
==============
*/
void Actor_PotentialThreat_Debug(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_EnterAlertState
==============
*/
void Actor_EnterAlertState(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_EnterCombatState
==============
*/
void Actor_EnterCombatState(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_CheckIgnore
==============
*/
BOOL Actor_CheckIgnore(sentient_t *self, sentient_t *enemy)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_UpdateThreat
==============
*/
void Actor_UpdateThreat(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

