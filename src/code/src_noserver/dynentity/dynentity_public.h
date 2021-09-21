#pragma once

#include "types.h"

//t6/code/src_noserver/dynentity/dynentity_client.cpp
void DynEntCl_RegisterDvars();
XModel *DynEntCl_GetCurrentXModel(const DynEntityDef *dynEntDef, const DynEntityClient *dynEntClient);
float DynEntCl_UpdateBModelWorldBounds(const GfxPlacement *pose);
void DynEntCl_LinkModel(unsigned int a1, unsigned __int16 dynEntId);
void DynEntCl_LinkBrush(unsigned __int16 dynEntId);
void DynEntCl_UnlinkEntity(unsigned __int16 dynEntId, DynEntityDrawType drawType);
void DynEnt_DestroyPhysics(PhysWorld worldIndex, const DynEntityDef *dynEntDef, DynEntityClient *dynEntClient);
void DynEntCl_UpdateBounds();
void DynEnt_FixupLightConstraints(LocalClientNum_t localClientNum, int entnum, int primaryLightIndex);
void DynEnt_UpdateLightConstraint(LocalClientNum_t localClientNum, const DynEntityDef *dynEntDef, const DynEntityPose *dynEntPose);
void DynEnt_UpdateConstraints(LocalClientNum_t localClientNum, DynEntityClient *dynEntClient, const DynEntityDef *dynEntDef);
int DynEnt_GetSurfaceType(const DynEntityDef *dynEntDef);
void DynEntCl_PointTrace_r(DynEntityDrawType drawType, const pointtrace_t *clip, unsigned int sectorIndex, vec4_t *p1, vec4_t *p2, trace_t *results);
void DynEntCl_PointTrace(const pointtrace_t *clip, trace_t *results);
void DynEntCl_AreaEntities_r(DynEntityDrawType drawType, unsigned int sectorIndex, DynEntityAreaParms *areaParms);
unsigned __int16 DynEntCl_AreaEntities(DynEntityDrawType drawType, const vec3_t *mins, const vec3_t *maxs, int contentMask, unsigned __int16 dynEntMaxCount, unsigned __int16 *dynEntList);
void DynEntCl_PlayEventFx(const FxEffectDef *def, const vec3_t *origin, const vec3_t *axis);
void DynEntCl_PlayImpactEffects(LocalClientNum_t localClientNum, int sourceEntityNum, int surfType, const vec3_t *hitPos, const vec3_t *hitNormal);
void DynEntCl_TurnOffLight(const DynEntityDef *dynEntDef);
void DynEntCl_Enable(unsigned __int16 absId, const bool enable);
void DynEntCl_Damage(LocalClientNum_t localClientNum, unsigned __int16 dynEntId, DynEntityDrawType drawType, const vec3_t *hitPos, const vec3_t *hitDir, int damage);
bool DynEntCl_IsLocalClient(LocalClientNum_t localClientNum, int sourceEntityNum);
unsigned int DynEntCl_PlayBoltedFX(const FxEffectDef *fx, unsigned __int16 absDynEntId);
void DynEntCl_RemoveFromFadeList(unsigned __int16 absDynEntId);
void DynEntCl_SetBurnFrac(unsigned __int16 dynEntId, DynEntityDrawType drawType, float frac);
double DynEntCl_GetBurnTime(unsigned __int16 dynEntId, DynEntityDrawType drawType);
BOOL DynEntCl_CompareDynEntsForExplosion(const DynEntSortStruct *ent1, const DynEntSortStruct *ent2);
void DynEntCl_DestroyEvent(LocalClientNum_t localClientNum, unsigned __int16 dynEntId, DynEntityDrawType drawType, const vec3_t *hitPos, const vec3_t *hitDir);
void CreateRopes(LocalClientNum_t localClientNum);
unsigned __int16 DynEnt_GetDynEntity(int targetname);
void SCR_DynEnt_GetDynEntityArray(int targetname);
void MapHitLocationToRagdollBoneName(hitLocation_t hitLoc, unsigned int *boneName);
void CheckDynEnts();
void DynEntCl_Shutdown(LocalClientNum_t localClientNum);
void DynEnt_SetupConstraints(unsigned int a1, const DynEntityDef *dynEntDef);
int DynEntCl_CreatePhysObj(const DynEntityDef *dynEntDef, DynEntityClient *dynEntClient, const GfxPlacement *pose);
void DynEntCl_Launch(unsigned __int16 absId, const vec3_t *dir, const vec3_t *hitp);
void DynEntCl_SetBurning(unsigned __int16 dynEntId, DynEntityDrawType drawType, bool burning);
LocalClientNum_t DynEnt_UpdateBurning();
void DynEntCl_FlameDamage(LocalClientNum_t localClientNum, unsigned __int16 dynEntId, DynEntityDrawType drawType, const vec3_t *hitPos, const vec3_t *hitVel, int damage);
void DynEntCl_EntityImpactEvent(const trace_t *trace, LocalClientNum_t localClientNum, int sourceEntityNum, const vec3_t *start, const vec3_t *hitPos, bool isMelee);
void DynEntCl_HitTrace(const vec3_t *end, trace_t *results);
bool DynEntCl_DynEntImpactEvent(const vec3_t *end, vec3_t *hitPos);
char DynEntCl_DynEntBulletImpactEvent(LocalClientNum_t localClientNum, int sourceEntityNum, const vec3_t *start, const vec3_t *end, const WeaponDef *weapDef);
void DynEntCl_InitEntities(LocalClientNum_t localClientNum);
void DynEntCl_DestroyEntityModel(unsigned __int16 id);
void DynEntCl_CleanUpOldModels();
unsigned __int16 DynEntCl_AddEntityModel();
unsigned __int16 DynEntCl_CreateEntityModel(XModel *model, const vec4_t *quat, const vec3_t *origin, const vec3_t *hitPos, const vec3_t *hitDir, const int mod, PhysPreset *preset);
void DynEntCl_SetFadeOut(unsigned __int16 dynEntId, DynEntityDrawType drawType);
void DynEnt_UpdateFading(int currentTime);
void DynEntCl_MeleeEvent(LocalClientNum_t localClientNum, int attackerEntNum);
void DynEntCl_ProcessEntities(LocalClientNum_t localClientNum, int time);
unsigned int DynEntCl_GetClosestEntities(DynEntityDrawType drawType, const vec3_t *radiusMins, const vec3_t *radiusMaxs, const vec3_t *origin, unsigned __int16 *hitEnts, bool isCylinder);
void DynEntCl_ExplosionEvent(int a1, LocalClientNum_t a2, LocalClientNum_t localClientNum, bool isCylinder, const vec3_t *origin, float innerRadius, float outerRadius, const vec3_t *impulse, float inScale, int innerDamage, int outerDamage, bool isBulletExplosiveDamage);
void DynEntCl_JetThrustEvent(int a1, LocalClientNum_t a2, LocalClientNum_t localClientNum, const vec3_t *origin, const vec3_t *forward, float outerRadius, float dotLimit);

