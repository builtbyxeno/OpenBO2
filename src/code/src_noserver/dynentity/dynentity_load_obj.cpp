#include "types.h"
#include "functions.h"

/*
==============
DynEnt_GetType
==============
*/
DynEntityType DynEnt_GetType(const char *typeName)
{
	UNIMPLEMENTED(__FUNCTION__);
	DynEntityType tmp;
	return tmp;
}

/*
==============
DynEnt_GetEntityCountFromString
==============
*/
void DynEnt_GetEntityCountFromString(const char *entityString, int *entCount, int *constraintCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LoadRopeParams
==============
*/
const char *LoadRopeParams()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DynEnt_CreateConstraint
==============
*/
bool DynEnt_CreateConstraint(PhysConstraint *constraint, DynEntityConstraintCreateParams *params)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEnt_GetEntityConstraintParams
==============
*/
void DynEnt_GetEntityConstraintParams(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_AllocXModel
==============
*/
void *DynEnt_AllocXModel(int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DynEnt_AllocXModelColl
==============
*/
void *DynEnt_AllocXModelColl(int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DynEnt_XModelPrecache
==============
*/
XModel *DynEnt_XModelPrecache(const char *modelName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DynEnt_AllocPhysPreset
==============
*/
void *DynEnt_AllocPhysPreset(int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DynEnt_AllocXModelPieces
==============
*/
void *DynEnt_AllocXModelPieces(int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DynEnt_PhysPresetPrecache
==============
*/
PhysPreset *DynEnt_PhysPresetPrecache(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DynEnt_XModelPiecesPrecache
==============
*/
XModelPieces *DynEnt_XModelPiecesPrecache(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
FindConstraints
==============
*/
bool FindConstraints(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEnt_AutoCreatePhysPreset
==============
*/
PhysPreset *DynEnt_AutoCreatePhysPreset(const DynEntityDef *dynEntDef, const DynEntityCreateParams *params)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DynEnt_CompareEntities
==============
*/
int DynEnt_CompareEntities(const void *arg0, const void *arg1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetAttachPointsInWorldSpace
==============
*/
void GetAttachPointsInWorldSpace(PhysConstraint *constraint, vec3_t *p0, vec3_t *p1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_GetEntityProps
==============
*/
const DynEntityProps *DynEnt_GetEntityProps(DynEntityType dynEntType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DynEnt_GetId
==============
*/
unsigned __int16 DynEnt_GetId(const DynEntityDef *dynEntDef, DynEntityDrawType drawType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEnt_GetAbsId
==============
*/
__int16 DynEnt_GetAbsId(const DynEntityDef *dynEntDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	__int16 tmp;
	return tmp;
}

/*
==============
DynEnt_GetEntityCount
==============
*/
unsigned __int16 DynEnt_GetEntityCount(DynEntityCollType collType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEnt_GetClientModelPoseList
==============
*/
DynEntityPose *DynEnt_GetClientModelPoseList()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DynEnt_GetClientPose
==============
*/
DynEntityPose *DynEnt_GetClientPose(unsigned __int16 dynEntId, DynEntityDrawType drawType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DynEnt_GetServerEntity
==============
*/
DynEntityServer *DynEnt_GetServerEntity(unsigned __int16 dynEntId, DynEntityDrawType drawType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DynEnt_GetClientIdDrawType
==============
*/
void DynEnt_GetClientIdDrawType(unsigned __int16 absId, unsigned __int16 *outId, DynEntityDrawType *drawType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_GetClientAbsId
==============
*/
int DynEnt_GetClientAbsId(unsigned __int16 dynEntId, DynEntityDrawType drawType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEnt_Create
==============
*/
bool DynEnt_Create(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEnt_LoadEntities
==============
*/
void DynEnt_LoadEntities()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_Valid
==============
*/
bool DynEnt_Valid(const unsigned __int16 absDynEntId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEnt_GetClientPose
==============
*/
DynEntityPose *DynEnt_GetClientPose(unsigned __int16 absDynEntId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

