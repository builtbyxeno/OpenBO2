#include "types.h"
#include "vars.h"
#include "qcommon_public.h"

/*
==============
Sys_LockWrite
==============
*/
inline void Sys_LockWrite(FastCriticalSection *critSect)
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
        NET_Sleep(0);
    }
}

/*
==============
Sys_UnlockWrite
==============
*/
inline void Sys_UnlockWrite(FastCriticalSection *critSect)
{
    assert(critSect->writeCount > 0);
    InterlockedDecrement(&critSect->writeCount);
}

/*
==============
Sys_UnlockRead
==============
*/
inline void Sys_UnlockRead(FastCriticalSection* critSect)
{
    assert(critSect->readCount > 0);
    InterlockedDecrement(&critSect->readCount);
}

/*
==============
Sys_WaitInterlockedCompareExchange
==============
*/
inline void Sys_WaitInterlockedCompareExchange(volatile int* destination, int value, int comperand)
{
    do
    {
        while (*destination != comperand)
        {
        }
    } while (InterlockedCompareExchange((volatile LONG*)destination, value, comperand) != comperand);
}

