#include "types.h"
#include "functions.h"

/*
==============
RB_VirtualToSceneRadius
==============
*/
void RB_VirtualToSceneRadius(float radius, float *radiusX, float *radiusY)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_GaussianFilterPoints1D
==============
*/
int RB_GaussianFilterPoints1D(float pixels, int srcRes, int dstRes, int tapLimit, float *tapOffsets, float *tapWeights)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RB_GenerateGaussianFilter1D
==============
*/
int *RB_GenerateGaussianFilter1D(int a1, float pixels, int *res, int axis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
RB_GenerateGaussianFilter2D
==============
*/
void RB_GenerateGaussianFilter2D(float radius, int srcWidth, int srcHeight, int dstWidth, int dstHeight, GfxImageFilterPass *filterPass)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_GenerateGaussianFilterChain
==============
*/
int RB_GenerateGaussianFilterChain(float radiusX, float radiusY, int srcWidth, int srcHeight, int dstWidth, int dstHeight, int passLimit, GfxImageFilterPass *filterPass)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RB_SetupFilterPass
==============
*/
void RB_SetupFilterPass(const GfxImageFilterPass *filterPass)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_FilterPingPong
==============
*/
void RB_FilterPingPong(const GfxImageFilter *filter, int passIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_FilterImage
==============
*/
void RB_FilterImage(int a1, GfxImageFilter *filter)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_GaussianFilterImage
==============
*/
void __cdecl RB_GaussianFilterImage(float radius, unsigned __int8 srcRenderTargetId, unsigned __int8 dstRenderTargetId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_GaussianFilter
==============
*/
void RB_GaussianFilter(float radiusX, float radiusY, unsigned __int8 srcRenderTargetId, unsigned __int8 dstRenderTargetId, unsigned __int8 tmpRenderTargetId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

