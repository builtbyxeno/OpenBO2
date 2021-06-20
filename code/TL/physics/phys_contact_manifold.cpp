/*
==============
phys_contact_manifold::compute_convex_poly_area
==============
*/
double __thiscall phys_contact_manifold::compute_convex_poly_area(phys_contact_manifold *this)
{
  contact_manifold_mesh_point **v1; // edx
  contact_manifold_mesh_point *v2; // esi
  int *v3; // eax
  int v4; // edi
  int v5; // ecx
  int v6; // edx
  float v7; // ST08_4
  float v8; // ST0C_4
  float v9; // ST10_4
  float v10; // ST14_4
  float v11; // ST18_4
  float v12; // ST1C_4
  double result; // st7
  float v14; // ST1C_4
  float area; // [esp+14h] [ebp-4h]

  v1 = this->m_list_contact_point;
  area = 0.0;
  v2 = *v1;
  v3 = (int *)(v1 + 1);
  v4 = (int)&v1[this->m_list_contact_point_count - 1];
  if ( v1 + 1 != (contact_manifold_mesh_point **)v4 )
  {
    do
    {
      v5 = *v3;
      v6 = v3[1];
      ++v3;
      v7 = *(float *)(v6 + 16) - *(float *)(v5 + 16);
      v8 = *(float *)(v6 + 20) - *(float *)(v5 + 20);
      v9 = *(float *)(v5 + 16) - v2->m_contact_p.x;
      v10 = *(float *)(v5 + 20) - v2->m_contact_p.y;
      v11 = v9 * v8 - v10 * v7;
      area = v11 + area;
    }
    while ( v3 != (int *)v4 );
  }
  v12 = area * 0.5;
  result = v12;
  if ( v12 < 0.0 )
  {
    v14 = -result;
    result = v14;
  }
  return result;
}

/*
==============
phys_contact_manifold::compute_convex_poly_perimeter
==============
*/
double __thiscall phys_contact_manifold::compute_convex_poly_perimeter(phys_contact_manifold *this)
{
  contact_manifold_mesh_point **v1; // esi
  int v2; // edi
  contact_manifold_mesh_point **i; // eax
  contact_manifold_mesh_point *v4; // eax
  float v5; // ST08_4
  float v6; // ST0C_4
  float v7; // ST10_4
  float v8; // ST10_4
  float perimeter; // [esp+10h] [ebp-4h]

  perimeter = 0.0;
  v1 = this->m_list_contact_point;
  v2 = (int)&v1[this->m_list_contact_point_count];
  for ( i = (contact_manifold_mesh_point **)(v2 - 4); v1 != (contact_manifold_mesh_point **)v2; perimeter = v8 + perimeter )
  {
    v4 = *i;
    v5 = (*v1)->m_contact_p.x - v4->m_contact_p.x;
    v6 = (*v1)->m_contact_p.y - v4->m_contact_p.y;
    v7 = v5 * v5 + v6 * v6;
    v8 = sqrt(v7);
    i = v1;
    ++v1;
  }
  return perimeter;
}

/*
==============
feature_qsort
==============
*/
void feature_qsort(contact_manifold_mesh_point **list, const int list_count)
{
  int v2; // eax
  bool v3; // zf
  bool v4; // sf
  unsigned __int8 v5; // of
  contact_manifold_mesh_point **v6; // edx
  contact_manifold_mesh_point *v7; // edi
  contact_manifold_mesh_point **v8; // ebx
  contact_manifold_mesh_point **v9; // ecx
  contact_manifold_mesh_point **v10; // esi
  contact_manifold_mesh_point *v11; // edx
  contact_manifold_mesh_point *v12; // eax
  contact_manifold_mesh_point *v13; // edx
  contact_manifold_mesh_point *v14; // eax
  contact_manifold_mesh_point *v15; // edx
  contact_manifold_mesh_point *v16; // eax
  contact_manifold_mesh_point *v17; // edx
  contact_manifold_mesh_point *v18; // eax
  contact_manifold_mesh_point *v19; // edx
  contact_manifold_mesh_point *v20; // eax
  contact_manifold_mesh_point *v21; // edx

  v2 = list_count;
  v5 = __OFSUB__(list_count, 2);
  v3 = list_count == 2;
  v4 = list_count - 2 < 0;
  if ( list_count == 2 )
  {
LABEL_20:
    v21 = *list;
    if ( (*list)->m_contact_p.x < (double)list[1]->m_contact_p.x )
    {
      *list = list[1];
      list[1] = v21;
    }
  }
  else
  {
    while ( !((unsigned __int8)(v4 ^ v5) | v3) )
    {
      v6 = list;
      v7 = *list;
      v8 = &list[v2 - 1];
      v9 = list + 1;
      v10 = list;
      if ( list + 1 <= v8 )
      {
        if ( (4 * v2 - 4) / 4 >= 4 )
        {
          do
          {
            v11 = *v9;
            if ( v7->m_contact_p.x < (double)(*v9)->m_contact_p.x )
            {
              v12 = v10[1];
              ++v10;
              *v9 = v12;
              *v10 = v11;
            }
            v13 = v9[1];
            if ( v7->m_contact_p.x < (double)v13->m_contact_p.x )
            {
              v14 = v10[1];
              ++v10;
              v9[1] = v14;
              *v10 = v13;
            }
            v15 = v9[2];
            if ( v7->m_contact_p.x < (double)v15->m_contact_p.x )
            {
              v16 = v10[1];
              ++v10;
              v9[2] = v16;
              *v10 = v15;
            }
            v17 = v9[3];
            if ( v7->m_contact_p.x < (double)v17->m_contact_p.x )
            {
              v18 = v10[1];
              ++v10;
              v9[3] = v18;
              *v10 = v17;
            }
            v9 += 4;
          }
          while ( (signed int)v9 <= (signed int)(v8 - 3) );
        }
        for ( ; v9 <= v8; ++v9 )
        {
          v19 = *v9;
          if ( v7->m_contact_p.x < (double)(*v9)->m_contact_p.x )
          {
            v20 = v10[1];
            ++v10;
            *v9 = v20;
            *v10 = v19;
          }
        }
        v6 = list;
      }
      *v6 = *v10;
      *v10 = v7;
      feature_qsort(v6, v10 - v6);
      v2 = v8 - v10;
      list = v10 + 1;
      v5 = __OFSUB__(v2, 2);
      v3 = v2 == 2;
      v4 = v2 - 2 < 0;
      if ( v2 == 2 )
        goto LABEL_20;
    }
  }
}

/*
==============
convex_poly_qsort
==============
*/
void convex_poly_qsort(contact_manifold_mesh_point **list, const int list_count)
{
  int v2; // eax
  bool v3; // zf
  bool v4; // sf
  unsigned __int8 v5; // of
  contact_manifold_mesh_point **v6; // edx
  contact_manifold_mesh_point *v7; // edi
  contact_manifold_mesh_point **v8; // ebx
  contact_manifold_mesh_point **v9; // ecx
  contact_manifold_mesh_point **v10; // esi
  contact_manifold_mesh_point *v11; // edx
  contact_manifold_mesh_point *v12; // eax
  contact_manifold_mesh_point *v13; // edx
  contact_manifold_mesh_point *v14; // eax
  contact_manifold_mesh_point *v15; // edx
  contact_manifold_mesh_point *v16; // eax
  contact_manifold_mesh_point *v17; // edx
  contact_manifold_mesh_point *v18; // eax
  contact_manifold_mesh_point *v19; // edx
  contact_manifold_mesh_point *v20; // eax
  contact_manifold_mesh_point *v21; // ecx
  contact_manifold_mesh_point *v22; // edx

  v2 = list_count;
  v5 = __OFSUB__(list_count, 2);
  v3 = list_count == 2;
  v4 = list_count - 2 < 0;
  if ( list_count == 2 )
  {
LABEL_30:
    v21 = list[1];
    v22 = *list;
    if ( (*list)->m_contact_p.x > (double)v21->m_contact_p.x
      || v22->m_contact_p.x == v21->m_contact_p.x && v22->m_contact_p.y > (double)v21->m_contact_p.y )
    {
      *list = v21;
      list[1] = v22;
    }
  }
  else
  {
    while ( !((unsigned __int8)(v4 ^ v5) | v3) )
    {
      v6 = list;
      v7 = *list;
      v8 = &list[v2 - 1];
      v9 = list + 1;
      v10 = list;
      if ( list + 1 <= v8 )
      {
        if ( (4 * v2 - 4) / 4 >= 4 )
        {
          do
          {
            v11 = *v9;
            if ( v7->m_contact_p.x > (double)(*v9)->m_contact_p.x
              || v7->m_contact_p.x == v11->m_contact_p.x && v7->m_contact_p.y > (double)v11->m_contact_p.y )
            {
              v12 = v10[1];
              ++v10;
              *v9 = v12;
              *v10 = v11;
            }
            v13 = v9[1];
            if ( v7->m_contact_p.x > (double)v13->m_contact_p.x
              || v7->m_contact_p.x == v13->m_contact_p.x && v7->m_contact_p.y > (double)v13->m_contact_p.y )
            {
              v14 = v10[1];
              ++v10;
              v9[1] = v14;
              *v10 = v13;
            }
            v15 = v9[2];
            if ( v7->m_contact_p.x > (double)v15->m_contact_p.x
              || v7->m_contact_p.x == v15->m_contact_p.x && v7->m_contact_p.y > (double)v15->m_contact_p.y )
            {
              v16 = v10[1];
              ++v10;
              v9[2] = v16;
              *v10 = v15;
            }
            v17 = v9[3];
            if ( v7->m_contact_p.x > (double)v17->m_contact_p.x
              || v7->m_contact_p.x == v17->m_contact_p.x && v7->m_contact_p.y > (double)v17->m_contact_p.y )
            {
              v18 = v10[1];
              ++v10;
              v9[3] = v18;
              *v10 = v17;
            }
            v9 += 4;
          }
          while ( (signed int)v9 <= (signed int)(v8 - 3) );
        }
        for ( ; v9 <= v8; ++v9 )
        {
          v19 = *v9;
          if ( v7->m_contact_p.x > (double)(*v9)->m_contact_p.x
            || v7->m_contact_p.x == v19->m_contact_p.x && v7->m_contact_p.y > (double)v19->m_contact_p.y )
          {
            v20 = v10[1];
            ++v10;
            *v9 = v20;
            *v10 = v19;
          }
        }
        v6 = list;
      }
      *v6 = *v10;
      *v10 = v7;
      convex_poly_qsort(v6, v10 - v6);
      v2 = v8 - v10;
      list = v10 + 1;
      v5 = __OFSUB__(v2, 2);
      v3 = v2 == 2;
      v4 = v2 - 2 < 0;
      if ( v2 == 2 )
        goto LABEL_30;
    }
  }
}

