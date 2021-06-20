/*
==============
rigid_body_constraint_point::set
==============
*/
void __thiscall rigid_body_constraint_point::set(rigid_body_constraint_point *this, phys_vec3 *b1_r_loc, phys_vec3 *b2_r_loc)
{
  this->m_b1_r_loc.x = b1_r_loc->x;
  this->m_b1_r_loc.y = b1_r_loc->y;
  this->m_b1_r_loc.z = b1_r_loc->z;
  this->m_b2_r_loc.x = b2_r_loc->x;
  this->m_b2_r_loc.y = b2_r_loc->y;
  this->m_b2_r_loc.z = b2_r_loc->z;
}

/*
==============
rigid_body_constraint_point::epilog_vel_constraint
==============
*/
void __thiscall rigid_body_constraint_point::epilog_vel_constraint(rigid_body_constraint_point *this, const float __formal)
{
  this->m_stress = this->m_ps_cache_list[1].m_pulse_sum * this->m_ps_cache_list[1].m_pulse_sum
                 + this->m_ps_cache_list[0].m_pulse_sum * this->m_ps_cache_list[0].m_pulse_sum
                 + this->m_ps_cache_list[2].m_pulse_sum * this->m_ps_cache_list[2].m_pulse_sum;
}

/*
==============
rigid_body_constraint_distance::set
==============
*/
void __thiscall rigid_body_constraint_distance::set(rigid_body_constraint_distance *this, phys_vec3 *b1_r_loc, phys_vec3 *b2_r_loc, const float min_distance, const float max_distance)
{
  this->m_b1_r_loc.x = b1_r_loc->x;
  this->m_b1_r_loc.y = b1_r_loc->y;
  this->m_b1_r_loc.z = b1_r_loc->z;
  this->m_b2_r_loc.x = b2_r_loc->x;
  this->m_b2_r_loc.y = b2_r_loc->y;
  this->m_b2_r_loc.z = b2_r_loc->z;
  this->m_flags = 1;
  this->m_min_distance = min_distance;
  this->m_max_distance = max_distance;
  this->m_next_max_distance = max_distance;
  this->m_max_distance_vel = 0.0;
  this->m_damp_coef = 0.0;
}

/*
==============
rigid_body_constraint_distance::outer_prolog_update
==============
*/
void __thiscall rigid_body_constraint_distance::outer_prolog_update(rigid_body_constraint_distance *this, const float delta_t)
{
  this->m_max_distance_vel = (this->m_next_max_distance - this->m_max_distance) / delta_t;
}

/*
==============
rigid_body_constraint_distance::inner_update
==============
*/
void __thiscall rigid_body_constraint_distance::inner_update(rigid_body_constraint_distance *this, const float delta_t)
{
  this->m_max_distance = this->m_max_distance_vel * delta_t + this->m_max_distance;
}

/*
==============
rigid_body_constraint_distance::outer_epilog_update
==============
*/
void __thiscall rigid_body_constraint_distance::outer_epilog_update(rigid_body_constraint_distance *this, const float __formal)
{
  this->m_max_distance = this->m_next_max_distance;
}

/*
==============
rigid_body_constraint_angular_actuator::set
==============
*/
void __thiscall rigid_body_constraint_angular_actuator::set(rigid_body_constraint_angular_actuator *this, float power, phys_mat44 *target_mat)
{
  float *v3; // edx

  this->m_power = power;
  v3 = &this->m_target_mat.x.x;
  this->m_power_scale = 1.0;
  *v3 = target_mat->x.x;
  v3[1] = target_mat->x.y;
  v3[2] = target_mat->x.z;
  v3[4] = target_mat->y.x;
  v3[5] = target_mat->y.y;
  v3[6] = target_mat->y.z;
  v3[8] = target_mat->z.x;
  v3[9] = target_mat->z.y;
  v3[10] = target_mat->z.z;
  v3[12] = target_mat->w.x;
  v3[13] = target_mat->w.y;
  v3[14] = target_mat->w.z;
  this->m_next_target_mat.x.x = target_mat->x.x;
  this->m_next_target_mat.x.y = target_mat->x.y;
  this->m_next_target_mat.x.z = target_mat->x.z;
  this->m_next_target_mat.y.x = target_mat->y.x;
  this->m_next_target_mat.y.y = target_mat->y.y;
  this->m_next_target_mat.y.z = target_mat->y.z;
  this->m_next_target_mat.z.x = target_mat->z.x;
  this->m_next_target_mat.z.y = target_mat->z.y;
  this->m_next_target_mat.z.z = target_mat->z.z;
  this->m_next_target_mat.w.x = target_mat->w.x;
  this->m_next_target_mat.w.y = target_mat->w.y;
  this->m_next_target_mat.w.z = target_mat->w.z;
  this->m_a_vel.x = 0.0;
  this->m_a_vel.y = 0.0;
  this->m_a_vel.z = 0.0;
  this->m_enabled = 1;
  PHYS_ASSERT_ORTHONORMAL(&this->m_target_mat);
}

/*
==============
rigid_body_constraint_angular_actuator::outer_prolog_update
==============
*/
void __userpurge rigid_body_constraint_angular_actuator::outer_prolog_update(rigid_body_constraint_angular_actuator *this@<ecx>, float a2@<ebp>, const float delta_t)
{
  int v3; // [esp+Ch] [ebp-1Ch]
  phys_vec3 t_vel; // [esp+18h] [ebp-10h]
  float retaddr; // [esp+28h] [ebp+0h]

  t_vel.y = a2;
  t_vel.z = retaddr;
  this->m_target_mat.w.x = 0.0;
  this->m_target_mat.w.y = 0.0;
  this->m_target_mat.w.z = 0.0;
  this->m_next_target_mat.w.x = 0.0;
  this->m_next_target_mat.w.y = 0.0;
  this->m_next_target_mat.w.z = 0.0;
  nuge::calc_velocities(&this->m_target_mat, &this->m_next_target_mat, delta_t, (phys_vec3 *)&v3, &this->m_a_vel);
}

