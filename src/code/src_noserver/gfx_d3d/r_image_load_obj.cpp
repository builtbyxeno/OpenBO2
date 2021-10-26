#include "types.h"
#include "vars.h"
#include <gfx_d3d/gfx_d3d_public.h>
#include <qcommon/qcommon_public.h>
#include <qcommon/threads_interlock.h>

unsigned int s_imageLoadBytesUsed;
unsigned __int8* s_imageLoadBuf;
FastCriticalSection s_imageLoadLock;

const BuiltinImageConstructorTable constructorTable[40] =
{
  { "$white", &Image_LoadWhite },
  { "$black", &Image_LoadBlack },
  { "$blank", &Image_LoadBlackTransparent },
  { "$gray", &Image_LoadGray },
  { "$lineargray", &Image_LoadLinearGray },
  { "$lightmapintensity1", &Image_LoadLightmapIntensity<1> },
  { "$lightmapintensity2", &Image_LoadLightmapIntensity<2> },
  { "$lightmapintensity3", &Image_LoadLightmapIntensity<3> },
  { "$lightmapintensity4", &Image_LoadLightmapIntensity<4> },
  { "$lightmapintensity5", &Image_LoadLightmapIntensity<5> },
  { "$lightmapintensity6", &Image_LoadLightmapIntensity<6> },
  { "$lightmapintensity7", &Image_LoadLightmapIntensity<7> },
  { "$lightmapintensity8", &Image_LoadLightmapIntensity<8> },
  { "$lightmapintensity9", &Image_LoadLightmapIntensity<9> },
  { "$lightmapintensity10", &Image_LoadLightmapIntensity<10> },
  { "$lightmapintensity11", &Image_LoadLightmapIntensity<11> },
  { "$lightmapintensity12", &Image_LoadLightmapIntensity<12> },
  { "$lightmapintensity13", &Image_LoadLightmapIntensity<13> },
  { "$lightmapintensity14", &Image_LoadLightmapIntensity<14> },
  { "$lightmapintensity15", &Image_LoadLightmapIntensity<15> },
  { "$lightmapintensity16", &Image_LoadLightmapIntensity<17> },
  { "$lightmapintensity17", &Image_LoadLightmapIntensity<17> },
  { "$lightmapintensity18", &Image_LoadLightmapIntensity<18> },
  { "$lightmapintensity19", &Image_LoadLightmapIntensity<19> },
  { "$lightmapintensity20", &Image_LoadLightmapIntensity<21> },
  { "$lightmapintensity21", &Image_LoadLightmapIntensity<21> },
  { "$lightmapintensity22", &Image_LoadLightmapIntensity<23> },
  { "$lightmapintensity23", &Image_LoadLightmapIntensity<23> },
  { "$lightmapintensity24", &Image_LoadLightmapIntensity<25> },
  { "$lightmapintensity25", &Image_LoadLightmapIntensity<25> },
  { "$lightmapintensity26", &Image_LoadLightmapIntensity<28> },
  { "$lightmapintensity27", &Image_LoadLightmapIntensity<28> },
  { "$lightmapintensity28", &Image_LoadLightmapIntensity<28> },
  { "$lightmapintensity29", &Image_LoadLightmapIntensity<31> },
  { "$lightmapintensity30", &Image_LoadLightmapIntensity<31> },
  { "$lightmapintensity31", &Image_LoadLightmapIntensity<31> },
  { "$identitynormalmap", &Image_LoadIdentityNormalMap },
  { "$whitetransparent", &Image_LoadWhiteTransparent },
  { "$blacktransparent", &Image_LoadBlackTransparent },
  { "$outdoor", &R_GenerateOutdoorImage }
};



/*
==============
Image_GetPcStreamedMips
==============
*/
unsigned __int8 Image_GetPcStreamedMips(GfxImageFileHeader *fileHeader)
{
	int minDimension;
	char streamedMipLevels;

	streamedMipLevels = 0;
	if (!(fileHeader->flags & 0x10))
	{
		return 0;
	}
	if (fileHeader->flags & 0xC)
	{
		return 0;
	}

	minDimension = min(fileHeader->dimensions[1], fileHeader->dimensions[0]);

	for (; minDimension > 128; minDimension >>= 1)
	{
		++streamedMipLevels;
	}

	return streamedMipLevels;
}

/*
==============
Image_GetPicmipUsed
==============
*/
int Image_GetPicmipUsed(const GfxImage *image)
{
	return image->picmip.platform[!Dvar_GetBool(useFastFile)];
}

