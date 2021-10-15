#pragma once

#include "types.h"

//#include "qcommon/bitarray.h"

//t6/code/src_noserver/qcommon/cmd.cpp
void TRACK_cmd();
void Cmd_SetZM_f();
void Cmd_Wait_f();
void Cbuf_Init();
void Cmd_ShiftArgs(int count, CmdArgs *args);
void Cbuf_AddText(LocalClientNum_t localClientNum, const char *text);
void Cbuf_InsertText(LocalClientNum_t localClientNum, const char *text);
void Cbuf_AddServerText_f();
void Cmd_AddServerCommandInternal(const char *cmdName, void (*function)(), cmd_function_s *allocedCmd);
bool Cmd_ExecFromDiskAddText(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, const char *filename);
void Cmd_ExecAddText_f();
void SV_Cmd_ArgvBuffer(int arg, char *buffer, int bufferLength);
void Cmd_ArgsBuffer(int start, char *buffer, int bufLength);
bool Cmd_IsWhiteSpaceChar(char letter);
void Cmd_EmitChar(char letter, CmdArgs *argsPriv);
void Cmd_EmitString(const char *str, CmdArgs *argsPriv);
void Cmd_EvaluateExpression(const char **text_in, CmdArgs *argsPriv);
int Cmd_TokenizeStringInternal(const char *text_in, int max_tokens, bool evalExpressions, const char **argv, CmdArgs *argsPriv);
void AssertCmdArgsConsistency(const CmdArgs *args);
void Cmd_TokenizeStringKernel(LocalClientNum_t localClientNum, ControllerIndex_t localControllerIndex, itemDef_s *item, const char *text_in, int max_tokens, bool evalExpressions, CmdArgs *args);
void Cmd_EndTokenizedStringKernel(CmdArgs *args);
void Cmd_TokenizeStringWithLimit(const char *text_in, int max_tokens);
void Cmd_TokenizeString(const char *text_in);
void Cmd_TokenizeStringNoEval(const char *text_in);
void Cmd_EndTokenizedString();
void SV_Cmd_TokenizeString(const char *text_in);
void SV_Cmd_EndTokenizedString();
cmd_function_s *Cmd_FindCommand(const char *cmdName);
void Cmd_AddCommandInternal(const char *cmdName, void (*function)(), cmd_function_s *allocedCmd);
void Cmd_RemoveCommand(const char *cmdName);
void Cmd_SetAutoComplete(const char *cmdName, const char *dir, const char *ext);
void Cmd_Shutdown();
void Cmd_ForEach(void (*callback)(const char *));
void Cmd_ForEach(LocalClientNum_t localClientNum, void (*callback)(LocalClientNum_t, const char *));
const char **Cmd_GetAutoCompleteFileList(const char *cmdName, int *fileCount, int allocTrackType);
void Cmd_ComErrorCleanup();
void Cmd_List_f();
void Cmd_DObjDump();
void Cmd_HandleMissingCommand(const char *msg, bool fromRemoteConsole);
void Cmd_ExecuteServerString(const char *text);
void Cbuf_SV_Execute();
void Cmd_ExecuteSingleCommandInternal(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, itemDef_s *item, const char *text, bool fromRemoteConsole);
void Cmd_ExecuteSingleCommand(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, const char *text, bool fromRemoteConsole);
void SV_Cmd_ExecuteString(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, const char *text);
void ExecuteRestOfCommand();
void Cmd_IfMP_f();
void Cbuf_ExecuteBufferInternal(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, itemDef_s *item, const char *buffer);
void Cbuf_ExecuteBuffer(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, const char *buffer);
void Cbuf_ExecuteBufferUI(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, itemDef_s *item, const char *buffer);
void Cbuf_ExecuteInternal(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex);
void Cbuf_Execute(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex);
bool Cmd_ExecFromDisk(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex, const char *filename);
void Cmd_Exec_f();
void Cmd_Init();

//#include "qcommon/cmd.h"

//#include "qcommon/cm_brush_related_load_db.h"

//t6/code/src_noserver/qcommon/cm_load.cpp
void TRACK_cm_load();
void Load_ClipInfoFixup(ClipInfo **pInfo, ClipInfo *info);
void CM_InitThreadData(int threadContext);
unsigned __int16 *CM_InitAllThreadData();
void CM_LoadMapData_LoadObj(const char *name);
void CM_LoadMapData_FastFile(const char *name);
void CM_LoadMap(const char *name, int *checksum);
void CM_LoadAddonMapEnts_FastFile(const char *name);
void CM_LoadAddonMapEnts(const char *name);
void CM_LoadAddOnMapEnts(const char *name);
void Rope_InitRopes();
void ShutdownRopes();
void CM_Shutdown();
void CM_Unload();
void CM_ModelBounds(unsigned int model, vec3_t *mins, vec3_t *maxs);
int CM_ModelSurfaceFlags(unsigned int model);
void *CM_Hunk_Alloc(int size, const char *name, int type);
void CM_Hunk_CheckTempMemoryHighClear(int a1, int a2);
void *CM_Hunk_AllocateTempMemoryHigh(int size, const char *name);
void __cdecl CM_Hunk_ClearTempMemoryHigh();

//t6/code/src_noserver/qcommon/cm_load_obj.cpp
unsigned int CMod_LoadMaterials();
void CMod_LoadSubmodels();
float CMod_GetPartitionScore(unsigned __int16 *leafBrushes, int numLeafBrushes, int axis, const vec3_t *mins, const vec3_t *maxs, float *dist);
cLeafBrushNode_s *CMod_PartionLeafBrushes_r(char *a1, unsigned __int16 *leafBrushes, int numLeafBrushes, const vec3_t *mins, const vec3_t *maxs);
void CMod_PartionLeafBrushes(unsigned __int16 *leafBrushes, int numLeafBrushes, cLeaf_s *leaf);
unsigned int CMod_LoadSubmodelBrushNodes(char *a1);
cNode_t *CMod_LoadNodes();
vec3_t *CMod_LoadBrushes();
void CMod_LoadLeafs(bool usePvs);
void CMod_LoadLeafs_Version14(bool usePvs);
int *CMod_LoadLeafBrushNodes(char *a1);
int *CMod_LoadLeafBrushNodes_Version14(char *a1);
void CMod_LoadPlanes();
unsigned __int16 *CMod_LoadLeafBrushes();
CollisionPartition *CMod_LoadCollisionPartitions();
CollisionAabbTree *CMod_LoadCollisionAabbTrees();
bool MapEnts_CanPurgeEntity(const char *classname, void *userData, const char *(*GetKeyCallback)(void *, const char *));
const char *CMod_GetSpawnString(void *userData, const char *key);
MapEnts *MapEnts_GetFromString(const char *name, const char *entityString);
void CMod_LoadVisibility();
unsigned int EmitTechniqueSetName(const char *techSetName, char **emittedTechSetNames, unsigned int emittedCount);
unsigned int AppendTechniqueSetName(char *name, unsigned int nameLen, const char *append, char lyrToken);
LayeredTechniqueSetName *FindLayeredTechniqueSetNameInTable(const char *techSetName);
const LayeredTechniqueSetName *GetLayeredTechniqueSetName(const char *mtlName);
unsigned int AssembleLayeredMaterial(const dmaterial_t *diskMtl, const LayeredTechniqueSetName **lyrTechSetName, const char *lyrMtlName, char **emittedTechSetNames, unsigned int emittedCount);
int CompareTechSetNames(const void *e0, const void *e1);
unsigned int CM_InitBoxHull();
cplane_s *CM_GetPlanes();
int CM_GetPlaneCount();
char *CM_EntityString();
void CMod_LoadBrushRelated(unsigned int version, bool usePvs);
// void RunPIMP(const std::string *MaterialSubset);
void AssembleBspLayeredMaterials(char *a1);
void CM_LoadMapFromBsp(const char *name, char usePvs);

//#include "qcommon/cm_local_load_db.h"

//t6/code/src_noserver/qcommon/cm_mesh.cpp
bool CM_IsEdgeWalkable(int triIndex, int edgeIndex);
void CM_TracePointThroughTriangle(const traceWork_t *tw, const unsigned __int16 *indices, trace_t *trace);
SphereEdgeTraceResult CM_TraceSphereThroughEdge(const traceWork_t *tw, const vec3_t *sphereStart, const vec3_t *v0, const vec3_t *v0_v1, trace_t *trace);
void CM_TraceSphereThroughVertex(const traceWork_t *tw, bool isWalkable, const vec3_t *sphereStart, const vec3_t *v, trace_t *trace);
void CM_TraceCapsuleThroughTriangle(const traceWork_t *tw, int triIndex, const unsigned __int16 *indices, trace_t *trace);
void CM_ClosestPointOnTri(const vec3_t *pt, const vec3_t *v0, const vec3_t *e0, const vec3_t *e1, float a01, vec3_t *ptOnTri);
float CM_DistanceSquaredBetweenSegments(const vec3_t *start0, const vec3_t *start1);
bool CM_DoesCapsuleIntersectTriangle(const vec3_t *start, const vec3_t *end, float radiusSq, const unsigned __int16 *indices);
void CM_PositionTestCapsuleInTriangle(const traceWork_t *tw, const unsigned __int16 *indices, trace_t *trace);
void CM_TraceThroughAabbTree_work(const traceWork_t *tw, const CollisionAabbTree *aabbTree, trace_t *trace);
void CM_TraceThroughAabbTree_r(const traceWork_t *tw, trace_t *trace);
void CM_TraceThroughPartition(int a1, const traceWork_t *tw, int partitionIndex, trace_t *trace);
void CM_PositionTestInAabbTree_r(const traceWork_t *tw, CollisionAabbTree *aabbTree, trace_t *trace);
void CM_TraceThroughAabbTree(const traceWork_t *tw, const CollisionAabbTree *aabbTree, trace_t *trace);
void CM_MeshTestInLeaf(const traceWork_t *tw, cLeaf_s *leaf, trace_t *trace);
void __cdecl CM_MeshTest(const traceWork_t *tw, const CollisionAabbTree *tree, trace_t *trace);

//#include "qcommon/cm_public.h"

//t6/code/src_noserver/qcommon/cm_showcollision.cpp
void TRACK_cm_showcollision();
bool CM_BrushInView(const cbrush_t *brush, cplane_s *frustumPlanes, int frustumPlaneCount);
int CM_AddSimpleBrushPoint(const cbrush_t *brush, const vec4_t *axialPlanes, const __int16 *sideIndices, const vec3_t *xyz, int ptCount, ShowCollisionBrushPt *brushPts);
void CM_GetPlaneVec4Form(const cbrushside_t *sides, const vec4_t *axialPlanes, int index, vec4_t *expandedPlane);
int CM_ForEachBrushPlaneIntersection(const cbrush_t *brush, const vec4_t *axialPlanes, ShowCollisionBrushPt *brushPts);
int CM_GetXyzList(int sideIndex, const ShowCollisionBrushPt *pts, int ptCount, vec3_t *xyz, int xyzLimit);
void CM_AddColinearExteriorPointToWindingProjected(winding_t *w, const vec3_t *pt, int i, int j, int index0, int index1);
void CM_AddExteriorPointToWindingProjected(winding_t *w, const vec3_t *pt, int i, int j);
float CM_RepresentativeTriangleFromWinding(const winding_t *w, const vec3_t *normal, int *i0, int *i1, int *i2);
void CM_ReverseWinding(winding_t *w);
bool CM_BuildBrushWindingForSide(winding_t *winding, vec3_t *planeNormal, int sideIndex, const ShowCollisionBrushPt *pts, int ptCount);
void CM_ShowSingleBrushCollision(const cbrush_t *brush, const vec4_t *color, void (*drawCollisionPoly)(int, vec3_t *, const vec4_t *));
void CM_ShowBrushCollision(int contentMask, cplane_s *frustumPlanes, int frustumPlaneCount, void (*drawCollisionPoly)(int, vec3_t *, const vec4_t *));

