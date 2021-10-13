#include "types.h"

/*
==============
Voice_StopClientSamples
==============
*/
void Voice_StopClientSamples()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Voice_IncomingVoiceData_Platform
==============
*/
int Voice_IncomingVoiceData_Platform(SessionData *session, ClientNum_t talker, unsigned __int8 *data, int packetDataSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Voice_IsClientTalking
==============
*/
bool Voice_IsClientTalking(ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Mixer_GetRecordLevel
==============
*/
unsigned int Mixer_GetRecordLevel(unsigned int mixerID, unsigned int waveInLineID)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Mixer_GetMuteState
==============
*/
int Mixer_GetMuteState(unsigned int mixerID, unsigned int waveInLineID)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Voice_IsLocalClientTalking
==============
*/
BOOL Voice_IsLocalClientTalking()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Voice_IsHeadsetPresent
==============
*/
BOOL Voice_IsHeadsetPresent()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Voice_IsXuidTalking
==============
*/
bool Voice_IsXuidTalking(SessionData *session, ControllerIndex_t localControllerIndex, unsigned __int64 xuid)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Mixer_InitWaveInLineInfo
==============
*/
UINT Mixer_InitWaveInLineInfo()
{
	UNIMPLEMENTED(__FUNCTION__);
	UINT tmp;
	return tmp;
}

/*
==============
Mixer_SetWaveInRecordLevels
==============
*/
void Mixer_SetWaveInRecordLevels(int newLevel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mixer_RestoreWaveInRecordLevels
==============
*/
void Mixer_RestoreWaveInRecordLevels()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mixer_SetWaveInMuteStates
==============
*/
void Mixer_SetWaveInMuteStates(int muteState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mixer_RestoreWaveInMuteStates
==============
*/
void Mixer_RestoreWaveInMuteStates()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Voice_Init
==============
*/
char Voice_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Voice_Shutdown
==============
*/
void Voice_Shutdown()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Voice_Playback
==============
*/
void Voice_Playback(ControllerIndex_t a1, const char *a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

