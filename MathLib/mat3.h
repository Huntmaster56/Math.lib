#pragma once
#include "vec3.h"

union mat3
{
	float m[9];      // single dimensional matrix
	float mm[3][3];   // multidimentional matrix
	vec3  c[3];      // column vectors
	vec3  operator [](unsigned idx) const;
	vec3  &operator[](unsigned idx);
};

mat3 mat3Identity();
//mat3 transpose(const mat3 &A);


bool operator ==(const mat3 & A, const mat3 & B);
bool operator !=(const mat3 & A, const mat3 & B);
mat3 operator + (const mat3 & A, const mat3 & B);
mat3 operator - (const mat3 & A, const mat3 & B);
mat3 operator - (const mat3 & A);
mat3 transpose(const mat3 & A);
mat3 operator * (const mat3 & A, const mat3 & B);
mat3 operator * (float S, const mat3 & A);
mat3 operator * (float S, const mat3 & A);
vec3 operator * (const mat3 &A, const vec3 &V);
float determinate(const mat3 & A);
//vec3 inverse(const mat3 &A);

mat3 scale(float w, float h);
mat3 translate(float x, float y);
mat3 rotate(float a);


