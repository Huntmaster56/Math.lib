#pragma once
#include "vec2.h"

union mat2
{
	float m [4];      // single dimensional matrix
	float mm[2][2];   // multidimentional matrix
	vec2  c [2];      // column vectors
	vec2  operator [](unsigned idx) const;
	vec2  &operator[](unsigned idx);
};

bool operator ==(const mat2 & A, const mat2 & B);
bool operator !=(const mat2 & A, const mat2 & B);
mat2 operator + (const mat2 & A, const mat2 & B);
mat2 operator - (const mat2 & A, const mat2 & B);
mat2 operator - (const mat2 & A);
mat2 transpose  (const mat2 & A);
mat2 operator * (const mat2 & A, const mat2 & B);
mat2 operator * (float S, const mat2 & A);
mat2 operator * (float S, const mat2 & A);
vec2 operator * (const mat2 &A, const vec2 &V);
float determinate(const mat2 & D);
mat2 inverse(const mat2 &v);






//mat2 == mat2
// transpose(mat2)