#include "types.h"

/*
==============
BB_InitStringCache
==============
*/
void BB_InitStringCache()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BB_ClearStringCache
==============
*/
void BB_ClearStringCache()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BB_HashString
==============
*/
unsigned int BB_HashString(const char *str, int len)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BB_CacheString
==============
*/
int BB_CacheString(const char *str, int len)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BB_WriteString
==============
*/
void __cdecl BB_WriteString(bb_msg_t *msg, const char *str, int len)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BB_MsgInit
==============
*/
void BB_MsgInit(bb_msg_t *msg, void *data, int maxsize)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BB_MsgInitPPP
==============
*/
void BB_MsgInitPPP(bb_msg_t *msg, void *pppHashTable, int size)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BB_InitDefinitions
==============
*/
void BB_InitDefinitions()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BB_RewriteDefinitions
==============
*/
void BB_RewriteDefinitions(bb_msg_t *a1, const void *a2)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BB_BeginDefinition
==============
*/
int __cdecl BB_BeginDefinition(const char *name)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BB_ParseParameter
==============
*/
unsigned __int8 BB_ParseParameter(const char *string, int len)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BB_GetDefinitionMap
==============
*/
DefinitionMap *BB_GetDefinitionMap(unsigned int nameHash, unsigned int formatHash)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BB_ParseAndCacheFormatString
==============
*/
int BB_ParseAndCacheFormatString(bb_msg_t *msg, const char *name, const char *fmt, int *parameterCount, const unsigned __int8 **parameters)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BB_WriteFormatParameters
==============
*/
void BB_WriteFormatParameters(const void *a1, bb_msg_t *msg, int parameterCount, const unsigned __int8 *parameters, char *args)
{
	UNIMPLEMENTED(__FUNCTION__);
}

