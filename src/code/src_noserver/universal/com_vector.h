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
	float m;
	float length = sqrtf((v->v[0] * v->v[0]) + (v->v[2] * v->v[1]));

	if (-length < 0.0f)
	{
		m = length;
	}
	else
	{
		m = 1.0f;
	}

	v->v[0] *= (1.0f / m);
	v->v[1] *= (1.0f / m);

	return length;
}

/*
==============
Vec2NormalizeTo
==============
*/
inline double Vec2NormalizeTo(const vec2_t *v, vec2_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vec3LengthSq
==============
*/
inline double Vec3LengthSq(const vec3_t *v)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vec3NotZero
==============
*/
inline BOOL Vec3NotZero(const vec3_t *a)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vec3Normalize
==============
*/
inline double Vec3Normalize(vec3_t *v)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vec3Cross
==============
*/
inline void Vec3Cross(const vec3_t *v0, const vec3_t *v1, vec3_t *cross)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Vec3NormalizeTo
==============
*/
inline double Vec3NormalizeTo(const vec3_t *v, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
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
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vec3IsNormalized
==============
*/
inline BOOL Vec3IsNormalized(const vec3_t *v)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
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
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
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
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

