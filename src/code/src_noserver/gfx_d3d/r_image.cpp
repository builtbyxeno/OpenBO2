#include "types.h"
#include "vars.h"
#include <qcommon/qcommon_public.h>
#include <gfx_d3d/gfx_d3d_public.h>

GfxImage g_imageProgs[59];
int Image_TrackBytes;

struct {
	GfxImage* imageHashTable[2048];
	int picmip;
	int picmipBump;
	int picmipSpec;
	CardMemory totalMemory;
} imageGlobals;

const char* imageTypeName[10] =
{
  "misc  ",
  "debug ",
  "$tex+?",
  "ui    ",
  "lmap  ",
  "light ",
  "f/x   ",
  "hud   ",
  "model ",
  "world "
};

const char* g_imageProgNames[59] =
{
  "$shadowmap_sun",
  "$shadowmap_spot",
  "$floatz",
  "$post_effect_src",
  "$post_effect_0",
  "$post_effect_1",
  "$pingpong_0",
  "$pingpong_1",
  "$resolved_scene",
  "$scene",
  "$savedscreen",
  "$scene_depth",
  "$raw",
  "$ssao_csz",
  "$ssao_csz_0",
  "$ssao_csz_1",
  "$ssao_csz_2",
  "$ssao_csz_3",
  "$ssao_csz_4",
  "$ssao_csz_5",
  "$ssao_1",
  "$ssao_2",
  "$txaa_feedback",
  "$txaa_srgb",
  "$txaa_srgb_scene",
  "$model_lighting",
  "$lut",
  "$ui3d",
  "$ui3d_ping_pong",
  "$missilecam",
  "$floatz_missilecam",
  "$missilecammulti0",
  "$missilecammulti1",
  "$missilecammulti2",
  "$missilecammulti3",
  "$sonar",
  "$sonar_blur",
  "$sonar_depth",
  "$composite",
  "$dof_scene_mask_ping",
  "$dof_scene_mask_pong",
  "$dof_scene_fp16",
  "$dof_scene_fp16_0",
  "$dof_scene_fp16_1",
  "$dof_scene_fp16_2",
  "$dof_scene_fp16_3",
  "$dof_scene_fp16_4",
  "$dof_scene_fp16_5",
  "$dof_scene_final",
  "$bloom_mip1_ping",
  "$bloom_mip1_pong",
  "$bloom_mip2_ping",
  "$bloom_mip3_ping",
  "$bloom_mip3_ping",
  "$bloom_mip3_pong",
  "$bloom_mip4_ping",
  "$bloom_mip4_pong",
  "$bloom_streak1",
  "$lut2d"
};

/*
==============
TRACK_r_image
==============
*/
void TRACK_r_image()
{
	track_static_alloc_internal(g_imageProgs, sizeof(g_imageProgs), "g_imageProgs", 21);
	track_static_alloc_internal(imageTypeName, sizeof(imageTypeName), "imageTypeName", 21);
}

/*
==============
Image_TrackTotalMemory
==============
*/
void Image_TrackTotalMemory(GfxImage *image, int platform, int memory)
{
	if (image->track > 1u && image->track != 4)
	{
		imageGlobals.totalMemory.platform[platform] += memory - image->cardMemory.platform[platform];
	}
}

/*
==============
R_AddImageToList
==============
*/
void R_AddImageToList(XAssetHeader header, void *data)
{
	ImageList* imageList;

	imageList = (ImageList*)data;
	assert(imageList->count < ARRAY_COUNT(imageList->image));

	imageList->image[imageList->count++] = header.image;
}

/*
==============
R_GetImageList
==============
*/
void R_GetImageList(ImageList *imageList)
{
	assert(imageList);
	imageList->count = 0;
	DB_EnumXAssets(ASSET_TYPE_IMAGE, R_AddImageToList, imageList, 1);
}

/*
==============
Image_Release
==============
*/
void Image_Release(GfxImage *image)
{
	if (image->track > 1 && image->track != 4)
	{
		imageGlobals.totalMemory.platform[0] -= image->cardMemory.platform[0];
		imageGlobals.totalMemory.platform[1] -= image->cardMemory.platform[1];
	}
	if (image->texture.basemap)
	{
		image->texture.basemap->Release();
		image->texture.basemap = 0;
		image->cardMemory.platform[PICMIP_PLATFORM_USED] = 0;
		image->cardMemory.platform[PICMIP_PLATFORM_MINSPEC] = 0;
	}
	assert(!image->cardMemory.platform[PICMIP_PLATFORM_USED]);
	Image_TrackBytes -= image->loadedSize;
	image->loadedSize = 0;
	image->mapType = 0;
}

