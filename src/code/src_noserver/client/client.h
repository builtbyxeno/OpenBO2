#include "types.h"
#include "vars.h"

static clientActive_t* clients;
static clientConnection_t* clientConnections;
static voiceCommunication_t cl_voiceCommunication[MAX_LOCAL_CLIENTS];

/*
==============
CL_GetLocalClientConnectionState
==============
*/
connstate_t CL_GetLocalClientConnectionState(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	connstate_t tmp;
	return tmp;
}

/*
==============
CL_LocalClient_IsCGameInitialized
==============
*/
unsigned int CL_LocalClient_IsCGameInitialized(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_GetLocalClientMigrationState
==============
*/
XModelRigidCullInfoContext *CL_GetLocalClientMigrationState(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_GetLocalClientGlobals
==============
*/
clientActive_t *CL_GetLocalClientGlobals(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_GetLocalClientUIGlobals
==============
*/
clientUIActive_t *CL_GetLocalClientUIGlobals(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_GetLocalClientConnection
==============
*/
clientConnection_t *CL_GetLocalClientConnection(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
CL_SetLocalClientMigrationState
==============
*/
void CL_SetLocalClientMigrationState(LocalClientNum_t client, clientMigState_t state)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_SetLocalClientConnectionState
==============
*/
void CL_SetLocalClientConnectionState(LocalClientNum_t client, connstate_t state)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_LocalClient_SetCUIFlag
==============
*/
void CL_LocalClient_SetCUIFlag(LocalClientNum_t localClientNum, int flag)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_LocalClient_ClearCUIFlag
==============
*/
void CL_LocalClient_ClearCUIFlag(LocalClientNum_t localClientNum, int flag)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_LocalClient_IsInvited
==============
*/
unsigned int CL_LocalClient_IsInvited(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_LocalClient_IsDisplayingKeyCatcherHud
==============
*/
unsigned int CL_LocalClient_IsDisplayingKeyCatcherHud(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

