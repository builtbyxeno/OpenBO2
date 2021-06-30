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

#ifndef COM_FILEACCESS_H
#define COM_FILEACCESS_H

#include <universal/q_shared.h>

FILE* FileWrapper_Open(char const*, char const*);
int FileWrapper_Seek(FILE*, int, int);
unsigned int FS_FileRead(void*, unsigned int, FILE*);
unsigned int FS_FileWrite(const void*, unsigned int, FILE*);
FILE* FS_FileOpenReadBinary(const char*);
FILE* FS_FileOpenReadText(const char*);
FILE* FS_FileOpenWriteBinary(const char*);
FILE* FS_FileOpenAppendText(const char*);
FILE* FS_FileOpenWriteText(const char*);
void FS_FileClose(FILE*);
int FS_FileSeek(FILE*, int, int);
int FS_FileGetFileSize(FILE*);

#endif