#include "com_math.h"
#include <universal/com_vector.h>
#include <universal/com_math_anglevectors.h>
#include <universal/q_shared.h>

void TRACK_com_math(void)
{
}

long double I_normCDF(long double x)
{
	double k = 1.0 / (1.0 + 0.2316419 * x);
	double k_sum = k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));

	if (x >= 0.0) {
		return (1.0 - (1.0 / (pow(2 * M_PI, 0.5))) * exp(-0.5 * x * x) * k_sum);
	}
	else {
		return 1.0 - I_normCDF(-x);
	}
}

float random(void)
{
	return rand() * 0.000030517578;
}

float crandom(void)
{
	signed int randomNum = rand();
	return (double)randomNum * 0.000030517578 + (double)randomNum * 0.000030517578 - 1.0;
}

int RandWithSeed(int* seed)
{
	int v1 = 0x41C64E6D * *seed + 12345;
	*seed = v1;
	return (v1 / 0x10000) & 0x7FFF;
}

double LinearTrack(float tgt, float cur, float rate, float deltaTime)
{
	float err, step;

	err = tgt - cur;
	if (err <= 0.0)
		step = -(rate * deltaTime);
	else
		step = rate * deltaTime;
	if (fabs(err) <= 0.001)
		return tgt;
	if (fabs(step) <= fabs(err))
		return cur + step;
	return tgt;
}

float LinearTrackAngle(float tgt, float cur, float rate, float deltaTime)
{
	float angle;

	while ((tgt - cur) > 180.0)
	{
		tgt = tgt - 360.0;
	}
	while ((tgt - cur) < -180.0)
	{
		tgt = tgt + 360.0;
	}
	angle = LinearTrack(tgt, cur, rate, deltaTime);
	return AngleNormalize180(angle);
}

float DiffTrack(float tgt, float cur, float rate, float deltaTime)
{
	float step;
	float d, ad;

	d = tgt - cur;

	step = rate * d * deltaTime;
	ad = fabs(d);
	if (ad <= 0.001 || fabs(step) > ad)
		return tgt;
	return cur + step;
}

float DiffTrackAngle(float tgt, float cur, float rate, float deltaTime)
{
	float angle;

	while ((tgt - cur) > 180.0)
		tgt = tgt - 360.0;
	while ((tgt - cur) < -180.0)
		tgt = tgt + 360.0;
	angle = DiffTrack(tgt, cur, rate, deltaTime);
	return AngleNormalize180(angle);
}

float GraphGetValueFromFraction(int knotCount, const vec2_t* knots, float fraction)
{
	float result, adjustedFrac;
	int knotIndex = 1;

	result = -1.0;
	while (knots[knotIndex].v[0] < fraction)
	{
		if (++knotIndex >= knotCount)
			return result;
	}
	adjustedFrac = (fraction - knots[knotIndex - 1].v[0]) / (knots[knotIndex].v[0] - knots[knotIndex - 1].v[0]);
	result = ((knots[knotIndex].v[1] - knots[knotIndex - 1].v[1]) * adjustedFrac) + knots[knotIndex - 1].v[1];
	return result;
}

float Q_acos(float c)
{
	c = acos(c);

	if (c > 3.1415927 || c < -3.1415927)
		return 3.1415927;
	else
		return c;
}

char ClampChar(const int i)
{
	if (i < 0xFFFFFF80)
		return 0x80;
	if (i > 0x7F)
		return 0x7F;
	return i;
}

short ClampShort(const int i)
{
	if (i < 0xFFFF8000)
		return 0xFFFF8000;
	if (i > 0x7FFF)
		return 0x7FFF;
	return i;
}

vec3_t bytedirs[162] =
{
  { -0.52573103,  0.0,  0.85065103 },
  { -0.44286299,  0.238856,  0.86418802 },
  { -0.29524201,  0.0,  0.955423 },
  { -0.309017,  0.5,  0.809017 },
  { -0.16246,  0.26286599,  0.951056 },
  {  0.0,  0.0,  1.0 },
  {  0.0,  0.85065103,  0.52573103 },
  { -0.14762101,  0.71656698,  0.68171799 },
  {  0.14762101,  0.71656698,  0.68171799 },
  {  0.0,  0.52573103,  0.85065103 },
  {  0.309017,  0.5,  0.809017 },
  {  0.52573103,  0.0,  0.85065103 },
  {  0.29524201,  0.0,  0.955423 },
  {  0.44286299,  0.238856,  0.86418802 },
  {  0.16246,  0.26286599,  0.951056 },
  { -0.68171799,  0.14762101,  0.71656698 },
  { -0.809017,  0.309017,  0.5 },
  { -0.58778501,  0.42532501,  0.688191 },
  { -0.85065103,  0.52573103,  0.0 },
  { -0.86418802,  0.44286299,  0.238856 },
  { -0.71656698,  0.68171799,  0.14762101 },
  { -0.688191,  0.58778501,  0.42532501 },
  { -0.5,  0.809017,  0.309017 },
  { -0.238856,  0.86418802,  0.44286299 },
  { -0.42532501,  0.688191,  0.58778501 },
  { -0.71656698,  0.68171799, -0.14762101 },
  { -0.5,  0.809017, -0.309017 },
  { -0.52573103,  0.85065103,  0.0 },
  {  0.0,  0.85065103, -0.52573103 },
  { -0.238856,  0.86418802, -0.44286299 },
  {  0.0,  0.955423, -0.29524201 },
  { -0.26286599,  0.951056, -0.16246 },
  {  0.0,  1.0,  0.0 },
  {  0.0,  0.955423,  0.29524201 },
  { -0.26286599,  0.951056,  0.16246 },
  {  0.238856,  0.86418802,  0.44286299 },
  {  0.26286599,  0.951056,  0.16246 },
  {  0.5,  0.809017,  0.309017 },
  {  0.238856,  0.86418802, -0.44286299 },
  {  0.26286599,  0.951056, -0.16246 },
  {  0.5,  0.809017, -0.309017 },
  {  0.85065103,  0.52573103,  0.0 },
  {  0.71656698,  0.68171799,  0.14762101 },
  {  0.71656698,  0.68171799, -0.14762101 },
  {  0.52573103,  0.85065103,  0.0 },
  {  0.42532501,  0.688191,  0.58778501 },
  {  0.86418802,  0.44286299,  0.238856 },
  {  0.688191,  0.58778501,  0.42532501 },
  {  0.809017,  0.309017,  0.5 },
  {  0.68171799,  0.14762101,  0.71656698 },
  {  0.58778501,  0.42532501,  0.688191 },
  {  0.955423,  0.29524201,  0.0 },
  {  1.0,  0.0,  0.0 },
  {  0.951056,  0.16246,  0.26286599 },
  {  0.85065103, -0.52573103,  0.0 },
  {  0.955423, -0.29524201,  0.0 },
  {  0.86418802, -0.44286299,  0.238856 },
  {  0.951056, -0.16246,  0.26286599 },
  {  0.809017, -0.309017,  0.5 },
  {  0.68171799, -0.14762101,  0.71656698 },
  {  0.85065103,  0.0,  0.52573103 },
  {  0.86418802,  0.44286299, -0.238856 },
  {  0.809017,  0.309017, -0.5 },
  {  0.951056,  0.16246, -0.26286599 },
  {  0.52573103,  0.0, -0.85065103 },
  {  0.68171799,  0.14762101, -0.71656698 },
  {  0.68171799, -0.14762101, -0.71656698 },
  {  0.85065103,  0.0, -0.52573103 },
  {  0.809017, -0.309017, -0.5 },
  {  0.86418802, -0.44286299, -0.238856 },
  {  0.951056, -0.16246, -0.26286599 },
  {  0.14762101,  0.71656698, -0.68171799 },
  {  0.309017,  0.5, -0.809017 },
  {  0.42532501,  0.688191, -0.58778501 },
  {  0.44286299,  0.238856, -0.86418802 },
  {  0.58778501,  0.42532501, -0.688191 },
  {  0.688191,  0.58778501, -0.42532501 },
  { -0.14762101,  0.71656698, -0.68171799 },
  { -0.309017,  0.5, -0.809017 },
  {  0.0,  0.52573103, -0.85065103 },
  { -0.52573103,  0.0, -0.85065103 },
  { -0.44286299,  0.238856, -0.86418802 },
  { -0.29524201,  0.0, -0.955423 },
  { -0.16246,  0.26286599, -0.951056 },
  {  0.0,  0.0, -1.0 },
  {  0.29524201,  0.0, -0.955423 },
  {  0.16246,  0.26286599, -0.951056 },
  { -0.44286299, -0.238856, -0.86418802 },
  { -0.309017, -0.5, -0.809017 },
  { -0.16246, -0.26286599, -0.951056 },
  {  0.0, -0.85065103, -0.52573103 },
  { -0.14762101, -0.71656698, -0.68171799 },
  {  0.14762101, -0.71656698, -0.68171799 },
  {  0.0, -0.52573103, -0.85065103 },
  {  0.309017, -0.5, -0.809017 },
  {  0.44286299, -0.238856, -0.86418802 },
  {  0.16246, -0.26286599, -0.951056 },
  {  0.238856, -0.86418802, -0.44286299 },
  {  0.5, -0.809017, -0.309017 },
  {  0.42532501, -0.688191, -0.58778501 },
  {  0.71656698, -0.68171799, -0.14762101 },
  {  0.688191, -0.58778501, -0.42532501 },
  {  0.58778501, -0.42532501, -0.688191 },
  {  0.0, -0.955423, -0.29524201 },
  {  0.0, -1.0,  0.0 },
  {  0.26286599, -0.951056, -0.16246 },
  {  0.0, -0.85065103,  0.52573103 },
  {  0.0, -0.955423,  0.29524201 },
  {  0.238856, -0.86418802,  0.44286299 },
  {  0.26286599, -0.951056,  0.16246 },
  {  0.5, -0.809017,  0.309017 },
  {  0.71656698, -0.68171799,  0.14762101 },
  {  0.52573103, -0.85065103,  0.0 },
  { -0.238856, -0.86418802, -0.44286299 },
  { -0.5, -0.809017, -0.309017 },
  { -0.26286599, -0.951056, -0.16246 },
  { -0.85065103, -0.52573103,  0.0 },
  { -0.71656698, -0.68171799, -0.14762101 },
  { -0.71656698, -0.68171799,  0.14762101 },
  { -0.52573103, -0.85065103,  0.0 },
  { -0.5, -0.809017,  0.309017 },
  { -0.238856, -0.86418802,  0.44286299 },
  { -0.26286599, -0.951056,  0.16246 },
  { -0.86418802, -0.44286299,  0.238856 },
  { -0.809017, -0.309017,  0.5 },
  { -0.688191, -0.58778501,  0.42532501 },
  { -0.68171799, -0.14762101,  0.71656698 },
  { -0.44286299, -0.238856,  0.86418802 },
  { -0.58778501, -0.42532501,  0.688191 },
  { -0.309017, -0.5,  0.809017 },
  { -0.14762101, -0.71656698,  0.68171799 },
  { -0.42532501, -0.688191,  0.58778501 },
  { -0.16246, -0.26286599,  0.951056 },
  {  0.44286299, -0.238856,  0.86418802 },
  {  0.16246, -0.26286599,  0.951056 },
  {  0.309017, -0.5,  0.809017 },
  {  0.14762101, -0.71656698,  0.68171799 },
  {  0.0, -0.52573103,  0.85065103 },
  {  0.42532501, -0.688191,  0.58778501 },
  {  0.58778501, -0.42532501,  0.688191 },
  {  0.688191, -0.58778501,  0.42532501 },
  { -0.955423,  0.29524201,  0.0 },
  { -0.951056,  0.16246,  0.26286599 },
  { -1.0,  0.0,  0.0 },
  { -0.85065103,  0.0,  0.52573103 },
  { -0.955423, -0.29524201,  0.0 },
  { -0.951056, -0.16246,  0.26286599 },
  { -0.86418802,  0.44286299, -0.238856 },
  { -0.951056,  0.16246, -0.26286599 },
  { -0.809017,  0.309017, -0.5 },
  { -0.86418802, -0.44286299, -0.238856 },
  { -0.951056, -0.16246, -0.26286599 },
  { -0.809017, -0.309017, -0.5 },
  { -0.68171799,  0.14762101, -0.71656698 },
  { -0.68171799, -0.14762101, -0.71656698 },
  { -0.85065103,  0.0, -0.52573103 },
  { -0.688191,  0.58778501, -0.42532501 },
  { -0.58778501,  0.42532501, -0.688191 },
  { -0.42532501,  0.688191, -0.58778501 },
  { -0.42532501, -0.688191, -0.58778501 },
  { -0.58778501, -0.42532501, -0.688191 },
  { -0.688191, -0.58778501, -0.42532501 }
};

