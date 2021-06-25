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