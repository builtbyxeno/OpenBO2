#include "types.h"
#include "vars.h"
#include "universal_public.h"
#include <stringed/stringed_public.h>
#include <qcommon/qcommon_public.h>

fileHandleData_t fsh[70];
char fs_gamedir[256];

searchpath_s* fs_searchpaths;

int fs_loadStack;

int fs_checksumFeed;
int fs_iwdFileCount;
int fs_fakeChkSum;

int bLanguagesListed;
int fs_numServerIwds;
int fs_serverIwds[1024];
bool g_disablePureCheck;

char lastValidBase[256];
char lastValidGame[256];

const char* fs_serverIwdNames[1024];
int fs_numServerReferencedIwds;
const char* fs_serverReferencedIwdNames[1024];
int fs_numServerReferencedFFs;
const char* fs_serverReferencedFFNames[32];

iwd_pure_check_s* fs_iwdPureChecks;

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
	return (fs_searchpaths != NULL);
}

/*
==============
FS_CheckFileSystemStarted
==============
*/
void FS_CheckFileSystemStarted()
{
	assert(fs_searchpaths);
}

/*
==============
FS_IwdIsPure
==============
*/
int FS_IwdIsPure(const iwd_t *iwd)
{
	int i;

	if (!fs_numServerIwds)
	{
		return 1;
	}
	for (i = 0; i < fs_numServerIwds; ++i)
	{
		if (iwd->checksum == fs_serverIwds[i])
		{
			return 1;
		}
	}
	return 0;
}

/*
==============
FS_LoadStack
==============
*/
int FS_LoadStack()
{
	return fs_loadStack;
}

/*
==============
FS_UseSearchPath
==============
*/
BOOL FS_UseSearchPath(const searchpath_s *pSearch)
{
	return !pSearch->bLocalized || !Dvar_GetBool(fs_ignoreLocalized) && (!pSearch->bLocalized || pSearch->language == SEH_GetCurrentLanguage());
}

/*
==============
FS_LanguageHasAssets
==============
*/
int FS_LanguageHasAssets(int iLanguage)
{
	searchpath_s* pSearch;

	for (pSearch = fs_searchpaths; pSearch; pSearch = pSearch->next)
	{
		if (pSearch->bLocalized && pSearch->language == iLanguage)
		{
			return 1;
		}
	}
	return 0;
}

/*
==============
FS_HashFileName
==============
*/
int FS_HashFileName(const char *fname, int hashSize)
{
	long hash;
	int letter;
	int i;

	hash = 0;
	i = 0;
	while (fname[i] != '\0')
	{
		letter = tolower(fname[i]);
		if (letter == '.')
		{
			break;                          // don't include extension
		}
		if (letter == '\\')
		{
			letter = '/';                           // damn path names
		}
		hash += (long)(letter) * (i + 119);
		i++;
	}

	hash = (hash ^ (hash >> 10) ^ (hash >> 20));
	hash &= (hashSize - 1);
	return hash;
}

/*
==============
FS_HandleForFile
==============
*/
int FS_HandleForFile(const char *name, FsThread thread)
{
	int i;
	int count;
	int first;

	switch (thread)
	{
	case FS_THREAD_MAIN:
		assert(Sys_IsMainThread());
		first = 1;
		count = 49;
		break;
	case FS_THREAD_STREAM:
		assert(Sys_IsStreamThread());
		first = 50;
		count = 11;
		break;
	case FS_THREAD_DATABASE:
		assert(Sys_IsDatabaseThread());
		first = 61;
		count = 1;
		break;
	case FS_THREAD_BACKEND:
		assert(Sys_IsRenderThread());
		first = 62;
		count = 1;
		break;
	case FS_THREAD_SERVER:
		assert(Sys_IsServerThread());
		first = 63;
		count = 2;
		break;
	default:
		assertMsg(false, "Does the FS need to support a new thread? ");
		first = 0;
		count = 0;
		break;
	}

	for (i = 0; i < count; ++i)
	{
		if (fsh[i + first].handleFiles.file.o == NULL)
		{
			return i + first;
		}
	}

	Com_PrintWarning(CON_CHANNEL_FILES, "FILE %2i: '%s' 0x%x\n", first, fsh[first].name, fsh[first].handleFiles.file.o);
	Com_PrintWarning(CON_CHANNEL_FILES, "FS_HandleForFile: none free (%d)\n", thread);

	for (i = 1; i < 70; ++i)
	{
		Com_Printf(CON_CHANNEL_FILES, "FILE %2i: '%s' 0x%x\n", i, fsh[i].name, fsh[i].handleFiles.file.o);
	}

	assertMsg("FS_HandleForFile: No free handles available");

	Com_Error(ERR_DROP, "\x15" "FS_HandleForFile: none free");
	return 0;
}

/*
==============
FS_HandleForFileCurrentThread
==============
*/
int FS_HandleForFileCurrentThread(const char *filename)
{
	if (Sys_IsMainThread())
		return FS_HandleForFile(filename, FS_THREAD_MAIN);
	if (Sys_IsDatabaseThread())
		return FS_HandleForFile(filename, FS_THREAD_DATABASE);
	if (Sys_IsStreamThread())
		return FS_HandleForFile(filename, FS_THREAD_STREAM);
	if (Sys_IsRenderThread())
		return FS_HandleForFile(filename, FS_THREAD_BACKEND);
	if (Sys_IsServerThread())
		return FS_HandleForFile(filename, FS_THREAD_SERVER);
}

/*
==============
FS_FileForHandle
==============
*/
FILE *FS_FileForHandle(int f)
{
	assertMsg((f > 0 && f < (1 + 49 + 11 + 1 + 1 + 2 + 5)), "(f) = %i", f);
	assert(!fsh[f].zipFile);
	assert(fsh[f].handleFiles.file.o);

	return fsh[f].handleFiles.file.o;
}

/*
==============
FS_filelength
==============
*/
__int64 FS_filelength(int f)
{
	FILE* h;

	assert(f);

	FS_CheckFileSystemStarted();
	if (fsh[f].zipFile)
	{
		return ((unz_s*)fsh[f].handleFiles.file.z)->cur_file_info.uncompressed_size;
	}

	h = FS_FileForHandle(f);
	return FS_FileGetFileSize(h);
}

/*
==============
FS_ReplaceSeparators
==============
*/
void FS_ReplaceSeparators(char *path)
{
	char* src;
	char* dst;
	bool wasSep;

	wasSep = 0;
	src = path;
	dst = path;
	while (*src)
	{
		if (*src != 47 && *src != 92)
		{
			wasSep = 0;
			*dst++ = *src;
		}
		else if (!wasSep)
		{
			wasSep = 1;
			*dst++ = 92;
		}
		++src;
	}
	*dst = 0;
}

/*
==============
FS_BuildOSPathForThread
==============
*/
void FS_BuildOSPathForThread(const char *base, const char *game, const char *qpath, char *ospath, FsThread thread)
{
	unsigned int lenQpath;
	unsigned int lenGame;
	unsigned int lenBase;

	assert(base);
	assert(qpath);
	assert(ospath);
	if (game)
	{
		if (!*game)
		{
			game = fs_gamedir;
		}
	}
	else
	{
		game = "";
	}

	lenBase = strlen(base);
	lenGame = strlen(game);
	lenQpath = strlen(qpath);
	if ((int)(lenBase + lenGame + 1 + lenQpath + 1) >= 256)
	{
		if (thread)
		{
			*ospath = 0;
			return;
		}
		Com_Error(ERR_FATAL, "\x15" "FS_BuildOSPath: os path length exceeded\n");
	}

	memcpy(ospath, base, lenBase);
	ospath[lenBase] = '/';

	memcpy(&ospath[lenBase + 1], game, lenGame);
	ospath[lenBase + 1 + lenGame] = '/';

	memcpy(&ospath[lenBase + 2 + lenGame], qpath, lenQpath + 1);
	FS_ReplaceSeparators(ospath);
}

/*
==============
FS_BuildOSPath
==============
*/
void FS_BuildOSPath(const char *base, const char *game, const char *qpath, char* ospath)
{
	FS_BuildOSPathForThread(base, game, qpath, ospath, FS_THREAD_MAIN);
}

/*
==============
FS_CreatePath
==============
*/
int FS_CreatePath(char *OSPath)
{
	char* ofs;

	// make absolutely sure that it can't back up the path
	if (strstr(OSPath, "..") || strstr(OSPath, "::"))
	{
		Com_PrintWarning(CON_CHANNEL_FILES, "WARNING: refusing to create relative path \"%s\"\n", OSPath);
		return 1;
	}

	for (ofs = OSPath + 1; *ofs; ++ofs)
	{
		if (*ofs == 92)
		{
			// create the directory
			*ofs = 0;
			Sys_Mkdir(OSPath);
			*ofs = 92;
		}
	}

	return 0;
}

