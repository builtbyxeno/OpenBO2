#include "types.h"
#include "vars.h"
#include <universal/universal_public.h>
#include <universal/com_math.h>
#include <qcommon/qcommon_public.h>
#include <qcommon/threads_interlock.h>
#include <universal/q_shared.h>

static bool s_isLoadingAutoExecGlobalFlag;
static bool s_isDvarSystemActive;
static dvarCallBack_t s_dvarCallbackPool[64];
static int s_nextFreeCallback;
FastCriticalSection g_dvarCritSect;
dvar_t s_dvarPool[4320];
bool s_areDvarsSorted;
bool s_canSetConfigDvars;

const char* s_dvarTypeNames[] =
{
  "INVALID",
  "bool",
  "float",
  "float2",
  "float3",
  "float4",
  "int",
  "enum",
  "string",
  "color",
  "int64",
  "linColorRGB",
  "colorXYZ"
};

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
	s_isLoadingAutoExecGlobalFlag = inAutoExec;
}

/*
==============
Dvar_IsSystemActive
==============
*/
bool Dvar_IsSystemActive()
{
	return s_isDvarSystemActive;
}

/*
==============
Dvar_IsValidName
==============
*/
bool Dvar_IsValidName(const char *dvarName)
{
	char nameChar;
	int index;

	if (!dvarName)
	{
		return 0;
	}

	for (index = 0; dvarName[index]; ++index)
	{
		nameChar = dvarName[index];
		if (!isalnum(nameChar) && nameChar != '_')
		{
			return 0;
		}
	}

	return 1;
}

/*
==============
Dvar_CopyString
==============
*/
void Dvar_CopyString(const char *string, DvarValue *value)
{
	value->string = CopyString(string);
}

/*
==============
Dvar_WeakCopyString
==============
*/
void Dvar_WeakCopyString(const char *string, DvarValue *value)
{
	value->string = string;
}

/*
==============
Dvar_ShouldFreeCurrentString
==============
*/
bool Dvar_ShouldFreeCurrentString(dvar_t *dvar)
{
	return dvar->current.string
		&& dvar->current.string != dvar->latched.string
		&& dvar->current.string != dvar->reset.string;
}

/*
==============
Dvar_ShouldFreeLatchedString
==============
*/
bool Dvar_ShouldFreeLatchedString(dvar_t *dvar)
{
	return dvar->latched.string
		&& dvar->latched.string != dvar->current.string
		&& dvar->latched.string != dvar->reset.string;
}

/*
==============
Dvar_ShouldFreeResetString
==============
*/
bool Dvar_ShouldFreeResetString(dvar_t *dvar)
{
	return dvar->reset.string
		&& dvar->reset.string != dvar->current.string
		&& dvar->reset.string != dvar->latched.string;
}

/*
==============
Dvar_FreeString
==============
*/
void Dvar_FreeString(DvarValue *value)
{
	FreeString(value->string);
	value->string = NULL;
}

/*
==============
Dvar_AssignCurrentStringValue
==============
*/
void Dvar_AssignCurrentStringValue(dvar_t *dvar, DvarValue *dest, const char *string)
{
	assert(string);
	if (dvar->latched.string && (string == dvar->latched.string || !strcmp(string, dvar->latched.string)))
	{
		Dvar_WeakCopyString(dvar->latched.string, dest);
	}
	else if (dvar->reset.string && (string == dvar->reset.string || !strcmp(string, dvar->reset.string)))
	{
		Dvar_WeakCopyString(dvar->reset.string, dest);
	}
	else
	{
		Dvar_CopyString(string, dest);
	}
}

/*
==============
Dvar_AssignLatchedStringValue
==============
*/
void Dvar_AssignLatchedStringValue(dvar_t *dvar, DvarValue *dest, const char *string)
{
	assert(string);

	if (dvar->current.string && (string == dvar->current.string || !strcmp(string, dvar->current.string)))
	{
		Dvar_WeakCopyString(dvar->current.string, dest);
	}
	else if (dvar->reset.string && (string == dvar->reset.string || !strcmp(string, dvar->reset.string)))
	{
		Dvar_WeakCopyString(dvar->reset.string, dest);
	}
	else
	{
		Dvar_CopyString(string, dest);
	}
}

/*
==============
Dvar_AssignResetStringValue
==============
*/
void Dvar_AssignResetStringValue(dvar_t *dvar, DvarValue *dest, const char *string)
{
	assert(string);
	if (dvar->current.integer && (string == dvar->current.string || !strcmp(string, dvar->current.string)))
	{
		Dvar_WeakCopyString(dvar->current.string, dest);
	}
	else if (dvar->latched.integer && (string == dvar->latched.string || !strcmp(string, dvar->latched.string)))
	{
		Dvar_WeakCopyString(dvar->latched.string, dest);
	}
	else
	{
		Dvar_CopyString(string, dest);
	}
}

/*
==============
Dvar_EnumToString
==============
*/
const char *Dvar_EnumToString(const dvar_t *dvar)
{
	assert(dvar);
	assert(dvar->name);
	assertMsg((dvar->type == DVAR_TYPE_ENUM), "(dvar->name) = %s", dvar->name);
	assertMsg((dvar->domain.enumeration.strings), "(dvar->name) = %s", dvar->name);
	assertMsg((dvar->current.integer >= 0 && dvar->current.integer < dvar->domain.integer.min || dvar->current.integer == 0),
		"(dvar->current.integer) = %i", dvar->current.integer);

	if (dvar->domain.enumeration.stringCount)
	{
		return dvar->domain.enumeration.strings[dvar->current.integer];
	}

	return "";
}

/*
==============
Dvar_IndexStringToEnumString
==============
*/
const char *Dvar_IndexStringToEnumString(const dvar_t *dvar, const char *indexString)
{
	int enumIndex;
	int indexStringIndex;

	assert(dvar);
	assert(dvar->name);
	assertMsg((dvar->type == DVAR_TYPE_ENUM), "(dvar->name) = %s", dvar->name);
	assertMsg((dvar->domain.enumeration.strings), "(dvar->name) = %s", dvar->name);
	assertMsg((indexString), "(dvar->name) = %s", dvar->name);
	if (dvar->domain.enumeration.stringCount == 0)
	{
		return "";
	}

	for (indexStringIndex = 0; indexStringIndex < strlen(indexString); ++indexStringIndex)
	{
		if (!isdigit(indexString[indexStringIndex]))
		{
			return "";
		}
	}

	enumIndex = atoi(indexString);
	if (enumIndex >= 0 && enumIndex < dvar->domain.enumeration.stringCount)
	{
		return dvar->domain.enumeration.strings[enumIndex];
	}

	return "";
}

/*
==============
Dvar_ValueToString
==============
*/
const char *Dvar_ValueToString(const dvar_t *dvar, DvarValue value)
{
	const char* result;

	switch (dvar->type)
	{
	case DVAR_TYPE_BOOL:
		result = value.enabled ? "1" : "0";
		break;
	case DVAR_TYPE_FLOAT:
		result = va("%g", value.value);
		break;
	case DVAR_TYPE_FLOAT_2:
		result = va("%g %g", value.vector.v[0], value.vector.v[1]);
		break;
	case DVAR_TYPE_FLOAT_3:
	case DVAR_TYPE_LINEAR_COLOR_RGB:
	case DVAR_TYPE_COLOR_XYZ:
		result = va("%g %g %g", value.vector.v[0], value.vector.v[1], value.vector.v[2]);
		break;
	case DVAR_TYPE_FLOAT_4:
		result = va("%g %g %g %g", value.vector.v[0], value.vector.v[1], value.vector.v[2], value.vector.v[3]);
		break;
	case DVAR_TYPE_INT:
		result = va("%i", value.integer);
		break;
	case DVAR_TYPE_ENUM:
		assertMsg((value.integer >= 0 && value.integer < dvar->domain.integer.min || value.integer == 0),
			"(value.integer) = %i", value.integer);

		if (dvar->domain.enumeration.stringCount)
		{
			result = dvar->domain.enumeration.strings[value.integer];
		}
		else
		{
			result = "";
		}
		break;
	case DVAR_TYPE_STRING:
		assertMsg((value.string), "(dvar->name) = %s", dvar->name);
		result = va("%s", value.integer);
		break;
	case DVAR_TYPE_COLOR:
		result = va("%g %g %g %g",
			(float)((float)value.color[0] / 255.0f),
			(float)((float)value.color[1] / 255.0f),
			(float)((float)value.color[2] / 255.0f),
			(float)((float)value.color[3] / 255.0f));
		break;
	case DVAR_TYPE_INT64:
		result = va("%lli", value.integer64);
		break;
	default:
		assertMsg(false, va("unhandled dvar type '%i'", dvar->type));
		result = "";
		break;
	}

	return result;
}

/*
==============
Dvar_StringToBool
==============
*/
bool Dvar_StringToBool(const char *string)
{
	assert(string);
	return atoi(string) != 0;
}

/*
==============
Dvar_StringToInt
==============
*/
int Dvar_StringToInt(const char *string)
{
	assert(string);
	return atoi(string);
}

/*
==============
Dvar_StringToInt64
==============
*/
__int64 Dvar_StringToInt64(const char *string)
{
	assert(string);
	return I_atoi64(string);
}

/*
==============
Dvar_StringToFloat
==============
*/
float Dvar_StringToFloat(const char *string)
{
	assert(string);
	return atof(string);
}

/*
==============
Dvar_StringToVec2
==============
*/
void Dvar_StringToVec2(const char *string, vec2_t *vector)
{
	assert(string);
	sscanf(string, "%g %g", vector->v[0], vector->v[1]);
}

/*
==============
Dvar_StringToVec3
==============
*/
void Dvar_StringToVec3(const char *string, vec3_t *vector)
{
	assert(string);
	if (string[0] == '(' )
		sscanf(string, "( %g %g %g )", vector->v[0], vector->v[1], vector->v[2]);
	else
		sscanf(string, "%g %g %g", vector->v[0], vector->v[1], vector->v[2]);
}

/*
==============
Dvar_StringToVec4
==============
*/
void Dvar_StringToVec4(const char *string, vec4_t *vector)
{
	assert(string);
	vector->v[0] = 0.0f;
	vector->v[1] = 0.0f;
	vector->v[2] = 0.0f;
	vector->v[3] = 0.0f;
	sscanf(string, "%g %g %g %g", vector->v[0], vector->v[1], vector->v[2], vector->v[3]);
}

/*
==============
Dvar_StringToEnum
==============
*/
int Dvar_StringToEnum(const DvarLimits *domain, const char *string)
{
	int stringIndex;
	const char* digit;

	assert(domain);
	assert(string);

	for (stringIndex = 0; stringIndex < domain->enumeration.stringCount; ++stringIndex)
	{
		if (!I_stricmp(string, domain->enumeration.strings[stringIndex]))
		{
			return stringIndex;
		}
	}

	stringIndex = 0;
	for (digit = string; *digit; ++digit)
	{
		if (*digit < '0' || *digit > '9')
		{
			return DVAR_INVALID_ENUM_INDEX;
		}
		stringIndex = 10 * stringIndex + *digit - '0';
	}

	if (stringIndex >= 0 && stringIndex < domain->enumeration.stringCount)
	{
		return stringIndex;
	}

	for (stringIndex = 0; stringIndex < domain->enumeration.stringCount; ++stringIndex)
	{
		if (!I_strnicmp(string, domain->enumeration.strings[stringIndex], strlen(string)))
		{
			return stringIndex;
		}
	}

	return DVAR_INVALID_ENUM_INDEX;
}

/*
==============
Dvar_StringToColor
==============
*/
void Dvar_StringToColor(const char *string, unsigned __int8 *color)
{
	vec4_t* colorVec;

	colorVec->r = 0.0f;
	colorVec->g = 0.0f;
	colorVec->b = 0.0f;
	colorVec->a = 0.0f;
	sscanf(string, "%g %g %g %g", colorVec->r, colorVec->g, colorVec->b, colorVec->a);

	color[0] = (int)((float)(255.0 * I_fclamp(colorVec->r, 0.0f, 1.0f)) + 9.313225746154785e-10);
	color[1] = (int)((float)(255.0 * I_fclamp(colorVec->g, 0.0f, 1.0f)) + 9.313225746154785e-10);
	color[2] = (int)((float)(255.0 * I_fclamp(colorVec->b, 0.0f, 1.0f)) + 9.313225746154785e-10);
	color[3] = (int)((float)(255.0 * I_fclamp(colorVec->a, 0.0f, 1.0f)) + 9.313225746154785e-10);
}

