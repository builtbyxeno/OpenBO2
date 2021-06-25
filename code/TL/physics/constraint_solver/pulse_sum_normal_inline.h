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
pulse_sum_normal::calc_abs
==============
*/
void __userpurge pulse_sum_normal::calc_abs(pulse_sum_normal *this@<ecx>, int a2@<ebp>, phys_vec3 *b1_r_displace)
{
  pulse_sum_normal *v3; // esi
  double v4; // st7
  phys_mat44 *v5; // ecx
  phys_vec3 *v6; // eax
  pulse_sum_node *v7; // eax
  double v8; // st7
  pulse_sum_node *v9; // eax
  phys_vec3 *v10; // eax
  pulse_sum_node *v11; // eax
  float v12; // [esp-1Ch] [ebp-3Ch]
  float v13; // [esp-18h] [ebp-38h]
  float v14; // [esp-14h] [ebp-34h]
  float v15; // [esp-Ch] [ebp-2Ch]
  float v16; // [esp-8h] [ebp-28h]
  float v17; // [esp-4h] [ebp-24h]
  float v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch]
  int v20; // [esp+18h] [ebp-8h]
  int retaddr; // [esp+20h] [ebp+0h]

  v19 = a2;
  v20 = retaddr;
  v3 = this;
  v4 = b1_r_displace->x + this->m_b1_r.x;
  v5 = &this->m_b1->m_world_inv_inertia;
  v15 = v4;
  v16 = b1_r_displace->y + v3->m_b1_r.y;
  v17 = b1_r_displace->z + v3->m_b1_r.z;
  v12 = v16 * v3->m_ud.z - v3->m_ud.y * v17;
  v13 = v17 * v3->m_ud.x - v15 * v3->m_ud.z;
  v14 = v15 * v3->m_ud.y - v16 * v3->m_ud.x;
  v6 = phys_multiply((phys_vec3 *)&v15, v5, (phys_vec3 *)&v12);
  v3->m_b1_ap.x = v6->x;
  v3->m_b1_ap.y = v6->y;
  v3->m_b1_ap.z = v6->z;
  v7 = v3->m_b1;
  v15 = v3->m_b1_ap.y * v3->m_b1_r.z - v3->m_b1_ap.z * v3->m_b1_r.y;
  v16 = v3->m_b1_ap.z * v3->m_b1_r.x - v3->m_b1_r.z * v3->m_b1_ap.x;
  v17 = v3->m_b1_r.y * v3->m_b1_ap.x - v3->m_b1_ap.y * v3->m_b1_r.x;
  v18 = v3->m_ud.x * v15 + v3->m_ud.y * v16 + v17 * v3->m_ud.z;
  v8 = v18 + v7->m_inv_mass;
  v9 = v3->m_b2;
  v3->m_denom = v8;
  if ( v9 )
  {
    v15 = v3->m_b2_r.y * v3->m_ud.z - v3->m_b2_r.z * v3->m_ud.y;
    v16 = v3->m_b2_r.z * v3->m_ud.x - v3->m_b2_r.x * v3->m_ud.z;
    v17 = v3->m_ud.y * v3->m_b2_r.x - v3->m_b2_r.y * v3->m_ud.x;
    v10 = phys_multiply((phys_vec3 *)&v12, &v9->m_world_inv_inertia, (phys_vec3 *)&v15);
    v3->m_b2_ap.x = v10->x;
    v3->m_b2_ap.y = v10->y;
    v3->m_b2_ap.z = v10->z;
    v11 = v3->m_b2;
    v18 = v3->m_b2_ap.x * v15 + v16 * v3->m_b2_ap.y + v17 * v3->m_b2_ap.z;
    v3->m_denom = v18 + v11->m_inv_mass + v3->m_denom;
  }
}

