#pragma once

#include "types.h"

//t6/code/src_noserver/dynentity/dynentity_client.cpp
void DynEntCl_RegisterDvars();
XModel *DynEntCl_GetCurrentXModel(const DynEntityDef *dynEntDef, const DynEntityClient *dynEntClient);
;
;
void DynEntCl_LinkBrush(unsigned __int16 dynEntId);
void DynEntCl_UnlinkEntity(unsigned __int16 dynEntId, DynEntityDrawType drawType);
void DynEnt_DestroyPhysics(PhysWorld worldIndex, const DynEntityDef *dynEntDef, DynEntityClient *dynEntClient);
void DynEntCl_UpdateBounds();
void DynEnt_FixupLightConstraints(LocalClientNum_t localClientNum, int entnum, int primaryLightIndex);
void DynEnt_UpdateLightConstraint(;
void DynEnt_UpdateConstraints(;
int DynEnt_GetSurfaceType(const DynEntityDef *dynEntDef);
void DynEntCl_PointTrace_r(;
void DynEntCl_PointTrace(const pointtrace_t *clip, trace_t *results);
void DynEntCl_AreaEntities_r(;
unsigned __int16 DynEntCl_AreaEntities(;
void DynEntCl_PlayEventFx(const FxEffectDef *def, const vec3_t *origin, const vec3_t *axis);
void DynEntCl_PlayImpactEffects(;
void DynEntCl_TurnOffLight(const DynEntityDef *dynEntDef);
void DynEntCl_Enable(unsigned __int16 absId, const bool enable);
void DynEntCl_Damage(;
bool DynEntCl_IsLocalClient(LocalClientNum_t localClientNum, int sourceEntityNum);
unsigned int DynEntCl_PlayBoltedFX(const FxEffectDef *fx, unsigned __int16 absDynEntId);
void DynEntCl_RemoveFromFadeList(unsigned __int16 absDynEntId);
void DynEntCl_SetBurnFrac(unsigned __int16 dynEntId, DynEntityDrawType drawType, float frac);
double DynEntCl_GetBurnTime(unsigned __int16 dynEntId, DynEntityDrawType drawType);
BOOL DynEntCl_CompareDynEntsForExplosion(const DynEntSortStruct *ent1, const DynEntSortStruct *ent2);
void DynEntCl_DestroyEvent(;
void CreateRopes(LocalClientNum_t localClientNum);
unsigned __int16 DynEnt_GetDynEntity(int targetname);
void SCR_DynEnt_GetDynEntityArray(int targetname);
void MapHitLocationToRagdollBoneName(hitLocation_t hitLoc, unsigned int *boneName);
void CheckDynEnts();
void DynEntCl_Shutdown(LocalClientNum_t localClientNum);
;
int DynEntCl_CreatePhysObj(;
void DynEntCl_Launch(unsigned __int16 absId, const vec3_t *dir, const vec3_t *hitp);
void DynEntCl_SetBurning(unsigned __int16 dynEntId, DynEntityDrawType drawType, bool burning);
LocalClientNum_t DynEnt_UpdateBurning();
void DynEntCl_FlameDamage(;
void DynEntCl_EntityImpactEvent(;
;
;
char DynEntCl_DynEntBulletImpactEvent(;
void DynEntCl_InitEntities(LocalClientNum_t localClientNum);
void DynEntCl_DestroyEntityModel(unsigned __int16 id);
void DynEntCl_CleanUpOldModels();
unsigned __int16 DynEntCl_AddEntityModel();
unsigned __int16 DynEntCl_CreateEntityModel(;
void DynEntCl_SetFadeOut(unsigned __int16 dynEntId, DynEntityDrawType drawType);
void DynEnt_UpdateFading(int currentTime);
void DynEntCl_MeleeEvent(LocalClientNum_t localClientNum, int attackerEntNum);
void DynEntCl_ProcessEntities(LocalClientNum_t localClientNum, int time);
unsigned int DynEntCl_GetClosestEntities(;
void DynEntCl_ExplosionEvent(;
void DynEntCl_JetThrustEvent(;

//t6/code/src_noserver/dynentity/dynentity_coll.cpp
void TRACK_DynEntityCollWorld();
DynEntityCollSector *DynEnt_GetCollSector(DynEntityCollType collType, unsigned int sectorIndex);
void DynEnt_ClearCollWorld(DynEntityCollType collType);
unsigned __int16 DynEnt_AllocCollSector(DynEntityCollType collType, const vec2_t *mins, const vec2_t *maxs);
void DynEnt_AddToCollSector(;
void DynEnt_UnlinkEntity(DynEntityCollType collType, unsigned __int16 dynEntId);
int DynEnt_GetContents(const DynEntityDef *dynEntDef);
void DynEnt_GetLocalBounds(const DynEntityDef *dynEntDef, vec3_t *mins, vec3_t *maxs);
double DynEnt_GetRadiusDistSqr(const DynEntityColl *dynEntColl, const vec3_t *origin);
bool DynEnt_IsInCone(;
double DynEnt_GetCylindricalRadiusDistSqr(const DynEntityColl *dynEntColl, const vec3_t *origin);
bool DynEnt_EntityInArea(;
void DynEnt_PointTraceToModel(;
void DynEnt_PointTraceToBrush(;
void DynEnt_SortCollSector(;
void DynEnt_LinkEntity(;

//t6/code/src_noserver/dynentity/dynentity_gamestate.cpp
void DynEnt_WriteGameState(msg_t *msg);
void DynEnt_ReadGameState(msg_t *msg, LocalClientNum_t localClientNum);

//#include "dynentity/dynentity_load_db.h"

//t6/code/src_noserver/dynentity/dynentity_load_obj.cpp
DynEntityType DynEnt_GetType(const char *typeName);
void DynEnt_GetEntityCountFromString(const char *entityString, int *entCount, int *constraintCount);
const char *LoadRopeParams();
bool DynEnt_CreateConstraint(PhysConstraint *constraint, DynEntityConstraintCreateParams *params);
void DynEnt_GetEntityConstraintParams(;
void *DynEnt_AllocXModel(int size);
void *DynEnt_AllocXModelColl(int size);
XModel *DynEnt_XModelPrecache(const char *modelName);
void *DynEnt_AllocPhysPreset(int size);
void *DynEnt_AllocXModelPieces(int size);
PhysPreset *DynEnt_PhysPresetPrecache(const char *name);
XModelPieces *DynEnt_XModelPiecesPrecache(const char *name);
bool FindConstraints(;
PhysPreset *DynEnt_AutoCreatePhysPreset(const DynEntityDef *dynEntDef, const DynEntityCreateParams *params);
int DynEnt_CompareEntities(const void *arg0, const void *arg1);
void GetAttachPointsInWorldSpace(PhysConstraint *constraint, vec3_t *p0, vec3_t *p1);
const DynEntityProps *DynEnt_GetEntityProps(DynEntityType dynEntType);
unsigned __int16 DynEnt_GetId(const DynEntityDef *dynEntDef, DynEntityDrawType drawType);
__int16 DynEnt_GetAbsId(const DynEntityDef *dynEntDef);
unsigned __int16 DynEnt_GetEntityCount(DynEntityCollType collType);
DynEntityPose *DynEnt_GetClientModelPoseList();
DynEntityPose *DynEnt_GetClientPose(unsigned __int16 dynEntId, DynEntityDrawType drawType);
DynEntityServer *DynEnt_GetServerEntity(unsigned __int16 dynEntId, DynEntityDrawType drawType);
void DynEnt_GetClientIdDrawType(unsigned __int16 absId, unsigned __int16 *outId, DynEntityDrawType *drawType);
int DynEnt_GetClientAbsId(unsigned __int16 dynEntId, DynEntityDrawType drawType);
bool DynEnt_Create(;
void DynEnt_LoadEntities();
bool DynEnt_Valid(const unsigned __int16 absDynEntId);
DynEntityPose *DynEnt_GetClientPose(unsigned __int16 absDynEntId);

//#include "dynentity/dynentity_load_obj.h"

//t6/code/src_noserver/dynentity/dynentity_pieces.cpp
void DynEntPieces_RegisterDvars();
void DynEntPieces_AddDrawSurfs();
int DynEntPieces_SpawnPhysObj(;
void DynEntPieces_SpawnPieces(;

//t6/code/src_noserver/dynentity/dynentity_server.cpp
void DynEntSv_RegisterDvars();
;
;
void DynEntClSv_ShouldCullEntitiesForSplitscreen();
void DynEntSv_InitEntities();
void DynEntSv_PointTrace_r(;
void DynEntSv_PointTrace(const pointtrace_t *clip, trace_t *results);
void DynEntSv_PointTrace(;
void DynEntSv_ClipMoveTrace_r(;
void DynEntSv_ClipMoveTrace(const moveclip_t *clip, trace_t *results);
void DynEntSv_AreaEntities_r(;
unsigned __int16 DynEntSv_AreaEntities(;
void DynEntSv_Damage(;
unsigned int DynEntSv_GetClosestEntities(;
void DynEntSv_RadiusDamage(;

