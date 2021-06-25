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
phys_calc_world_aabb
==============
*/
void __usercall phys_calc_world_aabb(int a1@<ebp>, phys_vec3 *local_center, phys_vec3 *local_half_aabb_dims, phys_mat44 *local_to_world_xform, phys_vec3 *aabb_min, phys_vec3 *aabb_max)
{
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm7_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  float v17; // xmm2_4
  float v18; // xmm7_4
  float v19; // xmm2_4
  float v20; // xmm6_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm5_4
  float v25; // xmm4_4
  float v26; // xmm3_4
  float v27; // xmm7_4
  float v28; // xmm5_4
  float v29; // xmm5_4
  float v30; // xmm6_4
  float v31; // xmm5_4
  int v32; // [esp-Ch] [ebp-7Ch]
  int v33; // [esp-8h] [ebp-78h]
  int v34; // [esp-4h] [ebp-74h]
  phys_mat44 world_to_local_xform; // [esp+0h] [ebp-70h]
  int v36; // [esp+48h] [ebp-28h]
  float v37; // [esp+4Ch] [ebp-24h]
  phys_vec3 half_aabb_dim; // [esp+50h] [ebp-20h]
  int v39; // [esp+64h] [ebp-Ch]
  int v40; // [esp+68h] [ebp-8h]
  int retaddr; // [esp+70h] [ebp+0h]

  v39 = a1;
  v40 = retaddr;
  phys_transpose((phys_mat44 *)&v32, local_to_world_xform);
  v6 = local_half_aabb_dims->y;
  v7 = local_half_aabb_dims->z;
  v36 = LODWORD(world_to_local_xform.y.z) & _mask__AbsFloat_;
  LODWORD(v37) = LODWORD(world_to_local_xform.y.w) & _mask__AbsFloat_;
  LODWORD(half_aabb_dim.z) = LODWORD(world_to_local_xform.x.z) & _mask__AbsFloat_;
  LODWORD(half_aabb_dim.w) = LODWORD(world_to_local_xform.x.w) & _mask__AbsFloat_;
  v8 = local_half_aabb_dims->x;
  LODWORD(world_to_local_xform.w.w) = v34 & _mask__AbsFloat_;
  v9 = v8 * COERCE_FLOAT(LODWORD(world_to_local_xform.x.y) & _mask__AbsFloat_);
  v10 = (float)((float)(v6 * COERCE_FLOAT(v33 & _mask__AbsFloat_)) + (float)(v8 * COERCE_FLOAT(v32 & _mask__AbsFloat_)))
      + (float)(v7 * COERCE_FLOAT(v34 & _mask__AbsFloat_));
  v11 = v6 * COERCE_FLOAT(LODWORD(world_to_local_xform.x.z) & _mask__AbsFloat_);
  v12 = (float)(v8 * COERCE_FLOAT(LODWORD(world_to_local_xform.y.y) & _mask__AbsFloat_))
      + (float)(v6 * COERCE_FLOAT(LODWORD(world_to_local_xform.y.z) & _mask__AbsFloat_));
  v13 = local_center->z;
  v14 = v7 * COERCE_FLOAT(LODWORD(world_to_local_xform.x.w) & _mask__AbsFloat_);
  v15 = v12 + (float)(v7 * COERCE_FLOAT(LODWORD(world_to_local_xform.y.w) & _mask__AbsFloat_));
  v16 = local_to_world_xform->x.y;
  v37 = v15;
  v17 = v11 + v9;
  v18 = local_to_world_xform->z.y * v13;
  v19 = v17 + v14;
  v20 = local_to_world_xform->z.x * v13;
  world_to_local_xform.w.w = local_to_world_xform->z.z * v13;
  v21 = local_center->y;
  half_aabb_dim.y = local_center->y * local_to_world_xform->y.x;
  half_aabb_dim.z = local_to_world_xform->y.y * v21;
  v22 = local_to_world_xform->y.z * v21;
  v23 = local_center->x;
  half_aabb_dim.w = v22;
  v24 = (float)((float)(local_to_world_xform->x.z * v23) + v22) + world_to_local_xform.w.w;
  v25 = local_to_world_xform->w.y + (float)((float)((float)(v16 * v23) + half_aabb_dim.z) + v18);
  v26 = local_to_world_xform->w.x + (float)((float)((float)(local_to_world_xform->x.x * v23) + half_aabb_dim.y) + v20);
  v27 = v24;
  v28 = local_to_world_xform->w.z;
  world_to_local_xform.w.z = v25 - v19;
  v29 = v28 + v27;
  aabb_min->x = v26 - v10;
  v30 = v29 - v37;
  v31 = v29 + v37;
  aabb_min->y = world_to_local_xform.w.z;
  aabb_min->z = v30;
  aabb_max->x = v26 + v10;
  aabb_max->y = v25 + v19;
  aabb_max->z = v31;
}

