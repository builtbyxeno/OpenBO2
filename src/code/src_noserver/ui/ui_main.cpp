#include "types.h"
#include "vars.h"
#include <qcommon/qcommon_public.h>

UiContext uiInfoArray;

/*
==============
UI_UIContext_GetInfo
==============
*/
uiInfo_s* UI_UIContext_GetInfo(UIContextIndex_t contextIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_GetInfo
==============
*/
UiContext* UI_GetInfo(LocalClientNum_t localClientNum)
{
	return &uiInfoArray;
}

/*
==============
UI_UIContext_GetLocalVarsContext
==============
*/
UILocalVarContext *UI_UIContext_GetLocalVarsContext(UIContextIndex_t contextIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_GetMonthAbbrev
==============
*/
const char *UI_GetMonthAbbrev(int month)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
TRACK_ui_main
==============
*/
void TRACK_ui_main()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_RegisterDvars
==============
*/
void UI_RegisterDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_AssetCache
==============
*/
void UI_AssetCache()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetMenuBuffer_LoadObj
==============
*/
char *GetMenuBuffer_LoadObj(const char *filename)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GetMenuBuffer_FastFile
==============
*/
XModelPiece *GetMenuBuffer_FastFile(const char *filename)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_GetMenuBuffer
==============
*/
char *UI_GetMenuBuffer()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_GameModeHistory_AddMatchHistory
==============
*/
void UI_GameModeHistory_AddMatchHistory()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_GameModeHistory_Clear
==============
*/
void UI_GameModeHistory_Clear()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawSides
==============
*/
void UI_DrawSides(const ScreenPlacement *scrPlace, float x, float y, float w, float h, int horzAlign, int vertAlign, float size, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawTopBottom
==============
*/
void UI_DrawTopBottom(const ScreenPlacement *scrPlace, float x, float y, float w, float h, int horzAlign, int vertAlign, float size, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawRect
==============
*/
void UI_DrawRect(const ScreenPlacement *scrPlace, float x, float y, float width, float height, int horzAlign, int vertAlign, float size, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawHighlightRect
==============
*/
void UI_DrawHighlightRect(const ScreenPlacement *scrPlace, float x, float y, float w, float h, int horzAlign, int vertAlign, float size, const vec4_t *hiColor, const vec4_t *loColor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_TextWidth
==============
*/
int UI_TextWidth(LocalClientNum_t localClientNum, const char *text, int maxChars, Font_s *font, float scale)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_TextHeight
==============
*/
int UI_TextHeight(Font_s *font, float scale)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_DrawTextRotated
==============
*/
void UI_DrawTextRotated(const ScreenPlacement *scrPlace, const char *text, int maxChars, Font_s *font, float x, float y, int horzAlign, int vertAlign, float scale, const vec4_t *color, int style, float rotation)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawTextWithGlow
==============
*/
void UI_DrawTextWithGlow(const ScreenPlacement *scrPlace, const char *text, int maxChars, Font_s *font, float x, float y, int horzAlign, int vertAlign, float scale, const vec4_t *color, int style, const vec4_t *glowColor, bool subtitle, bool cinematic)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawTextNoSnap
==============
*/
void UI_DrawTextNoSnap(const ScreenPlacement *scrPlace, const char *text, int maxChars, Font_s *font, float x, float y, int horzAlign, int vertAlign, float scale, const vec4_t *color, int style)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawTextWithCursor
==============
*/
void UI_DrawTextWithCursor(const ScreenPlacement *scrPlace, const char *text, int maxChars, Font_s *font, float x, float y, int horzAlign, int vertAlign, float scale, const vec4_t *color, int style, int cursorPos, char cursor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_GetFontHandleDefault
==============
*/
Font_s *UI_GetFontHandleDefault(float scale)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_GetFontHandle
==============
*/
Font_s *UI_GetFontHandle(const ScreenPlacement *scrPlace, int fontEnum, float scale)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_UpdateTime
==============
*/
void UI_UpdateTime(LocalClientNum_t localClientNum, int realtime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_ShouldDrawBuildNumber
==============
*/
bool UI_ShouldDrawBuildNumber(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_Shutdown
==============
*/
void UI_Shutdown(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_ScriptMenuInternal
==============
*/
MenuList *Load_ScriptMenuInternal(const char *pszMenu, int imageTrack)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Load_ScriptMenu
==============
*/
int Load_ScriptMenu(int a1, const char *a2, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_VerifyLanguage
==============
*/
void UI_VerifyLanguage()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_GetOpenOrCloseMenuOnDvarArgs
==============
*/
bool UI_GetOpenOrCloseMenuOnDvarArgs(const char **args, const char *cmd, char *dvarName, int dvarNameLen, char *testValue, int testValueLen, char *menuName, int menuNameLen)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_DvarValueTest
==============
*/
bool UI_DvarValueTest(const char *cmd, const char *dvarName, const char *testValue, bool wantMatch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_OpenMenuOnDvar
==============
*/
void UI_OpenMenuOnDvar(LocalClientNum_t localClientNum, uiInfo_s *uiInfo, const char *cmd, const char *menuName, const char *dvarName, const char *testValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_CloseMenuOnDvar
==============
*/
void UI_CloseMenuOnDvar(const LocalClientNum_t localClientNum, uiInfo_s *uiInfo, const char *cmd, const char *menuName, const char *dvarName, const char *testValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_RunMenuScript
==============
*/
void UI_RunMenuScript(LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, const char **args, const char *actualScript)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_Pause
==============
*/
void UI_Pause(LocalClientNum_t localClientNum, int b)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_UpdateMouseScreenPosition
==============
*/
void UI_UpdateMouseScreenPosition(LocalClientNum_t localClientNum, int x, int y)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_MouseEvent
==============
*/
void UI_MouseEvent(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_GetActiveMenu
==============
*/
int UI_GetActiveMenu(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_IsFullscreen
==============
*/
int UI_IsFullscreen(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_GetBlurRadius
==============
*/
double UI_GetBlurRadius(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_SafeTranslateString
==============
*/
const char *UI_SafeTranslateString(const char *reference)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_FormatStringWithCommas
==============
*/
void UI_FormatStringWithCommas(char *outputString, int stringLength, unsigned __int64 value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_FilterStringForButtonAnimation
==============
*/
void UI_FilterStringForButtonAnimation(char *str, unsigned int strMaxSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_ReplaceConversions
==============
*/
void UI_ReplaceConversions(const char *sourceString, ConversionArguments *arguments, char *outputString, int outputStringSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_CloseFocusedMenu
==============
*/
void UI_CloseFocusedMenu(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Menu_IsMenuOpenAndVisible
==============
*/
bool Menu_IsMenuOpenAndVisible(const LocalClientNum_t localClientNum, const char *menuName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_ClosePopupScriptMenu
==============
*/
void UI_ClosePopupScriptMenu(LocalClientNum_t localClientNum, bool allowResponse)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_AllowScriptMenuResponse
==============
*/
bool UI_AllowScriptMenuResponse(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_CloseInGameMenu
==============
*/
void UI_CloseInGameMenu(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CheckCurrentChar
==============
*/
bool CheckCurrentChar(char charToCheck, const char *testChars)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_CheckCODClanTag
==============
*/
bool __cdecl UI_CheckCODClanTag(const char *clanTag)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_CheckClanTagAllowed
==============
*/
bool UI_CheckClanTagAllowed(ControllerIndex_t controllerIndex, const char *clanTag)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_SetClanName
==============
*/
void UI_SetClanName(ControllerIndex_t localControllerIndex, const char *clanName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_SetClanNameCmd
==============
*/
void UI_SetClanNameCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_CheckClanName
==============
*/
void UI_CheckClanName()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_CheckClanNameCmd
==============
*/
void UI_CheckClanNameCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_OwnerDrawWidth
==============
*/
int UI_OwnerDrawWidth(LocalClientNum_t localClientNum, int ownerDraw, Font_s *font, float scale)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_DrawLocalTalking
==============
*/
void UI_DrawLocalTalking(LocalClientNum_t localClientNum, SessionData *session, UIContextIndex_t contextIndex, const rectDef_s *rect, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_GetTalkerClientNum
==============
*/
int UI_GetTalkerClientNum(LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, const int num)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_DrawPartyStatus
==============
*/
void UI_DrawPartyStatus(LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, rectDef_s *rect, Font_s *font, vec4_t *color, float textScale, int style, float text_x, float text_y, int textAlignMode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetXpLockDescription
==============
*/
char *GetXpLockDescription(const LocalClientNum_t localClientNum, const int playlistId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_DrawScrollingTextLong
==============
*/
void UI_DrawScrollingTextLong(const LocalClientNum_t localClientNum, const UIContextIndex_t contextIndex, rectDef_s *rect, Font_s *font, float scale, vec4_t *color, int style, int textAlignMode, const char *text)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawScrollingTextMOTD
==============
*/
void UI_DrawScrollingTextMOTD(const LocalClientNum_t localClientNum, const UIContextIndex_t contextIndex, rectDef_s *rect, Font_s *font, float scale, vec4_t *color, int style, int textAlignMode, const char *text)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawControllerIcon
==============
*/
void UI_DrawControllerIcon(const LocalClientNum_t localClientNum, const UIContextIndex_t contextIndex, const rectDef_s *rect, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_OwnerDraw
==============
*/
void UI_OwnerDraw(double localClientNum, LocalClientNum_t a2, itemDef_s *item, float x, float y, float w, float h, int horzAlign, int vertAlign, int ownerDraw, int ownerDrawFlags, vec4_t *color, Material *material, rectDef_s parentRect)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_InitUIInfos
==============
*/
void UI_InitUIInfos()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_InitOnceForAllClients
==============
*/
void UI_InitOnceForAllClients()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_Init
==============
*/
void UI_Init(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_KeyEvent_CancelButtonPressed
==============
*/
bool UI_KeyEvent_CancelButtonPressed(LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu, int key, int down)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_MenuInputAllowedForLocalClientNum
==============
*/
bool UI_MenuInputAllowedForLocalClientNum(LocalClientNum_t localClientNum, UiContext *dc, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_KeyEvent_IsLocalClientInputAllowedForMenu
==============
*/
bool UI_KeyEvent_IsLocalClientInputAllowedForMenu(LocalClientNum_t localClientNum, uiInfo_s *uiInfo, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_HandleLocalClientInput
==============
*/
char UI_HandleLocalClientInput(LocalClientNum_t localClientNum, int key, int down, uiInfo_s *uiInfo, menuDef_t *menu)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_CloseAll
==============
*/
void UI_CloseAll(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_UIContext_OpenToastPopup
==============
*/
void UI_UIContext_OpenToastPopup(UIContextIndex_t contextIndex, const char *toastPopupIconName, const char *toastPopupTitle, const char *toastPopupDesc, int toastPopupDuration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_OpenErrorPopup
==============
*/
void UI_OpenErrorPopup()
{
	const char* String;
	String = Dvar_GetString(ui_errorMessage);
	if (strlen(String))
		I_stricmp(String, ";");
}

/*
==============
UI_OpenMenu
==============
*/
void UI_OpenMenu(LocalClientNum_t localClientNum, const char *menuName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_CloseMenu
==============
*/
void UI_CloseMenu(LocalClientNum_t localClientNum, const char *menuName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_CloseFromMenuToTopOfStack
==============
*/
void UI_CloseFromMenuToTopOfStack(LocalClientNum_t localClientNum, const char *menuName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_OpenToastPopup
==============
*/
void UI_OpenToastPopup(LocalClientNum_t localClientNum, const char *toastPopupIconName, const char *toastPopupTitle, const char *toastPopupDesc, int toastPopupDuration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_LoadIngameMenus
==============
*/
void UI_LoadIngameMenus(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_ToUpper
==============
*/
char *UI_ToUpper(const char *sourceString)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_KeysBypassMenu
==============
*/
bool UI_KeysBypassMenu(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_DrawTextPadding
==============
*/
void UI_DrawTextPadding(LocalClientNum_t localClientNum, const ScreenPlacement *scrPlace, const char *text, int maxChars, Font_s *font, float x, float y, int horzAlign, int vertAlign, float scale, const vec4_t *color, int style, float padding)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawText
==============
*/
void UI_DrawText(const ScreenPlacement *scrPlace, const char *text, int maxChars, Font_s *font, float x, float y, int horzAlign, int vertAlign, float scale, const vec4_t *color, int style, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawMouseCursor
==============
*/
void UI_DrawMouseCursor(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_GetMapDisplayName
==============
*/
const char *UI_GetMapDisplayName(const char *pszMap)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_GetMapDisplayNameFromPartialLoadNameMatch
==============
*/
const char *UI_GetMapDisplayNameFromPartialLoadNameMatch(const char *mapName, int *mapLoadNameLen)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_GetGameTypeDisplayName
==============
*/
const char *UI_GetGameTypeDisplayName(const char *pszGameType, const char *pszMap)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_ShowAcceptInviteWarning
==============
*/
void UI_ShowAcceptInviteWarning(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_ReplaceConversionStrings
==============
*/
char *UI_ReplaceConversionStrings(const char *sourceString, int numStrings, const char **replaceStrings)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_ReplaceConversionInts
==============
*/
char *UI_ReplaceConversionInts(const char *sourceString, int numInts, int *replaceInts)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_DrawKeyBindStatus
==============
*/
void UI_DrawKeyBindStatus(UIContextIndex_t contextIndex, rectDef_s *rect, Font_s *font, float scale, vec4_t *color, int textStyle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawTalkerNum
==============
*/
void UI_DrawTalkerNum(LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, const int num, rectDef_s *rect, Font_s *font, vec4_t *color, float textScale, int style)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawReservedSlots
==============
*/
void UI_DrawReservedSlots(const UIContextIndex_t contextIndex, rectDef_s *rect, Font_s *font, vec4_t *color, float textScale, int style)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawLoggedInUser
==============
*/
void UI_DrawLoggedInUser(LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, rectDef_s *rect, Font_s *font, float scale, vec4_t *color, int textStyle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawLoggedInUserName
==============
*/
void UI_DrawLoggedInUserName(LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, rectDef_s *rect, Font_s *font, float scale, vec4_t *color, int textStyle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_OwnerDrawText
==============
*/
void UI_OwnerDrawText(const LocalClientNum_t localClientNum, UIContextIndex_t contextIndex, itemDef_s *item, float x, float y, float w, float h, int horzAlign, int vertAlign, float text_x, float text_y, int ownerDraw, int ownerDrawFlags, int align, Font_s *font, float scale, vec4_t *color, Material *material, int textStyle, rectDef_s parentRect, int textAlignMode, const char *text)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_KeyEvent
==============
*/
void UI_KeyEvent(LocalClientNum_t localClientNum, int key, int down)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawBuildNumber
==============
*/
void UI_DrawBuildNumber(LocalClientNum_t localClientNum, const UIContextIndex_t contextIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawSessionAndGameModeLine
==============
*/
void UI_DrawSessionAndGameModeLine(LocalClientNum_t localClientNum, const UIContextIndex_t contextIndex, const char *text, Font_s *fh, vec2_t *buildLocation, float buildSize, bool error)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawSessionAndGameModes
==============
*/
void __cdecl UI_DrawSessionAndGameModes(LocalClientNum_t localClientNum, const UIContextIndex_t contextIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawGameModeHistory_DrawMode_HostedOrPlayed
==============
*/
void UI_DrawGameModeHistory_DrawMode_HostedOrPlayed(const LocalClientNum_t localClientNum, const char *gamemode, const char *hostedOrPlayed, vec2_t *buildLocation, float buildSize, Font_s *fh)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawGameModeHistory_DrawMode
==============
*/
void UI_DrawGameModeHistory_DrawMode(const LocalClientNum_t localClientNum, const char *gamemode, vec2_t *buildLocation, float buildSize, Font_s *fh)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawGameModeHistory
==============
*/
void UI_DrawGameModeHistory(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_Refresh
==============
*/
void UI_Refresh(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_ReplaceConversionString
==============
*/
char *UI_ReplaceConversionString(const char *sourceString, const char *replaceString)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_ReplaceConversionInt
==============
*/
char *UI_ReplaceConversionInt(const char *sourceString, int replaceInt)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GetPLevelLockDescription
==============
*/
const char *GetPLevelLockDescription(const LocalClientNum_t localClientNum, const int playlistId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_GetPlaylistDescription
==============
*/
const char *UI_GetPlaylistDescription(const LocalClientNum_t localClientNum, int playlistId, PlaylistLockState lockState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_SecondsAsTimeDisplay
==============
*/
void UI_SecondsAsTimeDisplay(int seconds, char *output, int maxChars)
{
	UNIMPLEMENTED(__FUNCTION__);
}

