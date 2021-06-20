/*
==============
nuge::get_ballistic_info
==============
*/
void nuge::get_ballistic_info(rigid_body *const *list_rigid_body, const int rbodies_count, phys_vec3 *center_of_mass, phys_vec3 *total_momentum, float *total_mass)
{
  phys_vec3 *v5; // ecx
  phys_vec3 *v6; // eax
  int v7; // edx
  int v8; // edi
  double v9; // st7
  rigid_body *const *v10; // edi
  float *v11; // edx
  float v12; // ST4C_4
  float v13; // ST30_4
  float v14; // ST34_4
  float v15; // ST38_4
  float v16; // ST20_4
  float v17; // ST24_4
  float v18; // ST28_4
  float *v19; // edx
  float v20; // ST4C_4
  float v21; // ST30_4
  float v22; // ST34_4
  float v23; // ST38_4
  float v24; // ST20_4
  float v25; // ST24_4
  float v26; // ST28_4
  float *v27; // edx
  float v28; // ST4C_4
  float v29; // ST30_4
  float v30; // ST34_4
  float v31; // ST38_4
  float v32; // ST20_4
  float v33; // ST24_4
  float v34; // ST28_4
  float *v35; // edx
  float v36; // ST4C_4
  float v37; // ST30_4
  float v38; // ST34_4
  float v39; // ST38_4
  float v40; // ST20_4
  float v41; // ST24_4
  float v42; // ST28_4
  rigid_body *v43; // edx
  float v44; // ST4C_4
  float v45; // ST30_4
  float v46; // ST34_4
  float v47; // ST38_4
  float v48; // ST20_4
  float v49; // ST24_4
  float v50; // ST28_4
  float v51; // ST44_4
  int v52; // [esp-Ch] [ebp-18h]
  unsigned int v53; // [esp-8h] [ebp-14h]

  v5 = center_of_mass;
  if ( (unsigned __int8)center_of_mass & 0xF )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_math.h",
           444,
           "uint(v) % PHYS_ALIGNOF(phys_vec3) == 0",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v5 = center_of_mass;
  }
  v6 = total_momentum;
  if ( (unsigned __int8)total_momentum & 0xF )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_math.h",
           444,
           "uint(v) % PHYS_ALIGNOF(phys_vec3) == 0",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v5 = center_of_mass;
    v6 = total_momentum;
  }
  v7 = rbodies_count;
  v5->x = PHYS_ZERO_VEC_90.x;
  v8 = 0;
  v5->y = PHYS_ZERO_VEC_90.y;
  v5->z = PHYS_ZERO_VEC_90.z;
  v6->x = PHYS_ZERO_VEC_90.x;
  v6->y = PHYS_ZERO_VEC_90.y;
  v6->z = PHYS_ZERO_VEC_90.z;
  *total_mass = 0.0;
  v9 = 1.0;
  if ( rbodies_count >= 4 )
  {
    v53 = ((unsigned int)(rbodies_count - 4) >> 2) + 1;
    v10 = list_rigid_body + 2;
    v52 = 4 * v53;
    do
    {
      v11 = (float *)*((_DWORD *)v10 - 2);
      if ( v11 )
      {
        v12 = 1.0 / v11[60];
        v13 = v12 * v11[24];
        v14 = v11[25] * v12;
        v15 = v11[26] * v12;
        v5->x = v5->x + v13;
        v5->y = v5->y + v14;
        v5->z = v5->z + v15;
        v16 = v11[36] * v12;
        v17 = v11[37] * v12;
        v18 = v11[38] * v12;
        v6->x = v6->x + v16;
        v6->y = v6->y + v17;
        v6->z = v18 + v6->z;
        *total_mass = v12 + *total_mass;
      }
      v19 = (float *)*((_DWORD *)v10 - 1);
      if ( v19 )
      {
        v20 = 1.0 / v19[60];
        v21 = v20 * v19[24];
        v22 = v19[25] * v20;
        v23 = v19[26] * v20;
        v5->x = v5->x + v21;
        v5->y = v5->y + v22;
        v5->z = v5->z + v23;
        v24 = v19[36] * v20;
        v25 = v19[37] * v20;
        v26 = v19[38] * v20;
        v6->x = v6->x + v24;
        v6->y = v6->y + v25;
        v6->z = v26 + v6->z;
        *total_mass = v20 + *total_mass;
      }
      v27 = (float *)*v10;
      if ( *v10 )
      {
        v28 = 1.0 / v27[60];
        v29 = v28 * v27[24];
        v30 = v27[25] * v28;
        v31 = v27[26] * v28;
        v5->x = v5->x + v29;
        v5->y = v5->y + v30;
        v5->z = v5->z + v31;
        v32 = v27[36] * v28;
        v33 = v27[37] * v28;
        v34 = v27[38] * v28;
        v6->x = v6->x + v32;
        v6->y = v6->y + v33;
        v6->z = v34 + v6->z;
        *total_mass = v28 + *total_mass;
      }
      v35 = (float *)*((_DWORD *)v10 + 1);
      if ( v35 )
      {
        v36 = 1.0 / v35[60];
        v37 = v36 * v35[24];
        v38 = v35[25] * v36;
        v39 = v35[26] * v36;
        v5->x = v5->x + v37;
        v5->y = v5->y + v38;
        v5->z = v5->z + v39;
        v40 = v35[36] * v36;
        v41 = v35[37] * v36;
        v42 = v35[38] * v36;
        v6->x = v6->x + v40;
        v6->y = v6->y + v41;
        v6->z = v42 + v6->z;
        *total_mass = v36 + *total_mass;
      }
      v10 += 4;
      --v53;
    }
    while ( v53 );
    v8 = v52;
    v7 = rbodies_count;
  }
  if ( v8 < v7 )
  {
    do
    {
      v43 = list_rigid_body[v8];
      if ( v43 )
      {
        v44 = 1.0 / v43->m_inv_mass;
        v45 = v44 * v43->m_mat.w.x;
        v46 = v43->m_mat.w.y * v44;
        v47 = v43->m_mat.w.z * v44;
        v5->x = v5->x + v45;
        v5->y = v5->y + v46;
        v5->z = v5->z + v47;
        v48 = v43->m_t_vel.x * v44;
        v49 = v43->m_t_vel.y * v44;
        v50 = v43->m_t_vel.z * v44;
        v6->x = v6->x + v48;
        v6->y = v6->y + v49;
        v6->z = v50 + v6->z;
        *total_mass = v44 + *total_mass;
      }
      ++v8;
    }
    while ( v8 < rbodies_count );
  }
  if ( *total_mass <= 0.0000099999997 )
  {
    if ( _tlAssert("source/phys_util.cpp", 23, "*total_mass > 0.00001f", (const char *)&pBlock) )
      __debugbreak();
    v5 = center_of_mass;
    v9 = 1.0;
  }
  v51 = v9 / *total_mass;
  v5->x = v5->x * v51;
  v5->y = v5->y * v51;
  v5->z = v51 * v5->z;
}

