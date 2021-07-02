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

#include "files.h"

#include <universal/com_files.h>
#include <universal/com_fileaccess.h>
#include <universal/q_shared.h>
#include <universal/win_common.h>
#include <qcommon/common.h>

void TRACK_files(void)
{
}

int FS_SV_FOpenFileWrite(char const* filename, char const* dir)
{
    char ospath[256];
    const char* basepath;
    int f;
    int fs_debugInt = Dvar_GetInt(fs_debug);

    f = 0;
    FS_CheckFileSystemStarted();
    if (fs_debugInt)
    {
        Com_Printf(CON_CHANNEL_FILES, "FS_SV_FOpenFileWrite: opening %s\n", filename);
    }

    f = FS_FOpenFileWriteCurrentThread(filename, dir, Dvar_GetString(fs_homepath));

    if (!f && fs_debugInt)
    {
        Com_Printf(CON_CHANNEL_FILES, "FS_SV_FOpenFileWrite: failed to open %s\n", ospath);
    }

    return f;
}

int FS_SV_FOpenFileRead(char const* filename, char const* dir, int* fp)
{
    int result;
    char ospath[256];
    const char* basepath;
    int f;

    f = 0;
    FS_CheckFileSystemStarted();
    if (fs_debug->current.integer)
    {
        Com_Printf(CON_CHANNEL_FILES, "FS_SV_FOpenFileRead: opening %s\n", filename);
    }

    basepath = fs_homepath->current.string;
    FS_BuildOSPath(basepath, dir, filename, ospath);
    f = FS_HandleForFileCurrentThread(filename);
    if (!f)
    {
        return 0;
    }

    fsh[f].zipFile = 0;
    fsh[f].handleSync = 0;
    fsh[f].handleFiles.file.o = FS_FileOpenReadBinary(ospath);
    if (!fsh[f].handleFiles.file.o && I_stricmp(fs_homepath->current.string, fs_basepath->current.string))
    {
        FS_BuildOSPath(fs_basepath->current.string, dir, filename, ospath);
        if (fs_debug->current.integer)
        {
            Com_Printf(CON_CHANNEL_FILES, "FS_SV_FOpenFileRead (fs_basepath): %s\n", ospath);
        }

        fsh[f].handleFiles.file.o = FS_FileOpenReadBinary(ospath);
    }

    if (!fsh[f].handleFiles.file.o)
    {
        FS_BuildOSPath(fs_cdpath->current.string, dir, filename, ospath);
        if (fs_debug->current.integer)
        {
            Com_Printf(CON_CHANNEL_FILES, "FS_SV_FOpenFileRead (fs_cdpath) : %s\n", ospath);
        }

        fsh[f].handleFiles.file.o = FS_FileOpenReadBinary(ospath);
    }

    if (fsh[f].handleFiles.file.o)
    {
        I_strncpyz(fsh[f].name, filename, sizeof(fsh[f].name));
        *fp = f;
        result = FS_filelength(f);
    }
    else
    {
        if (fs_debug->current.integer)
        {
            Com_Printf(CON_CHANNEL_FILES, "FS_SV_FOpenFileRead: failed to open %s\n", filename);
        }
        *fp = 0;
        result = 0;
    }

    return result;
}

int FS_GetModList(char* listbuf, int bufsize)
{
    FILE* file;
    int nMods;
    int nDescLen;
    int descHandle;
    const char* basepath;
    int dummy;
    char* name;
    char descPath[256];
    int nPotential;
    int nLen;
    int nTotal;
    int i;
    char** pFiles;

    pFiles = NULL;
    *listbuf = 0;
    nTotal = 0;
    nPotential = 0;
    nMods = 0;
    basepath = fs_homepath->current.string;

    Com_sprintf(descPath, 256, "%s/%s", basepath, "mods");
    pFiles = Sys_ListFiles(descPath, NULL, NULL, &dummy, 1);
    nPotential = Sys_CountFileList(pFiles);
    for (i = 0; i < nPotential; ++i)
    {
        name = pFiles[i];
        nLen = strlen(name) + 1;
        strcpy(descPath, name);
        I_strncat(descPath, 256, "/description.txt");

        if (FS_SV_FOpenFileRead(descPath, "mods", &descHandle) > 0 && descHandle)
        {
            file = FS_FileForHandle(descHandle);
            Com_Memset(descPath, 0, 256);
            nDescLen = FS_FileRead(descPath, 0x30u, file);
            if (nDescLen >= 0)
            {
                descPath[nDescLen] = 0;
            }

            FS_FCloseFile(descHandle);
        }
        else
        {
            Com_Printf(CON_CHANNEL_FILES, "FS_GetModList: failed to open %s\n", descPath);
            descPath[0] = 0;
        }

        nDescLen = strlen(descPath) + 1;
        if (nLen + nTotal + nDescLen + 2 >= bufsize)
        {
            break;
        }

        strcpy(listbuf, name);
        listbuf = &listbuf[nLen];
        strcpy(listbuf, descPath);

        listbuf = &listbuf[nDescLen];
        nTotal += nDescLen + nLen;
        ++nMods;
    }

    FS_FreeFileList((const char**)pFiles, 0);
    return nMods;
}

void FS_Dir_f(void)
{
}

void FS_NewDir_f(void)
{
}

void FS_TouchFile_f(void)
{
}

int FS_iwIwd(char const*, char*)
{
	return 0;
}

void FS_RemoveCommands(void)
{
}

void FS_AddCommands(void)
{
}

void FS_SetRestrictions(void)
{
}

void FS_LoadedIwds(char const**, char const**)
{
}

char const* FS_LoadedIwdPureChecksums(void)
{
	return nullptr;
}

void FS_ReferencedIwds(char const**, char const**)
{
}

char const* FS_ReferencedIwdPureChecksums(void)
{
	return nullptr;
}

bool FS_PureServerSetLoadedIwds(char const*, char const*)
{
	return false;
}

int FS_ServerSetReferencedFiles(char const*, char const*, int, int*, char const**)
{
	return 0;
}

void FS_ServerSetReferencedIwds(char const*, char const*)
{
}

void FS_ServerSetReferencedFFs(char const*, char const*)
{
}

char const* FS_GetMapBaseName(char const*)
{
	return nullptr;
}
