#include "com_vector.h"

#include <math.h>
#include "com_math_anglevectors.h"

vec3_t vec3_origin = { 0,0,0 };

void AngleVectors(vec3_t const* angles, vec3_t* forward, vec3_t* right, vec3_t* up)
{
    float angle;
    float sr, sp, sy, cr, cp, cy;

    cy = cos(angles->y * RadiansConstant);
    sy = sinf(angles->y * RadiansConstant);
    angle = angles->x * RadiansConstant;
    cp = cosf(angle);
    sp = sinf(angle);
    if (forward)
    {
        forward->y = cp * sy;
        forward->x = cp * cy;
        forward->z = -sp;
    }
    if (right || up)
    {
        cr = cosf(angles->z * RadiansConstant);
        sr = sinf(angles->z * RadiansConstant);
        if (right)
        {
            right->x = (cr * sy) - ((sr * sp) * cy);
            right->y = ((cr * -1.0) * cy) - ((sr * sp) * sy);
            right->z = (sr * -1.0) * cp;
        }
        if (up)
        {
            up->x = ((cr * sp) * cy) + (sr * sy);
            up->y = ((cr * sp) * sy) - (sr * cy);
            up->z = cr * cp;
        }
    }
}

void AnglesToAxis(vec3_t const* angles, vec3_t* axis)
{
    float angley, anglex, anglez;
    float cr, sr, cp, sy, cy, sp;

    angley = angles->y * RadiansConstant;
    cy = cos(angley);
    sy = sin(angley);
    anglex = angles->x * RadiansConstant;
    cp = cos(anglex);
    sp = sin(anglex);
    axis->y = cp * sy;
    axis->x = cp * cy;
    axis->z = -sp;
    anglez = angles->z * RadiansConstant;
    cr = cos(anglez);
    sr = sin(anglez);
    axis[1].x = ((sr * sp) * cy) - (cr * sy);
    axis[1].y = ((sr * sp) * sy) + (cr * cy);
    axis[1].z = sr * cp;
    axis[2].x = ((cr * sp) * cy) + (sr * sy);
    axis[2].y = ((cr * sp) * sy) - (sr * cy);
    axis[2].z = cr * cp;
}

void AnglesToQuat(vec3_t const* angles, vec4_t* quat)
{
    vec3_t axis[3];

    AnglesToAxis(angles, axis);
    //AxisToQuat(axis, quat);
}

void QuatToAxis(vec4_t const* quat, vec3_t* axis)
{
    float v5, v6, v7, v8, v9, v10, v11, v12, v13;
    float xz, zw, xx, xw;

    v5 = 2.0 / ((((quat->v[1] * quat->v[1]) + (quat->v[0] * quat->v[0])) + (quat->v[2] * quat->v[2])) + (quat->v[3] * quat->v[3]));
    xx = v5 * (quat->v[0] * quat->v[0]);
    v6 = quat->v[0] * v5;
    v7 = v5 * (quat->v[1] * quat->v[1]);
    v8 = v5 * (quat->v[2] * quat->v[2]);
    xz = quat->v[2] * v6;
    v9 = quat->v[3] * v6;
    v10 = quat->v[1] * v5;
    v11 = quat->v[1] * v6;
    v12 = quat->v[2] * v10;
    xw = v9;
    v13 = quat->v[3] * v10;
    zw = (quat->v[2] * v5) * quat->v[3];
    axis->x = 1.0 - (v8 + v7);
    axis->y = zw + v11;
    axis->z = xz - v13;
    axis[1].x = v11 - zw;
    axis[1].y = 1.0 - (v8 + xx);
    axis[1].z = v12 + xw;
    axis[2].x = v13 + xz;
    axis[2].y = v12 - xw;
    axis[2].z = 1.0 - (v7 + xx);
}

void vectosignedangles(vec3_t const* vec, vec3_t* angles)
{
    float _Y, _X, yaw, pitch;

    _Y = vec->y;
    if (_Y == 0.0 && vec->x == 0.0)
    {
        if (-vec->z < 0.0)
            angles->x = -90.0;
        else
            angles->x = 90.0;
        angles->v[1] = 0.0;
    }
    else
    {
        yaw = atan2f(_Y, vec->x) * 180.0 * PIInverseFraction;
        _X = sqrtf((vec->x * vec->x) + (vec->y * vec->y));
        angles->v[1] = yaw;
        pitch = atan2f(vec->z, _X) * -180.0 * PIInverseFraction;
        angles->x = pitch;
    }
}

float vectosignedpitch(vec3_t const*)
{
    return 0.0f;
}

void AxisToSignedAngles(vec3_t const* axis, vec3_t* angles)
{
    vec3_t* v2; // edi
    const vec3_t* v3; // esi
    int v4; // xmm4_4
    float v5; // xmm1_4
    float v6; // xmm3_4
    float v7; // xmm2_4
    float v8; // xmm7_4
    float v9; // xmm0_4
    float v10; // xmm1_4
    float v11; // xmm3_4
    float v12; // xmm0_4
    float v13; // xmm3_4
    float v14; // xmm2_4
    float v15; // xmm3_4
    float v16; // xmm2_4
    double v17; // st7
    float _X; // [esp+4h] [ebp-30h]
    float fCos; // [esp+14h] [ebp-20h]
    float fSin; // [esp+18h] [ebp-1Ch]
    float rad; // [esp+1Ch] [ebp-18h]
    float v22; // [esp+20h] [ebp-14h]
    float v23; // [esp+24h] [ebp-10h]
    vec3_t right; // [esp+28h] [ebp-Ch]

    v2 = angles;
    v3 = axis;
    vectosignedangles(axis, angles);
    v5 = v3[1].x;
    v6 = v3[1].y;
    v7 = v3[1].z;
    rad = -v2->y * 0.017453292;
    v23 = fCos;
    v22 = fSin;
    fCos = cosf(rad);
    fSin = sinf(rad);
    v8 = v6;
    v9 = v5;
    v10 = (v5 * fSin) + (v6 * fCos);
    v11 = -v2->x * 0.017453292;
    v12 = (v9 * fCos) - (v8 * fSin);
    right.y = v10;
    rad = v11;
    v22 = fCos;
    v23 = fSin;
    fCos = cosf(v11);
    fSin = sinf(v11);
    v13 = v7;
    v14 = (v7 * fCos) - (v12 * fSin);
    v15 = (v13 * fSin) + (v12 * fCos);
    right.z = v14;
    if (v10 != 0.0 || v15 != 0.0)
    {
        _X = sqrtf((v15 * v15) + (v10 * v10));
        v17 = atan2f(right.z, _X);
        v10 = right.y;
        v23 = v17 * -180.0 * 0.31830987;
        v16 = v23;
    }
    else if ((-v14) < 0.0)
    {
        v16 = -90.0;
    }
    else
    {
        v16 = 90.0;
    }
    if (v10 >= 0.0)
    {
        v2->z = -v16;
    }
    else if (v16 >= 0.0)
    {
        v2->z = v16 + -180.0;
    }
    else
    {
        v2->z = v16 + 180.0;
    }
}
