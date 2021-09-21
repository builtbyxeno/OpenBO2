#pragma once

#include "types.h"

//t6/code/src_noserver/stringed/stringed_hooks.cpp
void SEH_UpdateCurrentLanguage();
int SEH_GetCurrentLanguage();
void SEH_InitLanguage();
unsigned int SEH_VerifyLanguageSelection(int iLanguageSelection);
;
;
const char *SE_GetString_FastFile(const char *psPackageAndStringReference);
const char *SEH_StringEd_GetString(const char *pszReference);
const char *SEH_SafeTranslateString(const char *pszReference);
int SEH_GetLocalizedTokenReference(char *token, const char *reference, const char *messageType, msgLocErrType_t errType);
void SEH_ParseDirective(const char *directive, char *resultName, char *resultArg0);
void SEH_GetBindingForDirective(LocalClientNum_t localClientNum, const char *directive, char *result);
bool SEH_ReplaceDirective(LocalClientNum_t localClientNum, unsigned int *searchPos, unsigned int *dstLen, char *dstString, unsigned int size);
int SEH_ReplaceDirectiveInStringWithBinding(int a1, LocalClientNum_t localClientNum, const char *translatedString, char *finalString);
const char *SEH_LocalizeTextMessage(const char *pszInputBuffer, const char *pszMessageType, msgLocErrType_t errType);
int SEH_DecodeLetter(unsigned __int8 firstChar, unsigned __int8 secondChar, unsigned __int8 thirdChar, int *usedCount);
int SEH_ReadCharFromString(const char **text);
int SEH_PrintStrlen(const char *string);
const char *SEH_GetLanguageName(const int iLanguage);
const char *SEH_GetLanguageNameAbbr(const int iLanguage);
int SEH_StringEd_SetLanguageStrings(int iLanguage);
;
void SEH_UpdateLanguageInfo();

//t6/code/src_noserver/stringed/stringed_ingame.cpp
// char *__thiscall CStringEdPackage::Filename_WithoutExt(CStringEdPackage *this, const char *psFilename);
// char *__thiscall CStringEdPackage::Filename_WithoutPath(CStringEdPackage *this, const char *psFilename);
// int __thiscall CStringEdPackage::CheckLineForKeyword(CStringEdPackage *this, const char *psKeyword, const char **psLine);
// char __thiscall CStringEdPackage::IsStringFormatCorrect(CStringEdPackage *this, const char *string);
// void __thiscall CStringEdPackage::REMKill(CStringEdPackage *this, char *psBuffer);
// int __thiscall CStringEdPackage::ReadLine(CStringEdPackage *this, const char **psParsePos, char *psDest);
// const char *SE_GetFoundFile(std::string *strResult);
// void __thiscall CStringEdPackage::SetupNewFileParse(CStringEdPackage *this, const char *psFileName);
// void __thiscall CStringEdPackage::SetString(CStringEdPackage *this, const char *psLocalReference, const char *psNewString, int bSentenceIsEnglish);
// std::string *SE_GetString_LoadObj(const char *psPackageAndStringReference);
// std::string *__thiscall CStringEdPackage::ConvertCRLiterals_Read(CStringEdPackage *this, std::string *result, std::string string);
// std::string *__thiscall CStringEdPackage::InsideQuotes(CStringEdPackage *this, std::string *result, const char *psLine);
// void __thiscall CStringEdPackage::Clear(CStringEdPackage *this);
void SE_NewLanguage();
// void __thiscall CStringEdPackage::AddEntry(CStringEdPackage *this, const char *psLocalReference);
void SE_Init();
void SE_ShutDown();
// const char *__thiscall CStringEdPackage::ParseLine(CStringEdPackage *this, const char *psLine, bool forceEnglish);
char *SE_Load(const char *psFileName, bool forceEnglish);
char *SE_LoadLanguage(bool forceEnglish);
char ReadLine(_iobuf *fp);

//t6/code/src_noserver/stringed/stringed_interface.cpp
unsigned __int8 *SE_LoadFileData(const char *psFileName);
void SE_FreeFileDataAfterLoad(unsigned __int8 *psLoadedFile);
// void SE_R_ListFiles(const char *psExtension, const char *psDir, std::string *strResults);
// int SE_BuildFileList(const char *psStartDir, std::string *strResults);

//#include "stringed/stringed_load_db.h"

