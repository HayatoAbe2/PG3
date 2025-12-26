#include "ClearScene.h"
#include <Novice.h>

void ClearScene::Initialize(InputManager* inputManager) {
	// 入力マネージャー
	inputManager_ = inputManager;

	// 画像ハンドル
	clearTextureHandle_ = Novice::LoadTexture("./Resources/clearScene.png");
}

void ClearScene::Update() {
	// キー入力で次のシーンに移行
	if (inputManager_->GetInput(DECIDE)) {
		sceneNum_ = TITLE;
	}
}

void ClearScene::Draw() {
	Novice::DrawSprite(0, 0, clearTextureHandle_, 1, 1, 0.0f, WHITE);
}
