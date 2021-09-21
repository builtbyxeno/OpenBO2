#include "types.h"
#include "functions.h"

/*
==============
gjk_collision_epilog
==============
*/
void gjk_collision_epilog(const bool is_server_thread)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
gjk_query_output::calc_query_aabb
==============
*/
/*void __thiscall gjk_query_output::calc_query_aabb(gjk_query_output *this, const gjk_query_input *input)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_query_output::query_epilog
==============
*/
/*void __thiscall gjk_query_output::query_epilog(gjk_query_output *this)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_physics_collision_visitor::query_create_epilog_1
==============
*/
/*void __thiscall gjk_physics_collision_visitor::query_create_epilog_1(gjk_physics_collision_visitor *this, gjk_base_t *gjk_geom)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_query_output::set_local_query_info
==============
*/
/*void __thiscall gjk_query_output::set_local_query_info(gjk_query_output *this, const gjk_query_input *input, gjk_entity_info_t *ent_info)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
query_should_pass_gentity
==============
*/
bool query_should_pass_gentity(const gjk_query_input *input, const gentity_t *gent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
query_should_pass_centity
==============
*/
char query_should_pass_centity(const gjk_query_input *input, const centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
gjk_query_output::accum_query_reset
==============
*/
/*void __thiscall gjk_query_output::accum_query_reset(gjk_query_output *this, const phys_vec3 *start_origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
query_should_pass_entity
==============
*/
char query_should_pass_entity(const gjk_query_input *input, gjk_entity_info_t *ent_info)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
adjust_gjk_polygon_cylinder_query_aabb
==============
*/
void adjust_gjk_polygon_cylinder_query_aabb(vec3_t &,vec3_t &)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
get_material_from_brush
==============
*/
void get_material_from_brush(const cbrush_t *brush, int *sflags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
fill_results_type_and_id
==============
*/
void fill_results_type_and_id(const gjk_trace_output_t *gto, trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
fill_results_no_hit
==============
*/
void fill_results_no_hit(trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
is_walkable
==============
*/
bool is_walkable(float gto, const gjk_trace_output_t *a2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
gjk_query_output::allocate
==============
*/
/*char *__thiscall gjk_query_output::allocate(gjk_query_output *this, const int size, const int alignment, const bool no_error)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
gjk_query_output::get_local_query_aabb
==============
*/
/*void __thiscall gjk_query_output::get_local_query_aabb(gjk_query_output *this, vec3_t *local_query_aabb_min, vec3_t *local_query_aabb_max)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_query_output::query_create_prolog_1
==============
*/
/*bool __thiscall gjk_query_output::query_create_prolog_1(gjk_query_output *this, const vec3_t *local_aabb_min, const vec3_t *local_aabb_max, const void *geom)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
gjk_query_output::create_geom_info
==============
*/
/*gjk_geom_info_t *__thiscall gjk_query_output::create_geom_info(gjk_query_output *this, gjk_base_t *cg, gjk_entity_info_t *ent_info, const vec3_t *aabb_min, const vec3_t *aabb_max)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
setup_gjk_capsule
==============
*/
void setup_gjk_capsule(const vec3_t *mins, const vec3_t *maxs, const float radius_adjust, gjk_double_sphere_t *gjk_capsule)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
setup_gjk_cylinder
==============
*/
void setup_gjk_cylinder(const vec3_t *mins, const vec3_t *maxs, const float radius_adjust, gjk_cylinder_t *gjk_cylinder)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
gjk_aabb_t::is_walkable
==============
*/
/*bool gjk_aabb_t::is_walkable(gjk_aabb_t *this, int a2, const phys_vec3 *hit_point, const phys_vec3 *up)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
is_walkable
==============
*/
bool is_walkable(const cbrush_t *brush, const phys_vec3 *hit_point_loc, const phys_vec3 *up_loc)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
is_walkable
==============
*/
bool is_walkable(const CollisionPartition *partition, const phys_vec3 *hit_point_loc, const phys_vec3 *up_loc)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
fill_results
==============
*/
void fill_results(const gjk_trace_output_t *gto, const bool is_walkable, trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
gjk_query_output::query_prolog
==============
*/
/*void __thiscall gjk_query_output::query_prolog(gjk_query_output *this, const gjk_query_input *input)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_query_output::query_create_epilog
==============
*/
/*void __thiscall gjk_query_output::query_create_epilog(gjk_query_output *this, gjk_base_t *gjk_geom)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
project
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
gjk_query_output::reset_cache
==============
*/
/*void __thiscall gjk_query_output::reset_cache(gjk_query_output *this)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_query_output::query_create_prolog
==============
*/
/*bool __thiscall gjk_query_output::query_create_prolog(gjk_query_output *this, const void *geom)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
gjk_query_output::add
==============
*/
/*void __thiscall gjk_query_output::add(gjk_query_output *this, const gjk_query_input *input, gentity_t *gent)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_query_output::add
==============
*/
/*void __thiscall gjk_query_output::add(gjk_query_output *this, const gjk_query_input *input, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_query_output::add
==============
*/
/*void __thiscall gjk_query_output::add(gjk_query_output *this, const gjk_query_input *input, const Glass *glass)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_query_output::add
==============
*/
/*void __thiscall gjk_query_output::add(gjk_query_output *this, const gjk_query_input *input, const DynEntityDef *dent)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_query_prims
==============
*/
void gjk_query_prims(const gjk_query_input *input, gjk_query_output *output)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
gjk_query_terrain
==============
*/
void gjk_query_terrain(int a1, const gjk_query_input *input, gjk_query_output *output)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
gjk_query_gents
==============
*/
void gjk_query_gents(const gjk_query_input *input, gjk_query_output *output)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
gjk_query_cents
==============
*/
void gjk_query_cents(const gjk_query_input *input, gjk_query_output *output)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
gjk_query_glass
==============
*/
void gjk_query_glass(const gjk_query_input *input, gjk_query_output *output)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
gjk_query_dents
==============
*/
void gjk_query_dents(const gjk_query_input *input, gjk_query_output *output)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
gjk_query
==============
*/
/*void gjk_query(const gjk_query_input *a1@<edx>, colgeom_visitor_inlined_t<300> *a2@<ecx>, const gjk_query_input *input, gjk_query_output *output)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_query_output::cached_query_resize
==============
*/
/*
{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}*/

/*
==============
gjk_query_output::cached_query_prolog
==============
*/
/*void __thiscall gjk_query_output::cached_query_prolog(gjk_query_output *this, const bool is_server_thread, colgeom_visitor_inlined_t<300> *proximity_data, const int proximity_mask, const phys_vec3 *start_origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_query_output::cached_query_epilog
==============
*/
/*void __thiscall gjk_query_output::cached_query_epilog(gjk_query_output *this)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_query_cached
==============
*/
void gjk_query_cached(int a1, const gjk_query_input *input, gjk_query_output *output)
{
	UNIMPLEMENTED(__FUNCTION__);
}

