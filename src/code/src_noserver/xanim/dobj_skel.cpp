#include "types.h"
#include "functions.h"

/*
==============
GetControlAndDuplicatePartBits
==============
*/
void GetControlAndDuplicatePartBits(const DObj *obj, const int *partBits, const int *ignorePartBits, const int *savedDuplicatePartBits, int *calcPartBits, int *controlPartBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CalcSkelDuplicateBones
==============
*/
const unsigned __int8 *CalcSkelDuplicateBones(const XModel *model, DSkel *skel, int minBoneIndex, const unsigned __int8 *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CalcSkelRootBonesNoParentOrDuplicate
==============
*/
void CalcSkelRootBonesNoParentOrDuplicate(const XModel *model, int minBoneIndex, DSkel *skel, int *calcPartBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CalcSkelRootBonesWithParent
==============
*/
void CalcSkelRootBonesWithParent(const XModel *model, DSkel *skel, unsigned int minBoneIndex, unsigned int modelParent, int *calcPartBits, const int *controlPartBits, const XAnimRootAdjustMat *rootAdjustMat)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjCalcBaseAnim
==============
*/
void DObjCalcBaseAnim(const DObj *obj, DObjAnimMat *mat, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CalcSkelNonRootBones
==============
*/
void CalcSkelNonRootBones(DSkel *skel, int *calcPartBits, const XModel *model, int minBoneIndex, const int *controlPartBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjCalcSkel
==============
*/
void DObjCalcSkel(const DObj *obj, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjCalcBaseSkel
==============
*/
void DObjCalcBaseSkel(DObjAnimMat *a1, const DObj *obj, DObjAnimMat *mat, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

