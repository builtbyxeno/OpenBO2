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
phys_gjk_info::gjk_subalgorithm
==============
*/
int __thiscall phys_gjk_info::gjk_subalgorithm(phys_gjk_info *this, const int w_set, const int new_index)
{
  return backup1(this, new_index, 0);
}

/*
==============
phys_gjk_info::seed_simplex
==============
*/
int __thiscall phys_gjk_info::seed_simplex(phys_gjk_info *this, const int cached_vert_count)
{
  int v2; // edi
  phys_gjk_info *v3; // esi
  int v4; // edx
  int v5; // ecx
  unsigned int v6; // edx
  float *v7; // eax
  float v8; // ST30_4
  float v9; // ST34_4
  float v10; // ST38_4
  float v11; // ST20_4
  float v12; // ST24_4
  float v13; // ST28_4
  int v14; // ecx
  float v15; // ST30_4
  float v16; // ST34_4
  float v17; // ST38_4
  float v18; // ST20_4
  float v19; // ST24_4
  float v20; // ST28_4
  float v21; // ST30_4
  float v22; // ST34_4
  float v23; // ST38_4
  float v24; // ST20_4
  float v25; // ST24_4
  float v26; // ST28_4
  float v27; // ST30_4
  double v28; // st7
  float v29; // ST34_4
  float v30; // ST38_4
  float v31; // ST20_4
  float v32; // ST24_4
  float v33; // ST28_4
  int v34; // eax
  int v35; // edi
  double v36; // st7
  float v37; // ST30_4
  float v38; // ST34_4
  float v39; // ST38_4
  float v40; // ST20_4
  float v41; // ST24_4
  float v42; // ST28_4
  int v44; // [esp-4h] [ebp-10h]

  v2 = cached_vert_count;
  v3 = this;
  if ( cached_vert_count <= 0 && _tlAssert("source/phys_gjk.cpp", 381, "cached_vert_count > 0", (const char *)&pBlock) )
    __debugbreak();
  if ( cached_vert_count >= 4 && _tlAssert("source/phys_gjk.cpp", 382, "cached_vert_count < 4", (const char *)&pBlock) )
    __debugbreak();
  v4 = 0;
  v3->m_w_set = 0;
  v5 = 1;
  if ( cached_vert_count >= 4 )
  {
    v6 = ((unsigned int)(cached_vert_count - 4) >> 2) + 1;
    v7 = &v3->m_b_verts[0].y;
    v44 = 4 * v6;
    do
    {
      v8 = *(v7 - 17) - *(v7 - 1);
      v9 = *(v7 - 16) - *v7;
      v10 = *(v7 - 15) - v7[1];
      v11 = v8 - v3->m_gjk_origin.x;
      v12 = v9 - v3->m_gjk_origin.y;
      v13 = v10 - v3->m_gjk_origin.z;
      *(v7 - 33) = v11;
      *(v7 - 32) = v12;
      *(v7 - 31) = v13;
      v3->m_w_set |= v5;
      v14 = 2 * v5;
      v15 = *(v7 - 13) - v7[3];
      v16 = *(v7 - 12) - v7[4];
      v17 = *(v7 - 11) - v7[5];
      v18 = v15 - v3->m_gjk_origin.x;
      v19 = v16 - v3->m_gjk_origin.y;
      v20 = v17 - v3->m_gjk_origin.z;
      *(v7 - 29) = v18;
      *(v7 - 28) = v19;
      *(v7 - 27) = v20;
      v3->m_w_set |= v14;
      v14 *= 2;
      v21 = *(v7 - 9) - v7[7];
      v22 = *(v7 - 8) - v7[8];
      v23 = *(v7 - 7) - v7[9];
      v24 = v21 - v3->m_gjk_origin.x;
      v25 = v22 - v3->m_gjk_origin.y;
      v26 = v23 - v3->m_gjk_origin.z;
      *(v7 - 25) = v24;
      *(v7 - 24) = v25;
      *(v7 - 23) = v26;
      v3->m_w_set |= v14;
      v14 *= 2;
      v27 = *(v7 - 5) - v7[11];
      v28 = *(v7 - 4);
      v7 += 16;
      v29 = v28 - *(v7 - 4);
      v30 = *(v7 - 19) - *(v7 - 3);
      v31 = v27 - v3->m_gjk_origin.x;
      v32 = v29 - v3->m_gjk_origin.y;
      v33 = v30 - v3->m_gjk_origin.z;
      *(v7 - 37) = v31;
      *(v7 - 36) = v32;
      *(v7 - 35) = v33;
      v3->m_w_set |= v14;
      v5 = 2 * v14;
      --v6;
    }
    while ( v6 );
    v2 = cached_vert_count;
    v4 = v44;
  }
  if ( v4 < v2 )
  {
    v34 = (int)&v3->m_b_verts[v4].y;
    v35 = v2 - v4;
    do
    {
      v36 = *(float *)(v34 - 68);
      v34 += 16;
      v37 = v36 - *(float *)(v34 - 20);
      v38 = *(float *)(v34 - 80) - *(float *)(v34 - 16);
      v39 = *(float *)(v34 - 76) - *(float *)(v34 - 12);
      v40 = v37 - v3->m_gjk_origin.x;
      v41 = v38 - v3->m_gjk_origin.y;
      v42 = v39 - v3->m_gjk_origin.z;
      *(float *)(v34 - 148) = v40;
      *(float *)(v34 - 144) = v41;
      *(float *)(v34 - 140) = v42;
      v3->m_w_set |= v5;
      v5 *= 2;
      --v35;
    }
    while ( v35 );
  }
  return backup1(v3, 0, 1);
}

