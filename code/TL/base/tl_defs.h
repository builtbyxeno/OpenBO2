#ifndef TL_DEFS_H
#define TL_DEFS_H

#include "tl_system.h"

struct tlFileBuf {
	unsigned __int8* Buf;
	unsigned int Size;
	unsigned int UserData;
};

/*
==============
tlEndianSwap64
==============
*/
inline int tlEndianSwap64(unsigned __int64 x)
{
  x = ((x & 0x00000000FFFFFFFFull) << 32) | ((x & 0xFFFFFFFF00000000ull) >> 32);
  x = ((x & 0x0000FFFF0000FFFFull) << 16) | ((x & 0xFFFF0000FFFF0000ull) >> 16);
  x = ((x & 0x00FF00FF00FF00FFull) << 8) | ((x & 0xFF00FF00FF00FF00ull) >> 8);

  return x;
}

/*
==============
tlEndianSwapMemory32
==============
*/
inline void tlEndianSwapMemory32(void *Data, unsigned int Bytes)
{
    unsigned int i; // edx

    if ((Bytes & 3) != 0
        && _tlAssert(__FILE__, __LINE__, "(Bytes&3) == 0", "Size must be a multiple of 4."))
    {
        __debugbreak();
    }
    for (i = Bytes >> 2; i; --i)
    {
        *(DWORD*)Data = (((*(DWORD*)Data << 16) | *(DWORD*)Data & 0xFF00) << 8) | ((*(DWORD*)Data | 0xFF00FF & *(DWORD*)Data) >> 8);
        Data = (char*)Data + 4;
    }
}

#endif // !TL_DEFS_H