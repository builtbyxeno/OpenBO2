#include "types.h"
#include "functions.h"

/*
==============
Com_GetBspLumpCountForVersion
==============
*/
unsigned int Com_GetBspLumpCountForVersion(const int version)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_ValidateBspLumpData
==============
*/
const void *Com_ValidateBspLumpData(LumpType type, unsigned int offset, unsigned int length, unsigned int elemSize, unsigned int *count)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_GetBspLump
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Com_ReadLumpOutOfBspAtOffset
==============
*/
const void *Com_ReadLumpOutOfBspAtOffset(int h, LumpType type, unsigned int offset, unsigned int length, unsigned int elemSize, unsigned int *count)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_ReadLumpOutOfBsp
==============
*/
const void *Com_ReadLumpOutOfBsp(int h, LumpType type, unsigned int elemSize, unsigned int *count)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_LoadBspLump
==============
*/
const void *Com_LoadBspLump(const char *mapname, LumpType type, unsigned int elemSize, unsigned int *count)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_UnloadBspLump
==============
*/
void Com_UnloadBspLump(LumpType type)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_BspHasLump
==============
*/
/*BOOL Com_BspHasLump@<eax>(LumpType a1@<edx>, LumpType type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
Com_GetBspVersion
==============
*/
unsigned int Com_GetBspVersion()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_GetBspChecksum
==============
*/
unsigned int Com_GetBspChecksum()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_CheckVersionLumpCountError
==============
*/
bool Com_CheckVersionLumpCountError(int version)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_LoadBsp
==============
*/
void Com_LoadBsp(const char *filename)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_UnloadBsp
==============
*/
void Com_UnloadBsp()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_CleanupBsp
==============
*/
void Com_CleanupBsp()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_EntityString
==============
*/
/*const char *Com_EntityString@<eax>(LumpType a1@<edx>, char *a2@<ecx>, char *a3@<edi>, int *numEntityChars)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
Com_SaveLump
==============
*/
void Com_SaveLump(LumpType type, const void *newLump, unsigned int size, ComSaveLumpBehavior behavior)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GetHunkStringCopy
==============
*/
const char *Com_GetHunkStringCopy(const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_GetLightDefName
==============
*/
const char *Com_GetLightDefName(const char *defName, const ComPrimaryLight *primaryLights, unsigned int primaryLightCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_LoadWorld_FastFile
==============
*/
void Com_LoadWorld_FastFile(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_ShutdownWorld
==============
*/
void Com_ShutdownWorld()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_LoadPrimaryLights
==============
*/
void Com_LoadPrimaryLights(char *a1, LumpType a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_LoadWorld_LoadObj
==============
*/
void Com_LoadWorld_LoadObj(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_LoadWorld
==============
*/
void Com_LoadWorld()
{
	UNIMPLEMENTED(__FUNCTION__);
}

