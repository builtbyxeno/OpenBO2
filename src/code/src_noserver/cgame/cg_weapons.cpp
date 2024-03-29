#include "types.h"

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
float GetWeaponAnimTimeFrac(LocalClientNum_t localClientNum, const Weapon weapon, XAnim_s *anims, int animIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
StartWeaponAnim
==============
*/
void StartWeaponAnim(LocalClientNum_t localClientNum, const Weapon weapon, DObj *obj, int animIndex, float transitionTime, int newPlayerstate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
StartCameraAnim
==============
*/
double StartCameraAnim(float localClientNum, LocalClientNum_t a2, Weapon weapon, DObj *obj, int animIndex, float transitionTime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

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
void PlayIdleAnim(LocalClientNum_t localClientNum, const playerState_s *ps, ViewModelInfo *viewModelInfo, DObj *obj, Weapon weapon, float transitionTime, int newPlayerstate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PlayLeftIdleAnim
==============
*/
void PlayLeftIdleAnim(LocalClientNum_t localClientNum, const playerState_s *ps, ViewModelInfo *viewModelInfo, DObj *obj, Weapon weapon, float transitionTime, int newPlayerstate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PlayADSAnim
==============
*/
void PlayADSAnim(LocalClientNum_t localClientNum, float weaponPosFrac, Weapon weapon, DObj *obj, int animIndex, bool bIsAltScope)
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
void EnsureValidLeftAnim(LocalClientNum_t localClientNum, DObj *obj, ViewModelInfo *viewModelInfo, XAnimTree_s *pAnimTree, Weapon weapon, int newPlayerstate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
WeaponRunXModelAnims
==============
*/
void WeaponRunXModelAnims(char *a1, LocalClientNum_t localClientNum, const playerState_s *ps, ViewModelInfo *viewModelInfo, int newPlayerstate)
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
void CG_CreateWeaponViewModelXAnimDefs(const Weapon weapon, const Weapon lastWeaponAltModeSwitch, ViewModelInfo *viewModelInfo)
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
bool ShouldRebuildTree(LocalClientNum_t localClientNum, const ClientPlayerWeaponInfo *weapInfo, Weapon weapon, unsigned __int8 weaponModel, XModel *newHands)
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
void PlayChangedViewmodelAdsAnim(LocalClientNum_t localClientNum, const playerState_s *ps, Weapon weapon, ViewModelInfo *viewModelInfo)
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
void PlayNoteMappedSoundAliases(LocalClientNum_t localClientNum, const char *noteName, const WeaponDef *weapDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ProcessWeaponNoteTracks
==============
*/
void ProcessWeaponNoteTracks(LocalClientNum_t localClientNum, const playerState_s *predictedPlayerState, bool isViewArms)
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
void PlayWeaponFx(LocalClientNum_t localClientNum, int dobjHandle, const FxEffectDef *def, unsigned int flashTag, const vec3_t *offset, const vec3_t *offsetrot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
WeaponFlash
==============
*/
void WeaponFlash(LocalClientNum_t localClientNum, int dobjHandle, Weapon weapon, int bViewFlash, unsigned int flashTag)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PlayWeaponContinuousFireFx
==============
*/
void PlayWeaponContinuousFireFx(LocalClientNum_t localClientNum, int dobjHandle, Weapon weapon, unsigned int flashTag)
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
void ChargeShotUpdate(LocalClientNum_t localClientNum, const WeaponVariantDef *weapVariantDef, int chargeShotLevel)
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
void CG_UpdateMinigunTurretSounds(LocalClientNum_t localClientNum, cg_t *cgameGlob, centity_t *cent, const WeaponDef *weaponDef, float lastWeaponSpinSpeed, float minigunRotationSpeed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateJetgunSounds
==============
*/
void CG_UpdateJetgunSounds(LocalClientNum_t localClientNum, cg_t *cgameGlob, centity_t *cent, Weapon weapon, const WeaponDef *weaponDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateMinigunSounds
==============
*/
void CG_UpdateMinigunSounds(LocalClientNum_t localClientNum, cg_t *cgameGlob, centity_t *cent, Weapon weapon, const WeaponDef *weaponDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UpdateMinigunTag
==============
*/
void UpdateMinigunTag(cg_t *cgameGlob, centity_t *cent, const DObj *obj, unsigned __int16 name, int axis, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UpdateJetgunDialTags
==============
*/
void UpdateJetgunDialTags(cg_t *cgameGlob, const playerState_s *ps, centity_t *cent, const DObj *obj, unsigned __int16 lname, unsigned __int16 rname, int axis, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UpdateParalyzerDialTags
==============
*/
void UpdateParalyzerDialTags(cg_t *cgameGlob, const playerState_s *ps, centity_t *cent, const DObj *obj, unsigned __int16 name1, unsigned __int16 name2, unsigned __int16 name3, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateMinigunTags
==============
*/
void __cdecl CG_UpdateMinigunTags(cg_t *cgameGlob, centity_t *cent, const DObj *obj, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateJetgunTags
==============
*/
void __cdecl CG_UpdateJetgunTags(cg_t *cgameGlob, const playerState_s *ps, centity_t *cent, const DObj *obj, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateViewModelMinigun
==============
*/
void CG_UpdateViewModelMinigun(cg_t *cgameGlob, const playerState_s *ps, DObj *obj, const Weapon weapon, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateViewModelStackCounter
==============
*/
void CG_UpdateViewModelStackCounter(cg_t *cgameGlob, const playerState_s *ps, const DObj *obj, const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BulletTrace
==============
*/
bool BulletTrace(LocalClientNum_t localClientNum, const BulletFireParams *bp, const WeaponDef *weapDef, const centity_t *attacker, BulletTraceResults *br, int lastSurfaceType, bool simulated)
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
void CG_GuessSpreadForWeapon(LocalClientNum_t localClientNum, const centity_t *cent, const WeaponDef *weapDef, float *minSpread, float *maxSpread)
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
void CG_BulletEndpos(unsigned int *randSeed, const float spread, const vec3_t *start, vec3_t *end, vec3_t *dir, const vec3_t *forwardDir, const vec3_t *rightDir, const vec3_t *upDir, const float maxRange, Weapon weapon, int shotIndex, int maxShotIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetPlayerVehicleViewOrigin_Internal
==============
*/
char CG_GetPlayerVehicleViewOrigin_Internal(LocalClientNum_t localClientNum, const playerState_s *ps, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetPlayer3rdPersonVehicleViewOrigin
==============
*/
void CG_GetPlayer3rdPersonVehicleViewOrigin(LocalClientNum_t localClientNum, const playerState_s *ps, vec3_t *origin)
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
void CG_GetPlayerViewDirection(LocalClientNum_t localClientNum, const playerState_s *ps, vec3_t *forward, vec3_t *right, vec3_t *up)
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
bool UpdateViewmodelAttachments(LocalClientNum_t localClientNum, Weapon weapon, unsigned __int8 weaponModel, ClientPlayerWeaponInfo *weapInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NeedToRebuildViewmodel
==============
*/
bool NeedToRebuildViewmodel(LocalClientNum_t localClientNum, Weapon weapon, unsigned __int8 weaponModel, const ViewModelInfo *viewModelInfo, ClientPlayerWeaponInfo *weapInfo, bool inADS)
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
void CG_CalculateWeaponMovement_ClientSpecific(cg_t *cgameGlob, GfxScaledPlacement *placement, vec3_t *angles)
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
Weapon NextWeapInCycle(LocalClientNum_t localClientNum, const playerState_s *ps, weapInventoryType_t type, Weapon startWeapon, bool cycleForward, bool skipEmpties)
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
void CG_EjectWeaponBrass(LocalClientNum_t localClientNum, const entityState_s *ent, Weapon weapon, int tagName, bool leftHand, bool lastShot)
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
void CG_FireWeapon_VehicleFire(LocalClientNum_t localClientNum, centity_t *cent, const playerState_s *ps, const Weapon weapon, int event)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_FireWeapon_OriginAndDirection
==============
*/
void CG_FireWeapon_OriginAndDirection(LocalClientNum_t localClientNum, centity_t *cent, const unsigned __int16 tagName, bool useViewModelDObj, vec3_t *origin, vec3_t *direction)
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
void CG_FireWeapon_Rumble(LocalClientNum_t localClientNum, const entityState_s *ent, const Weapon weapon, bool isPlayerView, bool playerUsingVehicleWeapon)
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
void CG_SndUpdateAutoSim(float a1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_WeaponFireSingle
==============
*/
void CG_WeaponFireSingle(LocalClientNum_t localClientNum, SndEntHandle shooter, Weapon weapon, bool shooterIsPlayer, bool shooterIsLocalPlayer, bool leftGun, bool isLastShotInClip, const vec3_t *origin, const vec3_t *direction, unsigned int tagName, bool doubleTap, bool scriptedWeaponFire, bool firstShotOfBurst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_WeaponFireFake
==============
*/
void CG_WeaponFireFake(LocalClientNum_t localClientNum, SndEntHandle shooter, Weapon weapon, const vec3_t *origin, const vec3_t *direction, int count)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PullBackWeapon
==============
*/
void CG_PullBackWeapon(LocalClientNum_t localClientNum, const centity_t *cent, Weapon weapon, bool isPlayerView)
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
void CG_GetViewDirection(LocalClientNum_t localClientNum, int entityNum, vec3_t *forward, vec3_t *right, vec3_t *up)
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
void CG_ImpactEffectForWeapon(Weapon weapon, int surfType, int impactFlags, const FxEffectDef **outFx, unsigned int *outSnd)
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
bool CG_BulletHitDeployedDeployedRiotshield(LocalClientNum_t localClientNum, int targetEntityNum, const vec3_t *position, int surfType)
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
void CG_DeployRiotshieldEvent(char *a1, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CalcViewmodelHitPos
==============
*/
bool CalcViewmodelHitPos(LocalClientNum_t localClientNum, unsigned int eventParm, vec3_t *resultPos, vec3_t *resultNormal)
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
void CG_BulletHitClientShieldEvent(char *a1, LocalClientNum_t localClientNum, int sourceEntityNum, const Weapon weapon, int surfType, int event, unsigned int eventParm)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ExplosiveImpactOnShieldEvent
==============
*/
void CG_ExplosiveImpactOnShieldEvent(char *a1, LocalClientNum_t localClientNum)
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
int CG_AirburstLazeCancelledByMovement(float forwardMove, float rightMove, float pitchMove, float yawMove, float moveScale)
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
int AddViewmodelWeaponAttachments(const playerState_s *ps, Weapon weapon, const WeaponVariantDef *currentWeapVariantDef, DObjModel_s *dobjModels, int mdlIdx, const unsigned __int16 boneIndex, bool inADS, WeaponDobjInfo *weaponDobjInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ChangeViewmodelDobj
==============
*/
void ChangeViewmodelDobj(LocalClientNum_t localClientNum, const playerState_s *ps, Weapon weapon, unsigned __int8 weaponModel, XModel *newHands, XModel *newGoggles, XModel *newRocket, bool updateClientInfo, bool forceRebuildTree, bool inADS)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateHandViewmodel_Internal
==============
*/
void __cdecl CG_UpdateHandViewmodel_Internal(LocalClientNum_t localClientNum, Weapon weapon, XModel *handModel)
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
char CG_PrepFireParams(LocalClientNum_t localClientNum, centity_t *ent, const unsigned __int16 boneName, const playerState_s *ps, Weapon weapon, int event, bool isPlayer, BulletFireParams *bp, vec3_t *tracerStart, int *shotCount, float *range, orientation_t *orient, vec3_t *origin, float *aimSpreadAmount, int *ignoreEntity)
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
void CG_AddPlayerWeaponFx(centity_t *a1, LocalClientNum_t localClientNum, const playerState_s *ps, centity_t *cent, Weapon weapon, int bViewModel, int bDrawGun)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AddPlayerWeapon
==============
*/
void CG_AddPlayerWeapon(LocalClientNum_t localClientNum, const GfxScaledPlacement *placement, const playerState_s *ps, centity_t *cent, int bDrawGun)
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
char ToggleWeaponAltMode(LocalClientNum_t localClientNum, bool adsOnly)
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
void CG_FakeFireWeapon(LocalClientNum_t localClientNum, centity_t *cent, Weapon weapon, vec3_t *origin, int count)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_BulletHitEvent_Internal
==============
*/
void CG_BulletHitEvent_Internal(LocalClientNum_t localClientNum, int sourceEntityNum, int targetEntityNum, Weapon weapon, const vec3_t *startPos, const vec3_t *position, const vec3_t *normal, const vec3_t *seeThruDecalNormal, int surfType, int event, unsigned __int8 eventParam, int hitContents, unsigned __int8 boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_BulletHitEvent
==============
*/
void __cdecl CG_BulletHitEvent(LocalClientNum_t localClientNum, int sourceEntityNum, int targetEntityNum, Weapon weapon, const vec3_t *startPos, const vec3_t *position, const vec3_t *normal, const vec3_t *seeThruDecalNormal, int surfType, int event, const vec3_t *eventParam, int hitContents, int boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_BulletHitClientEvent
==============
*/
void CG_BulletHitClientEvent(LocalClientNum_t localClientNum, int sourceEntityNum, Weapon weapon, int hitEntityNum, const vec3_t *startPos, const vec3_t *position, int surfType, int event)
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
/*int CG_GetAirburstMarkDistance(LocalClientNum_t localClientNum, playerState_s *ps, bitarray<64> *buttons, unsigned int *outDistance, int lazeCancelled)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

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
void CG_SimulateBulletFire_Effect(LocalClientNum_t localClientNum, int sourceEntityNum, int targetEntityNum, Weapon weapon, const vec3_t *startPos, const vec3_t *position, const vec3_t *normal, const vec3_t *seeThruDecalNormal, int surfType, int event, unsigned __int8 eventParam, int hitContents, unsigned __int8 boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_WeaponBounceShot
==============
*/
void CG_WeaponBounceShot(LocalClientNum_t localClientNum, Weapon weapon, BulletFireParams *incomingbp, BulletTraceResults *br, centity_t *attacker, bool drawTracer)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SimulateBulletInternal
==============
*/
void CG_SimulateBulletInternal(BulletFireParams *bp, int *num_results)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SimulateBulletFire_Internal
==============
*/
void CG_SimulateBulletFire_Internal(BulletFireParams *bp, centity_t *attacker)
{
	UNIMPLEMENTED(__FUNCTION__);
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
void CG_SimulateBulletFire(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_NextWeapon_f
==============
*/
void CG_NextWeapon_f(cg_t *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PrevWeapon_f
==============
*/
void CG_PrevWeapon_f(cg_t *notthis)
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
void CG_FireWeapon(LocalClientNum_t localClientNum, centity_t *cent, int event, int eventParm, const unsigned __int16 tagName, Weapon weapon, const playerState_s *ps, centity_t *leftGun)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateViewWeaponAnim
==============
*/
void __cdecl CG_UpdateViewWeaponAnim(LocalClientNum_t localClientNum, int newPlayerstate)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_FireVehicleWeapon
==============
*/
void CG_FireVehicleWeapon(LocalClientNum_t localClientNum, centity_t *cent, int event, int eventParm, const unsigned __int16 tagName, Weapon weapon, const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
}