/*
==============
FS_CopyFile
==============
*/
void FS_CopyFile(char *fromOSPath, char *toOSPath)
{
	char* buf;
	int len;
	FILE* f;

	f = FS_FileOpenReadBinary(fromOSPath);
	if (!f)
	{
		return;
	}

	len = FS_FileGetFileSize(f);

	buf = (char*)Z_Malloc(len, "FS_CopyFile", 3);
	if (FS_FileRead(buf, len, f) != len)
	{
		Com_Error(ERR_FATAL, "\x15" "Short read in FS_CopyFile()\n");
	}
	FS_FileClose(f);

	if (FS_CreatePath(toOSPath))
	{
		Z_Free(buf, 3);
		return;
	}

	f = FS_FileOpenWriteBinary(toOSPath);
	if (!f)
	{
		Z_Free(buf, 3);
		return;
	}

	if (FS_FileWrite(buf, len, f) != len)
	{
		Com_Error(ERR_FATAL, "\x15" "Short write in FS_CopyFile()\n");
	}

	FS_FileClose(f);
	Z_Free(buf, 3);
}

/*
==============
FS_FCloseFile
==============
*/
void FS_FCloseFile(int h)
{
	FILE* f;

	FS_CheckFileSystemStarted();
	assert(!fsh[h].streamed);
	if (Dvar_GetInt(fs_debug))
	{
		Com_Printf(CON_CHANNEL_FILES, "FS_FCloseFile from thread '%s', handle '%i', filename '%s'\n", Sys_GetCurrentThreadName(), h, fsh[h].name);
	}

	if (fsh[h].zipFile)
	{
		unzCloseCurrentFile(fsh[h].handleFiles.file.z);
		if (fsh[h].handleFiles.iwdIsClone)
		{
			unzClose(fsh[h].handleFiles.file.z);
		}
		else
		{
			assert(fsh[h].zipFile->hasOpenFile);
			fsh[h].zipFile->hasOpenFile = 0;
		}
		Com_Memset(&fsh[h], 0, sizeof(fsh[h]));
		return;
	}

	if (fsh[h].handleFiles.file.o)
	{
		f = FS_FileForHandle(h);
		FS_FileClose(f);
	}
	Com_Memset(&fsh[h], 0, sizeof(fsh[h]));
}

/*
==============
FS_FCloseLogFile
==============
*/
void FS_FCloseLogFile(int h)
{
	FS_FCloseFile(h);
}

/*
==============
FS_GetHandleAndOpenFile
==============
*/
int FS_GetHandleAndOpenFile(const char *filename, const char *ospath, FsThread thread)
{
	fileHandle_t f;
	FILE* fp;

	fp = FS_FileOpenWriteBinary(ospath);
	if (!fp)
	{
		return 0;
	}

	f = FS_HandleForFile(filename, thread);
	fsh[f].zipFile = NULL;
	fsh[f].handleFiles.file.o = fp;

	I_strncpyz(fsh[f].name, filename, sizeof(fsh[f].name));
	fsh[f].handleSync = 0;

	return f;
}

/*
==============
FS_FOpenFileWriteToDirForThread
==============
*/
int FS_FOpenFileWriteToDirForThread(const char *filename, const char *dir, FsThread thread)
{
	char ospath[256];
	const char* basepath;

	FS_CheckFileSystemStarted();

	basepath = Dvar_GetString(fs_homepath);
	FS_BuildOSPath(basepath, dir, filename, ospath);

	if (Dvar_GetInt(fs_debug))
	{
		Com_Printf(CON_CHANNEL_FILES, "FS_FOpenFileWriteToDirForThread: %s\n", ospath);
	}

	if (FS_CreatePath(ospath))
	{
		return 0;
	}

	return FS_GetHandleAndOpenFile(filename, ospath, thread);
}

/*
==============
FS_FOpenFileWriteToDir
==============
*/
int FS_FOpenFileWriteToDir(const char *filename, const char *dir)
{
	return FS_FOpenFileWriteToDirForThread(filename, dir, FS_THREAD_MAIN);
}

/*
==============
FS_FOpenFileWrite
==============
*/
int FS_FOpenFileWrite(const char *filename)
{
	return FS_FOpenFileWriteToDirForThread(filename, fs_gamedir, FS_THREAD_MAIN);
}

/*
==============
FS_FOpenFileWriteCurrentThread
==============
*/
int FS_FOpenFileWriteCurrentThread(const char *filename, const char *dir)
{
	FsThread thread;

	if (Sys_IsMainThread())
	{
		thread = FS_THREAD_MAIN;
		return FS_FOpenFileWriteToDirForThread(filename, dir, thread);
	}
	if (Sys_IsDatabaseThread())
	{
		thread = FS_THREAD_DATABASE;
		return FS_FOpenFileWriteToDirForThread(filename, dir, thread);
	}
	if (Sys_IsStreamThread())
	{
		thread = FS_THREAD_STREAM;
		return FS_FOpenFileWriteToDirForThread(filename, dir, thread);
	}
	if (Sys_IsRenderThread())
	{
		thread = FS_THREAD_BACKEND;
		return FS_FOpenFileWriteToDirForThread(filename, dir, thread);
	}
	if (Sys_IsServerThread())
	{
		thread = FS_THREAD_SERVER;
		return FS_FOpenFileWriteToDirForThread(filename, dir, thread);
	}
	Com_PrintError(1, "FS_FOpenFileWriteCurrentThread for an unknown thread\n");
	return 0;
}

/*
==============
FS_FOpenTextFileWrite
==============
*/
int FS_FOpenTextFileWrite(const char* filename)
{
	char ospath[256];
	const char* basepath;
	FILE* f;
	int h;

	h = 0;
	FS_CheckFileSystemStarted();

	basepath = Dvar_GetString(fs_homepath);
	FS_BuildOSPath(basepath, fs_gamedir, filename, ospath);
	if (Dvar_GetInt(fs_debug))
	{
		Com_Printf(CON_CHANNEL_FILES, "FS_FOpenTextFileWrite: %s\n", ospath);
	}

	if (FS_CreatePath(ospath))
	{
		return 0;
	}

	f = FS_FileOpenWriteText(ospath);
	if (!f)
	{
		return 0;
	}

	h = FS_HandleForFileCurrentThread(filename);
	fsh[h].zipFile = NULL;
	fsh[h].handleFiles.file.o = f;
	I_strncpyz(fsh[h].name, filename, sizeof(fsh[h].name));
	fsh[h].handleSync = 0;

	if (!fsh[h].handleFiles.file.o)
	{
		FS_FCloseFile(h);
		h = 0;
	}

	return h;
}

/*
==============
FS_FOpenFileAppend
==============
*/
int FS_FOpenFileAppend(const char* filename)
{
	char ospath[256];
	const char* basepath;
	FILE* f;
	int h;

	h = 0;
	FS_CheckFileSystemStarted();
	basepath = Dvar_GetString(fs_homepath);
	FS_BuildOSPath(basepath, fs_gamedir, filename, ospath);
	if (Dvar_GetInt(fs_debug))
	{
		Com_Printf(CON_CHANNEL_FILES, "FS_FOpenFileAppend: %s\n", ospath);
	}

	if (FS_CreatePath(ospath))
	{
		return 0;
	}

	f = FS_FileOpenAppendText(ospath);
	if (!f)
	{
		return 0;
	}

	h = FS_HandleForFileCurrentThread(filename);
	fsh[h].zipFile = NULL;
	I_strncpyz(fsh[h].name, filename, sizeof(fsh[h].name));
	fsh[h].handleFiles.file.o = f;
	fsh[h].handleSync = 0;

	if (!fsh[h].handleFiles.file.o)
	{
		FS_FCloseFile(h);
		h = 0;
	}

	return h;
}

/*
==============
FS_FilenameCompare
==============
*/
int FS_FilenameCompare(const char *s1, const char *s2)
{
	int c1, c2;

	do
	{
		c1 = *s1++;
		c2 = *s2++;

		if (I_islower(c1))
		{
			c1 -= ('a' - 'A');
		}
		if (I_islower(c2))
		{
			c2 -= ('a' - 'A');
		}

		if (c1 == '\\' || c1 == ':')
		{
			c1 = '/';
		}
		if (c2 == '\\' || c2 == ':')
		{
			c2 = '/';
		}

		if (c1 != c2)
		{
			return -1;      // strings not equal
		}
	} while (c1);

	return 0;       // strings are equal
}