//t6/code/src_noserver/qcommon/cm_staticmodel.cpp
void *CM_Hunk_AllocXModel(int size);
void *CM_Hunk_AllocXModelColl(int size);
XModel *CM_XModelPrecache(const char *name);
void CM_TraceStaticModel(cStaticModel_s *sm, trace_t *results, const vec3_t *start, const vec3_t *end, int contentmask);
BOOL CM_TraceStaticModelComplete(unsigned int a1, cStaticModel_s *sm, const vec3_t *start, const vec3_t *end, int contentmask);

//t6/code/src_noserver/qcommon/cm_staticmodel_load_obj.cpp
void CM_InitStaticModel(cStaticModel_s *staticModel, vec3_t *origin, vec3_t *angles, float scale);
bool CM_CreateStaticModel(cStaticModel_s *staticModel, const char *name, vec3_t *origin, vec3_t *angles, float scale);
void CM_LoadStaticModels(char *a1);

//t6/code/src_noserver/qcommon/cm_test.cpp
int CM_PointLeafnum_r(const vec3_t *p, int num);
void CM_StoreLeafs(leafList_s *ll, int nodenum);
void CM_BoxLeafnums_r(int a1, leafList_s *a2, leafList_s *ll, int nodenum);
int CM_PointContentsLeafBrushNode_r(const vec3_t *p, cLeafBrushNode_s *node);
int CM_PointContents(const vec3_t *p, unsigned int model);
int CM_TransformedPointContents(const vec3_t *p, unsigned int model, const vec3_t *origin, const vec3_t *angles);

//t6/code/src_noserver/qcommon/cm_trace.cpp
// void col_context_t::col_context_t(col_context_t *notthis);
// void col_context_t::col_context_t(col_context_t *notthis, int _mask);
// void col_context_t::init_locational(col_context_t *notthis, int ent0);
// void col_context_t::init_locational(col_context_t *notthis, int ent0, int ent1);
int Trace_GetEntityHitId(const trace_t *trace);
unsigned __int16 Trace_GetDynEntHitId(const trace_t *trace, DynEntityDrawType *drawType);
int Trace_GetGlassHitId(const trace_t *trace);
void CM_GetTraceThreadInfo(TraceThreadInfo *threadInfo);
clipMap_t *CM_GetClipMap();
void CM_GetBox(cbrush_t **box_brush, cmodel_t **box_model, PhysGeomList ***geoms);
unsigned int CM_TempBoxModel(cmodel_t **a1, const vec3_t *mins, const vec3_t *maxs, int contents);
unsigned int CM_TempBrushModel(cmodel_t **a1, PhysGeomList *geoms);
bool CM_ClipHandleIsValid(unsigned int handle);
cmodel_t *CM_ClipHandleToModel(cmodel_t **a1, unsigned int handle);
int CM_ContentsOfModel(cmodel_t **a1, unsigned int handle);
void CM_TestBoxInBrush(const traceWork_t *tw, const cbrush_t *brush, trace_t *trace);
void CM_TestInLeafBrushNode_r(const traceWork_t *tw, cLeafBrushNode_s *node, trace_t *trace);
int CM_TestInLeafBrushNode(traceWork_t *tw, cLeaf_s *leaf, trace_t *trace);
void CM_TestCapsuleInCapsule(const traceWork_t *tw, trace_t *trace);
void CM_PositionTest(traceWork_t *tw, trace_t *trace, col_context_t *context);
void CM_TraceThroughBrush(const traceWork_t *tw, const cbrush_t *brush, trace_t *trace);
void CM_TraceThroughLeafBrushNode_r(const traceWork_t *tw, cLeafBrushNode_s *node, const vec4_t *p1_, const vec4_t *p2, trace_t *trace);
bool CM_TraceThroughLeafBrushNode(const traceWork_t *tw, cLeaf_s *leaf, trace_t *trace);
void CM_TraceThroughLeaf(const traceWork_t *tw, cLeaf_s *leaf, trace_t *trace);
void CM_TestInTempBrush(const traceWork_t *tw, trace_t *trace);
void __cdecl CM_TraceThroughTempBrush(const traceWork_t *tw, trace_t *trace);
int CM_TraceSphereThroughSphere(const traceWork_t *tw, const vec3_t *vStart, const vec3_t *vEnd, const vec3_t *vStationary, float radius, trace_t *trace);
int CM_TraceCylinderThroughCylinder(const traceWork_t *tw, const vec3_t *vStationary, float fStationaryHalfHeight, float radius, trace_t *trace);
void CM_TraceCapsuleThroughCapsule(const traceWork_t *tw, trace_t *trace);
void CM_TraceThroughTree(const traceWork_t *tw, int num, const vec4_t *p1_, const vec4_t *p2, trace_t *trace);
void CM_TraceThroughPrimitives(const traceWork_t *tw, trace_t *trace, col_context_t *context);
int CM_SightTraceThroughBrush(const traceWork_t *tw, const cbrush_t *brush, int brushNum, trace_t *trace);
int CM_SightTracePointThroughBrush(const TraceExtents *extents, const cbrush_t *brush);
int CM_SightTraceThroughLeafBrushNode_r(const traceWork_t *tw, cLeafBrushNode_s *remoteNode, const vec3_t *p1_, const vec3_t *p2, trace_t *trace);
int CM_SightTraceThroughLeafBrushNode(const traceWork_t *tw, const cLeaf_s *leaf, trace_t *trace);
int CM_SightTraceThroughLeaf(const traceWork_t *tw, const cLeaf_s *leaf, trace_t *trace);
int CM_SightTraceSphereThroughSphere(const traceWork_t *tw, const vec3_t *vStart, const vec3_t *vEnd, const vec3_t *vStationary, float radius, trace_t *trace);
int CM_SightTraceCylinderThroughCylinder(const traceWork_t *tw, const vec3_t *vStationary, float fStationaryHalfHeight, float radius, trace_t *trace);
int CM_SightTraceCapsuleThroughCapsule(const traceWork_t *tw, trace_t *trace);
int CM_SightTraceThroughTree(const traceWork_t *tw, int num, const vec3_t *p1_, const vec3_t *p2, trace_t *trace);
void calc_closest(const vec3_t *v0, const vec3_t *v1, const vec3_t *v2, const vec3_t *p, vec3_t *res);
bool is_inside(const vec3_t *a, const vec3_t *b, const vec3_t *n, const vec3_t *p);
bool point_in_triangle(const vec3_t *p, const vec3_t *v0, const vec3_t *v1, const vec3_t *v2, const vec3_t *n);
char trace_sphere_through_triangle(const vec3_t *c0, const vec3_t *dir, float *t, float r, const vec3_t *v0, const vec3_t *v1, const vec3_t *v2, const vec3_t *n);
void trace_sphere_through_partition(const vec3_t *c, const vec3_t *dir, float *t, const float r, const CollisionAabbTree *tree, vec3_t *hitn, int *sflags);
void trace_sphere_through_brush(const vec3_t *c0, const vec3_t *dir, float *t, const float r, const cbrush_t *brush, vec3_t *hitn, int *sflags, bool *startSolid);
void trace_sphere_through_brush(const vec3_t *c0, const vec3_t *dir, float *t, const float r, const cbrush_t *brush, vec3_t *hitn, int *sflags, bool *startSolid);
void trace_point_through_brush(const vec3_t *c0, const vec3_t *dir, float *t, const cbrush_t *brush, vec3_t *hitn, int *sflags, bool *startSolid);
char trace_point_through_triangle(const vec3_t *p0, const vec3_t *u0, const vec3_t *v0, const vec3_t *v1, const vec3_t *v2, const float cur_t, float *t);
void trace_sphere_through_partition(const vec3_t *p, const vec3_t *dir, float *t, const float r, const CollisionPartition *partition, vec3_t *hitn, int *hint, clipMap_t *pClipMap);
void trace_point_through_partition(const vec3_t *p, const vec3_t *dir, float *t, const CollisionPartition *partition, vec3_t *hitn, int *hint, clipMap_t *pClipMap);
void trace_point_vs_env(trace_t *trace, const vec3_t *start, const vec3_t *end, col_context_t *context, int *index_hint, clipMap_t *pClipMap);
void trace_point_vs_env(trace_t *trace, const vec3_t *start, const vec3_t *end, col_context_t *context, int *index_hint);
void trace_point_vs_env(trace_t *trace, const vec3_t *start, const vec3_t *end, col_context_t *context, int *index_hint, unsigned __int8 *pClipMap);
void trace_sphere_vs_env(trace_t *trace, const vec3_t *start, const vec3_t *end, const float radius, col_context_t *context, int *index_hint, clipMap_t *pClipMap);
void trace_sphere_vs_env(trace_t *trace, const vec3_t *start, const vec3_t *end, const float radius, col_context_t *context, int *index_hint, unsigned __int8 *pClipMap);
int collide_segment_brush(const vec3_t *p0, const vec3_t *p1, const cbrush_t *brush);
BOOL collide_segment_triangle(const vec3_t *p0, const vec3_t *u0, const vec3_t *v0, const vec3_t *v1, const vec3_t *v2);
int collide_segment(const vec3_t *p0, const vec3_t *p1, col_context_t *context);
bool CM_GetWaterForce(cmodel_t **plane, const vec3_t *pt, vec3_t *dir, float *force);
void CM_GetClosestPointToBrush(const vec3_t *p, const cbrush_t *brush, vec3_t *result);
int CM_SightTraceThroughTempBrush(const traceWork_t *tw, trace_t *trace);
int CM_BoxSightTrace(int a1, int oldHitNum, const vec3_t *start, const vec3_t *end, const vec3_t *mins, const vec3_t *maxs, unsigned int model, int brushmask);
int CM_SightTracePoint(int a1, int oldHitNum, const vec3_t *start, const vec3_t *end, col_context_t *context);
int CM_TransformedBoxSightTrace(int hitNum, const vec3_t *start, const vec3_t *end, const vec3_t *mins, const vec3_t *maxs, unsigned int model, int brushmask, const vec3_t *origin, const vec3_t *angles);
int CM_TracePointDown(int a1, const vec3_t *start, const vec3_t *end, int contentmask, int surf_type, vec3_t *endpos, float *fraction, vec3_t *normal);
double CM_GetWaterHeight(unsigned int a1, const vec3_t *pos, float z_up, float z_down);
void CM_Trace(unsigned int a1, col_context_t *a2, trace_t *results, const vec3_t *start, const vec3_t *end, const vec3_t *mins, const vec3_t *maxs, unsigned int model, int brushmask, col_context_t *context);
void CM_BoxTrace(col_context_t *a1, trace_t *results, const vec3_t *start, const vec3_t *end, const vec3_t *mins, const vec3_t *maxs, int brushmask, col_context_t *context);
void CM_TransformedBoxTraceRotated(trace_t *results, const vec3_t *start, const vec3_t *end, const vec3_t *mins, const vec3_t *maxs, unsigned int model, int brushmask, const vec3_t *origin, const vec3_t *matrix);
void CM_TransformedBoxTrace(trace_t *results, const vec3_t *start, const vec3_t *end, const vec3_t *mins, const vec3_t *maxs, unsigned int model, int brushmask, const vec3_t *origin, const vec3_t *angles);
void CM_TransformedBoxTraceExternal(trace_t *results, const vec3_t *start, const vec3_t *end, const vec3_t *mins, const vec3_t *maxs, unsigned int model, int brushmask, const vec3_t *origin, const vec3_t *angles);
char CM_GetHeliHeight(unsigned int a1, const vec3_t *pt, const float checkdist, float *result, const bool checkDisabledPatches);

