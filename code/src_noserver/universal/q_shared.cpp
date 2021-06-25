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

#include "q_shared.h"

#include "com_vector.h"
#include "com_math_anglevectors.h"

unsigned char ColorIndex(unsigned char c)
{
	if ((c - 48) >= 0xA)
		return 7;
	else
		return (c - 48);
}

const char* Com_GetExtensionSubString(const char* filename)
{
	char curLetter;

	if (!*filename)
		return filename;
    do
    {
        if (curLetter == 46)
        {
            return filename;
        }
        else if (curLetter == 47 || curLetter == 92)
        {
            return 0;
        }
        curLetter = *++filename;
    }   while (curLetter);
    return filename;
}

void Com_StripExtension(const char* in, char* out)
{
    const char* subStr = Com_GetExtensionSubString(in);

    if (in == subStr)
        *out = 0;
    else {
        do
            *out++ = *in++;
        while (in != subStr);
        *out = 0;
    }
}

short BigShort(short l)
{
    return _BigShort(l);
}

int BigLongNoSwap(int l)
{
    return l;
}

int BigLong(int l)
{
    return _BigLong(l);
}

int LittleLongNoSwap(int l)
{
    return l;
}

unsigned __int64 BigLong64(unsigned __int64 l)
{
    return _BigLong64(l);
}

short LittleShort(short l)
{
    return _LittleShort(l);
}

int LittleLong(int l)
{
    return _LittleLong(l);
}

int LittleFloatWrite(float l)
{
    return _LittleFloatWrite(l);
}

short ShortSwap(short l)
{
    return (l << 8) + l;
}

short ShortNoSwap(short l)
{
    return l;
}

int LongSwap(int l)
{
    return l + ((l + (((l << 8) + l) << 8)) << 8);
}

unsigned __int64 Long64Swap(unsigned __int64 ll)
{
    return ((ll
        + ((ll + ((ll + ((ll + ((ll + (((ll << 8) + ll) << 8)) << 8)) << 8)) << 8)) << 8)) << 8)
        + ll;
}

unsigned __int64 Long64NoSwap(unsigned __int64 ll)
{
    return ll;
}

float FloatReadNoSwap(int n)
{
    return *&n;
}

int FloatWriteNoSwap(float f)
{
    return f;
}

void Swap_Init(void)
{
    _LittleFloatRead = FloatReadNoSwap;
    _LittleFloatWrite = FloatWriteNoSwap;
    /*  TODO
    if (Com_IsClientConsole())
    {
        BigShort = ShortSwap;
        LittleShort = ShortNoSwap;
        BigLong = LongSwap;
        LittleLong = Ragdoll_HandleBody;
        LittleLong64 = Long64NoSwap;
        BigLong64 = Long64Swap;
    }
    else
    {
        BigShort = ShortNoSwap;
        LittleShort = ShortNoSwap;
        BigLong = Ragdoll_HandleBody;
        LittleLong = Ragdoll_HandleBody;
        LittleLong64 = Long64NoSwap;
        BigLong64 = Long64NoSwap;
    }
    */
    _BigShort = ShortNoSwap;
    _LittleShort = ShortNoSwap;
    _BigLong = BigLongNoSwap;
    _LittleLong = LittleLongNoSwap;
    _LittleLong64 = Long64NoSwap;
    _BigLong64 = Long64NoSwap;
}

unsigned int I_atoui(char const* str)
{
    int strLen; // edi
    unsigned int value; // eax
    int i; // edx
    char c; // cl
    unsigned int chck; // esi

    if (!str || !*str)
        return 0;
    strLen = strlen(str);
    value = 0;
    i = 0;
    if (strLen > 0)
    {
        while (1)
        {
            c = str[i];
            if (c < '0' || c > '9')
                break;
            chck = value;
            value = c + 10 * value - 48;
            if (chck > value)
                return -1;
            if (++i >= strLen)
                return value;
        }
        value = 0;
    }
    return value;
}

__int64 I_atoi64(char const* str)
{
    return _atoi64(str);
}

bool I_islower(int c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    return false;
}

bool I_isupper(int c)
{
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}

bool I_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