/*
==============
FS_PureIgnoreFiles
==============
*/
BOOL FS_PureIgnoreFiles(const char *filename)
{
	const char* extension;

	if (!I_stricmp(filename, "ban.txt"))
		return 1;

	extension = Com_GetExtensionSubString(filename);
	if (*extension == '.')
		++extension;

	if (!I_stricmp(extension, "cfg"))
		return 1;

	return I_stricmp(extension, ".dm_NETWORK_PROTOCOL_VERSION") == 0;
}

/*
==============
FS_IsBackupSubStr
==============
*/
inline char FS_IsBackupSubStr(const char* filenameSubStr)
{
	if (*filenameSubStr == 46 && filenameSubStr[1] == 46)
	{
		return 1;
	}
	if (*filenameSubStr != 58 || filenameSubStr[1] != 58)
	{
		return 0;
	}
	return 1;
}

/*
==============
FS_SanitizeFilename
==============
*/
bool FS_SanitizeFilename(const char *filename, char *sanitizedName, int sanitizedNameSize)
{
	int srcIndex;
	int dstIndex;

	assert(filename);
	assert(sanitizedName);
	assertMsg((sanitizedNameSize > 0), "(sanitizedNameSize) = %i", sanitizedNameSize);
	for (srcIndex = 0; ; ++srcIndex)
	{
		if (!(filename[srcIndex] == '/' || filename[srcIndex] == '\\'))
		{
			break;
		}
	}

	dstIndex = 0;
	while (filename[srcIndex])
	{
		if (FS_IsBackupSubStr(&filename[srcIndex]))
		{
			return 0;
		}

		if (filename[srcIndex] != '.' || (filename[srcIndex + 1] != 0 &&
			filename[srcIndex + 1] != '/' && filename[srcIndex + 1] != '\\'))
		{
			if (dstIndex + 1 >= sanitizedNameSize)
			{
				assertMsg(dstIndex + 1 < sanitizedNameSize, va("%i + 1 > %i", dstIndex, sanitizedNameSize));
				return 0;
			}

			if (filename[srcIndex] == '/' || filename[srcIndex] == '\\')
			{
				sanitizedName[dstIndex] = '/';
				while (1)
				{
					if (!(filename[srcIndex + 1] == '/' || filename[srcIndex + 1] == '\\'))
					{
						break;
					}
					++srcIndex;
				}
			}
			else
			{
				sanitizedName[dstIndex] = filename[srcIndex];
			}
			++dstIndex;
		}
		++srcIndex;
	}

	assertMsg(!(dstIndex > srcIndex), "dstIndex <= srcIndex\n\t%i, %i", dstIndex, srcIndex)

	sanitizedName[dstIndex] = 0;
	return 1;
}

/*
==============
FS_FilesAreLoadedGlobally
==============
*/
bool FS_FilesAreLoadedGlobally(const char *filename)
{
	const char* extensions[7] = { ".hlsl", ".txt", ".cfg", ".levelshots", ".menu", ".str", "" };
	int filenameLen;
	int extensionNum;

	filenameLen = strlen(filename);

	for (extensionNum = 0; *extensions[extensionNum]; ++extensionNum)
	{
		if (!I_stricmp(&filename[filenameLen - strlen(extensions[extensionNum])], extensions[extensionNum]))
		{
			return 1;
		}
	}

	return 0;
}

/*
==============
FS_Delete
==============
*/
BOOL FS_Delete(const char *filename)
{
	char ospath[256];
	const char* basepath;

	FS_CheckFileSystemStarted();
	assert(filename);
	if (!*filename)
	{
		return 0;
	}

	basepath = Dvar_GetString(fs_homepath);
	FS_BuildOSPath(basepath, fs_gamedir, filename, ospath);

	return remove(ospath) != -1;
}

/*
==============
FS_Read
==============
*/
int FS_Read(void *buffer, int len, int h)
{
	int tries;
	unsigned int remaining;
	char* buf;
	FILE* f;
	int read;

	FS_CheckFileSystemStarted();
	if (!h)
	{
		return 0;
	}

	if (fsh[h].zipFile)
	{
		return unzReadCurrentFile(fsh[h].handleFiles.file.z, buffer, len);
	}

	f = FS_FileForHandle(h);
	buf = (char*)buffer;
	remaining = len;
	tries = 0;

	while (remaining)
	{
		read = FS_FileRead(buf, remaining, f);
		if (!read)
		{
			if (tries)
			{
				return len - remaining;
			}
			tries = 1;
		}

		if (read == -1)
		{
			if (h >= 50 && h < 61)
			{
				return -1;
			}
			Com_Error(ERR_FATAL, "\x15" "FS_Read: -1 bytes read");
		}

		remaining -= read;
		buf += read;
	}

	return len;
}

/*
==============
FS_Write
==============
*/
int FS_Write(const void *buffer, int len, int h)
{
	int tries;
	unsigned int remaining;
	char* buf;
	int written;
	FILE* f;

	FS_CheckFileSystemStarted();
	if (!h)
	{
		return 0;
	}

	f = FS_FileForHandle(h);
	buf = (char*)buffer;
	remaining = len;
	tries = 0;
	while (remaining)
	{
		written = FS_FileWrite(buf, remaining, f);
		if (!written)
		{
			if (tries)
			{
				return 0;
			}
			tries = 1;
		}

		if (written == -1)
		{
			return 0;
		}

		remaining -= written;
		buf += written;
	}

	if (fsh[h].handleSync)
	{
		fflush(f);
	}
	return len;
}

/*
==============
FS_WriteToDemo
==============
*/
int FS_WriteToDemo(const void *buffer, int len, int h)
{
	return FS_Write(buffer, len, h);
}

/*
==============
FS_Printf
==============
*/
void FS_Printf(int h, const char *fmt, ...)
{
	char msg[4096];
	va_list va;

	va_start(va, fmt);
	_vsnprintf(msg, sizeof(msg), fmt, va);
	va_end(va);

	FS_Write(msg, strlen(msg), h);
}

/*
==============
FS_Seek
==============
*/
int FS_Seek(int f, int offset, int origin)
{
	int iZipPos;
	unsigned int iZipOffset;

	FS_CheckFileSystemStarted();
	assert(!fsh[f].streamed);
	if (!fsh[f].zipFile)
	{
		return FS_FileSeek(FS_FileForHandle(f), offset, origin);
	}

	if (offset == 0 && origin == 2)
	{
		// set the file position in the zip file (also sets the current file info)
		unzSetCurrentFileInfoPosition(fsh[f].handleFiles.file.z, fsh[f].zipFilePos);
		return unzOpenCurrentFile(fsh[f].handleFiles.file.z);
	}

	if (!offset && !origin)
	{
		return 0;
	}

	iZipPos = unztell(fsh[f].handleFiles.file.z);
	switch (origin)
	{
	case 0:
		assert(offset != 0);
		if (offset >= 0)
		{
			iZipOffset = offset;
		}
		else
		{
			unzSetCurrentFileInfoPosition(fsh[f].handleFiles.file.z, fsh[f].zipFilePos);
			unzOpenCurrentFile(fsh[f].handleFiles.file.z);
			iZipOffset = offset + iZipPos;
		}

		if (unzReadCurrentFile(fsh[f].handleFiles.file.z, NULL, iZipOffset))
		{
			return 0;
		}

		return -1;
	case 1:
		if (offset + FS_filelength(f) >= iZipPos)
		{
			iZipOffset = offset + FS_filelength(f) - iZipPos;
		}
		else
		{
			unzSetCurrentFileInfoPosition(fsh[f].handleFiles.file.z, fsh[f].zipFilePos);
			unzOpenCurrentFile(fsh[f].handleFiles.file.z);
			iZipOffset = offset + FS_filelength(f);
		}
		if (unzReadCurrentFile(fsh[f].handleFiles.file.z, NULL, iZipOffset))
		{
			return 0;
		}

		return -1;
	case 2:
		if (offset >= iZipPos)
		{
			iZipOffset = offset - iZipPos;
		}
		else
		{
			unzSetCurrentFileInfoPosition(fsh[f].handleFiles.file.z, fsh[f].zipFilePos);
			unzOpenCurrentFile(fsh[f].handleFiles.file.z);
			iZipOffset = offset;
		}
		if (unzReadCurrentFile(fsh[f].handleFiles.file.z, NULL, iZipOffset))
		{
			return 0;
		}

		return -1;
	}

	assertMsg(va("Bad origin %i in FS_Seek", origin));
	return -1;
}

