#pragma once

#include "types.h"

//t6/code/src_noserver/physics/destructible.cpp
void TRACK_destructible();
void Destructible_DumpEventInfo();
void EnableAllDestructiblePieces();
char IsDestructiblePieceDisabled(int label);
void CG_EnableAllDestructiblePieces();
int CG_GetDestructibleIndex(LocalClientNum_t localClientNum, const Destructible *destructible);
Destructible *Destructible_GetDestructibleByIndex(int index);
Destructible *Destructible_GetFreeDestructible();
void Destructible_FreeDestructible(Destructible *destructible);
Destructible *CG_GetFreeDestructible(LocalClientNum_t localClientNum, int entNum);
void CG_InitDestructibles(LocalClientNum_t localClientNum);
void G_InitDestructibles();
destructible_gamestate *Destructible_FindGameState(int entityNum, LocalClientNum_t localClientNum);
char Destructible_RemoveGameState(int entityNum, LocalClientNum_t localClientNum);
int Destructible_GetNumStagesForPiece(DestructibleDef *ddef, int pieceIndex);
int Destructible_GetDestructibleStage(const DestructibleDef *ddef, int pieceIndex, int health);
unsigned int Destructible_GetShowBoneNameForPiece(Destructible *destructible, int pieceIndex);
void Destructible_GetHideParts(Destructible *destructible, unsigned int *partBits);
char Destructible_GetPieceIndexFromBoneName(Destructible *destructible, int modelIndex, unsigned int boneName, unsigned __int8 *index);
int GetHealthFromState(const LerpEntityStateDestructibleHit *state, DestructibleDef *ddef, unsigned __int8 pieceIndex);
void DestructibleEventSetPieceState(Destructible *destructible, LerpEntityStateDestructibleHit *state);
void CG_DestructibleClientOnlyCreate(centity_t *ent, DestructibleDef *ddef);
int CG_SpawnPhysObjForBone(const centity_t *cent, int pieceIndex, int boneName, const vec3_t *hitp, const vec3_t *hitd, int mod);
unsigned int CG_GetTagTransform(centity_t *self, DestructibleDef *ddef, int pieceIndex, vec3_t *tagOrigin, vec3_t *tagMat);
unsigned int G_GetTagTransform(gentity_t *ent, DestructibleDef *ddef, int pieceIndex, vec3_t *tagMat);
void CG_DestructibleSetBurn(LocalClientNum_t localClientNum, centity_t *self, Destructible *destructible, int pieceIndex, bool burn);
double CG_DestructibleGetBurnFrac(Destructible *destructible);
BOOL CG_DestructibleIsClientOnly(Destructible *destructible);
void CG_DestructibleUpdateDObj(centity_t *self);
void CG_StoreDestructibleState(centity_t *cent, DestructibleState newState);
void CG_DestructibleRewindToTime(LocalClientNum_t localClientNum, Destructible *destructible, int time);
unsigned __int8 *CM_Hunk_AllocDestructible(int size);
DestructibleDef *DestructibleDefPrecache_LoadObj(const char *name);
DestructibleDef *DestructibleDefPrecache_FastFile(const char *name);
DestructibleDef *DestructibleDefPrecache();
int Destructible_GetPieceCount(Destructible *obj);
unsigned int Destructible_XDollActive(Destructible *obj);
int Destructible_GetXDollHandle(Destructible *obj, int piece_index);
environment_rigid_body *__cdecl Destructible_GetRigidBody();
void Destructible_LoadDestructibles(MemoryFile *memFile);
void Destructible_WriteGameState(msg_t *msg);
void Destructible_ReadGameState(msg_t *msg, LocalClientNum_t localClientNum);
void Demo_Destructible_WriteGameState(msg_t *msg, LocalClientNum_t localClientNum);
void Demo_Destructible_ReadGameState(msg_t *msg, LocalClientNum_t localClientNum);
DestructiblePose *CG_GetDestructiblePose(__int16 index);
void CG_DestructibleShake(LocalClientNum_t localClientNum, centity_t *cent, int pieceIndex, const vec3_t *dir, const vec3_t *hitp, const int mod);
void Destructible_SetDebugRender(Destructible *destructible);
void Destructible_DebugRender();
DestructibleDef *Destructible_GetDDef(const centity_t *cent);
void Scr_DestructibleCallback(gentity_t *self, unsigned __int16 event, int piece, float time, int damage);
void DisableDestructiblePiece(int label);
void CG_DisableDestructiblePiece(LocalClientNum_t localClientNum, int label);
unsigned __int16 DestructibleUpdate(gentity_t *ent, DObjModel_s *dobjModels, unsigned __int16 numModels);
void DestructibleExplosiveDamageEvent(gentity_t *self, const vec3_t *point, const float radius, const int mod);
void DestructibleBulletDamageEvent(gentity_t *self, const vec3_t *point, const vec3_t *dir, const int mod);
char DamagePiece(gentity_t *self, unsigned __int8 index, int damage, const vec3_t *point, const vec3_t *dir, int mod, const bool damageChildren, const int excludeChild, gentity_t *attacker, int recursiveDepth, Weapon weapon);
double DestructibleRadiusDamage(gentity_t *self, const vec3_t *point, float damgeInner, float damgeOuter, float radius, int mod, gentity_t *attacker, Weapon weapon);
int DestructibleDamage(gentity_t *self, gentity_t *attacker, const vec3_t *dir, const vec3_t *point, int damage, int mod, unsigned int modelIndex, unsigned int partName, Weapon weapon);
unsigned int CG_DestructibleUpdate(centity_t *ent, DObjModel_s *dobjModels, unsigned int numModels, LocalClientNum_t localClientNum);
unsigned __int16 CG_DestructibleSpawnDynEnt(unsigned int a1, const centity_t *cent, XModel *model, vec3_t *origin, vec3_t *mat, const vec3_t *hitp, const vec3_t *hitd, int mod);
void CG_DestructibleBreakPiece(centity_t *self, DestructiblePiece *piece, int pieceIndex, int stage, int nextStage, const vec3_t *hitp, const vec3_t *hitd, const int mod);
void CG_RestartDestructibles(LocalClientNum_t localClientNum);
bool CG_DestructibleDamage(vec3_t *a1, centity_t *self, const vec3_t *dir, const vec3_t *point, const unsigned int pieceIndex, const int newHealth, int damage, const int mod, const bool updateDObj, const bool applyForce);
void CG_FreeDestructiblePose(LocalClientNum_t localClientNum, unsigned __int8 destructiblePoseID);
void CG_FreeDestructible(LocalClientNum_t localClientNum, Destructible *destructible);
char CG_DamagePiece(vec3_t *a1, LocalClientNum_t localClientNum, centity_t *self, unsigned __int8 index, int damage, const vec3_t *point, const vec3_t *dir, int mod, const bool damageChildren, int recursiveDepth);
void CG_DestructibleRadiusDamage(centity_t *self, const vec3_t *point, float damgeInner, float damgeOuter, float radius, int mod, const int lazyprocess);
void CG_DestructibleHitEvent(LocalClientNum_t localClientNum, int event, const entityState_s *es, const int lazyprocess);
void CG_DestructibleDamage(const char *a1, centity_t *self, const centity_t *attacker, const vec3_t *dir, const vec3_t *point, int damage, int mod, unsigned int modelIndex, unsigned int partName, const int lazyprocess);
void CG_ProcessDestructibleEvents();

