#include "types.h"
#include "functions.h"

/*
==============
SND_PlayInternal
==============
*/
void SND_PlayInternal(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_Play
==============
*/
void SND_Play(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_Play
==============
*/
void SND_Play(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_StopSoundAliasOnEnt
==============
*/
void SND_StopSoundAliasOnEnt(SndEntHandle ent, unsigned int alias_name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_StopSoundsOnEnt
==============
*/
void SND_StopSoundsOnEnt(SndEntHandle ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_NotifyCinematicStart
==============
*/
void SND_NotifyCinematicStart(float volume)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_NotifyCinematicEnd
==============
*/
void SND_NotifyCinematicEnd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_DisconnectListener
==============
*/
void SND_DisconnectListener(LocalClientNum_t listener)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetListener
==============
*/
void SND_SetListener(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_FadeIn
==============
*/
void SND_FadeIn()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_FadeOut
==============
*/
void SND_FadeOut()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetEnvironmentEffects
==============
*/
void SND_SetEnvironmentEffects(int priority, const char *preset, float drylevel, float wetlevel, int fademsec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_DeactivateEnvironmentEffects
==============
*/
void SND_DeactivateEnvironmentEffects(int priority, int fademsec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetPlaybackAttenuation
==============
*/
void SND_SetPlaybackAttenuation(int id, float attenuation)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetPlaybackAttenuationRate
==============
*/
void SND_SetPlaybackAttenuationRate(int id, float rate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetPlaybackPitch
==============
*/
void SND_SetPlaybackPitch(int playbackId, float pitch)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetPlaybackPitchRate
==============
*/
void SND_SetPlaybackPitchRate(int playbackId, float rate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_StopPlayback
==============
*/
void SND_StopPlayback(int playbackId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetDuck
==============
*/
void SND_SetDuck(SndDuckCategoryType type, const char *name, float length, float amount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetSideChainDuck
==============
*/
void SND_SetSideChainDuck(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetEntState
==============
*/
void SND_SetEntState(SndEntHandle handle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_PlayLoopAt
==============
*/
void SND_PlayLoopAt(unsigned int id, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_StopLoopAt
==============
*/
void SND_StopLoopAt(unsigned int id, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_PlayLineAt
==============
*/
void SND_PlayLineAt(unsigned int id, const vec3_t *origin0, const vec3_t *origin1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_StopLineAt
==============
*/
void SND_StopLineAt(unsigned int id, const vec3_t *origin0, const vec3_t *origin1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetContext
==============
*/
void SND_SetContext(const char *type, const char *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_RestartDriver
==============
*/
void SND_RestartDriver()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetEntContext
==============
*/
void SND_SetEntContext(SndEntHandle handle, const char *type, const char *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetEntContext
==============
*/
void SND_SetEntContext(SndEntHandle handle, const unsigned int type, const unsigned int value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetScriptTimescale
==============
*/
void SND_SetScriptTimescale(float value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetMusicState
==============
*/
void SND_SetMusicState(const char *state)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_AddBank
==============
*/
void SND_AddBank(SndBank *bank)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_AddPatch
==============
*/
void SND_AddPatch(SndPatch *patch)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_AddGlobals
==============
*/
void SND_AddGlobals(SndDriverGlobals *globals)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_WhizbyPath
==============
*/
bool SND_WhizbyPath(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_Whizby
==============
*/
void SND_Whizby(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_FindEntState
==============
*/
SndEntState **SND_FindEntState(SndEntHandle handle, bool createNew)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SNDL_SetEntState
==============
*/
void SNDL_SetEntState(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_ResetEntState
==============
*/
void SND_ResetEntState()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_ResetAliases
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
SND_SubtitleNotify
==============
*/
void SND_SubtitleNotify(const char *subtitle, unsigned int lengthMs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_LengthNotify
==============
*/
void SND_LengthNotify(unsigned int ent, unsigned int lengthMs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_FreePlaybackNotify
==============
*/
void SND_FreePlaybackNotify(SndPlayback *playback)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_BankLoadedNotify
==============
*/
void SND_BankLoadedNotify()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_AllocatePlayback
==============
*/
SndPlayback *SND_AllocatePlayback(unsigned int aliasId, SndEntHandle entHandle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_FreePlayback
==============
*/
void SND_FreePlayback(SndPlayback *p)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_FindPlayback
==============
*/
SndPlayback *SND_FindPlayback(int playbackId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_IsPlaying
==============
*/
bool SND_IsPlaying()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_GetKnownLength
==============
*/
bool SND_GetKnownLength(int playbackId, int *msec)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_Frame
==============
*/
/*int SND_Frame@<eax>(float a1@<edi>)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
updatesound_workerCallback_Implementation
==============
*/
/*int updatesound_workerCallback_Implementation@<eax>(float a1@<edi>)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
SND_PossiblyUpdate
==============
*/
void SND_PossiblyUpdate(int minUpdateMs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_Update
==============
*/
void SND_Update()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_UpdateWait
==============
*/
void __thiscall SND_UpdateWait(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_GameReset
==============
*/
void SND_GameReset()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_BeginFrame
==============
*/
void SND_BeginFrame(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetFrontendMusic
==============
*/
void SND_SetFrontendMusic(const char *musicAlias)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_SetLoopState
==============
*/
void SND_SetLoopState(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_PlayLoops
==============
*/
void SND_PlayLoops(int count, const SndEntLoop *loops)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_EndFrame
==============
*/
void SND_EndFrame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_Shutdown
==============
*/
void SND_Shutdown()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_PlaybackBundle
==============
*/
int SND_PlaybackBundle(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_Playback
==============
*/
int SND_Playback(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_Playback
==============
*/
int SND_Playback(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_StopSounds
==============
*/
void SND_StopSounds(SndStopSoundFlags flags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_RemoveBank
==============
*/
void SND_RemoveBank(SndBank *bank)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_RemovePatch
==============
*/
void SND_RemovePatch(SndPatch *patch)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_RemoveGlobals
==============
*/
void SND_RemoveGlobals(SndDriverGlobals *globals)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_GetEntPosition
==============
*/
char SND_GetEntPosition(SndEntHandle handle, vec3_t *origin, vec3_t *velocity, vec3_t *orientation)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_EntStateFrame
==============
*/
void SND_EntStateFrame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
updatesound_workerCallback
==============
*/
int updatesound_workerCallback(jqBatch *batch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