/*
==============
FS_ResetFiles
==============
*/
void FS_ResetFiles()
{
	fs_loadStack = 0;
}

/*
==============
FS_WriteFile
==============
*/
int FS_WriteFile(const char* filename, const void* buffer, int size)
{
	int actualSize;
	fileHandle_t f;

	FS_CheckFileSystemStarted();
	assert(filename);
	assert(buffer);

	f = FS_FOpenFileWrite(filename);
	if (!f)
	{
		Com_Printf(CON_CHANNEL_FILES, "Failed to open %s\n", filename);
		return 0;
	}

	actualSize = FS_Write(buffer, size, f);
	FS_FCloseFile(f);
	if (actualSize != size)
	{
		FS_Delete(filename);
		return 0;
	}

	return 1;
}

/*
==============
FS_GetFileOsPath
==============
*/
int FS_GetFileOsPath(const char *filename, char *ospath)
{
	char sanitizedName[256];
	directory_t* dir;
	searchpath_s* search;
	FILE* fp;

	assert(filename);
	assert(ospath);
	if (!FS_SanitizeFilename(filename, sanitizedName, 256))
	{
		return -1;
	}

	for (search = fs_searchpaths; search; search = search->next)
	{
		if (FS_UseSearchPath(search))
		{
			if (!search->iwd)
			{
				dir = search->dir;
				FS_BuildOSPathForThread(dir->path, dir->gamedir, sanitizedName, ospath, FS_THREAD_MAIN);
				fp = FS_FileOpenReadBinary(ospath);

				if (fp)
				{
					FS_FileClose(fp);

					return 0;
				}
			}
		}
	}
	return -1;
}

/*
==============
FS_OpenFileOverwrite
==============
*/
int FS_OpenFileOverwrite(const char* qpath)
{
	DWORD oldAttr;
	char ospath[256];
	unsigned int attributes;

	FS_CheckFileSystemStarted();
	assert(qpath);
	if (FS_GetFileOsPath(qpath, ospath) < 0)
	{
		Com_Error(
			ERR_DROP,
			"FS_FOpenFileOverWrite: Failed to open %s for writing.  It either does not exist or is in a iwd file.",
			qpath);
	}

	if (Dvar_GetInt(fs_debug))
	{
		Com_Printf(CON_CHANNEL_FILES, "FS_FOpenFileOverWrite: %s\n", ospath);
	}

	oldAttr = GetFileAttributesA(ospath);
	attributes = oldAttr & 0xFFFFFFFE;
	if (attributes != oldAttr)
	{
		SetFileAttributesA(ospath, attributes);
	}

	return FS_GetHandleAndOpenFile(qpath, ospath, FS_THREAD_MAIN);
}

/*
==============
FS_ReturnPath
==============
*/
int FS_ReturnPath(const char *zname, char *zpath, int *depth)
{
	int at;
	int len;
	int newdep;

	newdep = 0;
	zpath[0] = 0;
	len = 0;
	at = 0;

	while (zname[at] != 0)
	{
		if (zname[at] == '/' || zname[at] == '\\')
		{
			len = at;
			newdep++;
		}
		at++;
	}

	strcpy(zpath, zname);
	zpath[len] = 0;
	if (len + 1 == at)
	{
		--newdep;
	}
	*depth = newdep;

	return len;
}

/*
==============
FS_AddFileToList
==============
*/
int FS_AddFileToList(HunkUser *user, const char *name, const char **list, int nfiles)
{
	int i;

	if (nfiles == 0x3FFF)
	{
		return nfiles;
	}
	for (i = 0; i < nfiles; ++i)
	{
		if (!I_stricmp(name, list[i]))
		{
			return nfiles;      // allready in list
		}
	}

	list[nfiles] = Hunk_CopyString(user, name);
	nfiles++;

	return nfiles;
}

/*
==============
FS_FreeFileList
==============
*/
inline void FS_FreeFileList(const char** list)
{
	if (list)
	{
		Hunk_UserDestroy((HunkUser*)*(list - 1));
	}
}

/*
==============
FS_ListFilteredFiles
==============
*/
const char **FS_ListFilteredFiles(searchpath_s *searchPath, const char *path, const char *extension, const char *filter, FsListBehavior_e behavior, int *numfiles)
{
	const char** result;
	char netpath[256];
	int numSysFiles;
	char** sysFiles;
	char szTrimmedName[64];
	int depth;
	char* name;
	int zpathLen;
	int pathDepth;
	iwd_t* iwd;
	char zpath[256];
	bool isDirSearch;
	const char** list;
	int extensionLength;
	int nfiles;
	int pathLength;
	fileInIwd_s* buildBuffer;
	HunkUser* user;
	int temp;
	char sanitizedPath[256];
	searchpath_s* search;
	int i;
	int length;

	FS_CheckFileSystemStarted();
	if (!path)
	{
		*numfiles = 0;
		return 0;
	}

	if (!extension)
	{
		extension = "";
	}

	if (!FS_SanitizeFilename(path, sanitizedPath, sizeof(sanitizedPath)))
	{
		*numfiles = 0;
		return 0;
	}

	isDirSearch = I_stricmp(extension, "/") == 0;
	pathLength = strlen(sanitizedPath);
	if (pathLength && path[pathLength - 1] == '\\' || path[pathLength - 1] == '/')
	{
		--pathLength;
	}

	extensionLength = strlen(extension);
	nfiles = 0;
	FS_ReturnPath(sanitizedPath, zpath, &pathDepth);
	if (sanitizedPath[0])
	{
		++pathDepth;
	}

	user = Hunk_UserCreate(0x20000, HU_SCHEME_DEFAULT, 0, NULL, "FS_ListFilteredFiles", 3);
	list = (const char**)Hunk_UserAlloc(user, 65540, 4, NULL);
	*list = (const char*)user;
	++list;

	//
	// search through the path, one element at a time, adding to list
	//
	for (search = searchPath; search; search = search->next)
	{
		if (FS_UseSearchPath(search))
		{
			// is the element a iwd file?
			if (search->iwd)
			{
				if ((!search->bLocalized || !Dvar_GetBool(fs_ignoreLocalized)) && !FS_IwdIsPure(search->iwd))
				{
					continue;
				}

				// look through all the pak file elements
				iwd = search->iwd;
				buildBuffer = iwd->buildBuffer;
				for (i = 0; i < iwd->numFiles; ++i)
				{
					// check for directory match
					name = buildBuffer[i].name;
					//
					if (filter)
					{
						if (Com_FilterPath(filter, name, 0))
						{
							// unique the match
							nfiles = FS_AddFileToList(user, name, list, nfiles);
						}
						continue;
					}

					zpathLen = FS_ReturnPath(name, zpath, &depth);
					if (depth == pathDepth
						&& pathLength <= zpathLen
						&& (pathLength <= 0 || name[pathLength] == 47)
						&& !I_strnicmp(name, sanitizedPath, pathLength))
					{
						if (!isDirSearch)
						{
							if (extensionLength)
							{
								length = strlen(name);
								if (length <= extensionLength
									|| name[length - extensionLength - 1] != 46
									|| I_stricmp(&name[length - extensionLength], extension))
								{
									continue;
								}
							}
							temp = pathLength;
							if (pathLength)
							{
								++temp;
							}

							if (isDirSearch)
							{
								strcpy(szTrimmedName, name + temp);
								szTrimmedName[strlen(szTrimmedName) - 1] = 0;
								nfiles = FS_AddFileToList(user, szTrimmedName, list, nfiles);
							}
							else
							{
								nfiles = FS_AddFileToList(user, name + temp, list, nfiles);
							}
							continue;
						}

						assert(extensionLength == 1);
						assert(extension[0] == '/' && extension[1] == '\\0');
						if (name[strlen(name) - 1] == 47)
						{
							temp = pathLength;
							if (pathLength)
							{
								++temp;
							}

							if (isDirSearch)
							{
								strcpy(szTrimmedName, name + temp);
								szTrimmedName[strlen(szTrimmedName) - 1] = 0;
								nfiles = FS_AddFileToList(user, szTrimmedName, list, nfiles);
							}
							else
							{
								nfiles = FS_AddFileToList(user, name + temp, list, nfiles);
							}
							continue;
						}
					}
				}
			}
			else if (search->dir && (!Dvar_GetBool(fs_restrict) && !fs_numServerIwds || behavior))
			{
				FS_BuildOSPath(search->dir->path, search->dir->gamedir, sanitizedPath, netpath);
				sysFiles = Sys_ListFiles(netpath, extension, filter, &numSysFiles, isDirSearch);
				for (i = 0; i < numSysFiles; ++i)
				{
					nfiles = FS_AddFileToList(user, sysFiles[i], list, nfiles);
				}
				FS_FreeFileList((const char**)sysFiles);
			}
		}
	}

	// return a copy of the list
	*numfiles = nfiles;
	if (!nfiles)
	{
		Hunk_UserDestroy(user);
		return NULL;
	}

	list[nfiles] = NULL;
	return list;
}

