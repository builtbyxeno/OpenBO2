#ifndef THREADS_INTERLOCK_H
#define THREADS_INTERLOCK_H

#include <Windows.h>

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
            if (InterlockedIncrement(&critSect->writeCount) == 1 && !critSect->readCount)
                //if ( Sys_InterlockedIncrement(&critSect->writeCount) == 1 && !critSect->readCount )
            {
                break;
            }
            InterlockedDecrement(&critSect->writeCount);
        }
        //NET_Sleep(0);
    }
}

static void Sys_UnlockWrite(FastCriticalSection* critSect)
{
    InterlockedDecrement(&critSect->writeCount);
}

static void Sys_UnlockRead(FastCriticalSection* critSect)
{
    InterlockedDecrement(&critSect->readCount);
}

static void Sys_WaitInterlockedCompareExchange(volatile int* destination, int value, int comperand)
{
    do
    {
        while (*destination != comperand)
        {
        }
    }     while (InterlockedCompareExchange((volatile LONG*)destination, value, comperand) != comperand);
}

#endif