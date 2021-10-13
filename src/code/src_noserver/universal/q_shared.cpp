#include "types.h"
#include "vars.h"

#include "universal_public.h"
#include <clientscript/clientscript_public.h>
#include <qcommon/qcommon_public.h>
#include <physics/physics_public.h>
#include <tracers/tracers_public.h>
#include <sound/sound_public.h>
#include <gfx_d3d/gfx_d3d_public.h>
#include <gfx_d3d/gfx_d3d_public.h>
#include <effectscore/effectscore_public.h>

static va_info_t va_info[15];
static int g_com_error[15][16];
static TraceThreadInfo g_traceThreadInfo[15];
static CmdArgs g_cmd_args[2];

#define MAX_INFO_STRING 1024
#define BIG_INFO_STRING 0x4000

/*
==============
TRACK_q_shared
==============
*/
void TRACK_q_shared()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ColorIndex
==============
*/
char ColorIndex(unsigned char c)
{
	if ((int)(c - 48) >= 17)
	{
		return 7;
	}
	else
	{
		return c - 48;
	}
}

/*
==============
Com_GetFilenameSubString
==============
*/
const char *Com_GetFilenameSubString(const char *pathname)
{
	const char* last;

	last = pathname;
	while (*pathname)
	{
		if (*pathname == '/' || *pathname == '\\')
		{
			last = pathname + 1;
		}
		++pathname;
	}
	return last;
}

/*
==============
Com_GetExtensionSubString
==============
*/
const char *Com_GetExtensionSubString(const char *filename)
{
	const char* substr;

	assert(filename);
	substr = NULL;
	while (*filename)
	{
		if (*filename == '.')
		{
			substr = filename;
		}
		else if (*filename == '/' || *filename == '\\')
		{
			substr = NULL;
		}
		++filename;
	}
	if (!substr)
	{
		substr = filename;
	}
	return substr;
}

/*
==============
Com_StripExtension
==============
*/
void Com_StripExtension(const char *in, char *out)
{
	const char* extension;

	extension = Com_GetExtensionSubString(in);
	while (in != extension)
	{
		*out++ = *in++;
	}
	*out = 0;
}

/*
==============
BigShort
==============
*/
__int16 BigShort(__int16 l)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BigLong
==============
*/
int BigLong(int l)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BigLong64
==============
*/
unsigned __int64 BigLong64(unsigned __int64 l)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LittleShort
==============
*/
__int16 LittleShort(__int16 l)
{
	UNIMPLEMENTED(__FUNCTION__);
	__int16 tmp;
	return tmp;
}

/*
==============
LittleLong
==============
*/
int LittleLong(int l)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LittleFloatWrite
==============
*/
int LittleFloatWrite(float l)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ShortSwap
==============
*/
int ShortSwap(__int16 l)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ShortNoSwap
==============
*/
__int16 ShortNoSwap(__int16 l)
{
	UNIMPLEMENTED(__FUNCTION__);
	__int16 tmp;
	return tmp;
}

/*
==============
LongSwap
==============
*/
int LongSwap(int l)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Long64Swap
==============
*/
unsigned __int64 Long64Swap(unsigned __int64 l)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Long64NoSwap
==============
*/
unsigned __int64 Long64NoSwap(unsigned __int64 ll)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FloatReadNoSwap
==============
*/
double FloatReadNoSwap(int n)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Swap_Init
==============
*/
void Swap_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
I_atoui
==============
*/
unsigned int I_atoui(const char *str)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
I_atoi64
==============
*/
__int64 I_atoi64(const char *str)
{
	return _atoi64(str);
}

/*
==============
I_islower
==============
*/
BOOL I_islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return true;
	}
	return false;
}

/*
==============
I_isupper
==============
*/
BOOL I_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return TRUE;
	}
	return FALSE;
}

/*
==============
I_isalpha
==============
*/
BOOL I_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return TRUE;
	}
	return FALSE;
}


/*
==============
I_isdigit
==============
*/
BOOL I_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return TRUE;
	}

	return FALSE;
}

/*
==============
I_isalnum
==============
*/
BOOL I_isalnum(int c)
{
	return I_isalpha(c) || I_isdigit(c);
}