/*
==============
FS_CheckLocation
==============
*/
bool FS_CheckLocation(const char *path, int lookInFlags)
{
	return lookInFlags == 63 || (lookInFlags & 1) != 0 && !I_strncmp(path, "main", 4) || (lookInFlags & 2) != 0 && !I_strncmp(path, "dev", 3) || (lookInFlags & 4) != 0 && !I_strncmp(path, "temp", 4) || (lookInFlags & 8) != 0 && !I_strncmp(path, "raw", 3) || (lookInFlags & 0x10) != 0 && !I_strncmp(path, "raw_shared", 10) || (lookInFlags & 0x20) != 0 && !I_strncmp(path, "devraw", 6);
}

/*
==============
FS_GetFileList
==============
*/
int FS_GetFileList(const char *path, const char *extension, FsListBehavior_e behavior, char *listbuf, int bufsize)
{
	const char** fileNames;
	int nLen;
	int nTotal;
	int i;
	int fileCount;

	*listbuf = 0;
	fileCount = 0;
	nTotal = 0;
	if (!I_stricmp(path, "$modlist"))
	{
		return FS_GetModList(listbuf, bufsize);
	}

	fileNames = FS_ListFilteredFiles(fs_searchpaths, path, extension, 0, behavior, &fileCount);
	for (i = 0; i < fileCount; ++i)
	{
		nLen = strlen(fileNames[i]) + 1;
		if (nTotal + nLen + 1 >= bufsize)
		{
			fileCount = i;
			break;
		}

		strcpy(listbuf, fileNames[i]);
		listbuf += nLen;
		nTotal += nLen;
	}

	FS_FreeFileList(fileNames);
	return fileCount;
}

/*
==============
FS_ConvertPath
==============
*/
void FS_ConvertPath(char *s)
{
	while (*s)
	{
		if (*s == '\\' || *s == ':')
		{
			*s = '/';
		}
		s++;
	}
}

/*
==============
FS_PathCmp

==============
*/
inline int FS_PathCmp(const char* s1, const char* s2)
{
	int c2;
	int c1;

	do
	{
		c1 = *s1++;
		c2 = *s2++;

		if (I_islower(c1))
		{
			c1 -= ('a' - 'A');
		}
		if (I_islower(c2))
		{
			c2 -= ('a' - 'A');
		}
		if (c1 == '\\' || c1 == ':')
		{
			c1 = '/';
		}
		if (c2 == '\\' || c2 == ':')
		{
			c2 = '/';
		}

		if (c1 < c2)
		{
			return -1;      // strings not equal
		}
		if (c1 > c2)
		{
			return 1;
		}
	} while (c1);

	return 0;       // strings are equal
}

/*
==============
FS_SortFileList
==============
*/
void FS_SortFileList(const char **filelist, int numfiles)
{
	int j;
	int k;
	int numsortedfiles;
	int i;
	const char** sortedlist;

	sortedlist = (const char**)Z_Malloc((numfiles + 1) * sizeof(*sortedlist), "FS_SortFileList", 3);
	sortedlist[0] = NULL;
	numsortedfiles = 0;
	for (i = 0; i < numfiles; ++i)
	{
		for (j = 0; j < numsortedfiles; j++)
		{
			if (FS_PathCmp(filelist[i], sortedlist[j]) < 0)
			{
				break;
			}
		}

		for (k = numsortedfiles; k > j; --k)
		{
			sortedlist[k] = sortedlist[k - 1];
		}
		sortedlist[j] = filelist[i];
		numsortedfiles++;
	}

	Com_Memcpy(filelist, sortedlist, numfiles * sizeof(*filelist));
	Z_Free(sortedlist, 3);
}

/*
==============
FS_DisplayPath
==============
*/
void FS_DisplayPath(int bLanguageCull)
{
	int iLanguage;
	const char* pszLanguageName;
	searchpath_s* s;
	int i;

	iLanguage = SEH_GetCurrentLanguage();
	pszLanguageName = SEH_GetLanguageName(iLanguage);
	Com_Printf(CON_CHANNEL_FILES, "Current language: %s\n", pszLanguageName);
	if (fs_ignoreLocalized->current.enabled)
	{
		Com_Printf(CON_CHANNEL_FILES, "    localized assets are being ignored\n");
	}

	Com_Printf(CON_CHANNEL_FILES, "Current search path:\n");
	for (s = fs_searchpaths; s; s = s->next)
	{
		if (!bLanguageCull || FS_UseSearchPath(s))
		{
			if (s->iwd)
			{
				Com_Printf(CON_CHANNEL_FILES, "%s (%i files)\n", s->iwd, s->iwd->numFiles);
				if (s->bLocalized)
				{
					Com_Printf(CON_CHANNEL_FILES, "    localized assets iwd file for %s\n", SEH_GetLanguageName(s->language));
				}

				if (fs_numServerIwds)
				{
					if (FS_IwdIsPure(s->iwd))
					{
						Com_Printf(CON_CHANNEL_FILES, "    on the pure list\n");
					}
					else
					{
						Com_Printf(CON_CHANNEL_FILES, "    not on the pure list\n");
					}
				}
			}
			else
			{
				Com_Printf(CON_CHANNEL_FILES, "%s/%s\n", s->dir, s->dir->gamedir);
				if (s->bLocalized)
				{
					Com_Printf(CON_CHANNEL_FILES, "    localized assets game folder for %s\n", SEH_GetLanguageName(s->language));
				}
			}
		}
	}

	Com_Printf(CON_CHANNEL_FILES, "\nFile Handles:\n");
	for (i = 1; i < 70; ++i)
	{
		if (fsh[i].handleFiles.file.o)
		{
			Com_Printf(CON_CHANNEL_FILES, "handle %i: %s\n", i, fsh[i].name);
		}
	}
}

/*
==============
FS_FullPath_f
==============
*/
void FS_FullPath_f()
{
	FS_DisplayPath(0);
}

/*
==============
FS_Path_f
==============
*/
void FS_Path_f()
{
	FS_DisplayPath(1);
}

/*
==============
FS_AddSearchPath
==============
*/
inline void FS_AddSearchPath(searchpath_s* search)
{
	searchpath_s** pSearch;

	pSearch = &fs_searchpaths;
	if (search->bLocalized)
	{
		while (*pSearch && !(*pSearch)->bLocalized)
		{
			pSearch = (searchpath_s**)*pSearch;
		}
	}
	search->next = *pSearch;
	*pSearch = search;
}

/*
==============
FS_AddGameDirectory
==============
*/
void FS_AddGameDirectory(const char *path, const char *dir, int bLanguageDirectory, int iLanguage)
{
	const char* locText;
	char ospath[256];
	const char* pszLanguage;
	char szGameFolder[64];
	searchpath_s* search;
	searchpath_s* i;

	if (bLanguageDirectory)
	{
		pszLanguage = SEH_GetLanguageName(iLanguage);
		Com_sprintf(szGameFolder, sizeof(szGameFolder), "%s/%s", dir, pszLanguage);
	}
	else
	{
		I_strncpyz(szGameFolder, dir, sizeof(szGameFolder));
	}

	for (i = fs_searchpaths; i; i = i->next)
	{
		if (i->dir && !I_stricmp(i->dir->path, path) && !I_stricmp(i->dir->gamedir, szGameFolder))
		{
			if (i->bLocalized != bLanguageDirectory)
			{
				Com_PrintWarning(10,
					"WARNING: game folder %s/%s added as both localized & non-localized. Using folder as %s\n",
					path, szGameFolder, i->bLocalized ? "localized" : "non-localized");
			}

			if (i->bLocalized)
			{
				if (i->language != iLanguage)
				{
					Com_PrintWarning(10,
						"WARNING: game folder %s/%s re-added as localized folder with different language\n",
						path, szGameFolder);
				}
			}
			return;
		}
	}

	if (bLanguageDirectory)
	{
		// find all iwd files in this directory
		FS_BuildOSPath(path, szGameFolder, "", ospath);
		ospath[strlen(ospath) - 1] = 0; // strip the trailing slash
		if (!Sys_DirectoryHasContents(ospath))
		{
			return;
		}
	}
	else
	{
		I_strncpyz(fs_gamedir, szGameFolder, sizeof(fs_gamedir));
	}

	//
	// add the directory to the search path
	//
	search = (searchpath_s*)Z_Malloc(sizeof(searchpath_s), "FS_AddGameDirectory", 3);
	search->dir = (directory_t*)Z_Malloc(sizeof(*search->dir), "FS_AddGameDirectory", 3);

	I_strncpyz(search->dir->path, path, sizeof(search->dir->path));
	I_strncpyz(search->dir->gamedir, szGameFolder, sizeof(search->dir->gamedir));

	assert(bLanguageDirectory || (!bLanguageDirectory && !iLanguage));
	search->bLocalized = bLanguageDirectory;
	search->language = iLanguage;
	if (fs_usedevdir->current.enabled)
	{
		search->ignore = 0;
		search->ignorePureCheck = 1;
	}
	else
	{
		search->ignore = I_stricmp(dir, "main") == 0;
		search->ignorePureCheck = !I_stricmp(dir, "players") || !I_stricmp(dir, "demos");
	}

	FS_AddSearchPath(search);
	// FS_AddIwdFilesForGameDirectory(path, szGameFolder);
}

