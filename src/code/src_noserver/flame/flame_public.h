#pragma once

#include "types.h"

//t6/code/src_noserver/flame/flame_class_chunk.cpp
void Flame_Class_Chunk_Allocate(int max_flame_chunks);
void Flame_Class_Chunk_Release();
void Flame_Class_Chunk_Init();
flameChunk_s *Flame_Class_Chunk_Alloc(bool is_server);
void Flame_Class_Chunk_Free(bool is_server, flameChunk_s *chunk);
void Flame_Phys_Spawn_Items(bool is_server, int curTime, flameChunk_s *trav);
void Flame_Class_Chunk_Age(bool is_server, int time, LocalClientNum_t localClientNum);
flameChunk_s *Flame_Class_Chunk_Spawn(bool is_server, flameChunkSpawnVars_t *spawnVars, flameChunk_s **chunkList, vec3_t *velocityAdd, flameTable *fTable);
void Flame_Class_Chunk_Render_All(LocalClientNum_t localClientNum);

//t6/code/src_noserver/flame/flame_class_drips.cpp
void Flame_Class_Drips_Allocate(int max_flame_drips);
void Flame_Class_Drips_Release();
void Flame_Class_Drips_Init();
flameDrips_t *Flame_Class_Drips_Alloc(bool is_server);
void Flame_Class_Drips_Free_If_Stream(bool is_server, flameStream_s *stream);
void Flame_Class_Drips_Age(bool is_server, int time, LocalClientNum_t localClientNum);
void Flame_Class_Drips_Render_All(LocalClientNum_t localClientNum);
void Flame_Class_Drips_Render_Local_List(LocalClientNum_t localClientNum, flameDrips_t *start);
flameDrips_t *Flame_Class_Drips_Spawn(bool is_server, flameChunk_s *fromChunk, int curTime, float minLifeFrac);

//t6/code/src_noserver/flame/flame_class_fire.cpp
void Flame_Class_Fire_Allocate(int max_flame_fire);
void Flame_Class_Fire_Release();
void Flame_Class_Fire_Init();
flameFire_t *Flame_Class_Fire_Alloc();
void Flame_Class_Fire_Age(bool is_server, int time, LocalClientNum_t localClientNum);
void Flame_Class_Fire_Render_All(LocalClientNum_t localClientNum);
void Flame_Class_Fire_Render_Local_List(LocalClientNum_t localClientNum, flameFire_t *start);
flameFire_t *Flame_Class_Fire_Spawn(bool is_server, flameChunk_s *fromChunk, int curTime, float minLifeFrac);

//t6/code/src_noserver/flame/flame_class_smoke.cpp
void Flame_Class_Smoke_Allocate(int max_flame_smoke);
void Flame_Class_Smoke_Release();
void Flame_Class_Smoke_Init();
void Flame_Class_Smoke_Age(bool is_server, int time, LocalClientNum_t localClientNum);
flameSmoke_t *Flame_Class_Smoke_Spawn(flameChunk_s *fromChunk, int curTime);
void Flame_Class_Smoke_Render_All(LocalClientNum_t localClientNum);

//t6/code/src_noserver/flame/flame_class_stream.cpp
void Flame_Class_Stream_Allocate(int max_flame_streams);
void Flame_Class_Stream_Release();
void Flame_Class_Stream_Init();
flameStream_s *Flame_Class_Stream_Alloc(bool is_server);
void Flame_Class_Stream_Age(bool is_server);
void Flame_Class_Stream_Fire_Chunks(flameSource_t *source, flameWeaponConfig_t *weaponConfig, int inTime, flameRender_s *flameRend, LocalClientNum_t localClientNum);
void Flame_Class_Stream_Render_Item(LocalClientNum_t localClientNum, const flameStream_s *stream, Material *material, Material *material2, vec3_t *verts, bool isFire);
void Flame_Class_Stream_Render_All(LocalClientNum_t localClientNum);
void CG_Flame_Render_Lights_Only(LocalClientNum_t localClientNum);

//t6/code/src_noserver/flame/flame_cull.cpp
void Flame_Cull_Stream_Chunk(bool is_server, flameChunk_s *cull, flameChunk_s *keep);
void Flame_Cull_Stream_Chunks(bool is_server, flameStream_s *stream);

//t6/code/src_noserver/flame/flame_damage.cpp
void SV_Flame_Apply_Damage(gentity_t *ent);

