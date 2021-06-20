/*
==============
rigid_body::add_force
==============
*/
void __thiscall rigid_body::add_force(rigid_body *this, phys_vec3 *force)
{
  __int128 v2; // xmm0
  rigid_body *v3; // esi
  __int128 v4; // xmm0
  __int128 v5; // xmm0

  v2 = LODWORD(force->x);
  v3 = this;
  v4 = LODWORD(force->y);
  v5 = LODWORD(force->z);
  v3->m_force_sum.x = v3->m_force_sum.x + force->x;
  v3->m_force_sum.y = force->y + v3->m_force_sum.y;
  v3->m_force_sum.z = force->z + v3->m_force_sum.z;
  if ( COERCE_FLOAT(LODWORD(this->m_force_sum.x) & _mask__AbsFloat_) > 100000.0
    || COERCE_FLOAT(LODWORD(this->m_force_sum.y) & _mask__AbsFloat_) > 100000.0
    || COERCE_FLOAT(LODWORD(this->m_force_sum.z) & _mask__AbsFloat_) > 100000.0 )
  {
    phys_exec_debug_callback(this);
  }
}

/*
==============
rigid_body::set_inertia
==============
*/
void __thiscall rigid_body::set_inertia(rigid_body *this, phys_vec3 *inertia)
{
  double v2; // st6
  rigid_body *v3; // edi
  double v4; // st7
  double v5; // st7
  float v6; // ST20_4
  float v7; // ST24_4
  float v8; // ST28_4

  v2 = inertia->x;
  v3 = this;
  v4 = inertia->y;
  v5 = inertia->z;
  if ( v2 <= 0.000001 && _tlAssert("source/rigid_body.cpp", 8, "inertia.GetX() > 0.000001f", (const char *)&pBlock) )
    __debugbreak();
  if ( inertia->y <= 0.000001
    && _tlAssert("source/rigid_body.cpp", 9, "inertia.GetY() > 0.000001f", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( inertia->z <= 0.000001
    && _tlAssert("source/rigid_body.cpp", 10, "inertia.GetZ() > 0.000001f", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v6 = 1.0 / inertia->x;
  v7 = 1.0 / inertia->y;
  v8 = 1.0 / inertia->z;
  v3->m_inv_inertia.x = v6;
  v3->m_inv_inertia.y = v7;
  v3->m_inv_inertia.z = v8;
}

/*
==============
rigid_body::set_mass
==============
*/
void __thiscall rigid_body::set_mass(rigid_body *this, const float mass)
{
  rigid_body *v2; // esi

  v2 = this;
  if ( mass <= 0.000001 && _tlAssert("source/rigid_body.cpp", 17, "mass > 0.000001f", (const char *)&pBlock) )
    __debugbreak();
  v2->m_inv_mass = 1.0 / mass;
}

/*
==============
user_rigid_body::setPosition
==============
*/
void __thiscall user_rigid_body::setPosition(user_rigid_body *this, phys_mat44 *const dictator)
{
  float *v2; // eax

  v2 = &this->m_dictator_mat.x.x;
  *v2 = dictator->x.x;
  this->m_dictator = &this->m_dictator_mat;
  v2[1] = dictator->x.y;
  v2[2] = dictator->x.z;
  v2[4] = dictator->y.x;
  v2[5] = dictator->y.y;
  v2[6] = dictator->y.z;
  v2[8] = dictator->z.x;
  v2[9] = dictator->z.y;
  v2[10] = dictator->z.z;
  v2[12] = dictator->w.x;
  v2[13] = dictator->w.y;
  v2[14] = dictator->w.z;
}

/*
==============
rigid_body::set
==============
*/
void __thiscall rigid_body::set(rigid_body *this, const float mass, phys_vec3 *inertia, phys_mat44 *mat, phys_vec3 *t_vel, phys_vec3 *a_vel, const int stable_min_contact_count)
{
  rigid_body *v7; // esi
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  float *v17; // edi
  long double v18; // st6
  double v19; // st7
  long double v20; // st6
  long double v21; // st6
  long double v22; // st6
  long double v23; // st6
  long double v24; // st6
  double v25; // st6
  long double v26; // st5
  long double v27; // st5
  long double v28; // st5
  long double v29; // st5
  long double v30; // st5
  long double v31; // st5
  long double v32; // st5
  long double v33; // st5
  long double v34; // st5
  long double v35; // st5
  long double v36; // st5
  long double v37; // st5
  bool v38; // c0
  bool v39; // c3
  double v40; // st7
  float massa; // [esp+14h] [ebp+8h]
  float massb; // [esp+14h] [ebp+8h]
  float massc; // [esp+14h] [ebp+8h]
  float massd; // [esp+14h] [ebp+8h]
  float masse; // [esp+14h] [ebp+8h]
  float massf; // [esp+14h] [ebp+8h]
  float massg; // [esp+14h] [ebp+8h]
  float massh; // [esp+14h] [ebp+8h]
  float massi; // [esp+14h] [ebp+8h]
  float massj; // [esp+14h] [ebp+8h]
  float massk; // [esp+14h] [ebp+8h]
  float massl; // [esp+14h] [ebp+8h]
  float massm; // [esp+14h] [ebp+8h]
  float massn; // [esp+14h] [ebp+8h]
  float masso; // [esp+14h] [ebp+8h]
  float massp; // [esp+14h] [ebp+8h]
  float massq; // [esp+14h] [ebp+8h]
  float massr; // [esp+14h] [ebp+8h]

  v7 = this;
  v8 = inertia->x;
  v9 = inertia->y;
  v10 = inertia->z;
  v11 = t_vel->x;
  v12 = t_vel->y;
  v13 = t_vel->z;
  v14 = a_vel->x;
  v15 = a_vel->y;
  v16 = a_vel->z;
  rigid_body::set_mass(this, mass);
  rigid_body::set_inertia(v7, inertia);
  v17 = &v7->m_mat.x.x;
  *v17 = mat->x.x;
  v17[1] = mat->x.y;
  v17[2] = mat->x.z;
  v17[4] = mat->y.x;
  v17[5] = mat->y.y;
  v17[6] = mat->y.z;
  v17[8] = mat->z.x;
  v17[9] = mat->z.y;
  v17[10] = mat->z.z;
  v17[12] = mat->w.x;
  v17[13] = mat->w.y;
  v17[14] = mat->w.z;
  v18 = v7->m_mat.w.x;
  v19 = 100000.0;
  massa = fabs(v18);
  if ( massa > 100000.0
    || (v20 = v7->m_mat.w.y, massb = fabs(v20), massb > 100000.0)
    || (v21 = v7->m_mat.w.z, massc = fabs(v21), massc > 100000.0) )
  {
    phys_exec_debug_callback(v7);
    v19 = 100000.0;
  }
  v7->m_last_position.x = v7->m_mat.w.x;
  v7->m_last_position.y = v7->m_mat.w.y;
  v7->m_last_position.z = v7->m_mat.w.z;
  v22 = v7->m_last_position.x;
  massd = fabs(v22);
  if ( massd > v19
    || (v23 = v7->m_last_position.y, masse = fabs(v23), masse > v19)
    || (v24 = v7->m_last_position.z, massf = fabs(v24), massf > v19) )
  {
    phys_exec_debug_callback(v7);
    v19 = 100000.0;
  }
  v7->m_moved_vec.x = PHYS_ZERO_VEC_89.x;
  v7->m_moved_vec.y = PHYS_ZERO_VEC_89.y;
  v7->m_moved_vec.z = PHYS_ZERO_VEC_89.z;
  v25 = 0.0;
  v7->m_smallest_lambda = 0.0;
  v7->m_t_vel.x = t_vel->x;
  v7->m_t_vel.y = t_vel->y;
  v7->m_t_vel.z = t_vel->z;
  v7->m_a_vel.x = a_vel->x;
  v7->m_a_vel.y = a_vel->y;
  v7->m_a_vel.z = a_vel->z;
  v26 = v7->m_t_vel.x;
  massg = fabs(v26);
  if ( massg > v19
    || (v27 = v7->m_t_vel.y, massh = fabs(v27), massh > v19)
    || (v28 = v7->m_t_vel.z, massi = fabs(v28), massi > v19) )
  {
    phys_exec_debug_callback(v7);
    v19 = 100000.0;
    v25 = 0.0;
  }
  v29 = v7->m_a_vel.x;
  massj = fabs(v29);
  if ( massj > v19
    || (v30 = v7->m_a_vel.y, massk = fabs(v30), massk > v19)
    || (v31 = v7->m_a_vel.z, massl = fabs(v31), massl > v19) )
  {
    phys_exec_debug_callback(v7);
    v19 = 100000.0;
    v25 = 0.0;
  }
  v7->m_stable_min_contact_count = stable_min_contact_count;
  v7->m_force_sum.x = PHYS_ZERO_VEC_89.x;
  v7->m_force_sum.y = PHYS_ZERO_VEC_89.y;
  v7->m_force_sum.z = PHYS_ZERO_VEC_89.z;
  v7->m_torque_sum.x = PHYS_ZERO_VEC_89.x;
  v7->m_torque_sum.y = PHYS_ZERO_VEC_89.y;
  v7->m_torque_sum.z = PHYS_ZERO_VEC_89.z;
  v7->m_last_t_vel.x = v7->m_t_vel.x;
  v7->m_last_t_vel.y = v7->m_t_vel.y;
  v7->m_last_t_vel.z = v7->m_t_vel.z;
  v7->m_last_a_vel.x = v7->m_a_vel.x;
  v7->m_last_a_vel.y = v7->m_a_vel.y;
  v7->m_last_a_vel.z = v7->m_a_vel.z;
  v32 = v7->m_last_t_vel.x;
  massm = fabs(v32);
  if ( massm > v19
    || (v33 = v7->m_last_t_vel.y, massn = fabs(v33), massn > v19)
    || (v34 = v7->m_last_t_vel.z, masso = fabs(v34), masso > v19) )
  {
    phys_exec_debug_callback(v7);
    v19 = 100000.0;
    v25 = 0.0;
  }
  v35 = v7->m_last_a_vel.x;
  massp = fabs(v35);
  if ( massp > v19
    || (v36 = v7->m_last_a_vel.y, massq = fabs(v36), massq > v19)
    || (v37 = v7->m_last_a_vel.z, massr = fabs(v37), v38 = massr < v19, v39 = massr == v19, v40 = v25, !v38 && !v39) )
  {
    phys_exec_debug_callback(v7);
    v40 = 0.0;
  }
  v7->m_gravity_acc_vec.x = v40;
  v7->m_gravity_acc_vec.y = -9.8000002;
  v7->m_gravity_acc_vec.z = v40;
  v7->m_flags = 0;
  v7->m_tick = 0;
  v7->m_max_delta_t = 0.033898305;
  v7->m_userdata = NULL;
  v7->m_max_avel = 1000.0;
  v7->m_largest_vel_sq = 1000.0;
  v7->m_stable_energy_time = v40;
  v7->m_t_drag_coef = v40;
  v7->m_a_drag_coef = v40;
  if ( g_physics_system->m_flags & 1 )
    rbint::collision_prolog(v7, g_physics_system->m_outside_sub_delta_t);
  PHYS_ASSERT_ORTHONORMAL(&v7->m_mat);
}

/*
==============
rigid_body::add_force
==============
*/
void __thiscall rigid_body::add_force(rigid_body *this, phys_vec3 *force, phys_vec3 *point, const float torque_mult)
{
  phys_vec3 *v4; // edi
  double v5; // st7
  rigid_body *v6; // esi
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  float v12; // ST30_4
  float v13; // ST34_4
  float v14; // ST38_4
  float v15; // ST20_4
  float v16; // ST24_4
  float v17; // ST28_4
  float v18; // ST30_4
  float v19; // ST34_4
  float v20; // ST38_4
  long double v21; // st6
  double v22; // st7
  float v23; // ST4C_4
  long double v24; // st6
  float v25; // ST4C_4
  long double v26; // st6
  float v27; // ST4C_4
  long double v28; // st6
  float v29; // ST4C_4
  long double v30; // st6
  float v31; // ST4C_4
  long double v32; // st6
  float v33; // ST4C_4

  v4 = force;
  v5 = force->x;
  v6 = this;
  v7 = force->y;
  v8 = force->z;
  v9 = point->x;
  v10 = point->y;
  v11 = point->z;
  v6->m_force_sum.x = v6->m_force_sum.x + force->x;
  v6->m_force_sum.y = v6->m_force_sum.y + force->y;
  v6->m_force_sum.z = force->z + v6->m_force_sum.z;
  v12 = point->x - this->m_mat.w.x;
  v13 = point->y - this->m_mat.w.y;
  v14 = point->z - this->m_mat.w.z;
  v15 = v4->z * v13 - v4->y * v14;
  v16 = v14 * v4->x - v4->z * v12;
  v17 = v12 * v4->y - v13 * v4->x;
  v18 = v15 * torque_mult;
  v19 = v16 * torque_mult;
  v20 = torque_mult * v17;
  v6->m_torque_sum.x = v6->m_torque_sum.x + v18;
  v6->m_torque_sum.y = v6->m_torque_sum.y + v19;
  v6->m_torque_sum.z = v6->m_torque_sum.z + v20;
  v21 = this->m_force_sum.x;
  v22 = 100000.0;
  v23 = fabs(v21);
  if ( v23 > 100000.0
    || (v24 = this->m_force_sum.y, v25 = fabs(v24), v25 > 100000.0)
    || (v26 = this->m_force_sum.z, v27 = fabs(v26), v27 > 100000.0) )
  {
    phys_exec_debug_callback(this);
    v22 = 100000.0;
  }
  v28 = v6->m_torque_sum.x;
  v29 = fabs(v28);
  if ( v29 > v22 || (v30 = v6->m_torque_sum.y, v31 = fabs(v30), v31 > v22) )
  {
    phys_exec_debug_callback(v6);
  }
  else
  {
    v32 = v6->m_torque_sum.z;
    v33 = fabs(v32);
    if ( v22 < v33 )
      phys_exec_debug_callback(v6);
  }
}

/*
==============
user_rigid_body::set
==============
*/
void __thiscall user_rigid_body::set(user_rigid_body *this, phys_mat44 *const dictator)
{
  phys_mat44 *v2; // eax
  user_rigid_body *v3; // esi
  long double v4; // st6
  double v5; // st7
  long double v6; // st6
  long double v7; // st6
  long double v8; // st6
  long double v9; // st6
  long double v10; // st6
  float dictatora; // [esp+10h] [ebp+8h]
  float dictatorb; // [esp+10h] [ebp+8h]
  float dictatorc; // [esp+10h] [ebp+8h]
  float dictatord; // [esp+10h] [ebp+8h]
  float dictatore; // [esp+10h] [ebp+8h]
  float dictatorf; // [esp+10h] [ebp+8h]

  v2 = dictator;
  v3 = this;
  if ( dictator )
  {
    this->m_mat.x.x = dictator->x.x;
    this->m_mat.x.y = dictator->x.y;
    this->m_mat.x.z = dictator->x.z;
    this->m_mat.y.x = dictator->y.x;
    this->m_mat.y.y = dictator->y.y;
    this->m_mat.y.z = dictator->y.z;
    this->m_mat.z.x = dictator->z.x;
    this->m_mat.z.y = dictator->z.y;
    this->m_mat.z.z = dictator->z.z;
    this->m_mat.w.x = dictator->w.x;
    this->m_mat.w.y = dictator->w.y;
    this->m_mat.w.z = dictator->w.z;
  }
  else
  {
    v2 = &this->m_mat;
  }
  this->m_dictator = v2;
  v4 = this->m_mat.w.x;
  v5 = 100000.0;
  dictatora = fabs(v4);
  if ( dictatora > 100000.0
    || (v6 = this->m_mat.w.y, dictatorb = fabs(v6), dictatorb > 100000.0)
    || (v7 = this->m_mat.w.z, dictatorc = fabs(v7), dictatorc > 100000.0) )
  {
    phys_exec_debug_callback(this);
    v5 = 100000.0;
  }
  v3->m_last_position.x = v3->m_mat.w.x;
  v3->m_last_position.y = v3->m_mat.w.y;
  v3->m_last_position.z = v3->m_mat.w.z;
  v8 = v3->m_last_position.x;
  dictatord = fabs(v8);
  if ( dictatord > v5
    || (v9 = v3->m_last_position.y, dictatore = fabs(v9), dictatore > v5)
    || (v10 = v3->m_last_position.z, dictatorf = fabs(v10), v5 < dictatorf) )
  {
    phys_exec_debug_callback(v3);
  }
  v3->m_moved_vec.x = PHYS_ZERO_VEC_89.x;
  v3->m_moved_vec.y = PHYS_ZERO_VEC_89.y;
  v3->m_moved_vec.z = PHYS_ZERO_VEC_89.z;
  v3->m_flags = 0;
  v3->m_smallest_lambda = 0.0;
  v3->m_inv_mass = 0.0;
  v3->m_inv_inertia.x = PHYS_ZERO_VEC_89.x;
  v3->m_inv_inertia.y = PHYS_ZERO_VEC_89.y;
  v3->m_inv_inertia.z = PHYS_ZERO_VEC_89.z;
  v3->m_t_vel.x = PHYS_ZERO_VEC_89.x;
  v3->m_t_vel.y = PHYS_ZERO_VEC_89.y;
  v3->m_t_vel.z = PHYS_ZERO_VEC_89.z;
  v3->m_a_vel.x = PHYS_ZERO_VEC_89.x;
  v3->m_a_vel.y = PHYS_ZERO_VEC_89.y;
  v3->m_a_vel.z = PHYS_ZERO_VEC_89.z;
  v3->m_last_t_vel.x = PHYS_ZERO_VEC_89.x;
  v3->m_last_t_vel.y = PHYS_ZERO_VEC_89.y;
  v3->m_last_t_vel.z = PHYS_ZERO_VEC_89.z;
  v3->m_last_a_vel.x = PHYS_ZERO_VEC_89.x;
  v3->m_last_a_vel.y = PHYS_ZERO_VEC_89.y;
  v3->m_last_a_vel.z = PHYS_ZERO_VEC_89.z;
  v3->m_gravity_acc_vec.x = PHYS_ZERO_VEC_89.x;
  v3->m_gravity_acc_vec.y = PHYS_ZERO_VEC_89.y;
  v3->m_gravity_acc_vec.z = PHYS_ZERO_VEC_89.z;
  v3->m_flags |= 0x20u;
  v3->m_max_delta_t = 0.033898305;
  v3->m_node = NULL;
  v3->m_userdata = NULL;
  if ( g_physics_system->m_flags & 1 )
    rbint::collision_prolog(v3, g_physics_system->m_outside_sub_delta_t);
}

/*
==============
environment_rigid_body::set
==============
*/
void __thiscall environment_rigid_body::set(environment_rigid_body *this)
{
  environment_rigid_body *v1; // esi
  long double v2; // st7
  float v3; // ST08_4
  long double v4; // st6
  float v5; // ST08_4
  long double v6; // st6
  float v7; // ST08_4

  v1 = this;
  this->m_inv_mass = 0.0;
  this->m_flags = 0;
  this->m_inv_inertia.x = PHYS_ZERO_VEC_89.x;
  this->m_inv_inertia.y = PHYS_ZERO_VEC_89.y;
  this->m_inv_inertia.z = PHYS_ZERO_VEC_89.z;
  SetIdentity(&this->m_mat);
  v1->m_last_position.x = v1->m_mat.w.x;
  v1->m_last_position.y = v1->m_mat.w.y;
  v1->m_last_position.z = v1->m_mat.w.z;
  v2 = v1->m_last_position.x;
  v3 = fabs(v2);
  if ( v3 > 100000.0
    || (v4 = v1->m_last_position.y, v5 = fabs(v4), v5 > 100000.0)
    || (v6 = v1->m_last_position.z, v7 = fabs(v6), v7 > 100000.0) )
  {
    phys_exec_debug_callback(v1);
  }
  v1->m_moved_vec.x = PHYS_ZERO_VEC_89.x;
  v1->m_moved_vec.y = PHYS_ZERO_VEC_89.y;
  v1->m_moved_vec.z = PHYS_ZERO_VEC_89.z;
  v1->m_smallest_lambda = 0.0;
  v1->m_t_vel.x = PHYS_ZERO_VEC_89.x;
  v1->m_t_vel.y = PHYS_ZERO_VEC_89.y;
  v1->m_t_vel.z = PHYS_ZERO_VEC_89.z;
  v1->m_a_vel.x = PHYS_ZERO_VEC_89.x;
  v1->m_a_vel.y = PHYS_ZERO_VEC_89.y;
  v1->m_a_vel.z = PHYS_ZERO_VEC_89.z;
  v1->m_last_t_vel.x = PHYS_ZERO_VEC_89.x;
  v1->m_last_t_vel.y = PHYS_ZERO_VEC_89.y;
  v1->m_last_t_vel.z = PHYS_ZERO_VEC_89.z;
  v1->m_last_a_vel.x = PHYS_ZERO_VEC_89.x;
  v1->m_last_a_vel.y = PHYS_ZERO_VEC_89.y;
  v1->m_last_a_vel.z = PHYS_ZERO_VEC_89.z;
  v1->m_gravity_acc_vec.x = PHYS_ZERO_VEC_89.x;
  v1->m_gravity_acc_vec.y = PHYS_ZERO_VEC_89.y;
  v1->m_gravity_acc_vec.z = PHYS_ZERO_VEC_89.z;
  v1->m_flags |= 0x10u;
  v1->m_max_delta_t = 0.033898305;
  v1->m_node = NULL;
  v1->m_userdata = NULL;
}

