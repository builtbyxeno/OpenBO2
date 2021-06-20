/*
==============
rbint::take_last_step
==============
*/
void rbint::take_last_step(user_rigid_body *rb)
{
  phys_mat44 *v1; // eax

  if ( !(rb->m_flags & 0x20)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\rigid_body_internal.h",
         75,
         "rb->is_user_rigid_body()",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !rb->m_dictator
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\rigid_body_internal.h",
         76,
         "rb->m_dictator",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1 = rb->m_dictator;
  rb->m_mat.x.x = v1->x.x;
  rb->m_mat.x.y = v1->x.y;
  rb->m_mat.x.z = v1->x.z;
  rb->m_mat.y.x = v1->y.x;
  rb->m_mat.y.y = v1->y.y;
  rb->m_mat.y.z = v1->y.z;
  rb->m_mat.z.x = v1->z.x;
  rb->m_mat.z.y = v1->z.y;
  rb->m_mat.z.z = v1->z.z;
  rb->m_mat.w.x = v1->w.x;
  rb->m_mat.w.y = v1->w.y;
  rb->m_mat.w.z = v1->w.z;
}

/*
==============
rbint::prolog_frame_advance
==============
*/
void rbint::prolog_frame_advance(user_rigid_body *rb, const float delta_t)
{
  user_rigid_body *v2; // esi
  float *v3; // ebx
  double v4; // st7
  long double v5; // st6
  long double v6; // st6
  long double v7; // st6
  long double v8; // st6
  long double v9; // st6
  float rba; // [esp+20h] [ebp+8h]
  float rbb; // [esp+20h] [ebp+8h]
  float rbc; // [esp+20h] [ebp+8h]
  float rbd; // [esp+20h] [ebp+8h]
  float rbe; // [esp+20h] [ebp+8h]
  float rbf; // [esp+20h] [ebp+8h]

  v2 = rb;
  if ( !(rb->m_flags & 0x20)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\rigid_body_internal.h",
         37,
         "rb->is_user_rigid_body()",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !rb->m_dictator
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\rigid_body_internal.h",
         38,
         "rb->m_dictator",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v3 = &rb->m_a_vel.x;
  nuge::calc_velocities(&rb->m_mat, rb->m_dictator, delta_t, &rb->m_t_vel, &rb->m_a_vel);
  v4 = 100000.0;
  rba = fabs(rb->m_t_vel.x);
  if ( rba > 100000.0
    || (v5 = v2->m_t_vel.y, rbb = fabs(v5), rbb > 100000.0)
    || (v6 = v2->m_t_vel.z, rbc = fabs(v6), rbc > 100000.0) )
  {
    phys_exec_debug_callback(v2);
    v4 = 100000.0;
  }
  v7 = *v3;
  rbd = fabs(v7);
  if ( rbd > v4 || (v8 = v2->m_a_vel.y, rbe = fabs(v8), rbe > v4) )
  {
    phys_exec_debug_callback(v2);
  }
  else
  {
    v9 = v2->m_a_vel.z;
    rbf = fabs(v9);
    if ( v4 < rbf )
      phys_exec_debug_callback(v2);
  }
}

/*
==============
rbint::collision_prolog
==============
*/
void rbint::collision_prolog(user_rigid_body *rb, const float delta_t)
{
  float v2; // ST20_4
  float v3; // ST24_4
  float v4; // ST28_4
  long double v5; // st7
  float v6; // ST3C_4
  long double v7; // st6
  float v8; // ST3C_4
  long double v9; // st6
  float v10; // ST3C_4

  if ( !(rb->m_flags & 0x20)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\rigid_body_internal.h",
         46,
         "rb->is_user_rigid_body()",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !rb->m_dictator
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\rigid_body_internal.h",
         47,
         "rb->m_dictator",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v2 = rb->m_t_vel.x * delta_t;
  v3 = rb->m_t_vel.y * delta_t;
  v4 = delta_t * rb->m_t_vel.z;
  rb->m_moved_vec.x = v2;
  rb->m_moved_vec.y = v3;
  rb->m_moved_vec.z = v4;
  v5 = rb->m_moved_vec.x;
  v6 = fabs(v5);
  if ( v6 > 100000.0
    || (v7 = rb->m_moved_vec.y, v8 = fabs(v7), v8 > 100000.0)
    || (v9 = rb->m_moved_vec.z, v10 = fabs(v9), v10 > 100000.0) )
  {
    phys_exec_debug_callback(rb);
  }
  rb->m_smallest_lambda = 0.0;
}

/*
==============
rbint::take_next_step
==============
*/
void __usercall rbint::take_next_step(int a1@<ebp>, user_rigid_body *rb, const float delta_t)
{
  int v3; // [esp+18h] [ebp-5Ch]
  phys_mat44 rv; // [esp+24h] [ebp-50h]
  int v5; // [esp+68h] [ebp-Ch]
  int v6; // [esp+6Ch] [ebp-8h]
  int retaddr; // [esp+74h] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !(rb->m_flags & 0x20)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\rigid_body_internal.h",
         65,
         "rb->is_user_rigid_body()",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !rb->m_dictator
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\rigid_body_internal.h",
         66,
         "rb->m_dictator",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  rv.w.y = rb->m_t_vel.x * delta_t;
  rv.w.z = rb->m_t_vel.y * delta_t;
  rv.w.w = rb->m_t_vel.z * delta_t;
  rb->m_mat.w.x = rb->m_mat.w.x + rv.w.y;
  rb->m_mat.w.y = rb->m_mat.w.y + rv.w.z;
  rb->m_mat.w.z = rb->m_mat.w.z + rv.w.w;
  make_rotate((phys_mat44 *)&v3, &rb->m_a_vel, delta_t, 1000.0);
  phys_multiply_mat((int)&v5, &rb->m_mat, (phys_mat44 *)&v3, &rb->m_mat);
}

/*
==============
rbint::collision_prolog
==============
*/
void rbint::collision_prolog(rigid_body *const rb, const float delta_t)
{
  float v2; // ST24_4
  float v3; // ST28_4
  float v4; // ST2C_4
  float v5; // ST14_4
  float v6; // ST18_4
  float v7; // ST1C_4
  float v8; // ST24_4
  float v9; // ST28_4
  float v10; // ST2C_4
  long double v11; // st7
  float v12; // ST40_4
  long double v13; // st6
  float v14; // ST40_4
  long double v15; // st6
  float v16; // ST40_4

  v2 = rb->m_t_vel.x * delta_t;
  v3 = rb->m_t_vel.y * delta_t;
  v4 = delta_t * rb->m_t_vel.z;
  v5 = v2 + rb->m_mat.w.x;
  v6 = rb->m_mat.w.y + v3;
  v7 = rb->m_mat.w.z + v4;
  v8 = v5 - rb->m_last_position.x;
  v9 = v6 - rb->m_last_position.y;
  v10 = v7 - rb->m_last_position.z;
  rb->m_moved_vec.x = v8;
  rb->m_moved_vec.y = v9;
  rb->m_moved_vec.z = v10;
  v11 = rb->m_moved_vec.x;
  v12 = fabs(v11);
  if ( v12 > 100000.0
    || (v13 = rb->m_moved_vec.y, v14 = fabs(v13), v14 > 100000.0)
    || (v15 = rb->m_moved_vec.z, v16 = fabs(v15), v16 > 100000.0) )
  {
    phys_exec_debug_callback(rb);
  }
  rb->m_smallest_lambda = 1.0;
  rigid_body::swap_last_position(rb);
  rb->m_largest_vel_sq = 0.0;
}

/*
==============
rbint::update_stability
==============
*/
void rbint::update_stability(rigid_body *const rb, const float delta_t)
{
  rigid_body *v2; // ecx
  int v3; // esi
  unsigned int v4; // edx
  float max_stable_energy_sq; // [esp+4h] [ebp-4h]
  float rba; // [esp+10h] [ebp+8h]

  v2 = rb;
  max_stable_energy_sq = 141.60999;
  v3 = rb->m_stable_min_contact_count;
  if ( !v3 )
    max_stable_energy_sq = 29.593601;
  if ( max_stable_energy_sq >= (double)rb->m_largest_vel_sq )
  {
    v4 = rb->m_flags;
    if ( !(v4 & 4) )
    {
      rba = rb->m_stable_energy_time + delta_t;
      v2->m_stable_energy_time = rba;
      if ( rba >= 1.0 )
      {
        v2->m_flags = v4 | 4;
      }
      else if ( rba >= 0.5 && v2->m_contact_count >= v3 )
      {
        v2->m_flags = v4 | 4;
      }
    }
  }
  else
  {
    rb->m_flags &= 0xFFFFFFFB;
    rb->m_stable_energy_time = 0.0;
  }
}

/*
==============
rbint::gtv
==============
*/
phys_vec3 *rbint::gtv(phys_vec3 *result, rigid_body *const b, phys_vec3 *r)
{
  rigid_body *v3; // ecx
  phys_vec3 *v4; // eax
  float v5; // ST00_4
  float v6; // ST04_4
  phys_vec3 *v7; // eax
  float v8; // ST08_4

  v3 = b;
  v4 = r;
  v5 = v3->m_a_vel.y * v4->z - v3->m_a_vel.z * v4->y;
  v6 = v3->m_a_vel.z * v4->x - v3->m_a_vel.x * v4->z;
  v7 = result;
  v8 = b->m_a_vel.x * r->y - b->m_a_vel.y * r->x;
  result->x = b->m_t_vel.x + v5;
  result->y = b->m_t_vel.y + v6;
  result->z = b->m_t_vel.z + v8;
  return v7;
}

/*
==============
rbint::solver_prolog
==============
*/
void rbint::solver_prolog(rigid_body *rb, const float delta_t)
{
  rigid_body *v2; // esi
  long double v3; // st6
  double v4; // st7
  long double v5; // st6
  long double v6; // st6
  long double v7; // st6
  long double v8; // st6
  long double v9; // st6
  float rba; // [esp+8h] [ebp+8h]
  float rbb; // [esp+8h] [ebp+8h]
  float rbc; // [esp+8h] [ebp+8h]
  float rbd; // [esp+8h] [ebp+8h]
  float rbe; // [esp+8h] [ebp+8h]
  float rbf; // [esp+8h] [ebp+8h]
  float rbg; // [esp+8h] [ebp+8h]

  v2 = rb;
  rba = 1.0 / delta_t;
  v2->m_force_sum.x = rba * v2->m_force_sum.x;
  v2->m_force_sum.y = rba * v2->m_force_sum.y;
  v2->m_force_sum.z = rba * v2->m_force_sum.z;
  v2->m_torque_sum.x = v2->m_torque_sum.x * rba;
  v2->m_torque_sum.y = rba * v2->m_torque_sum.y;
  v2->m_torque_sum.z = rba * v2->m_torque_sum.z;
  v3 = v2->m_force_sum.x;
  v4 = 100000.0;
  rbb = fabs(v3);
  if ( rbb > 100000.0
    || (v5 = v2->m_force_sum.y, rbc = fabs(v5), rbc > 100000.0)
    || (v6 = v2->m_force_sum.z, rbd = fabs(v6), rbd > 100000.0) )
  {
    phys_exec_debug_callback(v2);
    v4 = 100000.0;
  }
  v7 = v2->m_torque_sum.x;
  rbe = fabs(v7);
  if ( rbe > v4 || (v8 = v2->m_torque_sum.y, rbf = fabs(v8), rbf > v4) )
  {
    phys_exec_debug_callback(v2);
  }
  else
  {
    v9 = v2->m_torque_sum.z;
    rbg = fabs(v9);
    if ( v4 < rbg )
      phys_exec_debug_callback(v2);
  }
}

/*
==============
rbint::euler_integrate_velocity
==============
*/
void __usercall rbint::euler_integrate_velocity(float a1@<ebp>, rigid_body *const rb, const float delta_t)
{
  double v3; // st7
  double v4; // st7
  long double v5; // st6
  long double v6; // st6
  long double v7; // st6
  long double v8; // st6
  long double v9; // st6
  phys_vec3 *v10; // eax
  double v11; // st6
  double v12; // st5
  phys_vec3 *v13; // eax
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st6
  double v18; // st3
  double v19; // st7
  long double v20; // st7
  double v21; // st7
  long double v22; // st6
  long double v23; // st6
  long double v24; // st6
  long double v25; // st6
  long double v26; // st6
  float v27; // [esp-Ch] [ebp-3Ch]
  float v28; // [esp-8h] [ebp-38h]
  float v29; // [esp-4h] [ebp-34h]
  phys_vec3 a_vel_loc2; // [esp+0h] [ebp-30h]
  phys_vec3 a_mom_loc2; // [esp+10h] [ebp-20h]
  float v32; // [esp+20h] [ebp-10h]
  const float factor; // [esp+24h] [ebp-Ch]
  const float ake_times_two_2; // [esp+28h] [ebp-8h]
  float retaddr; // [esp+30h] [ebp+0h]

  factor = a1;
  ake_times_two_2 = retaddr;
  v3 = rb->m_t_vel.x;
  v4 = 100000.0;
  v32 = fabs(rb->m_t_vel.x);
  if ( v32 > 100000.0
    || (v5 = rb->m_t_vel.y, v32 = fabs(v5), v32 > 100000.0)
    || (v6 = rb->m_t_vel.z, v32 = fabs(v6), v32 > 100000.0) )
  {
    phys_exec_debug_callback(rb);
    v4 = 100000.0;
  }
  v7 = rb->m_a_vel.x;
  v32 = fabs(v7);
  if ( v32 > v4 || (v8 = rb->m_a_vel.y, v32 = fabs(v8), v32 > v4) || (v9 = rb->m_a_vel.z, v32 = fabs(v9), v4 < v32) )
    phys_exec_debug_callback(rb);
  rb->m_last_t_vel.x = rb->m_t_vel.x;
  rb->m_last_t_vel.y = rb->m_t_vel.y;
  rb->m_last_t_vel.z = rb->m_t_vel.z;
  rb->m_last_a_vel.x = rb->m_a_vel.x;
  rb->m_last_a_vel.y = rb->m_a_vel.y;
  rb->m_last_a_vel.z = rb->m_a_vel.z;
  v32 = rb->m_inv_mass;
  a_vel_loc2.y = v32 * rb->m_force_sum.x;
  a_vel_loc2.z = rb->m_force_sum.y * v32;
  a_vel_loc2.w = v32 * rb->m_force_sum.z;
  v27 = a_vel_loc2.y + rb->m_gravity_acc_vec.x;
  v28 = rb->m_gravity_acc_vec.y + a_vel_loc2.z;
  v29 = rb->m_gravity_acc_vec.z + a_vel_loc2.w;
  a_vel_loc2.y = v27 * delta_t;
  a_vel_loc2.z = v28 * delta_t;
  a_vel_loc2.w = delta_t * v29;
  rb->m_t_vel.x = a_vel_loc2.y + rb->m_t_vel.x;
  rb->m_t_vel.y = rb->m_t_vel.y + a_vel_loc2.z;
  rb->m_t_vel.z = a_vel_loc2.w + rb->m_t_vel.z;
  v10 = phys_multiply((phys_vec3 *)((char *)&a_vel_loc2 + 4), &rb->m_node->m_world_inv_inertia, &rb->m_torque_sum);
  v27 = v10->x * delta_t;
  v28 = v10->y * delta_t;
  v29 = v10->z * delta_t;
  rb->m_a_vel.x = rb->m_a_vel.x + v27;
  rb->m_a_vel.y = v28 + rb->m_a_vel.y;
  rb->m_a_vel.z = rb->m_a_vel.z + v29;
  v27 = rb->m_mat.x.y * rb->m_a_vel.y + rb->m_mat.x.x * rb->m_a_vel.x + rb->m_mat.x.z * rb->m_a_vel.z;
  v28 = rb->m_mat.y.y * rb->m_a_vel.y + rb->m_mat.y.x * rb->m_a_vel.x + rb->m_mat.y.z * rb->m_a_vel.z;
  v29 = rb->m_mat.z.y * rb->m_a_vel.y + rb->m_mat.z.x * rb->m_a_vel.x + rb->m_mat.z.z * rb->m_a_vel.z;
  v11 = v27;
  a_vel_loc2.y = v27 / rb->m_inv_inertia.x;
  v12 = v28;
  a_vel_loc2.z = v28 / rb->m_inv_inertia.y;
  a_vel_loc2.w = v29 / rb->m_inv_inertia.z;
  a_mom_loc2.z = a_vel_loc2.z * v28 + a_vel_loc2.y * v27 + a_vel_loc2.w * v29;
  v27 = a_vel_loc2.z * v29 - a_vel_loc2.w * v28;
  v28 = a_vel_loc2.w * v11 - v29 * a_vel_loc2.y;
  v29 = a_vel_loc2.y * v12 - v11 * a_vel_loc2.z;
  a_vel_loc2.y = v27 * rb->m_inv_inertia.x;
  a_vel_loc2.z = v28 * rb->m_inv_inertia.y;
  a_vel_loc2.w = v29 * rb->m_inv_inertia.z;
  v27 = a_vel_loc2.y * delta_t;
  v28 = a_vel_loc2.z * delta_t;
  v29 = delta_t * a_vel_loc2.w;
  v13 = phys_multiply((phys_vec3 *)((char *)&a_vel_loc2 + 4), &rb->m_mat, (phys_vec3 *)&v27);
  rb->m_a_vel.x = rb->m_a_vel.x + v13->x;
  rb->m_a_vel.y = v13->y + rb->m_a_vel.y;
  rb->m_a_vel.z = v13->z + rb->m_a_vel.z;
  v32 = rb->m_a_vel.y * rb->m_a_vel.y + rb->m_a_vel.x * rb->m_a_vel.x + rb->m_a_vel.z * rb->m_a_vel.z;
  a_mom_loc2.w = rb->m_max_avel;
  a_mom_loc2.w = a_mom_loc2.w * a_mom_loc2.w;
  if ( a_mom_loc2.w < (double)v32 )
  {
    if ( v32 <= 9.999999439624929e-11
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\rigid_body_internal.h",
           124,
           "navel_sq > phys_sqr(0.00001f)",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    *(double *)&a_vel_loc2.w = rb->m_max_avel;
    a_mom_loc2.w = sqrt(v32);
    a_mom_loc2.w = *(double *)&a_vel_loc2.w / a_mom_loc2.w;
    v14 = a_mom_loc2.w;
    rb->m_a_vel.x = rb->m_a_vel.x * a_mom_loc2.w;
    rb->m_a_vel.y = v14 * rb->m_a_vel.y;
    rb->m_a_vel.z = v14 * rb->m_a_vel.z;
  }
  v27 = rb->m_mat.x.y * rb->m_a_vel.y + rb->m_mat.x.x * rb->m_a_vel.x + rb->m_mat.x.z * rb->m_a_vel.z;
  v28 = rb->m_mat.y.y * rb->m_a_vel.y + rb->m_mat.y.x * rb->m_a_vel.x + rb->m_mat.y.z * rb->m_a_vel.z;
  v29 = rb->m_mat.z.y * rb->m_a_vel.y + rb->m_a_vel.x * rb->m_mat.z.x + rb->m_mat.z.z * rb->m_a_vel.z;
  a_vel_loc2.y = v27 / rb->m_inv_inertia.x;
  a_vel_loc2.z = v28 / rb->m_inv_inertia.y;
  a_vel_loc2.w = v29 / rb->m_inv_inertia.z;
  a_mom_loc2.w = v29 * a_vel_loc2.w + v28 * a_vel_loc2.z + v27 * a_vel_loc2.y;
  v15 = a_mom_loc2.w;
  if ( a_mom_loc2.z < (double)a_mom_loc2.w && v15 > 0.0000099999997 )
  {
    a_mom_loc2.z = a_mom_loc2.z / v15;
    a_mom_loc2.z = sqrt(a_mom_loc2.z);
    v16 = a_mom_loc2.z;
    rb->m_a_vel.x = rb->m_a_vel.x * a_mom_loc2.z;
    rb->m_a_vel.y = rb->m_a_vel.y * v16;
    rb->m_a_vel.z = v16 * rb->m_a_vel.z;
  }
  a_mom_loc2.z = rb->m_t_drag_coef * delta_t;
  if ( a_mom_loc2.z >= 0.8999999761581421 )
  {
    v32 = 0.89999998;
    v17 = 0.89999998;
  }
  else
  {
    v17 = 0.89999998;
    v32 = a_mom_loc2.z;
  }
  a_mom_loc2.z = 1.0 - v32;
  v18 = a_mom_loc2.z;
  rb->m_t_vel.x = a_mom_loc2.z * rb->m_t_vel.x;
  rb->m_t_vel.y = rb->m_t_vel.y * v18;
  rb->m_t_vel.z = v18 * rb->m_t_vel.z;
  a_mom_loc2.z = delta_t * rb->m_a_drag_coef;
  if ( a_mom_loc2.z < 0.8999999761581421 )
    v17 = a_mom_loc2.z;
  v32 = v17;
  a_mom_loc2.z = 1.0 - v32;
  v19 = a_mom_loc2.z;
  rb->m_a_vel.x = a_mom_loc2.z * rb->m_a_vel.x;
  rb->m_a_vel.y = v19 * rb->m_a_vel.y;
  rb->m_a_vel.z = v19 * rb->m_a_vel.z;
  v20 = rb->m_t_vel.x;
  a_mom_loc2.z = fabs(v20);
  v21 = 100000.0;
  if ( a_mom_loc2.z > 100000.0
    || (v22 = rb->m_t_vel.y, a_mom_loc2.z = fabs(v22), a_mom_loc2.z > 100000.0)
    || (v23 = rb->m_t_vel.z, a_mom_loc2.z = fabs(v23), a_mom_loc2.z > 100000.0) )
  {
    phys_exec_debug_callback(rb);
    v21 = 100000.0;
  }
  v24 = rb->m_a_vel.x;
  a_mom_loc2.z = fabs(v24);
  if ( a_mom_loc2.z > v21 || (v25 = rb->m_a_vel.y, a_mom_loc2.z = fabs(v25), a_mom_loc2.z > v21) )
  {
    phys_exec_debug_callback(rb);
  }
  else
  {
    v26 = rb->m_a_vel.z;
    a_mom_loc2.z = fabs(v26);
    if ( v21 < a_mom_loc2.z )
      phys_exec_debug_callback(rb);
  }
}

/*
==============
rbint::euler_integrate_pos
==============
*/
void __usercall rbint::euler_integrate_pos(int a1@<ebp>, rigid_body *const rb, const float delta_t)
{
  rigid_body *v3; // esi
  long double v4; // st7
  long double v5; // st6
  long double v6; // st6
  int v7; // [esp+18h] [ebp-6Ch]
  phys_mat44 rv; // [esp+24h] [ebp-60h]
  float v9; // [esp+74h] [ebp-10h]
  int v10; // [esp+78h] [ebp-Ch]
  int v11; // [esp+7Ch] [ebp-8h]
  int retaddr; // [esp+84h] [ebp+0h]

  v10 = a1;
  v11 = retaddr;
  v3 = rb;
  rv.w.y = rb->m_t_vel.x * delta_t;
  rv.w.z = rb->m_t_vel.y * delta_t;
  rv.w.w = rb->m_t_vel.z * delta_t;
  v3->m_mat.w.x = v3->m_mat.w.x + rv.w.y;
  v3->m_mat.w.y = rv.w.z + v3->m_mat.w.y;
  v3->m_mat.w.z = rv.w.w + v3->m_mat.w.z;
  make_rotate((phys_mat44 *)&v7, &rb->m_a_vel, delta_t, 1000.0);
  phys_multiply_mat((int)&v10, &v3->m_mat, (phys_mat44 *)&v7, &v3->m_mat);
  ++v3->m_tick;
  if ( rb->m_tick > 5 )
  {
    rb->m_tick = 0;
    orthonormalize(&rb->m_mat);
  }
  v4 = rb->m_mat.w.x;
  v9 = fabs(v4);
  if ( v9 > 100000.0 || (v5 = rb->m_mat.w.y, v9 = fabs(v5), v9 > 100000.0) )
  {
    phys_exec_debug_callback(rb);
  }
  else
  {
    v6 = rb->m_mat.w.z;
    v9 = fabs(v6);
    if ( v9 > 100000.0 )
      phys_exec_debug_callback(rb);
  }
}

/*
==============
rbint::add_vel
==============
*/
void rbint::add_vel(rigid_body *rb, phys_vec3 *t, phys_vec3 *a)
{
  rigid_body *v3; // esi
  long double v4; // st6
  double v5; // st7
  long double v6; // st6
  long double v7; // st6
  long double v8; // st6
  long double v9; // st6
  long double v10; // st6
  double v11; // st7
  float rba; // [esp+Ch] [ebp+8h]
  float rbb; // [esp+Ch] [ebp+8h]
  float rbc; // [esp+Ch] [ebp+8h]
  float rbd; // [esp+Ch] [ebp+8h]
  float rbe; // [esp+Ch] [ebp+8h]
  float rbf; // [esp+Ch] [ebp+8h]
  float rbg; // [esp+Ch] [ebp+8h]
  float rbh; // [esp+Ch] [ebp+8h]

  v3 = rb;
  rb->m_t_vel.x = t->x + rb->m_t_vel.x;
  v3->m_t_vel.y = t->y + v3->m_t_vel.y;
  v3->m_t_vel.z = t->z + v3->m_t_vel.z;
  v3->m_a_vel.x = v3->m_a_vel.x + a->x;
  v3->m_a_vel.y = a->y + v3->m_a_vel.y;
  v3->m_a_vel.z = a->z + v3->m_a_vel.z;
  v4 = rb->m_t_vel.x;
  v5 = 100000.0;
  rba = fabs(v4);
  if ( rba > 100000.0
    || (v6 = v3->m_t_vel.y, rbb = fabs(v6), rbb > 100000.0)
    || (v7 = v3->m_t_vel.z, rbc = fabs(v7), rbc > 100000.0) )
  {
    phys_exec_debug_callback(v3);
    v5 = 100000.0;
  }
  v8 = v3->m_a_vel.x;
  rbd = fabs(v8);
  if ( rbd > v5 || (v9 = v3->m_a_vel.y, rbe = fabs(v9), rbe > v5) || (v10 = v3->m_a_vel.z, rbf = fabs(v10), v5 < rbf) )
    phys_exec_debug_callback(v3);
  rbg = v3->m_a_vel.z * v3->m_a_vel.z + v3->m_a_vel.y * v3->m_a_vel.y + v3->m_a_vel.x * v3->m_a_vel.x;
  v11 = rbg;
  rbh = v3->m_t_vel.z * v3->m_t_vel.z + v3->m_t_vel.y * v3->m_t_vel.y + v3->m_t_vel.x * v3->m_t_vel.x;
  if ( v11 + rbh > 1.0e10 )
    v3->m_flags |= 0x80u;
}

/*
==============
rbint::mul_L
==============
*/
phys_vec3 *__usercall rbint::mul_L@<eax>(int a1@<ebp>, phys_vec3 *result, rigid_body *rb, phys_vec3 *t)
{
  phys_vec3 *v4; // ecx
  rigid_body *v5; // edx
  float v7; // [esp-20h] [ebp-2Ch]
  float v8; // [esp-1Ch] [ebp-28h]
  float v9; // [esp-18h] [ebp-24h]
  float v10; // [esp-10h] [ebp-1Ch]
  float v11; // [esp-Ch] [ebp-18h]
  float v12; // [esp-8h] [ebp-14h]
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v13 = a1;
  v14 = retaddr;
  v4 = t;
  v5 = rb;
  v10 = rb->m_mat.x.y * t->y + v4->x * v5->m_mat.x.x + v5->m_mat.x.z * v4->z;
  v11 = v5->m_mat.y.y * v4->y + v5->m_mat.y.x * v4->x + v5->m_mat.y.z * v4->z;
  v12 = v5->m_mat.z.y * v4->y + v4->x * v5->m_mat.z.x + rb->m_mat.z.z * t->z;
  v7 = v10 / rb->m_inv_inertia.x;
  v8 = v11 / rb->m_inv_inertia.y;
  v9 = v12 / rb->m_inv_inertia.z;
  phys_multiply(result, &rb->m_mat, (phys_vec3 *)&v7);
  return result;
}

