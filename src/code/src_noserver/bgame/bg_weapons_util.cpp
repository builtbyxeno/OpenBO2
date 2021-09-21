#include "types.h"
#include "functions.h"

/*
==============
BG_WeaponNameToComponentList
==============
*/
void BG_WeaponNameToComponentList(const char *name, WeaponComponentList *componentList)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_WeaponNameToIdentifiedComponentList
==============
*/
void BG_WeaponNameToIdentifiedComponentList(const char *name, WeaponComponentList *componentList)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_WeaponComponentListIdentify
==============
*/
void BG_WeaponComponentListIdentify(WeaponComponentList *componentList)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_WeaponComponentListCountAttachments
==============
*/
int BG_WeaponComponentListCountAttachments(const WeaponComponentList *componentList)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_WeaponComponentListRemove
==============
*/
void BG_WeaponComponentListRemove(const WeaponComponentList *componentListIn, WeaponComponentList *componentListOut, bool lookingForAttachments)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_WeaponComponentListRemoveAllAttachments
==============
*/
void BG_WeaponComponentListRemoveAllAttachments(const WeaponComponentList *componentListIn, WeaponComponentList *componentListOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_WeaponComponentListNthAttachment
==============
*/
void BG_WeaponComponentListNthAttachment(const WeaponComponentList *componentListIn, int nth, WeaponComponentList *componentListOut)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_WeaponComponentListToName
==============
*/
void BG_WeaponComponentListToName(const WeaponComponentList *componentList, char *name, int size)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_WeaponComponentListToBaseName
==============
*/
void BG_WeaponComponentListToBaseName(const WeaponComponentList *componentList, char *name, int size)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_WeaponUsesBurstFire
==============
*/
bool BG_WeaponUsesBurstFire(weapFireType_t fireType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_WeaponUsesAttachments
==============
*/
BOOL BG_WeaponUsesAttachments(const WeaponVariantDef *weapVariantDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_WeaponHasAttachment
==============
*/
bool BG_WeaponHasAttachment(const Weapon weapon, eAttachment attachment)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetWeaponAttachments
==============
*/
void BG_GetWeaponAttachments(const Weapon weapon, WeaponAttachment *(*attachmentList)[3])
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetWeaponAttachmentUniques
==============
*/
void BG_GetWeaponAttachmentUniques(const Weapon weapon, WeaponAttachmentUnique *(*attachmentUniqueList)[3])
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetAttachmentUnique
==============
*/
WeaponAttachmentUnique *BG_GetAttachmentUnique(const Weapon weapon, eAttachment attachment)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_TracerType
==============
*/
TracerDef *BG_TracerType(const Weapon weapon, bool friendly)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_WeaponBulletFire_ExplodeOnImpact
==============
*/
bool BG_WeaponBulletFire_ExplodeOnImpact(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_PlayerPrimaryMeleeWeapon
==============
*/
Weapon BG_PlayerPrimaryMeleeWeapon(const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
BG_ShouldWeaponIgnoreAttachments
==============
*/
bool BG_ShouldWeaponIgnoreAttachments(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetAttachmentAnimationOverrideMask
==============
*/
void BG_GetAttachmentAnimationOverrideMask(const Weapon weapon, int (*overrideMask)[3])
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetAttachmentAnimationOverrideADSIndex
==============
*/
unsigned int BG_GetAttachmentAnimationOverrideADSIndex(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsAttachmentUniqueOverridingAnimation
==============
*/
BOOL BG_IsAttachmentUniqueOverridingAnimation(WeaponAttachmentUnique *attachment, int animType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetAttachmentOverrideChildIndex
==============
*/
int BG_GetAttachmentOverrideChildIndex(const Weapon weapon, const WeaponVariantDef *weapVariantDef, int attachmentIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetAttachmentAnimationOverride_Internal
==============
*/
const char *BG_GetAttachmentAnimationOverride_Internal(const Weapon weapon, const WeaponVariantDef *weapVariantDef, int animType, int attachmentIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_GetAttachmentAnimationFirstRaiseOverride
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
BG_EnsureUniqueAttachments
==============
*/
void BG_EnsureUniqueAttachments(Weapon *weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_IsDualWield
==============
*/
char BG_IsDualWield(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsSilenced
==============
*/
char BG_IsSilenced(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsDualMag
==============
*/
char BG_IsDualMag(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsLaserSight
==============
*/
char BG_IsLaserSight(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsInfraRed
==============
*/
char BG_IsInfraRed(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsTVGuided
==============
*/
bool BG_IsTVGuided(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsSharedAmmo
==============
*/
char BG_IsSharedAmmo(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsSegmentedReload
==============
*/
char BG_IsSegmentedReload(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsMMS
==============
*/
char BG_IsMMS(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetMMSMaxDist
==============
*/
double BG_GetMMSMaxDist(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetADSDofStartEnd
==============
*/
void BG_GetADSDofStartEnd(const Weapon weapon, float *start, float *end)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetOverriddenSound
==============
*/
unsigned int BG_GetOverriddenSound(const Weapon weapon, const WeaponVariantDef *weapVariantDef, eAttachmentOverrideSounds soundOverride, const char *defaultSound)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_FireSound
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
BG_FireSoundPlayer
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
BG_FireFinalKillcamSound
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
BG_FireFinalKillcamSoundPlayer
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
BG_FireSoundStart
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
BG_GetOverriddenEffect
==============
*/
const FxEffectDef *BG_GetOverriddenEffect(const Weapon weapon, const WeaponVariantDef *weapVariantDef, eAttachmentOverrideEffects effectOverride, const FxEffectDef *defaultEffect)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_ViewFlashEffect
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
BG_WorldFlashEffect
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
BG_GetHideTags
==============
*/
void BG_GetHideTags(const Weapon weapon, unsigned __int16 *hideTags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetADSZoomFOV
==============
*/
void BG_GetADSZoomFOV(const Weapon weapon, float *adsZoomFov1, float *adsZoomFov2, float *adsZoomFov3)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetADSZoomInFrac
==============
*/
double BG_GetADSZoomInFrac(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetADSZoomOutFrac
==============
*/
double BG_GetADSZoomOutFrac(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetSwaySettings
==============
*/
void BG_GetSwaySettings(const Weapon weapon, float *maxAngle, float *lerpSpeed, float *pitchScale, float *yawScale, float *horizScale, float *vertScale)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetADSSwaySettings
==============
*/
void BG_GetADSSwaySettings(const Weapon weapon, float *maxAngle, float *lerpSpeed, float *pitchScale, float *yawScale, float *horizScale, float *vertScale)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetFireTime
==============
*/
int BG_GetFireTime(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetReloadTime
==============
*/
int BG_GetReloadTime(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetReloadEmptyTime
==============
*/
int BG_GetReloadEmptyTime(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetReloadAddTime
==============
*/
int BG_GetReloadAddTime(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetReloadQuickTime
==============
*/
int BG_GetReloadQuickTime(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetReloadQuickEmptyTime
==============
*/
int BG_GetReloadQuickEmptyTime(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetReloadQuickAddTime
==============
*/
int BG_GetReloadQuickAddTime(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetAltWeapon
==============
*/
Weapon BG_GetAltWeapon(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
BG_GetDualWieldWeapon
==============
*/
Weapon BG_GetDualWieldWeapon(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
BG_IsAltWeaponAdsOnly
==============
*/
char BG_IsAltWeaponAdsOnly(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsAltWeaponDisableSwitching
==============
*/
char BG_IsAltWeaponDisableSwitching(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetAltScopeADSTransInTime
==============
*/
double BG_GetAltScopeADSTransInTime(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetAltScopeADSTransOutTime
==============
*/
double BG_GetAltScopeADSTransOutTime(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetADSTransTimeScales
==============
*/
void BG_GetADSTransTimeScales(const Weapon weapon, float *adsTransInTimeScale, float *adsTransOutTimeScale)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetADSRecoilReduction
==============
*/
void BG_GetADSRecoilReduction(const Weapon weapon, float *rate, float *limit)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetFireType
==============
*/
weapFireType_t BG_GetFireType(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	weapFireType_t tmp;
	return tmp;
}

/*
==============
BG_GetForceBounce
==============
*/
bool BG_GetForceBounce(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetStackFireAccuracyDecay
==============
*/
double BG_GetStackFireAccuracyDecay(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetStackFireSpread
==============
*/
double BG_GetStackFireSpread(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetPenetrateType
==============
*/
PenetrateType BG_GetPenetrateType(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	PenetrateType tmp;
	return tmp;
}

/*
==============
BG_GetPerks
==============
*/
void BG_GetPerks(const Weapon weapon, unsigned int *perks)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetADSViewKickCenterSpeed
==============
*/
double BG_GetADSViewKickCenterSpeed(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetADSIdleAmount
==============
*/
double BG_GetADSIdleAmount(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetDamageRangeScale
==============
*/
double BG_GetDamageRangeScale(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetADSMoveSpeedScale
==============
*/
double BG_GetADSMoveSpeedScale(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetFirstRaiseTime
==============
*/
int BG_GetFirstRaiseTime(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetAltRaiseTime
==============
*/
int BG_GetAltRaiseTime(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetAltDropTime
==============
*/
int BG_GetAltDropTime(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetReloadAmmoAdd
==============
*/
int BG_GetReloadAmmoAdd(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetReloadStartAdd
==============
*/
int BG_GetReloadStartAdd(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetHipSpreadScale
==============
*/
void BG_GetHipSpreadScale(const Weapon weapon, float *min, float *max)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetHipIdleAmount
==============
*/
double BG_GetHipIdleAmount(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetStandMoveAndRotation
==============
*/
void BG_GetStandMoveAndRotation(const Weapon weapon, vec3_t *move, vec3_t *rot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetStrafeRotation
==============
*/
void BG_GetStrafeRotation(const Weapon weapon, vec3_t *rot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetOverlayMaterial
==============
*/
Material *BG_GetOverlayMaterial(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_GetOverlayMaterialLowRes
==============
*/
Material *BG_GetOverlayMaterialLowRes(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_GetOverlayReticle
==============
*/
weapOverlayReticle_t BG_GetOverlayReticle(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	weapOverlayReticle_t tmp;
	return tmp;
}

/*
==============
BG_GetDpadIcon
==============
*/
Material *BG_GetDpadIcon(const Weapon weapon, weaponIconRatioType_t *ratio)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_GetWeaponHitLocationMultiplier
==============
*/
double BG_GetWeaponHitLocationMultiplier(const Weapon weapon, hitLocation_t hitLoc)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsBaseWeaponAttachmentDisabled
==============
*/
bool BG_IsBaseWeaponAttachmentDisabled(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_IsBaseWeaponClipAttachmentDisabled
==============
*/
bool BG_IsBaseWeaponClipAttachmentDisabled(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetClipWorldModel
==============
*/
XModel *BG_GetClipWorldModel(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_IsOverridingBaseWeaponAttachmentOffsets
==============
*/
eAttachment BG_IsOverridingBaseWeaponAttachmentOffsets(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	eAttachment tmp;
	return tmp;
}

/*
==============
BG_GetViewAttachmentOffsetsOverride
==============
*/
void BG_GetViewAttachmentOffsetsOverride(const Weapon weapon, eAttachment attachment, vec3_t *offset)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetWorldAttachmentOffsetsOverride
==============
*/
void BG_GetWorldAttachmentOffsetsOverride(const Weapon weapon, eAttachment attachment, vec3_t *offset)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetLeftHandIK
==============
*/
void BG_GetLeftHandIK(const Weapon weapon, const float **offset, const float **rotation)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetLeftHandProneIK
==============
*/
void BG_GetLeftHandProneIK(const Weapon weapon, const float **offset, const float **rotation)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetWeaponDamageForRange
==============
*/
int BG_GetWeaponDamageForRange(const Weapon weapon, const vec3_t *start, const vec3_t *hitPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_ShotLimitReached
==============
*/
bool BG_ShotLimitReached(const Weapon weapon, int weaponShotCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetAttachmentAnimationOverride
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
BG_IsLeftHandWeapon
==============
*/
char BG_IsLeftHandWeapon(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_WeaponComponentListSort
==============
*/
void BG_WeaponComponentListSort(const char *originalName, WeaponComponentList *componentList, char *outputName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

