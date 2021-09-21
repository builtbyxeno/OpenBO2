#include "types.h"
#include "functions.h"

/*
==============
create_gjkcc_gjk_geom
==============
*/
gjk_polygon_cylinder_t *create_gjkcc_gjk_geom(const vec3_t *mins, const vec3_t *maxs, const int stype, gjk_collision_visitor *allocator)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
gjkcc_info::update_cg
==============
*/
/*void gjkcc_info::update_cg(gjkcc_info *notthis, int a2, int mins, const vec3_t *maxs, const vec3_t *force, const bool a6)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_double_sphere_t::is_foot
==============
*/
/*bool gjk_double_sphere_t::is_foot(gjk_double_sphere_t *notthis, const phys_vec3 *hit_point)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
gjk_polygon_cylinder_t::is_foot
==============
*/
/*bool gjk_polygon_cylinder_t::is_foot(gjk_polygon_cylinder_t *notthis, const phys_vec3 *hit_point)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
gjk_brush_t::is_walkable
==============
*/
/*bool gjk_brush_t::is_walkable(gjk_brush_t *notthis, const phys_vec3 *hit_point, const phys_vec3 *up)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
gjk_partition_t::is_walkable
==============
*/
/*bool gjk_partition_t::is_walkable(gjk_partition_t *notthis, const phys_vec3 *hit_point, const phys_vec3 *up)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
gjk_collide
==============
*/
char gjk_collide(phys_gjk_info *gjk_info, const phys_gjk_input *pgi, gjk_trace_output_t *gto, const gjk_trace_input_t *gti, gjk_geom_info_t *gi)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
init_pgi
==============
*/
void init_pgi(phys_gjk_input *pgi, const gjk_trace_input_t *gti)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
sort_gi_list
==============
*/
void sort_gi_list(gjk_geom_info_t **list, const int list_count)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
is_sentient
==============
*/
char is_sentient(gjk_geom_info_t *gi)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
no_push_out
==============
*/
char no_push_out(const gjk_trace_output_t *gto)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_VerifyPronePosition
==============
*/
int PM_VerifyPronePosition(pmove_t *pm, vec3_t *vFallbackOrg, vec3_t *vFallbackVel)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_PermuteRestrictiveClipPlanes
==============
*/
double PM_PermuteRestrictiveClipPlanes(const vec3_t *velocity, int planeCount, const vec3_t *planes, int *permutation)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
setup_player_gjk_slide_move_input
==============
*/
void setup_player_gjk_slide_move_input(player_gjk_slide_move_input_t *input, pmove_t *pm, pml_t *pml, int gravity)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
gjkcc_info_database_t::gjkcc_info_find
==============
*/
/*gjkcc_info *gjkcc_info_database_t::gjkcc_info_find(gjkcc_info_database_t *notthis, const unsigned int gjkcc_id, const bool is_server_thread)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
gjk_cylinder_t::is_foot
==============
*/
/*bool gjk_cylinder_t::is_foot(gjk_cylinder_t *notthis, float hit_point, const phys_vec3 *a3)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
setup_query_input
==============
*/
void setup_query_input(const gjkcc_input_t *gjkcc_in, const phys_vec3 *aabb_min, const phys_vec3 *aabb_max, const phys_vec3 *position, const phys_vec3 *translation, const int passEntityNum, const int contentMask, gjk_query_input *query_input)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
setup_trace_info
==============
*/
void setup_trace_info(int a1, int a2, int gjkcc_in, const gjkcc_input_t *start, const vec3_t *mins, const vec3_t *maxs, const vec3_t *end, const vec3_t *passEntityNum, int contentMask, int gti, gjk_trace_input_t *a11)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
player_gjk_slide_move_input_t::custom_process
==============
*/
/*void player_gjk_slide_move_input_t::custom_process(player_gjk_slide_move_input_t *notthis, int a2, gjk_trace_output_t *gto)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_trace
==============
*/
void gjk_trace(int a1, const gjk_trace_input_t *gti, list_gjk_trace_output *list)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
add_hit_info
==============
*/
/*void add_hit_info(const gjk_trace_output_t *gto, phys_static_array<geom_plane,128> *list_geom_plane, phys_link_list<gjk_geom_info_t> *geom_skip_list)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjk_push_out
==============
*/
bool gjk_push_out(int a1, const gjkcc_input_t *gjkcc_in, const gjk_slide_move_input_t *input, bool skip_sentients, gjk_slide_move_output_t *output)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
gjk_slide_move1
==============
*/
BOOL gjk_slide_move1(int a1, const gjkcc_input_t *gjkcc_in, const gjk_slide_move_input_t *input, const bool no_push_out, gjk_slide_move_output_t *output, bool *needs_push_out)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
gjk_slide_move
==============
*/
BOOL gjk_slide_move(const gjkcc_input_t *a1, int a2, const gjkcc_input_t *gjkcc_in, const gjk_slide_move_input_t *input, gjk_slide_move_output_t *output)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
gjk_sentient_push
==============
*/
void gjk_sentient_push(int a1, pmove_t *pm, pml_t *pml, const vec3_t *origin, const vec3_t *mins, const vec3_t *maxs, const int contentMask, const int passEntityNum, const gjkcc_input_t *gjkcc_in, const float pushRadius, const float frameTime, vec3_t *velocity_, vec3_t *origin_)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
render_gjkcc_collision
==============
*/
void render_gjkcc_collision(int a1, int a2, const vec3_t *mins, const vec3_t *maxs, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
render_gjkcc_collision
==============
*/
void render_gjkcc_collision(int a1, pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_gjk_ground_trace
==============
*/
void PM_gjk_ground_trace(float gjkcc_in, const gjkcc_input_t *a2, trace_t *results, const vec3_t *start, const vec3_t *mins, const vec3_t *maxs, const vec3_t *end, const int passEntityNum, const int contentMask, float *first_hit_time_out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_SlideMove
==============
*/
int PM_SlideMove(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_StepSlideMove
==============
*/
void PM_StepSlideMove(unsigned int a1, pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
gjkcc_epilog
==============
*/
void gjkcc_epilog(const gjkcc_input_t *gjkcc_in, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
gjk_player_trace
==============
*/
void gjk_player_trace(gjk_trace_output_t **a1, int a2, const gjkcc_input_t *gjkcc_in, trace_t *results, const vec3_t *start, const vec3_t *mins, const vec3_t *maxs, const vec3_t *end, int passEntityNum, int contentMask)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
gjkcc_info_database_t::create_gjkcc_info
==============
*/
/*gjkcc_info *gjkcc_info_database_t::create_gjkcc_info(gjkcc_info_database_t *notthis, const gjkcc_input_t *gjkcc_in, const bool is_server_thread, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
destroy_gjkcc_info
==============
*/
void destroy_gjkcc_info(void *gcci_)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
gjkcc_info_database_t::gjkcc_info_find_or_create
==============
*/
/*gjkcc_info *gjkcc_info_database_t::gjkcc_info_find_or_create(gjkcc_info_database_t *notthis, const gjkcc_input_t *gjkcc_in, const bool is_server_thread, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
gjkcc_info_database_t::gjkcc_info_destroy
==============
*/
/*void gjkcc_info_database_t::gjkcc_info_destroy(gjkcc_info_database_t *notthis, const unsigned int gjkcc_id, const bool is_server_thread)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
gjkcc_info_database_t::gjkcc_info_destroy_all
==============
*/
/*void gjkcc_info_database_t::gjkcc_info_destroy_all(gjkcc_info_database_t *notthis, const bool is_server_thread)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
destroy_client_gjkcc_info
==============
*/
void destroy_client_gjkcc_info(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
destroy_all_server_gjkcc_info
==============
*/
void destroy_all_server_gjkcc_info()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
gjkcc_prolog
==============
*/
void gjkcc_prolog(int a1, const gjkcc_input_t *gjkcc_in, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

