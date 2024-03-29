#pragma once

#include "types.h"

//t6/code/src_noserver/xanim/dobj.cpp
void DObjInit();
void DObjShutdown();
void DObjDumpCreationInfo(DObjModel_s *dobjModels, unsigned int numModels);
void DObjGetHierarchyBits(const DObj *obj, int boneIndex, int *partBits);
BOOL DObjSkelIsBoneUpToDate(DObj *obj, int boneIndex);
void DObjComputeBounds(DObj *obj);
void DObjCalcBounds(DObj *dobj, vec3_t *mins, vec3_t *maxs);
void DObjSkelClear(const DObj *obj);
LocalClientNum_t DObjGetLocalClientIndex(const DObj *obj);
void DObjGetBounds(const DObj *obj, vec3_t *mins, vec3_t *maxs);
void DObjPhysicsGetBounds(const DObj *obj, vec3_t *mins, vec3_t *maxs);
double DObjGetRadius(const DObj *obj);
PhysPreset *DObjGetPhysPreset(const DObj *obj);
const char *DObjGetName(const DObj *obj);
const char *DObjGetBoneName(const DObj *obj, int boneIndex);
const char *DObjGetModelParentBoneName(const DObj *obj, int modelIndex);
XAnimTree_s *DObjGetTree(const DObj *obj);
int DObjBad(const DObj *obj);
void DObjTracelinePartBits(DObj *obj, int *partBits);
void DObjGeomTraceline(int a1, DObj *obj, vec3_t *localStart, vec3_t *localEnd, int contentmask, DObjTrace_s *results);
void DObjGeomTracelinePartBits(DObj *obj, int contentmask, int *partBits);
int DObjHasContents(DObj *obj, int contentmask);
int DObjGetContents(const DObj *obj);
BOOL DObjHasCollmap(const DObj *obj);
PhysGeomList *DObjGetCollmap(DObj *obj);
XModel *DObjGetXModel(DObj *obj, int index);
int DObjSetLocalBoneIndex(DObj *obj, int *partBits, int boneIndex, const vec3_t *trans, const vec3_t *angles);
int DObjGetModelBoneIndex(const DObj *obj, const char *modelName, unsigned int name, unsigned __int8 *index);
void DObjGetBasePoseMatrix(const DObj *obj, unsigned __int8 boneIndex, DObjAnimMat *outMat);
void DObjSetHidePartBits(DObj *obj, const unsigned int *partBits);
BOOL DObjHasFlag(const DObj *obj, unsigned __int8 flag);
void DObjSetFlag(DObj *obj, unsigned __int8 flag, int val);
int DObjHasIKActiveFlag(const DObj *obj);
void DObjSetIKActiveFlag(DObj *obj, int val);
void DObjSetIKBypassFlag(DObj *obj, int val);
void DObjSetIKState(DObj *obj, const unsigned __int8 *pIKState);
void DObjDumpInfo(const DObj *obj);
void DObjCreateDuplicateParts(DObj *obj, DObjModel_s *dobjModels, unsigned int numModels);
void DObjFree(DObj *obj);
BOOL DObjIsServer(const DObj *obj);
int DObjIsLocalPlayer(const DObj *obj);
int DObjIsPlayerShadow(const DObj *obj);
BOOL DObjIsLeftHandGripIKActive(const DObj *obj);
void DObjTraceline(int a1, DObj *obj, vec3_t *start, vec3_t *end, unsigned __int8 *priorityMap, DObjTrace_s *trace);
void DObjSetTree(DObj *obj, XAnimTree_s *tree);
void __cdecl DObjCreate(DObjModel_s *dobjModels, unsigned int numModels, XAnimTree_s *tree, void *buf, unsigned int entnum);
void DObjCreateExt(DObjModel_s *dobjModels, unsigned int numModels, XAnimTree_s *tree, void *buf, unsigned int entnum, bool isServer, bool isLocalPlayer, LocalClientNum_t localClientIndex);
int DObjGetModelBoneIndex(const DObj *obj, int model_index, unsigned int name, unsigned __int8 *index);

