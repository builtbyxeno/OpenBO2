#include "types.h"
#include "vars.h"
#include <qcommon/qcommon_public.h>
#include <clientscript/clientscript_public.h>

enum
{
	MEMORY_NODE_BITS = 0x10,
	MEMORY_NODE_COUNT = 0x10000,
	MT_SIZE = 0x100000,
	REFSTRING_STRING_OFFSET = 0x4,
};

scrMemTreeGlob_t gScrMemTreeGlob;
MemoryNode gScrMemTreeServerNodes[MEMORY_NODE_COUNT];
unsigned __int16 gScrMemTreeServerHead[17];
scrMemTreeDebugGlob_t gScrMemTreeDebugGlob;

/*
==============
TRACK_scr_memorytree
==============
*/
void TRACK_scr_memorytree()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MT_GetSubTreeSize
==============
*/
int MT_GetSubTreeSize(int nodeNum)
{
	int treeSize;

	if (nodeNum)
	{
		treeSize = MT_GetSubTreeSize(gScrMemTreeGlob.nodes[nodeNum].next);
		return treeSize + MT_GetSubTreeSize(gScrMemTreeGlob.nodes[nodeNum].prev) + 1;
	}
	else
	{
		return 0;
	}
}

/*
==============
MT_DumpTree
==============
*/
void MT_DumpTree(void)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Scr_GetStringUsage
==============
*/
int Scr_GetStringUsage()
{
	return gScrMemTreeGlob.totalAllocBuckets;
}

/*
==============
MT_InitBits
==============
*/
void MT_InitBits()
{
	char bits;
	int temp;
	int i;

	for (i = 0; i < 256; ++i)
	{
		bits = 0;
		for (temp = i; temp; temp >>= 1)
		{
			if (temp & 1)
			{
				++bits;
			}
		}

		gScrMemTreeGlob.numBits[i] = bits;
		for (bits = 8; i & ((1 << bits) - 1); --bits)
		{
		}

		gScrMemTreeGlob.leftBits[i] = bits;
		bits = 0;
		for (temp = i; temp; temp >>= 1)
		{
			++bits;
		}
		gScrMemTreeGlob.logBits[i] = bits;
	}
}

/*
==============
MT_GetScore
==============
*/
int MT_GetScore(int num)
{
	char bits;

	assert(num != 0);

	union MTnum_t
	{
		int i;
		uint8_t b[4];
	};

	MTnum_t mtnum;

	mtnum.i = MEMORY_NODE_COUNT - num;
	assert(mtnum.i != 0);

	bits = gScrMemTreeGlob.leftBits[mtnum.b[0]];
	if (!mtnum.b[0])
	{
		bits += gScrMemTreeGlob.leftBits[mtnum.b[1]];
	}
	return mtnum.i - (gScrMemTreeGlob.numBits[mtnum.b[1]] + gScrMemTreeGlob.numBits[mtnum.b[0]]) + (1 << bits);
}

/*
==============
MT_AddMemoryNode
==============
*/
void MT_AddMemoryNode(int newNode, int size)
{
	int node;
	int nodeNum;
	int newScore;
	uint16_t* parentNode;
	int level;
	int score;

	assert(size >= 0 && size <= MEMORY_NODE_BITS);

	parentNode = &gScrMemTreeGlob.head[size];
	node = gScrMemTreeGlob.head[size];
	if (gScrMemTreeGlob.head[size])
	{
		newScore = MT_GetScore(newNode);
		nodeNum = 0;
		level = MEMORY_NODE_COUNT;
		do
		{
			assert(newNode != node);
			score = MT_GetScore(node);

			assert(score != newScore);

			if (score < newScore)
			{
				while (1)
				{
					assert(node == *parentNode);
					assert(node != newNode);

					*parentNode = newNode;
					gScrMemTreeGlob.nodes[newNode] = gScrMemTreeGlob.nodes[node];
					if (!node)
					{
						break;
					}
					level >>= 1;

					assert(node != nodeNum);

					if (node >= nodeNum)
					{
						parentNode = &gScrMemTreeGlob.nodes[newNode].next;
						nodeNum += level;
					}
					else
					{
						parentNode = &gScrMemTreeGlob.nodes[newNode].prev;
						nodeNum -= level;
					}
					newNode = node;
					node = *parentNode;
				}
				return;
			}
			level >>= 1;

			assert(newNode != nodeNum);

			if (newNode >= nodeNum)
			{
				parentNode = &gScrMemTreeGlob.nodes[node].next;
				nodeNum += level;
			}
			else
			{
				parentNode = &gScrMemTreeGlob.nodes[node].prev;
				nodeNum -= level;
			}

			node = *parentNode;
		} while (node);
	}

	*parentNode = newNode;
	gScrMemTreeGlob.nodes[newNode].prev = 0;
	gScrMemTreeGlob.nodes[newNode].next = 0;
}

