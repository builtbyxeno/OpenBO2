/*
 * Copyright (c) 2020-2021 OpenIW
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
==============
pulse_sum_point::get_vel
==============
*/
phys_vec3 *__userpurge pulse_sum_point::get_vel@<eax>(pulse_sum_point *this@<ecx>, int a2@<ebp>, phys_vec3 *result)
{
  rigid_body *v3; // eax
  float *v4; // edx
  rigid_body *v5; // eax
  double v6; // st7
  phys_vec3 *v7; // eax
  float v8; // [esp-30h] [ebp-3Ch]
  float v9; // [esp-2Ch] [ebp-38h]
  float v10; // [esp-28h] [ebp-34h]
  float v11; // [esp-20h] [ebp-2Ch]
  float v12; // [esp-1Ch] [ebp-28h]
  float v13; // [esp-18h] [ebp-24h]
  float v14; // [esp-10h] [ebp-1Ch]
  float v15; // [esp-Ch] [ebp-18h]
  float v16; // [esp-8h] [ebp-14h]
  int v17; // [esp+0h] [ebp-Ch]
  int v18; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v17 = a2;
  v18 = retaddr;
  if ( this->m_b2 )
  {
    v3 = this->m_b2->m_rb;
    v4 = &v8;
    v14 = this->m_b2_r.z * v3->m_a_vel.y - this->m_b2_r.y * v3->m_a_vel.z;
    v15 = this->m_b2_r.x * v3->m_a_vel.z - this->m_b2_r.z * v3->m_a_vel.x;
    v16 = this->m_b2_r.y * v3->m_a_vel.x - v3->m_a_vel.y * this->m_b2_r.x;
    v8 = v3->m_t_vel.x + v14;
    v9 = v3->m_t_vel.y + v15;
    v10 = v3->m_t_vel.z + v16;
  }
  else
  {
    v4 = &this->m_b2_apx.x;
  }
  v5 = this->m_b1->m_rb;
  v14 = this->m_b1_r.z * v5->m_a_vel.y - this->m_b1_r.y * v5->m_a_vel.z;
  v15 = this->m_b1_r.x * v5->m_a_vel.z - this->m_b1_r.z * v5->m_a_vel.x;
  v16 = v5->m_a_vel.x * this->m_b1_r.y - v5->m_a_vel.y * this->m_b1_r.x;
  v11 = v5->m_t_vel.x + v14;
  v12 = v5->m_t_vel.y + v15;
  v6 = v5->m_t_vel.z;
  v7 = result;
  v13 = v6 + v16;
  result->x = v11 - *v4;
  result->y = v12 - v4[1];
  result->z = v13 - v4[2];
  return v7;
}

/*
==============
pulse_sum_point::get_pos
==============
*/
phys_vec3 *__userpurge pulse_sum_point::get_pos@<eax>(pulse_sum_point *this@<ecx>, int a2@<ebp>, phys_vec3 *result)
{
  pulse_sum_node *v3; // eax
  float *v4; // eax
  float *v5; // edx
  rigid_body *v6; // eax
  double v7; // st7
  phys_vec3 *v8; // eax
  float v9; // [esp-20h] [ebp-2Ch]
  float v10; // [esp-1Ch] [ebp-28h]
  float v11; // [esp-18h] [ebp-24h]
  float v12; // [esp-10h] [ebp-1Ch]
  float v13; // [esp-Ch] [ebp-18h]
  float v14; // [esp-8h] [ebp-14h]
  int v15; // [esp+0h] [ebp-Ch]
  int v16; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v15 = a2;
  v16 = retaddr;
  v3 = this->m_b2;
  if ( v3 )
  {
    v4 = &v3->m_rb->m_last_position.x;
    v5 = &v9;
    v9 = this->m_b2_r.x + v4[24];
    v10 = this->m_b2_r.y + v4[25];
    v11 = this->m_b2_r.z + v4[26];
  }
  else
  {
    v5 = &this->m_b2_r.x;
  }
  v6 = this->m_b1->m_rb;
  v12 = v6->m_mat.w.x + this->m_b1_r.x;
  v13 = v6->m_mat.w.y + this->m_b1_r.y;
  v7 = v6->m_mat.w.z;
  v8 = result;
  v14 = v7 + this->m_b1_r.z;
  result->x = v12 - *v5;
  result->y = v13 - v5[1];
  result->z = v14 - v5[2];
  return v8;
}