//t6/code/src_noserver/flame/flame_physics.cpp
void trace_sphere(trace_t *trace, const vec3_t *start, const vec3_t *end, float radius, col_context_t *context);
void Flame_Phys_Collision_Response(bool is_server, trace_t *trace, flameGeneric_s *gen);
void Flame_Impact_Process(bool is_server, flameGeneric_s *gen, trace_t *trace);
void Flame_Phys_Update_Item_Stream(flameGeneric_s *gen, int time);
void Flame_Phys_Update_Item_Fire(flameGeneric_s *gen, int time);
void Flame_Phys_Update_Item_Smoke(flameGeneric_s *gen, int time);
;
// void Flame_Phys_Update_Item_Chunk(flameGeneric_s *gen, int time, phys_static_array<flameGeneric_s *,1000> *flames);
// void Flame_Phys_Update_Item_Drip(flameGeneric_s *gen, int time, phys_static_array<flameGeneric_s *,1000> *flames);
;
void Flame_Phys_Collision(bool is_server, trace_t *trace, flameGeneric_s *gen, col_context_t *context, unsigned __int16 (*dynEnts)[2][100]);
;
// void Flame_Phys_Update_Items(const char *a1@<edi>, int is_server);

//t6/code/src_noserver/flame/flame_sound.cpp
void Flame_Class_Source_Sound_Init(flameSource_t *source);
void Flame_Class_Source_Sound(LocalClientNum_t localClientNum, bool isFiring, bool isFirstPerson, int time, flameTable *table, flameSource_t *source);

//t6/code/src_noserver/flame/flame_system.cpp
// unsigned __int8 *FlameAlloc@<eax>(const char *a1@<edx>, char *a2@<ecx>, unsigned int size, const char *name);
void FlameFree(void *ptr, const char *name);
void Flame_Init_FlameVars();
void Flame_Init_DVars();
void Flame_CMD_PrintDVarsToConsol();
void Flame_CMD_Test_Toggle();
void Flame_CMD_Use_Dvars_Toggle();
void Flame_DVarsToFlameVars(flameTable *fTable);
flameTable *Flame_FindFlameTable(const char *tableName);
long double Flame_SwayRand(float x, float y, int time);
flameSource_t *SV_Flame_Source_Get(int entityNum);
flameSource_t *Flame_Source_Get(int entityNum);
flameRender_s *Flame_Get_FlameRender(const char *name);
void Flame_Item_Init(flameGeneric_s *item, int itemSize);
void Flame_List_Init(flameGeneric_s *list, int itemSize, int listSize);
void Flame_List_Move_Global(flameGeneric_s *item, flameGeneric_s **fromList, flameGeneric_s **toList);
void Flame_List_Add_Local(flameGeneric_s *item, flameGeneric_s **localList);
void Flame_List_Sub_Local(flameGeneric_s *item, flameGeneric_s **localList);
flameSource_t *Flame_Source_Alloc(int entityNum);
flameSource_t *SV_Flame_Source_Alloc(int entityNum);
void Flame_Render_Sprite(cg_t *clientGlobals, Material *material, flameGeneric_s *flameGeneric, float alpha, float frame, unsigned __int8 col);
void Flame_Render_Sprites(int a1, cg_t *clientGlobals, Material *material, flameGeneric_s **flameGenericList, int numItems, unsigned __int8 col);
int Flame_GetLocalClientFlameSource(LocalClientNum_t localClientNum, int EntNum);
char Flame_GetLocalClientSourceRange(LocalClientNum_t localClientNum, int EntNum);
int Flame_GetTrueFlameSourceEntityNum(int EntNum);
void SV_Flame_Update_Source_Internal(flameSource_t *source, int entityNum, flameWeaponConfig_t *weaponConfig, int time);
void SV_Flame_Update_Source(int entityNum, flameWeaponConfig_t *weaponConfig, int time);
void Flame_Generate_Verts(LocalClientNum_t localClientNum);
void CG_Flame_Update_ViewModel(LocalClientNum_t localClientNum, centity_t *cent);
double Flame_Random(bool is_server);
double Flame_CRandom(bool is_server);
double Flame_CalcTimeScale(int startTime, int endTime);
double Flame_CalcInvStartSpeed(float invInitialSpeed, float speedScale);
void Flame_System_Allocate(int max_flame_sources);
void Flame_System_Release();
void Flame_Init_Sources();
void Flame_InitDevGui();
void Flame_Init();
void Flame_Reset();
void CG_Flame_Age_All_Objects(int time, LocalClientNum_t localClientNum);
void SV_Flame_Age_All_Objects(int time);
;
void Flame_Enable_And_Allocate(void *buffer, unsigned int bufsize, int max_flame_sources, int max_flame_chunks, int max_flame_drips, int max_flame_fire, int max_flame_smoke, int max_flame_streams);
void Flame_System_Disable();

