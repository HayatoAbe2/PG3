#include "InputHandler.h"
#include <Novice.h>
#include "PlayerCommand.h"
#include "Player.h"

void InputHandler::Update() {
	// キー入力を受け取る
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);
}

std::unique_ptr<ICommand> InputHandler::HandleInput(Player* player) {
	std::unique_ptr<ICommand> command = nullptr;

	if (keys_[DIK_LEFT] || keys_[DIK_A]) {
		command = std::make_unique<PlayerMoveCommand>(player, -1.0f);
		return command;
	} else if (keys_[DIK_RIGHT] || keys_[DIK_D]) {
		command = std::make_unique<PlayerMoveCommand>(player, 1.0f);
		return command;
	}
	return nullptr;
}