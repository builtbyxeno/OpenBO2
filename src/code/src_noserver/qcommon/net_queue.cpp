#include "types.h"

/*
==============
PacketQueueBlock_Enqueue
==============
*/
PacketQueueEntry *PacketQueueBlock_Enqueue(PacketQueueBlock *block, unsigned int flags, int dequeueTime, netsrc_t sock, const netadr_t *addr, int length, const void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
PacketQueueBlock_Dequeue
==============
*/
bool PacketQueueBlock_Dequeue(PacketQueueBlock *block)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PacketQueueBlock_Peek
==============
*/
PacketQueueEntry *PacketQueueBlock_Peek(PacketQueueBlock *block)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
PacketQueue_AddTailBlock
==============
*/
bool PacketQueue_AddTailBlock(PacketQueue *queue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PacketQueue_RemoveHeadBlock
==============
*/
void PacketQueue_RemoveHeadBlock(PacketQueue *queue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PacketQueue_Peek
==============
*/
PacketQueueEntry *PacketQueue_Peek(PacketQueue *queue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
PacketQueue_EnqueueInternal
==============
*/
PacketQueueEntry *PacketQueue_EnqueueInternal(PacketQueue *queue, unsigned int flags, int dequeueTime, netsrc_t sock, const netadr_t *addr, int length, const void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
PacketQueue_DequeueInternal
==============
*/
bool PacketQueue_DequeueInternal(PacketQueue *queue)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PacketQueue_Enqueue
==============
*/
PacketQueueEntry *PacketQueue_Enqueue(PacketQueue *queue, unsigned int flags, netsrc_t sock, const netadr_t *addr, int length, const void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
PacketQueue_Dequeue
==============
*/
bool PacketQueue_Dequeue(PacketQueue *queue, unsigned int *flags, netsrc_t *sock, netadr_t *addr, int maxlength, int *length, void *data)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_InitQueues
==============
*/
void NET_InitQueues()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NET_InitQueue
==============
*/
void NET_InitQueue(PacketQueue *queue, const char *name, bool emulation)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
NET_DequeuePacket
==============
*/
bool NET_DequeuePacket(char *a1, PacketQueue *queue, unsigned int *flags, netsrc_t *sock, netadr_t *addr, int maxlength, int *length)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_EnqueuePacket
==============
*/
bool __cdecl NET_EnqueuePacket(PacketQueue *queue, unsigned int flags, netsrc_t sock, const netadr_t *addr, int length)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NET_QueueCmd
==============
*/
void NET_QueueCmd()
{
	UNIMPLEMENTED(__FUNCTION__);
}

