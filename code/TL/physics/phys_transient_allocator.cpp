/*
==============
phys_transient_allocator::reset
==============
*/
void __thiscall phys_transient_allocator::reset(phys_transient_allocator *this)
{
  phys_transient_allocator *v1; // edi
  phys_transient_allocator::block_header *v2; // eax
  void *v3; // ebx
  phys_transient_allocator::block_header *v4; // esi

  v1 = this;
  v2 = this->m_first_block;
  v3 = this->m_slot_pool;
  if ( this->m_first_block )
  {
    do
    {
      v4 = v2->m_next_block;
      PSP_FREE(v3, v2);
      v2 = v4;
    }
    while ( v4 );
  }
  v1->m_first_block = NULL;
  v1->m_cur = NULL;
  v1->m_end = NULL;
  v1->m_total_memory_allocated = 0;
}

/*
==============
phys_transient_allocator::reset_to_state
==============
*/
void __thiscall phys_transient_allocator::reset_to_state(phys_transient_allocator *this, phys_transient_allocator::allocator_state *as)
{
  phys_transient_allocator *v2; // ebx
  phys_transient_allocator::block_header *v3; // eax
  phys_transient_allocator::block_header *v4; // esi
  void *slot_pool; // [esp+8h] [ebp-4h]

  v2 = this;
  slot_pool = this->m_slot_pool;
  v3 = this->m_first_block;
  if ( this->m_first_block != as->m_first_block )
  {
    do
    {
      v4 = v3->m_next_block;
      PSP_FREE(slot_pool, v3);
      v3 = v4;
    }
    while ( v4 != as->m_first_block );
  }
  *(phys_transient_allocator::allocator_state *)&v2->m_first_block = *as;
}

/*
==============
phys_transient_allocator::resize
==============
*/
void __thiscall phys_transient_allocator::resize(phys_transient_allocator *this)
{
  phys_transient_allocator *v1; // esi
  void *v2; // eax
  _DWORD *v3; // eax

  v1 = this;
  v2 = this->m_slot_pool;
  if ( !v2 )
  {
    v2 = GET_PHYS_SLOT_POOL(0x4000u, 4u);
    v1->m_slot_pool = v2;
  }
  v3 = PSP_ALLOC(v2);
  if ( v3 )
  {
    *v3 = 0x4000;
    v3[1] = 4;
    v3[2] = v1->m_first_block;
    v1->m_first_block = (phys_transient_allocator::block_header *)v3;
    v1->m_total_memory_allocated += 0x4000;
    v1->m_cur = (char *)(v3 + 3);
    v1->m_end = (char *)(v3 + 4096);
  }
}

