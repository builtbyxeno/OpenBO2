#include "types.h"
#include "vars.h"
#include <io.h>

static bool inited_1;
static _RTL_CRITICAL_SECTION s_criticalSection[CRITSECT_COUNT];
static unsigned int s_threadAffinityMask;

/*
==============
TRACK_win_common
==============
*/
void TRACK_win_common()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_Mkdir
==============
*/
void Sys_Mkdir(const char *path)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_MkdirEx
==============
*/
void Sys_MkdirEx(const char *_path)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_Cwd
==============
*/
char *Sys_Cwd()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Clan_GetName
==============
*/
const GfxViewParms *Clan_GetName()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Sys_DefaultHomePath
==============
*/
char *Sys_DefaultHomePath()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Sys_DefaultInstallPath
==============
*/
char *Sys_DefaultInstallPath()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Sys_FileExists
==============
*/
bool Sys_FileExists(const char *path)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

bool HasFileExtension(const char* name, const char* extension)
{
    char search[256];

    Com_sprintf(search, sizeof(search), "*.%s", extension);
    return I_stricmpwild(search, name) == 0;
}

/*
==============
Sys_ListFilteredFiles
==============
*/
void Sys_ListFilteredFiles(HunkUser *user, const char *basedir, const char *subdirs, const char *filter, char **list, int *numfiles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Sys_ListFiles
==============
*/
char **Sys_ListFiles(const char *directory, const char *extension, const char *filter, int *numfiles, int wantsubs)
{
    _finddata_t findinfo;
    int flag;
    char** listCopy;
    int findhandle;
    char* list[16384];
    int nfiles;
    HunkUser* user;
    char search[256];
    int i;

    if (filter)
    {
        user = Hunk_UserCreate(0x20000, HU_SCHEME_DEFAULT, 0, NULL, "Sys_ListFiles", 3);
        nfiles = 0;
        Sys_ListFilteredFiles(user, directory, "", filter, list, &nfiles);
        list[nfiles] = NULL;
        *numfiles = nfiles;
        if (!nfiles)
        {
            Hunk_UserDestroy(user);
            return NULL;
        }

        listCopy = (char**)Hunk_UserAlloc(user, 4 * nfiles + 8, 4, NULL);
        *listCopy = (char*)user;
        ++listCopy;
        for (i = 0; i < nfiles; ++i)
        {
            listCopy[i] = list[i];
        }
        listCopy[i] = NULL;

        return listCopy;
    }

    if (!extension)
    {
        extension = "";
    }

    // passing a slash as extension will find directories
    if (extension[0] == '/' && extension[1] == 0)
    {
        extension = "";
        flag = 0;
    }
    else
    {
        flag = _A_SUBDIR;
    }

    if (*extension)
    {
        Com_sprintf(search, sizeof(search), "%s\\*.%s", directory, extension);
    }
    else
    {
        Com_sprintf(search, sizeof(search), "%s\\*", directory);
    }

    // search
    nfiles = 0;

    findhandle = _findfirst(search, &findinfo);
    if (findhandle == -1)
    {
        *numfiles = 0;
        return NULL;
    }

    user = Hunk_UserCreate(0x20000, HU_SCHEME_DEFAULT, 0, NULL, "Sys_ListFiles", 3);
    do
    {
        if ((!wantsubs && flag != (findinfo.attrib & 0x10) || wantsubs && findinfo.attrib & 0x10)
            && (!(findinfo.attrib & 0x10)
                || I_stricmp(findinfo.name, ".") && I_stricmp(findinfo.name, "..") && I_stricmp(findinfo.name, "CVS"))
            && (!*extension || HasFileExtension(findinfo.name, extension)))
        {
            list[nfiles++] = Hunk_CopyString(user, findinfo.name);
            if (nfiles == 0x3FFF)
            {
                break;
            }
        }
    } while (_findnext(findhandle, &findinfo) != -1);

    list[nfiles] = 0;

    _findclose(findhandle);

    // return a copy of the list
    *numfiles = nfiles;

    if (!nfiles)
    {
        Hunk_UserDestroy(user);
        return NULL;
    }

    listCopy = (char**)Hunk_UserAlloc(user, 4 * nfiles + 8, 4, NULL);
    *listCopy = (char*)user;
    ++listCopy;
    for (i = 0; i < nfiles; ++i)
    {
        listCopy[i] = list[i];
    }
    listCopy[i] = NULL;

    return listCopy;
}

/*
==============
Sys_DirectoryHasContents
==============
*/
int Sys_DirectoryHasContents(const char *directory)
{
	_finddata64i32_t findinfo;
	int findhandle;
	char search[256];

	Com_sprintf(search, sizeof(search), "%s\\*", directory);
	findhandle = _findfirst(search, &findinfo);
	if (findhandle == -1)
	{
		return 0;
	}

	do
	{
		if (!(findinfo.attrib & 0x10)
			|| I_stricmp(findinfo.name, ".") && I_stricmp(findinfo.name, "..") && I_stricmp(findinfo.name, "CVS"))
		{
			_findclose(findhandle);
			return 1;
		}
	} while (_findnext(findhandle, &findinfo) != -1);

	_findclose(findhandle);
	return 0;
}

/*
==============
Sys_InitializeCriticalSections
==============
*/
void Sys_InitializeCriticalSections()
{
	int critSect;
	static bool inited = false;

	if (!inited)
	{
		inited = true;
		for (critSect = 0; critSect < CRITSECT_COUNT; ++critSect)
		{
			InitializeCriticalSection(&s_criticalSection[critSect]);
		}
	}
}

/*
==============
Sys_EnterCriticalSection
==============
*/
void Sys_EnterCriticalSection(CriticalSection critSect)
{
	assertIn(critSect, CRITSECT_COUNT);
	EnterCriticalSection(&s_criticalSection[critSect]);
}

/*
==============
Sys_TryEnterCriticalSection
==============
*/
BOOL Sys_TryEnterCriticalSection(CriticalSection critSect)
{
	assertIn(critSect, CRITSECT_COUNT);
	return TryEnterCriticalSection(&s_criticalSection[critSect]) != 0;
}

/*
==============
Sys_LeaveCriticalSection
==============
*/
void Sys_LeaveCriticalSection(CriticalSection critSect)
{
	assertIn(critSect, CRITSECT_COUNT);
	LeaveCriticalSection(&s_criticalSection[critSect]);
}

