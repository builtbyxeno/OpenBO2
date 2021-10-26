#include "types.h"
#include "vars.h"
#include <gfx_d3d/gfx_d3d_public.h>

/*
==============
Image_GetCardMemoryAmountForMipLevel
==============
*/
unsigned int Image_GetCardMemoryAmountForMipLevel(DXGI_FORMAT format, unsigned int mipWidth, unsigned int mipHeight, unsigned int mipDepth)
{
    switch (format)
    {
    case DXGI_FORMAT_R16G16B16A16_FLOAT:
    case DXGI_FORMAT_R16G16B16A16_UNORM:
        return 8 * mipDepth * mipHeight * mipWidth;
    case DXGI_FORMAT_R10G10B10A2_UNORM:
    case DXGI_FORMAT_R11G11B10_FLOAT:
    case DXGI_FORMAT_R8G8B8A8_TYPELESS:
    case DXGI_FORMAT_R8G8B8A8_UNORM:
    case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
    case DXGI_FORMAT_R16G16_FLOAT:
    case DXGI_FORMAT_R16G16_UNORM:
    case DXGI_FORMAT_D32_FLOAT:
    case DXGI_FORMAT_R32_FLOAT:
    case DXGI_FORMAT_D24_UNORM_S8_UINT:
        return 4 * mipDepth * mipHeight * mipWidth;
    case DXGI_FORMAT_D16_UNORM:
    case DXGI_FORMAT_B5G6R5_UNORM:
        return 2 * mipDepth * mipHeight * mipWidth;
    case DXGI_FORMAT_A8_UNORM:
        return mipDepth * mipHeight * mipWidth;
    case DXGI_FORMAT_BC1_UNORM:
        return 8 * mipDepth * ((mipHeight + 3) >> 2) * ((mipWidth + 3) >> 2);
    case DXGI_FORMAT_BC2_UNORM:
    case DXGI_FORMAT_BC3_UNORM:
    case DXGI_FORMAT_BC5_UNORM:
        return 16 * mipDepth * ((mipHeight + 3) >> 2) * ((mipWidth + 3) >> 2);
    default:
        AssertMsg(va("unhandled case: %d", format));
        return 0;
    }
}

/*
==============
Image_GetCardMemoryAmount
==============
*/
unsigned int Image_GetCardMemoryAmount(unsigned int imageFlags, DXGI_FORMAT format, unsigned int width, unsigned int height, unsigned int depth)
{
	unsigned int memory;

	memory = Image_GetCardMemoryAmountForMipLevel(format, width, height, depth);
	if (!(imageFlags & 2))
	{
		while (depth + height + width > 3)
		{
			width = max(1, width >> 1);
			height = max(1, height >> 1);
			depth = max(1, depth >> 1);
			memory += Image_GetCardMemoryAmountForMipLevel(format, width, height, depth);
		}
	}

	if (imageFlags & 4)
	{
		memory *= 6;
	}

	return memory;
}

/*
==============
Image_SourceBytesPerSlice_PC
==============
*/
int Image_SourceBytesPerSlice_PC(DXGI_FORMAT format, int width, int height)
{
    switch (format)
    {
    case DXGI_FORMAT_R8G8B8A8_UNORM:
    case DXGI_FORMAT_R32_FLOAT:
    case DXGI_FORMAT_D24_UNORM_S8_UINT:
        return 4 * height * width;
    case DXGI_FORMAT_D16_UNORM:
    case DXGI_FORMAT_B5G6R5_UNORM:
        return 2 * height * width;
    case DXGI_FORMAT_A8_UNORM:
        return height * width;
    case DXGI_FORMAT_BC1_UNORM:
        return 8 * ((height + 3) >> 2) * ((width + 3) >> 2);
    case DXGI_FORMAT_BC2_UNORM:
    case DXGI_FORMAT_BC3_UNORM:
    case DXGI_FORMAT_BC5_UNORM:
        return 16 * ((height + 3) >> 2) * ((width + 3) >> 2);
    default:
        AssertMsg(va("unhandled case: %d", format));
        return 0;
    }
}

