/*
==============
ragdoll_joint_limit_info::set_b1_ud_loc
==============
*/
void __userpurge ragdoll_joint_limit_info::set_b1_ud_loc(ragdoll_joint_limit_info *this@<ecx>, int a2@<ebp>, phys_vec3 *b1_ud_loc)
{
  ragdoll_joint_limit_info *v3; // esi
  phys_vec3 *v4; // eax
  int v5; // [esp-10h] [ebp-1Ch]
  int v6; // [esp+0h] [ebp-Ch]
  int v7; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v6 = a2;
  v7 = retaddr;
  v3 = this;
  v4 = phys_Unitize((phys_vec3 *)&v5, b1_ud_loc);
  v3->m_b1_ud_loc.x = v4->x;
  v3->m_b1_ud_loc.y = v4->y;
  v3->m_b1_ud_loc.z = v4->z;
  PHYS_ASSERT_UNIT(&v3->m_b1_ud_loc);
}

/*
==============
rigid_body_constraint_ragdoll::set
==============
*/
void __thiscall rigid_body_constraint_ragdoll::set(rigid_body_constraint_ragdoll *this, phys_vec3 *b1_r_loc, phys_vec3 *b2_r_loc)
{
  this->m_b1_r_loc.x = b1_r_loc->x;
  this->m_b1_r_loc.y = b1_r_loc->y;
  this->m_b1_r_loc.z = b1_r_loc->z;
  this->m_b2_r_loc.x = b2_r_loc->x;
  this->m_b2_r_loc.y = b2_r_loc->y;
  this->m_b2_r_loc.z = b2_r_loc->z;
}

/*
==============
rigid_body_constraint_ragdoll::set_snider_style
==============
*/
void __userpurge rigid_body_constraint_ragdoll::set_snider_style(rigid_body_constraint_ragdoll *this@<ecx>, int a2@<ebp>, phys_vec3 *b1_axis_loc, phys_vec3 *b1_ref_loc)
{
  rigid_body_constraint_ragdoll *v4; // esi
  phys_vec3 *v5; // eax
  float *v6; // edi
  phys_vec3 *v7; // eax
  float *v8; // ecx
  double v9; // st7
  phys_vec3 *v10; // eax
  float v11; // [esp-20h] [ebp-2Ch]
  float v12; // [esp-1Ch] [ebp-28h]
  float v13; // [esp-18h] [ebp-24h]
  phys_vec3 *v14; // [esp-4h] [ebp-10h]
  int v15; // [esp+0h] [ebp-Ch]
  int v16; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v15 = a2;
  v16 = retaddr;
  v4 = this;
  v5 = phys_Unitize((phys_vec3 *)&v11, b1_axis_loc);
  v4->m_b1_axis_loc.x = v5->x;
  v6 = &v4->m_b1_axis_loc.x;
  v6[1] = v5->y;
  v6[2] = v5->z;
  v7 = phys_Unitize((phys_vec3 *)&v11, b1_ref_loc);
  v8 = &v4->m_b1_ref_loc.x;
  *v8 = v7->x;
  v9 = v7->y;
  v14 = &v4->m_b1_ref_loc;
  v8[1] = v9;
  v8[2] = v7->z;
  if ( v4->m_flags & 4 )
  {
    v10 = construct_orth_ud((phys_vec3 *)&v11, &v4->m_b1_axis_loc);
    v4->m_b1_a1_loc.x = v10->x;
    v4->m_b1_a1_loc.y = v10->y;
    v4->m_b1_a1_loc.z = v10->z;
    v11 = v4->m_b1_axis_loc.y * v4->m_b1_a1_loc.z - v4->m_b1_axis_loc.z * v4->m_b1_a1_loc.y;
    v12 = v4->m_b1_axis_loc.z * v4->m_b1_a1_loc.x - v4->m_b1_a1_loc.z * v4->m_b1_axis_loc.x;
    v13 = v4->m_b1_a1_loc.y * *v6 - v4->m_b1_axis_loc.y * v4->m_b1_a1_loc.x;
    v4->m_b1_a2_loc.x = v11;
    v4->m_b1_a2_loc.y = v12;
    v4->m_b1_a2_loc.z = v13;
  }
  PHYS_ASSERT_UNIT(&v4->m_b1_axis_loc);
  PHYS_ASSERT_UNIT(v14);
}

