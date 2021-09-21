#include "types.h"
#include "functions.h"

/*
==============
R_Is3DOn
==============
*/
bool R_Is3DOn()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
gjk_collision_visitor::get_local_query_aabb
==============
*/
/*void gjk_collision_visitor::get_local_query_aabb(gjk_collision_visitor *notthis, vec3_t *local_query_aabb_min, vec3_t *local_query_aabb_max)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_geom_list_t::add_geom
==============
*/
/*void gjk_geom_list_t::add_geom(gjk_geom_list_t *notthis, gjk_base_t *geom)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
create_gjk_geom_collision_visitor::allocate
==============
*/
/*void *create_gjk_geom_collision_visitor::allocate(create_gjk_geom_collision_visitor *notthis, const int size, const int alignment, const bool no_error)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
create_gjk_geom_collision_visitor::query_create_prolog
==============
*/
/*char create_gjk_geom_collision_visitor::query_create_prolog(create_gjk_geom_collision_visitor *notthis, const void *geom)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
create_gjk_geom_collision_visitor::query_create_epilog_1
==============
*/
/*void create_gjk_geom_collision_visitor::query_create_epilog_1(create_gjk_geom_collision_visitor *notthis, gjk_base_t *gjk_geom)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
create_gjk_geom_collision_visitor::query_create_prolog_1
==============
*/
/*char create_gjk_geom_collision_visitor::query_create_prolog_1(create_gjk_geom_collision_visitor *notthis, const vec3_t *local_aabb_min, const vec3_t *local_aabb_max, const void *geom)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
gjk_base_t::get_aabb_mn_loc
==============
*/
/*const phys_vec3 *gjk_base_t::get_aabb_mn_loc(gjk_base_t *notthis, const phys_vec3 *result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
gjk_base_t::get_aabb_mx_loc
==============
*/
/*const phys_vec3 *gjk_base_t::get_aabb_mx_loc(gjk_base_t *notthis, const phys_vec3 *result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
gjk_geom_list_t::get_first_geom
==============
*/
/*gjk_base_t *gjk_geom_list_t::get_first_geom(gjk_geom_list_t *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
gjk_geom_list_t::comp_aabb_loc
==============
*/
/*void gjk_geom_list_t::comp_aabb_loc(gjk_geom_list_t *notthis, int a2, int aabb_mn_loc, phys_vec3 *aabb_mx_loc, phys_vec3 *a5)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_base_t::comp_aabb_loc
==============
*/
/*void gjk_base_t::comp_aabb_loc(gjk_base_t *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_base_t::set_xform
==============
*/
/*void gjk_base_t::set_xform(gjk_base_t *notthis, const phys_mat44 *xform)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_base_t::is_walkable
==============
*/
/*bool gjk_base_t::is_walkable(gjk_base_t *notthis, const phys_vec3 *hit_point, const phys_vec3 *up)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
gjk_aabb_t::get_simplex
==============
*/
/*void gjk_aabb_t::get_simplex(gjk_aabb_t *notthis, const cached_simplex_info *cache_info, const int index_count, phys_vec3 *simplex_verts, phys_vec3 *simplex_inds)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_aabb_t::get_brush
==============
*/
/*const cbrush_t *gjk_aabb_t::get_brush(gjk_aabb_t *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
gjk_aabb_t::support
==============
*/
/*void gjk_aabb_t::support(gjk_aabb_t *notthis, const phys_vec3 *v, phys_vec3 *support_vert, phys_vec3 *support_ind)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_aabb_t::get_feature
==============
*/
/*void gjk_aabb_t::get_feature(gjk_aabb_t *notthis, int a2, phys_contact_manifold *cman)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_aabb_t::calc_aabb
==============
*/
/*void gjk_aabb_t::calc_aabb(gjk_aabb_t *notthis, const phys_mat44 *xform, phys_vec3 *aabb_min, phys_vec3 *aabb_max)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_obb_t::get_simplex
==============
*/
/*void gjk_obb_t::get_simplex(gjk_obb_t *notthis, const cached_simplex_info *cache_info, const int index_count, phys_vec3 *simplex_verts, phys_vec3 *simplex_inds)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_obb_t::get_center
==============
*/
/*const phys_vec3 *gjk_obb_t::get_center(gjk_obb_t *notthis, const phys_vec3 *result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
gjk_obb_t::calc_aabb
==============
*/
/*void gjk_obb_t::calc_aabb(gjk_obb_t *notthis, int a2, const phys_mat44 *xform, phys_vec3 *aabb_min, phys_vec3 *aabb_max)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_obb_t::get_type
==============
*/
/*unsigned int gjk_obb_t::get_type(gjk_obb_t *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
gjk_obb_t::support
==============
*/
/*void gjk_obb_t::support(gjk_obb_t *notthis, const phys_vec3 *v, phys_vec3 *support_vert, phys_vec3 *support_ind)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_obb_t::get_feature
==============
*/
/*void gjk_obb_t::get_feature(gjk_obb_t *notthis, int a2, phys_contact_manifold *cman)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_brush_t::get_brush
==============
*/
/*const cbrush_t *gjk_brush_t::get_brush(gjk_brush_t *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
gjk_brush_t::get_type
==============
*/
/*unsigned int gjk_brush_t::get_type(gjk_brush_t *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
gjk_brush_t::support
==============
*/
/*void gjk_brush_t::support(gjk_brush_t *notthis, const phys_vec3 *v, phys_vec3 *support_vert, phys_vec3 *support_ind)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_brush_t::get_simplex
==============
*/
/*void gjk_brush_t::get_simplex(gjk_brush_t *notthis, const cached_simplex_info *cache_info, const int index_count, phys_vec3 *simplex_verts, phys_vec3 *simplex_inds)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_brush_t::get_feature
==============
*/
/*void gjk_brush_t::get_feature(gjk_brush_t *notthis, int a2, phys_contact_manifold *cman)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_brush_t::calc_aabb
==============
*/
/*void gjk_brush_t::calc_aabb(gjk_brush_t *notthis, const phys_mat44 *xform, phys_vec3 *aabb_min, phys_vec3 *aabb_max)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_brush_t::get_center
==============
*/
/*const phys_vec3 *gjk_brush_t::get_center(gjk_partition_t *notthis, const phys_vec3 *result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
gjk_partition_t::get_type
==============
*/
/*unsigned int gjk_partition_t::get_type(gjk_partition_t *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
gjk_partition_t::support
==============
*/
/*void gjk_partition_t::support(gjk_partition_t *notthis, const phys_vec3 *v, phys_vec3 *support_vert, phys_vec3 *support_ind)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_partition_t::get_simplex
==============
*/
/*void gjk_partition_t::get_simplex(gjk_partition_t *notthis, const cached_simplex_info *cache_info, const int index_count, phys_vec3 *simplex_verts, phys_vec3 *simplex_inds)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_partition_t::get_feature
==============
*/
/*void gjk_partition_t::get_feature(gjk_partition_t *notthis, float cman, phys_contact_manifold *a3)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_partition_t::calc_aabb
==============
*/
/*void gjk_partition_t::calc_aabb(gjk_partition_t *notthis, const phys_mat44 *xform, phys_vec3 *aabb_min, phys_vec3 *aabb_max)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_double_sphere_t::support
==============
*/
/*void gjk_double_sphere_t::support(gjk_double_sphere_t *notthis, const phys_vec3 *v, phys_vec3 *support_vert, phys_vec3 *support_ind)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_double_sphere_t::get_simplex
==============
*/
/*void gjk_double_sphere_t::get_simplex(gjk_double_sphere_t *notthis, const cached_simplex_info *cache_info, const int index_count, phys_vec3 *simplex_verts, phys_vec3 *simplex_inds)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_double_sphere_t::set_simplex
==============
*/
/*void gjk_double_sphere_t::set_simplex(gjk_double_sphere_t *notthis, const phys_vec3 *simplex_inds, const int w_set, const phys_vec3 *normal, cached_simplex_info *cache_info)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_double_sphere_t::get_center
==============
*/
/*const phys_vec3 *gjk_double_sphere_t::get_center(gjk_double_sphere_t *notthis, const phys_vec3 *result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
gjk_double_sphere_t::calc_aabb
==============
*/
/*void gjk_double_sphere_t::calc_aabb(gjk_double_sphere_t *notthis, const phys_mat44 *xform, phys_vec3 *aabb_min, phys_vec3 *aabb_max)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_double_sphere_t::get_geom_radius
==============
*/
/*double gjk_double_sphere_t::get_geom_radius(gjk_double_sphere_t *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
gjk_double_sphere_t::is_polyhedron
==============
*/
/*bool gjk_double_sphere_t::is_polyhedron(gjk_double_sphere_t *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
gjk_double_sphere_t::get_feature
==============
*/
/*void gjk_double_sphere_t::get_feature(gjk_double_sphere_t *notthis, int a2, phys_contact_manifold *cman)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_cylinder_t::get_center
==============
*/
/*const phys_vec3 *gjk_cylinder_t::get_center(gjk_cylinder_t *notthis, const phys_vec3 *result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
gjk_cylinder_t::get_geom_radius
==============
*/
/*double gjk_cylinder_t::get_geom_radius(gjk_cylinder_t *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
gjk_cylinder_t::support
==============
*/
/*void gjk_cylinder_t::support(gjk_cylinder_t *notthis, int a2, const phys_vec3 *v, phys_vec3 *support_vert, phys_vec3 *support_ind)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_cylinder_t::get_simplex
==============
*/
/*void gjk_cylinder_t::get_simplex(gjk_cylinder_t *notthis, int a2, const cached_simplex_info *cache_info, const int index_count, phys_vec3 *simplex_verts, phys_vec3 *simplex_inds)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_cylinder_t::get_feature
==============
*/
/*void gjk_cylinder_t::get_feature(gjk_cylinder_t *notthis, int a2, phys_contact_manifold *cman)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_cylinder_t::calc_aabb
==============
*/
/*void gjk_cylinder_t::calc_aabb(gjk_cylinder_t *notthis, float xform_, const phys_mat44 *a3, phys_vec3 *aabb_min, phys_vec3 *aabb_max)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_polygon_cylinder_t::poly_verts::support
==============
*/
/*void gjk_polygon_cylinder_t::poly_verts::support(phys_vec3 const &)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_polygon_cylinder_t::poly_verts::get_co_si
==============
*/
/*void gjk_polygon_cylinder_t::poly_verts::get_co_si(gjk_polygon_cylinder_t::poly_verts *notthis, const int i, float *co_, float *si_)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_polygon_cylinder_t::support
==============
*/
/*void gjk_polygon_cylinder_t::support(gjk_polygon_cylinder_t *notthis, int a2, const phys_vec3 *v, phys_vec3 *support_vert, phys_vec3 *support_ind)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_polygon_cylinder_t::get_simplex
==============
*/
/*void gjk_polygon_cylinder_t::get_simplex(gjk_polygon_cylinder_t *notthis, int a2, const cached_simplex_info *cache_info, const int index_count, phys_vec3 *simplex_verts, phys_vec3 *simplex_inds)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_aabb_t::get_center
==============
*/
/*const phys_vec3 *gjk_aabb_t::get_center(gjk_polygon_cylinder_t *notthis, const phys_vec3 *result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
gjk_polygon_cylinder_t::calc_aabb
==============
*/
/*void gjk_polygon_cylinder_t::calc_aabb(gjk_polygon_cylinder_t *notthis, const phys_mat44 *xform, phys_vec3 *aabb_min, phys_vec3 *aabb_max)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_polygon_cylinder_t::get_geom_radius
==============
*/
/*double gjk_polygon_cylinder_t::get_geom_radius(gjk_polygon_cylinder_t *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
destroy_gjk_geom
==============
*/
void destroy_gjk_geom(gjk_base_t *geom)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
destroy_gjk_geom
==============
*/
void destroy_gjk_geom(gjk_geom_list_t *gjk_geom_list)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
gjk_geom_list_t::get_geom_count
==============
*/
/*int gjk_geom_list_t::get_geom_count(gjk_geom_list_t *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
get_simplex
==============
*/
void get_simplex(const phys_gjk_geom *cg1, const phys_gjk_geom *cg2, phys_gjk_cache_info *gjk_ci, phys_vec3 *a_verts, phys_vec3 *a_inds, phys_vec3 *b_verts, phys_vec3 *b_inds, int *vert_count)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
set_simplex
==============
*/
void set_simplex(const phys_gjk_geom *cg1, const phys_gjk_geom *cg2, phys_gjk_cache_info *gjk_ci, const phys_vec3 *a_normal, const phys_vec3 *b_normal, const phys_vec3 *a_inds, const phys_vec3 *b_inds, const int w_set)
{
	UNIMPLEMENTED(__FUNCTION__);
}

