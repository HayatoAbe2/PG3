#pragma once
#include "IScene.h"
#include "InputManager.h"
#include <memory>

class GameManager {
public:
	GameManager(InputManager* inputManager);
	void Run(InputManager* inputManager);

private:
	std::unique_ptr<IScene> currentScene_{};
	int currentSceneNum_{};
};