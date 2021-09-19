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
void Phys_RenderBulletMeshInfo(
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
/*void __thiscall colgeom_debug_renderer_t::update(
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
/*rigid_body_constraint_ragdoll *Phys_CreateHinge@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

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
void Phys_ObjSetAngularVelocity(int id, const vec3_t *angularVel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjSetVelocity
==============
*/
void Phys_ObjSetVelocity(int id, const vec3_t *velocity)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjSetAngularVelocityRaw
==============
*/
void Phys_ObjSetAngularVelocityRaw(int id, const vec3_t *angularVel)
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
/*void Phys_AddCacheImpulses(int a1@<ebp>)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Phys_ObjAddForce
==============
*/
void Phys_ObjAddForce(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjAddTorque
==============
*/
void Phys_ObjAddTorque(int id, const vec3_t *torque)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjBulletImpact
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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
void Phys_SetUserBody(int id, vec3_t *position)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_ObjIsAsleep
==============
*/
/*BOOL Phys_ObjIsAsleep@<eax>(clientDebugLineInfo_t *a1@<edi>, int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
Phys_ObjIsAsleepSingle
==============
*/
/*BOOL Phys_ObjIsAsleepSingle@<eax>(clientDebugLineInfo_t *a1@<edi>, int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

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
/*rigid_body_constraint_ragdoll *Phys_CreateSwivel@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
Phys_ObjAddCustomForce
==============
*/
void Phys_ObjAddCustomForce(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_FindAndRenderBulletMesh
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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
/*chull_t *get_brushmodel_chull@<eax>(cmodel_t **a1@<edx>, int brushmodel, unsigned int key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

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
void Phys_FindAndRenderEntityBrushes(const vec3_t *pos, int contentmask)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
colgeom_debug_renderer_t::visit
==============
*/
/*void __thiscall colgeom_debug_renderer_t::visit(colgeom_debug_renderer_t *this, const CollisionAabbTree *tree)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
colgeom_debug_renderer_t::visit
==============
*/
/*void __thiscall colgeom_debug_renderer_t::visit(colgeom_debug_renderer_t *this, const cbrush_t *brush)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Phys_RenderWorldCollMesh
==============
*/
void Phys_RenderWorldCollMesh(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
debug_loop
==============
*/
/*void debug_loop(int a1@<ebp>)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
UpdateRigidBody
==============
*/
void UpdateRigidBody(float delta_t)
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
/*PhysObjUserData *Phys_CreateUserBody@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
Phys_CreateBodyFromState
==============
*/
/*rigid_body **Phys_CreateBodyFromState@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
Phys_ObjCreateAxis
==============
*/
int Phys_ObjCreateAxis(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Phys_ObjCreate
==============
*/
int Phys_ObjCreate(
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

