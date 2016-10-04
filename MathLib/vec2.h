#pragma once


struct vec2{ float x, y; };
vec2 operator+(const vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &lhs, const vec2 &rhs);
vec2 operator*(const vec2 &lhs, float rhs);
vec2 operator*(float rhs, const vec2 &lhs);
vec2 operator/(const vec2 &lhs, float rhs);
vec2 operator/(float rhs, const vec2 &lhs);
vec2 operator+(const vec2 &v);
vec2 operator-(const vec2 &v);
vec2 operator+=(vec2 & lhs, const vec2 &rhs);
vec2 operator-=(vec2 & lhs, const vec2 &rhs);

bool operator==(const vec2 & lhs, const vec2 & rhs);

float magnitude(const vec2 &v);
vec2 normal(const vec2 &v);

float dot(const vec2 &rhs, const vec2 &lhs);

float angleBetween(const vec2 &rhs, const vec2 &lhs);

vec2 perp(const vec2 &v);

float angle(const vec2 &v);
vec2 fromAngle(float a);


/////////////////////////////////////
/////////////////////////////////////
vec2 lerp(const vec2 start, const vec2 end, const vec2 alpha);

vec2 quadBezier(const vec2 start, const vec2 mid, const vec2 end, const vec2 alpha);

vec2 hermitSpline(const vec2 start, const vec2 s_tan, const vec2 end, const vec2 e_tan, const vec2 alpha);

vec2 cardinalSpline(const vec2 start, const vec2 mid, const vec2 end, const vec2 tightness, const vec2 alpha);

vec2 catRoomSpline(const vec2 start, const vec2 mid, const vec2 end, const vec2 alpha);
