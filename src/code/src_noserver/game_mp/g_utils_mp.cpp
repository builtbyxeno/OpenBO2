#include "types.h"
#include "functions.h"

/*
==============
G_ClearCachedModels
==============
*/
void G_ClearCachedModels()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_FindConfigstringIndex
==============
*/
int G_FindConfigstringIndex(const char *name, int start, int max, int create, const char *errormsg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_LocalizedStringIndex
==============
*/
int G_LocalizedStringIndex(const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ClearRegisteredLeaderboards
==============
*/
void ClearRegisteredLeaderboards()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SaveRegisteredLeaderboards
==============
*/
void SaveRegisteredLeaderboards()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_MaterialIndex
==============
*/
int G_MaterialIndex(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_ModelIndex
==============
*/
unsigned int G_ModelIndex(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_GetModel
==============
*/
XModel *G_GetModel(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_GetModelBounds
==============
*/
bool G_GetModelBounds(int index, vec3_t *outMins, vec3_t *outMaxs)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_ModelName
==============
*/
unsigned int G_ModelName(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_EntityCentroid
==============
*/
void G_EntityCentroid(const gentity_t *ent, vec3_t *centroid)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetEntityBoundsPoint
==============
*/
void G_GetEntityBoundsPoint(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_EntityNearestBoxPoint
==============
*/
void G_EntityNearestBoxPoint(const gentity_t *ent, const vec3_t *vOrigin, vec3_t *vClosest)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_TagIndex
==============
*/
int G_TagIndex(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_EffectIndex
==============
*/
int G_EffectIndex(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_ShellShockIndex
==============
*/
int G_ShellShockIndex(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_RumbleIndex
==============
*/
int G_RumbleIndex(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_GetEntAnimTree
==============
*/
XAnimTree_s *G_GetEntAnimTree(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_SetModel
==============
*/
void G_SetModel(gentity_t *ent, const char *modelName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SetModelIfLoaded
==============
*/
void G_SetModelIfLoaded(gentity_t *ent, const char *modelName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_OverrideModel
==============
*/
void G_OverrideModel(int modelIndex, const char *defaultModelName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_DObjUpdateServerTime
==============
*/
void G_DObjUpdateServerTime(gentity_t *ent, int bNotify, void (*CallbackFunc)())
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_DObjCalcPose
==============
*/
void G_DObjCalcPose(gentity_t *ent, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_DObjCalcBone
==============
*/
void G_DObjCalcBone(const gentity_t *ent, int boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_DObjGetLocalTagMatrix
==============
*/
DObjAnimMat *G_DObjGetLocalTagMatrix(const gentity_t *ent, unsigned int tagName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_DObjGetWorldTagMatrix
==============
*/
int G_DObjGetWorldTagMatrix(const gentity_t *ent, unsigned int tagName, vec3_t *tagMat)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_DObjGetWorldTagPos
==============
*/
int G_DObjGetWorldTagPos(const gentity_t *ent, unsigned int tagName, vec3_t *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_DObjGetLocalBoneIndexMatrix
==============
*/
DObjAnimMat *G_DObjGetLocalBoneIndexMatrix(const gentity_t *ent, int boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_DObjGetWorldBoneIndexPos
==============
*/
void G_DObjGetWorldBoneIndexPos(const gentity_t *ent, int boneIndex, vec3_t *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_DObjGetWorldBoneIndexMatrix
==============
*/
void G_DObjGetWorldBoneIndexMatrix(const gentity_t *ent, int boneIndex, vec3_t *tagMat)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_Find
==============
*/
gentity_t *G_Find(gentity_t *from, int fieldofs, unsigned __int16 match)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_InitGentity
==============
*/
void G_InitGentity(gentity_t *e)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_PrintEntities
==============
*/
void G_PrintEntities()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SpawnStaticEntity
==============
*/
gentity_t *G_SpawnStaticEntity(int start, int range, const char *entity_type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_SpawnTurret
==============
*/
gentity_t *G_SpawnTurret(int a1, int a2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_SpawnActor
==============
*/
gentity_t *G_SpawnActor(int a1, int a2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_Spawn
==============
*/
gentity_t *G_Spawn()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_ClearGroundEntity
==============
*/
void G_ClearGroundEntity(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_ClearGroundEntityRefs
==============
*/
void G_ClearGroundEntityRefs(gentity_t *ed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_FreeEntityDelay
==============
*/
void G_FreeEntityDelay(gentity_t *ed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_BroadcastEntity
==============
*/
void G_BroadcastEntity(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_FreeEntityAfterEvent
==============
*/
void G_FreeEntityAfterEvent(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_AddEvent
==============
*/
void G_AddEvent(gentity_t *ent, int event, unsigned int eventParm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_RegisterSoundWait
==============
*/
void G_RegisterSoundWait(gentity_t *ent, unsigned int index, unsigned int notifyString)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SetOrigin
==============
*/
void G_SetOrigin(gentity_t *ent, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SetAngle
==============
*/
void G_SetAngle(gentity_t *ent, const vec3_t *angle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SetConstString
==============
*/
void G_SetConstString(unsigned __int16 *to, const char *from)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetEntityTypeName
==============
*/
const char *G_GetEntityTypeName(const gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_IsSpeciesDog
==============
*/
BOOL G_IsSpeciesDog(int species)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_IsBigDog
==============
*/
BOOL G_IsBigDog(gentity_t *gent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_IsSpeciesBigDog
==============
*/
BOOL CG_IsSpeciesBigDog(int species)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_SpeciesUsesNonGenericAnimtree
==============
*/
BOOL G_SpeciesUsesNonGenericAnimtree(int species)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_SpeciesCanUseNegotiations
==============
*/
BOOL G_SpeciesCanUseNegotiations(int species)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_srand
==============
*/
void G_srand(unsigned int seed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetRandomSeed
==============
*/
unsigned int *G_GetRandomSeed()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_rand
==============
*/
unsigned int G_rand()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_flrand
==============
*/
double G_flrand(float min, float max)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_irand
==============
*/
int G_irand(int min, int max)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_random
==============
*/
double G_random()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_crandom
==============
*/
double G_crandom()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_UpdateVehicleAttachedModels
==============
*/
void G_UpdateVehicleAttachedModels(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_UpdateScriptMoverAttachedModels
==============
*/
void G_UpdateScriptMoverAttachedModels(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_ClientDObjUpdate
==============
*/
void G_ClientDObjUpdate(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_DObjUpdate
==============
*/
void G_DObjUpdate(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_PlayerCorpseDObjUpdate
==============
*/
void G_PlayerCorpseDObjUpdate(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_DObjLoad
==============
*/
void G_DObjLoad(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_EntDetach
==============
*/
int G_EntDetach(gentity_t *ent, const char *modelName, unsigned int tagName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_EntDetachAll
==============
*/
void G_EntDetachAll(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_TraceBulletPathForVehTurret
==============
*/
void G_TraceBulletPathForVehTurret(gentity_t *ent, DObjTrace_s *trace, int gunnerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SpawnVehicle
==============
*/
gentity_t *G_SpawnVehicle(int a1, int a2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_FreeEntityRefs
==============
*/
void G_FreeEntityRefs(gentity_t *ed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_FreeEntity
==============
*/
void G_FreeEntity(gentity_t *ed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_TempEntity
==============
*/
gentity_t *G_TempEntity(const vec3_t *origin, int event)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_PlaySoundAliasAtPoint
==============
*/
gentity_t *G_PlaySoundAliasAtPoint(const vec3_t *origin, unsigned int alias)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_PlaySoundAlias
==============
*/
gentity_t *G_PlaySoundAlias(gentity_t *ent, unsigned int alias, unsigned int notifyString, unsigned int bone)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_PlaySoundAliasWithNotify
==============
*/
/*gentity_t *G_PlaySoundAliasWithNotify@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
G_AnimScriptSound
==============
*/
void G_AnimScriptSound(ClientNum_t client, SndAliasList *aliasList)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_EntAttach
==============
*/
int G_EntAttach(gentity_t *ent, const char *modelName, unsigned int tagName, int ignoreCollision)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_SpawnPlayerClone
==============
*/
gentity_t *G_SpawnPlayerClone()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_SpawnActorClone
==============
*/
gentity_t *G_SpawnActorClone()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
G_SpawnVehicle
==============
*/
void G_SpawnVehicle(gentity_t *ent, const char *typeName, int load)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SpawnTurret
==============
*/
void G_SpawnTurret(gentity_t *self, const char *weaponinfoname, SpawnVar *spawnVar)
{
	UNIMPLEMENTED(__FUNCTION__);
}