/*
==============
rigid_body_constraint_angular_actuator::outer_epilog_update
==============
*/
void __thiscall rigid_body_constraint_angular_actuator::outer_epilog_update(rigid_body_constraint_angular_actuator *this, const float __formal)
{
  this->m_target_mat.x.x = this->m_next_target_mat.x.x;
  this->m_target_mat.x.y = this->m_next_target_mat.x.y;
  this->m_target_mat.x.z = this->m_next_target_mat.x.z;
  this->m_target_mat.y.x = this->m_next_target_mat.y.x;
  this->m_target_mat.y.y = this->m_next_target_mat.y.y;
  this->m_target_mat.y.z = this->m_next_target_mat.y.z;
  this->m_target_mat.z.x = this->m_next_target_mat.z.x;
  this->m_target_mat.z.y = this->m_next_target_mat.z.y;
  this->m_target_mat.z.z = this->m_next_target_mat.z.z;
  this->m_target_mat.w.x = this->m_next_target_mat.w.x;
  this->m_target_mat.w.y = this->m_next_target_mat.w.y;
  this->m_target_mat.w.z = this->m_next_target_mat.w.z;
}

/*
==============
rigid_body_constraint_upright::calc_current_lean_angle
==============
*/
double __thiscall rigid_body_constraint_upright::calc_current_lean_angle(rigid_body_constraint_upright *this)
{
  rigid_body *v1; // eax
  float v2; // ST00_4
  float v3; // ST04_4
  float v4; // ST08_4
  float v5; // ST1C_4
  float b2_up_axis_12; // [esp+Ch] [ebp-14h]
  float v9; // [esp+10h] [ebp-10h]

  v1 = this->b1;
  v2 = this->b1->m_mat.x.y * this->m_b2_up_axis_loc.y
     + this->b1->m_mat.x.x * this->m_b2_up_axis_loc.x
     + this->b1->m_mat.x.z * this->m_b2_up_axis_loc.z;
  v3 = v1->m_mat.y.y * this->m_b2_up_axis_loc.y
     + this->m_b2_up_axis_loc.x * v1->m_mat.y.x
     + v1->m_mat.y.z * this->m_b2_up_axis_loc.z;
  v4 = v1->m_mat.z.y * this->m_b2_up_axis_loc.y
     + this->m_b2_up_axis_loc.x * v1->m_mat.z.x
     + v1->m_mat.z.z * this->m_b2_up_axis_loc.z;
  b2_up_axis_12 = this->m_b1_up_axis_loc.z * v4 + this->m_b1_up_axis_loc.x * v2 + this->m_b1_up_axis_loc.y * v3;
  v5 = v2 * this->m_b1_right_axis_loc.x + v3 * this->m_b1_right_axis_loc.y + v4 * this->m_b1_right_axis_loc.z;
  v9 = -v5;
  if ( v9 * v9 + b2_up_axis_12 * b2_up_axis_12 <= 0.000000009999999051046871 )
    return 0.0;
  return (float)atan2(v9, b2_up_axis_12);
}

/*
==============
rigid_body_constraint_upright::calc_b1_lean_axis_loc
==============
*/
phys_vec3 *__thiscall rigid_body_constraint_upright::calc_b1_lean_axis_loc(rigid_body_constraint_upright *this, phys_vec3 *result, const float lean_angle)
{
  float v3; // ST3C_4
  float v4; // ST10_4
  float v5; // ST14_4
  float v6; // ST18_4
  float v7; // ST3C_4
  phys_vec3 *v8; // eax
  float v9; // ST20_4
  float v10; // ST24_4
  float v11; // ST28_4

  v3 = sin(lean_angle);
  v4 = this->m_b1_right_axis_loc.x * v3;
  v5 = this->m_b1_right_axis_loc.y * v3;
  v6 = v3 * this->m_b1_right_axis_loc.z;
  v7 = cos(lean_angle);
  v8 = result;
  v9 = this->m_b1_up_axis_loc.x * v7;
  v10 = this->m_b1_up_axis_loc.y * v7;
  v11 = v7 * this->m_b1_up_axis_loc.z;
  result->x = v9 - v4;
  result->y = v10 - v5;
  result->z = v11 - v6;
  return v8;
}

