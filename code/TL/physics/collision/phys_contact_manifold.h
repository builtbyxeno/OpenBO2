/*
==============
phys_contact_manifold::add_feature_point
==============
*/
void __thiscall phys_contact_manifold::add_feature_point(phys_contact_manifold *this, phys_vec3 *p)
{
  phys_contact_manifold *v2; // esi
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  phys_memory_heap *v8; // ecx
  float *v9; // eax
  const char *v10; // edi
  float v11; // [esp-Ch] [ebp-2Ch]
  float v12; // [esp-8h] [ebp-28h]
  float v13; // [esp-4h] [ebp-24h]
  float *dist_12; // [esp+Ch] [ebp-14h]

  v2 = this;
  v3 = p->y - this->m_feature_hitp.y;
  v4 = p->x - this->m_feature_hitp.x;
  v5 = p->z - this->m_feature_hitp.z;
  v12 = p->y - this->m_feature_hitp.y;
  v11 = p->x - this->m_feature_hitp.x;
  v6 = (float)((float)(this->m_feature_hitn.y * v3) + (float)(this->m_feature_hitn.x * v4))
     + (float)(this->m_feature_hitn.z * v5);
  v13 = p->z - this->m_feature_hitp.z;
  v7 = (float)((float)(v3 * v3) + (float)(v4 * v4)) + (float)(v5 * v5);
  if ( this->m_feature_distance_eps >= v6 || (float)(this->m_sin_feautre_angular_eps_sq * v7) >= (float)(v6 * v6) )
  {
    v8 = this->m_allocator;
    v9 = (float *)v8->m_buffer_cur;
    v10 = g_contact_manifold_error_msg;
    dist_12 = (float *)v8->m_buffer_cur;
    v8->m_buffer_cur = (char *)(v9 + 8);
    if ( (char *)(v9 + 8) > v8->m_buffer_end )
    {
      if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 122, "m_buffer_cur <= m_buffer_end", v10) )
        __debugbreak();
      v9 = dist_12;
    }
    if ( (unsigned __int8)v9 & 0xF )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_contact_manifold.h",
             208,
             "(unsigned int)(mp) % PHYS_ALIGNOF(contact_manifold_mesh_point) == 0",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v9 = dist_12;
    }
    if ( v9 != &v2->m_list_mesh_point[v2->m_list_mesh_point_count].m_p.x )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_contact_manifold.h",
             209,
             "mp == m_list_mesh_point + m_list_mesh_point_count",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v9 = dist_12;
    }
    ++v2->m_list_mesh_point_count;
    *v9 = v11;
    v9[1] = v12;
    v9[2] = v13;
    v9[5] = v7;
    if ( v7 <= 0.000011559999 )
    {
      v9[4] = FLOAT_2_0;
      ++v2->m_close_mesh_point_count;
    }
    else
    {
      v9[4] = 1.0 - (float)((float)(v6 * v6) / v7);
    }
  }
}

/*
==============
phys_v2_to_v3_multiply
==============
*/
phys_vec3 *phys_v2_to_v3_multiply(phys_vec3 *result, phys_mat44 *m, phys_vec2 *v)
{
  float v3; // ST2C_4
  float v4; // ST00_4
  float v5; // ST04_4
  float v6; // ST08_4
  float v7; // ST10_4
  float v8; // ST14_4
  phys_vec3 *v9; // eax
  float v10; // ST18_4

  v3 = v->y;
  v4 = m->y.x * v3;
  v5 = m->y.y * v3;
  v6 = v3 * m->y.z;
  v7 = m->x.x * v->x;
  v8 = m->x.y * v->x;
  v9 = result;
  v10 = v->x * m->x.z;
  result->x = v7 + v4;
  result->y = v8 + v5;
  result->z = v10 + v6;
  return v9;
}

/*
==============
phys_contact_manifold_process::phys_contact_manifold_process
==============
*/
void __thiscall phys_contact_manifold_process::phys_contact_manifold_process(phys_contact_manifold_process *this)
{
  phys_contact_manifold_process *v1; // esi
  phys_memory_heap *v2; // edi
  phys_link_list<contact_point_info> *v3; // eax

  v1 = this;
  this->m_allocator.m_buffer_start = NULL;
  this->m_allocator.m_buffer_end = NULL;
  this->m_allocator.m_buffer_cur = NULL;
  this->m_allocator.m_user_start = NULL;
  v2 = &this->m_allocator;
  v3 = &this->m_list_cpi;
  this->m_cpi_allocator = NULL;
  v3->m_first = NULL;
  v3->m_alloc_count = 0;
  v3->m_last_next_ptr = &v3->m_first;
  this->m_cpi = NULL;
  this->m_rbc_contact_search_tree_root = (rigid_body_constraint_contact *)-1;
  phys_memory_heap::set_buffer(&this->m_allocator, this->m_allocator_memory, 0x4000, 1);
  v1->cman1.m_allocator = v2;
  v1->cman2.m_allocator = v2;
}

