#include "types.h"
#include "vars.h"
#include "gfx_d3d_public.h"
#include <qcommon/qcommon_public.h>
#include <client_mp/client_mp_public.h>
#include <win32/win32_public.h>
#include <gfx_d3d/r_pix_profile.h>
#include <gfx_d3d/r_state.h>
#include <gfx_d3d/rb_backend.h>
#include <stringed/stringed_public.h>
#include <gfx_d3d/r_setstate_d3d.h>

r_backEndGlobals_t backEnd;
GfxCmdBufState gfxCmdBufState;

GfxBackEndData* data;
const GfxBackEndData* backEndData;

GfxCmdBufContext gfxCmdBufContext = { { { &gfxCmdBufSourceState, &gfxCmdBufState } } };
GfxCmdBufSourceState gfxCmdBufSourceState;

GfxFrameStats g_frameStatsCur;

unsigned int(__cdecl* const rb_tessTable[16])(const GfxDrawSurfListArgs*) =
{
  &R_TessTrianglesList,
  &R_TessTrianglesList,
  &R_TessStaticModelRigidList,
  &R_TessStaticModelRigidList,
  &R_TessStaticModelSkinnedDrawSurfList,
  &R_TessBModel,
  &R_TessXModelRigidDrawSurfList,
  &R_TessXModelRigidDrawSurfList,
  &R_TessXModelRigidSkinnedDrawSurfList,
  &R_TessXModelSkinnedDrawSurfList,
  &R_TessXModelSkinnedDrawSurfList,
  &R_TessCodeMeshList,
  &R_TessMarkMeshList,
  &R_TessParticleCloudList,
  &R_TessRopeMeshList,
  &R_TessGlassMeshList
};

/*
==============
TRACK_rb_backend
==============
*/
void TRACK_rb_backend()
{
	track_static_alloc_internal(&backEnd, sizeof(r_backEndGlobals_t), "backEnd", 21);
	track_static_alloc_internal(&tess, sizeof(materialCommands_t), "tess", 21);
	track_static_alloc_internal(&gfxCmdBufInput, sizeof(GfxCmdBufInput), "gfxCmdBufInput", 21);
}

/*
==============
RB_SetIdentity
==============
*/
void RB_SetIdentity()
{
	if (gfxCmdBufSourceState.viewMode != VIEW_MODE_IDENTITY)
	{
		if (tess.indexCount)
		{
			RB_EndTessSurface();
		}
		gfxCmdBufSourceState.viewMode = VIEW_MODE_IDENTITY;
		memcpy(&gfxCmdBufSourceState.viewParms, &rg, sizeof(gfxCmdBufSourceState.viewParms));
		gfxCmdBufSourceState.eyeOffset.v[0] = 0.0;
		gfxCmdBufSourceState.eyeOffset.v[1] = 0.0;
		gfxCmdBufSourceState.eyeOffset.v[2] = 0.0;
		gfxCmdBufSourceState.eyeOffset.v[3] = 1.0;
		R_CmdBufSet3D(&gfxCmdBufSourceState);
	}
}

/*
==============
R_SetVertex2d
==============
*/
void R_SetVertex2d(GfxVertex *vert, float x, float y, float s, float t, unsigned int color)
{
	vert->xyzw.v[0] = x;
	vert->xyzw.v[1] = y;
	vert->xyzw.v[2] = 0.0;
	vert->xyzw.v[3] = 1.0;

	vert->normal.packed = 0x3FFE7F7F;
	vert->color.packed = color;
	
	vert->texCoord.v[0] = s;
	vert->texCoord.v[1] = t;
}

/*
==============
R_SetVertex3d
==============
*/
void R_SetVertex3d(GfxVertex* vert, float x, float y, float z, float s, float t, unsigned int color)
{
	vert->xyzw.v[0] = x;
	vert->xyzw.v[1] = y;
	vert->xyzw.v[2] = z;
	vert->xyzw.v[3] = 1.0;

	vert->normal.packed = 0x3FFE7F7F;
	vert->color.packed = color;

	vert->texCoord.v[0] = s;
	vert->texCoord.v[1] = t;
}

/*
==============
RB_DrawFullSceneTri
==============
*/
void RB_DrawFullSceneTri(const Material *material, unsigned __int8 scene)
{
	int width, height;

	assert(gfxCmdBufSourceState.viewMode == VIEW_MODE_2D);
	RB_SetTessTechnique(material, 2);
	RB_TrackPrimsBegin(&gfxCmdBufState.prim.frameStats, GFX_PRIM_STATS_CODE);
	RB_CheckTessOverflow(tess.vertexCount, tess.indexCount);
	
	tess.indices[tess.indexCount] = tess.vertexCount;
	tess.indices[tess.indexCount + 1] = tess.vertexCount + 1;
	tess.indices[tess.indexCount + 2] = tess.vertexCount + 2;
	
	width = gfxRenderTargets[scene].width;
	height = gfxRenderTargets[scene].height;
	R_SetVertex2d(&tess.verts[tess.vertexCount], 0, 0, 1.0, -1.0, -1);
	R_SetVertex2d(&tess.verts[tess.vertexCount + 1], width * 2, 0, 2.0, 0.0, -1);
	R_SetVertex2d(&tess.verts[tess.vertexCount + 2], 0, height * 2, 0.0, 2.0, -1);
	tess.vertexCount += 3;
	tess.indexCount += 3;
}

/*
==============
RB_TessAddQuadIndices
==============
*/
void RB_TessAddQuadIndices(unsigned int vertCount)
{
	tess.indices[tess.indexCount] = vertCount + 3;
	tess.indices[tess.indexCount + 1] = vertCount;
	tess.indices[tess.indexCount + 2] = vertCount + 2;
	tess.indices[tess.indexCount + 3] = vertCount + 2;
	tess.indices[tess.indexCount + 4] = vertCount;
	tess.indices[tess.indexCount + 5] = vertCount + 1;
	tess.indexCount += 6;
}

/*
==============
RB_DrawSW4Quads
==============
*/
void RB_DrawSW4Quads(const Material *material, int ParticleCount)
{
	unsigned short vertCount;
	int i;

	RB_SetTessTechnique(material, 2);
	RB_TrackPrimsBegin(&gfxCmdBufState.prim.frameStats, GFX_PRIM_STATS_CODE);
	RB_CheckTessOverflow(4 * ParticleCount, 6 * ParticleCount);
	for (i = 0; i < ParticleCount; ++i)
	{
		vertCount = tess.vertexCount;

		tess.indices[tess.indexCount + 0] = vertCount + 3;
		tess.indices[tess.indexCount + 1] = vertCount; // + 0
		tess.indices[tess.indexCount + 2] = vertCount + 2;
		tess.indices[tess.indexCount + 3] = vertCount + 2;
		tess.indices[tess.indexCount + 4] = vertCount; // + 0
		tess.indices[tess.indexCount + 5] = vertCount + 1;

		R_SetVertex2d(&tess.verts[tess.vertexCount + 0], i, 0.0f, 0.0f, 0.0f, 0xFFFFFFFF);
		R_SetVertex2d(&tess.verts[tess.vertexCount + 1], i, 0.0f, 1.0f, 0.0f, 0xFFFFFFFF);
		R_SetVertex2d(&tess.verts[tess.vertexCount + 2], i, 0.0f, 1.0f, 1.0f, 0xFFFFFFFF);
		R_SetVertex2d(&tess.verts[tess.vertexCount + 3], i, 0.0f, 0.0f, 1.0f, 0xFFFFFFFF);
		tess.vertexCount += 4;
		tess.indexCount += 6;
	}
	RB_EndTessSurface();
}

/*
==============
RB_DrawStretchPic
==============
*/
void RB_DrawStretchPic(const Material *material, float x, float y, float w, float h, float s0, float t0, float s1, float t1, unsigned int color, GfxPrimStatsTarget statsTarget)
{
	unsigned short vertCount;

	assert(gfxCmdBufSourceState.viewMode == VIEW_MODE_2D);
	RB_SetTessTechnique(material, 2u);
	RB_TrackPrimsBegin(&gfxCmdBufState.prim.frameStats, statsTarget);
	RB_CheckTessOverflow(4, 6);
	RB_TessAddQuadIndices(tess.vertexCount);

	R_SetVertex2d(&tess.verts[tess.vertexCount + 0], x, y, s0, t0, color);
	R_SetVertex2d(&tess.verts[tess.vertexCount + 1], x + w, y, s1, t0, color);
	R_SetVertex2d(&tess.verts[tess.vertexCount + 2], x + w, y + h, s1, t1, color);
	R_SetVertex2d(&tess.verts[tess.vertexCount + 3], x, y + h, s0, t1, color);

	tess.vertexCount += 4;
}

/*
==============
RB_DrawStretchPicW
==============
*/
void RB_DrawStretchPicW(const Material *material, float x, float y, float w0, float w, float h, float s0, float t0, float s1, float t1, unsigned int color, GfxPrimStatsTarget statsTarget)
{
	assert(gfxCmdBufSourceState.viewMode == VIEW_MODE_2D);
	RB_SetTessTechnique(material, 2u);
	RB_TrackPrimsBegin(&gfxCmdBufState.prim.frameStats, statsTarget);
	RB_CheckTessOverflow(4, 6);
	RB_TessAddQuadIndices(tess.vertexCount);

	R_SetVertex4d(&tess.verts[tess.vertexCount + 0], x, y, 0.0f, w0, s0, t0, color);
	R_SetVertex4d(&tess.verts[tess.vertexCount + 1], x + w, y, 0.0f, w0, s1, t0, color);
	R_SetVertex4d(&tess.verts[tess.vertexCount + 2], x + w, y + h, 0.0f, w0, s1, t1, color);
	R_SetVertex4d(&tess.verts[tess.vertexCount + 3], x, y + h, 0.0f, w0, s0, t1, color);

	tess.vertexCount += 4;
}

/*
==============
RB_DrawStretchPicZ
==============
*/
void RB_DrawStretchPicZ(const Material *material, float x, float y, float z, float w, float h, float s0, float t0, float s1, float t1, unsigned int color, GfxPrimStatsTarget statsTarget)
{
	assert(gfxCmdBufSourceState.viewMode == VIEW_MODE_2D);
	RB_SetTessTechnique(material, 2u);
	RB_TrackPrimsBegin(&gfxCmdBufState.prim.frameStats, statsTarget);
	RB_CheckTessOverflow(4, 6);
	RB_TessAddQuadIndices(tess.vertexCount);

	R_SetVertex3d(&tess.verts[tess.vertexCount + 0], x, y, z, s0, t0, color);
	R_SetVertex3d(&tess.verts[tess.vertexCount + 1], x + w, y, z, s1, t0, color);
	R_SetVertex3d(&tess.verts[tess.vertexCount + 2], x + w, y + h, z, s1, t1, color);
	R_SetVertex3d(&tess.verts[tess.vertexCount + 3], x, y + h, z, s0, t1, color);

	tess.vertexCount += 4;
}

/*
==============
RB_DrawStretchPicFlipST
==============
*/
void RB_DrawStretchPicFlipST(const Material *material, float x, float y, float w, float h, float s0, float t0, float s1, float t1, unsigned int color, GfxPrimStatsTarget statsTarget)
{
	assert(gfxCmdBufSourceState.viewMode == VIEW_MODE_2D);
	RB_SetTessTechnique(material, 2u);
	RB_TrackPrimsBegin(&gfxCmdBufState.prim.frameStats, statsTarget);
	RB_CheckTessOverflow(4, 6);
	RB_TessAddQuadIndices(tess.vertexCount);

	R_SetVertex2d(&tess.verts[tess.vertexCount + 0], x, y, s0, t0, color);
	R_SetVertex2d(&tess.verts[tess.vertexCount + 1], x + w, y, s0, t1, color);
	R_SetVertex2d(&tess.verts[tess.vertexCount + 2], x + w, y + h, s1, t1, color);
	R_SetVertex2d(&tess.verts[tess.vertexCount + 3], x, y + h, s1, t0, color);

	tess.vertexCount += 4;
}

/*
==============
RB_DrawStretchPicRotate
==============
*/
void RB_DrawStretchPicRotate(const Material *material, float x, float y, float w, float width, float height, float s0, float t0, float s1, float t1, float sinAngle, float cosAngle, unsigned int color, GfxPrimStatsTarget statsTarget)
{
	float stepY;

	assert(gfxCmdBufSourceState.viewMode == VIEW_MODE_2D);
	RB_SetTessTechnique(material, 2u);
	RB_TrackPrimsBegin(&gfxCmdBufState.prim.frameStats, statsTarget);
	RB_CheckTessOverflow(4, 6);
	RB_TessAddQuadIndices(tess.vertexCount);

	stepY = -height * sinAngle;
	R_SetVertex4d(&tess.verts[tess.vertexCount + 0], x, y, 0.0f, w, s0, t0, color);
	R_SetVertex4d(&tess.verts[tess.vertexCount + 1], x + width * cosAngle, y + width * sinAngle, 0.0f, w, s1, t0, color);
	R_SetVertex4d(&tess.verts[tess.vertexCount + 2], x + width * cosAngle + stepY, y + width * sinAngle + height * cosAngle, 0.0f, w, s1, t1, color);
	R_SetVertex4d(&tess.verts[tess.vertexCount + 3], x + stepY, y + height * cosAngle, 0.0f, w, s0, t1, color);

	tess.vertexCount += 4;
}

