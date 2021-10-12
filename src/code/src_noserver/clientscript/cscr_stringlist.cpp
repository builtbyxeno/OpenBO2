#include "types.h"
#include "vars.h"
#include <clientscript/clientscript_public.h>
#include <qcommon/qcommon_public.h>

#define MT_NODE_SIZE 24
#define MT_SIZE 0x180000
#define HASH_NEXT_MASK 0xFFFF
#define HASH_STAT_MASK 0x30000
#define HASH_STAT_MOVABLE 0x10000
#define HASH_STAT_FREE 0

static HashEntry gScrStringHashTable[49152];
static scrStringDebugGlob_t* gScrStringDebugGlob;
static scrStringDebugGlob_t gScrStringDebugGlobBuff;

scrStringGlob_t gScrStringGlob =
{
  gScrStringHashTable,
  false,
  NULL,
  0,
  {
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0
  }
};

/*
==============
TRACK_scr_stringlist
==============
*/
void TRACK_scr_stringlist()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetRefString
==============
*/
RefString* GetRefString(unsigned int stringValue)
{
	assert(stringValue);
	assert(stringValue * MT_NODE_SIZE < MT_SIZE);

	return (RefString*)&gScrMemTreePub.mt_buffer[stringValue * MT_NODE_SIZE];
}

/*
==============
SL_ConvertToString
==============
*/
char *SL_ConvertToString(unsigned int stringValue)
{
	assertMsg((!stringValue || !gScrStringDebugGlob || gScrStringDebugGlob->refCount[stringValue]),
		"(stringValue) = %i", stringValue);

	if (stringValue)
	{
		return GetRefString(stringValue)->str;
	}

	return NULL;
}

/*
==============
SL_ConvertToStringSafe
==============
*/
char *SL_ConvertToStringSafe(unsigned int stringValue)
{
	assertMsg((!stringValue || !gScrStringDebugGlob || gScrStringDebugGlob->refCount[stringValue]),
		"(stringValue) = %i", stringValue);

	if (stringValue)
	{
		return GetRefString(stringValue)->str;
	}

	return "(NULL)";
}

/*
==============
SL_DebugConvertToString
==============
*/
const char *SL_DebugConvertToString(unsigned int stringValue)
{
	int len;
	int i;
	RefString* refString;

	if (!stringValue)
	{
		return "<NULL>";
	}

	refString = GetRefString(stringValue);
	len = refString->byteLen - 1;
	if (refString->str[len])
	{
		return "<BINARY>";
	}

	for (i = 0; i < len; ++i)
	{
		if (!isprint(refString->str[i]))
		{
			return "<BINARY>";
		}
	}
	return refString->str;
}

/*
==============
SL_GetStringLen
==============
*/
int SL_GetStringLen(unsigned int stringValue)
{
	RefString* refString;

	assert(stringValue);

	refString = GetRefString(stringValue);

	int len = refString->byteLen - 1;
	while (refString->str[len])
	{
		len += 256;
	}

	return len;
}

/*
==============
GetHashCode
==============
*/
unsigned int GetHashCode(const char *str, unsigned int len)
{
	unsigned int i;

	if (len >= 0x100)
		return (len >> 2) % 0xBFFF + 1;
	for (i = 0; len; --len)
		i = 31 * i + *str++;
	return i % 0xBFFF + 1;
}

/*
==============
Scr_GetHashCode
==============
*/
unsigned int Scr_GetHashCode(const char *str, unsigned int len)
{
	return GetHashCode(str, len);
}

