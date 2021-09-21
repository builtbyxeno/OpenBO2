#include "types.h"
#include "functions.h"

/*
==============
DebugPatchesAndBrushesProlog
==============
*/
void DebugPatchesAndBrushesProlog()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DebugPatchesAndBrushesEpilog
==============
*/
void DebugPatchesAndBrushesEpilog()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
debug_brush_info_t::find_index_in_brush
==============
*/
/*__int16 __thiscall debug_brush_info_t::find_index_in_brush(debug_brush_info_t *this, const cbrush_t *brush, const vec3_t *v)
{
	UNIMPLEMENTED(__FUNCTION__);
	__int16 __thiscall tmp;
	return tmp;
}*/

/*
==============
debug_patch_info_t::find_index_in_clipmap
==============
*/
/*unsigned int __thiscall debug_patch_info_t::find_index_in_clipmap(debug_patch_info_t *this, const CollisionAabbTree *tree, const vec3_t *v)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
clear_debug_brushes_and_patches
==============
*/
void clear_debug_brushes_and_patches()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SeedColor
==============
*/
void SeedColor(const void *ptr, const vec4_t *baseColor, float scale, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
render_debug_brushes
==============
*/
void render_debug_brushes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
render_debug_patches_full
==============
*/
void render_debug_patches_full()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
render_debug_brushes_and_patches
==============
*/
void render_debug_brushes_and_patches()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
calc_color
==============
*/
void calc_color(const void *id, const float alpha, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
render_tree
==============
*/
void render_tree(const CollisionAabbTree *tree, vec3_t *_trans)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
render_collision_tree
==============
*/
void render_collision_tree(const CollisionAabbTree *tree, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
debug_patch_info_t::add_patch
==============
*/
/*void __thiscall debug_patch_info_t::add_patch(debug_patch_info_t *this, const CollisionAabbTree *tree)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
add_debug_patch
==============
*/
void add_debug_patch(const CollisionAabbTree *tree)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
render_brush
==============
*/
void render_brush(unsigned int a1, const cbrush_t *brush, const phys_mat44 *xform, const vec4_t *color, bool bLinesOnly, const vec3_t *lightPos, bool persistent, bool ztest, const vec4_t *edgeColor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
render_convex_partition
==============
*/
void render_convex_partition(const CollisionAabbTree *tree)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
render_chull
==============
*/
void render_chull(unsigned int a1, const chull_t *first, const phys_mat44 *xform, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
render_xmodel_chull
==============
*/
void render_xmodel_chull(const XModel *model, const unsigned int key, const phys_mat44 *xform, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
render_brushmodel_chull
==============
*/
void render_brushmodel_chull(cmodel_t **a1, int brushmodel, unsigned int key, const phys_mat44 *xform, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
render_line
==============
*/
void render_line(clientDebugLineInfo_t *a1, const phys_vec3 *p0, const phys_vec3 *p1, const vec4_t *color, int duration, int ztest)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
render_box
==============
*/
void render_box(int a1, const phys_vec3 *mins, const phys_vec3 *maxs, const phys_mat44 *xform, const vec4_t *color, int duration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
render_box
==============
*/
void render_box(float _mn, const vec3_t *a2, const vec3_t *_mx, const vec4_t *color, int duration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
render_box
==============
*/
void render_box(const phys_vec3 *mins, const phys_vec3 *maxs, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
render_gjk_geom
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
init_winding
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Phys_DebugPoint
==============
*/
void Phys_DebugPoint(clientDebugLineInfo_t *a1, const phys_vec3 *pos, const float radius, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_DebugBox
==============
*/
void Phys_DebugBox(const phys_mat44 *mat, const vec4_t *color, float scale)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_DebugBox
==============
*/
void Phys_DebugBox(const phys_mat44 *mat, const phys_vec3 *dims, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Phys_RenderBase
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Phys_JointDebugRender
==============
*/
void Phys_JointDebugRender(int a1, int id)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
render_prims
==============
*/
void render_prims(col_prim_t *prims, int nprims)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GjkTraceGeom::Render
==============
*/
/*void GjkTraceGeom::Render(unsigned int a1)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
render_debug_draw_gjk_trace_geom
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
clip_winding
==============
*/
/*void clip_winding(int a1, phys_static_array<phys_vec3,512> *winding, const plane_lt *clip)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
calc_winding
==============
*/
/*void calc_winding(int a1, const phys_static_array<plane_lt,512> *planes, int plane_index, phys_static_array<phys_vec3,512> *winding)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
render_contact
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
debug_brush_info_t::add_brush
==============
*/
/*void debug_brush_info_t::add_brush(debug_brush_info_t *this, int a2, const cbrush_t *brush, const phys_mat44 *mat)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
add_debug_brush
==============
*/
void add_debug_brush(const cbrush_t *brush, const phys_mat44 *mat)
{
	UNIMPLEMENTED(__FUNCTION__);
}

