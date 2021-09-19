#include "types.h"
#include "functions.h"

/*
==============
XAnimTreeHasInfo
==============
*/
BOOL XAnimTreeHasInfo(const XAnimTree_s *tree)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimInit
==============
*/
void XAnimInit()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimShutdown
==============
*/
void XAnimShutdown()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimFree
==============
*/
void XAnimFree(XAnimParts *parts)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimFindData_LoadObj
==============
*/
XAnimParts *XAnimFindData_LoadObj(const char *name, void *(*Alloc)(int))
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XAnimFindData_FastFile
==============
*/
XAnimParts *XAnimFindData_FastFile(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XAnimClone
==============
*/
XAnimParts *XAnimClone(XAnimParts *fromParts, void *(*Alloc)(int))
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XAnimPrecache
==============
*/
XAnimParts *XAnimPrecache(const char *name, void *(*Alloc)(int))
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XAnimCreate
==============
*/
void XAnimCreate(XAnim_s *anims, unsigned int animIndex, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimBlend
==============
*/
void XAnimBlend(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimSetParamValue
==============
*/
void XAnimSetParamValue(XAnim_s *anims, unsigned int paramIndex, const char *strParamName, float paramValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimSetValueSection
==============
*/
void XAnimSetValueSection(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimCreateAnimsWithValues
==============
*/
XAnim_s *XAnimCreateAnimsWithValues(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XAnimFreeList
==============
*/
void XAnimFreeList(XAnim_s *anims)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimCreateTree
==============
*/
XAnimTree_s *XAnimCreateTree(XAnim_s *anims, void *(*Alloc)(int))
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XAnimGetAnims
==============
*/
XAnim_s *XAnimGetAnims(const XAnimTree_s *tree)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XAnimGetAnimIndex
==============
*/
int XAnimGetAnimIndex(XAnim_s *anims, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimInitModelMap
==============
*/
void XAnimInitModelMap(XModel *const *models, unsigned int numModels, XModelNameMap *modelMap)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimCalcRelDeltaParts
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
XAnimFreeInfo
==============
*/
void XAnimFreeInfo(XAnimTree_s *tree, unsigned int infoIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimCheckFreeInfo
==============
*/
void XAnimCheckFreeInfo(XAnimTree_s *tree, unsigned int infoIndex, int hasWeight)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimGetAverageRateFrequency
==============
*/
double XAnimGetAverageRateFrequency(const XAnimTree_s *tree, unsigned int infoIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimGetNextNotifyIndex
==============
*/
signed int XAnimGetNextNotifyIndex(const XAnimParts *parts, float time)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimGetNotifyFracLeaf
==============
*/
float XAnimGetNotifyFracLeaf(const XAnimState *state, const XAnimState *nextState, float time, float dtime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimGetPartsForNotify
==============
*/
XAnimParts *XAnimGetPartsForNotify(const XAnimTree_s *tree, XAnimInfo *info)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XAnimAddClientNotify
==============
*/
void XAnimAddClientNotify(unsigned int notetrackName, float frac, unsigned int notifyType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimAddClientNotifyNamed
==============
*/
void XAnimAddClientNotifyNamed(unsigned int notetrackName, float frac, unsigned int notifyName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimProcessClientNotify
==============
*/
void XAnimProcessClientNotify(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimResetTime
==============
*/
void XAnimResetTime(unsigned int infoIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NotifyServerNotetrack
==============
*/
/*void NotifyServerNotetrack(int a1@<eax>, unsigned int a2@<edx>, unsigned int a3@<edi>, float a4@<xmm0>)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
XAnimProcessServerNotify
==============
*/
/*void XAnimProcessServerNotify(XAnimInfo *a1@<edx>, const DObj *obj, XAnimInfo *info, float time)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
XAnimGetLength
==============
*/
double XAnimGetLength(const XAnim_s *anims, unsigned int animIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimGetFrameCount
==============
*/
int XAnimGetFrameCount(const XAnim_s *anims, unsigned int animIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimGetLengthMsec
==============
*/
int XAnimGetLengthMsec(const XAnim_s *anims, unsigned int anim)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimGetInfoIndex_r
==============
*/
unsigned int XAnimGetInfoIndex_r(unsigned int animIndex, unsigned int infoIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimGetInfoIndex
==============
*/
/*unsigned int XAnimGetInfoIndex@<eax>(unsigned int a1@<edx>, const XAnimTree_s *tree)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
XAnimGetTime
==============
*/
/*double XAnimGetTime@<st0>(unsigned int a1@<edx>, const XAnimTree_s *tree, unsigned int animIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
XAnimGetWeight
==============
*/
/*double XAnimGetWeight@<st0>(unsigned int a1@<edx>, const XAnimTree_s *tree, unsigned int animIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
XAnimHasFinished
==============
*/
/*bool XAnimHasFinished@<al>(unsigned int a1@<edx>, const XAnimTree_s *tree, unsigned int animIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
XAnimGetNumChildren
==============
*/
int XAnimGetNumChildren(const XAnim_s *anims, unsigned int animIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimGetChildAt
==============
*/
unsigned int XAnimGetChildAt(const XAnim_s *anims, unsigned int animIndex, unsigned int childIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimGetAnimName
==============
*/
const char *XAnimGetAnimName(const XAnim_s *anims, unsigned int animIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XAnimIsDefault
==============
*/
bool XAnimIsDefault(XAnimParts *animParts)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimGetAnimDebugName
==============
*/
char *XAnimGetAnimDebugName(const XAnim_s *anims, unsigned int animIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XAnimGetAnimTreeSize
==============
*/
unsigned int XAnimGetAnimTreeSize(const XAnim_s *anims)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DObjClearServerNotifies
==============
*/
void DObjClearServerNotifies()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjSetServerNotifies
==============
*/
void DObjSetServerNotifies(XAnimServerNotifyList *pNotifyList)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjClearClientNotifies
==============
*/
void DObjClearClientNotifies()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjSetClientNotifies
==============
*/
void DObjSetClientNotifies(XAnimClientNotifyList *pNotifyList)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjGetClientNotifies
==============
*/
XAnimClientNotifyList *DObjGetClientNotifies()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XAnimAllocInfoWithParent
==============
*/
unsigned int XAnimAllocInfoWithParent(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimEnsureGoalWeightParent
==============
*/
unsigned int XAnimEnsureGoalWeightParent(DObj *obj, unsigned int animIndex, int cmdIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimClearGoalWeightInternal
==============
*/
void XAnimClearGoalWeightInternal(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimClearGoalWeight
==============
*/
void XAnimClearGoalWeight(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimClearTreeGoalWeightsInternal
==============
*/
void XAnimClearTreeGoalWeightsInternal(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimClearTreeGoalWeights
==============
*/
void XAnimClearTreeGoalWeights(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimClearTreeGoalWeightsStrict
==============
*/
void XAnimClearTreeGoalWeightsStrict(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimClearGoalWeightKnobInternal
==============
*/
void XAnimClearGoalWeightKnobInternal(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimClearTree
==============
*/
void XAnimClearTree(XAnimTree_s *tree)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimGetDescendantWithGreatestWeight
==============
*/
unsigned int XAnimGetDescendantWithGreatestWeight(const XAnimTree_s *tree, unsigned int infoIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimSetGoalWeightNode
==============
*/
int XAnimSetGoalWeightNode(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimSetupSyncNodes_r
==============
*/
void XAnimSetupSyncNodes_r(XAnim_s *anims, unsigned int animIndex, int parFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimSetupSyncNodes
==============
*/
void XAnimSetupSyncNodes(XAnim_s *anims)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimHasTime
==============
*/
BOOL XAnimHasTime(const XAnim_s *anims, unsigned int animIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimIsPrimitive
==============
*/
bool XAnimIsPrimitive(XAnim_s *anims, unsigned int animIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimSetAnimRate
==============
*/
/*void XAnimSetAnimRate(unsigned int a1@<edx>, XAnimTree_s *tree, unsigned int animIndex, float rate)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
XAnimIsLooped
==============
*/
bool XAnimIsLooped(const XAnim_s *anims, unsigned int animIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimGetBoneCount
==============
*/
unsigned __int8 XAnimGetBoneCount(const XAnim_s *anims, unsigned int animIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimHasBone
==============
*/
int XAnimHasBone(const XAnim_s *anims, unsigned int animIndex, unsigned __int16 boneName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimIsClientNode
==============
*/
int XAnimIsClientNode(const XAnim_s *anims, unsigned int animIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimIsClientNode
==============
*/
int XAnimIsClientNode(XAnimTree_s *tree, unsigned int animIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimNotetrackExists
==============
*/
char XAnimNotetrackExists(const XAnim_s *anims, unsigned int animIndex, unsigned int name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimAddNotetrackTimesToScriptArray
==============
*/
void XAnimAddNotetrackTimesToScriptArray(const XAnim_s *anims, unsigned int animIndex, unsigned int name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimDoesNoteTrackExistAtPosAfterTime
==============
*/
char XAnimDoesNoteTrackExistAtPosAfterTime(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimCloneAnimInfo
==============
*/
void XAnimCloneAnimInfo(XAnimTree_s *toTree, const XAnimInfo *from, XAnimInfo *to)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimCloneAnimTree_r
==============
*/
void XAnimCloneAnimTree_r(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimCloneAnimTree
==============
*/
void XAnimCloneAnimTree(const XAnimTree_s *from, XAnimTree_s *to)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetAnimInfo
==============
*/
XAnimInfo *GetAnimInfo(int infoIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XAnimGetParamValue
==============
*/
char XAnimGetParamValue(const XAnim_s *anims, unsigned int animIndex, const char *paramName, float *outValue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimGetParamValueTree
==============
*/
bool XAnimGetParamValueTree(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimGetParamValue
==============
*/
bool XAnimGetParamValue(XAnimTree_s *tree, unsigned int animIndex, const char *paramName, float *outValue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimCreateAnims
==============
*/
XAnim_s *XAnimCreateAnims(const char *debugName, int size, void *(*Alloc)(int))
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XAnimFreeTree
==============
*/
void XAnimFreeTree(XAnimTree_s *tree, void (*Free)(void *, int))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimCalcAbsDeltaParts
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
XAnimUpdateInfoSync
==============
*/
void XAnimUpdateInfoSync(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimUpdateTimeAndNotetrackLeaf
==============
*/
void XAnimUpdateTimeAndNotetrackLeaf(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimUpdateTimeAndNotetrackSyncSubTree
==============
*/
void XAnimUpdateTimeAndNotetrackSyncSubTree(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimUpdateTimeAndNotetrack
==============
*/
void XAnimUpdateTimeAndNotetrack(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimCloneInitTime
==============
*/
unsigned int XAnimCloneInitTime(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimInitTime
==============
*/
unsigned int XAnimInitTime(XAnimTree_s *tree, unsigned int infoIndex, float goalTime, int cmdIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimUpdateOldTime
==============
*/
void XAnimUpdateOldTime(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimCalcDeltaTree
==============
*/
void XAnimCalcDeltaTree(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjInitServerTime
==============
*/
void DObjInitServerTime(DObj *obj, float dtime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjUpdateClientInfo
==============
*/
void DObjUpdateClientInfo(DObj *obj, float dtime, int notifyFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjUpdateServerInfo
==============
*/
void DObjUpdateServerInfo(DObj *obj, float dtime, int notifyFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimDisplay
==============
*/
void XAnimDisplay(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjDisplayAnimToBuffer
==============
*/
void DObjDisplayAnimToBuffer(const DObj *obj, const char *header, char *buffer, int bufferSize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DObjDisplayAnim
==============
*/
void DObjDisplayAnim(const DObj *obj, const char *header)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimCalcDelta
==============
*/
void XAnimCalcDelta(DObj *obj, unsigned int animIndex, vec2_t *rot, vec3_t *trans, bool bUseGoalWeight)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimCalcAbsDelta
==============
*/
void XAnimCalcAbsDelta(DObj *obj, unsigned int animIndex, vec4_t *rot, vec3_t *trans)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimGetRelDelta
==============
*/
void XAnimGetRelDelta(const XAnim_s *anims, unsigned int animIndex, vec2_t *rot, vec3_t *trans)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimGetAbsDelta
==============
*/
void XAnimGetAbsDelta(const XAnim_s *anims, unsigned int animIndex, vec4_t *rot, vec3_t *trans)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimSetCompleteGoalWeightNode
==============
*/
int XAnimSetCompleteGoalWeightNode(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimSetTime
==============
*/
void XAnimSetTime(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimRestart
==============
*/
unsigned int XAnimRestart(XAnimTree_s *tree, unsigned int infoIndex, float goalTime, int cmdIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimGetAnimMap
==============
*/
unsigned int XAnimGetAnimMap(const XAnimParts *parts, const XModelNameMap *modelMap)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimResetAnimMapLeaf
==============
*/
void XAnimResetAnimMapLeaf(const XModelNameMap *modelMap, unsigned int infoIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimResetAnimMap_r
==============
*/
void XAnimResetAnimMap_r(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimResetAnimMap
==============
*/
void XAnimResetAnimMap(const DObj *obj, unsigned int infoIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
XAnimAllocInfoIndex
==============
*/
unsigned int XAnimAllocInfoIndex(unsigned int animIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimAllocInfo
==============
*/
XAnimInfo *XAnimAllocInfo(DObj *obj, unsigned int animIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
XAnimSetCompleteGoalWeightKnob
==============
*/
/*int XAnimSetCompleteGoalWeightKnob@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
XAnimSetGoalWeightKnob
==============
*/
/*int XAnimSetGoalWeightKnob@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
XAnimSetGoalWeight
==============
*/
/*int XAnimSetGoalWeight@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
XAnimSetCompleteGoalWeight
==============
*/
/*int XAnimSetCompleteGoalWeight@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
XAnimSetGoalWeightKnobAll
==============
*/
int XAnimSetGoalWeightKnobAll(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
XAnimSetCompleteGoalWeightKnobAll
==============
*/
int XAnimSetCompleteGoalWeightKnobAll(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

