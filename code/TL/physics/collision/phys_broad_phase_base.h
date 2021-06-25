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
broad_phase_info::set_bpi_env
==============
*/
void __thiscall broad_phase_info::set_bpi_env(broad_phase_info *this, phys_auto_activate_callback *auto_activate_callback)
{
  broad_phase_info *v2; // esi

  v2 = this;
  if ( !(this->m_flags & 1)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_base.h",
         165,
         "is_bpi()",
         "call broad_phase_info::set first.") )
  {
    __debugbreak();
  }
  if ( v2->m_sap_node
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\collision\\phys_broad_phase_base.h",
         166,
         "m_sap_node == NULL",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v2->m_sap_node = auto_activate_callback;
  v2->m_flags = 4;
  v2->m_flags = auto_activate_callback != NULL ? 132 : 4;
}

/*
==============
broad_phase_base::get_aabb
==============
*/
void __userpurge broad_phase_base::get_aabb(broad_phase_base *this@<ecx>, int a2@<ebp>, phys_vec3 *aabb)
{
  broad_phase_base *v3; // esi
  phys_vec3 *v4; // eax
  phys_vec3 *v5; // eax
  int v6; // [esp-20h] [ebp-2Ch]
  float v7; // [esp-10h] [ebp-1Ch]
  float v8; // [esp-Ch] [ebp-18h]
  float v9; // [esp-8h] [ebp-14h]
  int v10; // [esp+0h] [ebp-Ch]
  int v11; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v10 = a2;
  v11 = retaddr;
  v3 = this;
  v7 = this->m_trace_aabb_min_whace.x + this->m_trace_translation.x;
  v8 = this->m_trace_aabb_min_whace.y + this->m_trace_translation.y;
  v9 = this->m_trace_aabb_min_whace.z + this->m_trace_translation.z;
  v4 = phys_min((phys_vec3 *)&v6, &this->m_trace_aabb_min_whace, (phys_vec3 *)&v7);
  aabb->x = v4->x;
  aabb->y = v4->y;
  aabb->z = v4->z;
  v7 = v3->m_trace_aabb_max_whace.x + v3->m_trace_translation.x;
  v8 = v3->m_trace_aabb_max_whace.y + v3->m_trace_translation.y;
  v9 = v3->m_trace_aabb_max_whace.z + v3->m_trace_translation.z;
  v5 = phys_max((phys_vec3 *)&v6, &v3->m_trace_aabb_max_whace, (phys_vec3 *)&v7);
  aabb[1].x = v5->x;
  aabb[1].y = v5->y;
  aabb[1].z = v5->z;
}

