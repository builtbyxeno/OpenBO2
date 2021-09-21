#include "types.h"
#include "functions.h"

/*
==============
TRACK_com_files
==============
*/
void TRACK_com_files()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_Initialized
==============
*/
BOOL FS_Initialized()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_CheckFileSystemStarted
==============
*/
void FS_CheckFileSystemStarted()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_IwdIsPure
==============
*/
int FS_IwdIsPure(const iwd_t *iwd)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_LoadStack
==============
*/
int FS_LoadStack()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_UseSearchPath
==============
*/
BOOL FS_UseSearchPath(const searchpath_s *pSearch)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_LanguageHasAssets
==============
*/
int FS_LanguageHasAssets(int iLanguage)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_HashFileName
==============
*/
int FS_HashFileName(const char *fname, int hashSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_HandleForFile
==============
*/
int FS_HandleForFile(const char *name, FsThread thread)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_HandleForFileCurrentThread
==============
*/
int FS_HandleForFileCurrentThread(const char *filename)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_FileForHandle
==============
*/
_iobuf *FS_FileForHandle(int f)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
FS_filelength
==============
*/
__int64 FS_filelength(int f)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_ReplaceSeparators
==============
*/
void FS_ReplaceSeparators(char *path)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_BuildOSPathForThread
==============
*/
void FS_BuildOSPathForThread(const char *base, const char *game, const char *qpath, char *ospath, FsThread thread)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_BuildOSPath
==============
*/
void __cdecl FS_BuildOSPath(const char *base, const char *game, const char *qpath)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_CreatePath
==============
*/
int FS_CreatePath(char *OSPath)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_CopyFile
==============
*/
void FS_CopyFile(char *fromOSPath, char *toOSPath)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_FCloseFile
==============
*/
void FS_FCloseFile(int h)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_FCloseLogFile
==============
*/
void FS_FCloseLogFile(int h)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_GetHandleAndOpenFile
==============
*/
int FS_GetHandleAndOpenFile(const char *filename, const char *ospath, FsThread thread)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_FOpenFileWriteToDirForThread
==============
*/
int FS_FOpenFileWriteToDirForThread(const char *filename, const char *dir, const char *osbasepath, FsThread thread)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_FOpenFileWriteToDir
==============
*/
int FS_FOpenFileWriteToDir(const char *a1, const char *a2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_FOpenFileWrite
==============
*/
int FS_FOpenFileWrite(const char *a1, const char *a2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_FOpenFileWriteCurrentThread
==============
*/
int FS_FOpenFileWriteCurrentThread(FsThread a1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_FOpenTextFileWrite
==============
*/
int FS_FOpenTextFileWrite(qfile_gus filename, const char *a2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_FOpenFileAppend
==============
*/
int FS_FOpenFileAppend(qfile_gus filename, const char *a2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_FilenameCompare
==============
*/
int FS_FilenameCompare(const char *s1, const char *s2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_PureIgnoreFiles
==============
*/
BOOL FS_PureIgnoreFiles(const char *filename)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_SanitizeFilename
==============
*/
bool FS_SanitizeFilename(const char *filename, char *sanitizedName, int sanitizedNameSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_FilesAreLoadedGlobally
==============
*/
char FS_FilesAreLoadedGlobally(const char *filename)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_Delete
==============
*/
BOOL FS_Delete(char *a1, const char *filename)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_Read
==============
*/
int FS_Read(void *buffer, int len, int h)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_Write
==============
*/
int FS_Write(const void *buffer, int len, int h)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_WriteToDemo
==============
*/
int FS_WriteToDemo(const void *buffer, int len, int h)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_Printf
==============
*/
void FS_Printf(int h, const char *fmt, ...)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_Seek
==============
*/
int FS_Seek(int f, int offset, int origin)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_ResetFiles
==============
*/
void FS_ResetFiles()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_WriteFile
==============
*/
int FS_WriteFile(const char *a1, const char *a2, FsThread filename, const char *buffer, const void *size, int a6)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_GetFileOsPath
==============
*/
int FS_GetFileOsPath(char *a1, const char *a2, const char *filename, char *ospath)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_OpenFileOverwrite
==============
*/
int FS_OpenFileOverwrite(char *a1, const char *a2, char *qpath, const char *a4)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_ReturnPath
==============
*/
int FS_ReturnPath(const char *zname, char *zpath, int *depth)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_AddFileToList
==============
*/
int FS_AddFileToList(HunkUser *user, const char *name, const char **list, int nfiles)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_ListFilteredFiles
==============
*/
const char **FS_ListFilteredFiles(searchpath_s *searchPath, const char *path, const char *extension, const char *filter, FsListBehavior_e behavior, int *numfiles)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
FS_CheckLocation
==============
*/
bool FS_CheckLocation(const char *path, int lookInFlags)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_GetFileList
==============
*/
int FS_GetFileList(const char *path, const char *extension, FsListBehavior_e behavior, char *listbuf, int bufsize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_ConvertPath
==============
*/
void FS_ConvertPath(char *s)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_SortFileList
==============
*/
void FS_SortFileList(const char **filelist, int numfiles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_DisplayPath
==============
*/
void FS_DisplayPath(int bLanguageCull)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_FullPath_f
==============
*/
void FS_FullPath_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_Path_f
==============
*/
void FS_Path_f()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_AddGameDirectory
==============
*/
void FS_AddGameDirectory(const char *path, const char *dir, int bLanguageDirectory, int iLanguage)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_AddLocalizedGameDirectory
==============
*/
void FS_AddLocalizedGameDirectory(const char *path, const char *dir)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_ShutdownSearchPaths
==============
*/
void FS_ShutdownSearchPaths(searchpath_s *p)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_ShutdownServerFileReferences
==============
*/
void FS_ShutdownServerFileReferences(int *numFiles, const char **fileNames)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_ShutdownServerIwdNames
==============
*/
void FS_ShutdownServerIwdNames(int *a1, const char **a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_ShutdownServerReferencedIwds
==============
*/
void FS_ShutdownServerReferencedIwds(int *a1, const char **a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_ShutdownServerReferencedFFs
==============
*/
void FS_ShutdownServerReferencedFFs(int *a1, const char **a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_Shutdown
==============
*/
void FS_Shutdown()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_RegisterDvars
==============
*/
const dvar_t *FS_RegisterDvars()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
FS_AddDevGameDirs
==============
*/
void FS_AddDevGameDirs(const char *path, bool allow_devraw)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_Startup
==============
*/
void __cdecl FS_Startup(const char *gameName, const char *allow_devraw)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_ClearIwdReferences
==============
*/
void FS_ClearIwdReferences()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_AddIwdPureCheckReference
==============
*/
void FS_AddIwdPureCheckReference(const searchpath_s *search)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_ShutDownIwdPureCheckReferences
==============
*/
void FS_ShutDownIwdPureCheckReferences()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_InitFilesystem
==============
*/
void FS_InitFilesystem(const char *a1, const char *allow_devraw)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_Restart
==============
*/
void FS_Restart(LocalClientNum_t localClientNum, int checksumFeed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_IsInCompressedIwd
==============
*/
BOOL FS_IsInCompressedIwd(int f)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_Flush
==============
*/
void FS_Flush(int f)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Com_IsAddonMap
==============
*/
char Com_IsAddonMap(const char *mapName, const char **pBaseMapName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_DisablePureCheck
==============
*/
void FS_DisablePureCheck(bool disable)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_FOpenFileReadForThread
==============
*/
int FS_FOpenFileReadForThread(const char *filename, int *file, FsThread thread, char *outfullpath, int outfullpathsize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_FOpenFileReadCurrentThread
==============
*/
int __cdecl FS_FOpenFileReadCurrentThread(const char *filename, int *file)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Com_GetBspFilename
==============
*/
void Com_GetBspFilename(char *filename, int size, const char *mapname)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FS_FOpenFileRead
==============
*/
int FS_FOpenFileRead(const char *filename, int *file)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_TouchFile
==============
*/
BOOL FS_TouchFile(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FS_FOpenFileByMode
==============
*/
int FS_FOpenFileByMode(const char *a1, const char *a2, FsThread qpath, const char *f, int *mode, fsMode_t a6)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