//t6/code/src_noserver/xanim/dobj_skel.cpp
void GetControlAndDuplicatePartBits(const DObj *obj, const int *partBits, const int *ignorePartBits, const int *savedDuplicatePartBits, int *calcPartBits, int *controlPartBits);
const unsigned __int8 *CalcSkelDuplicateBones(const XModel *model, DSkel *skel, int minBoneIndex, const unsigned __int8 *pos);
void CalcSkelRootBonesNoParentOrDuplicate(const XModel *model, int minBoneIndex, DSkel *skel, int *calcPartBits);
void CalcSkelRootBonesWithParent(const XModel *model, DSkel *skel, unsigned int minBoneIndex, unsigned int modelParent, int *calcPartBits, const int *controlPartBits, const XAnimRootAdjustMat *rootAdjustMat);
void DObjCalcBaseAnim(const DObj *obj, DObjAnimMat *mat, int *partBits);
void CalcSkelNonRootBones(DSkel *skel, int *calcPartBits, const XModel *model, int minBoneIndex, const int *controlPartBits);
void DObjCalcSkel(const DObj *obj, int *partBits);
void DObjCalcBaseSkel(DObjAnimMat *a1, const DObj *obj, DObjAnimMat *mat, int *partBits);

//t6/code/src_noserver/xanim/dobj_utils.cpp
DObjAnimMat *DObjGetRotTransArray(const DObj *obj);
DObjAnimMat *DObjGetRotTransArrayMain(const DObj *obj);
int DObjGetNumModels(const DObj *obj);
unsigned __int16 DObjGetEntNum(const DObj *obj);
int DObjGetSurfaces(const DObj *obj, int *partBits, const char *lods);
void DObjGetBoneInfo(const DObj *obj, XBoneInfo **boneInfo);
int DObjNumBones(const DObj *obj);
void DObjGetSetBones(const DObj *obj, int *setPartBits);
int DObjSetRotTransIndex(const DObj *obj, const int *partBits, int boneIndex);
char DObjSetSkelRotTransIndex(const DObj *obj, const int *partBits, int boneIndex);
XModel *DObjGetModel(const DObj *obj, int modelIndex);
int DObjHasCollision(const DObj *obj);
XModel *DObjGetModelRemote(const DObj *obj, int modelIndex);
void DObjSetAngles(DObjAnimMat *rotTrans, const vec3_t *angles);
void DObjSetTrans(DObjAnimMat *rotTrans, const vec3_t *trans);
void DObjCompleteHierarchyBits(const DObj *obj, int *partBits);
int DObjSetControlRotTransIndex(const DObj *obj, const int *partBits, int boneIndex);
BOOL DObjSkelExists(const DObj *obj, int timeStamp);
void DObjClearSkel(const DObj *obj);
int DObjSkelAreBonesUpToDate(const DObj *obj, int *partBits);
void DObjSkelSetSkel(const DObj *obj, int *partBits);
int DObjGetAllocSkelSize(const DObj *obj);
void DObjCreateSkel(const DObj *obj, char *buf, int timeStamp);
DObjAnimMat *I_dmaGetDObjSkel(const DObj *obj);
void DObjGetHidePartBits(const DObj *obj, unsigned int *partBits);
int DObjGetBoneIndex(const DObj *obj, unsigned int name, unsigned __int8 *index, int modelNum);
int DObjGetParentBone(const DObj *obj, unsigned __int8 childBoneIndex);
int DObjGetChildBones(const DObj *obj, unsigned __int8 parentBone, unsigned __int8 *children, int maxChildren);
void DObjLock(const DObj *obj);
void DObjUnlock(const DObj *obj);
int DObjIsRecorded(const DObj *obj);
void DObjGetSurfaceData(const DObj *obj, const vec3_t *origin, const float scale, char *lods);
unsigned int DObjGetRootBoneCount(const DObj *obj);
void DObjSetLocalTagInternal(const DObj *obj, const vec3_t *trans, const vec3_t *angles, int boneIndex);
void DObjSetControlTagAngles(const DObj *obj, int *partBits, unsigned int boneIndex, vec3_t *angles);
void DObjSetLocalTag(const DObj *obj, int *partBits, unsigned int boneIndex, const vec3_t *trans, const vec3_t *angles);

