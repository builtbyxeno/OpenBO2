#include "types.h"

/*
==============
ScrPlace_GetView
==============
*/
ScreenPlacement *ScrPlace_GetView(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
ScrPlace_GetViewWritable
==============
*/
ScreenPlacement *ScrPlace_GetViewWritable(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
ScrPlace_GetViewUIContext
==============
*/
ScreenPlacement *ScrPlace_GetViewUIContext(const UIContextIndex_t contextIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
ScrPlace_GetViewUIContextWritable
==============
*/
ScreenPlacement *ScrPlace_GetViewUIContextWritable(const UIContextIndex_t contextIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
ScrPlace_HiResGetScaleY
==============
*/
double ScrPlace_HiResGetScaleY()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ScrPlace_CalcSafeAreaOffsets
==============
*/
vec2_t *ScrPlace_CalcSafeAreaOffsets(float *a1, float *a2, float viewportY, float viewportWidth, float horzAspectScale, float vertAspectScale, float safeAreaRatioHorz, float safeAreaRatioVert, float virtualViewableMin, float virtualViewableMax, vec2_t *a11, vec2_t *a12)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
ScrPlace_SetupFloatViewport
==============
*/
void ScrPlace_SetupFloatViewport(vec2_t *a1, vec2_t *a2, ScreenPlacement *scrPlace, float viewportX, float viewportY, float viewportWidth, float viewportHeight, float aspect, bool splitScreen)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ScrPlace_SetupViewport
==============
*/
void ScrPlace_SetupViewport(ScreenPlacement *scrPlace, int viewportX, int viewportY, int viewportWidth, int viewportHeight, float aspect, bool splitScreen)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ScrPlace_SetupUnsafeViewport
==============
*/
void ScrPlace_SetupUnsafeViewport(ScreenPlacement *scrPlace, int viewportX, int viewportY, int viewportWidth, int viewportHeight, float aspect, bool splitScreen)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ScrPlace_ApplyX
==============
*/
double ScrPlace_ApplyX(const ScreenPlacement *scrPlace, float x, int horzAlign)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ScrPlace_ApplyY
==============
*/
double ScrPlace_ApplyY(const ScreenPlacement *scrPlace, float y, int vertAlign)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ScrPlace_ApplyW
==============
*/
double ScrPlace_ApplyW(const ScreenPlacement *scrPlace, float w, int horzAlign)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ScrPlace_ApplyH
==============
*/
double ScrPlace_ApplyH(const ScreenPlacement *scrPlace, float h, int vertAlign)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ApplySplitscreenScaling
==============
*/
void ApplySplitscreenScaling(float *x, float *y, float *w, float *h, float hudSplitscreenScale)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ScrPlace_ApplyRect
==============
*/
void ScrPlace_ApplyRect(float *a1, const ScreenPlacement *scrPlace, float *x, float *y, float *w, float *h, int horzAlign, int vertAlign)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ScrPlace_SetLegacySplitscreenScaling
==============
*/
void ScrPlace_SetLegacySplitscreenScaling()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ScrPlace_SetNormalSplitscreenScaling
==============
*/
void ScrPlace_SetNormalSplitscreenScaling()
{
	UNIMPLEMENTED(__FUNCTION__);
}

