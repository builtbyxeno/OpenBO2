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
gjk_unique_id_database_t::get_unique_id
==============
*/
signed __int32 __thiscall gjk_unique_id_database_t::get_unique_id(gjk_unique_id_database_t *this)
{
  gjk_unique_id_database_t *v1; // edi
  signed __int32 v2; // esi

  v1 = this;
  do
  {
    v2 = v1->m_counter;
    if ( !v1->m_counter
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase.h",
           153,
           "id != 0",
           "gjk unique_id wrapped around.") )
    {
      __debugbreak();
    }
  }
  while ( _InterlockedCompareExchange((volatile signed __int32 *)v1, v2 + 1, v2) != v2 );
  return v2;
}

/*
==============
broad_phase_environement_query_results::add
==============
*/
void __thiscall broad_phase_environement_query_results::add(broad_phase_environement_query_results *this, broad_phase_base *bpb)
{
  broad_phase_environement_query_results *v2; // esi
  broad_phase_base_list::node *v3; // eax

  v2 = this;
  if ( !(bpb->m_flags & 4) )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase.h",
           389,
           "bpb->is_bpi_env()",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( !(bpb->m_flags & 4)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_base.h",
           103,
           "is_bpi_env()",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
  v3 = *v2->m_list_bpi_env.m_list_cur;
  if ( !v3 )
  {
    v3 = (broad_phase_base_list::node *)phys_transient_allocator::mt_allocate(
                                          &G_BPM->g_collision_memory_buffer,
                                          8,
                                          4,
                                          0,
                                          "broad phase collision out of memory.");
    *v2->m_list_bpi_env.m_list_cur = v3;
    v3->m_next = NULL;
  }
  v3->m_bpb = bpb;
  ++v2->m_list_bpi_env_count;
  v2->m_list_bpi_env.m_list_cur = &v3->m_next;
  v2->m_env_collision_flags |= bpb->m_env_collision_flags;
}

/*
==============
bpei_database_t::create_bpei
==============
*/
broad_phase_environment_info *__thiscall bpei_database_t::create_bpei(bpei_database_t *this, bpei_database_id database_id)
{
  bpei_database_t *v2; // edi
  broad_phase_environment_info *v3; // eax
  broad_phase_environment_info *v4; // esi

  v2 = this;
  v3 = (broad_phase_environment_info *)PMM_ALLOC(0x24u, 4u);
  if ( v3 )
  {
    ++v2->m_bpei_allocator.m_count;
    v3->m_mutex.m_token = 0;
    v4 = v3;
  }
  else
  {
    v4 = NULL;
  }
  phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::add(
    &v2->m_bpei_map,
    &database_id,
    v4);
  v4->m_data = NULL;
  v4->m_gjk_geom_id = gjk_unique_id_database_t::get_unique_id(&g_gjk_unique_id_database);
  return v4;
}

/*
==============
bpei_database_t::get_bpei_mt
==============
*/
broad_phase_environment_info *__thiscall bpei_database_t::get_bpei_mt(bpei_database_t *this, bpei_database_id database_id)
{
  bpei_database_t *v2; // esi
  broad_phase_environment_info *v3; // edi
  LONG Target; // [esp+Ch] [ebp-4h]

  v2 = this;
  minspec_read_write_mutex::ReadLock(&this->m_mutex);
  v3 = phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::find(
         &v2->m_bpei_map,
         &database_id);
  minspec_read_write_mutex::ReadUnlock(&v2->m_mutex);
  if ( !v3 )
  {
    while ( _InterlockedCompareExchange((volatile signed __int32 *)&v2->m_mutex, 0, 1) != 1 )
      ;
    Target = 0;
    InterlockedExchange(&Target, 0);
    v3 = phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::find(
           &v2->m_bpei_map,
           &database_id);
    if ( !v3 )
    {
      v3 = bpei_database_t::create_bpei(v2, database_id);
      v3->m_next_bpei = v2->m_bpei_list;
      v2->m_bpei_list = v3;
    }
    minspec_read_write_mutex::WriteUnlock(&v2->m_mutex);
    if ( !v3
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase.h",
           278,
           "bpei",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
  return v3;
}

/*
==============
bpei_database_t::get_bpei
==============
*/
broad_phase_environment_info *__thiscall bpei_database_t::get_bpei(bpei_database_t *this, bpei_database_id database_id)
{
  bpei_database_t *v2; // edi
  broad_phase_environment_info *result; // eax
  broad_phase_environment_info *v4; // eax
  broad_phase_environment_info *v5; // esi
  bpei_database_id key; // [esp+4h] [ebp-8h]

  v2 = this;
  result = phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::find(
             &this->m_bpei_map,
             &database_id);
  if ( !result )
  {
    key = database_id;
    v4 = (broad_phase_environment_info *)PMM_ALLOC(0x24u, 4u);
    if ( v4 )
    {
      ++v2->m_bpei_allocator.m_count;
      v4->m_mutex.m_token = 0;
      v5 = v4;
    }
    else
    {
      v5 = NULL;
    }
    phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::add(
      &v2->m_bpei_map,
      &key,
      v5);
    v5->m_data = NULL;
    v5->m_gjk_geom_id = gjk_unique_id_database_t::get_unique_id(&g_gjk_unique_id_database);
    v5->m_next_bpei = v2->m_bpei_list;
    v2->m_bpei_list = v5;
    result = v5;
  }
  return result;
}

/*
==============
bpei_database_t::update_database
==============
*/
void __thiscall bpei_database_t::update_database(bpei_database_t *this)
{
  bpei_database_t *v1; // edi
  broad_phase_environment_info *v2; // esi
  broad_phase_environment_info **v3; // ebx

  v1 = this;
  v2 = this->m_bpei_list;
  v3 = &this->m_bpei_list;
  if ( v2 )
  {
    do
    {
      if ( v2->m_data )
      {
        v3 = &v2->m_next_bpei;
        v2->m_data = NULL;
      }
      else
      {
        *v3 = v2->m_next_bpei;
        phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::remove(
          &v1->m_bpei_map,
          &v2->m_database_id);
        PMM_VALIDATE(v2, 0x24u, 4u);
        --v1->m_bpei_allocator.m_count;
        PMM_FREE(v2, 0x24u, 4u);
      }
      v2 = *v3;
    }
    while ( *v3 );
  }
}

/*
==============
bpei_database_t::purge_database
==============
*/
void __thiscall bpei_database_t::purge_database(bpei_database_t *this)
{
  bpei_database_t *v1; // edi
  broad_phase_environment_info *v2; // esi
  broad_phase_environment_info *v3; // ebx

  v1 = this;
  v2 = this->m_bpei_list;
  if ( v2 )
  {
    do
    {
      v3 = v2->m_next_bpei;
      phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::remove(
        &v1->m_bpei_map,
        &v2->m_database_id);
      PMM_VALIDATE(v2, 0x24u, 4u);
      --v1->m_bpei_allocator.m_count;
      PMM_FREE(v2, 0x24u, 4u);
      v2 = v3;
    }
    while ( v3 );
  }
  v1->m_bpei_list = NULL;
}

/*
==============
bpei_database_t::~bpei_database_t
==============
*/
void __thiscall bpei_database_t::~bpei_database_t(bpei_database_t *this)
{
  bpei_database_t::purge_database(this);
}

