#ifndef COM_MATH_H
#define COM_MATH_H

#define M_PI 3.14159265358979323846f

#define	PITCH 0	// up / down
#define	YAW	1	// left / right
#define	ROLL 2	// fall over

#define minBounds 131072.0f
#define maxBounds -131072.0f

#define Square(x) ((x)*(x))

extern "C" {
	static unsigned int holdrand_0 = 2309737967;

	inline float AngleNormalize360(const float angle) {
		float sa;
		float result;

		sa = angle * 0.0027777778;
		result = (sa - floor(sa)) * 360.0;

		if ((result - 360.0) < 0.0)
		{
			return result;
		}

		return result - 360.0;
	}
	inline float AngleNormalize180(float angle) {
		angle = AngleNormalize360(angle);
		if (angle > 180.0) {
			angle -= 360.0;
		}
		return angle;
	}
	void TRACK_com_math(void);
	double I_normCDF(double);
	float random(void);
	float crandom(void);
	int RandWithSeed(int*);
	double LinearTrack(float, float, float, float);
	float LinearTrackAngle(float, float, float, float);
	float DiffTrack(float, float, float, float);
	float DiffTrackAngle(float, float, float, float);
	float GraphGetValueFromFraction(int, const union vec2_t*, float);
	float Q_acos(float);
	char ClampChar(const int);
	short ClampShort(const int);
	unsigned char DirToByte(union vec3_t const*);
	void ByteToDir(int, union vec3_t*);
	int VecNCompareCustomEpsilon(union vec3_t const*, union vec3_t const*, float, int);
	void Vec3ProjectionCoords(union vec3_t const*, int*, int*);
	float vectoyaw(union vec2_t const*);
	float vectosignedyaw(union vec2_t const*);
	float vectopitch(union vec3_t const*);
	void vectoangles(union vec3_t const*, union vec3_t*);
	void YawVectors(float, union vec3_t*, union vec3_t*);
	void YawVectors2D(float, union vec2_t*, union vec2_t*);
	void VectorScale(vec3_t const* v, float scale, vec3_t* out);
	float VectorNormalize2(const vec3_t* v, vec3_t* out);
	void PerpendicularVector(union vec3_t const*, union vec3_t*);
	float PointToLineSegmentDistSq2D(union vec2_t const*, union vec2_t const*, union vec2_t const*);
	float PointToLineSegmentDistSq(union vec3_t const*, union vec3_t const*, union vec3_t const*);
	int BoxInPlanes(union vec4_t const*, unsigned int, union vec3_t const*, union vec3_t const*);
	int SphereInPlanes(union vec4_t const*, unsigned int, union vec3_t const*, float);
	void MatrixIdentity33(union vec3_t*);
	void MatrixIdentity44(union vec4_t*);
	void MatrixMultiply(union vec3_t const*, union vec3_t const*, union vec3_t*);
	void MatrixVecMultiply(union vec3_t const*, union vec3_t const*, union vec3_t*);
	void MatrixVecMultiplyProject(union vec4_t const* const, union vec3_t const*, union vec3_t*);
	void MatrixMultiply43(union vec3_t const* const, union vec3_t const* const, union vec3_t* const);
	void MatrixMultiply44(union vec4_t const* const, union vec4_t const* const, union vec4_t* const);
	void MatrixTranspose(union vec3_t const* const, union vec3_t* const);
	void MatrixTranspose44(union vec4_t const* const, union vec4_t* const);
	void MatrixInverse(union vec3_t const* const, union vec3_t* const);
	void MatrixInverseOrthogonal43(union vec3_t const* const, union vec3_t* const);
	void MatrixInverse44(union vec4_t const* const, union vec4_t* const);
	void MatrixTransformVector44(union vec4_t const*, union vec4_t const* const, union vec4_t*);
	void MatrixTransformVector43(union vec3_t const*, union vec3_t const* const, union vec3_t*);
	void MatrixTransposeTransformVector43(union vec3_t const*, union vec3_t const* const, union vec3_t*);
	void MatrixTransformVector43Equals(union vec3_t*, union vec3_t const* const);
	void VectorAngleMultiply(union vec2_t*, float);
	void UnitQuatToAxis(union vec4_t const*, union vec3_t*);
	void UnitQuatToForward(union vec4_t const*, union vec3_t*);
	void QuatSlerp(union vec4_t const*, union vec4_t const*, float, union vec4_t*);
	float RotationToYaw(union vec2_t const*);
	void FinitePerspectiveMatrix(float, float, float, float, union vec4_t*);
	void SpotLightViewMatrix(union vec3_t const*, float, union vec4_t* const);
	void SpotLightViewMatrixDir3(union vec3_t const*, union vec3_t const*, union vec3_t const*, union vec4_t* const);
	void SpotLightProjectionMatrix(float, float, float, union vec4_t* const);
	void InfinitePerspectiveMatrix(float, float, float, union vec4_t* const);
	void MatrixForViewer(union vec3_t const*, union vec3_t const* const, union vec4_t* const);
	void AnglesSubtract(union vec3_t const*, union vec3_t const*, union vec3_t*);
	void AnglesSubtract(union vec2_t const*, union vec2_t const*, union vec2_t*);
	float AngleNormalize360(float);
	float RadiusFromBounds2DSq(union vec2_t const*, union vec2_t const*);
	void ExtendBounds(union vec3_t*, union vec3_t*, union vec3_t const*);
	void ExpandBoundsToWidth(union vec3_t*, union vec3_t*);
	void _ClearBounds(union vec3_t*, union vec3_t*);
	void AddPointToBounds(union vec3_t const*, union vec3_t*, union vec3_t*);
	void AddPointToBounds2D(union vec2_t const*, union vec2_t*, union vec2_t*);
	bool BoundsOverlap(union vec3_t const*, union vec3_t const*, union vec3_t const*, union vec3_t const*);
	void ExpandBounds(union vec3_t const*, union vec3_t const*, union vec3_t*, union vec3_t*);
	void AxisClear(union vec3_t* const);
	void Vec3PackNormAxis(union vec3_t const* const, union vec3_t* const);
	void AxisCopy(union vec3_t const* const, union vec3_t* const);
	void AxisTranspose(union vec3_t const* const, union vec3_t* const);
	void AxisTransformVec3(union vec3_t const* const, union vec3_t const*, union vec3_t*);
	void YawToAxis(float, union vec3_t* const);
	void AxisToAngles(union vec3_t const* const, union vec3_t*);
	void Axis4ToAngles(union vec4_t const* const, union vec3_t*);
	int IntersectPlanes(float const** const, union vec3_t*);
	int ProjectedWindingContainsCoplanarPoint(union vec3_t const* const, int, int, int, union vec3_t const*);
	int PlaneFromPoints(union vec4_t*, union vec3_t const*, union vec3_t const*, union vec3_t const*);
	void ProjectPointOnPlane(union vec3_t const*, union vec3_t const*, union vec3_t*);
	void SetPlaneSignbits(struct cplane_s*);
	int BoxOnPlaneSide(union vec3_t const*, union vec3_t const*, struct cplane_s const*);
	int IsPosInsideArc(union vec3_t const*, float, union vec3_t const*, float, float, float, float);
	float Q_rint(float);
	float ColorNormalize(union vec3_t const*, union vec3_t*);
	void ColorSRGBtoLinear(union vec3_t const*, union vec3_t*);
	float PitchForYawOnNormal(float, union vec3_t const*);
	void NearestPitchAndYawOnPlane(union vec3_t const*, union vec3_t const*, union vec3_t*);
	void Rand_Init(int);
	unsigned int* GetRandSeed(void);
	float flrand(float, float);
	int irand(int, int);
	void AxisToQuat(union vec3_t const* const, union vec4_t*);
	void QuatLerp(union vec4_t const*, union vec4_t const*, float, union vec4_t*);
	bool CullBoxFromCone(union vec3_t const*, union vec3_t const*, float, union vec3_t const*, union vec3_t const*);
	bool CullBoxFromSphere(union vec3_t const*, float, union vec3_t const*, union vec3_t const*);
	bool CullBoxFromConicSectionOfSphere(union vec3_t const*, union vec3_t const*, float, float, union vec3_t const*, union vec3_t const*);
	bool CullSphereFromCone(union vec3_t const*, union vec3_t const*, float, union vec3_t const*, float);
	void colorTempToXYZ(float, union vec4_t*);
	void colorTempMatrix(union vec4_t* const, float);
	void colorHueMatrix(union vec4_t* const, float);
	void colorSaturationMatrix(union vec4_t* const, float);
	float I_fnormPDF(float);
	float I_fnormCDF(float);
	void RotatePointAroundVector(union vec3_t*, union vec3_t const*, union vec3_t const*, float);
	void Vec3Basis_RightHanded(union vec3_t const*, union vec3_t*, union vec3_t*);
	void UnitQuatToAngles(union vec4_t const*, union vec3_t*);
	float RadiusFromBounds(union vec3_t const*, union vec3_t const*);
	float RadiusFromBounds2D(union vec2_t const*, union vec2_t const*);
	void SnapPointToIntersectingPlanes(float const** const, union vec3_t*, float, float);
}

#endif // COM_MATH_H