/*
==============
MT_RemoveMemoryNode
==============
*/
bool MT_RemoveMemoryNode(int oldNode, int size)
{
	MemoryNode tempNodeValue;
	int node;
	MemoryNode oldNodeValue;
	int nodeNum;
	uint16_t* parentNode;
	int prevScore;
	int nextScore;
	int level;

	assert(size >= 0 && size <= MEMORY_NODE_BITS);

	nodeNum = 0;
	level = MEMORY_NODE_COUNT;
	parentNode = &gScrMemTreeGlob.head[size];
	for (node = *parentNode; node; node = *parentNode)
	{
		if (oldNode == node)
		{
			oldNodeValue = gScrMemTreeGlob.nodes[oldNode];

			while (1)
			{
				if (oldNodeValue.prev)
				{
					if (oldNodeValue.next)
					{
						prevScore = MT_GetScore(oldNodeValue.prev);
						nextScore = MT_GetScore(oldNodeValue.next);

						assert(prevScore != nextScore);

						if (prevScore >= nextScore)
						{
							oldNode = oldNodeValue.prev;
							*parentNode = oldNodeValue.prev;
							parentNode = &gScrMemTreeGlob.nodes[oldNodeValue.prev].prev;
						}
						else
						{
							oldNode = oldNodeValue.next;
							*parentNode = oldNodeValue.next;
							parentNode = &gScrMemTreeGlob.nodes[oldNodeValue.next].next;
						}
					}
					else
					{
						oldNode = oldNodeValue.prev;
						*parentNode = oldNodeValue.prev;
						parentNode = &gScrMemTreeGlob.nodes[oldNodeValue.prev].prev;
					}
				}
				else
				{
					oldNode = oldNodeValue.next;
					*parentNode = oldNodeValue.next;
					if (!oldNodeValue.next)
					{
						return true;
					}
					parentNode = &gScrMemTreeGlob.nodes[oldNodeValue.next].next;
				}

				assert(oldNode != 0);

				tempNodeValue = oldNodeValue;
				oldNodeValue = gScrMemTreeGlob.nodes[oldNode];
				gScrMemTreeGlob.nodes[oldNode] = tempNodeValue;
			}
		}

		if (oldNode == nodeNum)
		{
			return false;
		}

		level >>= 1;
		if (oldNode >= nodeNum)
		{
			parentNode = &gScrMemTreeGlob.nodes[node].next;
			nodeNum += level;
		}
		else
		{
			parentNode = &gScrMemTreeGlob.nodes[node].prev;
			nodeNum -= level;
		}
	}

	return false;
}

