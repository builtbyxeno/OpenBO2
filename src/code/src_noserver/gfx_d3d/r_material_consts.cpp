#include "types.h"
#include "functions.h"

/*
==============
R_RegisterShaderConst
==============
*/
void R_RegisterShaderConst(unsigned int buffer, unsigned int offset, const vec4_t *value, GfxShaderConstantBlock *consts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetPixelLiteralConsts
==============
*/
void R_GetPixelLiteralConsts(int a1, int a2, int mtl, const Material *argCount, const MaterialPass *pass, GfxShaderConstantBlock *pixelLiteralConsts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ComparePixelConsts
==============
*/
int R_ComparePixelConsts(const Material **material, const MaterialPass **pass)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

