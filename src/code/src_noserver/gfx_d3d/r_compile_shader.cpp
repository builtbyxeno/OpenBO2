#include "types.h"
#include "functions.h"

/*
==============
Material_EmitShaderString
==============
*/
void Material_EmitShaderString(GfxAssembledShaderText *prog, const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_AddShaderFile
==============
*/
void Material_AddShaderFile(GfxAssembledShaderText *prog, const char *shaderFileName, unsigned int srcLine)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_FindCachedShaderText
==============
*/
char Material_FindCachedShaderText(const char *filename, const char **data, unsigned int *byteCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_FileIncludeFileAndLineNumber
==============
*/
void Material_FileIncludeFileAndLineNumber(GfxAssembledShaderText *prog, const char *errorMessage, const char **fileName, unsigned int *lineNumber)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_PreLoadSingleShaderText
==============
*/
bool Material_PreLoadSingleShaderText(const char *filename, const char *subdir, GfxCachedShaderText *cached)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_CachedShaderTextLess
==============
*/
bool Material_CachedShaderTextLess(const GfxCachedShaderText *cached0, const GfxCachedShaderText *cached1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_IncludeShader
==============
*/
bool Material_IncludeShader(GfxAssembledShaderText *prog, const char *includeName, bool isInLibDir)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_GenerateShaderString_r
==============
*/
bool Material_GenerateShaderString_r(GfxAssembledShaderText *prog, const char *shaderName, const char *file)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_GenerateShaderString
==============
*/
unsigned int Material_GenerateShaderString(GfxAssembledShaderText *prog, const char *shaderName, const char *shaderType, char *shaderString, int sizeofShaderString)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_CompileShader
==============
*/
ID3D10Blob *Material_CompileShader(const char *shaderName, const char *shaderType, const char *entryPoint, const char *target, ShaderStats *stats, unsigned int *shaderChecksum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

