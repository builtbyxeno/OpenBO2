#pragma once

#include "types.h"

//t6/code/src_noserver/effectscore/fxcurve.cpp
void FxCurveIterator_Create(FxCurveIterator *createe, const FxCurve *master);
void FxCurveIterator_Release(FxCurveIterator *releasee);

//#include "effectscore/fxcurve.h"

//t6/code/src_noserver/effectscore/fxcurve_load_obj.cpp
const FxCurve *FxCurve_AllocAndCreateWithKeys(const float *keyArray, int dimensionCount, int keyCount);

//t6/code/src_noserver/effectscore/fx_actions.cpp
void FX_ProcessActionsPPU(FxSystem *system);
FxPPUAction *FxAction_AllocPPUAction(const FxSystem *system, unsigned __int8 actionType, int *outAllocIndex);
char FX_AddPlaySoundAction(const FxSystem *system, const char *soundName, const vec3_t *origin);

//t6/code/src_noserver/effectscore/fx_beam.cpp
void Float4x4ForViewer(const vec3_t *origin3, const vec3_t *axis3);
void CreateClipMatrix(vector4 *clipMtx, const vec3_t *vieworg, const vec3_t *viewaxis);
bool Vec4HomogenousClipZW(__m128 *pt0, __m128 *pt1, const __m128 *coeffZW);
;
void FX_Beam_Begin();
void FX_Beam_Add(FxBeam *beam);
FxBeamInfo *FX_Beam_GetInfo();
;

