/*
==============
phys_min
==============
*/
phys_vec3 *phys_min(phys_vec3 *result, phys_vec3 *v1, phys_vec3 *v2)
{
  float v3; // xmm3_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  phys_vec3 *v6; // eax

  if ( v2->z < v1->z )
    v3 = v2->z;
  else
    v3 = v1->z;
  if ( v2->y < v1->y )
    v4 = v2->y;
  else
    v4 = v1->y;
  v5 = v1->x;
  if ( v2->x < v1->x )
    v5 = v2->x;
  v6 = result;
  result->x = v5;
  result->y = v4;
  result->z = v3;
  return v6;
}

/*
==============
phys_max
==============
*/
phys_vec3 *phys_max(phys_vec3 *result, phys_vec3 *v1, phys_vec3 *v2)
{
  float v3; // xmm3_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  phys_vec3 *v6; // eax

  if ( v1->z < v2->z )
    v3 = v2->z;
  else
    v3 = v1->z;
  if ( v1->y < v2->y )
    v4 = v2->y;
  else
    v4 = v1->y;
  v5 = v1->x;
  if ( v1->x < v2->x )
    v5 = v2->x;
  v6 = result;
  result->x = v5;
  result->y = v4;
  result->z = v3;
  return v6;
}

/*
==============
PHYS_ASSERT_UNIT
==============
*/
void PHYS_ASSERT_UNIT(phys_vec3 *v)
{
  float va; // [esp+8h] [ebp+8h]
  float vb; // [esp+8h] [ebp+8h]
  float vc; // [esp+8h] [ebp+8h]
  float vd; // [esp+8h] [ebp+8h]

  va = v->y * v->y + v->x * v->x + v->z * v->z;
  vb = sqrt(va);
  vc = vb - 1.0;
  vd = fabs(vc);
  if ( vd >= 0.001 )
  {
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_math.h",
           420,
           "fabsf(nv - 1.0f) < 0.001f",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
}

/*
==============
PHYS_ASSERT_ORTHOGONAL
==============
*/
void PHYS_ASSERT_ORTHOGONAL(phys_vec3 *v1, phys_vec3 *v2)
{
  float v1a; // [esp+8h] [ebp+8h]
  float v1b; // [esp+8h] [ebp+8h]

  v1a = v1->y * v2->y + v1->x * v2->x + v1->z * v2->z;
  v1b = fabs(v1a);
  if ( v1b >= 0.001 )
  {
    if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_math.h", 425, "fabsf(d) < 0.001f", (const char *)&pBlock) )
      __debugbreak();
  }
}

/*
==============
PHYS_ASSERT_ORTHONORMAL
==============
*/
void PHYS_ASSERT_ORTHONORMAL(phys_mat44 *m)
{
  phys_mat44 *v1; // esi
  float dyz; // [esp+4h] [ebp-14h]
  float dxz; // [esp+8h] [ebp-10h]
  float dxy; // [esp+Ch] [ebp-Ch]
  float nz; // [esp+10h] [ebp-8h]
  float ny; // [esp+14h] [ebp-4h]
  float ma; // [esp+20h] [ebp+8h]
  float mb; // [esp+20h] [ebp+8h]
  float mc; // [esp+20h] [ebp+8h]
  float md; // [esp+20h] [ebp+8h]
  float me; // [esp+20h] [ebp+8h]
  float mf; // [esp+20h] [ebp+8h]
  float mg; // [esp+20h] [ebp+8h]
  float mh; // [esp+20h] [ebp+8h]
  float mi; // [esp+20h] [ebp+8h]
  float mj; // [esp+20h] [ebp+8h]
  float mk; // [esp+20h] [ebp+8h]
  float ml; // [esp+20h] [ebp+8h]
  float mm; // [esp+20h] [ebp+8h]
  float mn; // [esp+20h] [ebp+8h]
  float mo; // [esp+20h] [ebp+8h]

  v1 = m;
  ma = m->y.y * m->y.y + m->y.x * m->y.x + m->y.z * m->y.z;
  mb = sqrt(ma);
  ny = mb;
  mc = v1->z.y * v1->z.y + v1->z.x * v1->z.x + v1->z.z * v1->z.z;
  md = sqrt(mc);
  nz = md;
  dxy = v1->x.y * v1->y.y + v1->x.x * v1->y.x + v1->x.z * v1->y.z;
  dxz = v1->x.y * v1->z.y + v1->z.x * v1->x.x + v1->x.z * v1->z.z;
  dyz = v1->z.x * v1->y.x + v1->y.y * v1->z.y + v1->y.z * v1->z.z;
  me = v1->x.z * v1->x.z + v1->x.x * v1->x.x + v1->x.y * v1->x.y;
  mf = sqrt(me);
  mg = mf - 1.0;
  mh = fabs(mg);
  if ( mh >= 0.001
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_math.h",
         435,
         "fabsf(nx - 1.0f) < 0.001f",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  mi = ny - 1.0;
  mj = fabs(mi);
  if ( mj >= 0.001
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_math.h",
         436,
         "fabsf(ny - 1.0f) < 0.001f",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  mk = nz - 1.0;
  ml = fabs(mk);
  if ( ml >= 0.001
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_math.h",
         437,
         "fabsf(nz - 1.0f) < 0.001f",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  mm = fabs(dxy);
  if ( mm >= 0.001
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_math.h", 438, "fabsf(dxy) < 0.001f", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  mn = fabs(dxz);
  if ( mn >= 0.001
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_math.h", 439, "fabsf(dxz) < 0.001f", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  mo = fabs(dyz);
  if ( mo >= 0.001 )
  {
    if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_math.h", 440, "fabsf(dyz) < 0.001f", (const char *)&pBlock) )
      __debugbreak();
  }
}

