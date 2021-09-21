#include "types.h"
#include "functions.h"

/*
==============
SND_SetPosition
==============
*/
void SND_SetPosition(int index, const vec3_t *org)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_ActiveListenerCount
==============
*/
unsigned int SND_ActiveListenerCount()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_GetListenerIndexNearestToOrigin
==============
*/
int SND_GetListenerIndexNearestToOrigin(const vec3_t *origin, float *minDistanceSq)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_AcquirePlaybackId
==============
*/
int SND_AcquirePlaybackId()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DoLengthNotify
==============
*/
void DoLengthNotify(int msec, void *lengthNotifyData, SndLengthType id)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_StartLengthNotify
==============
*/
void SND_StartLengthNotify(int index, int totalMsec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_GetSeed
==============
*/
double SND_GetSeed(unsigned int key, unsigned int global_age)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_SetVoiceStartFlux
==============
*/
void SND_SetVoiceStartFlux(SndVoice *voice, vec3_t *player)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetVoiceStartSeeds
==============
*/
void SND_SetVoiceStartSeeds(const SndAlias *alias, SndVoice *voice)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetVoiceStartFades
==============
*/
void SND_SetVoiceStartFades(float fadetime, bool setScriptValues, float scriptPitch, float scriptPitchRate, float scriptAttenuation, float scriptAttenuationRate, SndVoice *voice)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_UpdateVoicePosition
==============
*/
void SND_UpdateVoicePosition(SndVoice *voice, const vec3_t *startPosition)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_LosOcclusionCache
==============
*/
char SND_LosOcclusionCache(unsigned int channel, const vec3_t *position, float *value)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_SetSoundFileVoiceInfo
==============
*/
void SND_SetSoundFileVoiceInfo(int voiceIndex, int srcChannelCount, int baserate, int total_msec, int start_msec, SndFileLoadingState loadingState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Snd_GetGlobalPriorityVolume
==============
*/
float Snd_GetGlobalPriorityVolume(const SndAlias *alias, const vec3_t *org, int localClientGroupMask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Snd_GetLowestPriority
==============
*/
void Snd_GetLowestPriority(float *priority, int *channel, unsigned int start, unsigned int count)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_ContinueLoopingSound_Internal
==============
*/
void SND_ContinueLoopingSound_Internal(int voiceIndex, float volumeScale, int fadeTime, const vec3_t *org, SndPlayback *playback, bool setScriptValues, float scriptPitch, float scriptPitchRate, float scriptAttenuation, float scriptAttenuationRate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_ContinueLoopingSound
==============
*/
unsigned int SND_ContinueLoopingSound(unsigned int aliasId, float volumeScale, SndEntHandle sndEnt, const vec3_t *org, int fadeTime, SndPlayback *playback, bool setScriptValues, float scriptPitch, float scriptPitchRate, float scriptAttenuation, float scriptAttenuationRate)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_PickSoundAliasFromList
==============
*/
SndAlias *SND_PickSoundAliasFromList(const SndAliasList *aliasList, int objectId, SndEntHandle sndEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_PickSoundAlias
==============
*/
SndAlias *SND_PickSoundAlias(const char *name, int objectid, SndEntHandle sndEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_CheckValidSecondary
==============
*/
bool SND_CheckValidSecondary(const SndAlias *alias, const SndAlias *secondaryAlias)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_GetPlayingInfo
==============
*/
void SND_GetPlayingInfo(unsigned int aliasHash, int *pcount, int *poldest, int *least, bool *isMultiple, SndEntHandle ent, bool useEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_IsSoloAlias
==============
*/
bool SND_IsSoloAlias(const SndAlias *alias)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_IsMuteAlias
==============
*/
bool SND_IsMuteAlias(const SndAlias *alias)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_PauseSounds
==============
*/
void SND_PauseSounds()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_UnpauseSounds
==============
*/
int *SND_UnpauseSounds()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_GetCurrentReverb
==============
*/
unsigned int SND_GetCurrentReverb()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_UpdateRoomEffects
==============
*/
void SND_UpdateRoomEffects(int frametime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_UpdatePreloads
==============
*/
void SND_UpdatePreloads()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_StopVoicePFutz
==============
*/
void SND_StopVoicePFutz(int voiceIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetStartPaused
==============
*/
void SND_SetStartPaused(SndVoice *voice, bool pause)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_Active
==============
*/
int SND_Active()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SNDL_AddGlobals
==============
*/
void SNDL_AddGlobals(SndDriverGlobals *globals)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_RemoveGlobals
==============
*/
void SNDL_RemoveGlobals(SndDriverGlobals *globals)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_ErrorIfSoundGlobalsTrashed
==============
*/
void SND_ErrorIfSoundGlobalsTrashed()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_Init
==============
*/
void SND_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_ResetDriver
==============
*/
void __cdecl SND_ResetDriver()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_GetPitch
==============
*/
double SND_GetPitch(SndVoice *voice)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_GetBaseLevel
==============
*/
double SND_GetBaseLevel(const SndVoice *voice)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_GetDryLevel
==============
*/
float SND_GetDryLevel(const SndVoice *voice, float baseLevel)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_GetWetLevel
==============
*/
float SND_GetWetLevel(const SndVoice *voice, float baseLevel)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_GetLevels
==============
*/
void SND_GetLevels(const SndVoice *voice, float *wet, float *dry)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_GetDistance
==============
*/
double SND_GetDistance(const SndVoice *voice)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_GetLpfLevel
==============
*/
double SND_GetLpfLevel(const SndVoice *voice)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_GetVoiceLength
==============
*/
unsigned int SND_GetVoiceLength(int voiceIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_GetOmni
==============
*/
double SND_GetOmni(const SndVoice *voice)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_GetPlaybackVoice
==============
*/
SndVoice *SND_GetPlaybackVoice(int playbackId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_DuckFindFree
==============
*/
SndDuckActive *SND_DuckFindFree()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_DuckRateLimit
==============
*/
void SND_DuckRateLimit(unsigned int count, const float *rate, const float *negrate, const float *target, float *delta, float *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetDuckByCategory
==============
*/
void SND_SetDuckByCategory(SndDuckCategoryType category, unsigned int duckId, const SndDuck *duck, float amount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_DuckStartAlias
==============
*/
SndDuckActive *SND_DuckStartAlias(const SndDuck *duck)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_StopDuck
==============
*/
void SND_StopDuck(SndDuckActive *duck)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_DuckUpdate
==============
*/
void SND_DuckUpdate(int a1, char *a2, float dt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_GetCurrentGfutzId
==============
*/
unsigned int SND_GetCurrentGfutzId()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_AddLengthNotify
==============
*/
char SND_AddLengthNotify(SndLengthType a1, char *a2, int playbackId, void *lengthNotifyData, SndLengthType id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_ResetVoiceInfo
==============
*/
void SND_ResetVoiceInfo(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_ContinueLoopingPlayback
==============
*/
void SND_ContinueLoopingPlayback(int id)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_StopVoice
==============
*/
void SND_StopVoice(int voiceIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_ShutdownVoices
==============
*/
void SND_ShutdownVoices()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_UpdateVoiceDuck
==============
*/
void SND_UpdateVoiceDuck(SndVoice *voice)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_UpdateVoice
==============
*/
void SND_UpdateVoice(SndVoice *voice, float dt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_DuckReset
==============
*/
void SND_DuckReset()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetVoiceStartInfo
==============
*/
void __cdecl SND_SetVoiceStartInfo(int index, SndStartAliasInfo *SndStartAliasInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_FindFreeVoice
==============
*/
int SND_FindFreeVoice(const vec3_t *a1, float volume, SndStartAliasInfo *startAliasInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_Limit
==============
*/
bool SND_Limit(const char *name, int aliasHash, SndLimitType limitType, int limitCount, SndEntHandle ent, bool useEnt, float priority)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_LimitVoice
==============
*/
char SND_LimitVoice(const SndAlias *alias, SndEntHandle ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_PlaySoundAlias
==============
*/
unsigned int SND_PlaySoundAlias(int a1, const SndAliasList *aliasList, float volumeScale, SndEntHandle sndEnt, const vec3_t *org, int timeshift, int fadeTime, const vec3_t *direction, SndPlayback *playback, SndOcclusionStartCache *ocache, bool notify, const vec3_t *startPaused, bool setScriptValues, float scriptPitch, float scriptPitchRate, float scriptAttenuation, float scriptAttenuationRate)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_UpdateDebug
==============
*/
void SND_UpdateDebug(unsigned int a1, float a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_Update
==============
*/
void SNDL_Update(float a1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_Shutdown
==============
*/
void SNDL_Shutdown()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetGlobalFutz
==============
*/
void SND_SetGlobalFutz(unsigned int id, SndCallLocation callLocation)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetStartPaused
==============
*/
void SND_SetStartPaused(int playbackId, bool pause)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetGlobalFutz
==============
*/
void SND_SetGlobalFutz(const char *futzName, SndCallLocation callLocation)
{
	UNIMPLEMENTED(__FUNCTION__);
}

