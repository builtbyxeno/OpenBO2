#include "types.h"
#include "functions.h"

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
MaterialVertexDeclaration *Material_AllocVertexDecl(
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
MtlParseSuccess Material_ParseRuleSetConditionTest(
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
MtlParseSuccess Material_ParseRuleSetCondition(
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
bool Material_ParseRuleSetValue(
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
bool Material_ParseRuleSet(
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
bool Material_ResourceDestForStreamDest(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_LoadPassVertexDecl
==============
*/
bool Material_LoadPassVertexDecl(
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
bool Material_CodeSamplerSource_r(
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
bool Material_DefaultSamplerSourceFromTable(
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
bool Material_ParseCodeConstantSource_r(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_ParseConstantSource
==============
*/
bool Material_ParseConstantSource(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_DefaultConstantSourceFromTable
==============
*/
char Material_DefaultConstantSourceFromTable(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_UnknownShaderworksConstantSource
==============
*/
bool Material_UnknownShaderworksConstantSource(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_ElemCountForParamName
==============
*/
unsigned int Material_ElemCountForParamName(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_ParseArgumentSource
==============
*/
bool Material_ParseArgumentSource(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_DefaultArgumentSource
==============
*/
bool Material_DefaultArgumentSource(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetParameterDefArray
==============
*/
unsigned int R_SetParameterDefArray(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_PrepareToParseShaderArguments
==============
*/
unsigned int Material_PrepareToParseShaderArguments(
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
bool Material_SetShaderArguments(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_GetShaderArgumentDest
==============
*/
ShaderUniformDef *Material_GetShaderArgumentDest(
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
bool MaterialAddShaderArgument(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_AddShaderArgumentFromLiteral
==============
*/
bool Material_AddShaderArgumentFromLiteral(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_AddShaderArgumentFromCodeConst
==============
*/
bool Material_AddShaderArgumentFromCodeConst(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_AddShaderArgumentFromMaterial
==============
*/
bool Material_AddShaderArgumentFromMaterial(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_AddShaderArgument
==============
*/
/*bool Material_AddShaderArgument@<al>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
Material_ParseShaderArguments
==============
*/
bool Material_ParseShaderArguments(
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
/*MaterialVertexShader *Material_RegisterVertexShader@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

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
/*MaterialPixelShader *Material_RegisterPixelShader@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

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
bool Material_SetPassShaderArguments_DX(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_LoadPassVertexShader
==============
*/
bool Material_LoadPassVertexShader(
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
bool Material_LoadPassPixelShader(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_ValidateShaderLinkage
==============
*/
bool Material_ValidateShaderLinkage(
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
unsigned __int8 Material_CountArgsWithUpdateFrequency(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_LoadPass
==============
*/
bool Material_LoadPass(
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
void Material_GetTechniqueSetDrawRegion
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
void Material_RemapStateBits(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_AddStateBitsArrayToTable
==============
*/
unsigned __int8 Material_AddStateBitsArrayToTable(
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
void Material_SetStateBits(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_BuildStateBitsTable
==============
*/
void Material_BuildStateBitsTable(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_ValidatePassArguments
==============
*/
char Material_ValidatePassArguments(
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
bool Material_FinishLoadingInstance(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_GetLayeredStateBits
==============
*/
void Material_GetLayeredStateBits(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_CreateLayeredStateBitsTable
==============
*/
unsigned int Material_CreateLayeredStateBitsTable(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_CreateLayered
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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
unsigned int Material_AppendTechniqueSetName(
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
void Material_SetGameFlags
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_LoadRaw
==============
*/
Material *Material_LoadRaw(
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
int Material_CompareBySortKeyAndTechnique(
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
/*char R_FindScriptableConstantSource_ByHash@<al>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

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
/*const char *R_FindScriptableConstantName_BySource@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

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
/*Material *Material_Load@<eax>(LocalClientNum_t a1@<ebx>, const char *fullAssetName, int imageTrack)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

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