/*
==============
Dvar_StringToValue
==============
*/
DvarValue Dvar_StringToValue(const dvarType_t type, const DvarLimits domain, const char *string)
{
	DvarValue value;

	assert(string);
	switch (type)
	{
	case DVAR_TYPE_BOOL:
		value.enabled = Dvar_StringToBool(string);
		break;
	case DVAR_TYPE_FLOAT:
		value.value = Dvar_StringToFloat(string);
		break;
	case DVAR_TYPE_FLOAT_2:
		Dvar_StringToVec2(string, (vec2_t*)&value.vector);
		break;
	case DVAR_TYPE_FLOAT_3:
	case DVAR_TYPE_LINEAR_COLOR_RGB:
	case DVAR_TYPE_COLOR_XYZ:
		Dvar_StringToVec3(string, (vec3_t*)&value.vector);
		break;
	case DVAR_TYPE_FLOAT_4:
		Dvar_StringToVec4(string, (vec4_t*)&value.vector);
		break;
	case DVAR_TYPE_INT:
		value.integer = Dvar_StringToInt(string);
		break;
	case DVAR_TYPE_ENUM:
		value.integer = Dvar_StringToEnum(&domain, string);
		break;
	case DVAR_TYPE_STRING:
		value.string = string;
		break;
	case DVAR_TYPE_COLOR:
		Dvar_StringToColor(string, value.color);
		break;
	case DVAR_TYPE_INT64:
		value.integer64 = Dvar_StringToInt64(string);
		break;
	default:
		assertMsg(false, va("unhandled dvar type '%i'", type));
		break;
	}

	return value;
}

/*
==============
Dvar_DisplayableValue
==============
*/
const char *__cdecl Dvar_DisplayableValue(const dvar_t *dvar)
{
	assert(dvar);
	return Dvar_ValueToString(dvar, dvar->current);
}

/*
==============
Dvar_DisplayableResetValue
==============
*/
const char *__cdecl Dvar_DisplayableResetValue(const dvar_t *dvar)
{
	assert(dvar);
	return Dvar_ValueToString(dvar, dvar->reset);
}

/*
==============
Dvar_DisplayableLatchedValue
==============
*/
const char *__cdecl Dvar_DisplayableLatchedValue(const dvar_t *dvar)
{
	assert(dvar);
	return Dvar_ValueToString(dvar, dvar->latched);
}

/*
==============
Dvar_ClampVectorToDomain
==============
*/
void Dvar_ClampVectorToDomain(float* vector, int components, float min, float max)
{
	int channel;

	for (channel = 0; channel < components; ++channel)
	{
		if (min <= vector[channel])
		{
			if (vector[channel] > max)
			{
				vector[channel] = max;
			}
		}
		else
		{
			vector[channel] = min;
		}
	}
}

/*
==============
Dvar_ClampValueToDomain
==============
*/
DvarValue Dvar_ClampValueToDomain(dvarType_t type, DvarValue value, const DvarValue resetValue, const DvarLimits domain)
{
	switch (type)
	{
	case DVAR_TYPE_BOOL:
		value.enabled = value.enabled != 0;
		break;
	case DVAR_TYPE_FLOAT:
		if (domain.value.min <= value.value)
		{
			if (value.value > domain.value.max)
			{
				value.integer = domain.integer.max;
			}
		}
		else
		{
			value.integer = domain.integer.min;
		}
		break;
	case DVAR_TYPE_FLOAT_2:
		Dvar_ClampVectorToDomain(value.vector.v, 2, domain.value.min, domain.value.max);
		break;
	case DVAR_TYPE_FLOAT_3:
	case DVAR_TYPE_LINEAR_COLOR_RGB:
	case DVAR_TYPE_COLOR_XYZ:
		Dvar_ClampVectorToDomain(value.vector.v, 3, domain.value.min, domain.value.max);
		break;
	case DVAR_TYPE_FLOAT_4:
		Dvar_ClampVectorToDomain(value.vector.v, 4, domain.value.min, domain.value.max);
		break;
	case DVAR_TYPE_INT:
		assert(domain.integer.min <= domain.integer.max);
		if (value.integer >= domain.enumeration.stringCount)
		{
			if (value.integer > domain.integer.max)
			{
				value.integer = domain.integer.max;
			}
		}
		else
		{
			value.integer = domain.enumeration.stringCount;
		}
		break;
	case DVAR_TYPE_ENUM:
		if (value.integer < 0 || value.integer >= domain.enumeration.stringCount)
		{
			value.integer = resetValue.integer;
			assertMsg((value.integer >= 0 && value.integer < domain.enumeration.stringCount || value.integer == 0),
				"(value.integer) = %i", value.integer);
		}
		break;
	case DVAR_TYPE_STRING:
	case DVAR_TYPE_COLOR:
		break;
	case DVAR_TYPE_INT64:
		assert(domain.integer64.min <= domain.integer64.max);
		if (value.integer64 >= domain.integer64.min)
		{
			if (value.integer64 > domain.integer64.max)
			{
				value.integer64 = domain.integer64.max;
			}
		}
		else
		{
			value.integer64 = domain.integer64.min;
		}
		break;
	default:
		assertMsg(false, va("unhandled dvar type '%i'", type));
		break;
	}

	return value;
}

/*
==============
Dvar_VectorInDomain
==============
*/
bool Dvar_VectorInDomain(const float* vector, int components, float min, float max)
{
	int channel;

	for (channel = 0; channel < components; ++channel)
	{
		if (min > vector[channel])
		{
			return 0;
		}
		if (vector[channel] > max)
		{
			return 0;
		}
	}
	return 1;
}

/*
==============
Dvar_ValueInDomain
==============
*/
bool Dvar_ValueInDomain(dvarType_t type, DvarValue value, DvarLimits domain)
{
	switch (type)
	{
	case DVAR_TYPE_BOOL:
		assert(!(value.enabled == true || value.enabled == false));
		return 1;
	case DVAR_TYPE_FLOAT:
		if (domain.value.min <= value.value)
		{
			return value.value <= domain.value.max;
		}
		return 0;
	case DVAR_TYPE_FLOAT_2:
		return Dvar_VectorInDomain(value.vector.v, 2, domain.vector.min, domain.vector.max);
	case DVAR_TYPE_FLOAT_3:
	case DVAR_TYPE_LINEAR_COLOR_RGB:
	case DVAR_TYPE_COLOR_XYZ:
		return Dvar_VectorInDomain(value.vector.v, 3, domain.vector.min, domain.vector.max);
	case DVAR_TYPE_FLOAT_4:
		return Dvar_VectorInDomain(value.vector.v, 4, domain.vector.min, domain.vector.max);
	case DVAR_TYPE_INT:
		assert(domain.integer.min <= domain.integer.max);
		if (value.integer >= domain.integer.min)
		{
			return value.integer <= domain.integer.max;
		}
		return 0;
	case DVAR_TYPE_ENUM:
		return value.integer >= 0 && value.integer < domain.enumeration.stringCount || !value.integer;
	case DVAR_TYPE_STRING:
		return 1;
	case DVAR_TYPE_COLOR:
		return 1;
	case DVAR_TYPE_INT64:
		assert(domain.integer64.min <= domain.integer64.max);
		if (value.integer64 >= domain.integer64.min)
		{
			return value.integer64 <= domain.integer64.max;
		}
		return 0;
	default:
		assertMsg(false, va("unhandled dvar type '%i'", type));
		return 0;
	}
}

/*
==============
Dvar_VectorDomainToString
==============
*/
void Dvar_VectorDomainToString(int components, DvarLimits domain, char *outBuffer, int outBufferLen)
{
	if (domain.vector.min == -FLT_MAX)
	{
		if (domain.vector.max == FLT_MAX)
		{
			_snprintf(outBuffer, outBufferLen, "Domain is any %iD vector", components);
		}
		else
		{
			_snprintf(outBuffer, outBufferLen, "Domain is any %iD vector with components %g or smaller",
				components, domain.vector.max);
		}
	}
	else if (domain.vector.max == FLT_MAX)
	{
		_snprintf(outBuffer, outBufferLen, "Domain is any %iD vector with components %g or bigger",
			components, domain.vector.min);
	}
	else
	{
		_snprintf(outBuffer, outBufferLen, "Domain is any %iD vector with components from %g to %g",
			components, domain.vector.min, domain.vector.max);
	}
}

/*
==============
Dvar_DomainToString_Internal
==============
*/
const char *Dvar_DomainToString_Internal(dvarType_t type, DvarLimits domain, char *outBuffer, int outBufferLen, int *outLineCount)
{
	char* outBufferEnd;
	char* outBufferWalk;
	int charsWritten;
	int stringIndex;

	assert(outBufferLen > 0);
	outBufferEnd = &outBuffer[outBufferLen];
	if (outLineCount)
	{
		*outLineCount = 0;
	}

	switch (type)
	{
	case DVAR_TYPE_BOOL:
		_snprintf(outBuffer, outBufferLen, "Domain is 0 or 1");
		break;
	case DVAR_TYPE_FLOAT:
		if (domain.value.min == -FLT_MAX)
		{
			if (domain.value.max == FLT_MAX)
			{
				_snprintf(outBuffer, outBufferLen, "Domain is any number");
			}
			else
			{
				_snprintf(outBuffer, outBufferLen, "Domain is any number %g or smaller", domain.value.max);
			}
		}
		else if (domain.value.max == FLT_MAX)
		{
			_snprintf(outBuffer, outBufferLen, "Domain is any number %g or bigger", domain.value.min);
		}
		else
		{
			_snprintf(outBuffer, outBufferLen, "Domain is any number from %g to %g", domain.value.min, domain.value.max);
		}
		break;
	case DVAR_TYPE_FLOAT_2:
		Dvar_VectorDomainToString(2, domain, outBuffer, outBufferLen);
		break;
	case DVAR_TYPE_FLOAT_3:
	case DVAR_TYPE_LINEAR_COLOR_RGB:
	case DVAR_TYPE_COLOR_XYZ:
		Dvar_VectorDomainToString(3, domain, outBuffer, outBufferLen);
		break;
	case DVAR_TYPE_FLOAT_4:
		Dvar_VectorDomainToString(4, domain, outBuffer, outBufferLen);
		break;
	case DVAR_TYPE_INT:
		if (domain.integer.min == 0x80000000)
		{
			if (domain.integer.max == 0x7FFFFFFF)
			{
				_snprintf(outBuffer, outBufferLen, "Domain is any integer");
			}
			else
			{
				_snprintf(outBuffer, outBufferLen, "Domain is any integer %i or smaller", domain.integer.max);
			}
		}
		else if (domain.integer.max == 0x7FFFFFFF)
		{
			_snprintf(outBuffer, outBufferLen, "Domain is any integer %i or bigger", domain.integer.min);
		}
		else
		{
			_snprintf(outBuffer, outBufferLen, "Domain is any integer from %i to %i", domain.integer.min, domain.integer.max);
		}
		break;
	case DVAR_TYPE_ENUM:
		charsWritten = _snprintf(outBuffer, outBufferEnd - outBuffer, "Domain is one of the following:");
		if (charsWritten >= 0)
		{
			outBufferWalk = &outBuffer[charsWritten];
			for (stringIndex = 0; stringIndex < domain.enumeration.stringCount; ++stringIndex)
			{
				charsWritten = _snprintf(outBufferWalk, outBufferEnd - outBufferWalk, "\n  %2i: %s",
					stringIndex, domain.enumeration.strings[stringIndex]);

				if (charsWritten < 0)
				{
					break;
				}

				if (outLineCount)
				{
					++* outLineCount;
				}
				outBufferWalk += charsWritten;
			}
		}
		break;
	case DVAR_TYPE_STRING:
		_snprintf(outBuffer, outBufferLen, "Domain is any text");
		break;
	case DVAR_TYPE_COLOR:
		_snprintf(outBuffer, outBufferLen, "Domain is any 4-component color, in RGBA format");
		break;
	case DVAR_TYPE_INT64:
		if (domain.integer64.min || domain.integer64.max != 0x80000000)
		{
			if (domain.integer64.max == 0x7FFFFFFFFFFFFFFF)
			{
				_snprintf(outBuffer, outBufferLen, "Domain is any integer %lli or bigger", domain.integer64.min);
			}
			else
			{
				_snprintf(outBuffer, outBufferLen, "Domain is any integer from %lli to %lli",
					domain.integer64.min, domain.integer64.max);
			}
		}
		else if (domain.integer64.max == 0x7FFFFFFF)
		{
			_snprintf(outBuffer, outBufferLen, "Domain is any integer");
		}
		else
		{
			_snprintf(outBuffer, outBufferLen, "Domain is any integer %lli or smaller", domain.integer64.max);
		}
		break;
	default:
		assertMsg(false, va("unhandled dvar type '%i'", type));
		*outBuffer = 0;
		break;
	}

	*(outBufferEnd - 1) = 0;
	return outBuffer;
}

