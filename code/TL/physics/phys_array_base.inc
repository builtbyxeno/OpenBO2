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
phys_static_array<phys_vec3 *,6144>::remove
==============
*/
void __thiscall phys_static_array<phys_vec3 *,6144>::remove(phys_static_array<phys_vec3 *,6144> *this, phys_vec3 **data)
{
  phys_static_array<phys_vec3 *,6144> *v2; // esi
  phys_vec3 **v3; // eax

  v2 = this;
  v3 = this->m_slot_array;
  if ( (((_BYTE)data - (_BYTE)v3) & 3 || data < v3 || data >= &v3[this->m_alloc_count])
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_array_base.inc",
         65,
         "is_member(data)",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( v2->m_alloc_count <= 0
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_array_base.inc",
         163,
         "m_alloc_count > 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  *data = v2->m_slot_array[v2->m_alloc_count-- - 1];
}

/*
==============
phys_static_array<phys_convex_hull::ch_triangle,256>::remove_slow
==============
*/
void __thiscall phys_static_array<phys_convex_hull::ch_triangle,256>::remove_slow(phys_static_array<phys_convex_hull::ch_triangle,256> *this, phys_convex_hull::ch_triangle *data)
{
  phys_static_array<phys_convex_hull::ch_triangle,256> *v2; // edi
  phys_convex_hull::ch_triangle *v3; // eax
  int v4; // eax
  phys_vec3 *v5; // ecx
  phys_vec3 *v6; // edx
  double v7; // st7
  phys_vec3 *v8; // eax

  v2 = this;
  v3 = this->m_slot_array;
  if ( (((_BYTE)data - (_BYTE)v3) & 0x1F || data < v3 || data >= &v3[this->m_alloc_count])
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_array_base.inc",
         73,
         "is_member(data)",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v4 = (int)&v2->m_slot_array[--v2->m_alloc_count];
  v5 = *(phys_vec3 **)(v4 + 16);
  data->m_normal.x = *(float *)v4;
  data->m_verts[0] = v5;
  v6 = *(phys_vec3 **)(v4 + 20);
  data->m_normal.y = *(float *)(v4 + 4);
  data->m_verts[1] = v6;
  v7 = *(float *)(v4 + 8);
  v8 = *(phys_vec3 **)(v4 + 24);
  data->m_normal.z = v7;
  data->m_verts[2] = v8;
}

