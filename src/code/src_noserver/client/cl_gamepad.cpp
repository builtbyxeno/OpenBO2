#include "types.h"
#include "functions.h"

/*
==============
CL_ResetLastGamePadEventTime
==============
*/
void CL_ResetLastGamePadEventTime()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_InitGamepadAxisBindings
==============
*/
void CL_InitGamepadAxisBindings()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Gamepad_StringToPhysicalAxis
==============
*/
GamepadPhysicalAxis Gamepad_StringToPhysicalAxis(const char *axisName)
{
	UNIMPLEMENTED(__FUNCTION__);
	GamepadPhysicalAxis tmp;
	return tmp;
}

/*
==============
Axis_StringToVirtualAxis
==============
*/
GamepadVirtualAxis Axis_StringToVirtualAxis(const char *axisName)
{
	UNIMPLEMENTED(__FUNCTION__);
	GamepadVirtualAxis tmp;
	return tmp;
}

/*
==============
Gamepad_InputTypeStringToId
==============
*/
GamepadMapping Gamepad_InputTypeStringToId(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	GamepadMapping tmp;
	return tmp;
}

/*
==============
Gamepad_BindAxis
==============
*/
void Gamepad_BindAxis(GpadAxesGlob *gaGlob, GamepadPhysicalAxis realIndex, GamepadVirtualAxis axisIndex, GamepadMapping mapType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Axis_Bind_f
==============
*/
void Axis_Bind_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Axis_Unbindall_f
==============
*/
void Axis_Unbindall_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_GamepadAxisValue
==============
*/
double CL_GamepadAxisValue(LocalClientNum_t localClientNum, int virtualAxis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_CheckForIgnoreDueToRepeat
==============
*/
bool CL_CheckForIgnoreDueToRepeat(LocalClientNum_t localClientNum, int key, int repeatCount, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_GamepadResetMenuScrollTime
==============
*/
void CL_GamepadResetMenuScrollTime(LocalClientNum_t localClientNum, int key, int down, unsigned int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamepadButtonEvent_LocationSelection
==============
*/
bool GamepadButtonEvent_LocationSelection(bool pressed, int keyCatchers, KeyState *keys, int key, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamepadButtonEvent_DevguiKeyEvent
==============
*/
bool GamepadButtonEvent_DevguiKeyEvent(LocalClientNum_t localClientNum, bool pressed, const char *kb, int keyCatchers, connstate_t clcState, int activeMenu)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamepadButtonEvent_UnlockableItems
==============
*/
void GamepadButtonEvent_UnlockableItems(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, int key, KeyState *keys)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamepadButtonEvent_Cheats
==============
*/
void GamepadButtonEvent_Cheats(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, int key, bool pressed, KeyState *keys)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_GamepadButtonEvent
==============
*/
void CL_GamepadButtonEvent(char *a1, LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, int key, int buttonEvent, unsigned int time, int gamePadButton)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_GamepadButtonEventForPort
==============
*/
void CL_GamepadButtonEventForPort(ControllerIndex_t portIndex, int key, int buttonEvent, unsigned int time, int button)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_InitGamepadCommands
==============
*/
void CL_InitGamepadCommands()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_GamepadGenerateAPad
==============
*/
void CL_GamepadGenerateAPad(LocalClientNum_t localClientNum, ControllerIndex_t portIndex, int physicalAxis, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_GamepadEvent
==============
*/
void CL_GamepadEvent(ControllerIndex_t portIndex, int physicalAxis, int value, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

