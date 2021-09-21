#include "types.h"
#include "functions.h"

/*
==============
Avoid_Init
==============
*/
void Avoid_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Avoid_Init
==============
*/
void Avoid_Init(int index, vec3_t origin, float radius, float timeHorizon, float maxSpeed, bool stubborn)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Avoid_Allocate
==============
*/
unsigned __int8 Avoid_Allocate(int entnum, vec3_t origin, float radius, float timeHorizon, float maxSpeed)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Avoid_Free
==============
*/
void Avoid_Free(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Avoid_GetNeighbors
==============
*/
int Avoid_GetNeighbors(Avoid *avoid, Avoid **neighbors, int team)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Avoid_UpdateNoGoal
==============
*/
void Avoid_UpdateNoGoal(int index, vec3_t origin, vec3_t vel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Avoid_Disable
==============
*/
void Avoid_Disable(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Avoid_SetRadius
==============
*/
void Avoid_SetRadius(int index, const float radius)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Avoid_SetPriority
==============
*/
void Avoid_SetPriority(int index, const int priority)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Avoidance_DebugRender
==============
*/
void Avoidance_DebugRender()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CalcStaticORCAs
==============
*/
void CalcStaticORCAs(int a1, Avoid *curr, float invT, OrcaPlane *orcas, int *orcaCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AvoidUpdateOne
==============
*/
void AvoidUpdateOne(float curr, Avoid *a2, Avoid **inRange, int inRangeCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Avoid_UpdateGoal
==============
*/
void Avoid_UpdateGoal(int index, const float dt, const vec3_t *position, const vec3_t *vel, vec3_t *goalPos, float *speed, int team)
{
	UNIMPLEMENTED(__FUNCTION__);
}

