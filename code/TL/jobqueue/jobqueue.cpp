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

/*
==============
jqAttachQueueToWorkers
==============
*/
void jqAttachQueueToWorkers(jqQueue *Queue, unsigned int ProcessorMask)
{
  unsigned int v2; // eax
  signed int v3; // ecx
  signed int v4; // edi
  char *v5; // edi
  volatile signed __int32 *v6; // ebx
  volatile signed __int32 v7; // esi
  signed int v8; // [esp+0h] [ebp-Ch]
  unsigned int BaseProcessorsMask; // [esp+4h] [ebp-8h]
  unsigned int Processor; // [esp+8h] [ebp-4h]

  v2 = jqProcessorsMask;
  v3 = 1;
  Processor = 1;
  if ( jqProcessorsMask )
  {
    v4 = -128;
    do
    {
      if ( !(v3 & v2) )
      {
        do
          v3 *= 2;
        while ( !(v3 & v2) );
        Processor = v3;
      }
      v4 += 128;
      v2 ^= v3;
      v8 = v4;
      BaseProcessorsMask = v2;
      if ( v3 & ProcessorMask )
      {
        v5 = (char *)jqWorkers + v4;
        v6 = (volatile signed __int32 *)(v5 + 28);
        do
        {
          v7 = *v6;
          if ( *v6 >= 8 )
          {
            if ( _tlAssert(
                   "c:\\t6\\code\\tl\\jobqueue\\jobqueue.cpp",
                   111,
                   "numQueues < JQ_MAX_QUEUES",
                   "Ran out of queues for this worker!") )
            {
              __debugbreak();
            }
            v3 = Processor;
          }
        }
        while ( _InterlockedCompareExchange((volatile signed __int32 *)&v5[4 * v7 + 88], (signed __int32)Queue, 0) );
        _InterlockedExchangeAdd(v6, 1u);
        Queue->ProcessorsMask |= *((_DWORD *)v5 + 5);
        v2 = BaseProcessorsMask;
        v4 = v8;
      }
    }
    while ( v2 );
  }
}

/*
==============
jqEnableWorkers
==============
*/
void jqEnableWorkers(unsigned int ProcessorsMask)
{
  jqProcessorsMask = ProcessorsMask;
}

/*
==============
jqGetNumWorkers
==============
*/
int jqGetNumWorkers()
{
  return jqNWorkers;
}

/*
==============
jqGetCurrentThreadID
==============
*/
unsigned __int64 jqGetCurrentThreadID()
{
  return GetCurrentThreadId();
}

/*
==============
jqGetMainThreadID
==============
*/
unsigned __int64 jqGetMainThreadID()
{
  return jqMainThreadID;
}

/*
==============
jqGetCurrentBatch
==============
*/
jqBatch *jqGetCurrentBatch()
{
  return *(jqBatch **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + LODWORD(_tls_index)) + 14972);
}

/*
==============
jqGetCurrentWorker
==============
*/
jqWorker *jqGetCurrentWorker()
{
  return *(jqWorker **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + LODWORD(_tls_index)) + 14968);
}

/*
==============
jqGetWorkerQueue
==============
*/
jqQueue *jqGetWorkerQueue(int worker)
{
  int v1; // eax
  int *v2; // ecx

  v1 = 0;
  if ( jqNWorkers <= 0 )
    return 0;
  v2 = &jqWorkers->Processor;
  while ( *v2 != worker )
  {
    ++v1;
    v2 += 32;
    if ( v1 >= jqNWorkers )
      return 0;
  }
  return &jqWorkers[v1].WorkerSpecific;
}

/*
==============
jqShutdownWorker
==============
*/
void jqShutdownWorker(jqWorker *)
{
	//Failed decompiling
}

/*
==============
jqGetQueuedBatchCount
==============
*/
int jqGetQueuedBatchCount(jqBatchGroup *GroupID)
{
  int result; // eax

  if ( GroupID )
    result = GroupID->QueuedBatchCount;
  else
    result = dword_10E5578;
  return result;
}

/*
==============
jqGetExecutingBatchCount
==============
*/
int jqGetExecutingBatchCount(jqBatchGroup *GroupID)
{
  int result; // eax

  if ( GroupID )
    result = GroupID->ExecutingBatchCount;
  else
    result = dword_10E557C;
  return result;
}

