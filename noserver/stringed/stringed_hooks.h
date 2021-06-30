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

#ifndef STRINGED_HOOKS_H
#define STRINGED_HOOKS_H

void SEH_UpdateCurrentLanguage(void);
int SEH_GetCurrentLanguage(void);
void SEH_InitLanguage(void);
int SEH_VerifyLanguageSelection(int);
void SEH_Init_StringEd(void);
void SEH_Shutdown_StringEd(void);
char const* SE_GetString_FastFile(char const*);
char const* SEH_StringEd_GetString(char const*);
char const* SEH_SafeTranslateString(char const*);
int SEH_GetLocalizedTokenReference(char*, char const*, char const*, enum msgLocErrType_t);
void SEH_ParseDirective(char const*, char* const, char* const);
void SEH_GetBindingForDirective(enum LocalClientNum_t, char const*, char* const);
bool SEH_ReplaceDirective(enum LocalClientNum_t, unsigned int*, unsigned int*, char* const, unsigned int);
int SEH_ReplaceDirectiveInStringWithBinding(enum LocalClientNum_t, char const*, char*);
char const* SEH_LocalizeTextMessage(char const*, char const*, enum msgLocErrType_t);
unsigned int SEH_DecodeLetter(unsigned char, unsigned char, unsigned char, int*);
unsigned int SEH_ReadCharFromString(char const**);
int SEH_PrintStrlen(char const*);
char const* SEH_GetLanguageName(int);
char const* SEH_GetLanguageNameAbbr(int);
int SEH_StringEd_SetLanguageStrings(int);
void SEH_TranslateMessage(enum LocalClientNum_t, char const*, char const*, char*, unsigned int);
void SEH_UpdateLanguageInfo(void);

#endif