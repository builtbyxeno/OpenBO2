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

#ifndef THREADS_INTERLOCK_H
#define THREADS_INTERLOCK_H

#include <Windows.h>
#include <qcommon/threads.h>

typedef struct FastCriticalSection
{
    volatile long readCount;
    volatile long writeCount;
} FastCriticalSection;

static void Sys_LockWrite(FastCriticalSection* critSect)
{
    while (1)
    {
        if (!critSect->readCount)
        {
            if (_InterlockedIncrement(&critSect->writeCount) == 1 && !critSect->readCount)
                //if ( Sys_InterlockedIncrement(&critSect->writeCount) == 1 && !critSect->readCount )
            {
                break;
            }
            _InterlockedDecrement(&critSect->writeCount);
        }
        NET_Sleep(0);
    }
}

static void Sys_UnlockWrite(FastCriticalSection* critSect)
{
    _InterlockedDecrement(&critSect->writeCount);
}

static void Sys_UnlockRead(FastCriticalSection* critSect)
{
    _InterlockedDecrement(&critSect->readCount);
}

static void Sys_WaitInterlockedCompareExchange(volatile int* destination, int value, int comperand)
{
    do
    {
        while (*destination != comperand)
        {
        }
    }     while (_InterlockedCompareExchange((volatile LONG*)destination, value, comperand) != comperand);
}

#endif