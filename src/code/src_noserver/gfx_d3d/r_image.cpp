#include "types.h"
#include "vars.h"
#include <qcommon/qcommon_public.h>
#include <gfx_d3d/gfx_d3d_public.h>
#include <database/database_public.h>

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
	HRESULT hr;
	D3D11_SHADER_RESOURCE_VIEW_DESC viewDesc;
	ID3D11Texture2D* cubemap;
	D3D11_TEXTURE2D_DESC desc;

	assert(image);
	assert(!image->texture.basemap);

	image->width = edgeLen;
	image->height = edgeLen;
	image->depth = 1;
	image->mapType = 5;
	memset(&desc, 0, sizeof(desc));
	desc.Width = edgeLen;
	desc.Height = edgeLen;
	desc.Format = imageFormat;
	desc.MipLevels = mipmapCount;
	desc.ArraySize = 6;
	desc.SampleDesc.Count = 1;
	desc.SampleDesc.Quality = 0;
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.BindFlags = 8;
	desc.MiscFlags = 4;

	while (1)
	{
		hr = dx.device->CreateTexture2D(&desc, (const D3D11_SUBRESOURCE_DATA*)initData, &cubemap);
		if (hr < 0)
		{
			break;
		}
		else
		{
			Com_Error(ERR_FATAL, __FILE__, " (%i) dx.device->CreateTexture2D(&desc, (D3D11_SUBRESOURCE_DATA*)initData, &cubemap) failed: %s\n", __LINE__, R_ErrorDescription(hr));
		}
	}

	cubemap->SetPrivateData(WKPDID_D3DDebugObjectName, strlen(image->name), image->name);
	viewDesc.Buffer.FirstElement = -1;
	viewDesc.Buffer.ElementOffset = 0;
	viewDesc.Texture3D.MipLevels = 0;
	viewDesc.Texture3D.MostDetailedMip = 0;
	viewDesc.Format = desc.Format;
	viewDesc.ViewDimension = D3D_SRV_DIMENSION_TEXTURECUBE;

	while (1)
	{
		hr = dx.device->CreateShaderResourceView(cubemap, &viewDesc, &image->texture.basemap);
		if (hr < 0)
		{
			break;
		}
		else
		{
			Com_Error(ERR_FATAL, __FILE__, " (%i) dx.device->CreateShaderResourceView(cubemap, &viewDesc, &image->texture.basemap) failed: %s\n", __LINE__, R_ErrorDescription(hr));
		}
	}
	image->texture.basemap->SetPrivateData(WKPDID_D3DDebugObjectName, strlen(image->name), image->name);
	cubemap->Release();
}

/*
==============
Image_SetupRenderTarget
==============
*/
void Image_SetupRenderTarget(GfxImage *image, unsigned __int16 width, unsigned __int16 height, DXGI_FORMAT imageFormat, const char *name, unsigned int allocFlags)
{
	assert(image);
	assert(image->semantic == TS_2D);

	if (!strcmp(image->name, "$scene"))
	{
		Image_SetupAndLoad(image, width, height, 1, 0x60003, imageFormat);
	}
	else if (!strcmp(image->name, "$ssao_csz") || !strcmp(image->name, "$dof_scene_fp16"))
	{
		Image_SetupAndLoad(image, width, height, 1, 0x30001, imageFormat);
	}
	else
	{
		Image_SetupAndLoad(image, width, height, 1, 0x20003, imageFormat);
	}
}

/*
==============
Image_PicmipForSemantic
==============
*/
void Image_PicmipForSemantic(unsigned __int8 semantic, Picmip *picmip)
{
	int picmipBump;

	switch (semantic)
	{
	case 0u:
	case 1u:
		picmip = nullptr;
		break;
	case 2u:
	case 0xAu:
	case 0xCu:
	case 0xDu:
	case 0xEu:
	case 0xFu:
	case 0x10u:
	case 0x11u:
	case 0x12u:
	case 0x13u:
	case 0x14u:
	case 0x15u:
	case 0x16u:
	case 0x17u:
	case 0x18u:
	case 0x19u:
	case 0x1Au:
	case 0x1Bu:
	case 0x1Cu:
		picmipBump = imageGlobals.picmip;
		picmip->platform[1] = 2;
		if (picmipBump >= 0)
		{
			if (picmipBump > 3)
			{
				picmipBump = 3;
			}
			picmip->platform[0] = picmipBump;
		}
		else
		{
			picmip->platform[0] = 0;
		}
		break;
	case 5u:
		picmipBump = imageGlobals.picmipBump;
		picmip->platform[1] = 2;
		if (picmipBump >= 0)
		{
			if (picmipBump > 3)
			{
				picmipBump = 3;
			}
			picmip->platform[0] = picmipBump;
		}
		else
		{
			picmip->platform[0] = 0;
		}
		break;
	case 8u:
		picmipBump = imageGlobals.picmipSpec;
		picmip->platform[1] = 2;
		if (picmipBump >= 0)
		{
			if (picmipBump > 3)
			{
				picmipBump = 3;
			}
			picmip->platform[0] = picmipBump;
		}
		else
		{
			picmip->platform[0] = 0;
		}
		break;
	default:
		AssertMsg(va("unhandled case: %d", semantic));
	}
}

