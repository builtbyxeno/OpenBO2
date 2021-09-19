#pragma once

#include "types.h"

//t6/code/src_noserver/gfx_d3d/rb_backend.cpp
void TRACK_rb_backend();
void RB_SetIdentity();
void R_SetVertex2d(GfxVertex *vert, float x, float y, float s, float t, unsigned int color);
void RB_DrawFullSceneTri(const Material *material, unsigned __int8 scene);
void RB_TessAddQuadIndices(unsigned int vertCount);
void RB_DrawSW4Quads(const Material *material, int ParticleCount);
void RB_DrawStretchPic(;
void RB_DrawStretchPicW(;
void RB_DrawStretchPicZ(;
void RB_DrawStretchPicFlipST(;
void RB_DrawStretchPicRotate(;
void RB_DrawFullScreenColoredQuad(;
void RB_FullScreenColoredFilter(const Material *material, unsigned int color);
void RB_FullScreenFilterWithFlag(const Material *material, int filterFlags);
void RB_FullScreenFilter(const Material *material);
void RB_SplitScreenTexCoords(float x, float y, float w, float h, float *s0, float *t0, float *s1, float *t1);
void RB_SplitScreenFilter(const Material *material, const GfxViewInfo *viewInfo, unsigned int color);
void R_Resolve(GfxCmdBufContext context, GfxImage *image);
void R_ResolveFloatZ(GfxCmdBufContext context);
void RB_StretchPicCmd(GfxRenderCommandExecState *execState);
// void RB_StretchPicCmdFlipST(unsigned int a1@<edx>, GfxRenderCommandExecState *execState);
void RB_StretchPicRotateXYCmd(GfxRenderCommandExecState *execState);
void RB_StretchPicRotateSTCmd(GfxRenderCommandExecState *execState);
void RB_DrawQuadPicCmd(GfxRenderCommandExecState *execState);
void RB_DrawQuadList2DCmd(GfxRenderCommandExecState *execState);
void RB_SetUIStencilState(;
void RB_DrawUIQuadsInternal(;
void RB_DrawEmblemLayer(GfxRenderCommandExecState *execState);
void RB_StretchCompositeCmd(GfxRenderCommandExecState *execState);
void RB_DrawFullScreenColoredQuadCmd(GfxRenderCommandExecState *execState);
void TessQuad(unsigned __int16 v0, unsigned __int16 v1, unsigned __int16 v2, unsigned __int16 v3);
void RB_DrawFramedCmd(GfxRenderCommandExecState *execState);
void RB_ConstantSetCmd(GfxRenderCommandExecState *execState);
unsigned int R_RenderDrawSurfStaticModelListMaterial(;
unsigned int R_RenderDrawSurfBspListMaterial(;
unsigned int R_RenderDrawSurfListMaterial(const GfxDrawSurfListArgs *listArgs);
void R_SetCustomCodeConstants(GfxCmdBufContext context);
void R_DrawSurfs(GfxCmdBufContext context, const GfxDrawSurfListInfo *info);
void R_DrawSurfsBsp(GfxCmdBufContext context, const GfxDrawSurfListInfo *info);
void R_DrawSurfsStaticModel(GfxCmdBufContext context, const GfxDrawSurfListInfo *info);
void RB_ClearScreenCmd(GfxRenderCommandExecState *execState);
// void RB_SetGammaRamp(int a1@<ebx>, int a2@<edi>, int a3@<esi>);
void RB_BlendSavedScreenFlashedCmd(GfxRenderCommandExecState *execState);
void RB_DrawPoints2D(const GfxCmdDrawPoints *cmd);
void RB_DrawPoints3D(const GfxCmdDrawPoints *cmd);
void RB_DrawPointsCmd(GfxRenderCommandExecState *execState);
void RB_DrawLines2D(int count, int width, const GfxPointVertex *verts);
void RB_DrawLines3D(int count, int width, const GfxPointVertex *verts, bool depthTest);
void RB_DrawLinesCmd(GfxRenderCommandExecState *execState);
void RB_DrawTriangles_Internal(;
void RB_DrawUIQuadsCmd(GfxRenderCommandExecState *execState);
void RB_DrawUIQuadsReplaceImageCmd(GfxRenderCommandExecState *execState);
void RB_DrawUITrianglesCmd(GfxRenderCommandExecState *execState);
void RB_DrawTrianglesCmd(GfxRenderCommandExecState *execState);
void RB_SetCustomConstantCmd(GfxRenderCommandExecState *execState);
void RB_SetMaterialColorCmd(GfxRenderCommandExecState *execState);
void RB_BeginViewCmd(GfxRenderCommandExecState *execState);
void RB_SetViewportCmd(GfxRenderCommandExecState *execState);
void RB_SetScissorCmd(GfxRenderCommandExecState *execState);
void RB_ResolveCompositeCmd(GfxRenderCommandExecState *execState);
void RB_PCCopyImageGenMIPCmd(GfxRenderCommandExecState *execState);
void RB_LookupColor(unsigned __int8 c, unsigned __int8 *color);
float RB_DrawHudIcon(;
float RB_DrawButton(;
int RB_DrawChar(;
void RB_DrawCursor(;
void GlowColor(GfxColor *result, GfxColor baseColor, GfxColor forcedGlowColor, int renderFlags);
bool SetupFadeinFXVars(;
bool SetupCOD7DecodeFXVars(;
char SetupTypewriterFXVars(;
char SetupPopInFXVars(;
bool SetupPulseFXVars(;
void GetShiftColor(;
bool SetupRedactTextFXVars(;
void SetupRedactFXVars(;
void GetDecayingStringAlphaInfo(;
void GetDecayingLetterInfo(;
void DrawTextFxExtraCharacter(;
;
void DrawTeleType(;
void RB_DrawText(;
void RB_DrawCharInSpace(;
void RB_DrawTextInSpace(;
void RB_DrawText2DCmd(GfxRenderCommandExecState *execState);
void RB_DrawText3DCmd(GfxRenderCommandExecState *execState);
void RB_ProjectionSetCmd(GfxRenderCommandExecState *execState);
_NvAPI_Status RB_SwapBuffers();
void RB_EndFrame(unsigned int drawType);
void RB_ExecuteRenderCommandsLoop(const void *cmds, int *ui3dTextureWindow);
void RB_Draw3D();
void RB_CallExecuteRenderCommands();
void RB_SetBspImages();
void RB_SaveScreen_BlendBlurred(const GfxBlendSaveScreenBlurredParam *p);
void RB_SaveScreen_BlendFlashed(const GfxBlendSaveScreenFlashedParam *p);
// void RB_SaveScreen(int a1@<esi>, const GfxSaveScreenParam *p);
void R_DrawSurfsDepthOnly(GfxCmdBufContext context, const GfxDrawSurfListInfo *info);
void RB_Filter(const Material *material, const GfxViewInfo *viewInfo);
void RB_BeginFrame(const void *data);

//#include "gfx_d3d/rb_backend.h"

//t6/code/src_noserver/gfx_d3d/rb_corona.cpp
void RB_TessCoronaBillboard(Corona *corona, GfxColor color, float radius, int query);
void RB_DrawCoronaQuerySprite(Corona *corona);
GfxLightCorona *RB_FindBestCoronaToSpawn(CoronaState *state);
void RB_SpawnCorona(Corona *corona, GfxLightCorona *info);
void RB_PromoteCorona(CoronaState *state, Corona *corona);
void RB_DrawCorona(Corona *corona, int frameTime, const Material *coronaMat);
void RB_DrawCoronas(LocalClientNum_t localClientNum);
void RB_ResetCoronas();
void RB_DrawWaypoint(;

//t6/code/src_noserver/gfx_d3d/rb_debug.cpp
void TRACK_rb_debug();
int RB_AddDebugLine(;
int RB_EndDebugLines(int vertCount, const GfxPointVertex *verts);
void RB_SetPolyVert(const vec3_t *xyz, GfxColor color, int tessVertIndex);
void RB_DrawPolyInteriors(PolySet *polySet);
void RB_DrawPolyOutlines(PolySet *polySet);
const GfxBackEndData *RB_DrawDebugPolys();
void RB_DrawDebugSphere(trDebugSphere_t *sphere);
void RB_DrawDebugSpheres(trDebugSphere_t *spheres, int sphereCount);
void RB_DrawDebugLines(trDebugLine_t *lines, int lineCount, GfxPointVertex *verts);
void RB_DrawDebugStrings(trDebugString_t *strings, int stringCount);
// void RB_AddPlumeStrings(float a1@<edi>, const GfxViewParms *viewParms);
void RB_SetDebugBrushesAndPatchesCallback(void (*callback)());
void RB_DrawDebug(const GfxViewParms *viewParms);
void RB_ApplySunLight(const vec3_t *verts, const vec4_t *color, vec4_t *out_color);
void RB_BeginCollisionPolygons(bool faceDepthTest, bool faceBlend);
void RB_DrawCollisionPolygon(;
materialCommands_t *RB_GetCmd();
;

//t6/code/src_noserver/gfx_d3d/rb_depthprepass.cpp
void R_DepthPrepassCallback(const void *userData, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DepthPrepass(const GfxViewInfo *viewInfo, GfxCmdBuf *cmdBuf);
// void RB_DrawDepthPrepassCommandBuffer(int a1@<esi>, const GfxBackEndData *data, const GfxViewInfo *viewInfo);
void R_DrawDepthCmd(DrawDepthWorkerCmd *cmd);

//t6/code/src_noserver/gfx_d3d/rb_draw3d.cpp
void RB_DrawWaypoints(const LocalClientNum_t localClientNum, const GfxViewInfo *viewInfo);
void R_CalcGameTimeVec(float gameTime, vec4_t *out);
void R_ShowTris(GfxCmdBufContext context, const GfxDrawSurfListInfo *info);
void RB_CompositeSceneGroup();
void RB_EndSceneRendering(;
void R_RunCommandBuffer(const GfxBackEndData *data, GfxCmdBuf *cmdBuf);
void R_SetAndClearSceneTarget(const GfxViewport *viewport, const GfxViewInfo *viewInfo);
void R_DrawFullbrightLitCallback(const void *__formal, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawFullbrightDecalCallback(const void *__formal, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawFullbrightEmissiveCallback(;
void R_DrawFullbrightOrDebugShader(;
void R_DrawFullbright(const GfxViewInfo *viewInfo, GfxCmdBufInput *input, GfxCmdBuf *cmdBuf);
void RB_FullbrightDrawCommands(const GfxViewInfo *viewInfo);
int RB_FullbrightDrawCommandsCommon();
void R_DrawDebugShaderLitCallback(const void *__formal, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawDebugShaderDecalCallback(;
void R_DrawDebugShaderEmissiveCallback(;
void RB_DebugShaderDrawCommands(const GfxViewInfo *viewInfo);
const GfxBackEndData *RB_DebugShaderDrawCommandsCommon();
void RB_SetFrameBufferAlpha();
void R_DrawEmissiveOpaqueCallback(const void *__formal, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawEmissiveOpaque(const GfxViewInfo *viewInfo, GfxCmdBuf *cmdBuf);
void R_DrawEmissiveFXCallback(const void *userData, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawEmissiveFX(const GfxViewInfo *viewInfo, GfxCmdBuf *cmdBuf);
void R_DrawEmissiveFX(const GfxViewInfo *a1, GfxCmdBuf *a2);
void R_DrawViewmodelFX(const GfxViewInfo *a1, GfxCmdBuf *a2);
void R_DrawPostBlur(const GfxViewInfo *viewInfo, unsigned __int8 renderTarget);
void R_DrawSuperflare(;
void R_ResolveDistortion(const GfxViewInfo *viewInfo);
void RB_StandardRenderCommands(const GfxViewInfo *viewInfo);
void RB_SonarRenderToTexture(const GfxBackEndData *data, const GfxViewInfo *viewInfo);
unsigned int RB_DrawLitCommandBuffer(;
void RB_DrawMiscCommandBuffer(;
void RB_DrawWaypoints(const GfxViewInfo *viewInfo, unsigned __int8 renderTarget);
void RB_StandardDrawCommands_ClearScreen(const GfxViewInfo *viewInfo, const GfxBackEndData *data);
void RB_UI3D_DebugDisplay();
void RB_ExtraCam_DebugDisplay(const GfxBackEndData *data);
void RB_QRCodeImages_DebugDisplay();
void RB_DrawSonarDebugText(const GfxViewInfo *firstViewInfo, unsigned int numViewInfos);
void RB_DrawLODScaleDebugText();
int RB_StandardDrawCommandsCommon();
void RB_Draw3DCommon();
void RB_StandardDrawCommands(const GfxViewInfo *viewInfo);
void RB_Draw3DInternal();
void R_DrawPostBlur(const GfxViewInfo *viewInfo, GfxCmdBuf *cmdBuf, unsigned __int8 renderTarget);

//t6/code/src_noserver/gfx_d3d/rb_fog.cpp
// void R_SetFrameFog(float a1@<esi>, GfxCmdBufInput *input, const vec4_t *viewOrigin);

//t6/code/src_noserver/gfx_d3d/rb_imagefilter.cpp
void RB_VirtualToSceneRadius(float radius, float *radiusX, float *radiusY);
int RB_GaussianFilterPoints1D(;
// int *RB_GenerateGaussianFilter1D@<eax>(int a1@<esi>, float pixels@<xmm0>, int *res, int axis);
void RB_GenerateGaussianFilter2D(;
int RB_GenerateGaussianFilterChain(;
void RB_SetupFilterPass(const GfxImageFilterPass *filterPass);
void RB_FilterPingPong(const GfxImageFilter *filter, int passIndex);
// void RB_FilterImage(int a1@<edx>, GfxImageFilter *filter);
void RB_GaussianFilterImage(float radius, unsigned __int8 srcRenderTargetId, unsigned __int8 dstRenderTargetId);
void RB_GaussianFilter(;

//t6/code/src_noserver/gfx_d3d/rb_imagetouch.cpp
int RB_CompareTouchImages(const void *e0, const void *e1);
void RB_TouchAllImages();

//t6/code/src_noserver/gfx_d3d/rb_light.cpp
void R_CalculateLightGridColorFromCoeffs(const __m128 *coeffs, const vec3_t *dir, vec4_t *energy);
void R_DecodeLightGridCoeffsWeighted(;
// unsigned __int8 *R_DecodeLightGridColorsWeighted@<eax>(int a1@<eax>, int a2@<ecx>, float a3@<xmm0>);
void R_ComputeLightGridAverageAndVisibility(;
void R_ShowGridBox(const unsigned int *pos);
void R_ShowGridCorner(;
void R_ShowLightGrid(;
void R_SetLightGridColorsFromIndex(;
void R_BlendAndSetLightGridColors(;
void R_SetBlackLightGridColors(unsigned __int16 dest, float *destVis, GfxLightingSH *destSH);
void R_SetDebugLightGridColors(unsigned __int16 dest, float *destVis, GfxLightingSH *destSH);
bool R_LookupSkyGridVolumesAtPoint(;
unsigned __int8 R_ExtrapolateLightingAtPoint(;
unsigned __int8 R_ExtrapolateAverageLightingAtPoint(;
void R_GetLightGridSampleEntryQuad(;
bool R_IsValidLightGridSample(;
unsigned __int8 R_LightGridLookup(;
unsigned int R_GetLightingAtPoint(;
void R_GetAverageLightingAtPoint(;

//t6/code/src_noserver/gfx_d3d/rb_postfx.cpp
bool RB_UsingElectrifiedFX(const GfxViewInfo *viewInfo);
bool RB_UsingTransportedFX(const GfxViewInfo *viewInfo);
bool RB_UsingWaterSheetingFX(const GfxViewInfo *viewInfo);
bool RB_UsingDepthOfFieldFX(const GfxViewInfo *viewInfo);
bool RB_UsingGenericFilter(const GfxViewInfo *viewInfo);
int RB_FindActivePostFX(const GfxViewInfo *viewInfo);
;
void RB_CreateVisionLut(const GfxViewInfo *viewInfo);
void RB_SetBloomRemapConstants(GfxBloom bloom);
void RB_SSAO(const GfxViewInfo *viewInfo);
;
BOOL R_UsingDoubleVision(const GfxViewInfo *viewInfo);
void RB_PoisonFX(const GfxViewInfo *viewInfo);
;
void RB_FlameFX(const GfxViewInfo *viewInfo);
void RB_ElectrifiedFX(const GfxViewInfo *viewInfo);
void RB_TransportedFX(const GfxViewInfo *viewInfo);
void RB_WaterSheetingFX(const GfxViewInfo *viewInfo);
void RB_GetSceneDepthOfFieldEquation(;
float RB_GetDepthOfFieldBlurFraction(const GfxViewInfo *viewInfo, float pixelRadiusAtSceneRes);
void RB_DepthOfFieldFX(const GfxViewInfo *viewInfo);
void RB_DepthOfFieldHDR(GfxViewInfo *viewInfo, int mode);
// void RB_ReviveFX(__m128 a2@<xmm6>, const GfxViewInfo *viewInfo);
void RB_BlurSceneFX(const GfxViewInfo *viewInfo);
// void RB_AdditionalPostFX(__m128 a1@<xmm6>, const GfxViewInfo *viewInfo);
void RB_BloomLDR(const GfxViewInfo *viewInfo);

//t6/code/src_noserver/gfx_d3d/rb_query.cpp
unsigned int RB_CalcOcclusionQuerySamples();
void RB_TessRectBillboard(;
float RB_GetSampleRectRelativeArea(const vec3_t *position, int widthInPixels, int heightInPixels);
void RB_UpdateVisibilityWithoutQuery(OcclusionQuery *occlusionQuery);
void RB_DrawOcclusionQueries(LocalClientNum_t localClientNum);
void R_GetOcclusionQueryUsage(int *queryTotalCount, int *queryInUseCount);
void RB_FreeOcclusionQuery(unsigned __int16 handle);
void RB_SetOcclusionQueryPosition(unsigned __int16 handle, const vec3_t *position);
double RB_GetOcclusionQueryVisibility(unsigned __int16 handle);
// unsigned __int16 RB_AllocOcclusionQuery@<ax>(;

//#include "gfx_d3d/rb_query_d3d.h"

//t6/code/src_noserver/gfx_d3d/rb_shade.cpp
void RB_ClearPixelShader();
void RB_ClearVertexShader();
void RB_ClearVertexDecl();
void R_BeginPixMaterial(GfxCmdBufState *state);
void R_EndPixMaterial(GfxCmdBufState *state);
void R_SetPixPrimarySortKey(GfxCmdBufState *state, unsigned int primarySortKey);
void R_BeginPixMaterials(GfxCmdBufState *state);
void R_EndPixMaterials(GfxCmdBufState *state);
void R_DrawTessTechnique(GfxCmdBufContext context, const GfxDrawPrimArgs *args);
void RB_BeginSurface(const Material *material, unsigned __int8 techType, TessPrimType primType);
void RB_EndSurfaceEpilogue();
void RB_DrawTessSurface();
void RB_EndTessSurface();
void RB_TessOverflow();
void RB_SetTessTechnique(const Material *material, unsigned __int8 techType);

//t6/code/src_noserver/gfx_d3d/rb_showcollision.cpp
void TRACK_rb_showcollision();
void BuildFrustumPlanes(const GfxViewParms *viewParms, cplane_s *frustumPlanes);
void RB_DrawCollisionPoly(int numPoints, vec3_t *points, const vec4_t *colorFloat);
void RB_ShowCollision(const GfxViewParms *viewParms);

//t6/code/src_noserver/gfx_d3d/rb_sky.cpp
GfxVertex *RB_SetTessQuad(GfxColor color);
void TRACK_rb_sky();
float R_UpdateOverTime(float fCurrent, float fGoal, int iFadeInTime, int iFadeOutTime, int frametime);
void RB_DrawSunFlareCore(vec4_t *colorTint, float alpha, float sizeIn640x480);
void RB_DrawSunFlare(vec4_t *colorTint, SunFlareDynamic *sunFlare, int frameTime);
void RB_CalcSunBlind(SunFlareDynamic *sunFlare, int frameTime, float *blind, float *glare);
void RB_AddSunEffects(SunFlareDynamic *sunFlare);
void RB_DrawBlindAndGlare(SunFlareDynamic *sunFlare, int frameTime);
void RB_DrawSun(LocalClientNum_t localClientNum);
void RB_DrawSunPostEffects(;

//t6/code/src_noserver/gfx_d3d/rb_spotshadow.cpp
void R_DrawSpotShadowMapCallback(const void *userData, GfxCmdBufContext context);
void R_DrawSpotShadowMap(;
void RB_SpotShadowMaps(const GfxBackEndData *data, const GfxViewInfo *viewInfo);
void RB_DrawSpotShadowOverlay();

//t6/code/src_noserver/gfx_d3d/rb_state.cpp
void TRACK_rb_state();
void RB_InitSceneViewport();

//t6/code/src_noserver/gfx_d3d/rb_stats.cpp
const char *RB_Stats_GetStageName(GfxPrimStatsStage s);
const char *RB_Stats_GetTargetName(GfxPrimStatsTarget t);
int RB_GetCounterSum(;
void RB_TrackStageBegin(GfxFrameStats *stats, GfxPrimStatsStage stage);
void RB_TrackStageEnd(GfxFrameStats *stats);
void RB_TrackPrimsBegin(GfxFrameStats *stats, GfxPrimStatsTarget target);
void RB_TrackPrimsEnd(GfxFrameStats *stats);
void RB_TrackDrawPrimCall(GfxFrameStats *stats, int triCount);
void RB_TrackDrawSurfMat(GfxFrameStats *stats, int surfCount, int matCount);
void RB_TrackDrawDynamic(GfxFrameStats *stats, int dynamicIndexCount, int dynamicVertexCount);
void RB_TrackDrawStatic(GfxFrameStats *stats, int staticIndexCount, int staticVertexCount);
void RB_TrackGeoIndex(GfxFrameStats *stats, int geoIndexCount);
void RB_TrackFxIndex(GfxFrameStats *stats, int fxIndexCount);
void RB_Stats_Accumulate(GfxFrameStats *dest, const GfxFrameStats *src);

//t6/code/src_noserver/gfx_d3d/rb_sunshadow.cpp
void TRACK_rb_sunshadow();
void RB_SunShadowMaps(const GfxBackEndData *data, const GfxViewInfo *viewInfo);
void RB_GetShadowOverlayDepthBounds(float *nearDepth, float *farDepth);
int RB_SetSunShadowOverlayScaleAndBias();
void RB_DrawSunShadowOverlay();

//t6/code/src_noserver/gfx_d3d/rb_tess.cpp
void RB_ShowTess(GfxCmdBufContext context, const vec3_t *center, const char *tessName, const vec4_t *color);
void R_SetVertexDeclTypeNormal(GfxCmdBufState *state, MaterialVertexDeclType vertDeclType);
void R_SetVertexDeclTypeWorldSurface(GfxCmdBufState *state);
void R_SetVertexDeclTypeModelLit(const XSurface *surf, GfxCmdBufState *state);
void R_SetVertexDeclTypeModel(const XSurface *surf, GfxCmdBufState *state);
void R_TessCodeMeshList_AddCodeMeshArgs(;
// void R_SetObjectIdentityPlacement(const GfxScaledPlacement *a1@<edx>, GfxCmdBufSourceState *source);
unsigned int R_TessCodeMeshList(const GfxDrawSurfListArgs *listArgs);
unsigned int R_TessRopeMeshList(const GfxDrawSurfListArgs *listArgs);
unsigned int R_TessGlassMeshList(const GfxDrawSurfListArgs *listArgs);
unsigned int R_TessMarkMeshList(const GfxDrawSurfListArgs *listArgs);
void RB_Vec3DirWorldToView(const GfxCmdBufSourceState *source, const vec3_t *worldDir, vec3_t *viewDir);
void RB_CreateParticleCloud2dAxis(const GfxParticleCloud *cloud, const vec3_t *viewUp, vec2_t *viewAxis);
void R_SetParticleCloudConstants(;
unsigned int R_TessParticleCloudList(const GfxDrawSurfListArgs *listArgs);
void R_DrawXModelSkinnedCached(GfxCmdBufContext context, const GfxModelSkinnedSurface *modelSurf);
void R_DrawXModelSkinnedUncached(;
void R_DrawXModelSkinnedModelSurf(GfxCmdBufContext context, const GfxModelSkinnedSurface *modelSurf);
;
unsigned int R_TessXModelRigidDrawSurfList(const GfxDrawSurfListArgs *listArgs);
unsigned int R_TessXModelRigidSkinnedDrawSurfList(const GfxDrawSurfListArgs *listArgs);
unsigned int R_TessStaticModelRigidList(const GfxDrawSurfListArgs *listArgs);
unsigned int R_TessStaticModelSkinnedDrawSurfList(const GfxDrawSurfListArgs *listArgs);
unsigned int R_TessTrianglesList(const GfxDrawSurfListArgs *listArgs);
void R_SetBModelPlacement(;
unsigned int R_TessBModel(const GfxDrawSurfListArgs *listArgs);

//t6/code/src_noserver/gfx_d3d/r_add_bsp.cpp
unsigned int R_GetVisLightsMask(;
void R_InitBspDrawSurfRegions(;
void R_AddAllBspDrawSurfacesRangeCamera(;
void R_AddAllBspDrawSurfacesCameraNonlit(;
void R_AddAllBspDrawSurfacesCamera(;
void R_SortAllBspSurfacesCamera(int addAllList);
void R_AddAllBspDrawSurfacesRangeSunShadow(;
void R_SortAllBspSurfacesSunShadow();
void R_InitBspDrawSurfSunShadow(;
void R_AddAllBspDrawSurfacesSunShadow(;
void R_AddAllBspDrawSurfacesSpotShadow(;

//#include "gfx_d3d/r_add_bsp.h"

//#include "gfx_d3d/r_add_cmdbuf.h"

//t6/code/src_noserver/gfx_d3d/r_add_staticmodel.cpp
void R_SkinStaticModelsShadowForLod(;
void R_SkinStaticModelsShadow(;
void R_ShowCountsStaticModel(int smodelIndex, int lod);
GfxStaticModelId R_GetStaticModelId(int smodelIndex, int lod);
void R_StaticModelWriteInfoHeader(int fileHandle);
void R_StaticModelWriteInfo(int fileHandle, const GfxStaticModelDrawInst *smodelDrawInst, const float dist);
void R_DumpStaticModelLodInfo(const GfxStaticModelDrawInst *smodelDrawInst, const float dist);
unsigned int R_GetSModelDLightMask(;
void R_SetupSModelDrawSurfLightingDataForCamera(;
void R_StaticModelDebugAids(;
void R_SortAllStaticModelSurfacesCamera();
void R_AddAllStaticModelSurfacesRangeSunShadow(;
void R_SortAllStaticModelSurfacesSunShadow();
// void R_AddAllStaticModelSurfacesSunShadow(unsigned int a1@<edx>, int viewIndex);
void R_AddAllStaticModelSurfacesSpotShadow(;
void R_FixupSmodelCullOutDists();
void R_FixupSmodelCullOutDists(const XModel *model, const vec3_t *origin, float newCullDist);
void R_StaticModelCameraDistSort(unsigned __int16 *list, float *dists, unsigned int count);
void R_SkinStaticModelsCameraForLod(;
void R_SkinStaticModelsCamera(;
void R_AddStaticModelSurfacesCamera(;
void R_AddAllStaticModelSurfacesCamera(;

//#include "gfx_d3d/r_add_staticmodel.h"

//t6/code/src_noserver/gfx_d3d/r_adszscale.cpp
void R_SetADSZScaleConstants(GfxCmdBufInput *input, float adsZScale);

//t6/code/src_noserver/gfx_d3d/r_bsp.cpp
MaterialUsage *R_GetMaterialUsageData(const Material *material);
void R_CreateMaterialList();
void R_ShutdownMaterialUsage();
void R_CopyParseParamsFromDvars(SunLightParseParams *sunParse);
void R_InterpretSunLightParseParams(SunLightParseParams *sunParse);
void R_UpdateLightsFromDvars();
void R_CopyParseParamsToDvars(const SunLightParseParams *sunParse, int savegame);
void R_SetWorldPtr_LoadObj(const char *name);
void R_SetWorldPtr_FastFile(const char *name);
void R_LoadWorld(const char *name, int *checksum, int savegame);
signed int R_GetDebugReflectionProbeLocs(vec3_t *locArray, unsigned int maxCount);

//#include "gfx_d3d/r_bsp_load_db.h"

//t6/code/src_noserver/gfx_d3d/r_bsp_load_obj.cpp
bool ParseKVPFileFloatKVP(char *kvpFile, char *kvp, vec3_t *vec);
bool ParseKVPFileVec3KVP(char *kvpFile, char *kvp, vec3_t *vec);
void TRACK_r_bsp_load_obj();
Material *R_GetBspMaterial(unsigned int materialIndex, GfxSurface *surface);
void R_CreateWorldVertexBuffer(ID3D11Buffer **vb, const void *srcData, unsigned int sizeInBytes);
const DiskTriangleSoup *R_UpdateDiskSurfaces_Version14(const DiskTriangleSoup *oldSurfs, int surfCount);
const DiskTriangleSoup *R_UpdateDiskSurfaces_Version12(;
const DiskTriangleSoup *R_UpdateDiskSurfaces_Version8(;
void R_LoadTriangleSurfaces(;
int R_DetermineLightmapCoupling(GfxBspLoad *load, long double (*coupling)[30], LumpType lumpType);
int R_BuildLightmapMergability(;
void R_LoadLightmaps(GfxBspLoad *load);
void R_AssertLightGridValid(const GfxLightGrid *lightGrid);
void R_LoadLightGridHeader();
void R_LoadLightGridColors(unsigned int bspVersion);
GfxLightGridEntry *R_LoadLightGridEntries();
void R_LoadReflectionProbes();
int R_HeroLightSorter(const void *a, const void *b);
void R_BuildHeroLightTree(;
void R_LoadHeroOnlyLights(unsigned int bspVersion);
GfxLightCorona *R_LoadCoronas();
unsigned __int8 *R_LoadOccluders();
unsigned __int8 *R_LoadShadowMapVolumes();
unsigned __int8 *R_LoadExposureVolumes();
void R_LoadWorldFogVolumes();
void R_LoadWorldFogModifierVolumes();
void R_LoadLutVolumes();
void R_CalculateSurfaceBounds(GfxSurface *surface, const DiskGfxVertex *vertsDisk, int vertCount);
void R_MergeSurfaceLightMapCoords(;
void R_CalculateOutdoorBounds(GfxBspLoad *load, const DiskTriangleSoup *diskSurfaces);
bool R_CompareSurfaces(const GfxSurface *surf0, const GfxSurface *surf1);
BOOL R_SortSurfacesOnAxis_PosX(const GfxSurface *surf0, const GfxSurface *surf1);
BOOL R_SortSurfacesOnAxis_NegX(const GfxSurface *surf0, const GfxSurface *surf1);
BOOL R_SortSurfacesOnAxis_PosY(const GfxSurface *surf0, const GfxSurface *surf1);
BOOL R_SortSurfacesOnAxis_NegY(const GfxSurface *surf0, const GfxSurface *surf1);
void R_PackPosition(const vec3_t dataDisk, vec3_t *dataMem);
void R_PackWorldVertex0(const GfxSurface *surface, unsigned __int8 *out, const GfxWorldVertex *worldVert);
void R_PackWorldVertex1(;
void R_ValidateSurfaceLightmapUsage(const GfxSurface *surface);
void R_CalculateTriangleGroupTexCoordExtents(;
void R_LoadSubmodels();
float R_FloatForKey(const char *key, float defaultValue, char *(*spawnVars)[2], int spawnVarCount);
int R_IntForKey(const char *key, int defaultValue, char *(*spawnVars)[2], int spawnVarCount);
bool R_VectorForKey(;
void R_LoadStaticModelData(int bspVersion);
void R_LoadSkyGridVolumes(int bspVersion);
void R_PrefixStaticModelName(;
bool R_CheckValidStaticModel(char *(*spawnVars)[2], int spawnVarCount, XModel **model, vec3_t *origin);
void R_SetStaticModelsLightmapData();
// void R_LoadMiscModel(int a1@<edx>, char *(*spawnVars)[2], int spawnVarCount);
char *R_ParseSunLight(SunLightParseParams *params, const char *text);
void R_LoadPrimaryLights(unsigned int bspVersion);
void R_LoadLightRegions();
unsigned int R_GetStaticModelSortIndex(const XModel *model);
bool R_StaticModelCompare(;
int R_AabbTreeChildrenCount_r(GfxAabbTree *tree);
void R_AabbTreeFixAABBSizes_r(GfxAabbTree *tree);
GfxAabbTree *R_AabbTreeMove_r(GfxAabbTree *tree, GfxAabbTree *newTree, GfxAabbTree *newChildren);
void R_FixupGfxAabbTrees(GfxCell *cell);
BOOL R_SortStaticModelsOnAxis_NegX(;
BOOL R_SortStaticModelsOnAxis_PosY(;
BOOL R_SortStaticModelsOnAxis_NegY(;
bool R_CompareStaticModelSortModels(;
void R_LoadEntities();
int R_FinishLoadingAabbTrees_r(GfxAabbTree *tree, int totalTreesUsed);
unsigned int R_LoadAabbTrees();
void R_LoadCells(unsigned int bspVersion);
GfxPortal *R_LoadPortals();
void R_SetParentAndCell_r(mnode_load_t *node);
unsigned int R_CountNodes_r(mnode_load_t *node);
mnode_t *R_SortNodes_r(mnode_load_t *node, mnode_t *out);
void R_LoadNodesAndLeafs(unsigned int bspVersion);
unsigned __int8 *R_AllocPrimaryLightBuffers();
unsigned __int8 *R_LoadWorldRuntime();
void R_SetStaticModelReflectionProbes();
void R_IncrementShadowGeometryCount(GfxWorld *world, unsigned int primaryLightIndex);
void R_SetUpSunLight(const vec3_t *sunColor, const vec3_t *sunDirection, GfxLight *light);
void R_InterpretSunLightParseParamsIntoLights(SunLightParseParams *sunParse, GfxLight *sunLight);
void R_InitPrimaryLights(GfxLight *primaryLights);
void R_ForEachPrimaryLightAffectingSurface(;
MaterialTechniqueSet *R_GetSurfaceVertexLayerDataStride(const GfxSurface *surface);
void R_GetSurfaceVertexPosition(const GfxSurface *surface, int vertIndex, vec3_t *result);
void R_GetSurfaceVertexLmapCoord(const GfxSurface *surface, int vertIndex, vec2_t *result);
void R_GetSurfaceVertexNormal(const GfxSurface *surface, int vertIndex, vec3_t *result);
void R_RecenterSurfaceTexCoords(;
// void R_LoadSurfaces(const DiskTriangleSoup **a1@<edx>, unsigned int a2@<ecx>, GfxBspLoad *load);
void R_LoadSunSettings();
void R_ForEachShadowCastingSurfaceOnEachLight(void (*Callback)(GfxWorld *, unsigned int, unsigned int));
void R_AddShadowSurfaceToPrimaryLight(;
void R_InitShadowGeometryArrays();
void R_SpatialSortSurfaceSubArray_r(GfxSurface *beginSurf, GfxSurface *endSurf, unsigned int predIndex);
void R_SpatialSortAllSurfaces(int surfaceCount);
void R_SortSurfaces();
void R_SpatialSortStaticModelSubArray_r(;
void R_SpatialSortAllStaticModels(GfxStaticModelCombinedInst *smodelCombinedInsts);
void R_InitSortStaticModelsByModel();
void R_PostLoadEntities();
GfxWorld *R_LoadWorldInternal(const char *name);

//t6/code/src_noserver/gfx_d3d/r_buffers.cpp
void TRACK_r_buffers();
char *R_LockVertexBuffer(;
void R_UnlockVertexBuffer(ID3D11DeviceContext *device, ID3D11Buffer *handle);
char *R_LockIndexBuffer(;
void R_UnlockIndexBuffer(ID3D11DeviceContext *device, ID3D11Buffer *handle);
void *R_AllocDynamicVertexBuffer(ID3D11Buffer **vb, int sizeInBytes);
void *R_AllocStaticVertexBuffer(ID3D11Buffer **vb, int sizeInBytes, const void *data);
void *R_AllocDynamicIndexBuffer(ID3D11Buffer **ib, int sizeInBytes);
void *R_AllocStaticIndexBuffer(ID3D11Buffer **ib, int sizeInBytes, const void *data);
void Load_IndexBuffer(ID3D11Buffer **ib, void *bufferData, int indexCount);
void Load_VertexBuffer(ID3D11Buffer **vb, void *bufferData, int sizeInBytes);
void R_InitDynamicVertexBufferState(GfxVertexBufferState *vb, int bytes);
void R_InitSkinnedVertexBuffers(const SkinnedVertsDef *sv);
void R_FreeStaticVertexBuffer(ID3D11Buffer *vb);
void R_FreeStaticIndexBuffer(ID3D11Buffer *ib);
void R_ShutdownSkinnedVertexBuffers();

//t6/code/src_noserver/gfx_d3d/r_cinematic.cpp
void duck_Initialize();
void duck_Update();
void R_Cinematic_MemoryInit(CinematicInfo *cinematicInfo);
void R_Cinematic_CancelQueuedMovie(CinematicInfo *info);
bool R_Cinematic_GetPathFromFilename(;
void R_Cinematic_StartSound(CinematicInfo *info, bool startPaused);
void *R_Cinematic_OpenMovie_Now(;
void StreamThread_OpenMovie(int msAllotted, void *user);
void R_Cinematic_QueueStreamOpen(bool isNextBink, bool isNeededImmediately);
void R_Cinematic_PopFromQueue();
void R_Cinematic_RemoveInactiveFromQueue(int a1);
void StreamThread_GetMoviePath(int msAllotted, void *user, int id);
void R_Cinematic_StartPlayback_Internal(;
int R_Cinematic_GetPlayingId();
int R_Cinematic_StartPlayback(;
char R_Cinematic_StopPlayback(int id, bool cancelAll);
void R_Cinematic_HandleFinishedCallbacks(CIN_CALLBACK_TYPE type);
char R_Cinematic_UpdateSoundTime();
void R_Cinematic_UpdateFrame(bool force_wait);
char R_Cinematic_GetFilenameAndTimeInMsec(int id, char *outName, int outNameSize, unsigned int *outTimeInMsec);
char R_Cinematic_IsAnyPlaying();
char R_Cinematic_IsInProgress(int id);
char R_Cinematic_IsPreloading(int id);
void R_Cinematic_GetDebugInfo(const char **name, int *bytesUsed);
void R_Cinematic_ForceRelinquishIO();

//t6/code/src_noserver/gfx_d3d/r_cinematic_bink.cpp
const char *R_Cinematic_CheckBinkError();
void CinematicHunk_Open(CinematicHunk *hunk, void *memory, int size);
void CinematicHunk_Close(CinematicHunk *hunk);
void CinematicHunk_Reset(CinematicHunk *hunk);
int CinematicHunk_GetFreeSpace(CinematicHunk *hunk);
void *CinematicHunk_Alloc(CinematicHunk *hunk, int size);
// double BinkMoviePlayer::GetTimeRemaining(void *handle);
// void BinkMoviePlayer::SetPaused(void *handle, bool paused, bool forUnderrun);
// void **BinkMoviePlayer::GetMaxTextureBytesNeeded();
// unsigned int BinkMoviePlayer::GetMainBytesNeeded(unsigned int playbackFlags);
// GfxImage *BinkMoviePlayer::R_Cinematic_BlackRendererImages();
// void BinkMoviePlayer::InitMemory(;
// void __thiscall BinkMoviePlayer::Destroy(CinematicHunk *this);
// void BinkMoviePlayer::R_Cinematic_ReleaseImages(CinematicTextureSet *textureSet);
// int BinkMoviePlayer::MakeBinkTexturePC(;
// HRESULT BinkMoviePlayer::R_Cinematic_MakeBinkDrawTextures@<eax>(;
// HRESULT BinkMoviePlayer::R_Cinematic_InitBinkTextures@<eax>(unsigned int *a1@<edi>);
// void BinkMoviePlayer::R_Cinematic_Unlock_textures();
// void BinkMoviePlayer::R_Cinematic_SetRendererImagesToFrame(int frameToSetTo);
// double BinkMoviePlayer::GetTimeElapsed();
// void BinkMoviePlayer::SetMovieClock(void *handle, float time);
// void BinkMoviePlayer::SetVolume(void *handle, float volume);
// int BinkMoviePlayer::GetBufferFillPercentage(void *handle);
// bool __thiscall BinkMoviePlayer::IsUnderrun(void *this);
// int BinkMoviePlayer::R_Cinematic_BinkWaitAsyncDecode(BINK *bink, int waitMs);
// bool __thiscall BinkMoviePlayer::IsReadyToStart(void *this);
// void BinkMoviePlayer::StreamThread_DoBackgroundIO_Bink(int msAllotted, void *user, int id);
// void BinkMoviePlayer::StartPlayback(void *handle, unsigned int playbackFlags);
// const char *BinkMoviePlayer::AdvanceFrame();
// void BinkMoviePlayer::R_Cinematic_Lock_textures(;
// const char *BinkMoviePlayer::R_Cinematic_BinkLaunchAsyncDecode@<eax>(;
// void BinkMoviePlayer::DoFrameSync(D3D11_MAPPED_SUBRESOURCE *a1@<ebx>, int a2@<edi>, int a3@<esi>);
// void BinkMoviePlayer::UpdateMoviesAndImages(;
// char BinkMoviePlayer::ForceRelinquishIO();
// void *BinkMoviePlayer::Bink_Alloc_Alt(unsigned int bytes);
// void BinkMoviePlayer::Bink_Free(void *ptr);
// void BinkMoviePlayer::Bink_Free_Alt(void *ptr);
// void BinkMoviePlayer::PreOpen_Common(bool isNextBink);
// void BinkMoviePlayer::PostOpen_Common(BINK *pbink, unsigned int playbackFlags, bool isNextBink);
// ;
// BINK *BinkMoviePlayer::OpenFromFastfile(const char *assetname, unsigned int playbackFlags);
// BINK *BinkMoviePlayer::OpenPath(const char *filepath, unsigned int playbackFlags);
// void BinkMoviePlayer::StopPlayback(void *handle);
MoviePlayerFunctions *R_Cinematic_GetBinkFunctions();
// int launch_async_bink_drawCallback@<eax>(D3D11_MAPPED_SUBRESOURCE *a1@<ebx>, jqBatch *batch);

//t6/code/src_noserver/gfx_d3d/r_cmdbuf.cpp
void R_ShutdownCmdBuf(GfxCmdBuf *cmdBuf);
void R_InitContext(const GfxBackEndData *data, GfxCmdBuf *cmdBuf);

//t6/code/src_noserver/gfx_d3d/r_compile_shader.cpp
void Material_EmitShaderString(GfxAssembledShaderText *prog, const char *string);
void Material_AddShaderFile(GfxAssembledShaderText *prog, const char *shaderFileName, unsigned int srcLine);
char Material_FindCachedShaderText(const char *filename, const char **data, unsigned int *byteCount);
void Material_FileIncludeFileAndLineNumber(;
bool Material_PreLoadSingleShaderText(const char *filename, const char *subdir, GfxCachedShaderText *cached);
bool Material_CachedShaderTextLess(const GfxCachedShaderText *cached0, const GfxCachedShaderText *cached1);
bool Material_IncludeShader(GfxAssembledShaderText *prog, const char *includeName, bool isInLibDir);
bool Material_GenerateShaderString_r(GfxAssembledShaderText *prog, const char *shaderName, const char *file);
unsigned int Material_GenerateShaderString(;
ID3D10Blob *Material_CompileShader(;

//t6/code/src_noserver/gfx_d3d/r_debug.cpp
void TRACK_r_debug();
void R_AddDebugPolygonInternal(;
void R_AddDebugPolygon(;
void R_AddPersistentDebugPolygon(;
void R_ClearPersistentDebugPolygons();
void R_AddDebugLine(;
void R_AddDebugBox(;
;
void R_AddDebugString(;
void R_AddScaledDebugString(;
void R_InitDebugEntry(DebugGlobals *debugGlobalsEntry);
void R_ShutdownDebugEntry(DebugGlobals *debugGlobalsEntry);
void R_UpdatePersistentDebugPolys(DebugGlobals *debugGlobalsEntry);
void R_TransferDebugGlobals(DebugGlobals *debugGlobalsEntry);
void R_ShutdownDebug();
void R_CopyDebugStrings(;
void R_CopyDebugLines(;
void R_CopyDebugSpheres(;
void R_AddDebugAxis(;
void R_AddDebugPolygonOutline(;

//t6/code/src_noserver/gfx_d3d/r_debug_alloc.cpp
void R_DebugAlloc(void **memPtr, int size, const char *name);
void R_DebugFree(void **dataPtr);

//t6/code/src_noserver/gfx_d3d/r_dobj_skin.cpp
int R_PreSkinXSurface(const GfxModelSurfaceInfo *surfaceInfo, unsigned __int8 *surfPos);
unsigned int R_GetSkinSurfaceBufferSize(GfxSceneEntity *sceneEnt, const DObj *obj);
void R_GetPartBitsForSurfaceAndBoneIndex(XSurface *xsurf, unsigned int boneIndex, int *partBits);
unsigned int R_SkinSceneDObjModels(GfxSceneEntity *sceneEnt, const DObj *obj);
void R_FlagXModelAsSkinned(GfxSceneEntity *sceneEnt, unsigned int surfaceCount);
void R_SkinSceneDObj(;
void R_SkinGfxEntityCmd(void *data);

//t6/code/src_noserver/gfx_d3d/r_dpvs.cpp
// int DpvsCachedCell::Compare(const void *lhs, const void *rhs);
void TRACK_r_dpvs();
void R_GetSidePlaneNormals(const vec3_t *winding, unsigned int vertexCount, vec3_t *normals);
float R_FurthestPointOnWinding(const vec3_t *points, int pointCount, const DpvsPlane *plane);
float R_NearestPointOnWinding(const vec3_t *points, int pointCount, const DpvsPlane *plane);
void R_FrustumClipPlanes(;
char *R_PortalAssertMsg();
void R_ProjectPortal(;
void R_UnprojectPoint(GfxViewParms *viewParms, const vec2_t *projected, vec4_t *unprojected);
unsigned int R_AddBevelPlanes(;
unsigned int R_PortalClipPlanes(;
unsigned int R_PortalClipPlanesNoFrustum(DpvsPlane *planes, unsigned int vertexCount, const vec3_t *winding);
bool R_PortalBehindAnyPlane(const GfxPortal *portal, const DpvsPlane *planes, int planeCount);
const vec3_t *R_ChopPortalWinding(;
unsigned int R_GetLightingMask_Box(;
unsigned int R_GetLightingMask_Sphere(;
void R_AddSceneEntSurfs_SceneDObjs(AddSceneEntSurfsCmd *cmd);
void R_AddSceneEntSurfs_SceneModels(AddSceneEntSurfsCmd *cmd);
void R_AddSceneEntSurfs_SceneDynEnts(AddSceneEntSurfsCmd *cmd);
void R_AddSceneEntSurfs_SceneBrush(AddSceneEntSurfsCmd *cmd);
void R_AddSceneEntSurfs_SceneGlassBrush(AddSceneEntSurfsCmd *cmd);
void R_AddSceneEntSurfs_SceneDynBrush(AddSceneEntSurfsCmd *cmd);
void R_InitSceneEntDrawSurfs(;
void R_FinishSceneEntDrawSurfs(GfxDrawSurf **drawSurfs);
void R_AddAllSceneEntSurfacesCamera(;
void R_AddAllSceneEntSurfacesRangeSunShadow(unsigned int partitionIndex);
void R_AddAllSceneEntSurfacesSunShadow();
void R_AddAllSceneEntSurfacesSpotShadow(;
int R_DrawBModel(;
void R_CullDynBrushInCell(unsigned int cellIndex, const DpvsPlane *planes, int planeCount);
void R_DrawAllSceneEnt(const GfxViewInfo *viewInfo);
void R_DrawAllDynEnt(const GfxViewInfo *viewInfo);
void R_FilterEntIntoCells_r(;
void R_FilterDynEntIntoCells_r(;
void R_UnfilterEntFromCells(LocalClientNum_t localClientNum, unsigned int entnum);
void R_UnfilterDynEntFromCells(unsigned int dynEntId, DynEntityDrawType drawType);
void R_FilterDObjIntoCells(;
void R_FilterBModelIntoCells(;
void R_FilterDynEntIntoCells(;
int R_DpvsBoxIsVisible(;
void R_FilterXModelIntoScene(;
void R_InitialEntityCulling();
void R_GetStaticModelsAabb(;
void R_GetStaticModels(const vec3_t *mins, const vec3_t *maxs, int *models, int *models_count, int max_models);
void R_AddCellDynBrushSurfacesInFrustumCmd(void *data);
void R_FinishDpvsDynamicBatch(DpvsDynamicCellCmd *dpvsDynamicBatch, bool bRunCmd);
void R_AddDpvsDynamicBatch(;
void R_AddCellSurfacesInFrustumDelayed(;
void R_CacheCell(int cellIndex, int planeIndex, int planeCount, int frustumPlaneCount);
void R_AddCellSurfaces(;
void R_AssertValidQueue();
// void R_EnqueuePortal(const vec3_t *a1@<ecx>, const DpvsPlane *a2@<edi>, float a3@<xmm0>, GfxPortal *portal);
GfxPortal *R_NextQueuedPortal();
void R_AddVertToPortalHullPoints(GfxPortal *portal, const vec3_t *v);
int R_ChopPortal(;
bool R_ChopPortalAndAddHullPoints(;
bool R_ChopPortalAndAddHullPointsNoFrustum(;
int R_GetFurtherCellList_r(;
void R_SetCellVisible(unsigned int cellIndex);
void R_VisitAllFurtherCells(;
void R_SetAncestorListStatus(GfxPortal *portal, bool isAncestor);
int R_VisitPortalsForCell(;
void R_VisitPortals(;
void R_VisitPortalsForCellNoFrustum(;
void R_VisitPortalsNoFrustum(const GfxCell *cell);
void R_GenerateShadowMapCasterCells();
void R_AddSunShadowSurfacesFrustumOnly(unsigned int viewIndex, bool cache);
void R_ShowCull(const vec3_t *viewOrigin);
void R_InitSceneData(LocalClientNum_t localClientNum);
void DynEntCl_InitFilter();
void R_InitSceneBuffers();
void R_ClearDpvsScene(LocalClientNum_t previousLocalClientNum, bool bIsExtraCam);
void R_CullDynamicPointLightsInCameraView();
void R_EnableOccluder(const char *name, bool enable);
void R_SetViewFrustumPlanes(GfxViewInfo *viewInfo);
void R_AddWorldSurfacesPortalWalk(int cameraCellIndex, DpvsDynamicCellCmd *pDynamicBatch);
void R_DpvsClearCellVisibility();
void R_StartCachedDpvsBatches(unsigned int view, unsigned int batchMask);
void R_SetupShadowSurfacesDpvs(;
double R_GetFarPlaneDist();
void R_SetCullDist(float dist);
int R_CullBoxCurDpvs_SceneSelect(;
int R_CullBoxCurDpvs(const vec3_t *mins, const vec3_t *maxs, unsigned int viewIndex);
int R_CullPoint(LocalClientNum_t localClient, const vec3_t *p0, float cutoff);
int R_CullPoint(int max_local_clients, const vec3_t *point, float cutoff);
int R_CullLine(int localClient, const vec3_t *p0, const vec3_t *p1, float cutoff);
unsigned int R_ExtraCam_SaveDpvsData(;
void R_ExtraCam_RestoreDpvsData(LocalClientNum_t localClientNum, unsigned __int8 *buffer);
void R_PerMap_DpvsGlobInit();
int r_sceneents_dobjCallback(jqBatch *batch);
int r_sceneents_modelCallback(jqBatch *batch);
int r_sceneents_dynentCallback(jqBatch *batch);
int r_sceneents_brushCallback(jqBatch *batch);
int r_sceneents_glassbrushCallback(jqBatch *batch);
int r_sceneents_dynbrushCallback(jqBatch *batch);
void R_DpvsStartCachedShadowBatches(unsigned int viewIndex);
void R_SetupWorldSurfacesDpvs(const GfxViewParms *viewParms, unsigned int renderCullFlags);
void R_AddWorldSurfacesDpvs();
void R_DpvsGetVisibleCells(int cameraCellIndex);

//#include "gfx_d3d/r_dpvs.h"

//t6/code/src_noserver/gfx_d3d/r_dpvs_dynmodel.cpp
void R_CullDynModelInCell(;
void R_AddCellDynModelSurfacesInFrustumCmd(void *data);

//t6/code/src_noserver/gfx_d3d/r_dpvs_entity.cpp
void R_AddEntitySurfacesInFrustum(;
void R_ForceAddEntitySurfacesInFrustum(GfxSceneEntity *sceneEnt, unsigned __int8 *entVisData);

//t6/code/src_noserver/gfx_d3d/r_dpvs_sceneent.cpp
void R_AddCellSceneEntSurfacesInFrustum(;
void R_AddCellSceneEntSurfacesInFrustumCmd(void *data);

//t6/code/src_noserver/gfx_d3d/r_dpvs_static.cpp
int R_CullBoxLeaf(const vec3_t *mins, const vec3_t *maxs, DpvsClipPlanes *planes);
char TestOccluders(const vec3_t *bounds, int numOccluders, vec4_t *plane);
vec4_t *TestOccludersPartial(const vec3_t *bounds, int *numOccludersPtr, vec4_t *plane);
;
int R_AddCellStaticSurfacesInFrustum(const DpvsPlanes *planes);
void R_AddCellStaticSurfacesInFrustumCmd(void *data);

//t6/code/src_noserver/gfx_d3d/r_drawsurf.cpp
GfxWorld *R_SetPrimaryLightShadowSurfaces();
int R_GetWorldDrawSurf(GfxSurface *worldSurf);
void R_SortWorldSurfaces();
GfxDrawSurf *R_AllocFxDrawSurf(unsigned int region);
unsigned int R_GetDrawSurfRegionForSortKey(const Material *material, unsigned int baseRegion);
void R_AddCodeMeshDrawSurf(;
void R_AddCodeMeshDrawSurf_UseIndices(;
void R_AddRopeCodeMeshDrawSurf(;
// FxCodeMeshData *R_AddGlassDrawSurf@<eax>(;
void R_AddMarkMeshDrawSurf(;
// char R_AddParticleCloudDrawSurf@<al>(float a1@<xmm0>, unsigned int cloudIndex, Material *material);
void R_BeginCodeMeshVerts();
void R_EndCodeMeshVerts();
void R_BeginMarkMeshVerts();
void R_EndMarkMeshVerts();
// char R_ReserveCodeMeshIndices@<al>(float a1@<xmm0>, int indexCount, r_double_index_t **indicesOut);
// char R_ReserveCodeMeshVerts@<al>(float a1@<xmm0>, int vertCount, unsigned __int16 *baseVertex);
// char R_ReserveCodeMeshArgs@<al>(float a1@<xmm0>, int argCount, unsigned int *argOffsetOut);
// char R_ReserveMarkMeshIndices@<al>(float a1@<xmm0>, int indexCount, r_double_index_t **indicesOut);
// char R_ReserveMarkMeshVerts@<al>(float a1@<xmm0>, int vertCount, unsigned __int16 *baseVertex);
vec4_t *R_GetCodeMeshArgs(unsigned int argOffset);
GfxPackedVertex *R_GetCodeMeshVerts(unsigned __int16 baseVertex);
GfxWorldVertex *R_GetMarkMeshVerts(unsigned __int16 baseVertex);
// void R_SortDrawSurfs(int a1@<edx>, GfxDrawSurf *drawSurfList);

//t6/code/src_noserver/gfx_d3d/r_draw_bsp.cpp
void R_SetStreamsForBspSurface(GfxCmdBufPrimState *state, const srfTriangles_t *tris);
void R_DrawTrianglesLit(GfxTrianglesDrawStream *drawStream, GfxCmdBufState *state);
void R_DrawTriangles(GfxTrianglesDrawStream *drawStream, GfxCmdBufState *state);
void R_DrawBspDrawSurfsLit(const unsigned int *primDrawSurfPos, GfxCmdBufContext context);
void R_DrawBspDrawSurfs(const unsigned int *primDrawSurfPos, GfxCmdBufContext context);

//t6/code/src_noserver/gfx_d3d/r_draw_lit.cpp
void R_DrawSonarCallback(const void *__formal, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawSonar(const GfxViewInfo *viewInfo, GfxCmdBuf *cmdBuf);
void R_DrawLitQuasiOpaqueCallback(const void *__formal, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawLitQuasiOpaque(const GfxViewInfo *viewInfo, GfxCmdBuf *cmdBuf);
void R_DrawTransCallback(const void *userData, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawTransInternal(const GfxViewInfo *viewInfo, GfxCmdBuf *cmdBuf);
void R_DrawTrans(const GfxViewInfo *a1, GfxCmdBuf *a2);
void R_DrawTransPostFX(const GfxViewInfo *a1, GfxCmdBuf *a2);
void RB_SetSonarCodeImages(GfxCmdBufSourceState *source);
void R_AdjustDrawsurfListToCmdBufPartition(;
void R_DrawLit(const GfxViewInfo *viewInfo, GfxCmdBuf *cmdBuf, LitPhaseID phase);
void R_DrawLitBsp(const GfxViewInfo *viewInfo, GfxCmdBuf *cmdBuf, LitPhaseID phase);
void R_DrawLitStaticModel(const GfxViewInfo *viewInfo, GfxCmdBuf *cmdBuf, LitPhaseID phase);
void R_DrawViewModelTransCallback(const void *userData, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawViewModelTrans(const GfxViewInfo *viewInfo, GfxCmdBuf *cmdBuf);
void R_PostBlurCallback(const void *userData, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
;
;
;

//t6/code/src_noserver/gfx_d3d/r_draw_material.cpp
unsigned __int8 RemoveShadowTech(unsigned __int8 srcTech);
int R_SetPrepassMaterial(GfxCmdBufContext context, GfxDrawSurf drawSurf, unsigned __int8 techType);
int R_SetMaterial(GfxCmdBufContext context, GfxDrawSurf drawSurf, const Material **techType);
int R_SetMaterialNoShaderConstantSet(GfxCmdBufContext context, GfxDrawSurf drawSurf, unsigned __int8 techType);
unsigned __int8 R_GetTechType(;
const char *RB_LogTechniqueType(unsigned __int8 techType);
// int R_SetTechnique@<eax>(;
// int R_SetLitTechniqueNoShaderConstantSet@<eax>(;
void R_SetGameTime(GfxCmdBufSourceState *source, float gameTime);
int R_UpdateMaterialTime(GfxCmdBufSourceState *source, float materialTime, float burn);

//t6/code/src_noserver/gfx_d3d/r_draw_method.cpp
void R_SetDefaultLitTechTypes();
void R_InitDrawMethod();
void R_UpdateDrawMethod(GfxBackEndData *data);

//t6/code/src_noserver/gfx_d3d/r_draw_model_util.cpp
void R_SetStreamsForXModelSurface(const XSurface *localSurf, GfxCmdBufState *state);

//t6/code/src_noserver/gfx_d3d/r_draw_shadowablelight.cpp
void R_SetLightProperties(;
void R_SetShadowableLight(GfxCmdBufSourceState *source, unsigned int shadowableLightIndex);

//t6/code/src_noserver/gfx_d3d/r_draw_staticmodel.cpp
void R_SetStaticModelVertexBuffer(GfxCmdBufPrimState *primState, XSurface *xsurf);
void R_SetStaticModelIndexBuffer(GfxCmdBufPrimState *primState, XSurface *xsurf);
void R_DrawStaticModelUnlitNoPrepass(GfxStaticModelDrawStream *drawStream);
;
;
void R_DrawStaticModelsLit(GfxStaticModelDrawStream *drawStream, GfxCmdBufContext context);
void R_DrawStaticModels(GfxStaticModelDrawStream *drawStream, GfxCmdBufContext context);
void R_DrawStaticModelSurfLit(;
void R_DrawStaticModelDrawSurfPlacement(;
void R_DrawStaticModelDrawSurfNonOptimized(GfxStaticModelDrawStream *drawStream, GfxCmdBufContext context);
void R_DrawStaticModelsSkinnedDrawSurfLighting(GfxStaticModelDrawStream *drawStream, GfxCmdBufContext context);
void R_DrawStaticModelsSkinnedDrawSurf(GfxStaticModelDrawStream *drawStream, GfxCmdBufContext context);
void R_DrawStaticModelSkinnedSurfLit(;
void R_DrawStaticModelSkinnedSurf(;
void R_DrawStaticModelSurf(;

//t6/code/src_noserver/gfx_d3d/r_draw_sunshadow.cpp
void R_DrawSunShadowMapCallback(const void *userData, GfxCmdBufContext context);
void R_DrawSunShadowMap(;

//t6/code/src_noserver/gfx_d3d/r_draw_xmodel.cpp
void R_GetWorldMatrixForModelSurf(;
const GfxModelRigidSurface *R_GetLocalModelSurfaceOnly(const GfxBackEndData *data, GfxDrawSurf drawSurf);
// unsigned int R_DrawXModelSurfLitInternal@<eax>(;
// GfxCmdBufSourceState *R_DrawXModelSurfCameraInternal@<eax>(;
// XSurface *R_DrawXModelSurfInternal@<eax>(;
// unsigned int R_DrawXModelSurfLit@<eax>(;
// GfxCmdBufSourceState *R_DrawXModelSurfCamera@<eax>(;
// XSurface *R_DrawXModelSurf@<eax>(;

//#include "gfx_d3d/r_draw_xmodel.h"

//t6/code/src_noserver/gfx_d3d/r_dvars.cpp
void R_RegisterDvars();
bool R_CheckDvarModified(const dvar_t *dvar);
double R_GetDefaultNearClip();
double R_GetDefaultNearClip_DepthHack();
void DvarBlock_SetFog();
void DvarBlock_SetWSI();
void DvarBlock_SetVcBloom();
void DvarBlock_SetVcColor();

//t6/code/src_noserver/gfx_d3d/r_extracam.cpp
void CreateExtraCamRenderTargets(eExtraCamResolution resConfig, int location);
void R_ExtraCam_Init(int location);
void R_ExtraCam_Shutdown();
unsigned int R_ExtraCam_RenderTargetWidth(bool usingMultiExtraCam);
unsigned int R_ExtraCam_RenderTargetHeight(bool usingMultiExtraCam);
BOOL R_ExtraCam_GfxResourcesReady();
void RB_ExtraCam_SetSampler(GfxCmdBufSourceState *cmdBufSrcState);

//t6/code/src_noserver/gfx_d3d/r_fog.cpp
void R_SetFogFromServer(;
void R_GetFogSettings(float *fogSettings);
void R_SwitchFog(LocalClientNum_t localClientNum, int fogvar, int startTime, int transitionTime);

//t6/code/src_noserver/gfx_d3d/r_font.cpp
Glyph *R_GetCharacterGlyph(Font_s *font, unsigned int letter);
int R_GetKerningAmount(Font_s *font, int previousLetter, int letter);
unsigned int R_FontGetRandomLetter(Font_s *font, int seed);
unsigned int R_FontGetRandomNumberCharacter(Font_s *font, int seed);
void TRACK_r_font();
Font_s *R_RegisterFont_LoadObj(const char *fontName, int imageTrack);
Font_s *R_RegisterFont_FastFile(const char *fontName);
Font_s *R_RegisterFont();
double R_NormalizedTextScale(Font_s *font, float scale);
void GetButtonProperties(;
int R_TextWidth(LocalClientNum_t localClientNum, const char *text, int maxChars, Font_s *font);
int R_TextHeight(Font_s *font);
const char *R_TextLineWrapPosition(;
int R_ConsoleTextWidth(const char *textPool, int poolSize, int firstChar, int charCount, Font_s *font);

//t6/code/src_noserver/gfx_d3d/r_fonticon.cpp
FontIconEntry *R_GetFontIconEntryByHash(int fontIconNameHash, int size);
FontIconAlias *R_GetFontAliasEntry(char *fontIconAlias);
void R_GetFontIconEntryInfo(;

//#include "gfx_d3d/r_fonticon_load_db.h"

//#include "gfx_d3d/r_font_load_db.h"

//t6/code/src_noserver/gfx_d3d/r_font_load_obj.cpp
Font_s *R_LoadFont(const char *fontName, int imageTrack);

//t6/code/src_noserver/gfx_d3d/r_gpu_timer.cpp
void R_GPU_CalcDerivedTimers(GPUTimerFrame *timerFrame);
void R_GPU_CalcTimers(GPUTimerFrame *timerFrame);
void R_GPU_FreeInterveningTimeStamps(int lastReadIndex, int readIndex);
void R_GPU_EndFrameCallback();
void R_GPU_BeginFrame();
void R_GPU_EndFrame();
// void R_GPU_BeginTimer(int a1@<edi>, int a2@<esi>, GPUTimerId timerId);
;
void R_GPU_DrawTimers();

//t6/code/src_noserver/gfx_d3d/r_image.cpp
void TRACK_r_image();
void Image_TrackTotalMemory(GfxImage *image, int platform, int memory);
void R_AddImageToList(XAssetHeader header, void *data);
void R_GetImageList(ImageList *imageList);
void Image_Release(GfxImage *image);
int Image_GetAvailableHashLocation(const char *name);
void Image_Construct(;
GfxImage *Image_AllocProg(int imageProgType, unsigned __int8 category, unsigned __int8 semantic);
GfxImage *Image_GetProg(int imageProgType);
GfxImage *Image_Alloc(const char *name, const char *category, int semantic, int imageTrack);
void Image_Create2DTexture_PC(;
void Image_Create3DTexture_PC(;
void Image_CreateCubeTexture_PC(;
void Image_SetupRenderTarget(;
void Image_PicmipForSemantic(unsigned __int8 semantic, Picmip *picmip);
bool Image_AssignDefaultTexture(GfxImage *image);
void R_DelayLoadImage(XAssetHeader header);
void Load_Texture(GfxImageLoadDef **remoteLoadDef, GfxImage *image);
GfxImage *Image_FindExisting_LoadObj(const char *name);
GfxImage *Image_FindExisting_FastFile(const char *name);
GfxImage *Image_Register_LoadObj(const char *imageName, unsigned __int8 semantic, int imageTrack);
GfxImage *Image_Register_FastFile(const char *imageName);
GfxImage *Image_Register();
void R_EnumImages(void (*func)(XAssetHeader, void *), void *data);

//t6/code/src_noserver/gfx_d3d/r_image_load_common.cpp
unsigned int Image_GetCardMemoryAmountForMipLevel(;
unsigned int Image_GetCardMemoryAmount(;
int Image_SourceBytesPerSlice_PC(DXGI_FORMAT format, int width, int height);
void Image_Upload2D_CopyDataBlock_PC(;
void Image_Upload2D_CopyData_PC(;
void Image_Upload3D_CopyData_PC(;
void Image_UploadData(;
unsigned int Image_CountMipmaps(;
void Image_GetPicmip(const GfxImage *image, Picmip *picmip);
unsigned int Image_CubemapFace(unsigned int faceIndex);
void Image_TrackTexture(GfxImage *image, int imageFlags, DXGI_FORMAT format, int width, int height, int depth);
void Image_Setup(;
void Image_SetupAndLoad(;

//#include "gfx_d3d/r_image_load_db.h"

//t6/code/src_noserver/gfx_d3d/r_image_load_obj.cpp
unsigned __int8 Image_GetPcStreamedMips(GfxImageFileHeader *fileHeader);
int Image_GetPicmipUsed(const GfxImage *image);
void Image_SetupFromFile(;
unsigned __int8 *Image_AllocTempMemory(int bytes);
void Image_FreeTempMemory(unsigned __int8 *mem, int bytes);
void Image_LoadBitmap(;
void Image_LoadDxtc(;
void Image_LoadFromData(;
char Image_LoadFromFileInternal(const GfxImageFileHeader *a1, unsigned int a2, GfxImage *image);
char Image_LoadFromFile(GfxImage *image);
void Image_Generate2D(GfxImage *image, unsigned __int8 *pixels, int width, int height, DXGI_FORMAT imageFormat);
void Image_GenerateCube(;
void Image_LoadWhite(GfxImage *image);
void Image_LoadBlack(GfxImage *image);
void Image_LoadGray(GfxImage *image);
void Image_LoadLinearGray(GfxImage *image);
void Image_LoadIdentityNormalMap(GfxImage *image);
void Image_LoadWhiteTransparent(GfxImage *image);
void Image_LoadBlackTransparent(GfxImage *image);
GfxImage *Image_LoadBuiltin(const char *name, unsigned __int8 semantic, int imageTrack);
GfxImage *Image_Load(const char *name, int semantic, int imageTrack);

//t6/code/src_noserver/gfx_d3d/r_image_wavelet.cpp
void TRACK_r_image_wavelet();

//t6/code/src_noserver/gfx_d3d/r_init.cpp
void TRACK_r_init();
const char *R_ErrorDescription(int hr);
;
char *R_GetFontPathFromName(const char *fontName);
void R_SetBrightness(float brightness);
void R_SetColorMappings();
void R_GammaCorrect(unsigned __int8 *buffer, int bufSize);
void SetGfxConfig(const GfxConfiguration *config);
void __thiscall R_MakeDedicated(const GfxConfiguration *this);
void R_SetVidRestart();
void R_AllocateMinimalResources();
void R_SetIsMultiplayer(bool isMp);
void R_SetIsZombie(bool isZM);
void R_ShutdownStreams();
void R_Shutdown(int destroyWindow);
void R_UnloadWorld();
void R_BeginRegistration(vidConfig_t *vidConfigOut);
void R_EndRegistration();
void R_TrackStatistics(trStatistics_t *stats);
void __thiscall R_ConfigureRenderer(const GfxConfiguration *this);
bool R_StereoActivated();

//t6/code/src_noserver/gfx_d3d/r_light.cpp
GfxLightDef *R_RegisterLightDef_LoadObj(const char *name);
GfxLightDef *R_RegisterLightDef_FastFile(const char *name);
GfxLightDef *R_RegisterLightDef();
void R_InitFlashlight();
bool R_LightImportanceGreaterEqual(const GfxLight *light0, const GfxLight *light1);
// void R_MostImportantLights(const GfxLight *a1@<edx>, const GfxLight **lights, int lightCount, int keepCount);
// int R_GetPointLightPartitions@<eax>(GfxLight *visibleLights);
void R_ComputeSpotLightCrossDirs(const GfxLight *light, vec3_t *crossDirs);
void R_CalcSpotLightPlanes(;
void R_GetSceneEntLightSurfs(const GfxLight *visibleLights, int visibleCount);
void R_SortSceneEntLightSurfs(const GfxLight *visibleLights, int visibleCount);
BOOL R_AllowBspSpotLightShadows(int surfIndex);
BOOL R_SortBspLightSurfaces(GfxSurface *surface0, GfxSurface *surface1);
BOOL R_AllowStaticModelSpotLight(int smodelIndex);
void R_GetStaticModelLightSurfs(int viewIndex, const GfxLight *visibleLights, int visibleCount);
void R_SortStaticModelLightSurfs(const GfxLight *visibleLights, int visibleCount);
void R_GetBspLightSurfs(const GfxLight *visibleLights, int visibleCount);

//#include "gfx_d3d/r_light_load_db.h"

//t6/code/src_noserver/gfx_d3d/r_light_load_obj.cpp
const unsigned __int8 *R_LoadLightImage(const unsigned __int8 *readPos, GfxLightImage *lightImage);
GfxLightDef *R_LoadLightDef(const char *name);

//t6/code/src_noserver/gfx_d3d/r_marks.cpp
int R_ChopPolyBehindPlane(;
int R_ChopWorldPolyBehindPlane(;
bool R_Mark_MaterialAllowsMarks(;
BOOL R_AllowMarks();
void R_AABBTreeBoxSurfaces_r(;
void R_AABBTreeBoxSurfacesTwoLists_r(;
void R_AddStaticModelToList(int smodelIndex, unsigned __int16 *smodelList, int *smodelCount);
void R_AABBTreeBoxStaticModels_r(;
void R_AABBTreeFrustumSurfaces_r(;
void R_AABBTreeFrustumStaticModels_r(;
void R_CellBoxSurfaces(;
void R_CellBoxSurfacesTwoLists(;
void R_BoxSurfaces_r(;
void R_BoxStaticModels_r(;
void R_FrustumSurfaces_r(;
void R_FrustumStaticModels_r(;
void R_BoxSurfaces(;
// int R_BoxStaticModels@<eax>(;
// int R_FrustumSurfaces@<eax>(;
// int R_FrustumStaticModels@<eax>(;
void R_GetMarkFragmentClipPlanes(;
bool R_MarkFragments_BrushSurface(;
bool R_MarkFragments_WorldBrushes(MarkInfo *markInfo);
void R_Mark_TransformClipPlanes(;
char R_MarkFragments_EntBrushes(MarkInfo *markInfo);
bool R_MarkFragments_Glass(MarkInfo *markInfo);
void R_MarkUtil_GetDObjAnimMatAndHideParts(;
void R_MarkFragments_Begin(;
bool R_MarkFragments_AddDObj(MarkInfo *markInfo, DObj *dObj, cpose_t *pose, unsigned __int16 entityIndex);
char R_MarkFragments_AddViewModelDObj(MarkInfo *markInfo, DObj *dObj, cpose_t *pose);
bool R_MarkFragments_AddBModel(;
// char R_MarkFragments_XModelSurface_Basic@<al>(;
bool R_MarkFragments_EntirelyRigidXModel(;
;
bool R_MarkFragments_AnimatedXModel(;
bool R_MarkFragments_SceneDObjs(MarkInfo *markInfo);
bool R_MarkFragments_ViewmodelDObjs(MarkInfo *markInfo);
bool R_MarkFragments_StaticModels(MarkInfo *markInfo);
bool R_MarkFragments_Models(MarkInfo *markInfo);
void R_MarkFragments_Go(;

//t6/code/src_noserver/gfx_d3d/r_material.cpp
void TRACK_r_material();
unsigned __int8 *Material_Alloc(int size);
void Load_CreateStateBits(const unsigned int (*pLoadBits)[2], GfxStateBits *stateBits);
void Load_CreateMaterialPixelShader(int a1, GfxPixelShaderLoadDef *loadDef, MaterialPixelShader *mtlShader);
void Load_CreateMaterialVertexShader(GfxVertexShaderLoadDef *loadDef, MaterialVertexShader *mtlShader);
void AssertValidVertexDeclOffsets(const stream_source_info_t *streamTable);
void Load_BuildVertexDecl(MaterialVertexDeclaration **mtlVertDecl, MaterialPass *pass);
bool MaterialTechniqueSet_FindHashLocation(const char *name, int *foundHashIndex);
// MaterialTechniqueSet *Material_FindTechniqueSet_LoadObj@<eax>(;
MaterialTechniqueSet *Material_FindTechniqueSet_FastFile(;
void Material_SetTechniqueSet(const char *name, MaterialTechniqueSet *techniqueSet);
void Material_SetAlwaysUseDefaultMaterial(const bool alwaysUseDefaultMaterial);
MaterialTechniqueSet *Material_RegisterTechniqueSet(;
void Material_ReleaseMaterialResources(Material *mtl);
void Material_WarmTechniqueSetShaders(XAssetHeader header);
void Material_WarmAllShaders();
void Material_DirtySort();
void Material_Add(Material *material, unsigned __int16 hashIndex);
bool Material_IsDefault(const Material *material);
void Material_GetHashIndex(const char *name, unsigned __int16 *hashIndex, bool *exists);
Material *Material_Register_FastFile(const char *name, int imageTrack, bool errorIfMissing, int waitTime);
void R_MaterialParameterTweakUpdate();
void R_EnumTechniqueSets(void (*func)(XAssetHeader, void *), void *data);
void R_EnumMaterials(void (*func)(XAssetHeader, void *), void *data);
const char *Material_GetName(Material *handle);
int Material_LoadFile(const char *filename, int *file);
BOOL IsValidMaterialHandle(Material *const handle);
int GetCodeConst_GenericParam0();
int GetCodeConst_GenericParam1();
int GetCodeConst_GenericParam2();
int GetCodeConst_GenericParam3();
int GetCodeConst_GenericParamA();
int GetCodeConst_GenericParamB();
int GetCodeConst_GameTimeParam();
void Material_ReleaseTechniqueSetResources(MaterialTechniqueSet *techniqueSet);
Material *Material_Duplicate(Material *mtlCopy, const char *name);
Material *Material_MakeDefault(const char *name);
Material *Material_Register_LoadObj(const char *name, int imageTrack);
Material *Material_Register();
Material *Material_RegisterHandle(const char *name, int imageTrack, bool errorIfMissing, int waitTime);
void Material_LoadPerMap(const PerMapMaterialTable *mtlTable, int mtlTableCount);
void R_InitAssets_PostMapFastfileLoad(int a1, int a2);

//#include "gfx_d3d/r_material.h"

//t6/code/src_noserver/gfx_d3d/r_material_consts.cpp
void R_RegisterShaderConst(;
void R_GetPixelLiteralConsts(;
int R_ComparePixelConsts(const Material **material, const MaterialPass **pass);

//#include "gfx_d3d/r_material_load_db.h"

//t6/code/src_noserver/gfx_d3d/r_material_load_obj.cpp
int Material_GetTypeByPrefix(const char *name);
int Material_GetTypeByTechsetPrefix(const char *name);
const char *Material_GetPrefix(unsigned int materialType);
int R_DrawSurfStandardPrepassSortKey(const Material *material);
unsigned int Material_HashVertexDecl(const MaterialStreamRouting *routingData, int streamCount);
MaterialVertexDeclaration *Material_AllocVertexDecl(;
const float *Material_RegisterLiteral(const vec4_t *literal);
const char *Material_StringFromHash(unsigned int hash);
const char *Material_RegisterString(const char *string);
char Material_HashStateMap(const char *name, unsigned int *foundHashIndex);
bool MaterialTechnique_FindHashLocation(const char *name, unsigned int *foundHashIndex);
void Material_SetTechnique(const char *name, MaterialTechnique *technique);
const MtlStateMapBitName *Material_ParseValueForState(const char **text, const MtlStateMapBitName *bitNames);
MtlParseSuccess Material_ParseRuleSetConditionTest(;
MtlParseSuccess Material_ParseRuleSetCondition(;
bool Material_ParseRuleSetValue(;
MaterialStateMapRuleSet *Material_AssembleRuleSet(int ruleCount, const MaterialStateMapRule *rules);
bool Material_ParseRuleSet(;
bool Material_ParseStateMap(const char **text, MaterialStateMap *stateMap);
MaterialStateMap *Material_LoadStateMap(const char *name);
MaterialStateMap *Material_RegisterStateMap(const char *name);
bool Material_LoadPassStateMap(const char **text, MaterialStateMap **stateMap);
bool Material_ParseIndex(const char **text, int indexCount, int *index);
const char *Material_NameForStreamDest(unsigned __int8 dest);
bool Material_StreamDestForName(const char **text, const char *destName, unsigned __int8 *dest);
bool Material_StreamSourceForName(const char **text, const char *sourceName, unsigned __int8 *source);
bool Material_ResourceDestForStreamDest(;
bool Material_LoadPassVertexDecl(;
bool Material_ParseIndexRange(const char **text, unsigned int arrayCount, ShaderIndexRange *indexRange);
bool Material_ParseArrayOffset(const char **text, int arrayCount, int arrayStride, int *offset);
bool Material_CodeSamplerSource_r(;
bool Material_ParseSamplerSource(const char **text, ShaderArgumentSource *argSource);
bool Material_DefaultSamplerSourceFromTable(;
bool Material_ParseVector(const char **text, int elemCount, vec4_t *vector);
bool Material_ParseLiteral(const char **text, const char *token, vec4_t *literal);
bool Material_ParseCodeConstantSource_r(;
bool Material_ParseConstantSource(;
char Material_DefaultConstantSourceFromTable(;
bool Material_UnknownShaderworksConstantSource(;
unsigned int Material_ElemCountForParamName(;
bool Material_ParseArgumentSource(;
bool Material_DefaultArgumentSource(;
unsigned int R_SetParameterDefArray(;
unsigned int Material_PrepareToParseShaderArguments(;
int Material_CompareShaderArgumentsForCombining(const void *e0, const void *e1);
unsigned int Material_CombineShaderArguments(unsigned int usedCount, MaterialShaderArgument *localArgs);
bool Material_SetShaderArguments(;
ShaderUniformDef *Material_GetShaderArgumentDest(;
MaterialUpdateFrequency Material_GetArgUpdateFrequency(const MaterialShaderArgument *arg);
bool MaterialAddShaderArgument(;
bool Material_AddShaderArgumentFromLiteral(;
bool Material_AddShaderArgumentFromCodeConst(;
bool Material_AddShaderArgumentFromMaterial(;
// bool Material_AddShaderArgument@<al>(;
bool Material_ParseShaderArguments(;
MaterialVertexShader *Material_LoadVertexShader(const char *shaderName, ShaderStats *stats);
MaterialPixelShader *Material_LoadPixelShader(const char *shaderName, int shaderVersion, ShaderStats *stats);
bool Material_GetVertexShaderHashIndex(const char *shaderName, unsigned int *foundHashIndex);
// MaterialVertexShader *Material_RegisterVertexShader@<eax>(;
bool Material_GetPixelShaderHashIndex(const char *shaderName, unsigned int *foundHashIndex);
// MaterialPixelShader *Material_RegisterPixelShader@<eax>(;
unsigned __int8 Material_GetStreamDestForSemantic(const _D3D11_SIGNATURE_PARAMETER_DESC *semantic);
bool Material_SetPassShaderArguments_DX(;
bool Material_LoadPassVertexShader(;
bool Material_LoadDeclTypes(const char **text, MaterialPass *pass);
bool Material_LoadPassPixelShader(;
bool Material_ValidateShaderLinkage(;
int Material_CompareShaderArgumentsForRuntime(const void *e0, const void *e1);
unsigned __int8 Material_CountArgsWithUpdateFrequency(;
bool Material_LoadPass(;
MaterialTechnique *Material_LoadTechnique(const char *name, int materialType);
MaterialTechnique *Material_RegisterTechnique(const char *name, int materialType);
bool Material_IgnoreTechnique(const char *name);
unsigned __int8 Material_TechniqueTypeForName(const char *name, bool *inUse);
bool Material_HasAlphaTest(const Material *mtl);
void Material_GetTechniqueSetDrawRegion;
void Material_SetMaterialDrawRegion(Material *material);
MaterialTechniqueSet *Material_LoadTechniqueSet(const char *fullName);
void Material_RemapStateBits(;
unsigned __int8 Material_AddStateBitsArrayToTable(;
unsigned int Material_GetCullFlags(Material *material);
unsigned int Material_GetCullShadowFlags(Material *material);
unsigned int Material_GetDecalFlags(const Material *mtl);
unsigned int Material_GetWritesDepthFlags(const Material *mtl);
unsigned int Material_GetUsesDepthBufferFlags(const Material *mtl);
unsigned int Material_GetUsesStencilBufferFlags(const Material *mtl);
void Material_UpdateTechniqueFlags(Material *material);
void Material_SetStateBits(;
void Material_BuildStateBitsTable(;
char Material_ValidatePassArguments(;
char Material_Validate(const Material *material);
int CompareRawMaterialTextures(const void *e0, const void *e1);
int CompareHashedMaterialTextures(const void *e0, const void *e1);
bool Material_FinishLoadingInstance(;
void Material_GetLayeredStateBits(;
unsigned int Material_CreateLayeredStateBitsTable(;
;
bool Material_HasNormalMap(const Material *mtl);
unsigned int Material_AppendTechniqueSetName(;
const LayeredTechniqueSetName *Material_GetLayeredTechniqueSetName(const char *techSetName);
void Material_SetGameFlags;
Material *Material_LoadRaw(;
void Material_GetInfo(Material *handle, MaterialInfo *matInfo);
void Material_GetVertexShaderName(char *dest, const MaterialPass *pass, int destsize);
int Material_ComparePixelConsts(const Material *mtl0, const Material *mtl1, unsigned __int8 techType);
int Material_CompareBySortKeyAndTechnique(;
bool Material_Compare(const Material *mtl0, const Material *mtl1);
void R_BuildScritableConstantArray(ScriptableConstant *array, int arraySize);
// char R_FindScriptableConstantSource_ByHash@<al>(;
char R_FindScriptableConstantSource_ByName(const char *name, unsigned __int8 *dest);
// const char *R_FindScriptableConstantName_BySource@<eax>(;
MaterialTechniqueSet *Material_RegisterLayeredTechniqueSet(const Material **mtl, unsigned int layerCount);
Material *Material_LoadLayered(const char *assetName);
// Material *Material_Load@<eax>(LocalClientNum_t a1@<ebx>, const char *fullAssetName, int imageTrack);
void Material_SortInternal(Material **sortedMaterials, unsigned int materialCount);
void Material_Sort();

//t6/code/src_noserver/gfx_d3d/r_material_pass_load_obj.cpp
int R_IsMaterialPassMatch(MaterialPass *pass, VertexConstantMappingEntry *entry);
int R_IsMaterialPassConflict(;
// void R_MaterialPrecompilePass(VertexConstantMappingEntry *a1@<edx>, MaterialPass *pass);

//t6/code/src_noserver/gfx_d3d/r_mem_track.cpp
void R_Track_Init();

//t6/code/src_noserver/gfx_d3d/r_meshdata.cpp
void R_BeginMeshVerts(GfxMeshData *mesh);
char R_ReserveMeshIndices(GfxMeshData *mesh, int indexCount, r_double_index_t **indicesOut);
char R_ReserveMeshVerts(GfxMeshData *mesh, int vertCount, unsigned __int16 *baseVertex);
unsigned __int8 *R_GetMeshVerts(GfxMeshData *mesh, unsigned __int16 baseVertex);
void R_ResetMesh(GfxMeshData *mesh);
void R_SetQuadMeshData(;
void R_SetQuadMesh(;

//t6/code/src_noserver/gfx_d3d/r_model.cpp
void TRACK_r_model();
unsigned __int8 *Hunk_AllocXModelPrecache(int size);
unsigned __int8 *Hunk_AllocXModelPrecacheColl(int size);
XModel *R_RegisterModel();
void R_XModelDebugBoxes(const DObj *obj, int *partBits);
void R_XModelDebugAxes(const DObj *obj, int *partBits);
void R_XModelDebug(const DObj *obj, int *partBits);
int R_SkinXModel(;
int R_SkinAndBoundSceneEnt(GfxSceneEntity *sceneEnt);
void XSurfaceReleaseResources(XSurface *surf);
void XSurfaceRenderString(const vec3_t *pos, const char *string);

//t6/code/src_noserver/gfx_d3d/r_model_lighting.cpp
unsigned int R_ModelLightingIndexFromHandle(unsigned __int16 handle);
void R_SetModelLightingConsts(;
void R_SetStaticModelLightingConsts(;
// unsigned int R_AllocModelLightingPixel@<eax>(;
void R_ToggleModelLightingFrame();
void R_SetStaticModelLightingForSource(;
void R_BeginAllStaticModelLighting();
void R_SetupDynamicModelLighting(GfxCmdBufInput *input);
void R_InitModelLightingGlobals();
void R_ResetModelLighting();
void R_InitStaticModelLighting();
void R_SetModelLightingForSource(unsigned __int16 handle, GfxCmdBufSourceState *source);
char R_AllocStaticModelLighting(const GfxStaticModelDrawInst *smodelDrawInst, unsigned int smodelIndex);
void R_CalcModelLighting(;
void R_SetStaticModelLighting(unsigned int smodelIndex);
void R_SetAllStaticModelLighting();
// unsigned int R_AllocModelLighting@<eax>(;

//#include "gfx_d3d/r_model_lighting.h"

//t6/code/src_noserver/gfx_d3d/r_model_lod.cpp
double R_GetBaseLodDist(const vec3_t *origin);
double R_GetAdjustedLodDistExtracam(;
double R_GetAdjustedLodDist(float dist, XModelLodRampType lodRampType);

//t6/code/src_noserver/gfx_d3d/r_model_pose.cpp
DObjAnimMat *R_DObjCalcPose(const GfxSceneEntity *sceneEnt, const DObj *obj, int *partBits);
void R_SetNoDraw(GfxSceneEntity *sceneEnt, GfxSceneEntity *localSceneEnt);
;
void R_UpdateGfxEntityBoundsCmd(void *data);
// int R_SkinSceneModel@<eax>(;
void R_ModelSkelCmd(void *data);

//t6/code/src_noserver/gfx_d3d/r_model_skin.cpp
void R_Tension(;
DWORD EndBench();
void BenchSurf(const XSurface *surf, const DObjSkelMat *mat);
void R_SkinXSurfaceRigid(const XSurface *surf);
void R_SkinXSurfaceWeight(const GfxPackedVertex *inVerts, const XSurfaceVertexInfo *vertexInfo);
void R_SkinXModelCmd(void *data);

//t6/code/src_noserver/gfx_d3d/r_outdoor.cpp
void Outdoor_ApplyBoundingBox(const vec3_t *outdoorMin, const vec3_t *outdoorMax);
unsigned int Outdoor_UpdateTransforms();
// void R_RegisterOutdoorImage(const vec3_t *a1@<edx>, GfxWorld *world, const vec3_t *outdoorMin);
;
void R_GenerateOutdoorImage(GfxImage *outdoorImage);

//t6/code/src_noserver/gfx_d3d/r_perf_timer.cpp
void R_Perf_GetTimerAverageAndMaxMs(;
void R_Perf_GetFrameAverageAndMaxMs(;
void R_Perf_ResetDraw();
void R_Perf_DrawTimers(PerfTimerFrameHistory *timerFrameHistory, PerfTimerStyle *timerStyle);

//#include "gfx_d3d/r_pix_profile.h"

//t6/code/src_noserver/gfx_d3d/r_pointlights.cpp
void GenerateLightGridBasisDirs();
void GatherIncidentEnergyInSpaceForLightFromDir(;
void AddLightGridLightingForDir(vec3_t *lightingForDir, GfxDecodedLightGridColors *colors);
bool EvaluateHeroLightForGrid(;
void R_AdjustLightColorSamples(GfxDecodedLightGridColors *colors);
void R_AddHeroOnlyLightsToGridColors(GfxDecodedLightGridColors *packed, const vec3_t *heroPos);

//t6/code/src_noserver/gfx_d3d/r_pretess.cpp
void R_InitDrawSurfListInfo(GfxDrawSurfListInfo *info);
void R_EmitDrawSurfList(;
unsigned int R_GetKeyCount(;
void R_MergeAndEmitDrawSurfLists(;

//t6/code/src_noserver/gfx_d3d/r_primarylights.cpp
unsigned int R_AddPotentiallyShadowedLight(;
void R_AddShadowedLightToShadowHistory(;
void R_FadeOutShadowHistoryEntries(GfxShadowedLightHistory *shadowHistory, float fadeDelta);
void R_ClearShadowedPrimaryLightHistory(LocalClientNum_t localClientNum);
unsigned int R_AddDynamicShadowableLight(GfxViewInfo *viewInfo, const GfxLight *visibleLight);
BOOL R_IsDynamicShadowedLight(unsigned int shadowableLightIndex);
BOOL R_IsPrimaryLight(unsigned int shadowableLightIndex);
void R_ChooseShadowedLights(unsigned __int8 *shadowableLightIsUsed, GfxViewInfo *viewInfo);
unsigned int R_GetPrimaryLightEntityShadowBit(;
unsigned int R_GetPrimaryLightDynEntShadowBit(unsigned int entnum, unsigned int primaryLightIndex);
void R_LinkSphereEntityToPrimaryLights(;
void R_LinkBoxEntityToPrimaryLights(;
void R_LinkDynEntToPrimaryLights(;
void R_UnlinkEntityFromPrimaryLights(;
void R_UnlinkDynEntFromPrimaryLights(;
// BOOL R_IsEntityVisibleToPrimaryLight@<eax>(unsigned int a1@<edx>, LocalClientNum_t localClientNum);
// BOOL R_IsDynEntVisibleToPrimaryLight@<eax>(;
int R_IsEntityVisibleToAnyShadowedLight(const GfxViewInfo *viewInfo, unsigned int entityNum);
BOOL R_IsDynEntVisibleToAnyShadowedLight(;
void R_ShowPrimaryLightDebugLine(;
void R_ShowPrimaryLightBsp(const GfxSurface *surface, unsigned int primaryLightIndex);

//#include "gfx_d3d/r_primarylights_cull.h"

//t6/code/src_noserver/gfx_d3d/r_qrcode.cpp
void RB_QRCode_SetShaderConstants(GfxCmdBufSourceState *source, const GfxQRCodeBackend *rbQRCode);
void R_QRCode_SetupBackendData(GfxQRCodeBackend *qrcodeBackend);

//t6/code/src_noserver/gfx_d3d/r_reflection_probe.cpp
void R_GetReflectionProbePosition(unsigned int index, vec3_t *pos);
void R_SetBlackProbe(unsigned __int8 *to, unsigned int size);
GfxImage *R_GenerateReflectionImageFromRawData(;
void R_GenerateDummyReflectionImages(;
void R_GenerateReflectionImages(;

//#include "gfx_d3d/r_reflection_probe_load_db.h"

//t6/code/src_noserver/gfx_d3d/r_rendercmds.cpp
void TRACK_r_rendercmds();
void R_InitGlassRenderBuffers(int numIndices, int numVerts, int vertexSize);
void R_InitTempSkinBuf(unsigned int maxVerts);
void R_ShutdownTempSkinBuf();
unsigned int R_UpdateSkinCacheUsage();
GfxCmdHeader *R_GetCommandBuffer(GfxRenderCommand renderCmd, int bytes);
void R_BeginClientCmdList2D();
void R_ClearClientCmdList2D();
void R_BeginSharedCmdList();
void R_BeginCompositingCmdList();
void R_AddCmdEndOfList();
int R_ToggleSmpFrame();
unsigned int R_GetFrameCount();
GfxViewParms *R_AllocViewParms();
void R_AddCmdDrawStretchPicWInternal(;
void R_AddCmdDrawStretchPicInternal(;
void R_AddCmdDrawStretchPicRotateXYInternal(;
void R_AddCmdDrawStretchPicRotateSTInternal(;
GfxCmdDrawText2D *AddBaseDrawTextCmd(;
void R_AddCmdDrawTextWithCursorInternal(;
void R_AddCmdDrawTextInternal(;
void R_AddCmdDrawTextWInternal(;
void R_AddCmdDrawTextSubtitleInternal(;
void R_AddCmdDrawTextWithEffectsInternal(;
void R_AddCmdDrawTextWithCOD7DecodeEffectsInternal(;
void R_AddCmdDrawTextWithCOD7TypeWriterEffectsInternal(;
void R_AddCmdDrawTextWithRedactEffectsInternal(;
void R_AddCmdDrawTextWithPopInEffectsInternal(;
void CopyPoolTextToCmd(;
GfxCmdDrawText2D *AddBaseDrawConsoleTextCmd(;
void R_AddCmdDrawConsoleTextInternal(;
void R_AddCmdDrawConsoleTextTypewriterFXInternal(;
void R_AddCmdDrawConsoleTextSubtitleInternal(;
void R_AddCmdDrawConsoleTextPulseFXInternal(;
void R_AddCmdDrawQuadPicWInternal(const vec2_t *verts, float w, const vec4_t *color, Material *material);
void R_AddCmdDrawQuadPicInternal(const vec2_t *verts, const vec4_t *color, Material *material);
void R_AddCmdSetCustomConstantInternal(unsigned int type, const vec4_t *vec);
void R_AddCmdSetViewportValuesInternal(int x, int y, int width, int height);
void R_AddCmdSetScissorValuesInternal(bool enabled, int x, int y, int width, int height);
void R_AddCmdPCCopyImageGenMIPInternal(void (*callback)(void *), GfxImage *image, void *job);
bool R_LightTweaksModified();
void R_SetTestLods();
int R_SetOutdoorFeatherConst();
void R_EndFrame();
void R_AddCmdClearScreenInternal(int whichToClear, const vec4_t *color, float depth, unsigned __int8 stencil);
GfxCmdHeader *R_AddCmdDrawQuadList2DInternal(Material *materialHandle, int quadCount);
void R_AddCmdProjectionSet2DInternal();
void R_AddCmdDrawFramedInternal(;
void R_AddCmdSetShaderConstantSetInternal(const ShaderConstantSet *scs_src);
void R_EnableRemoteScreenUpdateInGame(bool en);
void R_BeginRemoteScreenUpdate();
void R_EndRemoteScreenUpdate();
void R_PushRemoteScreenUpdate(int remoteScreenUpdateNesting);
int R_PopRemoteScreenUpdate();
BOOL R_IsInRemoteScreenUpdate();
void R_InitRenderCommands();
void R_FreeGlassRenderBuffers();
void R_SyncRenderThread();
void R_ToggleSmpFrameCmd();
void R_IssueRenderCommands(unsigned int type);
bool R_UpdateFrontEndDvarOptions();
void R_BeginFrame();

//t6/code/src_noserver/gfx_d3d/r_rendertarget.cpp
void AssertUninitializedRenderTarget(const GfxRenderTarget *renderTarget);
void R_AssignImageToRenderTargetDepthStencil(;
void R_AssignImageToRenderTargetColor(GfxRenderTarget *renderTarget, GfxImage *image, DXGI_FORMAT format);
void R_InitRenderTargetImage(;
void R_InitSizedRenderTargetImage(;
void R_InitShadowmapRenderTarget(;
const char *R_RenderTargetName(unsigned __int8 renderTargetId);
void R_InitExtraCamRenderTargets(;
void R_ShutdownExtraCamRenderTargets();
void R_InitUI3DRenderTarget(int width, int height, int location, bool allocatePingPongBuffer);
void R_ShutdownUI3DRenderTarget(bool freePingPongBuffer);
void R_ResizeSunShadowmapRenderTarget_PC();
void R_ResizeSpotShadowmapRenderTarget_PC();

//t6/code/src_noserver/gfx_d3d/r_rope_render.cpp
void SetupVertex(;
;
void R_Rope_GenerateVerts_Camera(RopeGenerateVertsCmd *cmd);
void R_Rope_ClearAll();
void R_Rope_Add(const VisualRope *vropeIn);
unsigned __int8 R_Rope_CalcVisibility(const vec3_t *mins, const vec3_t *maxs, LocalClientNum_t localClientNum);
const Material *R_Rope_GetMaterialFromGfxWorld();
RopeRenderInfo *R_Rope_GetInfo();

//t6/code/src_noserver/gfx_d3d/r_scene.cpp
GfxScene *R_GetScene();
unsigned int R_AllocSceneDObj();
unsigned int R_AllocSceneModel();
char R_AllocTextureOverride(;
char R_AllocTextureOverride(;
char R_AllocTextureOverride(;
char R_AllocTextureOverride(;
char R_AllocTextureOverride(;
unsigned int R_AllocSceneBrush();
void R_TryToValidateBrushModel(unsigned int modelIndex);
GfxBrushModel *R_GetBrushModel(unsigned int modelIndex);
void R_AddBrushModelToSceneFromAngles(;
void R_AddGlassBrushToScene(;
void R_AddDObjToScene(;
int R_AllocParticleCloud();
GfxParticleCloud *R_GetGfxParticleCloud(unsigned int index);
void R_PrepareXModelRigidCullInfo(XModelRigidCullInfoContext *cullInfoContext);
void R_CloneAndSetupXModelDrawSurf(;
void R_AddOmniLightToScene(;
void R_AddSpotLightToScene(;
void R_AddFlashLightToScene(;
void R_UpdateFrameFog(refdef_t *refdef);
void R_SetupViewProjectionMatrices(GfxViewParms *viewParms);
void R_SetAllowShadowMaps(const bool allowShadowMaps);
void R_AddBModelSurfacesCamera(;
GfxDrawSurf *R_AddBModelSurfaces(;
const XSurface *R_GetXSurface(const void *modelSurf, surfaceType_t surfType);
void R_SetEnablePlayerShadowFlag(bool flag);
Material *R_MaterialOverride(unsigned int modelIndex, int textureOverrideIdx, Material *drawMaterial);
void R_AddXModelSurfacesCamera(;
GfxDrawSurf *R_AddXModelSurfaces(;
GfxDrawSurf *R_AddDObjSurfaces(;
void R_SetSceneComposition(;
void R_CheckShadowMapVolumes(const vec3_t *position);
char R_CheckShadowMapVolume(const vec3_t *position, unsigned int volumeIdx);
int R_CheckWorldFogModifierVolumes(vec3_t *position, unsigned int bankMask);
void R_UpdateWorldFrameFog(refdef_t *refdef);
int R_CheckExposureVolumes(vec3_t *position, float *feather);
void R_UpdateExposureValue;
void R_SetExposure;
// void R_InitModifierVolumes(float *a1@<edx>, vec3_t *a2@<ecx>, refdef_t *refdef);
void R_SetDepthOfField(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms);
void R_SetDoubleVision(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms);
void R_SetWaterSheetingFx(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms);
void R_SetFlameFx(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms);
void R_SetElectrifiedFx(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms);
void R_SetTransportedFx(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms);
void R_SetReviveFx(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms);
void R_SetRimIntensity(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms);
void R_SetGenericSceneVectors(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms);
void R_SetPoisonFx(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms);
__int16 R_TestLutVolumes(vec3_t *position, unsigned __int16 bankMask);
void R_SetFilmInfo(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms, refdef_t *refdef);
void R_SetBloomInfo(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms);
void R_SetCharacterPrimaryLightScaleInfo(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms);
void R_SetFullSceneViewMesh(int viewInfoIndex, GfxViewInfo *viewInfo);
void R_AddDrawLitCall(;
void R_AddDrawLitBspCall(;
void R_AddDrawLitStaticModelCall(;
void R_AddEmissiveSpotLight(GfxViewInfo *viewInfo, GfxLight *visibleLights, int visibleLightCount);
void R_SetSunShadowConstants(GfxCmdBufInput *input, const GfxSunShadowProjection *sunProj);
void R_SetSkyConstants(GfxCmdBufInput *input, const GfxViewInfo *viewInfo);
void R_SetSunConstants(GfxCmdBufInput *input, float sunVisibility);
void R_SetHeroLighting(GfxCmdBufInput *input, GfxViewInfo *viewInfo);
void R_SetSkyColorMatrix(GfxCmdBufInput *input);
void R_SetHDRControlConstants(;
;
void R_SplitDrawSurfacesPrimarySortKeyScanRev(;
void DrawLightDebug(;
void DrawSunDirectionDebug(const vec3_t *viewOrg, const vec3_t *viewForward);
void R_DrawFogParams(const refdef_t *refdef);
// void R_SetSkyDynamicIntensity(float a1@<edi>, const vec3_t *viewForward, GfxCmdBufInput *input);
int R_WaitForFXUpdateWorkerCmds();
int R_WaitForFXNonSpriteWorkerCmds();
void R_SetupDrawSurfListInfos(;
void R_SplitAndMergeDrawLists(;
void R_MergeAndEmitDrawSurfListsIntoList(;
void R_FinishDecalAndEmissiveDrawSurfs(;
void R_DrawRecordFrame();
void R_AddDrawRecord(GfxViewInfo *viewInfo, GfxBackEndData *data, unsigned int viewInfoIndex);
unsigned int R_GetDrawRecordFrame();
void R_InvalidateShadowableLightCache();
int R_UpdateCachedLightUsage();
void R_InitCachedVisibleLights();
void R_GetCachedVisibleLights(GfxViewInfo *viewInfo);
void R_SetupVisibility(GfxViewInfo *viewInfo, const GfxViewParms *viewParmsDpvs, bool recalculateShadows);
void R_SetupNeedResolve(GfxViewInfo *viewInfo);
GfxViewInfo *R_AllocViewInfo();
void R_SetupSunShadowGlobals();
void R_GenerateSortedDrawSurfs(;
void R_AddDrawCalls();
void R_ClearScene(LocalClientNum_t localClientNum, bool forStereoRightEyeView, bool forExtraCam);
LocalClientNum_t R_GetLocalClientNum();
void R_SetViewParmsForScene(const refdef_t *refdef, GfxViewParms *viewParms);
void R_SetSceneParms(const refdef_t *refdef, GfxSceneParms *sceneParms);
void R_ExtraCam_SetSceneParms(const refdef_t *refdef, GfxSceneParms *sceneParms);
void R_LerpDir(;
int R_UpdateFrameSun();
double R_LodScaleForSkinCacheOverflow(unsigned int viewIndex, float currentScale);
void R_UpdateLodParms(const refdef_t *refdef, GfxLodParms *lodParms);
void R_SetLodOrigin(const refdef_t *refdef);
GfxViewParms *R_SetupRenderSceneViewParms(const refdef_t *refdef);
void R_RenderScene(;
void R_LinkDObjEntity(LocalClientNum_t localClientNum, unsigned int entnum, vec3_t *origin, float radius);
void R_LinkBModelEntity(LocalClientNum_t localClientNum, unsigned int entnum, GfxBrushModel *bmodel);
void R_UnlinkEntity(LocalClientNum_t localClientNum, unsigned int entnum);
void R_LinkDynEnt(unsigned int dynEntId, DynEntityDrawType drawType, vec3_t *mins, vec3_t *maxs);
void R_UnlinkDynEnt(unsigned int dynEntId, DynEntityDrawType drawType);
void R_PvsLock_GetViewOrigin(vec3_t *out);
void R_PvsLock_GetViewAxis(vec3_t *out);
GfxViewParms *R_PvsLock_GetViewParms();
void ShowLodInfo(;
void R_PerMap_Init();
void R_AddDObjSurfacesCamera(;
void R_SetupVisibilityEarly(;
int r_add_draw_callsCallback(jqBatch *batch);
void R_RenderExtraCam(;

//t6/code/src_noserver/gfx_d3d/r_screenshot.cpp
void TRACK_r_screenshot();
void R_CubemapShotFlipVerticalBuffer(unsigned __int8 *buffer);
void R_CubemapShotWriteTargaHeader(const int res, unsigned __int8 *fileBuffer);
void R_CubemapShotCopyBufferToTarga(const unsigned __int8 *srcBuffer, unsigned __int8 *targa);
void R_CubemapShotApplyFresnelToTarga(;
void R_CubemapShotWriteTargaFile(;
void R_BeginCubemapShot(const int pixelWidthHeight, const int pixelBorder);
void R_SaveCubemapShot(const char *filename, const CubemapShot shotIndex, const float n0, const float n1);
void R_CubemapLightingForDir(;
void R_CubemapLighting(;
void R_CubemapShotExtractLinearLight(unsigned __int8 **pixels, int width, int height, vec3_t **linearColors);
void R_LightingFromCubemapShots(const vec3_t *baseColor);
// char R_GetBackBufferData@<al>(;
void R_CubemapShotCopySurfaceToBuffer(unsigned __int8 *buffer, const int bufferSizeInBytes);
void R_CopyCubemapShot(CubemapShot shotIndex);
void __thiscall R_EndCubemapShot(void *this);

//#include "gfx_d3d/r_setstate_d3d.h"

//t6/code/src_noserver/gfx_d3d/r_shade.cpp
void R_SetVertexShaderConstantFromLiteral(;
void R_SetPixelShaderConstantFromLiteral(;
const float *R_GetCodeConstant(const GfxCmdBufContext *context, unsigned int constant);
void R_SetVertexShaderConstantFromCode(;
int R_IsPixelShaderConstantUpToDate(;
void R_SetPixelShaderConstantFromCode(;
void R_SetPassShaderPrimArguments(;
void R_SetPassShaderObjectArguments(;
void R_SetupPassPerPrimArgs(GfxCmdBufContext context);
void R_SetupPassPerObjectArgs(GfxCmdBufContext context);
void R_SetPassPixelShaderStableArguments(;
void R_SetPassVertexShaderStableArguments(;
void R_SetupPassCriticalPixelShaderArgs(GfxCmdBufContext context);
void R_SetupPassVertexShaderArgs(GfxCmdBufContext context);
const MaterialTextureDef *R_SetPixelSamplerFromMaterial(;
void R_SetPassShaderStableArguments(;
int R_SetIndexDataIndexCount(GfxCmdBufState *state, const unsigned __int16 *indices, int indexCount);
void R_SetPixelShader(GfxCmdBufState *state, const MaterialPixelShader *pixelShader);
void R_SetVertexShader(GfxCmdBufState *state, const MaterialVertexShader *vertexShader);
void R_UpdateVertexDecl(GfxCmdBufState *state);
void R_SetupPass(GfxCmdBufContext context, unsigned int passIndex);
int R_SetVertexData(GfxCmdBufState *state, const void *data, int vertexCount, int stride);

//#include "gfx_d3d/r_shade.h"

//t6/code/src_noserver/gfx_d3d/r_shader_constant_set.cpp
void R_InitShaderConstantSet(ShaderConstantSet *scs);
BOOL R_ShaderConstantSetIsUsed(const ShaderConstantSet *scs);
void R_CopyShaderConstantSet(const ShaderConstantSet *scs_src, ShaderConstantSet *scs_dst);
int R_GetConstantIndex(const ShaderConstantSet *scs, const char *constantName);
char R_SetShaderConstantSetValue(ShaderConstantSet *scs, int index, const vec4_t *v);
char R_SetShaderConstantSetValue(ShaderConstantSet *scs, int index, float x, float y, float z, float w);
char R_SetShaderConstantSetValueX(ShaderConstantSet *scs, int index, float x);
char R_SetShaderConstantSetValueY(ShaderConstantSet *scs, int index, float y);
char R_SetShaderConstantSetValueZ(ShaderConstantSet *scs, int index, float z);
char R_SetShaderConstantSetValueW(ShaderConstantSet *scs, int index, float w);
int RB_ApplyShaderConstantSet(GfxCmdBufSourceState *gfxSourceState, const ShaderConstantSet *scs);
void XModelDrawSurf_EncodeIndex(GfxDrawSurf *drawSurf, unsigned int scsIndex);
ShaderConstantSet *RB_ShaderConstantSetFromDrawSurf(;
void RB_ApplyShaderConstantSet(GfxCmdBufSourceState *gfxSourceState, const GfxDrawSurf *drawSurf);
BOOL RB_DrawSurf_Uses_ShaderConstantSet(const GfxDrawSurf *drawSurf);
unsigned int CopyShaderConstantSetToBackendData(const ShaderConstantSet *scs);
void R_XModelDrawSurfEncodeShaderConstantSet(;
unsigned int R_ShaderConstantSet_CopyToFrontEndDataOut(const ShaderConstantSet *scs);
ShaderConstantSet *R_ShaderConstantSet_FromFrontEndDataOut(unsigned int constSetindex);
void RB_SaveCurrentShaderConstantSetValues(;
// void __thiscall ScopedShaderConstantSetUndo::ScopedShaderConstantSetUndo(;
// void __thiscall ScopedShaderConstantSetUndo::~ScopedShaderConstantSetUndo(ScopedShaderConstantSetUndo *this);
void R_ShaderConstantShowDebug(;
bool R_MapShaderConstantSet(ShaderConstantSet *scs, int index, const char *constantName);
int R_AllocShaderConstantSet(ShaderConstantSet *scs, const char *name);

//#include "gfx_d3d/r_skinnedverts_load_db.h"

//t6/code/src_noserver/gfx_d3d/r_sky.cpp
void R_RegisterSunDvars(const char *a1, dvarType_t a2);
void R_SetSunFromDvars(sunflare_t *sun);
void R_LoadSunThroughDvars(const char *sunName, sunflare_t *sun);
void R_FlushSun();

//t6/code/src_noserver/gfx_d3d/r_skybox.cpp
void R_RegisterSkyboxModel();
void R_ClearSkyboxModel();
void R_AddSkyboxModel(const vec3_t *eyePos);
XModel *R_MapGetSkyboxModel();

//t6/code/src_noserver/gfx_d3d/r_sky_load_obj.cpp
void R_LoadSun(const char *name, sunflare_t *sun);

//t6/code/src_noserver/gfx_d3d/r_spotshadow.cpp
;
void R_GetSpotShadowLookupMatrix(;
void R_AddSpotShadowModelEntities(;
void R_EmitSpotShadowMapSurfs(GfxViewInfo *viewInfo);
void R_GenerateAllSortedSpotShadowDrawSurfs(GfxViewInfo *viewInfo, int viewIndex);
char R_AddSpotShadowsForLight(;

//t6/code/src_noserver/gfx_d3d/r_sprite.cpp
void R_BuildQuadStampCodeMeshVerts(;
void R_GenerateQuadStampCodeMeshVerts(;
// _DWORD *really_fast_sincos@<eax>(_DWORD *result@<eax>, _DWORD *a2@<ecx>, __m128d a3@<xmm0>);
;

//t6/code/src_noserver/gfx_d3d/r_state.cpp
void R_ChangeDepthHackNearClip(GfxCmdBufSourceState *source, unsigned int depthHackFlags);
void R_ChangeObjectPlacement_Core(GfxCmdBufSourceState *source, const GfxScaledPlacement *placement);
void R_ChangeObjectPlacementRemote(GfxCmdBufSourceState *a1, const GfxScaledPlacement *a2);
void R_DeriveViewMatrix(GfxCmdBufSourceState *source);
;
void R_DeriveProjectionMatrix(GfxCmdBufSourceState *source);
void R_DeriveViewProjectionMatrix(GfxCmdBufSourceState *source);
;
void R_DeriveShadowLookupMatrix(GfxCmdBufSourceState *source);
;
void R_DeriveCodeMatrix(;
const vec4_t *R_GetCodeMatrix(GfxCmdBufSourceState *source, unsigned int sourceIndex, unsigned int firstRow);
const GfxImage *R_GetTextureFromCode(;
void R_TextureFromCodeError(const GfxCmdBufContext *context, unsigned int codeTexture);
GfxImage *R_OverrideLightmapImage(int dvar_integer);
void R_SetReflectionProbe(GfxCmdBufContext context, unsigned int reflectionProbeIndex);
void R_ChangeDepthRange(GfxCmdBufState *state, GfxDepthRangeType depthRangeType);
void R_ChangeIndices(GfxCmdBufPrimState *state, ID3D11Buffer *ib);
void R_FlushStreamSources(GfxCmdBufPrimState *state, int firstStream, int lastStream);
void R_ChangeStreamSource(;
void R_DrawIndexedPrimitive(;
ID3D11BlendState *R_HW_CreateBlendState(unsigned int stateBits0);
ID3D11DepthStencilState *R_HW_CreateDepthStencilState(unsigned int stateBits1, unsigned __int8 stencilMask);
ID3D11RasterizerState *R_HW_CreateRasterizerState(unsigned int stateBits0, unsigned int stateBits1);
void R_DX11_ReleaseSamplerStates();
void R_SetSampler(;
void R_TextureOverride(;
void R_GetViewport(GfxCmdBufSourceState *source, GfxViewport *outViewport);
void R_SetViewport(GfxCmdBufState *state, const GfxViewport *viewport);
void R_SetViewportStruct(GfxCmdBufSourceState *source, const GfxViewport *viewport);
void R_SetViewportStructNoOffset(GfxCmdBufSourceState *source, const GfxViewport *viewport);
void R_SetScissorStruct(GfxCmdBufSourceState *source, const GfxViewport *scissor);
void R_ClearScissorStruct(GfxCmdBufSourceState *source);
char R_GetScissor(GfxCmdBufSourceState *source, GfxViewport *outScissor);
void R_SetScissor(GfxCmdBufState *state, const GfxViewport *_scissor);
void R_ClearScissor(GfxCmdBufState *state);
void R_SetViewportValues(GfxCmdBufSourceState *source, int x, int y, int width, int height);
void R_SetFullViewport(GfxCmdBufSourceState *source);
void R_UpdateViewport(GfxCmdBufSourceState *source, GfxViewport *viewport);
void R_DisableSampler(GfxCmdBufState *state, unsigned int samplerIndex);
void R_UnbindImage(GfxCmdBufState *state, const GfxImage *image);
void R_SetRenderTargetSize(GfxCmdBufSourceState *source, unsigned __int8 newTargetId);
void R_SetRenderTarget(GfxCmdBufContext context, unsigned __int8 newTargetId);
void R_ClearRenderTargetForMultiGpu(GfxCmdBufContext context, unsigned __int8 targetId);
void R_ClearScreenInternal(;
void R_ClearScreen(;
void R_DrawCall(;
void R_SetLightmap(GfxCmdBufContext context, unsigned int lmapIndex);
void R_ClearAllStreamSources(GfxCmdBufPrimState *state);
void R_SetMeshStream(GfxCmdBufState *state, GfxMeshData *mesh);
void R_HW_SetBlendState(GfxCmdBufState *state, unsigned int stateBits0);
ID3D11DepthStencilState *R_HW_FindDepthStencilState(unsigned int stateBits1, unsigned __int8 stencilMask);
void R_HW_SetDepthStencilState(;

//#include "gfx_d3d/r_state.h"

//t6/code/src_noserver/gfx_d3d/r_state_utils.cpp
void R_InitCmdBufSourceState(GfxCmdBufSourceState *source, const GfxCmdBufInput *input, int cameraView);
void R_SetDebugShaderFeatures(GfxCmdBufSourceState *source);
void R_PixStartNamedRenderTarget(unsigned __int8 renderTargetId);
void R_InitCmdBufState(GfxCmdBufState *state, const GfxBackEndData *backEndData);
void R_ShutdownCmdBufState(GfxCmdBufState *state);
GfxCmdBufSourceState *R_GetActiveWorldMatrix(GfxCmdBufSourceState *source);
;
void R_Set2D(GfxCmdBufSourceState *source);
void R_CmdBufSet3D(GfxCmdBufSourceState *source);
void R_Set3D(GfxCmdBufSourceState *source);
void R_BeginView(GfxCmdBufSourceState *source, const GfxSceneDef *sceneDef, const GfxViewParms *viewParms);
void R_SetShadowLookupMatrix(GfxCmdBufSourceState *source, const GfxMatrix *matrix);
void R_InitGlobalCmdBufState();

//t6/code/src_noserver/gfx_d3d/r_staticmodel.cpp
int FindStaticModelIndex(const vec3_t *pos);
void HideStaticModel(unsigned int smodelIndex);
void UnhideStaticModel(unsigned int smodelIndex);

//#include "gfx_d3d/r_staticmodel_load_db.h"

//t6/code/src_noserver/gfx_d3d/r_staticmodel_load_obj.cpp
int R_CellForPoint(const vec3_t *origin);
unsigned int R_FindNearestReflectionProbeInCell(int cellIndex, const vec3_t *origin);
unsigned int R_FindNearestReflectionProbe(const GfxWorldDraw *worldDraw, const vec3_t *origin);
unsigned int R_FindProbeFromVolume(const GfxWorldDraw *worldDraw, const vec3_t *origin);
// unsigned int R_CalcReflectionProbeIndex@<eax>(;
void R_AllocStaticModels(GfxAabbTree *tree);
int R_SortGfxAabbTreeChildren(;
int CompareStaticModels(const void *smodel0, const void *smodel1);
void R_SortGfxAabbTree(GfxWorld *world, GfxAabbTree *tree);
void R_AddStaticModelToAabbTree_r(GfxWorld *world, GfxAabbTree *tree, int smodelIndex);
void R_AddStaticModelToCell(GfxWorld *world, GfxStaticModelInst *smodelInst, const int cellIndex);
const char *GetNameFromStaticModelInst(const GfxStaticModelInst *smodelInst);
void R_FilterStaticModelIntoCells_r(;
int R_CellForPoint(const GfxWorld *world, const vec3_t *origin);
unsigned int R_CalcReflectionProbeIndex(const GfxWorld *world, const vec3_t *origin);
void R_SetStaticModelReflectionProbe(;
void R_CreateStaticModel(;

//t6/code/src_noserver/gfx_d3d/r_sunshadow.cpp
void R_CalcBoxVsCylinderRayMinBox(;
void R_GetSceneExtentsAlongDir(;
void R_GetSunAxes(vec3_t *sunAxis);
void R_ClipSpaceToWorldSpace(;
void R_SetupSunShadowBoundingPoly(;
void R_SunShadowMapBoundingPoly(;
// unsigned int R_SunShadowMapClipSpaceClipPlanes@<eax>(;
void R_SunShadowMapProjectionMatrix(;
void R_SetupSunShadowMapPartitionFraction(;
void R_SetupNearRegionPlane(const vec4_t *partitionFraction);
void R_SetupSunShadowMapProjection(;
void R_GetSunShadowLookupMatrix(;
void R_SunShadowMaps(bool cache);
void R_FinishSunShadowMaps();
void R_MergeAndEmitSunShadowMapsSurfs(GfxViewInfo *viewInfo);
void R_SetupSunShadowMaps(const GfxViewParms *viewParms, GfxSunShadow *sunShadow);

//#include "gfx_d3d/r_surface_load_db.h"

//#include "gfx_d3d/r_types_d3d.h"

//t6/code/src_noserver/gfx_d3d/r_ui3d.cpp
GfxUI3DStack *R_GetUI3DStack();
void R_UI3DStack_Push(GfxUI3DStack *stack, int val);
void R_UI3DStack_Pop(GfxUI3DStack *stack);
int R_UI3DStack_Top(GfxUI3DStack *stack);
ScreenPlacement *R_UI3D_ScrPlaceFromTextureWindow(int windowIndex);
void R_UI3D_SetBlurRadius(float blurRadius);
void R_UI3D_Shutdown();
void R_UI3D_SetupBackendData_UVConstants(GfxUI3DBackend *ui3dBackend);
void R_UI3D_SetupBackendData(GfxUI3DBackend *ui3dBackend);
void ScrPlace_SetupUI3D(ScreenPlacement *scrPlace, int viewportWidth, int viewportHeight);
void R_UI3D_IncrementRenderCmdCount(int wndIndex, int renderCmdDrawsSomething);
void R_UI3D_SetupTextureWindow(;
void RB_UI3D_SetShaderConstants(GfxCmdBufSourceState *source, const GfxUI3DBackend *rbUI3D);
void RB_SetUI3DSamplerAndConstants(GfxCmdBufSourceState *cmdBufSrcState, const GfxUI3DBackend *rbUI3D);
int RB_UI3D_GetValidWindows(const GfxUI3DBackend *rbUI3D, int *validWindowsArray);
void RB_UI3D_RenderToTexture(const void *cmds, const GfxUI3DBackend *rbUI3D, const GfxCmdBufInput *input);
void R_UI3D_OnetimeInit(int width, int height, int pmemLocation, bool allocatePingPongBuffer);
void R_UI3D_PerframeInit();

//t6/code/src_noserver/gfx_d3d/r_utils.cpp
int R_HashAssetName(const char *name);
unsigned int R_HashString(const char *string, unsigned int hash);
void *R_AllocGlobalVariable(unsigned int bytes, const char *name);
void R_FreeGlobalVariable(void *var);
char R_CullPointAndRadius(const vec3_t *pt, float radius, const DpvsPlane *clipPlanes, int clipPlaneCount);
;
double FresnelTerm(float n0, float n1, float cosIncidentAngle);
char R_GetClearColor(vec4_t *unpackedRgba);
;

//t6/code/src_noserver/gfx_d3d/r_warn.cpp
void R_UpdateFrameRate();
// void R_WarnOncePerFrame(float a1@<xmm0>, GfxWarningType warnType, ...);
void R_WarnInitDvars(int a1, dvarType_t a2);

//t6/code/src_noserver/gfx_d3d/r_wind.cpp
void R_SetWindDirection(vec3_t *dir, float speed);
void R_SetVariantWindSpringAngle(unsigned int index, float angle);
void R_SetVariantWindRustleAngle(unsigned int windIndex, const vec3_t *angles);
void R_SetWindShaderConstants(GfxCmdBufInput *input);
void R_CopyWindStateToBackEnd();

//t6/code/src_noserver/gfx_d3d/r_workercmds.cpp
int r_add_bspCallback_Implementation(jqBatch *batch, void *data);
int r_add_bsp_sunCallback_Implementation(jqBatch *batch, void *data);
int r_add_staticmodelCallback_Implementation(jqBatch *batch, void *data);
int r_add_staticmodel_sunCallback_Implementation(jqBatch *batch, void *data);
int r_add_bsp_dlightCallback_Implementation(jqBatch *batch, void *data);
int r_add_smodels_dlightCallback_Implementation(jqBatch *batch, void *data);
int r_model_skinCallback_Implementation(jqBatch *batch, void *data);
int r_draw_litCallback_Implementation(jqBatch *batch, void *data);
int r_draw_lit_bspCallback_Implementation(jqBatch *batch, void *data);
int r_draw_lit_static_modelCallback_Implementation(jqBatch *batch, void *data);
int fx_update_remainingCallback_Implementation(jqBatch *batch, void *data);
int fx_post_updateCallback_Implementation(jqBatch *batch, void *data);
int fx_draw_nonspriteCallback_Implementation(jqBatch *batch, void *data);
int fx_marks_drawCallback_Implementation(jqBatch *batch, void *data);
int fx_spawnCallback_Implementation(jqBatch *batch, void *data);
int r_add_bspCallback(jqBatch *batch);
int r_add_bsp_sunCallback(jqBatch *batch);
int r_add_staticmodelCallback(jqBatch *batch);
int r_add_staticmodel_sunCallback(jqBatch *batch);
int r_add_bsp_dlightCallback(jqBatch *batch);
int r_add_smodels_dlightCallback(jqBatch *batch);
int r_model_skinCallback(jqBatch *batch);
int r_draw_litCallback(jqBatch *batch);
int r_draw_lit_bspCallback(jqBatch *batch);
int r_draw_lit_static_modelCallback(jqBatch *batch);
int r_draw_depthCallback(jqBatch *batch);
int r_dpvs_staticCallback(jqBatch *batch);
int r_dpvs_dynmodelCallback(jqBatch *batch);
int r_dpvs_sceneentCallback(jqBatch *batch);
int r_dpvs_dynbrushCallback(jqBatch *batch);
int fx_updateCallback(jqBatch *batch);
int fx_update_remainingCallback(jqBatch *batch);
int fx_update_portalledCallback(jqBatch *batch);
int fx_post_updateCallback(jqBatch *batch);
int fx_drawCallback(jqBatch *batch);
int fx_update_nonspriteCallback(jqBatch *batch);
int fx_draw_nonspriteCallback(jqBatch *batch);
int dobj_skelCallback(jqBatch *batch);
int dobj_skinCallback(jqBatch *batch);
int model_skelCallback(jqBatch *batch);
int fx_marks_drawCallback(jqBatch *batch);
int fx_update_spotCallback(jqBatch *batch);
int fx_spawnCallback(jqBatch *batch);

//t6/code/src_noserver/gfx_d3d/r_workercmds_common.cpp
void R_ProcessCmd_UpdateFxSpotLight(FxCmd *cmd);
void R_ProcessCmd_UpdateFxNonDependent(FxCmd *cmd);
void R_DrawEffects(FxCmd *cmd);
void R_ProcessCmd_FxPostUpdate(FxCmd *cmd);
void R_UpdateSpotLightEffect(FxCmd *cmd);
void R_UpdateNonDependentEffects(FxCmd *cmd);
void R_UpdateRemainingEffects(FxCmd *cmd);
void R_UpdateNonSpriteEffects(FxCmd *cmd);
void R_ProcessCmd_DrawNonSprite(FxCmd *cmd);
void R_UpdatePortalledEffects(FxCmd *cmd);
void R_UpdateXModelBoundsDelayed(GfxSceneEntity *sceneEnt);
void R_SkinGfxEntityDelayed(GfxSceneEntity *sceneEnt);
void R_SkelGfxModelInit();
void R_SkelGfxModelDelayed(GfxSceneModel *sceneModel);
void R_SkelGfxModelFinish();

//t6/code/src_noserver/gfx_d3d/r_xsurface.cpp
int XSurfaceGetNumVerts(const XSurface *surface);
int XSurfaceGetNumTris(const XSurface *surface);
void XSurfaceGetVerts(const XSurface *surf, float *pVert, float *pTexCoord, float *pNormal);

//#include "gfx_d3d/r_xsurface_load_db.h"

