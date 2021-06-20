/*
==============
jqPopNextBatchFromQueue
==============
*/
bool jqPopNextBatchFromQueue(jqWorker *Worker, jqQueue *Queue, jqBatchGroup *GroupID, jqBatch *PoppedBatch)
{
  int v4; // edi
  jqBatch *v5; // esi
  int v6; // eax
  int v7; // ecx
  jqBatchGroup *v8; // eax
  jqBatchGroup *v9; // eax
  int CheckedBatches; // [esp+4h] [ebp-4h]

  v6 = *(_DWORD *)(*(_DWORD *)v4 + 48);
  v7 = 0;
  if ( v6 )
  {
    while ( v7 <= v6 )
    {
      CheckedBatches = v7 + 1;
      if ( !jqAtomicQueue<jqBatch,32>::Pop((jqAtomicQueue<jqBatch,32> *)(v4 + 8), v5) )
        break;
      v8 = v5->GroupID;
      if ( !v8 )
        v8 = &v5->Module->Group;
      *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + LODWORD(_tls_index)) + 14964) = v4;
      if ( !GroupID || GroupID == v8 )
      {
        v9 = v5->GroupID;
        if ( v9 )
        {
          _InterlockedExchangeAdd(&v9->ExecutingBatchCount, 1u);
          _InterlockedExchangeAdd(&v5->GroupID->QueuedBatchCount, 0xFFFFFFFF);
          if ( v5->GroupID->QueuedBatchCount < 0 )
          {
            if ( _tlAssert(
                   "c:\\t6\\code\\tl\\jobqueue\\jobqueue_kernel.cpp",
                   88,
                   "PoppedBatch->GroupID->QueuedBatchCount >= 0",
                   "JobQueue group queued count went below zero!") )
            {
              __debugbreak();
            }
          }
        }
        _InterlockedExchangeAdd(&v5->Module->Group.ExecutingBatchCount, 1u);
        _InterlockedExchangeAdd(&v5->Module->Group.QueuedBatchCount, 0xFFFFFFFF);
        _InterlockedExchangeAdd(&jqPool.ThisPtr->ExecutingBatchCount, 1u);
        _InterlockedExchangeAdd(&jqPool.ThisPtr->QueuedBatchCount, 0xFFFFFFFF);
        _InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)v4 + 48), 0xFFFFFFFF);
        if ( dword_10E5578 < 0
          && _tlAssert(
               "c:\\t6\\code\\tl\\jobqueue\\jobqueue_kernel.cpp",
               99,
               "jqGetPool()->QueuedBatchCount >= 0",
               "JobQueue global queued count went below zero!") )
        {
          __debugbreak();
        }
        if ( *(_DWORD *)(v4 + 48) < 0 )
        {
          if ( _tlAssert(
                 "c:\\t6\\code\\tl\\jobqueue\\jobqueue_kernel.cpp",
                 100,
                 "Queue->QueuedBatchCount >= 0",
                 "JobQueue queue count went below zero!") )
          {
            __debugbreak();
          }
        }
        return 1;
      }
      jqAtomicQueue<jqBatch,32>::Push((jqAtomicQueue<jqBatch,32> *)(v4 + 8), v5);
      v6 = *(_DWORD *)(*(_DWORD *)v4 + 48);
      if ( !v6 )
        return 0;
      v7 = CheckedBatches;
    }
  }
  return 0;
}

