#include "types.h"
#include "functions.h"

/*
==============
CG_RegisterVisionSetsDvars
==============
*/
void CG_RegisterVisionSetsDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RawBufferOpen
==============
*/
const char *RawBufferOpen(const char *path, const char *backupPath)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
ApplyTokenToField
==============
*/
bool ApplyTokenToField(int fieldNum, const char *token, visionSetVars_t *settings)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LoadVisionSettingsFromBuffer
==============
*/
bool LoadVisionSettingsFromBuffer(const char *buffer, const char *filename, visionSetVars_t *settings)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LoadVisionFile
==============
*/
bool LoadVisionFile(const char *name, visionSetVars_t *resultSettings)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetVisionSet
==============
*/
bool GetVisionSet(LocalClientNum_t localClientNum, const char *name, visionSetVars_t *resultSettings)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LerpBool
==============
*/
bool LerpBool(bool from, bool to, float fraction, visionSetLerpStyle_t style)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LerpInteger
==============
*/
int LerpInteger(int from, int to, const float fraction, visionSetLerpStyle_t style)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LerpStepFloat
==============
*/
float LerpStepFloat(float from, float to, const float fraction, visionSetLerpStyle_t style)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LerpFloat
==============
*/
float LerpFloat(float from, float to, float fraction, visionSetLerpStyle_t style)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LerpVec4
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
VisionSetCurrent
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_VisionSetStartLerp_To
==============
*/
bool CG_VisionSetStartLerp_To(LocalClientNum_t localClientNum, visionSetMode_t mode, visionSetLerpStyle_t style, const char *nameTo, int duration)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_VisionSetLerp_To
==============
*/
char CG_VisionSetLerp_To(const char *a1, char *a2, LocalClientNum_t localClientNum, visionSetMode_t mode, visionSetLerpStyle_t style, const char *nameTo, const char *nameFrom, float lerpFraction)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SetDefaultVision
==============
*/
void SetDefaultVision(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_VisionSetConfigString_Naked
==============
*/
void CG_VisionSetConfigString_Naked(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_VisionSetConfigString_Night
==============
*/
void CG_VisionSetConfigString_Night(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_VisionSetConfigString_LastStand
==============
*/
void CG_VisionSetConfigString_LastStand(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_VisionSetMyChanges
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_InLastStandVision
==============
*/
bool CG_InLastStandVision(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_InFlareVision
==============
*/
bool CG_InFlareVision(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CG_LookingThroughNightVision
==============
*/
char CG_LookingThroughNightVision(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DrawVisionSetDebug
==============
*/
void DrawVisionSetDebug(LocalClientNum_t localClientNum, visionSetMode_t curChannel)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_VisionSetApplyToRefdef
==============
*/
void CG_VisionSetApplyToRefdef(LocalClientNum_t localClientNum, bool isExtracam)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UpdateVarsLerpCustom
==============
*/
void UpdateVarsLerpCustom(float lerpFraction, const visionSetVars_t *from, const visionSetVars_t *to, visionSetLerpData_t *lerpData, visionSetVars_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UpdateVarsLerp
==============
*/
void UpdateVarsLerp(visionSetLerpStyle_t a1, int time, const visionSetVars_t *from, const visionSetVars_t *to, visionSetLerpData_t *lerpData, visionSetVars_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_InitVisionSets
==============
*/
void CG_InitVisionSets(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_VisionSetsUpdate
==============
*/
/*void CG_VisionSetsUpdate(char *a1@<edi>, LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
LoadVisionFileForTweaks
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
CG_VisionSetUpdateTweaksFromFile_Film
==============
*/
void CG_VisionSetUpdateTweaksFromFile_Film()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_VisionSetUpdateTweaksFromFile_CharPrimary
==============
*/
void CG_VisionSetUpdateTweaksFromFile_CharPrimary()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CG_VisionSetUpdateTweaksFromFile_Bloom
==============
*/
void CG_VisionSetUpdateTweaksFromFile_Bloom()
{
	UNIMPLEMENTED(__FUNCTION__);
}

