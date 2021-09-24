#include "types.h"

/*
==============
FX_InterpolateSamples
==============
*/
void FX_InterpolateSamples(int dimensions, float time0, const float *samples0, float time1, const float *samples1, float timeEval, float *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SampleCurve1D
==============
*/
float FX_SampleCurve1D(const FxCurve *curve, float scale, float time)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_DecideSampleCount
==============
*/
int FX_DecideSampleCount(int curveCount, const FxCurve **curves, int intervalLimit)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_DecideVelocitySampleCount
==============
*/
int FX_DecideVelocitySampleCount(const FxEditorElemDef *edElem, int intervalLimit)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_GetVisualSampleRouting
==============
*/
void FX_GetVisualSampleRouting(const FxEditorElemDef *edElem, FxSampleChannel *routing)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DecideVisualSampleCount
==============
*/
int FX_DecideVisualSampleCount(const FxEditorElemDef *edElem, const FxSampleChannel *routing, int intervalLimit)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_SampleVelocityInFrame
==============
*/
void FX_SampleVelocityInFrame(FxElemDef *elemDef, const vec3_t *velScale, FxElemVelStateInFrame *velState, int velStateStride, int useGraphBit, const FxEditorElemDef *edElemDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SampleVisualStateScalar
==============
*/
void FX_SampleVisualStateScalar(const FxEditorElemDef *edElemDef, float sampleTime, FxSampleChannel routing, float scaleFactor, float *base, float *amplitude)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_SampleVisualState
==============
*/
void FX_SampleVisualState(FxElemDef *elemDef, const FxEditorElemDef *edElemDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ValidateAtlasSettings
==============
*/
bool FX_ValidateAtlasSettings(const FxEditorEffectDef *editorEffect, const FxEditorElemDef *edElemDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_ConvertAtlas
==============
*/
void FX_ConvertAtlas(FxElemDef *elemDef, const FxEditorElemDef *edElemDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ReserveElemDefMemory
==============
*/
void FX_ReserveElemDefMemory(FxElemDef *elemDef, unsigned __int8 **memPool)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_BoundFloatRange
==============
*/
void FX_BoundFloatRange(FxFloatRange *range, float lower, float upper)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ConvertTrail_CompileVertices
==============
*/
void FX_ConvertTrail_CompileVertices(const FxEditorElemDef *edElemDef, FxTrailDef *outTrailDef, unsigned __int8 **mempool)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ConvertTrail
==============
*/
void FX_ConvertTrail(FxTrailDef **outTrailDef, const FxEditorElemDef *edElemDef, unsigned __int8 **mempool)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ConvertSpotLight
==============
*/
void FX_ConvertSpotLight(FxSpotLightDef **outSpotLightDef, const FxEditorElemDef *edElemDef, unsigned __int8 **mempool)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_FindEmission
==============
*/
int FX_FindEmission(const FxEffectDef *emission, const FxEditorEffectDef *editorEffect)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_CopyEmittedElemDefs
==============
*/
int FX_CopyEmittedElemDefs(const FxEditorEffectDef *a1, FxElemDef *elemDefArray, const FxEditorEffectDef *editorEffect, unsigned __int8 **memPool)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_AdditionalBytesNeededForEmission
==============
*/
int FX_AdditionalBytesNeededForEmission(const FxEffectDef *emission)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_ValidateVisuals
==============
*/
bool FX_ValidateVisuals(const FxEditorEffectDef *editorEffect, const FxEditorElemDef *edElemDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_ConvertElemDef
==============
*/
void FX_ConvertElemDef(FxElemDef *elemDef, const FxEditorElemDef *edElemDef, int velStateCount, int visStateCount, int emitIndex, unsigned __int8 **memPool)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ConvertElemDefsOfType
==============
*/
int FX_ConvertElemDefsOfType(FxElemDef *elemDefArray, const FxEditorEffectDef *editorEffect, int loopingFlagState, const int *velStateCount, const int *visStateCount, const int *emitIndex, unsigned __int8 **memPool)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_Convert
==============
*/
const FxEffectDef *FX_Convert(char *a1, const FxEditorEffectDef *editorEffect, void *(*Alloc)(int))
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

