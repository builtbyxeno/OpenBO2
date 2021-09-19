#include "types.h"
#include "functions.h"

/*
==============
TRACK_dvar
==============
*/
void TRACK_dvar()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetInAutoExec
==============
*/
void Dvar_SetInAutoExec(bool inAutoExec)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_IsSystemActive
==============
*/
bool Dvar_IsSystemActive()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_IsValidName
==============
*/
char Dvar_IsValidName(const char *dvarName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_CopyString
==============
*/
void Dvar_CopyString(const char *string, DvarValue *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_WeakCopyString
==============
*/
void Dvar_WeakCopyString(const char *string, DvarValue *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_ShouldFreeCurrentString
==============
*/
bool Dvar_ShouldFreeCurrentString(dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_ShouldFreeLatchedString
==============
*/
bool Dvar_ShouldFreeLatchedString(dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_ShouldFreeResetString
==============
*/
bool Dvar_ShouldFreeResetString(dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_FreeString
==============
*/
void Dvar_FreeString(DvarValue *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_AssignCurrentStringValue
==============
*/
void Dvar_AssignCurrentStringValue(dvar_t *dvar, DvarValue *dest, const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_AssignLatchedStringValue
==============
*/
void Dvar_AssignLatchedStringValue(dvar_t *dvar, DvarValue *dest, const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_AssignResetStringValue
==============
*/
void Dvar_AssignResetStringValue(dvar_t *dvar, DvarValue *dest, const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_EnumToString
==============
*/
const GfxViewParms *Dvar_EnumToString(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_IndexStringToEnumString
==============
*/
const GfxViewParms *Dvar_IndexStringToEnumString(const dvar_t *dvar, const char *indexString)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_ValueToString
==============
*/
const char *Dvar_ValueToString(const dvar_t *dvar, DvarValue value)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_StringToBool
==============
*/
bool Dvar_StringToBool(const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_StringToInt
==============
*/
int Dvar_StringToInt(const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_StringToInt64
==============
*/
__int64 Dvar_StringToInt64(const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_StringToFloat
==============
*/
float Dvar_StringToFloat(const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_StringToVec2
==============
*/
void Dvar_StringToVec2(const char *string, vec2_t *vector)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_StringToVec3
==============
*/
void Dvar_StringToVec3(const char *string, vec3_t *vector)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_StringToVec4
==============
*/
void Dvar_StringToVec4(const char *string, vec4_t *vector)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_StringToEnum
==============
*/
int Dvar_StringToEnum(const DvarLimits *domain, const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_StringToColor
==============
*/
void Dvar_StringToColor(const char *string, unsigned __int8 *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_StringToValue
==============
*/
DvarValue *Dvar_StringToValue(const dvarType_t type, const DvarLimits domain, const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_DisplayableValue
==============
*/
const char *Dvar_DisplayableValue(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_DisplayableResetValue
==============
*/
const char *Dvar_DisplayableResetValue(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_DisplayableLatchedValue
==============
*/
const char *Dvar_DisplayableLatchedValue(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_ClampValueToDomain
==============
*/
DvarValue *Dvar_ClampValueToDomain(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_ValueInDomain
==============
*/
bool Dvar_ValueInDomain(dvarType_t type, DvarValue value, DvarLimits domain)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_VectorDomainToString
==============
*/
void Dvar_VectorDomainToString(int components, DvarLimits domain, char *outBuffer, int outBufferLen)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_DomainToString_Internal
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Dvar_DomainToString_GetLines
==============
*/
/*const char *Dvar_DomainToString_GetLines@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
Dvar_PrintDomain
==============
*/
/*void Dvar_PrintDomain(char *a1@<edx>, dvarType_t type, DvarLimits domain)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Dvar_ValuesEqual
==============
*/
int Dvar_ValuesEqual(dvarType_t type, DvarValue val0, DvarValue val1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_SetLatchedValue
==============
*/
void Dvar_SetLatchedValue(dvar_t *dvar, DvarValue value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_HasLatchedValue
==============
*/
BOOL Dvar_HasLatchedValue(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
findCallBackForDvar
==============
*/
dvarCallBack_t *findCallBackForDvar(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_FindMalleableVar
==============
*/
dvar_t *Dvar_FindMalleableVar(int dvarHash)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_FindVar
==============
*/
dvar_t *Dvar_FindVar(const char *dvarName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_FindVar
==============
*/
dvar_t *__thiscall Dvar_FindVar(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_ClearModified
==============
*/
void Dvar_ClearModified(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetModified
==============
*/
void Dvar_SetModified(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_GetModified
==============
*/
bool Dvar_GetModified(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetInt
==============
*/
dvar_t *__thiscall Dvar_GetInt(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_GetUnsignedInt
==============
*/
const dvar_t *Dvar_GetUnsignedInt(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_GetFloat
==============
*/
double __thiscall Dvar_GetFloat(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetVec2
==============
*/
void Dvar_GetVec2(const dvar_t *dvar, vec2_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_GetVec3
==============
*/
void Dvar_GetVec3(const dvar_t *dvar, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_GetVec4
==============
*/
void Dvar_GetVec4(const dvar_t *dvar, vec4_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_GetString
==============
*/
const GfxViewParms *Dvar_GetString(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_GetVariantString
==============
*/
const char *__thiscall Dvar_GetVariantString(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_GetVariantString
==============
*/
const char *Dvar_GetVariantString(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_GetUnpackedColor
==============
*/
void Dvar_GetUnpackedColor(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_GetColor
==============
*/
void Dvar_GetColor(const dvar_t *dvar, unsigned __int8 *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_GetColorRed
==============
*/
/*double Dvar_GetColorRed@<st0>(unsigned __int8 *a1@<edx>, const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
Dvar_GetColorRed
==============
*/
double __thiscall Dvar_GetColorRed(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetColorGreen
==============
*/
/*double Dvar_GetColorGreen@<st0>(unsigned __int8 *a1@<edx>, const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
Dvar_GetColorGreen
==============
*/
double __thiscall Dvar_GetColorGreen(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetColorBlue
==============
*/
/*double Dvar_GetColorBlue@<st0>(unsigned __int8 *a1@<edx>, const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
Dvar_GetColorBlue
==============
*/
double __thiscall Dvar_GetColorBlue(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetColorAlpha
==============
*/
/*double Dvar_GetColorAlpha@<st0>(unsigned __int8 *a1@<edx>, const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
Dvar_GetColorAlpha
==============
*/
double __thiscall Dvar_GetColorAlpha(void *this)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetLatchedBool
==============
*/
bool Dvar_GetLatchedBool(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetLatchedInt
==============
*/
int Dvar_GetLatchedInt(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetLatchedFloat
==============
*/
double Dvar_GetLatchedFloat(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetLatchedVec2
==============
*/
void Dvar_GetLatchedVec2(const dvar_t *dvar, vec2_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_GetLatchedVec3
==============
*/
void Dvar_GetLatchedVec3(const dvar_t *dvar, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_GetLatchedVec4
==============
*/
void Dvar_GetLatchedVec4(const dvar_t *dvar, vec4_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_GetLatchedColor
==============
*/
void Dvar_GetLatchedColor(const dvar_t *dvar, unsigned __int8 *color)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_GetResetInt
==============
*/
int Dvar_GetResetInt(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetResetString
==============
*/
const char *Dvar_GetResetString(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_GetResetVec3
==============
*/
void Dvar_GetResetVec3(const dvar_t *dvar, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_GetDomainEnumStrings
==============
*/
const char **Dvar_GetDomainEnumStrings(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_GetDomainEnumStringCount
==============
*/
int Dvar_GetDomainEnumStringCount(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetDomainIntMin
==============
*/
int Dvar_GetDomainIntMin(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetDomainIntMax
==============
*/
int Dvar_GetDomainIntMax(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetDomainInt64Min
==============
*/
__int64 Dvar_GetDomainInt64Min(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetDomainInt64Max
==============
*/
__int64 Dvar_GetDomainInt64Max(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetDomainFloatMin
==============
*/
double Dvar_GetDomainFloatMin(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetDomainFloatMax
==============
*/
double Dvar_GetDomainFloatMax(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetDomainVecMin
==============
*/
double Dvar_GetDomainVecMin(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetDomainVecMax
==============
*/
double Dvar_GetDomainVecMax(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetType
==============
*/
dvarType_t Dvar_GetType(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	dvarType_t tmp;
	return tmp;
}

/*
==============
Dvar_GetCurrent
==============
*/
DvarValue *Dvar_GetCurrent(DvarValue *result, const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_GetDomain
==============
*/
DvarLimits *Dvar_GetDomain(DvarLimits *result, const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_GetDescription
==============
*/
const char *Dvar_GetDescription(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_GetFlags
==============
*/
const dvar_t *Dvar_GetFlags(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_GetName
==============
*/
const char *Dvar_GetName(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_Shutdown
==============
*/
void Dvar_Shutdown()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_PerformUnregistration
==============
*/
void Dvar_PerformUnregistration(dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_UpdateResetValue
==============
*/
void Dvar_UpdateResetValue(dvar_t *dvar, DvarValue value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_ChangeResetValue
==============
*/
void Dvar_ChangeResetValue(const dvar_t *dvar, DvarValue value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_UpdateValue
==============
*/
void Dvar_UpdateValue(dvar_t *dvar, DvarValue value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_MakeExplicitType
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Dvar_ReinterpretDvar
==============
*/
void Dvar_ReinterpretDvar(
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_RegisterNew
==============
*/
const dvar_t *Dvar_RegisterNew(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_AddFlags
==============
*/
void Dvar_AddFlags(const dvar_t *dvar, int flags)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_SaveDvarsToBuffer
==============
*/
int Com_SaveDvarsToBuffer(const char **dvarnames, unsigned int numDvars, char *buffer, unsigned int bufsize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_SetModifiedCallback
==============
*/
void Dvar_SetModifiedCallback(const dvar_t *dvar, void (*callback)(const dvar_t *))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetCanSetConfigDvars
==============
*/
void Dvar_SetCanSetConfigDvars(bool canSetConfigDvars)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_CanSetConfigDvar
==============
*/
bool Dvar_CanSetConfigDvar(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_CanChangeValue
==============
*/
bool Dvar_CanChangeValue(const dvar_t *dvar, DvarValue value, DvarSetSource source)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_SetVariant
==============
*/
void Dvar_SetVariant(dvar_t *dvar, DvarValue value, DvarSetSource source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_UpdateEnumDomain
==============
*/
void Dvar_UpdateEnumDomain(const dvar_t *dvar, const char **stringTable)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_GetBool
==============
*/
bool Dvar_GetBool(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetInt
==============
*/
int Dvar_GetInt(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetInt64
==============
*/
int Dvar_GetInt64(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_GetFloat
==============
*/
double Dvar_GetFloat(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_MakeLatchedValueCurrent
==============
*/
void Dvar_MakeLatchedValueCurrent(const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_Reregister
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Dvar_RegisterVariant
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
_Dvar_RegisterBool
==============
*/
const dvar_t *_Dvar_RegisterBool(const char *dvarName, bool value, unsigned int flags, const char *description)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
_Dvar_RegisterInt
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
_Dvar_RegisterInt64
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
_Dvar_RegisterFloat
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
_Dvar_RegisterVec2
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
_Dvar_RegisterVec3
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
_Dvar_RegisterVec4
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
_Dvar_RegisterString
==============
*/
/*const dvar_t *_Dvar_RegisterString@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
_Dvar_RegisterEnum
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
_Dvar_RegisterColor
==============
*/
const dvar_t *_Dvar_RegisterColor(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
_Dvar_RegisterLinearRGB
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
_Dvar_RegisterColorXYZ
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Dvar_SetBoolFromSource
==============
*/
void Dvar_SetBoolFromSource(const dvar_t *dvar, bool value, DvarSetSource source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetIntFromSource
==============
*/
void Dvar_SetIntFromSource(const dvar_t *dvar, int value, DvarSetSource source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetInt64FromSource
==============
*/
void Dvar_SetInt64FromSource(const dvar_t *dvar, __int64 value, DvarSetSource source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetFloatFromSource
==============
*/
void Dvar_SetFloatFromSource(const dvar_t *dvar, float value, DvarSetSource source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetVec2FromSource
==============
*/
void Dvar_SetVec2FromSource(const dvar_t *dvar, float x, float y, DvarSetSource source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetVec3FromSource
==============
*/
void Dvar_SetVec3FromSource(const dvar_t *dvar, float x, float y, float z, DvarSetSource source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetVec4FromSource
==============
*/
void Dvar_SetVec4FromSource(const dvar_t *dvar, float x, float y, float z, float w, DvarSetSource source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetStringFromSource
==============
*/
void Dvar_SetStringFromSource(const dvar_t *dvar, const char *string, DvarSetSource source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetColorFromSource
==============
*/
void Dvar_SetColorFromSource(const dvar_t *dvar, float r, float g, float b, float a, DvarSetSource source)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetBool
==============
*/
void Dvar_SetBool(const dvar_t *dvar, bool value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetInt
==============
*/
void Dvar_SetInt(const dvar_t *dvar, int value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetFloat
==============
*/
void Dvar_SetFloat(const dvar_t *dvar, float value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetVec2
==============
*/
void Dvar_SetVec2(const dvar_t *dvar, float x, float y)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetVec3
==============
*/
void Dvar_SetVec3(const dvar_t *dvar, float x, float y, float z)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetVec4
==============
*/
void Dvar_SetVec4(const dvar_t *dvar, float x, float y, float z, float w)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetVec4FromVec4
==============
*/
void Dvar_SetVec4FromVec4(const dvar_t *dvar, vec4_t *vecin)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetString
==============
*/
/*void Dvar_SetString(const char *a1@<edx>, const dvar_t *a2@<ecx>, const dvar_t *dvar, const char *value)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Dvar_SetOrRegisterString
==============
*/
/*const dvar_t *Dvar_SetOrRegisterString@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
Dvar_SetColor
==============
*/
void Dvar_SetColor(const dvar_t *dvar, float r, float g, float b, float a)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetFromStringFromSource
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Dvar_SetFromString
==============
*/
void Dvar_SetFromString(const dvar_t *dvar, const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetFromStringByNameFromSource
==============
*/
/*dvar_t *Dvar_SetFromStringByNameFromSource@<eax>(
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}*/

/*
==============
Dvar_SetFromStringByName
==============
*/
/*void Dvar_SetFromStringByName(dvarType_t a1@<edx>, const char *dvarName, const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Dvar_SetCommand
==============
*/
/*void Dvar_SetCommand(dvarType_t a1@<edx>, const char *dvarName, const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
Dvar_Reset
==============
*/
void Dvar_Reset(const dvar_t *dvar, DvarSetSource setSource)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetCheatState
==============
*/
void Dvar_SetCheatState()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_Init
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Dvar_LoadDvarsAddFlags
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Dvar_LoadDvars
==============
*/
void Dvar_LoadDvars(MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_LoadScriptInfo
==============
*/
void Dvar_LoadScriptInfo(MemoryFile *memFile)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_ResetDvars
==============
*/
void Dvar_ResetDvars(unsigned int filter, DvarSetSource setSource)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_LoadDvarsFromBufferOptional
==============
*/
int Com_LoadDvarsFromBufferOptional(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_SetBoolIfChanged
==============
*/
void Dvar_SetBoolIfChanged(const dvar_t *dvar, bool value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetIntIfChanged
==============
*/
void Dvar_SetIntIfChanged(const dvar_t *dvar, int value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetFloatIfChanged
==============
*/
void Dvar_SetFloatIfChanged(const dvar_t *dvar, float value)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetStringIfChanged
==============
*/
void Dvar_SetStringIfChanged(const dvar_t *dvar, const char *newString)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_DoModifiedCallbacks
==============
*/
void Dvar_DoModifiedCallbacks()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_LoadDvarsFromBuffer
==============
*/
int Com_LoadDvarsFromBuffer(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Dvar_Sort
==============
*/
void Dvar_Sort()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_ForEach
==============
*/
void Dvar_ForEach(void (*callback)(const dvar_t *, void *), void *userData)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_ForEachName
==============
*/
void Dvar_ForEachName(void (*callback)(const char *))
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_ForEachName
==============
*/
void Dvar_ForEachName(
{
	UNIMPLEMENTED(__FUNCTION__);
}

