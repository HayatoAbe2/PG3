#pragma once
class Selector;
class Unit {
public:
	void Initialize(const int x, const int y);
	void Draw();

	// コマンド
	void Move(const int x, const int y);

	// Getter
	int GetPosX() { return posX_; }
	int GetPosY() { return posY_; }

	// Setter
	void SetSelected(bool selected) { selected_ = selected; }

private:
	int posX_ = 12;
	int posY_ = 12;
	int size_ = 24;

	bool selected_ = false;
};

