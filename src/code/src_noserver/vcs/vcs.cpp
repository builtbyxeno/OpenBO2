#include "types.h"
#include "functions.h"

/*
==============
AddressROM
==============
*/
void AddressROM(Machine *machine, unsigned __int16 address)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RunDPC
==============
*/
void RunDPC(Machine *machine)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
WriteDPC
==============
*/
void WriteDPC(Machine *machine, unsigned __int16 address, unsigned __int8 b)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ReadDPC
==============
*/
unsigned __int8 ReadDPC(Machine *machine, unsigned __int16 address)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ReadROM
==============
*/
unsigned __int8 ReadROM(Machine *machine, unsigned __int16 address)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
InitAudio
==============
*/
void InitAudio(Machine *machine)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RunAudioChannel
==============
*/
unsigned __int8 RunAudioChannel(AudioState *audio)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RunAudio
==============
*/
void RunAudio(TIAState *TIA, int cycles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UpdatePlayField
==============
*/
void UpdatePlayField(TIAState *TIA)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AdjustPlayerX
==============
*/
int AdjustPlayerX(int pX, unsigned __int8 NUSIZ)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UpdateXCache
==============
*/
void UpdateXCache(TIAState *TIA, int i)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UpdateGRPCache
==============
*/
unsigned __int8 *UpdateGRPCache(TIAState *TIA, int i, unsigned __int8 GRP)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DrawTIA
==============
*/
void DrawTIA(TIAState *TIA, const int y, const int xStart, const int xEnd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RunTIA
==============
*/
void RunTIA(Machine *machine, int extra)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ModifyAudio
==============
*/
void ModifyAudio(TIAState *TIA, int index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RunPIA
==============
*/
void RunPIA(Machine *machine)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ReadPIA
==============
*/
unsigned __int8 ReadPIA(Machine *machine, unsigned __int16 address)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
WritePIA
==============
*/
void WritePIA(Machine *machine, unsigned __int16 address, unsigned __int8 b)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
WriteTIA
==============
*/
void WriteTIA(Machine *machine, unsigned __int16 address, unsigned __int8 b)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ReadByte
==============
*/
unsigned __int8 ReadByte(Machine *machine, unsigned __int16 address)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ReadWord
==============
*/
unsigned __int16 ReadWord(Machine *machine, unsigned __int16 address)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
WriteByte
==============
*/
void WriteByte(Machine *machine, unsigned __int16 address, unsigned __int8 b)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SetNZ
==============
*/
void SetNZ(MOSState *MOS, unsigned __int8 value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PushByte
==============
*/
void PushByte(Machine *machine, unsigned __int8 b)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PopByte
==============
*/
unsigned __int8 PopByte(Machine *machine)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PushWord
==============
*/
void PushWord(Machine *machine, unsigned __int16 w)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PopWord
==============
*/
unsigned __int16 PopWord(Machine *machine)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ReadOperand
==============
*/
unsigned __int8 ReadOperand(Machine *machine, Operand *operand)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
WriteOperand
==============
*/
void WriteOperand(Machine *machine, Operand *operand, unsigned __int8 b)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetBCD
==============
*/
unsigned __int8 GetBCD(int v)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AddWithCarry
==============
*/
unsigned __int8 AddWithCarry(unsigned __int8 a, unsigned __int8 b, unsigned __int8 c, unsigned __int8 *SR)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RunMOS
==============
*/
void RunMOS(Machine *machine)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VCS_CreateMachine
==============
*/
Machine *VCS_CreateMachine()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
VCS_ResetMachine
==============
*/
void VCS_ResetMachine(unsigned __int16 a1, Machine *a2, Machine *machine)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VCS_InitMachine
==============
*/
char VCS_InitMachine(Machine *machine, ROMInfo *info)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VCS_GetAudioData
==============
*/
char VCS_GetAudioData(Machine *machine, float *data, int sampleCount, int rate)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VCS_RunFrame
==============
*/
char VCS_RunFrame(Machine *machine)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

