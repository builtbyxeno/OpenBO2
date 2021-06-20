/*
==============
rigid_body_constraint_custom_orientation::setup_constraint
==============
*/
void __userpurge rigid_body_constraint_custom_orientation::setup_constraint(rigid_body_constraint_custom_orientation *this@<ecx>, float a2@<ebp>, pulse_sum_constraint_solver *psys, const float delta_t)
{
  double v4; // st7
  rigid_body_constraint_custom_orientation *v5; // esi
  bool v6; // c0
  phys_vec3 *v7; // ecx
  phys_vec3 *v8; // edi
  pulse_sum_angular *v9; // eax
  double v10; // st7
  pulse_sum_angular *v11; // eax
  double v12; // st6
  double v13; // st6
  double v14; // st6
  double v15; // st7
  rigid_body *v16; // edx
  float v17; // eax
  rigid_body **v18; // ecx
  rigid_body *v19; // eax
  rigid_body *v20; // ecx
  float v21; // edx
  float *v22; // eax
  float v23; // edx
  float v24; // eax
  rigid_body *v25; // eax
  pulse_sum_angular *v26; // eax
  double v27; // st6
  double v28; // rt1
  rigid_body *v29; // ecx
  double v30; // rt2
  double v31; // st7
  float v32; // eax
  float v33; // edx
  float v34; // eax
  phys_vec3 *v35; // eax
  rigid_body *v36; // edx
  rigid_body *v37; // eax
  pulse_sum_angular *v38; // eax
  bool v39; // zf
  double v40; // st7
  double v41; // st7
  double v42; // st6
  double v43; // st5
  double v44; // st7
  float *v45; // eax
  rigid_body *v46; // ST08_4
  rigid_body *v47; // ST00_4
  pulse_sum_angular *v48; // eax
  double v49; // st7
  double v50; // st7
  double v51; // st6
  float *v52; // eax
  double v53; // st7
  float v54; // [esp-Ch] [ebp-5Ch]
  float v55; // [esp-8h] [ebp-58h]
  float v56; // [esp-4h] [ebp-54h]
  phys_vec3 rel_vel; // [esp+0h] [ebp-50h]
  phys_vec3 gravity_dir; // [esp+10h] [ebp-40h]
  phys_vec3 rb1_point_velocity; // [esp+20h] [ebp-30h]
  float v60; // [esp+30h] [ebp-20h]
  float v61; // [esp+34h] [ebp-1Ch]
  phys_free_list<rigid_body_constraint_contact>::iterator rbc_i_end; // [esp+38h] [ebp-18h]
  float v63; // [esp+3Ch] [ebp-14h]
  float roll; // [esp+40h] [ebp-10h]
  float pitch; // [esp+44h] [ebp-Ch]
  float collision_scale; // [esp+48h] [ebp-8h]
  float retaddr; // [esp+50h] [ebp+0h]

  pitch = a2;
  collision_scale = retaddr;
  v4 = 0.0;
  v5 = this;
  v6 = 0.0 < this->m_torque_resistance_pitch_roll;
  v7 = &this->b2->m_mat.x;
  v8 = &v5->b1->m_mat.x;
  rbc_i_end.m_ptr = (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)v7;
  if ( v6 )
  {
    roll = v5->m_torque_resistance_pitch_roll * 10.0;
    v9 = pulse_sum_constraint_solver::create_pulse_sum_angular(
           psys,
           v5->b1,
           v8 + 2,
           v5->b2,
           v7 + 2,
           v8 + 1,
           v5->m_ps_cache_list);
    v9->m_pulse_sum_min = -10000000.0;
    v9->m_pulse_sum_max = 10000000.0;
    v63 = 1.0 / (roll * delta_t);
    v9->m_right_side = 0.0;
    v9->m_big_dirt = 0.0;
    v10 = v63;
    v9->m_cfm = v63;
    v9->m_denom = v10 + v9->m_denom;
    v11 = pulse_sum_constraint_solver::create_pulse_sum_angular(
            psys,
            v5->b1,
            v8 + 2,
            v5->b2,
            (phys_vec3 *)&rbc_i_end.m_ptr[4],
            v8,
            &v5->m_ps_cache_list[1]);
    v11->m_pulse_sum_min = -10000000.0;
    v11->m_pulse_sum_max = 10000000.0;
    v4 = 0.0;
    v11->m_right_side = 0.0;
    v11->m_big_dirt = 0.0;
    v12 = v63;
    v11->m_cfm = v63;
    v11->m_denom = v12 + v11->m_denom;
  }
  v13 = 1.0;
  if ( v4 >= v5->m_torque_resistance_yaw )
    goto LABEL_21;
  v14 = v4;
  v15 = 1.0;
  if ( v14 >= v5->m_torque_resistance_yaw_max_collision_speed || (v16 = v5->b1, !(v5->b1->m_flags & 0x100)) )
  {
    v30 = v14;
    v13 = 1.0;
    v4 = v30;
LABEL_21:
    v28 = v13;
    v14 = v4;
    v15 = v28;
    goto LABEL_22;
  }
  v63 = v14;
  v17 = *(float *)&g_physics_system->m_list_rbc_contact.m_dummy_head.m_next_T_internal;
  roll = v17;
  for ( LODWORD(rb1_point_velocity.w) = (char *)g_physics_system + 2476;
        LODWORD(rb1_point_velocity.w) != LODWORD(v17);
        roll = v17 )
  {
    v18 = (rigid_body **)(LODWORD(v17) + 8);
    if ( v17 != -6.8056441e38/*NaN*/ )
    {
      v19 = *v18;
      if ( *v18 == v16 )
      {
        v20 = v18[3];
        if ( v20 )
        {
          gravity_dir.y = v19->m_t_vel.x;
          gravity_dir.z = v19->m_t_vel.y;
          v21 = v19->m_t_vel.z;
          rb1_point_velocity.x = v19->m_t_vel.w;
          v22 = *(float **)(LODWORD(roll) + 12);
          gravity_dir.w = v21;
          rel_vel.y = v22[36];
          rel_vel.z = v22[37];
          v23 = v22[38];
          v54 = gravity_dir.y - rel_vel.y;
          v24 = v22[39];
          rel_vel.w = v23;
          gravity_dir.x = v24;
          v55 = gravity_dir.z - rel_vel.z;
          v56 = gravity_dir.w - v23;
          do
          {
            v61 = v20->m_last_position.y * v55 + v20->m_last_position.x * v54 + v20->m_last_position.z * v56;
            v61 = fabs(v61);
            if ( v63 < (double)v61 )
              v63 = v61;
            v20 = (rigid_body *)LODWORD(v20->m_mat.x.x);
          }
          while ( v20 );
          v16 = v5->b1;
        }
      }
      v17 = roll;
    }
    v17 = *(float *)(LODWORD(v17) + 4);
  }
  if ( impact_intensity_limit < (double)v63 )
  {
    v63 = v63 / v5->m_torque_resistance_yaw_max_collision_speed;
    if ( v63 > 1.0 )
      v63 = 1.0;
    v25 = v5->b2;
    roll = v5->m_torque_resistance_yaw * v63 * 1000.0;
    v26 = pulse_sum_constraint_solver::create_pulse_sum_angular(
            psys,
            v16,
            v8,
            v25,
            (phys_vec3 *)rbc_i_end.m_ptr,
            v8 + 2,
            &v5->m_ps_cache_list[2]);
    v26->m_pulse_sum_min = -10000000.0;
    v26->m_pulse_sum_max = 10000000.0;
    v63 = 1.0 / (roll * delta_t);
    v4 = 0.0;
    v26->m_right_side = 0.0;
    v26->m_big_dirt = 0.0;
    v27 = v63;
    v26->m_cfm = v63;
    v26->m_denom = v27 + v26->m_denom;
    v13 = 1.0;
    goto LABEL_21;
  }
LABEL_22:
  if ( v5->m_active && v14 < v5->m_upright_strength )
  {
    v29 = v5->b1;
    rb1_point_velocity.w = fabs(v5->b1->m_mat.y.z);
    v61 = rb1_point_velocity.w;
    rb1_point_velocity.w = fabs(v29->m_mat.x.z);
    rbc_i_end.m_ptr = (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)LODWORD(rb1_point_velocity.w);
    if ( v14 > v29->m_mat.z.z )
    {
      *(float *)&rbc_i_end.m_ptr = v15;
      v61 = v15;
    }
    v31 = v5->m_upright_strength * 30.0;
    v32 = v29->m_gravity_acc_vec.y;
    v54 = v29->m_gravity_acc_vec.x;
    v33 = v29->m_gravity_acc_vec.z;
    v55 = v32;
    v34 = v29->m_gravity_acc_vec.w;
    rb1_point_velocity.w = v31 * delta_t;
    v56 = v33;
    rel_vel.x = v34;
    roll = rb1_point_velocity.w * *(float *)&rbc_i_end.m_ptr;
    v35 = phys_Unitize((phys_vec3 *)((char *)&gravity_dir + 4), (phys_vec3 *)&v54);
    rb1_point_velocity.w = -v35->y;
    v36 = v5->b2;
    v60 = -v35->z;
    rel_vel.y = -v35->x;
    rel_vel.z = rb1_point_velocity.w;
    v37 = v5->b1;
    rel_vel.w = v60;
    *(float *)&v38 = COERCE_FLOAT(
                       pulse_sum_constraint_solver::create_pulse_sum_angular(
                         psys,
                         v37,
                         v8 + 2,
                         v36,
                         (phys_vec3 *)((char *)&rel_vel + 4),
                         v8 + 1,
                         &v5->m_ps_cache_list[3]));
    v39 = v5->m_no_orientation_correction == 0;
    v63 = *(float *)&v38;
    if ( v39 )
    {
      v44 = roll;
      v38->m_pulse_sum_min = -roll;
      v38->m_pulse_sum_max = v44;
      v41 = pulse_sum_angular::get_pos(v38);
      v42 = delta_t;
      v43 = -1.0 / delta_t;
    }
    else
    {
      v40 = 0.0;
      if ( v8->z >= 0.0 )
      {
        v38->m_pulse_sum_min = 0.0;
        v40 = roll;
      }
      else
      {
        v38->m_pulse_sum_min = -roll;
      }
      v38->m_pulse_sum_max = v40;
      v41 = pulse_sum_angular::get_pos(v38);
      v42 = delta_t;
      v43 = -0.0 / delta_t;
    }
    v45 = (float *)LODWORD(v63);
    *(float *)(LODWORD(v63) + 108) = v41 * v43;
    v45[28] = 0.0;
    v45[29] = 0.0;
    v45[30] = v45[30] + 0.0;
    v46 = v5->b2;
    v47 = v5->b1;
    rb1_point_velocity.w = v42 * (v5->m_upright_strength * 100.0);
    roll = rb1_point_velocity.w * v61;
    *(float *)&v48 = COERCE_FLOAT(
                       pulse_sum_constraint_solver::create_pulse_sum_angular(
                         psys,
                         v47,
                         v8 + 2,
                         v46,
                         (phys_vec3 *)((char *)&rel_vel + 4),
                         v8,
                         &v5->m_ps_cache_list[4]));
    v39 = v5->m_no_orientation_correction == 0;
    v63 = *(float *)&v48;
    if ( v39 )
    {
      v53 = roll;
      v48->m_pulse_sum_min = -roll;
      v48->m_pulse_sum_max = v53;
      v50 = pulse_sum_angular::get_pos(v48);
      v51 = -1.0 / delta_t;
    }
    else
    {
      roll = roll * 0.5;
      v49 = 0.0;
      if ( v8[1].z <= 0.0 )
      {
        v48->m_pulse_sum_min = 0.0;
        v49 = roll;
      }
      else
      {
        v48->m_pulse_sum_min = -roll;
      }
      v48->m_pulse_sum_max = v49;
      v50 = pulse_sum_angular::get_pos(v48);
      v51 = -0.0 / delta_t;
    }
    v52 = (float *)LODWORD(v63);
    *(float *)(LODWORD(v63) + 108) = v50 * v51;
    v52[28] = 0.0;
    v52[29] = 0.0;
    v52[30] = v52[30] + 0.0;
  }
}

