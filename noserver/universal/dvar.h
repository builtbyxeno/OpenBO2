/*
 * Copyright (c) 2020-2021 OpenIW
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DVAR_H
#define DVAR_H

#include <universal/com_vector.h>

typedef enum dvarType_t : __int32
{
	DVAR_TYPE_INVALID = 0x0,
	DVAR_TYPE_BOOL = 0x1,
	DVAR_TYPE_FLOAT = 0x2,
	DVAR_TYPE_FLOAT_2 = 0x3,
	DVAR_TYPE_FLOAT_3 = 0x4,
	DVAR_TYPE_FLOAT_4 = 0x5,
	DVAR_TYPE_INT = 0x6,
	DVAR_TYPE_ENUM = 0x7,
	DVAR_TYPE_STRING = 0x8,
	DVAR_TYPE_COLOR = 0x9,
	DVAR_TYPE_INT64 = 0xA,
	DVAR_TYPE_LINEAR_COLOR_RGB = 0xB,
	DVAR_TYPE_COLOR_XYZ = 0xC,
	DVAR_TYPE_COUNT = 0xD,
} dvarType_t;

typedef union DvarValue
{
	bool enabled;
	int integer;
	unsigned int unsignedInt;
	__int64 integer64;
	unsigned __int64 unsignedInt64;
	float value;
	vec4_t vector;
	const char* string;
	unsigned __int8 color[4];
} DvarValue;

typedef union DvarLimits {
	struct {
		int stringCount;
		const char** strings;
	} enumeration;
	struct {
		int min;
		int max;
	} integer;
	struct {
		__int64 min;
		__int64 max;
	} integer64;
	struct {
		float min;
		float max;
	} value;
	struct {
		float min;
		float max;
	} vector;
} DvarLimits;

typedef struct __declspec(align(8)) dvar_t
{
	const char* name;
	const char* description;
	int hash;
	unsigned int flags;
	dvarType_t type;
	bool modified;
	DvarValue current;
	DvarValue latched;
	DvarValue reset;
	DvarLimits domain;
	dvar_t* hashNext;
} dvar_t;


void TRACK_dvar(void);
void Dvar_SetInAutoExec(bool);
bool Dvar_IsSystemActive(void);
bool Dvar_IsValidName(char const*);
void Dvar_CopyString(char const*, union DvarValue*);
void Dvar_WeakCopyString(char const*, union DvarValue*);
bool Dvar_ShouldFreeCurrentString(struct dvar_t*);
bool Dvar_ShouldFreeLatchedString(struct dvar_t*);
bool Dvar_ShouldFreeResetString(struct dvar_t*);
void Dvar_FreeString(union DvarValue*);
void Dvar_AssignCurrentStringValue(struct dvar_t*, union DvarValue*, char const*);
void Dvar_AssignLatchedStringValue(struct dvar_t*, union DvarValue*, char const*);
void Dvar_AssignResetStringValue(struct dvar_t*, union DvarValue*, char const*);
char const* Dvar_EnumToString(struct dvar_t const*);
char const* Dvar_IndexStringToEnumString(struct dvar_t const*, char const*);
char const* Dvar_ValueToString(struct dvar_t const*, union DvarValue);
bool Dvar_StringToBool(char const*);
int Dvar_StringToInt(char const*);
__int64 Dvar_StringToInt64(char const*);
float Dvar_StringToFloat(char const*);
void Dvar_StringToVec2(char const*, union vec2_t*);
void Dvar_StringToVec3(char const*, union vec3_t*);
void Dvar_StringToVec4(char const*, union vec4_t*);
int Dvar_StringToEnum(union DvarLimits const*, char const*);
void Dvar_StringToColor(char const*, unsigned char*);
union DvarValue Dvar_StringToValue(enum dvarType_t, union DvarLimits, char const*);
char const* Dvar_DisplayableValue(struct dvar_t const*);
char const* Dvar_DisplayableResetValue(struct dvar_t const*);
char const* Dvar_DisplayableLatchedValue(struct dvar_t const*);
union DvarValue Dvar_ClampValueToDomain(enum dvarType_t, union DvarValue, union DvarValue, union DvarLimits);
bool Dvar_ValueInDomain(enum dvarType_t, union DvarValue, union DvarLimits);
void Dvar_VectorDomainToString(int, union DvarLimits, char*, int);
char const* Dvar_DomainToString_Internal(enum dvarType_t, union DvarLimits, char*, int, int*);
char const* Dvar_DomainToString_GetLines(enum dvarType_t, union DvarLimits, char*, int, int*);
void Dvar_PrintDomain(enum dvarType_t, union DvarLimits);
bool Dvar_ValuesEqual(enum dvarType_t, union DvarValue, union DvarValue);
void Dvar_SetLatchedValue(struct dvar_t*, union DvarValue);
bool Dvar_HasLatchedValue(struct dvar_t const*);
struct dvarCallBack_t* findCallBackForDvar(struct dvar_t const*);
struct dvar_t* Dvar_FindMalleableVar(int);
struct dvar_t* Dvar_FindMalleableVar(char const*);
struct dvar_t* Dvar_FindVar(char const*);
struct dvar_t* Dvar_FindVar(int);
void Dvar_ClearModified(struct dvar_t*);
void Dvar_SetModified(struct dvar_t*);
bool Dvar_GetModified(struct dvar_t const*);
int Dvar_GetInt(int);
unsigned int Dvar_GetUnsignedInt(struct dvar_t const*);
float Dvar_GetFloat(int);
void Dvar_GetVec2(struct dvar_t const*, union vec2_t*);
void Dvar_GetVec3(struct dvar_t const*, union vec3_t*);
void Dvar_GetVec4(struct dvar_t const*, union vec4_t*);
char const* Dvar_GetString(struct dvar_t const*);
char const* Dvar_GetVariantString(int);
char const* Dvar_GetVariantString(struct dvar_t const*);
void Dvar_GetUnpackedColor(struct dvar_t const*, union vec4_t*);
void Dvar_GetColor(struct dvar_t const*, unsigned char*);
float Dvar_GetColorRed(struct dvar_t const*);
float Dvar_GetColorRed(int);
float Dvar_GetColorGreen(struct dvar_t const*);
float Dvar_GetColorGreen(int);
float Dvar_GetColorBlue(struct dvar_t const*);
float Dvar_GetColorBlue(int);
float Dvar_GetColorAlpha(struct dvar_t const*);
float Dvar_GetColorAlpha(int);
bool Dvar_GetLatchedBool(struct dvar_t const*);
int Dvar_GetLatchedInt(struct dvar_t const*);
float Dvar_GetLatchedFloat(struct dvar_t const*);
void Dvar_GetLatchedVec2(struct dvar_t const*, union vec2_t*);
void Dvar_GetLatchedVec3(struct dvar_t const*, union vec3_t*);
void Dvar_GetLatchedVec4(struct dvar_t const*, union vec4_t*);
void Dvar_GetLatchedColor(struct dvar_t const*, unsigned __int8*);
int Dvar_GetResetInt(struct dvar_t const*);
char const* Dvar_GetResetString(struct dvar_t const*);
void Dvar_GetResetVec3(struct dvar_t const*, union vec3_t*);
char const** Dvar_GetDomainEnumStrings(struct dvar_t const*);
int Dvar_GetDomainEnumStringCount(struct dvar_t const*);
int Dvar_GetDomainIntMin(struct dvar_t const*);
int Dvar_GetDomainIntMax(struct dvar_t const*);
__int64 Dvar_GetDomainInt64Min(struct dvar_t const*);
__int64 Dvar_GetDomainInt64Max(struct dvar_t const*);
float Dvar_GetDomainFloatMin(struct dvar_t const*);
float Dvar_GetDomainFloatMax(struct dvar_t const*);
float Dvar_GetDomainVecMin(struct dvar_t const*);
float Dvar_GetDomainVecMax(struct dvar_t const*);
enum dvarType_t Dvar_GetType(struct dvar_t const*);
union DvarValue Dvar_GetCurrent(struct dvar_t const*);
union DvarLimits Dvar_GetDomain(struct dvar_t const*);
char const* Dvar_GetDescription(struct dvar_t const*);
unsigned int Dvar_GetFlags(struct dvar_t const*);
char const* Dvar_GetName(struct dvar_t const*);
void Dvar_Shutdown(void);
void Dvar_PerformUnregistration(struct dvar_t*);
void Dvar_UpdateResetValue(struct dvar_t*, union DvarValue);
void Dvar_ChangeResetValue(struct dvar_t*, union DvarValue);
void Dvar_UpdateValue(struct dvar_t*, union DvarValue);
void Dvar_MakeExplicitType(struct dvar_t*, char const*, enum dvarType_t, unsigned int, union DvarValue, union DvarLimits);
void Dvar_ReinterpretDvar(struct dvar_t*, char const*, enum dvarType_t, unsigned int, union DvarValue, union DvarLimits);
struct dvar_t* Dvar_RegisterNew(char const*, enum dvarType_t, unsigned int, union DvarValue, union DvarLimits, char const*);
void Dvar_AddFlags(struct dvar_t*, int);
int Com_SaveDvarsToBuffer(char const** const, unsigned int, char*, unsigned int);
void Dvar_SetModifiedCallback(struct dvar_t*, void (*)(struct dvar_t const*));
void Dvar_SetCanSetConfigDvars(bool);
bool Dvar_CanSetConfigDvar(struct dvar_t const*);
bool Dvar_CanChangeValue(struct dvar_t const*, union DvarValue, enum DvarSetSource);
void Dvar_SetVariant(struct dvar_t*, union DvarValue, enum DvarSetSource);
void Dvar_UpdateEnumDomain(struct dvar_t*, char const**);
bool Dvar_GetBool(struct dvar_t const*);
int Dvar_GetInt(struct dvar_t const*);
__int64 Dvar_GetInt64(struct dvar_t const*);
float Dvar_GetFloat(struct dvar_t const*);
void Dvar_MakeLatchedValueCurrent(struct dvar_t const*);
void Dvar_Reregister(struct dvar_t*, char const*, enum dvarType_t, unsigned int, union DvarValue, union DvarLimits, char const*);
struct dvar_t* Dvar_RegisterVariant(char const*, enum dvarType_t, unsigned int, union DvarValue, union DvarLimits, char const*);
struct dvar_t* _Dvar_RegisterBool(char const*, bool, unsigned int, char const*);
struct dvar_t* _Dvar_RegisterInt(char const*, int, int, int, unsigned int, char const*);
struct dvar_t* _Dvar_RegisterInt64(char const*, __int64, __int64, __int64, unsigned int, char const*);
struct dvar_t* _Dvar_RegisterFloat(char const*, float, float, float, unsigned int, char const*);
struct dvar_t* _Dvar_RegisterVec2(char const*, float, float, float, float, unsigned int, char const*);
struct dvar_t* _Dvar_RegisterVec3(char const*, float, float, float, float, float, unsigned int, char const*);
struct dvar_t* _Dvar_RegisterVec4(char const*, float, float, float, float, float, float, unsigned int, char const*);
struct dvar_t* _Dvar_RegisterString(char const*, char const*, unsigned int, char const*);
struct dvar_t* _Dvar_RegisterEnum(char const*, char const** const, int, unsigned int, char const*);
struct dvar_t* _Dvar_RegisterColor(char const*, float, float, float, float, unsigned int, char const*);
struct dvar_t* _Dvar_RegisterLinearRGB(char const*, float, float, float, float, float, unsigned int, char const*);
struct dvar_t* _Dvar_RegisterColorXYZ(char const*, float, float, float, float, float, unsigned int, char const*);
void Dvar_SetBoolFromSource(struct dvar_t*, bool, enum DvarSetSource);
void Dvar_SetIntFromSource(struct dvar_t*, int, enum DvarSetSource);
void Dvar_SetInt64FromSource(struct dvar_t*, __int64, enum DvarSetSource);
void Dvar_SetFloatFromSource(struct dvar_t*, float, enum DvarSetSource);
void Dvar_SetVec2FromSource(struct dvar_t*, float, float, enum DvarSetSource);
void Dvar_SetVec3FromSource(struct dvar_t*, float, float, float, enum DvarSetSource);
void Dvar_SetVec4FromSource(struct dvar_t*, float, float, float, float, enum DvarSetSource);
void Dvar_SetStringFromSource(struct dvar_t*, char const*, enum DvarSetSource);
void Dvar_SetColorFromSource(struct dvar_t*, float, float, float, float, enum DvarSetSource);
void Dvar_SetBool(struct dvar_t*, bool);
void Dvar_SetInt(struct dvar_t*, int);
void Dvar_SetFloat(struct dvar_t*, float);
void Dvar_SetVec2(struct dvar_t*, float, float);
void Dvar_SetVec3(struct dvar_t*, float, float, float);
void Dvar_SetVec4(struct dvar_t*, float, float, float, float);
void Dvar_SetVec4FromVec4(struct dvar_t*, union vec4_t*);
void Dvar_SetString(struct dvar_t*, char const*);
struct dvar_t const* Dvar_SetOrRegisterString(struct dvar_t const*, char const*, char const*);
void Dvar_SetColor(struct dvar_t*, float, float, float, float);
void Dvar_SetFromStringFromSource(struct dvar_t*, char const*, enum DvarSetSource);
void Dvar_SetFromString(struct dvar_t*, char const*);
struct dvar_t* Dvar_SetFromStringByNameFromSource(char const*, char const*, enum DvarSetSource, unsigned int);
void Dvar_SetFromStringByName(char const*, char const*);
void Dvar_SetCommand(char const*, char const*);
void Dvar_Reset(struct dvar_t*, enum DvarSetSource);
void Dvar_SetCheatState(void);
void Dvar_Init(void);
void Dvar_LoadDvarsAddFlags(struct MemoryFile*, unsigned short);
void Dvar_LoadDvars(struct MemoryFile*);
void Dvar_LoadScriptInfo(struct MemoryFile*);
void Dvar_ResetDvars(unsigned int, enum DvarSetSource);
int Com_LoadDvarsFromBufferOptional(char const** const, bool*, unsigned int, char const*, char const*);
void Dvar_SetBoolIfChanged(struct dvar_t*, bool);
void Dvar_SetIntIfChanged(struct dvar_t*, int);
void Dvar_SetFloatIfChanged(struct dvar_t*, float);
void Dvar_SetStringIfChanged(struct dvar_t*, char const*);
void Dvar_DoModifiedCallbacks(void);
int Com_LoadDvarsFromBuffer(char const** const, unsigned int, char const*, char const*);
void Dvar_Sort(void);
void Dvar_ForEach(void (*)(struct dvar_t const*, void*), void*);
void Dvar_ForEachName(void (*)(char const*));
void Dvar_ForEachName(enum LocalClientNum_t, void (*)(enum LocalClientNum_t, char const*));

#endif