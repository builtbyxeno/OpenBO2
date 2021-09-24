#include "types.h"

/*
==============
CG_RegisterSoundDvars
==============
*/
void CG_RegisterSoundDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ClearSoundPlaybackTracking
==============
*/
void CG_ClearSoundPlaybackTracking()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ShouldPlaySoundOnLocalClient
==============
*/
bool CG_ShouldPlaySoundOnLocalClient(LocalClientNum_t localClientNum, int entitynum, const vec3_t *origin, unsigned int aliasname)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_SndEntHandle
==============
*/
SndEntHandle CG_SndEntHandle(LocalClientNum_t localClientNum, int entIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	SndEntHandle tmp;
	return tmp;
}

/*
==============
CG_PlaySound
==============
*/
void CG_PlaySound(LocalClientNum_t localClientNum, int entitynum, const vec3_t *origin, int fadeMs, bool doNotify, float attenuation, unsigned int id)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PlaySound
==============
*/
void CG_PlaySound(LocalClientNum_t localClientNum, int entitynum, const vec3_t *origin, int fadeMs, bool doNotify, float attenuation, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PlaySound
==============
*/
void CG_PlaySound(LocalClientNum_t localClientNum, const vec3_t *origin, int fadeMs, bool doNotify, float attenuation, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PlaySoundWithHandle
==============
*/
int CG_PlaySoundWithHandle(LocalClientNum_t localClientNum, int entitynum, const vec3_t *origin, int fadeMs, bool doNotify, float volume, unsigned int id)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_PlaySoundWithHandle
==============
*/
int CG_PlaySoundWithHandle(LocalClientNum_t localClientNum, int entitynum, const vec3_t *origin, int fadeMs, bool doNotify, float attenuation, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_FlushLoops
==============
*/
void CG_FlushLoops()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PumpEntityLoopSound
==============
*/
void CG_PumpEntityLoopSound(LocalClientNum_t localClientNum, const centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PlayAnimScriptSoundAlias
==============
*/
void CG_PlayAnimScriptSoundAlias(ClientNum_t clientIndex, SndAliasList *aliasList)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SubtitlePrint
==============
*/
void CG_SubtitlePrint(int msec, const char *subtitle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SubtitleSndLengthNotify
==============
*/
void CG_SubtitleSndLengthNotify(int msec, const char *lengthNotifyData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ScriptSndLengthNotify
==============
*/
void CG_ScriptSndLengthNotify(int msec, int lengthNotifyData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CopySoundEntityOrientation
==============
*/
void CG_CopySoundEntityOrientation(LocalClientNum_t localClientNum, int entIndex, vec3_t *origin_out, vec3_t *axis_out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SoundGetUseCount
==============
*/
unsigned int CG_SoundGetUseCount(const SndEntHandle sndEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetSoundEntityOrientation
==============
*/
void CG_GetSoundEntityOrientation(const SndEntHandle sndEnt, vec3_t *origin_out, vec3_t *axis_out, vec3_t *velocity_out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_StopSoundAlias
==============
*/
void CG_StopSoundAlias(LocalClientNum_t localClientNum, int entityNum, unsigned int aliasName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SndFireReset
==============
*/
void CG_SndFireReset()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SndUpdateFire
==============
*/
void CG_SndUpdateFire()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_FlameSourceUpdate
==============
*/
void CG_FlameSourceUpdate(LocalClientNum_t localClientNum, int entityNum, const vec3_t *sourcePosition, const vec3_t *flamePosition, snd_flame_source_flags flags, const char *flameOffLoopSound, const char *flameIgniteSound, const char *flameOnLoopSound, const char *flameCooldownSound)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SoundWhizby
==============
*/
void CG_SoundWhizby(LocalClientNum_t localClientNum, const WeaponDef *weapDef, const vec3_t *shotPosition, const vec3_t *shotDirection, const vec3_t *position)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SndUpdate
==============
*/
void CG_SndUpdate()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SoundUpdateListeners
==============
*/
void CG_SoundUpdateListeners(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetLoopingSoundPosition
==============
*/
void CG_GetLoopingSoundPosition(LocalClientNum_t localClientNum, centity_t *cent, vec3_t *sndOrigin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateLoopingFireSounds
==============
*/
void CG_UpdateLoopingFireSounds(LocalClientNum_t localClientNum, cg_t *cgameGlob, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CheckADSRaiseAndLower
==============
*/
void CG_CheckADSRaiseAndLower(LocalClientNum_t localClientNum, cg_t *cgameGlob, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Turret_UpdateTurretRotationSound
==============
*/
void CG_Turret_UpdateTurretRotationSound(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SoundForceAmbientRoomChange
==============
*/
void CG_SoundForceAmbientRoomChange(bool forceChange, bool defaultRoom, unsigned int roomHash)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SoundForceAmbientPackageChange
==============
*/
void CG_SoundForceAmbientPackageChange(bool forceChange, bool defaultPackage, unsigned int packageHash)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SoundInitAmbientColliders
==============
*/
void CG_SoundInitAmbientColliders()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SoundSetAmbientData
==============
*/
void CG_SoundSetAmbientData(const snd_ambient_script_data *ambData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SoundSetAmbientContext
==============
*/
void CG_SoundSetAmbientContext(const unsigned int roomName, const char *ctxType, const char *ctxValue, const bool defaultRoom)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetHighestPriorityRoomIndices
==============
*/
void CG_GetHighestPriorityRoomIndices(cg_t *cgameGlob, snd_ambient_collider *currentCollider)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SoundAmbientCheckOverrides
==============
*/
void CG_SoundAmbientCheckOverrides(cg_t *cgameGlob, snd_ambient_collider *collider)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SoundUpdateAmbient
==============
*/
void CG_SoundUpdateAmbient()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_StopZombieVoxSounds
==============
*/
void CG_StopZombieVoxSounds(LocalClientNum_t localClientNum, int entityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SoundEntInUse
==============
*/
bool CG_SoundEntInUse(const SndEntHandle sndEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_SndGameReset
==============
*/
void CG_SndGameReset()
{
	UNIMPLEMENTED(__FUNCTION__);
}

