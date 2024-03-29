#include "types.h"

/*
==============
FX_GetProfileEntry
==============
*/
FxProfileEntry *FX_GetProfileEntry(const FxEffectDef *effectDef, FxProfileEntry *entryPool, int *entryCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
FX_CompareProfileEntries
==============
*/
int FX_CompareProfileEntries(const void *e0, const void *e1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_ComparePriorityDebugEntries
==============
*/
int FX_ComparePriorityDebugEntries(const void *e0, const void *e1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_DrawPriorityDebug
==============
*/
void FX_DrawPriorityDebug(LocalClientNum_t clientIndex, void (*drawFunc)(const char *, vec2_t *), vec2_t *profilePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_CompareOccQueryDebugEntries
==============
*/
int FX_CompareOccQueryDebugEntries(const void *e0, const void *e1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FX_DrawOccQueryDebug
==============
*/
void FX_DrawOccQueryDebug(LocalClientNum_t clientIndex, void (*drawFunc)(const char *, vec2_t *), vec2_t *profilePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
typeAsString
==============
*/
const char *typeAsString(unsigned __int8 type)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
FX_DrawMarkProfile_MarkPrint
==============
*/
void FX_DrawMarkProfile_MarkPrint(FxMarksSystem *marksSystem, unsigned __int16 head, const char *name, int index, void (*drawFunc)(const char *, vec2_t *), vec2_t *profilePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawMarkProfile
==============
*/
void __cdecl FX_DrawMarkProfile(LocalClientNum_t clientIndex, void (__cdecl *drawFunc)(const char *, vec2_t *), vec2_t *profilePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DebugShowNamesInWorld
==============
*/
void FX_DebugShowNamesInWorld(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_ProfileSingleEffect
==============
*/
void FX_ProfileSingleEffect(FxSystem *system, const FxEffect *effect, FxProfileEntry *entry)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
FX_DrawProfile
==============
*/
void FX_DrawProfile(LocalClientNum_t clientIndex, void (*drawFunc)(const char *, vec2_t *), vec2_t *profilePos)
{
	UNIMPLEMENTED(__FUNCTION__);
}

