#include "types.h"

/*
==============
R_SetInputCodeConstantFromVec4
==============
*/
inline void R_SetInputCodeConstantFromVec4(GfxCmdBufInput *input, unsigned int constant, const vec4_t *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetCodeConstant
==============
*/
inline void R_SetCodeConstant(GfxCmdBufSourceState *source, unsigned int constant, float x, float y, float z, float w)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UpdateCodeConstant
==============
*/
int R_UpdateCodeConstant(GfxCmdBufSourceState *source, unsigned int constant, float x, float y, float z, float w)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetCodeConstantFromVec4
==============
*/
inline void R_SetCodeConstantFromVec4(GfxCmdBufSourceState *source, unsigned int constant, const vec4_t *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UpdateCodeConstantFromVec4
==============
*/
int R_UpdateCodeConstantFromVec4(GfxCmdBufSourceState *source, unsigned int constant, const vec4_t *value)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetObjectPlacement
==============
*/
inline void R_SetObjectPlacement(GfxCmdBufSourceState *source, const GfxScaledPlacement *placement)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetState
==============
*/
inline void R_SetState(GfxCmdBufState *state, const GfxStateBits *stateBits, unsigned __int8 stencilRef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetStreamSource
==============
*/
inline void R_SetStreamSource(GfxCmdBufPrimState *primState, ID3D11Buffer *vb, unsigned int vertexOffset, unsigned int vertexStride)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_HW_SetRenderTarget
==============
*/
inline void R_HW_SetRenderTarget(GfxCmdBufState *state, unsigned __int8 newTargetId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetTripleStreamSource
==============
*/
inline void R_SetTripleStreamSource(GfxCmdBufPrimState *primState, ID3D11Buffer *vb0, unsigned int vertexOffset0, unsigned int vertexStride0, ID3D11Buffer *vb1, unsigned int vertexOffset1, unsigned int vertexStride1, ID3D11Buffer *vb2, unsigned int vertexOffset2, unsigned int vertexStride2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetDoubleStreamSource
==============
*/
inline void R_SetDoubleStreamSource(GfxCmdBufPrimState *primState, ID3D11Buffer *vb0, unsigned int vertexOffset0, unsigned int vertexStride0, ID3D11Buffer *vb1, unsigned int vertexOffset1, unsigned int vertexStride1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UpdateShadowLookupMatrix
==============
*/
inline void R_UpdateShadowLookupMatrix(GfxCmdBufSourceState *source, unsigned int shadowableLightIndex, const GfxMatrix *lookupMatrix)
{
	UNIMPLEMENTED(__FUNCTION__);
}

