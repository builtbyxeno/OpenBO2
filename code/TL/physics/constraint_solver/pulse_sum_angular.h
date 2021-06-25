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
pulse_sum_angular::setup_vel_uni_standard
==============
*/
void __thiscall pulse_sum_angular::setup_vel_uni_standard(pulse_sum_angular *this, const float delta_t, const float max_penalty_restitution_vel)
{
  double v3; // st7
  pulse_sum_angular *v4; // esi
  double v5; // st7
  float delta_tc; // [esp+Ch] [ebp+8h]
  float delta_ta; // [esp+Ch] [ebp+8h]
  float delta_tb; // [esp+Ch] [ebp+8h]

  v3 = 0.016666668;
  v4 = this;
  if ( delta_t > 0.016666668 )
    v3 = delta_t;
  delta_tc = v3;
  delta_ta = -pulse_sum_angular::get_pos(this) / delta_tc;
  v4->m_big_dirt = delta_ta;
  if ( delta_ta >= 0.0 )
  {
    v5 = 0.0;
  }
  else
  {
    v5 = 0.0;
    v4->m_big_dirt = delta_ta * 0.300000011920929;
  }
  delta_tb = -max_penalty_restitution_vel;
  if ( delta_tb > (double)v4->m_big_dirt )
    v4->m_big_dirt = delta_tb;
  if ( v5 > v4->m_big_dirt )
  {
    v4->m_right_side = v5;
  }
  else
  {
    v4->m_right_side = v4->m_big_dirt;
    v4->m_big_dirt = v5;
  }
  v4->m_cfm = v5;
}