/*
==============
jqFindWorkerForProcessor
==============
*/
jqWorker *jqFindWorkerForProcessor(jqProcessor Processor)
{
  int v1; // eax
  int *v2; // ecx

  v1 = 0;
  if ( jqNWorkers <= 0 )
    return 0;
  v2 = &jqWorkers->Processor;
  while ( *v2 != Processor )
  {
    ++v1;
    v2 += 32;
    if ( v1 >= jqNWorkers )
      return 0;
  }
  return &jqWorkers[v1];
}

/*
==============
jqPoll
==============
*/
BOOL jqPoll(jqBatchGroup *GroupID)
{
  jqBatchGroup *v1; // ebx

  v1 = GroupID;
  if ( !GroupID )
    v1 = (jqBatchGroup *)&dword_10E5578;
  if ( (unsigned __int8)v1 & 7
    && _tlAssert(
         "c:\\t6\\code\\tl\\jobqueue\\jobqueue.cpp",
         480,
         "((u32)BatchCount & 0x7)==0",
         "Data not aligned correctly, read won't be atomic!\n") )
  {
    __debugbreak();
  }
  return v1->BatchCount != 0;
}

/*
==============
jqAreJobsQueued
==============
*/
bool jqAreJobsQueued(jqBatchGroup *GroupID)
{
  jqBatchGroup *v1; // eax

  v1 = GroupID;
  if ( !GroupID )
    v1 = (jqBatchGroup *)&dword_10E5578;
  return v1->QueuedBatchCount != 0;
}

/*
==============
jqSetWorkerInitFunction
==============
*/
void jqSetWorkerInitFunction(void (*fn)(int))
{
  jqWorkerInitFn = fn;
}

/*
==============
jqLetWorkersSleep
==============
*/
void jqLetWorkersSleep()
{
  if ( jqKeepWorkersAwakeCount <= 0
    && _tlAssert(
         "c:\\t6\\code\\tl\\jobqueue\\jobqueue.cpp",
         536,
         "jqKeepWorkersAwakeCount > 0",
         "jqKeepWorkersAwakeCount underflow.") )
  {
    __debugbreak();
  }
  _InterlockedExchangeAdd(&jqKeepWorkersAwakeCount, 0xFFFFFFFF);
}

/*
==============
jqAllocBatchData
==============
*/
void *jqAllocBatchData(unsigned int Size)
{
  return jqAtomicHeap::Alloc(&stru_10E5580, Size, 0x10u);
}

/*
==============
jqFreeBatchData
==============
*/
void jqFreeBatchData(void *Ptr)
{
  jqAtomicHeap::Free(&stru_10E5580, Ptr);
}

/*
==============
jqGetBatchDataAvailable
==============
*/
unsigned int jqGetBatchDataAvailable()
{
  return stru_10E5580.HeapSize - stru_10E5580.TotalUsed;
}

/*
==============
jqIsTempWorker
==============
*/
bool jqIsTempWorker()
{
  int v0; // ecx
  bool result; // al

  v0 = *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + LODWORD(_tls_index)) + 14968);
  result = 0;
  if ( v0 )
    result = *(_DWORD *)(v0 + 24) == 0;
  return result;
}

/*
==============
jqKeepWorkersAwake
==============
*/
void jqKeepWorkersAwake()
{
  _InterlockedExchangeAdd(&jqKeepWorkersAwakeCount, 1u);
  if ( jqKeepWorkersAwakeCount > 0 )
    PulseEvent(jqNewJobAdded);
}

/*
==============
jqLockBatchPool
==============
*/
void __thiscall jqLockBatchPool(void *this)
{
  jqLockBatchPoolInternal(this);
  _InterlockedExchangeAdd(&jqBatchPoolExternallyLockedCount, 1u);
}

/*
==============
jqUnlockBatchPool
==============
*/
void __thiscall jqUnlockBatchPool(void *this)
{
  LONG Target; // [esp+0h] [ebp-4h]

  Target = (LONG)this;
  if ( jqBatchPoolExternallyLockedCount <= 0
    && _tlAssert(
         "c:\\t6\\code\\tl\\jobqueue\\jobqueue.cpp",
         555,
         "jqBatchPoolExternallyLockedCount > 0",
         "Batch pool unlocked without being locked first.") )
  {
    __debugbreak();
  }
  _InterlockedExchangeAdd(&jqBatchPoolExternallyLockedCount, 0xFFFFFFFF);
  if ( !jqBatchPoolExternallyLockedCount )
    PulseEvent(jqNewJobAdded);
  Target = 0;
  InterlockedExchange(&Target, 0);
  while ( _InterlockedCompareExchange((volatile signed __int32 *)&jqPoolLock, 0, 1) != 1 )
    ;
}

