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
destroy_broad_phase_info
==============
*/
void destroy_broad_phase_info(rigid_body *body)
{
  void *v1; // esi
  broad_phase_base *v2; // eax
  int v3; // eax
  int v4; // edi
  int v5; // edi

  v1 = body->m_userdata;
  v2 = (broad_phase_base *)*((_DWORD *)v1 + 40);
  if ( v2 )
  {
    aasap_list_remove(v2);
    environment_collision_list_remove(*((broad_phase_base **)v1 + 40));
    v3 = *(_DWORD *)(*((_DWORD *)v1 + 40) + 48);
    if ( v3 & 1 )
    {
      destroy_broad_phase_info(*((broad_phase_info **)v1 + 40));
      *((_DWORD *)v1 + 40) = 0;
    }
    else
    {
      if ( !(v3 & 2)
        && _tlAssert(
             "c:\\t6\\code\\src_noserver\\physics\\phys_main.cpp",
             466,
             "userData->m_bpb->is_bpg()",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v4 = *((_DWORD *)v1 + 40);
      if ( !(*(_BYTE *)(v4 + 48) & 2)
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_base.h",
             102,
             "is_bpg()",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      destroy_broad_phase_info_list(*(broad_phase_info **)(v4 + 80));
      v5 = *((_DWORD *)v1 + 40);
      if ( !(*(_BYTE *)(v5 + 48) & 2)
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_base.h",
             102,
             "is_bpg()",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      destroy_broad_phase_group((broad_phase_group *)v5);
      *((_DWORD *)v1 + 40) = 0;
    }
  }
}

/*
==============
create_broad_phase_info
==============
*/
void create_broad_phase_info(rigid_body *body, int colflag_mask)
{
  PhysObjUserData *v2; // esi
  signed int v3; // eax
  broad_phase_group *v4; // edi
  gjk_base_t *v5; // ebx
  broad_phase_info *v6; // esi
  unsigned int v7; // eax
  gjk_base_t *v8; // ebx
  broad_phase_info *v9; // edi
  unsigned int v10; // ecx
  PhysObjUserData *userData; // [esp+Ch] [ebp-4h]

  v2 = (PhysObjUserData *)body->m_userdata;
  userData = v2;
  if ( v2->m_gjk_geom_list.m_geom_count < 0
    && _tlAssert(
         "c:\\t6\\code\\src_noserver\\physics\\phys_colgeom.h",
         1035,
         "m_geom_count >= 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v3 = v2->m_gjk_geom_list.m_geom_count;
  if ( v3 > 1 )
  {
    v4 = create_broad_phase_group();
    v4->m_list_bpi_head = NULL;
    v4->m_bpi_count = 0;
    v4->m_rbvm = NULL;
    v4->m_list_wci = NULL;
    v4->m_sap_node = NULL;
    v4->m_list_bpb_next = NULL;
    v4->m_user_data = NULL;
    v4->m_flags = 2;
    v4->m_env_collision_flags = 0;
    v4->m_my_collision_type_flags = 0;
    if ( v2->m_gjk_geom_list.m_geom_count < 0
      && _tlAssert(
           "c:\\t6\\code\\src_noserver\\physics\\phys_colgeom.h",
           1034,
           "m_geom_count >= 0",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v5 = v2->m_gjk_geom_list.m_first_geom;
    if ( v5 )
    {
      do
      {
        v6 = create_broad_phase_info();
        if ( !(v5->m_flags & 4)
          && _tlAssert(
               "c:\\t6\\code\\src_noserver\\physics\\phys_colgeom.h",
               86,
               "get_flag(FLAG_GEOM_ID_VALID)",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v7 = v5->m_gjk_geom_id;
        v6->m_list_bpb_next = NULL;
        v6->m_sap_node = NULL;
        v6->m_rb = body;
        v6->m_rb_to_world_xform = &body->m_mat;
        v6->m_cg_to_world_xform = &userData->m2w;
        v6->m_cg_to_rb_xform = &userData->cg2rb;
        v6->m_gjk_geom_id = v7;
        v6->m_gjk_geom = (phys_gjk_geom *)&v5->vfptr;
        v6->m_flags = 513;
        v6->m_surface_type = 32;
        v6->m_user_data = NULL;
        v6->m_env_collision_flags = colflag_mask;
        v6->m_my_collision_type_flags = 0;
        environment_collision_list_remove((broad_phase_base *)&v6->m_trace_aabb_min_whace);
        v6->m_flags |= 0x40u;
        v6->m_list_bpb_next = (broad_phase_base *)&v4->m_list_bpi_head->m_trace_aabb_min_whace;
        ++v4->m_bpi_count;
        v4->m_list_bpi_head = v6;
        v4->m_env_collision_flags |= v6->m_env_collision_flags;
        v4->m_my_collision_type_flags |= v6->m_my_collision_type_flags;
        v5 = v5->m_next_geom;
      }
      while ( v5 );
      v2 = userData;
    }
    else if ( _tlAssert("c:\\t6\\code\\src_noserver\\physics\\phys_main.cpp", 425, "geom", (const char *)&pBlock) )
    {
      __debugbreak();
      v2->m_bpb = (broad_phase_base *)&v4->m_trace_aabb_min_whace;
      goto LABEL_34;
    }
    v2->m_bpb = (broad_phase_base *)&v4->m_trace_aabb_min_whace;
    goto LABEL_34;
  }
  if ( v3 < 0
    && _tlAssert(
         "c:\\t6\\code\\src_noserver\\physics\\phys_colgeom.h",
         1035,
         "m_geom_count >= 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( v2->m_gjk_geom_list.m_geom_count != 1
    && _tlAssert(
         "c:\\t6\\code\\src_noserver\\physics\\phys_main.cpp",
         437,
         "userData->m_gjk_geom_list.get_geom_count() == 1",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( v2->m_gjk_geom_list.m_geom_count < 0
    && _tlAssert(
         "c:\\t6\\code\\src_noserver\\physics\\phys_colgeom.h",
         1034,
         "m_geom_count >= 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v8 = v2->m_gjk_geom_list.m_first_geom;
  if ( !v8 && _tlAssert("c:\\t6\\code\\src_noserver\\physics\\phys_main.cpp", 439, "gjk_geom", (const char *)&pBlock) )
    __debugbreak();
  v9 = create_broad_phase_info();
  if ( !(v8->m_flags & 4)
    && _tlAssert(
         "c:\\t6\\code\\src_noserver\\physics\\phys_colgeom.h",
         86,
         "get_flag(FLAG_GEOM_ID_VALID)",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v10 = v8->m_gjk_geom_id;
  v9->m_list_bpb_next = NULL;
  v9->m_sap_node = NULL;
  v9->m_rb_to_world_xform = &body->m_mat;
  v9->m_cg_to_world_xform = &v2->m2w;
  v9->m_cg_to_rb_xform = &v2->cg2rb;
  v9->m_gjk_geom_id = v10;
  v9->m_rb = body;
  v9->m_gjk_geom = (phys_gjk_geom *)&v8->vfptr;
  v9->m_flags = 513;
  v9->m_surface_type = 32;
  v9->m_user_data = NULL;
  v9->m_env_collision_flags = colflag_mask;
  v9->m_my_collision_type_flags = 0;
  v2->m_bpb = (broad_phase_base *)&v9->m_trace_aabb_min_whace;
  if ( body->m_flags & 0x20 )
    v9->m_env_collision_flags &= 0xFFFFFFFE;
LABEL_34:
  environment_collision_list_add(v2->m_bpb);
  aasap_list_add(v2->m_bpb);
}

/*
==============
merge_sort
==============
*/
void merge_sort(rigid_body_constraint_contact **list, const int list_count)
{
  rigid_body_constraint_contact *v2; // ecx
  rigid_body_constraint_contact **v3; // esi
  rigid_body_constraint_contact **v4; // edi
  unsigned int i; // eax
  rigid_body_constraint_contact *v6; // ecx
  int v7; // ecx
  int v8; // esi
  rigid_body_constraint_contact **last; // [esp+4h] [ebp-4h]

  if ( list_count >= 3 )
  {
    v3 = list;
    merge_sort(list, list_count / 2);
    merge_sort(&list[list_count / 2], list_count - list_count / 2);
    v4 = &list[list_count / 2];
    last = &list[list_count];
    for ( i = (unsigned int)(v4 - 1); v4 < last; ++v4 )
    {
      v6 = *(rigid_body_constraint_contact **)i;
      if ( (*v4)->m_solver_priority >= *(_DWORD *)(*(_DWORD *)i + 20) )
        break;
      *(_DWORD *)i = *v4;
      *v4 = v6;
      v7 = i - 4;
      if ( i > (unsigned int)v3 )
      {
        while ( 1 )
        {
          v8 = *(_DWORD *)v7;
          if ( *(_DWORD *)(*(_DWORD *)i + 20) >= *(_DWORD *)(*(_DWORD *)v7 + 20) )
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
    if ( list[1]->m_solver_priority < (*list)->m_solver_priority )
    {
      *list = list[1];
      list[1] = v2;
    }
  }
}

/*
==============
phys_wheel_collide_info::collision_process
==============
*/
void __userpurge phys_wheel_collide_info::collision_process(phys_wheel_collide_info *this@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>, broad_phase_info *bpi)
{
  int v5; // ST18_4
  int v6; // ST14_4
  phys_mat44 *v7; // edi
  phys_wheel_collide_info *v8; // esi
  phys_gjk_geom *v9; // ecx
  int v10; // [esp+14h] [ebp-54h]
  int v11; // [esp+18h] [ebp-50h]
  int v12; // [esp+1Ch] [ebp-4Ch]
  int v13; // [esp+20h] [ebp-48h]
  int v14; // [esp+24h] [ebp-44h]
  phys_vec3 ray_pos_loc; // [esp+28h] [ebp-40h]
  phys_vec3 hitn; // [esp+38h] [ebp-30h]
  phys_vec3 ray_dir_loc; // [esp+48h] [ebp-20h]
  float v18; // [esp+58h] [ebp-10h]
  int v19; // [esp+5Ch] [ebp-Ch]
  int v20; // [esp+60h] [ebp-8h]
  int retaddr; // [esp+68h] [ebp+0h]

  v19 = a2;
  v20 = retaddr;
  v5 = a4;
  v6 = a3;
  v7 = bpi->m_cg_to_world_xform;
  v8 = this;
  phys_full_inv_multiply((phys_vec3 *)&v12, bpi->m_cg_to_world_xform, &this->m_ray_pos);
  v18 = v7->y.y * v8->m_ray_dir.y + v7->y.x * v8->m_ray_dir.x + v7->y.z * v8->m_ray_dir.z;
  ray_dir_loc.w = v7->z.y * v8->m_ray_dir.y + v7->z.x * v8->m_ray_dir.x + v7->z.z * v8->m_ray_dir.z;
  v9 = bpi->m_gjk_geom;
  hitn.y = v7->x.y * v8->m_ray_dir.y + v8->m_ray_dir.x * v7->x.x + v7->x.z * v8->m_ray_dir.z;
  hitn.z = v18;
  hitn.w = ray_dir_loc.w;
  if ( ((unsigned int (__stdcall *)(_DWORD *, float *, _DWORD, float *, float *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, float, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v9->vfptr->ray_cast)(
         &v12,
         &hitn.y,
         v8->m_hit_t,
         &v18,
         &ray_pos_loc.y,
         v6,
         v5,
         v10,
         v11,
         v12,
         v13,
         v14,
         LODWORD(ray_pos_loc.x),
         LODWORD(ray_pos_loc.y),
         LODWORD(ray_pos_loc.z),
         LODWORD(ray_pos_loc.w),
         LODWORD(hitn.x),
         LODWORD(hitn.y),
         COERCE_FLOAT(LODWORD(v18)),
         LODWORD(ray_dir_loc.w),
         LODWORD(ray_dir_loc.x),
         LODWORD(ray_dir_loc.y),
         LODWORD(ray_dir_loc.z),
         LODWORD(ray_dir_loc.w)) )
  {
    if ( v8->m_hit_t < (double)v18 )
    {
      if ( _tlAssert("source/phys_broad_phase.cpp", 41, "hit_t <= m_hit_t", (const char *)&pBlock) )
        __debugbreak();
    }
    v8->m_hit_t = v18;
    v8->m_hitn.x = ray_pos_loc.y;
    v8->m_hitn.y = ray_pos_loc.z;
    v8->m_hitn.z = ray_pos_loc.w;
    v8->m_hit_bpi = bpi;
  }
}

/*
==============
phys_wheel_collide_info::collision_epilog
==============
*/
void __userpurge phys_wheel_collide_info::collision_epilog(phys_wheel_collide_info *this@<ecx>, int a2@<ebp>, rigid_body_constraint_wheel *rbc_wheel)
{
  phys_wheel_collide_info *v3; // edi
  phys_vec3 *v4; // esi
  double v5; // st7
  phys_vec3 *v6; // eax
  double v7; // st7
  broad_phase_info *v8; // edi
  phys_mat44 *v9; // ST10_4
  int v10; // [esp-Ch] [ebp-4Ch]
  phys_vec3 b2_hitn_loc; // [esp+0h] [ebp-40h]
  float v12; // [esp+14h] [ebp-2Ch]
  float v13; // [esp+18h] [ebp-28h]
  float v14; // [esp+1Ch] [ebp-24h]
  float v15; // [esp+30h] [ebp-10h]
  int v16; // [esp+34h] [ebp-Ch]
  int v17; // [esp+38h] [ebp-8h]
  int retaddr; // [esp+40h] [ebp+0h]

  v16 = a2;
  v17 = retaddr;
  v3 = this;
  rigid_body_constraint_wheel::set_no_collision(rbc_wheel);
  if ( v3->m_hit_bpi )
  {
    v4 = &v3->m_hitn;
    v15 = v3->m_hitn.y * v3->m_hitn.y + v3->m_hitn.x * v3->m_hitn.x + v3->m_hitn.z * v3->m_hitn.z;
    v15 = sqrt(v15);
    if ( v15 > 0.000001 )
    {
      v15 = 1.0 / v15;
      v5 = v15;
      v4->x = v15 * v4->x;
      v3->m_hitn.y = v3->m_hitn.y * v5;
      v3->m_hitn.z = v5 * v3->m_hitn.z;
      v6 = phys_multiply((phys_vec3 *)((char *)&b2_hitn_loc + 4), v3->m_hit_bpi->m_cg_to_world_xform, &v3->m_hitn);
      v4->x = v6->x;
      v3->m_hitn.y = v6->y;
      v3->m_hitn.z = v6->z;
      v15 = v3->m_hit_t;
      v12 = v15 * v3->m_ray_dir.x;
      v13 = v3->m_ray_dir.y * v15;
      v14 = v15 * v3->m_ray_dir.z;
      b2_hitn_loc.y = v3->m_ray_pos.x + v12;
      b2_hitn_loc.z = v3->m_ray_pos.y + v13;
      v7 = v3->m_ray_pos.z;
      v8 = v3->m_hit_bpi;
      v9 = v8->m_rb_to_world_xform;
      b2_hitn_loc.w = v7 + v14;
      phys_full_inv_multiply((phys_vec3 *)&v12, v9, (phys_vec3 *)((char *)&b2_hitn_loc + 4));
      phys_inv_multiply((phys_vec3 *)&v10, v8->m_rb_to_world_xform, v4);
      rigid_body_constraint_wheel::set_collision(rbc_wheel, v8->m_rb, (phys_vec3 *)&v12, (phys_vec3 *)&v10);
    }
  }
}

/*
==============
axis_aligned_sweep_and_prune::sap_node::init
==============
*/
void __thiscall axis_aligned_sweep_and_prune::sap_node::init(axis_aligned_sweep_and_prune::sap_node *this, broad_phase_base *bpb, axis_aligned_sweep_and_prune::axis_element **xlist, axis_aligned_sweep_and_prune::axis_element **ylist, axis_aligned_sweep_and_prune::axis_element **zlist)
{
  axis_aligned_sweep_and_prune::axis_element *v5; // edx
  axis_aligned_sweep_and_prune::axis_element *v6; // eax

  this->m_bpb = bpb;
  this->m_updated = 0;
  *(_QWORD *)&this->m_ae1[0][0].m_node = (unsigned int)this;
  this->m_ae1[0][1].m_node = this;
  this->m_ae1[0][1].m_min_max = 1;
  this->m_ae1[0][0].m_next = &this->m_ae1[0][1];
  this->m_ae1[0][1].m_next = *xlist;
  *xlist = (axis_aligned_sweep_and_prune::axis_element *)this->m_ae1;
  *(_QWORD *)&this->m_ae1[1][0].m_node = (unsigned int)this;
  this->m_ae1[1][1].m_node = this;
  this->m_ae1[1][1].m_min_max = 1;
  this->m_ae1[1][0].m_next = &this->m_ae1[1][1];
  this->m_ae1[1][1].m_next = *ylist;
  *ylist = this->m_ae1[1];
  v5 = this->m_ae1[2];
  v6 = &this->m_ae1[2][1];
  v5->m_node = this;
  v5->m_min_max = 0;
  v6->m_node = this;
  v6->m_min_max = 1;
  v5->m_next = &this->m_ae1[2][1];
  v6->m_next = *zlist;
  *zlist = this->m_ae1[2];
}

/*
==============
axis_aligned_sweep_and_prune::are_overlapping
==============
*/
BOOL axis_aligned_sweep_and_prune::are_overlapping(axis_aligned_sweep_and_prune::sap_node *n1, axis_aligned_sweep_and_prune::sap_node *n2)
{
  return n1->m_ae1[0][0].m_ae_list_index < n2->m_ae1[0][1].m_ae_list_index
      && n2->m_ae1[0][0].m_ae_list_index < n1->m_ae1[0][1].m_ae_list_index
      && n1->m_ae1[1][0].m_ae_list_index < n2->m_ae1[1][1].m_ae_list_index
      && n2->m_ae1[1][0].m_ae_list_index < n1->m_ae1[1][1].m_ae_list_index
      && n1->m_ae1[2][0].m_ae_list_index < n2->m_ae1[2][1].m_ae_list_index
      && n2->m_ae1[2][0].m_ae_list_index < n1->m_ae1[2][1].m_ae_list_index;
}

/*
==============
axis_aligned_sweep_and_prune::remove
==============
*/
void axis_aligned_sweep_and_prune::remove(axis_aligned_sweep_and_prune::axis_element **axis_list, axis_aligned_sweep_and_prune::sap_node *node)
{
  axis_aligned_sweep_and_prune::axis_element **v3; // ecx
  axis_aligned_sweep_and_prune::axis_element *v4; // eax
  signed int v5; // edx

  v3 = axis_list;
  v4 = *axis_list;
  v5 = 0;
  if ( !*axis_list )
    goto LABEL_12;
  do
  {
    if ( v5 >= 2 )
      break;
    if ( v4->m_node == node )
    {
      *v3 = v4->m_next;
      ++v5;
    }
    else
    {
      v3 = &v4->m_next;
    }
    v4 = *v3;
  }
  while ( *v3 );
  if ( v5 != 2 )
  {
LABEL_12:
    if ( _tlAssert("source/phys_broad_phase.cpp", 515, "count == 2", (const char *)&pBlock) )
      __debugbreak();
  }
}

/*
==============
check_terrain_query_params
==============
*/
void check_terrain_query_params(broad_phase_base *bpb)
{
  float ntranslation_sq; // [esp+8h] [ebp+8h]

  ntranslation_sq = bpb->m_trace_translation.y * bpb->m_trace_translation.y
                  + bpb->m_trace_translation.x * bpb->m_trace_translation.x
                  + bpb->m_trace_translation.z * bpb->m_trace_translation.z;
  if ( ntranslation_sq > 260100.0 )
  {
    if ( (pai_check_terrain_query_params.m_hits_total_count < dword_10E5860 || !dword_10E5860)
      && dword_10E585C < dword_10E5864 )
    {
      if ( byte_10E5868 )
      {
        PHYS_WARNING(
          "source/phys_broad_phase.cpp",
          636,
          "ntranslation_sq <= MAX_TRANSLATION_SQ",
          "terrain query translation too large.");
      }
      else if ( ntranslation_sq > 260100.0 )
      {
        if ( _tlAssert(
               "source/phys_broad_phase.cpp",
               636,
               "ntranslation_sq <= MAX_TRANSLATION_SQ",
               "terrain query translation too large.") )
        {
          __debugbreak();
        }
      }
    }
    _InterlockedExchangeAdd(&pai_check_terrain_query_params.m_hits_total_count, 1u);
    _InterlockedExchangeAdd(&dword_10E585C, 1u);
  }
}

/*
==============
calc_largest_vel_sq
==============
*/
void __usercall calc_largest_vel_sq(float a1@<ebp>, broad_phase_info *bpi)
{
  rigid_body *v2; // esi
  double v3; // st7
  double v4; // st7
  double v5; // st5
  double v6; // st1
  phys_mat44 *v7; // edi
  phys_vec3 *v8; // eax
  float *v9; // edx
  double v10; // st7
  float v11; // ecx
  int v12; // [esp-Ch] [ebp-6Ch]
  phys_vec3 support_pt_loc; // [esp+0h] [ebp-60h]
  phys_vec3 dir_loc; // [esp+10h] [ebp-50h]
  float v15; // [esp+24h] [ebp-3Ch]
  float v16; // [esp+28h] [ebp-38h]
  float v17; // [esp+2Ch] [ebp-34h]
  phys_vec3 support_pt; // [esp+30h] [ebp-30h]
  phys_vec3 dir; // [esp+40h] [ebp-20h]
  float v20; // [esp+50h] [ebp-10h]
  float lvs; // [esp+54h] [ebp-Ch]
  const float t_vel_sq; // [esp+58h] [ebp-8h]
  float retaddr; // [esp+60h] [ebp+0h]

  lvs = a1;
  t_vel_sq = retaddr;
  if ( bpi->m_flags & 4 && _tlAssert("source/phys_broad_phase.cpp", 694, "!bpi->is_bpi_env()", (const char *)&pBlock) )
    __debugbreak();
  v2 = bpi->m_rb;
  if ( v2->m_flags & 0x30
    && _tlAssert(
         "source/phys_broad_phase.cpp",
         696,
         "!rb->get_flag(rigid_body::FLAG_ENVIRONMENT_RIGID_BODY|rigid_body::FLAG_USER_RIGID_BODY)",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  dir.z = v2->m_a_vel.y * v2->m_a_vel.y + v2->m_a_vel.x * v2->m_a_vel.x + v2->m_a_vel.z * v2->m_a_vel.z;
  dir.w = v2->m_t_vel.y * v2->m_t_vel.y + v2->m_t_vel.x * v2->m_t_vel.x + v2->m_t_vel.z * v2->m_t_vel.z;
  v3 = 0.0000010000001;
  if ( dir.z >= 0.0000010000001 )
  {
    support_pt.y = v2->m_t_vel.y * v2->m_a_vel.z - v2->m_t_vel.z * v2->m_a_vel.y;
    support_pt.z = v2->m_t_vel.z * v2->m_a_vel.x - v2->m_t_vel.x * v2->m_a_vel.z;
    support_pt.w = v2->m_t_vel.x * v2->m_a_vel.y - v2->m_t_vel.y * v2->m_a_vel.x;
    v20 = support_pt.z * support_pt.z + support_pt.y * support_pt.y + support_pt.w * support_pt.w;
    if ( v20 < 0.0000010000001 )
    {
      v15 = v2->m_a_vel.y * 0.0 - v2->m_a_vel.z * 0.0;
      v5 = v2->m_a_vel.x * 0.0;
      v16 = v2->m_a_vel.z - v5;
      v17 = v5 - v2->m_a_vel.y;
      dir_loc.y = v2->m_t_vel.x + v15;
      dir_loc.z = v2->m_t_vel.y + v16;
      dir_loc.w = v2->m_t_vel.z + v17;
      v15 = dir_loc.z * v2->m_a_vel.z - dir_loc.w * v2->m_a_vel.y;
      v16 = dir_loc.w * v2->m_a_vel.x - v2->m_a_vel.z * dir_loc.y;
      v17 = dir_loc.y * v2->m_a_vel.y - dir_loc.z * v2->m_a_vel.x;
      support_pt.y = v15;
      support_pt.z = v16;
      support_pt.w = v17;
      v20 = v17 * v17 + v16 * v16 + v15 * v15;
      if ( v20 >= 0.0000010000001 )
      {
        v3 = 0.0000010000001;
      }
      else
      {
        v6 = v2->m_a_vel.y * 0.0;
        dir_loc.y = v6 - v2->m_a_vel.z * 2.0;
        dir_loc.z = 0.0 * v2->m_a_vel.z - v5;
        v3 = 0.0000010000001;
        dir_loc.w = 2.0 * v2->m_a_vel.x - v6;
        v15 = v2->m_t_vel.x + dir_loc.y;
        v16 = v2->m_t_vel.y + dir_loc.z;
        v17 = v2->m_t_vel.z + dir_loc.w;
        dir_loc.y = v16 * v2->m_a_vel.z - v17 * v2->m_a_vel.y;
        dir_loc.z = v17 * v2->m_a_vel.x - v2->m_a_vel.z * v15;
        dir_loc.w = v15 * v2->m_a_vel.y - v16 * v2->m_a_vel.x;
        support_pt.y = dir_loc.y;
        support_pt.z = dir_loc.z;
        support_pt.w = dir_loc.w;
        v20 = dir_loc.w * dir_loc.w + dir_loc.z * dir_loc.z + dir_loc.y * dir_loc.y;
      }
    }
    if ( v3 > v20 )
    {
      v4 = dir.w + dir.z;
    }
    else
    {
      phys_inv_multiply(
        (phys_vec3 *)((char *)&support_pt_loc + 4),
        bpi->m_cg_to_world_xform,
        (phys_vec3 *)((char *)&support_pt + 4));
      ((void (__stdcall *)(float *, int *, float *))bpi->m_gjk_geom->vfptr->support)(
        &support_pt_loc.y,
        &v12,
        &dir_loc.y);
      v7 = bpi->m_rb_to_world_xform;
      LODWORD(dir.z) = bpi->m_cg_to_world_xform;
      v8 = phys_multiply((phys_vec3 *)&v15, (phys_mat44 *)LODWORD(dir.z), (phys_vec3 *)&v12);
      dir_loc.y = v8->x + *(float *)(LODWORD(dir.z) + 48);
      dir_loc.z = v8->y + *(float *)(LODWORD(dir.z) + 52);
      dir_loc.w = v8->z + *(float *)(LODWORD(dir.z) + 56);
      v15 = dir_loc.y - v7->w.x;
      v16 = dir_loc.z - v7->w.y;
      v17 = dir_loc.w - v7->w.z;
      dir_loc.y = v17 * v2->m_a_vel.y - v16 * v2->m_a_vel.z;
      dir_loc.z = v15 * v2->m_a_vel.z - v17 * v2->m_a_vel.x;
      dir_loc.w = v16 * v2->m_a_vel.x - v15 * v2->m_a_vel.y;
      v15 = v2->m_t_vel.x + dir_loc.y;
      v16 = v2->m_t_vel.y + dir_loc.z;
      v17 = v2->m_t_vel.z + dir_loc.w;
      v4 = v15 * v15 + v16 * v16 + v17 * v17;
    }
  }
  else
  {
    v4 = dir.w;
  }
  v20 = v4;
  v9 = &v2->m_largest_vel_sq;
  v10 = v20;
  do
  {
    dir.z = *v9;
    if ( dir.z > v10 )
      break;
    v11 = dir.z;
  }
  while ( _InterlockedCompareExchange((volatile signed __int32 *)v9, SLODWORD(v20), SLODWORD(dir.z)) != LODWORD(v11) );
}

/*
==============
broad_phase_reset_buffer
==============
*/
void broad_phase_reset_buffer()
{
  phys_transient_allocator::reset(&G_BPM->g_collision_memory_buffer);
}

/*
==============
broad_phase_memory_info::broad_phase_memory_info
==============
*/
void __thiscall broad_phase_memory_info::broad_phase_memory_info(broad_phase_memory_info *this)
{
  this->m_max_num_gjk_ci = 0;
  this->m_max_num_sap_active_pairs = 0;
  this->m_max_num_surface_types = 0;
}

/*
==============
bp_env_jq_batch_function1
==============
*/
int __usercall bp_env_jq_batch_function1@<eax>(int a1@<ebp>, jqBatch *pBatch)
{
  signed __int32 i; // eax
  float **v3; // esi
  float *v4; // ecx
  double v5; // st7
  double v6; // st7
  double v7; // st7
  float *v8; // ecx
  double v9; // st7
  bool v10; // c0
  bool v11; // c3
  double v12; // st7
  double v13; // st7
  bool v14; // c0
  bool v15; // c3
  double v16; // st7
  double v17; // st7
  bool v18; // c0
  bool v19; // c3
  double v20; // st7
  float v22; // [esp-Ch] [ebp-6Ch]
  float v23; // [esp-8h] [ebp-68h]
  float v24; // [esp-4h] [ebp-64h]
  broad_phase_base bpb; // [esp+0h] [ebp-60h]
  float v26; // [esp+50h] [ebp-10h]
  int v27; // [esp+54h] [ebp-Ch]
  int v28; // [esp+58h] [ebp-8h]
  int retaddr; // [esp+60h] [ebp+0h]

  v27 = a1;
  v28 = retaddr;
  v22 = 1.0e30;
  v23 = 1.0e30;
  v24 = 1.0e30;
  bpb.m_trace_aabb_min_whace.y = -1.0e30;
  bpb.m_trace_aabb_min_whace.z = -1.0e30;
  bpb.m_trace_aabb_min_whace.w = -1.0e30;
  for ( i = _InterlockedExchangeAdd(&g_bpb_list_index, 1u);
        i < g_bpb_list_max_index;
        i = _InterlockedIncrement(&g_bpb_list_index) - 1 )
  {
    process_cluster_environment_collision_prolog(g_bpb_ptr_list[i], (broad_phase_base *)&v22);
  }
  v3 = (float **)pBatch->Input;
  tlAtomicMutex::Lock(&g_prolog_task_mutex);
  v4 = *v3;
  v5 = v24;
  if ( v24 >= (double)(*v3)[2] )
    v5 = v4[2];
  *(float *)&bpb.m_my_collision_type_flags = v5;
  v6 = v23;
  if ( v23 >= (double)v4[1] )
    v6 = v4[1];
  *((float *)&bpb.m_my_collision_type_flags + 1) = v6;
  v7 = v22;
  if ( v22 >= (double)*v4 )
    v7 = *v4;
  v26 = v7;
  *v4 = v26;
  v4[1] = *((float *)&bpb.m_my_collision_type_flags + 1);
  v4[2] = *(float *)&bpb.m_my_collision_type_flags;
  v8 = v3[1];
  v9 = v8[2];
  v10 = bpb.m_trace_aabb_min_whace.w < v9;
  v11 = bpb.m_trace_aabb_min_whace.w == v9;
  v12 = bpb.m_trace_aabb_min_whace.w;
  if ( v10 || v11 )
    v12 = v8[2];
  v26 = v12;
  v13 = v8[1];
  v14 = bpb.m_trace_aabb_min_whace.z < v13;
  v15 = bpb.m_trace_aabb_min_whace.z == v13;
  v16 = bpb.m_trace_aabb_min_whace.z;
  if ( v14 || v15 )
    v16 = v8[1];
  *((float *)&bpb.m_my_collision_type_flags + 1) = v16;
  v17 = *v8;
  v18 = bpb.m_trace_aabb_min_whace.y < v17;
  v19 = bpb.m_trace_aabb_min_whace.y == v17;
  v20 = bpb.m_trace_aabb_min_whace.y;
  if ( v18 || v19 )
    v20 = *v8;
  *(float *)&bpb.m_my_collision_type_flags = v20;
  *v8 = *(float *)&bpb.m_my_collision_type_flags;
  v8[1] = *((float *)&bpb.m_my_collision_type_flags + 1);
  v8[2] = v26;
  if ( !--g_prolog_task_mutex.LockCount )
  {
    bpb.m_my_collision_type_flags = 0;
    InterlockedExchange((volatile LONG *)&bpb.m_my_collision_type_flags, 0);
    g_prolog_task_mutex.ThreadId = 0i64;
  }
  return 0;
}

/*
==============
merge_sort_bpb
==============
*/
void merge_sort_bpb(broad_phase_base **list, const int list_count)
{
  broad_phase_base *v2; // eax
  broad_phase_base **v3; // ebx
  broad_phase_base **i; // esi
  signed int v5; // eax
  broad_phase_base *v6; // edi
  double v7; // st7
  signed int v8; // edi
  broad_phase_base *v9; // eax
  broad_phase_base **j; // edi
  broad_phase_base *v11; // eax
  broad_phase_base **last; // [esp+8h] [ebp-8h]
  broad_phase_base *v13; // [esp+Ch] [ebp-4h]
  int list_counta; // [esp+1Ch] [ebp+Ch]
  float list_countb; // [esp+1Ch] [ebp+Ch]

  if ( list_count >= 3 )
  {
    merge_sort_bpb(list, list_count / 2);
    merge_sort_bpb(&list[list_count / 2], list_count - list_count / 2);
    v3 = &list[list_count / 2];
    last = &list[list_count];
    for ( i = v3 - 1; v3 < last; ++v3 )
    {
      v5 = g_bpb_cluster_sort_axis;
      v6 = *v3;
      v13 = *i;
      list_counta = g_bpb_cluster_sort_axis;
      if ( g_bpb_cluster_sort_axis < 0 || g_bpb_cluster_sort_axis >= 3 )
      {
        if ( _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h",
               36,
               "i >= 0 && i < 3",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v5 = g_bpb_cluster_sort_axis;
      }
      v7 = *(&v6->m_trace_aabb_min_whace.x + list_counta);
      v8 = v5;
      if ( (v5 < 0 || v5 >= 3)
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h",
             36,
             "i >= 0 && i < 3",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      list_countb = v7;
      if ( *(&v13->m_trace_aabb_min_whace.x + v8) <= (double)list_countb )
        break;
      v9 = *i;
      *i = *v3;
      *v3 = v9;
      for ( j = i - 1; i > list; --j )
      {
        if ( !compare_bpb(*i, *j) )
          break;
        v11 = *j;
        *j = *i;
        *i = v11;
        i = j;
      }
      i = v3;
    }
  }
  else if ( list_count == 2 )
  {
    if ( compare_bpb(list[1], *list) )
    {
      v2 = *list;
      *list = list[1];
      list[1] = v2;
    }
  }
}

/*
==============
broad_phase_process_object_environment_collision
==============
*/
void __usercall broad_phase_process_object_environment_collision(int a1@<ebp>, bpi_environment_collision_info *eci)
{
  int v2; // eax
  bpi_environment_collision_info *v3; // esi
  char *v4; // eax
  broad_phase_base *v5; // edi
  float v6; // eax
  broad_phase_base **v7; // edi
  int v8; // edx
  int v9; // edx
  unsigned int v10; // edx
  broad_phase_base **i; // eax
  broad_phase_base *v12; // edi
  broad_phase_base *v13; // eax
  float v14; // eax
  float v15; // ecx
  float v16; // edx
  int v17; // esi
  double v18; // st7
  double v19; // st7
  float v20; // eax
  unsigned int v21; // ecx
  volatile unsigned int v22; // edx
  double v23; // st7
  float v24; // eax
  float v25; // ecx
  int v26; // edx
  double v27; // st7
  int v28; // esi
  double v29; // st7
  double v30; // st7
  double v31; // st7
  double v32; // st7
  double v33; // st7
  double v34; // st7
  double v35; // st7
  double v36; // st7
  double v37; // st7
  double v38; // st7
  double v39; // st7
  double v40; // st7
  double v41; // st7
  double v42; // st6
  double v43; // st5
  double v44; // st4
  double v45; // st3
  double v46; // st2
  int v47; // eax
  int v48; // edx
  double v49; // st1
  double v50; // st1
  float v51; // eax
  float v52; // eax
  float v53; // esi
  double v54; // st7
  double v55; // st6
  double v56; // st5
  double v57; // st4
  double v58; // st3
  double v59; // st2
  int v60; // ecx
  float v61; // [esp-Ch] [ebp-12Ch]
  float v62; // [esp-8h] [ebp-128h]
  float v63; // [esp-4h] [ebp-124h]
  phys_vec3 p1; // [esp+0h] [ebp-120h]
  phys_vec3 p2; // [esp+10h] [ebp-110h]
  phys_vec3 half_dims; // [esp+20h] [ebp-100h]
  phys_vec3 *v67; // [esp+30h] [ebp-F0h]
  float v68; // [esp+34h] [ebp-ECh]
  broad_phase_prolog_task_input bppti; // [esp+38h] [ebp-E8h]
  phys_vec3 bp_aabb_min; // [esp+40h] [ebp-E0h]
  phys_vec3 bp_aabb_max; // [esp+50h] [ebp-D0h]
  phys_vec3 aabb2_min; // [esp+60h] [ebp-C0h]
  phys_vec3 aabb2_max; // [esp+70h] [ebp-B0h]
  int v74; // [esp+80h] [ebp-A0h]
  unsigned int v75; // [esp+84h] [ebp-9Ch]
  phys_transient_allocator transient_buffer; // [esp+88h] [ebp-98h]
  phys_vec3 aabb1_max; // [esp+A0h] [ebp-80h]
  phys_vec3 aabb1_min; // [esp+B0h] [ebp-70h]
  broad_phase_base *v79; // [esp+C0h] [ebp-60h]
  int v80; // [esp+C4h] [ebp-5Ch]
  float v81; // [esp+C8h] [ebp-58h]
  broad_phase_base *bpb_cluster_head; // [esp+CCh] [ebp-54h]
  unsigned int env_collision_flags; // [esp+D0h] [ebp-50h]
  float v84; // [esp+D4h] [ebp-4Ch]
  int bpb_cluster_list_count; // [esp+D8h] [ebp-48h]
  float v86; // [esp+DCh] [ebp-44h]
  float v87; // [esp+E0h] [ebp-40h]
  float v88; // [esp+E4h] [ebp-3Ch]
  float v89; // [esp+E8h] [ebp-38h]
  float j; // [esp+ECh] [ebp-34h]
  float v91; // [esp+F0h] [ebp-30h]
  broad_phase_base **bpb_ptr_cur; // [esp+F4h] [ebp-2Ch]
  const float bpb_i_aabb_min; // [esp+F8h] [ebp-28h]
  broad_phase_base *bpb_cluster_list; // [esp+FCh] [ebp-24h]
  float v95; // [esp+100h] [ebp-20h]
  int *v96; // [esp+104h] [ebp-1Ch]
  int v97; // [esp+108h] [ebp-18h]
  void **v98; // [esp+10Ch] [ebp-14h]
  int v99; // [esp+110h] [ebp-10h]
  int v100; // [esp+114h] [ebp-Ch]
  int v101; // [esp+118h] [ebp-8h]
  int v102; // [esp+11Ch] [ebp-4h]
  int retaddr; // [esp+120h] [ebp+0h]

  v100 = a1;
  v101 = retaddr;
  v99 = -1;
  v98 = &_ehhandler__broad_phase_process_object_environment_collision__YAXAAVbpi_environment_collision_info___Z;
  v97 = v2;
  v96 = &v102;
  v3 = eci;
  if ( eci->m_bpb_count <= 0
    && _tlAssert("source/phys_broad_phase.cpp", 1007, "eci.m_bpb_count > 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  aabb2_max.w = 0.0;
  v74 = 0;
  v75 = 0;
  transient_buffer.m_first_block = NULL;
  transient_buffer.m_cur = (char *)1;
  transient_buffer.m_end = NULL;
  v99 = 0;
  *(float *)&v4 = COERCE_FLOAT(
                    phys_transient_allocator::allocate(
                      (phys_transient_allocator *)&aabb2_max.w,
                      4 * eci->m_bpb_count,
                      4,
                      0,
                      "phys_transient_allocator out of memory."));
  v5 = eci->m_bpb_i_start;
  v91 = *(float *)&v4;
  v89 = *(float *)&v4;
  if ( v5 != eci->m_bpb_i_end )
  {
    bpb_i_aabb_min = 0.0;
    do
    {
      if ( SLODWORD(bpb_i_aabb_min) >> 2 >= eci->m_bpb_count
        && _tlAssert(
             "source/phys_broad_phase.cpp",
             1022,
             "bpb_ptr_cur - bpb_ptr_list < eci.m_bpb_count",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v6 = v89;
      LODWORD(bpb_i_aabb_min) += 4;
      *(_DWORD *)LODWORD(v89) = v5;
      v5 = v5->m_list_bpb_next;
      LODWORD(v89) = LODWORD(v6) + 4;
    }
    while ( v5 != eci->m_bpb_i_end );
  }
  if ( (LODWORD(v89) - LODWORD(v91)) >> 2 != eci->m_bpb_count
    && _tlAssert(
         "source/phys_broad_phase.cpp",
         1029,
         "bpb_ptr_cur - bpb_ptr_list == eci.m_bpb_count",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v7 = (broad_phase_base **)LODWORD(v91);
  g_bpb_ptr_list = (struct broad_phase_base **)LODWORD(v91);
  v68 = 1.0e30;
  g_bpb_list_index = 0;
  *(float *)&bppti.m_aabb_min = 1.0e30;
  v8 = eci->m_bpb_count;
  *(float *)&bppti.m_aabb_max = 1.0e30;
  g_bpb_list_max_index = v8;
  v9 = eci->m_bpb_count;
  bp_aabb_min.y = -1.0e30;
  bp_aabb_min.z = -1.0e30;
  LODWORD(half_dims.w) = &v68;
  bp_aabb_min.w = -1.0e30;
  v67 = (phys_vec3 *)((char *)&bp_aabb_min + 4);
  phys_task_manager_process(&bp_env_jq_module1Module, &half_dims.w, v9);
  phys_task_manager_flush();
  v95 = bp_aabb_min.y - v68;
  *(float *)&bpb_cluster_list = bp_aabb_min.z - *(float *)&bppti.m_aabb_min;
  v91 = bp_aabb_min.w - *(float *)&bppti.m_aabb_max;
  if ( *(float *)&bpb_cluster_list > (double)v95 )
  {
    g_bpb_cluster_sort_axis = 1;
    if ( v91 <= (double)*(float *)&bpb_cluster_list )
      goto LABEL_18;
  }
  else if ( v91 <= (double)v95 )
  {
    g_bpb_cluster_sort_axis = 0;
    goto LABEL_18;
  }
  g_bpb_cluster_sort_axis = 2;
LABEL_18:
  merge_sort_bpb(v7, eci->m_bpb_count);
  G_BPM->g_list_bpb = *v7;
  v10 = (unsigned int)&v7[eci->m_bpb_count];
  eci->m_bpb_i_start = *v7;
  for ( i = v7; (unsigned int)i < v10; ++i )
    (*i)->m_list_bpb_next = i[1];
  (*(i - 1))->m_list_bpb_next = eci->m_bpb_i_end;
  v12 = eci->m_bpb_i_start;
  v13 = NULL;
  v91 = 0.0;
  bpb_cluster_head = NULL;
  if ( v12 != eci->m_bpb_i_end )
  {
    while ( v12->m_flags & 0x10 )
    {
LABEL_84:
      v12 = v12->m_list_bpb_next;
      if ( v12 == v3->m_bpb_i_end )
      {
        v13 = bpb_cluster_head;
        goto LABEL_86;
      }
    }
    if ( v12->m_list_bpb_cluster_next
      && _tlAssert("source/phys_broad_phase.cpp", 1095, "bpb_i->get_bpb_cluster_next() == NULL", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v12->m_flags |= 0x10u;
    v14 = v12->m_trace_aabb_min_whace.x;
    v15 = v12->m_trace_aabb_min_whace.y;
    v16 = v12->m_trace_aabb_min_whace.z;
    v95 = v12->m_trace_aabb_min_whace.x + v12->m_trace_translation.x;
    v17 = g_bpb_cluster_sort_axis;
    v18 = v12->m_trace_aabb_min_whace.y;
    aabb1_max.y = v14;
    v19 = v18 + v12->m_trace_translation.y;
    v20 = v12->m_trace_aabb_min_whace.w;
    aabb1_max.z = v15;
    v21 = LODWORD(v12->m_trace_aabb_max_whace.x);
    *(float *)&bpb_cluster_list = v19;
    aabb1_max.w = v16;
    v22 = LODWORD(v12->m_trace_aabb_max_whace.y);
    v23 = v12->m_trace_aabb_min_whace.z + v12->m_trace_translation.z;
    aabb1_min.x = v20;
    v24 = v12->m_trace_aabb_max_whace.z;
    transient_buffer.m_total_memory_allocated = v21;
    *(float *)&bpb_ptr_cur = v23;
    v25 = v12->m_trace_aabb_max_whace.w;
    transient_buffer.m_mutex.m_count = v22;
    bp_aabb_max.y = v95;
    v26 = v12->m_env_collision_flags;
    *(float *)&transient_buffer.m_slot_pool = v24;
    bp_aabb_max.z = *(float *)&bpb_cluster_list;
    aabb1_max.x = v25;
    v80 = v26;
    bp_aabb_max.w = *(float *)&bpb_ptr_cur;
    v79 = v12;
    v95 = v12->m_trace_aabb_max_whace.x + v12->m_trace_translation.x;
    *(float *)&bpb_cluster_list = v12->m_trace_aabb_max_whace.y + v12->m_trace_translation.y;
    *(float *)&bpb_ptr_cur = v12->m_trace_aabb_max_whace.z + v12->m_trace_translation.z;
    aabb2_min.y = v95;
    aabb2_min.z = *(float *)&bpb_cluster_list;
    aabb2_min.w = *(float *)&bpb_ptr_cur;
    if ( (g_bpb_cluster_sort_axis < 0 || g_bpb_cluster_sort_axis >= 3)
      && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h", 36, "i >= 0 && i < 3", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v27 = *(&v12->m_trace_aabb_min_whace.x + v17);
    v28 = (int)v12->m_list_bpb_next;
    for ( j = v27; (broad_phase_base *)v28 != eci->m_bpb_i_end; v28 = *(_DWORD *)(v28 + 52) )
    {
      v95 = *(float *)&g_bpb_cluster_sort_axis;
      if ( (g_bpb_cluster_sort_axis < 0 || g_bpb_cluster_sort_axis >= 3)
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h",
             36,
             "i >= 0 && i < 3",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v95 = *(float *)(v28 + 4 * LODWORD(v95));
      if ( v95 - j > 136.0 )
        break;
      if ( !(*(_BYTE *)(v28 + 48) & 0x10) )
      {
        if ( *(_DWORD *)(v28 + 56)
          && _tlAssert(
               "source/phys_broad_phase.cpp",
               1110,
               "bpb_j->get_bpb_cluster_next() == NULL",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v95 = *(float *)(v28 + 8);
        v29 = aabb1_max.w;
        if ( v95 < (double)aabb1_max.w )
          v29 = *(float *)(v28 + 8);
        *(float *)&env_collision_flags = v29;
        v95 = *(float *)(v28 + 4);
        v30 = aabb1_max.z;
        if ( v95 < (double)aabb1_max.z )
          v30 = *(float *)(v28 + 4);
        bpb_i_aabb_min = v30;
        v95 = *(float *)v28;
        v31 = aabb1_max.y;
        if ( v95 < (double)aabb1_max.y )
          v31 = *(float *)v28;
        v89 = v31;
        v95 = *(float *)(v28 + 24);
        v32 = *(float *)&transient_buffer.m_slot_pool;
        if ( v95 > (double)*(float *)&transient_buffer.m_slot_pool )
          v32 = *(float *)(v28 + 24);
        v84 = v32;
        v95 = *(float *)(v28 + 20);
        v33 = *(float *)&transient_buffer.m_mutex.m_count;
        if ( v95 > (double)*(float *)&transient_buffer.m_mutex.m_count )
          v33 = *(float *)(v28 + 20);
        v81 = v33;
        v95 = *(float *)(v28 + 16);
        v34 = *(float *)&transient_buffer.m_total_memory_allocated;
        if ( v95 > (double)*(float *)&transient_buffer.m_total_memory_allocated )
          v34 = *(float *)(v28 + 16);
        *(float *)&bpb_cluster_list_count = v34;
        v95 = *(float *)&bpb_cluster_list_count - v89;
        *(float *)&bpb_cluster_list = v81 - bpb_i_aabb_min;
        *(float *)&bpb_ptr_cur = v84 - *(float *)&env_collision_flags;
        if ( v95 <= 136.0 && *(float *)&bpb_cluster_list <= 136.0 && *(float *)&bpb_ptr_cur <= 136.0 )
        {
          v88 = *(float *)v28 + *(float *)(v28 + 32);
          *(float *)&bpb_cluster_list = *(float *)(v28 + 36) + *(float *)(v28 + 4);
          v95 = *(float *)(v28 + 40) + *(float *)(v28 + 8);
          v35 = bp_aabb_max.w;
          if ( v95 < (double)bp_aabb_max.w )
            v35 = v95;
          v95 = v35;
          v36 = bp_aabb_max.z;
          if ( *(float *)&bpb_cluster_list < (double)bp_aabb_max.z )
            v36 = *(float *)&bpb_cluster_list;
          *(float *)&bpb_ptr_cur = v36;
          v37 = bp_aabb_max.y;
          if ( v88 < (double)bp_aabb_max.y )
            v37 = v88;
          v86 = v37;
          v87 = *(float *)(v28 + 16) + *(float *)(v28 + 32);
          v88 = *(float *)(v28 + 20) + *(float *)(v28 + 36);
          *(float *)&bpb_cluster_list = *(float *)(v28 + 24) + *(float *)(v28 + 40);
          v38 = aabb2_min.w;
          if ( *(float *)&bpb_cluster_list > (double)aabb2_min.w )
            v38 = *(float *)&bpb_cluster_list;
          *(float *)&bpb_cluster_list = v38;
          v39 = aabb2_min.z;
          if ( v88 > (double)aabb2_min.z )
            v39 = v88;
          v88 = v39;
          v40 = aabb2_min.y;
          if ( v87 > (double)aabb2_min.y )
            v40 = v87;
          v87 = v40;
          v41 = v87;
          v42 = v86;
          v86 = v87 - v86;
          v43 = v88;
          v44 = *(float *)&bpb_ptr_cur;
          *(float *)&bpb_ptr_cur = v88 - *(float *)&bpb_ptr_cur;
          v45 = *(float *)&bpb_cluster_list;
          v46 = v95;
          v95 = *(float *)&bpb_cluster_list - v95;
          if ( v86 <= 136.0 && *(float *)&bpb_ptr_cur <= 136.0 && v95 <= 136.0 )
          {
            v47 = (int)v79;
            aabb1_max.y = v89;
            v48 = *(_DWORD *)(v28 + 68);
            v49 = bpb_i_aabb_min;
            *(_DWORD *)(v28 + 48) |= 0x10u;
            aabb1_max.z = v49;
            v80 |= v48;
            v50 = *(float *)&env_collision_flags;
            *(_DWORD *)(v28 + 56) = v47;
            aabb1_max.w = v50;
            v79 = (broad_phase_base *)v28;
            transient_buffer.m_total_memory_allocated = bpb_cluster_list_count;
            *(float *)&transient_buffer.m_mutex.m_count = v81;
            *(float *)&transient_buffer.m_slot_pool = v84;
            bp_aabb_max.y = v42;
            bp_aabb_max.z = v44;
            bp_aabb_max.w = v46;
            aabb2_min.y = v41;
            aabb2_min.z = v43;
            aabb2_min.w = v45;
          }
        }
      }
    }
    transient_allocator_update_largest_size(80);
    LODWORD(v51) = (v74 + 15) & 0xFFFFFFF0;
    if ( LODWORD(v51) + 80 <= v75 )
    {
      v74 = LODWORD(v51) + 80;
      bpb_i_aabb_min = v51;
      if ( v51 != 0.0 )
        goto LABEL_81;
    }
    phys_transient_allocator::resize((phys_transient_allocator *)&aabb2_max.w);
    LODWORD(v52) = (v74 + 15) & 0xFFFFFFF0;
    if ( LODWORD(v52) + 80 <= v75 )
    {
      v74 = LODWORD(v52) + 80;
      bpb_i_aabb_min = v52;
      if ( v52 != 0.0 )
        goto LABEL_81;
    }
    else
    {
      bpb_i_aabb_min = 0.0;
    }
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
    if ( bpb_i_aabb_min == 0.0 )
    {
      v53 = 0.0;
      goto LABEL_83;
    }
LABEL_81:
    v53 = bpb_i_aabb_min;
LABEL_83:
    bpb_cluster_head = (broad_phase_base *)((char *)bpb_cluster_head + 1);
    *(float *)(LODWORD(v53) + 52) = v91;
    v91 = v53;
    comp_trace_volume(
      (int)&v100,
      (phys_vec3 *)((char *)&aabb1_max + 4),
      (phys_vec3 *)&transient_buffer.m_total_memory_allocated,
      (phys_vec3 *)((char *)&bp_aabb_max + 4),
      (phys_vec3 *)((char *)&aabb2_min + 4),
      (phys_vec3 *)&v61,
      (phys_vec3 *)((char *)&p1 + 4),
      (phys_vec3 *)((char *)&p2 + 4));
    v54 = v61;
    v55 = p2.y;
    j = v61 - p2.y;
    v56 = v62;
    v57 = p2.z;
    v95 = v62 - p2.z;
    v58 = v63;
    v59 = p2.w;
    *(float *)&bpb_cluster_list = v63 - p2.w;
    *(float *)LODWORD(v53) = j;
    *(float *)(LODWORD(v53) + 4) = v95;
    *(float *)(LODWORD(v53) + 8) = *(float *)&bpb_cluster_list;
    j = v55 + v54;
    v95 = v57 + v56;
    *(float *)&bpb_cluster_list = v59 + v58;
    *(float *)(LODWORD(v53) + 16) = j;
    *(float *)(LODWORD(v53) + 20) = v95;
    *(float *)(LODWORD(v53) + 24) = *(float *)&bpb_cluster_list;
    j = p1.y - v54;
    v95 = p1.z - v56;
    *(float *)&bpb_cluster_list = p1.w - v58;
    *(float *)(LODWORD(v53) + 32) = j;
    *(float *)(LODWORD(v53) + 36) = v95;
    *(float *)(LODWORD(v53) + 40) = *(float *)&bpb_cluster_list;
    v60 = v80;
    *(_DWORD *)(LODWORD(v53) + 56) = v79;
    *(_DWORD *)(LODWORD(v53) + 68) = v60;
    v3 = eci;
    goto LABEL_84;
  }
LABEL_86:
  g_bpb_list_cur = (broad_phase_base *)LODWORD(v91);
  g_bpb_list_index = 0;
  g_bpb_list_max_index = (int)v13;
  g_thread_id = 0;
  phys_task_manager_process(&bp_env_jq_module2Module, NULL, (const int)v13);
  phys_task_manager_flush();
  phys_transient_allocator::reset((phys_transient_allocator *)&aabb2_max.w);
  v99 = -1;
  if ( LODWORD(aabb2_max.w) )
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
broad_phase_process_object_environment_collision
==============
*/
void broad_phase_process_object_environment_collision()
{
  int v0; // eax
  int v1; // eax
  int v2; // edx
  bpi_environment_collision_info eci; // [esp+0h] [ebp-10h]
  int savedregs; // [esp+10h] [ebp+0h]

  v0 = G_BPM->g_list_bpb_count;
  eci.m_bpb_i_start = G_BPM->g_list_bpb;
  eci.m_bpb_i_end = NULL;
  eci.m_bpb_count = v0;
  eci.m_bpb_last_count = v0;
  if ( v0 )
  {
    do
    {
      broad_phase_process_object_environment_collision((int)&savedregs, &eci);
      eci.m_bpb_i_end = eci.m_bpb_i_start;
      v1 = G_BPM->g_list_bpb_count;
      v2 = G_BPM->g_list_bpb_count - eci.m_bpb_last_count;
      eci.m_bpb_i_start = G_BPM->g_list_bpb;
      eci.m_bpb_count = v2;
      eci.m_bpb_last_count = v1;
    }
    while ( v2 );
  }
}

/*
==============
axis_aligned_sweep_and_prune::swap
==============
*/
void __thiscall axis_aligned_sweep_and_prune::swap(axis_aligned_sweep_and_prune *this, axis_aligned_sweep_and_prune::axis_element **a1_ptr, axis_aligned_sweep_and_prune::axis_element **a2_ptr)
{
  axis_aligned_sweep_and_prune::axis_element *v3; // esi
  axis_aligned_sweep_and_prune::axis_element *v4; // edi
  axis_aligned_sweep_and_prune::sap_node *v5; // ebx
  bool (__cdecl *v6)(broad_phase_base *, broad_phase_base *); // eax
  axis_aligned_sweep_and_prune *v7; // [esp+Ch] [ebp-4h]

  v3 = *a1_ptr;
  v7 = this;
  v4 = *a2_ptr;
  if ( (*a1_ptr)->m_node == (*a2_ptr)->m_node
    && _tlAssert("source/phys_broad_phase.cpp", 570, "a1->m_node != a2->m_node", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( v3->m_ae_list_index + 1 != v4->m_ae_list_index
    && _tlAssert(
         "source/phys_broad_phase.cpp",
         571,
         "a1->m_ae_list_index + 1 == a2->m_ae_list_index",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ++v3->m_ae_list_index;
  --v4->m_ae_list_index;
  if ( v3->m_min_max == 1 && !v4->m_min_max )
  {
    v5 = v4->m_node;
    if ( axis_aligned_sweep_and_prune::are_overlapping(v3->m_node, v4->m_node) )
    {
      v6 = v7->m_should_collide_callback;
      if ( !v6 || v6(v3->m_node->m_bpb, v5->m_bpb) )
        axis_aligned_sweep_and_prune::add_active_pair(v7, v3->m_node, v4->m_node);
    }
  }
  *a1_ptr = v4;
  *a2_ptr = v3;
}

/*
==============
axis_aligned_sweep_and_prune::merge_sort
==============
*/
void __thiscall axis_aligned_sweep_and_prune::merge_sort(axis_aligned_sweep_and_prune *this, axis_aligned_sweep_and_prune::axis_element **list, const int list_count)
{
  axis_aligned_sweep_and_prune *v3; // esi
  axis_aligned_sweep_and_prune::axis_element **v4; // ebx
  axis_aligned_sweep_and_prune::axis_element **v5; // edi
  axis_aligned_sweep_and_prune::axis_element **v6; // ecx
  axis_aligned_sweep_and_prune::axis_element **i; // esi
  axis_aligned_sweep_and_prune::axis_element **last; // [esp+8h] [ebp-8h]
  axis_aligned_sweep_and_prune *v9; // [esp+Ch] [ebp-4h]

  v3 = this;
  v9 = this;
  if ( list_count >= 3 )
  {
    axis_aligned_sweep_and_prune::merge_sort(this, list, list_count / 2);
    axis_aligned_sweep_and_prune::merge_sort(v3, &list[list_count / 2], list_count - list_count / 2);
    v4 = &list[list_count / 2];
    last = &list[list_count];
    v5 = v4 - 1;
    if ( v4 < last )
    {
      while ( (*v5)->m_val > (double)(*v4)->m_val )
      {
        axis_aligned_sweep_and_prune::swap(v3, v5, v4);
        v6 = v5;
        for ( i = v5 - 1; v6 > list; --i )
        {
          if ( (*i)->m_val <= (double)(*v6)->m_val )
            break;
          axis_aligned_sweep_and_prune::swap(v9, i, v6);
          v6 = i;
        }
        v5 = v4;
        ++v4;
        if ( v4 >= last )
          break;
        v3 = v9;
      }
    }
  }
  else if ( list_count == 2 && (*list)->m_val > (double)list[1]->m_val )
  {
    axis_aligned_sweep_and_prune::swap(this, list, list + 1);
  }
}

/*
==============
aasap_list_add
==============
*/
void aasap_list_add(broad_phase_base *bpb)
{
  axis_aligned_sweep_and_prune::create_sap_node(g_axis_aligned_sweep_and_prune, bpb);
}

/*
==============
aasap_list_remove
==============
*/
void aasap_list_remove(broad_phase_base *bpb)
{
  axis_aligned_sweep_and_prune::destroy_sap_node(g_axis_aligned_sweep_and_prune, bpb);
}

/*
==============
do_initial_tunnel_test
==============
*/
void __usercall do_initial_tunnel_test(int a1@<ebp>, broad_phase_group *bpg, broad_phase_environement_query_results *bpeqr)
{
  bool v3; // zf
  phys_vec3 ***v4; // edi
  broad_phase_info *v5; // esi
  phys_gjk_geomVtbl *v6; // eax
  int v7; // ecx
  phys_vec3 *v8; // edi
  int v9; // [esp+14h] [ebp-44Ch]
  phys_gjk_input pgi; // [esp+20h] [ebp-440h]
  int v11; // [esp+74h] [ebp-3ECh]
  broad_phase_info *v12; // [esp+78h] [ebp-3E8h]
  phys_vec3 *v13; // [esp+7Ch] [ebp-3E4h]
  phys_collision_pair pcp; // [esp+80h] [ebp-3E0h]
  phys_vec3 **v15; // [esp+94h] [ebp-3CCh]
  const float reduced_radius; // [esp+98h] [ebp-3C8h]
  phys_vec3 **v17; // [esp+9Ch] [ebp-3C4h]
  broad_phase_base_list::node *last_bpi_env_iter; // [esp+A0h] [ebp-3C0h]
  float hit_time; // [esp+A4h] [ebp-3BCh]
  phys_gjk_info gjk_info; // [esp+B0h] [ebp-3B0h]
  unsigned int v21; // [esp+450h] [ebp-10h]
  int v22; // [esp+454h] [ebp-Ch]
  int v23; // [esp+458h] [ebp-8h]
  int retaddr; // [esp+460h] [ebp+0h]

  v22 = a1;
  v23 = retaddr;
  v21 = (unsigned int)&v22 ^ __security_cookie;
  v3 = (bpg->m_flags & 0x200) == 0;
  v4 = (phys_vec3 ***)bpeqr;
  pcp.m_gjk_ci = (phys_gjk_cache_info *)bpeqr;
  if ( v3
    && _tlAssert(
         "source/phys_broad_phase.cpp",
         755,
         "bpg->get_flag(broad_phase_group::FLAG_DO_INITIAL_TUNNEL_TEST)",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  bpg->m_flags &= 0xFFFFFDFF;
  v5 = bpg->m_list_bpi_head;
  *(float *)&pcp.m_next_link = -1.0;
  for ( reduced_radius = 0.0; v5; v5 = (broad_phase_info *)v5->m_list_bpb_next )
  {
    v6 = v5->m_gjk_geom->vfptr;
    *(float *)&last_bpi_env_iter = 1.0;
    ((void (*)(void))v6->get_geom_radius)();
    v7 = (int)*v4[1];
    v17 = *v4;
    v15 = (phys_vec3 **)v7;
    pcp.m_hit_time = 1.0 * 0.8999999761581421 + 0.3400000035762787;
    if ( v17 != (phys_vec3 **)v7 )
    {
      do
      {
        v8 = *v17;
        if ( LODWORD((*v17)[4].y) & v5->m_env_collision_flags )
        {
          pgi.m_sep_thresh = v5->m_trace_translation.x - v8[2].x;
          *(float *)&pgi.m_intersection_test_only = v5->m_trace_translation.y - v8[2].y;
          *(float *)(&pgi.m_continuous_collision + 3) = v5->m_trace_translation.z - v8[2].z;
          if ( phys_are_potentially_colliding(
                 &v5->m_trace_aabb_min_whace,
                 &v5->m_trace_aabb_max_whace,
                 (phys_vec3 *)&pgi.m_sep_thresh,
                 v8,
                 v8 + 1,
                 (float *)&reduced_radius) )
          {
            *(float *)&pcp.m_next_link = reduced_radius;
            v12 = v5;
            v13 = v8;
            pcp.m_bpi1 = NULL;
            setup_gjk_input_from_pcp((phys_gjk_input *)&v9, (phys_collision_pair *)&v11);
            *(float *)&pgi.cg1_to_world_xform = pcp.m_hit_time;
            *(float *)&pgi.gjk_ci = 1.02;
            LOWORD(pgi.cg1_radius) = 256;
            if ( phys_gjk_info::phys_collide_do_gjk_collide((phys_gjk_info *)&hit_time, (phys_gjk_input *)&v9) )
            {
              *(float *)&pcp.m_bpi2 = gjk_info.cg1_cinfo_loc.m_p2.z * gjk_info.cg2_to_cg1_xform.w.z
                                    + gjk_info.cg1_cinfo_loc.m_p2.y * gjk_info.cg2_to_cg1_xform.w.y
                                    + gjk_info.cg1_cinfo_loc.m_p2.w * gjk_info.cg2_to_cg1_xform.w.w;
              if ( *(float *)&pcp.m_bpi2 < 0.0
                && *(float *)&last_bpi_env_iter > (double)gjk_info.m_cg1_relative_translation_loc.y )
              {
                last_bpi_env_iter = (broad_phase_base_list::node *)LODWORD(gjk_info.m_cg1_relative_translation_loc.y);
              }
            }
          }
        }
        v17 = (phys_vec3 **)v17[1];
      }
      while ( v17 != v15 );
      v4 = (phys_vec3 ***)pcp.m_gjk_ci;
    }
    rigid_body::adjust_col_moved_vec(v5->m_rb, *(const float *)&last_bpi_env_iter);
    broad_phase_info::collision_prolog(v5);
  }
}

/*
==============
create_broad_phase_info
==============
*/
broad_phase_info *create_broad_phase_info()
{
  return phys_free_list<broad_phase_info>::add(
           &G_BPM->g_list_broad_phase_info,
           0,
           "phys_free_list error: out of memory.");
}

/*
==============
destroy_broad_phase_info
==============
*/
void destroy_broad_phase_info(broad_phase_info *bpi)
{
  broad_phase_memory *v1; // edi

  environment_collision_list_remove((broad_phase_base *)&bpi->m_trace_aabb_min_whace);
  axis_aligned_sweep_and_prune::destroy_sap_node(
    g_axis_aligned_sweep_and_prune,
    (broad_phase_base *)&bpi->m_trace_aabb_min_whace);
  v1 = G_BPM;
  if ( bpi )
  {
    PMM_VALIDATE(&bpi[-1].m_gjk_geom, 0x90u, 0x10u);
    phys_free_list<broad_phase_info>::remove(
      &v1->g_list_broad_phase_info,
      (phys_free_list<broad_phase_info>::T_internal *)&bpi[-1].m_gjk_geom);
  }
}

/*
==============
destroy_broad_phase_info_list
==============
*/
void destroy_broad_phase_info_list(broad_phase_info *list_bpi)
{
  broad_phase_info *v1; // esi
  broad_phase_info *v2; // ebx
  broad_phase_memory *v3; // edi
  phys_free_list<broad_phase_info>::T_internal *v4; // esi
  phys_free_list<broad_phase_info>::T_internal_base *v5; // eax
  phys_free_list<broad_phase_info>::T_internal_base *v6; // ecx

  v1 = list_bpi;
  if ( list_bpi )
  {
    do
    {
      if ( v1->m_flags & 0x20
        && _tlAssert(
             "source/phys_broad_phase.cpp",
             130,
             "!bpi->get_flag(broad_phase_base::FLAG_ON_ENV_LIST)",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      if ( v1->m_sap_node
        && _tlAssert("source/phys_broad_phase.cpp", 131, "bpi->m_sap_node == NULL", (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v2 = (broad_phase_info *)v1->m_list_bpb_next;
      v3 = G_BPM;
      v4 = (phys_free_list<broad_phase_info>::T_internal *)&v1[-1].m_gjk_geom;
      PMM_VALIDATE(v4, 0x90u, 0x10u);
      if ( !v4 )
      {
        if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
      }
      --v3->g_list_broad_phase_info.m_list_count;
      phys_free_list<broad_phase_info>::debug_remove(&v3->g_list_broad_phase_info, v4);
      v5 = v4->m_next_T_internal;
      v6 = v4->m_prev_T_internal;
      v6->m_next_T_internal = v5;
      v5->m_prev_T_internal = v6;
      PMM_FREE(v4, 0x90u, 0x10u);
      v1 = v2;
    }
    while ( v2 );
  }
}

/*
==============
create_broad_phase_collision_pair
==============
*/
broad_phase_collision_pair *create_broad_phase_collision_pair()
{
  return phys_free_list<broad_phase_collision_pair>::add(
           &G_BPM->g_list_broad_phase_collision_pair,
           0,
           "phys_free_list error: out of memory.");
}

/*
==============
destroy_broad_phase_collision_pair
==============
*/
void destroy_broad_phase_collision_pair(broad_phase_collision_pair *bpcp)
{
  phys_free_list<broad_phase_collision_pair>::remove(&G_BPM->g_list_broad_phase_collision_pair, bpcp);
}

/*
==============
destroy_broad_phase_collision_pair_list
==============
*/
void destroy_broad_phase_collision_pair_list(broad_phase_collision_pair *list_bpcp)
{
  broad_phase_collision_pair *v1; // eax
  broad_phase_collision_pair *v2; // ebx
  broad_phase_memory *v3; // edi
  phys_free_list<broad_phase_collision_pair>::T_internal *v4; // esi
  phys_free_list<broad_phase_collision_pair>::T_internal_base *v5; // eax
  phys_free_list<broad_phase_collision_pair>::T_internal_base *v6; // ecx

  v1 = list_bpcp;
  if ( list_bpcp )
  {
    do
    {
      v2 = v1->m_next_bpcp;
      v3 = G_BPM;
      v4 = (phys_free_list<broad_phase_collision_pair>::T_internal *)&v1[-1].m_bpi2;
      PMM_VALIDATE(&v1[-1].m_bpi2, 0x18u, 4u);
      if ( !v4 )
      {
        if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
      }
      --v3->g_list_broad_phase_collision_pair.m_list_count;
      phys_free_list<broad_phase_collision_pair>::debug_remove(&v3->g_list_broad_phase_collision_pair, v4);
      v5 = v4->m_next_T_internal;
      v6 = v4->m_prev_T_internal;
      v6->m_next_T_internal = v5;
      v5->m_prev_T_internal = v6;
      PMM_FREE(v4, 0x18u, 4u);
      v1 = v2;
    }
    while ( v2 );
  }
}

/*
==============
create_broad_phase_group
==============
*/
broad_phase_group *create_broad_phase_group()
{
  return phys_free_list<broad_phase_group>::add(
           &G_BPM->g_list_broad_phase_group,
           0,
           "phys_free_list error: out of memory.");
}

/*
==============
destroy_broad_phase_group
==============
*/
void destroy_broad_phase_group(broad_phase_group *bpg)
{
  broad_phase_memory *v1; // edi

  environment_collision_list_remove((broad_phase_base *)&bpg->m_trace_aabb_min_whace);
  axis_aligned_sweep_and_prune::destroy_sap_node(
    g_axis_aligned_sweep_and_prune,
    (broad_phase_base *)&bpg->m_trace_aabb_min_whace);
  v1 = G_BPM;
  if ( bpg )
  {
    PMM_VALIDATE(&bpg[-1].m_list_bpi_head, 0x80u, 0x10u);
    phys_free_list<broad_phase_group>::remove(
      &v1->g_list_broad_phase_group,
      (phys_free_list<broad_phase_group>::T_internal *)&bpg[-1].m_list_bpi_head);
  }
}

/*
==============
bpi_do_gjk_intersect
==============
*/
bool __usercall bpi_do_gjk_intersect@<al>(int a1@<ebp>, broad_phase_info *p1, broad_phase_info *p2, const float hit_time)
{
  broad_phase_info *v4; // ecx
  int v6; // [esp-Ch] [ebp-42Ch]
  phys_gjk_input pgi; // [esp+0h] [ebp-420h]
  broad_phase_info *v8; // [esp+50h] [ebp-3D0h]
  phys_collision_pair pcp; // [esp+54h] [ebp-3CCh]
  unsigned int v10; // [esp+410h] [ebp-10h]
  int v11; // [esp+414h] [ebp-Ch]
  int v12; // [esp+418h] [ebp-8h]
  int retaddr; // [esp+420h] [ebp+0h]

  v11 = a1;
  v12 = retaddr;
  v10 = (unsigned int)&v11 ^ __security_cookie;
  if ( (hit_time < 0.0 || hit_time > 1.0)
    && _tlAssert("source/phys_broad_phase.cpp", 81, "hit_time >= 0.0f && hit_time <= 1.0f", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v4 = (broad_phase_info *)p2->m_gjk_geom_id;
  LODWORD(pcp.m_hit_time) = p1->m_gjk_geom_id;
  pcp.m_bpi2 = v4;
  if ( p1 == p2 && _tlAssert("source/phys_broad_phase.cpp", 86, "p1 && p2 && p1 != p2", (const char *)&pBlock) )
    __debugbreak();
  if ( (broad_phase_info *)LODWORD(pcp.m_hit_time) == pcp.m_bpi2
    && _tlAssert("source/phys_broad_phase.cpp", 87, "id1 != id2", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  *(float *)&pcp.m_next_link = hit_time;
  *(_DWORD *)(&pgi.m_continuous_collision + 3) = p1;
  v8 = p2;
  pcp.m_bpi1 = (broad_phase_info *)phys_heap_gjk_cache_system_avl_tree::get_gjk_cache_info_mutex(
                                     &G_BPM->g_phys_gjk_cache_system,
                                     LODWORD(pcp.m_hit_time),
                                     (unsigned int)pcp.m_bpi2,
                                     &G_BPM->g_bp_gjk_cache_mutex,
                                     1);
  setup_gjk_input_from_pcp((phys_gjk_input *)&v6, (phys_collision_pair *)&pgi.m_intersection_test_only);
  *(float *)&pgi.gjk_ci = 1.02;
  LOWORD(pgi.cg1_radius) = 257;
  return phys_gjk_info::phys_collide_do_gjk_collide((phys_gjk_info *)&pcp.m_gjk_ci, (phys_gjk_input *)&v6);
}

/*
==============
collide_bpi_environment
==============
*/
void __usercall collide_bpi_environment(broad_phase_base_list::node *a1@<ebp>, broad_phase_info *bpi, broad_phase_environement_query_results *bpeqr)
{
  broad_phase_base_list::node *v3; // eax
  broad_phase_base *v4; // esi
  unsigned __int8 (*v5)(void); // edx
  broad_phase_memory *v6; // eax
  bool v7; // zf
  broad_phase_memory *v8; // eax
  float v9; // [esp+1Ch] [ebp-3Ch]
  float v10; // [esp+20h] [ebp-38h]
  float v11; // [esp+24h] [ebp-34h]
  broad_phase_base_list::node *i; // [esp+34h] [ebp-24h]
  broad_phase_memory *v13; // [esp+38h] [ebp-20h]
  int v14; // [esp+3Ch] [ebp-1Ch]
  broad_phase_base_list::node *last_bpi_env_iter; // [esp+40h] [ebp-18h]
  void *v16; // [esp+44h] [ebp-14h]
  float v17; // [esp+48h] [ebp-10h]
  broad_phase_base_list::node *bpi_env_iter; // [esp+4Ch] [ebp-Ch]
  phys_auto_activate_callback *aac; // [esp+50h] [ebp-8h]
  phys_auto_activate_callback *retaddr; // [esp+58h] [ebp+0h]

  bpi_env_iter = a1;
  aac = retaddr;
  if ( bpeqr->m_env_collision_flags & bpi->m_env_collision_flags )
  {
    v3 = *bpeqr->m_list_bpi_env.m_list_cur;
    last_bpi_env_iter = bpeqr->m_list_bpi_env.m_list;
    for ( i = v3; last_bpi_env_iter != i; last_bpi_env_iter = last_bpi_env_iter->m_next )
    {
      v4 = last_bpi_env_iter->m_bpb;
      v17 = 0.0;
      if ( v4->m_env_collision_flags & bpi->m_env_collision_flags )
      {
        v9 = bpi->m_trace_translation.x - v4->m_trace_translation.x;
        v10 = bpi->m_trace_translation.y - v4->m_trace_translation.y;
        v11 = bpi->m_trace_translation.z - v4->m_trace_translation.z;
        if ( phys_are_potentially_colliding(
               &bpi->m_trace_aabb_min_whace,
               &bpi->m_trace_aabb_max_whace,
               (phys_vec3 *)&v9,
               &v4->m_trace_aabb_min_whace,
               &v4->m_trace_aabb_max_whace,
               &v17) )
        {
          if ( SLOBYTE(v4->m_flags) >= 0 )
            goto LABEL_17;
          v5 = **(unsigned __int8 (***)(void))v4->m_sap_node;
          v16 = v4->m_sap_node;
          if ( !v5() && bpi_do_gjk_intersect((int)&bpi_env_iter, bpi, (broad_phase_info *)v4, v17) )
          {
            tlAtomicMutex::Lock(&G_BPM->g_bp_auto_activate_mutex);
            if ( !(**(unsigned __int8 (***)(void))v16)() )
              (*(void (__stdcall **)(broad_phase_info *))(*(_DWORD *)v16 + 4))(bpi);
            v6 = G_BPM;
            v7 = G_BPM->g_bp_auto_activate_mutex.LockCount == 1;
            --v6->g_bp_auto_activate_mutex.LockCount;
            v13 = v6;
            if ( v7 )
            {
              v14 = 0;
              InterlockedExchange(&v14, 0);
              v8 = v13;
              LODWORD(v13->g_bp_auto_activate_mutex.ThreadId) = 0;
              HIDWORD(v8->g_bp_auto_activate_mutex.ThreadId) = 0;
            }
            if ( (*(unsigned __int8 (**)(void))(*(_DWORD *)v16 + 8))() )
LABEL_17:
              add_collision_pair_mutex(bpi, (broad_phase_info *)v4, v17, NULL);
          }
        }
      }
    }
  }
}

/*
==============
collide_bpg_environment
==============
*/
void __usercall collide_bpg_environment(broad_phase_base_list::node *a1@<ebp>, broad_phase_group *bpg, broad_phase_environement_query_results *bpeqr)
{
  broad_phase_group *v3; // edi
  broad_phase_base_list::node *v4; // ecx
  broad_phase_base *v5; // esi
  broad_phase_info *v6; // edi
  phys_wheel_collide_info *v7; // ecx
  broad_phase_memory *v8; // eax
  bool v9; // zf
  _DWORD *v10; // eax
  phys_wheel_collide_info *v11; // edi
  phys_wheel_collide_info *v12; // eax
  float v13; // [esp+18h] [ebp-6Ch]
  float v14; // [esp+1Ch] [ebp-68h]
  float v15; // [esp+20h] [ebp-64h]
  float v16; // [esp+28h] [ebp-5Ch]
  float v17; // [esp+2Ch] [ebp-58h]
  float v18; // [esp+30h] [ebp-54h]
  float v19; // [esp+38h] [ebp-4Ch]
  float v20; // [esp+3Ch] [ebp-48h]
  float v21; // [esp+40h] [ebp-44h]
  float v22; // [esp+48h] [ebp-3Ch]
  float v23; // [esp+4Ch] [ebp-38h]
  float v24; // [esp+50h] [ebp-34h]
  broad_phase_base_list::node *i; // [esp+60h] [ebp-24h]
  phys_wheel_collide_info *v26; // [esp+64h] [ebp-20h]
  int v27; // [esp+68h] [ebp-1Ch]
  broad_phase_base_list::node *last_bpi_env_iter; // [esp+6Ch] [ebp-18h]
  phys_wheel_collide_info *last_wci; // [esp+70h] [ebp-14h]
  float v30; // [esp+74h] [ebp-10h]
  broad_phase_base_list::node *bpi_env_iter; // [esp+78h] [ebp-Ch]
  phys_auto_activate_callback *aac; // [esp+7Ch] [ebp-8h]
  phys_auto_activate_callback *retaddr; // [esp+84h] [ebp+0h]

  bpi_env_iter = a1;
  aac = retaddr;
  v30 = 0.0;
  v3 = bpg;
  if ( bpeqr->m_env_collision_flags & bpg->m_env_collision_flags )
  {
    if ( bpg->m_flags & 0x200 )
      do_initial_tunnel_test((int)&bpi_env_iter, bpg, bpeqr);
    v4 = *bpeqr->m_list_bpi_env.m_list_cur;
    last_bpi_env_iter = bpeqr->m_list_bpi_env.m_list;
    for ( i = v4; last_bpi_env_iter != i; last_bpi_env_iter = last_bpi_env_iter->m_next )
    {
      v5 = last_bpi_env_iter->m_bpb;
      if ( last_bpi_env_iter->m_bpb->m_env_collision_flags & v3->m_env_collision_flags )
      {
        v22 = v3->m_trace_translation.x - v5->m_trace_translation.x;
        v23 = v3->m_trace_translation.y - v5->m_trace_translation.y;
        v24 = v3->m_trace_translation.z - v5->m_trace_translation.z;
        if ( phys_are_potentially_colliding(
               &v3->m_trace_aabb_min_whace,
               &v3->m_trace_aabb_max_whace,
               (phys_vec3 *)&v22,
               &v5->m_trace_aabb_min_whace,
               &v5->m_trace_aabb_max_whace,
               &v30) )
        {
          v6 = v3->m_list_bpi_head;
          if ( SLOBYTE(v5->m_flags) >= 0 )
          {
            for ( ; v6; v6 = (broad_phase_info *)v6->m_list_bpb_next )
            {
              if ( v6->m_env_collision_flags & v5->m_env_collision_flags )
              {
                v16 = v6->m_trace_translation.x - v5->m_trace_translation.x;
                v17 = v6->m_trace_translation.y - v5->m_trace_translation.y;
                v18 = v6->m_trace_translation.z - v5->m_trace_translation.z;
                if ( phys_are_potentially_colliding(
                       &v6->m_trace_aabb_min_whace,
                       &v6->m_trace_aabb_max_whace,
                       (phys_vec3 *)&v16,
                       &v5->m_trace_aabb_min_whace,
                       &v5->m_trace_aabb_max_whace,
                       &v30) )
                {
                  add_collision_pair_mutex(v6, (broad_phase_info *)v5, v30, NULL);
                }
              }
            }
            if ( bpg->m_rbvm )
            {
              if ( !bpg->m_list_wci
                && _tlAssert("source/phys_broad_phase.cpp", 837, "bpg->m_list_wci", (const char *)&pBlock) )
              {
                __debugbreak();
              }
              v11 = bpg->m_list_wci;
              v26 = &v11[bpg->m_rbvm->m_wheels.m_alloc_count];
              if ( v11 != v26 )
              {
                v12 = (phys_wheel_collide_info *)((char *)v11 + 24);
                for ( last_wci = (phys_wheel_collide_info *)((char *)v11 + 24); ; v12 = last_wci )
                {
                  v13 = *((float *)&v12[-1].m_hit_bpi + 1) - v5->m_trace_translation.x;
                  v14 = *((float *)&v12[-1].m_hit_bpi + 2) - v5->m_trace_translation.y;
                  v15 = v12->m_ray_pos.x - v5->m_trace_translation.z;
                  if ( phys_are_potentially_colliding(
                         &v11->m_ray_pos,
                         &v11->m_ray_pos,
                         (phys_vec3 *)&v13,
                         &v5->m_trace_aabb_min_whace,
                         &v5->m_trace_aabb_max_whace,
                         &v30) )
                  {
                    phys_wheel_collide_info::collision_process(
                      v11,
                      (int)&bpi_env_iter,
                      (int)v11,
                      (int)v5,
                      (broad_phase_info *)v5);
                  }
                  ++last_wci;
                  ++v11;
                  if ( v11 == v26 )
                    break;
                }
              }
            }
          }
          else
          {
            v7 = (phys_wheel_collide_info *)v5->m_sap_node;
            last_wci = (phys_wheel_collide_info *)v5->m_sap_node;
            if ( v6 )
            {
              while ( !(*(unsigned __int8 (**)(void))LODWORD(v7->m_ray_pos.x))() )
              {
                if ( v6->m_env_collision_flags & v5->m_env_collision_flags )
                {
                  v19 = v6->m_trace_translation.x - v5->m_trace_translation.x;
                  v20 = v6->m_trace_translation.y - v5->m_trace_translation.y;
                  v21 = v6->m_trace_translation.z - v5->m_trace_translation.z;
                  if ( phys_are_potentially_colliding(
                         &v6->m_trace_aabb_min_whace,
                         &v6->m_trace_aabb_max_whace,
                         (phys_vec3 *)&v19,
                         &v5->m_trace_aabb_min_whace,
                         &v5->m_trace_aabb_max_whace,
                         &v30) )
                  {
                    if ( bpi_do_gjk_intersect((int)&bpi_env_iter, v6, (broad_phase_info *)v5, v30) )
                    {
                      tlAtomicMutex::Lock(&G_BPM->g_bp_auto_activate_mutex);
                      if ( !(*(unsigned __int8 (**)(void))LODWORD(last_wci->m_ray_pos.x))() )
                        (*(void (__stdcall **)(broad_phase_info *))(LODWORD(last_wci->m_ray_pos.x) + 4))(v6);
                      v8 = G_BPM;
                      v9 = G_BPM->g_bp_auto_activate_mutex.LockCount == 1;
                      --v8->g_bp_auto_activate_mutex.LockCount;
                      v26 = (phys_wheel_collide_info *)v8;
                      if ( v9 )
                      {
                        v27 = 0;
                        InterlockedExchange(&v27, 0);
                        v10 = (_DWORD *)&v26->m_ray_pos.x;
                        v26->m_ray_pos.x = 0.0;
                        v10[1] = 0;
                      }
                    }
                  }
                }
                v6 = (broad_phase_info *)v6->m_list_bpb_next;
                if ( !v6 )
                  break;
                v7 = last_wci;
              }
            }
          }
          v3 = bpg;
        }
      }
    }
  }
  broad_phase_group::collision_epilog(v3);
}

/*
==============
bp_env_jq_batch_function2
==============
*/
int __usercall bp_env_jq_batch_function2@<eax>(int a1@<ebp>)
{
  broad_phase_base_list::node *v1; // eax
  broad_phase_base *v2; // esi
  double v3; // st6
  float v5; // [esp-Ch] [ebp-8Ch]
  float v6; // [esp-8h] [ebp-88h]
  float v7; // [esp-4h] [ebp-84h]
  broad_phase_environment_query_input bpeqi; // [esp+0h] [ebp-80h]
  int v9; // [esp+40h] [ebp-40h]
  int *v10; // [esp+44h] [ebp-3Ch]
  int v11; // [esp+48h] [ebp-38h]
  broad_phase_environement_query_results bpeqr; // [esp+4Ch] [ebp-34h]
  float v13; // [esp+64h] [ebp-1Ch]
  float v14; // [esp+68h] [ebp-18h]
  float v15; // [esp+6Ch] [ebp-14h]
  int v16; // [esp+74h] [ebp-Ch]
  int v17; // [esp+78h] [ebp-8h]
  int retaddr; // [esp+80h] [ebp+0h]

  v16 = a1;
  v17 = retaddr;
  v1 = (broad_phase_base_list::node *)_InterlockedExchangeAdd(&g_thread_id, 1u);
  v2 = g_bpb_list_cur;
  v9 = 0;
  v10 = &v9;
  for ( bpeqr.m_list_bpi_env.m_list = v1; g_bpb_list_cur; v2 = g_bpb_list_cur )
  {
    if ( (broad_phase_base *)_InterlockedCompareExchange(
                               (volatile signed __int32 *)&g_bpb_list_cur,
                               (signed __int32)v2->m_list_bpb_next,
                               (signed __int32)v2) == v2 )
    {
      check_terrain_query_params(v2);
      v11 = 0;
      bpeqr.m_list_bpi_env.m_list_cur = NULL;
      v10 = &v9;
      v3 = v2->m_trace_aabb_min_whace.x - 0.5099999904632568;
      LODWORD(bpeqi.trace_translation.y) = v2->m_env_collision_flags;
      v13 = v3;
      v14 = v2->m_trace_aabb_min_whace.y - 0.5099999904632568;
      v15 = v2->m_trace_aabb_min_whace.z - 0.5099999904632568;
      v5 = v13;
      v6 = v14;
      v7 = v15;
      *(float *)&bpeqr.m_list_bpi_env_count = v2->m_trace_aabb_max_whace.x + 0.5099999904632568;
      *(float *)&bpeqr.m_thread_id = v2->m_trace_aabb_max_whace.y + 0.5099999904632568;
      *(float *)&bpeqr.m_env_collision_flags = v2->m_trace_aabb_max_whace.z + 0.5099999904632568;
      bpeqi.trace_aabb_min_wace.y = *(float *)&bpeqr.m_list_bpi_env_count;
      bpeqi.trace_aabb_min_wace.z = *(float *)&bpeqr.m_thread_id;
      bpeqi.trace_aabb_min_wace.w = *(float *)&bpeqr.m_env_collision_flags;
      bpeqi.trace_aabb_max_wace.y = v2->m_trace_translation.x;
      bpeqi.trace_aabb_max_wace.z = v2->m_trace_translation.y;
      bpeqi.trace_aabb_max_wace.w = v2->m_trace_translation.z;
      ((void (__stdcall *)(float *, int *))G_BPM->g_broad_phase_terrain_query_callback->vfptr->query)(&v5, &v9);
      process_cluster_environment_collision(v2, (broad_phase_environement_query_results *)&v9);
    }
  }
  return 0;
}

/*
==============
broad_phase_process
==============
*/
void __usercall broad_phase_process(int a1@<ebp>)
{
  broad_phase_memory *v1; // eax
  phys_link_list<phys_collision_pair> *v2; // eax
  broad_phase_base *i; // edi
  broad_phase_base **v4; // esi
  broad_phase_base *v5; // ecx
  broad_phase_memory *v6; // edx
  phys_collision_pair *j; // esi
  int v8; // eax
  phys_link_list<phys_collision_pair> *v9; // eax
  float v10; // [esp-20h] [ebp-2Ch]
  float v11; // [esp-1Ch] [ebp-28h]
  float v12; // [esp-18h] [ebp-24h]
  float v13; // [esp-10h] [ebp-1Ch]
  float v14; // [esp-Ch] [ebp-18h]
  float v15; // [esp-8h] [ebp-14h]
  int v16; // [esp+0h] [ebp-Ch]
  int v17; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v16 = a1;
  v17 = retaddr;
  v1 = G_BPM;
  G_BPM->m_list_bpi_env = NULL;
  v1->m_bpi_env_count = 0;
  v1->m_bpg_env_count = 0;
  v1->m_bpg_env_bpi_count = 0;
  v1->m_bpi_env_no_database_count = 0;
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
  if ( G_BPM->g_collision_memory_buffer.m_cur
    && _tlAssert(
         "source/phys_broad_phase.cpp",
         1222,
         "G_BPM->g_collision_memory_buffer.is_empty()",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v2 = &G_BPM->g_list_phys_collide_data;
  v2->m_first = NULL;
  v2->m_last_next_ptr = &v2->m_first;
  v2->m_alloc_count = 0;
  broad_phase_process_object_environment_collision();
  broad_phase_process_collision_pairs();
  for ( i = G_BPM->g_list_bpb; i; i = i->m_list_bpb_next )
  {
    v4 = (broad_phase_base **)i->m_sap_node;
    if ( v4 )
    {
      if ( v4[31] && _tlAssert("source/phys_broad_phase.cpp", 225, "m_updated == 0", (const char *)&pBlock) )
        __debugbreak();
      v5 = *v4;
      v4[31] = (broad_phase_base *)1;
      broad_phase_base::get_aabb(v5, (int)&v16, (phys_vec3 *)&v10);
      *((float *)v4 + 3) = v10;
      *((float *)v4 + 8) = v13;
      *((float *)v4 + 13) = v11;
      *((float *)v4 + 18) = v14;
      *((float *)v4 + 23) = v12;
      *((float *)v4 + 28) = v15;
    }
  }
  axis_aligned_sweep_and_prune::process(g_axis_aligned_sweep_and_prune);
  v6 = G_BPM;
  for ( j = G_BPM->g_list_phys_collide_data.m_first; j; j = j->m_next_link )
  {
    if ( !j->m_gjk_ci )
    {
      j->m_gjk_ci = (phys_gjk_cache_info *)phys_heap_gjk_cache_system_avl_tree::get_gjk_cache_info(
                                             &v6->g_phys_gjk_cache_system,
                                             j->m_bpi1->m_gjk_geom_id,
                                             j->m_bpi2->m_gjk_geom_id,
                                             1);
      v6 = G_BPM;
    }
  }
  v8 = v6->g_collision_memory_buffer.m_total_memory_allocated;
  if ( v6->m_memory_high_water > v8 )
    v8 = v6->m_memory_high_water;
  v6->m_memory_high_water = v8;
  process_list_do_gjk_collide_and_contact_manifold(&G_BPM->g_list_phys_collide_data);
  v9 = &G_BPM->g_list_phys_collide_data;
  v9->m_first = NULL;
  v9->m_last_next_ptr = &v9->m_first;
  v9->m_alloc_count = 0;
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
  phys_heap_gjk_cache_system_avl_tree::update_cache(&G_BPM->g_phys_gjk_cache_system);
  bpei_database_t::update_database(&G_BPM->g_bpei_database);
}

/*
==============
broad_phase_system_init
==============
*/
void broad_phase_system_init(broad_phase_memory_info *bpmi, bool (*should_collide_callback)(broad_phase_base *, broad_phase_base *))
{
  axis_aligned_sweep_and_prune *v2; // eax
  broad_phase_memory *v3; // esi
  phys_free_list<broad_phase_info> *v4; // ecx

  break_here_44 = 1;
  G_BPM = broad_phase_memory::allocate_buffer(bpmi);
  v2 = (axis_aligned_sweep_and_prune *)PMM_PERM_ALLOCATE(0x28u, 4u);
  if ( v2 )
  {
    v2->m_sap_node_allocator.m_count = 0;
    v2->m_active_pair_allocator.m_count = 0;
  }
  else
  {
    v2 = NULL;
  }
  v3 = G_BPM;
  g_axis_aligned_sweep_and_prune = v2;
  v4 = &G_BPM->g_list_broad_phase_info;
  G_BPM->g_broad_phase_terrain_query_callback = NULL;
  v3->g_list_bpb = NULL;
  v3->g_list_bpb_count = 0;
  phys_free_list<broad_phase_info>::remove_all(v4);
  phys_free_list<rigid_body_constraint_distance>::remove_all(&v3->g_list_broad_phase_group);
  phys_free_list<broad_phase_collision_pair>::remove_all(&v3->g_list_broad_phase_collision_pair);
  bpei_database_t::purge_database(&v3->g_bpei_database);
  v3->m_memory_high_water = 0;
  axis_aligned_sweep_and_prune::init_system(g_axis_aligned_sweep_and_prune, bpmi->m_max_num_sap_active_pairs);
  g_axis_aligned_sweep_and_prune->m_should_collide_callback = should_collide_callback;
}

/*
==============
broad_phase_system_shutdown
==============
*/
void broad_phase_system_shutdown()
{
  broad_phase_memory::~broad_phase_memory(G_BPM);
  G_BPM = NULL;
  g_axis_aligned_sweep_and_prune = NULL;
}

/*
==============
broad_phase_group::collision_epilog
==============
*/
void __thiscall broad_phase_group::collision_epilog(broad_phase_group *this)
{
  broad_phase_group *v1; // edi
  int v2; // esi
  phys_wheel_collide_info *v3; // ebx
  rb_vehicle_model *v4; // edi
  int wheel_count; // [esp+8h] [ebp-Ch]
  broad_phase_group *v6; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h]
  int savedregs; // [esp+14h] [ebp+0h]

  v1 = this;
  v2 = 0;
  v6 = this;
  if ( this->m_rbvm )
  {
    if ( !this->m_list_wci && _tlAssert("source/phys_broad_phase.cpp", 69, "m_list_wci", (const char *)&pBlock) )
      __debugbreak();
    wheel_count = v1->m_rbvm->m_wheels.m_alloc_count;
    if ( wheel_count > 0 )
    {
      v7 = 0;
      while ( 1 )
      {
        v3 = &v1->m_list_wci[v7];
        v4 = v1->m_rbvm;
        if ( v2 < 0 || v2 >= v4->m_wheels.m_alloc_count )
        {
          if ( _tlAssert(
                 "c:\\t6\\code\\tl\\physics\\include\\phys_array_base.inc",
                 118,
                 "i >= 0 && i < m_alloc_count",
                 (const char *)&pBlock) )
          {
            __debugbreak();
          }
        }
        phys_wheel_collide_info::collision_epilog(v3, (int)&savedregs, v4->m_wheels.m_slot_array[v2]);
        ++v7;
        if ( ++v2 >= wheel_count )
          break;
        v1 = v6;
      }
    }
  }
}

/*
==============
axis_aligned_sweep_and_prune::init_system
==============
*/
void __thiscall axis_aligned_sweep_and_prune::init_system(axis_aligned_sweep_and_prune *this, const int max_num_active_pairs)
{
  axis_aligned_sweep_and_prune *v2; // esi

  v2 = this;
  if ( this->m_active_pair_allocator.m_count
    && _tlAssert("source/phys_broad_phase.cpp", 347, "m_active_pair_allocator.get_count() == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( v2->m_sap_node_allocator.m_count
    && _tlAssert("source/phys_broad_phase.cpp", 348, "m_sap_node_allocator.get_count() == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v2->m_x_list = NULL;
  v2->m_y_list = NULL;
  v2->m_z_list = NULL;
  v2->m_list_bpi_bpi = NULL;
  v2->m_list_bpi_bpg = NULL;
  v2->m_list_bpg_bpg = NULL;
  v2->m_max_num_active_pairs = max_num_active_pairs;
}

/*
==============
process_cluster_environment_collision_prolog
==============
*/
void __usercall process_cluster_environment_collision_prolog(int a1@<ebp>, broad_phase_base *bpb, broad_phase_base *info)
{
  unsigned int v3; // eax
  phys_vec3 *v4; // eax
  float *v5; // edi
  phys_vec3 *v6; // eax
  int v7; // [esp-10h] [ebp-1Ch]
  int v8; // [esp+0h] [ebp-Ch]
  int v9; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v8 = a1;
  v9 = retaddr;
  v3 = bpb->m_flags;
  if ( v3 & 1 )
  {
    broad_phase_info::collision_prolog((broad_phase_info *)bpb);
  }
  else
  {
    if ( !(v3 & 2)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_base.h",
           102,
           "is_bpg()",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    broad_phase_group::collision_prolog((broad_phase_group *)bpb, (int)&v8);
  }
  bpb->m_flags &= 0xFFFFFFEF;
  bpb->m_list_bpb_cluster_next = NULL;
  v4 = phys_min((phys_vec3 *)&v7, &info->m_trace_aabb_min_whace, &bpb->m_trace_aabb_min_whace);
  info->m_trace_aabb_min_whace.x = v4->x;
  info->m_trace_aabb_min_whace.y = v4->y;
  v5 = &info->m_trace_aabb_max_whace.x;
  *(v5 - 2) = v4->z;
  v6 = phys_max((phys_vec3 *)&v7, &info->m_trace_aabb_max_whace, &bpb->m_trace_aabb_max_whace);
  *v5 = v6->x;
  v5[1] = v6->y;
  v5[2] = v6->z;
}

/*
==============
compare_bpb
==============
*/
BOOL compare_bpb(broad_phase_base *bpb1, broad_phase_base *bpb2)
{
  signed int v2; // eax
  int v3; // esi
  double v4; // st7
  signed int v5; // esi
  float bpb1a; // [esp+Ch] [ebp+8h]

  v2 = g_bpb_cluster_sort_axis;
  v3 = g_bpb_cluster_sort_axis;
  if ( g_bpb_cluster_sort_axis < 0 || g_bpb_cluster_sort_axis >= 3 )
  {
    if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h", 36, "i >= 0 && i < 3", (const char *)&pBlock) )
      __debugbreak();
    v2 = g_bpb_cluster_sort_axis;
  }
  v4 = *(&bpb1->m_trace_aabb_min_whace.x + v3);
  v5 = v2;
  if ( v2 < 0 || v2 >= 3 )
  {
    if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h", 36, "i >= 0 && i < 3", (const char *)&pBlock) )
      __debugbreak();
  }
  bpb1a = v4;
  return *(&bpb2->m_trace_aabb_min_whace.x + v5) > (double)bpb1a;
}

/*
==============
add_collision_pair
==============
*/
void add_collision_pair(broad_phase_info *bpi1, broad_phase_info *bpi2, const float hit_time, phys_gjk_cache_info *gjk_ci)
{
  char *v4; // eax
  char *v5; // esi
  broad_phase_memory *v6; // edi
  phys_collision_pair **v7; // eax

  if ( (hit_time < 0.0 || hit_time > 1.0)
    && _tlAssert("source/phys_broad_phase.cpp", 11, "hit_time >= 0.0f && hit_time <= 1.0f", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v4 = phys_transient_allocator::allocate(
         &G_BPM->g_collision_memory_buffer,
         20,
         4,
         0,
         "phys_transient_allocator out of memory.");
  if ( v4 )
  {
    v5 = v4;
    *((float *)v4 + 3) = -1.0;
  }
  else
  {
    v5 = NULL;
  }
  *((const float *)v5 + 3) = hit_time;
  *((_DWORD *)v5 + 1) = bpi1;
  *((_DWORD *)v5 + 2) = bpi2;
  *((_DWORD *)v5 + 4) = gjk_ci;
  v6 = G_BPM;
  if ( !G_BPM->g_list_phys_collide_data.m_last_next_ptr
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 230, "m_last_next_ptr", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  *(_DWORD *)v5 = 0;
  v7 = v6->g_list_phys_collide_data.m_last_next_ptr;
  ++v6->g_list_phys_collide_data.m_alloc_count;
  *v7 = (phys_collision_pair *)v5;
  v6->g_list_phys_collide_data.m_last_next_ptr = (phys_collision_pair **)v5;
}

/*
==============
add_collision_pair_mutex
==============
*/
void add_collision_pair_mutex(broad_phase_info *bpi1, broad_phase_info *bpi2, const float hit_time, phys_gjk_cache_info *gjk_ci)
{
  phys_collision_pair *v4; // eax

  if ( (hit_time < 0.0 || hit_time > 1.0)
    && _tlAssert("source/phys_broad_phase.cpp", 23, "hit_time >= 0.0f && hit_time <= 1.0f", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v4 = (phys_collision_pair *)phys_transient_allocator::mt_allocate(
                                &G_BPM->g_collision_memory_buffer,
                                20,
                                4,
                                0,
                                "broad phase collision out of memory.");
  if ( v4 )
    v4->m_hit_time = -1.0;
  else
    v4 = NULL;
  v4->m_hit_time = hit_time;
  v4->m_bpi1 = bpi1;
  v4->m_gjk_ci = gjk_ci;
  v4->m_bpi2 = bpi2;
  phys_link_list<phys_collision_pair>::add_mt(&G_BPM->g_list_phys_collide_data, v4);
}

/*
==============
axis_aligned_sweep_and_prune::add_active_pair
==============
*/
void __thiscall axis_aligned_sweep_and_prune::add_active_pair(axis_aligned_sweep_and_prune *this, axis_aligned_sweep_and_prune::sap_node *p1, axis_aligned_sweep_and_prune::sap_node *p2)
{
  axis_aligned_sweep_and_prune *v3; // esi
  axis_aligned_sweep_and_prune::active_pair *v4; // eax

  v3 = this;
  if ( this->m_active_pair_allocator.m_count >= this->m_max_num_active_pairs )
  {
    if ( (pai_max_num_sap_active_pair.m_hits_total_count < dword_10E5878 || !dword_10E5878)
      && dword_10E5874 < dword_10E587C )
    {
      if ( byte_10E5880 )
      {
        PHYS_WARNING(
          "source/phys_broad_phase.cpp",
          309,
          "m_active_pair_allocator.get_count() < m_max_num_active_pairs",
          "max num sap active pairs reached.");
      }
      else if ( _tlAssert(
                  "source/phys_broad_phase.cpp",
                  309,
                  "m_active_pair_allocator.get_count() < m_max_num_active_pairs",
                  "max num sap active pairs reached.") )
      {
        __debugbreak();
      }
    }
    _InterlockedExchangeAdd(&pai_max_num_sap_active_pair.m_hits_total_count, 1u);
    _InterlockedExchangeAdd(&dword_10E5874, 1u);
  }
  if ( v3->m_active_pair_allocator.m_count < v3->m_max_num_active_pairs )
  {
    v4 = (axis_aligned_sweep_and_prune::active_pair *)PMM_ALLOC(0x10u, 4u);
    if ( v4 )
    {
      ++v3->m_active_pair_allocator.m_count;
      v4->m_p1 = p1;
      v4->m_p2 = p2;
      v4->m_gjk_ci = NULL;
      if ( p1->m_bpb->m_flags & 1 )
      {
        if ( p2->m_bpb->m_flags & 1 )
        {
          v4->m_next = v3->m_list_bpi_bpi;
          v3->m_list_bpi_bpi = v4;
        }
        else
        {
          v4->m_next = v3->m_list_bpi_bpg;
          v3->m_list_bpi_bpg = v4;
        }
      }
      else if ( p2->m_bpb->m_flags & 1 )
      {
        v4->m_p1 = p2;
        v4->m_p2 = p1;
        v4->m_gjk_ci = NULL;
        v4->m_next = v3->m_list_bpi_bpg;
        v3->m_list_bpi_bpg = v4;
      }
      else
      {
        v4->m_next = v3->m_list_bpg_bpg;
        v3->m_list_bpg_bpg = v4;
      }
    }
    else
    {
      if ( (pai_create_sap_active_pair.m_hits_total_count < dword_10E5890 || !dword_10E5890)
        && dword_10E588C < dword_10E5894 )
      {
        if ( byte_10E5898 )
        {
          PHYS_WARNING("source/phys_broad_phase.cpp", 313, "ap", "list sap active pairs out of memory.");
        }
        else if ( _tlAssert("source/phys_broad_phase.cpp", 313, "ap", "list sap active pairs out of memory.") )
        {
          __debugbreak();
        }
      }
      _InterlockedExchangeAdd(&pai_create_sap_active_pair.m_hits_total_count, 1u);
      _InterlockedExchangeAdd(&dword_10E588C, 1u);
    }
  }
}

/*
==============
axis_aligned_sweep_and_prune::create_sap_node
==============
*/
void __thiscall axis_aligned_sweep_and_prune::create_sap_node(axis_aligned_sweep_and_prune *this, broad_phase_base *bpb)
{
  axis_aligned_sweep_and_prune *v2; // esi
  axis_aligned_sweep_and_prune::sap_node *v3; // eax
  axis_aligned_sweep_and_prune::sap_node *v4; // edi

  v2 = this;
  if ( bpb->m_sap_node
    && _tlAssert("source/phys_broad_phase.cpp", 496, "bpb->m_sap_node == NULL", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v3 = (axis_aligned_sweep_and_prune::sap_node *)PMM_ALLOC(0x80u, 4u);
  if ( v3 )
  {
    ++v2->m_sap_node_allocator.m_count;
    v4 = v3;
  }
  else
  {
    v4 = NULL;
  }
  axis_aligned_sweep_and_prune::sap_node::init(v4, bpb, &v2->m_x_list, &v2->m_y_list, &v2->m_z_list);
  bpb->m_sap_node = v4;
}

/*
==============
axis_aligned_sweep_and_prune::remove
==============
*/
void __thiscall axis_aligned_sweep_and_prune::remove(axis_aligned_sweep_and_prune *this, axis_aligned_sweep_and_prune::active_pair **list_ap, axis_aligned_sweep_and_prune::sap_node *node)
{
  axis_aligned_sweep_and_prune::active_pair *v3; // esi
  phys_gjk_cache_info *v4; // edi
  broad_phase_memory *v5; // ebx
  axis_aligned_sweep_and_prune *i; // [esp+4h] [ebp-4h]

  v3 = *list_ap;
  for ( i = this; *list_ap; v3 = *list_ap )
  {
    if ( v3->m_p1 == node || v3->m_p2 == node )
    {
      *list_ap = v3->m_next;
      v4 = v3->m_gjk_ci;
      v5 = G_BPM;
      if ( v4 )
      {
        PMM_VALIDATE(v4, 0x90u, 0x10u);
        --v5->g_phys_gjk_cache_system.m_list_phys_gjk_cache_info_internal.m_count;
        PMM_FREE(v4, 0x90u, 0x10u);
      }
      PMM_VALIDATE(v3, 0x10u, 4u);
      --i->m_active_pair_allocator.m_count;
      PMM_FREE(v3, 0x10u, 4u);
    }
    else
    {
      list_ap = &v3->m_next;
    }
  }
}

/*
==============
axis_aligned_sweep_and_prune::destroy_sap_node
==============
*/
void __thiscall axis_aligned_sweep_and_prune::destroy_sap_node(axis_aligned_sweep_and_prune *this, broad_phase_base *bpb)
{
  axis_aligned_sweep_and_prune::sap_node *v2; // edi
  axis_aligned_sweep_and_prune *v3; // esi

  v2 = (axis_aligned_sweep_and_prune::sap_node *)bpb->m_sap_node;
  v3 = this;
  if ( v2 )
  {
    axis_aligned_sweep_and_prune::remove(
      this,
      &this->m_list_bpi_bpi,
      (axis_aligned_sweep_and_prune::sap_node *)bpb->m_sap_node);
    axis_aligned_sweep_and_prune::remove(v3, &v3->m_list_bpi_bpg, v2);
    axis_aligned_sweep_and_prune::remove(v3, &v3->m_list_bpg_bpg, v2);
    axis_aligned_sweep_and_prune::remove(&v3->m_x_list, v2);
    axis_aligned_sweep_and_prune::remove(&v3->m_y_list, v2);
    axis_aligned_sweep_and_prune::remove(&v3->m_z_list, v2);
    if ( v2 )
    {
      PMM_VALIDATE(v2, 0x80u, 4u);
      --v3->m_sap_node_allocator.m_count;
      PMM_FREE(v2, 0x80u, 4u);
    }
    bpb->m_sap_node = NULL;
  }
}

/*
==============
broad_phase_process_collision_pairs
==============
*/
void __usercall broad_phase_process_collision_pairs(int a1@<ebp>)
{
  phys_free_list<broad_phase_collision_pair>::T_internal_base *v1; // esi
  phys_free_list<broad_phase_collision_pair> *v2; // edi
  phys_vec3 *v3; // ecx
  phys_vec3 *v4; // eax
  float v5; // [esp+18h] [ebp-2Ch]
  float v6; // [esp+1Ch] [ebp-28h]
  float v7; // [esp+20h] [ebp-24h]
  float v8; // [esp+34h] [ebp-10h]
  int v9; // [esp+38h] [ebp-Ch]
  int v10; // [esp+3Ch] [ebp-8h]
  int retaddr; // [esp+44h] [ebp+0h]

  v9 = a1;
  v10 = retaddr;
  v8 = 0.0;
  v1 = G_BPM->g_list_broad_phase_collision_pair.m_dummy_head.m_next_T_internal;
  v2 = &G_BPM->g_list_broad_phase_collision_pair;
  if ( &G_BPM->g_list_broad_phase_collision_pair != (phys_free_list<broad_phase_collision_pair> *)v1 )
  {
    do
    {
      v3 = (phys_vec3 *)v1[1].m_prev_T_internal;
      v4 = (phys_vec3 *)v1[1].m_next_T_internal;
      v5 = v3[2].x - v4[2].x;
      v6 = v3[2].y - v4[2].y;
      v7 = v3[2].z - v4[2].z;
      if ( phys_are_potentially_colliding(v3, v3 + 1, (phys_vec3 *)&v5, v4, v4 + 1, &v8) )
        add_collision_pair(
          (broad_phase_info *)v1[1].m_prev_T_internal,
          (broad_phase_info *)v1[1].m_next_T_internal,
          v8,
          NULL);
      v1 = v1->m_next_T_internal;
    }
    while ( v2 != (phys_free_list<broad_phase_collision_pair> *)v1 );
  }
}

/*
==============
axis_aligned_sweep_and_prune::process_active_pair_list
==============
*/
void __usercall axis_aligned_sweep_and_prune::process_active_pair_list(axis_aligned_sweep_and_prune *this@<ecx>, axis_aligned_sweep_and_prune::active_pair **a2@<ebp>)
{
  axis_aligned_sweep_and_prune::active_pair **v2; // edx
  axis_aligned_sweep_and_prune::active_pair *v3; // edi
  axis_aligned_sweep_and_prune::sap_node *v4; // eax
  axis_aligned_sweep_and_prune::sap_node *v5; // ecx
  broad_phase_info *v6; // eax
  bool v7; // zf
  broad_phase_info **v8; // eax
  broad_phase_info *v9; // esi
  broad_phase_memory *v10; // esi
  phys_gjk_cache_info *v11; // eax
  phys_gjk_cache_info *v12; // esi
  axis_aligned_sweep_and_prune::active_pair *v13; // esi
  axis_aligned_sweep_and_prune::active_pair **v14; // edx
  axis_aligned_sweep_and_prune::sap_node *v15; // eax
  axis_aligned_sweep_and_prune::sap_node *v16; // ecx
  broad_phase_info *v17; // edi
  axis_aligned_sweep_and_prune::sap_node *v18; // eax
  broad_phase_base *v19; // esi
  broad_phase_info *i; // esi
  phys_gjk_cache_info *v21; // edi
  axis_aligned_sweep_and_prune::active_pair *v22; // edi
  axis_aligned_sweep_and_prune::active_pair **v23; // edx
  axis_aligned_sweep_and_prune::sap_node *v24; // eax
  axis_aligned_sweep_and_prune::sap_node *v25; // ecx
  broad_phase_base *v26; // esi
  int *v27; // eax
  int v28; // edi
  broad_phase_info *j; // esi
  broad_phase_info *k; // edi
  phys_gjk_cache_info *v31; // esi
  float v32; // [esp+18h] [ebp-4Ch]
  float v33; // [esp+1Ch] [ebp-48h]
  float v34; // [esp+20h] [ebp-44h]
  float v35; // [esp+28h] [ebp-3Ch]
  float v36; // [esp+2Ch] [ebp-38h]
  float v37; // [esp+30h] [ebp-34h]
  phys_heap_gjk_cache_system_avl_tree *v38; // [esp+44h] [ebp-20h]
  broad_phase_info *v39; // [esp+48h] [ebp-1Ch]
  axis_aligned_sweep_and_prune::active_pair **v40; // [esp+4Ch] [ebp-18h]
  axis_aligned_sweep_and_prune *v41; // [esp+50h] [ebp-14h]
  float v42; // [esp+54h] [ebp-10h]
  axis_aligned_sweep_and_prune::active_pair **ap_i; // [esp+58h] [ebp-Ch]
  int v44; // [esp+5Ch] [ebp-8h]
  int retaddr; // [esp+64h] [ebp+0h]

  ap_i = a2;
  v44 = retaddr;
  v2 = &this->m_list_bpi_bpi;
  v3 = this->m_list_bpi_bpi;
  v41 = this;
  v40 = &this->m_list_bpi_bpi;
  if ( v3 )
  {
    while ( 1 )
    {
      v4 = v3->m_p1;
      v5 = v3->m_p2;
      if ( v3->m_p1->m_ae1[0][0].m_ae_list_index >= v5->m_ae1[0][1].m_ae_list_index
        || v5->m_ae1[0][0].m_ae_list_index >= v4->m_ae1[0][1].m_ae_list_index
        || v4->m_ae1[1][0].m_ae_list_index >= v5->m_ae1[1][1].m_ae_list_index
        || v5->m_ae1[1][0].m_ae_list_index >= v4->m_ae1[1][1].m_ae_list_index
        || v4->m_ae1[2][0].m_ae_list_index >= v5->m_ae1[2][1].m_ae_list_index
        || v5->m_ae1[2][0].m_ae_list_index >= v4->m_ae1[2][1].m_ae_list_index )
      {
        *v2 = v3->m_next;
        v12 = v3->m_gjk_ci;
        v38 = &G_BPM->g_phys_gjk_cache_system;
        if ( v12 )
        {
          PMM_VALIDATE(v12, 0x90u, 0x10u);
          --v38->m_list_phys_gjk_cache_info_internal.m_count;
          PMM_FREE(v12, 0x90u, 0x10u);
        }
        PMM_VALIDATE(v3, 0x10u, 4u);
        --v41->m_active_pair_allocator.m_count;
        PMM_FREE(v3, 0x10u, 4u);
      }
      else
      {
        v6 = (broad_phase_info *)v4->m_bpb;
        v7 = (v6->m_flags & 1) == 0;
        v40 = &v3->m_next;
        v39 = v6;
        if ( v7
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_base.h",
               101,
               "is_bpi()",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v8 = (broad_phase_info **)v3->m_p2;
        v9 = *v8;
        v7 = ((*v8)->m_flags & 1) == 0;
        v38 = (phys_heap_gjk_cache_system_avl_tree *)*v8;
        if ( v7
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_base.h",
               101,
               "is_bpi()",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v35 = v39->m_trace_translation.x - v9->m_trace_translation.x;
        v36 = v39->m_trace_translation.y - v9->m_trace_translation.y;
        v37 = v39->m_trace_translation.z - v9->m_trace_translation.z;
        if ( phys_are_potentially_colliding(
               &v39->m_trace_aabb_min_whace,
               &v39->m_trace_aabb_max_whace,
               (phys_vec3 *)&v35,
               &v9->m_trace_aabb_min_whace,
               &v9->m_trace_aabb_max_whace,
               &v42) )
        {
          if ( !v3->m_gjk_ci )
          {
            v10 = G_BPM;
            v11 = (phys_gjk_cache_info *)PMM_ALLOC(0x90u, 0x10u);
            if ( v11 )
            {
              ++v10->g_phys_gjk_cache_system.m_list_phys_gjk_cache_info_internal.m_count;
              v11->m_key.m_id1 = 1;
              v11->m_key.m_id2 = 2;
              v11->m_flags = 0;
            }
            else
            {
              v11 = NULL;
            }
            v9 = (broad_phase_info *)v38;
            v3->m_gjk_ci = v11;
          }
          add_collision_pair(v39, v9, v42, v3->m_gjk_ci);
        }
      }
      v3 = *v40;
      if ( !*v40 )
        break;
      v2 = v40;
    }
    this = v41;
  }
  v13 = this->m_list_bpi_bpg;
  v14 = &this->m_list_bpi_bpg;
  v40 = &this->m_list_bpi_bpg;
  if ( v13 )
  {
    while ( 1 )
    {
      v15 = v13->m_p1;
      v16 = v13->m_p2;
      if ( v13->m_p1->m_ae1[0][0].m_ae_list_index >= v16->m_ae1[0][1].m_ae_list_index
        || v16->m_ae1[0][0].m_ae_list_index >= v15->m_ae1[0][1].m_ae_list_index
        || v15->m_ae1[1][0].m_ae_list_index >= v16->m_ae1[1][1].m_ae_list_index
        || v16->m_ae1[1][0].m_ae_list_index >= v15->m_ae1[1][1].m_ae_list_index
        || v15->m_ae1[2][0].m_ae_list_index >= v16->m_ae1[2][1].m_ae_list_index
        || v16->m_ae1[2][0].m_ae_list_index >= v15->m_ae1[2][1].m_ae_list_index )
      {
        *v14 = v13->m_next;
        v21 = v13->m_gjk_ci;
        v38 = &G_BPM->g_phys_gjk_cache_system;
        if ( v21 )
        {
          PMM_VALIDATE(v21, 0x90u, 0x10u);
          --v38->m_list_phys_gjk_cache_info_internal.m_count;
          PMM_FREE(v21, 0x90u, 0x10u);
        }
        PMM_VALIDATE(v13, 0x10u, 4u);
        --v41->m_active_pair_allocator.m_count;
        PMM_FREE(v13, 0x10u, 4u);
      }
      else
      {
        v17 = (broad_phase_info *)v15->m_bpb;
        v7 = (v15->m_bpb->m_flags & 1) == 0;
        v40 = &v13->m_next;
        if ( v7
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_base.h",
               101,
               "is_bpi()",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v18 = v13->m_p2;
        v19 = v18->m_bpb;
        if ( !(v18->m_bpb->m_flags & 2)
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_base.h",
               102,
               "is_bpg()",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v35 = v17->m_trace_translation.x - v19->m_trace_translation.x;
        v36 = v17->m_trace_translation.y - v19->m_trace_translation.y;
        v37 = v17->m_trace_translation.z - v19->m_trace_translation.z;
        if ( phys_are_potentially_colliding(
               &v17->m_trace_aabb_min_whace,
               &v17->m_trace_aabb_max_whace,
               (phys_vec3 *)&v35,
               &v19->m_trace_aabb_min_whace,
               &v19->m_trace_aabb_max_whace,
               &v42) )
        {
          for ( i = (broad_phase_info *)LODWORD(v19[1].m_trace_aabb_min_whace.x);
                i;
                i = (broad_phase_info *)i->m_list_bpb_next )
          {
            v32 = v17->m_trace_translation.x - i->m_trace_translation.x;
            v33 = v17->m_trace_translation.y - i->m_trace_translation.y;
            v34 = v17->m_trace_translation.z - i->m_trace_translation.z;
            if ( phys_are_potentially_colliding(
                   &v17->m_trace_aabb_min_whace,
                   &v17->m_trace_aabb_max_whace,
                   (phys_vec3 *)&v32,
                   &i->m_trace_aabb_min_whace,
                   &i->m_trace_aabb_max_whace,
                   &v42) )
            {
              add_collision_pair(v17, i, v42, NULL);
            }
          }
        }
      }
      v13 = *v40;
      if ( !*v40 )
        break;
      v14 = v40;
    }
    this = v41;
  }
  v22 = this->m_list_bpg_bpg;
  v23 = &this->m_list_bpg_bpg;
  v40 = &this->m_list_bpg_bpg;
  if ( v22 )
  {
    while ( 1 )
    {
      v24 = v22->m_p1;
      v25 = v22->m_p2;
      if ( v22->m_p1->m_ae1[0][0].m_ae_list_index >= v25->m_ae1[0][1].m_ae_list_index
        || v25->m_ae1[0][0].m_ae_list_index >= v24->m_ae1[0][1].m_ae_list_index
        || v24->m_ae1[1][0].m_ae_list_index >= v25->m_ae1[1][1].m_ae_list_index
        || v25->m_ae1[1][0].m_ae_list_index >= v24->m_ae1[1][1].m_ae_list_index
        || v24->m_ae1[2][0].m_ae_list_index >= v25->m_ae1[2][1].m_ae_list_index
        || v25->m_ae1[2][0].m_ae_list_index >= v24->m_ae1[2][1].m_ae_list_index )
      {
        *v23 = v22->m_next;
        v31 = v22->m_gjk_ci;
        v38 = &G_BPM->g_phys_gjk_cache_system;
        if ( v31 )
        {
          PMM_VALIDATE(v31, 0x90u, 0x10u);
          --v38->m_list_phys_gjk_cache_info_internal.m_count;
          PMM_FREE(v31, 0x90u, 0x10u);
        }
        PMM_VALIDATE(v22, 0x10u, 4u);
        --v41->m_active_pair_allocator.m_count;
        PMM_FREE(v22, 0x10u, 4u);
      }
      else
      {
        v26 = v24->m_bpb;
        v7 = (v24->m_bpb->m_flags & 2) == 0;
        v40 = &v22->m_next;
        if ( v7
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_base.h",
               102,
               "is_bpg()",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v27 = (int *)v22->m_p2;
        v28 = *v27;
        v7 = (*(_BYTE *)(*v27 + 48) & 2) == 0;
        v39 = (broad_phase_info *)*v27;
        if ( v7
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_base.h",
               102,
               "is_bpg()",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        for ( j = (broad_phase_info *)LODWORD(v26[1].m_trace_aabb_min_whace.x);
              j;
              j = (broad_phase_info *)j->m_list_bpb_next )
        {
          v32 = j->m_trace_translation.x - *(float *)(v28 + 32);
          v33 = j->m_trace_translation.y - *(float *)(v28 + 36);
          v34 = j->m_trace_translation.z - *(float *)(v28 + 40);
          if ( phys_are_potentially_colliding(
                 &j->m_trace_aabb_min_whace,
                 &j->m_trace_aabb_max_whace,
                 (phys_vec3 *)&v32,
                 (phys_vec3 *)v28,
                 (phys_vec3 *)(v28 + 16),
                 &v42) )
          {
            for ( k = *(broad_phase_info **)(v28 + 80); k; k = (broad_phase_info *)k->m_list_bpb_next )
            {
              v35 = j->m_trace_translation.x - k->m_trace_translation.x;
              v36 = j->m_trace_translation.y - k->m_trace_translation.y;
              v37 = j->m_trace_translation.z - k->m_trace_translation.z;
              if ( phys_are_potentially_colliding(
                     &j->m_trace_aabb_min_whace,
                     &j->m_trace_aabb_max_whace,
                     (phys_vec3 *)&v35,
                     &k->m_trace_aabb_min_whace,
                     &k->m_trace_aabb_max_whace,
                     &v42) )
              {
                add_collision_pair(j, k, v42, NULL);
              }
            }
            v28 = (int)v39;
          }
        }
      }
      v22 = *v40;
      if ( !*v40 )
        break;
      v23 = v40;
    }
  }
}

/*
==============
axis_aligned_sweep_and_prune::process
==============
*/
void __thiscall axis_aligned_sweep_and_prune::process(axis_aligned_sweep_and_prune *this)
{
  int v1; // eax
  int v2; // esi
  char *v3; // ebx
  char *v4; // eax
  axis_aligned_sweep_and_prune::axis_element *v5; // edx
  axis_aligned_sweep_and_prune::axis_element *v6; // edi
  axis_aligned_sweep_and_prune::axis_element *v7; // ecx
  axis_aligned_sweep_and_prune::axis_element **v8; // eax
  int v9; // esi
  axis_aligned_sweep_and_prune::axis_element **v10; // eax
  axis_aligned_sweep_and_prune::axis_element *v11; // ecx
  axis_aligned_sweep_and_prune::axis_element **v12; // edx
  axis_aligned_sweep_and_prune::axis_element *v13; // edx
  axis_aligned_sweep_and_prune::axis_element *v14; // ecx
  axis_aligned_sweep_and_prune::axis_element **v15; // edx
  axis_aligned_sweep_and_prune::axis_element *v16; // ecx
  int v17; // esi
  axis_aligned_sweep_and_prune::axis_element **v18; // edi
  int v19; // ST0C_4
  axis_aligned_sweep_and_prune *v20; // esi
  axis_aligned_sweep_and_prune::axis_element **v21; // ecx
  axis_aligned_sweep_and_prune::axis_element **v22; // edx
  axis_aligned_sweep_and_prune::axis_element **v23; // eax
  axis_aligned_sweep_and_prune::axis_element *v24; // edi
  axis_aligned_sweep_and_prune::axis_element *v25; // ebx
  phys_transient_allocator transient_buffer; // [esp+10h] [ebp-4Ch]
  axis_aligned_sweep_and_prune::axis_element **zlist; // [esp+28h] [ebp-34h]
  const int axis_element_count; // [esp+2Ch] [ebp-30h]
  axis_aligned_sweep_and_prune::axis_element **ylist; // [esp+30h] [ebp-2Ch]
  axis_aligned_sweep_and_prune::axis_element **zl_i; // [esp+34h] [ebp-28h]
  axis_aligned_sweep_and_prune::axis_element **yl_i; // [esp+38h] [ebp-24h]
  axis_aligned_sweep_and_prune::axis_element **xl_i; // [esp+3Ch] [ebp-20h]
  axis_aligned_sweep_and_prune::axis_element **xl_i_last; // [esp+40h] [ebp-1Ch]
  axis_aligned_sweep_and_prune::axis_element *zcur; // [esp+44h] [ebp-18h]
  axis_aligned_sweep_and_prune::axis_element *ycur; // [esp+48h] [ebp-14h]
  axis_aligned_sweep_and_prune *v36; // [esp+4Ch] [ebp-10h]
  int v37; // [esp+58h] [ebp-4h]
  int savedregs; // [esp+5Ch] [ebp+0h]

  v36 = this;
  v1 = 2 * this->m_sap_node_allocator.m_count;
  axis_element_count = v1;
  if ( v1 > 0 )
  {
    transient_buffer.m_first_block = NULL;
    transient_buffer.m_cur = NULL;
    transient_buffer.m_end = NULL;
    transient_buffer.m_total_memory_allocated = 0;
    transient_buffer.m_mutex.m_count = 1;
    transient_buffer.m_slot_pool = NULL;
    v2 = 4 * v1;
    v37 = 0;
    v3 = phys_transient_allocator::allocate(&transient_buffer, 4 * v1, 4, 0, "phys_transient_allocator out of memory.");
    ylist = (axis_aligned_sweep_and_prune::axis_element **)phys_transient_allocator::allocate(
                                                             &transient_buffer,
                                                             v2,
                                                             4,
                                                             0,
                                                             "phys_transient_allocator out of memory.");
    v4 = phys_transient_allocator::allocate(&transient_buffer, v2, 4, 0, "phys_transient_allocator out of memory.");
    v5 = v36->m_y_list;
    v6 = v36->m_x_list;
    v7 = v36->m_z_list;
    zlist = (axis_aligned_sweep_and_prune::axis_element **)v4;
    zl_i = (axis_aligned_sweep_and_prune::axis_element **)v4;
    v8 = (axis_aligned_sweep_and_prune::axis_element **)&v3[v2];
    ycur = v5;
    v9 = 0;
    zcur = v7;
    xl_i = (axis_aligned_sweep_and_prune::axis_element **)v3;
    yl_i = ylist;
    xl_i_last = v8;
    if ( v3 != (char *)v8 )
    {
      do
      {
        if ( v6->m_node->m_updated != 1
          && _tlAssert("source/phys_broad_phase.cpp", 451, "xcur->m_node->m_updated == 1", (const char *)&pBlock) )
        {
          __debugbreak();
        }
        if ( ycur->m_node->m_updated != 1
          && _tlAssert("source/phys_broad_phase.cpp", 452, "ycur->m_node->m_updated == 1", (const char *)&pBlock) )
        {
          __debugbreak();
        }
        if ( zcur->m_node->m_updated != 1
          && _tlAssert("source/phys_broad_phase.cpp", 453, "zcur->m_node->m_updated == 1", (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v10 = xl_i;
        v11 = ycur;
        v12 = yl_i;
        *xl_i = v6;
        v6->m_ae_list_index = v9;
        v6 = v6->m_next;
        *v12 = v11;
        yl_i = v12 + 1;
        v13 = v11->m_next;
        v11->m_ae_list_index = v9;
        v14 = zcur;
        ycur = v13;
        v15 = zl_i;
        *zl_i = zcur;
        v14->m_ae_list_index = v9;
        v16 = v14->m_next;
        ++v9;
        xl_i = v10 + 1;
        zl_i = v15 + 1;
        zcur = v16;
      }
      while ( v10 + 1 != xl_i_last );
    }
    if ( (v6 || ycur || zcur)
      && _tlAssert(
           "source/phys_broad_phase.cpp",
           459,
           "xcur == NULL && ycur == NULL && zcur == NULL",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v17 = axis_element_count;
    axis_aligned_sweep_and_prune::merge_sort(v36, (axis_aligned_sweep_and_prune::axis_element **)v3, axis_element_count);
    v18 = ylist;
    v19 = v17;
    v20 = v36;
    axis_aligned_sweep_and_prune::merge_sort(v36, ylist, v19);
    axis_aligned_sweep_and_prune::merge_sort(v20, zlist, axis_element_count);
    v20->m_x_list = *(axis_aligned_sweep_and_prune::axis_element **)v3;
    v21 = zlist;
    v20->m_y_list = *v18;
    v20->m_z_list = *v21;
    v22 = (axis_aligned_sweep_and_prune::axis_element **)v3;
    v23 = v18;
    if ( v3 != (char *)xl_i_last )
    {
      do
      {
        (*v22)->m_node->m_updated = 0;
        (*v23)->m_node->m_updated = 0;
        (*v21)->m_node->m_updated = 0;
        (*v22)->m_next = v22[1];
        (*v23)->m_next = v23[1];
        v24 = *v21;
        v25 = v21[1];
        ++v23;
        ++v21;
        ++v22;
        v24->m_next = v25;
      }
      while ( v22 != xl_i_last );
    }
    (*(v22 - 1))->m_next = NULL;
    (*(v23 - 1))->m_next = NULL;
    (*(v21 - 1))->m_next = NULL;
    phys_transient_allocator::reset(&transient_buffer);
    v37 = -1;
    if ( transient_buffer.m_first_block
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_transient_allocator.h",
           69,
           "m_first_block == NULL",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
  axis_aligned_sweep_and_prune::process_active_pair_list(v36, (axis_aligned_sweep_and_prune::active_pair **)&savedregs);
}

/*
==============
process_cluster_environment_collision
==============
*/
void process_cluster_environment_collision(broad_phase_base *bpb, broad_phase_environement_query_results *bpeqr)
{
  broad_phase_base *i; // esi
  unsigned int v3; // eax
  int savedregs; // [esp+4h] [ebp+0h]

  if ( (!bpb || !bpb->m_list_bpb_cluster_next)
    && _tlAssert("source/phys_broad_phase.cpp", 890, "bpb && bpb->get_bpb_cluster_next()", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  for ( i = bpb->m_list_bpb_cluster_next; i; i = i->m_list_bpb_cluster_next )
  {
    if ( !(i->m_flags & 0x10)
      && _tlAssert(
           "source/phys_broad_phase.cpp",
           893,
           "bpb->get_flag(broad_phase_base::FLAG_IS_IN_CLUSTER)",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v3 = i->m_flags;
    if ( v3 & 1 )
    {
      collide_bpi_environment((broad_phase_base_list::node *)&savedregs, (broad_phase_info *)i, bpeqr);
    }
    else
    {
      if ( !(v3 & 2) )
      {
        if ( _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_base.h",
               102,
               "is_bpg()",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      collide_bpg_environment((broad_phase_base_list::node *)&savedregs, (broad_phase_group *)i, bpeqr);
    }
  }
}

