#include "types.h"
#include "functions.h"

/*
==============
Tracer_Spawn_ApplyOverrides
==============
*/
void Tracer_Spawn_ApplyOverrides(LocalClientNum_t localClientNum, const centity_t *instigator, const Weapon weapon, TracerInfo *tracer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Tracer_Spawn
==============
*/
void Tracer_Spawn(LocalClientNum_t localClientNum, const vec3_t *pstart, const vec3_t *pend, const centity_t *instigator, const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Tracer_Draw
==============
*/
void Tracer_Draw(const vec3_t *start, const vec3_t *finish, TracerInfo *tracer, TracerDrawFlags drawFlags, const float alphaScale, const bool smokeTrail)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Tracer_UpdateDrawRate
==============
*/
int Tracer_UpdateDrawRate(const LocalClientNum_t localClientNum, const Weapon weapon, centity_t *attackerEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Tracer_FindTracer
==============
*/
TracerDef *Tracer_FindTracer(const char *tracerName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

