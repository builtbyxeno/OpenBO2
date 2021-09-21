#pragma once

#include "types.h"

//t6/code/src_noserver/gfx_d3d/rb_backend.cpp
void TRACK_rb_backend();
void RB_SetIdentity();
void R_SetVertex2d(GfxVertex *vert, float x, float y, float s, float t, unsigned int color);
void RB_DrawFullSceneTri(const Material *material, unsigned __int8 scene);
void RB_TessAddQuadIndices(unsigned int vertCount);
void RB_DrawSW4Quads(const Material *material, int ParticleCount);
void RB_DrawStretchPic(const Material *material, float x, float y, float w, float h, float s0, float t0, float s1, float t1, unsigned int color, GfxPrimStatsTarget statsTarget);
void RB_DrawStretchPicW(const Material *material, float x, float y, float w0, float w, float h, float s0, float t0, float s1, float t1, unsigned int color, GfxPrimStatsTarget statsTarget);
void RB_DrawStretchPicZ(const Material *material, float x, float y, float z, float w, float h, float s0, float t0, float s1, float t1, unsigned int color, GfxPrimStatsTarget statsTarget);
void RB_DrawStretchPicFlipST(const Material *material, float x, float y, float w, float h, float s0, float t0, float s1, float t1, unsigned int color, GfxPrimStatsTarget statsTarget);
void RB_DrawStretchPicRotate(const Material *material, float x, float y, float w, float width, float height, float s0, float t0, float s1, float t1, float sinAngle, float cosAngle, unsigned int color, GfxPrimStatsTarget statsTarget);
void RB_DrawFullScreenColoredQuad(const Material *material, float s0, float t0, float s1, float t1, unsigned int color);
void RB_FullScreenColoredFilter(const Material *material, unsigned int color);
void RB_FullScreenFilterWithFlag(const Material *material, int filterFlags);
void RB_FullScreenFilter(const Material *material);
void RB_SplitScreenTexCoords(float x, float y, float w, float h, float *s0, float *t0, float *s1, float *t1);
void RB_SplitScreenFilter(const Material *material, const GfxViewInfo *viewInfo, unsigned int color);
void R_Resolve(GfxCmdBufContext context, GfxImage *image);
void R_ResolveFloatZ(GfxCmdBufContext context);
void RB_StretchPicCmd(GfxRenderCommandExecState *execState);
void RB_StretchPicCmdFlipST(unsigned int a1, GfxRenderCommandExecState *execState);
void RB_StretchPicRotateXYCmd(GfxRenderCommandExecState *execState);
void RB_StretchPicRotateSTCmd(GfxRenderCommandExecState *execState);
void RB_DrawQuadPicCmd(GfxRenderCommandExecState *execState);
void RB_DrawQuadList2DCmd(GfxRenderCommandExecState *execState);
void RB_SetUIStencilState(unsigned __int8 stencilWrite, unsigned __int8 stencilValue, unsigned int *stateBits);
void RB_DrawUIQuadsInternal(unsigned __int8 stencilWrite, unsigned __int8 stencilValue, bool isUI3D, int quadCount, const vec3_t *xyz, const vec2_t *st, const GfxColor *color, unsigned __int8 noclip);
void RB_DrawEmblemLayer(char *a1, GfxRenderCommandExecState *execState);
void RB_StretchCompositeCmd(char *a1, GfxRenderCommandExecState *execState);
void RB_DrawFullScreenColoredQuadCmd(GfxRenderCommandExecState *execState);
void TessQuad(unsigned __int16 v0, unsigned __int16 v1, unsigned __int16 v2, unsigned __int16 v3);
void __cdecl RB_DrawFramedCmd(GfxRenderCommandExecState *execState);
void RB_ConstantSetCmd(GfxRenderCommandExecState *execState);
unsigned int R_RenderDrawSurfStaticModelListMaterial(GfxCmdBufContext context, const GfxDrawSurfListInfo *info, unsigned int firstDrawSurfIndex);
unsigned int R_RenderDrawSurfBspListMaterial(GfxCmdBufContext context, const GfxDrawSurfListInfo *info, unsigned int firstDrawSurfIndex);
unsigned int R_RenderDrawSurfListMaterial(const GfxDrawSurfListArgs *listArgs);
void R_SetCustomCodeConstants(GfxCmdBufContext context);
void R_DrawSurfs(GfxCmdBufContext context, const GfxDrawSurfListInfo *info);
void R_DrawSurfsBsp(GfxCmdBufContext context, const GfxDrawSurfListInfo *info);
void R_DrawSurfsStaticModel(GfxCmdBufContext context, const GfxDrawSurfListInfo *info);
void RB_ClearScreenCmd(GfxRenderCommandExecState *execState);
void RB_SetGammaRamp(int a1, int a2, int a3);
void RB_BlendSavedScreenFlashedCmd(GfxRenderCommandExecState *execState);
void RB_DrawPoints2D(const GfxCmdDrawPoints *cmd);
void RB_DrawPoints3D(const GfxCmdDrawPoints *cmd);
void RB_DrawPointsCmd(GfxRenderCommandExecState *execState);
void RB_DrawLines2D(int count, int width, const GfxPointVertex *verts);
void RB_DrawLines3D(int count, int width, const GfxPointVertex *verts, bool depthTest);
void RB_DrawLinesCmd(GfxRenderCommandExecState *execState);
void RB_DrawTriangles_Internal(const Material *material, unsigned __int8 techType, __int16 indexCount, const unsigned __int16 *indices, __int16 vertexCount, const vec4_t *xyzw, const vec3_t *normal, const GfxColor *color, const vec2_t *st);
void RB_DrawUIQuadsCmd(char *a1, GfxRenderCommandExecState *execState);
void RB_DrawUIQuadsReplaceImageCmd(char *a1, GfxRenderCommandExecState *execState);
void RB_DrawUITrianglesCmd(GfxRenderCommandExecState *execState);
void __cdecl RB_DrawTrianglesCmd(GfxRenderCommandExecState *execState);
void RB_SetCustomConstantCmd(GfxRenderCommandExecState *execState);
void RB_SetMaterialColorCmd(GfxRenderCommandExecState *execState);
void RB_BeginViewCmd(GfxRenderCommandExecState *execState);
void RB_SetViewportCmd(GfxRenderCommandExecState *execState);
void RB_SetScissorCmd(GfxRenderCommandExecState *execState);
void RB_ResolveCompositeCmd(GfxRenderCommandExecState *execState);
void RB_PCCopyImageGenMIPCmd(GfxRenderCommandExecState *execState);
void RB_LookupColor(unsigned __int8 c, unsigned __int8 *color);
float RB_DrawHudIcon(const char *text, float x, float y, float sinAngle, float cosAngle, Font_s *font, float xScale, float yScale, unsigned int color);
float RB_DrawButton(const char *text, float x, float y, float sinAngle, float cosAngle, Font_s *font, float xScale, float yScale, unsigned int color, int *buttonNameLen);
int RB_DrawChar(unsigned int color, const Material *material, float x, float y, float w, float width, float height, float sinAngle);
void RB_DrawCursor(const Material *material, unsigned __int8 cursor, float x, float y, float sinAngle, float cosAngle, Font_s *font, float xScale, float yScale, unsigned int color);
void GlowColor(GfxColor *result, GfxColor baseColor, GfxColor forcedGlowColor, int renderFlags);
bool SetupFadeinFXVars(const char *text, int maxLength, int renderFlags, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, bool *resultDrawRandChar, int *resultRandSeed, bool *resultDecaying, int *resultdecayTimeElapsed);
bool SetupCOD7DecodeFXVars(const char *text, int maxLength, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, int *randSeed, int *resultRandomCharsLength, int *resultMaxLength, bool *resultDecaying, int *resultDecayTimeElapsed);
char SetupTypewriterFXVars(const char *text, int maxLength, int renderFlags, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, bool *resultDrawRandChar, int *resultRandSeed, int *resultMaxLength, bool *resultDecaying);
char SetupPopInFXVars(const char *text, int maxLength, int renderFlags, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, float *sizeIncrease, int *resultRandSeed, int *resultMaxLength, bool *resultDecaying);
bool SetupPulseFXVars(const char *text, int maxLength, int renderFlags, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, bool *resultDrawRandChar, int *resultRandSeed, int *resultMaxLength, bool *resultDecaying, int *resultdecayTimeElapsed);
void GetShiftColor(GfxColor targetColor, int fxBirthTime, int fxDecayStart, int fxDecayDuration, GfxColor startColor, GfxColor *shiftColor);
bool SetupRedactTextFXVars(const char *text, int maxLength, int renderFlags, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, bool *resultDrawRandChar, int *resultRandSeed, int *resultMaxLength, bool *resultDecaying, int *resultdecayTimeElapsed);
void SetupRedactFXVars(int *randSeed, int fxBirthTime, int maxLength, int fxRedactDecayStartTime, int fxRedactDecayDuration, int mode, vec4_t *src_rect, vec4_t *max_rect, vec4_t *out_rect, float *u, Material **mat);
void GetDecayingStringAlphaInfo(int decayTimeElapsed, int fxDecayDuration, unsigned __int8 alpha, unsigned __int8 *resultAlpha);
void GetDecayingLetterInfo(unsigned int letter, Font_s *font, int *randSeed, int decayTimeElapsed, int fxBirthTime, int fxDecayDuration, unsigned __int8 alpha, bool *resultSkipDrawing, unsigned __int8 *resultAlpha, unsigned int *resultLetter, bool *resultDrawExtraFxChar);
void DrawTextFxExtraCharacter(const Material *material, int charIndex, float x, float y, float w0, float w, float h, float sinAngle, float cosAngle, unsigned int color);
void DrawText2D(int *a1, int *a2, bool *text, const char *x, float y, float w, float font, Font_s *xScale, float yScale, float sinAngle, float cosAngle, float color, const GfxColor maxLength, int renderFlags, int cursorPos, int cursorLetter, float padding, float glowForcedColor, GfxColor fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, int fxRedactDecayStartTime, int fxRedactDecayDuration, int fxMaterial, const Material *fxMaterialGlow, const Material *a27);
void __cdecl DrawTeleType(const char *text, float x, float y, float w, float h, Font_s *font, float xScale, float yScale, const GfxColor color, int renderFlags, int cursorPos, float cursorLetter, float padding, int fxBirthTime);
void RB_DrawText(int *a1, int *a2, bool *text, const char *font, Font_s *x, float y, float color, const GfxColor a8);
void RB_DrawCharInSpace(const Material *material, const vec3_t *xyz, const vec3_t *dx, const vec3_t *dy, const Glyph *glyph, unsigned int color);
void RB_DrawTextInSpace(unsigned int a1, const char *text, Font_s *font, const vec3_t *org, const vec3_t *xPixelStep, const vec3_t *yPixelStep, unsigned int color);
void RB_DrawText2DCmd(const Material *a1, GfxRenderCommandExecState *execState);
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
void RB_SaveScreen(int a1, const GfxSaveScreenParam *p);
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
void RB_DrawWaypoint(const GfxViewInfo *viewInfo, Material *material, GfxColor color, vec3_t *origin, float radius, bool screenSize, bool alignBottom, bool forceNear);

//t6/code/src_noserver/gfx_d3d/rb_debug.cpp
void TRACK_rb_debug();
int RB_AddDebugLine(const vec3_t *start, const vec3_t *end, const vec4_t *color, bool depthTest, int vertCount, int vertLimit, GfxPointVertex *verts);
int RB_EndDebugLines(int vertCount, const GfxPointVertex *verts);
void RB_SetPolyVert(const vec3_t *xyz, GfxColor color, int tessVertIndex);
void RB_DrawPolyInteriors(PolySet *polySet);
void RB_DrawPolyOutlines(PolySet *polySet);
const GfxBackEndData *RB_DrawDebugPolys();
void RB_DrawDebugSphere(trDebugSphere_t *sphere);
void RB_DrawDebugSpheres(trDebugSphere_t *spheres, int sphereCount);
void RB_DrawDebugLines(trDebugLine_t *lines, int lineCount, GfxPointVertex *verts);
void RB_DrawDebugStrings(trDebugString_t *strings, int stringCount);
void RB_AddPlumeStrings(float viewParms, const GfxViewParms *a2);
void RB_SetDebugBrushesAndPatchesCallback(void (*callback)());
void __cdecl RB_DrawDebug(const GfxViewParms *viewParms);
void RB_ApplySunLight(const vec3_t *verts, const vec4_t *color, vec4_t *out_color);
void RB_BeginCollisionPolygons(bool faceDepthTest, bool faceBlend);
void RB_DrawCollisionPolygon(int vertCount, const vec3_t *verts, const vec4_t *faceColor, bool faceDepthTest, int debug_partition);
materialCommands_t *RB_GetCmd();
void __cdecl RB_EndCollisionPolygons();