//t6/code/src_noserver/xanim/xanim.cpp
BOOL XAnimTreeHasInfo(const XAnimTree_s *tree);
void XAnimInit();
void XAnimShutdown();
void XAnimFree(XAnimParts *parts);
XAnimParts *XAnimFindData_LoadObj(const char *name, void *(*Alloc)(int));
XAnimParts *XAnimFindData_FastFile(const char *name);
XAnimParts *XAnimClone(XAnimParts *fromParts, void *(*Alloc)(int));
XAnimParts *XAnimPrecache(const char *name, void *(*Alloc)(int));
void XAnimCreate(XAnim_s *anims, unsigned int animIndex, const char *name);
void XAnimBlend(XAnim_s *anims, unsigned int animIndex, const char *name, unsigned int children, unsigned int num, unsigned int flags);
void XAnimSetParamValue(XAnim_s *anims, unsigned int paramIndex, const char *strParamName, float paramValue);
void XAnimSetValueSection(XAnim_s *anims, unsigned int animIndex, unsigned int iFirstValueIndex, unsigned int iValueCount);
XAnim_s *XAnimCreateAnimsWithValues(const char *debugName, int size, int iTotalValueCount, void *(*Alloc)(int));
void XAnimFreeList(XAnim_s *anims);
XAnimTree_s *XAnimCreateTree(XAnim_s *anims, void *(*Alloc)(int));
XAnim_s *XAnimGetAnims(const XAnimTree_s *tree);
int XAnimGetAnimIndex(XAnim_s *anims, const char *name);
void XAnimInitModelMap(XModel *const *models, unsigned int numModels, XModelNameMap *modelMap);
void XAnimCalcRelDeltaParts(const XAnimParts *parts, XAnimRotPos *rotPos);
void XAnimFreeInfo(XAnimTree_s *tree, unsigned int infoIndex);
void XAnimCheckFreeInfo(XAnimTree_s *tree, unsigned int infoIndex, int hasWeight);
double XAnimGetAverageRateFrequency(const XAnimTree_s *tree, unsigned int infoIndex);
signed int XAnimGetNextNotifyIndex(const XAnimParts *parts, float time);
float XAnimGetNotifyFracLeaf(const XAnimState *state, const XAnimState *nextState, float time, float dtime);
XAnimParts *XAnimGetPartsForNotify(const XAnimTree_s *tree, XAnimInfo *info);
void XAnimAddClientNotify(unsigned int notetrackName, float frac, unsigned int notifyType);
void XAnimAddClientNotifyNamed(unsigned int notetrackName, float frac, unsigned int notifyName);
void XAnimProcessClientNotify(const XAnimState *a1, const XAnimState *a2, unsigned int info, XAnimInfo *dtime, float forceProcess, bool a6);
void XAnimResetTime(unsigned int infoIndex);
void NotifyServerNotetrack(int a1, unsigned int a2, unsigned int a3, float a4);
void XAnimProcessServerNotify(XAnimInfo *a1, const DObj *obj, XAnimInfo *info, float time);
double XAnimGetLength(const XAnim_s *anims, unsigned int animIndex);
int XAnimGetFrameCount(const XAnim_s *anims, unsigned int animIndex);
int XAnimGetLengthMsec(const XAnim_s *anims, unsigned int anim);
unsigned int XAnimGetInfoIndex_r(unsigned int animIndex, unsigned int infoIndex);
unsigned int XAnimGetInfoIndex(unsigned int a1, const XAnimTree_s *tree);
double XAnimGetTime(unsigned int a1, const XAnimTree_s *tree, unsigned int animIndex);
double XAnimGetWeight(unsigned int a1, const XAnimTree_s *tree, unsigned int animIndex);
bool XAnimHasFinished(unsigned int a1, const XAnimTree_s *tree, unsigned int animIndex);
int XAnimGetNumChildren(const XAnim_s *anims, unsigned int animIndex);
unsigned int XAnimGetChildAt(const XAnim_s *anims, unsigned int animIndex, unsigned int childIndex);
const char *XAnimGetAnimName(const XAnim_s *anims, unsigned int animIndex);
bool XAnimIsDefault(XAnimParts *animParts);
char *XAnimGetAnimDebugName(const XAnim_s *anims, unsigned int animIndex);
unsigned int XAnimGetAnimTreeSize(const XAnim_s *anims);
void DObjClearServerNotifies();
void DObjSetServerNotifies(XAnimServerNotifyList *pNotifyList);
void DObjClearClientNotifies();
void DObjSetClientNotifies(XAnimClientNotifyList *pNotifyList);
XAnimClientNotifyList *DObjGetClientNotifies();
unsigned int XAnimAllocInfoWithParent(const char *a1, XAnimTree_s *tree, unsigned int animToModel, unsigned int animIndex, unsigned int parentInfoIndex, int after);
unsigned int XAnimEnsureGoalWeightParent(DObj *obj, unsigned int animIndex, int cmdIndex);
void XAnimClearGoalWeightInternal(XAnimTree_s *tree, unsigned int infoIndex, float blendTime, int forceBlendTime, int cmdIndex);
void XAnimClearGoalWeight(unsigned int a1, char *a2, XAnimTree_s *tree, unsigned int animIndex, float blendTime, int cmdIndex);
void XAnimClearTreeGoalWeightsInternal(unsigned int a1, XAnimTree_s *tree, unsigned int infoIndex, float blendTime, int forceBlendTime, int cmdIndex);
void XAnimClearTreeGoalWeights(unsigned int a1, XAnimTree_s *tree, unsigned int animIndex, float blendTime, int cmdIndex);
void XAnimClearTreeGoalWeightsStrict(unsigned int a1, XAnimTree_s *tree, unsigned int animIndex, float blendTime, int cmdIndex);
void __cdecl XAnimClearGoalWeightKnobInternal(XAnimTree_s *tree, unsigned int infoIndex, float goalWeight, float goalTime, int cmdIndex);
void XAnimClearTree(XAnimTree_s *tree);
unsigned int XAnimGetDescendantWithGreatestWeight(const XAnimTree_s *tree, unsigned int infoIndex);
int XAnimSetGoalWeightNode(XAnimTree_s *tree, unsigned int infoIndex, float goalWeight, float goalTime, float rate, unsigned int notifyName, unsigned int notifyType, int cmdIndex);
void XAnimSetupSyncNodes_r(XAnim_s *anims, unsigned int animIndex, int parFlags);
void XAnimSetupSyncNodes(XAnim_s *anims);
BOOL XAnimHasTime(const XAnim_s *anims, unsigned int animIndex);
bool XAnimIsPrimitive(XAnim_s *anims, unsigned int animIndex);
void XAnimSetAnimRate(unsigned int a1, XAnimTree_s *tree, unsigned int animIndex, float rate);
bool XAnimIsLooped(const XAnim_s *anims, unsigned int animIndex);
unsigned __int8 XAnimGetBoneCount(const XAnim_s *anims, unsigned int animIndex);
int XAnimHasBone(const XAnim_s *anims, unsigned int animIndex, unsigned __int16 boneName);
int XAnimIsClientNode(const XAnim_s *anims, unsigned int animIndex);
int XAnimIsClientNode(XAnimTree_s *tree, unsigned int animIndex);
char XAnimNotetrackExists(const XAnim_s *anims, unsigned int animIndex, unsigned int name);
void XAnimAddNotetrackTimesToScriptArray(const XAnim_s *anims, unsigned int animIndex, unsigned int name);
char XAnimDoesNoteTrackExistAtPosAfterTime(const XAnim_s *anims, unsigned int animIndex, unsigned int name, float startTime, float checkTime);
void XAnimCloneAnimInfo(XAnimTree_s *toTree, const XAnimInfo *from, XAnimInfo *to);
void XAnimCloneAnimTree_r(XAnimInfo *a1, const XAnimTree_s *from, XAnimTree_s *to, unsigned int fromInfoIndex, unsigned int toInfoParentIndex);
void XAnimCloneAnimTree(const XAnimTree_s *a1, const XAnimTree_s *from, XAnimTree_s *to);
XAnimInfo *GetAnimInfo(int infoIndex);
char XAnimGetParamValue(const XAnim_s *anims, unsigned int animIndex, const char *paramName, float *outValue);
bool XAnimGetParamValueTree(const XAnim_s *anims, unsigned int animIndex, const char *paramName, float *outValue);
bool __cdecl XAnimGetParamValue(XAnimTree_s *tree, unsigned int animIndex, const char *paramName, float *outValue);
XAnim_s *XAnimCreateAnims(const char *debugName, int size, void *(*Alloc)(int));
void XAnimFreeTree(XAnimTree_s *tree, void (*Free)(void *, int));
void XAnimCalcAbsDeltaParts(XAnimRotPos *rotPos);
void XAnimUpdateInfoSync(int a1, const XAnimState *a2, const DObj *obj, unsigned int infoIndex, int notifyFlags, XAnimState *syncState, float dtime);
void XAnimUpdateTimeAndNotetrackLeaf(const DObj *obj, const XAnimParts *parts, unsigned int infoIndex, float dtime, int notifyFlags);
void XAnimUpdateTimeAndNotetrackSyncSubTree(const DObj *obj, unsigned int infoIndex, float dtime, int notifyFlags);
void XAnimUpdateTimeAndNotetrack(const XAnimParts *a1, const DObj *obj, unsigned int infoIndex, float dtime, int notifyFlags);
unsigned int __cdecl XAnimCloneInitTime(XAnimTree_s *tree, unsigned int infoIndex, unsigned int parentIndex, int cmdIndex);
unsigned int XAnimInitTime(XAnimTree_s *tree, unsigned int infoIndex, float goalTime, int cmdIndex);
void XAnimUpdateOldTime(DObj *obj, unsigned int infoIndex, XAnimState *syncState, float dtime, bool parentHasWeight, bool *childHasTimeForParent);
void XAnimCalcDeltaTree(XAnimRotPos *a1, XAnimRotPos *a2, const DObj *obj, const unsigned int infoIndex, const float weightScale, const XAnimDeltaInfo deltaInfo, XAnimRotPos *rotPos);
void DObjInitServerTime(DObj *obj, float dtime);
void DObjUpdateClientInfo(DObj *obj, float dtime, int notifyFlags);
void DObjUpdateServerInfo(DObj *obj, float dtime, int notifyFlags);
void XAnimDisplay(const XAnimTree_s *tree, unsigned int infoIndex, int depth, char *buffer, int bufferSize, int *bufferPos);
void DObjDisplayAnimToBuffer(const DObj *obj, const char *header, char *buffer, int bufferSize);
void DObjDisplayAnim(const DObj *obj, const char *header);
void XAnimCalcDelta(DObj *obj, unsigned int animIndex, vec2_t *rot, vec3_t *trans, bool bUseGoalWeight);
void XAnimCalcAbsDelta(DObj *obj, unsigned int animIndex, vec4_t *rot, vec3_t *trans);
void XAnimGetRelDelta(const XAnim_s *anims, unsigned int animIndex, vec2_t *rot, vec3_t *trans);
void XAnimGetAbsDelta(const XAnim_s *anims, unsigned int animIndex, vec4_t *rot, vec3_t *trans);
int XAnimSetCompleteGoalWeightNode(unsigned int notifyType, unsigned int notifyName, XAnimTree_s *tree, unsigned int infoIndex, float goalWeight, float goalTime, int cmdIndex);
void XAnimSetTime(unsigned int a1, XAnimTree_s *tree, unsigned int animIndex, float time, int cmdIndex);
unsigned int __cdecl XAnimRestart(XAnimTree_s *tree, unsigned int infoIndex, float goalTime, int cmdIndex);
unsigned int XAnimGetAnimMap(const XAnimParts *parts, const XModelNameMap *modelMap);
void XAnimResetAnimMapLeaf(const XModelNameMap *modelMap, unsigned int infoIndex);
void XAnimResetAnimMap_r(unsigned int a1, const XModelNameMap *a2, XModelNameMap *modelMap, unsigned int infoIndex);
void XAnimResetAnimMap(int a1, const DObj *obj, unsigned int infoIndex);
unsigned int XAnimAllocInfoIndex(unsigned int animIndex);
XAnimInfo *XAnimAllocInfo(DObj *obj, unsigned int animIndex);
int XAnimSetCompleteGoalWeightKnob(unsigned int a1, char *a2, DObj *obj, unsigned int animIndex, float goalWeight, float goalTime, float rate, unsigned int notifyName, unsigned int notifyType, int bRestart, int cmdIndex);
int XAnimSetGoalWeightKnob(unsigned int a1, DObj *obj, unsigned int animIndex, float goalWeight, float goalTime, float rate, unsigned int notifyName, unsigned int notifyType, int bRestart, int cmdIndex);
int XAnimSetGoalWeight(unsigned int a1, DObj *obj, unsigned int animIndex, float goalWeight, float goalTime, float rate, unsigned int notifyName, unsigned int notifyType, int bRestart, int cmdIndex);
int XAnimSetCompleteGoalWeight(unsigned int a1, DObj *obj, unsigned int animIndex, float goalWeight, float goalTime, float rate, unsigned int notifyName, unsigned int notifyType, int bRestart, int cmdIndex);
int XAnimSetGoalWeightKnobAll(DObj *obj, unsigned int animIndex, unsigned int rootIndex, float goalWeight, float goalTime, float rate, unsigned int notifyName, unsigned int notifyType, int bRestart, int cmdIndex);
int XAnimSetCompleteGoalWeightKnobAll(char *a1, DObj *obj, unsigned int animIndex, unsigned int rootIndex, float goalWeight, float goalTime, float rate, unsigned int notifyName, unsigned int notifyType, int bRestart, int cmdIndex);