/*
==============
jqSetBatchDataHeapSize
==============
*/
void jqSetBatchDataHeapSize(unsigned int Size, unsigned int BlockSize)
{
  void *v2; // eax

  if ( jqNWorkers
    && _tlAssert(
         "c:\\t6\\code\\tl\\jobqueue\\jobqueue.cpp",
         564,
         "!jqNWorkers",
         "This function can only be called when the JobQueue is stopped.") )
  {
    __debugbreak();
  }
  if ( !Size && _tlAssert("c:\\t6\\code\\tl\\jobqueue\\jobqueue.cpp", 565, "Size > 0", "Invalid batch pool size.") )
    __debugbreak();
  if ( stru_10E5580.LevelData )
    tlMemFree(stru_10E5580.LevelData);
  v2 = tlMemAlloc(Size, 0x80u, 0);
  jqAtomicHeap::Init(&stru_10E5580, v2, Size, BlockSize);
}

/*
==============
jqInit
==============
*/
void jqInit()
{
  jqAtomicQueue<jqBatch,32>::NodeType *v0; // eax
  DWORD v1; // eax

  jqPool.ThisPtr = &jqPool;
  stru_10E5548.ThisPtr = &stru_10E5548;
  stru_10E5548._FreeList.Val64 = 0i64;
  stru_10E5548.FreeListPtr = &stru_10E5548._FreeList;
  v0 = jqAtomicQueue<jqBatch,32>::AllocateNode(&stru_10E5548);
  v0->Next.Ptr = NULL;
  stru_10E5548.Tail.Ptr = v0;
  stru_10E5548.Head.Ptr = v0;
  dword_10E5570 = 0;
  jqAtomicQueue<jqBatch,32>::AllocateNodeBlock(&stru_10E5548, 128);
  v1 = GetCurrentThreadId();
  jqSleepingWorkersCount = 0;
  jqMainThreadID = v1;
  _jqInit();
}

/*
==============
jqInitQueue
==============
*/
void jqInitQueue(jqQueue *Queue)
{
  jqAtomicQueue<jqBatch,32> *v1; // esi
  jqAtomicQueue<jqBatch,32>::NodeType *v2; // eax

  Queue->ThisPtr = Queue;
  Queue->QueuedBatchCount = 0;
  v1 = &Queue->Queue;
  v1->ThisPtr = v1;
  v1->_FreeList.Ptr = NULL;
  v1->_FreeList.Count = 0;
  v1->FreeListPtr = stru_10E5548.FreeListPtr;
  v2 = jqAtomicQueue<jqBatch,32>::AllocateNode(&Queue->Queue);
  v2->Next.Ptr = NULL;
  Queue->Queue.Tail.Ptr = v2;
  Queue->Queue.Head.Ptr = v2;
  Queue->ProcessorsMask = 0;
}

/*
==============
jqInitWorker
==============
*/
void jqInitWorker(jqWorker *Worker)
{
  jqWorker *v1; // esi
  jqAtomicQueue<jqBatch,32> *v2; // edi
  jqAtomicQueue<jqBatch,32>::NodeType *v3; // eax

  v1 = Worker;
  v1->ThisPtr = v1;
  Worker->WorkerSpecific.QueuedBatchCount = 0;
  v1->WorkerSpecific.ThisPtr = &v1->WorkerSpecific;
  v2 = &Worker->WorkerSpecific.Queue;
  v2->ThisPtr = v2;
  v2->_FreeList.Ptr = NULL;
  v2->_FreeList.Count = 0;
  v2->FreeListPtr = stru_10E5548.FreeListPtr;
  v3 = jqAtomicQueue<jqBatch,32>::AllocateNode(&Worker->WorkerSpecific.Queue);
  v3->Next.Ptr = NULL;
  Worker->WorkerSpecific.Queue.Tail.Ptr = v3;
  Worker->WorkerSpecific.Queue.Head.Ptr = v3;
  Worker->WorkerSpecific.ProcessorsMask = 0;
  Worker->NumQueues = 0;
  Worker->Queues[0] = NULL;
  Worker->Queues[1] = NULL;
  Worker->Queues[2] = NULL;
  Worker->Queues[3] = NULL;
  Worker->Queues[4] = NULL;
  Worker->Queues[5] = NULL;
  Worker->Queues[6] = NULL;
  Worker->Queues[7] = NULL;
}

