#include "types.h"
#include "functions.h"

/*
==============
R_ChangeDepthHackNearClip
==============
*/
void R_ChangeDepthHackNearClip(GfxCmdBufSourceState *source, unsigned int depthHackFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ChangeObjectPlacement_Core
==============
*/
void R_ChangeObjectPlacement_Core(GfxCmdBufSourceState *source, const GfxScaledPlacement *placement)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ChangeObjectPlacementRemote
==============
*/
void R_ChangeObjectPlacementRemote(GfxCmdBufSourceState *a1, const GfxScaledPlacement *a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DeriveViewMatrix
==============
*/
void R_DeriveViewMatrix(GfxCmdBufSourceState *source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DeriveWorldViewMatrix
==============
*/
void R_DeriveWorldViewMatrix(GfxCmdBufSourceState *source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DeriveProjectionMatrix
==============
*/
void R_DeriveProjectionMatrix(GfxCmdBufSourceState *source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DeriveViewProjectionMatrix
==============
*/
void R_DeriveViewProjectionMatrix(GfxCmdBufSourceState *source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DeriveWorldViewProjectionMatrix
==============
*/
void R_DeriveWorldViewProjectionMatrix(GfxCmdBufSourceState *source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DeriveShadowLookupMatrix
==============
*/
void R_DeriveShadowLookupMatrix(GfxCmdBufSourceState *source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GenerateWorldOutdoorLookupMatrix
==============
*/
void R_GenerateWorldOutdoorLookupMatrix(GfxCmdBufSourceState *source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DeriveCodeMatrix
==============
*/
void R_DeriveCodeMatrix(GfxCmdBufSourceState *source, GfxCodeMatrices *activeMatrices, unsigned int baseIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetCodeMatrix
==============
*/
const vec4_t *R_GetCodeMatrix(GfxCmdBufSourceState *source, unsigned int sourceIndex, unsigned int firstRow)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_GetTextureFromCode
==============
*/
const GfxImage *R_GetTextureFromCode(GfxCmdBufSourceState *source, unsigned int codeTexture, unsigned __int8 *samplerState, const Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_TextureFromCodeError
==============
*/
void R_TextureFromCodeError(const GfxCmdBufContext *context, unsigned int codeTexture)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_OverrideLightmapImage
==============
*/
GfxImage *R_OverrideLightmapImage(int dvar_integer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_SetReflectionProbe
==============
*/
void R_SetReflectionProbe(GfxCmdBufContext context, unsigned int reflectionProbeIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ChangeDepthRange
==============
*/
void R_ChangeDepthRange(GfxCmdBufState *state, GfxDepthRangeType depthRangeType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ChangeIndices
==============
*/
void R_ChangeIndices(GfxCmdBufPrimState *state, ID3D11Buffer *ib)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FlushStreamSources
==============
*/
void R_FlushStreamSources(GfxCmdBufPrimState *state, int firstStream, int lastStream)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ChangeStreamSource
==============
*/
void R_ChangeStreamSource(GfxCmdBufPrimState *state, int streamIndex, ID3D11Buffer *vb, unsigned int vertexOffset, unsigned int vertexStride)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DrawIndexedPrimitive
==============
*/
void R_DrawIndexedPrimitive(const GfxCmdBufState *state, GfxCmdBufPrimState *primState, const GfxDrawPrimArgs *args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_HW_CreateBlendState
==============
*/
ID3D11BlendState *R_HW_CreateBlendState(unsigned int stateBits0)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_HW_CreateDepthStencilState
==============
*/
ID3D11DepthStencilState *R_HW_CreateDepthStencilState(unsigned int stateBits1, unsigned __int8 stencilMask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_HW_CreateRasterizerState
==============
*/
ID3D11RasterizerState *R_HW_CreateRasterizerState(unsigned int stateBits0, unsigned int stateBits1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_DX11_ReleaseSamplerStates
==============
*/
void R_DX11_ReleaseSamplerStates()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetSampler
==============
*/
void R_SetSampler(GfxCmdBufContext context, unsigned int textureIndex, unsigned int samplerIndex, unsigned __int8 samplerState, const GfxImage *image)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_TextureOverride
==============
*/
void R_TextureOverride(const GfxBackEndData *data, GfxCmdBufContext context, unsigned int modelIndex, int textureOverride)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetViewport
==============
*/
void R_GetViewport(GfxCmdBufSourceState *source, GfxViewport *outViewport)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetViewport
==============
*/
void R_SetViewport(GfxCmdBufState *state, const GfxViewport *viewport)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetViewportStruct
==============
*/
void R_SetViewportStruct(GfxCmdBufSourceState *source, const GfxViewport *viewport)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetViewportStructNoOffset
==============
*/
void R_SetViewportStructNoOffset(GfxCmdBufSourceState *source, const GfxViewport *viewport)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetScissorStruct
==============
*/
void R_SetScissorStruct(GfxCmdBufSourceState *source, const GfxViewport *scissor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ClearScissorStruct
==============
*/
void R_ClearScissorStruct(GfxCmdBufSourceState *source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetScissor
==============
*/
char R_GetScissor(GfxCmdBufSourceState *source, GfxViewport *outScissor)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetScissor
==============
*/
void R_SetScissor(GfxCmdBufState *state, const GfxViewport *_scissor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ClearScissor
==============
*/
void R_ClearScissor(GfxCmdBufState *state)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetViewportValues
==============
*/
void R_SetViewportValues(GfxCmdBufSourceState *source, int x, int y, int width, int height)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetFullViewport
==============
*/
void R_SetFullViewport(GfxCmdBufSourceState *source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UpdateViewport
==============
*/
void R_UpdateViewport(GfxCmdBufSourceState *source, GfxViewport *viewport)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DisableSampler
==============
*/
void R_DisableSampler(GfxCmdBufState *state, unsigned int samplerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UnbindImage
==============
*/
void R_UnbindImage(GfxCmdBufState *state, const GfxImage *image)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetRenderTargetSize
==============
*/
void R_SetRenderTargetSize(GfxCmdBufSourceState *source, unsigned __int8 newTargetId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetRenderTarget
==============
*/
void R_SetRenderTarget(GfxCmdBufContext context, unsigned __int8 newTargetId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ClearRenderTargetForMultiGpu
==============
*/
void R_ClearRenderTargetForMultiGpu(GfxCmdBufContext context, unsigned __int8 targetId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ClearScreenInternal
==============
*/
void R_ClearScreenInternal(GfxCmdBufState *state, unsigned __int8 whichToClear, const vec4_t *color, float depth, int stencil)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ClearScreen
==============
*/
void R_ClearScreen(GfxCmdBufState *state, unsigned __int8 whichToClear, const vec4_t *color, float depth, int stencil)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DrawCall
==============
*/
void R_DrawCall(int a1, void (*callback)(const void *, GfxCmdBufContext, const GfxViewInfo *), const void *userData, GfxCmdBufSourceState *source, const GfxViewInfo *viewInfo, const GfxViewParms *viewParms, GfxCmdBuf *cmdBufEA)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetLightmap
==============
*/
void R_SetLightmap(GfxCmdBufContext context, unsigned int lmapIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ClearAllStreamSources
==============
*/
void R_ClearAllStreamSources(GfxCmdBufPrimState *state)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetMeshStream
==============
*/
void R_SetMeshStream(GfxCmdBufState *state, GfxMeshData *mesh)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_HW_SetBlendState
==============
*/
void R_HW_SetBlendState(GfxCmdBufState *state, unsigned int stateBits0)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_HW_FindDepthStencilState
==============
*/
ID3D11DepthStencilState *R_HW_FindDepthStencilState(unsigned int stateBits1, unsigned __int8 stencilMask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_HW_SetDepthStencilState
==============
*/
void R_HW_SetDepthStencilState(GfxCmdBufState *state, unsigned int stateBits1, unsigned __int8 stencilRef, unsigned __int8 stencilMask)
{
	UNIMPLEMENTED(__FUNCTION__);
}