/*
==============
SL_Init
==============
*/
void SL_Init()
{
	HashEntry* entry;
	unsigned int hash;
	unsigned int prev;

	assert(!gScrStringGlob.inited);
	MT_Init();
	Sys_EnterCriticalSection(CRITSECT_SCRIPT_STRING);

	gScrStringGlob.hashTable->status_next = 0;
	prev = 0;
	for (hash = 1; hash < 0xC000; ++hash)
	{
		assert(!(hash & HASH_STAT_MASK));
		entry = &gScrStringGlob.hashTable[hash];
		entry->status_next = 0;
		gScrStringGlob.hashTable[prev].status_next |= hash;
		entry->u.prev = prev;
		prev = hash;
	}

	assert(!(gScrStringGlob.hashTable[prev].status_next & HASH_NEXT_MASK));
	gScrStringGlob.hashTable->u.prev = prev;
	Scr_ResetScrStringDebugGlob();
	gScrStringGlob.indentLevel = 0;
	memset(gScrStringGlob.stringsUsed, 0, sizeof(gScrStringGlob.stringsUsed));
	gScrStringGlob.inited = 1;
	Sys_LeaveCriticalSection(CRITSECT_SCRIPT_STRING);
}

/*
==============
SL_GetStringOfSize
==============
*/
unsigned int SL_GetStringOfSize(const char* str, unsigned int user, unsigned int len, int type)
{
	int newNext;
	unsigned int stringValue;
	HashEntry* entry;
	unsigned int hash;
	int newIndex;
	RefString* refStr;
	int next;
	unsigned int prev;
	HashEntry* newEntry;

	assert(str);
	hash = GetHashCode(str, len);
	Sys_EnterCriticalSection(CRITSECT_SCRIPT_STRING);
	entry = &gScrStringGlob.hashTable[hash];
	if ((entry->status_next & HASH_STAT_MASK) == 0x20000)
	{
		refStr = GetRefString(entry->u.prev);
		if (refStr->byteLen == len && !memcmp(refStr->str, str, len))
		{
			SL_AddUserInternal(refStr, user);
			assert((entry->status_next & HASH_STAT_MASK) != HASH_STAT_FREE);
			stringValue = entry->u.prev;
			assert(refStr->str == SL_ConvertToString(stringValue));
			Sys_LeaveCriticalSection(CRITSECT_SCRIPT_STRING);

			return stringValue;
		}

		prev = hash;
		newIndex = entry->status_next & 0xFFFF;
		for (newEntry = &gScrStringGlob.hashTable[newIndex];
			newEntry != entry;
			newEntry = &gScrStringGlob.hashTable[newIndex])
		{
			assert((newEntry->status_next & HASH_STAT_MASK) == HASH_STAT_MOVABLE);
			refStr = GetRefString(newEntry->u.prev);
			if (refStr->byteLen == len
				&& !memcmp(refStr->str, str, len))
			{
				gScrStringGlob.hashTable[prev].status_next = newEntry->status_next & 0xFFFF | gScrStringGlob.hashTable[prev].status_next & 0x30000;
				newEntry->status_next = entry->status_next & 0xFFFF | newEntry->status_next & 0x30000;
				entry->status_next = newIndex | entry->status_next & HASH_STAT_MASK;
				stringValue = newEntry->u.prev;
				newEntry->u.prev = entry->u.prev;
				entry->u.prev = stringValue;
				SL_AddUserInternal(refStr, user);

				assert((newEntry->status_next & HASH_STAT_MASK) != HASH_STAT_FREE);
				assert((entry->status_next & HASH_STAT_MASK) != HASH_STAT_FREE);
				assert(refStr->str == SL_ConvertToString(stringValue));
				Sys_LeaveCriticalSection(CRITSECT_SCRIPT_STRING);

				return stringValue;
			}
			prev = newIndex;
			newIndex = newEntry->status_next & 0xFFFF;
		}

		newIndex = gScrStringGlob.hashTable->status_next;
		if (!newIndex)
		{
			Scr_DumpScriptThreads(SCRIPTINSTANCE_SERVER);
			Scr_DumpScriptVariablesDefault(SCRIPTINSTANCE_SERVER);
			Com_Error(ERR_DROP, "\x15" "" "exceeded maximum number of script strings\n");
		}
		stringValue = MT_AllocIndex(len + 4, type);
		newEntry = &gScrStringGlob.hashTable[newIndex];

		assert((newEntry->status_next & HASH_STAT_MASK) == HASH_STAT_FREE);
		newNext = newEntry->status_next & 0xFFFF;
		gScrStringGlob.hashTable->status_next = newNext;
		gScrStringGlob.hashTable[newNext].u.prev = 0;
		newEntry->status_next = entry->status_next & 0xFFFF | 0x10000;
		entry->status_next = newIndex | entry->status_next & HASH_STAT_MASK;
		newEntry->u.prev = entry->u.prev;
	}
	else
	{
		if (entry->status_next & HASH_STAT_MASK)
		{
			assert((entry->status_next & HASH_STAT_MASK) == HASH_STAT_MOVABLE);
			next = entry->status_next & 0xFFFF;
			for (prev = entry->status_next & 0xFFFF;
				(gScrStringGlob.hashTable[prev].status_next & 0xFFFF) != hash;
				prev = gScrStringGlob.hashTable[prev].status_next & 0xFFFF)
			{
				;
			}

			assert(prev);
			newIndex = gScrStringGlob.hashTable->status_next;
			if (!newIndex)
			{
				Scr_DumpScriptThreads(SCRIPTINSTANCE_SERVER);
				Scr_DumpScriptVariablesDefault(SCRIPTINSTANCE_SERVER);
				Com_Error(ERR_DROP, "\x15" "exceeded maximum number of script strings\n");
			}

			stringValue = MT_AllocIndex(len + 4, type);
			newEntry = &gScrStringGlob.hashTable[newIndex];

			assert((newEntry->status_next & HASH_STAT_MASK) == HASH_STAT_FREE);
			newNext = newEntry->status_next & 0xFFFF;
			gScrStringGlob.hashTable->status_next = newNext;
			gScrStringGlob.hashTable[newNext].u.prev = 0;
			gScrStringGlob.hashTable[prev].status_next = newIndex | gScrStringGlob.hashTable[prev].status_next & 0x30000;
			newEntry->status_next = next | 0x10000;
			newEntry->u.prev = entry->u.prev;
		}
		else
		{
			stringValue = MT_AllocIndex(len + 4, type);
			newNext = entry->status_next & 0xFFFF;
			gScrStringGlob.hashTable[entry->u.prev].status_next = newNext | gScrStringGlob.hashTable[entry->u.prev].status_next & 0x30000;
			gScrStringGlob.hashTable[newNext].u.prev = entry->u.prev;
		}

		assert(!(hash & HASH_STAT_MASK));
		entry->status_next = hash | 0x20000;
	}

	++gScrStringGlob.stringsUsed[gScrStringGlob.indentLevel];
	assert(stringValue);
	entry->u.prev = stringValue;
	refStr = GetRefString(stringValue);
	memcpy(refStr->str, str, len);
	refStr->user = user;

	assert(refStr->user == user);
	refStr->refCount = 1;
	refStr->byteLen = len;
	if (gScrStringDebugGlob)
	{
		InterlockedIncrement(&gScrStringDebugGlob->totalRefCount);
		InterlockedIncrement(&gScrStringDebugGlob->refCount[stringValue]);
	}

	assert((entry->status_next & HASH_STAT_MASK) != HASH_STAT_FREE);
	assert(refStr->str == SL_ConvertToString(stringValue));
	Sys_LeaveCriticalSection(CRITSECT_SCRIPT_STRING);

	return stringValue;
}