/*
==============
I_isforfilename
==============
*/
BOOL I_isforfilename(int c)
{
	if (I_isalnum(c) || c == '_' || c == '-')
	{
		return TRUE;
	}

	return FALSE;
}

/*
==============
I_strncpyz
==============
*/
void I_strncpyz(char *dest, const char *src, int destsize)
{
	assert(src);
	assert(dest);
	assertMsg((destsize >= 1), "(destsize) = %i", destsize);

	strncpy(dest, src, destsize - 1);
	dest[destsize - 1] = 0;
}

/*
==============
I_strnicmp
==============
*/
int I_strnicmp(const char *s0, const char *s1, int n)
{
	int c1;
	int c0;

	assert(s0);
	assert(s1);

	if (!s0 || !s1)
	{
		return s1 - s0;
	}

	do
	{
		c0 = *s0++;
		c1 = *s1++;

		if (!n--)
		{
			return 0;       // strings are equal until end point
		}

		if (c0 != c1)
		{
			if (I_isupper(c0))
			{
				c0 += 32;
			}
			if (I_isupper(c1))
			{
				c1 += 32;
			}
			if (c0 != c1)
			{
				return c0 < c1 ? -1 : 1;
			}
		}
	} while (c0);

	return 0;
}

/*
==============
I_strncmp
==============
*/
int I_strncmp(const char *s0, const char *s1, int n)
{
	int c1;
	int c0;

	assert(s0);
	assert(s1);

	if (!s0 || !s1)
	{
		return s1 - s0;
	}

	do
	{
		c0 = *s0++;
		c1 = *s1++;

		if (!--n)       // strings are equal until end point
		{
			return 0;
		}
		if (c0 != c1)
		{
			return c0 < c1 ? -1 : 1;
		}
	} while (c0);

	return 0;      // strings are equal
}

/*
==============
I_stristr
==============
*/
const char *I_stristr(const char *s0, const char *substr)
{
	int sc;
	int s0Char;
	int substrChar;

	assert(s0);
	assert(substr);
	if (!s0 || !substr)
	{
		return 0;
	}

	for (s0Char = 0; s0[s0Char]; ++s0Char)
	{
		substrChar = -1;
		do
		{
			if (!substr[++substrChar])
			{
				return &s0[s0Char];
			}
			sc = tolower(s0[substrChar + s0Char]);
		} while (sc == tolower(substr[substrChar]));
	}
	return 0;
}

/*
==============
I_stricmp
==============
*/
int I_stricmp(const char *s0, const char *s1)
{
	assert(s0);
	assert(s1);
	return I_strnicmp(s0, s1, 0x7FFFFFFF);
}

/*
==============
I_strcmp
==============
*/
int I_strcmp(const char *s0, const char *s1)
{
	assert(s0);
	assert(s1);
	return I_strncmp(s0, s1, 0x7FFFFFFF);
}

/*
==============
I_stricmpwild
==============
*/
int I_stricmpwild(const char *wild, const char *s)
{
	int delta;
	char charWild;
	char charRef;

	assert(wild);
	assert(s);

	do
	{
		charWild = *wild++;
		if (charWild == '*')
		{
			if (!*wild)
			{
				return 0;
			}

			if (*s && !I_stricmpwild(wild - 1, s + 1))
			{
				return 0;
			}
		}
		else
		{
			charRef = *s++;
			if (charWild != charRef && charWild != '?')
			{
				delta = tolower(charWild) - tolower(charRef);
				if (delta != 0)
				{
					return 1;
				}
			}
		}
	} while (charWild);

	return 0;
}

/*
==============
I_strlwr
==============
*/
char *I_strlwr(char *s)
{
	char* iter;

	for (iter = s; *iter; ++iter)
	{
		if (I_isupper(*iter))
		{
			*iter += 32;
		}
	}
	return s;
}

/*
==============
I_strupr
==============
*/
char *I_strupr(char *s)
{
	char* iter;

	for (iter = s; *iter; ++iter)
	{
		if (I_islower(*iter))
		{
			*iter -= 32;
		}
	}
	return s;
}