/*
==============
R_DuplicateTexture
==============
*/
inline bool R_DuplicateTexture(GfxImage* dstImage, GfxImage* srcImage)
{
	if (!srcImage || !srcImage->texture.basemap)
	{
		return 0;
	}

	dstImage->texture.basemap = srcImage->texture.basemap;
	dstImage->texture.basemap->AddRef();

	return 1;
}

/*
==============
Image_AssignDefaultTexture
==============
*/
bool Image_AssignDefaultTexture(GfxImage *image)
{
	if (image->mapType != MAPTYPE_2D)
	{
		return false;
	}
	if (image->semantic == TS_NORMAL_MAP)
	{
		return R_DuplicateTexture(image, rgp.identityNormalMapImage);
	}

	if (image->semantic == TS_SPECULAR_MAP)
	{
		return R_DuplicateTexture(image, rgp.blackImage);
	}

	return R_DuplicateTexture(image, rgp.whiteImage);
}

/*
==============
R_DelayLoadImage
==============
*/
void R_DelayLoadImage(XAssetHeader header)
{
	GfxImage* image;
	int externalDataSize;

	image = header.image;

	if (image->delayLoadPixels)
	{
		image->delayLoadPixels = 0;

		externalDataSize = image->cardMemory.platform[PICMIP_PLATFORM_USED];
		image->cardMemory.platform[PICMIP_PLATFORM_USED] = 0;
		image->cardMemory.platform[PICMIP_PLATFORM_MINSPEC] = 0;

		if (Dvar_GetBool(r_loadForRenderer) && !Image_LoadFromFile(image))
		{
			Image_AssignDefaultTexture(image);
		}
		DB_LoadedExternalData(externalDataSize);
	}
}

/*
==============
Load_Texture
==============
*/
void Load_Texture(GfxImageLoadDef **remoteLoadDef, GfxImage *image)
{
	int width;
	int height;
	int depth;
	int faceCount;
	int faceIndex;
	int mipCount;
	int mipLevel;
	int externalDataSize;
	const unsigned char* data;
	GfxImageLoadDef* loadDef;
	DXGI_FORMAT format;
	D3D11_SUBRESOURCE_DATA initData[64];

	loadDef = *remoteLoadDef;
	assert(loadDef == image->texture.loadDef);
	image->texture.basemap = NULL;

	if (Dvar_GetBool(r_loadForRenderer))
	{
		format = static_cast<DXGI_FORMAT>(loadDef->format);
		if (loadDef->resourceSize)
		{
			image->delayLoadPixels = 0;
			if (image->mapType == MAPTYPE_2D)
			{
				faceCount = 1;
			}
			else if (image->mapType == MAPTYPE_3D)
			{
				faceCount = 1;
			}

			data = loadDef->data;
			mipCount = Image_CountMipmaps(loadDef->flags, image->width, image->height, image->depth);
			for (faceIndex = 0; faceIndex < faceCount; ++faceIndex)
			{
				if (faceCount != 1)
				{
					Image_CubemapFace(faceIndex);
				}
				for (mipLevel = 0; mipLevel < mipCount; ++mipLevel)
				{
					width = max(1, image->width >> mipLevel);
					height = max(1, image->height >> mipLevel);
					depth = max(1, image->depth >> mipLevel);
					initData[mipCount * faceIndex].pSysMem = data;
					initData[mipCount * faceIndex].SysMemPitch = Image_GetCardMemoryAmountForMipLevel(format, width, 1u, 1u);
					data += Image_GetCardMemoryAmountForMipLevel(format, width, height, depth);
				}
			}
			assert((data) == (&loadDef->data[loadDef->resourceSize]));

			if (image->mapType == MAPTYPE_2D)
			{
				Image_Create2DTexture_PC(image, image->width, image->height, loadDef->levelCount, 0, format, initData);
			}
			else if (image->mapType == MAPTYPE_3D)
			{
				Image_Create3DTexture_PC(image, image->width, image->height, image->depth, loadDef->levelCount, 0, format, initData);
			}
			else
			{
				assert((image->mapType == MAPTYPE_CUBE));
				Image_CreateCubeTexture_PC(image, image->width, loadDef->levelCount, format, initData);
			}
		}
		else
		{
			assertMsg((static_cast<uint>(image->cardMemory.platform[PICMIP_PLATFORM_USED])
				== Image_GetCardMemoryAmount(loadDef->flags, static_cast<DXGI_FORMAT>(loadDef->format),
					image->width, image->height, image->depth)),
				"(image->name) = %s", image->name);
			assertMsg((image->texture.basemap == 0), "(image->name) = %s", image->name);

			externalDataSize = image->cardMemory.platform[PICMIP_PLATFORM_USED];
			image->delayLoadPixels = 0;
			image->cardMemory.platform[PICMIP_PLATFORM_USED] = 0;
			image->cardMemory.platform[PICMIP_PLATFORM_MINSPEC] = 0;
			if (!Image_LoadFromFile(image))
			{
				Com_Error(ERR_DROP, "Couldn't load image '%s'\n", image->name);
			}
			DB_LoadedExternalData(externalDataSize);
		}
	}
}