//#include "physics/destructible.h"

//#include "physics/destructibledef_load_db.h"

//t6/code/src_noserver/physics/destructibledef_load_obj.cpp
void DestructibleDef_Strcpy(unsigned __int8 *member, const char *keyValue);
int DestructiblePiece_ParseDefSpecificFieldType(unsigned __int8 *pStruct, const char *pValue, const int iFieldType);
DestructiblePiece *DestructiblePieceLoadFile(fsMode_t a1, const char *name, DestructiblePiece *destructiblePiece);
int Destructible_ParseDefSpecificFieldType(unsigned __int8 *pStruct, const char *pValue, const int iFieldType);
DestructibleDef *DestructibleDefLoadFile(fsMode_t a1, const char *name, void *(*Alloc)(int));

//#include "physics/physconstraints_load_db.h"

//t6/code/src_noserver/physics/physconstraints_load_obj.cpp
void PhysConstraints_Strcpy(unsigned __int8 *member, const char *keyValue);
int CON_ParseSpecificField(unsigned __int8 *pStruct, const char *pValue, const int fieldType);
void PhysConstraintsPostLoadFixup(PhysConstraints *physConstraints);
PhysConstraints *PhysConstraintsLoadFile(fsMode_t a1, const char *name, void *(*Alloc)(int));
PhysConstraints *PhysConstraintsPrecache(const char *name, void *(*Alloc)(int));
void PhysConstraintsUpdateField(int (*a1)(unsigned __int8 *, const char *, const int, const int), const char *name, const char *keyvalue);

//#include "physics/physpreset_load_db.h"

//t6/code/src_noserver/physics/physpreset_load_obj.cpp
void PhysPreset_Strcpy(unsigned __int8 *member, const char *keyValue);
PhysPreset *PhysPresetLoadFile(fsMode_t a1, const char *name, void *(*Alloc)(int));
PhysPreset *PhysPresetPrecache(const char *name, void *(*Alloc)(int));
PhysPreset *PhysPreset_Register_FastFile(const char *name);
PhysPreset *PhysPreset_Register_LoadObj(const char *name);
PhysPreset *PhysPreset_Register();

//t6/code/src_noserver/physics/phys_auto_rigid_body.cpp
// user_rigid_body *auto_rigid_body::ent_has_auto_rigid_body(const centity_t *cent);
void fixup_wheel_constraints_arb(auto_rigid_body *arb);
// void auto_rigid_body::add(const centity_t *cent, gjk_physics_collision_visitor *collision_visitor, const int mask);
// void auto_rigid_body::update(int a1);
// void auto_rigid_body::remove_ent(const centity_t *cent);