/*
==============
rigid_body_constraint_hinge::set
==============
*/
void __userpurge rigid_body_constraint_hinge::set(rigid_body_constraint_hinge *this@<ecx>, int a2@<ebp>, phys_vec3 *b1_r_loc, phys_vec3 *b2_r_loc, phys_vec3 *b1_axis_loc, phys_vec3 *b2_axis_loc, phys_vec3 *b1_ref_loc, phys_vec3 *b2_ref_loc, const float theta_min, const float theta_max, const float damp_k)
{
  rigid_body_constraint_hinge *v11; // esi
  phys_vec3 *v12; // eax
  phys_vec3 *v13; // edi
  phys_vec3 *v14; // eax
  float *v15; // ecx
  phys_vec3 *v16; // eax
  float *v17; // ecx
  double v18; // st7
  phys_vec3 *v19; // eax
  int v20; // ecx
  double v21; // st7
  double v22; // st7
  float *v23; // eax
  double v24; // st6
  phys_vec3 *v25; // ecx
  phys_vec3 *v26; // eax
  phys_vec3 *v27; // eax
  int v28; // ecx
  phys_vec3 *v29; // eax
  phys_vec3 *v30; // eax
  int v31; // ecx
  phys_vec3 *v32; // esi
  int v33; // [esp+18h] [ebp-9Ch]
  phys_mat44 rv; // [esp+24h] [ebp-90h]
  int v35; // [esp+68h] [ebp-4Ch]
  phys_vec3 *v36; // [esp+7Ch] [ebp-38h]
  phys_vec3 *v37; // [esp+80h] [ebp-34h]
  phys_vec3 *v38; // [esp+84h] [ebp-30h]
  float v39; // [esp+88h] [ebp-2Ch]
  float v40; // [esp+8Ch] [ebp-28h]
  float v41; // [esp+90h] [ebp-24h]
  phys_vec3 *v42; // [esp+9Ch] [ebp-18h]
  phys_vec3 *v43; // [esp+A0h] [ebp-14h]
  phys_vec3 *v44; // [esp+A4h] [ebp-10h]
  int v45; // [esp+A8h] [ebp-Ch]
  int v46; // [esp+ACh] [ebp-8h]
  int retaddr; // [esp+B4h] [ebp+0h]

  v45 = a2;
  v46 = retaddr;
  v11 = this;
  this->m_flags = 0;
  this->m_b1_r_loc.x = b1_r_loc->x;
  this->m_b1_r_loc.y = b1_r_loc->y;
  this->m_b1_r_loc.z = b1_r_loc->z;
  this->m_b2_r_loc.x = b2_r_loc->x;
  this->m_b2_r_loc.y = b2_r_loc->y;
  this->m_b2_r_loc.z = b2_r_loc->z;
  v12 = phys_Unitize((phys_vec3 *)&v39, b1_axis_loc);
  v11->m_b1_axis_loc.x = v12->x;
  v13 = &v11->m_b1_axis_loc;
  v13->y = v12->y;
  v13->z = v12->z;
  v14 = phys_Unitize((phys_vec3 *)&v39, b2_axis_loc);
  v15 = &v11->m_b2_axis_loc.x;
  *v15 = v14->x;
  v44 = &v11->m_b2_axis_loc;
  v15[1] = v14->y;
  v15[2] = v14->z;
  v16 = phys_Unitize((phys_vec3 *)&v39, b1_ref_loc);
  v17 = &v11->m_b1_ref_loc.x;
  *v17 = v16->x;
  v18 = v16->y;
  v36 = &v11->m_b1_ref_loc;
  v17[1] = v18;
  v17[2] = v16->z;
  v19 = construct_orth_ud((phys_vec3 *)&v39, &v11->m_b1_axis_loc);
  v11->m_b1_a1_loc.x = v19->x;
  v20 = (int)&v11->m_b1_a1_loc;
  v21 = v19->y;
  v42 = &v11->m_b1_a1_loc;
  *(float *)(v20 + 4) = v21;
  *(float *)(v20 + 8) = v19->z;
  v39 = v11->m_b1_axis_loc.y * v11->m_b1_a1_loc.z - v11->m_b1_axis_loc.z * v11->m_b1_a1_loc.y;
  v40 = v11->m_b1_axis_loc.z * v11->m_b1_a1_loc.x - v11->m_b1_axis_loc.x * v11->m_b1_a1_loc.z;
  v22 = v11->m_b1_axis_loc.x * v11->m_b1_a1_loc.y;
  v23 = &v11->m_b1_a2_loc.x;
  v24 = v11->m_b1_axis_loc.y * v11->m_b1_a1_loc.x;
  v25 = v44;
  v43 = &v11->m_b1_a2_loc;
  v41 = v22 - v24;
  *v23 = v39;
  v23[1] = v40;
  v23[2] = v41;
  make_rotate((phys_mat44 *)&v33, v25, theta_min, 1000.0);
  v26 = phys_multiply((phys_vec3 *)&v39, (phys_mat44 *)&v33, b2_ref_loc);
  v27 = phys_Unitize((phys_vec3 *)&v35, v26);
  v11->m_b2_ref_min_loc.x = v27->x;
  v28 = (int)&v11->m_b2_ref_min_loc;
  *(float *)(v28 + 4) = v27->y;
  v38 = &v11->m_b2_ref_min_loc;
  *(float *)(v28 + 8) = v27->z;
  make_rotate((phys_mat44 *)&v33, v44, theta_max, 1000.0);
  v29 = phys_multiply((phys_vec3 *)&v35, (phys_mat44 *)&v33, b2_ref_loc);
  v30 = phys_Unitize((phys_vec3 *)((char *)&rv.w + 4), v29);
  v11->m_b2_ref_max_loc.x = v30->x;
  v31 = (int)&v11->m_b2_ref_max_loc;
  *(float *)(v31 + 4) = v30->y;
  v37 = &v11->m_b2_ref_max_loc;
  *(float *)(v31 + 8) = v30->z;
  v11->m_damp_k = damp_k;
  PHYS_ASSERT_UNIT(&v11->m_b1_axis_loc);
  PHYS_ASSERT_UNIT(v44);
  v32 = v36;
  PHYS_ASSERT_UNIT(v36);
  PHYS_ASSERT_UNIT(v42);
  PHYS_ASSERT_UNIT(v43);
  PHYS_ASSERT_UNIT(v38);
  PHYS_ASSERT_UNIT(v37);
  PHYS_ASSERT_ORTHOGONAL(v13, v32);
  PHYS_ASSERT_ORTHOGONAL(v42, v43);
}

/*
==============
rigid_body_constraint_angular_actuator::inner_update
==============
*/
void __userpurge rigid_body_constraint_angular_actuator::inner_update(rigid_body_constraint_angular_actuator *this@<ecx>, float a2@<ebp>, const float delta_t)
{
  rigid_body_constraint_angular_actuator *v3; // esi
  int v4; // [esp+18h] [ebp-4Ch]
  phys_mat44 rv; // [esp+24h] [ebp-40h]
  float retaddr; // [esp+64h] [ebp+0h]

  rv.w.y = a2;
  rv.w.z = retaddr;
  v3 = this;
  make_rotate((phys_mat44 *)&v4, &this->m_a_vel, delta_t, 1000.0);
  phys_multiply_mat((int)&rv.w.y, &v3->m_target_mat, (phys_mat44 *)&v4, &v3->m_target_mat);
}

/*
==============
rigid_body_constraint_upright::epilog_vel_constraint
==============
*/
void __thiscall rigid_body_constraint_upright::epilog_vel_constraint(rigid_body_constraint_upright *this, const float delta_t)
{
  rigid_body_constraint_upright *v2; // esi

  v2 = this;
  if ( this->m_enabled )
  {
    this->m_lean_angle = rigid_body_constraint_upright::calc_current_lean_angle(this);
    v2->m_lean_angle_calc_delta_t = v2->m_lean_angle_calc_delta_t + delta_t;
  }
}

