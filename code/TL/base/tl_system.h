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

#ifndef TL_SYSTEM_H
#define TL_SYSTEM_H

#include <Windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <malloc.h>
#include <Psapi.h>

#include "tl_defs.h"
#include "tl_thread.h"

struct tlFileBuf;

struct tagTHREADNAME_INFO
{
	unsigned int dwType;
	const char* szName;
	unsigned int dwThreadID;
	unsigned int dwFlags;
};

struct tlSystemCallbacks
{
	bool(__cdecl* ReadFile)(const char*, tlFileBuf*, unsigned int, unsigned int);
	void(__cdecl* ReleaseFile)(tlFileBuf*);
	void(__cdecl* CriticalError)(const char*);
	void(__cdecl* Warning)(const char*);
	void(__cdecl* DebugPrint)(const char*);
	void* (__cdecl* MemAlloc)(unsigned int, unsigned int, unsigned int);
	void* (__cdecl* MemRealloc)(void*, unsigned int, unsigned int, unsigned int);
	void(__cdecl* MemFree)(void*);
};

void tlSetSystemCallbacks(const tlSystemCallbacks* Callbacks);
void tlSetFileServerRootPC(const char* Path);
void tlMemFree(void* Ptr);
void tlReleaseFile(tlFileBuf* File);
void tlPrint(const char* txt);
int tlGetVersion();
void tlStackRangeInit();
bool tlFatalHandler(const char* Msg);
void tlDebugPrint(const char* txt);
void tlVPrintf(const char* Format, char* args);
void tlPrintf(const char* Format, ...);
char _tlAssert(const char* file, int line, const char* expr, const char* desc);
void tlFatal(const char* Format, ...);
void* tlMemAlloc(unsigned int Size, unsigned int Align, unsigned int Flags);
void* tlMemRealloc(void* Ptr, unsigned int Size, unsigned int Align, unsigned int Flags);
unsigned int tlGetFreeMemory();
void* tlScratchPadInit();
void tlScratchPadReset();
void tlWarning(const char* Format, ...);

tlSystemCallbacks tlCurSystemCallbacks;
char tlHostPrefix[256];
int tlMemAllocCounter;
void* tlStackBegin;
void* tlStackEnd;
int tlScratchPadRefCount;
void* tlScratchPadPtr;

#endif