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
#include "com_files.h"

#include <zlib/unzip.h>

#include <universal/q_shared.h>
#include <universal/com_fileaccess.h>
#include <universal/com_memory.h>
#include <universal/com_shared.h>
#include <universal/mem_userhunk.h>
#include <universal/dvar.h>
#include <universal/win_common.h>
#include <qcommon/common.h>
#include <qcommon/files.h>
#include <stringed/stringed_hooks.h>

enum FsThread : __int32
{
	FS_THREAD_MAIN = 0x0,
	FS_THREAD_STREAM = 0x1,
	FS_THREAD_DATABASE = 0x2,
	FS_THREAD_BACKEND = 0x3,
	FS_THREAD_SERVER = 0x4,
	FS_THREAD_COUNT = 0x5,
	FS_THREAD_INVALID = 0x6,
};

struct unz_file_info_internal_s
{
	unsigned int offset_curfile;
};

struct fileInIwd_s
{
	unsigned int pos;
	char* name;
	fileInIwd_s* next;
};

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

struct file_in_zip_read_info_s
{
	char* read_buffer;
	z_stream_s stream;
	unsigned int pos_in_zipfile;
	unsigned int stream_initialised;
	unsigned int offset_local_extrafield;
	unsigned int size_local_extrafield;
	unsigned int pos_local_extrafield;
	unsigned int rest_read_compressed;
	unsigned int rest_read_uncompressed;
	FILE* file;
	unsigned int compression_method;
	unsigned int byte_before_the_zipfile;
};

