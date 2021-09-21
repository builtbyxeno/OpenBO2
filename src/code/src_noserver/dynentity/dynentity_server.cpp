#include "types.h"
#include "functions.h"

/*
==============
DynEntSv_RegisterDvars
==============
*/
void DynEntSv_RegisterDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntSv_LinkModel
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
DynEntSv_LinkBrush
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
DynEntClSv_ShouldCullEntitiesForSplitscreen
==============
*/
void DynEntClSv_ShouldCullEntitiesForSplitscreen()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntSv_InitEntities
==============
*/
void DynEntSv_InitEntities()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntSv_PointTrace_r
==============
*/
void DynEntSv_PointTrace_r(DynEntityDrawType drawType, const pointtrace_t *clip, unsigned int sectorIndex, const vec4_t *p1, const vec4_t *p2, trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntSv_PointTrace
==============
*/
void DynEntSv_PointTrace(const pointtrace_t *clip, trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntSv_PointTrace
==============
*/
void DynEntSv_PointTrace(unsigned __int16 id, DynEntityDrawType drawType, const pointtrace_t *clip, trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntSv_ClipMoveTrace_r
==============
*/
void DynEntSv_ClipMoveTrace_r(const moveclip_t *clip, unsigned int sectorIndex, const vec4_t *p1, const vec4_t *p2, trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntSv_ClipMoveTrace
==============
*/
void DynEntSv_ClipMoveTrace(const moveclip_t *clip, trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntSv_AreaEntities_r
==============
*/
void DynEntSv_AreaEntities_r(DynEntityDrawType drawType, unsigned int sectorIndex, DynEntityAreaParms *areaParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntSv_AreaEntities
==============
*/
unsigned __int16 DynEntSv_AreaEntities(DynEntityDrawType drawType, const vec3_t *mins, const vec3_t *maxs, int contentMask, unsigned __int16 dynEntMaxCount, unsigned __int16 *dynEntList)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEntSv_Damage
==============
*/
void DynEntSv_Damage(unsigned __int16 dynEntId, DynEntityDrawType drawType, const vec3_t *hitPos, const vec3_t *hitDir, int damage, bool explosive)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntSv_GetClosestEntities
==============
*/
unsigned int DynEntSv_GetClosestEntities(DynEntityDrawType drawType, const vec3_t *radiusMins, const vec3_t *radiusMaxs, const vec3_t *origin, unsigned __int16 *hitEnts)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEntSv_RadiusDamage
==============
*/
void DynEntSv_RadiusDamage(unsigned __int16 *a1, const vec3_t *origin, float radius, float coneAngleCos, vec3_t *coneDirection, float innerDamage, float outerDamage)
{
	UNIMPLEMENTED(__FUNCTION__);
}