unsigned char DirToByte(vec3_t const* dir)
{
	int	i, best;
	float d, bestd;

	if (!dir) {
		return 0;
	}

	bestd = 0;
	best = 0;
	for (i = 0; i < sizeof(bytedirs)/sizeof(bytedirs[0]); i++)
	{
		d = (dir->x * bytedirs[i].x) + (dir->y * bytedirs[i].y) + (dir->z * bytedirs[i].z);	//DotProduct(dir, bytedirs[i]);
		if (d > bestd)
		{
			bestd = d;
			best = i;
		}
	}
	return best;
}

void ByteToDir(int b, vec3_t* dir)
{
	if (b > 0xA1)
	{
		*dir = vec3_origin;
	}
	else
	{
		*dir = bytedirs[b];
	}
}

void Vec3ProjectionCoords(vec3_t const* dir, int* xCoord, int* yCoord)
{
	float v3; // xmm1_4
	float v4; // xmm0_4
	float v5; // xmm2_4

	v3 = dir->x * dir->x;
	v4 = dir->z * dir->z;
	v5 = dir->y * dir->y;
	if (v4 < v3 || v4 < v5)
	{
		if (v5 < v3 || v5 < v4)
		{
			if (dir->x <= 0.0)
			{
				*xCoord = 2;
				*yCoord = 1;
			}
			else
			{
				*xCoord = 1;
				*yCoord = 2;
			}
		}
		else if (dir->y <= 0.0)
		{
			*xCoord = 0;
			*yCoord = 2;
		}
		else
		{
			*xCoord = 2;
			*yCoord = 0;
		}
	}
	else if (dir->z <= 0.0)
	{
		*xCoord = 1;
		*yCoord = 0;
	}
	else
	{
		*xCoord = 0;
		*yCoord = 1;
	}
}

float vectoyaw(vec2_t const* vec)
{
	float yaw;

	if (vec->v[YAW] == 0 && vec->v[PITCH] == 0) {
		yaw = 0;
	}
	else {
		if (vec->v[PITCH]) {
			yaw = (atan2(vec->v[YAW], vec->v[PITCH]) * 180 / M_PI);
		}
		else if (vec->v[YAW] > 0) {
			yaw = 90;
		}
		else {
			yaw = 270;
		}
		if (yaw < 0) {
			yaw += 360;
		}
	}

	return yaw;
}

float vectosignedyaw(vec2_t const* vec)
{
	double yaw;

	if (vec->v[YAW] == 0 && vec->v[PITCH] == 0) {
		yaw = 0;
	}
	else {
		if (vec->v[PITCH]) {
			yaw = (atan2(vec->v[YAW], vec->v[PITCH]) * 180 / M_PI);
		}
		else if (vec->v[YAW] > 0) {
			yaw = 90;
		}
		else {
			yaw = 270;
		}
		if (yaw < 0) {
			yaw += 360;
		}
	}

	return yaw;
}

float vectopitch(vec3_t const* vec)
{
	float pitch;

	if (vec->y == 0 && vec->x == 0) {
		pitch = 0;
	}
	else {
		if (vec->x) {
			pitch = (atan2(vec->y, vec->x) * 180 / M_PI);
		}
		else if (vec->y > 0) {
			pitch = 90;
		}
		else {
			pitch = 270;
		}
		if (pitch < 0) {
			pitch += 360;
		}
	}

	return pitch;
}

void vectoangles(vec3_t const* vec, vec3_t* angles)
{
	float forward;
	float yaw, pitch;

	if (vec->v[1] == 0 && vec->v[0] == 0) {
		yaw = 0;
		if (vec->v[2] > 0) {
			pitch = 90;
		}
		else {
			pitch = 270;
		}
	}
	else {
		if (vec->v[0]) {
			yaw = (atan2(vec->v[1], vec->v[0]) * 180 / M_PI);
		}
		else if (vec->v[1] > 0) {
			yaw = 90;
		}
		else {
			yaw = 270;
		}
		if (yaw < 0) {
			yaw += 360;
		}

		forward = sqrt(vec->v[0] * vec->v[0] + vec->v[1] * vec->v[1]);
		pitch = (atan2(vec->v[2], forward) * 180 / M_PI);
		if (pitch < 0) {
			pitch += 360;
		}
	}

	angles->v[PITCH] = -pitch;
	angles->v[YAW] = yaw;
	angles->v[ROLL] = 0;
}

void YawVectors(float yaw, vec3_t* forward, vec3_t* right)
{
	float sy, cy;

	cy = cos(yaw * 0.017453292);
	sy = sin(yaw * 0.017453292);
	if (forward) {
		forward->x = cy;
		forward->v[YAW] = sy;
	}
	if (right) {
		right->x = sy;
		right->v[YAW] = -cy;
	}
}

void YawVectors2D(float yaw, vec2_t* forward, vec2_t* right)
{
	float sy, cy;
	cy = cos(yaw * 0.017453292);
	sy = sin(yaw * 0.017453292);
	if (forward) {
		forward->v[PITCH] = cy;
		forward->v[YAW] = sy;
	}
	if (right) {
		right->v[PITCH] = sy;
		right->v[YAW] = -cy;
	}
}

void VectorScale(vec3_t const* v, float scale, vec3_t* out)
{
	out->v[0] = v->v[0] * scale;
	out->v[1] = v->v[1] * scale;
	out->v[2] = v->v[2] * scale;
}

