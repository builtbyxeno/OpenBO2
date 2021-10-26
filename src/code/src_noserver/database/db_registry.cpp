#include "types.h"
#include "vars.h"
#include <win32/win32_public.h>
#include <qcommon/qcommon_public.h>
#include <xanim/xanim_public.h>
#include <client/client_public.h>
#include <effectscore/effectscore_public.h>
#include <gfx_d3d/gfx_d3d_public.h>
#include <sound/sound_public.h>
#include <qcommon/threads_interlock.h>
#include <database/database_public.h>
#include <ipak/ipak_public.h>
#include <clientscript/clientscript_public.h>
#include <qcommon/cmd.h>
#include <database/db_assetlist_load.h>
#include <gfx_d3d/r_pix_profile.h>
#include <cgame/cgame_public.h>
#include <game/game_public.h>
#include <stringed/stringed_public.h>

#define XASSET_ENTRY_POOL_SIZE 0x95FF
#define REORDER_WEAPON_PREFIX "mp/"
#define REORDER_WEAPON_PREFIX_LEN 3

unsigned __int16 db_hashTable[38400];
XAssetEntry* g_copyInfo[3072];
XZoneName g_zoneNames[65];
XZone g_zones[64];
char g_zoneNameList[4160];
bool s_usageUpToDate[60];
int s_usageCounts[60];

XAssetPool<XModel, 1400> g_XModelPool;
XAssetPool<XModelPieces, 64> g_XModelPiecesPool;
XAssetPool<XAnimParts, 5200> g_XAnimPartsPool;
XAssetPool<PhysPreset, 65> g_PhysPresetPool;
XAssetPool<PhysConstraints, 64> g_PhysConstraintsPool;
XAssetPool<DestructibleDef, 64> g_DestructibleDefPool;
XAssetPool<MaterialTechniqueSet, 2048> g_MaterialTechniqueSetPool;
XAssetPool<SndBank, 32> g_SoundPool;
XAssetPool<MapEnts, 2> g_MapEntsPool;
XAssetPool<GfxLightDef, 32> g_GfxLightDefPool;
XAssetPool<Font_s, 16> g_FontPool;
XAssetPool<Font_s, 16> g_FontIconPool;
XAssetPool<MenuList, 164> g_MenuListPool;
XAssetPool<menuDef_t, 450> g_MenuPool;
XAssetPool<LocalizeEntry, 14336> g_LocalizeEntryPool;
XAssetPool<SndDriverGlobals, 1> g_SndDriverGlobalsPool;
XAssetPool<FxEffectDef, 600> g_FxEffectDefPool;
XAssetPool<FxImpactTable, 4> g_FxImpactTablePool;
XAssetPool<RawFile, 1024> g_RawFilePool;
XAssetPool<StringTable, 96> g_StringTablePool;
XAssetPool<LeaderboardDef, 128> g_LeaderboardPool;
XAssetPool<ddlDef_t, 24> g_DDLPool;
XAssetPool<Glasses, 1> g_GlassesPool;
XAssetPool<EmblemSet, 4> g_EmblemSetPool;
XAssetPool<VehicleDef, 32> g_VehicleDefPool;
XAssetPool<MemoryBlock, 16> g_MemoryBlockPool;
XAssetPool<AddonMapEnts, 1> g_AddonMapEntsPool;
XAssetPool<TracerDef, 50> g_TracerPool;
XAssetPool<SkinnedVertsDef, 1> g_SkinnedVertsPool;
XAssetPool<FootstepTableDef, 32> g_FootstepTablePool;
XAssetPool<FootstepFXTableDef, 4> g_FootstepFXTablePool;
XAssetPool<ZBarrierDef, 16> g_ZBarrierPool;
XAssetPool<Material, 4992> g_MaterialPool;
XAssetPool<GfxImage, 5376> g_GfxImagePool;
XAssetPool<SndAliasList, 16> g_SoundPatchPool;
XAssetPool<WeaponVariantDef, 256> g_WeaponVariantDefPool;
XAssetPool<WeaponAttachment, 128> g_WeaponAttachmentPool;
XAssetPool<WeaponAttachmentUnique, 2048> g_WeaponAttachmentUniquePool;
XAssetPool<WeaponCamo, 128> g_WeaponCamoPool;
XAssetPool<XGlobals, 1> g_XGlobalsPool;
XAssetPool<ScriptParseTree, 1024> g_ScriptParseTreePool;
XAssetPool<KeyValuePairs, 64> g_keyValuePairsPool;
XAssetPool<Qdb, 4> g_QdbPool;
XAssetPool<Slug, 5> g_SlugPool;

XAssetEntryPoolEntry g_assetEntryPool[38400];

static struct
{
	FastCriticalSection critSect;
	char zoneName[256];
	bool alreadyFinished;
	bool loadedSound;
	bool loadedLocalization;
	DBReorderAssetEntry* lastEntry;
	unsigned int sequence;
	unsigned int sequenceForIncludes;
	unsigned int entryCount;
	DBReorderAssetEntry entries[38400];
} s_dbReorder;

int g_poolSize[60] =
{
  64,
  65,
  64,
  64,
  5200,
  1400,
  4992,
  2048,
  5376,
  32,
  16,
  1,
  1,
  1,
  1,
  1,
  2,
  1,
  32,
  0,
  16,
  16,
  164,
  450,
  14336,
  256,
  0,
  0,
  0,
  128,
  2048,
  128,
  1,
  600,
  4,
  0,
  0,
  0,
  0,
  0,
  0,
  1024,
  96,
  128,
  1,
  24,
  1,
  4,
  1024,
  64,
  32,
  16,
  1,
  50,
  1,
  4,
  5,
  32,
  4,
  16
};

const char* g_assetNames[] =
{
  "xmodelpieces",
  "physpreset",
  "physconstraints",
  "destructibledef",
  "xanim",
  "xmodel",
  "material",
  "techset",
  "image",
  "sound",
  "sound_patch",
  "col_map_sp",
  "col_map_mp",
  "com_map",
  "game_map_sp",
  "game_map_mp",
  "map_ents",
  "gfx_map",
  "lightdef",
  "ui_map",
  "font",
  "fonticon",
  "menufile",
  "menu",
  "localize",
  "weapon",
  "weapondef",
  "weaponvariant",
  "weaponfull",
  "attachment",
  "attachmentunique",
  "weaponcamo",
  "snddriverglobals",
  "fx",
  "impactfx",
  "aitype",
  "mptype",
  "mpbody",
  "mphead",
  "character",
  "xmodelalias",
  "rawfile",
  "stringtable",
  "leaderboarddef",
  "xGlobals",
  "ddl",
  "glasses",
  "emblemset",
  "scriptparsetree",
  "keyvaluepairs",
  "vehicle",
  "memoryblock",
  "addon_map_ents",
  "tracer",
  "skinnedverts",
  "qdb",
  "slug",
  "footsteptable",
  "footstepfxtable",
  "zbarrier",
  "string",
  "assetlist",
  "report",
  "depend"
};

void* DB_XAssetPool[60] =
{
  &g_XModelPiecesPool,
  &g_PhysPresetPool,
  &g_PhysConstraintsPool,
  &g_DestructibleDefPool,
  &g_XAnimPartsPool,
  &g_XModelPool,
  &g_MaterialPool,
  &g_MaterialTechniqueSetPool,
  &g_GfxImagePool,
  &g_SoundPool,
  &g_SoundPatchPool,
  &cm,
  &cm,
  &comWorld,
  NULL,
  &gameWorldMp,
  &g_MapEntsPool,
  &s_world,
  &g_GfxLightDefPool,
  NULL,
  &g_FontPool,
  &g_FontIconPool,
  &g_MenuListPool,
  &g_MenuPool,
  &g_LocalizeEntryPool,
  &g_WeaponVariantDefPool,
  NULL,
  NULL,
  NULL,
  &g_WeaponAttachmentPool,
  &g_WeaponAttachmentUniquePool,
  &g_WeaponCamoPool,
  &g_SndDriverGlobalsPool,
  &g_FxEffectDefPool,
  &g_FxImpactTablePool,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  &g_RawFilePool,
  &g_StringTablePool,
  &g_LeaderboardPool,
  &g_XGlobalsPool,
  &g_DDLPool,
  &g_GlassesPool,
  &g_EmblemSetPool,
  &g_ScriptParseTreePool,
  &g_keyValuePairsPool,
  &g_VehicleDefPool,
  &g_MemoryBlockPool,
  &g_AddonMapEntsPool,
  &g_TracerPool,
  &g_SkinnedVertsPool,
  &g_QdbPool,
  &g_SlugPool,
  &g_FootstepTablePool,
  &g_FootstepFXTablePool,
  &g_ZBarrierPool
};

XAssetHeader(__cdecl* DB_AllocXAssetHeaderHandler[60])(void*) =
{
	DB_AllocXAsset<XModelPieces>,
	DB_AllocXAsset<PhysPreset>,
	DB_AllocXAsset<PhysConstraints>,
	DB_AllocXAsset<DestructibleDef>,
	DB_AllocXAsset<XAnimParts>,
	DB_AllocXAsset<XModel>,
	DB_AllocMaterial,
	DB_AllocXAsset<MaterialTechniqueSet>,
	DB_AllocGfxImage,
	DB_AllocXAsset<SndBank>,
	DB_AllocXAsset<SndPatch>,
	DB_AllocXAssetSingleton,
	DB_AllocXAssetSingleton,
	DB_AllocXAssetSingleton,
	NULL,
	DB_AllocXAssetSingleton,
	DB_AllocXAsset<MapEnts>,
	DB_AllocXAssetSingleton,
	DB_AllocXAsset<GfxLightDef>,
	NULL,
	DB_AllocXAsset<Font_s>,
	DB_AllocXAsset<Font_s>,
	DB_AllocXAsset<MenuList>,
	DB_AllocXAsset<menuDef_t>,
	DB_AllocXAsset<LocalizeEntry>,
	DB_AllocXAsset<WeaponVariantDef>,
	NULL,
	NULL,
	NULL,
	DB_AllocXAsset<WeaponAttachment>,
	DB_AllocXAsset<WeaponAttachmentUnique>,
	DB_AllocXAsset<WeaponCamo>,
	DB_AllocXAsset<SndDriverGlobals>,
	DB_AllocXAsset<FxEffectDef>,
	DB_AllocXAsset<FxImpactTable>,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	DB_AllocXAsset<RawFile>,
	DB_AllocXAsset<StringTable>,
	DB_AllocXAsset<LeaderboardDef>,
	DB_AllocXAsset<XGlobals>,
	DB_AllocXAsset<ddlDef_t>,
	DB_AllocXAsset<Glasses>,
	DB_AllocXAsset<EmblemSet>,
	DB_AllocXAsset<ScriptParseTree>,
	DB_AllocXAsset<KeyValuePairs>,
	DB_AllocXAsset<VehicleDef>,
	DB_AllocXAsset<MemoryBlock>,
	DB_AllocXAsset<AddonMapEnts>,
	DB_AllocXAsset<TracerDef>,
	DB_AllocXAsset<SkinnedVertsDef>,
	DB_AllocXAsset<Qdb>,
	DB_AllocXAsset<Slug>,
	DB_AllocXAsset<FootstepTableDef>,
	DB_AllocXAsset<FootstepFXTableDef>,
	DB_AllocXAsset<ZBarrierDef>
};

