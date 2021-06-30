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

#include "mem_track.h"

#include <universal/q_shared.h>
#include <universal/win_common.h>

int g_userhunk_track_count;
const char* g_mem_track_filename;
mem_track_t g_staticsMemTrack[2048];
int g_hunk_track_count;
int g_staticsMemTrackCount;
int g_hunklow_track_count;
int g_mallocMemInfoCount;
int g_tempMemInfoCount;
int g_tempHighMemInfoCount;
int g_physicalMemInfoCount;
int g_malloc_mem_size;
int g_malloc_mem_high;

meminfo_t g_info;
TempMemInfo g_mallocMemInfoArray[1500];
mem_track_node_s* g_ZMallocMemTrackList;
meminfo_t g_virtualMemInfo;
TempMemInfo g_physicalMemInfoArray[1500];
TempMemInfo g_tempMemInfoArray[1500];
mem_track_t g_userhunk_track[256];
mem_track_t g_hunklow_track[65536];
TempMemInfo g_combinedMemInfoArray[1500];
mem_track_t g_hunk_track[524288];
TempMemInfo g_tempHighMemInfoArray[1500];

#define MAX_MEM_TRACK 2048
#define TEMP_MEM_INFO_COUNT 1500
#define MAX_USERHUNK_TRACK 256

TempMemInfo* GetTempMemInfo(int permanent, const char* name, int type, int usageType, TempMemInfo* tempMemInfoArray, int* tempMemInfoCount, bool add_if_missing)
{
    TempMemInfo foundTempMemInfo;
    int i;
    TempMemInfo* tempMemInfo;
    int count;

    count = *tempMemInfoCount;
    tempMemInfo = tempMemInfoArray;
    for (i = 0; i < count; ++i, ++tempMemInfo)
    {
        tempMemInfo = &tempMemInfoArray[i];
        if ((!name || !_stricmp(tempMemInfo->data.name, name))
            && tempMemInfo->permanent == permanent
            && (unsigned char)tempMemInfo->data.usageType == usageType)
        {
            if (!i)
            {
                return tempMemInfo;
            }

            memcpy(&foundTempMemInfo, tempMemInfo, sizeof(foundTempMemInfo));
            while (i > 0)
            {
                memcpy(&tempMemInfoArray[i], &tempMemInfoArray[i - 1], sizeof(TempMemInfo));
                --i;
            }

            memcpy(tempMemInfoArray, &foundTempMemInfo, sizeof(TempMemInfo));
            return tempMemInfoArray;
        }
    }
    if (!add_if_missing)
    {
        return 0;
    }

    ++* tempMemInfoCount;
    tempMemInfo->permanent = permanent;
    strcpy(tempMemInfo->data.name, name);
    tempMemInfo->data.type = type;
    tempMemInfo->data.usageType = usageType;
    tempMemInfo->data.size[0] = 0;
    tempMemInfo->data.size[1] = 0;
    tempMemInfo->data.filename = "";
    tempMemInfo->data.count = 0;
    tempMemInfo->high = 0;
    tempMemInfo->low = 0;
    tempMemInfo->hunkSize = 0;
    tempMemInfo->highExtra = 0;

    memcpy(&foundTempMemInfo, tempMemInfo, sizeof(foundTempMemInfo));
    for (; i > 0; --i)
    {
        memcpy(&tempMemInfoArray[i], &tempMemInfoArray[i - 1], sizeof(TempMemInfo));
    }

    memcpy(tempMemInfoArray, &foundTempMemInfo, sizeof(TempMemInfo));
    return tempMemInfoArray;
}

void track_init()
{

}

void track_physical_alloc(int size, const char* name, int type, int location)
{
    TempMemInfo* memInfo;
    int dataSize;

    track_init();
    if (size)
    {
        Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
        if (size <= 0)
        {
            memInfo = GetTempMemInfo(0, name, type, 7, g_physicalMemInfoArray, &g_physicalMemInfoCount, 0);
            if (memInfo)
            {
                memInfo->data.size[location] += size;
                --memInfo->data.count;
                dataSize = memInfo->data.size[location];
                if (memInfo->low > dataSize)
                    memInfo->low = dataSize;
            }
        }
        else
        {
            memInfo = GetTempMemInfo(0, name, type, 7, g_physicalMemInfoArray, &g_physicalMemInfoCount, 1);
            memInfo->data.size[location] += size;
            ++memInfo->data.count;
            dataSize = memInfo->data.size[location];
            if (memInfo->high < dataSize)
                memInfo->high = dataSize;
            if (memInfo->hunkSize < 0)
            {
                memInfo->hunkSize = 0;
                memInfo->highExtra = dataSize;
            }
        }
        g_info.typeTotal[type][location] += size;
        g_info.total[location] += size;
        switch (type)
        {
            case 0:
            case 1:
            case 3:
            case 39:
            case 55:
                break;
            default:
                g_info.nonSwapTotal += size;
                break;
        }
        switch (type)
        {
            case 0:
            case 1:
            case 3:
            case 17:
            case 19:
            case 39:
            case 55:
                break;
            default:
                g_info.nonSwapMinSpecTotal += size;
                break;
        }
        Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
    }
}

void track_z_alloc(int size, const char* name, int type, void* pos, int project, int overhead)
{
    TempMemInfo* memInfo; // eax
    int memSize;
    int extendedSize;
    mem_track_node_s* memTrack;

    Sys_EnterCriticalSection(CRITSECT_MEMTRACK);
    g_staticsMemTrack[0].size[0] += overhead;
    g_info.typeTotal[0][0] += overhead;
    g_info.total[0] += overhead;
    if (type != 55)
    {
        memInfo = GetTempMemInfo(0, name, type, 2, g_mallocMemInfoArray, &g_mallocMemInfoCount, 1);
        memInfo->data.size[0] += size;
        memSize = memInfo->data.size[0];
        ++memInfo->data.count;
        if (memInfo->high < memSize)
            memInfo->high = memSize;
        if (memInfo->hunkSize < 0)
        {
            memInfo->hunkSize = 0;
            memInfo->highExtra = memSize;
        }
        extendedSize = size + g_malloc_mem_size;
        g_malloc_mem_size = extendedSize;
        if (g_malloc_mem_high < extendedSize)
            g_malloc_mem_high = extendedSize;
    }
    memTrack = (mem_track_node_s*)((char*)pos - 164);
    strcpy(memTrack->data.name, name);
    memTrack->data.filename = "";
    memTrack->data.size[0] = size;
    memTrack->data.size[1] = 0;
    memTrack->data.type = type;
    memTrack->data.usageType = 2;
    memTrack->next = g_ZMallocMemTrackList;
    memTrack->prev = 0;
    memTrack->project = project;
    if (g_ZMallocMemTrackList)
        g_ZMallocMemTrackList->prev = memTrack;
    g_info.typeTotal[type][0] += size;
    g_info.total[0] += size;
    g_ZMallocMemTrackList = (mem_track_node_s*)((char*)pos - 164);
    switch (type)
    {
        case 0:
        case 1:
        case 3:
        case 39:
        case 55:
            break;
        default:
            g_info.nonSwapTotal += size;
            break;
    }
    switch (type)
    {
        case 0:
        case 1:
        case 3:
        case 17:
        case 19:
        case 39:
        case 55:
            break;
        default:
            g_info.nonSwapMinSpecTotal += size;
            break;
    }
    Sys_LeaveCriticalSection(CRITSECT_MEMTRACK);
}

void track_z_free(int type, void* pos, int overhead)
{
}
