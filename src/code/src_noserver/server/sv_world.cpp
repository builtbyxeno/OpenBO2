#include "types.h"

/*
==============
SV_ClipHandleForEntity
==============
*/
unsigned int SV_ClipHandleForEntity(const gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_UnlinkEntity
==============
*/
void SV_UnlinkEntity(gentity_t *gEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_TraceCapsuleToEntity
==============
*/
void SV_TraceCapsuleToEntity(const moveclip_t *clip, svEntity_s *check, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_TracePointToEntity
==============
*/
void SV_TracePointToEntity(const pointtrace_t *clip, svEntity_s *check, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SightTraceCapsuleToEntity
==============
*/
int SV_SightTraceCapsuleToEntity(const sightclip_t *clip, int entnum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_SetupIgnoreEntParams
==============
*/
void SV_SetupIgnoreEntParams(IgnoreEntParams *ignoreEntParams, int baseEntity)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SightTraceCapsule
==============
*/
BOOL SV_SightTraceCapsule(int *hitNum, const vec3_t *start, const vec3_t *mins, const vec3_t *maxs, const vec3_t *end, col_context_t *context)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_SightTracePoint
==============
*/
BOOL SV_SightTracePoint(int *hitNum, const vec3_t *start, const vec3_t *end, col_context_t *context)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_PointContents
==============
*/
int SV_PointContents(const vec3_t *p, int passEntityNum, int contentmask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_LinkEntity
==============
*/
void SV_LinkEntity(int a1, gentity_t *gEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_SightTracePointToEntity
==============
*/
int SV_SightTracePointToEntity(unsigned int a1, const sightpointtrace_t *clip, int entnum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_TracePoint
==============
*/
void SV_TracePoint(int a1, trace_t *results, const vec3_t *start, const vec3_t *end, col_context_t *context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_TraceCapsule
==============
*/
void SV_TraceCapsule(int a1, trace_t *results, const vec3_t *start, const vec3_t *mins, const vec3_t *maxs, const vec3_t *end, col_context_t *context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_TraceCapsule
==============
*/
void G_TraceCapsule(trace_t *results, const vec3_t *start, const vec3_t *mins, const vec3_t *maxs, const vec3_t *end, int passEntityNum, int contentmask, col_context_t *context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_LocationalTrace
==============
*/
void G_LocationalTrace(trace_t *results, const vec3_t *start, const vec3_t *end, int passEntityNum, int contentmask, unsigned __int8 *priorityMap, int (*collide_entity_func)(int))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_LocationalTraceAllowChildren
==============
*/
void G_LocationalTraceAllowChildren(trace_t *results, const vec3_t *start, const vec3_t *end, int passEntityNum, int contentmask, unsigned __int8 *priorityMap)
{
	UNIMPLEMENTED(__FUNCTION__);
}

