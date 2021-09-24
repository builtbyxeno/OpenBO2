#include "types.h"

/*
==============
SND_CompareAssetLoads
==============
*/
int SND_CompareAssetLoads(const void *a, const void *b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_AddAssetToLoad
==============
*/
void SND_AddAssetToLoad(int bankFileId, unsigned int assetId, unsigned int fileOffset, unsigned int size, void *destination, unsigned int memoryOffset, SndBank *bank)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_FindNextAssetToLoad
==============
*/
SndAssetToLoad *SND_FindNextAssetToLoad()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_LoadAssetCallback
==============
*/
void SND_LoadAssetCallback(int id, stream_status result, unsigned int numBytesRead, void *b)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_LoadAssetUpdate
==============
*/
void SND_LoadAssetUpdate()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_AllocateEntries
==============
*/
int SND_AllocateEntries(const char *bankName, int entryCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_GetRuntimeAssetBankFileName
==============
*/
void SND_GetRuntimeAssetBankFileName(const char *a1, bool stream, const char *zone, const char *language, int length, char *path)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_AssetBankFindStreamed
==============
*/
char SND_AssetBankFindStreamed(unsigned int id, SndAssetBankEntry **entry, int *fid)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_AssetBankFindLoaded
==============
*/
char SND_AssetBankFindLoaded(unsigned int id, SndAssetBankEntry **entry, void **data)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_FindInIndex
==============
*/
bool SND_FindInIndex(unsigned int key, const SndBank *bank, SndAliasList **result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_AssertBankIndexValid
==============
*/
void SND_AssertBankIndexValid(const SndBank *bank)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_RemovePatch
==============
*/
void SNDL_RemovePatch(SndPatch *patch)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_AliasCount
==============
*/
int SND_AliasCount()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_AliasByIndex
==============
*/
SndAliasList *SND_AliasByIndex(unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_BankAliasLookup
==============
*/
SndAliasList *SND_BankAliasLookup(unsigned int key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_BankAliasLookupCache
==============
*/
SndAliasList *SND_BankAliasLookupCache(unsigned int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_FindAliasId
==============
*/
unsigned int SND_FindAliasId(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_GetPlaybackTime
==============
*/
int SND_GetPlaybackTime(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_GetRadverb
==============
*/
const SndRadverb *SND_GetRadverb(unsigned int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_FindAliasFromId
==============
*/
SndAliasList *SND_FindAliasFromId(unsigned int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_FindRowGroup
==============
*/
SndVolumeGroup *SND_FindRowGroup(unsigned int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_FindRowCurve
==============
*/
SndCurve *SND_FindRowCurve(unsigned int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_FindRowPan
==============
*/
SndPan *SND_FindRowPan(unsigned int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
gjk_base_t::get_brush
==============
*/
/*int gjk_base_t::get_brush()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
SND_GetDuckById
==============
*/
const SndDuck *SND_GetDuckById(unsigned int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_FindRowDuckPatchLpf
==============
*/
const SndDuck *SND_FindRowDuckPatchLpf(unsigned int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_FindRowContext
==============
*/
SndContext *SND_FindRowContext(unsigned int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_FindRowRadverb
==============
*/
const SndRadverb *SND_FindRowRadverb(unsigned int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_FindRowMaster
==============
*/
SndMaster *SND_FindRowMaster(unsigned int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_PatchValue
==============
*/
void SND_PatchValue(unsigned int table, char *asset, unsigned int fieldIndex, unsigned int value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_PatchDuckValue
==============
*/
void SND_PatchDuckValue(unsigned int table, SndDuck *duck, unsigned int fieldIndex, unsigned int groupId, unsigned int value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_PatchApply
==============
*/
void SND_PatchApply(const SndPatch *patch)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_ResetAliases
==============
*/
void SNDL_ResetAliases()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_BankReadCallback
==============
*/
void SND_BankReadCallback(int id, stream_status result, unsigned int numBytesRead, void *b)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_StreamRead
==============
*/
void SND_StreamRead(SndBank *bank, int fileHandle, int offset, int size, void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_StartHeaderRead
==============
*/
char SND_StartHeaderRead(bool streamed, SndRuntimeAssetBank *assetBank, SndBank *bank)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_HeaderCheck
==============
*/
char SND_HeaderCheck(SndBank *bank, SndRuntimeAssetBank *assetBank)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_StartTocRead
==============
*/
char SND_StartTocRead(SndBank *bank, SndRuntimeAssetBank *assetBank)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_TocCheck
==============
*/
char SND_TocCheck(SndBank *bank, SndRuntimeAssetBank *assetBank)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_BankLoadError
==============
*/
void SND_BankLoadError(SndBank *bank)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_GetAliasIdFromScriptId
==============
*/
unsigned int SND_GetAliasIdFromScriptId(const unsigned int scriptId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_EnqueueLoadedAssets
==============
*/
void SND_EnqueueLoadedAssets(SndBank *bank)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_AddBank
==============
*/
void SNDL_AddBank(SndBank *bank)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_RemoveBank
==============
*/
void SNDL_RemoveBank(SndBank *bank)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_AddPatch
==============
*/
void SNDL_AddPatch(SndPatch *patch)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_ApplyPatches
==============
*/
void SNDL_ApplyPatches()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_FindAlias
==============
*/
SndAliasList *SND_FindAlias(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_EnqueueAssetLoads
==============
*/
void SND_EnqueueAssetLoads(SndBank *bank)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_BankLoadUpdateState
==============
*/
void SND_BankLoadUpdateState(SndBank *bank)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_LoadSoundsWait
==============
*/
void SND_LoadSoundsWait()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_BankUpdate
==============
*/
char SND_BankUpdate()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_IsAliasNameLooping
==============
*/
bool SND_IsAliasNameLooping(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_GetPlaybackTime
==============
*/
int SND_GetPlaybackTime()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