/*
==============
nuge::apply_ballistic_target
==============
*/
void __usercall nuge::apply_ballistic_target(float a1@<ebp>, rigid_body *const *list_rigid_body, const int rbodies_count, phys_vec3 *target, float *const dist_sq)
{
  double v5; // st6
  double v6; // st7
  rigid_body *v7; // eax
  float v8; // edx
  float v9; // eax
  signed int v10; // ecx
  signed int v11; // edx
  float ddvs_4; // ST34_4
  double v13; // st6
  double v14; // st4
  float vt_8; // ST48_4
  double v16; // st5
  float v17; // ST28_4
  double v18; // st4
  double v19; // st2
  double v20; // st3
  double v21; // st4
  double v22; // st5
  double v23; // st4
  double v24; // st5
  int v25; // ecx
  int v26; // esi
  double v27; // st4
  double v28; // st6
  double v29; // st7
  unsigned int v30; // ecx
  rigid_body *const *v31; // eax
  int v32; // edx
  int v33; // edx
  int v34; // edx
  rigid_body *v35; // eax
  int v36; // esi
  rigid_body *v37; // ecx
  double vs_12; // [esp+3Ch] [ebp-84h]
  float v39; // [esp+44h] [ebp-7Ch]
  float v40; // [esp+48h] [ebp-78h]
  float v41; // [esp+4Ch] [ebp-74h]
  float dir_4; // [esp+54h] [ebp-6Ch]
  float dir_8; // [esp+58h] [ebp-68h]
  float dir_12; // [esp+5Ch] [ebp-64h]
  float total_velocity_4; // [esp+64h] [ebp-5Ch]
  float total_velocity_8; // [esp+68h] [ebp-58h]
  float total_velocity_12; // [esp+6Ch] [ebp-54h]
  float v48; // [esp+80h] [ebp-40h]
  float v49; // [esp+84h] [ebp-3Ch]
  float v50; // [esp+88h] [ebp-38h]
  float total_mass; // [esp+8Ch] [ebp-34h]
  phys_vec3 center_of_mass; // [esp+90h] [ebp-30h]
  phys_vec3 total_momentum; // [esp+A0h] [ebp-20h]
  const float delta_x; // [esp+B0h] [ebp-10h]
  const float B; // [esp+B4h] [ebp-Ch]
  float s_; // [esp+B8h] [ebp-8h]
  float retaddr; // [esp+C0h] [ebp+0h]

  B = a1;
  s_ = retaddr;
  nuge::get_ballistic_info(
    list_rigid_body,
    rbodies_count,
    (phys_vec3 *)&v49,
    (phys_vec3 *)((char *)&center_of_mass + 4),
    &v48);
  total_momentum.y = 1.0 / v48;
  dir_4 = center_of_mass.y * total_momentum.y;
  dir_8 = center_of_mass.z * total_momentum.y;
  dir_12 = total_momentum.y * center_of_mass.w;
  total_velocity_4 = target->x - v49;
  total_velocity_8 = target->y - v50;
  total_velocity_12 = target->z - total_mass;
  v5 = total_velocity_4 * total_velocity_4;
  *dist_sq = total_velocity_12 * total_velocity_12 + total_velocity_8 * total_velocity_8 + v5;
  total_momentum.y = total_velocity_12 * total_velocity_12 + v5;
  total_momentum.y = sqrt(total_momentum.y);
  v6 = total_momentum.y;
  if ( total_momentum.y >= 0.001 )
  {
    v7 = *list_rigid_body;
    center_of_mass.z = (*list_rigid_body)->m_gravity_acc_vec.y;
    center_of_mass.y = v7->m_gravity_acc_vec.x;
    v8 = v7->m_gravity_acc_vec.z;
    v9 = v7->m_gravity_acc_vec.w;
    v10 = 0;
    delta_x = center_of_mass.z * 0.5 * v6;
    total_momentum.x = v9;
    v11 = 0;
    total_momentum.z = total_velocity_8 / v6;
    total_momentum.y = 1.0 / v6;
    v39 = total_momentum.y * total_velocity_4;
    v40 = total_momentum.y * 0.0;
    v41 = total_momentum.y * total_velocity_12;
    total_momentum.w = 1.0;
    v13 = delta_x;
    vs_12 = -2.0 * delta_x;
    total_momentum.y = 0.0 - 0.0;
    center_of_mass.w = total_momentum.y;
    do
    {
      v14 = total_momentum.w;
      total_momentum.w = total_momentum.w * total_momentum.z - v13 / total_momentum.w;
      vt_8 = total_momentum.z + v13 / (v14 * v14);
      v16 = v14;
      v17 = vs_12 / (v14 * v14 * v14);
      ddvs_4 = v40 * dir_8 + v39 * dir_4 + v41 * dir_12;
      delta_x = v14 - ddvs_4;
      v18 = delta_x;
      v49 = delta_x;
      delta_x = total_momentum.w - dir_8;
      v50 = delta_x;
      total_mass = total_momentum.y;
      center_of_mass.y = v18;
      center_of_mass.z = delta_x;
      delta_x = vt_8 * delta_x + v49 + total_momentum.y * 0.0;
      v19 = delta_x;
      delta_x = center_of_mass.z * v17 + center_of_mass.y * 0.0 + total_momentum.y * 0.0;
      v20 = delta_x;
      delta_x = vt_8 * vt_8 + 1.0 + 0.0 * 0.0;
      delta_x = v20 + delta_x;
      delta_x = v16 - v19 / delta_x;
      v21 = delta_x - v16;
      v22 = delta_x;
      delta_x = v21;
      delta_x = fabs(delta_x);
      if ( delta_x < 0.001 )
        v11 = 1;
      ++v10;
      v23 = v22;
      total_momentum.w = v22;
    }
    while ( v10 <= 10 && !v11 );
    delta_x = fabs(v22);
    if ( delta_x >= 1.0 )
    {
      v24 = 0.0;
    }
    else
    {
      v24 = 0.0;
      if ( delta_x > 0.001 )
      {
        if ( v23 < 0.0 )
          total_momentum.w = -1.0;
        else
          total_momentum.w = 1.0;
      }
    }
    v25 = rbodies_count;
    v26 = 0;
    v27 = total_momentum.w * total_momentum.z - v13 / total_momentum.w;
    v28 = total_momentum.w;
    total_momentum.w = v27;
    center_of_mass.y = v39 * v28;
    center_of_mass.z = v40 * v28;
    center_of_mass.w = v28 * v41;
    v49 = center_of_mass.y + 0.0;
    v50 = center_of_mass.z + total_momentum.w;
    total_mass = center_of_mass.w + 0.0;
    total_momentum.z = v24;
    v29 = 1.0;
    if ( rbodies_count >= 4 )
    {
      v30 = ((unsigned int)(rbodies_count - 4) >> 2) + 1;
      v31 = list_rigid_body + 2;
      v26 = 4 * v30;
      do
      {
        v32 = *((_DWORD *)v31 - 2);
        if ( v32 )
        {
          total_momentum.w = *(float *)(v32 + 240);
          delta_x = total_momentum.w * total_momentum.w;
          total_momentum.z = 1.0 / delta_x + total_momentum.z;
        }
        v33 = *((_DWORD *)v31 - 1);
        if ( v33 )
        {
          total_momentum.w = *(float *)(v33 + 240);
          delta_x = total_momentum.w * total_momentum.w;
          total_momentum.z = 1.0 / delta_x + total_momentum.z;
        }
        if ( *v31 )
        {
          total_momentum.w = (*v31)->m_inv_mass;
          delta_x = total_momentum.w * total_momentum.w;
          total_momentum.z = 1.0 / delta_x + total_momentum.z;
        }
        v34 = *((_DWORD *)v31 + 1);
        if ( v34 )
        {
          total_momentum.w = *(float *)(v34 + 240);
          delta_x = total_momentum.w * total_momentum.w;
          total_momentum.z = 1.0 / delta_x + total_momentum.z;
        }
        v31 += 4;
        --v30;
      }
      while ( v30 );
      v25 = rbodies_count;
    }
    for ( ; v26 < v25; ++v26 )
    {
      v35 = list_rigid_body[v26];
      if ( v35 )
      {
        total_momentum.w = v35->m_inv_mass;
        delta_x = total_momentum.w * total_momentum.w;
        total_momentum.z = 1.0 / delta_x + total_momentum.z;
      }
    }
    if ( total_momentum.z <= 0.0000099999997 )
    {
      if ( _tlAssert("source/phys_util.cpp", 82, "total_square_mass > 0.00001f", (const char *)&pBlock) )
        __debugbreak();
      v25 = rbodies_count;
      v29 = 1.0;
    }
    v36 = 0;
    center_of_mass.y = v49 - dir_4;
    center_of_mass.z = v50 - dir_8;
    center_of_mass.w = total_mass - dir_12;
    delta_x = v48 / total_momentum.z;
    v49 = center_of_mass.y * delta_x;
    v50 = center_of_mass.z * delta_x;
    for ( total_mass = delta_x * center_of_mass.w; v36 < v25; ++v36 )
    {
      if ( list_rigid_body[v36] )
      {
        v37 = list_rigid_body[v36];
        delta_x = v37->m_inv_mass;
        delta_x = delta_x * delta_x;
        delta_x = v29 / delta_x;
        center_of_mass.y = delta_x * v49;
        center_of_mass.z = v50 * delta_x;
        center_of_mass.w = delta_x * total_mass;
        rigid_body::add_force(v37, (phys_vec3 *)((char *)&center_of_mass + 4));
        v29 = 1.0;
        v25 = rbodies_count;
      }
    }
  }
}