struct unz_s
{
	FILE* file;
	unz_global_info_s gi;
	unsigned int byte_before_the_zipfile;
	unsigned int num_file;
	unsigned int pos_in_central_dir;
	unsigned int current_file_ok;
	unsigned int central_pos;
	unsigned int size_central_dir;
	unsigned int offset_central_dir;
	unz_file_info_s cur_file_info;
	unz_file_info_internal_s cur_file_info_internal;
	file_in_zip_read_info_s* pfile_in_zip_read;
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

typedef struct iwd_pure_check_s
{
	iwd_pure_check_s* next;
	int checksum;
	char iwdBasename[256];
	char iwdGamename[256];
} iwd_pure_check_s;

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

typedef struct directory_t
{
	char path[256];
	char gamedir[256];
} directory_t;

struct searchpath_s
{
	searchpath_s* next;
	iwd_t* iwd;
	directory_t* dir;
	int bLocalized;
	int ignore;
	int ignorePureCheck;
	int language;
};

searchpath_s* fs_searchpaths;
int fs_loadStack;
int fs_serverIwds[1024];
int fs_numServerReferencedIwds;
int fs_numServerReferencedFFs;
int fs_numServerIwds;
int fs_iwdFileCount;
char fs_gamedir[256];
const char* fs_serverIwdNames[1024];
const char* fs_serverReferencedIwdNames[1024];
const char* fs_serverReferencedFFNames[64];
const dvar_t* fs_debug;
const dvar_t* fs_ignoreLocalized;
const dvar_t* fs_homepath;
const dvar_t* fs_restrict;
const dvar_t* fs_usedevdir;
const dvar_t* fs_basepath;
const dvar_t* fs_cdpath;
const dvar_t* fs_basegame;
const dvar_t* fs_gameDirVar;
iwd_pure_check_s* fs_iwdPureChecks;

fileHandleData_t fsh[70];

void TRACK_com_files(void)
{
}

int FS_Initialized(void)
{
	return fs_searchpaths != 0;
}

void FS_CheckFileSystemStarted(void)
{
}

int FS_IwdIsPure(iwd_t const* iwd)
{
	if (fs_numServerIwds)
	{
		if (fs_numServerIwds <= 0)
			return 0;
		for (int i = 0; iwd->checksum != fs_serverIwds[i];)
			if (++i >= fs_numServerIwds)
				return 0;
	}
	return 1;
}

int FS_LoadStack(void)
{
	return fs_loadStack;
}

int FS_UseSearchPath(searchpath_s const* pSearch)
{
	return !pSearch->bLocalized
		|| !Dvar_GetBool(fs_ignoreLocalized) && (!pSearch->bLocalized || pSearch->language == SEH_GetCurrentLanguage());
}

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

long FS_HashFileName(char const* fname, int hashSize)
{
	int hash;
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

int FS_HandleForFile(char const* name, FsThread thread)
{
	int i;
	int count;
	int first;

	switch (thread)
	{
		case FS_THREAD_MAIN:
			first = 1;
			count = 49;
			break;
		case FS_THREAD_STREAM:
			first = 50;
			count = 11;
			break;
		case FS_THREAD_DATABASE:
			first = 61;
			count = 1;
			break;
		case FS_THREAD_BACKEND:
			first = 62;
			count = 1;
			break;
		case FS_THREAD_SERVER:
			first = 63;
			count = 2;
			break;
		default:
			first = 0;
			count = 0;
			break;
	}

	for (i = 0; i < count; ++i)
	{
		if (!fsh[i + first].handleFiles.file.o)
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

	Com_Error(ERR_DROP, "\\x15FS_HandleForFile: none free");
	return 0;
}

int FS_HandleForFileCurrentThread(char const* filename)
{
	if (Sys_IsMainThread())
		return FS_HandleForFile(filename, FS_THREAD_MAIN);
	if (Sys_IsDatabaseThread())
		return FS_HandleForFile(filename, FS_THREAD_DATABASE);
	if (Sys_IsStreamThread())
		return FS_HandleForFile(filename, FS_THREAD_STREAM);
	if (Sys_IsRenderThread())
		return FS_HandleForFile(filename, FS_THREAD_BACKEND);
	return FS_HandleForFile(filename, FS_THREAD_SERVER);
}

FILE* FS_FileForHandle(int f)
{
	return fsh[f].handleFiles.file.o;
}

FsThread FS_GetCurrentThread()
{
	if (Sys_IsMainThread())
	{
		return FS_THREAD_MAIN;
	}
	if (Sys_IsDatabaseThread())
	{
		return FS_THREAD_DATABASE;
	}
	if (Sys_IsStreamThread())
	{
		return FS_THREAD_STREAM;
	}
	if (Sys_IsRenderThread())
	{
		return FS_THREAD_COUNT;
	}
	if (Sys_IsServerThread())
	{
		return FS_THREAD_SERVER;
	}
	return FS_THREAD_INVALID;
}

__int64 FS_filelength(int f)
{
	FILE* h;
	
	FS_CheckFileSystemStarted();
	if (fsh[f].zipFile)
		return ((unz_s*)fsh[f].handleFiles.file.z)->cur_file_info.uncompressed_size;
	h = FS_FileForHandle(f);
    return FS_FileGetFileSize(h);
}

void FS_ReplaceSeparators(char* path)
{
	char* src;
	char* dst;
	bool wasSep;

	wasSep = 0;
	src = path;
	dst = path;
	while (*src)
	{
		if (*src != '/' && *src != '\\')
		{
			wasSep = 0;
			*dst++ = *src;
		}
		else if (!wasSep)
		{
			wasSep = 1;
			*dst++ = '\\';
		}
		++src;
	}
	*dst = 0;
}

void FS_BuildOSPathForThread(char const* base, char const* game, char const* qpath, char* const ospath, FsThread thread)
{
	unsigned int lenQpath;
	unsigned int lenGame;
	unsigned int lenBase;

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
		Com_Error(ERR_FATAL, "FS_BuildOSPath: os path length exceeded\n");
	}

	memcpy(ospath, base, lenBase);
	ospath[lenBase] = 47;

	memcpy(&ospath[lenBase + 1], game, lenGame);
	ospath[lenBase + 1 + lenGame] = 47;

	memcpy(&ospath[lenBase + 2 + lenGame], qpath, lenQpath + 1);
	FS_ReplaceSeparators(ospath);
}

void FS_BuildOSPath(char const* base, char const* game, char const* qpath, char* const ospath)
{
	FS_BuildOSPathForThread(base, game, qpath, ospath, FS_THREAD_MAIN);
}

char FS_IsBackupSubStr(const char* filenameSubStr)
{
	if (*filenameSubStr == '.' && filenameSubStr[1] == '.')
	{
		return 1;
	}
	if (*filenameSubStr != ':' || filenameSubStr[1] != ':')
	{
		return 0;
	}
	return 1;
}

int FS_CreatePath(char* OSPath)
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

void FS_CopyFile(char* fromOSPath, char* toOSPath)
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
		Com_Error(ERR_FATAL, "Short read in FS_CopyFile()\n");
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
		Com_Error(ERR_FATAL, "Short write in FS_CopyFile()\n");
	}

