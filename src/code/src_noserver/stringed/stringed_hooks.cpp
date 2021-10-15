#include "types.h"
#include "vars.h"
#include <stringed/stringed_public.h>
#include <qcommon/qcommon_public.h>
#include <database/database_public.h>
#include <ui/ui_public.h>
#include <win32/win32_public.h>

int g_currentAsian;

languageInfo_t g_languages[13] =
{
		{ "english", "en_", 0 },
		{ "french", "fr_", 0 },
		{ "frenchcan", "fc_", 0 },
		{ "german", "ge_", 0 },
		{ "austrian", "ge_", 0 },
		{ "italian", "it_", 0 },
		{ "spanish", "sp_", 0 },
		{ "british", "br_", 0 },
		{ "russian", "ru_", 0 },
		{ "polish", "po_", 0 },
		{ "korean", "ko_", 0 },
		{ "japanese", "ja_", 0 },
		{ "czech", "cz_", 0 }
};

/*
==============
SEH_UpdateCurrentLanguage
==============
*/
void SEH_UpdateCurrentLanguage()
{
	language_t lang;

	lang = (language_t)Dvar_GetInt(loc_language);
	switch (lang)
	{
	case LANGUAGE_FRENCH:
	case LANGUAGE_FRENCHCANADIAN:
	case LANGUAGE_GERMAN:
	case LANGUAGE_AUSTRIAN:
	case LANGUAGE_ITALIAN:
	case LANGUAGE_SPANISH:
	case LANGUAGE_RUSSIAN:
		break;
	case LANGUAGE_KOREAN:
	case LANGUAGE_JAPANESE:
	case LANGUAGE_FULLJAPANESE:
		g_currentAsian = 1;
		break;
	default:
		g_currentAsian = 0;
		break;
	}
	if (lang == LANGUAGE_FULLJAPANESE)
		Dvar_SetString(language, g_languages[11].pszName);
	else
		Dvar_SetString(language, g_languages[lang].pszName);
}

/*
==============
SEH_GetCurrentLanguage
==============
*/
int SEH_GetCurrentLanguage()
{
	return Dvar_GetInt(loc_language);
}

/*
==============
SEH_InitLanguage
==============
*/
void SEH_InitLanguage()
{
	if (!language)
	{
		language = _Dvar_RegisterString("language", "", 0, "");
		loc_language = _Dvar_RegisterInt("loc_language", 0, 0, 15, 0x21u, "Language");
		loc_forceEnglish = _Dvar_RegisterBool("loc_forceEnglish", 0, 0x21u, "Force english localized strings");
		loc_warnings = _Dvar_RegisterBool("loc_warnings", 0, 0, "Enable localization warnings");
		loc_warningsAsErrors = _Dvar_RegisterBool("loc_warningsAsErrors", 0, 0, "Throw an error for any unlocalized string");
	}
	SEH_UpdateCurrentLanguage();
}

/*
==============
SEH_VerifyLanguageSelection
==============
*/
unsigned int SEH_VerifyLanguageSelection(int iLanguageSelection)
{
	int i;

	if (g_languages[iLanguageSelection].bPresent)
	{
		return iLanguageSelection;
	}
	for (i = 0; i < 13; ++i)
	{
		if (g_languages[(i + iLanguageSelection) % 13].bPresent)
		{
			return (i + iLanguageSelection) % 13;
		}
	}
	return 0;
}

/*
==============
SEH_Init_StringEd
==============
*/
void __cdecl SEH_Init_StringEd()
{
	SE_Init();
}

/*
==============
SEH_Shutdown_StringEd
==============
*/
void __cdecl SEH_Shutdown_StringEd()
{
	SE_ShutDown();
}

/*
==============
SE_GetString_FastFile
==============
*/
const char *SE_GetString_FastFile(const char *psPackageAndStringReference)
{
	LocalizeEntry* localize;
	const char* value;

	value = GetString(psPackageAndStringReference);
	if (value)
	{
		return value;
	}

	localize = DB_FindXAssetHeader(ASSET_TYPE_LOCALIZE_ENTRY, psPackageAndStringReference, true, -1).localize;
	if (localize)
	{
		return localize->value;
	}

	return NULL;
}

/*
==============
SE_GetString
==============
*/
inline const char* SE_GetString(const char* psPackageAndStringReference)
{
	if (IsFastFileLoad())
	{
		return SE_GetString_FastFile(psPackageAndStringReference);
	}

	return SE_GetString_LoadObj(psPackageAndStringReference)->c_str();

}

