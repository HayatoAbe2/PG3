#pragma once
#include "IScene.h"
class ClearScene : public IScene {
public:
	void Initialize(InputManager* inputManager) override;
	void Update() override;
	void Draw() override;

private:
	InputManager* inputManager_;

	int clearTextureHandle_;
};