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
process_cpi
==============
*/
void process_cpi(contact_point_info *cpi)
{
  contact_point_info *v1; // esi
  phys_collision_pair *v2; // eax
  broad_phase_info *v3; // edx
  rigid_body *v4; // ebx
  rigid_body_constraint_contact *v5; // edi
  contact_point_info *next_cpi; // [esp+4h] [ebp-4h]
  rigid_body *rb2; // [esp+10h] [ebp+8h]

  v1 = cpi;
  if ( cpi )
  {
    do
    {
      next_cpi = v1->m_next_link;
      if ( !v1->m_pcp && _tlAssert("source/phys_collision_multithreaded.cpp", 78, "cpi->m_pcp", (const char *)&pBlock) )
        __debugbreak();
      v2 = v1->m_pcp;
      v3 = v2->m_bpi2;
      v4 = v2->m_bpi1->m_rb;
      v5 = v1->m_rbc_contact;
      rb2 = v3->m_rb;
      if ( v5 || (v5 = phys_sys::create_rbc_contact(v4, v3->m_rb, v1->m_flags & 8)) != NULL )
      {
        v5->m_solver_priority = v1->m_flags & 7;
        if ( !v1->m_list_b1_r_loc
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\rbc_defs\\rbc_def_contact.h",
               365,
               "cpi->m_list_b1_r_loc",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        if ( !v1->m_list_b2_r_loc
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\rbc_defs\\rbc_def_contact.h",
               366,
               "cpi->m_list_b2_r_loc",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        if ( !v1->m_list_pulse_sum_cache_info
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\rbc_defs\\rbc_def_contact.h",
               367,
               "cpi->m_list_pulse_sum_cache_info",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        if ( v1->m_point_pair_count <= 0 )
        {
          if ( _tlAssert(
                 "c:\\t6\\code\\tl\\physics\\include\\rbc_defs\\rbc_def_contact.h",
                 368,
                 "cpi->m_point_pair_count > 0",
                 (const char *)&pBlock) )
          {
            __debugbreak();
          }
        }
        rigid_body_constraint_contact::verify_constraint(v5, v4, rb2);
        v1->m_next_link = v5->m_list_contact_point_info_buffer_1.m_first;
        v5->m_list_contact_point_info_buffer_1.m_first = v1;
      }
      v1 = next_cpi;
    }
    while ( next_cpi );
  }
}

/*
==============
process_list_do_gjk_collide_and_contact_manifold
==============
*/
void process_list_do_gjk_collide_and_contact_manifold(phys_link_list<phys_collision_pair> *list_pcd)
{
  phys_transient_allocator *v1; // eax
  char *v2; // eax

  if ( list_pcd->m_alloc_count > 0 )
  {
    g_list_pcp_iterator = list_pcd->m_first;
    g_list_output_cpi = NULL;
    v1 = contact_point_info::get_cpi_allocator();
    v2 = phys_transient_allocator::allocate(v1, 12, 4, 0, "phys_transient_allocator out of memory.");
    *((_DWORD *)v2 + 2) = &g_list_pcp_iterator;
    *((_DWORD *)v2 + 1) = g_physics_system->m_search_tree_rbc_contact.m_tree_root;
    *(_DWORD *)v2 = &g_list_output_cpi;
    phys_task_manager_process(&phys_gjk_collide_jqModule, v2, list_pcd->m_alloc_count);
    phys_task_manager_flush();
    process_cpi(g_list_output_cpi);
  }
}

/*
==============
phys_gjk_collide_jq_batch_function
==============
*/
int __usercall phys_gjk_collide_jq_batch_function@<eax>(int a1@<ebp>, jqBatch *pBatch)
{
  void *v2; // esp
  volatile signed __int32 **v3; // esi
  phys_transient_allocator *v4; // eax
  volatile signed __int32 *v5; // ecx
  volatile signed __int32 *v6; // eax
  phys_collision_pair *i; // ecx
  volatile signed __int32 v8; // edi
  signed __int32 v10; // [esp-4534h] [ebp-4540h]
  int v11; // [esp-4530h] [ebp-453Ch]
  phys_transient_allocator *v12; // [esp-44B0h] [ebp-44BCh]
  signed __int32 v13; // [esp-44ACh] [ebp-44B8h]
  volatile signed __int32 *v14; // [esp-44A8h] [ebp-44B4h]
  volatile signed __int32 *v15; // [esp-4498h] [ebp-44A4h]
  int v16; // [esp-3B0h] [ebp-3BCh]
  unsigned int v17; // [esp-4h] [ebp-10h]
  int v18; // [esp+0h] [ebp-Ch]
  int v19; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v18 = a1;
  v19 = retaddr;
  v2 = alloca(17720);
  v17 = (unsigned int)&v18 ^ __security_cookie;
  v3 = (volatile signed __int32 **)pBatch->Input;
  phys_contact_manifold_process::phys_contact_manifold_process((phys_contact_manifold_process *)&v11);
  v4 = contact_point_info::get_cpi_allocator();
  v5 = v3[1];
  v12 = v4;
  v15 = v5;
  v6 = v3[2];
  for ( i = (phys_collision_pair *)*v6; *v6; i = (phys_collision_pair *)*v6 )
  {
    if ( (phys_collision_pair *)_InterlockedCompareExchange(v6, (signed __int32)i->m_next_link, (signed __int32)i) == i )
      phys_collide_do_gjk_collide_and_contact_manifold(
        COERCE_FLOAT(&v18),
        i,
        (phys_gjk_info *)&v16,
        (phys_contact_manifold_process *)&v11);
    v6 = v3[2];
  }
  v10 = v13;
  if ( v13 )
  {
    do
      v8 = **v3;
    while ( _InterlockedCompareExchange(*v3, v10, **v3) != v8 );
    if ( !v14
      && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 263, "m_last_next_ptr", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    *v14 = v8;
  }
  return 0;
}

