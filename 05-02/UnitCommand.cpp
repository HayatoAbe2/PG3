#include "UnitCommand.h"
#include "Unit.h"
#include "Selector.h"

UnitMoveCommand::UnitMoveCommand(Unit* unit, int x, int y) {
	unit_ = unit;
	x_ = x;
	y_ = y;
}

void UnitMoveCommand::Execute() {
	unit_->Move(x_, y_);
}

void UnitMoveCommand::Undo() {
	unit_->Move(-x_, -y_);
}
