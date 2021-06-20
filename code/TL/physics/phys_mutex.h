/*
==============
minspec_mutex::Unlock
==============
*/
void __thiscall minspec_mutex::Unlock(minspec_mutex *this)
{
  minspec_mutex *v1; // esi
  LONG Target; // [esp+4h] [ebp-4h]

  v1 = this;
  Target = 0;
  InterlockedExchange(&Target, 0);
  if ( v1->m_token != 1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mutex.h",
         85,
         "GetStuff32(&m_token) == 1",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( _InterlockedCompareExchange((volatile signed __int32 *)v1, 0, 1) != 1
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mutex.h", 88, "retv", (const char *)&pBlock) )
  {
    __debugbreak();
  }
}

/*
==============
minspec_read_write_mutex::ReadLock
==============
*/
void __thiscall minspec_read_write_mutex::ReadLock(minspec_read_write_mutex *this)
{
  volatile unsigned int count; // ST10_4
  LONG Target; // [esp+Ch] [ebp-4h]

  do
  {
    while ( this->m_count < 1 )
      ;
    count = this->m_count;
  }
  while ( _InterlockedCompareExchange((volatile signed __int32 *)this, count + 1, this->m_count) != count );
  Target = 0;
  InterlockedExchange(&Target, 0);
}

/*
==============
minspec_read_write_mutex::ReadUnlock
==============
*/
void __thiscall minspec_read_write_mutex::ReadUnlock(minspec_read_write_mutex *this)
{
  minspec_read_write_mutex *v1; // esi
  signed __int32 count; // [esp+8h] [ebp-4h]

  v1 = this;
  do
  {
    count = v1->m_count;
    if ( v1->m_count <= 1
      && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mutex.h", 116, "count > 1", (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
  while ( _InterlockedCompareExchange((volatile signed __int32 *)v1, count - 1, count) != count );
}

/*
==============
minspec_read_write_mutex::WriteUnlock
==============
*/
void __thiscall minspec_read_write_mutex::WriteUnlock(minspec_read_write_mutex *this)
{
  minspec_read_write_mutex *v1; // esi
  LONG Target; // [esp+4h] [ebp-4h]

  v1 = this;
  Target = 0;
  InterlockedExchange(&Target, 0);
  if ( v1->m_count
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mutex.h",
         135,
         "GetStuff32(&m_count) == 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( _InterlockedCompareExchange((volatile signed __int32 *)v1, 1, 0) != 0
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mutex.h", 138, "retv", (const char *)&pBlock) )
  {
    __debugbreak();
  }
}

