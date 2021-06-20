/*
==============
pulse_sum_constraint_solver::create_pulse_sum_normal
==============
*/
pulse_sum_normal *__thiscall pulse_sum_constraint_solver::create_pulse_sum_normal(pulse_sum_constraint_solver *this)
{
  pulse_sum_constraint_solver *v1; // esi
  char *v2; // edi
  _DWORD *v3; // ecx

  v1 = this;
  v2 = phys_transient_allocator::allocate(
         &this->m_solver_memory_allocator,
         160,
         16,
         0,
         SOLVER_MEMORY_ALLOCATOR_ERROR_MSG);
  if ( !v1->m_list_pulse_sum_normal.m_last_next_ptr
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 230, "m_last_next_ptr", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  *(_DWORD *)v2 = 0;
  v3 = v1->m_list_pulse_sum_normal.m_last_next_ptr;
  ++v1->m_list_pulse_sum_normal.m_alloc_count;
  *v3 = v2;
  v1->m_list_pulse_sum_normal.m_last_next_ptr = (pulse_sum_normal **)v2;
  return (pulse_sum_normal *)v2;
}

/*
==============
pulse_sum_constraint_solver::create_point
==============
*/
void __thiscall pulse_sum_constraint_solver::create_point(pulse_sum_constraint_solver *this, rigid_body *const b1, phys_vec3 *b1_r, rigid_body *const b2, phys_vec3 *b2_r, pulse_sum_cache *const ps_cache, const float delta_t, const bool is_spring, const float spring_k, const float damp_k)
{
  pulse_sum_constraint_solver *v10; // esi
  pulse_sum_point *v11; // edi
  pulse_sum_point **v12; // ecx

  v10 = this;
  v11 = (pulse_sum_point *)phys_transient_allocator::allocate(
                             &this->m_solver_memory_allocator,
                             272,
                             16,
                             0,
                             SOLVER_MEMORY_ALLOCATOR_ERROR_MSG);
  if ( !v10->m_list_pulse_sum_point.m_last_next_ptr
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 230, "m_last_next_ptr", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v11->m_next_link = NULL;
  v12 = v10->m_list_pulse_sum_point.m_last_next_ptr;
  ++v10->m_list_pulse_sum_point.m_alloc_count;
  *v12 = v11;
  v10->m_list_pulse_sum_point.m_last_next_ptr = &v11->m_next_link;
  pulse_sum_point::set(v11, b1, b1_r, b2, b2_r, ps_cache, delta_t, is_spring, spring_k, damp_k);
}

/*
==============
pulse_sum_constraint_solver::create_pulse_sum_angular
==============
*/
pulse_sum_angular *__thiscall pulse_sum_constraint_solver::create_pulse_sum_angular(pulse_sum_constraint_solver *this, rigid_body *const b1, phys_vec3 *b1_r, rigid_body *const b2, phys_vec3 *b2_r, phys_vec3 *ud, pulse_sum_cache *const ps_cache)
{
  pulse_sum_constraint_solver *v7; // esi
  pulse_sum_angular *v8; // edi
  pulse_sum_angular **v9; // ecx

  v7 = this;
  v8 = (pulse_sum_angular *)phys_transient_allocator::allocate(
                              &this->m_solver_memory_allocator,
                              144,
                              16,
                              0,
                              SOLVER_MEMORY_ALLOCATOR_ERROR_MSG);
  if ( !v7->m_list_pulse_sum_angular.m_last_next_ptr
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 230, "m_last_next_ptr", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v8->m_next_link = NULL;
  v9 = v7->m_list_pulse_sum_angular.m_last_next_ptr;
  ++v7->m_list_pulse_sum_angular.m_alloc_count;
  *v9 = v8;
  v7->m_list_pulse_sum_angular.m_last_next_ptr = &v8->m_next_link;
  pulse_sum_angular::set(v8, b1, b1_r, b2, b2_r, ud, ps_cache);
  return v8;
}

/*
==============
pulse_sum_constraint_solver::create_hinge
==============
*/
void __thiscall pulse_sum_constraint_solver::create_hinge(pulse_sum_constraint_solver *this, rigid_body *const b1, phys_vec3 *b1_axis, rigid_body *const b2, phys_vec3 *b2_axis, phys_vec3 *a1, phys_vec3 *a2, pulse_sum_cache *const ps_cache, const float delta_t)
{
  pulse_sum_cache *v9; // ebx
  pulse_sum_constraint_solver *v10; // edi
  pulse_sum_angular *v11; // esi
  double v12; // st7
  pulse_sum_angular *v13; // esi
  double v14; // st7
  float b2_axisa; // [esp+20h] [ebp+14h]
  float ps_cachea; // [esp+2Ch] [ebp+20h]

  v9 = ps_cache;
  v10 = this;
  v11 = pulse_sum_constraint_solver::create_pulse_sum_angular(this, b1, b1_axis, b2, b2_axis, a1, ps_cache);
  v11->m_pulse_sum_min = -10000000.0;
  v11->m_pulse_sum_max = 10000000.0;
  v12 = 0.016666668;
  if ( delta_t > 0.016666668 )
    v12 = delta_t;
  ps_cachea = v12;
  v11->m_big_dirt = pulse_sum_angular::get_pos(v11) * (-0.5 / ps_cachea);
  v11->m_right_side = 0.0;
  v11->m_cfm = 0.0;
  v13 = pulse_sum_constraint_solver::create_pulse_sum_angular(v10, b1, b1_axis, b2, b2_axis, a2, v9 + 1);
  v13->m_pulse_sum_min = -10000000.0;
  v13->m_pulse_sum_max = 10000000.0;
  v14 = 0.016666668;
  if ( delta_t > 0.016666668 )
    v14 = delta_t;
  b2_axisa = v14;
  v13->m_big_dirt = pulse_sum_angular::get_pos(v13) * (-0.5 / b2_axisa);
  v13->m_right_side = 0.0;
  v13->m_cfm = 0.0;
}

/*
==============
pulse_sum_constraint_solver::create_pulse_sum_wheel_fwd
==============
*/
pulse_sum_normal *__thiscall pulse_sum_constraint_solver::create_pulse_sum_wheel_fwd(pulse_sum_constraint_solver *this, pulse_sum_wheel *psw)
{
  pulse_sum_constraint_solver *v2; // esi
  pulse_sum_normal *result; // eax

  v2 = this;
  if ( !psw->m_side
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_constraint_solver.h",
         196,
         "psw->m_side",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  result = (pulse_sum_normal *)phys_transient_allocator::allocate(
                                 &v2->m_solver_memory_allocator,
                                 160,
                                 16,
                                 0,
                                 SOLVER_MEMORY_ALLOCATOR_ERROR_MSG);
  psw->m_fwd = result;
  return result;
}

/*
==============
pulse_sum_constraint_solver::create_pulse_sum_wheel
==============
*/
pulse_sum_wheel *__thiscall pulse_sum_constraint_solver::create_pulse_sum_wheel(pulse_sum_constraint_solver *this)
{
  pulse_sum_constraint_solver *v1; // esi
  char *v2; // edi
  _DWORD *v3; // ecx

  v1 = this;
  v2 = phys_transient_allocator::allocate(
         &this->m_solver_memory_allocator,
         192,
         16,
         0,
         SOLVER_MEMORY_ALLOCATOR_ERROR_MSG);
  if ( !v1->m_list_pulse_sum_wheel.m_last_next_ptr
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 230, "m_last_next_ptr", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  *(_DWORD *)v2 = 0;
  v3 = v1->m_list_pulse_sum_wheel.m_last_next_ptr;
  ++v1->m_list_pulse_sum_wheel.m_alloc_count;
  *v3 = v2;
  v1->m_list_pulse_sum_wheel.m_last_next_ptr = (pulse_sum_wheel **)v2;
  return (pulse_sum_wheel *)v2;
}

