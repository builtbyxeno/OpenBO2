#include "dvar.h"

#include <universal/q_shared.h>
#include <universal/com_memory.h>
#include <universal/com_math.h>

typedef struct dvarCallBack_t
{
	bool needsCallback;
	void(__cdecl* callback)(const dvar_t*);
	const dvar_t* dvar;
} dvarCallBack_t;

static bool s_isLoadingAutoExecGlobalFlag, s_isDvarSystemActive, s_nextFreeCallback;

static dvarCallBack_t s_dvarCallbackPool[64];

static FastCriticalSection g_dvarCritSect;

static dvar_t* s_dvarHashTable[1080];

void TRACK_dvar(void)
{
}

void Dvar_SetInAutoExec(bool inAutoExec)
{
	s_isLoadingAutoExecGlobalFlag = inAutoExec;
}

bool Dvar_IsSystemActive(void)
{
	return s_isDvarSystemActive;
}

bool Dvar_IsValidName(char const* dvarName)
{
	if (!dvarName)
		return false;
	if (!*dvarName)
		return 1;
	while (1)
	{
		char currChar = *dvarName;
		if (!isalnum(*dvarName) && currChar != 95)
			break;
		if (!*++dvarName)
			return 1;
	}
	return 0;
}

void Dvar_CopyString(char const* string, DvarValue* value)
{
	value->integer = (int)CopyString(string);
}

void Dvar_WeakCopyString(char const* string, DvarValue* value)
{
	value->integer = (int)string;
}

bool Dvar_ShouldFreeCurrentString(dvar_t* dvar)
{
	int currInt = dvar->current.integer;
	return currInt && currInt != dvar->latched.integer && currInt != dvar->reset.integer;
}

bool Dvar_ShouldFreeLatchedString(dvar_t* dvar)
{
	int latchedInt = dvar->latched.integer;
	return latchedInt && latchedInt != dvar->current.integer && latchedInt != dvar->reset.integer;
}

bool Dvar_ShouldFreeResetString(dvar_t* dvar)
{
	int resetInt = dvar->reset.integer;
	return resetInt && resetInt != dvar->current.integer && resetInt != dvar->latched.integer;
}

void Dvar_FreeString(DvarValue* value)
{
	FreeString(value->string);
	value->integer = 0;
}

void Dvar_AssignCurrentStringValue(dvar_t* dvar, DvarValue* dest, char const* string)
{
	const char* latchedStr;
	const char* resetStr;

	latchedStr = dvar->latched.string;
	if (latchedStr && (string == latchedStr || !strcmp(string, dvar->latched.string)))
	{
		dest->integer = (int)latchedStr;
	}
	else
	{
		resetStr = dvar->reset.string;
		if (resetStr && (string == resetStr || !strcmp(string, dvar->reset.string)))
		{
			dest->integer = (int)resetStr;
		}
		else
		{
			dest->integer = (int)CopyString(string);
		}
	}
}

void Dvar_AssignLatchedStringValue(dvar_t* dvar, DvarValue* dest, char const* string)
{
	const char* currStr;
	const char* resetStr;

	currStr = dvar->current.string;
	if (currStr && (string == currStr || !strcmp(string, dvar->current.string)))
	{
		dest->integer = (int)currStr;
	}
	else
	{
		resetStr = dvar->reset.string;
		if (resetStr && (string == resetStr || !strcmp(string, dvar->reset.string)))
		{
			dest->integer = (int)resetStr;
		}
		else
		{
			dest->integer = (int)CopyString(string);
		}
	}
}

void Dvar_AssignResetStringValue(dvar_t* dvar, DvarValue* dest, char const* string)
{
	const char* currStr;
	const char* latchedStr;

	currStr = dvar->current.string;
	if (currStr && (string == currStr || !strcmp(string, dvar->current.string)))
	{
		dest->integer = (int)currStr;
	}
	else
	{
		latchedStr = dvar->latched.string;
		if (latchedStr && (string == latchedStr || !strcmp(string, dvar->latched.string)))
		{
			dest->integer = (int)latchedStr;
		}
		else
		{
			dest->integer = (int)CopyString(string);
		}
	}
}

char const* Dvar_EnumToString(dvar_t const* dvar)
{
	if (dvar->domain.integer.min)
	{
		return dvar->domain.enumeration.strings[dvar->current.integer];
	}
	else
	{
		return "";
	}
}

char const* Dvar_IndexStringToEnumString(dvar_t const* dvar, char const* indexString)
{
	int enumIndex, indexStringIndex;

	if (!dvar->domain.integer.min)
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
	else
	{
		return "";
	}
}