/*
==============
phys_contact_manifold::xform_and_translate_mesh_points
==============
*/
void __userpurge phys_contact_manifold::xform_and_translate_mesh_points(phys_contact_manifold *this@<ecx>, int a2@<ebp>, phys_mat44 *xform, phys_vec3 *translation)
{
  phys_contact_manifold *v4; // esi
  phys_vec3 **v5; // eax
  int v6; // ecx
  phys_vec3 *v7; // esi
  phys_vec3 *v8; // eax
  double v9; // st7
  phys_vec3 **v10; // eax
  phys_vec3 *v11; // eax
  int v12; // [esp-40h] [ebp-4Ch]
  float v13; // [esp-30h] [ebp-3Ch]
  float v14; // [esp-2Ch] [ebp-38h]
  float v15; // [esp-28h] [ebp-34h]
  float v16; // [esp-20h] [ebp-2Ch]
  float v17; // [esp-1Ch] [ebp-28h]
  float v18; // [esp-18h] [ebp-24h]
  phys_contact_manifold *v19; // [esp-Ch] [ebp-18h]
  int v20; // [esp-8h] [ebp-14h]
  phys_vec3 **v21; // [esp-4h] [ebp-10h]
  int v22; // [esp+0h] [ebp-Ch]
  contact_manifold_mesh_point **last_mp_i; // [esp+4h] [ebp-8h]
  contact_manifold_mesh_point **retaddr; // [esp+Ch] [ebp+0h]

  v22 = a2;
  last_mp_i = retaddr;
  v4 = this;
  v5 = (phys_vec3 **)this->m_list_sorted_mesh_point;
  v6 = (int)&v5[this->m_list_mesh_point_count];
  v19 = v4;
  v20 = v6;
  v21 = v5;
  if ( v5 != (phys_vec3 **)v6 )
  {
    while ( 1 )
    {
      v7 = *v5;
      v8 = phys_multiply((phys_vec3 *)&v12, xform, *v5);
      v16 = v8->x + xform->w.x;
      v17 = v8->y + xform->w.y;
      v18 = v8->z + xform->w.z;
      v13 = translation->x + v16;
      v14 = translation->y + v17;
      v9 = translation->z + v18;
      ++v21;
      v10 = v21;
      v15 = v9;
      v7->x = v13;
      v7->y = v14;
      v7->z = v15;
      if ( v10 == (phys_vec3 **)v20 )
        break;
      v5 = v21;
    }
    v4 = v19;
  }
  v11 = phys_multiply((phys_vec3 *)&v12, xform, &v4->m_feature_normal);
  v4->m_feature_normal.x = v11->x;
  v4->m_feature_normal.y = v11->y;
  v4->m_feature_normal.z = v11->z;
}

/*
==============
phys_contact_manifold::get_STD_COMP_FEATURE_NORMAL_DISTANCE_EPS
==============
*/
double phys_contact_manifold::get_STD_COMP_FEATURE_NORMAL_DISTANCE_EPS(const float penetration_t)
{
  if ( penetration_t < 0.0 || penetration_t > 1.0 )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_contact_manifold.h",
           270,
           "penetration_t >= 0.0f && penetration_t <= 1.0f",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
  return (float)(penetration_t * 1.700000047683716 + 1.700000047683716);
}

/*
==============
phys_contact_manifold::get_STD_COMP_FEATURE_NORMAL_SIN_ANGULAR_EPS_SQ
==============
*/
double phys_contact_manifold::get_STD_COMP_FEATURE_NORMAL_SIN_ANGULAR_EPS_SQ(const float penetration_t)
{
  if ( penetration_t < 0.0 || penetration_t > 1.0 )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_contact_manifold.h",
           278,
           "penetration_t >= 0.0f && penetration_t <= 1.0f",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
  return (float)(penetration_t * 0.007589269621803396 + 0.000006853876129753189);
}

/*
==============
phys_contact_manifold::get_STD_GET_FEATURE_DISTANCE_EPS
==============
*/
double phys_contact_manifold::get_STD_GET_FEATURE_DISTANCE_EPS(const float penetration_t)
{
  if ( penetration_t < 0.0 || penetration_t > 1.0 )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_contact_manifold.h",
           288,
           "penetration_t >= 0.0f && penetration_t <= 1.0f",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
  return (float)(penetration_t * 5.100000143051147 + 1.700000047683716);
}

/*
==============
phys_contact_manifold::get_STD_GET_FEATURE_SIN_ANGULAR_EPS_SQ
==============
*/
double phys_contact_manifold::get_STD_GET_FEATURE_SIN_ANGULAR_EPS_SQ(const float penetration_t)
{
  if ( penetration_t < 0.0 || penetration_t > 1.0 )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_contact_manifold.h",
           296,
           "penetration_t >= 0.0f && penetration_t <= 1.0f",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
  return (float)(penetration_t * 0.4698463100939989 + 0.03015368990600109);
}

