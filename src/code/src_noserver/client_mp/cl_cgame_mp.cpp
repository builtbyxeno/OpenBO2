#include "types.h"
#include "functions.h"

/*
==============
CL_GetScreenDimensions
==============
*/
void CL_GetScreenDimensions(int *width, int *height, float *aspect)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_GetScreenAspectRatioDisplayPixel
==============
*/
double CL_GetScreenAspectRatioDisplayPixel()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_GetUserCmd
==============
*/
int CL_GetUserCmd(LocalClientNum_t localClientNum, int cmdNumber, usercmd_s *ucmd)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_AdjustUserCmdAngles
==============
*/
void CL_AdjustUserCmdAngles(LocalClientNum_t localClientNum, int cmdNumber, vec3_t *adjust)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_GetCurrentCmdNumber
==============
*/
int CL_GetCurrentCmdNumber(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_GetCurrentSnapshotNumber
==============
*/
void CL_GetCurrentSnapshotNumber(LocalClientNum_t localClientNum, int *snapshotNumber, int *serverTime)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CheckEntityNumber
==============
*/
void CheckEntityNumber(const entityState_s *es, bool *foundArray)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_GetSnapshot
==============
*/
int CL_GetSnapshot(LocalClientNum_t localClientNum, int snapshotNumber, snapshot_s *snapshot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_SetUserCmdWeapons
==============
*/
void CL_SetUserCmdWeapons(LocalClientNum_t localClientNum, Weapon weapon, Weapon offHandWeapon, Weapon lastWeaponForAlt)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetUserCmdAimValues
==============
*/
void CL_SetUserCmdAimValues(LocalClientNum_t localClientNum, const vec3_t *kickAngles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetUserCmdOrigin
==============
*/
void CL_SetUserCmdOrigin(LocalClientNum_t localClientNum, const vec3_t *origin, const vec3_t *velocity, int bobCycle, int movementDir)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetUserCmdVehicle
==============
*/
void CL_SetUserCmdVehicle(LocalClientNum_t localClientNum, const PlayerVehicleState *playerVehState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetFOVSensitivityScale
==============
*/
void CL_SetFOVSensitivityScale(LocalClientNum_t localClientNum, float scale)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DumpReliableCommands
==============
*/
void CL_DumpReliableCommands(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetExpectedHunkUsage
==============
*/
void CL_SetExpectedHunkUsage(const char *mapname)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_CM_LoadMap
==============
*/
void CL_CM_LoadMap(const char *mapname)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_CM_LoadAddOnMapEnts
==============
*/
void CL_CM_LoadAddOnMapEnts(const char *addon_mapname)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ShutdownAllClientsCGame
==============
*/
void CL_ShutdownAllClientsCGame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DObjCreateSkelForBone
==============
*/
int CL_DObjCreateSkelForBone(DObj *obj, int boneIndex, DObjAnimMat **pMatOut)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_SubtitlePrint
==============
*/
void CL_SubtitlePrint(LocalClientNum_t localClientNum, const char *text, int duration, int lineWidth)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_GetConfigString
==============
*/
char *CL_GetConfigString(int configStringIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_GetConfigStringChecksum
==============
*/
unsigned int CL_GetConfigStringChecksum(int configStringBase, int configStringIndex, int indexBits)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_GetDebugViewForward
==============
*/
void CL_GetDebugViewForward(vec3_t *forward)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_GetDebugViewPos
==============
*/
void CL_GetDebugViewPos(vec3_t *pos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_RenderScene
==============
*/
void CL_RenderScene(const refdef_t *fd, int frameTime, const GfxViewParms *viewParmsDraw, const GfxViewParms *viewParmsDpvs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_RenderExtraCam
==============
*/
void CL_RenderExtraCam(const refdef_t *fd, int frameTime, const GfxExtraCamParms *extraCamParms)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetFullScreenViewport
==============
*/
void CL_SetFullScreenViewport()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetCustomConstant
==============
*/
void CL_SetCustomConstant(unsigned int type, const vec4_t *vec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawStretchPicPhysicalInternal
==============
*/
void CL_DrawStretchPicPhysicalInternal(float x, float y, float w, float h, float s1, float t1, float s2, float t2, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawStretchPicPhysicalDPInternal
==============
*/
void CL_DrawStretchPicPhysicalDPInternal(float x, float y, float w, float h, float s1, float t1, float s2, float t2, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawStretchPicPhysicalDPx2Internal
==============
*/
void CL_DrawStretchPicPhysicalDPx2Internal(float x, float y, float w, float h, float s1, float t1, float s2, float t2, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawStretchPicPhysicalWInternal
==============
*/
void CL_DrawStretchPicPhysicalWInternal(float x, float y, float w0, float w, float h, float s1, float t1, float s2, float t2, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawStretchPicPhysicalRotateXYInternal
==============
*/
void CL_DrawStretchPicPhysicalRotateXYInternal(float x, float y, float w, float h, float s1, float t1, float s2, float t2, float angle, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawStretchPicWDPInternal
==============
*/
void CL_DrawStretchPicWDPInternal(const ScreenPlacement *scrPlace, float x, float y, float w0, float w, float h, int horzAlign, int vertAlign, float s1, float t1, float s2, float t2, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawStretchPicInternal
==============
*/
void CL_DrawStretchPicInternal(const ScreenPlacement *scrPlace, float x, float y, float w, float h, int horzAlign, int vertAlign, float s1, float t1, float s2, float t2, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawStretchPicDPInternal
==============
*/
void CL_DrawStretchPicDPInternal(const ScreenPlacement *scrPlace, float x, float y, float w, float h, int horzAlign, int vertAlign, float s1, float t1, float s2, float t2, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawStretchPicRotatedSTInternal
==============
*/
void CL_DrawStretchPicRotatedSTInternal(const ScreenPlacement *scrPlace, float x, float y, float w, float h, int horzAlign, int vertAlign, float centerS, float centerT, float radiusST, float scaleFinalS, float scaleFinalT, float angle, const vec4_t *color, Material *material)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_CapTurnRate
==============
*/
void CL_CapTurnRate(LocalClientNum_t localClientNum, float maxPitchSpeed, float maxYawSpeed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetViewAngles
==============
*/
void CL_SetViewAngles(LocalClientNum_t localClientNum, const vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_AdjustViewAngles
==============
*/
void CL_AdjustViewAngles(LocalClientNum_t localClientNum, const vec3_t *adjust)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ClampViewAngle
==============
*/
void CL_ClampViewAngle(LocalClientNum_t localClientNum, const int angle, const float min, const float max)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetupScreenPlacements
==============
*/
void CL_SetupScreenPlacements()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_UpdateLevelHunkUsage
==============
*/
void CL_UpdateLevelHunkUsage()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_StartLoading
==============
*/
void CL_StartLoading()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_InitCGame
==============
*/
void CL_InitCGame(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_RestartCGame
==============
*/
void CL_RestartCGame(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ResetServerTimeDelta
==============
*/
void CL_ResetServerTimeDelta(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_AdjustTimeDelta
==============
*/
void CL_AdjustTimeDelta(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_FirstSnapshot
==============
*/
void CL_FirstSnapshot(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_ForceNewSnapshots
==============
*/
void CL_ForceNewSnapshots()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetCGameTime
==============
*/
void CL_SetCGameTime(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetADS
==============
*/
void CL_SetADS(LocalClientNum_t localClientNum, bool ads)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_DrawString
==============
*/
void CL_DrawString(int x, int y, const char *pszString, int bShadow, int iCharHeight)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_LookupColor
==============
*/
void CL_LookupColor(unsigned __int8 c, vec4_t *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_IsServerRestarting
==============
*/
bool CL_IsServerRestarting(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_FixupSmodelCullOutDists
==============
*/
void CL_FixupSmodelCullOutDists(const char *mapname)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetExtraButtons
==============
*/
/*void CL_SetExtraButtons(LocalClientNum_t localClientNum, bitarray<64> *button_bits)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
CL_ConfigstringModified
==============
*/
void CL_ConfigstringModified(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_CGameNeedsServerCommand
==============
*/
int CL_CGameNeedsServerCommand(LocalClientNum_t localClientNum, int serverCommandNumber)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_SyncTimes
==============
*/
void CL_SyncTimes(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
LoadWorld
==============
*/
int LoadWorld(const char *mapname)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