/*
==============
Image_Upload2D_CopyDataBlock_PC
==============
*/
void Image_Upload2D_CopyDataBlock_PC(int width, int height, const unsigned __int8 *src, DXGI_FORMAT format, int dstPitch, unsigned __int8 *dst)
{
    int srcStride;
    int y;
    int dy;

    assert(src);
    assert(dst);

    switch (format)
    {
    case DXGI_FORMAT_R16G16B16A16_FLOAT:
    case DXGI_FORMAT_R16G16B16A16_UNORM:
    case DXGI_FORMAT_R8G8B8A8_UNORM:
    case DXGI_FORMAT_R16G16_UNORM:
    case DXGI_FORMAT_R32_FLOAT:
        srcStride = 4 * width;
        dy = 1;
        break;
    case DXGI_FORMAT_A8_UNORM:
        srcStride = width;
        dy = 1;
        break;
    case DXGI_FORMAT_BC1_UNORM:
        srcStride = 8 * ((width + 3) >> 2);
        dy = 4;
        break;
    case DXGI_FORMAT_BC2_UNORM:
    case DXGI_FORMAT_BC3_UNORM:
        srcStride = 16 * ((width + 3) >> 2);
        dy = 4;
        break;
    case DXGI_FORMAT_B5G6R5_UNORM:
        srcStride = 2 * width;
        dy = 1;
        break;
    default:
        AssertMsg(va("unhandled case: %d", format));
        return;
    }

    assertMsg(dstPitch >= srcStride, va("%i x %i: %i < %i", width, height, dstPitch, srcStride));

    if (dstPitch == srcStride)
    {
        memcpy(dst, (char*)src, srcStride * ((height - 1) / dy + 1));
    }
    else
    {
        for (y = 0; y < height; y += dy)
        {
            memcpy(dst, (char*)src, srcStride);
            dst += dstPitch;
            src += srcStride;
        }
    }
}

/*
==============
Image_Upload2D_CopyData_PC
==============
*/
void Image_Upload2D_CopyData_PC(const GfxImage *image, DXGI_FORMAT format, D3D11_TEXTURECUBE_FACE face, unsigned int mipLevel, const unsigned __int8 *src)
{
    int srcStride, dstResource;

    ID3D11Texture2D* texture;
    ID3D11Resource* resource;
    D3D11_TEXTURE2D_DESC desc;

    int width = max(1, image->width >> mipLevel);

    switch (format)
    {
    case DXGI_FORMAT_R16G16B16A16_FLOAT:
    case DXGI_FORMAT_R16G16B16A16_UNORM:
    case DXGI_FORMAT_R8G8B8A8_UNORM:
    case DXGI_FORMAT_R16G16_UNORM:
    case DXGI_FORMAT_R32_FLOAT:
        srcStride = 4 * width;
        break;
    case DXGI_FORMAT_A8_UNORM:
        srcStride = width;
        break;
    case DXGI_FORMAT_BC1_UNORM:
        srcStride = 8 * ((width + 3) >> 2);
        break;
    case DXGI_FORMAT_BC2_UNORM:
    case DXGI_FORMAT_BC3_UNORM:
        srcStride = 16 * ((width + 3) >> 2);
        break;
    case DXGI_FORMAT_B5G6R5_UNORM:
        srcStride = 2 * width;
        break;
    default:
        AssertMsg(va("unhandled case: %d", format));
        return;
    }

    image->texture.basemap->GetResource(&resource);
    texture = reinterpret_cast<ID3D11Texture2D*>(resource);
    texture->GetDesc(&desc);
    Sys_EnterCriticalSection(CRITSECT_DXCONTEXT);
    dx.context->UpdateSubresource(resource, mipLevel + face * desc.MipLevels, 0, src, srcStride, 0);
    Sys_LeaveCriticalSection(CRITSECT_DXCONTEXT);
    resource->Release();
}

/*
==============
Image_Upload3D_CopyData_PC
==============
*/
void Image_Upload3D_CopyData_PC(const GfxImage *image, DXGI_FORMAT format, unsigned int mipLevel, const unsigned __int8 *src)
{
    UINT subrc;
    int srcRowPitch;
    int sliceIndex;
    D3D11_MAPPED_SUBRESOURCE map;
    ID3D11Resource* resource;

    assert(image);
    assertMsg((image->mapType == MAPTYPE_3D), "(image->mapType) = %i", image->mapType);

    int width = max(1, image->width >> mipLevel);
    int height = max(1, image->height >> mipLevel);
    int depth = max(1, image->depth >> mipLevel);

    srcRowPitch = Image_SourceBytesPerSlice_PC(format, width, height);
    image->texture.basemap->GetResource(&resource);
    Sys_EnterCriticalSection(CRITSECT_DXCONTEXT);
    for (sliceIndex = 0; sliceIndex < depth; ++sliceIndex)
    {
        subrc = mipLevel + sliceIndex * image->levelCount;
        dx.context->Map(resource, subrc, D3D11_MAP_WRITE_DISCARD, 0, &map);
        Image_Upload2D_CopyDataBlock_PC(width, height, src, format, map.RowPitch, (unsigned char*)map.pData);
        dx.context->Unmap(resource, subrc);
        src += srcRowPitch;
    }
    Sys_LeaveCriticalSection(CRITSECT_DXCONTEXT);
    resource->Release();
}

