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
rigid_body_constraint_wheel::set_wheel_state_accelerating
==============
*/
void __thiscall rigid_body_constraint_wheel::set_wheel_state_accelerating(rigid_body_constraint_wheel *this, const float desired_speed_k, const float acceleration_factor_k)
{
  this->m_wheel_state = 0;
  this->m_desired_speed_k = desired_speed_k;
  this->m_acceleration_factor_k = acceleration_factor_k;
}

/*
==============
rigid_body_constraint_wheel::get_wheel_state_accelerating
==============
*/
void __thiscall rigid_body_constraint_wheel::get_wheel_state_accelerating(rigid_body_constraint_wheel *this, float *desired_speed_k, float *acceleration_factor_k)
{
  *desired_speed_k = this->m_desired_speed_k;
  *acceleration_factor_k = this->m_acceleration_factor_k;
}

/*
==============
rigid_body_constraint_wheel::set_wheel_state_braking
==============
*/
void __thiscall rigid_body_constraint_wheel::set_wheel_state_braking(rigid_body_constraint_wheel *this, const float braking_factor_k)
{
  this->m_wheel_state = 1;
  this->m_braking_factor_k = braking_factor_k;
}

/*
==============
rigid_body_constraint_wheel::set_no_collision
==============
*/
void __thiscall rigid_body_constraint_wheel::set_no_collision(rigid_body_constraint_wheel *this)
{
  this->m_wheel_flags &= 0xFFFFFFFE;
  this->b2 = NULL;
}

/*
==============
rigid_body_constraint_wheel::set_collision
==============
*/
void __thiscall rigid_body_constraint_wheel::set_collision(rigid_body_constraint_wheel *this, rigid_body *const rb, phys_vec3 *hitp_loc, phys_vec3 *hitn_loc)
{
  this->m_wheel_flags |= 1u;
  this->b2 = rb;
  this->m_b2_hitp_loc.x = hitp_loc->x;
  this->m_b2_hitp_loc.y = hitp_loc->y;
  this->m_b2_hitp_loc.z = hitp_loc->z;
  this->m_b2_hitn_loc.x = hitn_loc->x;
  this->m_b2_hitn_loc.y = hitn_loc->y;
  this->m_b2_hitn_loc.z = hitn_loc->z;
}

/*
==============
rigid_body_constraint_wheel::get_hitp_abs
==============
*/
phys_vec3 *__thiscall rigid_body_constraint_wheel::get_hitp_abs(rigid_body_constraint_wheel *this, phys_vec3 *result)
{
  phys_multiply(result, &this->b2->m_mat, &this->m_b2_hitp_loc);
  return result;
}

/*
==============
rigid_body_constraint_wheel::get_hitn_abs
==============
*/
phys_vec3 *__thiscall rigid_body_constraint_wheel::get_hitn_abs(rigid_body_constraint_wheel *this, phys_vec3 *result)
{
  phys_multiply(result, &this->b2->m_mat, &this->m_b2_hitn_loc);
  return result;
}

/*
==============
lerp_float
==============
*/
double lerp_float(const float tgt, const float cur, const float rate, const float delta_t)
{
  double result; // st7
  double v5; // st6
  long double v6; // st5
  double v7; // st4
  double v8; // st4
  float stepa; // [esp+8h] [ebp+8h]
  float step; // [esp+8h] [ebp+8h]
  float stepb; // [esp+8h] [ebp+8h]
  float stepc; // [esp+8h] [ebp+8h]
  float cura; // [esp+Ch] [ebp+Ch]

  result = tgt;
  v5 = cur;
  stepa = tgt - cur;
  v6 = stepa;
  if ( stepa <= 0.0 )
    v7 = -rate;
  else
    v7 = rate;
  step = v7 * delta_t;
  cura = fabs(v6);
  if ( cura > 0.05000000074505806 )
  {
    v8 = step;
    stepb = fabs(step);
    if ( stepb <= (double)cura )
    {
      stepc = v8 + v5;
      result = stepc;
    }
  }
  return result;
}

