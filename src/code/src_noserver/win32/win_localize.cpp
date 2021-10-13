#include "types.h"
#include "vars.h"
#include <qcommon/qcommon_public.h>

static struct
{
	char* language;
	char* strings;
} localization;

#define LANGUAGE_BUF_SIZE 4095

static char language_buffer[LANGUAGE_BUF_SIZE];

/*
==============
Win_InitLocalization
==============
*/
language_t Win_InitLocalization(bool isZombies)
{
    int size;
    FILE* fp;
    int i;
    language_t lang;

    localization.language = NULL;
    localization.strings = NULL;
    if (isZombies)
        fp = FS_FileOpenReadText("localization_zm.txt");
    else
        fp = FS_FileOpenReadText("localization_mp.txt");
    if (!fp)
    {
        return LANGUAGE_ENGLISH;
    }

    size = FS_FileGetFileSize(fp);
    assert(size < LANGUAGE_BUF_SIZE);
    localization.language = language_buffer;
    size = FS_FileRead(language_buffer, size, fp);
    FS_FileClose(fp);
    if (size)
    {
        localization.language[size] = 0;
        lang = LANGUAGE_ENGLISH;
        for (i = 0; localization.language[i]; ++i)
        {
            if (localization.language[i] == 10)
            {
                localization.language[i] = 0;
                localization.strings = &localization.language[i + 1];
                break;
            }
        }
        return lang;
    }

    localization.language = NULL;
    return LANGUAGE_ENGLISH;
}

/*
==============
Win_ShutdownLocalization
==============
*/
void Win_ShutdownLocalization()
{
    localization.language = 0;
    localization.strings = 0;
}

/*
==============
Win_CopyLocalizationString
==============
*/
inline const char* Win_CopyLocalizationString(const char* string)
{
    return va("%s", string);
}

/*
==============
Win_LocalizeRef
==============
*/
const char *Win_LocalizeRef(const char *ref)
{
    const char* strings;
    int useRef;
    const char* token;

    Com_BeginParseSession("localization");
    strings = localization.strings;
    while (1)
    {
        token = Com_Parse(&strings);
        if (!*token)
        {
            Com_EndParseSession();
            assertMsg(va("unlocalized: %s", ref));
            return Win_CopyLocalizationString(ref);
        }

        useRef = strcmp(token, ref) == 0;
        token = Com_Parse(&strings);
        if (!*token)
        {
            break;
        }

        if (useRef)
        {
            Com_EndParseSession();
            return Win_CopyLocalizationString(token);
        }
    }

    Com_EndParseSession();
    assertMsg(va("missing value: %s", ref));

    return Win_CopyLocalizationString(ref);
}

/*
==============
Win_GetLanguage
==============
*/
const char *Win_GetLanguage()
{
    return "english";
}