/*
==============
backup1
==============
*/
int __usercall backup1@<eax>(int a1@<ebp>, phys_gjk_info *gjk_info, const int new_index, const bool seed_simplex)
{
  int v4; // esi
  double v5; // st7
  float *v6; // esi
  double v7; // st6
  double v8; // st5
  float v9; // edx
  float *v10; // edi
  float v11; // eax
  float *v12; // ecx
  float v13; // ST10_4
  float v14; // ST14_4
  float v15; // ST18_4
  double v16; // st5
  double v17; // st4
  double v18; // rt2
  double v19; // st4
  double v20; // st5
  double v21; // st5
  double v22; // st4
  float j; // ST50_4
  float v24; // ST54_4
  float v25; // ST58_4
  float ww_4; // ST60_4
  float ww_8; // ST64_4
  float ww_12; // ST68_4
  int v29; // eax
  double v30; // st7
  float v31; // ecx
  float v32; // ST60_4
  float v33; // ST64_4
  float v34; // ST68_4
  double v35; // st6
  double v36; // st4
  double v37; // st5
  double v38; // st3
  double v39; // st3
  double v40; // st2
  double v41; // st6
  float v42; // ST60_4
  float v43; // ST64_4
  float v44; // ST68_4
  float v45; // ST50_4
  float v46; // ST54_4
  float v47; // ST58_4
  signed int v48; // ecx
  float *v49; // eax
  float *v50; // edi
  double v51; // st6
  double v52; // st5
  double v53; // st4
  double v54; // st3
  double v55; // st2
  double v56; // st4
  double v57; // st7
  double v58; // st5
  double v59; // st4
  float v60; // ST10_4
  float v61; // ST14_4
  float v62; // ST18_4
  float v63; // ST60_4
  float v64; // ST64_4
  float v65; // ST68_4
  float v66; // ST50_4
  float v67; // ST54_4
  float v68; // ST58_4
  float v69; // ST30_4
  float v70; // ST34_4
  float v71; // ST38_4
  int v72; // edi
  int v73; // eax
  double v74; // st5
  double v75; // rt0
  bool v76; // zf
  double v77; // st3
  double v78; // st2
  double v79; // st7
  int result; // eax
  int v81; // [esp-10h] [ebp-E0h]
  float v82; // [esp-Ch] [ebp-DCh]
  float v83; // [esp-8h] [ebp-D8h]
  float v84; // [esp-4h] [ebp-D4h]
  signed int crw2_8; // [esp+8h] [ebp-C8h]
  int crw2_12; // [esp+Ch] [ebp-C4h]
  phys_vec3 dif; // [esp+30h] [ebp-A0h]
  const float c1; // [esp+40h] [ebp-90h]
  float *v89; // [esp+44h] [ebp-8Ch]
  int w_count; // [esp+48h] [ebp-88h]
  float new_dist_sq; // [esp+4Ch] [ebp-84h]
  int i; // [esp+50h] [ebp-80h]
  int v93; // [esp+54h] [ebp-7Ch]
  const float c2; // [esp+58h] [ebp-78h]
  int w_inds[3]; // [esp+74h] [ebp-5Ch]
  phys_vec3 difs[3]; // [esp+80h] [ebp-50h]
  unsigned int v97; // [esp+C0h] [ebp-10h]
  int v98; // [esp+C4h] [ebp-Ch]
  int v99; // [esp+C8h] [ebp-8h]
  int retaddr; // [esp+D0h] [ebp+0h]

  v98 = a1;
  v99 = retaddr;
  v97 = (unsigned int)&v98 ^ __security_cookie;
  v4 = 16 * (new_index + 10);
  v5 = *(float *)((char *)&gjk_info->cg2_to_cg1_xform.x.y + v4);
  v6 = (float *)((char *)&gjk_info->cg2_to_cg1_xform.x.x + v4);
  v7 = *v6;
  v8 = v6[2];
  LODWORD(v9) = 1 << new_index;
  LODWORD(dif.z) = gjk_info;
  c1 = v5 * v5 + v7 * v7 + v8 * v8;
  *(&gjk_info->cg2_to_cg1_xform.x.x + (1 << new_index) + 30 + new_index + 4 * ((1 << new_index) + 30)) = 1.0;
  v93 = ~(1 << new_index) & gjk_info->m_w_set;
  dif.w = 0.0;
  v89 = NULL;
  LODWORD(new_dist_sq) = 1;
  w_count = (int)&gjk_info->m_w_verts[0].z;
  crw2_12 = __ROL4__(1, new_index);
  v10 = (float *)&w_inds[2];
  do
  {
    if ( v93 & LODWORD(new_dist_sq) )
    {
      v11 = dif.w;
      *(&v98 + LODWORD(dif.w) - 23) = (int)v89;
      v12 = (float *)w_count;
      v13 = *(float *)(w_count - 8) - *v6;
      v14 = *(float *)(w_count - 4) - v6[1];
      v15 = *(float *)w_count - v6[2];
      *(v10 - 2) = v13;
      *(v10 - 1) = v14;
      *v10 = v15;
      *(float *)&i = *(v10 - 1) * *(v10 - 1) + *(v10 - 2) * *(v10 - 2) + *v10 * *v10;
      v16 = *(float *)&i;
      *(&v98 + LODWORD(v11) - 26) = i;
      *(float *)&i = *v6 * *(v10 - 2) + v6[1] * *(v10 - 1) + *v10 * v6[2];
      v17 = *(float *)&i;
      *(&v98 + LODWORD(v11) - 7) = i;
      v18 = v17;
      v19 = v16;
      v20 = v18;
      if ( v19 > 9.999999439624929e-11 )
      {
        *(float *)&i = -v20 / v19;
        v21 = *(float *)&i;
        *(float *)&i = 1.0 - *(float *)&i;
        if ( v21 > 0.0 )
        {
          v22 = *(float *)&i;
          if ( *(float *)&i > 0.0 )
          {
            j = *(v10 - 2) * v21;
            v24 = v21 * *(v10 - 1);
            v25 = *v10 * v21;
            ww_4 = *v6 + j;
            ww_8 = v6[1] + v24;
            ww_12 = v25 + v6[2];
            *(float *)&i = ww_4 * ww_4 + ww_8 * ww_8 + ww_12 * ww_12;
            if ( c1 > (double)*(float *)&i )
            {
              c1 = *(float *)&i;
              LODWORD(v9) = LODWORD(new_dist_sq) | crw2_12;
              v29 = LODWORD(dif.z) + 4 * (5 * (LODWORD(new_dist_sq) | crw2_12) + 150);
              *(float *)(v29 + 4 * (_DWORD)v89) = v21;
              *(float *)(v29 + 4 * new_index) = v22;
              v12 = (float *)w_count;
            }
          }
        }
      }
      if ( seed_simplex
        && (*(float *)&i = *v12 * *v12 + *(v12 - 2) * *(v12 - 2) + *(v12 - 1) * *(v12 - 1), c1 > (double)*(float *)&i) )
      {
        v9 = new_dist_sq;
        c1 = *(float *)&i;
        ++LODWORD(dif.w);
        *(float *)(LODWORD(dif.z) + 4 * ((_DWORD)&v89[LODWORD(v9) + 37] + LODWORD(v9) + 2)) = 1.0;
        v12 = (float *)w_count;
        v10 += 4;
      }
      else
      {
        ++LODWORD(dif.w);
        v10 += 4;
      }
    }
    else
    {
      v12 = (float *)w_count;
    }
    LODWORD(new_dist_sq) *= 2;
    v89 = (float *)((char *)v89 + 1);
    w_count = (int)(v12 + 4);
  }
  while ( (signed int)v89 < 4 );
  v30 = 0.0;
  v31 = dif.z;
  if ( seed_simplex && LODWORD(dif.w) == 2 )
  {
    v32 = *(float *)(LODWORD(dif.z) + 192) - *(float *)(LODWORD(dif.z) + 176);
    v33 = *(float *)(LODWORD(dif.z) + 196) - *(float *)(LODWORD(dif.z) + 180);
    v34 = *(float *)(LODWORD(dif.z) + 200) - *(float *)(LODWORD(dif.z) + 184);
    v35 = v32;
    v36 = v33;
    v37 = v34;
    *(float *)&v93 = v34 * v34 + v32 * v32 + v33 * v33;
    v38 = *(float *)&v93;
    if ( *(float *)&v93 > 9.999999439624929e-11 )
    {
      *(float *)&v93 = v36 * *(float *)(LODWORD(dif.z) + 180)
                     + *(float *)(LODWORD(dif.z) + 176) * v35
                     + v37 * *(float *)(LODWORD(dif.z) + 184);
      *(float *)&v93 = -*(float *)&v93 / v38;
      v39 = *(float *)&v93;
      *(float *)&v93 = 1.0 - *(float *)&v93;
      if ( v39 > 0.0 && *(float *)&v93 > 0.0 )
      {
        v40 = v35 * v39;
        v41 = *(float *)&v93;
        v42 = v40;
        v43 = v36 * v39;
        v44 = v37 * v39;
        v45 = *(float *)(LODWORD(dif.z) + 176) + v42;
        v46 = v43 + *(float *)(LODWORD(dif.z) + 180);
        v47 = v44 + *(float *)(LODWORD(dif.z) + 184);
        *(float *)&v93 = v46 * v46 + v45 * v45 + v47 * v47;
        if ( c1 > (double)*(float *)&v93 )
        {
          c1 = *(float *)&v93;
          LODWORD(v9) = 6;
          *(float *)(LODWORD(dif.z) + 724) = v41;
          *(float *)(LODWORD(v31) + 728) = v39;
        }
      }
    }
  }
  if ( LODWORD(dif.w) - 1 > 0 )
  {
    v48 = 1;
    v49 = (float *)&w_inds[2];
    i = 1;
    v89 = (float *)&w_inds[2];
    w_count = 0;
    v93 = LODWORD(dif.w) - 1;
    do
    {
      crw2_8 = v48;
      if ( v48 < SLODWORD(dif.w) )
      {
        new_dist_sq = *(float *)((char *)&v98 + w_count - 104);
        v50 = v49 + 4;
        v81 = (int)(v49 + 4);
        dif.y = -*(float *)((char *)&v98 + w_count - 28);
        v51 = new_dist_sq;
        v52 = dif.y;
        do
        {
          new_dist_sq = *(v49 - 1) * *(v50 - 1) + *(v50 - 2) * *(v49 - 2) + *v49 * *v50;
          dif.y = *((float *)&v98 + v48 - 26);
          c2 = -*((float *)&v98 + v48 - 7);
          v53 = dif.y;
          v54 = new_dist_sq;
          dif.y = dif.y * v51 - new_dist_sq * new_dist_sq;
          if ( dif.y > 0.0000099999997 )
          {
            v55 = (v53 * v52 - c2 * v54) / dif.y;
            v56 = c2;
            c2 = v55;
            v57 = v52;
            dif.y = (v56 * v51 - v54 * v52) / dif.y;
            v58 = c2;
            v59 = dif.y;
            new_dist_sq = 1.0 - c2 - dif.y;
            if ( c2 <= 0.0 || v59 <= 0.0 || new_dist_sq <= 0.0 )
            {
              v74 = 0.0;
            }
            else
            {
              v60 = *(v50 - 2) * v59;
              v61 = *(v50 - 1) * v59;
              v62 = *v50 * v59;
              v63 = *(v89 - 2) * v58;
              v64 = *(v89 - 1) * v58;
              v65 = *v89 * v58;
              v66 = *v6 + v63;
              v67 = v6[1] + v64;
              v68 = v65 + v6[2];
              v69 = v66 + v60;
              v70 = v67 + v61;
              v71 = v68 + v62;
              c2 = v70 * v70 + v69 * v69 + v71 * v71;
              if ( c1 > (double)c2 )
              {
                v72 = *(&v98 + v48 - 23);
                c1 = c2;
                LODWORD(v9) = crw2_12 | (1 << v72) | (1 << *(int *)((char *)&v98 + w_count - 92));
                v73 = LODWORD(dif.z) + 4 * (5 * LODWORD(v9) + 150);
                *(float *)(v73 + 4 * *(int *)((char *)&v98 + w_count - 92)) = v58;
                *(float *)(v73 + 4 * v72) = v59;
                v50 = (float *)v81;
                *(float *)(v73 + 4 * new_index) = new_dist_sq;
                v48 = crw2_8;
              }
              v74 = 0.0;
            }
            v75 = v74;
            v52 = v57;
            v30 = v75;
          }
          v49 = v89;
          ++v48;
          v50 += 4;
          crw2_8 = v48;
          v81 = (int)v50;
        }
        while ( v48 < SLODWORD(dif.w) );
        v48 = i;
      }
      w_count += 4;
      ++v48;
      v49 += 4;
      v76 = v93-- == 1;
      i = v48;
      v89 = v49;
    }
    while ( !v76 );
    v31 = dif.z;
  }
  if ( LODWORD(dif.w) != 3 )
    goto LABEL_52;
  if ( v30 < *(float *)(LODWORD(v31) + 532) )
    goto LABEL_52;
  difs[2].y = difs[0].w * *(float *)&w_inds[1] - *(float *)&w_inds[2] * difs[0].z;
  difs[2].z = *(float *)&w_inds[2] * difs[0].y - difs[0].w * *(float *)w_inds;
  difs[2].w = *(float *)w_inds * difs[0].z - *(float *)&w_inds[1] * difs[0].y;
  v77 = difs[1].z;
  c2 = difs[2].z * difs[1].z + difs[2].y * difs[1].y + difs[2].w * difs[1].w;
  v78 = c2;
  c2 = fabs(c2);
  if ( c2 <= 0.0000099999997 )
    goto LABEL_52;
  c2 = difs[2].z * v6[1] + *v6 * difs[2].y + difs[2].w * v6[2];
  *(float *)&v93 = -c2 / v78;
  if ( *(float *)&v93 < 0.0 )
    goto LABEL_52;
  v82 = v6[1] * difs[1].w - v77 * v6[2];
  v83 = difs[1].y * v6[2] - *v6 * difs[1].w;
  v84 = v77 * *v6 - v6[1] * difs[1].y;
  c2 = difs[0].w * v84 + difs[0].y * v82 + difs[0].z * v83;
  c2 = c2 / v78;
  if ( c2 < 0.0
    || (v79 = c2,
        c2 = v84 * *(float *)&w_inds[2] + v82 * *(float *)w_inds + v83 * *(float *)&w_inds[1],
        c2 = -c2 / v78,
        c2 < 0.0)
    || (c2 = 1.0 - v79 - c2 - *(float *)&v93, c2 < 0.0) )
  {
LABEL_52:
    result = LODWORD(v9);
  }
  else
  {
    result = 15;
  }
  return result;
}

