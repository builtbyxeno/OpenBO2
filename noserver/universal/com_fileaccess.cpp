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

#include "com_fileaccess.h"

FILE* FileWrapper_Open(char const* ospath, char const* mode)
{
	FILE* file;

	*_errno() = 0;
	file = fopen(ospath, mode);
	if (file != (FILE*)-1)
		return file;
	return 0;
}

int FileWrapper_Seek(FILE* stream, int offset, int origin)
{
	switch (origin) {
		case 0:
			return fseek(stream, offset, 1);
		case 1:
			return fseek(stream, offset, 2);
		case 2:
			return fseek(stream, offset, 0);
	}
	return 0;
}

unsigned int FS_FileRead(void* ptr, unsigned int len, FILE* stream)
{
	return fread(ptr, 1u, len, stream);
}

unsigned int FS_FileWrite(const void* ptr, unsigned int len, FILE* stream)
{
	return fwrite(ptr, 1u, len, stream);
}

FILE* FS_FileOpenReadBinary(const char* filename)
{
	return FileWrapper_Open(filename, "rb");
}

FILE* FS_FileOpenReadText(const char* filename)
{
	return FileWrapper_Open(filename, "rt");
}

FILE* FS_FileOpenWriteBinary(const char* filename)
{
	return FileWrapper_Open(filename, "wb");
}

FILE* FS_FileOpenAppendText(const char* filename)
{
	return FileWrapper_Open(filename, "at");
}

FILE* FS_FileOpenWriteText(const char* filename)
{
	return FileWrapper_Open(filename, "w+t");
}

void FS_FileClose(FILE* stream)
{
	fclose(stream);
}

int FS_FileSeek(FILE* file, int offset, int whence)
{
	return FileWrapper_Seek(file, offset, whence);
}

int FS_FileGetFileSize(FILE* file)
{
	int startPos;
	int fileSize;

	startPos = ftell(file);
	fseek(file, 0, 2);

	fileSize = ftell(file);
	fseek(file, startPos, 0);

	return fileSize;
}
