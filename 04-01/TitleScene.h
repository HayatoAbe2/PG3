#pragma once
#include "IScene.h"
class TitleScene : public IScene {
public:
	void Initialize(InputManager* inputManager) override;
	void Update() override;
	void Draw() override;

private:
	InputManager* inputManager_;

	int titleTextureHandle_;
};