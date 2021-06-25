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
pulse_sum_angular::get_vel
==============
*/
double __thiscall pulse_sum_angular::get_vel(pulse_sum_angular *this)
{
  pulse_sum_node *v1; // eax
  float *v2; // edx
  rigid_body *v3; // eax
  float v4; // ST00_4
  float v5; // ST04_4
  float v6; // ST08_4

  v1 = this->m_b2;
  if ( v1 )
    v2 = &v1->m_rb->m_a_vel.x;
  else
    v2 = &this->m_b2_ap.x;
  v3 = this->m_b1->m_rb;
  v4 = v3->m_a_vel.x - *v2;
  v5 = v3->m_a_vel.y - v2[1];
  v6 = v3->m_a_vel.z - v2[2];
  return (float)(this->m_ud.y * v5 + this->m_ud.x * v4 + this->m_ud.z * v6);
}

/*
==============
pulse_sum_angular::get_pos
==============
*/
double __thiscall pulse_sum_angular::get_pos(pulse_sum_angular *this)
{
  float v1; // ST00_4
  float v2; // ST04_4
  float v3; // ST08_4
  float v4; // ST1C_4

  v1 = this->m_b1_r.y * this->m_b2_r.z - this->m_b1_r.z * this->m_b2_r.y;
  v2 = this->m_b1_r.z * this->m_b2_r.x - this->m_b1_r.x * this->m_b2_r.z;
  v3 = this->m_b1_r.x * this->m_b2_r.y - this->m_b1_r.y * this->m_b2_r.x;
  v4 = this->m_ud.y * v2 + this->m_ud.x * v1 + this->m_ud.z * v3;
  return -v4;
}