//t6/code/src_noserver/dynentity/dynentity_coll.cpp
void TRACK_DynEntityCollWorld();
DynEntityCollSector *DynEnt_GetCollSector(DynEntityCollType collType, unsigned int sectorIndex);
void DynEnt_ClearCollWorld(DynEntityCollType collType);
unsigned __int16 DynEnt_AllocCollSector(DynEntityCollType collType, const vec2_t *mins, const vec2_t *maxs);
void DynEnt_AddToCollSector(DynEntityCollType collType, unsigned __int16 dynEntId, unsigned __int16 sectorIndex);
void DynEnt_UnlinkEntity(DynEntityCollType collType, unsigned __int16 dynEntId);
int DynEnt_GetContents(const DynEntityDef *dynEntDef);
void DynEnt_GetLocalBounds(const DynEntityDef *dynEntDef, vec3_t *mins, vec3_t *maxs);
double DynEnt_GetRadiusDistSqr(const DynEntityColl *dynEntColl, const vec3_t *origin);
bool DynEnt_IsInCone(const DynEntityDef *dynEntDef, const GfxPlacement *pose, const vec3_t *origin, float coneAngleCos, const vec3_t *coneDir);
double DynEnt_GetCylindricalRadiusDistSqr(const DynEntityColl *dynEntColl, const vec3_t *origin);
bool DynEnt_EntityInArea(const DynEntityDef *dynEntDef, const DynEntityColl *dynEntColl, const vec3_t *mins, const vec3_t *maxs, int contentMask);
void DynEnt_PointTraceToModel(const DynEntityDef *dynEntDef, const XModel *xmodel, const GfxPlacement *pose, const pointtrace_t *clip, trace_t *results);
void DynEnt_PointTraceToBrush(const DynEntityDef *dynEntDef, const GfxPlacement *pose, const pointtrace_t *clip, trace_t *results);
void DynEnt_SortCollSector(DynEntityCollType collType, unsigned __int16 sectorIndex, const vec2_t *mins, const vec2_t *maxs);
void DynEnt_LinkEntity(DynEntityCollType collType, unsigned __int16 dynEntId, const vec3_t *absMins, const vec3_t *absMaxs);

