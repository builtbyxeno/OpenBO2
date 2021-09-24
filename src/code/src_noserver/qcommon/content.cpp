#include "types.h"

/*
==============
Content_GetContentPackMetaDataList
==============
*/
ContentPackMetaData *Content_GetContentPackMetaDataList()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Content_IsContentPackAllowedToBeListed
==============
*/
bool Content_IsContentPackAllowedToBeListed(int mask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_GetKnownContentPackCount
==============
*/
int Content_GetKnownContentPackCount()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_GetIndexedContentPackID
==============
*/
int Content_GetIndexedContentPackID(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_GetIndexedContentPackMask
==============
*/
int Content_GetIndexedContentPackMask(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_GetIndexedContentPackName
==============
*/
KnownContentPackData *Content_GetIndexedContentPackName(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Content_IsLoadFastfileLoaded
==============
*/
char Content_IsLoadFastfileLoaded(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_SetLoadFastfileLoaded
==============
*/
void Content_SetLoadFastfileLoaded(int index, bool value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Content_GetIndexedContentPackFilenameIdentifier
==============
*/
const char *Content_GetIndexedContentPackFilenameIdentifier(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Content_IsDiscovered
==============
*/
bool Content_IsDiscovered()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_RegisterContentDvars
==============
*/
void Content_RegisterContentDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Content_IsContentPackInvalid
==============
*/
bool Content_IsContentPackInvalid(int contentIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_GetAvailableContentPacks
==============
*/
int Content_GetAvailableContentPacks()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_GetAvailableContentMapPackFlags
==============
*/
int Content_GetAvailableContentMapPackFlags()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_GetContentPacksFlagsString
==============
*/
SearchSessionMapPackCombinationData *Content_GetContentPacksFlagsString(int contentFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Content_DoWeHaveContentPack
==============
*/
bool Content_DoWeHaveContentPack(const int contentPack)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_GetFreePackIndex
==============
*/
int Content_GetFreePackIndex()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_InitializeContentPacks
==============
*/
void Content_InitializeContentPacks()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Content_PlayerHasDLCForMapPackIndex
==============
*/
bool Content_PlayerHasDLCForMapPackIndex(dlcIndex_t mapPackTypeIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_GetPakNameForMap
==============
*/
const char *Content_GetPakNameForMap(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Content_ValidateTrialPackages
==============
*/
void Content_ValidateTrialPackages()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Content_GetMTXID
==============
*/
int Content_GetMTXID(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_GetMTXContentOffer
==============
*/
const char *Content_GetMTXContentOffer(const int mtxId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Content_GetMTXContentName
==============
*/
const char *Content_GetMTXContentName(const int mtxId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Content_ClearMTX
==============
*/
void Content_ClearMTX(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Content_MTXFinalizeDiscovery
==============
*/
void Content_MTXFinalizeDiscovery()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Content_DoWeHaveMTX
==============
*/
bool Content_DoWeHaveMTX(ControllerIndex_t controllerIndex, const int mtxId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_DoesAnyoneHaveMTX
==============
*/
char Content_DoesAnyoneHaveMTX(const int mtxId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_PurchaseMTX_f
==============
*/
void Content_PurchaseMTX_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Content_ForceMTX_f
==============
*/
void Content_ForceMTX_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Content_DumpMTX_f
==============
*/
void Content_DumpMTX_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Content_DetermineMTX
==============
*/
char Content_DetermineMTX(ControllerIndex_t controllerIndex, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_GetIndexedContentPackFromPakName
==============
*/
int Content_GetIndexedContentPackFromPakName(const char *pakName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_OwnsAnyByMask
==============
*/
char Content_OwnsAnyByMask(const ControllerIndex_t controllerIndex, const int contentMask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_GetContentPackFromPakName
==============
*/
int Content_GetContentPackFromPakName(const char *pakName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_DoWeHaveIndexedContentPack
==============
*/
bool Content_DoWeHaveIndexedContentPack(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_IsIndexedContentPackEnabled
==============
*/
bool Content_IsIndexedContentPackEnabled(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_GetEnabledContentPacks
==============
*/
unsigned int Content_GetEnabledContentPacks()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Content_RegisterContentCmds
==============
*/
void Content_RegisterContentCmds()
{
	UNIMPLEMENTED(__FUNCTION__);
}

