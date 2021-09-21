#include "types.h"
#include "functions.h"

/*
==============
SEH_UpdateCurrentLanguage
==============
*/
void SEH_UpdateCurrentLanguage()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SEH_GetCurrentLanguage
==============
*/
int SEH_GetCurrentLanguage()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SEH_InitLanguage
==============
*/
void SEH_InitLanguage()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SEH_VerifyLanguageSelection
==============
*/
unsigned int SEH_VerifyLanguageSelection(int iLanguageSelection)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SEH_Init_StringEd
==============
*/
void __cdecl SEH_Init_StringEd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SEH_Shutdown_StringEd
==============
*/
void __cdecl SEH_Shutdown_StringEd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SE_GetString_FastFile
==============
*/
const char *SE_GetString_FastFile(const char *psPackageAndStringReference)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SEH_StringEd_GetString
==============
*/
const char *SEH_StringEd_GetString(const char *pszReference)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SEH_SafeTranslateString
==============
*/
const char *SEH_SafeTranslateString(const char *pszReference)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SEH_GetLocalizedTokenReference
==============
*/
int SEH_GetLocalizedTokenReference(char *token, const char *reference, const char *messageType, msgLocErrType_t errType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SEH_ParseDirective
==============
*/
void SEH_ParseDirective(const char *directive, char *resultName, char *resultArg0)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SEH_GetBindingForDirective
==============
*/
void SEH_GetBindingForDirective(LocalClientNum_t localClientNum, const char *directive, char *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SEH_ReplaceDirective
==============
*/
bool SEH_ReplaceDirective(LocalClientNum_t localClientNum, unsigned int *searchPos, unsigned int *dstLen, char *dstString, unsigned int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SEH_ReplaceDirectiveInStringWithBinding
==============
*/
int SEH_ReplaceDirectiveInStringWithBinding(int a1, LocalClientNum_t localClientNum, const char *translatedString, char *finalString)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SEH_LocalizeTextMessage
==============
*/
const char *SEH_LocalizeTextMessage(const char *pszInputBuffer, const char *pszMessageType, msgLocErrType_t errType)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SEH_DecodeLetter
==============
*/
int SEH_DecodeLetter(unsigned __int8 firstChar, unsigned __int8 secondChar, unsigned __int8 thirdChar, int *usedCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SEH_ReadCharFromString
==============
*/
int SEH_ReadCharFromString(const char **text)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SEH_PrintStrlen
==============
*/
int SEH_PrintStrlen(const char *string)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SEH_GetLanguageName
==============
*/
const char *SEH_GetLanguageName(const int iLanguage)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SEH_GetLanguageNameAbbr
==============
*/
const char *SEH_GetLanguageNameAbbr(const int iLanguage)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
SEH_StringEd_SetLanguageStrings
==============
*/
int SEH_StringEd_SetLanguageStrings(int iLanguage)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SEH_TranslateMessage
==============
*/
void SEH_TranslateMessage(char *a1, LocalClientNum_t localClientNum, const char *message, const char *messageType, char *finalString, unsigned int size)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SEH_UpdateLanguageInfo
==============
*/
void SEH_UpdateLanguageInfo()
{
	UNIMPLEMENTED(__FUNCTION__);
}

