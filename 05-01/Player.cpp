#include "Player.h"
#include <Novice.h>

void Player::Initialize(const float x, const float y) {
	posX_ = x;
	posY_ = y;
}

void Player::Draw() {
	Novice::DrawBox(int(posX_) - size_ / 2, int(posY_) - size_ / 2, size_, size_, 0.0f, WHITE, kFillModeSolid);
}

void Player::Move(const float x) {
	posX_ += x * moveSpeed_;
}