/*
==============
Dvar_DomainToString_GetLines
==============
*/
const char *Dvar_DomainToString_GetLines(dvarType_t type, DvarLimits domain, char *outBuffer, int outBufferLen, int *outLineCount)
{
	assert(outLineCount);
	return Dvar_DomainToString_Internal(type, domain, outBuffer, outBufferLen, outLineCount);
}

/*
==============
Dvar_PrintDomain
==============
*/
void Dvar_PrintDomain(dvarType_t type, DvarLimits domain)
{
	char domainBuffer[1024];

	Com_Printf(CON_CHANNEL_SYSTEM, "  %s\n", Dvar_DomainToString_Internal(type, domain, domainBuffer, sizeof(domainBuffer), 0));
}

/*
==============
Dvar_ValuesEqual
==============
*/
qboolean Dvar_ValuesEqual(dvarType_t type, DvarValue val0, DvarValue val1)
{
	qboolean result;

	switch (type)
	{
	case DVAR_TYPE_BOOL:
		result = val0.enabled == val1.enabled;
		break;
	case DVAR_TYPE_FLOAT:
		result = val0.value == val1.value;
		break;
	case DVAR_TYPE_FLOAT_2:
		result = val0.vector.v[0] == val1.vector.v[0] && val0.vector.v[1] == val1.vector.v[1];
		break;
	case DVAR_TYPE_FLOAT_3:
	case DVAR_TYPE_LINEAR_COLOR_RGB:
	case DVAR_TYPE_COLOR_XYZ:
		result = val0.vector.v[0] == val1.vector.v[0] && val0.vector.v[1] == val1.vector.v[1] && val0.vector.v[2] == val1.vector.v[2];
		break;
	case DVAR_TYPE_FLOAT_4:
		result = val0.vector.v[0] == val1.vector.v[0] && val0.vector.v[1] == val1.vector.v[1]
			&& val0.vector.v[2] == val1.vector.v[2] && val0.vector.v[3] == val1.vector.v[3];
		break;
	case DVAR_TYPE_INT:
		result = val0.integer == val1.integer;
		break;
	case DVAR_TYPE_ENUM:
		result = val0.integer == val1.integer;
		break;
	case DVAR_TYPE_STRING:
		assert(val0.string);
		assert(val1.string);
		result = strcmp(val0.string, val1.string) == 0;
		break;
	case DVAR_TYPE_COLOR:
		result = val0.integer == val1.integer;
		break;
	case DVAR_TYPE_INT64:
		result = val0.integer64 == val1.integer64;
		break;
	default:
		assertMsg(false, va("unhandled dvar type '%i'", type));
		result = 0;
		break;
	}

	return result;
}

/*
==============
Dvar_SetLatchedValue
==============
*/
void Dvar_SetLatchedValue(dvar_t *dvar, DvarValue value)
{
	DvarValue latchedString;
	DvarValue oldString;
	bool shouldFree;

	switch (dvar->type)
	{
	case DVAR_TYPE_FLOAT_2:
		dvar->latched.vector.v[0] = value.vector.v[0];
		dvar->latched.vector.v[1] = value.vector.v[1];
		break;
	case DVAR_TYPE_FLOAT_3:
	case DVAR_TYPE_LINEAR_COLOR_RGB:
	case DVAR_TYPE_COLOR_XYZ:
		dvar->latched.vector.v[0] = value.vector.v[0];
		dvar->latched.vector.v[1] = value.vector.v[1];
		dvar->latched.vector.v[2] = value.vector.v[2];
		break;
	case DVAR_TYPE_FLOAT_4:
		dvar->latched.vector.v[0] = value.vector.v[0];
		dvar->latched.vector.v[1] = value.vector.v[1];
		dvar->latched.vector.v[2] = value.vector.v[2];
		dvar->latched.vector.v[3] = value.vector.v[3];
		break;
	case DVAR_TYPE_STRING:
		if (dvar->latched.string != value.string)
		{
			shouldFree = Dvar_ShouldFreeLatchedString(dvar);
			if (shouldFree)
			{
				oldString.string = dvar->latched.string;
			}

			Dvar_AssignLatchedStringValue(dvar, &latchedString, value.string);
			dvar->latched.string = latchedString.string;
			if (shouldFree)
			{
				Dvar_FreeString(&oldString);
			}
		}
		break;
	default:
		dvar->latched = value;
		break;
	}
}

/*
==============
Dvar_HasLatchedValue
==============
*/
qboolean Dvar_HasLatchedValue(const dvar_t *dvar)
{
	return Dvar_ValuesEqual(dvar->type, dvar->current, dvar->latched) == 0;
}

/*
==============
findCallBackForDvar
==============
*/
dvarCallBack_t *findCallBackForDvar(const dvar_t *dvar)
{
	int i;
	int hash;
	dvarCallBack_t* result;

	i = 0;
	if (s_nextFreeCallback > 0)
	{
		hash = dvar->hash;
		for (result = s_dvarCallbackPool; result->dvar->hash != hash; ++result)
		{
			if (++i >= s_nextFreeCallback)
				return 0;
		}
		return result;
	}
	return 0;
}

/*
==============
Dvar_FindMalleableVar
==============
*/
dvar_t *Dvar_FindMalleableVar(int dvarHash)
{
	dvar_t* var;

	InterlockedIncrement(&g_dvarCritSect.readCount);
	while (g_dvarCritSect.writeCount)
	{
		NET_Sleep(0);
	}

	for (var = s_dvarHashTable[dvarHash & 0x437]; var; var = var->hashNext)
	{
		if (var->hash == dvarHash)
		{
			Sys_UnlockRead(&g_dvarCritSect);
			return var;
		}
	}

	Sys_UnlockRead(&g_dvarCritSect);

	return NULL;
}

/*
==============
Dvar_FindMalleableVar
==============
*/
dvar_t *Dvar_FindMalleableVar(const char* dvarName)
{
	int hash;

	hash = Com_HashString(dvarName, 0);
	return Dvar_FindMalleableVar(hash);
}

/*
==============
Dvar_FindVar
==============
*/
dvar_t *Dvar_FindVar(const char *dvarName)
{
	assert(dvarName);
	if (dvarName && dvarName[0])
	{
		return Dvar_FindMalleableVar(dvarName);
	}

	return NULL;
}

/*
==============
Dvar_FindVar
==============
*/
dvar_t *Dvar_FindVar(int dvarHash)
{
	return Dvar_FindMalleableVar(dvarHash);
}

/*
==============
Dvar_ClearModified
==============
*/
void Dvar_ClearModified(dvar_t *dvar)
{
	assert(dvar);
	dvar->modified = false;
}

/*
==============
Dvar_SetModified
==============
*/
void Dvar_SetModified(dvar_t *dvar)
{
	assert(dvar);
	dvar->modified = true;
}

/*
==============
Dvar_GetModified
==============
*/
bool Dvar_GetModified(dvar_t *dvar)
{
	assert(dvar);
	return dvar->modified;
}

/*
==============
Dvar_GetInt
==============
*/
int Dvar_GetInt(const char* dvarName)
{
	dvar_t* dvar;

	dvar = Dvar_FindVar(dvarName);
	if (!dvar)
	{
		return 0;
	}

	assertMsg((dvar->type == DVAR_TYPE_BOOL || dvar->type == DVAR_TYPE_INT || dvar->type == DVAR_TYPE_FLOAT
		|| dvar->type == DVAR_TYPE_ENUM || (dvar->type == DVAR_TYPE_STRING && (dvar->flags & DVAR_EXTERNAL))),
		"(dvar->type) = %i", dvar->type);

	switch (dvar->type)
	{
	case DVAR_TYPE_INT:
	case DVAR_TYPE_ENUM:
		return dvar->current.integer;
	case DVAR_TYPE_BOOL:
		return dvar->current.enabled != 0;
	case DVAR_TYPE_FLOAT:
		return (int)dvar->current.value;
	}

	return Dvar_StringToInt(dvar->current.string);
}

/*
==============
Dvar_GetUnsignedInt
==============
*/
unsigned int Dvar_GetUnsignedInt(const dvar_t *dvar)
{
	assert(dvar);
	return dvar->current.unsignedInt;
}

/*
==============
Dvar_GetFloat
==============
*/
double Dvar_GetFloat(const dvar_t* dvar)
{
	dvarType_t type;

	assert(dvar);
	type = dvar->type;
	if (type != DVAR_TYPE_FLOAT)
	{
		Com_PrintWarning(23, "Dvar '%s' silently casting to a different type (%s -> float)\n", dvar->name, s_dvarTypeNames[type]);
		if (type == DVAR_TYPE_INT)
			return (double)dvar->current.integer;
		if (type == DVAR_TYPE_STRING)
			return Dvar_StringToFloat(dvar->current.string);
		return 0.0;
	}
	return dvar->current.value;
}

const vec2_t vec2_origin = { { 0.0, 0.0 } };

/*
==============
Dvar_GetVec2
==============
*/
void Dvar_GetVec2(const dvar_t *dvar, vec2_t *result)
{
	if (!dvar || dvar->type != DVAR_TYPE_FLOAT_2)
	{
		*result = vec2_origin;
		return;
	}
	// originally it was
	// *result = *(vec2_t*)&dvar->current.integer64;
	// but fuck that, i'll just use the damn vector
	// instead of casting from a int64
	result->x = dvar->current.vector.v[0];
	result->y = dvar->current.vector.v[1];
}

const vec3_t vec3_origin = { { 0.0, 0.0, 0.0 } };

/*
==============
Dvar_GetVec3
==============
*/
void Dvar_GetVec3(const dvar_t *dvar, vec3_t *result)
{
	if (!dvar || (dvar->type != DVAR_TYPE_FLOAT_3 && dvar->type != DVAR_TYPE_LINEAR_COLOR_RGB))
	{
		*result = vec3_origin;
		return;
	}
	result->x = dvar->current.vector.v[0];
	result->y = dvar->current.vector.v[1];
	result->z = dvar->current.vector.v[2];
}

vec4_t vec4_origin = { { 0.0, 0.0, 0.0, 0.0 } };

/*
==============
Dvar_GetVec4
==============
*/
void Dvar_GetVec4(const dvar_t *dvar, vec4_t *result)
{
	if (!dvar || dvar->type != DVAR_TYPE_FLOAT_4)
	{
		*result = vec4_origin;
		return;
	}
	result->x = dvar->current.vector.v[0];
	result->y = dvar->current.vector.v[1];
	result->z = dvar->current.vector.v[2];
	result->w = dvar->current.vector.v[3];
}

/*
==============
Dvar_GetString
==============
*/
const char *Dvar_GetString(const dvar_t *dvar)
{
	if (!dvar || (dvar->type != DVAR_TYPE_STRING && dvar->type != DVAR_TYPE_ENUM))
	{
		return "";
	}
	if (dvar->type == DVAR_TYPE_ENUM)
		return Dvar_EnumToString(dvar);
	else
		return dvar->current.string;
}

/*
==============
Dvar_GetVariantString
==============
*/
const char *Dvar_GetVariantString(int dvarHash)
{
	dvar_t* MalleableVar;

	MalleableVar = Dvar_FindMalleableVar(dvarHash);
	if (MalleableVar)
		return Dvar_ValueToString(MalleableVar, MalleableVar->current);
	else
		return "";
}

/*
==============
Dvar_GetVariantString
==============
*/
const char *__cdecl Dvar_GetVariantString(const dvar_t *dvar)
{
	if (dvar)
		return Dvar_ValueToString(dvar, dvar->current);
	else
		return "";
}

/*
==============
Dvar_GetUnpackedColor
==============
*/
void Dvar_GetUnpackedColor(const dvar_t *dvar, vec4_t *expandedColor)
{
	unsigned char color[4];

	assert(dvar);
	assertMsg((dvar->type == DVAR_TYPE_COLOR || (dvar->type == DVAR_TYPE_STRING && (dvar->flags & DVAR_EXTERNAL))),
		"(dvar->type) = %i", dvar->type);

	if (dvar->type == DVAR_TYPE_COLOR)
	{
		memcpy(color, dvar->current.color, sizeof(color));
	}
	else
	{
		Dvar_StringToColor(dvar->current.string, color);
	}

	expandedColor->r = (float)color[0] / 255.0f;
	expandedColor->g = (float)color[1] / 255.0f;
	expandedColor->b = (float)color[2] / 255.0f;
	expandedColor->a = (float)color[3] / 255.0f;
}

