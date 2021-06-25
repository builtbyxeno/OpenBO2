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
phys_slot_pool::encode_size_alignment
==============
*/
unsigned int phys_slot_pool::encode_size_alignment(const unsigned int size, const unsigned int alignment)
{
  if ( size > 0xFFFF && _tlAssert("source/phys_mem_new.cpp", 38, "size <= 0xFFFF", (const char *)&pBlock) )
    __debugbreak();
  if ( alignment > 0xFFFF && _tlAssert("source/phys_mem_new.cpp", 39, "alignment <= 0xFFFF", (const char *)&pBlock) )
    __debugbreak();
  return size | (alignment << 16);
}

/*
==============
phys_memory_manager_term
==============
*/
void phys_memory_manager_term()
{
  g_phys_memory_buffer = NULL;
  g_phys_memory_buffer_size = 0;
  g_phys_memory_manager = NULL;
}

/*
==============
phys_slot_pool::init
==============
*/
void __thiscall phys_slot_pool::init(phys_slot_pool *this, const unsigned int slot_size, const unsigned int slot_alignment)
{
  phys_slot_pool *v3; // esi

  v3 = this;
  this->m_first_free_slot.m_ptr = NULL;
  this->m_first_free_slot.m_tag = 0;
  this->m_map_key = phys_slot_pool::encode_size_alignment(slot_size, slot_alignment);
  v3->m_total_slot_count = 0;
  v3->m_allocated_slot_count = 0;
}

/*
==============
ppu_pmm_get_linear_buffer
==============
*/
void ppu_pmm_get_linear_buffer(char ***linear_buffer_cur, char **linear_buffer_end)
{
  *linear_buffer_cur = &g_phys_memory_manager->m_buffer_cur;
  *linear_buffer_end = g_phys_memory_manager->m_buffer_end;
}

/*
==============
PSP_FREE
==============
*/
void PSP_FREE(void *slot_pool, void *slot)
{
  phys_slot_pool::free_slot((phys_slot_pool *)slot_pool, slot);
}

/*
==============
transient_allocator_update_largest_size
==============
*/
void transient_allocator_update_largest_size(int)
{
	//Failed decompiling
}

/*
==============
phys_memory_manager::allocate
==============
*/
int __thiscall phys_memory_manager::allocate(phys_memory_manager *this, const unsigned int size, const unsigned int alignment)
{
  unsigned int v3; // edx
  unsigned int v4; // eax
  volatile signed __int32 *v5; // edi
  signed __int32 v6; // esi
  int v7; // edx
  unsigned int v9; // [esp+Ch] [ebp-8h]
  phys_memory_manager *v10; // [esp+10h] [ebp-4h]
  unsigned int alignmenta; // [esp+20h] [ebp+Ch]

  v3 = alignment - 1;
  v4 = ~(alignment - 1);
  v10 = this;
  alignmenta = alignment - 1;
  v9 = v4;
  v5 = (volatile signed __int32 *)&this->m_buffer_cur;
  while ( 1 )
  {
    v7 = v4 & (*v5 + v3);
    if ( (char *)(v7 + size) > this->m_buffer_end )
      return 0;
    v6 = *v5;
    if ( _InterlockedCompareExchange(v5, v7 + size, v6) == v6 )
      break;
    this = v10;
    v3 = alignmenta;
    v4 = v9;
  }
  return v7;
}

/*
==============
phys_memory_manager::allocate_slot_pool
==============
*/
phys_slot_pool *__thiscall phys_memory_manager::allocate_slot_pool(phys_memory_manager *this)
{
  phys_memory_manager *v1; // esi
  signed int v2; // eax
  int v3; // edi
  LONG Target; // [esp+Ch] [ebp-4h]

  v1 = this;
  while ( _InterlockedCompareExchange((volatile signed __int32 *)&this->m_slot_pool_allocate_mutex, 1, 0) )
    ;
  Target = 0;
  InterlockedExchange(&Target, 0);
  v2 = v1->m_list_preallocated_slot_pools_count;
  if ( v2 >= 28 )
  {
    v3 = phys_memory_manager::allocate(v1, 0x18u, 8u);
  }
  else
  {
    v3 = (int)&v1->m_list_preallocated_slot_pools[v2];
    v1->m_list_preallocated_slot_pools_count = v2 + 1;
  }
  ++v1->m_list_slot_pool_count;
  minspec_mutex::Unlock(&v1->m_slot_pool_allocate_mutex);
  return (phys_slot_pool *)v3;
}

