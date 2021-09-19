#include "types.h"
#include "functions.h"

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
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
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
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
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
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ClampChar
==============
*/
char ClampChar(const int i)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ClampShort
==============
*/
int ClampShort(const int i)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
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
int VecNCompareCustomEpsilon(const vec3_t *v0, const vec3_t *v1, float epsilon, int coordCount)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
Vec3ProjectionCoords
==============
*/
void Vec3ProjectionCoords(const vec3_t *dir, int *xCoord, int *yCoord)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
vectoyaw
==============
*/
void vectoyaw(vec2_t const &)
{
	UNIMPLEMENTED(__FUNCTION__);
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
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
YawVectors2D
==============
*/
void YawVectors2D(float yaw, vec2_t *forward, vec2_t *right)
{
	UNIMPLEMENTED(__FUNCTION__);
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
void MatrixInverse44(const vec4_t *mat, vec4_t *dst)
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
/*void QuatSlerp(float a1@<edi>, const vec4_t *from, const vec4_t *to, float frac, vec4_t *result)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
SpotLightViewMatrixDir3
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
RadiusFromBounds2DSq
==============
*/
double RadiusFromBounds2DSq(const vec2_t *mins, const vec2_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
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
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
AddPointToBounds2D
==============
*/
void AddPointToBounds2D(const vec2_t *v, vec2_t *mins, vec2_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
BoundsOverlap
==============
*/
BOOL BoundsOverlap(const vec3_t *mins0, const vec3_t *maxs0, const vec3_t *mins1, const vec3_t *maxs1)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
ExpandBounds
==============
*/
void ExpandBounds(const vec3_t *addedmins, const vec3_t *addedmaxs, vec3_t *mins, vec3_t *maxs)
{
	UNIMPLEMENTED(__FUNCTION__);
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
int ProjectedWindingContainsCoplanarPoint(
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

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
}

/*
==============
IsPosInsideArc
==============
*/
int IsPosInsideArc(
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
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
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
bool CullBoxFromCone(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CullBoxFromSphere
==============
*/
bool CullBoxFromSphere(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CullBoxFromConicSectionOfSphere
==============
*/
char CullBoxFromConicSectionOfSphere(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
CullSphereFromCone
==============
*/
bool CullSphereFromCone(
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}

/*
==============
colorTempToXYZ
==============
*/
/*int colorTempToXYZ@<eax>(int result@<eax>, float a2@<xmm0>)
{
	UNIMPLEMENTED(__FUNCTION__);
	return 0;
}*/

/*
==============
colorTempMatrix
==============
*/
/*void colorTempMatrix(__m128 a1@<xmm6>, vec4_t *finalMatrix, float colorTemp)
{
	UNIMPLEMENTED(__FUNCTION__);
}*/

/*
==============
colorHueMatrix
==============
*/

{
	UNIMPLEMENTED(__FUNCTION__);
	 tmp;
	return tmp;
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

