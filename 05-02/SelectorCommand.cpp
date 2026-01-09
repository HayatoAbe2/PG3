#include "SelectorCommand.h"
#include "Unit.h"
#include "Selector.h"

SelectorMoveCommand::SelectorMoveCommand(Selector* selector, int x, int y) {
	selector_ = selector;
	x_ = x;
	y_ = y;
}

void SelectorMoveCommand::Execute() {
	selector_->Move(x_, y_);
}

void SelectorMoveCommand::Undo() {
	selector_->Move(-x_, -y_);
}

SelectUnitCommand::SelectUnitCommand(Selector* selector) {
	selector_ = selector;
}

void SelectUnitCommand::Execute() {
	selector_->SelectUnit();
}

void SelectUnitCommand::Undo() {
}

QuitSelectUnitCommand::QuitSelectUnitCommand(Selector* selector) {
	selector_ = selector;
}

void QuitSelectUnitCommand::Execute() {
	selector_->QuitSelectUnit();
}

void QuitSelectUnitCommand::Undo() {
}
