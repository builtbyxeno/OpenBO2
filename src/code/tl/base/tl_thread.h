#include "tl_system.h"

inline void SetThreadName(unsigned int dwThreadID, const char* szThreadName)
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

    ~tlAtomicReadWriteMutex()
    {
        this->ThisPtr = NULL;
    }
};

class tlAtomicMutex {

private:
    tlAtomicMutex* ThisPtr;
public:
    unsigned __int64 ThreadId;
    int LockCount;

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

    ~tlAtomicMutex()
    {
        this->ThreadId = 0i64;
        this->ThisPtr = NULL;
    }
};

inline unsigned __int64 tlAtomicAnd(volatile unsigned __int64* var, unsigned __int64 value)
{
    signed __int64 v;

    for (v = *var; _InterlockedCompareExchange64((volatile signed __int64*)var, value & v, v) != v; v = *var)
        Sleep(0);
    return value & v;
}

inline unsigned __int64 tlAtomicOr(volatile unsigned __int64* var, unsigned __int64 value)
{
    signed __int64 v;

    for (v = *var; _InterlockedCompareExchange64((volatile signed __int64*)var, value | v, v) != v; v = *var)
        Sleep(0);
    return value | v;
}

inline unsigned int tlAtomicAdd(volatile unsigned int* var, unsigned int value)
{
    volatile unsigned int v;

    for (v = *var; _InterlockedCompareExchange(var, *var + value, *var) != v; v = *var)
        Sleep(0);
    return v + value;
}