//t6/code/src_noserver/physics/phys_colgeom.cpp
void setup_gjk_polygon_cylinder(int a1, const vec3_t *mins, const vec3_t *maxs, const float radius_adjust, gjk_polygon_cylinder_t *gjk_cylinder);
unsigned int collision_get_area_persistent_code_collision(int a1, const broad_phase_environment_query_input *bpeqi, gjk_base_t **colgeoms, unsigned int max);
// gjk_aabb_t *gjk_aabb_t::create(const phys_vec3 *center, const phys_vec3 *dims, int stype, gjk_collision_visitor *allocator);
// gjk_obb_t *gjk_obb_t::create(const phys_mat44 *xform, const phys_vec3 *dims, int stype, gjk_collision_visitor *allocator);
// gjk_aabb_t *gjk_brush_t::create(float brush, const cbrush_t *a2, const int stype, gjk_collision_visitor *allocator);
// gjk_partition_t *gjk_partition_t::create(const CollisionAabbTree *tree, gjk_collision_visitor *allocator);
// gjk_double_sphere_t *gjk_double_sphere_t::create(const phys_vec3 *c0, const phys_vec3 *c1, const float r, int stype, gjk_collision_visitor *allocator);
// gjk_cylinder_t *gjk_cylinder_t::create(int _direction, float _halfHeight, float _radius, const phys_mat44 *_xform, int stype, gjk_collision_visitor *allocator);
// gjk_polygon_cylinder_t *gjk_polygon_cylinder_t::create(const vec3_t *mins, const vec3_t *maxs, const float radius_adjust, const int stype, gjk_collision_visitor *allocator);
gjk_aabb_t *create_aabb_gjk_geom(int a1, const vec3_t *mn, const vec3_t *mx, int stype, gjk_collision_visitor *allocator);
void create_brush_gjk_geom();
gjk_double_sphere_t *create_capsule_gjk_geom(int a1, const vec3_t *center, float radius, float halfHeight, int direction, int stype, gjk_collision_visitor *allocator);
gjk_cylinder_t *create_cylinder_gjk_geom(float rot, const vec3_t *a2, const vec3_t *trans, float radius, float halfHeight, int stype, gjk_collision_visitor *allocator);
void create_brush_model_gjk_geom_r(cLeafBrushNode_s *node, int *index_base, gjk_collision_visitor *allocator, const int contents_mask);
// void query_brush_model_gjk_geom_visitor::visit(query_brush_model_gjk_geom_visitor *notthis, const cbrush_t *brush);
void create_xmodel_gjk_geom(unsigned int a1, const XModel *model, gjk_collision_visitor *allocator, int bone_index, unsigned int brush_mask, bool b_fallback_to_bounding_box, int contents_for_proxy_collision, phys_mat44 *worldMat);
void create_gjk_dobj_geom(DObj *obj, const cpose_t *pose, gentity_t *gent, const bool calc_bone_mats, unsigned int brush_mask, bool b_fallback_to_bounding_box, const int contents_for_proxy_collision, gjk_collision_visitor *allocator);
void collision_add_persistent_box(gjk_base_t *a1, vec3_t *axis, vec3_t *position, vec3_t *dims);
// void gjk_aabb_t::destroy(gjk_aabb_t *geom);
// void gjk_obb_t::destroy(gjk_obb_t *geom);
// void gjk_brush_t::destroy(gjk_brush_t *geom);
// void gjk_partition_t::destroy(gjk_partition_t *geom);
// void gjk_double_sphere_t::destroy(gjk_double_sphere_t *geom);
// void gjk_cylinder_t::destroy(gjk_cylinder_t *geom);
// void gjk_polygon_cylinder_t::destroy(gjk_polygon_cylinder_t *geom);
void query_brush_model_gjk_geom(int a1, int a2, int brushModel, unsigned __int16 contents_mask, const int allocator, gjk_collision_visitor *a6);
void create_brush_model_gjk_geom(int a1, unsigned __int16 brushModel, const int contents_mask, gjk_collision_visitor *allocator);
void create_gjk_geom(LocalClientNum_t localClientNum, const centity_t *cent, gjk_collision_visitor *allocator, const bool calc_bone_mats, unsigned int brush_mask, const cpose_t *b_fallback_to_bounding_box, bool b_use_smallerbox_for_characters);
void create_gjk_geom(gentity_t *gent, gjk_collision_visitor *allocator, const bool calc_bone_mats, unsigned int brush_mask, const cpose_t *b_fallback_to_bounding_box);
void create_gjk_geom(int a1, const Glass *glass, gjk_collision_visitor *allocator, unsigned int brush_mask);
void create_gjk_geom(const XModel *a1, int a2, const DynEntityDef *dynEntDef, gjk_collision_visitor *allocator, unsigned int brush_mask);
void collision_reset_persistent_code_collision();

//#include "physics/phys_colgeom.h"