/*
==============
phys_contact_manifold_process::comp_contact_mat
==============
*/
void __userpurge phys_contact_manifold_process::comp_contact_mat(phys_contact_manifold_process *this@<ecx>, int a2@<ebp>, phys_vec3 *contact_normal)
{
  phys_contact_manifold_process *v3; // edi
  double v4; // st6
  double v5; // st7
  float v6; // [esp-1Ch] [ebp-3Ch]
  float v7; // [esp-18h] [ebp-38h]
  float v8; // [esp-14h] [ebp-34h]
  float v9; // [esp-10h] [ebp-30h]
  float v10; // [esp-Ch] [ebp-2Ch]
  float v11; // [esp-8h] [ebp-28h]
  float v12; // [esp-4h] [ebp-24h]
  phys_vec3 yrow; // [esp+0h] [ebp-20h]
  float v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch]
  int v16; // [esp+18h] [ebp-8h]
  int retaddr; // [esp+20h] [ebp+0h]

  v15 = a2;
  v16 = retaddr;
  v3 = this;
  v14 = fabs(contact_normal->x);
  if ( v14 >= 0.800000011920929 )
  {
    v14 = contact_normal->y;
    v10 = contact_normal->x * v14;
    v11 = contact_normal->y * v14;
    v12 = v14 * contact_normal->z;
    v5 = 0.0;
    v6 = 0.0 - v10;
    v4 = 1.0 - v11;
  }
  else
  {
    v14 = contact_normal->x;
    v10 = contact_normal->x * v14;
    v11 = contact_normal->y * v14;
    v12 = v14 * contact_normal->z;
    v6 = 1.0 - v10;
    v4 = 0.0 - v11;
    v5 = 0.0;
  }
  v7 = v4;
  v8 = v5 - v12;
  v10 = v6;
  v11 = v7;
  v12 = v8;
  yrow.x = v9;
  v14 = v7 * v7 + v6 * v6 + v8 * v8;
  v14 = sqrt(v14);
  if ( v14 <= 0.1000000014901161
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_contact_manifold.h",
         397,
         "nyrow > 0.1f",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v14 = 1.0 / v14;
  v6 = v14 * v10;
  v7 = v11 * v14;
  v8 = v14 * v12;
  v3->contact_mat.y.x = v6;
  v3->contact_mat.y.y = v7;
  v3->contact_mat.y.z = v8;
  v6 = contact_normal->z * v3->contact_mat.y.y - v3->contact_mat.y.z * contact_normal->y;
  v7 = v3->contact_mat.y.z * contact_normal->x - contact_normal->z * v3->contact_mat.y.x;
  v8 = v3->contact_mat.y.x * contact_normal->y - v3->contact_mat.y.y * contact_normal->x;
  v3->contact_mat.x.x = v6;
  v3->contact_mat.x.y = v7;
  v3->contact_mat.x.z = v8;
  v3->contact_mat.z.x = contact_normal->x;
  v3->contact_mat.z.y = contact_normal->y;
  v3->contact_mat.z.z = contact_normal->z;
}

/*
==============
phys_contact_manifold::set_get_feature_params
==============
*/
void __thiscall phys_contact_manifold::set_get_feature_params(phys_contact_manifold *this, phys_vec3 *hitp, phys_vec3 *hitn, const float feature_distance_eps, const float sin_feautre_angular_eps_sq)
{
  phys_contact_manifold *v5; // esi
  phys_memory_heap *v6; // edi
  const char *v7; // ecx
  unsigned int v8; // eax

  v5 = this;
  this->m_feature_hitp.x = hitp->x;
  this->m_feature_hitp.y = hitp->y;
  this->m_feature_hitp.z = hitp->z;
  this->m_feature_hitn.x = hitn->x;
  this->m_feature_hitn.y = hitn->y;
  this->m_feature_hitn.z = hitn->z;
  v6 = this->m_allocator;
  this->m_feature_distance_eps = feature_distance_eps;
  this->m_sin_feautre_angular_eps_sq = sin_feautre_angular_eps_sq;
  v7 = g_contact_manifold_error_msg;
  v8 = (_DWORD)(v6->m_buffer_cur + 15) & 0xFFFFFFF0;
  v6->m_buffer_cur = (char *)v8;
  if ( (char *)v8 >= v6->m_buffer_end
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 114, "m_buffer_cur < m_buffer_end", v7) )
  {
    __debugbreak();
  }
  v5->m_list_mesh_point = (contact_manifold_mesh_point *)v6->m_buffer_cur;
  v5->m_list_mesh_point_count = 0;
  v5->m_close_mesh_point_count = 0;
  v5->m_list_sorted_mesh_point = NULL;
  v5->m_list_contact_point = NULL;
}

