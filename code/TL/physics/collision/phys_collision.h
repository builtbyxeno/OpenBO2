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
setup_gjk_input_from_pcp
==============
*/
void setup_gjk_input_from_pcp(phys_gjk_input *pgi, phys_collision_pair *pcp)
{
  phys_collision_pair *v2; // edi
  broad_phase_info *v3; // eax
  broad_phase_info *v4; // ecx
  phys_gjk_input *v5; // esi
  phys_gjk_geom *v6; // ebx
  phys_mat44 *v7; // ST24_4
  float v8; // ST20_4
  phys_gjk_cache_info *v9; // edi
  float v10; // ST1C_4
  phys_gjk_input *pgia; // [esp+20h] [ebp+8h]
  float pcpa; // [esp+24h] [ebp+Ch]
  phys_collision_pair *pcpb; // [esp+24h] [ebp+Ch]

  v2 = pcp;
  if ( pcp->m_hit_time < 0.0 || pcp->m_hit_time > 1.0 )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_collision.h",
           11,
           "pcp->m_hit_time >= 0.0f && pcp->m_hit_time <= 1.0f",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
  v3 = pcp->m_bpi1;
  v4 = pcp->m_bpi2;
  pcpa = pcp->m_hit_time;
  v5 = pgi;
  pgi->m_cg1_translation.x = v3->m_trace_translation.x;
  pgi->m_cg1_translation.y = v3->m_trace_translation.y;
  pgi->m_cg1_translation.z = v3->m_trace_translation.z;
  pgi->m_cg2_translation.x = v4->m_trace_translation.x;
  pgi->m_cg2_translation.y = v4->m_trace_translation.y;
  pgi->m_cg2_translation.z = v4->m_trace_translation.z;
  pgi->m_start_time = pcpa;
  pgi->m_end_time = 1.0;
  v6 = v4->m_gjk_geom;
  pgia = (phys_gjk_input *)v3->m_cg_to_world_xform;
  v7 = v4->m_cg_to_world_xform;
  pcpb = (phys_collision_pair *)v3->m_gjk_geom;
  ((void (__thiscall *)(phys_collision_pair *))pcpb->m_next_link[1].m_next_link)(pcpb);
  v8 = 1.0 + 0.3400000035762787;
  v6->vfptr->get_geom_radius(v6);
  v9 = v2->m_gjk_ci;
  v10 = 1.0 + 0.3400000035762787 + 0.3400000035762787;
  v5->cg1_radius = v8;
  v5->gjk_ci = v9;
  v5->gjk_cg2 = v6;
  v5->cg2_radius = v10;
  v5->gjk_cg1 = (phys_gjk_geom *)pcpb;
  v5->cg1_to_world_xform = (phys_mat44 *)pgia;
  v5->cg2_to_world_xform = v7;
}

/*
==============
phys_collide_do_gjk_collide_and_contact_manifold
==============
*/
void __usercall phys_collide_do_gjk_collide_and_contact_manifold(float a1@<ebp>, phys_collision_pair *pcp, phys_gjk_info *gjk_info, phys_contact_manifold_process *cman_process)
{
  broad_phase_info *v4; // eax
  broad_phase_info *v5; // esi
  int v6; // [esp-Ch] [ebp-5Ch]
  phys_gjk_input pgi; // [esp+0h] [ebp-50h]
  void *retaddr; // [esp+50h] [ebp+0h]

  pgi.m_sep_thresh = a1;
  *(_DWORD *)&pgi.m_intersection_test_only = retaddr;
  if ( (pcp->m_hit_time < 0.0 || pcp->m_hit_time > 1.0)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_collision.h",
         29,
         "pcp->m_hit_time >= 0.0f && pcp->m_hit_time <= 1.0f",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  setup_gjk_input_from_pcp((phys_gjk_input *)&v6, pcp);
  *(float *)&pgi.gjk_ci = 1.02;
  LOWORD(pgi.cg1_radius) = 256;
  if ( phys_gjk_info::phys_collide_do_gjk_collide(gjk_info, (int)&pgi.m_sep_thresh, (phys_gjk_input *)&v6) )
    phys_contact_manifold_process::process(cman_process, pcp, gjk_info);
  if ( phys_gjk_info::get_flag(gjk_info, 64) )
  {
    v4 = pcp->m_bpi1;
    if ( !(v4->m_flags & 4) )
      v4->m_rb->m_flags |= 0x200u;
    v5 = pcp->m_bpi2;
    if ( !(v5->m_flags & 4) )
      v5->m_rb->m_flags |= 0x200u;
  }
}