float VectorNormalize(vec3_t* v)
{
	float length, ilength;

	length = v->v[0] * v->v[0] + v->v[1] * v->v[1] + v->v[2] * v->v[2];
	length = sqrt(length);

	if (length) {
		ilength = 1 / length;
		v->v[0] *= ilength;
		v->v[1] *= ilength;
		v->v[2] *= ilength;
	}

	return length;
}

void PerpendicularVector(vec3_t const* src, vec3_t* dst)
{
	int pos;
	vec3_t srcSq;

	srcSq.v[0] = Square(src->v[0]);
	srcSq.v[1] = Square(src->v[1]);
	srcSq.v[2] = Square(src->v[2]);
	pos = srcSq.v[0] > srcSq.v[1];
	if (srcSq.v[pos] > srcSq.v[2]) {
		pos = 2;
	}
	VectorScale(src, -src->v[pos], dst);
	dst->v[pos] = dst->v[pos] + 1.0;
	VectorNormalize(dst);
}

float PointToLineSegmentDistSq2D(vec2_t const*, vec2_t const*, vec2_t const*)
{
	return 0.0f;
}

float PointToLineSegmentDistSq(vec3_t const*, vec3_t const*, vec3_t const*)
{
	return 0.0f;
}

int BoxInPlanes(vec4_t const*, unsigned int, vec3_t const*, vec3_t const*)
{
	return 0;
}

int SphereInPlanes(vec4_t const*, unsigned int, vec3_t const*, float)
{
	return 0;
}

float identityMatrix44[] =
{ 1.0, 0.0, 0.0, 0.0,
   0.0, 1.0, 0.0, 0.0,
   0.0, 0.0, 1.0, 0.0,
   0.0, 0.0, 0.0, 1.0
};

float identityMatrix33[] =
{ 1.0, 0.0, 0.0,
   0.0, 1.0, 0.0,
   0.0, 0.0, 1.0,
};

void MatrixIdentity33(vec3_t* out)
{
	Com_Memcpy(out, identityMatrix33, sizeof(identityMatrix33));
}

void MatrixIdentity44(vec4_t* out)
{
	Com_Memcpy(out, identityMatrix44, sizeof(identityMatrix44));
}

void MatrixMultiply(vec3_t const* in1, vec3_t const* in2, vec3_t* out)
{
	out->x = ((in1->x * in2->x) + (in2[1].x * in1->y)) + (in2[2].x * in1->z);
	out->y = ((in2[1].y * in1->y) + (in2->y * in1->x)) + (in2[2].y * in1->z);
	out->z = ((in2[1].z * in1->y) + (in2->z * in1->x)) + (in2[2].z * in1->z);
	out[1].x = ((in1[1].y * in2[1].x) + (in1[1].x * in2->x)) + (in1[1].z * in2[2].x);
	out[1].y = ((in1[1].y * in2[1].y) + (in1[1].x * in2->y)) + (in1[1].z * in2[2].y);
	out[1].z = ((in1[1].y * in2[1].z) + (in1[1].x * in2->z)) + (in1[1].z * in2[2].z);
	out[2].x = ((in2[1].x * in1[2].y) + (in2->x * in1[2].x)) + (in2[2].x * in1[2].z);
	out[2].y = ((in2[1].y * in1[2].y) + (in2->y * in1[2].x)) + (in2[2].y * in1[2].z);
	out[2].z = ((in2[1].z * in1[2].y) + (in2->z * in1[2].x)) + (in2[2].z * in1[2].z);
}

void MatrixVecMultiply(vec3_t const* mulMat, vec3_t const* mulVec, vec3_t* solution)
{
	solution->x = ((mulMat->y * mulVec->y) + (mulMat->x * mulVec->x)) + (mulMat->z * mulVec->z);
	solution->y = ((mulMat[1].y * mulVec->y) + (mulMat[1].x * mulVec->x)) + (mulMat[1].z * mulVec->z);
	solution->z = ((mulMat[2].y * mulVec->y) + (mulMat[2].x * mulVec->x)) + (mulMat[2].z * mulVec->z);
}

void MatrixVecMultiplyProject(vec4_t const* mulMat, vec3_t const* mulVec, vec3_t* solution)
{
	solution->x = ((((mulMat->v[1] * mulVec->y) + (mulMat->v[0] * mulVec->x)) + (mulMat->v[2] * mulVec->z)) + mulMat->v[3]) * 1.0 / ((((mulMat[3].v[1] * mulVec->y) + (mulMat[3].v[0] * mulVec->x)) + (mulMat[3].v[2] * mulVec->z)) + mulMat[3].v[3]);
	solution->y = ((((mulMat[1].v[1] * mulVec->y) + (mulMat[1].v[0] * mulVec->x)) + (mulMat[1].v[2] * mulVec->z)) + mulMat[1].v[3]) * (1.0 / ((((mulMat[3].v[1] * mulVec->y) + (mulMat[3].v[0] * mulVec->x)) + (mulMat[3].v[2] * mulVec->z)) + mulMat[3].v[3]));
	solution->z = ((((mulMat[2].v[1] * mulVec->y) + (mulMat[2].v[0] * mulVec->x)) + (mulMat[2].v[2] * mulVec->z)) + mulMat[2].v[3]) * (1.0 / ((((mulMat[3].v[1] * mulVec->y) + (mulMat[3].v[0] * mulVec->x)) + (mulMat[3].v[2] * mulVec->z)) + mulMat[3].v[3]));
}

void MatrixMultiply43(vec3_t const* in1, vec3_t const* in2, vec3_t* out)
{
	out->x = ((in1->x * in2->x) + (in2[1].x * in1->y)) + (in2[2].x * in1->z);
	out[1].x = ((in1[1].y * in2[1].x) + (in1[1].x * in2->x)) + (in1[1].z * in2[2].x);
	out[2].x = ((in1[2].y * in2[1].x) + (in1[2].x * in2->x)) + (in1[2].z * in2[2].x);
	out->y = ((in2[1].y * in1->y) + (in2->y * in1->x)) + (in2[2].y * in1->z);
	out[1].y = ((in1[1].y * in2[1].y) + (in1[1].x * in2->y)) + (in1[1].z * in2[2].y);
	out[2].y = ((in1[2].y * in2[1].y) + (in1[2].x * in2->y)) + (in1[2].z * in2[2].y);
	out->z = ((in1->x * in2->z) + (in1->y * in2[1].z)) + (in2[2].z * in1->z);
	out[1].z = ((in1[1].y * in2[1].z) + (in1[1].x * in2->z)) + (in1[1].z * in2[2].z);
	out[2].z = ((in1[2].y * in2[1].z) + (in1[2].x * in2->z)) + (in1[2].z * in2[2].z);
	out[3].x = (((in1[3].y * in2[1].x) + (in1[3].x * in2->x)) + (in1[3].z * in2[2].x)) + in2[3].x;
	out[3].y = (((in1[3].y * in2[1].y) + (in1[3].x * in2->y)) + (in1[3].z * in2[2].y)) + in2[3].y;
	out[3].z = (((in1[3].y * in2[1].z) + (in1[3].x * in2->z)) + (in1[3].z * in2[2].z)) + in2[3].z;
}

void MatrixMultiply44(vec4_t const* in1, vec4_t const* in2, vec4_t* out)
{
	out[0] = in1[0] * in2[0] + in1[1] * in2[4] + in1[2] * in2[8] + in1[3] * in2[12];
	out[1] = in1[0] * in2[1] + in1[1] * in2[5] + in1[2] * in2[9] + in1[3] * in2[13];
	out[2] = in1[0] * in2[2] + in1[1] * in2[6] + in1[2] * in2[10] + in1[3] * in2[14];
	out[3] = in1[0] * in2[3] + in1[1] * in2[7] + in1[2] * in2[11] + in1[3] * in2[15];
	out[4] = in1[4] * in2[0] + in1[5] * in2[4] + in1[6] * in2[8] + in1[7] * in2[12];
	out[5] = in1[4] * in2[1] + in1[5] * in2[5] + in1[6] * in2[9] + in1[7] * in2[13];
	out[6] = in1[4] * in2[2] + in1[5] * in2[6] + in1[6] * in2[10] + in1[7] * in2[14];
	out[7] = in1[4] * in2[3] + in1[5] * in2[7] + in1[6] * in2[11] + in1[7] * in2[15];
	out[8] = in1[8] * in2[0] + in1[9] * in2[4] + in1[10] * in2[8] + in1[11] * in2[12];
	out[9] = in1[8] * in2[1] + in1[9] * in2[5] + in1[10] * in2[9] + in1[11] * in2[13];
	out[10] = in1[8] * in2[2] + in1[9] * in2[6] + in1[10] * in2[10] + in1[11] * in2[14];
	out[11] = in1[8] * in2[3] + in1[9] * in2[7] + in1[10] * in2[11] + in1[11] * in2[15];
	out[12] = in1[12] * in2[0] + in1[13] * in2[4] + in1[14] * in2[8] + in1[15] * in2[12];
	out[13] = in1[12] * in2[1] + in1[13] * in2[5] + in1[14] * in2[9] + in1[15] * in2[13];
	out[14] = in1[12] * in2[2] + in1[13] * in2[6] + in1[14] * in2[10] + in1[15] * in2[14];
	out[15] = in1[12] * in2[3] + in1[13] * in2[7] + in1[14] * in2[11] + in1[15] * in2[15];
}

