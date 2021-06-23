#ifndef Q_SHARED_H
#define Q_SHARED_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct cspField_t
{
	const char* szName;
	int iOffset;
	int iFieldType;
} cspField_t;

typedef struct va_info_t
{
	char va_string[4][1024];
	int index;
} va_info_t;

typedef struct TraceCheckCount
{
	unsigned __int16 global;
	unsigned __int16* partitions;
	unsigned __int16* brushes;
} TraceCheckCount;

typedef struct TraceThreadInfo
{
	TraceCheckCount checkcount;
	struct cbrush_t* box_brush;
	struct cmodel_t* box_model;
	struct PhysGeomList** geoms;
} TraceThreadInfo;

short(__cdecl* _BigShort)(__int16);
int(__cdecl* _BigLong)(int);
unsigned __int64(__cdecl* _BigLong64)(unsigned __int64);
unsigned __int64(__cdecl* _LittleLong64)(unsigned __int64);
__int16(__cdecl* _LittleShort)(__int16);
int(__cdecl* _LittleLong)(int);
float(__cdecl* _LittleFloatRead)(int);
int(__cdecl* _LittleFloatWrite)(float);

extern va_info_t va_info[17];
extern int g_com_error[17][16];
extern TraceThreadInfo g_traceThreadInfo[17];
extern int unknownThreadValue;
extern struct CmdArgs g_cmd_args[2];

// the game guarantees that no string from the network will ever
// exceed MAX_STRING_CHARS
#define	MAX_STRING_CHARS	1024	// max length of a string passed to Cmd_TokenizeString
#define	MAX_STRING_TOKENS	1024	// max tokens resulting from Cmd_TokenizeString
#define	MAX_TOKEN_CHARS		1024	// max length of an individual token

#define	MAX_INFO_STRING		1024
#define	MAX_INFO_KEY		  1024
#define	MAX_INFO_VALUE		1024

#define	BIG_INFO_STRING		8192  // used for system info key only
#define	BIG_INFO_KEY		  8192
#define	BIG_INFO_VALUE		8192

char value1[3][2][BIG_INFO_KEY];

inline void Com_Memcpy(void* dest, const void* src, int count) {
	memcpy(dest, src, count);
}

//int LongNoSwap(int);
int FloatWriteNoSwap(float);
unsigned char ColorIndex(unsigned char);
const char* Com_GetExtensionSubString(const char* filename);
void Com_StripExtension(const char*, char*);
short BigShort(short);
int BigLongNoSwap(int);
int BigLong(int);
int LittleLongNoSwap(int);
unsigned __int64 BigLong64(unsigned __int64);
short LittleShort(short);
int LittleLong(int);
int LittleFloatWrite(float);
short ShortSwap(short);
short ShortNoSwap(short);
int LongSwap(int);
unsigned __int64 Long64Swap(unsigned __int64);
unsigned __int64 Long64NoSwap(unsigned __int64);
float FloatReadNoSwap(int);
int FloatWriteNoSwap(float);
void Swap_Init(void);
unsigned int I_atoui(char const*);
__int64 I_atoi64(char const*);
bool I_islower(int);
bool I_isupper(int);
bool I_isdigit(int);
bool I_isalnum(int);
bool I_isforfilename(int);
void I_strncpyz(char* dest, char const* src, int destsize);
int I_strnicmp(char const* s0, char const* s1, int n);
int I_strncmp(char const* s0, char const* s1, int n);
char const* I_stristr(char const* s0, char const* substr);
int I_stricmp(const char* s0, const char* s1);
int I_strcmp(char const*, char const*);
int I_stricmpwild(char const*, char const*);
char* I_strlwr(char*);
char* I_strupr(char*);
bool I_iscsym(int);
void I_strncat(char*, int, char const*);
int I_DrawStrlen(char const*);
bool I_IsSpecialToken(char const*);
int I_IsSpecialTokenRecursive(char const*);
char* I_CleanChat(char*);
char* I_CleanStr(char*);
char I_CleanChar(char);
int Com_sprintf(char* dest, int size, const char* fmt, ...);
int Com_sprintfPos(char*, int, int*, char const*, ...);
bool CanKeepStringPointer(char const*);
char* I_itoa(int, char*, int);
char* va(char const* format, ...);
void Sys_SetValue(int valueIndex, void* data);
void Com_InitThreadData(int);
char const* Info_ValueForKey(char const*, char const*);
void Info_NextPair(char const**, char*, char*);
void Info_RemoveKey(char*, char const*);
void Info_RemoveKey_Big(char*, char const*);
bool Info_Validate(char const*);
void Info_SetValueForKey(char*, char const*, char const*);
void Info_SetValueForKey_Big(char*, char const*, char const*);
int KeyValueToField(unsigned char*, cspField_t const*, const int, void(*)(unsigned char*, const char*), const char*, int(*)(unsigned char*, const char*, const int, const int));
int ParseConfigStringToStruct(unsigned char*, cspField_t const*, int, char const*, const int, int (*)(unsigned char*, char const*, int, int), void (*)(unsigned char*, char const*));
int ParseConfigStringToStructMerged(unsigned char*, const cspField_t*, const int, const char*, const char**, const char**, char*, const int , int(*)(unsigned char*, const char*, const int,const int), void(*)(unsigned char*, const char*), int(*)(const char*, char**, char*, int));
float GetLeanFraction(float);
float UnGetLeanFraction(float);
void AddLeanToPosition(union vec3_t*, float, float, float, float);
void OrientationConcatenate(struct orientation_t const*, struct orientation_t const*, struct orientation_t*);
void OrientationInvert(struct orientation_t const*, struct orientation_t*);
bool Com_IsLegacyXModelName(char const*);
void Com_DefaultExtension(char*, int, char const*);
float CMD_GetAnalogButtonValue(struct usercmd_s*, int);

#endif // Q_SHARED_H