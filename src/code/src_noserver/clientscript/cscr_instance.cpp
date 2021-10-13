#include "types.h"
#include "vars.h"

/*
==============
Scr_ClearScrVarDebugPub
==============
*/
void Scr_ClearScrVarDebugPub(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_ResetScrVarDebugPub
==============
*/
void Scr_ResetScrVarDebugPub(scriptInstance_t inst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_ClearScrStringDebugGlob
==============
*/
void Scr_ClearScrStringDebugGlob()
{
	gScrStringDebugGlob = NULL;
}

/*
==============
Scr_ResetScrStringDebugGlob
==============
*/
void Scr_ResetScrStringDebugGlob()
{
	gScrStringDebugGlob = &gScrStringDebugGlobBuff;
}

