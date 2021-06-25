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
pulse_sum_wheel::set_side_fwd_ratios
==============
*/
void __thiscall pulse_sum_wheel::set_side_fwd_ratios(pulse_sum_wheel *this, const float side_ratio, const float fwd_ratio, const float side_fric_max)
{
  pulse_sum_wheel *v4; // esi

  v4 = this;
  if ( !this->m_side || !this->m_fwd )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_wheel.h",
           34,
           "m_side && m_fwd",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
  v4->m_side->m_pulse_limit_ratio = side_ratio;
  v4->m_fwd->m_pulse_limit_ratio = fwd_ratio;
  v4->m_side_fric_max = side_fric_max;
}