//t6/code/src_noserver/physics/phys_collision.cpp
void process_dynent_hits();
void process_destructible_hits();
// unsigned __int8 destructible_ent_aa::has_auto_activated(bdDTLSHeader *notthis);
// void destructible_ent_aa::auto_activate(destructible_ent_aa *notthis, broad_phase_info *bpi_impactor);
void set_bp_standard_query();
void debug_callback();
void set_debug_callback();
user_rigid_body *GetTraceResultsRigidBody(const trace_t *traceResults);
void set_cpi_params(contact_point_info *cpi, phys_collision_pair *pcp);
// void dynamic_ent_aa::auto_activate(dynamic_ent_aa *notthis, broad_phase_info *bpi_impactor);
// void *gjk_physics_collision_visitor::allocate(gjk_physics_collision_visitor *notthis, const int size, const int alignment, const bool no_error);
// void gjk_physics_collision_visitor::get_local_query_aabb(gjk_physics_collision_visitor *notthis, vec3_t *local_query_aabb_min, vec3_t *local_query_aabb_max);
// bool gjk_physics_collision_visitor::query_create_prolog_1(gjk_physics_collision_visitor *notthis, float local_aabb_min, const vec3_t *a3, const vec3_t *local_aabb_max, const void *geom);
phys_mat44 *create_ent_mat(gjk_physics_collision_visitor *collision_visitor);
phys_auto_activate_callback *create_ent_aac(gjk_physics_collision_visitor *collision_visitor);
// void gjk_physics_collision_visitor::query_create_epilog(gjk_physics_collision_visitor *notthis, gjk_base_t *gjk_geom);
void prop_system_collision_process();
void collide_vehicle_wheels(int a1, NitrousVehicle *nveh_in);
void generic_avl_map_destroy_all_recurse(generic_avl_map_node_t *gamn, void (*destroy_func)(void *));
// void generic_avl_map_destroy_all(phys_inplace_avl_tree<unsigned int,generic_avl_map_node_t,generic_avl_map_node_t> *gam, void (*destroy_func)(void *));
// char gjk_physics_collision_visitor::query_create_prolog(gjk_physics_collision_visitor *notthis, const void *geom);
void create_entity_bpi(LONG a1, gjk_physics_collision_visitor *collision_visitor, const int mask);
// void standard_query::query(standard_query *notthis, int a2, const broad_phase_environment_query_input *bpeqi, broad_phase_environement_query_results *bpeqr);
int wheel_collision_worker(int a1);
// generic_avl_map_node_t *generic_avl_map_add(phys_inplace_avl_tree<unsigned int,generic_avl_map_node_t,generic_avl_map_node_t> *gam, void *data, const unsigned int avl_key);
// void *generic_avl_map_destroy(phys_inplace_avl_tree<unsigned int,generic_avl_map_node_t,generic_avl_map_node_t> *gam, const unsigned int avl_key);

//#include "physics/phys_convert.h"

//t6/code/src_noserver/physics/phys_effects.cpp
void Phys_InitSoundAliases();
void Phys_EffectsInit(dvarType_t a1, dvarType_t a2);
void Phys_EffectsProcess();

