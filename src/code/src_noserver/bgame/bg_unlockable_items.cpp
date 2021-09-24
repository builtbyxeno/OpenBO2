#include "types.h"

/*
==============
BG_UnlockablesBuildUnlockMapping
==============
*/
void BG_UnlockablesBuildUnlockMapping(const char *unlockMappingTableName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesGetUnlockIndexFromGroup
==============
*/
int BG_UnlockablesGetUnlockIndexFromGroup(itemGroup_t group)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetUnlockIndexFromName
==============
*/
int BG_UnlockablesGetUnlockIndexFromName(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetUnlockLocString
==============
*/
const char *BG_UnlockablesGetUnlockLocString(int unlockIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_UnlockablesGetCurrentUnlocks
==============
*/
unsigned int BG_UnlockablesGetCurrentUnlocks(const ControllerIndex_t controllerIndex, int unlockIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesSpendUnlocks
==============
*/
int BG_UnlockablesSpendUnlocks(const ControllerIndex_t controllerIndex, int unlockIndex, int cost)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesSetItemIndex
==============
*/
void BG_UnlockablesSetItemIndex(const CACRoot *cacRoot, loadoutClass_t customClass, loadoutSlot_t loadoutSlot, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesSetGlobalItemIndex
==============
*/
void BG_UnlockablesSetGlobalItemIndex(const CACRoot *cacRoot, loadoutSlot_t loadoutSlot, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesSetLoadoutItem
==============
*/
void BG_UnlockablesSetLoadoutItem(const CACRoot *cacRoot, int customClass, int loadoutSlot, int itemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesGetGlobalItemIndex
==============
*/
int BG_UnlockablesGetGlobalItemIndex(const CACRoot *cacRoot, loadoutSlot_t loadoutSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetItemIndex
==============
*/
int BG_UnlockablesGetItemIndex(const CACRoot *cacRoot, loadoutClass_t customClass, loadoutSlot_t loadoutSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesGetLoadoutItem
==============
*/
int BG_UnlockablesGetLoadoutItem(loadoutSlot_t a1, char *a2, const CACRoot *cacRoot, int customClass, int loadoutSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_UnlockablesEquipClassToSlot
==============
*/
void BG_UnlockablesEquipClassToSlot(const char **a1, const char *a2, char *a3, const CACRoot *cacRoot, loadoutClass_t customClass, int itemIndex, const char *loadoutName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_UnlockablesGetLocalCACRoot
==============
*/
const CACRoot *BG_UnlockablesGetLocalCACRoot(const CACRoot *result, const ControllerIndex_t controllerIndex, const loadoutClass_t loadoutClass)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