/*
==============
Dvar_GetColor
==============
*/
void Dvar_GetColor(const dvar_t *dvar, unsigned __int8 *color)
{
	assert(dvar);
	if (dvar->type == DVAR_TYPE_COLOR)
		memcpy(color, dvar->current.color, sizeof(dvar->current.color));
}

/*
==============
Dvar_GetColorRed
==============
*/
double Dvar_GetColorRed(const dvar_t *dvar)
{
	vec4_t expandedColor;

	Dvar_GetUnpackedColor(dvar, &expandedColor);
	return expandedColor.r;
}

/*
==============
Dvar_GetColorRed
==============
*/
double Dvar_GetColorRed(int dvarHash)
{
	vec4_t expandedColor;
	dvar_t* MalleableVar;

	MalleableVar = Dvar_FindMalleableVar(dvarHash);
	Dvar_GetUnpackedColor(MalleableVar, &expandedColor);
	return expandedColor.r;
}

/*
==============
Dvar_GetColorGreen
==============
*/
double Dvar_GetColorGreen(const dvar_t *dvar)
{
	vec4_t expandedColor;

	Dvar_GetUnpackedColor(dvar, &expandedColor);
	return expandedColor.g;
}

/*
==============
Dvar_GetColorGreen
==============
*/
double Dvar_GetColorGreen(int dvarHash)
{
	vec4_t expandedColor;
	dvar_t* MalleableVar;

	MalleableVar = Dvar_FindMalleableVar(dvarHash);
	Dvar_GetUnpackedColor(MalleableVar, &expandedColor);
	return expandedColor.g;
}

/*
==============
Dvar_GetColorBlue
==============
*/
double Dvar_GetColorBlue(const dvar_t *dvar)
{
	vec4_t expandedColor;

	Dvar_GetUnpackedColor(dvar, &expandedColor);
	return expandedColor.b;
}

/*
==============
Dvar_GetColorBlue
==============
*/
double Dvar_GetColorBlue(int dvarHash)
{
	vec4_t expandedColor;
	dvar_t* MalleableVar;

	MalleableVar = Dvar_FindMalleableVar(dvarHash);
	Dvar_GetUnpackedColor(MalleableVar, &expandedColor);
	return expandedColor.b;
}

/*
==============
Dvar_GetColorAlpha
==============
*/
double Dvar_GetColorAlpha(const dvar_t *dvar)
{
	vec4_t expandedColor;

	Dvar_GetUnpackedColor(dvar, &expandedColor);
	return expandedColor.a;
}

/*
==============
Dvar_GetColorAlpha
==============
*/
double Dvar_GetColorAlpha(int dvarHash)
{
	vec4_t expandedColor;
	dvar_t* MalleableVar;

	MalleableVar = Dvar_FindMalleableVar(dvarHash);
	Dvar_GetUnpackedColor(MalleableVar, &expandedColor);
	return expandedColor.a;
}

/*
==============
Dvar_GetLatchedBool
==============
*/
bool Dvar_GetLatchedBool(const dvar_t *dvar)
{
	if (!dvar)
		return 0;
	return dvar->latched.enabled;
}

/*
==============
Dvar_GetLatchedInt
==============
*/
int Dvar_GetLatchedInt(const dvar_t *dvar)
{
	if (!dvar)
		return 0;
	return dvar->latched.integer;
}

/*
==============
Dvar_GetLatchedFloat
==============
*/
double Dvar_GetLatchedFloat(const dvar_t *dvar)
{
	if (!dvar)
		return 0.0;
	return dvar->latched.value;
}

/*
==============
Dvar_GetLatchedVec2
==============
*/
void Dvar_GetLatchedVec2(const dvar_t *dvar, vec2_t *result)
{
	if (!dvar)
		memcpy(result, &vec2_origin, sizeof(vec2_t));
	else
	{
		result->x = dvar->latched.vector.v[0];
		result->y = dvar->latched.vector.v[1];
	}
}

/*
==============
Dvar_GetLatchedVec3
==============
*/
void Dvar_GetLatchedVec3(const dvar_t *dvar, vec3_t *result)
{
	if (!dvar)
		memcpy(result, &vec3_origin, sizeof(vec3_t));
	else
	{
		result->x = dvar->latched.vector.v[0];
		result->y = dvar->latched.vector.v[1];
		result->z = dvar->latched.vector.v[2];
	}
}

/*
==============
Dvar_GetLatchedVec4
==============
*/
void Dvar_GetLatchedVec4(const dvar_t *dvar, vec4_t *result)
{
	if (!dvar)
		memcpy(result, &vec4_origin, sizeof(vec4_t));
	else
	{
		result->x = dvar->latched.vector.v[0];
		result->y = dvar->latched.vector.v[1];
		result->z = dvar->latched.vector.v[2];
		result->w = dvar->latched.vector.v[3];
	}
}

/*
==============
Dvar_GetLatchedColor
==============
*/
void Dvar_GetLatchedColor(const dvar_t *dvar, unsigned __int8 *color)
{
	if (dvar->type == DVAR_TYPE_COLOR)
		memcpy(color, dvar->latched.color, sizeof(dvar->latched.color));
}

/*
==============
Dvar_GetResetInt
==============
*/
int Dvar_GetResetInt(const dvar_t *dvar)
{
	if (!dvar)
		return 0;
	return dvar->reset.integer;
}

/*
==============
Dvar_GetResetString
==============
*/
const char *Dvar_GetResetString(const dvar_t *dvar)
{
	if (!dvar)
		return "";
	return dvar->reset.string;
}

/*
==============
Dvar_GetResetVec3
==============
*/
void Dvar_GetResetVec3(const dvar_t *dvar, vec3_t *result)
{
	if (!dvar)
		memcpy(result, &vec3_origin, sizeof(vec3_t));
	else
	{
		result->x = dvar->reset.vector.v[0];
		result->y = dvar->reset.vector.v[1];
		result->z = dvar->reset.vector.v[2];
	}
}

/*
==============
Dvar_GetDomainEnumStrings
==============
*/
const char **Dvar_GetDomainEnumStrings(const dvar_t *dvar)
{
	if (!dvar)
		return NULL;
	return dvar->domain.enumeration.strings;
}

/*
==============
Dvar_GetDomainEnumStringCount
==============
*/
int Dvar_GetDomainEnumStringCount(const dvar_t *dvar)
{
	if (!dvar)
		return 0;
	return dvar->domain.enumeration.stringCount;
}

/*
==============
Dvar_GetDomainIntMin
==============
*/
int Dvar_GetDomainIntMin(const dvar_t *dvar)
{
	if (!dvar)
		return 0;
	if (dvar->type == DVAR_TYPE_ENUM)
		return dvar->domain.enumeration.stringCount;
	return dvar->domain.integer.min;
}

/*
==============
Dvar_GetDomainIntMax
==============
*/
int Dvar_GetDomainIntMax(const dvar_t *dvar)
{
	if (!dvar)
		return 0;
	if (dvar->type == DVAR_TYPE_ENUM)
		return dvar->domain.enumeration.stringCount;
	return dvar->domain.integer.max;
}

/*
==============
Dvar_GetDomainInt64Min
==============
*/
__int64 Dvar_GetDomainInt64Min(const dvar_t *dvar)
{
	if (!dvar)
		return 0;
	if (dvar->type == DVAR_TYPE_ENUM)
		return dvar->domain.enumeration.stringCount;
	return dvar->domain.integer64.min;
}

/*
==============
Dvar_GetDomainInt64Max
==============
*/
__int64 Dvar_GetDomainInt64Max(const dvar_t *dvar)
{
	if (!dvar)
		return 0;
	if (dvar->type == DVAR_TYPE_ENUM)
		return dvar->domain.enumeration.stringCount;
	return dvar->domain.integer64.max;
}

/*
==============
Dvar_GetDomainFloatMin
==============
*/
double Dvar_GetDomainFloatMin(const dvar_t *dvar)
{
	if (!dvar)
		return 0;
	if (dvar->type == DVAR_TYPE_ENUM)
		return dvar->domain.enumeration.stringCount;
	return dvar->domain.value.min;
}

/*
==============
Dvar_GetDomainFloatMax
==============
*/
double Dvar_GetDomainFloatMax(const dvar_t *dvar)
{
	if (!dvar)
		return 0;
	if (dvar->type == DVAR_TYPE_ENUM)
		return dvar->domain.enumeration.stringCount;
	return dvar->domain.value.max;
}

/*
==============
Dvar_GetDomainVecMin
==============
*/
double Dvar_GetDomainVecMin(const dvar_t *dvar)
{
	if (!dvar)
		return 0;
	if (dvar->type == DVAR_TYPE_ENUM)
		return dvar->domain.enumeration.stringCount;
	return dvar->domain.vector.min;
}

/*
==============
Dvar_GetDomainVecMax
==============
*/
double Dvar_GetDomainVecMax(const dvar_t *dvar)
{
	if (!dvar)
		return 0;
	if (dvar->type == DVAR_TYPE_ENUM)
		return dvar->domain.enumeration.stringCount;
	return dvar->domain.vector.max;
}

/*
==============
Dvar_GetType
==============
*/
dvarType_t Dvar_GetType(const dvar_t *dvar)
{
	if (!dvar)
		return DVAR_TYPE_COUNT;
	return dvar->type;
}

/*
==============
Dvar_GetCurrent
==============
*/
DvarValue Dvar_GetCurrent(const dvar_t *dvar)
{
	if (!dvar)
		return DvarValue();
	return dvar->current;
}

/*
==============
Dvar_GetDomain
==============
*/
DvarLimits Dvar_GetDomain(const dvar_t *dvar)
{
	if (!dvar)
		return DvarLimits();
	return dvar->domain;
}

/*
==============
Dvar_GetDescription
==============
*/
const char *Dvar_GetDescription(const dvar_t *dvar)
{
	if (!dvar)
		return "";
	return dvar->description;
}

/*
==============
Dvar_GetFlags
==============
*/
unsigned int Dvar_GetFlags(const dvar_t *dvar)
{
	if (!dvar)
		return 0;
	return dvar->flags;
}

/*
==============
Dvar_GetName
==============
*/
const char *Dvar_GetName(const dvar_t *dvar)
{
	if (!dvar)
		return "";
	return dvar->name;
}

/*
==============
Dvar_Shutdown
==============
*/
void Dvar_Shutdown()
{
	int dvarIter;
	dvar_t* dvar;

	Sys_LockWrite(&g_dvarCritSect);
	s_isDvarSystemActive = 0;
	for (dvarIter = 0; dvarIter < g_dvarCount; ++dvarIter)
	{
		dvar = &s_dvarPool[dvarIter];
		if (dvar->type == DVAR_TYPE_STRING)
		{
			if (Dvar_ShouldFreeCurrentString(dvar))
			{
				Dvar_FreeString(&dvar->current);
			}

			dvar->current.integer = 0;
			if (Dvar_ShouldFreeResetString(dvar))
			{
				Dvar_FreeString(&dvar->reset);
			}

			dvar->reset.integer = 0;
			if (Dvar_ShouldFreeLatchedString(dvar))
			{
				Dvar_FreeString(&dvar->latched);
			}
			dvar->latched.integer = 0;
		}

		if (dvar->flags & DVAR_EXTERNAL)
		{
			FreeString(dvar->name);
		}
	}

	g_dvarCount = 0;
	dvar_cheats = NULL;
	g_dvar_modifiedFlags = 0;
	memset(s_dvarHashTable, 0, sizeof(s_dvarHashTable));
	Sys_UnlockWrite(&g_dvarCritSect);
}

/*
==============
Dvar_PerformUnregistration
==============
*/
void Dvar_PerformUnregistration(dvar_t *dvar)
{
	DvarValue resetString;

	assert(dvar);
	if (!(dvar->flags & DVAR_EXTERNAL))
	{
		dvar->flags |= DVAR_EXTERNAL;
		dvar->name = CopyString(dvar->name);
	}

	if (dvar->type != DVAR_TYPE_STRING)
	{
		Dvar_CopyString(Dvar_DisplayableLatchedValue(dvar), &dvar->current);
		if (Dvar_ShouldFreeLatchedString(dvar))
		{
			Dvar_FreeString(&dvar->latched);
		}

		dvar->latched.string = 0;
		Dvar_WeakCopyString(dvar->current.string, &dvar->latched);
		if (Dvar_ShouldFreeResetString(dvar))
		{
			Dvar_FreeString(&dvar->reset);
		}

		dvar->reset.string = 0;
		Dvar_AssignResetStringValue(dvar, &resetString, Dvar_DisplayableResetValue(dvar));
		dvar->reset.string = resetString.string;
		dvar->type = DVAR_TYPE_STRING;
	}
}

