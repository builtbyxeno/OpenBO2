/*
==============
rigid_body::set_max_avel
==============
*/
void __thiscall rigid_body::set_max_avel(rigid_body *this, const float max_avel)
{
  this->m_max_avel = max_avel;
}

/*
==============
rigid_body::add_torque
==============
*/
void __thiscall rigid_body::add_torque(rigid_body *this, phys_vec3 *torque)
{
  __int128 v2; // xmm0
  rigid_body *v3; // esi
  __int128 v4; // xmm0
  __int128 v5; // xmm0

  v2 = LODWORD(torque->x);
  v3 = this;
  v4 = LODWORD(torque->y);
  v5 = LODWORD(torque->z);
  v3->m_torque_sum.x = v3->m_torque_sum.x + torque->x;
  v3->m_torque_sum.y = torque->y + v3->m_torque_sum.y;
  v3->m_torque_sum.z = torque->z + v3->m_torque_sum.z;
  if ( COERCE_FLOAT(LODWORD(this->m_torque_sum.x) & _mask__AbsFloat_) > 100000.0
    || COERCE_FLOAT(LODWORD(this->m_torque_sum.y) & _mask__AbsFloat_) > 100000.0
    || COERCE_FLOAT(LODWORD(this->m_torque_sum.z) & _mask__AbsFloat_) > 100000.0 )
  {
    phys_exec_debug_callback(this);
  }
}

/*
==============
rigid_body::dangerous_set_t_vel
==============
*/
void __thiscall rigid_body::dangerous_set_t_vel(rigid_body *this, phys_vec3 *t_vel)
{
  __int128 v2; // xmm0
  __int128 v3; // xmm0
  __int128 v4; // xmm0

  v2 = LODWORD(t_vel->x);
  v3 = LODWORD(t_vel->y);
  v4 = LODWORD(t_vel->z);
  this->m_t_vel.x = t_vel->x;
  this->m_t_vel.y = t_vel->y;
  this->m_t_vel.z = t_vel->z;
  if ( COERCE_FLOAT(LODWORD(this->m_t_vel.x) & _mask__AbsFloat_) > 100000.0
    || COERCE_FLOAT(LODWORD(this->m_t_vel.y) & _mask__AbsFloat_) > 100000.0
    || COERCE_FLOAT(LODWORD(this->m_t_vel.z) & _mask__AbsFloat_) > 100000.0 )
  {
    phys_exec_debug_callback(this);
  }
}

/*
==============
rigid_body::dangerous_set_a_vel
==============
*/
void __thiscall rigid_body::dangerous_set_a_vel(rigid_body *this, phys_vec3 *a_vel)
{
  __int128 v2; // xmm0
  __int128 v3; // xmm0
  __int128 v4; // xmm0

  v2 = LODWORD(a_vel->x);
  v3 = LODWORD(a_vel->y);
  v4 = LODWORD(a_vel->z);
  this->m_a_vel.x = a_vel->x;
  this->m_a_vel.y = a_vel->y;
  this->m_a_vel.z = a_vel->z;
  if ( COERCE_FLOAT(LODWORD(this->m_a_vel.x) & _mask__AbsFloat_) > 100000.0
    || COERCE_FLOAT(LODWORD(this->m_a_vel.y) & _mask__AbsFloat_) > 100000.0
    || COERCE_FLOAT(LODWORD(this->m_a_vel.z) & _mask__AbsFloat_) > 100000.0 )
  {
    phys_exec_debug_callback(this);
  }
}

/*
==============
rigid_body::swap_last_position
==============
*/
void __thiscall rigid_body::swap_last_position(rigid_body *this)
{
  rigid_body *v1; // esi
  float v2; // eax
  double v3; // st7
  float v4; // ecx
  float v5; // edx
  float v6; // ST14_4
  float v7; // eax
  long double v8; // st6
  double v9; // st7
  float v10; // ST30_4
  long double v11; // st6
  float v12; // ST30_4
  long double v13; // st6
  float v14; // ST30_4
  long double v15; // st6
  float v16; // ST30_4
  long double v17; // st6
  float v18; // ST30_4
  long double v19; // st6
  float v20; // ST30_4

  v1 = this;
  v2 = this->m_last_position.x;
  v3 = this->m_mat.w.x;
  v4 = this->m_last_position.y;
  v5 = v1->m_last_position.z;
  v6 = v2;
  v7 = v1->m_last_position.w;
  v1->m_last_position.x = v3;
  v1->m_last_position.y = v1->m_mat.w.y;
  v1->m_last_position.z = v1->m_mat.w.z;
  v1->m_mat.w.x = v6;
  v1->m_mat.w.y = v4;
  v1->m_mat.w.z = v5;
  v8 = v1->m_last_position.x;
  v9 = 100000.0;
  v10 = fabs(v8);
  if ( v10 > 100000.0
    || (v11 = v1->m_last_position.y, v12 = fabs(v11), v12 > 100000.0)
    || (v13 = v1->m_last_position.z, v14 = fabs(v13), v14 > 100000.0) )
  {
    phys_exec_debug_callback(v1);
    v9 = 100000.0;
  }
  v15 = v1->m_mat.w.x;
  v16 = fabs(v15);
  if ( v16 > v9 || (v17 = v1->m_mat.w.y, v18 = fabs(v17), v18 > v9) )
  {
    phys_exec_debug_callback(v1);
  }
  else
  {
    v19 = v1->m_mat.w.z;
    v20 = fabs(v19);
    if ( v9 < v20 )
      phys_exec_debug_callback(v1);
  }
}