/*
==============
jqAddBatchToQueue
==============
*/
void jqAddBatchToQueue(jqBatch *Batch, jqQueue *Queue)
{
  jqBatchGroup *v2; // eax

  if ( !Batch->Module
    && _tlAssert(
         "c:\\t6\\code\\tl\\jobqueue\\jobqueue.cpp",
         303,
         "Batch.Module != NULL",
         "Batch has no module assigned.") )
  {
    __debugbreak();
  }
  v2 = Batch->GroupID;
  if ( v2 )
    _InterlockedExchangeAdd(&v2->QueuedBatchCount, 1u);
  _InterlockedExchangeAdd(&Batch->Module->Group.QueuedBatchCount, 1u);
  _InterlockedExchangeAdd(&dword_10E5578, 1u);
  _InterlockedExchangeAdd(&Queue->QueuedBatchCount, 1u);
  jqAtomicQueue<jqBatch,32>::Push(&Queue->Queue, Batch);
  PulseEvent(jqNewJobAdded);
}

/*
==============
jqAddBatch
==============
*/
void jqAddBatch(jqBatch *Data, jqQueue *Queue)
{
  jqQueue *v2; // eax

  v2 = Queue;
  if ( !Queue )
    v2 = &jqGlobalQueue;
  jqAddBatchToQueue(Data, v2);
}

/*
==============
jqAddBatch
==============
*/
void jqAddBatch(jqModule *Module, void *Input, void *Output, jqBatchGroup *GroupID, jqQueue *Queue, void *ParamData, int ParamSize)
{
  jqQueue *v7; // ebx
  jqBatch Batch; // [esp+10h] [ebp-100h]

  v7 = Queue;
  Batch.p3x_info = NULL;
  Batch.ConditionalAddress = NULL;
  Batch.ConditionalValue = 0;
  Batch.Module = Module;
  Batch.Input = Input;
  Batch.Output = Output;
  Batch.GroupID = GroupID;
  if ( (ParamSize < 0 || ParamSize > 220)
    && _tlAssert(
         "c:\\t6\\code\\tl\\jobqueue\\jobqueue.cpp",
         355,
         "ParamSize >= 0 && ParamSize <= (int)sizeof(Batch.ParamData)",
         "Invalid Batch ParamSize.") )
  {
    __debugbreak();
  }
  if ( ParamData && ParamSize )
    memcpy((char *)Batch.ParamData, (char *)ParamData, ParamSize);
  memset((char *)Batch.ParamData + ParamSize, 205, 220 - ParamSize);
  if ( !Queue )
    v7 = &jqGlobalQueue;
  jqAddBatchToQueue(&Batch, v7);
}

