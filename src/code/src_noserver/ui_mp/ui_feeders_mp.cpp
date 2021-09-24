#include "types.h"

/*
==============
UI_GetMapCount
==============
*/
int UI_GetMapCount()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_Project_FeederCount
==============
*/
int UI_Project_FeederCount(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, float feederID)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_GetMapIdForNum
==============
*/
int UI_GetMapIdForNum(const int num)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_FeederItemText_Maps
==============
*/
const GfxViewParms *UI_FeederItemText_Maps(ControllerIndex_t controllerIndex, itemDef_s *item, int index, int column, Material **handle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_FeederItemColor_InGamePlayerList
==============
*/
bool UI_FeederItemColor_InGamePlayerList(ControllerIndex_t controllerIndex, UIContextIndex_t contextIndex, itemDef_s *item, int index, int column, vec4_t *color, bool onFocus, team_t team)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_FeederItemColor_ClanMembers
==============
*/
bool UI_FeederItemColor_ClanMembers(ControllerIndex_t controllerIndex, UIContextIndex_t contextIndex, itemDef_s *item, int index, int column, vec4_t *color, bool onFocus)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_FeederItemColor_AARScoreboard
==============
*/
bool UI_FeederItemColor_AARScoreboard(ControllerIndex_t controllerIndex, UIContextIndex_t contextIndex, float feederID, itemDef_s *item, int index, int column, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_Project_FeederItemColor
==============
*/
bool UI_Project_FeederItemColor(UIContextIndex_t a1, ControllerIndex_t controllerIndex, UIContextIndex_t contextIndex, itemDef_s *item, const float feederID, int index, int column)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_GetCurrentIndexForSplitscreen
==============
*/
int UI_GetCurrentIndexForSplitscreen(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_FeederDoubleClickDlcMaps
==============
*/
void UI_FeederDoubleClickDlcMaps(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, int index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_GetMapLoadNameForCurrentIndex
==============
*/
contentPackInfo *UI_GetMapLoadNameForCurrentIndex(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_OverrideCursorPos_Maps
==============
*/
void UI_OverrideCursorPos_Maps(UIContextIndex_t contextIndex, listBoxDef_s *listPtr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_OverrideCursorPos_Gametypes
==============
*/
void UI_OverrideCursorPos_Gametypes(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, listBoxDef_s *listPtr, float feederID)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_OverrideCursorPos_Contracts
==============
*/
void UI_OverrideCursorPos_Contracts(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, listBoxDef_s *listPtr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_Project_OverrideCursorPos
==============
*/
bool UI_Project_OverrideCursorPos(itemDef_s *a1, listBoxDef_s *a2, const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_FeederSelection_Maps
==============
*/
void UI_FeederSelection_Maps(UIContextIndex_t contextIndex, float feederID, int index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_FeederSelection_GametypesBase
==============
*/
void UI_FeederSelection_GametypesBase(LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, float feederID, int index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_Project_FeederSelection
==============
*/
void UI_Project_FeederSelection(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, float feederID, int index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_Project_FeederDataExtended
==============
*/
bool UI_Project_FeederDataExtended(ControllerIndex_t controllerIndex, UIContextIndex_t contextIndex, int feederID, listBoxDef_s *listBox, const char *field)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_FeederBackColor
==============
*/
void UI_FeederBackColor(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, const float feederID, int index, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

