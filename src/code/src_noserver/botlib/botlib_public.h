#pragma once

#include "types.h"

//t6/code/src_noserver/botlib/l_memory.cpp
char *GetMemory(unsigned int size);
char *GetClearedMemory(unsigned int size);
void FreeMemory(void *ptr);

//t6/code/src_noserver/botlib/l_precomp.cpp
void SourceError(source_s *source, char *str, ...);
void SourceWarning(source_s *source, char *str, ...);
void PC_PushIndent(source_s *source, int type, parseSkip_t skip);
void PC_PushScript(source_s *source, script_s *script);
token_s *PC_CopyToken(token_s *token);
int PC_ReadSourceToken(source_s *source, token_s *token);
int PC_UnreadSourceToken(source_s *source, token_s *token);
int PC_ReadDefineParms(source_s *source, define_s *define, token_s **parms, int maxparms);
int PC_StringizeTokens(token_s *tokens, token_s *token);
int PC_MergeTokens(token_s *t1, token_s *t2);
int PC_NameHash(char *name);
void PC_AddDefineToHash(define_s *define, define_s **definehash);
define_s *PC_FindHashedDefine(define_s **definehash, char *name);
int PC_FindDefineParm(define_s *define, const char *name);
void PC_FreeDefine(define_s *define);
int PC_ExpandBuiltinDefine(source_s *source, token_s *deftoken, define_s *define, token_s **firsttoken, token_s **lasttoken);
int PC_ExpandDefine(source_s *source, token_s *deftoken, define_s *define, token_s **firsttoken, token_s **lasttoken);
void PC_ConvertPath(char *path);
int PC_Directive_include(source_s *source);
int PC_ReadLine(token_s *token, source_s *source, bool expandDefines);
int PC_Directive_undef(source_s *a1, token_s *a2, source_s *source);
define_s *PC_CopyDefine(source_s *source, define_s *define);
void PC_AddGlobalDefinesToSource(source_s *source);
int PC_Directive_if_def(source_s *a1, token_s *a2, source_s *source, int type);
int PC_Directive_ifdef(source_s *a1, token_s *a2, source_s *source);
int PC_Directive_ifndef(source_s *a1, token_s *a2, source_s *source);
int PC_Directive_else(source_s *source);
int PC_Directive_endif(source_s *source);
int PC_OperatorPriority(int op);
int PC_EvaluateTokens(source_s *source, token_s *tokens, int *intvalue, long double *floatvalue, int integer);
int PC_Evaluate(source_s *source, int *intvalue, long double *floatvalue, int integer);
int PC_DollarEvaluate(source_s *source, int *intvalue, long double *floatvalue, int integer);
int __cdecl PC_Directive_elif(source_s *source);
int PC_Directive_if(source_s *source);
int PC_Directive_line(source_s *source);
int PC_Directive_error(source_s *source);
int PC_Directive_pragma(source_s *source);
void UnreadSignToken(source_s *source);
int PC_Directive_eval(int a1, source_s *source);
int __cdecl PC_Directive_evalfloat(source_s *source);
int PC_ReadDirective(source_s *source);
int PC_DollarDirective_evalint(source_s *source);
int PC_DollarDirective_evalfloat(source_s *source);
int PC_ReadDollarDirective(source_s *source);
source_s *LoadSourceFile(const char *filename);
void FreeSource(source_s *source);
int PC_FreeSourceHandle(int handle);
int PC_ReadLineHandle(source_s *a1, int handle, pc_token_s *pc_token);
void PC_UnreadLastTokenHandle(int handle);
int PC_SourceFileAndLine(int handle, char *filename, int *line);
int PC_ReadToken(source_s *source, token_s *token);
int PC_CheckTokenString(source_s *source, char *string);
int PC_ReadTokenHandle(int handle, pc_token_s *pc_token);
void PC_Directive_define(source_s *);
define_s *PC_DefineFromString(const char *string);
int PC_LoadSourceHandle(const char *filename, const char **builtinDefines);

//t6/code/src_noserver/botlib/l_script.cpp
void PS_CreatePunctuationTable(script_s *script, punctuation_s *punctuations);
void ScriptError(script_s *script, const char *str, ...);
void ScriptWarning(script_s *script, const char *str, ...);
int PS_ReadWhiteSpace(script_s *script);
int PS_ReadEscapeCharacter(script_s *script, char *ch);
int PS_ReadString(script_s *script, token_s *token, int quote);
int PS_ReadName(script_s *script, token_s *token);
void NumberValue(char *string, int subtype, unsigned int *intvalue, long double *floatvalue);
int PS_ReadNumber(script_s *script, token_s *token);
int PS_ReadPunctuation(script_s *script, token_s *token);
int PS_ReadPrimitive(script_s *script, token_s *token);
int PS_ReadToken(script_s *script, token_s *token);
void StripDoubleQuotes(char *string);
BOOL EndOfScript(script_s *script);
script_s *LoadScriptFile(const char *filename);
script_s *LoadScriptMemory(const char *ptr, int length, const char *name);
void FreeScript(script_s *script);