//t6/code/src_noserver/gfx_d3d/rb_depthprepass.cpp
void R_DepthPrepassCallback(const void *userData, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DepthPrepass(int a1, const GfxViewInfo *viewInfo, GfxCmdBuf *cmdBuf);
void RB_DrawDepthPrepassCommandBuffer(int a1, const GfxBackEndData *data, const GfxViewInfo *viewInfo);
void R_DrawDepthCmd(DrawDepthWorkerCmd *cmd);

//t6/code/src_noserver/gfx_d3d/rb_draw3d.cpp
void RB_DrawWaypoints(const LocalClientNum_t localClientNum, const GfxViewInfo *viewInfo);
void R_CalcGameTimeVec(float gameTime, vec4_t *out);
void R_ShowTris(GfxCmdBufContext context, const GfxDrawSurfListInfo *info);
void RB_CompositeSceneGroup();
void RB_EndSceneRendering(GfxCmdBufContext context, const GfxCmdBufInput *input, const GfxViewInfo *viewInfo);
void R_RunCommandBuffer(const GfxBackEndData *data, GfxCmdBuf *cmdBuf);
void R_SetAndClearSceneTarget(const GfxViewport *viewport, const GfxViewInfo *viewInfo);
void R_DrawFullbrightLitCallback(const void *__formal, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawFullbrightDecalCallback(const void *__formal, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawFullbrightEmissiveCallback(const void *__formal, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawFullbrightOrDebugShader(void (*callback)(const void *, GfxCmdBufContext, const GfxViewInfo *), const GfxViewInfo *viewInfo);
void R_DrawFullbright(const GfxViewInfo *viewInfo, GfxCmdBufInput *input, GfxCmdBuf *cmdBuf);
void RB_FullbrightDrawCommands(const GfxViewInfo *viewInfo);
int RB_FullbrightDrawCommandsCommon();
void R_DrawDebugShaderLitCallback(const void *__formal, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawDebugShaderDecalCallback(const void *__formal, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawDebugShaderEmissiveCallback(const void *__formal, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void RB_DebugShaderDrawCommands(const GfxViewInfo *viewInfo);
const GfxBackEndData *RB_DebugShaderDrawCommandsCommon();
void RB_SetFrameBufferAlpha();
void R_DrawEmissiveOpaqueCallback(const void *__formal, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawEmissiveOpaque(int a1, const GfxViewInfo *a2, GfxCmdBuf *a3);
void R_DrawEmissiveFXCallback(const void *userData, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawEmissiveFX(const GfxViewInfo *viewInfo, GfxCmdBuf *cmdBuf);
void R_DrawEmissiveFX(const GfxViewInfo *a1, GfxCmdBuf *a2);
void R_DrawViewmodelFX(const GfxViewInfo *a1, GfxCmdBuf *a2);
void R_DrawPostBlur(const GfxViewInfo *viewInfo, unsigned __int8 renderTarget);
void R_DrawSuperflare(const GfxViewInfo *viewInfo, unsigned __int8 renderTarget, SuperflareDrawlistModes superflareDrawlistModes);
void R_ResolveDistortion(const GfxViewInfo *viewInfo);
void RB_StandardRenderCommands(const GfxViewInfo *viewInfo);
void RB_SonarRenderToTexture(const GfxBackEndData *data, const GfxViewInfo *viewInfo);
unsigned int RB_DrawLitCommandBuffer(const GfxBackEndData *data, const GfxViewInfo *viewInfo, unsigned __int8 cmdBufType, unsigned int cmdBufCount, void (*drawFunction)(const GfxViewInfo *, GfxCmdBuf *, LitPhaseID), LitPhaseID phase, const char *label, unsigned int drawList, GPUTimerId timer);
void RB_DrawMiscCommandBuffer(const GfxBackEndData *data, const GfxViewInfo *viewInfo, unsigned __int8 cmdBufType, void (*drawFunction)(const GfxViewInfo *, GfxCmdBuf *), const char *label, unsigned int drawList, GPUTimerId timer);
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
void R_DrawPostBlur(const GfxViewInfo *viewInfo, GfxCmdBuf *cmdBuf, GfxCmdBufSourceState renderTarget);

//t6/code/src_noserver/gfx_d3d/rb_fog.cpp
void R_SetFrameFog(float input, GfxCmdBufInput *a2, const vec4_t *viewOrigin);

//t6/code/src_noserver/gfx_d3d/rb_imagefilter.cpp
void RB_VirtualToSceneRadius(float radius, float *radiusX, float *radiusY);
int RB_GaussianFilterPoints1D(float pixels, int srcRes, int dstRes, int tapLimit, float *tapOffsets, float *tapWeights);
int *RB_GenerateGaussianFilter1D(int a1, float pixels, int *res, int axis);
void RB_GenerateGaussianFilter2D(float radius, int srcWidth, int srcHeight, int dstWidth, int dstHeight, GfxImageFilterPass *filterPass);
int RB_GenerateGaussianFilterChain(float radiusX, float radiusY, int srcWidth, int srcHeight, int dstWidth, int dstHeight, int passLimit, GfxImageFilterPass *filterPass);
void RB_SetupFilterPass(const GfxImageFilterPass *filterPass);
void RB_FilterPingPong(const GfxImageFilter *filter, int passIndex);
void RB_FilterImage(int a1, GfxImageFilter *filter);
void __cdecl RB_GaussianFilterImage(float radius, unsigned __int8 srcRenderTargetId, unsigned __int8 dstRenderTargetId);
void RB_GaussianFilter(float radiusX, float radiusY, unsigned __int8 srcRenderTargetId, unsigned __int8 dstRenderTargetId, unsigned __int8 tmpRenderTargetId);

//t6/code/src_noserver/gfx_d3d/rb_imagetouch.cpp
int RB_CompareTouchImages(const void *e0, const void *e1);
void RB_TouchAllImages();

//t6/code/src_noserver/gfx_d3d/rb_light.cpp
void R_CalculateLightGridColorFromCoeffs(const __m128 *coeffs, const vec3_t *dir, vec4_t *energy);
void R_DecodeLightGridCoeffsWeighted(const GfxCompressedLightGridCoeffs *compressedCoeffs, GfxDecodedLightGridColors *decodedColors, float weight);
unsigned __int8 *R_DecodeLightGridColorsWeighted(int a1, int a2, float a3);
void R_ComputeLightGridAverageAndVisibility(const GfxDecodedLightGridColors *colors, float primaryWeight, vec4_t *destAvgAndVis);
void R_ShowGridBox(const unsigned int *pos);
void R_ShowGridCorner(const GfxLightGrid *lightGrid, unsigned int x, unsigned int y, unsigned int z, float halfSize, const vec4_t *color);
void R_ShowLightGrid(const GfxLightGrid *lightGrid, const unsigned int *pos, const vec3_t *samplePos, const GfxLightGridEntry **cornerEntry, bool *suppressEntry, bool honorSuppression);
void R_SetLightGridColorsFromIndex(const GfxLightGrid *lightGrid, unsigned int colorsIndex, const vec3_t *heroPos, unsigned __int16 dest, GfxLightingSH *destSH);
void R_BlendAndSetLightGridColors(const GfxLightGrid *lightGrid, const unsigned __int16 *colorsIndex, const float *colorsWeight, unsigned int colorsCount, const vec3_t *heroPos, float weightNormalizeScale, unsigned __int16 dest, GfxLightingSH *destSH);
void R_SetBlackLightGridColors(unsigned __int16 dest, float *destVis, GfxLightingSH *destSH);
void R_SetDebugLightGridColors(unsigned __int16 dest, float *destVis, GfxLightingSH *destSH);
bool R_LookupSkyGridVolumesAtPoint(const GfxLightGrid *lightGrid, const vec3_t *samplePos, unsigned __int16 *colorsIndex, float *visibility, unsigned __int8 *primaryLightIndex);
unsigned __int8 R_ExtrapolateLightingAtPoint(const GfxLightGrid *lightGrid, const vec3_t *samplePos, const vec3_t *heroPos, unsigned __int16 dest, float *destVis, GfxLightingSH *destSH, GfxModelLightExtrapolation extrapolateBehavior, unsigned int defaultGridEntry);
unsigned __int8 R_ExtrapolateAverageLightingAtPoint(const GfxLightGrid *lightGrid, const vec3_t *samplePos, unsigned int defaultGridEntry, vec4_t *colorWithPrimaryWeight);
void R_GetLightGridSampleEntryQuad(const GfxLightGrid *lightGrid, const unsigned int *pos, const GfxLightGridEntry **entries, unsigned int *defaultGridEntry);
bool R_IsValidLightGridSample(const GfxLightGrid *lightGrid, const GfxLightGridEntry *entry, int cornerIndex, const unsigned int *pos, const vec3_t *samplePos);
unsigned __int8 R_LightGridLookup(const GfxLightGrid *lightGrid, const vec3_t *samplePos, float *cornerWeight, const GfxLightGridEntry **cornerEntry, unsigned int *defaultGridEntry);
unsigned int R_GetLightingAtPoint(const GfxLightGrid *remoteLightGrid, const vec3_t *samplePos, unsigned __int16 dest, float *destVis, GfxLightingSH *destSH, GfxModelLightExtrapolation extrapolateBehavior, bool useHeroLighting);
void R_GetAverageLightingAtPoint(unsigned int *a1, const vec3_t *samplePos, float primaryLightFraction, vec3_t *outColor);

//t6/code/src_noserver/gfx_d3d/rb_postfx.cpp
bool RB_UsingElectrifiedFX(const GfxViewInfo *viewInfo);
bool RB_UsingTransportedFX(const GfxViewInfo *viewInfo);
bool RB_UsingWaterSheetingFX(const GfxViewInfo *viewInfo);
bool RB_UsingDepthOfFieldFX(const GfxViewInfo *viewInfo);
bool RB_UsingGenericFilter(const GfxViewInfo *viewInfo);
int RB_FindActivePostFX(const GfxViewInfo *viewInfo);
void RB_SetVisionSetColorCorrection(int a1, const GfxViewInfo *viewInfo);
void RB_CreateVisionLut(const GfxViewInfo *viewInfo);
void RB_SetBloomRemapConstants(GfxBloom bloom);
void RB_SSAO(const GfxViewInfo *viewInfo);
void RB_TXAA(float viewInfo, int a2, int a3, const GfxViewInfo *a4);
BOOL R_UsingDoubleVision(const GfxViewInfo *viewInfo);
void RB_PoisonFX(const GfxViewInfo *viewInfo);
void RB_GenericFilterFX(int a1, const GfxViewInfo *viewInfo);
void RB_FlameFX(const GfxViewInfo *viewInfo);
void RB_ElectrifiedFX(const GfxViewInfo *viewInfo);
void RB_TransportedFX(const GfxViewInfo *viewInfo);
void RB_WaterSheetingFX(const GfxViewInfo *viewInfo);
void RB_GetSceneDepthOfFieldEquation(float nearOutOfFocus, float nearInFocus, float farInFocus, float farOutOfFocus, vec4_t *dofEquation, float zNear);
float RB_GetDepthOfFieldBlurFraction(const GfxViewInfo *viewInfo, float pixelRadiusAtSceneRes);
void RB_DepthOfFieldFX(const GfxViewInfo *viewInfo);
void RB_DepthOfFieldHDR(GfxViewInfo *viewInfo, int mode);
void RB_ReviveFX(int a1, __m128 a2, const GfxViewInfo *viewInfo);
void RB_BlurSceneFX(const GfxViewInfo *viewInfo);
void RB_AdditionalPostFX(__m128 a1, const GfxViewInfo *viewInfo);
void RB_BloomLDR(const GfxViewInfo *viewInfo);

//t6/code/src_noserver/gfx_d3d/rb_query.cpp
unsigned int RB_CalcOcclusionQuerySamples();
void RB_TessRectBillboard(const vec3_t *inPos, bool isWorldPos, float widthInPixels, float heightInPixels, GfxColor color, float depthBias);
float RB_GetSampleRectRelativeArea(const vec3_t *position, int widthInPixels, int heightInPixels);
void RB_UpdateVisibilityWithoutQuery(OcclusionQuery *occlusionQuery);
void RB_DrawOcclusionQueries(LocalClientNum_t localClientNum);
void R_GetOcclusionQueryUsage(int *queryTotalCount, int *queryInUseCount);
void RB_FreeOcclusionQuery(unsigned __int16 handle);
void RB_SetOcclusionQueryPosition(unsigned __int16 handle, const vec3_t *position);
double RB_GetOcclusionQueryVisibility(unsigned __int16 handle);
unsigned __int16 RB_AllocOcclusionQuery(float localClientNum, LocalClientNum_t a2, const vec3_t *position, bool isWorldPos, float depthBias);

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
void RB_DrawSunPostEffects(const GfxViewInfo *viewInfo, LocalClientNum_t localClientNum, float sunVisibilityAdjust);

//t6/code/src_noserver/gfx_d3d/rb_spotshadow.cpp
void R_DrawSpotShadowMapCallback(const void *userData, GfxCmdBufContext context);
void R_DrawSpotShadowMap(int a1, const GfxViewInfo *viewInfo, unsigned int spotShadowIndex, GfxCmdBuf *cmdBuf);
void RB_SpotShadowMaps(const GfxBackEndData *data, const GfxViewInfo *viewInfo);
void RB_DrawSpotShadowOverlay();

//t6/code/src_noserver/gfx_d3d/rb_state.cpp
void TRACK_rb_state();
void RB_InitSceneViewport();

//t6/code/src_noserver/gfx_d3d/rb_stats.cpp
const char *RB_Stats_GetStageName(GfxPrimStatsStage s);
const char *RB_Stats_GetTargetName(GfxPrimStatsTarget t);
int RB_GetCounterSum(GfxPrimStatsCounters counter, GfxPrimStatsStage stageFrom, GfxPrimStatsStage stageTo, GfxPrimStatsTarget tgtFrom, GfxPrimStatsTarget tgtTo);
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
void R_TessCodeMeshList_AddCodeMeshArgs(GfxCmdBufSourceState *source, const GfxBackEndData *data, const FxCodeMeshData *codeMesh);
void R_SetObjectIdentityPlacement(const GfxScaledPlacement *a1, GfxCmdBufSourceState *source);
unsigned int R_TessCodeMeshList(const GfxDrawSurfListArgs *listArgs);
unsigned int R_TessRopeMeshList(const GfxDrawSurfListArgs *listArgs);
unsigned int R_TessGlassMeshList(const GfxDrawSurfListArgs *listArgs);
unsigned int R_TessMarkMeshList(const GfxDrawSurfListArgs *listArgs);
void RB_Vec3DirWorldToView(const GfxCmdBufSourceState *source, const vec3_t *worldDir, vec3_t *viewDir);
void RB_CreateParticleCloud2dAxis(const GfxParticleCloud *cloud, const vec3_t *viewUp, vec2_t *viewAxis);
void R_SetParticleCloudConstants(GfxCmdBufSourceState *source, const GfxParticleCloud *cloud, bool shaderUsesVelDirWorld);
unsigned int R_TessParticleCloudList(const GfxDrawSurfListArgs *listArgs);
void R_DrawXModelSkinnedCached(GfxCmdBufContext context, const GfxModelSkinnedSurface *modelSurf);
void R_DrawXModelSkinnedUncached(GfxCmdBufContext context, XSurface *xsurf, GfxPackedVertex *skinnedVert, int baseIndex, int triCount, int vertexCount);
void __cdecl R_DrawXModelSkinnedModelSurf(GfxCmdBufContext context, const GfxModelSkinnedSurface *modelSurf);
unsigned int __cdecl R_TessXModelSkinnedDrawSurfList(const GfxDrawSurfListArgs *listArgs);
unsigned int R_TessXModelRigidDrawSurfList(const GfxDrawSurfListArgs *listArgs);
unsigned int R_TessXModelRigidSkinnedDrawSurfList(const GfxDrawSurfListArgs *listArgs);
unsigned int R_TessStaticModelRigidList(const GfxDrawSurfListArgs *listArgs);
unsigned int R_TessStaticModelSkinnedDrawSurfList(const GfxDrawSurfListArgs *listArgs);
unsigned int R_TessTrianglesList(const GfxDrawSurfListArgs *listArgs);
void R_SetBModelPlacement(GfxCmdBufContext context, const GfxSurface *surface, const GfxScaledPlacement *remotePlacement);
unsigned int R_TessBModel(const GfxDrawSurfListArgs *listArgs);

//t6/code/src_noserver/gfx_d3d/r_add_bsp.cpp
unsigned int R_GetVisLightsMask(const GfxSurface *surface, const vec4_t *dynamicSpotLightPlanes, const GfxLight *visibleLights, int visibleLightCount);
void R_InitBspDrawSurfRegions(BspSurfRegions *regions, BspSurfRegionSetupInfo *setupInfo, int setupInfoCount, const GfxViewParms *viewParms);
void R_AddAllBspDrawSurfacesRangeCamera(unsigned int beginSurface, unsigned int endSurface, BspSurfRegions *bspSurfRegions, LocalClientNum_t localClientNum, const GfxLight *visibleLights, int visibleLightCount, TestForSunShadowList sunShadowListTest);
void R_AddAllBspDrawSurfacesCameraNonlit(unsigned int beginSurface, unsigned int endSurface, unsigned int stage, unsigned int maxDrawSurfCount, const GfxViewParms *viewParms);
void R_AddAllBspDrawSurfacesCamera(char *a1, LocalClientNum_t localClientNum, int addAllList, const GfxLight *visibleLights, int visibleLightCount, bool hasSunShadowVisData, const GfxViewParms *viewParms);
void R_SortAllBspSurfacesCamera(int addAllList);
void R_AddAllBspDrawSurfacesRangeSunShadow(GfxBspDrawSurfData *surfData, unsigned int partitionIndex, unsigned int beginSurface, unsigned int endSurface);
void R_SortAllBspSurfacesSunShadow();
void R_InitBspDrawSurfSunShadow(GfxBspDrawSurfData *surfData, unsigned int partitionIndex, unsigned int maxDrawSurfCount, const GfxViewParms *shadowViewParms);
void R_AddAllBspDrawSurfacesSunShadow(unsigned int a1, GfxBspDrawSurfData *a2, LocalClientNum_t localClientNum, const GfxSunShadow *sunShadow);
void R_AddAllBspDrawSurfacesSpotShadow(unsigned int spotShadowIndex, unsigned int primaryLightIndex, const GfxViewParms *shadowViewParms);

//#include "gfx_d3d/r_add_bsp.h"

//#include "gfx_d3d/r_add_cmdbuf.h"

//t6/code/src_noserver/gfx_d3d/r_add_staticmodel.cpp
void R_SkinStaticModelsShadowForLod(const XModel *model, unsigned __int16 *list, unsigned int count, unsigned int surfType, unsigned int lod, GfxSModelDrawSurfData *surfData);
void R_SkinStaticModelsShadow(const XModel *model, unsigned __int16 (*staticModelLodList)[4][128], unsigned __int16 (*staticModelLodCount)[4], GfxSModelDrawSurfData *surfData);
void R_ShowCountsStaticModel(int smodelIndex, int lod);
GfxStaticModelId R_GetStaticModelId(int smodelIndex, int lod);
void R_StaticModelWriteInfoHeader(int fileHandle);
void R_StaticModelWriteInfo(int fileHandle, const GfxStaticModelDrawInst *smodelDrawInst, const float dist);
void R_DumpStaticModelLodInfo(const GfxStaticModelDrawInst *smodelDrawInst, const float dist);
unsigned int R_GetSModelDLightMask(const GfxStaticModelInst *smodelInst, const vec4_t *dynamicSpotLightPlanes, const GfxLight *visibleLights, int visibleLightCount);
void R_SetupSModelDrawSurfLightingDataForCamera(GfxSModelDrawSurfLightingData *surfData, const GfxViewParms *viewParms);
void R_StaticModelDebugAids(unsigned int smodelIndex, const XModel *localModel, const GfxStaticModelDrawInst *smodelDrawInst, int lod, float lodDist, float lodScale, const vec3_t *eyePos);
void R_SortAllStaticModelSurfacesCamera();
void R_AddAllStaticModelSurfacesRangeSunShadow(int viewIndex, unsigned int partitionIndex, unsigned int maxDrawSurfCount, const GfxViewParms *shadowViewParms);
void R_SortAllStaticModelSurfacesSunShadow();
void R_AddAllStaticModelSurfacesSunShadow(unsigned int a1, int viewIndex);
void R_AddAllStaticModelSurfacesSpotShadow(int viewIndex, unsigned int spotShadowIndex, unsigned int primaryLightIndex, const GfxViewParms *shadowViewParms);
void R_FixupSmodelCullOutDists();
void R_FixupSmodelCullOutDists(const XModel *model, const vec3_t *origin, float newCullDist);
void R_StaticModelCameraDistSort(unsigned __int16 *list, float *dists, unsigned int count);
void R_SkinStaticModelsCameraForLod(const XModel *model, unsigned int primaryLightIndex, unsigned __int16 *list, float *dists, unsigned int count, unsigned int surfType, unsigned int lod, GfxSModelDrawSurfLightingData *surfData, unsigned int visLightsMask);
void R_SkinStaticModelsCamera(const XModel *model, unsigned int primaryLightIndex, unsigned __int16 (*staticModelLodList)[4][128], float (*staticModelLodDists)[4][128], unsigned __int16 (*staticModelLodCount)[4], GfxSModelDrawSurfLightingData *surfData, unsigned int visLightsMask);
void R_AddStaticModelSurfacesCamera(int viewIndex, int viewInfoIndex, int teleported, const GfxLight *visibleLights, int visibleLightCount, int noLodCullOut, GfxSModelDrawSurfLightingData *surfData, TestForSunShadowList sunShadowTest);
void R_AddAllStaticModelSurfacesCamera(int viewIndex, int viewInfoIndex, int teleported, const GfxLight *visibleLights, int visibleLightCount, int noLodCullOut, bool hasSunShadowVisData);

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
const DiskTriangleSoup *R_UpdateDiskSurfaces_Version12(const DiskTriangleSoup_Version12 *oldSurfs, int surfCount);
const DiskTriangleSoup *R_UpdateDiskSurfaces_Version8(const DiskTriangleSoup_Version8 *oldSurfs, int surfCount);
void R_LoadTriangleSurfaces(unsigned int bspVersion, const DiskTriangleSoup **diskSurfaces, unsigned int *surfCount);
int R_DetermineLightmapCoupling(GfxBspLoad *load, long double (*coupling)[30], LumpType lumpType);
int R_BuildLightmapMergability(GfxBspLoad *load, r_lightmapGroup_t *groupInfo, int *reorder, LumpType lumpType);
void R_LoadLightmaps(GfxBspLoad *load);
void R_AssertLightGridValid(const GfxLightGrid *lightGrid);
void R_LoadLightGridHeader(char *a1, LumpType a2);
void R_LoadLightGridColors(unsigned int bspVersion);
GfxLightGridEntry *R_LoadLightGridEntries(char *a1, LumpType a2);
void R_LoadReflectionProbes(char *a1, LumpType a2);
int R_HeroLightSorter(const void *a, const void *b);
void R_BuildHeroLightTree(unsigned int nodeIndex, unsigned int firstLight, unsigned int lightCount, vec3_t *mins, vec3_t *maxs);
void R_LoadHeroOnlyLights(LumpType a1, char *a2, const char *a3, unsigned int bspVersion);
GfxLightCorona *R_LoadCoronas(char *a1, LumpType a2);
unsigned __int8 *R_LoadOccluders(char *a1, LumpType a2);
unsigned __int8 *R_LoadShadowMapVolumes(char *a1, LumpType a2);
unsigned __int8 *R_LoadExposureVolumes(char *a1, LumpType a2);
void R_LoadWorldFogVolumes(char *a1, LumpType a2);
void R_LoadWorldFogModifierVolumes(char *a1, LumpType a2);
void R_LoadLutVolumes(char *a1, LumpType a2);
void R_CalculateSurfaceBounds(GfxSurface *surface, const DiskGfxVertex *vertsDisk, int vertCount);
void R_MergeSurfaceLightMapCoords(const Material *material, GfxSurface *surface, const DiskGfxVertex *vertsDisk, const r_lightmapMerge_t *merge, GfxWorldVertex *vertsMem, int vertCount);
void R_CalculateOutdoorBounds(GfxBspLoad *load, const DiskTriangleSoup *diskSurfaces);
bool R_CompareSurfaces(const GfxSurface *surf0, const GfxSurface *surf1);
BOOL R_SortSurfacesOnAxis_PosX(const GfxSurface *surf0, const GfxSurface *surf1);
BOOL R_SortSurfacesOnAxis_NegX(const GfxSurface *surf0, const GfxSurface *surf1);
BOOL R_SortSurfacesOnAxis_PosY(const GfxSurface *surf0, const GfxSurface *surf1);
BOOL R_SortSurfacesOnAxis_NegY(const GfxSurface *surf0, const GfxSurface *surf1);
void R_PackPosition(const vec3_t dataDisk, vec3_t *dataMem);
void R_PackWorldVertex0(const GfxSurface *surface, unsigned __int8 *out, const GfxWorldVertex *worldVert);
void R_PackWorldVertex1(const GfxSurface *surface, unsigned __int8 *out, const GfxWorldVertex *worldVert, const unsigned __int8 *vertLayerData);
void R_ValidateSurfaceLightmapUsage(const GfxSurface *surface);
void R_CalculateTriangleGroupTexCoordExtents(GfxSurface *surface, GfxWorldVertex *vertsMem, unsigned __int8 *layerVertsMem, unsigned int vertLayerDataStride, unsigned int extraTexCoordCount, unsigned __int8 *triUsed, unsigned __int8 *vertUsed, int startTriIndex, vec3_t *mins, vec3_t *maxs);
void R_LoadSubmodels(char *a1, LumpType a2);
float R_FloatForKey(const char *key, float defaultValue, char *(*spawnVars)[2], int spawnVarCount);
int R_IntForKey(const char *key, int defaultValue, char *(*spawnVars)[2], int spawnVarCount);
bool R_VectorForKey(const char *key, const char *defaultString, char *(*spawnVars)[2], int spawnVarCount, vec3_t *v);
void R_LoadStaticModelData(LumpType a1, char *a2, int bspVersion);
void R_LoadSkyGridVolumes(LumpType a1, char *a2, int bspVersion);
void R_PrefixStaticModelName(char *prefixedName, unsigned int prefixedNameSize, const char *name, unsigned int smid);
bool R_CheckValidStaticModel(char *(*spawnVars)[2], int spawnVarCount, XModel **model, vec3_t *origin);
void R_SetStaticModelsLightmapData();
void R_LoadMiscModel(int a1, char *(*spawnVars)[2], int spawnVarCount);
char *R_ParseSunLight(SunLightParseParams *params, const char *text);
void R_LoadPrimaryLights(unsigned int bspVersion);
void R_LoadLightRegions();
unsigned int R_GetStaticModelSortIndex(const XModel *model);
bool R_StaticModelCompare(const GfxStaticModelCombinedInst *smodelInst0, const GfxStaticModelCombinedInst *smodelInst1);
int R_AabbTreeChildrenCount_r(GfxAabbTree *tree);
void R_AabbTreeFixAABBSizes_r(GfxAabbTree *tree);
GfxAabbTree *R_AabbTreeMove_r(GfxAabbTree *tree, GfxAabbTree *newTree, GfxAabbTree *newChildren);
void R_FixupGfxAabbTrees(GfxCell *cell);
BOOL R_SortStaticModelsOnAxis_NegX(const GfxStaticModelCombinedInst *smodelCombinedInst0, const GfxStaticModelCombinedInst *smodelCombinedInst1);
BOOL R_SortStaticModelsOnAxis_PosY(const GfxStaticModelCombinedInst *smodelCombinedInst0, const GfxStaticModelCombinedInst *smodelCombinedInst1);
BOOL R_SortStaticModelsOnAxis_NegY(const GfxStaticModelCombinedInst *smodelCombinedInst0, const GfxStaticModelCombinedInst *smodelCombinedInst1);
bool R_CompareStaticModelSortModels(const GfxStaticModelSortModel *sortModel0, const GfxStaticModelSortModel *sortModel1);
void R_LoadEntities(char *a1, LumpType a2);
int R_FinishLoadingAabbTrees_r(GfxAabbTree *tree, int totalTreesUsed);
unsigned int R_LoadAabbTrees(LumpType a1, char *a2, const char *a3);
void R_LoadCells(LumpType a1, char *a2, unsigned int bspVersion);
GfxPortal *R_LoadPortals(char *a1, LumpType a2);
void R_SetParentAndCell_r(mnode_load_t *node);
unsigned int R_CountNodes_r(mnode_load_t *node);
mnode_t *R_SortNodes_r(mnode_load_t *node, mnode_t *out);
void R_LoadNodesAndLeafs(LumpType a1, char *a2, unsigned int bspVersion);
unsigned __int8 *R_AllocPrimaryLightBuffers();
unsigned __int8 *R_LoadWorldRuntime();
void R_SetStaticModelReflectionProbes();
void R_IncrementShadowGeometryCount(GfxWorld *world, unsigned int primaryLightIndex);
void R_SetUpSunLight(const vec3_t *sunColor, const vec3_t *sunDirection, GfxLight *light);
void R_InterpretSunLightParseParamsIntoLights(SunLightParseParams *sunParse, GfxLight *sunLight);
// void R_InitPrimaryLights(const vec3_t *a1, const char *a2@<ebx>, GfxLight *primaryLights);
void R_ForEachPrimaryLightAffectingSurface(GfxWorld *world, const GfxSurface *surface, unsigned int sortedSurfIndex, void (*Callback)(GfxWorld *, unsigned int, unsigned int));
MaterialTechniqueSet *R_GetSurfaceVertexLayerDataStride(const GfxSurface *surface);
void R_GetSurfaceVertexPosition(const GfxSurface *surface, int vertIndex, vec3_t *result);
void R_GetSurfaceVertexLmapCoord(const GfxSurface *surface, int vertIndex, vec2_t *result);
void R_GetSurfaceVertexNormal(const GfxSurface *surface, int vertIndex, vec3_t *result);
void R_RecenterSurfaceTexCoords(GfxSurface *surface, GfxWorldVertex *vertsMem, unsigned __int8 *vertLayerDataMem);
void R_LoadSurfaces(const DiskTriangleSoup **a1, unsigned int a2, char *load, GfxBspLoad *a4);
void R_LoadSunSettings(char *a1);
void R_ForEachShadowCastingSurfaceOnEachLight(void (*Callback)(GfxWorld *, unsigned int, unsigned int));
void R_AddShadowSurfaceToPrimaryLight(GfxWorld *world, unsigned int primaryLightIndex, unsigned int sortedSurfIndex);
void R_InitShadowGeometryArrays();
void R_SpatialSortSurfaceSubArray_r(GfxSurface *beginSurf, GfxSurface *endSurf, unsigned int predIndex);
void R_SpatialSortAllSurfaces(int surfaceCount);
void R_SortSurfaces(char *a1);
void R_SpatialSortStaticModelSubArray_r(GfxStaticModelCombinedInst *smodelCombinedInsts, unsigned int begin, unsigned int end, unsigned int predIndex);
void R_SpatialSortAllStaticModels(GfxStaticModelCombinedInst *smodelCombinedInsts);
void R_InitSortStaticModelsByModel();
void R_PostLoadEntities();
GfxWorld *R_LoadWorldInternal(const char *a1, const char *name);

//t6/code/src_noserver/gfx_d3d/r_buffers.cpp
void TRACK_r_buffers();
char *R_LockVertexBuffer(ID3D11DeviceContext *device, ID3D11Buffer *handle, int offset, int bytes, int lockFlags);
void R_UnlockVertexBuffer(ID3D11DeviceContext *device, ID3D11Buffer *handle);
char *R_LockIndexBuffer(ID3D11DeviceContext *device, ID3D11Buffer *handle, int offset, int bytes, int lockFlags);
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
bool R_Cinematic_GetPathFromFilename(CinematicInfo *info, const char *filename, const char *ext, unsigned int playbackFlags);
void R_Cinematic_StartSound(CinematicInfo *info, bool startPaused);
void *R_Cinematic_OpenMovie_Now(CinematicInfo *cinematicInfo, const char *filename, unsigned int playbackFlags, bool isNextBink);
void __cdecl StreamThread_OpenMovie(int msAllotted, void *user);
void R_Cinematic_QueueStreamOpen(bool isNextBink, bool isNeededImmediately);
void R_Cinematic_PopFromQueue();
void R_Cinematic_RemoveInactiveFromQueue(int a1);
void StreamThread_GetMoviePath(int msAllotted, void *user, int id);
void R_Cinematic_StartPlayback_Internal(const char *name, unsigned int playbackFlags, float volume, CIN_CALLBACK_INFO *callbackInfo, int id);
int R_Cinematic_GetPlayingId();
int R_Cinematic_StartPlayback(const char *name, unsigned int playbackFlags, float volume, CIN_CALLBACK_INFO *callbackInfo, int reservedId);
char R_Cinematic_StopPlayback(int id, bool cancelAll);
void R_Cinematic_HandleFinishedCallbacks(CIN_CALLBACK_TYPE type);
char R_Cinematic_UpdateSoundTime();
void R_Cinematic_UpdateFrame(int a1, bool force_wait);
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
// void __cdecl BinkMoviePlayer::InitMemory(void *mainMemory, unsigned int mainBytes, void *textureMemory, unsigned int textureBytes, unsigned int playbackFlags);
// void BinkMoviePlayer::Destroy(CinematicHunk *notthis);
// void BinkMoviePlayer::R_Cinematic_ReleaseImages(CinematicTextureSet *textureSet);
// int BinkMoviePlayer::MakeBinkTexturePC(unsigned int width, unsigned int height, int sysMem, DXGI_FORMAT format, unsigned int pixel_size, ID3D11Texture2D **out_texture, void **out_ptr, unsigned int *out_pitch, unsigned int *out_size);
// HRESULT BinkMoviePlayer::R_Cinematic_MakeBinkDrawTextures(unsigned int a1, unsigned int *a2);
// HRESULT BinkMoviePlayer::R_Cinematic_InitBinkTextures(unsigned int *a1);
// void BinkMoviePlayer::R_Cinematic_Unlock_textures();
// void BinkMoviePlayer::R_Cinematic_SetRendererImagesToFrame(int frameToSetTo);
// double BinkMoviePlayer::GetTimeElapsed();
// void BinkMoviePlayer::SetMovieClock(void *handle, float time);
// void BinkMoviePlayer::SetVolume(void *handle, float volume);
// int BinkMoviePlayer::GetBufferFillPercentage(void *handle);
// bool BinkMoviePlayer::IsUnderrun(void *notthis);
// int BinkMoviePlayer::R_Cinematic_BinkWaitAsyncDecode(BINK *bink, int waitMs);
// bool BinkMoviePlayer::IsReadyToStart(void *notthis);
// void BinkMoviePlayer::StreamThread_DoBackgroundIO_Bink(int msAllotted, void *user, int id);
// void BinkMoviePlayer::StartPlayback(void *handle, unsigned int playbackFlags);
// const char *BinkMoviePlayer::AdvanceFrame();
// void BinkMoviePlayer::R_Cinematic_Lock_textures(D3D11_MAPPED_SUBRESOURCE *p_m, int a2, int a3);
// void BinkMoviePlayer::R_Cinematic_BinkLaunchAsyncDecode;
// void BinkMoviePlayer::DoFrameSync;
// void BinkMoviePlayer::UpdateMoviesAndImages(D3D11_MAPPED_SUBRESOURCE *a1, int a2, bool forceWait);
// char BinkMoviePlayer::ForceRelinquishIO();
// void *BinkMoviePlayer::Bink_Alloc_Alt(unsigned int bytes);
// void BinkMoviePlayer::Bink_Free(void *ptr);
// void BinkMoviePlayer::Bink_Free_Alt(void *ptr);
// void BinkMoviePlayer::PreOpen_Common(bool isNextBink);
// void BinkMoviePlayer::PostOpen_Common(BINK *pbink, unsigned int playbackFlags, bool isNextBink);
// const char *__cdecl BinkMoviePlayer::GetLastError();
// BINK *BinkMoviePlayer::OpenFromFastfile(char *a1, const char *assetname, unsigned int playbackFlags);
// BINK *BinkMoviePlayer::OpenPath(char *a1, const char *filepath, unsigned int playbackFlags);
// void BinkMoviePlayer::StopPlayback(void *handle);
MoviePlayerFunctions *R_Cinematic_GetBinkFunctions();
int launch_async_bink_drawCallback(D3D11_MAPPED_SUBRESOURCE *a1, jqBatch *batch);

//t6/code/src_noserver/gfx_d3d/r_cmdbuf.cpp
void R_ShutdownCmdBuf(GfxCmdBuf *cmdBuf);
void R_InitContext(const GfxBackEndData *data, GfxCmdBuf *cmdBuf);

//t6/code/src_noserver/gfx_d3d/r_compile_shader.cpp
void Material_EmitShaderString(GfxAssembledShaderText *prog, const char *string);
void Material_AddShaderFile(GfxAssembledShaderText *prog, const char *shaderFileName, unsigned int srcLine);
char Material_FindCachedShaderText(const char *filename, const char **data, unsigned int *byteCount);
void Material_FileIncludeFileAndLineNumber(GfxAssembledShaderText *prog, const char *errorMessage, const char **fileName, unsigned int *lineNumber);
bool Material_PreLoadSingleShaderText(const char *filename, const char *subdir, GfxCachedShaderText *cached);
bool Material_CachedShaderTextLess(const GfxCachedShaderText *cached0, const GfxCachedShaderText *cached1);
bool Material_IncludeShader(GfxAssembledShaderText *prog, const char *includeName, bool isInLibDir);
bool Material_GenerateShaderString_r(GfxAssembledShaderText *prog, const char *shaderName, const char *file);
unsigned int Material_GenerateShaderString(GfxAssembledShaderText *prog, const char *shaderName, const char *shaderType, char *shaderString, int sizeofShaderString);
ID3D10Blob *Material_CompileShader(const char *shaderName, const char *shaderType, const char *entryPoint, const char *target, ShaderStats *stats, unsigned int *shaderChecksum);

//t6/code/src_noserver/gfx_d3d/r_debug.cpp
void TRACK_r_debug();
void R_AddDebugPolygonInternal(PolySet *polySet, int pointCount, const vec3_t *points, const vec4_t *faceColor, bool faceDepthTest, const vec4_t *edgeColor, bool edgeDepthTest);
void __cdecl R_AddDebugPolygon(DebugGlobals *debugGlobalsEntry, int pointCount, const vec3_t *points, const vec4_t *faceColor, int faceDepthTest, const vec4_t *edgeColor, bool edgeDepthTest);
void __cdecl R_AddPersistentDebugPolygon(DebugGlobals *debugGlobalsEntry, int pointCount, const vec3_t *points, const vec4_t *faceColor, int faceDepthTest, const vec4_t *edgeColor, bool edgeDepthTest);
void R_ClearPersistentDebugPolygons();
void R_AddDebugLine(DebugGlobals *debugGlobalsEntry, const vec3_t *start, const vec3_t *end, const vec4_t *color, int doDepthTest);
void R_AddDebugBox(DebugGlobals *debugGlobalsEntry, const vec3_t *mins, const vec3_t *maxs, const vec4_t *color);
void R_AddDebugFrustum(int a1, const GfxViewParms *viewParms);
void R_AddDebugString(DebugGlobals *debugGlobalsEntry, const vec3_t *origin, const vec4_t *color, float scale, const char *string);
void R_AddScaledDebugString(DebugGlobals *debugGlobalsEntry, const GfxViewParms *viewParms, const vec3_t *origin, const vec4_t *color, const char *string);
void R_InitDebugEntry(DebugGlobals *debugGlobalsEntry);
void R_ShutdownDebugEntry(DebugGlobals *debugGlobalsEntry);
void R_UpdatePersistentDebugPolys(DebugGlobals *debugGlobalsEntry);
void R_TransferDebugGlobals(DebugGlobals *debugGlobalsEntry);
void R_ShutdownDebug();
void R_CopyDebugStrings(trDebugString_t *clStrings, int clStringCnt, trDebugString_t *svStrings, int svStringCnt, int maxStringCount);
void R_CopyDebugLines(trDebugLine_t *clLines, int clLineCnt, trDebugLine_t *svLines, int svLineCnt, int maxLineCount);
void R_CopyDebugSpheres(trDebugSphere_t *clSpheres, int clSphereCnt, trDebugSphere_t *svSpheres, int svSphereCnt, int maxSphereCount);
void R_AddDebugAxis(DebugGlobals *debugGlobalsEntry, const vec3_t *origin, const vec3_t *axis, float length, int doDepthTest);
void R_AddDebugPolygonOutline(DebugGlobals *debugGlobalsEntry, int pointCount, const vec3_t *points, const vec4_t *color, int doDepthTest);

//t6/code/src_noserver/gfx_d3d/r_debug_alloc.cpp
void R_DebugAlloc(void **memPtr, int size, const char *name);
void R_DebugFree(void **dataPtr);

//t6/code/src_noserver/gfx_d3d/r_dobj_skin.cpp
int R_PreSkinXSurface(const GfxModelSurfaceInfo *surfaceInfo, unsigned __int8 *surfPos);
unsigned int R_GetSkinSurfaceBufferSize(GfxSceneEntity *sceneEnt, const DObj *obj);
void R_GetPartBitsForSurfaceAndBoneIndex(XSurface *xsurf, unsigned int boneIndex, int *partBits);
unsigned int R_SkinSceneDObjModels(GfxSceneEntity *sceneEnt, const DObj *obj);
void R_FlagXModelAsSkinned(GfxSceneEntity *sceneEnt, unsigned int surfaceCount);
void R_SkinSceneDObj(GfxSceneEntity *sceneEnt, GfxSceneEntity *localSceneEnt, const DObj *obj, DObjAnimMat *boneMatrix, int waitForCullState);
void R_SkinGfxEntityCmd(void *data);

//t6/code/src_noserver/gfx_d3d/r_dpvs.cpp
// int DpvsCachedCell::Compare(const void *lhs, const void *rhs);
void TRACK_r_dpvs();
void R_GetSidePlaneNormals(const vec3_t *winding, unsigned int vertexCount, vec3_t *normals);
float R_FurthestPointOnWinding(const vec3_t *points, int pointCount, const DpvsPlane *plane);
float R_NearestPointOnWinding(const vec3_t *points, int pointCount, const DpvsPlane *plane);
void R_FrustumClipPlanes(const GfxMatrix *viewProjMtx, const vec4_t *sidePlanes, int sidePlaneCount, DpvsPlane *frustumPlanes);
char *R_PortalAssertMsg();
void R_ProjectPortal(int vertexCount, const vec3_t *winding, vec2_t *mins, vec2_t *maxs, DpvsClipChildren *clipChildren);
void R_UnprojectPoint(GfxViewParms *viewParms, const vec2_t *projected, vec4_t *unprojected);
unsigned int R_AddBevelPlanes(DpvsPlane *planes, unsigned int vertexCount, const vec3_t *windingNormals, const vec2_t *mins, const vec2_t *maxs, DpvsForceBevels forceBevels);
unsigned int R_PortalClipPlanes(DpvsPlane *planes, unsigned int vertexCount, const vec3_t *winding, DpvsClipChildren *clipChildren);
unsigned int R_PortalClipPlanesNoFrustum(DpvsPlane *planes, unsigned int vertexCount, const vec3_t *winding);
bool R_PortalBehindAnyPlane(const GfxPortal *portal, const DpvsPlane *planes, int planeCount);
const vec3_t *R_ChopPortalWinding(const vec3_t *vertsIn, int *vertexCount, const DpvsPlane *plane, vec3_t *vertsOut);
unsigned int R_GetLightingMask_Box(const GfxLight *visibleLights, int visibleLightCount, const vec4_t *dynamicSpotLightPlanes, const vec3_t *mins, const vec3_t *maxs);
unsigned int R_GetLightingMask_Sphere(const GfxLight *visibleLights, int visibleLightCount, const vec4_t *dynamicSpotLightPlanes, const vec3_t *origin, float baseRadius);
void R_AddSceneEntSurfs_SceneDObjs(AddSceneEntSurfsCmd *cmd);
void R_AddSceneEntSurfs_SceneModels(AddSceneEntSurfsCmd *cmd);
void R_AddSceneEntSurfs_SceneDynEnts(AddSceneEntSurfsCmd *cmd);
void R_AddSceneEntSurfs_SceneBrush(AddSceneEntSurfsCmd *cmd);
void R_AddSceneEntSurfs_SceneGlassBrush(AddSceneEntSurfsCmd *cmd);
void R_AddSceneEntSurfs_SceneDynBrush(AddSceneEntSurfsCmd *cmd);
void R_InitSceneEntDrawSurfs(GfxDrawSurf **drawSurfs, unsigned int drawSurfsByteSize, GfxDrawSurf **lastDrawSurfs, unsigned int lastDrawSurfsByteSize);
void R_FinishSceneEntDrawSurfs(GfxDrawSurf **drawSurfs);
void R_AddAllSceneEntSurfacesCamera(const GfxViewInfo *viewInfo, GfxDrawSurf **drawSurfs, GfxDrawSurf **lastDrawSurfs);
void R_AddAllSceneEntSurfacesRangeSunShadow(unsigned int partitionIndex);
void R_AddAllSceneEntSurfacesSunShadow();
void R_AddAllSceneEntSurfacesSpotShadow(const GfxViewInfo *viewInfo, unsigned int spotShadowIndex, unsigned int primaryLightIndex);
int R_DrawBModel(BModelDrawInfo *bmodelInfo, const GfxBrushModel *bmodel, const GfxPlacement *placement, const ShaderConstantSet *constSet);
void R_CullDynBrushInCell(unsigned int cellIndex, const DpvsPlane *planes, int planeCount);
void R_DrawAllSceneEnt(const GfxViewInfo *viewInfo);
void R_DrawAllDynEnt(const GfxViewInfo *viewInfo);
void R_FilterEntIntoCells_r(float entInfo, const cplane_s *a2, float node, FilterEntInfo *a4, mnode_t *mins, const vec3_t *maxs, const vec3_t *a7);
void R_FilterDynEntIntoCells_r(float node, const cplane_s *a2, float dynEntIndex, mnode_t *a4, unsigned int drawType, DynEntityDrawType mins, const vec3_t *maxs, const vec3_t *a8);
void R_UnfilterEntFromCells(LocalClientNum_t localClientNum, unsigned int entnum);
void R_UnfilterDynEntFromCells(unsigned int dynEntId, DynEntityDrawType drawType);
void R_FilterDObjIntoCells(float localClientNum, LocalClientNum_t a2, unsigned int entnum, vec3_t *origin, float radius);
void R_FilterBModelIntoCells(float localClientNum, LocalClientNum_t a2, unsigned int entnum, GfxBrushModel *bmodel);
void R_FilterDynEntIntoCells(float dynEntId, unsigned int a2, DynEntityDrawType drawType, vec3_t *mins, vec3_t *maxs);
int R_DpvsBoxIsVisible(const vec3_t *mins, const vec3_t *maxs, LocalClientNum_t localClientNum, unsigned int view);
void R_FilterXModelIntoScene(const XModel *model, const GfxScaledPlacement *placement, unsigned int renderFxFlags, unsigned __int16 *cachedLightingHandle, float lightToleranceSq);
void R_InitialEntityCulling();
void R_GetStaticModelsAabb(const GfxAabbTree *tree, const vec3_t *mins, const vec3_t *maxs, int *models, int *models_count, int max_models);
void R_GetStaticModels(const vec3_t *mins, const vec3_t *maxs, int *models, int *models_count, int max_models);
void R_AddCellDynBrushSurfacesInFrustumCmd(void *data);
void R_FinishDpvsDynamicBatch(DpvsDynamicCellCmd *dpvsDynamicBatch, bool bRunCmd);
void R_AddDpvsDynamicBatch(DpvsDynamicCellCmd *dpvsDynamicBatch, int cellIndex, const DpvsPlane *planes, int planeCount, int frustumPlaneCount);
void R_AddCellSurfacesInFrustumDelayed(const GfxCell *cell, const DpvsPlane *planes, int planeCount, int frustumPlaneCount, DpvsDynamicCellCmd *dpvsDynamicBatch);
void R_CacheCell(int cellIndex, int planeIndex, int planeCount, int frustumPlaneCount);
void R_AddCellSurfaces(int cellIndex, const DpvsPlane *planes, int planeCount, int frustumPlaneCount, DpvsDynamicCellCmd *dpvsDynamicBatch);
void R_AssertValidQueue();
void R_EnqueuePortal(const vec3_t *a1, const DpvsPlane *a2, float dist, GfxPortal *portal);
GfxPortal *R_NextQueuedPortal();
void R_AddVertToPortalHullPoints(GfxPortal *portal, const vec3_t *v);
int R_ChopPortal(const GfxPortal *portal, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, vec3_t (*v)[128], const vec3_t **finalVerts);
bool R_ChopPortalAndAddHullPoints(GfxPortal *portal, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount);
bool R_ChopPortalAndAddHullPointsNoFrustum(GfxPortal *portal, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount);
int __cdecl R_GetFurtherCellList_r(const GfxCell *cell, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, vec3_t (*v)[128], const GfxCell **list, int count);
void R_SetCellVisible(unsigned int cellIndex);
void R_VisitAllFurtherCells(const GfxCell *cell, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, int frustumPlaneCount, DpvsDynamicCellCmd *dpvsDynamicBatch);
void R_SetAncestorListStatus(GfxPortal *portal, bool isAncestor);
int R_VisitPortalsForCell(const GfxCell *cell, GfxPortal *parentPortal, const DpvsPlane *parentPlane, DpvsPlane *planes, unsigned int maxPlaneCount, unsigned int planeCount, int frustumPlaneCount, unsigned int recursionDepth, DpvsClipChildren clipChildren, DpvsDynamicCellCmd *dpvsDynamicBatch);
void R_VisitPortals(const GfxCell *cell, const DpvsPlane *parentPlane, DpvsPlane *planes, int planeCount, DpvsDynamicCellCmd *dpvsDynamicBatch);
void R_VisitPortalsForCellNoFrustum(const GfxCell *cell, GfxPortal *parentPortal, const DpvsPlane *parentPlane, const DpvsPlane *planes, int planeCount, unsigned int recursionDepth);
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
void R_SetupShadowSurfacesDpvs(const GfxViewParms *viewParms, const vec4_t *sidePlanes, unsigned int sidePlaneCount, int partitionIndex);
double R_GetFarPlaneDist();
void R_SetCullDist(float dist);
int R_CullBoxCurDpvs_SceneSelect(const vec3_t *mins, const vec3_t *maxs, unsigned int viewIndex, unsigned int sceneIndex);
int R_CullBoxCurDpvs(const vec3_t *mins, const vec3_t *maxs, unsigned int viewIndex);
int R_CullPoint(LocalClientNum_t localClient, const vec3_t *p0, float cutoff);
int R_CullPoint(int max_local_clients, const vec3_t *point, float cutoff);
int R_CullLine(int localClient, const vec3_t *p0, const vec3_t *p1, float cutoff);
unsigned int R_ExtraCam_SaveDpvsData(LocalClientNum_t localClientNum, unsigned __int8 *buffer, unsigned int bufferByteSize);
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
void R_CullDynModelInCell(const unsigned int *dynEntCellBits, unsigned int dynEntClientWordCount, DynEntityPose *dynModelList, const DpvsPlane *planes, int planeCount, unsigned __int8 *dynEntVisData);
void R_AddCellDynModelSurfacesInFrustumCmd(void *data);

//t6/code/src_noserver/gfx_d3d/r_dpvs_entity.cpp
void R_AddEntitySurfacesInFrustum(GfxSceneEntity *sceneEnt, const DpvsPlane *planes, int planeCount, unsigned __int8 *entVisData);
void R_ForceAddEntitySurfacesInFrustum(GfxSceneEntity *sceneEnt, unsigned __int8 *entVisData);

//t6/code/src_noserver/gfx_d3d/r_dpvs_sceneent.cpp
void R_AddCellSceneEntSurfacesInFrustum(unsigned int localClientNum, unsigned int cellIndex, const DpvsPlane *planes, int planeCount, int frustumPlaneCount, unsigned int viewIndex);
void R_AddCellSceneEntSurfacesInFrustumCmd(void *data);

//t6/code/src_noserver/gfx_d3d/r_dpvs_static.cpp
int R_CullBoxLeaf(const vec3_t *mins, const vec3_t *maxs, DpvsClipPlanes *planes);
char TestOccluders(const vec3_t *bounds, int numOccluders, vec4_t *plane);
vec4_t *TestOccludersPartial(const vec3_t *bounds, int *numOccludersPtr, vec4_t *plane);
int R_AddAabbTreeSurfacesInFrustum_r(int a1, DpvsClipPlanes *a2, DpvsClipPlanes *tree, const GfxAabbTree *planes, const DpvsClipPlanes *treeDepth, int numOccluders, int occluderPlanes, vec4_t *a8);
int R_AddCellStaticSurfacesInFrustum(const DpvsPlanes *planes);
void R_AddCellStaticSurfacesInFrustumCmd(void *data);

//t6/code/src_noserver/gfx_d3d/r_drawsurf.cpp
GfxWorld *R_SetPrimaryLightShadowSurfaces();
int R_GetWorldDrawSurf(GfxSurface *worldSurf);
void R_SortWorldSurfaces();
GfxDrawSurf *R_AllocFxDrawSurf(unsigned int region);
unsigned int R_GetDrawSurfRegionForSortKey(const Material *material, unsigned int baseRegion);
void R_AddCodeMeshDrawSurf(float material, Material *a2, r_double_index_t *indices, unsigned int indexCount, unsigned int argOffset, unsigned int argCount, const char *fxName, unsigned int region, bool enableDepthHack);
void R_AddCodeMeshDrawSurf_UseIndices(float material, Material *a2, r_double_index_t *indices, unsigned int indexCount, unsigned int argOffset, unsigned int argCount, const char *fxName, unsigned int region, bool enableDepthHack, bool superflare);
void R_AddRopeCodeMeshDrawSurf(float material, const Material *a2, r_double_index_t *indices, unsigned int indexCount, unsigned int argOffset, unsigned int argCount, unsigned int primaryLightIndex, unsigned int reflectionProbeIndex, unsigned int drawsurfRegion);
FxCodeMeshData *R_AddGlassDrawSurf(float material, Material *a2, unsigned __int16 *indices, unsigned int indexCount, GfxDrawSurf **retDrawSurf);
void R_AddMarkMeshDrawSurf(float refLitTechType, Material *material, const GfxMarkContext *context, unsigned __int16 *indices, unsigned int indexCount, unsigned int visLightsMask);
char R_AddParticleCloudDrawSurf(float cloudIndex, unsigned int a2, Material *material);
void R_BeginCodeMeshVerts();
void R_EndCodeMeshVerts();
void R_BeginMarkMeshVerts();
void R_EndMarkMeshVerts();
char R_ReserveCodeMeshIndices(float indexCount, int a2, r_double_index_t **indicesOut);
char R_ReserveCodeMeshVerts(float vertCount, int a2, unsigned __int16 *baseVertex);
char R_ReserveCodeMeshArgs(float argCount, int a2, unsigned int *argOffsetOut);
char R_ReserveMarkMeshIndices(float indexCount, int a2, r_double_index_t **indicesOut);
char R_ReserveMarkMeshVerts(float vertCount, int a2, unsigned __int16 *baseVertex);
vec4_t *R_GetCodeMeshArgs(unsigned int argOffset);
GfxPackedVertex *R_GetCodeMeshVerts(unsigned __int16 baseVertex);
GfxWorldVertex *R_GetMarkMeshVerts(unsigned __int16 baseVertex);
void R_SortDrawSurfs(int a1, GfxDrawSurf *drawSurfList);

//t6/code/src_noserver/gfx_d3d/r_draw_bsp.cpp
void R_SetStreamsForBspSurface(GfxCmdBufPrimState *state, const srfTriangles_t *tris);
void R_DrawTrianglesLit(GfxTrianglesDrawStream *drawStream, GfxCmdBufState *state);
void R_DrawTriangles(GfxTrianglesDrawStream *drawStream, GfxCmdBufState *state);
void R_DrawBspDrawSurfsLit(const unsigned int *primDrawSurfPos, GfxCmdBufContext context);
void R_DrawBspDrawSurfs(const unsigned int *primDrawSurfPos, GfxCmdBufContext context);

//t6/code/src_noserver/gfx_d3d/r_draw_lit.cpp
void R_DrawSonarCallback(const void *__formal, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawSonar(int a1, const GfxViewInfo *viewInfo, GfxCmdBuf *cmdBuf);
void R_DrawLitQuasiOpaqueCallback(const void *__formal, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawLitQuasiOpaque(int a1, const GfxViewInfo *a2, GfxCmdBuf *a3);
void R_DrawTransCallback(const void *userData, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawTransInternal(const GfxViewInfo *viewInfo, GfxCmdBuf *cmdBuf);
void R_DrawTrans(const GfxViewInfo *a1, GfxCmdBuf *a2);
void R_DrawTransPostFX(const GfxViewInfo *a1, GfxCmdBuf *a2);
void RB_SetSonarCodeImages(GfxCmdBufSourceState *source);
void R_AdjustDrawsurfListToCmdBufPartition(GfxDrawSurfListInfo *info, unsigned int partitionIndex, unsigned int partitionCount);
void R_DrawLit(int a1, const GfxViewInfo *viewInfo, GfxCmdBuf *cmdBuf, LitPhaseID phase);
void R_DrawLitBsp(int a1, const GfxViewInfo *viewInfo, GfxCmdBuf *cmdBuf, LitPhaseID phase);
void R_DrawLitStaticModel(int a1, const GfxViewInfo *viewInfo, GfxCmdBuf *cmdBuf, LitPhaseID phase);
void R_DrawViewModelTransCallback(const void *userData, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawViewModelTrans(int a1, const GfxViewInfo *a2, GfxCmdBuf *a3);
void R_PostBlurCallback(const void *userData, GfxCmdBufContext context, const GfxViewInfo *viewInfo);
void R_DrawLitCmd(int a1, char *a2, int a3, DrawLitWorkerCmd *cmd);
void R_DrawLitBspCmd(int a1, char *a2, int a3, DrawLitWorkerCmd *cmd);
void R_DrawLitStaticModelCmd(int a1, char *a2, int a3, DrawLitWorkerCmd *cmd);

//t6/code/src_noserver/gfx_d3d/r_draw_material.cpp
unsigned __int8 RemoveShadowTech(unsigned __int8 srcTech);
int R_SetPrepassMaterial(GfxCmdBufContext context, GfxDrawSurf drawSurf, unsigned __int8 techType);
int R_SetMaterial(GfxCmdBufContext context, GfxDrawSurf drawSurf, const Material **techType);
int R_SetMaterialNoShaderConstantSet(GfxCmdBufContext context, GfxDrawSurf drawSurf, unsigned __int8 techType);
unsigned __int8 R_GetTechType(const GfxCmdBufContext context, const GfxDrawSurfListInfo *info, unsigned __int8 baseTechType, GfxDrawSurf drawSurf);
const char *RB_LogTechniqueType(unsigned __int8 techType);
int R_SetTechnique(float context, const GfxCmdBufContext context_4, const GfxDrawSurfListInfo *info, GfxDrawSurf drawSurf);
int R_SetLitTechniqueNoShaderConstantSet(float context, const GfxCmdBufContext context_4, const GfxDrawSurfListInfo *info, GfxDrawSurf drawSurf);
void R_SetGameTime(GfxCmdBufSourceState *source, float gameTime);
int R_UpdateMaterialTime(GfxCmdBufSourceState *source, float materialTime, float burn);

//t6/code/src_noserver/gfx_d3d/r_draw_method.cpp
void R_SetDefaultLitTechTypes();
void R_InitDrawMethod();
void R_UpdateDrawMethod(GfxBackEndData *data);

//t6/code/src_noserver/gfx_d3d/r_draw_model_util.cpp
void R_SetStreamsForXModelSurface(const XSurface *localSurf, GfxCmdBufState *state);

//t6/code/src_noserver/gfx_d3d/r_draw_shadowablelight.cpp
void R_SetLightProperties(unsigned int a1, float source, GfxCmdBufSourceState *a3, const GfxLight *light, const GfxLightDef *def, LightHasShadowMap hasShadowMap, float spotShadowFade);
void R_SetShadowableLight(const char *a1, GfxCmdBufSourceState *source, unsigned int shadowableLightIndex);

//t6/code/src_noserver/gfx_d3d/r_draw_staticmodel.cpp
void R_SetStaticModelVertexBuffer(GfxCmdBufPrimState *primState, XSurface *xsurf);
void R_SetStaticModelIndexBuffer(GfxCmdBufPrimState *primState, XSurface *xsurf);
void R_DrawStaticModelUnlitNoPrepass(GfxStaticModelDrawStream *drawStream);
void R_DrawStaticModelLitNoPrepass(GfxStaticModelDrawStream *drawStream);
void R_DrawStaticModelLitLightmapVCNoPrepass(GfxStaticModelDrawStream *drawStream);
void R_DrawStaticModelsLit(GfxStaticModelDrawStream *drawStream, GfxCmdBufContext context);
void R_DrawStaticModels(GfxStaticModelDrawStream *drawStream, GfxCmdBufContext context);
void R_DrawStaticModelSurfLit(const unsigned int *primDrawSurfPos, GfxCmdBufContext context, const GfxDrawSurfListInfo *info);
void R_DrawStaticModelDrawSurfPlacement(const GfxStaticModelDrawInst *smodelDrawInst, GfxCmdBufSourceState *source);
void R_DrawStaticModelDrawSurfNonOptimized(GfxStaticModelDrawStream *drawStream, GfxCmdBufContext context);
void R_DrawStaticModelsSkinnedDrawSurfLighting(GfxStaticModelDrawStream *drawStream, GfxCmdBufContext context);
void R_DrawStaticModelsSkinnedDrawSurf(GfxStaticModelDrawStream *drawStream, GfxCmdBufContext context);
void R_DrawStaticModelSkinnedSurfLit(const unsigned int *primDrawSurfPos, GfxCmdBufContext context, const GfxDrawSurfListInfo *info);
void R_DrawStaticModelSkinnedSurf(const unsigned int *primDrawSurfPos, GfxCmdBufContext context, const GfxDrawSurfListInfo *info);
void R_DrawStaticModelSurf(const unsigned int *primDrawSurfPos, GfxCmdBufContext context, const GfxDrawSurfListInfo *info);

//t6/code/src_noserver/gfx_d3d/r_draw_sunshadow.cpp
void R_DrawSunShadowMapCallback(const void *userData, GfxCmdBufContext context);
void R_DrawSunShadowMap(int a1, const GfxViewInfo *viewInfo, unsigned int partitionIndex, GfxCmdBuf *cmdBuf);

//t6/code/src_noserver/gfx_d3d/r_draw_xmodel.cpp
void R_GetWorldMatrixForModelSurf(const GfxModelRigidSurface *modelSurf, const __m128 eyeOffset, vector4 *worldMat, const XSurface *__formal, const GfxModelRigidSurfacePiece *piece);
const GfxModelRigidSurface *R_GetLocalModelSurfaceOnly(const GfxBackEndData *data, GfxDrawSurf drawSurf);
unsigned int R_DrawXModelSurfLitInternal(const XSurface *a1, const GfxModelRigidSurfacePiece *a2, const GfxDrawSurf *drawSurfList, unsigned int drawSurfCount, GfxCmdBufContext context);
GfxCmdBufSourceState *R_DrawXModelSurfCameraInternal(const XSurface *a1, const GfxModelRigidSurfacePiece *a2, const GfxDrawSurf *drawSurfList, unsigned int drawSurfCount, GfxCmdBufContext context, const GfxDrawSurfListInfo *info);
XSurface *R_DrawXModelSurfInternal(const XSurface *a1, const GfxModelRigidSurfacePiece *a2, const GfxDrawSurf *drawSurfList, unsigned int drawSurfCount, GfxCmdBufContext context, const GfxDrawSurfListInfo *info);
unsigned int R_DrawXModelSurfLit(const XSurface *a1, const GfxModelRigidSurfacePiece *a2, const GfxDrawSurf *drawSurfList, unsigned int drawSurfCount, GfxCmdBufContext context);
GfxCmdBufSourceState *R_DrawXModelSurfCamera(const XSurface *a1, const GfxModelRigidSurfacePiece *a2, const GfxDrawSurf *drawSurfList, unsigned int drawSurfCount, GfxCmdBufContext context, const GfxDrawSurfListInfo *info);
XSurface *R_DrawXModelSurf(const XSurface *a1, const GfxModelRigidSurfacePiece *a2, const GfxDrawSurf *drawSurfList, unsigned int drawSurfCount, GfxCmdBufContext context, const GfxDrawSurfListInfo *info);

//#include "gfx_d3d/r_draw_xmodel.h"

//t6/code/src_noserver/gfx_d3d/r_dvars.cpp
void R_RegisterDvars(const char *a1, dvarType_t a2);
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
void R_SetFogFromServer(LocalClientNum_t localClientNum, float start, float r, float g, float b, float density, float heightDensity, float baseHeight, float fogColorScale, float sunFogColorR, float sunFogColorG, float sunFogColorB, float sunFogDirX, float sunFogDirY, float sunFogDirZ, float sunFogStartAng, float sunFogEndAng, float fogMaxOpacity);
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
void GetButtonProperties(LocalClientNum_t localClientNum, const char *text, Font_s *font, int *buttonCharLength, int *buttonMaterialWidth);
int R_TextWidth(LocalClientNum_t localClientNum, const char *text, int maxChars, Font_s *font);
int R_TextHeight(Font_s *font);
const char *R_TextLineWrapPosition(const char *text, int bufferSize, int pixelsAvailable, Font_s *font, float scale);
int R_ConsoleTextWidth(const char *textPool, int poolSize, int firstChar, int charCount, Font_s *font);

//t6/code/src_noserver/gfx_d3d/r_fonticon.cpp
FontIconEntry *R_GetFontIconEntryByHash(int fontIconNameHash, int size);
FontIconAlias *R_GetFontAliasEntry(char *fontIconAlias);
void R_GetFontIconEntryInfo(LocalClientNum_t localClientNum, char *fontIconName, int size, Material **iconShader, float *iconWidth, float *iconHeight);

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
void R_GPU_BeginTimer(int a1, int a2, GPUTimerId timerId);
void R_GPU_EndTimer(int a1);
void R_GPU_DrawTimers();

//t6/code/src_noserver/gfx_d3d/r_image.cpp
void TRACK_r_image();
void Image_TrackTotalMemory(GfxImage *image, int platform, int memory);
void R_AddImageToList(XAssetHeader header, void *data);
void R_GetImageList(ImageList *imageList);
void Image_Release(GfxImage *image);
int Image_GetAvailableHashLocation(const char *name);
void Image_Construct(const char *name, int nameSize, unsigned __int8 category, unsigned __int8 semantic, int imageTrack, GfxImage *image);
GfxImage *Image_AllocProg(int imageProgType, unsigned __int8 category, unsigned __int8 semantic);
GfxImage *Image_GetProg(int imageProgType);
GfxImage *__cdecl Image_Alloc(const char *name, const char *category, int semantic, int imageTrack);
void Image_Create2DTexture_PC(GfxImage *image, unsigned __int16 width, unsigned __int16 height, int mipmapCount, int imageFlags, DXGI_FORMAT imageFormat, void *initData);
void Image_Create3DTexture_PC(GfxImage *image, unsigned __int16 width, unsigned __int16 height, unsigned __int16 depth, int mipmapCount, int imageFlags, DXGI_FORMAT imageFormat, void *initData);
void Image_CreateCubeTexture_PC(GfxImage *image, unsigned __int16 edgeLen, int mipmapCount, DXGI_FORMAT imageFormat, void *initData);
void Image_SetupRenderTarget(GfxImage *image, unsigned __int16 width, unsigned __int16 height, DXGI_FORMAT imageFormat, const char *name, unsigned int allocFlags);
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
unsigned int Image_GetCardMemoryAmountForMipLevel(DXGI_FORMAT format, unsigned int mipWidth, unsigned int mipHeight, unsigned int mipDepth);
unsigned int Image_GetCardMemoryAmount(unsigned int imageFlags, DXGI_FORMAT format, unsigned int width, unsigned int height, unsigned int depth);
int Image_SourceBytesPerSlice_PC(DXGI_FORMAT format, int width, int height);
void Image_Upload2D_CopyDataBlock_PC(int width, int height, const unsigned __int8 *src, DXGI_FORMAT format, int dstPitch, unsigned __int8 *dst);
void Image_Upload2D_CopyData_PC(const GfxImage *image, DXGI_FORMAT format, D3D11_TEXTURECUBE_FACE face, unsigned int mipLevel, const unsigned __int8 *src);
void Image_Upload3D_CopyData_PC(const GfxImage *image, DXGI_FORMAT format, unsigned int mipLevel, const unsigned __int8 *src);
void __cdecl Image_UploadData(GfxImage *image, DXGI_FORMAT format, D3D11_TEXTURECUBE_FACE face, unsigned int mipLevel, const unsigned __int8 *src);
unsigned int Image_CountMipmaps(unsigned int imageFlags, unsigned int width, unsigned int height, unsigned int depth);
void Image_GetPicmip(const GfxImage *image, Picmip *picmip);
unsigned int Image_CubemapFace(unsigned int faceIndex);
void Image_TrackTexture(GfxImage *image, int imageFlags, DXGI_FORMAT format, int width, int height, int depth);
void Image_Setup(GfxImage *image, int width, int height, int depth, int imageFlags, DXGI_FORMAT imageFormat, void *initData);
void Image_SetupAndLoad(GfxImage *image, int width, int height, int depth, int imageFlags, DXGI_FORMAT imageFormat);

//#include "gfx_d3d/r_image_load_db.h"

//t6/code/src_noserver/gfx_d3d/r_image_load_obj.cpp
unsigned __int8 Image_GetPcStreamedMips(GfxImageFileHeader *fileHeader);
int Image_GetPicmipUsed(const GfxImage *image);
void Image_SetupFromFile(GfxImage *image, const GfxImageFileHeader *fileHeader, DXGI_FORMAT imageFormat, void *initData, unsigned int allocFlags, unsigned int *outStreamedSize);
unsigned __int8 *Image_AllocTempMemory(int bytes);
void Image_FreeTempMemory(unsigned __int8 *mem, int bytes);
void Image_LoadBitmap(GfxImage *image, const GfxImageFileHeader *fileHeader, unsigned __int8 *data, DXGI_FORMAT format, int bytesPerPixel, int allocFlags, unsigned int *outStreamedSize);
void Image_LoadDxtc(GfxImage *image, const GfxImageFileHeader *fileHeader, const unsigned __int8 *data, DXGI_FORMAT format, int bytesPerBlock, unsigned int allocFlags, unsigned int *outStreamedSize);
void __cdecl Image_LoadFromData(GfxImage *image, GfxImageFileHeader *fileHeader, unsigned __int8 *srcData, unsigned int allocFlags, unsigned int *outStreamedSize);
char Image_LoadFromFileInternal(const GfxImageFileHeader *a1, unsigned int a2, GfxImage *image);
char __cdecl Image_LoadFromFile(GfxImage *image);
void Image_Generate2D(GfxImage *image, unsigned __int8 *pixels, int width, int height, DXGI_FORMAT imageFormat);
void Image_GenerateCube(GfxImage *image, const unsigned __int8 *(*pixels)[15], int edgeLen, DXGI_FORMAT imageFormat, const unsigned int mipCount);
void Image_LoadWhite(GfxImage *image);
void Image_LoadBlack(GfxImage *image);
void Image_LoadGray(GfxImage *image);
void Image_LoadLinearGray(GfxImage *image);
void Image_LoadIdentityNormalMap(GfxImage *image);
void Image_LoadWhiteTransparent(GfxImage *image);
void Image_LoadBlackTransparent(GfxImage *image);
GfxImage *Image_LoadBuiltin(const char *name, unsigned __int8 semantic, int imageTrack);
GfxImage *__cdecl Image_Load(const char *name, int semantic, int imageTrack);

//t6/code/src_noserver/gfx_d3d/r_image_wavelet.cpp
void TRACK_r_image_wavelet();

//t6/code/src_noserver/gfx_d3d/r_init.cpp
void TRACK_r_init();
const char *R_ErrorDescription(int hr);
bool __cdecl R_IsNullRenderer(LocalClientNum_t a1);
char *R_GetFontPathFromName(const char *fontName);
void R_SetBrightness(float brightness);
void R_SetColorMappings();
void R_GammaCorrect(unsigned __int8 *buffer, int bufSize);
void SetGfxConfig(const GfxConfiguration *config);
void R_MakeDedicated(const GfxConfiguration *notthis);
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
void R_ConfigureRenderer(const GfxConfiguration *notthis);
bool R_StereoActivated();

//t6/code/src_noserver/gfx_d3d/r_light.cpp
GfxLightDef *R_RegisterLightDef_LoadObj(const char *name);
GfxLightDef *R_RegisterLightDef_FastFile(const char *name);
GfxLightDef *R_RegisterLightDef();
void R_InitFlashlight();
bool R_LightImportanceGreaterEqual(const GfxLight *light0, const GfxLight *light1);
void R_MostImportantLights(const GfxLight *a1, const GfxLight **lights, int lightCount, int keepCount);
int R_GetPointLightPartitions(int a1, GfxLight *visibleLights);
void R_ComputeSpotLightCrossDirs(const GfxLight *light, vec3_t *crossDirs);
void R_CalcSpotLightPlanes(vec3_t *a1, const GfxLight *light, float dynamicSpotLightNearPlaneOffset, vec4_t *planes);
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
int R_ChopPolyBehindPlane(int inPointCount, const FxModelMarkPoint *inPoints, FxModelMarkPoint *outPoints, const vec4_t *plane);
int R_ChopWorldPolyBehindPlane(int inPointCount, const FxWorldMarkPoint *inPoints, FxWorldMarkPoint *outPoints, const vec4_t *plane, float epsilon);
bool R_Mark_MaterialAllowsMarks(const Material *markReceiverMaterialHandle, const Material *markMaterialHandle);
BOOL R_AllowMarks();
void R_AABBTreeBoxSurfaces_r(GfxAabbTree *treeEA, const vec3_t *mins, const vec3_t *maxs, int (*allowSurf)(int, void *), void *callbackContext, GfxSurface **surfList, unsigned int surfListSize, unsigned int *surfCount);
void R_AABBTreeBoxSurfacesTwoLists_r(GfxAabbTree *treeEA, const vec3_t *mins, const vec3_t *maxs, int (**allowSurf)(int, void *), void *callbackContext, GfxSurface ***surfLists, unsigned int surfListSize, unsigned int *surfCounts);
void R_AddStaticModelToList(int smodelIndex, unsigned __int16 *smodelList, int *smodelCount);
void R_AABBTreeBoxStaticModels_r(GfxAabbTree *treeEA, const vec3_t *mins, const vec3_t *maxs, int (*allowSModel)(int), unsigned __int16 *smodelList, int smodelListSize, int *smodelCount);
void R_AABBTreeFrustumSurfaces_r(GfxAabbTree *treeEA, const vec3_t *mins, const vec3_t *maxs, const vec4_t *planes, unsigned int numPlanes, int (*allowSurf)(int), GfxSurface **surfList, int surfListSize, int *surfCount);
void R_AABBTreeFrustumStaticModels_r(int *a1, GfxAabbTree *treeEA, const vec3_t *mins, const vec3_t *maxs, const vec4_t *planes, unsigned int numPlanes, int (*allowSModel)(int), unsigned __int16 *smodelList, int smodelListSize, int *smodelCount);
void R_CellBoxSurfaces(int cellIndex, const vec3_t *mins, const vec3_t *maxs, int (*allowSurf)(int, void *), void *callbackContext, GfxSurface **surfList, unsigned int surfListSize, unsigned int *surfCount, unsigned __int8 *cellBits);
void R_CellBoxSurfacesTwoLists(int cellIndex, const vec3_t *mins, const vec3_t *maxs, int (**allowSurf)(int, void *), void *callbackContext, GfxSurface ***surfLists, unsigned int surfListSize, unsigned int *surfCounts, unsigned __int8 *cellBits);
void __cdecl R_BoxSurfaces_r(mnode_t *node, const vec3_t *mins, const vec3_t *maxs, int (__cdecl **allowSurf)(int, void *), void *callbackContext, GfxSurface ***surfLists, unsigned int surfListSize, unsigned int *surfCounts, unsigned int listCount, unsigned __int8 *cellBits);
void R_BoxStaticModels_r(mnode_t *node, const vec3_t *mins, const vec3_t *maxs, int (*allowSModel)(int), unsigned __int16 *smodelList, int smodelListSize, int *smodelCount, unsigned __int8 *cellBits);
void R_FrustumSurfaces_r(mnode_t *node, const vec3_t *mins, const vec3_t *maxs, const vec4_t *planes, unsigned int numPlanes, int (*allowSurf)(int), GfxSurface **surfList, int surfListSize, int *surfCount, unsigned __int8 *cellBits);
void R_FrustumStaticModels_r(mnode_t *node, const vec3_t *mins, const vec3_t *maxs, const vec4_t *planes, unsigned int numPlanes, int (*allowSModel)(int), unsigned __int16 *smodelList, int smodelListSize, int *smodelCount, unsigned __int8 *cellBits);
void R_BoxSurfaces(int a1, const vec3_t *mins, const vec3_t *maxs, int (**allowSurf)(int, void *), void *callbackContext, GfxSurface ***surfLists, unsigned int surfListSize, unsigned int *surfCounts, unsigned int listCount);
int R_BoxStaticModels(int a1, const vec3_t *mins, const vec3_t *maxs, int (*allowSModel)(int), unsigned __int16 *smodelList, int smodelListSize);
int R_FrustumSurfaces(int a1, const vec3_t *mins, const vec3_t *maxs, const vec4_t *planes, unsigned int numPlanes, int (*allowSurf)(int), GfxSurface **surfList, int surfListSize);
int R_FrustumStaticModels(int a1, const vec3_t *mins, const vec3_t *maxs, const vec4_t *planes, unsigned int numPlanes, int (*allowSModel)(int), unsigned __int16 *smodelList, int smodelListSize);
void R_GetMarkFragmentClipPlanes(const vec3_t *origin, const vec3_t *axis, float radius, MarkClipPlaneSet *clipPlanes);
bool R_MarkFragments_BrushSurface(MarkInfo *markInfo, GfxMarkContext *markContext, const MarkClipPlaneSet *clipPlanes, const vec3_t *markDir, const GfxSurface *remoteSurface, bool *anyMarks);
bool R_MarkFragments_WorldBrushes(MarkInfo *markInfo);
void R_Mark_TransformClipPlanes(const MarkClipPlaneSet *inClipPlanes, vec3_t *matrix, MarkClipPlaneSet *outClipPlanes);
char R_MarkFragments_EntBrushes(MarkInfo *markInfo);
bool R_MarkFragments_Glass(MarkInfo *markInfo);
void R_MarkUtil_GetDObjAnimMatAndHideParts(const DObj *dobj, const cpose_t *pose, const DObjAnimMat **outBoneMtxList, unsigned int *outHidePartBits);
void __cdecl R_MarkFragments_Begin(MarkInfo *markInfo, MarkFragmentsAgainstEnum markAgainst, const vec3_t *origin, const vec3_t *axis, float radius, const vec3_t *viewOffset, Material *material);
bool R_MarkFragments_AddDObj(MarkInfo *markInfo, DObj *dObj, cpose_t *pose, unsigned __int16 entityIndex);
char R_MarkFragments_AddViewModelDObj(MarkInfo *markInfo, DObj *dObj, cpose_t *pose);
bool R_MarkFragments_AddBModel(MarkInfo *markInfo, GfxBrushModel *brushModel, cpose_t *pose, unsigned __int16 entityIndex);
char R_MarkFragments_XModelSurface_Basic(GfxMarkContext *a1, __int64 *a2, float surfaceEA, const XSurface *modelAxis, const vec3_t *modelOrigin, const vec3_t *a6);
bool R_MarkFragments_EntirelyRigidXModel(MarkInfo *markInfo, const XModel *xmodelEA, const vec3_t *modelAxis, const vec3_t *modelOrigin, float modelScale, GfxMarkContext *markContext);
bool R_MarkFragments_AnimatedXModel_VertList(GfxMarkContext *markContext, XSurface *surfaceEA);
bool R_MarkFragments_AnimatedXModel(MarkInfo *markInfo, const XModel *model, const unsigned int *hidePartBits, int boneIndex, const DObjAnimMat *boneMtxList, int boneCount, GfxMarkContext *markContext);
bool R_MarkFragments_SceneDObjs(MarkInfo *markInfo);
bool R_MarkFragments_ViewmodelDObjs(MarkInfo *markInfo);
bool R_MarkFragments_StaticModels(MarkInfo *markInfo);
bool R_MarkFragments_Models(MarkInfo *markInfo);
void R_MarkFragments_Go(MarkInfo *markInfo, void (*callback)(void *, int, FxMarkTri *, int, FxMarkPoint *, const vec3_t *, const vec3_t *), void *callbackContext, int maxTris, FxMarkTri *tris, int maxPoints, FxMarkPoint *points);

//t6/code/src_noserver/gfx_d3d/r_material.cpp
void TRACK_r_material();
unsigned __int8 *Material_Alloc(int size);
void Load_CreateStateBits(const unsigned int (*pLoadBits)[2], GfxStateBits *stateBits);
void Load_CreateMaterialPixelShader(int a1, GfxPixelShaderLoadDef *loadDef, MaterialPixelShader *mtlShader);
void Load_CreateMaterialVertexShader(GfxVertexShaderLoadDef *loadDef, MaterialVertexShader *mtlShader);
void AssertValidVertexDeclOffsets(const stream_source_info_t *streamTable);
void Load_BuildVertexDecl(MaterialVertexDeclaration **mtlVertDecl, MaterialPass *pass);
bool MaterialTechniqueSet_FindHashLocation(const char *name, int *foundHashIndex);
MaterialTechniqueSet *Material_FindTechniqueSet_LoadObj(int *a1, const char *a2, const char *tname, MtlTechSetNotFoundBehavior notFoundBehavior);
MaterialTechniqueSet *Material_FindTechniqueSet_FastFile(char *a1, const char *name, MtlTechSetNotFoundBehavior notFoundBehavior);
void Material_SetTechniqueSet(const char *name, MaterialTechniqueSet *techniqueSet);
void Material_SetAlwaysUseDefaultMaterial(const bool alwaysUseDefaultMaterial);
MaterialTechniqueSet *Material_RegisterTechniqueSet(const char *prefix, const char *materialName, char *name, bool isLayerOrDefault);
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
void R_RegisterShaderConst(unsigned int buffer, unsigned int offset, const vec4_t *value, GfxShaderConstantBlock *consts);
void R_GetPixelLiteralConsts(int a1, int a2, int mtl, const Material *argCount, const MaterialPass *pass, GfxShaderConstantBlock *pixelLiteralConsts);
int R_ComparePixelConsts(const Material **material, const MaterialPass **pass);

//#include "gfx_d3d/r_material_load_db.h"

//t6/code/src_noserver/gfx_d3d/r_material_load_obj.cpp
int Material_GetTypeByPrefix(const char *name);
int Material_GetTypeByTechsetPrefix(const char *name);
const char *Material_GetPrefix(unsigned int materialType);
int R_DrawSurfStandardPrepassSortKey(const Material *material);
unsigned int Material_HashVertexDecl(const MaterialStreamRouting *routingData, int streamCount);
MaterialVertexDeclaration *Material_AllocVertexDecl(MaterialStreamRouting *routingData, int streamCount, bool *existing);
const float *Material_RegisterLiteral(const vec4_t *literal);
const char *Material_StringFromHash(unsigned int hash);
const char *Material_RegisterString(const char *string);
char Material_HashStateMap(const char *name, unsigned int *foundHashIndex);
bool MaterialTechnique_FindHashLocation(const char *name, unsigned int *foundHashIndex);
void Material_SetTechnique(const char *name, MaterialTechnique *technique);
const MtlStateMapBitName *Material_ParseValueForState(const char **text, const MtlStateMapBitName *bitNames);
MtlParseSuccess Material_ParseRuleSetConditionTest(const char **text, const char *token, MaterialStateMapRule *rule);
MtlParseSuccess Material_ParseRuleSetCondition(const char **text, const char *token, MaterialStateMapRule *rule);
bool Material_ParseRuleSetValue(const char **text, const char *token, const MtlStateMapBitGroup *stateSet, MaterialStateMapRule *rule);
MaterialStateMapRuleSet *Material_AssembleRuleSet(int ruleCount, const MaterialStateMapRule *rules);
bool Material_ParseRuleSet(const char **text, const char *ruleSetName, const MtlStateMapBitGroup *stateSet, MaterialStateMapRuleSet **ruleSet);
bool Material_ParseStateMap(const char **text, MaterialStateMap *stateMap);
MaterialStateMap *Material_LoadStateMap(const char *name);
MaterialStateMap *Material_RegisterStateMap(const char *name);
bool Material_LoadPassStateMap(const char **text, MaterialStateMap **stateMap);
bool Material_ParseIndex(const char **text, int indexCount, int *index);
const char *Material_NameForStreamDest(unsigned __int8 dest);
bool Material_StreamDestForName(const char **text, const char *destName, unsigned __int8 *dest);
bool Material_StreamSourceForName(const char **text, const char *sourceName, unsigned __int8 *source);
bool Material_ResourceDestForStreamDest(unsigned __int8 streamDest, ShaderVaryingDef *inputTable, unsigned int inputCount, unsigned __int8 *resourceDest);
bool Material_LoadPassVertexDecl(const char **text, ShaderVaryingDef *inputTable, unsigned int inputCount, MaterialPass *pass);
bool Material_ParseIndexRange(const char **text, unsigned int arrayCount, ShaderIndexRange *indexRange);
bool Material_ParseArrayOffset(const char **text, int arrayCount, int arrayStride, int *offset);
bool Material_CodeSamplerSource_r(const char **text, int offset, const CodeSamplerSource *sourceTable, ShaderArgumentSource *argSource);
bool Material_ParseSamplerSource(const char **text, ShaderArgumentSource *argSource);
bool Material_DefaultSamplerSourceFromTable(const char *constantName, const ShaderIndexRange *indexRange, const CodeSamplerSource *sourceTable, ShaderArgumentSource *argSource);
bool Material_ParseVector(const char **text, int elemCount, vec4_t *vector);
bool Material_ParseLiteral(const char **text, const char *token, vec4_t *literal);
bool Material_ParseCodeConstantSource_r(MaterialShaderType shaderType, const char **text, int offset, const CodeConstantSource *sourceTable, ShaderArgumentSource *argSource);
bool Material_ParseConstantSource(MaterialShaderType shaderType, const char **text, ShaderArgumentSource *argSource);
char Material_DefaultConstantSourceFromTable(MaterialShaderType shaderType, const char *constantName, const ShaderIndexRange *indexRange, const CodeConstantSource *sourceTable, ShaderArgumentSource *argSource);
bool Material_UnknownShaderworksConstantSource(MaterialShaderType shaderType, const char *constantName, const ShaderIndexRange *indexRange, ShaderArgumentSource *argSource);
unsigned int Material_ElemCountForParamName(const char *shaderName, const ShaderUniformDef *paramTable, unsigned int paramCount, const char *name, ShaderParamType *paramType);
bool Material_ParseArgumentSource(MaterialShaderType shaderType, const char **text, const char *shaderName, ShaderParamType paramType, ShaderArgumentSource *argSource);
bool Material_DefaultArgumentSource(MaterialShaderType shaderType, const char *constantName, ShaderParamType paramType, const ShaderIndexRange *indexRange, ShaderArgumentSource *argSource);
unsigned int R_SetParameterDefArray(ID3D11ShaderReflectionConstantBuffer *constantTable, unsigned __int16 bufferIndex, unsigned int constantIndex, ShaderUniformDef *paramDef);
unsigned int Material_PrepareToParseShaderArguments(ID3D11ShaderReflection *reflector, _D3D11_SHADER_DESC *shaderDesc, ShaderUniformDef *paramTable);
int Material_CompareShaderArgumentsForCombining(const void *e0, const void *e1);
unsigned int Material_CombineShaderArguments(unsigned int usedCount, MaterialShaderArgument *localArgs);
bool Material_SetShaderArguments(unsigned int usedCount, MaterialShaderArgument *localArgs, unsigned int argLimit, unsigned int *argCount, MaterialShaderArgument *args);
ShaderUniformDef *Material_GetShaderArgumentDest(const char *paramName, unsigned int paramIndex, ShaderUniformDef *paramTable, unsigned int paramCount);
MaterialUpdateFrequency Material_GetArgUpdateFrequency(const MaterialShaderArgument *arg);
bool MaterialAddShaderArgument(const char *shaderName, const char *paramName, MaterialShaderArgument *arg, char (*registerUsage)[64]);
bool Material_AddShaderArgumentFromLiteral(const char *shaderName, const char *paramName, unsigned __int16 type, const float *literal, ShaderUniformDef *dest, MaterialShaderArgument *arg, char (*registerUsage)[64]);
bool Material_AddShaderArgumentFromCodeConst(const char *shaderName, const char *paramName, unsigned __int16 type, unsigned int codeIndex, unsigned int offset, ShaderUniformDef *dest, MaterialShaderArgument *arg, char (*registerUsage)[64]);
bool Material_AddShaderArgumentFromMaterial(const char *shaderName, const char *paramName, unsigned __int16 type, const char *name, ShaderUniformDef *dest, MaterialShaderArgument *arg, char (*registerUsage)[64]);
bool __cdecl Material_AddShaderArgument(const char *shaderName, MaterialShaderType shaderType, ShaderArgumentSource *argSource, const ShaderArgumentDest *argDest, ShaderUniformDef *paramTable, unsigned int paramCount, unsigned int *usedCount, MaterialShaderArgument *argTable);
bool Material_ParseShaderArguments(const char **text, const char *shaderName, MaterialShaderType shaderType, ShaderUniformDef *paramTable, unsigned int paramCount, unsigned __int16 *techFlags, unsigned int argLimit, unsigned int *argCount, MaterialShaderArgument *args);
MaterialVertexShader *Material_LoadVertexShader(const char *shaderName, ShaderStats *stats);
MaterialPixelShader *Material_LoadPixelShader(const char *shaderName, int shaderVersion, ShaderStats *stats);
bool Material_GetVertexShaderHashIndex(const char *shaderName, unsigned int *foundHashIndex);
MaterialVertexShader *Material_RegisterVertexShader(unsigned int *a1, const char *a2, const char *shaderName, unsigned __int8 shaderVersion, ShaderStats *stats);
bool Material_GetPixelShaderHashIndex(const char *shaderName, unsigned int *foundHashIndex);
MaterialPixelShader *Material_RegisterPixelShader(unsigned int *a1, const char *a2, const char *shaderName, unsigned __int8 shaderVersion, ShaderStats *stats);
unsigned __int8 Material_GetStreamDestForSemantic(const _D3D11_SIGNATURE_PARAMETER_DESC *semantic);
bool Material_SetPassShaderArguments_DX(const char **text, const char *shaderName, MaterialShaderType shaderType, const unsigned int *program, unsigned int programSize, unsigned __int16 *techFlags, ShaderParameterSet *paramSet, unsigned int argLimit, unsigned int *argCount, MaterialShaderArgument *args);
bool Material_LoadPassVertexShader(const char **text, unsigned __int16 *techFlags, ShaderParameterSet *paramSet, MaterialPass *pass, unsigned int argLimit, unsigned int *argCount, MaterialShaderArgument *args);
bool Material_LoadDeclTypes(const char **text, MaterialPass *pass);
bool Material_LoadPassPixelShader(const char **text, unsigned __int16 *techFlags, ShaderParameterSet *paramSet, MaterialPass *pass, unsigned int argLimit, unsigned int *argCount, MaterialShaderArgument *args);
bool Material_ValidateShaderLinkage(const ShaderVaryingDef *vertexOutputs, unsigned int vertexOutputCount, const ShaderVaryingDef *pixelInputs, unsigned int pixelInputCount);
int Material_CompareShaderArgumentsForRuntime(const void *e0, const void *e1);
unsigned __int8 Material_CountArgsWithUpdateFrequency(MaterialUpdateFrequency updateFreq, const MaterialShaderArgument *args, unsigned int argCount, unsigned int *firstArg);
bool Material_LoadPass(const char **text, unsigned __int16 *techFlags, MaterialPass *pass, MaterialStateMap **stateMap, int materialType);
MaterialTechnique *Material_LoadTechnique(const char *name, int materialType);
MaterialTechnique *Material_RegisterTechnique(const char *name, int materialType);
bool Material_IgnoreTechnique(const char *name);
unsigned __int8 Material_TechniqueTypeForName(const char *name, bool *inUse);
bool Material_HasAlphaTest(const Material *mtl);
void Material_GetTechniqueSetDrawRegion;
void Material_SetMaterialDrawRegion(Material *material);
MaterialTechniqueSet *Material_LoadTechniqueSet(const char *fullName);
void Material_RemapStateBits(const Material *material, unsigned int toolFlags, const MaterialStateMap *stateMap, const unsigned int *refStateBits, unsigned int *stateBitsOut);
unsigned __int8 Material_AddStateBitsArrayToTable(const unsigned int (*stateBitsForPass)[2], unsigned int passCount, unsigned int (*stateBitsTable)[2], unsigned int *stateBitsCount);
unsigned int Material_GetCullFlags(Material *material);
unsigned int Material_GetCullShadowFlags(Material *material);
unsigned int Material_GetDecalFlags(const Material *mtl);
unsigned int Material_GetWritesDepthFlags(const Material *mtl);
unsigned int Material_GetUsesDepthBufferFlags(const Material *mtl);
unsigned int Material_GetUsesStencilBufferFlags(const Material *mtl);
void Material_UpdateTechniqueFlags(Material *material);
void Material_SetStateBits(Material *material, unsigned int (*stateBitsTable)[2], unsigned int stateBitsCount);
void Material_BuildStateBitsTable(Material *material, unsigned int toolFlags, const unsigned int *refStateBits);
char Material_ValidatePassArguments(const Material *mtl, const char *techniqueName, unsigned int argCount, const MaterialShaderArgument *args);
char Material_Validate(const Material *material);
int CompareRawMaterialTextures(const void *e0, const void *e1);
int CompareHashedMaterialTextures(const void *e0, const void *e1);
bool Material_FinishLoadingInstance(const MaterialRaw *mtlRaw, const char *name, const char *techniqueSetVertDeclPrefix, MaterialTechniqueSet **techniqueSet, unsigned int materialType, int imageTrack);
void Material_GetLayeredStateBits(const Material **layerMtl, unsigned int layerCount, unsigned int techType, unsigned int *stateBits);
unsigned int Material_CreateLayeredStateBitsTable(const Material **layerMtl, unsigned int layerCount, const MaterialTechniqueSet *techSet, unsigned __int8 *stateBitsEntry, unsigned int (*stateBitsTable)[2]);
Material *Material_CreateLayered(const char *name, const Material **layerMtl, unsigned int layerCount, MaterialTechniqueSet *techSet);
bool Material_HasNormalMap(const Material *mtl);
unsigned int Material_AppendTechniqueSetName(char *name, unsigned int nameLen, const char *append, char lyrToken);
const LayeredTechniqueSetName *Material_GetLayeredTechniqueSetName(const char *techSetName);
void Material_SetGameFlags;
Material *Material_LoadRaw(const MaterialRaw *mtlRaw, unsigned int materialType, const char *matname, int imageTrack);
void Material_GetInfo(Material *handle, MaterialInfo *matInfo);
void Material_GetVertexShaderName(char *dest, const MaterialPass *pass, int destsize);
int Material_ComparePixelConsts(const Material *mtl0, const Material *mtl1, unsigned __int8 techType);
int Material_CompareBySortKeyAndTechnique(const Material *mtl0, const Material *mtl1, const MaterialTechniqueSet **techSet, const MaterialTechnique **techniqueLit, const MaterialTechnique **techniqueEmissive);
bool Material_Compare(const Material *mtl0, const Material *mtl1);
void R_BuildScritableConstantArray(ScriptableConstant *array, int arraySize);
char R_FindScriptableConstantSource_ByHash(int a1, ScriptableConstant *a2, unsigned int hash, unsigned __int8 *dest);
char R_FindScriptableConstantSource_ByName(const char *name, unsigned __int8 *dest);
const char *R_FindScriptableConstantName_BySource(int a1, ScriptableConstant *a2, unsigned __int8 src);
MaterialTechniqueSet *Material_RegisterLayeredTechniqueSet(const Material **mtl, unsigned int layerCount);
Material *Material_LoadLayered(const char *assetName);
Material *Material_Load(LocalClientNum_t a1, const char *fullAssetName, int imageTrack);
void Material_SortInternal(Material **sortedMaterials, unsigned int materialCount);
void Material_Sort();

//t6/code/src_noserver/gfx_d3d/r_material_pass_load_obj.cpp
int R_IsMaterialPassMatch(MaterialPass *pass, VertexConstantMappingEntry *entry);
int R_IsMaterialPassConflict(unsigned int argCount, const MaterialShaderArgument *arg, VertexConstantMappingEntry *entry);
void R_MaterialPrecompilePass(VertexConstantMappingEntry *a1, MaterialPass *pass);

//t6/code/src_noserver/gfx_d3d/r_mem_track.cpp
void R_Track_Init();

//t6/code/src_noserver/gfx_d3d/r_meshdata.cpp
void R_BeginMeshVerts(GfxMeshData *mesh);
char R_ReserveMeshIndices(GfxMeshData *mesh, int indexCount, r_double_index_t **indicesOut);
char R_ReserveMeshVerts(GfxMeshData *mesh, int vertCount, unsigned __int16 *baseVertex);
unsigned __int8 *R_GetMeshVerts(GfxMeshData *mesh, unsigned __int16 baseVertex);
void R_ResetMesh(GfxMeshData *mesh);
void R_SetQuadMeshData(GfxMeshData *mesh, float x, float y, float w, float h, float s0, float t0, float s1, float t1, unsigned int color);
void R_SetQuadMesh(GfxQuadMeshData *quadMesh, float x, float y, float w, float h, float s0, float t0, float s1, float t1, unsigned int color);

//t6/code/src_noserver/gfx_d3d/r_model.cpp
void TRACK_r_model();
unsigned __int8 *Hunk_AllocXModelPrecache(int size);
unsigned __int8 *Hunk_AllocXModelPrecacheColl(int size);
XModel *R_RegisterModel();
void R_XModelDebugBoxes(const DObj *obj, int *partBits);
void R_XModelDebugAxes(const DObj *obj, int *partBits);
void R_XModelDebug(const DObj *obj, int *partBits);
int R_SkinXModel(XModelDrawInfo *drawInfo, const XModel *model, const DObj *obj, const cpose_t *pose, const GfxPlacement *placement, float scale, unsigned int gfxEntIndex, int noLodCullOut);
int R_SkinAndBoundSceneEnt(GfxSceneEntity *sceneEnt);
void XSurfaceReleaseResources(XSurface *surf);
void XSurfaceRenderString(const vec3_t *pos, const char *string);

//t6/code/src_noserver/gfx_d3d/r_model_lighting.cpp
unsigned int R_ModelLightingIndexFromHandle(unsigned __int16 handle);
void R_SetModelLightingConsts(unsigned __int16 handle, vec4_t *coordsAndVis, vec4_t *sh0, vec4_t *sh1, vec4_t *sh2);
void R_SetStaticModelLightingConsts(unsigned __int16 handle, unsigned __int8 visibility, const GfxLightingSHQuantized *encodedLightingSH, vec4_t *coordsAndVis, vec4_t *sh0, vec4_t *sh1, vec4_t *sh2);
unsigned int R_AllocModelLightingPixel(float lightGlobEA, GfxModelLightGlob *a2, GfxModelLightGlob *lightGlob);
void R_ToggleModelLightingFrame();
void R_SetStaticModelLightingForSource(const GfxStaticModelDrawInst *smodelDrawInst, GfxCmdBufSourceState *source);
void R_BeginAllStaticModelLighting();
void R_SetupDynamicModelLighting(GfxCmdBufInput *input);
void R_InitModelLightingGlobals();
void R_ResetModelLighting();
void R_InitStaticModelLighting();
void R_SetModelLightingForSource(unsigned __int16 handle, GfxCmdBufSourceState *source);
char R_AllocStaticModelLighting(const GfxStaticModelDrawInst *smodelDrawInst, unsigned int smodelIndex);
void R_CalcModelLighting(unsigned int entryIndex, const vec3_t *lightingOrigin, GfxModelLightExtrapolation extrapolateBehavior, bool useHeroLighting, unsigned __int8 *primaryLightIndex1, unsigned __int8 *primaryLightIndex2);
void R_SetStaticModelLighting(unsigned int smodelIndex);
void R_SetAllStaticModelLighting();
unsigned int R_AllocModelLighting(float z, const vec3_t *lightingOrigin, float lightingOriginToleranceSq, unsigned __int8 *useHeroLighting, unsigned __int16 *cachedLightingHandle, GfxLightingInfo *lightingInfoOut);

//#include "gfx_d3d/r_model_lighting.h"

//t6/code/src_noserver/gfx_d3d/r_model_lod.cpp
double R_GetBaseLodDist(const vec3_t *origin);
double R_GetAdjustedLodDistExtracam(float *pDist, XModelLodRampType lodRampType, const vec3_t *origin, float scale);
double R_GetAdjustedLodDist(float dist, XModelLodRampType lodRampType);

//t6/code/src_noserver/gfx_d3d/r_model_pose.cpp
DObjAnimMat *R_DObjCalcPose(const GfxSceneEntity *sceneEnt, const DObj *obj, int *partBits);
void R_SetNoDraw(GfxSceneEntity *sceneEnt, GfxSceneEntity *localSceneEnt);
DObjAnimMat *R_UpdateSceneEntBounds(int a1, GfxSceneEntity *sceneEnt, GfxSceneEntity **pLocalSceneEnt, const DObj **pObj, int waitForCullState);
void R_UpdateGfxEntityBoundsCmd(void *data);
int R_SkinSceneModel(int a1, int a2, int drawInfo, XModelDrawInfo *model, const XModel *obj, const DObj *pose, const cpose_t *placement, const GfxPlacement *scale, float gfxEntIndex, unsigned int noLodCullOut, int a11);
void R_ModelSkelCmd(const char *a1, void *data);

//t6/code/src_noserver/gfx_d3d/r_model_skin.cpp
void R_Tension(float *tensionData, const unsigned int vertCount, GfxPackedVertex *vertsOut, unsigned __int16 *triIndices, const unsigned int triCount, float *tensionBuffer);
DWORD EndBench();
void BenchSurf(const XSurface *surf, const DObjSkelMat *mat);
void R_SkinXSurfaceRigid(const XSurface *surf);
void R_SkinXSurfaceWeight(const GfxPackedVertex *inVerts, const XSurfaceVertexInfo *vertexInfo);
void R_SkinXModelCmd(int a1, void *data);

//t6/code/src_noserver/gfx_d3d/r_outdoor.cpp
void Outdoor_ApplyBoundingBox(const vec3_t *outdoorMin, const vec3_t *outdoorMax);
unsigned int Outdoor_UpdateTransforms();
void R_RegisterOutdoorImage(const vec3_t *a1, GfxWorld *world, const vec3_t *outdoorMin);
int Outdoor_ComputeTexels(int a1);
void R_GenerateOutdoorImage(GfxImage *outdoorImage);

//t6/code/src_noserver/gfx_d3d/r_perf_timer.cpp
void R_Perf_GetTimerAverageAndMaxMs(PerfTimerFrameHistory *timerFrameHistory, PerfTimerStyle *timerStyle, unsigned int timerId, float *averageMs, float *maxMs);
void R_Perf_GetFrameAverageAndMaxMs(PerfTimerFrameHistory *timerFrameHistory, PerfTimerStyle *timerStyle, float *averageMs, float *maxMs);
void R_Perf_ResetDraw();
void R_Perf_DrawTimers(int a1, PerfTimerFrameHistory *timerFrameHistory, PerfTimerStyle *timerStyle);

//#include "gfx_d3d/r_pix_profile.h"

//t6/code/src_noserver/gfx_d3d/r_pointlights.cpp
void GenerateLightGridBasisDirs();
void GatherIncidentEnergyInSpaceForLightFromDir(const vec3_t *energy, const vec3_t *lightFromDir, vec3_t *incidentEnergy);
void AddLightGridLightingForDir(vec3_t *lightingForDir, GfxDecodedLightGridColors *colors);
bool EvaluateHeroLightForGrid(const GfxHeroLight *light, const vec3_t *xyz, vec3_t *dirToLight, vec3_t *attenuatedColor);
void R_AdjustLightColorSamples(GfxDecodedLightGridColors *colors);
void R_AddHeroOnlyLightsToGridColors(GfxDecodedLightGridColors *packed, const vec3_t *heroPos);

//t6/code/src_noserver/gfx_d3d/r_pretess.cpp
void R_InitDrawSurfListInfo(GfxDrawSurfListInfo *info);
void R_EmitDrawSurfList(float drawSurfs, const GfxDrawSurf *a2, unsigned int drawSurfCount, GfxBackEndData *data);
unsigned int R_GetKeyCount(const GfxDrawSurf *drawSurfs, unsigned int drawSurfCount, unsigned int primarySortKey);
void R_MergeAndEmitDrawSurfLists(float firstStage, unsigned int a2, unsigned int stageCount, GfxBackEndData *data);

//t6/code/src_noserver/gfx_d3d/r_primarylights.cpp
unsigned int R_AddPotentiallyShadowedLight(const GfxViewInfo *viewInfo, unsigned int shadowableLightIndex, GfxCandidateShadowedLight *candidateLights, unsigned int candidateLightCount);
void R_AddShadowedLightToShadowHistory(GfxShadowedLightHistory *shadowHistory, unsigned int shadowableLightIndex, float fadeDelta);
void R_FadeOutShadowHistoryEntries(GfxShadowedLightHistory *shadowHistory, float fadeDelta);
void R_ClearShadowedPrimaryLightHistory(LocalClientNum_t localClientNum);
unsigned int R_AddDynamicShadowableLight(GfxViewInfo *viewInfo, const GfxLight *visibleLight);
BOOL R_IsDynamicShadowedLight(unsigned int shadowableLightIndex);
BOOL R_IsPrimaryLight(unsigned int shadowableLightIndex);
void R_ChooseShadowedLights(unsigned __int8 *shadowableLightIsUsed, GfxViewInfo *viewInfo);
unsigned int R_GetPrimaryLightEntityShadowBit(LocalClientNum_t localClientNum, unsigned int entnum, unsigned int primaryLightIndex);
unsigned int R_GetPrimaryLightDynEntShadowBit(unsigned int entnum, unsigned int primaryLightIndex);
void R_LinkSphereEntityToPrimaryLights(LocalClientNum_t localClientNum, unsigned int entityNum, const vec3_t *origin, float radius);
void R_LinkBoxEntityToPrimaryLights(LocalClientNum_t localClientNum, unsigned int entityNum, const vec3_t *mins, const vec3_t *maxs);
void R_LinkDynEntToPrimaryLights(unsigned int dynEntId, DynEntityDrawType drawType, const vec3_t *mins, const vec3_t *maxs);
void R_UnlinkEntityFromPrimaryLights(GfxWorld *world, LocalClientNum_t a2, LocalClientNum_t localClientNum);
void R_UnlinkDynEntFromPrimaryLights(GfxWorld *world, unsigned int a2, unsigned int dynEntId, DynEntityDrawType drawType);
BOOL R_IsEntityVisibleToPrimaryLight(unsigned int a1, LocalClientNum_t localClientNum);
BOOL R_IsDynEntVisibleToPrimaryLight(unsigned int a1, unsigned int a2, unsigned int dynEntId, DynEntityDrawType drawType);
int R_IsEntityVisibleToAnyShadowedLight(const GfxViewInfo *viewInfo, unsigned int entityNum);
BOOL R_IsDynEntVisibleToAnyShadowedLight(const GfxViewInfo *viewInfo, unsigned int dynEntIndex, DynEntityDrawType drawType);
void R_ShowPrimaryLightDebugLine(const vec3_t *origin, const vec3_t *axis, const vec3_t *lightingOrigin, unsigned int primaryLightIndex, int context);
void R_ShowPrimaryLightBsp(const GfxSurface *surface, unsigned int primaryLightIndex);

//#include "gfx_d3d/r_primarylights_cull.h"

//t6/code/src_noserver/gfx_d3d/r_qrcode.cpp
void RB_QRCode_SetShaderConstants(GfxCmdBufSourceState *source, const GfxQRCodeBackend *rbQRCode);
void R_QRCode_SetupBackendData(GfxQRCodeBackend *qrcodeBackend);

//t6/code/src_noserver/gfx_d3d/r_reflection_probe.cpp
void R_GetReflectionProbePosition(unsigned int index, vec3_t *pos);
void R_SetBlackProbe(unsigned __int8 *to, unsigned int size);
GfxImage *R_GenerateReflectionImageFromRawData(const unsigned __int8 *rawPixels, const int probeIndex, int probeHighMipSize);
void R_GenerateDummyReflectionImages(GfxReflectionProbe *probes, const DiskGfxDummyReflectionProbe *probeRawData, const int probeCount, const int probeBaseIndex);
void R_GenerateReflectionImages(GfxReflectionProbe *probes, const DiskGfxReflectionProbe *probeRawData, const int probeCount, const int probeBaseIndex);

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
void R_AddCmdDrawStretchPicWInternal(float x, float y, float w0, float w, float h, float s0, float t0, float s1, float t1, const vec4_t *color, Material *material);
void R_AddCmdDrawStretchPicInternal(float x, float y, float w, float h, float s0, float t0, float s1, float t1, const vec4_t *color, Material *material);
void R_AddCmdDrawStretchPicRotateXYInternal(float x, float y, float w, float h, float s0, float t0, float s1, float t1, float angle, const vec4_t *color, Material *material);
void R_AddCmdDrawStretchPicRotateSTInternal(float x, float y, float w, float h, float centerS, float centerT, float radiusST, float scaleFinalS, float scaleFinalT, float angle, const vec4_t *color, Material *material);
GfxCmdDrawText2D *AddBaseDrawTextCmd(const char *text, int maxChars, Font_s *font, float x, float y, float w, float xScale, float yScale, float rotation, const vec4_t *color, int style, int cursorPos, char cursor, float padding);
void R_AddCmdDrawTextWithCursorInternal(const char *text, int maxChars, Font_s *font, float x, float y, float w, float xScale, float yScale, float rotation, const vec4_t *color, int style, int cursorPos, char cursor, float padding);
void R_AddCmdDrawTextInternal(const char *text, int maxChars, Font_s *font, float x, float y, float xScale, float yScale, float rotation, const vec4_t *color, int style);
void R_AddCmdDrawTextWInternal(const char *text, int maxChars, Font_s *font, float x, float y, float w, float xScale, float yScale, float rotation, const vec4_t *color, int style, float padding);
void R_AddCmdDrawTextSubtitleInternal(const char *text, int maxChars, Font_s *font, float x, float y, float xScale, float yScale, float rotation, const vec4_t *color, int style, const vec4_t *glowColor, bool cinematic);
void R_AddCmdDrawTextWithEffectsInternal(const char *text, int maxChars, Font_s *font, float x, float y, float w, float xScale, float yScale, float rotation, const vec4_t *color, int style, const vec4_t *glowColor, Material *fxMaterial, Material *fxMaterialGlow, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration);
void R_AddCmdDrawTextWithCOD7DecodeEffectsInternal(const char *text, int maxChars, Font_s *font, float x, float y, float xScale, float yScale, float rotation, const vec4_t *color, int style, const vec4_t *glowColor, Material *fxMaterial, Material *fxMaterialGlow, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration);
void R_AddCmdDrawTextWithCOD7TypeWriterEffectsInternal(const char *text, int maxChars, Font_s *font, float x, float y, float xScale, float yScale, float rotation, const vec4_t *color, int style, const vec4_t *glowColor, Material *fxMaterial, Material *fxMaterialGlow, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration);
void R_AddCmdDrawTextWithRedactEffectsInternal(const char *text, int maxChars, Font_s *font, float x, float y, float xScale, float yScale, float rotation, const vec4_t *color, int style, const vec4_t *glowColor, Material *fxMaterial, Material *fxMaterialGlow, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, int fxRedactDecayStartTime, int fxRedactDecayDuration);
void R_AddCmdDrawTextWithPopInEffectsInternal(const char *text, int maxChars, Font_s *font, float x, float y, float xScale, float yScale, float rotation, const vec4_t *color, int style, const vec4_t *glowColor, Material *fxMaterial, Material *fxMaterialGlow, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration);
void CopyPoolTextToCmd(const char *textPool, int poolSize, int firstChar, int charCount, GfxCmdDrawText2D *cmd);
GfxCmdDrawText2D *AddBaseDrawConsoleTextCmd(const char *textPool, int poolSize, int firstChar, int charCount, Font_s *font, float x, float y, float xScale, float yScale, const vec4_t *color, int style);
void __cdecl R_AddCmdDrawConsoleTextInternal(const char *textPool, int poolSize, int firstChar, int charCount, Font_s *font, float x, float y, float xScale, float yScale, const vec4_t *color);
void __cdecl R_AddCmdDrawConsoleTextTypewriterFXInternal(const char *textPool, int poolSize, int firstChar, int charCount, Font_s *font, float x, float y, float xScale, float yScale, const vec4_t *color, int style, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration);
void __cdecl R_AddCmdDrawConsoleTextSubtitleInternal(const char *textPool, int poolSize, int firstChar, int charCount, Font_s *font, float x, float y, float xScale, float yScale, const vec4_t *color, int style, const vec4_t *glowColor);
void __cdecl R_AddCmdDrawConsoleTextPulseFXInternal(const char *textPool, int poolSize, int firstChar, int charCount, Font_s *font, float x, float y, float xScale, float yScale, const vec4_t *color, int style, const vec4_t *glowColor, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, Material *fxMaterial, Material *fxMaterialGlow);
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
void R_AddCmdDrawFramedInternal(float x, float y, float w, float h, float thicknessW, float thicknessH, float thicknessTex, int sides, const vec4_t *color, Material *material);
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
void R_AssignImageToRenderTargetDepthStencil(GfxRenderTarget *renderTarget, GfxImage *image, DXGI_FORMAT format);
void R_AssignImageToRenderTargetColor(GfxRenderTarget *renderTarget, GfxImage *image, DXGI_FORMAT format);
void R_InitRenderTargetImage(int imageProgType, unsigned __int16 width, unsigned __int16 height, DXGI_FORMAT format, RenderTargetUsage usage, GfxRenderTarget *renderTarget, unsigned int allocFlags);
void R_InitSizedRenderTargetImage(int imageProgType, int fullscreenWidth, int fullscreenHeight, int picmip, DXGI_FORMAT format, RenderTargetUsage usage, GfxRenderTarget *renderTarget, unsigned int allocFlags, bool depthBindAsShaderResource);
void R_InitShadowmapRenderTarget(int imageProgType, unsigned __int16 tileRes, unsigned __int16 tileRowCount, GfxRenderTarget *renderTarget, ShadowmapRTTiling tilingMethond);
const char *R_RenderTargetName(unsigned __int8 renderTargetId);
void __cdecl R_InitExtraCamRenderTargets(unsigned int width, unsigned int height, unsigned int multiExtraCamWidth, unsigned int multiExtraCamHeight, int location);
void R_ShutdownExtraCamRenderTargets();
void __cdecl R_InitUI3DRenderTarget(int width, int height, int location, bool allocatePingPongBuffer);
void R_ShutdownUI3DRenderTarget(bool freePingPongBuffer);
void __cdecl R_ResizeSunShadowmapRenderTarget_PC();
void __cdecl R_ResizeSpotShadowmapRenderTarget_PC();

//t6/code/src_noserver/gfx_d3d/r_rope_render.cpp
void SetupVertex(const __m128 *pos, const __m128 *normal, const __m128 *tangent, const GfxColor *color, PackedTexCoords texCoord, GfxPackedVertex *v);
void R_Rope_GenerateVerts_Internal(const RopeGenerateVertsCmd *cmd);
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
char R_AllocTextureOverride(unsigned int dobjModelMask, const Material *mat, const GfxImage *img1, const GfxImage *img2, int *prevOverride);
char R_AllocTextureOverride(unsigned int dobjModelMask, const GfxImage *img1, const GfxImage *img2, int *prevOverride);
char R_AllocTextureOverride(unsigned int dobjModelMask, const Material *mat1, const Material *mat2, int *prevOverride);
char R_AllocTextureOverride(unsigned int dobjModelMask, const Material *mat, unsigned __int16 shaderCodeConst, float x, float y, float z, float w, int *prevOverride);
char R_AllocTextureOverride(unsigned int dobjModelMask, unsigned __int16 shaderCodeConst, float x, float y, float z, float w, int *prevOverride);
unsigned int R_AllocSceneBrush();
void R_TryToValidateBrushModel(unsigned int modelIndex);
GfxBrushModel *R_GetBrushModel(unsigned int modelIndex);
void R_AddBrushModelToSceneFromAngles(const GfxBrushModel *bmodel, const vec3_t *origin, const vec3_t *angles, unsigned int entnum, const ShaderConstantSet *constants);
void R_AddGlassBrushToScene(const GfxBrushModel *bmodel, const vec3_t *origin, const vec3_t *angles, Material *altStreamingMaterial);
void R_AddDObjToScene(const DObj *obj, const cpose_t *pose, unsigned int entnum, unsigned int renderFxFlags, const vec3_t *lightingOrigin, const float *materialTime, const float *burnFraction, int altXModel, int textureOverrideIndex, const ShaderConstantSet *dobjConstantSet, float lightingOriginToleranceSq, float scale, bool isMarkableViewmodel);
int R_AllocParticleCloud();
GfxParticleCloud *R_GetGfxParticleCloud(unsigned int index);
void R_PrepareXModelRigidCullInfo(XModelRigidCullInfoContext *cullInfoContext);
void R_CloneAndSetupXModelDrawSurf(GfxDrawSurf *outDrawSurf, int skinnedCachedOffset, Material *material, surfaceType_t surfType, unsigned int surfId, unsigned int reflectionProbeIndex, unsigned int customIndex, unsigned int primaryLightIndex, unsigned int shaderConstantSetIndex, unsigned int visLightsMask, XModelRigidCullInfoContext *cullInfoContext, const GfxViewParms *viewParms, ViewParmsType viewParmsType, unsigned int depthHack);
void R_AddOmniLightToScene(int a1, const vec3_t *org, float radius, float r, float g, float b, float a);
void R_AddSpotLightToScene(float org, const vec3_t *a2, const vec3_t *axis, float radius, float fovInnerFraction, float startRadius, float endRadius, float r, float g, float b, float a, GfxLightDef *lightDef);
void R_AddFlashLightToScene(float org, const vec3_t *a2, const vec3_t *dir, const vec3_t *diry, const vec3_t *dirz, float flicker);
void R_UpdateFrameFog(refdef_t *refdef);
void R_SetupViewProjectionMatrices(GfxViewParms *viewParms);
void R_SetAllowShadowMaps(const bool allowShadowMaps);
void R_AddBModelSurfacesCamera(BModelDrawInfo *bmodelInfo, const GfxBrushModel *bmodel, GfxDrawSurf **drawSurfs, GfxDrawSurf **lastDrawSurfs, unsigned int reflectionProbeIndex, unsigned int visLightsMask, bool isVisibleForSunShadow);
GfxDrawSurf *R_AddBModelSurfaces(BModelDrawInfo *bmodelInfo, const GfxBrushModel *bmodel, unsigned __int8 techType, unsigned int primaryLightIndex, GfxDrawSurf *drawSurf, GfxDrawSurf *lastDrawSurf);
const XSurface *R_GetXSurface(const void *modelSurf, surfaceType_t surfType);
void R_SetEnablePlayerShadowFlag(bool flag);
Material *R_MaterialOverride(unsigned int modelIndex, int textureOverrideIdx, Material *drawMaterial);
void R_AddXModelSurfacesCamera(unsigned int a1, XModelRigidCullInfoContext *a2, XModelDrawInfo *modelInfo, const XModel *model, vec3_t *origin, unsigned int gfxEntIndex, unsigned int lightingHandle, unsigned int primaryLightIndex, int depthHack, GfxDrawSurf **drawSurfs, GfxDrawSurf **lastDrawSurfs, unsigned int reflectionProbeIndex, unsigned int constantSetIndex, unsigned int visLightsMask, bool isVisibleForSunShadow);
GfxDrawSurf *R_AddXModelSurfaces(XModelDrawInfo *modelInfo, const XModel *model, unsigned __int8 techType, GfxDrawSurf *drawSurf, GfxDrawSurf *lastDrawSurf);
GfxDrawSurf *R_AddDObjSurfaces(GfxSceneEntity *sceneEnt, unsigned __int8 techType, GfxDrawSurf *drawSurf, GfxDrawSurf *lastDrawSurf);
void R_SetSceneComposition(GfxViewInfo *viewInfo, const GfxSceneParms *sceneParms, const GfxExtraCamParms *extraCamParms);
void R_CheckShadowMapVolumes(const vec3_t *position);
char R_CheckShadowMapVolume(const vec3_t *position, unsigned int volumeIdx);
int R_CheckWorldFogModifierVolumes(vec3_t *position, unsigned int bankMask);
void R_UpdateWorldFrameFog(refdef_t *refdef);
int R_CheckExposureVolumes(vec3_t *position, float *feather);
void R_UpdateExposureValue;
void R_SetExposure;
void R_InitModifierVolumes(float *a1, vec3_t *a2, refdef_t *refdef);
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
void R_AddDrawLitCall(GfxViewInfo *viewInfo, unsigned int drawListType, unsigned __int8 cmdBufType, unsigned int cmdBufPartitionCount);
void R_AddDrawLitBspCall(GfxViewInfo *viewInfo, unsigned int drawListType, unsigned __int8 cmdBufType, unsigned int cmdBufPartitionCount);
void R_AddDrawLitStaticModelCall(GfxViewInfo *viewInfo, unsigned int drawListType, unsigned __int8 cmdBufType, unsigned int cmdBufPartitionCount);
void R_AddEmissiveSpotLight(GfxViewInfo *viewInfo, GfxLight *visibleLights, int visibleLightCount);
void R_SetSunShadowConstants(GfxCmdBufInput *input, const GfxSunShadowProjection *sunProj);
void R_SetSkyConstants(GfxCmdBufInput *input, const GfxViewInfo *viewInfo);
void R_SetSunConstants(GfxCmdBufInput *input, float sunVisibility);
void R_SetHeroLighting(GfxCmdBufInput *input, GfxViewInfo *viewInfo);
void R_SetSkyColorMatrix(GfxCmdBufInput *input);
void R_SetHDRControlConstants(float input, GfxCmdBufInput *a2, const GfxViewInfo *viewInfo, refdef_t *refdef);
void R_SetDLightsConstants(GfxCmdBufInput *input);
void R_SplitDrawSurfacesPrimarySortKeyScanRev(GfxDrawSurfListInfo *srcList, GfxDrawSurfListInfo *destList, int sortkeyID);
void DrawLightDebug(const GfxViewInfo *viewInfo, const GfxLight *L, const vec4_t *debugColor, bool forShadow);
void DrawSunDirectionDebug(const vec3_t *viewOrg, const vec3_t *viewForward);
void R_DrawFogParams(const refdef_t *refdef);
void R_SetSkyDynamicIntensity(float viewForward, const vec3_t *a2, GfxCmdBufInput *input);
int R_WaitForFXUpdateWorkerCmds();
int R_WaitForFXNonSpriteWorkerCmds();
void R_SetupDrawSurfListInfos(const int *infolist, int count, GfxViewInfo *viewInfo, const GfxViewParms *viewParmsDraw);
void R_SplitAndMergeDrawLists(GfxViewInfo *viewInfo, unsigned int srcDrawList, unsigned int sortkey, unsigned int dstDrawList, GfxBackEndData *backendData);
void R_MergeAndEmitDrawSurfListsIntoList(GfxDrawSurfListInfo *info, int start, int count, GfxBackEndData *backendData);
void R_FinishDecalAndEmissiveDrawSurfs(GfxViewInfo *viewInfo, const GfxViewParms *viewParmsDraw, GfxBackEndData *backendData, bool forExtraCamView);
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
void R_GenerateSortedDrawSurfs(const GfxSceneParms *sceneParms, const GfxViewParms *viewParmsDpvs, const GfxViewParms *viewParmsDraw, int frameTime, const refdef_t *refdef, const GfxExtraCamParms *extraCamParms);
void R_AddDrawCalls();
void R_ClearScene(LocalClientNum_t localClientNum, bool forStereoRightEyeView, bool forExtraCam);
LocalClientNum_t R_GetLocalClientNum();
void R_SetViewParmsForScene(const refdef_t *refdef, GfxViewParms *viewParms);
void R_SetSceneParms(const refdef_t *refdef, GfxSceneParms *sceneParms);
void R_ExtraCam_SetSceneParms(const refdef_t *refdef, GfxSceneParms *sceneParms);
void R_LerpDir(const vec3_t *dirBegin, const vec3_t *dirEnd, const int beginLerpTime, const int endLerpTime, const int currTime, vec3_t *result);
int R_UpdateFrameSun();
double R_LodScaleForSkinCacheOverflow(unsigned int viewIndex, float currentScale);
void R_UpdateLodParms(const refdef_t *refdef, GfxLodParms *lodParms);
void R_SetLodOrigin(const refdef_t *refdef);
GfxViewParms *R_SetupRenderSceneViewParms(const refdef_t *refdef);
void R_RenderScene(const GfxExtraCamParms *a1, const refdef_t *refdef, int frameTime, const GfxViewParms *viewParmsDraw, const GfxViewParms *viewParmsDpvs);
void R_LinkDObjEntity(LocalClientNum_t localClientNum, unsigned int entnum, vec3_t *origin, float radius);
void R_LinkBModelEntity(LocalClientNum_t localClientNum, unsigned int entnum, GfxBrushModel *bmodel);
void R_UnlinkEntity(LocalClientNum_t localClientNum, unsigned int entnum);
void R_LinkDynEnt(DynEntityDrawType a1, unsigned int a2, unsigned int dynEntId, DynEntityDrawType drawType, vec3_t *mins, vec3_t *maxs);
void R_UnlinkDynEnt(unsigned int dynEntId, DynEntityDrawType drawType);
void R_PvsLock_GetViewOrigin(vec3_t *out);
void R_PvsLock_GetViewAxis(vec3_t *out);
GfxViewParms *R_PvsLock_GetViewParms();
void ShowLodInfo(const vec3_t *origin, int lod, int numLods, float curDist, float lodDist, bool lodDistAutoGenerated);
void R_PerMap_Init();
void R_AddDObjSurfacesCamera(XModelRigidCullInfoContext *a1, float sceneEnt, GfxSceneEntity *a3, unsigned int lightingHandle, unsigned int primaryLightIndex, GfxDrawSurf **drawSurfs, GfxDrawSurf **lastDrawSurfs, unsigned int visLightsMask, bool isExtraCamera, bool isVisibleForSunShadow, const GfxViewParms *viewParms, XModelRigidCullInfoContext *cullInfoContext, bool sonarUseThermalMaterial);
void R_SetupVisibilityEarly(const GfxViewParms *viewParmsDpvs, unsigned int renderCullFlags, int recalculateShadows);
int r_add_draw_callsCallback(jqBatch *batch);
void R_RenderExtraCam(const GfxExtraCamParms *a1, const refdef_t *refdef, int frameTime, const GfxExtraCamParms *extraCamParms);

//t6/code/src_noserver/gfx_d3d/r_screenshot.cpp
void TRACK_r_screenshot();
void R_CubemapShotFlipVerticalBuffer(unsigned __int8 *buffer);
void R_CubemapShotWriteTargaHeader(const int res, unsigned __int8 *fileBuffer);
void R_CubemapShotCopyBufferToTarga(const unsigned __int8 *srcBuffer, unsigned __int8 *targa);
void R_CubemapShotApplyFresnelToTarga(const CubemapShot shotIndex, const float n0, const float n1, unsigned __int8 *targa);
void R_CubemapShotWriteTargaFile(const char *filename, const CubemapShot shotIndex, const float n0, const float n1);
void R_BeginCubemapShot(const int pixelWidthHeight, const int pixelBorder);
void R_SaveCubemapShot(const char *filename, const CubemapShot shotIndex, const float n0, const float n1);
void R_CubemapLightingForDir(int a1, long double linearColors, vec3_t **a3, int width, int height, const vec3_t *dir, const vec3_t *baseColor, unsigned __int8 *pixel);
void R_CubemapLighting(vec3_t **linearColors, int width, int height, const vec3_t *baseColor, unsigned __int8 **pixels);
void R_CubemapShotExtractLinearLight(unsigned __int8 **pixels, int width, int height, vec3_t **linearColors);
void R_LightingFromCubemapShots(const vec3_t *baseColor);
char R_GetBackBufferData(int a1, int x, int y, int width, int height, int bytesPerPixel, unsigned __int8 *buffer);
void R_CubemapShotCopySurfaceToBuffer(unsigned __int8 *buffer, const int bufferSizeInBytes);
void R_CopyCubemapShot(CubemapShot shotIndex);
void R_EndCubemapShot(void *notthis);

//#include "gfx_d3d/r_setstate_d3d.h"

//t6/code/src_noserver/gfx_d3d/r_shade.cpp
void R_SetVertexShaderConstantFromLiteral(GfxCmdBufState *state, unsigned int buffer, unsigned int offset, unsigned int size, const float *literal);
void R_SetPixelShaderConstantFromLiteral(GfxCmdBufState *state, unsigned int buffer, unsigned int offset, unsigned int size, const float *literal);
const float *R_GetCodeConstant(const GfxCmdBufContext *context, unsigned int constant);
void R_SetVertexShaderConstantFromCode(const GfxCmdBufContext *context, const MaterialShaderArgument *routingData);
int R_IsPixelShaderConstantUpToDate(const GfxCmdBufContext *context, const MaterialShaderArgument *routingData);
void R_SetPixelShaderConstantFromCode(unsigned int a1, const GfxCmdBufContext *context, const MaterialShaderArgument *routingData);
void R_SetPassShaderPrimArguments(const GfxCmdBufContext *context, unsigned int argCount, const MaterialShaderArgument *arg);
void R_SetPassShaderObjectArguments(const GfxCmdBufContext *context, unsigned int argCount, const MaterialShaderArgument *arg);
void R_SetupPassPerPrimArgs(GfxCmdBufContext context);
void __cdecl R_SetupPassPerObjectArgs(GfxCmdBufContext context);
void R_SetPassPixelShaderStableArguments(const GfxCmdBufContext *context, unsigned int argCount, const MaterialShaderArgument *arg);
void R_SetPassVertexShaderStableArguments(const GfxCmdBufContext *context, unsigned int argCount, const MaterialShaderArgument *arg);
void __cdecl R_SetupPassCriticalPixelShaderArgs(GfxCmdBufContext context);
void R_SetupPassVertexShaderArgs(GfxCmdBufContext context);
const MaterialTextureDef *R_SetPixelSamplerFromMaterial(const GfxCmdBufContext *context, const MaterialShaderArgument *arg, const MaterialTextureDef *texDef);
void __cdecl R_SetPassShaderStableArguments(const GfxCmdBufContext *context, unsigned int argCount, const MaterialShaderArgument *arg);
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
ShaderConstantSet *RB_ShaderConstantSetFromDrawSurf(const GfxBackEndData *backEndData, const GfxDrawSurf *drawSurf);
void RB_ApplyShaderConstantSet(GfxCmdBufSourceState *gfxSourceState, const GfxDrawSurf *drawSurf);
BOOL RB_DrawSurf_Uses_ShaderConstantSet(const GfxDrawSurf *drawSurf);
unsigned int CopyShaderConstantSetToBackendData(const ShaderConstantSet *scs);
void R_XModelDrawSurfEncodeShaderConstantSet(unsigned int a1, GfxDrawSurf *a2, GfxDrawSurf *drawSurf, unsigned int constSetIndex);
unsigned int R_ShaderConstantSet_CopyToFrontEndDataOut(const ShaderConstantSet *scs);
ShaderConstantSet *R_ShaderConstantSet_FromFrontEndDataOut(unsigned int constSetindex);
void RB_SaveCurrentShaderConstantSetValues(ShaderConstantSet *destSet, GfxCmdBufSourceState *gfxSourceState, const ShaderConstantSet *srcSet);
// void ScopedShaderConstantSetUndo::ScopedShaderConstantSetUndo(ScopedShaderConstantSetUndo *notthis, GfxCmdBufSourceState *sourceState, const ShaderConstantSet *cscEA);
// void ScopedShaderConstantSetUndo::~ScopedShaderConstantSetUndo(ScopedShaderConstantSetUndo *notthis);
void R_ShaderConstantShowDebug(const vec3_t *eyePos, const vec3_t *objOrigin, float objRad, const ShaderConstantSet *scs);
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
void R_SetViewParmsForLight(const GfxLight *light, GfxViewParms *viewParms);
void R_GetSpotShadowLookupMatrix(const GfxViewParms *shadowViewParms, int usingGridTiling, int usingFullShadowBuffer, unsigned int spotShadowIndex, unsigned int tileCount, GfxMatrix *lookupMatrix);
void R_AddSpotShadowModelEntities(LocalClientNum_t localClientNum, unsigned int primaryLightIndex, const GfxLight *light);
void R_EmitSpotShadowMapSurfs(const char *a1, GfxViewInfo *viewInfo);
void R_GenerateAllSortedSpotShadowDrawSurfs(GfxViewInfo *viewInfo, int viewIndex);
char __cdecl R_AddSpotShadowsForLight(GfxViewInfo *viewInfo, GfxLight *light, unsigned int shadowableLightIndex, unsigned int totalSpotLightCount, float spotShadowFade);

//t6/code/src_noserver/gfx_d3d/r_sprite.cpp
void R_BuildQuadStampCodeMeshVerts(Material *material, const vec3_t *viewAxis, const vec3_t *origin, const vec3_t *left, const vec3_t *up, const unsigned __int8 *rgbaColor, float s0, float t0, float s1, float t1);
void R_GenerateQuadStampCodeMeshVerts(Material *material, const vec3_t *viewAngles, const vec3_t *origin, float worldRadius, const unsigned __int8 *rgbaColor, float frameFrac);
_DWORD *really_fast_sincos(_DWORD *result, _DWORD *a2, __m128d a3);
void R_GenerateQuadStampCodeMeshVertsArray(int a1, float material, Material *a3, renderQuad_t *quads, int numQuads, vec3_t *viewAxis, const unsigned __int8 *rgbaColor, bool keepAspectRatio);

//t6/code/src_noserver/gfx_d3d/r_state.cpp
void R_ChangeDepthHackNearClip(GfxCmdBufSourceState *source, unsigned int depthHackFlags);
void R_ChangeObjectPlacement_Core(GfxCmdBufSourceState *source, const GfxScaledPlacement *placement);
void R_ChangeObjectPlacementRemote(GfxCmdBufSourceState *a1, const GfxScaledPlacement *a2);
void R_DeriveViewMatrix(GfxCmdBufSourceState *source);
void R_DeriveWorldViewMatrix(GfxCmdBufSourceState *source);
void R_DeriveProjectionMatrix(GfxCmdBufSourceState *source);
void R_DeriveViewProjectionMatrix(GfxCmdBufSourceState *source);
void R_DeriveWorldViewProjectionMatrix(GfxCmdBufSourceState *source);
void R_DeriveShadowLookupMatrix(GfxCmdBufSourceState *source);
void R_GenerateWorldOutdoorLookupMatrix(GfxCmdBufSourceState *source);
void R_DeriveCodeMatrix(GfxCmdBufSourceState *source, GfxCodeMatrices *activeMatrices, unsigned int baseIndex);
const vec4_t *R_GetCodeMatrix(GfxCmdBufSourceState *source, unsigned int sourceIndex, unsigned int firstRow);
const GfxImage *R_GetTextureFromCode(GfxCmdBufSourceState *source, unsigned int codeTexture, unsigned __int8 *samplerState, const Material *material);
void R_TextureFromCodeError(const GfxCmdBufContext *context, unsigned int codeTexture);
GfxImage *R_OverrideLightmapImage(int dvar_integer);
void R_SetReflectionProbe(GfxCmdBufContext context, unsigned int reflectionProbeIndex);
void R_ChangeDepthRange(GfxCmdBufState *state, GfxDepthRangeType depthRangeType);
void R_ChangeIndices(GfxCmdBufPrimState *state, ID3D11Buffer *ib);
void R_FlushStreamSources(GfxCmdBufPrimState *state, int firstStream, int lastStream);
void R_ChangeStreamSource(GfxCmdBufPrimState *state, int streamIndex, ID3D11Buffer *vb, unsigned int vertexOffset, unsigned int vertexStride);
void R_DrawIndexedPrimitive(const GfxCmdBufState *state, GfxCmdBufPrimState *primState, const GfxDrawPrimArgs *args);
ID3D11BlendState *R_HW_CreateBlendState(unsigned int stateBits0);
ID3D11DepthStencilState *R_HW_CreateDepthStencilState(unsigned int stateBits1, unsigned __int8 stencilMask);
ID3D11RasterizerState *R_HW_CreateRasterizerState(unsigned int stateBits0, unsigned int stateBits1);
void R_DX11_ReleaseSamplerStates();
void R_SetSampler(GfxCmdBufContext context, unsigned int textureIndex, unsigned int samplerIndex, unsigned __int8 samplerState, const GfxImage *image);
void R_TextureOverride(const GfxBackEndData *data, GfxCmdBufContext context, unsigned int modelIndex, int textureOverride);
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
void R_ClearScreenInternal(GfxCmdBufState *state, unsigned __int8 whichToClear, const vec4_t *color, float depth, int stencil);
void R_ClearScreen(GfxCmdBufState *state, unsigned __int8 whichToClear, const vec4_t *color, float depth, int stencil);
void R_DrawCall(int a1, void (*callback)(const void *, GfxCmdBufContext, const GfxViewInfo *), const void *userData, GfxCmdBufSourceState *source, const GfxViewInfo *viewInfo, const GfxViewParms *viewParms, GfxCmdBuf *cmdBufEA);
void R_SetLightmap(GfxCmdBufContext context, unsigned int lmapIndex);
void R_ClearAllStreamSources(GfxCmdBufPrimState *state);
void R_SetMeshStream(GfxCmdBufState *state, GfxMeshData *mesh);
void R_HW_SetBlendState(GfxCmdBufState *state, unsigned int stateBits0);
ID3D11DepthStencilState *R_HW_FindDepthStencilState(unsigned int stateBits1, unsigned __int8 stencilMask);
void R_HW_SetDepthStencilState(GfxCmdBufState *state, unsigned int stateBits1, unsigned __int8 stencilRef, unsigned __int8 stencilMask);

//#include "gfx_d3d/r_state.h"

//t6/code/src_noserver/gfx_d3d/r_state_utils.cpp
void R_InitCmdBufSourceState(GfxCmdBufSourceState *source, const GfxCmdBufInput *input, int cameraView);
void R_SetDebugShaderFeatures(GfxCmdBufSourceState *source);
void R_PixStartNamedRenderTarget(unsigned __int8 renderTargetId);
void R_InitCmdBufState(GfxCmdBufState *state, const GfxBackEndData *backEndData);
void R_ShutdownCmdBufState(GfxCmdBufState *state);
GfxCmdBufSourceState *R_GetActiveWorldMatrix(GfxCmdBufSourceState *source);
void R_CmdBufSet2D(GfxViewport *viewport);
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
unsigned int R_CalcReflectionProbeIndex(const vec3_t *a1, const GfxWorldDraw *a2, const vec3_t *origin);
void R_AllocStaticModels(GfxAabbTree *tree);
int R_SortGfxAabbTreeChildren(GfxWorld *world, vec3_t *mins, vec3_t *maxs, unsigned __int16 *staticModels, int staticModelCount);
int CompareStaticModels(const void *smodel0, const void *smodel1);
void R_SortGfxAabbTree(GfxWorld *world, GfxAabbTree *tree);
void R_AddStaticModelToAabbTree_r(GfxWorld *world, GfxAabbTree *tree, int smodelIndex);
void R_AddStaticModelToCell(GfxWorld *world, GfxStaticModelInst *smodelInst, const int cellIndex);
const char *GetNameFromStaticModelInst(const GfxStaticModelInst *smodelInst);
void R_FilterStaticModelIntoCells_r(float world, const cplane_s *a2, float node, GfxWorld *a4, mnode_t *smodelInst, GfxStaticModelInst *mins, const vec3_t *maxs, const vec3_t *a8);
int R_CellForPoint(const GfxWorld *world, const vec3_t *origin);
unsigned int R_CalcReflectionProbeIndex(const GfxWorld *world, const vec3_t *origin);
void R_SetStaticModelReflectionProbe(const vec3_t *a1, const GfxWorld *world, const GfxStaticModelInst *smodelInst, GfxStaticModelDrawInst *smodelDrawInst);
void R_CreateStaticModel(XModel *model, const vec3_t *origin, const vec3_t *axis, float scale, GfxStaticModelDrawInst *smodelDrawInst, GfxStaticModelInst *smodelInst, unsigned int staticModelFlags);

//t6/code/src_noserver/gfx_d3d/r_sunshadow.cpp
void R_CalcBoxVsCylinderRayMinBox(const vec3_t *box0, const vec3_t *box1, const vec3_t *origin, const vec3_t *forward, float radius, vec3_t *outBox0, vec3_t *outBox1);
void R_GetSceneExtentsAlongDir(const vec3_t *cameraOrigin, const vec3_t *origin, const vec3_t *forward, float *nearCap, float *farCap);
void R_GetSunAxes(vec3_t *sunAxis);
void R_ClipSpaceToWorldSpace(const GfxMatrix *invViewProjMtx, const vec3_t *clipSpacePoints, int pointCount, vec3_t *worldSpacePoints);
void R_SetupSunShadowBoundingPoly(const vec2_t *frustumPointsInSunProj, const vec2_t *viewOrgInSunProj, const vec2_t *snappedViewOrgInSunProj, float maxSizeInSunProj, const vec2_t *snappedViewOrgInClipSpace, GfxSunShadowBoundingPoly *boundingPoly, unsigned int pointCount);
void R_SunShadowMapBoundingPoly(const GfxSunShadowBoundingPoly *boundingPoly, float sampleSize, vec2_t *polyInClipSpace, int *pointIsNear, unsigned int partitionRes);
unsigned int R_SunShadowMapClipSpaceClipPlanes(const GfxSunShadowBoundingPoly *a1, float partitionIndex, int a3, vec4_t *boundingPolyClipSpacePlanes, unsigned int partitionRes);
void R_SunShadowMapProjectionMatrix(const vec2_t *snappedViewOrgInClipSpace, float shadowSampleSize, float nearClip, float farClip, GfxViewParms *shadowViewParms, unsigned int partitionRes);
void R_SetupSunShadowMapPartitionFraction(const GfxViewParms *viewParms, float scaleToFitUsable, GfxSunShadowProjection *sunProj, vec4_t *partitionFraction);
void R_SetupNearRegionPlane(const vec4_t *partitionFraction);
void R_SetupSunShadowMapProjection(const GfxViewParms *viewParms, const vec3_t *sunAxis, GfxSunShadow *sunShadow, vec2_t *snappedViewOrgInClipSpace, vec4_t *partitionFraction, unsigned int partitionRes);
void R_GetSunShadowLookupMatrix(const GfxViewParms *shadowViewParms, const GfxSunShadowProjection *sunProj, const vec4_t *partitionFraction, GfxMatrix *lookupMatrix);
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
void R_UI3D_SetupTextureWindow(int a1, ScreenPlacement *a2, int windowIndex, float normX, float normY, float normWidth, float normHeight);
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
void R_ConvertColorToBytes();
double FresnelTerm(float n0, float n1, float cosIncidentAngle);
char R_GetClearColor(vec4_t *unpackedRgba);
int R_PickEntityBone(unsigned int a1, int traceMask, const vec3_t *org, const vec3_t *dir, int boneIndex, const char **boneName);

//t6/code/src_noserver/gfx_d3d/r_warn.cpp
void R_UpdateFrameRate();
void R_WarnOncePerFrame(float warnType, GfxWarningType ap);
void R_WarnInitDvars(dvarType_t a1, dvarType_t a2);

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