/*
==============
pulse_sum_normal::get_vel
==============
*/
double __usercall pulse_sum_normal::get_vel@<st0>(pulse_sum_normal *this@<ecx>, int a2@<ebp>)
{
  rigid_body *v2; // eax
  float *v3; // edx
  rigid_body *v4; // eax
  float v6; // [esp-40h] [ebp-4Ch]
  float v7; // [esp-3Ch] [ebp-48h]
  float v8; // [esp-38h] [ebp-44h]
  float v9; // [esp-30h] [ebp-3Ch]
  float v10; // [esp-2Ch] [ebp-38h]
  float v11; // [esp-28h] [ebp-34h]
  float v12; // [esp-20h] [ebp-2Ch]
  float v13; // [esp-1Ch] [ebp-28h]
  float v14; // [esp-18h] [ebp-24h]
  int v16; // [esp+0h] [ebp-Ch]
  int v17; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v16 = a2;
  v17 = retaddr;
  if ( this->m_b2 )
  {
    v2 = this->m_b2->m_rb;
    v3 = &v6;
    v12 = this->m_b2_r.z * v2->m_a_vel.y - this->m_b2_r.y * v2->m_a_vel.z;
    v13 = this->m_b2_r.x * v2->m_a_vel.z - this->m_b2_r.z * v2->m_a_vel.x;
    v14 = this->m_b2_r.y * v2->m_a_vel.x - v2->m_a_vel.y * this->m_b2_r.x;
    v6 = v2->m_t_vel.x + v12;
    v7 = v2->m_t_vel.y + v13;
    v8 = v2->m_t_vel.z + v14;
  }
  else
  {
    v3 = &this->m_b2_ap.x;
  }
  v4 = this->m_b1->m_rb;
  v12 = this->m_b1_r.z * v4->m_a_vel.y - this->m_b1_r.y * v4->m_a_vel.z;
  v13 = this->m_b1_r.x * v4->m_a_vel.z - this->m_b1_r.z * v4->m_a_vel.x;
  v14 = v4->m_a_vel.x * this->m_b1_r.y - v4->m_a_vel.y * this->m_b1_r.x;
  v9 = v4->m_t_vel.x + v12;
  v10 = v4->m_t_vel.y + v13;
  v11 = v4->m_t_vel.z + v14;
  v12 = v9 - *v3;
  v13 = v10 - v3[1];
  v14 = v11 - v3[2];
  return (float)(this->m_ud.y * v13 + this->m_ud.x * v12 + this->m_ud.z * v14);
}

/*
==============
pulse_sum_normal::get_last_vel
==============
*/
double __usercall pulse_sum_normal::get_last_vel@<st0>(pulse_sum_normal *this@<ecx>, int a2@<ebp>)
{
  rigid_body *v2; // eax
  float *v3; // edx
  rigid_body *v4; // eax
  float v6; // [esp-40h] [ebp-4Ch]
  float v7; // [esp-3Ch] [ebp-48h]
  float v8; // [esp-38h] [ebp-44h]
  float v9; // [esp-30h] [ebp-3Ch]
  float v10; // [esp-2Ch] [ebp-38h]
  float v11; // [esp-28h] [ebp-34h]
  float v12; // [esp-20h] [ebp-2Ch]
  float v13; // [esp-1Ch] [ebp-28h]
  float v14; // [esp-18h] [ebp-24h]
  int v16; // [esp+0h] [ebp-Ch]
  int v17; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v16 = a2;
  v17 = retaddr;
  if ( this->m_b2 )
  {
    v2 = this->m_b2->m_rb;
    v3 = &v6;
    v12 = this->m_b2_r.z * v2->m_last_a_vel.y - this->m_b2_r.y * v2->m_last_a_vel.z;
    v13 = this->m_b2_r.x * v2->m_last_a_vel.z - this->m_b2_r.z * v2->m_last_a_vel.x;
    v14 = this->m_b2_r.y * v2->m_last_a_vel.x - v2->m_last_a_vel.y * this->m_b2_r.x;
    v6 = v2->m_last_t_vel.x + v12;
    v7 = v2->m_last_t_vel.y + v13;
    v8 = v2->m_last_t_vel.z + v14;
  }
  else
  {
    v3 = &this->m_b2_ap.x;
  }
  v4 = this->m_b1->m_rb;
  v12 = this->m_b1_r.z * v4->m_last_a_vel.y - this->m_b1_r.y * v4->m_last_a_vel.z;
  v13 = this->m_b1_r.x * v4->m_last_a_vel.z - this->m_b1_r.z * v4->m_last_a_vel.x;
  v14 = v4->m_last_a_vel.x * this->m_b1_r.y - v4->m_last_a_vel.y * this->m_b1_r.x;
  v9 = v4->m_last_t_vel.x + v12;
  v10 = v4->m_last_t_vel.y + v13;
  v11 = v4->m_last_t_vel.z + v14;
  v12 = v9 - *v3;
  v13 = v10 - v3[1];
  v14 = v11 - v3[2];
  return (float)(this->m_ud.y * v13 + this->m_ud.x * v12 + this->m_ud.z * v14);
}

