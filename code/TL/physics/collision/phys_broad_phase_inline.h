/*
==============
broad_phase_info::collision_prolog
==============
*/
void __thiscall broad_phase_info::collision_prolog(broad_phase_info *this)
{
  broad_phase_info *v1; // esi
  rigid_body *v2; // eax
  __int64 v3; // ST24_8
  int savedregs; // [esp+20h] [ebp+0h]

  v1 = this;
  if ( this->m_flags & 0x200 )
    phys_full_multiply_mat(
      (int)&savedregs,
      this->m_cg_to_world_xform,
      this->m_rb_to_world_xform,
      this->m_cg_to_rb_xform);
  ((void (__stdcall *)(phys_mat44 *, broad_phase_info *, phys_vec3 *))v1->m_gjk_geom->vfptr->calc_aabb)(
    v1->m_cg_to_world_xform,
    v1,
    &v1->m_trace_aabb_max_whace);
  v1->m_trace_aabb_min_whace.x = v1->m_trace_aabb_min_whace.x - 0.50999999;
  v1->m_trace_aabb_min_whace.y = v1->m_trace_aabb_min_whace.y - 0.50999999;
  v1->m_trace_aabb_min_whace.z = v1->m_trace_aabb_min_whace.z - 0.50999999;
  v1->m_trace_aabb_max_whace.x = v1->m_trace_aabb_max_whace.x + 0.50999999;
  v1->m_trace_aabb_max_whace.y = v1->m_trace_aabb_max_whace.y + 0.50999999;
  v1->m_trace_aabb_max_whace.z = v1->m_trace_aabb_max_whace.z + 0.50999999;
  v2 = v1->m_rb;
  v3 = *(_QWORD *)&v2->m_moved_vec.z;
  *(_QWORD *)&v1->m_trace_translation.x = *(_QWORD *)&v2->m_moved_vec.x;
  LODWORD(v1->m_trace_translation.z) = v3;
  if ( !(v1->m_rb->m_flags & 0x30) )
    calc_largest_vel_sq(v1);
}

