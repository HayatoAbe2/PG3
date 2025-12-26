#pragma once
#include "IScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include <memory>
#include <vector>
class StageScene : public IScene {
public:
	void Initialize(InputManager* inputManager) override;
	void Update() override;
	void Draw() override;

private:
	InputManager* inputManager_;
	std::unique_ptr<Player> player_;
	std::unique_ptr<Enemy> enemy_;
	std::vector<std::unique_ptr<Bullet>> bullets_;
};