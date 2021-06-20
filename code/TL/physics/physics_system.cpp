/*
==============
fixup_wheel_constraints
==============
*/
void fixup_wheel_constraints(rigid_body *rb)
{
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v1; // esi
  phys_free_list<rigid_body_constraint_wheel> *v2; // edi

  v1 = g_physics_system->m_list_rbc_wheel.m_dummy_head.m_next_T_internal;
  v2 = &g_physics_system->m_list_rbc_wheel;
  if ( &g_physics_system->m_list_rbc_wheel != (phys_free_list<rigid_body_constraint_wheel> *)v1 )
  {
    do
    {
      if ( v1 != (phys_free_list<rigid_body_constraint_wheel>::T_internal_base *)-16
        && (rigid_body *)v1[2].m_next_T_internal == rb )
      {
        rigid_body_constraint_wheel::set_no_collision((rigid_body_constraint_wheel *)&v1[2]);
      }
      v1 = v1->m_next_T_internal;
    }
    while ( v2 != (phys_free_list<rigid_body_constraint_wheel> *)v1 );
  }
}

/*
==============
phys_sys::get_environment_rigid_body
==============
*/
environment_rigid_body *phys_sys::get_environment_rigid_body()
{
  return &g_physics_system->m_environment_rigid_body;
}

/*
==============
phys_sys::set_max_delta_t
==============
*/
void phys_sys::set_max_delta_t(const float max_delta_t)
{
  g_physics_system->m_max_delta_t = max_delta_t;
}

/*
==============
phys_sys::get_max_delta_t
==============
*/
double phys_sys::get_max_delta_t()
{
  return g_physics_system->m_max_delta_t;
}

/*
==============
phys_sys::set_v_tol
==============
*/
void phys_sys::set_v_tol(const int max_v_iters)
{
  g_physics_system->m_max_vel_iters = max_v_iters;
}

/*
==============
phys_sys::get_v_tol
==============
*/
void phys_sys::get_v_tol(int *max_v_iters)
{
  *max_v_iters = g_physics_system->m_max_vel_iters;
}

/*
==============
phys_sys::set_vp_tol
==============
*/
void phys_sys::set_vp_tol(const int max_vp_iters)
{
  g_physics_system->m_max_vel_pos_iters = max_vp_iters;
}

/*
==============
phys_sys::get_vp_tol
==============
*/
void phys_sys::get_vp_tol(int *max_vp_iters)
{
  *max_vp_iters = g_physics_system->m_max_vel_pos_iters;
}

/*
==============
phys_sys::set_collision_callback
==============
*/
void phys_sys::set_collision_callback(void (*collision_callback)())
{
  g_physics_system->m_collision_callback = collision_callback;
}

/*
==============
phys_sys::phys_frame_advance
==============
*/
void phys_sys::phys_frame_advance(float delta_t)
{
  physics_system::frame_advance(g_physics_system, delta_t);
}

/*
==============
phys_sys::phys_init
==============
*/
void phys_sys::phys_init()
{
  physics_system::initialize();
}

/*
==============
phys_sys::phys_shutdown
==============
*/
void phys_sys::phys_shutdown()
{
  physics_system::shutdown();
}

/*
==============
phys_sys::get_rigid_body_alloc_count
==============
*/
int phys_sys::get_rigid_body_alloc_count()
{
  return g_physics_system->m_list_rigid_body.m_list_count;
}

/*
==============
phys_sys::get_user_rigid_body_alloc_count
==============
*/
int phys_sys::get_user_rigid_body_alloc_count()
{
  return g_physics_system->m_list_user_rigid_body.m_list_count;
}

/*
==============
phys_sys::get_user_rigid_body
==============
*/
phys_free_list<user_rigid_body>::T_internal_base *phys_sys::get_user_rigid_body(phys_mat44 *const dictactor)
{
  phys_free_list<user_rigid_body>::T_internal_base *v1; // esi
  phys_free_list<user_rigid_body> *v2; // ebx

  v1 = g_physics_system->m_list_user_rigid_body.m_dummy_head.m_next_T_internal;
  v2 = &g_physics_system->m_list_user_rigid_body;
  if ( &g_physics_system->m_list_user_rigid_body == (phys_free_list<user_rigid_body> *)v1 )
    return 0;
  while ( 1 )
  {
    if ( !((_DWORD)v1[33].m_next_T_internal & 0x20) )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\rigid_body_internal.h",
             31,
             "rb->is_user_rigid_body()",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    if ( (phys_mat44 *const )v1[46].m_prev_T_internal == dictactor )
      break;
    v1 = v1->m_next_T_internal;
    if ( v2 == (phys_free_list<user_rigid_body> *)v1 )
      return 0;
  }
  return v1 + 2;
}

/*
==============
phys_sys::get_rbc_contact
==============
*/
rigid_body_constraint_contact *phys_sys::get_rbc_contact(rigid_body *const b1, rigid_body *const b2)
{
  rigid_body_pair_key *v2; // eax
  rigid_body_pair_key v4; // [esp+8h] [ebp-8h]

  physics_system::validate_member(g_physics_system, b1);
  physics_system::validate_member(g_physics_system, b2);
  rigid_body_pair_key::rigid_body_pair_key(&v4, b1, b2);
  return phys_inplace_avl_tree<rigid_body_pair_key,rigid_body_constraint_contact,rigid_body_constraint_contact::avl_tree_accessor>::find(
           &g_physics_system->m_search_tree_rbc_contact,
           v2);
}

/*
==============
phys_sys::fixup_wheel_constraints
==============
*/
void phys_sys::fixup_wheel_constraints(rigid_body *const rb)
{
  physics_system *v1; // eax
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v2; // esi

  v1 = g_physics_system;
  v2 = g_physics_system->m_list_rbc_wheel.m_dummy_head.m_next_T_internal;
  if ( &g_physics_system->m_list_rbc_wheel != (phys_free_list<rigid_body_constraint_wheel> *)v2 )
  {
    do
    {
      if ( (rigid_body *const )v2[2].m_next_T_internal == rb )
      {
        rigid_body_constraint_wheel::set_no_collision((rigid_body_constraint_wheel *)&v2[2]);
        v1 = g_physics_system;
      }
      else
      {
        v2 = v2->m_next_T_internal;
      }
    }
    while ( &v1->m_list_rbc_wheel != (phys_free_list<rigid_body_constraint_wheel> *)v2 );
  }
}