/*
==============
SL_FindStringOfSize
==============
*/
unsigned int SL_FindStringOfSize(const char *str, unsigned int len)
{
	unsigned int stringValue;
	HashEntry* entry;
	unsigned int hash;
	int newIndex;
	RefString* refStr;
	unsigned int prev;
	HashEntry* newEntry;

	assert(str);
	hash = GetHashCode(str, len);
	Sys_EnterCriticalSection(CRITSECT_SCRIPT_STRING);
	entry = &gScrStringGlob.hashTable[hash];
	if ((entry->status_next & HASH_STAT_MASK) != 0x20000)
	{
		Sys_LeaveCriticalSection(CRITSECT_SCRIPT_STRING);
		return 0;
	}

	refStr = GetRefString(entry->u.prev);
	if (refStr->byteLen != (unsigned char)len || memcmp(refStr->str, str, len))
	{
		prev = hash;
		newIndex = entry->status_next & 0xFFFF;
		for (newEntry = &gScrStringGlob.hashTable[newIndex];
			newEntry != entry;
			newEntry = &gScrStringGlob.hashTable[newIndex])
		{
			assert((newEntry->status_next & HASH_STAT_MASK) == HASH_STAT_MOVABLE);
			refStr = GetRefString(newEntry->u.prev);

			if (refStr->byteLen == (unsigned char)len
				&& !memcmp(refStr->str, str, len))
			{
				gScrStringGlob.hashTable[prev].status_next = newEntry->status_next & 0xFFFF | gScrStringGlob.hashTable[prev].status_next & 0x30000;
				newEntry->status_next = entry->status_next & 0xFFFF | newEntry->status_next & 0x30000;
				entry->status_next = newIndex | entry->status_next & HASH_STAT_MASK;
				stringValue = newEntry->u.prev;
				newEntry->u.prev = entry->u.prev;
				entry->u.prev = stringValue;

				assert((newEntry->status_next & HASH_STAT_MASK) != HASH_STAT_FREE);
				assert((entry->status_next & HASH_STAT_MASK) != HASH_STAT_FREE);
				assert(refStr->str == SL_ConvertToString(stringValue));

				Sys_LeaveCriticalSection(CRITSECT_SCRIPT_STRING);
				return stringValue;
			}

			prev = newIndex;
			newIndex = newEntry->status_next & 0xFFFF;
		}

		Sys_LeaveCriticalSection(CRITSECT_SCRIPT_STRING);
		return 0;
	}

	assert((entry->status_next & HASH_STAT_MASK) != HASH_STAT_FREE);
	stringValue = entry->u.prev;

	assert(refStr->str == SL_ConvertToString(stringValue));
	Sys_LeaveCriticalSection(CRITSECT_SCRIPT_STRING);

	return stringValue;
}

