#include "types.h"
#include "vars.h"

#define MAX_GPAD_COUNT 1
#define GPAD_STICK_MASK 0x40000000
#define GPAD_STICK_COUNT 4

GamePad s_gamePads[MAX_GPAD_COUNT];
XINPUT_STATE delayedInputState[MAX_GPAD_COUNT];
bool hasInput[MAX_GPAD_COUNT];
int inputCounter;

void (*s_insertedCB)(int);
void (*s_removedCB)(int);

/*
==============
TRACK_win_gamepad
==============
*/
void TRACK_win_gamepad()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GPad_UpdateDigitals
==============
*/
void GPad_UpdateDigitals(ControllerIndex_t portIndex, const _XINPUT_GAMEPAD *xpad)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GPad_UpdateAnalogs
==============
*/
void GPad_UpdateAnalogs(ControllerIndex_t portIndex, const _XINPUT_GAMEPAD *xpad)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GPad_ConvertStickToFloat
==============
*/
void GPad_ConvertStickToFloat(__int16 inX, __int16 inY, float *outX, float *outY)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GPad_UpdateSticksDown
==============
*/
void GPad_UpdateSticksDown(GamePad *gPad)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GPad_UpdateSticks
==============
*/
void GPad_UpdateSticks(__int16 a1, ControllerIndex_t portIndex, const _XINPUT_GAMEPAD *xpad)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GPad_StopRumbles
==============
*/
void GPad_StopRumbles(ControllerIndex_t portIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GPad_InUse
==============
*/
BOOL GPad_InUse(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GPad_IsActive
==============
*/
bool GPad_IsActive(ControllerIndex_t portIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GPad_GetButton
==============
*/
double GPad_GetButton(ControllerIndex_t portIndex, GamePadButton button)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GPad_ButtonRequiresUpdates
==============
*/
bool GPad_ButtonRequiresUpdates(ControllerIndex_t portIndex, GamePadButton button)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GPad_IsButtonPressed
==============
*/
BOOL GPad_IsButtonPressed(ControllerIndex_t portIndex, GamePadButton button)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GPad_IsButtonReleased
==============
*/
BOOL GPad_IsButtonReleased(ControllerIndex_t portIndex, GamePadButton button)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GPad_GetStick
==============
*/
double GPad_GetStick(ControllerIndex_t portIndex, GamePadStick stick)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GPad_SetLowRumble
==============
*/
void GPad_SetLowRumble(ControllerIndex_t portIndex, float rumble)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GPad_SetHighRumble
==============
*/
void GPad_SetHighRumble(ControllerIndex_t portIndex, float rumble)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GPad_GetStickChangedToPressedState
==============
*/
bool GPad_GetStickChangedToPressedState(ControllerIndex_t portIndex, GamePadStick stick, GamePadStickDir stickDir, bool pressedState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GPad_IsStickPressed
==============
*/
bool GPad_IsStickPressed(GamePadStick a1, ControllerIndex_t portIndex, GamePadStick stick, GamePadStickDir stickDir)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GPad_IsStickReleased
==============
*/
bool GPad_IsStickReleased(GamePadStick a1, ControllerIndex_t portIndex, GamePadStick stick, GamePadStickDir stickDir)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GPad_RefreshAll
==============
*/
void GPad_RefreshAll()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GPad_UpdateAll
==============
*/
void GPad_UpdateAll()
{
	UNIMPLEMENTED(__FUNCTION__);
}

