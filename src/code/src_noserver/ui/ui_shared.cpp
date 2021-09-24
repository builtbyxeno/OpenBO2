#include "types.h"
#include "ui_public.h"

/*
==============
MenuNameHash_t::MenuNameHash_t
==============
*/
/*void MenuNameHash_t::MenuNameHash_t(MenuNameHash_t *notthis, const char *s)
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
void Window_Paint(UiContext *dc, windowDef_t *w, float fadeAmount, float fadeInAmount, float fadeClamp, float fadeCycle, int itemType, itemDef_s *item)
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
itemDef_s *Menu_FindFirstFocusableItemByName(const LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu, const char *p)
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
void Item_LerpAnimationParameters(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, float lerpValue)
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
void Menu_ShowItemByName(const char *a1, menuDef_t *a2, UIContextIndex_t contextIndex, menuDef_t *menu, const char *p, int bShow)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_FadeItemByName
==============
*/
void Menu_FadeItemByName(const char *a1, menuDef_t *a2, UIContextIndex_t contextIndex, menuDef_t *menu, const char *p, int fadeOut)
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
void Script_SetDvarStringUsingTable(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
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
void Script_AddTextWrapper(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, itemDef_s *__formal, const char *text)
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
void Script_ConditionalExecHandler(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args, bool (*shouldExec)(const char *, const char *), void (*textCallback)(LocalClientNum_t, ControllerIndex_t, itemDef_s *, const char *))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ConditionalResponseHandler
==============
*/
void Script_ConditionalResponseHandler(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args, bool (*shouldRespond)(const char *, const char *))
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
void __cdecl Script_ExecOnDvarStringValue(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ExecOnDvarIntValue
==============
*/
void __cdecl Script_ExecOnDvarIntValue(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ExecOnDvarFloatValue
==============
*/
void __cdecl Script_ExecOnDvarFloatValue(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ExecNowOnDvarStringValue
==============
*/
void __cdecl Script_ExecNowOnDvarStringValue(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ExecNowOnDvarIntValue
==============
*/
void __cdecl Script_ExecNowOnDvarIntValue(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ExecNowOnDvarFloatValue
==============
*/
void __cdecl Script_ExecNowOnDvarFloatValue(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_RespondOnDvarStringValue
==============
*/
void Script_RespondOnDvarStringValue(UiContext *a1, LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_RespondOnDvarIntValue
==============
*/
void Script_RespondOnDvarIntValue(UiContext *a1, LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_RespondOnDvarFloatValue
==============
*/
void Script_RespondOnDvarFloatValue(UiContext *a1, LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
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
void Script_SetLocalVarFloat(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_SetLocalVarString
==============
*/
void Script_SetLocalVarString(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
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
void Script_SessionMode_SetOnlineGame(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_SessionMode_SetSystemLink
==============
*/
void Script_SessionMode_SetSystemLink(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_SessionMode_SetPrivate
==============
*/
void Script_SessionMode_SetPrivate(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_GameMode_SetMode
==============
*/
void Script_GameMode_SetMode(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_GameMode_ResetModes
==============
*/
void __cdecl Script_GameMode_ResetModes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_SessionMode_ResetModes
==============
*/
void __cdecl Script_SessionMode_ResetModes()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_ScriptMenuResponse
==============
*/
void Script_ScriptMenuResponse(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
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
bool Item_IsConditionSatisfied(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, GenericEventScript *eventScript)
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
void __cdecl UI_FadeItem_f()
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
float Item_ListBox_GetMaxHeight(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_ListBox_Viewmax
==============
*/
int Item_ListBox_Viewmax(float localClientNum, char *a2, const LocalClientNum_t a3, UIContextIndex_t contextIndex, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

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
int Item_Slider_OverSlider(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, float x, float y)
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
void Item_Listbox_Mouse_Column_Set(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, int x, int y)
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
void Item_TextField_BeginEdit(LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item)
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
void Scroll_Slider_ThumbFunc(itemDef_s *a1, const LocalClientNum_t localClientNum, UiContext *dc, void *p)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_Slider_HandleKey
==============
*/
int Item_Slider_HandleKey(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, int key, int down)
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
void Item_SetTextExtents(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, const char *text)
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
int UI_PickWordWrapLineWidth(const char *text, int bufferSize, Font_s *font, float normalizedScale, int targetLineCount, int widthGuess, int widthLimit)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
_DrawWrappedText
==============
*/
void DrawWrappedText(LocalClientNum_t localClientNum, const ScreenPlacement *scrPlace, const char *text, const rectDef_s *rect, Font_s *font, float x, float y, float scale, const vec4_t *color, int style, int textAlignMode, rectDef_s *textRect, bool subtitle, const vec4_t *subtitleGlowColor, bool cinematic)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
_DrawWrappedTextScissored
==============
*/
void DrawWrappedTextScissored(LocalClientNum_t localClientNum, const ScreenPlacement *scrPlace, const char *text, const rectDef_s *rect, Font_s *font, float x, float y, float scale, const vec4_t *color, int style, int textAlignMode, rectDef_s *textRect, bool subtitle, const vec4_t *subtitleGlowColor, bool cinematic)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawWrappedText
==============
*/
void UI_DrawWrappedText(const vec4_t *a1, bool a2, LocalClientNum_t localClientNum, const ScreenPlacement *scrPlace, const char *text, const rectDef_s *rect, Font_s *font, float x, float y, float scale, const vec4_t *color, int style, int textAlignMode, rectDef_s *textRect)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawWrappedTextScissored
==============
*/
void UI_DrawWrappedTextScissored(const vec4_t *a1, bool a2, LocalClientNum_t localClientNum, const ScreenPlacement *scrPlace, const char *text, const rectDef_s *rect, Font_s *font, float x, float y, float scale, const vec4_t *color, int style, int textAlignMode, rectDef_s *textRect)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_Text_AutoWrapped_Paint
==============
*/
void Item_Text_AutoWrapped_Paint(LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, const char *text, const vec4_t *color, bool subtitle, const vec4_t *subtitleGlowColor, bool cinematic)
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
int UI_GetKeyBindingLocalizedString(const char *a1, const LocalClientNum_t localClientNum, const char *command, char *keys, int bindNum, bool presscmd, bool cap, bool limit, bool findGestures, bool anim, bool swapCommand)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

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
int Item_Bind_HandleKey(const LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, int key, int down)
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
void Item_ListBox_PaintTextElem(LocalClientNum_t localClientNum, const UIContextIndex_t contextIndex, itemDef_s *item, int row, int col, int maxChars, int halignment, int valignment, float x, float y, float w, float h, bool onFocus)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_ListBox_PaintBackground
==============
*/
void Item_ListBox_PaintBackground(const LocalClientNum_t localClientNum, const UIContextIndex_t contextIndex, itemDef_s *item, float x, float y, int row)
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
void Item_ListBox_PaintItemIndicators(LocalClientNum_t localClientNum, const UIContextIndex_t contextIndex, itemDef_s *item, int row, int col, int maxChars, int alignment, float x, float y, float w, float h)
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
char Menu_IsVisible(int a1, const LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

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
void Script_SetUIVisibilityBit(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_RunSingleEventScript
==============
*/
void Item_RunSingleEventScript(GenericEventScript *a1, LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, GenericEventScript *eventScript)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_RunEventScript
==============
*/
void Item_RunEventScript(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char *eventName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UIAnimation_RunEventScript
==============
*/
void UIAnimation_RunEventScript(GenericEventScript *a1, LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, animParamsDef_t *animState, const char *eventName)
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
int Item_ListBox_MaxScroll(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_ListBox_ThumbPosition
==============
*/
float Item_ListBox_ThumbPosition(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item)
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
int Item_ListBox_OverLB(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, float x, float y)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_ListBox_SetCursorPos
==============
*/
void Item_ListBox_SetCursorPos(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, int max, int viewmax, int newCursorPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_ListBox_Page
==============
*/
void Item_ListBox_Page(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, int max, int scrollmax, int viewmax, int delta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_ListBox_Scroll
==============
*/
void Item_ListBox_Scroll(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, int max, int scrollmax, int viewmax, int delta)
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
void __cdecl Item_ListBox_Paint(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}

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
void Item_UpdateAnimation(UIContextIndex_t a1, const LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_AnimateToState
==============
*/
void Item_AnimateToState(const LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, animParamsDef_t *state, int milliseconds, bool sysTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_AnimateItemInternal
==============
*/
void UI_AnimateItemInternal(const LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu, const char *itemName, const char *newStateName, int milliseconds, bool sysTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_AnimateItem
==============
*/
void __cdecl UI_AnimateItem(const LocalClientNum_t localClientNum, UiContext *dc, const char *menuName, const char *itemName, const char *newStateName, int milliseconds)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_AnimateItemSysTime
==============
*/
void __cdecl UI_AnimateItemSysTime(const LocalClientNum_t localClientNum, UiContext *dc, const char *menuName, const char *itemName, const char *newStateName, int milliseconds)
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
void Menus_CompleteItemAnimations(char *animDuration, const LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu)
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
void Menus_CloseFromMenuToTopOfStack(const LocalClientNum_t localClientNum, UiContext *dc, const char *menuName)
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
void __cdecl Script_ActivateBlur(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Script_DeactivateBlur
==============
*/
void __cdecl Script_DeactivateBlur(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
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
int Item_SetFocus(char *a1, LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, float x, float y)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Item_ListBox_ModalSelection
==============
*/
void Item_ListBox_ModalSelection(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, int x, int y)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Item_ListBox_MouseEnter
==============
*/
void Item_ListBox_MouseEnter(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, float x, float y)
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
int Item_ListBox_HandleKey(LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, int key, int down, int force)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scroll_ListBox_AutoFunc
==============
*/
void __cdecl Scroll_ListBox_AutoFunc(const LocalClientNum_t localClientNum, UiContext *dc, void *p)
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
itemDef_s *Menu_SetNextCursorItem(LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu, int usedTab)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Menu_HandleMouseMove
==============
*/
int Menu_HandleMouseMove(menuDef_t *a1, LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Menu_PerformTransitionEffects
==============
*/
void Menu_PerformTransitionEffects(double localClientNum, int a2, const LocalClientNum_t a3, UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Display_MouseMove
==============
*/
int Display_MouseMove(menuDef_t *a1, LocalClientNum_t localClientNum, UiContext *dc)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

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
void __cdecl Menus_SetFocusToItem(LocalClientNum_t localClientNum, UiContext *dc, const char *menuName, const char *itemName)
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
void Script_FocusFirstInMenu(UiContext *a1, LocalClientNum_t a2, LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item)
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
void Script_SetFocusByDvar(char *a1, LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
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
void Menus_SetupOpenMenu(int a1, LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menus_HandleOOBClick
==============
*/
void Menus_HandleOOBClick(const LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu, int key, int down)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_HandleKey
==============
*/
void Menu_HandleKey(UiContext *a1, int a2, menuDef_t *localClientNum, LocalClientNum_t dc, UiContext *menu, menuDef_t *key, int down, int a8)
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
char Menu_Paint(int a1, LocalClientNum_t localClientNum, UiContext *dc, ScreenPlacementStack *scrPlaceViewStack, menuDef_t *menu, int UI3DOverrideId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Script_ExecKeyPress
==============
*/
/*void Script_ExecKeyPress(int a1@<ebx>, LocalClientNum_t localClientNum, UiContext *dc, itemDef_s *item, const char **args)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Menus_Open
==============
*/
void __cdecl Menus_Open(LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu)
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

/*
==============
UI_GetForcedMenuScreen
==============
*/
int UI_GetForcedMenuScreen()
{
	return -1;
}

/*
==============
UI_GetMenuScreen
==============
*/
int UI_GetMenuScreen()
{
	int menu;

	menu = UI_GetForcedMenuScreen();
	if (menu >= UIMENU_NONE)
	{
		return menu;
	}

	return 1;
}

