#pragma once

#include "types.h"

//t6/code/src_noserver/riotshield/riotshield.cpp
void Riotshield_RegisterDvars(dvarType_t a1, dvarType_t a2);
void BG_SetRiotshieldModel(playerState_s *ps, bool redShader);
;

//t6/code/src_noserver/riotshield/riotshield_client.cpp
BOOL CG_EntityIsDeployedRiotshield(const centity_t *cent);
BOOL CG_EntityNumIsDeployedRiotshield(LocalClientNum_t localClientNum, int entnum);

//t6/code/src_noserver/riotshield/riotshield_server.cpp
gentity_t *G_DeployRiotshield(gentity_t *owner, gentity_t *shield_ent);
BOOL G_EntityIsDeployedRiotshield(const gentity_t *ent);
int G_RefreshRiotshieldAttach(gentity_t *player);

