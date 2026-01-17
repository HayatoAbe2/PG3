#pragma once
#include "ICommand.h"

class Player;
class PlayerMoveCommand : public ICommand {
public:
	PlayerMoveCommand(Player* player, float x);
	void Execute() override;

private:
	Player* player_;
	float x_ = 0;
};
