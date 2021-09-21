#include "types.h"
#include "functions.h"

/*
==============
Field_AdjustScroll
==============
*/
void Field_AdjustScroll(LocalClientNum_t localClientNum, const ScreenPlacement *scrPlace, field_t *edit)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Field_Paste
==============
*/
char Field_Paste(LocalClientNum_t localClientNum, const ScreenPlacement *scrPlace, field_t *edit)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FindMatches
==============
*/
void FindMatches(const char *s)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PrintMatches
==============
*/
void PrintMatches(const char *s)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
keyConcatArgs
==============
*/
int keyConcatArgs()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ReplaceConsoleInputArgument
==============
*/
void ReplaceConsoleInputArgument(int replaceCount, const char *replacement)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CompleteCmdArgument
==============
*/
void CompleteCmdArgument()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CompleteDvarArgument
==============
*/
void CompleteDvarArgument()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UpdateMatches
==============
*/
void UpdateMatches(bool searchCmds, int *matchLenAfterCmds, int *matchLenAfterDvars)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CompleteCommand
==============
*/
void CompleteCommand(int *a1, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Console_IsScrollUpKey
==============
*/
bool Console_IsScrollUpKey(int key, int isShiftDown, int isCtrlDown)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Console_IsScrollDownKey
==============
*/
bool Console_IsScrollDownKey(int key, int isShiftDown, int isCtrlDown)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Key_GetOverstrikeMode
==============
*/
int Key_GetOverstrikeMode(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Key_SetOverstrikeMode
==============
*/
void Key_SetOverstrikeMode(LocalClientNum_t localClientNum, int state)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Key_IsDown
==============
*/
int Key_IsDown(LocalClientNum_t localClientNum, int keynum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Key_StringToKeynum
==============
*/
int Key_StringToKeynum(LocalClientNum_t localClientNum, const char *str)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Key_IsValidGamePadChar
==============
*/
BOOL Key_IsValidGamePadChar(const char key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Key_KeynumToString
==============
*/
const char *Key_KeynumToString(LocalClientNum_t localClientNum, int keynum, int translate)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Key_SetBinding
==============
*/
void Key_SetBinding(LocalClientNum_t localClientNum, int keynum, Bind_t binding, BindIndex_t index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Key_SetBindingCheat
==============
*/
void Key_SetBindingCheat(LocalClientNum_t localClientNum, int keynum, const char *bindingCheat)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Key_SetBindings
==============
*/
void Key_SetBindings(LocalClientNum_t localClientNum, int *twokeys, Bind_t binding, BindIndex_t bindNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Key_GetBinding
==============
*/
Bind_t Key_GetBinding(LocalClientNum_t localClientNum, int keynum, BindIndex_t index)
{
	UNIMPLEMENTED(__FUNCTION__);
	Bind_t tmp;
	return tmp;
}

/*
==============
Key_GetCommandAssignmentInternal
==============
*/
int Key_GetCommandAssignmentInternal(LocalClientNum_t localClientNum, Bind_t binding, int *twokeys, BindIndex_t bindNum, int gamePadOnly)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Key_GetSafeFreeKey
==============
*/
int Key_GetSafeFreeKey(LocalClientNum_t localClientNum, BindIndex_t bindNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Key_GetMouseKeyboardCommandAssignment
==============
*/
int Key_GetMouseKeyboardCommandAssignment(LocalClientNum_t localClientNum, Bind_t binding, int *twokeys, BindIndex_t bindNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Key_BindMustHaveCommands
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Key_UpdateMustHaveBindings_f
==============
*/
void Key_UpdateMustHaveBindings_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Key_GetCommandAssignment
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Key_Unbind_f
==============
*/
void Key_Unbind_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Key_Unbind2_f
==============
*/
void Key_Unbind2_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Key_Unbindall_f
==============
*/
void Key_Unbindall_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Key_Unbindall2_f
==============
*/
void Key_Unbindall2_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Key_ClearStates
==============
*/
void Key_ClearStates(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_IsKeyPressed
==============
*/
int CL_IsKeyPressed(const LocalClientNum_t localClientNum, const char *keyName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Key_Shutdown
==============
*/
void Key_Shutdown()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Key_IsCatcherActive
==============
*/
bool Key_IsCatcherActive(LocalClientNum_t localClientNum, int mask)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Key_AddCatcher
==============
*/
void Key_AddCatcher(LocalClientNum_t localClientNum, int orMask)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Key_RemoveCatcher
==============
*/
void Key_RemoveCatcher(LocalClientNum_t localClientNum, int andMask)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Key_SetCatcher
==============
*/
void Key_SetCatcher(LocalClientNum_t localClientNum, int catcher)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Key_GetBindingForCmd
==============
*/
Bind_t Key_GetBindingForCmd(const char *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
	Bind_t tmp;
	return tmp;
}

/*
==============
Key_GetCmdForBinding
==============
*/
const char *Key_GetCmdForBinding(Bind_t binding)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Field_DrawTextOverride
==============
*/
void Field_DrawTextOverride(LocalClientNum_t localClientNum, const field_t *edit, int x, int y, int horzAlign, int vertAlign, const char *str, int drawLen, int cursorPos, bool FullUnsafe)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Field_Draw
==============
*/
void Field_Draw(LocalClientNum_t localClientNum, field_t *edit, int x, int y, int horzAlign, int vertAlign, bool fullUnSafe)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Field_KeyDownEvent
==============
*/
bool Field_KeyDownEvent(LocalClientNum_t localClientNum, const ScreenPlacement *scrPlace, field_t *edit, int key)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Field_CharEvent
==============
*/
char Field_CharEvent(LocalClientNum_t localClientNum, const ScreenPlacement *scrPlace, field_t *edit, int ch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Console_Key
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Message_Key
==============
*/
void Message_Key(LocalClientNum_t localClientNum, int key)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Key_GetBindingCheat
==============
*/
const char *Key_GetBindingCheat(LocalClientNum_t localClientNum, int keynum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Key_GetCheatAssignmentInternal
==============
*/
int Key_GetCheatAssignmentInternal(LocalClientNum_t localClientNum, const char *command, int *twokeys, int gamePadOnly)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Key_IsCommandBound
==============
*/
BOOL Key_IsCommandBound(LocalClientNum_t localClientNum, const char *command, BindIndex_t bindIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Key_Bind_f
==============
*/
void Key_Bind_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Key_Bind2_f
==============
*/
void Key_Bind2_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Key_Bindlist_f
==============
*/
void Key_Bindlist_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_InitKeyCommands
==============
*/
void CL_InitKeyCommands()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_KeyEvent
==============
*/
void CL_KeyEvent(LocalClientNum_t localClientNum, int key, const int down, const unsigned int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ConsoleCharEvent
==============
*/
void CL_ConsoleCharEvent(LocalClientNum_t localClientNum, int key)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_CharEvent
==============
*/
void CL_CharEvent(LocalClientNum_t localClientNum, int key)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_GetKeyBindingInternal
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CL_GetKeyBinding
==============
*/
int CL_GetKeyBinding(LocalClientNum_t localClientNum, const char *command, char (*keyNames)[128], BindIndex_t bindNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_GetGamePadBinding
==============
*/
int CL_GetGamePadBinding(LocalClientNum_t localClientNum, const char *command, char (*keyNames)[128], BindIndex_t bindNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

