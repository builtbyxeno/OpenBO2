#include "types.h"
#include "functions.h"

/*
==============
Mantle_RegisterDvars
==============
*/
void Mantle_RegisterDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mantle_DebugPrint
==============
*/
void Mantle_DebugPrint(const char *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mantle_GetUpLength
==============
*/
int Mantle_GetUpLength(const MantleState *mstate)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Mantle_GetOverLength
==============
*/
int Mantle_GetOverLength(const MantleState *mstate)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Mantle_GetAnim
==============
*/
int Mantle_GetAnim(MantleState *mstate)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Mantle_GetAnimDelta
==============
*/
void Mantle_GetAnimDelta(MantleState *mstate, int time, vec3_t *delta)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mantle_FindTransition
==============
*/
int Mantle_FindTransition(float curHeight, float goalHeight)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Mantle_SetHaveWeapon
==============
*/
void Mantle_SetHaveWeapon(MantleState *mstate, const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mantle_Start
==============
*/
void Mantle_Start(pmove_t *pm, playerState_s *ps, MantleResults *mresults)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Hatch_FindHatchSurface
==============
*/
bool Hatch_FindHatchSurface(pmove_t *pm, pml_t *pml, trace_t *trace, vec3_t *mantleDir, vec3_t *mantleEnd, const float distance)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Mantle_CreateAnims
==============
*/
void Mantle_CreateAnims(void *(*xanimAlloc)(int))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mantle_ShutdownAnims
==============
*/
void Mantle_ShutdownAnims()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mantle_FindMantleSurface
==============
*/
bool Mantle_FindMantleSurface(pmove_t *pm, pml_t *pml, trace_t *trace, vec3_t *mantleDir)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Mantle_Move
==============
*/
void Mantle_Move(pmove_t *pm, playerState_s *ps, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mantle_CapView
==============
*/
void Mantle_CapView(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mantle_ClearHint
==============
*/
void Mantle_ClearHint(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mantle_IsWeaponInactive
==============
*/
bool Mantle_IsWeaponInactive(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Mantle_IsWeaponEquipped
==============
*/
BOOL Mantle_IsWeaponEquipped(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Mantle_DoAnim
==============
*/
BOOL Mantle_DoAnim(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Mantle_GetDuration
==============
*/
int Mantle_GetDuration(const MantleState *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Mantle_GetMantleFrac
==============
*/
double Mantle_GetMantleFrac(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Mount_CanPlayerDeployTurret
==============
*/
bool Mount_CanPlayerDeployTurret(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Mantle_CalcEndPos
==============
*/
void Mantle_CalcEndPos(pmove_t *pm, MantleResults *mresults)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mount_CheckProne
==============
*/
void Mount_CheckProne(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mount_CheckLedge
==============
*/
void Mount_CheckLedge(MantleResults *mresults)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Mantle_CheckLedge
==============
*/
char Mantle_CheckLedge(MantleResults *mresults, unsigned int a2, float a3, pmove_t *a4)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Hatch_CheckHatch
==============
*/
char __cdecl Hatch_CheckHatch(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Hatch_Check
==============
*/
char Hatch_Check(unsigned int a1, pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Mantle_Check
==============
*/
void Mantle_Check(unsigned int a1, pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

