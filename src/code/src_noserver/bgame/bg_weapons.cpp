#include "types.h"
#include "functions.h"

/*
==============
BG_ParsePenetrationDepthTable
==============
*/
void BG_ParsePenetrationDepthTable(const char *penetrateType, float *depthTable, const char *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_LoadPenetrationDepthTable
==============
*/
void BG_LoadPenetrationDepthTable()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_AdvanceTrace
==============
*/
bool BG_AdvanceTrace(BulletFireParams *bp, BulletTraceResults *br, float dist)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetSurfacePenetrationDepth
==============
*/
double BG_GetSurfacePenetrationDepth(PenetrateType penetrateType, int surfaceType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_StartWeaponAnim
==============
*/
void PM_StartWeaponAnim(playerState_s *ps, int anim, int leftAnim)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_ContinueWeaponAnim
==============
*/
void PM_ContinueWeaponAnim(playerState_s *ps, int anim, int leftAnim)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetImpactTypeName
==============
*/
const char *BG_GetImpactTypeName(int impactTypeIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_GetFirstEquippedOffhand
==============
*/
Weapon BG_GetFirstEquippedOffhand(const playerState_s *ps, int offhandSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
BG_GetWeaponState
==============
*/
int *BG_GetWeaponState(playerState_s *ps, bool leftGun)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_IsAimDownSightWeapon
==============
*/
BOOL BG_IsAimDownSightWeapon(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsAdsOnlyWeaponChange
==============
*/
BOOL BG_IsAdsOnlyWeaponChange(Weapon oldWeapon, Weapon newWeapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_CanPlayerHaveWeapon
==============
*/
bool BG_CanPlayerHaveWeapon(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_ValidateWeaponNumber
==============
*/
BOOL BG_ValidateWeaponNumber(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsWeaponValid
==============
*/
bool BG_IsWeaponValid(const playerState_s *ps, const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_WeaponBlocksProne
==============
*/
bool BG_WeaponBlocksProne(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsOverheatingWeapon
==============
*/
bool BG_IsOverheatingWeapon(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsBayonetWeapon
==============
*/
bool BG_IsBayonetWeapon(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsUseAsMeleeWeapon
==============
*/
char BG_IsUseAsMeleeWeapon(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_TakeHeldWeapon
==============
*/
void BG_TakeHeldWeapon(playerState_s *ps, const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_IsAdsAllowed
==============
*/
bool PM_IsAdsAllowed(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_ExitAimDownSight
==============
*/
void PM_ExitAimDownSight(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_GetMaxChargeLevelForClipAmmo
==============
*/
int PM_Weapon_GetMaxChargeLevelForClipAmmo(playerState_s *ps, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetChargeShotWeaponCenterSpeed
==============
*/
double BG_GetChargeShotWeaponCenterSpeed(const playerState_s *ps, const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_UpdateQuickScope
==============
*/
void PM_UpdateQuickScope(pmove_t *pm, pml_t *pml, float oldWeaponFrac)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UsingSniperScope
==============
*/
BOOL BG_UsingSniperScope(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UsingTacticalInsertion
==============
*/
int BG_UsingTacticalInsertion(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UsingVariableZoomWeapon
==============
*/
BOOL BG_UsingVariableZoomWeapon(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UsingVariableZoomScope
==============
*/
BOOL BG_UsingVariableZoomScope(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_PlayerWeaponOverheating
==============
*/
bool BG_PlayerWeaponOverheating(const playerState_s *ps, const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_PlayerWeaponOverheatPercent
==============
*/
double BG_PlayerWeaponOverheatPercent(const playerState_s *ps, const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_PlayerWeaponOverheatUpdate
==============
*/
void BG_PlayerWeaponOverheatUpdate(playerState_s *ps, const Weapon weapon, float amount)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_IsWeaponMinFireTimeElapsed
==============
*/
int PM_IsWeaponMinFireTimeElapsed(playerState_s *ps, bool leftGun)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_Weapon_PlayEjectBrass
==============
*/
void BG_Weapon_PlayEjectBrass(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_FinishRechamber
==============
*/
void PM_Weapon_FinishRechamber(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_CheckForRechamber
==============
*/
int PM_Weapon_CheckForRechamber(playerState_s *ps, int delayedAction)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_GetWeaponIndexForHand
==============
*/
Weapon PM_GetWeaponIndexForHand(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
PM_GetWeaponOnVehicleReloadTime
==============
*/
int PM_GetWeaponOnVehicleReloadTime(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_PlayDWThirdPersonReload
==============
*/
bool BG_PlayDWThirdPersonReload(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsAltSwitch
==============
*/
BOOL BG_IsAltSwitch(const playerState_s *ps, const Weapon lastWeapon, const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_CanFastSwitch
==============
*/
bool BG_CanFastSwitch(const WeaponDef *weapDef, int weaponState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsQuickSwitch
==============
*/
char BG_IsQuickSwitch(Weapon oldweapon, Weapon newweapon, int weaponState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_BeginWeaponChange
==============
*/
void PM_BeginWeaponChange(pmove_t *pm, pml_t *pml, Weapon newweapon, const bool quick)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_BeginWeaponRaise
==============
*/
void PM_Weapon_BeginWeaponRaise(playerState_s *ps, unsigned int anim, unsigned int time, float aim, int altSwitch)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_CheckIfDualWieldEmpty
==============
*/
bool BG_CheckIfDualWieldEmpty(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_SwitchWeaponsIfEmpty
==============
*/
void BG_SwitchWeaponsIfEmpty(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetValidPrimaryWeaponForAltMode
==============
*/
Weapon BG_GetValidPrimaryWeaponForAltMode(const playerState_s *ps, Weapon newWeapon, Weapon lastWeaponAltModeSwitch)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
PM_GetWeaponFireButton
==============
*/
int PM_GetWeaponFireButton(Weapon weapon, pmove_t *pm, bool runLeftGun)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_Weapon_FinishWeaponRaise
==============
*/
void PM_Weapon_FinishWeaponRaise(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_ReloadDelayedAction
==============
*/
void PM_Weapon_ReloadDelayedAction(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_FinishReloadEnd
==============
*/
void PM_Weapon_FinishReloadEnd(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_CheckForReloadInterferingWeaponStates
==============
*/
bool PM_CheckForReloadInterferingWeaponStates(pmove_t *pm, pml_t *pml, playerState_s *ps, int weaponState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_AddQuickScopeSpread
==============
*/
float PM_AddQuickScopeSpread(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ShotLimitReached
==============
*/
bool ShotLimitReached(playerState_s *ps, const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BurstFirePending
==============
*/
bool BurstFirePending(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_Weapon_TriggerPullPending
==============
*/
bool PM_Weapon_TriggerPullPending(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_CheckIfIntroShot
==============
*/
BOOL BG_CheckIfIntroShot(const playerState_s *ps, const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_CheckIfLastShot
==============
*/
bool BG_CheckIfLastShot(playerState_s *ps, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_Weapon_StartFiring
==============
*/
void PM_Weapon_StartFiring(pmove_t *pm, pml_t *pml, int delayedAction)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_GetAmmoRequired
==============
*/
int PM_Weapon_GetAmmoRequired(playerState_s *ps, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_Weapon_Jam
==============
*/
void PM_Weapon_Jam(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_SetFPSFireAnim
==============
*/
void PM_Weapon_SetFPSFireAnim(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_AddFiringAimSpreadScale
==============
*/
void PM_Weapon_AddFiringAimSpreadScale(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DrawPlantDebug
==============
*/
void DrawPlantDebug(vec3_t *start, vec3_t *end)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_CheckFriendlyFire
==============
*/
int PM_Weapon_CheckFriendlyFire(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_Weapon_MeleeFire
==============
*/
void PM_Weapon_MeleeFire(playerState_s *ps, int leftGun)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_MeleeInit
==============
*/
void PM_Weapon_MeleeInit(pmove_t *pm, pml_t *pml, bool right, bool left)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_Idle
==============
*/
void PM_Weapon_Idle(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_RiotshieldPrepare
==============
*/
void PM_Weapon_RiotshieldPrepare(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_RiotshieldHold
==============
*/
void PM_Weapon_RiotshieldHold(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_Riotshield
==============
*/
void PM_Weapon_Riotshield(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_OffHand_HoldUse
==============
*/
void PM_Weapon_OffHand_HoldUse(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_OffHandInit
==============
*/
void PM_Weapon_OffHandInit(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_OffHandEnd
==============
*/
void PM_Weapon_OffHandEnd(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_SendEmtpyOffhandEvent
==============
*/
void PM_SendEmtpyOffhandEvent(playerState_s *ps, OffhandSlot offhandSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Detonate
==============
*/
void PM_Detonate(playerState_s *ps, int delayedAction)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_FinishNightVisionWear
==============
*/
void PM_Weapon_FinishNightVisionWear(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_FinishNightVisionRemove
==============
*/
void PM_Weapon_FinishNightVisionRemove(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_WeaponSwimIn
==============
*/
void PM_WeaponSwimIn(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_WeaponSwimOut
==============
*/
void PM_WeaponSwimOut(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sprint_State_Raise
==============
*/
void Sprint_State_Raise(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sprint_State_Loop
==============
*/
void Sprint_State_Loop(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Crawl_State_In
==============
*/
void Crawl_State_In(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Crawl_State_Out
==============
*/
void Crawl_State_Out(playerState_s *ps, int tryingToFiring)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ContinuousFire_State_In
==============
*/
void ContinuousFire_State_In(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ContinuousFire_State_Loop
==============
*/
void ContinuousFire_State_Loop(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ContinuousFire_State_Out
==============
*/
void ContinuousFire_State_Out(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dtp_State_In
==============
*/
void Dtp_State_In(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Slide_State_In
==============
*/
void Slide_State_In(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dtp_State_Out
==============
*/
void Dtp_State_Out(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dtp_State_Loop
==============
*/
void Dtp_State_Loop(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Deploy_State_Deploy
==============
*/
void Deploy_State_Deploy(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Deploy_State_Breakdown
==============
*/
void Deploy_State_Breakdown(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_CheckForDtp
==============
*/
void PM_Weapon_CheckForDtp(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_CheckForSlide
==============
*/
void PM_Weapon_CheckForSlide(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_CheckForDeploy
==============
*/
void PM_Weapon_CheckForDeploy(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_CheckForMantle
==============
*/
void PM_Weapon_CheckForMantle(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UpdateRiotShieldSwitchingFlag
==============
*/
void UpdateRiotShieldSwitchingFlag(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_ResetWeaponState
==============
*/
void __thiscall PM_ResetWeaponState(playerState_s *this)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_PlayerWeaponCountPrimaryTypes
==============
*/
int BG_PlayerWeaponCountPrimaryTypes(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_PlayerWeaponsFull_Primaries
==============
*/
bool BG_PlayerWeaponsFull_Primaries(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_PlayerHasCompatibleWeapon
==============
*/
char BG_PlayerHasCompatibleWeapon(const playerState_s *ps, const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_ThrowingBackGrenade
==============
*/
BOOL BG_ThrowingBackGrenade(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_CalcVehicleTurretWeaponPosOffset
==============
*/
void BG_CalcVehicleTurretWeaponPosOffset(float positionFrac, const float weapDef, const WeaponDef *a3, vec3_t *outOffset)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_LoadWeaponVariantDef_LoadObj
==============
*/
WeaponVariantDef *BG_LoadWeaponVariantDef_LoadObj(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_LoadWeaponVariantDef_FastFile
==============
*/
WeaponVariantDef *BG_LoadWeaponVariantDef_FastFile(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_LoadWeaponVariantDef
==============
*/
WeaponVariantDef *BG_LoadWeaponVariantDef()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_GetFuelTankTime
==============
*/
PlayerHeldWeapon *BG_GetFuelTankTime(const playerState_s *ps, const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_SetFuelTankTime
==============
*/
void BG_SetFuelTankTime(playerState_s *ps, const Weapon weapon, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_AddFuelTankTime
==============
*/
void BG_AddFuelTankTime(playerState_s *ps, const Weapon weapon, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetWeaponName
==============
*/
char *BG_GetWeaponName(const Weapon weapon, char *output, unsigned int maxStringLen)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_GetWeaponFireBarrelInfo
==============
*/
void BG_GetWeaponFireBarrelInfo(const WeaponDef *weapDef, int currentBarrel, int *startBarrel, int *numBarrels)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_WeaponNotUsedOnVehicle
==============
*/
BOOL BG_WeaponNotUsedOnVehicle(int eFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_WeaponUsedOnVehicle
==============
*/
BOOL BG_WeaponUsedOnVehicle(int eFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetViewmodelWeaponIndex
==============
*/
Weapon BG_GetViewmodelWeaponIndex(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
BG_TakePlayerWeapon
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
PM_UpdateAimDownSightFlag
==============
*/
void PM_UpdateAimDownSightFlag(pml_t *a1, pmove_t *a2, pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdateScopeZoom
==============
*/
void PM_UpdateScopeZoom(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdateSpinLerp
==============
*/
void PM_UpdateSpinLerp(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdateChargeShot
==============
*/
void PM_UpdateChargeShot(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ShouldFireChargeShotWeapon
==============
*/
bool ShouldFireChargeShotWeapon(playerState_s *ps, pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_HoldBreathFire
==============
*/
void PM_HoldBreathFire(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdateAirburstLase
==============
*/
void PM_UpdateAirburstLase(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UsingVehicleWeapon
==============
*/
BOOL BG_UsingVehicleWeapon(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_InteruptWeaponWithProneMove
==============
*/
int PM_InteruptWeaponWithProneMove(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_SetWeaponReloadAddAmmoDelay
==============
*/
void PM_SetWeaponReloadAddAmmoDelay(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_SetReloadingState
==============
*/
void PM_SetReloadingState(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_BeginWeaponReload
==============
*/
void PM_BeginWeaponReload(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_TakeClipOnlyWeaponIfEmpty
==============
*/
void BG_TakeClipOnlyWeaponIfEmpty(playerState_s *ps, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_FinishWeaponChange
==============
*/
void PM_Weapon_FinishWeaponChange(pmove_t *pm, pml_t *pml, int previousWeaponState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_AllowReload
==============
*/
int PM_Weapon_AllowReload(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_Weapon_FinishReloadStart
==============
*/
void PM_Weapon_FinishReloadStart(pmove_t *pm, int delayedAction)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_FinishReload
==============
*/
void PM_Weapon_FinishReload(pmove_t *pm, int delayedAction)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_CheckFuelTime
==============
*/
void PM_Weapon_CheckFuelTime(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_CheckForReload
==============
*/
void PM_Weapon_CheckForReload(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_AdjustAimSpreadScale
==============
*/
void PM_AdjustAimSpreadScale(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UpdatePendingTriggerPull
==============
*/
void UpdatePendingTriggerPull(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_BurstFireWaitingForTriggerRelease
==============
*/
bool PM_Weapon_BurstFireWaitingForTriggerRelease(pmove_t *pm, const WeaponDef *weapDef, const Weapon weapon, int weaponState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_Weapon_WeaponTimeAdjust
==============
*/
int PM_Weapon_WeaponTimeAdjust(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_Weapon_CheckForChangeWeapon
==============
*/
void PM_Weapon_CheckForChangeWeapon(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_ShouldBeFiring
==============
*/
int PM_Weapon_ShouldBeFiring(pmove_t *pm, int delayedAction, bool testOnly, bool runLeftGun)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_Weapon_CheckFiringAmmo
==============
*/
int PM_Weapon_CheckFiringAmmo(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_Weapon_IsHoldingGrenade
==============
*/
bool PM_Weapon_IsHoldingGrenade(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_AllowTacticalInsertion
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
PM_WeaponAllowPlant
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
PM_Weapon_FireWeapon
==============
*/
void PM_Weapon_FireWeapon(pmove_t *pm, pml_t *pml, int delayedAction)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_MeleeEnd
==============
*/
void PM_Weapon_MeleeEnd(playerState_s *ps, int leftGun)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_CheckForMelee
==============
*/
void PM_Weapon_CheckForMelee(pmove_t *pm, pml_t *pml, int delayedAction)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_RiotshieldStart
==============
*/
void PM_Weapon_RiotshieldStart(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_CheckForDeployRiotshield
==============
*/
void PM_Weapon_CheckForDeployRiotshield(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_OffHandPrepare
==============
*/
void PM_Weapon_OffHandPrepare(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_OffHandHold
==============
*/
void PM_Weapon_OffHandHold(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_OffHandStart
==============
*/
void PM_Weapon_OffHandStart(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_OffHand
==============
*/
void PM_Weapon_OffHand(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdateGrenadeThrow
==============
*/
bool PM_UpdateGrenadeThrow(playerState_s *ps, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_Weapon_CheckGrenadeHold
==============
*/
bool PM_Weapon_CheckGrenadeHold(pmove_t *pm, int delayedAction)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_Weapon_CheckForDetonation
==============
*/
void PM_Weapon_CheckForDetonation(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_CheckForGrenadeThrowCancel
==============
*/
void PM_Weapon_CheckForGrenadeThrowCancel(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_CheckForNightVision
==============
*/
void PM_Weapon_CheckForNightVision(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Crawl_Set_Direction
==============
*/
char Crawl_Set_Direction(pmove_t *pm, int delayedAction)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Crawl_State_Continue_Loop
==============
*/
void Crawl_State_Continue_Loop(pmove_t *pm, int delayedAction)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_CheckForContinuousFire
==============
*/
void PM_Weapon_CheckForContinuousFire(pmove_t *pm, int delayedAction)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_CheckForProne
==============
*/
void PM_Weapon_CheckForProne(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_CheckForAirburstMark
==============
*/
void PM_Weapon_CheckForAirburstMark(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_IncrementViewMovementIdleTime
==============
*/
void BG_IncrementViewMovementIdleTime(playerState_s *ps, float frametime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_IncrementWeaponMovementIdleTime
==============
*/
void BG_IncrementWeaponMovementIdleTime(const playerState_s *ps, float frametime, int *weaponIdleTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdateSwayPrediction
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
PM_Weapon_Turret
==============
*/
void PM_Weapon_Turret(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_WeaponFireRecoil
==============
*/
void BG_WeaponFireRecoil(const playerState_s *ps, vec2_t *recoilSpeed, vec3_t *kickAVel, int *previousRecoilTime, bool previouslyFiring, float *previousRecoilRatio, unsigned int *holdrand)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_AssertOffhandIndexOrNone
==============
*/
void BG_AssertOffhandIndexOrNone(const Weapon offHandWeapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_HoldWeapon
==============
*/
char BG_HoldWeapon(playerState_s *ps, const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetFirstAvailableOffhand
==============
*/
Weapon BG_GetFirstAvailableOffhand(const playerState_s *ps, int offhandSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
BG_GetSpreadForWeapon
==============
*/
void BG_GetSpreadForWeapon(const playerState_s *ps, const Weapon weapon, float *minSpread, float *maxSpread)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdateAimDownSightLerp
==============
*/
void PM_UpdateAimDownSightLerp(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_UpdateHoldBreath
==============
*/
void PM_UpdateHoldBreath(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_CheckForOffHand
==============
*/
void PM_Weapon_CheckForOffHand(pmove_t *pm, pml_t *pml)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sprint_State_Drop
==============
*/
void Sprint_State_Drop(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PM_Weapon_CheckForSprint
==============
*/
void PM_Weapon_CheckForSprint(pmove_t *pm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_CheckForUniversalActionDW
==============
*/
int BG_CheckForUniversalActionDW(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PM_Weapon
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