bool I_isalnum(int c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
        return true;
    return false;
}

bool I_isforfilename(int c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || c == '_' || c == '-')
        return true;
    return false;
}

void I_strncpyz(char* dest, char const* src, int destsize)
{
    strncpy(dest, src, destsize - 1);
    dest[destsize - 1] = 0;
}

int I_strnicmp(char const* s0, char const* s1, int n)
{
    return strnicmp(s0, s1, n);
}

int I_strncmp(char const* s0, char const* s1, int n)
{
    return strncmp(s0, s1, n);
}

char const* I_stristr(char const* s0, char const* substr)
{
    int i;

    while (*s0) {
        for (i = 0; substr[i] && s0[i]; i++) {
            if (tolower(substr[i]) != tolower(s0[i])) break;
        }
        if (!substr[i]) return s0;
        s0++;
    }
    return NULL;
}

int I_stricmp(const char* s0, const char* s1)
{
    return I_strnicmp(s0, s1, 0x7FFFFFFF);
}

int I_strcmp(char const* s0, char const* s1)
{
    return I_strncmp(s0, s1, 0x7FFFFFFF);
}

int I_stricmpwild(char const* wild, char const* s)
{
    char charWild;
    int delta;
    char charRef;

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
    }   while (charWild);
    return 0;
}

char* I_strlwr(char* s)
{
    char* result;
    char* i;

    result = s;
    for (i = s; *i; ++i)
    {
        if ((*i - 65) <= 25)
            *i += 32;
    }
    return result;
}

char* I_strupr(char* s)
{
    char* result;
    char* i;

    result = s;
    for (i = s; *i; ++i)
    {
        if ((*i - 97) <= 25)
            *i -= 32;
    }
    return result;
}

bool I_iscsym(int c)
{
    if ((c - 97) <= 0x19 || (c - 65) <= 0x19 || (c - 48) <= 9)
        return true;
    else
        return c == 95;
}

void I_strncat(char* dest, int size, char const* src)
{
    int destLen = strlen(dest);
    if (destLen >= size) {
        //Com_Error(ERR_FATAL, "I_strncat: already overflowed");
    }
    I_strncpyz(&dest[destLen], src, size - destLen);
}

int I_DrawStrlen(char const* str)
{
    int result; // eax
    char nextChar; // cl

    result = 0;
    while (*str)
    {
        if (*str == 94 && (nextChar = str[1]) != 0 && nextChar != 94 && nextChar >= 48 && nextChar <= 57)
        {
            str += 2;
        }
        else
        {
            ++result;
            ++str;
        }
    }
    return result;
}

bool I_IsSpecialToken(char const* buf)
{
    return buf && (*buf == 94 && buf[1] || *buf == 91 && buf[1] == 123);
}

int I_IsSpecialTokenRecursive(char const* buf)
{
    char v1; // cl
    int result; // eax
    int v3; // eax

    if (!buf)
        return 0;
    if (*buf == '^' && buf[1] || *buf == '[' && buf[1] == '{')
        return 2;
    if ((*buf == '^' || *buf == '[') && (v3 = I_IsSpecialTokenRecursive(buf + 1)) != 0)
        return v3 + 1;
    else
        return 0;
}

char* I_CleanChat(char* string)
{
    char* cleanString; // eax
    char v2; // bl
    int v3; // edi

    do
    {
        cleanString = string;
        v2 = *string;
        v3 = 0;
        if (*string)
        {
            do
            {
                if (*string == '^' && string[1] || *string == '[' && string[1] == '{')
                {
                    ++string;
                    v3 = 1;
                }
                else if ((v2 - ' ') <= '^')
                {
                    *string++ = v2;
                }
                v2 = *++string;
            }       while (v2);
            cleanString = string;
        }
        *string = 0;
    }   while (v3);
    return cleanString;
}

char* I_CleanStr(char* string)
{
    char* clearStr; // eax
    char v2; // dl
    int v3; // edi
    char* i; // esi
    char v6; // bl

    clearStr = string;
    do
    {
        v2 = *string;
        v3 = 0;
        for (i = string; v2; ++string)
        {
            if (*string == 94 && (v6 = string[1]) != 0 && v6 != 94 && v6 >= 48 && v6 <= 57)
            {
                ++string;
                v3 = 1;
            }
            else if ((v2 - 32) <= 0x5Eu)
            {
                *i++ = v2;
            }
            v2 = string[1];
        }
        *i = 0;
    }   while (v3);
    return clearStr;
}

