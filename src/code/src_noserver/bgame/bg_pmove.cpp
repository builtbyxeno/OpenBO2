#include "types.h"
#include "functions.h"

/*
==============
PM_GetMoveSpeedScale
==============
*/
float PM_GetMoveSpeedScale(pmove_t *pm, const WeaponDef *weapDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_AddEvent
==============
*/
void PM_AddEvent(playerState_s *ps, int newEvent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_AddTouchEnt
==============
*/
void PM_AddTouchEnt(pmove_t *pm, int entityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_AddTouchGlass
==============
*/
void PM_AddTouchGlass(pmove_t *pm, int glassId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_ClipVelocity
==============
*/
void PM_ClipVelocity(const vec3_t *in, const vec3_t *normal, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_ProjectVelocity
==============
*/
void PM_ProjectVelocity(const vec3_t *velIn, const vec3_t *normal, vec3_t *velOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_GetEffectiveStance
==============
*/
int PM_GetEffectiveStance(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_GetSprintLeft
==============
*/
int PM_GetSprintLeft(const playerState_s *ps, const int gametime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_IsSprinting
==============
*/
bool PM_IsSprinting(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_StartSprint
==============
*/
void PM_StartSprint(playerState_s *ps, pmove_t *pm, const pml_t *pml, int sprintLeft)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdateVisionAnims
==============
*/
void PM_UpdateVisionAnims(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdateScriptedAnim
==============
*/
void PM_UpdateScriptedAnim(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_GetEntityOrigin
==============
*/
int PM_GetEntityOrigin(const unsigned __int8 handler, LocalClientNum_t localClientNum, int entIndex, vec3_t *outPosition)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_GetEntityVelocity
==============
*/
BOOL PM_GetEntityVelocity(const unsigned __int8 handler, LocalClientNum_t localClientNum, int entIndex, vec3_t *outVelocity)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_GetMeleeChargeFriction
==============
*/
float PM_GetMeleeChargeFriction(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_Friction
==============
*/
void PM_Friction(playerState_s *ps, pml_t *pml, pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Accelerate
==============
*/
void PM_Accelerate(playerState_s *ps, const pml_t *pml, vec3_t *wishdir, float wishspeed, float accel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_DoSlideAdjustments
==============
*/
void PM_DoSlideAdjustments(playerState_s *ps, const pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_MoveScale
==============
*/
float PM_MoveScale(playerState_s *ps, float fmove, float rmove, float umove)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_CmdScale
==============
*/
float PM_CmdScale(playerState_s *ps, usercmd_s *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_DamageScale_Walk
==============
*/
double PM_DamageScale_Walk(int damage_timer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_SetMovementDir
==============
*/
void PM_SetMovementDir(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_GroundSurfaceType
==============
*/
unsigned int PM_GroundSurfaceType(playerState_s *ps, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_DeadMove
==============
*/
void PM_DeadMove(playerState_s *ps, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_FootstepType
==============
*/
int PM_FootstepType(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_DamageLandingForSurface
==============
*/
int PM_DamageLandingForSurface(playerState_s *ps, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_CrashLand
==============
*/
void PM_CrashLand(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_GetWaterLevel
==============
*/
int PM_GetWaterLevel(const playerState_s *ps, float waterHeight)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_SetWaterLevel
==============
*/
void PM_SetWaterLevel(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_GetViewHeightLerpTime
==============
*/
int PM_GetViewHeightLerpTime(const playerState_s *ps, int iTarget, int bDown)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_ViewHeightTableLerp
==============
*/
float PM_ViewHeightTableLerp(int iFrac, viewLerpWaypoint_s *pTable, int lowVal, int highVal)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_ViewHeightAdjust
==============
*/
void __cdecl PM_ViewHeightAdjust(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PlayerProneAllowed
==============
*/
bool PlayerProneAllowed(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_IsPlayerFrozenByWeapon
==============
*/
bool PM_IsPlayerFrozenByWeapon(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_ShouldLeaveStanceAlone
==============
*/
bool PM_ShouldLeaveStanceAlone(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_FootstepEvent
==============
*/
void PM_FootstepEvent(pmove_t *pm, pml_t *pml, int iOldBobCycle, int iNewBobCycle, int bFootStep)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_ShouldMakeFootsteps
==============
*/
BOOL PM_ShouldMakeFootsteps(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_Footsteps_TurnAnim
==============
*/
int PM_Footsteps_TurnAnim(pmove_t *pm, clientInfo_t *ci)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_ShouldFlinch
==============
*/
int PM_ShouldFlinch(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_Footstep_LadderMove
==============
*/
bool PM_Footstep_LadderMove(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_Footsteps_NotMoving
==============
*/
void PM_Footsteps_NotMoving(pmove_t *pm, pml_t *pml, int stance)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_GetMoveAnim
==============
*/
scriptAnimMoveTypes_t PM_GetMoveAnim(playerState_s *ps, pml_t *pml, PmStanceFrontBack stance, int walking, int sprinting)
{
	UNIMPLEMENTED(__FUNCTION__);
	scriptAnimMoveTypes_t tmp;
	return tmp;
}

/*
==============
PM_Footstep_NotTryingToMove
==============
*/
void PM_Footstep_NotTryingToMove(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_VehicleDrive
==============
*/
void PM_VehicleDrive(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_CalcBob
==============
*/
int BG_CalcBob(pmove_t *pm, pml_t *pml, int old, float bobmove)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_ApplyMovementAnimations
==============
*/
void PM_ApplyMovementAnimations(pmove_t *pm, pml_t *pml, PmStanceFrontBack stanceFrontBack, int walking, int sprinting)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_ApplyLegAnimations
==============
*/
void PM_ApplyLegAnimations(pmove_t *pm, pml_t *pml, int iStance, PmStanceFrontBack stanceFrontBack, int walking, int sprinting)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_CalcPlayerPitch
==============
*/
float PM_CalcPlayerPitch(playerState_s *ps, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_IsInAir
==============
*/
bool PM_IsInAir(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_DropTimers
==============
*/
void PM_DropTimers(playerState_s *ps, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_CheckProneTurned
==============
*/
int BG_CheckProneTurned(playerState_s *ps, float newProneYaw, unsigned __int8 handler)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_UpdateViewLockedEnt
==============
*/
void PM_UpdateViewLockedEnt(LocalClientNum_t localClientNum, playerState_s *ps, usercmd_s *cmd, unsigned __int8 handler)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdateViewAngles_Clamp
==============
*/
void PM_UpdateViewAngles_Clamp(playerState_s *ps, usercmd_s *cmd, unsigned __int8 handler)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdateViewAngles_RangeLimited
==============
*/
void PM_UpdateViewAngles_RangeLimited(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdateViewAngles_LadderClamp
==============
*/
void PM_UpdateViewAngles_LadderClamp(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdateViewAngles_ProneYawClamp
==============
*/
void PM_UpdateViewAngles_ProneYawClamp(playerState_s *ps, float delta, int proneBlocked, float oldViewYaw, float newViewYaw)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdateViewAngles_PronePitchClamp
==============
*/
void PM_UpdateViewAngles_PronePitchClamp(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdateViewAngles_Prone
==============
*/
void PM_UpdateViewAngles_Prone(playerState_s *ps, float msec, usercmd_s *cmd, unsigned __int8 handler, float oldViewYaw)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_ViewRangeLimited
==============
*/
BOOL PM_ViewRangeLimited(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_UpdatePronePitch
==============
*/
void PM_UpdatePronePitch(unsigned int ebp0, pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_SetProneMovementOverride
==============
*/
void PM_SetProneMovementOverride(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_ClearLadderFlag
==============
*/
void PM_ClearLadderFlag(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_MeleeChargeClear
==============
*/
void PM_MeleeChargeClear(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_GetMeleeChargeYaw
==============
*/
float PM_GetMeleeChargeYaw(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_MeleeChargeIsValid
==============
*/
bool PM_MeleeChargeIsValid(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_MeleeChargeStart
==============
*/
void PM_MeleeChargeStart(pml_t *a1, pmove_t *a2, pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_IsValidCharge
==============
*/
bool PM_IsValidCharge(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_MeleeChargeCatchupVelocity
==============
*/
void PM_MeleeChargeCatchupVelocity(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_MeleeChargeUpdate
==============
*/
void PM_MeleeChargeUpdate(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_MeleeChargeCheck
==============
*/
void PM_MeleeChargeCheck(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_MeleeChargeMove_IsActive
==============
*/
bool PM_MeleeChargeMove_IsActive(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_MeleeChargeMove
==============
*/
void PM_MeleeChargeMove(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ClearPlayerVelocity
==============
*/
void ClearPlayerVelocity(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdatePush
==============
*/
void PM_UpdatePush(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_seedRandWithGameTime
==============
*/
void BG_seedRandWithGameTime(unsigned int *pHoldrand)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_rand
==============
*/
unsigned int BG_rand(unsigned int *pHoldrand)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_irand
==============
*/
int BG_irand(int min, int max, unsigned int *pHoldrand)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_random
==============
*/
double BG_random(unsigned int *pHoldrand)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_trace
==============
*/
void PM_trace(pmove_t *pm, trace_t *results, const vec3_t *start, const vec3_t *mins, const vec3_t *maxs, const vec3_t *end, int passEntityNum, int contentMask)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_GetSprintLeftLastTime
==============
*/
int PM_GetSprintLeftLastTime(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_EndSprint
==============
*/
void PM_EndSprint(playerState_s *ps, pmove_t *pm, const pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_SprintStartInterferingButtons
==============
*/
/*char PM_SprintStartInterferingButtons(const playerState_s *ps, const int forwardSpeed, bitarray<64> *button_bits)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
PM_CmdScaleForStance
==============
*/
float PM_CmdScaleForStance(const pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_SprintEndingButtons
==============
*/
bool PM_SprintEndingButtons(const pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_CmdScale_Walk
==============
*/
float PM_CmdScale_Walk(pmove_t *pm, usercmd_s *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_FlyMove
==============
*/
void PM_FlyMove(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_NoclipMove
==============
*/
void PM_NoclipMove(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UFOMove
==============
*/
void PM_UFOMove(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_GetMaxSpeed
==============
*/
float PM_GetMaxSpeed(pmove_t *pm, int walking, int sprinting)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_Footsteps
==============
*/
void PM_Footsteps(float ps, pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdateLean
==============
*/
void PM_UpdateLean(unsigned int a1, playerState_s *ps, float msec, usercmd_s *cmd, void (__cdecl *capsuleTrace)(trace_t *, const vec3_t *, const vec3_t *, const vec3_t *, const vec3_t *, int, int, col_context_t *))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdateViewAngles
==============
*/
void PM_UpdateViewAngles(usercmd_s *a1, playerState_s *a2, unsigned int localClientNum, LocalClientNum_t oldViewYaw, playerState_s *ps, float msec, usercmd_s *cmd, unsigned __int8 handler, float a9)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdatePlayerWalkingFlag
==============
*/
void PM_UpdatePlayerWalkingFlag(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_WeaponThrustCheck
==============
*/
void PM_WeaponThrustCheck(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
TurretNVGTrigger
==============
*/
void TurretNVGTrigger(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_srand
==============
*/
void BG_srand(unsigned int *pHoldrand)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_playerTrace
==============
*/
void PM_playerTrace(int a1, pmove_t *pm, trace_t *results, const vec3_t *start, const vec3_t *mins, const vec3_t *maxs, const vec3_t *end, int passEntityNum, int contentMask)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
is_not_penetrating
==============
*/
bool is_not_penetrating(const vec3_t *start, const vec3_t *mins, const vec3_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_CanCrouch
==============
*/
bool PM_CanCrouch(playerState_s *ps, pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_CanStand
==============
*/
bool __cdecl PM_CanStand(playerState_s *ps, pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_UpdateSprint
==============
*/
void PM_UpdateSprint(pmove_t *pm, const pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_SwimMove
==============
*/
void PM_SwimMove(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_CorrectAllSolid
==============
*/
int PM_CorrectAllSolid(pmove_t *pm, pml_t *pml, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_GroundTraceMissed
==============
*/
void PM_GroundTraceMissed(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_GroundTrace
==============
*/
void PM_GroundTrace(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_CheckDuck
==============
*/
void PM_CheckDuck(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_FoliageSounds
==============
*/
void PM_FoliageSounds(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_CheckLadderMove
==============
*/
void PM_CheckLadderMove(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_AirMove
==============
*/
void PM_AirMove(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_WalkMove
==============
*/
void PM_WalkMove(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_LadderMove
==============
*/
void PM_LadderMove(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PmoveSingle
==============
*/
void PmoveSingle(const char *a1, float a2, pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Pmove_1
==============
*/
void Pmove_1(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Pmove
==============
*/
void Pmove(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