/*
==============
MT_RemoveHeadMemoryNode
==============
*/
void MT_RemoveHeadMemoryNode(int size)
{
	MemoryNode tempNodeValue;
	int oldNode;
	MemoryNode oldNodeValue;
	uint16_t* parentNode;
	int prevScore;
	int nextScore;

	assert(size >= 0 && size <= MEMORY_NODE_BITS);

	parentNode = &gScrMemTreeGlob.head[size];
	oldNodeValue = gScrMemTreeGlob.nodes[*parentNode];

	while (1)
	{
		if (!oldNodeValue.prev)
		{
			oldNode = oldNodeValue.next;
			*parentNode = oldNodeValue.next;
			if (!oldNode)
			{
				break;
			}
			parentNode = &gScrMemTreeGlob.nodes[oldNode].next;
		}
		else
		{
			if (oldNodeValue.next)
			{
				prevScore = MT_GetScore(oldNodeValue.prev);
				nextScore = MT_GetScore(oldNodeValue.next);

				assert(prevScore != nextScore);

				if (prevScore >= nextScore)
				{
					oldNode = oldNodeValue.prev;
					*parentNode = oldNode;
					parentNode = &gScrMemTreeGlob.nodes[oldNode].prev;
				}
				else
				{
					oldNode = oldNodeValue.next;
					*parentNode = oldNode;
					parentNode = &gScrMemTreeGlob.nodes[oldNode].next;
				}
			}
			else
			{
				oldNode = oldNodeValue.prev;
				*parentNode = oldNode;
				parentNode = &gScrMemTreeGlob.nodes[oldNode].prev;
			}
		}

		assert(oldNode != 0);

		tempNodeValue = oldNodeValue;
		oldNodeValue = gScrMemTreeGlob.nodes[oldNode];
		gScrMemTreeGlob.nodes[oldNode] = tempNodeValue;
	}
}

/*
==============
MT_Init
==============
*/
void MT_Init()
{
	int i;

	Sys_EnterCriticalSection(CRITSECT_MEMORY_TREE);
	gScrMemTreePub.mt_buffer = (char*)gScrMemTreeServerNodes;
	gScrMemTreeGlob.nodes = gScrMemTreeServerNodes;
	gScrMemTreeGlob.head = gScrMemTreeServerHead;
	MT_InitBits();
	for (i = 0; i <= MEMORY_NODE_BITS; ++i)
	{
		gScrMemTreeGlob.head[i] = 0;
	}

	gScrMemTreeGlob.nodes->prev = 0;
	gScrMemTreeGlob.nodes->next = 0;
	for (i = 0; i < MEMORY_NODE_BITS; ++i)
	{
		MT_AddMemoryNode( 1 << i, i);
	}

	gScrMemTreeGlob.totalAlloc = 0;
	gScrMemTreeGlob.totalAllocBuckets = 0;
	memset(gScrMemTreeDebugGlob.mt_usage, 0, MEMORY_NODE_COUNT);
	memset(gScrMemTreeDebugGlob.mt_usage_size, 0, MEMORY_NODE_COUNT);
	Sys_LeaveCriticalSection(CRITSECT_MEMORY_TREE);
}

/*
==============
MT_Error
==============
*/
inline void MT_Error(const char* funcName, int numBytes)
{
	MT_DumpTree();
	Com_Printf(CON_CHANNEL_SCRIPT, "%s: failed memory allocation of %d bytes for script usage\n", funcName, numBytes);
	if (Sys_IsServerThread())
	{
		Scr_TerminalError(SCRIPTINSTANCE_SERVER, "failed memory allocation for script usage");
	}
	else
	{
		Com_Error(ERR_DROP, "\x15" "%s: failed allocation of %d bytes for script usage", funcName, numBytes);
	}
}

/*
==============
MT_GetSize
==============
*/
int MT_GetSize(int numBytes)
{
	int numBuckets;

	assert(numBytes > 0);
	if (numBytes >= 0x10000)
	{
		MT_Error("MT_GetSize: max allocation exceeded", numBytes);
		return 0;
	}

	numBuckets = (numBytes + 15) / 16 - 1;
	if (numBuckets > 255)
	{
		return gScrMemTreeGlob.logBits[numBuckets >> 8] + 8;
	}

	return gScrMemTreeGlob.logBits[numBuckets];
}

