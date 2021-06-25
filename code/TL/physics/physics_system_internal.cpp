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
IPN_merge
==============
*/
void IPN_merge(rigid_body *dest, rigid_body *source)
{
  rigid_body *v2; // eax

  if ( dest->m_partition_node.m_partition_head != dest
    && _tlAssert(
         "source/physics_system_internal.cpp",
         186,
         "GIPN(dest)->m_partition_head == dest",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( source->m_partition_node.m_partition_head != source
    && _tlAssert(
         "source/physics_system_internal.cpp",
         187,
         "GIPN(source)->m_partition_head == source",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( dest == source && _tlAssert("source/physics_system_internal.cpp", 188, "dest != source", (const char *)&pBlock) )
    __debugbreak();
  dest->m_partition_node.m_partition_tail->m_partition_node.m_next_node = source;
  dest->m_partition_node.m_partition_tail = source->m_partition_node.m_partition_tail;
  dest->m_partition_node.m_partition_size += source->m_partition_node.m_partition_size;
  v2 = source;
  do
  {
    v2->m_partition_node.m_partition_head = dest->m_partition_node.m_partition_head;
    v2 = v2->m_partition_node.m_next_node;
  }
  while ( v2 );
  source->m_partition_node.m_partition_tail = NULL;
  source->m_partition_node.m_partition_size = 0;
}

/*
==============
rigid_body_island_qsort
==============
*/
void rigid_body_island_qsort(rigid_body **list, const int list_count)
{
  rigid_body *v2; // ecx
  rigid_body **v3; // esi
  rigid_body **v4; // edi
  unsigned int i; // eax
  rigid_body *v6; // ecx
  int v7; // ecx
  int v8; // esi
  rigid_body **last; // [esp+4h] [ebp-4h]

  if ( list_count >= 3 )
  {
    v3 = list;
    rigid_body_island_qsort(list, list_count / 2);
    rigid_body_island_qsort(&list[list_count / 2], list_count - list_count / 2);
    v4 = &list[list_count / 2];
    last = &list[list_count];
    for ( i = (unsigned int)(v4 - 1); v4 < last; ++v4 )
    {
      v6 = *(rigid_body **)i;
      if ( (*v4)->m_partition_node.m_partition_size <= *(_DWORD *)(*(_DWORD *)i + 348) )
        break;
      *(_DWORD *)i = *v4;
      *v4 = v6;
      v7 = i - 4;
      if ( i > (unsigned int)v3 )
      {
        while ( 1 )
        {
          v8 = *(_DWORD *)v7;
          if ( *(_DWORD *)(*(_DWORD *)i + 348) <= *(_DWORD *)(*(_DWORD *)v7 + 348) )
            break;
          *(_DWORD *)v7 = *(_DWORD *)i;
          *(_DWORD *)i = v8;
          v3 = list;
          i = v7;
          v7 -= 4;
          if ( i <= (unsigned int)list )
            goto LABEL_12;
        }
        v3 = list;
      }
LABEL_12:
      i = (unsigned int)v4;
    }
  }
  else if ( list_count == 2 )
  {
    v2 = *list;
    if ( list[1]->m_partition_node.m_partition_size > (*list)->m_partition_node.m_partition_size )
    {
      *list = list[1];
      list[1] = v2;
    }
  }
}

/*
==============
IPN_verify_rigid_bodies
==============
*/
void IPN_verify_rigid_bodies(rigid_body *rb_partition_head)
{
  rigid_body_constraint_point *i; // esi
  rigid_body *v2; // eax
  unsigned int v3; // ecx
  rigid_body **v4; // eax
  rigid_body *v5; // eax
  unsigned int v6; // ecx
  rigid_body **v7; // eax
  rigid_body_constraint_hinge *j; // esi
  rigid_body *v9; // eax
  unsigned int v10; // ecx
  rigid_body **v11; // eax
  rigid_body *v12; // eax
  unsigned int v13; // ecx
  rigid_body **v14; // eax
  rigid_body_constraint_distance *k; // esi
  rigid_body *v16; // eax
  unsigned int v17; // ecx
  rigid_body **v18; // eax
  rigid_body *v19; // eax
  unsigned int v20; // ecx
  rigid_body **v21; // eax
  rigid_body_constraint_ragdoll *l; // esi
  rigid_body *v23; // eax
  unsigned int v24; // ecx
  rigid_body **v25; // eax
  rigid_body *v26; // eax
  unsigned int v27; // ecx
  rigid_body **v28; // eax
  rigid_body_constraint_wheel *m; // esi
  rigid_body *v30; // eax
  unsigned int v31; // ecx
  rigid_body **v32; // eax
  rigid_body *v33; // eax
  unsigned int v34; // ecx
  rigid_body **v35; // eax
  rigid_body_constraint_angular_actuator *n; // esi
  rigid_body *v37; // eax
  unsigned int v38; // ecx
  rigid_body **v39; // eax
  rigid_body *v40; // eax
  unsigned int v41; // ecx
  rigid_body **v42; // eax
  rigid_body_constraint_upright *ii; // esi
  rigid_body *v44; // eax
  unsigned int v45; // ecx
  rigid_body **v46; // eax
  rigid_body *v47; // eax
  unsigned int v48; // ecx
  rigid_body **v49; // eax
  rigid_body_constraint_custom_orientation *jj; // esi
  rigid_body *v51; // eax
  unsigned int v52; // ecx
  rigid_body **v53; // eax
  rigid_body *v54; // eax
  unsigned int v55; // ecx
  rigid_body **v56; // eax
  rigid_body_constraint_custom_path *kk; // esi
  rigid_body *v58; // eax
  unsigned int v59; // ecx
  rigid_body **v60; // eax
  rigid_body *v61; // eax
  unsigned int v62; // ecx
  rigid_body **v63; // eax
  rigid_body_constraint_contact *ll; // esi
  rigid_body *v65; // eax
  unsigned int v66; // ecx
  rigid_body **v67; // eax
  rigid_body *v68; // eax
  unsigned int v69; // ecx
  rigid_body **v70; // eax

  if ( rb_partition_head->m_partition_node.m_partition_head != rb_partition_head
    && _tlAssert(
         "source/physics_system_internal.cpp",
         174,
         "GIPN(rb_partition_head)->m_partition_head == rb_partition_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  for ( i = rb_partition_head->m_partition_node.m_rbc_point_first; i; i = (rigid_body_constraint_point *)i->m_next )
  {
    v2 = i->b1;
    if ( i->b1 )
    {
      v3 = v2->m_flags;
      if ( v3 & 0x10 )
      {
        if ( v2 != (rigid_body *)&g_physics_system->m_environment_rigid_body
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      else
      {
        v4 = &v2[-1].m_partition_node.m_partition_head;
        if ( v3 & 0x20 )
          PMM_VALIDATE(v4, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v4, 0x180u, 0x10u);
      }
    }
    v5 = i->b2;
    if ( v5 )
    {
      v6 = v5->m_flags;
      if ( v6 & 0x10 )
      {
        if ( v5 != (rigid_body *)&g_physics_system->m_environment_rigid_body
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      else
      {
        v7 = &v5[-1].m_partition_node.m_partition_head;
        if ( v6 & 0x20 )
          PMM_VALIDATE(v7, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v7, 0x180u, 0x10u);
      }
    }
  }
  for ( j = rb_partition_head->m_partition_node.m_rbc_hinge_first; j; j = (rigid_body_constraint_hinge *)j->m_next )
  {
    v9 = j->b1;
    if ( j->b1 )
    {
      v10 = v9->m_flags;
      if ( v10 & 0x10 )
      {
        if ( v9 != (rigid_body *)&g_physics_system->m_environment_rigid_body
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      else
      {
        v11 = &v9[-1].m_partition_node.m_partition_head;
        if ( v10 & 0x20 )
          PMM_VALIDATE(v11, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v11, 0x180u, 0x10u);
      }
    }
    v12 = j->b2;
    if ( v12 )
    {
      v13 = v12->m_flags;
      if ( v13 & 0x10 )
      {
        if ( v12 != (rigid_body *)&g_physics_system->m_environment_rigid_body
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      else
      {
        v14 = &v12[-1].m_partition_node.m_partition_head;
        if ( v13 & 0x20 )
          PMM_VALIDATE(v14, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v14, 0x180u, 0x10u);
      }
    }
  }
  for ( k = rb_partition_head->m_partition_node.m_rbc_dist_first; k; k = (rigid_body_constraint_distance *)k->m_next )
  {
    v16 = k->b1;
    if ( k->b1 )
    {
      v17 = v16->m_flags;
      if ( v17 & 0x10 )
      {
        if ( v16 != (rigid_body *)&g_physics_system->m_environment_rigid_body
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      else
      {
        v18 = &v16[-1].m_partition_node.m_partition_head;
        if ( v17 & 0x20 )
          PMM_VALIDATE(v18, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v18, 0x180u, 0x10u);
      }
    }
    v19 = k->b2;
    if ( v19 )
    {
      v20 = v19->m_flags;
      if ( v20 & 0x10 )
      {
        if ( v19 != (rigid_body *)&g_physics_system->m_environment_rigid_body
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      else
      {
        v21 = &v19[-1].m_partition_node.m_partition_head;
        if ( v20 & 0x20 )
          PMM_VALIDATE(v21, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v21, 0x180u, 0x10u);
      }
    }
  }
  for ( l = rb_partition_head->m_partition_node.m_rbc_ragdoll_first; l; l = (rigid_body_constraint_ragdoll *)l->m_next )
  {
    v23 = l->b1;
    if ( l->b1 )
    {
      v24 = v23->m_flags;
      if ( v24 & 0x10 )
      {
        if ( v23 != (rigid_body *)&g_physics_system->m_environment_rigid_body
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      else
      {
        v25 = &v23[-1].m_partition_node.m_partition_head;
        if ( v24 & 0x20 )
          PMM_VALIDATE(v25, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v25, 0x180u, 0x10u);
      }
    }
    v26 = l->b2;
    if ( v26 )
    {
      v27 = v26->m_flags;
      if ( v27 & 0x10 )
      {
        if ( v26 != (rigid_body *)&g_physics_system->m_environment_rigid_body
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      else
      {
        v28 = &v26[-1].m_partition_node.m_partition_head;
        if ( v27 & 0x20 )
          PMM_VALIDATE(v28, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v28, 0x180u, 0x10u);
      }
    }
  }
  for ( m = rb_partition_head->m_partition_node.m_rbc_wheel_first; m; m = (rigid_body_constraint_wheel *)m->m_next )
  {
    v30 = m->b1;
    if ( m->b1 )
    {
      v31 = v30->m_flags;
      if ( v31 & 0x10 )
      {
        if ( v30 != (rigid_body *)&g_physics_system->m_environment_rigid_body
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      else
      {
        v32 = &v30[-1].m_partition_node.m_partition_head;
        if ( v31 & 0x20 )
          PMM_VALIDATE(v32, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v32, 0x180u, 0x10u);
      }
    }
    v33 = m->b2;
    if ( v33 )
    {
      v34 = v33->m_flags;
      if ( v34 & 0x10 )
      {
        if ( v33 != (rigid_body *)&g_physics_system->m_environment_rigid_body
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      else
      {
        v35 = &v33[-1].m_partition_node.m_partition_head;
        if ( v34 & 0x20 )
          PMM_VALIDATE(v35, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v35, 0x180u, 0x10u);
      }
    }
  }
  for ( n = rb_partition_head->m_partition_node.m_rbc_angular_actuator_first;
        n;
        n = (rigid_body_constraint_angular_actuator *)n->m_next )
  {
    v37 = n->b1;
    if ( n->b1 )
    {
      v38 = v37->m_flags;
      if ( v38 & 0x10 )
      {
        if ( v37 != (rigid_body *)&g_physics_system->m_environment_rigid_body
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      else
      {
        v39 = &v37[-1].m_partition_node.m_partition_head;
        if ( v38 & 0x20 )
          PMM_VALIDATE(v39, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v39, 0x180u, 0x10u);
      }
    }
    v40 = n->b2;
    if ( v40 )
    {
      v41 = v40->m_flags;
      if ( v41 & 0x10 )
      {
        if ( v40 != (rigid_body *)&g_physics_system->m_environment_rigid_body
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      else
      {
        v42 = &v40[-1].m_partition_node.m_partition_head;
        if ( v41 & 0x20 )
          PMM_VALIDATE(v42, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v42, 0x180u, 0x10u);
      }
    }
  }
  for ( ii = rb_partition_head->m_partition_node.m_rbc_upright_first; ii; ii = (rigid_body_constraint_upright *)ii->m_next )
  {
    v44 = ii->b1;
    if ( ii->b1 )
    {
      v45 = v44->m_flags;
      if ( v45 & 0x10 )
      {
        if ( v44 != (rigid_body *)&g_physics_system->m_environment_rigid_body
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      else
      {
        v46 = &v44[-1].m_partition_node.m_partition_head;
        if ( v45 & 0x20 )
          PMM_VALIDATE(v46, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v46, 0x180u, 0x10u);
      }
    }
    v47 = ii->b2;
    if ( v47 )
    {
      v48 = v47->m_flags;
      if ( v48 & 0x10 )
      {
        if ( v47 != (rigid_body *)&g_physics_system->m_environment_rigid_body
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      else
      {
        v49 = &v47[-1].m_partition_node.m_partition_head;
        if ( v48 & 0x20 )
          PMM_VALIDATE(v49, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v49, 0x180u, 0x10u);
      }
    }
  }
  for ( jj = rb_partition_head->m_partition_node.m_rbc_custom_orientation_first;
        jj;
        jj = (rigid_body_constraint_custom_orientation *)jj->m_next )
  {
    v51 = jj->b1;
    if ( jj->b1 )
    {
      v52 = v51->m_flags;
      if ( v52 & 0x10 )
      {
        if ( v51 != (rigid_body *)&g_physics_system->m_environment_rigid_body
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      else
      {
        v53 = &v51[-1].m_partition_node.m_partition_head;
        if ( v52 & 0x20 )
          PMM_VALIDATE(v53, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v53, 0x180u, 0x10u);
      }
    }
    v54 = jj->b2;
    if ( v54 )
    {
      v55 = v54->m_flags;
      if ( v55 & 0x10 )
      {
        if ( v54 != (rigid_body *)&g_physics_system->m_environment_rigid_body
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      else
      {
        v56 = &v54[-1].m_partition_node.m_partition_head;
        if ( v55 & 0x20 )
          PMM_VALIDATE(v56, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v56, 0x180u, 0x10u);
      }
    }
  }
  for ( kk = rb_partition_head->m_partition_node.m_rbc_custom_path_first;
        kk;
        kk = (rigid_body_constraint_custom_path *)kk->m_next )
  {
    v58 = kk->b1;
    if ( kk->b1 )
    {
      v59 = v58->m_flags;
      if ( v59 & 0x10 )
      {
        if ( v58 != (rigid_body *)&g_physics_system->m_environment_rigid_body
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      else
      {
        v60 = &v58[-1].m_partition_node.m_partition_head;
        if ( v59 & 0x20 )
          PMM_VALIDATE(v60, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v60, 0x180u, 0x10u);
      }
    }
    v61 = kk->b2;
    if ( v61 )
    {
      v62 = v61->m_flags;
      if ( v62 & 0x10 )
      {
        if ( v61 != (rigid_body *)&g_physics_system->m_environment_rigid_body
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      else
      {
        v63 = &v61[-1].m_partition_node.m_partition_head;
        if ( v62 & 0x20 )
          PMM_VALIDATE(v63, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v63, 0x180u, 0x10u);
      }
    }
  }
  for ( ll = rb_partition_head->m_partition_node.m_rbc_contact_first; ll; ll = (rigid_body_constraint_contact *)ll->m_next )
  {
    v65 = ll->b1;
    if ( ll->b1 )
    {
      v66 = v65->m_flags;
      if ( v66 & 0x10 )
      {
        if ( v65 != (rigid_body *)&g_physics_system->m_environment_rigid_body
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      else
      {
        v67 = &v65[-1].m_partition_node.m_partition_head;
        if ( v66 & 0x20 )
          PMM_VALIDATE(v67, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v67, 0x180u, 0x10u);
      }
    }
    v68 = ll->b2;
    if ( v68 )
    {
      v69 = v68->m_flags;
      if ( v69 & 0x10 )
      {
        if ( v68 != (rigid_body *)&g_physics_system->m_environment_rigid_body )
        {
          if ( _tlAssert(
                 "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
                 73,
                 "rb == &m_environment_rigid_body",
                 (const char *)&pBlock) )
          {
            __debugbreak();
          }
        }
      }
      else
      {
        v70 = &v68[-1].m_partition_node.m_partition_head;
        if ( v69 & 0x20 )
          PMM_VALIDATE(v70, 0x1D0u, 0x10u);
        else
          PMM_VALIDATE(v70, 0x180u, 0x10u);
      }
    }
  }
}

/*
==============
physics_system::generate_partitions_and_stuff
==============
*/
void __thiscall physics_system::generate_partitions_and_stuff(physics_system *this, phys_transient_allocator *transient_buffer)
{
  physics_system *v2; // edi
  phys_free_list<user_rigid_body>::T_internal_base *v3; // eax
  phys_free_list<user_rigid_body> *v4; // ecx
  phys_free_list<rigid_body>::T_internal_base *j; // ecx
  phys_free_list<rigid_body>::T_internal_base *v6; // eax
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v7; // esi
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v8; // ecx
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v9; // ecx
  phys_free_list<rigid_body_constraint_hinge>::T_internal_base *k; // esi
  phys_free_list<rigid_body_constraint_hinge>::T_internal_base *v11; // ecx
  phys_free_list<rigid_body_constraint_hinge>::T_internal_base *v12; // ecx
  phys_free_list<rigid_body_constraint_distance>::T_internal_base *l; // esi
  phys_free_list<rigid_body_constraint_distance>::T_internal_base *v14; // ecx
  phys_free_list<rigid_body_constraint_distance>::T_internal_base *v15; // ecx
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *m; // esi
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *v17; // ecx
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *v18; // ecx
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *n; // esi
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v20; // ecx
  rigid_body_constraint *v21; // eax
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v22; // ecx
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v23; // ecx
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *ii; // esi
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *v25; // ecx
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *v26; // ecx
  phys_free_list<rigid_body_constraint_upright>::T_internal_base *jj; // esi
  phys_free_list<rigid_body_constraint_upright>::T_internal_base *v28; // ecx
  phys_free_list<rigid_body_constraint_upright>::T_internal_base *v29; // ecx
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *kk; // esi
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *v31; // ecx
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *v32; // ecx
  phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *ll; // esi
  phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *v34; // ecx
  phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *v35; // ecx
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *mm; // ebx
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v37; // eax
  int v38; // ecx
  int nn; // esi
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v40; // eax
  int i1; // edx
  phys_free_list<rigid_body>::T_internal_base *v42; // ebx
  int i2; // edi
  phys_free_list<rigid_body_constraint_point> *i3; // ebx
  rigid_body_constraint_point *v45; // eax
  float v46; // eax
  float v47; // edi
  rigid_body_constraint_point *v48; // eax
  physics_system *v49; // eax
  phys_free_list<rigid_body_constraint_hinge> *i4; // ebx
  rigid_body_constraint_hinge *v51; // eax
  float v52; // eax
  float v53; // edi
  rigid_body_constraint_hinge *v54; // eax
  phys_free_list<rigid_body_constraint_distance> *v55; // ebx
  rigid_body_constraint_distance *v56; // eax
  float v57; // eax
  float v58; // edi
  rigid_body_constraint_distance *v59; // eax
  phys_free_list<rigid_body_constraint_ragdoll> *v60; // ebx
  rigid_body_constraint_ragdoll *v61; // eax
  unsigned int v62; // eax
  unsigned int v63; // edi
  rigid_body_constraint_ragdoll *v64; // eax
  phys_free_list<rigid_body_constraint_wheel> *v65; // ebx
  rigid_body_constraint_wheel *v66; // eax
  float v67; // eax
  float v68; // edi
  rigid_body_constraint_wheel *v69; // eax
  phys_free_list<rigid_body_constraint_angular_actuator> *v70; // ebx
  rigid_body_constraint_angular_actuator *v71; // eax
  float v72; // eax
  float v73; // edi
  rigid_body_constraint_angular_actuator *v74; // eax
  phys_free_list<rigid_body_constraint_upright> *v75; // ebx
  rigid_body_constraint_upright *v76; // eax
  float v77; // eax
  float v78; // edi
  rigid_body_constraint_upright *v79; // eax
  phys_free_list<rigid_body_constraint_custom_orientation> *v80; // ebx
  int v81; // eax
  int v82; // eax
  int v83; // edi
  int v84; // eax
  phys_free_list<rigid_body_constraint_custom_path> *v85; // ebx
  rigid_body_constraint_custom_path *v86; // eax
  float v87; // eax
  float v88; // edi
  rigid_body_constraint_custom_path *v89; // eax
  phys_free_list<rigid_body_constraint_contact> *v90; // ebx
  int v91; // eax
  int v92; // eax
  int v93; // edi
  int v94; // eax
  int v95; // eax
  int v96; // edi
  unsigned int v97; // eax
  unsigned int v98; // ebx
  unsigned int v99; // eax
  char *v100; // edi
  phys_free_list<rigid_body>::T_internal_base *v101; // eax
  int v102; // ebx
  int v103; // edi
  physics_system *v104; // [esp+Ch] [ebp-4h]
  phys_free_list<rigid_body>::iterator i; // [esp+18h] [ebp+8h]

  v2 = this;
  v2->m_environment_rigid_body.m_flags &= 0xFFFFFEFF;
  this->m_environment_rigid_body.m_constraint_count = 0;
  this->m_environment_rigid_body.m_contact_count = 0;
  v3 = this->m_list_user_rigid_body.m_dummy_head.m_next_T_internal;
  v4 = &this->m_list_user_rigid_body;
  v104 = v2;
  for ( v2->m_environment_rigid_body.m_partition_node.m_partition_head = NULL;
        v4 != (phys_free_list<user_rigid_body> *)v3;
        v3 = v3->m_next_T_internal )
  {
    v3[33].m_next_T_internal = (phys_free_list<user_rigid_body>::T_internal_base *)((_DWORD)v3[33].m_next_T_internal & 0xFFFFFEFF);
    v3[35].m_prev_T_internal = NULL;
    v3[35].m_next_T_internal = NULL;
    v3[44].m_prev_T_internal = NULL;
  }
  for ( j = v2->m_list_rigid_body.m_dummy_head.m_next_T_internal;
        &v2->m_list_rigid_body != (phys_free_list<rigid_body> *)j;
        j = j->m_next_T_internal )
  {
    j[33].m_next_T_internal = (phys_free_list<rigid_body>::T_internal_base *)((_DWORD)j[33].m_next_T_internal & 0xFFFFFEFF);
    v6 = j + 2;
    v6[33].m_prev_T_internal = NULL;
    v6[33].m_next_T_internal = NULL;
    v6[42].m_prev_T_internal = v6;
    v6[42].m_next_T_internal = v6;
    v6[43].m_prev_T_internal = NULL;
    v6[43].m_next_T_internal = (phys_free_list<rigid_body>::T_internal_base *)1;
  }
  v7 = v2->m_list_rbc_point.m_dummy_head.m_next_T_internal;
  for ( v2->m_list_island_count = v2->m_list_rigid_body.m_list_count;
        &v2->m_list_rbc_point != (phys_free_list<rigid_body_constraint_point> *)v7;
        v7 = v7->m_next_T_internal )
  {
    v8 = v7[2].m_prev_T_internal;
    if ( v8 )
      ++v8[33].m_prev_T_internal;
    v9 = v7[2].m_next_T_internal;
    if ( v9 )
      ++v9[33].m_prev_T_internal;
    IPN_partition_process((rigid_body_constraint *)&v7[2], &v2->m_list_island_count);
  }
  for ( k = v2->m_list_rbc_hinge.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_hinge != (phys_free_list<rigid_body_constraint_hinge> *)k;
        k = k->m_next_T_internal )
  {
    v11 = k[2].m_prev_T_internal;
    if ( v11 )
      ++v11[33].m_prev_T_internal;
    v12 = k[2].m_next_T_internal;
    if ( v12 )
      ++v12[33].m_prev_T_internal;
    IPN_partition_process((rigid_body_constraint *)&k[2], &v2->m_list_island_count);
  }
  for ( l = v2->m_list_rbc_dist.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_dist != (phys_free_list<rigid_body_constraint_distance> *)l;
        l = l->m_next_T_internal )
  {
    v14 = l[2].m_prev_T_internal;
    if ( v14 )
      ++v14[33].m_prev_T_internal;
    v15 = l[2].m_next_T_internal;
    if ( v15 )
      ++v15[33].m_prev_T_internal;
    IPN_partition_process((rigid_body_constraint *)&l[2], &v2->m_list_island_count);
  }
  for ( m = v2->m_list_rbc_ragdoll.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_ragdoll != (phys_free_list<rigid_body_constraint_ragdoll> *)m;
        m = m->m_next_T_internal )
  {
    v17 = m[2].m_prev_T_internal;
    if ( v17 )
      ++v17[33].m_prev_T_internal;
    v18 = m[2].m_next_T_internal;
    if ( v18 )
      ++v18[33].m_prev_T_internal;
    IPN_partition_process((rigid_body_constraint *)&m[2], &v2->m_list_island_count);
  }
  for ( n = v2->m_list_rbc_wheel.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_wheel != (phys_free_list<rigid_body_constraint_wheel> *)n;
        n = n->m_next_T_internal )
  {
    v20 = n[2].m_prev_T_internal;
    v21 = (rigid_body_constraint *)&n[2];
    if ( v20 )
      ++v20[33].m_prev_T_internal;
    v22 = n[2].m_next_T_internal;
    if ( v22 )
      ++v22[33].m_prev_T_internal;
    if ( (_DWORD)n[24].m_prev_T_internal & 1 )
    {
      if ( v21->b1 )
        ++v21->b1->m_contact_count;
      v23 = n[2].m_next_T_internal;
      if ( v23 )
        ++v23[33].m_next_T_internal;
    }
    IPN_partition_process(v21, &v2->m_list_island_count);
  }
  for ( ii = v2->m_list_rbc_angular_actuator.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_angular_actuator != (phys_free_list<rigid_body_constraint_angular_actuator> *)ii;
        ii = ii->m_next_T_internal )
  {
    v25 = ii[2].m_prev_T_internal;
    if ( v25 )
      ++v25[33].m_prev_T_internal;
    v26 = ii[2].m_next_T_internal;
    if ( v26 )
      ++v26[33].m_prev_T_internal;
    IPN_partition_process((rigid_body_constraint *)&ii[2], &v2->m_list_island_count);
  }
  for ( jj = v2->m_list_rbc_upright.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_upright != (phys_free_list<rigid_body_constraint_upright> *)jj;
        jj = jj->m_next_T_internal )
  {
    v28 = jj[2].m_prev_T_internal;
    if ( v28 )
      ++v28[33].m_prev_T_internal;
    v29 = jj[2].m_next_T_internal;
    if ( v29 )
      ++v29[33].m_prev_T_internal;
    IPN_partition_process((rigid_body_constraint *)&jj[2], &v2->m_list_island_count);
  }
  for ( kk = v2->m_list_rbc_custom_orientation.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_custom_orientation != (phys_free_list<rigid_body_constraint_custom_orientation> *)kk;
        kk = kk->m_next_T_internal )
  {
    v31 = kk[1].m_prev_T_internal;
    if ( v31 )
      ++v31[33].m_prev_T_internal;
    v32 = kk[1].m_next_T_internal;
    if ( v32 )
      ++v32[33].m_prev_T_internal;
    IPN_partition_process((rigid_body_constraint *)&kk[1], &v2->m_list_island_count);
  }
  for ( ll = v2->m_list_rbc_custom_path.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_custom_path != (phys_free_list<rigid_body_constraint_custom_path> *)ll;
        ll = ll->m_next_T_internal )
  {
    v34 = ll[2].m_prev_T_internal;
    if ( v34 )
      ++v34[33].m_prev_T_internal;
    v35 = ll[2].m_next_T_internal;
    if ( v35 )
      ++v35[33].m_prev_T_internal;
    IPN_partition_process((rigid_body_constraint *)&ll[2], &v2->m_list_island_count);
  }
  for ( mm = v2->m_list_rbc_contact.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_contact != (phys_free_list<rigid_body_constraint_contact> *)mm;
        mm = mm->m_next_T_internal )
  {
    v37 = mm[2].m_next_T_internal;
    v38 = (int)&mm[1];
    for ( nn = 0; v37; v37 = v37[6].m_prev_T_internal )
      nn += (int)v37[4].m_prev_T_internal;
    v40 = mm[3].m_prev_T_internal;
    for ( i1 = 0; v40; v40 = v40[6].m_prev_T_internal )
      i1 += (int)v40[4].m_prev_T_internal;
    if ( i1 <= nn )
      i1 = nn;
    if ( *(_DWORD *)v38 )
    {
      *(_DWORD *)(*(_DWORD *)v38 + 268) += i1;
      *(_DWORD *)(*(_DWORD *)v38 + 252) |= 0x100u;
    }
    if ( mm[1].m_next_T_internal )
    {
      mm[1].m_next_T_internal[33].m_next_T_internal = (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)((char *)mm[1].m_next_T_internal[33].m_next_T_internal + i1);
      mm[1].m_next_T_internal[31].m_next_T_internal = (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)((_DWORD)mm[1].m_next_T_internal[31].m_next_T_internal | 0x100);
    }
    IPN_partition_process((rigid_body_constraint *)&mm[1], &v2->m_list_island_count);
  }
  v42 = v2->m_list_rigid_body.m_dummy_head.m_next_T_internal;
  for ( i2 = (int)&v2->m_list_rigid_body;
        (phys_free_list<rigid_body>::T_internal_base *)i2 != v42;
        v42 = v42->m_next_T_internal )
  {
    if ( (_DWORD)v42[45].m_next_T_internal > 0 )
    {
      if ( v42[44].m_prev_T_internal != &v42[2]
        && _tlAssert(
             "source/physics_system_internal.cpp",
             141,
             "GIPN(rb_partition_head)->m_partition_head == rb_partition_head",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v42[39].m_prev_T_internal = NULL;
      v42[39].m_next_T_internal = NULL;
      v42[40].m_prev_T_internal = NULL;
      v42[40].m_next_T_internal = NULL;
      v42[41].m_prev_T_internal = NULL;
      v42[41].m_next_T_internal = NULL;
      v42[42].m_prev_T_internal = NULL;
      v42[42].m_next_T_internal = NULL;
      v42[43].m_prev_T_internal = NULL;
      v42[43].m_next_T_internal = NULL;
    }
  }
  for ( i3 = (phys_free_list<rigid_body_constraint_point> *)v104->m_list_rbc_point.m_dummy_head.m_next_T_internal;
        &v104->m_list_rbc_point != i3;
        i3 = (phys_free_list<rigid_body_constraint_point> *)i3->m_dummy_head.m_next_T_internal )
  {
    v45 = i3->m_ptr_list[0];
    if ( v45 && (v46 = v45[4].m_b1_r_loc.x, v46 != 0.0) )
    {
      v47 = v46;
    }
    else
    {
      v48 = i3->m_ptr_list[1];
      if ( (!v48 || !LODWORD(v48[4].m_b1_r_loc.x))
        && _tlAssert(
             "source/physics_system_internal.cpp",
             229,
             "rbc.get_b2() && GIPN(rbc.get_b2())->m_partition_head",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v47 = i3->m_ptr_list[1][4].m_b1_r_loc.x;
    }
    if ( *(_DWORD *)(LODWORD(v47) + 336) != LODWORD(v47)
      && _tlAssert(
           "source/physics_system_internal.cpp",
           163,
           "GIPN(rb_partition_head)->m_partition_head == rb_partition_head",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    i3->m_ptr_list[2] = *(rigid_body_constraint_point **)(LODWORD(v47) + 296);
    *(_DWORD *)(LODWORD(v47) + 296) = (char *)i3 + 16;
  }
  v49 = v104;
  for ( i4 = (phys_free_list<rigid_body_constraint_hinge> *)v104->m_list_rbc_hinge.m_dummy_head.m_next_T_internal;
        &v104->m_list_rbc_hinge != i4;
        i4 = (phys_free_list<rigid_body_constraint_hinge> *)i4->m_dummy_head.m_next_T_internal )
  {
    v51 = i4->m_ptr_list[0];
    if ( v51 && (v52 = v51[1].m_b2_ref_min_loc.x, v52 != 0.0) )
    {
      v53 = v52;
    }
    else
    {
      v54 = i4->m_ptr_list[1];
      if ( (!v54 || !LODWORD(v54[1].m_b2_ref_min_loc.x))
        && _tlAssert(
             "source/physics_system_internal.cpp",
             229,
             "rbc.get_b2() && GIPN(rbc.get_b2())->m_partition_head",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v53 = i4->m_ptr_list[1][1].m_b2_ref_min_loc.x;
    }
    if ( *(_DWORD *)(LODWORD(v53) + 336) != LODWORD(v53)
      && _tlAssert(
           "source/physics_system_internal.cpp",
           163,
           "GIPN(rb_partition_head)->m_partition_head == rb_partition_head",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v49 = v104;
    i4->m_ptr_list[2] = *(rigid_body_constraint_hinge **)(LODWORD(v53) + 300);
    *(_DWORD *)(LODWORD(v53) + 300) = (char *)i4 + 16;
  }
  v55 = (phys_free_list<rigid_body_constraint_distance> *)v49->m_list_rbc_dist.m_dummy_head.m_next_T_internal;
  if ( &v49->m_list_rbc_dist != v55 )
  {
    do
    {
      v56 = v55->m_ptr_list[0];
      if ( v56 && (v57 = v56[3].m_min_distance, v57 != 0.0) )
      {
        v58 = v57;
      }
      else
      {
        v59 = v55->m_ptr_list[1];
        if ( (!v59 || !LODWORD(v59[3].m_min_distance))
          && _tlAssert(
               "source/physics_system_internal.cpp",
               229,
               "rbc.get_b2() && GIPN(rbc.get_b2())->m_partition_head",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v58 = v55->m_ptr_list[1][3].m_min_distance;
      }
      if ( *(_DWORD *)(LODWORD(v58) + 336) != LODWORD(v58)
        && _tlAssert(
             "source/physics_system_internal.cpp",
             163,
             "GIPN(rb_partition_head)->m_partition_head == rb_partition_head",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v55->m_ptr_list[2] = *(rigid_body_constraint_distance **)(LODWORD(v58) + 304);
      v49 = v104;
      *(_DWORD *)(LODWORD(v58) + 304) = (char *)v55 + 16;
      v55 = (phys_free_list<rigid_body_constraint_distance> *)v55->m_dummy_head.m_next_T_internal;
    }
    while ( &v104->m_list_rbc_dist != v55 );
  }
  v60 = (phys_free_list<rigid_body_constraint_ragdoll> *)v49->m_list_rbc_ragdoll.m_dummy_head.m_next_T_internal;
  if ( &v49->m_list_rbc_ragdoll != v60 )
  {
    do
    {
      v61 = v60->m_ptr_list[0];
      if ( v61 && (v62 = v61[1].m_flags) != 0 )
      {
        v63 = v62;
      }
      else
      {
        v64 = v60->m_ptr_list[1];
        if ( (!v64 || !v64[1].m_flags)
          && _tlAssert(
               "source/physics_system_internal.cpp",
               229,
               "rbc.get_b2() && GIPN(rbc.get_b2())->m_partition_head",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v63 = v60->m_ptr_list[1][1].m_flags;
      }
      if ( *(_DWORD *)(v63 + 336) != v63
        && _tlAssert(
             "source/physics_system_internal.cpp",
             163,
             "GIPN(rb_partition_head)->m_partition_head == rb_partition_head",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v49 = v104;
      v60->m_ptr_list[2] = *(rigid_body_constraint_ragdoll **)(v63 + 308);
      *(_DWORD *)(v63 + 308) = (char *)v60 + 16;
      v60 = (phys_free_list<rigid_body_constraint_ragdoll> *)v60->m_dummy_head.m_next_T_internal;
    }
    while ( &v104->m_list_rbc_ragdoll != v60 );
  }
  v65 = (phys_free_list<rigid_body_constraint_wheel> *)v49->m_list_rbc_wheel.m_dummy_head.m_next_T_internal;
  if ( &v49->m_list_rbc_wheel != v65 )
  {
    do
    {
      v66 = v65->m_ptr_list[0];
      if ( v66 && (v67 = v66[1].m_pitch_stability_factor, v67 != 0.0) )
      {
        v68 = v67;
      }
      else
      {
        v69 = v65->m_ptr_list[1];
        if ( (!v69 || !LODWORD(v69[1].m_pitch_stability_factor))
          && _tlAssert(
               "source/physics_system_internal.cpp",
               229,
               "rbc.get_b2() && GIPN(rbc.get_b2())->m_partition_head",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v68 = v65->m_ptr_list[1][1].m_pitch_stability_factor;
      }
      if ( *(_DWORD *)(LODWORD(v68) + 336) != LODWORD(v68)
        && _tlAssert(
             "source/physics_system_internal.cpp",
             163,
             "GIPN(rb_partition_head)->m_partition_head == rb_partition_head",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v49 = v104;
      v65->m_ptr_list[2] = *(rigid_body_constraint_wheel **)(LODWORD(v68) + 312);
      *(_DWORD *)(LODWORD(v68) + 312) = (char *)v65 + 16;
      v65 = (phys_free_list<rigid_body_constraint_wheel> *)v65->m_dummy_head.m_next_T_internal;
    }
    while ( &v104->m_list_rbc_wheel != v65 );
  }
  v70 = (phys_free_list<rigid_body_constraint_angular_actuator> *)v49->m_list_rbc_angular_actuator.m_dummy_head.m_next_T_internal;
  if ( &v49->m_list_rbc_angular_actuator != v70 )
  {
    do
    {
      v71 = v70->m_ptr_list[0];
      if ( v71 && (v72 = v71[1].m_a_vel.x, v72 != 0.0) )
      {
        v73 = v72;
      }
      else
      {
        v74 = v70->m_ptr_list[1];
        if ( (!v74 || !LODWORD(v74[1].m_a_vel.x))
          && _tlAssert(
               "source/physics_system_internal.cpp",
               229,
               "rbc.get_b2() && GIPN(rbc.get_b2())->m_partition_head",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v73 = v70->m_ptr_list[1][1].m_a_vel.x;
      }
      if ( *(_DWORD *)(LODWORD(v73) + 336) != LODWORD(v73)
        && _tlAssert(
             "source/physics_system_internal.cpp",
             163,
             "GIPN(rb_partition_head)->m_partition_head == rb_partition_head",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v70->m_ptr_list[2] = *(rigid_body_constraint_angular_actuator **)(LODWORD(v73) + 316);
      v49 = v104;
      *(_DWORD *)(LODWORD(v73) + 316) = (char *)v70 + 16;
      v70 = (phys_free_list<rigid_body_constraint_angular_actuator> *)v70->m_dummy_head.m_next_T_internal;
    }
    while ( &v104->m_list_rbc_angular_actuator != v70 );
  }
  v75 = (phys_free_list<rigid_body_constraint_upright> *)v49->m_list_rbc_upright.m_dummy_head.m_next_T_internal;
  if ( &v49->m_list_rbc_upright != v75 )
  {
    do
    {
      v76 = v75->m_ptr_list[0];
      if ( v76 && (v77 = v76[1].m_ps_cache_list[0].m_pulse_sum, v77 != 0.0) )
      {
        v78 = v77;
      }
      else
      {
        v79 = v75->m_ptr_list[1];
        if ( (!v79 || !LODWORD(v79[1].m_ps_cache_list[0].m_pulse_sum))
          && _tlAssert(
               "source/physics_system_internal.cpp",
               229,
               "rbc.get_b2() && GIPN(rbc.get_b2())->m_partition_head",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v78 = v75->m_ptr_list[1][1].m_ps_cache_list[0].m_pulse_sum;
      }
      if ( *(_DWORD *)(LODWORD(v78) + 336) != LODWORD(v78)
        && _tlAssert(
             "source/physics_system_internal.cpp",
             163,
             "GIPN(rb_partition_head)->m_partition_head == rb_partition_head",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v49 = v104;
      v75->m_ptr_list[2] = *(rigid_body_constraint_upright **)(LODWORD(v78) + 320);
      *(_DWORD *)(LODWORD(v78) + 320) = (char *)v75 + 16;
      v75 = (phys_free_list<rigid_body_constraint_upright> *)v75->m_dummy_head.m_next_T_internal;
    }
    while ( &v104->m_list_rbc_upright != v75 );
  }
  v80 = (phys_free_list<rigid_body_constraint_custom_orientation> *)v49->m_list_rbc_custom_orientation.m_dummy_head.m_next_T_internal;
  if ( &v49->m_list_rbc_custom_orientation != v80 )
  {
    do
    {
      v81 = v80->m_list_count;
      if ( v81 && (v82 = *(_DWORD *)(v81 + 336)) != 0 )
      {
        v83 = v82;
      }
      else
      {
        v84 = v80->m_list_count_high_water;
        if ( (!v84 || !*(_DWORD *)(v84 + 336))
          && _tlAssert(
               "source/physics_system_internal.cpp",
               229,
               "rbc.get_b2() && GIPN(rbc.get_b2())->m_partition_head",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v83 = *(_DWORD *)(v80->m_list_count_high_water + 336);
      }
      if ( *(_DWORD *)(v83 + 336) != v83
        && _tlAssert(
             "source/physics_system_internal.cpp",
             163,
             "GIPN(rb_partition_head)->m_partition_head == rb_partition_head",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v49 = v104;
      v80->m_ptr_list[0] = *(rigid_body_constraint_custom_orientation **)(v83 + 324);
      *(_DWORD *)(v83 + 324) = (char *)v80 + 8;
      v80 = (phys_free_list<rigid_body_constraint_custom_orientation> *)v80->m_dummy_head.m_next_T_internal;
    }
    while ( &v104->m_list_rbc_custom_orientation != v80 );
  }
  v85 = (phys_free_list<rigid_body_constraint_custom_path> *)v49->m_list_rbc_custom_path.m_dummy_head.m_next_T_internal;
  if ( &v49->m_list_rbc_custom_path != v85 )
  {
    do
    {
      v86 = v85->m_ptr_list[0];
      if ( v86 && (v87 = v86[2].b1_r_loc.x, v87 != 0.0) )
      {
        v88 = v87;
      }
      else
      {
        v89 = v85->m_ptr_list[1];
        if ( (!v89 || !LODWORD(v89[2].b1_r_loc.x))
          && _tlAssert(
               "source/physics_system_internal.cpp",
               229,
               "rbc.get_b2() && GIPN(rbc.get_b2())->m_partition_head",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v88 = v85->m_ptr_list[1][2].b1_r_loc.x;
      }
      if ( *(_DWORD *)(LODWORD(v88) + 336) != LODWORD(v88)
        && _tlAssert(
             "source/physics_system_internal.cpp",
             163,
             "GIPN(rb_partition_head)->m_partition_head == rb_partition_head",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v85->m_ptr_list[2] = *(rigid_body_constraint_custom_path **)(LODWORD(v88) + 328);
      v49 = v104;
      *(_DWORD *)(LODWORD(v88) + 328) = (char *)v85 + 16;
      v85 = (phys_free_list<rigid_body_constraint_custom_path> *)v85->m_dummy_head.m_next_T_internal;
    }
    while ( &v104->m_list_rbc_custom_path != v85 );
  }
  v90 = (phys_free_list<rigid_body_constraint_contact> *)v49->m_list_rbc_contact.m_dummy_head.m_next_T_internal;
  if ( &v49->m_list_rbc_contact != v90 )
  {
    do
    {
      v91 = v90->m_list_count;
      if ( v91 && (v92 = *(_DWORD *)(v91 + 336)) != 0 )
      {
        v93 = v92;
      }
      else
      {
        v94 = v90->m_list_count_high_water;
        if ( (!v94 || !*(_DWORD *)(v94 + 336))
          && _tlAssert(
               "source/physics_system_internal.cpp",
               229,
               "rbc.get_b2() && GIPN(rbc.get_b2())->m_partition_head",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v93 = *(_DWORD *)(v90->m_list_count_high_water + 336);
      }
      if ( *(_DWORD *)(v93 + 336) != v93
        && _tlAssert(
             "source/physics_system_internal.cpp",
             163,
             "GIPN(rb_partition_head)->m_partition_head == rb_partition_head",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v90->m_ptr_list[0] = *(rigid_body_constraint_contact **)(v93 + 332);
      *(_DWORD *)(v93 + 332) = (char *)v90 + 8;
      v90 = (phys_free_list<rigid_body_constraint_contact> *)v90->m_dummy_head.m_next_T_internal;
    }
    while ( &v104->m_list_rbc_contact != v90 );
  }
  if ( transient_buffer->m_cur
    && _tlAssert("source/physics_system_internal.cpp", 300, "transient_buffer->is_empty()", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v95 = v104->m_list_island_count;
  if ( v95 <= 0 )
  {
    v104->m_list_island = NULL;
    return;
  }
  v96 = 4 * v95;
  transient_allocator_update_largest_size(4 * v95);
  v97 = (_DWORD)(transient_buffer->m_cur + 3) & 0xFFFFFFFC;
  if ( (char *)(v97 + v96) > transient_buffer->m_end
    || (transient_buffer->m_cur = (char *)(v97 + v96), (v98 = v97) == 0) )
  {
    phys_transient_allocator::resize(transient_buffer);
    v99 = (_DWORD)(transient_buffer->m_cur + 3) & 0xFFFFFFFC;
    v100 = (char *)(v99 + v96);
    if ( v100 > transient_buffer->m_end )
    {
      v98 = 0;
LABEL_222:
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_transient_allocator.h",
             79,
             "ptr",
             "transient allocation too large, increase block_size.") )
      {
        __debugbreak();
      }
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_transient_allocator.h",
             81,
             "ptr || no_error",
             "phys_transient_allocator out of memory.") )
      {
        __debugbreak();
      }
      goto LABEL_226;
    }
    transient_buffer->m_cur = v100;
    v98 = v99;
    if ( !v99 )
      goto LABEL_222;
  }
LABEL_226:
  v101 = v104->m_list_rigid_body.m_dummy_head.m_next_T_internal;
  v104->m_list_island = (rigid_body **)v98;
  v102 = 0;
  for ( i.m_ptr = v101; &v104->m_list_rigid_body != (phys_free_list<rigid_body> *)v101; i.m_ptr = v101 )
  {
    v103 = (int)&v101[2];
    if ( (_DWORD)v101[45].m_next_T_internal > 0 )
    {
      IPN_verify_rigid_bodies((rigid_body *)&v101[2]);
      if ( v102 >= v104->m_list_island_count
        && _tlAssert(
             "source/physics_system_internal.cpp",
             314,
             "list_island_cur < m_list_island_count",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v104->m_list_island[v102] = (rigid_body *)v103;
      v101 = i.m_ptr;
      ++v102;
    }
    v101 = v101->m_next_T_internal;
  }
  if ( v102 != v104->m_list_island_count )
  {
    if ( _tlAssert(
           "source/physics_system_internal.cpp",
           319,
           "list_island_cur == m_list_island_count",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
  rigid_body_island_qsort(v104->m_list_island, v104->m_list_island_count);
}

/*
==============
physics_system::time_step
==============
*/
void __thiscall physics_system::time_step(physics_system *this, const float outside_delta_t, const bool last_step)
{
  physics_system *v3; // esi
  phys_free_list<rigid_body>::T_internal_base *v4; // edi
  phys_free_list<rigid_body> *v5; // ebx
  phys_free_list<user_rigid_body>::T_internal_base *i; // edi
  void (*v7)(void); // eax
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v8; // ebx
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v9; // eax
  int v10; // edx
  int v11; // ecx
  phys_free_list<rigid_body_constraint_contact>::T_internal *v12; // edi
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v13; // ecx
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v14; // eax
  phys_free_list<user_rigid_body>::T_internal_base *v15; // edi
  int v16; // ebx
  int v17; // eax
  phys_transient_allocator::block_header *v18; // eax
  char *v19; // ecx
  char *v20; // edx
  unsigned int temp_buffer_12; // ST2C_4
  volatile unsigned int temp_buffer_16; // ST30_4
  void *temp_buffer_20; // ST34_4
  void *v24; // ebx
  phys_transient_allocator transient_buffer; // [esp+2Ch] [ebp-24h]
  int v26; // [esp+4Ch] [ebp-4h]

  v3 = this;
  v4 = this->m_list_rigid_body.m_dummy_head.m_next_T_internal;
  v3->m_flags |= 1u;
  this->m_outside_sub_delta_t = outside_delta_t;
  v5 = &this->m_list_rigid_body;
  if ( &this->m_list_rigid_body != (phys_free_list<rigid_body> *)v4 )
  {
    do
    {
      rbint::collision_prolog((rigid_body *const )&v4[2], outside_delta_t);
      v4 = v4->m_next_T_internal;
    }
    while ( v5 != (phys_free_list<rigid_body> *)v4 );
  }
  for ( i = v3->m_list_user_rigid_body.m_dummy_head.m_next_T_internal;
        &v3->m_list_user_rigid_body != (phys_free_list<user_rigid_body> *)i;
        i = i->m_next_T_internal )
  {
    rbint::collision_prolog((user_rigid_body *)&i[2], outside_delta_t);
  }
  v7 = (void (*)(void))v3->m_collision_callback;
  if ( v7 )
    v7();
  v8 = v3->m_list_rbc_contact.m_dummy_head.m_next_T_internal;
  v3->m_flags &= 0xFFFFFFFE;
  while ( &v3->m_list_rbc_contact != (phys_free_list<rigid_body_constraint_contact> *)v8 )
  {
    v9 = v8[2].m_next_T_internal;
    v10 = (int)&v8[1];
    v11 = 0;
    if ( !v9 )
      goto LABEL_39;
    do
    {
      v11 += (int)v9[4].m_prev_T_internal;
      v9 = v9[6].m_prev_T_internal;
    }
    while ( v9 );
    if ( v11 )
    {
      v8 = v8->m_next_T_internal;
    }
    else
    {
LABEL_39:
      v8 = v8->m_next_T_internal;
      v12 = (phys_free_list<rigid_body_constraint_contact>::T_internal *)(v10 - 8);
      PMM_VALIDATE((void *)(v10 - 8), 0x38u, 4u);
      if ( !v12 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
        __debugbreak();
      --v3->m_list_rbc_contact.m_list_count;
      phys_free_list<rigid_body_constraint_contact>::debug_remove(&v3->m_list_rbc_contact, v12);
      v13 = v12->m_prev_T_internal;
      v14 = v12->m_next_T_internal;
      v13->m_next_T_internal = v14;
      v14->m_prev_T_internal = v13;
      rigid_body_constraint_contact::~rigid_body_constraint_contact(&v12->m_data);
      PMM_FREE(v12, 0x38u, 4u);
    }
  }
  transient_buffer.m_first_block = NULL;
  transient_buffer.m_cur = NULL;
  transient_buffer.m_end = NULL;
  transient_buffer.m_total_memory_allocated = 0;
  transient_buffer.m_mutex.m_count = 1;
  transient_buffer.m_slot_pool = NULL;
  v26 = 0;
  physics_system::solver_priority_sort(v3, &transient_buffer);
  physics_system::generate_partitions_and_stuff(v3, &transient_buffer);
  if ( tlScratchpadLocked
    && _tlAssert(
         "c:\\t6\\code\\tl\\base\\include\\tl_system.h",
         215,
         "!tlScratchpadLocked",
         "Scratchpad is already locked!") )
  {
    __debugbreak();
  }
  tlScratchpadLocked = 1;
  constraint_solver_process(&transient_buffer, v3, outside_delta_t);
  if ( !tlScratchpadLocked
    && _tlAssert(
         "c:\\t6\\code\\tl\\base\\include\\tl_system.h",
         221,
         "tlScratchpadLocked",
         "Scratchpad is already unlocked!") )
  {
    __debugbreak();
  }
  tlScratchpadLocked = 0;
  phys_transient_allocator::reset(&transient_buffer);
  v3->m_list_island = NULL;
  v3->m_list_island_count = 0;
  v15 = v3->m_list_user_rigid_body.m_dummy_head.m_next_T_internal;
  v16 = (int)&v3->m_list_user_rigid_body;
  if ( last_step )
  {
    for ( ; (phys_free_list<user_rigid_body>::T_internal_base *)v16 != v15; v15 = v15->m_next_T_internal )
      rbint::take_last_step((user_rigid_body *)&v15[2]);
  }
  else
  {
    for ( ; (phys_free_list<user_rigid_body>::T_internal_base *)v16 != v15; v15 = v15->m_next_T_internal )
      rbint::take_next_step((user_rigid_body *)&v15[2], outside_delta_t);
  }
  v17 = v3->m_contact_point_buffer_1.m_total_memory_allocated;
  if ( v3->m_contact_point_buffer_high_water > v17 )
    v17 = v3->m_contact_point_buffer_high_water;
  v3->m_contact_point_buffer_high_water = v17;
  phys_transient_allocator::reset(&v3->m_contact_point_buffer_2);
  v18 = v3->m_contact_point_buffer_2.m_first_block;
  v19 = v3->m_contact_point_buffer_2.m_cur;
  v20 = v3->m_contact_point_buffer_2.m_end;
  temp_buffer_12 = v3->m_contact_point_buffer_2.m_total_memory_allocated;
  temp_buffer_16 = v3->m_contact_point_buffer_2.m_mutex.m_count;
  temp_buffer_20 = v3->m_contact_point_buffer_2.m_slot_pool;
  v3->m_contact_point_buffer_2.m_first_block = v3->m_contact_point_buffer_1.m_first_block;
  v3->m_contact_point_buffer_2.m_cur = v3->m_contact_point_buffer_1.m_cur;
  v3->m_contact_point_buffer_2.m_end = v3->m_contact_point_buffer_1.m_end;
  v3->m_contact_point_buffer_2.m_total_memory_allocated = v3->m_contact_point_buffer_1.m_total_memory_allocated;
  v3->m_contact_point_buffer_2.m_mutex.m_count = v3->m_contact_point_buffer_1.m_mutex.m_count;
  v24 = v3->m_contact_point_buffer_1.m_slot_pool;
  v3->m_contact_point_buffer_1.m_first_block = v18;
  v3->m_contact_point_buffer_1.m_cur = v19;
  v3->m_contact_point_buffer_1.m_end = v20;
  v3->m_contact_point_buffer_1.m_total_memory_allocated = temp_buffer_12;
  v3->m_contact_point_buffer_1.m_mutex.m_count = temp_buffer_16;
  v3->m_contact_point_buffer_2.m_slot_pool = v24;
  v3->m_contact_point_buffer_1.m_slot_pool = temp_buffer_20;
  if ( v18
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_transient_allocator.h",
         69,
         "m_first_block == NULL",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v26 = -1;
  if ( transient_buffer.m_first_block )
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

/*
==============
physics_system::frame_advance
==============
*/
void __thiscall physics_system::frame_advance(physics_system *this, const float delta_t)
{
  physics_system *v2; // esi
  float v3; // ST18_4
  float sub_delta_t; // ST14_4
  phys_free_list<user_rigid_body>::T_internal_base *i; // edi
  float outside_delta_t; // ST14_4
  phys_free_list<rigid_body_constraint_point>::T_internal_base *j; // eax
  phys_free_list<rigid_body_constraint_hinge>::T_internal_base *k; // eax
  phys_free_list<rigid_body_constraint_distance>::T_internal_base *l; // edi
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *m; // eax
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *n; // eax
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *ii; // edi
  phys_free_list<rigid_body_constraint_upright>::T_internal_base *jj; // eax
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *kk; // eax
  phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *ll; // eax
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v16; // eax
  int mm; // edx
  int v18; // eax
  int v19; // edi
  phys_free_list<rigid_body_constraint_point>::T_internal_base *nn; // eax
  phys_free_list<rigid_body_constraint_hinge>::T_internal_base *i1; // eax
  phys_free_list<rigid_body_constraint_distance>::T_internal_base *v22; // edi
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *i2; // eax
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *i3; // eax
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *v25; // edi
  phys_free_list<rigid_body_constraint_upright>::T_internal_base *i4; // eax
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *i5; // eax
  phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *i6; // eax
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *i7; // esi
  float v30; // [esp+18h] [ebp-8h]
  int sub_count; // [esp+1Ch] [ebp-4h]

  v2 = this;
  phys_assert_info_frame_advance_all();
  sub_count = (signed int)(delta_t / v2->m_max_delta_t);
  v3 = (double)sub_count * v2->m_max_delta_t;
  if ( v3 < (double)delta_t )
    ++sub_count;
  v30 = (double)sub_count;
  sub_delta_t = v30 * v2->m_max_delta_t;
  if ( sub_delta_t < (double)delta_t
    && _tlAssert(
         "source/physics_system_internal.cpp",
         367,
         "delta_t <= m_max_delta_t * sub_count",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  for ( i = v2->m_list_user_rigid_body.m_dummy_head.m_next_T_internal;
        &v2->m_list_user_rigid_body != (phys_free_list<user_rigid_body> *)i;
        i = i->m_next_T_internal )
  {
    rbint::prolog_frame_advance((user_rigid_body *)&i[2], delta_t);
  }
  for ( j = v2->m_list_rbc_point.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_point != (phys_free_list<rigid_body_constraint_point> *)j;
        j = j->m_next_T_internal )
  {
    ;
  }
  for ( k = v2->m_list_rbc_hinge.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_hinge != (phys_free_list<rigid_body_constraint_hinge> *)k;
        k = k->m_next_T_internal )
  {
    ;
  }
  for ( l = v2->m_list_rbc_dist.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_dist != (phys_free_list<rigid_body_constraint_distance> *)l;
        l = l->m_next_T_internal )
  {
    rigid_body_constraint_distance::outer_prolog_update((rigid_body_constraint_distance *)&l[2], delta_t);
  }
  for ( m = v2->m_list_rbc_ragdoll.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_ragdoll != (phys_free_list<rigid_body_constraint_ragdoll> *)m;
        m = m->m_next_T_internal )
  {
    ;
  }
  for ( n = v2->m_list_rbc_wheel.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_wheel != (phys_free_list<rigid_body_constraint_wheel> *)n;
        n = n->m_next_T_internal )
  {
    ;
  }
  for ( ii = v2->m_list_rbc_angular_actuator.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_angular_actuator != (phys_free_list<rigid_body_constraint_angular_actuator> *)ii;
        ii = ii->m_next_T_internal )
  {
    rigid_body_constraint_angular_actuator::outer_prolog_update(
      (rigid_body_constraint_angular_actuator *)&ii[2],
      delta_t);
  }
  for ( jj = v2->m_list_rbc_upright.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_upright != (phys_free_list<rigid_body_constraint_upright> *)jj;
        jj = jj->m_next_T_internal )
  {
    ;
  }
  for ( kk = v2->m_list_rbc_custom_orientation.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_custom_orientation != (phys_free_list<rigid_body_constraint_custom_orientation> *)kk;
        kk = kk->m_next_T_internal )
  {
    ;
  }
  for ( ll = v2->m_list_rbc_custom_path.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_custom_path != (phys_free_list<rigid_body_constraint_custom_path> *)ll;
        ll = ll->m_next_T_internal )
  {
    ;
  }
  v16 = v2->m_list_rbc_contact.m_dummy_head.m_next_T_internal;
  for ( mm = (int)&v2->m_list_rbc_contact;
        (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)mm != v16;
        v16 = v16->m_next_T_internal )
  {
    ;
  }
  v18 = 0;
  if ( sub_count > 0 )
  {
    do
    {
      v19 = v18 + 1;
      outside_delta_t = delta_t / v30;
      physics_system::time_step(v2, outside_delta_t, v18 + 1 == sub_count);
      v18 = v19;
    }
    while ( v19 < sub_count );
    mm = (int)&v2->m_list_rbc_contact;
  }
  for ( nn = v2->m_list_rbc_point.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_point != (phys_free_list<rigid_body_constraint_point> *)nn;
        nn = nn->m_next_T_internal )
  {
    ;
  }
  for ( i1 = v2->m_list_rbc_hinge.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_hinge != (phys_free_list<rigid_body_constraint_hinge> *)i1;
        i1 = i1->m_next_T_internal )
  {
    ;
  }
  v22 = v2->m_list_rbc_dist.m_dummy_head.m_next_T_internal;
  if ( &v2->m_list_rbc_dist != (phys_free_list<rigid_body_constraint_distance> *)v22 )
  {
    do
    {
      rigid_body_constraint_distance::outer_epilog_update((rigid_body_constraint_distance *)&v22[2], delta_t);
      v22 = v22->m_next_T_internal;
    }
    while ( &v2->m_list_rbc_dist != (phys_free_list<rigid_body_constraint_distance> *)v22 );
    mm = (int)&v2->m_list_rbc_contact;
  }
  for ( i2 = v2->m_list_rbc_ragdoll.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_ragdoll != (phys_free_list<rigid_body_constraint_ragdoll> *)i2;
        i2 = i2->m_next_T_internal )
  {
    ;
  }
  for ( i3 = v2->m_list_rbc_wheel.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_wheel != (phys_free_list<rigid_body_constraint_wheel> *)i3;
        i3 = i3->m_next_T_internal )
  {
    ;
  }
  v25 = v2->m_list_rbc_angular_actuator.m_dummy_head.m_next_T_internal;
  if ( &v2->m_list_rbc_angular_actuator != (phys_free_list<rigid_body_constraint_angular_actuator> *)v25 )
  {
    do
    {
      rigid_body_constraint_angular_actuator::outer_epilog_update(
        (rigid_body_constraint_angular_actuator *)&v25[2],
        delta_t);
      v25 = v25->m_next_T_internal;
    }
    while ( &v2->m_list_rbc_angular_actuator != (phys_free_list<rigid_body_constraint_angular_actuator> *)v25 );
    mm = (int)&v2->m_list_rbc_contact;
  }
  for ( i4 = v2->m_list_rbc_upright.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_upright != (phys_free_list<rigid_body_constraint_upright> *)i4;
        i4 = i4->m_next_T_internal )
  {
    ;
  }
  for ( i5 = v2->m_list_rbc_custom_orientation.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_custom_orientation != (phys_free_list<rigid_body_constraint_custom_orientation> *)i5;
        i5 = i5->m_next_T_internal )
  {
    ;
  }
  for ( i6 = v2->m_list_rbc_custom_path.m_dummy_head.m_next_T_internal;
        &v2->m_list_rbc_custom_path != (phys_free_list<rigid_body_constraint_custom_path> *)i6;
        i6 = i6->m_next_T_internal )
  {
    ;
  }
  for ( i7 = v2->m_list_rbc_contact.m_dummy_head.m_next_T_internal;
        (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)mm != i7;
        i7 = i7->m_next_T_internal )
  {
    ;
  }
}

/*
==============
physics_system::physics_system
==============
*/
void __thiscall physics_system::physics_system(physics_system *this)
{
  physics_system *v1; // esi
  phys_free_list<user_rigid_body> *v2; // eax
  phys_free_list<rigid_body> *v3; // eax
  phys_free_list<rigid_body_constraint_contact> *v4; // eax
  phys_free_list<rigid_body_constraint_point> *v5; // eax
  phys_free_list<rigid_body_constraint_hinge> *v6; // eax
  phys_free_list<rigid_body_constraint_distance> *v7; // eax
  phys_free_list<rigid_body_constraint_ragdoll> *v8; // eax
  phys_free_list<rigid_body_constraint_wheel> *v9; // eax
  phys_free_list<rigid_body_constraint_custom_orientation> *v10; // eax
  phys_free_list<rigid_body_constraint_custom_path> *v11; // eax
  phys_free_list<rigid_body_constraint_angular_actuator> *v12; // eax
  phys_free_list<rigid_body_constraint_upright> *v13; // eax

  v1 = this;
  v2 = &this->m_list_user_rigid_body;
  this->m_search_tree_rbc_contact.m_tree_root = NULL;
  v2->m_dummy_head.m_next_T_internal = &v2->m_dummy_head;
  v2->m_dummy_head.m_prev_T_internal = &v2->m_dummy_head;
  v2->m_list_count = 0;
  v2->m_list_count_high_water = 0;
  v2->m_ptr_list_count = 0;
  v3 = &this->m_list_rigid_body;
  v3->m_dummy_head.m_next_T_internal = &v3->m_dummy_head;
  v3->m_dummy_head.m_prev_T_internal = &v3->m_dummy_head;
  v3->m_list_count = 0;
  v3->m_list_count_high_water = 0;
  v3->m_ptr_list_count = 0;
  v4 = &this->m_list_rbc_contact;
  v4->m_dummy_head.m_next_T_internal = &v4->m_dummy_head;
  v4->m_dummy_head.m_prev_T_internal = &v4->m_dummy_head;
  v4->m_list_count = 0;
  v4->m_list_count_high_water = 0;
  v4->m_ptr_list_count = 0;
  v5 = &this->m_list_rbc_point;
  v5->m_dummy_head.m_next_T_internal = &v5->m_dummy_head;
  v5->m_dummy_head.m_prev_T_internal = &v5->m_dummy_head;
  v5->m_list_count = 0;
  v5->m_list_count_high_water = 0;
  v5->m_ptr_list_count = 0;
  v6 = &this->m_list_rbc_hinge;
  v6->m_dummy_head.m_next_T_internal = &v6->m_dummy_head;
  v6->m_dummy_head.m_prev_T_internal = &v6->m_dummy_head;
  v6->m_list_count = 0;
  v6->m_list_count_high_water = 0;
  v6->m_ptr_list_count = 0;
  v7 = &this->m_list_rbc_dist;
  v7->m_dummy_head.m_next_T_internal = &v7->m_dummy_head;
  v7->m_dummy_head.m_prev_T_internal = &v7->m_dummy_head;
  v7->m_list_count = 0;
  v7->m_list_count_high_water = 0;
  v7->m_ptr_list_count = 0;
  v8 = &this->m_list_rbc_ragdoll;
  v8->m_dummy_head.m_next_T_internal = &v8->m_dummy_head;
  v8->m_dummy_head.m_prev_T_internal = &v8->m_dummy_head;
  v8->m_list_count = 0;
  v8->m_list_count_high_water = 0;
  v8->m_ptr_list_count = 0;
  v9 = &this->m_list_rbc_wheel;
  v9->m_dummy_head.m_next_T_internal = &v9->m_dummy_head;
  v9->m_dummy_head.m_prev_T_internal = &v9->m_dummy_head;
  v9->m_list_count = 0;
  v9->m_list_count_high_water = 0;
  v9->m_ptr_list_count = 0;
  v10 = &this->m_list_rbc_custom_orientation;
  v10->m_dummy_head.m_next_T_internal = &v10->m_dummy_head;
  v10->m_dummy_head.m_prev_T_internal = &v10->m_dummy_head;
  v10->m_list_count = 0;
  v10->m_list_count_high_water = 0;
  v10->m_ptr_list_count = 0;
  v11 = &this->m_list_rbc_custom_path;
  v11->m_dummy_head.m_next_T_internal = &v11->m_dummy_head;
  v11->m_dummy_head.m_prev_T_internal = &v11->m_dummy_head;
  v11->m_list_count = 0;
  v11->m_list_count_high_water = 0;
  v11->m_ptr_list_count = 0;
  v12 = &this->m_list_rbc_angular_actuator;
  v12->m_dummy_head.m_next_T_internal = &v12->m_dummy_head;
  v12->m_dummy_head.m_prev_T_internal = &v12->m_dummy_head;
  v12->m_list_count = 0;
  v12->m_list_count_high_water = 0;
  v12->m_ptr_list_count = 0;
  v13 = &this->m_list_rbc_upright;
  v13->m_dummy_head.m_next_T_internal = &v13->m_dummy_head;
  v13->m_dummy_head.m_prev_T_internal = &v13->m_dummy_head;
  v13->m_list_count = 0;
  v13->m_list_count_high_water = 0;
  v13->m_ptr_list_count = 0;
  this->m_contact_point_buffer_1.m_first_block = NULL;
  this->m_contact_point_buffer_1.m_cur = NULL;
  this->m_contact_point_buffer_1.m_end = NULL;
  this->m_contact_point_buffer_1.m_total_memory_allocated = 0;
  this->m_contact_point_buffer_1.m_mutex.m_count = 1;
  this->m_contact_point_buffer_1.m_slot_pool = NULL;
  this->m_contact_point_buffer_2.m_first_block = NULL;
  this->m_contact_point_buffer_2.m_cur = NULL;
  this->m_contact_point_buffer_2.m_end = NULL;
  this->m_contact_point_buffer_2.m_total_memory_allocated = 0;
  this->m_contact_point_buffer_2.m_mutex.m_count = 1;
  this->m_contact_point_buffer_2.m_slot_pool = NULL;
  this->m_outside_sub_delta_t = 0.0;
  this->m_max_delta_t = 0.051282052;
  this->m_flags = 0;
  this->m_collision_callback = NULL;
  this->m_max_vel_iters = 8;
  this->m_max_vel_pos_iters = 4;
  environment_rigid_body::set(&this->m_environment_rigid_body);
  v1->m_solver_memory_high_water = 0;
  v1->m_contact_point_buffer_high_water = 0;
}

/*
==============
physics_system::create_physics_system
==============
*/
void physics_system::create_physics_system()
{
  physics_system *v0; // eax

  v0 = (physics_system *)PMM_PERM_ALLOCATE(0x32C0u, 0x10u);
  if ( v0 )
    physics_system::physics_system(v0);
}

/*
==============
physics_system::initialize
==============
*/
void physics_system::initialize()
{
  physics_system *v0; // eax
  physics_system *v1; // eax

  v0 = (physics_system *)PMM_PERM_ALLOCATE(0x32C0u, 0x10u);
  if ( v0 )
  {
    physics_system::physics_system(v0);
    g_physics_system = v1;
  }
  else
  {
    g_physics_system = NULL;
  }
}

/*
==============
physics_system::destroy_physics_system
==============
*/
void physics_system::destroy_physics_system(physics_system *psys)
{
  physics_system::~physics_system(psys);
}

/*
==============
physics_system::shutdown
==============
*/
void physics_system::shutdown()
{
  physics_system::~physics_system(g_physics_system);
  g_physics_system = NULL;
}

/*
==============
IPN_partition_process
==============
*/
void IPN_partition_process(rigid_body_constraint *rbc, int *island_count)
{
  rigid_body *v2; // ecx
  rigid_body *v3; // esi
  rigid_body *v4; // edi

  v2 = rbc->b2;
  if ( rbc->b1 )
  {
    if ( v2 )
    {
      v3 = rbc->b1->m_partition_node.m_partition_head;
      v4 = v2->m_partition_node.m_partition_head;
      if ( v3 )
      {
        if ( v4 && v3 != v4 )
        {
          if ( --*island_count <= 0
            && _tlAssert("source/physics_system_internal.cpp", 215, "*island_count > 0", (const char *)&pBlock) )
          {
            __debugbreak();
          }
          if ( v3->m_partition_node.m_partition_size < v4->m_partition_node.m_partition_size )
            IPN_merge(v4, v3);
          else
            IPN_merge(v3, v4);
        }
      }
    }
  }
}

/*
==============
physics_system::solver_priority_sort
==============
*/
void __thiscall physics_system::solver_priority_sort(physics_system *this, phys_transient_allocator *transient_buffer)
{
  physics_system *v2; // esi
  char *v3; // edi

  v2 = this;
  if ( this->m_list_rbc_contact.m_list_count >= 4 )
  {
    if ( transient_buffer->m_cur )
    {
      if ( _tlAssert("source/physics_system_internal.cpp", 351, "transient_buffer->is_empty()", (const char *)&pBlock) )
        __debugbreak();
    }
    v3 = phys_transient_allocator::allocate(
           transient_buffer,
           4 * v2->m_list_rbc_contact.m_list_count,
           4,
           0,
           "phys_transient_allocator out of memory.");
    phys_free_list<rigid_body_constraint_contact>::ptr_array_read(
      &v2->m_list_rbc_contact,
      (rigid_body_constraint_contact **)v3,
      v2->m_list_rbc_contact.m_list_count);
    merge_sort((rigid_body_constraint_contact **)v3, v2->m_list_rbc_contact.m_list_count);
    phys_free_list<rigid_body_constraint_contact>::ptr_array_write(
      &v2->m_list_rbc_contact,
      (rigid_body_constraint_contact **)v3,
      v2->m_list_rbc_contact.m_list_count);
    phys_transient_allocator::reset(transient_buffer);
  }
}

/*
==============
shutdown
==============
*/
int shutdown(SOCKET s, int how)
{
  return shutdown(s, how);
}