/*
==============
phys_sys::update_constraint_infos
==============
*/
void phys_sys::update_constraint_infos()
{
  physics_system *v0; // eax
  physics_system *v1; // eax
  phys_free_list<user_rigid_body>::T_internal_base *v2; // ecx
  phys_free_list<user_rigid_body> *v3; // edx
  phys_free_list<rigid_body> *v4; // ecx
  phys_free_list<rigid_body_constraint_point> *v5; // ecx
  int v6; // edx
  rigid_body_constraint_point *v7; // eax
  rigid_body_constraint_point *v8; // eax
  phys_free_list<rigid_body_constraint_hinge> *v9; // ecx
  int v10; // edx
  rigid_body_constraint_hinge *v11; // eax
  rigid_body_constraint_hinge *v12; // eax
  phys_free_list<rigid_body_constraint_distance> *v13; // ecx
  int v14; // edx
  rigid_body_constraint_distance *v15; // eax
  rigid_body_constraint_distance *v16; // eax
  phys_free_list<rigid_body_constraint_ragdoll> *v17; // ecx
  int v18; // edx
  rigid_body_constraint_ragdoll *v19; // eax
  rigid_body_constraint_ragdoll *v20; // eax
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v21; // ecx
  int v22; // edx
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v23; // eax
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v24; // eax
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v25; // eax
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v26; // eax
  phys_free_list<rigid_body_constraint_angular_actuator> *v27; // ecx
  int v28; // edx
  rigid_body_constraint_angular_actuator *v29; // eax
  rigid_body_constraint_angular_actuator *v30; // eax
  phys_free_list<rigid_body_constraint_upright> *v31; // ecx
  int v32; // edx
  rigid_body_constraint_upright *v33; // eax
  rigid_body_constraint_upright *v34; // eax
  phys_free_list<rigid_body_constraint_custom_orientation> *v35; // ecx
  int v36; // edx
  int v37; // eax
  int v38; // eax
  phys_free_list<rigid_body_constraint_custom_path> *v39; // ecx
  int v40; // edx
  rigid_body_constraint_custom_path *v41; // eax
  rigid_body_constraint_custom_path *v42; // eax
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v43; // ecx
  int i; // ebx
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v45; // eax
  int j; // esi
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v47; // eax
  int k; // edx
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v49; // eax

  v0 = g_physics_system;
  v0->m_environment_rigid_body.m_flags &= 0xFFFFFEFF;
  v0->m_environment_rigid_body.m_constraint_count = 0;
  v0->m_environment_rigid_body.m_contact_count = 0;
  v1 = g_physics_system;
  v2 = g_physics_system->m_list_user_rigid_body.m_dummy_head.m_next_T_internal;
  v3 = &g_physics_system->m_list_user_rigid_body;
  if ( &g_physics_system->m_list_user_rigid_body != (phys_free_list<user_rigid_body> *)v2 )
  {
    do
    {
      v2[33].m_next_T_internal = (phys_free_list<user_rigid_body>::T_internal_base *)((_DWORD)v2[33].m_next_T_internal & 0xFFFFFEFF);
      v2[35].m_prev_T_internal = NULL;
      v2[35].m_next_T_internal = NULL;
      v2 = v2->m_next_T_internal;
    }
    while ( v3 != (phys_free_list<user_rigid_body> *)v2 );
    v1 = g_physics_system;
  }
  v4 = (phys_free_list<rigid_body> *)v1->m_list_rigid_body.m_dummy_head.m_next_T_internal;
  if ( &v1->m_list_rigid_body != v4 )
  {
    do
    {
      v4->m_ptr_list[63] = (rigid_body *)((_DWORD)v4->m_ptr_list[63] & 0xFFFFFEFF);
      v4->m_ptr_list[66] = NULL;
      v4->m_ptr_list[67] = NULL;
      v4 = (phys_free_list<rigid_body> *)v4->m_dummy_head.m_next_T_internal;
    }
    while ( &v1->m_list_rigid_body != v4 );
    v1 = g_physics_system;
  }
  v5 = (phys_free_list<rigid_body_constraint_point> *)v1->m_list_rbc_point.m_dummy_head.m_next_T_internal;
  v6 = (int)&v1->m_list_rbc_point;
  if ( &v1->m_list_rbc_point != v5 )
  {
    do
    {
      v7 = v5->m_ptr_list[0];
      if ( v7 )
        ++LODWORD(v7[3].m_b1_r_loc.z);
      v8 = v5->m_ptr_list[1];
      if ( v8 )
        ++LODWORD(v8[3].m_b1_r_loc.z);
      v5 = (phys_free_list<rigid_body_constraint_point> *)v5->m_dummy_head.m_next_T_internal;
    }
    while ( (phys_free_list<rigid_body_constraint_point> *)v6 != v5 );
    v1 = g_physics_system;
  }
  v9 = (phys_free_list<rigid_body_constraint_hinge> *)v1->m_list_rbc_hinge.m_dummy_head.m_next_T_internal;
  v10 = (int)&v1->m_list_rbc_hinge;
  if ( &v1->m_list_rbc_hinge != v9 )
  {
    do
    {
      v11 = v9->m_ptr_list[0];
      if ( v11 )
        ++LODWORD(v11[1].m_b1_axis_loc.z);
      v12 = v9->m_ptr_list[1];
      if ( v12 )
        ++LODWORD(v12[1].m_b1_axis_loc.z);
      v9 = (phys_free_list<rigid_body_constraint_hinge> *)v9->m_dummy_head.m_next_T_internal;
    }
    while ( (phys_free_list<rigid_body_constraint_hinge> *)v10 != v9 );
    v1 = g_physics_system;
  }
  v13 = (phys_free_list<rigid_body_constraint_distance> *)v1->m_list_rbc_dist.m_dummy_head.m_next_T_internal;
  v14 = (int)&v1->m_list_rbc_dist;
  if ( &v1->m_list_rbc_dist != v13 )
  {
    do
    {
      v15 = v13->m_ptr_list[0];
      if ( v15 )
        ++LODWORD(v15[2].m_ps_cache_list[0].m_pulse_sum);
      v16 = v13->m_ptr_list[1];
      if ( v16 )
        ++LODWORD(v16[2].m_ps_cache_list[0].m_pulse_sum);
      v13 = (phys_free_list<rigid_body_constraint_distance> *)v13->m_dummy_head.m_next_T_internal;
    }
    while ( (phys_free_list<rigid_body_constraint_distance> *)v14 != v13 );
    v1 = g_physics_system;
  }
  v17 = (phys_free_list<rigid_body_constraint_ragdoll> *)v1->m_list_rbc_ragdoll.m_dummy_head.m_next_T_internal;
  v18 = (int)&v1->m_list_rbc_ragdoll;
  if ( &v1->m_list_rbc_ragdoll != v17 )
  {
    do
    {
      v19 = v17->m_ptr_list[0];
      if ( v19 )
        ++LODWORD(v19->m_joint_limits[1].m_b1_ud_active_limit_co_);
      v20 = v17->m_ptr_list[1];
      if ( v20 )
        ++LODWORD(v20->m_joint_limits[1].m_b1_ud_active_limit_co_);
      v17 = (phys_free_list<rigid_body_constraint_ragdoll> *)v17->m_dummy_head.m_next_T_internal;
    }
    while ( (phys_free_list<rigid_body_constraint_ragdoll> *)v18 != v17 );
    v1 = g_physics_system;
  }
  v21 = v1->m_list_rbc_wheel.m_dummy_head.m_next_T_internal;
  v22 = (int)&v1->m_list_rbc_wheel;
  if ( &v1->m_list_rbc_wheel != (phys_free_list<rigid_body_constraint_wheel> *)v21 )
  {
    do
    {
      v23 = v21[2].m_prev_T_internal;
      if ( v23 )
        ++v23[33].m_prev_T_internal;
      v24 = v21[2].m_next_T_internal;
      if ( v24 )
        ++v24[33].m_prev_T_internal;
      if ( (_DWORD)v21[24].m_prev_T_internal & 1 )
      {
        v25 = v21[2].m_prev_T_internal;
        if ( v25 )
          ++v25[33].m_next_T_internal;
        v26 = v21[2].m_next_T_internal;
        if ( v26 )
          ++v26[33].m_next_T_internal;
      }
      v21 = v21->m_next_T_internal;
    }
    while ( (phys_free_list<rigid_body_constraint_wheel>::T_internal_base *)v22 != v21 );
    v1 = g_physics_system;
  }
  v27 = (phys_free_list<rigid_body_constraint_angular_actuator> *)v1->m_list_rbc_angular_actuator.m_dummy_head.m_next_T_internal;
  v28 = (int)&v1->m_list_rbc_angular_actuator;
  if ( &v1->m_list_rbc_angular_actuator != v27 )
  {
    do
    {
      v29 = v27->m_ptr_list[0];
      if ( v29 )
        ++LODWORD(v29[1].m_target_mat.w.z);
      v30 = v27->m_ptr_list[1];
      if ( v30 )
        ++LODWORD(v30[1].m_target_mat.w.z);
      v27 = (phys_free_list<rigid_body_constraint_angular_actuator> *)v27->m_dummy_head.m_next_T_internal;
    }
    while ( (phys_free_list<rigid_body_constraint_angular_actuator> *)v28 != v27 );
    v1 = g_physics_system;
  }
  v31 = (phys_free_list<rigid_body_constraint_upright> *)v1->m_list_rbc_upright.m_dummy_head.m_next_T_internal;
  v32 = (int)&v1->m_list_rbc_upright;
  if ( &v1->m_list_rbc_upright != v31 )
  {
    do
    {
      v33 = v31->m_ptr_list[0];
      if ( v33 )
        ++LODWORD(v33[1].m_b2_up_axis_loc.z);
      v34 = v31->m_ptr_list[1];
      if ( v34 )
        ++LODWORD(v34[1].m_b2_up_axis_loc.z);
      v31 = (phys_free_list<rigid_body_constraint_upright> *)v31->m_dummy_head.m_next_T_internal;
    }
    while ( (phys_free_list<rigid_body_constraint_upright> *)v32 != v31 );
    v1 = g_physics_system;
  }
  v35 = (phys_free_list<rigid_body_constraint_custom_orientation> *)v1->m_list_rbc_custom_orientation.m_dummy_head.m_next_T_internal;
  v36 = (int)&v1->m_list_rbc_custom_orientation;
  if ( &v1->m_list_rbc_custom_orientation != v35 )
  {
    do
    {
      v37 = v35->m_list_count;
      if ( v37 )
        ++*(_DWORD *)(v37 + 264);
      v38 = v35->m_list_count_high_water;
      if ( v38 )
        ++*(_DWORD *)(v38 + 264);
      v35 = (phys_free_list<rigid_body_constraint_custom_orientation> *)v35->m_dummy_head.m_next_T_internal;
    }
    while ( (phys_free_list<rigid_body_constraint_custom_orientation> *)v36 != v35 );
    v1 = g_physics_system;
  }
  v39 = (phys_free_list<rigid_body_constraint_custom_path> *)v1->m_list_rbc_custom_path.m_dummy_head.m_next_T_internal;
  v40 = (int)&v1->m_list_rbc_custom_path;
  if ( &v1->m_list_rbc_custom_path != v39 )
  {
    do
    {
      v41 = v39->m_ptr_list[0];
      if ( v41 )
        ++v41[2].m_next;
      v42 = v39->m_ptr_list[1];
      if ( v42 )
        ++v42[2].m_next;
      v39 = (phys_free_list<rigid_body_constraint_custom_path> *)v39->m_dummy_head.m_next_T_internal;
    }
    while ( (phys_free_list<rigid_body_constraint_custom_path> *)v40 != v39 );
    v1 = g_physics_system;
  }
  v43 = v1->m_list_rbc_contact.m_dummy_head.m_next_T_internal;
  for ( i = (int)&v1->m_list_rbc_contact;
        (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)i != v43;
        v43 = v43->m_next_T_internal )
  {
    v45 = v43[2].m_next_T_internal;
    for ( j = 0; v45; v45 = v45[6].m_prev_T_internal )
      j += (int)v45[4].m_prev_T_internal;
    v47 = v43[3].m_prev_T_internal;
    for ( k = 0; v47; v47 = v47[6].m_prev_T_internal )
      k += (int)v47[4].m_prev_T_internal;
    if ( k <= j )
      k = j;
    v49 = v43[1].m_prev_T_internal;
    if ( v49 )
    {
      v49[33].m_next_T_internal = (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)((char *)v49[33].m_next_T_internal + k);
      v43[1].m_prev_T_internal[31].m_next_T_internal = (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)((_DWORD)v43[1].m_prev_T_internal[31].m_next_T_internal | 0x100);
    }
    if ( v43[1].m_next_T_internal )
    {
      v43[1].m_next_T_internal[33].m_next_T_internal = (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)((char *)v43[1].m_next_T_internal[33].m_next_T_internal + k);
      v43[1].m_next_T_internal[31].m_next_T_internal = (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)((_DWORD)v43[1].m_next_T_internal[31].m_next_T_internal | 0x100);
    }
  }
}

/*
==============
phys_sys::create_rigid_body
==============
*/
rigid_body *phys_sys::create_rigid_body(const int no_error)
{
  return phys_free_list<rigid_body>::add(
           &g_physics_system->m_list_rigid_body,
           no_error,
           "POOL OUT OF MEMORY, rigid_body, INCREASE phys_mem_info::m_num_rigid_body.");
}

/*
==============
phys_sys::destroy
==============
*/
void phys_sys::destroy(rigid_body_constraint_point *const rbc)
{
  phys_free_list<rigid_body_constraint_point>::remove(&g_physics_system->m_list_rbc_point, rbc);
}

/*
==============
phys_sys::destroy
==============
*/
void phys_sys::destroy(rigid_body_constraint_hinge *const rbc)
{
  physics_system *v1; // edi

  v1 = g_physics_system;
  if ( rbc )
  {
    PMM_VALIDATE(&rbc[-1].m_ps_cache[6], 0xF0u, 0x10u);
    phys_free_list<rigid_body_constraint_wheel>::remove(
      (phys_free_list<rigid_body_constraint_wheel> *)&v1->m_list_rbc_hinge,
      (phys_free_list<rigid_body_constraint_wheel>::T_internal *)&rbc[-1].m_ps_cache[6]);
  }
}

/*
==============
phys_sys::destroy
==============
*/
void phys_sys::destroy(rigid_body_constraint_distance *const rbc)
{
  physics_system *v1; // edi

  v1 = g_physics_system;
  if ( rbc )
  {
    PMM_VALIDATE(&rbc[-1].m_ps_cache_list[2], 0x80u, 0x10u);
    phys_free_list<broad_phase_group>::remove(
      (phys_free_list<broad_phase_group> *)&v1->m_list_rbc_dist,
      (phys_free_list<broad_phase_group>::T_internal *)&rbc[-1].m_ps_cache_list[2]);
  }
}

/*
==============
phys_sys::destroy
==============
*/
void phys_sys::destroy(rigid_body_constraint_ragdoll *const rbc)
{
  physics_system *v1; // edi

  v1 = g_physics_system;
  if ( rbc )
  {
    PMM_VALIDATE(&rbc[-1].m_joint_limits_count, 0x140u, 0x10u);
    phys_free_list<rigid_body_constraint_ragdoll>::remove(
      &v1->m_list_rbc_ragdoll,
      (phys_free_list<rigid_body_constraint_ragdoll>::T_internal *)&rbc[-1].m_joint_limits_count);
  }
}

