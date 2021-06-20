#ifndef JOBQUEUE_ATOMIC_QUEUE_LF_H
#define JOBQUEUE_ATOMIC_QUEUE_LF_H
#include <base\tl_system.h>

template<typename T, int I>
class jqAtomicQueue {
private:
    template<typename T>
    class jqAtomicQueuePtr {
    public:
        struct {
            T* Ptr;
            unsigned int Count;
        };
        unsigned __int64 Val64;
    };

    struct NodeType {
        jqAtomicQueuePtr<NodeType> Next;
        jqConditionalQueue* Data;
    };

    jqAtomicQueuePtr<NodeType>* FreeListPtr;
    jqAtomicQueuePtr<NodeType> _FreeList;
    jqAtomicQueuePtr<NodeType> Head;
    jqAtomicQueuePtr<NodeType> Tail;
    jqAtomicQueue<T, I>* ThisPtr;
public:
    /*
    ==============
    jqAtomicQueue<T*,I>::AllocateNodeBlock
    ==============
    */
    void AllocateNodeBlock(int Count) {
        int v2; // esi
        jqAtomicQueue<T, I>* v3; // edi
        int v6; // edx
        signed __int64 v7; // rdi
        NodeType* NodeBlock; // [esp+14h] [ebp-8h] MAPDST

        v2 = Count;
        v3 = this;
        NodeBlock = tlMemAlloc(264 * Count, 8u, 0);
        if (Count - 1 > 0)
        {
            v6 = Count - 1;
            do
            {
                --v6;
                NodeBlock->Next.Ptr = NodeBlock + 1;
                ++NodeBlock;
            }     while (v6);
        }
        NodeBlock[v2 - 1].Next.Ptr = 0;
        v7 = v3->FreeListPtr->Val64;
        Count = 0;
        InterlockedExchange(&Count, 0);
        Count = this->FreeListPtr;
        if (_InterlockedCompareExchange64(Count, v7, v7) != v7)
            tlMemFree(NodeBlock);
    }

    /*
    ==============
    jqAtomicQueue<T,I>::AllocateNode
    ==============
    */
    NodeType* AllocateNode() {
        jqAtomicQueue<T,I>* i; // ebx
        NodeType* v2; // esi
        unsigned int v3; // ebp

        for (i = this; ; i = this)
        {
            while (1)
            {
                v2 = i->FreeListPtr->Ptr;
                if (v2)
                    break;
                i->AllocateNodeBlock(32);
            }
            v3 = i->FreeListPtr->Count;
            if (_InterlockedCompareExchange64(
                (volatile signed __int64*)i->FreeListPtr,
                v3 + 1,
                v3) == v3)
                break;
        }
        return v2;
    }

    /*
    ==============
    jqAtomicQueue<T *,I>::FreeNode
    ==============
    */
    void FreeNode(NodeType* Node) {
        NodeType* v2;
        unsigned int v3;
        jqAtomicQueue* i;

        for (i = this; ; this = i)
        {
            v2 = this->FreeListPtr->Ptr;
            v3 = this->FreeListPtr->Count;
            Node->Next.Ptr = v2;
            if (_InterlockedCompareExchange64(
                (volatile signed __int64*)this->FreeListPtr,
                v3 + 1,
                v3) == v3)
                break;
        }
    }

    /*
    ==============
    jqAtomicQueue<T *,I>::AllocateNode
    ==============
    */
    NodeType* AllocateNode() {
        jqAtomicQueue<T, I>* i;

        while (1)
        {
            if (this->FreeListPtr->Ptr)
                break;
            this->AllocateNodeBlock(32);
        }
        if (InterlockedCompareExchange64(
            (volatile LONGLONG)this->FreeListPtr,
            this->FreeListPtr->Ptr->Next,
            this->FreeListPtr->Val64
        ) == this->FreeListPtr)
            break;
    }

