#include "types.h"
#include "functions.h"

/*
==============
Vehicle_RegisterDvars
==============
*/
void Vehicle_RegisterDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_Strdup
==============
*/
void VEH_Strdup(unsigned __int8 *pMember, const char *str)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_DebugCapsule
==============
*/
void VEH_DebugCapsule(vec3_t *pos, float rad, float height, float r, float g, float b)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_GetVehicle
==============
*/
gentity_t *VEH_GetVehicle(int entNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
VEH_IsSeatPresent
==============
*/
BOOL VEH_IsSeatPresent(gentity_t *ent, int seatIdx, const VehicleDef *info)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_GetSeatWeapon
==============
*/
Weapon VEH_GetSeatWeapon(gentity_t *const vehicle, const int seatIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	Weapon tmp;
	return tmp;
}

/*
==============
VEH_GetSeat
==============
*/
VehicleSeat *VEH_GetSeat(vehicle_t *veh, int seatIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
VEH_GetSeat
==============
*/
VehicleSeat *VEH_GetSeat(gentity_t *vehEnt, int seatIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
VEH_GetSeatOccupantEntNum
==============
*/
int VEH_GetSeatOccupantEntNum(vehicle_t *veh, int seatIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_GetSeatOccupantEntNum
==============
*/
int VEH_GetSeatOccupantEntNum(gentity_t *vehEnt, int seatIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_SetSeatOccupantEntNum
==============
*/
int VEH_SetSeatOccupantEntNum(vehicle_t *veh, int seatIdx, int occEntNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_GetSeatOccupantEntity
==============
*/
gentity_t *VEH_GetSeatOccupantEntity(vehicle_t *veh, int seatIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
VEH_GetSeatOccupantEntity
==============
*/
gentity_t *VEH_GetSeatOccupantEntity(gentity_t *vehEnt, int seatIdx)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
VEH_GetWheelOrigin
==============
*/
void VEH_GetWheelOrigin(gentity_t *ent, int idx, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_DObjHasRequiredTags
==============
*/
bool VEH_DObjHasRequiredTags(gentity_t *ent, int defIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_InitEntity
==============
*/
void VEH_InitEntity(gentity_t *ent, vehicle_t *veh, int defIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdatePhysics
==============
*/
void VEH_UpdatePhysics(gentity_t *ent, const PlayerVehicleState *vehicleState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_JoltBody
==============
*/
void VEH_JoltBody(gentity_t *ent, const vec3_t *dir, float intensity, float speedFrac, float decel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_CalcAccel
==============
*/
void VEH_CalcAccel(gentity_t *ent, char *move, vec3_t *bodyAccel, vec3_t *rotAccel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_ClipVelocity
==============
*/
void VEH_ClipVelocity(const vec3_t *in, const vec3_t *normal, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_CorrectAllSolid
==============
*/
int VEH_CorrectAllSolid(gentity_t *ent, trace_t *trace)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_ClearGround
==============
*/
void VEH_ClearGround()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_GroundTrace
==============
*/
void VEH_GroundTrace(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_MoveTrace
==============
*/
void VEH_MoveTrace(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_SlideMove
==============
*/
BOOL VEH_SlideMove(gentity_t *ent, int gravity, float frameTime, unsigned int *bumpEntityNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_StepSlideMove
==============
*/
void VEH_StepSlideMove(int *a1, float gravity, int a3)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_SlideMoveAndNotify
==============
*/
void VEH_SlideMoveAndNotify(gentity_t *ent, int gravity, float frameTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_GroundMove
==============
*/
void VEH_GroundMove(gentity_t *ent, float frameTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_AirMove
==============
*/
void VEH_AirMove(gentity_t *ent, int gravity)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_GroundPlant
==============
*/
void VEH_GroundPlant(float ent, vec3_t *a2, int a3, gentity_t *phys, vehicle_physic_t *gravity, int a6)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_BackupPosition
==============
*/
void VEH_BackupPosition(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AttachedStickyMissile
==============
*/
bool AttachedStickyMissile(gentity_t *vehicle, gentity_t *missile)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PushAttachedStickyMissile
==============
*/
void PushAttachedStickyMissile(gentity_t *vehicle, gentity_t *missile, vec3_t *deltaOrigin, vec3_t *deltaAngles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_GetBoundingBoxFromCollmap
==============
*/
void VEH_GetBoundingBoxFromCollmap(vec3_t *bbMins, gentity_t *vehicle, vec3_t *bbMaxs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_ClampPointToBoundingBox
==============
*/
bool VEH_ClampPointToBoundingBox(gentity_t *a1, vec3_t *a2, gentity_t *vehicle, const vec3_t *point, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_PushEntity
==============
*/
void VEH_PushEntity(gentity_t *ent, gentity_t *target, vec3_t *pushDir, vec3_t *deltaOrigin, vec3_t *deltaAngles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_TouchEntities
==============
*/
void VEH_TouchEntities(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_DebugAim
==============
*/
void VEH_DebugAim(gentity_t *ent, const vec4_t *color, int duration)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_PredictPlayerPosition
==============
*/
void VEH_PredictPlayerPosition(const gentity_t *ent, const playerState_s *ps, vec3_t *vPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateAim
==============
*/
void VEH_UpdateAim(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateGunnerAim
==============
*/
void VEH_UpdateGunnerAim(gentity_t *ent, int gunnerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Veh_GunnerBurstFirePending
==============
*/
bool Veh_GunnerBurstFirePending(const Weapon weapon, int weaponShotCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_UpdateBody
==============
*/
void VEH_UpdateBody(gentity_t *ent, const VehicleDef *info)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateSteering
==============
*/
void VEH_UpdateSteering(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateQuadrotor
==============
*/
void VEH_UpdateQuadrotor(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_ShouldEjectOccupants
==============
*/
bool VEH_ShouldEjectOccupants(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_UpdateAvoidance
==============
*/
void VEH_UpdateAvoidance(vec3_t *pos, vec3_t *goal, float radius, float height, vec3_t *newGoalPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_IsHovering
==============
*/
bool VEH_IsHovering(vehicle_t *veh)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_UpdateAngleAndAngularVel
==============
*/
void VEH_UpdateAngleAndAngularVel(int index, float desiredAngle, float accel, float decel, float overShoot, vehicle_physic_t *phys)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_SetHoverGoal
==============
*/
void VEH_SetHoverGoal(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateMove_GetDesiredYaw
==============
*/
float VEH_UpdateMove_GetDesiredYaw(vehicle_t *veh, vec3_t *desiredDir)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_UpdateYawAndNotify
==============
*/
void VEH_UpdateYawAndNotify(gentity_t *ent, float desiredYaw)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateVelocityWithRotation
==============
*/
void VEH_UpdateVelocityWithRotation(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateMoveOrientation
==============
*/
void VEH_UpdateMoveOrientation(vec3_t *a1, vehicle_t *a2, float desiredYaw, gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_CheckHorizontalVelocityToGoal
==============
*/
void VEH_CheckHorizontalVelocityToGoal(vehicle_t *veh, const vec2_t *vecToGoal, float accelMax, vec3_t *accelVec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_CheckVerticalVelocityToGoal
==============
*/
void VEH_CheckVerticalVelocityToGoal(vehicle_t *veh, float verticalDist, vec3_t *accelVec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateMove_CheckStop
==============
*/
float VEH_UpdateMove_CheckStop(vehicle_t *veh, float distToGoal)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_GetNewSpeedAndAccel
==============
*/
void VEH_GetNewSpeedAndAccel(vehicle_t *veh, float dt, int hovering, float speedScale, float *newSpeed, float *accelMax)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateYawAngularVel
==============
*/
void VEH_UpdateYawAngularVel(gentity_t *ent, float desiredYaw)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateAngle
==============
*/
void VEH_UpdateAngle(int index, float desiredAngle, float acceleration, vehicle_physic_t *phys)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_DebugPlaneOnCurve
==============
*/
void VEH_DebugPlaneOnCurve(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdatePlaneRoll
==============
*/
void VEH_UpdatePlaneRoll(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdatePlaneOnCurve
==============
*/
void VEH_UpdatePlaneOnCurve(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdatePlaneFree
==============
*/
void VEH_UpdatePlaneFree(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdatePathOffset
==============
*/
void VEH_UpdatePathOffset(vehicle_t *veh, const VehicleDef *info, vec3_t *origin, vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_DoAutoTilt
==============
*/
bool VEH_DoAutoTilt(vehicle_t *veh)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_UpdatePathTransition
==============
*/
void VEH_UpdatePathTransition(vehicle_t *veh, vec3_t *origin, vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_GetMaxSpeed
==============
*/
double VEH_GetMaxSpeed(gentity_t *ent, bool useGDT)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_SetLinkAngleClamps
==============
*/
void VEH_SetLinkAngleClamps(const VehicleDef *info, gentity_t *player, int seatIndex, vec3_t *playerAngles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_SetPlayerVehicle
==============
*/
void VEH_SetPlayerVehicle(gentity_t *ent, bool enable)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_ShouldLinkPlayer
==============
*/
char VEH_ShouldLinkPlayer(gentity_t *ent, gentity_t *player, int seatIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_LinkPlayer
==============
*/
void VEH_LinkPlayer(gentity_t *ent, gentity_t *player, int seatIndex, bool changingSeats)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_ExitPosOkay
==============
*/
bool VEH_ExitPosOkay(gentity_t *vehEnt, int exitIndex, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_IsHorse
==============
*/
BOOL VEH_IsHorse(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_GetNextSeat
==============
*/
int VEH_GetNextSeat(const VehicleDef *info, int currentSeat)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_ParseScrVehicleDef
==============
*/
void G_ParseScrVehicleDef()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateViewClampsOnPlayer
==============
*/
void VEH_UpdateViewClampsOnPlayer(gentity_t *ent, const VehicleDef *info)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_ReloadVehicleDef
==============
*/
void G_ReloadVehicleDef()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_InitScrVehicles
==============
*/
void G_InitScrVehicles()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_SetupScrVehicles
==============
*/
void G_SetupScrVehicles(void *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_FreeScrVehicles
==============
*/
void G_FreeScrVehicles()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GScr_GetVehicleArray
==============
*/
void GScr_GetVehicleArray(int teamFlags, bool spawner)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_MakeVehicleUsable
==============
*/
void G_MakeVehicleUsable(gentity_t *ent, bool usable)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_UpdateVehicleTags
==============
*/
void G_UpdateVehicleTags(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetNumVehicles
==============
*/
int G_GetNumVehicles()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_GetOccupantsTeam
==============
*/
team_t VEH_GetOccupantsTeam(gentity_t *vehEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
	team_t tmp;
	return tmp;
}

/*
==============
VEH_IsSeatOccupied
==============
*/
bool VEH_IsSeatOccupied(gentity_t *ent, int seatIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_GetSeatPlayerOccupies
==============
*/
int VEH_GetSeatPlayerOccupies(gentity_t *ent, gentity_t *player)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_GetSeatToEnter
==============
*/
int VEH_GetSeatToEnter(gentity_t *ent, gentity_t *player, bool scriptUse, int *entryPoint)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_GetPlayerMantlePoint
==============
*/
VehicleMantlePoints VEH_GetPlayerMantlePoint(gentity_t *ent, gentity_t *player)
{
	UNIMPLEMENTED(__FUNCTION__);
	VehicleMantlePoints tmp;
	return tmp;
}

/*
==============
VEH_IsUsable
==============
*/
int VEH_IsUsable(gentity_t *ent, gentity_t *player)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_GetRadius
==============
*/
double VEH_GetRadius(vehicle_physic_t *phys)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_IsPlayerDriving
==============
*/
bool VEH_IsPlayerDriving(const gentity_t *player)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Scr_Vehicle_Controller
==============
*/
void Scr_Vehicle_Controller(const gentity_t *pSelf, int *partBits)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_AvoidTracePassed
==============
*/
bool VEH_AvoidTracePassed(const gentity_t *pSelf, const vec3_t *avoidPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_UpdateLink
==============
*/
void VEH_UpdateLink(gentity_t *pSelf)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_Vehicle_Touch
==============
*/
void Scr_Vehicle_Touch(gentity_t *pSelf, gentity_t *pOther)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetVehicleTypeString
==============
*/
vehicle_t *G_GetVehicleTypeString(ClientNum_t clientNum, int entityNum, VehicleDef **vehDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Scr_Vehicle_Use
==============
*/
void Scr_Vehicle_Use(gentity_t *pEnt, gentity_t *pOther)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_GetVehicleDefIndex
==============
*/
int VEH_GetVehicleDefIndex(const gentity_t *vehicle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_GetVehicleDef
==============
*/
const VehicleDef *VEH_GetVehicleDef(const gentity_t *vehicle)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
VEH_GetWheelBone
==============
*/
bool VEH_GetWheelBone(gentity_t *vehEnt, int wheelIndex, int *wheelBone)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_GetBoneOrigin
==============
*/
void VEH_GetBoneOrigin(gentity_t *vehEnt, int boneIndex, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_CanPlayerPlaceVehicle
==============
*/
int VEH_CanPlayerPlaceVehicle(int a1, const gentity_t *player, const float boundingRadius, const float boundingHeight, const float startForward, const float startUp, const float sweepDistance, const float plancementMinNormal, vec3_t *outOrigin, vec3_t *outAngles)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_IsOccupied
==============
*/
char VEH_IsOccupied(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_LoadVehicle
==============
*/
int G_LoadVehicle(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_GetDefFromName
==============
*/
int VEH_GetDefFromName(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_ValidatePosition
==============
*/
char VEH_ValidatePosition(unsigned int a1, gentity_t *ent, const vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_SetPosition
==============
*/
void VEH_SetPosition(gentity_t *a1, unsigned int a2, gentity_t *ent, const vec3_t *origin, const vec3_t *vel, const vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_InitFromInfo
==============
*/
void VEH_InitFromInfo(gentity_t *ent, const VehicleDef *info)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_InitPhysics
==============
*/
void VEH_InitPhysics(gentity_t *ent, int defIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_InitVehicle
==============
*/
void VEH_InitVehicle(gentity_t *ent, vehicle_t *veh, int defIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_FireGunnerWeapon
==============
*/
gentity_t *VEH_FireGunnerWeapon(gentity_t *ent, int gunnerIndex, gentity_t *attacker)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
ShouldCoolDown
==============
*/
bool ShouldCoolDown(vehicle_t *veh, gentity_t *player, const WeaponDef *weapDef, int gunnerIndex, int checkButton)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ShouldHeatUp
==============
*/
bool ShouldHeatUp(vehicle_t *veh, gentity_t *player, const WeaponDef *weapDef, int gunnerIndex, int checkButton, bool burstFirePending)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_UpdateGunnerWeapon
==============
*/
void VEH_UpdateGunnerWeapon(gentity_t *ent, int gunnerIndex, int msec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateDriverWeapons
==============
*/
void VEH_UpdateDriverWeapons(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateClient
==============
*/
void VEH_UpdateClient(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdatePathPosition
==============
*/
void VEH_UpdatePathPosition(gentity_t *ent, vehicle_pathpos_t *vpp, vec3_t *origin, vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_CheckPathEnd
==============
*/
void VEH_CheckPathEnd(int a1, gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateMove_CheckGoalAndNearGoal
==============
*/
int VEH_UpdateMove_CheckGoalAndNearGoal(gentity_t *ent, vec3_t *goalPosition)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_UpdateMoveToGoal
==============
*/
void VEH_UpdateMoveToGoal(gentity_t *ent, const vec3_t *goalPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateMoveToGoalAircraft
==============
*/
vec3_t *VEH_UpdateMoveToGoalAircraft(gentity_t *ent, const vec3_t *goalPos)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
VEH_UpdateMoveToGoalBoat
==============
*/
void VEH_UpdateMoveToGoalBoat(gentity_t *ent, const vec3_t *goalPos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateHover
==============
*/
void VEH_UpdateHover(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateAIMove
==============
*/
void VEH_UpdateAIMove(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdatePath
==============
*/
void VEH_UpdatePath(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_Update
==============
*/
void VEH_Update(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_GetSeatExitPositionAndAngles
==============
*/
void VEH_GetSeatExitPositionAndAngles(gentity_t *vehicle, gentity_t *player, vec3_t *exitOrigin, vec3_t *exitViewAngles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UnseatPlayer
==============
*/
void VEH_UnseatPlayer(gentity_t *vehicle, gentity_t *player, bool remoteControlled, const char *error_msg, vec3_t *exitOrigin, vec3_t *exitViewAngles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_PlayerExit
==============
*/
void VEH_PlayerExit(gentity_t *vehicle, gentity_t *player, int unlinkReasonFlag, bool remoteControlled, const char *error_msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UnlinkPlayer
==============
*/
void VEH_UnlinkPlayer(gentity_t *player, int unlinkReasonFlag, const char *error_msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_FinishedAnimating
==============
*/
void VEH_FinishedAnimating(gentity_t *player, pmoveVehAnimState_t vehAnimState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_SwitchClientToSeat
==============
*/
void VEH_SwitchClientToSeat(gentity_t *ent, gentity_t *player, int seatIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_NextAvailableSeat
==============
*/
int VEH_NextAvailableSeat(gentity_t *player)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_SwitchClientToNextSeat
==============
*/
void __cdecl VEH_SwitchClientToNextSeat(gentity_t *ent, gentity_t *player)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_RinitVehiclesUsingInfo
==============
*/
void VEH_RinitVehiclesUsingInfo(int defIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateField
==============
*/
char VEH_UpdateField(const char *vehicleDefName, const char *keyValue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
G_FreeVehicle
==============
*/
void G_FreeVehicle(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_HideVehicle
==============
*/
void G_HideVehicle(gentity_t *ent)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
G_GetVehicleDefIndex
==============
*/
int G_GetVehicleDefIndex(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_IsRemoteControl
==============
*/
bool VEH_IsRemoteControl(gentity_t *vehEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
VEH_Teleport
==============
*/
void VEH_Teleport(unsigned int a1, gentity_t *pSelf, vec3_t *origin, vec3_t *angles, vec3_t *vel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateDebug
==============
*/
void VEH_UpdateDebug(char *a1, gentity_t *pSelf)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_Vehicle_Init
==============
*/
void Scr_Vehicle_Init(gentity_t *pSelf)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_AvoidUpdate
==============
*/
void VEH_AvoidUpdate(const gentity_t *pSelf, const vehicle_t *veh, NitrousVehicle *nitrousVeh, const float radius, const vec3_t *pos, const vec3_t *vel, float *goalSpeed, vec3_t *goal)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VEH_UpdateNitrousPosition
==============
*/
void VEH_UpdateNitrousPosition(unsigned int a1, char *a2, gentity_t *pSelf)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_Vehicle_Think
==============
*/
void Scr_Vehicle_Think(gentity_t *pSelf)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Launch_Vehicle
==============
*/
void Launch_Vehicle(gentity_t *ent, int damage, const vec3_t *point, const vec3_t *dir, int mod)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_Vehicle_Pain
==============
*/
void Scr_Vehicle_Pain(gentity_t *pSelf, gentity_t *pAttacker, int damage, const vec3_t *point, const int mod, const vec3_t *dir, const hitLocation_t hitLoc, const Weapon weapon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_Vehicle_Die
==============
*/
void Scr_Vehicle_Die(gentity_t *pSelf, gentity_t *pInflictor, gentity_t *pAttacker, const int damage, const int mod, const Weapon weapon, const vec3_t *dir, const hitLocation_t hitLoc, int timeOffset)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SP_script_vehicle
==============
*/
void SP_script_vehicle(gentity_t *pSelf, SpawnVar *spawnVar)
{
	UNIMPLEMENTED(__FUNCTION__);
}

