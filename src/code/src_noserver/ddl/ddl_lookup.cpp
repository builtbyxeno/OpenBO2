#include "types.h"

/*
==============
DDL_Lookup_FindInStruct
==============
*/
ddlMemberDef_t *DDL_Lookup_FindInStruct(ddlStructDef_t *structDef, const ddlDef_t *ddl, int parentOffset, int searchOffset, int *arrayIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DDL_Lookup_ClearState
==============
*/
void DDL_Lookup_ClearState(ddlState_t *searchState)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
DDL_Lookup_FindMemberDefByLName
==============
*/
ddlMemberDef_t *DDL_Lookup_FindMemberDefByLName(ddlStructDef_t *structDef, int hashStartIndex, const char *memberNameLowercase)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DDL_Lookup_FindMemberDef
==============
*/
ddlMemberDef_t *DDL_Lookup_FindMemberDef(const char *memberName, ddlStructDef_t *structDef)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DDL_Lookup_MoveToIndex
==============
*/
ddlMemberDef_t *DDL_Lookup_MoveToIndex(const ddlState_t *searchState, int arrayIndex, ddlState_t *resultState, int checkValidIndex)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
DDL_Lookup_FindEnumIndexByName
==============
*/
int DDL_Lookup_FindEnumIndexByName(ddlEnumDef_t *enumDef, int hashStartIndex, const char *memberName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_Lookup_MoveTo
==============
*/
int DDL_Lookup_MoveTo(const ddlState_t *searchState, const char *name, ddlState_t *resultState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_Lookup_MoveNext
==============
*/
int DDL_Lookup_MoveNext(const ddlState_t *searchState, ddlState_t *resultState)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DDL_Lookup_MoveToStart
==============
*/
BOOL DDL_Lookup_MoveToStart(ddlState_t *resultState, ddlDef_t *ddl)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

