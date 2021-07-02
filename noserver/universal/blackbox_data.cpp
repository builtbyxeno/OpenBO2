/*
 * Copyright (c) 2020-2021 OpenIW
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "blackbox_data.h"

#include <universal/q_shared.h>

void BB_Copy(bb_msg_t* msg, void const* _data, int len)
{
	unsigned char currBit;

	if (!msg->pppHashTable)
	{
		if (!msg->overflow)
		{
			if (msg->cursize + len > msg->maxsize)
			{
				msg->overflow = 1;
				return;
			}
			if (len > 0)
				memcpy(&msg->data[msg->cursize], _data, len);
			msg->cursize = msg->cursize + len;
		}
	}
	if (msg->overflow || len + (len >> 3) + msg->cursize + 1 > msg->maxsize) 
	{
		msg->overflow = 1;
		return;
	}
	if (len > 0)
	{
		for (int i = 0; i < len; ++i)
		{
			currBit = *((unsigned char*)_data + i);
			if (msg->pppHashTable[msg->pppHash] == currBit)
				msg->pppBits = (2 * msg->pppBits) | 1;
			else
			{
				msg->pppBits *= 2;
				msg->data[msg->cursize] = currBit;
				msg->pppHashTable[msg->pppHash] = currBit;
				msg->cursize = msg->cursize + 1;
			}
			++msg->pppBitCount;
			msg->pppHash = (currBit + 32 * msg->pppHash) & 0xFFF;
			if (msg->pppBitCount == 8)
			{
				msg->data[msg->pppBitOffset] = msg->pppBits;
				msg->pppBitOffset = msg->cursize;
				msg->pppBits = 0;
				msg->cursize = msg->cursize + 1;
			}
		}
	}
}

void BB_WriteInt8(bb_msg_t*, int)
{
}

void BB_WriteVarUInt32(bb_msg_t*, unsigned int)
{
}

void BB_WriteVarUInt64(bb_msg_t*, unsigned __int64)
{
}

void BB_InitStringCache(void)
{
}

void BB_ClearStringCache(void)
{
}

unsigned int BB_HashString(char const*, int)
{
	return 0;
}

unsigned int BB_CacheString(char const*, int)
{
	return 0;
}

void BB_WriteString(bb_msg_t*, char const*, int)
{
}

void BB_MsgInit(bb_msg_t*, void*, int)
{
}

void BB_MsgInitPPP(bb_msg_t*, void*, int)
{
}

void BB_InitDefinitions(void)
{
}

void BB_RewriteDefinitions(bb_msg_t*)
{
}

int BB_BeginDefinition(char const*)
{
	return 0;
}

unsigned char BB_ParseParameter(char const*, int)
{
	return 0;
}

DefinitionMap* BB_GetDefinitionMap(unsigned int, unsigned int)
{
	return nullptr;
}

int BB_ParseAndCacheFormatString(bb_msg_t*, char const*, char const*, int*, unsigned char const**)
{
	return 0;
}

void BB_WriteFormatParameters(bb_msg_t*, int, unsigned char const*, char*)
{
}
