#include "types.h"
#include "functions.h"

/*
==============
CG_GetPicWidth
==============
*/
double CG_GetPicWidth(Material *mat)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawRotatedPicPhysicalW
==============
*/
void CG_DrawRotatedPicPhysicalW(const ScreenPlacement *scrPlace, float x, float y, float w, float width, float height, float angle, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawRotatedPicPhysical
==============
*/
void CG_DrawRotatedPicPhysical(const ScreenPlacement *scrPlace, float x, float y, float width, float height, float angle, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawRotatedPicW
==============
*/
void CG_DrawRotatedPicW(const ScreenPlacement *scrPlace, float x, float y, float w, float width, float height, int horzAlign, int vertAlign, float angle, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawRotatedPic
==============
*/
void CG_DrawRotatedPic(const ScreenPlacement *scrPlace, float x, float y, float width, float height, int horzAlign, int vertAlign, float angle, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawRotatedQuadPic
==============
*/
void CG_DrawRotatedQuadPic(const ScreenPlacement *scrPlace, float x, float y, const vec2_t *verts, float angle, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawStringExt
==============
*/
void CG_DrawStringExt(const ScreenPlacement *scrPlace, float x, float y, const char *string, const vec4_t *setColor, int forceColor, int shadow, float charHeight)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawDevString
==============
*/
int CG_DrawDevString(LocalClientNum_t localClientNum, const ScreenPlacement *scrPlace, float x, float y, float xScale, float yScale, const char *s, const vec4_t *color, int align, Font_s *font)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DrawSmallDevStringColor
==============
*/
int CG_DrawSmallDevStringColor(LocalClientNum_t localClientNum, const ScreenPlacement *scrPlace, float x, float y, const char *s, const vec4_t *color, int align)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_FadeAlpha
==============
*/
double CG_FadeAlpha(int timeNow, int startMsec, int totalMsec, int fadeMsec)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_FadeColor
==============
*/
vec4_t *CG_FadeColor(int timeNow, int startMsec, int totalMsec, int fadeMsec)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_MiniMapChanged
==============
*/
void CG_MiniMapChanged(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_NorthDirectionChanged
==============
*/
void CG_NorthDirectionChanged(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RelativeTeamColor
==============
*/
void CG_RelativeTeamColor(ClientNum_t clientNum, vec4_t *color, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DrawBigDevString
==============
*/
int CG_DrawBigDevString(LocalClientNum_t localClientNum, const ScreenPlacement *scrPlace, float x, float y, const char *s, float alpha, int align)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

