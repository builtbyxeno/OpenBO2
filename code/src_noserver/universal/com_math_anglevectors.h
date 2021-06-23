#ifndef COM_MATH_ANGLEVECTORS_H
#define COM_MATH_ANGLEVECTORS_H

#define RadiansConstant 0.017453292
#define PIInverseFraction 0.31830987

void AngleVectors(union vec3_t const*, union vec3_t*, union vec3_t*, union vec3_t*);
void AnglesToAxis(union vec3_t const*, union vec3_t*);
void AnglesToQuat(union vec3_t const*, union vec4_t*);
void QuatToAxis(union vec4_t const*, union vec3_t*);
void vectosignedangles(union vec3_t const*, union vec3_t*);
float vectosignedpitch(union vec3_t const*);
void AxisToSignedAngles(union vec3_t const*, union vec3_t*);

#endif // COM_MATH_ANGLEVECTORS_H