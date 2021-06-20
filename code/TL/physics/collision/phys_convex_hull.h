/*
==============
phys_convex_hull::add_convex_hull_vert
==============
*/
void __thiscall phys_convex_hull::add_convex_hull_vert(phys_convex_hull *this, phys_vec3 **vert)
{
  phys_convex_hull *v2; // esi
  signed int v3; // eax
  phys_vec3 **v4; // eax
  int v5; // ecx

  v2 = this;
  if ( !vert
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\collision\\phys_convex_hull.h", 52, "vert", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v3 = v2->m_convex_hull_vert_list.m_alloc_count;
  if ( v3 < 128 )
  {
    v5 = (int)&v2->m_convex_hull_vert_list.m_slot_array[v3];
    v2->m_convex_hull_vert_list.m_alloc_count = v3 + 1;
    v4 = (phys_vec3 **)v5;
  }
  else
  {
    tlFatal("phys array add overflow.");
    v4 = NULL;
  }
  *v4 = *vert;
  phys_static_array<phys_vec3 *,6144>::remove(&v2->m_intermediate_vertex_list, vert);
}

/*
==============
phys_convex_hull::add_intermediate_edge
==============
*/
void __thiscall phys_convex_hull::add_intermediate_edge(phys_convex_hull *this, phys_vec3 *v0, phys_vec3 *v1)
{
  phys_convex_hull *v3; // edi
  phys_vec3 **v4; // esi
  int v5; // ecx
  signed int v6; // ecx
  phys_convex_hull::ch_edge *v7; // eax
  int v8; // eax
  phys_convex_hull::ch_edge *v9; // edi
  phys_convex_hull::ch_edge *v10; // eax

  v3 = this;
  if ( (!v0 || !v1 || v0 == v1)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_convex_hull.h",
         59,
         "v0 && v1 && v0 != v1",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v4 = v3->m_intermediate_edge_list.m_slot_array->m_verts;
  v5 = (int)&v4[2 * v3->m_intermediate_edge_list.m_alloc_count];
  if ( (phys_vec3 **)v5 == v4 )
  {
LABEL_12:
    v6 = v3->m_intermediate_edge_list.m_alloc_count;
    if ( v6 < 128 )
    {
      v10 = &v3->m_intermediate_edge_list.m_slot_array[v6];
      v3->m_intermediate_edge_list.m_alloc_count = v6 + 1;
      v10->m_verts[0] = v0;
      v10->m_verts[1] = v1;
    }
    else
    {
      tlFatal("phys array add overflow.");
      MEMORY[0] = (unsigned int)v0;
      MEMORY[4] = (unsigned int)v1;
    }
  }
  else
  {
    while ( (*v4 != v0 || v4[1] != v1) && (*v4 != v1 || v4[1] != v0) )
    {
      v4 += 2;
      if ( (phys_vec3 **)v5 == v4 )
        goto LABEL_12;
    }
    v7 = v3->m_intermediate_edge_list.m_slot_array;
    if ( (((_BYTE)v4 - (_BYTE)v7) & 7
       || v4 < (phys_vec3 **)v7
       || v4 >= v7[v3->m_intermediate_edge_list.m_alloc_count].m_verts)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_array_base.inc",
           73,
           "is_member(data)",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v8 = --v3->m_intermediate_edge_list.m_alloc_count;
    v9 = v3->m_intermediate_edge_list.m_slot_array;
    *v4 = v9[v8].m_verts[0];
    v4[1] = v9[v8].m_verts[1];
  }
}

/*
==============
phys_convex_hull::create_intermediate_triangle
==============
*/
void __userpurge phys_convex_hull::create_intermediate_triangle(phys_convex_hull *this@<ecx>, int a2@<ebp>, phys_vec3 *v0, phys_vec3 *v1, phys_vec3 *v2)
{
  int v5; // edx
  phys_convex_hull::ch_triangle *v6; // esi
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm0_4
  float v12; // xmm4_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // [esp+10h] [ebp-10h]
  int v17; // [esp+14h] [ebp-Ch]
  int v18; // [esp+18h] [ebp-8h]
  int retaddr; // [esp+20h] [ebp+0h]

  v17 = a2;
  v18 = retaddr;
  v5 = this->m_intermediate_triangle_list.m_alloc_count;
  if ( v5 < 256 )
  {
    v6 = &this->m_intermediate_triangle_list.m_slot_array[v5];
    this->m_intermediate_triangle_list.m_alloc_count = v5 + 1;
  }
  else
  {
    tlFatal("phys array add overflow.");
    v6 = NULL;
  }
  v6->m_verts[0] = v0;
  v6->m_verts[1] = v1;
  v6->m_verts[2] = v2;
  v7 = v1->y - v0->y;
  v8 = v1->z - v0->z;
  v9 = v2->y - v0->y;
  v10 = v2->z - v0->z;
  v11 = v1->x - v0->x;
  v12 = v2->x - v0->x;
  v13 = (float)(v7 * v10) - (float)(v8 * v9);
  v14 = (float)(v8 * v12) - (float)(v11 * v10);
  v15 = (float)(v11 * v9) - (float)(v7 * v12);
  v16 = fsqrt((float)((float)(v14 * v14) + (float)(v13 * v13)) + (float)(v15 * v15));
  if ( v16 <= 0.0000099999997
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_convex_hull.h",
         95,
         "nnormal > 0.00001f",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v6->m_normal.x = v13 * (float)(1.0 / v16);
  v6->m_normal.y = v14 * (float)(1.0 / v16);
  v6->m_normal.z = v15 * (float)(1.0 / v16);
}

/*
==============
phys_convex_hull::calculate_initial_triangle_vertices
==============
*/
void __usercall phys_convex_hull::calculate_initial_triangle_vertices(phys_convex_hull *this@<ecx>, float a2@<ebp>)
{
  phys_convex_hull *v2; // edi
  phys_vec3 **v3; // esi
  phys_vec3 **v4; // ecx
  int v5; // edi
  phys_vec3 **v6; // edx
  float *v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm5_4
  float v13; // xmm6_4
  int v14; // edx
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm5_4
  float v21; // xmm6_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  signed int v25; // ecx
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  float *v30; // eax
  int v31; // eax
  int v32; // esi
  signed int v33; // eax
  int v34; // esi
  int *v35; // eax
  int v36; // ecx
  phys_vec3 **v37; // esi
  phys_vec3 **v38; // ecx
  char v39; // al
  signed int v40; // eax
  phys_vec3 **v41; // eax
  int v42; // ecx
  phys_vec3 **v43; // ST0C_4
  signed int v44; // eax
  phys_vec3 **v45; // eax
  int v46; // ecx
  signed int v47; // eax
  _DWORD *v48; // eax
  int v49; // ecx
  phys_vec3 **v50; // ST0C_4
  float v51; // [esp-Ch] [ebp-4Ch]
  float v52; // [esp-4h] [ebp-44h]
  phys_vec3 **v53; // [esp+10h] [ebp-30h]
  unsigned int v54; // [esp+14h] [ebp-2Ch]
  unsigned int v55; // [esp+18h] [ebp-28h]
  phys_vec3 **best_verts[3]; // [esp+1Ch] [ebp-24h]
  float v57; // [esp+28h] [ebp-18h]
  phys_convex_hull *v58; // [esp+2Ch] [ebp-14h]
  phys_vec3 **z0; // [esp+30h] [ebp-10h]
  float largest_twice_area_sq; // [esp+34h] [ebp-Ch]
  int v61; // [esp+38h] [ebp-8h]
  int retaddr; // [esp+40h] [ebp+0h]

  largest_twice_area_sq = a2;
  v61 = retaddr;
  v2 = this;
  z0 = (phys_vec3 **)this->m_intermediate_vertex_list.m_alloc_count;
  v3 = NULL;
  v58 = this;
  v57 = 0.0;
  if ( (signed int)z0 - 2 <= 0 )
    goto LABEL_66;
  do
  {
    if ( ((signed int)v3 < 0 || (signed int)v3 >= v2->m_intermediate_vertex_list.m_alloc_count)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_array_base.inc",
           118,
           "i >= 0 && i < m_alloc_count",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v4 = &v2->m_intermediate_vertex_list.m_slot_array[(_DWORD)v3];
    v3 = (phys_vec3 **)((char *)v3 + 1);
    best_verts[2] = v4;
    best_verts[0] = v3;
    if ( (signed int)v3 < (signed int)z0 - 1 )
    {
      do
      {
        if ( ((signed int)v3 < 0 || (signed int)v3 >= v2->m_intermediate_vertex_list.m_alloc_count)
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_array_base.inc",
               118,
               "i >= 0 && i < m_alloc_count",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v5 = (int)&v2->m_intermediate_vertex_list.m_slot_array[(_DWORD)v3];
        v3 = (phys_vec3 **)((char *)v3 + 1);
        best_verts[1] = v3;
        if ( (signed int)v3 < (signed int)z0 )
        {
          do
          {
            if ( ((signed int)v3 < 0 || (signed int)v3 >= v58->m_intermediate_vertex_list.m_alloc_count)
              && _tlAssert(
                   "c:\\t6\\code\\tl\\physics\\include\\phys_array_base.inc",
                   118,
                   "i >= 0 && i < m_alloc_count",
                   (const char *)&pBlock) )
            {
              __debugbreak();
            }
            v6 = v58->m_intermediate_vertex_list.m_slot_array;
            v7 = &v6[(_DWORD)v3]->x;
            v8 = v7[1] - (*best_verts[2])->y;
            v9 = *(float *)(*(_DWORD *)v5 + 4) - (*best_verts[2])->y;
            v10 = v7[2] - (*best_verts[2])->z;
            v11 = *(float *)(*(_DWORD *)v5 + 8) - (*best_verts[2])->z;
            v12 = *v7 - **(float **)best_verts[2];
            v13 = **(float **)v5 - **(float **)best_verts[2];
            v14 = (int)&v6[(_DWORD)v3];
            v15 = (float)((float)((float)((float)(v11 * v12) - (float)(v10 * v13))
                                * (float)((float)(v11 * v12) - (float)(v10 * v13)))
                        + (float)((float)((float)(v9 * v10) - (float)(v11 * v8))
                                * (float)((float)(v9 * v10) - (float)(v11 * v8))))
                + (float)((float)((float)(v8 * v13) - (float)(v9 * v12)) * (float)((float)(v8 * v13) - (float)(v9 * v12)));
            if ( v15 > v57 )
            {
              v57 = v15;
              v53 = best_verts[2];
              v54 = v5;
              v55 = v14;
            }
            v3 = (phys_vec3 **)((char *)v3 + 1);
          }
          while ( (signed int)v3 < (signed int)z0 );
          v3 = best_verts[1];
        }
        v2 = v58;
      }
      while ( (signed int)v3 < (signed int)z0 - 1 );
      v3 = best_verts[0];
    }
  }
  while ( (signed int)v3 < (signed int)z0 - 2 );
  if ( v57 <= 0.0 )
  {
LABEL_66:
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_convex_hull.h",
           210,
           "largest_twice_area_sq>0.0f",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
  v16 = *(float *)(*(_DWORD *)v55 + 8) - (*v53)->z;
  v17 = *(float *)(*(_DWORD *)v55 + 4) - (*v53)->y;
  v18 = *(float *)(*(_DWORD *)v54 + 4) - (*v53)->y;
  v19 = *(float *)(*(_DWORD *)v54 + 8) - (*v53)->z;
  v20 = **(float **)v55 - (*v53)->x;
  v21 = **(float **)v54 - (*v53)->x;
  v22 = (float)(v18 * v16) - (float)(v19 * v17);
  v23 = (float)(v19 * v20) - (float)(v16 * v21);
  v24 = (float)(v17 * v21) - (float)(v18 * v20);
  best_verts[0] = COERCE_PHYS_VEC3___(fsqrt((float)((float)(v23 * v23) + (float)(v22 * v22)) + (float)(v24 * v24)));
  if ( *(float *)best_verts <= 0.0
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h", 85, "na > 0.0f", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v25 = v2->m_vertex_buffer.m_alloc_count;
  v26 = v24 * (float)(1.0 / *(float *)best_verts);
  v27 = (*v53)->x + (float)((float)(1.0 / *(float *)best_verts) * v22);
  v28 = (*v53)->y + (float)(v23 * (float)(1.0 / *(float *)best_verts));
  v29 = (*v53)->z + v26;
  v51 = (*v53)->x + (float)((float)(1.0 / *(float *)best_verts) * v22);
  v52 = (*v53)->z + v26;
  if ( v25 < 6144 )
  {
    v30 = &v2->m_vertex_buffer.m_slot_array[v25].x;
    v2->m_vertex_buffer.m_alloc_count = v25 + 1;
  }
  else
  {
    tlFatal("phys array add overflow.");
    v27 = v51;
    v29 = v52;
    v30 = NULL;
  }
  *v30 = v27;
  v30[1] = v28;
  v30[2] = v29;
  v31 = v2->m_vertex_buffer.m_alloc_count;
  v32 = v31 - 1;
  if ( (v31 - 1 < 0 || v32 >= v31)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_array_base.inc",
         118,
         "i >= 0 && i < m_alloc_count",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v33 = v2->m_intermediate_vertex_list.m_alloc_count;
  v34 = (int)&v2->m_vertex_buffer.m_slot_array[v32];
  if ( v33 < 6144 )
  {
    v36 = (int)&v2->m_intermediate_vertex_list.m_slot_array[v33];
    v2->m_intermediate_vertex_list.m_alloc_count = v33 + 1;
    v35 = (int *)v36;
  }
  else
  {
    tlFatal("phys array add overflow.");
    v35 = NULL;
  }
  *v35 = v34;
  do
  {
    while ( 1 )
    {
      v37 = (phys_vec3 **)v54;
      v38 = v53;
      v39 = 0;
      if ( (unsigned int)v53 < v54 )
      {
        v53 = (phys_vec3 **)v54;
        v54 = (unsigned int)v38;
        v39 = 1;
        v37 = v38;
      }
      if ( (unsigned int)v37 >= v55 )
        break;
      v54 = v55;
      v55 = (unsigned int)v37;
    }
  }
  while ( v39 );
  if ( !v53
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\collision\\phys_convex_hull.h", 52, "vert", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v40 = v2->m_convex_hull_vert_list.m_alloc_count;
  if ( v40 < 128 )
  {
    v42 = (int)&v2->m_convex_hull_vert_list.m_slot_array[v40];
    v2->m_convex_hull_vert_list.m_alloc_count = v40 + 1;
    v41 = (phys_vec3 **)v42;
  }
  else
  {
    tlFatal("phys array add overflow.");
    v41 = NULL;
  }
  v43 = v53;
  *v41 = *v53;
  phys_static_array<phys_vec3 *,6144>::remove(&v2->m_intermediate_vertex_list, v43);
  if ( !v37
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\collision\\phys_convex_hull.h", 52, "vert", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v44 = v2->m_convex_hull_vert_list.m_alloc_count;
  if ( v44 < 128 )
  {
    v46 = (int)&v2->m_convex_hull_vert_list.m_slot_array[v44];
    v2->m_convex_hull_vert_list.m_alloc_count = v44 + 1;
    v45 = (phys_vec3 **)v46;
  }
  else
  {
    tlFatal("phys array add overflow.");
    v45 = NULL;
  }
  *v45 = *v37;
  phys_static_array<phys_vec3 *,6144>::remove(&v2->m_intermediate_vertex_list, v37);
  if ( !v55
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\collision\\phys_convex_hull.h", 52, "vert", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v47 = v2->m_convex_hull_vert_list.m_alloc_count;
  if ( v47 < 128 )
  {
    v49 = (int)&v2->m_convex_hull_vert_list.m_slot_array[v47];
    v2->m_convex_hull_vert_list.m_alloc_count = v47 + 1;
    v48 = (_DWORD *)v49;
  }
  else
  {
    tlFatal("phys array add overflow.");
    v48 = NULL;
  }
  v50 = (phys_vec3 **)v55;
  *v48 = *(_DWORD *)v55;
  phys_static_array<phys_vec3 *,6144>::remove(&v2->m_intermediate_vertex_list, v50);
}

/*
==============
phys_convex_hull::init_convex_hull
==============
*/
void __usercall phys_convex_hull::init_convex_hull(phys_convex_hull *this@<ecx>, int a2@<ebp>)
{
  phys_convex_hull *v2; // esi
  phys_vec3 *v3; // edi
  int v4; // ebx
  signed int v5; // eax
  phys_vec3 **v6; // eax
  int v7; // ecx
  phys_vec3 **v8; // ebx
  phys_vec3 **v9; // edi
  phys_vec3 **v10; // edi
  phys_vec3 **v11; // ebx

  v2 = this;
  this->m_intermediate_vertex_list.m_alloc_count = 0;
  v3 = this->m_vertex_buffer.m_slot_array;
  v4 = (int)&v3[this->m_vertex_buffer.m_alloc_count];
  if ( (phys_vec3 *)v4 != v3 )
  {
    do
    {
      v5 = v2->m_intermediate_vertex_list.m_alloc_count;
      if ( v5 < 6144 )
      {
        v7 = (int)&v2->m_intermediate_vertex_list.m_slot_array[v5];
        v2->m_intermediate_vertex_list.m_alloc_count = v5 + 1;
        v6 = (phys_vec3 **)v7;
      }
      else
      {
        tlFatal("phys array add overflow.");
        v6 = NULL;
      }
      *v6 = v3;
      ++v3;
    }
    while ( v3 != (phys_vec3 *)v4 );
  }
  v2->m_convex_hull_vert_list.m_alloc_count = 0;
  v2->m_intermediate_triangle_list.m_alloc_count = 0;
  v2->m_convex_hull_triangle_list.m_alloc_count = 0;
  phys_convex_hull::calculate_initial_triangle_vertices(v2, *(float *)&a2);
  if ( v2->m_convex_hull_vert_list.m_alloc_count != 3
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_convex_hull.h",
         256,
         "m_convex_hull_vert_list.get_count() == 3",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( v2->m_convex_hull_vert_list.m_alloc_count <= 2
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_array_base.inc",
         118,
         "i >= 0 && i < m_alloc_count",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v8 = v2->m_convex_hull_vert_list.m_slot_array;
  if ( v2->m_convex_hull_vert_list.m_alloc_count <= 1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_array_base.inc",
         118,
         "i >= 0 && i < m_alloc_count",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v9 = v2->m_convex_hull_vert_list.m_slot_array;
  if ( v2->m_convex_hull_vert_list.m_alloc_count <= 0
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_array_base.inc",
         118,
         "i >= 0 && i < m_alloc_count",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  phys_convex_hull::create_intermediate_triangle(v2, a2, *v2->m_convex_hull_vert_list.m_slot_array, v9[1], v8[2]);
  if ( v2->m_convex_hull_vert_list.m_alloc_count <= 2
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_array_base.inc",
         118,
         "i >= 0 && i < m_alloc_count",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v10 = v2->m_convex_hull_vert_list.m_slot_array;
  if ( v2->m_convex_hull_vert_list.m_alloc_count <= 0
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_array_base.inc",
         118,
         "i >= 0 && i < m_alloc_count",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v11 = v2->m_convex_hull_vert_list.m_slot_array;
  if ( v2->m_convex_hull_vert_list.m_alloc_count <= 1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_array_base.inc",
         118,
         "i >= 0 && i < m_alloc_count",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  phys_convex_hull::create_intermediate_triangle(
    v2,
    a2,
    *((phys_vec3 **)v2->m_convex_hull_vert_list.m_slot_array + 1),
    *v11,
    v10[2]);
}

/*
==============
phys_convex_hull::calc_expansion_volume
==============
*/
double __thiscall phys_convex_hull::calc_expansion_volume(phys_convex_hull *this, phys_vec3 *vert)
{
  phys_convex_hull::ch_triangle *v2; // edx
  float v3; // xmm0_4
  int v4; // edi
  phys_vec3 *v5; // eax
  float v6; // xmm7_4
  float *v7; // ecx
  float *v8; // eax
  float *v9; // esi
  float v10; // xmm5_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm6_4
  float v17; // xmm5_4
  float v18; // xmm1_4
  float v20; // [esp+0h] [ebp-Ch]
  float v21; // [esp+4h] [ebp-8h]
  float volume; // [esp+8h] [ebp-4h]
  float verta; // [esp+14h] [ebp+8h]

  v2 = this->m_intermediate_triangle_list.m_slot_array;
  v3 = 0.0;
  v4 = (int)&v2[this->m_intermediate_triangle_list.m_alloc_count];
  volume = 0.0;
  if ( (phys_convex_hull::ch_triangle *)v4 == v2 )
    goto LABEL_12;
  v5 = vert;
  v6 = vert->x;
  verta = vert->y;
  v20 = v6;
  v21 = v5->z;
  do
  {
    v7 = &v2->m_verts[0]->x;
    if ( (float)((float)((float)(v2->m_normal.y * (float)(verta - v7[1])) + (float)(v2->m_normal.x * (float)(v6 - *v7)))
               + (float)(v2->m_normal.z * (float)(v21 - v7[2]))) > 0.034000002 )
    {
      v8 = &v2->m_verts[2]->x;
      v9 = &v2->m_verts[1]->x;
      v10 = v7[1] - v8[1];
      v11 = v7[2] - v8[2];
      v12 = v9[1] - v8[1];
      v13 = v9[2] - v8[2];
      v14 = *v9 - *v8;
      v15 = *v7 - *v8;
      v16 = (float)(v10 * v13) - (float)(v11 * v12);
      v17 = (float)(v15 * v12) - (float)(v14 * v10);
      v18 = (float)(v11 * v14) - (float)(v15 * v13);
      v6 = v20;
      v3 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                  (float)((float)((float)(verta - v8[1]) * v18) + (float)((float)(v20 - *v8) * v16))
                                + (float)((float)(v21 - v8[2]) * v17)) & _mask__AbsFloat_)
                 * 0.16666667)
         + volume;
      volume = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                      (float)((float)((float)(verta - v8[1]) * v18) + (float)((float)(v20 - *v8) * v16))
                                    + (float)((float)(v21 - v8[2]) * v17)) & _mask__AbsFloat_)
                     * 0.16666667)
             + volume;
    }
    ++v2;
  }
  while ( v2 != (phys_convex_hull::ch_triangle *)v4 );
  if ( v3 <= 0.0 )
  {
LABEL_12:
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_convex_hull.h",
           277,
           "volume > 0.0f",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
  return volume;
}

/*
==============
phys_convex_hull::create_edge_list
==============
*/
void __thiscall phys_convex_hull::create_edge_list(phys_convex_hull *this, phys_vec3 *vert)
{
  phys_convex_hull *v2; // edi
  phys_convex_hull::ch_triangle *v3; // esi
  phys_vec3 *v4; // eax

  v2 = this;
  this->m_intermediate_edge_list.m_alloc_count = 0;
  v3 = this->m_intermediate_triangle_list.m_slot_array;
  if ( &v3[this->m_intermediate_triangle_list.m_alloc_count] != v3 )
  {
    do
    {
      v4 = v3->m_verts[0];
      if ( (float)((float)((float)(v3->m_normal.y * (float)(vert->y - v4->y))
                         + (float)(v3->m_normal.x * (float)(vert->x - v4->x)))
                 + (float)(v3->m_normal.z * (float)(vert->z - v4->z))) <= 0.034000002 )
      {
        ++v3;
      }
      else
      {
        phys_convex_hull::add_intermediate_edge(v2, v4, v3->m_verts[1]);
        phys_convex_hull::add_intermediate_edge(v2, v3->m_verts[1], v3->m_verts[2]);
        phys_convex_hull::add_intermediate_edge(v2, v3->m_verts[2], v3->m_verts[0]);
        phys_static_array<phys_convex_hull::ch_triangle,256>::remove_slow(&v2->m_intermediate_triangle_list, v3);
      }
    }
    while ( &v2->m_intermediate_triangle_list.m_slot_array[v2->m_intermediate_triangle_list.m_alloc_count] != v3 );
  }
  if ( v2->m_intermediate_edge_list.m_alloc_count < 3
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_convex_hull.h",
         301,
         "m_intermediate_edge_list.get_count() >= 3",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
}

/*
==============
phys_convex_hull::remove_inside_verts
==============
*/
void __thiscall phys_convex_hull::remove_inside_verts(phys_convex_hull *this)
{
  phys_convex_hull *v1; // edx
  phys_vec3 **v2; // edi
  float v3; // xmm3_4
  phys_convex_hull::ch_triangle *v4; // eax
  int v5; // esi
  bool v6; // cl
  phys_convex_hull *v7; // [esp+4h] [ebp-4h]

  v1 = this;
  v2 = this->m_intermediate_vertex_list.m_slot_array;
  v7 = this;
  if ( &v2[this->m_intermediate_vertex_list.m_alloc_count] != v2 )
  {
    v3 = CONVEX_HULL_VERT_ADD_DIST_THRESH;
    do
    {
      v4 = v1->m_intermediate_triangle_list.m_slot_array;
      v5 = (int)&v4[v1->m_intermediate_triangle_list.m_alloc_count];
      v6 = 1;
      if ( (phys_convex_hull::ch_triangle *)v5 == v4 )
      {
LABEL_7:
        phys_static_array<phys_vec3 *,6144>::remove(&v1->m_intermediate_vertex_list, v2);
        v3 = CONVEX_HULL_VERT_ADD_DIST_THRESH;
        v1 = v7;
      }
      else
      {
        while ( v6 )
        {
          v6 = v3 >= (float)((float)((float)(v4->m_normal.y * (float)((*v2)->y - v4->m_verts[0]->y))
                                   + (float)(v4->m_normal.x * (float)((*v2)->x - v4->m_verts[0]->x)))
                           + (float)(v4->m_normal.z * (float)((*v2)->z - v4->m_verts[0]->z)));
          v1 = v7;
          ++v4;
          if ( (phys_convex_hull::ch_triangle *)v5 == v4 )
          {
            if ( v6 )
              goto LABEL_7;
            break;
          }
        }
        ++v2;
      }
    }
    while ( &v1->m_intermediate_vertex_list.m_slot_array[v1->m_intermediate_vertex_list.m_alloc_count] != v2 );
  }
}

/*
==============
phys_convex_hull::compute_convex_hull
==============
*/
void __thiscall phys_convex_hull::compute_convex_hull(phys_convex_hull *this, const int max_verts, const float min_expansion_volume_percent)
{
  phys_convex_hull *v3; // esi
  phys_convex_hull::ch_triangle *v4; // edi
  phys_vec3 **v5; // eax
  float v6; // xmm1_4
  int v7; // edx
  float v8; // xmm2_4
  float v9; // xmm4_4
  double v10; // st7
  float v11; // ST18_4
  signed int v12; // ecx
  int v13; // eax
  phys_vec3 *v14; // edx
  double v15; // st7
  phys_vec3 *v16; // ecx
  float v17; // xmm0_4
  phys_vec3 **v18; // edi
  signed int v19; // ecx
  unsigned int v20; // edi
  int v21; // eax
  int v22; // ecx
  double v23; // st7
  int v24; // ecx
  phys_convex_hull::ch_triangle *v25; // eax
  int v26; // eax
  int v27; // edx
  int v28; // ecx
  int v29; // edx
  phys_static_array<phys_convex_hull::ch_edge,128>::iterator edge_i_end; // [esp+8h] [ebp-18h]
  float total_volume; // [esp+Ch] [ebp-14h]
  phys_convex_hull::ch_triangle *best_tri; // [esp+10h] [ebp-10h]
  phys_vec3 **v33; // [esp+14h] [ebp-Ch]
  float best_volume; // [esp+18h] [ebp-8h]
  phys_vec3 **best_vert; // [esp+1Ch] [ebp-4h]
  int savedregs; // [esp+20h] [ebp+0h]

  v3 = this;
  if ( max_verts < 3
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_convex_hull.h",
         331,
         "max_verts >= 3",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  phys_convex_hull::init_convex_hull(v3, (int)&savedregs);
  total_volume = 0.0;
  while ( v3->m_convex_hull_vert_list.m_alloc_count < max_verts )
  {
    if ( v3->m_intermediate_triangle_list.m_alloc_count <= 0 )
      break;
    if ( v3->m_intermediate_vertex_list.m_alloc_count <= 0 )
      break;
    v4 = v3->m_intermediate_triangle_list.m_slot_array;
    best_tri = NULL;
    best_vert = NULL;
    best_volume = 0.0;
    if ( &v4[v3->m_intermediate_triangle_list.m_alloc_count] == v4 )
      break;
    do
    {
      v5 = v3->m_intermediate_vertex_list.m_slot_array;
      v6 = FLOAT_N1000000_0;
      v7 = (int)&v5[v3->m_intermediate_vertex_list.m_alloc_count];
      v33 = NULL;
      if ( (phys_vec3 **)v7 == v5 )
        goto LABEL_53;
      do
      {
        v8 = v4->m_normal.y;
        v9 = v4->m_normal.z;
        if ( (float)((float)((float)((*v5)->y * v8) + (float)((*v5)->x * v4->m_normal.x)) + (float)((*v5)->z * v9)) > v6 )
        {
          v33 = v5;
          v6 = (float)((float)((*v5)->y * v8) + (float)((*v5)->x * v4->m_normal.x)) + (float)((*v5)->z * v9);
        }
        ++v5;
      }
      while ( v5 != (phys_vec3 **)v7 );
      if ( !v33 )
      {
LABEL_53:
        if ( _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_convex_hull.h",
               118,
               "best_vert",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      if ( (float)((float)((float)((float)((*v33)->x - v4->m_verts[0]->x) * v4->m_normal.x)
                         + (float)(v4->m_normal.y * (float)((*v33)->y - v4->m_verts[0]->y)))
                 + (float)(v4->m_normal.z * (float)((*v33)->z - v4->m_verts[0]->z))) <= 0.034000002 )
      {
        v12 = v3->m_convex_hull_triangle_list.m_alloc_count;
        if ( v12 < 128 )
        {
          v13 = (int)&v3->m_convex_hull_triangle_list.m_slot_array[v12];
          v3->m_convex_hull_triangle_list.m_alloc_count = v12 + 1;
        }
        else
        {
          tlFatal("phys array add overflow.");
          v13 = 0;
        }
        v14 = v4->m_verts[0];
        *(float *)v13 = v4->m_normal.x;
        *(float *)(v13 + 4) = v4->m_normal.y;
        v15 = v4->m_normal.z;
        *(_DWORD *)(v13 + 16) = v14;
        v16 = v4->m_verts[1];
        *(float *)(v13 + 8) = v15;
        *(_DWORD *)(v13 + 20) = v16;
        *(_DWORD *)(v13 + 24) = v4->m_verts[2];
        phys_static_array<phys_convex_hull::ch_triangle,256>::remove_slow(&v3->m_intermediate_triangle_list, v4);
      }
      else
      {
        v10 = phys_convex_hull::calc_expansion_volume(v3, *v33);
        if ( v10 > best_volume )
        {
          best_tri = v4;
          best_vert = v33;
          v11 = v10;
          best_volume = v11;
        }
        ++v4;
      }
    }
    while ( &v3->m_intermediate_triangle_list.m_slot_array[v3->m_intermediate_triangle_list.m_alloc_count] != v4 );
    if ( !best_tri )
      break;
    if ( !best_vert
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_convex_hull.h",
           373,
           "best_vert",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( best_volume <= 0.0
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_convex_hull.h",
           374,
           "best_volume > 0.0f",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( (float)((float)((float)(best_tri->m_normal.y * (float)((*best_vert)->y - best_tri->m_verts[0]->y))
                       + (float)(best_tri->m_normal.x * (float)((*best_vert)->x - best_tri->m_verts[0]->x)))
               + (float)(best_tri->m_normal.z * (float)((*best_vert)->z - best_tri->m_verts[0]->z))) <= 0.034000002
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_convex_hull.h",
           375,
           "best_tri->get_dist(**best_vert) > CONVEX_HULL_VERT_ADD_DIST_THRESH",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v17 = total_volume <= 0.000099999997 ? FLOAT_100000_0 : best_volume / total_volume;
    if ( min_expansion_volume_percent > v17 )
      break;
    total_volume = best_volume + total_volume;
    phys_convex_hull::create_edge_list(v3, *best_vert);
    v18 = v3->m_intermediate_edge_list.m_slot_array->m_verts;
    edge_i_end.m_ptr = (phys_convex_hull::ch_edge *)&v18[2 * v3->m_intermediate_edge_list.m_alloc_count];
    if ( (phys_vec3 **)edge_i_end.m_ptr != v18 )
    {
      do
      {
        phys_convex_hull::create_intermediate_triangle(v3, (int)&savedregs, *best_vert, *v18, v18[1]);
        v18 += 2;
      }
      while ( v18 != (phys_vec3 **)edge_i_end.m_ptr );
    }
    phys_convex_hull::add_convex_hull_vert(v3, best_vert);
    phys_convex_hull::remove_inside_verts(v3);
  }
  for ( ; v3->m_intermediate_triangle_list.m_alloc_count > 0; *(_DWORD *)(v20 + 24) = v29 )
  {
    v19 = v3->m_convex_hull_triangle_list.m_alloc_count;
    v20 = (unsigned int)v3->m_intermediate_triangle_list.m_slot_array;
    if ( v19 < 128 )
    {
      v21 = (int)&v3->m_convex_hull_triangle_list.m_slot_array[v19];
      v3->m_convex_hull_triangle_list.m_alloc_count = v19 + 1;
    }
    else
    {
      tlFatal("phys array add overflow.");
      v21 = 0;
    }
    v22 = *(_DWORD *)(v20 + 16);
    *(float *)v21 = *(float *)v20;
    *(_DWORD *)(v21 + 16) = v22;
    v23 = *(float *)(v20 + 4);
    *(_DWORD *)(v21 + 20) = *(_DWORD *)(v20 + 20);
    *(float *)(v21 + 4) = v23;
    v24 = *(_DWORD *)(v20 + 24);
    *(float *)(v21 + 8) = *(float *)(v20 + 8);
    *(_DWORD *)(v21 + 24) = v24;
    v25 = v3->m_intermediate_triangle_list.m_slot_array;
    if ( (((_BYTE)v20 - (_BYTE)v25) & 0x1F
       || v20 < (unsigned int)v25
       || v20 >= (unsigned int)&v25[v3->m_intermediate_triangle_list.m_alloc_count])
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_array_base.inc",
           73,
           "is_member(data)",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v26 = (int)&v3->m_intermediate_triangle_list.m_slot_array[--v3->m_intermediate_triangle_list.m_alloc_count];
    v27 = *(_DWORD *)(v26 + 16);
    *(float *)v20 = *(float *)v26;
    *(_DWORD *)(v20 + 16) = v27;
    v28 = *(_DWORD *)(v26 + 20);
    *(float *)(v20 + 4) = *(float *)(v26 + 4);
    *(_DWORD *)(v20 + 20) = v28;
    v29 = *(_DWORD *)(v26 + 24);
    *(float *)(v20 + 8) = *(float *)(v26 + 8);
  }
}

