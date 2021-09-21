#pragma once

#include "types.h"

//t6/code/src_noserver/groupvoice/decode.cpp
void Decode_Shutdown();
int Decode_Sample(char *buffer, int maxLength, __int16 *out, int frame_size);
char Decode_Init(int bandwidthEnum);

//t6/code/src_noserver/groupvoice/encode.cpp
void Encode_SetOptions(int frequency, int quality);
bool Encode_Init(int bandwidthEnum);
char Encode_Shutdown();
int Encode_Sample(__int16 *buffer_in, char *buffer_out, int maxLength);
int Encode_GetFrameSize();

//t6/code/src_noserver/groupvoice/play.cpp
;
;
;
;
;
;
int Sound_Init(const void *handle);
;

//t6/code/src_noserver/groupvoice/play_dsound.cpp
HRESULT CreateBasicBuffer(IDirectSound8 *lpDirectSound, IDirectSoundBuffer **ppDsb, int sampleRate, int channels, int bufferSize);
void DSound_AdjustSamplePlayback(dsound_sample_t *sample, int bytesLeft);
void DSound_HandleBufferUnderrun(dsound_sample_t *sample);
void DSound_SetVolume(dsound_sample_t *sample, int level);
;
char DSound_StopSample(dsound_sample_t *sample);
int DSound_Init(bool callDsoundInit, const void *handle);
void DSound_Shutdown();
unsigned int DSound_UpdateSample(dsound_sample_t *sample, char *data, unsigned int data_len);
void DSound_SampleFrame(dsound_sample_t *sample);

//t6/code/src_noserver/groupvoice/record.cpp
int Record_QueueAudioDataForEncoding(audioSample_t *sample);
int Record_AudioCallback(audioSample_t *sample);
int Record_Stop(dsound_sample_t *sample);
int Record_DestroySample(dsound_sample_t *sample);
void Record_Shutdown();
int Record_Init(bool callInit, const void *handle);

//t6/code/src_noserver/groupvoice/record_dsound.cpp
dsound_sample_t *DSOUNDRecord_NewSample();
int DSOUNDRecord_DestroySample(dsound_sample_t *pRecSample);
int DSOUNDRecord_Stop(int a1, int a2, dsound_sample_t *pRecSample);
const char *GetDSoundErrorDesc(HRESULT hr);
int DSOUNDRecord_Init(bool bCallDsoundInit);
void DSOUNDRecord_Shutdown();