	FS_FileClose(f);
	Z_Free(buf, 3);
}

void FS_FCloseFile(int h)
{
	FILE* f;

	FS_CheckFileSystemStarted();
	if (fs_debug->current.integer)
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

void FS_FCloseLogFile(int h)
{
	FS_FCloseFile(h);
}

int FS_GetHandleAndOpenFile(char const* filename, char const* ospath, FsThread thread)
{
	int f;
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

int FS_FOpenFileWriteToDirForThread(char const* filename, char const* dir, char const* osbasepath, FsThread thread)
{
	int result;
	char ospath[256];
	const char* basepath;

	FS_CheckFileSystemStarted();
	basepath = fs_homepath->current.string;
	FS_BuildOSPath(basepath, dir, filename, ospath);
	if (fs_debug->current.integer)
	{
		Com_Printf(CON_CHANNEL_FILES, "FS_FOpenFileWriteToDirForThread: %s\n", ospath);
	}
	if (FS_CreatePath(ospath))
	{
		result = 0;
	}
	else
	{
		result = FS_GetHandleAndOpenFile(filename, ospath, thread);
	}
	return result;
}

int FS_FOpenFileWriteToDir(char const* filename, char const* dir, char const* osbasepath)
{
	return FS_FOpenFileWriteToDirForThread(filename, dir, osbasepath, FS_THREAD_MAIN);
}

int FS_FOpenFileWrite(char const* filename)
{
	return FS_FOpenFileWriteToDirForThread(filename, fs_gamedir, "", FS_THREAD_MAIN);
}

int FS_FOpenFileWriteCurrentThread(char const* filename, char const* dir, char const* osbasepath)
{
	FsThread thread;

	thread = FS_GetCurrentThread();
	if (thread != 6)
	{
		return FS_FOpenFileWriteToDirForThread(filename, dir, osbasepath, thread);
	}
	Com_PrintError(1, "FS_FOpenFileWriteCurrentThread for an unknown thread\n");
	return 0;
}

int FS_FOpenTextFileWrite(char const* filename)
{
	char ospath[256];
	const char* basepath;
	FILE* f;
	int h;

	h = 0;
	FS_CheckFileSystemStarted();

	basepath = fs_homepath->current.string;
	FS_BuildOSPath(basepath, fs_gamedir, filename, ospath);
	if (fs_debug->current.integer)
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

int FS_FOpenFileAppend(char const* filename)
{
	char ospath[256];
	const char* basepath;
	FILE* f;
	int h;

	h = 0;
	FS_CheckFileSystemStarted();
	basepath = fs_homepath->current.string;
	FS_BuildOSPath(basepath, fs_gamedir, filename, ospath);
	if (fs_debug->current.integer)
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

int FS_FilenameCompare(char const* s1, char const* s2)
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
	}     while (c1);

	return 0;       // strings are equal
}

int FS_PureIgnoreFiles(char const* filename)
{
	int result;
	const char* extension;

	if (!I_stricmp(filename, "ban.txt"))
	{
		return 1;
	}
	extension = Com_GetExtensionSubString(filename);
	if (*extension == 46)
	{
		++extension;
	}
	if (!I_stricmp(extension, "cfg"))
	{
		result = 1;
	}
	else
	{
		result = I_stricmp(extension, ".dm_NETWORK_PROTOCOL_VERSION") == 0;
	}
	return result;
}

bool FS_SanitizeFilename(char const* filename, char* sanitizedName, int sanitizedNameSize)
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

	sanitizedName[dstIndex] = 0;
	return 1;
}

bool FS_FilesAreLoadedGlobally(char const* filename)
{
	const char* extensions[8] = { ".hlsl", ".txt", ".cfg", ".levelshots", ".menu", ".arena", ".str", "" };
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

void FS_FreeFileList(const char** list, int allocTrackType)
{
	if (list)
	{
		Hunk_UserDestroy((HunkUser*)*(list - 1));
	}
}

int FS_Delete(char const* filename)
{
	char ospath[256];
	const char* basepath;

	FS_CheckFileSystemStarted();
	assert(filename);
	if (!*filename)
	{
		return 0;
	}

	basepath = fs_homepath->current.string;
	FS_BuildOSPath(basepath, fs_gamedir, filename, ospath);

	return remove(ospath) != -1;
}

int FS_Read(void* buffer, int len, int h)
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
			Com_Error(ERR_FATAL, "FS_Read: -1 bytes read");
		}

		remaining -= read;
		buf += read;
	}

	return len;
}

