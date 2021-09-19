#include "types.h"
#include "functions.h"

/*
==============
SourceError
==============
*/
void SourceError(source_s *source, char *str, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SourceWarning
==============
*/
void SourceWarning(source_s *source, char *str, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PC_PushIndent
==============
*/
void PC_PushIndent(source_s *source, int type, parseSkip_t skip)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PC_PushScript
==============
*/
void PC_PushScript(source_s *source, script_s *script)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PC_CopyToken
==============
*/
token_s *PC_CopyToken(token_s *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
PC_ReadSourceToken
==============
*/
int PC_ReadSourceToken(source_s *source, token_s *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_UnreadSourceToken
==============
*/
int PC_UnreadSourceToken(source_s *source, token_s *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_ReadDefineParms
==============
*/
int PC_ReadDefineParms(source_s *source, define_s *define, token_s **parms, int maxparms)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_StringizeTokens
==============
*/
int PC_StringizeTokens(token_s *tokens, token_s *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_MergeTokens
==============
*/
int PC_MergeTokens(token_s *t1, token_s *t2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_NameHash
==============
*/
int PC_NameHash(char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_AddDefineToHash
==============
*/
void PC_AddDefineToHash(define_s *define, define_s **definehash)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PC_FindHashedDefine
==============
*/
define_s *PC_FindHashedDefine(define_s **definehash, char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
PC_FindDefineParm
==============
*/
int PC_FindDefineParm(define_s *define, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_FreeDefine
==============
*/
void PC_FreeDefine(define_s *define)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PC_ExpandBuiltinDefine
==============
*/
int PC_ExpandBuiltinDefine(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_ExpandDefine
==============
*/
int PC_ExpandDefine(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_ConvertPath
==============
*/
void PC_ConvertPath(char *path)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PC_Directive_include
==============
*/
int PC_Directive_include(source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_ReadLine
==============
*/
int PC_ReadLine(token_s *token, source_s *source, bool expandDefines)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_Directive_undef
==============
*/
/*int PC_Directive_undef@<eax>(source_s *a1@<edx>, token_s *a2@<ecx>, source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
PC_CopyDefine
==============
*/
define_s *PC_CopyDefine(source_s *source, define_s *define)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
PC_AddGlobalDefinesToSource
==============
*/
void PC_AddGlobalDefinesToSource(source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PC_Directive_if_def
==============
*/
/*int PC_Directive_if_def@<eax>(source_s *a1@<edx>, token_s *a2@<ecx>, source_s *source, int type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
PC_Directive_ifdef
==============
*/
/*int PC_Directive_ifdef@<eax>(source_s *a1@<edx>, token_s *a2@<ecx>, source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
PC_Directive_ifndef
==============
*/
/*int PC_Directive_ifndef@<eax>(source_s *a1@<edx>, token_s *a2@<ecx>, source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
PC_Directive_else
==============
*/
int PC_Directive_else(source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_Directive_endif
==============
*/
int PC_Directive_endif(source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_OperatorPriority
==============
*/
int PC_OperatorPriority(int op)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_EvaluateTokens
==============
*/
int PC_EvaluateTokens(source_s *source, token_s *tokens, int *intvalue, long double *floatvalue, int integer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_Evaluate
==============
*/
int PC_Evaluate(source_s *source, int *intvalue, long double *floatvalue, int integer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_DollarEvaluate
==============
*/
int PC_DollarEvaluate(source_s *source, int *intvalue, long double *floatvalue, int integer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_Directive_elif
==============
*/
int PC_Directive_elif(source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_Directive_if
==============
*/
int PC_Directive_if(source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_Directive_line
==============
*/
int PC_Directive_line(source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_Directive_error
==============
*/
int PC_Directive_error(source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_Directive_pragma
==============
*/
int PC_Directive_pragma(source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UnreadSignToken
==============
*/
void UnreadSignToken(source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PC_Directive_eval
==============
*/
int PC_Directive_eval(source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_Directive_evalfloat
==============
*/
int PC_Directive_evalfloat(source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_ReadDirective
==============
*/
int PC_ReadDirective(source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_DollarDirective_evalint
==============
*/
int PC_DollarDirective_evalint(source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_DollarDirective_evalfloat
==============
*/
int PC_DollarDirective_evalfloat(source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_ReadDollarDirective
==============
*/
int PC_ReadDollarDirective(source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LoadSourceFile
==============
*/
source_s *LoadSourceFile(const char *filename)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
FreeSource
==============
*/
void FreeSource(source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PC_FreeSourceHandle
==============
*/
int PC_FreeSourceHandle(int handle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_ReadLineHandle
==============
*/
/*int PC_ReadLineHandle@<eax>(source_s *a1@<edx>, int handle, pc_token_s *pc_token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
PC_UnreadLastTokenHandle
==============
*/
void PC_UnreadLastTokenHandle(int handle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PC_SourceFileAndLine
==============
*/
int PC_SourceFileAndLine(int handle, char *filename, int *line)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_ReadToken
==============
*/
int PC_ReadToken(source_s *source, token_s *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_CheckTokenString
==============
*/
int PC_CheckTokenString(source_s *source, char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_ReadTokenHandle
==============
*/
int PC_ReadTokenHandle(int handle, pc_token_s *pc_token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PC_Directive_define
==============
*/
/*int PC_Directive_define@<eax>(source_s *a1@<edx>, token_s *a2@<ecx>, source_s *source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
PC_DefineFromString
==============
*/
define_s *PC_DefineFromString(const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
PC_LoadSourceHandle
==============
*/
int PC_LoadSourceHandle(const char *filename, const char **builtinDefines)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

