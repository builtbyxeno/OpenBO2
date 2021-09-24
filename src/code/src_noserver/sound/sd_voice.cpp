#include "types.h"

/*
==============
SD_VoiceShutdown
==============
*/
void SD_VoiceShutdown()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SD_VoiceParamAllocate
==============
*/
sd_voice_param *SD_VoiceParamAllocate()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SD_VoiceParamFree
==============
*/
void SD_VoiceParamFree(sd_voice_param *p)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SD_VoiceAllocate
==============
*/
sd_voice *SD_VoiceAllocate()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SD_VoiceAllocateRam
==============
*/
sd_voice *SD_VoiceAllocateRam(unsigned int assetId, bool looping, unsigned int channelCount, unsigned int frameRate, unsigned int frameCount, unsigned int dataSize, const char *data, const SndAssetBankEntry *entry)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SD_VoiceAllocateStream
==============
*/
sd_voice *SD_VoiceAllocateStream(const char *name, const SndAssetBankEntry *entry, int fid, const char *primeData, unsigned int primeSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SD_VoiceSetParam
==============
*/
void SD_VoiceSetParam(sd_voice *voice, sd_voice_param *param)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SD_VoiceHasData
==============
*/
BOOL SD_VoiceHasData(sd_voice *voice)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SD_VoiceStart
==============
*/
void SD_VoiceStart(sd_voice *voice, sd_voice_param *param)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SD_VoiceStarted
==============
*/
BOOL SD_VoiceStarted(sd_voice *voice)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SD_VoiceDone
==============
*/
BOOL SD_VoiceDone(sd_voice *voice)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SD_VoicePosition
==============
*/
__int64 SD_VoicePosition(sd_voice *voice)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