int FS_Write(void const* buffer, int len, int h)
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

int FS_WriteToDemo(void const* buffer, int len, int h)
{
	return FS_Write(buffer, len, h);
}

int FS_WriteLog(void const*, int, int)
{
	return 0;
}

void FS_Printf(int h, char const* fmt, ...)
{
	char msg[4096];
	va_list va;

	va_start(va, fmt);
	_vsnprintf(msg, sizeof(msg), fmt, va);
	va_end(va);

	FS_Write(msg, strlen(msg), h);
}

int FS_Seek(int f, long offset, int origin)
{
	int result;
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
			result = 0;
		}
		else
		{
			result = -1;
		}
		return result;
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
			result = 0;
		}
		else
		{
			result = -1;
		}
		return result;
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
			result = 0;
		}
		else
		{
			result = -1;
		}
		return result;
	}

	assertMsg(va("Bad origin %i in FS_Seek", origin));
	return -1;
}

void FS_ResetFiles(void)
{
	fs_loadStack = 0;
}

void FS_FreeFile(void* buffer)
{
	FS_CheckFileSystemStarted();
	--fs_loadStack;
	Hunk_FreeTempMemory(buffer);
}

int FS_WriteFile(char const* filename, void const* buffer, int size)
{
	int result;
	int actualSize;
	int f;

	FS_CheckFileSystemStarted();
	f = FS_FOpenFileWrite(filename);
	if (f)
	{
		actualSize = FS_Write(buffer, size, f);
		FS_FCloseFile(f);
		if (actualSize == size)
		{
			result = 1;
		}
		else
		{
			FS_Delete(filename);
			result = 0;
		}
	}
	else
	{
		Com_Printf(CON_CHANNEL_FILES, "Failed to open %s\n", filename);
		result = 0;
	}

	return result;
}