char I_CleanChar(char character)
{
    char result; // al

    result = character;
    if (character == 0x92)
        result = 0x27;
    return result;
}

int Com_sprintf(char* dest, int size, const char* fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    int result = _vsnprintf(dest, size, fmt, ap);
    dest[size - 1] = 0;
    return result;
}

int Com_sprintfPos(char* dest, int destSize, int* destPos, char const* fmt, ...)
{
    int v4; // eax
    int result; // eax
    char* v6; // edi
    int v7; // esi
    va_list ap; // [esp+20h] [ebp+18h] BYREF

    va_start(ap, fmt);
    v4 = *destPos;
    if (*destPos >= destSize - 1)
        return -1;
    v6 = &dest[v4];
    v7 = destSize - v4;
    result = _vsnprintf(&dest[v4], destSize - v4, fmt, ap);
    v6[v7 - 1] = 0;
    if (result == v7 || result == -1)
        *destPos = destSize - 1;
    else
        *destPos += result;
    return result;
}

bool CanKeepStringPointer(char const* string)
{
    return 0;
}

char* I_itoa(int value, char* buf, int bufSize)
{
    return itoa(value, buf, bufSize);
}

char* va(char const* format, ...)
{
    uintptr_t* v1; // eax
    int v2; // ecx
    char* v3; // esi
    int v4; // eax
    va_list ap; // [esp+10h] [ebp+Ch] BYREF

    va_start(ap, format);
    v1 = Sys_GetValue(1);
    v2 = v1[1024];
    v3 = (char*)&v1[256 * v2];
    v1[1024] = (v2 + 1) % 4;
    v4 = _vsnprintf(v3, 0x400u, format, ap);
    v3[1023] = 0;
    if (v4 < 0 || v4 >= 1024)
    {
        v3[1023] = 0;
        //Com_Error(ERR_DROP, "Attempted to overrun string in call to va(): ", v3);
    }
    return v3;
}

void Com_InitThreadData(int threadContext)
{
    Sys_SetValue(1, &va_info[threadContext]);
    Sys_SetValue(2, g_com_error[threadContext]);
    Sys_SetValue(3, &g_traceThreadInfo[threadContext]);
    if (threadContext == 1)
        Sys_SetValue(4, &unknownThreadValue);
    else
        Sys_SetValue(4, g_cmd_args);
}

char const* Info_ValueForKey(char const* s, char const* key)
{
    char	pkey[BIG_INFO_KEY];
    static	char value[2][BIG_INFO_VALUE];	// use two buffers so compares
                                            // work without stomping on each other
    static	int	valueindex = 0;
    char* o;

    if (!s || !key) {
        return "";
    }

    if (strlen(s) >= BIG_INFO_STRING) {
        //Com_Error(ERR_DROP, "Info_ValueForKey: oversize infostring");
    }

    valueindex ^= 1;
    if (*s == '\\')
        s++;
    while (1)
    {
        o = pkey;
        while (*s != '\\')
        {
            if (!*s)
                return "";
            *o++ = *s++;
        }
        *o = 0;
        s++;

        if (Sys_IsServerThread())
            o = value1[2][valueindex];
        else
            o = value1[1][valueindex];

        while (*s != '\\' && *s)
        {
            *o++ = *s++;
        }
        *o = 0;

        if (!I_stricmp(key, pkey))
            return o;

        if (!*s)
            break;
        s++;
    }

    return "";
}

void Info_NextPair(char const** head, char* key, char* value)
{
    char* o;
    const char* s;

    s = *head;

    if (*s == '\\') {
        s++;
    }
    key[0] = 0;
    value[0] = 0;

    o = key;
    while (*s != '\\') {
        if (!*s) {
            *o = 0;
            *head = s;
            return;
        }
        *o++ = *s++;
    }
    *o = 0;
    s++;

    o = value;
    while (*s != '\\' && *s) {
        *o++ = *s++;
    }
    *o = 0;

    *head = s;
}