/*
==============
FS_AddLocalizedGameDirectory
==============
*/
void FS_AddLocalizedGameDirectory(const char *path, const char *dir)
{
	int i;

	for (i = 12; i >= 0; --i)
	{
		FS_AddGameDirectory(path, dir, 1, i);
	}

	FS_AddGameDirectory(path, dir, 0, 0);
}

/*
==============
FS_ShutdownSearchPaths
==============
*/
void FS_ShutdownSearchPaths(searchpath_s *p)
{
	searchpath_s* next;

	while (p)
	{
		next = p->next;
		if (p->iwd)
		{
			unzClose(p->iwd->handle);
			Z_Free(p->iwd->buildBuffer, 3);
			Z_Free(p->iwd, 3);
		}
		if (p->dir)
		{
			Z_Free(p->dir, 3);
		}
		Z_Free(p, 3);
		p = next;
	}
}

/*
==============
FS_ShutdownServerFileReferences
==============
*/
void FS_ShutdownServerFileReferences(int *numFiles, const char **fileNames)
{
	int i;

	for (i = 0; i < *numFiles; ++i)
	{
		if (fileNames[i])
		{
			FreeString(fileNames[i]);
			fileNames[i] = NULL;
		}
	}
	*numFiles = 0;
}

/*
==============
FS_ShutdownServerIwdNames
==============
*/
void FS_ShutdownServerIwdNames()
{
	FS_ShutdownServerFileReferences(&fs_numServerIwds, fs_serverIwdNames);
}

/*
==============
FS_ShutdownServerReferencedIwds
==============
*/
void FS_ShutdownServerReferencedIwds()
{
	FS_ShutdownServerFileReferences(&fs_numServerReferencedIwds, fs_serverReferencedIwdNames);
}

/*
==============
FS_ShutdownServerReferencedFFs
==============
*/
void FS_ShutdownServerReferencedFFs()
{
	FS_ShutdownServerFileReferences(&fs_numServerReferencedFFs, fs_serverReferencedFFNames);
}

/*
==============
FS_Shutdown
==============
*/
void FS_Shutdown()
{
	int i;

	SEH_Shutdown_StringEd();
	for (i = 1; i < 70; ++i)
	{
		if (fsh[i].fileSize)
		{
			FS_FCloseFile(i);
		}
	}

	FS_ShutdownSearchPaths(fs_searchpaths);
	fs_searchpaths = NULL;
	FS_RemoveCommands();
}

/*
==============
FS_GetOsFolderPath

==============
*/
inline char* FS_GetOsFolderPath(int folder, char* ospath)
{
	char buffer[1024];

	assert(CSIDL_LOCAL_APPDATA == folder || CSIDL_PERSONAL == folder);

	SHGetFolderPathA(NULL, folder | 0x8000, NULL, 0, buffer);
	I_strncpyz(ospath, buffer, 256);
	I_strncat(ospath, 256, "\\Activision\\CoD");

	return ospath;
}

/*
==============
FS_RegisterDvars
==============
*/
void FS_RegisterDvars()
{
	const char* homePath;
	static char ospathPersonalDocuments[256];
	bool fs_usedevdir_default;

	fs_debug = _Dvar_RegisterInt("fs_debug", 0, 0, 2, 0, "Enable file system debugging information");
	fs_copyfiles = _Dvar_RegisterBool("fs_copyfiles", 0, 0x10u, "Copy all used files to another location");
	fs_cdpath = _Dvar_RegisterString("fs_cdpath", "", 0x10u, "CD path");
	fs_basepath = _Dvar_RegisterString("fs_basepath", Sys_Cwd(), 0x210u, "Base game path");
	fs_basegame = _Dvar_RegisterString("fs_basegame", "", 0x10u, "Base game name");
	fs_gameDirVar = _Dvar_RegisterString("fs_game", "", 0x114u,
		"Game data directory. Must be \"\" or a sub directory of 'mods/'.");
	fs_usermapDir = _Dvar_RegisterString("fs_usermapdir", "", 0x144u, "Usermap data directory.");
	fs_ignoreLocalized = _Dvar_RegisterBool("fs_ignoreLocalized", 0, 0xA0u, "Ignore localized files");
	homePath = Sys_DefaultHomePath();
	if (!homePath || !*homePath)
	{
		homePath = Dvar_GetResetString(fs_basepath);
	}
	fs_homepath = _Dvar_RegisterString("fs_homepath", homePath, 0x210u, "Game home path");
	FS_GetOsFolderPath(5, ospathPersonalDocuments);
	fs_userDocuments = _Dvar_RegisterString("fs_userDocuments", ospathPersonalDocuments, 0x10u,
		"user documents path(screenshots).");
	fs_restrict = _Dvar_RegisterBool("fs_restrict", 0, 0x10u, "Restrict file access for demos etc.");

	fs_usedevdir_default = Sys_FileExists(va("%s\\raw\\fileSysCheck.cfg", Sys_DefaultInstallPath()));
	fs_usedevdir = _Dvar_RegisterBool("fs_usedevdir", fs_usedevdir_default, 0x10u, "Use development directories.");
}

/*
==============
FS_AddDevGameDirs
==============
*/
void FS_AddDevGameDirs(const char *path, bool allow_devraw)
{
	unsigned int j;
	unsigned int i;
	char devDir[32];
	const char* devDirsOrder[3] = { "raw_shared", "raw", "discdata" };

	assert(Dvar_GetBool(fs_usedevdir) && *path);

	if (allow_devraw)
	{
		strcpy(devDir, "dev");

		for (i = 0; i < 3; ++i)
		{
			I_strncpyz(devDir + 3, devDirsOrder[i], sizeof(devDir) - 3);
			FS_AddLocalizedGameDirectory(path, devDir);
		}
	}

	for (j = 0; j < ARRAY_COUNT(devDirsOrder); ++j)
	{
		FS_AddLocalizedGameDirectory(path, devDirsOrder[j]);
	}
}