int FS_GetFileOsPath(char const* filename, char* ospath)
{
	char sanitizedName[256];
	directory_t* dir;
	searchpath_s* search;
	FILE* fp;

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

int FS_OpenFileOverwrite(char const* qpath)
{
	DWORD oldAttr;
	char ospath[256];
	unsigned int attributes;

	FS_CheckFileSystemStarted();
	if (FS_GetFileOsPath(qpath, ospath) < 0)
	{
		Com_Error(
			ERR_DROP,
			"FS_FOpenFileOverWrite: Failed to open %s for writing.  It either does not exist or is in a iwd file.",
			qpath);
	}

	if (fs_debug->current.integer)
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

int FS_ReturnPath(char const* zname, char* zpath, int* depth)
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

int FS_AddFileToList(HunkUser* user, char const* name, char const** list, int nfiles)
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

char const** FS_ListFilteredFiles(searchpath_s* searchPath, char const* path, char const* extension, char const* filter, FsListBehavior_e behavior, int* numfiles, int allocTrackType)
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
				if (!search->bLocalized && !FS_IwdIsPure(search->iwd))
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
						LABEL_46:
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
							goto LABEL_46;
						}
					}
				}
			}
			else if (search->dir && (!fs_restrict->current.enabled && !fs_numServerIwds || behavior))
			{
				FS_BuildOSPath(search->dir->path, search->dir->gamedir, sanitizedPath, netpath);
				sysFiles = Sys_ListFiles(netpath, extension, filter, &numSysFiles, isDirSearch);
				for (i = 0; i < numSysFiles; ++i)
				{
					nfiles = FS_AddFileToList(user, sysFiles[i], list, nfiles);
				}
				FS_FreeFileList((const char**)sysFiles, 0);
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

const char** FS_ListFiles(const char* path, const char* extension, FsListBehavior_e behavior, int* numfiles, int allocTrackType)
{
	return FS_ListFilteredFiles(fs_searchpaths, path, extension, NULL, behavior, numfiles, allocTrackType);
}

bool FS_CheckLocation(char const* path, int lookInFlags)
{
	if (lookInFlags == 63)
	{
		return 1;
	}
	if (lookInFlags & 1 && !I_strncmp(path, "main", 4))
	{
		return 1;
	}
	if (lookInFlags & 2 && !I_strncmp(path, "dev", 3))
	{
		return 1;
	}
	if (lookInFlags & 4 && !I_strncmp(path, "temp", 4))
	{
		return 1;
	}
	if (lookInFlags & 8 && !I_strncmp(path, "raw", 3))
	{
		return 1;
	}
	if (lookInFlags & 0x10 && !I_strncmp(path, "raw_shared", 10))
	{
		return 1;
	}
	if (lookInFlags & 0x20 && !I_strncmp(path, "devraw", 6))
	{
		return 1;
	}

	return 0;
}

const char** FS_ListFilteredFilesInLocation(const char* path, const char* extension, const char* filter, FsListBehavior_e behavior, int* numfiles, int lookInFlags, int allocTrackType)
{
	const char** result;
	searchpath_s* locationSearchPath;
	HunkUser* user;
	char* pathDir;
	searchpath_s* search;
	searchpath_s* locationSearch;

	user = Hunk_UserCreate(0x20000, HU_SCHEME_DEFAULT, 0, 0, "FS_ListFilteredFilesInLocation", 3);
	locationSearchPath = 0;
	locationSearch = 0;

	//
	// search through the path, one element at a time, adding to list
	//
	for (search = fs_searchpaths; search; search = search->next)
	{
		if (search->dir)
		{
			pathDir = search->dir->gamedir;
		}
		else if (search->iwd)
		{
			pathDir = search->iwd->iwdGamename;
		}
		else
		{
			pathDir = 0;
		}

		assert(pathDir);
		if (FS_CheckLocation(pathDir, lookInFlags))
		{
			if (locationSearchPath)
			{
				locationSearch->next = (searchpath_s*)Hunk_UserAlloc(user, 28, 4, 0);
				locationSearch = locationSearch->next;
			}
			else
			{
				locationSearchPath = (searchpath_s*)Hunk_UserAlloc(user, 28, 4, 0);
				locationSearch = locationSearchPath;
			}

			locationSearch->next = 0;
			locationSearch->dir = search->dir;
			locationSearch->language = search->language;
			locationSearch->bLocalized = search->bLocalized;
			locationSearch->iwd = search->iwd;
		}
	}

	result = FS_ListFilteredFiles(locationSearchPath, path, extension, filter, behavior, numfiles, allocTrackType);
	Hunk_UserDestroy(user);

	return result;
}

int FS_GetFileList(char const* path, char const* extension, FsListBehavior_e behavior, char* listbuf, int bufsize)
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

	fileNames = FS_ListFiles(path, extension, behavior, &fileCount, 3);
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

	FS_FreeFileList(fileNames, 3);
	return fileCount;
}

void FS_ConvertPath(char* s)
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

int FS_PathCmp(const char* s1, const char* s2)
{
	int c2;
	int c1;

	do
	{
		c1 = *s1++;
		c2 = *s2++;

		if (I_islower(c1))
		{
			c1 -= 32;
		}
		if (I_islower(c2))
		{
			c2 -= 32;
		}
		if (c1 == 92 || c1 == 58)
		{
			c1 = 47;
		}
		if (c2 == 92 || c2 == 58)
		{
			c2 = 47;
		}
		if (c1 < c2)
		{
			return -1;
		}
		if (c1 > c2)
		{
			return 1;
		}
	}     
	while (c1);

	return 0;
}

void FS_SortFileList(char const** filelist, int numfiles)
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

void FS_FullPath_f(void)
{
	FS_DisplayPath(0);
}

void FS_Path_f(void)
{
	FS_DisplayPath(1);
}

void FS_AddIwdFilesForGameDirectory(const char* path, const char* pszGameFolder)
{
}

void FS_AddSearchPath(searchpath_s*)
{
}