void Info_RemoveKey(char* s, char const* key)
{
    char* start;
    char	pkey[MAX_INFO_KEY];
    char	value[MAX_INFO_VALUE];
    char* o;

    if (strlen(s) >= MAX_INFO_STRING) {
        //Com_Error(ERR_DROP, "Info_RemoveKey: oversize infostring");
    }

    if (strchr(key, '\\')) {
        return;
    }

    while (1)
    {
        start = s;
        if (*s == '\\')
            s++;
        o = pkey;
        while (*s != '\\')
        {
            if (!*s)
                return;
            *o++ = *s++;
        }
        *o = 0;
        s++;

        o = value;
        while (*s != '\\' && *s)
        {
            if (!*s)
                return;
            *o++ = *s++;
        }
        *o = 0;

        if (!strcmp(key, pkey))
        {
            strcpy(start, s);	// remove this part
            return;
        }

        if (!*s)
            return;
    }
}

void Info_RemoveKey_Big(char* s, char const* key)
{
    char* start;
    char	pkey[BIG_INFO_KEY];
    char	value[BIG_INFO_VALUE];
    char* o;

    if (strlen(s) >= BIG_INFO_STRING) {
        //Com_Error(ERR_DROP, "Info_RemoveKey_Big: oversize infostring");
    }

    if (strchr(key, '\\')) {
        return;
    }

    while (1)
    {
        start = s;
        if (*s == '\\')
            s++;
        o = pkey;
        while (*s != '\\')
        {
            if (!*s)
                return;
            *o++ = *s++;
        }
        *o = 0;
        s++;

        o = value;
        while (*s != '\\' && *s)
        {
            if (!*s)
                return;
            *o++ = *s++;
        }
        *o = 0;

        if (!strcmp(key, pkey))
        {
            strcpy(start, s);	// remove this part
            return;
        }

        if (!*s)
            return;
    }
}

bool Info_Validate(char const* s)
{
    if (strchr(s, '\"')) {
        return false;
    }
    if (strchr(s, ';')) {
        return false;
    }
    return true;
}

void Info_SetValueForKey(char* s, char const* key, char const* value)
{
    char	newi[MAX_INFO_STRING];

    if (strlen(s) >= MAX_INFO_STRING) {
        //Com_Error(ERR_DROP, "Info_SetValueForKey: oversize infostring");
    }

    if (strchr(key, '\\') || strchr(value, '\\'))
    {
        //Com_Printf("Can't use keys or values with a \\\n");
        return;
    }

    if (strchr(key, ';') || strchr(value, ';'))
    {
        //Com_Printf("Can't use keys or values with a semicolon\n");
        return;
    }

    if (strchr(key, '\"') || strchr(value, '\"'))
    {
        //Com_Printf("Can't use keys or values with a \"\n");
        return;
    }

    Info_RemoveKey(s, key);
    if (!value || !strlen(value))
        return;

    Com_sprintf(newi, sizeof(newi), "\\%s\\%s", key, value);

    if (strlen(newi) + strlen(s) > MAX_INFO_STRING)
    {
        //Com_Printf("Info string length exceeded\n");
        return;
    }

    strcat(newi, s);
    strcpy(s, newi);
}

void Info_SetValueForKey_Big(char* s, char const* key, char const* value)
{
    char	newi[BIG_INFO_STRING];

    if (strlen(s) >= BIG_INFO_STRING) {
        //Com_Error(ERR_DROP, "Info_SetValueForKey: oversize infostring");
    }

    if (strchr(key, '\\') || strchr(value, '\\'))
    {
        //Com_Printf("Can't use keys or values with a \\\n");
        return;
    }

    if (strchr(key, ';') || strchr(value, ';'))
    {
        //Com_Printf("Can't use keys or values with a semicolon\n");
        return;
    }

    if (strchr(key, '\"') || strchr(value, '\"'))
    {
        //Com_Printf("Can't use keys or values with a \"\n");
        return;
    }

    Info_RemoveKey_Big(s, key);
    if (!value || !strlen(value))
        return;

    Com_sprintf(newi, sizeof(newi), "\\%s\\%s", key, value);

    if (strlen(newi) + strlen(s) > BIG_INFO_STRING)
    {
        //Com_Printf("BIG Info string length exceeded\n");
        return;
    }

    strcat(s, newi);
}

