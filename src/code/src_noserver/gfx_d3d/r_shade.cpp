#include "types.h"

/*
==============
R_SetVertexShaderConstantFromLiteral
==============
*/
void R_SetVertexShaderConstantFromLiteral(GfxCmdBufState *state, unsigned int buffer, unsigned int offset, unsigned int size, const float *literal)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetPixelShaderConstantFromLiteral
==============
*/
void R_SetPixelShaderConstantFromLiteral(GfxCmdBufState *state, unsigned int buffer, unsigned int offset, unsigned int size, const float *literal)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetCodeConstant
==============
*/
const float *R_GetCodeConstant(const GfxCmdBufContext *context, unsigned int constant)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_SetVertexShaderConstantFromCode
==============
*/
void R_SetVertexShaderConstantFromCode(const GfxCmdBufContext *context, const MaterialShaderArgument *routingData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_IsPixelShaderConstantUpToDate
==============
*/
int R_IsPixelShaderConstantUpToDate(const GfxCmdBufContext *context, const MaterialShaderArgument *routingData)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetPixelShaderConstantFromCode
==============
*/
void R_SetPixelShaderConstantFromCode(unsigned int a1, const GfxCmdBufContext *context, const MaterialShaderArgument *routingData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetPassShaderPrimArguments
==============
*/
void R_SetPassShaderPrimArguments(const GfxCmdBufContext *context, unsigned int argCount, const MaterialShaderArgument *arg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetPassShaderObjectArguments
==============
*/
void R_SetPassShaderObjectArguments(const GfxCmdBufContext *context, unsigned int argCount, const MaterialShaderArgument *arg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetupPassPerPrimArgs
==============
*/
void R_SetupPassPerPrimArgs(GfxCmdBufContext context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetupPassPerObjectArgs
==============
*/
void __cdecl R_SetupPassPerObjectArgs(GfxCmdBufContext context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetPassPixelShaderStableArguments
==============
*/
void R_SetPassPixelShaderStableArguments(const GfxCmdBufContext *context, unsigned int argCount, const MaterialShaderArgument *arg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetPassVertexShaderStableArguments
==============
*/
void R_SetPassVertexShaderStableArguments(const GfxCmdBufContext *context, unsigned int argCount, const MaterialShaderArgument *arg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetupPassCriticalPixelShaderArgs
==============
*/
void __cdecl R_SetupPassCriticalPixelShaderArgs(GfxCmdBufContext context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetupPassVertexShaderArgs
==============
*/
void R_SetupPassVertexShaderArgs(GfxCmdBufContext context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetPixelSamplerFromMaterial
==============
*/
const MaterialTextureDef *R_SetPixelSamplerFromMaterial(const GfxCmdBufContext *context, const MaterialShaderArgument *arg, const MaterialTextureDef *texDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_SetPassShaderStableArguments
==============
*/
void __cdecl R_SetPassShaderStableArguments(const GfxCmdBufContext *context, unsigned int argCount, const MaterialShaderArgument *arg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetIndexDataIndexCount
==============
*/
int R_SetIndexDataIndexCount(GfxCmdBufState *state, const unsigned __int16 *indices, int indexCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetPixelShader
==============
*/
void R_SetPixelShader(GfxCmdBufState *state, const MaterialPixelShader *pixelShader)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetVertexShader
==============
*/
void R_SetVertexShader(GfxCmdBufState *state, const MaterialVertexShader *vertexShader)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UpdateVertexDecl
==============
*/
void R_UpdateVertexDecl(GfxCmdBufState *state)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetupPass
==============
*/
void R_SetupPass(GfxCmdBufContext context, unsigned int passIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetVertexData
==============
*/
int R_SetVertexData(GfxCmdBufState *state, const void *data, int vertexCount, int stride)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

