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
/*void FX_FreeMark(FxMark *a1@<edx>, FxMarksSystem *a2@<ecx>, FxMarksSystem *marksSystem, FxMark *mark)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
FX_FreeLruMark
==============
*/
void FX_FreeLruMark(FxMarksSystem *marksSystem)
{
	UNIMPLEMENTED(__FUNCTION__);
}

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
void FX_CopyMarkPoints(
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
void FX_ImpactMark_Generate_AddEntityModel(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ImpactMark_Generate_AddViewmodel
==============
*/
void FX_ImpactMark_Generate_AddViewmodel(
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
void FX_MarkEntDetachAll(LocalClientNum_t localClientNum, int entnum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

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
void FX_MarkGlassDetachAll(LocalClientNum_t localClientNum, int glassIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_MarkEntDetachAllOfType
==============
*/
void FX_MarkEntDetachAllOfType(LocalClientNum_t localClientNum, int entnum, int markType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_MarkEntDetachMatchingBones
==============
*/
void FX_MarkEntDetachMatchingBones(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_MarkEntUpdateHidePartBits
==============
*/
void FX_MarkEntUpdateHidePartBits(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_MarkEntUpdateBegin
==============
*/
void FX_MarkEntUpdateBegin(
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
void FX_MarkEntUpdateEndDObj(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_MarkEntUpdateEnd
==============
*/
void FX_MarkEntUpdateEnd(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ClearViewmodelMarks
==============
*/
void FX_ClearViewmodelMarks(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_EmitMarkTri
==============
*/
void FX_EmitMarkTri(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawMarkTris
==============
*/
void FX_DrawMarkTris(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateMarkVertsForMark_Begin
==============
*/
char FX_GenerateMarkVertsForMark_Begin(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_GenerateMarkVertsForMark_SetLightHandle
==============
*/
void FX_GenerateMarkVertsForMark_SetLightHandle(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateMarkVertsForMark_SetReflectionProbeIndex
==============
*/
void FX_GenerateMarkVertsForMark_SetReflectionProbeIndex(
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
void FX_MarksGridUpdate(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateMarkVertsForMark_FinishNonAnimated
==============
*/
void FX_GenerateMarkVertsForMark_FinishNonAnimated(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateMarkVertsForMark_FinishAnimated
==============
*/
void FX_GenerateMarkVertsForMark_FinishAnimated(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateMarkVertsForList_EntDObj
==============
*/
bool FX_GenerateMarkVertsForList_EntDObj(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_GenerateMarkVertsForList_EntXModel
==============
*/
bool FX_GenerateMarkVertsForList_EntXModel(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_GenerateMarkVertsForList_EntBrush
==============
*/
bool FX_GenerateMarkVertsForList_EntBrush(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_GenerateMarkVertsForList_WorldBrush
==============
*/
bool FX_GenerateMarkVertsForList_WorldBrush(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_GenerateMarkVertsForEntXModel
==============
*/
void FX_GenerateMarkVertsForEntXModel(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateMarkVertsForEntDObj_internal
==============
*/
void FX_GenerateMarkVertsForEntDObj_internal(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateMarkVertsForEntDObj
==============
*/
void FX_GenerateMarkVertsForEntDObj(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateMarkVertsForEntBrush
==============
*/
void FX_GenerateMarkVertsForEntBrush(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateMarkVertsForStaticModels
==============
*/
void FX_GenerateMarkVertsForStaticModels(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateMarkVertsForWorld
==============
*/
void FX_GenerateMarkVertsForWorld(LocalClientNum_t localClientNum, const GfxLight *visibleLights)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateMarkVertsForDynamicModels
==============
*/
void FX_GenerateMarkVertsForDynamicModels(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_AllocAndConstructMark
==============
*/
void FX_AllocAndConstructMark(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ImpactMark_Generate_Callback
==============
*/
void FX_ImpactMark_Generate_Callback(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ImpactMark_Generate
==============
*/
void FX_ImpactMark_Generate(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ImpactMark
==============
*/
void FX_ImpactMark(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_CreateImpactMarkInternal
==============
*/
void FX_CreateImpactMarkInternal(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_CreateImpactMark
==============
*/
void FX_CreateImpactMark(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
fx_add_markCallback
==============
*/
int fx_add_markCallback(jqBatch *batch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