//t6/code/src_noserver/qcommon/cm_tracebox.cpp
void CM_CalcTraceExtents(TraceExtents *extents);
int intersect_extents_aabb(const TraceExtents *extents, const vec3_t *mins, const vec3_t *maxs, float fraction);
int intersect_extents_aabb(const TraceExtents *extents, const vec3_t *mins, const vec3_t *maxs, float *enterFrac, float *leaveFrac);
BOOL intersect_extents_sphere(const TraceExtents *extents, const vec3_t *origin, float radius, float fraction);

//t6/code/src_noserver/qcommon/cm_world.cpp
void TRACK_cm_world();
unsigned __int16 CM_AllocWorldSector(vec2_t *mins, vec2_t *maxs);
int CM_ClearWorld();
void CM_UnlinkEntity(svEntity_s *ent);
void CM_AddEntityToNode(svEntity_s *ent, unsigned __int16 childNodeIndex);
void CM_AddStaticModelToNode(cStaticModel_s *staticModel, unsigned __int16 childNodeIndex);
void CM_SortNode(unsigned __int16 nodeIndex, vec2_t *mins, vec2_t *maxs);
void CM_LinkEntity(svEntity_s *ent, vec3_t *absmin, vec3_t *absmax, unsigned int clipHandle);
void CM_LinkAllStaticModels();
void CM_AreaEntities_r(unsigned int nodeIndex, areaParms_t *ap);
int CM_AreaEntities(const vec3_t *mins, const vec3_t *maxs, int *entityList, int maxcount, int contentmask);
void CM_PointTraceStaticModels_r(locTraceWork_t *tw, unsigned __int16 nodeIndex, const vec4_t *p1_, const vec4_t *p2, trace_t *trace);
int CM_PointTraceStaticModelsComplete_r(const staticmodeltrace_t *clip, unsigned __int16 nodeIndex, const vec3_t *p1_, const vec3_t *p2);
void CM_ClipMoveToEntities_r(const moveclip_t *clip, unsigned __int16 nodeIndex, const vec4_t *p1, const vec4_t *p2, trace_t *trace);
void CM_ClipMoveToEntities(moveclip_t *clip, trace_t *trace);
int CM_ClipSightTraceToEntities_r(const sightclip_t *clip, unsigned __int16 nodeIndex, const vec3_t *p1, const vec3_t *p2);
int CM_ClipSightTraceToEntities(sightclip_t *clip);
void CM_PointTraceToEntities_r(pointtrace_t *clip, unsigned __int16 nodeIndex, const vec4_t *p1, const vec4_t *p2, trace_t *trace, col_context_t *context);
void CM_PointTraceToEntities(pointtrace_t *clip, trace_t *trace, col_context_t *context);
int CM_PointSightTraceToEntities_r(const sightpointtrace_t *clip, unsigned __int16 nodeIndex, const vec3_t *p1, const vec3_t *p2);
int CM_PointSightTraceToEntities(sightpointtrace_t *clip);
void CM_LinkWorld();
int CM_PointTraceStaticModelsComplete(int a1, const vec3_t *start, const vec3_t *end, int contentmask);
void CM_PointTraceStaticModels(unsigned int a1, trace_t *results, const vec3_t *start, const vec3_t *end, int contentmask);

//t6/code/src_noserver/qcommon/common.cpp
void TRACK_common();
void Com_NTPSync_f();
bool Com_IsRunningMenuLevel(const char *name);
char Com_IsMenuLevel(const char *name);
void Com_AssetLoadUI(const char* name);
void Com_BeginRedirect(char *buffer, unsigned int buffersize, void (*flush)(char *));
void Com_EndRedirect();
void Com_OpenLogFile();
void Com_LogPrintMessage(int channel, const char *msg);
void Com_PrintMessage(int channel, const char *msg, int error);
void Com_Printf(int channel, const char *fmt, ...);
void Com_DPrintf(int channel, const char *fmt, ...);
void Com_PrintError(int channel, const char *fmt, ...);
void Com_PrintWarning(int channel, const char *fmt, ...);
void Com_InitDynamicRender();
void Com_ShutdownDynamicMemorySystems();
double Com_GetTimeScale();
void Com_SetTimeScale(float timescale);
void Com_StartHunkUsers();
bool Com_ErrorIsNotice(const char *errorMessage);
void Com_SetLocalizedErrorMessage(const char *localizedErrorMessage, const char *titleToken);
void Com_SetErrorMessage(const char *errorMessage);
void Com_PrintStackTrace(int code, void (*cb)(const char *));
void Com_ErrorAbort();
void Com_Error(errorParm_t code, const char *fmt, ...);
void Com_ParseCommandLine(char *commandLine);
int Com_SafeMode();
bool Com_StartupProcessSetCommand(int lineIndex, const char *match);
void Com_StartupVariable(const char *match);
void Com_AddStartupCommands();
void Info_Print(const char *s);
void *Com_AllocEvent(int size);
void Com_PacketEventLoop(LocalClientNum_t localClientNum, msg_t *netmsg);
char Com_ClientPacketEvent(int a1);
void Com_ServerPacketEvent();
void Com_EventLoop();
void Com_Error_f();
void Com_Freeze_f();
void Com_Crash_f();
unsigned int Com_CompressWithZLib(const unsigned __int8 *from, int inSizeBytes, unsigned __int8 *to, int outSizeBytes);
unsigned int Com_DecompressWithZLib(const unsigned __int8 *from, int inSizeBytes, unsigned __int8 *to, int outSizeBytes);
void Com_InitDvars();
void Com_CheckForInvites_f();
void Com_RunAutoExec(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex);
void Com_ExecStartupConfigs(LocalClientNum_t localClientNum, const char *configFile);
void Com_WriteConfigToFile(LocalClientNum_t localClientNum, const char *filename);
BOOL Com_isFullyInitialized();
void Com_WriteConfig_f();
void Com_WriteKeyConfig_f();
void Com_WriteDefaults_f();
double Com_GetTimescaleForSnd();
void Com_SetSlowMotion(const float startTimescale, const float endTimescale, const int deltaMsec);
void Com_ResetSlowMotion();
void Com_SetSlowMotionDelayed(const float startTimescale, const float endTimescale, const int deltaMsec, const int delayMsec);
double Com_ViewScaleMsec(float sec);
void Com_Frame_Try_Block_Function();
void Com_WriteConfiguration(LocalClientNum_t localClientNum);
char *Com_GetLevelSharedFastFile(const char *mapName);
void Com_LoadCommonFastFile();
void Com_LoadUiFastFile();
void Com_UnloadLevelFastFiles();
void Com_LoadLevelFastFiles(const char *mapName);
void Com_LoadLevelFastFiles_BlockForOverlay(const char *mapName);
void Com_UnloadFrontEnd();
void Com_ResetFrametime();
void Com_CheckSyncFrame();
BOOL Com_LogFileOpen();
void Field_Clear(field_t *edit);
void Com_Restart();
void *CG_AllocAnimTree(int size);
XAnimTree_s *Com_XAnimCreateSmallTree(XAnim_s *anims);
void Com_XAnimFreeSmallTree(XAnimTree_s *animtree);
void Com_SetWeaponInfoMemory(int source);
void Com_FreeWeaponInfoMemory(int source);
int Com_GetWeaponInfoMemory();
int Com_AddToString(const char *add, char *msg, int len, int maxlen, int mayAddQuotes);
char Com_GetDecimalDelimiter();
void Com_LocalizedFloatToString(float f, char *buffer, unsigned int maxlen, unsigned int numDecimalPlaces);
void Com_SyncThreads();
const char *Com_DisplayName(const char *name, const char *clanAbbrev, int type);
char *CS_DisplayName(const clientState_s *cs, int type);
int Com_GetPrivateClients();

// Added
void Com_InitUIAndCommonXAssets();

void NetAdr_SetType(netadr_t *addr, netadrtype_t type);
bool Com_UseRawUDP();
void Com_Quit_f();
void Com_InitDynamicMemorySystems();
void Com_ErrorCleanup();
void Com_Init_Try_Block_Function(char* commandLine);
void Com_Frame();
bool Com_SetPrivateClients();
void Com_ShutdownInternal(const char* finalmsg);
void Com_Shutdown(const char *finalmsg);
void Com_Init(char *commandLine);

//t6/code/src_noserver/qcommon/com_bsp.cpp
void Com_UnloadWorld();

//#include "qcommon/com_bsp_api.h"

//#include "qcommon/com_bsp_load_db.h"

//t6/code/src_noserver/qcommon/com_bsp_load_obj.cpp
unsigned int Com_GetBspLumpCountForVersion(const int version);
const void *Com_ValidateBspLumpData(LumpType type, unsigned int offset, unsigned int length, unsigned int elemSize, unsigned int *count);
const void *Com_GetBspLump(char *a1, LumpType type, unsigned int elemSize, unsigned int *count);
const void *Com_ReadLumpOutOfBspAtOffset(int h, LumpType type, unsigned int offset, unsigned int length, unsigned int elemSize, unsigned int *count);
const void *Com_ReadLumpOutOfBsp(int h, LumpType type, unsigned int elemSize, unsigned int *count);
const void *Com_LoadBspLump(const char *mapname, LumpType type, unsigned int elemSize, unsigned int *count);
void Com_UnloadBspLump(LumpType type);
BOOL Com_BspHasLump(LumpType a1, LumpType type);
unsigned int Com_GetBspVersion();
unsigned int Com_GetBspChecksum();
bool Com_CheckVersionLumpCountError(int version);
void Com_LoadBsp(const char *filename);
void Com_UnloadBsp();
void Com_CleanupBsp();
const char *Com_EntityString(LumpType a1, char *a2, char *a3, int *numEntityChars);
void Com_SaveLump(LumpType type, const void *newLump, unsigned int size, ComSaveLumpBehavior behavior);
const char *Com_GetHunkStringCopy(const char *string);
const char *Com_GetLightDefName(const char *defName, const ComPrimaryLight *primaryLights, unsigned int primaryLightCount);
void Com_LoadWorld_FastFile(const char *name);
void Com_ShutdownWorld();
void Com_LoadPrimaryLights(char *a1, LumpType a2);
void Com_LoadWorld_LoadObj(const char *name);
void Com_LoadWorld();

