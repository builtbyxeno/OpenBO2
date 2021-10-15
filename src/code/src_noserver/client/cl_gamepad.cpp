#include "types.h"
#include "client_public.h"

GpadAxesGlob gaGlobs[1];
int lastGamepadEventTimeGlobal;

const char* physicalAxisNames[6] =
{
	"A_RSTICK_X",
	"A_RSTICK_Y",
	"A_LSTICK_X",
	"A_LSTICK_Y",
	"A_RTRIGGER",
	"A_LTRIGGER"
};

keyNum_t menuScrollButtonList[8] =
{
		K_DPAD_UP,
		K_DPAD_DOWN,
		K_DPAD_LEFT,
		K_DPAD_RIGHT,
		K_FIRSTGAMEPADBUTTON_RANGE_3,
		K_APAD_DOWN,
		K_APAD_LEFT,
		K_APAD_RIGHT
};

const char* inputTypeNames[2] = { "MAP_LINEAR", "MAP_SQUARED" };
const char* virtualAxisNames[6] = { "VA_SIDE", "VA_FORWARD", "VA_UP", "VA_YAW", "VA_PITCH", "VA_ATTACK" };

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

/*
==============
Gamepad_VirtualAxisName
==============
*/
const char* Gamepad_VirtualAxisName(GamepadVirtualAxis axis)
{
	assertMsg((axis >= 0 && axis < GPAD_VIRTAXIS_COUNT), "(axis) = %i", axis);
	return virtualAxisNames[axis];
}

/*
==============
Axis_NumToAxisString
==============
*/
const char* Axis_NumToAxisString(GamepadPhysicalAxis axis)
{
	assertMsg((axis >= 0 && axis < GPAD_PHYSAXIS_COUNT), "(axis) = %i", axis);
	return physicalAxisNames[axis];
}

/*
==============
Gamepad_InputTypeName
==============
*/
const char* Gamepad_InputTypeName(GamepadMapping mapType)
{
	assertMsg((mapType >= 0 && mapType < GPAD_MAP_COUNT), "(mapType) = %i", mapType);
	return inputTypeNames[mapType];
}

/*
==============
CL_GamepadEvent
==============
*/
void Gamepad_WriteBindings(LocalClientNum_t localClientNum, int f)
{
	GpadAxesGlob* gaGlob;
	const char* inputTypeName;
	const char* virtualAxisName;
	const char* realAxisName;
	int axis;

	gaGlob = &gaGlobs[localClientNum];
	FS_Printf(f, "unbindallaxis\n");

	for (axis = 0; axis < 6; ++axis)
	{
		if (gaGlob->virtualAxes[axis].physicalAxis != -1)
		{
			virtualAxisName = Gamepad_VirtualAxisName((GamepadVirtualAxis)axis);
			realAxisName = Axis_NumToAxisString(gaGlob->virtualAxes[axis].physicalAxis);
			inputTypeName = Gamepad_InputTypeName(gaGlob->virtualAxes[axis].mapType);
			assert(realAxisName);
			assert(virtualAxisName);
			assert(inputTypeName);

			FS_Printf(f, "bindaxis %s %s %s\n", realAxisName, virtualAxisName, inputTypeName);
		}
	}
}

