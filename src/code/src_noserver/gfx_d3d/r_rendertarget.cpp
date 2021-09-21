#include "types.h"
#include "functions.h"

/*
==============
AssertUninitializedRenderTarget
==============
*/
void AssertUninitializedRenderTarget(const GfxRenderTarget *renderTarget)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AssignImageToRenderTargetDepthStencil
==============
*/
void R_AssignImageToRenderTargetDepthStencil(GfxRenderTarget *renderTarget, GfxImage *image, DXGI_FORMAT format)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AssignImageToRenderTargetColor
==============
*/
void R_AssignImageToRenderTargetColor(GfxRenderTarget *renderTarget, GfxImage *image, DXGI_FORMAT format)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitRenderTargetImage
==============
*/
void R_InitRenderTargetImage(int imageProgType, unsigned __int16 width, unsigned __int16 height, DXGI_FORMAT format, RenderTargetUsage usage, GfxRenderTarget *renderTarget, unsigned int allocFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitSizedRenderTargetImage
==============
*/
void R_InitSizedRenderTargetImage(int imageProgType, int fullscreenWidth, int fullscreenHeight, int picmip, DXGI_FORMAT format, RenderTargetUsage usage, GfxRenderTarget *renderTarget, unsigned int allocFlags, bool depthBindAsShaderResource)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitShadowmapRenderTarget
==============
*/
void R_InitShadowmapRenderTarget(int imageProgType, unsigned __int16 tileRes, unsigned __int16 tileRowCount, GfxRenderTarget *renderTarget, ShadowmapRTTiling tilingMethond)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_RenderTargetName
==============
*/
const char *R_RenderTargetName(unsigned __int8 renderTargetId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_InitExtraCamRenderTargets
==============
*/
void __cdecl R_InitExtraCamRenderTargets(unsigned int width, unsigned int height, unsigned int multiExtraCamWidth, unsigned int multiExtraCamHeight, int location)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ShutdownExtraCamRenderTargets
==============
*/
void R_ShutdownExtraCamRenderTargets()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitUI3DRenderTarget
==============
*/
void __cdecl R_InitUI3DRenderTarget(int width, int height, int location, bool allocatePingPongBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ShutdownUI3DRenderTarget
==============
*/
void R_ShutdownUI3DRenderTarget(bool freePingPongBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ResizeSunShadowmapRenderTarget_PC
==============
*/
void __cdecl R_ResizeSunShadowmapRenderTarget_PC()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ResizeSpotShadowmapRenderTarget_PC
==============
*/
void __cdecl R_ResizeSpotShadowmapRenderTarget_PC()
{
	UNIMPLEMENTED(__FUNCTION__);
}

