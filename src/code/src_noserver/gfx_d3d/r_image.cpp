#include "types.h"

/*
==============
TRACK_r_image
==============
*/
void TRACK_r_image()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_TrackTotalMemory
==============
*/
void Image_TrackTotalMemory(GfxImage *image, int platform, int memory)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddImageToList
==============
*/
void R_AddImageToList(XAssetHeader header, void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_GetImageList
==============
*/
void R_GetImageList(ImageList *imageList)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_Release
==============
*/
void Image_Release(GfxImage *image)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_GetAvailableHashLocation
==============
*/
int Image_GetAvailableHashLocation(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Image_Construct
==============
*/
void Image_Construct(const char *name, int nameSize, unsigned __int8 category, unsigned __int8 semantic, int imageTrack, GfxImage *image)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_AllocProg
==============
*/
GfxImage *Image_AllocProg(int imageProgType, unsigned __int8 category, unsigned __int8 semantic)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Image_GetProg
==============
*/
GfxImage *Image_GetProg(int imageProgType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Image_Alloc
==============
*/
GfxImage *__cdecl Image_Alloc(const char *name, const char *category, int semantic, int imageTrack)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Image_Create2DTexture_PC
==============
*/
void Image_Create2DTexture_PC(GfxImage *image, unsigned __int16 width, unsigned __int16 height, int mipmapCount, int imageFlags, DXGI_FORMAT imageFormat, void *initData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_Create3DTexture_PC
==============
*/
void Image_Create3DTexture_PC(GfxImage *image, unsigned __int16 width, unsigned __int16 height, unsigned __int16 depth, int mipmapCount, int imageFlags, DXGI_FORMAT imageFormat, void *initData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_CreateCubeTexture_PC
==============
*/
void Image_CreateCubeTexture_PC(GfxImage *image, unsigned __int16 edgeLen, int mipmapCount, DXGI_FORMAT imageFormat, void *initData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_SetupRenderTarget
==============
*/
void Image_SetupRenderTarget(GfxImage *image, unsigned __int16 width, unsigned __int16 height, DXGI_FORMAT imageFormat, const char *name, unsigned int allocFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_PicmipForSemantic
==============
*/
void Image_PicmipForSemantic(unsigned __int8 semantic, Picmip *picmip)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_AssignDefaultTexture
==============
*/
bool Image_AssignDefaultTexture(GfxImage *image)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_DelayLoadImage
==============
*/
void R_DelayLoadImage(XAssetHeader header)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_Texture
==============
*/
void Load_Texture(GfxImageLoadDef **remoteLoadDef, GfxImage *image)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Image_FindExisting_LoadObj
==============
*/
GfxImage *Image_FindExisting_LoadObj(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Image_FindExisting_FastFile
==============
*/
GfxImage *Image_FindExisting_FastFile(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Image_Register_LoadObj
==============
*/
GfxImage *Image_Register_LoadObj(const char *imageName, unsigned __int8 semantic, int imageTrack)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Image_Register_FastFile
==============
*/
GfxImage *Image_Register_FastFile(const char *imageName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Image_Register
==============
*/
GfxImage *Image_Register()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_EnumImages
==============
*/
void R_EnumImages(void (*func)(XAssetHeader, void *), void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
}

