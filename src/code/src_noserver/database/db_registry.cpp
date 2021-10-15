#include "types.h"
#include "vars.h"
#include <win32/win32_public.h>
#include <qcommon/qcommon_public.h>

/*
==============
TRACK_db_registry
==============
*/
void TRACK_db_registry()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_InitSingleton
==============
*/
void DB_InitSingleton(void *pool, int size)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_RemoveXModel
==============
*/
void DB_RemoveXModel(XAssetHeader header)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_RemoveFX
==============
*/
void DB_RemoveFX(XAssetHeader header)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_RemoveMaterial
==============
*/
void DB_RemoveMaterial(XAssetHeader header)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_RemoveTechniqueSet
==============
*/
void DB_RemoveTechniqueSet(XAssetHeader header)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_RemoveImage
==============
*/
void DB_RemoveImage(XAssetHeader header)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_RemoveSound
==============
*/
void DB_RemoveSound(XAssetHeader header)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_RemoveSndDriverGlobals
==============
*/
void DB_RemoveSndDriverGlobals(XAssetHeader header)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_RemoveSoundPatch
==============
*/
void DB_RemoveSoundPatch(XAssetHeader header)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_RemoveClipMap
==============
*/
void __cdecl DB_RemoveClipMap()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_RemoveComWorld
==============
*/
void __cdecl DB_RemoveComWorld()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_RemoveGfxWorld
==============
*/
void __cdecl DB_RemoveGfxWorld()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_DynamicCloneMenu
==============
*/
void DB_DynamicCloneMenu(const XAssetHeader from, XAssetHeader to, DBCloneMethod cloneMethod)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_RemoveKeyValuePairs
==============
*/
void DB_RemoveKeyValuePairs(XAssetHeader header)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_CompareReorderEntries
==============
*/
char DB_CompareReorderEntries(const DBReorderAssetEntry *e0, const DBReorderAssetEntry *e1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_SetReorderIncludeSequence
==============
*/
void DB_SetReorderIncludeSequence()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_AddReorderAsset
==============
*/
void DB_AddReorderAsset(const char *typeString, const char *assetName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_NextZoneCsvToken
==============
*/
char DB_NextZoneCsvToken(const char **parse, char *token, unsigned int tokenSize, bool allowNewLine)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_BeginReorderZone
==============
*/
void DB_BeginReorderZone(const char *zoneName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_PrintAssetName
==============
*/
void DB_PrintAssetName(XAssetHeader header, void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_MarkAssetTypeUsageDirty
==============
*/
void DB_MarkAssetTypeUsageDirty()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_GetAssetTypeUsageInfo
==============
*/
void DB_GetAssetTypeUsageInfo(XAssetType assetType, const char **outName, int *outUsed, int *outPool)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_PrintXAssetsForType_FastFile
==============
*/
void DB_PrintXAssetsForType_FastFile(XAssetType type, void *inData, bool includeOverride)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_AllocXAssetHeader
==============
*/
XAssetHeader DB_AllocXAssetHeader(XAssetType type)
{
	UNIMPLEMENTED(__FUNCTION__);
	XAssetHeader tmp;
	return tmp;
}

/*
==============
DB_Init
==============
*/
unsigned int DB_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_AllocXAssetEntry
==============
*/
XAssetEntry *DB_AllocXAssetEntry(XAssetType type, unsigned int zoneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DB_FreeXAssetEntry
==============
*/
void DB_FreeXAssetEntry(XAssetEntry *assetEntry)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_LogMissingAsset
==============
*/
void DB_LogMissingAsset(int a1, XAssetType type, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_EnumXAssets_FastFile
==============
*/
void DB_EnumXAssets_FastFile(XAssetType type, void (*func)(XAssetHeader, void *), void *inData, bool includeOverride)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_EnumXAssetsTimeout_FastFile
==============
*/
char DB_EnumXAssetsTimeout_FastFile(XAssetType type, void (*func)(XAssetHeader, void *), void *inData, bool includeOverride, int msec)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_LoadDelayedImages
==============
*/
void DB_LoadDelayedImages()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_CloneXAsset
==============
*/
void DB_CloneXAsset(const XAsset *from, XAsset *to, DBCloneMethod cloneMethod)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_SwapXAsset
==============
*/
void DB_SwapXAsset(XAsset *from, XAsset *to)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_DelayedCloneXAsset
==============
*/
void DB_DelayedCloneXAsset(XAssetEntry *newEntry)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_FindXAssetEntry
==============
*/
XAssetEntry *DB_FindXAssetEntry(XAssetType type, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DB_FindXAssetDefaultHeaderInternal
==============
*/
XAssetHeader DB_FindXAssetDefaultHeaderInternal(XAssetType a1, XAssetType type)
{
	UNIMPLEMENTED(__FUNCTION__);
	XAssetHeader tmp;
	return tmp;
}

/*
==============
DB_CreateDefaultEntry
==============
*/
XAssetEntry *DB_CreateDefaultEntry(XAssetType type, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DB_ListDefaultEntries_f
==============
*/
void DB_ListDefaultEntries_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_ListAssetPool
==============
*/
void DB_ListAssetPool(XAssetType type)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_ListAssetPool_f
==============
*/
void DB_ListAssetPool_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_DumpMaterialList_f
==============
*/
void DB_DumpMaterialList_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_DumpModels_f
==============
*/
void DB_DumpModels_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IsConfigFile
==============
*/
bool IsConfigFile(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PrintWaitedError
==============
*/
void PrintWaitedError(XAssetType type, const char *name, int waitedMsec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_DoesXAssetExist
==============
*/
char DB_DoesXAssetExist(XAssetType type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_DoesXAssetExist
==============
*/
char DB_DoesXAssetExist(const char *typeName, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_SetInitializing
==============
*/
void DB_SetInitializing(bool inUse)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_IsXAssetDefault
==============
*/
bool DB_IsXAssetDefault(XAssetType a1, XAssetType type, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_GetAllXAssetOfType_FastFile
==============
*/
int DB_GetAllXAssetOfType_FastFile(XAssetType type, XAssetHeader *assets, int maxCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_SyncLostDevice
==============
*/
void DB_SyncLostDevice()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_GetZonePriority
==============
*/
int DB_GetZonePriority(int zone)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_OverrideAsset
==============
*/
int DB_OverrideAsset(unsigned int newZoneIndex, unsigned int existingZoneIndex, XAssetType type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_LinkXAssetEntry
==============
*/
XAssetEntry *DB_LinkXAssetEntry(XAssetEntry *newEntry, int allowOverride)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DB_EnableInUseCache
==============
*/
void DB_EnableInUseCache(unsigned __int16 *data)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_GetXAsset
==============
*/
void DB_GetXAsset(XAssetType type, XAssetHeader header)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_BuildOSPath
==============
*/
void DB_BuildOSPath(const char *zoneName, const char *ext, int size, char *filename)
{
	const char* Language;

	Com_sprintf(filename, size, "%s\\zone\\%s\\%s%s", Sys_DefaultInstallPath(), Win_GetLanguage(), zoneName, ext);
}

/*
==============
DB_BuildOSPath_FromSource
==============
*/
void DB_BuildOSPath_FromSource(const char *zoneName, FF_DIR source, int size, char *filename)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_LoadXZone
==============
*/
void DB_LoadXZone(XZoneInfo *zoneInfo, unsigned int zoneCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_PostLoadPerXZone
==============
*/
int DB_PostLoadPerXZone()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_UpdateDebugZone
==============
*/
void DB_UpdateDebugZone(int a1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_LoadZone_f
==============
*/
void DB_LoadZone_f(int a1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_IsZoneLoaded
==============
*/
char DB_IsZoneLoaded(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_IsZoneTypeLoading
==============
*/
bool DB_IsZoneTypeLoading(int zoneType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_IsZoneTypeLoaded
==============
*/
char DB_IsZoneTypeLoaded(int zoneType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_IsZoneTypeComplete
==============
*/
char DB_IsZoneTypeComplete(int zoneType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_ZoneLoadsOverlays
==============
*/
char DB_ZoneLoadsOverlays(const char *zoneName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_CompareLoadXZoneInfos
==============
*/
char DB_CompareLoadXZoneInfos(const XZoneInfo *zone0, const XZoneInfo *zone1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_TryLoadXFileInternal
==============
*/
int DB_TryLoadXFileInternal(const char *zoneName, int zoneFlags, int requiredVersion, const char *contentDir)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_InitFastFileNames
==============
*/
void DB_InitFastFileNames()
{
	I_strncpyz(CODE_PRE_GFX_FAST_FILE_NAME, "code_pre_gfx", 24);
	I_strncpyz(CODE_FAST_FILE_NAME, "code_post_gfx", 24);
	I_strncpyz(CODE_FAST_FILE_RES_NAME, "code_post_gfx", 24);
	I_strncpyz(DEV_FAST_FILE_NAME, "dev", 24);
	I_strncpyz(PATCH_FAST_FILE_NAME, "patch", 24);
	I_strncpyz(LOC_PATCH_FAST_FILE_NAME, "patch_loc", 24);
	I_strncpyz(LOC_PATCH_UI_FAST_FILE_NAME, "patch_ui_loc", 24);
	I_strncpyz(PATCH_UI_FAST_FILE_NAME, "patch_ui", 24);
	I_strncpyz(UI_FAST_FILE_NAME, "ui", 24);
	I_strncpyz(COMMON_FAST_FILE_NAME, "common", 24);
	I_strncpyz(DEFAULT_FAST_FILE_NAME, "default", 24);
	I_strncpyz(FFOTD_FAST_FILE_NAME, "sv_ffotd", 24);
	I_strncpyz(FFOTD_FILENAME, "", 24);
	if (Com_SessionMode_IsZombiesGame())
	{
		I_strncpyz(COMMON_FASTFILE_SUFFIX, "_zm", 4);
	}
	else
	{
		I_strncpyz(COMMON_FASTFILE_SUFFIX, "_mp", 4);
	}
	I_strncat(CODE_PRE_GFX_FAST_FILE_NAME, 24, COMMON_FASTFILE_SUFFIX);
	I_strncat(CODE_FAST_FILE_NAME, 24, COMMON_FASTFILE_SUFFIX);
	I_strncat(CODE_FAST_FILE_RES_NAME, 24, va("_%d%s", Dvar_GetInt(r_fontResolution), COMMON_FASTFILE_SUFFIX));
	I_strncat(DEV_FAST_FILE_NAME, 24, COMMON_FASTFILE_SUFFIX);
	I_strncat(PATCH_FAST_FILE_NAME, 24, COMMON_FASTFILE_SUFFIX);
	I_strncat(LOC_PATCH_FAST_FILE_NAME, 24, COMMON_FASTFILE_SUFFIX);
	I_strncat(PATCH_UI_FAST_FILE_NAME, 24, COMMON_FASTFILE_SUFFIX);
	I_strncat(LOC_PATCH_UI_FAST_FILE_NAME, 24, COMMON_FASTFILE_SUFFIX);
	I_strncat(UI_FAST_FILE_NAME, 24, COMMON_FASTFILE_SUFFIX);
	I_strncat(COMMON_FAST_FILE_NAME, 24, COMMON_FASTFILE_SUFFIX);
	I_strncat(FFOTD_FAST_FILE_NAME, 24, va("%s%s%s", "_tu17", COMMON_FASTFILE_SUFFIX, "_147"));
	I_strncat(FFOTD_FILENAME, 24, va("%s%s", FFOTD_FAST_FILE_NAME, ".ff"));
}

/*
==============
DB_UnloadXZoneInternal
==============
*/
void DB_UnloadXZoneInternal(unsigned int zoneIndex, bool createDefault)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_UnloadXZoneMemory
==============
*/
void DB_UnloadXZoneMemory(XZone *zone)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_FreeDefaultEntries
==============
*/
BOOL DB_FreeDefaultEntries()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_ReleaseXAssets
==============
*/
void DB_ReleaseXAssets()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_UnloadXAssetsMemory
==============
*/
void DB_UnloadXAssetsMemory(XZone *zone)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_UnloadXAssetsMemoryForZone
==============
*/
void DB_UnloadXAssetsMemoryForZone(int zoneFreeFlags, int zoneFreeBit)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_ArchiveAssets
==============
*/
char DB_ArchiveAssets()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_FreeUnusedResources
==============
*/
void DB_FreeUnusedResources(int fast_free)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_UnarchiveAssets
==============
*/
char DB_UnarchiveAssets()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_Cleanup
==============
*/
void DB_Cleanup()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_GetImageAtIndex
==============
*/
/*XAssetPoolEntry<GfxImage> *DB_GetImageAtIndex(unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
DB_GetImagePartPoolSize
==============
*/
unsigned int DB_GetImagePartPoolSize()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_GetImagePartAtIndex
==============
*/
GfxStreamedPartInfo *DB_GetImagePartAtIndex(unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DB_ReferencedFFChecksums
==============
*/
char *DB_ReferencedFFChecksums()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DB_ReferencedFFNameList
==============
*/
char *DB_ReferencedFFNameList()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DB_FileExists
==============
*/
char DB_FileExists(FF_DIR a1, const char *zoneName, FF_DIR source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_GetGfxWorldChecksum
==============
*/
unsigned int DB_GetGfxWorldChecksum()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Load_PhysPresetAsset
==============
*/
void Load_PhysPresetAsset(PhysPreset **physPreset)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_PhysPresetAsset
==============
*/
void __cdecl Mark_PhysPresetAsset(PhysPreset *physPreset)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_PhysConstraintsAsset
==============
*/
void Load_PhysConstraintsAsset(PhysConstraints **physConstraints)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_PhysConstraintsAsset
==============
*/
void __cdecl Mark_PhysConstraintsAsset(PhysConstraints *physConstraints)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_DestructibleDefAsset
==============
*/
void Load_DestructibleDefAsset(DestructibleDef **destructibleDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_DestructibleDefAsset
==============
*/
void __cdecl Mark_DestructibleDefAsset(DestructibleDef *destructibleDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_XAnimPartsAsset
==============
*/
void Load_XAnimPartsAsset(XAnimParts **parts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_XAnimPartsAsset
==============
*/
void __cdecl Mark_XAnimPartsAsset(XAnimParts *parts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_XModelAsset
==============
*/
void Load_XModelAsset(XModel **model)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_XModelAsset
==============
*/
void __cdecl Mark_XModelAsset(XModel *model)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_MaterialAsset
==============
*/
void Load_MaterialAsset(Material **material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_MaterialAsset
==============
*/
void __cdecl Mark_MaterialAsset(Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_MaterialTechniqueSetAsset
==============
*/
void Load_MaterialTechniqueSetAsset(MaterialTechniqueSet **techniqueSet)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_MaterialTechniqueSetAsset
==============
*/
void __cdecl Mark_MaterialTechniqueSetAsset(MaterialTechniqueSet *techniqueSet)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_GfxImageAsset
==============
*/
void Load_GfxImageAsset(GfxImage **image)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_GfxImageAsset
==============
*/
void __cdecl Mark_GfxImageAsset(GfxImage *image)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_SndBankAsset
==============
*/
void Load_SndBankAsset(SndBank **sound)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_SndBankAsset
==============
*/
void __cdecl Mark_SndBankAsset(SndBank *sound)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_SndDriverGlobalsAsset
==============
*/
void Load_SndDriverGlobalsAsset(SndDriverGlobals **sndDriverGlobals)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_SndDriverGlobalsAsset
==============
*/
void __cdecl Mark_SndDriverGlobalsAsset(SndDriverGlobals *sndDriverGlobals)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_SndPatchAsset
==============
*/
void Load_SndPatchAsset(SndPatch **soundPatch)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_SndPatchAsset
==============
*/
void __cdecl Mark_SndPatchAsset(SndPatch *soundPatch)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_ClipMapAsset
==============
*/
void Load_ClipMapAsset(clipMap_t **clipMap)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_ClipMapAsset
==============
*/
void __cdecl Mark_ClipMapAsset(clipMap_t *clipMap)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_ComWorldAsset
==============
*/
void Load_ComWorldAsset(ComWorld **comWorld)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_ComWorldAsset
==============
*/
void __cdecl Mark_ComWorldAsset(ComWorld *comWorld)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_GameWorldSpAsset
==============
*/
void Load_GameWorldSpAsset(GameWorldSp **gameWorldSp)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_GameWorldSpAsset
==============
*/
void __cdecl Mark_GameWorldSpAsset(GameWorldSp *gameWorldSp)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_GameWorldMpAsset
==============
*/
void Load_GameWorldMpAsset(GameWorldMp **gameWorldMp)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_GameWorldMpAsset
==============
*/
void __cdecl Mark_GameWorldMpAsset(GameWorldMp *gameWorldMp)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_MapEntsAsset
==============
*/
void Load_MapEntsAsset(MapEnts **mapEnts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_MapEntsAsset
==============
*/
void __cdecl Mark_MapEntsAsset(MapEnts *mapEnts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_DDLAsset
==============
*/
void Load_DDLAsset(ddlRoot_t **ddlRoot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_DDLAsset
==============
*/
void __cdecl Mark_DDLAsset(ddlRoot_t *ddlRoot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_GfxWorldAsset
==============
*/
void Load_GfxWorldAsset(GfxWorld **gfxWorld)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_GfxWorldAsset
==============
*/
void __cdecl Mark_GfxWorldAsset(GfxWorld *gfxWorld)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_LightDefAsset
==============
*/
void Load_LightDefAsset(GfxLightDef **lightDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_LightDefAsset
==============
*/
void __cdecl Mark_LightDefAsset(GfxLightDef *lightDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_FontAsset
==============
*/
void Load_FontAsset(Font_s **font)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_FontAsset
==============
*/
void __cdecl Mark_FontAsset(Font_s *font)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_FontIconAsset
==============
*/
void Load_FontIconAsset(FontIcon **fontIcon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_FontIconAsset
==============
*/
void __cdecl Mark_FontIconAsset(FontIcon *fontIcon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_MenuListAsset
==============
*/
void Load_MenuListAsset(MenuList **menuList)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_MenuListAsset
==============
*/
void __cdecl Mark_MenuListAsset(MenuList *menuList)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_MenuAsset
==============
*/
void Load_MenuAsset(menuDef_t **menu)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_MenuAsset
==============
*/
void __cdecl Mark_MenuAsset(menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_LocalizeEntryAsset
==============
*/
void Load_LocalizeEntryAsset(LocalizeEntry **localize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_LocalizeEntryAsset
==============
*/
void __cdecl Mark_LocalizeEntryAsset(LocalizeEntry *localize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_WeaponVariantDefAsset
==============
*/
void Load_WeaponVariantDefAsset(WeaponVariantDef **weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_WeaponVariantDefAsset
==============
*/
void __cdecl Mark_WeaponVariantDefAsset(WeaponVariantDef *weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_WeaponAttachmentAsset
==============
*/
void Load_WeaponAttachmentAsset(WeaponAttachment **attachment)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_WeaponAttachmentAsset
==============
*/
void __cdecl Mark_WeaponAttachmentAsset(WeaponAttachment *attachment)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_WeaponAttachmentUniqueAsset
==============
*/
void Load_WeaponAttachmentUniqueAsset(WeaponAttachmentUnique **attachmentUnique)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_WeaponAttachmentUniqueAsset
==============
*/
void __cdecl Mark_WeaponAttachmentUniqueAsset(WeaponAttachmentUnique *attachmentUnique)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_WeaponCamoAsset
==============
*/
void Load_WeaponCamoAsset(WeaponCamo **weaponCamo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_WeaponCamoAsset
==============
*/
void __cdecl Mark_WeaponCamoAsset(WeaponCamo *weaponCamo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_FxEffectDefAsset
==============
*/
void Load_FxEffectDefAsset(const FxEffectDef **fx)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_FxEffectDefAsset
==============
*/
void __cdecl Mark_FxEffectDefAsset(FxEffectDef *fx)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_FxImpactTableAsset
==============
*/
void Load_FxImpactTableAsset(FxImpactTable **impactFx)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_FxImpactTableAsset
==============
*/
void __cdecl Mark_FxImpactTableAsset(FxImpactTable *impactFx)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_RawFileAsset
==============
*/
void Load_RawFileAsset(RawFile **rawfile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_RawFileAsset
==============
*/
void __cdecl Mark_RawFileAsset(RawFile *rawfile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_StringTableAsset
==============
*/
void Load_StringTableAsset(StringTable **stringTable)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_StringTableAsset
==============
*/
void __cdecl Mark_StringTableAsset(StringTable *stringTable)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_LeaderboardDefAsset
==============
*/
void Load_LeaderboardDefAsset(LeaderboardDef **leaderboardDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_LeaderboardDefAsset
==============
*/
void __cdecl Mark_LeaderboardDefAsset(LeaderboardDef *leaderboardDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_XGlobalsAsset
==============
*/
void Load_XGlobalsAsset(XGlobals **xGlobals)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_XGlobalsAsset
==============
*/
void __cdecl Mark_XGlobalsAsset(XGlobals *xGlobals)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_GlassesAsset
==============
*/
void Load_GlassesAsset(Glasses **glasses)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_GlassesAsset
==============
*/
void __cdecl Mark_GlassesAsset(Glasses *glasses)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_EmblemSetAsset
==============
*/
void Load_EmblemSetAsset(EmblemSet **emblemSet)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_EmblemSetAsset
==============
*/
void __cdecl Mark_EmblemSetAsset(EmblemSet *emblemSet)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_ScriptParseTreeAsset
==============
*/
void Load_ScriptParseTreeAsset(ScriptParseTree **scriptParseTree)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_ScriptParseTreeAsset
==============
*/
void __cdecl Mark_ScriptParseTreeAsset(ScriptParseTree *scriptParseTree)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_QdbAsset
==============
*/
void Load_QdbAsset(Qdb **qdb)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_QdbAsset
==============
*/
void __cdecl Mark_QdbAsset(Qdb *qdb)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_SlugAsset
==============
*/
void Load_SlugAsset(Slug **slug)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_SlugAsset
==============
*/
void __cdecl Mark_SlugAsset(Slug *slug)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_KeyValuePairsAsset
==============
*/
void Load_KeyValuePairsAsset(KeyValuePairs **keyValuePairs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_KeyValuePairsAsset
==============
*/
void __cdecl Mark_KeyValuePairsAsset(KeyValuePairs *keyValuePairs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_VehicleDefAsset
==============
*/
void Load_VehicleDefAsset(VehicleDef **vehicleDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_VehicleDefAsset
==============
*/
void __cdecl Mark_VehicleDefAsset(VehicleDef *vehicleDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_MemoryBlockAsset
==============
*/
void Load_MemoryBlockAsset(MemoryBlock **memoryBlock)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_MemoryBlockAsset
==============
*/
void __cdecl Mark_MemoryBlockAsset(MemoryBlock *memoryBlock)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_AddonMapEntsAsset
==============
*/
void Load_AddonMapEntsAsset(AddonMapEnts **addonMapEnts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_AddonMapEntsAsset
==============
*/
void __cdecl Mark_AddonMapEntsAsset(AddonMapEnts *addonMapEnts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_TracerDefAsset
==============
*/
void Load_TracerDefAsset(TracerDef **tracerDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_TracerDefAsset
==============
*/
void __cdecl Mark_TracerDefAsset(TracerDef *tracerDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_SkinnedVertsDefAsset
==============
*/
void Load_SkinnedVertsDefAsset(SkinnedVertsDef **skinnedVertsDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_SkinnedVertsDefAsset
==============
*/
void __cdecl Mark_SkinnedVertsDefAsset(SkinnedVertsDef *skinnedVertsDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_FootstepTableDefAsset
==============
*/
void Load_FootstepTableDefAsset(FootstepTableDef **footstepTableDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_FootstepTableDefAsset
==============
*/
void __cdecl Mark_FootstepTableDefAsset(FootstepTableDef *footstepTableDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_FootstepFXTableDefAsset
==============
*/
void Load_FootstepFXTableDefAsset(FootstepFXTableDef **footstepFXTableDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_FootstepFXTableDefAsset
==============
*/
void __cdecl Mark_FootstepFXTableDefAsset(FootstepFXTableDef *footstepFXTableDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_ZBarrierDefAsset
==============
*/
void Load_ZBarrierDefAsset(ZBarrierDef **zbarrierDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mark_ZBarrierDefAsset
==============
*/
void __cdecl Mark_ZBarrierDefAsset(ZBarrierDef *zbarrierDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_AllocMaterial
==============
*/
XAssetHeader DB_AllocMaterial(void *pool)
{
	UNIMPLEMENTED(__FUNCTION__);
	XAssetHeader tmp;
	return tmp;
}

/*
==============
DB_AllocGfxImage
==============
*/
XAssetHeader DB_AllocGfxImage(void *pool)
{
	UNIMPLEMENTED(__FUNCTION__);
	XAssetHeader tmp;
	return tmp;
}

/*
==============
DB_FreeMaterial
==============
*/
void DB_FreeMaterial(void *pool, XAssetHeader header)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_FreeMenu
==============
*/
void DB_FreeMenu(void *pool, XAssetHeader header)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_FreeXGlobals
==============
*/
void DB_FreeXGlobals(void *pool, XAssetHeader header)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_PostLoadXZone
==============
*/
char DB_PostLoadXZone()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_SyncXAssets
==============
*/
void DB_SyncXAssets()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_ShutdownXAssets
==============
*/
void DB_ShutdownXAssets()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_Update
==============
*/
void DB_Update()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_EndReorderZone
==============
*/
void DB_EndReorderZone()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_RegisterAllReorderAssetsOfType
==============
*/
bool DB_RegisterAllReorderAssetsOfType(int type, XAssetEntry *assetEntry)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DB_RegisteredReorderAsset
==============
*/
void DB_RegisteredReorderAsset(int type, const char *assetName, XAssetEntry *assetEntry)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_FindXAssetHeader
==============
*/
XAssetHeader DB_FindXAssetHeader(XAssetType type, const char *name, bool errorIfMissing, int waitTime)
{
	UNIMPLEMENTED(__FUNCTION__);
	XAssetHeader tmp;
	return tmp;
}

/*
==============
DB_LoadXAssets
==============
*/
void DB_LoadXAssets(XZoneInfo *zoneInfo, unsigned int zoneCount, int sync)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_Thread
==============
*/
void DB_Thread(unsigned int threadContext)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_InitThread
==============
*/
void DB_InitThread()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_ReplaceModel
==============
*/
void DB_ReplaceModel(const char *original, const char *replacement)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_LoadGraphicsAssetsForPC
==============
*/
void DB_LoadGraphicsAssetsForPC()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_InitFrontendXAssets
==============
*/
void DB_InitFrontendXAssets(bool uiOnly)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_FxEffectDefFromName
==============
*/
void Load_FxEffectDefFromName(const char **name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DB_LoadLoadFastfilesForNewContent
==============
*/
void DB_LoadLoadFastfilesForNewContent()
{
	UNIMPLEMENTED(__FUNCTION__);
}

