#include "types.h"

/*
==============
IS_NAN
==============
*/
inline qboolean IS_NAN(float x)
{
	return ((*(int*)&x) & 0x7F800000) == 2139095040;
}

/*
==============
I_fmax
==============
*/
inline float I_fmax(float x, float y)
{
	if ((float)(x - y) < 0.0)
	{
		return y;
	}
	else
	{
		return x;
	}
}

/*
==============
I_fmin
==============
*/
inline float I_fmin(float x, float y)
{
	if ((float)(y - x) < 0.0)
	{
		return y;
	}
	else
	{
		return x;
	}
}

/*
==============
I_fclamp
==============
*/
inline float I_fclamp(float val, float min, float max)
{
	return I_fmax(min, I_fmin(val, max));
}

/*
==============
AngleNormalize180
==============
*/
inline float AngleNormalize180(const float angle)
{
	float scaledAngle;

	scaledAngle = angle * 0.0027777778f;
	return (scaledAngle - (float)floor(scaledAngle + 0.5f)) * 360.0f;
}

/*
==============
AngleDelta
==============
*/
inline float AngleDelta(const float a1, const float a2)
{
	float delta;

	delta = (a1 - a2) * 0.0027777778;
	return (delta - floor(delta + 0.5)) * 360.0;
}

/*
==============
I_max
==============
*/
inline int I_max(int x, int y)
{
	if (x < y)
	{
		return y;
	}
	return x;
}

/*
==============
I_min
==============
*/
inline int I_min(int x, int y)
{
	if (y >= x)
	{
		return x;
	}
	return y;
}

/*
==============
LerpAngle
==============
*/
inline float LerpAngle(const float from, const float to, const float frac)
{
	float angle;

	angle = (to - from) * 0.0027777778;
	return (angle - floor(angle + 0.5)) * 360.0 * frac + from;
}

/*
==============
LerpAngleVector
==============
*/
inline void LerpAngleVector(const vec3_t *from, const vec3_t *to, const float frac, vec3_t *result)
{
	result->x = AngleNormalize180(to->x - from->x) * frac + from->x;
	result->y = AngleNormalize180(to->y - from->y) * frac + from->y;
	result->z = AngleNormalize180(to->z - from->z) * frac + from->z;
}

/*
==============
I_rsqrt
==============
*/
inline float I_rsqrt(const float number)
{
	// CLASSIC LULE
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	//assert(!IS_NAN(number));
	assert(number);

	x2 = number * 0.5F;
	y = number;
	i = *(long*)&y;                        // evil floating point bit level hacking
	i = 0x5f3759df - (i >> 1);               // what the fuck?
	y = *(float*)&i;
	y = y * (threehalfs - (x2 * y * y));   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}

/*
==============
ClampFloat
==============
*/
inline float ClampFloat(const float x, const float minf, const float maxf)
{
	assert(minf < maxf);
	if (minf > x)
		return minf;
	if (x <= maxf)
		return x;
	return maxf;
}

/*
==============
MatrixTransformVector
==============
*/
inline void MatrixTransformVector(const vec3_t *in1, const vec3_t *in2, vec3_t *out)
{
	assert(&in1 != &out);
	out->x = ((in2[1].x * in1->y) + (in1->x * in2->x)) + (in2[2].x * in1->z);
	out->y = ((in2->y * in1->x) + (in2[1].y * in1->y)) + (in2[2].y * in1->z);
	out->z = ((in2->z * in1->x) + (in2[1].z * in1->y)) + (in2[2].z * in1->z);
}

/*
==============
ClampInt
==============
*/
inline int ClampInt(const int x, const int min, const int max)
{
	if (x < min)
		return min;
	if (x > max)
		return max;
	return x;
}

/*
==============
QuatMultiply
==============
*/
inline void QuatMultiply(const vec4_t *in1, const vec4_t *in2, vec4_t *out)
{
	assert(&in1 != &out);
	assert(&in2 != &out);

	out->v[0] = (((in1->v[0] * in2->v[3]) + (in1->v[3] * in2->v[0])) + (in2->v[1] * in1->v[2])) - (in2->v[2] * in1->v[1]);
	out->v[1] = (((in1->v[1] * in2->v[3]) - (in1->v[2] * in2->v[0])) + (in1->v[3] * in2->v[1])) + (in2->v[2] * in1->v[0]);
	out->v[2] = (((in1->v[1] * in2->v[0]) + (in1->v[2] * in2->v[3])) - (in2->v[1] * in1->v[0])) + (in1->v[3] * in2->v[2]);
	out->v[3] = (((in1->v[3] * in2->v[3]) - (in1->v[0] * in2->v[0])) - (in2->v[1] * in1->v[1])) - (in2->v[2] * in1->v[2]);
}

