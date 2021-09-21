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
bool AimAssist_ConvertToClipBounds(const AimAssistGlobals *aaGlob, const vec3_t *bounds, const vec3_t *mtx, vec3_t *clipBounds);
float AimAssist_GetCrosshairDistSqr(LocalClientNum_t localClientNum, const vec2_t *clipMins, const vec2_t *clipMaxs);
bool AimAssist_DoBoundsIntersectCenterBox(const vec2_t *clipMins, const vec2_t *clipMaxs, float clipHalfWidth, float clipHalfHeight);
double AimAssist_GetAimAssistRange(Weapon weapon, float adsLerp);
double AimAssist_GetAutoAimRange(double localClientNum, LocalClientNum_t a2, Weapon weapon);
void AimAssist_AddToTargetList(AimAssistGlobals *aaGlob, const AimScreenTarget *screenTarget);
int AimTarget_GetTagPos(LocalClientNum_t localClientNum, const centity_t *cent, unsigned int tagName, vec3_t *pos);
int AimAssist_CalcAimPos(LocalClientNum_t localClientNum, const centity_t *targetEnt, vec3_t *aimPos);
void AimAssist_UpdateScreenTargets(LocalClientNum_t localClientNum, const vec3_t *viewOrg, const vec3_t *viewAngles, float tanHalfFovX, float tanHalfFovY);
int AimAssist_GetScreenTargetCount(LocalClientNum_t localClientNum);
int AimAssist_GetScreenTargetEntity(LocalClientNum_t localClientNum, int targetIndex);
void AimAssist_ClearEntityReference(LocalClientNum_t localClientNum, int entIndex);
bool AimAssist_IsPrevTargetEntity(LocalClientNum_t localClientNum, int entIndex);
AimScreenTarget *AimAssist_GetTargetFromEntity(AimAssistGlobals *aaGlob, int entIndex);
AimScreenTarget *AimAssist_GetBestTarget(const vec2_t *a1, const vec2_t *a2, AimAssistGlobals *aaGlob, float range, float regionWidth, float regionHeight);
AimScreenTarget *AimAssist_GetPrevOrBestTarget(int a1, AimAssistGlobals *a2, AimAssistGlobals *aaGlob, float range, float regionWidth, float regionHeight);
void AimAssist_CalcAdjustedAxis(const AimInput *input, float *pitchAxis, float *yawAxis);
bool AimAssist_IsPlayerUsingOffhand(const AimAssistPlayerState *ps);
int AimAssist_IsSlowdownActive(const AimAssistPlayerState *ps);
void AimAssist_CalcSlowdown(const AimInput *input, float *pitchScale, float *yawScale);
float AimAssist_GetProfileSensitivity(LocalClientNum_t localClientNum);
double AimAssist_ApplyTurnRates(float *a1, LocalClientNum_t a2, const AimInput *input, AimOutput *output);
void AimAssist_ClearAutoAimTarget(AimAssistGlobals *aaGlob);
void AimAssist_ClearAutoMeleeTarget(AimAssistGlobals *aaGlob);
void AimAssist_SetAutoMeleeTarget(AimAssistGlobals *aaGlob, const AimScreenTarget *screenTarget);
bool AimAssit_ShouldMeleeChargeMoveLimit(const AimAssistGlobals *aaGlob, const AimScreenTarget *screenTarget);
void __cdecl AimAssist_ScreenTargetGetAimPos(LocalClientNum_t localClientNum, AimScreenTarget *aimScreenTarget, vec3_t *aimPos);
void AimAssist_DrawCenterBox(const AimAssistGlobals *aaGlob, float clipHalfWidth, float clipHalfHeight, const vec4_t *color, bool centerOnCrosshair);
void AimAssist_DrawTargets(LocalClientNum_t localClientNum, const playerState_s *ps, const vec4_t *color);
void AimAssist_DrawDebugOverlay(bool a1, LocalClientNum_t localClientNum);
void AimAssist_UpdateTweakables(const AimInput *input, LocalClientNum_t localClientNum);
void AimAssist_UpdateAdsLerp(const AimInput *input);
void AimAssist_Setup(LocalClientNum_t localClientNum, const playerState_s *ps);
bool AimAssist_UpdateAutoAimTarget(AimAssistGlobals *aaGlob);
void AimAssist_SetAutoAimTarget(AimAssistGlobals *aaGlob, const AimScreenTarget *screenTarget);
bool AimAssist_ShouldAutoAim(const AimInput *input);
void AimAssist_ApplyAutoAim(const AimInput *input, AimOutput *output);
void AimAssist_ApplyLockOn(char *a1, const AimInput *input, AimOutput *output);
bool AimAssist_UpdateAutoMeleeTarget(AimAssistGlobals *aaGlob, LocalClientNum_t localClientNum);
bool AimAssist_IsMeleePressed(const AimInput *input, const AimAssistGlobals *aaGlob);
void AimAssist_ApplyAutoMelee(const AimInput *input, AimOutput *output);
void AimAssist_UpdateGamePadInput(LocalClientNum_t a1, const AimInput *a2, const AimInput *input, AimOutput *output);
void AimAssist_UpdateMouseInput(LocalClientNum_t a1, const AimInput *a2, const AimInput *input, AimOutput *output);

//t6/code/src_noserver/aim_assist/aim_target.cpp
void TRACK_aim_target();
const dvar_t *AimTarget_RegisterDvars();
void AimTarget_Init(LocalClientNum_t localClientNum);
BOOL R_SortStaticModelsOnAxis_PosX(const GfxStaticModelCombinedInst *smodelCombinedInst0, const GfxStaticModelCombinedInst *smodelCombinedInst1);
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
bool AimTarget_IsTargetVisible(unsigned int a1, const centity_t *a2, unsigned int localClientNum, LocalClientNum_t targetEnt, const centity_t *a5);
void AimTarget_GetClientTargetList(LocalClientNum_t localClientNum, const AimTarget **targetList, int *targetCount);

