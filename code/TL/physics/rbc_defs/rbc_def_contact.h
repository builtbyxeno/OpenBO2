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
contact_point_info::check_surface_properties
==============
*/
void __thiscall contact_point_info::check_surface_properties(contact_point_info *this)
{
  contact_point_info *v1; // esi
  float v2; // xmm0_4

  v1 = this;
  if ( this->m_fric_coef < 0.0
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\rbc_defs\\rbc_def_contact.h",
         137,
         "m_fric_coef >= 0.0f",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v2 = v1->m_bounce_coef;
  if ( (v2 > 1.0 || v2 < 0.0)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\rbc_defs\\rbc_def_contact.h",
         138,
         "m_bounce_coef <= 1.0f && m_bounce_coef >= 0.0f",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( v1->m_max_restitution_vel < 0.0
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\rbc_defs\\rbc_def_contact.h",
         139,
         "m_max_restitution_vel >= 0.0f",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
}

/*
==============
rigid_body_pair_key::rigid_body_pair_key
==============
*/
void __thiscall rigid_body_pair_key::rigid_body_pair_key(rigid_body_pair_key *this, rigid_body *const b1, rigid_body *const b2)
{
  rigid_body_pair_key *v3; // esi

  v3 = this;
  if ( b1 == b2
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\rbc_defs\\rbc_def_contact.h",
         232,
         "b1 != b2",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !b1
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\rbc_defs\\rbc_def_contact.h", 233, "b1", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !b2 )
  {
    if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\rbc_defs\\rbc_def_contact.h", 234, "b2", (const char *)&pBlock) )
      __debugbreak();
    goto LABEL_10;
  }
  if ( b1 >= b2 )
  {
LABEL_10:
    v3->m_b2 = b1;
    v3->m_b1 = b2;
    return;
  }
  v3->m_b1 = b1;
  v3->m_b2 = b2;
}

/*
==============
rigid_body_constraint_contact::update_smallest_lambda
==============
*/
void __thiscall rigid_body_constraint_contact::update_smallest_lambda(rigid_body_constraint_contact *this)
{
  rigid_body_constraint_contact *v1; // esi
  contact_point_info *i; // ecx
  rigid_body *v3; // edx
  double v4; // st7
  float v5; // ST14_4

  v1 = this;
  if ( this->b1->m_flags & 0x10
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\rbc_defs\\rbc_def_contact.h",
         414,
         "b1->is_environment_rigid_body() == false",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( v1->b2->m_flags & 0x10 )
  {
    for ( i = v1->m_list_contact_point_info_buffer_1.m_first; i; i = i->m_next_link )
    {
      v3 = v1->b1;
      if ( i->m_translation_lambda <= (double)v1->b1->m_smallest_lambda )
        v4 = i->m_translation_lambda;
      else
        v4 = v3->m_smallest_lambda;
      v5 = v4;
      v3->m_smallest_lambda = v5;
    }
  }
}

/*
==============
contact_point_info::create_cpi
==============
*/
contact_point_info *contact_point_info::create_cpi(const int point_pair_count, const bool no_error, phys_transient_allocator *allocator)
{
  unsigned int v3; // edi
  contact_point_info *result; // eax
  contact_point_info *v5; // esi

  if ( point_pair_count <= 0
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\rbc_defs\\rbc_def_contact.h",
         159,
         "point_pair_count > 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v3 = (32 * point_pair_count + 95) & 0xFFFFFFF0;
  result = (contact_point_info *)phys_transient_allocator::mt_allocate(
                                   allocator,
                                   v3 + ((12 * point_pair_count + 15) & 0xFFFFFFF0),
                                   16,
                                   1,
                                   "contact_point_info buffer overflow");
  v5 = result;
  if ( result )
  {
    result->m_fric_coef = -1.0;
    result->m_bounce_coef = -1.0;
    result->m_max_restitution_vel = -1.0;
    result->m_list_b1_r_loc = &result[1].m_normal;
    result->m_list_b2_r_loc = &result[1].m_normal + point_pair_count;
    result->m_list_pulse_sum_cache_info = (contact_point_info::pulse_sum_cache_info *)((char *)result + v3);
    result->m_point_pair_count = point_pair_count;
    result->m_flags = 0;
    result->m_rb2_entity = (const void *)-1;
  }
  else if ( !no_error )
  {
    if ( (pai_create_cpi.m_hits_total_count < dword_10E5920 || !dword_10E5920) && dword_10E591C < dword_10E5924 )
    {
      if ( byte_10E5928 )
      {
        PHYS_WARNING(
          "c:\\t6\\code\\tl\\physics\\include\\rbc_defs\\rbc_def_contact.h",
          173,
          "cpi || no_error",
          "contact_point_info buffer overflow");
      }
      else if ( _tlAssert(
                  "c:\\t6\\code\\tl\\physics\\include\\rbc_defs\\rbc_def_contact.h",
                  173,
                  "cpi || no_error",
                  "contact_point_info buffer overflow") )
      {
        __debugbreak();
      }
    }
    _InterlockedExchangeAdd(&pai_create_cpi.m_hits_total_count, 1u);
    _InterlockedExchangeAdd(&dword_10E591C, 1u);
    result = v5;
  }
  return result;
}

/*
==============
contact_point_info::set_closest_cached_psc
==============
*/
void __usercall contact_point_info::set_closest_cached_psc(int a1@<ebp>, contact_point_info *cached_cpi, phys_vec3 *normal, phys_vec3 *b1_r_loc, phys_vec3 *b2_r_loc, contact_point_info::pulse_sum_cache_info *psc)
{
  contact_point_info *v6; // eax
  phys_vec3 *v7; // edi
  float *v8; // edx
  float v9; // ST10_4
  float v10; // ST14_4
  float *v11; // ecx
  double v12; // st7
  int v13; // eax
  float v14; // ST18_4
  float v15; // ST44_4
  double v16; // st7
  float v17; // ST30_4
  float v18; // ST34_4
  float v19; // ST38_4
  float v20; // ST20_4
  float v21; // ST24_4
  float v22; // ST28_4
  double v23; // st6
  float v24; // ST30_4
  float v25; // ST34_4
  float v26; // ST38_4
  float v27; // ST20_4
  float v28; // ST24_4
  float v29; // ST28_4
  double v30; // st6
  float v31; // ST30_4
  float v32; // ST34_4
  float v33; // ST38_4
  float v34; // ST20_4
  float v35; // ST24_4
  float v36; // ST28_4
  double v37; // st6
  float v38; // ST30_4
  float v39; // ST34_4
  float v40; // ST38_4
  float v41; // ST20_4
  float v42; // ST24_4
  float v43; // ST28_4
  double v44; // st6
  float *v45; // eax
  int v46; // ecx
  float v47; // ST30_4
  float v48; // ST34_4
  float v49; // ST38_4
  float v50; // ST20_4
  float v51; // ST24_4
  float v52; // ST28_4
  float v53; // ST4C_4
  double v54; // st6
  float v55; // ST4C_4
  int v56; // [esp-1Ch] [ebp-2Ch]
  unsigned int v57; // [esp-18h] [ebp-28h]
  int v58; // [esp-18h] [ebp-28h]
  int v59; // [esp-14h] [ebp-24h]
  int i; // [esp-14h] [ebp-24h]
  int v61; // [esp-10h] [ebp-20h]
  contact_point_info::pulse_sum_cache_info *v62; // [esp-Ch] [ebp-1Ch]
  int v63; // [esp-8h] [ebp-18h]
  float *v64; // [esp-8h] [ebp-18h]
  float v65; // [esp-4h] [ebp-14h]
  contact_point_info::pulse_sum_cache_info *closest_psc; // [esp+0h] [ebp-10h]
  int v67; // [esp+4h] [ebp-Ch]
  int v68; // [esp+8h] [ebp-8h]
  int retaddr; // [esp+10h] [ebp+0h]

  v67 = a1;
  v68 = retaddr;
  v6 = cached_cpi;
  *(float *)&closest_psc = 10000000.0;
  v62 = NULL;
  if ( !cached_cpi )
    goto LABEL_30;
  v7 = b1_r_loc;
  while ( 1 )
  {
    v8 = &v6->m_list_b2_r_loc->x;
    v59 = 0;
    v9 = normal->x - v6->m_normal.x;
    v10 = normal->y - v6->m_normal.y;
    v11 = &v6->m_list_b1_r_loc->x;
    v12 = normal->z - v6->m_normal.z;
    v13 = cached_cpi->m_point_pair_count;
    v61 = v13;
    v14 = v12;
    v15 = v9 * v9 + v10 * v10 + v14 * v14;
    v16 = v15;
    if ( v13 >= 4 )
    {
      v57 = ((unsigned int)(v13 - 4) >> 2) + 1;
      v63 = 0;
      v59 = 4 * v57;
      do
      {
        v17 = *v11 - v7->x;
        v18 = v11[1] - v7->y;
        v19 = v11[2] - v7->z;
        v20 = *v8 - b2_r_loc->x;
        v21 = v8[1] - b2_r_loc->y;
        v22 = v8[2] - b2_r_loc->z;
        v65 = v19 * v19 + v17 * v17 + v18 * v18;
        v23 = v65 + v16;
        v65 = v22 * v22 + v20 * v20 + v21 * v21;
        v65 = v23 + v65;
        if ( *(float *)&closest_psc > (double)v65 )
        {
          *(float *)&closest_psc = v65;
          v7 = b1_r_loc;
          v62 = &cached_cpi->m_list_pulse_sum_cache_info[v63];
        }
        v24 = v11[4] - v7->x;
        v25 = v11[5] - v7->y;
        v26 = v11[6] - v7->z;
        v27 = v8[4] - b2_r_loc->x;
        v28 = v8[5] - b2_r_loc->y;
        v29 = v8[6] - b2_r_loc->z;
        v65 = v26 * v26 + v24 * v24 + v25 * v25;
        v30 = v65 + v16;
        v65 = v29 * v29 + v27 * v27 + v28 * v28;
        v65 = v30 + v65;
        if ( *(float *)&closest_psc > (double)v65 )
        {
          *(float *)&closest_psc = v65;
          v7 = b1_r_loc;
          v62 = &cached_cpi->m_list_pulse_sum_cache_info[v63 + 1];
        }
        v31 = v11[8] - v7->x;
        v32 = v11[9] - v7->y;
        v33 = v11[10] - v7->z;
        v34 = v8[8] - b2_r_loc->x;
        v35 = v8[9] - b2_r_loc->y;
        v36 = v8[10] - b2_r_loc->z;
        v65 = v33 * v33 + v31 * v31 + v32 * v32;
        v37 = v65 + v16;
        v65 = v36 * v36 + v34 * v34 + v35 * v35;
        v65 = v37 + v65;
        if ( *(float *)&closest_psc > (double)v65 )
        {
          *(float *)&closest_psc = v65;
          v7 = b1_r_loc;
          v62 = &cached_cpi->m_list_pulse_sum_cache_info[v63 + 2];
        }
        v38 = v11[12] - v7->x;
        v39 = v11[13] - v7->y;
        v40 = v11[14] - v7->z;
        v41 = v8[12] - b2_r_loc->x;
        v42 = v8[13] - b2_r_loc->y;
        v43 = v8[14] - b2_r_loc->z;
        v65 = v40 * v40 + v38 * v38 + v39 * v39;
        v44 = v65 + v16;
        v65 = v43 * v43 + v41 * v41 + v42 * v42;
        v65 = v44 + v65;
        if ( *(float *)&closest_psc > (double)v65 )
        {
          *(float *)&closest_psc = v65;
          v7 = b1_r_loc;
          v62 = &cached_cpi->m_list_pulse_sum_cache_info[v63 + 3];
        }
        v63 += 4;
        v11 += 16;
        v8 += 16;
        --v57;
      }
      while ( v57 );
    }
    if ( v59 >= v13 )
    {
      v7 = b1_r_loc;
    }
    else
    {
      v58 = v59;
      v56 = (char *)v11 - (char *)v8 - 8;
      v64 = v11 + 2;
      v45 = v8 + 2;
      v46 = v61 - v59;
      v7 = b1_r_loc;
      for ( i = (int)(v8 + 2); ; v45 = (float *)i )
      {
        v47 = *(float *)((char *)v45 + v56) - b1_r_loc->x;
        v48 = *(v64 - 1) - b1_r_loc->y;
        v49 = *v64 - b1_r_loc->z;
        v50 = *(v45 - 2) - b2_r_loc->x;
        v51 = *(v45 - 1) - b2_r_loc->y;
        v52 = *v45 - b2_r_loc->z;
        v53 = v49 * v49 + v47 * v47 + v48 * v48;
        v54 = v53 + v16;
        v55 = v52 * v52 + v50 * v50 + v51 * v51;
        v65 = v54 + v55;
        if ( *(float *)&closest_psc > (double)v65 )
        {
          *(float *)&closest_psc = v65;
          v62 = &cached_cpi->m_list_pulse_sum_cache_info[v58];
        }
        ++v58;
        v64 += 4;
        i += 16;
        if ( !--v46 )
          break;
      }
    }
    cached_cpi = cached_cpi->m_next_link;
    if ( !cached_cpi )
      break;
    v6 = cached_cpi;
  }
  if ( v62 )
  {
    psc->m_ps_cache_list[0].m_pulse_sum = v62->m_ps_cache_list[0].m_pulse_sum;
    psc->m_ps_cache_list[1].m_pulse_sum = v62->m_ps_cache_list[1].m_pulse_sum;
    psc->m_ps_cache_list[2].m_pulse_sum = v62->m_ps_cache_list[2].m_pulse_sum;
  }
  else
  {
LABEL_30:
    if ( psc )
    {
      psc->m_ps_cache_list[0].m_pulse_sum = 0.0;
      psc->m_ps_cache_list[1].m_pulse_sum = 0.0;
      psc->m_ps_cache_list[2].m_pulse_sum = 0.0;
    }
  }
}

