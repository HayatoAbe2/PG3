#include "Enemy.h"
#include <Novice.h>

void Enemy::Draw() {
	Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y), static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, RED, kFillModeSolid);
}