/*
==============
phys_contact_manifold::generate_convex_poly_internal
==============
*/
void __thiscall phys_contact_manifold::generate_convex_poly_internal(phys_contact_manifold *this)
{
  phys_contact_manifold *v1; // ebx
  int v2; // eax
  contact_manifold_mesh_point **min_length2; // ST08_4
  contact_manifold_mesh_point **v4; // edi
  contact_manifold_mesh_point **v5; // esi
  contact_manifold_mesh_point **v6; // eax
  contact_manifold_mesh_point *v7; // ebx
  int v8; // eax
  int v9; // ecx
  unsigned int v10; // edi
  phys_memory_heap *v11; // eax
  contact_manifold_mesh_point **v12; // eax
  contact_manifold_mesh_point **v13; // edi
  contact_manifold_mesh_point *v14; // ebx
  int v15; // eax
  int v16; // ecx
  unsigned int v17; // edi
  phys_memory_heap *v18; // eax
  int v19; // esi
  bool v20; // zf
  bool v21; // sf
  unsigned __int8 v22; // of
  phys_vec2 e1; // [esp+14h] [ebp-20h]
  phys_vec2 e2; // [esp+1Ch] [ebp-18h]
  contact_manifold_mesh_point **last_i_smp; // [esp+24h] [ebp-10h]
  phys_contact_manifold *v26; // [esp+28h] [ebp-Ch]
  contact_manifold_mesh_point **i_smp; // [esp+2Ch] [ebp-8h]
  contact_manifold_mesh_point **min_cp_mp; // [esp+30h] [ebp-4h]

  v1 = this;
  v2 = this->m_list_mesh_point_count;
  min_length2 = this->m_list_sorted_mesh_point;
  v26 = this;
  convex_poly_qsort(min_length2, v2);
  v4 = v1->m_list_sorted_mesh_point;
  v5 = v1->m_list_contact_point;
  v6 = &v4[v1->m_list_mesh_point_count];
  i_smp = v1->m_list_sorted_mesh_point;
  min_cp_mp = v5 + 1;
  last_i_smp = v6;
  if ( v4 < v6 )
  {
    do
    {
      v7 = *v4;
      if ( v5 > min_cp_mp )
      {
        do
        {
          v8 = (int)*(v5 - 1);
          v9 = (int)*(v5 - 2);
          v10 = (unsigned int)(v5 - 1);
          e2.x = v7->m_contact_p.x - *(float *)(v8 + 16);
          e2.y = v7->m_contact_p.y - *(float *)(v8 + 20);
          e1.x = *(float *)(v8 + 16) - *(float *)(v9 + 16);
          e1.y = *(float *)(v8 + 20) - *(float *)(v9 + 20);
          if ( phys_contact_manifold::rht(&e1, &e2, 0.1156, 0.00030458649) )
            break;
          --v5;
        }
        while ( v10 > (unsigned int)min_cp_mp );
        v4 = i_smp;
      }
      v11 = v26->m_allocator;
      if ( ((char *)v5 < v11->m_buffer_start || (char *)(v5 + 1) > v11->m_buffer_end)
        && _tlAssert(
             "source/phys_contact_manifold.cpp",
             205,
             "m_allocator->fast_is_within_buffer_limits(cp_mp,sizeof(contact_manifold_mesh_point*))",
             g_contact_manifold_error_msg) )
      {
        __debugbreak();
      }
      ++v4;
      *v5 = v7;
      ++v5;
      i_smp = v4;
    }
    while ( v4 < last_i_smp );
    v1 = v26;
  }
  v12 = v1->m_list_sorted_mesh_point;
  v13 = v4 - 2;
  min_cp_mp = v5;
  last_i_smp = v12;
  i_smp = v13;
  if ( v13 >= v12 )
  {
    do
    {
      v14 = *v13;
      if ( v5 > min_cp_mp )
      {
        do
        {
          v15 = (int)*(v5 - 1);
          v16 = (int)*(v5 - 2);
          v17 = (unsigned int)(v5 - 1);
          e1.x = v14->m_contact_p.x - *(float *)(v15 + 16);
          e1.y = v14->m_contact_p.y - *(float *)(v15 + 20);
          e2.x = *(float *)(v15 + 16) - *(float *)(v16 + 16);
          e2.y = *(float *)(v15 + 20) - *(float *)(v16 + 20);
          if ( phys_contact_manifold::rht(&e2, &e1, 0.1156, 0.00030458649) )
            break;
          --v5;
        }
        while ( v17 > (unsigned int)min_cp_mp );
        v13 = i_smp;
      }
      v18 = v26->m_allocator;
      if ( ((char *)v5 < v18->m_buffer_start || (char *)(v5 + 1) > v18->m_buffer_end)
        && _tlAssert(
             "source/phys_contact_manifold.cpp",
             226,
             "m_allocator->fast_is_within_buffer_limits(cp_mp,sizeof(contact_manifold_mesh_point*))",
             g_contact_manifold_error_msg) )
      {
        __debugbreak();
      }
      --v13;
      *v5 = v14;
      ++v5;
      i_smp = v13;
    }
    while ( v13 >= last_i_smp );
    v1 = v26;
  }
  v19 = ((char *)v5 - (char *)v1->m_list_contact_point - 4) >> 2;
  v22 = __OFSUB__(v19, v1->m_list_mesh_point_count);
  v20 = v19 == v1->m_list_mesh_point_count;
  v21 = v19 - v1->m_list_mesh_point_count < 0;
  v1->m_list_contact_point_count = v19;
  if ( !((unsigned __int8)(v21 ^ v22) | v20) )
  {
    if ( _tlAssert(
           "source/phys_contact_manifold.cpp",
           232,
           "m_list_contact_point_count <= m_list_mesh_point_count",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
}

/*
==============
phys_contact_manifold_process::intersect_poly_segment
==============
*/
void __thiscall phys_contact_manifold_process::intersect_poly_segment(phys_contact_manifold_process *this, phys_contact_manifold *cman, phys_vec2 *p0, phys_vec2 *p1)
{
  phys_vec2 *v4; // esi
  phys_contact_manifold_process *v5; // ebx
  contact_manifold_mesh_point **v6; // ecx
  contact_manifold_mesh_point **v7; // edi
  contact_manifold_mesh_point *v8; // eax
  double v9; // st7
  double v10; // st5
  double v11; // rt0
  contact_manifold_mesh_point *v12; // edx
  float v13; // ST24_4
  float v14; // ST28_4
  float normal; // ST1C_4
  float v16; // ST2C_4
  float v17; // ST30_4
  float denom; // ST3C_4
  double v19; // st4
  double v20; // rt2
  double v21; // st5
  double v22; // st7
  bool v23; // c0
  double v24; // st4
  double v25; // rtt
  contact_manifold_mesh_point **v26; // eax
  contact_manifold_mesh_point *v27; // eax
  float v28; // ST24_4
  float v29; // ST28_4
  float v30; // ST2C_4
  double v31; // st5
  float v32; // ST30_4
  int v33; // eax
  float v34; // ST24_4
  float v35; // ST28_4
  float v36; // ST2C_4
  double v37; // st7
  float v38; // ST30_4
  float dir; // [esp+24h] [ebp-10h]
  float dir_4; // [esp+28h] [ebp-Ch]
  float t_; // [esp+30h] [ebp-4h]
  float t_a; // [esp+30h] [ebp-4h]
  float t_exit; // [esp+40h] [ebp+Ch]
  float t_enter; // [esp+44h] [ebp+10h]

  v4 = p0;
  v5 = this;
  dir = p1->x - p0->x;
  v6 = cman->m_list_contact_point;
  v7 = &v6[cman->m_list_contact_point_count - 1];
  v8 = *v7;
  dir_4 = p1->y - p0->y;
  v9 = 0.0;
  t_enter = 0.0;
  t_exit = 1.0;
  if ( v6 <= v7 )
  {
    v10 = 0.00009999999747378752;
    while ( 1 )
    {
      v12 = *v6;
      v13 = v8->m_contact_p.x - (*v6)->m_contact_p.x;
      v14 = v8->m_contact_p.y - (*v6)->m_contact_p.y;
      normal = -v14;
      v16 = v8->m_contact_p.x - v4->x;
      v17 = v8->m_contact_p.y - v4->y;
      t_ = v17 * v13 + v16 * normal;
      denom = v13 * dir_4 + normal * dir;
      v19 = denom;
      if ( denom <= -0.00009999999747378752 || v19 >= v10 )
      {
        t_a = t_ / v19;
        v23 = v19 < v9;
        v24 = t_a;
        if ( v23 )
        {
          if ( t_enter < v24 )
            t_enter = t_a;
        }
        else if ( t_exit > v24 )
        {
          t_exit = t_a;
        }
        if ( t_exit < (double)t_enter )
          return;
        v25 = v10;
        v21 = v9;
        v22 = v25;
      }
      else
      {
        v20 = v10;
        v21 = v9;
        v22 = v20;
        if ( v21 > t_ )
          return;
      }
      ++v6;
      v8 = v12;
      if ( v6 > v7 )
        break;
      v11 = v21;
      v10 = v22;
      v9 = v11;
    }
  }
  if ( t_exit < (double)t_enter
    && _tlAssert("source/phys_contact_manifold.cpp", 294, "t_enter <= t_exit", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( cman->m_list_contact_point_count < 2 )
  {
    if ( _tlAssert(
           "source/phys_contact_manifold.cpp",
           295,
           "cman->m_list_contact_point_count >= 2",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
  v26 = cman->m_list_contact_point;
  v5->m_list_isect_point = v26;
  v5->m_contact_point_count = 2;
  v27 = *v26;
  v28 = dir * t_enter;
  v29 = t_enter * dir_4;
  v30 = v4->x + v28;
  v31 = v29 + v4->y;
  v27->m_contact_p.x = v30;
  v32 = v31;
  v27->m_contact_p.y = v32;
  v33 = *((_DWORD *)v5->m_list_isect_point + 1);
  v34 = dir * t_exit;
  v35 = t_exit * dir_4;
  v36 = v4->x + v34;
  v37 = v35 + v4->y;
  *(float *)(v33 + 16) = v36;
  v38 = v37;
  *(float *)(v33 + 20) = v38;
}

/*
==============
phys_contact_manifold_process::find_bottom
==============
*/
char phys_contact_manifold_process::find_bottom(phys_contact_manifold_process::bridge *b, phys_contact_manifold_process::isect_info *left_cman, phys_contact_manifold_process::isect_info *right_cman)
{
  phys_contact_manifold_process::isect_info *v4; // ebx
  phys_contact_manifold_process::bridge *v5; // esi
  contact_manifold_mesh_point **v6; // eax
  int v7; // ecx
  int v8; // edi
  contact_manifold_mesh_point *v9; // eax
  float left_edge; // ST24_4
  float left_edge_4; // ST28_4
  double v12; // st6
  double v13; // st5
  contact_manifold_mesh_point **v14; // eax
  contact_manifold_mesh_point **v15; // ecx
  float v16; // ST1C_4
  float v17; // ST20_4
  contact_manifold_mesh_point **v18; // eax
  contact_manifold_mesh_point **v19; // ecx
  contact_manifold_mesh_point *v20; // ecx
  contact_manifold_mesh_point *v21; // eax
  float right_edge; // ST14_4
  float right_edge_4; // ST18_4
  double v24; // st4
  double v25; // st3
  contact_manifold_mesh_point **v26; // eax
  contact_manifold_mesh_point **v27; // edx
  float v28; // ST0C_4
  float v29; // ST10_4
  char result; // al
  float v31; // ST0C_4
  float v32; // ST10_4
  double v33; // rt0
  float v34; // ST0C_4
  float v35; // ST10_4
  float v36; // ST14_4
  double v37; // st7
  float v38; // ST18_4
  contact_manifold_mesh_point *v39; // eax
  contact_manifold_mesh_point **r_i; // [esp+2Ch] [ebp-Ch]
  contact_manifold_mesh_point **start_left_i; // [esp+30h] [ebp-8h]
  contact_manifold_mesh_point **start_right_i; // [esp+34h] [ebp-4h]
  float deta; // [esp+40h] [ebp+8h]
  float detb; // [esp+40h] [ebp+8h]
  float det; // [esp+40h] [ebp+8h]
  float detc; // [esp+40h] [ebp+8h]
  float detd; // [esp+40h] [ebp+8h]
  contact_manifold_mesh_point **l_i; // [esp+44h] [ebp+Ch]

  v4 = left_cman;
  v5 = b;
  v6 = b->m_left_i;
  start_left_i = b->m_left_i;
  start_right_i = b->m_right_i;
  do
  {
    l_i = v6;
    r_i = v5->m_right_i;
    if ( v6 == v4->m_last_i )
      v7 = (int)v4->m_cman->m_list_contact_point;
    else
      v7 = (int)(v6 + 1);
    v8 = *(_DWORD *)v7;
    v9 = *v6;
    left_edge = *(float *)(*(_DWORD *)v7 + 16) - v9->m_contact_p.x;
    left_edge_4 = *(float *)(*(_DWORD *)v7 + 20) - v9->m_contact_p.y;
    v12 = left_edge_4;
    v13 = left_edge;
    while ( 1 )
    {
      v14 = v5->m_right_i;
      v15 = v14 == right_cman->m_cman->m_list_contact_point ? right_cman->m_last_i : v14 - 1;
      v16 = (*v15)->m_contact_p.x - *(float *)(v8 + 16);
      v17 = (*v15)->m_contact_p.y - *(float *)(v8 + 20);
      deta = v17 * v13 - v12 * v16;
      if ( deta >= 0.0 )
        break;
      v5->m_right_i = v15;
      if ( v15 == start_right_i )
        return 0;
    }
    v18 = v5->m_right_i;
    if ( v18 == right_cman->m_cman->m_list_contact_point )
      v19 = right_cman->m_last_i;
    else
      v19 = v18 - 1;
    v20 = *v19;
    v21 = *v18;
    right_edge = v20->m_contact_p.x - v21->m_contact_p.x;
    right_edge_4 = v20->m_contact_p.y - v21->m_contact_p.y;
    v24 = right_edge_4;
    v25 = right_edge;
    while ( 1 )
    {
      v26 = v5->m_left_i;
      v27 = v26 == v4->m_last_i ? v4->m_cman->m_list_contact_point : v26 + 1;
      v28 = (*v27)->m_contact_p.x - v20->m_contact_p.x;
      v29 = (*v27)->m_contact_p.y - v20->m_contact_p.y;
      detb = v29 * v25 - v24 * v28;
      if ( detb <= 0.0 )
        break;
      v5->m_left_i = v27;
      if ( v27 == start_left_i )
        return 0;
    }
    v6 = v5->m_left_i;
  }
  while ( l_i != v6 || r_i != v5->m_right_i );
  det = v24 * v13 - v12 * v25;
  if ( det <= 0.00009999999747378752 )
  {
    v39 = *v5->m_right_i;
    v5->m_intersection_p.x = v39->m_contact_p.x;
    v5->m_intersection_p.y = v39->m_contact_p.y;
    result = 1;
  }
  else
  {
    v31 = v20->m_contact_p.x - *(float *)(v8 + 16);
    v32 = v20->m_contact_p.y - *(float *)(v8 + 20);
    v33 = det;
    detc = v24 * v31 - v25 * v32;
    detd = detc / v33;
    v34 = v13 * detd;
    v35 = detd * v12;
    v36 = *(float *)(v8 + 16) + v34;
    v37 = *(float *)(v8 + 20);
    v5->m_intersection_p.x = v36;
    result = 1;
    v38 = v37 + v35;
    v5->m_intersection_p.y = v38;
  }
  return result;
}

/*
==============
phys_contact_manifold::comp_feature_normal
==============
*/
void __thiscall phys_contact_manifold::comp_feature_normal(phys_contact_manifold *this)
{
  phys_contact_manifold *v1; // edi
  phys_memory_heap *v2; // esi
  const char *v3; // ecx
  unsigned int v4; // eax
  int v5; // ecx
  phys_memory_heap *v6; // eax
  const char *v7; // edx
  contact_manifold_mesh_point **v8; // eax
  contact_manifold_mesh_point *v9; // ecx
  unsigned int v10; // esi
  bool v11; // sf
  unsigned __int8 v12; // of
  double v13; // st7
  float **v14; // edx
  float *v15; // ecx
  float v16; // ST30_4
  float v17; // ST34_4
  float v18; // ST38_4
  double v19; // st6
  double v20; // st4
  double v21; // st5
  float v22; // ST50_4
  double v23; // st2
  float v24; // ST50_4
  float v25; // ST50_4
  float v26; // ST30_4
  float v27; // ST34_4
  float v28; // ST38_4
  float v29; // ST20_4
  float v30; // ST24_4
  float v31; // ST28_4
  float v32; // ST50_4
  float *v33; // eax
  float *v34; // eax
  contact_manifold_mesh_point **v35; // eax
  int v36; // edx
  unsigned int v37; // ecx
  float *v38; // eax
  float *v39; // ecx
  float v40; // ST30_4
  float v41; // ST34_4
  float v42; // ST38_4
  double v43; // st6
  double v44; // st4
  double v45; // st5
  float v46; // ST64_4
  double v47; // st3
  float v48; // ST64_4
  double v49; // st2
  float v50; // ST64_4
  char v51; // cl
  float v52; // ST20_4
  float v53; // ST24_4
  float v54; // ST28_4
  float **v55; // esi
  float *v56; // edx
  float v57; // ST6C_4
  float *v58; // edx
  float v59; // ST6C_4
  float *v60; // edx
  float v61; // ST6C_4
  float *v62; // edx
  float v63; // ST6C_4
  float *v64; // edx
  float v65; // ST6C_4
  double v66; // st6
  contact_manifold_mesh_point **v67; // edx
  float **j; // esi
  float *v69; // ecx
  float v70; // ST4C_4
  double v71; // st5
  float v72; // ST4C_4
  float v73; // ST4C_4
  float v74; // ST4C_4
  float v75; // ST4C_4
  float v76; // ST20_4
  float v77; // ST24_4
  double v78; // st5
  float v79; // ST28_4
  float v80; // ST30_4
  float v81; // ST34_4
  float v82; // ST38_4
  unsigned int v83; // [esp+10h] [ebp-30h]
  float **v84; // [esp+14h] [ebp-2Ch]
  float v85; // [esp+14h] [ebp-2Ch]
  unsigned int v86; // [esp+18h] [ebp-28h]
  float v87; // [esp+18h] [ebp-28h]
  float dot_p_fn; // [esp+1Ch] [ebp-24h]
  contact_manifold_mesh_point **start_mp; // [esp+20h] [ebp-20h]
  contact_manifold_mesh_point **mp_j_it; // [esp+24h] [ebp-1Ch]
  float best_cos_sq; // [esp+28h] [ebp-18h]
  unsigned int i; // [esp+2Ch] [ebp-14h]
  float v93; // [esp+30h] [ebp-10h]
  float v94; // [esp+30h] [ebp-10h]
  float v95; // [esp+30h] [ebp-10h]
  float v96; // [esp+30h] [ebp-10h]
  float v97; // [esp+30h] [ebp-10h]
  float v98; // [esp+30h] [ebp-10h]
  float v99; // [esp+30h] [ebp-10h]
  float v100; // [esp+30h] [ebp-10h]
  float v101; // [esp+30h] [ebp-10h]
  float v102; // [esp+30h] [ebp-10h]

  v1 = this;
  if ( !this->m_list_mesh_point
    && _tlAssert("source/phys_contact_manifold.cpp", 49, "m_list_mesh_point != NULL", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( v1->m_list_sorted_mesh_point
    && _tlAssert("source/phys_contact_manifold.cpp", 50, "m_list_sorted_mesh_point == NULL", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v2 = v1->m_allocator;
  v3 = g_contact_manifold_error_msg;
  v4 = (_DWORD)(v2->m_buffer_cur + 3) & 0xFFFFFFFC;
  v2->m_buffer_cur = (char *)v4;
  if ( (char *)v4 >= v2->m_buffer_end
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 114, "m_buffer_cur < m_buffer_end", v3) )
  {
    __debugbreak();
  }
  v5 = v1->m_list_mesh_point_count;
  v1->m_list_sorted_mesh_point = (contact_manifold_mesh_point **)v2->m_buffer_cur;
  v6 = v1->m_allocator;
  v7 = g_contact_manifold_error_msg;
  v6->m_buffer_cur += 4 * v5;
  if ( v6->m_buffer_cur > v6->m_buffer_end
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 122, "m_buffer_cur <= m_buffer_end", v7) )
  {
    __debugbreak();
  }
  v8 = v1->m_list_sorted_mesh_point;
  v9 = v1->m_list_mesh_point;
  v10 = (unsigned int)&v8[v1->m_list_mesh_point_count];
  for ( i = v10; (unsigned int)v8 < v10; ++v9 )
  {
    *v8 = v9;
    ++v8;
  }
  v12 = __OFSUB__(v1->m_list_mesh_point_count, 2);
  v11 = v1->m_list_mesh_point_count - 2 < 0;
  v1->m_list_mesh_point = NULL;
  if ( v11 ^ v12
    && _tlAssert("source/phys_contact_manifold.cpp", 61, "m_list_mesh_point_count >= 2", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v13 = 0.0;
  if ( v1->m_list_mesh_point_count == 2 )
  {
    v14 = (float **)v1->m_list_sorted_mesh_point;
    v15 = v14[1];
    v16 = *v15 - **v14;
    v17 = v15[1] - (*v14)[1];
    v18 = v15[2] - (*v14)[2];
    v19 = v17;
    v20 = v16;
    v21 = v18;
    v22 = v18 * v18 + v17 * v17 + v16 * v16;
    v23 = v22;
    if ( v22 <= 0.000011559999 )
    {
      v1->m_feature_normal.x = v1->m_feature_hitn.x;
      v1->m_feature_normal.y = v1->m_feature_hitn.y;
      v1->m_feature_normal.z = v1->m_feature_hitn.z;
    }
    else
    {
      v24 = v1->m_feature_hitn.x * v20 + v19 * v1->m_feature_hitn.y + v21 * v1->m_feature_hitn.z;
      v25 = v24 / v23;
      v26 = v20 * v25;
      v27 = v19 * v25;
      v28 = v25 * v21;
      v29 = v1->m_feature_hitn.x - v26;
      v30 = v1->m_feature_hitn.y - v27;
      v31 = v1->m_feature_hitn.z - v28;
      v1->m_feature_normal.x = v29;
      v1->m_feature_normal.y = v30;
      v1->m_feature_normal.z = v31;
      v32 = v31 * v31 + v30 * v30 + v29 * v29;
      if ( v32 <= 0.000011559999 )
      {
        v1->m_feature_normal.x = v1->m_feature_hitn.x;
        v1->m_feature_normal.y = v1->m_feature_hitn.y;
        v1->m_feature_normal.z = v1->m_feature_hitn.z;
      }
      v13 = 0.0;
    }
    v33 = *v14;
    *v33 = v1->m_feature_hitp.x + **v14;
    v33[1] = v33[1] + v1->m_feature_hitp.y;
    v33[2] = v33[2] + v1->m_feature_hitp.z;
    v34 = (float *)*((_DWORD *)v1->m_list_sorted_mesh_point + 1);
    *v34 = v1->m_feature_hitp.x + *v34;
    v34[1] = v34[1] + v1->m_feature_hitp.y;
    v34[2] = v34[2] + v1->m_feature_hitp.z;
  }
  else
  {
    feature_qsort(v1->m_list_sorted_mesh_point, v1->m_list_mesh_point_count);
    v35 = v1->m_list_sorted_mesh_point;
    v1->m_feature_normal.x = v1->m_feature_hitn.x;
    v36 = v1->m_close_mesh_point_count;
    v1->m_feature_normal.y = v1->m_feature_hitn.y;
    v37 = (unsigned int)&v35[v36];
    v1->m_feature_normal.z = v1->m_feature_hitn.z;
    v84 = (float **)v37;
    dot_p_fn = 0.11697778;
    v13 = 0.0;
    if ( v37 < v10 - 4 )
    {
      do
      {
        mp_j_it = *(contact_manifold_mesh_point ***)v37;
        if ( dot_p_fn > (double)*(float *)(*(_DWORD *)v37 + 16) )
          break;
        v83 = v37 + 4;
        v86 = v37 + 4;
        if ( v37 + 4 < v10 )
        {
          do
          {
            start_mp = *(contact_manifold_mesh_point ***)v86;
            if ( dot_p_fn > (double)*(float *)(*(_DWORD *)v86 + 16) )
              break;
            v38 = *(float **)v86;
            v39 = (float *)mp_j_it;
            v40 = v38[2] * v39[1] - v38[1] * v39[2];
            v41 = v39[2] * *v38 - v38[2] * *v39;
            v42 = v38[1] * *v39 - *v38 * v39[1];
            v43 = v40;
            v44 = v41;
            v45 = v42;
            v46 = v42 * v42 + v40 * v40 + v41 * v41;
            v47 = v46;
            if ( v46 > 0.000011559999 )
            {
              v48 = v44 * v1->m_feature_hitn.y + v1->m_feature_hitn.x * v43 + v45 * v1->m_feature_hitn.z;
              v49 = v48;
              v50 = v48 * v48;
              best_cos_sq = v50 / v47;
              if ( dot_p_fn < (double)best_cos_sq )
              {
                v51 = 1;
                if ( v49 < 0.0 )
                {
                  v52 = -v43;
                  v53 = -v44;
                  v54 = -v45;
                  v45 = v54;
                  v44 = v53;
                  v43 = v52;
                }
                v55 = v84;
                if ( (unsigned int)v84 >= i )
                  goto LABEL_100;
                if ( (signed int)(i - (_DWORD)v84 + 3) / 4 < 4 )
                {
LABEL_68:
                  while ( (unsigned int)v55 < i )
                  {
                    v64 = *v55;
                    if ( best_cos_sq > (double)(*v55)[4] )
                      break;
                    if ( !v51 )
                      goto LABEL_79;
                    if ( v64 != (float *)mp_j_it && v64 != (float *)start_mp )
                    {
                      v101 = v64[1] * v44 + *v64 * v43 + v64[2] * v45;
                      if ( v101 < 0.0 )
                      {
                        v65 = v101 * v101;
                        v102 = v65 / v47;
                        if ( v102 > 0.0011560001 && v64[5] * 0.000006853876129753189 < v102 )
                          v51 = 0;
                      }
                    }
                    ++v55;
                  }
                }
                else
                {
                  while ( 1 )
                  {
                    v56 = *v55;
                    if ( best_cos_sq > (double)(*v55)[4] )
                      break;
                    if ( !v51 )
                      goto LABEL_79;
                    if ( v56 != (float *)mp_j_it && v56 != (float *)start_mp )
                    {
                      v93 = v56[1] * v44 + *v56 * v43 + v56[2] * v45;
                      if ( v93 < 0.0 )
                      {
                        v57 = v93 * v93;
                        v94 = v57 / v47;
                        if ( v94 > 0.0011560001 && v56[5] * 0.000006853876129753189 < v94 )
                          v51 = 0;
                      }
                    }
                    v58 = v55[1];
                    if ( best_cos_sq > (double)v58[4] )
                      break;
                    if ( !v51 )
                      goto LABEL_79;
                    if ( v58 != (float *)mp_j_it && v58 != (float *)start_mp )
                    {
                      v95 = v58[1] * v44 + *v58 * v43 + v58[2] * v45;
                      if ( v95 < 0.0 )
                      {
                        v59 = v95 * v95;
                        v96 = v59 / v47;
                        if ( v96 > 0.0011560001 && v58[5] * 0.000006853876129753189 < v96 )
                          v51 = 0;
                      }
                    }
                    v60 = v55[2];
                    if ( best_cos_sq > (double)v60[4] )
                      break;
                    if ( !v51 )
                      goto LABEL_79;
                    if ( v60 != (float *)mp_j_it && v60 != (float *)start_mp )
                    {
                      v97 = v60[1] * v44 + *v60 * v43 + v60[2] * v45;
                      if ( v97 < 0.0 )
                      {
                        v61 = v97 * v97;
                        v98 = v61 / v47;
                        if ( v98 > 0.0011560001 && v60[5] * 0.000006853876129753189 < v98 )
                          v51 = 0;
                      }
                    }
                    v62 = v55[3];
                    if ( best_cos_sq > (double)v62[4] )
                      break;
                    if ( !v51 )
                      goto LABEL_79;
                    if ( v62 != (float *)mp_j_it && v62 != (float *)start_mp )
                    {
                      v99 = v62[1] * v44 + *v62 * v43 + v62[2] * v45;
                      if ( v99 < 0.0 )
                      {
                        v63 = v99 * v99;
                        v100 = v63 / v47;
                        if ( v100 > 0.0011560001 && v62[5] * 0.000006853876129753189 < v100 )
                          v51 = 0;
                      }
                    }
                    v55 += 4;
                    if ( (signed int)v55 >= (signed int)(i - 12) )
                      goto LABEL_68;
                  }
                }
                if ( v51 )
                {
LABEL_100:
                  dot_p_fn = best_cos_sq;
                  v1->m_feature_normal.x = v43;
                  v1->m_feature_normal.y = v44;
                  v1->m_feature_normal.z = v45;
                }
              }
            }
LABEL_79:
            v86 += 4;
          }
          while ( v86 < i );
        }
        v10 = i;
        v37 = v83;
      }
      while ( v83 < i - 4 );
    }
    v87 = v1->m_feature_normal.y * v1->m_feature_normal.y
        + v1->m_feature_normal.x * v1->m_feature_normal.x
        + v1->m_feature_normal.z * v1->m_feature_normal.z;
    v66 = v87;
    if ( v87 <= 0.0 )
    {
      if ( _tlAssert("source/phys_contact_manifold.cpp", 132, "nfeature_normal_sq > 0.0f", (const char *)&pBlock) )
        __debugbreak();
      v13 = 0.0;
      v66 = v87;
    }
    v67 = v1->m_list_sorted_mesh_point;
    for ( j = (float **)v1->m_list_sorted_mesh_point; (unsigned int)j < i; ++j )
    {
      v69 = *j;
      v70 = **j * v1->m_feature_normal.x + (*j)[1] * v1->m_feature_normal.y + (*j)[2] * v1->m_feature_normal.z;
      v71 = v70;
      v72 = v70 * v70;
      v85 = v72 / v66;
      v73 = v1->m_feature_distance_eps * v1->m_feature_distance_eps;
      if ( v73 >= (double)v85 || v69[5] * v1->m_sin_feautre_angular_eps_sq >= v85 )
      {
        ++v67;
        v75 = v71 / v66;
        v76 = v75 * v1->m_feature_normal.x;
        v77 = v75 * v1->m_feature_normal.y;
        v78 = v75 * v1->m_feature_normal.z;
        *(v67 - 1) = (contact_manifold_mesh_point *)v69;
        v79 = v78;
        v80 = v1->m_feature_hitp.x - v76;
        v81 = v1->m_feature_hitp.y - v77;
        v82 = v1->m_feature_hitp.z - v79;
        *v69 = v80 + *v69;
        v69[1] = v81 + v69[1];
        v69[2] = v69[2] + v82;
      }
    }
    v1->m_list_mesh_point_count = v67 - v1->m_list_sorted_mesh_point;
  }
  v74 = v1->m_feature_normal.y * v1->m_feature_normal.y
      + v1->m_feature_normal.x * v1->m_feature_normal.x
      + v1->m_feature_normal.z * v1->m_feature_normal.z;
  if ( v13 >= v74 )
  {
    if ( _tlAssert(
           "source/phys_contact_manifold.cpp",
           149,
           "AbsSquared(m_feature_normal) > 0.0f",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
}

/*
==============
phys_contact_manifold::generate_convex_poly
==============
*/
void __thiscall phys_contact_manifold::generate_convex_poly(phys_contact_manifold *this, phys_mat44 *contact_mat)
{
  phys_contact_manifold *v2; // esi
  phys_memory_heap *v3; // edi
  const char *v4; // ecx
  unsigned int v5; // eax
  contact_manifold_mesh_point **v6; // edi
  phys_memory_heap *v7; // eax
  float **v8; // edx
  int i; // edi
  float *v10; // eax
  double v11; // st7
  float v12; // ST18_4
  double v13; // st7
  double v14; // st6
  float v15; // ST1C_4
  contact_manifold_mesh_point **v16; // ecx
  contact_manifold_mesh_point *v17; // eax
  contact_manifold_mesh_point *v18; // ecx
  float v19; // ST18_4
  float v20; // ST1C_4
  phys_memory_heap *v21; // eax
  contact_manifold_mesh_point **v22; // edi
  const char *v23; // edx
  unsigned int v24; // ecx
  float contact_mata; // [esp+18h] [ebp+8h]

  v2 = this;
  if ( !this->m_list_sorted_mesh_point
    && _tlAssert("source/phys_contact_manifold.cpp", 237, "m_list_sorted_mesh_point != NULL", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( v2->m_list_contact_point
    && _tlAssert("source/phys_contact_manifold.cpp", 238, "m_list_contact_point == NULL", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( v2->m_list_mesh_point_count <= 1
    && _tlAssert("source/phys_contact_manifold.cpp", 239, "m_list_mesh_point_count > 1", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v3 = v2->m_allocator;
  v4 = g_contact_manifold_error_msg;
  v5 = (_DWORD)(v3->m_buffer_cur + 3) & 0xFFFFFFFC;
  v3->m_buffer_cur = (char *)v5;
  if ( (char *)v5 >= v3->m_buffer_end
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 114, "m_buffer_cur < m_buffer_end", v4) )
  {
    __debugbreak();
  }
  v6 = (contact_manifold_mesh_point **)v3->m_buffer_cur;
  v7 = v2->m_allocator;
  v2->m_list_contact_point = v6;
  if ( ((char *)v6 < v7->m_buffer_start || (char *)&v6[v2->m_list_mesh_point_count] > v7->m_buffer_end)
    && _tlAssert("source/phys_contact_manifold.cpp", 241, aM_allocatorF_0, g_contact_manifold_error_msg) )
  {
    __debugbreak();
  }
  v8 = (float **)v2->m_list_sorted_mesh_point;
  for ( i = (int)&v8[v2->m_list_mesh_point_count]; v8 != (float **)i; v10[5] = v15 )
  {
    v10 = *v8;
    v11 = **v8;
    ++v8;
    v12 = v11 * contact_mat->x.x + v10[1] * contact_mat->x.y + v10[2] * contact_mat->x.z;
    v13 = *v10 * contact_mat->y.x + contact_mat->y.y * v10[1];
    v14 = contact_mat->y.z;
    v10[4] = v12;
    v15 = v13 + v14 * v10[2];
  }
  phys_contact_manifold::generate_convex_poly_internal(v2);
  if ( v2->m_list_contact_point_count == 2 )
  {
    v16 = v2->m_list_contact_point;
    v17 = v16[1];
    v18 = *v16;
    v19 = v18->m_contact_p.x - v17->m_contact_p.x;
    v20 = v18->m_contact_p.y - v17->m_contact_p.y;
    contact_mata = v20 * v20 + v19 * v19;
    if ( contact_mata < 0.1156000047922134 )
      v2->m_list_contact_point_count = 1;
  }
  if ( v2->m_list_contact_point_count <= 0
    && _tlAssert("source/phys_contact_manifold.cpp", 254, "m_list_contact_point_count > 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v21 = v2->m_allocator;
  v22 = (contact_manifold_mesh_point **)v21->m_buffer_cur;
  v23 = g_contact_manifold_error_msg;
  v24 = (unsigned int)&v22[v2->m_list_contact_point_count];
  v21->m_buffer_cur = (char *)v24;
  if ( (char *)v24 > v21->m_buffer_end
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 122, "m_buffer_cur <= m_buffer_end", v23) )
  {
    __debugbreak();
  }
  if ( v2->m_list_contact_point != v22 )
  {
    if ( _tlAssert("source/phys_contact_manifold.cpp", 259, "m_list_contact_point == temp", (const char *)&pBlock) )
      __debugbreak();
  }
}

/*
==============
phys_contact_manifold_process::intersect_poly_poly
==============
*/
void __usercall phys_contact_manifold_process::intersect_poly_poly(phys_contact_manifold_process *this@<ecx>, int a2@<ebp>)
{
  phys_contact_manifold_process *v2; // esi
  phys_vec2 *v3; // edi
  phys_vec2 *v4; // edi
  contact_manifold_mesh_point **v5; // eax
  phys_contact_manifold *v6; // edi
  contact_manifold_mesh_point **v7; // edx
  contact_manifold_mesh_point *v8; // ecx
  double v9; // st7
  contact_manifold_mesh_point *v10; // eax
  double v11; // st7
  double v12; // st7
  contact_manifold_mesh_point **v13; // eax
  phys_contact_manifold *v14; // ecx
  int v15; // edi
  contact_manifold_mesh_point *v16; // eax
  int v17; // ecx
  double v18; // st7
  double v19; // st7
  phys_contact_manifold_process::isect_info *v20; // edi
  double v21; // st7
  unsigned int v22; // eax
  float v23; // ecx
  contact_manifold_mesh_point *v24; // edx
  bool v25; // sf
  phys_contact_manifold_process::bridge *v26; // edx
  double v27; // st7
  contact_manifold_mesh_point **v28; // eax
  double v29; // st6
  double v30; // st5
  double v31; // st5
  float v32; // edx
  contact_manifold_mesh_point **v33; // eax
  contact_manifold_mesh_point **v34; // edx
  contact_manifold_mesh_point *v35; // eax
  contact_manifold_mesh_point *v36; // edx
  double v37; // st6
  float v38; // edx
  int *v39; // eax
  int *v40; // edx
  int v41; // eax
  int v42; // edx
  double v43; // st6
  contact_manifold_mesh_point *v44; // eax
  int v45; // edx
  float v46; // eax
  phys_contact_manifold_process::isect_info *v47; // eax
  double v48; // st5
  double v49; // st7
  phys_vec3 *v50; // eax
  float *v51; // ecx
  double v52; // st7
  int v53; // eax
  char *v54; // edi
  const char *v55; // ecx
  unsigned int v56; // eax
  const char *v57; // ecx
  unsigned int v58; // eax
  bool v59; // zf
  phys_contact_manifold_process::isect_info *v60; // edi
  float v61; // ecx
  contact_manifold_mesh_point **v62; // eax
  contact_manifold_mesh_point *v63; // eax
  contact_manifold_mesh_point **v64; // edx
  int v65; // eax
  float v66; // ecx
  contact_manifold_mesh_point **v67; // ecx
  phys_contact_manifold_process::isect_info *v68; // eax
  contact_manifold_mesh_point *v69; // eax
  float v70; // ecx
  int v71; // eax
  char *v72; // edi
  const char *v73; // ecx
  unsigned int v74; // eax
  int v75; // [esp-28h] [ebp-9Ch]
  int v76; // [esp-Ch] [ebp-80h]
  contact_manifold_mesh_point **v77; // [esp-8h] [ebp-7Ch]
  int v78; // [esp-4h] [ebp-78h]
  phys_contact_manifold_process::isect_info gb_cman2; // [esp+0h] [ebp-74h]
  phys_contact_manifold_process::isect_info gb_cman1; // [esp+18h] [ebp-5Ch]
  float v81; // [esp+30h] [ebp-44h]
  float v82; // [esp+34h] [ebp-40h]
  float v83; // [esp+38h] [ebp-3Ch]
  contact_manifold_mesh_point **v84; // [esp+3Ch] [ebp-38h]
  float term_left_i; // [esp+40h] [ebp-34h]
  float v86; // [esp+44h] [ebp-30h]
  phys_contact_manifold_process::bridge *list_bridge; // [esp+48h] [ebp-2Ch]
  float v88; // [esp+4Ch] [ebp-28h]
  phys_contact_manifold_process::isect_info *left_gb; // [esp+50h] [ebp-24h]
  const int max_ctr; // [esp+54h] [ebp-20h]
  phys_vec2 vdisplace; // [esp+58h] [ebp-1Ch]
  contact_manifold_mesh_point **test_i; // [esp+60h] [ebp-14h]
  phys_contact_manifold_process::isect_info *right_gb; // [esp+64h] [ebp-10h]
  int ctr; // [esp+68h] [ebp-Ch]
  contact_manifold_mesh_point **left_i; // [esp+6Ch] [ebp-8h]
  contact_manifold_mesh_point **retaddr; // [esp+74h] [ebp+0h]

  ctr = a2;
  left_i = retaddr;
  v2 = this;
  if ( (this->cman1.m_list_contact_point_count < 2 || this->cman2.m_list_contact_point_count < 2)
    && _tlAssert(
         "source/phys_contact_manifold.cpp",
         367,
         "cman1.get_poly_vert_count() >= 2 && cman2.get_poly_vert_count() >= 2",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( v2->cman1.m_list_contact_point_count <= 2
    && v2->cman2.m_list_contact_point_count <= 2
    && _tlAssert(
         "source/phys_contact_manifold.cpp",
         368,
         "cman1.get_poly_vert_count() > 2 || cman2.get_poly_vert_count() > 2",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v2->m_list_isect_point = NULL;
  v2->m_contact_point_count = 0;
  if ( v2->cman1.m_list_contact_point_count == 2 )
  {
    if ( v2->cman1.m_list_contact_point_count <= 1
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_contact_manifold.h",
           256,
           "i >= 0 && i < m_list_contact_point_count",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v3 = (phys_vec2 *)(*((_DWORD *)v2->cman1.m_list_contact_point + 1) + 16);
    if ( v2->cman1.m_list_contact_point_count <= 0 )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_contact_manifold.h",
             256,
             "i >= 0 && i < m_list_contact_point_count",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    phys_contact_manifold_process::intersect_poly_segment(
      v2,
      &v2->cman2,
      &(*v2->cman1.m_list_contact_point)->m_contact_p,
      v3);
    return;
  }
  if ( v2->cman2.m_list_contact_point_count == 2 )
  {
    if ( v2->cman2.m_list_contact_point_count <= 1
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_contact_manifold.h",
           256,
           "i >= 0 && i < m_list_contact_point_count",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v4 = (phys_vec2 *)(*((_DWORD *)v2->cman2.m_list_contact_point + 1) + 16);
    if ( v2->cman2.m_list_contact_point_count <= 0
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_contact_manifold.h",
           256,
           "i >= 0 && i < m_list_contact_point_count",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    phys_contact_manifold_process::intersect_poly_segment(
      v2,
      &v2->cman1,
      &(*v2->cman2.m_list_contact_point)->m_contact_p,
      v4);
    return;
  }
  v5 = v2->cman1.m_list_contact_point;
  v6 = (phys_contact_manifold *)&v5[v2->cman1.m_list_contact_point_count - 1];
  v7 = (contact_manifold_mesh_point **)&v2->cman1;
  LODWORD(gb_cman2.m_edge.y) = v5 + 1;
  v8 = v5[1];
  v9 = v8->m_contact_p.x;
  LODWORD(gb_cman2.m_edge.x) = v5;
  v10 = *v5;
  v11 = v9 - v10->m_contact_p.x;
  gb_cman1.m_cman = v6;
  gb_cman2.m_last_i = (contact_manifold_mesh_point **)&v2->cman1;
  v88 = v11;
  v12 = v8->m_contact_p.y - v10->m_contact_p.y;
  *(float *)&gb_cman1.m_i = v88;
  v13 = v2->cman2.m_list_contact_point;
  *(float *)&left_gb = v12;
  gb_cman1.m_next_i = (contact_manifold_mesh_point **)left_gb;
  v76 = (int)&v2->cman2;
  v14 = (phys_contact_manifold *)&v13[v2->cman2.m_list_contact_point_count - 1];
  v15 = (int)(v13 + 1);
  v77 = v13;
  v16 = *v13;
  gb_cman2.m_cman = v14;
  v17 = *(_DWORD *)v15;
  v18 = *(float *)(*(_DWORD *)v15 + 16);
  v78 = v15;
  v19 = v18 - v16->m_contact_p.x;
  *(float *)&v20 = COERCE_FLOAT((phys_contact_manifold_process::isect_info *)((char *)&gb_cman2 + 12));
  v86 = COERCE_FLOAT((phys_contact_manifold_process::isect_info *)((char *)&gb_cman2 + 12));
  v88 = v19;
  v21 = *(float *)(v17 + 20) - v16->m_contact_p.y;
  *(float *)&gb_cman2.m_i = v88;
  right_gb = (phys_contact_manifold_process::isect_info *)g_contact_manifold_error_msg;
  *(float *)&left_gb = v21;
  v22 = (_DWORD)(v2->m_allocator.m_buffer_cur + 3) & 0xFFFFFFFC;
  gb_cman2.m_next_i = (contact_manifold_mesh_point **)left_gb;
  v23 = COERCE_FLOAT(&v76);
  LODWORD(vdisplace.x) = &v76;
  v2->m_allocator.m_buffer_cur = (char *)v22;
  if ( (char *)v22 >= v2->m_allocator.m_buffer_end )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           114,
           "m_buffer_cur < m_buffer_end",
           (const char *)right_gb) )
    {
      __debugbreak();
    }
    v7 = gb_cman2.m_last_i;
    v23 = vdisplace.x;
  }
  v24 = v7[20];
  v84 = (contact_manifold_mesh_point **)v2->m_allocator.m_buffer_cur;
  test_i = v84;
  v25 = (signed int)v24 + *(_DWORD *)(v76 + 80) < 0;
  v26 = (phys_contact_manifold_process::bridge *)((char *)v24 + *(_DWORD *)(v76 + 80));
  vdisplace.y = 0.0;
  list_bridge = v26;
  if ( !v25 )
  {
    v27 = 0.0;
    do
    {
      v28 = test_i;
      v29 = *(float *)(LODWORD(v23) + 20) * v20->m_edge.x;
      v30 = v20->m_edge.y;
      test_i[2] = (contact_manifold_mesh_point *)v20->m_i;
      v31 = v30 * *(float *)(LODWORD(v23) + 16);
      v28[3] = *(contact_manifold_mesh_point **)(LODWORD(v23) + 4);
      *(float *)&right_gb = v29 - v31;
      if ( *(float *)&right_gb < v27 )
      {
        v38 = *(float *)(LODWORD(v23) + 16);
        v83 = *(float *)(LODWORD(v23) + 20);
        v39 = *(int **)(LODWORD(v23) + 8);
        v82 = v38;
        *(_DWORD *)(LODWORD(v23) + 4) = v39;
        if ( v39 == *(int **)(LODWORD(v23) + 12) )
          v40 = *(int **)(*(_DWORD *)LODWORD(v23) + 76);
        else
          v40 = v39 + 1;
        v41 = *v39;
        *(_DWORD *)(LODWORD(v23) + 8) = v40;
        v42 = *v40;
        term_left_i = *(float *)(v42 + 16) - *(float *)(v41 + 16);
        v43 = *(float *)(v42 + 20) - *(float *)(v41 + 20);
        *(float *)(LODWORD(v23) + 16) = term_left_i;
        v86 = v43;
        *(float *)(LODWORD(v23) + 20) = v86;
      }
      else
      {
        v32 = v20->m_edge.y;
        v82 = v20->m_edge.x;
        v33 = v20->m_next_i;
        v83 = v32;
        v20->m_i = v33;
        if ( v33 == v20->m_last_i )
          v34 = v20->m_cman->m_list_contact_point;
        else
          v34 = v33 + 1;
        v35 = *v20->m_i;
        v20->m_next_i = v34;
        v36 = *v34;
        gb_cman1.m_edge.y = v36->m_contact_p.x - v35->m_contact_p.x;
        v37 = v36->m_contact_p.y - v35->m_contact_p.y;
        v20->m_edge.x = gb_cman1.m_edge.y;
        v81 = v37;
        v20->m_edge.y = v81;
      }
      v44 = *v20->m_i;
      v45 = **(_DWORD **)(LODWORD(v23) + 4);
      *(float *)&gb_cman1.m_last_i = *(float *)(v45 + 16) - v44->m_contact_p.x;
      gb_cman1.m_edge.x = *(float *)(v45 + 20) - v44->m_contact_p.y;
      *(float *)&right_gb = gb_cman1.m_edge.x * v82 - v83 * *(float *)&gb_cman1.m_last_i;
      if ( *(float *)&right_gb <= v27 )
      {
        if ( *(float *)&right_gb >= v27 )
        {
          v88 = -v83;
          *(float *)&right_gb = v82 * v82 + v88 * v88;
          *(float *)&right_gb = sqrt(*(float *)&right_gb);
          max_ctr = (const int)right_gb;
          if ( *(float *)&right_gb <= 0.00009999999747378752
            && _tlAssert("source/phys_contact_manifold.cpp", 431, "nvdisplace > 0.0001f", (const char *)&pBlock) )
          {
            __debugbreak();
          }
          v47 = **(phys_contact_manifold_process::isect_info ***)(LODWORD(vdisplace.x) + 4);
          *(float *)&right_gb = 0.03400000184774399 / *(float *)&max_ctr;
          v48 = *(float *)&right_gb;
          v49 = v88 * *(float *)&right_gb;
          right_gb = v47;
          v88 = v49;
          *(float *)&left_gb = v48 * v82;
          v47->m_edge.x = v47->m_edge.x + v88;
          v47->m_edge.y = *(float *)&left_gb + v47->m_edge.y;
          v50 = phys_v2_to_v3_multiply((phys_vec3 *)&v75, &v2->contact_mat, (phys_vec2 *)&v88);
          v51 = (float *)right_gb;
          *v51 = v50->x + *v51;
          v51[1] = v50->y + v51[1];
          v51[2] = v50->z + v51[2];
          v23 = vdisplace.x;
          v27 = 0.0;
        }
        else
        {
          if ( LODWORD(vdisplace.y) )
          {
            if ( ((char *)test_i < v2->m_allocator.m_buffer_start || (char *)(test_i + 4) > v2->m_allocator.m_buffer_end)
              && _tlAssert(
                   "source/phys_contact_manifold.cpp",
                   417,
                   "m_allocator.fast_is_within_buffer_limits(b_cur,sizeof(bridge))",
                   g_contact_manifold_error_msg) )
            {
              __debugbreak();
            }
            if ( !phys_contact_manifold_process::find_bottom(
                    (phys_contact_manifold_process::bridge *)test_i,
                    v20,
                    (phys_contact_manifold_process::isect_info *)LODWORD(vdisplace.x)) )
              return;
            test_i += 4;
            v27 = 0.0;
            v23 = vdisplace.x;
          }
          v46 = *(float *)&v20;
          *(float *)&v20 = v23;
          v23 = v46;
          vdisplace.x = v46;
        }
      }
      ++LODWORD(vdisplace.y);
    }
    while ( SLODWORD(vdisplace.y) <= (signed int)list_bridge );
    v86 = *(float *)&v20;
  }
  list_bridge = (phys_contact_manifold_process::bridge *)(((char *)test_i - (char *)v84) >> 4);
  if ( (signed int)list_bridge % 2 )
  {
    tlWarning("contact manifold intersect poly poly failed.\n");
    *(float *)&right_gb = phys_contact_manifold::compute_convex_poly_perimeter(&v2->cman1);
    v52 = phys_contact_manifold::compute_convex_poly_perimeter(&v2->cman2);
    v53 = (int)&v2->cman1;
    if ( *(float *)&right_gb > v52 )
      v53 = (int)&v2->cman2;
    goto LABEL_67;
  }
  v54 = v2->m_allocator.m_buffer_cur;
  v55 = g_contact_manifold_error_msg;
  v56 = (unsigned int)&v54[16 * (((char *)test_i - (char *)v84) >> 4)];
  v2->m_allocator.m_buffer_cur = (char *)v56;
  if ( (char *)v56 > v2->m_allocator.m_buffer_end
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 122, "m_buffer_cur <= m_buffer_end", v55) )
  {
    __debugbreak();
  }
  if ( v54 != (char *)v84
    && _tlAssert("source/phys_contact_manifold.cpp", 454, "temp_ptr == list_bridge", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !list_bridge )
  {
    v53 = *(_DWORD *)LODWORD(vdisplace.x);
LABEL_67:
    v2->m_list_isect_point = *(contact_manifold_mesh_point ***)(v53 + 76);
    v2->m_contact_point_count = *(_DWORD *)(v53 + 80);
    return;
  }
  v57 = g_contact_manifold_error_msg;
  v58 = (_DWORD)(v2->m_allocator.m_buffer_cur + 3) & 0xFFFFFFFC;
  v2->m_allocator.m_buffer_cur = (char *)v58;
  if ( (char *)v58 >= v2->m_allocator.m_buffer_end
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 114, "m_buffer_cur < m_buffer_end", v57) )
  {
    __debugbreak();
  }
  v59 = list_bridge == NULL;
  v25 = (signed int)list_bridge < 0;
  v60 = (phys_contact_manifold_process::isect_info *)v2->m_allocator.m_buffer_cur;
  v2->m_list_isect_point = (contact_manifold_mesh_point **)v60;
  *(float *)&right_gb = 0.0;
  if ( !v25 && !v59 )
  {
    LODWORD(vdisplace.y) = v84;
    do
    {
      if ( ((char *)v60 < v2->m_allocator.m_buffer_start || (char *)&v60->m_i > v2->m_allocator.m_buffer_end)
        && _tlAssert(
             "source/phys_contact_manifold.cpp",
             472,
             "m_allocator.fast_is_within_buffer_limits(ip_i,sizeof(contact_manifold_mesh_point*))",
             g_contact_manifold_error_msg) )
      {
        __debugbreak();
      }
      v61 = vdisplace.y;
      v60->m_cman = **(phys_contact_manifold ***)(LODWORD(vdisplace.y) + 8);
      v62 = v2->m_list_isect_point;
      for ( max_ctr = (const int)v62; v62 != (contact_manifold_mesh_point **)v60; max_ctr = (const int)v62 )
      {
        if ( *v62 == **(contact_manifold_mesh_point ***)(LODWORD(v61) + 8) )
        {
          tlWarning("contact manifold failure.");
          v62 = (contact_manifold_mesh_point **)max_ctr;
        }
        v61 = vdisplace.y;
        ++v62;
      }
      v63 = (contact_manifold_mesh_point *)v60->m_cman;
      v63->m_contact_p.x = *(float *)LODWORD(v61);
      v63->m_contact_p.y = *(float *)(LODWORD(v61) + 4);
      left_gb = (phys_contact_manifold_process::isect_info *)((char *)right_gb + 1);
      v60 = (phys_contact_manifold_process::isect_info *)((char *)v60 + 4);
      v64 = (contact_manifold_mesh_point **)v84[4 * (((signed int)&right_gb->m_cman + 1) % (signed int)list_bridge) + 3];
      v65 = *(_DWORD *)(LODWORD(vdisplace.y) + 8);
      v66 = *(float *)(LODWORD(v86) + 12);
      v83 = *(float *)&v84[4 * (((signed int)&right_gb->m_cman + 1) % (signed int)list_bridge) + 3];
      v81 = v66;
      if ( v65 == LODWORD(v66) )
        v67 = *(contact_manifold_mesh_point ***)(*(_DWORD *)LODWORD(v86) + 76);
      else
        v67 = (contact_manifold_mesh_point **)(v65 + 4);
      test_i = v67;
      if ( v67 != v64 )
      {
        max_ctr = (const int)&v60->m_i;
        do
        {
          if ( (char *)v60 < v2->m_allocator.m_buffer_start || (char *)max_ctr > v2->m_allocator.m_buffer_end )
          {
            if ( _tlAssert(
                   "source/phys_contact_manifold.cpp",
                   480,
                   "m_allocator.fast_is_within_buffer_limits(ip_i,sizeof(contact_manifold_mesh_point*))",
                   g_contact_manifold_error_msg) )
            {
              __debugbreak();
            }
            v67 = test_i;
          }
          v68 = (phys_contact_manifold_process::isect_info *)v2->m_list_isect_point;
          for ( right_gb = v68; v68 != v60; right_gb = v68 )
          {
            if ( (contact_manifold_mesh_point *)v68->m_cman == *v67 )
            {
              tlWarning("contact manifold failure.");
              v68 = right_gb;
              v67 = test_i;
            }
            v68 = (phys_contact_manifold_process::isect_info *)((char *)v68 + 4);
          }
          v69 = *v67;
          max_ctr += 4;
          v60->m_cman = (phys_contact_manifold *)v69;
          v60 = (phys_contact_manifold_process::isect_info *)((char *)v60 + 4);
          if ( v67 == (contact_manifold_mesh_point **)LODWORD(v81) )
            v67 = *(contact_manifold_mesh_point ***)(*(_DWORD *)LODWORD(v86) + 76);
          else
            ++v67;
          test_i = v67;
        }
        while ( v67 != (contact_manifold_mesh_point **)LODWORD(v83) );
      }
      v70 = vdisplace.x;
      LODWORD(vdisplace.y) += 16;
      vdisplace.x = v86;
      v86 = v70;
      right_gb = left_gb;
    }
    while ( (signed int)left_gb < (signed int)list_bridge );
  }
  v71 = ((char *)v60 - (char *)v2->m_list_isect_point) >> 2;
  v2->m_contact_point_count = v71;
  v72 = v2->m_allocator.m_buffer_cur;
  v73 = g_contact_manifold_error_msg;
  v74 = (unsigned int)&v72[4 * v71];
  v2->m_allocator.m_buffer_cur = (char *)v74;
  if ( (char *)v74 > v2->m_allocator.m_buffer_end
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 122, "m_buffer_cur <= m_buffer_end", v73) )
  {
    __debugbreak();
  }
  if ( v72 != (char *)v2->m_list_isect_point
    && _tlAssert("source/phys_contact_manifold.cpp", 494, "temp_ptr == m_list_isect_point", (const char *)&pBlock) )
  {
    __debugbreak();
  }
}

/*
==============
phys_contact_manifold::rht
==============
*/
bool phys_contact_manifold::rht(phys_vec2 *e1, phys_vec2 *e2, const float min_length2, const float min_sin_sq)
{
  phys_vec2 *v4; // edx
  double v5; // st7
  double v6; // st6
  bool result; // al
  float cra; // [esp+Ch] [ebp+Ch]
  float crb; // [esp+Ch] [ebp+Ch]
  float cr; // [esp+Ch] [ebp+Ch]
  float crc; // [esp+Ch] [ebp+Ch]

  v4 = e2;
  cra = e1->x * e2->y - e2->x * e1->y;
  v5 = cra;
  result = 0;
  if ( cra > 0.0 )
  {
    crb = e1->y * e1->y + e1->x * e1->x;
    v6 = crb;
    if ( min_length2 < (double)crb )
    {
      cr = v4->y * v4->y + v4->x * v4->x;
      if ( cr > (double)min_length2 )
      {
        crc = v5 * v5 / (v6 * cr);
        if ( min_sin_sq < (double)crc )
          result = 1;
      }
    }
  }
  return result;
}