/*
==============
SL_FindString
==============
*/
unsigned int SL_FindString(const char *str)
{
	return SL_FindStringOfSize(str, strlen(str) + 1);
}

/*
==============
SL_FindLowercaseString
==============
*/
unsigned int SL_FindLowercaseString(const char *str)
{
	char newStr[8192];
	int len;
	int i;

	len = strlen(str) + 1;
	if (len > 0x2000)
	{
		return 0;
	}

	for (i = 0; i < len; ++i)
	{
		newStr[i] = tolower(str[i]);
	}

	return SL_FindStringOfSize(newStr, len);
}

/*
==============
SL_IsLowercaseString
==============
*/
int SL_IsLowercaseString(unsigned int stringValue)
{
	const char* str;

	assert(stringValue);
	for (str = SL_ConvertToString(stringValue); *str; ++str)
	{
		if (*str != (char)tolower(*str))
		{
			return 0;
		}
	}
	return 1;
}

/*
==============
SL_ConvertFromRefString
==============
*/
inline int SL_ConvertFromRefString(RefString* refString)
{
	return ((char*)refString - gScrMemTreePub.mt_buffer) / MT_NODE_SIZE;
}

/*
==============
SL_AddUserInternal
==============
*/
void SL_AddUserInternal(RefString *refStr, unsigned int user)
{
	RefString exchange;
	RefString compare;
	int str;

	if (!(user & refStr->user))
	{
		str = SL_ConvertFromRefString(refStr);
		if (gScrStringDebugGlob)
		{
			assertMsg((gScrStringDebugGlob->refCount[str] < 65536), "(SL_DebugConvertToString( str, inst )) = %s",
				SL_DebugConvertToString(str, inst));
			assertMsg((gScrStringDebugGlob->refCount[str] >= 0), "(SL_DebugConvertToString( str, inst )) = %s",
				SL_DebugConvertToString(str, inst));

			InterlockedIncrement(&gScrStringDebugGlob->totalRefCount);
			InterlockedIncrement(&gScrStringDebugGlob->refCount[str]);
		}

		do
		{
			compare.data = refStr->data;

			exchange.data = compare.data;
			exchange.user |= user;
		} while (InterlockedCompareExchange(&refStr->data, exchange.data, compare.data) != (DWORD)compare.data);
		InterlockedIncrement(&refStr->data);
	}
}

