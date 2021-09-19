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
char Destructible_GetPieceIndexFromBoneName(;
int GetHealthFromState(;
void DestructibleEventSetPieceState(Destructible *destructible, LerpEntityStateDestructibleHit *state);
void CG_DestructibleClientOnlyCreate(centity_t *ent, DestructibleDef *ddef);
int CG_SpawnPhysObjForBone(;
unsigned int CG_GetTagTransform(;
unsigned int G_GetTagTransform(gentity_t *ent, DestructibleDef *ddef, int pieceIndex, vec3_t *tagMat);
void CG_DestructibleSetBurn(;
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
;
void Destructible_LoadDestructibles(MemoryFile *memFile);
void Destructible_WriteGameState(msg_t *msg);
void Destructible_ReadGameState(msg_t *msg, LocalClientNum_t localClientNum);
void Demo_Destructible_WriteGameState(msg_t *msg, LocalClientNum_t localClientNum);
void Demo_Destructible_ReadGameState(msg_t *msg, LocalClientNum_t localClientNum);
DestructiblePose *CG_GetDestructiblePose(__int16 index);
void CG_DestructibleShake(;
void Destructible_SetDebugRender(Destructible *destructible);
void Destructible_DebugRender();
DestructibleDef *Destructible_GetDDef(const centity_t *cent);
void Scr_DestructibleCallback(gentity_t *self, unsigned __int16 event, int piece, float time, int damage);
void DisableDestructiblePiece(int label);
void CG_DisableDestructiblePiece(LocalClientNum_t localClientNum, int label);
unsigned __int16 DestructibleUpdate(gentity_t *ent, DObjModel_s *dobjModels, unsigned __int16 numModels);
void DestructibleExplosiveDamageEvent(gentity_t *self, const vec3_t *point, const float radius, const int mod);
void DestructibleBulletDamageEvent(gentity_t *self, const vec3_t *point, const vec3_t *dir, const int mod);
// char DamagePiece@<al>(;
double DestructibleRadiusDamage(;
int DestructibleDamage(;
unsigned int CG_DestructibleUpdate(;
;
void CG_DestructibleBreakPiece(;
void CG_RestartDestructibles(LocalClientNum_t localClientNum);
// bool CG_DestructibleDamage@<al>(;
void CG_FreeDestructiblePose(LocalClientNum_t localClientNum, unsigned __int8 destructiblePoseID);
void CG_FreeDestructible(LocalClientNum_t localClientNum, Destructible *destructible);
// char CG_DamagePiece@<al>(;
void CG_DestructibleRadiusDamage(;
void CG_DestructibleHitEvent(;
void CG_DestructibleDamage(;
void CG_ProcessDestructibleEvents();

//#include "physics/destructible.h"

//#include "physics/destructibledef_load_db.h"

//t6/code/src_noserver/physics/destructibledef_load_obj.cpp
void DestructibleDef_Strcpy(unsigned __int8 *member, const char *keyValue);
int DestructiblePiece_ParseDefSpecificFieldType(;
DestructiblePiece *DestructiblePieceLoadFile(const char *name, DestructiblePiece *destructiblePiece);
int Destructible_ParseDefSpecificFieldType(unsigned __int8 *pStruct, const char *pValue, const int iFieldType);
DestructibleDef *DestructibleDefLoadFile(const char *name, void *(*Alloc)(int));

//#include "physics/physconstraints_load_db.h"

//t6/code/src_noserver/physics/physconstraints_load_obj.cpp
void PhysConstraints_Strcpy(unsigned __int8 *member, const char *keyValue);
int CON_ParseSpecificField(unsigned __int8 *pStruct, const char *pValue, const int fieldType);
void PhysConstraintsPostLoadFixup(PhysConstraints *physConstraints);
PhysConstraints *PhysConstraintsLoadFile(const char *name, void *(*Alloc)(int));
PhysConstraints *PhysConstraintsPrecache(const char *name, void *(*Alloc)(int));
void PhysConstraintsUpdateField(;

//#include "physics/physpreset_load_db.h"

//t6/code/src_noserver/physics/physpreset_load_obj.cpp
void PhysPreset_Strcpy(unsigned __int8 *member, const char *keyValue);
PhysPreset *PhysPresetLoadFile(const char *name, void *(*Alloc)(int));
PhysPreset *PhysPresetPrecache(const char *name, void *(*Alloc)(int));
PhysPreset *PhysPreset_Register_FastFile(const char *name);
PhysPreset *PhysPreset_Register_LoadObj(const char *name);
PhysPreset *PhysPreset_Register();

//t6/code/src_noserver/physics/phys_auto_rigid_body.cpp
// user_rigid_body *auto_rigid_body::ent_has_auto_rigid_body(const centity_t *cent);
void fixup_wheel_constraints_arb(auto_rigid_body *arb);
// void auto_rigid_body::add(;
// void auto_rigid_body::update(int a1@<ebp>);
// void auto_rigid_body::remove_ent(const centity_t *cent);

//t6/code/src_noserver/physics/phys_colgeom.cpp
void setup_gjk_polygon_cylinder(;
;
// gjk_aabb_t *gjk_aabb_t::create(;
// gjk_obb_t *gjk_obb_t::create(;
// gjk_aabb_t *gjk_brush_t::create@<eax>(;
// gjk_partition_t *gjk_partition_t::create(const CollisionAabbTree *tree, gjk_collision_visitor *allocator);
// gjk_double_sphere_t *gjk_double_sphere_t::create(;
// gjk_cylinder_t *gjk_cylinder_t::create(;
// gjk_polygon_cylinder_t *gjk_polygon_cylinder_t::create(;
// gjk_aabb_t *create_aabb_gjk_geom@<eax>(;
;
;
// gjk_cylinder_t *create_cylinder_gjk_geom@<eax>(;
void create_brush_model_gjk_geom_r(;
// void __thiscall query_brush_model_gjk_geom_visitor::visit(;
;
void create_gjk_dobj_geom(;
// void collision_add_persistent_box(gjk_base_t *a1@<ebp>, vec3_t *axis, vec3_t *position, vec3_t *dims);
// void gjk_aabb_t::destroy(gjk_aabb_t *geom);
// void gjk_obb_t::destroy(gjk_obb_t *geom);
// void gjk_brush_t::destroy(gjk_brush_t *geom);
// void gjk_partition_t::destroy(gjk_partition_t *geom);
// void gjk_double_sphere_t::destroy(gjk_double_sphere_t *geom);
// void gjk_cylinder_t::destroy(gjk_cylinder_t *geom);
// void gjk_polygon_cylinder_t::destroy(gjk_polygon_cylinder_t *geom);
;
void create_brush_model_gjk_geom(;
void create_gjk_geom(;
void create_gjk_geom(;
void create_gjk_geom(;
void create_gjk_geom(const DynEntityDef *dynEntDef, gjk_collision_visitor *allocator, unsigned int brush_mask);
void collision_reset_persistent_code_collision();

//#include "physics/phys_colgeom.h"

//t6/code/src_noserver/physics/phys_collision.cpp
void process_dynent_hits();
void process_destructible_hits();
// unsigned __int8 __thiscall destructible_ent_aa::has_auto_activated(bdDTLSHeader *this);
// void __thiscall destructible_ent_aa::auto_activate(destructible_ent_aa *this, broad_phase_info *bpi_impactor);
void set_bp_standard_query();
void debug_callback();
void set_debug_callback();
user_rigid_body *GetTraceResultsRigidBody(const trace_t *traceResults);
void set_cpi_params(contact_point_info *cpi, phys_collision_pair *pcp);
// void __thiscall dynamic_ent_aa::auto_activate(dynamic_ent_aa *this, broad_phase_info *bpi_impactor);
// void *__thiscall gjk_physics_collision_visitor::allocate(;
// void __thiscall gjk_physics_collision_visitor::get_local_query_aabb(;
// bool gjk_physics_collision_visitor::query_create_prolog_1@<al>(;
phys_mat44 *create_ent_mat(gjk_physics_collision_visitor *collision_visitor);
phys_auto_activate_callback *create_ent_aac(gjk_physics_collision_visitor *collision_visitor);
// void __thiscall gjk_physics_collision_visitor::query_create_epilog(;
void prop_system_collision_process();
;
void generic_avl_map_destroy_all_recurse(generic_avl_map_node_t *gamn, void (*destroy_func)(void *));
void generic_avl_map_destroy_all(;
// char __thiscall gjk_physics_collision_visitor::query_create_prolog(;
// void create_entity_bpi(LONG a1@<ebp>, gjk_physics_collision_visitor *collision_visitor, const int mask);
// void standard_query::query(;
// int wheel_collision_worker@<eax>(int a1@<ebp>);
generic_avl_map_node_t *generic_avl_map_add(;
void *generic_avl_map_destroy(;

//#include "physics/phys_convert.h"

//t6/code/src_noserver/physics/phys_effects.cpp
void Phys_InitSoundAliases();
void Phys_EffectsInit(int a1, dvarType_t a2);
void Phys_EffectsProcess();

//t6/code/src_noserver/physics/phys_gjk_collision_detection.cpp
void gjk_collision_epilog(const bool is_server_thread);
// void __thiscall gjk_query_output::calc_query_aabb(gjk_query_output *this, const gjk_query_input *input);
// void __thiscall gjk_query_output::query_epilog(gjk_query_output *this);
// void __thiscall gjk_physics_collision_visitor::query_create_epilog_1(;
// void __thiscall gjk_query_output::set_local_query_info(;
bool query_should_pass_gentity(const gjk_query_input *input, const gentity_t *gent);
char query_should_pass_centity(const gjk_query_input *input, const centity_t *cent);
// void __thiscall gjk_query_output::accum_query_reset(gjk_query_output *this, const phys_vec3 *start_origin);
char query_should_pass_entity(const gjk_query_input *input, gjk_entity_info_t *ent_info);
void adjust_gjk_polygon_cylinder_query_aabb(vec3_t &,vec3_t &);
void get_material_from_brush(const cbrush_t *brush, int *sflags);
void fill_results_type_and_id(const gjk_trace_output_t *gto, trace_t *results);
void fill_results_no_hit(trace_t *results);
// bool is_walkable@<al>(const gjk_trace_output_t *gto);
// char *__thiscall gjk_query_output::allocate(;
// void __thiscall gjk_query_output::get_local_query_aabb(;
// bool __thiscall gjk_query_output::query_create_prolog_1(;
// gjk_geom_info_t *__thiscall gjk_query_output::create_geom_info(;
void setup_gjk_capsule(;
void setup_gjk_cylinder(;
// bool gjk_aabb_t::is_walkable@<al>(;
bool is_walkable(const cbrush_t *brush, const phys_vec3 *hit_point_loc, const phys_vec3 *up_loc);
bool is_walkable(const CollisionPartition *partition, const phys_vec3 *hit_point_loc, const phys_vec3 *up_loc);
void fill_results(const gjk_trace_output_t *gto, const bool is_walkable, trace_t *results);
// void __thiscall gjk_query_output::query_prolog(gjk_query_output *this, const gjk_query_input *input);
// void __thiscall gjk_query_output::query_create_epilog(gjk_query_output *this, gjk_base_t *gjk_geom);
;
// void __thiscall gjk_query_output::reset_cache(gjk_query_output *this);
// bool __thiscall gjk_query_output::query_create_prolog(gjk_query_output *this, const void *geom);
// void __thiscall gjk_query_output::add(gjk_query_output *this, const gjk_query_input *input, gentity_t *gent);
// void __thiscall gjk_query_output::add(gjk_query_output *this, const gjk_query_input *input, centity_t *cent);
// void __thiscall gjk_query_output::add(gjk_query_output *this, const gjk_query_input *input, const Glass *glass);
// void __thiscall gjk_query_output::add(gjk_query_output *this, const gjk_query_input *input, const DynEntityDef *dent);
void gjk_query_prims(const gjk_query_input *input, gjk_query_output *output);
void gjk_query_terrain(const gjk_query_input *input, gjk_query_output *output);
void gjk_query_gents(const gjk_query_input *input, gjk_query_output *output);
void gjk_query_cents(const gjk_query_input *input, gjk_query_output *output);
void gjk_query_glass(const gjk_query_input *input, gjk_query_output *output);
void gjk_query_dents(const gjk_query_input *input, gjk_query_output *output);
void gjk_query(const gjk_query_input *input, gjk_query_output *output);
// ;
// void __thiscall gjk_query_output::cached_query_prolog(;
// void __thiscall gjk_query_output::cached_query_epilog(gjk_query_output *this);
void gjk_query_cached(const gjk_query_input *input, gjk_query_output *output);

//#include "physics/phys_gjk_collision_detection.h"

//t6/code/src_noserver/physics/phys_main.cpp
void Phys_EnterPhysicsCriticalSection();
void Phys_LeavePhysicsCriticalSection();
void PhysPrint(const char *fmt, ...);
void Phys_ObjGetPosition(int id, phys_mat44 *m2w);
void Phys_ObjGetVelocities(int id, vec3_t *tvel, vec3_t *avel);
void Phys_ObjAddCollFlags(int physObjId, int collFlags);
void Phys_ObjRemoveCollFlags(int physObjId, int collFlags);
void Phys_RenderBulletMeshInfo(;
void Phys_ComputeStringPosition(const vec3_t *start, const vec3_t *end, vec3_t *position);
int sort_scored_spawn_point_vectors_ascending(const void *a, const void *b);
void Phys_FindAndRenderEntityBounds(const vec3_t *pos);
void Phys_DumpCollisionTree();
void Phys_RenderHeliMesh(int a1, cmodel_t **a2);
// void __thiscall colgeom_debug_renderer_t::update(;
char Phys_DebugRenderChanged();
int Phys_GetMaskFromDVar();
int SortModelsFunc(const void *a, const void *b);
char Phys_ShouldCollideCallback(const broad_phase_base *bpi1, const broad_phase_base *bpi2);
int Phys_ObjIsDangerous(int id);
int Phys_ObjIsExpensive(int id);
void Phys_SetHingeParams(int id, float motorSpeed, float damp);
// rigid_body_constraint_ragdoll *Phys_CreateHinge@<eax>(;
void Phys_CalcPreset(PhysPreset *physPreset, vec3_t *dims, int surfaceType);
int Phys_GetCurrentTime();
void Phys_ObjSetPosition(int id, const vec3_t *newPosition);
void Phys_ObjSetOrientation(int id, const vec3_t *newPosition, const vec4_t *newOrientation);
void Phys_ObjSetAngularVelocity(int id, const vec3_t *angularVel);
void Phys_ObjSetVelocity(int id, const vec3_t *velocity);
void Phys_ObjSetAngularVelocityRaw(int id, const vec3_t *angularVel);
void Phys_ObjGetPosition(int id, vec3_t *outPosition, vec3_t *outRotation);
void Phys_ObjGetCenterOfMass(int id, vec3_t *outPosition);
void Phys_ObjSetGravity(int id, const vec3_t *gravity);
// void Phys_AddCacheImpulses(int a1@<ebp>);
void Phys_ObjAddForce(;
void Phys_ObjAddTorque(int id, const vec3_t *torque);
;
void Phys_BodyGrabSnapshotNitrous(PhysObjUserData *userData, float deltaT);
int Phys_ObjGetSnapshot(int id, vec3_t *outPos, vec3_t *outMat);
void free_chull_lists();
void print_static_models_stats();
void draw_static_models_bounds();
int buoyancy_worker();
void Phys_ObjGetInterpolatedState(int id, vec3_t *outPos, vec4_t *outQuat);
void Phys_SetUserBody(int id, vec3_t *position);
// BOOL Phys_ObjIsAsleep@<eax>(clientDebugLineInfo_t *a1@<edi>, int id);
// BOOL Phys_ObjIsAsleepSingle@<eax>(clientDebugLineInfo_t *a1@<edi>, int id);
void Phys_SetAngularMotorParams(int id, const vec3_t *motorSpeeds, const vec3_t *damp);
// rigid_body_constraint_ragdoll *Phys_CreateSwivel@<eax>(;
void Phys_ObjAddCustomForce(;
;
chull_t *create_chull(phys_convex_hull *pch);
chull_t *generate_brush_chull(const cbrush_t *brush);
chull_t *generate_partition_chull(const CollisionAabbTree *tree);
void generate_brushmodel_chull_r(cLeafBrushNode_s *node, chull_t **hull);
chull_t *generate_collmap_chull(PhysGeomList *geomList);
chull_t *get_collmap_chull(PhysGeomList *geomList, unsigned int key);
// chull_t *get_brushmodel_chull@<eax>(cmodel_t **a1@<edx>, int brushmodel, unsigned int key);
chull_t *get_brush_chull(const cbrush_t *brush);
chull_t *get_partition_chull(const CollisionAabbTree *tree);
void Phys_FindAndRenderEntityBrushes(const vec3_t *pos, int contentmask);
// void __thiscall colgeom_debug_renderer_t::visit(colgeom_debug_renderer_t *this, const CollisionAabbTree *tree);
// void __thiscall colgeom_debug_renderer_t::visit(colgeom_debug_renderer_t *this, const cbrush_t *brush);
void Phys_RenderWorldCollMesh(;
// void debug_loop(int a1@<ebp>);
void UpdateRigidBody(float delta_t);
void Phys_CollisionCallback();
void Phys_RunToTime(int timeNow);
void Phys_Init();
void Phys_DestroyUserData(PhysObjUserData *userData);
// PhysObjUserData *Phys_CreateUserBody@<eax>(;
// rigid_body **Phys_CreateBodyFromState@<eax>(;
int Phys_ObjCreateAxis(;
int Phys_ObjCreate(;
void Phys_ObjDestroy(int id);
void PhysicsSystem_Update();

//t6/code/src_noserver/physics/phys_render.cpp
void DebugPatchesAndBrushesProlog();
void DebugPatchesAndBrushesEpilog();
// __int16 __thiscall debug_brush_info_t::find_index_in_brush(;
// unsigned int __thiscall debug_patch_info_t::find_index_in_clipmap(;
void clear_debug_brushes_and_patches();
void SeedColor(const void *ptr, const vec4_t *baseColor, float scale, vec4_t *color);
void render_debug_brushes();
void render_debug_patches_full();
void render_debug_brushes_and_patches();
void calc_color(const void *id, const float alpha, vec4_t *color);
void render_tree(const CollisionAabbTree *tree, vec3_t *_trans);
void render_collision_tree(const CollisionAabbTree *tree, const vec4_t *color);
// void __thiscall debug_patch_info_t::add_patch(debug_patch_info_t *this, const CollisionAabbTree *tree);
void add_debug_patch(const CollisionAabbTree *tree);
;
void render_convex_partition(const CollisionAabbTree *tree);
;
void render_xmodel_chull(;
void render_brushmodel_chull(;
void render_line(;
void render_box(;
void render_box(const vec3_t *_mn, const vec3_t *_mx, const vec4_t *color, int duration);
void render_box(const phys_vec3 *mins, const phys_vec3 *maxs, const vec4_t *color, int duration);
;
;
void Phys_DebugPoint(;
void Phys_DebugBox(const phys_mat44 *mat, const vec4_t *color, float scale);
void Phys_DebugBox(const phys_mat44 *mat, const phys_vec3 *dims, const vec4_t *color);
;
void Phys_JointDebugRender(int id);
void render_prims(col_prim_t *prims, int nprims);
// void GjkTraceGeom::Render(unsigned int a1@<ebp>);
;
// void clip_winding(phys_static_array<phys_vec3,512> *winding, const plane_lt *clip);
;
;
// void debug_brush_info_t::add_brush(;
void add_debug_brush(const cbrush_t *brush, const phys_mat44 *mat);

//t6/code/src_noserver/physics/phys_traverse.cpp
// void __thiscall colgeom_visitor_t::intersect_box_brushnode(colgeom_visitor_t *this, cLeafBrushNode_s *node);
// void __thiscall colgeom_visitor_t::intersect_box_partitions_r(colgeom_visitor_t *this, CollisionAabbTree *aabbTree);
// void __thiscall static_colgeom_visitor_t::visit(static_colgeom_visitor_t *this, const CollisionAabbTree *tree);
// void __thiscall static_colgeom_visitor_t::visit(static_colgeom_visitor_t *this, const cbrush_t *brush);
// void __thiscall colgeom_visitor_t::intersect_box_brushes(colgeom_visitor_t *this, cLeaf_s *leaf);
// void __thiscall colgeom_visitor_t::intersect_box_partitions(colgeom_visitor_t *this, cLeaf_s *leaf);
// void __thiscall colgeom_visitor_t::intersect_box(colgeom_visitor_t *this, const vec3_t *mn, const vec3_t *mx, int mask);
// void __thiscall static_colgeom_visitor_t::update(;

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
void Rope_Init(;
void Rope_AddAnchor(;
void Rope_AddDynEntAnchor(int rope_index, int particle_index, const vec3_t *p, int entity_index);
void Rope_AddEntAnchor(;
void Rope_RemoveAnchor(int rope_index, int particle_index);
void Rope_ApplyPhysics(int rope_index, float dt);
void Rope_ApplyContactConstraint(int rope_index, int contact_index);
void Rope_ApplyConstraint(int rope_index, int constraint_index);
// void Rope_ApplyConstraints(int a1@<edx>, int rope_index, bool forward);
void Rope_UpdateVisible(int rope_index);
void Rope_DebugDraw(int rope_index);
void Rope_GetPosition(int rope_index, float frac, vec3_t *pos);
void Rope_BuildCurve(const RopeUpdateCmdData *cmd, int rope_index);
void Rope_Draw(int rope_index, LocalClientNum_t localClientNum);
void Rope_Create(;
void Rope_Render(LocalClientNum_t localClientNum);
void Rope_ExplosionEvent(;
void Rope_Trace(const vec3_t *p0, const vec3_t *p1);
void Rope_CollideEntitiesHelper(int rope_index, const vec3_t *origin);
void Rope_CollideEntities(int rope_index);
;
void Rope_UpdateInternal(const RopeUpdateCmdData *cmd);
void Rope_Update(LocalClientNum_t localClientNum, int curtime);
void Rope_Settle(int rope_index);

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
bool XDoll_CreatePhysObj(;
void XDoll_Update(int msec);
void XDoll_CreateConstraint(const PhysConstraint *constraint);
void XDoll_DestroyXDoll(int xdoll_handle);
int XDoll_CreateXDollForBoneLaunch(;
int XDoll_CreateXDollForConstraints(;
void XDoll_UpdateHealth(int xdoll_handle, int health);
void XDoll_ApplyForce(int xdoll_handle, const vec3_t *hitp, const vec3_t *hitd, const int mod);

