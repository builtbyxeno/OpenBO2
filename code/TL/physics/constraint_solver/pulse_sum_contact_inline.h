/*
==============
pulse_sum_contact_point::get_vel
==============
*/
phys_vec3 *__userpurge pulse_sum_contact_point::get_vel@<eax>(pulse_sum_contact_point *this@<ecx>, float a2@<ebp>, phys_vec3 *result, pulse_sum_contact *psc)
{
  rigid_body *v4; // eax
  float *v5; // esi
  rigid_body *v6; // eax
  double v7; // st7
  phys_vec3 *v8; // eax
  double v9; // st6
  double v10; // st5
  double v11; // st7
  float v12; // [esp-2Ch] [ebp-3Ch]
  float v13; // [esp-28h] [ebp-38h]
  float v14; // [esp-24h] [ebp-34h]
  float v15; // [esp-1Ch] [ebp-2Ch]
  float v16; // [esp-18h] [ebp-28h]
  float v17; // [esp-14h] [ebp-24h]
  float v18; // [esp-Ch] [ebp-1Ch]
  float v19; // [esp-8h] [ebp-18h]
  float v20; // [esp-4h] [ebp-14h]
  phys_vec3 retv; // [esp+0h] [ebp-10h]
  float retaddr; // [esp+10h] [ebp+0h]

  retv.y = a2;
  retv.z = retaddr;
  if ( psc->m_b2 )
  {
    v4 = psc->m_b2->m_rb;
    v5 = &v12;
    v18 = this->m_b2_r.z * v4->m_a_vel.y - this->m_b2_r.y * v4->m_a_vel.z;
    v19 = this->m_b2_r.x * v4->m_a_vel.z - this->m_b2_r.z * v4->m_a_vel.x;
    v20 = v4->m_a_vel.x * this->m_b2_r.y - v4->m_a_vel.y * this->m_b2_r.x;
    v12 = v4->m_t_vel.x + v18;
    v13 = v4->m_t_vel.y + v19;
    v14 = v4->m_t_vel.z + v20;
  }
  else
  {
    v5 = &this->m_b2_ap_n.x;
  }
  v6 = psc->m_b1->m_rb;
  v18 = v6->m_a_vel.y * this->m_b1_r.z - v6->m_a_vel.z * this->m_b1_r.y;
  v19 = v6->m_a_vel.z * this->m_b1_r.x - v6->m_a_vel.x * this->m_b1_r.z;
  v20 = this->m_b1_r.y * v6->m_a_vel.x - v6->m_a_vel.y * this->m_b1_r.x;
  v15 = v6->m_t_vel.x + v18;
  v16 = v6->m_t_vel.y + v19;
  v7 = v6->m_t_vel.z;
  v8 = result;
  v17 = v7 + v20;
  v18 = v15 - *v5;
  v19 = v16 - v5[1];
  v20 = v17 - v5[2];
  v9 = v19;
  v10 = v18;
  v11 = v20;
  result->x = psc->m_ud_n.z * v20 + psc->m_ud_n.y * v19 + v18 * psc->m_ud_n.x;
  result->y = psc->m_ud_f1.y * v9 + psc->m_ud_f1.x * v10 + psc->m_ud_f1.z * v11;
  result->z = v11 * psc->m_ud_f2.z + v9 * psc->m_ud_f2.y + v10 * psc->m_ud_f2.x;
  return v8;
}

/*
==============
pulse_sum_contact_point::get_pos
==============
*/
double __userpurge pulse_sum_contact_point::get_pos@<st0>(pulse_sum_contact_point *this@<ecx>, int a2@<ebp>, pulse_sum_contact *psc)
{
  pulse_sum_node *v3; // eax
  float *v4; // eax
  float *v5; // edx
  rigid_body *v6; // eax
  float v8; // [esp-40h] [ebp-4Ch]
  float v9; // [esp-3Ch] [ebp-48h]
  float v10; // [esp-38h] [ebp-44h]
  float v11; // [esp-30h] [ebp-3Ch]
  float v12; // [esp-2Ch] [ebp-38h]
  float v13; // [esp-28h] [ebp-34h]
  float v14; // [esp-20h] [ebp-2Ch]
  float v15; // [esp-1Ch] [ebp-28h]
  float v16; // [esp-18h] [ebp-24h]
  int v18; // [esp+0h] [ebp-Ch]
  int v19; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v18 = a2;
  v19 = retaddr;
  v3 = psc->m_b2;
  if ( v3 )
  {
    v4 = &v3->m_rb->m_last_position.x;
    v5 = &v8;
    v8 = v4[24] + this->m_b2_r.x;
    v9 = this->m_b2_r.y + v4[25];
    v10 = this->m_b2_r.z + v4[26];
  }
  else
  {
    v5 = &this->m_b2_r.x;
  }
  v6 = psc->m_b1->m_rb;
  v14 = this->m_b1_r.x + v6->m_mat.w.x;
  v15 = v6->m_mat.w.y + this->m_b1_r.y;
  v16 = v6->m_mat.w.z + this->m_b1_r.z;
  v11 = v14 - *v5;
  v12 = v15 - v5[1];
  v13 = v16 - v5[2];
  return (float)(psc->m_ud_n.y * v12 + psc->m_ud_n.x * v11 + psc->m_ud_n.z * v13);
}

