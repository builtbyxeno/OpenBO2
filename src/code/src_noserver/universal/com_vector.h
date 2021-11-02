#include "types.h"
#include "vars.h"
#include <universal/com_math.h>

/*
==============
Vec2Normalize
==============
*/
inline double Vec2Normalize(vec2_t *v)
{
	const float length = sqrtf((v->x * v->x) + (v->y * v->y));
	const float m = length;

	if (-length > 0)
		m = 1;

	v->x *= (1 / m);
	v->y *= (1 / m);

	return length;
}

/*
==============
Vec2NormalizeTo
==============
*/
inline double Vec2NormalizeTo(const vec2_t *v, vec2_t *out)
{
	const float length = sqrtf((v->x * v->x) + (v->y * v->y));
	const float m = length;

	if (-length > 0)
		m = 1;

	out->x = v->x * (1 / m);
	out->y = v->y * (1 / m);

	return length;
}

/*
==============
Vec3LengthSq
==============
*/
inline double Vec3LengthSq(const vec3_t *v)
{
	return (v->y * v->y) + (v->x * v->x) + (v->z * v->z);
}

/*
==============
Vec3NotZero
==============
*/
inline BOOL Vec3NotZero(const vec3_t *a)
{
	return a->x != 0 || a->y != 0 || a->z != 0;
}

/*
==============
Vec3Normalize
==============
*/
inline double Vec3Normalize(vec3_t *v)
{
	const float length = sqrtf((v->x * v->x) + (v->y * v->y)) + (v->z * v->z));
	const float m = length;

	if (-length > 0)
		m = 1;

	v->x *= (1 / m);
	v->y *= (1 / m);
	v->z *= (1 / m);

	return length;
}

/*
==============
Vec3Cross
==============
*/
inline void Vec3Cross(const vec3_t *v0, const vec3_t *v1, vec3_t *cross)
{
	assert(v0 != cross);
	assert(v1 != cross);

	cross->x = (v1->z * v0->y) - (v0->z * v1->y);
	cross->y = (v0->z * v1->x) - (v0->x * v1->z);
	cross->z = (v0->x * v1->y) - (v1->x * v0->y);
}

/*
==============
Vec3NormalizeTo
==============
*/
inline double Vec3NormalizeTo(const vec3_t *v, vec3_t *out)
{
	const float length = sqrtf((v->x * v->x) + (v->y * v->y)) + (v->z * v->z));
	const float m = length;

	if (-length > 0)
		m = 1;

	out->x = v->x * (1 / m);
	out->y = v->y * (1 / m);
	out->z = v->z * (1 / m);

	return length;
}

/*
==============
Vec3RotateTranspose
==============
*/
inline void Vec3RotateTranspose(const vec3_t *in, const vec3_t *matrix, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Vec3Compare
==============
*/
inline BOOL Vec3Compare(const vec3_t *a, const vec3_t *b)
{
	return a->x == b->x && a->y == b->y && a->z == b->z;
}

/*
==============
Vec3IsNormalized
==============
*/
inline BOOL Vec3IsNormalized(const vec3_t *v)
{
	return sqrtf(fabs((v->x * v->x) + (v->y * v->y) + (v->z * v->z) - 1)) < 0.0020000001;
}

/*
==============
Vec3Rotate
==============
*/
inline void Vec3Rotate(const vec3_t *in, const vec3_t *matrix, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Vec4Compare
==============
*/
inline BOOL Vec4Compare(const vec4_t *a, const vec4_t *b)
{
	return a->x == b->x && a->y == b->y && a->z == b->z && a->w == b->w;
}

/*
==============
Vec3Dir
==============
*/
inline double Vec3Dir(const vec3_t *p1, const vec3_t *p2, vec3_t *dir)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vec2NormalizeFast
==============
*/
inline void Vec2NormalizeFast(vec2_t *v)
{
	float invLength;

	invLength = I_rsqrt(v->v[0] * v->v[0] + v->v[1] * v->v[1]);
	v->v[0] *= invLength;
	v->v[1] *= invLength;
}

/*
==============
Vec3IsNormalizedEpsilon
==============
*/
inline BOOL Vec3IsNormalizedEpsilon(const vec3_t *v, float epsilon)
{
	return (epsilon * 2) >
		sqrtf(fabs((v->x * v->x) + (v->y * v->y) + (v->z * v->z) - 1));
}

