#include "types.h"

/*
==============
SD_GetMixParam
==============
*/
sd_mix_master_param *SD_GetMixParam(sd_mix_master_param *param)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SD_GetVoiceParam
==============
*/
sd_voice_param *SD_GetVoiceParam(int voiceIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SD_PrefetchAliasId
==============
*/
void SD_PrefetchAliasId(unsigned int aliasId, int timeTillPlayMs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SD_PreUpdate
==============
*/
void SD_PreUpdate()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SD_StartAlias
==============
*/
unsigned int SD_StartAlias(SndStartAliasInfo *info, int voiceIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SD_StopVoice
==============
*/
void SD_StopVoice(int voiceIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SD_UpdateVoice
==============
*/
void SD_UpdateVoice(int voiceIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SD_Sync
==============
*/
void SD_Sync()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SD_Shutdown
==============
*/
void SD_Shutdown()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SD_SetAuxCallback
==============
*/
void SD_SetAuxCallback(bool (*callback)(float *, unsigned int, unsigned int))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SD_SetVcsCallback
==============
*/
void SD_SetVcsCallback(bool (*callback)(float *, unsigned int, unsigned int, bool *))
{
	UNIMPLEMENTED(__FUNCTION__);
}