//t6/code/src_noserver/qcommon/com_buildinfo.cpp
char *Com_GetBuildVersion();
int Com_GetBuildNumber();
const char *Com_GetBuildMachine();
const char *Com_GetBuildTime();
const char *Com_GetBuildDisplayName();
const char *Com_GetBuildDisplayNameR();
const char *Com_GetBuildName();
const char *Com_GetBuildBaseName();
const char *Com_GetBuildConfig();
const char *Com_GetBuildMode();
int Com_GetChangelist();
char *Com_GetBuildInfoName();
int Com_GetBuildInfoVersion();

//t6/code/src_noserver/qcommon/com_clients.cpp
void Com_LocalClients_AssignUIContextsForInGame();
UIContextIndex_t Com_LocalClient_GetUIContextIndex(LocalClientNum_t localClientNum);
ControllerIndex_t Com_LocalClient_GetControllerIndex(LocalClientNum_t localClientNum);
netsrc_t Com_LocalClient_GetNetworkID(LocalClientNum_t localClientNum);
void Com_LocalClient_SetControllerIndex(LocalClientNum_t localClientNum, ControllerIndex_t controllerIndex);
void Com_LocalClient_SetPrimary(LocalClientNum_t localClientNum, bool primary);
LocalClientNum_t Com_LocalClients_GetPrimary();
LocalClientNum_t Com_LocalClients_GetPrimaryDefault();
bool Com_LocalClient_IsPrimary(LocalClientNum_t localClientNum);
BOOL Com_LocalClient_IsPrimarySet();
bool Com_LocalClient_IsBeingUsed(LocalClientNum_t localClientNum);
void Com_LocalClient_SetBeingUsed(LocalClientNum_t localClientNum, bool beingUsed);
bool Com_LocalClients_NoneBeingUsed();
int Com_LocalClients_GetUsedControllerCount();
LocalClientNum_t Com_ControllerIndex_GetLocalClientNum(ControllerIndex_t controllerIndex);
netsrc_t Com_ControllerIndex_GetNetworkID(ControllerIndex_t controllerIndex);
UIContextIndex_t Com_ControllerIndex_GetUIContextIndex(ControllerIndex_t controllerIndex);
ControllerIndex_t Com_ControllerIndexes_GetPrimary();
ControllerIndex_t Com_NetworkID_GetControllerIndex(netsrc_t netID);
void Com_LocalClient_LastInput_Set(LocalClientNum_t localClientNum, LastInput_t currentInput);
LastInput_t Com_LocalClient_LastInput_Get(LocalClientNum_t localClientNum);
void Com_InitClientGameStates();
void SwapClients(int clientA, int clientB);
void Com_LocalClients_CompressClients();

//t6/code/src_noserver/qcommon/com_fileaccess.cpp
unsigned int FS_FileWrite(const void* ptr, unsigned int len, FILE* stream);
unsigned int FS_FileRead(void* ptr, unsigned int len, FILE* stream);
FILE* FS_FileOpenReadText(const char* filename);
FILE* FS_FileOpenReadBinary(const char* filename);
FILE* FS_FileOpenWriteText(const char* filename);
FILE* FS_FileOpenWriteBinary(const char* filename);
int FS_FileGetFileSize(FILE* file);
void FS_FileClose(FILE* stream);
int FS_FileSeek(FILE* file, int offset, int whence);
FILE* FS_FileOpenAppendText(const char* filename);

//t6/code/src_noserver/qcommon/com_factions.cpp
const char *Com_FactionLookup(const char *mapName, int columnIndex);
BOOL Com_IsFactionFastfile(const char *mapName);
const char *Com_FactionLookupAxis(int columnIndex);
const char *Com_FactionLookupAllies(int columnIndex);
char Com_FactionFastFileAxis(const char *mapName, char *buffer, const int bufSize);
char Com_FactionFastFileAllies(const char *mapName, char *buffer, const int bufSize);

//t6/code/src_noserver/qcommon/com_gamemodes.cpp
const char *Com_GameMode_GetModeName();
BOOL Com_GameMode_IsModeSet();
bool Com_GameMode_IsMode(eGameModes mode);
void Com_GameMode_ResetModes();
int Com_GameMode_IsUsingXP();
BOOL Com_GameMode_IsUsingStats();
void Com_GameMode_WriteModes(msg_t *msg);
bool Com_GameMode_ReadModes(msg_t *msg);
bool ValidateGameModes();
void Com_GameMode_SetMode(eGameModes mode, bool value);

//t6/code/src_noserver/qcommon/com_gametypesettings.cpp
int Com_GametypeSetting_CacheDDLState();
const CACRoot *Com_GametypeSettings_GetCACRoot(const CACRoot *result, team_t team);
int Com_GametypeSettings_GetDDLMemberTypeForSetting(const char *settingName);
unsigned int Com_GametypeSettings_GetUInt(GameTypeSettingsType setting);
unsigned int Com_GametypeSettings_GetUInt(const char *settingName, bool getDefault);
double Com_GametypeSettings_GetFloat(const char *settingName, bool getDefault);
bool Com_GametypeSettings_SetUInt(const char *settingName, unsigned int newValue);
bool Com_GametypeSettings_SetFloat(const char *settingName, float newValue);
void Com_GametypeSettings_GametypeSetting_f();
bool Com_GametypeSettings_AreSettingsDirty();
void Com_GametypeSettings_ClearDirtyFlag();
char Com_GametypeSettings_Read(msg_t *msg);
void Com_GametypeSettings_Write(msg_t *msg);
int Com_GametypeSettings_ResetClassesToDefault();
team_t Com_GametypeSettings_GetCurrentPresetClassTeam();
bool Com_GametypeSettings_IsItemIndexRestricted(int itemIndex, bool getDefault);
bool Com_GametypeSettings_IsAttachmentIndexRestricted(int attachmentIndex, bool getDefault);
void Com_GametypeSettings_UploadSuccess(const ControllerIndex_t controllerIndex, unsigned __int64 fileID);
void Com_GametypeSettings_UploadFailure(const ControllerIndex_t controllerIndex);
bool Com_GametypeSetting_SetMetada(const ControllerIndex_t controllerIndex, unsigned __int8 *metaData, int metaDataSize);
void Com_GametypeSetting_Upload(const ControllerIndex_t controllerIndex, int slot);
void Com_GametypeSetting_DownloadFailure();
void Com_GametypeSettings_Upload_f();
void Com_GametypeSettings_ClearUploadInfo_f();
void Com_GametypeSettings_SetName(const char *name);
void Com_GametypeSettings_SetDescription(const char *description);
void Com_GametypeSettings_SetGametype(const char *a1, const dvar_t *a2, char *a3, const char *gametype, bool loadDefaultSettings);
void Com_GametypeSettings_SetGametype_f();
void Com_GametypeSettings_RestrictItem_f();
void Com_GametypeSettings_RestrictAttachment_f();
void Com_GametypeSetting_DownloadSuccess(const ControllerIndex_t controllerIndex, dwFileShareReadFileTask *task);
void Com_GametypeSetting_Download(const ControllerIndex_t controllerIndex, unsigned __int64 fileID, const char *gameType);
void __cdecl Com_GametypeSettings_Download_f();
void Com_GametypeSettings_Init();

//t6/code/src_noserver/qcommon/com_loadutils.cpp
const char *Com_LoadInfoString_LoadObj(const char *fileName, const char *fileDesc, const char *ident, char *loadBuffer);
const char *Com_LoadInfoString_FastFile(const char *fileName, const char *fileDesc, const char *ident);
const char *Com_LoadInfoString(const char *fileName, const char *fileDesc, const char *ident);
char *Com_LoadRawTextFile_LoadObj(const char *fullpath);
const char *Com_LoadRawTextFile_FastFile(const char *fullpath);
const char *Com_LoadRawTextFile();
void Com_UnloadRawTextFile(const char *filebuf);

//t6/code/src_noserver/qcommon/com_profilemapload.cpp
void TRACK_com_profilemapload();
bool ProfLoad_IsActive();
void ProfLoad_BeginTrackedValueTicks(MapProfileElement *value, unsigned __int64 ticks);
void ProfLoad_BeginTrackedValue(MapProfileTrackedValue type);
void ProfLoad_EndTrackedValueTicks(MapProfileElement *value, unsigned __int64 ticks);
void ProfLoad_EndTrackedValue(MapProfileTrackedValue type);
void ProfLoad_Init();
void ProfLoad_Activate();
MapProfileEntry *Com_GetEntryForNewLabel(const char *label);
void ProfLoad_CalculateSelfTicks();
void ProfLoad_GetEntryRowText(const MapProfileEntry *entry, char *rowText, int sizeofRowText);
void ProfLoad_PrintTree();
BOOL ProfLoad_CompareHotSpotNames(const MapProfileHotSpot *hotSpot0, const MapProfileHotSpot *hotSpot1);
BOOL ProfLoad_CompareHotSpotTicks(const MapProfileHotSpot *hotSpot0, const MapProfileHotSpot *hotSpot1);
void ProfLoad_Begin(const char *label);
void ProfLoad_End();
void ProfLoad_DrawTree();
void ProfLoad_DrawOverlay(rectDef_s *rect);
void ProfLoad_PrintHotSpots();
void ProfLoad_Print();
void ProfLoad_Deactivate();

//t6/code/src_noserver/qcommon/com_sessionmodes.cpp
bool Com_SessionMode_IsMode(eSessionModes mode);
void Com_SessionMode_WriteModes(msg_t *msg);
bool Com_SessionMode_ReadModes(msg_t *msg);
bool __cdecl BG_EmblemsInit();
bool Com_SessionMode_IsOnlineGame();
void Com_SessionMode_SetMode(eSessionModes mode, bool value);
bool Com_SessionMode_IsPrivateOnlineGame();
bool Com_SessionMode_IsPublicOnlineGame();
bool Com_SessionMode_IsZombiesGame();
bool Com_SessionMode_CanPauseZombiesGame();
void Com_SessionMode_ResetModes();
void Com_SessionMode_SetOnlineGame(bool onlineGame);
bool Com_SessionMode_IsPublicBotGame();

//t6/code/src_noserver/qcommon/console_mp.cpp
int Live_GetNecessaryBandwidth();
int Live_HowManyPlayersCanWeHost();

