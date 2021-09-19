#include "types.h"
#include "functions.h"

/*
==============
Fill_Clip
==============
*/
void Fill_Clip(playerState_s *ps, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CurrentPrimaryWeapon
==============
*/
Weapon CurrentPrimaryWeapon(playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
G_ItemClipMask
==============
*/
int G_ItemClipMask(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PrintPlayerPickupMessage
==============
*/
void PrintPlayerPickupMessage(gentity_t *player, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
WeaponPickup_GetCompatibleWeapon
==============
*/
Weapon WeaponPickup_GetCompatibleWeapon(gentity_t *player, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
WeaponPickup_Notifies
==============
*/
void WeaponPickup_Notifies(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PrintMessage_CannotGrabItem
==============
*/
void PrintMessage_CannotGrabItem(gentity_t *ent, gentity_t *player, int touched, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetFreeDropCueIdx
==============
*/
int GetFreeDropCueIdx()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DroppedItemClearOwner
==============
*/
void DroppedItemClearOwner(gentity_t *pSelf)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetItemClassname
==============
*/
void G_GetItemClassname(const Weapon item, unsigned __int16 *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PlayerHasAnyAmmoToTransferToWeapon
==============
*/
bool PlayerHasAnyAmmoToTransferToWeapon(gentity_t *player, Weapon transferWeapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TransferPlayerAmmoToWeaponEntity
==============
*/
int TransferPlayerAmmoToWeaponEntity(gentity_t *player, gentity_t *weaponEnt, Weapon transferWeapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TransferRandomAmmoToWeaponEntity
==============
*/
int TransferRandomAmmoToWeaponEntity(gentity_t *weaponEnt, Weapon transferWeapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TransferSpecifiedAmmoToWeaponEntity
==============
*/
int TransferSpecifiedAmmoToWeaponEntity(gentity_t *weaponEnt, Weapon transferWeapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FinishSpawningItem
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
ClearRegisteredItems
==============
*/
void ClearRegisteredItems()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DumpWeaponConfigStrings
==============
*/
void DumpWeaponConfigStrings()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SaveRegisteredWeapons
==============
*/
void SaveRegisteredWeapons()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SaveRegisteredItems
==============
*/
void SaveRegisteredItems()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RegisterWeaponRumbles
==============
*/
void RegisterWeaponRumbles(const WeaponDef *weapDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_RegisterWeapon
==============
*/
void G_RegisterWeapon(unsigned int weapIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IsItemRegistered
==============
*/
int IsItemRegistered(int iItemIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_SpawnItem
==============
*/
void G_SpawnItem(gentity_t *ent, const Weapon item)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_OrientItemToGround
==============
*/
void G_OrientItemToGround(gentity_t *ent, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_RunItem
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Add_Ammo
==============
*/
int Add_Ammo(gentity_t *ent, Weapon weapon, int count, int fillClip)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
WeaponPickup_LeechFromWeaponEnt
==============
*/
bool WeaponPickup_LeechFromWeaponEnt(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
WeaponPickup_AddAmmoForNewWeapon
==============
*/
void WeaponPickup_AddAmmoForNewWeapon(gentity_t *weaponEnt, gentity_t *player)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
WeaponPickup_Touch
==============
*/
int WeaponPickup_Touch(gentity_t *weaponEnt, gentity_t *player, Weapon weapon, int *pickupEvent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LaunchItem
==============
*/
gentity_t *LaunchItem(const Weapon item, vec3_t *origin, vec3_t *angles, vec3_t *velocity, int ownerNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Drop_Item
==============
*/
gentity_t *Drop_Item(gentity_t *ent, const Weapon item, float angle, int novelocity)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
ThrowClientWeapon
==============
*/
gentity_t *ThrowClientWeapon(gentity_t *ent, const Weapon item, float heightIncrease, float velocityIncrease)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
ThrowDownWeapon
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Drop_Weapon
==============
*/
gentity_t *Drop_Weapon(gentity_t *ent, Weapon weapon, unsigned __int8 weaponModel, unsigned int tag)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
WeaponPickup_AddWeapon
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
WeaponPickup_Grab
==============
*/
int WeaponPickup_Grab(gentity_t *weaponEnt, gentity_t *player, Weapon weapon, int *pickupEvent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
WeaponPickup
==============
*/
int WeaponPickup(gentity_t *weaponEnt, gentity_t *player, int *pickupEvent, int touched)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Touch_Item
==============
*/
void Touch_Item(gentity_t *ent, gentity_t *other, int touched)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Touch_Item_Auto
==============
*/
void Touch_Item_Auto(gentity_t *ent, gentity_t *other, int bTouched)
{
	UNIMPLEMENTED(__FUNCTION__);
}