void (*DB_InitPoolHeaderHandler[ASSET_TYPE_COUNT])(void*, int) =
{
	DB_InitPool<XModelPieces>,
	DB_InitPool<PhysPreset>,
	DB_InitPool<PhysConstraints>,
	DB_InitPool<DestructibleDef>,
	DB_InitPool<XAnimParts>,
	DB_InitPool<XModel>,
	DB_InitPool<Material>,
	DB_InitPool<MaterialTechniqueSet>,
	DB_InitPool<GfxImage>,
	DB_InitPool<SndBank>,
	DB_InitPool<SndPatch>,
	DB_InitSingleton,
	DB_InitSingleton,
	DB_InitSingleton,
	NULL,
	DB_InitSingleton,
	DB_InitPool<MapEnts>,
	DB_InitSingleton,
	DB_InitPool<GfxLightDef>,
	NULL,
	DB_InitPool<Font_s>,
	DB_InitPool<Font_s>,
	DB_InitPool<MenuList>,
	DB_InitPool<menuDef_t>,
	DB_InitPool<LocalizeEntry>,
	DB_InitPool<WeaponVariantDef>,
	NULL,
	NULL,
	NULL,
	DB_InitPool<WeaponAttachment>,
	DB_InitPool<WeaponAttachmentUnique>,
	DB_InitPool<WeaponCamo>,
	DB_InitPool<SndDriverGlobals>,
	DB_InitPool<FxEffectDef>,
	DB_InitPool<FxImpactTable>,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	DB_InitPool<RawFile>,
	DB_InitPool<StringTable>,
	DB_InitPool<LeaderboardDef>,
	DB_InitPool<XGlobals>,
	DB_InitPool<ddlDef_t>,
	DB_InitPool<Glasses>,
	DB_InitPool<EmblemSet>,
	DB_InitPool<ScriptParseTree>,
	DB_InitPool<KeyValuePairs>,
	DB_InitPool<VehicleDef>,
	DB_InitPool<MemoryBlock>,
	DB_InitPool<AddonMapEnts>,
	DB_InitPool<TracerDef>,
	DB_InitPool<SkinnedVertsDef>,
	DB_InitPool<Qdb>,
	DB_InitPool<Slug>,
	DB_InitPool<FootstepTableDef>,
	DB_InitPool<FootstepFXTableDef>,
	DB_InitPool<ZBarrierDef>
};

/*
==============
TRACK_db_registry
==============
*/
void TRACK_db_registry()
{
	track_static_alloc_internal(db_hashTable, 76800, "db_hashTable", 12);
	track_static_alloc_internal(g_copyInfo, 12288, "g_copyInfo", 12);
	track_static_alloc_internal(g_zoneNames, 4940, "g_zoneNames", 12);
	track_static_alloc_internal(g_zones, 4608, "g_zones", 12);
	track_static_alloc_internal(g_zoneNameList, 4160, "g_zoneNameList", 12);
	track_static_alloc_internal(&g_XModelPiecesPool, 772, "g_XModelPiecesPool", 12);
	track_static_alloc_internal(&g_PhysPresetPool, 5464, "g_PhysPresetPool", 12);
	track_static_alloc_internal(&g_PhysConstraintsPool, 172548, "g_PhysConstraintsPool", 12);
	track_static_alloc_internal(&g_DestructibleDefPool, 1540, "g_DestructibleDefPool", 12);
	track_static_alloc_internal(&g_MaterialTechniqueSetPool, 311300, "g_MaterialTechniqueSetPool", 12);
	track_static_alloc_internal(&g_SoundPool, 152196, "g_SoundPool", 12);
	track_static_alloc_internal(&g_MapEntsPool, 76, "g_MapEntsPool", 12);
	track_static_alloc_internal(&g_GfxLightDefPool, 516, "g_GfxLightDefPool", 12);
	track_static_alloc_internal(&g_FontPool, 580, "g_FontPool", 12);
	track_static_alloc_internal(&g_FontIconPool, 580, "g_FontIconPool", 12);
	track_static_alloc_internal(&g_MenuListPool, 1972, "g_MenuListPool", 12);
	track_static_alloc_internal(&g_MenuPool, 180008, "g_MenuPool", 12);
	track_static_alloc_internal(&g_LocalizeEntryPool, 114692, "g_LocalizeEntryPool", 12);
	track_static_alloc_internal(&g_SndDriverGlobalsPool, 72, "g_SndDriverGlobalsPool", 12);
	track_static_alloc_internal(&g_FxEffectDefPool, 45604, "g_FxEffectDefPool", 12);
	track_static_alloc_internal(&g_FxImpactTablePool, 36, "g_FxImpactTablePool", 12);
	track_static_alloc_internal(&g_RawFilePool, 12292, "g_RawFilePool", 12);
	track_static_alloc_internal(&g_StringTablePool, 1924, "g_StringTablePool", 12);
	track_static_alloc_internal(&g_LeaderboardPool, 4612, "g_LeaderboardPool", 12);
	track_static_alloc_internal(&g_DDLPool, 676, "g_DDLPool", 12);
	track_static_alloc_internal(&g_GlassesPool, 60, "g_GlassesPool", 12);
	track_static_alloc_internal(&g_EmblemSetPool, 244, "g_EmblemSetPool", 12);
	track_static_alloc_internal(&g_VehicleDefPool, 83332, "g_VehicleDefPool", 12);
	track_static_alloc_internal(&g_MemoryBlockPool, 324, "g_MemoryBlockPool", 12);
	track_static_alloc_internal(&g_AddonMapEntsPool, 56, "g_AddonMapEntsPool", 12);
	track_static_alloc_internal(&g_TracerPool, 6404, "g_TracerPool", 12);
	track_static_alloc_internal(&g_SkinnedVertsPool, 12, "g_SkinnedVertsPool", 12);
	track_static_alloc_internal(&g_FootstepTablePool, 28804, "g_FootstepTablePool", 12);
	track_static_alloc_internal(&g_FootstepFXTablePool, 532, "g_FootstepFXTablePool", 12);
	track_static_alloc_internal(&g_ZBarrierPool, 8964, "g_ZBarrierPool", 12);
}

/*
==============
DB_InitSingleton
==============
*/
void DB_InitSingleton(void *pool, int size)
{
	assert(size == 1);
}

/*
==============
DB_RemoveXModel
==============
*/
void DB_RemoveXModel(XAssetHeader header)
{
	XModelReleaseResources(header.model);
}

/*
==============
DB_RemoveFX
==============
*/
void DB_RemoveFX(XAssetHeader header)
{
	if (CL_LocalClient_IsActive(LOCAL_CLIENT_FIRST))
	{
		FX_KillEffectDef(LOCAL_CLIENT_FIRST, header.fx);
	}
}

/*
==============
DB_RemoveMaterial
==============
*/
void DB_RemoveMaterial(XAssetHeader header)
{
	Material_ReleaseMaterialResources(header.material);
}

/*
==============
DB_RemoveTechniqueSet
==============
*/
void DB_RemoveTechniqueSet(XAssetHeader header)
{
	Material_ReleaseTechniqueSetResources(header.techniqueSet);
}

/*
==============
DB_RemoveImage
==============
*/
void DB_RemoveImage(XAssetHeader header)
{
	Image_Release(header.image);
}

/*
==============
DB_RemoveSound
==============
*/
void DB_RemoveSound(XAssetHeader header)
{
	SND_RemoveBank(header.sound);
}

/*
==============
DB_RemoveSndDriverGlobals
==============
*/
void DB_RemoveSndDriverGlobals(XAssetHeader header)
{
	SND_RemoveGlobals(header.sndDriverGlobals);
}

/*
==============
DB_RemoveSoundPatch
==============
*/
void DB_RemoveSoundPatch(XAssetHeader header)
{
	SND_RemovePatch(header.soundPatch);
}

/*
==============
DB_RemoveClipMap
==============
*/
void DB_RemoveClipMap()
{
	CM_Unload();
}

/*
==============
DB_RemoveComWorld
==============
*/
void DB_RemoveComWorld()
{
	Com_UnloadWorld();
}

/*
==============
DB_RemoveGfxWorld
==============
*/
void DB_RemoveGfxWorld()
{
	R_UnloadWorld();
}

/*
==============
DB_RemoveWindowFocus
==============
*/
inline void DB_RemoveWindowFocus(windowDef_t* window)
{
	unsigned int i;

	for (i = 0; i < 1; ++i)
	{
		window->dynamicFlags[i] &= ~2;
	}
}

/*
==============
DB_DynamicCloneMenu
==============
*/
void DB_DynamicCloneMenu(const XAssetHeader from, XAssetHeader to, DBCloneMethod cloneMethod)
{
	windowDef_t* toWindow;
	int toIndex;
	int fromIndex;
	windowDef_t* fromWindow;

	from.menu->window.dynamicFlags[0] = to.menu->window.dynamicFlags[0];
	for (toIndex = 0; toIndex < from.menu->itemCount; ++toIndex)
	{
		toWindow = &from.menu->items[toIndex]->window;
		if (toWindow->name)
		{
			for (fromIndex = 0; fromIndex < to.menu->itemCount; ++fromIndex)
			{
				fromWindow = &to.menu->items[fromIndex]->window;
				if (fromWindow->name && !strcmp(fromWindow->name, toWindow->name))
				{
					toWindow->dynamicFlags[0] = fromWindow->dynamicFlags[0];
					break;
				}
			}
		}
		DB_RemoveWindowFocus(toWindow);
	}
}

/*
==============
DB_RemoveKeyValuePairs
==============
*/
void DB_RemoveKeyValuePairs(XAssetHeader header)
{
	KeyValuePairs_Remove(header.keyValuePairs);
}

/*
==============
DB_CompareReorderEntries
==============
*/
char DB_CompareReorderEntries(const DBReorderAssetEntry *e0, const DBReorderAssetEntry *e1)
{
	int comparison;

	if (e0->sequence != e1->sequence)
	{
		return e0->sequence < e1->sequence;
	}

	if (e0->type == 60)
	{
		if (e1->type != 60)
		{
			return 1;
		}

		comparison = _stricmp(e0->typeString, e1->typeString);
		if (comparison)
		{
			return comparison < 0;
		}

		return _stricmp(e0->assetName, e1->assetName) < 0;
	}

	if (e1->type == 60)
	{
		return 0;
	}

	if (e0->type == e1->type)
	{
		return _stricmp(e0->assetName, e1->assetName) < 0;
	}

	if (e0->sequence != -1)
	{
		return e0->type < e1->type;
	}

	if (e0->type == 9)
	{
		return 1;
	}

	if (e1->type == 9)
	{
		return 0;
	}

	if (e0->type == 24)
	{
		return 1;
	}

	return e1->type != 24 && e0->type < e1->type;
}

/*
==============
DB_SetReorderIncludeSequence
==============
*/
void DB_SetReorderIncludeSequence()
{
	DBReorderAssetEntry* entry;
	unsigned int entryIter;

	for (entryIter = 0; entryIter < s_dbReorder.entryCount; ++entryIter)
	{
		entry = &s_dbReorder.entries[entryIter];
		if (entry->type == 43 && !I_strnicmp(entry->typeString, "include", 7))
		{
			entry->sequence = s_dbReorder.sequenceForIncludes;
		}
	}
}

