/*
==============
contact_point_info::get_cpi_allocator
==============
*/
phys_transient_allocator *contact_point_info::get_cpi_allocator()
{
  return &g_physics_system->m_contact_point_buffer_1;
}

/*
==============
rigid_body_constraint_contact::verify_constraint
==============
*/
void __thiscall rigid_body_constraint_contact::verify_constraint(rigid_body_constraint_contact *this, rigid_body *const b1_, rigid_body *const b2_)
{
  rigid_body_constraint_contact *v3; // esi

  v3 = this;
  if ( (this->b1 != b1_ || this->b2 != b2_) && (this->b1 != b2_ || this->b2 != b1_) )
  {
    if ( _tlAssert(
           "source/rbc_def_contact.cpp",
           14,
           "(b1 == b1_ && b2 == b2_) || (b1 == b2_ && b2 == b1_)",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
  physics_system::validate_member(g_physics_system, b1_);
  physics_system::validate_member(g_physics_system, b2_);
  PMM_VALIDATE(&v3[-1].m_avl_key, 0x38u, 4u);
}

/*
==============
rigid_body_constraint_contact::setup_constraint
==============
*/
void __thiscall rigid_body_constraint_contact::setup_constraint(rigid_body_constraint_contact *this, pulse_sum_constraint_solver *psys, const float delta_t)
{
  rigid_body_constraint_contact *v3; // edi
  contact_point_info *v4; // esi

  v3 = this;
  v4 = this->m_list_contact_point_info_buffer_1.m_first;
  for ( this->m_list_contact_point_info_buffer_2.m_first = NULL; v4; v4 = v4->m_next_link )
  {
    contact_point_info::check_surface_properties(v4);
    pulse_sum_constraint_solver::create_pulse_sum_contact(psys, v3->b1, v3->b2, v4, delta_t);
  }
}

/*
==============
rigid_body_constraint_contact::~rigid_body_constraint_contact
==============
*/
void __thiscall rigid_body_constraint_contact::~rigid_body_constraint_contact(rigid_body_constraint_contact *this)
{
  phys_inplace_avl_tree<rigid_body_pair_key,rigid_body_constraint_contact,rigid_body_constraint_contact::avl_tree_accessor>::remove(
    &g_physics_system->m_search_tree_rbc_contact,
    &this->m_avl_key);
}

/*
==============
pulse_sum_constraint_solver::create_pulse_sum_contact
==============
*/
pulse_sum_contact *__thiscall pulse_sum_constraint_solver::create_pulse_sum_contact(pulse_sum_constraint_solver *this, rigid_body *b1, rigid_body *b2, contact_point_info *cpi, const float delta_t)
{
  int v5; // esi
  phys_transient_allocator *v6; // edi
  unsigned int v7; // eax
  pulse_sum_contact *v8; // ebx
  pulse_sum_contact **v10; // eax
  pulse_sum_constraint_solver *v11; // [esp+10h] [ebp-4h]

  v5 = 208 * cpi->m_point_pair_count + 96;
  v11 = this;
  v6 = &this->m_solver_memory_allocator;
  transient_allocator_update_largest_size(v5);
  v7 = (_DWORD)(v6->m_cur + 15) & 0xFFFFFFF0;
  if ( (char *)(v7 + v5) <= v6->m_end )
  {
    v6->m_cur = (char *)(v7 + v5);
    v8 = (pulse_sum_contact *)v7;
    if ( v7 )
      goto LABEL_18;
  }
  phys_transient_allocator::resize(v6);
  v8 = (pulse_sum_contact *)((_DWORD)(v6->m_cur + 15) & 0xFFFFFFF0);
  if ( (char *)v8 + v5 > v6->m_end )
  {
    v8 = NULL;
    goto LABEL_6;
  }
  v6->m_cur = (char *)v8 + v5;
  if ( v8 )
  {
LABEL_18:
    if ( !v11->m_list_pulse_sum_contact.m_last_next_ptr
      && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 230, "m_last_next_ptr", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v8->m_next_link = NULL;
    v10 = v11->m_list_pulse_sum_contact.m_last_next_ptr;
    ++v11->m_list_pulse_sum_contact.m_alloc_count;
    *v10 = v8;
    v11->m_list_pulse_sum_contact.m_last_next_ptr = &v8->m_next_link;
    v8->m_list_pscp = (pulse_sum_contact_point *)&v8[1];
    v8->m_list_pscp_count = cpi->m_point_pair_count;
    pulse_sum_contact::set(v8, b1, b2, cpi, delta_t);
    return v8;
  }
LABEL_6:
  if ( _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_transient_allocator.h",
         79,
         "ptr",
         "transient allocation too large, increase block_size.") )
  {
    __debugbreak();
  }
  if ( v8 )
    goto LABEL_18;
  if ( cpi->m_flags & 8 )
    return v8;
  if ( (pai_create_pulse_sum_contact.m_hits_total_count < dword_10E5950 || !dword_10E5950)
    && dword_10E594C < dword_10E5954 )
  {
    if ( byte_10E5958 )
    {
      PHYS_WARNING(
        "source/rbc_def_contact.cpp",
        44,
        "psc || cpi->get_flag(contact_point_info::FLAG_NO_OVERFLOW_ERROR)",
        SOLVER_MEMORY_ALLOCATOR_ERROR_MSG);
    }
    else if ( _tlAssert(
                "source/rbc_def_contact.cpp",
                44,
                "psc || cpi->get_flag(contact_point_info::FLAG_NO_OVERFLOW_ERROR)",
                SOLVER_MEMORY_ALLOCATOR_ERROR_MSG) )
    {
      __debugbreak();
    }
  }
  _InterlockedExchangeAdd(&pai_create_pulse_sum_contact.m_hits_total_count, 1u);
  _InterlockedExchangeAdd(&dword_10E594C, 1u);
  return 0;
}

