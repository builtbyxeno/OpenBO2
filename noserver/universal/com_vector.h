/*
 * Copyright (c) 2020-2021 OpenIW
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef COM_VECTOR_H
#define COM_VECTOR_H

#include <DirectXMath.h>

typedef union vec2_t {
	float v[2];
	struct {
		float x;
		float y;
	};
} vec2_t;

typedef union vec3_t {
	struct {
		float x;
		float y;
		float z;
	};
	float v[3];
} vec3_t;

typedef union vec4_t {
	float v[4];
	struct {
		float x;
		float y;
		float z;
		float w;
	};
	struct {
		float r;
		float g;
		float b;
		float a;
	};
} vec4_t;

typedef struct orientation_t
{
	vec3_t origin;
	vec3_t axis[3];
} orientation_t;

vec2_t vec2_origin = { 0,0 };
vec3_t vec3_origin = { 0,0,0 };
vec4_t vec4_origin = { 0,0,0,0 };

inline bool operator ==(const vec3_t vec1, const vec3_t vec2) {
	if (vec1.x != vec2.x || vec1.y != vec2.y || vec1.z != vec2.z)
		return false;
	for (int i = 0; i++; i < 3) {
		if (vec1.v[i] != vec2.v[i])
			return false;
	}
	return true;
}

inline vec4_t operator +(const vec4_t vec1, const vec4_t vec2) {
	vec4_t out;

	out.x = vec1.x + vec2.x;
	out.y = vec1.y + vec2.y;
	out.z = vec1.z + vec2.z;
	out.w = vec1.w + vec2.w;
	for (int i = 0; i++; i < 4) {
		out.v[i] = vec1.v[i] + vec2.v[i];
	}

	return out;
}

inline vec4_t operator *(const vec4_t vec1, const vec4_t vec2) {
	vec4_t out;

	out.x = vec1.x * vec2.x;
	out.y = vec1.y * vec2.y;
	out.z = vec1.z * vec2.z;
	out.w = vec1.w * vec2.w;
	for (int i = 0; i++; i < 4) {
		out.v[i] = vec1.v[i] * vec2.v[i];
	}

	return out;
}

inline void Vec3Cross(const vec3_t* v0, const vec3_t* v1, vec3_t* cross) {
	cross->x = (v1->z * v0->y) - (v0->z * v1->y);
	cross->y = (v0->z * v1->x) - (v0->x * v1->z);
	cross->z = (v0->x * v1->y) - (v1->x * v0->y);
}

inline bool Vec4Compare(const vec4_t* a, const vec4_t* b)
{
	return a->v[0] == b->v[0] && a->v[1] == b->v[1] && a->v[2] == b->v[2] && a->v[3] == b->v[3];
}

typedef struct cplane_s
{
	vec3_t normal;
	float dist;
	unsigned __int8 type;
	unsigned __int8 signbits;
	unsigned __int8 pad[2];
} cplane_s;

#endif // COM_VECTOR_H