char const* Dvar_ValueToString(dvar_t const* dvar, DvarValue value)
{
	switch (dvar->type)
	{
	case DVAR_TYPE_BOOL:
		return value.enabled ? "1" : "0";
	case DVAR_TYPE_FLOAT:
		return va("%g", value.value);
	case DVAR_TYPE_FLOAT_2:
		return va("%g %g", value.value, value.vector.v[1]);
	case DVAR_TYPE_FLOAT_3:
	case DVAR_TYPE_LINEAR_COLOR_RGB:
	case DVAR_TYPE_COLOR_XYZ:
		return va("%g %g %g", value.value, value.vector.v[1], value.vector.v[2]);
	case DVAR_TYPE_FLOAT_4:
		return va("%g %g %g %g", value.value, value.vector.v[1], value.vector.v[2], value.vector.v[3]);
	case DVAR_TYPE_INT:
		return va("%i", value.integer);
	case DVAR_TYPE_ENUM:
		if (dvar->domain.enumeration.stringCount)
		{
			return dvar->domain.enumeration.strings[value.integer];
		}
		else
		{
			return "";
		}
	case DVAR_TYPE_STRING:
		return va("%s", value.string);
	case DVAR_TYPE_COLOR:
		return va(
			"%g %g %g %g",
			(float)((float)value.color[0] * 0.0039215689),
			(float)((float)value.color[1] * 0.0039215689),
			(float)((float)value.color[2] * 0.0039215689),
			(float)((float)value.color[3] * 0.0039215689));
	case DVAR_TYPE_INT64:
		return va("%lli", value.integer64);
	default:
	}
}

bool Dvar_StringToBool(char const* string)
{
	return atoi(string) != 0;
}

int Dvar_StringToInt(char const* string)
{
	return atoi(string);
}

__int64 Dvar_StringToInt64(char const* string)
{
	return I_atoi64(string);
}

float Dvar_StringToFloat(char const* string)
{
	return atof(string);
}

void Dvar_StringToVec2(char const* string, vec2_t* vector)
{
	vector->x = 0.0f;
	vector->y = 0.0f;
	sscanf(string, "%g %g", vector->x, vector->y);
}

void Dvar_StringToVec3(char const* string, vec3_t* vector)
{
	vector->x = 0.0f;
	vector->y = 0.0f;
	vector->z = 0.0f;
	if (*string == '(')
	{
		sscanf(string, "( %g, %g, %g )", vector->x, vector->y, vector->z);
	}
	else
	{
		sscanf(string, "%g %g %g", vector->x, vector->y, vector->z);
	}
}

void Dvar_StringToVec4(char const* string, vec4_t* vector)
{
	vector->x = 0.0f;
	vector->y = 0.0f;
	vector->z = 0.0f;
	vector->w = 0.0f;
	sscanf(string, "%g %g %g %g", vector->x, vector->y, vector->z, vector->w);
}

int Dvar_StringToEnum(DvarLimits const* domain, char const* string)
{
	int stringIndex;
	const char* digit;

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
		if (*digit < 48 || *digit > 57)
		{
			return -1337;
		}
		stringIndex = 10 * stringIndex + *digit - 48;
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

	return -1337;
}

void Dvar_StringToColor(char const* string, unsigned char* color)
{
	vec4_t colorVec;

	colorVec.r = 0.0f;
	colorVec.g = 0.0f;
	colorVec.b = 0.0f;
	colorVec.a = 0.0f;
	sscanf(string, "%g %g %g %g", colorVec.r, colorVec.g, colorVec.b, colorVec.a);

	color[0] = (int)((float)(255.0 * I_fclamp(colorVec.r, 0.0f, 1.0f)) + 9.313225746154785e-10);
	color[1] = (int)((float)(255.0 * I_fclamp(colorVec.g, 0.0f, 1.0f)) + 9.313225746154785e-10);
	color[2] = (int)((float)(255.0 * I_fclamp(colorVec.b, 0.0f, 1.0f)) + 9.313225746154785e-10);
	color[3] = (int)((float)(255.0 * I_fclamp(colorVec.a, 0.0f, 1.0f)) + 9.313225746154785e-10);
}

DvarValue Dvar_StringToValue(dvarType_t type, DvarLimits domain, char const* string)
{
	DvarValue value;

	switch (type)
	{
	case DVAR_TYPE_BOOL:
		value.enabled = Dvar_StringToBool(string);
		break;
	case DVAR_TYPE_FLOAT:
		value.value = Dvar_StringToFloat(string);
		break;
	case DVAR_TYPE_FLOAT_2:
		Dvar_StringToVec2(string, (vec2_t*)&value.value);
		break;
	case DVAR_TYPE_FLOAT_3:
	case DVAR_TYPE_LINEAR_COLOR_RGB:
	case DVAR_TYPE_COLOR_XYZ:
		Dvar_StringToVec3(string, (vec3_t*)&value.value);
		break;
	case DVAR_TYPE_FLOAT_4:
		Dvar_StringToVec4(string, (vec4_t*)&value.value);
		break;
	case DVAR_TYPE_INT:
		value.value = Dvar_StringToInt(string);
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
	}

	return value;
}

char const* Dvar_DisplayableValue(dvar_t const* dvar)
{
	return Dvar_ValueToString(dvar, dvar->current);
}

char const* Dvar_DisplayableResetValue(dvar_t const* dvar)
{
	return Dvar_ValueToString(dvar, dvar->reset);
}

char const* Dvar_DisplayableLatchedValue(dvar_t const* dvar)
{
	return Dvar_ValueToString(dvar, dvar->latched);
}

