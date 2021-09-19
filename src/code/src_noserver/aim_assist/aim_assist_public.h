#pragma once

#include "types.h"

//t6/code/src_noserver/aim_assist/aim_assist.cpp
double AA_GetAutoMeleeRange(Weapon weapon);
void TRACK_aim_assist();
float AimAssist_LerpDvars(const dvar_t *from, const dvar_t *to, float frac);
void AimAssist_RegisterDvars();
void AimAssist_Init(LocalClientNum_t localClientNum);
void AimAssist_BackupPlayerState(LocalClientNum_t localClientNum, const playerState_s *ps);
void AimAssist_FovScale(AimAssistGlobals *aaGlob, float tanHalfFovY);
void AimAssist_CreateScreenMatrix(AimAssistGlobals *aaGlob);
bool AimAssist_ConvertToClipBounds(;
float AimAssist_GetCrosshairDistSqr(;
bool AimAssist_DoBoundsIntersectCenterBox(;
double AimAssist_GetAimAssistRange(Weapon weapon, float adsLerp);
// double AimAssist_GetAutoAimRange@<st0>(double a1@<st1>, LocalClientNum_t localClientNum, Weapon weapon);
void AimAssist_AddToTargetList(AimAssistGlobals *aaGlob, const AimScreenTarget *screenTarget);
int AimTarget_GetTagPos(;
int AimAssist_CalcAimPos(LocalClientNum_t localClientNum, const centity_t *targetEnt, vec3_t *aimPos);
void AimAssist_UpdateScreenTargets(;
int AimAssist_GetScreenTargetCount(LocalClientNum_t localClientNum);
int AimAssist_GetScreenTargetEntity(LocalClientNum_t localClientNum, int targetIndex);
void AimAssist_ClearEntityReference(LocalClientNum_t localClientNum, int entIndex);
bool AimAssist_IsPrevTargetEntity(LocalClientNum_t localClientNum, int entIndex);
AimScreenTarget *AimAssist_GetTargetFromEntity(AimAssistGlobals *aaGlob, int entIndex);
// AimScreenTarget *AimAssist_GetBestTarget@<eax>(;
// AimScreenTarget *AimAssist_GetPrevOrBestTarget@<eax>(;
void AimAssist_CalcAdjustedAxis(const AimInput *input, float *pitchAxis, float *yawAxis);
bool AimAssist_IsPlayerUsingOffhand(const AimAssistPlayerState *ps);
int AimAssist_IsSlowdownActive(const AimAssistPlayerState *ps);
void AimAssist_CalcSlowdown(const AimInput *input, float *pitchScale, float *yawScale);
float AimAssist_GetProfileSensitivity(LocalClientNum_t localClientNum);
// double AimAssist_ApplyTurnRates@<st0>(;
void AimAssist_ClearAutoAimTarget(AimAssistGlobals *aaGlob);
void AimAssist_ClearAutoMeleeTarget(AimAssistGlobals *aaGlob);
void AimAssist_SetAutoMeleeTarget(AimAssistGlobals *aaGlob, const AimScreenTarget *screenTarget);
bool AimAssit_ShouldMeleeChargeMoveLimit(;
void AimAssist_ScreenTargetGetAimPos(;
void AimAssist_DrawCenterBox(;
void AimAssist_DrawTargets(LocalClientNum_t localClientNum, const playerState_s *ps, const vec4_t *color);
// void AimAssist_DrawDebugOverlay(bool a1@<dil>, LocalClientNum_t localClientNum);
void AimAssist_UpdateTweakables(const AimInput *input, LocalClientNum_t localClientNum);
void AimAssist_UpdateAdsLerp(const AimInput *input);
void AimAssist_Setup(LocalClientNum_t localClientNum, const playerState_s *ps);
bool AimAssist_UpdateAutoAimTarget(AimAssistGlobals *aaGlob);
void AimAssist_SetAutoAimTarget(AimAssistGlobals *aaGlob, const AimScreenTarget *screenTarget);
bool AimAssist_ShouldAutoAim(const AimInput *input);
void AimAssist_ApplyAutoAim(const AimInput *input, AimOutput *output);
void AimAssist_ApplyLockOn(const AimInput *input, AimOutput *output);
bool AimAssist_UpdateAutoMeleeTarget(AimAssistGlobals *aaGlob, LocalClientNum_t localClientNum);
bool AimAssist_IsMeleePressed(const AimInput *input, const AimAssistGlobals *aaGlob);
void AimAssist_ApplyAutoMelee(const AimInput *input, AimOutput *output);
void AimAssist_UpdateGamePadInput(;
void AimAssist_UpdateMouseInput(;

//t6/code/src_noserver/aim_assist/aim_target.cpp
void TRACK_aim_target();
const dvar_t *AimTarget_RegisterDvars();
void AimTarget_Init(LocalClientNum_t localClientNum);
BOOL R_SortStaticModelsOnAxis_PosX(;
void AimTarget_AddTargetToList(LocalClientNum_t localClientNum, const AimTarget *target);
int AimTarget_GetTagUpdateInterval(const centity_t *ent);
void AimTarget_GetTargetBounds(const centity_t *targetEnt, vec3_t *mins, vec3_t *maxs);
float AimTarget_GetTargetRadius(const centity_t *targetEnt);
void AimTarget_GetTargetCenter(const centity_t *targetEnt, vec3_t *center);
bool AimTarget_IsTargetValid(const cg_t *cgameGlob, const centity_t *targetEnt);
void AimTarget_CreateTarget(LocalClientNum_t localClientNum, const centity_t *targetEnt, AimTarget *target);
bool AimTarget_PlayerInValidState(const playerState_s *ps);
void AimTarget_ProcessEntityInternal(LocalClientNum_t localClientNum, const centity_t *ent);
void AimTarget_UpdateClientTargets(LocalClientNum_t localClientNum);
;
void AimTarget_GetClientTargetList(;

