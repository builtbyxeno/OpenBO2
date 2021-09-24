#include "types.h"
#include "vars.h"
#include "universal_public.h"

/*
==============
Hunk_FirstFitInit
==============
*/
HunkUser *Hunk_FirstFitInit(void *buffer, int size, HU_ALLOCATION_SCHEME scheme, unsigned int flags, void *scheme_specific_data, const char *name, int type)
{
    FIRSTFIT_HUNKUSER* hunk = (FIRSTFIT_HUNKUSER*)buffer;

    assert((flags & HF_FROMBUFFER) != 0);
    assert(size > sizeof(FIRSTFIT_HUNKUSER) + sizeof(FIRSTFIT_HEAPNODE));
    hunk->hunkUser.name = name;
    hunk->hunkUser.scheme = scheme;
    hunk->hunkUser.flags = flags;
    hunk->hunkUser.type = type;
    hunk->watermarkId = -1;
    hunk->base_size = size;
    hunk->free_blocks = (_firstfit_heapnode*)(((char*)hunk) + sizeof(FIRSTFIT_HUNKUSER));
    hunk->free_blocks->next = NULL;
    hunk->free_blocks->size = hunk->base_size - sizeof(FIRSTFIT_HUNKUSER);
    hunk->hunkUser_memAllocated = sizeof(FIRSTFIT_HUNKUSER);

    return &hunk->hunkUser;
}

/*
==============
Hunk_FirstFitReset
==============
*/
void Hunk_FirstFitReset(HunkUser *_user)
{
    FIRSTFIT_HUNKUSER* hunk = (FIRSTFIT_HUNKUSER*)_user;

    hunk->free_blocks = (_firstfit_heapnode*)(((char*)hunk) + sizeof(FIRSTFIT_HUNKUSER));
    hunk->free_blocks->next = NULL;
    hunk->free_blocks->size = hunk->base_size - sizeof(FIRSTFIT_HUNKUSER);
    hunk->hunkUser_memAllocated = sizeof(FIRSTFIT_HUNKUSER);
}

/*
==============
Hunk_FirstFitDestroy
==============
*/
void Hunk_FirstFitDestroy(HunkUser *_user)
{
    FIRSTFIT_HUNKUSER* hunk = (FIRSTFIT_HUNKUSER*)_user;
    hunk->hunkUser.scheme = HU_SCHEME_DEFAULT;
    hunk->hunkUser.flags = 0;
    hunk->hunkUser.name = 0;
    hunk->hunkUser.type = 0;
    hunk->base_size = 0;
    hunk->free_blocks = 0;
    hunk->watermarkId = 0;
    hunk->hunkUser_memAllocated = 0;
}

/*
==============
Hunk_FirstFitAlloc
==============
*/
void *Hunk_FirstFitAlloc(HunkUser *_user, int size, int alignment, const char* name)
{
    FIRSTFIT_HUNKUSER* hunk = (FIRSTFIT_HUNKUSER*)_user;
    _firstfit_heapnode* free_link;
    int adj_size;
    _firstfit_heapnode* last;

    assert(alignment > 0);

    ScopedCriticalSection csc(CRITSECT_MEMFIRSTFIT);

    free_link = hunk->free_blocks;
    last = NULL;
    while (1)
    {
        if (!free_link)
        {
            return NULL;
        }

        adj_size = (~(alignment - 1) & ((unsigned int)&free_link[1].next + alignment + 11)) - (DWORD)free_link + size;
        if (free_link->size >= adj_size)
        {
            break;
        }
        last = (_firstfit_heapnode*)free_link;
        free_link = free_link->next;
    }
    if (free_link->next || (int)(free_link->size - adj_size) > 1024)
    {
        if ((int)(free_link->size - adj_size) > 1024)
        {
            *(DWORD*)((~(alignment - 1) & ((unsigned int)&free_link[1].next + 3)) + size) = (DWORD)free_link->next;
            *(DWORD*)((~(alignment - 1) & ((unsigned int)&free_link[1].next + 3)) + size + 4) = free_link->size
                - ((~(alignment - 1) & ((unsigned int)free_link + alignment + 11))
                    - (DWORD)free_link
                    + size);
            free_link->next = (_firstfit_heapnode*)((~(alignment - 1) & ((unsigned int)&free_link[1].next + 3)) + size);
            free_link->size = adj_size;
        }
        if (last)
        {
            last->next = (_firstfit_heapnode*)free_link->next;
        }
        else
        {
            hunk->free_blocks = free_link->next;
        }
        free_link->next = (_firstfit_heapnode*)-559038737;
        *(DWORD*)((~(alignment - 1) & ((unsigned int)&free_link[1].next + alignment + 3)) - 12 + 8) = (DWORD)free_link;
        hunk->hunkUser_memAllocated += free_link->size;

        return (void*)(~(alignment - 1) & ((unsigned int)&free_link[1].next + alignment + 3));
    }

    return NULL;
}

/*
==============
Hunk_FirstFitFree
==============
*/
void Hunk_FirstFitFree(HunkUser *_user, void *ptr)
{
    FIRSTFIT_HUNKUSER* hunk = (FIRSTFIT_HUNKUSER*)_user;
    _firstfit_heapnode* free_link;
    _firstfit_heapnode* scan;
    _firstfit_heapnode* last;

    if (ptr)
    {
        ScopedCriticalSection csc(CRITSECT_MEMFIRSTFIT);
        last = NULL;
        scan = hunk->free_blocks;
        free_link = (_firstfit_heapnode*)*((DWORD*)ptr - 1);
        if (free_link->next == (_firstfit_heapnode*)-559038737)
        {
            hunk->hunkUser_memAllocated -= free_link->size;
            assert(hunk->free_blocks != NULL);
            while (scan)
            {
                if (scan > free_link)
                {
                    if (last)
                    {
                        free_link->next = scan;
                        last->next = free_link;
                    }
                    else
                    {
                        free_link->next = (_firstfit_heapnode*)hunk->free_blocks;
                        hunk->free_blocks = free_link;
                    }
                    if (last && (_firstfit_heapnode*)((char*)last + last->size) == free_link)
                    {
                        last->size += free_link->size;
                        last->next = free_link->next;
                        free_link = last;
                    }
                    if (free_link->next && (_firstfit_heapnode*)((char*)free_link + free_link->size) == free_link->next)
                    {
                        free_link->size += free_link->next->size;
                        free_link->next = free_link->next->next;
                    }

                    return;
                }
                last = scan;
                scan = scan->next;
            }
        }
        else
        {
        }
    }
}