/*
==============
rigid_body_constraint_ragdoll::set_damp_k
==============
*/
void __thiscall rigid_body_constraint_ragdoll::set_damp_k(rigid_body_constraint_ragdoll *this, const float damp_k)
{
  this->m_damp_k = damp_k;
  if ( damp_k <= 0.0 )
    this->m_flags &= 0xFFFFFFBF;
  else
    this->m_flags |= 0x40u;
}

/*
==============
ragdoll_joint_limit_info::set
==============
*/
void __userpurge ragdoll_joint_limit_info::set(ragdoll_joint_limit_info *this@<ecx>, int a2@<ebp>, phys_vec3 *b1_ud_loc, const float theta_limit)
{
  ragdoll_joint_limit_info *v4; // esi
  phys_vec3 *v5; // eax
  double v6; // st7
  double v7; // st7
  int v8; // [esp-20h] [ebp-2Ch]
  float v9; // [esp-4h] [ebp-10h]
  int v10; // [esp+0h] [ebp-Ch]
  int v11; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v10 = a2;
  v11 = retaddr;
  v4 = this;
  if ( theta_limit <= 0.0 && _tlAssert("source/rbc_def_ragdoll.cpp", 7, "theta_limit > 0.0f", (const char *)&pBlock) )
    __debugbreak();
  v5 = phys_Unitize((phys_vec3 *)&v8, b1_ud_loc);
  v4->m_b1_ud_loc.x = v5->x;
  v4->m_b1_ud_loc.y = v5->y;
  v4->m_b1_ud_loc.z = v5->z;
  v9 = cos(theta_limit);
  v4->m_b1_ud_limit_co_ = v9;
  v9 = sin(theta_limit);
  v4->m_b1_ud_limit_si_ = v9;
  v9 = theta_limit - 0.04363323003053665;
  v6 = v9;
  if ( v9 > 0.0 )
    v6 = 0.0;
  v9 = v6;
  v9 = cos(v9);
  v7 = v9;
  v9 = *(float *)&v4;
  v4->m_b1_ud_active_limit_co_ = v7;
  PHYS_ASSERT_UNIT((phys_vec3 *)LODWORD(v9));
}

/*
==============
ragdoll_joint_limit_info::set_theta_limit
==============
*/
void __thiscall ragdoll_joint_limit_info::set_theta_limit(ragdoll_joint_limit_info *this, const float theta_limit)
{
  ragdoll_joint_limit_info *v2; // esi
  float v3; // ST14_4
  float v4; // ST14_4
  double v5; // st7
  float theta_limita; // [esp+10h] [ebp+8h]
  float theta_limitb; // [esp+10h] [ebp+8h]
  float theta_limitc; // [esp+10h] [ebp+8h]

  v2 = this;
  if ( theta_limit <= 0.0 && _tlAssert("source/rbc_def_ragdoll.cpp", 23, "theta_limit > 0.0f", (const char *)&pBlock) )
    __debugbreak();
  v3 = cos(theta_limit);
  v2->m_b1_ud_limit_co_ = v3;
  v4 = sin(theta_limit);
  v2->m_b1_ud_limit_si_ = v4;
  theta_limita = theta_limit - 0.04363323003053665;
  v5 = theta_limita;
  if ( theta_limita > 0.0 )
    v5 = 0.0;
  theta_limitb = v5;
  theta_limitc = cos(theta_limitb);
  v2->m_b1_ud_active_limit_co_ = theta_limitc;
}

