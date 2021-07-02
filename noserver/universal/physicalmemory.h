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

#ifndef PHYSICALMEMORY_H
#define PHYSICALMEMORY_H

void PMem_InitPhysicalMemory(struct PhysicalMemory*, unsigned int, char const*, void*);
void PMem_Init(void);
void PMem_BeginAllocInPrim(struct PhysicalMemoryPrim*, char const*, enum EMemTrack);
void PMem_BeginAlloc(char const*, unsigned int, enum EMemTrack);
void PMem_EndAlloc(char const*, unsigned int);
void PMem_FreeIndex(struct PhysicalMemory*, unsigned int, int, int);
void PMem_Free(char const*);
int PMem_GetOverAllocatedSize(void);
void* PMem_AllocNamed(unsigned int, unsigned int, unsigned int, unsigned int, char const*, enum EMemTrack, char const*, int);
void* PMem_Alloc(unsigned int, unsigned int, unsigned int, unsigned int, enum EMemTrack, char const*, int);

#endif