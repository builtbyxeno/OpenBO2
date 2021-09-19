#include "types.h"
#include "functions.h"

/*
==============
CG_RegisterWeaponDvars
==============
*/
void CG_RegisterWeaponDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetWeaponAnimRate
==============
*/
float GetWeaponAnimRate(LocalClientNum_t localClientNum, const Weapon weapon, XAnim_s *anims, int animIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetWeaponAnimTimeFrac
==============
*/
float GetWeaponAnimTimeFrac(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
StartWeaponAnim
==============
*/
void StartWeaponAnim(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
StartCameraAnim
==============
*/
/*double StartCameraAnim@<st0>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
StopCameraAnim
==============
*/
void StopCameraAnim(DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PlayIdleAnim
==============
*/
void PlayIdleAnim(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PlayLeftIdleAnim
==============
*/
void PlayLeftIdleAnim(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PlayADSAnim
==============
*/
void PlayADSAnim(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_JavelinADS
==============
*/
bool CG_JavelinADS(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_UICheckWeapLockBlink
==============
*/
bool CG_UICheckWeapLockBlink(LocalClientNum_t localClientNum, float blinkPerSec)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_UICheckWeapLockAttackTop
==============
*/
bool CG_UICheckWeapLockAttackTop(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_UICheckWeapLockAttackDirect
==============
*/
bool CG_UICheckWeapLockAttackDirect(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CheckForValidAnimIDDW
==============
*/
int CheckForValidAnimIDDW(int animID)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
EnsureValidLeftAnim
==============
*/
void EnsureValidLeftAnim(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
WeaponRunXModelAnims
==============
*/
void WeaponRunXModelAnims(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ResetWeaponAnimTrees
==============
*/
void CG_ResetWeaponAnimTrees(LocalClientNum_t localClientNum, const playerState_s *ps, int newPlayerstate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_WeaponDObjHandle
==============
*/
int CG_WeaponDObjHandle(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CreateWeaponViewModelXAnim
==============
*/
void CG_CreateWeaponViewModelXAnim(const char **animArray, const char **dwAnimArray, XAnim_s *pAnims)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RemoveAltAttachmentFromWeapon
==============
*/
Weapon RemoveAltAttachmentFromWeapon(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
CG_CreateWeaponViewModelXAnimDefs
==============
*/
void CG_CreateWeaponViewModelXAnimDefs(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetWeaponHidePartBits
==============
*/
void CG_SetWeaponHidePartBits(const Weapon weapon, ViewModelInfo *viewModelInfo, DObj *obj, int modelNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_FreeWeapons
==============
*/
void CG_FreeWeapons(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RegisterWeapon
==============
*/
void CG_RegisterWeapon(LocalClientNum_t localClientNum, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ShouldRebuildTree
==============
*/
bool ShouldRebuildTree(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ShouldRebuildAnims
==============
*/
char ShouldRebuildAnims(LocalClientNum_t localClientNum, const ViewModelInfo *viewModelInfo, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PlayViewmodelAdsAnim
==============
*/
void PlayViewmodelAdsAnim(ViewModelInfo *viewModelInfo, Weapon weapon, int animIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PlayChangedViewmodelAdsAnim
==============
*/
void PlayChangedViewmodelAdsAnim(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ViewmodelRocketShouldBeAttached
==============
*/
bool ViewmodelRocketShouldBeAttached(LocalClientNum_t localClientNum, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetHandViewmodel
==============
*/
XModel *CG_GetHandViewmodel(cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
PlayNoteMappedSoundAliases
==============
*/
void PlayNoteMappedSoundAliases(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ProcessWeaponNoteTracks
==============
*/
void ProcessWeaponNoteTracks(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RegisterItems
==============
*/
void CG_RegisterItems(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CalculateWeaponPostion_PositionToADS
==============
*/
void CalculateWeaponPostion_PositionToADS(cg_t *cgameGlob, playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PlayWeaponFx
==============
*/
void PlayWeaponFx(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
WeaponFlash
==============
*/
void WeaponFlash(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PlayWeaponContinuousFireFx
==============
*/
void PlayWeaponContinuousFireFx(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_HoldBreathInit
==============
*/
void CG_HoldBreathInit(cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HoldBreathUpdate
==============
*/
void HoldBreathUpdate(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ChargeShotUpdate
==============
*/
void ChargeShotUpdate(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateViewModelPose
==============
*/
void CG_UpdateViewModelPose(const DObj *obj, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateMinigunTurretSounds
==============
*/
void CG_UpdateMinigunTurretSounds(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateJetgunSounds
==============
*/
void CG_UpdateJetgunSounds(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateMinigunSounds
==============
*/
void CG_UpdateMinigunSounds(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UpdateMinigunTag
==============
*/
void UpdateMinigunTag(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UpdateJetgunDialTags
==============
*/
void UpdateJetgunDialTags(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UpdateParalyzerDialTags
==============
*/
void UpdateParalyzerDialTags(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateMinigunTags
==============
*/
void CG_UpdateMinigunTags(cg_t *cgameGlob, centity_t *cent, const DObj *obj, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateJetgunTags
==============
*/
void CG_UpdateJetgunTags(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateViewModelMinigun
==============
*/
void CG_UpdateViewModelMinigun(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateViewModelStackCounter
==============
*/
void CG_UpdateViewModelStackCounter(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BulletTrace
==============
*/
bool BulletTrace(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IsEntityNotDoingClientSideBullets
==============
*/
bool IsEntityNotDoingClientSideBullets(LocalClientNum_t localClientNum, int entityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_ShouldSimulateBulletFire
==============
*/
bool CG_ShouldSimulateBulletFire(LocalClientNum_t localClientNum, BulletFireParams *bp)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_IsPlayerCrouching
==============
*/
bool CG_IsPlayerCrouching(clientInfo_t *ci, const centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_IsPlayerADS
==============
*/
bool CG_IsPlayerADS(clientInfo_t *ci, const centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GuessSpreadForWeapon
==============
*/
void CG_GuessSpreadForWeapon(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RandomBulletDir
==============
*/
void RandomBulletDir(unsigned int *randSeed, float *x, float *y)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_BulletEndpos
==============
*/
void CG_BulletEndpos(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetPlayerVehicleViewOrigin_Internal
==============
*/
char CG_GetPlayerVehicleViewOrigin_Internal(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetPlayer3rdPersonVehicleViewOrigin
==============
*/
void CG_GetPlayer3rdPersonVehicleViewOrigin(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetPlayerVehicleViewOrigin
==============
*/
char CG_GetPlayerVehicleViewOrigin(LocalClientNum_t localClientNum, const playerState_s *ps, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetPlayerViewDirection
==============
*/
void CG_GetPlayerViewDirection(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ShowWeaponFx
==============
*/
bool CG_ShowWeaponFx(const cg_t *cgameGlob, centity_t *cent, int bViewModel)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Hack_TouchPlayerWeaponBones
==============
*/
void CG_Hack_TouchPlayerWeaponBones(LocalClientNum_t localClientNum, const cg_t *cgameGlob, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetSonarAttachmentShaderConstants
==============
*/
void CG_SetSonarAttachmentShaderConstants(LocalClientNum_t localClientNum, ShaderConstantSet *constantSet)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Weapon_DrawAxisOrigin
==============
*/
void Weapon_DrawAxisOrigin(orientation_t orient, float colorScale)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Weapon_DrawTagAxis
==============
*/
void Weapon_DrawTagAxis(LocalClientNum_t localClientNum, int entityNum, Weapon weapon, int bViewModel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Anim_DrawTags
==============
*/
void Anim_DrawTags(LocalClientNum_t localClientNum, int entityNum, Weapon weapon, cpose_t *pose, int flags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UpdateViewmodelAttachments
==============
*/
bool UpdateViewmodelAttachments(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NeedToRebuildViewmodel
==============
*/
bool NeedToRebuildViewmodel(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CalculateWeaponMovement_Landing
==============
*/
void CG_CalculateWeaponMovement_Landing(const cg_t *cgameGlob, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalculateWeaponMovement_SaveOrigin
==============
*/
void CG_CalculateWeaponMovement_SaveOrigin(cg_t *cgameGlob, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalculateWeaponMovement_Debug
==============
*/
void CG_CalculateWeaponMovement_Debug(const cg_t *cgameGlob, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalculateWeaponMovement_SaveAngles
==============
*/
void CG_CalculateWeaponMovement_SaveAngles(cg_t *cgameGlob, vec3_t *angles, GfxScaledPlacement *placement)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalculateWeaponMovement_ClientSpecific
==============
*/
void CG_CalculateWeaponMovement_ClientSpecific(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_BuildWeaponState
==============
*/
void CG_BuildWeaponState(cg_t *cgameGlob, weaponState_t *ws)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SaveWeaponState
==============
*/
void CG_SaveWeaponState(const weaponState_t *ws, cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NextWeapInCycle
==============
*/
Weapon NextWeapInCycle(
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
CG_GetLastWeaponForAlt
==============
*/
Weapon CG_GetLastWeaponForAlt(const cg_t *cgameGlob, const playerState_s *ps, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
CG_GetAltWeapon
==============
*/
Weapon CG_GetAltWeapon(const cg_t *cgameGlob, const playerState_s *ps, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
CG_AltWeaponToggleIndex
==============
*/
Weapon CG_AltWeaponToggleIndex(LocalClientNum_t localClientNum, const cg_t *cgameGlob, Weapon *primaryWeapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
ShouldToggleWeaponAltMode
==============
*/
bool ShouldToggleWeaponAltMode(LocalClientNum_t localClientNum, const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetBrassTagForEvent
==============
*/
int CG_GetBrassTagForEvent(int event)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_EjectWeaponBrass
==============
*/
void CG_EjectWeaponBrass(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_VehicleJolt
==============
*/
void CG_VehicleJolt(centity_t *cent, vec3_t *origin, vec3_t *dir)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_VehicleFire
==============
*/
void CG_VehicleFire(centity_t *cent, const unsigned __int16 tagName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_FireWeapon_LocalPlayerUsingVehicleWeapon
==============
*/
bool CG_FireWeapon_LocalPlayerUsingVehicleWeapon(centity_t *cent, const playerState_s *ps, int event)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_FireWeapon_VehicleFire
==============
*/
void CG_FireWeapon_VehicleFire(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_FireWeapon_OriginAndDirection
==============
*/
void CG_FireWeapon_OriginAndDirection(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SetWeaponFxFlags
==============
*/
void SetWeaponFxFlags(centity_t *cent, bool leftGun, bool shellEject, bool lastShot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_FireWeapon_Rumble
==============
*/
void CG_FireWeapon_Rumble(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_HideVisibleAmmo
==============
*/
void CG_HideVisibleAmmo(LocalClientNum_t localClientNum, centity_t *cent, const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SndWeaponFakeFire
==============
*/
void CG_SndWeaponFakeFire(snd_weapon_shot *shot, const WeaponDef *weaponDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SndWeaponFire
==============
*/
void CG_SndWeaponFire(snd_weapon_shot *shot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SndAutoSimReset
==============
*/
void CG_SndAutoSimReset()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SndPingAutoSim
==============
*/
void CG_SndPingAutoSim(snd_weapon_shot *shot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SndKillAutoSimEnt
==============
*/
void CG_SndKillAutoSimEnt(SndEntHandle ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SndUpdateAutoSim
==============
*/
/*void CG_SndUpdateAutoSim(float a1@<ebx>)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
CG_WeaponFireSingle
==============
*/
void CG_WeaponFireSingle(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_WeaponFireFake
==============
*/
void CG_WeaponFireFake(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PullBackWeapon
==============
*/
void CG_PullBackWeapon(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetLocalClientGlobalsForEnt
==============
*/
cg_t *CG_GetLocalClientGlobalsForEnt(LocalClientNum_t localClientNum, int entityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_GetViewDirection
==============
*/
void CG_GetViewDirection(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalcEyePoint
==============
*/
void CG_CalcEyePoint(LocalClientNum_t localClientNum, int entityNum, vec3_t *eyePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CalcMuzzlePoint
==============
*/
void CalcMuzzlePoint(LocalClientNum_t localClientNum, int entityNum, vec3_t *muzzle, unsigned int flashTag)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RandomEffectAxis
==============
*/
void CG_RandomEffectAxis(const vec3_t *forward, vec3_t *left, vec3_t *up)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ImpactEffectForWeapon
==============
*/
void CG_ImpactEffectForWeapon(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_BulletHitEvent_FindPlayerCorpse
==============
*/
centity_t *CG_BulletHitEvent_FindPlayerCorpse(LocalClientNum_t localClientNum, centity_t *player)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_BulletHitDeployedDeployedRiotshield
==============
*/
bool CG_BulletHitDeployedDeployedRiotshield(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DogBloodEvent
==============
*/
void CG_DogBloodEvent(LocalClientNum_t localClientNum, int entnum, vec3_t *position, int boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DeployRiotshieldEvent
==============
*/
void CG_DeployRiotshieldEvent(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CalcViewmodelHitPos
==============
*/
bool CalcViewmodelHitPos(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_ViewmodelShieldHitStore
==============
*/
void CG_ViewmodelShieldHitStore(LocalClientNum_t localClientNum, unsigned int eventParm, bool damaged)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ViewmodelShieldHitsProcess
==============
*/
void CG_ViewmodelShieldHitsProcess(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_BulletHitClientShieldEvent
==============
*/
void CG_BulletHitClientShieldEvent(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ExplosiveImpactOnShieldEvent
==============
*/
void CG_ExplosiveImpactOnShieldEvent(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ExplosiveSplashOnShieldEvent
==============
*/
void CG_ExplosiveSplashOnShieldEvent(LocalClientNum_t localClientNum, int originalDamage)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_MeleeBloodEvent
==============
*/
void CG_MeleeBloodEvent(LocalClientNum_t localClientNum, const centity_t *cent, int eventParm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_MeleeSwipeEvent
==============
*/
void CG_MeleeSwipeEvent(LocalClientNum_t localClientNum, const centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetBaseWeaponForStats
==============
*/
void CG_SetBaseWeaponForStats(const WeaponVariantDef *weapVariantDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetupWeaponDef
==============
*/
void CG_SetupWeaponDef()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ValidLatestPrimaryWeapon
==============
*/
Weapon ValidLatestPrimaryWeapon(const cg_t *cgameGlob, const playerState_s *ps, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
CG_ClearLastWeaponForAlt
==============
*/
char CG_ClearLastWeaponForAlt(cg_t *cgameGlob, const playerState_s *ps, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_SetLastWeaponForAlt
==============
*/
bool CG_SetLastWeaponForAlt(cg_t *cgameGlob, const playerState_s *ps, Weapon altWeapon, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_UpdateLastWeaponForAlt
==============
*/
bool CG_UpdateLastWeaponForAlt(cg_t *cgameGlob, const playerState_s *ps, Weapon oldweapon, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_SelectWeaponIndex
==============
*/
void CG_SelectWeaponIndex(LocalClientNum_t localClientNum, const playerState_s *ps, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SelectWeaponIndex
==============
*/
void CG_SelectWeaponIndex(LocalClientNum_t localClientNum, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DisplayViewmodelAnim
==============
*/
void CG_DisplayViewmodelAnim(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetPlayerTurretWeapon
==============
*/
Weapon CG_GetPlayerTurretWeapon(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
CG_GetPlayerVehicleWeapon
==============
*/
Weapon CG_GetPlayerVehicleWeapon(const playerState_s *ps, const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
CG_GetPlayerMeleeWeapon
==============
*/
Weapon CG_GetPlayerMeleeWeapon(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
CG_GetPlayerWeapon
==============
*/
Weapon CG_GetPlayerWeapon(const playerState_s *ps, const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
CG_GetClientWeapon
==============
*/
Weapon CG_GetClientWeapon(ClientNum_t clientNum, const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
CG_PlayerUsingScopedTurret
==============
*/
bool CG_PlayerUsingScopedTurret(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_PlayerUsingMouseToControlVehicle
==============
*/
bool CG_PlayerUsingMouseToControlVehicle(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_PlayerUsingHandbrakeInVehicle
==============
*/
bool CG_PlayerUsingHandbrakeInVehicle(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetPlayerVehicleHandbrakeTurnSpeedValue
==============
*/
float CG_GetPlayerVehicleHandbrakeTurnSpeedValue(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_ApplyWeaponTurnRateCap
==============
*/
void CG_ApplyWeaponTurnRateCap(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_MolotovFloat
==============
*/
void CG_MolotovFloat(LocalClientNum_t localClientNum, const centity_t *cent, const entityState_s *es)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetWeaponOverlay
==============
*/
Material *CG_GetWeaponOverlay(LocalClientNum_t localClientNum, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_IsInGuidedMissile
==============
*/
BOOL CG_IsInGuidedMissile(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_IsInRemoteKillstreakStatic
==============
*/
int CG_IsInRemoteKillstreakStatic(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_AirburstLazeCancelledByMovement
==============
*/
int CG_AirburstLazeCancelledByMovement(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CheckForAirburstReset
==============
*/
void CG_CheckForAirburstReset(cg_t *cgameGlob, const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_IsClientControlledMissile
==============
*/
BOOL CG_IsClientControlledMissile(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_IsAirborneKillstreak
==============
*/
BOOL CG_IsAirborneKillstreak(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetWeaponForName_Internal
==============
*/
Weapon CG_GetWeaponForName_Internal(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
CG_GetWeaponForName
==============
*/
Weapon CG_GetWeaponForName(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
CG_AllocDroppedWeaponDobjInfo
==============
*/
DroppedWeaponDobjInfo *CG_AllocDroppedWeaponDobjInfo(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_FreeDroppedWeaponDobjInfo
==============
*/
void CG_FreeDroppedWeaponDobjInfo(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AddViewmodelWeaponAttachments
==============
*/
int AddViewmodelWeaponAttachments(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ChangeViewmodelDobj
==============
*/
void ChangeViewmodelDobj(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateHandViewmodel_Internal
==============
*/
void CG_UpdateHandViewmodel_Internal(LocalClientNum_t localClientNum, Weapon weapon, XModel *handModel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateWeaponAndHandViewmodels
==============
*/
void CG_UpdateWeaponAndHandViewmodels(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateMinigunSpin
==============
*/
void CG_UpdateMinigunSpin(LocalClientNum_t localClientNum, cg_t *cgameGlob, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetPlayerViewOrigin
==============
*/
char CG_GetPlayerViewOrigin(LocalClientNum_t localClientNum, const playerState_s *ps, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_PrepFireParams
==============
*/
char CG_PrepFireParams(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetWeaponDefBasedOnNumberOfBullets
==============
*/
Weapon CG_GetWeaponDefBasedOnNumberOfBullets(const cg_t *cgameGlob, int numBulletsQueued, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
CG_AddPlayerWeaponFx
==============
*/
void CG_AddPlayerWeaponFx(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AddPlayerWeapon
==============
*/
void CG_AddPlayerWeapon(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AddViewWeapon
==============
*/
void CG_AddViewWeapon(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CancelOffhand
==============
*/
bool CG_CancelOffhand(cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
WeaponCycleAllowed
==============
*/
bool WeaponCycleAllowed(cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VerifyPlayerAltModeWeapon
==============
*/
char VerifyPlayerAltModeWeapon(LocalClientNum_t localClientNum, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_SwitchToLastValidPrimary
==============
*/
void CG_SwitchToLastValidPrimary(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CycleWeapPrimary
==============
*/
char CycleWeapPrimary(LocalClientNum_t localClientNum, int cycleForward, int bIgnoreEmpty)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CycleWeapon
==============
*/
void CG_CycleWeapon(LocalClientNum_t localClientNum, int cycleForward)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ToggleWeaponAltMode
==============
*/
bool ToggleWeaponAltMode(LocalClientNum_t localClientNum, bool adsOnly)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_AdsAltWeaponDown
==============
*/
void CG_AdsAltWeaponDown(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ActionSlot_SelectWeapon
==============
*/
char CG_ActionSlot_SelectWeapon(const LocalClientNum_t localClientNum, Weapon weapon, bool checkMomentumCost)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_FakeFireWeapon
==============
*/
void CG_FakeFireWeapon(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_BulletHitEvent_Internal
==============
*/
void CG_BulletHitEvent_Internal(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_BulletHitEvent
==============
*/
void CG_BulletHitEvent(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_BulletHitClientEvent
==============
*/
void CG_BulletHitClientEvent(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ScopeIsOverlayed
==============
*/
char CG_ScopeIsOverlayed(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetAirburstMarkDistance
==============
*/
int CG_GetAirburstMarkDistance(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_WeaponMyChanges
==============
*/
void CG_WeaponMyChanges()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SimulateBulletFire_Effect
==============
*/
void CG_SimulateBulletFire_Effect(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_WeaponBounceShot
==============
*/
void CG_WeaponBounceShot(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SimulateBulletInternal
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_SimulateBulletFire_Internal
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_SimulateBullet
==============
*/
void CG_SimulateBullet(bullet_hit_info_t *results, const int max_results, int *num_results)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SimulateBulletFire
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_NextWeapon_f
==============
*/
void __thiscall CG_NextWeapon_f(cg_t *this)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PrevWeapon_f
==============
*/
void __thiscall CG_PrevWeapon_f(cg_t *this)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_OutOfAmmoChange
==============
*/
void CG_OutOfAmmoChange(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ActionSlotUsageAllowed
==============
*/
bool ActionSlotUsageAllowed(const cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_ActionSlotDown
==============
*/
void CG_ActionSlotDown(LocalClientNum_t localClientNum, int slot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ActionSlotUp
==============
*/
void CG_ActionSlotUp(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SelectInventoryWeapon
==============
*/
char CG_SelectInventoryWeapon(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TakeClipOnlyWeaponIfEmpty
==============
*/
void TakeClipOnlyWeaponIfEmpty(LocalClientNum_t localClientNum, playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_FireWeapon
==============
*/
void CG_FireWeapon(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateViewWeaponAnim
==============
*/
void CG_UpdateViewWeaponAnim(LocalClientNum_t localClientNum, int newPlayerstate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_FireVehicleWeapon
==============
*/
void CG_FireVehicleWeapon(
{
	UNIMPLEMENTED(__FUNCTION__);
}

