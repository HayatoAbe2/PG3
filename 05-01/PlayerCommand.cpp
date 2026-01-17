#include "PlayerCommand.h"
#include "Player.h"

PlayerMoveCommand::PlayerMoveCommand(Player* player, float x) {
	player_ = player;
	x_ = x;
}

void PlayerMoveCommand::Execute() {
	player_->Move(x_);
}
