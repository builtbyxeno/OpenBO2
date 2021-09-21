#include "types.h"
#include "functions.h"

/*
==============
R_InitShaderConstantSet
==============
*/
void R_InitShaderConstantSet(ShaderConstantSet *scs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ShaderConstantSetIsUsed
==============
*/
BOOL R_ShaderConstantSetIsUsed(const ShaderConstantSet *scs)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_CopyShaderConstantSet
==============
*/
void R_CopyShaderConstantSet(const ShaderConstantSet *scs_src, ShaderConstantSet *scs_dst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetConstantIndex
==============
*/
int R_GetConstantIndex(const ShaderConstantSet *scs, const char *constantName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetShaderConstantSetValue
==============
*/
char R_SetShaderConstantSetValue(ShaderConstantSet *scs, int index, const vec4_t *v)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetShaderConstantSetValue
==============
*/
char R_SetShaderConstantSetValue(ShaderConstantSet *scs, int index, float x, float y, float z, float w)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetShaderConstantSetValueX
==============
*/
char R_SetShaderConstantSetValueX(ShaderConstantSet *scs, int index, float x)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetShaderConstantSetValueY
==============
*/
char R_SetShaderConstantSetValueY(ShaderConstantSet *scs, int index, float y)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetShaderConstantSetValueZ
==============
*/
char R_SetShaderConstantSetValueZ(ShaderConstantSet *scs, int index, float z)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetShaderConstantSetValueW
==============
*/
char R_SetShaderConstantSetValueW(ShaderConstantSet *scs, int index, float w)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RB_ApplyShaderConstantSet
==============
*/
int RB_ApplyShaderConstantSet(GfxCmdBufSourceState *gfxSourceState, const ShaderConstantSet *scs)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XModelDrawSurf_EncodeIndex
==============
*/
void XModelDrawSurf_EncodeIndex(GfxDrawSurf *drawSurf, unsigned int scsIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_ShaderConstantSetFromDrawSurf
==============
*/
ShaderConstantSet *RB_ShaderConstantSetFromDrawSurf(const GfxBackEndData *backEndData, const GfxDrawSurf *drawSurf)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
RB_ApplyShaderConstantSet
==============
*/
void RB_ApplyShaderConstantSet(GfxCmdBufSourceState *gfxSourceState, const GfxDrawSurf *drawSurf)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_DrawSurf_Uses_ShaderConstantSet
==============
*/
BOOL RB_DrawSurf_Uses_ShaderConstantSet(const GfxDrawSurf *drawSurf)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CopyShaderConstantSetToBackendData
==============
*/
unsigned int CopyShaderConstantSetToBackendData(const ShaderConstantSet *scs)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_XModelDrawSurfEncodeShaderConstantSet
==============
*/
void R_XModelDrawSurfEncodeShaderConstantSet(unsigned int a1, GfxDrawSurf *a2, GfxDrawSurf *drawSurf, unsigned int constSetIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ShaderConstantSet_CopyToFrontEndDataOut
==============
*/
unsigned int R_ShaderConstantSet_CopyToFrontEndDataOut(const ShaderConstantSet *scs)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_ShaderConstantSet_FromFrontEndDataOut
==============
*/
ShaderConstantSet *R_ShaderConstantSet_FromFrontEndDataOut(unsigned int constSetindex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
RB_SaveCurrentShaderConstantSetValues
==============
*/
void RB_SaveCurrentShaderConstantSetValues(ShaderConstantSet *destSet, GfxCmdBufSourceState *gfxSourceState, const ShaderConstantSet *srcSet)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ScopedShaderConstantSetUndo::ScopedShaderConstantSetUndo
==============
*/
/*void __thiscall ScopedShaderConstantSetUndo::ScopedShaderConstantSetUndo(ScopedShaderConstantSetUndo *this, GfxCmdBufSourceState *sourceState, const ShaderConstantSet *cscEA)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
ScopedShaderConstantSetUndo::~ScopedShaderConstantSetUndo
==============
*/
/*void __thiscall ScopedShaderConstantSetUndo::~ScopedShaderConstantSetUndo(ScopedShaderConstantSetUndo *this)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
R_ShaderConstantShowDebug
==============
*/
void R_ShaderConstantShowDebug(const vec3_t *eyePos, const vec3_t *objOrigin, float objRad, const ShaderConstantSet *scs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_MapShaderConstantSet
==============
*/
bool R_MapShaderConstantSet(ShaderConstantSet *scs, int index, const char *constantName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AllocShaderConstantSet
==============
*/
int R_AllocShaderConstantSet(ShaderConstantSet *scs, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

