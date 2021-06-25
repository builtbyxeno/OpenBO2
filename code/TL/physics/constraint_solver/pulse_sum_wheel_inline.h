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
pulse_sum_wheel::pulse_chain_within_limits
==============
*/
bool __thiscall pulse_sum_wheel::pulse_chain_within_limits(pulse_sum_wheel *this)
{
  pulse_sum_normal *v1; // edx
  pulse_sum_normal *v2; // esi
  float a2_; // ST04_4
  float b2_; // ST08_4
  double v5; // st4
  float v6; // ST04_4
  double v7; // st6
  float v8; // ST04_4
  double v9; // st5
  float v10; // ST04_4
  float v11; // ST04_4
  float v12; // ST04_4
  float p2_; // [esp+Ch] [ebp-8h]
  float a_; // [esp+10h] [ebp-4h]

  v1 = this->m_side;
  v2 = this->m_fwd;
  a_ = -v1->m_pulse_limit_ratio * this->m_suspension.m_pulse_sum;
  if ( this->m_side_fric_max <= (double)a_ )
    a_ = this->m_side_fric_max;
  p2_ = -v2->m_pulse_limit_ratio * this->m_suspension.m_pulse_sum;
  if ( this->m_side_fric_max <= (double)p2_ )
    p2_ = this->m_side_fric_max;
  a2_ = a_ * a_;
  b2_ = p2_ * p2_;
  v5 = a2_;
  v6 = b2_ * a2_;
  v7 = v6;
  v8 = v1->m_pulse_sum * v1->m_pulse_sum;
  v9 = b2_ * v8;
  v10 = v2->m_pulse_sum * v2->m_pulse_sum;
  v11 = v5 * v10 + v9;
  v12 = v11 * 0.9999900000002526;
  return v12 <= v7;
}

/*
==============
pulse_sum_wheel::clamp_pulse_sum_pulse_chain
==============
*/
char __thiscall pulse_sum_wheel::clamp_pulse_sum_pulse_chain(pulse_sum_wheel *this, float *ps1_, float *ps2_)
{
  pulse_sum_normal *v3; // edx
  pulse_sum_normal *v4; // esi
  float numer_sq; // ST04_4
  float denom_sq; // ST08_4
  float v7; // ST10_4
  double v8; // st6
  double v9; // st7
  float v10; // ST08_4
  float v11; // ST08_4
  float v12; // ST04_4
  double v13; // st7
  double v14; // st6
  char result; // al
  float v16; // ST04_4
  float v17; // ST04_4
  double v18; // st7
  float v19; // ST10_4
  float p2_; // [esp+Ch] [ebp-Ch]
  float t_; // [esp+10h] [ebp-8h]
  float a_; // [esp+14h] [ebp-4h]
  float a_a; // [esp+14h] [ebp-4h]

  v3 = this->m_fwd;
  v4 = this->m_side;
  a_ = -v4->m_pulse_limit_ratio * this->m_suspension.m_pulse_sum;
  if ( this->m_side_fric_max <= (double)a_ )
    a_ = this->m_side_fric_max;
  t_ = -v3->m_pulse_limit_ratio * this->m_suspension.m_pulse_sum;
  if ( this->m_side_fric_max <= (double)t_ )
    t_ = this->m_side_fric_max;
  numer_sq = a_ * a_;
  denom_sq = t_ * t_;
  a_a = v4->m_pulse_sum;
  p2_ = v3->m_pulse_sum;
  v7 = a_a * a_a;
  v8 = v7 * denom_sq;
  v9 = denom_sq;
  v10 = p2_ * p2_;
  v11 = v10 * numer_sq + v8;
  v12 = v9 * numer_sq;
  v13 = v12;
  v14 = v11;
  if ( v11 >= (double)v12 || v13 < 0.0000099999997 )
  {
    v3->m_flags |= 4u;
    if ( v14 <= 0.0000099999997 )
    {
      v18 = 0.0;
    }
    else
    {
      v16 = v13 / v14;
      v17 = sqrt(v16);
      v18 = v17;
    }
    v19 = v18;
    *ps1_ = v19 * a_a;
    *ps2_ = v19 * p2_;
    result = 1;
  }
  else
  {
    v3->m_flags &= 0xFFFFFFFB;
    *ps1_ = v4->m_pulse_sum;
    result = 0;
    *ps2_ = v3->m_pulse_sum;
  }
  return result;
}