//t6/code/src_noserver/physics/phys_gjk_collision_detection.cpp
void gjk_collision_epilog(const bool is_server_thread);
// void gjk_query_output::calc_query_aabb(gjk_query_output *notthis, const gjk_query_input *input);
// void gjk_query_output::query_epilog(gjk_query_output *notthis);
// void gjk_physics_collision_visitor::query_create_epilog_1(gjk_physics_collision_visitor *notthis, gjk_base_t *gjk_geom);
// void gjk_query_output::set_local_query_info(gjk_query_output *notthis, const gjk_query_input *input, gjk_entity_info_t *ent_info);
bool query_should_pass_gentity(const gjk_query_input *input, const gentity_t *gent);
char query_should_pass_centity(const gjk_query_input *input, const centity_t *cent);
// void gjk_query_output::accum_query_reset(gjk_query_output *notthis, const phys_vec3 *start_origin);
char query_should_pass_entity(const gjk_query_input *input, gjk_entity_info_t *ent_info);
void adjust_gjk_polygon_cylinder_query_aabb(vec3_t &,vec3_t &);
void get_material_from_brush(const cbrush_t *brush, int *sflags);
void fill_results_type_and_id(const gjk_trace_output_t *gto, trace_t *results);
void fill_results_no_hit(trace_t *results);
bool is_walkable(float gto, const gjk_trace_output_t *a2);
// char *gjk_query_output::allocate(gjk_query_output *notthis, const int size, const int alignment, const bool no_error);
// void gjk_query_output::get_local_query_aabb(gjk_query_output *notthis, vec3_t *local_query_aabb_min, vec3_t *local_query_aabb_max);
// bool gjk_query_output::query_create_prolog_1(gjk_query_output *notthis, const vec3_t *local_aabb_min, const vec3_t *local_aabb_max, const void *geom);
// gjk_geom_info_t *gjk_query_output::create_geom_info(gjk_query_output *notthis, gjk_base_t *cg, gjk_entity_info_t *ent_info, const vec3_t *aabb_min, const vec3_t *aabb_max);
void setup_gjk_capsule(const vec3_t *mins, const vec3_t *maxs, const float radius_adjust, gjk_double_sphere_t *gjk_capsule);
void setup_gjk_cylinder(const vec3_t *mins, const vec3_t *maxs, const float radius_adjust, gjk_cylinder_t *gjk_cylinder);
// bool gjk_aabb_t::is_walkable(gjk_aabb_t *notthis, int a2, const phys_vec3 *hit_point, const phys_vec3 *up);
bool is_walkable(const cbrush_t *brush, const phys_vec3 *hit_point_loc, const phys_vec3 *up_loc);
bool is_walkable(const CollisionPartition *partition, const phys_vec3 *hit_point_loc, const phys_vec3 *up_loc);
void fill_results(const gjk_trace_output_t *gto, const bool is_walkable, trace_t *results);
// void gjk_query_output::query_prolog(gjk_query_output *notthis, const gjk_query_input *input);
// void gjk_query_output::query_create_epilog(gjk_query_output *notthis, gjk_base_t *gjk_geom);
// void project(float point, const phys_vec3 *a2, phys_static_array<geom_plane,128> *list_geom_plane, phys_vec3 *result);
// void gjk_query_output::reset_cache(gjk_query_output *notthis);
// bool gjk_query_output::query_create_prolog(gjk_query_output *notthis, const void *geom);
// void gjk_query_output::add(gjk_query_output *notthis, const gjk_query_input *input, gentity_t *gent);
// void gjk_query_output::add(gjk_query_output *notthis, const gjk_query_input *input, centity_t *cent);
// void gjk_query_output::add(gjk_query_output *notthis, const gjk_query_input *input, const Glass *glass);
// void gjk_query_output::add(gjk_query_output *notthis, const gjk_query_input *input, const DynEntityDef *dent);
void gjk_query_prims(const gjk_query_input *input, gjk_query_output *output);
void gjk_query_terrain(int a1, const gjk_query_input *input, gjk_query_output *output);
void gjk_query_gents(const gjk_query_input *input, gjk_query_output *output);
void gjk_query_cents(const gjk_query_input *input, gjk_query_output *output);
void gjk_query_glass(const gjk_query_input *input, gjk_query_output *output);
void gjk_query_dents(const gjk_query_input *input, gjk_query_output *output);
// void gjk_query(const gjk_query_input *a1, colgeom_visitor_inlined_t<300> *a2, const gjk_query_input *input, gjk_query_output *output);
// void gjk_query_output::cached_query_resize(gjk_query_output *notthis, int a2, const bool is_server_thread, colgeom_visitor_inlined_t<300> *proximity_data, const int proximity_mask);
// void gjk_query_output::cached_query_prolog(gjk_query_output *notthis, const bool is_server_thread, colgeom_visitor_inlined_t<300> *proximity_data, const int proximity_mask, const phys_vec3 *start_origin);
// void gjk_query_output::cached_query_epilog(gjk_query_output *notthis);
void gjk_query_cached(int a1, const gjk_query_input *input, gjk_query_output *output);

//#include "physics/phys_gjk_collision_detection.h"