//t6/code/src_noserver/xanim/xanim_calc.cpp
void XAnim_CalcPosDeltaEntire(const XAnimDeltaPart *animDelta, __m128 *posDelta);
void XAnimClearRotTransArray(const DObj *obj, DObjAnimMat *rotTransArray, XAnimCalcAnimInfo *info);
// void XAnimCalcNonLoopEnd(const XAnimParts *parts, const unsigned __int8 *animToModel, float weightScale, DObjAnimMat *rotTransArray, const bitarray<160> *ignorePartBits);
void XAnimScaleRotTransArray(int numBones, const XAnimCalcAnimInfo *info, DObjAnimMat *rotTransArray);
void XAnimNormalizeRotScaleTransArray(int numBones, const XAnimCalcAnimInfo *info, float weightScale, DObjAnimMat *rotTransArray);
void XAnimMadRotTransArray(int numBones, const XAnimCalcAnimInfo *info, float weightScale, const DObjAnimMat *rotTrans, DObjAnimMat *totalRotTrans);
void XAnimApplyAdditives(DObjAnimMat *rotTransArray, DObjAnimMat *additiveArray, float weight, int boneCount, XAnimCalcAnimInfo *info);
void XAnim_CalcDeltaForTime(int a1, const XAnimDeltaPart *a2, const XAnimParts *anim, const float time, vec2_t *rotDelta, __m128 *posDelta);
void XAnim_CalcDelta3DForTime(int a1, const XAnimDeltaPart *a2, const XAnimParts *anim, const float time, vec4_t *rotDelta, __m128 *posDelta);
// void XAnimCalcLeafInternal(const XAnimParts *parts, unsigned __int16 animToModelIndex, float time, float weightScale, DObjAnimMat *rotTransArray, bitarray<160> *animPartBits, const bitarray<160> *ignorePartBits);
void XAnimCalcLeaf(XAnimInfo *info, float weightScale, DObjAnimMat *rotTransArray, XAnimCalcAnimInfo *animInfo);
void XAnimCalc(const DObj *obj, XAnimInfo *info, float weightScale, bool bClear, bool bNormQuat, XAnimCalcAnimInfo *animInfo, int rotTransArrayIndex, DObjAnimMat *rotTransArray);
void DObjCalcAnim(int a1, const DObj *obj, int *partBits);