/*
==============
pulse_sum_contact_point::get_impact_vel
==============
*/
double __userpurge pulse_sum_contact_point::get_impact_vel@<st0>(pulse_sum_contact_point *this@<ecx>, int a2@<ebp>, pulse_sum_contact *psc)
{
  pulse_sum_node *v3; // edi
  float *v4; // eax
  float *v5; // esi
  rigid_body *v6; // eax
  float *v7; // eax
  float *v8; // esi
  rigid_body *v9; // eax
  float v11; // [esp-1Ch] [ebp-5Ch]
  float v12; // [esp-18h] [ebp-58h]
  float v13; // [esp-14h] [ebp-54h]
  float v14; // [esp-Ch] [ebp-4Ch]
  float v15; // [esp-8h] [ebp-48h]
  float v16; // [esp-4h] [ebp-44h]
  phys_vec3 lv; // [esp+0h] [ebp-40h]
  phys_vec3 v; // [esp+10h] [ebp-30h]
  float v19; // [esp+2Ch] [ebp-14h]
  float v20; // [esp+30h] [ebp-10h]
  int v21; // [esp+34h] [ebp-Ch]
  int v22; // [esp+38h] [ebp-8h]
  int retaddr; // [esp+40h] [ebp+0h]

  v21 = a2;
  v22 = retaddr;
  v3 = psc->m_b2;
  if ( v3 )
  {
    v4 = &v3->m_rb->m_last_position.x;
    v5 = &v11;
    v.y = this->m_b2_r.z * v4[49] - this->m_b2_r.y * v4[50];
    v.z = this->m_b2_r.x * v4[50] - this->m_b2_r.z * v4[48];
    v.w = this->m_b2_r.y * v4[48] - v4[49] * this->m_b2_r.x;
    v11 = v4[44] + v.y;
    v12 = v4[45] + v.z;
    v13 = v4[46] + v.w;
  }
  else
  {
    v5 = &this->m_b2_ap_n.x;
  }
  v6 = psc->m_b1->m_rb;
  v.y = v6->m_last_a_vel.y * this->m_b1_r.z - v6->m_last_a_vel.z * this->m_b1_r.y;
  v.z = v6->m_last_a_vel.z * this->m_b1_r.x - this->m_b1_r.z * v6->m_last_a_vel.x;
  v.w = this->m_b1_r.y * v6->m_last_a_vel.x - v6->m_last_a_vel.y * this->m_b1_r.x;
  lv.y = v6->m_last_t_vel.x + v.y;
  lv.z = v6->m_last_t_vel.y + v.z;
  lv.w = v6->m_last_t_vel.z + v.w;
  v14 = lv.y - *v5;
  v15 = lv.z - v5[1];
  v16 = lv.w - v5[2];
  if ( v3 )
  {
    v7 = &v3->m_rb->m_last_position.x;
    v8 = &v11;
    lv.y = this->m_b2_r.z * v7[41] - this->m_b2_r.y * v7[42];
    lv.z = this->m_b2_r.x * v7[42] - this->m_b2_r.z * v7[40];
    lv.w = this->m_b2_r.y * v7[40] - v7[41] * this->m_b2_r.x;
    v11 = lv.y + v7[36];
    v12 = v7[37] + lv.z;
    v13 = v7[38] + lv.w;
  }
  else
  {
    v8 = &this->m_b2_ap_n.x;
  }
  v9 = psc->m_b1->m_rb;
  lv.y = this->m_b1_r.z * v9->m_a_vel.y - this->m_b1_r.y * v9->m_a_vel.z;
  lv.z = this->m_b1_r.x * v9->m_a_vel.z - v9->m_a_vel.x * this->m_b1_r.z;
  lv.w = this->m_b1_r.y * v9->m_a_vel.x - this->m_b1_r.x * v9->m_a_vel.y;
  v.y = v9->m_t_vel.x + lv.y;
  v.z = v9->m_t_vel.y + lv.z;
  v.w = v9->m_t_vel.z + lv.w;
  lv.y = v.y - *v8;
  lv.z = v.z - v8[1];
  lv.w = v.w - v8[2];
  v19 = psc->m_ud_n.x * lv.y + psc->m_ud_n.y * lv.z + psc->m_ud_n.z * lv.w;
  v20 = psc->m_ud_n.x * v14 + psc->m_ud_n.y * v15 + psc->m_ud_n.z * v16;
  if ( v19 >= (double)v20 )
    v20 = v19;
  return v20;
}

