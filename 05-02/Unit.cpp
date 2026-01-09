#include "Unit.h"
#include "Selector.h"
#include "MapInfo.h"
#include <Novice.h>

void Unit::Initialize(const int x, const int y) {
	posX_ = x * tileSize + tileSize / 2;
	posY_ = y * tileSize + tileSize / 2;
}

void Unit::Draw() {
	if (selected_) {
		Novice::DrawBox(posX_ - size_ / 2, posY_ - size_ / 2, size_, size_, 0.0f, 0xFFCCCCFF, kFillModeSolid);
	} else {
		Novice::DrawBox(posX_ - size_ / 2, posY_ - size_ / 2, size_, size_, 0.0f, WHITE, kFillModeSolid);
	}
}

void Unit::Move(const int x, const int y) {
	posX_ += x * tileSize;
	posY_ += y * tileSize;
}