//t6/code/src_noserver/xanim/xanim_clientnotify.cpp
// void XAnimClientNotifyList::XAnimClientNotifyList(XAnimClientNotifyList *notthis);
// void XAnimClientNotifyList::GetNotifyList(bdTrulyRandomImpl *notthis);
// BOOL XAnimClientNotify::IsClientAnimNotify(XAnimClientNotify *notthis);
// const char *XAnimClientNotify::GetNotifyStringName(XAnimClientNotify *notthis);
// unsigned int XAnimClientNotify::GetNotifyType(XAnimClientNotify *notthis);
// unsigned int XAnimClientNotify::GetNotifyName(XAnimClientNotify *notthis);
// void XAnimClientNotifyList::~XAnimClientNotifyList(XAnimClientNotifyList *notthis);
// void XAnimClientNotifyList::AddNotify(XAnimClientNotifyList *notthis, const ClientNotifyData *notifyData);

//#include "xanim/xanim_load_db.h"

//t6/code/src_noserver/xanim/xanim_load_obj.cpp
void ConsumeQuat(const unsigned __int8 **pos, __int16 *out);
void ConsumeQuat2(const unsigned __int8 **pos, __int16 *out);
void ReadNoteTracks(const char *name, const unsigned __int8 **pos, XAnimParts *parts, void *(*Alloc)(int));
const unsigned __int8 *GetDeltaQuaternions2(XAnimDeltaPart *deltaPart, void *(*Alloc)(int), const unsigned __int8 *pos, unsigned __int16 numloopframes, bool useSmallIndices);
const unsigned __int8 *GetDeltaQuaternions(__int16 *a1, const unsigned __int8 **a2, XAnimDeltaPart *deltaPart, void *(*Alloc)(int), const unsigned __int8 *pos, unsigned __int16 numloopframes, bool useSmallIndices);
const unsigned __int8 *LoadTrans(void *(*Alloc)(int), const unsigned __int8 *pos, unsigned __int16 numTransIndices, XAnimPartTrans *trans);
const unsigned __int8 *GetDeltaTranslations(const char *name, XAnimDeltaPart *deltaPart, void *(*Alloc)(int), const unsigned __int8 *pos, unsigned __int16 numloopframes, bool useSmallIndices);
void *XAnimTempAlloc(int size);
unsigned __int8 *GetQuaternions(__int16 *a1, const unsigned __int8 **a2, XAnimPartQuatPtr *part, const unsigned __int8 *pos, bool bFlipQuat, bool bSimpleQuat, unsigned __int16 numloopframes, bool useSmallIndices);
const unsigned __int8 *GetTranslations(XAnimPartTransPtr *part, const unsigned __int8 *pos, unsigned __int16 numloopframes, bool useSmallIndices);
int XAnimCompareQuatParts(const void *p0, const void *p1);
int XAnimCompareTransParts(const void *p0, const void *p1);
int XAnimIsHighPrecisionPart(const char *name);
void XAnimEmitFrameIndices(unsigned int tableSize, unsigned __int8 **dataByte, __int16 **dataShort, XAnimIndices *indices, XAnimDynamicIndices *frameIndices, bool useSmallIndices);
XAnimParts *XAnimLoadFile(const char *name, void *(*Alloc)(int), bool streamedVersion);