//t6/code/src_noserver/dynentity/dynentity_gamestate.cpp
void DynEnt_WriteGameState(msg_t *msg);
void DynEnt_ReadGameState(msg_t *msg, LocalClientNum_t localClientNum);

//#include "dynentity/dynentity_load_db.h"

//t6/code/src_noserver/dynentity/dynentity_load_obj.cpp
DynEntityType DynEnt_GetType(const char *typeName);
void DynEnt_GetEntityCountFromString(const char *entityString, int *entCount, int *constraintCount);
const char *LoadRopeParams();
bool DynEnt_CreateConstraint(PhysConstraint *constraint, DynEntityConstraintCreateParams *params);
void DynEnt_GetEntityConstraintParams(DynEntityConstraintCreateParams *constraintParams, PhysConstraint *constraints, int dynEntConstraintCount);
void *DynEnt_AllocXModel(int size);
void *DynEnt_AllocXModelColl(int size);
XModel *DynEnt_XModelPrecache(const char *modelName);
void *DynEnt_AllocPhysPreset(int size);
void *DynEnt_AllocXModelPieces(int size);
PhysPreset *DynEnt_PhysPresetPrecache(const char *name);
XModelPieces *DynEnt_XModelPiecesPrecache(const char *name);
bool FindConstraints(const char *targetname, const vec3_t *origin, const vec3_t *angles, AttachPointType attach_type, DynEntityConstraintCreateParams *constraintParams, int numConstraints, int *outConstraints);
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
bool DynEnt_Create(DynEntityDef *dynEntDef, const DynEntityCreateParams *params, DynEntityConstraintCreateParams *constraintParams, int numConstraints);
void DynEnt_LoadEntities(char *a1);
bool DynEnt_Valid(const unsigned __int16 absDynEntId);
DynEntityPose *DynEnt_GetClientPose(unsigned __int16 absDynEntId);

//#include "dynentity/dynentity_load_obj.h"

//t6/code/src_noserver/dynentity/dynentity_pieces.cpp
void DynEntPieces_RegisterDvars();
void DynEntPieces_AddDrawSurfs();
int DynEntPieces_SpawnPhysObj(const char *modelName, int stype, const vec3_t *mins, const vec3_t *maxs, const vec3_t *position, const vec4_t *quat, const vec3_t *velocity, const vec3_t *angularVelocity, const PhysPreset *physPreset);
void DynEntPieces_SpawnPieces(LocalClientNum_t localClientNum, const XModelPieces *pieces, const vec3_t *origin, const vec3_t *axis, const vec3_t *hitPos, const vec3_t *hitDir);

//t6/code/src_noserver/dynentity/dynentity_server.cpp
void DynEntSv_RegisterDvars();
void DynEntSv_LinkModel(unsigned __int16 dynEntId);
void DynEntSv_LinkBrush(unsigned __int16 dynEntId);
void DynEntClSv_ShouldCullEntitiesForSplitscreen();
void DynEntSv_InitEntities();
void DynEntSv_PointTrace_r(DynEntityDrawType drawType, const pointtrace_t *clip, unsigned int sectorIndex, const vec4_t *p1, const vec4_t *p2, trace_t *results);
void DynEntSv_PointTrace(const pointtrace_t *clip, trace_t *results);
void DynEntSv_PointTrace(unsigned __int16 id, DynEntityDrawType drawType, const pointtrace_t *clip, trace_t *results);
void DynEntSv_ClipMoveTrace_r(const moveclip_t *clip, unsigned int sectorIndex, const vec4_t *p1, const vec4_t *p2, trace_t *results);
void DynEntSv_ClipMoveTrace(const moveclip_t *clip, trace_t *results);
void DynEntSv_AreaEntities_r(DynEntityDrawType drawType, unsigned int sectorIndex, DynEntityAreaParms *areaParms);
unsigned __int16 DynEntSv_AreaEntities(DynEntityDrawType drawType, const vec3_t *mins, const vec3_t *maxs, int contentMask, unsigned __int16 dynEntMaxCount, unsigned __int16 *dynEntList);
void DynEntSv_Damage(unsigned __int16 dynEntId, DynEntityDrawType drawType, const vec3_t *hitPos, const vec3_t *hitDir, int damage, bool explosive);
unsigned int DynEntSv_GetClosestEntities(DynEntityDrawType drawType, const vec3_t *radiusMins, const vec3_t *radiusMaxs, const vec3_t *origin, unsigned __int16 *hitEnts);
void DynEntSv_RadiusDamage(unsigned __int16 *a1, const vec3_t *origin, float radius, float coneAngleCos, vec3_t *coneDirection, float innerDamage, float outerDamage);

