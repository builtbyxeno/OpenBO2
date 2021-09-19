#include "types.h"
#include "functions.h"

/*
==============
Sentient_Alloc
==============
*/
sentient_t *Sentient_Alloc(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Sentient_DissociateSentient
==============
*/
void Sentient_DissociateSentient(sentient_t *self, sentient_t *other)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sentient_GetOrigin
==============
*/
void Sentient_GetOrigin(const sentient_t *self, vec3_t *vOriginOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sentient_GetVelocity
==============
*/
void Sentient_GetVelocity(const sentient_t *self, vec3_t *vVelOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sentient_GetCentroid
==============
*/
void Sentient_GetCentroid(const sentient_t *self, vec3_t *vCentroidOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sentient_GetEyePosition
==============
*/
void Sentient_GetEyePosition(const sentient_t *self, vec3_t *vEyePosOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sentient_GetThirdPersonEyePosition
==============
*/
void Sentient_GetThirdPersonEyePosition(const sentient_t *self, vec3_t *vEyePosOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sentient_GetDebugEyePosition
==============
*/
void Sentient_GetDebugEyePosition(const sentient_t *self, vec3_t *vEyePosOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sentient_NearestNode
==============
*/
pathnode_t *Sentient_NearestNode(sentient_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Sentient_NearestNodeSuppressed
==============
*/
pathnode_t *Sentient_NearestNodeSuppressed(sentient_t *self, PathBlockPlanes *blockPlanes)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Sentient_InvalidateNearestNode
==============
*/
void Sentient_InvalidateNearestNode(sentient_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sentient_SetEnemy
==============
*/
void Sentient_SetEnemy(sentient_t *self, gentity_t *enemy, int bNotify, int resetThreatUpdate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sentient_FirstSentient
==============
*/
sentient_t *Sentient_FirstSentient(const int iTeamFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Sentient_NextSentient
==============
*/
sentient_t *Sentient_NextSentient(sentient_t *pPrevSentient, const int iTeamFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Sentient_NameForTeam
==============
*/
const char *Sentient_NameForTeam(team_t eTeam)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Sentient_SetTeam
==============
*/
void Sentient_SetTeam(sentient_t *self, team_t eTeam)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sentient_ClaimNode
==============
*/
void Sentient_ClaimNode(sentient_t *self, pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sentient_NodeClaimRevoked
==============
*/
void Sentient_NodeClaimRevoked(sentient_t *self, pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sentient_StealClaimNode
==============
*/
void Sentient_StealClaimNode(sentient_t *self, sentient_t *other)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sentient_BanNearNodes
==============
*/
void Sentient_BanNearNodes(sentient_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_InitSentients
==============
*/
void G_InitSentients()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sentient_NearestNodeDirty
==============
*/
bool Sentient_NearestNodeDirty(sentient_t *self, bool originChanged)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sentient_IsEnemyIndoor
==============
*/
int Sentient_IsEnemyIndoor(sentient_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Sentient_Dissociate
==============
*/
void Sentient_Dissociate(sentient_t *pSentient)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sentient_Free
==============
*/
void Sentient_Free(sentient_t *sentient)
{
	UNIMPLEMENTED(__FUNCTION__);
}

