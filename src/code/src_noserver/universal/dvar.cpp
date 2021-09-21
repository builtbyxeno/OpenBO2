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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Dvar_DisplayableResetValue
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Dvar_DisplayableLatchedValue
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Dvar_ClampValueToDomain
==============
*/
DvarValue *Dvar_ClampValueToDomain(dvarType_t type, DvarValue value, const DvarValue resetValue, const DvarLimits domain)
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Dvar_PrintDomain
==============
*/
void Dvar_PrintDomain(char *a1, dvarType_t type, DvarLimits domain)
{
	UNIMPLEMENTED(__FUNCTION__);
}

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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Dvar_GetVariantString
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Dvar_GetUnpackedColor
==============
*/
void Dvar_GetUnpackedColor(unsigned __int8 *a1, const char *a2, const dvar_t *dvar, vec4_t *expandedColor)
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
double Dvar_GetColorRed(unsigned __int8 *a1, const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

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
double Dvar_GetColorGreen(unsigned __int8 *a1, const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

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
double Dvar_GetColorBlue(unsigned __int8 *a1, const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

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
double Dvar_GetColorAlpha(unsigned __int8 *a1, const dvar_t *dvar)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Dvar_RegisterNew
==============
*/
const dvar_t *Dvar_RegisterNew(const char *dvarName, dvarType_t type, unsigned int flags, DvarValue value, DvarLimits domain, const char *description)
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Dvar_SetVariant
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Dvar_UpdateEnumDomain
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
Dvar_SetOrRegisterString
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

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
/*void Dvar_SetFromStringFromSource(const char *a1@<edi>, const dvar_t *dvar, const char *string, DvarSetSource source)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

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
dvar_t *Dvar_SetFromStringByNameFromSource(dvarType_t a1, const char *a2, const char *dvarName, const char *string, DvarSetSource source, unsigned int flags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Dvar_SetFromStringByName
==============
*/
void Dvar_SetFromStringByName(dvarType_t a1, const char *dvarName, const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Dvar_SetCommand
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

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
int Com_LoadDvarsFromBufferOptional(const char **dvarnames, bool *isOptional, unsigned int numDvars, const char *buffer, const char *filename)
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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
int Com_LoadDvarsFromBuffer(const char **dvarnames, unsigned int numDvars, const char *buffer, const char *filename)
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
void Dvar_ForEachName(LocalClientNum_t localClientNum, void (*callback)(LocalClientNum_t, const char *))
{
	UNIMPLEMENTED(__FUNCTION__);
}

