#include "types.h"

/*
==============
UILocalVar_Init
==============
*/
void UILocalVar_Init(UILocalVarContext *context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UILocalVar_Shutdown
==============
*/
void UILocalVar_Shutdown(UILocalVarContext *context)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UILocalVar_FindLocation
==============
*/
char UILocalVar_FindLocation(UILocalVarContext *context, const char *name, unsigned int *hashForName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UILocalVar_Find
==============
*/
const UILocalVar *UILocalVar_Find(UILocalVarContext *context, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UILocalVar_FindOrCreate
==============
*/
UILocalVar *UILocalVar_FindOrCreate(UILocalVarContext *context, const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UILocalVar_GetBool
==============
*/
BOOL UILocalVar_GetBool(const UILocalVar *var)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UILocalVar_GetInt
==============
*/
/*UILocalVar::<unnamed_type_u> UILocalVar_GetInt(const UILocalVar *var)
{
	UNIMPLEMENTED(__FUNCTION__);
	UILocalVar::<unnamed_type_u> tmp;
	return tmp;
}*/

/*
==============
UILocalVar_GetFloat
==============
*/
double UILocalVar_GetFloat(const UILocalVar *var)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
UILocalVar_GetString
==============
*/
char *UILocalVar_GetString(const UILocalVar *var, char *stringBuf, int size)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
UILocalVar_SetBool
==============
*/
void UILocalVar_SetBool(const UILocalVar *var, bool b)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UILocalVar_SetInt
==============
*/
void UILocalVar_SetInt(const UILocalVar *var, int i)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UILocalVar_SetFloat
==============
*/
void UILocalVar_SetFloat(const UILocalVar *var, float f)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UILocalVar_SetString
==============
*/
void UILocalVar_SetString(const UILocalVar *var, const char *s)
{
	UNIMPLEMENTED(__FUNCTION__);
}