//t6/code/src_noserver/physics/phys_main.cpp
void Phys_EnterPhysicsCriticalSection();
void Phys_LeavePhysicsCriticalSection();
void PhysPrint(const char *fmt, ...);
void Phys_ObjGetPosition(int id, phys_mat44 *m2w);
void Phys_ObjGetVelocities(int id, vec3_t *tvel, vec3_t *avel);
void Phys_ObjAddCollFlags(int physObjId, int collFlags);
void Phys_ObjRemoveCollFlags(int physObjId, int collFlags);
void Phys_RenderBulletMeshInfo(vec3_t *pos, int entnum, const XModel *model, const char *type, int numTriangles, float avgArea);
void Phys_ComputeStringPosition(const vec3_t *start, const vec3_t *end, vec3_t *position);
int sort_scored_spawn_point_vectors_ascending(const void *a, const void *b);
void Phys_FindAndRenderEntityBounds(const vec3_t *pos);
void Phys_DumpCollisionTree();
void Phys_RenderHeliMesh(int a1, cmodel_t **a2);
// void colgeom_debug_renderer_t::update(colgeom_debug_renderer_t *notthis, const vec3_t *_mn, const vec3_t *_mx, int mask, const vec3_t *expand_vec);
char Phys_DebugRenderChanged();
int Phys_GetMaskFromDVar();
int SortModelsFunc(const void *a, const void *b);
char Phys_ShouldCollideCallback(const broad_phase_base *bpi1, const broad_phase_base *bpi2);
int Phys_ObjIsDangerous(int id);
int Phys_ObjIsExpensive(int id);
void Phys_SetHingeParams(int id, float motorSpeed, float damp);
rigid_body_constraint_ragdoll *Phys_CreateHinge(int a1, int obj1, int obj2, const vec3_t *anchor, const vec3_t *axis, float motorSpeed, float damp, float lowStop, float highStop);
void Phys_CalcPreset(PhysPreset *physPreset, vec3_t *dims, int surfaceType);
int Phys_GetCurrentTime();
void Phys_ObjSetPosition(int id, const vec3_t *newPosition);
void Phys_ObjSetOrientation(int id, const vec3_t *newPosition, const vec4_t *newOrientation);
void Phys_ObjSetAngularVelocity(int a1, int id, const vec3_t *angularVel);
void Phys_ObjSetVelocity(int a1, int id, const vec3_t *velocity);
void Phys_ObjSetAngularVelocityRaw(int a1, int id, const vec3_t *angularVel);
void Phys_ObjGetPosition(int id, vec3_t *outPosition, vec3_t *outRotation);
void Phys_ObjGetCenterOfMass(int id, vec3_t *outPosition);
void Phys_ObjSetGravity(int id, const vec3_t *gravity);
void Phys_AddCacheImpulses(int a1);
void Phys_ObjAddForce(float id, int a2, const vec3_t *worldPos, const vec3_t *impulse, const bool relative);
void Phys_ObjAddTorque(float id, int a2, const vec3_t *torque);
void Phys_ObjBulletImpact(unsigned int a1, int id, const vec3_t *worldPosRaw, const vec3_t *bulletDirRaw, float bulletSpeed, float scale);
void Phys_BodyGrabSnapshotNitrous(PhysObjUserData *userData, float deltaT);
int Phys_ObjGetSnapshot(int id, vec3_t *outPos, vec3_t *outMat);
void free_chull_lists();
void print_static_models_stats();
void draw_static_models_bounds();
int buoyancy_worker();
void Phys_ObjGetInterpolatedState(int id, vec3_t *outPos, vec4_t *outQuat);
void Phys_SetUserBody(float id, int a2, vec3_t *position);
BOOL Phys_ObjIsAsleep(clientDebugLineInfo_t *a1, int id);
BOOL Phys_ObjIsAsleepSingle(clientDebugLineInfo_t *a1, int id);
void Phys_SetAngularMotorParams(int id, const vec3_t *motorSpeeds, const vec3_t *damp);
rigid_body_constraint_ragdoll *Phys_CreateSwivel(int a1, int obj1, int obj2, const vec3_t *anchor, int numAxes, const vec3_t *axes, const vec3_t *motorSpeeds, const vec3_t *motorFMaxs, const vec3_t *lowStops, const vec3_t *highStops);
void Phys_ObjAddCustomForce(unsigned int a1, int physObjId, const vec3_t *hitPos, const vec3_t *hitDir, const int mod, PhysPreset *physPreset);
void Phys_FindAndRenderBulletMesh(unsigned int a1, const vec3_t *start, const vec3_t *end, int contentmask);
chull_t *create_chull(phys_convex_hull *pch);
chull_t *generate_brush_chull(const cbrush_t *brush);
chull_t *generate_partition_chull(const CollisionAabbTree *tree);
void generate_brushmodel_chull_r(cLeafBrushNode_s *node, chull_t **hull);
chull_t *generate_collmap_chull(PhysGeomList *geomList);
chull_t *get_collmap_chull(PhysGeomList *geomList, unsigned int key);
chull_t *get_brushmodel_chull(cmodel_t **m_avl_key, int brushmodel, unsigned int key);
chull_t *get_brush_chull(const cbrush_t *brush);
chull_t *get_partition_chull(const CollisionAabbTree *tree);
void Phys_FindAndRenderEntityBrushes(int a1, const vec3_t *pos, int contentmask);
// void colgeom_debug_renderer_t::visit(colgeom_debug_renderer_t *notthis, const CollisionAabbTree *tree);
// void colgeom_debug_renderer_t::visit(colgeom_debug_renderer_t *notthis, const cbrush_t *brush);
void Phys_RenderWorldCollMesh(unsigned int a1, const vec3_t *pos, bool bRenderStaticCollision, bool bRenderBrushes);
void debug_loop(int a1);
void UpdateRigidBody(unsigned int a1, float delta_t);
void Phys_CollisionCallback();
void Phys_RunToTime(int timeNow);
void Phys_Init();
void Phys_DestroyUserData(PhysObjUserData *userData);
PhysObjUserData *Phys_CreateUserBody(int a1, vec3_t *position, const int id, PhysicsGeomType geomType);
rigid_body **Phys_CreateBodyFromState(unsigned int a1, const BodyState *state, gjk_geom_list_t *gjk_geom_list);
int Phys_ObjCreateAxis(const vec3_t *position, const vec3_t *axis, const vec3_t *velocity, const PhysPreset *physPreset, gjk_geom_list_t *gjk_geom_list, int id, const bool do_collision_test, int owner, PhysicsOwnerType owner_type);
int Phys_ObjCreate(const vec3_t *position, const vec4_t *quat, const vec3_t *velocity, const PhysPreset *physPreset, gjk_geom_list_t *gjk_geom_list, const vec3_t *do_collision_test, int id, int owner, PhysicsOwnerType owner_type);
void Phys_ObjDestroy(int id);
void PhysicsSystem_Update();

