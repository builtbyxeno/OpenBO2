#include "types.h"
#include "functions.h"

/*
==============
SV_IsMigrating
==============
*/
bool SV_IsMigrating()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_MigrationIsWaitingForPlayers
==============
*/
int SV_MigrationIsWaitingForPlayers()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_MigrationReset
==============
*/
void SV_MigrationReset()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_MigrationInit
==============
*/
void SV_MigrationInit()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ClientRemoteAddr
==============
*/
netadr_t *ClientRemoteAddr(const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
IsClientConnected
==============
*/
bool IsClientConnected(const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SendToClient
==============
*/
bool SendToClient(const ClientNum_t clientNum, const unsigned __int8 *data, int len)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SendStartMessage
==============
*/
void SendStartMessage(const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CreateBlock
==============
*/
void CreateBlock(const int blockNum, Block *block)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SendBlock
==============
*/
bool SendBlock(const ClientNum_t clientNum, Block *block)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SendSave
==============
*/
void SendSave()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SendMigrateTo
==============
*/
void SendMigrateTo(const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SendHeader
==============
*/
void SendHeader(char *a1)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PickNewHost
==============
*/
void PickNewHost()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_GetMigrationCount
==============
*/
int SV_GetMigrationCount()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_MigrationStart
==============
*/
void SV_MigrationStart(const char *reason)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HasTimedOut
==============
*/
bool HasTimedOut(const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
TimedOut
==============
*/
void TimedOut(const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CheckTimeouts
==============
*/
void CheckTimeouts(void *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SendMigrateToMessages
==============
*/
void SendMigrateToMessages()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SendFrame
==============
*/
void SendFrame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_MigrationUpdateCount
==============
*/
void SV_MigrationUpdateCount(const int count)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_MigrationFrame
==============
*/
void SV_MigrationFrame()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HandleRatingMsg
==============
*/
void HandleRatingMsg(const ClientNum_t clientNum, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HandleSaveAckMsg
==============
*/
void HandleSaveAckMsg(const ClientNum_t clientNum, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HandleHeaderAckMsg
==============
*/
void HandleHeaderAckMsg(const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
HandleMigrateToAckMsg
==============
*/
void HandleMigrateToAckMsg(const ClientNum_t clientNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SV_MigrationPacket
==============
*/
char SV_MigrationPacket(const char *cmd, netadr_t from, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SV_MigrationEnd
==============
*/
void SV_MigrationEnd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

