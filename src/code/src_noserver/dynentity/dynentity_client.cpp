#include "types.h"
#include "functions.h"

/*
==============
DynEntCl_RegisterDvars
==============
*/
void DynEntCl_RegisterDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_GetCurrentXModel
==============
*/
XModel *DynEntCl_GetCurrentXModel(const DynEntityDef *dynEntDef, const DynEntityClient *dynEntClient)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DynEntCl_UpdateBModelWorldBounds
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
DynEntCl_LinkModel
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
DynEntCl_LinkBrush
==============
*/
void DynEntCl_LinkBrush(unsigned __int16 dynEntId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_UnlinkEntity
==============
*/
void DynEntCl_UnlinkEntity(unsigned __int16 dynEntId, DynEntityDrawType drawType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_DestroyPhysics
==============
*/
void DynEnt_DestroyPhysics(PhysWorld worldIndex, const DynEntityDef *dynEntDef, DynEntityClient *dynEntClient)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_UpdateBounds
==============
*/
void DynEntCl_UpdateBounds()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_FixupLightConstraints
==============
*/
void DynEnt_FixupLightConstraints(LocalClientNum_t localClientNum, int entnum, int primaryLightIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_UpdateLightConstraint
==============
*/
void DynEnt_UpdateLightConstraint(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_UpdateConstraints
==============
*/
void DynEnt_UpdateConstraints(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_GetSurfaceType
==============
*/
int DynEnt_GetSurfaceType(const DynEntityDef *dynEntDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEntCl_PointTrace_r
==============
*/
void DynEntCl_PointTrace_r(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_PointTrace
==============
*/
void DynEntCl_PointTrace(const pointtrace_t *clip, trace_t *results)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_AreaEntities_r
==============
*/
void DynEntCl_AreaEntities_r(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_AreaEntities
==============
*/
unsigned __int16 DynEntCl_AreaEntities(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEntCl_PlayEventFx
==============
*/
void DynEntCl_PlayEventFx(const FxEffectDef *def, const vec3_t *origin, const vec3_t *axis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_PlayImpactEffects
==============
*/
void DynEntCl_PlayImpactEffects(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_TurnOffLight
==============
*/
void DynEntCl_TurnOffLight(const DynEntityDef *dynEntDef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_Enable
==============
*/
void DynEntCl_Enable(unsigned __int16 absId, const bool enable)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_Damage
==============
*/
void DynEntCl_Damage(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_IsLocalClient
==============
*/
bool DynEntCl_IsLocalClient(LocalClientNum_t localClientNum, int sourceEntityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEntCl_PlayBoltedFX
==============
*/
unsigned int DynEntCl_PlayBoltedFX(const FxEffectDef *fx, unsigned __int16 absDynEntId)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEntCl_RemoveFromFadeList
==============
*/
void DynEntCl_RemoveFromFadeList(unsigned __int16 absDynEntId)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_SetBurnFrac
==============
*/
void DynEntCl_SetBurnFrac(unsigned __int16 dynEntId, DynEntityDrawType drawType, float frac)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_GetBurnTime
==============
*/
double DynEntCl_GetBurnTime(unsigned __int16 dynEntId, DynEntityDrawType drawType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEntCl_CompareDynEntsForExplosion
==============
*/
BOOL DynEntCl_CompareDynEntsForExplosion(const DynEntSortStruct *ent1, const DynEntSortStruct *ent2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEntCl_DestroyEvent
==============
*/
void DynEntCl_DestroyEvent(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CreateRopes
==============
*/
void CreateRopes(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_GetDynEntity
==============
*/
unsigned __int16 DynEnt_GetDynEntity(int targetname)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SCR_DynEnt_GetDynEntityArray
==============
*/
void SCR_DynEnt_GetDynEntityArray(int targetname)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MapHitLocationToRagdollBoneName
==============
*/
void MapHitLocationToRagdollBoneName(hitLocation_t hitLoc, unsigned int *boneName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CheckDynEnts
==============
*/
void CheckDynEnts()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_Shutdown
==============
*/
void DynEntCl_Shutdown(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_SetupConstraints
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
DynEntCl_CreatePhysObj
==============
*/
int DynEntCl_CreatePhysObj(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEntCl_Launch
==============
*/
void DynEntCl_Launch(unsigned __int16 absId, const vec3_t *dir, const vec3_t *hitp)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_SetBurning
==============
*/
void DynEntCl_SetBurning(unsigned __int16 dynEntId, DynEntityDrawType drawType, bool burning)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_UpdateBurning
==============
*/
LocalClientNum_t DynEnt_UpdateBurning()
{
	UNIMPLEMENTED(__FUNCTION__);
	LocalClientNum_t tmp;
	return tmp;
}

/*
==============
DynEntCl_FlameDamage
==============
*/
void DynEntCl_FlameDamage(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_EntityImpactEvent
==============
*/
void DynEntCl_EntityImpactEvent(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_HitTrace
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
DynEntCl_DynEntImpactEvent
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
DynEntCl_DynEntBulletImpactEvent
==============
*/
char DynEntCl_DynEntBulletImpactEvent(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEntCl_InitEntities
==============
*/
void DynEntCl_InitEntities(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_DestroyEntityModel
==============
*/
void DynEntCl_DestroyEntityModel(unsigned __int16 id)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_CleanUpOldModels
==============
*/
void DynEntCl_CleanUpOldModels()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_AddEntityModel
==============
*/
unsigned __int16 DynEntCl_AddEntityModel()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEntCl_CreateEntityModel
==============
*/
unsigned __int16 DynEntCl_CreateEntityModel(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEntCl_SetFadeOut
==============
*/
void DynEntCl_SetFadeOut(unsigned __int16 dynEntId, DynEntityDrawType drawType)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEnt_UpdateFading
==============
*/
void DynEnt_UpdateFading(int currentTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_MeleeEvent
==============
*/
void DynEntCl_MeleeEvent(LocalClientNum_t localClientNum, int attackerEntNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_ProcessEntities
==============
*/
void DynEntCl_ProcessEntities(LocalClientNum_t localClientNum, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_GetClosestEntities
==============
*/
unsigned int DynEntCl_GetClosestEntities(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DynEntCl_ExplosionEvent
==============
*/
void DynEntCl_ExplosionEvent(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DynEntCl_JetThrustEvent
==============
*/
void DynEntCl_JetThrustEvent(
{
	UNIMPLEMENTED(__FUNCTION__);
}

