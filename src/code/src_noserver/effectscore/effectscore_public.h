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
bool FX_GenerateBeam_GetFlatDelta(const vector4 *invClipMtx, const __m128 *beamWorldBegin, const __m128 *beamWorldEnd, __m128 *outFlatDelta);
void FX_Beam_Begin();
void FX_Beam_Add(FxBeam *beam);
FxBeamInfo *FX_Beam_GetInfo();
void FX_Beam_GenerateVerts(int a1, const vec3_t *a2, __m128 *cmd, FxGenerateVertsCmd *a4);

//t6/code/src_noserver/effectscore/fx_convert.cpp
void FX_InterpolateSamples(int dimensions, float time0, const float *samples0, float time1, const float *samples1, float timeEval, float *result);
float FX_SampleCurve1D(const FxCurve *curve, float scale, float time);
int FX_DecideSampleCount(int curveCount, const FxCurve **curves, int intervalLimit);
int FX_DecideVelocitySampleCount(const FxEditorElemDef *edElem, int intervalLimit);
void FX_GetVisualSampleRouting(const FxEditorElemDef *edElem, FxSampleChannel *routing);
int FX_DecideVisualSampleCount(const FxEditorElemDef *edElem, const FxSampleChannel *routing, int intervalLimit);
void FX_SampleVelocityInFrame(FxElemDef *elemDef, const vec3_t *velScale, FxElemVelStateInFrame *velState, int velStateStride, int useGraphBit, const FxEditorElemDef *edElemDef);
void FX_SampleVisualStateScalar(const FxEditorElemDef *edElemDef, float sampleTime, FxSampleChannel routing, float scaleFactor, float *base, float *amplitude);
void FX_SampleVisualState(FxElemDef *elemDef, const FxEditorElemDef *edElemDef);
bool FX_ValidateAtlasSettings(const FxEditorEffectDef *editorEffect, const FxEditorElemDef *edElemDef);
void FX_ConvertAtlas(FxElemDef *elemDef, const FxEditorElemDef *edElemDef);
void FX_ReserveElemDefMemory(FxElemDef *elemDef, unsigned __int8 **memPool);
void FX_BoundFloatRange(FxFloatRange *range, float lower, float upper);
void FX_ConvertTrail_CompileVertices(const FxEditorElemDef *edElemDef, FxTrailDef *outTrailDef, unsigned __int8 **mempool);
void FX_ConvertTrail(FxTrailDef **outTrailDef, const FxEditorElemDef *edElemDef, unsigned __int8 **mempool);
void FX_ConvertSpotLight(FxSpotLightDef **outSpotLightDef, const FxEditorElemDef *edElemDef, unsigned __int8 **mempool);
int FX_FindEmission(const FxEffectDef *emission, const FxEditorEffectDef *editorEffect);
int FX_CopyEmittedElemDefs(const FxEditorEffectDef *a1, FxElemDef *elemDefArray, const FxEditorEffectDef *editorEffect, unsigned __int8 **memPool);
int FX_AdditionalBytesNeededForEmission(const FxEffectDef *emission);
bool FX_ValidateVisuals(const FxEditorEffectDef *editorEffect, const FxEditorElemDef *edElemDef);
void FX_ConvertElemDef(FxElemDef *elemDef, const FxEditorElemDef *edElemDef, int velStateCount, int visStateCount, int emitIndex, unsigned __int8 **memPool);
int FX_ConvertElemDefsOfType(FxElemDef *elemDefArray, const FxEditorEffectDef *editorEffect, int loopingFlagState, const int *velStateCount, const int *visStateCount, const int *emitIndex, unsigned __int8 **memPool);
const FxEffectDef *FX_Convert(char *a1, const FxEditorEffectDef *editorEffect, void *(*Alloc)(int));

//t6/code/src_noserver/effectscore/fx_dpvs.cpp
int FX_DpvsIsBoxVisible(FxSystem *system, const vec3_t *mins, const vec3_t *maxs);

