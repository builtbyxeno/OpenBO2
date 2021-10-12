#include "types.h"
#include "vars.h"
#include "qcommon_public.h"
#include <universal/com_files_wrapper_stdio.h>

unsigned int FS_FileWrite(const void* ptr, unsigned int len, FILE* stream)
{
	return fwrite(ptr, 1, len, stream);
}

unsigned int FS_FileRead(void* ptr, unsigned int len, FILE* stream)
{
	unsigned int read_size;

	ProfLoad_BeginTrackedValue(MAP_PROFILE_FILE_READ);
	read_size = fread(ptr, 1, len, stream);
	ProfLoad_EndTrackedValue(MAP_PROFILE_FILE_READ);
	return read_size;
}

FILE* FS_FileOpenReadText(const char* filename)
{
	FILE* file;

	ProfLoad_BeginTrackedValue(MAP_PROFILE_FILE_READ);
	file = FileWrapper_Open(filename, "rt");
	ProfLoad_EndTrackedValue(MAP_PROFILE_FILE_READ);
	return file;
}

FILE* FS_FileOpenReadBinary(const char* filename)
{
	FILE* file;

	ProfLoad_BeginTrackedValue(MAP_PROFILE_FILE_READ);
	file = FileWrapper_Open(filename, "rb");
	ProfLoad_EndTrackedValue(MAP_PROFILE_FILE_READ);
	return file;
}

FILE* FS_FileOpenWriteText(const char* filename)
{
	FILE* file;

	ProfLoad_BeginTrackedValue(MAP_PROFILE_FILE_OPEN);
	file = FileWrapper_Open(filename, "w+t");
	ProfLoad_EndTrackedValue(MAP_PROFILE_FILE_OPEN);
	return file;
}

FILE* FS_FileOpenWriteBinary(const char* filename)
{
	FILE* file;

	ProfLoad_BeginTrackedValue(MAP_PROFILE_FILE_OPEN);
	file = FileWrapper_Open(filename, "wb");
	ProfLoad_EndTrackedValue(MAP_PROFILE_FILE_OPEN);
	return file;
}

int FS_FileGetFileSize(FILE* file)
{
	return FileWrapper_GetFileSize((int)file);
}

void FS_FileClose(FILE* stream)
{
	fclose(stream);
}

int FS_FileSeek(FILE* file, int offset, int whence)
{
	int seek;

	ProfLoad_BeginTrackedValue(MAP_PROFILE_FILE_SEEK);
	seek = FileWrapper_Seek((int)file, offset, whence);
	ProfLoad_EndTrackedValue(MAP_PROFILE_FILE_SEEK);
	return seek;
}

FILE* FS_FileOpenAppendText(const char* filename)
{
	FILE* file;

	ProfLoad_BeginTrackedValue(MAP_PROFILE_FILE_OPEN);
	file = FileWrapper_Open(filename, "at");
	ProfLoad_EndTrackedValue(MAP_PROFILE_FILE_OPEN);
	return file;
}