/*
==============
phys_sys::destroy
==============
*/
void phys_sys::destroy(rigid_body_constraint_wheel *const rbc)
{
  physics_system *v1; // edi

  v1 = g_physics_system;
  if ( rbc )
  {
    PMM_VALIDATE(&rbc[-1].m_ps_cache_list[3], 0xF0u, 0x10u);
    phys_free_list<rigid_body_constraint_wheel>::remove(
      &v1->m_list_rbc_wheel,
      (phys_free_list<rigid_body_constraint_wheel>::T_internal *)&rbc[-1].m_ps_cache_list[3]);
  }
}

/*
==============
phys_sys::destroy
==============
*/
void phys_sys::destroy(rigid_body_constraint_angular_actuator *const rbc)
{
  physics_system *v1; // edi

  v1 = g_physics_system;
  if ( rbc )
  {
    PMM_VALIDATE(&rbc[-1].m_ps_cache_list[1], 0xE0u, 0x10u);
    phys_free_list<rigid_body_constraint_angular_actuator>::remove(
      &v1->m_list_rbc_angular_actuator,
      (phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *)&rbc[-1].m_ps_cache_list[1]);
  }
}

/*
==============
phys_sys::destroy
==============
*/
void phys_sys::destroy(rigid_body_constraint_upright *const rbc)
{
  physics_system *v1; // edi

  v1 = g_physics_system;
  if ( rbc )
  {
    PMM_VALIDATE(rbc[-1].m_ps_cache_list, 0xD0u, 0x10u);
    phys_free_list<rigid_body_constraint_upright>::remove(
      &v1->m_list_rbc_upright,
      (phys_free_list<rigid_body_constraint_upright>::T_internal *)rbc[-1].m_ps_cache_list);
  }
}

/*
==============
phys_sys::destroy
==============
*/
void phys_sys::destroy(rigid_body_constraint_custom_orientation *const rbc)
{
  phys_free_list<rigid_body_constraint_custom_orientation>::remove(
    &g_physics_system->m_list_rbc_custom_orientation,
    rbc);
}

/*
==============
phys_sys::destroy
==============
*/
void phys_sys::destroy(rigid_body_constraint_custom_path *const rbc)
{
  physics_system *v1; // edi

  v1 = g_physics_system;
  if ( rbc )
  {
    PMM_VALIDATE(&rbc[-1].m_list_psc[1], 0xA0u, 0x10u);
    phys_free_list<rigid_body_constraint_custom_path>::remove(
      &v1->m_list_rbc_custom_path,
      (phys_free_list<rigid_body_constraint_custom_path>::T_internal *)&rbc[-1].m_list_psc[1]);
  }
}

/*
==============
phys_sys::destroy_all_unused_user_rigid_body
==============
*/
void phys_sys::destroy_all_unused_user_rigid_body()
{
  physics_system *v0; // ecx
  phys_free_list<user_rigid_body>::T_internal_base *v1; // eax
  phys_free_list<user_rigid_body> *v2; // edi
  bool v3; // zf
  int v4; // eax
  phys_free_list<user_rigid_body>::T_internal_base *v5; // ebx
  phys_free_list<user_rigid_body>::T_internal *v6; // esi
  phys_free_list<user_rigid_body>::T_internal_base *v7; // eax
  phys_free_list<user_rigid_body>::T_internal_base *v8; // ecx

  v0 = g_physics_system;
  v1 = g_physics_system->m_list_user_rigid_body.m_dummy_head.m_next_T_internal;
  v2 = &g_physics_system->m_list_user_rigid_body;
  if ( &g_physics_system->m_list_user_rigid_body != (phys_free_list<user_rigid_body> *)v1 )
  {
    do
    {
      if ( v1[35].m_prev_T_internal )
      {
        v1 = v1->m_next_T_internal;
      }
      else
      {
        v3 = &v1[2] == NULL;
        v4 = (int)&v1[2];
        v5 = *(phys_free_list<user_rigid_body>::T_internal_base **)(v4 - 12);
        if ( !v3 )
        {
          v6 = (phys_free_list<user_rigid_body>::T_internal *)(v4 - 16);
          PMM_VALIDATE((void *)(v4 - 16), 0x1D0u, 0x10u);
          if ( !v6 )
          {
            if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
              __debugbreak();
          }
          --v2->m_list_count;
          phys_free_list<user_rigid_body>::debug_remove(v2, v6);
          v7 = v6->m_next_T_internal;
          v8 = v6->m_prev_T_internal;
          v8->m_next_T_internal = v7;
          v7->m_prev_T_internal = v8;
          PMM_FREE(v6, 0x1D0u, 0x10u);
          v0 = g_physics_system;
        }
        v1 = v5;
      }
      v2 = &v0->m_list_user_rigid_body;
    }
    while ( &v0->m_list_user_rigid_body != (phys_free_list<user_rigid_body> *)v1 );
  }
}

/*
==============
phys_sys::create_user_rigid_body
==============
*/
user_rigid_body *phys_sys::create_user_rigid_body(const int no_error)
{
  return phys_free_list<user_rigid_body>::add(
           &g_physics_system->m_list_user_rigid_body,
           no_error,
           "POOL OUT OF MEMORY, user_rigid_body, INCREASE phys_mem_info::m_num_user_rigid_body.");
}

/*
==============
phys_sys::destroy
==============
*/
void phys_sys::destroy(rigid_body_constraint_contact *const rbc)
{
  physics_system *v1; // edi

  v1 = g_physics_system;
  if ( rbc )
  {
    PMM_VALIDATE(&rbc[-1].m_avl_key, 0x38u, 4u);
    phys_free_list<rigid_body_constraint_contact>::remove(
      &v1->m_list_rbc_contact,
      (phys_free_list<rigid_body_constraint_contact>::T_internal *)&rbc[-1].m_avl_key);
  }
}