void MatrixTranspose(vec3_t const* in, vec3_t* out)
{
	out->x = in->x;
	out->y = in[1].x;
	out->z = in[2].x;
	out[1].x = in->y;
	out[1].y = in[1].y;
	out[1].z = in[2].y;
	out[2].x = in->z;
	out[2].y = in[1].z;
	out[2].z = in[2].z;
}

void MatrixTranspose44(vec4_t const* in, vec4_t* out)
{
	*out = *in;
	out[1] = in[4];
	out[2] = in[8];
	out[3] = in[12];
	out[4] = in[1];
	out[5] = in[5];
	out[6] = in[9];
	out[7] = in[13];
	out[8] = in[2];
	out[9] = in[6];
	out[10] = in[10];
	out[11] = in[14];
	out[12] = in[3];
	out[13] = in[7];
	out[14] = in[11];
	out[15] = in[15];
}

void MatrixInverse(vec3_t const* in, vec3_t* out)
{
	float det;

	det = ((((in[1].y * in[2].z) - (in[1].z * in[2].y)) * in->x) - (((in->y * in[2].z) - (in->z * in[2].y)) * in[1].x)) + (((in->y * in[1].z) - (in->z * in[1].y)) * in[2].x);

	out->x = ((in[1].y * in[2].z) - (in[1].z * in[2].y)) * (1.0 / det);
	out->y = -(((in[2].z * in->y) - (in[2].y * in->z)) * (1.0 / det));
	out->z = ((in[1].z * in->y) - (in[1].y * in->z)) * (1.0 / det);
	out[1].x = -(((in[1].x * in[2].z) - (in[1].z * in[2].x)) * (1.0 / det));
	out[1].y = ((in[2].z * in->x) - (in->z * in[2].x)) * (1.0 / det);
	out[1].z = -(((in[1].z * in->x) - (in[1].x * in->z)) * (1.0 / det));
	out[2].x = ((in[1].x * in[2].y) - (in[1].y * in[2].x)) * (1.0 / det);
	out[2].y = -(((in[2].y * in->x) - (in->y * in[2].x)) * (1.0 / det));
	out[2].z = ((in[1].y * in->x) - (in[1].x * in->y)) * (1.0 / det);
}

void MatrixInverseOrthogonal43(vec3_t const* in, vec3_t* out)
{
	vec3_t origin;
	float m_x, m_y, m_z;

	MatrixTranspose(in, out);
	m_x = 0.0 - in[3].x;
	m_y = 0.0 - in[3].y;
	m_z = 0.0 - in[3].z;
	origin.x = m_x;
	origin.v[1] = m_z;
	if (origin == out[3]) {
		m_x = origin.x;
		m_y = origin.y;
		m_z = origin.z;
	}
	out[3].x = ((out[1].x * m_x) + (out->x * m_x)) + (out[2].x * m_z);
	out[3].y = ((out->y * m_x) + (out[1].y * m_y)) + (out[2].y * m_z);
	out[3].z = ((out->z * m_x) + (out[1].z * m_y)) + (out[2].z * m_z);
}

void MatrixInverse44(const vec4_t* mat, vec4_t* dst)
{
	// Fuck this

	DirectX::XMMATRIX inMatrix, outMatrix;
	DirectX::XMVECTOR det;

	inMatrix.r[0] = *(__m128*)&mat;
	inMatrix.r[1] = *(__m128*)&mat[1];
	inMatrix.r[2] = *(__m128*)&mat[2];
	inMatrix.r[3] = *(__m128*)&mat[3];
	outMatrix = DirectX::XMMatrixInverse(&det, inMatrix);
	*(__m128 *)((unsigned int)dst & 0xFFFFFFF0) = outMatrix.r[0];
	*(__m128 *)((unsigned int)&dst[1] & 0xFFFFFFF0) = outMatrix.r[1];
	*(__m128 *)((unsigned int)&dst[2] & 0xFFFFFFF0) = outMatrix.r[2];
	*(__m128 *)((unsigned int)&dst[3] & 0xFFFFFFF0) = outMatrix.r[3];

	0xFFFFFFF0;
}

void MatrixTransformVector44(vec4_t const* vec, vec4_t const* mat, vec4_t* out)
{
	// More cancer pog
	*(__m128*)((unsigned int)out & 0xFFFFFFF0) = _mm_add_ps(
		_mm_add_ps(
			_mm_mul_ps(
				_mm_shuffle_ps(*(__m128*)vec, *(__m128*)vec, 255),
				*(__m128*)&mat[3]),
			_mm_mul_ps(
				_mm_shuffle_ps(*(__m128*)vec, *(__m128*)vec, 170),
				*(__m128*)&mat[2])),
		_mm_add_ps(
			_mm_mul_ps(
				_mm_shuffle_ps(*(__m128*)vec, *(__m128*)vec, 0),
				*(__m128*)&mat),
			_mm_mul_ps(
				_mm_shuffle_ps(*(__m128*)vec, *(__m128*)vec, 85),
				*(__m128*)&mat[1])));
}

void MatrixTransformVector43(vec3_t const* in1, vec3_t const* in2, vec3_t* out)
{
	out->x = (((in2[1].x * in1->y) + (in1->x * in2->x)) + (in2[2].x * in1->z)) + in2[3].x;
	out->y = (((in2->y * in1->x) + (in2[1].y * in1->y)) + (in2[2].y * in1->z)) + in2[3].y;
	out->z = (((in2->z * in1->x) + (in2[1].z * in1->y)) + (in2[2].z * in1->z)) + in2[3].z;
}

void MatrixTransposeTransformVector43(vec3_t const* in1, vec3_t const* in2, vec3_t* out)
{
	out->x = ((in2->y * in1->y - in2[3].y) + (in2->x * in1->x - in2[3].x)) + (in2->z * in1->z - in2[3].z);
	out->y = ((in2[1].y * in1->y - in2[3].y) + (in2[1].x * in1->x - in2[3].x)) + (in2[1].z * in1->z - in2[3].z);
	out->z = ((in2[2].y * in1->y - in2[3].y) + (in2[2].x * in1->x - in2[3].x)) + (in2[2].z * in1->z - in2[3].z);
}

void MatrixTransformVector43Equals(vec3_t* out, vec3_t const* in)
{
	out->z = (((in->z * out->x) + (in[1].z * out->y)) + (in[2].z * out->z)) + in[3].z;
	out->x = (((in[1].x * out->y) + (out->x * in->x)) + (in[2].x * out->z)) + in[3].x;
	out->y = (((in->y * out->x) + (in[1].y * out->y)) + (in[2].y * out->z)) + in[3].y;
}

void VectorAngleMultiply(vec2_t* vec, float angle)
{
	float x, y;
	x = cos(angle * 0.017453292);
	y = sin(angle * 0.017453292);
	vec->v[1] = (vec->v[1] * x) + (vec->v[0] * y);
	vec->v[0] = (vec->v[0] * x) - (vec->v[1] * y);
}

void UnitQuatToAxis(vec4_t const* quat, vec3_t* axis)
{
	float xw, xx, xz, yy, zw;
	xz = quat->v[2] * (quat->v[0] * 2.0);
	xw = quat->v[3] * (quat->v[0] * 2.0);
	xx = quat->v[0] * (quat->v[0] * 2.0);
	yy = quat->v[1] * (quat->v[1] * 2.0);
	zw = quat->v[3] * (quat->v[2] * 2.0);
	axis->x = 1.0 - ((quat->v[2] * (quat->v[2] * 2.0)) + yy);
	axis->y = zw + ((quat->v[1] * (quat->v[0] * 2.0)));
	axis->z = xz - (quat->v[3] * (quat->v[1] * 2.0));
	axis[1].x = (quat->v[1] * (quat->v[0] * 2.0)) - zw;
	axis[1].y = 1.0 - ((quat->v[2] * (quat->v[2] * 2.0)) + xx);
	axis[1].z = (quat->v[2] * (quat->v[1] * 2.0)) + xw;
	axis[2].x = quat->v[3] * (quat->v[1] * 2.0) + xz;
	axis[2].y = (quat->v[2] * (quat->v[1] * 2.0)) - xw;
	axis[2].z = 1.0 - (yy + xx);
}

void UnitQuatToForward(vec4_t const* quat, vec3_t* forward)
{
	forward->x = 1,0 - (((quat->v[1] * quat->v[1]) + (quat->v[2] * quat->v[2])) * 2.0);
	forward->y = ((quat->v[0] * quat->v[1]) + (quat->v[3] * quat->v[2])) * 2.0;
	forward->z = ((quat->v[0] * quat->v[2]) - (quat->v[3] * quat->v[1])) * 2.0;
}

