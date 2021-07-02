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

#ifndef BLACKBOX_DATA_H
#define BLACKBOX_DATA_H

typedef struct bb_msg
{
	unsigned __int8* data;
	int maxsize;
	int cursize;
	bool overflow;
	unsigned __int8* pppHashTable;
	unsigned __int8 pppBits;
	unsigned int pppHash;
	int pppBitOffset;
	int pppBitCount;
} bb_msg_t;

struct DefinitionMap
{
	unsigned int nameHash;
	unsigned int formatHash;
	int parameterCount;
	int definitionId;
	unsigned __int8 parameters[64];
};

void BB_Copy(bb_msg_t*, void const*, int);
void BB_WriteInt8(bb_msg_t*, int);
void BB_WriteVarUInt32(bb_msg_t*, unsigned int);
void BB_WriteVarUInt64(bb_msg_t*, unsigned __int64);
void BB_InitStringCache(void);
void BB_ClearStringCache(void);
unsigned int BB_HashString(char const*, int);
unsigned int BB_CacheString(char const*, int);
void BB_WriteString(bb_msg_t*, char const*, int);
void BB_MsgInit(bb_msg_t*, void*, int);
void BB_MsgInitPPP(bb_msg_t*, void*, int);
void BB_InitDefinitions(void);
void BB_RewriteDefinitions(bb_msg_t*);
int BB_BeginDefinition(char const*);
unsigned char BB_ParseParameter(char const*, int);
DefinitionMap* BB_GetDefinitionMap(unsigned int, unsigned int);
int BB_ParseAndCacheFormatString(bb_msg_t*, char const*, char const*, int*, unsigned char const**);
void BB_WriteFormatParameters(bb_msg_t*, int, unsigned char const*, char*);

#endif