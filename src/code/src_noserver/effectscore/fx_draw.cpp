#include "types.h"

/*
==============
FX_PrepareGenericLookupTables
==============
*/
void FX_PrepareGenericLookupTables()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SetupVisualState
==============
*/
void FX_SetupVisualState(const FxElemDef *elemDef, int randomSeed, float normTimeUpdateEnd, FxElemPreVisualState *preVisState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_EvaluateSize
==============
*/
void FX_EvaluateSize(const FxElemPreVisualState *preVisState, int elemDefFlags, float *outSize0, float *outSize1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GetExposureFloat4
==============
*/
__m128 *FX_GetExposureFloat4(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
FX_ApplyLightingFrac
==============
*/
void FX_ApplyLightingFrac(const FxEffect *effect, FxColor4b *outColor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_EvaluateRotation
==============
*/
double FX_EvaluateRotation(const FxElemDef *elemDef, const FxElemPreVisualState *preVisState, float msecLifeSpan)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_PrepareAtlasLookupTables
==============
*/
void FX_PrepareAtlasLookupTables()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GetSpriteTexCoords
==============
*/
void FX_GetSpriteTexCoords(const FxElemAtlas *atlas, int elemRandomSeed, int elemSequence, float elemMsecElapsed, float elemMsecLifeSpan, float *s0, float *ds, float *t0, float *dt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenSpriteVerts_Internal
==============
*/
void FX_GenSpriteVerts_Internal(const FxDrawState *draw, const FxElemRenderState *elemState, unsigned __int16 baseVertex, r_double_index_t *baseIndices, const vec3_t *tangent, const vec3_t *binormal, const vec3_t *normal)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenTrail_IndsForSegment
==============
*/
void FX_GenTrail_IndsForSegment(FxDrawState *draw, unsigned __int16 reservedBaseVertex, r_double_index_t *outIndices)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenTrail_VertsForSegment
==============
*/
void FX_GenTrail_VertsForSegment(const FxTrailSegmentDrawState *segmentDrawState, GfxPackedVertex *remoteVerts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_CullElementForDraw_Sprite
==============
*/
bool FX_CullElementForDraw_Sprite(const FxDrawState *draw, const FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_DrawElem_BillboardSprite_NoCull
==============
*/
void FX_DrawElem_BillboardSprite_NoCull(const FxDrawState *draw, FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawElem_BillboardSprite
==============
*/
void FX_DrawElem_BillboardSprite(const FxDrawState *draw, FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawElem_OrientedSprite_NoCull
==============
*/
void FX_DrawElem_OrientedSprite_NoCull(char *a1, const FxDrawState *draw, FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawElem_OrientedSprite
==============
*/
void FX_DrawElem_OrientedSprite(const FxDrawState *draw, FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_CullCylinder
==============
*/
bool FX_CullCylinder(const FxCamera *camera, unsigned int frustumPlaneCount, const vec3_t *posWorld0, const vec3_t *posWorld1, float radius)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_CullElementForDraw_Tail
==============
*/
bool FX_CullElementForDraw_Tail(const FxDrawState *draw, const FxElemRenderState *elemState, const vec3_t *velDirWorld)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_DrawElem_CalculateVelDirWorld
==============
*/
void FX_DrawElem_CalculateVelDirWorld(const FxDrawState *draw, const FxElemRenderState *elemState, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_CullElementForDraw_Tail_Wrapper
==============
*/
bool FX_CullElementForDraw_Tail_Wrapper(const FxDrawState *draw, const FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_DrawElem_Tail_Main
==============
*/
void FX_DrawElem_Tail_Main(const FxDrawState *draw, FxElemRenderState *elemState, const vec3_t *velDirWorld)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawElem_Tail_NoCull
==============
*/
void FX_DrawElem_Tail_NoCull(const FxDrawState *draw, FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawElem_Tail
==============
*/
void FX_DrawElem_Tail(const FxDrawState *draw, FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_CullElement_Line
==============
*/
bool FX_CullElement_Line(const FxDrawState *draw, const FxElemRenderState *elemState, const vec3_t *velDirWorld)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_CullElement_Line_Wrapper
==============
*/
bool FX_CullElement_Line_Wrapper(const FxDrawState *draw, const FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_DrawElem_Line_Main
==============
*/
void FX_DrawElem_Line_Main(const FxDrawState *draw, FxElemRenderState *elemState, const vec3_t *velDirWorld)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawElem_Line_NoCull
==============
*/
void FX_DrawElem_Line_NoCull(const FxDrawState *draw, FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawElem_Line
==============
*/
void FX_DrawElem_Line(const FxDrawState *draw, FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawElem_RotatedSprite_NoCull
==============
*/
void FX_DrawElem_RotatedSprite_NoCull(const FxDrawState *draw, FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawElem_RotatedSprite
==============
*/
void FX_DrawElem_RotatedSprite(const FxDrawState *draw, FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_EvaluateDistanceFade
==============
*/
float FX_EvaluateDistanceFade(const FxDrawState *draw, const vec3_t *elemPosWorld)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_DrawElem_Cloud_Main
==============
*/
void FX_DrawElem_Cloud_Main(const FxDrawState *draw, const FxElemRenderState *elemState, const vec3_t *velDirWorld, float scale)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawElem_Cloud_NoCull
==============
*/
void FX_DrawElem_Cloud_NoCull(const FxDrawState *draw, FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_CullElementForDraw_Cloud
==============
*/
bool FX_CullElementForDraw_Cloud(const FxDrawState *draw, const FxElemRenderState *elemState, float scale)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_CullElement_Cloud
==============
*/
bool FX_CullElement_Cloud(const FxDrawState *draw, const FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_DrawElem_Cloud
==============
*/
void FX_DrawElem_Cloud(vec3_t *a1, const FxDrawState *draw, FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawElem_Model
==============
*/
void FX_DrawElem_Model(const FxDrawState *draw, FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_CullElementForDraw_Light
==============
*/
bool FX_CullElementForDraw_Light(const FxDrawState *draw, const FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_DrawElem_Light
==============
*/
void FX_DrawElem_Light(const FxElemRenderState *a1, const FxDrawState *a2, const FxDrawState *draw, FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawElem_SpotLight_NoCull
==============
*/
void FX_DrawElem_SpotLight_NoCull(const FxDrawState *draw, FxElemRenderState *elemState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawElem_SpotLight
==============
*/
void FX_DrawElem_SpotLight(const FxDrawState *a1, const FxElemRenderState *a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_EvaluateVisAlpha
==============
*/
float FX_EvaluateVisAlpha(const FxElemPreVisualState *preVisState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_InterpolateColor4b
==============
*/
__m128 *FX_InterpolateColor4b(const FxElemVisStateSample *refState, __m128 vlerp, __m128 vlerpInv, const float *sampleLerp, const float *sampleLerpInv)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
FX_EvaluateBaseColor
==============
*/
void FX_EvaluateBaseColor(const float *a1, int a2, const FxElemPreVisualState *preVisState, FxColor4b *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawTrail_SubmitGfxDrawSurfs
==============
*/
void FX_DrawTrail_SubmitGfxDrawSurfs(FxSystem *system, FxEffect *effect, const FxTrail *trail, int effectRandomSeed, int drawRegion, int exactSegmentCount, unsigned __int16 reservedBaseVertex, r_double_index_t *reservedIndices)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_OcclusionQuery_UpdateOverTime
==============
*/
double FX_OcclusionQuery_UpdateOverTime(float fCurrent, float fGoal, int iFadeInTime, int iFadeOutTime, int frametime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_InitSmpDrawBuffer
==============
*/
FxSmpDrawBuffer *FX_InitSmpDrawBuffer()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
FX_CloudElemAllocParticleClouds
==============
*/
void FX_CloudElemAllocParticleClouds(EffectElementDraw *elemDraw, unsigned __int16 numElems)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EffectCountInfoSort
==============
*/
int EffectCountInfoSort(const void *elem1, const void *elem2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_FindAllTrailEffects
==============
*/
int FX_FindAllTrailEffects(FxSystem *system, int firstActiveEffect, int firstNewEffect, unsigned __int16 *handlesArray, int arrayCapacity)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_AllocAllTrailResource
==============
*/
int FX_AllocAllTrailResource(int activeTrailEffectCount, const FxDrawTrailResourceRequired *resReqArrayRemote, FxDrawTrailResource *resArrayRemote)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_TrailGeoWorkers_Start
==============
*/
void FX_TrailGeoWorkers_Start(FxSystem *remoteSystem, int drawTime, unsigned int cameraType, int numTrailEffectsResourceAllocOk, const FxDrawTrailResourceRequired *resReqArrayRemote, const FxDrawTrailResource *resArrayRemote, const unsigned __int16 *resReqTrailEffectsRemote)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_LaunchElemSetupWorkers
==============
*/
void FX_LaunchElemSetupWorkers(FxGenerateVertsCmd *generateVertsCmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_LaunchSpriteGeoWorkers
==============
*/
void FX_LaunchSpriteGeoWorkers(FxSystem *remoteSystem, int drawTime, unsigned int cameraType, FxSmpDrawBuffer *smpBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_AllocSpriteDrawData
==============
*/
void FX_AllocSpriteDrawData(FxSystem *system, FxSystem *remoteSystem, unsigned int cameraType, FxSmpDrawBuffer *smpBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_FillGenerateVertsCmd
==============
*/
void FX_FillGenerateVertsCmd(LocalClientNum_t localClientNum, FxGenerateVertsCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_WaitForFXDrawWorkers
==============
*/
void FX_WaitForFXDrawWorkers()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_LaunchFXMarksWorkers
==============
*/
void FX_LaunchFXMarksWorkers(GfxViewInfo *viewInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_WaitForFXMarksWorkers
==============
*/
void FX_WaitForFXMarksWorkers()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawElement
==============
*/
void FX_DrawElement(const FxElemDef *elemDef, const FxElem *elem, FxDrawState *draw)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawTrail
==============
*/
void FX_DrawTrail(FxSystem *system, const FxTrail *trail)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawTrail_CalcRequiredResources
==============
*/
char FX_DrawTrail_CalcRequiredResources(FxSystem *system, FxEffect *effect, const FxTrail *trail, int msecDraw, FxDrawTrailResourceRequired *req, FxTrailDrawState *trailDrawState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_DrawTrailsForEffect
==============
*/
void FX_DrawTrailsForEffect(FxSystem *system, const FxEffect *effect, int drawTime, const FxDrawTrailResourceRequired *resReq, const FxDrawTrailResource *res, unsigned int cameraType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawSpotLightEffect
==============
*/
void FX_DrawSpotLightEffect(FxSystem *system, FxEffect *effectEA, int drawTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawNonSpriteEffect
==============
*/
void FX_DrawNonSpriteEffect(FxSystem *localSystem, FxEffect *remoteEffect, FxEffect *localEffect, unsigned int elemClass, int drawTime, unsigned int cameraType, bool isInfraredDraw)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawNonSpriteElems
==============
*/
void __cdecl FX_DrawNonSpriteElems(FxSystem *system, unsigned int cameraType, bool isInfraredDraw)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawSpotLight
==============
*/
void FX_DrawSpotLight(char *a1, FxSystem *system)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ShouldDrawElement
==============
*/
bool FX_ShouldDrawElement(const FxElemDef *elemDef, FxElem *elem, FxDrawState *draw)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_SpriteElemDrawSetup
==============
*/
unsigned int FX_SpriteElemDrawSetup(FxElemRenderState *elemRenderStates, FxSystem *system)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_CloudElemDrawSetup
==============
*/
unsigned int FX_CloudElemDrawSetup(FxElemRenderState *elemRenderStates, FxSystem *system)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_SpriteElemMakeQuads
==============
*/
void FX_SpriteElemMakeQuads(FxEffect *effect, const EffectElementDraw *elemDraw, const FxElemBits *drawBits, FxSystem *system, int drawTime, int cameraType, FxElemRenderState *elemRenderStates)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SpriteElemMakeGfxDrawSurfs
==============
*/
void FX_SpriteElemMakeGfxDrawSurfs(FxSystem *system, FxEffect *effect, const EffectElementDraw *elemDraw, const FxElemBits *drawBits, unsigned int drawSurfRegion)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_CloudElemMakeParticleClouds
==============
*/
void FX_CloudElemMakeParticleClouds(FxEffect *effect, const EffectElementDraw *elemDraw, const FxElemBits *drawBits, FxSystem *system, int drawTime, unsigned int cameraType, FxElemRenderState *elemRenderStates)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_CloudElemMakeGfxDrawSurfs
==============
*/
void FX_CloudElemMakeGfxDrawSurfs(FxEffect *effect, const EffectElementDraw *elemDraw, const FxElemBits *drawBits, FxSystem *system)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SMPDraw_MakeSpriteGeo
==============
*/
void __cdecl FX_SMPDraw_MakeSpriteGeo(FxDrawSpriteGeoCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SMPDraw_MakeTrailGeo
==============
*/
void __cdecl FX_SMPDraw_MakeTrailGeo(FxDrawTrailGeoCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ElemSetupWorker
==============
*/
void FX_ElemSetupWorker(FxElemSetupCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_CalculateTrailRequiredResources
==============
*/
int FX_CalculateTrailRequiredResources(int a1, FxSystem *system, int drawTime, const unsigned __int16 *const handlesArray, int numTrailEffects, FxDrawTrailResourceRequired *resReqArrayRemote, unsigned __int16 *resReqTrailEffectsRemote, FxTrailDrawState *trailDrawStateArray, int trailDrawStateArrayCapacity)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_AllocTrailDrawData
==============
*/
void FX_AllocTrailDrawData(FxSystem *system, FxSystem *remoteSystem, int drawTime, FxSmpDrawBuffer *smpBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateSpriteDrawSurfs
==============
*/
void FX_GenerateSpriteDrawSurfs(FxSystem *system, unsigned int cameraType, FxSmpDrawBuffer *smpBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateTrailDrawSurfs
==============
*/
void FX_GenerateTrailDrawSurfs(FxSystem *system, FxSmpDrawBuffer *smpBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
fx_allocCallback
==============
*/
int fx_allocCallback(jqBatch *batch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
fx_add_surfsCallback
==============
*/
int fx_add_surfsCallback(jqBatch *batch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_DrawSpriteElems
==============
*/
void FX_DrawSpriteElems(FxSmpDrawBuffer *a1, FxSmpDrawBuffer *a2, float system, FxSystem *remoteSystem, FxSystem *drawTime, int cameraType, unsigned int smpBuffer, FxSmpDrawBuffer *a8)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_GenerateVerts
==============
*/
void FX_GenerateVerts(FxGenerateVertsCmd *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
fx_draw_sprite_geoCallback
==============
*/
int fx_draw_sprite_geoCallback(jqBatch *batch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
fx_draw_trail_geoCallback
==============
*/
int fx_draw_trail_geoCallback(jqBatch *batch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
fx_elemsetupCallback
==============
*/
int fx_elemsetupCallback(jqBatch *batch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

