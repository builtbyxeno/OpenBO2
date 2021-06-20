/*
==============
physics_system::validate_member
==============
*/
void __thiscall physics_system::validate_member(physics_system *this, rigid_body *rb)
{
  unsigned int v2; // edx
  rigid_body **v3; // eax

  if ( rb )
  {
    v2 = rb->m_flags;
    if ( v2 & 0x10 )
    {
      if ( rb != (rigid_body *)&this->m_environment_rigid_body )
      {
        if ( _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\physics_system_internal.h",
               73,
               "rb == &m_environment_rigid_body",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
    }
    else
    {
      v3 = &rb[-1].m_partition_node.m_partition_head;
      if ( v2 & 0x20 )
        PMM_VALIDATE(v3, 0x1D0u, 0x10u);
      else
        PMM_VALIDATE(v3, 0x180u, 0x10u);
    }
  }
}