//t6/code/src_noserver/qcommon/content.cpp
ContentPackMetaData *Content_GetContentPackMetaDataList();
bool Content_IsContentPackAllowedToBeListed(int mask);
int Content_GetKnownContentPackCount();
int Content_GetIndexedContentPackID(int index);
int Content_GetIndexedContentPackMask(int index);
KnownContentPackData *Content_GetIndexedContentPackName(int index);
char Content_IsLoadFastfileLoaded(int index);
void Content_SetLoadFastfileLoaded(int index, bool value);
const char *Content_GetIndexedContentPackFilenameIdentifier(int index);
bool Content_IsDiscovered();
void Content_RegisterContentDvars();
bool Content_IsContentPackInvalid(int contentIndex);
int Content_GetAvailableContentPacks();
int Content_GetAvailableContentMapPackFlags();
SearchSessionMapPackCombinationData *Content_GetContentPacksFlagsString(int contentFlags);
bool Content_DoWeHaveContentPack(const int contentPack);
int Content_GetFreePackIndex();
void Content_InitializeContentPacks();
bool Content_PlayerHasDLCForMapPackIndex(dlcIndex_t mapPackTypeIndex);
const char *Content_GetPakNameForMap(const char *name);
void Content_ValidateTrialPackages();
int Content_GetMTXID(const char *name);
const char *Content_GetMTXContentOffer(const int mtxId);
const char *Content_GetMTXContentName(const int mtxId);
void Content_ClearMTX(ControllerIndex_t controllerIndex);
void Content_MTXFinalizeDiscovery();
bool Content_DoWeHaveMTX(ControllerIndex_t controllerIndex, const int mtxId);
char Content_DoesAnyoneHaveMTX(const int mtxId);
void Content_PurchaseMTX_f();
void Content_ForceMTX_f();
void Content_DumpMTX_f();
char Content_DetermineMTX(ControllerIndex_t controllerIndex, const char *name);
int Content_GetIndexedContentPackFromPakName(const char *pakName);
char Content_OwnsAnyByMask(const ControllerIndex_t controllerIndex, const int contentMask);
int Content_GetContentPackFromPakName(const char *pakName);
bool Content_DoWeHaveIndexedContentPack(int index);
bool Content_IsIndexedContentPackEnabled(int index);
unsigned int Content_GetEnabledContentPacks();
void Content_RegisterContentCmds();

//t6/code/src_noserver/qcommon/dobj_management.cpp
void TRACK_dobj_management();
DObj *Com_GetServerDObj(int handle);
unsigned int Com_GetFreeDObjIndex();
void Com_DObjDumpPrintEntry(int dobjIndex, bool *dobjChecked);
void Com_DObjDump();
void Com_ClientDObjClearAllSkel(LocalClientNum_t localClientNum);
DObj *Com_ServerDObjCreate(DObjModel_s *dobjModels, unsigned __int16 numModels, XAnimTree_s *tree, int handle);
void Com_SafeClientDObjFree(int handle, LocalClientNum_t localClientNum);
void Com_SafeServerDObjFree(int handle);
void Com_InitDObj();
void Com_ShutdownDObj();
DObj *Com_GetClientDObj(int handle, LocalClientNum_t localClientNum);
DObj *Com_ClientDObjCreate(DObjModel_s *dobjModels, unsigned __int16 numModels, XAnimTree_s *tree, int handle, LocalClientNum_t localClientNum);

//t6/code/src_noserver/qcommon/dvar_cmds.cpp
void TRACK_dvar_cmds();
void Cmd_GetCombinedString(char *combined, int first);
int Dvar_Command();
bool Dvar_ToggleSimple(dvar_t *dvar);
bool Dvar_ToggleInternal();
bool __cdecl Dvar_Toggle_f();
void Dvar_TogglePrint_f();
void Dvar_Set_f();
void Dvar_RegisterBool_f();
void Dvar_RegisterInt_f();
void Dvar_RegisterFloat_f();
void Dvar_RegisterColor_f();
void Dvar_SetA_f();
void Dvar_SetToTime_f();
void Dvar_Reset_f();
void Dvar_WriteSingleVariable(dvar_t *dvar, void *userData);
void Dvar_WriteVariables(int f);
void Dvar_WriteSingleDefault(dvar_t *dvar, void *userData);
void Dvar_WriteDefaults(int f);
void Dvar_ListSingle(dvar_t *dvar, void *userData);
void Dvar_List_f();
void Com_DvarDumpSingle(dvar_t *dvar, void *userData);
void Com_DvarDump(int channel, const char *match);
void Dvar_Dump_f();
void SV_SetConfigDvar(dvar_t *dvar, void *userData);
void SV_SetConfig(int start, int max, int bit);
void Dvar_InfoStringSingle(dvar_t *dvar, void *userData);
void Dvar_InfoStringSingle_Big(dvar_t *dvar, void *userData);
char *Dvar_InfoString(LocalClientNum_t localClientNum, int bit);
char *Dvar_InfoString_Big(int bit);
void Dvar_AddConfigFlag_f();
void Dvar_ListByCount_f();
void Dvar_AddCommands();

//t6/code/src_noserver/qcommon/files.cpp
void TRACK_files();
int FS_SV_FOpenFileWrite(const char *filename, const char *dir);
int FS_SV_FOpenFileRead(const char *filename, const char *dir, int *fp);
int FS_GetModList(char *listbuf, int bufsize);
void FS_Dir_f(int a1);
void FS_NewDir_f(int a1);
void FS_TouchFile_f();
int FS_iwIwd(const char *iwd, char *base);
void FS_RemoveCommands();
void FS_AddCommands();
void FS_SetRestrictions();
void FS_LoadedIwds(const char **checksums, const char **names);
char *FS_LoadedIwdPureChecksums();
void FS_ReferencedIwds(const char **checksums, const char **names);
char *FS_ReferencedIwdPureChecksums();
char FS_PureServerSetLoadedIwds(const char *iwdSums, const char *iwdNames);
int FS_ServerSetReferencedFiles(const char *fileSums, const char *fileNames, int maxFiles, int *fs_sums, const char **fs_names);
void FS_ServerSetReferencedIwds(const char **a1, int *a2, const char *iwdSums, const char *iwdNames);
void FS_ServerSetReferencedFFs(const char **a1, int *a2, const char *FFSums, const char *FFNames);
char *FS_GetMapBaseName(const char *mapname);

//t6/code/src_noserver/qcommon/gdt_remote.cpp
const char *GDTCmd_NextToken(const char *src, char *dst, unsigned int len);
char GDT_RemoteWeaponUpdate(char *a1, const char *in);
char GDT_RemoteAttachmentUpdate(char *a1, const char *in);
char GDT_RemoteAttachmentUniqueUpdate(char *a1, const char *in);
char GDT_RemoteWeaponCamoUpdate(char *a1, const char *in);
bool GDT_RemoteFlametableUpdate(char *a1, const char *in);
bool GDT_TracerUpdate(char *a1, const char *in);
char GDT_ZBarrierUpdate(char *a1, const char *in);
char GDT_RemotePhysConstraintsUpdate(char *a1, const char *in);
char GDT_RemoteVehicleUpdate(char *a1, const char *in);
char GDT_RemoteXModelUpdate(const char *in);
bool GDT_RemoteMaterialUpdate(const char *in);
char ProcessGDTCmds();

//t6/code/src_noserver/qcommon/graph.cpp
void GraphFloat_ParseBuffer(GraphFloat *graph, const char *buffer, const char *fileName);
void GraphFloat_Load(GraphFloat *graph, const char *fileName, float scale);
double GraphFloat_GetValue(const GraphFloat *graph, float fraction);
void GraphFloat_SaveToFile(const GraphFloat *graph);
void GraphFloat_DevGuiCB_Event(const DevGraph *graph, DevEventType event);
void GraphFloat_DevGuiCB_Text(const DevGraph *devGuiGraph, float inputX, float inputY, char *text);
void GraphFloat_CreateDevGui(GraphFloat *graph, const char *devguiPath);
GraphFloat *GraphFloat_Load(const char *fileName);

//t6/code/src_noserver/qcommon/huffman.cpp
void Huff_offsetReceive(nodetype *node, unsigned __int8 *ch, const unsigned __int8 *fin, int *_offset);
void huffman_send(nodetype *node, nodetype *child, unsigned __int8 *fout);
void Huff_offsetTransmit(huff_t *huff, int ch, unsigned __int8 *fout, int *offset);
void Huff_Init(huffman_t *huff);
int nodeCmp(const void *left, const void *right);
void Huff_BuildFromData(huff_t *huff, const int *msg_hData);

//t6/code/src_noserver/qcommon/keyvaluepairs.cpp
char KeyValuePairs_GetNextValue(const char *key, const char *namespaceKey, const char **outValue);
void KeyValuePairs_Add(KeyValuePairs *kvp, int zoneIndex);
void KeyValuePairs_Remove(KeyValuePairs *kvp);

//#include "qcommon/keyvaluepairs_load_db.h"

//#include "qcommon/memory_block_load_db.h"

//t6/code/src_noserver/qcommon/mem_track.cpp
void track_addbasicmeminfo(meminfo_t *sum, meminfo_t *in);
void track_static_alloc_internal_simple(void *ptr, int size, const char *name, int memTrack);
TempMemInfo *GetTempMemInfo(int permanent, const char *name, int type, int usageType, TempMemInfo *tempMemInfoArray, int *tempMemInfoCount, bool add_if_missing);
void track_flush_physical_alloc(const char *name, int type);
void track_z_alloc(int size, const char *name, int type, void *pos, int project, int overhead);
void track_z_free(int type, void *pos, int overhead);
void track_z_commit(int size, int type);
void track_temp_alloc(int size, int hunkSize, int permanent, const char *name);
void track_temp_free(int size, int permanent, const char *name);
void track_temp_clear(int permanent);
void track_temp_high_alloc(int size, int hunkSize, int permanent, const char *name);
void track_temp_high_clear(int permanent);
void track_userhunk_freerange(void *low, unsigned int size);
void track_userhunk_free(void *ptr);
void track_userhunk_alloc(int size, int pos, const char *name, int type);
void track_hunk_alloc(int size, int pos, const char *name, int type);
void track_hunk_allocLow(int size, int pos, const char *name, int type);
void track_set_hunk_size(int size);
void track_hunk_ClearToMarkHigh(int mark);
void track_hunk_ClearToMarkLow(int mark);
void track_hunk_ClearToStart();
int mem_track_compare(const void *elem1, const void *elem2);
void track_getbasicinfo(meminfo_t *info);
void track_printf(const char *fmt, ...);
void track_shutdown(int project);
void TRACK_memtrack();
void track_init();
void track_physical_alloc(int size, const char *name, int type, int location);
void track_PrintInfo();
void track_PrintAllInfo();

//#include "qcommon/mem_track.h"

//t6/code/src_noserver/qcommon/migration.cpp
void Migration_Init(unsigned __int8 *buffer, int len);
void Migration_Shutdown();
unsigned __int8 *Migration_GetBuffer();
int Migration_GetBufferSize();