/*
==============
SEH_StringEd_GetString
==============
*/
const char *SEH_StringEd_GetString(const char *pszReference)
{
	if (!loc_translate || !loc_translate->current.enabled)
	{
		return pszReference;
	}
	if (*pszReference && (!*pszReference || pszReference[1]))
	{
		return SE_GetString(pszReference);
	}
	return pszReference;
}

/*
==============
SEH_SafeTranslateString
==============
*/
const char *SEH_SafeTranslateString(const char *pszReference)
{
	const char* pszTranslation;
	static char szErrorString[1024];

	pszTranslation = SEH_StringEd_GetString(pszReference);
	if (!pszTranslation)
	{
		if (loc_warnings->current.enabled)
		{
			if (loc_warningsAsErrors->current.enabled)
			{
				Com_Error(ERR_LOCALIZATION, "Could not translate exe string \"%s\"", pszReference);
			}
			else
			{
				Com_PrintWarning(16, "WARNING: Could not translate exe string \"%s\"\n", pszReference);
			}

			strcpy(szErrorString, "^1UNLOCALIZED(^7");
			I_strncat(szErrorString, sizeof(szErrorString), pszReference);
			I_strncat(szErrorString, sizeof(szErrorString), "^1)^7");
		}
		else
		{
			I_strncpyz(szErrorString, pszReference, sizeof(szErrorString));
		}
		pszTranslation = szErrorString;
	}

	return pszTranslation;
}

/*
==============
SEH_GetLocalizedTokenReference
==============
*/
int SEH_GetLocalizedTokenReference(char *token, const char *reference, const char *messageType, msgLocErrType_t errType)
{
	const char* translation;

	translation = SEH_StringEd_GetString(reference);
	if (!translation)
	{
		if (loc_warnings && loc_warnings->current.enabled)
		{
			if (loc_warningsAsErrors && loc_warningsAsErrors->current.enabled && errType != 1)
			{
				Com_Error(ERR_LOCALIZATION, "Could not translate part of %s: \"%s\"", messageType, reference);
			}
			else
			{
				Com_PrintWarning(CON_CHANNEL_SYSTEM, "WARNING: Could not translate part of %s: \"%s\"\n", messageType, reference);
			}
			translation = va("^1UNLOCALIZED(^7%s^1)^7", reference);
		}
		else
		{
			translation = va("%s", reference);
		}

		if (errType == 1)
		{
			return 0;
		}
	}

	I_strncpyz(token, translation, 1024);

	return 1;
}

/*
==============
SEH_ParseDirective
==============
*/
void SEH_ParseDirective(const char *directive, char *resultName, char *resultArg0)
{
	const char* argpos;

	argpos = strstr((char*)directive, ":");
	if (argpos)
	{
		memcpy(resultName, (char*)directive, argpos - directive);
		resultName[argpos - directive] = 0;
		I_strncpyz(resultArg0, argpos + 1, 256);
	}
	else
	{
		I_strncpyz(resultName, directive, 256);
		*resultArg0 = 0;
	}
}

/*
==============
SEH_GetBindingForDirective
==============
*/
void SEH_GetBindingForDirective(LocalClientNum_t localClientNum, const char *directive, char *result)
{
	char arg0[256];
	char name[256];

	if (UI_GetKeyBindingLocalizedString(localClientNum, directive, result, 0, 0, 0, 0, 1, 0, 1))
	{
		UI_FilterStringForButtonAnimation(result, 0x100u);
		return;
	}
	SEH_ParseDirective(directive, name, arg0);
	if (UI_GetSticksTranslatedString(localClientNum, directive, result))
	{
		UI_FilterStringForButtonAnimation(result, 0x100u); 
		return;
	}
	if (I_stricmp(name, "gocrouch"))
	{
		if (!I_stricmp(name, "primary"))
		{
			if (GPad_InUse(localClientNum))
				I_strncpyz(result, "^BBUTTON_SELECTCHOICE^", 256);
			else
				I_strncpyz(result, "^BBUTTON_MOUSE_LEFT^", 256);
			UI_FilterStringForButtonAnimation(result, 0x100u);
			return;
		}
	}
	else if (UI_GetKeyBindingLocalizedString(localClientNum, "togglecrouch", result, 0, 0, 0, 0, 1, 0, 1) || UI_GetKeyBindingLocalizedString(localClientNum, "+movedown", result, 0, 0, 0, 0, 1, 0, 1) || UI_GetKeyBindingLocalizedString(localClientNum, "+stance", result, 0, 0, 0, 0, 1, 0, 1))
	{
	LABEL_12:
		UI_FilterStringForButtonAnimation(result, 0x100u);
		return;
	}
	Com_sprintf(result, 256, "%s(%s)", UI_SafeTranslateString("KEY_UNBOUND"), directive);
}