//t6/code/src_noserver/xanim/xanim_readwrite.cpp
void XAnimLoadAnimTree(DObj *obj, MemoryFile *memFile);

//t6/code/src_noserver/xanim/xmodel.cpp
BOOL XModelBad(const XModel *model);
void TRACK_xmodel();
void XModelReleaseResources(XModel *model);
void XModelPartsFree(XModelPartsLoad *modelParts);
void XModelMakeDefault(XModel *model);
XModelPartsLoad *XModelPartsFindData(const char *name);
void XModelPartsSetData(const char *name, XModelPartsLoad *modelParts, void *(*Alloc)(int));
XModel *XModelPrecache_LoadObj(const char *name, void *(*Alloc)(int), void *(*AllocColl)(int));
XModel *XModelPrecache_FastFile(const char *name);
XModel *XModelPrecache();
unsigned __int16 *XModelBoneNames(XModel *model);
double XModelGetRadius(const XModel *model);
void XModelGetBounds(const XModel *model, vec3_t *mins, vec3_t *maxs);
void XModelRenderString(const vec3_t *pos, const char *string);
int XModelTraceLineAnimated(unsigned int a1, const DObj *obj, unsigned int modelIndex, int baseBoneIndex, trace_t *results, const DObjAnimMat *boneMtxList, vec3_t *localStart, vec3_t *localEnd, int contentmask);
void XModelTraceLineAnimatedPartBits(const DObj *obj, unsigned int modelIndex, int baseBoneIndex, int contentmask, int *partBits);
void XSurfaceVisitTrianglesInAabb_ConvertAabb(const XSurfaceCollisionTree *tree, const vec3_t *aabbMins, const vec3_t *aabbMaxs, int *mins, int *maxs);
bool XSurfaceVisitTrianglesInAabb_ProcessVertices(XSurfaceGetTriCandidatesLocals *locals);
bool XSurfaceVisitTrianglesInAabb_ProcessTriangles(XSurfaceGetTriCandidatesLocals *locals);
int XModelTraceLine(int a1, const XModel *model, trace_t *results, const vec3_t *localStart, const vec3_t *localEnd, int contentmask);
bool XSurfaceVisitTrianglesInAabb_ProcessLeaf(XSurfaceGetTriCandidatesLocals *locals);
char XSurfaceVisitTrianglesInAabb_ProcessNode(XSurfaceGetTriCandidatesLocals *locals);
char XSurfaceVisitTrianglesInAabb(const XSurface *surface, unsigned int vertListIndex, const vec3_t *aabbMins, const vec3_t *aabbMaxs, bool (*visitorFunc)(void *, const unsigned __int8 **, const unsigned __int8 **), void *visitorContext);