/*
==============
Dvar_UpdateResetValue
==============
*/
void Dvar_UpdateResetValue(dvar_t *dvar, DvarValue value)
{
	DvarValue oldString;
	bool shouldFree;
	DvarValue resetString;

	assert(dvar);
	switch (dvar->type)
	{
	case DVAR_TYPE_FLOAT_2:
		dvar->reset.vector.v[0] = value.vector.v[0];
		dvar->reset.vector.v[1] = value.vector.v[1];
		break;
	case DVAR_TYPE_FLOAT_3:
	case DVAR_TYPE_LINEAR_COLOR_RGB:
	case DVAR_TYPE_COLOR_XYZ:
		dvar->reset.vector.v[0] = value.vector.v[0];
		dvar->reset.vector.v[1] = value.vector.v[1];
		dvar->reset.vector.v[2] = value.vector.v[2];
		break;
	case DVAR_TYPE_FLOAT_4:
		dvar->reset.vector.v[0] = value.vector.v[0];
		dvar->reset.vector.v[1] = value.vector.v[1];
		dvar->reset.vector.v[2] = value.vector.v[2];
		dvar->reset.vector.v[3] = value.vector.v[3];
		break;
	case DVAR_TYPE_STRING:
		if (dvar->reset.string != value.string)
		{
			shouldFree = Dvar_ShouldFreeResetString(dvar);
			if (shouldFree)
			{
				oldString.string = dvar->reset.string;
			}
			Dvar_AssignResetStringValue(dvar, &resetString, value.string);
			dvar->reset = resetString;
			if (shouldFree)
			{
				Dvar_FreeString(&oldString);
			}
		}
		break;
	default:
		dvar->reset = value;
		break;
	}
}

/*
==============
Dvar_ChangeResetValue
==============
*/
void Dvar_ChangeResetValue(const dvar_t *dvar, DvarValue value)
{
	assert(dvar);
	assert(dvar->name);
	assertMsg((dvar->flags & DVAR_SAVED), "(dvar->name) = %s", dvar->name);
	Dvar_UpdateResetValue((dvar_t*)dvar, value);
}

/*
==============
Dvar_UpdateValue
==============
*/
void Dvar_UpdateValue(dvar_t *dvar, DvarValue value)
{
	DvarValue oldString;
	bool shouldFree;
	DvarValue currentString;

	assert(dvar);
	switch (dvar->type)
	{
	case DVAR_TYPE_FLOAT_2:
		dvar->current.vector.v[0] = value.vector.v[0];
		dvar->current.vector.v[1] = value.vector.v[1];

		dvar->latched.vector.v[0] = value.vector.v[0];
		dvar->latched.vector.v[1] = value.vector.v[1];
		break;
	case DVAR_TYPE_FLOAT_3:
	case DVAR_TYPE_LINEAR_COLOR_RGB:
	case DVAR_TYPE_COLOR_XYZ:
		dvar->current.vector.v[0] = value.vector.v[0];
		dvar->current.vector.v[1] = value.vector.v[1];
		dvar->current.vector.v[2] = value.vector.v[2];

		dvar->latched.vector.v[0] = value.vector.v[0];
		dvar->latched.vector.v[1] = value.vector.v[1];
		dvar->latched.vector.v[2] = value.vector.v[2];
		break;
	case DVAR_TYPE_FLOAT_4:
		dvar->current.vector.v[0] = value.vector.v[0];
		dvar->current.vector.v[1] = value.vector.v[1];
		dvar->current.vector.v[2] = value.vector.v[2];
		dvar->current.vector.v[3] = value.vector.v[3];

		dvar->latched.vector.v[0] = value.vector.v[0];
		dvar->latched.vector.v[1] = value.vector.v[1];
		dvar->latched.vector.v[2] = value.vector.v[2];
		dvar->latched.vector.v[3] = value.vector.v[3];
		break;
	case DVAR_TYPE_STRING:
		if (value.integer != dvar->current.integer)
		{
			shouldFree = Dvar_ShouldFreeCurrentString(dvar);
			if (shouldFree)
			{
				oldString.integer = dvar->current.integer;
			}
			Dvar_AssignCurrentStringValue(dvar, &currentString, value.string);
			dvar->current.integer = currentString.integer;
			if (Dvar_ShouldFreeLatchedString(dvar))
			{
				Dvar_FreeString(&dvar->latched);
			}
			dvar->latched.integer = 0;
			Dvar_WeakCopyString(dvar->current.string, &dvar->latched);
			if (shouldFree)
			{
				Dvar_FreeString(&oldString);
			}
		}
		break;
	default:
		dvar->current = value;
		dvar->latched = value;
		break;
	}
}

/*
==============
Dvar_MakeExplicitType
==============
*/
void Dvar_MakeExplicitType(dvar_t *dvar, const char *dvarName, dvarType_t type, unsigned int flags, DvarValue resetValue, DvarLimits domain)
{
	bool wasString;
	DvarValue castValue;

	assertMsg(dvar->type == DVAR_TYPE_STRING, va("dvar %s, type %i", dvar->name, dvar->type));

	dvar->type = type;
	dvar->domain = domain;
	if (flags & DVAR_ROM || flags & DVAR_CHEAT && dvar_cheats && !dvar_cheats->current.enabled)
	{
		castValue = resetValue;
	}
	else
	{
		castValue = Dvar_StringToValue(dvar->type, dvar->domain, dvar->current.string);
		castValue = Dvar_ClampValueToDomain(type, castValue, resetValue, domain);
	}

	wasString = dvar->type == DVAR_TYPE_STRING && castValue.integer;
	if (wasString)
	{
		castValue.string = CopyString(castValue.string);
	}

	if (dvar->type != DVAR_TYPE_STRING && Dvar_ShouldFreeCurrentString(dvar))
	{
		Dvar_FreeString(&dvar->current);
	}

	dvar->current.string = 0;
	if (Dvar_ShouldFreeLatchedString(dvar))
	{
		Dvar_FreeString(&dvar->latched);
	}

	dvar->latched.string = 0;
	if (Dvar_ShouldFreeResetString(dvar))
	{
		Dvar_FreeString(&dvar->reset);
	}

	dvar->reset.string = 0;
	Dvar_UpdateResetValue(dvar, resetValue);
	Dvar_UpdateValue(dvar, castValue);

	g_dvar_modifiedFlags |= flags;

	if (wasString)
	{
		FreeString(castValue.string);
	}
}

/*
==============
Dvar_ReinterpretDvar
==============
*/
void Dvar_ReinterpretDvar(dvar_t *dvar, const char *dvarName, dvarType_t type, unsigned int flags, DvarValue value, DvarLimits domain)
{
	DvarValue resetValue;

	if (dvar->flags & DVAR_EXTERNAL && !(flags & DVAR_EXTERNAL))
	{
		resetValue = value;
		Dvar_PerformUnregistration(dvar);
		FreeString(dvar->name);
		dvar->name = dvarName;
		dvar->flags &= ~DVAR_EXTERNAL;

		Dvar_MakeExplicitType(dvar, dvarName, type, flags, resetValue, domain);
	}
}

/*
==============
Dvar_RegisterNew
==============
*/
dvar_t *Dvar_RegisterNew(const char *dvarName, dvarType_t type, unsigned int flags, DvarValue value, DvarLimits domain, const char *description)
{
	dvar_t* var;
	int hash;
	dvar_t* dvar;

	Sys_LockWrite(&g_dvarCritSect);
	if (g_dvarCount >= 4320)
	{
		Sys_UnlockWrite(&g_dvarCritSect);
		Com_Error(ERR_FATAL, "Can't create dvar '%s': %i dvars already exist", dvarName, 4320);
	}

	dvar = &s_dvarPool[g_dvarCount];
	s_sortedDvars[g_dvarCount] = dvar;

	s_areDvarsSorted = false;
	++g_dvarCount;
	dvar->type = type;

	if (flags & DVAR_EXTERNAL)
	{
		dvar->name = CopyString(dvarName);
	}
	else
	{
		dvar->name = dvarName;
	}

	switch (type)
	{
	case DVAR_TYPE_FLOAT_2:
		dvar->current.vector.v[0] = value.vector.v[0];
		dvar->current.vector.v[1] = value.vector.v[1];

		dvar->latched.vector.v[0] = value.vector.v[0];
		dvar->latched.vector.v[1] = value.vector.v[1];

		dvar->reset.vector.v[0] = value.vector.v[0];
		dvar->reset.vector.v[1] = value.vector.v[1];
		break;
	case DVAR_TYPE_FLOAT_3:
	case DVAR_TYPE_LINEAR_COLOR_RGB:
	case DVAR_TYPE_COLOR_XYZ:
		dvar->current.vector.v[0] = value.vector.v[0];
		dvar->current.vector.v[1] = value.vector.v[1];
		dvar->current.vector.v[2] = value.vector.v[2];

		dvar->latched.vector.v[0] = value.vector.v[0];
		dvar->latched.vector.v[1] = value.vector.v[1];
		dvar->latched.vector.v[2] = value.vector.v[2];

		dvar->reset.vector.v[0] = value.vector.v[0];
		dvar->reset.vector.v[1] = value.vector.v[1];
		dvar->reset.vector.v[2] = value.vector.v[2];
		break;
	case DVAR_TYPE_FLOAT_4:
		dvar->current.vector.v[0] = value.vector.v[0];
		dvar->current.vector.v[1] = value.vector.v[1];
		dvar->current.vector.v[2] = value.vector.v[2];
		dvar->current.vector.v[3] = value.vector.v[3];

		dvar->latched.vector.v[0] = value.vector.v[0];
		dvar->latched.vector.v[1] = value.vector.v[1];
		dvar->latched.vector.v[2] = value.vector.v[2];
		dvar->latched.vector.v[3] = value.vector.v[3];

		dvar->reset.vector.v[0] = value.vector.v[0];
		dvar->reset.vector.v[1] = value.vector.v[1];
		dvar->reset.vector.v[2] = value.vector.v[2];
		dvar->reset.vector.v[3] = value.vector.v[3];
		break;
	case DVAR_TYPE_STRING:
		Dvar_CopyString(value.string, &dvar->current);
		Dvar_WeakCopyString(dvar->current.string, &dvar->latched);
		Dvar_WeakCopyString(dvar->current.string, &dvar->reset);
		break;
	default:
		dvar->current = value;
		dvar->latched = value;
		dvar->reset = value;
		break;
	}

	dvar->domain = domain;
	dvar->modified = false;
	dvar->flags = flags;
	dvar->description = description;
	hash = Com_HashString(dvarName, 0);
	dvar->hash = hash;

	for (var = s_dvarHashTable[hash & 0x437]; var; var = var->hashNext)
	{
		if (I_stricmp(dvarName, var->name) && hash == var->hash)
		{
			Com_Error(ERR_FATAL, "dvar name hash collision between '%s' and '%s' Please change one of these names to remove the hash collision\n",
				dvarName, var->name);
		}
	}

	dvar->hashNext = s_dvarHashTable[hash & 0x437];
	s_dvarHashTable[hash & 0x437] = dvar;
	Sys_UnlockWrite(&g_dvarCritSect);

	return dvar;
}

/*
==============
Dvar_AddFlags
==============
*/
void Dvar_AddFlags(dvar_t *dvar, int flags)
{
	assert(dvar);
	assertMsg(((flags & (DVAR_CHEAT | DVAR_INIT | DVAR_ROM | DVAR_EXTERNAL | DVAR_LATCH)) == 0), "(flags) = %i", flags);

	dvar->flags |= flags;
}

/*
==============
Com_SaveDvarsToBuffer
==============
*/
int Com_SaveDvarsToBuffer(const char **dvarnames, unsigned int numDvars, char *buffer, unsigned int bufsize)
{
	const char* string;
	int ret;
	int written;
	unsigned int i;
	dvar_t* dvar;

	ret = 1;
	for (i = 0; i < numDvars; ++i)
	{
		dvar = Dvar_FindVar(dvarnames[i]);
		assert(dvar);
		string = Dvar_DisplayableValue(dvar);
		written = _snprintf(buffer, bufsize, "%s \"%s\"\n", dvar->name, string);
		if (written < 0)
		{
			return 0;
		}

		buffer += written;
		bufsize -= written;
	}

	return ret;
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
	s_canSetConfigDvars = canSetConfigDvars;
}

/*
==============
Dvar_CanSetConfigDvar
==============
*/
bool Dvar_CanSetConfigDvar(const dvar_t *dvar)
{
	if (!dvar)
		return 0;
	return (dvar->flags & 0x20000) == 0 || !Sys_IsMainThread() || s_canSetConfigDvars;
}

