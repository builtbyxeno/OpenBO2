#pragma once

#include "types.h"

//t6/code/src_noserver/ddl/ddl_api.cpp
int DDL_GetTotalBufferBitSize(ddlDef_t *ddl);
int DDL_IsStateReadyForIO(ddlState_t *state, unsigned __int8 *buffer);
int DDL_GetStateForCmdPath(ddlState_t *state, int startArg, int endArg);
void DDL_ResetBufferInternal(unsigned __int8 *buffer, int bufferSize, ddlDef_t *ddl);
int DDL_GetBufferSize(ddlDef_t *ddl);
ddlDef_t *DDL_LoadAssetWithVersion(const char *fileName, int version);
ddlDef_t *DDL_LoadAsset(const char *fileName);
void DDL_ResetAndAssociateBuffer(unsigned __int8 *buffer, int bufferSize, ddlDef_t *ddl);
int DDL_BitwiseCopy(;
int DDL_BitwiseCopy(ddlState_t *fromState, ddlState_t *toState, unsigned __int8 *buffer);
char DDL_IsStateZero(const ddlState_t *state, unsigned __int8 *buffer);
int DDL_Buffer_Check(int offset, int size);
int DDL_AreStateValuesSame(;
BOOL DDL_AreValuesEqual(ddlState_t *state, ddlValue_t *valueA, ddlValue_t *valueB);
void DDL_Reset(ddlState_t *searchState, const ddlDef_t *ddl);
int DDL_MoveTo(const ddlState_t *searchState, ddlState_t *resultState, int numArgs, ...);
int DDL_MoveToPath(const ddlState_t *searchState, ddlState_t *resultState, int depth, const char **ddlPath);
int DDL_IterateNext(const ddlState_t *searchState, ddlState_t *resultState);
int DDL_IterateFirst(const ddlState_t *searchState, ddlState_t *resultState);
ddlIntValueChanged_e DDL_WriteUIntValueIfChanged(;
int DDL_SetRawBytes(unsigned __int8 *buffer, int offset, int size, const char *valueToInsert);
int DDL_WriteUIntValueInternal(ddlState_t *state, int absoluteOffset, unsigned int valueToInsert);
int DDL_WriteIntValueInternal(;
int DDL_WriteInt64ValueInternal(;
int DDL_WriteFloatValueInternal(ddlState_t *state, int absoluteOffset, float value, unsigned __int8 *buffer);
int DDL_WriteFixedPointValueInternal(;
int DDL_WriteStringValueInternal(;
int DDL_WriteValueInternal(ddlState_t *state, int absoluteOffset, ddlValue_t value, unsigned __int8 *buffer);
int DDL_GetState(const ddlDef_t *ddl, ddlState_t *searchState, int numArgs, char *args);
int DDL_SetInt(ddlState_t *searchState, int value, unsigned __int8 *buffer);
int DDL_SetUInt(ddlState_t *searchState, unsigned int value, unsigned __int8 *buffer);
int DDL_SetInt64(ddlState_t *searchState, unsigned __int64 value, unsigned __int8 *buffer);
int DDL_SetFloat(ddlState_t *searchState, float value, unsigned __int8 *buffer);
int DDL_SetFloat(ddlDef_t *ddl, float value, unsigned __int8 *buffer, int numArgs, ...);
int DDL_SetFixedPoint(ddlState_t *searchState, float value, unsigned __int8 *buffer);
int DDL_SetFixedPoint(ddlDef_t *ddl, float value, unsigned __int8 *buffer, int numArgs, ...);
int DDL_SetString(ddlState_t *searchState, const char *value, unsigned __int8 *buffer);
int DDL_SetValue(ddlState_t *searchState, ddlValue_t value, unsigned __int8 *buffer);
int DDL_SetValue(ddlState_t *searchState, const char *value, unsigned __int8 *buffer);
int DDL_SetBits(unsigned __int8 *buffer, int bitOffset, int bitSize, unsigned int value);
unsigned int DDL_ReadUIntValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int8 *buffer);
unsigned int DDL_GetUInt(ddlState_t *searchState, unsigned __int8 *buffer);
int DDL_ReadIntValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int8 *buffer);
int DDL_GetInt(ddlState_t *searchState, unsigned __int8 *buffer);
unsigned int DDL_ReadInt64ValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int8 *buffer);
unsigned int DDL_GetInt64(ddlState_t *searchState, unsigned __int8 *buffer);
float DDL_ReadFloatValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int8 *buffer);
// float DDL_GetFloat@<st0>(ddlState_t *a1@<xmm0>, ddlState_t *searchState, unsigned __int8 *buffer);
// double DDL_GetFloat@<st0>(ddlState_t *a1@<xmm0>, ddlDef_t *ddl, unsigned __int8 *buffer, int numArgs, ...);
float DDL_ReadFixedPointValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int8 *buffer);
// float DDL_GetFixedPoint@<st0>(ddlState_t *a1@<xmm0>, ddlState_t *searchState, unsigned __int8 *buffer);
// double DDL_GetFixedPoint@<st0>(;
bool DDL_GetBool(ddlState_t *searchState, unsigned __int8 *buffer);
bool DDL_GetBool(ddlDef_t *ddl, unsigned __int8 *buffer, int numArgs, ...);
char DDL_LoadStringValueInternal(;
char *DDL_ReadStringValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int8 *buffer);
char *DDL_GetString(ddlState_t *searchState, unsigned __int8 *buffer);
char DDL_LoadString(ddlState_t *searchState, unsigned __int8 *buffer, char *outBuffer, int outBufferLength);
int DDL_ReadValueInternal(;
int DDL_GetValue(ddlState_t *searchState, ddlValue_t *result, unsigned __int8 *buffer);
unsigned int DDL_GetBits(unsigned __int8 *buffer, int bitOffset, int bitSize);
void DDL_CheckArrayBindings();
;
void DDL_ZeroState(ddlState_t *state, unsigned __int8 *buffer);
int DDL_SetBool(ddlState_t *searchState, bool value, unsigned __int8 *buffer);
int DDL_SetUpdatedChecksum(unsigned __int8 *buffer, int bufferSize);
unsigned int DDL_GetHeaderVersion(unsigned __int8 *buffer);
int DDL_FixBufferVersion(;
int DDL_ValidateHeader(;
int DDL_AssociateBufferNonDestructive(;
int DDL_AssociateBuffer(;
int DDL_SetBool(ddlDef_t *ddl, bool value, unsigned __int8 *buffer, int numArgs, ...);

//t6/code/src_noserver/ddl/ddl_buffer.cpp
void DDL_Buffer_SwapHeader(const ddlBufferHeader_t *src, ddlBufferHeader_t *dest);
void DDL_Buffer_WriteHeader(unsigned __int8 *buffer, const ddlBufferHeader_t *header);
void DDL_Buffer_ReadHeader(unsigned __int8 *buffer, ddlBufferHeader_t *header);
int DDL_Buffer_ReadBits(unsigned __int8 *buffer, int offset, int size);
void DDL_Buffer_WriteBits(unsigned __int8 *buffer, int offset, int size, unsigned int value);

//#include "ddl/ddl_buffer.h"

//t6/code/src_noserver/ddl/ddl_cmd.cpp
void DDL_Cmd_GetAsset_f();
void DDL_Cmd_Show_f();
void DDL_Cmd_ShowMember_f();
void DDL_Cmd_ShowPaths_f();
void DDL_Cmd_Init();

//t6/code/src_noserver/ddl/ddl_converter.cpp
void DDL_Converter_CopyStates(;
void DDL_Converter_ProcessStates(;
void DDL_Converter_TraverseStruct(;
// int DDL_Converter_Versions@<eax>(;
char *DDL_PathStackPrint();
void DDL_Converter_ProcessStateForPaths(;
void DDL_Converter_TraverseStructForPaths(;
int DDL_Converter_GetPathsInBytes(ddlDef_t *ddlDef, int startByte, int endByte);

//#include "ddl/ddl_load_db.h"

//t6/code/src_noserver/ddl/ddl_lookup.cpp
ddlMemberDef_t *DDL_Lookup_FindInStruct(;
void DDL_Lookup_ClearState(ddlState_t *searchState);
ddlMemberDef_t *DDL_Lookup_FindMemberDefByLName(;
ddlMemberDef_t *DDL_Lookup_FindMemberDef(const char *memberName, ddlStructDef_t *structDef);
ddlMemberDef_t *DDL_Lookup_MoveToIndex(;
int DDL_Lookup_FindEnumIndexByName(ddlEnumDef_t *enumDef, int hashStartIndex, const char *memberName);
int DDL_Lookup_MoveTo(const ddlState_t *searchState, const char *name, ddlState_t *resultState);
int DDL_Lookup_MoveNext(const ddlState_t *searchState, ddlState_t *resultState);
BOOL DDL_Lookup_MoveToStart(ddlState_t *resultState, ddlDef_t *ddl);