//t6/code/src_noserver/qcommon/msg.cpp
vec3_t *__cdecl MSG_GetMapCenter();
int GetMinBitCountForNum(const unsigned int num);
void MSG_BeginReading(msg_t *msg);
void MSG_Discard(msg_t *msg);
void MSG_GetBytes(msg_t *msg, int where, unsigned __int8 *dest, int len);
int MSG_GetUsedBitCount(const msg_t *msg);
int MSG_GetNumBitsRead(const msg_t *msg);
void MSG_SetBookmark(const msg_t *msg, msg_bookmark_t *bookmark);
void MSG_GotoBookmark(msg_t *msg, const msg_bookmark_t *bookmark);
int MSG_ReadBit(msg_t *msg);
void showHuffmanData();
void MSG_RecordHuffmanDistribution();
int MSG_ReadBitsCompress(const unsigned __int8 *from, int fromSizeBytes, unsigned __int8 *to, int toSizeBytes);
void MSG_Embed(msg_t *dest, msg_t *src);
void MSG_UnEmbed(msg_t *msg);
void MSG_WriteByte(msg_t *msg, int c);
void MSG_WriteData(msg_t *buf, const void *data, int length);
void MSG_WriteFloat(msg_t *msg, float f);
void MSG_WriteAngle(msg_t *sb, int bits, float f);
void MSG_WriteAngle16(msg_t *sb, float f);
void MSG_WriteRangedFloatBits(msg_t *sb, float f, float begin, float end, int bits);
void MSG_WriteRiceGolomb(msg_t *sb, unsigned int c, int mbits);
void MSG_WriteExpGolomb0(msg_t *sb, unsigned int q);
void MSG_WriteSignedExpGolomb0(msg_t *sb, int c);
void MSG_WriteSignedExpGolomb(msg_t *sb, int c, int kbits);
void MSG_WriteSignedNonZeroExpGolomb0(msg_t *sb, int c);
void MSG_WriteSignedNonZeroExpGolomb(msg_t *sb, int c, int kbits);
void MSG_WriteBits64(msg_t *msg, __int64 value, int bits);
void MSG_WriteInt64(msg_t *msg, unsigned __int64 c);
void MSG_WriteString(msg_t *sb, const char *s);
void MSG_WriteBigString(msg_t *sb, const char *s);
int MSG_ReadByte(msg_t *msg);
int MSG_ReadShort(msg_t *msg);
int MSG_ReadLong(msg_t *msg);
unsigned __int64 MSG_ReadInt64(msg_t *msg);
double MSG_ReadFloat(msg_t *msg);
char *MSG_ReadString(msg_t *msg, char *string, unsigned int maxChars);
char *MSG_ReadBigString(msg_t *msg);
char *MSG_ReadStringLine(msg_t *msg, char *string, unsigned int maxChars);
double MSG_ReadAngle(msg_t *msg, int bits);
double MSG_ReadAngle16(msg_t *msg);
double MSG_ReadRangedFloatBits(msg_t *sb, float begin, float end, int bits);
int MSG_ReadRiceGolomb(msg_t *msg, int mbits);
int MSG_ReadExpGolomb0(msg_t *msg);
int MSG_ReadSignedExpGolomb0(msg_t *msg);
int MSG_ReadSignedNonZeroExpGolomb(msg_t *msg, int kbits);
int MSG_ReadSignedNonZeroExpGolomb0(msg_t *msg);
int MSG_ReadBits64(msg_t *msg, int bits);
void MSG_ReadData(msg_t *msg, void *data, int len);
void MSG_WriteDeltaKey(msg_t *msg, int key, int oldV, int newV, int bits);
int MSG_ReadDeltaKey(msg_t *msg, int key, int oldV, int bits);
void MSG_WriteKey(msg_t *msg, int key, int newV, int bits);
unsigned int MSG_ReadKey(msg_t *msg, int key, int bits);
void MSG_WriteDeltaKeyByte(msg_t *msg, int key, int oldV, int newV);
int MSG_ReadDeltaKeyByte(msg_t *msg, int key, int oldV);
void MSG_WriteDeltaKeyShort(msg_t *msg, int key, int oldV, int newV);
int MSG_ReadDeltaKeyShort(msg_t *msg, int key, int oldV);
int MSG_ReadDeltaTime(msg_t *msg, int timeBase);
int MSG_ReadDeltaEventField(msg_t *msg);
int MSG_ReadDeltaEventParamField(msg_t *msg);
int MSG_ReadEFlags(msg_t *msg, const int oldFlags);
double MSG_ReadOriginFloat(int bits, msg_t *msg, float oldValue);
double MSG_ReadOriginZFloat(msg_t *msg, float oldValue);
double MSG_ReadRangedFloat(msg_t *msg, const float oldValue, const float begin, const float end, const int precision, const bool oftenZeroOrOne);
int MSG_ReadEntityIndex(msg_t *msg, int indexBits);
void MSG_InitHuffman();
int MSG_ReadValueNoXor(msg_t *msg, const int bits);
int MSG_ReadValue(msg_t *msg, const int *fromF, int *toF, const int bits, const int size);
double MSG_ReadDeltaAngle(msg_t *msg, const float oldFloat);
int MSG_ReadLastChangedField(msg_t *msg, int totalFields);
int MSG_ReadNumFieldsSkipped(msg_t *msg, const int skippedFieldBits, const int maxVal);
void MSG_CopyFieldOver(const NetField *stateFields, const void *from, void *to, const int fieldNum);
void MSG_ReadDeltaFields(msg_t *msg, const int time, const void *from, void *to, int numFields, const NetField *stateFields, const int skippedFieldBits);
int MSG_ReadDeltaStruct(msg_t *msg, const int time, const void *from, void *to, unsigned int number, int numFields, int indexBits, const NetField *stateFields, const int skippedFieldBits);
void MSG_ReadDeltaMatchState(int a1, msg_t *msg, const int time, const MatchState *remoteFrom, const MatchState *remoteTo);
int MSG_ReadDeltaClient(msg_t *msg, const int time, const clientState_s *remoteFrom, clientState_s *remoteTo, int number);
int MSG_ReadDeltaActor(msg_t *msg, const int time, const actorState_s *remoteFrom, actorState_s *remoteTo, int number);
int MSG_ReadDeltaEntity(msg_t *msg, const int time, const entityState_s *from, entityState_s *to, int number, const ClientNum_t clientNum);
void MSG_Init(msg_t *buf, unsigned __int8 *data, int length);
void MSG_InitReadOnly(msg_t *buf, unsigned __int8 *data, int length);
void MSG_InitReadOnlySplit(msg_t *buf, unsigned __int8 *data, int length, unsigned __int8 *data2, int length2);
void MSG_SetDefaultUserCmd(playerState_s *ps, usercmd_s *cmd);

//#include "qcommon/msg.h"

//t6/code/src_noserver/qcommon/msg_crc.cpp
int MSG_CRCNetFields();
void MsgCRC_Init();
unsigned int MsgCRC_NetFieldChecksum();

//t6/code/src_noserver/qcommon/msg_mp.cpp
int MSG_ReadBits(msg_t *msg, int bits);
void MSG_WriteBits(msg_t *msg, int value, int bits);
void MSG_WriteBit0(msg_t *msg);
void MSG_WriteBit1(msg_t *msg);
int MSG_WriteBitsCompress(bool trainHuffman, const unsigned __int8 *from, int fromSizeBytes, unsigned __int8 *to, int toSizeBytes);
void MSG_WriteShort(msg_t *msg, int c);
void MSG_WriteLong(msg_t *msg, int c);
void MSG_ClearLastReferencedEntity(msg_t *msg);
BOOL HasMeleeChargeChanged(const usercmd_s *from, const usercmd_s *to);
int MSG_ReadDeltaGroundEntity(msg_t *msg);
double MSG_ReadDemoRoundedFloat(msg_t *msg, int bits, float oldValue, int diffBits, int fullBits);
void MSG_ReadDeltaField(msg_t *msg, const int time, const void *from, void *to, const NetField *field, int print, __int16 noXor);
int MSG_ReadDeltaEntityStruct(msg_t *msg, const int time, const void *from, void *to, unsigned int number, const int totalFields);
int MSG_ReadDeltaArchivedEntity(msg_t *msg, const int time, const archivedEntity_s *from, archivedEntity_s *to, int number);
void MSG_ReadDeltaHudElems(msg_t *msg, const int time, const hudelem_s *from, hudelem_s *to, int count);
void MSG_ReadDeltaPlayerstate(const LocalClientNum_t localClientNum, msg_t *msg, const int time, const playerState_s *remoteFrom, playerState_s *remoteTo, bool predictedFieldsIgnoreXor);
void MSG_DumpNetFieldChanges_f();
void MSG_ReadDeltaUsercmdKey(msg_t *msg, int key, const usercmd_s *from, usercmd_s *to);
void MSG_WriteDeltaUsercmdKey(msg_t *msg, int key, const usercmd_s *from, const usercmd_s *to, int forceSendAngles);

//#include "qcommon/net.h"

//t6/code/src_noserver/qcommon/net_chan.cpp
char *NET_AdrToString(netadr_t a);
char *NET_AdrToStringDW(netadr_t a);
void NetProf_PrepProfiling(netProfileInfo_t *prof);
void NetProf_AddPacket(netProfileStream_t *pProfStream, int iSize, int bFragment);
void NetProf_NewRecievePacket(netchan_t *pChan, int iSize, int bFragment);
void NetProf_UpdateStatistics(netProfileStream_t *pStream);
void Net_DumpProfile_f();
void Net_GetQPort_f();
void Net_SetQPort_f();
void Net_DisplayProfile(LocalClientNum_t localClientNum);
void TRACK_net_chan();
void Netchan_Init(int port);
void Netchan_Setup(netsrc_t sock, netchan_t *chan, netadr_t adr, int qport, char *outgoingBuffer, int outgoingBufferSize, char *incomingBuffer, int incomingBufferSize);
unsigned __int8 *Netchan_BorrowBuffer(netchan_t *chan, int size);
void Netchan_ReturnBuffer(netchan_t *chan, unsigned __int8 *ptr);
int NET_CompareBaseAdrSigned(netadr_t *a, netadr_t *b, bool skipLocalClient);
BOOL NET_CompareBaseAdr(netadr_t a, netadr_t b);
BOOL NET_CompareIPAdr(netadr_t a, netadr_t b);
int NET_CompareAdrSigned(netadr_t *a, netadr_t *b);
BOOL NET_CompareAdr(netadr_t a, netadr_t b);
BOOL NET_CompareXNAddr(XNADDR *a, XNADDR *b);
BOOL NET_IsLocalAddress(const netadr_t adr);
BOOL NET_IsLocalIP(const netadr_t adr);
BOOL NET_IsZeroIP(const netadr_t adr);
void NET_SetNetAdrLoopbackIP(netadr_t *src);
int NET_GetLoopPacket(netsrc_t sock, netadr_t *net_from, msg_t *net_message);
void NET_SendLoopPacket(netsrc_t sock, int length, const void *data, netadr_t to);
void NET_DeferPacketToClient(netadr_t *net_from, msg_t *net_message);
bool NET_GetDeferredClientPacket(netadr_t *net_from, msg_t *net_message);
void NET_DeferNonVoicePacket(netadr_t *net_from, msg_t *net_message);
bool NET_GetNonVoiceDeferred(netadr_t *net_from, msg_t *net_message);
bool NET_SendPacket(netsrc_t sock, int length, const void *data, netadr_t to);
bool NET_OutOfBandPrint(netsrc_t sock, netadr_t adr, const char *data);
BOOL NET_OutOfBandData(netsrc_t sock, netadr_t adr, const unsigned __int8 *format, int len);
BOOL NET_OutOfBandVoiceData(netsrc_t sock, netadr_t adr, unsigned __int8 *format, int len);
int NET_StringToAdr(const char *s, netadr_t *a);
void Int64ToString(__int64 int64, char *str);
void XUIDToString(const unsigned __int64 *xuid, char *str);
void XUIDToStringDecimal(const unsigned __int64 *xuid, char *str);
void StringToXUID(const char *str, unsigned __int64 *xuid);
void StringToXUIDDecimal(const char *str, unsigned __int64 *xuid);
void ByteArrayToString(const void *from, unsigned int fromSize, char *to, unsigned int toSize);
void StringToByteArray(const char *from, unsigned int fromSize, void *to, unsigned int toSize);
void XNAddrToString(const XNADDR *xnaddr, char *str);
void StringToXNAddr(const char *str, XNADDR *xnaddr);
unsigned __int16 Sys_Checksum(const unsigned __int8 *src, int len);
unsigned __int16 Sys_ChecksumCopy(unsigned __int8 *dest, const unsigned __int8 *src, int len);
int Sys_VerifyPacketChecksum(int a1, const unsigned __int8 *payload, int paylen);
unsigned int Sys_CheckSumPacketCopy(const unsigned __int8 *a1, unsigned __int8 *dest, const unsigned __int8 *payload, int paylen);
char *XNKEYToString(const bdSecurityKey *xnkey);
char *XNAddrToString(const XNADDR *xnaddr);
int Netchan_TransmitFragment(netchan_t *chan, int fragmentLength, int fragmentIndex, int maxFragmentIndex);
bool Netchan_TransmitNextFragment(netchan_t *chan);
bool Netchan_Transmit(netchan_t *chan, int length, const unsigned __int8 *data, bool reliable_fragments);
int Netchan_Process(netchan_t *chan, msg_t *msg);
int NET_GetClientPacket(netadr_t *net_from, msg_t *net_message);
int NET_GetServerPacket(netadr_t *net_from, msg_t *net_message);
char *XSessionToString(const XSESSION_INFO *info);

