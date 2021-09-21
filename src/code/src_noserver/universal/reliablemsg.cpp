#include "types.h"
#include "functions.h"

/*
==============
RMsg_FindMessageSlot
==============
*/
int RMsg_FindMessageSlot(const int clientSlot, unsigned __int8 sequenceNum)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RMsg_FindOldestSeq
==============
*/
int RMsg_FindOldestSeq(const int clientSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RMsg_FindSlotForAddr
==============
*/
int RMsg_FindSlotForAddr(netadr_t *to)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RMsg_DropAllPacketsToAddr
==============
*/
void RMsg_DropAllPacketsToAddr(netadr_t *notthis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RMsg_Init
==============
*/
void RMsg_Init()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RMsg_AddMessageAtMsgSlot
==============
*/
void RMsg_AddMessageAtMsgSlot(const int clientSlot, const int msgSlot, netsrc_t from, netadr_t *to, const unsigned __int8 *msg, const int length)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RMsg_ShiftMessagesBackInBuffer
==============
*/
void RMsg_ShiftMessagesBackInBuffer(reliableClient *client, int bytesShifted)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RMsg_AddMessageForClient
==============
*/
char __cdecl RMsg_AddMessageForClient(int clientSlot, netsrc_t from, netadr_t *to, const unsigned __int8 *msg, int length)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RMsg_AddMessage
==============
*/
char RMsg_AddMessage(netsrc_t from, netadr_t *to, msg_t *msg)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RMsg_AddPrint
==============
*/
char RMsg_AddPrint(netsrc_t from, netadr_t *to, const char *line)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RMsg_AckSequence
==============
*/
void RMsg_AckSequence(netadr_t *from, unsigned __int8 sequenceNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RMsg_CountOutstandingMessages
==============
*/
int RMsg_CountOutstandingMessages(const int clientSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RMsg_AckMsgSlot
==============
*/
void RMsg_AckMsgSlot(reliableClient *client, int clientSlot, int msgSlot)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RMsg_MarkPacketReceived
==============
*/
void RMsg_MarkPacketReceived(netadr_t *from, unsigned __int8 sequenceNum)
{
	UNIMPLEMENTED(__FUNCTION__);
}

