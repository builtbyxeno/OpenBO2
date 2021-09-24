#include "types.h"

/*
==============
TRACK_r_screenshot
==============
*/
void TRACK_r_screenshot()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CubemapShotFlipVerticalBuffer
==============
*/
void R_CubemapShotFlipVerticalBuffer(unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CubemapShotWriteTargaHeader
==============
*/
void R_CubemapShotWriteTargaHeader(const int res, unsigned __int8 *fileBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CubemapShotCopyBufferToTarga
==============
*/
void R_CubemapShotCopyBufferToTarga(const unsigned __int8 *srcBuffer, unsigned __int8 *targa)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CubemapShotApplyFresnelToTarga
==============
*/
void R_CubemapShotApplyFresnelToTarga(const CubemapShot shotIndex, const float n0, const float n1, unsigned __int8 *targa)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CubemapShotWriteTargaFile
==============
*/
void R_CubemapShotWriteTargaFile(const char *filename, const CubemapShot shotIndex, const float n0, const float n1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_BeginCubemapShot
==============
*/
void R_BeginCubemapShot(const int pixelWidthHeight, const int pixelBorder)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SaveCubemapShot
==============
*/
void R_SaveCubemapShot(const char *filename, const CubemapShot shotIndex, const float n0, const float n1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CubemapLightingForDir
==============
*/
void R_CubemapLightingForDir(int a1, long double linearColors, vec3_t **a3, int width, int height, const vec3_t *dir, const vec3_t *baseColor, unsigned __int8 *pixel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CubemapLighting
==============
*/
void R_CubemapLighting(vec3_t **linearColors, int width, int height, const vec3_t *baseColor, unsigned __int8 **pixels)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CubemapShotExtractLinearLight
==============
*/
void R_CubemapShotExtractLinearLight(unsigned __int8 **pixels, int width, int height, vec3_t **linearColors)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LightingFromCubemapShots
==============
*/
void R_LightingFromCubemapShots(const vec3_t *baseColor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetBackBufferData
==============
*/
char R_GetBackBufferData(int a1, int x, int y, int width, int height, int bytesPerPixel, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_CubemapShotCopySurfaceToBuffer
==============
*/
void R_CubemapShotCopySurfaceToBuffer(unsigned __int8 *buffer, const int bufferSizeInBytes)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_CopyCubemapShot
==============
*/
void R_CopyCubemapShot(CubemapShot shotIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_EndCubemapShot
==============
*/
void R_EndCubemapShot(void *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

