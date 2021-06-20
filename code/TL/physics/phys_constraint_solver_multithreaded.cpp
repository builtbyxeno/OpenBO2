/*
==============
constraint_solver_process
==============
*/
void constraint_solver_process(phys_transient_allocator *transient_buffer, physics_system *psys, const float outside_delta_t)
{
  rigid_body **v3; // ebx
  int v4; // edi
  char *v5; // eax
  int v6; // edx
  int v7; // eax

  v3 = psys->m_list_island;
  v4 = psys->m_list_island_count;
  if ( v4 > 0 )
  {
    g_list_island_cur = 0;
    v5 = phys_transient_allocator::allocate(transient_buffer, 32, 4, 0, "phys_transient_allocator out of memory.");
    *(_DWORD *)v5 = v3;
    *((_DWORD *)v5 + 1) = v4;
    *((_DWORD *)v5 + 2) = &g_list_island_cur;
    *((_DWORD *)v5 + 5) = psys->m_max_vel_iters;
    v6 = psys->m_max_vel_pos_iters;
    *((const float *)v5 + 7) = outside_delta_t;
    *((_DWORD *)v5 + 6) = v6;
    phys_task_manager_process(&phys_jq_constraint_solverModule, v5, v4);
  }
  LOBYTE(v7) = phys_task_manager_needs_flush();
  if ( v7 )
    phys_task_manager_flush();
}

/*
==============
phys_jq_constraint_solver_batch_function
==============
*/
int phys_jq_constraint_solver_batch_function(jqBatch *pBatch)
{
  void *v1; // esi
  int v2; // eax
  int v3; // ecx
  volatile signed __int32 *v4; // ecx
  signed __int32 i; // eax
  pulse_sum_constraint_solver v7; // [esp+Ch] [ebp-94h]
  int v8; // [esp+9Ch] [ebp-4h]

  v1 = pBatch->Input;
  v7.m_list_pulse_sum_node.m_last_next_ptr = &v7.m_list_pulse_sum_node.m_first;
  v7.m_list_pulse_sum_normal.m_last_next_ptr = &v7.m_list_pulse_sum_normal.m_first;
  v7.m_list_pulse_sum_point.m_last_next_ptr = &v7.m_list_pulse_sum_point.m_first;
  v7.m_solver_memory_allocator.m_first_block = NULL;
  v7.m_solver_memory_allocator.m_cur = NULL;
  v7.m_solver_memory_allocator.m_end = NULL;
  v7.m_solver_memory_allocator.m_total_memory_allocated = 0;
  v7.m_solver_memory_allocator.m_mutex.m_count = 1;
  v7.m_solver_memory_allocator.m_slot_pool = NULL;
  v7.m_list_pulse_sum_node.m_first = NULL;
  v7.m_list_pulse_sum_node.m_alloc_count = 0;
  v7.m_list_pulse_sum_normal.m_first = NULL;
  v7.m_list_pulse_sum_normal.m_alloc_count = 0;
  v7.m_list_pulse_sum_point.m_first = NULL;
  v7.m_list_pulse_sum_point.m_alloc_count = 0;
  v7.m_list_pulse_sum_angular.m_first = NULL;
  v7.m_list_pulse_sum_angular.m_last_next_ptr = &v7.m_list_pulse_sum_angular.m_first;
  v7.m_list_pulse_sum_angular.m_alloc_count = 0;
  v7.m_list_pulse_sum_wheel.m_first = NULL;
  v7.m_list_pulse_sum_wheel.m_last_next_ptr = &v7.m_list_pulse_sum_wheel.m_first;
  v7.m_list_pulse_sum_wheel.m_alloc_count = 0;
  v7.m_list_pulse_sum_contact.m_first = NULL;
  v7.m_list_pulse_sum_contact.m_last_next_ptr = &v7.m_list_pulse_sum_contact.m_first;
  v7.m_list_pulse_sum_contact.m_alloc_count = 0;
  v2 = *((_DWORD *)v1 + 6);
  v3 = *((_DWORD *)v1 + 5);
  v7.m_outside_delta_t = *((float *)v1 + 7);
  v7.m_psys_max_vel_pos_iters = v2;
  v7.m_psys_max_vel_iters = v3;
  v7.m_memory_high_water = 0;
  v4 = (volatile signed __int32 *)*((_DWORD *)v1 + 2);
  v8 = 0;
  for ( i = _InterlockedExchangeAdd(v4, 1u);
        i < *((_DWORD *)v1 + 1);
        i = _InterlockedExchangeAdd(*((volatile signed __int32 **)v1 + 2), 1u) )
  {
    pulse_sum_constraint_solver::execute_constraint_solver(&v7, *(rigid_body *const *)(*(_DWORD *)v1 + 4 * i));
  }
  v8 = -1;
  if ( v7.m_solver_memory_allocator.m_first_block
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_transient_allocator.h",
         69,
         "m_first_block == NULL",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  return 0;
}

