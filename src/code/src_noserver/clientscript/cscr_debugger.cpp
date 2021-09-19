#include "types.h"
#include "functions.h"

/*
==============
TRACK_scr_debugger
==============
*/
void TRACK_scr_debugger()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_FindBreakpointInfo
==============
*/
scrDebuggerGlob_t *Scr_FindBreakpointInfo(scriptInstance_t inst, const unsigned __int8 *codePos, int lineNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_AddBreakpoint
==============
*/
breakpointData_t *Scr_AddBreakpoint(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_ForceBreakpoint
==============
*/
void Scr_ForceBreakpoint(scriptInstance_t inst, unsigned __int8 *codePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_RemoveBreakpoint
==============
*/
void Scr_RemoveBreakpoint(scriptInstance_t inst, int uniqueId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_DisableAllBreakpoint
==============
*/
void Scr_DisableAllBreakpoint(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_EnableAllBreakpoint
==============
*/
void Scr_EnableAllBreakpoint(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_RemoveAllBreakpoint
==============
*/
/*void Scr_RemoveAllBreakpoint(unsigned __int8 *a1@<edx>, scriptInstance_t a2@<ecx>, scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Scr_Step
==============
*/
void Scr_Step(scriptInstance_t inst, int step_mode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_RemoveValue
==============
*/
void Scr_RemoveValue(scriptInstance_t inst, _watchNode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_UpdateSelfName
==============
*/
void Scr_UpdateSelfName(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_UpdateLocals
==============
*/
void Scr_UpdateLocals(scriptInstance_t inst, unsigned int localVarCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SortDataCompare
==============
*/
int SortDataCompare(const void *e1, const void *e2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SortThreadCompare
==============
*/
int SortThreadCompare(const void *e1, const void *e2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SortEntCompare
==============
*/
int SortEntCompare(const void *e1, const void *e2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_Msg_SetBreakpoint
==============
*/
void Scr_Msg_SetBreakpoint()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_Msg_SetWatchBreakpoint
==============
*/
void Scr_Msg_SetWatchBreakpoint()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_Msg_SetNotifyBreakpoint
==============
*/
void Scr_Msg_SetNotifyBreakpoint()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_Msg_ClearBreakpoint
==============
*/
void Scr_Msg_ClearBreakpoint()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_Msg_SetBreakpointCondition
==============
*/
void Scr_Msg_SetBreakpointCondition()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_Msg_WatchSetData
==============
*/
void Scr_Msg_WatchSetData(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_ExecutePendingShellCommand
==============
*/
void Scr_ExecutePendingShellCommand(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_ShellCommand
==============
*/
void Scr_ShellCommand(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_ExecCommand
==============
*/
void Scr_ExecCommand()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_Msg_RunToLine
==============
*/
void Scr_Msg_RunToLine(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_Msg_SetLine
==============
*/
void Scr_Msg_SetLine(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_Msg_ChangeScope
==============
*/
void Scr_Msg_ChangeScope(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_InitDebugger
==============
*/
void Scr_InitDebugger(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_ShutdownDebugger
==============
*/
/*void Scr_ShutdownDebugger(unsigned __int8 *a1@<edx>, scriptInstance_t a2@<ecx>, scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Scr_SynchronizeDebuggerFileInfo
==============
*/
void Scr_SynchronizeDebuggerFileInfo(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_MonitorCommand
==============
*/
void Scr_MonitorCommand(const char *text, scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_UpdateDebuggerCallStack
==============
*/
void Scr_UpdateDebuggerCallStack(scriptInstance_t inst, unsigned __int8 *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_DebuggerReportRuntimeError
==============
*/
void Scr_DebuggerReportRuntimeError(const char *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_TestBreakpointCondition
==============
*/
bool Scr_TestBreakpointCondition(scriptInstance_t inst, breakpointData_t *breakpointInfo, unsigned int localId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_CheckForceJump
==============
*/
unsigned __int8 *Scr_CheckForceJump(scriptInstance_t inst, unsigned __int8 *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_EvaluateWatchChild
==============
*/
void Scr_EvaluateWatchChild(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_EvaluateWatchNode
==============
*/
void Scr_EvaluateWatchNode(scriptInstance_t inst, _watchNode_t *node, int uniqueId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_Msg_UpdateWatch
==============
*/
void Scr_Msg_UpdateWatch(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_Msg_ExpandWatch
==============
*/
void Scr_Msg_ExpandWatch(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_ReportThreadUsage
==============
*/
void Scr_ReportThreadUsage(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_ProcessDebugMessages
==============
*/
void Scr_ProcessDebugMessages(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_WaitForDebuggerToRespond
==============
*/
void Scr_WaitForDebuggerToRespond(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_UpdateDebugger
==============
*/
void Scr_UpdateDebugger(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_HitBreakpoint
==============
*/
unsigned __int8 Scr_HitBreakpoint(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_TestDataBreakpoints
==============
*/
void Scr_TestDataBreakpoints(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_TestNotifyBreakpoints
==============
*/
void Scr_TestNotifyBreakpoints(
{
	UNIMPLEMENTED(__FUNCTION__);
}

