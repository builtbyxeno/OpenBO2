#include "types.h"
#include "functions.h"

/*
==============
TRACK_r_material
==============
*/
void TRACK_r_material()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_Alloc
==============
*/
unsigned __int8 *Material_Alloc(int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Load_CreateStateBits
==============
*/
void Load_CreateStateBits(const unsigned int (*pLoadBits)[2], GfxStateBits *stateBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_CreateMaterialPixelShader
==============
*/
void Load_CreateMaterialPixelShader(int a1, GfxPixelShaderLoadDef *loadDef, MaterialPixelShader *mtlShader)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_CreateMaterialVertexShader
==============
*/
void Load_CreateMaterialVertexShader(GfxVertexShaderLoadDef *loadDef, MaterialVertexShader *mtlShader)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AssertValidVertexDeclOffsets
==============
*/
void AssertValidVertexDeclOffsets(const stream_source_info_t *streamTable)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Load_BuildVertexDecl
==============
*/
void Load_BuildVertexDecl(MaterialVertexDeclaration **mtlVertDecl, MaterialPass *pass)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MaterialTechniqueSet_FindHashLocation
==============
*/
bool MaterialTechniqueSet_FindHashLocation(const char *name, int *foundHashIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_FindTechniqueSet_LoadObj
==============
*/
MaterialTechniqueSet *Material_FindTechniqueSet_LoadObj(int *a1, const char *a2, const char *tname, MtlTechSetNotFoundBehavior notFoundBehavior)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_FindTechniqueSet_FastFile
==============
*/
/*MaterialTechniqueSet *Material_FindTechniqueSet_FastFile@<eax>(char *a1@<edi>, const char *name, MtlTechSetNotFoundBehavior notFoundBehavior)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
Material_SetTechniqueSet
==============
*/
void Material_SetTechniqueSet(const char *name, MaterialTechniqueSet *techniqueSet)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_SetAlwaysUseDefaultMaterial
==============
*/
void Material_SetAlwaysUseDefaultMaterial(const bool alwaysUseDefaultMaterial)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_RegisterTechniqueSet
==============
*/
MaterialTechniqueSet *Material_RegisterTechniqueSet(const char *prefix, const char *materialName, char *name, bool isLayerOrDefault)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_ReleaseMaterialResources
==============
*/
void Material_ReleaseMaterialResources(Material *mtl)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_WarmTechniqueSetShaders
==============
*/
void Material_WarmTechniqueSetShaders(XAssetHeader header)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_WarmAllShaders
==============
*/
void Material_WarmAllShaders()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_DirtySort
==============
*/
void Material_DirtySort()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_Add
==============
*/
void Material_Add(Material *material, unsigned __int16 hashIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_IsDefault
==============
*/
bool Material_IsDefault(const Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_GetHashIndex
==============
*/
void Material_GetHashIndex(const char *name, unsigned __int16 *hashIndex, bool *exists)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_Register_FastFile
==============
*/
Material *Material_Register_FastFile(const char *name, int imageTrack, bool errorIfMissing, int waitTime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_MaterialParameterTweakUpdate
==============
*/
void R_MaterialParameterTweakUpdate()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_EnumTechniqueSets
==============
*/
void R_EnumTechniqueSets(void (*func)(XAssetHeader, void *), void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_EnumMaterials
==============
*/
void R_EnumMaterials(void (*func)(XAssetHeader, void *), void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_GetName
==============
*/
const char *Material_GetName(Material *handle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_LoadFile
==============
*/
int Material_LoadFile(const char *filename, int *file)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IsValidMaterialHandle
==============
*/
BOOL IsValidMaterialHandle(Material *const handle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetCodeConst_GenericParam0
==============
*/
int GetCodeConst_GenericParam0()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetCodeConst_GenericParam1
==============
*/
int GetCodeConst_GenericParam1()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetCodeConst_GenericParam2
==============
*/
int GetCodeConst_GenericParam2()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetCodeConst_GenericParam3
==============
*/
int GetCodeConst_GenericParam3()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetCodeConst_GenericParamA
==============
*/
int GetCodeConst_GenericParamA()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetCodeConst_GenericParamB
==============
*/
int GetCodeConst_GenericParamB()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetCodeConst_GameTimeParam
==============
*/
int GetCodeConst_GameTimeParam()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Material_ReleaseTechniqueSetResources
==============
*/
void Material_ReleaseTechniqueSetResources(MaterialTechniqueSet *techniqueSet)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Material_Duplicate
==============
*/
Material *Material_Duplicate(Material *mtlCopy, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_MakeDefault
==============
*/
Material *Material_MakeDefault(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_Register_LoadObj
==============
*/
Material *Material_Register_LoadObj(const char *name, int imageTrack)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_Register
==============
*/
Material *Material_Register()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_RegisterHandle
==============
*/
Material *Material_RegisterHandle(const char *name, int imageTrack, bool errorIfMissing, int waitTime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Material_LoadPerMap
==============
*/
void Material_LoadPerMap(const PerMapMaterialTable *mtlTable, int mtlTableCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitAssets_PostMapFastfileLoad
==============
*/
void R_InitAssets_PostMapFastfileLoad(int a1, int a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

