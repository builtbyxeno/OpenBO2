#include "types.h"
#include "functions.h"

/*
==============
CG_GetEntityBModelContents
==============
*/
int CG_GetEntityBModelContents(const centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetEntityDobjBounds
==============
*/
void CG_GetEntityDobjBounds(const centity_t *cent, const DObj *dobj, vec3_t *mins, vec3_t *maxs, vec3_t *absMins, vec3_t *absMaxs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetEntityDObjContents
==============
*/
int CG_GetEntityDObjContents(const centity_t *cent, const DObj *dobj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_EntityHasCollision
==============
*/
bool CG_EntityHasCollision(const centity_t *cent, DObj *dobj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_EntityNeedsLinked
==============
*/
bool CG_EntityNeedsLinked(LocalClientNum_t localClientNum, int entIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_UnlinkEntity
==============
*/
void CG_UnlinkEntity(LocalClientNum_t localClientNum, int entIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalcWorldBounds
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_EntityInArea
==============
*/
bool CG_EntityInArea(int entIndex, const vec3_t *mins, const vec3_t *maxs, int contentMask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_AreaEntities_r
==============
*/
void CG_AreaEntities_r(unsigned __int16 sectorIndex, CEntityAreaParms *areaParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AreaEntities
==============
*/
int CG_AreaEntities(const vec3_t *mins, const vec3_t *maxs, int *entityList, const int maxEntities, const int contentMask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
cmpr
==============
*/
int cmpr(const void *e0, const void *e1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetEntityBoneInfo
==============
*/
int CG_GetEntityBoneInfo(int entID, int boneIndex, vec3_t *bonePos, vec3_t *boneAxis, const char **boneName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetEntityBModelBounds
==============
*/
void CG_GetEntityBModelBounds(int a1, const centity_t *cent, vec3_t *mins, vec3_t *maxs, vec3_t *absMins, vec3_t *absMaxs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_LinkEntity
==============
*/
void CG_LinkEntity(LocalClientNum_t localClientNum, int entIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ClipMoveToEntity
==============
*/
void CG_ClipMoveToEntity(const moveclip_t *clip, int entIndex, trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ClipMoveToEntities_r
==============
*/
void CG_ClipMoveToEntities_r(const moveclip_t *clip, unsigned __int16 sectorIndex, const vec4_t *p1, const vec4_t *p2, trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ClipMoveToEntities
==============
*/
void CG_ClipMoveToEntities(const moveclip_t *clip, trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PointTraceToEntity
==============
*/
void CG_PointTraceToEntity(const pointtrace_t *clip, int entIndex, trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PointTraceToEntities_r
==============
*/
void CG_PointTraceToEntities_r(const pointtrace_t *clip, unsigned __int16 sectorIndex, const vec4_t *p1, const vec4_t *p2, trace_t *results, col_context_t *context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PointTraceToEntities
==============
*/
void CG_PointTraceToEntities(const pointtrace_t *clip, trace_t *results, col_context_t *context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_TracePoint
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_LocationalTrace
==============
*/
void CG_LocationalTrace(trace_t *results, const vec3_t *start, const vec3_t *end, int passEntityNum, int contentMask, bool checkRopes, col_context_t *context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SightTracePointInternal
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_SightTracePoint
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_TraceCapsule
==============
*/
void CG_TraceCapsule(int a1, trace_t *results, const vec3_t *start, const vec3_t *mins, const vec3_t *maxs, const vec3_t *end, int passEntityNum, int contentMask, col_context_t *context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

