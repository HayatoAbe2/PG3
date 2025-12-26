#include "StageScene.h"
#include "Vector2.h"

void StageScene::Initialize(InputManager* inputManager) {
	// 入力マネージャー
	inputManager_ = inputManager;

	player_ = std::make_unique<Player>();
	enemy_ = std::make_unique<Enemy>();
}

void StageScene::Update() {
	// 攻撃
	if (inputManager_->GetInput(ATTACK) && player_->GetCoolDownTimer() <= 0) {
		// 弾を追加
		std::unique_ptr<Bullet> newBullet = std::make_unique<Bullet>(player_->GetPos());
		bullets_.push_back(std::move(newBullet));

		player_->SetCoolDown();
	}

	player_->Update();

	// 弾の管理
	for (auto it = bullets_.begin(); it != bullets_.end(); ) {
		auto& bullet = *it; // 弾ごとの処理
		bullet->Update();

		// 当たり判定
		if (Length(bullet->GetPos() - enemy_->GetPos()) <= bullet->GetRadius() + enemy_->GetRadius()) {
			enemy_->Hit();
			it = bullets_.erase(it);
		} else {
			++it;
		}
	}

	// 敵のHPが0になったらクリアシーン
	if (enemy_->GetHP() <= 0) {
		sceneNum_ = CLEAR;
	}
}

void StageScene::Draw() {
	player_->Draw();
	enemy_->Draw();
	for (auto& bullet : bullets_) {
		bullet->Draw();
	}
}
