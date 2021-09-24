#include "types.h"

/*
==============
AA_GetAutoMeleeRange
==============
*/
double AA_GetAutoMeleeRange(Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TRACK_aim_assist
==============
*/
void TRACK_aim_assist()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_LerpDvars
==============
*/
float AimAssist_LerpDvars(const dvar_t *from, const dvar_t *to, float frac)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_RegisterDvars
==============
*/
void AimAssist_RegisterDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_Init
==============
*/
void AimAssist_Init(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_BackupPlayerState
==============
*/
void AimAssist_BackupPlayerState(LocalClientNum_t localClientNum, const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_FovScale
==============
*/
void AimAssist_FovScale(AimAssistGlobals *aaGlob, float tanHalfFovY)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_CreateScreenMatrix
==============
*/
void AimAssist_CreateScreenMatrix(AimAssistGlobals *aaGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_ConvertToClipBounds
==============
*/
bool AimAssist_ConvertToClipBounds(const AimAssistGlobals *aaGlob, const vec3_t *bounds, const vec3_t *mtx, vec3_t *clipBounds)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_GetCrosshairDistSqr
==============
*/
float AimAssist_GetCrosshairDistSqr(LocalClientNum_t localClientNum, const vec2_t *clipMins, const vec2_t *clipMaxs)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_DoBoundsIntersectCenterBox
==============
*/
bool AimAssist_DoBoundsIntersectCenterBox(const vec2_t *clipMins, const vec2_t *clipMaxs, float clipHalfWidth, float clipHalfHeight)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_GetAimAssistRange
==============
*/
double AimAssist_GetAimAssistRange(Weapon weapon, float adsLerp)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_GetAutoAimRange
==============
*/
double AimAssist_GetAutoAimRange(double localClientNum, LocalClientNum_t a2, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_AddToTargetList
==============
*/
void AimAssist_AddToTargetList(AimAssistGlobals *aaGlob, const AimScreenTarget *screenTarget)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimTarget_GetTagPos
==============
*/
int AimTarget_GetTagPos(LocalClientNum_t localClientNum, const centity_t *cent, unsigned int tagName, vec3_t *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_CalcAimPos
==============
*/
int AimAssist_CalcAimPos(LocalClientNum_t localClientNum, const centity_t *targetEnt, vec3_t *aimPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_UpdateScreenTargets
==============
*/
void AimAssist_UpdateScreenTargets(LocalClientNum_t localClientNum, const vec3_t *viewOrg, const vec3_t *viewAngles, float tanHalfFovX, float tanHalfFovY)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_GetScreenTargetCount
==============
*/
int AimAssist_GetScreenTargetCount(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_GetScreenTargetEntity
==============
*/
int AimAssist_GetScreenTargetEntity(LocalClientNum_t localClientNum, int targetIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_ClearEntityReference
==============
*/
void AimAssist_ClearEntityReference(LocalClientNum_t localClientNum, int entIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_IsPrevTargetEntity
==============
*/
bool AimAssist_IsPrevTargetEntity(LocalClientNum_t localClientNum, int entIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_GetTargetFromEntity
==============
*/
AimScreenTarget *AimAssist_GetTargetFromEntity(AimAssistGlobals *aaGlob, int entIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
AimAssist_GetBestTarget
==============
*/
AimScreenTarget *AimAssist_GetBestTarget(const vec2_t *a1, const vec2_t *a2, AimAssistGlobals *aaGlob, float range, float regionWidth, float regionHeight)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
AimAssist_GetPrevOrBestTarget
==============
*/
AimScreenTarget *AimAssist_GetPrevOrBestTarget(int a1, AimAssistGlobals *a2, AimAssistGlobals *aaGlob, float range, float regionWidth, float regionHeight)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
AimAssist_CalcAdjustedAxis
==============
*/
void AimAssist_CalcAdjustedAxis(const AimInput *input, float *pitchAxis, float *yawAxis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_IsPlayerUsingOffhand
==============
*/
bool AimAssist_IsPlayerUsingOffhand(const AimAssistPlayerState *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_IsSlowdownActive
==============
*/
int AimAssist_IsSlowdownActive(const AimAssistPlayerState *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_CalcSlowdown
==============
*/
void AimAssist_CalcSlowdown(const AimInput *input, float *pitchScale, float *yawScale)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_GetProfileSensitivity
==============
*/
float AimAssist_GetProfileSensitivity(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_ApplyTurnRates
==============
*/
double AimAssist_ApplyTurnRates(float *a1, LocalClientNum_t a2, const AimInput *input, AimOutput *output)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_ClearAutoAimTarget
==============
*/
void AimAssist_ClearAutoAimTarget(AimAssistGlobals *aaGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_ClearAutoMeleeTarget
==============
*/
void AimAssist_ClearAutoMeleeTarget(AimAssistGlobals *aaGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_SetAutoMeleeTarget
==============
*/
void AimAssist_SetAutoMeleeTarget(AimAssistGlobals *aaGlob, const AimScreenTarget *screenTarget)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssit_ShouldMeleeChargeMoveLimit
==============
*/
bool AimAssit_ShouldMeleeChargeMoveLimit(const AimAssistGlobals *aaGlob, const AimScreenTarget *screenTarget)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_ScreenTargetGetAimPos
==============
*/
void __cdecl AimAssist_ScreenTargetGetAimPos(LocalClientNum_t localClientNum, AimScreenTarget *aimScreenTarget, vec3_t *aimPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_DrawCenterBox
==============
*/
void AimAssist_DrawCenterBox(const AimAssistGlobals *aaGlob, float clipHalfWidth, float clipHalfHeight, const vec4_t *color, bool centerOnCrosshair)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_DrawTargets
==============
*/
void AimAssist_DrawTargets(LocalClientNum_t localClientNum, const playerState_s *ps, const vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_DrawDebugOverlay
==============
*/
void AimAssist_DrawDebugOverlay(bool a1, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_UpdateTweakables
==============
*/
void AimAssist_UpdateTweakables(const AimInput *input, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_UpdateAdsLerp
==============
*/
void AimAssist_UpdateAdsLerp(const AimInput *input)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_Setup
==============
*/
void AimAssist_Setup(LocalClientNum_t localClientNum, const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_UpdateAutoAimTarget
==============
*/
bool AimAssist_UpdateAutoAimTarget(AimAssistGlobals *aaGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_SetAutoAimTarget
==============
*/
void AimAssist_SetAutoAimTarget(AimAssistGlobals *aaGlob, const AimScreenTarget *screenTarget)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_ShouldAutoAim
==============
*/
bool AimAssist_ShouldAutoAim(const AimInput *input)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_ApplyAutoAim
==============
*/
void AimAssist_ApplyAutoAim(const AimInput *input, AimOutput *output)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_ApplyLockOn
==============
*/
void AimAssist_ApplyLockOn(char *a1, const AimInput *input, AimOutput *output)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_UpdateAutoMeleeTarget
==============
*/
bool AimAssist_UpdateAutoMeleeTarget(AimAssistGlobals *aaGlob, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_IsMeleePressed
==============
*/
bool AimAssist_IsMeleePressed(const AimInput *input, const AimAssistGlobals *aaGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AimAssist_ApplyAutoMelee
==============
*/
void AimAssist_ApplyAutoMelee(const AimInput *input, AimOutput *output)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_UpdateGamePadInput
==============
*/
void AimAssist_UpdateGamePadInput(LocalClientNum_t a1, const AimInput *a2, const AimInput *input, AimOutput *output)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AimAssist_UpdateMouseInput
==============
*/
void AimAssist_UpdateMouseInput(LocalClientNum_t a1, const AimInput *a2, const AimInput *input, AimOutput *output)
{
	UNIMPLEMENTED(__FUNCTION__);
}