/*
==============
SL_GetString
==============
*/
unsigned int SL_GetString(const char *str, unsigned int user, int type)
{
	return SL_GetStringOfSize(str, user, strlen(str) + 1, type);
}

/*
==============
SL_GetLowercaseStringOfSize
==============
*/
unsigned int SL_GetLowercaseStringOfSize(const char *str, unsigned int user, unsigned int len, int type)
{
	char newStr[8192];
	unsigned int i;

	if (len <= 0x2000)
	{
		for (i = 0; i < len; ++i)
		{
			newStr[i] = tolower(str[i]);
		}

		return SL_GetStringOfSize(newStr, user, len, type);
	}
	else
	{
		Com_Error(ERR_DROP, "max string length exceeded: \"%s\"", str);

		return 0;
	}
}

/*
==============
SL_GetLowercaseString_
==============
*/
unsigned int SL_GetLowercaseString_(const char *str, unsigned int user, int type)
{
	return SL_GetLowercaseStringOfSize(str, user, strlen(str) + 1, type);
}

/*
==============
SL_GetLowercaseString
==============
*/
unsigned int SL_GetLowercaseString(const char *str, unsigned int user)
{
	return SL_GetLowercaseString_(str, user, 6);
}

/*
==============
SL_CheckExists
==============
*/
void SL_CheckExists(unsigned int stringValue)
{
	assertMsg(!gScrStringDebugGlob || gScrStringDebugGlob->refCount[stringValue],
		va("%d '%s'", stringValue, SL_DebugConvertToString(stringValue)));
}

/*
==============
SL_AddRefToString
==============
*/
void SL_AddRefToString(unsigned int stringValue)
{
	RefString* refStr;

	if (gScrStringDebugGlob)
	{
		assertMsg(gScrStringDebugGlob->refCount[stringValue],
			va("%d '%s'", stringValue, SL_DebugConvertToString(stringValue, inst)));
		assertMsg((gScrStringDebugGlob->refCount[stringValue] < 65536), "SL_DebugConvertToString( stringValue, inst )",
			SL_DebugConvertToString(stringValue, inst));

		InterlockedIncrement(&gScrStringDebugGlob->totalRefCount);
		InterlockedIncrement(&gScrStringDebugGlob->refCount[stringValue]);
	}

	refStr = GetRefString(stringValue);
	InterlockedIncrement(&refStr->data);

	assertMsg(refStr->refCount, va("string: '%s', refCount: %d", SL_DebugConvertToString(stringValue, inst),
		gScrStringDebugGlob ? gScrStringDebugGlob->refCount[stringValue] : 0));
}

