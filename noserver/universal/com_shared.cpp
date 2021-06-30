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

#include "com_shared.h"

#include <universal/q_shared.h>

typedef struct qtime_s
{
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
} qtime_s;

bool Com_Filter(char const* filter, char const* name, int casesensitive)
{
    char buf[1024];
    const char* ptr;
    int i;
    int found;

    while (*filter)
    {
        if (*filter == 42)
        {
            ++filter;
            i = 0;
            while (*filter && *filter != 42 && *filter != 63)
            {
                buf[i++] = *filter++;
            }
            buf[i] = 0;
            if (strlen(buf))
            {
                if (casesensitive)
                {
                    ptr = I_stristr(name, buf);
                }
                else
                {
                    ptr = strstr((char*)name, buf);
                }

                if (!ptr)
                {
                    return 0;
                }

                name = &ptr[strlen(buf)];
            }
        }
        else if (*filter == 63)
        {
            ++filter;
            ++name;
        }
        else if (*filter != 91 || filter[1] != 91)
        {
            if (*filter == 91)
            {
                filter++;
                found = 0;
                while (*filter && !found && (*filter != 93 || filter[1] == 93))
                {
                    if (filter[1] == 45 && filter[2] && (filter[2] != 93 || filter[3] == 93))
                    {
                        if (casesensitive)
                        {
                            if (*name >= *filter && *name <= filter[2])
                            {
                                found = 1;
                            }
                        }
                        else
                        {
                            if (toupper(*name) >= toupper(*filter))
                            {
                                if (toupper(*name) <= toupper(filter[2]))
                                {
                                    found = 1;
                                }
                            }
                        }
                        filter += 3;
                    }
                    else
                    {
                        if (casesensitive)
                        {
                            if (*filter == *name)
                            {
                                found = 1;
                            }
                        }
                        else
                        {
                            if (toupper(*filter) == toupper(*name))
                            {
                                found = 1;
                            }
                        }
                        ++filter;
                    }
                }

                if (!found)
                {
                    return 0;
                }

                while (*filter && (*filter != 93 || filter[1] == 93))
                {
                    ++filter;
                }

                filter++;
                ++name;
            }
            else
            {
                if (casesensitive)
                {
                    if (*filter != *name)
                    {
                        return 0;
                    }
                }
                else
                {
                    if (toupper(*filter) != toupper(*name))
                    {
                        return 0;
                    }
                }
                ++filter;
                ++name;
            }
        }
        else
        {
            ++filter;
        }
    }
    return 1;
}

bool Com_FilterPath(char const* filter, char const* name, int casesensitive)
{
    char new_filter[64];
    char new_name[64];
    int i;

    for (i = 0; i < 63 && filter[i]; ++i)
    {
        if (filter[i] != 92 && filter[i] != 58)
        {
            new_filter[i] = filter[i];
        }
        else
        {
            new_filter[i] = 47;
        }
    }
    new_filter[i] = 0;
    for (i = 0; i < 63 && name[i]; ++i)
    {
        if (name[i] != 92 && name[i] != 58)
        {
            new_name[i] = name[i];
        }
        else
        {
            new_name[i] = 47;
        }
    }

    new_name[i] = 0;
    return Com_Filter(new_filter, new_name, casesensitive);
}

int Com_HashKey(char const*, int)
{
	return 0;
}

void Com_GetQTime(int, qtime_s*, bool)
{
}

int Com_RealTime(qtime_s*, bool)
{
	return 0;
}

void Com_Memset(void*, int, int)
{
}