/*
==============
Image_GetAvailableHashLocation
==============
*/
int Image_GetAvailableHashLocation(const char *name)
{
	unsigned int stuck;
	int hashIndex;

	hashIndex = R_HashAssetName(name) & 0x7FF;

	for (stuck = 0; stuck <= 0x800; ++stuck)
	{
		if (!imageGlobals.imageHashTable[hashIndex])
		{
			break;
		}
		hashIndex = (hashIndex + 1) & 0x7FF;
	}

	return hashIndex;
}

/*
==============
Image_Construct
==============
*/
void Image_Construct(const char *name, int nameSize, unsigned __int8 category, unsigned __int8 semantic, int imageTrack, GfxImage *image)
{
	assert(name);
	assertMsg((nameSize > 0), "(nameSize) = %i", nameSize);
	assert(image);
	memcpy((char*)image->name, name, nameSize);
	assert(category != IMG_CATEGORY_UNKNOWN);

	image->category = category;
	image->semantic = semantic;

	assert(image->noPicmip == false);
	assert(image->picmip.platform[PICMIP_PLATFORM_USED] == 0);
	assert(image->picmip.platform[PICMIP_PLATFORM_MINSPEC] == 0);
	image->track = imageTrack;
}

/*
==============
Image_AllocProg
==============
*/
GfxImage *Image_AllocProg(int imageProgType, unsigned __int8 category, unsigned __int8 semantic)
{
	GfxImage* image;
	const char* name;

	image = &g_imageProgs[imageProgType];
	assert(image);
	name = g_imageProgNames[imageProgType];
	image->name = name;
	image->semantic = semantic;
	assert(category);
	image->category = category;
	image->track = 0;
	imageGlobals.imageHashTable[Image_GetAvailableHashLocation(name)] = image;
	return &g_imageProgs[imageProgType];
}

/*
==============
Image_GetProg
==============
*/
GfxImage *Image_GetProg(int imageProgType)
{
	assert(&g_imageProgs[imageProgType]);
	return &g_imageProgs[imageProgType];
}

/*
==============
Image_Alloc
==============
*/
GfxImage *Image_Alloc(const char *name, unsigned __int8 category, unsigned __int8 semantic, int imageTrack)
{
	unsigned int nameSize;
	GfxImage* image;

	assert(name);
	nameSize = strlen(name) + 1;
	image = (GfxImage*)Hunk_Alloc(nameSize + sizeof(GfxImage), "Image_Alloc", 25);

	assert(image);
	image->name = (const char*)(((char*)image) + sizeof(GfxImage));
	Image_Construct(name, nameSize, category, semantic, imageTrack, image);
	imageGlobals.imageHashTable[Image_GetAvailableHashLocation(name)] = image;

	return image;
}

/*
==============
Image_Create2DTexture_PC
==============
*/
void Image_Create2DTexture_PC(GfxImage *image, unsigned __int16 width, unsigned __int16 height, int mipmapCount, int imageFlags, DXGI_FORMAT imageFormat, void *initData)
{
	bool multisample;
	unsigned int multiSampleType;
	HRESULT hr;
	D3D11_SHADER_RESOURCE_VIEW_DESC viewDesc;
	ID3D11Texture2D* map;
	D3D11_TEXTURE2D_DESC desc;

	if ((imageFlags & 0x40000) == 0 || (multisample = 1, dx.multiSampleType <= 1))
	{
		multisample = 0;
	}
	assert(image);
	assert(image->texture.basemap);
	image->width = width;
	image->height = height;
	image->depth = 1;
	image->mapType = 3;
	memset(&desc, 0, sizeof(desc));
	desc.Width = width;
	multiSampleType = 1;
	desc.Height = height;
	desc.MipLevels = mipmapCount;
	desc.ArraySize = 1;
	if (imageFormat == DXGI_FORMAT_D32_FLOAT)
	{
		desc.Format = DXGI_FORMAT_R32_TYPELESS;
	}
	else if (imageFormat == DXGI_FORMAT_D24_UNORM_S8_UINT)
	{
		desc.Format = DXGI_FORMAT_R24G8_TYPELESS;
	}
	else
	{
		desc.Format = DXGI_FORMAT_R32G8X24_TYPELESS;
		if (imageFormat != DXGI_FORMAT_D32_FLOAT_S8X24_UINT)
		{
			desc.Format = imageFormat;
		}
	}
	if (multisample)
	{
		multiSampleType = dx.multiSampleType;
		desc.SampleDesc.Quality = dx.multiSampleQuality;
	}
	else
	{
		desc.SampleDesc.Quality = 0;
	}
	desc.SampleDesc.Count = multiSampleType;
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.BindFlags = 8;
	if ((imageFlags & 0x20000) != 0)
	{
		if (imageFormat == DXGI_FORMAT_D32_FLOAT || imageFormat == DXGI_FORMAT_D24_UNORM_S8_UINT || (desc.BindFlags = 40, imageFormat == DXGI_FORMAT_D32_FLOAT_S8X24_UINT))
		{
			desc.BindFlags = 72;
		}
	}
	while (1)
	{
		hr = dx.device->CreateTexture2D(&desc, (const D3D11_SUBRESOURCE_DATA*)initData, &map);
		if (hr < 0)
		{
			break;
		}
		else
		{
			++g_disableRendering;
			Com_Error(ERR_FATAL, __FILE__, " (%i) dx.device->CreateTexture2D(&desc, (D3D11_SUBRESOURCE_DATA*)initData, &map) failed: %s\n", __LINE__, R_ErrorDescription(hr));
		}
	}
	map->SetPrivateData(WKPDID_D3DDebugObjectName, strlen(image->name), image->name);
	memset(&viewDesc, 0, sizeof(viewDesc));
	switch (imageFormat)
	{
	case DXGI_FORMAT_D32_FLOAT:
		viewDesc.Format = DXGI_FORMAT_R32_FLOAT;
		break;
	case DXGI_FORMAT_D24_UNORM_S8_UINT:
		viewDesc.Format = DXGI_FORMAT_R24_UNORM_X8_TYPELESS;
		break;
	case DXGI_FORMAT_D32_FLOAT_S8X24_UINT:
		viewDesc.Format = DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS;
		break;
	case DXGI_FORMAT_R8G8B8A8_TYPELESS:
		viewDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		break;
	default:
		viewDesc.Format = desc.Format;
		break;
	}
	viewDesc.Buffer.NumElements = -1;
	viewDesc.ViewDimension = (D3D11_SRV_DIMENSION)(2 * multisample + 4);
	while (1)
	{
		hr = dx.device->CreateShaderResourceView(map, &viewDesc, &image->texture.basemap);
		if (hr < 0)
		{
			break;
		}
		else
		{
			++g_disableRendering;
			Com_Error(ERR_FATAL, __FILE__, " (%i) dx.device->CreateShaderResourceView(map, &viewDesc, &image->texture.basemap) failed: %s\n", __LINE__, R_ErrorDescription(hr));
		}
	}
	image->texture.basemap->SetPrivateData(WKPDID_D3DDebugObjectName, strlen(image->name), image->name);
	map->Release();
}