//t6/code/src_noserver/physics/phys_render.cpp
void DebugPatchesAndBrushesProlog();
void DebugPatchesAndBrushesEpilog();
// __int16 debug_brush_info_t::find_index_in_brush(debug_brush_info_t *notthis, const cbrush_t *brush, const vec3_t *v);
// unsigned int debug_patch_info_t::find_index_in_clipmap(debug_patch_info_t *notthis, const CollisionAabbTree *tree, const vec3_t *v);
void clear_debug_brushes_and_patches();
void SeedColor(const void *ptr, const vec4_t *baseColor, float scale, vec4_t *color);
void render_debug_brushes();
void render_debug_patches_full();
void render_debug_brushes_and_patches();
void calc_color(const void *id, const float alpha, vec4_t *color);
void render_tree(const CollisionAabbTree *tree, vec3_t *_trans);
void render_collision_tree(const CollisionAabbTree *tree, const vec4_t *color);
// void debug_patch_info_t::add_patch(debug_patch_info_t *notthis, const CollisionAabbTree *tree);
void add_debug_patch(const CollisionAabbTree *tree);
void render_brush(unsigned int a1, const cbrush_t *brush, const phys_mat44 *xform, const vec4_t *color, bool bLinesOnly, const vec3_t *lightPos, bool persistent, bool ztest, const vec4_t *edgeColor);
void render_convex_partition(const CollisionAabbTree *tree);
void render_chull(unsigned int a1, const chull_t *first, const phys_mat44 *xform, const vec4_t *color);
void render_xmodel_chull(const XModel *model, const unsigned int key, const phys_mat44 *xform, const vec4_t *color);
void render_brushmodel_chull(cmodel_t **a1, int brushmodel, unsigned int key, const phys_mat44 *xform, const vec4_t *color);
void render_line(clientDebugLineInfo_t *a1, const phys_vec3 *p0, const phys_vec3 *p1, const vec4_t *color, int duration, int ztest);
void render_box(int a1, const phys_vec3 *mins, const phys_vec3 *maxs, const phys_mat44 *xform, const vec4_t *color, int duration);
void render_box(float _mn, const vec3_t *a2, const vec3_t *_mx, const vec4_t *color, int duration);
void render_box(const phys_vec3 *mins, const phys_vec3 *maxs, const vec4_t *color);
void render_gjk_geom(int a1, int a2, int geom, gjk_base_t *cg2w, const phys_mat44 *a5);
// void init_winding(float plane, const plane_lt *a2, phys_static_array<phys_vec3,512> *winding);
void Phys_DebugPoint(clientDebugLineInfo_t *a1, const phys_vec3 *pos, const float radius, const vec4_t *color);
void Phys_DebugBox(const phys_mat44 *mat, const vec4_t *color, float scale);
void Phys_DebugBox(const phys_mat44 *mat, const phys_vec3 *dims, const vec4_t *color);
void Phys_RenderBase(int a1, clientDebugLineInfo_t *a2, const phys_mat44 *mat, const float scale);
void Phys_JointDebugRender(int a1, int id);
void render_prims(col_prim_t *prims, int nprims);
// void GjkTraceGeom::Render(unsigned int a1);
void render_debug_draw_gjk_trace_geom(unsigned int a1);
// void clip_winding(int a1, phys_static_array<phys_vec3,512> *winding, const plane_lt *clip);
// void calc_winding(int a1, const phys_static_array<plane_lt,512> *planes, int plane_index, phys_static_array<phys_vec3,512> *winding);
void render_contact(int a1, rigid_body_constraint_contact *rbc);
// void debug_brush_info_t::add_brush(debug_brush_info_t *notthis, int a2, const cbrush_t *brush, const phys_mat44 *mat);
void add_debug_brush(const cbrush_t *brush, const phys_mat44 *mat);

//t6/code/src_noserver/physics/phys_traverse.cpp
// void colgeom_visitor_t::intersect_box_brushnode(colgeom_visitor_t *notthis, cLeafBrushNode_s *node);
// void colgeom_visitor_t::intersect_box_partitions_r(colgeom_visitor_t *notthis, CollisionAabbTree *aabbTree);
// void static_colgeom_visitor_t::visit(static_colgeom_visitor_t *notthis, const CollisionAabbTree *tree);
// void static_colgeom_visitor_t::visit(static_colgeom_visitor_t *notthis, const cbrush_t *brush);
// void colgeom_visitor_t::intersect_box_brushes(colgeom_visitor_t *notthis, cLeaf_s *leaf);
// void colgeom_visitor_t::intersect_box_partitions(colgeom_visitor_t *notthis, cLeaf_s *leaf);
// void colgeom_visitor_t::intersect_box(colgeom_visitor_t *notthis, const vec3_t *mn, const vec3_t *mx, int mask);
// void static_colgeom_visitor_t::update(static_colgeom_visitor_t *notthis, const vec3_t *_mn, const vec3_t *_mx, int mask, const vec3_t *expand_vec);

//#include "physics/phys_visitor.h"

//#include "physics/proftimers.h"