/*
==============
FS_Startup
==============
*/
void FS_Startup(const char *gameName, bool allow_devraw)
{
	const char* fs_basepath_string;
	const char* fs_gameDirVar_string;
	const char* fs_basegame_string;
	const char* fs_homepath_string;
	const char* fs_cdpath_string;


	FS_RegisterDvars();

	fs_gameDirVar_string = Dvar_GetString(fs_gameDirVar);
	fs_basegame_string = Dvar_GetString(fs_basegame);
	fs_homepath_string = Dvar_GetString(fs_homepath);
	fs_basepath_string = Dvar_GetString(fs_basepath);
	fs_cdpath_string = Dvar_GetString(fs_cdpath);

	Com_Printf(CON_CHANNEL_FILES, "----- FS_Startup -----\n");

	if (Dvar_GetBool(fs_usedevdir))
	{
		if (fs_basepath_string[0])
		{
			FS_AddDevGameDirs(fs_basepath_string, allow_devraw);
		}
		if (fs_homepath_string[0] && I_stricmp(fs_basepath_string, fs_homepath_string))
		{
			FS_AddDevGameDirs(fs_homepath_string, allow_devraw);
		}
		if (fs_cdpath_string[0] && I_stricmp(fs_basepath_string, fs_cdpath_string))
		{
			FS_AddDevGameDirs(fs_cdpath_string, allow_devraw);
		}
	}

	// add search path elements in reverse priority order
	if (fs_cdpath_string[0] && I_stricmp(fs_basepath_string, fs_cdpath_string))
	{
		FS_AddLocalizedGameDirectory(fs_cdpath_string, gameName);
	}

	if (true)
	{
		if (fs_basepath_string[0])
		{
			FS_AddLocalizedGameDirectory(fs_basepath_string, "players");
			FS_AddGameDirectory(fs_basepath_string, "zone", 0, 0);
			FS_AddGameDirectory(fs_basepath_string, "wads", 0, 0);
		}
		FS_AddGameDirectory(fs_basepath_string, "machinecfg", 0, 0);
	}
	else
	{
		FS_AddLocalizedGameDirectory(fs_basepath_string, "players");
	}

	if (fs_basepath_string[0])
	{
		FS_AddLocalizedGameDirectory(fs_basepath_string, va("%s_shared", gameName));
		FS_AddLocalizedGameDirectory(fs_basepath_string, gameName);
	}
	if (fs_basepath_string[0] && I_stricmp(fs_homepath_string, fs_basepath_string))
	{
		FS_AddLocalizedGameDirectory(fs_basepath_string, va("%s_shared", gameName));
		FS_AddLocalizedGameDirectory(fs_homepath_string, gameName);
	}

	if (fs_basegame->current.string[0]
		&& !I_stricmp(gameName, "main")
		&& I_stricmp(fs_basegame->current.string, gameName)
		&& fs_basepath_string[0])
	{
		FS_AddGameDirectory(fs_basepath_string, fs_basegame->current.string, 0, 0);
	}

	if (fs_gameDirVar->current.string[0]
		&& !I_stricmp(gameName, "main")
		&& I_stricmp(fs_gameDirVar->current.string, gameName)
		&& fs_basepath_string[0])
	{
		FS_AddGameDirectory(fs_basepath_string, "usermaps", 0, 0);
		FS_AddGameDirectory(fs_basepath_string, fs_gameDirVar->current.string, 0, 0);
	}

	FS_AddCommands();
	FS_DisplayPath(1);
	Dvar_ClearModified(fs_gameDirVar);
	Com_Printf(15, "----------------------\n");
	Com_Printf(15, "%d files in iwd files\n", fs_iwdFileCount);
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
	for (search = fs_searchpaths; search; search = search->next)
	{
		// is the element an iwd file and has it been referenced?
		if (search->iwd)
		{
			search->iwd->referenced = 0;
		}
	}
}

/*
==============
FS_ShutDownIwdPureCheckReferences
==============
*/
void FS_ShutDownIwdPureCheckReferences()
{
	iwd_pure_check_s* next;
	iwd_pure_check_s* p;

	for (p = fs_iwdPureChecks; p; p = next)
	{
		next = p->next;
		Z_Free(p, 3);
	}

	fs_iwdPureChecks = NULL;
}

/*
==============
FS_InitFilesystem
==============
*/
void FS_InitFilesystem(bool allow_devraw)
{
	Com_StartupVariable("fs_cdpath");
	Com_StartupVariable("fs_basepath");
	Com_StartupVariable("fs_homepath");
	Com_StartupVariable("fs_game");
	Com_StartupVariable("fs_copyfiles");
	Com_StartupVariable("fs_restrict");
	Com_StartupVariable("loc_language");
	SEH_InitLanguage();
	FS_Startup("main", allow_devraw);
	SEH_Init_StringEd();
	SEH_UpdateLanguageInfo();
	FS_SetRestrictions();
}

/*
==============
FS_Restart
==============
*/
void FS_Restart(LocalClientNum_t localClientNum, int checksumFeed)
{
	// free anything we currently have loaded
	FS_Shutdown();

	// set the checksum feed
	fs_checksumFeed = checksumFeed;

	// clear iwd references
	FS_ClearIwdReferences();
	FS_ShutDownIwdPureCheckReferences();
	fs_iwdPureChecks = 0;
	ProfLoad_Begin("Start file system");
	FS_Startup("main", 1);
	ProfLoad_End();
	ProfLoad_Begin("Init text localization");
	SEH_Init_StringEd();
	SEH_UpdateLanguageInfo();
	ProfLoad_End();
	ProfLoad_Begin("Set restrictions");
	FS_SetRestrictions();
	ProfLoad_End();
}

/*
==============
FS_IsInCompressedIwd
==============
*/
BOOL FS_IsInCompressedIwd(int f)
{
	return fsh[f].zipFile && ((unz_s*)fsh[f].handleFiles.file.z)->pfile_in_zip_read->compression_method;
}

/*
==============
FS_Flush
==============
*/
void FS_Flush(int f)
{
	FILE* file;

	file = FS_FileForHandle(f);
	fflush(file);
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
	if (IsUsingMods())
	{
		g_disablePureCheck = disable;
	}
	if (disable)
	{
		FS_ShutdownServerIwdNames();
	}
}