/*
==============
DB_AddReorderAsset
==============
*/
void DB_AddReorderAsset(const char *typeString, const char *assetName)
{
	DBReorderAssetEntry* entry;
	int type;
	unsigned int entryIter;

	for (type = 0; type < ASSET_TYPE_COUNT; ++type)
	{
		if (!_stricmp(typeString, g_assetNames[type]))
		{
			break;
		}
	}

	if (type == 24)
	{
		assert(!strnicmp(assetName, REORDER_WEAPON_PREFIX, REORDER_WEAPON_PREFIX_LEN));
		assetName += 3;
	}

	for (entryIter = 0; entryIter < s_dbReorder.entryCount; ++entryIter)
	{
		entry = &s_dbReorder.entries[entryIter];
		if (entry->type == type
			&& !_stricmp(entry->assetName, assetName)
			&& !_stricmp(entry->typeString, typeString))
		{
			return;
		}
	}

	entry = &s_dbReorder.entries[s_dbReorder.entryCount++];
	entry->type = type;
	if (type >= 43)
	{
		entry->typeString = _strdup(typeString);
	}
	else
	{
		entry->typeString = g_assetNames[type];
	}

	entry->assetName = _strdup(assetName);
	if (entry->type == 43 && !I_stricmp(typeString, "ignore"))
	{
		entry->sequence = 0;
	}
	else if (entry->type != 11 && entry->type != 12)
	{
		entry->sequence = -1;
	}
	else
	{
		entry->sequence = 1;
	}
}

/*
==============
DB_NextZoneCsvToken
==============
*/
char DB_NextZoneCsvToken(const char **parse, char *token, unsigned int tokenSize, bool allowNewLine)
{
	unsigned int used;
	bool isSkippingLeadingSpaces;
	const char* scan;

	scan = *parse;
	if (*scan == '\n')
	{
		if (!allowNewLine)
		{
			return 0;
		}

		while (*scan == '\n')
		{
			++scan;
		}
	}

	if (!*scan)
	{
		*parse = scan;
		return 0;
	}

	if (*scan == ',')
	{
		++scan;
	}

	used = 0;
	isSkippingLeadingSpaces = 1;
	while (*scan && *scan != '\n' && *scan != ',')
	{
		if (!isSkippingLeadingSpaces || !isspace(*scan))
		{
			isSkippingLeadingSpaces = 0;
			if (used < tokenSize - 1)
			{
				token[used++] = *scan;
			}
		}
		++scan;
	}

	while (used && isspace(token[used - 1]))
	{
		--used;
	}

	token[used] = 0;
	*parse = scan;

	return 1;
}

/*
==============
DB_BeginReorderZone
==============
*/
void DB_BeginReorderZone(const char *zoneName)
{
	char* from;
	DBReorderAssetEntry* entry;
	char assetType[32];
	unsigned int size;
	void* file;
	int success;
	char assetName[256];
	char csvName[256];
	const char* parse;
	char* csv;
	char* to;
	unsigned int read;
	unsigned int entryIter;

	for (entryIter = 0; entryIter < s_dbReorder.entryCount; ++entryIter)
	{
		entry = &s_dbReorder.entries[entryIter];
		free((void*)entry->assetName);
		if (entry->type == 43)
		{
			free((void*)entry->typeString);
		}
	}
	s_dbReorder.entryCount = 0;
	s_dbReorder.sequence = 2;
	s_dbReorder.sequenceForIncludes = 3;
	s_dbReorder.alreadyFinished = 0;
	s_dbReorder.loadedSound = 0;
	s_dbReorder.loadedLocalization = 0;
	s_dbReorder.lastEntry = NULL;
	strcpy(s_dbReorder.zoneName, zoneName);

	Sys_LockWrite(&s_dbReorder.critSect);
	Com_sprintf(csvName, 256, "..\\share\\zone_source\\%s.csv", zoneName);
	file = CreateFile(csvName, 0x80000000, 0, NULL, 3, 0, NULL);
	if (file == INVALID_HANDLE_VALUE)
	{
		Sys_UnlockWrite(&s_dbReorder.critSect);
	}
	else
	{
		size = GetFileSize(file, NULL);
		csv = (char*)malloc(size + 1);
		success = ReadFile(file, csv, size, (LPDWORD)&read, NULL);
		CloseHandle(file);
		if (success && read == size)
		{
			csv[size] = 0;
			to = csv;
			for (from = csv; *from; ++from)
			{
				if (*from != 13)
				{
					*to++ = *from;
				}
			}

			*to = 0;
			for (parse = csv; DB_NextZoneCsvToken(&parse, assetType, 0x20u, 1); ++parse)
			{
				if (DB_NextZoneCsvToken(&parse, assetName, 0x100u, 0) && assetType[0] && assetName[0])
				{
					DB_AddReorderAsset(assetType, assetName);
				}

				while (*parse && *parse != 10)
				{
					++parse;
				}

				if (!*parse)
				{
					break;
				}
			}

			free(csv);
			Sys_UnlockWrite(&s_dbReorder.critSect);
		}
		else
		{
			free(csv);
			Sys_UnlockWrite(&s_dbReorder.critSect);
		}
	}
}

/*
==============
DB_PrintAssetName
==============
*/
void DB_PrintAssetName(XAssetHeader header, void *data)
{
	Com_Printf(0, "%s\n", DB_GetXAssetHeaderName(*(int*)data, &header));
}

/*
==============
DB_MarkAssetTypeUsageDirty
==============
*/
void DB_MarkAssetTypeUsageDirty()
{
	memset(s_usageUpToDate, 0, sizeof(s_usageUpToDate));
}

/*
==============
DB_GetAssetTypeUsageInfo
==============
*/
void DB_GetAssetTypeUsageInfo(XAssetType assetType, const char **outName, int *outUsed, int *outPool)
{
	if (!s_usageUpToDate[assetType])
	{
		s_usageUpToDate[assetType] = 1;
		s_usageCounts[assetType] = DB_GetAllXAssetOfType(assetType, NULL, 0);
	}
	*outUsed = s_usageCounts[assetType];
	*outPool = g_poolSize[assetType];
	*outName = g_assetNames[assetType];
}

/*
==============
DB_PrintXAssetsForType_FastFile
==============
*/
void DB_PrintXAssetsForType_FastFile(XAssetType type, void *inData, bool includeOverride)
{
	unsigned int hash;
	unsigned int assetEntryIndex;
	XAssetEntryPoolEntry* assetEntry;
	unsigned int overrideAssetEntryIndex;

	Sys_EnterCriticalSection(CRITSECT_DBHASH);
	for (hash = 0; hash < 0x12C00; ++hash)
	{
		for (assetEntryIndex = db_hashTable[hash];
			assetEntryIndex;
			assetEntryIndex = assetEntry->entry.nextHash)
		{
			assetEntry = &g_assetEntryPool[assetEntryIndex];
			if (assetEntry->entry.asset.type == type)
			{
				Com_Printf(CON_CHANNEL_DONT_FILTER, "%i: '%s','%s'\n",assetEntryIndex, DB_GetXAssetHeaderName(type, &assetEntry->entry.asset.header),
					g_zoneNames[assetEntry->entry.zoneIndex].name);
				if (includeOverride)
				{
					for (overrideAssetEntryIndex = assetEntry->entry.nextOverride;
						overrideAssetEntryIndex;
						overrideAssetEntryIndex = g_assetEntryPool[overrideAssetEntryIndex].entry.nextOverride)
					{
						Com_Printf(CON_CHANNEL_DONT_FILTER, "%i: '%s','%s'\n", overrideAssetEntryIndex,
							DB_GetXAssetHeaderName(type, &g_assetEntryPool[overrideAssetEntryIndex].entry.asset.header),
							g_zoneNames[g_assetEntryPool[overrideAssetEntryIndex].entry.zoneIndex].name);
					}
				}
			}
		}
	}
	Com_Printf(CON_CHANNEL_DONT_FILTER, "\n------Total assets: %d\n\n", assetEntryIndex);
	Sys_LeaveCriticalSection(CRITSECT_DBHASH);
}

/*
==============
DB_AllocXAssetSingleton
==============
*/
XAssetHeader DB_AllocXAssetSingleton(void* pool)
{
	XAssetHeader header;
	header.data = pool;

	return header;
}

/*
==============
DB_AllocXAsset<typename T>
==============
*/
template <typename T>
XAssetHeader DB_AllocXAsset(void* pool)
{
	XAssetHeader header;
	XAssetPool<T, 1>* castPool = (XAssetPool<T, 1> *)pool;

	if (castPool->freeHead)
	{
		header.data = &castPool->freeHead->entry;
		castPool->freeHead = castPool->freeHead->next;
	}
	else
	{
		header.data = NULL;
	}

	return header;
}

/*
==============
DB_InitPool<typename T>
==============
*/
template <typename T>
void DB_InitPool(void* pool, int size)
{
	int i;

	XAssetPool<T, 1>* castPool = (XAssetPool<T, 1> *)pool;

	castPool->freeHead = &castPool->entries[0];
	for (i = 0; i < size - 1; ++i)
	{
		castPool->entries[i].next = &castPool->entries[i + 1];
	}
	castPool->entries[size - 1].next = NULL;
}

/*
==============
DB_PrintXAssetsForType
==============
*/
inline void DB_PrintXAssetsForType(XAssetType type, void (*func)(XAssetHeader, void*), void* inData, bool includeOverride)
{
	if (IsFastFileLoad())
	{
		DB_PrintXAssetsForType_FastFile(type, &inData, includeOverride);
	}
	else
	{
		DB_EnumXAssets(type, func, &inData, includeOverride);
	}
}

/*
==============
DB_AllocXAssetHeader
==============
*/
XAssetHeader DB_AllocXAssetHeader(XAssetType type)
{
	XAssetHeader header;

	header = DB_AllocXAssetHeaderHandler[type](DB_XAssetPool[type]);
	if (header.data == NULL)
	{
		Sys_LeaveCriticalSection(CRITSECT_DBHASH);
		Com_PrintError(ERR_DROP, "Exceeded limit of %d '%s' assets.\n", g_poolSize[type], g_assetNames[type]);
		DB_PrintXAssetsForType(type, DB_PrintAssetName, &type, 1);
		Com_Error(ERR_DROP, "Exceeded limit of %d '%s' assets.\n", g_poolSize[type], g_assetNames[type]);
	}
	return header;
}

char dvarname[32][4];
XAssetEntryPoolEntry* g_freeAssetEntryHead;

/*
==============
DB_Init
==============
*/
void DB_Init()
{
	int i, j;
	void* type;

	db_xassetdebug = _Dvar_RegisterBool("db_xassetdebug", 0, 0, "debug assets loading");
	db_xassetdebugtype = _Dvar_RegisterInt("db_xassetdebugtype", -1, -2, 60, 0, "debug assets loading type: -1 all; indexes start at 0");
	db_xassetdebugname = _Dvar_RegisterString("db_xassetdebugname", "", 0, "");

	for (i = 0; i < 4; ++i)
	{
		_snprintf(dvarname[i], 0x20u, "gump_name%u", i);
		gump_name[i] = _Dvar_RegisterString(dvarname[i], "", 0, "");
	}
	restore_gump_name = _Dvar_RegisterString("restore_gump_name", "", 0, "");

	DB_InitFFOTDMem();
	DB_Init_Reading();
	for (j = 0; j < 60; ++j)
	{
		type = DB_XAssetPool[j];
		if (type)
		{
			DB_InitPoolHeaderHandler[j](type, g_poolSize[j]);
		}
	}
	g_freeAssetEntryHead = &g_assetEntryPool[1];
	for (i = 1; i < XASSET_ENTRY_POOL_SIZE - 1; ++i)
	{
		g_assetEntryPool[i].next = &g_assetEntryPool[i + 1];
	}

	g_assetEntryPool[XASSET_ENTRY_POOL_SIZE - 1].next = NULL;
}

