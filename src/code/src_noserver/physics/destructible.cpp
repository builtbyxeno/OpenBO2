#include "types.h"
#include "functions.h"

/*
==============
TRACK_destructible
==============
*/
void TRACK_destructible()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Destructible_DumpEventInfo
==============
*/
void Destructible_DumpEventInfo()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EnableAllDestructiblePieces
==============
*/
void EnableAllDestructiblePieces()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IsDestructiblePieceDisabled
==============
*/
char IsDestructiblePieceDisabled(int label)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_EnableAllDestructiblePieces
==============
*/
void CG_EnableAllDestructiblePieces()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetDestructibleIndex
==============
*/
int CG_GetDestructibleIndex(LocalClientNum_t localClientNum, const Destructible *destructible)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Destructible_GetDestructibleByIndex
==============
*/
Destructible *Destructible_GetDestructibleByIndex(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Destructible_GetFreeDestructible
==============
*/
Destructible *Destructible_GetFreeDestructible()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Destructible_FreeDestructible
==============
*/
void Destructible_FreeDestructible(Destructible *destructible)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetFreeDestructible
==============
*/
Destructible *CG_GetFreeDestructible(LocalClientNum_t localClientNum, int entNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_InitDestructibles
==============
*/
void CG_InitDestructibles(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_InitDestructibles
==============
*/
void G_InitDestructibles()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Destructible_FindGameState
==============
*/
destructible_gamestate *Destructible_FindGameState(int entityNum, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Destructible_RemoveGameState
==============
*/
char Destructible_RemoveGameState(int entityNum, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Destructible_GetNumStagesForPiece
==============
*/
int Destructible_GetNumStagesForPiece(DestructibleDef *ddef, int pieceIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Destructible_GetDestructibleStage
==============
*/
int Destructible_GetDestructibleStage(const DestructibleDef *ddef, int pieceIndex, int health)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Destructible_GetShowBoneNameForPiece
==============
*/
unsigned int Destructible_GetShowBoneNameForPiece(Destructible *destructible, int pieceIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Destructible_GetHideParts
==============
*/
void Destructible_GetHideParts(Destructible *destructible, unsigned int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Destructible_GetPieceIndexFromBoneName
==============
*/
char Destructible_GetPieceIndexFromBoneName(Destructible *destructible, int modelIndex, unsigned int boneName, unsigned __int8 *index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetHealthFromState
==============
*/
int GetHealthFromState(const LerpEntityStateDestructibleHit *state, DestructibleDef *ddef, unsigned __int8 pieceIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DestructibleEventSetPieceState
==============
*/
void DestructibleEventSetPieceState(Destructible *destructible, LerpEntityStateDestructibleHit *state)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DestructibleClientOnlyCreate
==============
*/
void CG_DestructibleClientOnlyCreate(centity_t *ent, DestructibleDef *ddef)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SpawnPhysObjForBone
==============
*/
int CG_SpawnPhysObjForBone(const centity_t *cent, int pieceIndex, int boneName, const vec3_t *hitp, const vec3_t *hitd, int mod)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetTagTransform
==============
*/
unsigned int CG_GetTagTransform(centity_t *self, DestructibleDef *ddef, int pieceIndex, vec3_t *tagOrigin, vec3_t *tagMat)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_GetTagTransform
==============
*/
unsigned int G_GetTagTransform(gentity_t *ent, DestructibleDef *ddef, int pieceIndex, vec3_t *tagMat)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DestructibleSetBurn
==============
*/
void CG_DestructibleSetBurn(LocalClientNum_t localClientNum, centity_t *self, Destructible *destructible, int pieceIndex, bool burn)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DestructibleGetBurnFrac
==============
*/
double CG_DestructibleGetBurnFrac(Destructible *destructible)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DestructibleIsClientOnly
==============
*/
BOOL CG_DestructibleIsClientOnly(Destructible *destructible)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DestructibleUpdateDObj
==============
*/
void CG_DestructibleUpdateDObj(centity_t *self)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_StoreDestructibleState
==============
*/
void CG_StoreDestructibleState(centity_t *cent, DestructibleState newState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DestructibleRewindToTime
==============
*/
void CG_DestructibleRewindToTime(LocalClientNum_t localClientNum, Destructible *destructible, int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CM_Hunk_AllocDestructible
==============
*/
unsigned __int8 *CM_Hunk_AllocDestructible(int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DestructibleDefPrecache_LoadObj
==============
*/
DestructibleDef *DestructibleDefPrecache_LoadObj(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DestructibleDefPrecache_FastFile
==============
*/
DestructibleDef *DestructibleDefPrecache_FastFile(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DestructibleDefPrecache
==============
*/
DestructibleDef *DestructibleDefPrecache()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Destructible_GetPieceCount
==============
*/
int Destructible_GetPieceCount(Destructible *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Destructible_XDollActive
==============
*/
unsigned int Destructible_XDollActive(Destructible *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Destructible_GetXDollHandle
==============
*/
int Destructible_GetXDollHandle(Destructible *obj, int piece_index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Destructible_GetRigidBody
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Destructible_LoadDestructibles
==============
*/
void Destructible_LoadDestructibles(MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Destructible_WriteGameState
==============
*/
void Destructible_WriteGameState(msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Destructible_ReadGameState
==============
*/
void Destructible_ReadGameState(msg_t *msg, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_Destructible_WriteGameState
==============
*/
void Demo_Destructible_WriteGameState(msg_t *msg, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_Destructible_ReadGameState
==============
*/
void Demo_Destructible_ReadGameState(msg_t *msg, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetDestructiblePose
==============
*/
DestructiblePose *CG_GetDestructiblePose(__int16 index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_DestructibleShake
==============
*/
void CG_DestructibleShake(LocalClientNum_t localClientNum, centity_t *cent, int pieceIndex, const vec3_t *dir, const vec3_t *hitp, const int mod)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Destructible_SetDebugRender
==============
*/
void Destructible_SetDebugRender(Destructible *destructible)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Destructible_DebugRender
==============
*/
void Destructible_DebugRender()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Destructible_GetDDef
==============
*/
DestructibleDef *Destructible_GetDDef(const centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_DestructibleCallback
==============
*/
void Scr_DestructibleCallback(gentity_t *self, unsigned __int16 event, int piece, float time, int damage)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DisableDestructiblePiece
==============
*/
void DisableDestructiblePiece(int label)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DisableDestructiblePiece
==============
*/
void CG_DisableDestructiblePiece(LocalClientNum_t localClientNum, int label)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DestructibleUpdate
==============
*/
unsigned __int16 DestructibleUpdate(gentity_t *ent, DObjModel_s *dobjModels, unsigned __int16 numModels)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DestructibleExplosiveDamageEvent
==============
*/
void DestructibleExplosiveDamageEvent(gentity_t *self, const vec3_t *point, const float radius, const int mod)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DestructibleBulletDamageEvent
==============
*/
void DestructibleBulletDamageEvent(gentity_t *self, const vec3_t *point, const vec3_t *dir, const int mod)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DamagePiece
==============
*/
char DamagePiece(gentity_t *self, unsigned __int8 index, int damage, const vec3_t *point, const vec3_t *dir, int mod, const bool damageChildren, const int excludeChild, gentity_t *attacker, int recursiveDepth, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DestructibleRadiusDamage
==============
*/
double DestructibleRadiusDamage(gentity_t *self, const vec3_t *point, float damgeInner, float damgeOuter, float radius, int mod, gentity_t *attacker, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DestructibleDamage
==============
*/
int DestructibleDamage(gentity_t *self, gentity_t *attacker, const vec3_t *dir, const vec3_t *point, int damage, int mod, unsigned int modelIndex, unsigned int partName, Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DestructibleUpdate
==============
*/
unsigned int CG_DestructibleUpdate(centity_t *ent, DObjModel_s *dobjModels, unsigned int numModels, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DestructibleSpawnDynEnt
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_DestructibleBreakPiece
==============
*/
void CG_DestructibleBreakPiece(centity_t *self, DestructiblePiece *piece, int pieceIndex, int stage, int nextStage, const vec3_t *hitp, const vec3_t *hitd, const int mod)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RestartDestructibles
==============
*/
void CG_RestartDestructibles(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DestructibleDamage
==============
*/
bool CG_DestructibleDamage(vec3_t *a1, centity_t *self, const vec3_t *dir, const vec3_t *point, const unsigned int pieceIndex, const int newHealth, int damage, const int mod, const bool updateDObj, const bool applyForce)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_FreeDestructiblePose
==============
*/
void CG_FreeDestructiblePose(LocalClientNum_t localClientNum, unsigned __int8 destructiblePoseID)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_FreeDestructible
==============
*/
void CG_FreeDestructible(LocalClientNum_t localClientNum, Destructible *destructible)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DamagePiece
==============
*/
char CG_DamagePiece(vec3_t *a1, LocalClientNum_t localClientNum, centity_t *self, unsigned __int8 index, int damage, const vec3_t *point, const vec3_t *dir, int mod, const bool damageChildren, int recursiveDepth)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DestructibleRadiusDamage
==============
*/
void CG_DestructibleRadiusDamage(centity_t *self, const vec3_t *point, float damgeInner, float damgeOuter, float radius, int mod, const int lazyprocess)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DestructibleHitEvent
==============
*/
void CG_DestructibleHitEvent(LocalClientNum_t localClientNum, int event, const entityState_s *es, const int lazyprocess)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DestructibleDamage
==============
*/
/*void CG_DestructibleDamage(const char *a1@<edi>, centity_t *self, const centity_t *attacker, const vec3_t *dir, const vec3_t *point, int damage, int mod, unsigned int modelIndex, unsigned int partName, const int lazyprocess)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
CG_ProcessDestructibleEvents
==============
*/
void CG_ProcessDestructibleEvents()
{
	UNIMPLEMENTED(__FUNCTION__);
}

