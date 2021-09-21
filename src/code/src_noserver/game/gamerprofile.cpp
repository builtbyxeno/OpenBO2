#include "types.h"
#include "functions.h"

/*
==============
GamerProfile_GetSettingByName
==============
*/
int GamerProfile_GetSettingByName(const char *settingName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamerProfile_LookupKey
==============
*/
bool GamerProfile_LookupKey(profile_setting setting, ControllerIndex_t controllerIndex, ddlState_t *outState, unsigned __int8 **outBuffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamerProfile_Get_f
==============
*/
void GamerProfile_Get_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_IsValidProfileVariable
==============
*/
bool GamerProfile_IsValidProfileVariable(const char *settingName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamerProfile_GetInt
==============
*/
unsigned int GamerProfile_GetInt(ControllerIndex_t a1, profile_setting setting)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamerProfile_GetBool
==============
*/
BOOL GamerProfile_GetBool(ControllerIndex_t a1, profile_setting setting)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamerProfile_GetFloat
==============
*/
double GamerProfile_GetFloat(ControllerIndex_t a1, profile_setting setting)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamerProfile_GetString
==============
*/
const GfxViewParms *GamerProfile_GetString(ControllerIndex_t a1, char *a2, profile_setting setting)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GamerProfile_GetInt
==============
*/
unsigned int GamerProfile_GetInt(const char *settingName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamerProfile_GetFloat
==============
*/
double GamerProfile_GetFloat(const char *setting)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamerProfile_GetString
==============
*/
const GfxViewParms *GamerProfile_GetString(const char *settingName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GamerProfile_GetArrayString
==============
*/
const GfxViewParms *GamerProfile_GetArrayString(const char *settingName, ControllerIndex_t controllerIndex, int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GamerProfile_GetArrayInt
==============
*/
unsigned int GamerProfile_GetArrayInt(const char *settingName, ControllerIndex_t controllerIndex, int index)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamerProfile_GetGlobalProfileBool
==============
*/
bool GamerProfile_GetGlobalProfileBool(profile_setting setting)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamerProfile_GetTeamIndicator
==============
*/
unsigned int GamerProfile_GetTeamIndicator(int a1, ControllerIndex_t a2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamerProfile_GetColorBlindAssist
==============
*/
char GamerProfile_GetColorBlindAssist(int a1, ControllerIndex_t a2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamerProfile_UpdateButtonConfig
==============
*/
void GamerProfile_UpdateButtonConfig(ControllerIndex_t controllerIndex, int gpadButtonsConfig)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_UpdateStickConfig
==============
*/
void GamerProfile_UpdateStickConfig(ControllerIndex_t controllerIndex, int gpadSticksConfig)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_ExecuteFloatCallback
==============
*/
void GamerProfile_ExecuteFloatCallback(profile_setting setting, ControllerIndex_t controllerIndex, float newValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_SetFloat_Internal
==============
*/
bool GamerProfile_SetFloat_Internal(ControllerIndex_t controllerIndex, ddlState_t *profileItemState, float newValue, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamerProfile_SetString_Internal
==============
*/
bool GamerProfile_SetString_Internal(ControllerIndex_t controllerIndex, ddlState_t *profileItemState, const char *newValue, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamerProfile_SetString
==============
*/
void GamerProfile_SetString(ControllerIndex_t a1, char *a2, profile_setting setting, ControllerIndex_t controllerIndex, const char *newValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_CopyProfileEntry
==============
*/
void GamerProfile_CopyProfileEntry(ControllerIndex_t a1, char *a2, profile_setting setting)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_GetVariableAsString
==============
*/
char *GamerProfile_GetVariableAsString(char *a1, const char *settingName, ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
TRACK_gamerprofile
==============
*/
void TRACK_gamerprofile()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_IsProfileLoggedIn
==============
*/
bool GamerProfile_IsProfileLoggedIn(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamerProfile_IsProfileInitialized
==============
*/
bool GamerProfile_IsProfileInitialized(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamerProfile_WasErrorOnRead
==============
*/
bool GamerProfile_WasErrorOnRead(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DebugReportProfileVars
==============
*/
void DebugReportProfileVars(ControllerIndex_t controllerIndex, const char *headerMsg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_SetLocClassCmd
==============
*/
void GamerProfile_SetLocClassCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_SetClassVersion
==============
*/
void GamerProfile_SetClassVersion(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_SetupInitialClasses
==============
*/
void GamerProfile_SetupInitialClasses(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_ExecControllerBindings
==============
*/
void GamerProfile_ExecControllerBindings(ControllerIndex_t a1, ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_AreBothBuffersInitialized
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
GamerProfile_InitAllProfiles
==============
*/
void GamerProfile_InitAllProfiles()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_GetCACRoot
==============
*/
const CACRoot *GamerProfile_GetCACRoot(const CACRoot *result, const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GamerProfile_GetCACRoot
==============
*/
const CACRoot *GamerProfile_GetCACRoot(const CACRoot *result, unsigned __int8 *buffer)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GamerProfile_GetExeSettingsSize
==============
*/
int GamerProfile_GetExeSettingsSize()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamerProfile_GetExeSettingsBuffer
==============
*/
unsigned __int8 *GamerProfile_GetExeSettingsBuffer(const ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
GamerProfile_ExecuteIntCallback
==============
*/
void GamerProfile_ExecuteIntCallback(profile_setting setting, ControllerIndex_t controllerIndex, int newValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_SetInt_Internal
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
GamerProfile_SetInt
==============
*/
void GamerProfile_SetInt(ControllerIndex_t a1, profile_setting setting, ControllerIndex_t controllerIndex, int newValue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_SetBool
==============
*/
void GamerProfile_SetBool(profile_setting setting, ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_SetVariableFromString_Internal
==============
*/
bool GamerProfile_SetVariableFromString_Internal(const char *settingName, ControllerIndex_t controllerIndex, int index, const char *settingValue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GamerProfile_SetVariableFromString
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
GamerProfile_SetArrayVariableFromString
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
GamerProfile_ResetCommonVarsToDefault
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
GamerProfile_ResetExeVarsToDefault
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
GamerProfile_SaveChanges
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
GamerProfile_SaveChangesCmd
==============
*/
void GamerProfile_SaveChangesCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_RunCallbacks
==============
*/
void GamerProfile_RunCallbacks(int a1, ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_ResetProfile
==============
*/
void GamerProfile_ResetProfile(ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_InitProfileWithoutSignin
==============
*/
void GamerProfile_InitProfileWithoutSignin(int a1, ControllerIndex_t controllerIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GamerProfile_Set_f
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
GamerProfile_Reset_f
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
GamerProfile_InitOnce
==============
*/
void GamerProfile_InitOnce()
{
	UNIMPLEMENTED(__FUNCTION__);
}
