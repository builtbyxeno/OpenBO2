#include "types.h"
#include "functions.h"

/*
==============
TRACK_r_rendercmds
==============
*/
void TRACK_r_rendercmds()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitGlassRenderBuffers
==============
*/
void R_InitGlassRenderBuffers(int numIndices, int numVerts, int vertexSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_InitTempSkinBuf
==============
*/
void R_InitTempSkinBuf(unsigned int maxVerts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ShutdownTempSkinBuf
==============
*/
void R_ShutdownTempSkinBuf()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UpdateSkinCacheUsage
==============
*/
unsigned int R_UpdateSkinCacheUsage()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_GetCommandBuffer
==============
*/
GfxCmdHeader *R_GetCommandBuffer(GfxRenderCommand renderCmd, int bytes)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_BeginClientCmdList2D
==============
*/
void R_BeginClientCmdList2D()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ClearClientCmdList2D
==============
*/
void R_ClearClientCmdList2D()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_BeginSharedCmdList
==============
*/
void R_BeginSharedCmdList()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_BeginCompositingCmdList
==============
*/
void R_BeginCompositingCmdList()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdEndOfList
==============
*/
void R_AddCmdEndOfList()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ToggleSmpFrame
==============
*/
int R_ToggleSmpFrame()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_GetFrameCount
==============
*/
unsigned int R_GetFrameCount()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_AllocViewParms
==============
*/
GfxViewParms *R_AllocViewParms()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_AddCmdDrawStretchPicWInternal
==============
*/
void R_AddCmdDrawStretchPicWInternal(float x, float y, float w0, float w, float h, float s0, float t0, float s1, float t1, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdDrawStretchPicInternal
==============
*/
void R_AddCmdDrawStretchPicInternal(float x, float y, float w, float h, float s0, float t0, float s1, float t1, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdDrawStretchPicRotateXYInternal
==============
*/
void R_AddCmdDrawStretchPicRotateXYInternal(float x, float y, float w, float h, float s0, float t0, float s1, float t1, float angle, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdDrawStretchPicRotateSTInternal
==============
*/
void R_AddCmdDrawStretchPicRotateSTInternal(float x, float y, float w, float h, float centerS, float centerT, float radiusST, float scaleFinalS, float scaleFinalT, float angle, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AddBaseDrawTextCmd
==============
*/
GfxCmdDrawText2D *AddBaseDrawTextCmd(const char *text, int maxChars, Font_s *font, float x, float y, float w, float xScale, float yScale, float rotation, const vec4_t *color, int style, int cursorPos, char cursor, float padding)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_AddCmdDrawTextWithCursorInternal
==============
*/
void R_AddCmdDrawTextWithCursorInternal(const char *text, int maxChars, Font_s *font, float x, float y, float w, float xScale, float yScale, float rotation, const vec4_t *color, int style, int cursorPos, char cursor, float padding)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdDrawTextInternal
==============
*/
void R_AddCmdDrawTextInternal(const char *text, int maxChars, Font_s *font, float x, float y, float xScale, float yScale, float rotation, const vec4_t *color, int style)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdDrawTextWInternal
==============
*/
void R_AddCmdDrawTextWInternal(const char *text, int maxChars, Font_s *font, float x, float y, float w, float xScale, float yScale, float rotation, const vec4_t *color, int style, float padding)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdDrawTextSubtitleInternal
==============
*/
void R_AddCmdDrawTextSubtitleInternal(const char *text, int maxChars, Font_s *font, float x, float y, float xScale, float yScale, float rotation, const vec4_t *color, int style, const vec4_t *glowColor, bool cinematic)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdDrawTextWithEffectsInternal
==============
*/
void R_AddCmdDrawTextWithEffectsInternal(const char *text, int maxChars, Font_s *font, float x, float y, float w, float xScale, float yScale, float rotation, const vec4_t *color, int style, const vec4_t *glowColor, Material *fxMaterial, Material *fxMaterialGlow, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdDrawTextWithCOD7DecodeEffectsInternal
==============
*/
void R_AddCmdDrawTextWithCOD7DecodeEffectsInternal(const char *text, int maxChars, Font_s *font, float x, float y, float xScale, float yScale, float rotation, const vec4_t *color, int style, const vec4_t *glowColor, Material *fxMaterial, Material *fxMaterialGlow, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdDrawTextWithCOD7TypeWriterEffectsInternal
==============
*/
void R_AddCmdDrawTextWithCOD7TypeWriterEffectsInternal(const char *text, int maxChars, Font_s *font, float x, float y, float xScale, float yScale, float rotation, const vec4_t *color, int style, const vec4_t *glowColor, Material *fxMaterial, Material *fxMaterialGlow, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdDrawTextWithRedactEffectsInternal
==============
*/
void R_AddCmdDrawTextWithRedactEffectsInternal(const char *text, int maxChars, Font_s *font, float x, float y, float xScale, float yScale, float rotation, const vec4_t *color, int style, const vec4_t *glowColor, Material *fxMaterial, Material *fxMaterialGlow, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, int fxRedactDecayStartTime, int fxRedactDecayDuration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdDrawTextWithPopInEffectsInternal
==============
*/
void R_AddCmdDrawTextWithPopInEffectsInternal(const char *text, int maxChars, Font_s *font, float x, float y, float xScale, float yScale, float rotation, const vec4_t *color, int style, const vec4_t *glowColor, Material *fxMaterial, Material *fxMaterialGlow, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CopyPoolTextToCmd
==============
*/
void CopyPoolTextToCmd(const char *textPool, int poolSize, int firstChar, int charCount, GfxCmdDrawText2D *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AddBaseDrawConsoleTextCmd
==============
*/
GfxCmdDrawText2D *AddBaseDrawConsoleTextCmd(const char *textPool, int poolSize, int firstChar, int charCount, Font_s *font, float x, float y, float xScale, float yScale, const vec4_t *color, int style)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_AddCmdDrawConsoleTextInternal
==============
*/
void __cdecl R_AddCmdDrawConsoleTextInternal(const char *textPool, int poolSize, int firstChar, int charCount, Font_s *font, float x, float y, float xScale, float yScale, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdDrawConsoleTextTypewriterFXInternal
==============
*/
void __cdecl R_AddCmdDrawConsoleTextTypewriterFXInternal(const char *textPool, int poolSize, int firstChar, int charCount, Font_s *font, float x, float y, float xScale, float yScale, const vec4_t *color, int style, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdDrawConsoleTextSubtitleInternal
==============
*/
void __cdecl R_AddCmdDrawConsoleTextSubtitleInternal(const char *textPool, int poolSize, int firstChar, int charCount, Font_s *font, float x, float y, float xScale, float yScale, const vec4_t *color, int style, const vec4_t *glowColor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdDrawConsoleTextPulseFXInternal
==============
*/
void __cdecl R_AddCmdDrawConsoleTextPulseFXInternal(const char *textPool, int poolSize, int firstChar, int charCount, Font_s *font, float x, float y, float xScale, float yScale, const vec4_t *color, int style, const vec4_t *glowColor, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, Material *fxMaterial, Material *fxMaterialGlow)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdDrawQuadPicWInternal
==============
*/
void R_AddCmdDrawQuadPicWInternal(const vec2_t *verts, float w, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdDrawQuadPicInternal
==============
*/
void R_AddCmdDrawQuadPicInternal(const vec2_t *verts, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdSetCustomConstantInternal
==============
*/
void R_AddCmdSetCustomConstantInternal(unsigned int type, const vec4_t *vec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdSetViewportValuesInternal
==============
*/
void R_AddCmdSetViewportValuesInternal(int x, int y, int width, int height)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdSetScissorValuesInternal
==============
*/
void R_AddCmdSetScissorValuesInternal(bool enabled, int x, int y, int width, int height)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdPCCopyImageGenMIPInternal
==============
*/
void R_AddCmdPCCopyImageGenMIPInternal(void (*callback)(void *), GfxImage *image, void *job)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_LightTweaksModified
==============
*/
bool R_LightTweaksModified()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_SetTestLods
==============
*/
void R_SetTestLods()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SetOutdoorFeatherConst
==============
*/
int R_SetOutdoorFeatherConst()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_EndFrame
==============
*/
void R_EndFrame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdClearScreenInternal
==============
*/
void R_AddCmdClearScreenInternal(int whichToClear, const vec4_t *color, float depth, unsigned __int8 stencil)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdDrawQuadList2DInternal
==============
*/
GfxCmdHeader *R_AddCmdDrawQuadList2DInternal(Material *materialHandle, int quadCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
R_AddCmdProjectionSet2DInternal
==============
*/
void R_AddCmdProjectionSet2DInternal()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdDrawFramedInternal
==============
*/
void R_AddCmdDrawFramedInternal(float x, float y, float w, float h, float thicknessW, float thicknessH, float thicknessTex, int sides, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_AddCmdSetShaderConstantSetInternal
==============
*/
void R_AddCmdSetShaderConstantSetInternal(const ShaderConstantSet *scs_src)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_EnableRemoteScreenUpdateInGame
==============
*/
void R_EnableRemoteScreenUpdateInGame(bool en)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_BeginRemoteScreenUpdate
==============
*/
void R_BeginRemoteScreenUpdate()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_EndRemoteScreenUpdate
==============
*/
void R_EndRemoteScreenUpdate()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_PushRemoteScreenUpdate
==============
*/
void R_PushRemoteScreenUpdate(int remoteScreenUpdateNesting)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_PopRemoteScreenUpdate
==============
*/
int R_PopRemoteScreenUpdate()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_IsInRemoteScreenUpdate
==============
*/
BOOL R_IsInRemoteScreenUpdate()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_InitRenderCommands
==============
*/
void R_InitRenderCommands()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_FreeGlassRenderBuffers
==============
*/
void R_FreeGlassRenderBuffers()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_SyncRenderThread
==============
*/
void R_SyncRenderThread()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_ToggleSmpFrameCmd
==============
*/
void R_ToggleSmpFrameCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_IssueRenderCommands
==============
*/
void R_IssueRenderCommands(unsigned int type)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_UpdateFrontEndDvarOptions
==============
*/
bool R_UpdateFrontEndDvarOptions()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
R_BeginFrame
==============
*/
void R_BeginFrame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

