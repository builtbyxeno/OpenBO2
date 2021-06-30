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

#include "mem_userhunk.h"

HunkUser* Hunk_UserDebugInit(void*, int, HU_ALLOCATION_SCHEME, unsigned long, void*, char const*, int)
{
	return nullptr;
}

void Hunk_UserDebugReset(HunkUser*)
{
}

void Hunk_UserDebugDestroy(HunkUser*)
{
}

void* Hunk_UserDebugAlloc(HunkUser*, int, int, char const*)
{
	return nullptr;
}

void Hunk_UserDebugFree(HunkUser*, void*)
{
}

HunkUser* Hunk_UserDefaultInit(void*, int, HU_ALLOCATION_SCHEME, unsigned long, void*, char const*, int)
{
	return nullptr;
}

void Hunk_UserDefaultDestroy(HunkUser*)
{
}

void Hunk_UserDefaultFree(HunkUser*, void*)
{
}

HunkUser* Hunk_UserNullInit(void*, int, HU_ALLOCATION_SCHEME, unsigned long, void*, char const*, int)
{
	return nullptr;
}

void Hunk_UserNullReset(HunkUser*)
{
}

void Hunk_UserNullDestroy(HunkUser*)
{
}

void* Hunk_UserNullAlloc(HunkUser*, int, int, char const*)
{
	return nullptr;
}

void Hunk_UserNullFree(HunkUser*, void*)
{
}

HunkUser* Hunk_UserCreateFromBuffer(void*, int, HU_ALLOCATION_SCHEME, unsigned long, void*, char const*, int)
{
	return nullptr;
}

HunkUser* Hunk_UserCreate(int, HU_ALLOCATION_SCHEME, unsigned long, void*, char const*, int)
{
	return nullptr;
}

HunkUser* Hunk_UserCreateNull(HunkUserNull*)
{
	return nullptr;
}

void* Hunk_UserAlloc(HunkUser*, int, int, char const*)
{
	return nullptr;
}

void Hunk_UserFree(HunkUser*, void*)
{
}

void Hunk_UserReset(HunkUser*)
{
}

void Hunk_UserDestroy(HunkUser*)
{
}

void Hunk_UserSetPos(HunkUser*, void*)
{
}

char* Hunk_CopyString(HunkUser*, char const*)
{
	return nullptr;
}

void Hunk_UserDefaultReset(HunkUser*)
{
}

void* Hunk_UserDefaultAlloc(HunkUser*, int, int, char const*)
{
	return nullptr;
}

void Hunk_UserStartup(void)
{
}

void Hunk_UserShutdown(void)
{
}
