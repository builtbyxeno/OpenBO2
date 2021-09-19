#pragma once

#include "types.h"

//t6/code/src_noserver/tracers/tracer.cpp
void Tracer_Spawn_ApplyOverrides(;
void Tracer_Spawn(;
void Tracer_Draw(;
int Tracer_UpdateDrawRate(const LocalClientNum_t localClientNum, const Weapon weapon, centity_t *attackerEnt);
TracerDef *Tracer_FindTracer(const char *tracerName);

//#include "tracers/tracer_load_db.h"

//t6/code/src_noserver/tracers/tracer_load_obj.cpp
int Tracer_GetStringArrayIndex(const char *value, const char **stringArray, int arraySize);
// int BG_ParseTracerDefSpecificFieldType@<eax>(;
int Tracer_ValidateDef(const char *tracerFilePath, const TracerDef *trDef);
void Tracer_Load_StringCopy(char **strDest, const char *strSrc);
void Tracer_Load_StringCopy_BatchInternal(char **a1, const char *a2);
int Tracer_Load_ParseFile(const char *name, TracerDef *trDef);
TracerDef *Tracer_Load(const char *name);
TracerDef *Tracer_Register_LoadObj(const char *name);
TracerDef *Tracer_Register_FastFile(const char *name);
TracerDef *Tracer_Register(const char *name);
// bool BG_TracerUpdateField@<al>(;

