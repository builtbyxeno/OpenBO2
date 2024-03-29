#include "types.h"

/*
==============
DDL_GetTotalBufferBitSize
==============
*/
int DDL_GetTotalBufferBitSize(ddlDef_t *ddl)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_IsStateReadyForIO
==============
*/
int DDL_IsStateReadyForIO(ddlState_t *state, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_GetStateForCmdPath
==============
*/
int DDL_GetStateForCmdPath(ddlState_t *state, int startArg, int endArg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_ResetBufferInternal
==============
*/
void DDL_ResetBufferInternal(unsigned __int8 *buffer, int bufferSize, ddlDef_t *ddl)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DDL_GetBufferSize
==============
*/
int DDL_GetBufferSize(ddlDef_t *ddl)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_LoadAssetWithVersion
==============
*/
ddlDef_t *DDL_LoadAssetWithVersion(const char *fileName, int version)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DDL_LoadAsset
==============
*/
ddlDef_t *DDL_LoadAsset(const char *fileName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DDL_ResetAndAssociateBuffer
==============
*/
void __cdecl DDL_ResetAndAssociateBuffer(unsigned __int8 *buffer, int bufferSize, ddlDef_t *ddl)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DDL_BitwiseCopy
==============
*/
int DDL_BitwiseCopy(ddlState_t *fromState, ddlState_t *toState, unsigned __int8 *inBuffer, unsigned __int8 *outBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_BitwiseCopy
==============
*/
int DDL_BitwiseCopy(ddlState_t *fromState, ddlState_t *toState, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_IsStateZero
==============
*/
char DDL_IsStateZero(const ddlState_t *state, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_Buffer_Check
==============
*/
int DDL_Buffer_Check(int offset, int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_AreStateValuesSame
==============
*/
int DDL_AreStateValuesSame(ddlState_t *stateA, unsigned __int8 *bufferA, ddlState_t *stateB, unsigned __int8 *bufferB)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_AreValuesEqual
==============
*/
BOOL DDL_AreValuesEqual(ddlState_t *state, ddlValue_t *valueA, ddlValue_t *valueB)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_Reset
==============
*/
void DDL_Reset(ddlState_t *searchState, const ddlDef_t *ddl)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DDL_MoveTo
==============
*/
int DDL_MoveTo(const ddlState_t *searchState, ddlState_t *resultState, int numArgs, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_MoveToPath
==============
*/
int DDL_MoveToPath(const ddlState_t *searchState, ddlState_t *resultState, int depth, const char **ddlPath)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_IterateNext
==============
*/
int DDL_IterateNext(const ddlState_t *searchState, ddlState_t *resultState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_IterateFirst
==============
*/
int DDL_IterateFirst(const ddlState_t *searchState, ddlState_t *resultState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_WriteUIntValueIfChanged
==============
*/
ddlIntValueChanged_e DDL_WriteUIntValueIfChanged(unsigned __int8 *buffer, int offset, int size, unsigned int valueToInsert)
{
	UNIMPLEMENTED(__FUNCTION__);
	ddlIntValueChanged_e tmp;
	return tmp;
}

/*
==============
DDL_SetRawBytes
==============
*/
int DDL_SetRawBytes(unsigned __int8 *buffer, int offset, int size, const char *valueToInsert)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_WriteUIntValueInternal
==============
*/
int __cdecl DDL_WriteUIntValueInternal(ddlState_t *state, int absoluteOffset, unsigned int valueToInsert)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_WriteIntValueInternal
==============
*/
int DDL_WriteIntValueInternal(ddlState_t *state, int absoluteOffset, int valueToInsert, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_WriteInt64ValueInternal
==============
*/
int DDL_WriteInt64ValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int64 valueToInsert, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_WriteFloatValueInternal
==============
*/
int DDL_WriteFloatValueInternal(ddlState_t *state, int absoluteOffset, float value, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_WriteFixedPointValueInternal
==============
*/
int DDL_WriteFixedPointValueInternal(ddlState_t *state, int absoluteOffset, float value, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_WriteStringValueInternal
==============
*/
int DDL_WriteStringValueInternal(ddlState_t *state, int absoluteOffset, const char *value, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_WriteValueInternal
==============
*/
int DDL_WriteValueInternal(ddlState_t *state, int absoluteOffset, ddlValue_t value, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_GetState
==============
*/
int DDL_GetState(const ddlDef_t *ddl, ddlState_t *searchState, int numArgs, char *args)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_SetInt
==============
*/
int __cdecl DDL_SetInt(ddlState_t *searchState, int value, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_SetUInt
==============
*/
int DDL_SetUInt(ddlState_t *searchState, unsigned int value, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_SetInt64
==============
*/
int __cdecl DDL_SetInt64(ddlState_t *searchState, unsigned __int64 value, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_SetFloat
==============
*/
int __cdecl DDL_SetFloat(ddlState_t *searchState, float value, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_SetFloat
==============
*/
int DDL_SetFloat(ddlDef_t *ddl, float value, unsigned __int8 *buffer, int numArgs, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_SetFixedPoint
==============
*/
int __cdecl DDL_SetFixedPoint(ddlState_t *searchState, float value, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_SetFixedPoint
==============
*/
int DDL_SetFixedPoint(ddlDef_t *ddl, float value, unsigned __int8 *buffer, int numArgs, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_SetString
==============
*/
int DDL_SetString(ddlState_t *searchState, const char *value, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_SetValue
==============
*/
int __cdecl DDL_SetValue(ddlState_t *searchState, ddlValue_t value, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_SetValue
==============
*/
int DDL_SetValue(char *a1, ddlState_t *searchState, const char *value, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_SetBits
==============
*/
int DDL_SetBits(unsigned __int8 *buffer, int bitOffset, int bitSize, unsigned int value)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_ReadUIntValueInternal
==============
*/
unsigned int DDL_ReadUIntValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_GetUInt
==============
*/
unsigned int __cdecl DDL_GetUInt(ddlState_t *searchState, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_ReadIntValueInternal
==============
*/
int DDL_ReadIntValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_GetInt
==============
*/
int __cdecl DDL_GetInt(ddlState_t *searchState, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_ReadInt64ValueInternal
==============
*/
unsigned int DDL_ReadInt64ValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_GetInt64
==============
*/
unsigned int DDL_GetInt64(ddlState_t *searchState, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_ReadFloatValueInternal
==============
*/
float DDL_ReadFloatValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_GetFloat
==============
*/
float DDL_GetFloat(ddlState_t *a1, ddlState_t *searchState, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_GetFloat
==============
*/
double DDL_GetFloat(ddlState_t *ddl, ddlDef_t *buffer, unsigned __int8 *numArgs, int args)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_ReadFixedPointValueInternal
==============
*/
float DDL_ReadFixedPointValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_GetFixedPoint
==============
*/
float DDL_GetFixedPoint(ddlState_t *a1, ddlState_t *searchState, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_GetFixedPoint
==============
*/
double DDL_GetFixedPoint(ddlState_t *ddl, ddlDef_t *buffer, unsigned __int8 *numArgs, int args)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_GetBool
==============
*/
bool DDL_GetBool(ddlState_t *searchState, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_GetBool
==============
*/
bool DDL_GetBool(ddlDef_t *ddl, unsigned __int8 *buffer, int numArgs, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_LoadStringValueInternal
==============
*/
char DDL_LoadStringValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int8 *buffer, char *outBuffer, int outBufferLength)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_ReadStringValueInternal
==============
*/
char *DDL_ReadStringValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DDL_GetString
==============
*/
char *DDL_GetString(ddlState_t *searchState, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DDL_LoadString
==============
*/
char DDL_LoadString(ddlState_t *searchState, unsigned __int8 *buffer, char *outBuffer, int outBufferLength)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_ReadValueInternal
==============
*/
int DDL_ReadValueInternal(ddlState_t *state, int absoluteOffset, ddlValue_t *result, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_GetValue
==============
*/
int __cdecl DDL_GetValue(ddlState_t *searchState, ddlValue_t *result, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_GetBits
==============
*/
unsigned int DDL_GetBits(unsigned __int8 *buffer, int bitOffset, int bitSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_CheckArrayBindings
==============
*/
void DDL_CheckArrayBindings()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DDL_Init
==============
*/
void __cdecl DDL_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DDL_ZeroState
==============
*/
void DDL_ZeroState(ddlState_t *state, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DDL_SetBool
==============
*/
int DDL_SetBool(ddlState_t *searchState, bool value, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_SetUpdatedChecksum
==============
*/
int DDL_SetUpdatedChecksum(unsigned __int8 *buffer, int bufferSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_GetHeaderVersion
==============
*/
unsigned int DDL_GetHeaderVersion(unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_FixBufferVersion
==============
*/
int DDL_FixBufferVersion(unsigned __int8 *buffer, ddlDef_t *ddlTo, const char *ddlName, unsigned __int8 *backupBuffer, int bufferSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_ValidateHeader
==============
*/
int DDL_ValidateHeader(unsigned __int8 *buffer, int bufferSize, ddlDef_t *ddl, const char *ddlFileName, const char *ddlArchiveFileName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_AssociateBufferNonDestructive
==============
*/
int __cdecl DDL_AssociateBufferNonDestructive(unsigned __int8 *buffer, int bufferSize, ddlDef_t *ddl, const char *ddlFileName, const char *ddlArchiveFileName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_AssociateBuffer
==============
*/
int __cdecl DDL_AssociateBuffer(unsigned __int8 *buffer, int bufferSize, ddlDef_t *ddl, const char *ddlFileName, const char *ddlArchiveFileName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_SetBool
==============
*/
int DDL_SetBool(ddlDef_t *ddl, bool value, unsigned __int8 *buffer, int numArgs, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

