#include "types.h"

/*
==============
PS_CreatePunctuationTable
==============
*/
void PS_CreatePunctuationTable(script_s *script, punctuation_s *punctuations)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ScriptError
==============
*/
void ScriptError(script_s *script, const char *str, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ScriptWarning
==============
*/
void ScriptWarning(script_s *script, const char *str, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PS_ReadWhiteSpace
==============
*/
int PS_ReadWhiteSpace(script_s *script)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PS_ReadEscapeCharacter
==============
*/
int PS_ReadEscapeCharacter(script_s *script, char *ch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PS_ReadString
==============
*/
int PS_ReadString(script_s *script, token_s *token, int quote)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PS_ReadName
==============
*/
int PS_ReadName(script_s *script, token_s *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NumberValue
==============
*/
void NumberValue(char *string, int subtype, unsigned int *intvalue, long double *floatvalue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PS_ReadNumber
==============
*/
int PS_ReadNumber(script_s *script, token_s *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PS_ReadPunctuation
==============
*/
int PS_ReadPunctuation(script_s *script, token_s *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PS_ReadPrimitive
==============
*/
int PS_ReadPrimitive(script_s *script, token_s *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PS_ReadToken
==============
*/
int PS_ReadToken(script_s *script, token_s *token)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
StripDoubleQuotes
==============
*/
void StripDoubleQuotes(char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EndOfScript
==============
*/
BOOL EndOfScript(script_s *script)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LoadScriptFile
==============
*/
script_s *LoadScriptFile(const char *filename)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LoadScriptMemory
==============
*/
script_s *LoadScriptMemory(const char *ptr, int length, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
FreeScript
==============
*/
void FreeScript(script_s *script)
{
	UNIMPLEMENTED(__FUNCTION__);
}