void FS_AddGameDirectory(char const* path, char const* dir, int bLanguageDirectory, int iLanguage)
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
				if (i->bLocalized)
				{
					locText = "localized";
				}
				else
				{
					locText = "non-localized";
				}
				Com_PrintWarning(
					10,
					"WARNING: game folder %s/%s added as both localized & non-localized. Using folder as %s\n",
					path,
					szGameFolder,
					locText);
			}

			if (i->bLocalized)
			{
				if (i->language != iLanguage)
				{
					Com_PrintWarning(
						10,
						"WARNING: game folder %s/%s re-added as localized folder with different language\n",
						path,
						szGameFolder);
				}
			}
			return;
		}
	}

	if (bLanguageDirectory)
	{
		FS_BuildOSPath(path, szGameFolder, "", ospath);
		ospath[strlen(ospath) - 1] = 0;
		if (!Sys_DirectoryHasContents(ospath))
		{
			return;
		}
	}
	else
	{
		I_strncpyz(fs_gamedir, szGameFolder, 256);
	}

	search = (searchpath_s*)Z_Malloc(sizeof(searchpath_s), "FS_AddGameDirectory", 3);
	search->dir = (directory_t*)Z_Malloc(sizeof(directory_t), "FS_AddGameDirectory", 3);
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
	FS_AddIwdFilesForGameDirectory(path, szGameFolder);
}

void FS_AddLocalizedGameDirectory(char const* path, char const* dir)
{
	int i;

	for (i = 12; i >= 0; --i)
	{
		FS_AddGameDirectory(path, dir, 1, i);
	}

	FS_AddGameDirectory(path, dir, 0, 0);
}

void FS_ShutdownSearchPaths(searchpath_s* p)
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

void FS_ShutdownServerFileReferences(int* numFiles, char const** fileNames)
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

void FS_ShutdownServerIwdNames(void)
{
	FS_ShutdownServerFileReferences(&fs_numServerIwds, fs_serverIwdNames);
}

void FS_ShutdownServerReferencedIwds(void)
{
	FS_ShutdownServerFileReferences(&fs_numServerReferencedIwds, fs_serverReferencedIwdNames);
}

void FS_ShutdownServerReferencedFFs(void)
{
	FS_ShutdownServerFileReferences(&fs_numServerReferencedFFs, fs_serverReferencedFFNames);
}

void FS_Shutdown(void)
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

void FS_RegisterDvars(void)
{
}

void FS_AddDevGameDirs(char const* path, bool allow_devraw)
{
	unsigned int j;
	unsigned int i;
	char devDir[32];
	const char* devDirsOrder[3] = { "raw_shared", "raw", "discdata" };

	if (allow_devraw)
	{
		strcpy(devDir, "dev");

		for (i = 0; i < 3; ++i)
		{
			I_strncpyz(devDir + 3, devDirsOrder[i], 29);
			FS_AddLocalizedGameDirectory(path, devDir);
		}
	}

	for (j = 0; j < 3; ++j)
	{
		FS_AddLocalizedGameDirectory(path, devDirsOrder[j]);
	}
}

void FS_Startup(char const* gameName, bool allow_devraw)
{
	const char* basepath;

	Com_Printf(CON_CHANNEL_FILES, "----- FS_Startup -----\n");
	FS_RegisterDvars();

	if (fs_usedevdir->current.enabled)
	{
		if (fs_basepath->current.string[0])
		{
			FS_AddDevGameDirs(fs_basepath->current.string, allow_devraw);
		}
		if (fs_homepath->current.string[0] && I_stricmp(fs_basepath->current.string, fs_homepath->current.string))
		{
			FS_AddDevGameDirs(fs_homepath->current.string, allow_devraw);
		}
		if (fs_cdpath->current.string[0] && I_stricmp(fs_basepath->current.string, fs_cdpath->current.string))
		{
			FS_AddDevGameDirs(fs_cdpath->current.string, allow_devraw);
		}
	}

	if (fs_cdpath->current.string[0] && I_stricmp(fs_basepath->current.string, fs_cdpath->current.string))
	{
		FS_AddLocalizedGameDirectory(fs_cdpath->current.string, gameName);
	}

	basepath = fs_homepath->current.string;
	if (fs_basepath->current.string[0])
	{
		FS_AddLocalizedGameDirectory(fs_basepath->current.string, "players");
	}

	if (fs_basepath->current.string[0])
	{
		FS_AddLocalizedGameDirectory(fs_basepath->current.string, va("%s_shared", gameName));
		FS_AddLocalizedGameDirectory(fs_basepath->current.string, gameName);
	}
	if (fs_basepath->current.string[0] && I_stricmp(fs_homepath->current.string, fs_basepath->current.string))
	{
		FS_AddLocalizedGameDirectory(fs_basepath->current.string, va("%s_shared", gameName));
		FS_AddLocalizedGameDirectory(fs_homepath->current.string, gameName);
	}

	if (fs_basegame->current.string[0]
		&& !I_stricmp(gameName, "main")
		&& I_stricmp(fs_basegame->current.string, gameName)
		&& fs_basepath->current.string[0])
	{
		FS_AddGameDirectory(fs_basepath->current.string, fs_basegame->current.string, 0, 0);
	}

	if (fs_gameDirVar->current.string[0]
		&& !I_stricmp(gameName, "main")
		&& I_stricmp(fs_gameDirVar->current.string, gameName)
		&& fs_basepath->current.string[0])
	{
		FS_AddGameDirectory(fs_basepath->current.string, "usermaps", 0, 0);
		FS_AddGameDirectory(fs_basepath->current.string, fs_gameDirVar->current.string, 0, 0);
	}
	FS_AddCommands();
	FS_Path_f();
	Dvar_ClearModified((dvar_t*)fs_gameDirVar);
	Com_Printf(CON_CHANNEL_FILES, "----------------------\n");
	Com_Printf(CON_CHANNEL_FILES, "%d files in iwd files\n", fs_iwdFileCount);
}

