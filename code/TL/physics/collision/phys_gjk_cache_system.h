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
phys_gjk_cache_info::update_swapped
==============
*/
void __userpurge phys_gjk_cache_info::update_swapped(phys_gjk_cache_info *this@<ecx>, int a2@<ebp>, const bool swapped)
{
  unsigned int v3; // edi
  unsigned int v4; // edi
  float v5; // xmm1_4
  float v6; // xmm2_4
  __int64 v7; // ST10_8
  __int64 v8; // ST18_8
  __int64 temp_4; // ST20_8
  __int64 temp_12; // ST28_8
  __int64 temp_20; // ST30_8
  __int64 v12; // xmm0_8
  int v13; // [esp+34h] [ebp-Ch]
  int v14; // [esp+38h] [ebp-8h]
  int retaddr; // [esp+40h] [ebp+0h]

  v13 = a2;
  v14 = retaddr;
  v3 = this->m_flags;
  if ( swapped != ((this->m_flags >> 1) & 1) )
  {
    if ( swapped )
      v4 = v3 | 2;
    else
      v4 = v3 & 0xFFFFFFFD;
    this->m_flags = v4;
    if ( v4 & 4 )
    {
      LODWORD(v5) = LODWORD(this->m_support_dir.y) ^ _mask__NegFloat_;
      LODWORD(v6) = LODWORD(this->m_support_dir.z) ^ _mask__NegFloat_;
      LODWORD(this->m_support_dir.x) ^= _mask__NegFloat_;
      this->m_support_dir.y = v5;
      this->m_support_dir.z = v6;
    }
    if ( v4 & 8 )
    {
      v7 = *(_QWORD *)&this->m_support_a.m_indices[0].x;
      v8 = *(_QWORD *)&this->m_support_a.m_indices[0].z;
      temp_4 = *(_QWORD *)&this->m_support_a.m_indices[1].x;
      temp_12 = *(_QWORD *)&this->m_support_a.m_indices[1].z;
      temp_20 = *(_QWORD *)&this->m_support_a.m_indices[2].x;
      v12 = *(_QWORD *)&this->m_support_a.m_indices[2].z;
      this->m_support_a.m_indices[0].x = this->m_support_b.m_indices[0].x;
      this->m_support_a.m_indices[0].y = this->m_support_b.m_indices[0].y;
      this->m_support_a.m_indices[0].z = this->m_support_b.m_indices[0].z;
      this->m_support_a.m_indices[1].x = this->m_support_b.m_indices[1].x;
      this->m_support_a.m_indices[1].y = this->m_support_b.m_indices[1].y;
      this->m_support_a.m_indices[1].z = this->m_support_b.m_indices[1].z;
      this->m_support_a.m_indices[2].x = this->m_support_b.m_indices[2].x;
      this->m_support_a.m_indices[2].y = this->m_support_b.m_indices[2].y;
      this->m_support_a.m_indices[2].z = this->m_support_b.m_indices[2].z;
      *(_QWORD *)&this->m_support_b.m_indices[0].x = v7;
      LODWORD(this->m_support_b.m_indices[0].z) = v8;
      *(_QWORD *)&this->m_support_b.m_indices[1].x = temp_4;
      LODWORD(this->m_support_b.m_indices[1].z) = temp_12;
      *(_QWORD *)&this->m_support_b.m_indices[2].x = temp_20;
      LODWORD(this->m_support_b.m_indices[2].z) = v12;
    }
  }
}

