#include "Vector2.h"
#include "cmath"

Vector2 operator+(const Vector2& v1, const Vector2& v2) {
	Vector2 result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	return result;
}

Vector2 operator-(const Vector2& v1, const Vector2& v2) {
	Vector2 result;
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	return result;
}

float Length(const Vector2& v) {
	return sqrtf(powf(v.x, 2) + powf(v.y, 2));
}