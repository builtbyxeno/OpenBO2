#pragma once

#include "types.h"

//t6/code/src_noserver/vcs/vcs.cpp
void AddressROM(Machine *machine, unsigned __int16 address);
void RunDPC(Machine *machine);
void WriteDPC(Machine *machine, unsigned __int16 address, unsigned __int8 b);
unsigned __int8 ReadDPC(Machine *machine, unsigned __int16 address);
unsigned __int8 ReadROM(Machine *machine, unsigned __int16 address);
void InitAudio(Machine *machine);
unsigned __int8 RunAudioChannel(AudioState *audio);
void RunAudio(TIAState *TIA, int cycles);
void UpdatePlayField(TIAState *TIA);
int AdjustPlayerX(int pX, unsigned __int8 NUSIZ);
void UpdateXCache(TIAState *TIA, int i);
unsigned __int8 *UpdateGRPCache(TIAState *TIA, int i, unsigned __int8 GRP);
void DrawTIA(TIAState *TIA, const int y, const int xStart, const int xEnd);
void RunTIA(Machine *machine, int extra);
void ModifyAudio(TIAState *TIA, int index);
void RunPIA(Machine *machine);
unsigned __int8 ReadPIA(Machine *machine, unsigned __int16 address);
;
;
unsigned __int8 ReadByte(Machine *machine, unsigned __int16 address);
unsigned __int16 ReadWord(Machine *machine, unsigned __int16 address);
;
void SetNZ(MOSState *MOS, unsigned __int8 value);
;
unsigned __int8 PopByte(Machine *machine);
;
unsigned __int16 PopWord(Machine *machine);
unsigned __int8 ReadOperand(Machine *machine, Operand *operand);
;
unsigned __int8 GetBCD(int v);
unsigned __int8 AddWithCarry(unsigned __int8 a, unsigned __int8 b, unsigned __int8 c, unsigned __int8 *SR);
void RunMOS(Machine *machine);
Machine *VCS_CreateMachine();
void VCS_ResetMachine(unsigned __int16 a1, Machine *a2, Machine *machine);
char VCS_InitMachine(Machine *machine, ROMInfo *info);
char VCS_GetAudioData(Machine *machine, float *data, int sampleCount, int rate);
char VCS_RunFrame(Machine *machine);

//t6/code/src_noserver/vcs/vcs_hooks.cpp
char VCS_AudioCallback(float *out, unsigned int frameCount, unsigned int channelCount, bool *isGlove);
void VCS_Start(const LocalClientNum_t localClientNum, const char *rom, int target3D);
void VCS_Stop();
int VCS_RunFrameFuncCallback_Implementation();
void VCS_Start_f();
void VCS_Init();
int VCS_RunFrameFuncCallback(jqBatch *batch);