/*
==============
Image_SetupFromFile
==============
*/
void Image_SetupFromFile(GfxImage *image, const GfxImageFileHeader *fileHeader, DXGI_FORMAT imageFormat, void *initData)
{
	int depth;
	int height;
	int width;
	char picmip;

	assert(image);
	assert(fileHeader);

	picmip = image->picmip.platform[!IsFastFileLoad() ? 1 : 0];
	width = max(1, fileHeader->dimensions[0] >> picmip);
	height = max(1, fileHeader->dimensions[1] >> picmip);
	depth = max(1, fileHeader->dimensions[2] >> picmip);

	Image_Setup(image, width, height, depth, fileHeader->flags, imageFormat, initData);
	assert(image->cardMemory.platform[PICMIP_PLATFORM_USED] > 0);
}

/*
==============
Image_AllocTempMemory
==============
*/
unsigned __int8 *Image_AllocTempMemory(int bytes)
{
	unsigned char* mem;

	bytes = (bytes + 3) & ~3;
	if (bytes + s_imageLoadBytesUsed > 0x1000000)
	{
		Com_Error(ERR_DROP, "Needed to allocate at least %.1f MB to load images", (bytes + s_imageLoadBytesUsed) / (1.0f * 1024.0f * 1024.0f));
	}
	if (!s_imageLoadBuf)
	{
		s_imageLoadBuf = (unsigned char*)Z_VirtualAlloc(0x1000000, "Image_AllocTempMemory", 21);
		assert(s_imageLoadBuf);
	}

	mem = &s_imageLoadBuf[s_imageLoadBytesUsed];
	s_imageLoadBytesUsed += bytes;

	return mem;
}

