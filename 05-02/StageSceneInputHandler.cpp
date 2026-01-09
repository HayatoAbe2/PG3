#include "StageSceneInputHandler.h"
#include "Selector.h"
#include "Unit.h"
#include "SelectorCommand.h"
#include "UnitCommand.h"
#include <Novice.h>

void StageSceneInputHandler::Update(
	std::list<std::unique_ptr<IStageSceneCommand>>& commandHistory_,
	std::list<std::unique_ptr<IStageSceneCommand>>::iterator& commandHistoryItr) {

	// キー入力を受け取る
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);

	if ((keys_[DIK_LCONTROL] || keys_[DIK_RCONTROL]) && (keys_[DIK_Z] && !preKeys_[DIK_Z])) {
		if (commandHistoryItr != commandHistory_.begin()) {
			--commandHistoryItr;
			(*commandHistoryItr)->Undo();
		}
	}
}

std::unique_ptr<IStageSceneCommand> StageSceneInputHandler::SelectorHandleInput(Selector* selector) {
	std::unique_ptr<IStageSceneCommand> command = nullptr;
	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE]) {
		if (selector->IsSelectingUnit()) {
			command = std::make_unique<QuitSelectUnitCommand>(selector);
		} else {
			command = std::make_unique<SelectUnitCommand>(selector);
		}
		return command;
	}

	if ((keys_[DIK_LEFT] && !preKeys_[DIK_LEFT]) || (keys_[DIK_A] && !preKeys_[DIK_A])) {
		command = std::make_unique<SelectorMoveCommand>(selector, -1, 0);
		return command;
	} else if ((keys_[DIK_RIGHT] && !preKeys_[DIK_RIGHT]) || (keys_[DIK_D] && !preKeys_[DIK_D])) {
		command = std::make_unique<SelectorMoveCommand>(selector, 1, 0);
		return command;
	} else if ((keys_[DIK_UP] && !preKeys_[DIK_UP]) || (keys_[DIK_W] && !preKeys_[DIK_W])) {
		command = std::make_unique<SelectorMoveCommand>(selector, 0, -1);
		return command;
	} else if ((keys_[DIK_DOWN] && !preKeys_[DIK_DOWN]) || (keys_[DIK_S] && !preKeys_[DIK_S])) {
		command = std::make_unique<SelectorMoveCommand>(selector, 0, 1);
		return command;
	}

	return nullptr;
}