#include "GameManager.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"

GameManager::GameManager(InputManager* inputManager) {
	// タイトルシーンを設定
	currentScene_ = std::make_unique<TitleScene>();
	currentScene_->Initialize(inputManager);
	currentSceneNum_ = TITLE;
}

void GameManager::Run(InputManager* inputManager) {
	// 現在シーンの処理
	currentScene_->Update();
	currentScene_->Draw();

	// シーンの切り替えチェック
	int newSceneNum = currentScene_->GetSceneNum();
	if (currentSceneNum_ != newSceneNum) {
		currentSceneNum_ = newSceneNum;

		switch (currentSceneNum_) {
		case TITLE:
			currentScene_ = std::make_unique<TitleScene>();
			break;

		case STAGE:
			currentScene_ = std::make_unique<StageScene>();
			break;

		case CLEAR:
			currentScene_ = std::make_unique<ClearScene>();
			break;
		}
		currentScene_->Initialize(inputManager);
	}
}