//t6/code/src_noserver/effectscore/fx_draw.cpp
void FX_PrepareGenericLookupTables();
void FX_SetupVisualState(const FxElemDef *elemDef, int randomSeed, float normTimeUpdateEnd, FxElemPreVisualState *preVisState);
void FX_EvaluateSize(const FxElemPreVisualState *preVisState, int elemDefFlags, float *outSize0, float *outSize1);
__m128 *FX_GetExposureFloat4(LocalClientNum_t localClientNum);
void FX_ApplyLightingFrac(const FxEffect *effect, FxColor4b *outColor);
double FX_EvaluateRotation(const FxElemDef *elemDef, const FxElemPreVisualState *preVisState, float msecLifeSpan);
void FX_PrepareAtlasLookupTables();
void FX_GetSpriteTexCoords(const FxElemAtlas *atlas, int elemRandomSeed, int elemSequence, float elemMsecElapsed, float elemMsecLifeSpan, float *s0, float *ds, float *t0, float *dt);
void FX_GenSpriteVerts_Internal(const FxDrawState *draw, const FxElemRenderState *elemState, unsigned __int16 baseVertex, r_double_index_t *baseIndices, const vec3_t *tangent, const vec3_t *binormal, const vec3_t *normal);
void FX_GenTrail_IndsForSegment(FxDrawState *draw, unsigned __int16 reservedBaseVertex, r_double_index_t *outIndices);
void FX_GenTrail_VertsForSegment(const FxTrailSegmentDrawState *segmentDrawState, GfxPackedVertex *remoteVerts);
bool FX_CullElementForDraw_Sprite(const FxDrawState *draw, const FxElemRenderState *elemState);
void FX_DrawElem_BillboardSprite_NoCull(const FxDrawState *draw, FxElemRenderState *elemState);
void FX_DrawElem_BillboardSprite(const FxDrawState *draw, FxElemRenderState *elemState);
void FX_DrawElem_OrientedSprite_NoCull(char *a1, const FxDrawState *draw, FxElemRenderState *elemState);
void FX_DrawElem_OrientedSprite(const FxDrawState *draw, FxElemRenderState *elemState);
bool FX_CullCylinder(const FxCamera *camera, unsigned int frustumPlaneCount, const vec3_t *posWorld0, const vec3_t *posWorld1, float radius);
bool FX_CullElementForDraw_Tail(const FxDrawState *draw, const FxElemRenderState *elemState, const vec3_t *velDirWorld);
void FX_DrawElem_CalculateVelDirWorld(const FxDrawState *draw, const FxElemRenderState *elemState, vec3_t *result);
bool FX_CullElementForDraw_Tail_Wrapper(const FxDrawState *draw, const FxElemRenderState *elemState);
void FX_DrawElem_Tail_Main(const FxDrawState *draw, FxElemRenderState *elemState, const vec3_t *velDirWorld);
void FX_DrawElem_Tail_NoCull(const FxDrawState *draw, FxElemRenderState *elemState);
void FX_DrawElem_Tail(const FxDrawState *draw, FxElemRenderState *elemState);
bool FX_CullElement_Line(const FxDrawState *draw, const FxElemRenderState *elemState, const vec3_t *velDirWorld);
bool FX_CullElement_Line_Wrapper(const FxDrawState *draw, const FxElemRenderState *elemState);
void FX_DrawElem_Line_Main(const FxDrawState *draw, FxElemRenderState *elemState, const vec3_t *velDirWorld);
void FX_DrawElem_Line_NoCull(const FxDrawState *draw, FxElemRenderState *elemState);
void FX_DrawElem_Line(const FxDrawState *draw, FxElemRenderState *elemState);
void FX_DrawElem_RotatedSprite_NoCull(const FxDrawState *draw, FxElemRenderState *elemState);
void FX_DrawElem_RotatedSprite(const FxDrawState *draw, FxElemRenderState *elemState);
float FX_EvaluateDistanceFade(const FxDrawState *draw, const vec3_t *elemPosWorld);
void FX_DrawElem_Cloud_Main(const FxDrawState *draw, const FxElemRenderState *elemState, const vec3_t *velDirWorld, float scale);
void FX_DrawElem_Cloud_NoCull(const FxDrawState *draw, FxElemRenderState *elemState);
bool FX_CullElementForDraw_Cloud(const FxDrawState *draw, const FxElemRenderState *elemState, float scale);
bool FX_CullElement_Cloud(const FxDrawState *draw, const FxElemRenderState *elemState);
void FX_DrawElem_Cloud(vec3_t *a1, const FxDrawState *draw, FxElemRenderState *elemState);
void FX_DrawElem_Model(const FxDrawState *draw, FxElemRenderState *elemState);
bool FX_CullElementForDraw_Light(const FxDrawState *draw, const FxElemRenderState *elemState);
void FX_DrawElem_Light(const FxElemRenderState *a1, const FxDrawState *a2, const FxDrawState *draw, FxElemRenderState *elemState);
void FX_DrawElem_SpotLight_NoCull(const FxDrawState *draw, FxElemRenderState *elemState);
void FX_DrawElem_SpotLight(const FxDrawState *a1, const FxElemRenderState *a2);
float FX_EvaluateVisAlpha(const FxElemPreVisualState *preVisState);
__m128 *FX_InterpolateColor4b(const FxElemVisStateSample *refState, __m128 vlerp, __m128 vlerpInv, const float *sampleLerp, const float *sampleLerpInv);
void FX_EvaluateBaseColor(const float *a1, int a2, const FxElemPreVisualState *preVisState, FxColor4b *result);
void FX_DrawTrail_SubmitGfxDrawSurfs(FxSystem *system, FxEffect *effect, const FxTrail *trail, int effectRandomSeed, int drawRegion, int exactSegmentCount, unsigned __int16 reservedBaseVertex, r_double_index_t *reservedIndices);
double FX_OcclusionQuery_UpdateOverTime(float fCurrent, float fGoal, int iFadeInTime, int iFadeOutTime, int frametime);
FxSmpDrawBuffer *FX_InitSmpDrawBuffer();
void FX_CloudElemAllocParticleClouds(EffectElementDraw *elemDraw, unsigned __int16 numElems);
int EffectCountInfoSort(const void *elem1, const void *elem2);
int FX_FindAllTrailEffects(FxSystem *system, int firstActiveEffect, int firstNewEffect, unsigned __int16 *handlesArray, int arrayCapacity);
int FX_AllocAllTrailResource(int activeTrailEffectCount, const FxDrawTrailResourceRequired *resReqArrayRemote, FxDrawTrailResource *resArrayRemote);
void FX_TrailGeoWorkers_Start(FxSystem *remoteSystem, int drawTime, unsigned int cameraType, int numTrailEffectsResourceAllocOk, const FxDrawTrailResourceRequired *resReqArrayRemote, const FxDrawTrailResource *resArrayRemote, const unsigned __int16 *resReqTrailEffectsRemote);
void FX_LaunchElemSetupWorkers(FxGenerateVertsCmd *generateVertsCmd);
void FX_LaunchSpriteGeoWorkers(FxSystem *remoteSystem, int drawTime, unsigned int cameraType, FxSmpDrawBuffer *smpBuffer);
void FX_AllocSpriteDrawData(FxSystem *system, FxSystem *remoteSystem, unsigned int cameraType, FxSmpDrawBuffer *smpBuffer);
void FX_FillGenerateVertsCmd(LocalClientNum_t localClientNum, FxGenerateVertsCmd *cmd);
void FX_WaitForFXDrawWorkers();
void FX_LaunchFXMarksWorkers(GfxViewInfo *viewInfo);
void FX_WaitForFXMarksWorkers();
void FX_DrawElement(const FxElemDef *elemDef, const FxElem *elem, FxDrawState *draw);
void FX_DrawTrail(FxSystem *system, const FxTrail *trail);
char FX_DrawTrail_CalcRequiredResources(FxSystem *system, FxEffect *effect, const FxTrail *trail, int msecDraw, FxDrawTrailResourceRequired *req, FxTrailDrawState *trailDrawState);
void FX_DrawTrailsForEffect(FxSystem *system, const FxEffect *effect, int drawTime, const FxDrawTrailResourceRequired *resReq, const FxDrawTrailResource *res, unsigned int cameraType);
void FX_DrawSpotLightEffect(FxSystem *system, FxEffect *effectEA, int drawTime);
void FX_DrawNonSpriteEffect(FxSystem *localSystem, FxEffect *remoteEffect, FxEffect *localEffect, unsigned int elemClass, int drawTime, unsigned int cameraType, bool isInfraredDraw);
void __cdecl FX_DrawNonSpriteElems(FxSystem *system, unsigned int cameraType, bool isInfraredDraw);
void FX_DrawSpotLight(char *a1, FxSystem *system);
bool FX_ShouldDrawElement(const FxElemDef *elemDef, FxElem *elem, FxDrawState *draw);
unsigned int FX_SpriteElemDrawSetup(FxElemRenderState *elemRenderStates, FxSystem *system);
unsigned int FX_CloudElemDrawSetup(FxElemRenderState *elemRenderStates, FxSystem *system);
void FX_SpriteElemMakeQuads(FxEffect *effect, const EffectElementDraw *elemDraw, const FxElemBits *drawBits, FxSystem *system, int drawTime, int cameraType, FxElemRenderState *elemRenderStates);
void FX_SpriteElemMakeGfxDrawSurfs(FxSystem *system, FxEffect *effect, const EffectElementDraw *elemDraw, const FxElemBits *drawBits, unsigned int drawSurfRegion);
void FX_CloudElemMakeParticleClouds(FxEffect *effect, const EffectElementDraw *elemDraw, const FxElemBits *drawBits, FxSystem *system, int drawTime, unsigned int cameraType, FxElemRenderState *elemRenderStates);
void FX_CloudElemMakeGfxDrawSurfs(FxEffect *effect, const EffectElementDraw *elemDraw, const FxElemBits *drawBits, FxSystem *system);
void __cdecl FX_SMPDraw_MakeSpriteGeo(FxDrawSpriteGeoCmd *cmd);
void __cdecl FX_SMPDraw_MakeTrailGeo(FxDrawTrailGeoCmd *cmd);
void FX_ElemSetupWorker(FxElemSetupCmd *cmd);
int FX_CalculateTrailRequiredResources(int a1, FxSystem *system, int drawTime, const unsigned __int16 *const handlesArray, int numTrailEffects, FxDrawTrailResourceRequired *resReqArrayRemote, unsigned __int16 *resReqTrailEffectsRemote, FxTrailDrawState *trailDrawStateArray, int trailDrawStateArrayCapacity);
void FX_AllocTrailDrawData(FxSystem *system, FxSystem *remoteSystem, int drawTime, FxSmpDrawBuffer *smpBuffer);
void FX_GenerateSpriteDrawSurfs(FxSystem *system, unsigned int cameraType, FxSmpDrawBuffer *smpBuffer);
void FX_GenerateTrailDrawSurfs(FxSystem *system, FxSmpDrawBuffer *smpBuffer);
int fx_allocCallback(jqBatch *batch);
int fx_add_surfsCallback(jqBatch *batch);
void FX_DrawSpriteElems(FxSmpDrawBuffer *a1, FxSmpDrawBuffer *a2, float system, FxSystem *remoteSystem, FxSystem *drawTime, int cameraType, unsigned int smpBuffer, FxSmpDrawBuffer *a8);
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
bool FX_ParseGraphRange(const char **parse, int dimCount, float minValue, float maxValue, float *scale, const FxCurve **shape);
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
bool FX_ParseVelGraph0X(int a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseVelGraph0Y(int a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseVelGraph0Z(int a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseVelGraph1X(int a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseVelGraph1Y(int a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseVelGraph1Z(int a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseRotGraph(int a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseSizeGraph0(int a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseSizeGraph1(int a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseScaleGraph(int a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseColorGraph(int a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseAlphaGraph(int a1, const char **parse, FxEditorElemDef *edElemDef);
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
bool FX_ParseElemSpawnSound(FxEditorElemDef *a1, const char **parse, FxEditorElemDef *edElemDef);
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
char __cdecl FX_ParseEditorElem(int version, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseEditorEffect(const char **parse, FxEditorEffectDef *edEffectDef);
bool FX_LoadEditorEffectFromBuffer(const char *buffer, const char *parseSessionName, FxEditorEffectDef *edEffectDef);
bool FX_LoadEditorEffect(const char *name, FxEditorEffectDef *edEffectDef);
int FX_HashName(const char *name);
int FX_GetHashIndex(const char *name, bool *exists);
const FxEffectDef *FX_Register_FastFile(const char *name);
bool FX_RegisterMarkMaterials(const char *materialName, Material **materials);
bool FX_RegisterAsset_DecalMaterials(const char *name, FxElemMarkVisuals *visuals);
bool FX_ParseBillboardSprite(unsigned __int8 a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseOrientedSprite(unsigned __int8 a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseRotatedSprite(unsigned __int8 a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseCloud(unsigned __int8 a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseTail(unsigned __int8 a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseLine(unsigned __int8 a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseTrail(unsigned __int8 a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseDecal(unsigned __int8 a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseModel(unsigned __int8 a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseSpotLight(unsigned __int8 a1, const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseSound(unsigned __int8 a1, const char **parse, FxEditorElemDef *edElemDef);
const FxEffectDef *FX_LoadFailed(const char *name);
const FxEffectDef *FX_Load(const char *name);
const FxEffectDef *FX_Register_LoadObj(bool *a1, const char *a2, const char *name);
const FxEffectDef *FX_Register();
void FX_RegisterDefaultEffect();
bool FX_RegisterAsset_EffectDef(const char *name, FxElemVisuals *visuals);
char FX_ParseFxOnImpact(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseFxOnDeath(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseEmission(const char **parse, FxEditorElemDef *edElemDef);
char FX_ParseAttachment(const char **parse, FxEditorElemDef *edElemDef);
bool FX_ParseRunner(unsigned __int8 a1, const char **parse, FxEditorElemDef *edElemDef);
unsigned __int8 *Hunk_AllocPhysPresetPrecache(int size);

//t6/code/src_noserver/effectscore/fx_marks.cpp
void TRACK_fx_marks();
void FX_InitMarksSystem(FxMarksSystem *marksSystem);
void FX_ClearMarks(LocalClientNum_t localClientNum);
void FX_FreeMarkTriGroups(FxMarksSystem *marksSystem, FxMark *mark);
void FX_FreeMarkPointGroups(FxMarksSystem *marksSystem, FxMark *mark);
void FX_FreeMarkFromList(FxMarksSystem *marksSystem, FxMark *mark, unsigned __int16 *listHead);
void FX_FreeMark(FxMark *a1, FxMarksSystem *a2, FxMarksSystem *marksSystem, FxMark *mark);
void FX_FreeLruMark(char *a1, FxMarksSystem *marksSystem);
int FX_AllocMarkTris(FxMarksSystem *marksSystem, const FxMarkTri *markTris, int triCount);
int FX_AllocMarkPoints(FxMarksSystem *marksSystem, int pointCount);
void FX_LinkMarkIntoList(FxMarksSystem *marksSystem, unsigned __int16 *head, FxMark *mark, FxMark *markEA);
void FX_CopyMarkTris(FxMarksSystem *marksSystem, const FxMarkTri *srcTris, int dstGroupHandle, int triCount);
void FX_CopyMarkPoints(FxMarksSystem *marksSystem, const FxMarkPoint *srcPoints, int dstGroupHandle, int pointCount);
unsigned __int16 FX_FindModelHead(FxMarksSystem *marksSystem, unsigned __int16 modelIndex, int type);
int FX_MarkContextsCompare(const GfxMarkContext *context0, const GfxMarkContext *context1);
bool FX_CompareMarkTris(const FxMarkTri *tri0, const FxMarkTri *tri1);
char FX_ImpactMark_Generate_AddEntityBrush(LocalClientNum_t localClientNum, MarkInfo *a2, unsigned int a3, int a4, float a5, float *a6);
void FX_ImpactMark_Generate_AddEntityModel(LocalClientNum_t localClientNum, MarkInfo *markInfo, unsigned int entityIndex, const vec3_t *origin, float radius);
void FX_ImpactMark_Generate_AddViewmodel(LocalClientNum_t localClientNum, MarkInfo *markInfo, const vec3_t *origin, float radius);
void FX_BeginMarks(LocalClientNum_t clientIndex);
void FX_MarkEntDetachAll(char *a1, LocalClientNum_t localClientNum, int entnum);
void FX_MarkEntDetachAllViewmodel(LocalClientNum_t localClientNum);
void FX_MarkGlassDetachAll(char *a1, LocalClientNum_t localClientNum, int glassIndex);
void FX_MarkEntDetachAllOfType(char *a1, LocalClientNum_t localClientNum, int entnum, int markType);
void FX_MarkEntDetachMatchingBones(FxMarksSystem *marksSystem, int entnum, const unsigned int *unsetHidePartBits);
void FX_MarkEntUpdateHidePartBits(const unsigned int *oldHidePartBits, const unsigned int *newHidePartBits, LocalClientNum_t localClientNum);
void FX_MarkEntUpdateBegin(FxMarkDObjUpdateContext *context, DObj *obj, bool isBrush, unsigned __int16 brushIndex);
void FX_MarkEntDetachModel(FxMarksSystem *marksSystem, int entnum, int oldModelIndex);
void FX_MarkEntUpdateEndDObj(FxMarkDObjUpdateContext *context, LocalClientNum_t localClientNum, int entnum, DObj *obj);
void FX_MarkEntUpdateEnd(LocalClientNum_t a1, FxMarkDObjUpdateContext *a2, FxMarkDObjUpdateContext *context, LocalClientNum_t localClientNum, int entnum, DObj *obj, bool isBrush, unsigned __int16 brushIndex);
void FX_ClearViewmodelMarks(char *a1, LocalClientNum_t localClientNum);
void FX_EmitMarkTri(FxMarksSystem *marksSystem, const unsigned __int16 *indices, const GfxMarkContext *markContext, unsigned __int16 baseVertex, FxActiveMarkSurf *outSurf);
void FX_DrawMarkTris(FxMarksSystem *marksSystem, const FxMark *mark, unsigned __int16 baseVertex, unsigned __int16 *indices, FxActiveMarkSurf *outSurf);
char FX_GenerateMarkVertsForMark_Begin(float marksSystem, FxMarksSystem *a2, FxMark *mark, unsigned int *indexCount, unsigned __int16 *outBaseVertex);
void FX_GenerateMarkVertsForMark_SetLightHandle(FxActiveMarkSurf *drawSurf, unsigned __int16 lightHandleOverride);
void FX_GenerateMarkVertsForMark_SetReflectionProbeIndex(FxActiveMarkSurf *drawSurf, unsigned __int8 reflectionProbeIndexOverride);
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
void FX_MarksGridUpdate(char *a1, LocalClientNum_t localClientNum);
void FX_GenerateMarkVertsForMark_FinishNonAnimated(FxMarksSystem *marksSystem, FxMark *mark, unsigned __int16 baseVertex, FxActiveMarkSurf *drawSurf, const GfxLight *visibleLights, int visibleLightCount);
void FX_GenerateMarkVertsForMark_FinishAnimated(FxMarksSystem *marksSystem, FxMark *mark, unsigned __int16 baseVertex, FxActiveMarkSurf *drawSurf, const vec3_t *transform, const GfxLight *visibleLights, int visibleLightCount);
bool FX_GenerateMarkVertsForList_EntDObj(FxMarksSystem *marksSystem, unsigned __int16 head, const FxCamera *camera, unsigned int *indexCount, unsigned __int16 lightHandleOverride, unsigned __int8 reflectionProbeIndexOverride, const DObj *dobj, const DObjAnimMat *boneMtxList, unsigned int *hidePartBits, const GfxLight *visibleLights, int visibleLightCount);
bool FX_GenerateMarkVertsForList_EntXModel(FxMarksSystem *marksSystem, unsigned __int16 head, const FxCamera *camera, unsigned int *indexCount, unsigned __int16 lightHandleOverride, unsigned __int8 reflectionProbeIndexOverride, const GfxScaledPlacement *placement, const GfxLight *visibleLights, int visibleLightCount);
bool FX_GenerateMarkVertsForList_EntBrush(FxMarksSystem *marksSystem, unsigned __int16 head, const FxCamera *camera, unsigned int *indexCount, const GfxPlacement *placement, unsigned __int8 reflectionProbeIndex, const GfxLight *visibleLights, int visibleLightCount);
bool FX_GenerateMarkVertsForList_WorldBrush(FxMarksSystem *marksSystem, unsigned __int16 head, const FxCamera *camera, unsigned int *indexCount, const GfxLight *visibleLights, int visibleLightCount);
void FX_GenerateMarkVertsForEntXModel(char *a1, LocalClientNum_t localClientNum, int entId, unsigned int *indexCount, unsigned __int16 lightHandle, unsigned __int8 reflectionProbeIndex, const GfxScaledPlacement *placement, const GfxLight *visibleLights, int visibleLightCount);
void FX_GenerateMarkVertsForEntDObj_internal(LocalClientNum_t localClientNum, unsigned int *indexCount, unsigned __int16 lightHandle, unsigned __int8 reflectionProbeIndex, const DObj *dobj, const cpose_t *pose, FxMarksSystem *marksSystem, unsigned int *entMarkListHead, const GfxLight *visibleLights, int visibleLightCount);
void FX_GenerateMarkVertsForEntDObj(LocalClientNum_t localClientNum, int entId, unsigned int *indexCount, unsigned __int16 lightHandle, unsigned __int8 reflectionProbeIndex, const DObj *dobj, const cpose_t *pose, const GfxLight *visibleLights, int visibleLightCount);
void FX_GenerateMarkVertsForEntBrush(char *a1, LocalClientNum_t localClientNum, int entId, unsigned int *indexCount, unsigned __int8 reflectionProbeIndex, const GfxPlacement *placement, const GfxLight *visibleLights, int visibleLightCount);
void FX_GenerateMarkVertsForStaticModels(char *a1, float indexCount, LocalClientNum_t localClientNum, int smodelCount, const unsigned __int8 *smodelVisLods, const GfxStaticModelDrawInst *smodelDrawInsts, const GfxLight *visibleLights);
void FX_GenerateMarkVertsForWorld(float localClientNum, LocalClientNum_t a2, const GfxLight *visibleLights);
void FX_GenerateMarkVertsForDynamicModels(LocalClientNum_t localClientNum, const GfxLight *visibleLights, int visibleLightCount);
void FX_AllocAndConstructMark(LocalClientNum_t localClientNum, int triCount, int pointCount, Material *material, FxMarkTri *markTris, const FxMarkPoint *markPoints, const vec3_t *origin, float radius, const vec3_t *texCoordAxis, const unsigned __int8 *nativeColor, const FxMarkAlphaFade *markAlpha);
void __cdecl FX_ImpactMark_Generate_Callback(void *context, int triCount, FxMarkTri *tris, int pointCount, FxMarkPoint *points, const vec3_t *markOrigin, const vec3_t *markTexCoordAxis);
void FX_ImpactMark_Generate(LocalClientNum_t localClientNum, MarkFragmentsAgainstEnum markAgainst, Material *material, const vec3_t *origin, const vec3_t *axis, float orientation, const unsigned __int8 *nativeColor, float radius, const vec3_t *viewOffset, unsigned int markEntnum, const FxMarkAlphaFade *markAlpha, bool markViewmodel);
void FX_ImpactMark(LocalClientNum_t localClientNum, Material *worldMaterial, Material *modelMaterial, const vec3_t *origin, const vec4_t *quat, float orientation, const unsigned __int8 *nativeColor, float radius, const vec3_t *viewOffset, unsigned int markEntnum, const FxMarkAlphaFade *markAlpha, bool markViewmodel);
void FX_CreateImpactMarkInternal(LocalClientNum_t localClientNum, const FxElemDef *elemDefEA, const FxSpatialFrame *spatialFrame, int randomSeed, const vec3_t *viewOffset, unsigned int markEntnum, bool markViewmodel);
void __cdecl FX_CreateImpactMark(LocalClientNum_t localClientNum, const FxElemDef *elemDef, const FxSpatialFrame *spatialFrame, int randomSeed, unsigned int markEntnum, bool markViewmodel);
int __cdecl fx_add_markCallback(jqBatch *batch);

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
void FX_DrawPriorityDebug(LocalClientNum_t clientIndex, void (*drawFunc)(const char *, vec2_t *), vec2_t *profilePos);
int FX_CompareOccQueryDebugEntries(const void *e0, const void *e1);
void FX_DrawOccQueryDebug(LocalClientNum_t clientIndex, void (*drawFunc)(const char *, vec2_t *), vec2_t *profilePos);
const char *typeAsString(unsigned __int8 type);
void FX_DrawMarkProfile_MarkPrint(FxMarksSystem *marksSystem, unsigned __int16 head, const char *name, int index, void (*drawFunc)(const char *, vec2_t *), vec2_t *profilePos);
void __cdecl FX_DrawMarkProfile(LocalClientNum_t clientIndex, void (__cdecl *drawFunc)(const char *, vec2_t *), vec2_t *profilePos);
void FX_DebugShowNamesInWorld(LocalClientNum_t localClientNum);
void FX_ProfileSingleEffect(FxSystem *system, const FxEffect *effect, FxProfileEntry *entry);
void FX_DrawProfile(LocalClientNum_t clientIndex, void (*drawFunc)(const char *, vec2_t *), vec2_t *profilePos);

//t6/code/src_noserver/effectscore/fx_random.cpp
void TRACK_fx_random();
void FX_RandomDir(int seed, vec3_t *dir);

//#include "effectscore/fx_random.h"

//t6/code/src_noserver/effectscore/fx_sort.cpp
int FX_CalcRunnerParentSortOrder(FxEffect *effect);
void FX_SortEffects(FxSystem *system);
void FX_GetInsertSortElem(const FxSystem *system, const FxEffect *effect, const FxEffectDef *effectDef, const FxElem *elem, FxInsertSortElem *sortElem);
bool FX_ExistingElemSortsBeforeNewElem(const FxSystem *system, const FxEffect *effect, const FxEffectDef *effectDef, const FxElem *remoteElem, const FxInsertSortElem *sortElemNew);
void FX_SortSpriteElemIntoEffect(const FxSystem *system, FxEffect *effect, FxElem *remoteElem, FxElem *elem);
void FX_SortNewElemsInEffect(const FxSystem *system, FxEffect *effect);

//t6/code/src_noserver/effectscore/fx_sprite.cpp
void FX_BuildQuadStampCodeMeshVerts(Material *material, const vec3_t *viewAxis, const vec3_t *origin, const vec3_t *left, const vec3_t *up, const unsigned __int8 *rgbaColor, float s0, float t0, float s1, float t1);
bool FX_HeightScreenToWorld(const vec3_t *worldOrigin, float screenHeight, float *worldHeight, FxGenerateVertsCmd *cmd);
bool FX_HeightWorldToScreen(const vec3_t *worldOrigin, float worldHeight, float *screenHeight, FxGenerateVertsCmd *cmd);
void FX_SpriteBegin();
void FX_SpriteAdd(FxSprite *sprite);
FxSpriteInfo *FX_SpriteGetInfo();
// void FX_SpriteGenerateVerts_Internal<1>(float *a1, Material *a2, char *cmd, FxGenerateVertsCmd *a4);
void FX_SpriteGenerateVerts(float *a1, Material *a2, FxGenerateVertsCmd *cmd);

//t6/code/src_noserver/effectscore/fx_system.cpp
void TRACK_fx_system();
FxSystemContainer *FX_GetSystem(LocalClientNum_t localClientNum);
void FX_LinkSystemBuffers(FxSystem *system, FxSystemBuffers *systemBuffers);
int FX_PrintMatchingEffects(LocalClientNum_t clientNum, unsigned int testOffset, unsigned int testValue);
bool FX_CullElemForSpawn(const FxCamera *camera, const FxElemDef *elemDef, const vec3_t *origin);
bool FX_EffectHasSideEffects(const FxElemDef *elemDef);
void FX_DelRefToOwnerEffect(const FxSystem *system, unsigned int ownerEffect, unsigned int stackCount);
void FX_RunGarbageCollection_FreeSpotLight(const FxSystem *system, unsigned __int16 effectHandle);
char FX_RingBufferAllocate(volatile int *firstFree, const volatile int *firstActive, int bufferCapacity, int *outAllocIndex);
void FX_RingBufferCommit(volatile int *firstNew, const volatile int *firstFree, int allocIndex);
char FX_EffectAffectsGameplay(const FxEffectDef *remoteEffectDef);
void FX_SetEffectRandomSeed(FxEffect *effect, const FxEffectDef *remoteDef);
bool FX_SpawnEffect_AllocSpotLightEffect(const FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef);
void FX_SetWarningPriority(const FxSystem *system, unsigned __int8 priority);
void FX_InvalidateFrameWarningPriority(const FxSystem *system);
int FX_GetFrameWarningPriority(const FxSystem *system);
void FX_Priority_Begin(FxSystem *system);
void FX_AddRefToOwnerEffect(const FxSystem *system, unsigned int owner, FxEffect *newEffect);
void FX_InitEffectGroundEntity(const FxSystem *system, FxEffect *effect, const vec3_t *origin, const vec3_t *axis, int groundEntityNum);
unsigned int FX_SpawnEffectDeferred(const FxSystem *system, FxSpawnEffectCmd *cmd);
BOOL FX_SpawnWorkerShouldBeHeld(const FxSpawnEffectCmd *cmd);
void FX_AssertAllocatedEffect(LocalClientNum_t localClientNum, unsigned int hEffect, const char *error_msg);
int FX_GetEffectPlayedTime(LocalClientNum_t localClientNum, unsigned int hEffect);
BOOL FX_IsEffectDone(LocalClientNum_t localClientNum, unsigned int hEffect);
void FX_HideEffectInExtracam(LocalClientNum_t localClientNum, unsigned int hEffect, bool hide);
void FX_RandomlyRotateAxis(const vec3_t *axisIn, int randomSeed, vec3_t *axisOut);
void FX_SpawnRunner(const FxSystem *system, FxEffect *effect, const FxElemDef *elemDef, const FxSpatialFrame *effectFrameWhenPlayed, int randomSeed, int msecWhenPlayed);
void FX_GetOriginForElem(FxEffect *effect, const FxElemDef *elemDef, const FxSpatialFrame *effectFrameWhenPlayed, int randomSeed, vec3_t *outOrigin);
void FX_SpawnSound(const FxSystem *system, FxEffect *effect, const FxElemDef *elemDef, const FxSpatialFrame *effectFrameWhenPlayed, int randomSeed, int msecWhenPlayed);
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
unsigned int FX_SpawnEffect(float system, const FxSystem *a2, const FxEffectDef *remoteDef, int msecBegin, const vec3_t *origin, const vec3_t *axis, int dobjHandle, int boneIndex, int runnerSortOrder, unsigned int owner, unsigned int markEntnum, const orientation_t *boneOffset, bool markViewmodel, unsigned int preAllocatedUniqueHandle, int groundEntityNum, float primaryLightFraction, int lightingOriginOffset);
void FX_WaitForFxSpawnWorkers(LocalClientNum_t localClientNum);
unsigned int FX_SpawnOrientedEffect(char *a1, LocalClientNum_t localClientNum, const FxEffectDef *def, int msecBegin, const vec3_t *origin, const vec3_t *axis, unsigned int markEntnum, unsigned int markViewmodel, int groundEntity);
unsigned int FX_PlayOrientedEffectWithMarkEntity(LocalClientNum_t localClientNum, const FxEffectDef *def, int startMsec, const vec3_t *origin, const vec3_t *axis, unsigned int markEntnum, int groundEntity);
unsigned int FX_PlayOrientedEffectWithMarkViewmodel(LocalClientNum_t localClientNum, const FxEffectDef *def, int startMsec, const vec3_t *origin, const vec3_t *axis);
unsigned int FX_PlayOrientedEffect(LocalClientNum_t localClientNum, const FxEffectDef *def, int startMsec, const vec3_t *origin, const vec3_t *axis);
unsigned int FX_PlayOrientedEffectWithLightingParams(LocalClientNum_t localClientNum, const FxEffectDef *def, int startMsec, const vec3_t *origin, const vec3_t *axis, float primaryLightFraction);
bool FX_NeedsBoltUpdate(const FxEffectDef *def);
unsigned int FX_SpawnBoltedEffect(LocalClientNum_t localClientNum, const FxEffectDef *def, int msecBegin, int dobjHandle, int boneIndex, const vec3_t *origin, const vec3_t *axis, int groundEntity);
unsigned int FX_SpawnBoltedEffect(LocalClientNum_t localClientNum, const FxEffectDef *def, int msecBegin, int dobjHandle, int boneIndex);
unsigned int FX_SpawnBoltedEffectBoltRelative(LocalClientNum_t localClientNum, const FxEffectDef *def, int msecBegin, int dobjHandle, int boneIndex, const vec3_t *origin, const vec3_t *axis);
unsigned int FX_PlayBoltedEffect_DynEnt(LocalClientNum_t localClientNum, const FxEffectDef *def, int startMsec, int absDynEntId);
unsigned int FX_PlayBoltedEffect(LocalClientNum_t localClientNum, const FxEffectDef *def, int startMsec, int dobjHandle, int boneIndex);
unsigned int FX_PlayBoltedEffect(LocalClientNum_t localClientNum, const FxEffectDef *def, int startMsec, int dobjHandle, int boneIndex, const vec3_t *origin, const vec3_t *axis, int groundEntity);
unsigned int FX_PlayBoltedEffectBoltRelative(LocalClientNum_t localClientNum, const FxEffectDef *def, int startMsec, int dobjHandle, int boneIndex, const vec3_t *origin, const vec3_t *axis);
void FX_GetTrailHandleList_Last(FxSystem *system, FxEffect *effect, unsigned __int16 *outHandleList, int *outTrailCount);
void FX_StopEffectNonRecursive(const FxSystem *system, FxEffect *effect);
bool FX_SpawnModelPhysics(int randomSeed, FxElem *elem);
void FX_SpawnTrailElem_NoCull(const FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, FxTrail *trail, const FxElemDef *trailElemDef, const FxSpatialFrame *effectFrameWhenPlayed, int msecWhenPlayed, float distanceWhenPlayed);
void FX_SpawnTrailElem_Cull(const FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, FxTrail *trail, const FxElemDef *trailElemDef, const FxSpatialFrame *effectFrameWhenPlayed, int msecWhenPlayed, float distanceWhenPlayed);
void FX_SpawnSpotLightElem(const FxSystem *system, FxElem *elem);
void FX_FreeTrailElem(const FxSystem *system, unsigned __int16 trailElemHandle, FxEffect *effect, FxEffect *remoteEffect, FxTrail *trail);
void FX_FreeSpotLightElem(const FxSystem *system, unsigned __int16 elemHandle, FxEffect *effect);
void FX_ProcessCmd_SpawnEffect(FxSpawnEffectCmd *data);
void FX_StopEffect(const FxSystem *system, FxEffect *effect);
void FX_RemoveAllEffectElems(const FxSystem *system, FxEffect *effect, FxEffect *localEffect, const FxEffectDef *effectDef);
void FX_KillEffect(const FxSystem *system, FxEffect *effect, FxEffect *localEffect, const FxEffectDef *effectDef);
void FX_KillEffectDef(LocalClientNum_t localClientNum, const FxEffectDef *def);
void FX_KillAllEffects(LocalClientNum_t localClientNum);
void FX_RetriggerEffect(LocalClientNum_t localClientNum, FxEffect *effect, int msecBegin);
void FX_RetriggerEffect(LocalClientNum_t localClientNum, unsigned int hEffect, int msecBegin);
void FX_ThroughWithEffect(const FxSystem *system, FxEffect *effect, bool forcekill);
void FX_FreeElem(const FxSystem *system, unsigned __int16 elemHandle, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, unsigned int elemClass);
void FX_ThroughWithEffect(LocalClientNum_t localClientNum, unsigned int hEffect, bool forcekill);
void FX_SpawnElem(float system, const FxSystem *a2, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, const FxElemDef *elemDef, int elemDefIndex, const FxSpatialFrame *effectFrameWhenPlayed, int msecWhenPlayed, float distanceWhenPlayed, int sequence);
void FX_RunPrioritySorting(const FxSystem *system);

//#include "effectscore/fx_system.h"

//t6/code/src_noserver/effectscore/fx_unique_handle.cpp
FxEffect *UniqueHandleToEffect(const FxSystem *system, unsigned int handle);
unsigned int UniqueHandleAlloc(const FxSystem *system);
void UniqueHandleAssignEffect(unsigned int handle, const FxSystem *system, FxEffect *effect, FxEffect *remoteEffect);
void UniqueHandleReleaseHandle(const FxSystem *system, unsigned int handle);
void UniqueHandleRelease(const FxSystem *system, FxEffect *effect);
void UniqueHandleInit(FxUniqueHandleDb *uniqueHandleDb);
FxEffect *UniqueHandleToEffect(LocalClientNum_t localClientNum, unsigned int h);

//t6/code/src_noserver/effectscore/fx_update.cpp
bool FX_IsDemoPlaying();
void FX_SpawnTrailLoopingElems(const FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, FxTrail *trail, const FxElemDef *trailElemDef, const FxSpatialFrame *frameBegin, const FxSpatialFrame *frameEnd, int msecWhenPlayed, int msecUpdateBegin, int msecUpdateEnd, float distanceTravelledBegin, float distanceTravelledEnd);
int FX_LimitStabilizeTimeForEffectDef_Recurse(const FxEffectDef *remoteEffectDef, int originalUpdateTime);
int FX_LimitStabilizeTimeForElemDef_Recurse(const FxElemDef *elemDef, bool needToSpawnSystem, int originalUpdateTime);
void FX_SpawnLoopingElems(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, const FxElemDef *elemDef, int elemDefIndex, const FxSpatialFrame *frameBegin, const FxSpatialFrame *frameEnd, int msecWhenPlayed, int msecUpdateBegin, int msecUpdateEnd);
void FX_SpawnAllFutureLooping(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, const FxSpatialFrame *frameBegin, const FxSpatialFrame *frameEnd, int msecWhenPlayed, int msecUpdateBegin);
void FX_TriggerOneShot(const FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, const FxSpatialFrame *frameWhenPlayed, int msecWhenPlayed);
void FX_IntegrateVelocityAcrossSegments(int elemDefFlags, const orientation_t *orient, const FxElemVelStateSample *velState0, const FxElemVelStateSample *velState1, float t0, float t1, const vec3_t *amplitudeScale, float integralScale, vec3_t *posLocal, vec3_t *posWorld);
void FX_IntegrateVelocityInSegment(int elemDefFlags, const orientation_t *orient, const FxElemVelStateSample *velState, float t0, float t1, const vec3_t *amplitudeScale, float integralScale, vec3_t *posLocal, vec3_t *posWorld);
void FX_IntegrateVelocity(int a1, vec3_t *a2, float t1, const vec3_t *posLocal);
void FX_NextElementPosition_NoExternalForces(FxUpdateElem *update, int msecUpdateBegin, int msecUpdateEnd, vec3_t *posLocal, vec3_t *posWorld);
double FX_GetAtRestFraction(int a1, float a2);
void FX_GetQuatForOrientation(const FxEffect *effect, const FxElemDef *elemDef, const FxSpatialFrame *frameNow, const orientation_t *orient, vec4_t *quat);
bool FX_UpdateElement_SetupUpdate(FxEffect *effect, const FxEffectDef *effectDef, int msecUpdateBegin, int msecUpdateEnd, int elemDefIndex, int elemAtRestFraction, int elemMsecBegin, int elemSequence, float *elemOrigin, float elemWindInterp, FxUpdateElem *update);
void FX_PlayElementSpawnSound(const FxSystem *system, const FxElemDef *elemDef, const vec3_t *origin);
bool FX_UpdateElement_TruncateToElemBegin(FxUpdateElem *update, FxUpdateResult *outUpdateResult);
int FX_GetBoltTemporalBits(LocalClientNum_t localClientNum, int dobjHandle, unsigned int ignoreTeleporting);
bool FX_GetBoneOrientation_IsDObjEntityValid(LocalClientNum_t localClientNum, int dobjHandle);
char FX_GetBoneOrientation(LocalClientNum_t localClientNum, int dobjHandle, int boneIndex, orientation_t *orient);
bool FX_CanKillImmediate(const FxEffectDef *def);
int FX_UpdateEffectBolt(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef);
void FX_GetWorldBoundingBox(const vec3_t *origin, const vec3_t *orient, const vec3_t *boxCentre, const vec3_t *boxDim, unsigned int effectDefFlags, vec3_t *boxMin, vec3_t *boxMax);
int FX_TestEffectBoundingBoxMinMaxAgainstFrustum(const FxSystem *system, const vec3_t *boxMin, const vec3_t *boxMax, unsigned int effectFlags);
bool FX_ShouldProcessEffect(FxSystem *system, FxEffect *remoteEffect, FxUpdateEffectType updateEffectType);
void FX_BeginUpdate(LocalClientNum_t localClientNum);
void FX_EndUpdate(LocalClientNum_t localClientNum);
void FX_SaveGfxCloudCount(LocalClientNum_t localClientNum, int count);
void FX_SortEffectsForDraw(FxSystem *system);
void FX_AddNonSpriteDrawSurfs(FxCmd *cmd);
void DB_RestartEffects_Begin();
void FX_SetupCamera(FxCamera *camera, const vec3_t *vieworg, const vec3_t *viewaxis, const float tanHalfFovX, const float tanHalfFovY, const float zfar);
void FX_GetCameraUpdateFromRefdefAndZFar(FxCameraUpdate *cameraUpdate, const refdef_t *refdef, float zfar);
void __cdecl FX_SetExtraCamera(LocalClientNum_t localClientNum, const FxCameraUpdate *cameraUpdate);
void __cdecl FX_SetNextUpdateCamera(LocalClientNum_t localClientNum, const FxCameraUpdate *cameraUpdate);
void FX_SetNextUpdateTime(LocalClientNum_t localClientNum, int time, int timeDelta);
void FX_FillUpdateCmd(LocalClientNum_t localClientNum, FxCmd *cmd);
void FX_InitFxSpawnEffectCmd(FxSpawnEffectCmd *cmd, LocalClientNum_t clientNum, const FxEffectDef *effectDef, int msecBegin);
void FX_ProcessLooping(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, const FxSpatialFrame *frameBegin, const FxSpatialFrame *frameEnd, int msecWhenPlayed, int msecUpdateBegin, int msecUpdateEnd, float distanceTravelledBegin, float distanceTravelledEnd);
void __cdecl FX_BeginLooping(const FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, const FxSpatialFrame *frameWhenPlayed, const FxSpatialFrame *frameNow, int msecWhenPlayed, int msecNow);
void FX_StartNewEffect(const FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef);
unsigned __int8 FX_ProcessEmitting(FxSystem *system, const FxUpdateElem *update, unsigned __int8 emitResidual, const FxSpatialFrame *frameBegin, const FxSpatialFrame *frameEnd);
void FX_NextElementPosition(FxUpdateElem *update, int msecUpdateBegin, int msecUpdateEnd);
void FX_SpawnImpactEffect(FxSystem *system, const FxUpdateElem *update, const FxEffectDef *impactEffect, int msecOnImpact, const vec3_t *impactNormal);
int FX_CollisionResponse(FxSystem *system, FxUpdateElem *update, const trace_t *trace, int msecUpdateBegin, int msecUpdateEnd, vec3_t *xyzWorldOld);
FxUpdateResult FX_UpdateElementPosition_CollidingStep(FxUpdateElem *update, vec3_t *xyzWorldOld);
FxUpdateResult FX_UpdateElementPosition_Colliding(FxUpdateElem *update);
FxUpdateResult FX_UpdateElementPosition_Local(FxUpdateElem *update);
FxUpdateResult FX_UpdateElementPosition(FxSystem *system, FxUpdateElem *update);
void FX_SpawnDeathEffect(FxSystem *system, FxUpdateElem *update);
void FX_UpdateElement_HandleEmitting(FxSystem *system, FxElem *elem, const FxUpdateElem *update, const vec3_t *elemOriginPrev, FxUpdateResult *outUpdateResult);
void FX_UpdateElement_HandleAttachedEffect(FxSystem *system, FxElem *elem, const FxUpdateElem *update, FxUpdateResult updateResult);
FxUpdateResult FX_UpdateTrailElement(FxSystem *system, FxEffect *effect, const FxEffectDef *effectDef, const FxTrail *trail, FxTrailElem *trailElem, int msecUpdateBegin, int msecUpdateEnd);
bool FX_UpdateEffectPartialTrail(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, FxTrail *trail, int msecUpdateBegin, int msecUpdateEnd, float distanceTravelledBegin, float distanceTravelledEnd, unsigned __int16 trailElemHandleStart, unsigned __int16 trailElemHandleStop, FxSpatialFrame *frameNow);
void FX_RewindTo(LocalClientNum_t localClientNum, int time);
void DB_RestartEffects_Finish();
void FX_UpdateSpotLightEffectPartial(FxSystem *system, FxEffect *localEffect, FxEffect *effect, const FxEffectDef *effectDef, int msecUpdateBegin, int msecUpdateEnd);
unsigned int FX_UpdateEffectPartialForClass(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, int msecUpdateBegin, int msecUpdateEnd, unsigned __int16 elemHandleStart, unsigned __int16 elemHandleStop, unsigned int elemClass, bool OFFSCREEN);
// void FX_UpdateEffectPartial<1>(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, int msecUpdateBegin, int msecUpdateEnd, float distanceTravelledBegin, float distanceTravelledEnd, unsigned __int16 *elemHandleStart, unsigned __int16 *elemHandleStop);
// void __cdecl FX_UpdateEffectPartial<0>(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef, int msecUpdateBegin, int msecUpdateEnd, float distanceTravelledBegin, float distanceTravelledEnd, unsigned __int16 *elemHandleStart, unsigned __int16 *elemHandleStop, volatile unsigned __int16 *trailElemStart, volatile unsigned __int16 *trailElemStop);
void FX_UpdateCulledEffect(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect, const FxEffectDef *effectDef);
void FX_UpdateEffect(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect);
void FX_UpdateSpotLightEffect(FxSystem *system, FxEffect *effect, FxEffect *remoteEffect);
void FX_UpdateBatch(FxSystem *system, FxSystem *remoteSystem, int firstEffect, int lastEffect, FxUpdateEffectType updateEffectType);
void FX_UpdateSpotLight(char *a1, FxCmd *cmd);
void __cdecl FX_UpdateNonSprite(FxCmd *cmd);
void __cdecl FX_UpdateNonDependent(FxCmd *cmd);
void __cdecl FX_UpdatePortalled(FxCmd *cmd);
void __cdecl FX_UpdateRemaining(FxCmd *cmd);

//t6/code/src_noserver/effectscore/fx_update_util.cpp
void FX_OffsetSpawnOrigin(const FxSpatialFrame *effectFrame, const FxElemDef *elemDef, int randomSeed, vec3_t *spawnOrigin);
void FX_GetSpawnOrigin(const FxSpatialFrame *effectFrame, const FxElemDef *elemDef, int randomSeed, vec3_t *spawnOrigin);
void FX_SpatialFrameToOrientation(const FxSpatialFrame *frame, orientation_t *orient);
void FX_OrientationToSpatialFrame(const orientation_t *orient, FxSpatialFrame *frame);
void FX_GetOrientation_RunRelativeToOffset(const FxElemDef *elemDef, const FxSpatialFrame *frameAtSpawn, const FxSpatialFrame *frameNow, int randomSeed, orientation_t *orient);
void FX_GetOrientation(const FxElemDef *elemDef, const FxSpatialFrame *frameAtSpawn, const FxSpatialFrame *frameNow, int randomSeed, orientation_t *orient);
void FX_GetVelocityAtTime(const FxElemDef *elemDef, int randomSeed, float msecLifeSpan, float msecElapsed, const orientation_t *orient, const vec3_t *baseVel, vec3_t *velocity);
void FX_OrientationPosToWorldPos(const orientation_t *orient, const vec3_t *pos, vec3_t *out);
void FX_OrientationPosFromWorldPos(const orientation_t *orient, const vec3_t *pos, vec3_t *out);
void FX_AddVisBlocker(FxSystem *system, const vec3_t *posWorld, float radius, float opacity);
void FX_ToggleVisBlockerFrame(FxSystem *system);
char FX_CullSphere(const FxCamera *camera, unsigned int frustumPlaneCount, const vec3_t *posWorld, float radius);
char FX_CullBox(const FxCamera *camera, unsigned int frustumPlaneCount, const vec3_t *mins, const vec3_t *maxs);
void FX_AnglesToOrientedAxis(const vec3_t *anglesInRad, const orientation_t *orient, vec3_t *axisOut);
void FX_GetElemAxis(const FxElemDef *elemDef, int randomSeed, const orientation_t *orient, float msecElapsed, vec3_t *axis);
int FX_GetElemLifeSpanMsec(int elemRandomSeed, float elemWindInterpolate, const FxElemDef *elemDef);
void FX_GetOriginForTrailElem(FxEffect *effect, const FxElemDef *elemDef, const FxSpatialFrame *effectFrameWhenPlayed, int randomSeed, vec3_t *outOrigin, vec3_t *outRight, vec3_t *outUp);

//t6/code/src_noserver/effectscore/fx_wind.cpp
void FX_SetGlobalWind(const FX_WindInfo *windInput);
FX_WindInfo *FX_GetGlobalWind();