/*
==============
Dvar_CanChangeValue
==============
*/
bool Dvar_CanChangeValue(const dvar_t *dvar, DvarValue value, DvarSetSource source)
{
	char* reason;

	assert(dvar);
	if (!dvar)
	{
		return 0;
	}

	if (Dvar_ValuesEqual(dvar->type, value, dvar->reset))
	{
		return 1;
	}

	reason = NULL;
	if (dvar->flags & DVAR_ROM)
	{
		reason = va("%s is read only.\n", dvar->name);
	}
	else if (dvar->flags & DVAR_INIT)
	{
		reason = va("%s is write protected.\n", dvar->name);
	}
	else if (dvar->flags & DVAR_CHEAT && !dvar_cheats->current.enabled)
	{
		if (source == DVAR_SOURCE_EXTERNAL || source == DVAR_SOURCE_SCRIPT)
		{
			reason = va("%s is cheat protected.\n", dvar->name);
		}
	}

	if (!reason)
	{
		return 1;
	}

	Com_Printf(CON_CHANNEL_ERROR, reason);
	return 0;
}

/*
==============
Dvar_SetVariant
==============
*/
void Dvar_SetVariant(dvar_t *dvar, DvarValue value, DvarSetSource source)
{
	bool shouldFreeString;
	char string[1024];
	DvarValue oldString;
	DvarValue currentString;

	assert(dvar);
	assert(dvar->name);
	if (!dvar || !dvar->name || !dvar->name[0])
	{
		return;
	}

	if (Com_LogFileOpen())
	{
		if (!Dvar_ValuesEqual(dvar->type, dvar->current, value))
		{
			Com_sprintf(string, sizeof(string), "      dvar set %s %s\n", dvar->name, Dvar_ValueToString(dvar, value));
			Com_PrintMessage(6, string, 0);
		}
	}

	if (!Dvar_ValueInDomain(dvar->type, value, dvar->domain))
	{
		Com_Printf(CON_CHANNEL_ERROR, "'%s' is not a valid value for dvar '%s'\n", Dvar_ValueToString(dvar, value), dvar->name);
		Dvar_PrintDomain(dvar->type, dvar->domain);
		if (dvar->type == DVAR_TYPE_ENUM)
		{
			assertMsg((Dvar_ValueInDomain(dvar->type, dvar->reset, dvar->domain)), "(dvar->name) = %s", dvar->name);
			Dvar_SetVariant(dvar, dvar->reset, source);
		}
		return;
	}
	if (source != DVAR_SOURCE_EXTERNAL && source != DVAR_SOURCE_SCRIPT)
	{
		if (source == DVAR_SOURCE_DEVGUI && dvar->flags & 0x800)
		{
			Dvar_SetLatchedValue(dvar, value);
			return;
		}
	}
	else
	{
		if (!Dvar_CanChangeValue(dvar, value, source))
		{
			return;
		}
		if (dvar->flags & DVAR_LATCH)
		{
			Dvar_SetLatchedValue(dvar, value);
			if (!Dvar_ValuesEqual(dvar->type, dvar->latched, dvar->current))
			{
				Com_Printf(CON_CHANNEL_SYSTEM, "%s will be changed upon restarting.\n", dvar->name);
			}
			return;
		}
	}

	if (Dvar_ValuesEqual(dvar->type, dvar->current, value))
	{
		Dvar_SetLatchedValue(dvar, dvar->current);
	}
	else
	{
		g_dvar_modifiedFlags |= dvar->flags;

		switch (dvar->type)
		{
		case DVAR_TYPE_FLOAT_2:
			dvar->current.vector.v[0] = value.vector.v[0];
			dvar->current.vector.v[1] = value.vector.v[1];

			dvar->latched.vector.v[0] = value.vector.v[0];
			dvar->latched.vector.v[1] = value.vector.v[1];
			break;
		case DVAR_TYPE_FLOAT_3:
		case DVAR_TYPE_LINEAR_COLOR_RGB:
		case DVAR_TYPE_COLOR_XYZ:
			dvar->current.vector.v[0] = value.vector.v[0];
			dvar->current.vector.v[1] = value.vector.v[1];
			dvar->current.vector.v[2] = value.vector.v[2];

			dvar->latched.vector.v[0] = value.vector.v[0];
			dvar->latched.vector.v[1] = value.vector.v[1];
			dvar->latched.vector.v[2] = value.vector.v[2];
			break;
		case DVAR_TYPE_FLOAT_4:
			dvar->current.vector.v[0] = value.vector.v[0];
			dvar->current.vector.v[1] = value.vector.v[1];
			dvar->current.vector.v[2] = value.vector.v[2];
			dvar->current.vector.v[3] = value.vector.v[3];

			dvar->latched.vector.v[0] = value.vector.v[0];
			dvar->latched.vector.v[1] = value.vector.v[1];
			dvar->latched.vector.v[2] = value.vector.v[2];
			dvar->latched.vector.v[3] = value.vector.v[3];
			break;
		case DVAR_TYPE_STRING:
			assert(dvar->name);
			assertMsg((value.string != dvar->current.string || value.string == dvar->latched.string || value.string == dvar->reset.string),
				"(dvar->name) = %s", dvar->name);

			shouldFreeString = Dvar_ShouldFreeCurrentString(dvar);
			if (shouldFreeString)
			{
				oldString.string = dvar->current.string;
			}

			Dvar_AssignCurrentStringValue(dvar, &currentString, value.string);
			dvar->current.string = currentString.string;

			if (Dvar_ShouldFreeLatchedString(dvar))
			{
				Dvar_FreeString(&dvar->latched);
			}

			dvar->latched.string = NULL;
			Dvar_WeakCopyString(dvar->current.string, &dvar->latched);
			if (shouldFreeString)
			{
				Dvar_FreeString(&oldString);
			}
			break;
		default:
			dvar->current = value;
			dvar->latched = value;
			break;
		}

		dvar->modified = true;
	}
}

/*
==============
Dvar_UpdateEnumDomain
==============
*/
void Dvar_UpdateEnumDomain(dvar_t *dvar, const char **stringTable)
{
	int stringCount;
	dvar_t* malleableDvar;

	assert(dvar);
	assert(dvar->name);
	assertMsg((stringTable), "(dvar->name) = %s", dvar->name);
	assertMsg(dvar->type == DVAR_TYPE_ENUM, va("dvar %s type %i", dvar->name, dvar->type));

	stringCount = 0;
	while (stringTable[stringCount] != NULL)
	{
		stringCount++;
	}

	assertMsg(dvar->reset.integer >= 0 && (dvar->reset.integer < stringCount || dvar->reset.integer == 0),
		va("name %s reset %i count %i", dvar->name, dvar->reset.integer, stringCount));

	malleableDvar = dvar;
	malleableDvar->domain.enumeration.stringCount = stringCount;
	malleableDvar->domain.enumeration.strings = stringTable;
	malleableDvar->current = Dvar_ClampValueToDomain(dvar->type, dvar->current, dvar->reset, dvar->domain);
	malleableDvar->latched = dvar->current;
}

/*
==============
Dvar_GetBool
==============
*/
bool Dvar_GetBool(const dvar_t *dvar)
{
	if (!dvar)
	{
		return false;
	}

	assertMsg((dvar->type == DVAR_TYPE_BOOL || (dvar->type == DVAR_TYPE_STRING && (dvar->flags & DVAR_EXTERNAL))),
		"(dvar->type) = %i", dvar->type);

	if (dvar->type == DVAR_TYPE_BOOL)
	{
		return dvar->current.enabled;
	}

	return Dvar_StringToBool(dvar->current.string);
}

/*
==============
Dvar_GetInt
==============
*/
int Dvar_GetInt(const dvar_t *dvar)
{
	if (!dvar)
	{
		return 0;
	}

	assertMsg((dvar->type == DVAR_TYPE_BOOL || dvar->type == DVAR_TYPE_INT || dvar->type == DVAR_TYPE_FLOAT
		|| dvar->type == DVAR_TYPE_ENUM || (dvar->type == DVAR_TYPE_STRING && (dvar->flags & DVAR_EXTERNAL))),
		"(dvar->type) = %i", dvar->type);

	switch (dvar->type)
	{
	case DVAR_TYPE_INT:
	case DVAR_TYPE_ENUM:
		return dvar->current.integer;
	case DVAR_TYPE_BOOL:
		return dvar->current.enabled != 0;
	case DVAR_TYPE_FLOAT:
		return (int)dvar->current.value;
	}

	return Dvar_StringToInt(dvar->current.string);
}

/*
==============
Dvar_GetInt64
==============
*/
__int64 Dvar_GetInt64(const dvar_t *dvar)
{
	if (!dvar)
	{
		return 0;
	}

	assertMsg((dvar->type == DVAR_TYPE_BOOL || dvar->type == DVAR_TYPE_INT64 || dvar->type == DVAR_TYPE_INT || dvar->type == DVAR_TYPE_FLOAT
		|| dvar->type == DVAR_TYPE_ENUM || (dvar->type == DVAR_TYPE_STRING && (dvar->flags & DVAR_EXTERNAL))),
		"(dvar->type) = %i", dvar->type);

	if (dvar->type == DVAR_TYPE_INT || dvar->type == DVAR_TYPE_ENUM)
		return dvar->current.integer;
	Com_PrintWarning(23, "Dvar '%s' silently casting to a different type (%s -> int64)\n", dvar->name, s_dvarTypeNames[dvar->type]);
	
	switch (dvar->type)
	{
	case DVAR_TYPE_BOOL:
		return dvar->current.enabled;
	case DVAR_TYPE_INT64:
		return dvar->current.integer64;
	case DVAR_TYPE_FLOAT:
		return dvar->current.value;
	}

	return Dvar_StringToInt64(dvar->current.string);
}

/*
==============
Dvar_MakeLatchedValueCurrent
==============
*/
void Dvar_MakeLatchedValueCurrent(dvar_t *dvar)
{
	Dvar_SetVariant(dvar, dvar->latched, DVAR_SOURCE_INTERNAL);
}

/*
==============
Dvar_Reregister
==============
*/
void Dvar_Reregister(dvar_t *dvar, const char *dvarName, dvarType_t type, unsigned int flags, DvarValue resetValue, DvarLimits domain, const char *description)
{
	assert(dvar);
	assert(dvarName);

	assertMsg(dvar->type == type || (dvar->flags & DVAR_EXTERNAL), va("%s: %i != %i", dvarName, dvar->type, type));
	if ((dvar->flags ^ flags) & DVAR_EXTERNAL)
	{
		Dvar_ReinterpretDvar(dvar, dvarName, type, flags, resetValue, domain);
	}

	if (dvar->flags & DVAR_EXTERNAL && dvar->type != type)
	{
		assertMsg(dvar->type == DVAR_TYPE_STRING, va("dvar %s, type %i", dvar->name, dvar->type));
		Dvar_MakeExplicitType(dvar, dvarName, type, flags, resetValue, domain);
	}
	assertMsg((dvar->type == type), "(dvarName) = %s", dvarName);

	assertMsg((dvar->flags & (DVAR_CHANGEABLE_RESET | DVAR_SAVED | DVAR_AUTOEXEC)) || Dvar_ValuesEqual(type, dvar->reset, resetValue),
		va("dvar %s, %s != %s", dvarName, Dvar_DisplayableResetValue(dvar), Dvar_ValueToString(dvar, resetValue)));

	dvar->flags |= flags;
	if (description)
	{
		dvar->description = description;
	}

	if (dvar->flags & DVAR_CHEAT && dvar_cheats && !dvar_cheats->current.enabled)
	{
		Dvar_SetVariant(dvar, dvar->reset, DVAR_SOURCE_INTERNAL);
		Dvar_SetLatchedValue(dvar, dvar->reset);
	}

	if (dvar->flags & DVAR_LATCH)
	{
		Dvar_MakeLatchedValueCurrent(dvar);
	}
}

/*
==============
Dvar_RegisterVariant
==============
*/
dvar_t *Dvar_RegisterVariant(const char *dvarName, dvarType_t type, unsigned int flags, DvarValue value, DvarLimits domain, const char *description)
{
	dvar_t* dvar;

	assertMsg(((flags & DVAR_EXTERNAL) || CanKeepStringPointer(dvarName)), "(dvarName) = %s", dvarName);

	dvar = Dvar_FindMalleableVar(dvarName);
	if (!dvar)
	{
		return Dvar_RegisterNew(dvarName, type, flags, value, domain, description);
	}

	Dvar_Reregister(dvar, dvarName, type, flags, value, domain, description);

	return dvar;
}

