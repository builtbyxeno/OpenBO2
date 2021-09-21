#include "types.h"
#include "functions.h"

/*
==============
TRACK_actor_badplace
==============
*/
void TRACK_actor_badplace()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_UpdateBadPlaceCount
==============
*/
void Path_UpdateBadPlaceCount(badplace_t *place, int delta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_AllocBadPlace
==============
*/
badplace_t *Path_AllocBadPlace(unsigned int name, int duration, badplace_parms_t *params)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Path_CheckLineSegmentIntersectsAnyBadPlaceCylinder
==============
*/
char Path_CheckLineSegmentIntersectsAnyBadPlaceCylinder(const vec3_t *start, const vec3_t *end, int teamflags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Path_MakeBadPlaceEx
==============
*/
void Path_MakeBadPlaceEx(unsigned int name, int duration, int teamflags, int type, badplace_parms_t *parms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_DrawBadPlaces
==============
*/
void Path_DrawBadPlaces()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_InitBadPlaces
==============
*/
void Path_InitBadPlaces()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Path_ShutdownBadPlaces
==============
*/
void Path_ShutdownBadPlaces()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_IsInAnyBadPlace
==============
*/
char Actor_IsInAnyBadPlace(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_BadPlace_UpdateFleeingActors
==============
*/
actor_t *Actor_BadPlace_UpdateFleeingActors(unsigned int a1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Actor_BadPlace_GetMaximumFleeRadius
==============
*/
void Actor_BadPlace_GetMaximumFleeRadius()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_BadPlace_HasPotentialNodeDuplicates
==============
*/
bool Actor_BadPlace_HasPotentialNodeDuplicates(pathsort_t *potentialNodes, int potentialNodeCount, pathnode_t *checkNode)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_BadPlace_IsPointInAnyBadPlace
==============
*/
int Actor_BadPlace_IsPointInAnyBadPlace(const vec3_t *a1, vec3_t *point)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_BadPlace_IsNodeInAnyBadPlace
==============
*/
char Actor_BadPlace_IsNodeInAnyBadPlace(pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_BadPlace_FindSafeNodeAlongPath
==============
*/
pathnode_t *Actor_BadPlace_FindSafeNodeAlongPath(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Path_UpdateBadPlaces
==============
*/
void __cdecl Path_UpdateBadPlaces()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_BadPlace_FindSafeNodeOutsideBadPlace
==============
*/
int Actor_BadPlace_FindSafeNodeOutsideBadPlace(actor_t *self, pathsort_t *potentialNodes, float maxFleeDist)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_BadPlace_AttemptEscape
==============
*/
bool Actor_BadPlace_AttemptEscape(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_BadPlace_Flee_Start
==============
*/
bool Actor_BadPlace_Flee_Start(actor_t *self, ai_state_t ePrevState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_BadPlace_Flee_Think
==============
*/
int Actor_BadPlace_Flee_Think(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

