#include "types.h"
#include "functions.h"

/*
==============
BG_UnlockablesGetLoadoutSlotName
==============
*/
const char *BG_UnlockablesGetLoadoutSlotName(loadoutSlot_t loadoutSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
FindEntryInList
==============
*/
int FindEntryInList(const char *stringEntry, const char **textArray, int numEntries)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesCompareItemsBySortKey
==============
*/
int BG_UnlockablesCompareItemsBySortKey(const void *arg0, const void *arg1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsItemAttachmentValid
==============
*/
int BG_UnlockablesIsItemAttachmentValid(itemInfo_t *itemInfo, eAttachment attachment)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsGrenadeOrEquipment
==============
*/
bool BG_UnlockablesIsGrenadeOrEquipment(itemInfo_t *itemInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsPrimaryOrSecondary
==============
*/
bool BG_UnlockablesIsPrimaryOrSecondary(itemInfo_t *itemInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesParseDefaultClassesForItem
==============
*/
void BG_UnlockablesParseDefaultClassesForItem(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesParseAttachmentsForItem
==============
*/
void BG_UnlockablesParseAttachmentsForItem(itemInfo_t *itemInfo, const char *attachmentList)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesGetItemInfo
==============
*/
itemInfo_t *BG_UnlockablesGetItemInfo(int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_GetSpecialtyCollectionCount
==============
*/
int BG_GetSpecialtyCollectionCount()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_SpecialtyCollectionLoaoutSlot
==============
*/
loadoutSlot_t BG_SpecialtyCollectionLoaoutSlot(int collectionIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	loadoutSlot_t tmp;
	return tmp;
}

/*
==============
BG_HasSpecialtyCollection
==============
*/
bool BG_HasSpecialtyCollection(int collectionIndex, unsigned int *perks)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetItemGroupFromName
==============
*/
/*int BG_UnlockablesGetItemGroupFromName@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
BG_UnlockablesGetClassIndexFromName
==============
*/
/*int BG_UnlockablesGetClassIndexFromName@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
BG_UnlockablesGetBonusCardNameHashFromIndex
==============
*/
int BG_UnlockablesGetBonusCardNameHashFromIndex(bonusCards_t bonusCard)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetBonusCardIndexFromNameHash
==============
*/
bonusCards_t BG_UnlockablesGetBonusCardIndexFromNameHash(int bonusCardNameHash)
{
	UNIMPLEMENTED(__FUNCTION__);
	bonusCards_t tmp;
	return tmp;
}

/*
==============
BG_UnlockablesBuildBonusCardNameHash
==============
*/
void BG_UnlockablesBuildBonusCardNameHash()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesGetNameForClass
==============
*/
const char *BG_UnlockablesGetNameForClass(loadoutClass_t customClass)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UnlockablesGetItemGroupName
==============
*/
const char *BG_UnlockablesGetItemGroupName(itemGroup_t groupIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UnlockablesCompareGunLevelRows
==============
*/
int BG_UnlockablesCompareGunLevelRows(const void *a, const void *b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetGunLevelRowForChallenge
==============
*/
gunLevelRow_t *BG_UnlockablesGetGunLevelRowForChallenge(int itemIndex, int currentXP)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UnlockablesHashItemGroupNames
==============
*/
void BG_UnlockablesHashItemGroupNames()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesAllItemsFree
==============
*/
bool BG_UnlockablesAllItemsFree()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesAllItemsUnlocked
==============
*/
bool BG_UnlockablesAllItemsUnlocked()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesBuildClanTagFeatureRows
==============
*/
char __thiscall BG_UnlockablesBuildClanTagFeatureRows(const StringTable *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetEquippedClanTagFeatureIndex
==============
*/
unsigned int BG_UnlockablesGetEquippedClanTagFeatureIndex(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetClanTagFeature
==============
*/
const GfxViewParms *BG_UnlockablesGetClanTagFeature(unsigned int index, clanTagFeatureColumn_t column)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UnlockablesGetClanTagFeaturePLvlUnlock
==============
*/
int BG_UnlockablesGetClanTagFeaturePLvlUnlock(unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsClanTagFeatureLocked
==============
*/
bool BG_UnlockablesIsClanTagFeatureLocked(const ControllerIndex_t controllerIndex, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsClanTagFeaturePurchased
==============
*/
bool BG_UnlockablesIsClanTagFeaturePurchased(const ControllerIndex_t controllerIndex, unsigned int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetItemAttachmentNumWithAttachPoint
==============
*/
int BG_UnlockablesGetItemAttachmentNumWithAttachPoint(int itemIndex, int attachmentNum, int attachmentPoint)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsItemAttachmentValid
==============
*/
int BG_UnlockablesIsItemAttachmentValid(int itemIndex, eAttachment attachment)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetItemAttachmentIndexForAttachmentPoint
==============
*/
int BG_UnlockablesGetItemAttachmentIndexForAttachmentPoint(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetItemRefHash
==============
*/
itemInfo_t *__thiscall BG_UnlockablesGetItemRefHash(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UnlockablesGetItemCount
==============
*/
int __thiscall BG_UnlockablesGetItemCount(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetItemUnlockLevel
==============
*/
itemInfo_t *__thiscall BG_UnlockablesGetItemUnlockLevel(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UnlockablesGetItemUnlockPLevel
==============
*/
itemInfo_t *__thiscall BG_UnlockablesGetItemUnlockPLevel(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UnlockablesGetItemMomentumCost
==============
*/
itemInfo_t *__thiscall BG_UnlockablesGetItemMomentumCost(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UnlockablesGetItemAllocationCost
==============
*/
itemInfo_t *__thiscall BG_UnlockablesGetItemAllocationCost(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UnlockablesGetRealItemCost
==============
*/
itemInfo_t *__thiscall BG_UnlockablesGetRealItemCost(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UnlockablesGetItemCost
==============
*/
int __thiscall BG_UnlockablesGetItemCost(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetItemDualWieldCost
==============
*/
int __thiscall BG_UnlockablesGetItemDualWieldCost(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetItemDualWieldIndex
==============
*/
int __thiscall BG_UnlockablesGetItemDualWieldIndex(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetItemDualWieldBaseIndex
==============
*/
int __thiscall BG_UnlockablesGetItemDualWieldBaseIndex(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetNumItemAttachmentsWithAttachPoint
==============
*/
int BG_UnlockablesGetNumItemAttachmentsWithAttachPoint(int itemIndex, int attachPoint)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetNumItemAttachments
==============
*/
int __thiscall BG_UnlockablesGetNumItemAttachments(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetNumItemAttachmentsAtPoint
==============
*/
int BG_UnlockablesGetNumItemAttachmentsAtPoint(int itemIndex, eAttachmentPoint point)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetItemAttachmentAtPointByIndex
==============
*/
eAttachment BG_UnlockablesGetItemAttachmentAtPointByIndex(
{
	UNIMPLEMENTED(__FUNCTION__);
	eAttachment tmp;
	return tmp;
}

/*
==============
BG_UnlockablesGetItemGroup
==============
*/
const char *__thiscall BG_UnlockablesGetItemGroup(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UnlockablesGetItemGroupEnum
==============
*/
int __thiscall BG_UnlockablesGetItemGroupEnum(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetLoadoutSlotFromString
==============
*/
/*int BG_UnlockablesGetLoadoutSlotFromString@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
BG_UnlockablesGetItemLoadoutSlot
==============
*/
int __thiscall BG_UnlockablesGetItemLoadoutSlot(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsItemLockedForRank
==============
*/
bool BG_UnlockablesIsItemLockedForRank(int pLevel, int rank)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsPrestigeTokenSpent
==============
*/
bool BG_UnlockablesIsPrestigeTokenSpent(unsigned __int8 *buffer, int pLevel)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesSpendPrestigeToken
==============
*/
bool BG_UnlockablesSpendPrestigeToken(unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetPrestigeTokenTypeFromBuffer
==============
*/
int BG_UnlockablesGetPrestigeTokenTypeFromBuffer(unsigned __int8 *buffer, int pLevel)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsItemPermanentlyUnlockedFromBuffer
==============
*/
char BG_UnlockablesIsItemPermanentlyUnlockedFromBuffer(unsigned __int8 *buffer, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsItemLockedFromBuffer
==============
*/
bool BG_UnlockablesIsItemLockedFromBuffer(unsigned __int8 *buffer, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetItemDLCIndex
==============
*/
unsigned __int8 __thiscall BG_UnlockablesGetItemDLCIndex(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsItemDLCAvailable
==============
*/
char BG_UnlockablesIsItemDLCAvailable(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesItemHasDualWield
==============
*/
bool __thiscall BG_UnlockablesItemHasDualWield(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesItemIsDualWield
==============
*/
bool __thiscall BG_UnlockablesItemIsDualWield(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsItemValidNotNull
==============
*/
bool BG_UnlockablesIsItemValidNotNull(int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesSetItemPurchased
==============
*/
bool BG_UnlockablesSetItemPurchased(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetCustomClassCountFromBuffer
==============
*/
int BG_UnlockablesGetCustomClassCountFromBuffer(unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsItemPublicPurchasedFromBuffer
==============
*/
bool BG_UnlockablesIsItemPublicPurchasedFromBuffer(unsigned __int8 *statsBuffer, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsItemPurchasedFromBuffer
==============
*/
bool BG_UnlockablesIsItemPurchasedFromBuffer()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesSetPurchasedBits
==============
*/
void BG_UnlockablesSetPurchasedBits(unsigned __int8 *statsBuffer, unsigned __int8 *purchasedItems)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesGetItemAttachmentAllocationCost
==============
*/
BOOL BG_UnlockablesGetItemAttachmentAllocationCost(int itemIndex, int attachmentNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetItemAttachmentXPInternal
==============
*/
int BG_UnlockablesGetItemAttachmentXPInternal(itemInfo_t *itemInfo, int attachmentNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetItemAttachmentXP
==============
*/
int BG_UnlockablesGetItemAttachmentXP(int itemIndex, int attachmentNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetGunXPFromBuffer
==============
*/
unsigned int BG_UnlockablesGetGunXPFromBuffer(unsigned __int8 *statsBuffer, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetGunPLevelFromBuffer
==============
*/
unsigned int BG_UnlockablesGetGunPLevelFromBuffer(unsigned __int8 *statsBuffer, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesSetGunXp
==============
*/
void BG_UnlockablesSetGunXp(const ControllerIndex_t controllerIndex, const int itemIndex, const int gunXP)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesSetGunXPCmd
==============
*/
void BG_UnlockablesSetGunXPCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesSetAllGunXPToMaxCmd
==============
*/
void BG_UnlockablesSetAllGunXPToMaxCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesIsItemAttachmentLockedFromBuffer
==============
*/
bool BG_UnlockablesIsItemAttachmentLockedFromBuffer(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsItemAttachmentLocked
==============
*/
bool BG_UnlockablesIsItemAttachmentLocked(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_SetBonusCardInUse
==============
*/
int BG_SetBonusCardInUse(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetBonusCardInUse
==============
*/
BOOL BG_GetBonusCardInUse(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_AnyBonusCardInUse
==============
*/
BOOL BG_AnyBonusCardInUse(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetStatPathForChallenge
==============
*/
int BG_UnlockablesGetStatPathForChallenge(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ChallengeLockedByXPGroup
==============
*/
bool ChallengeLockedByXPGroup(const ControllerIndex_t controllerIndex, challengeTableRow_t *challengeRow)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesItemOptionLockedByChallenge
==============
*/
bool BG_UnlockablesItemOptionLockedByChallenge(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesItemOptionLocked
==============
*/
bool BG_UnlockablesItemOptionLocked(const ControllerIndex_t controllerIndex, int itemIndex, int optionIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesEmblemIsElite
==============
*/
bool BG_UnlockablesEmblemIsElite(int emblemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesEquipClassSpecialPropertiesToSlot
==============
*/
void BG_UnlockablesEquipClassSpecialPropertiesToSlot(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesGetWeaponOptionRef
==============
*/
const char *BG_UnlockablesGetWeaponOptionRef(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UnlockablesGetLocalEquippedItemInSlot
==============
*/
int BG_UnlockablesGetLocalEquippedItemInSlot(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetDefaultItem
==============
*/
int BG_UnlockablesGetDefaultItem(int loadoutSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetDefaultWeaponItem
==============
*/
int BG_UnlockablesGetDefaultWeaponItem()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesEquipDefaultClass
==============
*/
void BG_UnlockablesEquipDefaultClass(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesEquipDefaultCustomMatchClassCmd
==============
*/
void BG_UnlockablesEquipDefaultCustomMatchClassCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesEquipDefaultLeagueClassCmd
==============
*/
void BG_UnlockablesEquipDefaultLeagueClassCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesEquipDefaultClassCmdInternal
==============
*/
void BG_UnlockablesEquipDefaultClassCmdInternal(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesEquipDefaultClassCmd
==============
*/
void BG_UnlockablesEquipDefaultClassCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesEquipDefaultClassToProfileCmd
==============
*/
void BG_UnlockablesEquipDefaultClassToProfileCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesUIEquipDefaultClassCmd
==============
*/
void BG_UnlockablesUIEquipDefaultClassCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesZeroClassSet
==============
*/
void BG_UnlockablesZeroClassSet(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesZeroClassSetCmdInternal
==============
*/
void BG_UnlockablesZeroClassSetCmdInternal(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesZeroPublicMatchClassSetCmd
==============
*/
void BG_UnlockablesZeroPublicMatchClassSetCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesZeroCustomMatchClassSetCmd
==============
*/
void BG_UnlockablesZeroCustomMatchClassSetCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesZeroLeagueMatchClassSetCmd
==============
*/
void BG_UnlockablesZeroLeagueMatchClassSetCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesCopyToClassSet
==============
*/
void BG_UnlockablesCopyToClassSet(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesCopyToClassSetCmdInternal
==============
*/
void BG_UnlockablesCopyToClassSetCmdInternal(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesCopyToPublicMatchClassSetCmd
==============
*/
void BG_UnlockablesCopyToPublicMatchClassSetCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesCopyToCustomMatchClassSetCmd
==============
*/
void BG_UnlockablesCopyToCustomMatchClassSetCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesCopyToLeagueMatchClassSetCmd
==============
*/
void BG_UnlockablesCopyToLeagueMatchClassSetCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesSetClassSetNameFromLocStringCmdInternal
==============
*/
void BG_UnlockablesSetClassSetNameFromLocStringCmdInternal(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesSetPublicMatchClassSetNameFromLocStringCmd
==============
*/
void BG_UnlockablesSetPublicMatchClassSetNameFromLocStringCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesSetCustomMatchClassSetNameFromLocStringCmd
==============
*/
void BG_UnlockablesSetCustomMatchClassSetNameFromLocStringCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesSetLeagueMatchClassSetNameFromLocStringCmd
==============
*/
void BG_UnlockablesSetLeagueMatchClassSetNameFromLocStringCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesGetClassSetsDDLState
==============
*/
bool BG_UnlockablesGetClassSetsDDLState(ddlState_t *ddlState, int specificGameMode)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetDefaultClassSlotIndexFromName
==============
*/
/*int BG_UnlockablesGetDefaultClassSlotIndexFromName@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
BG_UnlockablesBuildItemListForGroup
==============
*/
int BG_UnlockablesBuildItemListForGroup(itemGroup_t group)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesBuildItemListForGroupCmd
==============
*/
void BG_UnlockablesBuildItemListForGroupCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesBuildItemListForGroupForWeaponTable
==============
*/
int BG_UnlockablesBuildItemListForGroupForWeaponTable(itemGroup_t group)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesBuildItemListForGroupForWeaponTableCmd
==============
*/
void BG_UnlockablesBuildItemListForGroupForWeaponTableCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesCopyClassSection
==============
*/
void BG_UnlockablesCopyClassSection(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesCopyClassCmd
==============
*/
void BG_UnlockablesCopyClassCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesSetClanTagCmd
==============
*/
void BG_UnlockablesSetClanTagCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesClearWeaponInfo
==============
*/
void BG_UnlockablesClearWeaponInfo(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesGetBonusCardSet
==============
*/
int BG_UnlockablesGetBonusCardSet(const ControllerIndex_t controllerIndex, const loadoutClass_t customClass)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetItemEquipCount
==============
*/
int BG_UnlockablesGetItemEquipCount(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetAllocationCost
==============
*/
/*int BG_UnlockablesGetAllocationCost@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
BG_UnlockablesGetUsedAllocation
==============
*/
/*int BG_UnlockablesGetUsedAllocation@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
BG_UnlockablesGetBonusCardSetCmd
==============
*/
void BG_UnlockablesGetBonusCardSetCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesGetUsedAllocationCmd
==============
*/
void BG_UnlockablesGetUsedAllocationCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesGetItemsByGroup
==============
*/
int BG_UnlockablesGetItemsByGroup(itemGroup_t group, unsigned __int8 *buffer, unsigned int bufferSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_PerformPushItem_ToCACMPShared
==============
*/
void BG_PerformPushItem_ToCACMPShared(int numItemsInSlot, int itemNum, void *param)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
validateCACStatus_s::ValidateClass_NoDuplicateCards
==============
*/
/*char validateCACStatus_s::ValidateClass_NoDuplicateCards(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
validateCACStatus_s::ValidateClass_NoDuplicates
==============
*/
/*char validateCACStatus_s::ValidateClass_NoDuplicates(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
validateCACStatus_s::ValidateClass_HasBonusCard
==============
*/
/*char validateCACStatus_s::ValidateClass_HasBonusCard(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
validateCACStatus_s::verifyUnusedAttachmentSlotsCheck
==============
*/
/*char __thiscall validateCACStatus_s::verifyUnusedAttachmentSlotsCheck(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
validateCACStatus_s::Print
==============
*/
/*void __thiscall validateCACStatus_s::Print(validateCACStatus_s *this)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
validateCACStatus_s::Initialize
==============
*/
/*void __thiscall validateCACStatus_s::Initialize(
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
BG_UnlockablesGetColStringForItemIndex
==============
*/
const char *BG_UnlockablesGetColStringForItemIndex(int itemIndex, statsTableColumns_t column)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UnlockablesGetCountSlot
==============
*/
loadoutSlot_t BG_UnlockablesGetCountSlot(itemInfo_t *itemInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
	loadoutSlot_t tmp;
	return tmp;
}

/*
==============
BG_UnlockablesHandleDefaultGrenadeStatus
==============
*/
void BG_UnlockablesHandleDefaultGrenadeStatus(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesIsPrimaryOrSecondaryFromIndex
==============
*/
bool BG_UnlockablesIsPrimaryOrSecondaryFromIndex(int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesParseDLCInfo
==============
*/
void BG_UnlockablesParseDLCInfo(const char *dlcInfo, itemInfo_t *itemInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesIsMaxLevelFromBuffer
==============
*/
char BG_UnlockablesIsMaxLevelFromBuffer(unsigned __int8 *statsBuffer, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetItemName
==============
*/
const char *BG_UnlockablesGetItemName(int a1, statsTableColumns_t a2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UnlockablesGetItemRef
==============
*/
const char *BG_UnlockablesGetItemRef(int a1, statsTableColumns_t a2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UnlockablesGetItemImage
==============
*/
const char *BG_UnlockablesGetItemImage(int a1, statsTableColumns_t a2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UnlockablesDLCWeaponDisabled
==============
*/
bool __thiscall BG_UnlockablesDLCWeaponDisabled(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetItemDesc
==============
*/
const char *BG_UnlockablesGetItemDesc(int a1, statsTableColumns_t a2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UnlockablesIsItemLocked
==============
*/
bool BG_UnlockablesIsItemLocked(const ControllerIndex_t controllerIndex, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsItemDualWieldLocked
==============
*/
bool BG_UnlockablesIsItemDualWieldLocked(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsItemTrackedByMap
==============
*/
/*char BG_UnlockablesIsItemTrackedByMap@<al>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
BG_UnlockablesIsItemNew
==============
*/
bool BG_UnlockablesIsItemNew(const ControllerIndex_t controllerIndex, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsItemGroupNew
==============
*/
char BG_UnlockablesIsItemGroupNew(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsItemPurchased
==============
*/
bool BG_UnlockablesIsItemPurchased(const ControllerIndex_t controllerIndex, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsItemDualWieldPurchased
==============
*/
bool BG_UnlockablesIsItemDualWieldPurchased(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesSetBonusCardBits
==============
*/
void BG_UnlockablesSetBonusCardBits(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesEmblemOrBackingLockedByChallenge
==============
*/
bool BG_UnlockablesEmblemOrBackingLockedByChallenge(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesEmblemLockedByChallenge
==============
*/
bool BG_UnlockablesEmblemLockedByChallenge(ControllerIndex_t controllerIndex, int emblemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesEmblemBackingLockedByChallenge
==============
*/
bool BG_UnlockablesEmblemBackingLockedByChallenge(ControllerIndex_t controllerIndex, int backingIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetItemIndexFromName
==============
*/
int BG_UnlockablesGetItemIndexFromName(const char *itemName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetItemIndexFromRefHash
==============
*/
/*int BG_UnlockablesGetItemIndexFromRefHash@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
BG_UnlockablesGetItemIndexFromRef
==============
*/
int BG_UnlockablesGetItemIndexFromRef(const char *itemName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetItemIndexforWeapon
==============
*/
int BG_UnlockablesGetItemIndexforWeapon(Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesClearItemNew
==============
*/
void BG_UnlockablesClearItemNew(ControllerIndex_t controllerIndex, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesClearAllItemsNew
==============
*/
void BG_UnlockablesClearAllItemsNew(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesEquipClass
==============
*/
void BG_UnlockablesEquipClass(ControllerIndex_t controllerIndex, loadoutClass_t customClass, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesIsItemEquipped
==============
*/
bool BG_UnlockablesIsItemEquipped(ControllerIndex_t controllerIndex, loadoutClass_t customClass, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesEquipClassCmd
==============
*/
void BG_UnlockablesEquipClassCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesEquipDefaultItemToSlotCmd
==============
*/
void BG_UnlockablesEquipDefaultItemToSlotCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesGetDefaultClassSlotFromName
==============
*/
/*const char *BG_UnlockablesGetDefaultClassSlotFromName@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
BG_UnlockablesClearItemNewCmd
==============
*/
void BG_UnlockablesClearItemNewCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesClearAllItemsNewCmd
==============
*/
void BG_UnlockablesClearAllItemsNewCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesGetNumPurchasedItemsInCurrentList
==============
*/
int BG_UnlockablesGetNumPurchasedItemsInCurrentList(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesBuildItemListForSlotName
==============
*/
int BG_UnlockablesBuildItemListForSlotName(const ControllerIndex_t controllerIndex, const char *slotName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesBuildItemListForSlotNameCmd
==============
*/
void BG_UnlockablesBuildItemListForSlotNameCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesBuildItemListForGroupName
==============
*/
int BG_UnlockablesBuildItemListForGroupName(const ControllerIndex_t controllerIndex, const char *groupName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesBuildItemListForGroupNameCmd
==============
*/
void BG_UnlockablesBuildItemListForGroupNameCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesBuildItemListForSlotNameAndGroup
==============
*/
int BG_UnlockablesBuildItemListForSlotNameAndGroup(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesBuildItemListForSlotNameAndGroupCmd
==============
*/
void BG_UnlockablesBuildItemListForSlotNameAndGroupCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesGetItemIndexInSlot
==============
*/
int BG_UnlockablesGetItemIndexInSlot(int itemNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesBonusCardEquipAction
==============
*/
bool BG_UnlockablesBonusCardEquipAction(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsBonusCardInSet
==============
*/
bool BG_UnlockablesIsBonusCardInSet(const int cardSet, const char *cardName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesIsBonusCardInSetCmd
==============
*/
void BG_UnlockablesIsBonusCardInSetCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesEquipBonusCardCmd
==============
*/
void BG_UnlockablesEquipBonusCardCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesUnequipBonusCardCmd
==============
*/
void BG_UnlockablesUnequipBonusCardCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesPushItemsByGroupName
==============
*/
void BG_UnlockablesPushItemsByGroupName(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
validateCACStatus_s::ValidateClass_ByGroupSearch
==============
*/
/*char validateCACStatus_s::ValidateClass_ByGroupSearch(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
validateCACStatus_s::ValidateClass_GetNumItemAttachments
==============
*/
/*int __thiscall validateCACStatus_s::ValidateClass_GetNumItemAttachments(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
validateCACStatus_s::ValidateClass_BonusCard_PrerequisitesAndRules
==============
*/
/*bool __thiscall validateCACStatus_s::ValidateClass_BonusCard_PrerequisitesAndRules(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
validateCACStatus_s::ValidateClass_BonusCards
==============
*/
/*void validateCACStatus_s::ValidateClass_BonusCards(validateCACStatus_s *this, loadoutSlot_t a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
validateCACStatus_s::ValidateClass_AdditionalGrenadeCheck
==============
*/
/*bool __thiscall validateCACStatus_s::ValidateClass_AdditionalGrenadeCheck(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
validateCACStatus_s::ValidateClass_Grenade
==============
*/
/*void validateCACStatus_s::ValidateClass_Grenade(validateCACStatus_s *this, loadoutSlot_t a2, int slotIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
validateCACStatus_s::ValidateClass_Specialties
==============
*/
/*void validateCACStatus_s::ValidateClass_Specialties(validateCACStatus_s *this, loadoutSlot_t a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
validateCACStatus_s::ValidateClass_KillStreaks
==============
*/
/*void validateCACStatus_s::ValidateClass_KillStreaks(validateCACStatus_s *this, loadoutSlot_t a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
validateCACStatus_s::ValidateClass_BaseWeapon
==============
*/
/*void validateCACStatus_s::ValidateClass_BaseWeapon(
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
validateCACStatus_s::ValidateClass_Attachments_CheckMaxAllowed
==============
*/
/*bool validateCACStatus_s::ValidateClass_Attachments_CheckMaxAllowed(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
validateCACStatus_s::ValidateClass_VerifyNoAttachments
==============
*/
/*void validateCACStatus_s::ValidateClass_VerifyNoAttachments(
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
validateCACStatus_s::Verify
==============
*/
/*char validateCACStatus_s::Verify(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
BG_UnlockablesCheckItemsInClass
==============
*/
bool BG_UnlockablesCheckItemsInClass(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_Unlockable_CheckLoadOutVsRank
==============
*/
char BG_Unlockable_CheckLoadOutVsRank(unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesBuildDefaultClasses
==============
*/
void BG_UnlockablesBuildDefaultClasses(defaultClassInfo_t *defaultClassInfoTable)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesParseDualWieldInfo
==============
*/
void BG_UnlockablesParseDualWieldInfo(itemInfo_t *itemInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesParseSpecialtyInfo
==============
*/
void BG_UnlockablesParseSpecialtyInfo(itemInfo_t *itemInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetSpecialtyCollectionImageName
==============
*/
/*const char *BG_GetSpecialtyCollectionImageName@<eax>(statsTableColumns_t a1@<edx>, int collectionIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
BG_GetSpecialtyCollectionName
==============
*/
/*const char *BG_GetSpecialtyCollectionName@<eax>(statsTableColumns_t a1@<edx>, int collectionIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
BG_UnlockablesBuildGunLevels
==============
*/
void BG_UnlockablesBuildGunLevels()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesIsItemInUnlockedByCAC
==============
*/
bool BG_UnlockablesIsItemInUnlockedByCAC(int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesBuildItemInfo
==============
*/
bool BG_UnlockablesBuildItemInfo(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesBuildActualDefaultItems
==============
*/
unsigned int BG_UnlockablesBuildActualDefaultItems()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesBuildDefaultItems
==============
*/
unsigned int BG_UnlockablesBuildDefaultItems()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_InitUnlockables
==============
*/
void BG_InitUnlockables()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesGetItemAttachment
==============
*/
eAttachment BG_UnlockablesGetItemAttachment(int itemIndex, int attachmentNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	eAttachment tmp;
	return tmp;
}

/*
==============
BG_UnlockablesPurchaseItem
==============
*/
void BG_UnlockablesPurchaseItem(const ControllerIndex_t controllerIndex, int itemIndex, int cost)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesGetItemAttachmentRef
==============
*/
const char *BG_UnlockablesGetItemAttachmentRef(int itemIndex, int attachmentNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UnlockablesPurchaseItemCmd
==============
*/
void BG_UnlockablesPurchaseItemCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesSetUnlockedAttachmentBits
==============
*/
void BG_UnlockablesSetUnlockedAttachmentBits(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesGetAttachmentRef
==============
*/
/*const char *BG_UnlockablesGetAttachmentRef@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
BG_UnlockablesGetItemReferenceInLoadoutSlot
==============
*/
/*const char *BG_UnlockablesGetItemReferenceInLoadoutSlot@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
validateCACStatus_s::ValidateClass_WeaponOption
==============
*/
/*void validateCACStatus_s::ValidateClass_WeaponOption(
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
validateCACStatus_s::ValidateClass_NoConflictingAttachments
==============
*/
/*char __thiscall validateCACStatus_s::ValidateClass_NoConflictingAttachments(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
validateCACStatus_s::ValidateClass_Attachments
==============
*/
/*void validateCACStatus_s::ValidateClass_Attachments(
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
validateCACStatus_s::Validate
==============
*/
/*bool validateCACStatus_s::Validate(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
BG_UnlockablesValidateClassCmd
==============
*/
void BG_UnlockablesValidateClassCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockableItemsInit
==============
*/
void BG_UnlockableItemsInit()
{
	UNIMPLEMENTED(__FUNCTION__);
}

