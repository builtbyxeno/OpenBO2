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
;
int DDL_BitwiseCopy(ddlState_t *fromState, ddlState_t *toState, unsigned __int8 *inBuffer, unsigned __int8 *outBuffer);
int DDL_BitwiseCopy(ddlState_t *fromState, ddlState_t *toState, unsigned __int8 *buffer);
char DDL_IsStateZero(const ddlState_t *state, unsigned __int8 *buffer);
int DDL_Buffer_Check(int offset, int size);
int DDL_AreStateValuesSame(ddlState_t *stateA, unsigned __int8 *bufferA, ddlState_t *stateB, unsigned __int8 *bufferB);
BOOL DDL_AreValuesEqual(ddlState_t *state, ddlValue_t *valueA, ddlValue_t *valueB);
void DDL_Reset(ddlState_t *searchState, const ddlDef_t *ddl);
int DDL_MoveTo(const ddlState_t *searchState, ddlState_t *resultState, int numArgs, ...);
int DDL_MoveToPath(const ddlState_t *searchState, ddlState_t *resultState, int depth, const char **ddlPath);
int DDL_IterateNext(const ddlState_t *searchState, ddlState_t *resultState);
int DDL_IterateFirst(const ddlState_t *searchState, ddlState_t *resultState);
ddlIntValueChanged_e DDL_WriteUIntValueIfChanged(unsigned __int8 *buffer, int offset, int size, unsigned int valueToInsert);
int DDL_SetRawBytes(unsigned __int8 *buffer, int offset, int size, const char *valueToInsert);
;
int DDL_WriteIntValueInternal(ddlState_t *state, int absoluteOffset, int valueToInsert, unsigned __int8 *buffer);
;
int DDL_WriteFloatValueInternal(ddlState_t *state, int absoluteOffset, float value, unsigned __int8 *buffer);
int DDL_WriteFixedPointValueInternal(ddlState_t *state, int absoluteOffset, float value, unsigned __int8 *buffer);
int DDL_WriteStringValueInternal(ddlState_t *state, int absoluteOffset, const char *value, unsigned __int8 *buffer);
;
int DDL_GetState(const ddlDef_t *ddl, ddlState_t *searchState, int numArgs, char *args);
;
int DDL_SetUInt(ddlState_t *searchState, unsigned int value, unsigned __int8 *buffer);
;
;
int DDL_SetFloat(ddlDef_t *ddl, float value, unsigned __int8 *buffer, int numArgs, ...);
;
int DDL_SetFixedPoint(ddlDef_t *ddl, float value, unsigned __int8 *buffer, int numArgs, ...);
int DDL_SetString(ddlState_t *searchState, const char *value, unsigned __int8 *buffer);
;
;
int DDL_SetBits(unsigned __int8 *buffer, int bitOffset, int bitSize, unsigned int value);
unsigned int DDL_ReadUIntValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int8 *buffer);
;
;
;
unsigned int DDL_ReadInt64ValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int8 *buffer);
unsigned int DDL_GetInt64(ddlState_t *searchState, unsigned __int8 *buffer);
float DDL_ReadFloatValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int8 *buffer);
;
double DDL_GetFloat(ddlState_t *ddl, ddlDef_t *buffer, unsigned __int8 *numArgs, int args);
float DDL_ReadFixedPointValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int8 *buffer);
;
double DDL_GetFixedPoint(ddlState_t *ddl, ddlDef_t *buffer, unsigned __int8 *numArgs, int args);
bool DDL_GetBool(ddlState_t *searchState, unsigned __int8 *buffer);
bool DDL_GetBool(ddlDef_t *ddl, unsigned __int8 *buffer, int numArgs, ...);
char DDL_LoadStringValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int8 *buffer, char *outBuffer, int outBufferLength);
char *DDL_ReadStringValueInternal(ddlState_t *state, int absoluteOffset, unsigned __int8 *buffer);
char *DDL_GetString(ddlState_t *searchState, unsigned __int8 *buffer);
char DDL_LoadString(ddlState_t *searchState, unsigned __int8 *buffer, char *outBuffer, int outBufferLength);
;
;
unsigned int DDL_GetBits(unsigned __int8 *buffer, int bitOffset, int bitSize);
void DDL_CheckArrayBindings();
;
void DDL_ZeroState(ddlState_t *state, unsigned __int8 *buffer);
int DDL_SetBool(ddlState_t *searchState, bool value, unsigned __int8 *buffer);
int DDL_SetUpdatedChecksum(unsigned __int8 *buffer, int bufferSize);
unsigned int DDL_GetHeaderVersion(unsigned __int8 *buffer);
int DDL_FixBufferVersion(unsigned __int8 *buffer, ddlDef_t *ddlTo, const char *ddlName, unsigned __int8 *backupBuffer, int bufferSize);
;
;
;
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
void DDL_Converter_CopyStates(ddlState_t *a1, ddlState_t *const stateFrom, unsigned __int8 *bufferFrom, ddlState_t *const stateTo, unsigned __int8 *bufferTo);
void DDL_Converter_ProcessStates(ddlState_t *a1, const ddlStructDef_t *const structDef, const int structMemberItr, ddlState_t *const oldState, ddlState_t *const newState, unsigned __int8 *oldBuffer, unsigned __int8 *newBuffer);
void DDL_Converter_TraverseStruct(ddlState_t *a1, const ddlStructDef_t *const structDef, const ddlState_t *const oldBaseState, const ddlState_t *const newBaseState, unsigned __int8 *oldBuffer, unsigned __int8 *newBuffer);
int DDL_Converter_Versions(ddlState_t *a1, ddlDef_t *ddlVersionFrom, ddlDef_t *ddlVersionTo, unsigned __int8 *buffer, unsigned __int8 *backupBuffer, int bufferSize);
char *DDL_PathStackPrint();
void DDL_Converter_ProcessStateForPaths(const ddlStructDef_t *const structDef, const int structMemberItr, ddlState_t *const state, int bitStart, int bitEnd);
void DDL_Converter_TraverseStructForPaths(const ddlStructDef_t *const structDef, const ddlState_t *const baseState, int bitStart, int bitEnd);
int DDL_Converter_GetPathsInBytes(ddlDef_t *ddlDef, int startByte, int endByte);

//#include "ddl/ddl_load_db.h"

//t6/code/src_noserver/ddl/ddl_lookup.cpp
ddlMemberDef_t *DDL_Lookup_FindInStruct(ddlStructDef_t *structDef, const ddlDef_t *ddl, int parentOffset, int searchOffset, int *arrayIndex);
void DDL_Lookup_ClearState(ddlState_t *searchState);
ddlMemberDef_t *DDL_Lookup_FindMemberDefByLName(ddlStructDef_t *structDef, int hashStartIndex, const char *memberNameLowercase);
ddlMemberDef_t *DDL_Lookup_FindMemberDef(const char *memberName, ddlStructDef_t *structDef);
ddlMemberDef_t *DDL_Lookup_MoveToIndex(const ddlState_t *searchState, int arrayIndex, ddlState_t *resultState, int checkValidIndex);
int DDL_Lookup_FindEnumIndexByName(ddlEnumDef_t *enumDef, int hashStartIndex, const char *memberName);
int DDL_Lookup_MoveTo(const ddlState_t *searchState, const char *name, ddlState_t *resultState);
int DDL_Lookup_MoveNext(const ddlState_t *searchState, ddlState_t *resultState);
BOOL DDL_Lookup_MoveToStart(ddlState_t *resultState, ddlDef_t *ddl);