/*
==============
rigid_body_constraint_ragdoll::set_theta_min_max
==============
*/
void __userpurge rigid_body_constraint_ragdoll::set_theta_min_max(rigid_body_constraint_ragdoll *this@<ecx>, int a2@<ebp>, phys_vec3 *b2_ref_loc, const float theta_min, const float theta_max)
{
  rigid_body_constraint_ragdoll *v5; // esi
  phys_vec3 *v6; // edi
  phys_vec3 *v7; // eax
  phys_vec3 *v8; // eax
  phys_vec3 *v9; // eax
  phys_vec3 *v10; // eax
  int v11; // [esp+18h] [ebp-7Ch]
  phys_mat44 rv; // [esp+24h] [ebp-70h]
  int v13; // [esp+68h] [ebp-2Ch]
  int v14; // [esp+78h] [ebp-1Ch]
  int v15; // [esp+88h] [ebp-Ch]
  int v16; // [esp+8Ch] [ebp-8h]
  int retaddr; // [esp+94h] [ebp+0h]

  v15 = a2;
  v16 = retaddr;
  v5 = this;
  v6 = &this->m_b2_axis_loc;
  make_rotate((phys_mat44 *)&v11, &this->m_b2_axis_loc, theta_min, 1000.0);
  v7 = phys_multiply((phys_vec3 *)&v14, (phys_mat44 *)&v11, b2_ref_loc);
  v8 = phys_Unitize((phys_vec3 *)&v13, v7);
  v5->m_b2_ref_min_loc.x = v8->x;
  v5->m_b2_ref_min_loc.y = v8->y;
  v5->m_b2_ref_min_loc.z = v8->z;
  make_rotate((phys_mat44 *)&v11, v6, theta_max, 1000.0);
  v9 = phys_multiply((phys_vec3 *)&v13, (phys_mat44 *)&v11, b2_ref_loc);
  v10 = phys_Unitize((phys_vec3 *)((char *)&rv.w + 4), v9);
  v5->m_b2_ref_max_loc.x = v10->x;
  v5->m_b2_ref_max_loc.y = v10->y;
  v5->m_b2_ref_max_loc.z = v10->z;
}

/*
==============
rigid_body_constraint_ragdoll::set_hinge
==============
*/
void __userpurge rigid_body_constraint_ragdoll::set_hinge(rigid_body_constraint_ragdoll *this@<ecx>, int a2@<ebp>, phys_vec3 *b1_axis_loc, phys_vec3 *b2_axis_loc, phys_vec3 *b1_ref_loc, phys_vec3 *b2_ref_loc, const float theta_min, const float theta_max)
{
  rigid_body_constraint_ragdoll *v8; // esi
  phys_vec3 *v9; // eax
  int v10; // edi
  phys_vec3 *v11; // eax
  phys_vec3 *v12; // eax
  phys_vec3 *v13; // eax
  phys_vec3 *v14; // eax
  phys_vec3 *v15; // eax
  phys_vec3 *v16; // eax
  phys_vec3 *v17; // eax
  int v18; // [esp+18h] [ebp-7Ch]
  phys_mat44 rv; // [esp+24h] [ebp-70h]
  int v20; // [esp+68h] [ebp-2Ch]
  float v21; // [esp+78h] [ebp-1Ch]
  float v22; // [esp+7Ch] [ebp-18h]
  float v23; // [esp+80h] [ebp-14h]
  int v24; // [esp+88h] [ebp-Ch]
  int v25; // [esp+8Ch] [ebp-8h]
  int retaddr; // [esp+94h] [ebp+0h]

  v24 = a2;
  v25 = retaddr;
  v8 = this;
  v9 = phys_Unitize((phys_vec3 *)&v21, b1_axis_loc);
  v8->m_b1_axis_loc.x = v9->x;
  v10 = (int)&v8->m_b1_axis_loc;
  *(float *)(v10 + 4) = v9->y;
  *(float *)(v10 + 8) = v9->z;
  v11 = phys_Unitize((phys_vec3 *)&v21, b2_axis_loc);
  v8->m_b2_axis_loc.x = v11->x;
  v8->m_b2_axis_loc.y = v11->y;
  v8->m_b2_axis_loc.z = v11->z;
  v12 = phys_Unitize((phys_vec3 *)&v21, b1_ref_loc);
  v8->m_b1_ref_loc.x = v12->x;
  v8->m_b1_ref_loc.y = v12->y;
  v8->m_b1_ref_loc.z = v12->z;
  v8->m_flags |= 4u;
  v13 = construct_orth_ud((phys_vec3 *)&v21, &v8->m_b1_axis_loc);
  v8->m_b1_a1_loc.x = v13->x;
  v8->m_b1_a1_loc.y = v13->y;
  v8->m_b1_a1_loc.z = v13->z;
  v21 = v8->m_b1_a1_loc.z * v8->m_b1_axis_loc.y - v8->m_b1_a1_loc.y * v8->m_b1_axis_loc.z;
  v22 = v8->m_b1_axis_loc.z * v8->m_b1_a1_loc.x - v8->m_b1_a1_loc.z * v8->m_b1_axis_loc.x;
  v23 = v8->m_b1_a1_loc.y * v8->m_b1_axis_loc.x - v8->m_b1_axis_loc.y * v8->m_b1_a1_loc.x;
  v8->m_b1_a2_loc.x = v21;
  v8->m_b1_a2_loc.y = v22;
  v8->m_b1_a2_loc.z = v23;
  make_rotate((phys_mat44 *)&v18, &v8->m_b2_axis_loc, theta_min, 1000.0);
  v14 = phys_multiply((phys_vec3 *)&v21, (phys_mat44 *)&v18, b2_ref_loc);
  v15 = phys_Unitize((phys_vec3 *)&v20, v14);
  v8->m_b2_ref_min_loc.x = v15->x;
  v8->m_b2_ref_min_loc.y = v15->y;
  v8->m_b2_ref_min_loc.z = v15->z;
  make_rotate((phys_mat44 *)&v18, &v8->m_b2_axis_loc, theta_max, 1000.0);
  v16 = phys_multiply((phys_vec3 *)&v20, (phys_mat44 *)&v18, b2_ref_loc);
  v17 = phys_Unitize((phys_vec3 *)((char *)&rv.w + 4), v16);
  v8->m_b2_ref_max_loc.x = v17->x;
  v8->m_b2_ref_max_loc.y = v17->y;
  v8->m_b2_ref_max_loc.z = v17->z;
}