/*
==============
pulse_sum_normal::get_pos
==============
*/
double __usercall pulse_sum_normal::get_pos@<st0>(pulse_sum_normal *this@<ecx>, int a2@<ebp>)
{
  pulse_sum_node *v2; // eax
  float *v3; // eax
  float *v4; // edx
  rigid_body *v5; // eax
  float v7; // [esp-40h] [ebp-4Ch]
  float v8; // [esp-3Ch] [ebp-48h]
  float v9; // [esp-38h] [ebp-44h]
  float v10; // [esp-30h] [ebp-3Ch]
  float v11; // [esp-2Ch] [ebp-38h]
  float v12; // [esp-28h] [ebp-34h]
  float v13; // [esp-20h] [ebp-2Ch]
  float v14; // [esp-1Ch] [ebp-28h]
  float v15; // [esp-18h] [ebp-24h]
  int v17; // [esp+0h] [ebp-Ch]
  int v18; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v17 = a2;
  v18 = retaddr;
  v2 = this->m_b2;
  if ( v2 )
  {
    v3 = &v2->m_rb->m_last_position.x;
    v4 = &v7;
    v7 = this->m_b2_r.x + v3[24];
    v8 = this->m_b2_r.y + v3[25];
    v9 = this->m_b2_r.z + v3[26];
  }
  else
  {
    v4 = &this->m_b2_r.x;
  }
  v5 = this->m_b1->m_rb;
  v13 = v5->m_mat.w.x + this->m_b1_r.x;
  v14 = v5->m_mat.w.y + this->m_b1_r.y;
  v15 = v5->m_mat.w.z + this->m_b1_r.z;
  v10 = v13 - *v4;
  v11 = v14 - v4[1];
  v12 = v15 - v4[2];
  return (float)(this->m_ud.y * v11 + v10 * this->m_ud.x + this->m_ud.z * v12);
}