/*
==============
phys_gjk_info::gjk
==============
*/
phys_gjk_info::gjk_retval_e __userpurge phys_gjk_info::gjk@<eax>(phys_gjk_info *this@<ecx>, float a2@<ebp>, float *a3@<edi>, int a4@<esi>, phys_gjk_input *d, phys_vec3 *initial_support_dir, const bool in_separation_loop)
{
  phys_gjk_info *v7; // esi
  float *v8; // edi
  bool v9; // zf
  double v10; // st7
  phys_gjk_info::gjk_retval_e result; // eax
  int v12; // eax
  phys_gjk_geom *v13; // ecx
  double v14; // st7
  double v15; // st7
  double v16; // st7
  phys_gjk_geom *v17; // ecx
  double v18; // st7
  double v19; // st6
  double v20; // st7
  double v21; // st7
  double v22; // st7
  phys_vec3 *v23; // eax
  float *v24; // ecx
  double v25; // st7
  phys_vec3 *v26; // eax
  double v27; // st6
  double v28; // st5
  double v29; // st7
  double v30; // st4
  double v31; // st3
  signed int v32; // ecx
  signed int v33; // edx
  int v34; // ecx
  int v35; // eax
  int v36; // eax
  float *v37; // [esp-5Ch] [ebp-9Ch]
  int v38; // [esp-58h] [ebp-98h]
  int v39; // [esp-54h] [ebp-94h]
  int v40; // [esp-4Ch] [ebp-8Ch]
  float v41; // [esp-3Ch] [ebp-7Ch]
  float v42; // [esp-38h] [ebp-78h]
  float v43; // [esp-34h] [ebp-74h]
  float v44; // [esp-2Ch] [ebp-6Ch]
  float v45; // [esp-28h] [ebp-68h]
  float v46; // [esp-24h] [ebp-64h]
  float v47; // [esp-1Ch] [ebp-5Ch]
  float v48; // [esp-18h] [ebp-58h]
  float v49; // [esp-14h] [ebp-54h]
  float v50; // [esp-Ch] [ebp-4Ch]
  float v51; // [esp-8h] [ebp-48h]
  float v52; // [esp-4h] [ebp-44h]
  phys_vec3 w; // [esp+0h] [ebp-40h]
  float v54; // [esp+14h] [ebp-2Ch]
  float v55; // [esp+18h] [ebp-28h]
  float v56; // [esp+1Ch] [ebp-24h]
  float v57; // [esp+28h] [ebp-18h]
  phys_vec3 *v58; // [esp+2Ch] [ebp-14h]
  unsigned int v59; // [esp+30h] [ebp-10h]
  const float lower_dist_sq; // [esp+34h] [ebp-Ch]
  int v61; // [esp+38h] [ebp-8h]
  int retaddr; // [esp+40h] [ebp+0h]

  lower_dist_sq = a2;
  v61 = retaddr;
  v38 = a4;
  v37 = a3;
  v7 = this;
  this->m_lower_dist_sq = -34.0;
  this->m_upper_dist_sq = 34.0;
  this->m_gjk_iter = phys_gjk_info::init_gjk(this, d, initial_support_dir, in_separation_loop);
  v8 = &v7->m_support_dir.x;
  while ( 1 )
  {
    v9 = v7->m_gjk_iter == 0;
    v57 = v7->m_support_dir.y * v7->m_support_dir.y + *v8 * *v8 + v7->m_support_dir.z * v7->m_support_dir.z;
    v10 = v57;
    v7->m_upper_dist_sq = v57;
    if ( !v9 && v7->m_gjk_pen_thresh_sq > v10 )
      return 2;
    v12 = v7->m_w_set;
    if ( v12 & 1 )
    {
      if ( v12 & 2 )
        v59 = (v7->m_w_set & 4 | 8u) >> 2;
      else
        v59 = 1;
    }
    else
    {
      v59 = 0;
    }
    v13 = d->gjk_cg1;
    v44 = -*v8;
    v45 = -v7->m_support_dir.y;
    v46 = -v7->m_support_dir.z;
    LODWORD(v57) = (char *)v7 + 16 * (v59 + 14);
    ((void (__stdcall *)(float *, unsigned int, unsigned int, float *, int, int))v13->vfptr->support)(
      &v44,
      (int)v7 + 16 * (v59 + 14),
      (int)v7 + 16 * (v59 + 22),
      v37,
      v38,
      v39);
    v14 = *(float *)LODWORD(v57);
    v15 = v7->m_a_verts[v59].y;
    v16 = v7->m_a_verts[v59].z;
    v17 = d->gjk_cg2;
    v18 = v7->cg2_to_cg1_xform.x.y * v7->m_support_dir.y + v7->m_support_dir.x * v7->cg2_to_cg1_xform.x.x;
    v19 = v7->cg2_to_cg1_xform.x.z * v7->m_support_dir.z;
    v58 = &v7->cg2_to_cg1_xform.x + v59 + 18;
    v39 = (int)v7 + 16 * (v59 + 26);
    v38 = (int)v7 + 16 * (v59 + 18);
    v41 = v18 + v19;
    v37 = &v41;
    v42 = v7->cg2_to_cg1_xform.y.y * v7->m_support_dir.y
        + v7->m_support_dir.x * v7->cg2_to_cg1_xform.y.x
        + v7->cg2_to_cg1_xform.y.z * v7->m_support_dir.z;
    v43 = v7->cg2_to_cg1_xform.z.y * v7->m_support_dir.y
        + v7->cg2_to_cg1_xform.z.x * v7->m_support_dir.x
        + v7->cg2_to_cg1_xform.z.z * v7->m_support_dir.z;
    ((void (*)(void))v17->vfptr->support)();
    v20 = v58->x;
    v21 = v7->m_b_verts[v59].y;
    v22 = v7->m_b_verts[v59].z;
    v23 = phys_multiply((phys_vec3 *)&v40, &v7->cg2_to_cg1_xform, v58);
    v24 = (float *)LODWORD(v57);
    v54 = v23->x + v7->cg2_to_cg1_xform.w.x;
    v55 = v23->y + v7->cg2_to_cg1_xform.w.y;
    v25 = v23->z;
    v26 = v58;
    v56 = v25 + v7->cg2_to_cg1_xform.w.z;
    v58->x = v54;
    v26->y = v55;
    v26->z = v56;
    w.y = *v24 - v26->x;
    w.z = v24[1] - v26->y;
    w.w = v24[2] - v26->z;
    v50 = w.y - v7->m_gjk_origin.x;
    v51 = w.z - v7->m_gjk_origin.y;
    v52 = w.w - v7->m_gjk_origin.z;
    v27 = v50;
    v28 = v51;
    v29 = v52;
    v57 = v7->m_support_dir.x * v50 + v51 * v7->m_support_dir.y + v52 * v7->m_support_dir.z;
    v30 = 0.0;
    if ( v57 > 0.0 )
    {
      if ( v7->m_upper_dist_sq <= 0.0 )
      {
        v30 = 0.0;
      }
      else
      {
        v30 = 0.0;
        v57 = v57 * v57;
        v57 = v57 / v7->m_upper_dist_sq;
        v31 = v57;
        if ( v7->m_lower_dist_sq < (double)v57 )
        {
          v9 = (v7->m_flags & 1) == 0;
          v7->m_lower_dist_sq = v57;
          if ( !v9 )
          {
            v57 = v7->m_gjk_sep_thresh;
            v57 = v57 * v57;
            if ( v57 < v31 )
              return 0;
          }
        }
      }
    }
    if ( v7->m_gjk_iter && v30 < v7->m_lower_dist_sq )
      break;
LABEL_24:
    v34 = v59;
    v35 = 2 * (v59 + 10);
    *(&v7->cg2_to_cg1_xform.x.x + 2 * v35) = v27;
    *(&v7->cg2_to_cg1_xform.x.y + 2 * v35) = v28;
    *(&v7->cg2_to_cg1_xform.x.z + 2 * v35) = v29;
    v7->m_w_set |= 1 << v34;
    v7->m_last_w_set = v7->m_w_set;
    v36 = backup1((int)&lower_dist_sq, v7, v34, 0);
    v7->m_w_set = v36;
    if ( v36 == 15 )
      return 2;
    phys_gjk_info::comp_v(v7, v36, &v7->m_support_dir);
    result = 1;
    if ( ++v7->m_gjk_iter >= 30 )
      return result;
  }
  v57 = 1.0 - CONV_THRESH;
  v57 = v57 * v57;
  if ( v7->m_lower_dist_sq > v57 * v7->m_upper_dist_sq )
    return 1;
  v32 = 0;
  v33 = 1;
  LODWORD(v57) = (char *)v7 + 168;
  while ( 1 )
  {
    if ( v33 & v7->m_last_w_set )
    {
      v47 = v27 - *(float *)(LODWORD(v57) - 8);
      v48 = v28 - *(float *)(LODWORD(v57) - 4);
      v49 = v29 - *(float *)LODWORD(v57);
      *(float *)&v58 = v48 * v48 + v47 * v47 + v49 * v49;
      if ( *(float *)&v58 < 0.0000010000001 )
        return 1;
    }
    LODWORD(v57) += 16;
    ++v32;
    v33 *= 2;
    if ( v32 >= 4 )
      goto LABEL_24;
  }
}

