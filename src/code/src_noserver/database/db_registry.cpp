#include "types.h"
#include "functions.h"

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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
DB_RemoveComWorld
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
DB_RemoveGfxWorld
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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
	UNIMPLEMENTED(__FUNCTION__);
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
	UNIMPLEMENTED(__FUNCTION__);
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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
/*XAssetHeader DB_FindXAssetHeader@<eax>(char *a1@<edi>, XAssetType type, const char *name, bool errorIfMissing, int waitTime)
{
	UNIMPLEMENTED(__FUNCTION__);
	XAssetHeader tmp;
	return tmp;
}*/

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
void __noreturn DB_Thread(unsigned int threadContext)
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

