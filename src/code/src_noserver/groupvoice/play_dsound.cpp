#include "types.h"
#include "functions.h"

/*
==============
CreateBasicBuffer
==============
*/
HRESULT CreateBasicBuffer(IDirectSound8 *lpDirectSound, IDirectSoundBuffer **ppDsb, int sampleRate, int channels, int bufferSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	HRESULT tmp;
	return tmp;
}

/*
==============
DSound_AdjustSamplePlayback
==============
*/
void DSound_AdjustSamplePlayback(dsound_sample_t *sample, int bytesLeft)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DSound_HandleBufferUnderrun
==============
*/
void DSound_HandleBufferUnderrun(dsound_sample_t *sample)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DSound_SetVolume
==============
*/
void DSound_SetVolume(dsound_sample_t *sample, int level)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DSound_NewSample
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
DSound_StopSample
==============
*/
char DSound_StopSample(dsound_sample_t *sample)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DSound_Init
==============
*/
int DSound_Init(bool callDsoundInit, const void *handle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DSound_Shutdown
==============
*/
void DSound_Shutdown()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DSound_UpdateSample
==============
*/
unsigned int DSound_UpdateSample(dsound_sample_t *sample, char *data, unsigned int data_len)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DSound_SampleFrame
==============
*/
void DSound_SampleFrame(dsound_sample_t *sample)
{
	UNIMPLEMENTED(__FUNCTION__);
}

