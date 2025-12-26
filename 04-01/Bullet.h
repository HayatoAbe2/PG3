#pragma once
#include "Vector2.h"
class Bullet { // プレイヤーの弾
public:
	Bullet(Vector2 pos) { pos_ = pos; }
	void Update();
	void Draw();

	Vector2 GetPos() { return pos_; }
	float GetRadius() { return radius_; }

private:
	Vector2 pos_;
	float radius_ = 10.0f;
	float speed_ = 8.0f;
};

