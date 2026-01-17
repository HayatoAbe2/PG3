#include "StageScene.h"
#include "Novice.h"
#include "ICommand.h"

void StageScene::Initialize() {
	inputHandler_ = std::make_unique<InputHandler>();

	player_ = std::make_unique<Player>();
	player_->Initialize(128, 128);
}

void StageScene::Update() {
	// キー入力の更新
	inputHandler_->Update();

	command_ = inputHandler_->HandleInput(player_.get());
	if (command_) {
		command_->Execute();
	}
}

void StageScene::Draw() {
	player_->Draw();
}
