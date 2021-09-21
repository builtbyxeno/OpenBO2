#include "types.h"
#include "functions.h"

/*
==============
Image_GetCardMemoryAmountForMipLevel
==============
*/
unsigned int Image_GetCardMemoryAmountForMipLevel(DXGI_FORMAT format, unsigned int mipWidth, unsigned int mipHeight, unsigned int mipDepth)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Image_GetCardMemoryAmount
==============
*/
unsigned int Image_GetCardMemoryAmount(unsigned int imageFlags, DXGI_FORMAT format, unsigned int width, unsigned int height, unsigned int depth)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Image_SourceBytesPerSlice_PC
==============
*/
int Image_SourceBytesPerSlice_PC(DXGI_FORMAT format, int width, int height)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Image_Upload2D_CopyDataBlock_PC
==============
*/
void Image_Upload2D_CopyDataBlock_PC(int width, int height, const unsigned __int8 *src, DXGI_FORMAT format, int dstPitch, unsigned __int8 *dst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_Upload2D_CopyData_PC
==============
*/
void Image_Upload2D_CopyData_PC(const GfxImage *image, DXGI_FORMAT format, D3D11_TEXTURECUBE_FACE face, unsigned int mipLevel, const unsigned __int8 *src)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_Upload3D_CopyData_PC
==============
*/
void Image_Upload3D_CopyData_PC(const GfxImage *image, DXGI_FORMAT format, unsigned int mipLevel, const unsigned __int8 *src)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_UploadData
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Image_CountMipmaps
==============
*/
unsigned int Image_CountMipmaps(unsigned int imageFlags, unsigned int width, unsigned int height, unsigned int depth)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Image_GetPicmip
==============
*/
void Image_GetPicmip(const GfxImage *image, Picmip *picmip)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_CubemapFace
==============
*/
unsigned int Image_CubemapFace(unsigned int faceIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Image_TrackTexture
==============
*/
void Image_TrackTexture(GfxImage *image, int imageFlags, DXGI_FORMAT format, int width, int height, int depth)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_Setup
==============
*/
void Image_Setup(GfxImage *image, int width, int height, int depth, int imageFlags, DXGI_FORMAT imageFormat, void *initData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_SetupAndLoad
==============
*/
void Image_SetupAndLoad(GfxImage *image, int width, int height, int depth, int imageFlags, DXGI_FORMAT imageFormat)
{
	UNIMPLEMENTED(__FUNCTION__);
}

