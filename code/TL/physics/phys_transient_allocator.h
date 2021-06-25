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
phys_transient_allocator::mt_allocate_internal
==============
*/
int __thiscall phys_transient_allocator::mt_allocate_internal(phys_transient_allocator *this, const int size, const int alignment)
{
  int v3; // edx
  int v4; // eax
  char *v5; // esi
  int v6; // eax
  int v7; // edx
  signed __int32 v8; // eax
  int v10; // [esp+10h] [ebp-4h]
  int alignmenta; // [esp+1Ch] [ebp+8h]

  v3 = alignment;
  v4 = alignment - 1;
  v5 = this->m_cur;
  alignmenta = v4;
  v6 = ~v4;
  v7 = v6 & (unsigned int)&v5[v3 - 1];
  v10 = v6;
  v8 = v7 + size;
  if ( (char *)(v7 + size) > this->m_end )
    return 0;
  while ( (char *)_InterlockedCompareExchange((volatile signed __int32 *)&this->m_cur, v8, (signed __int32)v5) != v5 )
  {
    v5 = this->m_cur;
    v7 = v10 & (unsigned int)&v5[alignmenta];
    v8 = v7 + size;
    if ( (char *)(v7 + size) > this->m_end )
      return 0;
  }
  return v7;
}

/*
==============
phys_transient_allocator::mt_allocate
==============
*/
void *__thiscall phys_transient_allocator::mt_allocate(phys_transient_allocator *this, const int size, const int alignment, const int no_error, const char *error_msg)
{
  int v5; // ebp
  phys_transient_allocator *v6; // esi
  int v7; // ebx
  void *result; // eax
  int v9; // edi
  int v10; // eax
  char *v11; // edx
  int v12; // eax
  int v13; // esi

  v5 = size;
  v6 = this;
  transient_allocator_update_largest_size(size);
  minspec_read_write_mutex::ReadLock(&v6->m_mutex);
  v7 = alignment;
  size = phys_transient_allocator::mt_allocate_internal(v6, v5, alignment);
  minspec_read_write_mutex::ReadUnlock(&v6->m_mutex);
  result = (void *)size;
  if ( size )
    return result;
  while ( _InterlockedCompareExchange((volatile signed __int32 *)&v6->m_mutex, 0, 1) != 1 )
    ;
  size = 0;
  InterlockedExchange((volatile LONG *)&size, 0);
  v9 = ~(v7 - 1);
  v10 = v9 & (_DWORD)&v6->m_cur[v7 - 1];
  if ( (char *)(v10 + v5) > v6->m_end || (v6->m_cur = (char *)(v10 + v5), (size = v10) == 0) )
  {
    phys_transient_allocator::resize(v6);
    v11 = v6->m_cur;
    v12 = v9 & (unsigned int)&v11[v7 - 1];
    if ( (char *)(v12 + v5) > v6->m_end )
    {
      size = 0;
      goto LABEL_8;
    }
    v6->m_cur = (char *)(v12 + v5);
    size = v9 & (unsigned int)&v11[v7 - 1];
    if ( !v12 )
    {
LABEL_8:
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_transient_allocator.h",
             99,
             "ptr",
             "transient allocation too large, increase block_size.") )
      {
        __debugbreak();
      }
      goto LABEL_10;
    }
  }
LABEL_10:
  minspec_read_write_mutex::WriteUnlock(&v6->m_mutex);
  v13 = size;
  if ( !size
    && no_error == size
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_transient_allocator.h", 103, "ptr || no_error", error_msg) )
  {
    __debugbreak();
  }
  return (void *)v13;
}

/*
==============
phys_transient_allocator::allocate
==============
*/
char *__thiscall phys_transient_allocator::allocate(phys_transient_allocator *this, const int size, const int alignment, const int no_error, const char *error_msg)
{
  phys_transient_allocator *v5; // esi
  int v6; // edi
  char *result; // eax
  char *v8; // esi

  v5 = this;
  transient_allocator_update_largest_size(size);
  v6 = ~(alignment - 1);
  result = (char *)(v6 & (_DWORD)&v5->m_cur[alignment - 1]);
  if ( &result[size] > v5->m_end || (v5->m_cur = &result[size], !result) )
  {
    phys_transient_allocator::resize(v5);
    result = (char *)(v6 & (_DWORD)&v5->m_cur[alignment - 1]);
    if ( &result[size] <= v5->m_end )
    {
      v5->m_cur = &result[size];
      v8 = result;
      if ( result )
        return result;
    }
    else
    {
      v8 = NULL;
    }
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_transient_allocator.h",
           79,
           "ptr",
           "transient allocation too large, increase block_size.") )
    {
      __debugbreak();
    }
    if ( !no_error
      && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_transient_allocator.h", 81, "ptr || no_error", error_msg) )
    {
      __debugbreak();
    }
    result = v8;
  }
  return result;
}

/*
==============
phys_transient_allocator::~phys_transient_allocator
==============
*/
void __thiscall phys_transient_allocator::~phys_transient_allocator(phys_transient_allocator *this)
{
  if ( this->m_first_block )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_transient_allocator.h",
           69,
           "m_first_block == NULL",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
}