/*
==============
surface_type_info_database_get_index
==============
*/
int surface_type_info_database_get_index(const int surface_type_1, const int surface_type_2)
{
  int v2; // esi

  if ( (surface_type_1 < 0 || surface_type_1 >= G_BPM->m_max_num_surface_types)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_inline.h",
         336,
         "surface_type_1 >= 0 && surface_type_1 < G_BPM->m_max_num_surface_types",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (surface_type_2 < 0 || surface_type_2 >= G_BPM->m_max_num_surface_types)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_inline.h",
         337,
         "surface_type_2 >= 0 && surface_type_2 < G_BPM->m_max_num_surface_types",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( surface_type_1 < surface_type_2 )
    v2 = surface_type_1 + surface_type_2 * (surface_type_2 + 1) / 2;
  else
    v2 = surface_type_2 + surface_type_1 * (surface_type_1 + 1) / 2;
  if ( (v2 < 0 || v2 >= G_BPM->m_max_num_surface_type_infos)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_inline.h",
         339,
         "index >= 0 && index < G_BPM->m_max_num_surface_type_infos",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  return v2;
}

/*
==============
surface_type_info_database_get
==============
*/
phys_surface_type_info *surface_type_info_database_get(const int surface_type_1, const int surface_type_2)
{
  if ( !G_BPM->g_surface_type_info_database
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_inline.h",
         357,
         "G_BPM->g_surface_type_info_database",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  return &G_BPM->g_surface_type_info_database[surface_type_info_database_get_index(surface_type_1, surface_type_2)];
}

/*
==============
allocate_bpi_env
==============
*/
broad_phase_info *allocate_bpi_env()
{
  _DWORD *v0; // edx
  broad_phase_info *v1; // ecx

  _InterlockedExchangeAdd(&G_BPM->m_bpi_env_count, 1u);
  v0 = phys_transient_allocator::mt_allocate(
         &G_BPM->g_collision_memory_buffer,
         112,
         16,
         0,
         "broad phase collision out of memory.");
  do
  {
    v1 = G_BPM->m_list_bpi_env;
    v0[14] = v1;
  }
  while ( (broad_phase_info *)_InterlockedCompareExchange(
                                (volatile signed __int32 *)&G_BPM->m_list_bpi_env,
                                (signed __int32)v0,
                                (signed __int32)v1) != v1 );
  return (broad_phase_info *)v0;
}

/*
==============
broad_phase_memory::list_bpb_remove
==============
*/
void __thiscall broad_phase_memory::list_bpb_remove(broad_phase_memory *this, broad_phase_base *bpb_to_remove)
{
  broad_phase_memory *v2; // edi
  broad_phase_base *v3; // esi
  broad_phase_base **i; // eax

  v2 = this;
  v3 = this->g_list_bpb;
  for ( i = &this->g_list_bpb; v3 != bpb_to_remove; v3 = v3->m_list_bpb_next )
  {
    if ( !v3
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_inline.h",
           105,
           "bpb",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    i = &v3->m_list_bpb_next;
  }
  *i = v3->m_list_bpb_next;
  --v2->g_list_bpb_count;
}

/*
==============
environment_collision_list_add
==============
*/
void environment_collision_list_add(broad_phase_base *bpb)
{
  broad_phase_memory *v1; // eax

  if ( !(bpb->m_flags & 3)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_inline.h",
         235,
         "bpb->is_bpi() || bpb->is_bpg()",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( bpb->m_flags & 0x40
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_inline.h",
         236,
         "!bpb->get_flag(broad_phase_base::FLAG_ON_BPG_LIST)",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !(bpb->m_flags & 0x20) )
  {
    if ( bpb->m_list_bpb_next )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_inline.h",
             239,
             "bpb->m_list_bpb_next == NULL",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    v1 = G_BPM;
    bpb->m_list_bpb_next = G_BPM->g_list_bpb;
    ++v1->g_list_bpb_count;
    v1->g_list_bpb = bpb;
    bpb->m_flags |= 0x20u;
  }
}

/*
==============
environment_collision_list_remove
==============
*/
void environment_collision_list_remove(broad_phase_base *bpb)
{
  if ( !(bpb->m_flags & 3)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_inline.h",
         247,
         "bpb->is_bpi() || bpb->is_bpg()",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( bpb->m_flags & 0x40
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_inline.h",
         248,
         "!bpb->get_flag(broad_phase_base::FLAG_ON_BPG_LIST)",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( bpb->m_flags & 0x20 )
  {
    broad_phase_memory::list_bpb_remove(G_BPM, bpb);
    bpb->m_flags &= 0xFFFFFFDF;
    bpb->m_list_bpb_next = NULL;
  }
}

/*
==============
surface_type_info_database_set
==============
*/
void surface_type_info_database_set(const int surface_type_1, const int surface_type_2, phys_surface_type_info *pst)
{
  phys_surface_type_info *v3; // eax
  __int64 v4; // [esp+0h] [ebp-10h]
  __int64 v5; // [esp+8h] [ebp-8h]

  if ( !G_BPM->g_surface_type_info_database )
  {
    break_here_29 = 1;
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_inline.h",
           351,
           "G_BPM->g_surface_type_info_database",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
  v4 = *(_QWORD *)&pst->m_friction_coef;
  v5 = *(_QWORD *)&pst->m_solver_priority;
  v3 = &G_BPM->g_surface_type_info_database[surface_type_info_database_get_index(surface_type_1, surface_type_2)];
  _mm_storel_epi64((__m128i *)v3, _mm_loadl_epi64((const __m128i *)&v4));
  _mm_storel_epi64((__m128i *)&v3->m_solver_priority, _mm_loadl_epi64((const __m128i *)&v5));
}

/*
==============
broad_phase_group::collision_prolog
==============
*/
void __usercall broad_phase_group::collision_prolog(broad_phase_group *this@<ecx>, int a2@<ebp>)
{
  broad_phase_group *v2; // edi
  bool v3; // zf
  broad_phase_info *v4; // eax
  double v5; // st7
  float v6; // edx
  float v7; // ecx
  float v8; // ecx
  double v9; // st7
  float v10; // edx
  float v11; // ecx
  double v12; // st7
  double v13; // st7
  float v14; // edx
  unsigned int v15; // ecx
  double v16; // st7
  double v17; // st7
  broad_phase_info *v18; // esi
  double v19; // st7
  double v20; // st7
  double v21; // st7
  double v22; // st7
  double v23; // st7
  double v24; // st7
  double v25; // st7
  double v26; // st7
  double v27; // st7
  double v28; // st7
  double v29; // st7
  double v30; // st7
  unsigned int v31; // edx
  double v32; // st7
  rb_vehicle_model *v33; // eax
  phys_wheel_collide_info *v34; // eax
  rb_vehicle_model *v35; // esi
  float v36; // eax
  int v37; // esi
  int v38; // edi
  float *v39; // edi
  double v40; // st7
  double v41; // st7
  double v42; // st7
  double v43; // st7
  double v44; // st7
  double v45; // st7
  double v46; // st7
  double v47; // st6
  double v48; // st7
  double v49; // st7
  double v50; // st7
  double v51; // st7
  double v52; // st7
  double v53; // st7
  double v54; // st7
  double v55; // st6
  double v56; // st5
  double v57; // st4
  double v58; // st3
  double v59; // st2
  double v60; // st1
  double v61; // st6
  double v62; // st1
  double v63; // st4
  double v64; // st1
  double v65; // st2
  float v66; // [esp-Ch] [ebp-BCh]
  float v67; // [esp-8h] [ebp-B8h]
  float v68; // [esp-4h] [ebp-B4h]
  phys_vec3 p2; // [esp+0h] [ebp-B0h]
  phys_vec3 half_dims; // [esp+10h] [ebp-A0h]
  broad_phase_group *v71; // [esp+20h] [ebp-90h]
  phys_mat44 *rb_mat; // [esp+24h] [ebp-8Ch]
  const int wheel_count; // [esp+28h] [ebp-88h]
  float v74; // [esp+2Ch] [ebp-84h]
  phys_vec3 aabb2_min; // [esp+30h] [ebp-80h]
  phys_vec3 aabb2_max; // [esp+40h] [ebp-70h]
  phys_vec3 p1; // [esp+50h] [ebp-60h]
  phys_vec3 aabb1_max; // [esp+60h] [ebp-50h]
  phys_vec3 aabb1_min; // [esp+70h] [ebp-40h]
  float v80; // [esp+90h] [ebp-20h]
  float v81; // [esp+94h] [ebp-1Ch]
  float v82; // [esp+98h] [ebp-18h]
  float v83; // [esp+9Ch] [ebp-14h]
  float v84; // [esp+A0h] [ebp-10h]
  int i; // [esp+A4h] [ebp-Ch]
  int v86; // [esp+A8h] [ebp-8h]
  int retaddr; // [esp+B0h] [ebp+0h]

  i = a2;
  v86 = retaddr;
  v2 = this;
  v3 = this->m_list_bpi_head == NULL;
  v71 = this;
  if ( v3
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_inline.h",
         184,
         "m_list_bpi_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  broad_phase_info::collision_prolog(v2->m_list_bpi_head);
  v4 = v2->m_list_bpi_head;
  v5 = v4->m_trace_translation.x + v4->m_trace_aabb_min_whace.x;
  v6 = v4->m_trace_aabb_min_whace.y;
  aabb1_max.y = v4->m_trace_aabb_min_whace.x;
  v7 = v4->m_trace_aabb_min_whace.z;
  *(float *)&rb_mat = v5;
  aabb1_max.w = v7;
  v8 = v4->m_trace_aabb_max_whace.x;
  v9 = v4->m_trace_translation.y + v4->m_trace_aabb_min_whace.y;
  aabb1_max.z = v6;
  v10 = v4->m_trace_aabb_min_whace.w;
  p1.y = v8;
  v11 = v4->m_trace_aabb_max_whace.z;
  *(float *)&wheel_count = v9;
  v12 = v4->m_trace_translation.z;
  aabb1_min.x = v10;
  v13 = v12 + v4->m_trace_aabb_min_whace.z;
  v14 = v4->m_trace_aabb_max_whace.y;
  p1.w = v11;
  v15 = v4->m_env_collision_flags;
  v74 = v13;
  p1.z = v14;
  v16 = v4->m_trace_aabb_max_whace.x + v4->m_trace_translation.x;
  aabb1_max.x = v4->m_trace_aabb_max_whace.w;
  aabb2_min.y = v16;
  aabb2_min.z = v4->m_trace_aabb_max_whace.y + v4->m_trace_translation.y;
  v17 = v4->m_trace_aabb_max_whace.z + v4->m_trace_translation.z;
  v2->m_env_collision_flags = v15;
  v18 = (broad_phase_info *)v4->m_list_bpb_next;
  for ( aabb2_min.w = v17; v18; aabb2_min.w = v82 )
  {
    broad_phase_info::collision_prolog(v18);
    v19 = aabb1_max.w;
    if ( v18->m_trace_aabb_min_whace.z < (double)aabb1_max.w )
      v19 = v18->m_trace_aabb_min_whace.z;
    v84 = v19;
    v20 = aabb1_max.z;
    if ( v18->m_trace_aabb_min_whace.y < (double)aabb1_max.z )
      v20 = v18->m_trace_aabb_min_whace.y;
    v82 = v20;
    v21 = aabb1_max.y;
    if ( v18->m_trace_aabb_min_whace.x < (double)aabb1_max.y )
      v21 = v18->m_trace_aabb_min_whace.x;
    v81 = v21;
    aabb1_max.y = v81;
    aabb1_max.z = v82;
    aabb1_max.w = v84;
    v22 = p1.w;
    if ( v18->m_trace_aabb_max_whace.z > (double)p1.w )
      v22 = v18->m_trace_aabb_max_whace.z;
    v82 = v22;
    v23 = p1.z;
    if ( v18->m_trace_aabb_max_whace.y > (double)p1.z )
      v23 = v18->m_trace_aabb_max_whace.y;
    v81 = v23;
    v24 = p1.y;
    if ( v18->m_trace_aabb_max_whace.x > (double)p1.y )
      v24 = v18->m_trace_aabb_max_whace.x;
    v84 = v24;
    p1.y = v84;
    p1.z = v81;
    p1.w = v82;
    aabb1_min.y = v18->m_trace_translation.x + v18->m_trace_aabb_max_whace.x;
    aabb1_min.z = v18->m_trace_aabb_max_whace.y + v18->m_trace_translation.y;
    aabb1_min.w = v18->m_trace_aabb_max_whace.z + v18->m_trace_translation.z;
    aabb2_max.y = v18->m_trace_aabb_min_whace.x + v18->m_trace_translation.x;
    aabb2_max.z = v18->m_trace_aabb_min_whace.y + v18->m_trace_translation.y;
    aabb2_max.w = v18->m_trace_aabb_min_whace.z + v18->m_trace_translation.z;
    v25 = v74;
    if ( aabb2_max.w < (double)v74 )
      v25 = aabb2_max.w;
    v82 = v25;
    v26 = *(float *)&wheel_count;
    if ( aabb2_max.z < (double)*(float *)&wheel_count )
      v26 = aabb2_max.z;
    v81 = v26;
    v27 = *(float *)&rb_mat;
    if ( aabb2_max.y < (double)*(float *)&rb_mat )
      v27 = aabb2_max.y;
    v84 = v27;
    *(float *)&rb_mat = v84;
    *(float *)&wheel_count = v81;
    v74 = v82;
    v28 = aabb2_min.w;
    if ( aabb1_min.w > (double)aabb2_min.w )
      v28 = aabb1_min.w;
    v82 = v28;
    v29 = aabb2_min.z;
    if ( aabb1_min.z > (double)aabb2_min.z )
      v29 = aabb1_min.z;
    v81 = v29;
    v30 = aabb2_min.y;
    if ( aabb1_min.y > (double)aabb2_min.y )
      v30 = aabb1_min.y;
    v31 = v18->m_env_collision_flags;
    v84 = v30;
    v32 = v84;
    v2->m_env_collision_flags |= v31;
    v18 = (broad_phase_info *)v18->m_list_bpb_next;
    aabb2_min.y = v32;
    aabb2_min.z = v81;
  }
  v33 = v2->m_rbvm;
  if ( v33 )
  {
    LODWORD(half_dims.w) = v33->m_wheels.m_alloc_count;
    v34 = (phys_wheel_collide_info *)phys_transient_allocator::mt_allocate(
                                       &G_BPM->g_collision_memory_buffer,
                                       LODWORD(half_dims.w) << 6,
                                       16,
                                       0,
                                       "broad phase collision out of memory.");
    v35 = v2->m_rbvm;
    v2->m_list_wci = v34;
    if ( v35->m_wheels.m_alloc_count <= 0
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_array_base.inc",
           118,
           "i >= 0 && i < m_alloc_count",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    LODWORD(half_dims.z) = **(_DWORD **)v35->m_wheels.m_slot_array + 48;
    v36 = 0.0;
    v82 = 0.0;
    if ( SLODWORD(half_dims.w) > 0 )
    {
      v81 = 0.0;
      while ( 1 )
      {
        v37 = (int)v2->m_list_wci + LODWORD(v81);
        v38 = (int)v2->m_rbvm->m_wheels.m_buffer;
        v83 = *(float *)&v38;
        if ( (v36 < 0.0 || SLODWORD(v36) >= *(_DWORD *)(v38 + 20))
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_array_base.inc",
               118,
               "i >= 0 && i < m_alloc_count",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v39 = (float *)(v37 + 16);
        rigid_body_constraint_wheel::get_wheel_collide_segment(
          *(rigid_body_constraint_wheel **)(*(_DWORD *)(LODWORD(v83) + 16) + 4 * LODWORD(v82)),
          (phys_mat44 *)LODWORD(half_dims.z),
          (phys_vec3 *const )v37,
          (phys_vec3 *const )(v37 + 16));
        *v39 = *v39 - *(float *)v37;
        *(float *)(v37 + 20) = *(float *)(v37 + 20) - *(float *)(v37 + 4);
        *(float *)(v37 + 24) = *(float *)(v37 + 24) - *(float *)(v37 + 8);
        *(_DWORD *)(v37 + 52) = 0;
        *(float *)(v37 + 48) = 1.0;
        v40 = aabb1_max.w;
        if ( *(float *)(v37 + 8) < (double)aabb1_max.w )
          v40 = *(float *)(v37 + 8);
        v83 = v40;
        v41 = aabb1_max.z;
        if ( *(float *)(v37 + 4) < (double)aabb1_max.z )
          v41 = *(float *)(v37 + 4);
        v80 = v41;
        v42 = aabb1_max.y;
        if ( *(float *)v37 < (double)aabb1_max.y )
          v42 = *(float *)v37;
        v84 = v42;
        aabb1_max.y = v84;
        aabb1_max.z = v80;
        aabb1_max.w = v83;
        v43 = p1.w;
        if ( *(float *)(v37 + 8) > (double)p1.w )
          v43 = *(float *)(v37 + 8);
        v84 = v43;
        v44 = p1.z;
        if ( *(float *)(v37 + 4) > (double)p1.z )
          v44 = *(float *)(v37 + 4);
        v80 = v44;
        v45 = p1.y;
        if ( *(float *)v37 > (double)p1.y )
          v45 = *(float *)v37;
        v83 = v45;
        p1.y = v83;
        p1.z = v80;
        p1.w = v84;
        v83 = *(float *)v37 + *v39;
        v46 = v83;
        aabb2_max.y = v83;
        v83 = *(float *)(v37 + 20) + *(float *)(v37 + 4);
        v47 = v83;
        aabb2_max.z = v83;
        v83 = *(float *)(v37 + 8) + *(float *)(v37 + 24);
        aabb2_max.w = v83;
        aabb1_min.w = v83;
        aabb1_min.y = v46;
        aabb1_min.z = v47;
        v48 = v74;
        if ( v83 < (double)v74 )
          v48 = aabb1_min.w;
        v84 = v48;
        v49 = *(float *)&wheel_count;
        if ( aabb1_min.z < (double)*(float *)&wheel_count )
          v49 = aabb1_min.z;
        v80 = v49;
        v50 = *(float *)&rb_mat;
        if ( aabb1_min.y < (double)*(float *)&rb_mat )
          v50 = aabb1_min.y;
        v83 = v50;
        *(float *)&rb_mat = v83;
        *(float *)&wheel_count = v80;
        v74 = v84;
        v51 = aabb2_min.w;
        if ( aabb2_max.w > (double)aabb2_min.w )
          v51 = aabb2_max.w;
        v84 = v51;
        v52 = aabb2_min.z;
        if ( aabb2_max.z > (double)aabb2_min.z )
          v52 = aabb2_max.z;
        v80 = v52;
        v53 = aabb2_min.y;
        if ( aabb2_max.y > (double)aabb2_min.y )
          v53 = aabb2_max.y;
        v83 = v53;
        LODWORD(v81) += 64;
        v2 = v71;
        aabb2_min.y = v83;
        aabb2_min.z = v80;
        ++LODWORD(v82);
        aabb2_min.w = v84;
        if ( SLODWORD(v82) >= SLODWORD(half_dims.w) )
          break;
        v36 = v82;
      }
    }
  }
  comp_trace_volume(
    (int)&i,
    (phys_vec3 *)((char *)&aabb1_max + 4),
    (phys_vec3 *)((char *)&p1 + 4),
    (phys_vec3 *)&rb_mat,
    (phys_vec3 *)((char *)&aabb2_min + 4),
    (phys_vec3 *)((char *)&aabb2_max + 4),
    (phys_vec3 *)&v66,
    (phys_vec3 *)((char *)&p2 + 4));
  v54 = aabb2_max.y;
  v55 = p2.y;
  aabb1_min.y = aabb2_max.y - p2.y;
  v56 = aabb2_max.z;
  v57 = p2.z;
  aabb1_min.z = aabb2_max.z - p2.z;
  v58 = aabb2_max.w;
  v59 = p2.w;
  aabb1_min.w = aabb2_max.w - p2.w;
  v2->m_trace_aabb_min_whace.x = aabb1_min.y;
  v2->m_trace_aabb_min_whace.y = aabb1_min.z;
  v2->m_trace_aabb_min_whace.z = aabb1_min.w;
  v60 = v55 + v66;
  v61 = v66;
  aabb1_min.y = v60;
  v62 = v57 + v67;
  v63 = v67;
  aabb1_min.z = v62;
  v64 = v59 + v68;
  v65 = v68;
  aabb1_min.w = v64;
  v2->m_trace_aabb_max_whace.x = aabb1_min.y;
  v2->m_trace_aabb_max_whace.y = aabb1_min.z;
  v2->m_trace_aabb_max_whace.z = aabb1_min.w;
  aabb1_min.y = v61 - v54;
  aabb1_min.z = v63 - v56;
  aabb1_min.w = v65 - v58;
  v2->m_trace_translation.x = aabb1_min.y;
  v2->m_trace_translation.y = aabb1_min.z;
  v2->m_trace_translation.z = aabb1_min.w;
}

/*
==============
broad_phase_memory::allocate_buffer
==============
*/
broad_phase_memory *broad_phase_memory::allocate_buffer(broad_phase_memory_info *bpmi)
{
  broad_phase_memory *v1; // eax
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v4; // ecx
  int v5; // ecx
  int v6; // eax
  void *v7; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // eax
  int v11; // eax

  v1 = (broad_phase_memory *)PMM_PERM_ALLOCATE(0xCD8u, 8u);
  if ( v1 )
  {
    broad_phase_memory::broad_phase_memory(v1);
    v3 = v2;
  }
  else
  {
    v3 = NULL;
  }
  v4 = bpmi->m_max_num_gjk_ci + bpmi->m_max_num_sap_active_pairs;
  v3[13] = 0;
  v3[12] = v4;
  v5 = bpmi->m_max_num_surface_types;
  v6 = v5 * (v5 + 1) / 2;
  v3[820] = v5;
  v3[821] = v6;
  if ( v6 <= 0 )
  {
    v3[819] = 0;
    return (broad_phase_memory *)v3;
  }
  v7 = PMM_PERM_ALLOCATE(16 * v6, 4u);
  v8 = 0;
  v3[819] = v7;
  if ( v3[821] <= 0 )
    return (broad_phase_memory *)v3;
  v9 = 0;
  do
  {
    v10 = v3[819];
    *(float *)(v10 + v9) = 0.0;
    v11 = v9 + v10;
    ++v8;
    *(float *)(v11 + 4) = 0.0;
    *(_DWORD *)(v11 + 8) = 0;
    *(_BYTE *)(v11 + 12) = 0;
    v9 += 16;
  }
  while ( v8 < v3[821] );
  return (broad_phase_memory *)v3;
}

