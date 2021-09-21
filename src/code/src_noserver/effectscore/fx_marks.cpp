#include "types.h"
#include "functions.h"

/*
==============
TRACK_fx_marks
==============
*/
void TRACK_fx_marks()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_InitMarksSystem
==============
*/
void FX_InitMarksSystem(FxMarksSystem *marksSystem)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ClearMarks
==============
*/
void FX_ClearMarks(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_FreeMarkTriGroups
==============
*/
void FX_FreeMarkTriGroups(FxMarksSystem *marksSystem, FxMark *mark)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_FreeMarkPointGroups
==============
*/
void FX_FreeMarkPointGroups(FxMarksSystem *marksSystem, FxMark *mark)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_FreeMarkFromList
==============
*/
void FX_FreeMarkFromList(FxMarksSystem *marksSystem, FxMark *mark, unsigned __int16 *listHead)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_FreeMark
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
FX_FreeLruMark
==============
*/
/*void FX_FreeLruMark(char *a1@<edi>, FxMarksSystem *marksSystem)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
FX_AllocMarkTris
==============
*/
int FX_AllocMarkTris(FxMarksSystem *marksSystem, const FxMarkTri *markTris, int triCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_AllocMarkPoints
==============
*/
int FX_AllocMarkPoints(FxMarksSystem *marksSystem, int pointCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_LinkMarkIntoList
==============
*/
void FX_LinkMarkIntoList(FxMarksSystem *marksSystem, unsigned __int16 *head, FxMark *mark, FxMark *markEA)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_CopyMarkTris
==============
*/
void FX_CopyMarkTris(FxMarksSystem *marksSystem, const FxMarkTri *srcTris, int dstGroupHandle, int triCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_CopyMarkPoints
==============
*/
void FX_CopyMarkPoints(FxMarksSystem *marksSystem, const FxMarkPoint *srcPoints, int dstGroupHandle, int pointCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_FindModelHead
==============
*/
unsigned __int16 FX_FindModelHead(FxMarksSystem *marksSystem, unsigned __int16 modelIndex, int type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_MarkContextsCompare
==============
*/
int FX_MarkContextsCompare(const GfxMarkContext *context0, const GfxMarkContext *context1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_CompareMarkTris
==============
*/
bool FX_CompareMarkTris(const FxMarkTri *tri0, const FxMarkTri *tri1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_ImpactMark_Generate_AddEntityBrush
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
FX_ImpactMark_Generate_AddEntityModel
==============
*/
void FX_ImpactMark_Generate_AddEntityModel(LocalClientNum_t localClientNum, MarkInfo *markInfo, unsigned int entityIndex, const vec3_t *origin, float radius)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ImpactMark_Generate_AddViewmodel
==============
*/
void FX_ImpactMark_Generate_AddViewmodel(LocalClientNum_t localClientNum, MarkInfo *markInfo, const vec3_t *origin, float radius)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_BeginMarks
==============
*/
void FX_BeginMarks(LocalClientNum_t clientIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_MarkEntDetachAll
==============
*/
/*void FX_MarkEntDetachAll(char *a1@<edi>, LocalClientNum_t localClientNum, int entnum)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
FX_MarkEntDetachAllViewmodel
==============
*/
void FX_MarkEntDetachAllViewmodel(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_MarkGlassDetachAll
==============
*/
/*void FX_MarkGlassDetachAll(char *a1@<edi>, LocalClientNum_t localClientNum, int glassIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
FX_MarkEntDetachAllOfType
==============
*/
/*void FX_MarkEntDetachAllOfType(char *a1@<edi>, LocalClientNum_t localClientNum, int entnum, int markType)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
FX_MarkEntDetachMatchingBones
==============
*/
void FX_MarkEntDetachMatchingBones(FxMarksSystem *marksSystem, int entnum, const unsigned int *unsetHidePartBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_MarkEntUpdateHidePartBits
==============
*/
void FX_MarkEntUpdateHidePartBits(const unsigned int *oldHidePartBits, const unsigned int *newHidePartBits, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_MarkEntUpdateBegin
==============
*/
void FX_MarkEntUpdateBegin(FxMarkDObjUpdateContext *context, DObj *obj, bool isBrush, unsigned __int16 brushIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_MarkEntDetachModel
==============
*/
void FX_MarkEntDetachModel(FxMarksSystem *marksSystem, int entnum, int oldModelIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_MarkEntUpdateEndDObj
==============
*/
void FX_MarkEntUpdateEndDObj(FxMarkDObjUpdateContext *context, LocalClientNum_t localClientNum, int entnum, DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_MarkEntUpdateEnd
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
FX_ClearViewmodelMarks
==============
*/
/*void FX_ClearViewmodelMarks(char *a1@<edi>, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
FX_EmitMarkTri
==============
*/
void FX_EmitMarkTri(FxMarksSystem *marksSystem, const unsigned __int16 *indices, const GfxMarkContext *markContext, unsigned __int16 baseVertex, FxActiveMarkSurf *outSurf)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawMarkTris
==============
*/
void FX_DrawMarkTris(FxMarksSystem *marksSystem, const FxMark *mark, unsigned __int16 baseVertex, unsigned __int16 *indices, FxActiveMarkSurf *outSurf)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateMarkVertsForMark_Begin
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
FX_GenerateMarkVertsForMark_SetLightHandle
==============
*/
void FX_GenerateMarkVertsForMark_SetLightHandle(FxActiveMarkSurf *drawSurf, unsigned __int16 lightHandleOverride)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateMarkVertsForMark_SetReflectionProbeIndex
==============
*/
void FX_GenerateMarkVertsForMark_SetReflectionProbeIndex(FxActiveMarkSurf *drawSurf, unsigned __int8 reflectionProbeIndexOverride)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateMarkVertsForMark_MatrixFromPlacement
==============
*/
void FX_GenerateMarkVertsForMark_MatrixFromPlacement(vec3_t *outTransform)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateMarkVertsForMark_MatrixFromAnim
==============
*/
void FX_GenerateMarkVertsForMark_MatrixFromAnim(const FxMark *mark, const DObj *dobj)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_BeginGeneratingMarkVertsForEntModels
==============
*/
void FX_BeginGeneratingMarkVertsForEntModels(LocalClientNum_t localClientNum, unsigned int *indexCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_EndGeneratingMarkVertsForEntModels
==============
*/
void FX_EndGeneratingMarkVertsForEntModels(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_MarkUpdateClientTime
==============
*/
void FX_MarkUpdateClientTime(LocalClientNum_t localClientNum, int frameTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_MarksGridCellFromPosition
==============
*/
void FX_MarksGridCellFromPosition(FxMarksGridCell *cell, const vec3_t *position)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_MarksGridHashFromCell
==============
*/
unsigned int FX_MarksGridHashFromCell(const FxMarksGridCell *cell)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_MarksGrid_TooManyMarksInVicinity
==============
*/
bool FX_MarksGrid_TooManyMarksInVicinity(LocalClientNum_t localClientNum, const vec3_t *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_Marks_GridDebugText
==============
*/
void FX_Marks_GridDebugText(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_MarkDrawSpatialHashDebug
==============
*/
void FX_MarkDrawSpatialHashDebug(FxMarksSystem *marksSystem)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_MarksGridUpdate
==============
*/
/*void FX_MarksGridUpdate(char *a1@<edi>, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
FX_GenerateMarkVertsForMark_FinishNonAnimated
==============
*/
void FX_GenerateMarkVertsForMark_FinishNonAnimated(FxMarksSystem *marksSystem, FxMark *mark, unsigned __int16 baseVertex, FxActiveMarkSurf *drawSurf, const GfxLight *visibleLights, int visibleLightCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateMarkVertsForMark_FinishAnimated
==============
*/
void FX_GenerateMarkVertsForMark_FinishAnimated(FxMarksSystem *marksSystem, FxMark *mark, unsigned __int16 baseVertex, FxActiveMarkSurf *drawSurf, const vec3_t *transform, const GfxLight *visibleLights, int visibleLightCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateMarkVertsForList_EntDObj
==============
*/
bool FX_GenerateMarkVertsForList_EntDObj(FxMarksSystem *marksSystem, unsigned __int16 head, const FxCamera *camera, unsigned int *indexCount, unsigned __int16 lightHandleOverride, unsigned __int8 reflectionProbeIndexOverride, const DObj *dobj, const DObjAnimMat *boneMtxList, unsigned int *hidePartBits, const GfxLight *visibleLights, int visibleLightCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_GenerateMarkVertsForList_EntXModel
==============
*/
bool FX_GenerateMarkVertsForList_EntXModel(FxMarksSystem *marksSystem, unsigned __int16 head, const FxCamera *camera, unsigned int *indexCount, unsigned __int16 lightHandleOverride, unsigned __int8 reflectionProbeIndexOverride, const GfxScaledPlacement *placement, const GfxLight *visibleLights, int visibleLightCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_GenerateMarkVertsForList_EntBrush
==============
*/
bool FX_GenerateMarkVertsForList_EntBrush(FxMarksSystem *marksSystem, unsigned __int16 head, const FxCamera *camera, unsigned int *indexCount, const GfxPlacement *placement, unsigned __int8 reflectionProbeIndex, const GfxLight *visibleLights, int visibleLightCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_GenerateMarkVertsForList_WorldBrush
==============
*/
bool FX_GenerateMarkVertsForList_WorldBrush(FxMarksSystem *marksSystem, unsigned __int16 head, const FxCamera *camera, unsigned int *indexCount, const GfxLight *visibleLights, int visibleLightCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_GenerateMarkVertsForEntXModel
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
FX_GenerateMarkVertsForEntDObj_internal
==============
*/
void FX_GenerateMarkVertsForEntDObj_internal(LocalClientNum_t localClientNum, unsigned int *indexCount, unsigned __int16 lightHandle, unsigned __int8 reflectionProbeIndex, const DObj *dobj, const cpose_t *pose, FxMarksSystem *marksSystem, unsigned int *entMarkListHead, const GfxLight *visibleLights, int visibleLightCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateMarkVertsForEntDObj
==============
*/
void FX_GenerateMarkVertsForEntDObj(LocalClientNum_t localClientNum, int entId, unsigned int *indexCount, unsigned __int16 lightHandle, unsigned __int8 reflectionProbeIndex, const DObj *dobj, const cpose_t *pose, const GfxLight *visibleLights, int visibleLightCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateMarkVertsForEntBrush
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
FX_GenerateMarkVertsForStaticModels
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
FX_GenerateMarkVertsForWorld
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
FX_GenerateMarkVertsForDynamicModels
==============
*/
void FX_GenerateMarkVertsForDynamicModels(LocalClientNum_t localClientNum, const GfxLight *visibleLights, int visibleLightCount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_AllocAndConstructMark
==============
*/
void FX_AllocAndConstructMark(LocalClientNum_t localClientNum, int triCount, int pointCount, Material *material, FxMarkTri *markTris, const FxMarkPoint *markPoints, const vec3_t *origin, float radius, const vec3_t *texCoordAxis, const unsigned __int8 *nativeColor, const FxMarkAlphaFade *markAlpha)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ImpactMark_Generate_Callback
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
FX_ImpactMark_Generate
==============
*/
void FX_ImpactMark_Generate(LocalClientNum_t localClientNum, MarkFragmentsAgainstEnum markAgainst, Material *material, const vec3_t *origin, const vec3_t *axis, float orientation, const unsigned __int8 *nativeColor, float radius, const vec3_t *viewOffset, unsigned int markEntnum, const FxMarkAlphaFade *markAlpha, bool markViewmodel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ImpactMark
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
FX_CreateImpactMarkInternal
==============
*/
void FX_CreateImpactMarkInternal(LocalClientNum_t localClientNum, const FxElemDef *elemDefEA, const FxSpatialFrame *spatialFrame, int randomSeed, const vec3_t *viewOffset, unsigned int markEntnum, bool markViewmodel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_CreateImpactMark
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
fx_add_markCallback
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

