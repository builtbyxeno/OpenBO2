#include "types.h"
#include "vars.h"
#include <qcommon/qcommon_public.h>

HunkUser* g_DebugHunkUser;
ALLOCATION_SCHEME_FUNCTIONS g_HunkUserAllocationSchemeMap[5] =
{
		{
				&Hunk_UserDefaultInit,
				&Hunk_UserDefaultReset,
				&Hunk_UserDefaultDestroy,
				&Hunk_UserDefaultAlloc,
				&Hunk_UserDefaultFree
		},
		{
				&Hunk_UserDebugInit,
				&Hunk_UserDebugReset,
				&Hunk_UserDebugDestroy,
				&Hunk_UserDebugAlloc,
				&Hunk_UserDebugFree
		},
		{
				&Hunk_FirstFitInit,
				&Hunk_FirstFitReset,
				&Hunk_FirstFitDestroy,
				&Hunk_FirstFitAlloc,
				&Hunk_FirstFitFree
		},
		{
				&Hunk_FixedInit,
				&Hunk_FixedReset,
				&Hunk_FixedDestroy,
				&Hunk_FixedAlloc,
				&Hunk_FixedFree
		},
		{
				&Hunk_UserNullInit,
				&Hunk_UserNullReset,
				&Hunk_UserNullDestroy,
				&Hunk_UserNullAlloc,
				&Hunk_UserNullFree
		},
		
};

#define PAGE_SIZE 4096
#define HF_FIXEDSIZE 4

/*
==============
Hunk_UserDebugInit
==============
*/
HunkUser *Hunk_UserDebugInit(void *buffer, int size, HU_ALLOCATION_SCHEME scheme, unsigned int flags, void *scheme_specific_data, const char *name, int type)
{
	HunkUserDebug* user = (HunkUserDebug*)buffer;
	assert(scheme == HU_SCHEME_DEBUG);
	assert(Sys_IsMainThread());
	user->hunkUser.scheme = HU_SCHEME_DEFAULT;
	user->hunkUser.flags = 0;
	user->hunkUser.name = 0;
	user->hunkUser.type = 0;
	user->firstFit = 0;
	user->firstFit = Hunk_FirstFitInit((byte*)buffer + sizeof(HunkUserDebug), size - sizeof(HunkUserDebug),
		HU_SCHEME_FIRSTFIT, flags, 0, name, type);
	user->hunkUser.scheme = scheme;
	user->hunkUser.flags = flags;
	user->hunkUser.name = name;
	user->hunkUser.type = type;

	return &user->hunkUser;
}

/*
==============
Hunk_UserDebugReset
==============
*/
void Hunk_UserDebugReset(HunkUser *_user)
{
	HunkUserDebug* user = (HunkUserDebug*)_user;
	Hunk_FirstFitReset(user->firstFit);
}

/*
==============
Hunk_UserDebugDestroy
==============
*/
void Hunk_UserDebugDestroy(HunkUser *_user)
{
	HunkUserDebug* user = (HunkUserDebug*)_user;
	assert(user->hunkUser.scheme == HU_SCHEME_DEBUG);
	assert(Sys_IsMainThread());
	Z_VirtualFree(_user);
}

/*
==============
Hunk_UserDebugAlloc
==============
*/
void *Hunk_UserDebugAlloc(HunkUser *_user, int size, int alignment, const char* name)
{
	HunkUserDebug* user = (HunkUserDebug*)_user;
	assert(user);
	assert(user->hunkUser.scheme == HU_SCHEME_DEBUG);
	assert(Sys_IsMainThread());
	assert(!(alignment & (alignment - 1)));
	assert(alignment <= HUNK_MAX_ALIGNMENT);

	return Hunk_FirstFitAlloc(&user->hunkUser, size, alignment, name);
}

/*
==============
Hunk_UserDebugFree
==============
*/
void Hunk_UserDebugFree(HunkUser *_user, void *ptr)
{
	assert(_user->scheme == HU_SCHEME_DEBUG);
	assert(Sys_IsMainThread());
	Hunk_FirstFitFree(_user, ptr);
}

/*
==============
Hunk_UserDefaultInit
==============
*/
HunkUser *Hunk_UserDefaultInit(void *buffer, int size, HU_ALLOCATION_SCHEME scheme, unsigned int flags, void *scheme_specific_data, const char *name, int type)
{
	HunkUserDefault* user;

	assert(scheme == HU_SCHEME_DEFAULT);
	user = (HunkUserDefault*)buffer;
	memset(user, 0, sizeof(HunkUserDefault));
	user->end = (psize_int)user + size;
	user->pos = (psize_int)user->buf;
	user->pos = (user->pos + 31) & ~31;

	assertMsg((!(user->pos & 31)), "(user->pos) = %i", user->pos);
	if (flags & 2)
	{
		user->locked = size + user->pos;
	}
	else
	{
		user->locked = (user->pos + 4095) & ~4095;
	}

	user->maxSize = size;
	user->current = user;
	user->hunkUser.scheme = scheme;
	user->hunkUser.flags = flags;
	user->hunkUser.name = name;
	user->hunkUser.type = type;

	assert(!user->next);
	return &user->hunkUser;
}