/*
==============
rigid_body::adjust_col_moved_vec
==============
*/
void __thiscall rigid_body::adjust_col_moved_vec(rigid_body *this, const float lambda)
{
  rigid_body *v2; // esi
  float v3; // ST24_4
  float v4; // ST28_4
  float v5; // ST2C_4
  float v6; // ST14_4
  float v7; // ST18_4
  float v8; // ST1C_4
  float v9; // ST40_4
  long double v10; // st6
  double v11; // st7
  float v12; // ST40_4
  long double v13; // st6
  float v14; // ST40_4
  long double v15; // st6
  float v16; // ST40_4
  long double v17; // st6
  float v18; // ST40_4
  long double v19; // st6
  float v20; // ST40_4
  long double v21; // st6
  float v22; // ST40_4

  v2 = this;
  v3 = lambda * this->m_moved_vec.x;
  v4 = lambda * this->m_moved_vec.y;
  v5 = lambda * this->m_moved_vec.z;
  v6 = this->m_mat.w.x + v3;
  v7 = this->m_mat.w.y + v4;
  v8 = this->m_mat.w.z + v5;
  this->m_mat.w.x = v6;
  this->m_mat.w.y = v7;
  this->m_mat.w.z = v8;
  v9 = 1.0 - lambda;
  this->m_moved_vec.x = v9 * this->m_moved_vec.x;
  this->m_moved_vec.y = v9 * this->m_moved_vec.y;
  this->m_moved_vec.z = v9 * this->m_moved_vec.z;
  v10 = this->m_moved_vec.x;
  v11 = 100000.0;
  v12 = fabs(v10);
  if ( v12 > 100000.0
    || (v13 = this->m_moved_vec.y, v14 = fabs(v13), v14 > 100000.0)
    || (v15 = this->m_moved_vec.z, v16 = fabs(v15), v16 > 100000.0) )
  {
    phys_exec_debug_callback(this);
    v11 = 100000.0;
  }
  v17 = v2->m_mat.w.x;
  v18 = fabs(v17);
  if ( v18 > v11 || (v19 = v2->m_mat.w.y, v20 = fabs(v19), v20 > v11) )
  {
    phys_exec_debug_callback(v2);
  }
  else
  {
    v21 = v2->m_mat.w.z;
    v22 = fabs(v21);
    if ( v11 < v22 )
      phys_exec_debug_callback(v2);
  }
}

/*
==============
rigid_body::update_last_position
==============
*/
void __thiscall rigid_body::update_last_position(rigid_body *this)
{
  float v1; // ST20_4
  float v2; // ST04_4
  float v3; // ST08_4
  float v4; // ST0C_4
  long double v5; // st7
  float v6; // ST20_4
  long double v7; // st6
  float v8; // ST20_4
  long double v9; // st6
  float v10; // ST20_4

  v1 = this->m_smallest_lambda;
  v2 = this->m_moved_vec.x * v1;
  v3 = this->m_moved_vec.y * v1;
  v4 = v1 * this->m_moved_vec.z;
  this->m_last_position.x = this->m_last_position.x + v2;
  this->m_last_position.y = v3 + this->m_last_position.y;
  this->m_last_position.z = this->m_last_position.z + v4;
  v5 = this->m_last_position.x;
  v6 = fabs(v5);
  if ( v6 > 100000.0 || (v7 = this->m_last_position.y, v8 = fabs(v7), v8 > 100000.0) )
  {
    phys_exec_debug_callback(this);
  }
  else
  {
    v9 = this->m_last_position.z;
    v10 = fabs(v9);
    if ( v10 > 100000.0 )
      phys_exec_debug_callback(this);
  }
}

