#include "types.h"

/*
==============
WeaponVariantDefHash::Set
==============
*/
/*void WeaponVariantDefHash::Set(WeaponVariantDefHash *notthis, int wi)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
BG_GetNumWeapons
==============
*/
unsigned int BG_GetNumWeapons()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetWeaponVariantDef
==============
*/
WeaponVariantDef *BG_GetWeaponVariantDef(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_GetWeaponDef
==============
*/
WeaponDef *BG_GetWeaponDef(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_FreeWeaponDefStrings
==============
*/
unsigned int BG_FreeWeaponDefStrings()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_ShutdownWeaponDefFiles
==============
*/
void BG_ShutdownWeaponDefFiles()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_SetupAttachmentAlts
==============
*/
void BG_SetupAttachmentAlts(const Weapon weapon, void (*regWeap)(unsigned int))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_SetupAttachmentDualWield
==============
*/
void BG_SetupAttachmentDualWield(const Weapon weapon, void (*regWeap)(unsigned int))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_SetupWeaponAlts
==============
*/
void BG_SetupWeaponAlts(const Weapon weapon, void (*regWeap)(unsigned int))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_SetupDualWieldAlts
==============
*/
void BG_SetupDualWieldAlts(const Weapon weapon, void (*regWeap)(unsigned int))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_SetupWeaponMountedVersions
==============
*/
void BG_SetupWeaponMountedVersions(const Weapon weapon, void (*regWeap)(unsigned int))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_InitDefaultWeaponDef
==============
*/
void BG_InitDefaultWeaponDef()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_ClearWeaponDef
==============
*/
void BG_ClearWeaponDef()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_WeaponMyChanges
==============
*/
void BG_WeaponMyChanges()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_SetUpAmmoForWeapon
==============
*/
void BG_SetUpAmmoForWeapon(Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_WeaponVariantNameHashCompare
==============
*/
int BG_WeaponVariantNameHashCompare(const void *a, const void *b)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_FindWeaponForName
==============
*/
Weapon BG_FindWeaponForName(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
BG_IsDefaultWeapon
==============
*/
bool BG_IsDefaultWeapon(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_SortWeaponAttachments
==============
*/
Weapon BG_SortWeaponAttachments(const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
BG_GetWeaponForFullName
==============
*/
Weapon BG_GetWeaponForFullName(const char *name, Weapon (*getWeaponForName)(const char *))
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
GunPerkCount
==============
*/
int GunPerkCount()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GunPerkFromIndex
==============
*/
int GunPerkFromIndex(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_SetupWeaponVariantDef
==============
*/
unsigned int __cdecl BG_SetupWeaponVariantDef(WeaponVariantDef *weapVariantDef, void (__cdecl *regWeap)(unsigned int))
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_FillInAllWeaponItems
==============
*/
void BG_FillInAllWeaponItems()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetWeaponForName
==============
*/
Weapon BG_GetWeaponForName(const char *name, void (*regWeap)(unsigned int))
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
BG_GetWeaponForName
==============
*/
Weapon BG_GetWeaponForName(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
BG_SetupAltWeaponIndex
==============
*/
void BG_SetupAltWeaponIndex(const Weapon baseWeapon, WeaponVariantDef *weapVariantDef, void (*regWeap)(unsigned int))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_WeaponVariantPrecache
==============
*/
void BG_WeaponVariantPrecache(const Weapon baseWeapon, void (__cdecl *regWeap)(unsigned int), const char *namePrefix, const char *namePostfix)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PrecacheGunPerk_r
==============
*/
void PrecacheGunPerk_r(int index, int weaponTableItemIndex, const Weapon baseWeapon, void (*regWeap)(unsigned int), const char *namePrefix, const char *namePostfix, int *attachmentCount, unsigned __int64 incompatibleAttachments)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
WeaponVariantPrecacheGunPerk
==============
*/
void WeaponVariantPrecacheGunPerk(int weaponTableItemIndex, const Weapon baseWeapon, void (*regWeap)(unsigned int), const char *namePrefix, const char *namePostfix, int *attachmentCount, unsigned __int64 incompatibleAttachments)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_WeaponVariantPrecache_r
==============
*/
bool BG_WeaponVariantPrecache_r(int weaponTableItemIndex, const Weapon baseWeapon, void (*regWeap)(unsigned int), const char *namePrefix, const char *namePostfix, eAttachmentPoint point, int index, void (*alreadyRegistered)(unsigned int), int *numAttachments, unsigned __int64 incompatibleAttachments)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_LoadWeaponTableBaseAndVariants
==============
*/
bool BG_LoadWeaponTableBaseAndVariants(statsTableColumns_t a1, int a2, int weaponTableItemIndex, const char *weaponNamePostfix, void (*regWeap)(unsigned int))
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetWeaponTableItemIndex
==============
*/
int BG_GetWeaponTableItemIndex(Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_LoadWeaponTable
==============
*/
char BG_LoadWeaponTable(const char *weaponNamePostfix, void (*regWeap)(unsigned int))
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