/*
==============
Image_FreeTempMemory
==============
*/
void Image_FreeTempMemory(unsigned __int8 *mem, int bytes)
{
	bytes = (bytes + 3) & ~3;
	assert(mem + bytes == s_imageLoadBuf + s_imageLoadBytesUsed);
	s_imageLoadBytesUsed -= bytes;
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

int Image_TrackBytes;

/*
==============
Image_LoadFromData
==============
*/
void Image_LoadFromData(GfxImage *image, GfxImageFileHeader *fileHeader, unsigned __int8 *srcData, unsigned int allocFlags, unsigned int *outStreamedSize)
{
	image->loadedSize = fileHeader->fileSizeForPicmip[image->skippedMipLevels] - sizeof(GfxImageFileHeader);
	image->baseSize = fileHeader->fileSizeForPicmip[0] - sizeof(GfxImageFileHeader);
	Image_TrackBytes += image->loadedSize;
	image->texture.basemap = NULL;
	switch (fileHeader->format)
	{
	case 1u:
		Image_LoadBitmap(image, fileHeader, srcData, DXGI_FORMAT_R8G8B8A8_UNORM, 4, allocFlags, outStreamedSize);
		break;
	case 5u:
		Image_LoadBitmap(image, fileHeader, srcData, DXGI_FORMAT_A8_UNORM, 1, allocFlags, outStreamedSize);
		break;
	case 0xBu:
		Image_LoadDxtc(image, fileHeader, srcData, DXGI_FORMAT_BC1_UNORM, 8, allocFlags, outStreamedSize);
		break;
	case 0xCu:
		Image_LoadDxtc(image, fileHeader, srcData, DXGI_FORMAT_BC2_UNORM, 16, allocFlags, outStreamedSize);
		break;
	case 0xDu:
		Image_LoadDxtc(image, fileHeader, srcData, DXGI_FORMAT_BC3_UNORM, 16, allocFlags, outStreamedSize);
		break;
	case 0xEu:
		Image_LoadDxtc(image, fileHeader, srcData, DXGI_FORMAT_BC5_UNORM, 16, allocFlags, outStreamedSize);
		break;
	case 0x13u:
		Image_LoadDxtc(image, fileHeader, srcData, DXGI_FORMAT_R16G16B16A16_FLOAT, 128, allocFlags, outStreamedSize);
		break;
	default:
		AssertMsg(va("unhandled case: %d", fileHeader->format))
		break;
	}
}

/*
==============
Image_LoadFromFileInternal
==============
*/
char Image_LoadFromFileInternal(GfxImage *image)
{
	int fileLen;
	unsigned __int8* mem;
	unsigned __int8* tempmem;
	int readLen;
	unsigned int bytes;
	int n;
	int fileSize;
	int fileHandle;
	GfxImageFileHeader fileHeader;
	char filepath[64];

	assert(image);
	assert(image->category == IMG_CATEGORY_LOAD_FROM_FILE);
	assert(!image->texture.basemap);

	if (Com_sprintf(filepath, 64, "%s%s%s", "images/", image->name, ".iwi") < 0)
	{
		Com_PrintError(13, "ERROR: filename '%s' too long\n", filepath);
		return 0;
	}

	fileSize = FS_FOpenFileRead(filepath, &fileHandle);
	if (fileSize < 0)
	{
		Com_PrintError(13, "ERROR: image '%s' is missing\n", filepath);
		return 0;
	}
	if (FS_Read(&fileHeader, 64, fileHandle) != 64)
	{
		Com_PrintError(13, "ERROR: image '%s' is truncated.  Delete the file and run converter to fix.\n", filepath);
		FS_FCloseFile(fileHandle);
		return 0;
	}

	while (1)
	{
		if (fileHeader.tag[0] != 73 || fileHeader.tag[1] != 87 || fileHeader.tag[2] != 105)
		{
			Com_PrintError(13, "ERROR: image '%s' is not an IW image\n", filepath);
			FS_FCloseFile(fileHandle);
			return 0;
		}
		if (fileHeader.version != 27)
		{
			Com_PrintError(13, "ERROR: image '%s' is version %i but should be version %i\n", filepath, fileHeader.version, 27);
			FS_FCloseFile(fileHandle);
			return 0;
		}
		assert(fileHeader.fileSizeForPicmip[0]);
		if (fileHeader.fileSizeForPicmip[0] >= fileSize)
		{
			break;
		}

		if (FS_IsInCompressedIwd(fileHandle))
		{
			fileLen = fileHeader.fileSizeForPicmip[0] - 64;
			mem = Image_AllocTempMemory(fileHeader.fileSizeForPicmip[0] - 64);
			readLen = FS_Read(mem, fileLen, fileHandle);
			bytes = (fileLen + 3) & 0xFFFFFFFC;
			n = readLen;
			assert(&mem[bytes] == &s_imageLoadBuf[s_imageLoadBytesUsed])
			s_imageLoadBytesUsed -= bytes;
		}
		else
		{
			n = FS_Seek(fileHandle, fileHeader.fileSizeForPicmip[0], 2);
		}

		if (n < 0)
		{
			Com_PrintError(13, "ERROR: image '%s' is invalid. fileHeader.fileSizeForPicmip[0] != fileSize (%d != %d)\n", filepath, fileHeader.fileSizeForPicmip[0], fileSize);
			FS_FCloseFile(fileHandle);
			return 0;
		}

		fileSize -= fileHeader.fileSizeForPicmip[0];
		if (FS_Read(&fileHeader, 64, fileHandle) != 64)
		{
			Com_PrintError(13, "ERROR: image '%s' is truncated.  Delete the file and run converter to fix.\n", filepath);
			FS_FCloseFile(fileHandle);
			return 0;
		}
	}

	if ((fileHeader.flags & 3) != 0)
	{
		image->noPicmip = 1;
	}

	int headerDimensions;
	if (fileHeader.dimensions[1] >= fileHeader.dimensions[0])
	{
		headerDimensions = fileHeader.dimensions[0];
	}
	else
	{
		headerDimensions = fileHeader.dimensions[1];
	}
	if (headerDimensions < 32)
	{
		image->noPicmip = 1;
	}

	Image_GetPicmip(image, &image->picmip);
	image->streaming = (fileHeader.flags & 0x10) != 0;
	int picmipsize = fileHeader.fileSizeForPicmip[Image_GetPicmipUsed(image) > 0] - 64;
	tempmem = Image_AllocTempMemory(picmipsize);
	if (FS_Read(tempmem, picmipsize, fileHandle) == picmipsize)
	{
		FS_FCloseFile(fileHandle);
		image->streaming = Image_GetPcStreamedMips(&fileHeader) != 0;
		unsigned int imagesize;
		imagesize = fileHeader.fileSizeForPicmip[0] - 64;
		image->skippedMipLevels = 0;
		image->loadedSize = imagesize;
		image->baseSize = imagesize;
		Image_LoadFromData(image, &fileHeader, tempmem, 2u, 0);
		Image_FreeTempMemory(tempmem, picmipsize);
		return 1;
	}
	else
	{
		Com_PrintError(13, "ERROR: image '%s' is truncated.  Delete the file and run converter to fix.\n", filepath);
		Image_FreeTempMemory(tempmem, picmipsize);
		FS_FCloseFile(fileHandle);
		return 0;
	}

}

/*
==============
Image_LoadFromFile
==============
*/
char Image_LoadFromFile(GfxImage *image)
{
	bool ret;

	Sys_LockWrite(&s_imageLoadLock);
	ret = Image_LoadFromFileInternal(image);
	Sys_UnlockWrite(&s_imageLoadLock);
	return ret;
}

/*
==============
Image_Generate2D
==============
*/
void Image_Generate2D(GfxImage *image, unsigned __int8 *pixels, int width, int height, DXGI_FORMAT imageFormat)
{
	assert(pixels);
	Image_Setup(image, width, height, 1, 3, imageFormat, 0);
	assert(image->cardMemory.platform[PICMIP_PLATFORM_USED] > 0);
	Image_UploadData(image, imageFormat, D3D11_TEXTURECUBE_FACE_POSITIVE_X, 0, pixels);
}

/*
==============
Image_GenerateCube
==============
*/
void Image_GenerateCube(GfxImage *image, const unsigned __int8 *(*pixels)[15], int edgeLen, DXGI_FORMAT imageFormat, const unsigned int mipCount)
{
	D3D11_TEXTURECUBE_FACE face;
	unsigned int mipIndex;
	unsigned int faceIndex;
	unsigned char imageFlags;

	assert(pixels);
	assert(edgeLen > 0);
	assert(IsPowerOf2(edgeLen));
	assert(mipCount <= 15);

	imageFlags = 5;
	if (mipCount == 1)
	{
		imageFlags = 7;
	}

	Image_Setup(image, edgeLen, edgeLen, 1, imageFlags, imageFormat, 0);
	assert(image->cardMemory.platform[PICMIP_PLATFORM_USED] > 0);

	for (faceIndex = 0; faceIndex < 6; ++faceIndex)
	{
		face = Image_CubemapFace(faceIndex);
		for (mipIndex = 0; mipIndex < mipCount; ++mipIndex)
		{
			Image_UploadData(image, imageFormat, face, mipIndex, (&(*pixels)[15 * faceIndex])[mipIndex]);
		}
	}
}

/*
==============
Image_LoadWhite
==============
*/
void Image_LoadWhite(GfxImage *image)
{
	unsigned __int8 pixels[4];

	*pixels = 0xFFFFFFFF;
	Image_Generate2D(image, pixels, 1, 1, DXGI_FORMAT_R8G8B8A8_UNORM);
}

/*
==============
Image_LoadBlack
==============
*/
void Image_LoadBlack(GfxImage *image)
{
	unsigned __int8 pixels[4];

	*pixels = 0xFF000000;
	Image_Generate2D(image, pixels, 1, 1, DXGI_FORMAT_R8G8B8A8_UNORM);
}

/*
==============
Image_LoadGray
==============
*/
void Image_LoadGray(GfxImage *image)
{
	unsigned __int8 pixels[4];

	*pixels = 0x80808080;
	Image_Generate2D(image, pixels, 1, 1, DXGI_FORMAT_R8G8B8A8_UNORM);
}

/*
==============
Image_LoadLinearGray
==============
*/
void Image_LoadLinearGray(GfxImage *image)
{
	unsigned __int8 pixels[4];

	*pixels = 0x80B4B4B4;
	Image_Generate2D(image, pixels, 1, 1, DXGI_FORMAT_R8G8B8A8_UNORM);
}

/*
==============
Image_LoadIdentityNormalMap
==============
*/
void Image_LoadIdentityNormalMap(GfxImage *image)
{
	unsigned __int8 pixels[4];

	*pixels = 0x80FF8080;
	Image_Generate2D(image, pixels, 1, 1, DXGI_FORMAT_R8G8B8A8_UNORM);
}

/*
==============
Image_LoadWhiteTransparent
==============
*/
void Image_LoadWhiteTransparent(GfxImage *image)
{
	unsigned __int8 pixels[4];

	*pixels = 0xFFFFFF;
	Image_Generate2D(image, pixels, 1, 1, DXGI_FORMAT_R8G8B8A8_UNORM);
}

/*
==============
Image_LoadBlackTransparent
==============
*/
void Image_LoadBlackTransparent(GfxImage *image)
{
	unsigned __int8 pixels[4];

	*pixels = 0;
	Image_Generate2D(image, pixels, 1, 1, DXGI_FORMAT_R8G8B8A8_UNORM);
}

template<int S>
void Image_LoadLightmapIntensity(GfxImage* image)
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
	GfxImage* image;
	unsigned int tableIndex;

	for (tableIndex = 0; ; ++tableIndex)
	{
		if (tableIndex >= 0xC)
		{
			Com_PrintError(8, "ERROR: Unknown built-in image '%s'", name);
			return 0;
		}
		if (!strcmp(constructorTable[tableIndex].name, name))
		{
			break;
		}
	}
	image = Image_Alloc(name, 1, semantic, imageTrack);
	assert(image);

	constructorTable[tableIndex].LoadCallback(image);

	return image;
}

/*
==============
Image_Load
==============
*/
GfxImage *Image_Load(const char *name, int semantic, int imageTrack)
{
	GfxImage* image;

	if (*name == '$')
	{
		return Image_LoadBuiltin(name, semantic, imageTrack);
	}
	image = Image_Alloc(name, 3u, semantic, imageTrack);
	assert(image);
	assert(image->texture.basemap == 0);

	return Image_LoadFromFile(image) != 0 ? image : 0;
}

