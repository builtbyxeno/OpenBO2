#include "types.h"
#include "vars.h"
#include "gfx_d3d_public.h"
#include <qcommon/qcommon_public.h>
#include <gfx_d3d/r_pix_profile.h>

GfxViewInfo s_viewInfo[1][4];
GfxCmdArray s_frontEndCmds[1];
GfxCmdArray* s_cmdList;

unsigned __int8 gRenderCmdDrawsSomething[33] =
{
  0u,
  0u,
  0u,
  0u,
  0u,
  1u,
  0u,
  0u,
  0u,
  1u,
  0u,
  1u,
  1u,
  1u,
  1u,
  1u,
  1u,
  1u,
  1u,
  1u,
  1u,
  1u,
  1u,
  1u,
  1u,
  1u,
  1u,
  1u,
  1u,
  1u,
  0u,
  1u,
  0u
};

#define GFXCMDHEADER_UI3D_MASK_WINDOW_INDEX 127

/*
==============
TRACK_r_rendercmds
==============
*/
void TRACK_r_rendercmds()
{
	track_static_alloc_internal(s_viewInfo, 12608, "s_viewInfo", 21);
	track_static_alloc_internal(s_frontEndCmds, 28, "s_frontEndCmds", 21);
}

GfxBackEndData s_backEndData[1];

/*
==============
R_InitGlassRenderBuffers
==============
*/
void R_InitGlassRenderBuffers(int numIndices, int numVerts, int vertexSize)
{
	s_backEndData[0].glassMesh.thisPtr = &s_backEndData[0].glassMesh;
	s_backEndData[0].glassMesh.indices = (unsigned short*)R_AllocDynamicIndexBuffer(&s_backEndData[0].glassMesh.ib, 2 * numIndices);
	s_backEndData[0].glassMesh.indices = (unsigned short*)R_AllocGlobalVariable(2 * numIndices, "R_InitDynamicMesh");
	s_backEndData[0].glassMesh.totalIndexCount = numIndices;
	s_backEndData[0].glassMesh.indexCount = 0;
	s_backEndData[0].glassMesh.vertSize = vertexSize;
	R_InitDynamicVertexBufferState(&s_backEndData[0].glassMesh.vb, vertexSize * numVerts);
	s_backEndData[0].glassMesh.vb.verts = (unsigned char*)Z_VirtualAlloc(vertexSize * numVerts, "glassMesh", 21);
}

/*
==============
R_InitTempSkinBuf
==============
*/
void R_InitTempSkinBuf(unsigned int maxVerts)
{
	assert(!s_backEndData[0].tempSkinPos);
	assert(!s_backEndData[0].tempSkinBuf);
	s_backEndData[0].tempSkinBuf = (unsigned char*)Z_VirtualReserve(32 * maxVerts);
	s_backEndData[0].tempSkinSize = 32 * maxVerts;
	s_backEndData[0].tempSkinPos = 0;
}

/*
==============
R_ShutdownTempSkinBuf
==============
*/
void R_ShutdownTempSkinBuf()
{
	if (s_backEndData[0].tempSkinBuf)
	{
		Z_VirtualFree(s_backEndData[0].tempSkinBuf);
		s_backEndData[0].tempSkinBuf = 0;
		s_backEndData[0].tempSkinPos = 0;
		s_backEndData[0].tempSkinSize = 0;
	}
}

/*
==============
R_UpdateSkinCacheUsage
==============
*/
void R_UpdateSkinCacheUsage()
{
	rg.skinnedVertexCacheUsed[frontEndDataOut->viewInfoIndex] = frontEndDataOut->skinnedCacheVertsAllocated / frontEndDataOut->skinnedCacheVb->total;
}