/*
==============
phys_heap_gjk_cache_system_avl_tree::get_gjk_cache_info
==============
*/
phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *__thiscall phys_heap_gjk_cache_system_avl_tree::get_gjk_cache_info(phys_heap_gjk_cache_system_avl_tree *this, unsigned int id1, unsigned int id2, const bool __formal)
{
  unsigned int v4; // esi
  unsigned int v5; // edi
  phys_heap_gjk_cache_system_avl_tree *v6; // ebx
  bool v7; // cf
  bool v8; // zf
  unsigned int v9; // eax
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v10; // eax
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v11; // esi
  unsigned int v13; // eax
  phys_gjk_geom_id_pair_key key; // [esp+Ch] [ebp-8h]
  int savedregs; // [esp+14h] [ebp+0h]
  bool swapped; // [esp+1Ch] [ebp+8h]

  v4 = id1;
  v5 = id2;
  v6 = this;
  v7 = id1 < id2;
  v8 = id1 == id2;
  if ( id1 == id2 )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_gjk_cache_system.h",
           309,
           "id1 != id2",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v7 = id1 < id2;
    v8 = id1 == id2;
  }
  if ( v7 || v8 )
  {
    swapped = 0;
  }
  else
  {
    v9 = id1;
    v4 = id2;
    swapped = 1;
    v5 = v9;
  }
  if ( v4 >= v5
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_gjk_cache_system.h",
         24,
         "id1 < id2",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  key.m_id1 = v4;
  key.m_id2 = v5;
  v10 = phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::find(
          &v6->m_search_tree,
          &key);
  v11 = v10;
  if ( v10 )
  {
    phys_gjk_cache_info::update_swapped((phys_gjk_cache_info *)&v10->m_support_dir, (int)&savedregs, swapped);
    return v11;
  }
  if ( v6->m_list_phys_gjk_cache_info_internal.m_count >= v6->m_max_num_gjk_ci )
  {
    if ( (pai_gjk_cache_system_max_num_gjk_ci.m_hits_total_count < dword_10E58C0 || !dword_10E58C0)
      && dword_10E58BC < dword_10E58C4 )
    {
      if ( byte_10E58C8 )
      {
        PHYS_WARNING(
          "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_gjk_cache_system.h",
          328,
          "m_list_phys_gjk_cache_info_internal.get_count() < m_max_num_gjk_ci",
          "max num gjk_ci reached.");
      }
      else if ( _tlAssert(
                  "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_gjk_cache_system.h",
                  328,
                  "m_list_phys_gjk_cache_info_internal.get_count() < m_max_num_gjk_ci",
                  "max num gjk_ci reached.") )
      {
        __debugbreak();
      }
    }
    _InterlockedExchangeAdd(&pai_gjk_cache_system_max_num_gjk_ci.m_hits_total_count, 1u);
    _InterlockedExchangeAdd(&dword_10E58BC, 1u);
  }
  if ( v6->m_list_phys_gjk_cache_info_internal.m_count >= v6->m_max_num_gjk_ci )
    return v11;
  v11 = (phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *)PMM_ALLOC(0x90u, 0x10u);
  if ( v11 )
  {
    ++v6->m_list_phys_gjk_cache_info_internal.m_count;
    v13 = key.m_id2;
    v11->m_key.m_id1 = key.m_id1;
    v11->m_flags = 0;
    v11->m_flags = swapped != 0 ? 2 : 0;
    v11->m_key.m_id2 = v13;
    phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::add(
      &v6->m_search_tree,
      &key,
      v11);
    v11->m_next_gjk_ci = v6->m_list_head;
    v6->m_list_head = v11;
    return v11;
  }
  if ( (pai_gjk_cache_system_create_gjk_ci.m_hits_total_count < dword_10E58D8 || !dword_10E58D8)
    && dword_10E58D4 < dword_10E58DC )
  {
    if ( byte_10E58E0 )
    {
      PHYS_WARNING(
        "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_gjk_cache_system.h",
        332,
        "gjk_ci",
        "gjk_ci memory allocation failed.");
    }
    else if ( _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_gjk_cache_system.h",
                332,
                "gjk_ci",
                "gjk_ci memory allocation failed.") )
    {
      __debugbreak();
    }
  }
  _InterlockedExchangeAdd(&pai_gjk_cache_system_create_gjk_ci.m_hits_total_count, 1u);
  _InterlockedExchangeAdd(&dword_10E58D4, 1u);
  return 0;
}

