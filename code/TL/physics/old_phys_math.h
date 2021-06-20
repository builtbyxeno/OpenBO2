/*
==============
phys_multiply
==============
*/
phys_vec3 *phys_multiply(phys_vec3 *result, phys_mat44 *mat, phys_vec3 *v)
{
  float v3; // xmm0_4
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  phys_vec3 *v8; // eax
  float v9; // xmm1_4
  float v10; // xmm2_4

  v3 = v->z;
  v4 = mat->z.y * v3;
  v5 = mat->z.z * v3;
  v6 = mat->z.x * v3;
  v7 = v->y;
  v8 = result;
  v9 = (float)((float)(mat->x.y * v->x) + (float)(mat->y.y * v7)) + v4;
  v10 = (float)((float)(mat->x.z * v->x) + (float)(mat->y.z * v7)) + v5;
  result->x = (float)((float)(mat->x.x * v->x) + (float)(mat->y.x * v7)) + v6;
  result->y = v9;
  result->z = v10;
  return v8;
}

/*
==============
phys_inv_multiply
==============
*/
phys_vec3 *phys_inv_multiply(phys_vec3 *result, phys_mat44 *mat, phys_vec3 *v)
{
  phys_mat44 *v3; // ecx
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  phys_vec3 *v7; // eax
  float v8; // xmm4_4

  v3 = mat;
  v4 = v->y;
  v5 = v->x;
  v6 = v->z;
  v7 = result;
  v8 = mat->y.x;
  result->x = (float)((float)(mat->x.y * v4) + (float)(mat->x.x * v->x)) + (float)(mat->x.z * v6);
  result->y = (float)((float)(v3->y.y * v4) + (float)(v8 * v5)) + (float)(v3->y.z * v6);
  result->z = (float)((float)(v3->z.y * v4) + (float)(v3->z.x * v5)) + (float)(mat->z.z * v6);
  return v7;
}

/*
==============
phys_full_inv_multiply
==============
*/
phys_vec3 *phys_full_inv_multiply(phys_vec3 *result, phys_mat44 *mat, phys_vec3 *v)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  phys_vec3 *v6; // eax
  float v7; // xmm4_4

  v3 = v->x - mat->w.x;
  v4 = v->y - mat->w.y;
  v5 = v->z - mat->w.z;
  v6 = result;
  v7 = mat->y.x;
  result->x = (float)((float)(mat->x.y * v4) + (float)(mat->x.x * v3)) + (float)(mat->x.z * v5);
  result->y = (float)((float)(mat->y.y * v4) + (float)(v7 * v3)) + (float)(mat->y.z * v5);
  result->z = (float)((float)(mat->z.y * v4) + (float)(mat->z.x * v3)) + (float)(mat->z.z * v5);
  return v6;
}

/*
==============
phys_transpose
==============
*/
void phys_transpose(phys_mat44 *dest, phys_mat44 *source)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  float v4; // xmm0_4

  if ( dest == source )
  {
    v2 = dest->x.y;
    dest->x.y = dest->y.x;
    dest->y.x = v2;
    v3 = dest->x.z;
    dest->x.z = dest->z.x;
    dest->z.x = v3;
    v4 = dest->y.z;
    dest->y.z = dest->z.y;
    dest->z.y = v4;
  }
  else
  {
    dest->x.x = source->x.x;
    dest->x.y = source->y.x;
    dest->x.z = source->z.x;
    dest->y.x = source->x.y;
    dest->y.y = source->y.y;
    dest->y.z = source->z.y;
    dest->z.x = source->x.z;
    dest->z.y = source->y.z;
    dest->z.z = source->z.z;
  }
}

/*
==============
Abs
==============
*/
long double Abs(vec3_t *v)
{
  return sqrt(v->v[1] * v->v[1] + v->v[0] * v->v[0] + v->v[2] * v->v[2]);
}

