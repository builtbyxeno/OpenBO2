#include "types.h"
#include "functions.h"

/*
==============
UI_UIContext_GetInfo
==============
*/
UiContext *UI_UIContext_GetInfo(UIContextIndex_t contextIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UI_GetInfo
==============
*/
UiContext *UI_GetInfo(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
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
void UI_DrawSides(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawTopBottom
==============
*/
void UI_DrawTopBottom(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawRect
==============
*/
void UI_DrawRect(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawHighlightRect
==============
*/
void UI_DrawHighlightRect(
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
void UI_DrawTextRotated(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawTextWithGlow
==============
*/
void UI_DrawTextWithGlow(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawTextNoSnap
==============
*/
void UI_DrawTextNoSnap(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawTextWithCursor
==============
*/
void UI_DrawTextWithCursor(
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
/*int Load_ScriptMenu@<eax>(int a1@<edx>, const char *a2@<ecx>, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

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
bool UI_GetOpenOrCloseMenuOnDvarArgs(
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
void UI_OpenMenuOnDvar(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_CloseMenuOnDvar
==============
*/
void UI_CloseMenuOnDvar(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_RunMenuScript
==============
*/
void UI_RunMenuScript(
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
void UI_ReplaceConversions(
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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
void UI_DrawLocalTalking(
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
void UI_DrawPartyStatus(
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
void UI_DrawScrollingTextLong(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawScrollingTextMOTD
==============
*/
void UI_DrawScrollingTextMOTD(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawControllerIcon
==============
*/
void UI_DrawControllerIcon(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_OwnerDraw
==============
*/
void UI_OwnerDraw(
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
bool UI_KeyEvent_CancelButtonPressed(
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
bool UI_KeyEvent_IsLocalClientInputAllowedForMenu(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UI_HandleLocalClientInput
==============
*/
char UI_HandleLocalClientInput(
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
void UI_UIContext_OpenToastPopup(
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
	UNIMPLEMENTED(__FUNCTION__);
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
void UI_OpenToastPopup(
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
void UI_DrawTextPadding(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawText
==============
*/
void UI_DrawText(
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
void UI_DrawKeyBindStatus(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawTalkerNum
==============
*/
void UI_DrawTalkerNum(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawReservedSlots
==============
*/
void UI_DrawReservedSlots(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawLoggedInUser
==============
*/
void UI_DrawLoggedInUser(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawLoggedInUserName
==============
*/
void UI_DrawLoggedInUserName(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_OwnerDrawText
==============
*/
void UI_OwnerDrawText(
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
void UI_DrawSessionAndGameModeLine(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawSessionAndGameModes
==============
*/
void UI_DrawSessionAndGameModes(LocalClientNum_t localClientNum, const UIContextIndex_t contextIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawGameModeHistory_DrawMode_HostedOrPlayed
==============
*/
void UI_DrawGameModeHistory_DrawMode_HostedOrPlayed(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UI_DrawGameModeHistory_DrawMode
==============
*/
void UI_DrawGameModeHistory_DrawMode(
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
const char *UI_GetPlaylistDescription(
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