/*
==============
rigid_body_constraint_wheel::set
==============
*/
void __thiscall rigid_body_constraint_wheel::set(rigid_body_constraint_wheel *this, phys_vec3 *wheel_center_loc, phys_vec3 *suspension_dir_loc, phys_vec3 *wheel_axis_loc, const float wheel_radius, const float fwd_fric_k, const float side_fric_k, const float suspension_stiffness_k, const float suspension_damp_k, const float hard_limit_dist, const float roll_stability_factor, const float pitch_stability_factor, const float side_fric_max)
{
  phys_vec3 *v13; // esi
  phys_vec3 *v14; // edi

  this->m_b1_wheel_center_loc.x = wheel_center_loc->x;
  v13 = &this->m_b1_suspension_dir_loc;
  this->m_b1_wheel_center_loc.y = wheel_center_loc->y;
  v14 = &this->m_b1_wheel_axis_loc;
  this->m_b1_wheel_center_loc.z = wheel_center_loc->z;
  v13->x = suspension_dir_loc->x;
  v13->y = suspension_dir_loc->y;
  v13->z = suspension_dir_loc->z;
  v14->x = wheel_axis_loc->x;
  v14->y = wheel_axis_loc->y;
  v14->z = wheel_axis_loc->z;
  this->m_wheel_state = 1;
  this->m_wheel_flags = 0;
  this->m_wheel_radius = wheel_radius;
  this->m_fwd_fric_k = fwd_fric_k;
  this->m_side_fric_k = side_fric_k;
  this->m_side_fric_max = side_fric_max;
  this->m_suspension_stiffness_k = suspension_stiffness_k;
  this->m_suspension_damp_k = suspension_damp_k;
  this->m_hard_limit_dist = hard_limit_dist;
  this->m_roll_stability_factor = roll_stability_factor;
  this->m_pitch_stability_factor = pitch_stability_factor;
  this->m_braking_factor_k = 0.0;
  this->m_turning_radius_ratio_max_speed = 1.0;
  this->m_turning_radius_ratio_accel = 1.0;
  this->m_wheel_vel = 0.0;
  this->m_wheel_pos = 0.0;
  this->m_wheel_fwd = 0.0;
  this->m_wheel_displaced_center_dist = 0.0;
  PHYS_ASSERT_UNIT(&this->m_b1_suspension_dir_loc);
  PHYS_ASSERT_UNIT(v14);
  PHYS_ASSERT_ORTHOGONAL(v13, v14);
}