/*
==============
rigid_body_constraint_upright::update_lean_axis
==============
*/
void __userpurge rigid_body_constraint_upright::update_lean_axis(rigid_body_constraint_upright *this@<ecx>, int a2@<ebp>, phys_vec3 *b1_lean_center, phys_vec3 *b1_lean_axis_loc)
{
  rigid_body_constraint_upright *v4; // esi
  phys_vec3 *v5; // edi
  float v6; // eax
  float v7; // edx
  phys_vec3 *v8; // eax
  double v9; // st7
  phys_mat44 *v10; // eax
  float *v11; // esi
  long double v12; // st7
  long double v13; // st6
  long double v14; // st6
  int v15; // [esp-Ch] [ebp-7Ch]
  phys_mat44 lean_mat; // [esp+0h] [ebp-70h]
  phys_vec3 b1_lean_axis; // [esp+40h] [ebp-30h]
  phys_vec3 b2_up_axis; // [esp+50h] [ebp-20h]
  float v19; // [esp+60h] [ebp-10h]
  int v20; // [esp+64h] [ebp-Ch]
  int v21; // [esp+68h] [ebp-8h]
  int retaddr; // [esp+70h] [ebp+0h]

  v20 = a2;
  v21 = retaddr;
  v4 = this;
  this->m_b1_lean_axis_loc.x = b1_lean_axis_loc->x;
  v5 = &this->m_b1_lean_axis_loc;
  v5->y = b1_lean_axis_loc->y;
  v5->z = b1_lean_axis_loc->z;
  if ( this->m_enabled )
  {
    LODWORD(b2_up_axis.w) = (char *)this->b1 + 48;
    phys_multiply(
      (phys_vec3 *)((char *)&lean_mat.w + 4),
      (phys_mat44 *)LODWORD(b2_up_axis.w),
      &this->m_b1_forward_axis_loc);
    v6 = v4->m_b2_up_axis_loc.x;
    v7 = v4->m_b2_up_axis_loc.z;
    b1_lean_axis.z = v4->m_b2_up_axis_loc.y;
    b1_lean_axis.y = v6;
    b1_lean_axis.w = v7;
    b2_up_axis.x = v4->m_b2_up_axis_loc.w;
    v19 = lean_mat.w.y * v6 + lean_mat.w.z * b1_lean_axis.z + lean_mat.w.w * v7;
    lean_mat.w.y = lean_mat.w.y * v19;
    lean_mat.w.z = lean_mat.w.z * v19;
    lean_mat.w.w = lean_mat.w.w * v19;
    b1_lean_axis.y = v6 - lean_mat.w.y;
    b1_lean_axis.z = b1_lean_axis.z - lean_mat.w.z;
    b1_lean_axis.w = v7 - lean_mat.w.w;
    v19 = b1_lean_axis.z * b1_lean_axis.z + b1_lean_axis.y * b1_lean_axis.y + b1_lean_axis.w * b1_lean_axis.w;
    v19 = sqrt(v19);
    if ( v19 > 0.0000099999997 )
    {
      v19 = 1.0 / v19;
      b1_lean_axis.y = v19 * b1_lean_axis.y;
      b1_lean_axis.z = b1_lean_axis.z * v19;
      b1_lean_axis.w = v19 * b1_lean_axis.w;
      phys_multiply((phys_vec3 *)((char *)&lean_mat.w + 4), (phys_mat44 *)LODWORD(b2_up_axis.w), v5);
      make_rotate((phys_mat44 *)&v15, (phys_vec3 *)((char *)&lean_mat.w + 4), (phys_vec3 *)((char *)&b1_lean_axis + 4));
      v8 = phys_multiply((phys_vec3 *)((char *)&b1_lean_axis + 4), (phys_mat44 *)&v15, b1_lean_center);
      lean_mat.w.y = b1_lean_center->x - v8->x;
      lean_mat.w.z = b1_lean_center->y - v8->y;
      v9 = b1_lean_center->z - v8->z;
      v10 = &v4->b1->m_mat;
      lean_mat.w.w = v9;
      lean_mat.z.y = lean_mat.w.y;
      lean_mat.z.z = lean_mat.w.z;
      lean_mat.z.w = lean_mat.w.w;
      phys_full_multiply_mat((int)&v20, v10, (phys_mat44 *)&v15, v10);
      v11 = &v4->b1->m_last_position.x;
      v12 = v11[24];
      b2_up_axis.w = fabs(v12);
      if ( b2_up_axis.w > 100000.0 || (v13 = v11[25], b2_up_axis.w = fabs(v13), b2_up_axis.w > 100000.0) )
      {
        phys_exec_debug_callback(v11);
      }
      else
      {
        v14 = v11[26];
        b2_up_axis.w = fabs(v14);
        if ( b2_up_axis.w > 100000.0 )
          phys_exec_debug_callback(v11);
      }
    }
  }
}

/*
==============
rigid_body_constraint_point::setup_constraint
==============
*/
void __userpurge rigid_body_constraint_point::setup_constraint(rigid_body_constraint_point *this@<ecx>, int a2@<ebp>, pulse_sum_constraint_solver *psys, const float delta_t)
{
  rigid_body_constraint_point *v4; // esi
  rigid_body *v5; // edi
  int v6; // [esp+20h] [ebp-3Ch]
  int v7; // [esp+30h] [ebp-2Ch]
  rigid_body *v8; // [esp+4Ch] [ebp-10h]
  int v9; // [esp+50h] [ebp-Ch]
  int v10; // [esp+54h] [ebp-8h]
  int retaddr; // [esp+5Ch] [ebp+0h]

  v9 = a2;
  v10 = retaddr;
  v4 = this;
  v5 = this->b2;
  phys_multiply((phys_vec3 *)&v7, &v5->m_mat, &this->m_b2_r_loc);
  v8 = v4->b1;
  phys_multiply((phys_vec3 *)&v6, &v8->m_mat, &v4->m_b1_r_loc);
  pulse_sum_constraint_solver::create_point(
    psys,
    v8,
    (phys_vec3 *)&v6,
    v5,
    (phys_vec3 *)&v7,
    v4->m_ps_cache_list,
    delta_t,
    v4->m_spring_enabled,
    v4->m_spring_k,
    v4->m_damp_k);
}

