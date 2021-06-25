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
_jqInit
==============
*/
void _jqInit()
{
  unsigned int v0; // ecx
  unsigned int v1; // edx
  signed int v2; // esi
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h]

  jqNewJobAdded = CreateEventA(NULL, 1, 0, NULL);
  jqProcessorsMask = 0;
  GetSystemInfo(&SystemInfo);
  v0 = 0;
  if ( SystemInfo.dwNumberOfProcessors )
  {
    v1 = jqProcessorsMask;
    do
    {
      v2 = 1 << v0++;
      v1 |= v2;
    }
    while ( v0 < SystemInfo.dwNumberOfProcessors );
    jqProcessorsMask = v1;
  }
}

/*
==============
_jqShutdown
==============
*/
void _jqShutdown()
{
  CloseHandle(jqNewJobAdded);
}

/*
==============
_jqStop
==============
*/
void _jqStop()
{
  int v0; // edi
  int v1; // esi
  void *v2; // eax

  jqStopSignal = 1;
  SetEvent(jqNewJobAdded);
  v0 = 0;
  if ( jqNWorkers > 0 )
  {
    v1 = 0;
    do
    {
      v2 = jqWorkers[v1].Thread;
      if ( v2 )
      {
        WaitForSingleObject(v2, 0xFFFFFFFF);
        CloseHandle(jqWorkers[v1].Thread);
      }
      ++v0;
      ++v1;
    }
    while ( v0 < jqNWorkers );
  }
  jqStopSignal = 0;
  ResetEvent(jqNewJobAdded);
}

/*
==============
_jqAddBatch
==============
*/
void _jqAddBatch(jqBatch const *)
{
	//Failed decompiling
}

/*
==============
jqAlertWorkers
==============
*/
void jqAlertWorkers()
{
  PulseEvent(jqNewJobAdded);
}

/*
==============
jqLockBatchPoolInternal
==============
*/
void __thiscall jqLockBatchPoolInternal(void *this)
{
  LONG Target; // [esp+0h] [ebp-4h]

  Target = (LONG)this;
  while ( _InterlockedCompareExchange((volatile signed __int32 *)&jqPoolLock, 1, 0) )
    Sleep(0);
  Target = 0;
  InterlockedExchange(&Target, 0);
}

/*
==============
jqUnlockBatchPoolInternal
==============
*/
void jqUnlockBatchPoolInternal()
{
  LONG Target; // [esp+0h] [ebp-4h]

  Target = 0;
  InterlockedExchange(&Target, 0);
  while ( _InterlockedCompareExchange((volatile signed __int32 *)&jqPoolLock, 0, 1) != 1 )
    ;
}

/*
==============
_jqStart
==============
*/
void _jqStart()
{
  int v0; // ebx
  bool v1; // zf
  jqWorker *v2; // esi
  HANDLE v3; // edi
  unsigned int ThreadId; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v0 = 0;
  for ( i = 0; i < jqNWorkers; ++i )
  {
    v1 = jqWorkers[v0].Processor == 1;
    v2 = &jqWorkers[v0];
    jqWorkers[v0].Type = 0;
    if ( !v1 )
    {
      v3 = CreateThread(NULL, 0x10000u, jqWorkerThread, v2, 4u, &ThreadId);
      if ( !v3 )
      {
        if ( _tlAssert(
               "c:\\t6\\code\\tl\\base\\include\\tl_thread.h",
               346,
               "thr != 0",
               "tlCreateThread failed to create thread.") )
        {
          __debugbreak();
        }
      }
      v2->Thread = v3;
      ResumeThread(v3);
    }
    ++v0;
  }
}

/*
==============
jqFlush
==============
*/
void jqFlush(jqBatchGroup *GroupID, unsigned __int64 batchCount)
{
  jqBatchGroup *v2; // ebx
  int v3; // edi
  volatile int v4; // esi
  unsigned __int64 zero; // [esp+Ch] [ebp-18h]
  LONG Target; // [esp+14h] [ebp-10h]
  unsigned __int64 *workerBatchCount; // [esp+18h] [ebp-Ch]
  volatile int *ExecutingBatchCount; // [esp+1Ch] [ebp-8h]
  volatile int *QueuedBatchCount; // [esp+20h] [ebp-4h]

  PulseEvent(jqNewJobAdded);
  v2 = GroupID;
  v3 = 0;
  if ( GroupID )
  {
    ExecutingBatchCount = &GroupID->ExecutingBatchCount;
  }
  else
  {
    v2 = (jqBatchGroup *)&dword_10E5578;
    ExecutingBatchCount = &dword_10E557C;
  }
  QueuedBatchCount = &v2->QueuedBatchCount;
  if ( (unsigned __int8)v2 & 7
    && _tlAssert(
         "c:\\t6\\code\\tl\\jobqueue\\xenon/jobqueue_xenon.cpp",
         149,
         "((u32)BatchCount & 0x7)==0",
         "Data not aligned correctly, read won't be atomic!\n") )
  {
    __debugbreak();
  }
  zero = 0i64;
  workerBatchCount = (unsigned __int64 *)v2;
  if ( batchCount )
    workerBatchCount = &zero;
  while ( 1 )
  {
    v4 = *QueuedBatchCount;
    Target = 0;
    InterlockedExchange(&Target, 0);
    if ( !(v4 + *ExecutingBatchCount) && v2->BatchCount <= batchCount )
      break;
    jqWorkerLoop(jqWorkers, GroupID, 1, workerBatchCount);
    if ( ++v3 > 1 )
      Sleep(0);
  }
}

