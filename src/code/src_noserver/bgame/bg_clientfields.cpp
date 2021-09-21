#include "types.h"
#include "functions.h"

/*
==============
BG_GetFieldOffset
==============
*/
int BG_GetFieldOffset(const NetField *pFields, int numFields, const char *pName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_InitClientFields
==============
*/
void BG_InitClientFields()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_ShutdownClientFields
==============
*/
void BG_ShutdownClientFields()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_SortClientFields
==============
*/
int BG_SortClientFields(const void *arg0, const void *arg1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetClientFieldSetFromSetName
==============
*/
int BG_GetClientFieldSetFromSetName(const char *pSetName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetClientFieldSetName
==============
*/
const char *BG_GetClientFieldSetName(int system)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_GetClientFieldTypeFromTypeName
==============
*/
unsigned int BG_GetClientFieldTypeFromTypeName(unsigned __int16 typeName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_ReportClientFieldAllocation
==============
*/
void BG_ReportClientFieldAllocation()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_ReportClientFields
==============
*/
void BG_ReportClientFields(const char *pMsg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetClientFieldsHash
==============
*/
unsigned int BG_GetClientFieldsHash()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetClientFieldsHighestVersionUsed
==============
*/
unsigned int BG_GetClientFieldsHighestVersionUsed()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_BuildHashFromClientFieldSystem
==============
*/
unsigned int BG_BuildHashFromClientFieldSystem(bgsClientFields_s *pSys)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_RemoveObsoleteClientFields
==============
*/
void BG_RemoveObsoleteClientFields()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_PerformClientFieldSort
==============
*/
void BG_PerformClientFieldSort()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetClientFieldVersion
==============
*/
unsigned int BG_GetClientFieldVersion(const char *pSetName, const char *pFieldName)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_AllocateBitSpaceToFields
==============
*/
void BG_AllocateBitSpaceToFields()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_FinalizeClientFieldRegistration
==============
*/
void BG_FinalizeClientFieldRegistration()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetClientField
==============
*/
clientField_s *BG_GetClientField(int system, const char *pFieldName, bool bErrorIfNotFound)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_AddClientfieldCodeCallback
==============
*/
void BG_AddClientfieldCodeCallback(int system, const char *pFieldName, void (*cbFunc)(LocalClientNum_t, unsigned int, float, float, bool, bool, const char *, bool), bool bFailGracefully)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_AddClientfieldCodeCallback
==============
*/
void BG_AddClientfieldCodeCallback(int system, const char *pFieldName, void (*cbFunc)(LocalClientNum_t, unsigned int, unsigned int, unsigned int, bool, bool, const char *, bool), bool bFailGracefully)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_RegisterClientFieldInternal
==============
*/
clientField_s *BG_RegisterClientFieldInternal(int system, const char *pFieldName, int version, unsigned int numBits, unsigned int fieldType, int scriptFunc, int bSplitScreenHostOnly, int bCallbacksFor0WhenNew)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
BG_RegisterClientField
==============
*/
void BG_RegisterClientField(int system, const char *pFieldName, int version, unsigned int numBits, unsigned int fieldType, int scriptFunc, int bSplitScreenHostOnly, int bCallbacksFor0WhenNew)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_RegisterClientField
==============
*/
void BG_RegisterClientField(int system, const char *pFieldName, int version, unsigned int numBits, unsigned int fieldType, float minFloatVal, float maxFloatVal, int scriptFunc, int bSplitScreenHostOnly, int bCallbacksFor0WhenNew)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetClientFieldIntVal
==============
*/
unsigned int BG_GetClientFieldIntVal(int system, const char *pFieldName, void *pData)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_SetClientFieldIntVal
==============
*/
void BG_SetClientFieldIntVal(int system, clientField_s *pField, void *pData, int val)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_GetClientFieldFloatValInternal
==============
*/
double BG_GetClientFieldFloatValInternal(clientField_s *pField, unsigned int val)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_GetClientFieldFloatVal
==============
*/
double BG_GetClientFieldFloatVal(int system, const char *pFieldName, void *pData)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BG_SetClientFieldFloatVal
==============
*/
void BG_SetClientFieldFloatVal(int system, clientField_s *pField, void *pData, float val)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_ReportPendingClientfieldCallbackEvents
==============
*/
void BG_ReportPendingClientfieldCallbackEvents(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_AddClientfieldCallbackEvent
==============
*/
void BG_AddClientfieldCallbackEvent(LocalClientNum_t localClientNum, unsigned int entNum, clientField_s *pField, unsigned int oldInt, unsigned int newInt, bool bNewEnt, bool bInitialSnap, bool bWasDemoJump)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_AddClientfieldCallbackEvent
==============
*/
void BG_AddClientfieldCallbackEvent(LocalClientNum_t localClientNum, unsigned int entNum, clientField_s *pField, float oldFloat, float newFloat, bool bNewEnt, bool bInitialSnap, bool bWasDemoJump)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_ExecuteClientFieldCallbacks
==============
*/
void BG_ExecuteClientFieldCallbacks(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BG_ProcessClientFieldSet
==============
*/
void BG_ProcessClientFieldSet(int systemIndex, LocalClientNum_t localClientNum, int entNum, void *pOldData, void *pNewData, bool bNewEnt, bool bWasDemoJump)
{
	UNIMPLEMENTED(__FUNCTION__);
}