//#include "xanim/xmodel_load_db.h"

//t6/code/src_noserver/xanim/xmodel_load_obj.cpp
PhysConstraints *XModel_PhysConstraintsPrecache(const char *name, void *(*Alloc)(int));
void ConsumeQuatNoSwap(const unsigned __int8 **pos, __int16 *out);
bool XModelLoadConfigFile(const char *name, const unsigned __int8 **pos, XModelConfig *config);
void XModelLoadCollData(const unsigned __int8 **pos, XModel *model, void *(*AllocColl)(int), const char *name, unsigned int materialType);
void XModelCopyXModelParts(const XModelPartsLoad *modelParts, XModel *model);
void R_GetXModelBounds(XModel *model, const vec3_t *axes, vec3_t *mins, vec3_t *maxs);
int XModelGetFlags(const XModel *model);
XModelPieces *XModelPiecesLoadFile(const char *name, void *(*Alloc)(int));
XModelPieces *XModelPiecesPrecache(const char *name, void *(*Alloc)(int));
int XModelGetStaticBounds(const XModel *model, const vec3_t *axis, vec3_t *mins, vec3_t *maxs);
int XModelGetStaticBoundsExact(const XModel *model, const vec3_t *axis, vec3_t *mins, vec3_t *maxs);
int XModelGetStaticBounds(const XModel *model, vec3_t *mins, vec3_t *maxs);
void XModelCalcBasePose(XModelPartsLoad *modelParts);
XModelPartsLoad *XModelPartsLoadFile(XModel *model, const char *name, void *(*Alloc)(int), __int64 *xmodelModifiedTime);
XModelPartsLoad *XModelPartsPrecache(XModel *model, const char *name, void *(__cdecl *Alloc)(int), __int64 *xmodelModifiedTime);
XModel *XModelLoadFile(const char *name, void *(*Alloc)(int), void *(*AllocColl)(int), __int64 *xmodelModifiedTime);
XModel *XModelLoad(const char *name, void *(*Alloc)(int), void *(*AllocColl)(int));

