#include "types.h"
#include "functions.h"

/*
==============
InterpolateAnglesSmooth
==============
*/
void InterpolateAnglesSmooth(
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
void CG_UpdateCameraTransition(
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
void CG_UpdateVehicleBindings(LocalClientNum_t localClientNum)
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
char ShouldDoThirdPersonVehicle(
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
float CG_GetWeaponViewFov(
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
void CG_CalcFovInternal(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalcFov
==============
*/
void CG_CalcFov(LocalClientNum_t localClientNum, float fov_x)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_CalculateGunnerOffset_Sway
==============
*/
void CG_CalculateGunnerOffset_Sway(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_OffsetVehicleGunner
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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
/*void CG_CalcMissileAngleValues(float a1@<esi>, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
CG_Player3rdPersonVehicle_GetPitchOffsetRelativeToADirection
==============
*/
long double CG_Player3rdPersonVehicle_GetPitchOffsetRelativeToADirection(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Player3rdPersonVehicle_GetViewAngles
==============
*/
bool CG_Player3rdPersonVehicle_GetViewAngles(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_Player3rdPersonVehicle_GetLookAtPosition
==============
*/
void CG_Player3rdPersonVehicle_GetLookAtPosition(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_Player3rdPersonVehicle_GetDampedSpringDistance
==============
*/
float CG_Player3rdPersonVehicle_GetDampedSpringDistance(
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
/*void CG_CalcFov_ExtraCam(float a1@<xmm0>, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

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
/*void __thiscall ExtraCamClientStateRestore::ExtraCamClientStateRestore(
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
ExtraCamClientStateRestore::~ExtraCamClientStateRestore
==============
*/
/*void __thiscall ExtraCamClientStateRestore::~ExtraCamClientStateRestore(ExtraCamClientStateRestore *this)
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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
void CG_CalcVehicleViewValues(LocalClientNum_t localClientNum)
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