/*
==============
pulse_sum_wheel::addp_pulse_chain
==============
*/
void __thiscall pulse_sum_wheel::addp_pulse_chain(pulse_sum_wheel *this)
{
  pulse_sum_wheel *v1; // esi
  pulse_sum_normal *v2; // edi
  pulse_sum_normal *v3; // ebx
  float s_; // [esp+Ch] [ebp-Ch]
  float ps2_; // [esp+10h] [ebp-8h]
  float ps1_; // [esp+14h] [ebp-4h]

  v1 = this;
  v2 = this->m_side;
  v3 = this->m_fwd;
  if ( pulse_sum_wheel::clamp_pulse_sum_pulse_chain(this, &ps1_, &ps2_) )
  {
    s_ = ps1_ - v2->m_pulse_sum;
    pulse_sum_normal::apply(v2, &s_);
    v2->m_pulse_sum = ps1_;
    s_ = ps2_ - v3->m_pulse_sum;
    pulse_sum_normal::apply(v3, &s_);
    v3->m_pulse_sum = ps2_;
  }
  if ( !pulse_sum_wheel::pulse_chain_within_limits(v1) )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_wheel_inline.h",
           67,
           "pulse_chain_within_limits()",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
}

/*
==============
pulse_sum_wheel::SOLVER_apply_relaxation
==============
*/
void __thiscall pulse_sum_wheel::SOLVER_apply_relaxation(pulse_sum_wheel *this, float *error_sq)
{
  float *v2; // edi
  pulse_sum_wheel *v3; // esi
  pulse_sum_normal *v4; // ecx
  pulse_sum_normal *v5; // ecx
  float m_fwd_last_pulse_sum; // [esp+8h] [ebp-4h]
  float error_sq___; // [esp+14h] [ebp+8h]
  float error_sq___c; // [esp+14h] [ebp+8h]
  float error_sq___a; // [esp+14h] [ebp+8h]
  float error_sq___d; // [esp+14h] [ebp+8h]
  float error_sq___b; // [esp+14h] [ebp+8h]

  v2 = error_sq;
  v3 = this;
  pulse_sum_normal::SOLVER_apply_relaxation(&this->m_suspension, error_sq, 1);
  v4 = v3->m_side;
  if ( v4 )
  {
    error_sq___ = v4->m_pulse_sum;
    pulse_sum_normal::SOLVER_apply_relaxation(v4, v2, v3->m_fwd == NULL);
    if ( v3->m_fwd )
    {
      v5 = v3->m_fwd;
      m_fwd_last_pulse_sum = v5->m_pulse_sum;
      pulse_sum_normal::SOLVER_apply_relaxation(v5, v2, 0);
      pulse_sum_wheel::addp_pulse_chain(v3);
      error_sq___c = (v3->m_side->m_pulse_sum - error_sq___) * v3->m_side->m_denom;
      error_sq___a = error_sq___c * error_sq___c;
      if ( *v2 < (double)error_sq___a )
        *v2 = error_sq___a;
      error_sq___d = (v3->m_fwd->m_pulse_sum - m_fwd_last_pulse_sum) * v3->m_fwd->m_denom;
      error_sq___b = error_sq___d * error_sq___d;
      if ( *v2 < (double)error_sq___b )
        *v2 = error_sq___b;
    }
  }
}

/*
==============
pulse_sum_wheel::SOLVER_solver_prolog
==============
*/
void __thiscall pulse_sum_wheel::SOLVER_solver_prolog(pulse_sum_wheel *this, const float delta_t)
{
  pulse_sum_wheel *v2; // edi
  double ps; // ST10_8
  double v4; // st7
  float *v5; // eax
  pulse_sum_normal *v6; // esi
  double v7; // ST10_8
  double v8; // st7
  float *v9; // ecx
  pulse_sum_normal *v10; // ecx
  int savedregs; // [esp+18h] [ebp+0h]

  v2 = this;
  ps = this->m_suspension.m_right_side;
  v4 = pulse_sum_normal::get_vel(&this->m_suspension, (int)&savedregs);
  v5 = &v2->m_suspension.m_pulse_sum_cache->m_pulse_sum;
  v2->m_suspension.m_right_side = ps - v4;
  *((float *)&ps + 1) = *v5 * delta_t;
  v2->m_suspension.m_pulse_sum = *((float *)&ps + 1);
  v2->m_suspension.m_pulse_sum = pulse_sum_normal::clamp_pulse_sum(&v2->m_suspension, *((const float *)&ps + 1));
  pulse_sum_normal::apply(&v2->m_suspension, &v2->m_suspension.m_pulse_sum);
  v6 = v2->m_side;
  if ( v6 )
  {
    v7 = v6->m_right_side;
    v8 = pulse_sum_normal::get_vel(v2->m_side, (int)&savedregs);
    v9 = &v6->m_pulse_sum_cache->m_pulse_sum;
    v6->m_right_side = v7 - v8;
    *((float *)&v7 + 1) = *v9 * delta_t;
    v6->m_pulse_sum = *((float *)&v7 + 1);
    v6->m_pulse_sum = pulse_sum_normal::clamp_pulse_sum(v6, *((const float *)&v7 + 1));
    pulse_sum_normal::apply(v6, &v6->m_pulse_sum);
    v10 = v2->m_fwd;
    if ( v10 )
    {
      pulse_sum_normal::SOLVER_solver_prolog(v10, delta_t);
      pulse_sum_wheel::addp_pulse_chain(v2);
    }
  }
}