/*
==============
rigid_body_constraint_ragdoll::set_swivel
==============
*/
void __userpurge rigid_body_constraint_ragdoll::set_swivel(rigid_body_constraint_ragdoll *this@<ecx>, int a2@<ebp>, phys_vec3 *b1_axis_loc, phys_vec3 *b2_axis_loc, phys_vec3 *b1_ref_loc, phys_vec3 *b2_ref_loc, const float theta_min, const float theta_max)
{
  rigid_body_constraint_ragdoll *v8; // esi
  phys_vec3 *v9; // eax
  phys_vec3 *v10; // eax
  int v11; // edi
  phys_vec3 *v12; // eax
  phys_vec3 *v13; // eax
  phys_vec3 *v14; // eax
  phys_vec3 *v15; // eax
  phys_vec3 *v16; // eax
  int v17; // [esp+18h] [ebp-7Ch]
  phys_mat44 rv; // [esp+24h] [ebp-70h]
  int v19; // [esp+68h] [ebp-2Ch]
  int v20; // [esp+78h] [ebp-1Ch]
  int v21; // [esp+88h] [ebp-Ch]
  int v22; // [esp+8Ch] [ebp-8h]
  int retaddr; // [esp+94h] [ebp+0h]

  v21 = a2;
  v22 = retaddr;
  v8 = this;
  v9 = phys_Unitize((phys_vec3 *)&v20, b1_axis_loc);
  v8->m_b1_axis_loc.x = v9->x;
  v8->m_b1_axis_loc.y = v9->y;
  v8->m_b1_axis_loc.z = v9->z;
  v10 = phys_Unitize((phys_vec3 *)&v20, b2_axis_loc);
  v8->m_b2_axis_loc.x = v10->x;
  v11 = (int)&v8->m_b2_axis_loc;
  *(float *)(v11 + 4) = v10->y;
  *(float *)(v11 + 8) = v10->z;
  v12 = phys_Unitize((phys_vec3 *)&v20, b1_ref_loc);
  v8->m_b1_ref_loc.x = v12->x;
  v8->m_b1_ref_loc.y = v12->y;
  v8->m_b1_ref_loc.z = v12->z;
  v8->m_flags |= 8u;
  make_rotate((phys_mat44 *)&v17, &v8->m_b2_axis_loc, theta_min, 1000.0);
  v13 = phys_multiply((phys_vec3 *)&v20, (phys_mat44 *)&v17, b2_ref_loc);
  v14 = phys_Unitize((phys_vec3 *)&v19, v13);
  v8->m_b2_ref_min_loc.x = v14->x;
  v8->m_b2_ref_min_loc.y = v14->y;
  v8->m_b2_ref_min_loc.z = v14->z;
  make_rotate((phys_mat44 *)&v17, &v8->m_b2_axis_loc, theta_max, 1000.0);
  v15 = phys_multiply((phys_vec3 *)&v19, (phys_mat44 *)&v17, b2_ref_loc);
  v16 = phys_Unitize((phys_vec3 *)((char *)&rv.w + 4), v15);
  v8->m_b2_ref_max_loc.x = v16->x;
  v8->m_b2_ref_max_loc.y = v16->y;
  v8->m_b2_ref_max_loc.z = v16->z;
}