/*
==============
nuge::calc_velocities
==============
*/
void __usercall nuge::calc_velocities(float a1@<ebp>, phys_mat44 *mat0, phys_mat44 *mat1, const float delta_t, phys_vec3 *t_vel, phys_vec3 *a_vel)
{
  Phys_UnitQuaternion *v6; // eax
  float v7; // ecx
  float v8; // edx
  long double v9; // st7
  double v10; // st7
  double v11; // st6
  double v12; // st7
  double v13; // st6
  int v14; // [esp-Ch] [ebp-7Ch]
  phys_mat44 vel_mat; // [esp+0h] [ebp-70h]
  float v16; // [esp+44h] [ebp-2Ch]
  float v17; // [esp+48h] [ebp-28h]
  float v18; // [esp+4Ch] [ebp-24h]
  Phys_UnitQuaternion qvel; // [esp+50h] [ebp-20h]
  float v20; // [esp+60h] [ebp-10h]
  const float oo_delta_t; // [esp+64h] [ebp-Ch]
  const float nqvec; // [esp+68h] [ebp-8h]
  float retaddr; // [esp+70h] [ebp+0h]

  oo_delta_t = a1;
  nqvec = retaddr;
  if ( (unsigned __int8)t_vel & 0xF
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_math.h",
         444,
         "uint(v) % PHYS_ALIGNOF(phys_vec3) == 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (unsigned __int8)a_vel & 0xF
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_math.h",
         444,
         "uint(v) % PHYS_ALIGNOF(phys_vec3) == 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  qvel.z = 1.0 / delta_t;
  phys_transpose((phys_mat44 *)&v14, mat0);
  phys_multiply_mat((int)&oo_delta_t, (phys_mat44 *)&v14, mat1, (phys_mat44 *)&v14);
  v6 = Phys_GetQuaternion((Phys_UnitQuaternion *)&vel_mat.w.y, (phys_mat44 *)&v14);
  v7 = v6->y;
  v16 = v6->x;
  v8 = v6->z;
  qvel.x = v6->w;
  v17 = v7;
  v18 = v8;
  v9 = qvel.x;
  if ( qvel.x < 1.0 )
  {
    if ( v9 > -1.0 )
    {
      v20 = acos(v9);
      v10 = v20;
    }
    else
    {
      v10 = 3.1415927;
    }
  }
  else
  {
    v10 = 0.0;
  }
  v20 = v10;
  qvel.w = v17 * v17 + v16 * v16 + v18 * v18;
  qvel.w = sqrt(qvel.w);
  v11 = qvel.z;
  if ( qvel.w <= 0.00009999999747378752 )
  {
    v12 = qvel.z;
    a_vel->x = PHYS_ZERO_VEC_90.x;
    a_vel->y = PHYS_ZERO_VEC_90.y;
    v13 = PHYS_ZERO_VEC_90.z;
  }
  else
  {
    qvel.z = v20 + v20;
    v12 = v11;
    qvel.z = v11 / qvel.w * qvel.z;
    vel_mat.w.y = qvel.z * v16;
    vel_mat.w.z = v17 * qvel.z;
    vel_mat.w.w = qvel.z * v18;
    a_vel->x = vel_mat.w.y;
    a_vel->y = vel_mat.w.z;
    v13 = vel_mat.w.w;
  }
  a_vel->z = v13;
  vel_mat.w.y = mat1->w.x - mat0->w.x;
  vel_mat.w.z = mat1->w.y - mat0->w.y;
  vel_mat.w.w = mat1->w.z - mat0->w.z;
  v16 = vel_mat.w.y * v12;
  v17 = vel_mat.w.z * v12;
  v18 = v12 * vel_mat.w.w;
  t_vel->x = v16;
  t_vel->y = v17;
  t_vel->z = v18;
}

/*
==============
nuge::calc_velocities
==============
*/
void __usercall nuge::calc_velocities(int a1@<ebp>, phys_mat44 *mat0, phys_mat44 *mat1, phys_vec3 *center_offset_loc, const float delta_t, phys_vec3 *t_vel, phys_vec3 *a_vel)
{
  phys_vec3 *v7; // eax
  phys_vec3 *v8; // ecx
  double v9; // st7
  double v10; // st6
  phys_vec3 *v11; // eax
  int v12; // [esp+1Ch] [ebp-2Ch]
  float v13; // [esp+2Ch] [ebp-1Ch]
  float v14; // [esp+30h] [ebp-18h]
  float v15; // [esp+34h] [ebp-14h]
  int v16; // [esp+3Ch] [ebp-Ch]
  int v17; // [esp+40h] [ebp-8h]
  int retaddr; // [esp+48h] [ebp+0h]

  v16 = a1;
  v17 = retaddr;
  if ( (unsigned __int8)t_vel & 0xF
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_math.h",
         444,
         "uint(v) % PHYS_ALIGNOF(phys_vec3) == 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (unsigned __int8)a_vel & 0xF
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_math.h",
         444,
         "uint(v) % PHYS_ALIGNOF(phys_vec3) == 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  nuge::calc_velocities(COERCE_FLOAT(&v16), mat0, mat1, delta_t, t_vel, a_vel);
  v7 = phys_multiply((phys_vec3 *)&v12, mat1, center_offset_loc);
  v8 = a_vel;
  v13 = v7->z * v8->y - v7->y * v8->z;
  v14 = v8->z * v7->x - v8->x * v7->z;
  v9 = v7->y * a_vel->x;
  v10 = v7->x;
  v11 = t_vel;
  v15 = v9 - v10 * a_vel->y;
  v11->x = v11->x + v13;
  v11->y = v14 + v11->y;
  t_vel->z = t_vel->z + v15;
}

/*
==============
nuge::calc_sphere_inertia
==============
*/
void nuge::calc_sphere_inertia(const float radius, phys_vec3 *unit_inertia, float *volume)
{
  phys_vec3 *v3; // eax
  float d; // [esp+Ch] [ebp+Ch]
  float da; // [esp+Ch] [ebp+Ch]

  v3 = unit_inertia;
  if ( (unsigned __int8)unit_inertia & 0xF )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_math.h",
           444,
           "uint(v) % PHYS_ALIGNOF(phys_vec3) == 0",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v3 = unit_inertia;
  }
  d = 3.141592502593994 * radius * radius * radius * 4.0 / 3.0;
  *volume = d;
  da = (radius * (d * radius) + radius * (d * radius)) / 5.0;
  v3->x = da;
  v3->y = da;
  v3->z = da;
}

/*
==============
nuge::calc_box_inertia
==============
*/
void nuge::calc_box_inertia(phys_vec3 *dim, phys_vec3 *unit_inertia, float *volume)
{
  phys_vec3 *v3; // ecx
  phys_vec3 *v4; // eax
  float moments_4; // ST20_4
  float moments_8; // ST24_4
  float moments_12; // ST28_4
  float v8; // ST34_4
  float v9; // ST10_4
  float v10; // ST14_4
  float v11; // ST18_4
  float v12; // ST20_4
  float v13; // ST24_4
  float v14; // ST28_4

  v3 = unit_inertia;
  if ( (unsigned __int8)unit_inertia & 0xF )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_math.h",
           444,
           "uint(v) % PHYS_ALIGNOF(phys_vec3) == 0",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v3 = unit_inertia;
  }
  v4 = dim;
  *volume = v4->x * v4->y * v4->z;
  moments_4 = dim->x * dim->x;
  moments_8 = dim->y * dim->y;
  moments_12 = dim->z * dim->z;
  v8 = v4->x * 0.0833333358168602 * v4->y * v4->z;
  v9 = v8 * moments_4;
  v10 = moments_8 * v8;
  v11 = v8 * moments_12;
  v12 = v10 + v11;
  v13 = v11 + v9;
  v14 = v10 + v9;
  v3->x = v12;
  v3->y = v13;
  v3->z = v14;
}

