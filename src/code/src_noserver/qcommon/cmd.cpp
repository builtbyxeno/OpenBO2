#include "types.h"

/*
==============
TRACK_cmd
==============
*/
void TRACK_cmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_SetZM_f
==============
*/
void Cmd_SetZM_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_Wait_f
==============
*/
void Cmd_Wait_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cbuf_Init
==============
*/
void Cbuf_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_ShiftArgs
==============
*/
void Cmd_ShiftArgs(int count, CmdArgs *args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cbuf_AddText
==============
*/
void Cbuf_AddText(LocalClientNum_t localClientNum, const char *text)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cbuf_InsertText
==============
*/
void Cbuf_InsertText(LocalClientNum_t localClientNum, const char *text)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cbuf_AddServerText_f
==============
*/
void Cbuf_AddServerText_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_AddServerCommandInternal
==============
*/
void Cmd_AddServerCommandInternal(const char *cmdName, void (*function)(), cmd_function_s *allocedCmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_ExecFromDiskAddText
==============
*/
bool Cmd_ExecFromDiskAddText(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, const char *filename)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Cmd_ExecAddText_f
==============
*/
void Cmd_ExecAddText_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_Cmd_ArgvBuffer
==============
*/
void SV_Cmd_ArgvBuffer(int arg, char *buffer, int bufferLength)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_ArgsBuffer
==============
*/
void Cmd_ArgsBuffer(int start, char *buffer, int bufLength)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_IsWhiteSpaceChar
==============
*/
bool Cmd_IsWhiteSpaceChar(char letter)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Cmd_EmitChar
==============
*/
void Cmd_EmitChar(char letter, CmdArgs *argsPriv)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_EmitString
==============
*/
void Cmd_EmitString(const char *str, CmdArgs *argsPriv)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_EvaluateExpression
==============
*/
void Cmd_EvaluateExpression(const char **text_in, CmdArgs *argsPriv)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_TokenizeStringInternal
==============
*/
int Cmd_TokenizeStringInternal(const char *text_in, int max_tokens, bool evalExpressions, const char **argv, CmdArgs *argsPriv)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AssertCmdArgsConsistency
==============
*/
void AssertCmdArgsConsistency(const CmdArgs *args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_TokenizeStringKernel
==============
*/
void Cmd_TokenizeStringKernel(LocalClientNum_t localClientNum, ControllerIndex_t localControllerIndex, itemDef_s *item, const char *text_in, int max_tokens, bool evalExpressions, CmdArgs *args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_EndTokenizedStringKernel
==============
*/
void Cmd_EndTokenizedStringKernel(CmdArgs *args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_TokenizeStringWithLimit
==============
*/
void __cdecl Cmd_TokenizeStringWithLimit(const char *text_in)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_TokenizeString
==============
*/
void Cmd_TokenizeString(char *a1, const char *text_in)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_TokenizeStringNoEval
==============
*/
void __cdecl Cmd_TokenizeStringNoEval(const char *text_in)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_EndTokenizedString
==============
*/
void Cmd_EndTokenizedString()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_Cmd_TokenizeString
==============
*/
void SV_Cmd_TokenizeString(ControllerIndex_t a1, LocalClientNum_t a2, const char *text_in)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_Cmd_EndTokenizedString
==============
*/
void SV_Cmd_EndTokenizedString(CmdArgs *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_FindCommand
==============
*/
cmd_function_s *Cmd_FindCommand(const char *cmdName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Cmd_AddCommandInternal
==============
*/
void Cmd_AddCommandInternal(const char *cmdName, void (*function)(), cmd_function_s *allocedCmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_RemoveCommand
==============
*/
void Cmd_RemoveCommand(const char *cmdName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_SetAutoComplete
==============
*/
void Cmd_SetAutoComplete(const char *cmdName, const char *dir, const char *ext)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_Shutdown
==============
*/
void Cmd_Shutdown()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_ForEach
==============
*/
void Cmd_ForEach(void (*callback)(const char *))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_ForEach
==============
*/
void Cmd_ForEach(LocalClientNum_t localClientNum, void (*callback)(LocalClientNum_t, const char *))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_GetAutoCompleteFileList
==============
*/
const char **Cmd_GetAutoCompleteFileList(const char *cmdName, int *fileCount, int allocTrackType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Cmd_ComErrorCleanup
==============
*/
void Cmd_ComErrorCleanup()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_List_f
==============
*/
void Cmd_List_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_DObjDump
==============
*/
void __cdecl Cmd_DObjDump()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_HandleMissingCommand
==============
*/
void Cmd_HandleMissingCommand(const char *msg, bool fromRemoteConsole)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_ExecuteServerString
==============
*/
void Cmd_ExecuteServerString(ControllerIndex_t a1, LocalClientNum_t a2, const char *text)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cbuf_SV_Execute
==============
*/
void Cbuf_SV_Execute()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_ExecuteSingleCommandInternal
==============
*/
void Cmd_ExecuteSingleCommandInternal(char *a1, LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, itemDef_s *item, const char *text, bool fromRemoteConsole)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_ExecuteSingleCommand
==============
*/
void Cmd_ExecuteSingleCommand(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, const char *text, bool fromRemoteConsole)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_Cmd_ExecuteString
==============
*/
void SV_Cmd_ExecuteString(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, const char *text)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ExecuteRestOfCommand
==============
*/
void ExecuteRestOfCommand()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_IfMP_f
==============
*/
void __cdecl Cmd_IfMP_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cbuf_ExecuteBufferInternal
==============
*/
void Cbuf_ExecuteBufferInternal(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, itemDef_s *item, const char *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cbuf_ExecuteBuffer
==============
*/
void Cbuf_ExecuteBuffer(ControllerIndex_t a1, LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, const char *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cbuf_ExecuteBufferUI
==============
*/
void __cdecl Cbuf_ExecuteBufferUI(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, itemDef_s *item, const char *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cbuf_ExecuteInternal
==============
*/
void Cbuf_ExecuteInternal(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cbuf_Execute
==============
*/
void Cbuf_Execute(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_ExecFromDisk
==============
*/
bool Cmd_ExecFromDisk(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, const char *filename)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Cmd_Exec_f
==============
*/
void Cmd_Exec_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Cmd_Init
==============
*/
void Cmd_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