/*
==============
jqPopNextBatch
==============
*/
bool jqPopNextBatch(jqWorker *Worker, jqBatchGroup *GroupID, jqBatch *PoppedBatch, bool *doHighPriority)
{
  int v4; // eax
  int v5; // esi
  unsigned int *v7; // ebx
  unsigned int v8; // edi
  int v9; // eax
  int v10; // ecx
  bool *v11; // eax
  int v12; // eax
  jqBatch *v13; // [esp+0h] [ebp-14h]
  jqBatch *v14; // [esp+0h] [ebp-14h]
  int v15; // [esp+Ch] [ebp-8h]
  unsigned int *v16; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]
  jqWorker *doHighPrioritya; // [esp+24h] [ebp+10h]

  v5 = v4;
  if ( jqPopNextBatchFromQueue(Worker, (jqQueue *)GroupID, (jqBatchGroup *)doHighPriority, v13) )
    return 1;
  if ( jqHighPriorityQueue.ThisPtr
    && LOBYTE(doHighPrioritya->Type)
    && jqPopNextBatchFromQueue(doHighPrioritya, (jqQueue *)doHighPriority, (jqBatchGroup *)doHighPriority, v14) )
  {
    LOBYTE(doHighPrioritya->Type) = 0;
    return 1;
  }
  v7 = &PoppedBatch->ParamData[15];
  i = 0;
  v16 = v7;
  do
  {
    v8 = *v7;
    if ( *v7 )
    {
      v9 = *(_DWORD *)(*(_DWORD *)v8 + 48);
      v10 = 0;
      if ( v9 )
      {
        while ( v10 <= v9 )
        {
          v15 = v10 + 1;
          if ( !jqAtomicQueue<jqBatch,32>::Pop((jqAtomicQueue<jqBatch,32> *)(v8 + 8), (jqBatch *)v5) )
            break;
          v11 = *(bool **)(v5 + 16);
          if ( !v11 )
            v11 = (bool *)(*(_DWORD *)(v5 + 12) + 16);
          *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + LODWORD(_tls_index)) + 14964) = v8;
          if ( !doHighPriority || doHighPriority == v11 )
          {
            v12 = *(_DWORD *)(v5 + 16);
            if ( v12 )
            {
              _InterlockedExchangeAdd((volatile signed __int32 *)(v12 + 4), 1u);
              _InterlockedExchangeAdd(*(volatile signed __int32 **)(v5 + 16), 0xFFFFFFFF);
              if ( **(_DWORD **)(v5 + 16) < 0 )
              {
                if ( _tlAssert(
                       "c:\\t6\\code\\tl\\jobqueue\\jobqueue_kernel.cpp",
                       88,
                       "PoppedBatch->GroupID->QueuedBatchCount >= 0",
                       "JobQueue group queued count went below zero!") )
                {
                  __debugbreak();
                }
              }
            }
            _InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)(v5 + 12) + 20), 1u);
            _InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)(v5 + 12) + 16), 0xFFFFFFFF);
            _InterlockedExchangeAdd(&jqPool.ThisPtr->ExecutingBatchCount, 1u);
            _InterlockedExchangeAdd(&jqPool.ThisPtr->QueuedBatchCount, 0xFFFFFFFF);
            _InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)v8 + 48), 0xFFFFFFFF);
            if ( dword_10E5578 < 0
              && _tlAssert(
                   "c:\\t6\\code\\tl\\jobqueue\\jobqueue_kernel.cpp",
                   99,
                   "jqGetPool()->QueuedBatchCount >= 0",
                   "JobQueue global queued count went below zero!") )
            {
              __debugbreak();
            }
            if ( *(_DWORD *)(v8 + 48) < 0 )
            {
              if ( _tlAssert(
                     "c:\\t6\\code\\tl\\jobqueue\\jobqueue_kernel.cpp",
                     100,
                     "Queue->QueuedBatchCount >= 0",
                     "JobQueue queue count went below zero!") )
              {
                __debugbreak();
              }
            }
            return 1;
          }
          jqAtomicQueue<jqBatch,32>::Push((jqAtomicQueue<jqBatch,32> *)(v8 + 8), (jqBatch *)v5);
          v9 = *(_DWORD *)(*(_DWORD *)v8 + 48);
          if ( !v9 )
            break;
          v10 = v15;
        }
      }
    }
    v7 = v16 + 1;
    ++i;
    ++v16;
  }
  while ( i < 8 );
  Sleep(0);
  return 0;
}

