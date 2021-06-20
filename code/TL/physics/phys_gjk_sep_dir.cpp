/*
==============
gjk_sep_dir::comp_sep_dir
==============
*/
phys_vec3 *__usercall gjk_sep_dir::comp_sep_dir@<eax>(int a1@<ebp>, float *a2@<edi>, float *a3@<esi>, phys_vec3 *result, phys_gjk_input *m_pcd, phys_gjk_info *m_gjk_info)
{
  float *v6; // edi
  void (***v7)(void); // ecx
  phys_vec3 *v8; // eax
  double v9; // st7
  double v10; // st6
  double v11; // st5
  double v12; // st4
  double v13; // st3
  double v14; // st2
  const int *v15; // esi
  float *v16; // edx
  float *v17; // ecx
  float *v18; // edi
  float *v19; // eax
  double v20; // st6
  float *v21; // edi
  double v22; // st6
  double v23; // st5
  double v24; // st4
  double v25; // st5
  double v26; // st4
  double v27; // st5
  float v28; // ecx
  phys_vec3 *v29; // eax
  float v30; // ecx
  float v31; // edx
  float v32; // ecx
  float *v33; // [esp-5Ch] [ebp-31Ch]
  float *v34; // [esp-58h] [ebp-318h]
  int *v35; // [esp-54h] [ebp-314h]
  int v36; // [esp-4Ch] [ebp-30Ch]
  int v37; // [esp-3Ch] [ebp-2FCh]
  int v38; // [esp-2Ch] [ebp-2ECh]
  float v39; // [esp-1Ch] [ebp-2DCh]
  float v40; // [esp-18h] [ebp-2D8h]
  float v41; // [esp-14h] [ebp-2D4h]
  float v42; // [esp-Ch] [ebp-2CCh]
  float v43; // [esp-8h] [ebp-2C8h]
  float v44; // [esp-4h] [ebp-2C4h]
  phys_vec3 m_b_loc_vert; // [esp+0h] [ebp-2C0h]
  float v46; // [esp+14h] [ebp-2ACh]
  float v47; // [esp+18h] [ebp-2A8h]
  float v48; // [esp+1Ch] [ebp-2A4h]
  phys_vec3 m_b_vert; // [esp+20h] [ebp-2A0h]
  float v50; // [esp+34h] [ebp-28Ch]
  float v51; // [esp+38h] [ebp-288h]
  float v52; // [esp+3Ch] [ebp-284h]
  phys_vec3 *v53; // [esp+50h] [ebp-270h]
  float v54; // [esp+54h] [ebp-26Ch]
  float v55; // [esp+58h] [ebp-268h]
  float v56; // [esp+5Ch] [ebp-264h]
  phys_vec3 m_mesh_a_center; // [esp+60h] [ebp-260h]
  float v58; // [esp+80h] [ebp-240h]
  float v59; // [esp+84h] [ebp-23Ch]
  float v60; // [esp+88h] [ebp-238h]
  float best_dist_sq; // [esp+8Ch] [ebp-234h]
  phys_vec3 dir; // [esp+90h] [ebp-230h]
  float v63; // [esp+A0h] [ebp-220h]
  const float dotp; // [esp+ACh] [ebp-214h]
  unsigned int v65; // [esp+2B0h] [ebp-10h]
  int v66; // [esp+2B4h] [ebp-Ch]
  int v67; // [esp+2B8h] [ebp-8h]
  int retaddr; // [esp+2C0h] [ebp+0h]

  v66 = a1;
  v67 = retaddr;
  v65 = (unsigned int)&v66 ^ __security_cookie;
  v54 = 0.0;
  v55 = 0.0;
  v34 = a3;
  v56 = 0.0;
  m_mesh_a_center.y = 0.0;
  v33 = a2;
  m_mesh_a_center.z = 0.0;
  v53 = result;
  m_mesh_a_center.w = 0.0;
  LODWORD(dir.w) = m_pcd;
  v59 = 0.0;
  v6 = NULL;
  v60 = 0.0;
  best_dist_sq = 0.0;
  do
  {
    (***(void (__stdcall ****)(phys_vec3 *, float *, int *, float *, float *, int *))(LODWORD(dir.w) + 40))(
      (phys_vec3 *)((char *)m_list_support_dir + (_DWORD)v6),
      &v50,
      &v37,
      v33,
      v34,
      v35);
    v7 = *(void (****)(void))(LODWORD(dir.w) + 44);
    m_b_vert.y = -v6[4429632];
    v35 = &v38;
    m_b_vert.z = -v6[4429633];
    v34 = &v42;
    v33 = &v39;
    m_b_vert.w = -v6[4429634];
    v39 = m_gjk_info->cg2_to_cg1_xform.x.z * m_b_vert.w
        + m_gjk_info->cg2_to_cg1_xform.x.y * m_b_vert.z
        + m_b_vert.y * m_gjk_info->cg2_to_cg1_xform.x.x;
    v40 = m_gjk_info->cg2_to_cg1_xform.y.x * m_b_vert.y
        + m_gjk_info->cg2_to_cg1_xform.y.y * m_b_vert.z
        + m_b_vert.w * m_gjk_info->cg2_to_cg1_xform.y.z;
    v41 = m_b_vert.w * m_gjk_info->cg2_to_cg1_xform.z.z
        + m_b_vert.z * m_gjk_info->cg2_to_cg1_xform.z.y
        + m_b_vert.y * m_gjk_info->cg2_to_cg1_xform.z.x;
    (**v7)();
    v8 = phys_multiply((phys_vec3 *)&v36, &m_gjk_info->cg2_to_cg1_xform, (phys_vec3 *)&v42);
    v6 += 4;
    v46 = v8->x + m_gjk_info->cg2_to_cg1_xform.w.x;
    v47 = v8->y + m_gjk_info->cg2_to_cg1_xform.w.y;
    v48 = v8->z + m_gjk_info->cg2_to_cg1_xform.w.z;
    v9 = v50;
    v10 = v46;
    m_b_loc_vert.y = v50 - v46;
    v11 = v51;
    v12 = v47;
    m_b_loc_vert.z = v51 - v47;
    v13 = v52;
    v14 = v48;
    m_b_loc_vert.w = v52 - v48;
    *(float *)((char *)&v66 + (_DWORD)v6 - 224) = m_b_loc_vert.y;
    *(float *)((char *)&v66 + (_DWORD)v6 - 220) = m_b_loc_vert.z;
    *(float *)((char *)&v66 + (_DWORD)v6 - 216) = m_b_loc_vert.w;
    v54 = v9 + v54;
    v55 = v11 + v55;
    v56 = v13 + v56;
    m_mesh_a_center.y = v10 + m_mesh_a_center.y;
    m_mesh_a_center.z = v12 + m_mesh_a_center.z;
    m_mesh_a_center.w = v14 + m_mesh_a_center.w;
    v59 = v59 + *(float *)((char *)&v66 + (_DWORD)v6 - 224);
    v60 = v60 + *(float *)((char *)&v66 + (_DWORD)v6 - 220);
    best_dist_sq = *(float *)((char *)&v66 + (_DWORD)v6 - 216) + best_dist_sq;
  }
  while ( (signed int)v6 < 192 );
  dir.w = 0.0;
  v15 = m_list_triangle;
  v16 = (float *)&dotp;
  v54 = v54 * 0.0833333358168602;
  v55 = v55 * 0.0833333358168602;
  v56 = v56 * 0.0833333358168602;
  m_mesh_a_center.y = m_mesh_a_center.y * 0.0833333358168602;
  m_mesh_a_center.z = m_mesh_a_center.z * 0.0833333358168602;
  m_mesh_a_center.w = m_mesh_a_center.w * 0.0833333358168602;
  v59 = v59 * 0.0833333358168602;
  v60 = v60 * 0.0833333358168602;
  best_dist_sq = 0.0833333358168602 * best_dist_sq;
  v58 = 0.0;
  do
  {
    v17 = (float *)(&v66 + 4 * *v15 - 52);
    v18 = (float *)(&v66 + 4 * v15[2] - 52);
    v19 = (float *)(&v66 + 4 * v15[1] - 52);
    m_b_loc_vert.y = *v18 - *v17;
    m_b_loc_vert.z = v18[1] - v17[1];
    v20 = v18[2];
    v21 = v16 - 2;
    m_b_loc_vert.w = v20 - v17[2];
    v46 = *v19 - *v17;
    v47 = v19[1] - v17[1];
    v48 = v19[2] - v17[2];
    m_b_vert.y = v47 * m_b_loc_vert.w - v48 * m_b_loc_vert.z;
    m_b_vert.z = v48 * m_b_loc_vert.y - m_b_loc_vert.w * v46;
    m_b_vert.w = m_b_loc_vert.z * v46 - v47 * m_b_loc_vert.y;
    v22 = m_b_vert.y;
    *(v16 - 2) = m_b_vert.y;
    v23 = m_b_vert.z;
    *(v16 - 1) = m_b_vert.z;
    v24 = m_b_vert.w;
    *v16 = m_b_vert.w;
    v50 = *v17 - v59;
    v51 = v17[1] - v60;
    v52 = v17[2] - best_dist_sq;
    v63 = v50 * v22 + v51 * v23 + v52 * v24;
    if ( v63 < 0.0 )
    {
      v39 = -v22;
      v40 = -v23;
      v41 = -v24;
      *v21 = v39;
      *(v16 - 1) = v40;
      *v16 = v41;
    }
    v63 = *(v16 - 1) * *(v16 - 1) + *v21 * *v21 + *v16 * *v16;
    v25 = v63;
    if ( v63 < 0.0000000099999991 )
    {
      v28 = dir.w;
    }
    else
    {
      v42 = -*v17;
      v43 = -v17[1];
      v44 = -v17[2];
      v63 = v42 * *v21 + *(v16 - 1) * v43 + v44 * *v16;
      v26 = v63;
      v63 = v63 * v63;
      v63 = v63 / v25;
      v27 = v63;
      if ( v26 < 0.0 )
        v27 = -v27;
      v28 = dir.w;
      v63 = v27;
      if ( !LODWORD(dir.w) || v58 < (double)v63 )
      {
        v58 = v63;
        LODWORD(dir.w) = v16 - 2;
        LODWORD(v28) = v16 - 2;
      }
    }
    v15 += 3;
    v16 += 4;
  }
  while ( v15 < (const int *)"bad separation dir.\n" );
  if ( v28 == 0.0 )
  {
    v59 = v54 - m_mesh_a_center.y;
    v60 = v55 - m_mesh_a_center.z;
    best_dist_sq = v56 - m_mesh_a_center.w;
    v58 = v59 * v59 + v60 * v60 + best_dist_sq * best_dist_sq;
    if ( v58 < 0.0000000099999991 )
    {
      tlWarning("bad separation dir.\n");
      v29 = v53;
      v53->x = stru_10E5CC0.x;
      v29->y = stru_10E5CC0.y;
      v29->z = stru_10E5CC0.z;
      v32 = stru_10E5CC0.w;
    }
    else
    {
      v29 = v53;
      v30 = v60;
      v53->x = v59;
      v31 = best_dist_sq;
      v29->y = v30;
      v32 = dir.x;
      v29->z = v31;
    }
    v29->w = v32;
  }
  else
  {
    v58 = *(float *)(LODWORD(v28) + 4) * *(float *)(LODWORD(v28) + 4)
        + *(float *)LODWORD(v28) * *(float *)LODWORD(v28)
        + *(float *)(LODWORD(v28) + 8) * *(float *)(LODWORD(v28) + 8);
    if ( v58 < 0.0000000099999991 )
    {
      if ( _tlAssert(
             "source/phys_gjk_sep_dir.cpp",
             258,
             "AbsSquared(*best_normal) >= phys_sqr(GJK_MIN_SUPPORT_DIR_LENGTH)",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v28 = dir.w;
    }
    v29 = v53;
    v53->x = -*(float *)LODWORD(v28);
    v29->y = -*(float *)(LODWORD(v28) + 4);
    v29->z = -*(float *)(LODWORD(v28) + 8);
  }
  return v29;
}

/*
==============
gjk_sep_dir::dist_seg
==============
*/
double gjk_sep_dir::dist_seg(phys_vec3 *v0, phys_vec3 *v1, phys_vec3 *mesh_center, phys_vec3 *direction)
{
  float v4; // ST20_4
  float v5; // ST24_4
  float v6; // ST28_4
  double v7; // st7
  double v8; // st5
  double v9; // st6
  float v10; // ST20_4
  float v11; // ST24_4
  float v12; // ST28_4
  double v13; // st3
  double v14; // st7
  double v15; // rtt
  float v16; // ST3C_4
  float v17; // ST3C_4
  double v18; // st6
  float v19; // ST10_4
  float v20; // ST14_4
  float v21; // ST18_4
  float v22; // ST3C_4
  float v23; // ST20_4
  float v24; // ST24_4
  phys_vec3 *v25; // ecx
  float v26; // ST28_4
  float v27; // ST00_4
  float v28; // ST04_4
  float v29; // ST08_4
  double v30; // st6
  float v31; // ST3C_4
  float v32; // ST00_4
  float v33; // ST04_4
  float v34; // ST08_4
  float dif_v1_v0_12; // ST38_4
  float v36; // ST00_4
  float v37; // ST04_4
  float v38; // ST08_4
  float v40; // [esp+10h] [ebp-10h]
  float v41; // [esp+10h] [ebp-10h]
  float v42; // [esp+10h] [ebp-10h]

  v4 = v1->x - v0->x;
  v5 = v1->y - v0->y;
  v6 = v1->z - v0->z;
  v7 = v4;
  v8 = v5;
  v9 = v6;
  v40 = v6 * v6 + v4 * v4 + v5 * v5;
  if ( v40 <= 0.001 )
  {
    v25 = direction;
    v14 = 0.0;
    direction->x = v1->x;
    direction->y = v1->y;
    v30 = v1->z;
  }
  else
  {
    v10 = -v0->x;
    v11 = -v0->y;
    v12 = -v0->z;
    v13 = v7 * v10;
    v14 = 0.0;
    v15 = v40;
    v16 = v9 * v12 + v8 * v11 + v13;
    v17 = v16 / v15;
    v18 = v17;
    if ( v17 >= 0.0 )
    {
      if ( v18 > 1.0 )
        v18 = 1.0;
      v41 = v18;
    }
    else
    {
      v41 = 0.0;
    }
    v19 = v1->x * v41;
    v20 = v41 * v1->y;
    v21 = v1->z * v41;
    v22 = 1.0 - v41;
    v23 = v0->x * v22;
    v24 = v22 * v0->y;
    v25 = direction;
    v26 = v22 * v0->z;
    v27 = v23 + v19;
    v28 = v24 + v20;
    v29 = v26 + v21;
    direction->x = v27;
    direction->y = v28;
    v30 = v29;
  }
  v25->z = v30;
  v31 = v25->y * v25->y + v25->x * v25->x + v25->z * v25->z;
  v42 = -v31;
  v32 = v25->x - mesh_center->x;
  v33 = v25->y - mesh_center->y;
  v34 = v25->z - mesh_center->z;
  dif_v1_v0_12 = v25->y * v33 + v32 * v25->x + v25->z * v34;
  if ( v14 > dif_v1_v0_12 )
  {
    v36 = -v25->x;
    v37 = -v25->y;
    v38 = -v25->z;
    v25->x = v36;
    v25->y = v37;
    v25->z = v38;
    v42 = -v42;
  }
  return v42;
}