/*
==============
phys_sys::destroy_all_user_rigid_body
==============
*/
void phys_sys::destroy_all_user_rigid_body()
{
  physics_system *v0; // esi
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v1; // eax
  phys_free_list<rigid_body_constraint_point> *v2; // edi
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v3; // edx
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v4; // edx
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v5; // ebx
  phys_free_list<rigid_body_constraint_point>::T_internal *v6; // esi
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v7; // eax
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v8; // ecx
  phys_free_list<rigid_body_constraint_hinge> *v9; // ecx
  phys_free_list<rigid_body_constraint_wheel> *i; // edi
  rigid_body_constraint_hinge *v11; // edx
  rigid_body_constraint_hinge *v12; // edx
  phys_free_list<rigid_body_constraint_hinge> *v13; // ebx
  phys_free_list<rigid_body_constraint_wheel>::T_internal *v14; // esi
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v15; // eax
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v16; // ecx
  phys_free_list<rigid_body_constraint_distance> *v17; // ecx
  phys_free_list<broad_phase_group> *j; // edi
  rigid_body_constraint_distance *v19; // edx
  rigid_body_constraint_distance *v20; // edx
  phys_free_list<rigid_body_constraint_distance> *v21; // ebx
  phys_free_list<broad_phase_group>::T_internal *v22; // esi
  phys_free_list<broad_phase_group>::T_internal_base *v23; // eax
  phys_free_list<broad_phase_group>::T_internal_base *v24; // ecx
  phys_free_list<rigid_body_constraint_ragdoll> *v25; // ecx
  phys_free_list<rigid_body_constraint_ragdoll> *k; // edi
  rigid_body_constraint_ragdoll *v27; // edx
  rigid_body_constraint_ragdoll *v28; // edx
  phys_free_list<rigid_body_constraint_ragdoll> *v29; // ebx
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal *v30; // esi
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *v31; // eax
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *v32; // ecx
  phys_free_list<rigid_body_constraint_wheel>::T_internal *v33; // ecx
  phys_free_list<rigid_body_constraint_wheel> *l; // edi
  rigid_body *v35; // edx
  rigid_body *v36; // edx
  phys_free_list<rigid_body_constraint_wheel>::T_internal *v37; // ebx
  phys_free_list<rigid_body_constraint_wheel>::T_internal *v38; // esi
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v39; // eax
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v40; // ecx
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *v41; // ecx
  phys_free_list<rigid_body_constraint_angular_actuator> *m; // edi
  rigid_body *v43; // edx
  rigid_body *v44; // edx
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *v45; // ebx
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *v46; // esi
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *v47; // eax
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *v48; // ecx
  phys_free_list<rigid_body_constraint_upright>::T_internal *v49; // ecx
  phys_free_list<rigid_body_constraint_upright> *n; // edi
  rigid_body *v51; // edx
  rigid_body *v52; // edx
  phys_free_list<rigid_body_constraint_upright>::T_internal *v53; // ebx
  phys_free_list<rigid_body_constraint_upright>::T_internal *v54; // esi
  phys_free_list<rigid_body_constraint_upright>::T_internal_base *v55; // eax
  phys_free_list<rigid_body_constraint_upright>::T_internal_base *v56; // ecx
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *v57; // ecx
  phys_free_list<rigid_body_constraint_custom_orientation> *ii; // edi
  rigid_body *v59; // edx
  rigid_body *v60; // edx
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *v61; // ebx
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *v62; // esi
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *v63; // eax
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *v64; // ecx
  phys_free_list<rigid_body_constraint_custom_path>::T_internal *v65; // ecx
  phys_free_list<rigid_body_constraint_custom_path> *jj; // edi
  rigid_body *v67; // edx
  rigid_body *v68; // edx
  phys_free_list<rigid_body_constraint_custom_path>::T_internal *v69; // ebx
  phys_free_list<rigid_body_constraint_custom_path>::T_internal *v70; // esi
  phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *v71; // eax
  phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *v72; // ecx
  phys_free_list<rigid_body_constraint_contact>::T_internal *v73; // ecx
  phys_free_list<rigid_body_constraint_contact> *kk; // edi
  rigid_body *v75; // edx
  rigid_body *v76; // edx
  phys_free_list<rigid_body_constraint_contact>::T_internal *v77; // ebx
  phys_free_list<rigid_body_constraint_contact>::T_internal *v78; // esi
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v79; // ecx
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v80; // eax

  v0 = g_physics_system;
  v1 = g_physics_system->m_list_rbc_point.m_dummy_head.m_next_T_internal;
  v2 = &g_physics_system->m_list_rbc_point;
  if ( &g_physics_system->m_list_rbc_point != (phys_free_list<rigid_body_constraint_point> *)v1 )
  {
    do
    {
      v3 = v1[2].m_prev_T_internal;
      if ( v3 && (_DWORD)v3[31].m_next_T_internal & 0x20
        || (v4 = v1[2].m_next_T_internal) != NULL && (_DWORD)v4[31].m_next_T_internal & 0x20 )
      {
        v5 = v1->m_next_T_internal;
        if ( v1 != (phys_free_list<rigid_body_constraint_point>::T_internal_base *)-16 )
        {
          v6 = (phys_free_list<rigid_body_constraint_point>::T_internal *)v1;
          PMM_VALIDATE(v1, 0x70u, 0x10u);
          if ( !v6 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
            __debugbreak();
          --v2->m_list_count;
          phys_free_list<rigid_body_constraint_point>::debug_remove(v2, v6);
          v7 = v6->m_next_T_internal;
          v8 = v6->m_prev_T_internal;
          v8->m_next_T_internal = v7;
          v7->m_prev_T_internal = v8;
          PMM_FREE(v6, 0x70u, 0x10u);
          v0 = g_physics_system;
        }
        v1 = v5;
      }
      else
      {
        v1 = v1->m_next_T_internal;
      }
      v2 = &v0->m_list_rbc_point;
    }
    while ( &v0->m_list_rbc_point != (phys_free_list<rigid_body_constraint_point> *)v1 );
  }
  v9 = (phys_free_list<rigid_body_constraint_hinge> *)v0->m_list_rbc_hinge.m_dummy_head.m_next_T_internal;
  for ( i = (phys_free_list<rigid_body_constraint_wheel> *)&v0->m_list_rbc_hinge;
        &v0->m_list_rbc_hinge != v9;
        i = (phys_free_list<rigid_body_constraint_wheel> *)&v0->m_list_rbc_hinge )
  {
    v11 = v9->m_ptr_list[0];
    if ( v11 && LOBYTE(v11[1].m_b2_r_loc.w) & 0x20
      || (v12 = v9->m_ptr_list[1]) != NULL && LOBYTE(v12[1].m_b2_r_loc.w) & 0x20 )
    {
      v13 = (phys_free_list<rigid_body_constraint_hinge> *)v9->m_dummy_head.m_next_T_internal;
      if ( v9 != (phys_free_list<rigid_body_constraint_hinge> *)-16 )
      {
        v14 = (phys_free_list<rigid_body_constraint_wheel>::T_internal *)v9;
        PMM_VALIDATE(v9, 0xF0u, 0x10u);
        if ( !v14 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --i->m_list_count;
        phys_free_list<rigid_body_constraint_wheel>::debug_remove(i, v14);
        v15 = v14->m_next_T_internal;
        v16 = v14->m_prev_T_internal;
        v16->m_next_T_internal = v15;
        v15->m_prev_T_internal = v16;
        PMM_FREE(v14, 0xF0u, 0x10u);
        v0 = g_physics_system;
      }
      v9 = v13;
    }
    else
    {
      v9 = (phys_free_list<rigid_body_constraint_hinge> *)v9->m_dummy_head.m_next_T_internal;
    }
  }
  v17 = (phys_free_list<rigid_body_constraint_distance> *)v0->m_list_rbc_dist.m_dummy_head.m_next_T_internal;
  for ( j = (phys_free_list<broad_phase_group> *)&v0->m_list_rbc_dist;
        &v0->m_list_rbc_dist != v17;
        j = (phys_free_list<broad_phase_group> *)&v0->m_list_rbc_dist )
  {
    v19 = v17->m_ptr_list[0];
    if ( v19 && LOBYTE(v19[2].m_max_distance_vel) & 0x20
      || (v20 = v17->m_ptr_list[1]) != NULL && LOBYTE(v20[2].m_max_distance_vel) & 0x20 )
    {
      v21 = (phys_free_list<rigid_body_constraint_distance> *)v17->m_dummy_head.m_next_T_internal;
      if ( v17 != (phys_free_list<rigid_body_constraint_distance> *)-16 )
      {
        v22 = (phys_free_list<broad_phase_group>::T_internal *)v17;
        PMM_VALIDATE(v17, 0x80u, 0x10u);
        if ( !v22 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --j->m_list_count;
        phys_free_list<broad_phase_group>::debug_remove(j, v22);
        v23 = v22->m_next_T_internal;
        v24 = v22->m_prev_T_internal;
        v24->m_next_T_internal = v23;
        v23->m_prev_T_internal = v24;
        PMM_FREE(v22, 0x80u, 0x10u);
        v0 = g_physics_system;
      }
      v17 = v21;
    }
    else
    {
      v17 = (phys_free_list<rigid_body_constraint_distance> *)v17->m_dummy_head.m_next_T_internal;
    }
  }
  v25 = (phys_free_list<rigid_body_constraint_ragdoll> *)v0->m_list_rbc_ragdoll.m_dummy_head.m_next_T_internal;
  for ( k = &v0->m_list_rbc_ragdoll; &v0->m_list_rbc_ragdoll != v25; k = &v0->m_list_rbc_ragdoll )
  {
    v27 = v25->m_ptr_list[0];
    if ( v27 && LOBYTE(v27->m_joint_limits[1].m_b1_ud_loc.w) & 0x20
      || (v28 = v25->m_ptr_list[1]) != NULL && LOBYTE(v28->m_joint_limits[1].m_b1_ud_loc.w) & 0x20 )
    {
      v29 = (phys_free_list<rigid_body_constraint_ragdoll> *)v25->m_dummy_head.m_next_T_internal;
      if ( v25 != (phys_free_list<rigid_body_constraint_ragdoll> *)-16 )
      {
        v30 = (phys_free_list<rigid_body_constraint_ragdoll>::T_internal *)v25;
        PMM_VALIDATE(v25, 0x140u, 0x10u);
        if ( !v30 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --k->m_list_count;
        phys_free_list<rigid_body_constraint_ragdoll>::debug_remove(k, v30);
        v31 = v30->m_next_T_internal;
        v32 = v30->m_prev_T_internal;
        v32->m_next_T_internal = v31;
        v31->m_prev_T_internal = v32;
        PMM_FREE(v30, 0x140u, 0x10u);
        v0 = g_physics_system;
      }
      v25 = v29;
    }
    else
    {
      v25 = (phys_free_list<rigid_body_constraint_ragdoll> *)v25->m_dummy_head.m_next_T_internal;
    }
  }
  v33 = (phys_free_list<rigid_body_constraint_wheel>::T_internal *)v0->m_list_rbc_wheel.m_dummy_head.m_next_T_internal;
  for ( l = &v0->m_list_rbc_wheel;
        &v0->m_list_rbc_wheel != (phys_free_list<rigid_body_constraint_wheel> *)v33;
        l = &v0->m_list_rbc_wheel )
  {
    v35 = v33->m_data.b1;
    if ( v35 && v35->m_flags & 0x20 || (v36 = v33->m_data.b2) != NULL && v36->m_flags & 0x20 )
    {
      v37 = (phys_free_list<rigid_body_constraint_wheel>::T_internal *)v33->m_next_T_internal;
      if ( v33 != (phys_free_list<rigid_body_constraint_wheel>::T_internal *)-16 )
      {
        v38 = v33;
        PMM_VALIDATE(v33, 0xF0u, 0x10u);
        if ( !v38 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --l->m_list_count;
        phys_free_list<rigid_body_constraint_wheel>::debug_remove(l, v38);
        v39 = v38->m_next_T_internal;
        v40 = v38->m_prev_T_internal;
        v40->m_next_T_internal = v39;
        v39->m_prev_T_internal = v40;
        PMM_FREE(v38, 0xF0u, 0x10u);
        v0 = g_physics_system;
      }
      v33 = v37;
    }
    else
    {
      v33 = (phys_free_list<rigid_body_constraint_wheel>::T_internal *)v33->m_next_T_internal;
    }
  }
  v41 = (phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *)v0->m_list_rbc_angular_actuator.m_dummy_head.m_next_T_internal;
  for ( m = &v0->m_list_rbc_angular_actuator;
        &v0->m_list_rbc_angular_actuator != (phys_free_list<rigid_body_constraint_angular_actuator> *)v41;
        m = &v0->m_list_rbc_angular_actuator )
  {
    v43 = v41->m_data.b1;
    if ( v43 && v43->m_flags & 0x20 || (v44 = v41->m_data.b2) != NULL && v44->m_flags & 0x20 )
    {
      v45 = (phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *)v41->m_next_T_internal;
      if ( v41 != (phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *)-16 )
      {
        v46 = v41;
        PMM_VALIDATE(v41, 0xE0u, 0x10u);
        if ( !v46 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --m->m_list_count;
        phys_free_list<rigid_body_constraint_angular_actuator>::debug_remove(m, v46);
        v47 = v46->m_next_T_internal;
        v48 = v46->m_prev_T_internal;
        v48->m_next_T_internal = v47;
        v47->m_prev_T_internal = v48;
        PMM_FREE(v46, 0xE0u, 0x10u);
        v0 = g_physics_system;
      }
      v41 = v45;
    }
    else
    {
      v41 = (phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *)v41->m_next_T_internal;
    }
  }
  v49 = (phys_free_list<rigid_body_constraint_upright>::T_internal *)v0->m_list_rbc_upright.m_dummy_head.m_next_T_internal;
  for ( n = &v0->m_list_rbc_upright;
        &v0->m_list_rbc_upright != (phys_free_list<rigid_body_constraint_upright> *)v49;
        n = &v0->m_list_rbc_upright )
  {
    v51 = v49->m_data.b1;
    if ( v51 && v51->m_flags & 0x20 || (v52 = v49->m_data.b2) != NULL && v52->m_flags & 0x20 )
    {
      v53 = (phys_free_list<rigid_body_constraint_upright>::T_internal *)v49->m_next_T_internal;
      if ( v49 != (phys_free_list<rigid_body_constraint_upright>::T_internal *)-16 )
      {
        v54 = v49;
        PMM_VALIDATE(v49, 0xD0u, 0x10u);
        if ( !v54 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --n->m_list_count;
        phys_free_list<rigid_body_constraint_upright>::debug_remove(n, v54);
        v55 = v54->m_next_T_internal;
        v56 = v54->m_prev_T_internal;
        v56->m_next_T_internal = v55;
        v55->m_prev_T_internal = v56;
        PMM_FREE(v54, 0xD0u, 0x10u);
        v0 = g_physics_system;
      }
      v49 = v53;
    }
    else
    {
      v49 = (phys_free_list<rigid_body_constraint_upright>::T_internal *)v49->m_next_T_internal;
    }
  }
  v57 = (phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *)v0->m_list_rbc_custom_orientation.m_dummy_head.m_next_T_internal;
  for ( ii = &v0->m_list_rbc_custom_orientation;
        &v0->m_list_rbc_custom_orientation != (phys_free_list<rigid_body_constraint_custom_orientation> *)v57;
        ii = &v0->m_list_rbc_custom_orientation )
  {
    v59 = v57->m_data.b1;
    if ( v59 && v59->m_flags & 0x20 || (v60 = v57->m_data.b2) != NULL && v60->m_flags & 0x20 )
    {
      v61 = (phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *)v57->m_next_T_internal;
      if ( v57 != (phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *)-8 )
      {
        v62 = v57;
        PMM_VALIDATE(v57, 0x40u, 4u);
        if ( !v62 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --ii->m_list_count;
        phys_free_list<rigid_body_constraint_custom_orientation>::debug_remove(ii, v62);
        v63 = v62->m_next_T_internal;
        v64 = v62->m_prev_T_internal;
        v64->m_next_T_internal = v63;
        v63->m_prev_T_internal = v64;
        PMM_FREE(v62, 0x40u, 4u);
        v0 = g_physics_system;
      }
      v57 = v61;
    }
    else
    {
      v57 = (phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *)v57->m_next_T_internal;
    }
  }
  v65 = (phys_free_list<rigid_body_constraint_custom_path>::T_internal *)v0->m_list_rbc_custom_path.m_dummy_head.m_next_T_internal;
  for ( jj = &v0->m_list_rbc_custom_path;
        &v0->m_list_rbc_custom_path != (phys_free_list<rigid_body_constraint_custom_path> *)v65;
        jj = &v0->m_list_rbc_custom_path )
  {
    v67 = v65->m_data.b1;
    if ( v67 && v67->m_flags & 0x20 || (v68 = v65->m_data.b2) != NULL && v68->m_flags & 0x20 )
    {
      v69 = (phys_free_list<rigid_body_constraint_custom_path>::T_internal *)v65->m_next_T_internal;
      if ( v65 != (phys_free_list<rigid_body_constraint_custom_path>::T_internal *)-16 )
      {
        v70 = v65;
        PMM_VALIDATE(v65, 0xA0u, 0x10u);
        if ( !v70 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --jj->m_list_count;
        phys_free_list<rigid_body_constraint_custom_path>::debug_remove(jj, v70);
        v71 = v70->m_next_T_internal;
        v72 = v70->m_prev_T_internal;
        v72->m_next_T_internal = v71;
        v71->m_prev_T_internal = v72;
        PMM_FREE(v70, 0xA0u, 0x10u);
        v0 = g_physics_system;
      }
      v65 = v69;
    }
    else
    {
      v65 = (phys_free_list<rigid_body_constraint_custom_path>::T_internal *)v65->m_next_T_internal;
    }
  }
  v73 = (phys_free_list<rigid_body_constraint_contact>::T_internal *)v0->m_list_rbc_contact.m_dummy_head.m_next_T_internal;
  for ( kk = &v0->m_list_rbc_contact;
        &v0->m_list_rbc_contact != (phys_free_list<rigid_body_constraint_contact> *)v73;
        kk = &v0->m_list_rbc_contact )
  {
    v75 = v73->m_data.b1;
    if ( v75 && v75->m_flags & 0x20 || (v76 = v73->m_data.b2) != NULL && v76->m_flags & 0x20 )
    {
      v77 = (phys_free_list<rigid_body_constraint_contact>::T_internal *)v73->m_next_T_internal;
      if ( v73 != (phys_free_list<rigid_body_constraint_contact>::T_internal *)-8 )
      {
        v78 = v73;
        PMM_VALIDATE(v73, 0x38u, 4u);
        if ( !v78 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --kk->m_list_count;
        phys_free_list<rigid_body_constraint_contact>::debug_remove(kk, v78);
        v79 = v78->m_prev_T_internal;
        v80 = v78->m_next_T_internal;
        v79->m_next_T_internal = v80;
        v80->m_prev_T_internal = v79;
        rigid_body_constraint_contact::~rigid_body_constraint_contact(&v78->m_data);
        PMM_FREE(v78, 0x38u, 4u);
        v0 = g_physics_system;
      }
      v73 = v77;
    }
    else
    {
      v73 = (phys_free_list<rigid_body_constraint_contact>::T_internal *)v73->m_next_T_internal;
    }
  }
  phys_free_list<user_rigid_body>::remove_all(&v0->m_list_user_rigid_body);
}

/*
==============
phys_sys::destroy_all_constraint
==============
*/
void phys_sys::destroy_all_constraint(rigid_body *const rb)
{
  rigid_body *v1; // esi
  physics_system *v2; // ebx
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v3; // eax
  phys_free_list<rigid_body_constraint_point> *v4; // edi
  rigid_body *v5; // edx
  rigid_body *v6; // edx
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v7; // ebx
  phys_free_list<rigid_body_constraint_point>::T_internal *v8; // esi
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v9; // eax
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v10; // ecx
  phys_free_list<rigid_body_constraint_wheel>::T_internal *v11; // ecx
  phys_free_list<rigid_body_constraint_wheel> *v12; // edi
  rigid_body *v13; // edx
  rigid_body *v14; // edx
  phys_free_list<rigid_body_constraint_wheel>::T_internal *v15; // ebx
  phys_free_list<rigid_body_constraint_wheel>::T_internal *v16; // esi
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v17; // eax
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v18; // ecx
  phys_free_list<rigid_body_constraint_distance> *v19; // ecx
  phys_free_list<broad_phase_group> *i; // edi
  rigid_body *v21; // edx
  rigid_body *v22; // edx
  phys_free_list<rigid_body_constraint_distance> *v23; // ebx
  phys_free_list<broad_phase_group>::T_internal *v24; // esi
  phys_free_list<broad_phase_group>::T_internal_base *v25; // eax
  phys_free_list<broad_phase_group>::T_internal_base *v26; // ecx
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal *v27; // ecx
  phys_free_list<rigid_body_constraint_ragdoll> *v28; // edi
  rigid_body *v29; // edx
  rigid_body *v30; // edx
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal *v31; // ebx
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal *v32; // esi
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *v33; // eax
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *v34; // ecx
  phys_free_list<rigid_body_constraint_wheel>::T_internal *v35; // ecx
  phys_free_list<rigid_body_constraint_wheel> *j; // edi
  rigid_body *v37; // edx
  rigid_body *v38; // edx
  phys_free_list<rigid_body_constraint_wheel>::T_internal *v39; // ebx
  phys_free_list<rigid_body_constraint_wheel>::T_internal *v40; // esi
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v41; // eax
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v42; // ecx
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *v43; // ecx
  phys_free_list<rigid_body_constraint_angular_actuator> *v44; // edi
  rigid_body *v45; // edx
  rigid_body *v46; // edx
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *v47; // ebx
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *v48; // esi
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *v49; // eax
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *v50; // ecx
  phys_free_list<rigid_body_constraint_upright>::T_internal *v51; // ecx
  phys_free_list<rigid_body_constraint_upright> *k; // edi
  rigid_body *v53; // edx
  rigid_body *v54; // edx
  phys_free_list<rigid_body_constraint_upright>::T_internal *v55; // ebx
  phys_free_list<rigid_body_constraint_upright>::T_internal *v56; // esi
  phys_free_list<rigid_body_constraint_upright>::T_internal_base *v57; // eax
  phys_free_list<rigid_body_constraint_upright>::T_internal_base *v58; // ecx
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *v59; // ecx
  phys_free_list<rigid_body_constraint_custom_orientation> *v60; // edi
  rigid_body *v61; // edx
  rigid_body *v62; // edx
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *v63; // ebx
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *v64; // esi
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *v65; // eax
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *v66; // ecx
  phys_free_list<rigid_body_constraint_custom_path>::T_internal *v67; // ecx
  phys_free_list<rigid_body_constraint_custom_path> *l; // edi
  rigid_body *v69; // edx
  rigid_body *v70; // edx
  phys_free_list<rigid_body_constraint_custom_path>::T_internal *v71; // ebx
  phys_free_list<rigid_body_constraint_custom_path>::T_internal *v72; // esi
  phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *v73; // eax
  phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *v74; // ecx
  phys_free_list<rigid_body_constraint_contact>::T_internal *v75; // ecx
  phys_free_list<rigid_body_constraint_contact> *v76; // edi
  rigid_body *v77; // edx
  rigid_body *v78; // edx
  phys_free_list<rigid_body_constraint_contact>::T_internal *v79; // ebx
  phys_free_list<rigid_body_constraint_contact>::T_internal *v80; // esi
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v81; // ecx
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v82; // eax

  v1 = rb;
  phys_sys::fixup_wheel_constraints(rb);
  v2 = g_physics_system;
  v3 = g_physics_system->m_list_rbc_point.m_dummy_head.m_next_T_internal;
  v4 = &g_physics_system->m_list_rbc_point;
  if ( &g_physics_system->m_list_rbc_point != (phys_free_list<rigid_body_constraint_point> *)v3 )
  {
    do
    {
      v5 = (rigid_body *)v3[2].m_prev_T_internal;
      if ( v5 && v5 == v1 || (v6 = (rigid_body *)v3[2].m_next_T_internal) != NULL && v6 == v1 )
      {
        v7 = v3->m_next_T_internal;
        if ( v3 != (phys_free_list<rigid_body_constraint_point>::T_internal_base *)-16 )
        {
          v8 = (phys_free_list<rigid_body_constraint_point>::T_internal *)v3;
          PMM_VALIDATE(v3, 0x70u, 0x10u);
          if ( !v8 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
            __debugbreak();
          --v4->m_list_count;
          phys_free_list<rigid_body_constraint_point>::debug_remove(v4, v8);
          v9 = v8->m_next_T_internal;
          v10 = v8->m_prev_T_internal;
          v10->m_next_T_internal = v9;
          v9->m_prev_T_internal = v10;
          PMM_FREE(v8, 0x70u, 0x10u);
          v1 = rb;
        }
        v3 = v7;
        v2 = g_physics_system;
      }
      else
      {
        v3 = v3->m_next_T_internal;
      }
      v4 = &v2->m_list_rbc_point;
    }
    while ( &v2->m_list_rbc_point != (phys_free_list<rigid_body_constraint_point> *)v3 );
  }
  v11 = (phys_free_list<rigid_body_constraint_wheel>::T_internal *)v2->m_list_rbc_hinge.m_dummy_head.m_next_T_internal;
  v12 = (phys_free_list<rigid_body_constraint_wheel> *)&v2->m_list_rbc_hinge;
  if ( &v2->m_list_rbc_hinge != (phys_free_list<rigid_body_constraint_hinge> *)v11 )
  {
    do
    {
      v13 = v11->m_data.b1;
      if ( v13 && v13 == rb || (v14 = v11->m_data.b2) != NULL && v14 == rb )
      {
        v15 = (phys_free_list<rigid_body_constraint_wheel>::T_internal *)v11->m_next_T_internal;
        if ( v11 != (phys_free_list<rigid_body_constraint_wheel>::T_internal *)-16 )
        {
          v16 = v11;
          PMM_VALIDATE(v11, 0xF0u, 0x10u);
          if ( !v16 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
            __debugbreak();
          --v12->m_list_count;
          phys_free_list<rigid_body_constraint_wheel>::debug_remove(v12, v16);
          v17 = v16->m_next_T_internal;
          v18 = v16->m_prev_T_internal;
          v18->m_next_T_internal = v17;
          v17->m_prev_T_internal = v18;
          PMM_FREE(v16, 0xF0u, 0x10u);
        }
        v11 = v15;
      }
      else
      {
        v11 = (phys_free_list<rigid_body_constraint_wheel>::T_internal *)v11->m_next_T_internal;
      }
      v12 = (phys_free_list<rigid_body_constraint_wheel> *)&g_physics_system->m_list_rbc_hinge;
    }
    while ( &g_physics_system->m_list_rbc_hinge != (phys_free_list<rigid_body_constraint_hinge> *)v11 );
    v2 = g_physics_system;
  }
  v19 = (phys_free_list<rigid_body_constraint_distance> *)v2->m_list_rbc_dist.m_dummy_head.m_next_T_internal;
  for ( i = (phys_free_list<broad_phase_group> *)&v2->m_list_rbc_dist;
        &v2->m_list_rbc_dist != v19;
        i = (phys_free_list<broad_phase_group> *)&v2->m_list_rbc_dist )
  {
    v21 = (rigid_body *)v19->m_ptr_list[0];
    if ( v21 && v21 == rb || (v22 = (rigid_body *)v19->m_ptr_list[1]) != NULL && v22 == rb )
    {
      v23 = (phys_free_list<rigid_body_constraint_distance> *)v19->m_dummy_head.m_next_T_internal;
      if ( v19 != (phys_free_list<rigid_body_constraint_distance> *)-16 )
      {
        v24 = (phys_free_list<broad_phase_group>::T_internal *)v19;
        PMM_VALIDATE(v19, 0x80u, 0x10u);
        if ( !v24 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --i->m_list_count;
        phys_free_list<broad_phase_group>::debug_remove(i, v24);
        v25 = v24->m_next_T_internal;
        v26 = v24->m_prev_T_internal;
        v26->m_next_T_internal = v25;
        v25->m_prev_T_internal = v26;
        PMM_FREE(v24, 0x80u, 0x10u);
      }
      v19 = v23;
      v2 = g_physics_system;
    }
    else
    {
      v19 = (phys_free_list<rigid_body_constraint_distance> *)v19->m_dummy_head.m_next_T_internal;
    }
  }
  v27 = (phys_free_list<rigid_body_constraint_ragdoll>::T_internal *)v2->m_list_rbc_ragdoll.m_dummy_head.m_next_T_internal;
  v28 = &v2->m_list_rbc_ragdoll;
  if ( &v2->m_list_rbc_ragdoll != (phys_free_list<rigid_body_constraint_ragdoll> *)v27 )
  {
    do
    {
      v29 = v27->m_data.b1;
      if ( v29 && v29 == rb || (v30 = v27->m_data.b2) != NULL && v30 == rb )
      {
        v31 = (phys_free_list<rigid_body_constraint_ragdoll>::T_internal *)v27->m_next_T_internal;
        if ( v27 != (phys_free_list<rigid_body_constraint_ragdoll>::T_internal *)-16 )
        {
          v32 = v27;
          PMM_VALIDATE(v27, 0x140u, 0x10u);
          if ( !v32 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
            __debugbreak();
          --v28->m_list_count;
          phys_free_list<rigid_body_constraint_ragdoll>::debug_remove(v28, v32);
          v33 = v32->m_next_T_internal;
          v34 = v32->m_prev_T_internal;
          v34->m_next_T_internal = v33;
          v33->m_prev_T_internal = v34;
          PMM_FREE(v32, 0x140u, 0x10u);
        }
        v27 = v31;
      }
      else
      {
        v27 = (phys_free_list<rigid_body_constraint_ragdoll>::T_internal *)v27->m_next_T_internal;
      }
      v28 = &g_physics_system->m_list_rbc_ragdoll;
    }
    while ( &g_physics_system->m_list_rbc_ragdoll != (phys_free_list<rigid_body_constraint_ragdoll> *)v27 );
    v2 = g_physics_system;
  }
  v35 = (phys_free_list<rigid_body_constraint_wheel>::T_internal *)v2->m_list_rbc_wheel.m_dummy_head.m_next_T_internal;
  for ( j = &v2->m_list_rbc_wheel;
        &v2->m_list_rbc_wheel != (phys_free_list<rigid_body_constraint_wheel> *)v35;
        j = &v2->m_list_rbc_wheel )
  {
    v37 = v35->m_data.b1;
    if ( v37 && v37 == rb || (v38 = v35->m_data.b2) != NULL && v38 == rb )
    {
      v39 = (phys_free_list<rigid_body_constraint_wheel>::T_internal *)v35->m_next_T_internal;
      if ( v35 != (phys_free_list<rigid_body_constraint_wheel>::T_internal *)-16 )
      {
        v40 = v35;
        PMM_VALIDATE(v35, 0xF0u, 0x10u);
        if ( !v40 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --j->m_list_count;
        phys_free_list<rigid_body_constraint_wheel>::debug_remove(j, v40);
        v41 = v40->m_next_T_internal;
        v42 = v40->m_prev_T_internal;
        v42->m_next_T_internal = v41;
        v41->m_prev_T_internal = v42;
        PMM_FREE(v40, 0xF0u, 0x10u);
      }
      v35 = v39;
      v2 = g_physics_system;
    }
    else
    {
      v35 = (phys_free_list<rigid_body_constraint_wheel>::T_internal *)v35->m_next_T_internal;
    }
  }
  v43 = (phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *)v2->m_list_rbc_angular_actuator.m_dummy_head.m_next_T_internal;
  v44 = &v2->m_list_rbc_angular_actuator;
  if ( &v2->m_list_rbc_angular_actuator != (phys_free_list<rigid_body_constraint_angular_actuator> *)v43 )
  {
    do
    {
      v45 = v43->m_data.b1;
      if ( v45 && v45 == rb || (v46 = v43->m_data.b2) != NULL && v46 == rb )
      {
        v47 = (phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *)v43->m_next_T_internal;
        if ( v43 != (phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *)-16 )
        {
          v48 = v43;
          PMM_VALIDATE(v43, 0xE0u, 0x10u);
          if ( !v48 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
            __debugbreak();
          --v44->m_list_count;
          phys_free_list<rigid_body_constraint_angular_actuator>::debug_remove(v44, v48);
          v49 = v48->m_next_T_internal;
          v50 = v48->m_prev_T_internal;
          v50->m_next_T_internal = v49;
          v49->m_prev_T_internal = v50;
          PMM_FREE(v48, 0xE0u, 0x10u);
        }
        v43 = v47;
      }
      else
      {
        v43 = (phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *)v43->m_next_T_internal;
      }
      v44 = &g_physics_system->m_list_rbc_angular_actuator;
    }
    while ( &g_physics_system->m_list_rbc_angular_actuator != (phys_free_list<rigid_body_constraint_angular_actuator> *)v43 );
    v2 = g_physics_system;
  }
  v51 = (phys_free_list<rigid_body_constraint_upright>::T_internal *)v2->m_list_rbc_upright.m_dummy_head.m_next_T_internal;
  for ( k = &v2->m_list_rbc_upright;
        &v2->m_list_rbc_upright != (phys_free_list<rigid_body_constraint_upright> *)v51;
        k = &v2->m_list_rbc_upright )
  {
    v53 = v51->m_data.b1;
    if ( v53 && v53 == rb || (v54 = v51->m_data.b2) != NULL && v54 == rb )
    {
      v55 = (phys_free_list<rigid_body_constraint_upright>::T_internal *)v51->m_next_T_internal;
      if ( v51 != (phys_free_list<rigid_body_constraint_upright>::T_internal *)-16 )
      {
        v56 = v51;
        PMM_VALIDATE(v51, 0xD0u, 0x10u);
        if ( !v56 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --k->m_list_count;
        phys_free_list<rigid_body_constraint_upright>::debug_remove(k, v56);
        v57 = v56->m_next_T_internal;
        v58 = v56->m_prev_T_internal;
        v58->m_next_T_internal = v57;
        v57->m_prev_T_internal = v58;
        PMM_FREE(v56, 0xD0u, 0x10u);
      }
      v51 = v55;
      v2 = g_physics_system;
    }
    else
    {
      v51 = (phys_free_list<rigid_body_constraint_upright>::T_internal *)v51->m_next_T_internal;
    }
  }
  v59 = (phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *)v2->m_list_rbc_custom_orientation.m_dummy_head.m_next_T_internal;
  v60 = &v2->m_list_rbc_custom_orientation;
  if ( &v2->m_list_rbc_custom_orientation != (phys_free_list<rigid_body_constraint_custom_orientation> *)v59 )
  {
    do
    {
      v61 = v59->m_data.b1;
      if ( v61 && v61 == rb || (v62 = v59->m_data.b2) != NULL && v62 == rb )
      {
        v63 = (phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *)v59->m_next_T_internal;
        if ( v59 != (phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *)-8 )
        {
          v64 = v59;
          PMM_VALIDATE(v59, 0x40u, 4u);
          if ( !v64 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
            __debugbreak();
          --v60->m_list_count;
          phys_free_list<rigid_body_constraint_custom_orientation>::debug_remove(v60, v64);
          v65 = v64->m_next_T_internal;
          v66 = v64->m_prev_T_internal;
          v66->m_next_T_internal = v65;
          v65->m_prev_T_internal = v66;
          PMM_FREE(v64, 0x40u, 4u);
        }
        v59 = v63;
      }
      else
      {
        v59 = (phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *)v59->m_next_T_internal;
      }
      v60 = &g_physics_system->m_list_rbc_custom_orientation;
    }
    while ( &g_physics_system->m_list_rbc_custom_orientation != (phys_free_list<rigid_body_constraint_custom_orientation> *)v59 );
    v2 = g_physics_system;
  }
  v67 = (phys_free_list<rigid_body_constraint_custom_path>::T_internal *)v2->m_list_rbc_custom_path.m_dummy_head.m_next_T_internal;
  for ( l = &v2->m_list_rbc_custom_path;
        &v2->m_list_rbc_custom_path != (phys_free_list<rigid_body_constraint_custom_path> *)v67;
        l = &v2->m_list_rbc_custom_path )
  {
    v69 = v67->m_data.b1;
    if ( v69 && v69 == rb || (v70 = v67->m_data.b2) != NULL && v70 == rb )
    {
      v71 = (phys_free_list<rigid_body_constraint_custom_path>::T_internal *)v67->m_next_T_internal;
      if ( v67 != (phys_free_list<rigid_body_constraint_custom_path>::T_internal *)-16 )
      {
        v72 = v67;
        PMM_VALIDATE(v67, 0xA0u, 0x10u);
        if ( !v72 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --l->m_list_count;
        phys_free_list<rigid_body_constraint_custom_path>::debug_remove(l, v72);
        v73 = v72->m_next_T_internal;
        v74 = v72->m_prev_T_internal;
        v74->m_next_T_internal = v73;
        v73->m_prev_T_internal = v74;
        PMM_FREE(v72, 0xA0u, 0x10u);
      }
      v67 = v71;
      v2 = g_physics_system;
    }
    else
    {
      v67 = (phys_free_list<rigid_body_constraint_custom_path>::T_internal *)v67->m_next_T_internal;
    }
  }
  v75 = (phys_free_list<rigid_body_constraint_contact>::T_internal *)v2->m_list_rbc_contact.m_dummy_head.m_next_T_internal;
  v76 = &v2->m_list_rbc_contact;
  if ( &v2->m_list_rbc_contact != (phys_free_list<rigid_body_constraint_contact> *)v75 )
  {
    do
    {
      v77 = v75->m_data.b1;
      if ( v77 && v77 == rb || (v78 = v75->m_data.b2) != NULL && v78 == rb )
      {
        v79 = (phys_free_list<rigid_body_constraint_contact>::T_internal *)v75->m_next_T_internal;
        if ( v75 != (phys_free_list<rigid_body_constraint_contact>::T_internal *)-8 )
        {
          v80 = v75;
          PMM_VALIDATE(v75, 0x38u, 4u);
          if ( !v80 )
          {
            if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
              __debugbreak();
          }
          --v76->m_list_count;
          phys_free_list<rigid_body_constraint_contact>::debug_remove(v76, v80);
          v81 = v80->m_prev_T_internal;
          v82 = v80->m_next_T_internal;
          v81->m_next_T_internal = v82;
          v82->m_prev_T_internal = v81;
          rigid_body_constraint_contact::~rigid_body_constraint_contact(&v80->m_data);
          PMM_FREE(v80, 0x38u, 4u);
        }
        v75 = v79;
      }
      else
      {
        v75 = (phys_free_list<rigid_body_constraint_contact>::T_internal *)v75->m_next_T_internal;
      }
      v76 = &g_physics_system->m_list_rbc_contact;
    }
    while ( &g_physics_system->m_list_rbc_contact != (phys_free_list<rigid_body_constraint_contact> *)v75 );
  }
}

/*
==============
phys_sys::destroy_all_constraint_with_user_rigid_body
==============
*/
void phys_sys::destroy_all_constraint_with_user_rigid_body(rigid_body *const rb)
{
  physics_system *v1; // ebx
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v2; // eax
  phys_free_list<rigid_body_constraint_point> *v3; // edi
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v4; // esi
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v5; // edx
  phys_free_list<rigid_body_constraint_point>::T_internal *v6; // esi
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v7; // eax
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v8; // ecx
  phys_free_list<rigid_body_constraint_wheel>::T_internal *v9; // ecx
  phys_free_list<rigid_body_constraint_wheel> *v10; // edi
  rigid_body *v11; // esi
  rigid_body *v12; // edx
  phys_free_list<rigid_body_constraint_wheel>::T_internal *v13; // ebx
  phys_free_list<rigid_body_constraint_wheel>::T_internal *v14; // esi
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v15; // eax
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v16; // ecx
  phys_free_list<rigid_body_constraint_distance>::T_internal_base *v17; // ecx
  phys_free_list<broad_phase_group> *i; // edi
  phys_free_list<rigid_body_constraint_distance>::T_internal_base *v19; // esi
  phys_free_list<rigid_body_constraint_distance>::T_internal_base *v20; // edx
  phys_free_list<rigid_body_constraint_distance>::T_internal_base *v21; // ebx
  phys_free_list<broad_phase_group>::T_internal *v22; // esi
  phys_free_list<broad_phase_group>::T_internal_base *v23; // eax
  phys_free_list<broad_phase_group>::T_internal_base *v24; // ecx
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *v25; // ecx
  phys_free_list<rigid_body_constraint_ragdoll> *j; // edi
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *v27; // esi
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *v28; // edx
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *v29; // ebx
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal *v30; // esi
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *v31; // eax
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *v32; // ecx
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v33; // ecx
  phys_free_list<rigid_body_constraint_wheel> *k; // edi
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v35; // esi
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v36; // edx
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v37; // ebx
  phys_free_list<rigid_body_constraint_wheel>::T_internal *v38; // esi
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v39; // eax
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v40; // ecx
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *v41; // ecx
  phys_free_list<rigid_body_constraint_angular_actuator> *l; // edi
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *v43; // esi
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *v44; // edx
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *v45; // ebx
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *v46; // esi
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *v47; // eax
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *v48; // ecx
  phys_free_list<rigid_body_constraint_upright>::T_internal_base *v49; // ecx
  phys_free_list<rigid_body_constraint_upright> *m; // edi
  phys_free_list<rigid_body_constraint_upright>::T_internal_base *v51; // esi
  phys_free_list<rigid_body_constraint_upright>::T_internal_base *v52; // edx
  phys_free_list<rigid_body_constraint_upright>::T_internal_base *v53; // ebx
  phys_free_list<rigid_body_constraint_upright>::T_internal *v54; // esi
  phys_free_list<rigid_body_constraint_upright>::T_internal_base *v55; // eax
  phys_free_list<rigid_body_constraint_upright>::T_internal_base *v56; // ecx
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *v57; // ecx
  phys_free_list<rigid_body_constraint_custom_orientation> *n; // edi
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *v59; // esi
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *v60; // edx
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *v61; // ebx
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *v62; // esi
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *v63; // eax
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *v64; // ecx
  phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *v65; // ecx
  phys_free_list<rigid_body_constraint_custom_path> *ii; // edi
  phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *v67; // esi
  phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *v68; // edx
  phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *v69; // ebx
  phys_free_list<rigid_body_constraint_custom_path>::T_internal *v70; // esi
  phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *v71; // eax
  phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *v72; // ecx
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v73; // ecx
  phys_free_list<rigid_body_constraint_contact> *jj; // edi
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v75; // esi
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v76; // edx
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v77; // ebx
  phys_free_list<rigid_body_constraint_contact>::T_internal *v78; // esi
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v79; // ecx
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v80; // eax
  phys_free_list<rigid_body_constraint_point>::iterator i_next; // [esp+Ch] [ebp-4h]

  phys_sys::fixup_wheel_constraints(rb);
  v1 = g_physics_system;
  v2 = g_physics_system->m_list_rbc_point.m_dummy_head.m_next_T_internal;
  v3 = &g_physics_system->m_list_rbc_point;
  if ( &g_physics_system->m_list_rbc_point != (phys_free_list<rigid_body_constraint_point> *)v2 )
  {
    do
    {
      v4 = v2[2].m_prev_T_internal;
      if ( v4
        && (v5 = v2[2].m_next_T_internal) != NULL
        && (v4 == (phys_free_list<rigid_body_constraint_point>::T_internal_base *)rb
         && (_DWORD)v5[31].m_next_T_internal & 0x20
         || v5 == (phys_free_list<rigid_body_constraint_point>::T_internal_base *)rb
         && (_DWORD)v4[31].m_next_T_internal & 0x20) )
      {
        i_next.m_ptr = v2->m_next_T_internal;
        if ( v2 != (phys_free_list<rigid_body_constraint_point>::T_internal_base *)-16 )
        {
          v6 = (phys_free_list<rigid_body_constraint_point>::T_internal *)v2;
          PMM_VALIDATE(v2, 0x70u, 0x10u);
          if ( !v6 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
            __debugbreak();
          --v3->m_list_count;
          phys_free_list<rigid_body_constraint_point>::debug_remove(v3, v6);
          v7 = v6->m_next_T_internal;
          v8 = v6->m_prev_T_internal;
          v8->m_next_T_internal = v7;
          v7->m_prev_T_internal = v8;
          PMM_FREE(v6, 0x70u, 0x10u);
          v1 = g_physics_system;
        }
        v2 = i_next.m_ptr;
      }
      else
      {
        v2 = v2->m_next_T_internal;
      }
      v3 = &v1->m_list_rbc_point;
    }
    while ( &v1->m_list_rbc_point != (phys_free_list<rigid_body_constraint_point> *)v2 );
  }
  v9 = (phys_free_list<rigid_body_constraint_wheel>::T_internal *)v1->m_list_rbc_hinge.m_dummy_head.m_next_T_internal;
  v10 = (phys_free_list<rigid_body_constraint_wheel> *)&v1->m_list_rbc_hinge;
  if ( &v1->m_list_rbc_hinge != (phys_free_list<rigid_body_constraint_hinge> *)v9 )
  {
    do
    {
      v11 = v9->m_data.b1;
      if ( v11
        && (v12 = v9->m_data.b2) != NULL
        && (v11 == rb && v12->m_flags & 0x20 || v12 == rb && v11->m_flags & 0x20) )
      {
        v13 = (phys_free_list<rigid_body_constraint_wheel>::T_internal *)v9->m_next_T_internal;
        if ( v9 != (phys_free_list<rigid_body_constraint_wheel>::T_internal *)-16 )
        {
          v14 = v9;
          PMM_VALIDATE(v9, 0xF0u, 0x10u);
          if ( !v14 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
            __debugbreak();
          --v10->m_list_count;
          phys_free_list<rigid_body_constraint_wheel>::debug_remove(v10, v14);
          v15 = v14->m_next_T_internal;
          v16 = v14->m_prev_T_internal;
          v16->m_next_T_internal = v15;
          v15->m_prev_T_internal = v16;
          PMM_FREE(v14, 0xF0u, 0x10u);
        }
        v9 = v13;
      }
      else
      {
        v9 = (phys_free_list<rigid_body_constraint_wheel>::T_internal *)v9->m_next_T_internal;
      }
      v10 = (phys_free_list<rigid_body_constraint_wheel> *)&g_physics_system->m_list_rbc_hinge;
    }
    while ( &g_physics_system->m_list_rbc_hinge != (phys_free_list<rigid_body_constraint_hinge> *)v9 );
  }
  v17 = g_physics_system->m_list_rbc_dist.m_dummy_head.m_next_T_internal;
  for ( i = (phys_free_list<broad_phase_group> *)&g_physics_system->m_list_rbc_dist;
        &g_physics_system->m_list_rbc_dist != (phys_free_list<rigid_body_constraint_distance> *)v17;
        i = (phys_free_list<broad_phase_group> *)&g_physics_system->m_list_rbc_dist )
  {
    v19 = v17[2].m_prev_T_internal;
    if ( v19
      && (v20 = v17[2].m_next_T_internal) != NULL
      && (v19 == (phys_free_list<rigid_body_constraint_distance>::T_internal_base *)rb
       && (_DWORD)v20[31].m_next_T_internal & 0x20
       || v20 == (phys_free_list<rigid_body_constraint_distance>::T_internal_base *)rb
       && (_DWORD)v19[31].m_next_T_internal & 0x20) )
    {
      v21 = v17->m_next_T_internal;
      if ( v17 != (phys_free_list<rigid_body_constraint_distance>::T_internal_base *)-16 )
      {
        v22 = (phys_free_list<broad_phase_group>::T_internal *)v17;
        PMM_VALIDATE(v17, 0x80u, 0x10u);
        if ( !v22 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --i->m_list_count;
        phys_free_list<broad_phase_group>::debug_remove(i, v22);
        v23 = v22->m_next_T_internal;
        v24 = v22->m_prev_T_internal;
        v24->m_next_T_internal = v23;
        v23->m_prev_T_internal = v24;
        PMM_FREE(v22, 0x80u, 0x10u);
      }
      v17 = v21;
    }
    else
    {
      v17 = v17->m_next_T_internal;
    }
  }
  v25 = g_physics_system->m_list_rbc_ragdoll.m_dummy_head.m_next_T_internal;
  for ( j = &g_physics_system->m_list_rbc_ragdoll;
        &g_physics_system->m_list_rbc_ragdoll != (phys_free_list<rigid_body_constraint_ragdoll> *)v25;
        j = &g_physics_system->m_list_rbc_ragdoll )
  {
    v27 = v25[2].m_prev_T_internal;
    if ( v27
      && (v28 = v25[2].m_next_T_internal) != NULL
      && (v27 == (phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *)rb
       && (_DWORD)v28[31].m_next_T_internal & 0x20
       || v28 == (phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *)rb
       && (_DWORD)v27[31].m_next_T_internal & 0x20) )
    {
      v29 = v25->m_next_T_internal;
      if ( v25 != (phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *)-16 )
      {
        v30 = (phys_free_list<rigid_body_constraint_ragdoll>::T_internal *)v25;
        PMM_VALIDATE(v25, 0x140u, 0x10u);
        if ( !v30 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --j->m_list_count;
        phys_free_list<rigid_body_constraint_ragdoll>::debug_remove(j, v30);
        v31 = v30->m_next_T_internal;
        v32 = v30->m_prev_T_internal;
        v32->m_next_T_internal = v31;
        v31->m_prev_T_internal = v32;
        PMM_FREE(v30, 0x140u, 0x10u);
      }
      v25 = v29;
    }
    else
    {
      v25 = v25->m_next_T_internal;
    }
  }
  v33 = g_physics_system->m_list_rbc_wheel.m_dummy_head.m_next_T_internal;
  for ( k = &g_physics_system->m_list_rbc_wheel;
        &g_physics_system->m_list_rbc_wheel != (phys_free_list<rigid_body_constraint_wheel> *)v33;
        k = &g_physics_system->m_list_rbc_wheel )
  {
    v35 = v33[2].m_prev_T_internal;
    if ( v35
      && (v36 = v33[2].m_next_T_internal) != NULL
      && (v35 == (phys_free_list<rigid_body_constraint_wheel>::T_internal_base *)rb
       && (_DWORD)v36[31].m_next_T_internal & 0x20
       || v36 == (phys_free_list<rigid_body_constraint_wheel>::T_internal_base *)rb
       && (_DWORD)v35[31].m_next_T_internal & 0x20) )
    {
      v37 = v33->m_next_T_internal;
      if ( v33 != (phys_free_list<rigid_body_constraint_wheel>::T_internal_base *)-16 )
      {
        v38 = (phys_free_list<rigid_body_constraint_wheel>::T_internal *)v33;
        PMM_VALIDATE(v33, 0xF0u, 0x10u);
        if ( !v38 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --k->m_list_count;
        phys_free_list<rigid_body_constraint_wheel>::debug_remove(k, v38);
        v39 = v38->m_next_T_internal;
        v40 = v38->m_prev_T_internal;
        v40->m_next_T_internal = v39;
        v39->m_prev_T_internal = v40;
        PMM_FREE(v38, 0xF0u, 0x10u);
      }
      v33 = v37;
    }
    else
    {
      v33 = v33->m_next_T_internal;
    }
  }
  v41 = g_physics_system->m_list_rbc_angular_actuator.m_dummy_head.m_next_T_internal;
  for ( l = &g_physics_system->m_list_rbc_angular_actuator;
        &g_physics_system->m_list_rbc_angular_actuator != (phys_free_list<rigid_body_constraint_angular_actuator> *)v41;
        l = &g_physics_system->m_list_rbc_angular_actuator )
  {
    v43 = v41[2].m_prev_T_internal;
    if ( v43
      && (v44 = v41[2].m_next_T_internal) != NULL
      && (v43 == (phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *)rb
       && (_DWORD)v44[31].m_next_T_internal & 0x20
       || v44 == (phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *)rb
       && (_DWORD)v43[31].m_next_T_internal & 0x20) )
    {
      v45 = v41->m_next_T_internal;
      if ( v41 != (phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *)-16 )
      {
        v46 = (phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *)v41;
        PMM_VALIDATE(v41, 0xE0u, 0x10u);
        if ( !v46 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --l->m_list_count;
        phys_free_list<rigid_body_constraint_angular_actuator>::debug_remove(l, v46);
        v47 = v46->m_next_T_internal;
        v48 = v46->m_prev_T_internal;
        v48->m_next_T_internal = v47;
        v47->m_prev_T_internal = v48;
        PMM_FREE(v46, 0xE0u, 0x10u);
      }
      v41 = v45;
    }
    else
    {
      v41 = v41->m_next_T_internal;
    }
  }
  v49 = g_physics_system->m_list_rbc_upright.m_dummy_head.m_next_T_internal;
  for ( m = &g_physics_system->m_list_rbc_upright;
        &g_physics_system->m_list_rbc_upright != (phys_free_list<rigid_body_constraint_upright> *)v49;
        m = &g_physics_system->m_list_rbc_upright )
  {
    v51 = v49[2].m_prev_T_internal;
    if ( v51
      && (v52 = v49[2].m_next_T_internal) != NULL
      && (v51 == (phys_free_list<rigid_body_constraint_upright>::T_internal_base *)rb
       && (_DWORD)v52[31].m_next_T_internal & 0x20
       || v52 == (phys_free_list<rigid_body_constraint_upright>::T_internal_base *)rb
       && (_DWORD)v51[31].m_next_T_internal & 0x20) )
    {
      v53 = v49->m_next_T_internal;
      if ( v49 != (phys_free_list<rigid_body_constraint_upright>::T_internal_base *)-16 )
      {
        v54 = (phys_free_list<rigid_body_constraint_upright>::T_internal *)v49;
        PMM_VALIDATE(v49, 0xD0u, 0x10u);
        if ( !v54 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --m->m_list_count;
        phys_free_list<rigid_body_constraint_upright>::debug_remove(m, v54);
        v55 = v54->m_next_T_internal;
        v56 = v54->m_prev_T_internal;
        v56->m_next_T_internal = v55;
        v55->m_prev_T_internal = v56;
        PMM_FREE(v54, 0xD0u, 0x10u);
      }
      v49 = v53;
    }
    else
    {
      v49 = v49->m_next_T_internal;
    }
  }
  v57 = g_physics_system->m_list_rbc_custom_orientation.m_dummy_head.m_next_T_internal;
  for ( n = &g_physics_system->m_list_rbc_custom_orientation;
        &g_physics_system->m_list_rbc_custom_orientation != (phys_free_list<rigid_body_constraint_custom_orientation> *)v57;
        n = &g_physics_system->m_list_rbc_custom_orientation )
  {
    v59 = v57[1].m_prev_T_internal;
    if ( v59
      && (v60 = v57[1].m_next_T_internal) != NULL
      && (v59 == (phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *)rb
       && (_DWORD)v60[31].m_next_T_internal & 0x20
       || v60 == (phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *)rb
       && (_DWORD)v59[31].m_next_T_internal & 0x20) )
    {
      v61 = v57->m_next_T_internal;
      if ( v57 != (phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *)-8 )
      {
        v62 = (phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *)v57;
        PMM_VALIDATE(v57, 0x40u, 4u);
        if ( !v62 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --n->m_list_count;
        phys_free_list<rigid_body_constraint_custom_orientation>::debug_remove(n, v62);
        v63 = v62->m_next_T_internal;
        v64 = v62->m_prev_T_internal;
        v64->m_next_T_internal = v63;
        v63->m_prev_T_internal = v64;
        PMM_FREE(v62, 0x40u, 4u);
      }
      v57 = v61;
    }
    else
    {
      v57 = v57->m_next_T_internal;
    }
  }
  v65 = g_physics_system->m_list_rbc_custom_path.m_dummy_head.m_next_T_internal;
  for ( ii = &g_physics_system->m_list_rbc_custom_path;
        &g_physics_system->m_list_rbc_custom_path != (phys_free_list<rigid_body_constraint_custom_path> *)v65;
        ii = &g_physics_system->m_list_rbc_custom_path )
  {
    v67 = v65[2].m_prev_T_internal;
    if ( v67
      && (v68 = v65[2].m_next_T_internal) != NULL
      && (v67 == (phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *)rb
       && (_DWORD)v68[31].m_next_T_internal & 0x20
       || v68 == (phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *)rb
       && (_DWORD)v67[31].m_next_T_internal & 0x20) )
    {
      v69 = v65->m_next_T_internal;
      if ( v65 != (phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *)-16 )
      {
        v70 = (phys_free_list<rigid_body_constraint_custom_path>::T_internal *)v65;
        PMM_VALIDATE(v65, 0xA0u, 0x10u);
        if ( !v70 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
          __debugbreak();
        --ii->m_list_count;
        phys_free_list<rigid_body_constraint_custom_path>::debug_remove(ii, v70);
        v71 = v70->m_next_T_internal;
        v72 = v70->m_prev_T_internal;
        v72->m_next_T_internal = v71;
        v71->m_prev_T_internal = v72;
        PMM_FREE(v70, 0xA0u, 0x10u);
      }
      v65 = v69;
    }
    else
    {
      v65 = v65->m_next_T_internal;
    }
  }
  v73 = g_physics_system->m_list_rbc_contact.m_dummy_head.m_next_T_internal;
  for ( jj = &g_physics_system->m_list_rbc_contact;
        &g_physics_system->m_list_rbc_contact != (phys_free_list<rigid_body_constraint_contact> *)v73;
        jj = &g_physics_system->m_list_rbc_contact )
  {
    v75 = v73[1].m_prev_T_internal;
    if ( v75
      && (v76 = v73[1].m_next_T_internal) != NULL
      && (v75 == (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)rb
       && (_DWORD)v76[31].m_next_T_internal & 0x20
       || v76 == (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)rb
       && (_DWORD)v75[31].m_next_T_internal & 0x20) )
    {
      v77 = v73->m_next_T_internal;
      if ( v73 != (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)-8 )
      {
        v78 = (phys_free_list<rigid_body_constraint_contact>::T_internal *)v73;
        PMM_VALIDATE(v73, 0x38u, 4u);
        if ( !v78 )
        {
          if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
            __debugbreak();
        }
        --jj->m_list_count;
        phys_free_list<rigid_body_constraint_contact>::debug_remove(jj, v78);
        v79 = v78->m_prev_T_internal;
        v80 = v78->m_next_T_internal;
        v79->m_next_T_internal = v80;
        v80->m_prev_T_internal = v79;
        rigid_body_constraint_contact::~rigid_body_constraint_contact(&v78->m_data);
        PMM_FREE(v78, 0x38u, 4u);
      }
      v73 = v77;
    }
    else
    {
      v73 = v73->m_next_T_internal;
    }
  }
}

/*
==============
phys_sys::destroy
==============
*/
void phys_sys::destroy(rigid_body *const rb)
{
  physics_system *v1; // edi

  phys_sys::destroy_all_constraint(rb);
  v1 = g_physics_system;
  if ( rb )
  {
    PMM_VALIDATE(&rb[-1].m_partition_node.m_partition_head, 0x180u, 0x10u);
    phys_free_list<rigid_body>::remove(
      &v1->m_list_rigid_body,
      (phys_free_list<rigid_body>::T_internal *)&rb[-1].m_partition_node.m_partition_head);
  }
}

/*
==============
phys_sys::destroy
==============
*/
void phys_sys::destroy(user_rigid_body *const rb)
{
  physics_system *v1; // edi

  phys_sys::destroy_all_constraint((rigid_body *const )&rb->m_last_position);
  v1 = g_physics_system;
  if ( rb )
  {
    PMM_VALIDATE(&rb[-1].m_dictator_mat.w, 0x1D0u, 0x10u);
    phys_free_list<user_rigid_body>::remove(
      &v1->m_list_user_rigid_body,
      (phys_free_list<user_rigid_body>::T_internal *)&rb[-1].m_dictator_mat.w);
  }
}