/*
==============
rigid_body_constraint_wheel::get_wheel_collide_segment
==============
*/
void __userpurge rigid_body_constraint_wheel::get_wheel_collide_segment(rigid_body_constraint_wheel *this@<ecx>, int a2@<ebp>, phys_mat44 *b1_mat, phys_vec3 *const p0, phys_vec3 *const p1)
{
  rigid_body_constraint_wheel *v5; // edi
  phys_vec3 *v6; // eax
  phys_vec3 *v7; // eax
  double v8; // st7
  double v9; // st6
  double v10; // st5
  double v11; // st4
  double v12; // st3
  double v13; // st2
  double v14; // [esp-1Ch] [ebp-4Ch]
  float v15; // [esp-18h] [ebp-48h]
  float v16; // [esp-14h] [ebp-44h]
  float v17; // [esp-Ch] [ebp-3Ch]
  float v18; // [esp-8h] [ebp-38h]
  float v19; // [esp-4h] [ebp-34h]
  phys_vec3 seg_dir; // [esp+0h] [ebp-30h]
  float v21; // [esp+20h] [ebp-10h]
  int v22; // [esp+24h] [ebp-Ch]
  int v23; // [esp+28h] [ebp-8h]
  int retaddr; // [esp+30h] [ebp+0h]

  v22 = a2;
  v23 = retaddr;
  v5 = this;
  if ( (unsigned __int8)p0 & 0xF
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_math.h",
         444,
         "uint(v) % PHYS_ALIGNOF(phys_vec3) == 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (unsigned __int8)p1 & 0xF
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_math.h",
         444,
         "uint(v) % PHYS_ALIGNOF(phys_vec3) == 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v6 = phys_multiply((phys_vec3 *)&v14, b1_mat, &v5->m_b1_wheel_center_loc);
  seg_dir.y = v6->x + b1_mat->w.x;
  seg_dir.z = v6->y + b1_mat->w.y;
  seg_dir.w = v6->z + b1_mat->w.z;
  v7 = phys_multiply((phys_vec3 *)&v14, b1_mat, &v5->m_b1_suspension_dir_loc);
  v21 = v5->m_wheel_radius;
  v17 = v7->x * v21;
  v18 = v7->y * v21;
  v19 = v21 * v7->z;
  v8 = seg_dir.y;
  v9 = v17;
  *(float *)&v14 = seg_dir.y - v17;
  v10 = seg_dir.z;
  v11 = v18;
  v15 = seg_dir.z - v18;
  v12 = seg_dir.w;
  v13 = v19;
  v16 = seg_dir.w - v19;
  p0->x = *(float *)&v14;
  p0->y = v15;
  p0->z = v16;
  *(float *)&v14 = v8 + v9;
  v15 = v10 + v11;
  v16 = v12 + v13;
  p1->x = *(float *)&v14;
  p1->y = v15;
  p1->z = v16;
}

/*
==============
rigid_body_constraint_wheel::epilog_vel_constraint
==============
*/
void __userpurge rigid_body_constraint_wheel::epilog_vel_constraint(rigid_body_constraint_wheel *this@<ecx>, int a2@<ebp>, const float delta_t)
{
  rigid_body_constraint_wheel *v3; // esi
  float v4; // edx
  rigid_body *v5; // edi
  rigid_body *v6; // eax
  float *v7; // eax
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st6
  double v12; // st6
  pulse_sum_normal *v13; // eax
  pulse_sum_normal *v14; // ecx
  double v15; // st6
  float v16; // ST20_4
  float v17; // [esp+20h] [ebp-5Ch]
  float v18; // [esp+24h] [ebp-58h]
  float v19; // [esp+28h] [ebp-54h]
  float v20; // [esp+30h] [ebp-4Ch]
  float v21; // [esp+34h] [ebp-48h]
  float v22; // [esp+38h] [ebp-44h]
  phys_vec3 b1_r; // [esp+3Ch] [ebp-40h]
  phys_vec3 b2_r; // [esp+4Ch] [ebp-30h]
  phys_vec3 b1_suspension_dir; // [esp+5Ch] [ebp-20h]
  const float prev_wheel_displaced_center_dist; // [esp+6Ch] [ebp-10h]
  int v27; // [esp+70h] [ebp-Ch]
  float lerp_rate; // [esp+74h] [ebp-8h]
  float retaddr; // [esp+7Ch] [ebp+0h]

  v27 = a2;
  lerp_rate = retaddr;
  v3 = this;
  v4 = *(float *)&this->m_wheel_flags;
  b1_suspension_dir.y = this->m_wheel_displaced_center_dist;
  b1_suspension_dir.z = v4;
  if ( LOBYTE(v4) & 1 )
  {
    v5 = this->b1;
    phys_multiply((phys_vec3 *)((char *)&b2_r + 4), &this->b1->m_mat, &this->m_b1_suspension_dir_loc);
    b1_suspension_dir.w = v3->m_wheel_radius;
    b1_r.y = b2_r.y * b1_suspension_dir.w;
    b1_r.z = b2_r.z * b1_suspension_dir.w;
    b1_r.w = b1_suspension_dir.w * b2_r.w;
    phys_multiply((phys_vec3 *)&v17, &v5->m_mat, &v3->m_b1_wheel_center_loc);
    v6 = v3->b2;
    v20 = v17 + b1_r.y;
    v21 = v18 + b1_r.z;
    v22 = v19 + b1_r.w;
    phys_multiply((phys_vec3 *)((char *)&b1_r + 4), &v6->m_mat, &v3->m_b2_hitp_loc);
    v7 = &v3->b2->m_last_position.x;
    v17 = v7[24] + b1_r.y;
    v18 = v7[25] + b1_r.z;
    v19 = v7[26] + b1_r.w;
    b1_r.y = v5->m_mat.w.x + v20;
    b1_r.z = v5->m_mat.w.y + v21;
    b1_r.w = v5->m_mat.w.z + v22;
    v20 = b1_r.y - v17;
    v21 = b1_r.z - v18;
    v22 = b1_r.w - v19;
    b1_suspension_dir.w = v21 * b2_r.z + v20 * b2_r.y + v22 * b2_r.w;
    v8 = b1_suspension_dir.w;
    if ( v3->m_hard_limit_dist < (double)b1_suspension_dir.w )
      v8 = v3->m_hard_limit_dist;
    v4 = b1_suspension_dir.z;
    b1_suspension_dir.w = v8;
    v9 = b1_suspension_dir.w;
  }
  else
  {
    v9 = 0.0;
  }
  v3->m_wheel_displaced_center_dist = v9;
  if ( v3->m_wheel_displaced_center_dist >= (double)b1_suspension_dir.y )
  {
    v10 = delta_t;
  }
  else
  {
    v10 = delta_t;
    b1_suspension_dir.y = b1_suspension_dir.y - 51.0 * delta_t;
    v11 = b1_suspension_dir.y;
    if ( b1_suspension_dir.y < (double)v3->m_wheel_displaced_center_dist )
      v11 = v3->m_wheel_displaced_center_dist;
    b1_suspension_dir.w = v11;
    v3->m_wheel_displaced_center_dist = b1_suspension_dir.w;
  }
  if ( v3->m_ps_suspension )
    v12 = v3->m_ps_cache_list[1].m_pulse_sum;
  else
    v12 = 0.0;
  v3->m_wheel_normal_force = v12;
  HIBYTE(prev_wheel_displaced_center_dist) = 0;
  b1_suspension_dir.y = v3->m_wheel_vel * v3->m_wheel_radius;
  b1_suspension_dir.y = fabs(b1_suspension_dir.y);
  if ( velocity_clamp < (double)b1_suspension_dir.y )
    HIBYTE(prev_wheel_displaced_center_dist) = 1;
  v13 = v3->m_ps_side_fric;
  if ( v13 )
  {
    v14 = v3->m_ps_fwd_fric;
    if ( v14 )
    {
      if ( v14->m_flags & 4 )
        v3->m_wheel_flags = LODWORD(v4) | 4;
      v3->m_wheel_vel = pulse_sum_normal::get_unclamped_pulse_sum(v14) * v3->m_wheel_fwd / v3->m_wheel_radius
                      + v3->m_wheel_vel;
      v10 = delta_t;
    }
    else if ( v13->m_flags & 2 )
    {
      v3->m_wheel_flags = LODWORD(v4) | 4;
    }
  }
  if ( HIBYTE(prev_wheel_displaced_center_dist) )
    v3->m_wheel_pos = v3->m_wheel_vel * v10 + v3->m_wheel_pos;
  if ( !(v3->m_wheel_flags & 1) )
  {
    if ( v3->m_braking_factor_k >= 50.0 )
      v15 = lr;
    else
      v15 = lr_0;
    b1_suspension_dir.w = v15;
    v16 = v10;
    v3->m_wheel_vel = lerp_float(0.0, v3->m_wheel_vel, b1_suspension_dir.w, v16);
  }
}

/*
==============
rigid_body_constraint_wheel::setup_constraint
==============
*/
void __userpurge rigid_body_constraint_wheel::setup_constraint(rigid_body_constraint_wheel *this@<ecx>, int a2@<ebp>, pulse_sum_constraint_solver *psys, const float delta_t)
{
  rigid_body_constraint_wheel *v4; // esi
  rigid_body *v5; // edi
  phys_mat44 *v6; // eax
  float *v7; // ecx
  double v8; // st7
  double v9; // st6
  double v10; // st5
  double v11; // st4
  double v12; // st3
  double v13; // st2
  unsigned int v14; // eax
  pulse_sum_normal *v15; // eax
  pulse_sum_normal *v16; // edi
  rigid_body *v17; // eax
  rigid_body *v18; // edx
  bool v19; // zf
  double v20; // st5
  double v21; // rt2
  double v22; // rtt
  pulse_sum_wheel *v23; // eax
  pulse_sum_normal *v24; // eax
  float *v25; // edi
  pulse_sum_normal *v26; // ecx
  double v27; // st7
  double v28; // st6
  char *v29; // eax
  rigid_body *v30; // ST10_4
  rigid_body *v31; // ST08_4
  float *v32; // eax
  pulse_sum_normal *v33; // ecx
  phys_vec3 *v34; // eax
  unsigned int v35; // ecx
  pulse_sum_normal *v36; // eax
  pulse_sum_wheel *v37; // edx
  pulse_sum_normal *v38; // eax
  rigid_body *v39; // ecx
  rigid_body *v40; // ST10_4
  rigid_body *v41; // ecx
  double v42; // st7
  float *v43; // eax
  pulse_sum_normal *v44; // eax
  double v45; // st7
  double v46; // st7
  double v47; // st6
  double v48; // st7
  float *v49; // eax
  double v50; // st7
  double v51; // st5
  double v52; // st6
  double v53; // st6
  float *v54; // eax
  pulse_sum_wheel *v55; // ecx
  phys_vec3 *v56; // eax
  int v57; // [esp+1Ch] [ebp-11Ch]
  phys_mat44 rot_mat; // [esp+28h] [ebp-110h]
  float v59; // [esp+6Ch] [ebp-CCh]
  float v60; // [esp+70h] [ebp-C8h]
  float v61; // [esp+74h] [ebp-C4h]
  phys_vec3 fric_ud; // [esp+78h] [ebp-C0h]
  phys_vec3 b1_r_displace; // [esp+88h] [ebp-B0h]
  phys_vec3 b2_r; // [esp+98h] [ebp-A0h]
  phys_vec3 b1_suspension_dir; // [esp+A8h] [ebp-90h]
  phys_vec3 b1_r; // [esp+B8h] [ebp-80h]
  phys_vec3 wheel_axis; // [esp+C8h] [ebp-70h]
  unsigned int v68; // [esp+E8h] [ebp-50h]
  float v69; // [esp+ECh] [ebp-4Ch]
  float v70; // [esp+F0h] [ebp-48h]
  pulse_sum_wheel *ps_wheel; // [esp+F4h] [ebp-44h]
  float desired_speed; // [esp+F8h] [ebp-40h]
  float v73; // [esp+108h] [ebp-30h]
  float v74; // [esp+10Ch] [ebp-2Ch]
  float v75; // [esp+110h] [ebp-28h]
  float k_; // [esp+114h] [ebp-24h]
  float v77; // [esp+128h] [ebp-10h]
  int v78; // [esp+12Ch] [ebp-Ch]
  int v79; // [esp+130h] [ebp-8h]
  int retaddr; // [esp+138h] [ebp+0h]

  v78 = a2;
  v79 = retaddr;
  v4 = this;
  v4->m_wheel_flags &= 0xFFFFFFFB;
  this->m_wheel_fwd = 0.0;
  this->m_ps_suspension = NULL;
  this->m_ps_side_fric = NULL;
  this->m_ps_fwd_fric = NULL;
  v68 = this->m_wheel_flags;
  if ( v68 & 1 )
  {
    v5 = this->b1;
    phys_multiply((phys_vec3 *)((char *)&b2_r + 4), &this->b1->m_mat, &this->m_b1_suspension_dir_loc);
    v73 = v4->m_wheel_radius;
    v74 = b2_r.y * v73;
    v75 = b2_r.z * v73;
    k_ = v73 * b2_r.w;
    phys_multiply((phys_vec3 *)&v69, &v5->m_mat, &v4->m_b1_wheel_center_loc);
    v6 = &v4->b2->m_mat;
    b1_suspension_dir.y = v69 + v74;
    v77 = *(float *)&v6;
    b1_suspension_dir.z = v70 + v75;
    b1_suspension_dir.w = *(float *)&ps_wheel + k_;
    phys_multiply((phys_vec3 *)((char *)&b1_r_displace + 4), v6, &v4->m_b2_hitp_loc);
    v7 = &v4->b2->m_last_position.x;
    wheel_axis.y = v7[24] + b1_r_displace.y;
    v8 = b1_r_displace.z;
    wheel_axis.z = v7[25] + b1_r_displace.z;
    v9 = b1_r_displace.w;
    wheel_axis.w = v7[26] + b1_r_displace.w;
    v10 = b1_suspension_dir.y;
    v74 = v5->m_mat.w.x + b1_suspension_dir.y;
    v11 = b1_suspension_dir.z;
    v75 = v5->m_mat.w.y + b1_suspension_dir.z;
    v12 = b1_suspension_dir.w;
    k_ = v5->m_mat.w.z + b1_suspension_dir.w;
    v69 = v74 - wheel_axis.y;
    v70 = v75 - wheel_axis.z;
    *(float *)&ps_wheel = k_ - wheel_axis.w;
    v73 = v69 * b2_r.y + v70 * b2_r.z + *(float *)&ps_wheel * b2_r.w;
    v13 = v73;
    v73 = v4->m_hard_limit_dist - 3.400000095367432;
    if ( v73 > v13 )
      v14 = v68 & 0xFFFFFFFD;
    else
      v14 = v68 | 2;
    v4->m_wheel_flags = v14;
    wheel_axis.y = v7[24] + b1_r_displace.y;
    wheel_axis.z = v8 + v7[25];
    wheel_axis.w = v9 + v7[26];
    v74 = v10 + v5->m_mat.w.x;
    v75 = v11 + v5->m_mat.w.y;
    k_ = v12 + v5->m_mat.w.z;
    v69 = v74 - wheel_axis.y;
    v70 = v75 - wheel_axis.z;
    *(float *)&ps_wheel = k_ - wheel_axis.w;
    if ( v14 & 2 )
    {
      phys_multiply((phys_vec3 *)&v74, (phys_mat44 *)LODWORD(v77), &v4->m_b2_hitn_loc);
      rot_mat.w.y = -v74;
      rot_mat.w.z = -v75;
      rot_mat.w.w = -k_;
      v15 = pulse_sum_constraint_solver::create_pulse_sum_normal(psys);
      v77 = v4->m_hard_limit_dist;
      v16 = v15;
      v17 = v4->b2;
      v74 = v77 * b2_r.y;
      v18 = v4->b1;
      v75 = b2_r.z * v77;
      k_ = v77 * b2_r.w;
      b1_r.y = b1_suspension_dir.y - v74;
      b1_r.z = b1_suspension_dir.z - v75;
      b1_r.w = b1_suspension_dir.w - k_;
      pulse_sum_normal::set(
        v16,
        v18,
        (phys_vec3 *)((char *)&b1_r + 4),
        v17,
        (phys_vec3 *)((char *)&b1_r_displace + 4),
        (phys_vec3 *)((char *)&rot_mat.w + 4),
        v4->m_ps_cache_list,
        &PHYS_ZERO_VEC_87);
      v16->m_pulse_sum_min = -10000000.0;
      v16->m_pulse_sum_max = 0.0;
      pulse_sum_normal::setup_vel_uni_standard(v16, delta_t, 170.0);
    }
    phys_multiply((phys_vec3 *)((char *)&b1_r + 4), &v4->b2->m_mat, &v4->m_b2_hitn_loc);
    v19 = SLOBYTE(v4->m_wheel_flags) >= 0;
    wheel_axis.y = -b1_r.y;
    wheel_axis.z = -b1_r.z;
    wheel_axis.w = -b1_r.w;
    if ( !v19 )
    {
      phys_multiply((phys_vec3 *)((char *)&b1_r + 4), &v4->b1->m_mat, &v4->m_b1_suspension_dir_loc);
      wheel_axis.y = b1_r.y;
      wheel_axis.z = b1_r.z;
      wheel_axis.w = b1_r.w;
    }
    v77 = wheel_axis.z * v70 + wheel_axis.y * v69 + wheel_axis.w * *(float *)&ps_wheel;
    v20 = v77;
    v77 = wheel_axis.y * v77;
    v74 = v77;
    v21 = v77;
    v77 = wheel_axis.z * v20;
    v75 = v77;
    v22 = v77;
    v77 = v20 * wheel_axis.w;
    b1_suspension_dir.y = b1_suspension_dir.y - v74;
    b1_suspension_dir.z = b1_suspension_dir.z - v75;
    b1_suspension_dir.w = b1_suspension_dir.w - v77;
    v74 = v21;
    v75 = v22;
    k_ = v77;
    b1_r_displace.y = b1_r_displace.y - v74;
    b1_r_displace.z = b1_r_displace.z - v75;
    b1_r_displace.w = b1_r_displace.w - v77;
    v77 = -v4->m_roll_stability_factor;
    fric_ud.y = v77 * b2_r.y;
    fric_ud.z = b2_r.z * v77;
    fric_ud.w = v77 * b2_r.w;
    v23 = pulse_sum_constraint_solver::create_pulse_sum_wheel(psys);
    v23->m_side = NULL;
    v23->m_fwd = NULL;
    v68 = (unsigned int)v23;
    v23 = (pulse_sum_wheel *)((char *)v23 + 16);
    v4->m_ps_suspension = (pulse_sum_normal *)v23;
    pulse_sum_normal::set(
      (pulse_sum_normal *)v23,
      v4->b1,
      (phys_vec3 *)((char *)&b1_suspension_dir + 4),
      v4->b2,
      (phys_vec3 *)((char *)&b1_r_displace + 4),
      (phys_vec3 *)((char *)&wheel_axis + 4),
      &v4->m_ps_cache_list[1],
      (phys_vec3 *)((char *)&fric_ud + 4));
    v24 = v4->m_ps_suspension;
    v24->m_pulse_sum_min = -10000000.0;
    v24->m_pulse_sum_max = 0.0;
    v25 = (float *)v4->m_ps_suspension;
    v26 = v4->m_ps_suspension;
    v77 = v4->m_suspension_stiffness_k * delta_t;
    *(double *)&ps_wheel = v77 * delta_t;
    v77 = delta_t * v4->m_suspension_damp_k;
    v77 = 1.0 / (*(double *)&ps_wheel + v77);
    v27 = pulse_sum_normal::get_pos(v26);
    v28 = v77;
    v77 = *(double *)&ps_wheel * v77;
    v25[27] = v27 * (-v77 / delta_t);
    v25[28] = 0.0;
    v25[29] = v28;
    v25[30] = v28 + v25[30];
    phys_multiply((phys_vec3 *)((char *)&b1_r + 4), &v4->b1->m_mat, &v4->m_b1_wheel_axis_loc);
    make_rotate((phys_mat44 *)&v57, (phys_vec3 *)((char *)&b2_r + 4), (phys_vec3 *)((char *)&wheel_axis + 4));
    phys_multiply((phys_vec3 *)&v59, (phys_mat44 *)&v57, (phys_vec3 *)((char *)&b1_r + 4));
    v29 = phys_transient_allocator::allocate(
            &psys->m_solver_memory_allocator,
            160,
            16,
            0,
            SOLVER_MEMORY_ALLOCATOR_ERROR_MSG);
    *(_DWORD *)(v68 + 176) = v29;
    v30 = v4->b2;
    v31 = v4->b1;
    v4->m_ps_side_fric = (pulse_sum_normal *)v29;
    pulse_sum_normal::set(
      (pulse_sum_normal *)v29,
      v31,
      (phys_vec3 *)((char *)&b1_suspension_dir + 4),
      v30,
      (phys_vec3 *)((char *)&b1_r_displace + 4),
      (phys_vec3 *)&v59,
      &v4->m_ps_cache_list[2],
      (phys_vec3 *)((char *)&fric_ud + 4));
    v32 = (float *)v4->m_ps_side_fric;
    v32[27] = 0.0;
    v32[28] = 0.0;
    v32[29] = 0.0;
    v33 = v4->m_ps_suspension;
    v69 = v60 * wheel_axis.w - v61 * wheel_axis.z;
    v70 = v61 * wheel_axis.y - wheel_axis.w * v59;
    *(float *)&ps_wheel = wheel_axis.z * v59 - v60 * wheel_axis.y;
    v74 = -v69;
    v75 = -v70;
    k_ = -*(float *)&ps_wheel;
    v34 = pulse_sum_normal::get_relative_velocity(v33, (phys_vec3 *)((char *)&b1_r + 4));
    v35 = v4->m_wheel_state;
    v77 = v34->y * v75 + v34->x * v74 + v34->z * k_;
    v4->m_wheel_vel = v77 / v4->m_wheel_radius;
    if ( !v35 && v4->m_acceleration_factor_k < 0.00009999999747378752
      || v35 == 1 && v4->m_braking_factor_k < 0.00009999999747378752 )
    {
      pulse_sum_normal::set_pulse_sum_limits_parent_ratio(v4->m_ps_side_fric, v4->m_side_fric_k, v4->m_ps_suspension);
      return;
    }
    v36 = v4->m_ps_side_fric;
    v37 = (pulse_sum_wheel *)v68;
    v36->m_pulse_sum_min = -10000000.0;
    v36->m_pulse_sum_max = 10000000.0;
    v38 = pulse_sum_constraint_solver::create_pulse_sum_wheel_fwd(psys, v37);
    v77 = -v4->m_pitch_stability_factor;
    v39 = v4->b2;
    b1_r.y = v77 * b2_r.y;
    v40 = v39;
    v41 = v4->b1;
    b1_r.z = b2_r.z * v77;
    v42 = v77 * b2_r.w;
    v4->m_ps_fwd_fric = v38;
    b1_r.w = v42;
    pulse_sum_normal::set(
      v38,
      v41,
      (phys_vec3 *)((char *)&b1_suspension_dir + 4),
      v40,
      (phys_vec3 *)((char *)&b1_r_displace + 4),
      (phys_vec3 *)&v74,
      &v4->m_ps_cache_list[3],
      (phys_vec3 *)((char *)&b1_r + 4));
    if ( SLOBYTE(v4->m_wheel_flags) < 0 )
    {
      v43 = (float *)v4->m_ps_fwd_fric;
      v43[27] = 0.0;
      v43[28] = 0.0;
      v43[29] = 0.0;
      v44 = v4->m_ps_fwd_fric;
      v44->m_pulse_sum_min = -10000000.0;
      v45 = 10000000.0;
LABEL_26:
      v55 = (pulse_sum_wheel *)v68;
      v44->m_pulse_sum_max = v45;
      pulse_sum_wheel::set_side_fwd_ratios(v55, v4->m_side_fric_k, v4->m_fwd_fric_k, v4->m_side_fric_max);
      v56 = pulse_sum_normal::get_relative_velocity_change_dir(v4->m_ps_fwd_fric, (phys_vec3 *)((char *)&b1_r + 4));
      v4->m_wheel_fwd = v56->y * v75 + v74 * v56->x + v56->z * k_;
      return;
    }
    if ( v4->m_wheel_state )
    {
      v54 = (float *)v4->m_ps_fwd_fric;
      v54[27] = 0.0;
      v54[28] = 0.0;
      v54[29] = 0.0;
      v44 = v4->m_ps_fwd_fric;
      desired_speed = v4->m_braking_factor_k * delta_t;
      v45 = desired_speed;
      v53 = -desired_speed;
    }
    else
    {
      desired_speed = v4->m_desired_speed_k * v4->m_turning_radius_ratio_max_speed;
      v77 = v4->m_wheel_radius;
      v46 = v77;
      v77 = v4->m_acceleration_factor_k * v4->m_turning_radius_ratio_accel;
      v47 = v46 * v46;
      v48 = v77 * delta_t;
      v77 = v47;
      v73 = v48 / v77;
      if ( v73 <= 0.000001 )
        v73 = 0.0000099999997;
      v49 = (float *)v4->m_ps_fwd_fric;
      v77 = 1.0 / v73;
      v50 = desired_speed;
      v49[27] = v4->m_wheel_radius * desired_speed;
      v49[28] = 0.0;
      v51 = v77;
      v49[29] = v77;
      v49[30] = v51 + v49[30];
      v52 = v50;
      v45 = 0.0;
      if ( v52 > 0.00009999999747378752 )
      {
        v44 = v4->m_ps_fwd_fric;
        v44->m_pulse_sum_min = 0.0;
        v45 = 10000000.0;
        goto LABEL_26;
      }
      v44 = v4->m_ps_fwd_fric;
      if ( v52 >= -0.00009999999747378752 )
      {
        v44->m_pulse_sum_min = -10000000.0;
        v45 = 10000000.0;
        goto LABEL_26;
      }
      v53 = -10000000.0;
    }
    v44->m_pulse_sum_min = v53;
    goto LABEL_26;
  }
}

