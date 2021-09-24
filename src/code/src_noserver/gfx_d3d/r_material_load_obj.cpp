#include "types.h"

/*
==============
Material_GetTypeByPrefix
==============
*/
int Material_GetTypeByPrefix(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_GetTypeByTechsetPrefix
==============
*/
int Material_GetTypeByTechsetPrefix(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_GetPrefix
==============
*/
const char *Material_GetPrefix(unsigned int materialType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_DrawSurfStandardPrepassSortKey
==============
*/
int R_DrawSurfStandardPrepassSortKey(const Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_HashVertexDecl
==============
*/
unsigned int Material_HashVertexDecl(const MaterialStreamRouting *routingData, int streamCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_AllocVertexDecl
==============
*/
MaterialVertexDeclaration *Material_AllocVertexDecl(MaterialStreamRouting *routingData, int streamCount, bool *existing)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_RegisterLiteral
==============
*/
const float *Material_RegisterLiteral(const vec4_t *literal)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_StringFromHash
==============
*/
const char *Material_StringFromHash(unsigned int hash)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_RegisterString
==============
*/
const char *Material_RegisterString(const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_HashStateMap
==============
*/
char Material_HashStateMap(const char *name, unsigned int *foundHashIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MaterialTechnique_FindHashLocation
==============
*/
bool MaterialTechnique_FindHashLocation(const char *name, unsigned int *foundHashIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_SetTechnique
==============
*/
void Material_SetTechnique(const char *name, MaterialTechnique *technique)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_ParseValueForState
==============
*/
const MtlStateMapBitName *Material_ParseValueForState(const char **text, const MtlStateMapBitName *bitNames)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_ParseRuleSetConditionTest
==============
*/
MtlParseSuccess Material_ParseRuleSetConditionTest(const char **text, const char *token, MaterialStateMapRule *rule)
{
	UNIMPLEMENTED(__FUNCTION__);
	MtlParseSuccess tmp;
	return tmp;
}

/*
==============
Material_ParseRuleSetCondition
==============
*/
MtlParseSuccess Material_ParseRuleSetCondition(const char **text, const char *token, MaterialStateMapRule *rule)
{
	UNIMPLEMENTED(__FUNCTION__);
	MtlParseSuccess tmp;
	return tmp;
}

/*
==============
Material_ParseRuleSetValue
==============
*/
bool Material_ParseRuleSetValue(const char **text, const char *token, const MtlStateMapBitGroup *stateSet, MaterialStateMapRule *rule)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_AssembleRuleSet
==============
*/
MaterialStateMapRuleSet *Material_AssembleRuleSet(int ruleCount, const MaterialStateMapRule *rules)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_ParseRuleSet
==============
*/
bool Material_ParseRuleSet(const char **text, const char *ruleSetName, const MtlStateMapBitGroup *stateSet, MaterialStateMapRuleSet **ruleSet)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_ParseStateMap
==============
*/
bool Material_ParseStateMap(const char **text, MaterialStateMap *stateMap)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_LoadStateMap
==============
*/
MaterialStateMap *Material_LoadStateMap(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_RegisterStateMap
==============
*/
MaterialStateMap *Material_RegisterStateMap(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_LoadPassStateMap
==============
*/
bool Material_LoadPassStateMap(const char **text, MaterialStateMap **stateMap)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_ParseIndex
==============
*/
bool Material_ParseIndex(const char **text, int indexCount, int *index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_NameForStreamDest
==============
*/
const char *Material_NameForStreamDest(unsigned __int8 dest)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_StreamDestForName
==============
*/
bool Material_StreamDestForName(const char **text, const char *destName, unsigned __int8 *dest)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_StreamSourceForName
==============
*/
bool Material_StreamSourceForName(const char **text, const char *sourceName, unsigned __int8 *source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_ResourceDestForStreamDest
==============
*/
bool Material_ResourceDestForStreamDest(unsigned __int8 streamDest, ShaderVaryingDef *inputTable, unsigned int inputCount, unsigned __int8 *resourceDest)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_LoadPassVertexDecl
==============
*/
bool Material_LoadPassVertexDecl(const char **text, ShaderVaryingDef *inputTable, unsigned int inputCount, MaterialPass *pass)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_ParseIndexRange
==============
*/
bool Material_ParseIndexRange(const char **text, unsigned int arrayCount, ShaderIndexRange *indexRange)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_ParseArrayOffset
==============
*/
bool Material_ParseArrayOffset(const char **text, int arrayCount, int arrayStride, int *offset)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_CodeSamplerSource_r
==============
*/
bool Material_CodeSamplerSource_r(const char **text, int offset, const CodeSamplerSource *sourceTable, ShaderArgumentSource *argSource)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_ParseSamplerSource
==============
*/
bool Material_ParseSamplerSource(const char **text, ShaderArgumentSource *argSource)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_DefaultSamplerSourceFromTable
==============
*/
bool Material_DefaultSamplerSourceFromTable(const char *constantName, const ShaderIndexRange *indexRange, const CodeSamplerSource *sourceTable, ShaderArgumentSource *argSource)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_ParseVector
==============
*/
bool Material_ParseVector(const char **text, int elemCount, vec4_t *vector)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_ParseLiteral
==============
*/
bool Material_ParseLiteral(const char **text, const char *token, vec4_t *literal)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_ParseCodeConstantSource_r
==============
*/
bool Material_ParseCodeConstantSource_r(MaterialShaderType shaderType, const char **text, int offset, const CodeConstantSource *sourceTable, ShaderArgumentSource *argSource)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_ParseConstantSource
==============
*/
bool Material_ParseConstantSource(MaterialShaderType shaderType, const char **text, ShaderArgumentSource *argSource)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_DefaultConstantSourceFromTable
==============
*/
char Material_DefaultConstantSourceFromTable(MaterialShaderType shaderType, const char *constantName, const ShaderIndexRange *indexRange, const CodeConstantSource *sourceTable, ShaderArgumentSource *argSource)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_UnknownShaderworksConstantSource
==============
*/
bool Material_UnknownShaderworksConstantSource(MaterialShaderType shaderType, const char *constantName, const ShaderIndexRange *indexRange, ShaderArgumentSource *argSource)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_ElemCountForParamName
==============
*/
unsigned int Material_ElemCountForParamName(const char *shaderName, const ShaderUniformDef *paramTable, unsigned int paramCount, const char *name, ShaderParamType *paramType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_ParseArgumentSource
==============
*/
bool Material_ParseArgumentSource(MaterialShaderType shaderType, const char **text, const char *shaderName, ShaderParamType paramType, ShaderArgumentSource *argSource)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_DefaultArgumentSource
==============
*/
bool Material_DefaultArgumentSource(MaterialShaderType shaderType, const char *constantName, ShaderParamType paramType, const ShaderIndexRange *indexRange, ShaderArgumentSource *argSource)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetParameterDefArray
==============
*/
unsigned int R_SetParameterDefArray(ID3D11ShaderReflectionConstantBuffer *constantTable, unsigned __int16 bufferIndex, unsigned int constantIndex, ShaderUniformDef *paramDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_PrepareToParseShaderArguments
==============
*/
unsigned int Material_PrepareToParseShaderArguments(ID3D11ShaderReflection *reflector, _D3D11_SHADER_DESC *shaderDesc, ShaderUniformDef *paramTable)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_CompareShaderArgumentsForCombining
==============
*/
int Material_CompareShaderArgumentsForCombining(const void *e0, const void *e1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_CombineShaderArguments
==============
*/
unsigned int Material_CombineShaderArguments(unsigned int usedCount, MaterialShaderArgument *localArgs)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_SetShaderArguments
==============
*/
bool Material_SetShaderArguments(unsigned int usedCount, MaterialShaderArgument *localArgs, unsigned int argLimit, unsigned int *argCount, MaterialShaderArgument *args)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_GetShaderArgumentDest
==============
*/
ShaderUniformDef *Material_GetShaderArgumentDest(const char *paramName, unsigned int paramIndex, ShaderUniformDef *paramTable, unsigned int paramCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_GetArgUpdateFrequency
==============
*/
MaterialUpdateFrequency Material_GetArgUpdateFrequency(const MaterialShaderArgument *arg)
{
	UNIMPLEMENTED(__FUNCTION__);
	MaterialUpdateFrequency tmp;
	return tmp;
}

/*
==============
MaterialAddShaderArgument
==============
*/
bool MaterialAddShaderArgument(const char *shaderName, const char *paramName, MaterialShaderArgument *arg, char (*registerUsage)[64])
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_AddShaderArgumentFromLiteral
==============
*/
bool Material_AddShaderArgumentFromLiteral(const char *shaderName, const char *paramName, unsigned __int16 type, const float *literal, ShaderUniformDef *dest, MaterialShaderArgument *arg, char (*registerUsage)[64])
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_AddShaderArgumentFromCodeConst
==============
*/
bool Material_AddShaderArgumentFromCodeConst(const char *shaderName, const char *paramName, unsigned __int16 type, unsigned int codeIndex, unsigned int offset, ShaderUniformDef *dest, MaterialShaderArgument *arg, char (*registerUsage)[64])
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_AddShaderArgumentFromMaterial
==============
*/
bool Material_AddShaderArgumentFromMaterial(const char *shaderName, const char *paramName, unsigned __int16 type, const char *name, ShaderUniformDef *dest, MaterialShaderArgument *arg, char (*registerUsage)[64])
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_AddShaderArgument
==============
*/
bool __cdecl Material_AddShaderArgument(const char *shaderName, MaterialShaderType shaderType, ShaderArgumentSource *argSource, const ShaderArgumentDest *argDest, ShaderUniformDef *paramTable, unsigned int paramCount, unsigned int *usedCount, MaterialShaderArgument *argTable)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_ParseShaderArguments
==============
*/
bool Material_ParseShaderArguments(const char **text, const char *shaderName, MaterialShaderType shaderType, ShaderUniformDef *paramTable, unsigned int paramCount, unsigned __int16 *techFlags, unsigned int argLimit, unsigned int *argCount, MaterialShaderArgument *args)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_LoadVertexShader
==============
*/
MaterialVertexShader *Material_LoadVertexShader(const char *shaderName, ShaderStats *stats)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_LoadPixelShader
==============
*/
MaterialPixelShader *Material_LoadPixelShader(const char *shaderName, int shaderVersion, ShaderStats *stats)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_GetVertexShaderHashIndex
==============
*/
bool Material_GetVertexShaderHashIndex(const char *shaderName, unsigned int *foundHashIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_RegisterVertexShader
==============
*/
MaterialVertexShader *Material_RegisterVertexShader(unsigned int *a1, const char *a2, const char *shaderName, unsigned __int8 shaderVersion, ShaderStats *stats)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_GetPixelShaderHashIndex
==============
*/
bool Material_GetPixelShaderHashIndex(const char *shaderName, unsigned int *foundHashIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_RegisterPixelShader
==============
*/
MaterialPixelShader *Material_RegisterPixelShader(unsigned int *a1, const char *a2, const char *shaderName, unsigned __int8 shaderVersion, ShaderStats *stats)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_GetStreamDestForSemantic
==============
*/
unsigned __int8 Material_GetStreamDestForSemantic(const _D3D11_SIGNATURE_PARAMETER_DESC *semantic)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_SetPassShaderArguments_DX
==============
*/
bool Material_SetPassShaderArguments_DX(const char **text, const char *shaderName, MaterialShaderType shaderType, const unsigned int *program, unsigned int programSize, unsigned __int16 *techFlags, ShaderParameterSet *paramSet, unsigned int argLimit, unsigned int *argCount, MaterialShaderArgument *args)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_LoadPassVertexShader
==============
*/
bool Material_LoadPassVertexShader(const char **text, unsigned __int16 *techFlags, ShaderParameterSet *paramSet, MaterialPass *pass, unsigned int argLimit, unsigned int *argCount, MaterialShaderArgument *args)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_LoadDeclTypes
==============
*/
bool Material_LoadDeclTypes(const char **text, MaterialPass *pass)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_LoadPassPixelShader
==============
*/
bool Material_LoadPassPixelShader(const char **text, unsigned __int16 *techFlags, ShaderParameterSet *paramSet, MaterialPass *pass, unsigned int argLimit, unsigned int *argCount, MaterialShaderArgument *args)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_ValidateShaderLinkage
==============
*/
bool Material_ValidateShaderLinkage(const ShaderVaryingDef *vertexOutputs, unsigned int vertexOutputCount, const ShaderVaryingDef *pixelInputs, unsigned int pixelInputCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_CompareShaderArgumentsForRuntime
==============
*/
int Material_CompareShaderArgumentsForRuntime(const void *e0, const void *e1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_CountArgsWithUpdateFrequency
==============
*/
unsigned __int8 Material_CountArgsWithUpdateFrequency(MaterialUpdateFrequency updateFreq, const MaterialShaderArgument *args, unsigned int argCount, unsigned int *firstArg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_LoadPass
==============
*/
bool Material_LoadPass(const char **text, unsigned __int16 *techFlags, MaterialPass *pass, MaterialStateMap **stateMap, int materialType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_LoadTechnique
==============
*/
MaterialTechnique *Material_LoadTechnique(const char *name, int materialType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_RegisterTechnique
==============
*/
MaterialTechnique *Material_RegisterTechnique(const char *name, int materialType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_IgnoreTechnique
==============
*/
bool Material_IgnoreTechnique(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_TechniqueTypeForName
==============
*/
unsigned __int8 Material_TechniqueTypeForName(const char *name, bool *inUse)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_HasAlphaTest
==============
*/
bool Material_HasAlphaTest(const Material *mtl)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_GetTechniqueSetDrawRegion
==============
*/
void Material_GetTechniqueSetDrawRegion(MaterialTechniqueSet* techniqueSet)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_SetMaterialDrawRegion
==============
*/
void Material_SetMaterialDrawRegion(Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_LoadTechniqueSet
==============
*/
MaterialTechniqueSet *Material_LoadTechniqueSet(const char *fullName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_RemapStateBits
==============
*/
void Material_RemapStateBits(const Material *material, unsigned int toolFlags, const MaterialStateMap *stateMap, const unsigned int *refStateBits, unsigned int *stateBitsOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_AddStateBitsArrayToTable
==============
*/
unsigned __int8 Material_AddStateBitsArrayToTable(const unsigned int (*stateBitsForPass)[2], unsigned int passCount, unsigned int (*stateBitsTable)[2], unsigned int *stateBitsCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_GetCullFlags
==============
*/
unsigned int Material_GetCullFlags(Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_GetCullShadowFlags
==============
*/
unsigned int Material_GetCullShadowFlags(Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_GetDecalFlags
==============
*/
unsigned int Material_GetDecalFlags(const Material *mtl)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_GetWritesDepthFlags
==============
*/
unsigned int Material_GetWritesDepthFlags(const Material *mtl)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_GetUsesDepthBufferFlags
==============
*/
unsigned int Material_GetUsesDepthBufferFlags(const Material *mtl)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_GetUsesStencilBufferFlags
==============
*/
unsigned int Material_GetUsesStencilBufferFlags(const Material *mtl)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_UpdateTechniqueFlags
==============
*/
void Material_UpdateTechniqueFlags(Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_SetStateBits
==============
*/
void Material_SetStateBits(Material *material, unsigned int (*stateBitsTable)[2], unsigned int stateBitsCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_BuildStateBitsTable
==============
*/
void Material_BuildStateBitsTable(Material *material, unsigned int toolFlags, const unsigned int *refStateBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_ValidatePassArguments
==============
*/
char Material_ValidatePassArguments(const Material *mtl, const char *techniqueName, unsigned int argCount, const MaterialShaderArgument *args)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_Validate
==============
*/
char Material_Validate(const Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CompareRawMaterialTextures
==============
*/
int CompareRawMaterialTextures(const void *e0, const void *e1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CompareHashedMaterialTextures
==============
*/
int CompareHashedMaterialTextures(const void *e0, const void *e1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_FinishLoadingInstance
==============
*/
bool Material_FinishLoadingInstance(const MaterialRaw *mtlRaw, const char *name, const char *techniqueSetVertDeclPrefix, MaterialTechniqueSet **techniqueSet, unsigned int materialType, int imageTrack)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_GetLayeredStateBits
==============
*/
void Material_GetLayeredStateBits(const Material **layerMtl, unsigned int layerCount, unsigned int techType, unsigned int *stateBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_CreateLayeredStateBitsTable
==============
*/
unsigned int Material_CreateLayeredStateBitsTable(const Material **layerMtl, unsigned int layerCount, const MaterialTechniqueSet *techSet, unsigned __int8 *stateBitsEntry, unsigned int (*stateBitsTable)[2])
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_CreateLayered
==============
*/
Material *Material_CreateLayered(const char *name, const Material **layerMtl, unsigned int layerCount, MaterialTechniqueSet *techSet)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_HasNormalMap
==============
*/
bool Material_HasNormalMap(const Material *mtl)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_AppendTechniqueSetName
==============
*/
unsigned int Material_AppendTechniqueSetName(char *name, unsigned int nameLen, const char *append, char lyrToken)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_GetLayeredTechniqueSetName
==============
*/
const LayeredTechniqueSetName *Material_GetLayeredTechniqueSetName(const char *techSetName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_SetGameFlags
==============
*/
void Material_SetGameFlags(Material* material, const MaterialRaw* mtlRaw)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_LoadRaw
==============
*/
Material *Material_LoadRaw(const MaterialRaw *mtlRaw, unsigned int materialType, const char *matname, int imageTrack)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_GetInfo
==============
*/
void Material_GetInfo(Material *handle, MaterialInfo *matInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_GetVertexShaderName
==============
*/
void Material_GetVertexShaderName(char *dest, const MaterialPass *pass, int destsize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_ComparePixelConsts
==============
*/
int Material_ComparePixelConsts(const Material *mtl0, const Material *mtl1, unsigned __int8 techType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_CompareBySortKeyAndTechnique
==============
*/
int Material_CompareBySortKeyAndTechnique(const Material *mtl0, const Material *mtl1, const MaterialTechniqueSet **techSet, const MaterialTechnique **techniqueLit, const MaterialTechnique **techniqueEmissive)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_Compare
==============
*/
bool Material_Compare(const Material *mtl0, const Material *mtl1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_BuildScritableConstantArray
==============
*/
void R_BuildScritableConstantArray(ScriptableConstant *array, int arraySize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FindScriptableConstantSource_ByHash
==============
*/
char R_FindScriptableConstantSource_ByHash(int a1, ScriptableConstant *a2, unsigned int hash, unsigned __int8 *dest)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_FindScriptableConstantSource_ByName
==============
*/
char R_FindScriptableConstantSource_ByName(const char *name, unsigned __int8 *dest)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_FindScriptableConstantName_BySource
==============
*/
const char *R_FindScriptableConstantName_BySource(int a1, ScriptableConstant *a2, unsigned __int8 src)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_RegisterLayeredTechniqueSet
==============
*/
MaterialTechniqueSet *Material_RegisterLayeredTechniqueSet(const Material **mtl, unsigned int layerCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_LoadLayered
==============
*/
Material *Material_LoadLayered(const char *assetName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_Load
==============
*/
Material *Material_Load(LocalClientNum_t a1, const char *fullAssetName, int imageTrack)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_SortInternal
==============
*/
void Material_SortInternal(Material **sortedMaterials, unsigned int materialCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_Sort
==============
*/
void Material_Sort()
{
	UNIMPLEMENTED(__FUNCTION__);
}