/*
==============
get_gjk_cache_info
==============
*/
phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *get_gjk_cache_info(phys_heap_gjk_cache_system_avl_tree *gjk_cache, gjk_base_t *cg1, gjk_base_t *cg2)
{
  unsigned int v3; // esi

  if ( !gjk_cache || !g_use_gjk_cache )
    return 0;
  if ( !(cg2->m_flags & 4)
    && _tlAssert(
         "c:\\t6\\code\\src_noserver\\physics\\phys_colgeom.h",
         86,
         "get_flag(FLAG_GEOM_ID_VALID)",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v3 = cg2->m_gjk_geom_id;
  if ( !(cg1->m_flags & 4)
    && _tlAssert(
         "c:\\t6\\code\\src_noserver\\physics\\phys_colgeom.h",
         86,
         "get_flag(FLAG_GEOM_ID_VALID)",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  return phys_heap_gjk_cache_system_avl_tree::get_gjk_cache_info(gjk_cache, cg1->m_gjk_geom_id, v3, 1);
}

/*
==============
phys_heap_gjk_cache_system_avl_tree::shutdown
==============
*/
void __thiscall phys_heap_gjk_cache_system_avl_tree::shutdown(phys_heap_gjk_cache_system_avl_tree *this)
{
  phys_heap_gjk_cache_system_avl_tree *v1; // esi
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v2; // eax
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v3; // ebx
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v4; // edi

  v1 = this;
  if ( this->m_list_head )
  {
    do
    {
      v2 = v1->m_list_head;
      v3 = v2->m_next_gjk_ci;
      phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::remove(
        &v1->m_search_tree,
        &v2->m_key);
      v4 = v1->m_list_head;
      if ( v4 )
      {
        PMM_VALIDATE(v4, 0x90u, 0x10u);
        --v1->m_list_phys_gjk_cache_info_internal.m_count;
        PMM_FREE(v4, 0x90u, 0x10u);
      }
      v1->m_list_head = v3;
    }
    while ( v3 );
  }
  if ( v1->m_list_phys_gjk_cache_info_internal.m_count )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_gjk_cache_system.h",
           260,
           "m_list_phys_gjk_cache_info_internal.get_count() == 0",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
}

/*
==============
phys_heap_gjk_cache_system_avl_tree::~phys_heap_gjk_cache_system_avl_tree
==============
*/
void __thiscall phys_heap_gjk_cache_system_avl_tree::~phys_heap_gjk_cache_system_avl_tree(phys_heap_gjk_cache_system_avl_tree *this)
{
  phys_heap_gjk_cache_system_avl_tree::shutdown(this);
}

/*
==============
phys_heap_gjk_cache_system_avl_tree::update_cache
==============
*/
void __thiscall phys_heap_gjk_cache_system_avl_tree::update_cache(phys_heap_gjk_cache_system_avl_tree *this)
{
  phys_heap_gjk_cache_system_avl_tree *v1; // edi
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v2; // esi
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal **v3; // ebx
  unsigned int v4; // eax

  v1 = this;
  v2 = this->m_list_head;
  v3 = &this->m_list_head;
  if ( v2 )
  {
    do
    {
      v4 = v2->m_flags;
      if ( v4 & 1 )
      {
        v3 = &v2->m_next_gjk_ci;
        v2->m_flags = v4 & 0xFFFFFFFE;
      }
      else
      {
        *v3 = v2->m_next_gjk_ci;
        phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::remove(
          &v1->m_search_tree,
          &v2->m_key);
        PMM_VALIDATE(v2, 0x90u, 0x10u);
        --v1->m_list_phys_gjk_cache_info_internal.m_count;
        PMM_FREE(v2, 0x90u, 0x10u);
      }
      v2 = *v3;
    }
    while ( *v3 );
  }
}

/*
==============
phys_heap_gjk_cache_system_avl_tree::get_gjk_cache_info_mutex
==============
*/
phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *__thiscall phys_heap_gjk_cache_system_avl_tree::get_gjk_cache_info_mutex(phys_heap_gjk_cache_system_avl_tree *this, unsigned int id1, unsigned int id2, tlAtomicReadWriteMutex *query_mutex, const bool __formal)
{
  unsigned int v5; // esi
  unsigned int v6; // edi
  phys_heap_gjk_cache_system_avl_tree *v7; // ebx
  bool v8; // cf
  bool v9; // zf
  unsigned int v10; // eax
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v11; // eax
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v12; // esi
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v14; // eax
  unsigned int v15; // ecx
  phys_gjk_geom_id_pair_key key; // [esp+Ch] [ebp-8h]
  int savedregs; // [esp+14h] [ebp+0h]
  bool swapped; // [esp+1Ch] [ebp+8h]

  v5 = id1;
  v6 = id2;
  v7 = this;
  v8 = id1 < id2;
  v9 = id1 == id2;
  if ( id1 == id2 )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_gjk_cache_system.h",
           347,
           "id1 != id2",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v8 = id1 < id2;
    v9 = id1 == id2;
  }
  if ( v8 || v9 )
  {
    swapped = 0;
  }
  else
  {
    v10 = id1;
    v5 = id2;
    swapped = 1;
    v6 = v10;
  }
  if ( v5 >= v6
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_gjk_cache_system.h",
         24,
         "id1 < id2",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  key.m_id1 = v5;
  key.m_id2 = v6;
  tlAtomicReadWriteMutex::ReadLock(query_mutex);
  v11 = phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::find(
          &v7->m_search_tree,
          &key);
  v12 = v11;
  _InterlockedExchangeAdd(&query_mutex->ThisPtr->ReadLockCount, 0xFFFFFFFF);
  if ( v11 )
  {
    phys_gjk_cache_info::update_swapped((phys_gjk_cache_info *)&v11->m_support_dir, (int)&savedregs, swapped);
    return v12;
  }
  if ( v7->m_list_phys_gjk_cache_info_internal.m_count >= v7->m_max_num_gjk_ci )
  {
    if ( (pai_gjk_cache_system_max_num_gjk_ci.m_hits_total_count < dword_10E58C0 || !dword_10E58C0)
      && dword_10E58BC < dword_10E58C4 )
    {
      if ( byte_10E58C8 )
      {
        PHYS_WARNING(
          "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_gjk_cache_system.h",
          368,
          "m_list_phys_gjk_cache_info_internal.get_count() < m_max_num_gjk_ci",
          "max num gjk_ci reached.");
      }
      else if ( _tlAssert(
                  "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_gjk_cache_system.h",
                  368,
                  "m_list_phys_gjk_cache_info_internal.get_count() < m_max_num_gjk_ci",
                  "max num gjk_ci reached.") )
      {
        __debugbreak();
      }
    }
    _InterlockedExchangeAdd(&pai_gjk_cache_system_max_num_gjk_ci.m_hits_total_count, 1u);
    _InterlockedExchangeAdd(&dword_10E58BC, 1u);
  }
  if ( v7->m_list_phys_gjk_cache_info_internal.m_count >= v7->m_max_num_gjk_ci )
    return v12;
  tlAtomicReadWriteMutex::WriteLock(query_mutex);
  if ( phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::find(
         &v7->m_search_tree,
         &key)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_gjk_cache_system.h",
         372,
         "m_search_tree.find(key) == NULL",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v14 = (phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *)PMM_ALLOC(0x90u, 0x10u);
  v12 = v14;
  if ( v14 )
  {
    ++v7->m_list_phys_gjk_cache_info_internal.m_count;
    v15 = key.m_id2;
    v14->m_key.m_id1 = key.m_id1;
    v14->m_key.m_id2 = v15;
    v14->m_flags = 0;
    v14->m_flags = swapped != 0 ? 2 : 0;
    phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::add(
      &v7->m_search_tree,
      &key,
      v14);
    v12->m_next_gjk_ci = v7->m_list_head;
    v7->m_list_head = v12;
    tlAtomicReadWriteMutex::WriteUnlock(query_mutex);
    return v12;
  }
  if ( (pai_gjk_cache_system_create_gjk_ci.m_hits_total_count < dword_10E58D8 || !dword_10E58D8)
    && dword_10E58D4 < dword_10E58DC )
  {
    if ( byte_10E58E0 )
    {
      PHYS_WARNING(
        "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_gjk_cache_system.h",
        374,
        "gjk_ci",
        "gjk_ci memory allocation failed.");
    }
    else if ( _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_gjk_cache_system.h",
                374,
                "gjk_ci",
                "gjk_ci memory allocation failed.") )
    {
      __debugbreak();
    }
  }
  _InterlockedExchangeAdd(&pai_gjk_cache_system_create_gjk_ci.m_hits_total_count, 1u);
  _InterlockedExchangeAdd(&dword_10E58D4, 1u);
  tlAtomicReadWriteMutex::WriteUnlock(query_mutex);
  return 0;
}