/*
==============
pulse_sum_angular::set
==============
*/
void __thiscall pulse_sum_angular::set(pulse_sum_angular *this, rigid_body *const b1, phys_vec3 *b1_r, rigid_body *const b2, phys_vec3 *b2_r, phys_vec3 *ud, pulse_sum_cache *const ps_cache)
{
  pulse_sum_angular *v7; // esi
  rigid_body *v8; // eax
  int v9; // ecx
  unsigned int v10; // ecx
  pulse_sum_node *v11; // ecx
  pulse_sum_node *v12; // eax
  double v13; // st7
  float v14; // ST20_4
  float v15; // ST24_4
  float v16; // ST28_4

  v7 = this;
  if ( !ps_cache
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_angular_inline.h",
         86,
         "ps_cache",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !b1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_angular_inline.h",
         87,
         "b1",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !b2
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_angular_inline.h",
         88,
         "b2",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( b1 == b2
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_angular_inline.h",
         89,
         "b1 != b2",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  PHYS_ASSERT_UNIT(ud);
  v8 = b1;
  if ( b1->m_node )
    goto LABEL_43;
  if ( !b2->m_node )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_angular_inline.h",
           91,
           "rbint::get_pulse_sum_node(b1) || rbint::get_pulse_sum_node(b2)",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v8 = b1;
  }
  if ( v8->m_node )
LABEL_43:
    v9 = (v8->m_flags & 0x30) == 0;
  else
    v9 = v8->m_flags & 0x30;
  if ( !v9 || (!b2->m_node ? (v10 = b2->m_flags & 0x30) : (v10 = (b2->m_flags & 0x30) == 0), !v10) )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_angular_inline.h",
           92,
           "rbint::verify_pulse_sum_node(b1) && rbint::verify_pulse_sum_node(b2)",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v8 = b1;
  }
  v11 = v8->m_node;
  if ( v11 )
  {
    v7->m_b1 = v11;
    v7->m_b1_r.x = b1_r->x;
    v7->m_b1_r.y = b1_r->y;
    v7->m_b1_r.z = b1_r->z;
    v12 = b2->m_node;
    if ( v12 )
    {
      v7->m_b2 = v12;
    }
    else
    {
      v7->m_b2 = NULL;
      v7->m_b2_ap.x = b2->m_a_vel.x;
      v7->m_b2_ap.y = b2->m_a_vel.y;
      v7->m_b2_ap.z = b2->m_a_vel.z;
      if ( v7->m_b2
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_angular.h",
             47,
             "m_b2 == NULL",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    v7->m_b2_r.x = b2_r->x;
    v7->m_b2_r.y = b2_r->y;
    v7->m_b2_r.z = b2_r->z;
    v7->m_ud.x = ud->x;
    v7->m_ud.y = ud->y;
    v13 = ud->z;
  }
  else
  {
    v7->m_b1 = b2->m_node;
    v7->m_b1_r.x = b2_r->x;
    v7->m_b1_r.y = b2_r->y;
    v7->m_b1_r.z = b2_r->z;
    v7->m_b2 = NULL;
    v7->m_b2_ap.x = v8->m_a_vel.x;
    v7->m_b2_ap.y = v8->m_a_vel.y;
    v7->m_b2_ap.z = v8->m_a_vel.z;
    if ( v7->m_b2
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_angular.h",
           47,
           "m_b2 == NULL",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v7->m_b2_r.x = b1_r->x;
    v7->m_b2_r.y = b1_r->y;
    v7->m_b2_r.z = b1_r->z;
    v14 = -ud->x;
    v15 = -ud->y;
    v16 = -ud->z;
    v7->m_ud.x = v14;
    v7->m_ud.y = v15;
    v13 = v16;
  }
  v7->m_ud.z = v13;
  v7->m_pulse_sum_cache = ps_cache;
  v7->m_flags = 0;
  pulse_sum_angular::calc_abs(v7);
}

/*
==============
pulse_sum_angular::calc_abs
==============
*/
void __usercall pulse_sum_angular::calc_abs(pulse_sum_angular *this@<ecx>, int a2@<ebp>)
{
  pulse_sum_angular *v2; // esi
  phys_vec3 *v3; // edi
  phys_vec3 *v4; // eax
  pulse_sum_node *v5; // eax
  phys_vec3 *v6; // eax
  int v7; // [esp-20h] [ebp-2Ch]
  float v8; // [esp-4h] [ebp-10h]
  int v9; // [esp+0h] [ebp-Ch]
  int v10; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v9 = a2;
  v10 = retaddr;
  v2 = this;
  v3 = &this->m_ud;
  v4 = phys_multiply((phys_vec3 *)&v7, &this->m_b1->m_world_inv_inertia, &this->m_ud);
  v2->m_b1_ap.x = v4->x;
  v2->m_b1_ap.y = v4->y;
  v2->m_b1_ap.z = v4->z;
  v5 = v2->m_b2;
  v2->m_denom = v2->m_b1_ap.y * v3->y + v2->m_b1_ap.x * v3->x + v3->z * v2->m_b1_ap.z;
  if ( v5 )
  {
    v6 = phys_multiply((phys_vec3 *)&v7, &v5->m_world_inv_inertia, v3);
    v2->m_b2_ap.x = v6->x;
    v2->m_b2_ap.y = v6->y;
    v2->m_b2_ap.z = v6->z;
    v8 = v2->m_b2_ap.x * v3->x + v2->m_b2_ap.y * v3->y + v3->z * v2->m_b2_ap.z;
    v2->m_denom = v8 + v2->m_denom;
  }
  if ( v2->m_denom <= 0.0000099999997 )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_angular_inline.h",
           10,
           "m_denom > 0.00001f",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
}

/*
==============
pulse_sum_angular::get_objective
==============
*/
double __thiscall pulse_sum_angular::get_objective(pulse_sum_angular *this)
{
  pulse_sum_node *v1; // eax
  float v2; // edx
  float relv; // ST0C_4
  pulse_sum_node *v4; // eax
  float v7; // [esp-Ch] [ebp-2Ch]
  float v8; // [esp-8h] [ebp-28h]
  float v9; // [esp-4h] [ebp-24h]

  v1 = this->m_b1;
  v7 = v1->a_vel.x;
  v8 = v1->a_vel.y;
  v2 = v1->a_vel.z;
  relv = v1->a_vel.w;
  v4 = this->m_b2;
  v9 = v2;
  if ( v4 )
  {
    v7 = v7 - v4->a_vel.x;
    v8 = v8 - v4->a_vel.y;
    v9 = v2 - v4->a_vel.z;
  }
  return (float)(this->m_ud.y * v8 + this->m_ud.x * v7 + this->m_ud.z * v9);
}

/*
==============
pulse_sum_angular::apply
==============
*/
void __thiscall pulse_sum_angular::apply(pulse_sum_angular *this, const float *s_)
{
  pulse_sum_node *v2; // eax
  float v3; // ST00_4
  float v4; // ST04_4
  float v5; // ST08_4
  pulse_sum_node *v6; // eax
  float v7; // ST00_4
  float v8; // ST04_4
  float v9; // ST08_4

  v2 = this->m_b1;
  v3 = this->m_b1_ap.x * *s_;
  v4 = this->m_b1_ap.y * *s_;
  v5 = *s_ * this->m_b1_ap.z;
  v2->a_vel.x = v2->a_vel.x + v3;
  v2->a_vel.y = v2->a_vel.y + v4;
  v2->a_vel.z = v2->a_vel.z + v5;
  v6 = this->m_b2;
  if ( v6 )
  {
    v7 = *s_ * this->m_b2_ap.x;
    v8 = this->m_b2_ap.y * *s_;
    v9 = *s_ * this->m_b2_ap.z;
    v6->a_vel.x = v6->a_vel.x - v7;
    v6->a_vel.y = v6->a_vel.y - v8;
    v6->a_vel.z = v6->a_vel.z - v9;
  }
}

/*
==============
pulse_sum_angular::clamp_pulse_sum
==============
*/
double __thiscall pulse_sum_angular::clamp_pulse_sum(pulse_sum_angular *this, const float ps)
{
  pulse_sum_angular *v2; // esi
  double result; // st7

  v2 = this;
  if ( this->m_pulse_sum_max < (double)this->m_pulse_sum_min
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_angular_inline.h",
         40,
         "m_pulse_sum_min <= m_pulse_sum_max",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  result = ps;
  if ( v2->m_pulse_sum_min > (double)ps )
    return v2->m_pulse_sum_min;
  if ( v2->m_pulse_sum_max < result )
    result = v2->m_pulse_sum_max;
  return result;
}

/*
==============
pulse_sum_angular::SOLVER_apply_relaxation
==============
*/
void __thiscall pulse_sum_angular::SOLVER_apply_relaxation(pulse_sum_angular *this, float *error_sq)
{
  pulse_sum_angular *v2; // esi
  double v3; // st7
  const float error_sq___; // [esp+8h] [ebp-8h]
  const float m_last_pulse_sum; // [esp+Ch] [ebp-4h]

  v2 = this;
  error_sq___ = pulse_sum_angular::get_objective(this) + v2->m_cfm * v2->m_pulse_sum - v2->m_right_side;
  m_last_pulse_sum = v2->m_pulse_sum;
  error_sq___ = m_last_pulse_sum - error_sq___ / v2->m_denom;
  error_sq___ = pulse_sum_angular::clamp_pulse_sum(v2, error_sq___);
  v3 = error_sq___;
  v2->m_pulse_sum = error_sq___;
  if ( (v2->m_pulse_sum_min - 0.00009999999747378752 > v3 || v2->m_pulse_sum_max + 0.00009999999747378752 < v3)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_angular_inline.h",
         61,
         "m_pulse_sum >= (m_pulse_sum_min - .0001f) && m_pulse_sum <= (m_pulse_sum_max + .0001f)",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  error_sq___ = v2->m_pulse_sum - m_last_pulse_sum;
  pulse_sum_angular::apply(v2, &error_sq___);
  error_sq___ = (v2->m_pulse_sum - m_last_pulse_sum) * v2->m_denom;
  error_sq___ = error_sq___ * error_sq___;
  if ( *error_sq < (double)error_sq___ )
    *error_sq = error_sq___;
}

