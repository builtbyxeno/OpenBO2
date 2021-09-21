#include "types.h"
#include "functions.h"

/*
==============
Image_GetPcStreamedMips
==============
*/
unsigned __int8 Image_GetPcStreamedMips(GfxImageFileHeader *fileHeader)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Image_GetPicmipUsed
==============
*/
int Image_GetPicmipUsed(const GfxImage *image)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Image_SetupFromFile
==============
*/
void Image_SetupFromFile(GfxImage *image, const GfxImageFileHeader *fileHeader, DXGI_FORMAT imageFormat, void *initData, unsigned int allocFlags, unsigned int *outStreamedSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_AllocTempMemory
==============
*/
unsigned __int8 *Image_AllocTempMemory(int bytes)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Image_FreeTempMemory
==============
*/
void Image_FreeTempMemory(unsigned __int8 *mem, int bytes)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_LoadBitmap
==============
*/
void Image_LoadBitmap(GfxImage *image, const GfxImageFileHeader *fileHeader, unsigned __int8 *data, DXGI_FORMAT format, int bytesPerPixel, int allocFlags, unsigned int *outStreamedSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_LoadDxtc
==============
*/
void Image_LoadDxtc(GfxImage *image, const GfxImageFileHeader *fileHeader, const unsigned __int8 *data, DXGI_FORMAT format, int bytesPerBlock, unsigned int allocFlags, unsigned int *outStreamedSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_LoadFromData
==============
*/
void __cdecl Image_LoadFromData(GfxImage *image, GfxImageFileHeader *fileHeader, unsigned __int8 *srcData, unsigned int allocFlags, unsigned int *outStreamedSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_LoadFromFileInternal
==============
*/
char Image_LoadFromFileInternal(const GfxImageFileHeader *a1, unsigned int a2, GfxImage *image)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Image_LoadFromFile
==============
*/
char __cdecl Image_LoadFromFile(GfxImage *image)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Image_Generate2D
==============
*/
void Image_Generate2D(GfxImage *image, unsigned __int8 *pixels, int width, int height, DXGI_FORMAT imageFormat)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_GenerateCube
==============
*/
void Image_GenerateCube(GfxImage *image, const unsigned __int8 *(*pixels)[15], int edgeLen, DXGI_FORMAT imageFormat, const unsigned int mipCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_LoadWhite
==============
*/
void Image_LoadWhite(GfxImage *image)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_LoadBlack
==============
*/
void Image_LoadBlack(GfxImage *image)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_LoadGray
==============
*/
void Image_LoadGray(GfxImage *image)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_LoadLinearGray
==============
*/
void Image_LoadLinearGray(GfxImage *image)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_LoadIdentityNormalMap
==============
*/
void Image_LoadIdentityNormalMap(GfxImage *image)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_LoadWhiteTransparent
==============
*/
void Image_LoadWhiteTransparent(GfxImage *image)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_LoadBlackTransparent
==============
*/
void Image_LoadBlackTransparent(GfxImage *image)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_LoadBuiltin
==============
*/
GfxImage *Image_LoadBuiltin(const char *name, unsigned __int8 semantic, int imageTrack)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Image_Load
==============
*/
GfxImage *__cdecl Image_Load(const char *name, int semantic, int imageTrack)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