/*
==============
pulse_sum_normal::set
==============
*/
void __userpurge pulse_sum_normal::set(pulse_sum_normal *this@<ecx>, int a2@<ebp>, rigid_body *const b1, phys_vec3 *b1_r, rigid_body *const b2, phys_vec3 *b2_r, phys_vec3 *ud, pulse_sum_cache *const ps_cache, phys_vec3 *b1_r_displace)
{
  pulse_sum_normal *v9; // esi
  rigid_body *v10; // ecx
  int v11; // eax
  unsigned int v12; // eax
  pulse_sum_node *v13; // eax
  pulse_sum_node *v14; // eax
  double v15; // st7
  phys_vec3 *v16; // eax
  bool v17; // zf
  double v18; // st7
  phys_vec3 *v19; // eax
  float v20; // [esp-10h] [ebp-1Ch]
  float v21; // [esp-Ch] [ebp-18h]
  float v22; // [esp-8h] [ebp-14h]
  int v23; // [esp+0h] [ebp-Ch]
  int v24; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v23 = a2;
  v24 = retaddr;
  v9 = this;
  if ( !ps_cache
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_normal_inline.h",
         118,
         "ps_cache",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !b1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_normal_inline.h",
         119,
         "b1",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !b2
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_normal_inline.h",
         120,
         "b2",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( b1 == b2
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_normal_inline.h",
         121,
         "b1 != b2",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  PHYS_ASSERT_UNIT(ud);
  v10 = b1;
  if ( b1->m_node )
    goto LABEL_44;
  if ( !b2->m_node )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_normal_inline.h",
           123,
           "rbint::get_pulse_sum_node(b1) || rbint::get_pulse_sum_node(b2)",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v10 = b1;
  }
  if ( v10->m_node )
LABEL_44:
    v11 = (v10->m_flags & 0x30) == 0;
  else
    v11 = v10->m_flags & 0x30;
  if ( !v11 || (!b2->m_node ? (v12 = b2->m_flags & 0x30) : (v12 = (b2->m_flags & 0x30) == 0), !v12) )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_normal_inline.h",
           124,
           "rbint::verify_pulse_sum_node(b1) && rbint::verify_pulse_sum_node(b2)",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v10 = b1;
  }
  v13 = v10->m_node;
  if ( v13 )
  {
    v9->m_b1 = v13;
    v9->m_b1_r.x = b1_r->x;
    v9->m_b1_r.y = b1_r->y;
    v9->m_b1_r.z = b1_r->z;
    v14 = b2->m_node;
    if ( v14 )
    {
      v9->m_b2 = v14;
      v9->m_b2_r.x = b2_r->x;
      v9->m_b2_r.y = b2_r->y;
      v15 = b2_r->z;
    }
    else
    {
      v9->m_b2 = NULL;
      v16 = rbint::gtv((phys_vec3 *)&v20, b2, b2_r);
      v9->m_b2_ap.x = v16->x;
      v9->m_b2_ap.y = v16->y;
      v9->m_b2_ap.z = v16->z;
      v17 = v9->m_b2 == NULL;
      v20 = b2->m_mat.w.x + b2_r->x;
      v21 = b2->m_mat.w.y + b2_r->y;
      v22 = b2->m_mat.w.z + b2_r->z;
      if ( !v17
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_normal.h",
             72,
             "m_b2 == NULL",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v9->m_b2_r.x = v20;
      v9->m_b2_r.y = v21;
      v15 = v22;
    }
    v9->m_b2_r.z = v15;
    v9->m_ud.x = ud->x;
    v9->m_ud.y = ud->y;
    v18 = ud->z;
  }
  else
  {
    v9->m_b1 = b2->m_node;
    v9->m_b1_r.x = b2_r->x;
    v9->m_b1_r.y = b2_r->y;
    v9->m_b1_r.z = b2_r->z;
    v9->m_b2 = NULL;
    v19 = rbint::gtv((phys_vec3 *)&v20, v10, b1_r);
    v9->m_b2_ap.x = v19->x;
    v9->m_b2_ap.y = v19->y;
    v9->m_b2_ap.z = v19->z;
    v17 = v9->m_b2 == NULL;
    v20 = b1_r->x + b1->m_mat.w.x;
    v21 = b1->m_mat.w.y + b1_r->y;
    v22 = b1->m_mat.w.z + b1_r->z;
    if ( !v17
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_normal.h",
           72,
           "m_b2 == NULL",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v9->m_b2_r.x = v20;
    v9->m_b2_r.y = v21;
    v9->m_b2_r.z = v22;
    v20 = -ud->x;
    v21 = -ud->y;
    v22 = -ud->z;
    v9->m_ud.x = v20;
    v9->m_ud.y = v21;
    v18 = v22;
  }
  v9->m_ud.z = v18;
  v9->m_pulse_sum_cache = ps_cache;
  v9->m_flags = 0;
  pulse_sum_normal::calc_abs(v9, (int)&v23, b1_r_displace);
}

/*
==============
pulse_sum_normal::get_relative_velocity_change_dir
==============
*/
phys_vec3 *__thiscall pulse_sum_normal::get_relative_velocity_change_dir(pulse_sum_normal *this, phys_vec3 *result)
{
  pulse_sum_node *v2; // edx
  float v3; // ST10_4
  float v4; // ST14_4
  float v5; // ST18_4
  phys_vec3 *v6; // eax
  float v7; // ST3C_4
  float v8; // ST20_4
  float v9; // ST24_4
  float v10; // ST28_4
  float v11; // ST3C_4
  double v12; // st7
  float v13; // ST3C_4
  double v14; // st6
  float v15; // ST3C_4
  double v16; // st5
  float v17; // ST20_4
  float v18; // ST24_4
  float v19; // ST28_4
  float v20; // ST3C_4
  float v21; // ST10_4
  float v22; // ST14_4
  float v23; // ST18_4
  float v24; // ST00_4
  float v25; // ST04_4
  float v26; // ST08_4

  v2 = this->m_b2;
  v3 = this->m_b1_ap.y * this->m_b1_r.z - this->m_b1_ap.z * this->m_b1_r.y;
  v4 = this->m_b1_ap.z * this->m_b1_r.x - this->m_b1_r.z * this->m_b1_ap.x;
  v5 = this->m_b1_r.y * this->m_b1_ap.x - this->m_b1_ap.y * this->m_b1_r.x;
  v6 = result;
  v7 = this->m_b1->m_inv_mass;
  v8 = v7 * this->m_ud.x;
  v9 = v7 * this->m_ud.y;
  v10 = v7 * this->m_ud.z;
  v11 = v8 + v3;
  v12 = v11;
  result->x = v11;
  v13 = v9 + v4;
  v14 = v13;
  result->y = v13;
  v15 = v10 + v5;
  v16 = v15;
  result->z = v15;
  if ( v2 )
  {
    v17 = this->m_b2_ap.y * this->m_b2_r.z - this->m_b2_ap.z * this->m_b2_r.y;
    v18 = this->m_b2_ap.z * this->m_b2_r.x - this->m_b2_ap.x * this->m_b2_r.z;
    v19 = this->m_b2_r.y * this->m_b2_ap.x - this->m_b2_r.x * this->m_b2_ap.y;
    v20 = v2->m_inv_mass;
    v21 = v20 * this->m_ud.x;
    v22 = v20 * this->m_ud.y;
    v23 = v20 * this->m_ud.z;
    v24 = v21 + v17;
    v25 = v22 + v18;
    v26 = v23 + v19;
    result->x = v12 + v24;
    result->y = v14 + v25;
    result->z = v16 + v26;
  }
  return v6;
}

/*
==============
pulse_sum_normal::get_relative_velocity
==============
*/
phys_vec3 *__userpurge pulse_sum_normal::get_relative_velocity@<eax>(pulse_sum_normal *this@<ecx>, int a2@<ebp>, phys_vec3 *result)
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
    v4 = &this->m_b2_ap.x;
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
pulse_sum_normal::get_unclamped_pulse_sum
==============
*/
double __thiscall pulse_sum_normal::get_unclamped_pulse_sum(pulse_sum_normal *this)
{
  pulse_sum_normal *v1; // esi
  double ps; // ST08_8

  v1 = this;
  ps = this->m_right_side;
  *((float *)&ps + 1) = (ps - pulse_sum_normal::get_objective(this) - v1->m_cfm * v1->m_pulse_sum) / v1->m_denom;
  *((float *)&ps + 1) = v1->m_pulse_sum + *((float *)&ps + 1);
  return pulse_sum_normal::clamp_pulse_sum(v1, *((const float *)&ps + 1));
}

/*
==============
pulse_sum_normal::get_objective
==============
*/
double __thiscall pulse_sum_normal::get_objective(pulse_sum_normal *this)
{
  pulse_sum_node *v1; // eax
  float v2; // ST10_4
  float v3; // ST14_4
  float v4; // ST18_4
  pulse_sum_node *v5; // eax
  float v6; // ST10_4
  float v7; // ST14_4
  float v8; // ST18_4
  float v9; // ST00_4
  float v10; // ST04_4
  float v11; // ST08_4
  float v14; // [esp-Ch] [ebp-2Ch]
  float v15; // [esp-8h] [ebp-28h]
  float v16; // [esp-4h] [ebp-24h]

  v1 = this->m_b1;
  v2 = v1->a_vel.y * this->m_b1_r.z - v1->a_vel.z * this->m_b1_r.y;
  v3 = this->m_b1_r.x * v1->a_vel.z - v1->a_vel.x * this->m_b1_r.z;
  v4 = v1->a_vel.x * this->m_b1_r.y - this->m_b1_r.x * v1->a_vel.y;
  v14 = v1->t_vel.x + v2;
  v15 = v1->t_vel.y + v3;
  v16 = v1->t_vel.z + v4;
  if ( this->m_b2 )
  {
    v5 = this->m_b2;
    v6 = v5->a_vel.y * this->m_b2_r.z - v5->a_vel.z * this->m_b2_r.y;
    v7 = v5->a_vel.z * this->m_b2_r.x - v5->a_vel.x * this->m_b2_r.z;
    v8 = v5->a_vel.x * this->m_b2_r.y - v5->a_vel.y * this->m_b2_r.x;
    v9 = v5->t_vel.x + v6;
    v10 = v5->t_vel.y + v7;
    v11 = v5->t_vel.z + v8;
    v14 = v14 - v9;
    v15 = v15 - v10;
    v16 = v16 - v11;
  }
  return (float)(this->m_ud.y * v15 + this->m_ud.x * v14 + this->m_ud.z * v16);
}

/*
==============
pulse_sum_normal::apply
==============
*/
void __thiscall pulse_sum_normal::apply(pulse_sum_normal *this, const float *s_)
{
  pulse_sum_node *v2; // eax
  float v3; // ST1C_4
  float v4; // ST00_4
  float v5; // ST04_4
  float v6; // ST08_4
  pulse_sum_node *v7; // eax
  float v8; // ST00_4
  float v9; // ST04_4
  float v10; // ST08_4
  pulse_sum_node *v11; // eax
  float v12; // ST1C_4
  float v13; // ST00_4
  float v14; // ST04_4
  float v15; // ST08_4
  float v16; // ST00_4
  float v17; // ST04_4
  double v18; // st7
  pulse_sum_node *v19; // ecx
  float v20; // ST08_4

  v2 = this->m_b1;
  v3 = v2->m_inv_mass * *s_;
  v4 = v3 * this->m_ud.x;
  v5 = this->m_ud.y * v3;
  v6 = v3 * this->m_ud.z;
  v2->t_vel.x = v2->t_vel.x + v4;
  v2->t_vel.y = v2->t_vel.y + v5;
  v2->t_vel.z = v2->t_vel.z + v6;
  v7 = this->m_b1;
  v8 = this->m_b1_ap.x * *s_;
  v9 = this->m_b1_ap.y * *s_;
  v10 = *s_ * this->m_b1_ap.z;
  v7->a_vel.x = v8 + v7->a_vel.x;
  v7->a_vel.y = v7->a_vel.y + v9;
  v7->a_vel.z = v7->a_vel.z + v10;
  if ( this->m_b2 )
  {
    v11 = this->m_b2;
    v12 = v11->m_inv_mass * *s_;
    v13 = v12 * this->m_ud.x;
    v14 = this->m_ud.y * v12;
    v15 = v12 * this->m_ud.z;
    v11->t_vel.x = v11->t_vel.x - v13;
    v11->t_vel.y = v11->t_vel.y - v14;
    v11->t_vel.z = v11->t_vel.z - v15;
    v16 = *s_ * this->m_b2_ap.x;
    v17 = this->m_b2_ap.y * *s_;
    v18 = *s_ * this->m_b2_ap.z;
    v19 = this->m_b2;
    v20 = v18;
    v19->a_vel.x = v19->a_vel.x - v16;
    v19->a_vel.y = v19->a_vel.y - v17;
    v19->a_vel.z = v19->a_vel.z - v20;
  }
}

/*
==============
pulse_sum_normal::clamp_pulse_sum
==============
*/
double __thiscall pulse_sum_normal::clamp_pulse_sum(pulse_sum_normal *this, const float ps)
{
  pulse_sum_normal *v2; // esi
  float v3; // ST14_4
  float v4; // ST14_4
  double result; // st7

  v2 = this;
  if ( this->m_flags & 1 )
  {
    if ( !this->m_pulse_parent
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_normal_inline.h",
           57,
           "m_pulse_parent",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v2->m_pulse_limit_ratio < 0.0
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_normal_inline.h",
           58,
           "m_pulse_limit_ratio >= 0.0f",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v3 = fabs(v2->m_pulse_parent->m_pulse_sum);
    v4 = v3 * v2->m_pulse_limit_ratio;
    v2->m_pulse_sum_max = v4;
    v2->m_pulse_sum_min = -v4;
  }
  if ( v2->m_pulse_sum_max < (double)v2->m_pulse_sum_min
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_normal_inline.h",
         62,
         "m_pulse_sum_min <= m_pulse_sum_max",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  result = ps;
  if ( v2->m_pulse_sum_min <= (double)ps )
  {
    if ( v2->m_pulse_sum_max >= result )
    {
      v2->m_flags &= 0xFFFFFFFD;
    }
    else
    {
      v2->m_flags |= 2u;
      result = v2->m_pulse_sum_max;
    }
  }
  else
  {
    v2->m_flags |= 2u;
    result = v2->m_pulse_sum_min;
  }
  return result;
}

/*
==============
pulse_sum_normal::SOLVER_apply_relaxation
==============
*/
void __thiscall pulse_sum_normal::SOLVER_apply_relaxation(pulse_sum_normal *this, float *error_sq, const bool add_error)
{
  pulse_sum_normal *v3; // esi
  double v4; // st7
  const float m_objective; // [esp+8h] [ebp-8h]
  const float m_last_pulse_sum; // [esp+Ch] [ebp-4h]
  float error_sq___a; // [esp+1Ch] [ebp+Ch]
  float error_sq___; // [esp+1Ch] [ebp+Ch]

  v3 = this;
  m_objective = pulse_sum_normal::get_objective(this) + v3->m_cfm * v3->m_pulse_sum - v3->m_right_side;
  m_last_pulse_sum = v3->m_pulse_sum;
  m_objective = m_last_pulse_sum - m_objective / v3->m_denom;
  m_objective = pulse_sum_normal::clamp_pulse_sum(v3, m_objective);
  v4 = m_objective;
  v3->m_pulse_sum = m_objective;
  if ( (v3->m_pulse_sum_min - 0.00009999999747378752 > v4 || v3->m_pulse_sum_max + 0.00009999999747378752 < v4)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_normal_inline.h",
         91,
         "m_pulse_sum >= (m_pulse_sum_min - .0001f) && m_pulse_sum <= (m_pulse_sum_max + .0001f)",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  m_objective = v3->m_pulse_sum - m_last_pulse_sum;
  pulse_sum_normal::apply(v3, &m_objective);
  if ( add_error )
  {
    error_sq___a = (v3->m_pulse_sum - m_last_pulse_sum) * v3->m_denom;
    error_sq___ = error_sq___a * error_sq___a;
    if ( *error_sq < (double)error_sq___ )
      *error_sq = error_sq___;
  }
}

/*
==============
pulse_sum_normal::SOLVER_solver_prolog
==============
*/
void __thiscall pulse_sum_normal::SOLVER_solver_prolog(pulse_sum_normal *this, const float delta_t)
{
  pulse_sum_normal *v2; // esi
  double v3; // ST0C_8
  double v4; // st7
  float *v5; // eax
  pulse_sum_normal *v6; // ecx
  int savedregs; // [esp+14h] [ebp+0h]
  float delta_ta; // [esp+1Ch] [ebp+8h]

  v2 = this;
  v3 = this->m_right_side;
  v4 = pulse_sum_normal::get_vel(this, (int)&savedregs);
  v5 = &v2->m_pulse_sum_cache->m_pulse_sum;
  v2->m_right_side = v3 - v4;
  delta_ta = *v5 * delta_t;
  v2->m_pulse_sum = delta_ta;
  v2->m_pulse_sum = pulse_sum_normal::clamp_pulse_sum(v6, delta_ta);
  pulse_sum_normal::apply(v2, &v2->m_pulse_sum);
}

