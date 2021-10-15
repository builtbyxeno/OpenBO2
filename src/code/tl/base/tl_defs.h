#include "tl_system.h"

char _tlAssert(const char* file, int line, const char* expr, const char* desc);

inline int tlEndianSwap64(unsigned __int64 x)
{
    x = ((x & 0x00000000FFFFFFFFull) << 32) | ((x & 0xFFFFFFFF00000000ull) >> 32);
    x = ((x & 0x0000FFFF0000FFFFull) << 16) | ((x & 0xFFFF0000FFFF0000ull) >> 16);
    x = ((x & 0x00FF00FF00FF00FFull) << 8) | ((x & 0xFF00FF00FF00FF00ull) >> 8);

    return x;
}

inline void tlEndianSwapMemory32(void* Data, unsigned int Bytes)
{
    unsigned int i;

    for (i = Bytes >> 2; i; --i)
    {
        *(DWORD*)Data = (((*(DWORD*)Data << 16) | *(DWORD*)Data & 0xFF00) << 8) | ((*(DWORD*)Data | 0xFF00FF & *(DWORD*)Data) >> 8);
        Data = (char*)Data + 4;
    }
}
