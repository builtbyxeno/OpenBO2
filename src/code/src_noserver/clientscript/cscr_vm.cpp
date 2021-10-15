#include "types.h"

/*
==============
TRACK_scr_vm
==============
*/
void TRACK_scr_vm()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_ClearErrorMessage
==============
*/
void Scr_ClearErrorMessage(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_FindDataCycles
==============
*/
void Scr_FindDataCycles(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_ReportDataCycles
==============
*/
void Scr_ReportDataCycles()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_VM_Init
==============
*/
void Scr_VM_Init(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_Init
==============
*/
void Scr_Init(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_Settings
==============
*/
void Scr_Settings(scriptInstance_t inst, int developer, int developer_script, int abort_on_error)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_Shutdown
==============
*/
void Scr_Shutdown(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_SetLoading
==============
*/
void Scr_SetLoading(scriptInstance_t inst, int bLoading)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_ErrorInternal
==============
*/
void Scr_ErrorInternal(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetLevelObjectId
==============
*/
unsigned int Scr_GetLevelObjectId(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_GetNumScriptThreads
==============
*/
int Scr_GetNumScriptThreads(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_ClearOutParams
==============
*/
void Scr_ClearOutParams(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CodeBreakpoints_Set
==============
*/
void CodeBreakpoints_Set(scriptInstance_t inst, const char *filename, int lineNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CodeBreakpoints_Init
==============
*/
void CodeBreakpoints_Init(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_ReportLongCallWarning
==============
*/
void Scr_ReportLongCallWarning(scriptInstance_t inst, unsigned __int8 *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetReturnPos
==============
*/
unsigned __int8 *Scr_GetReturnPos(scriptInstance_t inst, unsigned int *localId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
VM_CancelNotifyInternal
==============
*/
void VM_CancelNotifyInternal(scriptInstance_t inst, unsigned int notifyListOwnerId, unsigned int startLocalId, unsigned int notifyListId, unsigned int notifyNameListId, unsigned int stringValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VM_CancelNotify
==============
*/
void __cdecl VM_CancelNotify(scriptInstance_t inst, unsigned int notifyListOwnerId, unsigned int startLocalId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VM_ArchiveStack
==============
*/
VariableStackBuffer *VM_ArchiveStack(scriptInstance_t inst, VariableValue *top, VariableValue *startTop, unsigned __int8 *pos, unsigned int localVarCount, unsigned int *localId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_AddLocalVars
==============
*/
int Scr_AddLocalVars(scriptInstance_t inst, unsigned int localId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VM_UnarchiveStack
==============
*/
void VM_UnarchiveStack(scriptInstance_t inst, unsigned int startLocalId, const VariableStackBuffer *stackValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VM_TerminateStack
==============
*/
void VM_TerminateStack(scriptInstance_t inst, unsigned int endLocalId, unsigned int startLocalId, VariableStackBuffer *stackValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetStackThreadPos
==============
*/
unsigned __int8 *Scr_GetStackThreadPos(scriptInstance_t inst, unsigned int endLocalId, VariableStackBuffer *stackValue, bool killThread)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_SetStackThreadPos
==============
*/
void Scr_SetStackThreadPos(scriptInstance_t inst, unsigned int endLocalId, VariableStackBuffer *stackValue, unsigned __int8 *codePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VM_TrimStack
==============
*/
void VM_TrimStack(scriptInstance_t inst, unsigned int startLocalId, VariableStackBuffer *stackValue, bool fromEndon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_TerminateRunningThread
==============
*/
void Scr_TerminateRunningThread(scriptInstance_t inst, unsigned int localId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetRunningThreadPos
==============
*/
unsigned __int8 *Scr_GetRunningThreadPos(scriptInstance_t inst, unsigned int localId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_SetRunningThreadPos
==============
*/
void Scr_SetRunningThreadPos(scriptInstance_t inst, unsigned int localId, unsigned __int8 *codePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_TerminateWaitThread
==============
*/
void Scr_TerminateWaitThread(scriptInstance_t inst, unsigned int localId, unsigned int startLocalId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetWaitThreadStackId
==============
*/
unsigned int Scr_GetWaitThreadStackId(scriptInstance_t inst, unsigned int localId, unsigned int startLocalId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_CancelWaittill
==============
*/
void Scr_CancelWaittill(scriptInstance_t inst, unsigned int startLocalId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_TerminateWaittillThread
==============
*/
void Scr_TerminateWaittillThread(scriptInstance_t inst, unsigned int localId, unsigned int startLocalId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetWaittillThreadStackId
==============
*/
unsigned int Scr_GetWaittillThreadStackId(scriptInstance_t inst, unsigned int localId, unsigned int startLocalId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_TerminateThread
==============
*/
void Scr_TerminateThread(scriptInstance_t inst, unsigned int localId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetThreadPos
==============
*/
unsigned __int8 *__cdecl Scr_GetThreadPos(scriptInstance_t inst, unsigned int localId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_SetThreadPos
==============
*/
void __cdecl Scr_SetThreadPos(scriptInstance_t inst, unsigned int localId, unsigned __int8 *codePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VM_Notify
==============
*/
void VM_Notify(scriptInstance_t inst, unsigned int notifyListOwnerId, unsigned int stringValue, VariableValue *top)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_NotifyId
==============
*/
void Scr_NotifyId(scriptInstance_t inst, LocalClientNum_t clientNum, unsigned int id, unsigned int stringValue, unsigned int paramcount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_NotifyNum
==============
*/
void Scr_NotifyNum(int entnum, unsigned int classnum, unsigned int stringValue, unsigned int paramcount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CScr_NotifyNum
==============
*/
void CScr_NotifyNum(LocalClientNum_t clientNum, int entnum, unsigned int classnum, unsigned int stringValue, unsigned int paramcount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_NotifyLevel
==============
*/
void Scr_NotifyLevel(unsigned int stringValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CScr_NotifyLevel
==============
*/
void CScr_NotifyLevel(LocalClientNum_t clientNum, unsigned int stringValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_NotifyLevel
==============
*/
void Scr_NotifyLevel(const char *notifyString)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CScr_NotifyLevel
==============
*/
void CScr_NotifyLevel(LocalClientNum_t clientNum, const char *notifyString)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_CancelNotifyList
==============
*/
void Scr_CancelNotifyList(scriptInstance_t inst, unsigned int notifyListOwnerId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VM_TerminateTime
==============
*/
void VM_TerminateTime(scriptInstance_t inst, unsigned int timeId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IncInParam
==============
*/
void IncInParam(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_FreeThread
==============
*/
void Scr_FreeThread(scriptInstance_t inst, unsigned __int16 handle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_IsSystemInitied
==============
*/
bool Scr_IsSystemInitied(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_InitSystem
==============
*/
void Scr_InitSystem(scriptInstance_t inst, int sys)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_IsSystemActive
==============
*/
BOOL Scr_IsSystemActive(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_GetNumParam
==============
*/
int Scr_GetNumParam(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_AddBool
==============
*/
void Scr_AddBool(scriptInstance_t inst, int value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_AddInt
==============
*/
void Scr_AddInt(scriptInstance_t inst, int value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_AddFloat
==============
*/
void Scr_AddFloat(scriptInstance_t inst, float value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_AddAnim
==============
*/
void Scr_AddAnim(scriptInstance_t inst, scr_anim_s value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_AddUndefined
==============
*/
void Scr_AddUndefined(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_AddObject
==============
*/
void Scr_AddObject(scriptInstance_t inst, unsigned int id)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_AddEntityNum
==============
*/
void Scr_AddEntityNum(scriptInstance_t inst, int entnum, unsigned int classnum, LocalClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_AddString
==============
*/
void Scr_AddString(scriptInstance_t inst, const char *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_AddIString
==============
*/
void Scr_AddIString(scriptInstance_t inst, const char *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_AddConstString
==============
*/
void Scr_AddConstString(scriptInstance_t inst, unsigned int value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_AddVectorInternal
==============
*/
void Scr_AddVectorInternal(scriptInstance_t inst, const vec3_t *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_AddVector
==============
*/
void Scr_AddVector(scriptInstance_t inst, const vec3_t *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_AddValue
==============
*/
void Scr_AddValue(scriptInstance_t inst, VariableValue *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_MakeArray
==============
*/
void Scr_MakeArray(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_AddArray
==============
*/
void Scr_AddArray(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_AddArrayStringIndexed
==============
*/
void Scr_AddArrayStringIndexed(scriptInstance_t inst, unsigned int stringValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_Error
==============
*/
void Scr_Error(scriptInstance_t inst, const char *error, bool force_terminal)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_TerminalError
==============
*/
void Scr_TerminalError(scriptInstance_t inst, const char *error)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_ParamError
==============
*/
void Scr_ParamError(scriptInstance_t inst, unsigned int index, const char *error)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_ObjectError
==============
*/
void Scr_ObjectError(scriptInstance_t inst, const char *error)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SetEntityFieldValue
==============
*/
char SetEntityFieldValue(scriptInstance_t inst, unsigned int classnum, int entnum, unsigned __int16 clientNum, int offset, VariableValue *value)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetEntityFieldValue
==============
*/
VariableValue GetEntityFieldValue(scriptInstance_t inst, unsigned int classnum, int entnum, unsigned __int16 clientNum, int offset)
{
	UNIMPLEMENTED(__FUNCTION__);
	VariableValue tmp;
	return tmp;
}

/*
==============
Scr_SetStructField
==============
*/
void Scr_SetStructField(scriptInstance_t inst, unsigned int structId, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_SetDynamicEntityField
==============
*/
void Scr_SetDynamicEntityField(scriptInstance_t inst, int entnum, unsigned int classnum, unsigned int index, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_DecTime
==============
*/
void Scr_DecTime(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetLastScriptPlace
==============
*/
void Scr_GetLastScriptPlace(scriptInstance_t inst, int *line, const char **filename)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_RegisterNotifyListener
==============
*/
void Scr_RegisterNotifyListener(scriptInstance_t inst, void (*cbFunc)(unsigned int, unsigned int))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_AddTeam
==============
*/
void Scr_AddTeam(scriptInstance_t inst, int team)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_IsTrue
==============
*/
int Scr_IsTrue(scriptInstance_t inst, VariableValue *value)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_GetDvar
==============
*/
void Scr_GetDvar(scriptInstance_t inst, VariableValue *v)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetDvarInt
==============
*/
void Scr_GetDvarInt(scriptInstance_t inst, VariableValue *v)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetDvarFloat
==============
*/
void Scr_GetDvarFloat(scriptInstance_t inst, VariableValue *v)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetDvarVector
==============
*/
void Scr_GetDvarVector(scriptInstance_t inst, VariableValue *v)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetDvarColorRed
==============
*/
void Scr_GetDvarColorRed(scriptInstance_t inst, VariableValue *v)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetDvarColorGreen
==============
*/
void Scr_GetDvarColorGreen(scriptInstance_t inst, VariableValue *v)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetDvarColorBlue
==============
*/
void Scr_GetDvarColorBlue(scriptInstance_t inst, VariableValue *v)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetDvarColorAlpha
==============
*/
void Scr_GetDvarColorAlpha(scriptInstance_t inst, VariableValue *v)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VM_Execute
==============
*/
unsigned int VM_Execute(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_GetNextCodepos
==============
*/
unsigned __int8 *Scr_GetNextCodepos(scriptInstance_t inst, int mode, unsigned __int8 opcode, unsigned __int8 *pos, VariableValue *top, unsigned int *localId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
VM_Resume
==============
*/
void VM_Resume(scriptInstance_t inst, unsigned int timeId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VM_Execute_0
==============
*/
unsigned int VM_Execute_0(scriptInstance_t inst, unsigned int localId, unsigned __int8 *pos, unsigned int paramcount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_ExecThread
==============
*/
__int16 Scr_ExecThread(scriptInstance_t inst, int handle, unsigned int paramcount)
{
	UNIMPLEMENTED(__FUNCTION__);
	__int16 tmp;
	return tmp;
}

/*
==============
Scr_ExecEntThreadNum
==============
*/
__int16 Scr_ExecEntThreadNum(scriptInstance_t inst, int entnum, unsigned int classnum, int handle, unsigned int paramcount, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	__int16 tmp;
	return tmp;
}

/*
==============
Scr_AddExecThread
==============
*/
void Scr_AddExecThread(scriptInstance_t inst, int handle, unsigned int paramcount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_ExecCode
==============
*/
void Scr_ExecCode(scriptInstance_t inst, unsigned __int8 *pos, unsigned int localId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VM_SetTime
==============
*/
void VM_SetTime(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_ShutdownSystem
==============
*/
void Scr_ShutdownSystem(const char *a1, scriptInstance_t inst, unsigned __int8 sys, bool bComplete)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetInt
==============
*/
int Scr_GetInt(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_GetAnim
==============
*/
scr_anim_s Scr_GetAnim(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	scr_anim_s tmp;
	return tmp;
}

/*
==============
Scr_GetAnimTree
==============
*/
scr_animtree_t Scr_GetAnimTree(scriptInstance_t inst, unsigned int index, unsigned int user)
{
	UNIMPLEMENTED(__FUNCTION__);
	scr_animtree_t tmp;
	return tmp;
}

/*
==============
Scr_GetFloat
==============
*/
double Scr_GetFloat(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_GetConstString
==============
*/
VariableUnion Scr_GetConstString(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	VariableUnion tmp;
	return tmp;
}

/*
==============
Scr_GetConstLowercaseString
==============
*/
VariableUnion Scr_GetConstLowercaseString(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	VariableUnion tmp;
	return tmp;
}

/*
==============
Scr_GetString
==============
*/
char *Scr_GetString(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_GetConstStringIncludeNull
==============
*/
VariableUnion Scr_GetConstStringIncludeNull(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	VariableUnion tmp;
	return tmp;
}

/*
==============
Scr_GetDebugString
==============
*/
char *Scr_GetDebugString(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_GetConstIString
==============
*/
unsigned int Scr_GetConstIString(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_GetIString
==============
*/
char *Scr_GetIString(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_GetVector
==============
*/
void Scr_GetVector(scriptInstance_t inst, unsigned int index, vec3_t *vectorValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetFunc
==============
*/
int Scr_GetFunc(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_GetEntityRef
==============
*/
int Scr_GetEntityRef(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_GetObject
==============
*/
unsigned int Scr_GetObject(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_GetType
==============
*/
int Scr_GetType(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_GetTypeName
==============
*/
const char *Scr_GetTypeName(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_GetPointerType
==============
*/
unsigned int Scr_GetPointerType(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_RunCurrentThreads
==============
*/
void Scr_RunCurrentThreads(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetTeam
==============
*/
int Scr_GetTeam(scriptInstance_t inst, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_IncTime
==============
*/
void Scr_IncTime(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