//t6/code/src_noserver/qcommon/net_queue.cpp
PacketQueueEntry *PacketQueueBlock_Enqueue(PacketQueueBlock *block, unsigned int flags, int dequeueTime, netsrc_t sock, const netadr_t *addr, int length, const void *data);
bool PacketQueueBlock_Dequeue(PacketQueueBlock *block);
PacketQueueEntry *PacketQueueBlock_Peek(PacketQueueBlock *block);
bool PacketQueue_AddTailBlock(PacketQueue *queue);
void PacketQueue_RemoveHeadBlock(PacketQueue *queue);
PacketQueueEntry *PacketQueue_Peek(PacketQueue *queue);
PacketQueueEntry *PacketQueue_EnqueueInternal(PacketQueue *queue, unsigned int flags, int dequeueTime, netsrc_t sock, const netadr_t *addr, int length, const void *data);
bool PacketQueue_DequeueInternal(PacketQueue *queue);
PacketQueueEntry *PacketQueue_Enqueue(PacketQueue *queue, unsigned int flags, netsrc_t sock, const netadr_t *addr, int length, const void *data);
bool PacketQueue_Dequeue(PacketQueue *queue, unsigned int *flags, netsrc_t *sock, netadr_t *addr, int maxlength, int *length, void *data);
void NET_InitQueues();
void NET_InitQueue(PacketQueue *queue, const char *name, bool emulation);
bool NET_DequeuePacket(char *a1, PacketQueue *queue, unsigned int *flags, netsrc_t *sock, netadr_t *addr, int maxlength, int *length);
bool __cdecl NET_EnqueuePacket(PacketQueue *queue, unsigned int flags, netsrc_t sock, const netadr_t *addr, int length);
void NET_QueueCmd();

//#include "qcommon/qdb_load_db.h"

//t6/code/src_noserver/qcommon/radiant_remote.cpp
char *GetPairValue(const SpawnVar *spawnVar, const char *key);
void AddSavedCommand(const RadiantCommand *command);
void G_RegisterGUID(int guid, GUIDType type, void *data);
void G_FindGUID(int guid, GUIDType *type, void **data);
void RadiantRemoteInit();
gentity_t *G_FindEntity(int guid);
bool IsEntityType(const SpawnVar *spawnVar);
void G_ClearSelectedEntity();
bool G_IsSpawnPoint(const char *classname);
void G_ProcessEntityCommand(const RadiantCommand *command, SpawnVar *spawnVar);
void G_ProcessCameraCommand(SpawnVar *spawnVar);
int G_FindMiscModel(const vec3_t *origin);
void G_ProcessMiscModelCommand(const RadiantCommand *command, SpawnVar *spawnVar);
void G_ClearSelectedMiscModel();
int G_FindCorona(const vec3_t *origin);
void G_ProcessCoronaCommand(const RadiantCommand *command, SpawnVar *spawnVar);
void G_ClearSelectedCorona();
void G_NotifyScriptsOfSelectedScriptStruct(unsigned int structId);
unsigned int G_FindStruct(SpawnVar *spawnVar);
void G_ProcessScriptStructCommand(const RadiantCommand *command, SpawnVar *spawnVar);
void G_ClearSelectedScriptStruct();
void CG_NotifyScriptsOfSelectedScriptStruct(unsigned int structId);
unsigned int CG_FindStruct(SpawnVar *spawnVar);
void CG_ProcessScriptStructCommand(const RadiantCommand *command, SpawnVar *spawnVar);
void CG_ClearSelectedScriptStruct();
void G_RadiantDebugDraw();
void G_ClearSelection(void (*ignoreFunc)());
void CG_ClearSelection(void (*ignoreFunc)());
char CG_ProcessRadiantCmds();
int GetCommandProcessorType(const SpawnVar *spawnVar);
void G_ProcessRadiantCmd(const RadiantCommand *command);
char G_ProcessRadiantCmds();
void RunSavedRadiantCmds();

//#include "qcommon/rawfile_load_db.h"

//#include "qcommon/scriptparsetree_load_db.h"

//#include "qcommon/slug_load_db.h"

//t6/code/src_noserver/qcommon/statmonitor.cpp
void StatMon_GetStatsArray(const statmonitor_s **array, int *count);
void StatMon_Reset();

//t6/code/src_noserver/qcommon/stream.cpp
int Stream_GetNextFileID();
void Stream_DoneWithFileID(int id);
stream_status Stream_GetStatus(int id);
void Stream_AddToQueue(streamInfo *newStreamInfo);
void Stream_RemoveFromQueue(streamInfo *stream, stream_status reason, callbackInfo *callbacks, int *numCallbacks);
char Stream_IsCancelledReadInProgress();
void Stream_CloseFile(int handle);
bool Stream_AddRequest(int handle, unsigned int offs, unsigned int bufferSize, void *buf, int msUntilRequired, stream_priority priority, void (*callback)(int, stream_status, unsigned int, void *), void *user, int *outId);
char Stream_AddCallbackOnlyRequest(int estMsNeeded, int msUntilRequired, stream_priority priority, void (*callback)(int, void *, int), void *user, int *outId);
char Stream_FreeRequest(int id, bool freeEvenIfLoadInProgress);
bool Stream_LoadFileSynchronously(streamInfo *stream);
void Stream_ProcessOpenRequests(callbackInfo *callbacks, int *numCallbacks);
streamInfo *Stream_GetNextStreamToLoad();
void Stream_Thread(char *id, unsigned int threadContext);
void Stream_Shutdown();
void Stream_InternalSyncCallback(int id, stream_status result, unsigned int numBytesRead, void *user);
unsigned int Stream_Easy_Read(int handle, void *buf, unsigned int bufferSize, unsigned int *bytesRead);
unsigned int Stream_Easy_Tell(int handle);
unsigned int Stream_Easy_FileSize(int handle);
void Stream_ClumpCloseFile(int fhandle);
char Stream_ClumpSeekToFile(int fhandle, const char *filename, unsigned int *fileSize);
void *Stream_ClumpReadFile(int fhandle, const char *filename, HunkUser *hunk, unsigned int *bytesRead);
unsigned int SplitPath(const char *path, PathItem *items);
int PathItem_Path_r(PathItem *item, char **output, int outputLen);
int Stream_FindOverridePath(const char *original, char *result, int resultLength);
int Stream_OpenFile(const char *name, int flags);
bool Stream_Init();
int Stream_ClumpOpenFile(const char *clump);

//t6/code/src_noserver/qcommon/stream_platform.cpp
void Stream_CheckLockedFile(const char *name);
void Stream_SeekInternal(void *fh, unsigned __int64 offset);
char Stream_ReadInternal(void *fh, unsigned __int64 readOffset, unsigned __int8 *dest, unsigned __int64 nBytes, unsigned __int64 *bytesRead);
void Stream_CloseInternal(void *fh);
int CG_Destructible_GetModelIndexFromLabel();
int Stream_OpenInternal(const char *name, int flags, void **fh, __int64 *fileSize);

//t6/code/src_noserver/qcommon/stringed_remote.cpp
char *GetString(const char *PackageAndStringReference);
char ProcessStringEdCmds();