//t6/code/src_noserver/effectscore/fx_convert.cpp
void FX_InterpolateSamples(;
float FX_SampleCurve1D(const FxCurve *curve, float scale, float time);
int FX_DecideSampleCount(int curveCount, const FxCurve **curves, int intervalLimit);
int FX_DecideVelocitySampleCount(const FxEditorElemDef *edElem, int intervalLimit);
void FX_GetVisualSampleRouting(const FxEditorElemDef *edElem, FxSampleChannel *routing);
int FX_DecideVisualSampleCount(;
void FX_SampleVelocityInFrame(;
void FX_SampleVisualStateScalar(;
void FX_SampleVisualState(FxElemDef *elemDef, const FxEditorElemDef *edElemDef);
bool FX_ValidateAtlasSettings(const FxEditorEffectDef *editorEffect, const FxEditorElemDef *edElemDef);
void FX_ConvertAtlas(FxElemDef *elemDef, const FxEditorElemDef *edElemDef);
void FX_ReserveElemDefMemory(FxElemDef *elemDef, unsigned __int8 **memPool);
void FX_BoundFloatRange(FxFloatRange *range, float lower, float upper);
void FX_ConvertTrail_CompileVertices(;
void FX_ConvertTrail(FxTrailDef **outTrailDef, const FxEditorElemDef *edElemDef, unsigned __int8 **mempool);
void FX_ConvertSpotLight(;
int FX_FindEmission(const FxEffectDef *emission, const FxEditorEffectDef *editorEffect);
// int FX_CopyEmittedElemDefs@<eax>(;
int FX_AdditionalBytesNeededForEmission(const FxEffectDef *emission);
bool FX_ValidateVisuals(const FxEditorEffectDef *editorEffect, const FxEditorElemDef *edElemDef);
void FX_ConvertElemDef(;
int FX_ConvertElemDefsOfType(;
const FxEffectDef *FX_Convert(const FxEditorEffectDef *editorEffect, void *(*Alloc)(int));

//t6/code/src_noserver/effectscore/fx_dpvs.cpp
int FX_DpvsIsBoxVisible(FxSystem *system, const vec3_t *mins, const vec3_t *maxs);

//t6/code/src_noserver/effectscore/fx_draw.cpp
void FX_PrepareGenericLookupTables();
void FX_SetupVisualState(;
void FX_EvaluateSize(;
__m128 *FX_GetExposureFloat4(LocalClientNum_t localClientNum);
void FX_ApplyLightingFrac(const FxEffect *effect, FxColor4b *outColor);
double FX_EvaluateRotation(;
void FX_PrepareAtlasLookupTables();
void FX_GetSpriteTexCoords(;
;
void FX_GenTrail_IndsForSegment(;
;
bool FX_CullElementForDraw_Sprite(const FxDrawState *draw, const FxElemRenderState *elemState);
void FX_DrawElem_BillboardSprite_NoCull(const FxDrawState *draw, FxElemRenderState *elemState);
void FX_DrawElem_BillboardSprite(const FxDrawState *draw, FxElemRenderState *elemState);
void FX_DrawElem_OrientedSprite_NoCull(const FxDrawState *draw, FxElemRenderState *elemState);
void FX_DrawElem_OrientedSprite(const FxDrawState *draw, FxElemRenderState *elemState);
bool FX_CullCylinder(;
bool FX_CullElementForDraw_Tail(;
void FX_DrawElem_CalculateVelDirWorld(;
bool FX_CullElementForDraw_Tail_Wrapper(const FxDrawState *draw, const FxElemRenderState *elemState);
void FX_DrawElem_Tail_Main(const FxDrawState *draw, FxElemRenderState *elemState, const vec3_t *velDirWorld);
void FX_DrawElem_Tail_NoCull(const FxDrawState *draw, FxElemRenderState *elemState);
void FX_DrawElem_Tail(const FxDrawState *draw, FxElemRenderState *elemState);
bool FX_CullElement_Line(;
bool FX_CullElement_Line_Wrapper(const FxDrawState *draw, const FxElemRenderState *elemState);
void FX_DrawElem_Line_Main(const FxDrawState *draw, FxElemRenderState *elemState, const vec3_t *velDirWorld);
void FX_DrawElem_Line_NoCull(const FxDrawState *draw, FxElemRenderState *elemState);
void FX_DrawElem_Line(const FxDrawState *draw, FxElemRenderState *elemState);
void FX_DrawElem_RotatedSprite_NoCull(const FxDrawState *draw, FxElemRenderState *elemState);
void FX_DrawElem_RotatedSprite(const FxDrawState *draw, FxElemRenderState *elemState);
float FX_EvaluateDistanceFade(const FxDrawState *draw, const vec3_t *elemPosWorld);
void FX_DrawElem_Cloud_Main(;
void FX_DrawElem_Cloud_NoCull(const FxDrawState *draw, FxElemRenderState *elemState);
bool FX_CullElementForDraw_Cloud(const FxDrawState *draw, const FxElemRenderState *elemState, float scale);
bool FX_CullElement_Cloud(const FxDrawState *draw, const FxElemRenderState *elemState);
// void FX_DrawElem_Cloud(vec3_t *a1@<edi>, const FxDrawState *draw, FxElemRenderState *elemState);
void FX_DrawElem_Model(const FxDrawState *draw, FxElemRenderState *elemState);
bool FX_CullElementForDraw_Light(const FxDrawState *draw, const FxElemRenderState *elemState);
void FX_DrawElem_Light(;
void FX_DrawElem_SpotLight_NoCull(const FxDrawState *draw, FxElemRenderState *elemState);
void FX_DrawElem_SpotLight(const FxDrawState *a1, const FxElemRenderState *a2);
float FX_EvaluateVisAlpha(const FxElemPreVisualState *preVisState);
__m128 *FX_InterpolateColor4b(;
void FX_EvaluateBaseColor(;
void FX_DrawTrail_SubmitGfxDrawSurfs(;
double FX_OcclusionQuery_UpdateOverTime(;
FxSmpDrawBuffer *FX_InitSmpDrawBuffer();
void FX_CloudElemAllocParticleClouds(EffectElementDraw *elemDraw, unsigned __int16 numElems);
int EffectCountInfoSort(const void *elem1, const void *elem2);
int FX_FindAllTrailEffects(;
int FX_AllocAllTrailResource(;
void FX_TrailGeoWorkers_Start(;
void FX_LaunchElemSetupWorkers(FxGenerateVertsCmd *generateVertsCmd);
void FX_LaunchSpriteGeoWorkers(;
void FX_AllocSpriteDrawData(;
void FX_FillGenerateVertsCmd(LocalClientNum_t localClientNum, FxGenerateVertsCmd *cmd);
void FX_WaitForFXDrawWorkers();
void FX_LaunchFXMarksWorkers(GfxViewInfo *viewInfo);
void FX_WaitForFXMarksWorkers();
void FX_DrawElement(const FxElemDef *elemDef, const FxElem *elem, FxDrawState *draw);
;
char FX_DrawTrail_CalcRequiredResources(;
void FX_DrawTrailsForEffect(;
void FX_DrawSpotLightEffect(FxSystem *system, FxEffect *effectEA, int drawTime);
void FX_DrawNonSpriteEffect(;
void FX_DrawNonSpriteElems(FxSystem *system, unsigned int cameraType, bool isInfraredDraw);
void FX_DrawSpotLight(FxSystem *system);
bool FX_ShouldDrawElement(const FxElemDef *elemDef, FxElem *elem, FxDrawState *draw);
;
;
void FX_SpriteElemMakeQuads(;
void FX_SpriteElemMakeGfxDrawSurfs(;
void FX_CloudElemMakeParticleClouds(;
void FX_CloudElemMakeGfxDrawSurfs(;
void FX_SMPDraw_MakeSpriteGeo(FxDrawSpriteGeoCmd *cmd);
void FX_SMPDraw_MakeTrailGeo(FxDrawTrailGeoCmd *cmd);
void FX_ElemSetupWorker(FxElemSetupCmd *cmd);
;
void FX_AllocTrailDrawData(;
void FX_GenerateSpriteDrawSurfs(FxSystem *system, unsigned int cameraType, FxSmpDrawBuffer *smpBuffer);
void FX_GenerateTrailDrawSurfs(FxSystem *system, FxSmpDrawBuffer *smpBuffer);
int fx_allocCallback(jqBatch *batch);
int fx_add_surfsCallback(jqBatch *batch);
void FX_DrawSpriteElems(;
void FX_GenerateVerts(FxGenerateVertsCmd *cmd);
int fx_draw_sprite_geoCallback(jqBatch *batch);
int fx_draw_trail_geoCallback(jqBatch *batch);
int fx_elemsetupCallback(jqBatch *batch);

//#include "effectscore/fx_draw.h"

//t6/code/src_noserver/effectscore/fx_dvars.cpp
void FX_RegisterDvars();
void FX_CreateDevGui();

//#include "effectscore/fx_effect_load_db.h"

//#include "effectscore/fx_effect_types.h"

//t6/code/src_noserver/effectscore/fx_load_obj.cpp
void FX_UnregisterAll();
char FX_ParseFlagsField(const char **parse, FxFlagOutputSet *flagOutputSet);
void *FX_AllocMem(int size);
void *Hunk_AllocPhysPresetPrecache(int size);
PhysPreset *FX_RegisterPhysPreset(const char *name);
bool FX_RegisterAsset_LightDef(const char *name, FxElemVisuals *visuals);
bool FX_RegisterAsset_Material(const char *name, FxElemVisuals *visuals);
bool FX_RegisterAsset_Model(const char *name, FxElemVisuals *visuals);
char FX_RegisterAsset_SoundAliasName(const char *name, FxElemVisuals *visuals);
bool FX_ParseElemSpawnSoundAsset(const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseCurve(const char **parse, int dimCount, float minValue, float maxValue, const FxCurve **shape);
bool FX_ParseGraphRange(;
char FX_ParseName(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseNonAtlasFlags(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseSpawnRange(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseFadeInRange(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseFadeOutRange(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseSpawnFrustumCullRadius(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseSpawnDefLooping(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseSpawnDefOneShot(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseSpawnDelayMsec(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseLifeSpanMsec(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseSpawnOrgX(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseSpawnOrgY(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseSpawnOrgZ(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseSpawnOffsetRadius(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseSpawnOffsetHeight(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseSpawnAnglePitch(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseSpawnAngleYaw(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseSpawnAngleRoll(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseAngleVelPitch(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseAngleVelYaw(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseAngleVelRoll(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseInitialRot(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseGravity(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseElasticity(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseWindinfluence(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseAtlasBehavior(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseAtlasIndex(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseAtlasIndexRange(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseAtlasFps(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseAtlasLoopCount(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseAtlasColIndexBits(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseAtlasRowIndexBits(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseAtlasEntryCount(const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseVelGraph0X@<al>(int a1@<edx>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseVelGraph0Y@<al>(int a1@<edx>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseVelGraph0Z@<al>(int a1@<edx>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseVelGraph1X@<al>(int a1@<edx>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseVelGraph1Y@<al>(int a1@<edx>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseVelGraph1Z@<al>(int a1@<edx>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseRotGraph@<al>(int a1@<edx>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseSizeGraph0@<al>(int a1@<edx>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseSizeGraph1@<al>(int a1@<edx>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseScaleGraph@<al>(int a1@<edx>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseColorGraph@<al>(int a1@<edx>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseAlphaGraph@<al>(int a1@<edx>, const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseCollOffset(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseLightingFrac(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseCollRadius(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseSortOrder(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParsePriority(const char **parse);
char FX_ParseAlphaFadeTimeMsec(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseMaxWindMagnitude(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseMaxWindLife(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseMaxWindInterval(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseEmitDist(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseEmitDistVariance(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseTrailRepeatTime(const char **parse);
char FX_ParseTrailSplitDist(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseTrailScrollTime(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseTrailRepeatDist(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseTrailDef(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseLight(const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseElemSpawnSound@<al>(FxEditorElemDef *a1@<edx>, const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseBillboardTopWidth(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseBillboardBottomWidth(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseRotationAxis(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseCloudDensityRange(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseEffectBoundMin(const char **parse, FxEditorEffectDef *edEffectDef);
char FX_ParseEffectBoundMax(const char **parse, FxEditorEffectDef *edEffectDef);
char FX_ParseEffectDummyVector(const char **parse);
char FX_ParseEffectFlags(const char **parse, FxEditorEffectDef *edEffectDef);
char FX_ParseEffectPriority(const char **parse, FxEditorEffectDef *edEffectDef);
char FX_ParseBillboardPivot(const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseEditorElemField(const char **parse, FxEditorElemDef *edElemDef, const char *token);
bool FX_ParseEditorEffectField(const char **parse, FxEditorEffectDef *edEffectDef, const char *token);
char FX_ParseEditorElem(int version, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseEditorEffect(const char **parse, FxEditorEffectDef *edEffectDef);
bool FX_LoadEditorEffectFromBuffer(;
bool FX_LoadEditorEffect(const char *name, FxEditorEffectDef *edEffectDef);
int FX_HashName(const char *name);
int FX_GetHashIndex(const char *name, bool *exists);
const FxEffectDef *FX_Register_FastFile(const char *name);
bool FX_RegisterMarkMaterials(const char *materialName, Material **materials);
bool FX_RegisterAsset_DecalMaterials(const char *name, FxElemMarkVisuals *visuals);
// bool FX_ParseBillboardSprite@<al>(unsigned __int8 a1@<dl>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseOrientedSprite@<al>(unsigned __int8 a1@<dl>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseRotatedSprite@<al>(unsigned __int8 a1@<dl>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseCloud@<al>(unsigned __int8 a1@<dl>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseTail@<al>(unsigned __int8 a1@<dl>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseLine@<al>(unsigned __int8 a1@<dl>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseTrail@<al>(unsigned __int8 a1@<dl>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseDecal@<al>(unsigned __int8 a1@<dl>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseModel@<al>(unsigned __int8 a1@<dl>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseSpotLight@<al>(unsigned __int8 a1@<dl>, const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseSound@<al>(unsigned __int8 a1@<dl>, const char **parse, FxEditorElemDef *edElemDef);
const FxEffectDef *FX_LoadFailed(const char *name);
const FxEffectDef *FX_Load(const char *name);
// const FxEffectDef *FX_Register_LoadObj@<eax>(bool *a1@<edx>, const char *a2@<ecx>, const char *name);
const FxEffectDef *FX_Register();
void FX_RegisterDefaultEffect();
bool FX_RegisterAsset_EffectDef(const char *name, FxElemVisuals *visuals);
char FX_ParseFxOnImpact(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseFxOnDeath(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseEmission(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseAttachment(const char **parse, FxEditorElemDef *edElemDef);
// bool FX_ParseRunner@<al>(unsigned __int8 a1@<dl>, const char **parse, FxEditorElemDef *edElemDef);
unsigned __int8 *Hunk_AllocPhysPresetPrecache(int size);

//t6/code/src_noserver/effectscore/fx_marks.cpp
void TRACK_fx_marks();
void FX_InitMarksSystem(FxMarksSystem *marksSystem);
void FX_ClearMarks(LocalClientNum_t localClientNum);
void FX_FreeMarkTriGroups(FxMarksSystem *marksSystem, FxMark *mark);
void FX_FreeMarkPointGroups(FxMarksSystem *marksSystem, FxMark *mark);
void FX_FreeMarkFromList(FxMarksSystem *marksSystem, FxMark *mark, unsigned __int16 *listHead);
// void FX_FreeMark(FxMark *a1@<edx>, FxMarksSystem *a2@<ecx>, FxMarksSystem *marksSystem, FxMark *mark);
void FX_FreeLruMark(FxMarksSystem *marksSystem);
int FX_AllocMarkTris(FxMarksSystem *marksSystem, const FxMarkTri *markTris, int triCount);
int FX_AllocMarkPoints(FxMarksSystem *marksSystem, int pointCount);
void FX_LinkMarkIntoList(FxMarksSystem *marksSystem, unsigned __int16 *head, FxMark *mark, FxMark *markEA);
void FX_CopyMarkTris(FxMarksSystem *marksSystem, const FxMarkTri *srcTris, int dstGroupHandle, int triCount);
void FX_CopyMarkPoints(;
unsigned __int16 FX_FindModelHead(FxMarksSystem *marksSystem, unsigned __int16 modelIndex, int type);
int FX_MarkContextsCompare(const GfxMarkContext *context0, const GfxMarkContext *context1);
bool FX_CompareMarkTris(const FxMarkTri *tri0, const FxMarkTri *tri1);
;
void FX_ImpactMark_Generate_AddEntityModel(;
void FX_ImpactMark_Generate_AddViewmodel(;
void FX_BeginMarks(LocalClientNum_t clientIndex);
void FX_MarkEntDetachAll(LocalClientNum_t localClientNum, int entnum);
void FX_MarkEntDetachAllViewmodel(LocalClientNum_t localClientNum);
void FX_MarkGlassDetachAll(LocalClientNum_t localClientNum, int glassIndex);
void FX_MarkEntDetachAllOfType(LocalClientNum_t localClientNum, int entnum, int markType);
void FX_MarkEntDetachMatchingBones(;
void FX_MarkEntUpdateHidePartBits(;
void FX_MarkEntUpdateBegin(;
void FX_MarkEntDetachModel(FxMarksSystem *marksSystem, int entnum, int oldModelIndex);
void FX_MarkEntUpdateEndDObj(;
void FX_MarkEntUpdateEnd(;
void FX_ClearViewmodelMarks(LocalClientNum_t localClientNum);
void FX_EmitMarkTri(;
void FX_DrawMarkTris(;
char FX_GenerateMarkVertsForMark_Begin(;
void FX_GenerateMarkVertsForMark_SetLightHandle(;
void FX_GenerateMarkVertsForMark_SetReflectionProbeIndex(;
void FX_GenerateMarkVertsForMark_MatrixFromPlacement(vec3_t *outTransform);
void FX_GenerateMarkVertsForMark_MatrixFromAnim(const FxMark *mark, const DObj *dobj);
void FX_BeginGeneratingMarkVertsForEntModels(LocalClientNum_t localClientNum, unsigned int *indexCount);
void FX_EndGeneratingMarkVertsForEntModels(LocalClientNum_t localClientNum);
void FX_MarkUpdateClientTime(LocalClientNum_t localClientNum, int frameTime);
void FX_MarksGridCellFromPosition(FxMarksGridCell *cell, const vec3_t *position);
unsigned int FX_MarksGridHashFromCell(const FxMarksGridCell *cell);
bool FX_MarksGrid_TooManyMarksInVicinity(LocalClientNum_t localClientNum, const vec3_t *pos);
void FX_Marks_GridDebugText(LocalClientNum_t localClientNum);
void FX_MarkDrawSpatialHashDebug(FxMarksSystem *marksSystem);
void FX_MarksGridUpdate(LocalClientNum_t localClientNum);
void FX_GenerateMarkVertsForMark_FinishNonAnimated(;
void FX_GenerateMarkVertsForMark_FinishAnimated(;
bool FX_GenerateMarkVertsForList_EntDObj(;
bool FX_GenerateMarkVertsForList_EntXModel(;
bool FX_GenerateMarkVertsForList_EntBrush(;
bool FX_GenerateMarkVertsForList_WorldBrush(;
void FX_GenerateMarkVertsForEntXModel(;
void FX_GenerateMarkVertsForEntDObj_internal(;
void FX_GenerateMarkVertsForEntDObj(;
void FX_GenerateMarkVertsForEntBrush(;
void FX_GenerateMarkVertsForStaticModels(;
void FX_GenerateMarkVertsForWorld(LocalClientNum_t localClientNum, const GfxLight *visibleLights);
void FX_GenerateMarkVertsForDynamicModels(;
void FX_AllocAndConstructMark(;
void FX_ImpactMark_Generate_Callback(;
void FX_ImpactMark_Generate(;
void FX_ImpactMark(;
void FX_CreateImpactMarkInternal(;
void FX_CreateImpactMark(;
int fx_add_markCallback(jqBatch *batch);

//#include "effectscore/fx_marks.h"

//t6/code/src_noserver/effectscore/fx_postlight.cpp
void FX_PostLight_GenerateVerts(FxPostLightInfo *postLightInfoAddr, const FxSystem *system);
void FX_PostLight_Begin();
void FX_PostLight_Add(FxPostLight *postLight);
FxPostLightInfo *FX_PostLight_GetInfo();

//t6/code/src_noserver/effectscore/fx_profile.cpp
FxProfileEntry *FX_GetProfileEntry(const FxEffectDef *effectDef, FxProfileEntry *entryPool, int *entryCount);
int FX_CompareProfileEntries(const void *e0, const void *e1);
int FX_ComparePriorityDebugEntries(const void *e0, const void *e1);
void FX_DrawPriorityDebug(;
int FX_CompareOccQueryDebugEntries(const void *e0, const void *e1);
void FX_DrawOccQueryDebug(;
const char *typeAsString(unsigned __int8 type);
void FX_DrawMarkProfile_MarkPrint(;
void FX_DrawMarkProfile(;
void FX_DebugShowNamesInWorld(LocalClientNum_t localClientNum);
void FX_ProfileSingleEffect(FxSystem *system, const FxEffect *effect, FxProfileEntry *entry);
void FX_DrawProfile(;

//t6/code/src_noserver/effectscore/fx_random.cpp
void TRACK_fx_random();
void FX_RandomDir(int seed, vec3_t *dir);

//#include "effectscore/fx_random.h"

//t6/code/src_noserver/effectscore/fx_sort.cpp
int FX_CalcRunnerParentSortOrder(FxEffect *effect);
void FX_SortEffects(FxSystem *system);
void FX_GetInsertSortElem(;
bool FX_ExistingElemSortsBeforeNewElem(;
void FX_SortSpriteElemIntoEffect(const FxSystem *system, FxEffect *effect, FxElem *remoteElem, FxElem *elem);
void FX_SortNewElemsInEffect(const FxSystem *system, FxEffect *effect);

//t6/code/src_noserver/effectscore/fx_sprite.cpp
void FX_BuildQuadStampCodeMeshVerts(;
bool FX_HeightScreenToWorld(;
bool FX_HeightWorldToScreen(;
void FX_SpriteBegin();
void FX_SpriteAdd(FxSprite *sprite);
FxSpriteInfo *FX_SpriteGetInfo();
// void FX_SpriteGenerateVerts_Internal<1>(float *a1@<edx>, Material *a2@<ecx>, FxGenerateVertsCmd *cmd);
// void FX_SpriteGenerateVerts(float *a1@<edx>, Material *a2@<ecx>, FxGenerateVertsCmd *cmd);

//t6/code/src_noserver/effectscore/fx_system.cpp
void TRACK_fx_system();
FxSystemContainer *FX_GetSystem(LocalClientNum_t localClientNum);
void FX_LinkSystemBuffers(FxSystem *system, FxSystemBuffers *systemBuffers);
int FX_PrintMatchingEffects(LocalClientNum_t clientNum, unsigned int testOffset, unsigned int testValue);
bool FX_CullElemForSpawn(const FxCamera *camera, const FxElemDef *elemDef, const vec3_t *origin);
bool FX_EffectHasSideEffects(const FxElemDef *elemDef);
void FX_DelRefToOwnerEffect(const FxSystem *system, unsigned int ownerEffect, unsigned int stackCount);
void FX_RunGarbageCollection_FreeSpotLight(const FxSystem *system, unsigned __int16 effectHandle);
char FX_RingBufferAllocate(;
void FX_RingBufferCommit(volatile int *firstNew, const volatile int *firstFree, int allocIndex);
char FX_EffectAffectsGameplay(const FxEffectDef *remoteEffectDef);
void FX_SetEffectRandomSeed(FxEffect *effect, const FxEffectDef *remoteDef);
bool FX_SpawnEffect_AllocSpotLightEffect(;
void FX_SetWarningPriority(const FxSystem *system, unsigned __int8 priority);
void FX_InvalidateFrameWarningPriority(const FxSystem *system);
int FX_GetFrameWarningPriority(const FxSystem *system);
void FX_Priority_Begin(FxSystem *system);
void FX_AddRefToOwnerEffect(const FxSystem *system, unsigned int owner, FxEffect *newEffect);
void FX_InitEffectGroundEntity(;
unsigned int FX_SpawnEffectDeferred(const FxSystem *system, FxSpawnEffectCmd *cmd);
BOOL FX_SpawnWorkerShouldBeHeld(const FxSpawnEffectCmd *cmd);
void FX_AssertAllocatedEffect(LocalClientNum_t localClientNum, unsigned int hEffect, const char *error_msg);
int FX_GetEffectPlayedTime(LocalClientNum_t localClientNum, unsigned int hEffect);
BOOL FX_IsEffectDone(LocalClientNum_t localClientNum, unsigned int hEffect);
void FX_HideEffectInExtracam(LocalClientNum_t localClientNum, unsigned int hEffect, bool hide);
void FX_RandomlyRotateAxis(const vec3_t *axisIn, int randomSeed, vec3_t *axisOut);
void FX_SpawnRunner(;
void FX_GetOriginForElem(;
void FX_SpawnSound(;
unsigned __int8 FX_ElemSpawnVisBits(const FxSystem *system, const FxElemDef *elemDef, const vec3_t *origin);
bool FX_ImpactMarkWithinRange(const FxSystem *system, const vec3_t *markLocation);
double FX_GetClientVisibility(LocalClientNum_t localClientNum, const vec3_t *start, const vec3_t *end);
bool FX_ClientVisibilityTest(LocalClientNum_t localClientNum, const vec3_t *start, const vec3_t *end);
BOOL FX_FxSpawnWorkersAreOnHold(LocalClientNum_t localClientNum);
BOOL FX_ShouldHideMatureContent();
void FX_ResetSystem(FxSystem *system);
void FX_InitSystem(LocalClientNum_t localClientNum);
void FX_ShutdownSystem(LocalClientNum_t localClientNum);
bool FX_CullEffectForSpawn(const FxCamera *camera, const FxEffectDef *effectDef, const vec3_t *origin);
void FX_RunGarbageCollection_FreeTrails(const FxSystem *system, FxEffect *effect);
void FX_EffectRemoveBaseRef(const FxSystem *system, FxEffect *remoteEffect);
void FX_RunGarbageCollection(const FxSystem *system);
void FX_SpawnEffect_AllocTrails(const FxSystem *system, FxEffect *effect, FxEffect *remoteEffect);
unsigned int FX_SpawnEffect(;
void FX_WaitForFxSpawnWorkers(LocalClientNum_t localClientNum);
unsigned int FX_SpawnOrientedEffect(;
unsigned int FX_PlayOrientedEffectWithMarkEntity(;
unsigned int FX_PlayOrientedEffectWithMarkViewmodel(;
unsigned int FX_PlayOrientedEffect(;
unsigned int FX_PlayOrientedEffectWithLightingParams(;
bool FX_NeedsBoltUpdate(const FxEffectDef *def);
unsigned int FX_SpawnBoltedEffect(;
unsigned int FX_SpawnBoltedEffect(;
unsigned int FX_SpawnBoltedEffectBoltRelative(;
unsigned int FX_PlayBoltedEffect_DynEnt(;
unsigned int FX_PlayBoltedEffect(;
unsigned int FX_PlayBoltedEffect(;
unsigned int FX_PlayBoltedEffectBoltRelative(;
void FX_GetTrailHandleList_Last(;
void FX_StopEffectNonRecursive(const FxSystem *system, FxEffect *effect);
bool FX_SpawnModelPhysics(int randomSeed, FxElem *elem);
void FX_SpawnTrailElem_NoCull(;
void FX_SpawnTrailElem_Cull(;
void FX_SpawnSpotLightElem(const FxSystem *system, FxElem *elem);
void FX_FreeTrailElem(;
void FX_FreeSpotLightElem(const FxSystem *system, unsigned __int16 elemHandle, FxEffect *effect);
void FX_ProcessCmd_SpawnEffect(FxSpawnEffectCmd *data);
void FX_StopEffect(const FxSystem *system, FxEffect *effect);
void FX_RemoveAllEffectElems(;
void FX_KillEffect(;
void FX_KillEffectDef(LocalClientNum_t localClientNum, const FxEffectDef *def);
void FX_KillAllEffects(LocalClientNum_t localClientNum);
void FX_RetriggerEffect(LocalClientNum_t localClientNum, FxEffect *effect, int msecBegin);
void FX_RetriggerEffect(LocalClientNum_t localClientNum, unsigned int hEffect, int msecBegin);
void FX_ThroughWithEffect(const FxSystem *system, FxEffect *effect, bool forcekill);
void FX_FreeElem(;
void FX_ThroughWithEffect(LocalClientNum_t localClientNum, unsigned int hEffect, bool forcekill);
void FX_SpawnElem(;
void FX_RunPrioritySorting(const FxSystem *system);

//#include "effectscore/fx_system.h"

//t6/code/src_noserver/effectscore/fx_unique_handle.cpp
FxEffect *UniqueHandleToEffect(const FxSystem *system, unsigned int handle);
unsigned int UniqueHandleAlloc(const FxSystem *system);
void UniqueHandleAssignEffect(;
void UniqueHandleReleaseHandle(const FxSystem *system, unsigned int handle);
void UniqueHandleRelease(const FxSystem *system, FxEffect *effect);
void UniqueHandleInit(FxUniqueHandleDb *uniqueHandleDb);
FxEffect *UniqueHandleToEffect(LocalClientNum_t localClientNum, unsigned int h);

//t6/code/src_noserver/effectscore/fx_update.cpp
bool FX_IsDemoPlaying();
void FX_SpawnTrailLoopingElems(;
int FX_LimitStabilizeTimeForEffectDef_Recurse(const FxEffectDef *remoteEffectDef, int originalUpdateTime);
int FX_LimitStabilizeTimeForElemDef_Recurse(;
void FX_SpawnLoopingElems(;
void FX_SpawnAllFutureLooping(;
void FX_TriggerOneShot(;
void FX_IntegrateVelocityAcrossSegments(;
void FX_IntegrateVelocityInSegment(;
// void FX_IntegrateVelocity(int a1@<edx>, vec3_t *a2@<ecx>, float a3@<xmm0>, const vec3_t *t1);
void FX_NextElementPosition_NoExternalForces(;
// double FX_GetAtRestFraction@<st0>(int a1@<eax>, float a2@<xmm0>);
void FX_GetQuatForOrientation(;
bool FX_UpdateElement_SetupUpdate(;
void FX_PlayElementSpawnSound(const FxSystem *system, const FxElemDef *elemDef, const vec3_t *origin);
bool FX_UpdateElement_TruncateToElemBegin(FxUpdateElem *update, FxUpdateResult *outUpdateResult);
int FX_GetBoltTemporalBits(LocalClientNum_t localClientNum, int dobjHandle, unsigned int ignoreTeleporting);
bool FX_GetBoneOrientation_IsDObjEntityValid(LocalClientNum_t localClientNum, int dobjHandle);
char FX_GetBoneOrientation(;
bool FX_CanKillImmediate(const FxEffectDef *def);
int FX_UpdateEffectBolt(;
void FX_GetWorldBoundingBox(;
int FX_TestEffectBoundingBoxMinMaxAgainstFrustum(;
bool FX_ShouldProcessEffect(FxSystem *system, FxEffect *remoteEffect, FxUpdateEffectType updateEffectType);
void FX_BeginUpdate(LocalClientNum_t localClientNum);
void FX_EndUpdate(LocalClientNum_t localClientNum);
void FX_SaveGfxCloudCount(LocalClientNum_t localClientNum, int count);
void FX_SortEffectsForDraw(FxSystem *system);
void FX_AddNonSpriteDrawSurfs(FxCmd *cmd);
void DB_RestartEffects_Begin();
void FX_SetupCamera(;
void FX_GetCameraUpdateFromRefdefAndZFar(FxCameraUpdate *cameraUpdate, const refdef_t *refdef, float zfar);
void FX_SetExtraCamera(LocalClientNum_t localClientNum, const FxCameraUpdate *cameraUpdate);
void FX_SetNextUpdateCamera(LocalClientNum_t localClientNum, const FxCameraUpdate *cameraUpdate);
void FX_SetNextUpdateTime(LocalClientNum_t localClientNum, int time, int timeDelta);
void FX_FillUpdateCmd(LocalClientNum_t localClientNum, FxCmd *cmd);
void FX_InitFxSpawnEffectCmd(;
void FX_ProcessLooping(;
void FX_BeginLooping(;
void FX_StartNewEffect(;
unsigned __int8 FX_ProcessEmitting(;
void FX_NextElementPosition(FxUpdateElem *update, int msecUpdateBegin, int msecUpdateEnd);
void FX_SpawnImpactEffect(;
int FX_CollisionResponse(;
;
;
FxUpdateResult FX_UpdateElementPosition_Local(FxUpdateElem *update);
FxUpdateResult FX_UpdateElementPosition(FxSystem *system, FxUpdateElem *update);
void FX_SpawnDeathEffect(FxSystem *system, FxUpdateElem *update);
void FX_UpdateElement_HandleEmitting(;
void FX_UpdateElement_HandleAttachedEffect(;
FxUpdateResult FX_UpdateTrailElement(;
bool FX_UpdateEffectPartialTrail(;
void FX_RewindTo(LocalClientNum_t localClientNum, int time);
void DB_RestartEffects_Finish();
void FX_UpdateSpotLightEffectPartial(;
unsigned int FX_UpdateEffectPartialForClass(;
// void FX_UpdateEffectPartial<1>(;
// void FX_UpdateEffectPartial<0>(;
void FX_UpdateCulledEffect(;
void FX_UpdateEffect(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect);
void FX_UpdateSpotLightEffect(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect);
void FX_UpdateBatch(;
void FX_UpdateSpotLight(FxCmd *cmd);
void FX_UpdateNonSprite(FxCmd *cmd);
void FX_UpdateNonDependent(FxCmd *cmd);
void FX_UpdatePortalled(FxCmd *cmd);
void FX_UpdateRemaining(FxCmd *cmd);

//t6/code/src_noserver/effectscore/fx_update_util.cpp
void FX_OffsetSpawnOrigin(;
void FX_GetSpawnOrigin(;
void FX_SpatialFrameToOrientation(const FxSpatialFrame *frame, orientation_t *orient);
void FX_OrientationToSpatialFrame(const orientation_t *orient, FxSpatialFrame *frame);
void FX_GetOrientation_RunRelativeToOffset(;
void FX_GetOrientation(;
void FX_GetVelocityAtTime(;
void FX_OrientationPosToWorldPos(const orientation_t *orient, const vec3_t *pos, vec3_t *out);
void FX_OrientationPosFromWorldPos(const orientation_t *orient, const vec3_t *pos, vec3_t *out);
void FX_AddVisBlocker(FxSystem *system, const vec3_t *posWorld, float radius, float opacity);
void FX_ToggleVisBlockerFrame(FxSystem *system);
char FX_CullSphere(;
char FX_CullBox(const FxCamera *camera, unsigned int frustumPlaneCount, const vec3_t *mins, const vec3_t *maxs);
void FX_AnglesToOrientedAxis(const vec3_t *anglesInRad, const orientation_t *orient, vec3_t *axisOut);
void FX_GetElemAxis(;
int FX_GetElemLifeSpanMsec(int elemRandomSeed, float elemWindInterpolate, const FxElemDef *elemDef);
void FX_GetOriginForTrailElem(;

//t6/code/src_noserver/effectscore/fx_wind.cpp
void FX_SetGlobalWind(const FX_WindInfo *windInput);
FX_WindInfo *FX_GetGlobalWind();