/*
==============
PitchToQuat
==============
*/
inline void PitchToQuat(float pitch, vec4_t *quat)
{
	float pitchconv;

	pitchconv = pitch * 0.0087266462;
	quat->v[0] = 0.0;
	quat->v[2] = 0.0;
	quat->v[3] = cos(pitchconv);
	quat->v[1] = sin(pitchconv);
}

/*
==============
MatrixTransformVectorQuatTrans
==============
*/
inline void MatrixTransformVectorQuatTrans(const vec3_t *in, const DObjAnimMat *mat, vec3_t *out)
{
	out->x = (((in->x * (1.0 - (((double)mat->quat.v[2] * ((double)mat->quat.v[2] * (double)mat->transWeight)) + ((double)mat->quat.v[1] * ((double)mat->quat.v[1] * (double)mat->transWeight))))) + (in->y * (((double)mat->quat.v[1] * ((double)mat->quat.v[0] * (double)mat->transWeight)) - ((double)mat->quat.v[3] * ((double)mat->quat.v[2] * (double)mat->transWeight))))) + (in->z * (((double)mat->quat.v[3] * ((double)mat->quat.v[1] * (double)mat->transWeight)) + ((double)mat->quat.v[2] * ((double)mat->quat.v[0] * ((double)mat->quat.v[0] * (double)mat->transWeight)))))) + (double)mat->trans.x;
	out->y = (((in->x * (((double)mat->quat.v[3] * ((double)mat->quat.v[2] * (double)mat->transWeight)) + ((double)mat->quat.v[1] * ((double)mat->quat.v[0] * (double)mat->transWeight)))) + (in->y * (1.0 - (((double)mat->quat.v[2] * ((double)mat->quat.v[2] * (double)mat->transWeight)) + ((double)mat->quat.v[0] * ((double)mat->quat.v[0] * (double)mat->transWeight)))))) + (in->z * (((double)mat->quat.v[2] * ((double)mat->quat.v[1] * (double)mat->transWeight)) - ((double)mat->quat.v[3] * ((double)mat->quat.v[0] * (double)mat->transWeight))))) + (double)mat->trans.y;
	out->z = (((in->x * (((double)mat->quat.v[2] * ((double)mat->quat.v[0] * (double)mat->transWeight)) - ((double)mat->quat.v[3] * ((double)mat->quat.v[1] * (double)mat->transWeight)))) + (in->y * (((double)mat->quat.v[2] * ((double)mat->quat.v[1] * (double)mat->transWeight)) + ((double)mat->quat.v[3] * ((double)mat->quat.v[0] * (double)mat->transWeight))))) + (in->z * (1.0 - (((double)mat->quat.v[1] * ((double)mat->quat.v[1] * (double)mat->transWeight)) + ((double)mat->quat.v[0] * ((double)mat->quat.v[0] * (double)mat->transWeight)))))) + (double)mat->trans.z;
}

/*
==============
I_fmodulus
==============
*/
inline float I_fmodulus(float f, float mod)
{
	float floorMod;
	float floorF;
	float floorDiff;
	float modulus;

	floorF = floor(f);
	floorMod = floor(mod);
	floorDiff = mod - floorMod;
	modulus = (float)((int)floorF % (int)floorMod);
	return floorDiff - (f - floorF) + modulus;
}

