#include "Selector.h"
#include "MapInfo.h"
#include "IStageSceneCommand.h"
#include <Novice.h>

void Selector::Draw() {
	if (!isSelectingUnit_) {
		Novice::DrawBox(posX_ - size_ / 2, posY_ - size_ / 2, size_, size_, 0.0f, RED, kFillModeWireFrame);
	}
}

void Selector::Move(const int x, const int y) {
	if (isSelectingUnit_) {
		for (auto& unit : units_) {
			if (unit->GetPosX() == posX_ + x * tileSize &&
				unit->GetPosY() == posY_ + y * tileSize) {
				// 移動できない
				return;
			}
		}
	}

	posX_ += x * tileSize;
	posY_ += y * tileSize;

	if (isSelectingUnit_) {
		selectedUnit_->Move(x, y);
	}
}

void Selector::SelectUnit() {
	// ユニットがいれば選択状態にする
	for (auto& unit : units_) {
		if (unit->GetPosX() == posX_ &&
			unit->GetPosY() == posY_) {
			unit->SetSelected(true);
			selectedUnit_ = unit;
			isSelectingUnit_ = true;
		}
	}
}

void Selector::QuitSelectUnit() {
	// 選択解除
	if (isSelectingUnit_) {
		selectedUnit_->SetSelected(false);
		selectedUnit_ = nullptr;
		isSelectingUnit_ = false;
	}
}