/*
==============
jqSkipBatch
==============
*/
void jqSkipBatch()
{
  int v0; // eax
  jqBatch *v1; // ecx
  jqQueue *v2; // eax

  v0 = *((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + LODWORD(_tls_index));
  v1 = *(jqBatch **)(v0 + 14972);
  v2 = *(jqQueue **)(v0 + 14964);
  if ( !v2 )
    v2 = &jqGlobalQueue;
  jqAddBatchToQueue(v1, v2);
}

/*
==============
jqInitConditionalQueue
==============
*/
void jqInitConditionalQueue(jqConditionalQueue *Queue)
{
  jqAtomicQueue<jqBatch,32> *v1; // esi
  jqAtomicQueue<jqBatch,32>::NodeType *v2; // eax

  Queue->Queue.ThisPtr = &Queue->Queue;
  Queue->Queue.QueuedBatchCount = 0;
  v1 = &Queue->Queue.Queue;
  v1->ThisPtr = v1;
  v1->_FreeList.Ptr = NULL;
  v1->_FreeList.Count = 0;
  v1->FreeListPtr = stru_10E5548.FreeListPtr;
  v2 = jqAtomicQueue<jqBatch,32>::AllocateNode(&Queue->Queue.Queue);
  v2->Next.Ptr = NULL;
  Queue->Queue.Queue.Tail.Ptr = v2;
  Queue->Queue.Queue.Head.Ptr = v2;
  Queue->Queue.ProcessorsMask = 0;
  Queue->DstQueue = NULL;
}

/*
==============
jqInsertQueueDelayed
==============
*/
void jqInsertQueueDelayed(jqConditionalQueue *srcQueue)
{
  LONG v1; // ecx
  LONG Target; // [esp+0h] [ebp-4h]

  Target = v1;
  _InterlockedCompareExchange((volatile signed __int32 *)&srcQueue->allow, 0, 1);
  Target = 0;
  InterlockedExchange(&Target, 0);
  jqAtomicQueue<jqConditionalQueue *,32>::Push(&jqPendingInsertQueues, &srcQueue);
}

/*
==============
jqInsertQueue
==============
*/
void jqInsertQueue(jqQueue *srcQueue, jqQueue *dstQueue)
{
  volatile signed __int32 *v2; // esi
  jqQueue *v3; // eax
  volatile signed __int32 *v4; // ebx
  jqAtomicQueue<jqBatch,32> *v5; // edi
  bool v6; // zf
  jqBatch batch; // [esp+4h] [ebp-FCh]
  jqAtomicQueue<jqBatch,32> *srcQueuea; // [esp+108h] [ebp+8h]

  v2 = &srcQueue->QueuedBatchCount;
  if ( srcQueue->QueuedBatchCount > 0 )
  {
    v3 = dstQueue;
    batch.p3x_info = NULL;
    batch.Input = NULL;
    batch.Output = NULL;
    batch.Module = NULL;
    batch.ConditionalAddress = NULL;
    batch.ConditionalValue = 0;
    batch.GroupID = NULL;
    if ( !dstQueue )
      v3 = &jqGlobalQueue;
    v4 = &v3->QueuedBatchCount;
    v5 = &srcQueue->Queue;
    srcQueuea = &v3->Queue;
    do
    {
      jqAtomicQueue<jqBatch,32>::Pop(v5, &batch);
      _InterlockedExchangeAdd(v2, 0xFFFFFFFF);
      _InterlockedExchangeAdd(v4, 1u);
      jqAtomicQueue<jqBatch,32>::Push(srcQueuea, &batch);
      v6 = *v2 == 0;
    }
    while ( *v2 > 0 );
    if ( *v2 < 0 )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\jobqueue\\jobqueue.cpp",
             427,
             "srcQueue->QueuedBatchCount >= 0",
             "Negative number of jobs in srcQueue?") )
      {
        __debugbreak();
      }
      v6 = *v2 == 0;
    }
    if ( !v6 )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\jobqueue\\jobqueue.cpp",
             428,
             "srcQueue->QueuedBatchCount == 0",
             "the src queue should be empty when insert is done") )
      {
        __debugbreak();
      }
    }
  }
}

/*
==============
jqInsertPendingQueues
==============
*/
void __thiscall jqInsertPendingQueues(jqConditionalQueue *this)
{
  jqConditionalQueue *v1; // esi
  jqConditionalQueue *srcQueue; // [esp+0h] [ebp-4h]

  srcQueue = this;
  while ( jqAtomicQueue<jqConditionalQueue *,32>::Pop(&jqPendingInsertQueues, &srcQueue) )
  {
    v1 = srcQueue;
    if ( _InterlockedCompareExchange((volatile signed __int32 *)&srcQueue->allow, 1, 1) == 1
      && _tlAssert(
           "c:\\t6\\code\\tl\\jobqueue\\jobqueue.cpp",
           443,
           "!srcQueue->CanUse()",
           "src queue should not be used at this time.") )
    {
      __debugbreak();
    }
    if ( _InterlockedCompareExchange(&v1->lock, 0, 0) )
    {
      jqAtomicQueue<jqConditionalQueue *,32>::Push(&jqPendingInsertQueues, &srcQueue);
    }
    else if ( v1->Queue.QueuedBatchCount > 0 )
    {
      jqInsertQueue(&v1->Queue, v1->DstQueue);
    }
  }
}

/*
==============
jqStop
==============
*/
void jqStop()
{
  if ( GetCurrentThreadId() != jqMainThreadID
    && _tlAssert(
         "c:\\t6\\code\\tl\\jobqueue\\jobqueue.cpp",
         264,
         "jqGetCurrentThreadID() == jqGetMainThreadID()",
         "jqStop can only be called from the main thread.") )
  {
    __debugbreak();
  }
  if ( jqWorkers )
  {
    jqFlush(NULL, 0i64);
    if ( dword_10E5578 )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\jobqueue\\jobqueue.cpp",
             269,
             "jqPool.QueuedBatchCount == 0",
             "Stop failed to stop all batches.") )
      {
        __debugbreak();
      }
    }
    _jqStop();
    tlMemFree(jqTempWorkers);
    jqNWorkers = 0;
    tlMemFree(jqWorkers);
    jqWorkers = NULL;
  }
}