/*
==============
SEH_ReplaceDirective
==============
*/
bool SEH_ReplaceDirective(LocalClientNum_t localClientNum, unsigned int *searchPos, unsigned int *dstLen, char *dstString, unsigned int size)
{
	int endLen;
	int directiveLen;
	char* startTokenPos;
	unsigned int newStringLen;
	int bindingLen;
	char keyBinding[256];
	char srcString[1024];
	int beginLen;
	char directive[256];
	const char* endTokenPos;

	assertMsg((size <= 1024), "(size) = %i", size);
	assertIn(*dstLen, MAX_STRING_CHARS);
	assertMsg(*searchPos > *dstLen, "*searchPos <= *dstLen\n\t%i, %i", *searchPos, *dstLen)
	assertEq(*dstLen, strlen(dstString));
	memcpy(srcString, dstString, *dstLen);
	srcString[*dstLen] = 0;

	startTokenPos = strstr(&srcString[*searchPos], "[{");
	if (!startTokenPos)
	{
		return 0;
	}

	endTokenPos = strstr(startTokenPos, "}]");
	if (!endTokenPos)
	{
		Com_Error(ERR_DROP, va("No end token to match begin token in string '%s'", dstString));
		return 0;
	}

	directiveLen = endTokenPos - startTokenPos - 2;
	assertMsg((directiveLen >= 0), "(directiveLen) = %i", directiveLen);
	if (!directiveLen)
	{
		Com_Error(ERR_DROP, va("Directive empty in string '%s'", dstString));
		return 0;
	}

	memcpy(directive, startTokenPos + 2, directiveLen);
	directive[directiveLen] = 0;
	SEH_GetBindingForDirective(localClientNum, directive, keyBinding);

	bindingLen = strlen(keyBinding);
	newStringLen = *dstLen - directiveLen + bindingLen - 4;

	if (newStringLen + 1 > size)
	{
		Com_Error(ERR_DROP, va("String too long to add key binding: %s\n", dstString));
		return 0;
	}

	beginLen = startTokenPos - srcString;
	dstString = &dstString[startTokenPos - srcString];
	memcpy(dstString, keyBinding, bindingLen);

	dstString = &dstString[bindingLen];
	endLen = newStringLen - beginLen - bindingLen;
	memcpy(dstString, (char*)endTokenPos + 2, endLen);

	dstString[endLen] = 0;
	*searchPos = bindingLen + beginLen;
	*dstLen = newStringLen;
	assertLessEq(*searchPos, *dstLen);

	return 1;
}

/*
==============
SEH_ReplaceDirectiveInStringWithBinding
==============
*/
int SEH_ReplaceDirectiveInStringWithBinding(LocalClientNum_t localClientNum, const char *translatedString, char *finalString)
{
	unsigned int stringLen;
	unsigned int searchPos;

	stringLen = strlen(translatedString);
	if (stringLen + 1 > 0x400)
	{
		Com_Error(ERR_DROP, va("Translated string too long to process\n"));

		return 0;
	}

	memcpy(finalString, (char*)translatedString, stringLen);
	finalString[stringLen] = 0;
	searchPos = 0;
	while (SEH_ReplaceDirective(localClientNum, &searchPos, &stringLen, finalString, 0x400u))
	{
	}

	return 1;
}

