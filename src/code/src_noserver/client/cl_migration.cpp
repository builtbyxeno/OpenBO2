#include "types.h"
#include "functions.h"

/*
==============
CL_MigrationInit
==============
*/
void CL_MigrationInit()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PingAck
==============
*/
void PingAck(const LocalClientNum_t localClientNum, netadr_t to, const int time)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SendToHost
==============
*/
void SendToHost(const LocalClientNum_t localClientNum, const char *cmd, const unsigned __int8 *data, int len)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Migration_SendMigrateToAck
==============
*/
void Migration_SendMigrateToAck(const char *a1, LocalClientNum_t a2, char *localClientNum, const LocalClientNum_t a4)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetHostRating
==============
*/
int GetHostRating(const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_SaveMigrationPers
==============
*/
void CL_SaveMigrationPers(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_LoadMigrationPers
==============
*/
void CL_LoadMigrationPers(LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HandleSaveDataMsg
==============
*/
void HandleSaveDataMsg(const LocalClientNum_t localClientNum, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HandlePingMsg
==============
*/
void __cdecl HandlePingMsg(const LocalClientNum_t localClientNum, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HandlePingAckMsg
==============
*/
void HandlePingAckMsg(const LocalClientNum_t localClientNum, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HandleHeaderMsg
==============
*/
void __cdecl HandleHeaderMsg(const LocalClientNum_t localClientNum, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CL_MigrationPacket
==============
*/
char CL_MigrationPacket(const LocalClientNum_t localClientNum, const char *cmd, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CL_Migrate
==============
*/
void CL_Migrate(LocalClientNum_t localClientNum, XSESSION_INFO *hostInfo, netadr_t addr)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HandleStartMsg
==============
*/
void HandleStartMsg(char *a1, const LocalClientNum_t localClientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