/*
==============
jqAssistWithBatches
==============
*/
void jqAssistWithBatches(bool (*callback)(void *), void *context, jqBatchGroup *GroupID, jqQueue *Queue)
{
  jqWorker *v4; // eax

  if ( jqTempWorkers )
  {
    if ( !callback
      && _tlAssert("c:\\t6\\code\\tl\\jobqueue\\jobqueue.cpp", 506, "callback", "You must supply a callback function") )
    {
      __debugbreak();
    }
    if ( jqNextAvailTempWorker >= 16
      && _tlAssert(
           "c:\\t6\\code\\tl\\jobqueue\\jobqueue.cpp",
           507,
           "jqNextAvailTempWorker < JQ_MAX_TEMP_WORKERS",
           "Ran out of temp workers - worker thread calling jqAssistWithBatches, or jqAssistWithBatches being called recursively?") )
    {
      __debugbreak();
    }
    v4 = (jqWorker *)((char *)jqTempWorkers + 128 * _InterlockedExchangeAdd(&jqNextAvailTempWorker, 1u));
    v4->Processor = -1;
    v4->NumQueues = 1;
    if ( Queue )
      v4->Queues[0] = Queue;
    else
      v4->Queues[0] = &jqGlobalQueue;
    jqTempWorkerLoop(v4, GroupID, callback, context);
    _InterlockedExchangeAdd(&jqNextAvailTempWorker, 0xFFFFFFFF);
  }
}

/*
==============
jqShutdown
==============
*/
void jqShutdown()
{
  if ( GetCurrentThreadId() != jqMainThreadID
    && _tlAssert(
         "c:\\t6\\code\\tl\\jobqueue\\jobqueue.cpp",
         122,
         "jqGetCurrentThreadID() == jqGetMainThreadID()",
         "jqShutdown() can only be called from the main thread.") )
  {
    __debugbreak();
  }
  jqStop();
  CloseHandle(jqNewJobAdded);
  jqSleepingWorkersCount = 0;
}