/*
==============
nuge::calc_bound_sphere
==============
*/
void __usercall nuge::calc_bound_sphere(int a1@<ebp>, phys_vec3 *vert_list, const int vert_count, float *radius, phys_vec3 *com)
{
  int v5; // esi
  float *v6; // eax
  unsigned int v7; // ecx
  double v8; // st7
  float v9; // ST30_4
  float v10; // ST34_4
  float v11; // ST38_4
  float v12; // ST30_4
  float v13; // ST34_4
  float v14; // ST38_4
  float v15; // ST30_4
  float v16; // ST34_4
  float v17; // ST38_4
  float *v18; // eax
  int v19; // ecx
  double v20; // st7
  int v21; // esi
  double v22; // st7
  double v23; // st6
  double v24; // st5
  float *v25; // ecx
  unsigned int v26; // esi
  float v27; // ST20_4
  float v28; // ST24_4
  float v29; // ST28_4
  float v30; // ST20_4
  float v31; // ST24_4
  float v32; // ST28_4
  float v33; // ST20_4
  float v34; // ST24_4
  float v35; // ST28_4
  float v36; // ST20_4
  float v37; // ST24_4
  float v38; // ST28_4
  float *v39; // ecx
  int v40; // edx
  float v41; // ST20_4
  float v42; // ST24_4
  float v43; // ST28_4
  float v44; // ST48_4
  float v45; // [esp-Ch] [ebp-2Ch]
  float v46; // [esp-Ch] [ebp-2Ch]
  float v47; // [esp-8h] [ebp-28h]
  float v48; // [esp-8h] [ebp-28h]
  float v49; // [esp-4h] [ebp-24h]
  float v50; // [esp-4h] [ebp-24h]
  int dir3_com_12; // [esp+Ch] [ebp-14h]
  float v52; // [esp+10h] [ebp-10h]
  int v53; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  int retaddr; // [esp+20h] [ebp+0h]

  v53 = a1;
  i = retaddr;
  if ( (unsigned __int8)vert_list & 0xF
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_math.h",
         444,
         "uint(v) % PHYS_ALIGNOF(phys_vec3) == 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (unsigned __int8)com & 0xF
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_math.h",
         444,
         "uint(v) % PHYS_ALIGNOF(phys_vec3) == 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v49 = PHYS_ZERO_VEC_90.z;
  v45 = PHYS_ZERO_VEC_90.x;
  v5 = 0;
  v47 = PHYS_ZERO_VEC_90.y;
  if ( vert_count >= 4 )
  {
    v6 = &vert_list[1].z;
    v7 = ((unsigned int)(vert_count - 4) >> 2) + 1;
    v5 = 4 * v7;
    do
    {
      v8 = *(v6 - 6);
      v6 += 16;
      --v7;
      v9 = v8 + v45;
      v10 = *(v6 - 21) + v47;
      v11 = *(v6 - 20) + v49;
      v12 = *(v6 - 18) + v9;
      v13 = *(v6 - 17) + v10;
      v14 = *(v6 - 16) + v11;
      v15 = *(v6 - 14) + v12;
      v16 = *(v6 - 13) + v13;
      v17 = *(v6 - 12) + v14;
      v45 = *(v6 - 10) + v15;
      v47 = *(v6 - 9) + v16;
      v49 = *(v6 - 8) + v17;
    }
    while ( v7 );
  }
  if ( v5 < vert_count )
  {
    v18 = &vert_list[v5].z;
    v19 = vert_count - v5;
    do
    {
      v20 = *(v18 - 2);
      v18 += 4;
      --v19;
      v45 = v20 + v45;
      v47 = *(v18 - 5) + v47;
      v49 = *(v18 - 4) + v49;
    }
    while ( v19 );
  }
  v21 = 0;
  v52 = 1.0 / (double)vert_count;
  v46 = v52 * v45;
  v48 = v47 * v52;
  v50 = v52 * v49;
  *radius = 0.0;
  v22 = v50;
  v23 = v48;
  v24 = v46;
  if ( vert_count >= 4 )
  {
    v25 = &vert_list[1].z;
    v26 = ((unsigned int)(vert_count - 4) >> 2) + 1;
    dir3_com_12 = 4 * v26;
    do
    {
      v27 = *(v25 - 6) - v24;
      v28 = *(v25 - 5) - v23;
      v29 = *(v25 - 4) - v22;
      v52 = v28 * v28 + v27 * v27 + v29 * v29;
      if ( *radius < (double)v52 )
        *radius = v52;
      v30 = *(v25 - 2) - v24;
      v31 = *(v25 - 1) - v23;
      v32 = *v25 - v22;
      v52 = v31 * v31 + v30 * v30 + v32 * v32;
      if ( *radius < (double)v52 )
        *radius = v52;
      v33 = v25[2] - v24;
      v34 = v25[3] - v23;
      v35 = v25[4] - v22;
      v52 = v34 * v34 + v33 * v33 + v35 * v35;
      if ( *radius < (double)v52 )
        *radius = v52;
      v36 = v25[6] - v24;
      v37 = v25[7] - v23;
      v38 = v25[8] - v22;
      v52 = v37 * v37 + v36 * v36 + v38 * v38;
      if ( *radius < (double)v52 )
        *radius = v52;
      v25 += 16;
      --v26;
    }
    while ( v26 );
    v21 = dir3_com_12;
  }
  if ( v21 < vert_count )
  {
    v39 = &vert_list[v21].z;
    v40 = vert_count - v21;
    do
    {
      v41 = *(v39 - 2) - v24;
      v42 = *(v39 - 1) - v23;
      v43 = *v39 - v22;
      v52 = v42 * v42 + v41 * v41 + v43 * v43;
      if ( *radius < (double)v52 )
        *radius = v52;
      v39 += 4;
      --v40;
    }
    while ( v40 );
  }
  v44 = sqrt(*radius);
  *radius = v44;
  com->x = v46;
  com->y = v48;
  com->z = v50;
}

/*
==============
nuge::calc_bound_box
==============
*/
void __usercall nuge::calc_bound_box(float a1@<ebp>, phys_vec3 *vert_list, const int vert_count, phys_vec3 *dim, phys_vec3 *com)
{
  int v5; // edx
  phys_vec3 *v6; // ecx
  unsigned int v7; // esi
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  phys_vec3 *v12; // ecx
  int v13; // edi
  double v14; // st7
  float v15; // edx
  double v16; // st7
  double v17; // st6
  float v18; // ST20_4
  double v19; // st5
  double v20; // st4
  double v21; // st3
  double v22; // st2
  float v23; // ST20_4
  float v24; // [esp-8h] [ebp-38h]
  float v25; // [esp-4h] [ebp-34h]
  phys_vec3 v; // [esp+0h] [ebp-30h]
  phys_vec3 vmin; // [esp+10h] [ebp-20h]
  phys_vec3 vmax; // [esp+20h] [ebp-10h]
  float retaddr; // [esp+30h] [ebp+0h]

  vmax.y = a1;
  vmax.z = retaddr;
  if ( (unsigned __int8)vert_list & 0xF
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_math.h",
         444,
         "uint(v) % PHYS_ALIGNOF(phys_vec3) == 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (unsigned __int8)dim & 0xF
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_math.h",
         444,
         "uint(v) % PHYS_ALIGNOF(phys_vec3) == 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (unsigned __int8)com & 0xF
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_math.h",
         444,
         "uint(v) % PHYS_ALIGNOF(phys_vec3) == 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v.y = 10000000.0;
  v5 = 0;
  v.z = 10000000.0;
  v.w = 10000000.0;
  vmin.y = -10000000.0;
  vmin.z = -10000000.0;
  vmin.w = -10000000.0;
  if ( vert_count >= 4 )
  {
    v6 = vert_list + 2;
    v7 = ((unsigned int)(vert_count - 4) >> 2) + 1;
    v5 = 4 * v7;
    do
    {
      v8 = v6[-2].x;
      v24 = v6[-2].y;
      v25 = v6[-2].z;
      v.x = v6[-2].w;
      if ( v.y > v8 )
        v.y = v8;
      if ( vmin.y < v8 )
        vmin.y = v8;
      if ( v.z > (double)v24 )
        v.z = v24;
      if ( vmin.z < (double)v24 )
        vmin.z = v24;
      if ( v.w > (double)v25 )
        v.w = v25;
      if ( vmin.w < (double)v25 )
        vmin.w = v25;
      v9 = v6[-1].x;
      v24 = v6[-1].y;
      v25 = v6[-1].z;
      v.x = v6[-1].w;
      if ( v.y > v9 )
        v.y = v9;
      if ( vmin.y < v9 )
        vmin.y = v9;
      if ( v.z > (double)v24 )
        v.z = v24;
      if ( vmin.z < (double)v24 )
        vmin.z = v24;
      if ( v.w > (double)v25 )
        v.w = v25;
      if ( vmin.w < (double)v25 )
        vmin.w = v25;
      v10 = v6->x;
      v24 = v6->y;
      v25 = v6->z;
      v.x = v6->w;
      if ( v.y > v10 )
        v.y = v10;
      if ( vmin.y < v10 )
        vmin.y = v10;
      if ( v.z > (double)v24 )
        v.z = v24;
      if ( vmin.z < (double)v24 )
        vmin.z = v24;
      if ( v.w > (double)v25 )
        v.w = v25;
      if ( vmin.w < (double)v25 )
        vmin.w = v25;
      v11 = v6[1].x;
      v24 = v6[1].y;
      v25 = v6[1].z;
      v.x = v6[1].w;
      if ( v.y > v11 )
        v.y = v11;
      if ( vmin.y < v11 )
        vmin.y = v11;
      if ( v.z > (double)v24 )
        v.z = v24;
      if ( vmin.z < (double)v24 )
        vmin.z = v24;
      if ( v.w > (double)v25 )
        v.w = v25;
      if ( vmin.w < (double)v25 )
        vmin.w = v25;
      v6 += 4;
      --v7;
    }
    while ( v7 );
  }
  if ( v5 < vert_count )
  {
    v12 = &vert_list[v5];
    v13 = vert_count - v5;
    do
    {
      v14 = v12->x;
      v15 = v12->z;
      v24 = v12->y;
      v.x = v12->w;
      v25 = v15;
      if ( v.y > v14 )
        v.y = v14;
      if ( vmin.y < v14 )
        vmin.y = v14;
      if ( v.z > (double)v24 )
        v.z = v24;
      if ( vmin.z < (double)v24 )
        vmin.z = v24;
      if ( v.w > (double)v25 )
        v.w = v25;
      if ( vmin.w < (double)v25 )
        vmin.w = v25;
      ++v12;
      --v13;
    }
    while ( v13 );
  }
  v16 = vmin.y;
  v17 = v.y;
  v18 = vmin.y + v.y;
  v19 = vmin.z;
  v20 = v.z;
  v24 = vmin.z + v.z;
  v21 = vmin.w;
  v22 = v.w;
  v25 = vmin.w + v.w;
  v.y = v18 * 0.5;
  v.z = v24 * 0.5;
  v.w = 0.5 * v25;
  com->x = v.y;
  com->y = v.z;
  com->z = v.w;
  v23 = v16 - v17;
  v24 = v19 - v20;
  v25 = v21 - v22;
  dim->x = v23;
  dim->y = v24;
  dim->z = v25;
}

