#include "types.h"
#include "functions.h"

/*
==============
SND_GetSpeakerConfigCount
==============
*/
unsigned int __thiscall SND_GetSpeakerConfigCount(gjk_double_sphere_t *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Snd_GetSpeakerConfig
==============
*/
SndSpeakerConfig *Snd_GetSpeakerConfig(unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Snd_GetMixChannelCount
==============
*/
int Snd_GetMixChannelCount(unsigned int speakerConfig)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Snd_PanMono
==============
*/
double Snd_PanMono(float angle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_EqualPowerFadeCoefs
==============
*/
void SND_EqualPowerFadeCoefs(float t, float a, float *a3, float *b)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_GetNearestPointOnSegment
==============
*/
void SND_GetNearestPointOnSegment(const vec3_t *P, const vec3_t *segmentA, const vec3_t *segmentB, vec3_t *nearPoint)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_GetNearestPointOnStrip
==============
*/
void SND_GetNearestPointOnStrip(const vec3_t *point, const vec3_t *verts, unsigned int count, vec3_t *position)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_GetAliasName
==============
*/
const char *SND_GetAliasName(const SndAliasList *alias)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SND_LinearToDbSpl
==============
*/
double SND_LinearToDbSpl(float linear)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_HashName
==============
*/
int SND_HashName(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Snd_SpeakerMapZero
==============
*/
void Snd_SpeakerMapZero(SndSpeakerMap *map)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Snd_SpeakerMapGetIndex
==============
*/
int Snd_SpeakerMapGetIndex(const SndSpeakerMap *map, int in, int out)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Snd_SpeakerMapGetVolume
==============
*/
double Snd_SpeakerMapGetVolume(const SndSpeakerMap *map, int in, int out)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Snd_GetGlobalPriority
==============
*/
double Snd_GetGlobalPriority(const SndAlias *alias, float volume)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Snd_CurveEval
==============
*/
double Snd_CurveEval(const SndCurve *curve, float x)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_HashAlias
==============
*/
unsigned int SND_HashAlias(const SndAliasList *alias)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Snd_PanStereo
==============
*/
void Snd_PanStereo(float angle, float boost, float *left, float *right)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Snd_Pan
==============
*/
/*void Snd_Pan(const char *a1@<edi>, unsigned int speakerCount, const float *angles, float toSound, float *levels)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Snd_SpeakerMapSetVolume
==============
*/
void Snd_SpeakerMapSetVolume(SndSpeakerMap *map, int in, int out, float volume)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_PanToSpeakermap11
==============
*/
void SND_PanToSpeakermap11(const SndPan *pan, SndSpeakerMap *map)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_PanToSpeakermap12
==============
*/
void SND_PanToSpeakermap12(const SndPan *pan, SndSpeakerMap *map)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_PanToSpeakermap16
==============
*/
void SND_PanToSpeakermap16(const SndPan *pan, SndSpeakerMap *map)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_PanToSpeakermap18
==============
*/
void SND_PanToSpeakermap18(const SndPan *pan, SndSpeakerMap *map)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_PanToSpeakermap21
==============
*/
void SND_PanToSpeakermap21(const SndPan *pan, SndSpeakerMap *map)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_PanToSpeakermap22
==============
*/
void SND_PanToSpeakermap22(const SndPan *pan, SndSpeakerMap *map)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_PanToSpeakermap26
==============
*/
void SND_PanToSpeakermap26(const SndPan *pan, SndSpeakerMap *map)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_PanToSpeakermap28
==============
*/
void SND_PanToSpeakermap28(const SndPan *pan, SndSpeakerMap *map)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SND_PanToSpeakermap
==============
*/
void SND_PanToSpeakermap(SndSpeakerMap *a1, const SndPan *a2, unsigned int inputChannelCount, unsigned int outputChannelCount, const SndPan *pan, float centerSend, SndSpeakerMap *map)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Snd_Pan3dFast
==============
*/
void Snd_Pan3dFast(const vec3_t *position, const vec3_t *f, const vec3_t *listener, float centerSend, float lfeSend, float aliasOmni, SndSpeakerMap *pan)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Snd_DistanceCurveEval
==============
*/
double Snd_DistanceCurveEval(const SndCurve *minCurve, const SndCurve *curve, float minDist, float maxDist, float dist)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SND_FixupStereoPan
==============
*/
void SND_FixupStereoPan(SndSpeakerMap *pan)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Snd_Pan3d
==============
*/
void Snd_Pan3d(const SndSpeakerConfig *config, const vec3_t *position, const vec3_t *forward, const vec3_t *listener, float centerSend, float lfeSend, float aliasOmni, SndSpeakerMap *pan)
{
	UNIMPLEMENTED(__FUNCTION__);
}

