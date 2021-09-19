#include "types.h"
#include "functions.h"

/*
==============
SNDL_Play
==============
*/
int SNDL_Play(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
StopSoundAliasesOnEnt
==============
*/
void StopSoundAliasesOnEnt(SndEntHandle sndEnt, unsigned int name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_StopSoundAliasOnEnt
==============
*/
void SNDL_StopSoundAliasOnEnt(SndEntHandle sndEnt, unsigned int name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_StopSoundsOnEnt
==============
*/
void SNDL_StopSoundsOnEnt(SndEntHandle sndEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_DisconnectListener
==============
*/
void SNDL_DisconnectListener(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_SetListener
==============
*/
void SNDL_SetListener(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_StopSounds
==============
*/
void SNDL_StopSounds(SndStopSoundFlags which)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_FadeOut
==============
*/
void SNDL_FadeOut()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_FadeIn
==============
*/
void SNDL_FadeIn()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_SetEnvironmentEffects
==============
*/
void SNDL_SetEnvironmentEffects(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_DeactivateEnvironmentEffects
==============
*/
void SNDL_DeactivateEnvironmentEffects(int priority, int fademsec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_SetPlaybackAttenuation
==============
*/
void SNDL_SetPlaybackAttenuation(int playbackId, float attenuation)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_SetPlaybackAttenuationRate
==============
*/
void SNDL_SetPlaybackAttenuationRate(int playbackId, float rate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_SetPlaybackPitch
==============
*/
void SNDL_SetPlaybackPitch(int playbackId, float pitch)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_SetPlaybackPitchRate
==============
*/
void SNDL_SetPlaybackPitchRate(int playbackId, float rate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_SetStartPaused
==============
*/
void SNDL_SetStartPaused(int playbackId, bool pause)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_StopPlayback
==============
*/
void SNDL_StopPlayback(int playbackId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_SetDuck
==============
*/
void SNDL_SetDuck(SndDuckCategoryType cat, unsigned int id, float amount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_SetSideChainDuck
==============
*/
void SNDL_SetSideChainDuck(unsigned int id)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_SetScriptTimescale
==============
*/
void SNDL_SetScriptTimescale(float value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_PlayLoopAt
==============
*/
void SNDL_PlayLoopAt(unsigned int id, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_StopLoopAt
==============
*/
void SNDL_StopLoopAt(unsigned int id, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_PlayLineAt
==============
*/
void SNDL_PlayLineAt(unsigned int id, const vec3_t *origin0, const vec3_t *origin1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_StopLineAt
==============
*/
void SNDL_StopLineAt(unsigned int id, const vec3_t *origin0, const vec3_t *origin1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_UpdateStaticSounds
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
SNDL_GetPlaybackTime
==============
*/
int SNDL_GetPlaybackTime(int playbackId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SNDL_GameReset
==============
*/
void SNDL_GameReset()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_SetContext
==============
*/
void SNDL_SetContext(unsigned int type, unsigned int value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_RestartDriver
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
SNDL_SetEntContext
==============
*/
void SNDL_SetEntContext(SndEntHandle handle, unsigned int type, unsigned int value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_UpdateLoopingSounds
==============
*/
/*void SNDL_UpdateLoopingSounds(SndListener *a1@<edi>)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
SNDL_SetMusicState
==============
*/
void SNDL_SetMusicState(unsigned int id)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_PrefetchLoadedAlias
==============
*/
void SNDL_PrefetchLoadedAlias(unsigned int aliasId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_SetGlobalFutz
==============
*/
void SNDL_SetGlobalFutz(unsigned int id, SndCallLocation callLocation)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_SetFrontendMusic
==============
*/
void SNDL_SetFrontendMusic(unsigned int musicAlias)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_SetLoopState
==============
*/
void SNDL_SetLoopState(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_PlayLoops
==============
*/
void SNDL_PlayLoops(int count, const SndEntLoop *loops)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SNDL_SetGameState
==============
*/
void SNDL_SetGameState(
{
	UNIMPLEMENTED(__FUNCTION__);
}

