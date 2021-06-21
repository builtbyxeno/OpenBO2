#include "com_math.h"
#include <universal/com_vector.h>
#include <universal/q_shared.h>

void TRACK_com_math(void)
{
}

double I_normCDF(double)
{
	return 0.0;
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

int VecNCompareCustomEpsilon(vec3_t const* v0, vec3_t const* v1, float epsilon, int coordCount)
{
	int v4; // ecx
	const vec3_t* i; // eax

	v4 = 0;
	if (coordCount <= 0)
		return 1;
	for (i = v1; ((*(&i->x + v0 - v1) - i->x) * (*(&i->x + v0 - v1) - i->x)) <= (epsilon * epsilon); i = (i + 4))
	{
		if (++v4 >= coordCount)
			return 1;
	}
	return 0;
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

void MatrixInverse44(vec4_t const* mat, vec4_t* dst)
{
	float det;
	vec4_t row1, row2, row3, row4;

	row1 = mat[0]; // |  x  y  z  w  |
	row2 = mat[1]; // |  x  y  z  w  |
	row3 = mat[2]; // |  x  y  z  w  |
	row4 = mat[3]; // |  x  y  z  w  |

	det = row1.w * row2.z * row3.y * row4.x - row1.z * row2.w * row3.y * row4.x -
		row1.w * row2.y * row3.z * row4.x + row1.y * row2.w * row3.z * row4.x +
		row1.z * row2.y * row3.w * row4.x - row1.y * row2.z * row3.w * row4.x -
		row1.w * row2.z * row3.x * row4.y + row1.z * row2.w * row3.x * row4.y +
		row1.w * row2.x * row3.z * row4.y - row1.x * row2.w * row3.z * row4.y -
		row1.z * row2.x * row3.w * row4.y + row1.x * row2.z * row3.w * row4.y +
		row1.w * row2.y * row3.x * row4.z - row1.y * row2.w * row3.x * row4.z -
		row1.w * row2.x * row3.y * row4.z + row1.x * row2.w * row3.y * row4.z +
		row1.y * row2.x * row3.w * row4.z - row1.x * row2.y * row3.w * row4.z -
		row1.z * row2.y * row3.x * row4.w + row1.y * row2.z * row3.x * row4.w +
		row1.z * row2.x * row3.y * row4.w - row1.x * row2.z * row3.y * row4.w -
		row1.y * row2.x * row3.z * row4.w + row1.x * row2.y * row3.z * row4.w;

	dst[0].x = 0;
}

void MatrixTransformVector44(vec4_t const*, vec4_t const* const, vec4_t*)
{
}

void MatrixTransformVector43(vec3_t const*, vec3_t const* const, vec3_t*)
{
}

void MatrixTransposeTransformVector43(vec3_t const*, vec3_t const* const, vec3_t*)
{
}

void MatrixTransformVector43Equals(vec3_t*, vec3_t const* const)
{
}

void VectorAngleMultiply(vec2_t*, float)
{
}

void UnitQuatToAxis(vec4_t const*, vec3_t* const)
{
}

void UnitQuatToForward(vec4_t const*, vec3_t*)
{
}

void QuatSlerp(vec4_t const*, vec4_t const*, float, vec4_t*)
{
}

float RotationToYaw(vec2_t const*)
{
	return 0.0f;
}

void FinitePerspectiveMatrix(float, float, float, float, vec4_t* const)
{
}

void SpotLightViewMatrix(vec3_t const*, float, vec4_t* const)
{
}

void SpotLightViewMatrixDir3(vec3_t const*, vec3_t const*, vec3_t const*, vec4_t* const)
{
}

void SpotLightProjectionMatrix(float, float, float, vec4_t* const)
{
}

void InfinitePerspectiveMatrix(float, float, float, vec4_t* const)
{
}

void MatrixForViewer(vec3_t const*, vec3_t const* const, vec4_t* const)
{
}

void AnglesSubtract(vec3_t const*, vec3_t const*, vec3_t*)
{
}

void AnglesSubtract(vec2_t const*, vec2_t const*, vec2_t*)
{
}

float AngleNormalize360(float)
{
	return 0.0f;
}

float RadiusFromBounds2DSq(vec2_t const*, vec2_t const*)
{
	return 0.0f;
}

void ExtendBounds(vec3_t*, vec3_t*, vec3_t const*)
{
}

void ExpandBoundsToWidth(vec3_t*, vec3_t*)
{
}

void _ClearBounds(vec3_t*, vec3_t*)
{
}

void AddPointToBounds(vec3_t const*, vec3_t*, vec3_t*)
{
}

void AddPointToBounds2D(vec2_t const*, vec2_t*, vec2_t*)
{
}

int BoundsOverlap(vec3_t const*, vec3_t const*, vec3_t const*, vec3_t const*)
{
	return 0;
}

void ExpandBounds(vec3_t const*, vec3_t const*, vec3_t*, vec3_t*)
{
}

void AxisClear(vec3_t* const)
{
}

void Vec3PackNormAxis(vec3_t const* const, vec3_t* const)
{
}

void AxisCopy(vec3_t const* const, vec3_t* const)
{
}

void AxisTranspose(vec3_t const* const, vec3_t* const)
{
}

void AxisTransformVec3(vec3_t const* const, vec3_t const*, vec3_t*)
{
}

void YawToAxis(float, vec3_t* const)
{
}

void AxisToAngles(vec3_t const* const, vec3_t*)
{
}

void Axis4ToAngles(vec4_t const* const, vec3_t*)
{
}

int IntersectPlanes(float const** const, vec3_t*)
{
	return 0;
}

int ProjectedWindingContainsCoplanarPoint(vec3_t const* const, int, int, int, vec3_t const*)
{
	return 0;
}

int PlaneFromPoints(vec4_t*, vec3_t const*, vec3_t const*, vec3_t const*)
{
	return 0;
}

void ProjectPointOnPlane(vec3_t const*, vec3_t const*, vec3_t*)
{
}

void SetPlaneSignbits(cplane_s*)
{
}

int BoxOnPlaneSide(vec3_t const*, vec3_t const*, cplane_s const*)
{
	return 0;
}

int IsPosInsideArc(vec3_t const*, float, vec3_t const*, float, float, float, float)
{
	return 0;
}

float Q_rint(float)
{
	return 0.0f;
}

float ColorNormalize(vec3_t const*, vec3_t*)
{
	return 0.0f;
}

void ColorSRGBtoLinear(vec3_t const*, vec3_t*)
{
}

float PitchForYawOnNormal(float, vec3_t const*)
{
	return 0.0f;
}

void NearestPitchAndYawOnPlane(vec3_t const*, vec3_t const*, vec3_t*)
{
}

void Rand_Init(int)
{
}

unsigned int* GetRandSeed(void)
{
	return nullptr;
}

float flrand(float, float)
{
	return 0.0f;
}

int irand(int, int)
{
	return 0;
}

void AxisToQuat(vec3_t const* const, vec4_t*)
{
}

void QuatLerp(vec4_t const*, vec4_t const*, float, vec4_t*)
{
}

bool CullBoxFromCone(vec3_t const*, vec3_t const*, float, vec3_t const*, vec3_t const*)
{
	return false;
}

bool CullBoxFromSphere(vec3_t const*, float, vec3_t const*, vec3_t const*)
{
	return false;
}

bool CullBoxFromConicSectionOfSphere(vec3_t const*, vec3_t const*, float, float, vec3_t const*, vec3_t const*)
{
	return false;
}

bool CullSphereFromCone(vec3_t const*, vec3_t const*, float, vec3_t const*, float)
{
	return false;
}

void colorTempToXYZ(float, vec4_t*)
{
}

void colorTempMatrix(vec4_t* const, float)
{
}

void colorHueMatrix(vec4_t* const, float)
{
}

void colorSaturationMatrix(vec4_t* const, float)
{
}

float I_fnormPDF(float)
{
	return 0.0f;
}

float I_fnormCDF(float)
{
	return 0.0f;
}

void RotatePointAroundVector(vec3_t*, vec3_t const*, vec3_t const*, float)
{
}

void Vec3Basis_RightHanded(vec3_t const*, vec3_t*, vec3_t*)
{
}

void UnitQuatToAngles(vec4_t const*, vec3_t*)
{
}

float RadiusFromBounds(vec3_t const*, vec3_t const*)
{
	return 0.0f;
}

float RadiusFromBounds2D(vec2_t const*, vec2_t const*)
{
	return 0.0f;
}

void SnapPointToIntersectingPlanes(float const** const, vec3_t*, float, float)
{
}