/*
==============
RB_DrawFullScreenColoredQuad
==============
*/
void RB_DrawFullScreenColoredQuad(const Material *material, float s0, float t0, float s1, float t1, unsigned int color)
{
	if (tess.indexCount)
	{
		RB_EndTessSurface();
	}
	R_Set2D(&gfxCmdBufSourceState);
	RB_DrawStretchPic(material, 0.0, 0.0, gfxCmdBufSourceState.renderTargetWidth, gfxCmdBufSourceState.renderTargetHeight, s0, t0, s1, t1, color, GFX_PRIM_STATS_CODE);
	RB_EndTessSurface();
}

/*
==============
RB_FullScreenColoredFilter
==============
*/
void RB_FullScreenColoredFilter(const Material *material, unsigned int color)
{
	if (tess.indexCount)
	{
		RB_EndTessSurface();
	}
	R_Set2D(&gfxCmdBufSourceState);
	RB_DrawStretchPic(material, 0.0, 0.0, gfxCmdBufSourceState.renderTargetWidth, gfxCmdBufSourceState.renderTargetHeight, 0.0, 0.0, 1.0, 1.0, color, GFX_PRIM_STATS_CODE);
	RB_EndTessSurface();
}

/*
==============
RB_FullScreenFilterWithFlag
==============
*/
void RB_FullScreenFilterWithFlag(const Material *material, int filterFlags)
{
	R_UpdateCodeConstant(&gfxCmdBufSourceState, 0x55u, 0.0, 0.0, 1.0, 1.0);
	if ((filterFlags & 4) != 0)
	{
		if (tess.indexCount)
		{
			RB_EndTessSurface();
		}
		R_Set2D(&gfxCmdBufSourceState);
		RB_DrawStretchPic(material, 0.0, 0.0, gfxCmdBufSourceState.renderTargetWidth, gfxCmdBufSourceState.renderTargetHeight, 0.0, 0.0, 1.0, 1.0, 0xFFFFFFFF, GFX_PRIM_STATS_CODE);
		RB_EndTessSurface();
	}
	else
	{
		RB_FullScreenColoredFilter(material, 0xFFFFFFFF);
	}
}

/*
==============
RB_FullScreenFilter
==============
*/
void RB_FullScreenFilter(const Material *material)
{
	R_UpdateCodeConstant(&gfxCmdBufSourceState, CONST_SRC_CODE_VIEWPORT_DIMENSIONS, 0.0, 0.0, 1.0, 1.0);
	RB_FullScreenColoredFilter(material, 0xFFFFFFFF);
}

/*
==============
RB_SplitScreenTexCoords
==============
*/
void RB_SplitScreenTexCoords(float x, float y, float w, float h, float *s0, float *t0, float *s1, float *t1)
{
	float xa, ya, wa, ha;

	assert(s0);
	assert(s1);
	assert(t0);
	assert(t1);

	x = x / (float)gfxCmdBufSourceState.renderTargetWidth;
	y = y / (float)gfxCmdBufSourceState.renderTargetHeight;
	w = w / (float)gfxCmdBufSourceState.renderTargetWidth;
	h = h / (float)gfxCmdBufSourceState.renderTargetHeight;

	*s0 = x;
	*t0 = y;
	*s1 = x + w;
	*t1 = y + h;
}

/*
==============
RB_SplitScreenFilter
==============
*/
void RB_SplitScreenFilter(const Material *material, const GfxViewInfo *viewInfo, unsigned int color)
{
	float t0, t1, s1, s0, x, y, w, h;

	if (tess.indexCount)
	{
		RB_EndTessSurface();
	}

	R_Set2D(&gfxCmdBufSourceState);
	x = viewInfo->displayViewport.x;
	y = viewInfo->displayViewport.y;
	w = viewInfo->displayViewport.width;
	h = viewInfo->displayViewport.height;
	RB_SplitScreenTexCoords(x, y, w, h, &s0, &t0, &s1, &t1);
	const float _s1 = 1.0f / (s1 - s0);
	const float _t1 = 1.0f / (t1 - t0);
	R_UpdateCodeConstant(&gfxCmdBufSourceState, CONST_SRC_CODE_VIEWPORT_DIMENSIONS, s0, t0, _s1, _t1);
	RB_DrawStretchPic(material, 0.0f, 0.0f, w, h, s0, t0, s1, t1, color, GFX_PRIM_STATS_CODE);
	RB_EndTessSurface();
}

/*
==============
R_Resolve
==============
*/
void R_Resolve(GfxCmdBufContext context, GfxImage *image)
{
	int renderTargetId;
	D3D11_RENDER_TARGET_VIEW_DESC desc;
	ID3D11Resource* src;
	ID3D11Resource* dst;

	assert(image);
	renderTargetId = context.state->renderTargetId;
	assertMsg((image->width == gfxRenderTargets[context.state->renderTargetId].width), "%s", va("%s,%i", image->name, renderTargetId));
	assertMsg((image->height == gfxRenderTargets[context.state->renderTargetId].height), "%s", va("%s,%i", image->name, context.state->renderTargetId));

	PIXBeginNamedEvent(-1, __FUNCTION__);
	assert((image != gfxRenderTargets[context.state->renderTargetId].image));

	gfxRenderTargets[context.state->renderTargetId].surface.color->GetResource(&src);
	assert(src);
	image->texture.basemap->GetResource(&dst);
	assert(dst);
	gfxRenderTargets[context.state->renderTargetId].surface.color->GetDesc(&desc);

	if (desc.ViewDimension == D3D11_RTV_DIMENSION_TEXTURE2DMS)
	{
		context.state->prim.device->ResolveSubresource(dst, 0, src, 0, desc.Format);
	}
	else
	{
		context.state->prim.device->CopyResource(dst, src);
	}

	dst->Release();
	src->Release();

	if (Sys_IsRenderThread())
	{
		D3DPERF_EndEvent();
	}
}

/*
==============
R_ResolveFloatZ
==============
*/
void R_ResolveFloatZ(GfxCmdBufContext context)
{
	const GfxImage* Prog;

	R_SetRenderTargetSize(context.source, R_RENDERTARGET_FLOAT_Z);
	R_SetRenderTarget(context, R_RENDERTARGET_FLOAT_Z);
	R_SetFullViewport(context.source);
	R_Set2D(context.source);

	Prog = Image_GetProg(11);

	assert(context.source);
	context.source->input.codeImages[18] = Prog;
	context.source->input.codeImageSamplerStates[18] = 97;

	switch (dx.multiSampleType)
	{
	case 1:
		RB_DrawFullSceneTri(rgp.resolveFloatZ1, 8);
		break;
	case 2:
		RB_DrawFullSceneTri(rgp.resolveFloatZ2, 8);
		break;
	case 4:
		RB_DrawFullSceneTri(rgp.resolveFloatZ4, 8);
		break;
	case 8:
		RB_DrawFullSceneTri(rgp.resolveFloatZ8, 8);
		break;
	case 16:
		RB_DrawFullSceneTri(rgp.resolveFloatZ16, 8);
		break;
	default:
		AssertMsg("Invalid MSAA");
	}
	RB_EndTessSurface();

	for (int i = 0; i < vidConfig.maxTextureMaps; ++i)
	{
		R_DisableSampler(context.state, i);
	}

	GfxCmdBufSourceState* source = context.source;
	GfxImage* image = gfxRenderTargets[8].image;
	if (!source)
	{
		assertCont(source, context.source->input.codeImages[18] = image);
		source = 0;
	}
	source->input.codeImages[18] = image;
}

