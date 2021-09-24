#include "types.h"

/*
==============
Float4x4ForViewer
==============
*/
void Float4x4ForViewer(const vec3_t *origin3, const vec3_t *axis3)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CreateClipMatrix
==============
*/
void CreateClipMatrix(vector4 *clipMtx, const vec3_t *vieworg, const vec3_t *viewaxis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Vec4HomogenousClipZW
==============
*/
bool Vec4HomogenousClipZW(__m128 *pt0, __m128 *pt1, const __m128 *coeffZW)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_GenerateBeam_GetFlatDelta
==============
*/
bool FX_GenerateBeam_GetFlatDelta(const vector4 *invClipMtx, const __m128 *beamWorldBegin, const __m128 *beamWorldEnd, __m128 *outFlatDelta)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_Beam_Begin
==============
*/
void FX_Beam_Begin()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_Beam_Add
==============
*/
void FX_Beam_Add(FxBeam *beam)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_Beam_GetInfo
==============
*/
FxBeamInfo *FX_Beam_GetInfo()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
FX_Beam_GenerateVerts
==============
*/
void FX_Beam_GenerateVerts(int a1, const vec3_t *a2, __m128 *cmd, FxGenerateVertsCmd *a4)
{
	UNIMPLEMENTED(__FUNCTION__);
}

