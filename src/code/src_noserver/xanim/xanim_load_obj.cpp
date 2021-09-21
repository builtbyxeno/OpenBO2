#include "types.h"
#include "functions.h"

/*
==============
ConsumeQuat
==============
*/
void ConsumeQuat(const unsigned __int8 **pos, __int16 *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ConsumeQuat2
==============
*/
void ConsumeQuat2(const unsigned __int8 **pos, __int16 *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ReadNoteTracks
==============
*/
void ReadNoteTracks(const char *name, const unsigned __int8 **pos, XAnimParts *parts, void *(*Alloc)(int))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetDeltaQuaternions2
==============
*/
const unsigned __int8 *GetDeltaQuaternions2(XAnimDeltaPart *deltaPart, void *(*Alloc)(int), const unsigned __int8 *pos, unsigned __int16 numloopframes, bool useSmallIndices)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GetDeltaQuaternions
==============
*/
const unsigned __int8 *GetDeltaQuaternions(__int16 *a1, const unsigned __int8 **a2, XAnimDeltaPart *deltaPart, void *(*Alloc)(int), const unsigned __int8 *pos, unsigned __int16 numloopframes, bool useSmallIndices)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
LoadTrans
==============
*/
const unsigned __int8 *LoadTrans(void *(*Alloc)(int), const unsigned __int8 *pos, unsigned __int16 numTransIndices, XAnimPartTrans *trans)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GetDeltaTranslations
==============
*/
const unsigned __int8 *GetDeltaTranslations(const char *name, XAnimDeltaPart *deltaPart, void *(*Alloc)(int), const unsigned __int8 *pos, unsigned __int16 numloopframes, bool useSmallIndices)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XAnimTempAlloc
==============
*/
void *XAnimTempAlloc(int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GetQuaternions
==============
*/
unsigned __int8 *GetQuaternions(__int16 *a1, const unsigned __int8 **a2, XAnimPartQuatPtr *part, const unsigned __int8 *pos, bool bFlipQuat, bool bSimpleQuat, unsigned __int16 numloopframes, bool useSmallIndices)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GetTranslations
==============
*/
const unsigned __int8 *GetTranslations(XAnimPartTransPtr *part, const unsigned __int8 *pos, unsigned __int16 numloopframes, bool useSmallIndices)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XAnimCompareQuatParts
==============
*/
int XAnimCompareQuatParts(const void *p0, const void *p1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimCompareTransParts
==============
*/
int XAnimCompareTransParts(const void *p0, const void *p1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimIsHighPrecisionPart
==============
*/
int XAnimIsHighPrecisionPart(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimEmitFrameIndices
==============
*/
void XAnimEmitFrameIndices(unsigned int tableSize, unsigned __int8 **dataByte, __int16 **dataShort, XAnimIndices *indices, XAnimDynamicIndices *frameIndices, bool useSmallIndices)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimLoadFile
==============
*/
XAnimParts *XAnimLoadFile(const char *name, void *(*Alloc)(int), bool streamedVersion)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

