#include "types.h"
#include "functions.h"

/*
==============
MenuNameHash_t::MenuNameHash_t
==============
*/
/*void __thiscall MenuNameHash_t::MenuNameHash_t(MenuNameHash_t *this, const char *s)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
UI_GetUTFHeaderSize
==============
*/
int UI_GetUTFHeaderSize(const char *buff)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_Fade
==============
*/
void Item_Fade(UIContextIndex_t contextIndex, itemDef_s *item, int fadeOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_SetColor
==============
*/
void Item_SetColor(itemDef_s *item, const char *name, UIContextIndex_t contextIndex, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_Setup
==============
*/
void Menu_Setup(UiContext *dc)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Color_Parse
==============
*/
int Color_Parse(const char **p, vec4_t *c)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
String_Parse
==============
*/
int String_Parse(const char **p, char *out, int len)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Command_Parse
==============
*/
BOOL Command_Parse(const char **p, char *out, int len)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Window_Paint
==============
*/
void Window_Paint(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_IsModal
==============
*/
bool Item_IsModal(itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Rect_ContainsPoint
==============
*/
int Rect_ContainsPoint(UIContextIndex_t contextIndex, const rectDef_s *rect, float x, float y)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Menu_ItemsMatchingGroup
==============
*/
int Menu_ItemsMatchingGroup(menuDef_t *menu, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Menu_GetMatchingItemByNumber
==============
*/
itemDef_s *Menu_GetMatchingItemByNumber(menuDef_t *menu, int index, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Script_SetColor
==============
*/
void Script_SetColor(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_SetBackground
==============
*/
void Script_SetBackground(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_FindItemByName
==============
*/
itemDef_s *Menu_FindItemByName(menuDef_t *menu, const char *p)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Menu_FindFirstFocusableItemByName
==============
*/
itemDef_s *Menu_FindFirstFocusableItemByName(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Item_FindStateByName
==============
*/
animParamsDef_t *Item_FindStateByName(itemDef_s *item, const char *p)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Item_LerpAnimationParameters
==============
*/
void Item_LerpAnimationParameters(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_SetShaderTime
==============
*/
void UI_SetShaderTime(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_SetItemColor
==============
*/
void Script_SetItemColor(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_ShowItemByName
==============
*/
void Menu_ShowItemByName(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_FadeItemByName
==============
*/
void Menu_FadeItemByName(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menus_RemoveFromStack
==============
*/
int Menus_RemoveFromStack(const LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *pMenu)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Menus_AddToStack
==============
*/
void Menus_AddToStack(const LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *pMenu)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menus_MenuIsInStack
==============
*/
int Menus_MenuIsInStack(UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Menus_MenuInStackLocalClientNum
==============
*/
LocalClientNum_t Menus_MenuInStackLocalClientNum(UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
	LocalClientNum_t tmp;
	return tmp;
}

/*
==============
Menus_FindIndexByHash
==============
*/
int Menus_FindIndexByHash(UiContext *dc, unsigned int hash)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Menus_FindByHash
==============
*/
menuDef_t *Menus_FindByHash(UiContext *dc, unsigned int hash)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Menus_FindByName
==============
*/
menuDef_t *Menus_FindByName(const UiContext *dc, const char *p)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Menus_HideByName
==============
*/
void Menus_HideByName(const UiContext *dc, const char *menuName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menus_ShowByName
==============
*/
void Menus_ShowByName(const UiContext *dc, const char *windowName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menus_RemoveMenu
==============
*/
void Menus_RemoveMenu(XAssetHeader header)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_DoesEventExist
==============
*/
char Item_DoesEventExist(itemDef_s *item, const char *eventName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Menus_DoesEventExist
==============
*/
char Menus_DoesEventExist(menuDef_t *menu, const char *eventName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_ClearErrors
==============
*/
void UI_ClearErrors()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_Show
==============
*/
void Script_Show(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_Hide
==============
*/
void Script_Hide(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_FadeIn
==============
*/
void Script_FadeIn(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_FadeOut
==============
*/
void Script_FadeOut(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ShowMenu
==============
*/
void Script_ShowMenu(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_HideMenu
==============
*/
void Script_HideMenu(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_OpParse
==============
*/
void Script_OpParse(int *operand, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_IntParse
==============
*/
int Script_IntParse(UiContext *dc, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Script_TableLookupParse
==============
*/
const char *Script_TableLookupParse(UiContext *dc, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Script_SetDvarStringUsingTable
==============
*/
void Script_SetDvarStringUsingTable(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_SetDvar
==============
*/
void Script_SetDvar(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ResetDvar
==============
*/
void Script_ResetDvar(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_AddTextWrapper
==============
*/
void Script_AddTextWrapper(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_Exec
==============
*/
void Script_Exec(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ExecNow
==============
*/
void Script_ExecNow(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ConditionalExecHandler
==============
*/
void Script_ConditionalExecHandler(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ConditionalResponseHandler
==============
*/
void Script_ConditionalResponseHandler(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ExecIfStringsEqual
==============
*/
BOOL Script_ExecIfStringsEqual(const char *dvarValue, const char *testValue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Script_ExecIfIntsEqual
==============
*/
bool Script_ExecIfIntsEqual(const char *dvarValue, const char *testValue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Script_ExecIfFloatsEqual
==============
*/
BOOL Script_ExecIfFloatsEqual(const char *dvarValue, const char *testValue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Script_ExecOnDvarStringValue
==============
*/
void Script_ExecOnDvarStringValue(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ExecOnDvarIntValue
==============
*/
void Script_ExecOnDvarIntValue(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ExecOnDvarFloatValue
==============
*/
void Script_ExecOnDvarFloatValue(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ExecNowOnDvarStringValue
==============
*/
void Script_ExecNowOnDvarStringValue(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ExecNowOnDvarIntValue
==============
*/
void Script_ExecNowOnDvarIntValue(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ExecNowOnDvarFloatValue
==============
*/
void Script_ExecNowOnDvarFloatValue(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_RespondOnDvarStringValue
==============
*/
void Script_RespondOnDvarStringValue(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_RespondOnDvarIntValue
==============
*/
void Script_RespondOnDvarIntValue(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_RespondOnDvarFloatValue
==============
*/
void Script_RespondOnDvarFloatValue(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_SetLocalVarBool
==============
*/
void Script_SetLocalVarBool(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_SetLocalVarInt
==============
*/
void Script_SetLocalVarInt(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_SetLocalVarFloat
==============
*/
void Script_SetLocalVarFloat(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_SetLocalVarString
==============
*/
void Script_SetLocalVarString(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_FeederTop
==============
*/
void Script_FeederTop(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_SessionMode_SetOnlineGame
==============
*/
void Script_SessionMode_SetOnlineGame(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_SessionMode_SetSystemLink
==============
*/
void Script_SessionMode_SetSystemLink(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_SessionMode_SetPrivate
==============
*/
void Script_SessionMode_SetPrivate(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_GameMode_SetMode
==============
*/
void Script_GameMode_SetMode(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_GameMode_ResetModes
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Script_SessionMode_ResetModes
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Script_ScriptMenuResponse
==============
*/
void Script_ScriptMenuResponse(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_ArePrereqsSatisfied
==============
*/
char Item_ArePrereqsSatisfied(GenericEventScript *eventScript, nestingStack_t *stack)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_IsConditionSatisfied
==============
*/
bool Item_IsConditionSatisfied(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_RunScript
==============
*/
void Item_RunScript(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char *s)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_SetLocalVarBool_f
==============
*/
void UI_SetLocalVarBool_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_SetLocalVarInt_f
==============
*/
void UI_SetLocalVarInt_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_SetLocalVarFloat_f
==============
*/
void UI_SetLocalVarFloat_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_SetLocalVarString_f
==============
*/
void UI_SetLocalVarString_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_FadeItem_f
==============
*/
void UI_FadeItem_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_ShowItem_f
==============
*/
void UI_ShowItem_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_HideItem_f
==============
*/
void UI_HideItem_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_ShowMenu_f
==============
*/
void UI_ShowMenu_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_HideMenu_f
==============
*/
void UI_HideMenu_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_ChangeMenuOpenSlideDirection_f
==============
*/
void UI_ChangeMenuOpenSlideDirection_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_ChangeMenuCloseSlideDirection_f
==============
*/
void UI_ChangeMenuCloseSlideDirection_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_OpenToastPopup_f
==============
*/
void UI_OpenToastPopup_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_AddToFeeder_f
==============
*/
void UI_AddToFeeder_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_AddToFeederExtended_f
==============
*/
void UI_AddToFeederExtended_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_ClearFeeder_f
==============
*/
void UI_ClearFeeder_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_ClearFeederWithoutResetCursor_f
==============
*/
void UI_ClearFeederWithoutResetCursor_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_RaiseFeederEvent_f
==============
*/
void UI_RaiseFeederEvent_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_RefreshFeeder_f
==============
*/
void UI_RefreshFeeder_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_ChangeRowStatus_f
==============
*/
void UI_ChangeRowStatus_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_ValidatePrivateMatchGametype_f
==============
*/
void UI_ValidatePrivateMatchGametype_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_SetActiveMenu_f
==============
*/
void UI_SetActiveMenu_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_KickPlayer_f
==============
*/
void UI_KickPlayer_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_ListBox_GetMaxHeight
==============
*/
float Item_ListBox_GetMaxHeight(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_ListBox_Viewmax
==============
*/
/*int Item_ListBox_Viewmax@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
Item_Slider_ThumbPosition
==============
*/
float Item_Slider_ThumbPosition(const LocalClientNum_t localClientNum, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_Slider_OverSlider
==============
*/
int Item_Slider_OverSlider(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_ListBox_GetIndexForMouse
==============
*/
int Item_ListBox_GetIndexForMouse(UIContextIndex_t contextIndex, itemDef_s *item, float x, float y)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_Listbox_Mouse_Column_Set
==============
*/
void Item_Listbox_Mouse_Column_Set(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_MouseLeave
==============
*/
void Item_MouseLeave(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_ShouldHandleKey
==============
*/
bool Item_ShouldHandleKey(UiContext *dc, itemDef_s *item, int key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_YesNo_IsActionKey
==============
*/
bool Item_YesNo_IsActionKey(int key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_YesNo_HandleKey
==============
*/
int Item_YesNo_HandleKey(UiContext *dc, itemDef_s *item, int key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_DvarEnum_CountSettings
==============
*/
int Item_DvarEnum_CountSettings(itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_Multi_FindDvarByValue
==============
*/
int Item_Multi_FindDvarByValue(itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_ProfileMulti_FindVarByValue
==============
*/
int Item_ProfileMulti_FindVarByValue(LocalClientNum_t localClientNum, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_Multi_Setting
==============
*/
const char *Item_Multi_Setting(itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Item_ProfileMulti_Setting
==============
*/
const char *Item_ProfileMulti_Setting(LocalClientNum_t localClientNum, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Item_DvarEnum_EnumIndex
==============
*/
int Item_DvarEnum_EnumIndex(itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_DvarEnum_Setting
==============
*/
const char *Item_DvarEnum_Setting(LocalClientNum_t localClientNum, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Item_List_NextEntryForKey
==============
*/
int Item_List_NextEntryForKey(int key, int current, int count)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_Multi_HandleKey
==============
*/
int Item_Multi_HandleKey(UiContext *dc, itemDef_s *item, int key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_ProfileMulti_HandleKey
==============
*/
int Item_ProfileMulti_HandleKey(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, int key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_DvarEnum_HandleKey
==============
*/
int Item_DvarEnum_HandleKey(UiContext *dc, itemDef_s *item, int key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_IsTextField
==============
*/
bool Item_IsTextField(const itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_TextField_BeginEdit
==============
*/
void Item_TextField_BeginEdit(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_TextField_EnsureCursorVisible
==============
*/
void Item_TextField_EnsureCursorVisible(UIContextIndex_t contextIndex, itemDef_s *item, const char *text)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scroll_Slider_SetThumbPos
==============
*/
void Scroll_Slider_SetThumbPos(UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scroll_Slider_ThumbFunc
==============
*/
void Scroll_Slider_ThumbFunc(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_Slider_HandleKey
==============
*/
int Item_Slider_HandleKey(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Menus_PrintAllLoadedMenus
==============
*/
void Menus_PrintAllLoadedMenus(UiContext *dc)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Display_VisibleMenuCount
==============
*/
int Display_VisibleMenuCount(UiContext *dc)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_CorrectedTextRect
==============
*/
rectDef_s *Item_CorrectedTextRect(UIContextIndex_t contextIndex, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Menu_ItemsAreAnimating
==============
*/
bool Menu_ItemsAreAnimating(LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_GetFont
==============
*/
Font_s *Item_GetFont(UIContextIndex_t contextIndex, const itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Item_SetTextExtents
==============
*/
void Item_SetTextExtents(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_TextColor
==============
*/
void Item_TextColor(UiContext *dc, itemDef_s *item, vec4_t *newColor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_PickWordWrapLineWidth
==============
*/
int UI_PickWordWrapLineWidth(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
_DrawWrappedText
==============
*/
void DrawWrappedText(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
_DrawWrappedTextScissored
==============
*/
void DrawWrappedTextScissored(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawWrappedText
==============
*/
void UI_DrawWrappedText(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawWrappedTextScissored
==============
*/
void UI_DrawWrappedTextScissored(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_Text_AutoWrapped_Paint
==============
*/
void Item_Text_AutoWrapped_Paint(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetPlatformCommand
==============
*/
void GetPlatformCommand(LocalClientNum_t localClientNum, const char *command, const char **consoleCommand)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_GetKeyBindingLocalizedString
==============
*/
/*int UI_GetKeyBindingLocalizedString@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
Item_Slider_Paint
==============
*/
void Item_Slider_Paint(const LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Display_KeyBindPending
==============
*/
int Display_KeyBindPending()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_Bind_IsActionKey
==============
*/
bool Item_Bind_IsActionKey(UiContext *dc, itemDef_s *item, int key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_Bind_HandleKey
==============
*/
int Item_Bind_HandleKey(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_GetTextAlignAdj
==============
*/
float Item_GetTextAlignAdj(const int alignment, float width, float textWidth)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_ListBox_PaintTextElem
==============
*/
void Item_ListBox_PaintTextElem(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_ListBox_PaintBackground
==============
*/
void Item_ListBox_PaintBackground(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_ListBox_PaintHighlight
==============
*/
void Item_ListBox_PaintHighlight(const UIContextIndex_t contextIndex, itemDef_s *item, float x, float y)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_ListBox_PaintItemIndicators
==============
*/
void Item_ListBox_PaintItemIndicators(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_GameMsgWindow_Paint
==============
*/
void Item_GameMsgWindow_Paint(const LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_GetFocused
==============
*/
menuDef_t *Menu_GetFocused(UiContext *dc)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Menus_AnyFullScreenVisible
==============
*/
int Menus_AnyFullScreenVisible(UiContext *dc)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Menu_IsVisible
==============
*/
/*char Menu_IsVisible@<al>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
UI_SetupTextShaderParams
==============
*/
void UI_SetupTextShaderParams(Font_s *font, textDef_s *textDefPtr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_SetSystemCursorPos
==============
*/
void UI_SetSystemCursorPos(UiContext *dc, float x, float y)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_OverActiveItem
==============
*/
int Menu_OverActiveItem(UIContextIndex_t contextIndex, menuDef_t *menu, float x, float y)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TRACK_ui_shared
==============
*/
void TRACK_ui_shared()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_ClearLocalUIVisibilityBits
==============
*/
void UI_ClearLocalUIVisibilityBits(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_SetLocalUIVisbilityBit
==============
*/
void UI_SetLocalUIVisbilityBit(LocalClientNum_t localClientNum, int bitShift, int value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menus_ActiveMenuAllowSignin
==============
*/
bool Menus_ActiveMenuAllowSignin(UiContext *dc)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Menu_DoesMenuOrParentsHaveControlFlag
==============
*/
char Menu_DoesMenuOrParentsHaveControlFlag(UiContext *dc, menuDef_t *menu, int controlFlag)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Menu_GetSpecifiedControlFlagFromStack
==============
*/
int Menu_GetSpecifiedControlFlagFromStack(UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Phys_ReEvalPriority
==============
*/
void Phys_ReEvalPriority()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_SetUIVisibilityBit
==============
*/
void Script_SetUIVisibilityBit(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_RunSingleEventScript
==============
*/
void Item_RunSingleEventScript(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_RunEventScript
==============
*/
void Item_RunEventScript(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UIAnimation_RunEventScript
==============
*/
void UIAnimation_RunEventScript(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_RefreshFeederSelection_f
==============
*/
void UI_RefreshFeederSelection_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_PlaySound_f
==============
*/
void UI_PlaySound_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_ListBox_MaxScroll
==============
*/
int Item_ListBox_MaxScroll(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_ListBox_ThumbPosition
==============
*/
float Item_ListBox_ThumbPosition(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_ListBox_ThumbDrawPosition
==============
*/
float Item_ListBox_ThumbDrawPosition(const LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_ListBox_OverLB
==============
*/
int Item_ListBox_OverLB(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_ListBox_SetCursorPos
==============
*/
void Item_ListBox_SetCursorPos(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_ListBox_Page
==============
*/
void Item_ListBox_Page(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_ListBox_Scroll
==============
*/
void Item_ListBox_Scroll(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_Action
==============
*/
void Item_Action(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_CheckOnKey
==============
*/
int Menu_CheckOnKey(UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_Text_Paint
==============
*/
void Item_Text_Paint(const LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_TextField_Paint
==============
*/
void Item_TextField_Paint(const LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_YesNo_Paint
==============
*/
void Item_YesNo_Paint(const LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_GetSticksTranslatedString
==============
*/
char UI_GetSticksTranslatedString(LocalClientNum_t localClientNum, const char *command, char *keys)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_Bind_Paint
==============
*/
void Item_Bind_Paint(const LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_ListBox_Paint
==============
*/
/*void Item_ListBox_Paint(float a1@<esi>, LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Item_OwnerDraw_Paint
==============
*/
void Item_OwnerDraw_Paint(const LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_RunFocusScript
==============
*/
void Menu_RunFocusScript(UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_RunLeaveFocusScript
==============
*/
void Menu_RunLeaveFocusScript(UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_ClearFocus
==============
*/
itemDef_s *Menu_ClearFocus(LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Item_UpdateAnimation
==============
*/
void Item_UpdateAnimation(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_AnimateToState
==============
*/
void Item_AnimateToState(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_AnimateItemInternal
==============
*/
void UI_AnimateItemInternal(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_AnimateItem
==============
*/
void UI_AnimateItem(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_AnimateItemSysTime
==============
*/
void UI_AnimateItemSysTime(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_LoseFocusDueToOpen
==============
*/
void Menu_LoseFocusDueToOpen(const LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_CallOnFocusDueToOpen
==============
*/
void Menu_CallOnFocusDueToOpen(const LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_GainFocusDueToClose
==============
*/
void Menu_GainFocusDueToClose(const LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_RunCloseScript
==============
*/
void Menu_RunCloseScript(UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menus_CompleteItemAnimations
==============
*/
void Menus_CompleteItemAnimations(const LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menus_Close
==============
*/
void Menus_Close(const LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menus_CloseByName
==============
*/
void Menus_CloseByName(const LocalClientNum_t localClientNum, UiContext *dc, const char *p)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menus_CloseAll
==============
*/
void Menus_CloseAll(const LocalClientNum_t localClientNum, UiContext *dc)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menus_CloseAllBehindMain
==============
*/
void Menus_CloseAllBehindMain(const LocalClientNum_t localClientNum, UiContext *dc)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menus_CloseFromMenuToTopOfStack
==============
*/
void Menus_CloseFromMenuToTopOfStack(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RemoveMenuFromBlurStack
==============
*/
bool RemoveMenuFromBlurStack(const LocalClientNum_t localClientNum, UiContext *dc, const char *menuName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Script_ActivateBlur
==============
*/
void Script_ActivateBlur(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_DeactivateBlur
==============
*/
void Script_DeactivateBlur(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetBlurFocus
==============
*/
int GetBlurFocus(const LocalClientNum_t localClientNum, UiContext *dc)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Script_Close
==============
*/
void Script_Close(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_CloseImmediate
==============
*/
void Script_CloseImmediate(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_InGameClose
==============
*/
void Script_InGameClose(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ChangeState
==============
*/
void Script_ChangeState(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ExecKeyHandler
==============
*/
void Script_ExecKeyHandler(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_FeederBottom
==============
*/
void Script_FeederBottom(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_CloseMenu_f
==============
*/
void UI_CloseMenu_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_CloseMenuImmediate_f
==============
*/
void UI_CloseMenuImmediate_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_MoveFeeder_f
==============
*/
void UI_MoveFeeder_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_SetFocus
==============
*/
int Item_SetFocus(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, float x, float y)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_ListBox_ModalSelection
==============
*/
void Item_ListBox_ModalSelection(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_ListBox_MouseEnter
==============
*/
void Item_ListBox_MouseEnter(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_MouseEnter
==============
*/
void Item_MouseEnter(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, float x, float y)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_ListBox_HandleKey
==============
*/
int Item_ListBox_HandleKey(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scroll_ListBox_AutoFunc
==============
*/
void Scroll_ListBox_AutoFunc(const LocalClientNum_t localClientNum, UiContext *dc, void *p)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scroll_ListBox_ThumbFunc
==============
*/
void Scroll_ListBox_ThumbFunc(const LocalClientNum_t localClientNum, UiContext *dc, void *p)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_StartCapture
==============
*/
void Item_StartCapture(const LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, int key)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_HandleKey
==============
*/
int Item_HandleKey(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, int key, int down)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Menu_SetPrevCursorItem
==============
*/
itemDef_s *Menu_SetPrevCursorItem(LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Menu_SetNextCursorItem
==============
*/
itemDef_s *Menu_SetNextCursorItem(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Menu_HandleMouseMove
==============
*/
/*int Menu_HandleMouseMove@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
Menu_PerformTransitionEffects
==============
*/
void Menu_PerformTransitionEffects(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Display_MouseMove
==============
*/
/*int Display_MouseMove@<eax>(menuDef_t *a1@<edi>, LocalClientNum_t localClientNum, UiContext *dc)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
UI_AddMenuList
==============
*/
void UI_AddMenuList(const LocalClientNum_t localClientNum, UiContext *dc, MenuList *menuList, int close)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menus_SetFocusToItem
==============
*/
void Menus_SetFocusToItem(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_FocusFirstSelectableItem
==============
*/
itemDef_s *Menu_FocusFirstSelectableItem(LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Script_FocusFirstInMenu
==============
*/
void Script_FocusFirstInMenu(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_SetFocus
==============
*/
void Script_SetFocus(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_SetFocusByDvar
==============
*/
void Script_SetFocusByDvar(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_FocusItem_f
==============
*/
void UI_FocusItem_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_TextField_HandleKey
==============
*/
int Item_TextField_HandleKey(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, int key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Menus_SetupOpenMenu
==============
*/
void Menus_SetupOpenMenu(LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menus_HandleOOBClick
==============
*/
void Menus_HandleOOBClick(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_HandleKey
==============
*/
void Menu_HandleKey(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_Paint
==============
*/
void Item_Paint(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_Paint
==============
*/
/*char Menu_Paint@<al>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
Script_ExecKeyPress
==============
*/
void Script_ExecKeyPress(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menus_Open
==============
*/
void Menus_Open(LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menus_OpenByName
==============
*/
int Menus_OpenByName(LocalClientNum_t localClientNum, UiContext *dc, const char *p)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Menus_OpenImmediateByName
==============
*/
int Menus_OpenImmediateByName(LocalClientNum_t localClientNum, UiContext *dc, const char *p)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Script_Open
==============
*/
void Script_Open(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_OpenImmediate
==============
*/
void Script_OpenImmediate(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_InGameOpen
==============
*/
void Script_InGameOpen(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_OpenMenu_f
==============
*/
void UI_OpenMenu_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_OpenMenuImmediate_f
==============
*/
void UI_OpenMenuImmediate_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_RegisterCmds
==============
*/
void UI_RegisterCmds()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_PaintAll_AppendToVisibleList
==============
*/
void Menu_PaintAll_AppendToVisibleList(char *stringBegin, unsigned int stringSize, const char *stringToAppend)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_PaintAll
==============
*/
void Menu_PaintAll(LocalClientNum_t localClientNum, UiContext *dc)
{
	UNIMPLEMENTED(__FUNCTION__);
}

