#include "types.h"

/*
==============
TRACK_com_math
==============
*/
void TRACK_com_math()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
I_normCDF
==============
*/
long double I_normCDF(long double x)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
random
==============
*/
double random()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
crandom
==============
*/
double crandom()
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RandWithSeed
==============
*/
int RandWithSeed(int *seed)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
LinearTrack
==============
*/
double LinearTrack(float tgt, float cur, float rate, float deltaTime)
{
	float v4 = rate * deltaTime;

	if ((tgt - cur) <= 0)
		v4 = -v4;

	const float v5 = fabs(tgt - cur);

	if (v5 <= 0.001 || fabs(v4) > v5)
		return tgt;
	else
		return v4 + cur;
}

/*
==============
LinearTrackAngle
==============
*/
double LinearTrackAngle(float tgt, float cur, float rate, float deltaTime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
DiffTrack
==============
*/
double DiffTrack(float tgt, float cur, float rate, float deltaTime)
{
	const float d = tgd - cur;
	const float step = rate * d * deltaTime;
	const float ad = fabs(d);

	if (ad <= 0.001 || fabs(step) > ad)
		return tgt;

	return cur + step;
}

/*
==============
DiffTrackAngle
==============
*/
double DiffTrackAngle(float tgt, float cur, float rate, float deltaTime)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
GraphGetValueFromFraction
==============
*/
double GraphGetValueFromFraction(const int knotCount, const vec2_t *knots, const float fraction)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Q_acos
==============
*/
double Q_acos(const float c)
{
	const float angle = acos(c);

	if (angle > M_PI)
		return static_cast<float>(M_PI);

	if (angle < -M_PI)
		return static_cast<float>(M_PI);

	return angle;
}

/*
==============
ClampChar
==============
*/
char ClampChar(const int i)
{
	if (i < CHAR_MIN)
		return CHAR_MIN;

	if (i > CHAR_MAX)
		return CHAR_MAX;

	return i;;
}

/*
==============
ClampShort
==============
*/
int ClampShort(const int i)
{
	if (i < SHRT_MIN)
		return SHRT_MIN;

	if (i > SHRT_MAX)
		return SHRT_MAX;

	return i;
}

/*
==============
DirToByte
==============
*/
unsigned __int8 DirToByte(const vec3_t *dir)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ByteToDir
==============
*/
void ByteToDir(const int b, vec3_t *dir)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VecNCompareCustomEpsilon
==============
*/
int VecNCompareCustomEpsilon(const float *v0, const float *v1, float epsilon, int coordCount)
{
	for (int i = 0; i < coordCount; ++i)
	{
		if ((v0[i] - v1[i]) * (v[i] - v1[i]) > epsilon * epsilon)
			return false;
	}

	return true;
}

/*
==============
Vec3ProjectionCoords
==============
*/
void Vec3ProjectionCoords(const vec3_t *dir, int *xCoord, int *yCoord)
{
	const float v3 = dir->x * dir->x;
	const float v4 = dir->z * dir->z;
	const float v5 = dir->y * dir->y;

	if (v4 < v3 || v4 < v5)
	{
		if (v5 < v3 || v5 < v4)
		{
			if (dir->x <= 0)
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

		else if (dir->y <= 0)
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

	else if (dir->z <= 0)
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

/*
==============
vectoyaw
==============
*/
void vectoyaw(vec2_t const &)
{
	if (vec.z == 0 && vec.y == 0)
		return 0;

	const float yaw = (atan2(vec.z, vec.y) * 180 / M_PI);

	if (yaw >= 0)
		return yaw;

	return yaw + 360;
}

/*
==============
vectosignedyaw
==============
*/
void vectosignedyaw(vec2_t const &)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
vectopitch
==============
*/
void vectopitch(vec3_t const &)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
vectoangles
==============
*/
void vectoangles(vec3_t const &,vec3_t &)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
YawVectors
==============
*/
void YawVectors(float yaw, vec3_t *forward, vec3_t *right)
{
	const float angle = yaw * 0.017453292;
	const float cy = cos(angle);
	const float sy = sin(angle);

	if (forward)
	{
		forward->x = cy;
		forward->y = sy;
		forward->z = 0;
	}

	if (right)
	{
		right->x = sy;
		right->y = -cy;
		right->z = 0;
	}
}

/*
==============
YawVectors2D
==============
*/
void YawVectors2D(float yaw, vec2_t *forward, vec2_t *right)
{
	const float angle = yaw * 0.017453292;
	const float cy = cos(angle);
	const float sy = sin(angle);

	if (forward)
	{
		forward->x = cy;
		forward->y = sy;
	}

	if (right)
	{
		right->x = sy;
		right->y = -cy;
	}
}

/*
==============
PerpendicularVector
==============
*/
void PerpendicularVector(const vec3_t *src, vec3_t *dst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PointToLineSegmentDistSq2D
==============
*/
double PointToLineSegmentDistSq2D(const vec2_t *point, const vec2_t *start, const vec2_t *end)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PointToLineSegmentDistSq
==============
*/
double PointToLineSegmentDistSq(const vec3_t *point, const vec3_t *start, const vec3_t *end)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
BoxInPlanes
==============
*/
int BoxInPlanes(const vec4_t *planes, unsigned int numPlanes, const vec3_t *mins, const vec3_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SphereInPlanes
==============
*/
int SphereInPlanes(const vec4_t *planes, unsigned int numPlanes, const vec3_t *center, const float radius)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
MatrixIdentity33
==============
*/
void MatrixIdentity33(vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatrixIdentity44
==============
*/
void MatrixIdentity44(vec4_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatrixMultiply
==============
*/
void MatrixMultiply(const vec3_t *in1, const vec3_t *in2, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatrixVecMultiply
==============
*/
void MatrixVecMultiply(const vec3_t *mulMat, const vec3_t *mulVec, vec3_t *solution)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatrixVecMultiplyProject
==============
*/
void MatrixVecMultiplyProject(const vec4_t *mulMat, const vec3_t *mulVec, vec3_t *solution)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatrixMultiply43
==============
*/
void MatrixMultiply43(const vec3_t *in1, const vec3_t *in2, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatrixMultiply44
==============
*/
void MatrixMultiply44(const vec4_t *in1, const vec4_t *in2, vec4_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatrixTranspose
==============
*/
void MatrixTranspose(const vec3_t *in, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatrixTranspose44
==============
*/
void MatrixTranspose44(const vec4_t *in, vec4_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatrixInverse
==============
*/
void MatrixInverse(const vec3_t *in, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatrixInverseOrthogonal43
==============
*/
void MatrixInverseOrthogonal43(const vec3_t *in, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatrixInverse44
==============
*/
void MatrixInverse44(int a1, const vec4_t *mat, vec4_t *dst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatrixTransformVector44
==============
*/
void MatrixTransformVector44(const vec4_t *vec, const vec4_t *mat, vec4_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatrixTransformVector43
==============
*/
void MatrixTransformVector43(const vec3_t *in1, const vec3_t *in2, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatrixTransposeTransformVector43
==============
*/
void MatrixTransposeTransformVector43(const vec3_t *in1, const vec3_t *in2, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatrixTransformVector43Equals
==============
*/
void MatrixTransformVector43Equals(vec3_t *out, const vec3_t *in)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
VectorAngleMultiply
==============
*/
void VectorAngleMultiply(vec2_t *vec, float angle)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UnitQuatToAxis
==============
*/
void UnitQuatToAxis(const vec4_t *quat, vec3_t *axis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UnitQuatToForward
==============
*/
void UnitQuatToForward(const vec4_t *quat, vec3_t *forward)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
QuatSlerp
==============
*/
void QuatSlerp(float theta, const vec4_t *from, const vec4_t *to, float frac, vec4_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RotationToYaw
==============
*/
long double RotationToYaw(const vec2_t *rot)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
FinitePerspectiveMatrix
==============
*/
void FinitePerspectiveMatrix(float tanHalfFovX, float tanHalfFovY, float zNear, float zFar, vec4_t *mtx)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpotLightViewMatrix
==============
*/
void SpotLightViewMatrix(int a1, const vec3_t *direction, float rotation, vec4_t *mtx)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpotLightViewMatrixDir3
==============
*/
void SpotLightViewMatrixDir3(int a1, const vec3_t *dirx, const vec3_t *diry, const vec3_t *dirz, vec4_t *mtx)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SpotLightProjectionMatrix
==============
*/
void SpotLightProjectionMatrix(float cosFov, float zNear, float zFar, vec4_t *mtx)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
InfinitePerspectiveMatrix
==============
*/
void InfinitePerspectiveMatrix(float tanHalfFovX, float tanHalfFovY, float zNear, vec4_t *mtx)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
MatrixForViewer
==============
*/
void MatrixForViewer(const vec3_t *origin, const vec3_t *axis, vec4_t *mtx)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AnglesSubtract
==============
*/
void AnglesSubtract(const vec3_t *v1, const vec3_t *v2, vec3_t *v3)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AnglesSubtract
==============
*/
void AnglesSubtract(const vec2_t *v1, const vec2_t *v2, vec2_t *v3)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AngleNormalize360
==============
*/
double AngleNormalize360(const float angle)
{
	return (360.0 / 65536) * (static_cast<int>(angle * (65536 / 360.0)) & 65535);
}

/*
==============
RadiusFromBounds2DSq
==============
*/
double RadiusFromBounds2DSq(const vec2_t *mins, const vec2_t *maxs)
{
	vec2_t corner;

	for (int i = 0; i < 2; ++i)
	{
		const float a = fabs(mins[i]);
		const float b = fabs(maxs[i]);
		if (a <= b)
			corner[i] = b;
		else
			corner[i] = a;
	}

	return corner.x * corner.x + corner.y * corner.y;
}

/*
==============
ExtendBounds
==============
*/
void ExtendBounds(vec3_t *mins, vec3_t *maxs, const vec3_t *offset)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ExpandBoundsToWidth
==============
*/
void ExpandBoundsToWidth(vec3_t *mins, vec3_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AddPointToBounds
==============
*/
void AddPointToBounds(const vec3_t *v, vec3_t *mins, vec3_t *maxs)
{
	if (v->x < mins->x)
		mins->x = v->x;

	if (v->x > maxs->x)
		maxs->x = v->x;

	if (v->y < mins->y)
		mins->y = v->y;

	if (v->y > maxs->y)
		maxs->y = v->y;

	if (v->z < mins->z)
		mins->z = v->z;

	if (v->z > maxs->z)
		maxs->z = v->z;
}

/*
==============
AddPointToBounds2D
==============
*/
void AddPointToBounds2D(const vec2_t *v, vec2_t *mins, vec2_t *maxs)
{
	if (mins->x > v->x)
		mins->x = v->x;

	if (v->x > maxs->x)
		maxs->x = v->x;

	if (mins->y > v->y)
		mins->y = v->y;

	if (v->y; > maxs->y)
		maxs->y = v->y;
}

/*
==============
BoundsOverlap
==============
*/
BOOL BoundsOverlap(const vec3_t *mins0, const vec3_t *maxs0, const vec3_t *mins1, const vec3_t *maxs1)
{
	return mins0->x <= maxs1->x
		&& mins1->x <= maxs0->x
		&& mins0->y <= maxs1->y
		&& mins1->y <= maxs0->y
		&& mins0->z <= maxs1->z
		&& mins1->z <= maxs0->z;
}

/*
==============
ExpandBounds
==============
*/
void ExpandBounds(const vec3_t *addedmins, const vec3_t *addedmaxs, vec3_t *mins, vec3_t *maxs)
{
	if (mins->x > addedmins->x)
		mins->x = addedmins->x;

	if (addedmaxs->x > maxs->x)
		maxs->x = addedmaxs->x;

	if (mins->y > addedmins->y;)
		mins->y = addedmins->y;

	if (addedmaxs->y > maxs->y)
		maxs->y = addedmaxs->y;

	if (mins->z > addedmins->z)
		mins->z = addedmins->z;

	if (addedmaxs->z > maxs->z)
		maxs->z = addedmaxs->z;
}

/*
==============
AxisClear
==============
*/
void AxisClear(vec3_t *axis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AxisCopy
==============
*/
void AxisCopy(const vec3_t *in, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AxisTranspose
==============
*/
void AxisTranspose(const vec3_t *in, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AxisTransformVec3
==============
*/
void AxisTransformVec3(const vec3_t *axes, const vec3_t *vec, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
YawToAxis
==============
*/
void YawToAxis(float yaw, vec3_t *axis)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AxisToAngles
==============
*/
void AxisToAngles(const vec3_t *axis, vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Axis4ToAngles
==============
*/
void Axis4ToAngles(const vec4_t *axis, vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
IntersectPlanes
==============
*/
int IntersectPlanes(const float **planein, vec3_t *xyz)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ProjectedWindingContainsCoplanarPoint
==============
*/
int ProjectedWindingContainsCoplanarPoint(const vec3_t *verts, int vertCount, int x, int y, const vec3_t *point)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
PlaneFromPoints
==============
*/
int PlaneFromPoints(vec4_t *plane, const vec3_t *v0, const vec3_t *v1, const vec3_t *v2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ProjectPointOnPlane
==============
*/
void ProjectPointOnPlane(const vec3_t *p, const vec3_t *normal, vec3_t *dst)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
SetPlaneSignbits
==============
*/
void SetPlaneSignbits(cplane_s *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BoxOnPlaneSide
==============
*/
int __cdecl BoxOnPlaneSide(const vec3_t *emins, const vec3_t *emaxs, const cplane_s *p, const cplane_s *pa, float a5, float a6, float a7)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
IsPosInsideArc
==============
*/
int IsPosInsideArc(const vec3_t *pos, float posRadius, const vec3_t *arcOrigin, float arcRadius, float arcAngle0, float arcAngle1, float arcHalfHeight)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Q_rint
==============
*/
double Q_rint(const float in)
{
	return floor(in + 0.5);
}

/*
==============
ColorNormalize
==============
*/
double ColorNormalize(const vec3_t *in, vec3_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ColorSRGBtoLinear
==============
*/
void ColorSRGBtoLinear(vec3_t const &,vec3_t &)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
PitchForYawOnNormal
==============
*/
long double PitchForYawOnNormal(const float fYaw, const vec3_t *normal)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
NearestPitchAndYawOnPlane
==============
*/
void NearestPitchAndYawOnPlane(const vec3_t *angles, const vec3_t *normal, vec3_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Rand_Init
==============
*/
void Rand_Init(int seed)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
GetRandSeed
==============
*/
unsigned int *GetRandSeed()
{
	UNIMPLEMENTED(__FUNCTION__);
	return NULL;
}

/*
==============
flrand
==============
*/
double flrand(float min, float max)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
irand
==============
*/
int irand(int min, int max)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
AxisToQuat
==============
*/
void AxisToQuat(const vec3_t *mat, vec4_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
QuatLerp
==============
*/
void QuatLerp(const vec4_t *qa, const vec4_t *qb, float frac, vec4_t *out)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
CullBoxFromCone
==============
*/
bool CullBoxFromCone(const vec3_t *coneOrg, const vec3_t *coneDir, float cosHalfFov, const vec3_t *boxCenter, const vec3_t *boxHalfSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CullBoxFromSphere
==============
*/
bool CullBoxFromSphere(const vec3_t *sphereOrg, float radius, const vec3_t *boxCenter, const vec3_t *boxHalfSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CullBoxFromConicSectionOfSphere
==============
*/
char CullBoxFromConicSectionOfSphere(const vec3_t *coneOrg, const vec3_t *coneDir, float cosHalfFov, float radius, const vec3_t *boxCenter, const vec3_t *boxHalfSize)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CullSphereFromCone
==============
*/
bool CullSphereFromCone(const vec3_t *coneOrg, const vec3_t *coneDir, float cosHalfFov, const vec3_t *sphereCenter, float radius)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
colorTempToXYZ
==============
*/
int colorTempToXYZ(int result, float a2)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
colorTempMatrix
==============
*/
void colorTempMatrix(__m128 a1, vec4_t *finalMatrix, float colorTemp)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
colorHueMatrix
==============
*/
void colorHueMatrix(float finalMatrix, __m128 a2, vec4_t *a3, float hue)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
colorSaturationMatrix
==============
*/
void colorSaturationMatrix(vec4_t *finalMatrix, float saturation)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
I_fnormPDF
==============
*/
long double I_fnormPDF(float x)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
I_fnormCDF
==============
*/
float I_fnormCDF(float x)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RotatePointAroundVector
==============
*/
void RotatePointAroundVector(vec3_t *dst, const vec3_t *dir, const vec3_t *point, const float degrees)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
Vec3Basis_RightHanded
==============
*/
void Vec3Basis_RightHanded(const vec3_t *forward, vec3_t *left, vec3_t *up)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
UnitQuatToAngles
==============
*/
void UnitQuatToAngles(const vec4_t *quat, vec3_t *angles)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
RadiusFromBounds
==============
*/
long double RadiusFromBounds(const vec3_t *mins, const vec3_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RadiusFromBounds2D
==============
*/
long double RadiusFromBounds2D(const vec2_t *mins, const vec2_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
SnapPointToIntersectingPlanes
==============
*/
void SnapPointToIntersectingPlanes(const float **planes, vec3_t *xyz, float snapGrid, float snapEpsilon)
{
	UNIMPLEMENTED(__FUNCTION__);
}