/*
==============
pulse_sum_contact::set
==============
*/
void __userpurge pulse_sum_contact::set(pulse_sum_contact *this@<ecx>, phys_vec3 *a2@<ebp>, rigid_body *const b1, rigid_body *const b2, contact_point_info *cpi, const float delta_t)
{
  pulse_sum_contact *v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // eax
  float *v9; // esi
  phys_vec3 *v10; // eax
  int v11; // eax
  rigid_body *v12; // eax
  float v13; // ecx
  float v14; // edx
  float v15; // eax
  double v16; // st7
  double v17; // st5
  phys_vec3 *v18; // ecx
  phys_vec3 *v19; // edx
  double v20; // st7
  pulse_sum_contact_point *v21; // esi
  phys_vec3 *v22; // edx
  double v23; // st7
  rigid_body *v24; // eax
  double v25; // st7
  double v26; // st6
  double v27; // st5
  bool v28; // zf
  float v29; // [esp+24h] [ebp-7Ch]
  float v30; // [esp+28h] [ebp-78h]
  float v31; // [esp+2Ch] [ebp-74h]
  float v32; // [esp+34h] [ebp-6Ch]
  float v33; // [esp+38h] [ebp-68h]
  float v34; // [esp+3Ch] [ebp-64h]
  float v35; // [esp+44h] [ebp-5Ch]
  float v36; // [esp+48h] [ebp-58h]
  float v37; // [esp+4Ch] [ebp-54h]
  float v38; // [esp+54h] [ebp-4Ch]
  float v39; // [esp+58h] [ebp-48h]
  float v40; // [esp+5Ch] [ebp-44h]
  float v41; // [esp+64h] [ebp-3Ch]
  float v42; // [esp+68h] [ebp-38h]
  float v43; // [esp+6Ch] [ebp-34h]
  phys_vec3 b2_r; // [esp+70h] [ebp-30h]
  phys_mat44 *v45; // [esp+80h] [ebp-20h]
  float v46; // [esp+84h] [ebp-1Ch]
  const float min_restitution_impact_vel_sq; // [esp+88h] [ebp-18h]
  phys_vec3 *v48; // [esp+8Ch] [ebp-14h]
  int pp_i; // [esp+90h] [ebp-10h]
  phys_vec3 *b2_r_loc; // [esp+94h] [ebp-Ch]
  phys_vec3 *b1_r_loc; // [esp+98h] [ebp-8h]
  phys_vec3 *retaddr; // [esp+A0h] [ebp+0h]

  b2_r_loc = a2;
  b1_r_loc = retaddr;
  v6 = this;
  if ( !b1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_contact_inline.h",
         236,
         "b1",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !b2
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_contact_inline.h",
         237,
         "b2",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( b1 == b2
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_contact_inline.h",
         238,
         "b1 != b2",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( b1->m_node )
    goto LABEL_41;
  if ( !b2->m_node
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_contact_inline.h",
         239,
         "rbint::get_pulse_sum_node(b1) || rbint::get_pulse_sum_node(b2)",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( b1->m_node )
LABEL_41:
    v7 = (b1->m_flags & 0x30) == 0;
  else
    v7 = b1->m_flags & 0x30;
  if ( !v7 || (!b2->m_node ? (v8 = b2->m_flags & 0x30) : (v8 = (b2->m_flags & 0x30) == 0), !v8) )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_contact_inline.h",
           240,
           "rbint::verify_pulse_sum_node(b1) && rbint::verify_pulse_sum_node(b2)",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
  if ( !b1->m_node
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_contact_inline.h",
         242,
         "rbint::get_pulse_sum_node(b1) != NULL",
         "b1 in contact constraint cannot be environment or user rigid body.") )
  {
    __debugbreak();
  }
  v6->m_b1 = b1->m_node;
  v6->m_b2 = b2->m_node;
  v9 = &v6->m_ud_n.x;
  *v9 = cpi->m_normal.x;
  v9[1] = cpi->m_normal.y;
  v9[2] = cpi->m_normal.z;
  v10 = construct_orth_ud((phys_vec3 *)&v29, &v6->m_ud_n);
  v6->m_ud_f1.x = v10->x;
  v6->m_ud_f1.y = v10->y;
  v6->m_ud_f1.z = v10->z;
  v41 = v6->m_ud_n.y * v6->m_ud_f1.z - v6->m_ud_n.z * v6->m_ud_f1.y;
  v42 = v6->m_ud_f1.x * v6->m_ud_n.z - v6->m_ud_f1.z * v6->m_ud_n.x;
  v43 = v6->m_ud_f1.y * v6->m_ud_n.x - v6->m_ud_f1.x * v6->m_ud_n.y;
  v6->m_ud_f2.x = v41;
  v6->m_ud_f2.y = v42;
  v6->m_ud_f2.z = v43;
  v11 = v6->m_list_pscp_count;
  v6->m_fric_coef = cpi->m_fric_coef;
  v6->m_pulse_sum_cache_list = cpi->m_list_pulse_sum_cache_info;
  if ( v11 != cpi->m_point_pair_count
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_contact_inline.h",
         251,
         "m_list_pscp_count == cpi->m_point_pair_count",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v12 = v6->m_b1->m_rb;
  v13 = v12->m_gravity_acc_vec.y;
  v41 = v12->m_gravity_acc_vec.x;
  v14 = v12->m_gravity_acc_vec.z;
  v15 = v12->m_gravity_acc_vec.w;
  v42 = v13;
  v16 = v13;
  v43 = v14;
  v17 = v14;
  v18 = cpi->m_list_b1_r_loc;
  v19 = cpi->m_list_b2_r_loc;
  b2_r.x = v15;
  v48 = v18;
  min_restitution_impact_vel_sq = *(float *)&v19;
  v46 = v16 * v16 + v41 * v41 + v17 * v17;
  v20 = v46;
  v46 = 0.0;
  b2_r.w = v20 * 0.09000000357627869;
  if ( cpi->m_point_pair_count > 0 )
  {
    v45 = &b1->m_mat;
    pp_i = 0;
    do
    {
      v21 = &v6->m_list_pscp[pp_i / 0xD0u];
      phys_multiply((phys_vec3 *)&v29, v45, v48);
      v22 = (phys_vec3 *)LODWORD(min_restitution_impact_vel_sq);
      v21->m_b1_r.x = v29;
      v21->m_b1_r.y = v30;
      v21->m_b1_r.z = v31;
      phys_multiply((phys_vec3 *)&v41, &b2->m_mat, v22);
      if ( v6->m_b2 )
      {
        v21->m_b2_r.x = v41;
        v21->m_b2_r.y = v42;
        v23 = v43;
      }
      else
      {
        v24 = b2;
        v25 = v43;
        v26 = v42;
        v38 = v43 * v24->m_a_vel.y - v24->m_a_vel.z * v42;
        v27 = v41;
        v39 = v24->m_a_vel.z * v41 - v24->m_a_vel.x * v43;
        v40 = b2->m_a_vel.x * v42 - b2->m_a_vel.y * v41;
        v35 = v38 + b2->m_t_vel.x;
        v36 = b2->m_t_vel.y + v39;
        v37 = b2->m_t_vel.z + v40;
        v21->m_b2_ap_n.x = v35;
        v21->m_b2_ap_n.y = v36;
        v21->m_b2_ap_n.z = v37;
        v28 = v6->m_b2 == NULL;
        v32 = v27 + b2->m_mat.w.x;
        v33 = v26 + b2->m_mat.w.y;
        v34 = v25 + b2->m_mat.w.z;
        if ( !v28 )
        {
          if ( _tlAssert(
                 "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_contact_inline.h",
                 209,
                 "psc->m_b2 == NULL",
                 (const char *)&pBlock) )
          {
            __debugbreak();
          }
        }
        v21->m_b2_r.x = v32;
        v21->m_b2_r.y = v33;
        v23 = v34;
      }
      v21->m_b2_r.z = v23;
      pulse_sum_contact_point::calc_abs(v21, v6);
      pulse_sum_contact_point::setup_vel_uni_restitution(
        v21,
        v6,
        cpi->m_bounce_coef,
        cpi->m_max_restitution_vel,
        delta_t,
        50.0,
        b2_r.w);
      pp_i += 208;
      ++v48;
      LODWORD(min_restitution_impact_vel_sq) += 16;
      ++LODWORD(v46);
    }
    while ( SLODWORD(v46) < cpi->m_point_pair_count );
  }
}

/*
==============
pulse_sum_contact_point::calc_abs
==============
*/
void __userpurge pulse_sum_contact_point::calc_abs(pulse_sum_contact_point *this@<ecx>, int a2@<ebp>, pulse_sum_contact *psc)
{
  pulse_sum_contact_point *v3; // esi
  pulse_sum_contact *v4; // edi
  phys_mat44 *v5; // ST1C_4
  phys_vec3 *v6; // eax
  pulse_sum_node *v7; // eax
  phys_mat44 *v8; // ST10_4
  phys_vec3 *v9; // eax
  pulse_sum_node *v10; // ecx
  phys_mat44 *v11; // ST04_4
  phys_vec3 *v12; // eax
  pulse_sum_node *v13; // edx
  double v14; // st6
  double v15; // st7
  double v16; // st5
  pulse_sum_node *v17; // eax
  phys_vec3 *v18; // eax
  pulse_sum_node *v19; // eax
  phys_mat44 *v20; // ST10_4
  phys_vec3 *v21; // eax
  pulse_sum_node *v22; // ecx
  phys_mat44 *v23; // ST04_4
  phys_vec3 *v24; // eax
  pulse_sum_node *v25; // edx
  double v26; // st6
  double v27; // st7
  double v28; // st5
  double v29; // st7
  int v30; // [esp-1Ch] [ebp-5Ch]
  float v31; // [esp-Ch] [ebp-4Ch]
  float v32; // [esp-8h] [ebp-48h]
  float v33; // [esp-4h] [ebp-44h]
  phys_vec3 b2_t_f2; // [esp+0h] [ebp-40h]
  phys_vec3 b2_t_f1; // [esp+10h] [ebp-30h]
  phys_vec3 b2_t_n; // [esp+20h] [ebp-20h]
  float v37; // [esp+30h] [ebp-10h]
  int v38; // [esp+34h] [ebp-Ch]
  const float oo_det; // [esp+38h] [ebp-8h]
  float retaddr; // [esp+40h] [ebp+0h]

  v38 = a2;
  oo_det = retaddr;
  v3 = this;
  v4 = psc;
  v5 = &psc->m_b1->m_world_inv_inertia;
  b2_t_f2.y = psc->m_ud_n.z * v3->m_b1_r.y - v3->m_b1_r.z * psc->m_ud_n.y;
  b2_t_f2.z = v3->m_b1_r.z * v4->m_ud_n.x - v4->m_ud_n.z * v3->m_b1_r.x;
  b2_t_f2.w = psc->m_ud_n.y * this->m_b1_r.x - this->m_b1_r.y * psc->m_ud_n.x;
  v6 = phys_multiply((phys_vec3 *)&v31, v5, (phys_vec3 *)((char *)&b2_t_f2 + 4));
  v3->m_b1_ap_n.x = v6->x;
  v3->m_b1_ap_n.y = v6->y;
  v3->m_b1_ap_n.z = v6->z;
  v7 = psc->m_b1;
  b2_t_n.w = v3->m_b1_ap_n.x * b2_t_f2.y + v3->m_b1_ap_n.y * b2_t_f2.z + v3->m_b1_ap_n.z * b2_t_f2.w;
  v3->m_denom_xx = b2_t_n.w + v7->m_inv_mass;
  v8 = &psc->m_b1->m_world_inv_inertia;
  b2_t_f1.y = v4->m_ud_f1.z * v3->m_b1_r.y - v4->m_ud_f1.y * v3->m_b1_r.z;
  b2_t_f1.z = v3->m_b1_r.z * v4->m_ud_f1.x - v4->m_ud_f1.z * v3->m_b1_r.x;
  b2_t_f1.w = v4->m_ud_f1.y * v3->m_b1_r.x - v3->m_b1_r.y * v4->m_ud_f1.x;
  v9 = phys_multiply((phys_vec3 *)&v31, v8, (phys_vec3 *)((char *)&b2_t_f1 + 4));
  v3->m_b1_ap_f1.x = v9->x;
  v3->m_b1_ap_f1.y = v9->y;
  v3->m_b1_ap_f1.z = v9->z;
  v10 = psc->m_b1;
  b2_t_n.w = v3->m_b1_ap_f1.x * b2_t_f1.y + v3->m_b1_ap_f1.y * b2_t_f1.z + v3->m_b1_ap_f1.z * b2_t_f1.w;
  v3->m_denom_yy = b2_t_n.w + v10->m_inv_mass;
  v11 = &psc->m_b1->m_world_inv_inertia;
  v31 = v3->m_b1_r.y * v4->m_ud_f2.z - v4->m_ud_f2.y * v3->m_b1_r.z;
  v32 = v3->m_b1_r.z * v4->m_ud_f2.x - v3->m_b1_r.x * v4->m_ud_f2.z;
  v33 = v4->m_ud_f2.y * v3->m_b1_r.x - v4->m_ud_f2.x * v3->m_b1_r.y;
  v12 = phys_multiply((phys_vec3 *)&v30, v11, (phys_vec3 *)&v31);
  v3->m_b1_ap_f2.x = v12->x;
  v3->m_b1_ap_f2.y = v12->y;
  v3->m_b1_ap_f2.z = v12->z;
  v13 = psc->m_b1;
  b2_t_n.w = v32 * v3->m_b1_ap_f2.y + v3->m_b1_ap_f2.x * v31 + v33 * v3->m_b1_ap_f2.z;
  v3->m_denom_zz = b2_t_n.w + v13->m_inv_mass;
  v37 = b2_t_f1.z * v3->m_b1_ap_f2.y + v3->m_b1_ap_f2.x * b2_t_f1.y + b2_t_f1.w * v3->m_b1_ap_f2.z;
  v14 = b2_t_f2.z;
  v15 = b2_t_f2.y;
  v16 = b2_t_f2.w;
  v3->m_denom_xy = v3->m_b1_ap_f1.z * b2_t_f2.w + v3->m_b1_ap_f1.x * b2_t_f2.y + v3->m_b1_ap_f1.y * b2_t_f2.z;
  v3->m_denom_xz = v16 * v3->m_b1_ap_f2.z + v14 * v3->m_b1_ap_f2.y + v15 * v3->m_b1_ap_f2.x;
  v17 = psc->m_b2;
  if ( v17 )
  {
    b2_t_f1.y = v3->m_b2_r.y * psc->m_ud_n.z - v3->m_b2_r.z * psc->m_ud_n.y;
    b2_t_f1.z = v3->m_b2_r.z * psc->m_ud_n.x - psc->m_ud_n.z * v3->m_b2_r.x;
    b2_t_f1.w = psc->m_ud_n.y * v3->m_b2_r.x - v3->m_b2_r.y * psc->m_ud_n.x;
    v18 = phys_multiply((phys_vec3 *)&v30, &v17->m_world_inv_inertia, (phys_vec3 *)((char *)&b2_t_f1 + 4));
    v3->m_b2_ap_n.x = v18->x;
    v3->m_b2_ap_n.y = v18->y;
    v3->m_b2_ap_n.z = v18->z;
    v19 = psc->m_b2;
    b2_t_n.w = v3->m_b2_ap_n.x * b2_t_f1.y + v3->m_b2_ap_n.y * b2_t_f1.z + v3->m_b2_ap_n.z * b2_t_f1.w;
    v3->m_denom_xx = b2_t_n.w + v19->m_inv_mass + v3->m_denom_xx;
    v20 = &psc->m_b2->m_world_inv_inertia;
    b2_t_f2.y = v3->m_b2_r.y * psc->m_ud_f1.z - psc->m_ud_f1.y * v3->m_b2_r.z;
    b2_t_f2.z = v3->m_b2_r.z * psc->m_ud_f1.x - psc->m_ud_f1.z * v3->m_b2_r.x;
    b2_t_f2.w = psc->m_ud_f1.y * v3->m_b2_r.x - v3->m_b2_r.y * psc->m_ud_f1.x;
    v21 = phys_multiply((phys_vec3 *)&v30, v20, (phys_vec3 *)((char *)&b2_t_f2 + 4));
    v3->m_b2_ap_f1.x = v21->x;
    v3->m_b2_ap_f1.y = v21->y;
    v3->m_b2_ap_f1.z = v21->z;
    v22 = psc->m_b2;
    b2_t_n.w = v3->m_b2_ap_f1.x * b2_t_f2.y + v3->m_b2_ap_f1.y * b2_t_f2.z + v3->m_b2_ap_f1.z * b2_t_f2.w;
    v3->m_denom_yy = b2_t_n.w + v22->m_inv_mass + v3->m_denom_yy;
    v23 = &psc->m_b2->m_world_inv_inertia;
    v31 = v3->m_b2_r.y * psc->m_ud_f2.z - psc->m_ud_f2.y * v3->m_b2_r.z;
    v32 = psc->m_ud_f2.x * v3->m_b2_r.z - v3->m_b2_r.x * psc->m_ud_f2.z;
    v33 = psc->m_ud_f2.y * v3->m_b2_r.x - v3->m_b2_r.y * psc->m_ud_f2.x;
    v24 = phys_multiply((phys_vec3 *)&v30, v23, (phys_vec3 *)&v31);
    v3->m_b2_ap_f2.x = v24->x;
    v3->m_b2_ap_f2.y = v24->y;
    v3->m_b2_ap_f2.z = v24->z;
    v25 = psc->m_b2;
    b2_t_n.w = v3->m_b2_ap_f2.x * v31 + v3->m_b2_ap_f2.y * v32 + v3->m_b2_ap_f2.z * v33;
    v3->m_denom_zz = b2_t_n.w + v25->m_inv_mass + v3->m_denom_zz;
    b2_t_n.w = v3->m_b2_ap_f2.x * b2_t_f2.y + v3->m_b2_ap_f2.y * b2_t_f2.z + v3->m_b2_ap_f2.z * b2_t_f2.w;
    v37 = b2_t_n.w + v37;
    v26 = b2_t_f1.y;
    v27 = b2_t_f1.z;
    v28 = b2_t_f1.w;
    b2_t_n.w = v3->m_b2_ap_f1.z * b2_t_f1.w + v3->m_b2_ap_f1.y * b2_t_f1.z + v3->m_b2_ap_f1.x * b2_t_f1.y;
    v3->m_denom_xy = b2_t_n.w + v3->m_denom_xy;
    b2_t_n.w = v27 * v3->m_b2_ap_f2.y + v26 * v3->m_b2_ap_f2.x + v28 * v3->m_b2_ap_f2.z;
    v3->m_denom_xz = b2_t_n.w + v3->m_denom_xz;
  }
  b2_t_n.w = v3->m_denom_zz * v3->m_denom_yy - v37 * v37;
  if ( b2_t_n.w <= 0.0
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_contact_inline.h",
         38,
         "det > 0.0f",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  b2_t_n.w = 1.0 / b2_t_n.w;
  v29 = b2_t_n.w;
  v3->m_inv_yy = b2_t_n.w * v3->m_denom_zz;
  v3->m_inv_yz = -v37 * v29;
  v3->m_inv_zz = v29 * v3->m_denom_yy;
}

/*
==============
pulse_sum_contact_point::get_objective
==============
*/
phys_vec3 *__thiscall pulse_sum_contact_point::get_objective(pulse_sum_contact_point *this, phys_vec3 *result, pulse_sum_contact *psc)
{
  pulse_sum_node *v3; // eax
  float v4; // ST10_4
  float v5; // ST14_4
  float v6; // ST18_4
  pulse_sum_node *v7; // eax
  float v8; // ST10_4
  float v9; // ST14_4
  float v10; // ST18_4
  float v11; // ST00_4
  float v12; // ST04_4
  float v13; // ST08_4
  phys_vec3 *v14; // eax
  float v15; // [esp-Ch] [ebp-1Ch]
  float v16; // [esp-8h] [ebp-18h]
  float v17; // [esp-4h] [ebp-14h]

  v3 = psc->m_b1;
  v4 = v3->a_vel.y * this->m_b1_r.z - v3->a_vel.z * this->m_b1_r.y;
  v5 = v3->a_vel.z * this->m_b1_r.x - v3->a_vel.x * this->m_b1_r.z;
  v6 = this->m_b1_r.y * v3->a_vel.x - this->m_b1_r.x * v3->a_vel.y;
  v15 = v3->t_vel.x + v4;
  v16 = v3->t_vel.y + v5;
  v17 = v3->t_vel.z + v6;
  if ( psc->m_b2 )
  {
    v7 = psc->m_b2;
    v8 = v7->a_vel.y * this->m_b2_r.z - v7->a_vel.z * this->m_b2_r.y;
    v9 = v7->a_vel.z * this->m_b2_r.x - this->m_b2_r.z * v7->a_vel.x;
    v10 = v7->a_vel.x * this->m_b2_r.y - v7->a_vel.y * this->m_b2_r.x;
    v11 = v7->t_vel.x + v8;
    v12 = v7->t_vel.y + v9;
    v13 = v7->t_vel.z + v10;
    v15 = v15 - v11;
    v16 = v16 - v12;
    v17 = v17 - v13;
  }
  v14 = result;
  result->x = psc->m_ud_n.z * v17 + psc->m_ud_n.x * v15 + psc->m_ud_n.y * v16;
  result->y = psc->m_ud_f1.y * v16 + v15 * psc->m_ud_f1.x + psc->m_ud_f1.z * v17;
  result->z = v15 * psc->m_ud_f2.x + v16 * psc->m_ud_f2.y + v17 * psc->m_ud_f2.z;
  return v14;
}

/*
==============
pulse_sum_contact_point::apply
==============
*/
void __thiscall pulse_sum_contact_point::apply(pulse_sum_contact_point *this, pulse_sum_contact *psc, phys_vec3 *s_)
{
  float v3; // ST5C_4
  pulse_sum_node *v4; // esi
  float v5; // ST10_4
  float v6; // ST14_4
  float v7; // ST18_4
  float v8; // ST5C_4
  float v9; // ST30_4
  float v10; // ST34_4
  float v11; // ST38_4
  float f_4; // ST40_4
  float f_8; // ST44_4
  float f_12; // ST48_4
  float v15; // ST20_4
  float v16; // ST24_4
  float v17; // ST28_4
  float v18; // ST30_4
  float v19; // ST34_4
  float v20; // ST38_4
  float v21; // ST5C_4
  double v22; // st7
  float v23; // ST10_4
  double v24; // st5
  float v25; // ST14_4
  double v26; // st6
  float v27; // ST18_4
  pulse_sum_node *v28; // esi
  float v29; // ST5C_4
  float v30; // ST40_4
  float v31; // ST44_4
  float v32; // ST48_4
  float v33; // ST5C_4
  float v34; // ST20_4
  float v35; // ST24_4
  float v36; // ST28_4
  float v37; // ST10_4
  float v38; // ST14_4
  float v39; // ST18_4
  float v40; // ST30_4
  float v41; // ST34_4
  float v42; // ST38_4
  float v43; // ST10_4
  float v44; // ST14_4
  float v45; // ST18_4
  pulse_sum_node *v46; // esi
  float v47; // ST5C_4
  float v48; // ST10_4
  float v49; // ST14_4
  float v50; // ST18_4
  pulse_sum_node *v51; // eax
  float v52; // ST5C_4
  float v53; // ST40_4
  float v54; // ST44_4
  float v55; // ST48_4
  float v56; // ST5C_4
  float v57; // ST20_4
  float v58; // ST24_4
  float v59; // ST28_4
  float v60; // ST10_4
  float v61; // ST14_4
  float v62; // ST18_4
  float v63; // ST30_4
  float v64; // ST34_4
  float v65; // ST38_4
  float v66; // ST10_4
  float v67; // ST14_4
  float v68; // ST18_4

  v3 = s_->z;
  v4 = psc->m_b1;
  v5 = psc->m_ud_f2.x * v3;
  v6 = psc->m_ud_f2.y * v3;
  v7 = v3 * psc->m_ud_f2.z;
  v8 = s_->y;
  v9 = v8 * psc->m_ud_f1.x;
  v10 = psc->m_ud_f1.y * v8;
  v11 = v8 * psc->m_ud_f1.z;
  f_4 = psc->m_ud_n.x * s_->x;
  f_8 = psc->m_ud_n.y * s_->x;
  f_12 = s_->x * psc->m_ud_n.z;
  v15 = f_4 + v9;
  v16 = f_8 + v10;
  v17 = f_12 + v11;
  v18 = v15 + v5;
  v19 = v16 + v6;
  v20 = v17 + v7;
  v21 = v4->m_inv_mass;
  v22 = v18;
  v23 = v18 * v21;
  v24 = v19;
  v25 = v19 * v21;
  v26 = v20;
  v27 = v21 * v20;
  v4->t_vel.x = v4->t_vel.x + v23;
  v4->t_vel.y = v25 + v4->t_vel.y;
  v4->t_vel.z = v4->t_vel.z + v27;
  v28 = psc->m_b1;
  v29 = s_->z;
  v30 = this->m_b1_ap_f2.x * v29;
  v31 = this->m_b1_ap_f2.y * v29;
  v32 = v29 * this->m_b1_ap_f2.z;
  v33 = s_->y;
  v34 = v33 * this->m_b1_ap_f1.x;
  v35 = this->m_b1_ap_f1.y * v33;
  v36 = v33 * this->m_b1_ap_f1.z;
  v37 = this->m_b1_ap_n.x * s_->x;
  v38 = this->m_b1_ap_n.y * s_->x;
  v39 = s_->x * this->m_b1_ap_n.z;
  v40 = v37 + v34;
  v41 = v38 + v35;
  v42 = v39 + v36;
  v43 = v40 + v30;
  v44 = v41 + v31;
  v45 = v42 + v32;
  v28->a_vel.x = v28->a_vel.x + v43;
  v28->a_vel.y = v44 + v28->a_vel.y;
  v28->a_vel.z = v28->a_vel.z + v45;
  if ( psc->m_b2 )
  {
    v46 = psc->m_b2;
    v47 = v46->m_inv_mass;
    v48 = v22 * v47;
    v49 = v24 * v47;
    v50 = v47 * v26;
    v46->t_vel.x = v46->t_vel.x - v48;
    v46->t_vel.y = v46->t_vel.y - v49;
    v46->t_vel.z = v46->t_vel.z - v50;
    v51 = psc->m_b2;
    v52 = s_->z;
    v53 = this->m_b2_ap_f2.x * v52;
    v54 = this->m_b2_ap_f2.y * v52;
    v55 = v52 * this->m_b2_ap_f2.z;
    v56 = s_->y;
    v57 = v56 * this->m_b2_ap_f1.x;
    v58 = this->m_b2_ap_f1.y * v56;
    v59 = v56 * this->m_b2_ap_f1.z;
    v60 = this->m_b2_ap_n.x * s_->x;
    v61 = this->m_b2_ap_n.y * s_->x;
    v62 = s_->x * this->m_b2_ap_n.z;
    v63 = v60 + v57;
    v64 = v61 + v58;
    v65 = v62 + v59;
    v66 = v63 + v53;
    v67 = v64 + v54;
    v68 = v65 + v55;
    v51->a_vel.x = v51->a_vel.x - v66;
    v51->a_vel.y = v51->a_vel.y - v67;
    v51->a_vel.z = v51->a_vel.z - v68;
  }
}

/*
==============
pulse_sum_contact_point::clamp_f
==============
*/
void __thiscall pulse_sum_contact_point::clamp_f(pulse_sum_contact_point *this, pulse_sum_contact *psc)
{
  pulse_sum_contact_point *v2; // esi
  float v3; // ST14_4
  double v4; // st7
  float v5; // ST14_4
  float v6; // ST14_4
  long double v7; // st7
  float v8; // ST14_4
  float pulse_sum_fric_sq; // [esp+4h] [ebp-8h]
  float ratio; // [esp+14h] [ebp+8h]
  float ratioa; // [esp+14h] [ebp+8h]

  v2 = this;
  ratio = -psc->m_fric_coef * this->m_pulse_sum.x;
  v3 = this->m_pulse_sum.y * this->m_pulse_sum.y;
  v4 = v3;
  v5 = this->m_pulse_sum.z * this->m_pulse_sum.z;
  v6 = v4 + v5;
  v7 = v6;
  v8 = ratio * ratio;
  if ( v8 < v7 )
  {
    pulse_sum_fric_sq = sqrt(v7);
    if ( pulse_sum_fric_sq <= 0.0
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_contact_inline.h",
           100,
           "pulse_sum_fric > 0.0f",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( ratio < 0.0 )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_contact_inline.h",
             101,
             "m_pulse_sum_fric_limit >= 0.0f",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    ratioa = ratio / pulse_sum_fric_sq;
    v2->m_pulse_sum.y = ratioa * v2->m_pulse_sum.y;
    v2->m_pulse_sum.z = ratioa * v2->m_pulse_sum.z;
  }
}

/*
==============
pulse_sum_contact_point::setup_vel_uni_restitution
==============
*/
void __userpurge pulse_sum_contact_point::setup_vel_uni_restitution(pulse_sum_contact_point *this@<ecx>, int a2@<ebp>, pulse_sum_contact *psc, const float restitution_k, const float max_restitution_v, const float delta_t, const float max_penalty_restitution_vel, const float min_restitution_impact_vel_sq)
{
  pulse_sum_contact_point *v8; // ecx
  double v9; // st7
  float v10; // ST30_4
  double v11; // st7
  double v12; // st6
  int v13; // ecx
  float v14; // ST30_4
  double v15; // st6
  float v16; // ST2C_4
  float v17; // ST30_4
  double v18; // st6
  float v19; // [esp-8h] [ebp-14h]
  float v20; // [esp-8h] [ebp-14h]
  float v21; // [esp-8h] [ebp-14h]
  float v22; // [esp-8h] [ebp-14h]
  int v23; // [esp+0h] [ebp-Ch]
  const float dist; // [esp+4h] [ebp-8h]
  float retaddr; // [esp+Ch] [ebp+0h]

  v23 = a2;
  dist = retaddr;
  v19 = pulse_sum_contact_point::get_pos(this, (int)&v23, psc);
  v9 = 0.016666668;
  if ( delta_t > 0.016666668 )
    v9 = delta_t;
  v10 = v9;
  v11 = v19;
  v20 = -v19 / v10;
  v8->m_big_dirt = v20;
  if ( v20 >= 0.0 )
  {
    v12 = 0.0;
  }
  else
  {
    v12 = 0.0;
    v8->m_big_dirt = v20 * 0.300000011920929;
  }
  v21 = -max_penalty_restitution_vel;
  if ( v21 > (double)v8->m_big_dirt )
    v8->m_big_dirt = v21;
  if ( v12 > v8->m_big_dirt )
  {
    v8->m_right_side.x = PHYS_ZERO_VEC_97.x;
    v8->m_right_side.y = PHYS_ZERO_VEC_97.y;
    v8->m_right_side.z = PHYS_ZERO_VEC_97.z;
  }
  else
  {
    v8->m_right_side.x = v8->m_big_dirt;
    v8->m_right_side.y = v12;
    v8->m_right_side.z = v12;
    v8->m_big_dirt = v12;
  }
  if ( restitution_k > 0.0000099999997 && max_restitution_v > 0.0000099999997 && v12 <= v11 )
  {
    v14 = pulse_sum_contact_point::get_impact_vel(v8, (int)&v23, psc);
    v15 = v14;
    if ( v14 > 0.0 )
    {
      v16 = v15 * v15;
      if ( min_restitution_impact_vel_sq < (double)v16 )
      {
        v17 = v15 * restitution_k;
        v18 = v17;
        if ( max_restitution_v < (double)v17 )
          v18 = max_restitution_v;
        if ( *(float *)(v13 + 160) > -0.0000099999997 )
        {
          *(float *)(v13 + 144) = *(float *)(v13 + 144) - v18;
        }
        else
        {
          v22 = -v18;
          if ( *(float *)(v13 + 160) > (double)v22 )
          {
            *(float *)(v13 + 144) = v22;
            *(float *)(v13 + 160) = 0.0;
          }
        }
      }
    }
  }
}

/*
==============
pulse_sum_contact::SOLVER_apply_relaxation
==============
*/
void __userpurge pulse_sum_contact::SOLVER_apply_relaxation(pulse_sum_contact *this@<ecx>, int a2@<ebp>, float *error_sq)
{
  pulse_sum_contact_point *v3; // edi
  int v4; // eax
  float *v5; // esi
  float v6; // edx
  phys_vec3 *v7; // eax
  pulse_sum_contact *v8; // ST04_4
  double v9; // st7
  double v10; // st6
  int v11; // [esp-78h] [ebp-8Ch]
  float v12; // [esp-68h] [ebp-7Ch]
  float v13; // [esp-64h] [ebp-78h]
  float v14; // [esp-60h] [ebp-74h]
  float v15; // [esp-58h] [ebp-6Ch]
  float v16; // [esp-54h] [ebp-68h]
  float v17; // [esp-50h] [ebp-64h]
  float v18; // [esp-48h] [ebp-5Ch]
  float v19; // [esp-44h] [ebp-58h]
  float v20; // [esp-40h] [ebp-54h]
  float v21; // [esp-38h] [ebp-4Ch]
  float v22; // [esp-34h] [ebp-48h]
  float v23; // [esp-30h] [ebp-44h]
  int v24; // [esp-2Ch] [ebp-40h]
  float v25; // [esp-28h] [ebp-3Ch]
  float v26; // [esp-24h] [ebp-38h]
  float v27; // [esp-20h] [ebp-34h]
  pulse_sum_contact_point *v28; // [esp-Ch] [ebp-20h]
  float v29; // [esp-8h] [ebp-1Ch]
  float v30; // [esp-4h] [ebp-18h]
  pulse_sum_contact_point *const last_pscp_i; // [esp+0h] [ebp-14h]
  pulse_sum_contact *v32; // [esp+4h] [ebp-10h]
  int v33; // [esp+8h] [ebp-Ch]
  int v34; // [esp+Ch] [ebp-8h]
  int retaddr; // [esp+14h] [ebp+0h]

  v33 = a2;
  v34 = retaddr;
  v3 = this->m_list_pscp;
  v4 = (int)&v3[this->m_list_pscp_count];
  v32 = this;
  v28 = (pulse_sum_contact_point *)v4;
  if ( v3 != (pulse_sum_contact_point *)v4 )
  {
    v5 = &v3->m_right_side.z;
    while ( 1 )
    {
      v6 = *(v5 - 5);
      v21 = *(v5 - 6);
      v23 = *(v5 - 4);
      v22 = v6;
      v24 = *((_DWORD *)v5 - 3);
      v7 = pulse_sum_contact_point::get_objective(v3, (phys_vec3 *)&v11, this);
      v25 = v7->x - *(v5 - 2);
      v26 = v7->y - *(v5 - 1);
      v27 = v7->z - *v5;
      *(v5 - 6) = *(v5 - 6) - v25 / v5[3];
      if ( *(v5 - 6) > 0.0 )
        *(v5 - 6) = 0.0;
      v8 = v32;
      *(float *)&last_pscp_i = *(v5 - 6) - v21;
      v26 = v5[6] * *(float *)&last_pscp_i + v26;
      v27 = *(float *)&last_pscp_i * v5[7] + v27;
      v9 = v27;
      v10 = v26;
      *(v5 - 5) = *(v5 - 5) - (v5[8] * v26 + v27 * v5[9]);
      *(v5 - 4) = *(v5 - 4) - (v10 * v5[9] + v9 * v5[10]);
      pulse_sum_contact_point::clamp_f(v3, v8);
      v18 = *(v5 - 6) - v21;
      v19 = *(v5 - 5) - v22;
      v20 = *(v5 - 4) - v23;
      pulse_sum_contact_point::apply(v3, v32, (phys_vec3 *)&v18);
      v15 = v5[3];
      v16 = v5[4];
      v17 = v5[5];
      v29 = v17 * v20;
      v30 = v16 * v19;
      *(float *)&last_pscp_i = v15 * v18;
      v12 = *(float *)&last_pscp_i * *(float *)&last_pscp_i;
      v13 = v30 * v30;
      v14 = v29 * v29;
      if ( *error_sq < (double)v12 )
        *error_sq = v12;
      if ( *error_sq < (double)v13 )
        *error_sq = v13;
      if ( *error_sq < (double)v14 )
        *error_sq = v14;
      ++v3;
      v5 += 52;
      if ( v3 == v28 )
        break;
      this = v32;
    }
  }
}

/*
==============
pulse_sum_contact::SOLVER_solver_prolog
==============
*/
void __userpurge pulse_sum_contact::SOLVER_solver_prolog(pulse_sum_contact *this@<ecx>, pulse_sum_contact_point *a2@<ebp>, const float delta_t)
{
  pulse_sum_contact_point *v3; // edi
  int v4; // eax
  float *v5; // esi
  phys_vec3 *v6; // eax
  double v7; // st7
  float *v8; // eax
  int v9; // [esp-20h] [ebp-2Ch]
  pulse_sum_contact_point *v10; // [esp-Ch] [ebp-18h]
  float *v11; // [esp-8h] [ebp-14h]
  pulse_sum_contact *v12; // [esp-4h] [ebp-10h]
  pulse_sum_contact_point *const last_pscp_i; // [esp+0h] [ebp-Ch]
  contact_point_info::pulse_sum_cache_info *ps_cache_info_i; // [esp+4h] [ebp-8h]
  contact_point_info::pulse_sum_cache_info *retaddr; // [esp+Ch] [ebp+0h]

  last_pscp_i = a2;
  ps_cache_info_i = retaddr;
  v11 = (float *)this->m_pulse_sum_cache_list;
  v3 = this->m_list_pscp;
  v4 = (int)&v3[this->m_list_pscp_count];
  v12 = this;
  v10 = (pulse_sum_contact_point *)v4;
  if ( v3 != (pulse_sum_contact_point *)v4 )
  {
    v5 = &v3->m_right_side.z;
    while ( 1 )
    {
      v6 = pulse_sum_contact_point::get_vel(v3, COERCE_FLOAT(&last_pscp_i), (phys_vec3 *)&v9, this);
      *(v5 - 2) = *(v5 - 2) - v6->x;
      *(v5 - 1) = *(v5 - 1) - v6->y;
      v7 = *v5 - v6->z;
      v8 = v11;
      *v5 = v7;
      *(v5 - 6) = *v8 * delta_t;
      *(v5 - 5) = v8[1] * delta_t;
      *(v5 - 4) = delta_t * v8[2];
      if ( *(v5 - 6) > 0.0 )
        *(v5 - 6) = 0.0;
      pulse_sum_contact_point::clamp_f(v3, v12);
      pulse_sum_contact_point::apply(v3, v12, (phys_vec3 *)(v5 - 6));
      v11 += 3;
      ++v3;
      v5 += 52;
      if ( v3 == v10 )
        break;
      this = v12;
    }
  }
}

/*
==============
pulse_sum_contact::SOLVER_solver_intermediate
==============
*/
void __thiscall pulse_sum_contact::SOLVER_solver_intermediate(pulse_sum_contact *this, const float delta_t)
{
  pulse_sum_contact_point *v2; // eax
  float *v3; // edx
  int v4; // ecx
  double v5; // st7
  double v6; // st6

  v2 = this->m_list_pscp;
  v3 = (float *)this->m_pulse_sum_cache_list;
  v4 = (int)&v2[this->m_list_pscp_count];
  if ( v2 != (pulse_sum_contact_point *)v4 )
  {
    v5 = delta_t;
    do
    {
      v6 = v2->m_pulse_sum.x;
      ++v2;
      v3 += 3;
      *(v3 - 3) = v6 / v5;
      *(v3 - 2) = v2[-1].m_pulse_sum.y / v5;
      *(v3 - 1) = v2[-1].m_pulse_sum.z / v5;
      v2[-1].m_right_side.x = v2[-1].m_big_dirt + v2[-1].m_right_side.x;
    }
    while ( v2 != (pulse_sum_contact_point *)v4 );
  }
}