/*
==============
Image_IsProg
==============
*/
inline bool Image_IsProg(GfxImage* image)
{
	return image >= g_imageProgs && image < &g_imageProgs[ARRAY_COUNT(g_imageProgs) - 1];
}

/*
==============
Image_FindExisting_LoadObj
==============
*/
GfxImage *Image_FindExisting_LoadObj(const char *name)
{
	GfxImage* image;
	unsigned int stuck;
	int hashIndex;
	char error_string[256];

	hashIndex = R_HashAssetName(name) & 0x7FF;
	image = imageGlobals.imageHashTable[hashIndex];
	stuck = 0;
	while (image && strcmp(name, image->name))
	{
		hashIndex = (hashIndex + 1) & 0x7FF;
		image = imageGlobals.imageHashTable[hashIndex];
		if (++stuck > 0x800)
		{
			sprintf(error_string, "stuck %s name %x\n", name, hashIndex);
			Com_Printf(CON_CHANNEL_SYSTEM, "%s", error_string);
			return Image_IsProg(image) == 0 ? image : NULL;
		}
	}
	return Image_IsProg(image) == 0 ? image : NULL;
}

/*
==============
Image_FindExisting_FastFile
==============
*/
GfxImage *Image_FindExisting_FastFile(const char *name)
{
	return DB_FindXAssetHeader(ASSET_TYPE_IMAGE, name, true, -1).image;
}

/*
==============
Image_FindExisting
==============
*/
inline GfxImage* Image_FindExisting(const char* name)
{
	if (IsFastFileLoad())
	{
		return Image_FindExisting_FastFile(name);
	}

	return Image_FindExisting_LoadObj(name);
}

/*
==============
Image_Register_LoadObj
==============
*/
GfxImage *Image_Register_LoadObj(const char *imageName, unsigned __int8 semantic, int imageTrack)
{
	GfxImage* image;

	image = Image_FindExisting(imageName);
	if (image)
	{
		return image;
	}

	ProfLoad_Begin("Load image");
	image = Image_Load(imageName, semantic, imageTrack);
	ProfLoad_End();
	if (!image)
	{
		Com_PrintError(8, "ERROR: failed to load image '%s'\n", imageName);
	}

	return image;
}

/*
==============
Image_Register_FastFile
==============
*/
GfxImage *Image_Register_FastFile(const char *imageName)
{
	return Image_FindExisting(imageName);
}

/*
==============
Image_Register
==============
*/
GfxImage* Image_Register(const char* imageName, char semantic, int imageTrack)
{
	if (IsFastFileLoad())
	{
		return Image_Register_FastFile(imageName);
	}

	return Image_Register_LoadObj(imageName, semantic, imageTrack);
}

/*
==============
R_EnumImages
==============
*/
void R_EnumImages(void (*func)(XAssetHeader, void *), void *data)
{
	XAssetHeader header;
	unsigned int imageIndex;

	for (imageIndex = 0; imageIndex < 0x800; ++imageIndex)
	{
		header.image = imageGlobals.imageHashTable[imageIndex];
		if (header.image)
		{
			if (!Image_IsProg(header.image))
			{
				func(header, data);
			}
		}
	}
}