void QuatSlerp(vec4_t const* from, vec4_t const* to, float frac, vec4_t* result)
{
	float dot, scaleFrom, scaleTo, acd, sacd;
	bool negative;

	dot = (((to->v[0] * from->v[0]) + (to->v[1] * from->v[1])) + (to->v[2] * from->v[2])) + (to->v[3] * from->v[3]);

	if (dot >= 0.0)
	{
		negative = false;
	}
	else
	{
		negative = true;
		dot = dot * -1.0;
	}
	if (dot <= 0.94999999)
	{
		acd = acosf(dot);
		sacd = sinf(acd);
		scaleTo = sinf(acd * frac) / sacd;
		scaleFrom = sinf(1.0 - (acd * frac)) / sacd;
	}
	else
	{
		scaleTo = frac;
		scaleFrom = 1.0 - frac;
	}
	if (negative)
	{
		result->v[0] = ((to->v[0] * scaleTo) * -1.0) + (from->v[0] * scaleFrom);
		result->v[1] = ((to->v[1] * scaleTo) * -1.0) + (scaleFrom * from->v[1]);
		result->v[2] = ((to->v[2] * scaleTo) * -1.0) + (from->v[2] * scaleFrom);
		result->v[3] = ((to->v[3] * scaleTo) * -1.0) + (from->v[3] * scaleFrom);
	}
	else
	{
		result->v[0] = (to->v[0] * scaleTo) + (from->v[0] * scaleFrom);
		result->v[1] = (to->v[1] * scaleTo) + (scaleFrom * from->v[1]);
		result->v[2] = (to->v[2] * scaleTo) + (from->v[2] * scaleFrom);
		result->v[3] = (to->v[3] * scaleTo) + (from->v[3] * scaleFrom);
	}
}

float RotationToYaw(vec2_t const* rot)
{
	float zz, r;

	zz = rot->v[0] * rot->v[0];
	r = (rot->v[1] * rot->v[1]) + zz;
	return atan2(rot->v[1] * rot->v[0] * (2.0 / r), 1.0 - 2.0 / r * zz) * 57.295776;
}

void FinitePerspectiveMatrix(float tanHalfFovX, float tanHalfFovY, float zNear, float zFar, vec4_t* mtx)
{
	memset(mtx, 0, 0x40u);
	mtx->v[0] = 1.0 / tanHalfFovX;
	mtx[1].v[1] = 1.0 / tanHalfFovY;
	mtx[2].v[2] = -(zNear / (zFar - zNear));
	mtx[2].v[3] = 1.0;
	mtx[3].v[2] = (zNear * zFar) / (zFar - zNear);
}

void SpotLightViewMatrix(vec3_t const* direction, float rotation, vec4_t* mtx)
{
	vec4_t src;
	vec3_t dst;

	src.v[0] = -direction->x;
	src.v[1] = -direction->y;
	src.v[2] = -direction->z;
	PerpendicularVector((const vec3_t*)&src, &dst);
}

void SpotLightViewMatrixDir3(vec3_t const*, vec3_t const*, vec3_t const*, vec4_t* const)
{
}

void SpotLightProjectionMatrix(float, float, float, vec4_t* const)
{
}

void InfinitePerspectiveMatrix(float tanHalfFovX, float tanHalfFovY, float zNear, vec4_t* mtx)
{
	memset(mtx, 0, 0x40u);
	mtx->v[0] = 1.0 / tanHalfFovX;
	mtx[2].v[3] = 1.0;
	mtx[1].v[1] = 1.0 / tanHalfFovY;
	mtx[3].v[2] = zNear;
}

void MatrixForViewer(vec3_t const* origin, vec3_t const* axis, vec4_t* mtx)
{
	mtx->v[0] = -axis[1].x;
	mtx[1].v[0] = -axis[1].y;
	mtx[2].v[0] = -axis[1].z;
	mtx[3].v[0] = -(((origin->x * mtx->v[0]) + (origin->y * mtx[1].v[0])) + (-axis[1].z * origin->z));
	mtx->v[1] = axis[2].x;
	mtx[1].v[1] = axis[2].y;
	mtx[2].v[1] = axis[2].z;
	mtx[3].v[1] = -(((origin->x * mtx->v[1]) + (origin->y * mtx[1].v[1])) + (axis[2].z * origin->z));
	mtx->v[2] = axis->x;
	mtx[1].v[2] = axis->y;
	mtx[2].v[2] = axis->z;
	mtx->v[3] = 0.0;
	mtx[1].v[3] = 0.0;
	mtx[2].v[3] = 0.0;
	mtx[3].v[2] = -(((origin->y * mtx[1].v[2]) + (mtx->v[2] * origin->x)) + (axis->z * origin->z));
	mtx[3].v[3] = 1.0;
}

void AnglesSubtract(vec3_t const* v1, vec3_t const* v2, vec3_t* v3)
{
	v3->x = AngleNormalize180(v1->x - v2->x);
	v3->y = AngleNormalize180(v1->y - v2->y);
	v3->z = AngleNormalize180(v1->z - v2->z);
}

void AnglesSubtract(vec2_t const* v1, vec2_t const* v2, vec2_t* v3)
{
	v3->x = AngleNormalize180(v1->x - v2->x);
	v3->y = AngleNormalize180(v1->y - v2->y);
}

float RadiusFromBounds2DSq(vec2_t const*, vec2_t const*)
{
	return 0.0f;
}

void ExtendBounds(vec3_t* mins, vec3_t* maxs, vec3_t const* offset)
{
	if (offset->x <= 0.0)
		mins->x = mins->x + offset->x;
	else
		maxs->x = maxs->x + offset->x;
	if (offset->y <= 0.0)
		mins->y = mins->y + offset->y;
	else
		maxs->y = maxs->y + offset->y;
	if (offset->z <= 0.0)
		mins->z = mins->z + offset->z;
	else
		maxs->z = maxs->z + offset->z;
}

void ExpandBoundsToWidth(vec3_t* mins, vec3_t* maxs)
{
	float subX, subZ;
	subX = maxs->x - mins->x;
	subZ = maxs->z - mins->z;
	if ((subX - (maxs->y - mins->y)) < 0.0)
		subX = maxs->y - mins->y;
	if (subX > subZ)
	{
		mins->z = mins->z - ((subX - subZ) * 0.5);
		maxs->z = maxs->z + ((subX - subZ) * 0.5);
	}
}

void _ClearBounds(vec3_t* mins, vec3_t* maxs)
{
	mins->x = minBounds;
	mins->y = minBounds;
	mins->z = minBounds;
	maxs->x = maxBounds;
	maxs->y = maxBounds;
	maxs->z = maxBounds;
}

void AddPointToBounds(vec3_t const* v, vec3_t* mins, vec3_t* maxs)
{
	if (mins->x > v->x)
		mins->x = v->x;
	if (v->x > maxs->x)
		maxs->x = v->x;
	if (mins->y > v->y)
		mins->y = v->y;
	if (v->y > maxs->y)
		maxs->y = v->y;
	if (mins->z > v->z)
		mins->z = v->z;
	if (v->z > maxs->z)
		maxs->z = v->z;
}

void AddPointToBounds2D(vec2_t const* v, vec2_t* mins, vec2_t* maxs)
{
	if (mins->v[0] > v->v[0])
		mins->v[0] = v->v[0];
	if (v->v[0] > maxs->v[0])
		maxs->v[0] = v->v[0];
	if (mins->v[1] > v->v[1])
		mins->v[1] = v->v[1];
	if (v->v[1] > maxs->v[1])
		maxs->v[1] = v->v[1];
}

bool BoundsOverlap(vec3_t const* mins0, vec3_t const* maxs0, vec3_t const* mins1, vec3_t const* maxs1)
{
	return mins0->x <= maxs1->x
		&& mins1->x <= maxs0->x
		&& mins0->y <= maxs1->y
		&& mins1->y <= maxs0->y
		&& mins0->z <= maxs1->z
		&& mins1->z <= maxs0->z;
}

void ExpandBounds(vec3_t const* addedmins, vec3_t const* addedmaxs, vec3_t* mins, vec3_t* maxs)
{
	if (mins->x > addedmins->x)
		mins->x = addedmins->x;
	if (addedmaxs->x > maxs->x)
		maxs->x = addedmaxs->x;
	if (mins->y > addedmins->y)
		mins->y = addedmins->y;
	if (addedmaxs->y > maxs->y)
		maxs->y = addedmaxs->y;
	if (mins->z > addedmins->z)
		mins->z = addedmins->z;
	if (addedmaxs->z > maxs->z)
		maxs->z = addedmaxs->z;
}

void AxisClear(vec3_t* axis)
{
	axis->x = 1.0f;
	axis->v[2] = 0.0f;
	axis[1].v[1] = 1.0f;
	axis[2].x = 0.0f;
	axis[2].z = 1.0f;
}

void Vec3PackNormAxis(vec3_t const* const, vec3_t* const)
{
	// It exists but doesn't ???
}

void AxisCopy(vec3_t const* in, vec3_t* out)
{
	out[0] = in[0];
	out[1] = in[1];
	out[2] = in[2];
}