/*
==============
SL_FreeString
==============
*/
void SL_FreeString(unsigned int stringValue, RefString *refStr, unsigned int len)
{
	HashEntry* entry;
	int newIndex;
	unsigned int newNext;
	unsigned int index;
	unsigned int prev;
	HashEntry* newEntry;

	index = GetHashCode(refStr->str, len);
	Sys_EnterCriticalSection(CRITSECT_SCRIPT_STRING);
	if (refStr->refCount)
	{
		Sys_LeaveCriticalSection(CRITSECT_SCRIPT_STRING);
	}
	else
	{
		entry = &gScrStringGlob.hashTable[index];
		assertMsg((!refStr->user), "(SL_DebugConvertToString( stringValue, inst )) = %s", SL_DebugConvertToString(stringValue, inst));

		MT_FreeIndex(stringValue, len + 4);
		assertMsg(((entry->status_next & HASH_STAT_MASK) == HASH_STAT_HEAD), "(entry->status_next) = %i", entry->status_next);
		newIndex = entry->status_next & 0xFFFF;
		newEntry = &gScrStringGlob.hashTable[newIndex];
		if (entry->u.prev == stringValue)
		{
			--gScrStringGlob.stringsUsed[gScrStringGlob.indentLevel];
			if (newEntry == entry)
			{
				newEntry = entry;
				newIndex = index;
			}
			else
			{
				entry->status_next = newEntry->status_next & 0xFFFF | 0x20000;
				entry->u.prev = newEntry->u.prev;
				gScrStringGlob.nextFreeEntry = entry;
			}
		}
		else
		{
			prev = index;
			while (1)
			{
				assert(newEntry != entry);
				assert((newEntry->status_next & HASH_STAT_MASK) == HASH_STAT_MOVABLE);
				if (newEntry->u.prev == stringValue)
				{
					break;
				}
				prev = newIndex;
				newIndex = newEntry->status_next & 0xFFFF;
				newEntry = &gScrStringGlob.hashTable[newIndex];
			}
			gScrStringGlob.hashTable[prev].status_next = newEntry->status_next & 0xFFFF | gScrStringGlob.hashTable[prev].status_next & 0x30000;
		}

		assert((newEntry->status_next & HASH_STAT_MASK) != HASH_STAT_FREE);
		newNext = gScrStringGlob.hashTable->status_next;

		assert((newNext & HASH_STAT_MASK) == HASH_STAT_FREE);
		newEntry->status_next = newNext;
		newEntry->u.prev = 0;
		gScrStringGlob.hashTable[newNext].u.prev = newIndex;
		gScrStringGlob.hashTable->status_next = newIndex;
		Sys_LeaveCriticalSection(CRITSECT_SCRIPT_STRING);
	}
}

/*
==============
SL_GetRefStringLen
==============
*/
inline int SL_GetRefStringLen(RefString* refString)
{
	int len;

	len = refString->byteLen - 1;
	while (refString->str[len])
	{
		len += 256;
	}

	return len;
}

/*
==============
SL_RemoveRefToString
==============
*/
void __cdecl SL_RemoveRefToString(unsigned int stringValue)
{
	RefString* refStr;
	int len;

	refStr = GetRefString(stringValue);
	len = SL_GetRefStringLen(refStr) + 1;
	SL_RemoveRefToStringOfSize(stringValue, len);
}

/*
==============
SL_RemoveRefToStringOfSize
==============
*/
void SL_RemoveRefToStringOfSize(unsigned int stringValue, unsigned int len)
{
	RefString* refStr;

	refStr = GetRefString(stringValue);
	//if ( Sys_InterlockedDecrement((volatile int *)&refStr->data) << 16 )
	if (InterlockedDecrement(&refStr->data) << 16)
	{
		if (gScrStringDebugGlob)
		{
			assertMsg(gScrStringDebugGlob->totalRefCount && gScrStringDebugGlob->refCount[stringValue],
				va("gScrStringDebugGlob->totalRefCount: %i, stringValue: %i, gScrStringDebugGlob->refCount[string"
					"Value]: %i, string: '%s'",
					gScrStringDebugGlob->totalRefCount,
					stringValue,
					gScrStringDebugGlob->refCount[stringValue],
					SL_DebugConvertToString(stringValue, inst)));
			assertMsg((gScrStringDebugGlob->refCount[stringValue]), "(SL_DebugConvertToString( stringValue, inst )) = %s",
				SL_DebugConvertToString(stringValue, inst));

			InterlockedDecrement(&gScrStringDebugGlob->totalRefCount);
			InterlockedDecrement(&gScrStringDebugGlob->refCount[stringValue]);
		}
	}
	else
	{
		SL_FreeString(stringValue, refStr, len);
		if (gScrStringDebugGlob)
		{
			assertMsg(gScrStringDebugGlob->totalRefCount && gScrStringDebugGlob->refCount[stringValue],
				va(
					"gScrStringDebugGlob->totalRefCount: %i, stringValue: %i, gScrStringDebugGlob->refCount[string"
					"Value]: %i, string: '%s'",
					gScrStringDebugGlob->totalRefCount,
					stringValue,
					gScrStringDebugGlob->refCount[stringValue],
					SL_DebugConvertToString(stringValue, inst)));
			assertMsg((gScrStringDebugGlob->refCount[stringValue]), "(SL_DebugConvertToString( stringValue, inst )) = %s",
				SL_DebugConvertToString(stringValue, inst));

			InterlockedDecrement(&gScrStringDebugGlob->totalRefCount);
			InterlockedDecrement(&gScrStringDebugGlob->refCount[stringValue]);
		}
	}
}

