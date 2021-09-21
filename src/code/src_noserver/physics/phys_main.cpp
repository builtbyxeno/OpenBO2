#include "types.h"
#include "functions.h"

/*
==============
Phys_EnterPhysicsCriticalSection
==============
*/
void Phys_EnterPhysicsCriticalSection()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_LeavePhysicsCriticalSection
==============
*/
void Phys_LeavePhysicsCriticalSection()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PhysPrint
==============
*/
void PhysPrint(const char *fmt, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjGetPosition
==============
*/
void Phys_ObjGetPosition(int id, phys_mat44 *m2w)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjGetVelocities
==============
*/
void Phys_ObjGetVelocities(int id, vec3_t *tvel, vec3_t *avel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjAddCollFlags
==============
*/
void Phys_ObjAddCollFlags(int physObjId, int collFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjRemoveCollFlags
==============
*/
void Phys_ObjRemoveCollFlags(int physObjId, int collFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_RenderBulletMeshInfo
==============
*/
void Phys_RenderBulletMeshInfo(vec3_t *pos, int entnum, const XModel *model, const char *type, int numTriangles, float avgArea)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ComputeStringPosition
==============
*/
void Phys_ComputeStringPosition(const vec3_t *start, const vec3_t *end, vec3_t *position)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
sort_scored_spawn_point_vectors_ascending
==============
*/
int sort_scored_spawn_point_vectors_ascending(const void *a, const void *b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Phys_FindAndRenderEntityBounds
==============
*/
void Phys_FindAndRenderEntityBounds(const vec3_t *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_DumpCollisionTree
==============
*/
void Phys_DumpCollisionTree()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_RenderHeliMesh
==============
*/
void Phys_RenderHeliMesh(int a1, cmodel_t **a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
colgeom_debug_renderer_t::update
==============
*/
/*void colgeom_debug_renderer_t::update(colgeom_debug_renderer_t *notthis, const vec3_t *_mn, const vec3_t *_mx, int mask, const vec3_t *expand_vec)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Phys_DebugRenderChanged
==============
*/
char Phys_DebugRenderChanged()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Phys_GetMaskFromDVar
==============
*/
int Phys_GetMaskFromDVar()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SortModelsFunc
==============
*/
int SortModelsFunc(const void *a, const void *b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Phys_ShouldCollideCallback
==============
*/
char Phys_ShouldCollideCallback(const broad_phase_base *bpi1, const broad_phase_base *bpi2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Phys_ObjIsDangerous
==============
*/
int Phys_ObjIsDangerous(int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Phys_ObjIsExpensive
==============
*/
int Phys_ObjIsExpensive(int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Phys_SetHingeParams
==============
*/
void Phys_SetHingeParams(int id, float motorSpeed, float damp)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_CreateHinge
==============
*/
rigid_body_constraint_ragdoll *Phys_CreateHinge(int a1, int obj1, int obj2, const vec3_t *anchor, const vec3_t *axis, float motorSpeed, float damp, float lowStop, float highStop)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Phys_CalcPreset
==============
*/
void Phys_CalcPreset(PhysPreset *physPreset, vec3_t *dims, int surfaceType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_GetCurrentTime
==============
*/
int Phys_GetCurrentTime()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Phys_ObjSetPosition
==============
*/
void Phys_ObjSetPosition(int id, const vec3_t *newPosition)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjSetOrientation
==============
*/
void Phys_ObjSetOrientation(int id, const vec3_t *newPosition, const vec4_t *newOrientation)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjSetAngularVelocity
==============
*/
void Phys_ObjSetAngularVelocity(int a1, int id, const vec3_t *angularVel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjSetVelocity
==============
*/
void Phys_ObjSetVelocity(int a1, int id, const vec3_t *velocity)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjSetAngularVelocityRaw
==============
*/
void Phys_ObjSetAngularVelocityRaw(int a1, int id, const vec3_t *angularVel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjGetPosition
==============
*/
void Phys_ObjGetPosition(int id, vec3_t *outPosition, vec3_t *outRotation)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjGetCenterOfMass
==============
*/
void Phys_ObjGetCenterOfMass(int id, vec3_t *outPosition)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjSetGravity
==============
*/
void Phys_ObjSetGravity(int id, const vec3_t *gravity)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_AddCacheImpulses
==============
*/
void Phys_AddCacheImpulses(int a1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjAddForce
==============
*/
void Phys_ObjAddForce(float id, int a2, const vec3_t *worldPos, const vec3_t *impulse, const bool relative)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjAddTorque
==============
*/
void Phys_ObjAddTorque(float id, int a2, const vec3_t *torque)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjBulletImpact
==============
*/
void Phys_ObjBulletImpact(unsigned int a1, int id, const vec3_t *worldPosRaw, const vec3_t *bulletDirRaw, float bulletSpeed, float scale)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_BodyGrabSnapshotNitrous
==============
*/
void Phys_BodyGrabSnapshotNitrous(PhysObjUserData *userData, float deltaT)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjGetSnapshot
==============
*/
int Phys_ObjGetSnapshot(int id, vec3_t *outPos, vec3_t *outMat)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
free_chull_lists
==============
*/
void free_chull_lists()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
print_static_models_stats
==============
*/
void print_static_models_stats()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
draw_static_models_bounds
==============
*/
void draw_static_models_bounds()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
buoyancy_worker
==============
*/
int buoyancy_worker()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Phys_ObjGetInterpolatedState
==============
*/
void Phys_ObjGetInterpolatedState(int id, vec3_t *outPos, vec4_t *outQuat)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_SetUserBody
==============
*/
void Phys_SetUserBody(float id, int a2, vec3_t *position)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjIsAsleep
==============
*/
BOOL Phys_ObjIsAsleep(clientDebugLineInfo_t *a1, int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Phys_ObjIsAsleepSingle
==============
*/
BOOL Phys_ObjIsAsleepSingle(clientDebugLineInfo_t *a1, int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Phys_SetAngularMotorParams
==============
*/
void Phys_SetAngularMotorParams(int id, const vec3_t *motorSpeeds, const vec3_t *damp)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_CreateSwivel
==============
*/
rigid_body_constraint_ragdoll *Phys_CreateSwivel(int a1, int obj1, int obj2, const vec3_t *anchor, int numAxes, const vec3_t *axes, const vec3_t *motorSpeeds, const vec3_t *motorFMaxs, const vec3_t *lowStops, const vec3_t *highStops)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Phys_ObjAddCustomForce
==============
*/
void Phys_ObjAddCustomForce(unsigned int a1, int physObjId, const vec3_t *hitPos, const vec3_t *hitDir, const int mod, PhysPreset *physPreset)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_FindAndRenderBulletMesh
==============
*/
void Phys_FindAndRenderBulletMesh(unsigned int a1, const vec3_t *start, const vec3_t *end, int contentmask)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
create_chull
==============
*/
chull_t *create_chull(phys_convex_hull *pch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
generate_brush_chull
==============
*/
chull_t *generate_brush_chull(const cbrush_t *brush)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
generate_partition_chull
==============
*/
chull_t *generate_partition_chull(const CollisionAabbTree *tree)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
generate_brushmodel_chull_r
==============
*/
void generate_brushmodel_chull_r(cLeafBrushNode_s *node, chull_t **hull)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
generate_collmap_chull
==============
*/
chull_t *generate_collmap_chull(PhysGeomList *geomList)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
get_collmap_chull
==============
*/
chull_t *get_collmap_chull(PhysGeomList *geomList, unsigned int key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
get_brushmodel_chull
==============
*/
chull_t *get_brushmodel_chull(cmodel_t **m_avl_key, int brushmodel, unsigned int key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
get_brush_chull
==============
*/
chull_t *get_brush_chull(const cbrush_t *brush)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
get_partition_chull
==============
*/
chull_t *get_partition_chull(const CollisionAabbTree *tree)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Phys_FindAndRenderEntityBrushes
==============
*/
void Phys_FindAndRenderEntityBrushes(int a1, const vec3_t *pos, int contentmask)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
colgeom_debug_renderer_t::visit
==============
*/
/*void colgeom_debug_renderer_t::visit(colgeom_debug_renderer_t *notthis, const CollisionAabbTree *tree)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
colgeom_debug_renderer_t::visit
==============
*/
/*void colgeom_debug_renderer_t::visit(colgeom_debug_renderer_t *notthis, const cbrush_t *brush)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Phys_RenderWorldCollMesh
==============
*/
void Phys_RenderWorldCollMesh(unsigned int a1, const vec3_t *pos, bool bRenderStaticCollision, bool bRenderBrushes)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
debug_loop
==============
*/
void debug_loop(int a1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UpdateRigidBody
==============
*/
void UpdateRigidBody(unsigned int a1, float delta_t)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_CollisionCallback
==============
*/
void Phys_CollisionCallback()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_RunToTime
==============
*/
void Phys_RunToTime(int timeNow)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_Init
==============
*/
void Phys_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_DestroyUserData
==============
*/
void Phys_DestroyUserData(PhysObjUserData *userData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_CreateUserBody
==============
*/
PhysObjUserData *Phys_CreateUserBody(int a1, vec3_t *position, const int id, PhysicsGeomType geomType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Phys_CreateBodyFromState
==============
*/
rigid_body **Phys_CreateBodyFromState(unsigned int a1, const BodyState *state, gjk_geom_list_t *gjk_geom_list)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Phys_ObjCreateAxis
==============
*/
int Phys_ObjCreateAxis(const vec3_t *position, const vec3_t *axis, const vec3_t *velocity, const PhysPreset *physPreset, gjk_geom_list_t *gjk_geom_list, int id, const bool do_collision_test, int owner, PhysicsOwnerType owner_type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Phys_ObjCreate
==============
*/
int Phys_ObjCreate(const vec3_t *position, const vec4_t *quat, const vec3_t *velocity, const PhysPreset *physPreset, gjk_geom_list_t *gjk_geom_list, const vec3_t *do_collision_test, int id, int owner, PhysicsOwnerType owner_type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Phys_ObjDestroy
==============
*/
void Phys_ObjDestroy(int id)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PhysicsSystem_Update
==============
*/
void PhysicsSystem_Update()
{
	UNIMPLEMENTED(__FUNCTION__);
}

