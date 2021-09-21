#include "types.h"
#include "functions.h"

/*
==============
R_HW_SetVertexShaderConstant
==============
*/
void R_HW_SetVertexShaderConstant(GfxCmdBufState *state, unsigned int buffer, unsigned int offset, const float *data, unsigned int size)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_HW_SetPixelShaderConstant
==============
*/
void R_HW_SetPixelShaderConstant(GfxCmdBufState *state, unsigned int buffer, unsigned int offset, const float *data, unsigned int size)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_HW_ForceSamplerState
==============
*/
void R_HW_ForceSamplerState(ID3D11DeviceContext *device, unsigned int samplerIndex, unsigned int samplerState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FlushDirtyConstantBuffers
==============
*/
void R_FlushDirtyConstantBuffers(GfxCmdBufPrimState *state)
{
	UNIMPLEMENTED(__FUNCTION__);
}

