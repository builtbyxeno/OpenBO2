#include "types.h"
#include "functions.h"

/*
==============
TRACK_scr_parser
==============
*/
void TRACK_scr_parser()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetLineNumInternal
==============
*/
int Scr_GetLineNumInternal(const char *buf, unsigned int sourcePos, const char **startLine, int *col, SourceBufferInfo *binfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_ReadFile_FastFile
==============
*/
char *Scr_ReadFile_FastFile(scriptInstance_t inst, const char *filename, const char *extFilename)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_ReadFile_LoadObj
==============
*/
char *Scr_ReadFile_LoadObj(const char *a1, FsThread a2, scriptInstance_t inst, const char *filename, const char *extFilename)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_ReadFile
==============
*/
char *Scr_ReadFile(scriptInstance_t inst, const char *filename, const char *extFilename, const unsigned __int8 *codePos, bool archive)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_AddSourceBuffer
==============
*/
char *Scr_AddSourceBuffer(char *a1, scriptInstance_t inst, const char *filename, const char *extFilename, unsigned __int8 *codePos, bool archive)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_CopyFormattedLine
==============
*/
void Scr_CopyFormattedLine(char *line, const char *rawLine)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetLineInfo
==============
*/
int Scr_GetLineInfo(const char *buf, unsigned int sourcePos, int *col, char *line, SourceBufferInfo *binfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_PrintSourcePos
==============
*/
void Scr_PrintSourcePos(scriptInstance_t inst, int channel, const char *filename, const char *buf, unsigned int sourcePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_PrintPrevCodePosToBuf
==============
*/
void Scr_PrintPrevCodePosToBuf(scriptInstance_t inst, unsigned __int8 *codePos, unsigned int index, char *buf)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_PrintPrevCodePos
==============
*/
void Scr_PrintPrevCodePos(scriptInstance_t inst, int channel, unsigned __int8 *codePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_PrevCodePosFileName
==============
*/
const char *Scr_PrevCodePosFileName(scriptInstance_t inst, unsigned __int8 *codePos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_PrevCodePosFunctionName
==============
*/
const char *Scr_PrevCodePosFunctionName(scriptInstance_t inst, unsigned __int8 *codePos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_PrevCodePosFileNameMatches
==============
*/
bool Scr_PrevCodePosFileNameMatches(scriptInstance_t inst, unsigned __int8 *codePos, const char *fileName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_PrintPrevCodePosSpreadSheet
==============
*/
void Scr_PrintPrevCodePosSpreadSheet(scriptInstance_t inst, int channel, unsigned __int8 *codePos, bool summary)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetCodePos
==============
*/
void Scr_GetCodePos(scriptInstance_t inst, unsigned __int8 *codePos, unsigned int index, char *outBuf, int outBufLen)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CompileError2
==============
*/
void CompileError2(scriptInstance_t inst, unsigned __int8 *codePos, const char *msg, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RuntimeError
==============
*/
void RuntimeError(scriptInstance_t inst, unsigned __int8 *codePos, unsigned int index, const char *msg, const char *dialogMessage)
{
	UNIMPLEMENTED(__FUNCTION__);
}

