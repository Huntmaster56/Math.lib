#include "mat3.h"
#include "flpos.h"
#include <cmath>

bool operator ==(const mat3 & A, const mat3 & B) 
{
	return  fequals(A.m[0], B.m[0]) &&
			fequals(A.m[1], B.m[1]) &&
			fequals(A.m[2], B.m[2]) &&
			fequals(A.m[3], B.m[3]) &&
			fequals(A.m[4], B.m[4]) &&
			fequals(A.m[5], B.m[5]) &&
			fequals(A.m[6], B.m[6]) &&
			fequals(A.m[7], B.m[7]) &&
			fequals(A.m[8], B.m[8]);
}

bool operator !=(const mat3 & A, const mat3 & B)
{
	return  !fequals(A.m[0], B.m[0]) &&
			!fequals(A.m[1], B.m[1]) &&
			!fequals(A.m[2], B.m[2]) &&
			!fequals(A.m[3], B.m[3]) &&
			!fequals(A.m[4], B.m[4]) &&
			!fequals(A.m[5], B.m[5]) &&
			!fequals(A.m[6], B.m[6]) &&
			!fequals(A.m[7], B.m[7]) &&
			!fequals(A.m[8], B.m[8]);
}

mat3 operator + (const mat3 & A, const mat3 & B)
{
	return mat3{ A.m[0] + B.m[0], A.m[1] + B.m[1], A.m[2] + B.m[2], A.m[3] + B.m[3], A.m[4] 
			   + B.m[4], A.m[5] + B.m[5], A.m[6] + B.m[6], A.m[7] + B.m[7], A.m[8] + B.m[8] };
}

mat3 operator - (const mat3 & A, const mat3 & B)
{
	return mat3{ A.m[0] - B.m[0], A.m[1] - B.m[1], A.m[2] - B.m[2], A.m[3] - B.m[3], A.m[4]
			   - B.m[4], A.m[5] - B.m[5], A.m[6] - B.m[6], A.m[7] - B.m[7], A.m[8] - B.m[8] };
}

mat3 operator - (const mat3 & A)
{
	return mat3{ A.m[0],
				 A.m[1],
				 A.m[2],
				 A.m[3],
				 A.m[4],
				 A.m[5],
				 A.m[6],
				 A.m[7],
				 A.m[8] };
}

mat3 mat3Identity()
{
	return mat3{ 1,0,0 ,0,1,0, 0,0,1 };
}



mat3 transpose(const mat3 & A)
{
	mat3 retval;

	for (unsigned i = 0; i < 3; ++i)
		for (unsigned j = 0; j < 3; ++j)
			retval[i][j] = A[j][i];

	return retval;
}

mat3 operator*(const mat3 & A, float S)
{
	return mat3{ A.m[0] * S,
				 A.m[1] * S,
				 A.m[2] * S,
				 A.m[3] * S,
				 A.m[4] * S,
				 A.m[5] * S,
				 A.m[6] * S,
				 A.m[7] * S,
				 A.m[8] * S };
}

mat3 operator*(float S, const mat3 & A)
{
	return A*S;
}

mat3 operator*(const mat3 &A, const mat3 &B)
{
	mat3 At = transpose(A);
	mat3 retval;

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			retval[i][j] = dot(At[j], B[i]);

	return retval;
}

vec3 operator*(const mat3 &A, const vec3 &V)
{
	return vec3{ (A.m[0] * V.x) + (A.m[3] * V.y) + (A.m[6] * V.z),
				 (A.m[1] * V.x) + (A.m[4] * V.y) + (A.m[7] * V.z),
				 (A.m[2] * V.x) + (A.m[5] * V.y) + (A.m[8] * V.z), };
}

float determinate(const mat3 & A)
{
	return  (A.m[0] * A.m[4] * A.m[8]) + (A.m[3] * A.m[7] * A.m[2]) + (A.m[6] * A.m[1] * A.m[5]) -
			(A.m[6] * A.m[4] * A.m[2]) - (A.m[3] * A.m[1] * A.m[8]) - (A.m[0] * A.m[7] * A.m[5]);
}

//mat3 inverse(const mat3 &A)
//{
//	return mat3{ 1 / determinate(A)};
//}

mat3 scale(float w, float h)
{
	return mat3{ {w,0,0,0,h,0,0,0,1} };
}

mat3 translate(float x, float y)
{
	return mat3{ {1,0,0,0,1,0,x,y,1 } };
}

mat3 rotate(float a)
{
	return mat3
	{  cos(a), sin(a), 0,
	   -sin(a), cos(a),0,
	   0,0,1 };
}

vec3 mat3::operator[](unsigned idx) const
{
	return c[idx];
}

vec3 & mat3::operator[](unsigned idx)
{
	return c[idx];
}