int KeyValueToField(unsigned char*, cspField_t const*, const int, void(*)(unsigned char*, const char*), const char*, int(*)(unsigned char*, const char*, const int, const int))
{
    return 0;
}

int ParseConfigStringToStruct(unsigned char* pStruct, const cspField_t* pFieldList, int iNumFields, char const* pszBuffer, const int iMaxFieldTypes, int(*parseSpecialFieldType)(unsigned char*, char const*, int, int), void(*parseStrCpy)(unsigned char*, char const*))
{
    char v7; // bl
    bool v9; // zf
    const char* v10; // eax
    int m_iNumFields; // [esp+14h] [ebp+Ch]

    v7 = 0;
    v9 = iNumFields == 0;
    if (iNumFields > 0)
    {
        m_iNumFields = iNumFields;
        do
        {
            v10 = Info_ValueForKey(pszBuffer, pFieldList->szName);
            if (*v10)
                v7 |= KeyValueToField(pStruct, pFieldList, iMaxFieldTypes, parseStrCpy, v10, parseSpecialFieldType) == 0;
            ++pFieldList;
            --m_iNumFields;
        }     while (m_iNumFields);
        v9 = v7 == 0;
    }
    return v9;
}

int ParseConfigStringToStructMerged(unsigned char* pStruct, const cspField_t* pFieldList, const int iNumFields, const char* mergedName, const char** pszBuffer, const char** sourceName, char* pszMergedBuffer, const int iMaxFieldTypes, int(* parseSpecialFieldType)(unsigned char*, const char*, const int, const int), void(* parseStrCpy)(unsigned char*, const char*), int(* parseMergeSpecialCase)(const char*, char**, char*, int))
{
    return 0;
}

float GetLeanFraction(float fFrac)
{
    return fFrac * (2.0 - fabs(fFrac));
}

float UnGetLeanFraction(float fFrac)
{
    if (fFrac < 1.0)
        fFrac = fFrac - 0.80000001;
    if (fFrac > 0.0)
        return 1.0 - sqrt(1.0 - fFrac);
    else
        return 0.0;
}

void AddLeanToPosition(vec3_t* position, float fViewYaw, float fLeanFrac, float fViewRoll, float fLeanDist)
{
    float fLean; // [esp+0h] [ebp-20h]
    vec3_t vRight; // [esp+4h] [ebp-1Ch] BYREF
    vec3_t vAng; // [esp+10h] [ebp-10h] BYREF

    if (fLeanFrac != 0.0)
    {
        fLean = (2.0 - fabs(fLeanFrac)) * fLeanFrac;
        vAng.x = 0.0;
        vAng.y = fViewYaw;
        vAng.z = fLean * fViewRoll;
        AngleVectors(&vAng, 0, &vRight, 0);
        position->x = (vRight.x * (fLean * fLeanDist)) + position->x;
        position->y = (vRight.y * (fLean * fLeanDist)) + position->y;
        position->z = (vRight.z * (fLean * fLeanDist)) + position->z;
    }
}