/*
==============
jqWorkerLoop
==============
*/
void jqWorkerLoop(jqWorker *Worker, jqBatchGroup *GroupID, bool BreakWhenEmpty, unsigned __int64 *batchCount)
{
  jqWorker *v4; // esi
  jqWorker *v5; // ecx
  jqWorker *v6; // ecx
  _LARGE_INTEGER v7; // rax
  void *v8; // ecx
  const char *v9; // edi
  unsigned __int32 v10; // esi
  jqProfEvent *v11; // eax
  const char *v12; // edi
  unsigned __int32 v13; // esi
  jqProfEvent *v14; // eax
  int v15; // edi
  unsigned __int32 v16; // esi
  jqProfEvent *v17; // eax
  unsigned __int32 v18; // esi
  jqProfEvent *v19; // eax
  _LARGE_INTEGER v20; // rax
  unsigned __int64 lastConditionalCheckTime; // [esp+14h] [ebp-128h]
  void *CachedConditionalAddress; // [esp+1Ch] [ebp-120h]
  unsigned __int64 WorkerStartTime; // [esp+24h] [ebp-118h]
  unsigned int CachedConditionalValue; // [esp+2Ch] [ebp-110h]
  int v25; // [esp+30h] [ebp-10Ch]
  bool doHighPriority; // [esp+3Bh] [ebp-101h]
  jqBatch CurBatch; // [esp+3Ch] [ebp-100h]

  v4 = Worker;
  if ( jqWorkerInitFn && Worker->WorkerID > 0 )
    jqWorkerInitFn(Worker->WorkerID);
  v5 = (jqWorker *)NtCurrentTeb()->ThreadLocalStoragePointer;
  lastConditionalCheckTime = 0i64;
  CachedConditionalAddress = NULL;
  CachedConditionalValue = 0;
  v25 = *((_DWORD *)&v5->Type + LODWORD(_tls_index));
  *(_DWORD *)(v25 + 14968) = Worker;
  doHighPriority = 1;
  CurBatch.p3x_info = NULL;
  CurBatch.Input = NULL;
  CurBatch.Output = NULL;
  CurBatch.Module = NULL;
  CurBatch.ConditionalAddress = NULL;
  CurBatch.ConditionalValue = 0;
  CurBatch.GroupID = NULL;
  while ( 1 )
  {
    if ( jqPopNextBatch(v5, (jqBatchGroup *)&doHighPriority, (jqBatch *)v4, (bool *)GroupID) )
    {
      while ( 1 )
      {
        *(_DWORD *)(v25 + 14972) = &CurBatch;
        v7 = tlPcGetTick();
        v8 = CurBatch.ConditionalAddress;
        WorkerStartTime = v7.QuadPart;
        if ( CachedConditionalAddress == CurBatch.ConditionalAddress
          && CachedConditionalValue == CurBatch.ConditionalValue )
        {
          break;
        }
        if ( !CurBatch.ConditionalAddress )
          goto LABEL_9;
        if ( v7.QuadPart - lastConditionalCheckTime > 0xC350 )
        {
          if ( *(_DWORD *)CurBatch.ConditionalAddress < CurBatch.ConditionalValue )
          {
            v15 = 1;
          }
          else
          {
            CurBatch.ConditionalAddress = NULL;
            v12 = CurBatch.Module->Name;
            CachedConditionalAddress = v8;
            CachedConditionalValue = CurBatch.ConditionalValue;
            if ( dword_8245868 )
            {
              v13 = _InterlockedExchangeAdd((volatile signed __int32 *)dword_8245864, 0x80u);
              v14 = &jqProf.EventBuffer[dword_8245868];
              if ( v13 < (unsigned int)v14 )
              {
                *(_DWORD *)v13 = GetCurrentThreadId();
                *(_DWORD *)(v13 + 4) = 0;
                *(_LARGE_INTEGER *)(v13 + 8) = tlPcGetTick();
                *(_DWORD *)(v13 + 16) = 0;
                _snprintf((char *)(v13 + 32), 0x60u, "%s", v12);
              }
              else
              {
                *(_DWORD *)dword_8245864 = v14;
              }
            }
            v15 = CurBatch.Module->Code(&CurBatch);
            if ( dword_8245868 )
            {
              v16 = _InterlockedExchangeAdd((volatile signed __int32 *)dword_8245864, 0x80u);
              v17 = &jqProf.EventBuffer[dword_8245868];
              if ( v16 < (unsigned int)v17 )
              {
                *(_DWORD *)v16 = GetCurrentThreadId();
                *(_DWORD *)(v16 + 4) = 0;
                *(_LARGE_INTEGER *)(v16 + 8) = tlPcGetTick();
                *(_DWORD *)(v16 + 16) = 0;
                _snprintf((char *)(v16 + 32), 0x60u, "%s", "$end");
              }
              else
              {
                *(_DWORD *)dword_8245864 = v17;
              }
              lastConditionalCheckTime = WorkerStartTime;
LABEL_32:
              v4 = Worker;
LABEL_33:
              if ( v15 )
              {
                if ( v15 == 2 )
                  doHighPriority = 1;
              }
              else
              {
                v20 = tlPcGetTick();
                doHighPriority = 1;
                v4->WorkTime += v20.QuadPart - WorkerStartTime;
              }
              goto LABEL_38;
            }
          }
          lastConditionalCheckTime = WorkerStartTime;
          goto LABEL_32;
        }
        v15 = 1;
        v4 = Worker;
LABEL_38:
        *(_DWORD *)(v25 + 14972) = 0;
        if ( v15 )
        {
          _InterlockedExchangeAdd(&jqPool.ThisPtr->QueuedBatchCount, 1u);
          _InterlockedExchangeAdd(&CurBatch.Module->Group.QueuedBatchCount, 1u);
          _InterlockedExchangeAdd((volatile signed __int32 *)(**(_DWORD **)(v25 + 14964) + 48), 1u);
          if ( CurBatch.GroupID )
            _InterlockedExchangeAdd(&CurBatch.GroupID->QueuedBatchCount, 1u);
          jqAtomicQueue<jqBatch,32>::Push((jqAtomicQueue<jqBatch,32> *)(*(_DWORD *)(v25 + 14964) + 8), &CurBatch);
        }
        _InterlockedExchangeAdd(&jqPool.ThisPtr->ExecutingBatchCount, 0xFFFFFFFF);
        v6 = (jqWorker *)_InterlockedExchangeAdd(&CurBatch.Module->Group.ExecutingBatchCount, 0xFFFFFFFF);
        if ( CurBatch.GroupID )
          _InterlockedExchangeAdd(&CurBatch.GroupID->ExecutingBatchCount, 0xFFFFFFFF);
        if ( !BreakWhenEmpty || !v15 )
        {
          if ( !batchCount || (v6 = (jqWorker *)(*((_DWORD *)batchCount + 1) | *(_DWORD *)batchCount), *batchCount) )
          {
            if ( jqPopNextBatch(v6, (jqBatchGroup *)&doHighPriority, (jqBatch *)v4, (bool *)GroupID) )
              continue;
          }
        }
        goto LABEL_49;
      }
      CurBatch.ConditionalAddress = NULL;
LABEL_9:
      v9 = CurBatch.Module->Name;
      if ( dword_8245868 )
      {
        v10 = _InterlockedExchangeAdd((volatile signed __int32 *)dword_8245864, 0x80u);
        v11 = &jqProf.EventBuffer[dword_8245868];
        if ( v10 < (unsigned int)v11 )
        {
          *(_DWORD *)v10 = GetCurrentThreadId();
          *(_DWORD *)(v10 + 4) = 0;
          *(_LARGE_INTEGER *)(v10 + 8) = tlPcGetTick();
          *(_DWORD *)(v10 + 16) = 0;
          _snprintf((char *)(v10 + 32), 0x60u, "%s", v9);
        }
        else
        {
          *(_DWORD *)dword_8245864 = v11;
        }
        v4 = Worker;
      }
      v15 = CurBatch.Module->Code(&CurBatch);
      if ( dword_8245868 )
      {
        v18 = _InterlockedExchangeAdd((volatile signed __int32 *)dword_8245864, 0x80u);
        v19 = &jqProf.EventBuffer[dword_8245868];
        if ( v18 < (unsigned int)v19 )
        {
          *(_DWORD *)v18 = GetCurrentThreadId();
          *(_DWORD *)(v18 + 4) = 0;
          *(_LARGE_INTEGER *)(v18 + 8) = tlPcGetTick();
          *(_DWORD *)(v18 + 16) = 0;
          _snprintf((char *)(v18 + 32), 0x60u, "%s", "$end");
        }
        else
        {
          *(_DWORD *)dword_8245864 = v19;
        }
        goto LABEL_32;
      }
      goto LABEL_33;
    }
LABEL_49:
    doHighPriority = 1;
    if ( BreakWhenEmpty )
      break;
    if ( !(unsigned __int8)jqWorkerSleep(v6) )
    {
      *(_DWORD *)(v25 + 14968) = 0;
      return;
    }
  }
  *(_DWORD *)(v25 + 14968) = 0;
}

