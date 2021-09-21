#include "types.h"
#include "functions.h"

/*
==============
XAnim_CalcPosDeltaEntire
==============
*/
void XAnim_CalcPosDeltaEntire(const XAnimDeltaPart *animDelta, __m128 *posDelta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimClearRotTransArray
==============
*/
void XAnimClearRotTransArray(const DObj *obj, DObjAnimMat *rotTransArray, XAnimCalcAnimInfo *info)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimCalcNonLoopEnd
==============
*/
/*void XAnimCalcNonLoopEnd(const XAnimParts *parts, const unsigned __int8 *animToModel, float weightScale, DObjAnimMat *rotTransArray, const bitarray<160> *ignorePartBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
XAnimScaleRotTransArray
==============
*/
void XAnimScaleRotTransArray(int numBones, const XAnimCalcAnimInfo *info, DObjAnimMat *rotTransArray)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimNormalizeRotScaleTransArray
==============
*/
void XAnimNormalizeRotScaleTransArray(int numBones, const XAnimCalcAnimInfo *info, float weightScale, DObjAnimMat *rotTransArray)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimMadRotTransArray
==============
*/
void XAnimMadRotTransArray(int numBones, const XAnimCalcAnimInfo *info, float weightScale, const DObjAnimMat *rotTrans, DObjAnimMat *totalRotTrans)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimApplyAdditives
==============
*/
void XAnimApplyAdditives(DObjAnimMat *rotTransArray, DObjAnimMat *additiveArray, float weight, int boneCount, XAnimCalcAnimInfo *info)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnim_CalcDeltaForTime
==============
*/
void XAnim_CalcDeltaForTime(int a1, const XAnimDeltaPart *a2, const XAnimParts *anim, const float time, vec2_t *rotDelta, __m128 *posDelta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnim_CalcDelta3DForTime
==============
*/
void XAnim_CalcDelta3DForTime(int a1, const XAnimDeltaPart *a2, const XAnimParts *anim, const float time, vec4_t *rotDelta, __m128 *posDelta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimCalcLeafInternal
==============
*/
/*void XAnimCalcLeafInternal(const XAnimParts *parts, unsigned __int16 animToModelIndex, float time, float weightScale, DObjAnimMat *rotTransArray, bitarray<160> *animPartBits, const bitarray<160> *ignorePartBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
XAnimCalcLeaf
==============
*/
void XAnimCalcLeaf(XAnimInfo *info, float weightScale, DObjAnimMat *rotTransArray, XAnimCalcAnimInfo *animInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimCalc
==============
*/
void XAnimCalc(const DObj *obj, XAnimInfo *info, float weightScale, bool bClear, bool bNormQuat, XAnimCalcAnimInfo *animInfo, int rotTransArrayIndex, DObjAnimMat *rotTransArray)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjCalcAnim
==============
*/
void DObjCalcAnim(int a1, const DObj *obj, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

