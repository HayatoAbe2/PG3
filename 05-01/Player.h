#pragma once
class Player {
public:
	void Initialize(const float x, const float y);
	void Draw();

	// コマンド
	void Move(const float x);

private:
	float posX_ = 12;
	float posY_ = 12;
	int size_ = 24;
	float moveSpeed_ = 2.0f;
};