/*
==============
rigid_body_constraint_hinge::setup_constraint
==============
*/
void __userpurge rigid_body_constraint_hinge::setup_constraint(rigid_body_constraint_hinge *this@<ecx>, int a2@<ebp>, pulse_sum_constraint_solver *psys, const float delta_t)
{
  rigid_body_constraint_hinge *v4; // esi
  rigid_body *v5; // edi
  phys_mat44 *v6; // edi
  pulse_sum_angular *v7; // eax
  double v8; // st7
  phys_mat44 *v9; // edi
  double v10; // st7
  unsigned int v11; // ecx
  double v12; // st6
  double v13; // st5
  double v14; // st4
  double v15; // st2
  double v16; // st5
  int v17; // ecx
  unsigned int v18; // ecx
  double v19; // st2
  double v20; // st4
  double v21; // st3
  unsigned int v22; // ecx
  double v23; // st2
  rigid_body *v24; // eax
  pulse_sum_angular *v25; // eax
  pulse_sum_angular *v26; // eax
  int v27; // [esp+20h] [ebp-8Ch]
  phys_vec3 b1_axis; // [esp+2Ch] [ebp-80h]
  float v29; // [esp+40h] [ebp-6Ch]
  float v30; // [esp+44h] [ebp-68h]
  float v31; // [esp+48h] [ebp-64h]
  float v32; // [esp+50h] [ebp-5Ch]
  float v33; // [esp+54h] [ebp-58h]
  float v34; // [esp+58h] [ebp-54h]
  phys_vec3 b1_ref; // [esp+5Ch] [ebp-50h]
  phys_vec3 b2_axis; // [esp+6Ch] [ebp-40h]
  phys_vec3 b2_ref_max; // [esp+7Ch] [ebp-30h]
  float v38; // [esp+9Ch] [ebp-10h]
  int v39; // [esp+A0h] [ebp-Ch]
  int v40; // [esp+A4h] [ebp-8h]
  int retaddr; // [esp+ACh] [ebp+0h]

  v39 = a2;
  v40 = retaddr;
  v4 = this;
  if ( !(this->m_flags & 0x10) )
  {
    v5 = this->b2;
    phys_multiply((phys_vec3 *)&v29, &v5->m_mat, &this->m_b2_r_loc);
    phys_multiply((phys_vec3 *)((char *)&b1_axis + 4), &v4->b1->m_mat, &v4->m_b1_r_loc);
    pulse_sum_constraint_solver::create_point(
      psys,
      v4->b1,
      (phys_vec3 *)((char *)&b1_axis + 4),
      v5,
      (phys_vec3 *)&v29,
      v4->m_ps_cache,
      delta_t,
      0,
      0.0,
      0.0);
  }
  v6 = &v4->b1->m_mat;
  phys_multiply((phys_vec3 *)&v27, v6, &v4->m_b1_axis_loc);
  phys_multiply((phys_vec3 *)((char *)&b1_ref + 4), &v4->b2->m_mat, &v4->m_b2_axis_loc);
  phys_multiply((phys_vec3 *)((char *)&b1_axis + 4), v6, &v4->m_b1_a2_loc);
  phys_multiply((phys_vec3 *)&v29, v6, &v4->m_b1_a1_loc);
  pulse_sum_constraint_solver::create_hinge(
    psys,
    v4->b1,
    (phys_vec3 *)&v27,
    v4->b2,
    (phys_vec3 *)((char *)&b1_ref + 4),
    (phys_vec3 *)&v29,
    (phys_vec3 *)((char *)&b1_axis + 4),
    &v4->m_ps_cache[4],
    delta_t);
  if ( v4->m_damp_k > 0.0000099999997 )
  {
    v7 = pulse_sum_constraint_solver::create_pulse_sum_angular(
           psys,
           v4->b1,
           &PHYS_ZERO_VEC_84,
           v4->b2,
           &PHYS_ZERO_VEC_84,
           (phys_vec3 *)((char *)&b1_ref + 4),
           &v4->m_ps_cache[3]);
    v7->m_right_side = 0.0;
    v7->m_big_dirt = 0.0;
    v7->m_cfm = 0.0;
    v38 = delta_t * v4->m_damp_k;
    v8 = v38;
    v7->m_pulse_sum_min = -v38;
    v7->m_pulse_sum_max = v8;
  }
  phys_multiply((phys_vec3 *)&v32, &v4->b1->m_mat, &v4->m_b1_ref_loc);
  v9 = &v4->b2->m_mat;
  phys_multiply((phys_vec3 *)((char *)&b2_ref_max + 4), v9, &v4->m_b2_ref_min_loc);
  phys_multiply((phys_vec3 *)((char *)&b2_axis + 4), v9, &v4->m_b2_ref_max_loc);
  v10 = b1_ref.w;
  v11 = v4->m_flags;
  v12 = b1_ref.z;
  v13 = v33;
  v14 = v33;
  if ( v11 & 8 )
  {
    v38 = b2_ref_max.y * v32 + v14 * b2_ref_max.z + v34 * b2_ref_max.w;
    v15 = v13 * b2_axis.z;
    v16 = v38;
    v38 = v32 * b2_axis.y + v15 + v34 * b2_axis.w;
    if ( v38 > v16 )
    {
      v18 = v11 & 0xFFFFFFFE | 2;
    }
    else
    {
      v17 = v11 | 1;
      v4->m_flags = v17;
      v18 = v17 & 0xFFFFFFFD;
    }
    v4->m_flags = v18;
  }
  else
  {
    v19 = v14 * b2_ref_max.w - v34 * b2_ref_max.z;
    v20 = v34;
    v29 = v19;
    v21 = v32;
    v30 = v34 * b2_ref_max.y - b2_ref_max.w * v32;
    v31 = v32 * b2_ref_max.z - v13 * b2_ref_max.y;
    v38 = v12 * v30 + v29 * b1_ref.y + v10 * v31;
    if ( v38 < -0.043618999 )
      v22 = v11 & 0xFFFFFFFE;
    else
      v22 = v11 | 1;
    v23 = b2_axis.w;
    v4->m_flags = v22;
    v29 = v23 * v13 - b2_axis.z * v20;
    v30 = v20 * b2_axis.y - b2_axis.w * v21;
    v31 = v21 * b2_axis.z - b2_axis.y * v13;
    v38 = v30 * v12 + v29 * b1_ref.y + v31 * v10;
    if ( v38 > 0.043618999 )
      v4->m_flags &= 0xFFFFFFFD;
    else
      v4->m_flags |= 2u;
  }
  if ( v4->m_flags & 1 )
  {
    v29 = -b1_ref.y;
    v24 = v4->b2;
    v30 = -v12;
    v31 = -v10;
    v25 = pulse_sum_constraint_solver::create_pulse_sum_angular(
            psys,
            v4->b1,
            (phys_vec3 *)&v32,
            v24,
            (phys_vec3 *)((char *)&b2_ref_max + 4),
            (phys_vec3 *)&v29,
            &v4->m_ps_cache[6]);
    v25->m_pulse_sum_min = -10000000.0;
    v25->m_pulse_sum_max = 0.0;
    pulse_sum_angular::setup_vel_uni_standard(v25, delta_t, 5.0);
  }
  if ( v4->m_flags & 2 )
  {
    v26 = pulse_sum_constraint_solver::create_pulse_sum_angular(
            psys,
            v4->b1,
            (phys_vec3 *)&v32,
            v4->b2,
            (phys_vec3 *)((char *)&b2_axis + 4),
            (phys_vec3 *)((char *)&b1_ref + 4),
            &v4->m_ps_cache[7]);
    v26->m_pulse_sum_min = -10000000.0;
    v26->m_pulse_sum_max = 0.0;
    pulse_sum_angular::setup_vel_uni_standard(v26, delta_t, 5.0);
  }
}