void OrientationConcatenate(orientation_t const* orFirst, orientation_t const* orSecond, orientation_t* out)
{
    out->axis[0].x = ((orSecond->axis[1].x * orFirst->axis[0].y) + (orFirst->axis[0].x * orSecond->axis[0].x))
        + (orSecond->axis[2].x * orFirst->axis[0].z);
    out->axis[0].y = ((orFirst->axis[0].x * orSecond->axis[0].y) + (orFirst->axis[0].y * orSecond->axis[1].y))
        + (orSecond->axis[2].y * orFirst->axis[0].z);
    out->axis[0].z = ((orFirst->axis[0].x * orSecond->axis[0].z) + (orFirst->axis[0].y * orSecond->axis[1].z))
        + (orSecond->axis[2].z * orFirst->axis[0].z);
    out->axis[1].x = ((orFirst->axis[1].y * orSecond->axis[1].x) + (orSecond->axis[0].x * orFirst->axis[1].x))
        + (orFirst->axis[1].z * orSecond->axis[2].x);
    out->axis[1].y = ((orFirst->axis[1].y * orSecond->axis[1].y) + (orSecond->axis[0].y * orFirst->axis[1].x))
        + (orFirst->axis[1].z * orSecond->axis[2].y);
    out->axis[1].z = ((orFirst->axis[1].y * orSecond->axis[1].z) + (orSecond->axis[0].z * orFirst->axis[1].x))
        + (orFirst->axis[1].z * orSecond->axis[2].z);
    out->axis[2].x = ((orSecond->axis[0].x * orFirst->axis[2].x) + (orSecond->axis[1].x * orFirst->axis[2].y))
        + (orFirst->axis[2].z * orSecond->axis[2].x);
    out->axis[2].y = ((orFirst->axis[2].y * orSecond->axis[1].y) + (orSecond->axis[0].y * orFirst->axis[2].x))
        + (orSecond->axis[2].y * orFirst->axis[2].z);
    out->axis[2].z = ((orFirst->axis[2].y * orSecond->axis[1].z) + (orSecond->axis[0].z * orFirst->axis[2].x))
        + (orSecond->axis[2].z * orFirst->axis[2].z);
    out->origin.x = (((orFirst->origin.x * orSecond->axis[0].x) + orSecond->origin.x)
        + (orSecond->axis[1].x * orFirst->origin.y))
        + (orSecond->axis[2].x * orFirst->origin.z);
    out->origin.y = (((orFirst->origin.x * orSecond->axis[0].y) + orSecond->origin.y)
        + (orSecond->axis[1].y * orFirst->origin.y))
        + (orSecond->axis[2].y * orFirst->origin.z);
    out->origin.z = (((orFirst->origin.x * orSecond->axis[0].z) + orSecond->origin.z)
        + (orSecond->axis[1].z * orFirst->origin.y))
        + (orSecond->axis[2].z * orFirst->origin.z);
}

void OrientationInvert(orientation_t const* orient, orientation_t* out)
{
    out->axis[0].x = orient->axis[0].x;
    out->axis[0].y = orient->axis[1].x;
    out->axis[0].z = orient->axis[2].x;
    out->axis[1].x = orient->axis[0].y;
    out->axis[1].y = orient->axis[1].y;
    out->axis[1].z = orient->axis[2].y;
    out->axis[2].x = orient->axis[0].z;
    out->axis[2].y = orient->axis[1].z;
    out->axis[2].z = orient->axis[2].z;
    out->origin.x = ((out->axis[0].x * (0.0 - orient->origin.x)) + ((0.0 - orient->origin.y) * out->axis[1].x)) + (out->axis[2].x * (0.0 - orient->origin.z));
    out->origin.y = ((out->axis[0].y * (0.0 - orient->origin.x)) + (out->axis[1].y * (0.0 - orient->origin.y))) + ((0.0 - orient->origin.z) * out->axis[2].y);
    out->origin.z = ((out->axis[0].z * (0.0 - orient->origin.x)) + (out->axis[1].z * (0.0 - orient->origin.y))) + (out->axis[2].z * (0.0 - orient->origin.z));
}

bool Com_IsLegacyXModelName(char const* name)
{
    char cha;

    if (!I_strnicmp(name, "xmodel", 6))
    {
        cha = name[6];
        if (cha == '/' || cha == '\\')
            return true;
    }
    return false;
}

void Com_DefaultExtension(char* path, int maxSize, char const* extension)
{
    unsigned int pathLen;
    char lastChar;
    char* i;
    char oldPath[64];

    pathLen = strlen(path);
    lastChar = path[pathLen - 1];
    for (i = &path[pathLen - 1]; lastChar != '/'; lastChar = *--i)
    {
        if (i == path)
            break;
        if (lastChar == '.')
            return;
    }
    I_strncpyz(oldPath, path, 64);
    Com_sprintf(path, maxSize, "%s%s", oldPath, extension);
}

float CMD_GetAnalogButtonValue(usercmd_s* cmd, int whichBit)
{
    return 0.0f;
}
