#include "TitleScene.h"
#include <Novice.h>

void TitleScene::Initialize(InputManager* inputManager) {
	// 入力マネージャー
	inputManager_ = inputManager;

	// 画像ハンドル
	titleTextureHandle_ = Novice::LoadTexture("./Resources/titleScene.png");
}

void TitleScene::Update() {
	// キー入力で次のシーンに移行
	if (inputManager_->GetInput(DECIDE)) {
		sceneNum_ = STAGE;
	}
}

void TitleScene::Draw() {
	Novice::DrawSprite(0, 0, titleTextureHandle_, 1, 1, 0.0f, WHITE);
}