/*
==============
Hunk_UserDefaultDestroy
==============
*/
void Hunk_UserDefaultDestroy(HunkUser *_user)
{
	HunkUserDefault* user;
	int pos;

	user = (HunkUserDefault*)_user;
	assert(user->hunkUser.scheme == HU_SCHEME_DEFAULT);
	if (user->next)
	{
		Hunk_UserDefaultDestroy(&user->next->hunkUser);
		user->current = user;
		user->next = NULL;
	}
	if (user->hunkUser.flags & 2)
	{
		user->pos = (psize_int)user->buf;
		user->locked = user->maxSize + user->pos;
	}
	else
	{
		pos = (((unsigned int)&_user[258].flags + 3) & ~4095);
		if ((void*)pos != (void*)((user->pos + 4095) & ~4095))
		{
			assert(user->pos - pos > 0);
			Z_VirtualDecommit((void*)pos, user->pos - pos);
		}
		user->pos = (psize_int)user->buf;
		user->locked = (user->pos + 4095) & ~4095;
		memset(user->buf, 0, 0xFD8u);
	}
}

/*
==============
Hunk_UserDefaultFree
==============
*/
void Hunk_UserDefaultFree(HunkUser *user, void *ptr)
{
	assert(user->scheme == HU_SCHEME_DEFAULT);

	if (user->flags & 8)
	{
		track_userhunk_free(ptr);
	}
}

/*
==============
Hunk_UserNullInit
==============
*/
HunkUser *Hunk_UserNullInit(void *buffer, int size, HU_ALLOCATION_SCHEME scheme, unsigned int flags, void *scheme_specific_data, const char *name, int type)
{
	HunkUser* user = (HunkUser*)buffer;
	user->scheme = HU_SCHEME_DEFAULT;
	user->name = 0;
	user->flags = 0;
	user->type = 0;

	user->flags = flags;
	user->scheme = scheme;
	user->name = name;
	user->type = type;
	return user;
}

/*
==============
Hunk_UserNullReset
==============
*/
void Hunk_UserNullReset(HunkUser *_user)
{
	_user->scheme = HU_SCHEME_DEFAULT;
	_user->flags = 0;
}