/*
==============
rigid_body_constraint_custom_path::setup_constraint
==============
*/
void __userpurge rigid_body_constraint_custom_path::setup_constraint(rigid_body_constraint_custom_path *this@<ecx>, float a2@<ebp>, pulse_sum_constraint_solver *psys, const float delta_t)
{
  rigid_body_constraint_custom_path *v4; // esi
  rigid_body *v5; // ecx
  double v6; // st6
  double v7; // st4
  double v8; // st6
  pulse_sum_normal *v9; // edi
  pulse_sum_constraint_solver *v10; // eax
  pulse_sum_normal **v11; // ecx
  double v12; // st7
  double v13; // st7
  pulse_sum_normal *v14; // edi
  pulse_sum_constraint_solver *v15; // eax
  pulse_sum_normal **v16; // edx
  double v17; // st7
  double v18; // st7
  rigid_body *v19; // edi
  float *v20; // eax
  float v21; // edx
  float v22; // ecx
  float *v23; // eax
  double v24; // st7
  phys_vec3 *v25; // eax
  double v26; // st7
  pulse_sum_angular *v27; // edi
  double v28; // st7
  double v29; // st6
  rigid_body *v30; // eax
  float v31; // ecx
  float v32; // edx
  float v33; // eax
  double v34; // st6
  double v35; // st5
  double v36; // rt0
  phys_vec3 *v37; // eax
  rigid_body *v38; // ecx
  rigid_body *v39; // ST0C_4
  double v40; // st7
  pulse_sum_angular *v41; // esi
  double v42; // st7
  double v43; // st6
  int v44; // [esp-Ch] [ebp-8Ch]
  phys_vec3 b1_r; // [esp+0h] [ebp-80h]
  phys_vec3 b2_r; // [esp+10h] [ebp-70h]
  phys_vec3 b2_pt; // [esp+20h] [ebp-60h]
  phys_vec3 b1_r_; // [esp+30h] [ebp-50h]
  phys_vec3 axis; // [esp+40h] [ebp-40h]
  phys_vec3 b1_ud; // [esp+50h] [ebp-30h]
  phys_vec3 b2_r2; // [esp+60h] [ebp-20h]
  float v52; // [esp+70h] [ebp-10h]
  float psa_cfm; // [esp+74h] [ebp-Ch]
  int v54; // [esp+78h] [ebp-8h]
  int retaddr; // [esp+80h] [ebp+0h]

  psa_cfm = a2;
  v54 = retaddr;
  v4 = this;
  b2_pt.y = 0.0;
  v5 = this->b1;
  b2_pt.z = 0.0;
  b2_pt.w = 0.0;
  phys_multiply((phys_vec3 *)&v44, &v5->m_mat, &v4->b1_r_loc);
  phys_multiply((phys_vec3 *)((char *)&b1_r + 4), &v4->b2->m_mat, (phys_vec3 *)((char *)&b2_pt + 4));
  if ( !v4->m_urb && _tlAssert("source/rbc_def_custom.cpp", 192, "m_urb", (const char *)&pBlock) )
    __debugbreak();
  b2_r2.z = 1.0 / v4->b1->m_inv_mass;
  v52 = v4->m_spring_scale * 50.0;
  v6 = b2_r2.z;
  b2_r2.z = v52 * b2_r2.z;
  b2_r2.z = b2_r2.z * delta_t;
  v7 = v6;
  v8 = b2_r2.z * delta_t;
  b2_r2.z = v7 * 12.0;
  b2_r2.z = delta_t * b2_r2.z;
  v52 = 1.0 / (b2_r2.z + v8);
  b2_r2.z = v8 * v52;
  v9 = (pulse_sum_normal *)phys_transient_allocator::allocate(
                             &psys->m_solver_memory_allocator,
                             160,
                             16,
                             0,
                             SOLVER_MEMORY_ALLOCATOR_ERROR_MSG);
  v10 = psys;
  if ( !psys->m_list_pulse_sum_normal.m_last_next_ptr )
  {
    if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 230, "m_last_next_ptr", (const char *)&pBlock) )
      __debugbreak();
    v10 = psys;
  }
  v9->m_next_link = NULL;
  v11 = v10->m_list_pulse_sum_normal.m_last_next_ptr;
  ++v10->m_list_pulse_sum_normal.m_alloc_count;
  *v11 = v9;
  v10->m_list_pulse_sum_normal.m_last_next_ptr = &v9->m_next_link;
  pulse_sum_normal::set(
    v9,
    (int)&psa_cfm,
    v4->b1,
    (phys_vec3 *)&v44,
    v4->b2,
    (phys_vec3 *)((char *)&b1_r + 4),
    &ud,
    v4->m_list_psc,
    &b1_r_displace);
  *(double *)&b2_r2.y = -b2_r2.z / delta_t;
  v12 = pulse_sum_normal::get_pos(v9, (int)&psa_cfm);
  v9->m_right_side = v12 * *(double *)&b2_r2.y;
  v9->m_big_dirt = 0.0;
  v13 = v52;
  v9->m_cfm = v52;
  v9->m_denom = v13 + v9->m_denom;
  v9->m_pulse_sum_min = -10000000.0;
  v9->m_pulse_sum_max = 10000000.0;
  v14 = (pulse_sum_normal *)phys_transient_allocator::allocate(
                              &psys->m_solver_memory_allocator,
                              160,
                              16,
                              0,
                              SOLVER_MEMORY_ALLOCATOR_ERROR_MSG);
  v15 = psys;
  if ( !psys->m_list_pulse_sum_normal.m_last_next_ptr )
  {
    if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 230, "m_last_next_ptr", (const char *)&pBlock) )
      __debugbreak();
    v15 = psys;
  }
  v14->m_next_link = NULL;
  v16 = v15->m_list_pulse_sum_normal.m_last_next_ptr;
  ++v15->m_list_pulse_sum_normal.m_alloc_count;
  *v16 = v14;
  v15->m_list_pulse_sum_normal.m_last_next_ptr = &v14->m_next_link;
  pulse_sum_normal::set(
    v14,
    (int)&psa_cfm,
    v4->b1,
    (phys_vec3 *)&v44,
    v4->b2,
    (phys_vec3 *)((char *)&b1_r + 4),
    &stru_10E5DF0,
    &v4->m_list_psc[1],
    &b1_r_displace);
  v17 = pulse_sum_normal::get_pos(v14, (int)&psa_cfm);
  v14->m_right_side = v17 * *(double *)&b2_r2.y;
  v14->m_big_dirt = 0.0;
  v18 = v52;
  v14->m_cfm = v52;
  v14->m_denom = v18 + v14->m_denom;
  v14->m_pulse_sum_min = -10000000.0;
  v14->m_pulse_sum_max = 10000000.0;
  v19 = v4->b1;
  b1_r_.y = v4->b1->m_mat.x.x;
  b1_r_.z = v19->m_mat.x.y;
  v20 = &v4->b2->m_last_position.x;
  b1_r_.w = v19->m_mat.x.z;
  axis.x = v19->m_mat.x.w;
  v21 = v20[17];
  axis.y = v20[16];
  v22 = v20[18];
  axis.z = v21;
  axis.w = v22;
  b1_ud.x = v20[19];
  b2_r2.z = v21 * b1_r_.z + axis.y * b1_r_.y + v22 * b1_r_.w;
  b2_pt.y = axis.y * b2_r2.z;
  b2_pt.z = v21 * b2_r2.z;
  b2_pt.w = b2_r2.z * v22;
  b1_ud.y = b1_r_.y - b2_pt.y;
  b1_ud.z = b1_r_.z - b2_pt.z;
  b1_ud.w = b1_r_.w - b2_pt.w;
  b2_r2.z = b1_ud.y * b1_ud.y + b1_ud.z * b1_ud.z + b1_ud.w * b1_ud.w;
  b2_r2.z = sqrt(b2_r2.z);
  v23 = &v4->b2->m_last_position.x;
  v52 = b2_r2.z;
  b2_r2.z = v19->m_mat.x.y * v23[13] + v23[12] * v19->m_mat.x.x + v19->m_mat.x.z * v23[14];
  v24 = 0.0;
  if ( v52 > 0.00009999999747378752 && b2_r2.z >= 0.0 )
  {
    b2_r2.z = 1.0 / v52;
    b1_ud.y = b2_r2.z * b1_ud.y;
    b1_ud.z = b1_ud.z * b2_r2.z;
    b1_ud.w = b2_r2.z * b1_ud.w;
    b2_pt.y = b1_ud.w * axis.z - b1_ud.z * axis.w;
    b2_pt.z = axis.w * b1_ud.y - b1_ud.w * axis.y;
    b2_pt.w = axis.y * b1_ud.z - b1_ud.y * axis.z;
    v25 = rbint::mul_L((int)&psa_cfm, (phys_vec3 *)((char *)&b2_r + 4), v19, (phys_vec3 *)((char *)&b2_pt + 4));
    b2_r2.z = v25->y * b2_pt.z + b2_pt.y * v25->x + v25->z * b2_pt.w;
    v26 = b2_r2.z;
    b2_r2.z = psa_spring_k_0 * b2_r2.z;
    b2_r2.z = b2_r2.z * delta_t;
    *(double *)&b2_r2.w = b2_r2.z * delta_t;
    b2_r2.z = v26 * psa_spring_d_0;
    b2_r2.z = delta_t * b2_r2.z;
    b2_r2.z = 1.0 / (*(double *)&b2_r2.w + b2_r2.z);
    v27 = pulse_sum_constraint_solver::create_pulse_sum_angular(
            psys,
            v4->b1,
            (phys_vec3 *)((char *)&b1_r_ + 4),
            v4->b2,
            (phys_vec3 *)((char *)&b1_ud + 4),
            (phys_vec3 *)((char *)&b2_pt + 4),
            &v4->m_list_psc[2]);
    v28 = pulse_sum_angular::get_pos(v27);
    v29 = b2_r2.z;
    b2_r2.z = *(double *)&b2_r2.w * b2_r2.z;
    v27->m_right_side = v28 * (-b2_r2.z / delta_t);
    v27->m_big_dirt = 0.0;
    v24 = 0.0;
    v27->m_cfm = v29;
    v27->m_denom = v29 + v27->m_denom;
    v27->m_pulse_sum_min = -10000000.0;
    v27->m_pulse_sum_max = 10000000.0;
  }
  v30 = v4->b1;
  v31 = v4->b1->m_mat.z.y;
  axis.y = v4->b1->m_mat.z.x;
  v32 = v30->m_mat.z.z;
  v33 = v30->m_mat.z.w;
  b2_r.y = v24;
  b2_r.z = v24;
  axis.z = v31;
  axis.w = v32;
  b2_r.w = 1.0;
  b1_ud.x = v33;
  b2_r2.z = v31 * 0.0 + axis.y * 0.0 + v32;
  b2_pt.y = axis.y * b2_r2.z;
  b2_pt.z = v31 * b2_r2.z;
  b2_pt.w = b2_r2.z * v32;
  b1_r_.y = 0.0 - b2_pt.y;
  b1_r_.z = 0.0 - b2_pt.z;
  b1_r_.w = 1.0 - b2_pt.w;
  b2_r2.z = b1_r_.z * b1_r_.z + b1_r_.y * b1_r_.y + b1_r_.w * b1_r_.w;
  b2_r2.z = sqrt(b2_r2.z);
  if ( b2_r2.z >= 0.00009999999747378752 )
  {
    v34 = axis.y;
    b1_ud.y = axis.y * 0.5;
    b1_ud.z = axis.z * 0.5;
    v35 = axis.w;
    b1_ud.w = 0.5 * axis.w;
    v36 = axis.z;
    b2_r2.z = 0.8660253882408142 / b2_r2.z;
    axis.y = b1_r_.y * b2_r2.z;
    axis.z = b1_r_.z * b2_r2.z;
    axis.w = b2_r2.z * b1_r_.w;
    b2_pt.y = axis.y + b1_ud.y;
    b2_pt.z = axis.z + b1_ud.z;
    b2_pt.w = axis.w + b1_ud.w;
    axis.y = b2_pt.z * v35 - b2_pt.w * v36;
    axis.z = b2_pt.w * v34 - v35 * b2_pt.y;
    axis.w = b2_pt.y * v36 - v34 * b2_pt.z;
    b1_r_.y = axis.y * 1.154700517654419;
    b1_r_.z = axis.z * 1.154700517654419;
    b1_r_.w = 1.154700517654419 * axis.w;
    PHYS_ASSERT_UNIT((phys_vec3 *)((char *)&b1_r_ + 4));
    v37 = rbint::mul_L((int)&psa_cfm, (phys_vec3 *)((char *)&axis + 4), v4->b1, (phys_vec3 *)((char *)&b1_r_ + 4));
    v38 = v4->b1;
    v39 = v4->b2;
    b2_r2.z = v37->y * b1_r_.z + b1_r_.y * v37->x + v37->z * b1_r_.w;
    v40 = b2_r2.z;
    b2_r2.z = b2_r2.z * psa_spring_k;
    b2_r2.z = b2_r2.z * delta_t;
    *(double *)&b2_r2.w = b2_r2.z * delta_t;
    b2_r2.z = v40 * psa_spring_d;
    b2_r2.z = delta_t * b2_r2.z;
    b2_r2.z = 1.0 / (*(double *)&b2_r2.w + b2_r2.z);
    v41 = pulse_sum_constraint_solver::create_pulse_sum_angular(
            psys,
            v38,
            (phys_vec3 *)((char *)&b2_pt + 4),
            v39,
            (phys_vec3 *)((char *)&b2_r + 4),
            (phys_vec3 *)((char *)&b1_r_ + 4),
            &v4->m_list_psc[3]);
    v41->m_pulse_sum_min = -10000000.0;
    v41->m_pulse_sum_max = 0.0;
    v42 = pulse_sum_angular::get_pos(v41);
    v43 = b2_r2.z;
    b2_r2.z = *(double *)&b2_r2.w * b2_r2.z;
    v41->m_right_side = v42 * (-b2_r2.z / delta_t);
    v41->m_big_dirt = 0.0;
    v41->m_cfm = v43;
    v41->m_denom = v43 + v41->m_denom;
  }
}