DvarValue Dvar_ClampValueToDomain(dvarType_t type, DvarValue value, DvarValue resetValue, DvarLimits domain)
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
		if (domain.value.min <= value.value)
		{
			if (value.value > domain.value.max)
			{
				value.integer = domain.integer.max;
			}
		}
		else
		{
			value.integer = domain.enumeration.stringCount;
		}
		if (domain.value.min <= value.vector.v[1])
		{
			if (value.vector.v[1] > domain.value.max)
				value.vector.v[1] = domain.integer.max;
		}
		else
			value.vector.v[1] = domain.enumeration.stringCount;
		break;
	case DVAR_TYPE_FLOAT_3:
	case DVAR_TYPE_LINEAR_COLOR_RGB:
	case DVAR_TYPE_COLOR_XYZ:
		if (domain.value.min <= value.value)
		{
			if (value.value > domain.value.max)
				value.integer = domain.integer.max;
		}
		else
		{
			value.integer = domain.enumeration.stringCount;
		}
		if (domain.value.min <= value.vector.v[1])
		{
			if (value.vector.v[1] > domain.value.max)
				value.vector.v[1] = domain.integer.max;
		}
		else
		{
			value.vector.v[1] = domain.enumeration.stringCount;
		}
		if (domain.value.min <= value.vector.v[2])
		{
			if (value.vector.v[2] > domain.value.max)
				value.vector.v[2] = domain.integer.max;
		}
		else
		{
			value.vector.v[2] = domain.enumeration.stringCount;
		}
		break;
	case DVAR_TYPE_FLOAT_4:
		if (domain.value.min <= value.value)
		{
			if (value.value > domain.value.max)
				value.integer = domain.integer.max;
		}
		else
		{
			value.integer = domain.enumeration.stringCount;
		}
		if (domain.value.min <= value.vector.v[1])
		{
			if (value.vector.v[1] > domain.value.max)
				value.vector.v[1] = domain.integer.max;
		}
		else
		{
			value.vector.v[1] = domain.enumeration.stringCount;
		}
		if (domain.value.min <= value.vector.v[2])
		{
			if (value.vector.v[2] > domain.value.max)
				value.vector.v[2] = domain.integer.max;
		}
		else
		{
			value.vector.v[2] = domain.enumeration.stringCount;
		}
		if (domain.value.min <= value.vector.v[3])
		{
			if (value.vector.v[3] > domain.value.max)
				value.vector.v[3] = domain.integer.max;
		}
		else
		{
			value.vector.v[3] = domain.enumeration.stringCount;
		}
		break;
	case DVAR_TYPE_INT:
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
		}
		break;
	case DVAR_TYPE_STRING:
		if (value.integer < 0 || value.integer >= domain.enumeration.stringCount)
		{
			value.integer = resetValue.integer;
		}
		break;
	case DVAR_TYPE_COLOR:
		break;
	case DVAR_TYPE_INT64:
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
	}
	return value;
}

bool Dvar_ValueInDomain(dvarType_t type, DvarValue value, DvarLimits domain)
{
	switch (type)
	{
	case DVAR_TYPE_BOOL:
		return 1;
	case DVAR_TYPE_FLOAT:
		return domain.value.min <= value.value && value.value <= domain.value.max;
	case DVAR_TYPE_FLOAT_2:
		for (int i = 0; i <= 2; ++i) {
			if (domain.value.min > *(&value.value + i) || *(&value.value + i) > domain.value.max)
				break;
			return 1;
		}
	case DVAR_TYPE_FLOAT_3:
	case DVAR_TYPE_LINEAR_COLOR_RGB:
	case DVAR_TYPE_COLOR_XYZ:
		for (int i = 0; i <= 3; ++i) {
			if (domain.value.min > *(&value.value + i) || *(&value.value + i) > domain.value.max)
				break;
			return 1;
		}
	case DVAR_TYPE_FLOAT_4:
		for (int i = 0; i <= 4; ++i) {
			if (domain.value.min > *(&value.value + i) || *(&value.value + i) > domain.value.max)
				break;
			return 1;
		}
	case DVAR_TYPE_INT:
		if (value.integer >= domain.integer.min)
		{
			return value.integer <= domain.integer.max;
		}
		return 0;
	case DVAR_TYPE_ENUM:
		return value.integer >= 0 && value.integer < domain.enumeration.stringCount || !value.integer;
	case DVAR_TYPE_STRING:
	case DVAR_TYPE_COLOR:
		return 1;
	case DVAR_TYPE_INT64:
		if (value.integer64 >= domain.integer64.min)
		{
			return value.integer64 <= domain.integer64.max;
		}
		return 0;
	}
}

void Dvar_VectorDomainToString(int components, DvarLimits domain, char* outBuffer, int outBufferLen)
{
	if (domain.vector.min == -FLT_MAX)
	{
		if (domain.vector.max == FLT_MAX)
		{
			_snprintf(outBuffer, outBufferLen, "Domain is any %iD vector", components);
		}
		else
		{
			_snprintf(
				outBuffer,
				outBufferLen,
				"Domain is any %iD vector with components %g or smaller",
				components,
				domain.vector.max);
		}
	}
	else if (domain.vector.max == FLT_MAX)
	{
		_snprintf(
			outBuffer,
			outBufferLen,
			"Domain is any %iD vector with components %g or bigger",
			components,
			domain.vector.min);
	}
	else
	{
		_snprintf(
			outBuffer,
			outBufferLen,
			"Domain is any %iD vector with components from %g to %g",
			components,
			domain.vector.min,
			domain.vector.max);
	}
}

