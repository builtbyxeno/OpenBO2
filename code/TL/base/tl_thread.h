#ifndef TL_THREAD_H
#define TL_THREAD_H

#include "tl_system.h"

/*
==============
SetThreadName
==============
*/
inline void SetThreadName(unsigned int dwThreadID, const char *szThreadName)
{
    ULONG_PTR info[4];

    info[0] = 4096;
    info[1] = (ULONG_PTR)szThreadName;
    info[2] = dwThreadID;
    info[3] = 0;
    RaiseException(0x406D1388u, 0, 4u, info);
}

class tlAtomicReadWriteMutex {

private:
    volatile unsigned __int64 WriteThreadId;
    volatile int ReadLockCount;
    volatile int WriteLockCount;
    tlAtomicReadWriteMutex* ThisPtr;

public:
    /*
    ==============
    tlAtomicReadWriteMutex::WriteLock
    ==============
    */
    inline void WriteLock()
    {
        DWORD curTID;

        curTID = GetCurrentThreadId();
        if (InterlockedCompareExchange64((volatile LONGLONG*)this->ThisPtr, curTID, curTID) == curTID)
        {
            InterlockedExchangeAdd((volatile LONG*)this->ThisPtr->WriteLockCount, 1u);
            return;
        }
        while (1)
        {
            if (InterlockedCompareExchange64((volatile LONGLONG*)this->ThisPtr, curTID, 0i64))
                Sleep(0);
            if (!InterlockedCompareExchange((volatile LONG*)this->ThisPtr->ReadLockCount, 0, 0))
                break;
            while (InterlockedCompareExchange64((volatile LONGLONG*)this->ThisPtr, 0i64, curTID) != curTID)
            Sleep(0);
        }
        InterlockedExchangeAdd((volatile LONG*)this->ThisPtr->WriteLockCount, 1);
        InterlockedExchange((volatile LONG*)this, 0);
    }

    /*
    ==============
    tlAtomicReadWriteMutex::ReadLock
    ==============
    */
    inline void ReadLock()
    {
        DWORD currTID;

        currTID = GetCurrentThreadId();
        if (InterlockedCompareExchange64((volatile LONGLONG*)this->ThisPtr, currTID, currTID) == currTID)
        {
            InterlockedExchangeAdd((volatile LONG*)this->ThisPtr->ReadLockCount, 1u);
        }
        else
        {
            while (InterlockedCompareExchange64((volatile LONGLONG*)this->ThisPtr, currTID, 0i64))
                Sleep(0);
            InterlockedExchangeAdd((volatile LONG*)this->ThisPtr->ReadLockCount, 1u);
            while (InterlockedCompareExchange64((volatile LONGLONG*)this->ThisPtr, 0i64, currTID) != currTID)
                ;
        }
        InterlockedExchange((volatile LONG*)this, 0);
    }

    /*
    ==============
    tlAtomicReadWriteMutex::WriteUnlock
    ==============
    */
    inline void WriteUnlock()
    {
        DWORD currTID;
        LONG Target;

        currTID = GetCurrentThreadId();
        if (!InterlockedExchangeAdd((volatile LONG*)this->ThisPtr->WriteLockCount, 0xFFFFFFFF))
        {
            Target = 0;
            InterlockedExchange(&Target, 0);
            while (InterlockedCompareExchange64((volatile LONGLONG*)this->ThisPtr, 0i64, currTID) != currTID)
                ;
        }
    }

    /*
    ==============
    tlAtomicReadWriteMutex::~tlAtomicReadWriteMutex
    ==============
    */
    ~tlAtomicReadWriteMutex()
    {
        this->ThisPtr = NULL;
    }
};

class tlAtomicMutex {

private:
    unsigned __int64 ThreadId;
    int LockCount;
    tlAtomicMutex* ThisPtr;
public:
    /*
    ==============
    tlAtomicMutex::Lock
    ==============
    */
    inline void Lock()
    {
        DWORD currTID;

        currTID = GetCurrentThreadId();
        if (this->ThreadId != currTID || this->ThreadId)
        {
            while (InterlockedCompareExchange64((volatile LONGLONG*)this->ThisPtr, currTID, 0i64))
            {
                Sleep(0);
                currTID = currTID;
            }
            InterlockedExchange((volatile LONG*)this, 0);
            this->LockCount = 1;
        }
        else
        {
            ++this->LockCount;
        }
    }

    /*
    ==============
    tlAtomicMutex::~tlAtomicMutex
    ==============
    */
    ~tlAtomicMutex()
    {
        this->ThreadId = 0i64;
        this->ThisPtr = NULL;
    }
};

/*
==============
tlAtomicAnd
==============
*/
inline unsigned __int64 tlAtomicAnd(volatile unsigned __int64 *var, unsigned __int64 value)
{
    volatile signed __int64* v2;
    signed __int64 v;

    v2 = (volatile signed __int64*)var;
    for (v = *var; _InterlockedCompareExchange64(v2, value & v, v) != v; v = *var)
    {
        Sleep(0);
        v2 = (volatile signed __int64*)var;
    }
    return value & v;
}

/*
==============
tlAtomicOr
==============
*/
inline unsigned __int64 tlAtomicOr(volatile unsigned __int64 *var, unsigned __int64 value)
{
    volatile signed __int64* v2;
    signed __int64 v;

    v2 = (volatile signed __int64*)var;
    for (v = *var; _InterlockedCompareExchange64(v2, value | v, v) != v; v = *var)
    {
        Sleep(0);
        v2 = (volatile signed __int64*)var;
    }
    return value | v;
}

#endif // !TL_THREAD_H