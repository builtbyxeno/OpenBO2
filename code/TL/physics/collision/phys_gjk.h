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
phys_gjk_geom::set_simplex
==============
*/
void phys_gjk_geom::set_simplex(phys_vec3 *simplex_inds, const int w_set, phys_vec3 *normal, cached_simplex_info *cache_info)
{
  cached_simplex_info *v5; // eax

  v5 = cache_info;
  if ( w_set & 1 )
  {
    v5 = (cached_simplex_info *)((char *)cache_info + 16);
    v5[-1].m_indices[2].x = simplex_inds->x;
    v5[-1].m_indices[2].y = simplex_inds->y;
    v5[-1].m_indices[2].z = simplex_inds->z;
  }
  if ( w_set & 2 )
  {
    v5 = (cached_simplex_info *)((char *)v5 + 16);
    v5[-1].m_indices[2].x = simplex_inds[1].x;
    v5[-1].m_indices[2].y = simplex_inds[1].y;
    v5[-1].m_indices[2].z = simplex_inds[1].z;
  }
  if ( w_set & 4 )
  {
    v5 = (cached_simplex_info *)((char *)v5 + 16);
    v5[-1].m_indices[2].x = simplex_inds[2].x;
    v5[-1].m_indices[2].y = simplex_inds[2].y;
    v5[-1].m_indices[2].z = simplex_inds[2].z;
  }
  if ( w_set & 8 )
  {
    v5->m_indices[0].x = simplex_inds[3].x;
    v5->m_indices[0].y = simplex_inds[3].y;
    v5->m_indices[0].z = simplex_inds[3].z;
  }
}

/*
==============
phys_gjk_geom::get_geom_radius
==============
*/
double phys_gjk_geom::get_geom_radius()
{
  return 0.0;
}

/*
==============
phys_gjk_geom::ray_cast
==============
*/
bool phys_gjk_geom::ray_cast(phys_vec3 *ray_pos, phys_vec3 *ray_dir, const float t_input, float *t_output, phys_vec3 *hitn)
{
  return 0;
}

/*
==============
phys_gjk_geom::support_only
==============
*/
phys_vec3 *__userpurge phys_gjk_geom::support_only@<eax>(phys_gjk_geom *this@<ecx>, int a2@<ebp>, int a3@<esi>, phys_vec3 *result, phys_mat44 *xform, phys_vec3 *v)
{
  phys_vec3 *v6; // eax
  int v7; // ST18_4
  phys_mat44 *v8; // esi
  double v9; // st7
  void (__thiscall *v10)(phys_gjk_geom *, phys_vec3 *, phys_vec3 *, phys_vec3 *); // eax
  phys_vec3 *v11; // eax
  double v12; // st7
  phys_vec3 *v13; // eax
  int v14; // [esp-40h] [ebp-4Ch]
  int v15; // [esp-30h] [ebp-3Ch]
  int v16; // [esp-20h] [ebp-2Ch]
  float v17; // [esp-10h] [ebp-1Ch]
  float v18; // [esp-Ch] [ebp-18h]
  float v19; // [esp-8h] [ebp-14h]
  int v20; // [esp+0h] [ebp-Ch]
  int v21; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v20 = a2;
  v21 = retaddr;
  v6 = v;
  v7 = a3;
  v8 = xform;
  v17 = xform->x.y * v->y + xform->x.x * v->x + xform->x.z * v->z;
  v18 = v8->y.y * v6->y + v8->y.x * v6->x + v8->y.z * v6->z;
  v9 = v8->z.y * v6->y + v6->x * v8->z.x;
  v10 = this->vfptr->support;
  v19 = v9 + xform->z.z * v->z;
  ((void (__cdecl *)(float *, int *, int *, int))v10)(&v17, &v16, &v15, v7);
  v11 = phys_multiply((phys_vec3 *)&v14, xform, (phys_vec3 *)&v16);
  result->x = v11->x + xform->w.x;
  result->y = v11->y + xform->w.y;
  v12 = v11->z;
  v13 = result;
  result->z = v12 + xform->w.z;
  return v13;
}

