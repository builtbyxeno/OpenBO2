#pragma once

#include "types.h"

//#include "leaderboard/leaderboard_load_db.h"

//t6/code/src_noserver/leaderboard/leaderboard_load_obj.cpp
void LB_LoadId(const char *parse, LeaderboardDef *lbDef);
bool LB_LoadColDef(const char *parse, LeaderboardDef *lbDef);
LeaderboardDef *LB_LoadDef_LoadObj(const char *filename);
// LeaderboardDef *LB_LoadDef_FastFile@<eax>(char *a1@<edi>, const char *name);
LeaderboardDef *LB_LoadDef();

