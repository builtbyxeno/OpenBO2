#include "types.h"
#include "functions.h"

/*
==============
Actor_TeamMoveBlocked
==============
*/
void Actor_TeamMoveBlocked(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_TeamMoveBlockedClear
==============
*/
void Actor_TeamMoveBlockedClear(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_TeamMoveCheckWaitTimer
==============
*/
bool Actor_TeamMoveCheckWaitTimer(actor_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_TeamMoveNeedToCheckWait
==============
*/
bool Actor_TeamMoveNeedToCheckWait(unsigned __int8 moveMode, path_t *pPath)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_TeamMoveCalcMovementDir
==============
*/
char Actor_TeamMoveCalcMovementDir(team_move_context_t *context, ai_teammove_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_AddToList
==============
*/
void Actor_AddToList(int *dodgeEntities, int *dodgeEntityCount, int arraysz, actor_t *pOtherActor)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_TeamMoveGetEntVelocity
==============
*/
void Actor_TeamMoveGetEntVelocity(gentity_t *other, vec2_t *velocity)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_TeamMoveCheckDontDodgeSentient
==============
*/
bool Actor_TeamMoveCheckDontDodgeSentient(actor_t *self, sentient_t *other)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_TeamMoveShouldTryDodgeSentient
==============
*/
/*char Actor_TeamMoveShouldTryDodgeSentient@<al>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
Actor_TeamMoveTryDodge
==============
*/
bool Actor_TeamMoveTryDodge(team_move_context_t *context, team_move_other_context_t *context_other)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_TeamMoveConsiderSlowDown
==============
*/
bool Actor_TeamMoveConsiderSlowDown(team_move_context_t *context, ai_teammove_t *eResult)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_TeamMoveNoDodge
==============
*/
ai_teammove_t Actor_TeamMoveNoDodge(team_move_context_t *context, ai_teammove_t eResult)
{
	UNIMPLEMENTED(__FUNCTION__);
	ai_teammove_t tmp;
	return tmp;
}

/*
==============
Actor_TeamMoveInitializeContext
==============
*/
void Actor_TeamMoveInitializeContext(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_TeamMoveTrimPath
==============
*/
int Actor_TeamMoveTrimPath(path_t *pPath, const team_move_context_t *context)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_TeamMoveTooCloseMoveAway
==============
*/
void Actor_TeamMoveTooCloseMoveAway(const actor_t *self, int mask, team_move_context_t *context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Actor_TeamMoveCheckPileup
==============
*/
bool Actor_TeamMoveCheckPileup(actor_t *self, actor_t *pOtherActor)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_WaitBeforeMoveStart
==============
*/
BOOL Actor_WaitBeforeMoveStart(actor_t *self, team_move_context_t *context, vec2_t *velOther)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Actor_GetTeamMoveStatus
==============
*/
ai_teammove_t Actor_GetTeamMoveStatus(
{
	UNIMPLEMENTED(__FUNCTION__);
	ai_teammove_t tmp;
	return tmp;
}

/*
==============
Actor_MoveAlongPathWithTeam
==============
*/
void Actor_MoveAlongPathWithTeam(
{
	UNIMPLEMENTED(__FUNCTION__);
}

