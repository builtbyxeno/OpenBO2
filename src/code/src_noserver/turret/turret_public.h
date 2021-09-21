#pragma once

#include "types.h"

//t6/code/src_noserver/turret/turret_placement.cpp
int Turret_PlaceTurret_UpdateFooting(const turret_handler handler, const int moverEntNum, trace_t *trace, vec3_t *outOrigin, vec3_t *outAxis);
int Turret_PlaceTurret_Wallmount(unsigned int a1, const turret_handler handler, const int moverEntNum, const vec3_t *moverOrigin, const vec3_t *viewOrigin, const vec3_t *viewAngles, vec3_t *outOrigin, vec3_t *outAngles, int turretFlags);
int Turret_PlaceTurret_Internal(unsigned int a1, const turret_handler handler, const int moverEntNum, const vec3_t *moverOrigin, const vec3_t *viewOrigin, const vec3_t *viewAngles, vec3_t *outOrigin, vec3_t *outAngles, int turretFlags);
// int Turret_PlaceTurret_Client(const char *a1@<ebx>, const LocalClientNum_t localClientNum, const entityState_s *es, vec3_t *outOrigin, vec3_t *outAngles);
int Turret_PlaceTurret_Server(playerState_s *ps, vec3_t *outOrigin, vec3_t *outAngles);