/*
==============
SEH_LocalizeTextMessage
==============
*/
const char *SEH_LocalizeTextMessage(const char *pszInputBuffer, const char *pszMessageType, msgLocErrType_t errType)
{
	char szInsertBuf[1024];
	char szTokenBuf[1024];
	int bLocOn;
	int iTokenLen;
	int iInsertLevel;
	int iLen;
	int bInsertEnabled;
	int insertIndex;
	const char* pszIn;
	int bLocSkipped;
	const char* pszTokenStart;
	int i;
	char* pszString;
	int digit;
	static int iCurrString;
	static char szStrings[10][1024];

	iCurrString = (iCurrString + 1) % 10;
	memset(szStrings[iCurrString], 0, sizeof(szStrings[iCurrString]));
	pszString = szStrings[iCurrString];
	iLen = 0;
	bLocOn = 1;
	bInsertEnabled = 1;
	iInsertLevel = 0;
	insertIndex = 1;
	bLocSkipped = 0;
	pszTokenStart = pszInputBuffer;
	pszIn = pszInputBuffer;
	while (*pszTokenStart)
	{
		if (!*pszIn || *pszIn == 20 || *pszIn == 21 || *pszIn == 22)
		{
			if (pszIn > pszTokenStart)
			{
				iTokenLen = pszIn - pszTokenStart;
				I_strncpyz(szTokenBuf, pszTokenStart, pszIn - pszTokenStart + 1);
				if (bLocOn)
				{
					if (!SEH_GetLocalizedTokenReference(szTokenBuf, szTokenBuf, pszMessageType, errType))
					{
						return 0;
					}
					iTokenLen = strlen(szTokenBuf);
				}

				if (iTokenLen + iLen >= 1024)
				{
					if (loc_warnings
						&& loc_warnings->current.enabled
						&& loc_warningsAsErrors
						&& loc_warningsAsErrors->current.enabled
						&& errType != 1)
					{
						Com_Error(ERR_DROP, "%s too long when translated: \"%s\"", pszMessageType, pszInputBuffer);
					}
					Com_Printf(CON_CHANNEL_SYSTEM, "%s too long when translated: \"%s\"\n", pszMessageType,
						pszInputBuffer);
				}

				for (i = 0; i < iTokenLen - 2; ++i)
				{
					if (!strncmp(&szTokenBuf[i], "&&", 2) && isdigit(szTokenBuf[i + 2]))
					{
						if (bInsertEnabled)
						{
							++iInsertLevel;
						}
						else
						{
							szTokenBuf[i] = 22;
							bLocSkipped = 1;
						}
					}
				}

				if (iInsertLevel <= 0 || iLen <= 0)
				{
					strcpy(&pszString[iLen], szTokenBuf);
				}
				else
				{
					for (i = 0; i < iLen - 2; ++i)
					{
						if (!strncmp(&pszString[i], "&&", 2) && isdigit(pszString[i + 2]))
						{
							digit = pszString[i + 2] - 48;
							if (!digit)
							{
								Com_Printf(CON_CHANNEL_SYSTEM, "%s cannot have &&0 as conversion format: \"%s\"\n",
									pszMessageType, pszInputBuffer);
							}
							if (digit == insertIndex)
							{
								strcpy(szInsertBuf, &pszString[i + 3]);
								pszString[i] = 0;
								++insertIndex;
								break;
							}
						}
					}

					strcpy(&pszString[i], szTokenBuf);
					strcpy(&pszString[iTokenLen + i], szInsertBuf);
					iLen -= 3;
					--iInsertLevel;
				}
				iLen += iTokenLen;
			}

			bInsertEnabled = 1;
			if (*pszIn == 20)
			{
				bLocOn = 1;
				++pszIn;
			}
			else if (*pszIn == 21)
			{
				bLocOn = 0;
				++pszIn;
			}

			if (*pszIn == 22)
			{
				bInsertEnabled = 0;
				++pszIn;
			}
			pszTokenStart = pszIn;
		}
		else
		{
			++pszIn;
		}
	}

	if (bLocSkipped)
	{
		for (i = 0; i < iLen; ++i)
		{
			if (pszString[i] == 22)
			{
				pszString[i] = 37;
			}
		}
	}

	return pszString;
}

/*
==============
Language_IsAsian
==============
*/
inline int Language_IsAsian()
{
	return g_currentAsian;
}

/*
==============
SEH_DecodeLetter
==============
*/
int SEH_DecodeLetter(unsigned __int8 firstChar, unsigned __int8 secondChar, unsigned __int8 thirdChar, int *usedCount)
{
	if ((firstChar & 0x80u) != 0)
	{
		if ((firstChar & 0xE0) == 0xC0)
		{
			*usedCount = 2;
			return ((firstChar & 0x1F) << 6) | secondChar & 0x3F;
		}
		else if ((firstChar & 0xF0) == 0xE0)
		{
			*usedCount = 3;
			return thirdChar & 0x3F | ((((firstChar & 0xF) << 6) | secondChar & 0x3F) << 6);
		}
		else
		{
			*usedCount = 1;
			return firstChar;
		}
	}
	else
	{
		*usedCount = 1;
		return firstChar;
	}
}

/*
==============
SEH_ReadCharFromString
==============
*/
int SEH_ReadCharFromString(const char **text)
{
	unsigned int letter;

	letter = SEH_DecodeLetter(**text, (*text)[1], (*text)[2], (int*)&text);
	*text += (int)&text;
	return letter;
}

/*
==============
SEH_PrintStrlen
==============
*/
int SEH_PrintStrlen(const char *string)
{
	unsigned int c;
	int len;
	const char* p;

	if (!string)
	{
		return 0;
	}
	len = 0;
	p = string;
	while (*p)
	{
		c = SEH_ReadCharFromString(&p);
		if (c == 94 && p && *p != 94 && *p >= 48 && *p <= 64)
		{
			++p;
		}
		else if (c != 10 && c != 13)
		{
			++len;
		}
	}
	return len;
}