/*
==============
I_iscsym
==============
*/
BOOL I_iscsym(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return 1;
	}
	if (c >= 'A' && c <= 'Z')
	{
		return 1;
	}
	if (c < '0' || c > '9')
	{
		return c == '_';
	}
	return 1;
}

/*
==============
I_strncat
==============
*/
void I_strncat(char *dest, int size, const char *src)
{
	int destLen;

	assert(size != sizeof(char*));
	destLen = strlen(dest);
	if (destLen >= size)
	{
		Com_Error(ERR_FATAL, "\x15" "I_strncat: already overflowed");
	}

	I_strncpyz(&dest[destLen], src, size - destLen);
}

/*
==============
I_DrawStrlen
==============
*/
int I_DrawStrlen(const char *str)
{
	const char* s;
	int count;

	s = str;
	count = 0;
	while (*s)
	{
		if (s && *s == '^' && s[1] && s[1] != '^' && s[1] >= '0' && s[1] <= '@')
		{
			s += 2;
		}
		else
		{
			++count;
			++s;
		}
	}
	return count;
}

/*
==============
I_IsSpecialToken
==============
*/
bool I_IsSpecialToken(const char *buf)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
I_IsSpecialTokenRecursive
==============
*/
int I_IsSpecialTokenRecursive(const char *buf)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
I_CleanChat
==============
*/
char *I_CleanChat(char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
I_CleanStr
==============
*/
char *I_CleanStr(char *string)
{
	char* d;
	char c;
	char* s;
	int keep_cleaning;

	do
	{
		s = string;
		d = string;
		keep_cleaning = 0;

		while (1)
		{
			c = *s;
			if (!*s)
			{
				break;
			}
			if (s && *s == '^' && s[1] && s[1] != '^' && s[1] >= '0' && s[1] <= '@')
			{
				++s;
				keep_cleaning = 1;
			}
			else if (c >= 0x20 && c != 0x7F)
			{
				*d++ = c;
			}
			++s;
		}
		*d = '\0';
	} while (keep_cleaning);

	return string;
}

/*
==============
I_CleanChar
==============
*/
char I_CleanChar(char character)
{
	if ((unsigned char)character == 146)
	{
		return 39;
	}
	else
	{
		return character;
	}
}

/*
==============
Com_sprintf
==============
*/
int Com_sprintf(char *dest, int size, const char *fmt, ...)
{
	int result;
	va_list va;

	va_start(va, fmt);
	result = _vsnprintf(dest, size, fmt, va);
	dest[size - 1] = 0;
	va_end(va);

	return result;
}

/*
==============
Com_sprintfPos
==============
*/
int Com_sprintfPos(char *dest, const int destSize, int *destPos, const char *fmt, ...)
{
	char* destMod;
	int destModSize;
	int len;
	va_list va;

	va_start(va, fmt);
	if (*destPos >= destSize - 1)
	{
		return -1;
	}

	destMod = &dest[*destPos];
	destModSize = destSize - *destPos;
	len = _vsnprintf(destMod, destSize - *destPos, fmt, va);
	destMod[destModSize - 1] = 0;
	va_end(va);

	if (len != destModSize && len != -1)
	{
		*destPos += len;
	}
	else
	{
		*destPos = destSize - 1;
	}

	return len;
}

/*
==============
CanKeepStringPointer
==============
*/
BOOL CanKeepStringPointer(const char *string)
{
	va_info_t* info;
	char stack;

	if (string >= &stack && string < "65" + 3) //(const char *)&a65 + 3 )
	{
		return 0;
	}
	info = (va_info_t*)Sys_GetValue(THREAD_VALUE_VA);
	return string < (const char*)info || string > &info->va_string[3][1023];
}

/*
==============
I_itoa
==============
*/
char *I_itoa(int value, char *buf, int bufsize)
{
	return itoa(value, buf, bufsize);
}

/*
==============
va
==============
*/
char *va(const char *format, ...)
{
	va_info_t* info;
	char* buf;
	int len;
	int index;
	va_list list;

	va_start(list, format);
	info = (va_info_t*)Sys_GetValue(THREAD_VALUE_VA);
	index = info->index;
	info->index = (info->index + 1) % 4;
	buf = info->va_string[index];
	len = vsprintf(buf, format, list);
	buf[1023] = 0;
	va_end(list);

	if (len < 0 || len >= 1024)
	{
		buf[1023] = 0;
		Com_Error(ERR_DROP, "\x15" "Attempted to overrun string in call to va(): '%s'", buf);
	}
	return buf;
}

/*
==============
Com_InitThreadData
==============
*/
void Com_InitThreadData(int threadContext)
{
	Sys_SetValue(THREAD_VALUE_VA, &va_info[threadContext]);
	Sys_SetValue(THREAD_VALUE_COM_ERROR, g_com_error[threadContext]);
	Sys_SetValue(THREAD_VALUE_TRACE, &g_traceThreadInfo[threadContext]);

	if (threadContext == 1)
	{
		Sys_SetValue(THREAD_VALUE_CMD, &g_cmd_args[1]);
	}
	else
	{
		Sys_SetValue(THREAD_VALUE_CMD, &g_cmd_args[0]);
	}
}

/*
==============
Info_ValueForKey
==============
*/
const char *Info_ValueForKey(const char *s, const char *key)
{
	char* o;
	char* result;
	char pkey[8192];

	static char value1[3][2][8192];
	static int valueindex = 0;

	if (!s || !key)
	{
		return "";
	}

	valueindex = (valueindex + 1) % 2;
	if (*s == '\\')
	{
		s++;
	}

	while (1)
	{
		o = pkey;
		while (*s != '\\')
		{
			if (!*s)
			{
				return "";
			}

			*o++ = *s++;

			if (o - pkey >= 0x2000)
			{
				Com_Error(ERR_DROP, "\x15" "Info_ValueForKey: oversize key %d", o - pkey);
			}
		}
		*o = 0;
		s++;

		if (Sys_IsMainThread())
		{
			result = value1[0][valueindex];
		}
		else if (Sys_IsServerThread())
		{
			result = value1[2][valueindex];
		}
		else
		{
			assert(Sys_IsRenderThread());
			result = value1[1][valueindex];
		}

		o = result;
		while (*s != '\\' && *s)
		{
			*o++ = *s++;
			if (o - result >= 0x2000)
			{
				Com_Error(ERR_DROP, "\x15" "Info_ValueForKey: oversize key %d", o - result);
			}
		}
		*o = 0;

		if (!I_stricmp(key, pkey))
		{
			return result;
		}

		if (!*s)
		{
			break;
		}
		s++;
	}
	return "";
}

/*
==============
Info_NextPair
==============
*/
void Info_NextPair(const char **head, char *key, char *value)
{
	char* o;
	const char* s;

	s = *head;

	if (*s == '\\')
	{
		++s;
	}
	key[0] = 0;
	value[0] = 0;

	o = key;
	while (*s != '\\')
	{
		if (!*s)
		{
			*o = 0;
			*head = s;
			return;
		}
		*o++ = *s++;
	}

	*o = 0;
	s++;

	o = value;
	while (*s != '\\' && *s)
	{
		*o++ = *s++;
	}
	*o = 0;

	*head = s;
}

/*
==============
Info_RemoveKey
==============
*/
void Info_RemoveKey(char *s, const char *key)
{
	char* o;
	char* start;
	char pkey[1024];
	char value[1024];

	if (strlen(s) >= 0x400)
	{
		Com_Error(ERR_DROP, "\x15" "Info_RemoveKey: oversize infostring");
	}

	if (strchr(key, '\\'))
	{
		return;
	}

	while (1)
	{
		start = s;
		if (*s == '\\')
		{
			++s;
		}
		o = pkey;
		while (*s != '\\')
		{
			if (!*s)
			{
				return;
			}
			*o++ = *s++;
		}
		*o = 0;
		++s;

		o = value;
		while (*s != '\\' && *s)
		{
			if (!*s)
			{
				return;
			}
			*o++ = *s++;
		}
		*o = 0;
		if (!strcmp(key, pkey))
		{
			strcpy(start, s);  // remove this part
			return;
		}

		if (!*s)
		{
			return;
		}
	}
}

/*
==============
Info_RemoveKey_Big
==============
*/
void Info_RemoveKey_Big(char *s, const char *key)
{
	char* o;
	char* start;
	char pkey[8192];
	char value[8192];

	if (strlen(s) >= 0x4000)
	{
		Com_Error(ERR_DROP, "\x15" "Info_RemoveKey_Big: oversize infostring");
	}


	if (strchr(key, '\\'))
	{
		return;
	}

	while (1)
	{
		start = s;
		if (*s == '\\')
		{
			++s;
		}
		o = pkey;
		while (*s != '\\')
		{
			if (!*s)
			{
				return;
			}
			*o++ = *s++;
		}
		*o = 0;
		++s;

		o = value;
		while (*s != '\\' && *s)
		{
			if (!*s)
			{
				return;
			}
			*o++ = *s++;
		}
		*o = 0;

		if (!strcmp(key, pkey))
		{
			strcpy(start, s);  // remove this part
			return;
		}
		if (!*s)
		{
			return;
		}
	}
}

/*
==============
Info_Validate
==============
*/
BOOL Info_Validate(const char *s)
{
	if (strchr(s, '"'))
	{
		return 0;
	}
	return strchr(s, ';') == 0;
}

/*
==============
Info_SetValueForKey
==============
*/
void Info_SetValueForKey(char *s, const char *key, const char *value)
{
	int j;
	char c;
	char cleanValue[MAX_INFO_STRING];
	int len;
	char newi[MAX_INFO_STRING];
	int i;

	assert(value);
	if (strlen(s) >= MAX_INFO_STRING)
	{
		assertMsg("Info_SetValueForKey: oversize infostring");
		Com_Printf(CON_CHANNEL_SYSTEM, "\x15" "Info_SetValueForKey: oversize infostring");
		return;
	}

	j = 0;
	for (i = 0; i < MAX_INFO_STRING - 1; ++i)
	{
		c = value[i];
		if (!c)
		{
			break;
		}
		if (c != '\\' && c != ';' && c != '\"')
		{
			assert(j < MAX_INFO_STRING);
			cleanValue[j++] = c;
		}
	}

	assert(j < MAX_INFO_STRING);
	cleanValue[j] = 0;
	if (strchr(key, '\\'))
	{
		assertMsg(va("Can't use keys with a \\\nkey: '%s'\nvalue: '%s'", key, value));
		Com_Printf(CON_CHANNEL_SYSTEM, "Can\'t use keys with a \\\nkey: '%s'\nvalue: '%s'", key, value);
		return;
	}

	if (strchr(key, ';'))
	{
		assertMsg(va("Can't use keys with a semicolon\nkey: '%s'\nvalue: '%s'", key, value));
		Com_Printf(CON_CHANNEL_SYSTEM, "\x15" "Can\'t use keys with a semicolon\nkey: '%s'\nvalue: '%s'", key, value);
		return;
	}

	if (strchr(key, '\"'))
	{
		assertMsg(va("Can't use keys with a \"\nkey: '%s'\nvalue: '%s'", key, value));
		Com_Printf(CON_CHANNEL_SYSTEM, "\x15" "Can\'t use keys with a \"\nkey: '%s'\nvalue: '%s'", key, value);
		return;
	}

	Info_RemoveKey(s, key);
	if (!cleanValue[0])
	{
		return;
	}

	len = Com_sprintf(newi, sizeof(newi), "\\%s\\%s", key, cleanValue);
	if (len <= 0)
	{
		assertMsg("Info buffer length exceeded, not including key/value pair in response\n");
		Com_Printf(CON_CHANNEL_SYSTEM, "\x15" "Info buffer length exceeded, not including key/value pair inresponse\n");
		return;
	}

	if (strlen(newi) + strlen(s) > MAX_INFO_STRING)
	{
		assertMsg(va("Info string length exceeded\nkey: '%s'\nvalue: '%s'\nInfo string:\n%s\n", key, value, s));
		Com_Printf(CON_CHANNEL_SYSTEM,
			"\x15" "Info string length exceeded\nkey: '%s'\nvalue: '%s'\nInfo string:\n%s\n", key, value, s);
		return;
	}

	strcat(s, newi);
}

/*
==============
Info_SetValueForKey_Big
==============
*/
void Info_SetValueForKey_Big(char *s, const char *key, const char *value)
{
	int j;
	char c;
	char cleanValue[BIG_INFO_STRING];
	int len;
	char newi[BIG_INFO_STRING];
	int i;

	assert(value);
	if (strlen(s) >= BIG_INFO_STRING)
	{
		Com_Printf(CON_CHANNEL_SYSTEM, "\x15" "Info_SetValueForKey: oversize infostring");
		return;
	}

	j = 0;
	for (i = 0; i < BIG_INFO_STRING - 1; ++i)
	{
		c = value[i];
		if (!c)
		{
			break;
		}
		if (c != 92 && c != 59 && c != 34)
		{
			assert(j < BIG_INFO_STRING);
			cleanValue[j++] = c;
		}
	}

	assert(j < BIG_INFO_STRING);
	cleanValue[j] = 0;

	if (strchr(key, '\\'))
	{
		Com_Printf(CON_CHANNEL_SYSTEM, "\x15" "Can\'t use keys with a \\\nkey: '%s'\nvalue: '%s'", key, value);
		return;
	}

	if (strchr(key, ';'))
	{
		Com_Printf(CON_CHANNEL_SYSTEM, "\x15" "Can\'t use keys with a semicolon\nkey: '%s'\nvalue: '%s'", key, value);
		return;
	}

	if (strchr(key, '\"'))
	{
		Com_Printf(CON_CHANNEL_SYSTEM, "\x15" "Can\'t use keys with a \"\nkey: '%s'\nvalue: '%s'", key, value);
		return;
	}

	Info_RemoveKey_Big(s, key);
	if (!cleanValue[0])
	{
		return;
	}

	len = Com_sprintf(newi, sizeof(newi), "\\%s\\%s", key, cleanValue);
	if (len <= 0)
	{
		Com_Printf(CON_CHANNEL_SYSTEM,
			"\x15" "Info buffer length exceeded, not including key/value pair in response\n");
		return;
	}

	if (strlen(newi) + strlen(s) > BIG_INFO_STRING)
	{
		Com_Printf(CON_CHANNEL_SYSTEM,
			"\x15" "Big info string length exceeded\nkey: '%s'\nvalue: '%s'\nInfo string:\n%s\n",
			key, value, s);
		return;
	}

	strcat(s, newi);
}

/*
==============
KeyValueToField
==============
*/
int KeyValueToField(byte* pStruct, cspField_t* pField, const char* pszKeyValue, const int iMaxFieldTypes, int (*parseSpecialFieldType)(byte*, const char*, const int, const int), void (*parseStrcpy)(byte*, const char*))
{
	char presetName[256];
	char dest[8192];
	XModel* xmodel;

	if (pField->iFieldType < 18)
	{
		switch (pField->iFieldType)
		{
		case 0:
			parseStrcpy(&pStruct[pField->iOffset], pszKeyValue);
			return 1;
		case 1:
			I_strncpyz((char*)&pStruct[pField->iOffset], pszKeyValue, 1024);
			return 1;
		case 2:
			I_strncpyz((char*)&pStruct[pField->iOffset], pszKeyValue, 64);
			return 1;
		case 3:
			I_strncpyz((char*)&pStruct[pField->iOffset], pszKeyValue, 256);
			return 1;
		case 4:
			*(unsigned int*)&pStruct[pField->iOffset] = atoi(pszKeyValue);
			return 1;
		case 5:
			pStruct[pField->iOffset] = I_atoui(pszKeyValue) != 0;
			return 1;
		case 6:
			pStruct[pField->iOffset] = atoi(pszKeyValue) != 0;
			return 1;
		case 7:
			pStruct[pField->iOffset] = atoi(pszKeyValue) != 0;
			return 1;
		case 8:
			*(float*)&pStruct[pField->iOffset] = atof(pszKeyValue);
			return 1;
		case 9:
			*(float *)&pStruct[pField->iOffset] = (atof(pszKeyValue) * 1000.0);
			break;
		case 0xB:
		case 0xC:
		case 0xA:
		case 0xE:
			I_strncpyz(presetName, pszKeyValue, 245);
			*(PhysPreset**)&pStruct[pField->iOffset] = PhysPreset_Register(presetName);
			break;
		case 0xF:
			*(unsigned short*)&pStruct[pField->iOffset] = SL_GetLowercaseString(pszKeyValue, 0);
			break;
		case 0x10:
			I_strncpyz(dest, pszKeyValue, 0x2000);
			*(TracerDef**)&pStruct[pField->iOffset] = Tracer_Register(dest);
			break;
		case 0x11:
			*(int*)&pStruct[pField->iOffset] = SND_HashName(pszKeyValue);
			break;
		}
		return 1;
	}

	if (iMaxFieldTypes > 0 && pField->iFieldType < iMaxFieldTypes)
	{
		assert(parseSpecialFieldType != NULL);
		if (!parseSpecialFieldType(pStruct, pszKeyValue, pField->iFieldType, pField->iOffset))
		{
			return 0;
		}
		return 1;
	}

	assertMsg(va("Bad field type %i\n", pField->iFieldType));
	Com_Error(ERR_DROP, "\x15" "Bad field type %i\n", pField->iFieldType);

	return 0;
}

/*
==============
ParseConfigStringToStruct
==============
*/
BOOL ParseConfigStringToStruct(byte* pStruct, cspField_t* pFieldList, const int iNumFields, const char* pszBuffer, const int iMaxFieldTypes, int (*parseSpecialFieldType)(byte*, const char*, const int, const int), void (*parseStrCpy)(byte*, const char*))
{
	const char* pszKeyValue;
	unsigned char error;
	cspField_t* pField;
	int iField;

	error = 0;
	iField = 0;
	pField = pFieldList;
	while (iField < iNumFields)
	{
		pszKeyValue = Info_ValueForKey(pszBuffer, pField->szName);
		if (*pszKeyValue)
		{
			error |= KeyValueToField(pStruct, pField, pszKeyValue, iMaxFieldTypes, parseSpecialFieldType, parseStrCpy) == 0;
		}
		++iField;
		++pField;
	}
	return iField == iNumFields && !error;
}

/*
==============
ParseConfigStringToStructMerged
==============
*/
BOOL ParseConfigStringToStructMerged(unsigned __int8 *pStruct, const cspField_t *pFieldList, const int iNumFields, const char *mergedName, const char **pszBuffer, const char **sourceName, char *pszMergedBuffer, const int iMaxFieldTypes, int (*parseSpecialFieldType)(unsigned __int8 *, const char *, const int, const int), void (*parseStrCpy)(unsigned __int8 *, const char *), int (*parseMergeSpecialCase)(const char *, char **, char *, int))
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GetLeanFraction
==============
*/
long double GetLeanFraction(const float fFrac)
{
	return (2.0f - fabs(fFrac)) * fFrac;
}

/*
==============
UnGetLeanFraction
==============
*/
long double UnGetLeanFraction(const float fFrac)
{
	assert(fFrac >= 0);
	assert(fFrac <= 1.f);

	return 1.0f - sqrtf(1.0f - fFrac);
}

/*
==============
AddLeanToPosition
==============
*/
void AddLeanToPosition(vec3_t *position, const float fViewYaw, const float fLeanFrac, const float fViewRoll, const float fLeanDist)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
OrientationConcatenate
==============
*/
void OrientationConcatenate(const orientation_t *orFirst, const orientation_t *orSecond, orientation_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
OrientationInvert
==============
*/
void OrientationInvert(const orientation_t *orient, orientation_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_IsLegacyXModelName
==============
*/
BOOL Com_IsLegacyXModelName(const char *name)
{
	return !I_strnicmp(name, "xmodel", 6) && (name[6] == '/' || name[6] == '\\');
}

/*
==============
Com_DefaultExtension
==============
*/
void Com_DefaultExtension(char *path, int maxSize, const char *extension)
{
	char oldPath[64];
	char* src;

	src = path + strlen(path) - 1;

	while (*src != '/' && src != path)
	{
		if (*src == '.')
		{
			return;
		}
		src--;
	}

	I_strncpyz(oldPath, path, sizeof(oldPath));
	Com_sprintf(path, maxSize, "%s%s", oldPath, extension);
}

/*
==============
CMD_GetAnalogButtonValue
==============
*/
double CMD_GetAnalogButtonValue(usercmd_s *cmd, int whichBit)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