/*
==============
Scr_SetStringLiveUpdateSafe
==============
*/
void Scr_SetStringLiveUpdateSafe(unsigned __int16 *to, const char *value)
{
	int substrLen;
	const char* substr;
	RefString* refStr;
	char pfValue[128];
	const char* destString;

	if (*to)
	{
		destString = SL_ConvertToString(*to);
		if (!destString || I_stricmp(destString, value))
		{
			if (*destString == 112 && destString[1] == 102)
			{
				substr = I_stristr(destString, "_");
				if (substr)
				{
					substrLen = substr - destString + 2;
					I_strncpyz(pfValue, destString, substrLen);
					I_strncpyz((char*)&refStr + substrLen + 3, value, 128 - substrLen);
					if (!I_stricmp(destString, pfValue))
					{
						return;
					}
					value = pfValue;
				}
			}

			refStr = GetRefString(*to);
			if (refStr->refCount == 0)
			{
				SL_RemoveRefToString(*to);
			}
			*to = SL_GetStringOfSize(value, 0, strlen(value) + 1, 6);
		}
	}
	else
	{
		*to = SL_GetStringOfSize(value, 0, strlen(value) + 1, 6);
	}
}

/*
==============
Scr_SetString
==============
*/
void Scr_SetString(unsigned __int16 *to, unsigned int from)
{
	if (from)
	{
		SL_AddRefToString(from);
	}
	if (*to)
	{
		SL_RemoveRefToString(*to);
	}
	*to = from;
}

/*
==============
Scr_SetStringFromCharString
==============
*/
void Scr_SetStringFromCharString(unsigned __int16 *to, const char *from)
{
	if (*to)
	{
		SL_RemoveRefToString(*to);
	}
	*to = SL_GetStringOfSize(from, 0, strlen(from) + 1, 6);
}

/*
==============
Scr_AllocString
==============
*/
unsigned int Scr_AllocString(const char *s, int sys)
{
	assert(sys == SCR_SYS_GAME);
	return SL_GetStringOfSize(s, 1, strlen(s) + 1, 6);
}

/*
==============
SL_GetStringForFloat
==============
*/
unsigned int SL_GetStringForFloat(float f)
{
	char tempString[128];

	sprintf(tempString, "%g", f);
	return SL_GetStringOfSize(tempString, 0, strlen(tempString) + 1, 15);
}

/*
==============
SL_GetStringForInt
==============
*/
unsigned int SL_GetStringForInt(int i)
{
	char tempString[128];

	I_itoa(i, tempString, 128);
	return SL_GetStringOfSize(tempString, 0, strlen(tempString) + 1, 15);
}

/*
==============
SL_GetStringForVector
==============
*/
unsigned int SL_GetStringForVector(const float *v)
{
	char tempString[128];

	sprintf(tempString, "(%g, %g, %g)", v[0], v[1], v[2]);
	return SL_GetStringOfSize(tempString, 0, strlen(tempString) + 1, 15);
}

