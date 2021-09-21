#include "types.h"
#include "functions.h"

/*
==============
SetupChatField
==============
*/
void SetupChatField(const LocalClientNum_t localClientNum, int teamChat, int widthInPixels)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_ChatModePublic_f
==============
*/
void Con_ChatModePublic_f(LocalClientNum_t a1, int a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_ChatModeTeam_f
==============
*/
void Con_ChatModeTeam_f(LocalClientNum_t a1, int a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_GetTextCopy
==============
*/
void Con_GetTextCopy(char *text, int maxSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_ResetMessageWindowTimes
==============
*/
void Con_ResetMessageWindowTimes(MessageWindow *msgwnd, int serverTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_TimeJumped
==============
*/
void Con_TimeJumped(int a1, MessageWindow *a2, LocalClientNum_t localClientNum, int serverTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_NudgeMessageWindowTimes
==============
*/
void Con_NudgeMessageWindowTimes(MessageWindow *msgwnd, int serverTimeNudge, int serverTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_TimeNudged
==============
*/
void __cdecl Con_TimeNudged(LocalClientNum_t localClientNum, int serverTimeNudge)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_ClearMessageWindow
==============
*/
void Con_ClearMessageWindow(MessageWindow *msgwnd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_ClearNotify
==============
*/
void Con_ClearNotify(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_CheckResize
==============
*/
void Con_CheckResize()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_InitMessageWindow
==============
*/
void Con_InitMessageWindow(MessageWindow *msgwnd, Message *messages, MessageLine *lines, char *text, int lineCount, int padding, int textPoolSize, int scrollTime, int fadeIn, int fadeOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_Clear_f
==============
*/
void Con_Clear_f(MessageWindow *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_InitClientAssets
==============
*/
void __cdecl Con_InitClientAssets()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_GetDefaultMsgDuration
==============
*/
int Con_GetDefaultMsgDuration(print_msg_dest_t dest)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Con_UpdateMessage
==============
*/
void Con_UpdateMessage(LocalClientNum_t localClientNum, MessageWindow *msgwnd, int duration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_FreeFirstMessageWindowLine
==============
*/
void Con_FreeFirstMessageWindowLine(MessageWindow *msgwnd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_NeedToFreeMessageWindowLine
==============
*/
bool Con_NeedToFreeMessageWindowLine(MessageWindow *msgwnd, int charCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Con_CopyCurrentConsoleLineText
==============
*/
void Con_CopyCurrentConsoleLineText(MessageWindow *msgwnd, MessageLine *msgLine)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LatestActiveTypewrittenLineIdx
==============
*/
int LatestActiveTypewrittenLineIdx(MessageWindow *msgwnd)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PrintableCharsCount
==============
*/
int PrintableCharsCount(const MessageWindow *msgwnd, MessageLine *line)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PrintTimeTotal
==============
*/
int PrintTimeTotal(MessageWindow *msgwnd, MessageLine *line)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetNextValidPrintTimeForLine
==============
*/
int GetNextValidPrintTimeForLine(LocalClientNum_t localClientNum, MessageWindow *msgwnd, int flags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Con_UpdateMessageWindowLine
==============
*/
void Con_UpdateMessageWindowLine(LocalClientNum_t localClientNum, MessageWindow *msgwnd, int linefeed, int flags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_GetDestWindow
==============
*/
MessageWindow *Con_GetDestWindow(LocalClientNum_t localClientNum, print_msg_dest_t dest)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Con_UpdateNotifyMessage
==============
*/
void Con_UpdateNotifyMessage(LocalClientNum_t localClientNum, int channel, int duration, int flags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_UpdateNotifyLine
==============
*/
void Con_UpdateNotifyLine(LocalClientNum_t localClientNum, int channel, bool lineFeed, int flags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_InitMessageBuffer
==============
*/
void __cdecl Con_InitMessageBuffer()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ConsolePrint_AddLine
==============
*/
char __cdecl CL_ConsolePrint_AddLine(LocalClientNum_t localClientNum, int channel, const char *txt, int duration, int pixelWidth, char color, int flags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_AddMessageChar
==============
*/
int CL_AddMessageChar(char *msg, unsigned int msgLen, unsigned int msgMaxLen, char c)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_AddMessageString
==============
*/
int CL_AddMessageString(char *msg, unsigned int msgLen, unsigned int msgMaxLen, const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_AddMessageIcon
==============
*/
int CL_AddMessageIcon(char *msg, unsigned int msgLen, unsigned int msgMaxLen, Material *iconShader, float iconWidth, float iconHeight, bool horzFlipIcon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Con_AutoCompleteFromList
==============
*/
void Con_AutoCompleteFromList(const char **strings, unsigned int stringCount, const char *prefix, char *completed, unsigned int sizeofCompleted)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_TokenizeInput
==============
*/
const GfxViewParms *Con_TokenizeInput()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Con_AnySpaceAfterCommand
==============
*/
char Con_AnySpaceAfterCommand()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ConDrawInput_Text
==============
*/
void ConDrawInput_Text(const char *str, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ConDrawInput_TextLimitChars
==============
*/
void ConDrawInput_TextLimitChars(const char *str, int maxChars, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ConDrawInput_TextAndOver
==============
*/
void ConDrawInput_TextAndOver(const vec4_t *a1, const char *a2, LocalClientNum_t localClientNum, const char *str)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ConDraw_Box
==============
*/
void ConDraw_Box(float x, float y, float w, float h, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ConDrawInput_Box
==============
*/
void ConDrawInput_Box(int lines, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_GetAutoCompleteColorCodedStringDiscontiguous
==============
*/
int Con_GetAutoCompleteColorCodedStringDiscontiguous(const char *query, const char *matchToText, int matchTextLen, char *colorCoded)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Con_GetAutoCompleteColorCodedStringContiguous
==============
*/
int Con_GetAutoCompleteColorCodedStringContiguous(const char *query, const char *matchToText, int matchTextLen, char *colorCoded)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Con_IsAutoCompleteMatch
==============
*/
bool Con_IsAutoCompleteMatch(const char *query, const char *matchToText, int matchTextLen)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ConDrawInput_IncrMatchCounter
==============
*/
void ConDrawInput_IncrMatchCounter(const char *str)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ConDrawInput_DvarMatch
==============
*/
void __cdecl ConDrawInput_DvarMatch(const char *str)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SortPlayersAlphabeticallyComparator
==============
*/
int CG_SortPlayersAlphabeticallyComparator(const void *a, const void *b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ConDrawInput_TextFieldFirstArgChar
==============
*/
int ConDrawInput_TextFieldFirstArgChar()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ConDrawInput_AutoCompleteArg
==============
*/
void ConDrawInput_AutoCompleteArg(LocalClientNum_t localClientNum, const char **stringList, int stringCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ConDrawInput_GetDvarDescriptionLines
==============
*/
int ConDrawInput_GetDvarDescriptionLines(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ConDrawInput_DetailedDvarMatch
==============
*/
void ConDrawInput_DetailedDvarMatch(LocalClientNum_t localClientNum, const char *str)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ConDrawInput_DetailedCmdMatch
==============
*/
void ConDrawInput_DetailedCmdMatch(LocalClientNum_t localClientNum, const char *str)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ConDrawInput_CmdMatch
==============
*/
void ConDrawInput_CmdMatch(const char *str)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_DrawAutoCompleteChoice
==============
*/
void Con_DrawAutoCompleteChoice(LocalClientNum_t localClientNum, bool isDvarCommand, const char *originalCommand)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_DrawInputPrompt
==============
*/
void Con_DrawInputPrompt(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_HasTooManyMatchesToShow
==============
*/
BOOL Con_HasTooManyMatchesToShow()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Con_IsDvarCommand
==============
*/
bool Con_IsDvarCommand(const char *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Con_CycleAutoComplete
==============
*/
char Con_CycleAutoComplete(int step)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Con_CancelAutoComplete
==============
*/
char Con_CancelAutoComplete()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Con_AllowAutoCompleteCycling
==============
*/
void Con_AllowAutoCompleteCycling(bool isAllowed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TypewriterSounds
==============
*/
void TypewriterSounds(LocalClientNum_t localClientNum, const MessageWindow *msgwnd, MessageLine *line)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_DrawMessageLineOnHUD
==============
*/
void Con_DrawMessageLineOnHUD(LocalClientNum_t localClientNum, const ScreenPlacement *scrPlace, int x, int y, int charHeight, int horzAlign, int vertAlign, Font_s *font, const MessageWindow *msgwnd, int lineIdx, vec4_t *color, int textStyle, float msgwndScale, int textAlignMode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_CullFinishedLines
==============
*/
void Con_CullFinishedLines(int serverTime, MessageWindow *msgwnd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_GetMessageAlpha
==============
*/
double Con_GetMessageAlpha(Message *message, MessageWindow *msgwnd, int serverTime, bool scrollsIntoPlace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Con_DrawMessageWindowNewToOld
==============
*/
void Con_DrawMessageWindowNewToOld(LocalClientNum_t localClientNum, MessageWindow *msgwnd, int x, int y, int hudCharHeight, int horzAlign, int vertAlign, bool up, Font_s *font, vec4_t *color, int textStyle, float msgwndScale, int textAlignMode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_DrawMessageWindowOldToNew
==============
*/
void Con_DrawMessageWindowOldToNew(LocalClientNum_t localClientNum, MessageWindow *msgwnd, int x, int y, int charHeight, int horzAlign, int vertAlign, bool up, Font_s *font, vec4_t *color, int textStyle, float msgwndScale, int textAlignMode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_DrawMessageWindow
==============
*/
void Con_DrawMessageWindow(LocalClientNum_t localClientNum, MessageWindow *msgwnd, int x, int y, int charHeight, int horzAlign, int vertAlign, Font_s *font, vec4_t *color, int textStyle, float msgwndScale, msgwnd_mode_t mode, int textAlignMode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_DrawGameMessageWindow
==============
*/
void Con_DrawGameMessageWindow(char *a1, LocalClientNum_t localClientNum, int windowIndex, int xPos, int yPos, int horzAlign, int vertAlign, Font_s *font, float fontScale, vec4_t *color, int textStyle, int textAlignMode, msgwnd_mode_t mode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_DrawMiniConsole
==============
*/
void __cdecl Con_DrawMiniConsole(LocalClientNum_t localClientNum, int xPos, int yPos, float alpha)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_DrawErrors
==============
*/
void __cdecl Con_DrawErrors(LocalClientNum_t localClientNum, int xPos, int yPos, float alpha)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_IsValidGameMessageWindow
==============
*/
BOOL Con_IsValidGameMessageWindow(int windowIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Con_IsGameMessageWindowActive
==============
*/
bool Con_IsGameMessageWindowActive(LocalClientNum_t localClientNum, int windowIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Con_DrawSay
==============
*/
void Con_DrawSay(LocalClientNum_t localClientNum, int x, int y)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_ToggleConsoleOutput
==============
*/
void Con_ToggleConsoleOutput()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_DrawOutputScrollBar
==============
*/
void Con_DrawOutputScrollBar(float x, float y, float width, float height)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_DrawOutputText
==============
*/
void Con_DrawOutputText(float x, float y)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_DrawOuputWindow
==============
*/
void Con_DrawOuputWindow()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_PageUp
==============
*/
void Con_PageUp()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_PageDown
==============
*/
void Con_PageDown()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_Top
==============
*/
void Con_Top()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_Bottom
==============
*/
void Con_Bottom()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_Close
==============
*/
void Con_Close(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_IsActive
==============
*/
bool Con_IsActive(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_PlayTextFXPulseSounds
==============
*/
void CL_PlayTextFXPulseSounds(LocalClientNum_t localClientNum, int currentTime, int strLength, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int *soundTimeKeeper)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_ToggleConsole
==============
*/
void Con_ToggleConsole()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_Echo_f
==============
*/
void Con_Echo_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_OneTimeInit
==============
*/
void __cdecl Con_OneTimeInit()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_Init
==============
*/
void Con_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ConsolePrint
==============
*/
void CL_ConsolePrint(LocalClientNum_t localClientNum, int channel, const char *txt, int duration, int pixelWidth, int flags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ConsoleFixPosition
==============
*/
void CL_ConsoleFixPosition()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ReviveMessagePrint
==============
*/
void CL_ReviveMessagePrint(unsigned int a1, LocalClientNum_t localClientNum, const char *reviveString, Material *iconShader, float iconWidth, float iconHeight, char *horzFlipIcon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DeathMessagePrint
==============
*/
void __cdecl CL_DeathMessagePrint(LocalClientNum_t localClientNum, const char *attackerName, char attackerColorIndex, const char *victimName, int victimColorIndex, Material *iconShader, float iconWidth, float iconHeight, unsigned int horzFlipIcon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_DrawInput
==============
*/
void Con_DrawInput(char *a1, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_CommitToAutoComplete
==============
*/
char Con_CommitToAutoComplete()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Con_DrawSolidConsole
==============
*/
void Con_DrawSolidConsole(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Con_DrawConsole
==============
*/
void Con_DrawConsole(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