/*
==============
phys_memory_manager::get_slot_pool
==============
*/
phys_slot_pool *__thiscall phys_memory_manager::get_slot_pool(phys_memory_manager *this, unsigned int slot_size, unsigned int slot_alignment)
{
  phys_memory_manager *v3; // ebx
  unsigned int v4; // esi
  unsigned int v5; // edi
  phys_slot_pool *i; // esi
  phys_slot_pool *j; // edx
  LONG Target; // [esp+10h] [ebp-8h]
  minspec_read_write_mutex *v10; // [esp+14h] [ebp-4h]
  unsigned int slot_sizea; // [esp+20h] [ebp+8h]

  v3 = this;
  if ( slot_alignment < 4 && _tlAssert("source/phys_mem_new.cpp", 204, "slot_alignment >= 4", (const char *)&pBlock) )
    __debugbreak();
  v4 = slot_size;
  if ( slot_size % slot_alignment
    && _tlAssert("source/phys_mem_new.cpp", 205, "slot_size % slot_alignment == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( slot_alignment & 3
    && _tlAssert(
         "source/phys_mem_new.cpp",
         208,
         "slot_alignment % PHYS_ALIGNOF(phys_slot_pool::extra_info) == 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  slot_sizea = slot_size + 8;
  v5 = phys_slot_pool::encode_size_alignment(v4 + 8, slot_alignment);
  v10 = &v3->m_slot_pool_map_mutex;
  minspec_read_write_mutex::ReadLock(&v3->m_slot_pool_map_mutex);
  for ( i = v3->m_slot_pool_map.m_hash_table[v5 % v3->m_slot_pool_map.m_mod]; i; i = i->m_hash_next )
  {
    if ( i->m_map_key == v5 )
      break;
  }
  minspec_read_write_mutex::ReadUnlock(v10);
  if ( !i )
  {
    while ( _InterlockedCompareExchange((volatile signed __int32 *)v10, 0, 1) != 1 )
      ;
    Target = 0;
    InterlockedExchange(&Target, 0);
    for ( j = v3->m_slot_pool_map.m_hash_table[v5 % v3->m_slot_pool_map.m_mod]; j; j = j->m_hash_next )
    {
      if ( j->m_map_key == v5 )
        break;
    }
    i = j;
    if ( !j )
    {
      i = phys_memory_manager::allocate_slot_pool(v3);
      i->m_first_free_slot.m_ptr = NULL;
      i->m_first_free_slot.m_tag = 0;
      i->m_map_key = phys_slot_pool::encode_size_alignment(slot_sizea, slot_alignment);
      i->m_total_slot_count = 0;
      i->m_allocated_slot_count = 0;
      minspec_hash_table<phys_slot_pool,64>::add(&v3->m_slot_pool_map, v5, i);
    }
    minspec_read_write_mutex::WriteUnlock(v10);
  }
  return i;
}

/*
==============
PMM_PERM_ALLOCATE
==============
*/
void *PMM_PERM_ALLOCATE(const unsigned int size, const unsigned int alignment)
{
  void *result; // eax
  void *v3; // esi

  result = (void *)phys_memory_manager::allocate(g_phys_memory_manager, size, alignment);
  v3 = result;
  if ( !result )
  {
    if ( _tlAssert("source/phys_mem_new.cpp", 265, "ptr", "physics memory manager error: out of memory.") )
      __debugbreak();
    result = v3;
  }
  return result;
}

/*
==============
PMM_ALLOC
==============
*/
void *PMM_ALLOC(const unsigned int size, const unsigned int alignment)
{
  phys_slot_pool *v2; // eax

  if ( !size && _tlAssert("source/phys_mem_new.cpp", 465, "size > 0", (const char *)&pBlock) )
    __debugbreak();
  v2 = phys_memory_manager::get_slot_pool(g_phys_memory_manager, size, alignment);
  return phys_slot_pool::allocate_slot(v2);
}

/*
==============
PMM_FREE
==============
*/
void PMM_FREE(void *ptr, const unsigned int size, const unsigned int alignment)
{
  phys_slot_pool *v3; // eax

  v3 = phys_memory_manager::get_slot_pool(g_phys_memory_manager, size, alignment);
  phys_slot_pool::free_slot(v3, ptr);
}

/*
==============
PSP_ALLOC
==============
*/
void *PSP_ALLOC(void *slot_pool)
{
  return phys_slot_pool::allocate_slot((phys_slot_pool *)slot_pool);
}

/*
==============
GET_PHYS_SLOT_POOL
==============
*/
phys_slot_pool *GET_PHYS_SLOT_POOL(const unsigned int size, const unsigned int alignment)
{
  if ( !size && _tlAssert("source/phys_mem_new.cpp", 489, "size > 0", (const char *)&pBlock) )
    __debugbreak();
  return phys_memory_manager::get_slot_pool(g_phys_memory_manager, size, alignment);
}

/*
==============
PMM_VALIDATE
==============
*/
void PMM_VALIDATE(void *ptr, const unsigned int size, const unsigned int alignment)
{
  phys_slot_pool *v3; // eax

  v3 = phys_memory_manager::get_slot_pool(g_phys_memory_manager, size, alignment);
  phys_slot_pool::validate_slot(v3, ptr);
}

/*
==============
phys_memory_manager::phys_memory_manager
==============
*/
void __thiscall phys_memory_manager::phys_memory_manager(phys_memory_manager *this, void *const memory_buffer, const int memory_buffer_size)
{
  this->m_slot_pool_map_mutex.m_count = 1;
  memset(&this->m_slot_pool_map, 0, 0x100u);
  this->m_slot_pool_map.m_mod = 1;
  this->m_slot_pool_map.m_highest_collision = 0;
  this->m_slot_pool_map.m_total_collisions = 0;
  this->m_slot_pool_allocate_mutex.m_token = 0;
  this->m_buffer_start = (char *)memory_buffer;
  this->m_buffer_cur = (char *)memory_buffer;
  this->m_buffer_end = (char *)memory_buffer + memory_buffer_size;
  this->m_list_slot_pool_count = 0;
  memset(&this->m_slot_pool_map, 0, 0x100u);
  this->m_slot_pool_map.m_highest_collision = 0;
  this->m_slot_pool_map.m_total_collisions = 0;
  this->m_slot_pool_map.m_mod = 1;
  this->m_list_preallocated_slot_pools_count = 0;
}

/*
==============
phys_memory_manager_init
==============
*/
void phys_memory_manager_init(void *const memory_buffer, const int memory_buffer_size)
{
  phys_memory_manager *v2; // ecx

  if ( g_phys_memory_buffer
    && _tlAssert("source/phys_mem_new.cpp", 237, "g_phys_memory_buffer == NULL", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( g_phys_memory_buffer_size
    && _tlAssert("source/phys_mem_new.cpp", 238, "g_phys_memory_buffer_size == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( g_phys_memory_manager
    && _tlAssert("source/phys_mem_new.cpp", 239, "g_phys_memory_manager == NULL", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v2 = (phys_memory_manager *)(((unsigned int)memory_buffer + 7) & 0xFFFFFFF8);
  g_phys_memory_buffer = memory_buffer;
  g_phys_memory_buffer_size = memory_buffer_size;
  g_phys_memory_manager = (phys_memory_manager *)(((unsigned int)memory_buffer + 7) & 0xFFFFFFF8);
  if ( v2 )
    phys_memory_manager::phys_memory_manager(v2, &v2[1], memory_buffer_size + (_BYTE *)memory_buffer - (_BYTE *)&v2[1]);
}

/*
==============
phys_slot_pool::extra_info_init
==============
*/
void __thiscall phys_slot_pool::extra_info_init(phys_slot_pool *this, void *slot)
{
  phys_slot_pool **v2; // eax

  if ( slot )
  {
    v2 = (phys_slot_pool **)((char *)slot + (this->m_map_key & 0xFFFF) - 8);
    *v2 = this;
    v2[1] = (phys_slot_pool *)-19088744;
    _InterlockedExchangeAdd(&this->m_total_slot_count, 1u);
    _InterlockedExchangeAdd(&this->m_allocated_slot_count, 1u);
    if ( this->m_allocated_slot_count > this->m_total_slot_count )
    {
      if ( _tlAssert(
             "source/phys_mem_new.cpp",
             296,
             "GetStuff32(&m_allocated_slot_count) <= GetStuff32(&m_total_slot_count)",
             "internal error.") )
      {
        __debugbreak();
      }
    }
    slot = NULL;
    InterlockedExchange((volatile LONG *)&slot, 0);
  }
}

/*
==============
phys_slot_pool::extra_info_allocate
==============
*/
void __thiscall phys_slot_pool::extra_info_allocate(phys_slot_pool *this, void *slot)
{
  phys_slot_pool *v2; // esi
  char *v3; // ebx
  unsigned int v4; // edi
  bool v5; // zf
  int v6; // edi
  LONG Target; // [esp+Ch] [ebp-4h]

  v2 = this;
  Target = 0;
  InterlockedExchange(&Target, 0);
  v3 = (char *)slot;
  v4 = v2->m_map_key;
  if ( !slot && _tlAssert("source/phys_mem_new.cpp", 306, "slot", (const char *)&pBlock) )
    __debugbreak();
  v5 = *(_DWORD *)&v3[(unsigned __int16)v4 - 8] == (_DWORD)v2;
  v6 = (int)&v3[(unsigned __int16)v4 - 8];
  if ( !v5
    && _tlAssert("source/phys_mem_new.cpp", 309, "GetStuff32(&ei->m_slot_pool_owner) == this_", "internal error.") )
  {
    __debugbreak();
  }
  if ( _InterlockedCompareExchange((volatile signed __int32 *)(v6 + 4), -19088744, (signed __int32)v2) != (_DWORD)v2
    && _tlAssert("source/phys_mem_new.cpp", 312, "retv", "internal error.") )
  {
    __debugbreak();
  }
  _InterlockedExchangeAdd(&v2->m_allocated_slot_count, 1u);
  if ( v2->m_allocated_slot_count > v2->m_total_slot_count
    && _tlAssert(
         "source/phys_mem_new.cpp",
         314,
         "GetStuff32(&m_allocated_slot_count) <= GetStuff32(&m_total_slot_count)",
         "internal error.") )
  {
    __debugbreak();
  }
  slot = NULL;
  InterlockedExchange((volatile LONG *)&slot, 0);
}

/*
==============
phys_slot_pool::extra_info_free
==============
*/
void __thiscall phys_slot_pool::extra_info_free(phys_slot_pool *this, void *slot)
{
  phys_slot_pool *v2; // esi
  char *v3; // ebx
  unsigned int v4; // edi
  LONG Target; // [esp+Ch] [ebp-4h]

  v2 = this;
  Target = 0;
  InterlockedExchange(&Target, 0);
  v3 = (char *)slot;
  v4 = v2->m_map_key;
  if ( !slot && _tlAssert("source/phys_mem_new.cpp", 323, "slot", (const char *)&pBlock) )
    __debugbreak();
  v4 = (unsigned __int16)v4;
  memset(v3, 255, (unsigned __int16)v4 - 8);
  if ( *(phys_slot_pool **)&v3[(unsigned __int16)v4 - 8] != v2
    && _tlAssert(
         "source/phys_mem_new.cpp",
         329,
         "GetStuff32(&ei->m_slot_pool_owner) == this_",
         "attempting to free a slot that was not allocated from this pool.") )
  {
    __debugbreak();
  }
  if ( _InterlockedCompareExchange((volatile signed __int32 *)&v3[v4 - 4], (signed __int32)v2, -19088744) != -19088744
    && _tlAssert(
         "source/phys_mem_new.cpp",
         332,
         "retv",
         "incorrect owner attempting to free a slot, possibly trying to free a slot more than once.") )
  {
    __debugbreak();
  }
  _InterlockedExchangeAdd(&v2->m_allocated_slot_count, 0xFFFFFFFF);
  if ( v2->m_allocated_slot_count > v2->m_total_slot_count
    && _tlAssert(
         "source/phys_mem_new.cpp",
         334,
         "GetStuff32(&m_allocated_slot_count) <= GetStuff32(&m_total_slot_count)",
         "internal error.") )
  {
    __debugbreak();
  }
  if ( v2->m_allocated_slot_count < 0
    && _tlAssert("source/phys_mem_new.cpp", 335, "GetStuff32(&m_allocated_slot_count) >= 0", "internal error.") )
  {
    __debugbreak();
  }
  slot = NULL;
  InterlockedExchange((volatile LONG *)&slot, 0);
}

/*
==============
phys_slot_pool::validate_slot
==============
*/
void __thiscall phys_slot_pool::validate_slot(phys_slot_pool *this, void *slot)
{
  phys_slot_pool *v2; // esi
  phys_slot_pool **v3; // edi
  LONG Target; // [esp+8h] [ebp-4h]

  v2 = this;
  Target = 0;
  InterlockedExchange(&Target, 0);
  v3 = (phys_slot_pool **)((char *)slot + (v2->m_map_key & 0xFFFF) - 8);
  if ( *v3 != v2
    && _tlAssert(
         "source/phys_mem_new.cpp",
         346,
         "GetStuff32(&ei->m_slot_pool_owner) == this_",
         "slot does not belong to this slot_pool.") )
  {
    __debugbreak();
  }
  if ( v3[1] != (phys_slot_pool *)-19088744 )
  {
    if ( _tlAssert(
           "source/phys_mem_new.cpp",
           347,
           "GetStuff32(&ei->m_allocation_owner) == allocation_owner",
           "slot does not belong to this allocation_owner.") )
    {
      __debugbreak();
    }
  }
}

/*
==============
phys_slot_pool::free_slot
==============
*/
void __userpurge phys_slot_pool::free_slot(phys_slot_pool *this@<ecx>, unsigned int a2@<ebp>, void *slot)
{
  _DWORD *v3; // edi
  phys_slot_pool *v4; // esi
  signed __int64 v5; // ST1C_8
  tagged_void_pointer_t first_slot; // [esp+0h] [ebp-10h]
  int v7; // [esp+8h] [ebp-8h]
  int retaddr; // [esp+10h] [ebp+0h]

  first_slot.m_tag = a2;
  v7 = retaddr;
  v3 = slot;
  v4 = this;
  if ( !slot && _tlAssert("source/phys_mem_new.cpp", 445, "slot", "no support support for freeing NULL slots.") )
    __debugbreak();
  phys_slot_pool::extra_info_free(v4, slot);
  while ( 1 )
  {
    v5 = (signed __int64)v4->m_first_free_slot;
    *v3 = v4->m_first_free_slot.m_ptr;
    first_slot.m_ptr = NULL;
    InterlockedExchange((volatile LONG *)&first_slot, 0);
    if ( _InterlockedCompareExchange64((volatile signed __int64 *)v4, __PAIR__(HIDWORD(v5) + 1, (unsigned int)v3), v5) == v5 )
      break;
    v3 = slot;
  }
}

/*
==============
phys_slot_pool::allocate_slot
==============
*/
_DWORD *__usercall phys_slot_pool::allocate_slot@<eax>(phys_slot_pool *this@<ecx>, unsigned int a2@<ebp>)
{
  phys_slot_pool *v2; // edi
  _DWORD *v3; // esi
  void *v5; // esi
  unsigned int v6; // [esp-8h] [ebp-18h]
  int v7; // [esp-4h] [ebp-14h]
  tagged_void_pointer_t first_slot; // [esp+0h] [ebp-10h]
  int v9; // [esp+8h] [ebp-8h]
  int retaddr; // [esp+10h] [ebp+0h]

  first_slot.m_tag = a2;
  v9 = retaddr;
  v2 = this;
  for ( first_slot.m_ptr = this; ; v2 = (phys_slot_pool *)first_slot.m_ptr )
  {
    v3 = v2->m_first_free_slot.m_ptr;
    v6 = v2->m_first_free_slot.m_tag;
    if ( !v2->m_first_free_slot.m_ptr )
      break;
    v7 = 0;
    InterlockedExchange(&v7, 0);
    if ( _InterlockedCompareExchange64(
           (volatile signed __int64 *)v2,
           __PAIR__(v6 + 1, *v3),
           __PAIR__(v6, (unsigned int)v3)) == __PAIR__(v6, (unsigned int)v3) )
    {
      phys_slot_pool::extra_info_allocate((phys_slot_pool *)first_slot.m_ptr, v3);
      return v3;
    }
  }
  v5 = (void *)phys_memory_manager::allocate(
                 g_phys_memory_manager,
                 (unsigned __int16)v2->m_map_key,
                 v2->m_map_key >> 16);
  phys_slot_pool::extra_info_init(v2, v5);
  return v5;
}

/*
==============
init
==============
*/
int init(void **a)
{
  mp_int *v1; // eax
  int v3; // eax
  int v4; // esi

  if ( !a )
    crypt_argchk("a != NULL", "c:\\t6\\code\\libs\\libtomcrypt-1.17\\src\\math\\ltm_desc.c", 48);
  v1 = (mp_int *)tom_game_calloc(1u, 0x10u);
  *a = v1;
  if ( !v1 )
    return 13;
  v3 = mp_init(v1);
  v4 = mpi_to_ltc_error(v3);
  if ( v4 )
    tom_game_free(*a);
  return v4;
}

