#include "types.h"
#include "functions.h"

/*
==============
Demo_GetAILockOnValues
==============
*/
AIDemoLockOnValues *Demo_GetAILockOnValues(centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Demo_GetAILockOnViewIndex
==============
*/
int Demo_GetAILockOnViewIndex(centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_GetCurrentFreeCameraMode
==============
*/
demoFreeCameraMode Demo_GetCurrentFreeCameraMode()
{
	UNIMPLEMENTED(__FUNCTION__);
	demoFreeCameraMode tmp;
	return tmp;
}

/*
==============
Demo_GetNextFreeCameraMode
==============
*/
demoFreeCameraMode Demo_GetNextFreeCameraMode(demoFreeCameraMode currentCameraMode, bool direction)
{
	UNIMPLEMENTED(__FUNCTION__);
	demoFreeCameraMode tmp;
	return tmp;
}

/*
==============
Demo_UpdateVisibilityBitsForCameraMode
==============
*/
void Demo_UpdateVisibilityBitsForCameraMode(LocalClientNum_t localClientNum, int cameraMode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_FreeCameraCalcView
==============
*/
void Demo_FreeCameraCalcView(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SaveView
==============
*/
void Demo_SaveView(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_IsThirdPersonCamera
==============
*/
bool Demo_IsThirdPersonCamera()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_IsAnyFreeMoveCamera
==============
*/
bool Demo_IsAnyFreeMoveCamera()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_IsMovieCamera
==============
*/
bool Demo_IsMovieCamera()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_IsDollyCamera
==============
*/
bool Demo_IsDollyCamera()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_IsCameraEditMode
==============
*/
bool Demo_IsCameraEditMode()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_GetHighlightedDollyCamMarker
==============
*/
int Demo_GetHighlightedDollyCamMarker()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_IsRepositioningDollyCamMarker
==============
*/
bool Demo_IsRepositioningDollyCamMarker()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_GetDollyCamMarkerCount
==============
*/
int Demo_GetDollyCamMarkerCount()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_GetDollyCamMarkerForTime
==============
*/
int Demo_GetDollyCamMarkerForTime(int serverTime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_GetOriginForDollyCamMarker
==============
*/
void Demo_GetOriginForDollyCamMarker(int index, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_GetAnglesForDollyCamMarker
==============
*/
void Demo_GetAnglesForDollyCamMarker(int index, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_GetTimeScaleModeForDollyCamMarker
==============
*/
demoDollyCameraTimeScaleMode Demo_GetTimeScaleModeForDollyCamMarker(int marker)
{
	UNIMPLEMENTED(__FUNCTION__);
	demoDollyCameraTimeScaleMode tmp;
	return tmp;
}

/*
==============
Demo_GetTimeScaleForDollyCamMarker
==============
*/
double Demo_GetTimeScaleForDollyCamMarker(int marker)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_GetInterpolatedTimeScaleForDollyCamMarker
==============
*/
double Demo_GetInterpolatedTimeScaleForDollyCamMarker(LocalClientNum_t localClientNum, int marker)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_IsFreeCameraEntityLockOnAllowed
==============
*/
bool Demo_IsFreeCameraEntityLockOnAllowed()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_GetHighlightedFreeCameraLockOnEntity
==============
*/
int Demo_GetHighlightedFreeCameraLockOnEntity()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_LerpClipCameraValues
==============
*/
void Demo_LerpClipCameraValues(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_RegisterDollyCameraFX
==============
*/
void Demo_RegisterDollyCameraFX()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_GetTimeForDollyCamMarker
==============
*/
int Demo_GetTimeForDollyCamMarker(int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_GetInterpolatedSplinePointAndAngles
==============
*/
void Demo_GetInterpolatedSplinePointAndAngles(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_GetDollyCamMarkerParameters
==============
*/
void Demo_GetDollyCamMarkerParameters(int marker, demoDollyCamFX *glowFXValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_ClearDollyCamMarkerFX
==============
*/
void Demo_ClearDollyCamMarkerFX(LocalClientNum_t localClientNum, int markerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_DrawDollyCamPoint
==============
*/
void Demo_DrawDollyCamPoint(LocalClientNum_t localClientNum, int markerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_DrawDollyCamTrack
==============
*/
void Demo_DrawDollyCamTrack()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_UpdateDollyCamera
==============
*/
void Demo_UpdateDollyCamera(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_WriteDollyCamKeyFrameInformation
==============
*/
void Demo_WriteDollyCamKeyFrameInformation(LocalClientNum_t localClientNum, int markerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_JumpToDollyCamKeyFrame
==============
*/
void Demo_JumpToDollyCamKeyFrame(LocalClientNum_t localClientNum, int markerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_ClearGhostDollyCam
==============
*/
void Demo_ClearGhostDollyCam(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_DrawGhostDollyCam
==============
*/
/*void Demo_DrawGhostDollyCam(int a1@<edx>, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Demo_ShouldUpdateFreeCamera
==============
*/
bool Demo_ShouldUpdateFreeCamera(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_DoesEntitySupportFreeCameraLockOn
==============
*/
bool Demo_DoesEntitySupportFreeCameraLockOn(centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_GetRenderFxFlagsForEntity
==============
*/
unsigned int Demo_GetRenderFxFlagsForEntity(centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_GetLockOnHighlightThresholdDistanceForEntity
==============
*/
float Demo_GetLockOnHighlightThresholdDistanceForEntity(centity_t *cent)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_UpdateLockOnCamera
==============
*/
void Demo_UpdateLockOnCamera(LocalClientNum_t localClientNum, usercmd_s *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_UpdateHighlightReelKillcamValues
==============
*/
void Demo_UpdateHighlightReelKillcamValues(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SwitchCameraMode
==============
*/
void Demo_SwitchCameraMode(LocalClientNum_t localClientNum, demoCameraMode newCamMode)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SwitchCamera
==============
*/
void Demo_SwitchCamera(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_SwitchFreeCamMode
==============
*/
void Demo_SwitchFreeCamMode(LocalClientNum_t localClientNum, demoFreeCameraMode anticlockwise)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_IsFreeCameraLockedOnEntity
==============
*/
bool Demo_IsFreeCameraLockedOnEntity()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_IsTimeScaleAdjustmentEnabled
==============
*/
bool Demo_IsTimeScaleAdjustmentEnabled(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Demo_RefreshAllDollyCamFX
==============
*/
void Demo_RefreshAllDollyCamFX(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_DrawDollyCamInformation
==============
*/
void Demo_DrawDollyCamInformation(LocalClientNum_t localClientNum, int infoEnum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_JumpToDollyCamMarkerTime
==============
*/
void Demo_JumpToDollyCamMarkerTime(LocalClientNum_t localClientNum, int markerNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_ApplyNewDollyCamMarkerPosition
==============
*/
void Demo_ApplyNewDollyCamMarkerPosition(LocalClientNum_t localClientNum, bool discardChanges)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_ClampViewAngleForLockedOnEntity
==============
*/
void Demo_ClampViewAngleForLockedOnEntity(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_UpdateLockOnCameraHighlight
==============
*/
void Demo_UpdateLockOnCameraHighlight(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Demo_FreeCameraViewTrace
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Demo_FreeCameraMove
==============
*/
void Demo_FreeCameraMove(LocalClientNum_t localClientNum, usercmd_s *cmd)
{
	UNIMPLEMENTED(__FUNCTION__);
}

