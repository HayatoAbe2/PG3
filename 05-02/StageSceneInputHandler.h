#pragma once
#include <memory>
#include <list>
#include "IStageSceneCommand.h"
class Selector;
class Unit;
class ICommand;

class StageSceneInputHandler {
public:
	void Update(
		std::list<std::unique_ptr<IStageSceneCommand>>& commandHistory_,
		std::list<std::unique_ptr<IStageSceneCommand>>::iterator& commandHistoryItr);

	std::unique_ptr<IStageSceneCommand> SelectorHandleInput(Selector* selector);

private:
	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };

	Selector* selector_;
	Unit* selectedUnit_;
};

