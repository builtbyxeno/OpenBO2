#include "types.h"
#include "functions.h"

/*
==============
setup_gjk_polygon_cylinder
==============
*/
void setup_gjk_polygon_cylinder(int a1, const vec3_t *mins, const vec3_t *maxs, const float radius_adjust, gjk_polygon_cylinder_t *gjk_cylinder)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
collision_get_area_persistent_code_collision
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
gjk_aabb_t::create
==============
*/
/*gjk_aabb_t *gjk_aabb_t::create(const phys_vec3 *center, const phys_vec3 *dims, int stype, gjk_collision_visitor *allocator)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
gjk_obb_t::create
==============
*/
/*gjk_obb_t *gjk_obb_t::create(const phys_mat44 *xform, const phys_vec3 *dims, int stype, gjk_collision_visitor *allocator)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
gjk_brush_t::create
==============
*/
/*gjk_aabb_t *gjk_brush_t::create(float brush, const cbrush_t *a2, const int stype, gjk_collision_visitor *allocator)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
gjk_partition_t::create
==============
*/
/*gjk_partition_t *gjk_partition_t::create(const CollisionAabbTree *tree, gjk_collision_visitor *allocator)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
gjk_double_sphere_t::create
==============
*/
/*gjk_double_sphere_t *gjk_double_sphere_t::create(const phys_vec3 *c0, const phys_vec3 *c1, const float r, int stype, gjk_collision_visitor *allocator)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
gjk_cylinder_t::create
==============
*/
/*gjk_cylinder_t *gjk_cylinder_t::create(int _direction, float _halfHeight, float _radius, const phys_mat44 *_xform, int stype, gjk_collision_visitor *allocator)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
gjk_polygon_cylinder_t::create
==============
*/
/*gjk_polygon_cylinder_t *gjk_polygon_cylinder_t::create(const vec3_t *mins, const vec3_t *maxs, const float radius_adjust, const int stype, gjk_collision_visitor *allocator)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
create_aabb_gjk_geom
==============
*/
gjk_aabb_t *create_aabb_gjk_geom(int a1, const vec3_t *mn, const vec3_t *mx, int stype, gjk_collision_visitor *allocator)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
create_brush_gjk_geom
==============
*/
void create_brush_gjk_geom()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
create_capsule_gjk_geom
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
create_cylinder_gjk_geom
==============
*/
gjk_cylinder_t *create_cylinder_gjk_geom(float rot, const vec3_t *a2, const vec3_t *trans, float radius, float halfHeight, int stype, gjk_collision_visitor *allocator)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
create_brush_model_gjk_geom_r
==============
*/
void create_brush_model_gjk_geom_r(cLeafBrushNode_s *node, int *index_base, gjk_collision_visitor *allocator, const int contents_mask)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
query_brush_model_gjk_geom_visitor::visit
==============
*/
/*void __thiscall query_brush_model_gjk_geom_visitor::visit(query_brush_model_gjk_geom_visitor *this, const cbrush_t *brush)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
create_xmodel_gjk_geom
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
create_gjk_dobj_geom
==============
*/
void create_gjk_dobj_geom(DObj *obj, const cpose_t *pose, gentity_t *gent, const bool calc_bone_mats, unsigned int brush_mask, bool b_fallback_to_bounding_box, const int contents_for_proxy_collision, gjk_collision_visitor *allocator)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
collision_add_persistent_box
==============
*/
void collision_add_persistent_box(gjk_base_t *a1, vec3_t *axis, vec3_t *position, vec3_t *dims)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
gjk_aabb_t::destroy
==============
*/
/*void gjk_aabb_t::destroy(gjk_aabb_t *geom)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_obb_t::destroy
==============
*/
/*void gjk_obb_t::destroy(gjk_obb_t *geom)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_brush_t::destroy
==============
*/
/*void gjk_brush_t::destroy(gjk_brush_t *geom)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_partition_t::destroy
==============
*/
/*void gjk_partition_t::destroy(gjk_partition_t *geom)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_double_sphere_t::destroy
==============
*/
/*void gjk_double_sphere_t::destroy(gjk_double_sphere_t *geom)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_cylinder_t::destroy
==============
*/
/*void gjk_cylinder_t::destroy(gjk_cylinder_t *geom)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_polygon_cylinder_t::destroy
==============
*/
/*void gjk_polygon_cylinder_t::destroy(gjk_polygon_cylinder_t *geom)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
query_brush_model_gjk_geom
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
create_brush_model_gjk_geom
==============
*/
void create_brush_model_gjk_geom(int a1, unsigned __int16 brushModel, const int contents_mask, gjk_collision_visitor *allocator)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
create_gjk_geom
==============
*/
void create_gjk_geom(LocalClientNum_t localClientNum, const centity_t *cent, gjk_collision_visitor *allocator, const bool calc_bone_mats, unsigned int brush_mask, const cpose_t *b_fallback_to_bounding_box, bool b_use_smallerbox_for_characters)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
create_gjk_geom
==============
*/
void create_gjk_geom(gentity_t *gent, gjk_collision_visitor *allocator, const bool calc_bone_mats, unsigned int brush_mask, const cpose_t *b_fallback_to_bounding_box)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
create_gjk_geom
==============
*/
void create_gjk_geom(int a1, const Glass *glass, gjk_collision_visitor *allocator, unsigned int brush_mask)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
create_gjk_geom
==============
*/
/*void create_gjk_geom(const XModel *a1@<edx>, int a2@<ecx>, const DynEntityDef *dynEntDef, gjk_collision_visitor *allocator, unsigned int brush_mask)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
collision_reset_persistent_code_collision
==============
*/
void collision_reset_persistent_code_collision()
{
	UNIMPLEMENTED(__FUNCTION__);
}