/*
==============
_Dvar_RegisterBool
==============
*/
dvar_t *_Dvar_RegisterBool(const char *dvarName, bool value, unsigned int flags, const char *description)
{
	DvarLimits dvarDomain;
	DvarValue dvarValue;

	dvarDomain.integer.min = 0;
	dvarDomain.integer.max = 0;
	dvarValue.enabled = value;
	return Dvar_RegisterVariant(dvarName, DVAR_TYPE_BOOL, flags, dvarValue, dvarDomain, description);
}

/*
==============
_Dvar_RegisterInt
==============
*/
dvar_t *_Dvar_RegisterInt(const char *dvarName, int value, int min, int max, unsigned int flags, const char* description)
{
	DvarLimits dvarDomain;
	DvarValue dvarValue;

	dvarDomain.integer.max = max;
	dvarDomain.integer.min = min;
	dvarValue.integer = value;
	return Dvar_RegisterVariant(dvarName, DVAR_TYPE_INT, flags, dvarValue, dvarDomain, description);
}

/*
==============
_Dvar_RegisterInt64
==============
*/
dvar_t *_Dvar_RegisterInt64(const char *dvarName, __int64 value, __int64 min, __int64 max, unsigned int flags, const char* description)
{
	DvarLimits dvarDomain;
	DvarValue dvarValue;

	dvarDomain.integer64.max = max;
	dvarDomain.integer64.min = min;
	dvarValue.integer64 = value;
	return Dvar_RegisterVariant(dvarName, DVAR_TYPE_INT64, flags, dvarValue, dvarDomain, description);
}

/*
==============
_Dvar_RegisterFloat
==============
*/
dvar_t *_Dvar_RegisterFloat(const char *dvarName, float value, float min, float max, unsigned int flags, const char* description)
{
	DvarLimits dvarDomain;
	DvarValue dvarValue;

	dvarDomain.value.max = max;
	dvarDomain.value.min = min;
	dvarValue.value = value;
	return Dvar_RegisterVariant(dvarName, DVAR_TYPE_FLOAT, flags, dvarValue, dvarDomain, description);
}

/*
==============
_Dvar_RegisterVec2
==============
*/
dvar_t *_Dvar_RegisterVec2(const char *dvarName, float x, float y, float min, float max, unsigned int flags, const char* description)
{
	DvarLimits dvarDomain;
	DvarValue dvarValue;

	dvarDomain.value.max = max;
	dvarDomain.value.min = min;
	dvarValue.vector.v[0] = x;
	dvarValue.vector.v[1] = y;
	return Dvar_RegisterVariant(dvarName, DVAR_TYPE_FLOAT_2, flags, dvarValue, dvarDomain, description);
}

/*
==============
_Dvar_RegisterVec3
==============
*/
dvar_t *_Dvar_RegisterVec3(const char *dvarName, float x, float y, float z, float min, float max, unsigned int flags, const char* description)
{
	DvarLimits dvarDomain;
	DvarValue dvarValue;

	dvarDomain.value.max = max;
	dvarDomain.value.min = min;
	dvarValue.vector.v[0] = x;
	dvarValue.vector.v[1] = y;
	dvarValue.vector.v[2] = z;
	return Dvar_RegisterVariant(dvarName, DVAR_TYPE_FLOAT_3, flags, dvarValue, dvarDomain, description);
}

/*
==============
_Dvar_RegisterVec4
==============
*/
dvar_t *_Dvar_RegisterVec4(const char *dvarName, float x, float y, float z, float w, float min, float max, unsigned int flags, const char* description)
{
	DvarLimits dvarDomain;
	DvarValue dvarValue;

	dvarDomain.value.max = max;
	dvarDomain.value.min = min;
	dvarValue.vector.v[0] = x;
	dvarValue.vector.v[1] = y;
	dvarValue.vector.v[2] = z;
	dvarValue.vector.v[3] = w;
	return Dvar_RegisterVariant(dvarName, DVAR_TYPE_FLOAT_4, flags, dvarValue, dvarDomain, description);
}

/*
==============
_Dvar_RegisterString
==============
*/
dvar_t *_Dvar_RegisterString(const char *dvarName, const char *value, unsigned int flags, const char* description)
{
	DvarLimits dvarDomain;
	DvarValue dvarValue;

	assert(dvarName);
	assert(value);
	assertMsg(((flags & DVAR_EXTERNAL) || CanKeepStringPointer(value)), "(dvarName) = %s", dvarName);

	dvarDomain.enumeration.stringCount = 0;
	dvarDomain.enumeration.strings = NULL;
	dvarValue.string = value;
	return Dvar_RegisterVariant(dvarName, DVAR_TYPE_STRING, flags, dvarValue, dvarDomain, description);
}

/*
==============
_Dvar_RegisterEnum
==============
*/
dvar_t *_Dvar_RegisterEnum(const char *dvarName, const char **valueList, int defaultIndex, unsigned int flags, const char* description)
{
	DvarLimits dvarDomain;
	DvarValue dvarValue;

	assert(dvarName);
	assert(valueList);
	dvarDomain.enumeration.strings = valueList;
	dvarDomain.enumeration.stringCount = 0;
	while (valueList[dvarDomain.enumeration.stringCount] != NULL)
	{
		dvarDomain.enumeration.stringCount++;
	}

	assertMsg((defaultIndex >= 0 && defaultIndex < dvarDomain.enumeration.stringCount || defaultIndex == 0),
		"(dvarName) = %s", dvarName);

	dvarValue.integer = defaultIndex;
	return Dvar_RegisterVariant(dvarName, DVAR_TYPE_ENUM, flags, dvarValue, dvarDomain, description);
}

/*
==============
_Dvar_RegisterColor
==============
*/
dvar_t *_Dvar_RegisterColor(const char *dvarName, float r, float g, float b, float a, unsigned int flags, const char *description)
{
	DvarLimits dvarDomain;
	DvarValue dvarValue;

	dvarDomain.integer.max = 0;
	dvarDomain.integer.min = 0;
	dvarValue.color[0] = (int)((float)((float)(255.0 * I_fclamp(r, 0.0f, 1.0f)) + 0.001) + 9.313225746154785e-10);
	dvarValue.color[1] = (int)((float)((float)(255.0 * I_fclamp(g, 0.0f, 1.0f)) + 0.001) + 9.313225746154785e-10);
	dvarValue.color[2] = (int)((float)((float)(255.0 * I_fclamp(b, 0.0f, 1.0f)) + 0.001) + 9.313225746154785e-10);
	dvarValue.color[3] = (int)((float)((float)(255.0 * I_fclamp(a, 0.0f, 1.0f)) + 0.001) + 9.313225746154785e-10);
	return Dvar_RegisterVariant(dvarName, DVAR_TYPE_COLOR, flags, dvarValue, dvarDomain, description);
}

/*
==============
_Dvar_RegisterLinearRGB
==============
*/
dvar_t *_Dvar_RegisterLinearRGB(const char *dvarName, float r, float g, float b, float min, float max, unsigned int flags, const char* description)
{
	DvarLimits dvarDomain;
	DvarValue dvarValue;

	dvarDomain.value.max = max;
	dvarDomain.value.min = min;
	dvarValue.vector.v[0] = r;
	dvarValue.vector.v[1] = g;
	dvarValue.vector.v[2] = b;
	return Dvar_RegisterVariant(dvarName, DVAR_TYPE_LINEAR_COLOR_RGB, flags, dvarValue, dvarDomain, description);
}

/*
==============
_Dvar_RegisterColorXYZ
==============
*/
dvar_t *_Dvar_RegisterColorXYZ(const char *dvarName, float x, float y, float z, float min, float max, unsigned int flags, const char* description)
{
	DvarLimits dvarDomain;
	DvarValue dvarValue;

	dvarDomain.value.max = max;
	dvarDomain.value.min = min;
	dvarValue.vector.v[0] = x;
	dvarValue.vector.v[1] = y;
	dvarValue.vector.v[2] = z;
	return Dvar_RegisterVariant(dvarName, DVAR_TYPE_COLOR_XYZ, flags, dvarValue, dvarDomain, description);
}

/*
==============
Dvar_SetBoolFromSource
==============
*/
void Dvar_SetBoolFromSource(dvar_t *dvar, bool value, DvarSetSource source)
{
	DvarValue newValue;

	assert(dvar);
	assert(dvar->name);
	assertMsg((dvar->type == DVAR_TYPE_BOOL || (dvar->type == DVAR_TYPE_STRING && (dvar->flags & DVAR_EXTERNAL))),
		"(dvar->name) = %s", dvar->name);

	if (dvar && dvar->name)
	{
		if (dvar->type)
		{
			newValue.string = value ? "1" : "0";
		}
		else
		{
			newValue.enabled = value;
		}

		Dvar_SetVariant(dvar, newValue, source);
	}
}

/*
==============
Dvar_SetIntFromSource
==============
*/
void Dvar_SetIntFromSource(dvar_t *dvar, int value, DvarSetSource source)
{
	char string[32];
	DvarValue newValue;

	assert(dvar);
	assert(dvar->name);

	assertMsg((dvar->type == DVAR_TYPE_INT || dvar->type == DVAR_TYPE_ENUM || (dvar->type == DVAR_TYPE_STRING
		&& (dvar->flags & DVAR_EXTERNAL))), "(dvar->name) = %s", dvar->name);

	if (dvar && dvar->name)
	{
		if (dvar->type == DVAR_TYPE_INT || dvar->type == DVAR_TYPE_ENUM)
		{
			newValue.integer = value;
		}
		else
		{
			Com_sprintf(string, sizeof(string), "%i", value);
			newValue.string = string;
		}

		Dvar_SetVariant(dvar, newValue, source);
	}
}

/*
==============
Dvar_SetInt64FromSource
==============
*/
void Dvar_SetInt64FromSource(dvar_t *dvar, __int64 value, DvarSetSource source)
{
	char string[32];
	DvarValue newValue;

	assert(dvar);
	assert(dvar->name);
	assertMsg((dvar->type == DVAR_TYPE_INT64 || (dvar->type == DVAR_TYPE_STRING && (dvar->flags & DVAR_EXTERNAL))),
		"(dvar->name) = %s", dvar->name);

	if (dvar && dvar->name)
	{
		if (dvar->type == 9)
		{
			newValue.integer64 = value;
		}
		else
		{
			Com_sprintf(string, sizeof(string), "%lli", value);
			newValue.string = string;
		}

		Dvar_SetVariant(dvar, newValue, source);
	}
}

/*
==============
Dvar_SetFloatFromSource
==============
*/
void Dvar_SetFloatFromSource(dvar_t *dvar, float value, DvarSetSource source)
{
	char string[32];
	DvarValue newValue;

	assert(dvar);
	assert(dvar->name);
	assertMsg((dvar->type == DVAR_TYPE_FLOAT || (dvar->type == DVAR_TYPE_STRING && (dvar->flags & DVAR_EXTERNAL))),
		"(dvar->name) = %s", dvar->name);

	if (dvar && dvar->name)
	{
		if (dvar->type == DVAR_TYPE_FLOAT)
		{
			newValue.value = value;
		}
		else
		{
			Com_sprintf(string, sizeof(string), "%g", value);
			newValue.string = string;
		}

		Dvar_SetVariant(dvar, newValue, source);
	}
}

/*
==============
Dvar_SetVec2FromSource
==============
*/
void Dvar_SetVec2FromSource(dvar_t *dvar, float x, float y, DvarSetSource source)
{
	char string[64];
	DvarValue newValue;

	assert(dvar);
	assert(dvar->name);
	assertMsg((dvar->type == DVAR_TYPE_FLOAT_2 || (dvar->type == DVAR_TYPE_STRING && (dvar->flags & DVAR_EXTERNAL))),
		"(dvar->name) = %s", dvar->name);
	if (dvar && dvar->name)
	{
		if (dvar->type == DVAR_TYPE_FLOAT_2)
		{
			newValue.vector.v[0] = x;
			newValue.vector.v[1] = y;
		}
		else
		{
			Com_sprintf(string, sizeof(string), "%g %g", x, y);
			newValue.string = string;
		}

		Dvar_SetVariant(dvar, newValue, source);
	}
}

