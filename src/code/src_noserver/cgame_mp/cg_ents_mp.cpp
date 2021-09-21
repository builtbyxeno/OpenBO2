#include "types.h"
#include "functions.h"

/*
==============
CG_GetLightingOrigin
==============
*/
void CG_GetLightingOrigin(const DObj *obj, const centity_t *cent, vec3_t *lightingOrigin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetTurretAnims
==============
*/
XAnim_s *CG_GetTurretAnims(centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_Player_PreControllers
==============
*/
void CG_Player_PreControllers(DObj *obj, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Turret_OverheatUpdate
==============
*/
void CG_Turret_OverheatUpdate(LocalClientNum_t localClientNum, const DObj *obj, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Turret_PreControllers
==============
*/
void CG_Turret_PreControllers(DObj *obj, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_IsCarriedTurretEnt
==============
*/
int CG_IsCarriedTurretEnt(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Turret_UpdateMinigun
==============
*/
void CG_Turret_UpdateMinigun(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SetBallisticAngles
==============
*/
void SetBallisticAngles(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IsWeaponRetrieveable
==============
*/
bool IsWeaponRetrieveable(LocalClientNum_t localClientNum, const centity_t *cent, const WeaponDef *weapDef, const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_UpdateBModelWorldBounds
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_ScriptMover_GetBurnFraction
==============
*/
double CG_ScriptMover_GetBurnFraction(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AnyLocalPlayersIsWeaponLinkedToEnt
==============
*/
bool AnyLocalPlayersIsWeaponLinkedToEnt(centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_InitZBarriers
==============
*/
void CG_InitZBarriers()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CreateZBarrierPieceDObj
==============
*/
void CG_CreateZBarrierPieceDObj(LocalClientNum_t localClientNum, centity_t *piece, centity_t *zbarrier, ZBarrierBoard *boardDef, int pieceIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_InitZBarrier
==============
*/
void CG_InitZBarrier(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_InitZBarrierPiece
==============
*/
void CG_InitZBarrierPiece(centity_t *piece, centity_t *parent, ZBarrierType *zbarrierType, int pieceIndex, DObj *pDobj)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateZBarrierPieceAnim
==============
*/
void CG_UpdateZBarrierPieceAnim(LocalClientNum_t localClientNum, centity_t *parent, int pieceIndex, DObj *pDobj)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetZBarrierEffectPosition
==============
*/
void CG_GetZBarrierEffectPosition(const centity_t *pCent, const vec3_t *offset, vec3_t *axis, vec3_t *outPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
zbarrier_repair_logic
==============
*/
void zbarrier_repair_logic(LocalClientNum_t localClientNum, cg_t *cgameGlob, centity_t *pParent, ZBarrierDef *pZBarrierDef, _cgZBarrierPiece_t *pPiece, LerpEntityStateZBarrierPiece *pLerpPiece, unsigned int pieceIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
zbarrier_piece_box_fly_away_logic
==============
*/
void zbarrier_piece_box_fly_away_logic(LocalClientNum_t localClientNum, cg_t *cgameGlob, centity_t *pParent, ZBarrierDef *pZBarrierDef, _cgZBarrierPiece_t *pPiece, LerpEntityStateZBarrierPiece *pLerpPiece)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
zbarrier_piece_teardown_logic
==============
*/
void zbarrier_piece_teardown_logic(LocalClientNum_t localClientNum, cg_t *cgameGlob, centity_t *pParent, ZBarrierDef *pZBarrierDef, _cgZBarrierPiece_t *pPiece, LerpEntityStateZBarrierPiece *pLerpPiece, unsigned int pieceIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_MissileProcessSnapshot
==============
*/
void CG_MissileProcessSnapshot(LocalClientNum_t localClientNum, centity_t *missileCent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ZBarrierProcessSnapshot
==============
*/
void CG_ZBarrierProcessSnapshot(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateMoverAnims
==============
*/
void CG_UpdateMoverAnims(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetFrameInterpolation
==============
*/
void CG_SetFrameInterpolation(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PlayClientRumbleNoteTracks
==============
*/
void CG_PlayClientRumbleNoteTracks(LocalClientNum_t localClientNum, int entnum, const vec3_t *origin, const char *notifyName)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PlayClientSoundNoteTracks
==============
*/
void CG_PlayClientSoundNoteTracks(LocalClientNum_t localClientNum, int entnum, const vec3_t *origin, const char *notifyName, bool isViewArms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetBoneFromNote
==============
*/
unsigned __int16 GetBoneFromNote(unsigned __int16 note, const char *noteString)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_ProcessFootstepNote
==============
*/
void CG_ProcessFootstepNote(LocalClientNum_t localClientNum, centity_t *cent, const XAnimClientNotify *note)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ProcessClientNote
==============
*/
void CG_ProcessClientNote(const XAnimClientNotify *note, int entityNum, cg_t *cgameGlob, centity_t *cent, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ProcessClientNoteTracks
==============
*/
void CG_ProcessClientNoteTracks(LocalClientNum_t localClientNum, int entityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ReduceOriginError
==============
*/
void CG_ReduceOriginError(LocalClientNum_t localClientNum, vec3_t *origin, vec3_t *originError, float maxChange)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ReduceAnglesError
==============
*/
void CG_ReduceAnglesError(LocalClientNum_t localClientNum, vec3_t *angles, vec3_t *anglesError, float maxChange)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_LerpOriginAnglesError
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_UpdateClientDobjPartBits
==============
*/
void CG_UpdateClientDobjPartBits(centity_t *cent, int entnum, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ClampPrimaryLightDir
==============
*/
void CG_ClampPrimaryLightDir(GfxLight *light, const ComPrimaryLight *refLight)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PrimaryLight
==============
*/
void CG_PrimaryLight(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ShouldDelayEntityPacketPostPS
==============
*/
int CG_ShouldDelayEntityPacketPostPS(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DelayListAdd
==============
*/
void DelayListAdd(DelayListInfo *listInfo, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DelayListRemove
==============
*/
void DelayListRemove(DelayListInfo *listInfo, centity_t *cent, centity_t *centPrev)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
EntPacketUpdateNeedsDelayed
==============
*/
bool EntPacketUpdateNeedsDelayed(LocalClientNum_t localClientNum, centity_t *cent, bool contextKey)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DObjUpdateInfo
==============
*/
void CG_DObjUpdateInfo(const cg_t *cgameGlob, DObj *obj, int notifyFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetPose
==============
*/
centity_t *CG_GetPose(LocalClientNum_t localClientNum, int handle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_StartFx
==============
*/
unsigned int CG_StartFx(LocalClientNum_t localClientNum, centity_t *cent, int startAtTime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Fx
==============
*/
void CG_Fx(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_InterpolateEntityPosition
==============
*/
void CG_InterpolateEntityPosition(cg_t *cgameGlob, centity_t *cent, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_LerpTrajectory
==============
*/
void CG_LerpTrajectory(const cg_t *cgameGlob, trajectory_t *trFrom, trajectory_t *trTo, float lerp, trajectory_t *trResult, bool isAngle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_InterpolateVehicleDriver
==============
*/
void CG_InterpolateVehicleDriver(const cg_t *cgameGlob, centity_t *cent, int curTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AnyLocalClientDriving
==============
*/
char AnyLocalClientDriving(centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ShouldInterpolateFromNitrousVehicleLocally
==============
*/
bool ShouldInterpolateFromNitrousVehicleLocally(const cg_t *cgameGlob, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_InterpolateVehicle
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_CreateRagdollObject
==============
*/
void CG_CreateRagdollObject(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateRagdollPose
==============
*/
void CG_UpdateRagdollPose(centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalcEntityRagdollPositions
==============
*/
void CG_CalcEntityRagdollPositions(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateMoverRecord
==============
*/
void CG_UpdateMoverRecord(LocalClientNum_t localClientNum, int moverNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_InterpolateEntityAngles
==============
*/
void CG_InterpolateEntityAngles(cg_t *cgameGlob, centity_t *cent, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CreateNitrousVehicle
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_UpdatePhysicsPose
==============
*/
void CG_UpdatePhysicsPose(centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateTags
==============
*/
void CG_UpdateTags(centity_t *ent, const DObj *obj)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AddClientScriptAttachedModel
==============
*/
unsigned int CG_AddClientScriptAttachedModel(centity_t *cent, DObjModel_s *dobjModels, unsigned int numModels, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_AddVehicleAttachedModel
==============
*/
unsigned int CG_AddVehicleAttachedModel(centity_t *cent, DObjModel_s *dobjModels, unsigned int numModels, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_AddScriptMoverAttachedModel
==============
*/
unsigned int CG_AddScriptMoverAttachedModel(centity_t *cent, DObjModel_s *dobjModels, unsigned int numModels, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_AddWeaponAttachedModel
==============
*/
unsigned int CG_AddWeaponAttachedModel(centity_t *cent, DObjModel_s *dobjModels, unsigned int numModels, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_PreProcess_GetDObj
==============
*/
DObj *CG_PreProcess_GetDObj(LocalClientNum_t localClientNum, int entIndex, int entType, XModel *model, XModel *model2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_DObjCalcBone
==============
*/
void CG_DObjCalcBone(const cpose_t *pose, DObj *obj, int boneIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ClearUnion
==============
*/
void CG_ClearUnion(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetUnionType
==============
*/
void CG_SetUnionType(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdatePoseUnion
==============
*/
void CG_UpdatePoseUnion(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetPoseOrigin
==============
*/
void CG_GetPoseOrigin(const cpose_t *pose, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetPoseAbsMinMax
==============
*/
void CG_GetPoseAbsMinMax(const cpose_t *pose, vec3_t *absmin, vec3_t *absmax)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetPoseAxis
==============
*/
void CG_GetPoseAxis(const cpose_t *pose, vec3_t *axis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetPoseQuat
==============
*/
void CG_GetPoseQuat(const cpose_t *pose, vec4_t *quat)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetEntityOrigin
==============
*/
vec3_t *CG_GetEntityOrigin(LocalClientNum_t localClientNum, unsigned int entnum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_PredictiveSkinCEntity
==============
*/
void CG_PredictiveSkinCEntity(GfxSceneEntity *sceneEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_PredictiveSkelModel
==============
*/
void CG_PredictiveSkelModel(GfxSceneModel *sceneModel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetOrigin
==============
*/
void CG_SetOrigin(centity_t *ent, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetAngle
==============
*/
void CG_SetAngle(centity_t *ent, const vec3_t *angle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_IsEntityFriendlyNotEnemy
==============
*/
bool CG_IsEntityFriendlyNotEnemy(LocalClientNum_t localClientNum, const centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_EntityInfrared
==============
*/
int CG_EntityInfrared(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_EntitySonar
==============
*/
__int16 *CG_EntitySonar(LocalClientNum_t localClientNum, centity_t *cent, bool corpse)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_WhatModelShouldLocalPlayerSee
==============
*/
int CG_WhatModelShouldLocalPlayerSee(LocalClientNum_t localClientNum, const cg_t *cgameGlob, const centity_t *cent, int centTeam, int friendlyModel, int enemyModel)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetDriverClientNumFromVehicle
==============
*/
int CG_GetDriverClientNumFromVehicle(LocalClientNum_t localClientNum, const centity_t *vehicle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_ClientFlagResetAll
==============
*/
void CG_ClientFlagResetAll(centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ClientFlagSet
==============
*/
void CG_ClientFlagSet(centity_t *cent, int flagNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ClientFlagClear
==============
*/
void CG_ClientFlagClear(centity_t *cent, int flagNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ClientFlagIsActive
==============
*/
BOOL CG_ClientFlagIsActive(const centity_t *cent, int flagNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_ClientFlagIsSet
==============
*/
BOOL CG_ClientFlagIsSet(const centity_t *cent, int flagNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_General
==============
*/
void CG_General(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Item
==============
*/
void CG_Item(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SensorGrenade
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_Missile
==============
*/
void CG_Missile(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ScriptMover_GetDObj
==============
*/
DObj *CG_ScriptMover_GetDObj(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_HandleZBarrierModelChanges
==============
*/
DObj *CG_HandleZBarrierModelChanges(LocalClientNum_t localClientNum, centity_t *parent, int pieceIndex, DObj *pDobj, ZBarrierBoard *pBoardDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SwitchZombieBoxWeapon
==============
*/
void SwitchZombieBoxWeapon(LocalClientNum_t localClientNum, centity_t *cent, zombieBoxWeapon_t *pZombieBoxWeapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ClearZombieBoxWeapon
==============
*/
void ClearZombieBoxWeapon(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
zbarrier_piece_box_rise_logic
==============
*/
void zbarrier_piece_box_rise_logic(LocalClientNum_t localClientNum, cg_t *cgameGlob, centity_t *pParent, ZBarrierDef *pZBarrierDef, _cgZBarrierPiece_t *pPiece, LerpEntityStateZBarrierPiece *pLerpPiece, unsigned int pieceIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateZBarrierPieceState
==============
*/
void CG_UpdateZBarrierPieceState(LocalClientNum_t localClientNum, cg_t *cgameGlob, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ZBarrier
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_ScriptMover
==============
*/
void CG_ScriptMover(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_LoopFx
==============
*/
void CG_LoopFx(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_DObjGetLocalTagMatrix
==============
*/
DObjAnimMat *CG_DObjGetLocalTagMatrix(const cpose_t *pose, DObj *obj, unsigned int tagName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CG_DObjGetWorldBoneMatrix
==============
*/
int CG_DObjGetWorldBoneMatrix(const cpose_t *poseEA, DObj *objEA, int boneIndex, vec3_t *tagMat, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DObjGetWorldTagMatrix
==============
*/
int CG_DObjGetWorldTagMatrix(DObj *a1, const cpose_t *pose, DObj *obj, unsigned int tagName, vec3_t *tagMat, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_DObjGetWorldTagPos
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_Vehicle
==============
*/
void CG_Vehicle(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CreatePhysicsObject
==============
*/
void CG_CreatePhysicsObject(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalcEntityPhysicsPositions
==============
*/
void CG_CalcEntityPhysicsPositions(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalcEntityLerpPositions
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_ClientFlagCallback
==============
*/
void CG_ClientFlagCallback(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ProcessFxEntity
==============
*/
void CG_ProcessFxEntity(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AddPacketFxEntity
==============
*/
void CG_AddPacketFxEntity(LocalClientNum_t localClientNum, int entnum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ProcessFakeEntity
==============
*/
void CG_ProcessFakeEntity(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Turret
==============
*/
void CG_Turret(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ProcessEntity
==============
*/
void CG_ProcessEntity(LocalClientNum_t localClientNum, centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AddPacketEntity
==============
*/
void CG_AddPacketEntity(LocalClientNum_t localClientNum, int entnum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UpdatePacketEnt
==============
*/
void UpdatePacketEnt(LocalClientNum_t localClientNum, int entnum, int timeNow, int *postPSEntNum, bool contextKey)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UpdateDelayedPacketEnts
==============
*/
void UpdateDelayedPacketEnts(LocalClientNum_t localClientNum, DelayListInfo *delayList, int *postPSEntNum, bool contextKey)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_AddPacketEntities
==============
*/
int CG_AddPacketEntities(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