void FS_ClearIwdReferences(void)
{
	searchpath_s* search;

	for (search = fs_searchpaths; search; search = search->next)
	{
		// is the element an iwd file and has it been referenced?
		if (search->iwd)
		{
			search->iwd->referenced = 0;
		}
	}
}

void FS_AddIwdPureCheckReference(searchpath_s const* search)
{
	iwd_pure_check_s* pureCheckInfo;
	iwd_pure_check_s* p;

	assert(search->iwd);
	if (!search->bLocalized)
	{
		for (p = fs_iwdPureChecks; p; p = p->next)
		{
			if (p->checksum == search->iwd->checksum && !I_stricmp(p->iwdBasename, search->iwd->iwdBasename))
			{
				return;
			}
		}

		pureCheckInfo = (iwd_pure_check_s*)Z_Malloc(520, "FS_AddIwdPureCheckReference", 3);
		pureCheckInfo->next = NULL;
		pureCheckInfo->checksum = search->iwd->checksum;
		I_strncpyz(pureCheckInfo->iwdBasename, search->iwd->iwdBasename, 256);
		I_strncpyz(pureCheckInfo->iwdGamename, search->iwd->iwdGamename, 256);
		if (fs_iwdPureChecks)
		{
			for (p = fs_iwdPureChecks; p; p = p->next)
			{
				if (!p->next)
				{
					p->next = pureCheckInfo;
					return;
				}
			}
		}
		else
		{
			fs_iwdPureChecks = pureCheckInfo;
		}
	}
}

void FS_ShutDownIwdPureCheckReferences(void)
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
	Dvar_GetBool(fs_usedevdir);
}

void FS_Restart(int checksumFeed)
{
	FS_Shutdown();
	fs_checksumFeed = checksumFeed;
	for (i = fs_searchpaths; i; i = i->next)
	{
		v4 = i->iwd;
		if (v4)
			v4->referenced = 0;
	}
	v5 = fs_iwdPureChecks;
	if (fs_iwdPureChecks)
	{
		do
		{
			v6 = v5->next;
			Z_Free(v5, 3);
			v5 = v6;
		}     while (v6);
	}
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

bool FS_IsInCompressedIwd(int)
{
	return false;
}

void FS_Flush(int f)
{
	FILE* file;

	file = FS_FileForHandle(f);
	fflush(file);
}

bool Com_IsAddonMap(char const*, char const**)
{
	return false;
}

void FS_DisablePureCheck(bool)
{
}

int FS_FOpenFileReadForThread(char const*, int*, FsThread, char*, int)
{
	return 0;
}

int FS_FOpenFileReadCurrentThread(char const*, int*)
{
	return 0;
}

int FS_ReadFile(const char*, void**)
{
	return 0;
}

const char** FS_ListFilesInLocation(const char*, const char*, FsListBehavior_e, int*, int, int)
{
	return nullptr;
}

void Com_GetBspFilename(char* const, int, char const*)
{
}

int FS_FOpenFileRead(char const*, int*)
{
	return 0;
}

int FS_TouchFile(char const*)
{
	return 0;
}

int FS_FOpenFileByMode(char const*, int*, fsMode_t)
{
	return 0;
}
