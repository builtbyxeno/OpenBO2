#include "types.h"

/*
==============
TRACK_DynEntityCollWorld
==============
*/
void TRACK_DynEntityCollWorld()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_GetCollSector
==============
*/
DynEntityCollSector *DynEnt_GetCollSector(DynEntityCollType collType, unsigned int sectorIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DynEnt_ClearCollWorld
==============
*/
void DynEnt_ClearCollWorld(DynEntityCollType collType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_AllocCollSector
==============
*/
unsigned __int16 DynEnt_AllocCollSector(DynEntityCollType collType, const vec2_t *mins, const vec2_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEnt_AddToCollSector
==============
*/
void DynEnt_AddToCollSector(DynEntityCollType collType, unsigned __int16 dynEntId, unsigned __int16 sectorIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_UnlinkEntity
==============
*/
void DynEnt_UnlinkEntity(DynEntityCollType collType, unsigned __int16 dynEntId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_GetContents
==============
*/
int DynEnt_GetContents(const DynEntityDef *dynEntDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEnt_GetLocalBounds
==============
*/
void DynEnt_GetLocalBounds(const DynEntityDef *dynEntDef, vec3_t *mins, vec3_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_GetRadiusDistSqr
==============
*/
double DynEnt_GetRadiusDistSqr(const DynEntityColl *dynEntColl, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEnt_IsInCone
==============
*/
bool DynEnt_IsInCone(const DynEntityDef *dynEntDef, const GfxPlacement *pose, const vec3_t *origin, float coneAngleCos, const vec3_t *coneDir)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEnt_GetCylindricalRadiusDistSqr
==============
*/
double DynEnt_GetCylindricalRadiusDistSqr(const DynEntityColl *dynEntColl, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEnt_EntityInArea
==============
*/
bool DynEnt_EntityInArea(const DynEntityDef *dynEntDef, const DynEntityColl *dynEntColl, const vec3_t *mins, const vec3_t *maxs, int contentMask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEnt_PointTraceToModel
==============
*/
void DynEnt_PointTraceToModel(const DynEntityDef *dynEntDef, const XModel *xmodel, const GfxPlacement *pose, const pointtrace_t *clip, trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_PointTraceToBrush
==============
*/
void DynEnt_PointTraceToBrush(const DynEntityDef *dynEntDef, const GfxPlacement *pose, const pointtrace_t *clip, trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_SortCollSector
==============
*/
void DynEnt_SortCollSector(DynEntityCollType collType, unsigned __int16 sectorIndex, const vec2_t *mins, const vec2_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_LinkEntity
==============
*/
void DynEnt_LinkEntity(DynEntityCollType collType, unsigned __int16 dynEntId, const vec3_t *absMins, const vec3_t *absMaxs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