//t6/code/src_noserver/qcommon/sv_msg_write.cpp
void TRACK_msg();
void MSG_LoopThroughFields(const NetFieldList *fieldToCheck);
void MSG_CheckForDuplicateOffsets();
const NetFieldList *MSG_GetStateFieldListForEntityType(const int eType, bool isDemoSnapshot);
const NetFieldList *MSG_GetNetFieldList(netFieldTypes_t fieldType, bool isDemoSnapshot);
void MSG_WriteReliableCommandToBuffer(const char *pszCommand, char **pszBuffer, char *allocBufferBase, int allocBufferLength, int *allocBufferPos);
void MSG_WriteOriginFloat(const SnapshotInfo_s *snapInfo, const ClientNum_t clientNum, msg_t *msg, int bits, float value, float oldValue);
void MSG_WriteOriginZFloat(const SnapshotInfo_s *snapInfo, const ClientNum_t clientNum, msg_t *msg, float value, float oldValue);
void MSG_WriteDemoRoundedFloat(msg_t *msg, int bits, float value, float oldValue, int diffBits, int fullBits);
bool MSG_CompareRangedFloat(const float oldValue, const float value, const float begin, const float end, const int precision);
bool MSG_ValuesAreEqual(const ClientNum_t clientNum, int bits, int size, const int *fromF, const int *toF);
bool MSG_ShouldSendPsViewAngles(const SnapshotInfo_s *snapInfo, const playerState_s *ps, const playerState_s *oldPs, const NetField *field);
bool MSG_ShouldSendPSField(const SnapshotInfo_s *snapInfo, bool sendOriginAndVel, bool sendVehicleState, const playerState_s *ps, const playerState_s *oldPs, const NetField *field);
void MSG_WriteEntityIndex(const SnapshotInfo_s *snapInfo, msg_t *msg, const int index, const int indexBits);
void MSG_WriteLastChangedField(msg_t *msg, const int lastChangedFieldNum, int numFields);
void MSG_WriteDeltaTime(const ClientNum_t clientNum, msg_t *msg, int timeBase, int time);
void MSG_WriteDeltaFrameTime(const ClientNum_t clientNum, msg_t *msg, int timeBase, int time);
void MSG_WriteEFlags(const ClientNum_t clientNum, msg_t *msg, const int oldFlags, const int newFlags);
void MSG_WriteEventNum(const ClientNum_t clientNum, msg_t *msg, int eventNum);
void MSG_WriteEventParam(const ClientNum_t clientNum, msg_t *msg, int eventParam);
int MSG_HighBitNumber(unsigned int v);
int MSG_WriteRangedFloat(const ClientNum_t clientNum, msg_t *msg, const float oldValue, const float value, const float begin, const float end, const int precision, const bool oftenZeroOrOne);
PacketEntityType MSG_GetPacketEntityTypeForEType(int eType);
void MSG_EncodeSkippedFields(const SnapshotInfo_s *snapInfo, msg_t *msg, int numFieldsSkipped, const int skippedFieldBits);
void MSG_WriteValueNoXor(const SnapshotInfo_s *snapInfo, msg_t *msg, int value, const int bits);
void MSG_WriteValue(const SnapshotInfo_s *snapInfo, msg_t *msg, const int *fromF, const int *toF, const int bits, const int size);
void MSG_WriteDeltaAngle(const SnapshotInfo_s *snapInfo, msg_t *msg, const float oldFloat, const float fullFloat);
bool MSG_WriteDeltaField_Internal(msg_t *a1, const SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const unsigned __int8 *from, const unsigned __int8 *to, const NetField *field, const int fieldNum, const int *fromF, const int *toF);
bool MSG_WriteDeltaField(char *a1, const SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const unsigned __int8 *from, const unsigned __int8 *to, const NetField *field, const int fieldNum, const bool forceSend, const bool xorValue, const int lastChangedField, const int skippedFieldBits, const bool sendSkippedFields);
void MSG_WriteDeltaFields(const SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const unsigned __int8 *from, const unsigned __int8 *to, const int force, int lastChanged, int numFields, const NetField *stateFields, const int skippedFieldBits, bool writeEntUnlinkBit);
void MSG_WriteEntityRemoval(SnapshotInfo_s *snapInfo, msg_t *msg, unsigned __int8 *from, int indexBits, bool changeBit);
int MSG_WriteEntityDeltaForEType(SnapshotInfo_s *snapInfo, msg_t *msg, const int time, int eType, const entityState_s *from, const entityState_s *to, DeltaFlags flags);
bool MSG_ShouldEntityFieldBeForcedSent(const SnapshotInfo_s *snapInfo, const NetField *field, const EntityFieldInfoFlags fromFlags, const EntityFieldInfoFlags toFlags);
void MSG_GetEntityFieldInfoFlags(const entityState_s *es, EntityFieldInfoFlags *flags);
bool MSG_ShouldSendEntityField(const NetField *a1, const SnapshotInfo_s *snapInfo, const entityState_s *from, const entityState_s *to, const NetField *field, const EntityFieldInfoFlags fromFlags, const EntityFieldInfoFlags toFlags);
void MSG_WriteDeltaClient(SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const clientState_s *from, const clientState_s *to, int force);
void MSG_WriteDeltaActor(SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const actorState_s *from, const actorState_s *to, int force);
BOOL MSG_WithinAllowedPredictionError(float dist, const playerState_s *to);
int MSG_GetLastChangedField(const SnapshotInfo_s *snapInfo, const unsigned __int8 *from, const unsigned __int8 *to, int numFields, const NetField *stateFields);
unsigned int MSG_GetBitFieldIndex(unsigned int *fieldsChanged, const BitField *bitFields, bool *bMatch, int entNum);
void __cdecl MSG_WriteDeltaPlayerstate(SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const playerState_s *from, const playerState_s *to);
void MSG_WriteDeltaMatchState(int a1, SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const MatchState *from, const MatchState *to);
int MSG_WriteDeltaHudElems_LastChangedField(SnapshotInfo_s *snapInfo, int i, const hudelem_s *from, const hudelem_s *to);
void MSG_WriteDeltaHudElems_ValidateHudElem(const hudelem_s *from, const hudelem_s *to);

//t6/code/src_noserver/qcommon/sv_msg_write_mp.cpp
bool MSG_EntityIsLinked(const entityState_s *ent);
void MSG_WriteGroundEntityNum(const ClientNum_t clientNum, msg_t *msg, const int groundEntityNum);
void MSG_WriteDeltaField_Default(const SnapshotInfo_s *snapInfo, msg_t *msg, const NetField *field, const int *fromF, const int *toF);
int MSG_WriteDeltaStruct(SnapshotInfo_s *snapInfo, msg_t *msg, const int time, unsigned __int8 *from, unsigned __int8 *to, int force, int numFields, int indexBits, const NetField *stateFields, int bChangeBit, int skippedFieldBits);
int MSG_WriteAppendedDeltaStruct(SnapshotInfo_s *snapInfo, msg_t *msg, const int time, unsigned __int8 *from, unsigned __int8 *to, int force, int numFields, int indexBits, const NetField *stateFields, int bChangeBit, int skippedFieldBits);
void MSG_WriteEntityDeltaFields(const SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const entityState_s *fromES, const entityState_s *toES, const int force, int lastChanged, int numFields, const NetField *stateFields, const int skippedFieldBits, unsigned int *fieldsChanged);
int MSG_WriteEntityDelta(const SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const entityState_s *fromES, const entityState_s *toES, DeltaFlags flags, int numFields, int indexBits, const NetField *stateFields, const char *tableName, const BitField *bitFields);
bool MSG_WriteDeltaArchivedEntity(SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const archivedEntity_s *from, const archivedEntity_s *to, DeltaFlags flags);
void UpdateEntTimesForTimeDelta(entityState_s *ent, const int timeDelta);
void PrintChangedEntityFields(SnapshotInfo_s *snapInfo, const entityState_s *from, const entityState_s *to);
void SV_ValidateEntityState(const entityState_s *entState);
int MSG_WriteEntity(SnapshotInfo_s *snapInfo, msg_t *msg, const int timeDeltaFrom, const int timeDeltaTo, const int time, const entityState_s *from, const entityState_s *to, DeltaFlags flags);
void MSG_WriteDeltaHudElems(SnapshotInfo_s *snapInfo, msg_t *msg, const int time, const hudelem_s *from, const hudelem_s *to, int count);

//t6/code/src_noserver/qcommon/threads.cpp
void NET_Sleep(unsigned int timeInMs);
void Sys_SetEvent(void **event);
void Sys_ResetEvent(void **event);
void Sys_CreateEvent(int manualReset, int initialState, void **evt);
BOOL Sys_WaitForSingleObjectTimeout(void **event, unsigned int msec);
void Sys_WaitForSingleObject(void **event);
unsigned int Sys_GetCpuCount();
void Win_InitThreads();
void Sys_InitMainThread();
void Sys_InitThread(int threadContext);
unsigned int Sys_ThreadMain(void *parameter);
void Sys_CreateThread(void (*function)(unsigned int), unsigned int threadContext);
void Sys_TitleServerThreadData();
void Sys_InitDemoStreamingEvent();
void Sys_WaitForDemoStreamingEvent();
BOOL Sys_WaitForDemoStreamingEventTimeout(unsigned int msec);
void Sys_SetDemoStreamingEvent();
void Sys_InitWebMStreamingEvent();
void Sys_InitServerEvents();
void Sys_NotifyRenderer();
BOOL Sys_WaitServer(int timeout);
int Sys_IsDBPrintingSuppressed();
void Sys_StartGumpLoading();
int Sys_IsLoadingGump();
BOOL Sys_WaitForGumpLoad(int timeout);
BOOL Sys_WaitForGumpFlush(int timeout);
void Sys_WakeServer();
void Sys_ServerCompleted();
BOOL Sys_WaitStartServer(int timeout);
BOOL Sys_IsServerThread();
BOOL Sys_IsDatabaseThread();
void Sys_DatabaseCompleted();
void Sys_WaitStartDatabase();
BOOL Sys_IsDatabaseReady();
void Sys_WakeDatabase();
void Sys_NotifyDatabase();
void Sys_DatabaseCompleted2();
BOOL Sys_IsDatabaseReady2();
void Sys_WakeDatabase2();
BOOL Sys_IsRenderThread();
BOOL Sys_IsMainThread();
int Sys_GetThreadContext();
void Sys_SetValue(int valueIndex, void *data);
void *Sys_GetValue(int valueIndex);
void Sys_SetWin32QuitEvent();
BOOL Sys_QueryWin32QuitEvent();
void Sys_SetRGRegisteredEvent();
BOOL Sys_QueryRGRegisteredEvent();
void Sys_SetRenderEvent();
void Sys_SetD3DShutdownEvent();
BOOL Sys_QueryD3DShutdownEvent();
char Sys_SpawnStreamThread();
void Sys_StreamSleep();
void Sys_ResetSndInitializedEvent();
BOOL Sys_QueryStreamPaused();
void Sys_WakeStream();
BOOL Sys_IsStreamThread();
void Sys_SetServerAllowNetworkEvent();
void Sys_ResetServerAllowNetworkEvent();
void Sys_SetServerNetworkCompletedEvent();
void Sys_ResetServerNetworkCompletedEvent();
void Sys_WaitServerNetworkCompleted();
unsigned int Sys_GetDefaultWorkerThreadsCount();
char Sys_SpawnServerThread();
char Sys_SpawnDatabaseThread();
void Sys_InitWorkerThreadContext();
void Sys_RenderCompleted();
void Sys_FrontEndSleep();
void Sys_WakeRenderer(void *data);
void Sys_SleepServer();
void Sys_SyncDatabase();
const char *Sys_GetCurrentThreadName();
void Sys_WaitAllowServerNetworkLoop();
void Sys_GumpPrint(const char *fmt, ...);
void Sys_GumpLoaded();
void Sys_GumpFlushed();

//#include "qcommon/threads_interlock.h"

//t6/code/src_noserver/qcommon/tl_support.cpp
void TL_Warning(const char *Text);
bool TL_ReadFile();
void TL_ReleaseFile();
void TL_DebugPrint(const char *Text);
void *TL_MemAlloc(unsigned int Size, unsigned int Align);
void TL_MemFree(void *Ptr);
void TL_CriticalError(const char *msg);
void Sys_SetupTLCallbacks(int hunkMemSize);

//#include "qcommon/xglobals_load_db.h"

//#include "qcommon/zbarrier_load_db.h"

//t6/code/src_noserver/qcommon/zbarrier_load_obj.cpp
void ZBarrierDef_Strcpy(unsigned __int8 *pMember, const char *pKeyValue);
bool G_ZBarrierUpdateField(const char *zbarrierName, const char *keyValue);