//t6/code/src_noserver/xanim/xmodel_load_phys_collmap.cpp
char RemoveDuplicateBrushPlanes(vec4_t *planes, unsigned int *sideCount, const char *mapname, unsigned int brushnum);
bool SnapAxialVector(vec3_t *normal);
void SnapPlane(vec4_t *plane);
unsigned int GetPlaneIntersections(const vec4_t *planes, unsigned int planeCount, SimplePlaneIntersection *OutPts, unsigned int maxPtCount);
bool Map_SkipNamedFlags(const char **file, const char *key);
void GetCollisionMaterial(const char *name, collision_material_t *cmat);
int IsAxisAligned(vec3_t *normal);
bool Xmodel_ParsePhysicsBrush(const char **file, const char *mapname, unsigned int brushCount, PhysGeomInfo *geom, unsigned int boneHash, DObjAnimMat *boneMat, void *(*Alloc)(int));
bool Xmodel_ParsePhysicsBox(const char **file, PhysGeomInfo *geom);
bool Xmodel_ParsePhysicsCylinder(const char **file, PhysGeomInfo *geom);
char SkipEpair(const char *token, const char **file);
bool AddBoneName(unsigned int *boneNameArray, const int boneNameLen, const char *boneName);
int Xmodel_CountPhysicsCollMaps(const char *name, const char **file, unsigned int *boneHashes, const int boneNameLen);
unsigned int Xmodel_CountPhysicsCollMapGeoms(const char **file, const char *name, unsigned int boneHash);
PhysGeomList *Xmodel_ParsePhysicsCollMap(DObjAnimMat *boneMat, void *(*Alloc)(int), const char **file, const char *name, unsigned int geomCount, unsigned int boneHash);
void XModel_LoadCollMap(const char *name, void *(*Alloc)(int), XModel *model, const char *xmodelName);

//t6/code/src_noserver/xanim/xmodel_utils.cpp
const char *XModelGetName(const XModel *model);
int XModelGetSurfaces(const XModel *model, XSurface **surfaces, int submodel);
XModelLodInfo *XModelGetLodInfo(const XModel *model, int lod);
unsigned int XModelGetSurfCount(const XModel *model, int lod);
Material **XModelGetSkins(const XModel *model, int lod);
XModelLodRampType XModelGetLodRampType(const XModel *model);
int XModelGetNumLods(const XModel *model);
double XModelGetLodOutDist(const XModel *model);
LocalClientNum_t XModelNumBones(const cpose_t *pose);
int XModelGetBoneIndex(const XModel *model, unsigned int name, unsigned int offset, unsigned __int8 *index);
int XModelGetParentBoneName(const XModel *model, unsigned int name);
DObjAnimMat *XModelGetBasePose(const XModel *model);
int XModelGetLodForDist_Internal(const XModel *model, float dist);
int XModelGetLodForDist(const XModel *model, float adjustedDist, float baseDist, int noLodCullOut);
void XModelSetTestLods(int lodLevel, float dist);
int XModelGetContents(const XModel *model);
BOOL XModelHasCollmap(const XModel *model);
BOOL XModelHasCollision(const XModel *model);
PhysGeomList *XModelGetCollmap(const XModel *model, int collMapIndex);
PhysGeomList *XModelGetCollmapForBoneIndex(const XModel *model, int boneIndex);
int XModelGetBoneIndex(const XModel *model, unsigned int name, unsigned __int8 *index);

