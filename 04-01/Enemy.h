#pragma once
#include "Vector2.h"
class Enemy {
public:
	void Draw();

	Vector2 GetPos() { return pos_; }
	float GetRadius() { return radius_; }
	int GetHP() { return hp_; }

	void Hit() { hp_--; }
private:
	Vector2 pos_ = { 980,360 };
	float radius_ = 20.0f;
	int hp_ = 3;
};