/*
==============
SL_ShutdownSystem
==============
*/
void SL_ShutdownSystem(unsigned int user)
{
	unsigned int hash;
	HashEntry* entry;
	RefString* refStr;

	assert(user);
	Sys_EnterCriticalSection(CRITSECT_SCRIPT_STRING);
	for (hash = 1; hash < 0xC000; ++hash)
	{
		do
		{
			entry = &gScrStringGlob.hashTable[hash];
			if (!(entry->status_next & HASH_STAT_MASK))
			{
				break;
			}

			refStr = GetRefString(entry->u.prev);
			if (!(user & refStr->user))
			{
				break;
			}

			refStr->user &= ~user;
			gScrStringGlob.nextFreeEntry = 0;
			SL_RemoveRefToString(entry->u.prev);
		} while (gScrStringGlob.nextFreeEntry);
	}

	Sys_LeaveCriticalSection(CRITSECT_SCRIPT_STRING);
}

/*
==============
Scr_ShutdownGameStrings
==============
*/
void Scr_ShutdownGameStrings()
{
	SL_ShutdownSystem(1);
}

/*
==============
SL_TransferSystem
==============
*/
void SL_TransferSystem(unsigned int from, unsigned int to)
{
	unsigned int hash;
	HashEntry* entry;
	RefString* refStr;

	assert(from);
	assert(to);
	Sys_EnterCriticalSection(CRITSECT_SCRIPT_STRING);
	for (hash = 1; hash < 0xC000; ++hash)
	{
		entry = &gScrStringGlob.hashTable[hash];
		if (entry->status_next & HASH_STAT_MASK)
		{
			refStr = GetRefString(entry->u.prev);
			if (from & refStr->user)
			{
				refStr->user = ~from & refStr->user;
				refStr->user = to | refStr->user;
			}
		}
	}
	Sys_LeaveCriticalSection(CRITSECT_SCRIPT_STRING);
}

/*
==============
SL_CreateCanonicalFilename
==============
*/
void SL_CreateCanonicalFilename(char *newFilename, const char *filename, int count)
{
	unsigned int c;

	assert(count);

	while (1)
	{
		do
		{
			c = *filename++;
		} while (c == '\\');

		if (c != '/')
		{
			while (c >= ' ')
			{
				*newFilename++ = tolower(c);
				--count;
				if (!count)
				{
					Com_Error(ERR_DROP, "\x15" "Filename '%s' exceeds maximum length", filename);
				}

				if (c == '/')
				{
					break;
				}

				c = *filename++;
				if (c == '\\')
				{
					c = '/';
				}
			}

			if (!c)
			{
				break;
			}
		}
	}
	*newFilename = 0;
}

/*
==============
Scr_CreateCanonicalFilename
==============
*/
unsigned int Scr_CreateCanonicalFilename(const char *filename)
{
	char newFilename[1024];

	SL_CreateCanonicalFilename(newFilename, filename, sizeof(newFilename));
	return SL_GetStringOfSize(newFilename, 0, strlen(newFilename) + 1, 7);
}

/*
==============
SL_CheckLeaks
==============
*/
void SL_CheckLeaks()
{
	unsigned int i;

	if (gScrStringDebugGlob)
	{
		if (!gScrStringDebugGlob->ignoreLeaks)
		{
			for (i = 1; i < 0x10000; ++i)
			{
				if (gScrStringDebugGlob->refCount[i])
				{
					Com_PrintError(1, "leaked string = '%s', refcount = %i, i = %i\n",
						SL_DebugConvertToString(i), gScrStringDebugGlob->refCount[i], i);
				}
			}
			assertMsg((!gScrStringDebugGlob->totalRefCount), "(gScrStringDebugGlob->totalRefCount) = %i",
				gScrStringDebugGlob->totalRefCount);
		}
		Scr_ClearScrStringDebugGlob();
	}
}

/*
==============
SL_Shutdown
==============
*/
void SL_Shutdown()
{
	if (gScrStringGlob.inited)
	{
		gScrStringGlob.inited = 0;
		SL_CheckLeaks();
	}
}