/*
==============
CountBitsEnabled
==============
*/
inline unsigned int CountBitsEnabled(unsigned int num)
{
	return (((((((num & 0x55) + ((num >> 1) & 0x55)) & 0x33) + ((((num & 0x55555555) + ((num >> 1) & 0x55555555)) >> 2) & 0x33)) & 0xF) + ((((((num & 0x55555555) + ((num >> 1) & 0x55555555))
		& 0x33333333) + ((((num & 0x55555555) + ((num >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4) & 0xF)) + (((((((num & 0x5555) + ((num >> 1) & 0x5555)) & 0x3333) + ((((num & 0x55555555) + 
		((num >> 1) & 0x55555555)) >> 2) & 0x3333)) & 0xF0F) + ((((((num & 0x55555555) + ((num >> 1) & 0x55555555)) & 0x33333333) + ((((num & 0x55555555) + ((num >> 1) & 0x55555555)) >> 2) 
		& 0x33333333)) >> 4) & 0xF0F)) >> 8)) + ((((((((num & 0x55555555) + ((num >> 1) & 0x55555555)) & 0x33333333) + ((((num & 0x55555555) + ((num >> 1) & 0x55555555)) >> 2) & 0x33333333))
		& 0xF0F0F0F) + ((((((num & 0x55555555) + ((num >> 1) & 0x55555555)) & 0x33333333) + ((((num & 0x55555555) + ((num >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4) & 0xF0F0F0F)) & 0xFF00FF)
		+ ((((((((num & 0x55555555) + ((num >> 1) & 0x55555555)) & 0x33333333) + ((((num & 0x55555555) + ((num >> 1) & 0x55555555)) >> 2) & 0x33333333)) & 0xF0F0F0F) + ((((((num & 0x55555555)
		+ ((num >> 1) & 0x55555555)) & 0x33333333) + ((((num & 0x55555555) + ((num >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4) & 0xF0F0F0F)) >> 8) & 0xFF00FF)) >> 16;
}

/*
==============
I_fsign
==============
*/
inline float I_fsign(float val)
{
	if (val < 0.0)
		return -1.0;
	else
		return 1.0;
}

/*
==============
ConvertQuatToInverseSkelMat
==============
*/
inline void ConvertQuatToInverseSkelMat(const DObjAnimMat *mat, DObjSkelMat *skelMat)
{
	float transWeight;
	float yy;
	float xy;
	float zz;
	float zw;
	float scaledQuat;
	float scaledQuat_4;
	float scaledQuat_8;
	float yw;
	float xz;
	float yz;
	float xx;
	float xw;

	transWeight = mat->transWeight;
	scaledQuat = transWeight * mat->quat.v[0];
	scaledQuat_4 = transWeight * mat->quat.v[1];
	scaledQuat_8 = transWeight * mat->quat.v[2];
	xx = scaledQuat * mat->quat.v[0];
	xy = scaledQuat * mat->quat.v[1];
	xz = scaledQuat * mat->quat.v[2];
	xw = scaledQuat * mat->quat.v[3];
	yy = scaledQuat_4 * mat->quat.v[1];
	yz = scaledQuat_4 * mat->quat.v[2];
	yw = scaledQuat_4 * mat->quat.v[3];
	zz = scaledQuat_8 * mat->quat.v[2];
	zw = scaledQuat_8 * mat->quat.v[3];
	skelMat->axis[0].v[0] = 1.0 - (yy + zz);
	skelMat->axis[0].v[1] = xy - zw;
	skelMat->axis[0].v[2] = xz + yw;
	skelMat->axis[0].v[3] = 0.0;
	skelMat->axis[1].v[0] = xy + zw;
	skelMat->axis[1].v[1] = 1.0 - (xx + zz);
	skelMat->axis[1].v[2] = yz - xw;
	skelMat->axis[1].v[3] = 0.0;
	skelMat->axis[2].v[0] = xz - yw;
	skelMat->axis[2].v[1] = yz + xw;
	skelMat->axis[2].v[2] = 1.0 - (xx + yy);
	skelMat->axis[2].v[3] = 0.0;

	skelMat->origin.v[0] =
		((mat->trans.v[0] * skelMat->axis[0].v[0]) + (mat->trans.v[1] * skelMat->axis[1].v[0]))
		+ -(mat->trans.v[2] * skelMat->axis[2].v[0]);
	skelMat->origin.v[1] =
		((mat->trans.v[0] * skelMat->axis[0].v[1]) + (mat->trans.v[1] * skelMat->axis[1].v[1]))
		+ -(mat->trans.v[2] * skelMat->axis[2].v[1]);
	skelMat->origin.v[2] = 
		((mat->trans.v[0] * skelMat->axis[0].v[2]) + (mat->trans.v[1] * skelMat->axis[1].v[2]))
		+ -(mat->trans.v[2] * skelMat->axis[2].v[2]);
	skelMat->origin.v[3] = 1.0;
}

inline void ConvertQuatToMat(const DObjAnimMat* mat, vec3_t* axis)
{
	float transWeight;
	float yy;
	float xy;
	float zz;
	float zw;
	float scaledQuat;
	float scaledQuat_4;
	float scaledQuat_8;
	float yw;
	float xz;
	float yz;
	float xx;
	float xw;

	transWeight = mat->transWeight;
	scaledQuat = transWeight * mat->quat.v[0];
	scaledQuat_4 = transWeight * mat->quat.v[1];
	scaledQuat_8 = transWeight * mat->quat.v[2];
	xx = scaledQuat * mat->quat.v[0];
	xy = scaledQuat * mat->quat.v[1];
	xz = scaledQuat * mat->quat.v[2];
	xw = scaledQuat * mat->quat.v[3];
	yy = scaledQuat_4 * mat->quat.v[1];
	yz = scaledQuat_4 * mat->quat.v[2];
	yw = scaledQuat_4 * mat->quat.v[3];
	zz = scaledQuat_8 * mat->quat.v[2];
	zw = scaledQuat_8 * mat->quat.v[3];

	axis[0].v[0] = 1.0 - (yy + zz);
	axis[0].v[1] = xy + zw;
	axis[0].v[2] = xz - yw;
	axis[1].v[0] = xy - zw;
	axis[1].v[1] = 1.0 - (xx + zz);
	axis[1].v[2] = yz + xw;
	axis[2].v[0] = xz + yw;
	axis[2].v[1] = yz - xw;
	axis[2].v[2] = 1.0 - (xx + yy);
}

/*
==============
MatrixTransformVectorQuatTransEquals
==============
*/
inline void MatrixTransformVectorQuatTransEquals(const DObjAnimMat *in, vec3_t *inout)
{
	float temp;
	float temp_4;
	vec3_t axis[3];

	ConvertQuatToMat(in, axis);
	inout->x = (((inout->x * axis[0].v[0]) + (inout->y * axis[1].v[0])) + (inout->z * axis[2].v[0])) + in->trans.x;
	inout->y = (((inout->x * axis[0].v[1]) + (inout->y * axis[1].v[1])) + (inout->z * axis[2].v[1])) + in->trans.y;
	inout->z = (((inout->x * axis[0].v[2]) + (inout->y * axis[1].v[2])) + (inout->z * axis[2].v[2])) + in->trans.z;
}

/*
==============
I_fres
==============
*/
inline float I_fres(float val)
{
	return 1.0 / val;
}

/*
==============
ConvertQuatToInverseMat
==============
*/
inline void ConvertQuatToInverseMat(const DObjAnimMat *mat, vec3_t *axis)
{
	float transWeight;
	float yy;
	float xy;
	float zz;
	float zw;
	float scaledQuat;
	float scaledQuat_4;
	float scaledQuat_8;
	float yw;
	float xz;
	float yz;
	float xx;
	float xw;

	transWeight = mat->transWeight;
	scaledQuat = transWeight * mat->quat.v[0];
	scaledQuat_4 = transWeight * mat->quat.v[1];
	scaledQuat_8 = transWeight * mat->quat.v[2];
	xx = scaledQuat * mat->quat.v[0];
	xy = scaledQuat * mat->quat.v[1];
	xz = scaledQuat * mat->quat.v[2];
	xw = scaledQuat * mat->quat.v[3];
	yy = scaledQuat_4 * mat->quat.v[1];
	yz = scaledQuat_4 * mat->quat.v[2];
	yw = scaledQuat_4 * mat->quat.v[3];
	zz = scaledQuat_8 * mat->quat.v[2];
	zw = scaledQuat_8 * mat->quat.v[3];
	axis[0].x = 1.0 - (yy + zz);
	axis[0].y = xy - zw;
	axis[0].z = xz + yw;
	axis[1].x = xy + zw;
	axis[1].y = 1.0 - (xx + zz);
	axis[1].z = yz - xw;
	axis[2].x = xz - yw;
	axis[2].y = yz + xw;
	axis[2].z = 1.0 - (xx + yy);
	axis[3].x = ((mat->trans.v[0] * axis[0].x) + (mat->trans.v[1] * axis[1].x)) + -(mat->trans.v[2] * axis[2].x);
	axis[3].y = ((mat->trans.v[0] * axis[0].y) + (mat->trans.v[1] * axis[1].y)) + -(mat->trans.v[2] * axis[2].y);
	axis[3].z = ((mat->trans.v[0] * axis[0].z) + (mat->trans.v[1] * axis[1].z)) + -(mat->trans.v[2] * axis[2].z);
}

/*
==============
I_fmap
==============
*/
inline float I_fmap(float minx, float maxx, float miny, float maxy, float x)
{
	float newX;

	assert(maxx != minx);

	if (((x - minx) - (maxx - minx)) < 0.0)
	{
		newX = x - minx;
	}
	else
	{
		newX = maxx - minx;
	}
	if ((0.0 - (x - minx)) < 0.0)
	{
		return maxy * (newX / (maxx - minx)) + (1.0 - (newX / (maxx - minx))) * miny;
	}
	else
	{
		return maxy * (0.0 / (maxx - minx)) + (1.0 - (0.0 / (maxx - minx))) * miny;
	}
}

/*
==============
PointInBounds
==============
*/
inline BOOL PointInBounds(const vec3_t *v, const vec3_t *mins, const vec3_t *maxs)
{
	float y;
	float z;

	assert(&v);
	assert(&mins);
	assert(&maxs);

	if (mins->x <= v->x && v->x <= maxs->x)
	{
		y = v->y;
		if (mins->y <= y && y <= maxs->y)
		{
			z = v->z;
			if (mins->z <= z && z <= maxs->z)
				return 1;
		}
	}
	return 0;
}