void AxisTranspose(vec3_t const* in, vec3_t* out)
{
	out->x = in->x;
	out->y = in[1].x;
	out->z = in[2].x;
	out[1].x = in->y;
	out[1].y = in[1].y;
	out[1].z = in[2].y;
	out[2].x = in->z;
	out[2].y = in[1].z;
	out[2].z = in[2].z;
}

void AxisTransformVec3(vec3_t const* axes, vec3_t const* vec, vec3_t* out)
{
	out->x = ((axes[1].x * vec->y) + (axes->x * vec->x)) + (axes[2].x * vec->z);
	out->y = ((axes[1].y * vec->y) + (axes->y * vec->x)) + (axes[2].y * vec->z);
	out->z = ((axes[1].z * vec->y) + (axes->z * vec->x)) + (axes[2].z * vec->z);
}

void YawToAxis(float yaw, vec3_t* axis)
{
	if (axis)
	{
		axis->x = cos(yaw * 0.017453292);
		*&axis->v[1] = sin(yaw * 0.017453292);
	}
	axis[2].x = 0.0f;
	axis[2].z = 1.0f;
	axis[1].x = 0.0 - (sinf(yaw * 0.017453292));
	axis[1].y = 0.0 - -(cosf(yaw * 0.017453292));
	axis[1].z = vec3_origin.z;
}

void AxisToAngles(vec3_t const* axis, vec3_t* angles)
{
	float pitcha, pitchb, pitch, fSin, fSina, fCos, fCosa;
	vec3_t right;

	vectoangles(axis, angles);
	right = axis[1];
	pitcha = -angles->y * 0.017453292;
	fCos = cos(pitcha);
	fSin = sin(pitcha);
	right.y = (right.x * fSin) + (right.y * fCos);
	pitchb = -angles->x * 0.017453292;
	fCosa = cos(pitchb);
	fSina = sin(pitchb);
	right.x = (right.z * fSina) + (((right.x * fCos) - right.y * fSin) * fCosa);
	right.z = (right.z * fCosa) - (((right.x * fCos) - right.y * fSin) * fSina);
	pitch = vectosignedpitch(&right);
	if (right.y >= 0.0)
	{
		angles->z = -pitch;
	}
	else if (pitch >= 0.0)
	{
		angles->z = pitch + -180.0;
	}
	else
	{
		angles->z = pitch + 180.0;
	}
}

void Axis4ToAngles(vec4_t const* axis, vec3_t* angles)
{
	float pitcha, pitchb, pitch, fSin, fSina, fCos, fCosa;
	vec4_t right;

	vectoangles((const vec3_t*)axis, angles);
	right = axis[1];
	pitcha = -angles->y * 0.017453292;
	fCos = cos(pitcha);
	fSin = sin(pitcha);
	right.v[1] = (right.v[0] * fSin) + (right.v[1] * fCos);
	pitchb = -angles->x * 0.017453292;
	fCosa = cos(pitchb);
	fSina = sin(pitchb);
	right.v[0] = (right.v[2] * fSina) + (((right.v[0] * fCos) - (right.v[1] * fSin)) * fCosa);
	right.v[2] = (right.v[2] * fCosa) - (((right.v[0] * fCos) - (right.v[1] * fSin)) * fSina);
	pitch = vectosignedpitch((const vec3_t*)&right);
	if (right.v[1] >= 0.0)
	{
		angles->z = -pitch;
	}
	else if (pitch >= 0.0)
	{
		angles->z = pitch + -180.0;
	}
	else
	{
		angles->z = pitch + 180.0;
	}
}

int IntersectPlanes(float const** plane, vec3_t* xyz)
{
	float det;

	det = ((plane[1][1] * plane[2][2] - plane[2][1] * plane[1][2]) * plane[0][0])
		+ ((plane[2][1] * plane[0][2] - plane[0][1] * plane[2][2]) * plane[1][0])
		+ ((plane[0][1] * plane[1][2] - plane[1][1] * plane[0][2]) * plane[2][0]);

	if (fabsf(det) >= 0.001000000047497451) {
		float revdet = 1.0f / det;

		xyz->x = ((plane[1][1] * plane[2][2] - plane[2][1] * plane[1][2]) * plane[0][3])
			+ ((plane[2][1] * plane[0][2] - plane[0][1] * plane[2][2]) * plane[1][3])
			+ ((plane[0][1] * plane[1][2] - plane[1][1] * plane[0][2]) * plane[2][3]);
		xyz->y = ((plane[1][2] * plane[2][0] - plane[2][2] * plane[1][0]) * plane[0][3])
			+ ((plane[2][2] * plane[0][0] - plane[0][2] * plane[2][0]) * plane[1][3])
			+ ((plane[0][2] * plane[1][0] - plane[1][2] * plane[0][0]) * plane[2][3]);
		xyz->z = ((plane[1][0] * plane[2][1] - plane[2][0] * plane[1][1]) * plane[0][3])
			+ ((plane[2][0] * plane[0][1] - plane[0][0] * plane[2][1]) * plane[1][3])
			+ ((plane[0][0] * plane[1][1] - plane[1][0] * plane[0][1]) * plane[2][3]);

		VectorScale(xyz, revdet, xyz);

		return 1;
	}
	
	return 0;
}

int ProjectedWindingContainsCoplanarPoint(vec3_t const* verts, int vertCount, int x, int y, vec3_t const* point)
{
	// IDA copypasta is the best pasta.

	int v5;
	float* v6;
	float* i;
	int v9;
	int vertIndex;

	vertIndex = 0;
	if (vertCount <= 0)
		return 1;
	v9 = 0;
	v5 = 4 * (3 * vertCount - 3);
	v6 = (float*)&verts->x + x;
	for (i = (float*)&verts->x + y;
		(float)((float)((float)(*(&point->x + y) - *(float*)((char*)&verts->x + 4 * y + v5))
			* (float)(*(float*)((char*)&verts->x + 4 * x + v5) - *v6))
			+ (float)((float)(*(&point->x + x) - *(float*)((char*)&verts->x + 4 * x + v5))
				* (float)(*i - *(float*)((char*)&verts->x + 4 * y + v5)))) >= 0.0;
		i += 3)
	{
		v5 = v9;
		++vertIndex;
		v9 += 12;
		v6 += 3;
		if (vertIndex >= vertCount)
			return 1;
	}
	return 0;
}

int PlaneFromPoints(vec4_t* plane, vec3_t const* v0, vec3_t const* v1, vec3_t const* v2)
{
	vec3_t v1_v0, v2_v0;

	v1_v0.x = v1->x - v0->x;
	v1_v0.y = v1->y - v0->y;
	v1_v0.z = v1->z - v0->z;

	v2_v0.x = v2->x - v0->x;
	v2_v0.y = v2->y - v0->y;
	v2_v0.z = v2->z - v0->z;

	Vec3Cross(&v2_v0, &v1_v0, (vec3_t*)plane);
}

void ProjectPointOnPlane(vec3_t const* p, vec3_t const* normal, vec3_t* dst)
{
	dst->x = (normal->x * (-(((p->y * normal->y) + (normal->x * p->x)) + (p->z * normal->z)))) + p->x;
	dst->y = ((-(((p->y * normal->y) + (normal->x * p->x)) + (p->z * normal->z))) * normal->y) + p->y;
	dst->z = ((-(((p->y * normal->y) + (normal->x * p->x)) + (p->z * normal->z))) * normal->z) + p->z;
}

void SetPlaneSignbits(cplane_s* out)
{
	unsigned __int8 bit; // al

	bit = out->normal.x < 0.0;
	if (out->normal.y < 0.0)
		bit |= 2u;
	if (out->normal.z < 0.0)
		bit |= 4u;
	out->signbits = bit;
}

int BoxOnPlaneSide(vec3_t const* emins, vec3_t const* emaxs, cplane_s* p)
{
	
}

int IsPosInsideArc(vec3_t const*, float, vec3_t const*, float, float, float, float)
{
	return 0;
}

float Q_rint(float in)
{
	return floorf(in + 0.5);
}

float ColorNormalize(vec3_t const* in, vec3_t* out)
{
	float max;

	max = in->x;
	if (in->y > max)
	{
		max = in->y;
	}
	if (in->z > max)
	{
		max = in->z;
	}
	if (max == 0.0)
	{
		out->z = 1.0f;
		out->y = 1.0f;
		out->x = 1.0f;
		return 0.0f;
	}
	else
	{
		out->x = in->x * (float)(1.0 / max);
		out->y = in->y * (float)(1.0 / max);
		out->z = in->z * (float)(1.0 / max);
		return max;
	}
}

void ColorSRGBtoLinear(vec3_t const* in, vec3_t* out)
{
}

float PitchForYawOnNormal(float fYaw, vec3_t const* normal)
{
	vec3_t* forward;

	YawVectors(fYaw, forward, 0);

	if (normal->z != 0)
	{
		return atan2((normal->x * forward->x + normal->y * forward->y) / normal->z, 1.0) * 180.0 * M_PI;
	}
	return 270.0;
}

