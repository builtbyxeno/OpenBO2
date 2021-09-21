#include "types.h"
#include "functions.h"

/*
==============
Bot_PredictPosition
==============
*/
void Bot_PredictPosition(const gentity_t *ent, vec3_t *vPos, int numFrames)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_GetCurrentGoal
==============
*/
bot_goal_t *Bot_GetCurrentGoal(bot_t *bot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Bot_AddGoal
==============
*/
char Bot_AddGoal(bot_t *bot, const vec3_t *goalPos, pathnode_t *goalNode, const float radius, BotGoalPriority priority, unsigned __int16 notify)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_GoalArrive
==============
*/
void Bot_GoalArrive(const bot_t *bot, bot_goal_t *goal)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_GoalFailed
==============
*/
void Bot_GoalFailed(bot_t *bot, bot_goal_t *goal)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_BotGoalAdd
==============
*/
char G_BotGoalAdd(const client_t *cl, const vec3_t *goalPos, pathnode_t *goalNode, const float radius, BotGoalPriority priority, unsigned __int16 notify)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_BotGoalCancel
==============
*/
void G_BotGoalCancel(const client_t *cl, unsigned __int16 notify)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_BotAtGoal
==============
*/
char G_BotAtGoal(const client_t *cl, unsigned __int16 notify)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_BotHasGoal
==============
*/
char G_BotHasGoal(const client_t *cl, unsigned __int16 notify)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_BotGetGoal
==============
*/
bool G_BotGetGoal(const client_t *cl, unsigned __int16 notify, vec3_t *vOrigin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_BotGetThreats
==============
*/
int G_BotGetThreats(const client_t *cl, float fov, bot_threat_t *threatList, int maxCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_BotSightTrace
==============
*/
bool G_BotSightTrace(const client_t *cl, const gentity_t *ent, const vec3_t *vEnd)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_HasLookAt
==============
*/
bool Bot_HasLookAt(const bot_t *bot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_BotDisconnect
==============
*/
void G_BotDisconnect(client_t *cl)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_InvalidatePaths
==============
*/
void Bot_InvalidatePaths()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_Load
==============
*/
void Bot_Load(MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_BotRegisterDvars
==============
*/
void SV_BotRegisterDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_DrawString
==============
*/
void Bot_DrawString(LocalClientNum_t localClientNum, const ScreenPlacement *scrPlace, const char *text, float x, float *y, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_DrawDebug
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
DrawClaimedNodes
==============
*/
unsigned int DrawClaimedNodes()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LerpColor
==============
*/
float *LerpColor(float *result, float *a2, float a, const vec4_t *a4)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DrawGoalString
==============
*/
void DrawGoalString(const client_t *cl, const vec3_t *origin, const char *txt, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_DrawPath
==============
*/
void Bot_DrawPath(float a1, const client_t *cl)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_DrawDangerousNode
==============
*/
void Bot_DrawDangerousNode(const pathnode_t *node, const vec4_t *teamColor, team_t team)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_DrawDangerousAreas
==============
*/
void Bot_DrawDangerousAreas(float a1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_DrawPaths
==============
*/
void Bot_DrawPaths()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_DrawThreats
==============
*/
void Bot_DrawThreats(float a1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_DebugBots
==============
*/
void G_DebugBots(void)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_NameUsed
==============
*/
client_t *Bot_NameUsed(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_BotNameRandom
==============
*/
const char *SV_BotNameRandom()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_ZombieNameRandom
==============
*/
const char *SV_ZombieNameRandom()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SV_BotNameUpdate
==============
*/
void SV_BotNameUpdate(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_SetStance
==============
*/
void Bot_SetStance(ClientNum_t clientNum, unsigned __int16 stance)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_InitBots
==============
*/
void G_InitBots()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_UpdateFailsafe
==============
*/
char Bot_UpdateFailsafe(const bot_t *bot, const playerState_s *ps, usercmd_s *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_Think
==============
*/
void Bot_Think(bot_t *bot, usercmd_s *cmd, const usercmd_s *lastUsercmd, float fov)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_BotThink
==============
*/
void G_BotThink(client_t *cl, usercmd_s *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_ZombieNameRandomFriend
==============
*/
bool SV_ZombieNameRandomFriend(const ControllerIndex_t controllerIndex, char *buf, const int bufLen)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LerpColor
==============
*/
void LerpColor(const vec4_t *a, const vec4_t *b, vec4_t *c, float t)
{
	UNIMPLEMENTED(__FUNCTION__);
}