/*
==============
R_GetCommandBuffer
==============
*/
GfxCmdHeader *R_GetCommandBuffer(GfxRenderCommand renderCmd, int bytes)
{
	GfxCmdHeader* header;
	int sizeLimit;
	int ui3dWindowIndex;

	assert(s_cmdList);
	assertMsg((renderCmd >= 0 && renderCmd < RC_COUNT), "(renderCmd) = %i", renderCmd);
	assertMsg(((bytes & 3) == 0), "(bytes) = %i", bytes);
	assertMsg((bytes < s_cmdList->byteSize), "(bytes) = %i", bytes);
	assertMsg((bytes == static_cast<unsigned short>(bytes)), "(bytes) = %i", bytes);
	assert(s_cmdList->cmds);
	assert(rg.inFrame);

	if (renderCmd < RC_FIRST_NONCRITICAL)
	{
		if (s_cmdList->usedCritical < 7680 && bytes + s_cmdList->usedCritical >= 7680)
		{
			Com_PrintWarning(13, "RENDERCOMMAND_CRITICAL_WARN_SIZE (%i bytes) reached\n", 7680);
		}
	}

	if (s_cmdList->usedTotal < s_cmdList->warnSize && bytes + s_cmdList->usedTotal >= s_cmdList->warnSize)
	{
		Com_PrintWarning(CON_CHANNEL_GFX, "RENDERCOMMAND_WARN_SIZE (%.0f KB) reached\n", (s_cmdList->warnSize * 0.0009765625));
	}

	sizeLimit = s_cmdList->byteSize - s_cmdList->usedTotal;
	if (renderCmd >= RC_FIRST_NONCRITICAL)
	{
		sizeLimit -= 0x2000 - s_cmdList->usedCritical;
	}

	if (bytes > sizeLimit)
	{
		assertMsg(renderCmd >= RC_FIRST_NONCRITICAL, va("rc %i used %i critical %i bytes %i", renderCmd, s_cmdList->usedTotal, s_cmdList->usedCritical, bytes));
		s_cmdList->lastCmd = NULL;

		return NULL;
	}

	header = (GfxCmdHeader*)&s_cmdList->cmds[s_cmdList->usedTotal];
	s_cmdList->usedTotal += bytes;
	s_cmdList->usedCritical += renderCmd >= RC_FIRST_NONCRITICAL ? 0 : bytes;
	s_cmdList->lastCmd = header;
	header->id = renderCmd;

	ui3dWindowIndex = R_UI3DStack_Top(R_GetUI3DStack());

	assert(ui3dWindowIndex <= GFXCMDHEADER_UI3D_MASK_WINDOW_INDEX);
	if (ui3dWindowIndex >= 0)
	{
		header->ui3d = ui3dWindowIndex | 0x80;
	}
	else
	{
		header->ui3d = 0;
	}
	R_UI3D_IncrementRenderCmdCount(ui3dWindowIndex, gRenderCmdDrawsSomething[renderCmd]);
	header->byteCount = bytes;
	return header;
}

/*
==============
R_BeginClientCmdList2D
==============
*/
void R_BeginClientCmdList2D()
{
	frontEndDataOut->viewInfo[frontEndDataOut->viewInfoCount].cmds = &s_cmdList->cmds[s_cmdList->usedTotal];
}

/*
==============
R_ClearClientCmdList2D
==============
*/
void R_ClearClientCmdList2D()
{
	frontEndDataOut->viewInfo[frontEndDataOut->viewInfoCount].cmds = 0;
}

/*
==============
R_BeginSharedCmdList
==============
*/
void R_BeginSharedCmdList()
{
	frontEndDataOut->cmds = &s_cmdList->cmds[s_cmdList->usedTotal];
}

/*
==============
R_BeginCompositingCmdList
==============
*/
void R_BeginCompositingCmdList()
{
	frontEndDataOut->compositingCmds = &s_cmdList->cmds[s_cmdList->usedTotal];
}

/*
==============
R_AddCmdEndOfList
==============
*/
void R_AddCmdEndOfList()
{
	R_GetCommandBuffer(RC_END_OF_LIST, 4);
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
	return frontEndDataOut->frameCount;
}

/*
==============
R_AllocViewParms
==============
*/
GfxViewParms *R_AllocViewParms()
{
	GfxViewParms* viewParms;

	assert(frontEndDataOut);
	assertIn(frontEndDataOut->viewParmCount, ARRAY_COUNT(frontEndDataOut->viewParms));

	viewParms = &frontEndDataOut->viewParms[frontEndDataOut->viewParmCount];
	frontEndDataOut->viewParmCount++;
	viewParms->bspCellIndex = -1;
	
	return viewParms;
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

/*
==============
R_InitRenderThread
==============
*/
void R_InitRenderThread()
{
	if (!Sys_SpawnRenderThread(RB_RenderThread))
	{
		Com_Error(ERR_FATAL, "Failed to create render thread");
	}
}