/*
==============
pulse_sum_point::set
==============
*/
void __userpurge pulse_sum_point::set(pulse_sum_point *this@<ecx>, int a2@<ebp>, rigid_body *const b1, phys_vec3 *b1_r, rigid_body *const b2, phys_vec3 *b2_r, pulse_sum_cache *const ps_cache, const float delta_t, const bool is_spring, const float spring_k, const float damp_k)
{
  pulse_sum_point *v11; // esi
  unsigned int v12; // eax
  unsigned int v13; // eax
  pulse_sum_node *v14; // eax
  double v15; // st7
  phys_vec3 *v16; // eax
  bool v17; // zf
  float v18; // [esp+20h] [ebp-1Ch]
  float v19; // [esp+24h] [ebp-18h]
  float v20; // [esp+28h] [ebp-14h]
  int v21; // [esp+30h] [ebp-Ch]
  int v22; // [esp+34h] [ebp-8h]
  int retaddr; // [esp+3Ch] [ebp+0h]

  v21 = a2;
  v22 = retaddr;
  v11 = this;
  if ( !ps_cache
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_point_inline.h",
         167,
         "ps_cache",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !b1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_point_inline.h",
         168,
         "b1",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !b2
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_point_inline.h",
         169,
         "b2",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( b1 == b2
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_point_inline.h",
         170,
         "b1 != b2",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !b1->m_node
    && !b2->m_node
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_point_inline.h",
         171,
         "rbint::get_pulse_sum_node(b1) || rbint::get_pulse_sum_node(b2)",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( b1->m_node )
    v12 = (b1->m_flags & 0x30) == 0;
  else
    v12 = b1->m_flags & 0x30;
  if ( !v12 || (!b2->m_node ? (v13 = b2->m_flags & 0x30) : (v13 = (b2->m_flags & 0x30) == 0), !v13) )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_point_inline.h",
           172,
           "rbint::verify_pulse_sum_node(b1) && rbint::verify_pulse_sum_node(b2)",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
  if ( !b1->m_node
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_point_inline.h",
         174,
         "rbint::get_pulse_sum_node(b1) != NULL",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v11->m_b1 = b1->m_node;
  v11->m_b1_r.x = b1_r->x;
  v11->m_b1_r.y = b1_r->y;
  v11->m_b1_r.z = b1_r->z;
  v14 = b2->m_node;
  if ( v14 )
  {
    v11->m_b2 = v14;
    v11->m_b2_r.x = b2_r->x;
    v11->m_b2_r.y = b2_r->y;
    v15 = b2_r->z;
  }
  else
  {
    v11->m_b2 = NULL;
    v16 = rbint::gtv((phys_vec3 *)&v18, b2, b2_r);
    v11->m_b2_apx.x = v16->x;
    v11->m_b2_apx.y = v16->y;
    v11->m_b2_apx.z = v16->z;
    v17 = v11->m_b2 == NULL;
    v18 = b2_r->x + b2->m_mat.w.x;
    v19 = b2->m_mat.w.y + b2_r->y;
    v20 = b2->m_mat.w.z + b2_r->z;
    if ( !v17
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_point.h",
           47,
           "m_b2 == NULL",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v11->m_b2_r.x = v18;
    v11->m_b2_r.y = v19;
    v15 = v20;
  }
  v11->m_b2_r.z = v15;
  v11->m_pulse_sum_cache = ps_cache;
  pulse_sum_point::calc_abs_and_setup(v11, delta_t, is_spring, spring_k, damp_k);
}

/*
==============
pulse_sum_point::get_objective
==============
*/
phys_vec3 *__thiscall pulse_sum_point::get_objective(pulse_sum_point *this, phys_vec3 *result)
{
  bool v2; // zf
  pulse_sum_node *v3; // edx
  phys_vec3 *v4; // eax
  float v5; // ST10_4
  float v6; // ST14_4
  float v7; // ST18_4
  float v8; // ST2C_4
  double v9; // st7
  float v10; // ST2C_4
  double v11; // st6
  pulse_sum_node *v12; // edx
  float v13; // ST10_4
  float v14; // ST14_4
  float v15; // ST18_4
  float v16; // ST00_4
  float v17; // ST04_4
  float v18; // ST08_4
  float v19; // [esp-4h] [ebp-10h]

  v2 = this->m_b2 == NULL;
  v3 = this->m_b1;
  v4 = result;
  v5 = v3->a_vel.y * this->m_b1_r.z - v3->a_vel.z * this->m_b1_r.y;
  v6 = this->m_b1_r.x * v3->a_vel.z - this->m_b1_r.z * v3->a_vel.x;
  v7 = this->m_b1_r.y * v3->a_vel.x - this->m_b1_r.x * v3->a_vel.y;
  v8 = v3->t_vel.x + v5;
  v9 = v8;
  result->x = v8;
  v10 = v3->t_vel.y + v6;
  v11 = v10;
  result->y = v10;
  v19 = v3->t_vel.z + v7;
  result->z = v19;
  if ( !v2 )
  {
    v12 = this->m_b2;
    v13 = v12->a_vel.y * this->m_b2_r.z - v12->a_vel.z * this->m_b2_r.y;
    v14 = v12->a_vel.z * this->m_b2_r.x - v12->a_vel.x * this->m_b2_r.z;
    v15 = v12->a_vel.x * this->m_b2_r.y - v12->a_vel.y * this->m_b2_r.x;
    v16 = v12->t_vel.x + v13;
    v17 = v12->t_vel.y + v14;
    v18 = v12->t_vel.z + v15;
    result->x = v9 - v16;
    result->y = v11 - v17;
    result->z = v19 - v18;
  }
  return v4;
}

/*
==============
pulse_sum_point::apply
==============
*/
void __thiscall pulse_sum_point::apply(pulse_sum_point *this, phys_vec3 *s_)
{
  pulse_sum_node *v2; // edx
  float v3; // ST4C_4
  float v4; // ST30_4
  float v5; // ST34_4
  float v6; // ST38_4
  pulse_sum_node *v7; // edx
  float v8; // ST4C_4
  float v9; // ST00_4
  float v10; // ST04_4
  float v11; // ST08_4
  float v12; // ST4C_4
  float v13; // ST20_4
  float v14; // ST24_4
  float v15; // ST28_4
  float v16; // ST30_4
  float v17; // ST34_4
  float v18; // ST38_4
  float v19; // ST10_4
  float v20; // ST14_4
  float v21; // ST18_4
  float v22; // ST20_4
  float v23; // ST24_4
  float v24; // ST28_4
  pulse_sum_node *v25; // edx
  float v26; // ST4C_4
  float v27; // ST00_4
  float v28; // ST04_4
  float v29; // ST08_4
  float v30; // ST4C_4
  float v31; // ST30_4
  float v32; // ST34_4
  float v33; // ST38_4
  float v34; // ST4C_4
  float v35; // ST10_4
  float v36; // ST14_4
  float v37; // ST18_4
  double v38; // st7
  float v39; // ST00_4
  float v40; // ST04_4
  double v41; // st7
  pulse_sum_node *v42; // ecx
  float v43; // ST08_4
  float v44; // ST20_4
  float v45; // ST24_4
  float v46; // ST28_4
  float v47; // ST00_4
  float v48; // ST04_4
  float v49; // ST08_4

  v2 = this->m_b1;
  v3 = v2->m_inv_mass;
  v4 = s_->x * v3;
  v5 = v3 * s_->y;
  v6 = v3 * s_->z;
  v2->t_vel.x = v2->t_vel.x + v4;
  v2->t_vel.y = v2->t_vel.y + v5;
  v2->t_vel.z = v2->t_vel.z + v6;
  v7 = this->m_b1;
  v8 = s_->z;
  v9 = this->m_b1_apz.x * v8;
  v10 = this->m_b1_apz.y * v8;
  v11 = v8 * this->m_b1_apz.z;
  v12 = s_->y;
  v13 = v12 * this->m_b1_apy.x;
  v14 = this->m_b1_apy.y * v12;
  v15 = v12 * this->m_b1_apy.z;
  v16 = this->m_b1_apx.x * s_->x;
  v17 = this->m_b1_apx.y * s_->x;
  v18 = s_->x * this->m_b1_apx.z;
  v19 = v16 + v13;
  v20 = v17 + v14;
  v21 = v18 + v15;
  v22 = v19 + v9;
  v23 = v20 + v10;
  v24 = v21 + v11;
  v7->a_vel.x = v7->a_vel.x + v22;
  v7->a_vel.y = v7->a_vel.y + v23;
  v7->a_vel.z = v24 + v7->a_vel.z;
  if ( this->m_b2 )
  {
    v25 = this->m_b2;
    v26 = v25->m_inv_mass;
    v27 = s_->x * v26;
    v28 = v26 * s_->y;
    v29 = v26 * s_->z;
    v25->t_vel.x = v25->t_vel.x - v27;
    v25->t_vel.y = v25->t_vel.y - v28;
    v25->t_vel.z = v25->t_vel.z - v29;
    v30 = s_->z;
    v31 = this->m_b2_apz.x * v30;
    v32 = this->m_b2_apz.y * v30;
    v33 = v30 * this->m_b2_apz.z;
    v34 = s_->y;
    v35 = v34 * this->m_b2_apy.x;
    v36 = this->m_b2_apy.y * v34;
    v37 = v34 * this->m_b2_apy.z;
    v38 = s_->x;
    v39 = this->m_b2_apx.x * v38;
    v40 = this->m_b2_apx.y * v38;
    v41 = v38 * this->m_b2_apx.z;
    v42 = this->m_b2;
    v43 = v41;
    v44 = v39 + v35;
    v45 = v40 + v36;
    v46 = v43 + v37;
    v47 = v44 + v31;
    v48 = v45 + v32;
    v49 = v46 + v33;
    v42->a_vel.x = v42->a_vel.x - v47;
    v42->a_vel.y = v42->a_vel.y - v48;
    v42->a_vel.z = v42->a_vel.z - v49;
  }
}

/*
==============
pulse_sum_point::SOLVER_apply_relaxation
==============
*/
void __userpurge pulse_sum_point::SOLVER_apply_relaxation(pulse_sum_point *this@<ecx>, int a2@<ebp>, float *error_sq)
{
  pulse_sum_point *v3; // esi
  phys_vec3 *v4; // eax
  float v5; // ecx
  float v6; // edx
  double v7; // st7
  float v8; // eax
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  float v14; // [esp-1Ch] [ebp-6Ch]
  float v15; // [esp-18h] [ebp-68h]
  float v16; // [esp-14h] [ebp-64h]
  float v17; // [esp-Ch] [ebp-5Ch]
  float v18; // [esp-8h] [ebp-58h]
  float v19; // [esp-4h] [ebp-54h]
  phys_vec3 error_; // [esp+0h] [ebp-50h]
  float v21; // [esp+14h] [ebp-3Ch]
  float v22; // [esp+18h] [ebp-38h]
  float v23; // [esp+1Ch] [ebp-34h]
  phys_vec3 m_objective; // [esp+20h] [ebp-30h]
  phys_vec3 m_last_pulse_sum; // [esp+30h] [ebp-20h]
  float v26; // [esp+40h] [ebp-10h]
  int v27; // [esp+44h] [ebp-Ch]
  int v28; // [esp+48h] [ebp-8h]
  int retaddr; // [esp+50h] [ebp+0h]

  v27 = a2;
  v28 = retaddr;
  v3 = this;
  v26 = this->m_cfm;
  v21 = v26 * this->m_pulse_sum.x;
  v22 = this->m_pulse_sum.y * v26;
  v23 = v26 * this->m_pulse_sum.z;
  v4 = pulse_sum_point::get_objective(this, (phys_vec3 *)&v14);
  v5 = v3->m_pulse_sum.x;
  v6 = v3->m_pulse_sum.y;
  m_objective.y = v4->x + v21;
  m_objective.z = v4->y + v22;
  v7 = v4->z;
  v8 = v3->m_pulse_sum.z;
  m_objective.w = v7 + v23;
  v9 = m_objective.y;
  m_objective.y = v5;
  v10 = v9 - v3->m_right_side.x;
  m_last_pulse_sum.x = v3->m_pulse_sum.w;
  v21 = v10;
  v11 = m_objective.z;
  m_objective.z = v6;
  v22 = v11 - v3->m_right_side.y;
  v12 = m_objective.w;
  m_objective.w = v8;
  v23 = v12 - v3->m_right_side.z;
  v14 = v23 * v3->m_cr12.x;
  v15 = v3->m_cr12.y * v23;
  v16 = v23 * v3->m_cr12.z;
  error_.y = v3->m_cr31.x * v22;
  error_.z = v3->m_cr31.y * v22;
  error_.w = v22 * v3->m_cr31.z;
  v13 = v21;
  v21 = v21 * v3->m_cr23.x;
  v22 = v3->m_cr23.y * v13;
  v23 = v13 * v3->m_cr23.z;
  v17 = v21 + error_.y;
  v18 = v22 + error_.z;
  v19 = v23 + error_.w;
  error_.y = v17 + v14;
  error_.z = v18 + v15;
  error_.w = v19 + v16;
  v3->m_pulse_sum.x = v3->m_pulse_sum.x - error_.y;
  v3->m_pulse_sum.y = v3->m_pulse_sum.y - error_.z;
  v3->m_pulse_sum.z = v3->m_pulse_sum.z - error_.w;
  v21 = v3->m_pulse_sum.x - m_objective.y;
  v22 = v3->m_pulse_sum.y - m_objective.z;
  v23 = v3->m_pulse_sum.z - m_objective.w;
  pulse_sum_point::apply(v3, (phys_vec3 *)&v21);
  v14 = v3->m_denom.x * v21;
  v15 = v3->m_denom.y * v22;
  v16 = v3->m_denom.z * v23;
  v17 = v14 * v14;
  v18 = v15 * v15;
  v19 = v16 * v16;
  if ( *error_sq < (double)v17 )
    *error_sq = v17;
  if ( *error_sq < (double)v18 )
    *error_sq = v18;
  if ( *error_sq < (double)v19 )
    *error_sq = v19;
}

/*
==============
pulse_sum_point::calc_abs_and_setup
==============
*/
void __userpurge pulse_sum_point::calc_abs_and_setup(pulse_sum_point *this@<ecx>, int a2@<ebp>, const float delta_t, const bool is_spring, const float spring_k, const float damp_k)
{
  pulse_sum_point *v6; // esi
  pulse_sum_node *v7; // eax
  phys_mat44 *v8; // edi
  phys_vec3 *v9; // eax
  phys_vec3 *v10; // eax
  phys_vec3 *v11; // eax
  pulse_sum_node *v12; // eax
  phys_mat44 *v13; // edi
  phys_vec3 *v14; // eax
  phys_vec3 *v15; // eax
  phys_vec3 *v16; // eax
  double v17; // st6
  double v18; // st5
  double v19; // st7
  phys_vec3 *v20; // eax
  double v21; // st7
  double v22; // st5
  double v23; // st4
  double v24; // rtt
  double v25; // st3
  double v26; // st7
  float v27; // [esp-Ch] [ebp-6Ch]
  float v28; // [esp-8h] [ebp-68h]
  float v29; // [esp-4h] [ebp-64h]
  phys_vec3 pos; // [esp+0h] [ebp-60h]
  float v31; // [esp+14h] [ebp-4Ch]
  float v32; // [esp+18h] [ebp-48h]
  float v33; // [esp+1Ch] [ebp-44h]
  phys_vec3 zz; // [esp+20h] [ebp-40h]
  phys_vec3 zy; // [esp+30h] [ebp-30h]
  phys_vec3 zx; // [esp+40h] [ebp-20h]
  float v37; // [esp+50h] [ebp-10h]
  int v38; // [esp+54h] [ebp-Ch]
  const float oo_det; // [esp+58h] [ebp-8h]
  float retaddr; // [esp+60h] [ebp+0h]

  v38 = a2;
  oo_det = retaddr;
  v6 = this;
  v7 = this->m_b1;
  v37 = v7->m_inv_mass;
  v8 = &v7->m_world_inv_inertia;
  pos.y = 0.0;
  pos.z = this->m_b1_r.z;
  pos.w = -this->m_b1_r.y;
  v9 = phys_multiply((phys_vec3 *)&v27, &v7->m_world_inv_inertia, (phys_vec3 *)((char *)&pos + 4));
  v6->m_b1_apx.x = v9->x;
  v6->m_b1_apx.y = v9->y;
  v6->m_b1_apx.z = v9->z;
  zy.y = v6->m_b1_apx.y * v6->m_b1_r.z - v6->m_b1_apx.z * v6->m_b1_r.y;
  zy.z = v6->m_b1_r.x * v6->m_b1_apx.z - v6->m_b1_apx.x * v6->m_b1_r.z;
  zy.w = v6->m_b1_apx.x * v6->m_b1_r.y - v6->m_b1_r.x * v6->m_b1_apx.y;
  zy.y = zy.y + v37;
  pos.y = -v6->m_b1_r.z;
  pos.z = 0.0;
  pos.w = v6->m_b1_r.x;
  v10 = phys_multiply((phys_vec3 *)&v27, v8, (phys_vec3 *)((char *)&pos + 4));
  v6->m_b1_apy.x = v10->x;
  v6->m_b1_apy.y = v10->y;
  v6->m_b1_apy.z = v10->z;
  zz.y = v6->m_b1_r.z * v6->m_b1_apy.y - v6->m_b1_r.y * v6->m_b1_apy.z;
  zz.z = v6->m_b1_r.x * v6->m_b1_apy.z - v6->m_b1_r.z * v6->m_b1_apy.x;
  zz.w = v6->m_b1_r.y * v6->m_b1_apy.x - v6->m_b1_r.x * v6->m_b1_apy.y;
  zz.z = zz.z + v37;
  pos.y = v6->m_b1_r.y;
  pos.z = -v6->m_b1_r.x;
  pos.w = 0.0;
  v11 = phys_multiply((phys_vec3 *)&v27, v8, (phys_vec3 *)((char *)&pos + 4));
  v6->m_b1_apz.x = v11->x;
  v6->m_b1_apz.y = v11->y;
  v6->m_b1_apz.z = v11->z;
  v12 = v6->m_b2;
  v31 = v6->m_b1_apz.y * v6->m_b1_r.z - v6->m_b1_apz.z * v6->m_b1_r.y;
  v32 = v6->m_b1_r.x * v6->m_b1_apz.z - v6->m_b1_apz.x * v6->m_b1_r.z;
  zx.w = v6->m_b1_apz.x * v6->m_b1_r.y - v6->m_b1_r.x * v6->m_b1_apz.y;
  v33 = zx.w + v37;
  if ( v12 )
  {
    v13 = &v12->m_world_inv_inertia;
    v37 = v12->m_inv_mass;
    pos.y = 0.0;
    pos.z = v6->m_b2_r.z;
    pos.w = -v6->m_b2_r.y;
    v14 = phys_multiply((phys_vec3 *)&v27, &v12->m_world_inv_inertia, (phys_vec3 *)((char *)&pos + 4));
    v6->m_b2_apx.x = v14->x;
    v6->m_b2_apx.y = v14->y;
    v6->m_b2_apx.z = v14->z;
    pos.y = v6->m_b2_apx.y * v6->m_b2_r.z - v6->m_b2_apx.z * v6->m_b2_r.y;
    pos.z = v6->m_b2_apx.z * v6->m_b2_r.x - v6->m_b2_r.z * v6->m_b2_apx.x;
    pos.w = v6->m_b2_r.y * v6->m_b2_apx.x - v6->m_b2_apx.y * v6->m_b2_r.x;
    zy.y = pos.y + zy.y;
    zy.z = pos.z + zy.z;
    zy.w = pos.w + zy.w;
    zy.y = v37 + zy.y;
    pos.y = -v6->m_b2_r.z;
    pos.z = 0.0;
    pos.w = v6->m_b2_r.x;
    v15 = phys_multiply((phys_vec3 *)&v27, v13, (phys_vec3 *)((char *)&pos + 4));
    v6->m_b2_apy.x = v15->x;
    v6->m_b2_apy.y = v15->y;
    v6->m_b2_apy.z = v15->z;
    pos.y = v6->m_b2_r.z * v6->m_b2_apy.y - v6->m_b2_r.y * v6->m_b2_apy.z;
    pos.z = v6->m_b2_apy.z * v6->m_b2_r.x - v6->m_b2_r.z * v6->m_b2_apy.x;
    pos.w = v6->m_b2_r.y * v6->m_b2_apy.x - v6->m_b2_apy.y * v6->m_b2_r.x;
    zz.y = pos.y + zz.y;
    zz.z = pos.z + zz.z;
    zz.w = pos.w + zz.w;
    zz.z = zz.z + v37;
    pos.y = v6->m_b2_r.y;
    pos.z = -v6->m_b2_r.x;
    pos.w = 0.0;
    v16 = phys_multiply((phys_vec3 *)&v27, v13, (phys_vec3 *)((char *)&pos + 4));
    v6->m_b2_apz.x = v16->x;
    v6->m_b2_apz.y = v16->y;
    v6->m_b2_apz.z = v16->z;
    pos.y = v6->m_b2_apz.y * v6->m_b2_r.z - v6->m_b2_apz.z * v6->m_b2_r.y;
    pos.z = v6->m_b2_apz.z * v6->m_b2_r.x - v6->m_b2_r.z * v6->m_b2_apz.x;
    pos.w = v6->m_b2_r.y * v6->m_b2_apz.x - v6->m_b2_apz.y * v6->m_b2_r.x;
    v31 = pos.y + v31;
    v32 = pos.z + v32;
    zx.w = pos.w + v33;
    v33 = zx.w + v37;
  }
  if ( is_spring )
  {
    pulse_sum_point::get_pos(v6, (int)&v38, (phys_vec3 *)&v27);
    zx.w = delta_t * spring_k;
    v17 = zx.w * delta_t;
    zx.w = delta_t * damp_k;
    zx.w = 1.0 / (zx.w + v17);
    v18 = zx.w;
    v6->m_cfm = zx.w;
    zy.y = v6->m_cfm + zy.y;
    zz.z = zz.z + v6->m_cfm;
    v33 = v33 + v6->m_cfm;
    zx.w = v17 * v18;
    zx.w = -zx.w / delta_t;
    pos.y = v27 * zx.w;
    pos.z = v28 * zx.w;
    pos.w = zx.w * v29;
    v6->m_right_side.x = pos.y;
    v6->m_right_side.y = pos.z;
    v6->m_right_side.z = pos.w;
    v6->m_big_dirt.x = PHYS_ZERO_VEC_97.x;
    v6->m_big_dirt.y = PHYS_ZERO_VEC_97.y;
    v6->m_big_dirt.z = PHYS_ZERO_VEC_97.z;
  }
  else
  {
    v19 = 0.016666668;
    if ( delta_t > 0.016666668 )
      v19 = delta_t;
    v37 = v19;
    v20 = pulse_sum_point::get_pos(v6, (int)&v38, (phys_vec3 *)&v27);
    zx.w = -0.5 / v37;
    pos.y = zx.w * v20->x;
    pos.z = v20->y * zx.w;
    pos.w = zx.w * v20->z;
    v6->m_big_dirt.x = pos.y;
    v6->m_big_dirt.y = pos.z;
    v6->m_big_dirt.z = pos.w;
    v6->m_right_side.x = PHYS_ZERO_VEC_97.x;
    v6->m_right_side.y = PHYS_ZERO_VEC_97.y;
    v6->m_right_side.z = PHYS_ZERO_VEC_97.z;
    v6->m_cfm = 0.0;
  }
  v21 = v33;
  v22 = zz.z;
  v23 = v32;
  pos.y = v33 * zz.z - v32 * zz.w;
  pos.z = zz.w * v31 - v33 * zz.y;
  v24 = v31;
  pos.w = zz.y * v32 - zz.z * v31;
  v6->m_cr23.x = pos.y;
  v6->m_cr23.y = pos.z;
  v6->m_cr23.z = pos.w;
  pos.y = v23 * zy.w - v21 * zy.z;
  v25 = zy.y;
  pos.z = v21 * zy.y - zy.w * v24;
  pos.w = zy.z * v24 - v23 * zy.y;
  v6->m_cr31.x = pos.y;
  v6->m_cr31.y = pos.z;
  v6->m_cr31.z = pos.w;
  pos.y = zz.w * zy.z - v22 * zy.w;
  pos.z = zy.w * zz.y - zz.w * v25;
  pos.w = v22 * v25 - zy.z * zz.y;
  v6->m_cr12.x = pos.y;
  v6->m_cr12.y = pos.z;
  v6->m_cr12.z = pos.w;
  v6->m_denom.x = v25;
  v6->m_denom.y = v22;
  v6->m_denom.z = v21;
  zx.w = v23 * v6->m_cr12.y + v24 * v6->m_cr12.x + v21 * v6->m_cr12.z;
  zx.w = 1.0 / zx.w;
  v26 = zx.w;
  v6->m_cr23.x = v6->m_cr23.x * zx.w;
  v6->m_cr23.y = v26 * v6->m_cr23.y;
  v6->m_cr23.z = v26 * v6->m_cr23.z;
  v6->m_cr31.x = v26 * v6->m_cr31.x;
  v6->m_cr31.y = v26 * v6->m_cr31.y;
  v6->m_cr31.z = v26 * v6->m_cr31.z;
  v6->m_cr12.x = v6->m_cr12.x * v26;
  v6->m_cr12.y = v26 * v6->m_cr12.y;
  v6->m_cr12.z = v26 * v6->m_cr12.z;
}

