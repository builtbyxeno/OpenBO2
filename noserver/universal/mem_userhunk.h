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

#ifndef MEM_USERHUNK_H
#define MEM_USERHUNK_H

enum HU_ALLOCATION_SCHEME : __int32
{
	HU_SCHEME_DEFAULT = 0x0,
	HU_SCHEME_DEBUG = 0x1,
	HU_SCHEME_FIRSTFIT = 0x2,
	HU_SCHEME_FIXED = 0x3,
	HU_SCHEME_NULL = 0x4,
	HU_SCHEME_COUNT = 0x5,
};

typedef struct HunkUser
{
	HU_ALLOCATION_SCHEME scheme;
	unsigned int flags;
	const char* name;
	int type;
} HunkUser;

struct HunkUser* Hunk_UserDebugInit(void*, int, enum HU_ALLOCATION_SCHEME, unsigned long, void*, char const*, int);
void Hunk_UserDebugReset(struct HunkUser*);
void Hunk_UserDebugDestroy(struct HunkUser*);
void* Hunk_UserDebugAlloc(struct HunkUser*, int, int, char const*);
void Hunk_UserDebugFree(struct HunkUser*, void*);
struct HunkUser* Hunk_UserDefaultInit(void*, int, enum HU_ALLOCATION_SCHEME, unsigned long, void*, char const*, int);
void Hunk_UserDefaultDestroy(struct HunkUser*);
void Hunk_UserDefaultFree(struct HunkUser*, void*);
struct HunkUser* Hunk_UserNullInit(void*, int, enum HU_ALLOCATION_SCHEME, unsigned long, void*, char const*, int);
void Hunk_UserNullReset(struct HunkUser*);
void Hunk_UserNullDestroy(struct HunkUser*);
void* Hunk_UserNullAlloc(struct HunkUser*, int, int, char const*);
void Hunk_UserNullFree(struct HunkUser*, void*);
struct HunkUser* Hunk_UserCreateFromBuffer(void*, int, enum HU_ALLOCATION_SCHEME, unsigned long, void*, char const*, int);
struct HunkUser* Hunk_UserCreate(int, enum HU_ALLOCATION_SCHEME, unsigned long, void*, char const*, int);
struct HunkUser* Hunk_UserCreateNull(struct HunkUserNull*);
void* Hunk_UserAlloc(struct HunkUser*, int, int, char const*);
void Hunk_UserFree(struct HunkUser*, void*);
void Hunk_UserReset(struct HunkUser*);
void Hunk_UserDestroy(struct HunkUser*);
void Hunk_UserSetPos(struct HunkUser*, void*);
char* Hunk_CopyString(struct HunkUser*, char const*);
void Hunk_UserDefaultReset(struct HunkUser*);
void* Hunk_UserDefaultAlloc(struct HunkUser*, int, int, char const*);
void Hunk_UserStartup(void);
void Hunk_UserShutdown(void);

#endif