/*
==============
Image_UploadData
==============
*/
void Image_UploadData(GfxImage *image, DXGI_FORMAT format, D3D11_TEXTURECUBE_FACE face, unsigned int mipLevel, const unsigned __int8 *src)
{
    if (image->mapType == MAPTYPE_3D)
    {
        Image_Upload3D_CopyData_PC(image, format, mipLevel, src);
    }
    else
    {
        Image_Upload2D_CopyData_PC(image, format, face, mipLevel, src);
    }
}

/*
==============
Image_CountMipmaps
==============
*/
unsigned int Image_CountMipmaps(unsigned int imageFlags, unsigned int width, unsigned int height, unsigned int depth)
{
    unsigned int mipCount;
    unsigned int mipRes;

    mipCount = 1;
    if ((imageFlags & 2) == 0)
    {
        for (mipRes = 1; mipRes < width || mipRes < height || mipRes < depth; mipRes *= 2)
        {
            ++mipCount;
        }
    }
    return mipCount;
}

/*
==============
Image_GetPicmip
==============
*/
void Image_GetPicmip(const GfxImage *image, Picmip *picmip)
{
    assert(image);
    assert(picmip);
    if (image->noPicmip)
    {
        picmip->platform[0] = 0;
        picmip->platform[1] = 0;
    }
    else
    {
        Image_PicmipForSemantic(image->semantic, picmip);
    }
}

/*
==============
Image_CubemapFace
==============
*/
D3D11_TEXTURECUBE_FACE Image_CubemapFace(unsigned int faceIndex)
{
    assertMsg((faceIndex < 6), "(faceIndex) = %i", faceIndex);
    return (D3D11_TEXTURECUBE_FACE)faceIndex;
}

/*
==============
Image_TrackTexture
==============
*/
void Image_TrackTexture(GfxImage *image, int imageFlags, DXGI_FORMAT format, int width, int height, int depth)
{
    unsigned int memory;
    int platform;

    for (platform = 0; platform < 2; ++platform)
    {
        if (imageFlags & 1)
        {
            memory = Image_GetCardMemoryAmount(imageFlags, format, width, height, depth);
        }
        else
        {
            width = max(1, width >> image->picmip.platform[platform]);
            height = max(1, height >> image->picmip.platform[platform]);
            depth = max(1, depth >> image->picmip.platform[platform]);
            memory = Image_GetCardMemoryAmount(imageFlags, format, width, height, depth);
        }

        assert(!image->cardMemory.platform[platform] || (image->cardMemory.platform[platform] == memory));
        if (!IsFastFileLoad())
        {
            Image_TrackTotalMemory(image, platform, memory);
        }
        image->cardMemory.platform[platform] = memory;
    }
}

/*
==============
Image_Setup
==============
*/
void Image_Setup(GfxImage *image, int width, int height, int depth, int imageFlags, DXGI_FORMAT imageFormat, void *initData)
{
    assert(image);
    image->width = width;
    image->height = height;
    image->depth = depth;
    if (Dvar_GetBool(r_loadForRenderer))
    {
        if ((imageFlags & 4) != 0)
        {
            Image_CreateCubeTexture_PC(image, image->width, (imageFlags >> 1) & 1, imageFormat, initData);
        }
        else if ((imageFlags & 8) != 0)
        {
            Image_Create3DTexture_PC(image, image->width, image->height, image->depth, (imageFlags >> 1) & 1, imageFlags, imageFormat, initData);
        }
        else
        {
            Image_Create2DTexture_PC(image, image->width, image->height, (imageFlags >> 1) & 1, imageFlags, imageFormat, initData);
        }
        Image_TrackTexture(image, imageFlags, imageFormat, width, height, depth);
        assert(!image->delayLoadPixels);
    }
}

/*
==============
Image_SetupAndLoad
==============
*/
void Image_SetupAndLoad(GfxImage *image, int width, int height, int depth, int imageFlags, DXGI_FORMAT imageFormat)
{
    Image_Setup(image, width, height, depth, imageFlags, imageFormat, 0);
}