/*
==============
SEH_GetLanguageName
==============
*/
const char *SEH_GetLanguageName(const int iLanguage)
{
	if (iLanguage >= 0 && iLanguage < 13)
	{
		return g_languages[iLanguage].pszName;
	}

	return g_languages[0].pszName;
}

/*
==============
SEH_GetLanguageNameAbbr
==============
*/
const char *SEH_GetLanguageNameAbbr(const int iLanguage)
{
	if (iLanguage >= 0 && iLanguage < 13)
	{
		return g_languages[iLanguage].pszNameAbbr;
	}

	return g_languages[0].pszNameAbbr;
}

/*
==============
SEH_StringEd_SetLanguageStrings
==============
*/
int SEH_StringEd_SetLanguageStrings(int iLanguage)
{
	const char* pszError;

	if (!g_languages[iLanguage].bPresent)
	{
		return 0;
	}

	pszError = SE_LoadLanguage(Dvar_GetBool(loc_forceEnglish));
	if (!pszError)
	{
		return 1;
	}

	if (!Dvar_GetBool(fs_ignoreLocalized) && Dvar_GetBool(loc_warnings))
	{
		if (Dvar_GetBool(loc_warningsAsErrors))
		{
			Com_Error(ERR_LOCALIZATION, "Could not load localization strings for %s: %s", SEH_GetLanguageName(iLanguage), pszError);
		}
		else
		{
			Com_PrintWarning(16, "WARNING: Could not load localization strings for %s: %s\n", SEH_GetLanguageName(iLanguage), pszError);
		}
	}
	return 1;
}

/*
==============
SEH_TranslateMessage
==============
*/
void SEH_TranslateMessage(LocalClientNum_t localClientNum, const char *message, const char *messageType, char *finalString, unsigned int size)
{
	int stringLen;
	int p;

	assert(message);
	assert(finalString);

	finalString = (char*)SEH_LocalizeTextMessage(message, messageType, LOCMSG_SAFE);
	stringLen = finalString[strlen(finalString) + 1];
	p = stringLen - (*finalString + 1);
	if (stringLen - (unsigned int)finalString <= size)
	{
		memcpy(finalString, finalString, p);
		finalString[p] = 0;
		message = 0;
		while (SEH_ReplaceDirective(localClientNum, (unsigned int*)&message, (unsigned int*)&finalString, finalString, size))
			;
	}
	else
	{
		Com_Error(ERR_DROP, "Translated message too long to process: %s\n", message);
	}
}

/*
==============
SEH_UpdateLanguageInfo
==============
*/
void SEH_UpdateLanguageInfo()
{
	language_t lang;
	const char* pszNameAbbr;
	int i, iNumLanguages;
	char filepath[256];
	char fname[256];

	assert(loc_language);
	SEH_UpdateCurrentLanguage();
	lang = (language_t)Dvar_GetInt(loc_language);
	if (lang > LANGUAGE_MEXICANSPANISH)
	{
		pszNameAbbr = g_languages[LANGUAGE_ENGLISH].pszNameAbbr;
	}
	else
	{
		pszNameAbbr = g_languages[lang].pszNameAbbr;
	}
	Com_sprintf(fname, 256, "%s%s", pszNameAbbr, CODE_FAST_FILE_NAME);
	DB_BuildOSPath(fname, ".ff", 256, filepath);
	if (!Sys_FileExists(filepath) || (g_languages[lang].bPresent = 1, !SEH_StringEd_SetLanguageStrings(lang)))
	{
		iNumLanguages = 0;
		for (i = 0; i < 13; ++i)
		{
			if (FS_LanguageHasAssets(i))
			{
				g_languages[i].bPresent = 1;
				++iNumLanguages;
			}
			else
			{
				g_languages[i].bPresent = 0;
			}
		}
		if (!iNumLanguages)
			Com_PrintError(10, "ERROR: No languages available because no localized assets were found\n");
		if (!SEH_StringEd_SetLanguageStrings(Dvar_GetInt(loc_language)))
		{
			for (i = 0; i < 13; ++i)
			{
				Dvar_SetInt(loc_language, i);
				SEH_UpdateCurrentLanguage();
				if (SEH_StringEd_SetLanguageStrings(i))
				{
					return;
				}
			}
			Dvar_SetInt(loc_language, 0);
			SEH_UpdateCurrentLanguage();
		}
	}
}

