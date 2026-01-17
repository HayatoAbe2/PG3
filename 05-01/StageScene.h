#pragma once
#include <memory>
#include "InputHandler.h"
#include "Player.h"

class StageScene {
public:
	void Initialize();
	void Update();
	void Draw();

private:
	std::unique_ptr<InputHandler> inputHandler_ = nullptr;
	std::unique_ptr<Player> player_ = nullptr;
	std::unique_ptr<ICommand> command_ = nullptr;
};

