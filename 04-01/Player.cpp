#include "Player.h"
#include <Novice.h>

void Player::Update() {
	if (coolDownTimer_ > 0) {
		coolDownTimer_--;
	}
}

void Player::Draw() {
	Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y), static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, BLUE, kFillModeSolid);
}
