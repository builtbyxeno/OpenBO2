/*
==============
jqCanBatchExecute
==============
*/
char jqCanBatchExecute()
{
  return 1;
}

/*
==============
jqWorkerSleep
==============
*/
BOOL __thiscall jqWorkerSleep(void *this)
{
  LONG Target; // [esp+0h] [ebp-4h]

  Target = (LONG)this;
  while ( !dword_10E5578 )
  {
    if ( jqStopSignal )
      break;
    if ( jqKeepWorkersAwakeCount )
      break;
    _InterlockedExchangeAdd(&jqSleepingWorkersCount, 1u);
    WaitForSingleObject(jqNewJobAdded, 1u);
    _InterlockedExchangeAdd(&jqSleepingWorkersCount, 0xFFFFFFFF);
  }
  Sleep(0);
  Target = 0;
  InterlockedExchange(&Target, 0);
  return jqStopSignal == 0;
}

/*
==============
jqExecuteBatch
==============
*/
int jqExecuteBatch(jqWorker *Worker, jqBatch *Batch)
{
  int v2; // esi

  jqProfBeginNamedEvent(0, Batch->Module->Name);
  v2 = Batch->Module->Code(Batch);
  jqProfBeginNamedEvent(0, "$end");
  return v2;
}

/*
==============
jqWorkerThread
==============
*/
unsigned int jqWorkerThread(void *_this)
{
  char ThreadName[256]; // [esp+4h] [ebp-104h]

  sprintf(ThreadName, "JQ Worker %d (Processor 0x%x)", *((_DWORD *)_this + 6), *((_DWORD *)_this + 5));
  SetThreadName(0xFFFFFFFF, ThreadName);
  *((_DWORD *)_this + 2) = GetCurrentThreadId();
  jqWorkerLoop((jqWorker *)_this, NULL, 0, NULL);
  return 0;
}