int XAssetEntryHighWaterMark;
int XAssetEntryHighCount;

/*
==============
DB_AllocXAssetEntry
==============
*/
XAssetEntry *DB_AllocXAssetEntry(XAssetType type, unsigned int zoneIndex)
{
	XAssetEntryPoolEntry* freeHead;

	freeHead = g_freeAssetEntryHead;
	if (!g_freeAssetEntryHead)
	{
		Sys_LeaveCriticalSection(CRITSECT_DBHASH);
		Com_Error(ERR_DROP, "Could not allocate asset - increase XASSET_ENTRY_POOL_SIZE");
	}

	if (++XAssetEntryHighCount > XAssetEntryHighWaterMark)
	{
		XAssetEntryHighWaterMark = XAssetEntryHighCount;
	}

	g_freeAssetEntryHead = freeHead->next;
	freeHead->entry.asset.type = type;
	freeHead->entry.asset.header = DB_AllocXAssetHeader(type);
	freeHead->entry.zoneIndex = zoneIndex;
	freeHead->entry.inuse = 0;
	freeHead->entry.nextHash = 0;
	freeHead->entry.nextOverride = 0;

	return &freeHead->entry;
}

/*
==============
DB_FreeXAssetEntry
==============
*/
void DB_FreeXAssetEntry(XAssetEntry *assetEntry)
{
	XAssetEntryPoolEntry* oldFreeHead;

	//(DB_FreeXAssetHeaderHandler[assetEntry->asset.type])();
	--XAssetEntryHighCount;
	oldFreeHead = g_freeAssetEntryHead;
	g_freeAssetEntryHead = (XAssetEntryPoolEntry*)assetEntry;
	*(XAssetEntryPoolEntry**)assetEntry = oldFreeHead;
}

int g_missingAssetFile;
int com_missingAssetOpenFailed;

/*
==============
DB_LogMissingAsset
==============
*/
void DB_LogMissingAsset(XAssetType type, const char *name)
{
	char msg[1024];

	switch (type)
	{
	case ASSET_TYPE_SOUND:
	case ASSET_TYPE_MENU:
	case ASSET_TYPE_LOCALIZE_ENTRY:
	case ASSET_TYPE_SNDDRIVER_GLOBALS:
	case ASSET_TYPE_XGLOBALS:
		return;
	case ASSET_TYPE_WEAPON:
		Com_sprintf(msg, sizeof(msg), "%s,mp/%s\n", g_assetNames[type], name);
		break;
	default:
		Com_sprintf(msg, sizeof(msg), "%s,%s\n", g_assetNames[type], name);
		break;
	}

	Sys_EnterCriticalSection(CRITSECT_MISSING_ASSET);
	if (g_missingAssetFile)
	{
		g_missingAssetFile = FS_FOpenFileAppend("missingasset.csv");
	}
	else
	{
		g_missingAssetFile = FS_FOpenTextFileWrite("missingasset.csv");
	}

	if (g_missingAssetFile)
	{
		FS_Write(msg, strlen(msg), g_missingAssetFile);
		FS_FCloseFile(g_missingAssetFile);
	}
	else
	{
		com_missingAssetOpenFailed = 1;
	}
	Sys_LeaveCriticalSection(CRITSECT_MISSING_ASSET);
}

