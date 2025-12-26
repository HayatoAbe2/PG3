#pragma once

struct Vector2 {
	float x;
	float y;
};

float Length(const Vector2& v);

// 演算子オーバーロード
Vector2 operator+(const Vector2& v1, const Vector2& v2);
Vector2 operator-(const Vector2& v1, const Vector2& v2);