void NearestPitchAndYawOnPlane(vec3_t const* angles, vec3_t const* normal, vec3_t* result)
{
	vec3_t forward;
	vec3_t projected;

	AngleVectors(angles, &forward, 0, 0);
	ProjectPointOnPlane(&forward, normal, &projected);
	vectoangles(&projected, result);
}

void Rand_Init(int seed)
{
	holdrand_0 = seed;
}

unsigned int* GetRandSeed(void)
{
	return &holdrand_0;
}

float flrand(float min, float max)
{
	holdrand_0 = 214013 * holdrand_0 + 2531011;
	return min + (max - min) * (holdrand_0 >> 17) * 0.000030517578;
}

int irand(int min, int max)
{
	holdrand_0 = 214013 * holdrand_0 + 2531011;
	return min + (((max - min) * (holdrand_0 >> 17)) >> 15);
}

void AxisToQuat(vec3_t const* const, vec4_t*)
{
}

void QuatLerp(vec4_t const* qa, vec4_t const* qb, float frac, vec4_t* out)
{
	if (((((qb->v[1] * qa->v[1]) + (qa->v[0] * qb->v[0])) + (qa->v[2] * qb->v[2])) + (qa->v[3] * qb->v[3])) < 0.0)
	{
		out->v[0] = -qb->v[0];
		out->v[1] = -qb->v[1];
		out->v[2] = -qb->v[2];
		out->v[3] = -qb->v[3];
		out->v[0] = ((out->v[0] - qa->v[0]) * frac) + qa->v[0];
		out->v[1] = ((out->v[1] - qa->v[1]) * frac) + qa->v[1];
		out->v[2] = ((out->v[2] - qa->v[2]) * frac) + qa->v[2];
		out->v[3] = ((out->v[3] - qa->v[3]) * frac) + qa->v[3];
	}
	else
	{
		out->v[0] = ((qb->v[0] - qa->v[0]) * frac) + qa->v[0];
		out->v[1] = ((qb->v[1] - qa->v[1]) * frac) + qa->v[1];
		out->v[2] = ((qb->v[2] - qa->v[2]) * frac) + qa->v[2];
		out->v[3] = ((qb->v[3] - qa->v[3]) * frac) + qa->v[3];
	}
}

bool CullBoxFromCone(vec3_t const* coneOrg, vec3_t const* coneDir, float cosHalfFov, vec3_t const* boxCenter, vec3_t const* boxHalfSize)
{
	bool result;
	float v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23;

	if (coneDir->x < 0.0)
		v7 = -1.0f;
	else
		v7 = 1.0f;
	v8 = (boxCenter->x - coneOrg->x) - (boxHalfSize->x * v7);
	v21 = coneDir->y;
	if (v21 < 0.0)
		v9 = -1.0f;
	else
		v9 = 1.0f;
	v22 = boxHalfSize->y;
	v10 = (boxCenter->y - coneOrg->y) - (v22 * v9);
	v11 = coneDir->z;
	if (v11 >= 0.0)
		v6 = 1.0f;
	else
		v6 = -1.0f;
	v12 = (boxCenter->z - coneOrg->z) - (boxHalfSize->z * v6);
	v13 = ((v21 * v10) + (coneDir->x * v8)) + (v11 * v12);
	result = 1;
	if (v13 < 0.0)
	{
		v15 = (coneDir->x * -v13) + v8;
		v16 = (v21 * -v13) + v10;
		v17 = (v11 * -v13) + v12;
		v18 = ((v16 * v16) + (v15 * v15)) + (v17 * v17);
		v23 = v13 * v13;
		v19 = 1.0 - (cosHalfFov * cosHalfFov);
		if ((v23 * v19) >= ((cosHalfFov * cosHalfFov) * v18)
			|| (v20 = cosHalfFov / sqrtf(v19 * v18),
				((((((((v15 * v20) + coneDir->x) * (boxCenter->x - coneOrg->x))
					+ (((v16 * v20) + v21) * (boxCenter->y - coneOrg->y)))
					+ (((v17 * v20) + coneDir->z) * (boxCenter->z - coneOrg->z)))
					- boxHalfSize->x * ((v15 * v20) + coneDir->x))
					- v22 * ((v16 * v20) + v21))
					- boxHalfSize->z * ((v17 * v20) + coneDir->z)) < 0.0))
		{
			result = 0;
		}
	}
	return result;
}

bool CullBoxFromSphere(vec3_t const* sphereOrg, float radius, vec3_t const* boxCenter, vec3_t const* boxHalfSize)
{
	float v4; // xmm3_4
	float v5; // xmm2_4
	float v6; // xmm0_4

	if ((sphereOrg->x - boxCenter->x - boxHalfSize->x) < 0.0)
		v4 = 0.0;
	else
		v4 = sphereOrg->x - boxCenter->x - boxHalfSize->x;
	if ((sphereOrg->y - boxCenter->y - boxHalfSize->y) < 0.0)
		v5 = 0.0;
	else
		v5 = sphereOrg->y - boxCenter->y - boxHalfSize->y;
	v6 = sphereOrg->z - boxCenter->z - boxHalfSize->z;
	if (v6 < 0.0)
		v6 = 0.0;
	return (((v4 * v4) + (v5 * v5)) + (v6 * v6)) > (radius * radius);
}

bool CullBoxFromConicSectionOfSphere(vec3_t const*, vec3_t const*, float, float, vec3_t const*, vec3_t const*)
{
	return false;
}

bool CullSphereFromCone(vec3_t const* coneOrg, vec3_t const* coneDir, float cosHalfFov, vec3_t const* sphereCenter, float radius)
{
	return false;
}

void colorTempToXYZ(float, vec4_t*)
{
}

void colorTempMatrix(vec4_t* finalMatrix, float colorTemp)
{
}

void colorHueMatrix(vec4_t* finalMatrix, float hue)
{
}

void colorSaturationMatrix(vec4_t* finalMatrix, float saturation)
{
	finalMatrix->v[0] = ((1.0 - saturation) * 0.25) + saturation;
	finalMatrix->v[1] = ((1.0 - saturation) * 0.25);
	finalMatrix->v[2] = ((1.0 - saturation) * 0.25);
	finalMatrix[2].v[0] = ((1.0 - saturation) * 0.25);
	finalMatrix[2].v[1] = ((1.0 - saturation) * 0.25);
	finalMatrix->v[3] = 0.0;
	finalMatrix[1].v[0] = ((1.0 - saturation) * 0.5);
	finalMatrix[1].v[1] = ((1.0 - saturation) * 0.5) + saturation;
	finalMatrix[1].b = ((1.0 - saturation) * 0.5);
	finalMatrix[2].v[2] = ((1.0 - saturation) * 0.25) + saturation;
	finalMatrix[3].v[1] = 0.0;
	finalMatrix[3].v[2] = 0.0;
	finalMatrix[3].v[3] = 1.0;
}

float I_fnormPDF(float x)
{
	return (1.0 / sqrt(2.0 * M_PI)) * exp(-0.5 * x * x);
}

float I_fnormCDF(float x)
{
	return I_normCDF(x);
}

