#include <base\tl_system.h>

class jqAtomicHeap {
private:

    enum {
        CellWidth = 0x40
    };
    struct LevelInfo {
        unsigned int BlockSize;
        int NBlocks;
        int NCells;
        unsigned __int64* CellAvailable;
        unsigned __int64* CellAllocated;
    };

    jqAtomicHeap* ThisPtr;
    tlAtomicMutex Mutex;
    unsigned __int8* HeapBase;
    unsigned int HeapSize;
    unsigned int BlockSize;
    volatile unsigned int TotalUsed;
    volatile unsigned int TotalBlocks;
    int NLevels;
    LevelInfo Levels[11];
    unsigned __int8* LevelData;

public:

    /*
    ==============
    jqAtomicHeap::AllocBlock
    ==============
    */
    char AllocBlock(LevelInfo** FitLevel, int* FitSlot) {
        jqAtomicHeap::LevelInfo** v3; // edi
        int v4; // ebx
        unsigned __int64* v5; // edx
        int v6; // eax
        signed __int64 v7; // rdi
        unsigned int v8; // ebx
        unsigned int v9; // edx
        jqAtomicHeap::LevelInfo* v11; // [esp+14h] [ebp-10h]
        jqAtomicHeap* i; // [esp+18h] [ebp-Ch]
        int v13; // [esp+20h] [ebp-4h]

        v3 = FitLevel;
        for (i = this; *v3 < &this->Levels[this->NLevels]; ++ * v3)
        {
            v4 = (*v3)->NCells;
            v5 = (*v3)->CellAvailable;
            v6 = 0;
            v11 = *v3;
            if (v4 > 0)
            {
                while (1)
                {
                    v7 = v5[v6];
                    if (v7)
                        break;
                    if (++v6 >= v4)
                        v3 = FitLevel;
                        this = i;
                }
                v8 = 0x80000000;
                v9 = 0;
                v13 = 0;
                if (v7 >= 0)
                {
                    do
                    {
                        ++v13;
                        v9 = v8 >> 1;
                        v8 >>= 1;
                    }         while (!(v7 & v8 | v7 & v9));
                }
                *FitSlot = 63 - v13 + (v6 << 6);
                if (_InterlockedCompareExchange64(&v11->CellAvailable[v6], v7 & ~(1i64 << ((63 - v13) & 0x3F)), v7) == v7)
                    return 1;
                v3 = FitLevel;
                this = i;
            }
        }
        return 0;
    }

    /*
    ==============
    jqAtomicHeap::SplitBlock
    ==============
    */
    int SplitBlock(LevelInfo* Level, int Slot, LevelInfo* LevelTo) {
        return 1;
    }

    /*
    ==============
    jqAtomicHeap::AllocLevel
    ==============
    */
    int AllocLevel(int LevelIdx) {
        return 1;
    }

    /*
    ==============
    jqAtomicHeap::FindLevelForSize
    ==============
    */
    int FindLevelForSize(unsigned int Size) {
        unsigned int blocksize = this->BlockSize;

        return (blocksize < Size)
            + (2 * blocksize < Size)
            + (4 * blocksize < Size)
            + (8 * blocksize < Size)
            + (16 * blocksize < Size)
            + (32 * blocksize < Size)
            + (blocksize << 6 < Size)
            + (blocksize << 7 < Size)
            + (blocksize << 8 < Size)
            + (blocksize << 9 < Size)
            + (blocksize << 10 < Size);
    }

    /*
    ==============
    jqAtomicHeap::Alloc
    ==============
    */
    void* Alloc(unsigned int Size, unsigned int Align) {
        return nullptr;
    }

    /*
    ==============
    jqAtomicHeap::FindAllocatedBlock
    ==============
    */
    void FindAllocatedBlock(unsigned int Offset, LevelInfo** FitLevel, int* FitSlot) {

    }

    /*
    ==============
    jqAtomicHeap::MergeBlocks
    ==============
    */
    void MergeBlocks(LevelInfo** FitLevel, int* FitSlot) {

    }

    /*
    ==============
    jqAtomicHeap::Free
    ==============
    */
    void Free(void* Ptr) {

    }

    /*
    ==============
    jqAtomicHeap::Init
    ==============
    */
    void Init(void* _HeapBase, unsigned int _HeapSize, unsigned int _BlockSize) {

    }
};