/*
==============
phys_are_potentially_colliding
==============
*/
char phys_are_potentially_colliding(phys_vec3 *aabb_min0, phys_vec3 *aabb_max0, phys_vec3 *aabb0_translation, phys_vec3 *aabb_min1, phys_vec3 *aabb_max1, float *hit_time)
{
  signed int v6; // esi
  int v7; // edi
  phys_vec3 *v8; // ebx
  float *v9; // edi
  float dif_max1_min0; // [esp+10h] [ebp-10h]
  float dif_min1_max0; // [esp+14h] [ebp-Ch]
  float tmax; // [esp+18h] [ebp-8h]
  float tmin; // [esp+1Ch] [ebp-4h]

  v6 = 0;
  tmin = 0.0;
  v7 = (char *)aabb_max0 - (char *)aabb0_translation;
  tmax = FLOAT_1_0;
  v8 = aabb0_translation;
  while ( 1 )
  {
    if ( (v6 < 0 || v6 >= 3)
      && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h", 36, "i >= 0 && i < 3", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( (v6 < 0 || v6 >= 3)
      && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h", 36, "i >= 0 && i < 3", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v9 = (float *)((char *)&v8->x + v7);
    dif_min1_max0 = *(float *)((char *)v9 + (char *)aabb_min1 - (char *)aabb_max0) - *v9;
    if ( (v6 < 0 || v6 >= 3)
      && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h", 36, "i >= 0 && i < 3", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( (v6 < 0 || v6 >= 3)
      && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h", 36, "i >= 0 && i < 3", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    dif_max1_min0 = *(float *)((char *)v9 + (char *)aabb_max1 - (char *)aabb_max0)
                  - *(float *)((char *)v9 + (char *)aabb_min0 - (char *)aabb_max0);
    if ( (v6 < 0 || v6 >= 3)
      && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h", 36, "i >= 0 && i < 3", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v8->x <= 0.0000099999997 )
    {
      if ( (v6 < 0 || v6 >= 3)
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h",
             36,
             "i >= 0 && i < 3",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      if ( v8->x >= -0.0000099999997 )
      {
        if ( dif_min1_max0 > 0.0 || dif_max1_min0 < 0.0 )
          return 0;
      }
      else
      {
        if ( (v6 < 0 || v6 >= 3)
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h",
               36,
               "i >= 0 && i < 3",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        if ( (float)(dif_min1_max0 / v8->x) <= tmax )
          tmax = dif_min1_max0 / v8->x;
        if ( (v6 < 0 || v6 >= 3)
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h",
               36,
               "i >= 0 && i < 3",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        if ( tmin <= (float)(dif_max1_min0 / v8->x) )
          tmin = dif_max1_min0 / v8->x;
      }
    }
    else
    {
      if ( (v6 < 0 || v6 >= 3)
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h",
             36,
             "i >= 0 && i < 3",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      if ( tmin <= (float)(dif_min1_max0 / v8->x) )
        tmin = dif_min1_max0 / v8->x;
      if ( (v6 < 0 || v6 >= 3)
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h",
             36,
             "i >= 0 && i < 3",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      if ( (float)(dif_max1_min0 / v8->x) <= tmax )
        tmax = dif_max1_min0 / v8->x;
    }
    if ( tmin > tmax )
      return 0;
    ++v6;
    v8 = (phys_vec3 *)((char *)v8 + 4);
    if ( v6 >= 3 )
      break;
    v7 = (char *)aabb_max0 - (char *)aabb0_translation;
  }
  if ( (tmin < 0.0 || tmin > 1.0)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_bounding_volume.h",
         172,
         "tmin >= 0.0f && tmin <= 1.0f",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  *hit_time = tmin;
  return 1;
}

/*
==============
phys_calc_local_aabb
==============
*/
void phys_calc_local_aabb(phys_vec3 *aabb_min, phys_vec3 *aabb_max, phys_mat44 *local_to_world_xform, phys_vec3 *local_aabb_min, phys_vec3 *local_aabb_max)
{
  float v5; // ST08_4
  float v6; // ST10_4
  float v7; // ST0C_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // ST14_4
  float v12; // ST38_4
  float v13; // ST30_4
  float v14; // xmm2_4
  float v15; // ST34_4
  float v16; // ST28_4
  float v17; // ST40_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // ST48_4
  float v21; // xmm7_4
  float v22; // xmm1_4
  float v23; // xmm6_4
  float v24; // xmm4_4
  float v25; // xmm5_4

  v5 = aabb_min->y;
  v6 = aabb_min->z;
  v7 = aabb_max->y;
  v8 = local_to_world_xform->z.x;
  v9 = local_to_world_xform->y.y;
  v10 = local_to_world_xform->x.y;
  v11 = aabb_max->z;
  v12 = (float)(v11 - v6) * 0.5;
  v13 = (float)(aabb_max->x - aabb_min->x) * 0.5;
  v14 = local_to_world_xform->y.x;
  v15 = (float)(v7 - v5) * 0.5;
  v16 = local_to_world_xform->z.y;
  v17 = (float)((float)(COERCE_FLOAT(LODWORD(v10) & _mask__AbsFloat_) * v15)
              + (float)(COERCE_FLOAT(LODWORD(local_to_world_xform->x.x) & _mask__AbsFloat_) * v13))
      + (float)(COERCE_FLOAT(LODWORD(local_to_world_xform->x.z) & _mask__AbsFloat_) * v12);
  v18 = (float)(COERCE_FLOAT(LODWORD(local_to_world_xform->y.z) & _mask__AbsFloat_) * v12)
      + (float)((float)(COERCE_FLOAT(LODWORD(v9) & _mask__AbsFloat_) * v15)
              + (float)(COERCE_FLOAT(LODWORD(v14) & _mask__AbsFloat_) * v13));
  v19 = (float)((float)(aabb_min->x + aabb_max->x) * 0.5) - local_to_world_xform->w.x;
  v20 = (float)((float)(COERCE_FLOAT(LODWORD(v16) & _mask__AbsFloat_) * v15)
              + (float)(COERCE_FLOAT(LODWORD(v8) & _mask__AbsFloat_) * v13))
      + (float)(COERCE_FLOAT(LODWORD(local_to_world_xform->z.z) & _mask__AbsFloat_) * v12);
  v21 = (float)((float)(v5 + v7) * 0.5) - local_to_world_xform->w.y;
  v22 = (float)((float)(v6 + v11) * 0.5) - local_to_world_xform->w.z;
  v23 = (float)((float)(v10 * v21) + (float)(local_to_world_xform->x.x * v19))
      + (float)(local_to_world_xform->x.z * v22);
  v24 = (float)((float)(v8 * v19) + (float)(v16 * v21)) + (float)(local_to_world_xform->z.z * v22);
  v25 = (float)((float)(v9 * v21) + (float)(v14 * v19)) + (float)(local_to_world_xform->y.z * v22);
  local_aabb_min->x = v23 - v17;
  local_aabb_min->z = v24 - v20;
  local_aabb_min->y = v25 - v18;
  local_aabb_max->x = v23 + v17;
  local_aabb_max->y = v25 + v18;
  local_aabb_max->z = v24 + v20;
}

/*
==============
comp_trace_volume
==============
*/
void __usercall comp_trace_volume(int a1@<ebp>, phys_vec3 *aabb1_min, phys_vec3 *aabb1_max, phys_vec3 *aabb2_min, phys_vec3 *aabb2_max, phys_vec3 *p1, phys_vec3 *p2, phys_vec3 *half_dims)
{
  phys_vec3 *v8; // eax
  phys_vec3 *v9; // eax
  phys_vec3 *v10; // eax
  phys_vec3 *v11; // eax
  phys_vec3 *v12; // eax
  float v13; // [esp-Ch] [ebp-4Ch]
  float v14; // [esp-8h] [ebp-48h]
  float v15; // [esp-4h] [ebp-44h]
  phys_vec3 cmin; // [esp+0h] [ebp-40h]
  phys_vec3 cmax; // [esp+10h] [ebp-30h]
  phys_vec3 total_aabb_max; // [esp+20h] [ebp-20h]
  int v19; // [esp+34h] [ebp-Ch]
  int v20; // [esp+38h] [ebp-8h]
  int retaddr; // [esp+40h] [ebp+0h]

  v19 = a1;
  v20 = retaddr;
  cmin.y = aabb1_max->x - aabb1_min->x;
  cmin.z = aabb1_max->y - aabb1_min->y;
  cmin.w = aabb1_max->z - aabb1_min->z;
  v13 = aabb2_max->x - aabb2_min->x;
  v14 = aabb2_max->y - aabb2_min->y;
  v15 = aabb2_max->z - aabb2_min->z;
  v8 = phys_max((phys_vec3 *)((char *)&cmax + 4), (phys_vec3 *)((char *)&cmin + 4), (phys_vec3 *)&v13);
  total_aabb_max.y = v8->x * 0.5;
  total_aabb_max.z = v8->y * 0.5;
  total_aabb_max.w = 0.5 * v8->z;
  half_dims->x = total_aabb_max.y;
  half_dims->y = total_aabb_max.z;
  half_dims->z = total_aabb_max.w;
  phys_min((phys_vec3 *)((char *)&cmin + 4), aabb1_min, aabb2_min);
  phys_max((phys_vec3 *)((char *)&cmax + 4), aabb1_max, aabb2_max);
  v13 = cmin.y + total_aabb_max.y;
  v14 = cmin.z + total_aabb_max.z;
  v15 = cmin.w + total_aabb_max.w;
  cmin.y = cmax.y - total_aabb_max.y;
  cmin.z = cmax.z - total_aabb_max.z;
  cmin.w = cmax.w - total_aabb_max.w;
  total_aabb_max.y = aabb1_min->x + aabb1_max->x;
  total_aabb_max.z = aabb1_min->y + aabb1_max->y;
  total_aabb_max.w = aabb1_min->z + aabb1_max->z;
  cmax.y = total_aabb_max.y * 0.5;
  cmax.z = total_aabb_max.z * 0.5;
  cmax.w = 0.5 * total_aabb_max.w;
  p1->x = cmax.y;
  p1->y = cmax.z;
  p1->z = cmax.w;
  v9 = phys_min((phys_vec3 *)((char *)&cmax + 4), p1, (phys_vec3 *)((char *)&cmin + 4));
  p1->x = v9->x;
  p1->y = v9->y;
  p1->z = v9->z;
  v10 = phys_max((phys_vec3 *)((char *)&cmax + 4), p1, (phys_vec3 *)&v13);
  p1->x = v10->x;
  p1->y = v10->y;
  p1->z = v10->z;
  cmax.y = aabb2_min->x + aabb2_max->x;
  cmax.z = aabb2_min->y + aabb2_max->y;
  cmax.w = aabb2_min->z + aabb2_max->z;
  total_aabb_max.y = cmax.y * 0.5;
  total_aabb_max.z = cmax.z * 0.5;
  total_aabb_max.w = 0.5 * cmax.w;
  p2->x = total_aabb_max.y;
  p2->y = total_aabb_max.z;
  p2->z = total_aabb_max.w;
  v11 = phys_min((phys_vec3 *)((char *)&cmax + 4), p2, (phys_vec3 *)((char *)&cmin + 4));
  p2->x = v11->x;
  p2->y = v11->y;
  p2->z = v11->z;
  v12 = phys_max((phys_vec3 *)((char *)&cmin + 4), p2, (phys_vec3 *)&v13);
  p2->x = v12->x;
  p2->y = v12->y;
  p2->z = v12->z;
}