/*
==============
Dvar_SetVec3FromSource
==============
*/
void Dvar_SetVec3FromSource(dvar_t *dvar, float x, float y, float z, DvarSetSource source)
{
	char string[96];
	DvarValue newValue;

	assert(dvar);
	assert(dvar->name);
	assertMsg((dvar->type == DVAR_TYPE_FLOAT_3 || dvar->type == DVAR_TYPE_COLOR_XYZ
		|| dvar->type == DVAR_TYPE_LINEAR_COLOR_RGB || (dvar->type == DVAR_TYPE_STRING && (dvar->flags & DVAR_EXTERNAL))),
		"(dvar->name) = %s", dvar->name);
	if (dvar && dvar->name)
	{
		if (dvar->type != 3 && dvar->type != 10 && dvar->type != 11)
		{
			Com_sprintf(string, 96, "%g %g %g", x, y, z);
			newValue.string = string;
		}
		else
		{
			newValue.vector.v[0] = x;
			newValue.vector.v[1] = y;
			newValue.vector.v[2] = z;
		}

		Dvar_SetVariant(dvar, newValue, source);
	}
}

/*
==============
Dvar_SetVec4FromSource
==============
*/
void Dvar_SetVec4FromSource(dvar_t *dvar, float x, float y, float z, float w, DvarSetSource source)
{
	char string[128];
	DvarValue newValue;

	assert(dvar);
	assert(dvar->name);
	assertMsg((dvar->type == DVAR_TYPE_FLOAT_4 || (dvar->type == DVAR_TYPE_STRING && (dvar->flags & DVAR_EXTERNAL))),
		"(dvar->name) = %s", dvar->name);

	if (dvar && dvar->name)
	{
		if (dvar->type == DVAR_TYPE_FLOAT_4)
		{
			newValue.vector.v[0] = x;
			newValue.vector.v[1] = y;
			newValue.vector.v[2] = z;
			newValue.vector.v[3] = w;
		}
		else
		{
			Com_sprintf(string, sizeof(string), "%g %g %g %g", x, y, z, w);
			newValue.string = string;
		}

		Dvar_SetVariant(dvar, newValue, source);
	}
}

/*
==============
Dvar_SetStringFromSource
==============
*/
void Dvar_SetStringFromSource(dvar_t *dvar, const char *string, DvarSetSource source)
{
	char stringCopy[1024];
	DvarValue newValue;

	assert(dvar);
	assert(dvar->name);
	assertMsg((dvar->type == DVAR_TYPE_STRING || dvar->type == DVAR_TYPE_ENUM), "(dvar->name) = %s", dvar->name);
	assert(string);
	if (dvar && dvar->name)
	{
		if (dvar->type == DVAR_TYPE_STRING)
		{
			I_strncpyz(stringCopy, string, sizeof(stringCopy));
			newValue.string = stringCopy;
		}
		else
		{
			newValue.integer = Dvar_StringToEnum(&dvar->domain, string);
			assertMsg(newValue.integer != DVAR_INVALID_ENUM_INDEX, va("%s doesn't include %s", dvar->name, string));
		}

		Dvar_SetVariant(dvar, newValue, source);
	}
}

/*
==============
Dvar_SetColorFromSource
==============
*/
void Dvar_SetColorFromSource(dvar_t *dvar, float r, float g, float b, float a, DvarSetSource source)
{
	char string[128];
	DvarValue newValue;

	assert(dvar);
	assert(dvar->name);
	assertMsg((dvar->type == DVAR_TYPE_COLOR || (dvar->type == DVAR_TYPE_STRING && (dvar->flags & DVAR_EXTERNAL))),
		"(dvar->name) = %s", dvar->name);

	if (dvar && dvar->name)
	{
		if (dvar->type == 8)
		{
			newValue.color[0] = (int)((float)(255.0 * I_fclamp(r, 0.0f, 1.0f)) + 9.313225746154785e-10);
			newValue.color[1] = (int)((float)(255.0 * I_fclamp(g, 0.0f, 1.0f)) + 9.313225746154785e-10);
			newValue.color[2] = (int)((float)(255.0 * I_fclamp(b, 0.0f, 1.0f)) + 9.313225746154785e-10);
			newValue.color[3] = (int)((float)(255.0 * I_fclamp(a, 0.0f, 1.0f)) + 9.313225746154785e-10);
		}
		else
		{
			Com_sprintf(string, sizeof(string), "%g %g %g %g", r, g, b, a);
			newValue.string = string;
		}

		Dvar_SetVariant(dvar, newValue, source);
	}
}

/*
==============
Dvar_SetBool
==============
*/
void Dvar_SetBool(dvar_t *dvar, bool value)
{
	Dvar_SetBoolFromSource(dvar, value, DVAR_SOURCE_INTERNAL);
}

/*
==============
Dvar_SetInt
==============
*/
void Dvar_SetInt(dvar_t *dvar, int value)
{
	Dvar_SetIntFromSource(dvar, value, DVAR_SOURCE_INTERNAL);
}

/*
==============
Dvar_SetFloat
==============
*/
void Dvar_SetFloat(dvar_t *dvar, float value)
{
	Dvar_SetFloatFromSource(dvar, value, DVAR_SOURCE_INTERNAL);
}

/*
==============
Dvar_SetVec2
==============
*/
void Dvar_SetVec2(dvar_t *dvar, float x, float y)
{
	Dvar_SetVec2FromSource(dvar, x, y, DVAR_SOURCE_INTERNAL);
}

/*
==============
Dvar_SetVec3
==============
*/
void Dvar_SetVec3(dvar_t *dvar, float x, float y, float z)
{
	Dvar_SetVec3FromSource(dvar, x, y, z, DVAR_SOURCE_INTERNAL);
}

/*
==============
Dvar_SetVec4
==============
*/
void Dvar_SetVec4(dvar_t *dvar, float x, float y, float z, float w)
{
	Dvar_SetVec4FromSource(dvar, x, y, z, w, DVAR_SOURCE_INTERNAL);
}

/*
==============
Dvar_SetVec4FromVec4
==============
*/
void Dvar_SetVec4FromVec4(dvar_t *dvar, vec4_t *vecin)
{
	Dvar_SetVec4FromSource(dvar, vecin->x, vecin->y, vecin->z, vecin->w, DVAR_SOURCE_INTERNAL);
}

/*
==============
Dvar_SetString
==============
*/
void Dvar_SetString(dvar_t *dvar, const char *value)
{
	Dvar_SetStringFromSource(dvar, value, DVAR_SOURCE_INTERNAL);
}

/*
==============
Dvar_SetOrRegisterString
==============
*/
dvar_t *Dvar_SetOrRegisterString(dvar_t *dvar, const char *dvarName, const char *value)
{
	if (!dvar)
		return _Dvar_RegisterString(dvarName, value, DVAR_EXTERNAL, "External Dvar");
	Dvar_SetStringFromSource(dvar, value, DVAR_SOURCE_INTERNAL);
	return dvar;
}

/*
==============
Dvar_SetColor
==============
*/
void Dvar_SetColor(dvar_t *dvar, float r, float g, float b, float a)
{
	Dvar_SetColorFromSource(dvar, r, g, b, a, DVAR_SOURCE_INTERNAL);
}

/*
==============
Dvar_SetFromStringFromSource
==============
*/
void Dvar_SetFromStringFromSource(dvar_t *dvar, const char *string, DvarSetSource source)
{
	char buf[1024];
	DvarValue newValue;

	if (dvar && dvar->name)
	{
		I_strncpyz(buf, string, sizeof(buf));
		newValue = Dvar_StringToValue(dvar->type, dvar->domain, buf);
		if (dvar->type == DVAR_TYPE_ENUM && newValue.integer == DVAR_INVALID_ENUM_INDEX)
		{
			Com_Printf(CON_CHANNEL_SYSTEM, "'%s' is not a valid value for dvar '%s'\n", buf, dvar->name);
			Dvar_PrintDomain(dvar->type, dvar->domain);
			newValue = dvar->reset;
		}

		Dvar_SetVariant(dvar, newValue, source);
	}
}

/*
==============
Dvar_SetFromString
==============
*/
void Dvar_SetFromString(dvar_t *dvar, const char *string)
{
	Dvar_SetFromStringFromSource(dvar, string, DVAR_SOURCE_INTERNAL);
}

/*
==============
Dvar_SetFromStringByNameFromSource
==============
*/
dvar_t *Dvar_SetFromStringByNameFromSource(const char *dvarName, const char *string, DvarSetSource source, unsigned int flags)
{
	dvar_t* dvar;

	dvar = Dvar_FindVar(dvarName);
	if (!dvar)
	{
		return _Dvar_RegisterString(dvarName, string, flags | DVAR_EXTERNAL, "External Dvar");
	}

	Dvar_SetFromStringFromSource(dvar, string, source);

	return dvar;
}

/*
==============
Dvar_SetFromStringByName
==============
*/
void Dvar_SetFromStringByName(const char *dvarName, const char *string)
{
	Dvar_SetFromStringByNameFromSource(dvarName, string, DVAR_SOURCE_INTERNAL, 0);
}

/*
==============
Dvar_SetCommand
==============
*/
void Dvar_SetCommand(const char *dvarName, const char *string)
{
	dvar_t* dvar;

	dvar = Dvar_SetFromStringByNameFromSource(dvarName, string, DVAR_SOURCE_EXTERNAL, 0);
	if (dvar && s_isLoadingAutoExecGlobalFlag)
	{
		Dvar_AddFlags(dvar, DVAR_AUTOEXEC);
		Dvar_UpdateResetValue(dvar, dvar->current);
	}
}

/*
==============
Dvar_Reset
==============
*/
void Dvar_Reset(dvar_t *dvar, DvarSetSource setSource)
{
	assert(dvar);
	Dvar_SetVariant(dvar, dvar->reset, setSource);
}

/*
==============
Dvar_SetCheatState
==============
*/
void Dvar_SetCheatState()
{
	int dvarIter;
	dvar_t* dvar;

	InterlockedIncrement(&g_dvarCritSect.readCount);
	while (g_dvarCritSect.writeCount)
	{
		NET_Sleep(0);
	}

	for (dvarIter = 0; dvarIter < g_dvarCount; ++dvarIter)
	{
		dvar = &s_dvarPool[dvarIter];
		if (dvar->flags & DVAR_CHEAT)
		{
			Dvar_SetVariant(dvar, dvar->reset, DVAR_SOURCE_INTERNAL);
		}
	}
	Sys_UnlockRead(&g_dvarCritSect);
}

/*
==============
Dvar_Init
==============
*/
void Dvar_Init()
{
	s_nextFreeCallback = 0;
	s_isDvarSystemActive = 1;

	r_cmdbuf_worker = _Dvar_RegisterBool("r_cmdbuf_worker", FALSE, 0x84000u, "Process command buffer in a separate thread");
	r_fxaa = _Dvar_RegisterBool("r_fxaa", TRUE, 0x84000u, "fxaa");
	ragdoll_enable = _Dvar_RegisterBool("ragdoll_enable", TRUE, 0x84000u, "Turn on ragdoll death animations");
	snd_losOcclusion = _Dvar_RegisterBool("snd_losOcclusion", TRUE, 0x84000u, "occlusion based off of LOS");
	sm_enable = _Dvar_RegisterBool("sm_enable", TRUE, 0x84000u, "Enable shadow mapping");
	cg_fov_default = _Dvar_RegisterFloat("cg_fov_default", 65.0, 65.0, 90.0, 0x84000u, "User default field of view angle in degrees");
	cg_fov_default_thirdperson = _Dvar_RegisterFloat("cg_fov_default_thirdperson", 40.0, 1.0, 160.0, 0x84000u, "User default 3rd person field of view angle in degrees");
	sm_polygonOffsetScale = _Dvar_RegisterFloat("sm_polygonOffsetScale", 2.0, 0.0, 8.0, 0x84000u, "Shadow map offset scale");
	cg_ScoresPing_Interval = _Dvar_RegisterInt("cg_ScoresPing_Interval", 100, 1, 500, 0x84000u, "Number of milliseconds each bar represents");
	cg_chatHeight = _Dvar_RegisterInt("cg_chatHeight", 8, 0, 8, 0x84000u, "The font height of a chat message");
	g_inactivity = _Dvar_RegisterInt("g_inactivity", 0, 0, INT_MAX, 0x84000u, "Time delay before player is kicked for inactivity");
	dvar_cheats = _Dvar_RegisterBool("sv_cheats", 1, 0x18u, "External Dvar");
	allClientDvarsEnabled = _Dvar_RegisterBool("allClientDvarsEnabled", TRUE /*For testing purposes leave on*/, 0x20000u, "Allow host to set all client dvars");

	Dvar_AddCommands();
}

/*
==============
Dvar_LoadDvarsAddFlags
==============
*/
void __cdecl Dvar_LoadDvarsAddFlags(MemoryFile *memFile, unsigned __int16 flags)
{
	UNIMPLEMENTED(__FUNCTION__);
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
void __cdecl Dvar_SetStringIfChanged(const dvar_t *dvar, const char *newString)
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

