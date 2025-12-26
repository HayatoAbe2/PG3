#pragma once

enum INPUTACTION {
	DECIDE, // 決定
	ATTACK // 攻撃
};

class InputManager {
public:
	void Update(char keys[256], char preKeys[256]);
	bool GetInput(INPUTACTION act) { return input_[act]; }

private:
	bool input_[2]{};
};

