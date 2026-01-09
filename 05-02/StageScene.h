#pragma once
#include <list>
#include <memory>
#include "StageSceneInputHandler.h"
#include "Selector.h"
#include "Unit.h"

class StageScene {
public:
	void Initialize();
	void Update();
	void Draw();

private:
	std::unique_ptr<StageSceneInputHandler> inputHandler_ = nullptr;
	std::unique_ptr<Selector> selector_ = nullptr;
	std::unique_ptr<Unit> unit_[5]{};
	std::unique_ptr<IStageSceneCommand> command_ = nullptr;

	// 履歴
	std::list<std::unique_ptr<IStageSceneCommand>> commandHistory_;
	std::list<std::unique_ptr<IStageSceneCommand>>::iterator commandHistoryItr_;
};

