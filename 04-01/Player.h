#pragma once
#include "Vector2.h"
#include "InputManager.h"
class Player {
public:
	void Update();
	void Draw();

	Vector2 GetPos() { return pos_; }
	float GetRadius() { return radius_; }
	int GetCoolDownTimer() { return coolDownTimer_; }
	void SetCoolDown() { coolDownTimer_ = coolDown_; }
private:
	Vector2 pos_ = {300,360};
	float radius_ = 20.0f;

	// 攻撃クールダウン
	const int coolDown_ = 30;
	int coolDownTimer_ = coolDown_;
};