/*
==============
RB_StretchPicCmd
==============
*/
void RB_StretchPicCmd(GfxRenderCommandExecState *execState)
{
	GfxCmdStretchPic* cmd;

	cmd = (GfxCmdStretchPic*)execState->cmd;

	PIXBeginNamedEvent(-1, va("\"%s\"", cmd->material->info.name[0] ? cmd->material->info.name : "noname"));
	RB_DrawStretchPicW(cmd->material, cmd->x, cmd->y, cmd->w0, cmd->w, cmd->h, cmd->s0, cmd->t0, cmd->s1, cmd->t1, cmd->color.packed, GFX_PRIM_STATS_HUD);
	if (Sys_IsRenderThread())
	{
		D3DPERF_EndEvent();
	}

	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_StretchPicCmdFlipST
==============
*/
void RB_StretchPicCmdFlipST(GfxRenderCommandExecState *execState)
{
	const GfxCmdStretchPicRotateST* cmd;

	cmd = (const GfxCmdStretchPicRotateST*)execState->cmd;

	RB_DrawStretchPicFlipST(cmd->material, cmd->x, cmd->y, cmd->w, cmd->h, cmd->centerS, cmd->centerT, cmd->scaleFinalS, cmd->scaleFinalT, cmd->color.packed, GFX_PRIM_STATS_HUD);

	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

inline void R_SetVertex4d(GfxVertex* vert, float x, float y, float z, float w, float s, float t, int color)
{
	vert->xyzw.v[0] = x;
	vert->xyzw.v[1] = y;
	vert->xyzw.v[2] = z;
	vert->xyzw.v[3] = w;
	vert->normal.packed = 1073643391;
	vert->color.packed = color;
	vert->texCoord.v[0] = s;
	vert->texCoord.v[1] = t;
}

/*
==============
RB_StretchPicRotateXYCmd
==============
*/
void RB_StretchPicRotateXYCmd(GfxRenderCommandExecState *execState)
{
	const GfxCmdStretchPicRotateXY* cmd;
	float halfWidth, halfHeight, midX, midY, angle, cosAngle, sinAngle, stepY[2], stepX[2];
	int indexCount, col;

	cmd = (const GfxCmdStretchPicRotateXY*)execState->cmd;
	
	assert(gfxCmdBufSourceState.viewMode == VIEW_MODE_2D);
	RB_SetTessTechnique(cmd->material, 4);
	RB_TrackPrimsBegin(&gfxCmdBufState.prim.frameStats, GFX_PRIM_STATS_HUD);

	RB_CheckTessOverflow(4, 6);
	RB_TessAddQuadIndices(tess.vertexCount);

	halfWidth = cmd->w * 0.5f;
	halfHeight = cmd->h * 0.5f;
	midX = cmd->x + halfWidth;
	midY = cmd->y + halfHeight;
	
	angle = cmd->rotation * (M_PI / 180.0f);
	cosAngle = cos(angle);
	sinAngle = sin(angle);

	stepX[0] = halfWidth * cosAngle;
	stepX[1] = halfWidth * sinAngle;
	stepY[0] = -halfHeight * sinAngle;
	stepY[1] = halfHeight * cosAngle;
	col = cmd->color.packed;

	R_SetVertex4d(
		&tess.verts[tess.vertexCount],
		(midX - halfWidth * cosAngle) - stepY[0],
		(midY - halfWidth * sinAngle) - stepY[1],
		0.0f,
		cmd->w0,
		cmd->s0,
		cmd->t0,
		col);
	R_SetVertex4d(
		&tess.verts[tess.vertexCount + 1],
		((midX + stepX[0]) - stepY[0]),
		((midY + stepX[1]) - stepY[1]),
		0.0f,
		cmd->w0,
		cmd->s1,
		cmd->t0,
		col);
	R_SetVertex4d(
		&tess.verts[tess.vertexCount + 2],
		((midX + stepX[0]) + stepY[0]),
		((midY + stepX[1]) + stepY[1]),
		0.0f,
		cmd->w0,
		cmd->s1,
		cmd->t1,
		col);
	R_SetVertex4d(
		&tess.verts[tess.vertexCount + 3],
		((midX - stepX[0]) + stepY[0]),
		((midY - stepX[1]) + stepY[1]),
		0.0f,
		cmd->w0,
		cmd->s0,
		cmd->t1,
		col);

	tess.vertexCount += 4;

	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_StretchPicRotateSTCmd
==============
*/
void RB_StretchPicRotateSTCmd(GfxRenderCommandExecState *execState)
{
	const GfxCmdStretchPicRotateST* cmd;
	float angle, cosAngle, sinAngle, texS[4], stepS[2], stepT[2], texT[4];

	cmd = (const GfxCmdStretchPicRotateST*)execState->cmd;

	assert(gfxCmdBufSourceState.viewMode == VIEW_MODE_2D);
	RB_SetTessTechnique(cmd->material, 4);
	RB_TrackPrimsBegin(&gfxCmdBufState.prim.frameStats, GFX_PRIM_STATS_HUD);
	RB_CheckTessOverflow(4, 6);
	RB_TessAddQuadIndices(tess.vertexCount);

	angle = cmd->rotation * (M_PI / 180.0f);
	cosAngle = cos(angle);
	sinAngle = sin(angle);
	stepS[0] = (float)(cmd->radiusST * cosAngle) * cmd->scaleFinalS;
	stepS[1] = (float)(cmd->radiusST * sinAngle) * cmd->scaleFinalT;
	stepT[0] = (float)(-cmd->radiusST * sinAngle) * cmd->scaleFinalS;
	stepT[1] = (float)(cmd->radiusST * cosAngle) * cmd->scaleFinalT;

	texS[0] = (float)(cmd->centerS - stepS[0]) - stepT[0];
	texT[0] = (float)(cmd->centerT - stepS[1]) - stepT[1];
	texS[1] = (float)(cmd->centerS + stepS[0]) - stepT[0];
	texT[1] = (float)(cmd->centerT + stepS[1]) - stepT[1];
	texS[2] = (float)(cmd->centerS + stepS[0]) + stepT[0];
	texT[2] = (float)(cmd->centerT + stepS[1]) + stepT[1];
	texS[3] = (float)(cmd->centerS - stepS[0]) + stepT[0];
	texT[3] = (float)(cmd->centerT - stepS[1]) + stepT[1];

	R_SetVertex2d(&tess.verts[tess.vertexCount + 0], cmd->x, cmd->y, texS[0], texT[0], cmd->color.packed);
	R_SetVertex2d(&tess.verts[tess.vertexCount + 1], cmd->x + cmd->w, cmd->y, texS[1], texT[1], cmd->color.packed);
	R_SetVertex2d(&tess.verts[tess.vertexCount + 2], cmd->x + cmd->w, cmd->y + cmd->h, texS[2], texT[2], cmd->color.packed);
	R_SetVertex2d(&tess.verts[tess.vertexCount + 3], cmd->x, cmd->y + cmd->h, texS[3], texT[3], cmd->color.packed);

	tess.vertexCount += 4;

	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_DrawQuadPicCmd
==============
*/
void RB_DrawQuadPicCmd(GfxRenderCommandExecState *execState)
{
	const GfxCmdDrawQuadPic* cmd;
	unsigned short vertCount;
	int indexCount;
	float w;

	cmd = (const GfxCmdDrawQuadPic*)execState->cmd;

	assert(gfxCmdBufSourceState.viewMode == VIEW_MODE_2D);
	RB_SetTessTechnique(cmd->material, 4);
	RB_TrackPrimsBegin(&gfxCmdBufState.prim.frameStats, GFX_PRIM_STATS_HUD);
	RB_CheckTessOverflow(4, 6);
	RB_TessAddQuadIndices(tess.vertexCount);

	w = cmd->w;
	R_SetVertex4d(&tess.verts[tess.vertexCount], cmd->verts[0].v[0], cmd->verts[0].v[1], 0.0f, w, 0.0f, 0.0f, cmd->color.packed);
	R_SetVertex4d(&tess.verts[tess.vertexCount + 1], cmd->verts[1].v[0], cmd->verts[1].v[1], 0.0f, w, 1.0f, 0.0f, cmd->color.packed);
	R_SetVertex4d(&tess.verts[tess.vertexCount + 2], cmd->verts[2].v[0], cmd->verts[2].v[1], 0.0f, w, 1.0f, 1.0f, cmd->color.packed);
	R_SetVertex4d(&tess.verts[tess.vertexCount + 3], cmd->verts[3].v[0], cmd->verts[3].v[1], 0.0f, w, 0.0f, 1.0f, cmd->color.packed);

	tess.vertexCount += 4;
	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_DrawQuadList2DCmd
==============
*/
void RB_DrawQuadList2DCmd(GfxRenderCommandExecState *execState)
{
	int n;
	int indexCount;
	GfxQuadVertex** verts;
	unsigned short vertCount;
	const GfxCmdDrawQuadList2D* cmd;
	int quadCount;

	cmd = (const GfxCmdDrawQuadList2D*)execState->cmd;
	assert(gfxCmdBufSourceState.viewMode == VIEW_MODE_2D);
	RB_SetTessTechnique(cmd->material, 4);
	RB_TrackPrimsBegin(&gfxCmdBufState.prim.frameStats, GFX_PRIM_STATS_HUD);
	quadCount = cmd->quadCount;
	RB_CheckTessOverflow(4 * quadCount, 6 * quadCount);

	vertCount = tess.vertexCount;
	indexCount = tess.indexCount;
	tess.vertexCount += 4 * quadCount;
	tess.indexCount += 6 * quadCount;
	verts = cmd->verts;
	for (n = 0; n < quadCount; ++n)
	{
		tess.indices[indexCount + 0] = vertCount + 3;
		tess.indices[indexCount + 1] = vertCount + 0;
		tess.indices[indexCount + 2] = vertCount + 2;
		tess.indices[indexCount + 3] = vertCount + 2;
		tess.indices[indexCount + 4] = vertCount + 0;
		tess.indices[indexCount + 5] = vertCount + 1;
		R_SetVertex2d(&tess.verts[vertCount], verts[n]->xy.v[0], verts[n]->xy.v[1], verts[n]->st.v[0], verts[n]->st.v[1], verts[n]->color.packed);
		R_SetVertex2d(
			&tess.verts[vertCount + 1],
			verts[n][1].xy.v[0],
			verts[n][1].xy.v[1],
			verts[n][1].st.v[0],
			verts[n][1].st.v[1],
			verts[n][1].color.packed);
		R_SetVertex2d(
			&tess.verts[vertCount + 2],
			verts[n][2].xy.v[0],
			verts[n][2].xy.v[1],
			verts[n][2].st.v[0],
			verts[n][2].st.v[1],
			verts[n][2].color.packed);
		R_SetVertex2d(
			&tess.verts[vertCount + 3],
			verts[n][3].xy.v[0],
			verts[n][3].xy.v[1],
			verts[n][3].st.v[0],
			verts[n][3].st.v[1],
			verts[n][3].color.packed);
		vertCount += 4;
		indexCount += 6;
	}
	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_SetUIStencilState
==============
*/
void RB_SetUIStencilState(unsigned __int8 stencilWrite, unsigned __int8 stencilValue, unsigned int *stateBits)
{
	const Material* material;
	int currBits;
	GfxStateBits* stateBitsTable;
	
	material = gfxCmdBufContext.state->material;
	currBits = material->stateBitsEntry[gfxCmdBufContext.state->techType];
	stateBitsTable = material->stateBitsTable;

	stateBits[0] = stateBitsTable[currBits].loadBits[0];
	stateBits[1] = stateBitsTable[currBits].loadBits[1];

	if (stencilWrite)
	{
		stateBits[0] &= 0xE7FFFFFF;
		stateBits[1] = stateBits[1] & 0x3F | 0xE92E92C0;
		R_HW_SetBlendState(gfxCmdBufContext.state, stateBits[0]);
		R_HW_SetDepthStencilState(gfxCmdBufContext.state, stateBits[1], stencilValue, 0xFF);
	}
	else if (stencilValue)
	{
		stateBits[1] = stateBitsTable[currBits].loadBits[1] & 0x3F | 0x600600C0;
		R_HW_SetDepthStencilState(gfxCmdBufContext.state, stateBits[1], stencilValue, 0);
	}
}

/*
==============
RB_DrawUIQuadsInternal
==============
*/
void RB_DrawUIQuadsInternal(unsigned __int8 stencilWrite, unsigned __int8 stencilValue, bool isUI3D, int quadCount, const vec3_t *xyz, const vec2_t *st, const GfxColor *color)
{
	unsigned int stateBits;
	int indexCount;
	unsigned __int16 vertCount;

	if (!isUI3D)
	{
		RB_SetUIStencilState(stencilWrite, stencilValue, &stateBits);
	}
	RB_TrackPrimsBegin(&gfxCmdBufState.prim.frameStats, GFX_PRIM_STATS_HUD);
	RB_CheckTessOverflow(4, 6);
	vertCount = tess.vertexCount;
	indexCount = tess.indexCount;
	tess.vertexCount += 4;
	tess.indexCount += 6;
	tess.indices[indexCount] = vertCount + 3;
	tess.indices[indexCount + 1] = vertCount;
	tess.indices[indexCount + 2] = vertCount + 2;
	tess.indices[indexCount + 3] = vertCount + 2;
	tess.indices[indexCount + 4] = vertCount;
	tess.indices[indexCount + 5] = vertCount + 1;
	R_SetVertex2d(
		&tess.verts[vertCount],
		xyz->y,
		xyz->z,
		st->v[0],
		st->v[1],
		color->packed);
	R_SetVertex2d(
		&tess.verts[vertCount],
		xyz[1].y,
		xyz[1].z,
		st[1].v[0],
		st[1].v[1],
		color->packed);
	R_SetVertex2d(
		&tess.verts[vertCount],
		xyz[2].y,
		xyz[2].z,
		st[2].v[0],
		st[2].v[1],
		color->packed);
	R_SetVertex2d(
		&tess.verts[vertCount],
		xyz[3].y,
		xyz[3].z,
		st[3].v[0],
		st[3].v[1],
		color->packed);
	if (tess.indexCount)
	{
		RB_EndTessSurface();
	}
	if (!isUI3D && (stencilWrite || stencilValue))
	{
		gfxCmdBufContext.state->blendState = 0;
		gfxCmdBufContext.state->depthStencilState = 0;
		gfxCmdBufContext.state->rasterizerState = 0;
	}
}

/*
==============
RB_DrawEmblemLayer
==============
*/
void RB_DrawEmblemLayer(GfxRenderCommandExecState *execState)
{
	GfxCmdDrawEmblemLayer* cmd;
	bool isUI3D;

	cmd = (GfxCmdDrawEmblemLayer*)execState->cmd;
	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;

	if (cmd->header.ui3d >= 0 || (cmd->header.ui3d & 0x7Fu) >= 6)
	{
		isUI3D = 0;
	}
	else
	{
		isUI3D = 1;
		if ((*(__int8*)&cmd->bits & 1) != 0)
		{
			AssertMsg("stencilled UI3D in backend");
			return;
		}
	}

	RB_SetTessTechnique(cmd->material, 2);
	gfxCmdBufSourceState.input.codeImages[28] = cmd->image;
	gfxCmdBufSourceState.input.codeImageSamplerStates[28] = 98;
	R_UpdateCodeConstant(&gfxCmdBufSourceState, 204, 0.0, cmd->smoothSize, cmd->outlineSize, 0.0);
	R_SetupPass(gfxCmdBufContext, 0);
	assert(gfxCmdBufContext.state->technique->passCount == 1);
	RB_DrawUIQuadsInternal(*(__int8*)&cmd->bits & 1, cmd->stencilValue, isUI3D, 1, cmd->quad.xyz, cmd->quad.st, &cmd->quad.color);
}

/*
==============
RB_StretchCompositeCmd
==============
*/
void RB_StretchCompositeCmd(GfxRenderCommandExecState *execState)
{
	GfxCmdStretchComposite* cmd;
	bool isUI3D;

	cmd = (GfxCmdStretchComposite*)execState->cmd;
	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;

	if (cmd->header.ui3d >= 0 || (cmd->header.ui3d & 0x7Fu) >= 6)
	{
		isUI3D = 0;
	}
	else
	{
		isUI3D = 1;
		if ((*(__int8*)&cmd->bits & 1) != 0)
		{
			AssertMsg("stencilled UI3D in backend");
			return;
		}
	}

	gfxCmdBufSourceState.input.codeImages[39] = cmd->image;
	gfxCmdBufSourceState.input.codeImageSamplerStates[39] = 114;
	RB_SetTessTechnique(rgp.compositeResult, 2u);
	R_SetupPass(gfxCmdBufContext, 0);
	assert(gfxCmdBufContext.state->technique->passCount == 1);
	RB_DrawUIQuadsInternal(*(__int8*)&cmd->bits & 1, cmd->stencilValue, isUI3D, 1, cmd->quad.xyz, cmd->quad.st, &cmd->quad.color);
}

/*
==============
RB_DrawFullScreenColoredQuadCmd
==============
*/
void RB_DrawFullScreenColoredQuadCmd(GfxRenderCommandExecState *execState)
{
	GfxCmdDrawFullScreenColoredQuad* cmd;

	cmd = (GfxCmdDrawFullScreenColoredQuad*)execState->cmd;

	if (tess.indexCount)
	{
		RB_EndTessSurface();
	}
	R_Set2D(&gfxCmdBufSourceState);
	RB_DrawStretchPic(cmd->material, 0.0f, 0.0f, gfxCmdBufSourceState.renderTargetWidth, gfxCmdBufSourceState.renderTargetHeight, cmd->s0, cmd->t0, cmd->s1, cmd->t1, cmd->color.packed, 
		GFX_PRIM_STATS_CODE);
}

/*
==============
TessQuad
==============
*/
void TessQuad(unsigned __int16 v0, unsigned __int16 v1, unsigned __int16 v2, unsigned __int16 v3)
{
	tess.indices[tess.indexCount] = v0 + tess.vertexCount;
	tess.indices[tess.indexCount + 1] = v1 + tess.vertexCount;
	tess.indices[tess.indexCount + 2] = v2 + tess.vertexCount;
	tess.indexCount += 3;

	tess.indices[tess.indexCount] = v0 + tess.vertexCount;
	tess.indices[tess.indexCount + 1] = v2 + tess.vertexCount;
	tess.indices[tess.indexCount + 2] = v3 + tess.vertexCount;
	tess.indexCount += 3;
}

/*
==============
RB_DrawFramedCmd
==============
*/
void RB_DrawFramedCmd(GfxRenderCommandExecState *execState)
{
	float t[4];
	unsigned short vertexCount;
	int row;
	float s[4];
	float x[4];
	float y[4];
	const GfxCmdDrawFramed2D* cmd;
	int col;

	cmd = (const GfxCmdDrawFramed2D*)execState->cmd;
	assert(gfxCmdBufSourceState.viewMode == VIEW_MODE_2D);
	RB_SetTessTechnique(cmd->material, 4);
	RB_TrackPrimsBegin(&gfxCmdBufState.prim.frameStats, GFX_PRIM_STATS_HUD);
	RB_CheckTessOverflow(16, 48);
	vertexCount = tess.vertexCount;
	x[0] = cmd->x;
	x[3] = cmd->x + cmd->w;

	if (cmd->sides & 1)
	{
		x[1] = cmd->x + cmd->thicknessW;
	}
	else
	{
		x[1] = cmd->x;
	}
	if (cmd->sides & 2)
	{
		x[2] = (float)(cmd->x + cmd->w) - cmd->thicknessW;
	}
	else
	{
		x[2] = cmd->x + cmd->w;
	}

	y[0] = cmd->y;
	y[3] = cmd->y + cmd->h;
	if (cmd->sides & 4)
	{
		y[1] = cmd->y + cmd->thicknessH;
	}
	else
	{
		y[1] = cmd->y;
	}
	if (cmd->sides & 8)
	{
		y[2] = (float)(cmd->y + cmd->h) - cmd->thicknessH;
	}
	else
	{
		y[2] = cmd->y + cmd->h;
	}

	s[0] = 0.0f;
	s[3] = 1.0f;
	s[1] = cmd->thicknessTex;
	s[2] = 1.0 - cmd->thicknessTex;
	t[0] = 0.0f;
	t[3] = 1.0f;
	t[1] = cmd->thicknessTex;
	t[2] = 1.0 - cmd->thicknessTex;
	for (row = 0; row < 4; ++row)
	{
		for (col = 0; col < 4; ++col)
		{
			R_SetVertex2d(&tess.verts[vertexCount++], x[col], y[row], s[col], t[row], cmd->color.packed);
		}
	}
	if (cmd->sides & 4)
	{
		if (cmd->sides & 1)
		{
			TessQuad(0, 1, 5, 4);
		}
		TessQuad(1, 2, 6, 5);
		if (cmd->sides & 2)
		{
			TessQuad(2, 3, 7, 6);
		}
	}
	if (cmd->sides & 1)
	{
		TessQuad(4, 5, 9, 8);
	}
	TessQuad(5, 6, 0xAu, 9);
	if (cmd->sides & 2)
	{
		TessQuad(6, 7, 0xBu, 0xAu);
	}
	if (cmd->sides & 8)
	{
		if (cmd->sides & 1)
		{
			TessQuad(8, 9, 0xDu, 0xCu);
		}
		TessQuad(9, 0xAu, 0xEu, 0xDu);
		if (cmd->sides & 2)
		{
			TessQuad(0xAu, 0xBu, 0xFu, 0xEu);
		}
	}
	tess.vertexCount = vertexCount;
	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_ConstantSetCmd
==============
*/
void RB_ConstantSetCmd(GfxRenderCommandExecState *execState)
{
	GfxCmdConstantSet* cmd;

	cmd = (GfxCmdConstantSet*)execState->cmd;

	if (tess.indexCount)
	{
		RB_EndTessSurface();
	}
	RB_ApplyShaderConstantSet(&gfxCmdBufSourceState, &cmd->scs);
	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
R_RenderDrawSurfStaticModelListMaterial
==============
*/
unsigned int R_RenderDrawSurfStaticModelListMaterial(GfxCmdBufContext context, const GfxDrawSurfListInfo *info, unsigned int firstDrawSurfIndex)
{
	GfxDrawSurf drawSurf;
	const unsigned int* primDrawSurfPos;
	unsigned int i, remainingSurfs;

	remainingSurfs = info->drawSurfCount - firstDrawSurfIndex;
	assert(*((unsigned int*)&info->drawSurfs[firstDrawSurfIndex]) != 0xb0b0b0b0);
	drawSurf = info->drawSurfs[firstDrawSurfIndex];

	if (R_SetLitTechniqueNoShaderConstantSet(context, info, info->drawSurfs[firstDrawSurfIndex]))
	{
		R_SetPixPrimarySortKey(context.state, drawSurf.fields.primarySortKey);
		R_BeginPixMaterial(context.state);
		assert(context.local.state->technique->passCount == 1);
		R_SetupPass(context, 0);
		assert(drawSurf.fields.surfType == SF_STATICMODEL_RIGID || drawSurf.fields.surfType == SF_STATICMODEL_RIGID_NO_SUN_SHADOW || drawSurf.fields.surfType == SF_STATICMODEL_SKINNED);
		R_SetupPassCriticalPixelShaderArgs(context);
		assert(info->baseTechType == TECHNIQUE_LIT || info->baseTechType == TECHNIQUE_UNLIT || info->baseTechType == TECHNIQUE_DEBUG_BUMPMAP);

		primDrawSurfPos = &context.source->input.data->primDrawSurfsBuf[(unsigned __int16)*(int*)&info->drawSurfs[firstDrawSurfIndex].fields];
		RB_TrackPrimsBegin(&context.state->prim.frameStats, GFX_PRIM_STATS_SMODELRIGID);
		if (drawSurf.fields.surfType == SF_STATICMODEL_SKINNED)
		{
			R_DrawStaticModelSkinnedSurfLit(primDrawSurfPos, context, info);
		}
		else
		{
			R_SetupPassPerObjectArgs(context);
			R_DrawStaticModelSurfLit(primDrawSurfPos, context, info);
		}
		RB_TrackPrimsEnd(&context.state->prim.frameStats);
		R_EndPixMaterial(context.state);
		return 1;
	}
	else
	{

		for (i = 0; i < remainingSurfs; ++i)
		{
			if ((*(int*)&info->drawSurfs[firstDrawSurfIndex + i].fields & 0xC0000000) != (*(int*)&info->drawSurfs[firstDrawSurfIndex].fields & 0xC0000000))
			{
				break;
			}
			if (info->drawSurfs[firstDrawSurfIndex + i].packed != info->drawSurfs[firstDrawSurfIndex].packed)
			{
				break;
			}
		}
		return i;
	}
}

/*
==============
R_RenderDrawSurfBspListMaterial
==============
*/
unsigned int R_RenderDrawSurfBspListMaterial(GfxCmdBufContext context, const GfxDrawSurfListInfo* info, unsigned int firstDrawSurfIndex)
{
	GfxDrawSurf drawSurf;
	const unsigned int* primDrawSurfPos;
	unsigned int i, remainingSurfs;

	remainingSurfs = info->drawSurfCount - firstDrawSurfIndex;
	assert(*((unsigned int*)&info->drawSurfs[firstDrawSurfIndex]) != 0xb0b0b0b0);
	drawSurf = info->drawSurfs[firstDrawSurfIndex];

	if (R_SetLitTechniqueNoShaderConstantSet(context, info, info->drawSurfs[firstDrawSurfIndex]))
	{
		R_SetPixPrimarySortKey(context.state, drawSurf.fields.primarySortKey);
		R_BeginPixMaterial(context.state);
		assert(context.local.state->technique->passCount == 1);
		R_SetupPass(context, 0);
		assert(drawSurf.fields.surfType == SF_TRIANGLES || drawSurf.fields.surfType == SF_TRIANGLES_NO_SUN_SHADOW);
		R_SetupPassCriticalPixelShaderArgs(context);
		assert(info->baseTechType == TECHNIQUE_LIT || info->baseTechType == TECHNIQUE_UNLIT || info->baseTechType == TECHNIQUE_DEBUG_BUMPMAP);

		primDrawSurfPos = &context.source->input.data->primDrawSurfsBuf[(unsigned __int16)*(int*)&info->drawSurfs[firstDrawSurfIndex].fields];
		RB_TrackPrimsBegin(&context.state->prim.frameStats, GFX_PRIM_STATS_WORLD);
		R_SetupPassPerObjectArgs(context);
		R_SetupPassPerPrimArgs(context);
		R_DrawBspDrawSurfsLit(primDrawSurfPos, context);
		RB_TrackPrimsEnd(&context.state->prim.frameStats);
		R_EndPixMaterial(context.state);
		return 1;
	}
	else
	{

		for (i = 0; i < remainingSurfs; ++i)
		{
			if ((*(int*)&info->drawSurfs[firstDrawSurfIndex + i].fields & 0xC0000000) != (*(int*)&info->drawSurfs[firstDrawSurfIndex].fields & 0xC0000000))
			{
				break;
			}
			if (info->drawSurfs[firstDrawSurfIndex + i].packed != info->drawSurfs[firstDrawSurfIndex].packed)
			{
				break;
			}
		}
		return i;
	}
}

/*
==============
R_RenderDrawSurfListMaterial
==============
*/
unsigned int R_RenderDrawSurfListMaterial(GfxDrawSurfListArgs *listArgs)
{
	int i;
	unsigned int firstDrawSurfIndex, passCount, drawSurfCount;
	const GfxDrawSurfListInfo* info;
	const GfxDrawSurf* drawSurfs;
	GfxCmdBufSourceState* source;

	firstDrawSurfIndex = listArgs->firstDrawSurfIndex;
	drawSurfCount = info->drawSurfCount - firstDrawSurfIndex;
	assert(*((unsigned int*)&listArgs->info->drawSurfs[firstDrawSurfIndex]) != 0xb0b0b0b0);
	drawSurfs = listArgs->info->drawSurfs;
	info = listArgs->info;

	ScopedShaderConstantSetUndo shaderConstantUndo(listArgs->context.source, RB_ShaderConstantSetFromDrawSurf(source->input.data, &drawSurfs[firstDrawSurfIndex]));
	if (listArgs->info->baseTechType == 0xFF)
	{
		MaterialTechniqueSet* localTechniqueSet = rgp.sortedMaterials[drawSurfs[firstDrawSurfIndex].fields.materialSortedIndex]->localTechniqueSet;
		if (localTechniqueSet->techniques[4])
		{
			listArgs->info->baseTechType = 4;
		}
		else if (localTechniqueSet->techniques[3])
		{
			listArgs->info->baseTechType = 3;
		}
	}
	if (R_SetTechnique(listArgs->context, listArgs->info, drawSurfs[firstDrawSurfIndex]))
	{
		R_SetPixPrimarySortKey(listArgs->context.state, drawSurfs[firstDrawSurfIndex].fields.primarySortKey);
		R_BeginPixMaterial(listArgs->context.state);
		passCount = listArgs->context.state->technique->passCount;
		for (int i = 0; i < passCount; ++i)
		{
			R_UpdateMaterialTime(listArgs->context.source, 0.0, 0.0);
			R_SetupPass(listArgs->context, i);
		}
		R_EndPixMaterial(listArgs->context.state);
		return rb_tessTable[(drawSurfs[firstDrawSurfIndex].fields.surfType) & 0xF](listArgs);
	}
	else
	{
		for (i = 0; i < drawSurfCount; ++i)
		{
			if ((*(int*)&info->drawSurfs[firstDrawSurfIndex + i].fields & 0xC0000000) != (*(int*)&info->drawSurfs[firstDrawSurfIndex].fields & 0xC0000000))
			{
				break;
			}
			if (info->drawSurfs[firstDrawSurfIndex + i].packed != info->drawSurfs[firstDrawSurfIndex].packed)
			{
				break;
			}
		}
		return i;
	}
}

/*
==============
R_SetCustomCodeConstants
==============
*/
void R_SetCustomCodeConstants(GfxCmdBufContext context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
R_DrawSurfs
==============
*/
void R_DrawSurfs(GfxCmdBufContext context, const GfxDrawSurfListInfo *info)
{
	unsigned int drawMatCount;
	GfxViewport viewport;
	GfxDrawSurfListArgs listArgs;
	const GfxUI3DBackend* p_rbUI3D;
	const GfxQRCodeBackend* p_rbQRCode;
	vec4_t swrk_override_characterDissolveColor;

	assert(context.local.source->cameraView == info->cameraView);
	R_Set3D(context.source);
	if (context.source->viewportIsDirty)
	{
		R_GetViewport(context.source, &viewport);
		R_SetViewport(context.state, &viewport);
		R_UpdateViewport(context.source, &viewport);
	}
	assert(dx.device);
	if (context.state->prim.device != dx.context)
	{
		PIXBeginNamedEvent(-1, "draw surf %d", info->drawSurfCount);
	}
	R_BeginPixMaterials(context.state);
	R_SetCustomCodeConstants(context);
	context.source->input.consts[CONST_SRC_CODE_CHARACTER_CHARRED_AMOUNT].v[0] = 0.0;
	context.source->input.consts[CONST_SRC_CODE_CHARACTER_CHARRED_AMOUNT].v[1] = 0.0;
	context.source->input.consts[CONST_SRC_CODE_CHARACTER_CHARRED_AMOUNT].v[2] = 0.0;
	context.source->input.consts[CONST_SRC_CODE_CHARACTER_CHARRED_AMOUNT].v[3] = 0.0;
	++context.source->constVersions[CONST_SRC_CODE_CHARACTER_CHARRED_AMOUNT];

	context.source->input.consts[CONST_SRC_CODE_CHARACTER_DISSOLVE_COLOR].v[0] = 0.0;
	context.source->input.consts[CONST_SRC_CODE_CHARACTER_DISSOLVE_COLOR].v[1] = 0.0;
	context.source->input.consts[CONST_SRC_CODE_CHARACTER_DISSOLVE_COLOR].v[2] = 0.0;
	context.source->input.consts[CONST_SRC_CODE_CHARACTER_DISSOLVE_COLOR].v[3] = 0.0;
	++context.source->constVersions[CONST_SRC_CODE_CHARACTER_DISSOLVE_COLOR];

	Dvar_GetVec4(r_swrk_override_characterDissolveColor, &swrk_override_characterDissolveColor);
	context.source->input.consts[CONST_SRC_CODE_CHARACTER_DISSOLVE_COLOR].v[0] = swrk_override_characterDissolveColor.v[0];
	context.source->input.consts[CONST_SRC_CODE_CHARACTER_DISSOLVE_COLOR].v[1] = swrk_override_characterDissolveColor.v[1];
	context.source->input.consts[CONST_SRC_CODE_CHARACTER_DISSOLVE_COLOR].v[2] = swrk_override_characterDissolveColor.v[2];
	context.source->input.consts[CONST_SRC_CODE_CHARACTER_DISSOLVE_COLOR].v[3] = swrk_override_characterDissolveColor.v[3];
	++context.source->constVersions[CONST_SRC_CODE_CHARACTER_DISSOLVE_COLOR];

	p_rbUI3D = 0;
	if (info->viewInfo)
	{
		p_rbUI3D = &info->viewInfo->rbUI3D;
	}
	RB_UI3D_SetShaderConstants(context.source, p_rbUI3D);

	p_rbQRCode = 0;
	if (info->viewInfo)
	{
		p_rbQRCode = &info->viewInfo->rbQRCode;
	}
	RB_QRCode_SetShaderConstants(context.source, p_rbQRCode);

	listArgs.context = context;
	listArgs.firstDrawSurfIndex = 0;
	listArgs.info = (GfxDrawSurfListInfo*)info;

	for (drawMatCount = 0; listArgs.firstDrawSurfIndex != info->drawSurfCount; ++drawMatCount)
	{
		listArgs.firstDrawSurfIndex += R_RenderDrawSurfListMaterial(&listArgs);
	}
	RB_TrackDrawSurfMat(&context.state->prim.frameStats, info->drawSurfCount, drawMatCount);

	R_EndPixMaterial(context.state);
	if (context.state->prim.device != dx.context && Sys_IsRenderThread())
	{
		D3DPERF_EndEvent();
	}
	context.source->objectPlacement = 0;
	R_ChangeDepthHackNearClip(context.source, 0);
	if (((context.source->cameraView != 0) - 1) != context.state->depthRangeType)
	{
		R_ChangeDepthRange(context.state, (GfxDepthRangeType)((context.source->cameraView != 0) - 1));
	}
}

/*
==============
R_DrawSurfsBsp
==============
*/
void R_DrawSurfsBsp(GfxCmdBufContext context, const GfxDrawSurfListInfo *info)
{
	unsigned __int8 sampState;
	unsigned int drawSurfCount;
	unsigned int drawSurfIndex;
	int drawMatCount;
	GfxViewport viewport;
	ID3D11Buffer* indexBuffer;

	assert(context.local.source->cameraView == info->cameraView);

	R_Set3D(context.source);
	if (context.source->viewportIsDirty)
	{
		R_GetViewport(context.source, &viewport);
		R_SetViewport(context.state, &viewport);
		R_UpdateViewport(context.source, &viewport);
	}
	R_SetCustomCodeConstants(context);
	R_UpdateMaterialTime(context.source, 0.0, 0.0);
	R_SetObjectIdentityPlacement(context.source);
	R_ChangeDepthHackNearClip(context.source, 0);

	if ((context.source->cameraView != 0) - 1 != context.state->depthRangeType)
	{
		R_ChangeDepthRange(context.state, (GfxDepthRangeType)((context.source->cameraView != 0) - 1));
	}
	sampState = 97;
	if (!Dvar_GetBool(r_lightMapFilterDisable))
	{
		sampState = 98;
	}
	if (context.state->samplerState[13] != sampState)
	{
		context.state->samplerState[13] = sampState;
		R_HW_ForceSamplerState(context.state->prim.device, 0xDu, sampState);
	}
	if (context.state->samplerState[15] != 114)
	{
		context.state->samplerState[15] = 114;
		R_HW_ForceSamplerState(context.state->prim.device, 0xFu, 0x72u);
	}
	assert(dx.device);
	indexBuffer = g_worldDraw->indexBuffer;
	if (context.state->prim.indexBuffer != indexBuffer)
	{
		R_ChangeIndices(&context.state->prim, indexBuffer);
	}
	if (context.state->prim.device != dx.context)
	{
		PIXBeginNamedEvent(-1, "draw surf bsp %d", info->drawSurfCount);
	}

	R_BeginPixMaterials(context.state);
	if (info->drawSurfCount)
	{
		for (drawMatCount = 0; drawSurfIndex != drawSurfCount; ++drawMatCount)
		{
			drawSurfIndex += R_RenderDrawSurfBspListMaterial(context, info, drawSurfIndex);
		}
	}
	RB_TrackDrawSurfMat(&context.state->prim.frameStats, info->drawSurfCount, drawMatCount);
	R_EndPixMaterials(context.state);
	if (context.state->prim.device != dx.context && Sys_IsRenderThread())
	{
		D3DPERF_EndEvent();
	}
	context.source->objectPlacement = 0;
	R_ChangeDepthHackNearClip(context.source, 0);
	if (((context.source->cameraView != 0) - 1) != context.state->depthRangeType)
	{
		R_ChangeDepthRange(context.state, (GfxDepthRangeType)((context.source->cameraView != 0) - 1));
	}
}

/*
==============
R_DrawSurfsStaticModel
==============
*/
void R_DrawSurfsStaticModel(GfxCmdBufContext context, const GfxDrawSurfListInfo *info)
{
	ID3D11DeviceContext* device;
	unsigned int drawSurfCount;
	unsigned int drawSurfIndex;
	int drawMatCount;
	GfxViewport viewport;

	assert(context.local.source->cameraView == info->cameraView);

	R_Set3D(context.source);
	if (context.source->viewportIsDirty)
	{
		R_GetViewport(context.source, &viewport);
		R_SetViewport(context.state, &viewport);
		R_UpdateViewport(context.source, &viewport);
	}
	R_SetCustomCodeConstants(context);
	R_UpdateMaterialTime(context.source, 0.0, 0.0);
	R_ChangeDepthHackNearClip(context.source, 0);
	if ((context.source->cameraView != 0) - 1 != context.state->depthRangeType)
	{
		R_ChangeDepthRange(context.state, (GfxDepthRangeType)((context.source->cameraView != 0) - 1));
	}
	context.source->objectPlacement = &s_manualObjectPlacement;
	if (context.state->samplerState[15] != 114)
	{
		device = context.state->prim.device;
		context.state->samplerState[15] = 114;
		R_HW_ForceSamplerState(device, 0xFu, 0x72u);
	}
	assert(dx.device);
	if (context.state->prim.device != dx.context)
	{
		PIXBeginNamedEvent(-1, "draw surf %d", info->drawSurfCount);
	}
	R_BeginPixMaterials(context.state);

	if (info->drawSurfCount)
	{
		for (drawMatCount = 0; drawSurfIndex != drawSurfCount; ++drawMatCount)
		{
			drawSurfIndex += R_RenderDrawSurfStaticModelListMaterial(context, info, drawSurfIndex);
		}
	}
	RB_TrackDrawSurfMat(&context.state->prim.frameStats, info->drawSurfCount, drawMatCount);
	R_EndPixMaterials(context.state);
	if (context.state->prim.device != dx.context && Sys_IsRenderThread())
	{
		D3DPERF_EndEvent();
	}

	context.source->objectPlacement = 0;
	R_ChangeDepthHackNearClip(context.source, 0);
	if (((context.source->cameraView != 0) - 1) != context.state->depthRangeType)
	{
		R_ChangeDepthRange(context.state, (GfxDepthRangeType)((context.source->cameraView != 0) - 1));
	}
}

/*
==============
RB_ClearScreenCmd
==============
*/
void RB_ClearScreenCmd(GfxRenderCommandExecState *execState)
{
	GfxCmdClearScreen* cmd;

	cmd = (GfxCmdClearScreen*)execState->cmd;

	if (tess.indexCount)
	{
		RB_EndTessSurface();
	}
	R_ClearScreen(&gfxCmdBufState, cmd->whichToClear, &cmd->color, cmd->depth, cmd->stencil);

	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_SetGammaRamp
==============
*/
void RB_SetGammaRamp(GfxGammaRamp* gammaTable)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_BlendSavedScreenFlashedCmd
==============
*/
void RB_BlendSavedScreenFlashedCmd(GfxRenderCommandExecState *execState)
{
	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_DrawPoints2D
==============
*/
void RB_DrawPoints2D(const GfxCmdDrawPoints *cmd)
{
	float size;
	int pointIndex;

	assert(gfxCmdBufSourceState.viewMode == VIEW_MODE_2D);
	RB_SetTessTechnique(rgp.whiteMaterial, 2u);
	RB_TrackPrimsBegin(&gfxCmdBufState.prim.frameStats, GFX_PRIM_STATS_DEBUG);
	size = cmd->size * 0.5f;
	pointIndex = 0;
	for (pointIndex = 0; pointIndex < cmd->pointCount; ++pointIndex)
	{
		RB_CheckTessOverflow(4, 6);
		tess.indices[tess.indexCount] = tess.vertexCount + 1;
		tess.indices[tess.indexCount + 1] = tess.vertexCount;
		tess.indices[tess.indexCount + 2] = tess.vertexCount + 2;
		tess.indices[tess.indexCount + 3] = tess.vertexCount + 2;
		tess.indices[tess.indexCount + 4] = tess.vertexCount;
		tess.indices[tess.indexCount + 5] = tess.vertexCount + 3;
		tess.indexCount += 6;
		R_SetVertex4d(
			&tess.verts[tess.vertexCount + 0],
			cmd->verts[pointIndex].xyz.v[0] - size,
			cmd->verts[pointIndex].xyz.v[1] - size,
			cmd->verts[pointIndex].xyz.v[2],
			1.0f,
			0.0f,
			0.0f,
			*(int*)cmd->verts[pointIndex].color);
		R_SetVertex4d(
			&tess.verts[tess.vertexCount + 1],
			cmd->verts[pointIndex].xyz.v[0] - size,
			cmd->verts[pointIndex].xyz.v[1] + size,
			cmd->verts[pointIndex].xyz.v[2],
			1.0f,
			0.0f,
			1.0f,
			*(int*)cmd->verts[pointIndex].color);
		R_SetVertex4d(
			&tess.verts[tess.vertexCount + 2],
			cmd->verts[pointIndex].xyz.v[0] + size,
			cmd->verts[pointIndex].xyz.v[1] + size,
			cmd->verts[pointIndex].xyz.v[2],
			1.0f,
			1.0f,
			1.0f,
			*(int*)cmd->verts[pointIndex].color);
		R_SetVertex4d(
			&tess.verts[tess.vertexCount + 3],
			cmd->verts[pointIndex].xyz.v[0] + size,
			cmd->verts[pointIndex].xyz.v[1] - size,
			cmd->verts[pointIndex].xyz.v[2],
			1.0f,
			1.0f,
			0.0f,
			*(int*)cmd->verts[pointIndex].color);
		tess.vertexCount += 4;
	}
}

/*
==============
RB_DrawPoints3D
==============
*/
void RB_DrawPoints3D(const GfxCmdDrawPoints *cmd)
{
	GfxViewParms* viewParms3D;
	float invWidth;
	float invHeight;
	int pointIndex;
	float xyz, xyz_4, xyz_8, xyz_12;

	RB_SetTessTechnique(rgp.pointMaterial, 2u);
	RB_TrackPrimsBegin(&gfxCmdBufState.prim.frameStats, GFX_PRIM_STATS_DEBUG);
	RB_SetIdentity();

	viewParms3D = (GfxViewParms*)gfxCmdBufSourceState.viewParms3D;
	invWidth = cmd->size / gfxCmdBufSourceState.renderTargetWidth;
	invHeight = cmd->size / gfxCmdBufSourceState.renderTargetHeight;

	for (pointIndex = 0; pointIndex < cmd->pointCount; ++pointIndex)
	{
		xyz = (((cmd->verts[pointIndex].xyz.x * viewParms3D->viewProjectionMatrix.m[0].v[0]) + (cmd->verts[pointIndex].xyz.y * viewParms3D->viewProjectionMatrix.m[1].v[0])) + (cmd->verts[pointIndex].xyz.z * viewParms3D->viewProjectionMatrix.m[2].v[0])) + viewParms3D->viewProjectionMatrix.m[3].v[0];
		xyz_4 = (((cmd->verts[pointIndex].xyz.x * viewParms3D->viewProjectionMatrix.m[0].v[1]) + (cmd->verts[pointIndex].xyz.y * viewParms3D->viewProjectionMatrix.m[1].v[1])) + (cmd->verts[pointIndex].xyz.z * viewParms3D->viewProjectionMatrix.m[2].v[1])) + viewParms3D->viewProjectionMatrix.m[3].v[1];
		xyz_12 = (((cmd->verts[pointIndex].xyz.x * viewParms3D->viewProjectionMatrix.m[0].v[3]) + (cmd->verts[pointIndex].xyz.y * viewParms3D->viewProjectionMatrix.m[1].v[3])) + (cmd->verts[pointIndex].xyz.z * viewParms3D->viewProjectionMatrix.m[2].v[3])) + viewParms3D->viewProjectionMatrix.m[3].v[3];
		xyz_8 = (xyz_12 * 0.001) + ((((viewParms3D->viewProjectionMatrix.m[0].v[2] * cmd->verts[pointIndex].xyz.x) + (viewParms3D->viewProjectionMatrix.m[1].v[2] * cmd->verts[pointIndex].xyz.y)) + (cmd->verts[pointIndex].xyz.z * viewParms3D->viewProjectionMatrix.m[2].v[2])) + viewParms3D->viewProjectionMatrix.m[3].v[2]);

		RB_CheckTessOverflow(4, 6);
		tess.indices[tess.indexCount] = tess.vertexCount + 3;
		tess.indices[tess.indexCount + 1] = tess.vertexCount;
		tess.indices[tess.indexCount + 2] = tess.vertexCount + 2;
		tess.indices[tess.indexCount + 3] = tess.vertexCount + 2;
		tess.indices[tess.indexCount + 4] = tess.vertexCount;
		tess.indices[tess.indexCount + 5] = tess.vertexCount + 1;
		tess.indexCount += 6;

		R_SetVertex4d(
			&tess.verts[tess.vertexCount],
			xyz - (invWidth * xyz_12),
			xyz_4 - (invHeight * xyz_12),
			xyz_8,
			xyz_12,
			0.0,
			0.0,
			*(int*)cmd->verts[pointIndex].color);
		R_SetVertex4d(
			&tess.verts[tess.vertexCount + 1],
			xyz - (invWidth * xyz_12),
			xyz_4 + (invHeight * xyz_12),
			xyz_8,
			xyz_12,
			0.0,
			1.0,
			*(int*)cmd->verts[pointIndex].color);
		R_SetVertex4d(
			&tess.verts[tess.vertexCount + 2],
			xyz + (invWidth * xyz_12),
			xyz_4 + (invHeight * xyz_12),
			xyz_8,
			xyz_12,
			1.0,
			1.0,
			*(int*)cmd->verts[pointIndex].color);
		R_SetVertex4d(
			&tess.verts[tess.vertexCount + 3],
			xyz + (invWidth * xyz_12),
			xyz_4 - (invHeight * xyz_12),
			xyz_8,
			xyz_12,
			1.0,
			0.0,
			*(int*)cmd->verts[pointIndex].color);
		tess.vertexCount += 4;
	}
	RB_EndTessSurface();
}

/*
==============
RB_DrawPointsCmd
==============
*/
void RB_DrawPointsCmd(GfxRenderCommandExecState *execState)
{
	GfxCmdDrawPoints* cmd;

	cmd = (GfxCmdDrawPoints*)execState->cmd;

	if (cmd->dimensions == 2)
	{
		RB_DrawPoints2D(cmd);
	}
	else
	{
		assert((cmd->dimensions == 3));
		RB_DrawPoints3D(cmd);
	}
	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_DrawLines2D
==============
*/
void RB_DrawLines2D(int count, int width, const GfxPointVertex *verts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_DrawLines3D
==============
*/
void RB_DrawLines3D(int count, int width, const GfxPointVertex *verts, bool depthTest)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_DrawLinesCmd
==============
*/
void RB_DrawLinesCmd(GfxRenderCommandExecState *execState)
{
	GfxCmdDrawLines* cmd;

	cmd = (GfxCmdDrawLines*)execState->cmd;

	if (cmd->dimensions == 2)
	{
		RB_DrawLines2D(cmd->lineCount, cmd->width, cmd->verts);
	}
	else
	{
		assertMsg((cmd->dimensions == 3), "(cmd->dimensions) = %i", cmd->dimensions);
		RB_DrawLines3D(cmd->lineCount, cmd->width, cmd->verts, true);
	}

	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_DrawTriangles_Internal
==============
*/
void RB_DrawTriangles_Internal(const Material *material, unsigned __int8 techType, __int16 indexCount, const unsigned __int16 *indices, __int16 vertexCount, const vec4_t *xyzw, const vec3_t *normal, const GfxColor *color, const vec2_t *st)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_DrawUIQuadsCmd
==============
*/
void RB_DrawUIQuadsCmd(char *a1, GfxRenderCommandExecState *execState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_DrawUIQuadsReplaceImageCmd
==============
*/
void RB_DrawUIQuadsReplaceImageCmd(char *a1, GfxRenderCommandExecState *execState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_DrawUITrianglesCmd
==============
*/
void RB_DrawUITrianglesCmd(GfxRenderCommandExecState *execState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_DrawTrianglesCmd
==============
*/
void RB_DrawTrianglesCmd(GfxRenderCommandExecState *execState)
{
	const GfxCmdDrawTriangles* cmd;

	if (tess.indexCount)
	{
		RB_EndTessSurface();
	}

	cmd = (GfxCmdDrawTriangles*)execState->cmd;
	RB_DrawTriangles_Internal(cmd->material, cmd->techType, cmd->indexCount, (unsigned short*)cmd->indexCount, cmd->vertexCount, &cmd->xyzw, &cmd->normal, &cmd->color, &cmd->st);

	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_SetCustomConstantCmd
==============
*/
void RB_SetCustomConstantCmd(GfxRenderCommandExecState *execState)
{
	const GfxCmdSetCustomConstant* cmd;

	if (tess.indexCount)
	{
		RB_EndTessSurface();
	}

	cmd = (GfxCmdSetCustomConstant*)execState->cmd;
	R_SetCodeConstantFromVec4(&gfxCmdBufSourceState, cmd->type, &cmd->vec);

	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_SetMaterialColorCmd
==============
*/
void RB_SetMaterialColorCmd(GfxRenderCommandExecState *execState)
{
	const GfxCmdSetMaterialColor* cmd;
	int i;

	if (tess.indexCount)
	{
		RB_EndTessSurface();
	}

	cmd = (GfxCmdSetMaterialColor*)execState->cmd;
	for (i = 0; i < 3; ++i)
	{
		gfxCmdBufSourceState.input.consts[46].v[i] = cmd->color.v[i];
	}
	++gfxCmdBufSourceState.constVersions[46];

	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_BeginViewCmd
==============
*/
void RB_BeginViewCmd(GfxRenderCommandExecState *execState)
{
	const GfxCmdBeginView* cmd;

	if (tess.indexCount)
	{
		RB_EndTessSurface();
	}

	cmd = (GfxCmdBeginView*)execState->cmd;
	R_BeginView(&gfxCmdBufSourceState, &cmd->sceneDef, cmd->viewParms);

	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_SetViewportCmd
==============
*/
void RB_SetViewportCmd(GfxRenderCommandExecState *execState)
{
	const GfxCmdSetViewport* cmd;

	if (tess.indexCount)
	{
		RB_EndTessSurface();
	}

	cmd = (GfxCmdSetViewport*)execState->cmd;
	R_SetViewportStruct(&gfxCmdBufSourceState, &cmd->viewport);

	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_SetScissorCmd
==============
*/
void RB_SetScissorCmd(GfxRenderCommandExecState *execState)
{
	const GfxCmdSetScissor* cmd;

	if (tess.indexCount)
	{
		RB_EndTessSurface();
	}

	cmd = (const GfxCmdSetScissor*)execState->cmd;
	if (cmd->enabled)
	{
		R_SetScissorStruct(&gfxCmdBufSourceState, &cmd->scissor);
	}
	else
	{
		R_ClearScissorStruct(&gfxCmdBufSourceState);
	}

	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_ResolveCompositeCmd
==============
*/
void RB_ResolveCompositeCmd(GfxRenderCommandExecState *execState)
{
	const GfxCmdResolveComposite* cmd;

	if (tess.indexCount)
	{
		RB_EndTessSurface();
	}

	cmd = (const GfxCmdResolveComposite*)execState->cmd;
	R_SetRenderTargetSize(&gfxCmdBufSourceState, r_glob.frameBuffer);
	R_SetRenderTarget(gfxCmdBufContext, r_glob.frameBuffer);
	cmd->callback(gfxRenderTargets[25].image);

	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_PCCopyImageGenMIPCmd
==============
*/
void RB_PCCopyImageGenMIPCmd(GfxRenderCommandExecState *execState)
{
	const GfxCmdPCCopyImageGenMIP* cmd;
	D3D11_SHADER_RESOURCE_VIEW_DESC viewDesc;
	ID3D11Resource* resource;
	ID3D11Resource* dst;
	ID3D11Resource* src;
	ID3D11Texture2D* map;
	D3D11_TEXTURE2D_DESC desc;
	HRESULT hr;

	cmd = (const GfxCmdPCCopyImageGenMIP*)execState->cmd;

	cmd->image->texture.basemap->GetResource(&resource);
	map = reinterpret_cast<ID3D11Texture2D*>(resource);
	map->GetDesc(&desc);
	resource->Release();
	if (desc.Usage || desc.Width != 256 || desc.Height != 256)
	{
		cmd->image->texture.basemap->Release();
		desc.Width = 256;
		desc.Height = 256;
		desc.MipLevels = 0;
		desc.ArraySize = 1;
		desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		desc.SampleDesc.Count = 1;
		desc.SampleDesc.Quality = 0;
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.BindFlags = 40;
		desc.CPUAccessFlags = 0;
		desc.MiscFlags = 1;
		while (1)
		{
			hr = dx.device->CreateTexture2D(&desc, 0, &map);
			if (hr == S_OK)
			{
				break;
			}
			if (!alwaysfails)
			{
				map->SetPrivateData(WKPDID_D3DDebugObjectName, strlen(cmd->image->name), cmd->image->name);
				viewDesc.Buffer.FirstElement = -1;
				viewDesc.Buffer.ElementOffset = 0;
				viewDesc.Texture3D.MipLevels = 0;
				viewDesc.Texture3D.MostDetailedMip = 0;
				viewDesc.Format = desc.Format;
				viewDesc.ViewDimension = D3D_SRV_DIMENSION_TEXTURE2D;
				while (1)
				{
					hr = dx.device->CreateShaderResourceView(map, &viewDesc, &cmd->image->texture.basemap);
					if (hr == S_OK)
						break;
					if (!alwaysfails)
					{
						cmd->image->texture.basemap->SetPrivateData(WKPDID_D3DDebugObjectName, strlen(cmd->image->name), cmd->image->name);
						map->Release();
					}
				}
				while (alwaysfails)
				{
					++g_disableRendering;
					Com_Error(ERR_FATAL, __FILE__, " (%i) dx.device->CreateShaderResourceView(map, &image->texture.basemap) failed: %s\n", __LINE__, R_ErrorDescription(hr));
				}
			}
		}
		while (alwaysfails)
		{
			++g_disableRendering;
			Com_Error(ERR_FATAL, __FILE__, " (%i) dx.device->CreateTexture2D(&desc, 0, &map) failed: %s\n", __LINE__, R_ErrorDescription(hr));
		}
		map->SetPrivateData(WKPDID_D3DDebugObjectName, strlen(cmd->image->name), cmd->image->name);
		viewDesc.Buffer.FirstElement = -1;
		viewDesc.Buffer.ElementOffset = 0;
		viewDesc.Texture3D.MipLevels = 0;
		viewDesc.Texture3D.MostDetailedMip = 0;
		viewDesc.Format = desc.Format;
		viewDesc.ViewDimension = D3D_SRV_DIMENSION_TEXTURE2D;
		while (1)
		{
			hr = dx.device->CreateShaderResourceView(map, &viewDesc, &cmd->image->texture.basemap);
			if (hr == S_OK)
				break;
			if (!alwaysfails)
			{
				cmd->image->texture.basemap->SetPrivateData(WKPDID_D3DDebugObjectName, strlen(cmd->image->name), cmd->image->name);
				map->Release();
			}
		}
		while (alwaysfails)
		{
			++g_disableRendering;
			Com_Error(ERR_FATAL, __FILE__, " (%i) dx.device->CreateShaderResourceView(map, &image->texture.basemap) failed: %s\n", __LINE__, R_ErrorDescription(hr));
		}
		cmd->image->texture.basemap->SetPrivateData(WKPDID_D3DDebugObjectName, strlen(cmd->image->name), cmd->image->name);
		map->Release();
	}
	cmd->image->texture.basemap->GetResource(&dst);
	gfxRenderTargets[25].surface.color->GetResource(&src);
	dx.context->CopySubresourceRegion(dst, 0, 0, 0, 0, src, 0, 0);
	dx.context->GenerateMips(cmd->image->texture.basemap);
	dst->Release();
	src->Release();
	cmd->callback(cmd->job);

	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

const unsigned __int8 color_table[8][4] =
{
  { 0u, 0u, 0u, 255u },
  { 255u, 51u, 51u, 255u },
  { 0u, 255u, 0u, 255u },
  { 255u, 255u, 128u, 255u },
  { 0u, 0u, 255u, 255u },
  { 0u, 255u, 255u, 255u },
  { 255u, 92u, 255u, 255u },
  { 255u, 255u, 255u, 255u }
};

/*
==============
RB_LookupColor
==============
*/
void RB_LookupColor(unsigned __int8 c, unsigned __int8 *color)
{
	unsigned __int8 indexedColor;

	indexedColor = ColorIndex(c);
	if (indexedColor > 8u)
	{
		if (c == 56)
		{
			*color = rg.color_allies.packed;
		}
		else if (c == 57)
		{
			*color = rg.color_axis.packed;
		}
		else
		{
			*color = -1;
		}
	}
	else
	{
		*color = *&color_table[indexedColor][0];
	}
}

/*
==============
RB_DrawHudIcon
==============
*/
float RB_DrawHudIcon(const char *text, float x, float y, float sinAngle, float cosAngle, Font_s *font, float xScale, float yScale, unsigned int color)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RB_DrawButton
==============
*/
float RB_DrawButton(const char *text, float x, float y, float sinAngle, float cosAngle, Font_s *font, float xScale, float yScale, unsigned int color, int *buttonNameLen)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RB_DrawChar
==============
*/
int RB_DrawChar(unsigned int color, const Material *material, float x, float y, float w, float width, float height, float sinAngle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RB_DrawCursor
==============
*/
void RB_DrawCursor(const Material *material, unsigned __int8 cursor, float x, float y, float sinAngle, float cosAngle, Font_s *font, float xScale, float yScale, unsigned int color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GlowColor
==============
*/
void GlowColor(GfxColor *result, GfxColor baseColor, GfxColor forcedGlowColor, int renderFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SetupFadeinFXVars
==============
*/
bool SetupFadeinFXVars(const char *text, int maxLength, int renderFlags, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, bool *resultDrawRandChar, int *resultRandSeed, bool *resultDecaying, int *resultdecayTimeElapsed)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SetupCOD7DecodeFXVars
==============
*/
bool SetupCOD7DecodeFXVars(const char *text, int maxLength, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, int *randSeed, int *resultRandomCharsLength, int *resultMaxLength, bool *resultDecaying, int *resultDecayTimeElapsed)
{
	int textLen, timeElapsed;

	textLen = SEH_PrintStrlen(text);
	if (textLen > maxLength)
	{
		textLen = maxLength;
	}
	if (gfxCmdBufSourceState.sceneDef.time - fxBirthTime <= fxDecayDuration + fxDecayStartTime)
	{
		if (timeElapsed <= fxLetterTime * textLen || timeElapsed <= fxDecayStartTime)
		{
			*resultDecaying = 0;
			*resultDecayTimeElapsed = 0;
			*resultMaxLength = textLen;
			*resultRandomCharsLength = textLen - timeElapsed / fxLetterTime;
			*randSeed = gfxCmdBufSourceState.sceneDef.time / 50;
			RandWithSeed(randSeed);
			RandWithSeed(randSeed);
			return 1;
		}
		else
		{
			*resultDecaying = 1;
			*resultDecayTimeElapsed = timeElapsed - fxDecayStartTime;
			*resultMaxLength = maxLength;
			*resultRandomCharsLength = 0;
			return 1;
		}
	}
	else
	{
		*resultDecaying = 1;
		*resultDecayTimeElapsed = 0;
		*resultMaxLength = maxLength;
		*resultRandomCharsLength = 0;
		return 0;
	}
}

/*
==============
SetupTypewriterFXVars
==============
*/
char SetupTypewriterFXVars(const char *text, int maxLength, int renderFlags, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, bool *resultDrawRandChar, int *resultRandSeed, int *resultMaxLength, bool *resultDecaying)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SetupPopInFXVars
==============
*/
char SetupPopInFXVars(const char *text, int maxLength, int renderFlags, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, float *sizeIncrease, int *resultRandSeed, int *resultMaxLength, bool *resultDecaying)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SetupPulseFXVars
==============
*/
bool SetupPulseFXVars(const char *text, int maxLength, int renderFlags, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, bool *resultDrawRandChar, int *resultRandSeed, int *resultMaxLength, bool *resultDecaying, int *resultdecayTimeElapsed)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetShiftColor
==============
*/
void GetShiftColor(GfxColor targetColor, int fxBirthTime, int fxDecayStart, int fxDecayDuration, GfxColor startColor, GfxColor *shiftColor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SetupRedactTextFXVars
==============
*/
bool SetupRedactTextFXVars(const char *text, int maxLength, int renderFlags, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, bool *resultDrawRandChar, int *resultRandSeed, int *resultMaxLength, bool *resultDecaying, int *resultdecayTimeElapsed)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SetupRedactFXVars
==============
*/
void SetupRedactFXVars(int *randSeed, int fxBirthTime, int maxLength, int fxRedactDecayStartTime, int fxRedactDecayDuration, int mode, vec4_t *src_rect, vec4_t *max_rect, vec4_t *out_rect, float *u, Material **mat)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetDecayingStringAlphaInfo
==============
*/
void GetDecayingStringAlphaInfo(int decayTimeElapsed, int fxDecayDuration, unsigned __int8 alpha, unsigned __int8 *resultAlpha)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetDecayingLetterInfo
==============
*/
void GetDecayingLetterInfo(unsigned int letter, Font_s *font, int *randSeed, int decayTimeElapsed, int fxBirthTime, int fxDecayDuration, unsigned __int8 alpha, bool *resultSkipDrawing, unsigned __int8 *resultAlpha, unsigned int *resultLetter, bool *resultDrawExtraFxChar)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawTextFxExtraCharacter
==============
*/
void DrawTextFxExtraCharacter(const Material *material, int charIndex, float x, float y, float w0, float w, float h, float sinAngle, float cosAngle, unsigned int color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawText2D
==============
*/
void DrawText2D(const char* text, float x, float y, float w, Font_s* font, float xScale, float yScale, float sinAngle, float cosAngle, const GfxColor color, int maxLength, int renderFlags, int cursorPos, unsigned __int8 cursorLetter, float padding, GfxColor glowForcedColor, int fxBirthTime, int fxLetterTime, int fxDecayStartTime, int fxDecayDuration, int fxRedactDecayStartTime, int fxRedactDecayDuration, const Material* fxMaterial, const Material* fxMaterialGlow)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawTeleType
==============
*/
void __cdecl DrawTeleType(const char *text, float x, float y, float w, float h, Font_s *font, float xScale, float yScale, const GfxColor color, int renderFlags, int cursorPos, float cursorLetter, float padding, int fxBirthTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_DrawText
==============
*/
void RB_DrawText(int *a1, int *a2, bool *text, const char *font, Font_s *x, float y, float color, const GfxColor a8)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_DrawCharInSpace
==============
*/
void RB_DrawCharInSpace(const Material *material, const vec3_t *xyz, const vec3_t *dx, const vec3_t *dy, const Glyph *glyph, GfxColor color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_DrawTextInSpace
==============
*/
void RB_DrawTextInSpace(const char *text, Font_s *font, const vec3_t *org, const vec3_t *xPixelStep, const vec3_t *yPixelStep, GfxColor color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_DrawText2DCmd
==============
*/
void RB_DrawText2DCmd(GfxRenderCommandExecState *execState)
{
	const GfxCmdDrawText2D* cmd;
	float cosAngle, sinAngle;

	cmd = (const GfxCmdDrawText2D*)execState->cmd;
	cosAngle = cos(cmd->rotation * (M_PI / 180.0f));
	sinAngle = sin(cmd->rotation * (M_PI / 180.0f));

	PIXBeginNamedEvent(-1, cmd->text);

	if (cmd->type == 1)
	{
		DrawTeleType(cmd->text, cmd->x, cmd->y, cmd->w, cmd->h, cmd->font, cmd->xScale, cmd->yScale, cmd->color, cmd->renderFlags, cmd->cursorPos, cmd->cursorLetter, cmd->padding, cmd->fxBirthTime);
	}
	else if (cmd->type == 0)
	{
		DrawText2D(cmd->text, cmd->x, cmd->y, cmd->w, cmd->font, cmd->xScale, cmd->yScale, sinAngle, cosAngle, cmd->color, cmd->maxChars, cmd->renderFlags, cmd->cursorPos, cmd->cursorLetter,
			cmd->padding, cmd->glowForceColor, cmd->fxBirthTime, cmd->fxLetterTime, cmd->fxDecayStartTime, cmd->fxDecayDuration, cmd->fxRedactDecayStartTime, cmd->fxRedactDecayDuration,
			cmd->fxMaterial, cmd->fxMaterialGlow);
	}
	else
	{
		AssertMsg(va("RB_DrawText2DCmd: Unknown type (%d) text='%s'", cmd->type, cmd->text));
	}
	if (Sys_IsRenderThread())
	{
		D3DPERF_EndEvent();
	}
	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_DrawText3DCmd
==============
*/
void RB_DrawText3DCmd(GfxRenderCommandExecState *execState)
{
	const GfxCmdDrawText3D* cmd;

	cmd = (const GfxCmdDrawText3D*)execState->cmd;

	PIXBeginNamedEvent(-1, cmd->text);
	RB_DrawTextInSpace(
		cmd->text,
		cmd->font,
		&cmd->org,
		&cmd->xPixelStep,
		&cmd->yPixelStep,
		cmd->color
	);
	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_ProjectionSetCmd
==============
*/
void RB_ProjectionSetCmd(GfxRenderCommandExecState *execState)
{
	const GfxCmdProjectionSet* cmd;

	cmd = (const GfxCmdProjectionSet*)execState->cmd;
	if (cmd->projection == GFX_PROJECTION_2D)
	{
		if (tess.indexCount)
		{
			RB_EndTessSurface();
		}
		R_Set2D(&gfxCmdBufSourceState);
	}
	else if (cmd->projection == GFX_PROJECTION_3D)
	{
		if (tess.indexCount)
		{
			RB_EndTessSurface();
		}
		R_Set3D(&gfxCmdBufSourceState);
	}
	else
	{
		assertMsg(false, "Invalid projection type");
	}

	execState->cmd = (char*)execState->cmd + *(unsigned short*)execState->cmd;
}

/*
==============
RB_SwapBuffers
==============
*/
void RB_SwapBuffers()
{
	bool shouldSync;
	int v2, v3, i;
	tagMSG msg;
	int fullscreen;
	unsigned char stereoActivated;

	PIXBeginNamedEvent(0, "Present");

	shouldSync = Dvar_GetBool(r_vsync) || Dvar_GetBool(r_loadingScreen);
	dx.windows[dx.targetWindowIndex].swapChain->Present(shouldSync, 0);

	if (Sys_IsRenderThread())
	{
		D3DPERF_EndEvent();
	}
	
	if (Dvar_HasLatchedValue(r_texFilterQuality))
	{
		Dvar_MakeLatchedValueCurrent(r_texFilterQuality);
		R_DX11_ReleaseSamplerStates();
		if (dx.resolutionCallback)
		{
			dx.resolutionCallback(0);
		}
	}
	if (dx.needsShaderWarming && Dvar_GetBool(r_warmShaders))
	{
		Material_WarmAllShaders();
	}

	v2 = g_showCursor;
	if (g_showCursor || g_showGameCursor)
	{
		v3 = 0;
		if (g_showCursor || g_showGameCursor)
			v2 = 1;
	}
	else
	{
		v3 = -1;
		v2 = 0;
	}
	for (i = ShowCursor(v2); i != v3; i = ShowCursor(i < v3))
		;
	while (PeekMessageA(&msg, 0, 0, 0, 0))
	{
		if (!GetMessageA(&msg, 0, 0, 0))
		{
			Sys_SetWin32QuitEvent();
		}
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}
	if (Dvar_GetInt(r_fullscreen) == 1)
	{
		dx.swapChain->GetFullscreenState(&fullscreen, 0);
		if (!fullscreen)
		{
			ShowWindow(dx.windows[0].hwnd, 6);
		}
	}
	if (!dx.nvStereoHandle || (stereoActivated = 0, NvAPI_Stereo_IsActivated(dx.nvStereoHandle, &stereoActivated)))
	{
		dx.nvStereoActivated = 0;
	}
	else
	{
		dx.nvStereoActivated = stereoActivated != 0;
		if (stereoActivated)
		{
			NvAPI_Stereo_SetConvergence(dx.nvStereoHandle, Dvar_GetFloat(r_convergence));
		}
	}

}

/*
==============
RB_EndFrame
==============
*/
void RB_EndFrame(unsigned int drawType)
{
	if ((drawType & 2) != 0)
	{
		R_GPU_EndFrame();
		RB_SwapBuffers();
		assert(r_ignoreHwGamma);
		if (rg.gammaModified || Dvar_GetModified(r_ignoreHwGamma))
		{
			rg.gammaModified = 0;
			Dvar_ClearModified(r_ignoreHwGamma);
			if (!Dvar_GetBool(r_ignoreHwGamma))
			{
				R_SetColorMappings();
			}
		}
	}
}

/*
==============
RB_ExecuteRenderCommandsLoop
==============
*/
void RB_ExecuteRenderCommandsLoop(const void *cmds, int *ui3dTextureWindow)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_Draw3D
==============
*/
void RB_Draw3D()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_CallExecuteRenderCommands
==============
*/
void RB_CallExecuteRenderCommands()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_SetBspImages
==============
*/
void RB_SetBspImages()
{
	gfxCmdBufInput.codeImages[17] = rgp.world->outdoorImage;
}

/*
==============
RB_SaveScreen_BlendBlurred
==============
*/
void RB_SaveScreen_BlendBlurred(const GfxBlendSaveScreenBlurredParam *p)
{
	int newTime;
	float s0, t0, ds, dt;

	if (p->enabled)
	{
		PIXBeginNamedEvent(-1, __FUNCTION__);
		if (tess.indexCount)
		{
			RB_EndTessSurface();
		}
		R_Set2D(&gfxCmdBufSourceState);
		assert(p->fadeMsec > 0);
		newTime = gfxCmdBufSourceState.sceneDef.time - rgp.savedScreenTimes[p->screenTimerId];
		if (newTime >= 0 && newTime < p->fadeMsec)
		{
			if (rgp.savedScreenParams[p->screenTimerId].isSet)
			{
				s0 = rgp.savedScreenParams[p->screenTimerId].s0;
				ds = rgp.savedScreenParams[p->screenTimerId].ds;
				t0 = rgp.savedScreenParams[p->screenTimerId].t0;
				dt = rgp.savedScreenParams[p->screenTimerId].dt;
			}
			else
			{
				s0 = p->s0;
				ds = p->ds;
				t0 = p->t0;
				dt = p->dt;
			}
			gfxCmdBufSourceState.input.codeImages[8] = gfxRenderTargets[1].image;
			RB_DrawStretchPic(rgp.shellShockBlurredMaterial, 0.0, 0.0, (float)gfxRenderTargets[2].width, (float)gfxRenderTargets[2].height, s0, t0, ds + s0, dt + t0, ((unsigned __int8)(int)((pow(newTime, 255)) + 9.313225746154785e-10) << 24) | 0xFFFFFF, GFX_PRIM_STATS_CODE);
			if (tess.indexCount)
				RB_EndTessSurface();
		}
		if (Sys_IsRenderThread())
			D3DPERF_EndEvent();
	}
}

/*
==============
RB_SaveScreen_BlendFlashed
==============
*/
void RB_SaveScreen_BlendFlashed(const GfxBlendSaveScreenFlashedParam *p)
{
	float s0, t0, ds, dt, wo;
	double is;

	if (p->enabled)
	{
		PIXBeginNamedEvent(-1, __FUNCTION__);
		if (tess.indexCount)
		{
			RB_EndTessSurface();
		}
		R_Set2D(&gfxCmdBufSourceState);
		wo = (p->intensityWhiteout * 255.0) + 9.313225746154785e-10;
		is = (p->intensityScreengrab * 255.0) + 9.313225746154785e-10;
		if (rgp.savedScreenParams[p->screenTimerId].isSet)
		{
			s0 = rgp.savedScreenParams[p->screenTimerId].s0;
			ds = rgp.savedScreenParams[p->screenTimerId].ds;
			t0 = rgp.savedScreenParams[p->screenTimerId].t0;
			dt = rgp.savedScreenParams[p->screenTimerId].dt;
		}
		else
		{
			s0 = p->s0;
			ds = p->ds;
			t0 = p->t0;
			dt = p->dt;
		}
		gfxCmdBufSourceState.input.codeImages[8] = gfxRenderTargets[1].image;
		RB_DrawStretchPic(rgp.shellShockFlashedMaterial, 0.0, 0.0, 0.0, 0.0, s0, t0, ds + s0, dt + t0, (int)wo | (((int)wo | (((int)wo | ((int)is << 8)) << 8)) << 8), GFX_PRIM_STATS_CODE);
		if (tess.indexCount)
		{
			RB_EndTessSurface();
		}
		if (Sys_IsRenderThread())
		{
			D3DPERF_EndEvent();
		}
	}
}

/*
==============
RB_SaveScreen
==============
*/
void RB_SaveScreen(const GfxSaveScreenParam *p)
{
	unsigned int screenTimerId;
	int ObjectHandleForResource;
	ID3D11Resource* resource;

	if (p->mode)
	{
		PIXBeginNamedEvent(-1, "RB_SaveScreen");
		screenTimerId = p->screenTimerId;
		ObjectHandleForResource = -1;
		p = NULL;
		if (dx.nvInitialized)
		{
			gfxRenderTargets[1].image->texture.basemap->GetResource(&resource);
			ObjectHandleForResource = NvAPI_D3D_GetObjectHandleForResource(dx.device, resource, (NVDX_ObjectHandle*)&p);
			if (!ObjectHandleForResource)
			{
				NvAPI_D3D_BeginResourceRendering(dx.device, (NVDX_ObjectHandle)p, 1u);
			}
			resource->Release();
		}
		R_Resolve(gfxCmdBufContext, gfxRenderTargets[1].image);
		if (dx.nvInitialized && !ObjectHandleForResource)
		{
			NvAPI_D3D_EndResourceRendering(dx.device, (NVDX_ObjectHandle)p, 0);
		}
		R_SetRenderTargetSize(&gfxCmdBufSourceState, 2u);
		R_SetRenderTarget(gfxCmdBufContext, 2u);
		rgp.savedScreenTimes[p->screenTimerId] = gfxCmdBufSourceState.sceneDef.time;
		if (Sys_IsRenderThread())
		{
			D3DPERF_EndEvent();
		}
	}
}

/*
==============
R_DrawSurfsDepthOnly
==============
*/
void R_DrawSurfsDepthOnly(GfxCmdBufContext context, const GfxDrawSurfListInfo *info)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RB_Filter
==============
*/
void RB_Filter(const Material *material, const GfxViewInfo *viewInfo)
{
	if ((viewInfo->sceneComposition.renderingMode & 7) != 0 || viewInfo->isRenderingFullScreen)
	{
		R_UpdateCodeConstant(&gfxCmdBufSourceState, 0x55u, 0.0, 0.0, 1.0, 1.0);
		RB_FullScreenColoredFilter(material, 0xFFFFFFFF);
	}
	else
	{
		RB_SplitScreenFilter(material, viewInfo, 0xFFFFFFFF);
	}
}

/*
==============
RB_BeginFrame
==============
*/
void RB_BeginFrame(const void *data)
{
	int rt;

	backEndData = (GfxBackEndData*)data;
	if ((backEndData->drawType & 1) != 0)
	{
		++r_glob.backEndFrameCount;

		for (rt = 0; rt < R_RENDERTARGET_COUNT; ++rt)
		{
			gfxRenderTargets[rt].cleared = false;
		}
		r_glob.frameBuffer = 2;
		R_Cinematic_UpdateFrame(false);
		if (R_CheckDvarModified(r_texFilterAnisoMax) || R_CheckDvarModified(r_texFilterDisable) || R_CheckDvarModified(r_texFilterAnisoMin) || R_CheckDvarModified(r_texFilterMipMode) || R_CheckDvarModified(r_texFilterMipBias))
		{
			R_SetTexFilter();
		}
		tess.indexCount = 0;
		tess.vertexCount = 0;
		R_GPU_BeginFrame();
	}
}

inline void RB_UpdateDynamicBuffers(GfxBackEndData* backendData)
{
	void* buffer;
	unsigned int size;

	Sys_EnterCriticalSection(CRITSECT_DXDEVICE);
	buffer = R_LockVertexBuffer(dx.context, backendData->skinnedCacheVb->buffer, 0, backendData->skinnedCacheVb->used, 0x2000);
	memcpy(buffer, backendData->skinnedCacheVb->verts, backendData->skinnedCacheVb->used);
	R_UnlockVertexBuffer(dx.context, backendData->skinnedCacheVb->buffer);

	if (backendData->markMesh.vb.buffer && backendData->markMesh.vb.used)
	{
		if (backendData->markMesh.vb.used >= backendData->markMesh.vb.total)
		{
			size = backendData->markMesh.vb.total;
		}
		else
		{
			size = backendData->markMesh.vb.used;
		}

		buffer = R_LockVertexBuffer(dx.context, backendData->markMesh.vb.buffer, 0, size, 0x2000);
		memcpy(buffer, backendData->markMesh.vb.verts, size);
		R_UnlockVertexBuffer(dx.context, backendData->markMesh.vb.buffer);
	}

	if (backendData->codeMeshPtr->vb.buffer && backendData->codeMeshPtr->vb.used)
	{
		if (backendData->codeMeshPtr->vb.used >= backendData->codeMeshPtr->vb.total)
		{
			size = backendData->codeMeshPtr->vb.total;
		}
		else
		{
			size = backendData->codeMeshPtr->vb.used;
		}

		buffer = R_LockVertexBuffer(dx.context, backendData->codeMeshPtr->vb.buffer, 0, size, 0x2000);
		memcpy(buffer, backendData->codeMeshPtr->vb.verts, size);
		R_UnlockVertexBuffer(dx.context, backendData->codeMeshPtr->vb.buffer);
	}

	if (backendData->glassMesh.vb.buffer && backendData->glassMesh.vb.used)
	{
		if (backendData->glassMesh.vb.used >= backendData->glassMesh.vb.total)
		{
			size = backendData->glassMesh.vb.total;
		}
		else
		{
			size = backendData->glassMesh.vb.used;
		}

		buffer = R_LockVertexBuffer(dx.context, backendData->glassMesh.vb.buffer, 0, size, 0x2000);
		memcpy(buffer, backendData->glassMesh.vb.verts, size);
		R_UnlockVertexBuffer(dx.context, backendData->glassMesh.vb.buffer);
	}
	Sys_LeaveCriticalSection(CRITSECT_DXDEVICE);
}

void RB_RenderCommandFrame()
{
	char* Name;
	int viewInfoIdx;
	ClientNum_t clientNum;
	unsigned int drawType;
	int renderStartMS;

	renderStartMS = Sys_Milliseconds();
	backEndData = data;

	RB_BeginFrame(data);
}

/*
==============
RB_RenderThread
==============
*/
void RB_RenderThread(unsigned int threadContext)
{
	int semaphore;

	assertEq(threadContext, THREAD_CONTEXT_BACKEND);

	while (1)
	{
		if (!setjmp((int*)Sys_GetValue(THREAD_VALUE_COM_ERROR)))
		{
			break;
		}

		if (r_glob.isRenderingRemoteUpdate)
		{
			r_glob.isRenderingRemoteUpdate = 0;
			assert(!r_glob.screenUpdateNotify);
			r_glob.screenUpdateNotify = 1;
			data = NULL;
		}
		else if (data)
		{
			Com_ErrorAbort();
		}
	}
	while (1)
	{
		Sys_StopRenderer();
		Sys_StartRenderer();

		if (Sys_WaitBackendEvent(0))
		{
			data = (GfxBackEndData*)Sys_RendererSleep();
			if (data)
			{
				data = (GfxBackEndData*)Sys_RendererSleep();
				if (data)
				{
					RB_UpdateDynamicBuffers(data);
					RB_RenderCommandFrame();
				}
				data = NULL;
			}
		}
		else if (Sys_QueryRGRegisteredEvent())
		{
			R_Init();
			Sys_WaitRGRegisteredEvent();
			Sys_ResetRGRegisteredEvent();
		}
		else if (Sys_QueryD3DShutdownEvent())
		{
			if (rg.registered)
			{
				R_ShutdownInternal();
			}
			Sys_ResetD3DShutdownEvent();
		}
		else if (dx.doResizeBuffers)
		{
			RB_SwapBuffers();
		}
		else
		{
			NET_Sleep(0);
		}
		if (r_glob.remoteScreenUpdateNesting)
		{
			r_glob.screenUpdateNotify = 1;
			r_glob.isRenderingRemoteUpdate = 1;
			do
				SCR_UpdateScreen();
			while (r_glob.remoteScreenUpdateNesting);
			assert(r_glob.isRenderingRemoteUpdate);
			r_glob.isRenderingRemoteUpdate = 0;

			assert(!r_glob.screenUpdateNotify);
			r_glob.screenUpdateNotify = 1;
		}
	}
}
