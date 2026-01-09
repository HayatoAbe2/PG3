#pragma once
#include "IStageSceneCommand.h"

class Selector;

// 移動コマンド
class SelectorMoveCommand : public IStageSceneCommand {
public:
	SelectorMoveCommand(Selector* selector, int x, int y);
	void Execute() override;
	void Undo() override;

private:
	Selector* selector_;
	int x_ = 0;
	int y_ = 0;
};

// 選択コマンド
class SelectUnitCommand : public IStageSceneCommand {
public:
	SelectUnitCommand(Selector* selector);
	void Execute() override;
	void Undo() override;

private:
	Selector* selector_;
};

// 選択解除コマンド
class QuitSelectUnitCommand : public IStageSceneCommand {
public:
	QuitSelectUnitCommand(Selector* selector);
	void Execute() override;
	void Undo() override;

private:
	Selector* selector_;
};