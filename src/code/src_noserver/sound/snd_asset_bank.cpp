#include "types.h"

/*
==============
SND_ChecksumToString
==============
*/
void SND_ChecksumToString(const unsigned __int8 *checksum, char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_AssetBankValidateHeader
==============
*/
char SND_AssetBankValidateHeader(const char *filename, const SndAssetBankHeader *header, __int64 size, const unsigned __int8 *checksum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_AssetBankValidateEntry
==============
*/
char SND_AssetBankValidateEntry(const char *name, const SndAssetBankHeader *header, const SndAssetBankEntry *entry)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_EntryCompare
==============
*/
int SND_EntryCompare(const void *va, const void *vb)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_AssetBankFindEntry
==============
*/
char SND_AssetBankFindEntry(unsigned int id, SndAssetBankEntry *entries, unsigned int entryCount, SndAssetBankEntry **entry)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_AssetBankGetFrameRate
==============
*/
unsigned int SND_AssetBankGetFrameRate(const SndAssetBankEntry *entry)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_AssetBankGetChannelCount
==============
*/
unsigned int SND_AssetBankGetChannelCount(const SndAssetBankEntry *entry)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_AssetBankGetLooping
==============
*/
BOOL SND_AssetBankGetLooping(const SndAssetBankEntry *entry)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_AssetBankGetFrameCount
==============
*/
unsigned int SND_AssetBankGetFrameCount(const SndAssetBankEntry *entry)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_AssetBankGetLengthMs
==============
*/
unsigned int SND_AssetBankGetLengthMs(const SndAssetBankEntry *entry)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_AssetBankFindEntry
==============
*/
char SND_AssetBankFindEntry(unsigned int id, SndAssetBankEntry **entry, int *fid, bool streamed)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

