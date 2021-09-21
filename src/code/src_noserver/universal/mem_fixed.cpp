#include "types.h"
#include "functions.h"

/*
==============
Hunk_FixedInit
==============
*/
HunkUser *Hunk_FixedInit(void *buffer, int size, HU_ALLOCATION_SCHEME scheme, unsigned int flags, void *scheme_specific_data, const char *name, int type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Hunk_FixedReset
==============
*/
void Hunk_FixedReset(HunkUser *_user)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Hunk_FixedDestroy
==============
*/
void Hunk_FixedDestroy(HunkUser *_user)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Hunk_FixedAlloc
==============
*/
const char *Hunk_FixedAlloc(HunkUser *_user)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Hunk_FixedFree
==============
*/
void Hunk_FixedFree(HunkUser *_user, void *ptr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

