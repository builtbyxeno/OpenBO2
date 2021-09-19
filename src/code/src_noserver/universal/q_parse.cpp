#include "types.h"
#include "functions.h"

/*
==============
TRACK_q_parse
==============
*/
void TRACK_q_parse()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GetParseThreadInfo
==============
*/
ParseThreadInfo *Com_GetParseThreadInfo()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_InitParse
==============
*/
void Com_InitParse()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_BeginParseSession
==============
*/
void Com_BeginParseSession(const char *filename)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_EndParseSession
==============
*/
void Com_EndParseSession()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_ResetParseSessions
==============
*/
void Com_ResetParseSessions()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_SetSpaceDelimited
==============
*/
void Com_SetSpaceDelimited(int spaceDelimited)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_SetKeepStringQuotes
==============
*/
void Com_SetKeepStringQuotes(int keepStringQuotes)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_SetCSV
==============
*/
void Com_SetCSV(int csv)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_SetParseNegativeNumbers
==============
*/
void Com_SetParseNegativeNumbers(int negativeNumbers)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GetCurrentParseLine
==============
*/
int Com_GetCurrentParseLine()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_SetScriptErrorPrefix
==============
*/
void Com_SetScriptErrorPrefix(const char *prefix)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GetScriptErrorPrefix
==============
*/
const GfxViewParms *Com_GetScriptErrorPrefix()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_SetScriptWarningPrefix
==============
*/
void Com_SetScriptWarningPrefix(const char *prefix)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GetScriptWarningPrefix
==============
*/
const GfxViewParms *Com_GetScriptWarningPrefix()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_ScriptErrorDrop
==============
*/
void Com_ScriptErrorDrop(const char *msg, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_ScriptError
==============
*/
void Com_ScriptError(const char *msg, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_ScriptWarning
==============
*/
void Com_ScriptWarning(const char *msg, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_UngetToken
==============
*/
void Com_UngetToken()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_ParseSetMark
==============
*/
void Com_ParseSetMark(const char **text, com_parse_mark_t *mark)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_ParseReturnToMark
==============
*/
void Com_ParseReturnToMark(const char **text, com_parse_mark_t *mark)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_Compress
==============
*/
int Com_Compress(char *data_p)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_GetLastTokenPos
==============
*/
const char *Com_GetLastTokenPos()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_ParseCSV
==============
*/
parseInfo_t *Com_ParseCSV(const char **data_p, int allowLineBreaks)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_ParseExt
==============
*/
parseInfo_t *Com_ParseExt(const char **data_p, int allowLineBreaks)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_Parse
==============
*/
parseInfo_t *Com_Parse(const char **data_p)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_ParseOnLine
==============
*/
parseInfo_t *Com_ParseOnLine(const char **data_p)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_GetTokenType
==============
*/
ParseTokenType Com_GetTokenType()
{
	UNIMPLEMENTED(__FUNCTION__);
	ParseTokenType tmp;
	return tmp;
}

/*
==============
Com_MatchToken
==============
*/
int Com_MatchToken(const char **buf_p, const char *match, int warning)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_SkipBracedSection
==============
*/
int Com_SkipBracedSection(const char **program, unsigned int startDepth, const int iMaxNesting)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_SkipRestOfLine
==============
*/
void Com_SkipRestOfLine(const char **data)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_GetArgCountOnLine
==============
*/
int Com_GetArgCountOnLine(const char **data_p)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_ParseRestOfLine
==============
*/
char *Com_ParseRestOfLine(const char **data_p)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Com_ParseFloat
==============
*/
float Com_ParseFloat(const char **buf_p)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_ParseFloatOnLine
==============
*/
float Com_ParseFloatOnLine(const char **buf_p)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_ParseInt
==============
*/
int Com_ParseInt(const char **buf_p)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_ParseIntOnLine
==============
*/
int Com_ParseIntOnLine(const char **buf_p)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_ParseUIntOnLine
==============
*/
unsigned int Com_ParseUIntOnLine(const char **buf_p)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_Parse1DMatrix
==============
*/
void Com_Parse1DMatrix(const char **buf_p, int x, float *m)
{
	UNIMPLEMENTED(__FUNCTION__);
}

