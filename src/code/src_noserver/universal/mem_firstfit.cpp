#include "types.h"
#include "functions.h"

/*
==============
Hunk_FirstFitInit
==============
*/
HunkUser *Hunk_FirstFitInit(void *buffer, int size, HU_ALLOCATION_SCHEME scheme, unsigned int flags, void *scheme_specific_data, const char *name, int type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Hunk_FirstFitReset
==============
*/
void Hunk_FirstFitReset(HunkUser *_user)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Hunk_FirstFitDestroy
==============
*/
void Hunk_FirstFitDestroy(HunkUser *_user)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Hunk_FirstFitAlloc
==============
*/
void *Hunk_FirstFitAlloc(HunkUser *_user, int size, int alignment)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
Hunk_FirstFitFree
==============
*/
void Hunk_FirstFitFree(HunkUser *_user, void *ptr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