/*
==============
phys_Unitize
==============
*/
phys_vec3 *phys_Unitize(phys_vec3 *result, phys_vec3 *a)
{
  phys_vec3 *v2; // esi
  phys_vec3 *v3; // eax
  float v4; // xmm0_4
  float na; // [esp+10h] [ebp+Ch]

  v2 = a;
  na = fsqrt((float)((float)(a->x * a->x) + (float)(a->y * a->y)) + (float)(a->z * a->z));
  if ( na <= 0.0
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h", 85, "na > 0.0f", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v3 = result;
  result->x = v2->x * (float)(1.0 / na);
  v4 = (float)(1.0 / na) * v2->z;
  result->y = (float)(1.0 / na) * v2->y;
  result->z = v4;
  return v3;
}

/*
==============
phys_multiply_mat
==============
*/
void __usercall phys_multiply_mat(int a1@<ebp>, phys_mat44 *dest, phys_mat44 *left, phys_mat44 *right)
{
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm7_4
  float v7; // xmm3_4
  float v8; // xmm5_4
  float v9; // xmm6_4
  float v10; // xmm4_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm7_4
  float v18; // xmm3_4
  float v19; // xmm5_4
  float v20; // xmm6_4
  float v21; // xmm4_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm7_4
  float v26; // xmm3_4
  float v27; // xmm5_4
  float v28; // xmm6_4
  float v29; // xmm3_4
  float v30; // xmm4_4
  float v31; // xmm2_4
  phys_mat44 v32; // [esp-Ch] [ebp-5Ch]
  phys_mat44 temp; // [esp+0h] [ebp-50h]
  int v34; // [esp+44h] [ebp-Ch]
  int v35; // [esp+48h] [ebp-8h]
  int retaddr; // [esp+50h] [ebp+0h]

  v34 = a1;
  v35 = retaddr;
  if ( dest == left )
  {
    qmemcpy(&v32, left, sizeof(v32));
    phys_multiply_mat(dest, &v32, right);
  }
  else
  {
    v4 = right->x.y;
    v5 = right->x.x;
    v6 = left->y.x;
    v7 = left->x.x * right->x.x;
    v8 = right->x.z * left->z.x;
    v9 = right->x.z * left->z.y;
    temp.w.w = right->x.z * left->z.z;
    v10 = v5 * left->x.y;
    v11 = v5 * left->x.z;
    v12 = (float)(v7 + (float)(v6 * v4)) + v8;
    v13 = v4 * left->y.y;
    v14 = v4 * left->y.z;
    dest->x.x = v12;
    dest->x.z = (float)(v11 + v14) + temp.w.w;
    dest->x.y = (float)(v10 + v13) + v9;
    v15 = right->y.y;
    v16 = right->y.x;
    v17 = left->y.x;
    v18 = left->x.x * v16;
    v19 = right->y.z * left->z.x;
    v20 = right->y.z * left->z.y;
    temp.w.w = right->y.z * left->z.z;
    v21 = v16 * left->x.y;
    v22 = v15 * left->y.y;
    dest->y.z = (float)((float)(v16 * left->x.z) + (float)(v15 * left->y.z)) + temp.w.w;
    dest->y.x = (float)(v18 + (float)(v17 * v15)) + v19;
    dest->y.y = (float)(v21 + v22) + v20;
    v23 = right->z.y;
    v24 = right->z.x;
    v25 = left->y.x;
    v26 = left->x.x;
    v27 = right->z.z * left->z.x;
    v28 = right->z.z * left->z.y;
    temp.w.w = right->z.z * left->z.z;
    v29 = (float)((float)(v26 * v24) + (float)(v25 * v23)) + v27;
    v30 = (float)((float)(v24 * left->x.y) + (float)(v23 * left->y.y)) + v28;
    v31 = (float)((float)(v24 * left->x.z) + (float)(v23 * left->y.z)) + temp.w.w;
    dest->z.x = v29;
    dest->z.y = v30;
    dest->z.z = v31;
  }
}

/*
==============
phys_full_multiply_mat
==============
*/
void __usercall phys_full_multiply_mat(int a1@<ebp>, phys_mat44 *dest, phys_mat44 *left, phys_mat44 *right)
{
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm7_4
  float v7; // xmm3_4
  float v8; // xmm5_4
  float v9; // xmm6_4
  float v10; // xmm4_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm7_4
  float v18; // xmm3_4
  float v19; // xmm5_4
  float v20; // xmm6_4
  float v21; // xmm4_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm7_4
  float v26; // xmm3_4
  float v27; // xmm5_4
  float v28; // xmm6_4
  float v29; // xmm3_4
  float v30; // xmm4_4
  float v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm7_4
  float v35; // xmm3_4
  float v36; // xmm5_4
  float v37; // xmm6_4
  float v38; // xmm3_4
  float v39; // xmm4_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm3_4
  phys_mat44 v44; // [esp-Ch] [ebp-5Ch]
  phys_mat44 temp; // [esp+0h] [ebp-50h]
  int v46; // [esp+44h] [ebp-Ch]
  int v47; // [esp+48h] [ebp-8h]
  int retaddr; // [esp+50h] [ebp+0h]

  v46 = a1;
  v47 = retaddr;
  if ( dest == left )
  {
    qmemcpy(&v44, left, sizeof(v44));
    phys_full_multiply_mat(dest, &v44, right);
  }
  else
  {
    v4 = right->x.y;
    v5 = right->x.x;
    v6 = left->y.x;
    v7 = left->x.x * right->x.x;
    v8 = right->x.z * left->z.x;
    v9 = right->x.z * left->z.y;
    temp.w.w = right->x.z * left->z.z;
    v10 = v5 * left->x.y;
    v11 = v5 * left->x.z;
    v12 = (float)(v7 + (float)(v6 * v4)) + v8;
    v13 = v4 * left->y.y;
    v14 = v4 * left->y.z;
    dest->x.x = v12;
    dest->x.z = (float)(v11 + v14) + temp.w.w;
    dest->x.y = (float)(v10 + v13) + v9;
    v15 = right->y.y;
    v16 = right->y.x;
    v17 = left->y.x;
    v18 = left->x.x * v16;
    v19 = right->y.z * left->z.x;
    v20 = right->y.z * left->z.y;
    temp.w.w = right->y.z * left->z.z;
    v21 = v16 * left->x.y;
    v22 = v15 * left->y.y;
    dest->y.z = (float)((float)(v16 * left->x.z) + (float)(v15 * left->y.z)) + temp.w.w;
    dest->y.x = (float)(v18 + (float)(v17 * v15)) + v19;
    dest->y.y = (float)(v21 + v22) + v20;
    v23 = right->z.y;
    v24 = right->z.x;
    v25 = left->y.x;
    v26 = left->x.x;
    v27 = right->z.z * left->z.x;
    v28 = right->z.z * left->z.y;
    temp.w.w = right->z.z * left->z.z;
    v29 = v26 * v24;
    v30 = (float)((float)(v24 * left->x.y) + (float)(v23 * left->y.y)) + v28;
    v31 = (float)((float)(v24 * left->x.z) + (float)(v23 * left->y.z)) + temp.w.w;
    dest->z.x = (float)(v29 + (float)(v25 * v23)) + v27;
    dest->z.y = v30;
    dest->z.z = v31;
    v32 = right->w.y;
    v33 = right->w.x;
    v34 = left->y.x;
    v35 = left->x.x;
    v36 = right->w.z * left->z.x;
    v37 = right->w.z * left->z.y;
    temp.w.w = right->w.z * left->z.z;
    v38 = v35 * v33;
    v39 = (float)(v33 * left->x.y) + (float)(v32 * left->y.y);
    v40 = (float)(v33 * left->x.z) + (float)(v32 * left->y.z);
    v41 = left->w.x + (float)((float)(v38 + (float)(v34 * v32)) + v36);
    v42 = left->w.y + (float)(v39 + v37);
    v43 = left->w.z + (float)(v40 + temp.w.w);
    dest->w.x = v41;
    dest->w.y = v42;
    dest->w.z = v43;
  }
}

/*
==============
SetIdentity
==============
*/
void SetIdentity(phys_mat44 *m)
{
  m->x.x = PHYS_IDENTITY_MATRIX_39.x.x;
  m->x.y = PHYS_IDENTITY_MATRIX_39.x.y;
  m->x.z = PHYS_IDENTITY_MATRIX_39.x.z;
  m->y.x = PHYS_IDENTITY_MATRIX_39.y.x;
  m->y.y = PHYS_IDENTITY_MATRIX_39.y.y;
  m->y.z = PHYS_IDENTITY_MATRIX_39.y.z;
  m->z.x = PHYS_IDENTITY_MATRIX_39.z.x;
  m->z.y = PHYS_IDENTITY_MATRIX_39.z.y;
  m->z.z = PHYS_IDENTITY_MATRIX_39.z.z;
  m->w.x = PHYS_IDENTITY_MATRIX_39.w.x;
  m->w.y = PHYS_IDENTITY_MATRIX_39.w.y;
  m->w.z = PHYS_IDENTITY_MATRIX_39.w.z;
}

/*
==============
phys_full_inverse
==============
*/
void __usercall phys_full_inverse(int a1@<ebp>, phys_mat44 *dest, phys_mat44 *source)
{
  float v3; // xmm0_4
  float v4; // xmm7_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm6_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // [esp-Ch] [ebp-5Ch]
  float v17; // [esp-8h] [ebp-58h]
  float v18; // [esp-4h] [ebp-54h]
  phys_mat44 temp; // [esp+0h] [ebp-50h]
  int v20; // [esp+44h] [ebp-Ch]
  int v21; // [esp+48h] [ebp-8h]
  int retaddr; // [esp+50h] [ebp+0h]

  v20 = a1;
  v21 = retaddr;
  if ( dest == source )
  {
    phys_full_inverse((phys_mat44 *)&v16, source);
    dest->x.x = v16;
    dest->x.y = v17;
    dest->x.z = v18;
    dest->y.x = temp.x.y;
    dest->y.y = temp.x.z;
    dest->y.z = temp.x.w;
    dest->z.x = temp.y.y;
    dest->z.y = temp.y.z;
    dest->z.z = temp.y.w;
    dest->w.x = temp.z.y;
    dest->w.y = temp.z.z;
    dest->w.z = temp.z.w;
  }
  else
  {
    phys_transpose(dest, source);
    v3 = source->w.z;
    v4 = source->w.x;
    v5 = dest->x.z;
    v6 = dest->z.x * v3;
    v7 = dest->z.y * v3;
    v8 = dest->z.z * v3;
    v9 = source->w.y;
    temp.w.z = dest->y.y * v9;
    v10 = dest->y.z * v9;
    v11 = v9;
    v12 = dest->x.x;
    v13 = v11 * dest->y.x;
    temp.w.w = v10;
    v14 = (float)((float)(dest->x.y * v4) + temp.w.z) + v7;
    v15 = (float)((float)(v5 * v4) + temp.w.w) + v8;
    LODWORD(dest->w.x) = COERCE_UNSIGNED_INT((float)((float)(v12 * v4) + v13) + v6) ^ _mask__NegFloat_;
    LODWORD(dest->w.y) = LODWORD(v14) ^ _mask__NegFloat_;
    LODWORD(dest->w.z) = LODWORD(v15) ^ _mask__NegFloat_;
  }
}

/*
==============
make_rotate
==============
*/
void make_rotate(phys_mat44 *mat, phys_vec3 *v, const float theta_factor, const float max_rotation_radians)
{
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float ud_12; // ST18_4
  float v9; // xmm0_4
  float v10; // ST00_4
  float v11; // ST00_4
  float v12; // xmm5_4
  float v13; // xmm2_4
  float v14; // xmm6_4
  float v15; // [esp-Ch] [ebp-2Ch]
  float v16; // [esp-8h] [ebp-28h]
  float v17; // [esp-4h] [ebp-24h]
  float v18; // [esp+10h] [ebp-10h]

  v4 = v->x;
  v5 = fsqrt((float)((float)(v4 * v4) + (float)(v->y * v->y)) + (float)(v->z * v->z));
  if ( v5 >= 0.0000099999997 )
  {
    v15 = v4 * (float)(1.0 / v5);
    v6 = (float)(1.0 / v5) * v->y;
    v17 = (float)(1.0 / v5) * v->z;
    v7 = v5 * theta_factor;
    v16 = (float)(1.0 / v5) * v->y;
    v18 = v5 * theta_factor;
    if ( (float)(v5 * theta_factor) > max_rotation_radians )
    {
      v7 = max_rotation_radians;
      v18 = max_rotation_radians;
    }
    __libm_sse2_sinf(v15);
    ud_12 = v7;
    v9 = v18;
    __libm_sse2_cosf(v10);
    mat->x.x = (float)((float)(v11 * v11) * (float)(1.0 - v9)) + v9;
    v12 = (float)(v6 * v11) * (float)(1.0 - v18);
    v13 = (float)(v17 * v11) * (float)(1.0 - v18);
    mat->y.x = v12 - (float)(v17 * ud_12);
    mat->x.y = (float)(v17 * ud_12) + v12;
    mat->x.z = v13 - (float)(v16 * ud_12);
    mat->z.x = (float)(v16 * ud_12) + v13;
    mat->y.y = (float)((float)(v16 * v16) * (float)(1.0 - v9)) + v9;
    v14 = (float)(v16 * v17) * (float)(1.0 - v18);
    mat->w.x = 0.0;
    mat->w.y = 0.0;
    mat->w.z = 0.0;
    mat->z.y = v14 - (float)(v11 * ud_12);
    mat->y.z = (float)(v11 * ud_12) + v14;
    mat->z.z = (float)((float)(v17 * v17) * (float)(1.0 - v9)) + v9;
    mat->x.w = 0.0;
    mat->y.w = 0.0;
    mat->z.w = 0.0;
    mat->w.w = FLOAT_1_0;
  }
  else
  {
    mat->x.x = PHYS_IDENTITY_MATRIX_39.x.x;
    mat->x.y = PHYS_IDENTITY_MATRIX_39.x.y;
    mat->x.z = PHYS_IDENTITY_MATRIX_39.x.z;
    mat->y.x = PHYS_IDENTITY_MATRIX_39.y.x;
    mat->y.y = PHYS_IDENTITY_MATRIX_39.y.y;
    mat->y.z = PHYS_IDENTITY_MATRIX_39.y.z;
    mat->z.x = PHYS_IDENTITY_MATRIX_39.z.x;
    mat->z.y = PHYS_IDENTITY_MATRIX_39.z.y;
    mat->z.z = PHYS_IDENTITY_MATRIX_39.z.z;
    mat->w.x = PHYS_IDENTITY_MATRIX_39.w.x;
    mat->w.y = PHYS_IDENTITY_MATRIX_39.w.y;
    mat->w.z = PHYS_IDENTITY_MATRIX_39.w.z;
  }
}

/*
==============
phys_inv_multiply_mat
==============
*/
void __usercall phys_inv_multiply_mat(float a1@<ebp>, phys_mat44 *dest, phys_mat44 *left, phys_mat44 *right)
{
  phys_mat44 *v4; // ecx
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm5_4
  float v10; // xmm3_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm5_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  phys_mat44 v24; // [esp-Ch] [ebp-4Ch]
  phys_mat44 temp; // [esp+0h] [ebp-40h]
  float retaddr; // [esp+40h] [ebp+0h]

  temp.w.y = a1;
  temp.w.z = retaddr;
  if ( dest == left )
  {
    qmemcpy(&v24, left, sizeof(v24));
    phys_inv_multiply_mat(dest, &v24, right);
  }
  else
  {
    v4 = right;
    v5 = right->x.y;
    v6 = right->x.z;
    v7 = right->x.x * left->z.x;
    v8 = (float)((float)(v4->x.x * left->x.x) + (float)(left->x.y * v5)) + (float)(v4->x.z * left->x.z);
    v9 = left->z.y * v5;
    v10 = left->z.z;
    dest->x.y = (float)((float)(v4->x.y * left->y.y) + (float)(left->y.x * v4->x.x)) + (float)(v4->x.z * left->y.z);
    dest->x.x = v8;
    dest->x.z = (float)(v7 + v9) + (float)(v10 * v6);
    v11 = right->y.y;
    v12 = right->y.x;
    v13 = right->y.z;
    v14 = left->y.x * v12;
    v15 = v12 * left->z.x;
    v16 = (float)((float)(v4->y.x * left->x.x) + (float)(left->x.y * v11)) + (float)(v4->y.z * left->x.z);
    v17 = (float)((float)(v4->y.y * left->y.y) + v14) + (float)(v4->y.z * left->y.z);
    v18 = left->z.y * v11;
    v19 = left->z.z;
    dest->y.y = v17;
    dest->y.x = v16;
    dest->y.z = (float)(v15 + v18) + (float)(v19 * v13);
    v20 = right->z.x;
    v21 = right->z.y;
    v22 = (float)((float)(right->z.y * left->y.y) + (float)(left->y.x * v20)) + (float)(right->z.z * left->y.z);
    v23 = (float)((float)(v20 * left->z.x) + (float)(left->z.y * v21)) + (float)(left->z.z * right->z.z);
    dest->z.x = (float)((float)(right->z.x * left->x.x) + (float)(left->x.y * v21)) + (float)(right->z.z * left->x.z);
    dest->z.y = v22;
    dest->z.z = v23;
  }
}

/*
==============
make_rotate
==============
*/
void make_rotate(phys_mat44 *mat, phys_vec3 *v1, phys_vec3 *v2)
{
  phys_vec3 *v3; // eax
  float v4; // xmm5_4
  float v5; // xmm6_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm1_4
  float v12; // ST08_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float ud_12; // ST18_4
  float ud_8; // ST14_4
  float v18; // xmm1_4

  v3 = v1;
  v4 = (float)(v2->z * v3->y) - (float)(v2->y * v3->z);
  v5 = (float)(v2->x * v3->z) - (float)(v3->x * v2->z);
  v6 = (float)(v1->x * v2->y) - (float)(v2->x * v1->y);
  v7 = (float)((float)(v5 * v5) + (float)(v4 * v4)) + (float)(v6 * v6);
  if ( v7 >= 0.0000099999997 )
  {
    v8 = fsqrt(v7);
    v9 = v4 * (float)(1.0 / v8);
    v10 = v5 * (float)(1.0 / v8);
    v11 = (float)(v1->z * v2->z) + (float)((float)(v1->x * v2->x) + (float)(v2->y * v1->y));
    v12 = v6 * (float)(1.0 / v8);
    v13 = 1.0 / fsqrt((float)(v11 * v11) + (float)(v8 * v8));
    v14 = v13 * v11;
    v15 = v13 * v8;
    ud_12 = (float)(v10 * v9) * (float)(1.0 - v14);
    ud_8 = (float)(v10 * v12) * (float)(1.0 - v14);
    mat->x.x = (float)((float)(v9 * v9) * (float)(1.0 - v14)) + v14;
    v18 = (float)(v12 * v9) * (float)(1.0 - v14);
    mat->y.x = ud_12 - (float)(v12 * v15);
    mat->x.z = v18 - (float)(v10 * v15);
    mat->y.y = (float)((float)(v10 * v10) * (float)(1.0 - v14)) + v14;
    mat->z.x = (float)(v10 * v15) + v18;
    mat->w.x = 0.0;
    mat->x.y = (float)(v12 * v15) + ud_12;
    mat->z.y = ud_8 - (float)(v9 * v15);
    mat->w.y = 0.0;
    mat->y.z = (float)(v9 * v15) + ud_8;
    mat->z.z = (float)((float)(v12 * v12) * (float)(1.0 - v14)) + v14;
    mat->w.z = 0.0;
    mat->x.w = 0.0;
    mat->y.w = 0.0;
    mat->z.w = 0.0;
    mat->w.w = FLOAT_1_0;
  }
  else
  {
    mat->x.x = PHYS_IDENTITY_MATRIX_49.x.x;
    mat->x.y = PHYS_IDENTITY_MATRIX_49.x.y;
    mat->x.z = PHYS_IDENTITY_MATRIX_49.x.z;
    mat->y.x = PHYS_IDENTITY_MATRIX_49.y.x;
    mat->y.y = PHYS_IDENTITY_MATRIX_49.y.y;
    mat->y.z = PHYS_IDENTITY_MATRIX_49.y.z;
    mat->z.x = PHYS_IDENTITY_MATRIX_49.z.x;
    mat->z.y = PHYS_IDENTITY_MATRIX_49.z.y;
    mat->z.z = PHYS_IDENTITY_MATRIX_49.z.z;
    mat->w.x = PHYS_IDENTITY_MATRIX_49.w.x;
    mat->w.y = PHYS_IDENTITY_MATRIX_49.w.y;
    mat->w.z = PHYS_IDENTITY_MATRIX_49.w.z;
  }
}

/*
==============
phys_full_inv_multiply_mat
==============
*/
void __usercall phys_full_inv_multiply_mat(float a1@<ebp>, phys_mat44 *dest, phys_mat44 *left, phys_mat44 *right)
{
  phys_mat44 *v4; // ecx
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm5_4
  float v10; // xmm3_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm5_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm5_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm5_4
  float v28; // xmm3_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm3_4
  float v33; // xmm4_4
  float v34; // xmm5_4
  float v35; // xmm0_4
  phys_mat44 v36; // [esp-Ch] [ebp-4Ch]
  phys_mat44 temp; // [esp+0h] [ebp-40h]
  float retaddr; // [esp+40h] [ebp+0h]

  temp.w.y = a1;
  temp.w.z = retaddr;
  if ( dest == left )
  {
    qmemcpy(&v36, left, sizeof(v36));
    phys_full_inv_multiply_mat(dest, &v36, right);
  }
  else
  {
    v4 = right;
    v5 = right->x.y;
    v6 = right->x.z;
    v7 = right->x.x * left->z.x;
    v8 = (float)((float)(v4->x.x * left->x.x) + (float)(left->x.y * v5)) + (float)(v4->x.z * left->x.z);
    v9 = left->z.y * v5;
    v10 = left->z.z;
    dest->x.y = (float)((float)(v4->x.y * left->y.y) + (float)(left->y.x * v4->x.x)) + (float)(v4->x.z * left->y.z);
    dest->x.x = v8;
    dest->x.z = (float)(v7 + v9) + (float)(v10 * v6);
    v11 = right->y.y;
    v12 = right->y.x;
    v13 = right->y.z;
    v14 = left->y.x * v12;
    v15 = v12 * left->z.x;
    v16 = (float)((float)(v4->y.x * left->x.x) + (float)(left->x.y * v11)) + (float)(v4->y.z * left->x.z);
    v17 = (float)((float)(v4->y.y * left->y.y) + v14) + (float)(v4->y.z * left->y.z);
    v18 = left->z.y * v11;
    v19 = left->z.z;
    dest->y.y = v17;
    dest->y.x = v16;
    dest->y.z = (float)(v15 + v18) + (float)(v19 * v13);
    v20 = right->z.x;
    v21 = right->z.y;
    v22 = right->z.z;
    v23 = left->y.x * v20;
    v24 = v20 * left->z.x;
    v25 = (float)((float)(v4->z.x * left->x.x) + (float)(left->x.y * v21)) + (float)(v4->z.z * left->x.z);
    v26 = (float)((float)(v4->z.y * left->y.y) + v23) + (float)(v4->z.z * left->y.z);
    v27 = left->z.y * v21;
    v28 = left->z.z;
    dest->z.x = v25;
    dest->z.y = v26;
    dest->z.z = (float)(v24 + v27) + (float)(v28 * v22);
    v29 = right->w.x - left->w.x;
    v30 = right->w.y - left->w.y;
    v31 = right->w.z - left->w.z;
    v32 = (float)((float)(left->x.x * v29) + (float)(left->x.y * v30)) + (float)(v31 * left->x.z);
    v33 = (float)((float)(left->y.x * v29) + (float)(left->y.y * v30)) + (float)(left->y.z * v31);
    v34 = (float)(left->z.x * v29) + (float)(left->z.y * v30);
    v35 = left->z.z * v31;
    dest->w.x = v32;
    dest->w.y = v33;
    dest->w.z = v34 + v35;
  }
}

/*
==============
construct_orth_ud
==============
*/
phys_vec3 *construct_orth_ud(phys_vec3 *result, phys_vec3 *ud)
{
  float v2; // ST3C_4
  float v3; // ST3C_4
  float v4; // ST3C_4
  float v5; // ST3C_4
  float v6; // ST3C_4
  double v7; // st7
  float v8; // ST3C_4
  float v9; // ST3C_4
  float v10; // ST20_4
  float v11; // ST28_4
  float v12; // ST3C_4
  float v13; // ST20_4
  float v14; // ST24_4
  float v15; // ST3C_4
  phys_vec3 *v16; // eax
  float v17; // ST3C_4
  double v18; // [esp-10h] [ebp-1Ch]
  float v19; // [esp-4h] [ebp-10h]

  v2 = ud->y * ud->y + ud->x * ud->x + ud->z * ud->z;
  v3 = sqrt(v2);
  v4 = v3 - 1.0;
  v5 = fabs(v4);
  if ( v5 >= 0.00009999999747378752
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h",
         303,
         "fabsf(nud - 1.0f) < .0001f",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  result->x = 0.0;
  v6 = ud->z;
  v7 = v6;
  result->y = v6;
  v8 = -ud->y;
  result->z = v8;
  v18 = 0.0 * 0.0;
  v9 = v7 * v7 + 0.0 * 0.0 + v8 * v8;
  v19 = sqrt(v9);
  if ( v19 < 0.00009999999747378752 )
  {
    v10 = -ud->z;
    v11 = ud->x;
    result->x = v10;
    result->y = 0.0;
    result->z = v11;
    v12 = v11 * v11 + v10 * v10 + v18;
    v19 = sqrt(v12);
    if ( v19 < 0.00009999999747378752 )
    {
      v13 = ud->y;
      v14 = -ud->x;
      result->x = v13;
      result->y = v14;
      result->z = 0.0;
      v15 = v13 * v13 + v14 * v14 + v18;
      v19 = sqrt(v15);
      if ( v19 < 0.00009999999747378752 )
      {
        if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h", 318, "0", "not possible") )
          __debugbreak();
      }
    }
  }
  v16 = result;
  v17 = 1.0 / v19;
  result->x = result->x * v17;
  result->y = v17 * result->y;
  result->z = v17 * result->z;
  return v16;
}

/*
==============
Phys_GetQuaternion
==============
*/
Phys_UnitQuaternion *Phys_GetQuaternion(Phys_UnitQuaternion *result, phys_mat44 *M)
{
  Phys_UnitQuaternion *v2; // esi
  float v3; // ST2C_4
  float v4; // ST2C_4
  double v5; // st7
  float v6; // ST28_4
  double v7; // st7
  double v8; // st7
  signed int v9; // esi
  signed int v10; // ebx
  float v11; // ST2C_4
  int v12; // edx
  int v13; // ecx
  float d; // ST20_4
  Phys_UnitQuaternion *v15; // eax
  float b; // [esp+10h] [ebp-20h]
  signed int ba; // [esp+10h] [ebp-20h]
  float s; // [esp+14h] [ebp-1Ch]
  float sa; // [esp+14h] [ebp-1Ch]
  float a; // [esp+18h] [ebp-18h]
  float aa; // [esp+18h] [ebp-18h]
  float ab; // [esp+18h] [ebp-18h]
  float q[4]; // [esp+1Ch] [ebp-14h]

  v2 = result;
  a = M->x.x + M->y.y + M->z.z;
  if ( a <= 0.0 )
  {
    v9 = 0;
    v10 = 1;
    ba = 2;
    if ( M->x.x < (double)M->y.y )
    {
      v9 = 1;
      v10 = 2;
      ba = 0;
    }
    if ( *(&M->x.x + 5 * v9) >= (double)M->z.z )
    {
      if ( (v9 < 0 || v9 >= 3)
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h",
             36,
             "i >= 0 && i < 3",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      if ( (v10 < 0 || v10 >= 3)
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h",
             36,
             "i >= 0 && i < 3",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      if ( (ba < 0 || ba >= 3)
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h",
             36,
             "i >= 0 && i < 3",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    else
    {
      v9 = 2;
      v10 = 0;
      ba = 1;
    }
    v11 = *(&M->x.x + 5 * v9) - *(&M->x.x + 5 * v10) - *(&M->x.x + 5 * ba) + 1.0;
    ab = sqrt(v11);
    sa = ab;
    q[v9 + 1] = ab * 0.5;
    if ( 0.0 != ab )
      sa = 0.5 / ab;
    if ( (v10 < 0 || v10 >= 3)
      && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h", 36, "i >= 0 && i < 3", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( (ba < 0 || ba >= 3)
      && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h", 36, "i >= 0 && i < 3", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    q[0] = (*(&M->x.x + v10 + 4 * ba) - *(&M->x.x + ba + 4 * v10)) * sa;
    if ( (v9 < 0 || v9 >= 3)
      && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h", 36, "i >= 0 && i < 3", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( (v10 < 0 || v10 >= 3)
      && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h", 36, "i >= 0 && i < 3", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    q[v10 + 1] = (*(&M->x.x + v9 + 4 * v10) + *(&M->x.x + v10 + 4 * v9)) * sa;
    if ( (v9 < 0 || v9 >= 3)
      && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h", 36, "i >= 0 && i < 3", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( ba < 0 || ba >= 3 )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\old_phys_math.h",
             36,
             "i >= 0 && i < 3",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    v12 = v9 + 4 * ba;
    v13 = ba + 4 * v9;
    v2 = result;
    q[ba + 1] = (*(&M->x.x + v12) + *(&M->x.x + v13)) * sa;
    aa = q[0];
    b = q[1];
    s = q[2];
    v8 = q[3];
  }
  else
  {
    v3 = a + 1.0;
    v4 = sqrt(v3);
    v5 = v4;
    aa = v4 * 0.5;
    v6 = 0.5 / v5;
    v7 = v6;
    b = (M->z.y - M->y.z) * v6;
    s = (M->x.z - M->z.x) * v6;
    v8 = v7 * (M->y.x - M->x.y);
  }
  d = v8;
  v15 = v2;
  v2->x = -b;
  v2->y = -s;
  v2->z = -d;
  v2->w = aa;
  return v15;
}

/*
==============
orthonormalize
==============
*/
void orthonormalize(phys_mat44 *mat)
{
  phys_mat44 *v1; // esi
  float v2; // ST2C_4
  float v3; // ST2C_4
  float v4; // ST2C_4
  double v5; // st7
  float v6; // ST2C_4
  double v7; // st6
  float v8; // ST2C_4
  double v9; // rt2
  float v10; // ST2C_4
  double v11; // st5
  float v12; // ST2C_4
  float v13; // ST10_4
  float v14; // ST14_4
  float v15; // ST18_4
  float v16; // ST2C_4
  float v17; // ST2C_4
  float v18; // ST2C_4
  float v19; // ST10_4
  float v20; // ST14_4
  float v21; // ST18_4

  v1 = mat;
  v2 = mat->x.y * mat->x.y + v1->x.x * v1->x.x + v1->x.z * v1->x.z;
  v3 = sqrt(v2);
  v4 = 1.0 / v3;
  v5 = v4;
  v6 = mat->x.x * v4;
  v7 = v6;
  mat->x.x = v6;
  v8 = v5 * mat->x.y;
  mat->x.y = v8;
  v9 = v8;
  v10 = v5 * mat->x.z;
  v11 = v10;
  mat->x.z = v10;
  v12 = v9 * v1->y.y + v7 * v1->y.x + v1->y.z * v10;
  v13 = v7 * v12;
  v14 = v9 * v12;
  v15 = v11 * v12;
  v1->y.x = v1->y.x - v13;
  v1->y.y = v1->y.y - v14;
  v1->y.z = v1->y.z - v15;
  v16 = v1->y.z * v1->y.z + v1->y.x * v1->y.x + v1->y.y * v1->y.y;
  v17 = sqrt(v16);
  v18 = 1.0 / v17;
  v1->y.x = v1->y.x * v18;
  v1->y.y = v1->y.y * v18;
  v1->y.z = v18 * v1->y.z;
  v19 = v1->y.z * v1->x.y - v1->x.z * v1->y.y;
  v20 = v1->x.z * v1->y.x - v1->y.z * v1->x.x;
  v21 = v1->y.y * v1->x.x - v1->y.x * v1->x.y;
  mat->z.x = v19;
  mat->z.y = v20;
  mat->z.z = v21;
}