/*
==============
jqTempWorkerLoop
==============
*/
void jqTempWorkerLoop(jqWorker *Worker, jqBatchGroup *GroupID, bool (*callback)(void *), void *context)
{
  jqWorker *v4; // esi
  bool (__cdecl *v5)(void *); // edi
  jqBatchGroup *v6; // edx
  _LARGE_INTEGER v7; // rax
  jqModule *v8; // ecx
  const char *v9; // edi
  unsigned __int32 v10; // esi
  jqProfEvent *v11; // eax
  unsigned __int32 v12; // esi
  jqProfEvent *v13; // eax
  jqBatchGroup *v14; // edx
  unsigned __int64 WorkerStartTime; // [esp+Ch] [ebp-124h]
  int v16; // [esp+1Ch] [ebp-114h]
  int numJobs; // [esp+20h] [ebp-110h]
  int v18; // [esp+24h] [ebp-10Ch]
  bool doHighPriority; // [esp+2Fh] [ebp-101h]
  jqBatch CurBatch; // [esp+30h] [ebp-100h]

  v4 = Worker;
  v5 = callback;
  v18 = *((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + LODWORD(_tls_index));
  *(_DWORD *)(v18 + 14968) = Worker;
  doHighPriority = 1;
  CurBatch.p3x_info = NULL;
  CurBatch.Input = NULL;
  CurBatch.Output = NULL;
  CurBatch.Module = NULL;
  CurBatch.ConditionalAddress = NULL;
  CurBatch.ConditionalValue = 0;
  CurBatch.GroupID = NULL;
  if ( callback(context) )
  {
LABEL_27:
    *(_DWORD *)(v18 + 14968) = 0;
    return;
  }
  while ( 1 )
  {
    numJobs = jqGetQueuedBatchCount(NULL);
    if ( jqPopNextBatch((jqWorker *)GroupID, v6, (jqBatch *)v4, (bool *)GroupID) )
      break;
LABEL_26:
    doHighPriority = 1;
    if ( v5(context) )
      goto LABEL_27;
  }
  while ( 1 )
  {
    v7 = tlPcGetTick();
    v8 = CurBatch.Module;
    WorkerStartTime = v7.QuadPart;
    *(_DWORD *)(v18 + 14972) = &CurBatch;
    v9 = v8->Name;
    if ( dword_8245868 )
    {
      v10 = _InterlockedExchangeAdd((volatile signed __int32 *)dword_8245864, 0x80u);
      v11 = &jqProf.EventBuffer[dword_8245868];
      if ( v10 < (unsigned int)v11 )
      {
        *(_DWORD *)v10 = GetCurrentThreadId();
        *(_DWORD *)(v10 + 4) = 0;
        *(_LARGE_INTEGER *)(v10 + 8) = tlPcGetTick();
        *(_DWORD *)(v10 + 16) = 0;
        _snprintf((char *)(v10 + 32), 0x60u, "%s", v9);
      }
      else
      {
        *(_DWORD *)dword_8245864 = v11;
      }
      v4 = Worker;
    }
    v16 = CurBatch.Module->Code(&CurBatch);
    if ( dword_8245868 )
    {
      v12 = _InterlockedExchangeAdd((volatile signed __int32 *)dword_8245864, 0x80u);
      v13 = &jqProf.EventBuffer[dword_8245868];
      if ( v12 < (unsigned int)v13 )
      {
        *(_DWORD *)v12 = GetCurrentThreadId();
        *(_DWORD *)(v12 + 4) = 0;
        *(_LARGE_INTEGER *)(v12 + 8) = tlPcGetTick();
        *(_DWORD *)(v12 + 16) = 0;
        _snprintf((char *)(v12 + 32), 0x60u, "%s", "$end");
      }
      else
      {
        *(_DWORD *)dword_8245864 = v13;
      }
      v4 = Worker;
    }
    *(_DWORD *)(v18 + 14972) = 0;
    if ( !v16 )
    {
      v4->WorkTime += *(_QWORD *)&tlPcGetTick() - WorkerStartTime;
LABEL_17:
      doHighPriority = 1;
      goto LABEL_18;
    }
    _InterlockedExchangeAdd(&jqPool.ThisPtr->QueuedBatchCount, 1u);
    _InterlockedExchangeAdd(&CurBatch.Module->Group.QueuedBatchCount, 1u);
    _InterlockedExchangeAdd((volatile signed __int32 *)(**(_DWORD **)(v18 + 14964) + 48), 1u);
    if ( CurBatch.GroupID )
      _InterlockedExchangeAdd(&CurBatch.GroupID->QueuedBatchCount, 1u);
    jqAtomicQueue<jqBatch,32>::Push((jqAtomicQueue<jqBatch,32> *)(*(_DWORD *)(v18 + 14964) + 8), &CurBatch);
    if ( v16 == 2 )
      goto LABEL_17;
LABEL_18:
    _InterlockedExchangeAdd(&jqPool.ThisPtr->ExecutingBatchCount, 0xFFFFFFFF);
    v14 = (jqBatchGroup *)((char *)&CurBatch.Module->Group + 4);
    _InterlockedExchangeAdd(&CurBatch.Module->Group.ExecutingBatchCount, 0xFFFFFFFF);
    if ( CurBatch.GroupID )
      _InterlockedExchangeAdd(&CurBatch.GroupID->ExecutingBatchCount, 0xFFFFFFFF);
    if ( v16 )
    {
      if ( --numJobs > 0 )
        goto LABEL_24;
    }
    if ( callback(context) )
      break;
    numJobs = jqGetQueuedBatchCount(NULL);
LABEL_24:
    if ( !jqPopNextBatch((jqWorker *)GroupID, v14, (jqBatch *)v4, (bool *)GroupID) )
    {
      v5 = callback;
      goto LABEL_26;
    }
  }
  *(_DWORD *)(v18 + 14968) = 0;
}