/*
==============
FS_FOpenFileReadForThread
==============
*/
int FS_FOpenFileReadForThread(const char *filename, int *file, FsThread thread, char *outfullpath, int outfullpathsize)
{
	unsigned int result;
	char copypath[256];
	fileInIwd_s* iwdFile;
	int hash;
	iwd_t* iwd;
	char sanitizedName[256];
	directory_t* dir;
	unz_s* zfi;
	iwd_t* impureIwd;
	file_in_zip_read_info_s* ziptemp;
	char netpath[256];
	bool wasSkipped;
	searchpath_s* search;
	FILE* filetemp;

	impureIwd = NULL;
	wasSkipped = 0;
	assert(filename);

	FS_CheckFileSystemStarted();

	if (!FS_SanitizeFilename(filename, sanitizedName, sizeof(sanitizedName)))
	{
		if (file)
		{
			*file = 0;
		}

		if (Dvar_GetInt(fs_debug))
		{
			Com_Printf(CON_CHANNEL_FILES, "fs_debug: %s is invalid or contains and invalid substring\n", filename);
		}

		return -1;
	}

	if (file == NULL)
	{
		// just wants to see if file is there
		for (search = fs_searchpaths; search; search = search->next)
		{
			if (!FS_UseSearchPath(search))
			{
				continue;
			}

			// look through all the iwd file elements
			iwd = search->iwd;
			if (iwd && iwd->numFiles)
			{
				assert(iwd->hashTable && iwd->hashSize);
				hash = FS_HashFileName(sanitizedName, iwd->hashSize);
				for (iwdFile = iwd->hashTable[hash]; iwdFile; iwdFile = iwdFile->next)
				{
					// case and separator insensitive comparisons
					if (!FS_FilenameCompare(iwdFile->name, sanitizedName))
					{
						// found it!
						return 1;
					}
				}
			}
			else if (search->dir)
			{
				dir = search->dir;

				FS_BuildOSPathForThread(dir->path, dir->gamedir, sanitizedName, netpath, thread);
				filetemp = FS_FileOpenReadBinary(netpath);
				if (!filetemp)
				{
					continue;
				}
				FS_FileClose(filetemp);
				return 1;
			}
		}
		return -1;
	}

	//
	// search through the path, one element at a time
	//

	*file = FS_HandleForFile(filename, thread);
	if (!*file)
	{
		return -1;
	}

	for (search = fs_searchpaths; search; search = search->next)
	{
		if (!FS_UseSearchPath(search))
		{
			continue;
		}

		// look through all the iwd file elements
		iwd = search->iwd;
		if (iwd && iwd->numFiles)
		{
			assert(iwd->hashTable && iwd->hashSize);
			hash = FS_HashFileName(sanitizedName, iwd->hashSize);
			for (iwdFile = iwd->hashTable[hash]; iwdFile; iwdFile = iwdFile->next)
			{
				// case and separator insensitive comparisons
				if (!FS_FilenameCompare(iwdFile->name, sanitizedName))
				{
					// found it!

					if (!g_disablePureCheck && !search->bLocalized && !search->ignorePureCheck &&
						!FS_IwdIsPure(iwd))
					{
						impureIwd = iwd;
						break;
					}

					if (!iwd->referenced && !FS_FilesAreLoadedGlobally(sanitizedName))
					{
						iwd->referenced = 1;
						FS_AddIwdPureCheckReference(search);
					}

					if (InterlockedCompareExchange(&iwd->hasOpenFile, 1, 0) == 1)
					{
						// open a new file on the iwdfile
						fsh[*file].handleFiles.iwdIsClone = 1;
						fsh[*file].handleFiles.file.z = (unsigned char*)unzReOpen(iwd->iwdFilename, iwd->handle);
						if (fsh[*file].handleFiles.file.z == NULL)
						{
							if (thread)
							{
								FS_FCloseFile(*file);
								*file = 0;
								return -1;
							}
							Com_Error(ERR_FATAL, "\x15" "Couldn\'t reopen %s", iwd->iwdFilename);
						}
					}
					else
					{
						fsh[*file].handleFiles.iwdIsClone = 0;
						fsh[*file].handleFiles.file.z = iwd->handle;
					}

					I_strncpyz(fsh[*file].name, sanitizedName, sizeof(fsh[*file].name));
					fsh[*file].zipFile = iwd;
					zfi = (unz_s*)fsh[*file].handleFiles.file.z;
					// in case the file was new
					filetemp = zfi->file;
					ziptemp = zfi->pfile_in_zip_read;
					// set the file position in the zip file (also sets the current file info)
					unzSetCurrentFileInfoPosition(iwd->handle, iwdFile->pos);
					// copy the file info into the unzip structure
					Com_Memcpy(zfi, iwd->handle, sizeof(unz_s));
					// we copy this back into the structure
					zfi->file = filetemp;
					zfi->pfile_in_zip_read = ziptemp;
					// open the file in the zip
					unzOpenCurrentFile(fsh[*file].handleFiles.file.z);
					fsh[*file].zipFilePos = iwdFile->pos;

					if (Dvar_GetInt(fs_debug))
					{
						Com_Printf(
							10,
							"FS_FOpenFileReadfrom thread '%s', handle '%d', %s (found in '%s')\n",
							Sys_GetCurrentThreadName(),
							*file,
							sanitizedName,
							iwd->iwdFilename);
					}
					return zfi->cur_file_info.uncompressed_size;
				}
			}
		}
		else if (search->dir)
		{
			// check a file in the directory tree

			if (!search->ignore && !Dvar_GetBool(fs_restrict) && !fs_numServerIwds
				|| search->bLocalized
				|| search->ignorePureCheck
				|| FS_PureIgnoreFiles(sanitizedName))
			{
				dir = search->dir;

				FS_BuildOSPathForThread(dir->path, dir->gamedir, sanitizedName, netpath, thread);
				fsh[*file].handleFiles.file.o = FS_FileOpenReadBinary(netpath);
				if (!fsh[*file].handleFiles.file.o)
				{
					continue;
				}

				if (!search->bLocalized && !search->ignorePureCheck &&
					!FS_PureIgnoreFiles(sanitizedName))
				{
					fs_fakeChkSum = rand() + 1;
				}

				I_strncpyz(fsh[*file].name, sanitizedName, sizeof(fsh[*file].name));
				fsh[*file].zipFile = NULL;
				if (Dvar_GetInt(fs_debug))
				{
					Com_Printf(
						10,
						"FS_FOpenFileRead from thread '%s', handle '%d', %s (found in '%s/%s')\n",
						Sys_GetCurrentThreadName(),
						*file,
						sanitizedName,
						dir,
						dir->gamedir);
				}

				// if we are getting it from the cdpath, optionally copy it
				//  to the basepath
				if (Dvar_GetBool(fs_copyfiles) &&
					!I_stricmp(dir->path, Dvar_GetString(fs_cdpath)))
				{
					FS_BuildOSPathForThread(Dvar_GetString(fs_basepath), dir->gamedir,
						sanitizedName, copypath, thread);
					FS_CopyFile(netpath, copypath);
				}

				return FS_filelength(*file);
			}
			else if (!wasSkipped)
			{
				dir = search->dir;

				FS_BuildOSPathForThread(dir->path, dir->gamedir, sanitizedName, netpath, thread);
				filetemp = FS_FileOpenReadBinary(netpath);
				if (filetemp)
				{
					wasSkipped = 1;
					FS_FileClose(filetemp);
				}
			}
		}
	}

	if (Dvar_GetInt(fs_debug) && thread == FS_THREAD_MAIN)
	{
		Com_Printf(CON_CHANNEL_FILES, "Can't find %s\n", filename);
	}

	FS_FCloseFile(*file);
	*file = 0;
	if (impureIwd)
	{
		Com_Error(ERR_DROP, va("%s\n%s", "Impure client detected. Invalid .IWD files referenced!",
			impureIwd->iwdFilename));
	}

	if (wasSkipped)
	{
		if (fs_numServerIwds || Dvar_GetBool(fs_restrict))
		{
			Com_Printf(CON_CHANNEL_FILES, "Error: %s must be in an IWD\n", filename);
		}
		else
		{
			Com_Printf(CON_CHANNEL_FILES, "Error: %s must be in an IWD or not in the main directory\n",
				filename);
		}
		result = -2;
	}
	else
	{
		result = -1;
	}

	return result;
}

/*
==============
FS_FOpenFileReadCurrentThread
==============
*/
int FS_FOpenFileReadCurrentThread(const char *filename, int *file)
{
	FsThread thread; // eax

	if (Sys_IsMainThread())
	{
		thread = FS_THREAD_MAIN;
		return FS_FOpenFileReadForThread(filename, file, thread, 0, 0);
	}
	if (Sys_IsDatabaseThread())
	{
		thread = FS_THREAD_DATABASE;
		return FS_FOpenFileReadForThread(filename, file, thread, 0, 0);
	}
	if (Sys_IsStreamThread())
	{
		thread = FS_THREAD_STREAM;
		return FS_FOpenFileReadForThread(filename, file, thread, 0, 0);
	}
	if (Sys_IsRenderThread())
	{
		thread = FS_THREAD_BACKEND;
		return FS_FOpenFileReadForThread(filename, file, thread, 0, 0);
	}
	if (Sys_IsServerThread())
	{
		thread = FS_THREAD_SERVER;
		return FS_FOpenFileReadForThread(filename, file, thread, 0, 0);
	}
	Com_PrintError(1, "FS_FOpenFileReadCurrentThread for an unknown thread\n");
	if (file)
		*file = 0;
	return -1;
}

/*
==============
Com_GetBspFilename
==============
*/
void Com_GetBspFilename(char *filename, int size, const char *mapname)
{
	Com_sprintf(filename, size, "maps/mp/%s.d3dbsp", mapname);
}

/*
==============
FS_FOpenFileRead
==============
*/
int FS_FOpenFileRead(const char *filename, int *file)
{
	com_fileAccessed = 1;
	return FS_FOpenFileReadCurrentThread(filename, file);
}

/*
==============
FS_TouchFile
==============
*/
BOOL FS_TouchFile(const char *name)
{
	return FS_FOpenFileRead(name, NULL) != -1;
}

/*
==============
FS_FOpenFileByMode
==============
*/
int FS_FOpenFileByMode(const char *qpath, int *f, fsMode_t mode)
{
	int r;
	int sync;

	sync = 0;
	switch (mode)
	{
	case 0:
		r = FS_FOpenFileRead(qpath, f);
		break;
	case 1:
		*f = FS_FOpenFileWrite(qpath);
		r = 0;
		if (!*f)
		{
			r = -1;
		}
		break;
	case 3:
		sync = 1;
	case 2:
		*f = FS_FOpenFileAppend(qpath);
		r = 0;
		if (!*f)
		{
			r = -1;
		}
		break;
	}

	if (!f)
	{
		return r;
	}

	if (*f)
	{
		fsh[*f].fileSize = r;
		fsh[*f].streamed = 0;
	}

	fsh[*f].handleSync = sync;
	return r;
}

/*
==============
FS_ReadFile
==============
*/
int FS_ReadFile(const char* qpath, void** buffer)
{
	char* buf;
	int len;
	int h;

	FS_CheckFileSystemStarted();
	if (!qpath || !qpath[0])
	{
		Com_Error(ERR_FATAL, "\x15" "FS_ReadFile with empty name\n");
	}

	// look for it in the filesystem or iwd files
	len = FS_FOpenFileReadCurrentThread(qpath, &h);
	if (h == 0)
	{
		if (buffer)
		{
			*buffer = NULL;
		}
		return -1;
	}

	if (buffer)
	{
		++fs_loadStack;
		buf = (char*)Hunk_AllocateTempMemory(len + 1, "FS_AllocMem");
		*buffer = buf;

		FS_Read(buf, len, h);

		// guarantee that it will have a trailing 0 for string operations
		buf[len] = 0;
	}

	FS_FCloseFile(h);
	return len;
}

/*
==============
FS_FreeFile
==============
*/
void FS_FreeFile(void* buffer)
{
	FS_CheckFileSystemStarted();
	assert(buffer);
	--fs_loadStack;
	Hunk_FreeTempMemory(buffer);
}

/*
==============
FS_ListFiles
==============
*/
const char** FS_ListFiles(const char* path, const char* extension, FsListBehavior_e behavior, int* numfiles)
{
	return FS_ListFilteredFiles(fs_searchpaths, path, extension, 0, behavior, numfiles);
}
