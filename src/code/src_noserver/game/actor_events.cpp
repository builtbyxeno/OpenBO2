#include "types.h"
#include "functions.h"

/*
==============
Actor_EventDefaultRadiusSqrd
==============
*/
double Actor_EventDefaultRadiusSqrd(ai_event_t eType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_DumpEvents
==============
*/
void Actor_DumpEvents(actor_t *self, ai_event_t event, gentity_t *originator)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_WasAttackedBy
==============
*/
void Actor_WasAttackedBy(actor_t *self, sentient_t *pOther)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_IsOnSameTeam
==============
*/
bool Actor_IsOnSameTeam(gentity_t *originator, actor_t *pActor, int teamFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_EventFootstep
==============
*/
void Actor_EventFootstep(actor_t *self, sentient_t *originator, const vec3_t *vOrigin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_EventNewEnemy
==============
*/
void Actor_EventNewEnemy(actor_t *self, sentient_t *originator)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_EventPain
==============
*/
void Actor_EventPain(actor_t *self, sentient_t *pCasualty, sentient_t *pAttacker)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_EventDeath
==============
*/
void Actor_EventDeath(actor_t *self, sentient_t *pCasualty, sentient_t *pAttacker)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_EventExplosion
==============
*/
void Actor_EventExplosion(actor_t *self, gentity_t *originator, const vec3_t *vOrigin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_EventGrenadePing
==============
*/
void Actor_EventGrenadePing(actor_t *self, gentity_t *originator)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_EventGunshot
==============
*/
void Actor_EventGunshot(actor_t *self, sentient_t *originator, const vec3_t *vOrigin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_EventBullet
==============
*/
void Actor_EventBullet(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_ShouldKnowAboutPainDeathEvent
==============
*/
bool Actor_ShouldKnowAboutPainDeathEvent(actor_t *self, gentity_t *originator, const vec3_t *vOrigin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_ReceivePointEvent
==============
*/
void Actor_ReceivePointEvent(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_ReceiveLineEvent
==============
*/
void Actor_ReceiveLineEvent(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_BroadcastPointEvent
==============
*/
void Actor_BroadcastPointEvent(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_BroadcastLineEvent
==============
*/
void Actor_BroadcastLineEvent(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_BroadcastTeamEvent
==============
*/
void Actor_BroadcastTeamEvent(sentient_t *sentient, ai_event_t eType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