//t6/code/src_noserver/physics/rope.cpp
BOOL Rope_IsValid(int rope_index);
void Rope_Activate(int rope_index);
void Rope_SetFlag(int rope_index, int flags, int onoff);
void Rope_Reset(int rope_index);
void Rope_Reset();
void Rope_SetMaterial(int rope_index, Material *const material);
int Rope_GetNumParticles(int rope_index);
void Rope_AddParticle(int rope_index, const vec3_t *pos);
void Rope_Init(int rope_index, int npars, const vec3_t *p0, const vec3_t *p1, float rope_len, float rope_width, float scale, float force_scale, int static_rope);
void Rope_AddAnchor(int rope_index, int particle_index, const vec3_t *p, int entity_index, int bone_name_hash, rope_constraint_e type);
void Rope_AddDynEntAnchor(int rope_index, int particle_index, const vec3_t *p, int entity_index);
void Rope_AddEntAnchor(int rope_index, int particle_index, const vec3_t *p, int entity_index, int bone_name_hash);
void Rope_RemoveAnchor(int rope_index, int particle_index);
void Rope_ApplyPhysics(int rope_index, float dt);
void Rope_ApplyContactConstraint(int rope_index, int contact_index);
void Rope_ApplyConstraint(int rope_index, int constraint_index);
void Rope_ApplyConstraints(int a1, int rope_index, bool forward);
void Rope_UpdateVisible(int rope_index);
void Rope_DebugDraw(int rope_index);
void Rope_GetPosition(int rope_index, float frac, vec3_t *pos);
void Rope_BuildCurve(const RopeUpdateCmdData *cmd, int rope_index);
void Rope_Draw(int rope_index, LocalClientNum_t localClientNum);
void __cdecl Rope_Create(int rope_index, const vec3_t *start, const vec3_t *end, const float length, const float scale, const float width, const float force_scale, int static_rope);
void Rope_Render(LocalClientNum_t localClientNum);
void Rope_ExplosionEvent(const vec3_t *origin, float innerRadius, float outerRadius, int innerDamage, int outerDamage);
void Rope_Trace(const vec3_t *p0, const vec3_t *p1);
void Rope_CollideEntitiesHelper(int rope_index, const vec3_t *origin);
void Rope_CollideEntities(int rope_index);
void Rope_CollideWorld(unsigned int a1, int rope_index);
void Rope_UpdateInternal(const char *a1, const RopeUpdateCmdData *cmd);
void Rope_Update(unsigned int a1, LocalClientNum_t localClientNum, int curtime);
void Rope_Settle(const char *a1, int rope_index);

//t6/code/src_noserver/physics/rope_gamestate.cpp
void Rope_WriteGameState(msg_t *msg);
void Rope_ReadGameState(msg_t *msg, LocalClientNum_t localClientNum);

//t6/code/src_noserver/physics/xdoll.cpp
int XDoll_GetUnusedBody();
void XDoll_SnapshotBonePositions(XDollBody *body, XDollBoneOrientation *boneSnapshot);
void XDoll_DestroyConstraint(XDoll_ConstraintInfo *cinfo);
rigid_body_constraint_hinge *XDoll_CreateHingeConstraint(rigid_body *rb1, rigid_body *rb2);
rigid_body_constraint_point *XDoll_CreatePointConstraint(rigid_body *rb1, rigid_body *rb2);
rigid_body_constraint_angular_actuator *XDoll_CreateActuatorConstraint(rigid_body *rb1);
bool XDoll_Activate(const PhysConstraints *constraintsDef, int health);
void XDoll_SetCollides(XDollBone *bone, bool collides);
void XDoll_SetCollides(XDollBody *body, bool collides);
void XDoll_UpdateTimers(XDollBody *body, int msec);
void XDoll_UpdateStability(XDollBody *body, int msec);
rigid_body *XDoll_GetRigidBody(XDollBody *body, const char *bone_name);
void XDoll_DestroyXDoll(XDollBody *body);
XDollBody *XDoll_HandleBody(int xdollHandle);
void XDoll_DoControllers(int xdoll_handle, int *partBits, LocalClientNum_t localClientNum);
void XDoll_SetCollides(int xdoll_handle, bool collides);
bool XDoll_CreatePhysObj(XDollBody *body, XDollBone *bone, XModel *model, const cpose_t *pose, PhysPreset *physPreset, bool collide);
void XDoll_Update(int msec);
void XDoll_CreateConstraint(const PhysConstraint *constraint);
void XDoll_DestroyXDoll(int xdoll_handle);
int XDoll_CreateXDollForBoneLaunch(LocalClientNum_t localClientNum, int entity_index, int piece_index, int bone_name, PhysPreset *physPreset);
int XDoll_CreateXDollForConstraints(LocalClientNum_t localClientNum, int entity_index, int piece_index, int health, PhysConstraints *constraints, PhysPreset *physPreset);
void XDoll_UpdateHealth(int xdoll_handle, int health);
void __cdecl XDoll_ApplyForce(int xdoll_handle, const vec3_t *hitp, const vec3_t *hitd, const int mod);