/*
==============
MT_AllocIndex
==============
*/
unsigned short MT_AllocIndex(int numBytes, int type)
{
	int nodeNum;
	int size;
	int newSize;

	size = MT_GetSize(numBytes);
	assert(size >= 0 && size <= MEMORY_NODE_BITS);

	Sys_EnterCriticalSection(CRITSECT_MEMORY_TREE);
	for (newSize = size; ; ++newSize)
	{
		if (newSize > MEMORY_NODE_BITS)
		{
			Sys_LeaveCriticalSection(CRITSECT_MEMORY_TREE);
			MT_Error("MT_AllocIndex", numBytes);
			return 0;
		}
		nodeNum = gScrMemTreeGlob.head[newSize];
		if (gScrMemTreeGlob.head[newSize])
		{
			break;
		}
	}

	MT_RemoveHeadMemoryNode(newSize);
	while (newSize != size)
	{
		--newSize;
		MT_AddMemoryNode(nodeNum + (1 << newSize), newSize);
	}

	assertMsg((nodeNum >= 0 && nodeNum < MEMORY_NODE_COUNT), "(nodeNum) = %i", nodeNum);
	++gScrMemTreeGlob.totalAlloc;
	++gScrMemTreeGlob.avgAlloc;
	gScrMemTreeGlob.avgAllocBytes += numBytes;
	gScrMemTreeGlob.totalAllocBuckets += 1 << size;

	assert(type);
	assertMsg((!gScrMemTreeDebugGlob.mt_usage[nodeNum]), "MT_NodeInfoString( inst, nodeNum )) = %s",
		MT_NodeInfoString(nodeNum));
	assertMsg((!gScrMemTreeDebugGlob.mt_usage_size[nodeNum]), "(MT_NodeInfoString( inst, nodeNum )) = %s",
		MT_NodeInfoString(nodeNum));

	gScrMemTreeDebugGlob.mt_usage[nodeNum] = type;
	gScrMemTreeDebugGlob.mt_usage_size[nodeNum] = size;
	Sys_LeaveCriticalSection(CRITSECT_MEMORY_TREE);

	return nodeNum;
}

/*
==============
MT_FreeIndex
==============
*/
void MT_FreeIndex(unsigned int nodeNum, int numBytes)
{
	int size;
	int lowBit;

	size = MT_GetSize(numBytes);
	assert(size >= 0 && size <= MEMORY_NODE_BITS);
	assert(nodeNum > 0 && nodeNum < MEMORY_NODE_COUNT);

	Sys_EnterCriticalSection(CRITSECT_MEMORY_TREE);
	--gScrMemTreeGlob.totalAlloc;
	gScrMemTreeGlob.totalAllocBuckets -= 1 << size;

	assert(gScrMemTreeDebugGlob.mt_usage[nodeNum]);
	assertMsg((gScrMemTreeDebugGlob.mt_usage_size[nodeNum] == size), "(MT_NodeInfoString( inst, nodeNum )) = %s",
		MT_NodeInfoString(inst, nodeNum));

	gScrMemTreeDebugGlob.mt_usage[nodeNum] = 0;
	gScrMemTreeDebugGlob.mt_usage_size[nodeNum] = 0;
	while (1)
	{
		assert(size <= MEMORY_NODE_BITS);
		lowBit = 1 << size;
		assert(nodeNum == (nodeNum & ~(lowBit - 1)));
		if (size == MEMORY_NODE_BITS || !MT_RemoveMemoryNode(lowBit ^ nodeNum, size))
		{
			break;
		}
		nodeNum &= ~lowBit;
		++size;
	}

	MT_AddMemoryNode(nodeNum, size);
	Sys_LeaveCriticalSection(CRITSECT_MEMORY_TREE);
}

/*
==============
MT_Alloc
==============
*/
void* MT_Alloc(int numBytes, int type)
{
	return gScrMemTreeGlob.nodes + MT_AllocIndex(numBytes, type);
}

/*
==============
MT_Free
==============
*/
void MT_Free(void* p, int numBytes)
{
	assertMsg(((MemoryNode*)p - gScrMemTreeGlob.nodes >= 0
		&& (MemoryNode*)p - gScrMemTreeGlob.nodes < MEMORY_NODE_COUNT),
		"((MemoryNode *) p - gScrMemTreeGlob.nodes) = %i", (MemoryNode*)p - gScrMemTreeGlob.nodes);

	MT_FreeIndex((MemoryNode*)p - gScrMemTreeGlob.nodes, numBytes);
}

/*
==============
MT_Realloc
==============
*/
qboolean MT_Realloc(int oldNumBytes, int newNumbytes)
{
	return MT_GetSize(oldNumBytes) >= MT_GetSize(newNumbytes);
}

