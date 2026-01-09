#pragma once
#include "IStageSceneCommand.h"

class Unit;
class Selector;

// 移動コマンド
class UnitMoveCommand : public IStageSceneCommand {
public:
	UnitMoveCommand(Unit* unit, int x, int y);
	void Execute() override;
	void Undo() override;

private:
	Unit* unit_;
	int x_ = 0;
	int y_ = 0;
};