/*
==============
jqStart
==============
*/
void jqStart()
{
  bool v0; // zf
  unsigned int v1; // ecx
  int v2; // eax
  unsigned int v3; // eax
  int v4; // edx
  signed int v5; // ecx
  int v6; // esi
  jqAtomicQueue<jqBatch,32> *v7; // esi
  jqAtomicQueue<jqBatch,32> *v8; // ebx
  signed __int64 v9; // rax
  int v10; // esi
  jqAtomicQueue<jqBatch,32> *v11; // esi
  jqAtomicQueue<jqBatch,32> *v12; // ebx
  signed __int64 v13; // rax
  jqAtomicQueuePtr<jqAtomicQueue<jqBatch,32>::NodeType> *v14; // ecx
  jqAtomicQueue<jqBatch,32>::NodeType *v15; // esi
  unsigned int v16; // ST28_4
  jqAtomicQueuePtr<jqAtomicQueue<jqBatch,32>::NodeType> *v17; // edi
  jqAtomicQueue<jqBatch,32>::NodeType *v18; // esi
  unsigned int v19; // ST28_4
  jqAtomicQueuePtr<jqAtomicQueue<jqConditionalQueue *,32>::NodeType> *v20; // edi
  jqAtomicQueue<jqConditionalQueue *,32>::NodeType *v21; // esi
  unsigned int v22; // ST28_4
  __int64 v23; // [esp+Ch] [ebp-20h]
  __int64 v24; // [esp+Ch] [ebp-20h]
  int ProcessorsMask; // [esp+14h] [ebp-18h]
  int v26; // [esp+1Ch] [ebp-10h]
  int id; // [esp+20h] [ebp-Ch]
  int ida; // [esp+20h] [ebp-Ch]
  int Processor; // [esp+24h] [ebp-8h]

  if ( GetCurrentThreadId() != jqMainThreadID
    && _tlAssert(
         "c:\\t6\\code\\tl\\jobqueue\\jobqueue.cpp",
         194,
         "jqGetCurrentThreadID() == jqGetMainThreadID()",
         "jqStart can only be called from the main thread.") )
  {
    __debugbreak();
  }
  jqStop();
  v1 = jqProcessorsMask | 1;
  v0 = (jqProcessorsMask | 1) == 0;
  jqProcessorsMask |= 1u;
  v2 = 0;
  if ( !v0 )
  {
    do
    {
      v1 &= v1 - 1;
      ++v2;
    }
    while ( v1 );
  }
  jqNWorkers = v2;
  jqWorkers = (jqWorker *)tlMemAlloc(v2 << 7, 8u, 0);
  memset((char *)jqWorkers, 0, jqNWorkers << 7);
  v3 = jqProcessorsMask;
  v4 = 0;
  v5 = 1;
  id = 0;
  Processor = 1;
  if ( jqProcessorsMask )
  {
    v6 = 0;
    v26 = 0;
    do
    {
      if ( !(v5 & v3) )
      {
        do
          v5 *= 2;
        while ( !(v5 & v3) );
        Processor = v5;
      }
      v7 = (jqAtomicQueue<jqBatch,32> *)((char *)jqWorkers + v6);
      v7->Head.Ptr = (jqAtomicQueue<jqBatch,32>::NodeType *)v7;
      v7[2].FreeListPtr = NULL;
      v7->ThisPtr = (jqAtomicQueue<jqBatch,32> *)((char *)v7 + 32);
      v8 = v7 + 1;
      ProcessorsMask = v5 ^ v3;
      v8->ThisPtr = v8;
      v8->_FreeList.Ptr = NULL;
      v8->_FreeList.Count = 0;
      v8->FreeListPtr = stru_10E5548.FreeListPtr;
      while ( 1 )
      {
        while ( 1 )
        {
          v9 = v8->FreeListPtr->Val64;
          LODWORD(v23) = v9;
          if ( (_DWORD)v9 )
            break;
          jqAtomicQueue<jqBatch,32>::AllocateNodeBlock(v8, 32);
        }
        HIDWORD(v23) = v8->FreeListPtr->Count;
        if ( _InterlockedCompareExchange64(
               (volatile signed __int64 *)v8->FreeListPtr,
               __PAIR__(HIDWORD(v9) + 1, *(_DWORD *)v9),
               v9) == v23 )
          break;
        v8 = v7 + 1;
      }
      *(_DWORD *)v9 = 0;
      v7[1].Tail.Ptr = (jqAtomicQueue<jqBatch,32>::NodeType *)v9;
      v7[1].Head.Ptr = (jqAtomicQueue<jqBatch,32>::NodeType *)v9;
      v5 = Processor;
      *((_DWORD *)&v7[2].FreeListPtr + 1) = 0;
      v7->Tail.Count = 0;
      v7[2]._FreeList.Ptr = NULL;
      v7[2]._FreeList.Count = 0;
      v7[2].Head.Ptr = NULL;
      v7[2].Head.Count = 0;
      v7[2].Tail.Ptr = NULL;
      v7[2].Tail.Count = 0;
      v7[2].ThisPtr = NULL;
      *((_DWORD *)&v7[2].ThisPtr + 1) = 0;
      jqWorkers[v26].Processor = Processor;
      jqWorkers[v26].WorkerID = id;
      v3 = ProcessorsMask;
      v4 = id + 1;
      v6 = v26 * 128 + 128;
      ++id;
      ++v26;
    }
    while ( ProcessorsMask );
  }
  if ( v4 != jqNWorkers
    && _tlAssert("c:\\t6\\code\\tl\\jobqueue\\jobqueue.cpp", 223, "id == jqNWorkers", "Worker count mismatch.") )
  {
    __debugbreak();
  }
  jqTempWorkers = tlMemAlloc(0x800u, 8u, 0);
  memset((char *)jqTempWorkers, 0, 0x800u);
  v10 = 0;
  ida = 0;
  do
  {
    v11 = (jqAtomicQueue<jqBatch,32> *)((char *)jqTempWorkers + v10);
    v11->Head.Ptr = (jqAtomicQueue<jqBatch,32>::NodeType *)v11;
    v11[2].FreeListPtr = NULL;
    v11->ThisPtr = (jqAtomicQueue<jqBatch,32> *)((char *)v11 + 32);
    v12 = v11 + 1;
    v12->ThisPtr = v12;
    v12->_FreeList.Ptr = NULL;
    v12->_FreeList.Count = 0;
    v12->FreeListPtr = stru_10E5548.FreeListPtr;
    while ( 1 )
    {
      while ( 1 )
      {
        v13 = v12->FreeListPtr->Val64;
        LODWORD(v24) = v13;
        if ( (_DWORD)v13 )
          break;
        jqAtomicQueue<jqBatch,32>::AllocateNodeBlock(v12, 32);
      }
      HIDWORD(v24) = v12->FreeListPtr->Count;
      if ( _InterlockedCompareExchange64(
             (volatile signed __int64 *)v12->FreeListPtr,
             __PAIR__(HIDWORD(v13) + 1, *(_DWORD *)v13),
             v13) == v24 )
        break;
      v12 = v11 + 1;
    }
    *(_DWORD *)v13 = 0;
    v11[1].Tail.Ptr = (jqAtomicQueue<jqBatch,32>::NodeType *)v13;
    v11[1].Head.Ptr = (jqAtomicQueue<jqBatch,32>::NodeType *)v13;
    *((_DWORD *)&v11[2].FreeListPtr + 1) = 0;
    v11->Tail.Count = 0;
    v11[2]._FreeList.Ptr = NULL;
    v11[2]._FreeList.Count = 0;
    v11[2].Head.Ptr = NULL;
    v11[2].Head.Count = 0;
    v11[2].Tail.Ptr = NULL;
    v11[2].Tail.Count = 0;
    v11[2].ThisPtr = NULL;
    *((_DWORD *)&v11[2].ThisPtr + 1) = 0;
    v10 = ida + 128;
    ida = v10;
  }
  while ( v10 < 2048 );
  v14 = stru_10E5548.FreeListPtr;
  jqGlobalQueue.ThisPtr = &jqGlobalQueue;
  jqGlobalQueue.QueuedBatchCount = 0;
  jqGlobalQueue.Queue.ThisPtr = &jqGlobalQueue.Queue;
  jqGlobalQueue.Queue._FreeList.Val64 = 0i64;
  for ( jqGlobalQueue.Queue.FreeListPtr = stru_10E5548.FreeListPtr; ; v14 = jqGlobalQueue.Queue.FreeListPtr )
  {
    v15 = v14->Ptr;
    if ( !v14->Ptr )
    {
      jqAtomicQueue<jqBatch,32>::AllocateNodeBlock(&jqGlobalQueue.Queue, 32);
      continue;
    }
    v16 = v14->Count;
    if ( _InterlockedCompareExchange64(
           (volatile signed __int64 *)v14,
           __PAIR__(v14->Count + 1, v15->Next.Ptr),
           v14->Val64) == __PAIR__(v16, (unsigned int)v15) )
      break;
  }
  v15->Next.Ptr = NULL;
  jqGlobalQueue.Queue.Tail.Ptr = v15;
  jqGlobalQueue.Queue.Head.Ptr = v15;
  jqGlobalQueue.ProcessorsMask = 0;
  jqAttachQueueToWorkers(&jqGlobalQueue, 0xFFu);
  v17 = stru_10E5548.FreeListPtr;
  jqHighPriorityQueue.ThisPtr = &jqHighPriorityQueue;
  unk_82459E8 = 0;
  stru_82459C0.ThisPtr = &stru_82459C0;
  stru_82459C0._FreeList.Val64 = 0i64;
  for ( stru_82459C0.FreeListPtr = stru_10E5548.FreeListPtr; ; v17 = stru_82459C0.FreeListPtr )
  {
    v18 = v17->Ptr;
    if ( !v17->Ptr )
    {
      jqAtomicQueue<jqBatch,32>::AllocateNodeBlock(&stru_82459C0, 32);
      continue;
    }
    v19 = v17->Count;
    if ( _InterlockedCompareExchange64(
           (volatile signed __int64 *)v17,
           __PAIR__(v17->Count + 1, v18->Next.Ptr),
           v17->Val64) == __PAIR__(v19, (unsigned int)v18) )
      break;
  }
  v18->Next.Ptr = NULL;
  stru_82459C0.Tail.Ptr = v18;
  stru_82459C0.Head.Ptr = v18;
  unk_82459EC = 0;
  jqAttachQueueToWorkers(&jqHighPriorityQueue, 0xFFu);
  jqPendingInsertQueues._FreeList.Val64 = 0i64;
  v20 = &jqPendingInsertQueues._FreeList;
  jqPendingInsertQueues.ThisPtr = &jqPendingInsertQueues;
  for ( jqPendingInsertQueues.FreeListPtr = &jqPendingInsertQueues._FreeList; ; v20 = jqPendingInsertQueues.FreeListPtr )
  {
    v21 = v20->Ptr;
    if ( !v20->Ptr )
    {
      jqAtomicQueue<jqConditionalQueue *,32>::AllocateNodeBlock(&jqPendingInsertQueues, 32);
      continue;
    }
    v22 = v20->Count;
    if ( _InterlockedCompareExchange64(
           (volatile signed __int64 *)v20,
           __PAIR__(v20->Count + 1, v21->Next.Ptr),
           v20->Val64) == __PAIR__(v22, (unsigned int)v21) )
      break;
  }
  v21->Next.Ptr = NULL;
  jqPendingInsertQueues.Tail.Ptr = v21;
  jqPendingInsertQueues.Head.Ptr = v21;
  _jqStart();
}

