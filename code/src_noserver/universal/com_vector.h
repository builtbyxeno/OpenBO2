#ifndef COM_VECTOR_H
#define COM_VECTOR_H

extern "C" {

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

}

#endif // COM_VECTOR_H