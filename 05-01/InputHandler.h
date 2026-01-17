#pragma once
#include <memory>
#include "ICommand.h"
class Player;

class InputHandler {
public:
	void Update();
	std::unique_ptr<ICommand> HandleInput(Player* player);

private:
	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };

	Player* player_ = nullptr;
};

