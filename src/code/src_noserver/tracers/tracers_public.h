#pragma once

#include "types.h"

//t6/code/src_noserver/tracers/tracer.cpp
void Tracer_Spawn_ApplyOverrides(LocalClientNum_t localClientNum, const centity_t *instigator, const Weapon weapon, TracerInfo *tracer);
void Tracer_Spawn(LocalClientNum_t localClientNum, const vec3_t *pstart, const vec3_t *pend, const centity_t *instigator, const Weapon weapon);
void Tracer_Draw(const vec3_t *start, const vec3_t *finish, TracerInfo *tracer, TracerDrawFlags drawFlags, const float alphaScale, const bool smokeTrail);
int Tracer_UpdateDrawRate(const LocalClientNum_t localClientNum, const Weapon weapon, centity_t *attackerEnt);
TracerDef *Tracer_FindTracer(const char *tracerName);

//#include "tracers/tracer_load_db.h"

//t6/code/src_noserver/tracers/tracer_load_obj.cpp
int Tracer_GetStringArrayIndex(const char *value, const char **stringArray, int arraySize);
int BG_ParseTracerDefSpecificFieldType(const char **a1, const char *a2, unsigned __int8 *pStruct, const char *pValue, const int iFieldType);
int Tracer_ValidateDef(const char *tracerFilePath, const TracerDef *trDef);
void Tracer_Load_StringCopy(char **strDest, const char *strSrc);
void Tracer_Load_StringCopy_BatchInternal(char **a1, const char *a2);
int Tracer_Load_ParseFile(const char *name, TracerDef *trDef);
TracerDef *Tracer_Load(const char *name);
TracerDef *Tracer_Register_LoadObj(const char *name);
TracerDef *Tracer_Register_FastFile(const char *name);
TracerDef *Tracer_Register(const char *name);
bool BG_TracerUpdateField(int (*a1)(unsigned __int8 *, const char *, const int, const int), const char *tracerName, const char *keyValue);

