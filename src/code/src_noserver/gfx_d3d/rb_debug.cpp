#include "types.h"

/*
==============
TRACK_rb_debug
==============
*/
void TRACK_rb_debug()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_AddDebugLine
==============
*/
int RB_AddDebugLine(const vec3_t *start, const vec3_t *end, const vec4_t *color, bool depthTest, int vertCount, int vertLimit, GfxPointVertex *verts)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RB_EndDebugLines
==============
*/
int RB_EndDebugLines(int vertCount, const GfxPointVertex *verts)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RB_SetPolyVert
==============
*/
void RB_SetPolyVert(const vec3_t *xyz, GfxColor color, int tessVertIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_DrawPolyInteriors
==============
*/
void RB_DrawPolyInteriors(PolySet *polySet)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_DrawPolyOutlines
==============
*/
void RB_DrawPolyOutlines(PolySet *polySet)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_DrawDebugPolys
==============
*/
const GfxBackEndData *RB_DrawDebugPolys()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
RB_DrawDebugSphere
==============
*/
void RB_DrawDebugSphere(trDebugSphere_t *sphere)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_DrawDebugSpheres
==============
*/
void RB_DrawDebugSpheres(trDebugSphere_t *spheres, int sphereCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_DrawDebugLines
==============
*/
void RB_DrawDebugLines(trDebugLine_t *lines, int lineCount, GfxPointVertex *verts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_DrawDebugStrings
==============
*/
void RB_DrawDebugStrings(trDebugString_t *strings, int stringCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_AddPlumeStrings
==============
*/
void RB_AddPlumeStrings(float viewParms, const GfxViewParms *a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_SetDebugBrushesAndPatchesCallback
==============
*/
void RB_SetDebugBrushesAndPatchesCallback(void (*callback)())
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_DrawDebug
==============
*/
void __cdecl RB_DrawDebug(const GfxViewParms *viewParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_ApplySunLight
==============
*/
void RB_ApplySunLight(const vec3_t *verts, const vec4_t *color, vec4_t *out_color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_BeginCollisionPolygons
==============
*/
void RB_BeginCollisionPolygons(bool faceDepthTest, bool faceBlend)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_DrawCollisionPolygon
==============
*/
void RB_DrawCollisionPolygon(int vertCount, const vec3_t *verts, const vec4_t *faceColor, bool faceDepthTest, int debug_partition)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_GetCmd
==============
*/
materialCommands_t *RB_GetCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
RB_EndCollisionPolygons
==============
*/
void __cdecl RB_EndCollisionPolygons()
{
	UNIMPLEMENTED(__FUNCTION__);
}

