#include "Bullet.h"
#include <Novice.h>

void Bullet::Update() {
	// 発射されたら右に飛ぶ
	pos_.x += speed_;
}

void Bullet::Draw() {
	Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y), static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, WHITE, kFillModeSolid);
}
