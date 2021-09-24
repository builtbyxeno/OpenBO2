#include "types.h"

/*
==============
DDL_Converter_CopyStates
==============
*/
void DDL_Converter_CopyStates(ddlState_t *a1, ddlState_t *const stateFrom, unsigned __int8 *bufferFrom, ddlState_t *const stateTo, unsigned __int8 *bufferTo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DDL_Converter_ProcessStates
==============
*/
void DDL_Converter_ProcessStates(ddlState_t *a1, const ddlStructDef_t *const structDef, const int structMemberItr, ddlState_t *const oldState, ddlState_t *const newState, unsigned __int8 *oldBuffer, unsigned __int8 *newBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DDL_Converter_TraverseStruct
==============
*/
void DDL_Converter_TraverseStruct(ddlState_t *a1, const ddlStructDef_t *const structDef, const ddlState_t *const oldBaseState, const ddlState_t *const newBaseState, unsigned __int8 *oldBuffer, unsigned __int8 *newBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DDL_Converter_Versions
==============
*/
int DDL_Converter_Versions(ddlState_t *a1, ddlDef_t *ddlVersionFrom, ddlDef_t *ddlVersionTo, unsigned __int8 *buffer, unsigned __int8 *backupBuffer, int bufferSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_PathStackPrint
==============
*/
char *DDL_PathStackPrint()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DDL_Converter_ProcessStateForPaths
==============
*/
void DDL_Converter_ProcessStateForPaths(const ddlStructDef_t *const structDef, const int structMemberItr, ddlState_t *const state, int bitStart, int bitEnd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DDL_Converter_TraverseStructForPaths
==============
*/
void DDL_Converter_TraverseStructForPaths(const ddlStructDef_t *const structDef, const ddlState_t *const baseState, int bitStart, int bitEnd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DDL_Converter_GetPathsInBytes
==============
*/
int DDL_Converter_GetPathsInBytes(ddlDef_t *ddlDef, int startByte, int endByte)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