/*
==============
Image_Create3DTexture_PC
==============
*/
void Image_Create3DTexture_PC(GfxImage *image, unsigned __int16 width, unsigned __int16 height, unsigned __int16 depth, int mipmapCount, int imageFlags, DXGI_FORMAT imageFormat, void *initData)
{
	HRESULT hr;
	D3D11_SHADER_RESOURCE_VIEW_DESC viewDesc;
	ID3D11Texture3D* volmap;
	D3D11_TEXTURE3D_DESC desc; 

	assert(image);
	assert(!image->texture.basemap);

	image->width = width;
	image->height = height;
	image->depth = depth;
	desc.Width = width;
	desc.Height = height;
	image->mapType = 4;
	desc.MiscFlags = 0;
	desc.Depth = depth;
	desc.MipLevels = mipmapCount;
	desc.Format = imageFormat;
	desc.Usage = D3D11_USAGE_DYNAMIC;
	desc.BindFlags = 8;
	desc.CPUAccessFlags = 0x10000;

	while (1)
	{
		hr = dx.device->CreateTexture3D(&desc, (const D3D11_SUBRESOURCE_DATA*)initData, &volmap);
		if (hr < 0)
		{
			break;
		}
		else
		{
			Com_Error(ERR_FATAL, __FILE__, " (%i) dx.device->CreateTexture3D(&desc, (D3D11_SUBRESOURCE_DATA*)initData, &volmap) failed: %s\n", __LINE__, R_ErrorDescription(hr));
		}
	}

	volmap->SetPrivateData(WKPDID_D3DDebugObjectName, strlen(image->name), image->name);
	viewDesc.Buffer.FirstElement = 0;
	viewDesc.Texture3D.MipLevels = NULL;
	viewDesc.Texture3D.MostDetailedMip = NULL;
	viewDesc.Format = desc.Format;
	viewDesc.ViewDimension = D3D_SRV_DIMENSION_TEXTURE3D;
	viewDesc.Buffer.NumElements = mipmapCount;

	while (1)
	{
		hr = dx.device->CreateShaderResourceView(volmap, &viewDesc, &image->texture.basemap);
		if (hr < 0)
		{
			break;
		}
		else
		{
			Com_Error(ERR_FATAL, __FILE__, " (%i) dx.device->CreateShaderResourceView(volmap, &viewDesc, &image->texture.basemap) failed: %s\n", __LINE__, R_ErrorDescription(hr));
		}
	}
	image->texture.basemap->SetPrivateData(WKPDID_D3DDebugObjectName, strlen(image->name), image->name);
	volmap->Release();
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

