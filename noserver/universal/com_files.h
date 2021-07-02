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

#ifndef COM_FILES_H
#define COM_FILES_H

#include <universal/dvar.h>

union qfile_gus
{
	FILE* o;
	unsigned __int8* z;
};

struct qfile_us
{
	qfile_gus file;
	int iwdIsClone;
};

struct fileInIwd_s
{
	unsigned int pos;
	char* name;
	fileInIwd_s* next;
};

typedef struct iwd_t
{
	char iwdFilename[256];
	char iwdBasename[256];
	char iwdGamename[256];
	unsigned __int8* handle;
	int checksum;
	int pure_checksum;
	volatile int hasOpenFile;
	int numFiles;
	unsigned __int8 referenced;
	unsigned int hashSize;
	fileInIwd_s** hashTable;
	fileInIwd_s* buildBuffer;
} iwd_t;

typedef struct fileHandleData_t
{
	qfile_us handleFiles;
	int handleSync;
	int fileSize;
	int zipFilePos;
	iwd_t* zipFile;
	int streamed;
	char name[256];
} fileHandleData_t;

extern int fs_numServerIwds;

static dvar_t* fs_debug;
static dvar_t* fs_ignoreLocalized;
static dvar_t* fs_homepath;
static dvar_t* fs_restrict;
static dvar_t* fs_usedevdir;
static dvar_t* fs_basepath;
static dvar_t* fs_cdpath;
static dvar_t* fs_basegame;
static dvar_t* fs_gameDirVar;
static dvar_t* fs_copyfiles;
static dvar_t* fs_userDocuments;
static dvar_t* fs_usermapDir;

static fileHandleData_t fsh[70];

void TRACK_com_files(void);
int FS_Initialized(void);
void FS_CheckFileSystemStarted(void);
int FS_IwdIsPure(struct iwd_t const*);
int FS_LoadStack(void);
int FS_UseSearchPath(struct searchpath_s const*);
int FS_LanguageHasAssets(int);
long FS_HashFileName(char const*, int);
int FS_HandleForFile(char const*, enum FsThread);
int FS_HandleForFileCurrentThread(char const*);
struct _iobuf* FS_FileForHandle(int);
enum FsThread FS_GetCurrentThread();
__int64 FS_filelength(int);
void FS_ReplaceSeparators(char*);
void FS_BuildOSPathForThread(char const*, char const*, char const*, char* const, enum FsThread);
void FS_BuildOSPath(char const*, char const*, char const*, char* const);
char FS_IsBackupSubStr(const char*);
int FS_CreatePath(char*);
void FS_CopyFile(char*, char*);
void FS_FCloseFile(int);
void FS_FCloseLogFile(int);
int FS_GetHandleAndOpenFile(char const*, char const*, enum FsThread);
int FS_FOpenFileWriteToDirForThread(char const*, char const*, char const*, enum FsThread);
int FS_FOpenFileWriteToDir(char const*, char const*, char const*);
int FS_FOpenFileWrite(char const*);
int FS_FOpenFileWriteCurrentThread(char const*, char const*, char const*);
int FS_FOpenTextFileWrite(char const*);
int FS_FOpenFileAppend(char const*);
int FS_FilenameCompare(char const*, char const*);
int FS_PureIgnoreFiles(char const*);
bool FS_SanitizeFilename(char const*, char*, int);
bool FS_FilesAreLoadedGlobally(char const*);
void FS_FreeFileList(const char**, int);
int FS_Delete(char const*);
int FS_Read(void*, int, int);
int FS_Write(void const*, int, int);
int FS_WriteToDemo(void const*, int, int);
int FS_WriteLog(void const*, int, int);
void FS_Printf(int, char const*, ...);
int FS_Seek(int, long, int);
void FS_ResetFiles(void);
void FS_FreeFile(void*);
int FS_WriteFile(char const*, void const*, int);
int FS_GetFileOsPath(char const*, char*);
int FS_OpenFileOverwrite(char const*);
int FS_ReturnPath(char const*, char*, int*);
int FS_AddFileToList(struct HunkUser*, char const*, char const** const, int);
char const** FS_ListFilteredFiles(struct searchpath_s*, char const*, char const*, char const*, enum FsListBehavior_e, int*, int);
const char** FS_ListFiles(const char*, const char*, enum FsListBehavior_e, int*, int);
bool FS_CheckLocation(char const*, int);
const char** FS_ListFilteredFilesInLocation(const char*, const char*, const char*, enum FsListBehavior_e, int*, int, int);
int FS_GetFileList(char const*, char const*, enum FsListBehavior_e, char*, int);
void FS_ConvertPath(char*);
int FS_PathCmp(const char*, const char*);
void FS_SortFileList(char const**, int);
void FS_DisplayPath(int);
void FS_FullPath_f(void);
void FS_Path_f(void);
void FS_AddIwdFilesForGameDirectory(const char*, const char*);
void FS_AddSearchPath(struct searchpath_s*);
void FS_AddGameDirectory(char const*, char const*, int, int);
void FS_AddLocalizedGameDirectory(char const*, char const*);
void FS_ShutdownSearchPaths(struct searchpath_s*);
void FS_ShutdownServerFileReferences(int*, char const**);
void FS_ShutdownServerIwdNames(void);
void FS_ShutdownServerReferencedIwds(void);
void FS_ShutdownServerReferencedFFs(void);
void FS_Shutdown(void);
void FS_RegisterDvars(void);
void FS_AddDevGameDirs(char const*, bool);
void FS_Startup(char const*, bool);
void FS_ClearIwdReferences(void);
void FS_AddIwdPureCheckReference(struct searchpath_s const*);
void FS_ShutDownIwdPureCheckReferences(void);
void FS_InitFilesystem(bool);
void FS_Restart(int);
bool FS_IsInCompressedIwd(int);
void FS_Flush(int);
bool Com_IsAddonMap(char const*, char const**);
void FS_DisablePureCheck(bool);
int FS_FOpenFileReadForThread(char const*, int*, enum FsThread);
int FS_FOpenFileReadCurrentThread(char const*, int*);
int FS_ReadFile(const char*, void**);
const char** FS_ListFilesInLocation(const char*, const char*, enum FsListBehavior_e, int*, int, int);
void Com_GetBspFilename(char*, int, char const*);
int FS_FOpenFileRead(char const*, int*);
int FS_TouchFile(char const*);
int FS_FOpenFileByMode(char const*, int*, enum fsMode_t);

#endif