/*
==============
rigid_body_constraint_ragdoll::add_joint_limit
==============
*/
void __thiscall rigid_body_constraint_ragdoll::add_joint_limit(rigid_body_constraint_ragdoll *this, phys_vec3 *b1_ud_loc, const float theta_limit)
{
  rigid_body_constraint_ragdoll *v3; // esi
  int savedregs; // [esp+8h] [ebp+0h]

  v3 = this;
  if ( this->m_joint_limits_count >= 2
    && _tlAssert("source/rbc_def_ragdoll.cpp", 102, "m_joint_limits_count < MAX_JOINT_LIMITS", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ragdoll_joint_limit_info::set(&v3->m_joint_limits[v3->m_joint_limits_count], (int)&savedregs, b1_ud_loc, theta_limit);
  ++v3->m_joint_limits_count;
}

/*
==============
rigid_body_constraint_ragdoll::pull_together
==============
*/
double __usercall rigid_body_constraint_ragdoll::pull_together@<st0>(rigid_body_constraint_ragdoll *this@<ecx>, int a2@<ebp>)
{
  rigid_body_constraint_ragdoll *v2; // edi
  phys_mat44 *v3; // esi
  phys_vec3 *v4; // eax
  double v5; // st7
  float *v6; // esi
  phys_mat44 *v7; // ST04_4
  phys_vec3 *v8; // eax
  float *v9; // ecx
  long double v10; // st6
  long double v11; // st6
  int v13; // [esp-3Ch] [ebp-5Ch]
  float v14; // [esp-2Ch] [ebp-4Ch]
  float v15; // [esp-28h] [ebp-48h]
  float v16; // [esp-24h] [ebp-44h]
  float v17; // [esp-1Ch] [ebp-3Ch]
  float v18; // [esp-18h] [ebp-38h]
  float v19; // [esp-14h] [ebp-34h]
  float v20; // [esp-Ch] [ebp-2Ch]
  float v21; // [esp-8h] [ebp-28h]
  float v22; // [esp-4h] [ebp-24h]
  float v23; // [esp+10h] [ebp-10h]
  int v24; // [esp+14h] [ebp-Ch]
  int v25; // [esp+18h] [ebp-8h]
  int retaddr; // [esp+20h] [ebp+0h]

  v24 = a2;
  v25 = retaddr;
  v2 = this;
  v3 = &this->b2->m_mat;
  v4 = phys_multiply((phys_vec3 *)&v20, v3, &this->m_b2_r_loc);
  v14 = v4->x + v3->w.x;
  v15 = v4->y + v3->w.y;
  v5 = v4->z + v3->w.z;
  v6 = &v2->b1->m_mat.x.x;
  v7 = &v2->b1->m_mat;
  v16 = v5;
  v8 = phys_multiply((phys_vec3 *)&v13, v7, &v2->m_b1_r_loc);
  v17 = v8->x + v6[12];
  v18 = v8->y + v6[13];
  v9 = &v2->b2->m_last_position.x;
  v19 = v8->z + v6[14];
  v20 = v17 - v14;
  v21 = v18 - v15;
  v22 = v19 - v16;
  v9[24] = v9[24] + v20;
  v9[25] = v21 + v9[25];
  v9[26] = v9[26] + v22;
  if ( v9[24] != v9[24]
    || (v23 = fabs(v9[24]), v23 > 100000.0)
    || (v10 = v9[25], v23 = fabs(v10), v23 > 100000.0)
    || (v11 = v9[26], v23 = fabs(v11), v23 > 100000.0) )
  {
    phys_exec_debug_callback(v9);
  }
  return (float)(v22 * v22 + v20 * v20 + v21 * v21);
}

/*
==============
rigid_body_constraint_ragdoll::setup_hinge
==============
*/
void __userpurge rigid_body_constraint_ragdoll::setup_hinge(rigid_body_constraint_ragdoll *this@<ecx>, int a2@<ebp>, pulse_sum_constraint_solver *psys, phys_vec3 *b1_ref, phys_vec3 *b2_axis, const float delta_t)
{
  rigid_body *v6; // eax
  rigid_body *v7; // edx
  rigid_body *v8; // ecx
  pulse_sum_angular *v9; // eax
  pulse_sum_angular *v10; // eax
  float v11; // [esp+18h] [ebp-4Ch]
  float v12; // [esp+1Ch] [ebp-48h]
  float v13; // [esp+20h] [ebp-44h]
  phys_vec3 b2_ref_max; // [esp+24h] [ebp-40h]
  phys_vec3 b2_ref_min; // [esp+34h] [ebp-30h]
  float v16; // [esp+50h] [ebp-14h]
  rigid_body_constraint_ragdoll *v17; // [esp+54h] [ebp-10h]
  int v18; // [esp+58h] [ebp-Ch]
  int v19; // [esp+5Ch] [ebp-8h]
  int retaddr; // [esp+64h] [ebp+0h]

  v18 = a2;
  v19 = retaddr;
  v6 = this->b2;
  v17 = this;
  phys_multiply((phys_vec3 *)((char *)&b2_ref_max + 4), &v6->m_mat, &this->m_b2_ref_min_loc);
  b2_ref_min.y = b1_ref->y * b2_ref_max.w - b1_ref->z * b2_ref_max.z;
  b2_ref_min.z = b1_ref->z * b2_ref_max.y - b2_ref_max.w * b1_ref->x;
  b2_ref_min.w = b2_ref_max.z * b1_ref->x - b2_ref_max.y * b1_ref->y;
  v16 = b2_axis->y * b2_ref_min.z + b2_axis->x * b2_ref_min.y + b2_axis->z * b2_ref_min.w;
  if ( v16 >= -0.043618999 )
  {
    b2_ref_min.y = -b2_axis->x;
    v7 = v17->b1;
    b2_ref_min.z = -b2_axis->y;
    v8 = v17->b2;
    b2_ref_min.w = -b2_axis->z;
    v9 = pulse_sum_constraint_solver::create_pulse_sum_angular(
           psys,
           v7,
           b1_ref,
           v8,
           (phys_vec3 *)((char *)&b2_ref_max + 4),
           (phys_vec3 *)((char *)&b2_ref_min + 4),
           &v17->m_ps_cache_list[6]);
    v9->m_pulse_sum_min = -10000000.0;
    v9->m_pulse_sum_max = 0.0;
    pulse_sum_angular::setup_vel_uni_standard(v9, delta_t, 5.0);
  }
  phys_multiply((phys_vec3 *)&v11, &v17->b2->m_mat, &v17->m_b2_ref_max_loc);
  b2_ref_min.y = b1_ref->y * v13 - b1_ref->z * v12;
  b2_ref_min.z = b1_ref->z * v11 - v13 * b1_ref->x;
  b2_ref_min.w = v12 * b1_ref->x - v11 * b1_ref->y;
  v16 = b2_axis->x * b2_ref_min.y + b2_axis->y * b2_ref_min.z + b2_axis->z * b2_ref_min.w;
  if ( v16 <= 0.043618999 )
  {
    v10 = pulse_sum_constraint_solver::create_pulse_sum_angular(
            psys,
            v17->b1,
            b1_ref,
            v17->b2,
            (phys_vec3 *)&v11,
            b2_axis,
            &v17->m_ps_cache_list[7]);
    v10->m_pulse_sum_min = -10000000.0;
    v10->m_pulse_sum_max = 0.0;
    pulse_sum_angular::setup_vel_uni_standard(v10, delta_t, 5.0);
  }
}

/*
==============
rigid_body_constraint_ragdoll::setup_constraint
==============
*/
void __userpurge rigid_body_constraint_ragdoll::setup_constraint(rigid_body_constraint_ragdoll *this@<ecx>, int a2@<ebp>, pulse_sum_constraint_solver *psys, const float delta_t)
{
  rigid_body_constraint_ragdoll *v4; // esi
  rigid_body *v5; // edi
  rigid_body *v6; // edi
  float *v7; // eax
  double v8; // st7
  pulse_sum_angular *v9; // eax
  double v10; // st7
  double v11; // st7
  rigid_body *v12; // edi
  unsigned int v13; // eax
  bool v14; // zf
  bool v15; // sf
  float *v16; // edi
  double v17; // st2
  double v18; // st7
  pulse_sum_angular *v19; // eax
  phys_vec3 *v20; // eax
  int v21; // [esp+20h] [ebp-FCh]
  phys_mat44 rv; // [esp+2Ch] [ebp-F0h]
  phys_vec3 b1_axis; // [esp+6Ch] [ebp-B0h]
  float v24; // [esp+80h] [ebp-9Ch]
  float v25; // [esp+84h] [ebp-98h]
  float v26; // [esp+88h] [ebp-94h]
  float v27; // [esp+90h] [ebp-8Ch]
  float v28; // [esp+94h] [ebp-88h]
  float v29; // [esp+98h] [ebp-84h]
  float v30; // [esp+A0h] [ebp-7Ch]
  float v31; // [esp+A4h] [ebp-78h]
  float v32; // [esp+A8h] [ebp-74h]
  phys_vec3 b1_r_; // [esp+ACh] [ebp-70h]
  phys_vec3 b1_ud; // [esp+BCh] [ebp-60h]
  float v35; // [esp+D0h] [ebp-4Ch]
  float v36; // [esp+D4h] [ebp-48h]
  float v37; // [esp+D8h] [ebp-44h]
  phys_vec3 b2_axis; // [esp+DCh] [ebp-40h]
  phys_vec3 axis; // [esp+ECh] [ebp-30h]
  phys_vec3 b1_r_length; // [esp+FCh] [ebp-20h]
  float v41; // [esp+10Ch] [ebp-10h]
  int i; // [esp+110h] [ebp-Ch]
  int v43; // [esp+114h] [ebp-8h]
  int retaddr; // [esp+11Ch] [ebp+0h]

  i = a2;
  v43 = retaddr;
  v4 = this;
  v5 = this->b2;
  phys_multiply((phys_vec3 *)((char *)&b2_axis + 4), &v5->m_mat, &this->m_b2_r_loc);
  phys_multiply((phys_vec3 *)((char *)&b1_ud + 4), &v4->b1->m_mat, &v4->m_b1_r_loc);
  pulse_sum_constraint_solver::create_point(
    psys,
    v4->b1,
    (phys_vec3 *)((char *)&b1_ud + 4),
    v5,
    (phys_vec3 *)((char *)&b2_axis + 4),
    v4->m_ps_cache_list,
    delta_t,
    0,
    0.0,
    0.0);
  v6 = v4->b1;
  phys_multiply((phys_vec3 *)((char *)&rv.w + 4), &v4->b1->m_mat, &v4->m_b1_axis_loc);
  phys_multiply((phys_vec3 *)&v35, &v4->b2->m_mat, &v4->m_b2_axis_loc);
  if ( v4->m_flags & 0x40 )
  {
    v7 = &v4->b2->m_last_position.x;
    b1_r_length.w = v7[41] - v6->m_a_vel.y;
    b1_r_length.z = v7[42] - v6->m_a_vel.z;
    axis.y = v7[40] - v6->m_a_vel.x;
    v41 = b1_r_length.w * b1_r_length.w + axis.y * axis.y + b1_r_length.z * b1_r_length.z;
    v41 = sqrt(v41);
    if ( v41 <= 0.00009999999747378752 )
    {
      axis.y = v35;
      axis.z = v36;
      v8 = v37;
    }
    else
    {
      v41 = 1.0 / v41;
      axis.y = v41 * axis.y;
      axis.z = v41 * b1_r_length.w;
      v8 = v41 * b1_r_length.z;
    }
    axis.w = v8;
    v9 = pulse_sum_constraint_solver::create_pulse_sum_angular(
           psys,
           v6,
           &PHYS_ZERO_VEC_95,
           v4->b2,
           &PHYS_ZERO_VEC_95,
           (phys_vec3 *)((char *)&axis + 4),
           &v4->m_ps_cache_list[3]);
    if ( v4->m_flags & 0x200 )
    {
      v41 = 1.0 / (v4->m_damp_k * delta_t);
      v9->m_right_side = 0.0;
      v9->m_big_dirt = 0.0;
      v10 = v41;
      v9->m_cfm = v41;
      v9->m_denom = v10 + v9->m_denom;
      v9->m_pulse_sum_min = -10000000.0;
      v11 = 10000000.0;
    }
    else
    {
      v9->m_right_side = 0.0;
      v9->m_big_dirt = 0.0;
      v9->m_cfm = 0.0;
      v41 = v4->m_damp_k * delta_t;
      v11 = v41;
      v9->m_pulse_sum_min = -v41;
    }
    v9->m_pulse_sum_max = v11;
  }
  if ( v4->m_flags & 4 )
  {
    v12 = v4->b1;
    phys_multiply((phys_vec3 *)((char *)&b2_axis + 4), &v4->b1->m_mat, &v4->m_b1_a2_loc);
    phys_multiply((phys_vec3 *)((char *)&b1_ud + 4), &v12->m_mat, &v4->m_b1_a1_loc);
    pulse_sum_constraint_solver::create_hinge(
      psys,
      v12,
      (phys_vec3 *)((char *)&rv.w + 4),
      v4->b2,
      (phys_vec3 *)&v35,
      (phys_vec3 *)((char *)&b1_ud + 4),
      (phys_vec3 *)((char *)&b2_axis + 4),
      &v4->m_ps_cache_list[4],
      delta_t);
    phys_multiply((phys_vec3 *)((char *)&b2_axis + 4), &v4->b1->m_mat, &v4->m_b1_ref_loc);
    rigid_body_constraint_ragdoll::setup_hinge(
      v4,
      (int)&i,
      psys,
      (phys_vec3 *)((char *)&b2_axis + 4),
      (phys_vec3 *)&v35,
      delta_t);
  }
  v13 = v4->m_flags;
  if ( v13 & 8 )
  {
    if ( !(v13 & 0x100) )
    {
      v14 = v4->m_joint_limits_count == 0;
      v15 = v4->m_joint_limits_count < 0;
      b1_r_length.z = 0.0;
      if ( !v15 && !v14 )
      {
        LODWORD(b1_r_length.w) = (char *)v4 + 84;
        v16 = &v4->m_joint_limits[0].m_b1_ud_limit_si_;
        do
        {
          phys_multiply((phys_vec3 *)((char *)&b1_r_ + 4), &v4->b1->m_mat, (phys_vec3 *)(v16 - 5));
          v41 = b1_r_.w * v37 + b1_r_.y * v35 + b1_r_.z * v36;
          v17 = v41;
          if ( v16[1] >= (double)v41 )
          {
            b1_axis.y = b1_r_.y * v17;
            b1_axis.z = b1_r_.z * v17;
            b1_axis.w = v17 * b1_r_.w;
            axis.y = v35 - b1_axis.y;
            axis.z = v36 - b1_axis.z;
            axis.w = v37 - b1_axis.w;
            v41 = axis.z * axis.z + axis.y * axis.y + axis.w * axis.w;
            v41 = sqrt(v41);
            v18 = v41;
            if ( v41 >= 0.00009999999747378752 )
            {
              v41 = *(v16 - 1);
              v24 = v41 * b1_r_.y;
              v25 = b1_r_.z * v41;
              v26 = v41 * b1_r_.w;
              v41 = *v16 / v18;
              v27 = axis.y * v41;
              v28 = axis.z * v41;
              v29 = v41 * axis.w;
              v30 = v27 + v24;
              v31 = v28 + v25;
              v32 = v29 + v26;
              b1_ud.y = v31 * b1_r_.w - v32 * b1_r_.z;
              b1_ud.z = v32 * b1_r_.y - b1_r_.w * v30;
              b1_ud.w = v30 * b1_r_.z - v31 * b1_r_.y;
              v41 = 1.0 / *v16;
              b2_axis.y = b1_ud.y * v41;
              b2_axis.z = b1_ud.z * v41;
              b2_axis.w = v41 * b1_ud.w;
              PHYS_ASSERT_UNIT((phys_vec3 *)((char *)&b2_axis + 4));
              v19 = pulse_sum_constraint_solver::create_pulse_sum_angular(
                      psys,
                      v4->b1,
                      (phys_vec3 *)&v30,
                      v4->b2,
                      (phys_vec3 *)&v35,
                      (phys_vec3 *)((char *)&b2_axis + 4),
                      (pulse_sum_cache *const )LODWORD(b1_r_length.w));
              v19->m_pulse_sum_min = -10000000.0;
              v19->m_pulse_sum_max = 0.0;
              pulse_sum_angular::setup_vel_uni_standard(v19, delta_t, 5.0);
            }
          }
          LODWORD(b1_r_length.w) += 4;
          v16 += 8;
          ++LODWORD(b1_r_length.z);
        }
        while ( SLODWORD(b1_r_length.z) < v4->m_joint_limits_count );
      }
    }
    make_rotate((phys_mat44 *)&v21, (phys_vec3 *)((char *)&rv.w + 4), (phys_vec3 *)&v35);
    phys_multiply((phys_vec3 *)((char *)&b2_axis + 4), &v4->b1->m_mat, &v4->m_b1_ref_loc);
    v20 = phys_multiply((phys_vec3 *)((char *)&b1_ud + 4), (phys_mat44 *)&v21, (phys_vec3 *)((char *)&b2_axis + 4));
    rigid_body_constraint_ragdoll::setup_hinge(v4, (int)&i, psys, v20, (phys_vec3 *)&v35, delta_t);
  }
}