/*
==============
phys_gjk_info::gjk_ray_cast
==============
*/
// local variable allocation has failed, the output may be wrong!
phys_gjk_info::gjk_retval_e __userpurge phys_gjk_info::gjk_ray_cast@<eax>(phys_gjk_info *this@<ecx>, float a2@<ebp>, float *a3@<edi>, int a4@<esi>, phys_gjk_input *d, phys_vec3 *initial_support_dir, const bool in_separation_loop)
{
  phys_gjk_info *v7; // esi
  double v8; // st7
  int v9; // eax
  phys_gjk_cache_info *v10; // ecx
  int v11; // eax
  unsigned int v12; // eax
  double v13; // st7
  bool v14; // zf
  double v15; // st7
  int v16; // ecx
  int v17; // ecx
  phys_gjk_info::gjk_retval_e result; // eax
  int v19; // eax
  unsigned int v20; // edi
  phys_gjk_geom *v21; // ecx
  double v22; // st7
  double v23; // st7
  int v24; // edi
  double v25; // st7
  double v26; // st7
  phys_gjk_geom *v27; // ecx
  phys_vec3 *v28; // edi
  double v29; // st7
  double v30; // st7
  double v31; // st7
  phys_vec3 *v32; // eax
  double v33; // st7
  float *v34; // eax
  double v35; // st6
  double v36; // st5
  double v37; // st7
  double v38; // st4
  double v39; // st4
  int v40; // ecx
  double v41; // st3
  double v42; // st3
  signed int v43; // ecx
  signed int v44; // edx
  float *v45; // edi
  double v46; // st4
  double v47; // st7
  double v48; // st6
  double v49; // st7
  int v50; // ecx
  int v51; // eax
  int v52; // eax
  bool v53; // c0
  double v54; // st5
  double v55; // st5
  double v56; // st7
  double v57; // st6
  double v58; // st6
  signed int v59; // eax
  float *v60; // [esp-8Ch] [ebp-BCh]
  int v61; // [esp-88h] [ebp-B8h]
  int v62; // [esp-84h] [ebp-B4h]
  int v63; // [esp-7Ch] [ebp-ACh]
  float v64; // [esp-6Ch] [ebp-9Ch]
  float v65; // [esp-68h] [ebp-98h]
  float v66; // [esp-64h] [ebp-94h]
  float v67; // [esp-5Ch] [ebp-8Ch]
  float v68; // [esp-58h] [ebp-88h]
  float v69; // [esp-54h] [ebp-84h]
  float v70; // [esp-4Ch] [ebp-7Ch]
  float v71; // [esp-48h] [ebp-78h]
  float v72; // [esp-44h] [ebp-74h]
  float v73; // [esp-3Ch] [ebp-6Ch]
  float v74; // [esp-38h] [ebp-68h]
  float v75; // [esp-34h] [ebp-64h]
  float v76; // [esp-2Ch] [ebp-5Ch]
  float v77; // [esp-28h] [ebp-58h]
  float v78; // [esp-24h] [ebp-54h]
  float v79; // [esp-1Ch] [ebp-4Ch]
  float v80; // [esp-18h] [ebp-48h]
  float v81; // [esp-14h] [ebp-44h]
  float v82; // [esp-Ch] [ebp-3Ch]
  float v83; // [esp-8h] [ebp-38h]
  float v84; // [esp-4h] [ebp-34h]
  phys_vec3 w; // [esp+0h] [ebp-30h]
  unsigned int v86; // [esp+10h] [ebp-20h]
  float v87; // [esp+14h] [ebp-1Ch]
  const float support_dir_moveback; // [esp+18h] [ebp-18h]
  int new_index; // [esp+1Ch] [ebp-14h]
  float lambda; // [esp+20h] [ebp-10h]
  const float ray_end_dist_numer; // [esp+24h] [ebp-Ch]
  void *v92; // [esp+28h] [ebp-8h] OVERLAPPED
  void *retaddr; // [esp+30h] [ebp+0h]

  ray_end_dist_numer = a2;
  v92 = retaddr;
  v61 = a4;
  v60 = a3;
  v7 = this;
  lambda = d->m_start_time;
  v8 = lambda;
  this->m_continuous_collision_lambda = lambda;
  lambda = -v8;
  v82 = this->m_cg1_relative_translation_loc.x * lambda;
  v83 = this->m_cg1_relative_translation_loc.y * lambda;
  v84 = lambda * this->m_cg1_relative_translation_loc.z;
  this->m_gjk_origin.x = v82;
  this->m_gjk_origin.y = v83;
  this->m_gjk_origin.z = v84;
  this->m_lower_dist_sq = -34.0;
  this->m_upper_dist_sq = 34.0;
  v9 = phys_gjk_info::init_gjk(this, d, initial_support_dir, in_separation_loop);
  v7->m_flags &= 0xFFFFFFDA;
  v7->m_gjk_iter = v9;
  v10 = d->gjk_ci;
  v11 = v7->m_flags;
  if ( v10 && v10->m_flags & 4 )
    v12 = v11 | 0x10;
  else
    v12 = v11 & 0xFFFFFFEF;
  v7->m_flags = v12;
  v7->m_cc_reset_iter = 0;
  if ( v7->m_geom_radii_sum >= 0.05099999904632568 )
    v13 = v7->m_geom_radii_sum;
  else
    v13 = 0.050999999;
  w.w = v13;
  if ( v7->m_gjk_sep_thresh <= (double)w.w
    && _tlAssert("source/phys_gjk.cpp", 1726, "support_dir_moveback < m_gjk_sep_thresh", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  while ( 1 )
  {
    while ( 1 )
    {
      v14 = v7->m_gjk_iter == 0;
      lambda = v7->m_support_dir.y * v7->m_support_dir.y
             + v7->m_support_dir.x * v7->m_support_dir.x
             + v7->m_support_dir.z * v7->m_support_dir.z;
      v15 = lambda;
      v7->m_upper_dist_sq = lambda;
      if ( !v14 )
      {
        v16 = v7->m_flags;
        if ( v16 & 0x10 )
        {
          lambda = v7->m_gjk_sep_thresh;
          lambda = lambda * lambda;
          if ( lambda > v15 )
            v7->m_flags = v16 | 1;
        }
        if ( v7->m_gjk_pen_thresh_sq > (double)v7->m_upper_dist_sq )
        {
          v17 = v7->m_flags;
          if ( v17 & 8 && 0.0 != v7->m_continuous_collision_lambda && !(v17 & 2) )
            tlWarning("m_continuous_collision_lambda problem\n");
          return 2;
        }
      }
      v19 = v7->m_w_set;
      if ( v19 & 1 )
      {
        if ( v19 & 2 )
        {
          v20 = (v7->m_w_set & 4 | 8u) >> 2;
          v86 = (v7->m_w_set & 4 | 8u) >> 2;
          goto LABEL_27;
        }
        v20 = 1;
      }
      else
      {
        v20 = 0;
      }
      v86 = v20;
LABEL_27:
      v21 = d->gjk_cg1;
      v67 = -v7->m_support_dir.x;
      v68 = -v7->m_support_dir.y;
      v22 = -v7->m_support_dir.z;
      LODWORD(v87) = (char *)v7 + 16 * (v20 + 14);
      v69 = v22;
      ((void (__stdcall *)(float *, unsigned int, unsigned int, float *, int, int))v21->vfptr->support)(
        &v67,
        (int)v7 + 16 * (v20 + 14),
        (int)v7 + 16 * (v20 + 22),
        v60,
        v61,
        v62);
      v23 = *(float *)LODWORD(v87);
      v24 = v20;
      v25 = v7->m_a_verts[v24].y;
      v26 = v7->m_a_verts[v24].z;
      v27 = d->gjk_cg2;
      v62 = (int)v7 + 16 * (v86 + 26);
      v28 = &v7->cg2_to_cg1_xform.x + v86 + 18;
      v61 = (int)v7 + 16 * (v86 + 18);
      v60 = &v64;
      v64 = v7->cg2_to_cg1_xform.x.y * v7->m_support_dir.y
          + v7->m_support_dir.x * v7->cg2_to_cg1_xform.x.x
          + v7->cg2_to_cg1_xform.x.z * v7->m_support_dir.z;
      v65 = v7->cg2_to_cg1_xform.y.y * v7->m_support_dir.y
          + v7->m_support_dir.x * v7->cg2_to_cg1_xform.y.x
          + v7->cg2_to_cg1_xform.y.z * v7->m_support_dir.z;
      v66 = v7->cg2_to_cg1_xform.z.y * v7->m_support_dir.y
          + v7->m_support_dir.x * v7->cg2_to_cg1_xform.z.x
          + v7->cg2_to_cg1_xform.z.z * v7->m_support_dir.z;
      ((void (*)(void))v27->vfptr->support)();
      v29 = v28->x;
      v30 = v7->m_b_verts[v86].y;
      v31 = v7->m_b_verts[v86].z;
      v32 = phys_multiply((phys_vec3 *)&v63, &v7->cg2_to_cg1_xform, v28);
      v76 = v32->x + v7->cg2_to_cg1_xform.w.x;
      v77 = v32->y + v7->cg2_to_cg1_xform.w.y;
      v33 = v32->z;
      v34 = (float *)LODWORD(v87);
      v78 = v33 + v7->cg2_to_cg1_xform.w.z;
      v28->x = v76;
      v28->y = v77;
      v28->z = v78;
      v70 = *v34 - v28->x;
      v71 = v34[1] - v28->y;
      v72 = v34[2] - v28->z;
      v82 = v70 - v7->m_gjk_origin.x;
      v83 = v71 - v7->m_gjk_origin.y;
      v84 = v72 - v7->m_gjk_origin.z;
      v35 = v82;
      v36 = v83;
      v37 = v84;
      v87 = v7->m_support_dir.x * v82 + v83 * v7->m_support_dir.y + v84 * v7->m_support_dir.z;
      v38 = 0.0;
      if ( v87 > 0.0 )
      {
        v39 = v87;
        if ( v7->m_upper_dist_sq <= 0.0 )
        {
          v38 = 0.0;
        }
        else
        {
          v7->m_flags |= 0x20u;
          v40 = v7->m_flags;
          v41 = v39 * v39;
          v38 = 0.0;
          lambda = v41;
          lambda = lambda / v7->m_upper_dist_sq;
          v42 = lambda;
          if ( v7->m_lower_dist_sq < (double)lambda )
          {
            v7->m_lower_dist_sq = lambda;
            if ( v40 & 1 )
            {
              lambda = v7->m_gjk_sep_thresh;
              lambda = lambda * lambda;
              if ( lambda < v42 )
                return 0;
            }
          }
        }
      }
      v14 = v7->m_gjk_iter == 0;
      HIBYTE(new_index) = 0;
      if ( !v14 && v38 < v7->m_lower_dist_sq )
      {
        lambda = 1.0 - CONV_THRESH;
        lambda = lambda * lambda;
        if ( v7->m_lower_dist_sq > lambda * v7->m_upper_dist_sq )
          HIBYTE(new_index) = 1;
        v43 = 0;
        v44 = 1;
        v45 = &v7->m_w_verts[0].z;
        do
        {
          if ( HIBYTE(new_index) )
            break;
          if ( v44 & v7->m_last_w_set )
          {
            v73 = v35 - *(v45 - 2);
            v74 = v36 - *(v45 - 1);
            v75 = v37 - *v45;
            lambda = v74 * v74 + v73 * v73 + v75 * v75;
            if ( lambda < 0.0000010000001 )
              HIBYTE(new_index) = 1;
          }
          ++v43;
          v45 += 4;
          v44 *= 2;
        }
        while ( v43 < 4 );
      }
      if ( !(v7->m_flags & 4) && v87 > 0.0 )
      {
        lambda = v87 * v87;
        v46 = lambda;
        lambda = w.w * w.w;
        if ( lambda * v7->m_upper_dist_sq <= v46 )
          break;
      }
LABEL_56:
      if ( HIBYTE(new_index) )
        return 1;
      v50 = v86;
      v51 = 2 * (v86 + 10);
      *(&v7->cg2_to_cg1_xform.x.x + 2 * v51) = v35;
      *(&v7->cg2_to_cg1_xform.x.y + 2 * v51) = v36;
      *(&v7->cg2_to_cg1_xform.x.z + 2 * v51) = v37;
      v7->m_w_set |= 1 << v50;
      v7->m_last_w_set = v7->m_w_set;
      v52 = backup1((int)&ray_end_dist_numer, v7, v50, 0);
      v7->m_w_set = v52;
      if ( v52 == 15 )
      {
        if ( v7->m_flags & 8 && 0.0 != v7->m_continuous_collision_lambda )
        {
          tlWarning("m_continuous_collision_lambda problem\n");
          v7->m_flags |= 0x40u;
        }
        return 2;
      }
      phys_gjk_info::comp_v(v7, v52, &v7->m_support_dir);
      if ( ++v7->m_gjk_iter >= 30 )
      {
        tlWarning("gjk reached the maximum number of iterations.\n");
        v53 = 0.0 < v7->m_lower_dist_sq;
        v7->m_flags |= 0x40u;
        result = 2;
        if ( v53 )
          result = 1;
        return result;
      }
    }
    lambda = sqrt(v7->m_upper_dist_sq);
    v47 = 0.0;
    if ( lambda <= 0.0 )
    {
      if ( _tlAssert("source/phys_gjk.cpp", 1813, "nsupport_dir > 0.0f", (const char *)&pBlock) )
        __debugbreak();
      v47 = 0.0;
    }
    support_dir_moveback = v7->m_support_dir.x * v7->m_cg1_relative_translation_loc.x
                         + v7->m_support_dir.y * v7->m_cg1_relative_translation_loc.y
                         + v7->m_support_dir.z * v7->m_cg1_relative_translation_loc.z;
    support_dir_moveback = -support_dir_moveback;
    v87 = v87 - lambda * w.w;
    v48 = support_dir_moveback;
    if ( support_dir_moveback <= v47 )
    {
      if ( v47 < v87 )
      {
        support_dir_moveback = v7->m_gjk_sep_thresh;
        v49 = v7->m_lower_dist_sq;
        support_dir_moveback = support_dir_moveback * support_dir_moveback;
        if ( support_dir_moveback < v49 )
          return 0;
        v7->m_flags |= 5u;
      }
LABEL_55:
      v37 = v84;
      v36 = v83;
      v35 = v82;
      goto LABEL_56;
    }
    v54 = v87;
    if ( v87 < v47 )
      goto LABEL_55;
    support_dir_moveback = v7->m_support_dir.x * v7->m_gjk_origin.x
                         + v7->m_support_dir.y * v7->m_gjk_origin.y
                         + v7->m_support_dir.z * v7->m_gjk_origin.z;
    v87 = (support_dir_moveback + v54) / v48;
    if ( v7->m_continuous_collision_lambda + 0.00009999999747378752 >= v87 )
      goto LABEL_55;
    if ( d->m_end_time < (double)v87 )
      break;
    v58 = v87;
    v56 = 0.00009999999747378752;
LABEL_68:
    if ( v58 - v7->m_continuous_collision_lambda <= v56 )
      v7->m_flags |= 5u;
    v7->m_continuous_collision_lambda = v58;
    support_dir_moveback = -v58;
    v79 = support_dir_moveback * v7->m_cg1_relative_translation_loc.x;
    v80 = support_dir_moveback * v7->m_cg1_relative_translation_loc.y;
    v81 = support_dir_moveback * v7->m_cg1_relative_translation_loc.z;
    v7->m_gjk_origin.x = v79;
    v7->m_gjk_origin.y = v80;
    v7->m_gjk_origin.z = v81;
    v59 = ++v7->m_cc_reset_iter;
    v7->m_lower_dist_sq = -34.0;
    v7->m_upper_dist_sq = 34.0;
    if ( v59 > 1 )
      v7->m_flags |= 0x10u;
    if ( v59 >= MAX_CC_RESET_ITERS )
      v7->m_flags |= 5u;
    if ( !v7->m_w_set )
      v7->m_w_set = 1 << v86;
    if ( !phys_gjk_info::init_gjk(v7, d, &v7->m_support_dir, 1)
      && _tlAssert("source/phys_gjk.cpp", 1918, "did_init", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( !v7->m_w_set && _tlAssert("source/phys_gjk.cpp", 1919, "m_w_set != 0", (const char *)&pBlock) )
      __debugbreak();
    if ( v7->m_last_w_set != v7->m_w_set
      && _tlAssert("source/phys_gjk.cpp", 1920, "m_last_w_set == m_w_set", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    ++v7->m_gjk_iter;
  }
  support_dir_moveback = v54 - v48 * d->m_end_time + support_dir_moveback;
  v55 = support_dir_moveback;
  support_dir_moveback = v7->m_gjk_sep_thresh * lambda;
  if ( support_dir_moveback >= v55 )
  {
    v56 = 0.00009999999747378752;
    v57 = d->m_end_time;
    v7->m_flags |= 5u;
    v87 = v57;
    v58 = v87;
    goto LABEL_68;
  }
  if ( v55 <= v47 && _tlAssert("source/phys_gjk.cpp", 1850, "ray_end_dist_numer > 0.0f", (const char *)&pBlock) )
    __debugbreak();
  return 0;
}

/*
==============
phys_gjk_info::collide
==============
*/
phys_gjk_info::gjk_retval_e __userpurge phys_gjk_info::collide@<eax>(phys_gjk_info *this@<ecx>, int a2@<ebp>, phys_gjk_input *d)
{
  phys_gjk_info *v3; // esi
  phys_gjk_info::gjk_retval_e result; // eax
  int v5; // eax
  phys_gjk_cache_info *v6; // eax
  phys_vec3 *v7; // eax
  float v8; // edx
  float v9; // ecx
  char v10; // al
  double v11; // st7
  phys_gjk_geom *v12; // ecx
  phys_vec3 *v13; // eax
  double v14; // st7
  bool v15; // ST0C_1
  phys_gjk_cache_info *v16; // eax
  int v17; // [esp-5Ch] [ebp-8Ch]
  int v18; // [esp-4Ch] [ebp-7Ch]
  float v19; // [esp-3Ch] [ebp-6Ch]
  float v20; // [esp-38h] [ebp-68h]
  float v21; // [esp-34h] [ebp-64h]
  float v22; // [esp-2Ch] [ebp-5Ch]
  float v23; // [esp-28h] [ebp-58h]
  float v24; // [esp-24h] [ebp-54h]
  float v25; // [esp-1Ch] [ebp-4Ch]
  float v26; // [esp-18h] [ebp-48h]
  float v27; // [esp-14h] [ebp-44h]
  double v28; // [esp-Ch] [ebp-3Ch]
  float v29; // [esp-8h] [ebp-38h]
  float v30; // [esp-4h] [ebp-34h]
  phys_vec3 w; // [esp+0h] [ebp-30h]
  phys_vec3 support_dir; // [esp+10h] [ebp-20h]
  phys_gjk_info::gjk_retval_e v33; // [esp+20h] [ebp-10h]
  int v34; // [esp+24h] [ebp-Ch]
  const float nsupport_dir_sq; // [esp+28h] [ebp-8h]
  float retaddr; // [esp+30h] [ebp+0h]

  v34 = a2;
  nsupport_dir_sq = retaddr;
  v3 = this;
  this->m_gjk_origin.x = PHYS_ZERO_VEC_94.x;
  this->m_gjk_origin.y = PHYS_ZERO_VEC_94.y;
  this->m_gjk_origin.z = PHYS_ZERO_VEC_94.z;
  v3->m_flags |= 1u;
  phys_gjk_info::get_initial_support_dir(this, (phys_vec3 *)&v28, d);
  if ( v3->m_flags & 8 )
    result = phys_gjk_info::gjk_ray_cast(
               v3,
               COERCE_FLOAT(&v34),
               &d->m_cg1_translation.x,
               (int)v3,
               d,
               (phys_vec3 *)&v28,
               0);
  else
    result = phys_gjk_info::gjk(v3, COERCE_FLOAT(&v34), &d->m_cg1_translation.x, (int)v3, d, (phys_vec3 *)&v28, 0);
  v33 = result;
  if ( result == 3 )
  {
    if ( _tlAssert("source/phys_gjk.cpp", 2062, "retv != GJK_INVALID", (const char *)&pBlock) )
      __debugbreak();
LABEL_10:
    if ( _tlAssert("source/phys_gjk.cpp", 2066, "retv == GJK_SEPARATED || retv == GJK_VALID", (const char *)&pBlock) )
      __debugbreak();
    return v33;
  }
  if ( result != 2 )
  {
    if ( result == GJK_SEPARATED || result == 1 )
      return result;
    goto LABEL_10;
  }
  v5 = v3->m_flags;
  if ( v5 & 2 )
    return 2;
  if ( v5 & 8 && 0.0 != v3->m_continuous_collision_lambda )
    tlWarning("m_continuous_collision_lambda problem\n");
  v3->m_continuous_collision_lambda = 0.0;
  v6 = d->gjk_ci;
  if ( v6 && v6->m_flags & 4 )
    v7 = (phys_vec3 *)&v28;
  else
    v7 = gjk_sep_dir::comp_sep_dir((phys_vec3 *)&v19, d, v3);
  v8 = v7->y;
  w.y = v7->x;
  v9 = v7->z;
  w.z = v8;
  w.w = v9;
  support_dir.x = v7->w;
  support_dir.w = v8 * v8 + w.y * w.y + v9 * v9;
  if ( support_dir.w >= 0.0000000099999991 )
    goto LABEL_28;
  support_dir.w = v30 * v30 + v29 * v29 + *(float *)&v28 * *(float *)&v28;
  if ( support_dir.w >= 0.0000000099999991 )
  {
    w.y = *(float *)&v28;
    w.z = v29;
    w.w = v30;
LABEL_28:
    v11 = w.z;
    v3->m_flags &= 0xFFFFFFFE;
    v33 = 0;
    support_dir.w = v11 * v11 + w.y * w.y + w.w * w.w;
    while ( 1 )
    {
      v12 = d->gjk_cg1;
      ++v33;
      v22 = -w.y;
      v23 = -w.z;
      v24 = -w.w;
      ((void (__stdcall *)(float *, float *, int *))v12->vfptr->support)(&v22, &v19, &v18);
      v13 = phys_gjk_geom::support_only(
              d->gjk_cg2,
              (phys_vec3 *)&v17,
              &v3->cg2_to_cg1_xform,
              (phys_vec3 *)((char *)&w + 4));
      *(float *)&v28 = v19 - v13->x;
      v29 = v20 - v13->y;
      v30 = v21 - v13->z;
      support_dir.z = sqrt(support_dir.w);
      v14 = 17.0 / support_dir.z;
      v15 = (signed int)v33 > 1;
      support_dir.z = v30 * w.w + *(float *)&v28 * w.y + v29 * w.z;
      support_dir.z = -(v14 - support_dir.z / support_dir.w);
      v25 = w.y * support_dir.z;
      v26 = w.z * support_dir.z;
      v27 = w.w * support_dir.z;
      v3->m_gjk_origin.x = v25;
      v3->m_gjk_origin.y = v26;
      v3->m_gjk_origin.z = v27;
      if ( phys_gjk_info::gjk(
             v3,
             COERCE_FLOAT(&v34),
             &d->m_cg1_translation.x,
             (int)v3,
             d,
             (phys_vec3 *)((char *)&w + 4),
             v15) == 2 )
      {
        tlWarning("gjk has possibly failed.\n");
        if ( v33 != 1 )
          break;
        v16 = d->gjk_ci;
        if ( !v16 )
          break;
        if ( !(v16->m_flags & 8) )
          break;
        v16->m_flags &= 0xFFFFFFF7;
        if ( phys_gjk_info::gjk(
               v3,
               COERCE_FLOAT(&v34),
               &d->m_cg1_translation.x,
               (int)v3,
               d,
               (phys_vec3 *)((char *)&w + 4),
               0) == 2 )
          break;
      }
      phys_gjk_info::comp_v(v3, v3->m_w_set, (phys_vec3 *)((char *)&w + 4));
      support_dir.w = w.z * w.z + w.y * w.y + w.w * w.w;
      if ( v3->m_gjk_pen_thresh_sq > (double)support_dir.w
        && _tlAssert(
             "source/phys_gjk.cpp",
             2119,
             "AbsSquared(support_dir) >= m_gjk_pen_thresh_sq",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      support_dir.z = 1.0 - SEP_CONV_THRESH;
      support_dir.z = support_dir.z * support_dir.z;
      if ( support_dir.z * v3->m_lower_dist_sq < 289.0 || (signed int)v33 >= 10 )
        return 2;
    }
    v10 = _tlAssert("source/phys_gjk.cpp", 2114, "0", "gjk has failed.");
    goto LABEL_24;
  }
  v10 = _tlAssert("source/phys_gjk.cpp", 2084, "0", "initial support dir invalid.");
LABEL_24:
  if ( v10 )
    __debugbreak();
  return 3;
}

/*
==============
phys_gjk_info::phys_collide_do_gjk_collide
==============
*/
bool __userpurge phys_gjk_info::phys_collide_do_gjk_collide@<al>(phys_gjk_info *this@<ecx>, int a2@<ebp>, phys_gjk_input *d)
{
  phys_gjk_info *v3; // esi
  double v4; // st7
  phys_mat44 *v5; // eax
  float v6; // ST20_4
  float v7; // ST24_4
  float v8; // ST28_4
  double v9; // st6
  double v10; // st7
  float v11; // ST20_4
  float v12; // ST24_4
  float v13; // ST28_4
  float v14; // ST3C_4
  double v15; // st7
  phys_gjk_info::gjk_retval_e v16; // eax
  char v17; // al
  phys_gjk_cache_info *v18; // eax
  bool result; // al
  int v20; // ecx
  phys_gjk_cache_info *v21; // eax
  signed int v22; // eax
  float v23; // ST3C_4
  float v24; // ST3C_4
  float v25; // ST20_4
  float v26; // ST24_4
  float v27; // ST28_4
  float v28; // ST3C_4
  float v29; // ST20_4
  float v30; // ST24_4
  float v31; // ST28_4
  double v32; // st7
  double v33; // st7
  double v34; // st7
  double v35; // st7
  double v36; // st7
  double v37; // st7
  float v38; // [esp-4h] [ebp-10h]
  phys_gjk_info::gjk_retval_e v39; // [esp-4h] [ebp-10h]
  int v40; // [esp+0h] [ebp-Ch]
  int v41; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v40 = a2;
  v41 = retaddr;
  v3 = this;
  if ( (d->m_start_time < 0.0 || d->m_end_time < (double)d->m_start_time || d->m_end_time > 1.0)
    && _tlAssert(
         "source/phys_gjk.cpp",
         2180,
         "(d->m_start_time >= 0.0f) && (d->m_start_time <= d->m_end_time) && (d->m_end_time <= 1.0f)",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v4 = d->m_start_time;
  v3->m_flags = 0;
  phys_full_inv_multiply_mat(COERCE_FLOAT(&v40), &v3->cg2_to_cg1_xform, d->cg1_to_world_xform, d->cg2_to_world_xform);
  if ( d->m_continuous_collision )
  {
    v5 = d->cg1_to_world_xform;
    v6 = d->m_cg1_translation.x - d->m_cg2_translation.x;
    v7 = d->m_cg1_translation.y - d->m_cg2_translation.y;
    v8 = d->m_cg1_translation.z - d->m_cg2_translation.z;
    v9 = v7;
    v10 = v6;
    v11 = v5->x.z * v8 + v5->x.x * v6 + v5->x.y * v7;
    v12 = v5->y.y * v7 + v5->y.x * v10 + v5->y.z * v8;
    v13 = v10 * v5->z.x + v9 * v5->z.y + v8 * v5->z.z;
    v3->m_cg1_relative_translation_loc.x = v11;
    v3->m_cg1_relative_translation_loc.y = v12;
    v3->m_cg1_relative_translation_loc.z = v13;
    v3->m_flags |= 8u;
  }
  v14 = d->cg2_radius + d->cg1_radius;
  v3->m_geom_radii_sum = v14;
  v38 = v14 + d->m_sep_thresh;
  v3->m_gjk_sep_thresh = v38;
  if ( d->m_intersection_test_only )
  {
    v3->m_flags |= 2u;
    v15 = v38 * v38;
  }
  else
  {
    v15 = 0.0011560001;
  }
  v3->m_gjk_pen_thresh_sq = v15;
  v16 = phys_gjk_info::collide(v3, (int)&v40, d);
  v39 = v16;
  if ( v16 == 3 )
  {
    v17 = _tlAssert("source/phys_gjk.cpp", 2211, "0", "phys_gjk failed");
LABEL_13:
    if ( v17 )
      __debugbreak();
    v18 = d->gjk_ci;
    if ( v18 )
    {
      v18->m_flags |= 1u;
      d->gjk_ci->m_flags &= 0xFFFFFFFB;
      d->gjk_ci->m_flags &= 0xFFFFFFF7;
    }
    return 0;
  }
  if ( v16 == GJK_SEPARATED )
  {
    phys_gjk_info::gjk_cache_update_test_only_valid(v3, d);
    return 0;
  }
  if ( !(v3->m_flags & 2) )
  {
    if ( v16 != 1
      && v16 != 2
      && _tlAssert("source/phys_gjk.cpp", 2241, "retv == GJK_VALID || retv == GJK_PENETRATING", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v22 = v3->m_w_set;
    if ( v22 == 15 )
    {
      v17 = _tlAssert("source/phys_gjk.cpp", 2244, "0", "phys_gjk failed");
      goto LABEL_13;
    }
    if ( (v22 >= 15 || v22 <= 0)
      && _tlAssert("source/phys_gjk.cpp", 2248, "m_w_set < 15 && m_w_set > 0", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    phys_gjk_info::comp_closest_points(v3, v3->m_w_set, &v3->cg1_cinfo_loc.m_p1, &v3->cg1_cinfo_loc.m_p2);
    phys_gjk_info::comp_v(v3, v3->m_w_set, &v3->cg1_cinfo_loc.m_n);
    v23 = 1.0 / Abs((vec3_t *)&v3->cg1_cinfo_loc.m_n);
    v3->cg1_cinfo_loc.m_n.x = v23 * v3->cg1_cinfo_loc.m_n.x;
    v3->cg1_cinfo_loc.m_n.y = v23 * v3->cg1_cinfo_loc.m_n.y;
    v3->cg1_cinfo_loc.m_n.z = v23 * v3->cg1_cinfo_loc.m_n.z;
    v24 = d->cg1_radius;
    v25 = v24 * v3->cg1_cinfo_loc.m_n.x;
    v26 = v24 * v3->cg1_cinfo_loc.m_n.y;
    v27 = v24 * v3->cg1_cinfo_loc.m_n.z;
    v3->cg1_cinfo_loc.m_p1.x = v3->cg1_cinfo_loc.m_p1.x - v25;
    v3->cg1_cinfo_loc.m_p1.y = v3->cg1_cinfo_loc.m_p1.y - v26;
    v3->cg1_cinfo_loc.m_p1.z = v3->cg1_cinfo_loc.m_p1.z - v27;
    v28 = d->cg2_radius;
    v29 = v28 * v3->cg1_cinfo_loc.m_n.x;
    v30 = v28 * v3->cg1_cinfo_loc.m_n.y;
    v31 = v28 * v3->cg1_cinfo_loc.m_n.z;
    v3->cg1_cinfo_loc.m_p2.x = v3->cg1_cinfo_loc.m_p2.x + v29;
    v3->cg1_cinfo_loc.m_p2.y = v30 + v3->cg1_cinfo_loc.m_p2.y;
    v3->cg1_cinfo_loc.m_p2.z = v31 + v3->cg1_cinfo_loc.m_p2.z;
    v32 = v3->cg1_cinfo_loc.m_p1.x;
    v33 = v3->cg1_cinfo_loc.m_p1.y;
    v34 = v3->cg1_cinfo_loc.m_p1.z;
    v35 = v3->cg1_cinfo_loc.m_p2.x;
    v36 = v3->cg1_cinfo_loc.m_p2.y;
    v37 = v3->cg1_cinfo_loc.m_p2.z;
    phys_gjk_info::gjk_cache_update_colliding(v3, d);
    return 1;
  }
  if ( v16 != 1 && v16 != 2 )
  {
    if ( _tlAssert("source/phys_gjk.cpp", 2222, "retv == GJK_VALID || retv == GJK_PENETRATING", (const char *)&pBlock) )
      __debugbreak();
    v16 = v39;
  }
  v20 = v3->m_w_set;
  if ( v20 == 15 )
  {
    v21 = d->gjk_ci;
    if ( v21 )
    {
      v21->m_flags |= 1u;
      d->gjk_ci->m_flags &= 0xFFFFFFFB;
      d->gjk_ci->m_flags &= 0xFFFFFFF7;
      return 1;
    }
    return 1;
  }
  if ( v16 == 1 )
  {
    phys_gjk_info::comp_v(v3, v20, &v3->m_support_dir);
    phys_gjk_info::gjk_cache_update_test_only_valid(v3, d);
    result = 1;
  }
  else
  {
    if ( v16 != 2 && _tlAssert("source/phys_gjk.cpp", 2234, "retv == GJK_PENETRATING", (const char *)&pBlock) )
      __debugbreak();
    phys_gjk_info::gjk_cache_update_test_only_penetrating(v3, d);
    result = 1;
  }
  return result;
}

/*
==============
phys_gjk_info::get_flag
==============
*/
int __thiscall phys_gjk_info::get_flag(phys_gjk_info *this, const int f)
{
  return f & this->m_flags;
}

/*
==============
phys_gjk_info::compress_verts
==============
*/
int __thiscall phys_gjk_info::compress_verts(phys_gjk_info *this, const int w_set)
{
  int result; // eax
  int v3; // edx
  int v4; // edx
  int v5; // edx
  int v6; // edx
  int v7; // edx
  int v8; // edx
  int v9; // edx
  int v10; // edx
  int v11; // edx
  int v12; // edx
  int v13; // edx
  int v14; // edx

  result = 0;
  if ( w_set & 1 )
  {
    result = 1;
    this->m_a_verts[0].x = this->m_a_verts[0].x;
    this->m_a_verts[0].y = this->m_a_verts[0].y;
    this->m_a_verts[0].z = this->m_a_verts[0].z;
    this->m_b_verts[0].x = this->m_b_verts[0].x;
    this->m_b_verts[0].y = this->m_b_verts[0].y;
    this->m_b_verts[0].z = this->m_b_verts[0].z;
    this->m_a_inds[0].x = this->m_a_inds[0].x;
    this->m_a_inds[0].y = this->m_a_inds[0].y;
    this->m_a_inds[0].z = this->m_a_inds[0].z;
    this->m_b_inds[0].x = this->m_b_inds[0].x;
    this->m_b_inds[0].y = this->m_b_inds[0].y;
    this->m_b_inds[0].z = this->m_b_inds[0].z;
  }
  if ( w_set & 2 )
  {
    v3 = 2 * (result + 14);
    *(&this->cg2_to_cg1_xform.x.x + 2 * v3) = this->m_a_verts[1].x;
    *(&this->cg2_to_cg1_xform.x.y + 2 * v3) = this->m_a_verts[1].y;
    *(&this->cg2_to_cg1_xform.x.z + 2 * v3) = this->m_a_verts[1].z;
    v4 = 2 * (result + 18);
    *(&this->cg2_to_cg1_xform.x.x + 2 * v4) = this->m_b_verts[1].x;
    *(&this->cg2_to_cg1_xform.x.y + 2 * v4) = this->m_b_verts[1].y;
    *(&this->cg2_to_cg1_xform.x.z + 2 * v4) = this->m_b_verts[1].z;
    v5 = 2 * (result + 22);
    *(&this->cg2_to_cg1_xform.x.x + 2 * v5) = this->m_a_inds[1].x;
    *(&this->cg2_to_cg1_xform.x.y + 2 * v5) = this->m_a_inds[1].y;
    *(&this->cg2_to_cg1_xform.x.z + 2 * v5) = this->m_a_inds[1].z;
    v6 = 2 * (result + 26);
    *(&this->cg2_to_cg1_xform.x.x + 2 * v6) = this->m_b_inds[1].x;
    ++result;
    *(&this->cg2_to_cg1_xform.x.y + 2 * v6) = this->m_b_inds[1].y;
    *(&this->cg2_to_cg1_xform.x.z + 2 * v6) = this->m_b_inds[1].z;
  }
  if ( w_set & 4 )
  {
    v7 = 2 * (result + 14);
    *(&this->cg2_to_cg1_xform.x.x + 2 * v7) = this->m_a_verts[2].x;
    *(&this->cg2_to_cg1_xform.x.y + 2 * v7) = this->m_a_verts[2].y;
    *(&this->cg2_to_cg1_xform.x.z + 2 * v7) = this->m_a_verts[2].z;
    v8 = 2 * (result + 18);
    *(&this->cg2_to_cg1_xform.x.x + 2 * v8) = this->m_b_verts[2].x;
    *(&this->cg2_to_cg1_xform.x.y + 2 * v8) = this->m_b_verts[2].y;
    *(&this->cg2_to_cg1_xform.x.z + 2 * v8) = this->m_b_verts[2].z;
    v9 = 2 * (result + 22);
    *(&this->cg2_to_cg1_xform.x.x + 2 * v9) = this->m_a_inds[2].x;
    *(&this->cg2_to_cg1_xform.x.y + 2 * v9) = this->m_a_inds[2].y;
    *(&this->cg2_to_cg1_xform.x.z + 2 * v9) = this->m_a_inds[2].z;
    v10 = 2 * (result + 26);
    *(&this->cg2_to_cg1_xform.x.x + 2 * v10) = this->m_b_inds[2].x;
    ++result;
    *(&this->cg2_to_cg1_xform.x.y + 2 * v10) = this->m_b_inds[2].y;
    *(&this->cg2_to_cg1_xform.x.z + 2 * v10) = this->m_b_inds[2].z;
  }
  if ( w_set & 8 )
  {
    v11 = 2 * (result + 14);
    *(&this->cg2_to_cg1_xform.x.x + 2 * v11) = this->m_a_verts[3].x;
    *(&this->cg2_to_cg1_xform.x.y + 2 * v11) = this->m_a_verts[3].y;
    *(&this->cg2_to_cg1_xform.x.z + 2 * v11) = this->m_a_verts[3].z;
    v12 = 2 * (result + 18);
    *(&this->cg2_to_cg1_xform.x.x + 2 * v12) = this->m_b_verts[3].x;
    *(&this->cg2_to_cg1_xform.x.y + 2 * v12) = this->m_b_verts[3].y;
    *(&this->cg2_to_cg1_xform.x.z + 2 * v12) = this->m_b_verts[3].z;
    v13 = 2 * (result + 22);
    *(&this->cg2_to_cg1_xform.x.x + 2 * v13) = this->m_a_inds[3].x;
    *(&this->cg2_to_cg1_xform.x.y + 2 * v13) = this->m_a_inds[3].y;
    *(&this->cg2_to_cg1_xform.x.z + 2 * v13) = this->m_a_inds[3].z;
    v14 = 2 * (result + 26);
    *(&this->cg2_to_cg1_xform.x.x + 2 * v14) = this->m_b_inds[3].x;
    ++result;
    *(&this->cg2_to_cg1_xform.x.y + 2 * v14) = this->m_b_inds[3].y;
    *(&this->cg2_to_cg1_xform.x.z + 2 * v14) = this->m_b_inds[3].z;
  }
  return result;
}

/*
==============
phys_gjk_info::comp_closest_points
==============
*/
void __thiscall phys_gjk_info::comp_closest_points(phys_gjk_info *this, const int w_set, phys_vec3 *a, phys_vec3 *b)
{
  float *v4; // eax
  double v5; // st6
  float v6; // ST30_4
  float v7; // ST34_4
  float v8; // ST38_4
  float v9; // ST20_4
  float v10; // ST24_4
  float v11; // ST28_4
  float v12; // ST48_4
  float v13; // ST30_4
  float v14; // ST34_4
  float v15; // ST38_4
  float v16; // ST20_4
  float v17; // ST24_4
  float v18; // ST28_4
  float v19; // ST48_4
  float v20; // ST30_4
  float v21; // ST34_4
  float v22; // ST38_4
  float v23; // ST20_4
  float v24; // ST24_4
  float v25; // ST28_4
  float v26; // ST48_4
  float v27; // ST30_4
  float v28; // ST34_4
  float v29; // ST38_4
  float v30; // ST20_4
  float v31; // ST24_4
  float v32; // ST28_4
  float v33; // ST48_4
  float v34; // [esp-4h] [ebp-10h]

  a->x = 0.0;
  a->y = 0.0;
  a->z = 0.0;
  b->x = 0.0;
  v4 = &this->cg2_to_cg1_xform.x.x + 5 * w_set + 150;
  b->y = 0.0;
  b->z = 0.0;
  v34 = 0.0;
  if ( w_set & 1 )
  {
    v5 = *v4;
    v6 = this->m_a_verts[0].x * v5;
    v7 = this->m_a_verts[0].y * v5;
    v8 = this->m_a_verts[0].z * v5;
    a->x = a->x + v6;
    a->y = a->y + v7;
    a->z = a->z + v8;
    v9 = this->m_b_verts[0].x * v5;
    v10 = this->m_b_verts[0].y * v5;
    v11 = this->m_b_verts[0].z * v5;
    b->x = b->x + v9;
    b->y = b->y + v10;
    b->z = v11 + b->z;
    v34 = v5 + 0.0;
  }
  if ( w_set & 2 )
  {
    v12 = v4[1];
    v13 = this->m_a_verts[1].x * v12;
    v14 = this->m_a_verts[1].y * v12;
    v15 = this->m_a_verts[1].z * v12;
    a->x = a->x + v13;
    a->y = a->y + v14;
    a->z = a->z + v15;
    v16 = this->m_b_verts[1].x * v12;
    v17 = this->m_b_verts[1].y * v12;
    v18 = this->m_b_verts[1].z * v12;
    b->x = b->x + v16;
    b->y = b->y + v17;
    b->z = v18 + b->z;
    v34 = v12 + v34;
  }
  if ( w_set & 4 )
  {
    v19 = v4[2];
    v20 = this->m_a_verts[2].x * v19;
    v21 = this->m_a_verts[2].y * v19;
    v22 = this->m_a_verts[2].z * v19;
    a->x = a->x + v20;
    a->y = a->y + v21;
    a->z = a->z + v22;
    v23 = this->m_b_verts[2].x * v19;
    v24 = this->m_b_verts[2].y * v19;
    v25 = this->m_b_verts[2].z * v19;
    b->x = b->x + v23;
    b->y = b->y + v24;
    b->z = v25 + b->z;
    v34 = v19 + v34;
  }
  if ( w_set & 8 )
  {
    v26 = v4[3];
    v27 = this->m_a_verts[3].x * v26;
    v28 = this->m_a_verts[3].y * v26;
    v29 = this->m_a_verts[3].z * v26;
    a->x = a->x + v27;
    a->y = a->y + v28;
    a->z = a->z + v29;
    v30 = this->m_b_verts[3].x * v26;
    v31 = this->m_b_verts[3].y * v26;
    v32 = this->m_b_verts[3].z * v26;
    b->x = b->x + v30;
    b->y = b->y + v31;
    b->z = v32 + b->z;
    v34 = v26 + v34;
  }
  if ( v34 < 0.0 && _tlAssert("source/phys_gjk.cpp", 173, "lambda_sum >= 0.0f", (const char *)&pBlock) )
    __debugbreak();
  v33 = 1.0 / v34;
  a->x = a->x * v33;
  a->y = a->y * v33;
  a->z = a->z * v33;
  b->x = b->x * v33;
  b->y = b->y * v33;
  b->z = v33 * b->z;
}

/*
==============
phys_gjk_info::get_initial_support_dir
==============
*/
phys_vec3 *__userpurge phys_gjk_info::get_initial_support_dir@<eax>(phys_gjk_info *this@<ecx>, int a2@<ebp>, phys_vec3 *result, phys_gjk_input *d)
{
  phys_gjk_cache_info *v4; // eax
  phys_gjk_info *v5; // esi
  phys_vec3 *v6; // eax
  phys_vec3 *v7; // eax
  phys_vec3 *v8; // eax
  phys_vec3 *(__thiscall *v9)(phys_gjk_geom *, phys_vec3 *); // edx
  float *v10; // eax
  float v11; // edx
  float v12; // ecx
  float v13; // edx
  int v14; // [esp-5Ch] [ebp-7Ch]
  int v15; // [esp-58h] [ebp-78h]
  int v16; // [esp-54h] [ebp-74h]
  int v17; // [esp-50h] [ebp-70h]
  int v18; // [esp-4Ch] [ebp-6Ch]
  int v19; // [esp-48h] [ebp-68h]
  int v20; // [esp-44h] [ebp-64h]
  int v21; // [esp-40h] [ebp-60h]
  int v22; // [esp-3Ch] [ebp-5Ch]
  int v23; // [esp-38h] [ebp-58h]
  int v24; // [esp-34h] [ebp-54h]
  int v25; // [esp-30h] [ebp-50h]
  int v26; // [esp-2Ch] [ebp-4Ch]
  int v27; // [esp-28h] [ebp-48h]
  int v28; // [esp-24h] [ebp-44h]
  int v29; // [esp-20h] [ebp-40h]
  float v30; // [esp-1Ch] [ebp-3Ch]
  float v31; // [esp-18h] [ebp-38h]
  float v32; // [esp-14h] [ebp-34h]
  int v33; // [esp-10h] [ebp-30h]
  float v34; // [esp-Ch] [ebp-2Ch]
  float v35; // [esp-8h] [ebp-28h]
  float v36; // [esp-4h] [ebp-24h]
  phys_vec3 dir; // [esp+0h] [ebp-20h]
  float v38; // [esp+10h] [ebp-10h]
  int v39; // [esp+14h] [ebp-Ch]
  int v40; // [esp+18h] [ebp-8h]
  int retaddr; // [esp+20h] [ebp+0h]

  v39 = a2;
  v40 = retaddr;
  v4 = d->gjk_ci;
  v5 = this;
  v38 = *(float *)&v4;
  if ( *(float *)&v4 != 0.0 && v4->m_flags & 4 )
  {
    phys_inv_multiply(result, d->cg1_to_world_xform, &v4->m_support_dir);
    v6 = result;
  }
  else
  {
    v7 = (phys_vec3 *)((int (__stdcall *)(int *, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))d->gjk_cg2->vfptr->get_center)(
                        &v26,
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        v21,
                        v22,
                        v23,
                        v24,
                        v25,
                        v26,
                        v27,
                        v28,
                        v29,
                        LODWORD(v30),
                        LODWORD(v31),
                        LODWORD(v32),
                        v33,
                        LODWORD(v34),
                        LODWORD(v35),
                        LODWORD(v36),
                        LODWORD(dir.x),
                        LODWORD(dir.y),
                        LODWORD(dir.z),
                        LODWORD(dir.w));
    v8 = phys_multiply((phys_vec3 *)&v22, &v5->cg2_to_cg1_xform, v7);
    v9 = d->gjk_cg1->vfptr->get_center;
    v30 = v8->x + v5->cg2_to_cg1_xform.w.x;
    v31 = v8->y + v5->cg2_to_cg1_xform.w.y;
    v32 = v8->z + v5->cg2_to_cg1_xform.w.z;
    v10 = (float *)((int (__stdcall *)(int *))v9)(&v18);
    v34 = *v10 - v30;
    v35 = v10[1] - v31;
    v36 = v10[2] - v32;
    v38 = v34 * v34 + v35 * v35 + v36 * v36;
    if ( v38 < 0.0000000099999991 )
    {
      if ( (pai_gjk_initial_support_dir.m_hits_total_count < dword_10E5908 || !dword_10E5908)
        && dword_10E5904 < dword_10E590C )
      {
        LODWORD(dir.w) = "degenerate gjk initial support dir.";
        LODWORD(dir.z) = "0";
        LODWORD(dir.y) = 2043;
        LODWORD(dir.x) = "source/phys_gjk.cpp";
        if ( byte_10E5910 )
        {
          PHYS_WARNING(
            (const char *)LODWORD(dir.x),
            SLODWORD(dir.y),
            (const char *)LODWORD(dir.z),
            (const char *)LODWORD(dir.w));
        }
        else if ( _tlAssert(
                    (const char *)LODWORD(dir.x),
                    SLODWORD(dir.y),
                    (const char *)LODWORD(dir.z),
                    (const char *)LODWORD(dir.w)) )
        {
          __debugbreak();
        }
      }
      _InterlockedExchangeAdd(&pai_gjk_initial_support_dir.m_hits_total_count, 1u);
      _InterlockedExchangeAdd(&dword_10E5904, 1u);
      v6 = result;
      *result = PHYS_X_VEC_94;
    }
    else
    {
      v6 = result;
      v11 = v35;
      result->x = v34;
      v12 = v36;
      result->y = v11;
      v13 = dir.x;
      result->z = v12;
      result->w = v13;
    }
  }
  return v6;
}

/*
==============
phys_gjk_info::gjk_cache_update_colliding
==============
*/
void __userpurge phys_gjk_info::gjk_cache_update_colliding(phys_gjk_info *this@<ecx>, int a2@<ebp>, phys_gjk_input *d)
{
  phys_gjk_info *v3; // edi
  phys_gjk_cache_info *v4; // eax
  phys_vec3 *v5; // eax
  phys_gjk_cache_info *v6; // ecx
  int v7; // ST1C_4
  phys_gjk_geom *v8; // edx
  phys_gjk_cache_info *v9; // ST08_4
  phys_gjk_geom *v10; // ST04_4
  float v11; // [esp-20h] [ebp-2Ch]
  float v12; // [esp-1Ch] [ebp-28h]
  float v13; // [esp-18h] [ebp-24h]
  float v14; // [esp-10h] [ebp-1Ch]
  float v15; // [esp-Ch] [ebp-18h]
  float v16; // [esp-8h] [ebp-14h]
  int v17; // [esp+0h] [ebp-Ch]
  int v18; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v17 = a2;
  v18 = retaddr;
  v3 = this;
  v4 = d->gjk_ci;
  if ( v4 )
  {
    v4->m_flags |= 1u;
    v5 = phys_multiply((phys_vec3 *)&v11, d->cg1_to_world_xform, &this->cg1_cinfo_loc.m_n);
    v6 = d->gjk_ci;
    v6->m_flags |= 4u;
    v6->m_support_dir.x = v5->x;
    v6->m_support_dir.y = v5->y;
    v6->m_support_dir.z = v5->z;
    v7 = v3->m_w_set;
    v8 = d->gjk_cg1;
    v9 = d->gjk_ci;
    v10 = d->gjk_cg2;
    v14 = v3->cg2_to_cg1_xform.x.y * v3->cg1_cinfo_loc.m_n.y
        + v3->cg1_cinfo_loc.m_n.x * v3->cg2_to_cg1_xform.x.x
        + v3->cg2_to_cg1_xform.x.z * v3->cg1_cinfo_loc.m_n.z;
    v15 = v3->cg2_to_cg1_xform.y.y * v3->cg1_cinfo_loc.m_n.y
        + v3->cg2_to_cg1_xform.y.x * v3->cg1_cinfo_loc.m_n.x
        + v3->cg2_to_cg1_xform.y.z * v3->cg1_cinfo_loc.m_n.z;
    v16 = v3->cg2_to_cg1_xform.z.y * v3->cg1_cinfo_loc.m_n.y
        + v3->cg2_to_cg1_xform.z.x * v3->cg1_cinfo_loc.m_n.x
        + v3->cg2_to_cg1_xform.z.z * v3->cg1_cinfo_loc.m_n.z;
    v11 = -v3->cg1_cinfo_loc.m_n.x;
    v12 = -v3->cg1_cinfo_loc.m_n.y;
    v13 = -v3->cg1_cinfo_loc.m_n.z;
    set_simplex(v8, v10, v9, (phys_vec3 *)&v11, (phys_vec3 *)&v14, v3->m_a_inds, v3->m_b_inds, v7);
  }
}

/*
==============
phys_gjk_info::gjk_cache_update_test_only_valid
==============
*/
void __userpurge phys_gjk_info::gjk_cache_update_test_only_valid(phys_gjk_info *this@<ecx>, int a2@<ebp>, phys_gjk_input *d)
{
  phys_gjk_cache_info *v3; // eax
  phys_vec3 *v4; // eax
  phys_gjk_cache_info *v5; // ecx
  int v6; // [esp-10h] [ebp-1Ch]
  int v7; // [esp+0h] [ebp-Ch]
  int v8; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v7 = a2;
  v8 = retaddr;
  v3 = d->gjk_ci;
  if ( v3 )
  {
    v3->m_flags |= 1u;
    v4 = phys_multiply((phys_vec3 *)&v6, d->cg1_to_world_xform, &this->m_support_dir);
    v5 = d->gjk_ci;
    v5->m_flags |= 4u;
    v5->m_support_dir.x = v4->x;
    v5->m_support_dir.y = v4->y;
    v5->m_support_dir.z = v4->z;
    d->gjk_ci->m_flags &= 0xFFFFFFF7;
  }
}

/*
==============
phys_gjk_info::gjk_cache_update_test_only_penetrating
==============
*/
void phys_gjk_info::gjk_cache_update_test_only_penetrating(phys_gjk_input *d)
{
  phys_gjk_cache_info *v2; // eax

  v2 = d->gjk_ci;
  if ( v2 )
  {
    v2->m_flags |= 1u;
    d->gjk_ci->m_flags &= 0xFFFFFFF7;
  }
}

/*
==============
phys_gjk_info::comp_v
==============
*/
void __userpurge phys_gjk_info::comp_v(phys_gjk_info *this@<ecx>, int a2@<ebp>, const int w_set, phys_vec3 *v)
{
  float *v4; // esi
  char v5; // cl
  signed int v6; // edi
  float *v7; // eax
  float *v8; // eax
  float *v9; // eax
  phys_vec3 *v10; // eax
  double v11; // st7
  float v12; // ST2C_4
  float v13; // ST2C_4
  float v14; // ST30_4
  float v15; // ST34_4
  double v16; // st7
  double v17; // st7
  float v18; // ST2C_4
  float v19; // ST2C_4
  float v20; // ST30_4
  float v21; // ST34_4
  float v22; // ST38_4
  signed int v23; // esi
  float *v24; // edi
  int v25; // esi
  float *v26; // eax
  float *v27; // ecx
  float v28; // ST2C_4
  float v29; // ST2C_4
  float v30; // ST30_4
  float v31; // ST34_4
  float v32; // [esp-Ch] [ebp-B4h]
  float v33; // [esp-4h] [ebp-ACh]
  float ne1_sq; // [esp+0h] [ebp-A8h]
  float v35; // [esp+4h] [ebp-A4h]
  float nnormal_sq; // [esp+8h] [ebp-A0h]
  float v37; // [esp+Ch] [ebp-9Ch]
  float v38; // [esp+10h] [ebp-98h]
  float v39; // [esp+14h] [ebp-94h]
  float v40; // [esp+14h] [ebp-94h]
  phys_vec3 normal; // [esp+18h] [ebp-90h]
  phys_vec3 side[3]; // [esp+28h] [ebp-80h]
  phys_vec3 list_w_vert[3]; // [esp+58h] [ebp-50h]
  const float nside_sq[3]; // [esp+88h] [ebp-20h]
  unsigned int v45; // [esp+98h] [ebp-10h]
  int v46; // [esp+9Ch] [ebp-Ch]
  int v47; // [esp+A0h] [ebp-8h]
  int retaddr; // [esp+A8h] [ebp+0h]

  v46 = a2;
  v47 = retaddr;
  v45 = (unsigned int)&v46 ^ __security_cookie;
  v4 = &this->cg2_to_cg1_xform.x.x;
  v5 = w_set;
  if ( w_set <= 0 || w_set >= 15 )
  {
    if ( _tlAssert("source/phys_gjk.cpp", 79, "w_set > 0 && w_set < 15", (const char *)&pBlock) )
      __debugbreak();
    v5 = w_set;
  }
  v6 = 0;
  if ( v5 & 1 )
  {
    v6 = 1;
    side[2].y = v4[40];
    side[2].z = v4[41];
    side[2].w = v4[42];
  }
  if ( v5 & 2 )
  {
    v7 = (float *)(&v46 + 4 * v6 - 20);
    *v7 = v4[44];
    ++v6;
    v7[1] = v4[45];
    v7[2] = v4[46];
  }
  if ( v5 & 4 )
  {
    v8 = (float *)(&v46 + 4 * v6 - 20);
    *v8 = v4[48];
    ++v6;
    v8[1] = v4[49];
    v8[2] = v4[50];
  }
  if ( v5 & 8 )
  {
    v9 = (float *)(&v46 + 4 * v6 - 20);
    *v9 = v4[52];
    ++v6;
    v9[1] = v4[53];
    v9[2] = v4[54];
  }
  if ( (v6 <= 0 || v6 >= 4)
    && _tlAssert("source/phys_gjk.cpp", 87, "list_w_vert_count > 0 && list_w_vert_count < 4", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( v6 != 1 )
  {
    list_w_vert[2].y = list_w_vert[0].y - side[2].y;
    list_w_vert[2].z = list_w_vert[0].z - side[2].z;
    list_w_vert[2].w = list_w_vert[0].w - side[2].w;
    if ( v6 == 2 )
    {
      v32 = list_w_vert[2].z * list_w_vert[2].z
          + list_w_vert[2].y * list_w_vert[2].y
          + list_w_vert[2].w * list_w_vert[2].w;
      if ( v32 <= 0.0 && _tlAssert("source/phys_gjk.cpp", 98, "ne1_sq > 0.0f", (const char *)&pBlock) )
        __debugbreak();
      v12 = list_w_vert[2].y * side[2].y + list_w_vert[2].z * side[2].z + list_w_vert[2].w * side[2].w;
      v13 = v12 / v32;
      v14 = list_w_vert[2].y * v13;
      v15 = list_w_vert[2].z * v13;
      v39 = list_w_vert[2].w * v13;
      list_w_vert[2].y = side[2].y - v14;
      list_w_vert[2].z = side[2].z - v15;
      v16 = side[2].w;
LABEL_39:
      v10 = v;
      list_w_vert[2].w = v16 - v39;
      v->x = list_w_vert[2].y;
      v->y = list_w_vert[2].z;
      v11 = list_w_vert[2].w;
      goto LABEL_40;
    }
    if ( v6 != 3 && _tlAssert("source/phys_gjk.cpp", 103, "list_w_vert_count == 3", (const char *)&pBlock) )
      __debugbreak();
    v33 = list_w_vert[1].y - side[2].y;
    ne1_sq = list_w_vert[1].z - side[2].z;
    v35 = list_w_vert[1].w - side[2].w;
    v37 = v35 * list_w_vert[2].z - ne1_sq * list_w_vert[2].w;
    v38 = list_w_vert[2].w * v33 - v35 * list_w_vert[2].y;
    v40 = ne1_sq * list_w_vert[2].y - list_w_vert[2].z * v33;
    nnormal_sq = v38 * v38 + v37 * v37 + v40 * v40;
    if ( nnormal_sq > 0.010000001 )
    {
      v17 = nnormal_sq;
      v10 = v;
      v18 = v38 * side[2].z + v37 * side[2].y + v40 * side[2].w;
      v19 = v18 / v17;
      v20 = v37 * v19;
      v21 = v38 * v19;
      v22 = v19 * v40;
      v->x = v20;
      v->y = v21;
      v11 = v22;
      goto LABEL_40;
    }
    normal.y = list_w_vert[2].y;
    side[0].y = list_w_vert[1].y - list_w_vert[0].y;
    normal.z = list_w_vert[2].z;
    normal.w = list_w_vert[2].w;
    side[0].x = nside_sq[0];
    side[0].z = list_w_vert[1].z - list_w_vert[0].z;
    side[0].w = list_w_vert[1].w - list_w_vert[0].w;
    side[1].y = -v33;
    side[1].z = -ne1_sq;
    side[1].w = -v35;
    list_w_vert[2].z = list_w_vert[2].z * list_w_vert[2].z
                     + list_w_vert[2].y * list_w_vert[2].y
                     + list_w_vert[2].w * list_w_vert[2].w;
    list_w_vert[2].w = side[0].z * side[0].z + side[0].y * side[0].y + side[0].w * side[0].w;
    nside_sq[0] = side[1].z * side[1].z + side[1].y * side[1].y + side[1].w * side[1].w;
    if ( list_w_vert[2].w > (double)list_w_vert[2].z )
    {
      v23 = 1;
      if ( nside_sq[0] <= (double)list_w_vert[2].w )
        goto LABEL_35;
    }
    else if ( nside_sq[0] <= (double)list_w_vert[2].z )
    {
      v23 = 0;
      goto LABEL_35;
    }
    v23 = 2;
LABEL_35:
    v24 = (float *)(&v46 + v23 - 7);
    if ( *v24 <= 0.0 && _tlAssert("source/phys_gjk.cpp", 137, "nside_sq[side_i] > 0.0f", (const char *)&pBlock) )
      __debugbreak();
    v25 = 2 * v23;
    v26 = (float *)(&v46 + 2 * v25 - 32);
    v27 = (float *)(&v46 + 2 * v25 - 20);
    v28 = *v26 * *v27 + v27[1] * v26[1] + v27[2] * v26[2];
    v29 = v28 / *v24;
    v30 = *v26 * v29;
    v31 = v26[1] * v29;
    v39 = v29 * v26[2];
    list_w_vert[2].y = *v27 - v30;
    list_w_vert[2].z = v27[1] - v31;
    v16 = v27[2];
    goto LABEL_39;
  }
  v10 = v;
  v->x = side[2].y;
  v->y = side[2].z;
  v11 = side[2].w;
LABEL_40:
  v10->z = v11;
}

/*
==============
phys_gjk_info::init_gjk
==============
*/
int __userpurge phys_gjk_info::init_gjk@<eax>(phys_gjk_info *this@<ecx>, int a2@<ebp>, phys_gjk_input *d, phys_vec3 *initial_support_dir, const bool in_separation_loop)
{
  phys_gjk_info *v5; // esi
  int v6; // eax
  phys_gjk_cache_info *v7; // ecx
  phys_vec3 *v8; // edi
  phys_vec3 *v9; // eax
  double v10; // st7
  bool v11; // zf
  int v12; // eax
  int result; // eax
  int v14; // [esp-30h] [ebp-3Ch]
  float v15; // [esp-20h] [ebp-2Ch]
  float v16; // [esp-1Ch] [ebp-28h]
  float v17; // [esp-18h] [ebp-24h]
  int v18; // [esp-8h] [ebp-14h]
  int v19; // [esp-4h] [ebp-10h]
  int v20; // [esp+0h] [ebp-Ch]
  int v21; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v20 = a2;
  v21 = retaddr;
  v5 = this;
  if ( in_separation_loop )
  {
    v6 = phys_gjk_info::compress_verts(this, this->m_w_set);
  }
  else
  {
    v7 = d->gjk_ci;
    if ( !v7 || !(v7->m_flags & 8) )
      goto LABEL_11;
    v8 = v5->m_b_verts;
    get_simplex(d->gjk_cg1, d->gjk_cg2, v7, v5->m_a_verts, v5->m_a_inds, v5->m_b_verts, v5->m_b_inds, &v19);
    v6 = v19;
    if ( v19 > 0 )
    {
      v18 = v19;
      do
      {
        v9 = phys_multiply((phys_vec3 *)&v14, &v5->cg2_to_cg1_xform, v8);
        v10 = v9->x + v5->cg2_to_cg1_xform.w.x;
        ++v8;
        v11 = v18-- == 1;
        v15 = v10;
        v16 = v9->y + v5->cg2_to_cg1_xform.w.y;
        v17 = v9->z + v5->cg2_to_cg1_xform.w.z;
        v8[-1].x = v15;
        v8[-1].y = v16;
        v8[-1].z = v17;
      }
      while ( !v11 );
      v6 = v19;
    }
  }
  if ( v6 )
  {
    v12 = phys_gjk_info::seed_simplex(v5, v6);
    v5->m_w_set = v12;
    phys_gjk_info::comp_v(v5, (int)&v20, v12, &v5->m_support_dir);
    v5->m_last_w_set = v5->m_w_set;
    return 1;
  }
LABEL_11:
  v5->m_support_dir.x = initial_support_dir->x;
  v5->m_support_dir.y = initial_support_dir->y;
  result = 0;
  v5->m_support_dir.z = initial_support_dir->z;
  v5->m_last_w_set = 0;
  v5->m_w_set = 0;
  return result;
}

