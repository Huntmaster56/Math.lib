#include "mat2.h"
#include "flpos.h"

bool operator ==(const mat2 & A, const mat2 & B)
{
	return  fequals(A.m[0], B.m[0]) &&
			fequals(A.m[1], B.m[1]) &&
			fequals(A.m[2], B.m[2]) &&
			fequals(A.m[3], B.m[3]);
}

bool operator !=(const mat2 & A, const mat2 & B)
{
	return !fequals(A.m[0], B.m[0]) &&
		   !fequals(A.m[1], B.m[1]) &&
		   !fequals(A.m[2], B.m[2]) &&
		   !fequals(A.m[3], B.m[3]);
}


mat2 operator + (const mat2 & A, const mat2 & B)
{
	return mat2 { A.m[0] + B.m[0], A.m[1] + B.m[1],
				  A.m[2] + B.m[2], A.m[3] + B.m[3] };
}

mat2 operator - (const mat2 & A, const mat2 & B)
{
	return mat2{ A.m[0] - B.m[0], A.m[1] - B.m[1],
				 A.m[2] - B.m[2], A.m[3] - B.m[3] };
}

mat2 operator - (const mat2 & A)
{
	return mat2{ A.m[0],
				  A.m[1],
				  A.m[2],
				  A.m[3] };
}

mat2 transpose   (const mat2 & A)
{
	mat2 retval = A;

	retval.mm[1][0] = A.mm[0][1];
	retval.mm[0][1] = A.mm[1][0];

	return A;
}

mat2 operator*(const mat2 & A, float S)
{
	return mat2{ A.m[0] * S,
				 A.m[1] * S, 
				 A.m[2] * S, 
				 A.m[3] * S };
}

mat2 operator*(float S, const mat2 & A)
{
	return A*S;
}

mat2 operator*(const mat2 &A, const mat2 &B)
{
	return mat2{ A.m[0] * B.m[0] + A.m[2] * B.m[1],A.m[1] * B.m[0] + A.m[3] * B.m[1],
				 A.m[0] * B.m[2] + A.m[2] * B.m[3],A.m[1] * B.m[2] + A.m[3] * B.m[3] };
}

vec2 operator*(const mat2 &A, const vec2 &V)
{
	return vec2{ (A.m[0] * V.x) + (A.m[1] * V.y),
				 (A.m[2] * V.x) + (A.m[3] * V.y) };
}

float determinate(const mat2 & A, const mat2 & B)
{
	return A.m[0] * A.m[2] - A.m[1] * A.m[3];
}

mat2 inverse(const mat2 &A)
{
	return mat2{ 1 / (A.m[0]*A.m[3] - A.m[1]*A.m[2]) };
}
// 2x2 * 2x1 = 2x1
//<dot([0],[0]), dot([1],[0])>
//vec2 operator*(const mat2 &A, const vec2 &b)
//{
//	
//
//	// dot product of the row by the column.
//	vec2 retval;
//
//	// transpose to convert the rows into vectors
//	mat2 At = transpose(A); 	
//
//	retval.x = dot(At[0], b); // dot product of the first row and the vector
//	retval.y = dot(At[1], b); // dot product of the second row and the vector
//
//	return retval;
//}

/*
[0 1] = [0 2]
[2 3]   [1 3]
*/

vec2 mat2::operator[](unsigned idx) const
{
	return c[idx];
}

vec2 & mat2::operator[](unsigned idx)
{
	return c[idx];
}
