#include "types.h"

/*
==============
InterpolateAnglesSmooth
==============
*/
void InterpolateAnglesSmooth(vec3_t *curAngles, const vec3_t *initialAngles, const vec3_t *targetAngles, float t)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_StartCameraTween
==============
*/
void CG_StartCameraTween(LocalClientNum_t localClientNum, float tweenTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateCameraTweenFOV
==============
*/
float CG_UpdateCameraTweenFOV(LocalClientNum_t localClientNum, float currentFov)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_UpdateCameraTween
==============
*/
void CG_UpdateCameraTween(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateVehicleInitView
==============
*/
void CG_UpdateVehicleInitView(LocalClientNum_t localClientNum, CameraMode newMode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_SetSoundFutz
==============
*/
void CG_SetSoundFutz(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateSoundFutz
==============
*/
void CG_UpdateSoundFutz(LocalClientNum_t localClientNum, CameraMode newMode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateCameraTransition
==============
*/
void CG_UpdateCameraTransition(LocalClientNum_t localClientNum, CameraMode oldMode, CameraMode newMode, bool useTagCamera)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RemapVehicleButton
==============
*/
int CG_RemapVehicleButton(LocalClientNum_t localClientNum, int *twokeys, int button, Bind_t vehicleBinding)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_UpdateVehicleBindings
==============
*/
void __cdecl CG_UpdateVehicleBindings(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RenderPlayerFromMissilePOV
==============
*/
bool CG_RenderPlayerFromMissilePOV(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_SpikeCameraViewActive
==============
*/
bool CG_SpikeCameraViewActive(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_ScriptedExtraCamActive
==============
*/
bool CG_ScriptedExtraCamActive(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_ScriptedExtraCamFov
==============
*/
float CG_ScriptedExtraCamFov(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ShouldDoCameraTransition
==============
*/
char ShouldDoCameraTransition(cg_t *cgameGlob, CameraMode prevMode, CameraMode newMode, bool useTagCamera)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ShouldDoThirdPersonVehicle
==============
*/
char ShouldDoThirdPersonVehicle(LocalClientNum_t localClientNum, const cg_t *cgameGlob, const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_UpdateCameraMode
==============
*/
CameraMode CG_UpdateCameraMode(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	CameraMode tmp;
	return tmp;
}

/*
==============
CG_GetExtraCamMode
==============
*/
CameraMode CG_GetExtraCamMode(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	CameraMode tmp;
	return tmp;
}

/*
==============
CG_ApplyViewAnimation
==============
*/
void CG_ApplyViewAnimation(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ShouldDefaultViewFov
==============
*/
bool CG_ShouldDefaultViewFov(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetWeaponViewFov
==============
*/
float CG_GetWeaponViewFov(LocalClientNum_t localClientNum, const playerState_s *ps, Weapon weapon, float viewFov, bool forWeapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetTurretViewFov
==============
*/
double CG_GetTurretViewFov(LocalClientNum_t localClientNum, const playerState_s *ps)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetViewFov
==============
*/
float CG_GetViewFov(LocalClientNum_t localClientNum, const playerState_s *forWeapon)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CalcFovInternal
==============
*/
void CG_CalcFovInternal(LocalClientNum_t localClientNum, bool forWeapon, float *fov_x, float *dxDzAtDefaultAspectRatio, float *dxDz, float *dyDz)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalcFov
==============
*/
void __cdecl CG_CalcFov(LocalClientNum_t localClientNum, float fov_x)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalculateGunnerOffset_Sway
==============
*/
void CG_CalculateGunnerOffset_Sway(const vec3_t *playerViewAngles, Weapon weapon, vec3_t *swayViewAngles, vec3_t *swayOffset, vec3_t *swayAngles, float ssSwayScale, int frametime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_OffsetVehicleGunner
==============
*/
void __cdecl CG_OffsetVehicleGunner(LocalClientNum_t localClientNum, cg_t *cgameGlob)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_GetExtraCamOrigin
==============
*/
void CG_GetExtraCamOrigin(LocalClientNum_t localClientNum, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalcExtraCamViewValues
==============
*/
void CG_CalcExtraCamViewValues(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RemoteEyesShake
==============
*/
void RemoteEyesShake(cg_t *cgameGlob, centity_t *possessedEnt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetWeaponviewEyeValues
==============
*/
bool GetWeaponviewEyeValues(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_GetMissileViewOrigin
==============
*/
void CG_GetMissileViewOrigin(LocalClientNum_t localClientNum, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalcScriptedExtraCamViewValues
==============
*/
void CG_CalcScriptedExtraCamViewValues(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalcMissileAngleValues
==============
*/
void CG_CalcMissileAngleValues(float localClientNum, LocalClientNum_t a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Player3rdPersonVehicle_GetPitchOffsetRelativeToADirection
==============
*/
long double CG_Player3rdPersonVehicle_GetPitchOffsetRelativeToADirection(const vec3_t *angles, vec3_t *direction)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Player3rdPersonVehicle_GetViewAngles
==============
*/
bool CG_Player3rdPersonVehicle_GetViewAngles(const cg_t *cgameGlob, const playerState_s *ps, const centity_t *vehicle, const VehicleDef *info, const vec3_t *lookAtPos, vec3_t *angles, bool setPlayerAngles, bool lerpViewBackToForward)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Player3rdPersonVehicle_GetLookAtPosition
==============
*/
void CG_Player3rdPersonVehicle_GetLookAtPosition(const centity_t *vehicle, const VehicleDef *info, vec3_t *origin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Player3rdPersonVehicle_GetDampedSpringDistance
==============
*/
float CG_Player3rdPersonVehicle_GetDampedSpringDistance(cg_t *cgameGlob, const centity_t *vehicle, const VehicleDef *info, float camDefaultDist)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Get3rdPersonVehicleMask
==============
*/
int CG_Get3rdPersonVehicleMask(int vehicleType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_OffsetVehicleView
==============
*/
void CG_OffsetVehicleView(LocalClientNum_t localClientNum, CameraMode camMode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ScrCamActive
==============
*/
int CG_ScrCamActive(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_ScrCamCalcView
==============
*/
void CG_ScrCamCalcView(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ExtraCamDebug_SetView
==============
*/
void CG_ExtraCamDebug_SetView(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ExtraCamDebug_SaveView
==============
*/
void CG_ExtraCamDebug_SaveView(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalcFov_ExtraCam
==============
*/
void CG_CalcFov_ExtraCam(float localClientNum, LocalClientNum_t a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
InScriptExtraCamDebugMode3
==============
*/
BOOL InScriptExtraCamDebugMode3()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_ExtraCam_GetViewOrigin
==============
*/
void CG_ExtraCam_GetViewOrigin(LocalClientNum_t localClientNum, ExtraCamLodInfo *extraCamLodInfo)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_UpdateScriptExtraCams
==============
*/
void CG_UpdateScriptExtraCams(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ResetScriptExtraCam
==============
*/
void CG_ResetScriptExtraCam(ScriptExtraCam *scriptExtraCam)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ExtraCamIsActive
==============
*/
bool CG_ExtraCamIsActive(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_IsUsingMultiExtraCam
==============
*/
BOOL CG_IsUsingMultiExtraCam(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ExtraCamClientStateRestore::ExtraCamClientStateRestore
==============
*/
/*void ExtraCamClientStateRestore::ExtraCamClientStateRestore(ExtraCamClientStateRestore *notthis, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
ExtraCamClientStateRestore::~ExtraCamClientStateRestore
==============
*/
/*void ExtraCamClientStateRestore::~ExtraCamClientStateRestore(ExtraCamClientStateRestore *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
CG_GetClientExtraCamParms
==============
*/
void CG_GetClientExtraCamParms(LocalClientNum_t localClientNum, GfxExtraCamParms *extraCamParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CaptureCameraOffset
==============
*/
void CG_CaptureCameraOffset(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ThirdPersonViewTrace
==============
*/
double ThirdPersonViewTrace(unsigned int a1, cg_t *cgameGlob, const vec3_t *start, const vec3_t *end, int contentMask, vec3_t *result, bool pitch_up, bool ignoreStartSolid)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CalcMissileViewValues
==============
*/
void CG_CalcMissileViewValues(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_ShouldVehicleCamAutoRecenter
==============
*/
bool CG_ShouldVehicleCamAutoRecenter(LocalClientNum_t localClientNum, const VehicleDef *info)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CalcVehicleViewValues
==============
*/
void CG_CalcVehicleViewValues(char *a1, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Calc3rdPersonVehicleViewValues
==============
*/
void CG_Calc3rdPersonVehicleViewValues(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_RadiantCamCalcView
==============
*/
void CG_RadiantCamCalcView(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetRemoteEyeValues
==============
*/
char GetRemoteEyeValues(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_CalcRemoteEyesViewValues
==============
*/
bool CG_CalcRemoteEyesViewValues(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

