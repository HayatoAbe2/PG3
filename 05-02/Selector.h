#pragma once
#include "Unit.h"
#include <list>

class Selector {
public:
	void Draw();

	// コマンド
	void Move(const int x, const int y);
	void SelectUnit();
	void QuitSelectUnit();

	// Getter
	bool IsSelectingUnit() { return isSelectingUnit_; }
	Unit* GetSelectedUnit() { return selectedUnit_; }

	void SetUnits(std::list<Unit*> units) { units_ = units; }
private:
	int posX_ = 16;
	int posY_ = 16;
	int size_ = 32;
	bool isSelectingUnit_ = false;

	std::list<Unit*> units_{};
	Unit* selectedUnit_ = nullptr;
};

