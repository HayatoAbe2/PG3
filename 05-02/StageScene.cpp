#include "StageScene.h"
#include "Novice.h"
#include "IStageSceneCommand.h"

void StageScene::Initialize() {
	inputHandler_ = std::make_unique<StageSceneInputHandler>();

	for (int i = 0; i < 5; ++i) {
		unit_[i] = std::make_unique<Unit>();
	}
	unit_[0]->Initialize(8, 16);
	unit_[1]->Initialize(8, 18);
	unit_[2]->Initialize(11, 14);
	unit_[3]->Initialize(15, 9);
	unit_[4]->Initialize(26, 12);

	std::list<Unit*> units;
	for (int i = 0; i < 5; ++i) {
		units.push_back(unit_[i].get());
	}
	selector_ = std::make_unique<Selector>();
	selector_->SetUnits(units);
}

void StageScene::Update() {
	// キー入力の更新
	inputHandler_->Update(commandHistory_, commandHistoryItr_);

	command_ = inputHandler_->SelectorHandleInput(selector_.get());
	if (command_) {
		command_->Execute();
		if (commandHistory_.empty()) {
			commandHistory_.push_back(std::move(command_));
			commandHistoryItr_ = std::prev(commandHistory_.end());
		} else if (commandHistoryItr_ == commandHistory_.end()) {
			commandHistory_.push_back(std::move(command_));
			commandHistoryItr_ = std::prev(commandHistory_.end());
		} else {
			*commandHistoryItr_ = std::move(command_);
			commandHistoryItr_++;
		}
	}
}

void StageScene::Draw() {
	for (int i = 0; i < 20; ++i) {
		Novice::DrawLine(0, i * 32, 1280, i * 32, WHITE);
	}
	for (int j = 0; j < 40; ++j) {
		Novice::DrawLine(j * 32, 0, j * 32, 720, WHITE);
	}

	selector_->Draw();
	for (auto& unit : unit_) {
		unit->Draw();
	}

	Novice::DrawBox(0, 640, 1280, 80, 0.0f, BLACK, kFillModeSolid);
}
