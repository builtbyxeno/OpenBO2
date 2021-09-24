#include "types.h"

/*
==============
UI_BuildPlayerList
==============
*/
void UI_BuildPlayerList(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_FeederCount
==============
*/
int UI_FeederCount(LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, float feederID, listBoxDef_s *listPtr)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_FeederItemColor
==============
*/
void UI_FeederItemColor(ControllerIndex_t controllerIndex, UIContextIndex_t contextIndex, itemDef_s *item, const float feederID, int index, int column, vec4_t *color, bool onFocus)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_ResetSelectedPlayerXuid
==============
*/
void UI_ResetSelectedPlayerXuid()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_OverrideCursorPos_Gamemodes
==============
*/
void UI_OverrideCursorPos_Gamemodes(UIContextIndex_t contextIndex, listBoxDef_s *listPtr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_OverrideCursorPos_Servers
==============
*/
void UI_OverrideCursorPos_Servers(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, listBoxDef_s *listPtr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_OverrideKeyPress
==============
*/
char UI_OverrideKeyPress(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, int key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_OverrideCursorPos_DynamicMenu
==============
*/
void UI_OverrideCursorPos_DynamicMenu(UIContextIndex_t contextIndex, listBoxDef_s *listPtr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_OverrideCursorPos_Default
==============
*/
int UI_OverrideCursorPos_Default(LocalClientNum_t a1, int a2, int a3, float a4)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_OverrideCursorPos
==============
*/
/*void UI_OverrideCursorPos(int a1@<ebx>, LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
UI_FeederSelection
==============
*/
void UI_FeederSelection(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, float feederID, int index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_FeederDataExtended_DynamicMenu
==============
*/
bool UI_FeederDataExtended_DynamicMenu(int index, listBoxDef_s *listBox, const char *field, const char **stringResult)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_FeederDataExtended
==============
*/
bool UI_FeederDataExtended(LocalClientNum_t localClientNum, itemDef_s *item, const char *field)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_AddToFeeder
==============
*/
void UI_AddToFeeder(itemDef_s *item, const char *eventName, int argCount, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_AddToFeederExtended
==============
*/
void UI_AddToFeederExtended(itemDef_s *item, const char *onActionEvent, const char *onFocusEvent, bool disableCondition, int argCount, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_ChangeRowStatus
==============
*/
void UI_ChangeRowStatus(itemDef_s *item, int rowToChange, int newStatus)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_ClearFeeder
==============
*/
void UI_ClearFeeder(UIContextIndex_t contextIndex, itemDef_s *item, bool resetCursorPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_FeederData
==============
*/
bool UI_FeederData(LocalClientNum_t localClientNum, itemDef_s *item, const char *field, const char **stringResult, float *numberResult)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_FeederItemText_DynamicMenu
==============
*/
const char *UI_FeederItemText_DynamicMenu(UIContextIndex_t contextIndex, int index, int column, listBoxDef_s *listPtr, Material **handle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_RaiseFeederEvent
==============
*/
void UI_RaiseFeederEvent(LocalClientNum_t localClientNum, itemDef_s *item, const char *eventName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_FeederItemText
==============
*/
char *__cdecl UI_FeederItemText(LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, const float feederID, int index, int column, Material **handle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