char const* Dvar_DomainToString_Internal(dvarType_t type, DvarLimits domain, char* outBuffer, int outBufferLen, int* outLineCount)
{
	char* outBufferEnd, char* outBufferWalk;
	int charsWritten, stringIndex;

	outBufferEnd = &outBuffer[outBufferLen];
	if (outLineCount)
	{
		*outLineCount = 0;
	}

	switch (type) {
	case DVAR_TYPE_BOOL:
		_snprintf(outBuffer, outBufferLen, "Domain is 0 or 1");
		break;
	case DVAR_TYPE_FLOAT:
		if (domain.value.min == -FLT_MAX)
		{
			if (domain.value.max == FLT_MAX)
				_snprintf(outBuffer, outBufferLen, "Domain is any number");
			else
				_snprintf(outBuffer, outBufferLen, "Domain is any number %g or smaller", domain.value.max);
		}
		else
		{
			if (domain.value.max == 3.4028235e38)
				_snprintf(outBuffer, outBufferLen, "Domain is any number %g or bigger", domain.value.min);
			else
				_snprintf(outBuffer, outBufferLen, "Domain is any number from %g to %g", domain.value.min, domain.value.max);
		}
		break;
	case DVAR_TYPE_FLOAT_2:
		Dvar_VectorDomainToString(2, domain, outBuffer, outBufferLen);
		break;
	case DVAR_TYPE_COLOR_XYZ:
		Dvar_VectorDomainToString(3, domain, outBuffer, outBufferLen);
		break;
	case DVAR_TYPE_FLOAT_4:
		Dvar_VectorDomainToString(4, domain, outBuffer, outBufferLen);
		break;
	case DVAR_TYPE_INT:
		if (domain.integer.min == INT_MIN)
		{
			if (domain.integer.max == INT_MAX)
				_snprintf(outBuffer, outBufferLen, "Domain is any integer");
			else
				_snprintf(outBuffer, outBufferLen, "Domain is any integer %i or smaller", domain.integer.max);
		}
		else if (domain.integer.max == INT_MAX)
			_snprintf(outBuffer, outBufferLen, "Domain is any integer %i or bigger", domain.integer.min);
		else
			_snprintf(outBuffer, outBufferLen, "Domain is any integer from %i to %i", domain.integer64.min);
		break;
	case DVAR_TYPE_ENUM:
		charsWritten = _snprintf(outBuffer, outBufferEnd - outBuffer, "Domain is one of the following:");
		if (charsWritten >= 0)
		{
			outBufferWalk = &outBuffer[charsWritten];
			for (stringIndex = 0; stringIndex < domain.enumeration.stringCount; ++stringIndex)
			{
				charsWritten = _snprintf(
					outBufferWalk,
					outBufferEnd - outBufferWalk,
					"\n  %2i: %s",
					stringIndex,
					domain.enumeration.strings[stringIndex]);
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
		if (!domain.integer.min && domain.integer.max == 0x80000000)
		{
			if (domain.integer64.max == INT64_MAX)
			{
				_snprintf(outBuffer, outBufferLen, "Domain is any integer");
			}
			else
			{
				_snprintf(outBuffer, outBufferLen, "Domain is any integer %lli or smaller", domain.integer64.max);
			}
		}
		else
		{
			if (domain.integer64.max == INT64_MAX)
				_snprintf(outBuffer, outBufferLen, "Domain is any integer %lli or bigger", domain.integer64.min);
			else
				_snprintf(
					outBuffer,
					outBufferLen,
					"Domain is any integer from %lli to %lli",
					domain.integer64.min,
					domain.integer64.max);
		}
		break;
	}

	*(outBufferEnd - 1) = 0;
	return outBuffer;
}

char const* Dvar_DomainToString_GetLines(dvarType_t type, DvarLimits domain, char* outBuffer, int outBufferLen, int* outLineCount)
{
	return Dvar_DomainToString_Internal(type, domain, outBuffer, outBufferLen, outLineCount);
}

void Dvar_PrintDomain(dvarType_t, DvarLimits)
{
	char domainBuffer[1024];
	//Com_Printf(10, "  %s\n", Dvar_DomainToString_Internal(type, domain, domainBuffer, 1024, 0));
}

bool Dvar_ValuesEqual(dvarType_t type, DvarValue val0, DvarValue val1)
{
	vec4_t b;
	vec4_t a;

	a = val0.vector;
	b = val1.vector;

	switch (type)
	{
	case DVAR_TYPE_BOOL:
		return val0.enabled == val1.enabled;
	case DVAR_TYPE_FLOAT:
		return val0.value == val1.value;
	case DVAR_TYPE_FLOAT_2:
		if (a.v[0] != b.v[0] || a.v[1] != b.v[1])
			return false;
		else
			return true;
	case DVAR_TYPE_FLOAT_3:
	case DVAR_TYPE_LINEAR_COLOR_RGB:
	case DVAR_TYPE_COLOR_XYZ:
		if (a.v[0] != b.v[0] || a.v[1] != b.v[1] || a.v[2] != b.v[2])
			return false;
		else
			return true;
	case DVAR_TYPE_FLOAT_4:
		return Vec4Compare(&a, &b);
	case DVAR_TYPE_INT:
		return val0.integer == val1.integer;
	case DVAR_TYPE_ENUM:
		return val0.integer == val1.integer;
	case DVAR_TYPE_STRING:
		return strcmp(val0.string, val1.string);
	case DVAR_TYPE_COLOR:
		return val0.integer == val1.integer;
	case DVAR_TYPE_INT64:
		return val0.integer64 == val1.integer64;
	}
}

void Dvar_SetLatchedValue(dvar_t* dvar, DvarValue value)
{
	switch (dvar->type)
	{
	case DVAR_TYPE_BOOL:
		dvar->latched.enabled = value.enabled;
		break;
	case DVAR_TYPE_FLOAT:
		dvar->latched.value = value.value;
		break;
	case DVAR_TYPE_FLOAT_2:
		dvar->latched.value = value.value;
		dvar->latched.vector.v[1] = value.vector.v[1];
		break;
	case DVAR_TYPE_FLOAT_3:
	case DVAR_TYPE_LINEAR_COLOR_RGB:
	case DVAR_TYPE_COLOR_XYZ:
		dvar->latched.value = value.value;
		dvar->latched.vector.v[1] = value.vector.v[1];
		dvar->latched.vector.v[2] = value.vector.v[2];
		break;
	case DVAR_TYPE_INT:
		dvar->latched.integer = value.integer;
		break;
	case DVAR_TYPE_ENUM:
		dvar->latched.integer = value.integer;
		break;
	case DVAR_TYPE_STRING:
		dvar->latched.string = value.string;
		break;
	case DVAR_TYPE_INT64:
		dvar->latched.integer64 = value.integer64;
		break;
	default:
		dvar->latched = value;
		break;
	}
}

bool Dvar_HasLatchedValue(dvar_t const* dvar)
{
	return Dvar_ValuesEqual(dvar->type, dvar->current, dvar->latched) == 0;
}

dvarCallBack_t* findCallBackForDvar(dvar_t const* dvar)
{
	dvarCallBack_t* result;

	int currCallback = 0;
	if (s_nextFreeCallback <= 0)
		return 0;
	for (result = s_dvarCallbackPool; result->dvar->hash != dvar->hash; ++result)
	{
		if (++currCallback >= s_nextFreeCallback)
			return 0;
	}
	return result;
}

dvar_t* Dvar_FindMalleableVar(int dvarHash)
{
	dvar_t* var;

	_InterlockedExchangeAdd(&g_dvarCritSect.readCount, 1u);
	while (g_dvarCritSect.writeCount)
	{
		//NET_Sleep(0);
	}

	for (var = s_dvarHashTable[dvarHash & 0x3FF]; var; var = var->hashNext)
	{
		if (var->hash == dvarHash)
		{
			Sys_UnlockRead(&g_dvarCritSect);
			return var;
		}
	}

	Sys_UnlockRead(&g_dvarCritSect);

	return 0;
}

dvar_t* Dvar_FindMalleableVar(char const* dvarName)
{
	int hash;

	hash = Com_HashString(dvarName, 0);
	return Dvar_FindMalleableVar(hash);
}

dvar_t* Dvar_FindVar(char const* dvarName)
{
	if (!*dvarName)
		return 0;
	return Dvar_FindMalleableVar(dvarName);
}

dvar_t* Dvar_FindVar(int dvarHash)
{
	return Dvar_FindMalleableVar(dvarHash);
}

void Dvar_ClearModified(dvar_t* dvar)
{
	dvar->modified = 0;
}

void Dvar_SetModified(dvar_t* dvar)
{
	dvar->modified = 1;
}

bool Dvar_GetModified(dvar_t const* dvar)
{
	if (!dvar)
		return 0;
	return dvar->modified;
}

int Dvar_GetInt(int dvarHash)
{
	dvar_t* dvar = Dvar_FindVar(dvarHash);
	if (!dvar)
		return 0;

	switch (dvar->type) {
	case DVAR_TYPE_INT:
	case DVAR_TYPE_BOOL:
		return dvar->current.enabled;
	case DVAR_TYPE_FLOAT:
		return (int)dvar->current.value;
	case DVAR_TYPE_ENUM:
		return dvar->current.integer;
	default:
		return Dvar_StringToInt(dvar->current.string);
	}
}

unsigned int Dvar_GetUnsignedInt(dvar_t const* dvar)
{
	if (!dvar)
		return 0;
	return dvar->current.integer;
}

float Dvar_GetFloat(int dvarHash)
{
	dvar_t* dvar = Dvar_FindMalleableVar(dvarHash);
	if (!dvar)
		return 0.0f;

	if (dvar->type == DVAR_TYPE_FLOAT)
		return dvar->current.value;
	if (dvar->type == DVAR_TYPE_INT)
		return (float)dvar->current.integer;
	return Dvar_StringToFloat(dvar->current.string);
}

void Dvar_GetVec2(dvar_t const* dvar, vec2_t* result)
{
	if (dvar)
		result = reinterpret_cast<vec2_t*>(dvar->current.integer64);
	else
		*result = vec2_origin;
}

void Dvar_GetVec3(dvar_t const* dvar, vec3_t* result)
{
	if (dvar)
	{
		result->x = dvar->current.value;
		result->y = dvar->current.vector.v[1];
		result->z = dvar->current.vector.v[2];
	}
	else
		result = &vec3_origin;
}

void Dvar_GetVec4(dvar_t const* dvar, vec4_t* result)
{
	if (dvar)
	{
		result->x = dvar->current.value;
		result->y = dvar->current.vector.v[1];
		result->z = dvar->current.vector.v[2];
		result->w = dvar->current.vector.v[3];
	}
	else
		result = &vec4_origin;
}

char const* Dvar_GetString(dvar_t const* dvar)
{
	if (!dvar)
		return "";

	if (dvar->type == DVAR_TYPE_ENUM)
		return Dvar_EnumToString(dvar);
	else
		return dvar->current.string;
}

char const* Dvar_GetVariantString(int dvarHash)
{
	dvar_t* dvar = Dvar_FindMalleableVar(dvarHash);
	if (!dvar)
		return "";
	return Dvar_ValueToString(dvar, dvar->current);
}

char const* Dvar_GetVariantString(dvar_t const* dvar)
{
	if (!dvar)
		return "";
	return Dvar_ValueToString(dvar, dvar->current);
}

void Dvar_GetUnpackedColor(dvar_t const* dvar, vec4_t* expandedColor)
{
	unsigned __int8 color[4];

	if (dvar->type == DVAR_TYPE_COLOR)
		*color = (unsigned __int8)dvar->current.integer;
	else
		Dvar_StringToColor(dvar->current.string, color);

	expandedColor->r = color[0] / 255.0;
	expandedColor->g = color[1] / 255.0;
	expandedColor->b = color[2] / 255.0;
	expandedColor->a = color[3] / 255.0;

}

void Dvar_GetColor(dvar_t const* dvar, unsigned char* color)
{
	// ????
	if (dvar->type == DVAR_TYPE_COLOR)
		*color = dvar->current.integer;
	else
		*color = dvar->current.integer;
}

float Dvar_GetColorRed(dvar_t const* dvar)
{
	vec4_t expandedColor;

	Dvar_GetUnpackedColor(dvar, &expandedColor);
	return expandedColor.r;
}

float Dvar_GetColorRed(int dvarHash)
{
	vec4_t expandedColor;
	dvar_t* dvar = Dvar_FindMalleableVar(dvarHash);
}

float Dvar_GetColorGreen(dvar_t const* dvar)
{
	vec4_t expandedColor;

	Dvar_GetUnpackedColor(dvar, &expandedColor);
	return expandedColor.g;
}

float Dvar_GetColorGreen(int dvarHash)
{
	vec4_t expandedColor;
	dvar_t* dvar = Dvar_FindMalleableVar(dvarHash);
	return Dvar_GetColorGreen(dvar);
}

float Dvar_GetColorBlue(dvar_t const* dvar)
{
	vec4_t expandedColor;

	Dvar_GetUnpackedColor(dvar, &expandedColor);
	return expandedColor.b;
}

float Dvar_GetColorBlue(int dvarHash)
{
	vec4_t expandedColor;
	dvar_t* dvar = Dvar_FindMalleableVar(dvarHash);
	return Dvar_GetColorBlue(dvar);
}

float Dvar_GetColorAlpha(dvar_t const* dvar)
{
	vec4_t expandedColor;

	Dvar_GetUnpackedColor(dvar, &expandedColor);
	return expandedColor.a;
}

float Dvar_GetColorAlpha(int dvarHash)
{
	dvar_t* dvar = Dvar_FindMalleableVar(dvarHash);
	return Dvar_GetColorAlpha(dvar);
}

bool Dvar_GetLatchedBool(dvar_t const* dvar)
{
	if (!dvar)
		return 0;
	return dvar->latched.enabled;
}

int Dvar_GetLatchedInt(dvar_t const* dvar)
{
	if (!dvar)
		return 0;
	return dvar->latched.integer;
}

float Dvar_GetLatchedFloat(dvar_t const* dvar)
{
	if (!dvar)
		return 0;
	return dvar->latched.value;
}

void Dvar_GetLatchedVec2(dvar_t const* dvar, vec2_t* result)
{
	if (dvar) {
		result->x = dvar->latched.value;
		result->y = dvar->latched.vector.v[1];
	}
	else
		*result = vec2_origin;
}

void Dvar_GetLatchedVec3(dvar_t const* dvar, vec3_t* result)
{
	if (dvar) {
		result->x = dvar->latched.value;
		result->y = dvar->latched.vector.v[1];
		result->z = dvar->latched.vector.v[2];
	}
	else
		*result = vec3_origin;
}

void Dvar_GetLatchedVec4(dvar_t const* dvar, vec4_t* result)
{
	if (dvar) {
		result->x = dvar->latched.value;
		result->y = dvar->latched.vector.v[1];
		result->z = dvar->latched.vector.v[2];
		result->w = dvar->latched.vector.v[3];
	}
	else
		*result = vec4_origin;
}

void Dvar_GetLatchedColor(dvar_t const* dvar, unsigned __int8* color)
{
	if (dvar->type == DVAR_TYPE_COLOR)
		*color = dvar->latched.integer;
	else
		*color = dvar->latched.integer;
}

int Dvar_GetResetInt(dvar_t const* dvar)
{
	if (!dvar)
		return 0;
	return dvar->reset.integer;
}

char const* Dvar_GetResetString(dvar_t const* dvar)
{
	if (!dvar)
		return "";
	return dvar->reset.string;
}

void Dvar_GetResetVec3(dvar_t const* dvar, vec3_t* result)
{
	if (dvar)
	{
		result->x = dvar->reset.value;
		result->y = dvar->reset.vector.v[1];
		result->z = dvar->reset.vector.v[2];
	}
	else
		*result = vec3_origin;
}

char const** Dvar_GetDomainEnumStrings(dvar_t const* dvar)
{
	return nullptr;
}

int Dvar_GetDomainEnumStringCount(dvar_t const* dvar)
{
	return 0;
}

int Dvar_GetDomainIntMin(dvar_t const* dvar)
{
	return 0;
}

int Dvar_GetDomainIntMax(dvar_t const*)
{
	return 0;
}

__int64 Dvar_GetDomainInt64Min(dvar_t const*)
{
	return 0;
}

__int64 Dvar_GetDomainInt64Max(dvar_t const*)
{
	return 0;
}

float Dvar_GetDomainFloatMin(dvar_t const*)
{
	return 0.0f;
}

float Dvar_GetDomainFloatMax(dvar_t const*)
{
	return 0.0f;
}

float Dvar_GetDomainVecMin(dvar_t const*)
{
	return 0.0f;
}

float Dvar_GetDomainVecMax(dvar_t const*)
{
	return 0.0f;
}

dvarType_t Dvar_GetType(dvar_t const*)
{
	return dvarType_t();
}

DvarValue Dvar_GetCurrent(dvar_t const*)
{
	return DvarValue();
}

DvarLimits Dvar_GetDomain(dvar_t const*)
{
	return DvarLimits();
}

char const* Dvar_GetDescription(dvar_t const*)
{
	return nullptr;
}

unsigned int Dvar_GetFlags(dvar_t const*)
{
	return 0;
}

char const* Dvar_GetName(dvar_t const*)
{
	return nullptr;
}

void Dvar_Shutdown(void)
{
}

void Dvar_PerformUnregistration(dvar_t*)
{
}

void Dvar_UpdateResetValue(dvar_t*, DvarValue)
{
}

void Dvar_ChangeResetValue(dvar_t const*, DvarValue)
{
}

void Dvar_UpdateValue(dvar_t*, DvarValue)
{
}

void Dvar_MakeExplicitType(dvar_t*, char const*, dvarType_t, unsigned int, DvarValue, DvarLimits)
{
}

void Dvar_ReinterpretDvar(dvar_t*, char const*, dvarType_t, unsigned int, DvarValue, DvarLimits)
{
}

dvar_t const* Dvar_RegisterNew(char const*, dvarType_t, unsigned int, DvarValue, DvarLimits, char const*)
{
	return nullptr;
}

void Dvar_AddFlags(dvar_t const*, int)
{
}

int Com_SaveDvarsToBuffer(char const** const, unsigned int, char*, unsigned int)
{
	return 0;
}

void Dvar_SetCanSetConfigDvars(bool)
{
}

bool Dvar_CanSetConfigDvar(dvar_t const*)
{
	return false;
}

bool Dvar_CanChangeValue(dvar_t const*, DvarValue, DvarSetSource)
{
	return false;
}

void Dvar_SetVariant(dvar_t*, DvarValue, DvarSetSource)
{
}

void Dvar_UpdateEnumDomain(dvar_t const*, char const** const)
{
}

bool Dvar_GetBool(dvar_t const*)
{
	return false;
}

int Dvar_GetInt(dvar_t const*)
{
	return 0;
}

__int64 Dvar_GetInt64(dvar_t const*)
{
	return 0;
}

float Dvar_GetFloat(dvar_t const*)
{
	return 0.0f;
}

void Dvar_MakeLatchedValueCurrent(dvar_t const*)
{
}

void Dvar_Reregister(dvar_t*, char const*, dvarType_t, unsigned int, DvarValue, DvarLimits, char const*)
{
}

dvar_t const* Dvar_RegisterVariant(char const*, dvarType_t, unsigned int, DvarValue, DvarLimits, char const*)
{
	return nullptr;
}

dvar_t const* _Dvar_RegisterBool(char const*, bool, unsigned int, char const*)
{
	return nullptr;
}

dvar_t const* _Dvar_RegisterInt(char const*, int, int, int, unsigned int, char const*)
{
	return nullptr;
}

dvar_t const* _Dvar_RegisterInt64(char const*, __int64, __int64, __int64, unsigned int, char const*)
{
	return nullptr;
}

dvar_t const* _Dvar_RegisterFloat(char const*, float, float, float, unsigned int, char const*)
{
	return nullptr;
}

dvar_t const* _Dvar_RegisterVec2(char const*, float, float, float, float, unsigned int, char const*)
{
	return nullptr;
}

dvar_t const* _Dvar_RegisterVec3(char const*, float, float, float, float, float, unsigned int, char const*)
{
	return nullptr;
}

dvar_t const* _Dvar_RegisterVec4(char const*, float, float, float, float, float, float, unsigned int, char const*)
{
	return nullptr;
}

dvar_t const* _Dvar_RegisterString(char const*, char const*, unsigned int, char const*)
{
	return nullptr;
}

dvar_t const* _Dvar_RegisterEnum(char const*, char const** const, int, unsigned int, char const*)
{
	return nullptr;
}

dvar_t const* _Dvar_RegisterColor(char const*, float, float, float, float, unsigned int, char const*)
{
	return nullptr;
}

dvar_t const* _Dvar_RegisterLinearRGB(char const*, float, float, float, float, float, unsigned int, char const*)
{
	return nullptr;
}

dvar_t const* _Dvar_RegisterColorXYZ(char const*, float, float, float, float, float, unsigned int, char const*)
{
	return nullptr;
}

void Dvar_SetBoolFromSource(dvar_t const*, bool, DvarSetSource)
{
}

void Dvar_SetIntFromSource(dvar_t const*, int, DvarSetSource)
{
}

void Dvar_SetInt64FromSource(dvar_t const*, __int64, DvarSetSource)
{
}

void Dvar_SetFloatFromSource(dvar_t const*, float, DvarSetSource)
{
}

void Dvar_SetVec2FromSource(dvar_t const*, float, float, DvarSetSource)
{
}

void Dvar_SetVec3FromSource(dvar_t const*, float, float, float, DvarSetSource)
{
}

void Dvar_SetVec4FromSource(dvar_t const*, float, float, float, float, DvarSetSource)
{
}

void Dvar_SetStringFromSource(dvar_t const*, char const*, DvarSetSource)
{
}

void Dvar_SetColorFromSource(dvar_t const*, float, float, float, float, DvarSetSource)
{
}

void Dvar_SetBool(dvar_t const*, bool)
{
}

void Dvar_SetInt(dvar_t const*, int)
{
}

void Dvar_SetFloat(dvar_t const*, float)
{
}

void Dvar_SetVec2(dvar_t const*, float, float)
{
}

void Dvar_SetVec3(dvar_t const*, float, float, float)
{
}

void Dvar_SetVec4(dvar_t const*, float, float, float, float)
{
}

void Dvar_SetVec4FromVec4(dvar_t const*, vec4_t&)
{
}

void Dvar_SetString(dvar_t const*, char const*)
{
}

dvar_t const* Dvar_SetOrRegisterString(dvar_t const*, char const*, char const*)
{
	return nullptr;
}

void Dvar_SetColor(dvar_t const*, float, float, float, float)
{
}

void Dvar_SetFromStringFromSource(dvar_t const*, char const*, DvarSetSource)
{
}

void Dvar_SetFromString(dvar_t const*, char const*)
{
}

dvar_t const* Dvar_SetFromStringByNameFromSource(char const*, char const*, DvarSetSource, unsigned int)
{
	return nullptr;
}

void Dvar_SetFromStringByName(char const*, char const*)
{
}

void Dvar_SetCommand(char const*, char const*)
{
}

void Dvar_Reset(dvar_t const*, DvarSetSource)
{
}

void Dvar_SetCheatState(void)
{
}

void Dvar_Init(void)
{
}

void Dvar_LoadDvarsAddFlags(MemoryFile*, unsigned short)
{
}

void Dvar_LoadDvars(MemoryFile*)
{
}

void Dvar_LoadScriptInfo(MemoryFile*)
{
}

void Dvar_ResetDvars(unsigned int, DvarSetSource)
{
}

int Com_LoadDvarsFromBufferOptional(char const** const, bool*, unsigned int, char const*, char const*)
{
	return 0;
}

void Dvar_SetBoolIfChanged(dvar_t const*, bool)
{
}

void Dvar_SetIntIfChanged(dvar_t const*, int)
{
}

void Dvar_SetFloatIfChanged(dvar_t const*, float)
{
}

void Dvar_SetStringIfChanged(dvar_t const*, char const*)
{
}

void Dvar_DoModifiedCallbacks(void)
{
}

int Com_LoadDvarsFromBuffer(char const** const, unsigned int, char const*, char const*)
{
	return 0;
}

void Dvar_Sort(void)
{
}

void Dvar_ForEachName(void(*)(char const*))
{
}

void Dvar_ForEachName(LocalClientNum_t, void(*)(LocalClientNum_t, char const*))
{
}

void Dvar_ForEach(void(*)(dvar_t const*, void*), void*)
{
}

void Dvar_SetModifiedCallback(dvar_t const*, void(*)(dvar_t const*))
{
}