    /*
    ==============
    jqAtomicQueue<jqBatch,32>::Push
    ==============
    */
    void Push(T* Data) {
        NodeType* Node;
        unsigned int v2;
        unsigned int v3; // esi
        signed __int64 v4; // rax
        NodeType* v5; // edi
        unsigned int v6; // ebx
        jqAtomicQueue* v7; // ecx
        unsigned int CurTail_4;
        jqAtomicQueuePtr<NodeType> Next;
        LONG Target;
        __int32 v11;

        Node = AllocateNode();
        memcpy(&Node->Data, Data, sizeof(Node->Data));
        Node->Next.Ptr = 0;
        Data = 0;
        InterlockedExchange(&Data, 0);
        do
        {
            while (1)
            {
                do
                {
                    v2 = this->ThisPtr;
                    v4 = *(v2 + 28);
                    v3 = *(v2 + 24);
                    CurTail_4 = v4;
                    v4 = _InterlockedExchange(&Data, v2);
                    v5 = *v3;
                    v6 = *(v3 + 4);
                    Next.Ptr = *v3;
                    Next.Count = v6;
                    _InterlockedExchange(&v11, v4);
                    v7 = this->ThisPtr;
                }
                while (v4 != v7->Tail.Val64);
                if (!v5)
                    break;
                v4 = v3;
                _InterlockedCompareExchange64(&v7->Tail, v4 + 1, v4);
            }
            Target = 0;
            InterlockedExchange(&Target, 0);
        }
        while (_InterlockedCompareExchange64(v3, v6 + 1, v6) != Next);
        _InterlockedCompareExchange64(&this->ThisPtr->Tail, CurTail_4 + 1, CurTail_4);
    }

    /*
    ==============
    jqAtomicQueue<jqBatch,32>::Pop
    ==============
    */
    char Pop(T* p) {
        jqAtomicQueue<T,I>* v2; // edi
        __int32 v3; // eax
        NodeType* v4; // esi
        unsigned int v5; // ebp
        jqAtomicQueue<T,I>* v6; // eax
        NodeType* v7; // ecx
        NodeType* v8; // ebx
        signed __int64 v9; // rax
        volatile signed __int64* v10; // ebp
        __int32 v13; // [esp+14h] [ebp-10h] BYREF
        __int32 v14; // [esp+18h] [ebp-Ch] BYREF
        LONG Target; // [esp+1Ch] [ebp-8h] BYREF
        __int32 v16; // [esp+20h] [ebp-4h]

        v2 = this;
        while (1)
        {
            while (1)
            {
                do
                {
                    do
                    {
                        v3 = (__int32)v2->ThisPtr;
                        v4 = *(v3 + 16);
                        v5 = *(__int32*)(v3 + 20);
                        _InterlockedExchange(&v13, v3);
                        v6 = v2->ThisPtr;
                        v7 = v6->Tail.Ptr;
                        v9 = v6->Tail.Count;
                        v8 = v4->Next.Ptr;
                        v16 = v4->Next.Count;
                        _InterlockedExchange(&v14, v16);
                        v9 = v2->ThisPtr;
                    }   
                    while (v4 != *(v9 + 16));
                }       
                while (v5 != *(v9 + 20));
                if (v4 == v7)
                    break;
                if (v8)
                {
                    memcpy((unsigned __int8*)p, (unsigned __int8*)&v8->Data, sizeof(jqBatch));
                    Target = 0;
                    InterlockedExchange(&Target, 0);
                    if (_InterlockedCompareExchange64(
                        (volatile signed __int64*)&v2->ThisPtr->Head,
                        v5 + 1,
                        v5) == v5)
                    {
                        this->FreeNode(v4);
                        return 1;
                    }
                    v2 = this;
                }
            }
            if (!v8)
                break;
            v10 = (volatile signed __int64*)(v9 + 24);
            v9 = v7;
            _InterlockedCompareExchange64(v10, v9 + 1, v9);
        }
        return 0;
    }
};

#endif // !JOBQUEUE_ATOMIC_QUEUE_LF_H