/*
==============
rigid_body_constraint_distance::setup_constraint
==============
*/
void __userpurge rigid_body_constraint_distance::setup_constraint(rigid_body_constraint_distance *this@<ecx>, int a2@<ebp>, pulse_sum_constraint_solver *psys, const float delta_t)
{
  rigid_body_constraint_distance *v4; // esi
  float *v5; // edi
  float *v6; // eax
  pulse_sum_normal *v7; // edi
  rigid_body *v8; // eax
  float pos_adjust; // ST14_4
  pulse_sum_normal *v10; // eax
  rigid_body *v11; // ST08_4
  rigid_body *v12; // ST00_4
  pulse_sum_normal *v13; // ecx
  double v14; // st7
  phys_vec3 *v15; // eax
  pulse_sum_normal *v16; // edi
  rigid_body *v17; // eax
  double v18; // st7
  float *v19; // eax
  double v20; // st7
  float v21; // [esp+1Ch] [ebp-ACh]
  float v22; // [esp+20h] [ebp-A8h]
  float v23; // [esp+24h] [ebp-A4h]
  phys_vec3 r2; // [esp+28h] [ebp-A0h]
  phys_vec3 b1_r; // [esp+38h] [ebp-90h]
  phys_vec3 b2_r; // [esp+48h] [ebp-80h]
  phys_vec3 ud; // [esp+58h] [ebp-70h]
  phys_vec3 b1_pt; // [esp+68h] [ebp-60h]
  phys_vec3 b2_pt; // [esp+78h] [ebp-50h]
  float v30; // [esp+98h] [ebp-30h]
  float v31; // [esp+9Ch] [ebp-2Ch]
  float v32; // [esp+A0h] [ebp-28h]
  float ndamp_dir; // [esp+A4h] [ebp-24h]
  float v34; // [esp+B8h] [ebp-10h]
  int v35; // [esp+BCh] [ebp-Ch]
  int v36; // [esp+C0h] [ebp-8h]
  int retaddr; // [esp+C8h] [ebp+0h]

  v35 = a2;
  v36 = retaddr;
  v4 = this;
  if ( this->m_flags & 1 )
  {
    if ( this->m_min_distance < 0.0
      && _tlAssert("source/rbc_def_generic.cpp", 137, "m_min_distance >= 0.0f", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v4->m_max_distance < (double)v4->m_min_distance
      && _tlAssert("source/rbc_def_generic.cpp", 138, "m_min_distance <= m_max_distance", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v5 = &v4->b1->m_last_position.x;
    phys_multiply((phys_vec3 *)((char *)&r2 + 4), &v4->b1->m_mat, &v4->m_b1_r_loc);
    phys_multiply((phys_vec3 *)((char *)&b1_r + 4), &v4->b2->m_mat, &v4->m_b2_r_loc);
    v6 = &v4->b2->m_last_position.x;
    ud.y = v5[24] + r2.y;
    ud.z = v5[25] + r2.z;
    ud.w = v5[26] + r2.w;
    b1_pt.y = v6[24] + b1_r.y;
    b1_pt.z = v6[25] + b1_r.z;
    b1_pt.w = v6[26] + b1_r.w;
    v31 = b1_pt.y - ud.y;
    v32 = b1_pt.z - ud.z;
    ndamp_dir = b1_pt.w - ud.w;
    v30 = v32 * v32 + v31 * v31 + ndamp_dir * ndamp_dir;
    if ( v30 >= 0.0000010000001 )
    {
      v34 = sqrt(v30);
      v34 = 1.0 / v34;
      b2_r.y = v31 * v34;
      b2_r.z = v32 * v34;
      b2_r.w = v34 * ndamp_dir;
      v7 = pulse_sum_constraint_solver::create_pulse_sum_normal(psys);
      b2_pt.y = -b2_r.y;
      v8 = v4->b2;
      b2_pt.z = -b2_r.z;
      b2_pt.w = -b2_r.w;
      pulse_sum_normal::set(
        v7,
        v4->b1,
        (phys_vec3 *)((char *)&r2 + 4),
        v8,
        (phys_vec3 *)((char *)&b1_r + 4),
        (phys_vec3 *)((char *)&b2_pt + 4),
        v4->m_ps_cache_list,
        &PHYS_ZERO_VEC_84);
      v7->m_pulse_sum_min = -10000000.0;
      v7->m_pulse_sum_max = 0.0;
      pos_adjust = -v4->m_max_distance;
      pulse_sum_normal::setup_vel_uni_standard_pos_adjust(v7, delta_t, pos_adjust, 1700.0);
      v7->m_right_side = v4->m_max_distance_vel + v7->m_right_side;
      if ( v4->m_min_distance > 0.0099999998 )
      {
        v10 = pulse_sum_constraint_solver::create_pulse_sum_normal(psys);
        v11 = v4->b2;
        v12 = v4->b1;
        v34 = *(float *)&v10;
        pulse_sum_normal::set(
          v10,
          v12,
          (phys_vec3 *)((char *)&r2 + 4),
          v11,
          (phys_vec3 *)((char *)&b1_r + 4),
          (phys_vec3 *)((char *)&b2_r + 4),
          &v4->m_ps_cache_list[1],
          &PHYS_ZERO_VEC_84);
        v13 = (pulse_sum_normal *)LODWORD(v34);
        *(float *)(LODWORD(v34) + 96) = -10000000.0;
        v13->m_pulse_sum_max = 0.0;
        pulse_sum_normal::setup_vel_uni_standard_pos_adjust(v13, delta_t, v4->m_min_distance, 1700.0);
      }
      if ( v4->m_damp_coef > 0.0000099999997 )
      {
        v34 = v4->m_max_distance - 0.1000000014901161;
        v34 = v34 * v34;
        if ( v34 <= (double)v30 )
        {
          v34 = v4->m_max_distance + 0.1000000014901161;
          v34 = v34 * v34;
          if ( v34 >= (double)v30 )
          {
            pulse_sum_normal::get_relative_velocity(v7, (phys_vec3 *)&v31);
            v34 = v32 * b2_r.z + v31 * b2_r.y + ndamp_dir * b2_r.w;
            b2_pt.y = b2_r.y * v34;
            b2_pt.z = b2_r.z * v34;
            b2_pt.w = v34 * b2_r.w;
            v31 = v31 - b2_pt.y;
            v32 = v32 - b2_pt.z;
            ndamp_dir = ndamp_dir - b2_pt.w;
            v30 = Abs((vec3_t *)&v31);
            v14 = v30;
            if ( v30 < 0.00009999999747378752 )
            {
              v15 = pulse_sum_normal::get_relative_velocity_change_dir(v7, (phys_vec3 *)((char *)&b2_pt + 4));
              v31 = v15->x;
              v32 = v15->y;
              ndamp_dir = v15->z;
              v34 = v32 * b2_r.z + v31 * b2_r.y + ndamp_dir * b2_r.w;
              b2_pt.y = b2_r.y * v34;
              b2_pt.z = b2_r.z * v34;
              b2_pt.w = v34 * b2_r.w;
              v31 = v31 - b2_pt.y;
              v32 = v32 - b2_pt.z;
              ndamp_dir = ndamp_dir - b2_pt.w;
              v30 = Abs((vec3_t *)&v31);
              v14 = v30;
            }
            if ( v14 > 0.00009999999747378752 )
            {
              v34 = 1.0 / v14;
              v31 = v34 * v31;
              v32 = v32 * v34;
              ndamp_dir = v34 * ndamp_dir;
              v16 = pulse_sum_constraint_solver::create_pulse_sum_normal(psys);
              if ( v4->m_flags & 2 )
              {
                v17 = v4->b1;
                ud.y = b1_pt.y - v4->b1->m_mat.w.x;
                ud.z = b1_pt.z - v17->m_mat.w.y;
                ud.w = b1_pt.w - v17->m_mat.w.z;
                b2_pt.y = ud.y;
                b2_pt.z = ud.z;
                b2_pt.w = ud.w;
                v21 = b1_r.y;
                v22 = b1_r.z;
                v18 = b1_r.w;
              }
              else
              {
                v19 = &v4->b2->m_last_position.x;
                b2_pt.y = r2.y;
                b2_pt.z = r2.z;
                b2_pt.w = r2.w;
                b1_pt.y = ud.y - v19[24];
                b1_pt.z = ud.z - v19[25];
                b1_pt.w = ud.w - v19[26];
                v21 = b1_pt.y;
                v22 = b1_pt.z;
                v18 = b1_pt.w;
              }
              v23 = v18;
              pulse_sum_normal::set(
                v16,
                v4->b1,
                (phys_vec3 *)((char *)&b2_pt + 4),
                v4->b2,
                (phys_vec3 *)&v21,
                (phys_vec3 *)&v31,
                &v4->m_ps_cache_list[2],
                &PHYS_ZERO_VEC_84);
              v34 = 1.0 / (v4->m_damp_coef * delta_t);
              v16->m_right_side = 0.0;
              v16->m_big_dirt = 0.0;
              v20 = v34;
              v16->m_cfm = v34;
              v16->m_denom = v20 + v16->m_denom;
              v16->m_pulse_sum_min = -10000000.0;
              v16->m_pulse_sum_max = 10000000.0;
            }
          }
        }
      }
    }
  }
}

/*
==============
rigid_body_constraint_angular_actuator::setup_constraint
==============
*/
void __userpurge rigid_body_constraint_angular_actuator::setup_constraint(rigid_body_constraint_angular_actuator *this@<ecx>, phys_mat44 *a2@<ebp>, pulse_sum_constraint_solver *psys, const float delta_t)
{
  rigid_body_constraint_angular_actuator *v4; // esi
  phys_mat44 *v5; // ST10_4
  phys_vec3 *v6; // edi
  phys_vec3 *v7; // eax
  rigid_body *v8; // edx
  pulse_sum_angular *v9; // eax
  double v10; // st7
  float *v11; // edi
  double v12; // st7
  pulse_sum_angular *v13; // edi
  double v14; // st7
  phys_vec3 *v15; // eax
  pulse_sum_angular *v16; // esi
  double v17; // st7
  float v18; // [esp-Ch] [ebp-7Ch]
  float v19; // [esp-8h] [ebp-78h]
  float v20; // [esp-4h] [ebp-74h]
  phys_mat44 mat; // [esp+0h] [ebp-70h]
  phys_vec3 a_vel; // [esp+40h] [ebp-30h]
  float v23; // [esp+54h] [ebp-1Ch]
  phys_vec3 *v24; // [esp+58h] [ebp-18h]
  float v25; // [esp+5Ch] [ebp-14h]
  float v26; // [esp+60h] [ebp-10h]
  phys_mat44 *b2_mat; // [esp+64h] [ebp-Ch]
  const float ps_limit; // [esp+68h] [ebp-8h]
  float retaddr; // [esp+70h] [ebp+0h]

  b2_mat = a2;
  ps_limit = retaddr;
  v4 = this;
  if ( this->m_enabled )
  {
    v5 = &this->b1->m_mat;
    v6 = &this->b2->m_mat.x;
    v25 = this->m_power * delta_t * this->m_power_scale;
    v24 = v6;
    phys_multiply_mat((int)&b2_mat, (phys_mat44 *)&v18, v5, &this->m_target_mat);
    v7 = phys_multiply((phys_vec3 *)((char *)&a_vel + 4), &v4->b1->m_mat, &v4->m_a_vel);
    v8 = v4->b2;
    mat.w.y = v7->x;
    mat.w.z = v7->y;
    mat.w.w = v7->z;
    v9 = pulse_sum_constraint_solver::create_pulse_sum_angular(
           psys,
           v4->b1,
           (phys_vec3 *)&v18,
           v8,
           v6,
           (phys_vec3 *)((char *)&mat.x + 4),
           v4->m_ps_cache_list);
    v10 = v25;
    v11 = (float *)v9;
    v26 = -v25;
    v9->m_pulse_sum_min = v26;
    v9->m_pulse_sum_max = v10;
    *(double *)&a_vel.w = -1.0 / delta_t;
    v12 = pulse_sum_angular::get_pos(v9);
    v11[28] = v12 * *(double *)&a_vel.w;
    v11[27] = 0.0;
    v11[29] = 0.0;
    v11[30] = v11[30] + 0.0;
    v23 = mat.x.z * mat.w.z + mat.x.y * mat.w.y + mat.x.w * mat.w.w;
    v11[27] = 0.0 - v23;
    v13 = pulse_sum_constraint_solver::create_pulse_sum_angular(
            psys,
            v4->b1,
            (phys_vec3 *)((char *)&mat.x + 4),
            v4->b2,
            v24 + 1,
            (phys_vec3 *)((char *)&mat.y + 4),
            &v4->m_ps_cache_list[1]);
    v13->m_pulse_sum_min = v26;
    v13->m_pulse_sum_max = v25;
    v14 = pulse_sum_angular::get_pos(v13);
    v15 = v24;
    v13->m_big_dirt = v14 * *(double *)&a_vel.w;
    v13->m_right_side = 0.0;
    v13->m_cfm = 0.0;
    v13->m_denom = v13->m_denom + 0.0;
    v23 = mat.y.y * mat.w.y + mat.y.z * mat.w.z + mat.y.w * mat.w.w;
    v13->m_right_side = 0.0 - v23;
    v16 = pulse_sum_constraint_solver::create_pulse_sum_angular(
            psys,
            v4->b1,
            (phys_vec3 *)((char *)&mat.y + 4),
            v4->b2,
            v15 + 2,
            (phys_vec3 *)&v18,
            &v4->m_ps_cache_list[2]);
    v16->m_pulse_sum_min = v26;
    v16->m_pulse_sum_max = v25;
    v17 = pulse_sum_angular::get_pos(v16);
    v16->m_big_dirt = v17 * *(double *)&a_vel.w;
    v16->m_right_side = 0.0;
    v16->m_cfm = 0.0;
    v16->m_denom = v16->m_denom + 0.0;
    v23 = v19 * mat.w.z + v18 * mat.w.y + v20 * mat.w.w;
    v16->m_right_side = 0.0 - v23;
  }
}

/*
==============
rigid_body_constraint_upright::setup_constraint
==============
*/
void __userpurge rigid_body_constraint_upright::setup_constraint(rigid_body_constraint_upright *this@<ecx>, int a2@<ebp>, pulse_sum_constraint_solver *psys, const float delta_t)
{
  rigid_body_constraint_upright *v4; // esi
  rigid_body *v5; // edi
  pulse_sum_angular *v6; // esi
  double v7; // st7
  double v8; // st7
  int v9; // [esp-Ch] [ebp-3Ch]
  phys_vec3 b1_lean_axis; // [esp+0h] [ebp-30h]
  float v11; // [esp+20h] [ebp-10h]
  int v12; // [esp+24h] [ebp-Ch]
  int v13; // [esp+28h] [ebp-8h]
  int retaddr; // [esp+30h] [ebp+0h]

  v12 = a2;
  v13 = retaddr;
  v4 = this;
  if ( this->m_enabled )
  {
    v5 = this->b1;
    phys_multiply((phys_vec3 *)((char *)&b1_lean_axis + 4), &this->b1->m_mat, &this->m_b1_forward_axis_loc);
    phys_multiply((phys_vec3 *)&v9, &v5->m_mat, &v4->m_b1_lean_axis_loc);
    v6 = pulse_sum_constraint_solver::create_pulse_sum_angular(
           psys,
           v5,
           (phys_vec3 *)&v9,
           v4->b2,
           &v4->m_b2_up_axis_loc,
           (phys_vec3 *)((char *)&b1_lean_axis + 4),
           v4->m_ps_cache_list);
    v6->m_pulse_sum_min = -10000000.0;
    v6->m_pulse_sum_max = 10000000.0;
    v7 = 0.016666668;
    if ( delta_t > 0.016666668 )
      v7 = delta_t;
    v11 = v7;
    v8 = pulse_sum_angular::get_pos(v6);
    v6->m_big_dirt = v8 * (-0.5 / v11);
    v6->m_right_side = 0.0;
    v6->m_cfm = 0.0;
  }
}

