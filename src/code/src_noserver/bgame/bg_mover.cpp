#include "types.h"

/*
==============
entity_is_a_mover
==============
*/
bool entity_is_a_mover(const int entnum, const int max_ents)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
mover_info_t::init
==============
*/
/*void mover_info_t::init(mover_info_t *notthis, const vec3_t *origin, const vec3_t *angles, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
mover_info_t::add_record
==============
*/
/*void mover_info_t::add_record(mover_info_t *notthis, const vec3_t *origin, const vec3_t *angles, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
mover_info_t::get_position
==============
*/
/*void mover_info_t::get_position(mover_info_t *notthis, int time, vec3_t *origin, vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
sv_rewind_context_t::~sv_rewind_context_t
==============
*/
/*void sv_rewind_context_t::~sv_rewind_context_t(sv_rewind_context_t *notthis, int a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
actors_rewind_context_t::restore
==============
*/
/*void actors_rewind_context_t::restore(actors_rewind_context_t *notthis, int a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
get_entity_mover
==============
*/
int get_entity_mover(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RestoreMovers
==============
*/
void RestoreMovers(unsigned __int8 handler, LocalClientNum_t localClientNum, bool doLink)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
cl_get_mover_info
==============
*/
mover_info_t *cl_get_mover_info(centity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
sv_get_mover_info
==============
*/
mover_info_t *sv_get_mover_info(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
mover_info_t::apply_rotation
==============
*/
/*void mover_info_t::apply_rotation(mover_info_t *notthis, int a2, vec3_t *v)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
mover_info_t::apply_rotation_translation
==============
*/
/*void mover_info_t::apply_rotation_translation(mover_info_t *notthis, int a2, vec3_t *v)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
AdjustMovers
==============
*/
void AdjustMovers(unsigned __int8 handler, LocalClientNum_t localClientNum, int time, bool doLink)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_AdjustPositionForMover
==============
*/
void BG_AdjustPositionForMover(unsigned int a1, unsigned __int8 handler, LocalClientNum_t localClientNum, int moverNum, int fromTime, int toTime, vec3_t *outOrigin, vec3_t *outAngles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
cl_destroy_mover_info
==============
*/
void cl_destroy_mover_info(void *mi_)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
cl_mover_info_level_init
==============
*/
void cl_mover_info_level_init(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
cl_create_mover_info
==============
*/
mover_info_t *cl_create_mover_info(centity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
sv_destroy_mover_info
==============
*/
void sv_destroy_mover_info(void *mi_)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
sv_mover_info_level_init
==============
*/
void sv_mover_info_level_init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
sv_destroy_mover_info
==============
*/
void sv_destroy_mover_info(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
sv_update_mover_info
==============
*/
mover_info_t *sv_update_mover_info(gentity_t *ent, vec3_t origin, vec3_t angles, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
mover_info_apply_rotation
==============
*/
void mover_info_apply_rotation(const int gentnum, vec3_t *v)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
mover_info_apply_rotation_xy
==============
*/
void mover_info_apply_rotation_xy(const int gentnum, vec2_t *v)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
mover_info_apply_rotation_translation
==============
*/
void mover_info_apply_rotation_translation(const int gentnum, vec3_t *v)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
sv_rewind_context_t::sv_rewind_context_t
==============
*/
/*void sv_rewind_context_t::sv_rewind_context_t(sv_rewind_context_t *notthis, int mover_num, int from_time, int to_time, vec3_t *origin, vec3_t *angles, gentity_t *ent_to_link)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
actors_rewind_context_t::rewind
==============
*/
/*void actors_rewind_context_t::rewind(actors_rewind_context_t *notthis, int from_time, int to_time, int _mover_num)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