/*
==============
DB_EnumXAssets_FastFile
==============
*/
void DB_EnumXAssets_FastFile(XAssetType type, void (*func)(XAssetHeader, void *), void *inData, bool includeOverride)
{
	unsigned int hash;
	unsigned int assetEntryIndex;
	XAssetEntryPoolEntry* assetEntry;
	unsigned int overrideAssetEntryIndex;

	Sys_EnterCriticalSection(CRITSECT_DBHASH);
	for (hash = 0; hash < 0x12C00; ++hash)
	{
		for (assetEntryIndex = db_hashTable[hash];
			assetEntryIndex;
			assetEntryIndex = assetEntry->entry.nextHash)
		{
			assetEntry = &g_assetEntryPool[assetEntryIndex];
			if (assetEntry->entry.asset.type == type)
			{
				func(assetEntry->entry.asset.header, inData);
				if (includeOverride)
				{
					for (overrideAssetEntryIndex = assetEntry->entry.nextOverride;
						overrideAssetEntryIndex;
						overrideAssetEntryIndex = g_assetEntryPool[overrideAssetEntryIndex].entry.nextOverride)
					{
						func(g_assetEntryPool[overrideAssetEntryIndex].entry.asset.header, inData);
					}
				}
			}
		}
	}
	Sys_LeaveCriticalSection(CRITSECT_DBHASH);
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
DB_CloneXAssetInternal
==============
*/
inline void DB_CloneXAssetInternal(const XAsset* from, XAsset* to)
{
	int size;

	assert(from->type == to->type);
	size = DB_GetXAssetTypeSize(from->type);
	memcpy(to->header.data, from->header.data, size);
}

void(__cdecl* DB_DynamicCloneXAssetHandler[60])(const XAssetHeader, XAssetHeader, DBCloneMethod) =
{
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  &DB_DynamicCloneMenu,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};

/*
==============
DB_CloneXAsset
==============
*/
void DB_CloneXAsset(const XAsset *from, XAsset *to, DBCloneMethod cloneMethod)
{
	assert(from->type == to->type);
	if (DB_DynamicCloneXAssetHandler[to->type])
	{
		DB_DynamicCloneXAssetHandler[to->type](from->header, to->header, cloneMethod);
	}
	DB_CloneXAssetInternal(from, to);
}

void(__cdecl* DB_DynamicCloneXAssetHandler[60])(const XAssetHeader, XAssetHeader, DBCloneMethod) =
{
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  &DB_DynamicCloneMenu,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};

/*
==============
DB_SwapXAsset
==============
*/
void DB_SwapXAsset(const XAsset *from, XAsset *to)
{
	XAsset asset;
	unsigned int size;

	assert(from->type == to->type);

	if (DB_DynamicCloneXAssetHandler[to->type])
	{
		DB_DynamicCloneXAssetHandler[to->type](from->header, to->header, DB_CLONE_SWAP);
	}

	size = DB_GetXAssetTypeSize(from->type);
	asset.header = from->header;
	asset.type = from->type;
	DB_CloneXAssetInternal(to, &asset);
	DB_CloneXAssetInternal(from, to);
	DB_CloneXAssetInternal(from, &asset);
}

unsigned int g_copyInfoCount;

/*
==============
DB_DelayedCloneXAsset
==============
*/
void DB_DelayedCloneXAsset(XAssetEntry *newEntry)
{
	unsigned int i;
	const char* debugName;

	if (g_copyInfoCount >= 0xC00)
	{
		Com_Printf(0, "g_copyInfo exceeded: too many asset overrides in one call to DB_LoadXAssets.\n");
		for (i = 0; i < 0xC00; ++i)
		{
			Com_Printf(0, "'%s','%s'\n", DB_GetXAssetTypeName(g_copyInfo[i]->asset.type), DB_GetXAssetName(&g_copyInfo[i]->asset));
		}
		Sys_Error("g_copyInfo exceeded");
	}
	if (Dvar_GetBool(db_xassetdebug))
	{
		debugName = Dvar_GetString(db_xassetdebugname);
		if (Dvar_GetInt(db_xassetdebugtype) == -1
			|| Dvar_GetInt(db_xassetdebugtype) == newEntry->asset.type
			|| debugName[0]
			&& !I_stricmp(DB_GetXAssetName(&newEntry->asset), debugName))
		{
			Com_Printf(CON_CHANNEL_SYSTEM, "DB_DelayedCloneXAsset: postponed load asset: '%s','%s' from fastfile %s\n", DB_GetXAssetTypeName(newEntry->asset.type), DB_GetXAssetName(&newEntry->asset), &g_zoneNames[newEntry->zoneIndex]);
		}
	}
	g_copyInfo[g_copyInfoCount++] = newEntry;
}

/*
==============
DB_HashForName
==============
*/
inline unsigned int DB_HashForName_Inline(const char* name, XAssetType type)
{
	const char* pos;
	unsigned int hash;
	int c;

	hash = type;
	for (pos = name; *pos; ++pos)
	{
		c = tolower(*pos);
		if (c == '\\')
		{
			c = '/';
		}
		hash = (hash << 16) + c + (hash << 6) - hash;
	}
	return hash;
}

/*
==============
DB_FindXAssetEntry
==============
*/
XAssetEntry *DB_FindXAssetEntry(XAssetType type, const char *name)
{
	unsigned int assetEntryIndex;
	XAssetEntry* assetEntry;

	for (assetEntryIndex = db_hashTable[DB_HashForName_Inline(name, type) % 0x9600];
		assetEntryIndex;
		assetEntryIndex = assetEntry->nextHash)
	{
		assetEntry = &g_assetEntryPool[assetEntryIndex].entry;
		if (assetEntry->asset.type == type)
		{
			if (!I_stricmp(DB_GetXAssetName(&assetEntry->asset), name))
			{
				return assetEntry;
			}
		}
	}
	return 0;
}

const char* g_defaultAssetName[60] =
{
  "",
  "default",
  "default",
  "defaultdestructible",
  "void",
  "void",
  "$default",
  "default",
  "$white",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "light_dynamic",
  "",
  "fonts/720/consolefont",
  "fonticon/defaultFontIcon.csv",
  "ui/default.menu",
  "default_menu",
  "CGAME_UNKNOWN",
  "defaultweapon_mp",
  "",
  "",
  "",
  "defaultattachment",
  "",
  "defaultcamo",
  "",
  "misc/missing_fx",
  "default",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "mp/defaultStringTable.csv",
  "DEFAULT_LB",
  "",
  "",
  "",
  "",
  "common_scripts/default",
  "",
  "defaultvehicle_mp",
  "",
  "",
  "defaulttracer",
  "",
  "",
  "",
  "",
  "",
  ""
};

/*
==============
DB_FindXAssetDefaultHeaderInternal
==============
*/
XAssetHeader DB_FindXAssetDefaultHeaderInternal(XAssetType type)
{
	unsigned int assetEntryIndex;
	const char* name;
	XAssetEntryPoolEntry* assetEntry;

	name = g_defaultAssetName[type];
	for (assetEntryIndex = db_hashTable[DB_HashForName_Inline(name, type) % 0x9600u]; ;
		assetEntryIndex = assetEntry->entry.nextHash)
	{
		if (!assetEntryIndex)
		{
			XAssetHeader header = { 0 };
			return header;
		}

		assetEntry = &g_assetEntryPool[assetEntryIndex];
		if (assetEntry->entry.asset.type == type)
		{
			if (!I_stricmp(DB_GetXAssetName(&assetEntry->entry.asset), name))
			{
				break;
			}
		}
	}

	while (assetEntry->entry.nextOverride)
	{
		assetEntry = &g_assetEntryPool[assetEntry->entry.nextOverride];
	}

	return assetEntry->entry.asset.header;
}

int g_defaultAssetCount;

/*
==============
DB_CreateDefaultEntry
==============
*/
XAssetEntry *DB_CreateDefaultEntry(XAssetType type, const char *name)
{
	unsigned int hash;
	XAsset asset;
	XAssetEntryPoolEntry* newEntry;

	asset.header = DB_FindXAssetDefaultHeaderInternal(type);
	if (!asset.header.data)
	{
		Sys_LeaveCriticalSection(CRITSECT_DBHASH);
		if (type != ASSET_TYPE_CLIPMAP && type != ASSET_TYPE_CLIPMAP_PVS)
		{
			Com_Error(
				ERR_DROP,
				"Could not load default asset '%s' for asset type '%s'.\nTried to load asset '%s'.",
				g_defaultAssetName[type],
				DB_GetXAssetTypeName(type),
				name);
		}
		else
		{
			Com_Error(
				ERR_DROP,
				"Couldn't find the bsp for this map.  Please build the fast file associated with %s and try again.",
				name);
		}
	}

	asset.type = type;
	++g_defaultAssetCount;

	newEntry = (XAssetEntryPoolEntry*)DB_AllocXAssetEntry(type, 0);
	DB_CloneXAssetInternal(&asset, &newEntry->entry.asset);
	hash = DB_HashForName_Inline(name, type);
	newEntry->entry.nextHash = db_hashTable[hash % 0x9600];
	db_hashTable[hash % 0x9600] = newEntry - g_assetEntryPool;

	DB_SetXAssetName(&newEntry->entry.asset, SL_ConvertToString(SL_GetString(name, 4, SCRIPTINSTANCE_SERVER)));
	newEntry->entry.inuse = 1;

	if (Dvar_GetInt(db_xassetdebug))
	{
		if (Dvar_GetInt(db_xassetdebug) == -1
			|| Dvar_GetInt(db_xassetdebug) == type
			|| *Dvar_GetString(db_xassetdebugname) && !I_stricmp(name, Dvar_GetString(db_xassetdebugname)))
		{
			Com_Printf(CON_CHANNEL_SYSTEM, "DB_CreateDefaultEntry: used default asset: '%s','%s' for asset name: '%s'\n",
				DB_GetXAssetTypeName(asset.type), DB_GetXAssetName(&asset), name);
		}
	}
	return (XAssetEntry*)newEntry;
}

/*
==============
DB_ListDefaultEntries_f
==============
*/
void DB_ListDefaultEntries_f()
{
	unsigned int nextAssetEntryIndex;
	unsigned int hash;
	unsigned int assetEntryIndex;
	XAssetEntryPoolEntry* assetEntry;
	unsigned int defaultAssetCount;
	unsigned int defaultAssetsSize;

	Sys_EnterCriticalSection(CRITSECT_DBHASH);
	defaultAssetCount = g_defaultAssetCount;
	defaultAssetsSize = 0;
	for (hash = 0; hash < 0x12C00; ++hash)
	{
		for (assetEntryIndex = db_hashTable[hash]; assetEntryIndex; assetEntryIndex = nextAssetEntryIndex)
		{
			assetEntry = &g_assetEntryPool[assetEntryIndex];
			nextAssetEntryIndex = assetEntry->entry.nextHash;
			if (!g_assetEntryPool[assetEntryIndex].entry.zoneIndex)
			{
				--defaultAssetCount;
				Com_Printf(CON_CHANNEL_SYSTEM, "%s,%s\n", DB_GetXAssetTypeName(assetEntry->entry.asset.type), DB_GetXAssetName(&assetEntry->entry.asset));
				defaultAssetsSize += DB_GetXAssetTypeSize(assetEntry->entry.asset.type);
			}
		}
	}

	Com_Printf(CON_CHANNEL_SYSTEM, "Total default assets %d, size %d\n", g_defaultAssetCount, defaultAssetsSize);
	assert(!defaultAssetCount);
	Sys_LeaveCriticalSection(CRITSECT_DBHASH);
}

/*
==============
DB_ListAssetPool
==============
*/
void DB_ListAssetPool(XAssetType type)
{
	XAssetEntryPoolEntry* overrideAssetEntry;
	unsigned int nextAssetEntryIndex;
	unsigned int hash;
	unsigned int assetPoolSize;
	unsigned int assetEntryIndex;
	unsigned int assetPoolCount;
	XAssetEntryPoolEntry* assetEntry;
	unsigned int overrideAssetEntryIndex;

	Sys_EnterCriticalSection(CRITSECT_DBHASH);
	assetPoolCount = 0;
	assetPoolSize = 0;
	Com_Printf(CON_CHANNEL_SYSTEM, "Listing assets in %s pool.\n", DB_GetXAssetTypeName(type));
	for (hash = 0; hash < 0x12C00; ++hash)
	{
		for (assetEntryIndex = db_hashTable[hash]; assetEntryIndex; assetEntryIndex = nextAssetEntryIndex)
		{
			assetEntry = &g_assetEntryPool[assetEntryIndex];
			nextAssetEntryIndex = g_assetEntryPool[assetEntryIndex].entry.nextHash;
			if (g_assetEntryPool[assetEntryIndex].entry.asset.type == type)
			{
				++assetPoolCount;
				Com_Printf(CON_CHANNEL_SYSTEM, "%s,%s\n", DB_GetXAssetName(&assetEntry->entry.asset), g_zoneNames[assetEntry->entry.zoneIndex].name);
				assetPoolSize += DB_GetXAssetTypeSize(assetEntry->entry.asset.type);

				for (overrideAssetEntryIndex = assetEntry->entry.nextOverride;
					overrideAssetEntryIndex;
					overrideAssetEntryIndex = overrideAssetEntry->entry.nextOverride)
				{
					overrideAssetEntry = &g_assetEntryPool[overrideAssetEntryIndex];
					++assetPoolCount;
					Com_Printf(CON_CHANNEL_SYSTEM, "%s,%s\n", DB_GetXAssetName(&g_assetEntryPool[overrideAssetEntryIndex].entry.asset),
						g_zoneNames[g_assetEntryPool[overrideAssetEntryIndex].entry.zoneIndex].name);
					assetPoolSize += DB_GetXAssetTypeSize(overrideAssetEntry->entry.asset.type);
				}
			}
		}
	}

	Com_Printf(CON_CHANNEL_SYSTEM, "Total of %d assets in %s pool, size %d\n", assetPoolCount, DB_GetXAssetTypeName(type), assetPoolSize);
	Sys_LeaveCriticalSection(CRITSECT_DBHASH);
}

/*
==============
DB_ListAssetPool_f
==============
*/
void DB_ListAssetPool_f()
{
	XAssetType type;
	int i;

	if (Cmd_Argc() >= 2)
	{
		type = (XAssetType)atoi(Cmd_Argv(1));
		DB_ListAssetPool(type);
	}
	else
	{
		Com_Printf(0, "listassetpool <poolnumber>: lists all the assets in the specified pool\n");
		for (i = 0; i < 43; ++i)
		{
			Com_Printf(0, "%d %s\n", i, DB_GetXAssetTypeName(i));
		}
	}
}

/*
==============
DB_DumpMaterialList_f
==============
*/
void DB_DumpMaterialList_f()
{
	XAssetType type = ASSET_TYPE_MATERIAL;
	DB_PrintXAssetsForType(type, DB_PrintAssetName, &type, 1);
}

/*
==============
DB_DumpModels_f
==============
*/
void DB_DumpModels_f()
{
	XAssetType type = ASSET_TYPE_XMODEL;
	DB_PrintXAssetsForType(type, DB_PrintAssetName, &type, 1);
}

/*
==============
IsConfigFile
==============
*/
bool IsConfigFile(const char *name)
{
	assert(name);
	return strstr(name, ".cfg") != 0;
}

/*
==============
PrintWaitedError
==============
*/
void PrintWaitedError(XAssetType type, const char *name, int waitedMsec)
{
	if (waitedMsec > 100)
	{
		if (type == ASSET_TYPE_SOUND)
		{
			Com_Printf(CON_CHANNEL_FILES, "Waited %i msec for missing asset \"%s\".\n", waitedMsec, name);
		}
		else
		{
			Com_PrintError(1, "Waited %i msec for missing asset \"%s\".\n", waitedMsec, name);
		}
	}
	switch (type)
	{
	case ASSET_TYPE_XANIMPARTS:
		Com_PrintWarning(CON_CHANNEL_FILES, "Could not load %s \"%s\".\n", g_assetNames[type], name);
		break;
	case ASSET_TYPE_XMODEL:
	case ASSET_TYPE_SOUND:
		return;
	case ASSET_TYPE_LOCALIZE_ENTRY:
		if (loc_warnings->current.enabled)
		{
			if (loc_warningsAsErrors->current.enabled)
			{
				Com_PrintError(1, "Could not load %s \"%s\".\n", g_assetNames[type], name);
			}
			else
			{
				Com_PrintWarning(CON_CHANNEL_FILES, "Could not load %s \"%s\".\n", g_assetNames[type], name);
			}
		}
		break;
	case ASSET_TYPE_RAWFILE:
		if (!IsConfigFile(name))
		{
			Com_PrintError(1, "Could not load %s \"%s\".\n", g_assetNames[type], name);
		}
		break;
	default:
		Com_PrintError(1, "Could not load %s \"%s\".\n", g_assetNames[type], name);
		break;
	}
}

/*
==============
DB_DoesXAssetExist
==============
*/
bool DB_DoesXAssetExist(XAssetType type, const char* name)
{
	XAssetEntryPoolEntry* asset;

	Sys_EnterCriticalSection(CRITSECT_DBHASH);
	asset = (XAssetEntryPoolEntry*)DB_FindXAssetEntry(type, name);
	Sys_LeaveCriticalSection(CRITSECT_DBHASH);
	
	if (asset)
	{
		if (type == ASSET_TYPE_XMODEL && XModelBad(asset->entry.asset.header.model))
		{
			return 0;
		}
		else if (type == ASSET_TYPE_XANIMPARTS && XAnimIsDefault(asset->entry.asset.header.parts))
		{
			return 0;
		}
		return 1;
	}
	return 0;
}

/*
==============
DB_DoesXAssetExist
==============
*/
bool DB_DoesXAssetExist(const char *typeName, const char *name)
{
	int i;
	XAssetEntryPoolEntry* asset;

	for (i = 0; i < 60; ++i)
	{
		if (!I_stricmp(typeName, g_assetNames[i]))
			break;
	}
	if (i == 60)
	{
		Com_Error(ERR_SCRIPT, "type %s is not a valid asset type: see g_assetNames in db_assetnames.h\n", typeName);
		return 0;
	}

	return DB_DoesXAssetExist((XAssetType)i, name);
}

bool g_initializing;

/*
==============
DB_SetInitializing
==============
*/
void DB_SetInitializing(bool inUse)
{
	g_initializing = inUse;
}

/*
==============
DB_IsXAssetDefault
==============
*/
bool DB_IsXAssetDefault(XAssetType a1, XAssetType type, const char *name)
{
	unsigned int hash;
	unsigned int assetEntryIndex;
	XAssetEntryPoolEntry* assetEntry;

	hash = DB_HashForName_Inline(name, type);
	Sys_EnterCriticalSection(CRITSECT_DBHASH);
	for (assetEntryIndex = db_hashTable[hash % 0x9600];
		assetEntryIndex;
		assetEntryIndex = assetEntry->entry.nextHash)
	{
		assetEntry = &g_assetEntryPool[assetEntryIndex];
		if (assetEntry->entry.asset.type == type)
		{
			if (!I_stricmp(DB_GetXAssetName(&assetEntry->entry.asset), name))
			{
				Sys_LeaveCriticalSection(CRITSECT_DBHASH);
				return assetEntry->entry.zoneIndex == 0;
			}
		}
	}
	Sys_LeaveCriticalSection(CRITSECT_DBHASH);
	assertMsg("unreachable");

	return 1;
}

/*
==============
DB_GetAllXAssetOfType_FastFile
==============
*/
int DB_GetAllXAssetOfType_FastFile(XAssetType type, XAssetHeader *assets, int maxCount)
{
	unsigned int hash;
	unsigned int assetEntryIndex;
	int assetCount;
	XAssetEntryPoolEntry* assetEntry;

	assetCount = 0;
	Sys_EnterCriticalSection(CRITSECT_DBHASH);
	for (hash = 0; hash < 0x12C00; ++hash)
	{
		for (assetEntryIndex = db_hashTable[hash];
			assetEntryIndex;
			assetEntryIndex = assetEntry->entry.nextHash)
		{
			assetEntry = &g_assetEntryPool[assetEntryIndex];
			if (assetEntry->entry.asset.type == type)
			{
				if (assets)
				{
					assert(assetCount < maxCount);
					assets[assetCount] = assetEntry->entry.asset.header;
				}
				++assetCount;
			}
		}
	}

	Sys_LeaveCriticalSection(CRITSECT_DBHASH);

	return assetCount;
}

bool g_mayRecoverLostAssets;
bool g_isRecoveringLostDevice;

/*
==============
DB_SyncLostDevice
==============
*/
void DB_SyncLostDevice()
{
	if (g_isRecoveringLostDevice)
	{
		assert(!g_mayRecoverLostAssets);
		g_mayRecoverLostAssets = 1;
		do
		{
			NET_Sleep(25);
		} while (g_isRecoveringLostDevice);
		assert(!g_mayRecoverLostAssets);
	}
}

/*
==============
DB_GetZonePriority
==============
*/
int DB_GetZonePriority(int zone)
{
	switch (zone)
	{
	case 0x4000000:
		return 58;
	case 0x10000000:
		return 50;
	case 0x2000000:
		return 8;
	case 0x400000:
		return 62;
	case 0x800000:
		return 3;
	case 0x1000000:
		return 53;
	case 0x200000:
		return 12;
	case 0x40000:
		return 57;
	case 0x80000:
		return 7;
	case 0x20000:
		return 6;
	case 0x4000:
		return 55;
	case 0x8000:
		return 5;
	case 0x10000:
		return 56;
	case 1:
		return 51;
	case 2:
		return 1;
	case 4:
		return 63;
	case 8:
		return 13;
	case 16:
		return 59;
	case 32:
		return 9;
	case 0x2000:
		return 4;
	case 2048:
		return 10;
	case 4096:
		return 54;
	case 1024:
		return 60;
	case 128:
		return 11;
	case 256:
		return 52;
	case 512:
		return 2;
	case 64:
		return 61;
	default:
		assert(0);
		return 0;
	}
}

/*
==============
DB_OverrideAsset
==============
*/
int DB_OverrideAsset(unsigned int newZoneIndex, unsigned int existingZoneIndex, XAssetType type)
{
	int newPriority;

	assert(newZoneIndex);
	assert(existingZoneIndex);

	newPriority = DB_GetZonePriority(g_zoneNames[newZoneIndex].flags & 0x17FFFFFF);
	return newPriority >= DB_GetZonePriority(g_zoneNames[existingZoneIndex].flags & 0x17FFFFFF);
}

unsigned int g_zoneIndex;
XAsset* varXAsset;

/*
==============
DB_LinkXAssetEntry
==============
*/
XAssetEntry *DB_LinkXAssetEntry(XAssetEntry *newEntry, int allowOverride)
{
	const char* debugName;
	const char* poolName;
	XAssetEntry* existingEntry;
	unsigned int hash;
	unsigned int existingEntryIndex;
	XAssetEntryPoolEntry* overrideAssetEntry;
	XAsset asset;
	int isStubAsset;
	const char* name;
	unsigned char zoneIndex;
	XAssetType type;
	unsigned short* pOverrideAssetEntryIndex;

	name = DB_GetXAssetName(&newEntry->asset);
	if (Dvar_GetBool(db_xassetdebug))
	{
		debugName = Dvar_GetString(db_xassetdebugname);
		if (Dvar_GetInt(db_xassetdebugtype) == -1
			|| Dvar_GetInt(db_xassetdebugtype) == newEntry->asset.type
			|| debugName[0] && !I_stricmp(name, debugName))
		{
			Com_Printf(CON_CHANNEL_SYSTEM, "***db_xassetdebug:***\nDB_LinkXAssetEntry: link asset: '%s','%s'\n", DB_GetXAssetTypeName(newEntry->asset.type), name);
		}
	}

	isStubAsset = name[0] == ',';
	if (isStubAsset)
	{
		++name;
	}

	type = newEntry->asset.type;
	hash = DB_HashForName_Inline(name, type);
	for (existingEntryIndex = db_hashTable[hash % 0x9600];
		existingEntryIndex;
		existingEntryIndex = existingEntry->nextHash)
	{
		existingEntry = &g_assetEntryPool[existingEntryIndex].entry;
		if (existingEntry->asset.type == type)
		{
			if (hash == DB_HashForName_Inline(DB_GetXAssetName(&existingEntry->asset), type))
			{
				if (I_stricmp(DB_GetXAssetName(&existingEntry->asset), name))
				{
					break;
				}
			}
		}
	}

	existingEntry = NULL;
	for (existingEntryIndex = db_hashTable[hash % 0x9600];
		existingEntryIndex;
		existingEntryIndex = existingEntry->nextHash)
	{
		existingEntry = &g_assetEntryPool[existingEntryIndex].entry;
		if (existingEntry->asset.type == type)
		{
			if (!I_stricmp(DB_GetXAssetName(&existingEntry->asset), name))
			{
				if (Dvar_GetBool(db_xassetdebug))
				{
					debugName = Dvar_GetString(db_xassetdebugname);
					if (Dvar_GetInt(db_xassetdebugtype) == -1
						|| Dvar_GetInt(db_xassetdebugtype) == newEntry->asset.type
						|| debugName[0]
						&& !I_stricmp(name, debugName))
					{
						if (g_zoneNames[existingEntry->zoneIndex].name[0])
						{
							poolName = g_zoneNames[existingEntry->zoneIndex].name;
						}
						else
						{
							poolName = "default asset pool";
						}
						Com_Printf(CON_CHANNEL_SYSTEM, "DB_LinkXAssetEntry: existing asset: '%s','%s' loaded from fastfile: '%s'\n",
							DB_GetXAssetTypeName(newEntry->asset.type), name, poolName);
					}
				}
				break;
			}
		}
	}

	if (allowOverride)
	{
		assert(!isStubAsset);
	}
	else
	{
		if (isStubAsset)
		{
			if (!existingEntryIndex)
			{
				return DB_CreateDefaultEntry(type, name);
			}

			assert(existingEntry);
			if (Dvar_GetBool(db_xassetdebug))
			{
				debugName = Dvar_GetString(db_xassetdebugname);
				if (Dvar_GetInt(db_xassetdebugtype) == -1
					|| Dvar_GetInt(db_xassetdebugtype) == newEntry->asset.type
					|| debugName[0] && !I_stricmp(name, debugName))
				{
					Com_Printf(CON_CHANNEL_SYSTEM, "DB_LinkXAssetEntry: stub asset: '%s','%s' already exists. Using existingEntry\n",
						DB_GetXAssetTypeName(newEntry->asset.type), name);
				}
			}

			return existingEntry;
		}

		asset.type = newEntry->asset.type;
		asset.header = newEntry->asset.header;
		newEntry = DB_AllocXAssetEntry(asset.type, g_zoneIndex);
		DB_CloneXAssetInternal(&asset, &newEntry->asset);
	}

	if (!existingEntryIndex)
	{
		if (Dvar_GetBool(db_xassetdebug))
		{
			debugName = Dvar_GetString(db_xassetdebugname);
			if (Dvar_GetInt(db_xassetdebugtype) == -1
				|| Dvar_GetInt(db_xassetdebugtype) == newEntry->asset.type
				|| debugName[0] && !I_stricmp(name, debugName))
			{
				Com_Printf(CON_CHANNEL_SYSTEM, "DB_LinkXAssetEntry: created new asset: '%s','%s'\n",
					DB_GetXAssetTypeName(newEntry->asset.type), name);
			}
		}

		newEntry->nextHash = db_hashTable[hash % 0x9600];
		db_hashTable[hash % 0x9600] = (XAssetEntryPoolEntry*)newEntry - g_assetEntryPool;
		if (Dvar_GetBool(db_xassetdebug))
		{
			debugName = Dvar_GetString(db_xassetdebugname);
			if (Dvar_GetInt(db_xassetdebugtype) == -1
				|| Dvar_GetInt(db_xassetdebugtype) == newEntry->asset.type
				|| debugName[0] && !I_stricmp(name, debugName))
			{
				Com_Printf(CON_CHANNEL_SYSTEM, "DB_LinkXAssetEntry: return new asset: '%s','%s' loaded from fastfile: '%s'\n",
					DB_GetXAssetTypeName(newEntry->asset.type), name, g_zoneNames[newEntry->zoneIndex].name);
			}
		}
		return newEntry;
	}

	assert(existingEntry);
	if (existingEntry->zoneIndex)
	{
		assert(existingEntry->zoneIndex != newEntry->zoneIndex);
		if (!*g_defaultAssetName[type] && type != ASSET_TYPE_RAWFILE && type != ASSET_TYPE_MAP_ENTS)
		{
			Sys_LeaveCriticalSection(CRITSECT_DBHASH);
			Com_Error(
				ERR_DROP,
				"Attempting to override asset '%s' from zone '%s' with zone '%s'",
				name,
				g_zoneNames[existingEntry->zoneIndex].name,
				g_zoneNames[newEntry->zoneIndex].name);
		}

		if (!DB_OverrideAsset(newEntry->zoneIndex, existingEntry->zoneIndex, type))
		{
			for (pOverrideAssetEntryIndex = &existingEntry->nextOverride;
				*pOverrideAssetEntryIndex;
				pOverrideAssetEntryIndex = &overrideAssetEntry->entry.nextOverride)
			{
				overrideAssetEntry = &g_assetEntryPool[*pOverrideAssetEntryIndex];
				if (DB_OverrideAsset(
					newEntry->zoneIndex,
					overrideAssetEntry->entry.zoneIndex,
					type))
				{
					break;
				}
			}
			if (Dvar_GetBool(db_xassetdebug))
			{
				debugName = Dvar_GetString(db_xassetdebugname);
				if (Dvar_GetInt(db_xassetdebugtype) == -1
					|| Dvar_GetInt(db_xassetdebugtype) == newEntry->asset.type
					|| debugName[0] && !I_stricmp(name, debugName))
				{
					Com_Printf(CON_CHANNEL_SYSTEM, "DB_LinkXAssetEntry: keep existing asset, and put new in its override position\n");
				}
			}
			newEntry->nextOverride = *pOverrideAssetEntryIndex;
			*pOverrideAssetEntryIndex = (XAssetEntryPoolEntry*)newEntry - g_assetEntryPool;
			return existingEntry;
		}
		goto LABEL_106;
	}

	assert(g_defaultAssetName[type][0]);
	assert(!existingEntry->nextOverride);
	assert(g_defaultAssetCount);
	if (!allowOverride)
	{
	LABEL_106:
		if (allowOverride)
		{
			assert(existingEntry->zoneIndex);
			if (existingEntry->inuse)
			{
				varXAsset = &existingEntry->asset;
				Mark_XAsset();
			}
			if (Dvar_GetBool(db_xassetdebug))
			{
				debugName = Dvar_GetString(db_xassetdebugname);
				if (Dvar_GetInt(db_xassetdebugtype) == -1
					|| Dvar_GetInt(db_xassetdebugtype) == newEntry->asset.type
					|| debugName[0] && !I_stricmp(name, debugName))
				{
					Com_Printf(
						16,
						"DB_LinkXAssetEntry: swapping existing asset: '%s','%s' with new asset loaded from fastfile: '%s'\n",
						DB_GetXAssetTypeName(newEntry->asset.type),
						name,
						g_zoneNames[newEntry->zoneIndex].name);
				}
			}
			newEntry->nextOverride = existingEntry->nextOverride;
			existingEntry->nextOverride = (XAssetEntryPoolEntry*)newEntry - g_assetEntryPool;
			DB_SwapXAsset(&newEntry->asset, &existingEntry->asset);
			zoneIndex = existingEntry->zoneIndex;
			existingEntry->zoneIndex = newEntry->zoneIndex;
			newEntry->zoneIndex = zoneIndex;
		}
		else
		{
			DB_DelayedCloneXAsset(newEntry);
		}

		if (Dvar_GetBool(db_xassetdebug))
		{
			debugName = Dvar_GetString(db_xassetdebugname);
			if (Dvar_GetInt(db_xassetdebugtype) == -1
				|| Dvar_GetInt(db_xassetdebugtype) == existingEntry->asset.type
				|| debugName[0] && !I_stricmp(name, debugName))
			{
				if (g_zoneNames[existingEntry->zoneIndex].name[0])
				{
					poolName = g_zoneNames[existingEntry->zoneIndex].name;
				}
				else
				{
					poolName = "default asset pool";
				}
				Com_Printf(CON_CHANNEL_SYSTEM, "DB_LinkXAssetEntry: return asset: '%s','%s' loaded from fastfile: '%s'\n",
					DB_GetXAssetTypeName(existingEntry->asset.type), name, poolName);
			}
		}
		return existingEntry;
	}

	debugName = Dvar_GetString(db_xassetdebugname);
	if (Dvar_GetBool(db_xassetdebug))
	{
		if (Dvar_GetInt(db_xassetdebugtype) == -1
			|| Dvar_GetInt(db_xassetdebugtype) == newEntry->asset.type
			|| debugName[0] && !I_stricmp(name, debugName))
		{
			Com_Printf(CON_CHANNEL_SYSTEM, "DB_LinkXAssetEntry: replacing default asset in asset: '%s','%s'\n", DB_GetXAssetTypeName(newEntry->asset.type), name);
		}
	}

	--g_defaultAssetCount;
	if (existingEntry->inuse)
	{
		varXAsset = &existingEntry->asset;
		Mark_XAsset();
	}

	DB_CloneXAsset(&existingEntry->asset, &newEntry->asset, DB_CLONE_FROM_DEFAULT);
	DB_FreeXAssetEntry(newEntry);

	return existingEntry;
}

bool s_inuseCacheEnabled;
unsigned int s_inuseCacheHits;
unsigned int s_inuseCacheMisses;
unsigned __int16* s_inuseCache;

/*
==============
DB_EnableInUseCache
==============
*/
void DB_EnableInUseCache(unsigned __int16 *data)
{
	PIXBeginNamedEvent(-1, "DB_EnableInUseCache");
	assert(s_inuseCacheEnabled == 0);
	s_inuseCacheEnabled = 1;
	s_inuseCacheHits = 0;
	s_inuseCacheMisses = 0;
	s_inuseCache = data;
	memset((unsigned __int8*)data, 0xFFu, 0x8000u);
	if (Sys_IsRenderThread())
	{
		D3DPERF_EndEvent();
	}
}

/*
==============
DB_GetXAsset
==============
*/
void DB_GetXAsset(XAssetType type, XAssetHeader header)
{
	unsigned int assetEntryIndex;
	XAsset asset;
	const char* name;
	XAssetEntry* assetEntry;

	if (s_inuseCacheEnabled && s_inuseCache[(unsigned int)header.data >> 2 & 0x1fff] == (unsigned int)header.data >> 0x10)
	{
		++s_inuseCacheHits;
	}
	else
	{
		++s_inuseCacheMisses;
		asset.type = type;
		asset.header = header;
		name = DB_GetXAssetName(&asset);
		for (assetEntryIndex = db_hashTable[DB_HashForName_Inline(name, type) % 0x9600];
			assetEntryIndex;
			assetEntryIndex = assetEntry->nextHash)
		{
			assert(assetEntryIndex);
			assetEntry = &g_assetEntryPool[assetEntryIndex].entry;
			if (assetEntry->asset.type == type
				&& assetEntry->asset.header.data == header.data)
			{
				assetEntry->inuse = 1;
				if (s_inuseCacheEnabled)
				{
					s_inuseCache[(unsigned int)header.data >> 2 & 0x1fff] = (unsigned int)header.data >> 0x10;
				}
				return;
			}
		}
	}
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
	if (source)
	{
		AssertMsg("inconceivable");
	}
	else
	{
		Com_sprintf(filename, size, "%s\\zone\\%s\\%s%s", Sys_DefaultInstallPath(), "dedicated", zoneName, ".ff");
		if (GetFileAttributesA(filename) == -1)
		{
			Com_sprintf(filename, size, "%s\\zone\\%s\\%s%s", Sys_DefaultInstallPath(), Win_GetLanguage(), zoneName, ".ff");
		}
	}
}

int g_zoneCount;
volatile unsigned int g_zoneInfoCount;
volatile unsigned int g_loadingAssets;

XZoneInfoInternal g_zoneInfo[64];

/*
==============
DB_LoadXZone
==============
*/
void DB_LoadXZone(XZoneInfo *zoneInfo, unsigned int zoneCount)
{
	unsigned int j;
	const char* zoneName;
	unsigned int zoneInfoCount;

	PIXBeginNamedEvent(-1, "DB_LoadXZone");
	if (g_zoneCount == 64)
	{
		Com_Error(ERR_DROP, "Max zone count exceeded");
	}

	assert(!g_zoneInfoCount);
	assert(!g_loadingAssets);

	zoneInfoCount = 0;
	for (j = 0; j < zoneCount; ++j)
	{
		zoneName = zoneInfo[j].name;
		if (!zoneName)
		{
			continue;
		}

		assert(zoneInfoCount < ARRAY_COUNT(g_zoneInfo));
		I_strncpyz(g_zoneInfo[zoneInfoCount].name, zoneName, sizeof(g_zoneInfo[zoneInfoCount].name));
		Com_Printf(CON_CHANNEL_SYSTEM, "Adding fastfile '%s' to queue\n", g_zoneInfo[zoneInfoCount].name);
		g_zoneInfo[zoneInfoCount].flags = zoneInfo[j].allocFlags;
		zoneInfoCount++;
	}

	if (zoneInfoCount)
	{
		g_loadingAssets = zoneInfoCount;
		Sys_WakeDatabase2();
		Sys_WakeDatabase();

		g_zoneInfoCount = zoneInfoCount;
		Sys_NotifyDatabase();
	}

	if (Sys_IsRenderThread())
	{
		D3DPERF_EndEvent();
	}
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

char g_debugZoneName[64];

/*
==============
DB_UpdateDebugZone
==============
*/
void DB_UpdateDebugZone()
{
	XZoneInfo zoneInfo[2];

	if (g_debugZoneName[0])
	{
		zoneInfo[0].name = NULL;
		zoneInfo[1].name = g_debugZoneName;
		Com_SyncThreads();
		zoneInfo[0].allocFlags = 0;
		zoneInfo[0].freeFlags = 0x400000;
		zoneInfo[1].allocFlags = 0x400000;
		zoneInfo[1].freeFlags = 0;
		DB_LoadXAssets(zoneInfo, 2, 1);

		CG_VisionSetMyChanges();
		if (!CL_AllLocalClientsDisconnected())
		{
			CG_WeaponMyChanges();
		}
		G_ReloadVehicleDef();
	}
}

/*
==============
DB_LoadZone_f
==============
*/
void DB_LoadZone_f()
{
	I_strncpyz(g_debugZoneName, Cmd_Argv(1), sizeof(g_debugZoneName));
	DB_UpdateDebugZone();
}

/*
==============
DB_IsZoneLoaded
==============
*/
char DB_IsZoneLoaded(const char *name)
{
	unsigned int i;
	XZoneState state;

	for (i = 1; i < 65; ++i)
	{
		state = g_zoneNames[i].state;
		if ((state == XZONE_LOADED || state == XZONE_COMPLETE) && !I_stricmp(g_zoneNames[i].name, name))
		{
			return 1;
		}
	}
	return 0;
}

/*
==============
DB_IsZoneTypeLoading
==============
*/
bool DB_IsZoneTypeLoading(int zoneType)
{
	unsigned int i;
	XZoneState state;

	for (i = 1; i < 65; ++i)
	{
		state = g_zoneNames[i].state;
		if (state == XZONE_LOADING && g_zoneNames[i].flags == zoneType)
		{
			return 1;
		}
	}
	return 0;
}

/*
==============
DB_IsZoneTypeLoaded
==============
*/
char DB_IsZoneTypeLoaded(int zoneType)
{
	unsigned int i;

	for (i = 1; i < 65; ++i)
	{
		if (g_zoneNames[i].flags == zoneType && (g_zoneNames[i].state == XZONE_LOADED || g_zoneNames[i].state == XZONE_COMPLETE))
		{
			return 1;
		}
	}
	return 0;
}

/*
==============
DB_IsZoneTypeComplete
==============
*/
char DB_IsZoneTypeComplete(int zoneType)
{
	unsigned int i;

	for (i = 1; i < 65; ++i)
	{
		if (g_zoneNames[i].flags == zoneType && g_zoneNames[i].state == XZONE_COMPLETE)
		{
			return 1;
		}
	}
	return 0;
}

const char* s_levelOverlayWhitelist[5] = { "zm_transit", "zm_prison", "zm_buried", "zm_tomb", "" };

/*
==============
DB_ZoneLoadsOverlays
==============
*/
char DB_ZoneLoadsOverlays(const char *zoneName)
{
	int i;

	if (Com_SessionMode_IsZombiesGame() && *s_levelOverlayWhitelist[0])
	{
		for (i = 0; i < 5; ++i)
		{
			if (I_stricmp(s_levelOverlayWhitelist[i], zoneName))
			{
				return true;
			}
		}
	}

	return false;
}

/*
==============
DB_CompareLoadXZoneInfos
==============
*/
char DB_CompareLoadXZoneInfos(const XZoneInfo *zone0, const XZoneInfo *zone1)
{
	if (zone0->name)
	{
		if (zone0->allocFlags >= 0x400000 || zone1->allocFlags >= 0x400000)
		{
			return  zone0->allocFlags > zone1->allocFlags;
		}
		else
		{
			return zone0->allocFlags < zone1->allocFlags;
		}
	}
}

volatile bool g_loadingZone;
unsigned int g_zoneAllocType;
unsigned __int8 g_fileBuf[524288];
XAssetList* varXAssetList;

/*
==============
DB_TryLoadXFileInternal
==============
*/
int DB_TryLoadXFileInternal(const char *zoneName, int zoneFlags, int requiredVersion, const char *contentDir)
{
	static bool zone_inited = false;
	int zoneHandle;
	int startWaitingTime;
	XZone* zone;
	FF_DIR zoneDir;
	char filename[256];
	const char* fixedZoneName;
	bool succeeded;
	unsigned int i, dependencyIndex;
	void* zoneFile;

	zone = &g_zones[g_zoneCount];
	memset(zone, 0, sizeof(XZone));
	assert(!g_zoneInfoCount);

	if (I_stricmp(zoneName, FFOTD_FAST_FILE_NAME))
	{
		if ((zoneFlags & 0x4092214))
		{
			Com_sprintf(filename, 256, "%s\\zone\\%s\\%s%s", Sys_DefaultInstallPath(), Win_GetLanguage(), zoneName, ".ff");
			zoneHandle = DB_Reliable_FsOpen_ReadOnly(filename, 0);
		}
		else
		{
			Com_sprintf(filename, 256, "%s\\zone\\%s\\%s%s", Sys_DefaultInstallPath(), "dedicated", zoneName, ".ff");
			zoneHandle = DB_Reliable_FsOpen_ReadOnly(filename, 0);
			if (zoneHandle == -1)
			{
				Com_sprintf(filename, 256, "%s\\zone\\%s\\%s%s", Sys_DefaultInstallPath(), Win_GetLanguage(), zoneName, ".ff");
				zoneHandle = DB_Reliable_FsOpen_ReadOnly(filename, 0);
			}
		}
	}
	else
	{
		zoneHandle = -1;
	}

	if (zoneHandle == -1)
	{
		if (strstr(filename, "_load") || strstr(filename, "_patch") || strstr(filename, "default"))
		{
			Com_PrintWarning(CON_CHANNEL_FILES, "WARNING: Could not find zone '%s'\n", filename);
		}
		else if (loc_language && I_strnicmp(filename, SEH_GetLanguageNameAbbr(SEH_GetCurrentLanguage()), 3))
		{
			Com_PrintWarning(CON_CHANNEL_FILES, "WARNING: Could not find zone '%s'\n", filename);
		}
		else
		{
			Sys_DatabaseCompleted();
			Com_Error(ERR_DROP, "ERROR: Could not find zone '%s'\n", filename);
		}

		return 0;
	}

	g_zoneIndex = 0;
	for (i = 1; i < 0x41; ++i)
	{
		if (!g_zoneNames[i].state)
		{
			g_zoneIndex = i;
			break;
		}
	}

	assert(g_zoneIndex);
	assert(zoneName[0]);
	fixedZoneName = g_zoneNames[g_zoneIndex].name;
	assert(!fixedZoneName[0]);

	g_zoneNames[g_zoneIndex].state = XZONE_LOADING;
	I_strncpyz((char*)fixedZoneName, zoneName, 64);
	g_zoneNames[g_zoneIndex].flags = zoneFlags;
	g_zoneNames[g_zoneIndex].fileSize = Stream_Easy_FileSize(zoneHandle);
	
	zone->index = g_zoneIndex;
	zone->flags = zoneFlags;
	memset(zone->blocks, 0, sizeof(zone->blocks));

	assert(!g_loadingZone);
	if (!zone_inited)
	{
		zone_inited = 1;
		zone_reorder = _Dvar_RegisterString(
			"zone_reorder",
			"",
			0,
			"Set to the name of the fast file you want to reorder");
	}

	if (!_stricmp(Dvar_GetString(zone_reorder), zoneName))
	{
		DB_BeginReorderZone(zoneName);
	}

	++g_zoneCount;
	g_loadingZone = 1;
	while (g_isRecoveringLostDevice)
	{
		NET_Sleep(25);
	}

	g_mayRecoverLostAssets = 0;
	g_zoneAllocType = zoneFlags >= 0x400000;
	if (zoneFlags >= 0x400000 && g_initializing)
	{
		startWaitingTime = Sys_Milliseconds();
		Com_Printf(CON_CHANNEL_DONT_FILTER, "Waiting for $init to finish.  There may be assets missing from code_post_gfx.\n");
		while (g_initializing)
		{
			R_BeginRemoteScreenUpdate();
			NET_Sleep(1u);
			R_EndRemoteScreenUpdate();
		}
		Com_Printf(CON_CHANNEL_SYSTEM, "Waited %d ms for $init to finish.\n", Sys_Milliseconds() - startWaitingTime);
	}

	if ((zoneFlags & 0x20000000) == 0)
	{
		if ((zoneFlags & 0x200000) != 0)
		{
			DB_GumpBeginAlloc(g_zoneNames[g_zoneIndex].name, g_zoneAllocType, TRACK_FASTFILE);
		}
		else
		{
			PMem_BeginAlloc(g_zoneNames[g_zoneIndex].name, g_zoneAllocType, TRACK_FASTFILE);
		}
	}

	if (Com_SessionMode_IsZombiesGame())
	{
		if ((0xB4000 & zoneFlags) == 0)
		{
			DB_ResetZoneSize((zoneFlags & 0x48000) != 0);
		}
	}
	else
	{
		if ((0x14000 & zoneFlags) == 0)
		{
			DB_ResetZoneSize((zoneFlags & 0x8000) != 0);
		}
	}

	succeeded = DB_LoadXFile(filename, zoneHandle, g_zoneNames[g_zoneIndex].name, zone->blocks, 0, g_fileBuf, g_zoneAllocType, zoneFlags, requiredVersion, 0);
	if ((zoneFlags & 0x20000000) == 0)
	{
		if ((zoneFlags & 0x200000) != 0)
		{
			DB_GumpEndAlloc(g_zoneNames[g_zoneIndex].name, g_zoneAllocType);
		}
		else
		{
			PMem_EndAlloc(g_zoneNames[g_zoneIndex].name, g_zoneAllocType);
		}
	}

	assert(g_zoneNames[g_zoneIndex].state == XZONE_LOADING);
	if (succeeded)
	{
		g_zoneNames[g_zoneIndex].state = XZONE_LOADED;
	}
	assert(g_loadingZone);
	g_loadingZone = 0;
	g_mayRecoverLostAssets = 1;

	if (varXAssetList->dependCount > 0)
	{
		for (dependencyIndex = 0; dependencyIndex >= varXAssetList->dependCount; ++dependencyIndex)
		{
			if (!DB_IsZoneLoaded(varXAssetList->depends[dependencyIndex]))
			{
				++g_loadingAssets;
				if (!DB_TryLoadXFileInternal(varXAssetList->depends[dependencyIndex], zoneFlags, requiredVersion, 0))
				{
					break;
				}
			}
		}
		return 1;
	}
	return 1;
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
	assert(g_zoneNames[zone->index].state == XZONE_UNLOADING);
	DB_FreeXBlocks(g_zoneNames[zone->index].name, zone->blocks, zone->flags);
	Com_Printf(CON_CHANNEL_SYSTEM, "Unloaded fastfile '%s'\n", g_zoneNames[zone->index].name);
	if ((zone->flags & 0x200000) == 0)
	{
		PMem_Free(g_zoneNames[zone->index].name);
	}
	g_zoneNames[zone->index].name[0] = 0;
	g_zoneNames[zone->index].state = XZONE_EMPTY;
}

/*
==============
DB_FreeDefaultEntries
==============
*/
void DB_FreeDefaultEntries()
{
	unsigned int nextAssetEntryIndex;
	unsigned int hash;
	unsigned int assetEntryIndex;
	XAssetEntry* assetEntry;

	for (hash = 0; hash < 0x9600; ++hash)
	{
		for (assetEntryIndex = db_hashTable[hash]; assetEntryIndex; assetEntryIndex = nextAssetEntryIndex)
		{
			assetEntry = &g_assetEntryPool[assetEntryIndex].entry;
			nextAssetEntryIndex = assetEntry->nextHash;

			assert(!assetEntry->zoneIndex);
			assert(!assetEntry->nextOverride);
			assert(g_defaultAssetCount);
			--g_defaultAssetCount;
			g_assetEntryPool[assetEntryIndex] = *g_freeAssetEntryHead;
			g_freeAssetEntryHead = &g_assetEntryPool[assetEntryIndex];
		}
		db_hashTable[hash] = 0;
	}
	assert(!g_defaultAssetCount);
}

/*
==============
DB_ReleaseXAssets
==============
*/
void DB_ReleaseXAssets()
{
	unsigned int hash;
	unsigned int assetEntryIndex;

	assert(Sys_IsMainThread());
	if (!cullInfoContext || !Com_SessionMode_IsZombiesGame())
	{
		Sys_SyncDatabase();
		for (hash = 0; hash < 0x8000; ++hash)
		{
			for (assetEntryIndex = db_hashTable[hash];
				assetEntryIndex;
				assetEntryIndex = g_assetEntryPool[assetEntryIndex].entry.nextHash)
			{
				g_assetEntryPool[assetEntryIndex].entry.inuse = 0;
			}
		}
	}
}

/*
==============
DB_UnloadXAssetsMemory
==============
*/
void DB_UnloadXAssetsMemory(XZone *zone)
{
	int zoneIter;

	for (zoneIter = 0; zone != &g_zones[zoneIter]; ++zoneIter)
	{
		assert(zoneIter < g_zoneCount);
	}
	assert(g_zoneNames[zone->index].state == XZONE_UNLOADING);
	DB_FreeXBlocks(g_zoneNames[zone->index].name, zone->blocks, zone->flags);
	Com_Printf(CON_CHANNEL_SYSTEM, "Unloaded fastfile '%s'\n", g_zoneNames[zone->index].name);
	if ((zone->flags & 0x200000) == 0)
	{
		PMem_Free(g_zoneNames[zone->index].name);
	}
	g_zoneNames[zone->index].name[0] = 0;
	g_zoneNames[zone->index].state = XZONE_EMPTY;
	--g_zoneCount;
	while (zoneIter < g_zoneCount)
	{
		memcpy(&g_zones[zoneIter], &g_zones[zoneIter + 1], sizeof(XZone));
		++zoneIter;
	}
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

bool g_archiveBuf;

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
	Sys_SyncDatabase();
	assert(!g_archiveBuf);
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
	Material_DirtySort();
	return DB_AllocXAsset<Material>(pool);
}

/*
==============
DB_AllocGfxImage
==============
*/
XAssetHeader DB_AllocGfxImage(void *pool)
{
	IPak_MarkAdjacencyInfoAsStale();
	return DB_AllocXAsset<GfxImage>(pool);
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
	unsigned int i;
	int remoteScreenUpdateNesting;

	assert(Sys_IsMainThread() || Sys_IsRenderThread());
	assert(!g_loadingZone);
	assert(!g_zoneInfoCount);

	if (Sys_IsDatabaseReady2())
	{
		return;
	}

	PIXBeginNamedEvent(-1, "DB_PostLoadXZone");
	DB_PostLoadPerXZone();

	//TODO
}

/*
==============
DB_SyncXAssets
==============
*/
void DB_SyncXAssets()
{
	PIXBeginNamedEvent(-1, "DB_SyncXAssets");
	assert(Sys_IsMainThread() || Sys_IsRenderThread());
	R_BeginRemoteScreenUpdate();
	Sys_SyncDatabase();
	R_EndRemoteScreenUpdate();
	BG_EvalVehicleName();
	DB_PostLoadXZone();
	if (Sys_IsRenderThread())
	{
		D3DPERF_EndEvent();
	}
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
	assert(Sys_IsMainThread());
	if (Sys_IsDatabaseReady() && !Sys_IsDatabaseReady2())
	{
		DB_PostLoadXZone();
	}
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
	if (!Sys_SpawnDatabaseThread(DB_Thread))
	{
		Sys_Error("Failed to create database thread");
	}
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

