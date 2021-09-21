#include "types.h"
#include "functions.h"

/*
==============
Bot_FreePathNode
==============
*/
void Bot_FreePathNode(const bot_t *bot, pathnode_t *node)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_ClaimPath
==============
*/
void Bot_ClaimPath(bot_t *bot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_FreePath
==============
*/
void Bot_FreePath(bot_t *bot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_GetMaxSpeed
==============
*/
int Bot_GetMaxSpeed(const bot_t *bot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_AtNegotiationEnd
==============
*/
bool Bot_AtNegotiationEnd(const bot_t *bot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_ShouldAvoid
==============
*/
bool Bot_ShouldAvoid(const bot_t *bot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_PathClear
==============
*/
void Bot_PathClear(bot_t *bot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_GetPathToGoal
==============
*/
bool Bot_GetPathToGoal(bot_t *bot, const vec3_t *goal, pathnode_t *nodeTo, bool continueFromNegotiation)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_LerpDvars
==============
*/
float Bot_LerpDvars(const dvar_t *from, const dvar_t *to, float frac)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_CalcAdjustedAxis
==============
*/
void Bot_CalcAdjustedAxis(float pitchAxis, float yawAxis, float *outPitchAxis, float *outYawAxis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_ApplyTurnRates
==============
*/
float *Bot_ApplyTurnRates(float *a1, float *a2, float pitchDelta, float ads, float yawDelta, float accel, float pitchAxis, float pitch, float *yaw, float *a10)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Bot_UpdateSteeringInput
==============
*/
void Bot_UpdateSteeringInput(const dvar_t *a1, const dvar_t *a2, bot_steering_t *steer, float ads, vec2_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_UpdateSteering
==============
*/
void Bot_UpdateSteering(bot_t *bot, usercmd_s *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_UpdateAngleWrap
==============
*/
void Bot_UpdateAngleWrap(bot_steering_t *steer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_FarthestSeenNode
==============
*/
const pathnode_t *Bot_FarthestSeenNode(const bot_t *bot, bool useNegotiation)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Bot_UpdateLookahead
==============
*/
void Bot_UpdateLookahead(bot_t *bot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_MantleGlassTrace
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Bot_InvalidatePath
==============
*/
void Bot_InvalidatePath(bot_t *bot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_AtNegotiationBegin
==============
*/
bool Bot_AtNegotiationBegin(const bot_t *bot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_AvoidTracePassed
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Bot_UpdateAvoidance
==============
*/
bool Bot_UpdateAvoidance(const bot_t *bot, vec3_t *vOutDir)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Bot_UpdateMovement
==============
*/
void Bot_UpdateMovement(bot_t *bot, usercmd_s *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Bot_Seek
==============
*/
void Bot_Seek(bot_t *bot, bot_goal_t *goal, usercmd_s *cmd, const usercmd_s *lastUsercmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