void RotatePointAroundVector(vec3_t* dst, vec3_t const* dir, vec3_t const* point, float degrees)
{
	unsigned int v11;
	float rad, v12, v13, v14; // [esp+2Ch] [ebp-9Ch]
	vec3_t vup; // [esp+34h] [ebp-94h] BYREF
	vec3_t vf; // [esp+40h] [ebp-88h] BYREF
	vec3_t vr; // [esp+4Ch] [ebp-7Ch] BYREF
	vec3_t m[3]; // [esp+58h] [ebp-70h]
	vec3_t tmpmat[3]; // [esp+7Ch] [ebp-4Ch]
	vec3_t rot[3]; // [esp+A0h] [ebp-28h]

	vf.y = dir->y;
	vf.x = dir->x;
	vf.z = dir->z;
	vup.x = dir->x * dir->x;
	vup.v[1] = dir->z * dir->z;
	vup.v[2] = dir->y * dir->y;
	v11 = vup.x > dir->y * dir->y;
	if (*(&vup.x + v11) > (dir->z * dir->z))
		v11 = 2;
	v12 = *(&dir->x + v11);
	vr.x = dir->x * v12;
	vr.y = dir->y * v12;
	vr.z = dir->z * v12;
	*(&vr.x + v11) = *(&vr.x + v11) + 1.0;
	v13 = sqrtf(((vr.y * vr.y) + (vr.x * vr.x)) + (vr.z * vr.z));
	if (v13 >= 0.0)
		v13 = 1.0;
	v14 = 1.0 / v13;
	vr.x = vr.x * v14;
	vr.y = vr.y * v14;
	vr.z = vr.z * v14;
	Vec3Cross(&vr, &vf, &vup);
	m[0].x = vr.x;
	m[1].y = vup.y;
	m[2].z = vf.z;
	rot[0].v[2] = 0.0;
	rot[0].v[3] = 0.0;
	rot[2].x = 0.0;
	rot[2].y = 0.0;
	rot[2].z = 1.0;
	rot[1].v[1] = 1.0;
	rot[0].x = 1.0;
	rad = degrees * 0.017453292;
	rot[0].x = cos(rad);
	rot[0].y = sin(rad);
	tmpmat[1].x = ((rot[0].y * vup.y) + (rot[0].x * vr.y)) + (rot[2].x * vf.y);
	tmpmat[2].x = ((rot[0].y * vup.z) + (rot[0].x * vr.z)) + (rot[2].x * vf.z);
	tmpmat[1].z = ((rot[1].z * vup.y) + (rot[0].z * vr.y)) + (rot[2].z * vf.y);
	tmpmat[2].z = ((rot[1].z * vup.z) + (rot[0].z * vr.z)) + (rot[2].z * vf.z);
	rot[0].x = (((((rot[0].x * vup.x) + (rot[0].y * vr.x)) + (rot[2].y * vf.x)) * vup.x) + ((((rot[0].y * vup.x) + (rot[0].x * vr.x)) + (rot[2].x * vf.x)) * m[0].x)) + ((((rot[1].z * vup.x) + (rot[0].z * vr.x)) + (rot[2].z * vf.x)) * vf.x);
	rot[0].z = (((((rot[0].x * vup.x) + (rot[0].y * vr.x)) + (rot[2].y * vf.x)) * vup.z) + ((((rot[0].y * vup.x) + (rot[0].x * vr.x)) + (rot[2].x * vf.x)) * vr.z)) + ((((rot[1].z * vup.x) + (rot[0].z * vr.x)) + (rot[2].z * vf.x)) * m[2].z);
	rot[1].z = (((((rot[0].x * vup.y) + (rot[0].y * vr.y)) + (rot[2].y * vf.y)) * vup.z) + (tmpmat[1].x * vr.z)) + (tmpmat[1].z * m[2].z);
	dst->x = ((((((((rot[0].x * vup.x) + (rot[0].y * vr.x)) + (rot[2].y * vf.x)) * m[1].y) + ((((rot[0].y * vup.x) + (rot[0].x * vr.x)) + (rot[2].x * vf.x)) * vr.y)) + ((((rot[1].z * vup.x) + (rot[0].z * vr.x)) + (rot[2].z * vf.x)) * vf.y)) * point->y) + (rot[0].x * point->x)) + (rot[0].z * point->z);
	dst->y = ((((((((rot[0].x * vup.y) + (rot[0].y * vr.y)) + (rot[2].y * vf.y)) * m[1].y) + (tmpmat[1].x * vr.y)) + (tmpmat[1].z * vf.y)) * point->y) + (((((((rot[0].x * vup.y) + (rot[0].y * vr.y)) + (rot[2].y * vf.y)) * vup.x) + (tmpmat[1].x * m[0].x)) + (tmpmat[1].z * vf.x)) * point->x)) + (rot[1].z * point->z);
	dst->z = ((((((((rot[0].x * vup.z) + (rot[0].y * vr.z)) + (rot[2].y * vf.z)) * m[1].y) + (tmpmat[2].x * vr.y)) + (tmpmat[2].z * vf.y)) * point->y) + (((((((rot[0].x * vup.z) + (rot[0].y * vr.z)) + (rot[2].y * vf.z)) * vup.x) + (tmpmat[2].x * m[0].x)) + (tmpmat[2].z * vf.x)) * point->x)) + (((((((rot[0].x * vup.z) + (rot[0].y * vr.z)) + (rot[2].y * vf.z)) * vup.z) + (tmpmat[2].x * vr.z)) + (tmpmat[2].z * m[2].z)) * point->z);
}

void Vec3Basis_RightHanded(vec3_t const* forward, vec3_t* left, vec3_t* up)
{
	float v3; // xmm3_4
	const char* v4; // eax
	float v5; // xmm1_4
	float v6; // xmm2_4
	int v7; // eax
	float v8; // xmm0_4
	float v9; // xmm0_4
	float v10; // xmm3_4
	int v11[3]; // [esp+2Ch] [ebp-10h]

	v3 = 1.0;
	v5 = forward->y * forward->y;
	v6 = forward->z * forward->z;
	v11[0] = forward->x * forward->x;
	v11[1] = v5;
	v11[2] = v6;
	v7 = v11[0] > v5;
	if (v11[v7] > v6)
		v7 = 2;
	v8 = -(forward->x + v7);
	up->x = forward->x * v8;
	up->y = v8 * forward->y;
	up->z = v8 * forward->z;
	*(&up->x + v7) = *(&up->x + v7) + v3;
	v9 = sqrtf(((up->x * up->x) + (up->y * up->y)) + (up->z * up->z));
	if (-v9 >= 0.0)
		v9 = v3;
	v10 = v3 / v9;
	up->x = up->x * v10;
	up->y = up->y * v10;
	up->z = up->z * v10;
	Vec3Cross(up, forward, left);
}

void UnitQuatToAngles(vec4_t const* quat, vec3_t* angles)
{
	vec3_t axis[3];

	UnitQuatToAxis(quat, axis);
	AxisToAngles(axis, angles);
}

float RadiusFromBounds(vec3_t const* mins, vec3_t const* maxs)
{
	float v2;
	float v3;
	float v5;
	float v6;

	v2 = mins->x;
	if (v2 <= maxs->x)
		v2 = maxs->x;
	v6 = v2;
	v3 = mins->y;
	if (v3 <= maxs->y)
		v3 = maxs->y;
	if (mins->z <= maxs->z)
		v5 = maxs->z;
	else
		v5 = mins->z;
	return sqrtf(v5 * v5 + v3 * v3 + v6 * v6);
}

float RadiusFromBounds2D(vec2_t const* mins, vec2_t const* maxs)
{
	float v2;
	float v4;

	v2 = mins->v[0];
	if (v2 <= maxs->v[0])
		v2 = maxs->v[0];
	if (mins->v[1] <= maxs->v[1])
		v4 = maxs->v[1];
	else
		v4 = mins->v[1];
	return sqrtf(v4 * v4 + v2 * v2);
}

void SnapPointToIntersectingPlanes(float const** planes, vec3_t* xyz, float snapGrid, float snapEpsilon)
{
	float v4; // xmm3_4
	vec3_t* v5; // eax
	int v6; // edx
	int axis; // esi
	float v8; // xmm0_4
	const float* v9; // eax
	float v10; // xmm2_4
	float v11; // xmm4_4
	float v12; // xmm5_4
	const float* v13; // eax
	const float* v14; // eax
	float v15; // xmm6_4
	vec3_t snapped; // [esp+10h] [ebp-10h] BYREF

	v4 = snapEpsilon;
	v5 = xyz;
	v6 = &snapped - xyz;
	axis = 3;
	do
	{
		v8 = (((1.0 / snapGrid) * v5->x) + 9.313225746154785e-10) * snapGrid;
		if (snapEpsilon <= v8 - v5->x)
			*(&v5->x + v6) = v5->x;
		else
			*(&v5->x + v6) = v8;
		v5 = (v5 + 4);
		--axis;
	}   while (axis);
	if (snapped.x != xyz->x || snapped.y != xyz->y || snapped.z != xyz->z)
	{
		v10 = 0.0;
		if (
			((((*planes)[1] * snapped.y) + (**planes * snapped.x)) + ((*planes)[2] * snapped.z))
			- (*planes)[3] > 0.0)
			v10 = ((((*planes)[1] * snapped.y) + (**planes * snapped.x)) + ((*planes)[2] * snapped.z)) - (*planes)[3];
		v11 = xyz->y;
		v12 = xyz->x;
		v9 = *planes;
		if ((((v9[1] * v11) + (*v9 * xyz->x)) + (v9[2] * xyz->z)) - v9[3] > snapEpsilon)
			v4 = (((v9[1] * v11) + (*v9 * xyz->x)) + (v9[2] * xyz->z)) - v9[3];
		v13 = planes[1];
		if ((((v13[1] * snapped.y) + (*v13 * snapped.x)) + (v13[2] * snapped.z)) - v13[3] > v10)
			v10 = (((v13[1] * snapped.y) + (*v13 * snapped.x)) + (v13[2] * snapped.z)) - v13[3];
		if ((((v13[1] * v11) + (*v13 * v12)) + (v13[2] * xyz->z)) - v13[3] > v4)
			v4 = (((v13[1] * v11) + (*v13 * v12)) + (v13[2] * xyz->z)) - v13[3];
		v14 = planes[2];
		v15 = snapped.z;
		if ((((v14[1] * snapped.y) + (*v14 * snapped.x)) + (v14[2] * snapped.z)) - v14[3] > v10)
			v10 = (((v14[1] * snapped.y) + (*v14 * snapped.x)) + (v14[2] * snapped.z)) - v14[3];
		if ((((v14[1] * v11) + (*v14 * v12)) + (v14[2] * xyz->z)) - v14[3] > v4)
			v4 = (((v14[1] * v11) + (*v14 * v12)) + (v14[2] * xyz->z)) - v14[3];
		if (v4 > v10)
		{
			*&xyz->x = *&snapped.x;
			xyz->z = v15;
		}
	}
}