/*
==============
Hunk_UserNullDestroy
==============
*/
void Hunk_UserNullDestroy(HunkUser *_user)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Hunk_UserNullAlloc
==============
*/
void *Hunk_UserNullAlloc(HunkUser *_user, int size, int alignment, const char* name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Hunk_UserNullFree
==============
*/
void Hunk_UserNullFree(HunkUser *user, void* ptr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Hunk_UserCreateFromBuffer
==============
*/
HunkUser *Hunk_UserCreateFromBuffer(void *buffer, int size, HU_ALLOCATION_SCHEME scheme, unsigned int flags, void *scheme_specific_data, const char *name, int type)
{
	assert(scheme != HU_SCHEME_DEBUG);
	return g_HunkUserAllocationSchemeMap[scheme].Init(
		buffer,
		size,
		scheme,
		flags | 2,
		scheme_specific_data,
		name,
		type);
}

/*
==============
Hunk_UserCreate
==============
*/
HunkUser *Hunk_UserCreate(int size, HU_ALLOCATION_SCHEME scheme, unsigned int flags, void *scheme_specific_data, const char *name, int type)
{
	void* buffer;

	assert((flags & HF_FROMBUFFER) == 0);
	assert(scheme == HU_SCHEME_DEFAULT || scheme == HU_SCHEME_DEBUG);
	assertMsg((!(size % (4 * 1024))), "(size) = %i", size);
	if (scheme == HU_SCHEME_DEBUG)
	{
		buffer = Z_VirtualReserve(size);
		Z_VirtualCommit(buffer, size);
		flags |= 2;
	}
	else
	{
		buffer = Z_VirtualReserve(size);
		Z_VirtualCommit(buffer, sizeof(HunkUserDefault));
	}

	return (HunkUser*)g_HunkUserAllocationSchemeMap[scheme].Init(
		buffer,
		size,
		scheme,
		flags,
		scheme_specific_data,
		name,
		type);
}

/*
==============
Hunk_UserCreateNull
==============
*/
HunkUser *Hunk_UserCreateNull(HunkUserNull *user)
{
	return (HunkUser*)g_HunkUserAllocationSchemeMap[5].Init(
		user, 
		24, 
		HU_SCHEME_NULL, 
		2, 
		0, 
		"null", 
		0);
}

/*
==============
Hunk_UserAlloc
==============
*/
void *Hunk_UserAlloc(HunkUser *user, int size, int alignment, const char *name)
{
	return g_HunkUserAllocationSchemeMap[user->scheme].Alloc(
		user, 
		size, 
		alignment, 
		name);
}

/*
==============
Hunk_UserFree
==============
*/
void Hunk_UserFree(HunkUser *user, void *ptr)
{
	g_HunkUserAllocationSchemeMap[user->scheme].Free(user, ptr);
}

/*
==============
Hunk_UserReset
==============
*/
void Hunk_UserReset(HunkUser *user)
{
	g_HunkUserAllocationSchemeMap[user->scheme].Reset(user);
}

/*
==============
Hunk_UserDestroy
==============
*/
void Hunk_UserDestroy(HunkUser *user)
{
	g_HunkUserAllocationSchemeMap[user->scheme].Destroy(user);
}

/*
==============
Hunk_UserSetPos
==============
*/
void Hunk_UserSetPos(HunkUser *_user, void *pos)
{
	HunkUserDefault* user = (HunkUserDefault*)_user;
	assert(_user->scheme == HU_SCHEME_DEFAULT);
	assert((user->hunkUser.flags & HF_FIXEDSIZE) != 0);
	assert(pos >= user->buf);
	assert((psize_int)pos <= user->pos);
	user->pos = (psize_int)pos;
}

/*
==============
Hunk_CopyString
==============
*/
char *Hunk_CopyString(HunkUser *user, const char *in)
{
	char* out;

	out = (char*)Hunk_UserAlloc(user, strlen(in) + 1, 1, NULL);
	strcpy(out, in);

	return out;
}

/*
==============
Hunk_UserDefaultReset
==============
*/
void Hunk_UserDefaultReset(HunkUser *_user)
{
	HunkUserDefault* user;
	int pos;

	user = (HunkUserDefault*)_user;
	assert(user->hunkUser.scheme == HU_SCHEME_DEFAULT);
	if (user->next)
	{
		Hunk_UserDefaultDestroy(&user->next->hunkUser);
		user->current = user;
		user->next = NULL;
	}
	if (user->hunkUser.flags & 2)
	{
		user->pos = (psize_int)user->buf;
		user->locked = user->maxSize + user->pos;
	}
	else
	{
		pos = (((unsigned int)&_user[258].flags + 3) & ~4095);
		if ((void*)pos != (void*)((user->pos + 4095) & ~4095))
		{
			assert(user->pos - pos > 0);
			Z_VirtualDecommit((void*)pos, user->pos - pos);
		}
		user->pos = (psize_int)user->buf;
		user->locked = (user->pos + 4095) & ~4095;
		memset(user->buf, 0, 0xFD8u);
	}
}

/*
==============
Hunk_UserDefaultAlloc
==============
*/
void *Hunk_UserDefaultAlloc(HunkUser *_user, int size, int alignment, const char *name)
{
	int range;
	void* pos;
	HunkUserDefault* current;
	HunkUserDefault* user;

	user = (HunkUserDefault*)_user;

	assert(user);
	assert(user->hunkUser.scheme == HU_SCHEME_DEFAULT);
	assertMsg(static_cast<uint>(size) <= user->maxSize - offsetof(HunkUserDefault, buf),
		va("size: %d, maxSize: %d", size, user->maxSize - offsetof(HunkUserDefault, buf)));
	assert(!(alignment & (alignment - 1)));
	assert(alignment <= HUNK_MAX_ALIGNMENT);

	//alignment--;
	for (current = user->current; ; current = current->next)
	{
		pos = (void*)current->pos;
		if (((psize_int)pos % alignment) != 0)
		{
			pos = (void*)((psize_int)pos + (alignment - 1) & ~(alignment - 1));
		}

		if ((psize_int)pos + size <= current->end)
		{
			break;
		}

		if (_user->flags & 4 || _user->flags & 2)
		{
			Com_Error(ERR_FATAL, "Hunk_UserAlloc: out of memory");
		}

		user->current = (HunkUserDefault*)Hunk_UserCreate(user->maxSize, _user->scheme, _user->flags, NULL, _user->name, _user->type);
		current->next = user->current;
	}

	current->pos = (psize_int)pos + size;
	if (current->pos > current->locked)
	{
		range = ((current->pos + 4096) & ~4095) - current->locked;
		assert(range > 0);
		assert(range % PAGE_SIZE == 0);
		Z_VirtualCommit((void*)current->locked, range);
		current->locked += range;
	}

	if (user->hunkUser.flags & 8)
	{
		if (name)
		{
			track_userhunk_alloc(size, (psize_int)pos, name, _user->type);
		}
		else
		{
			track_userhunk_alloc(size, (psize_int)pos, _user->name, _user->type);
		}
	}
	return pos;
}

/*
==============
Hunk_UserStartup
==============
*/
void Hunk_UserStartup()
{
	assert(!g_DebugHunkUser);

	g_DebugHunkUser = Hunk_UserCreate(
		0x1700000,
		HU_SCHEME_DEBUG,
		0,
		NULL,
		"Hunk_InitDebugMemory",
		0);
}

/*
==============
Hunk_UserShutdown
==============
*/
void Hunk_UserShutdown()
{
	assert(g_DebugHunkUser);

	Hunk_UserDestroy(g_DebugHunkUser);
	g_DebugHunkUser = NULL;
}

