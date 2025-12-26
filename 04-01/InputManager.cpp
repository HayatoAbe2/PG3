#include "InputManager.h"
#include <Novice.h>

void InputManager::Update(char keys[256],char preKeys[256]) {
	input_[DECIDE] = !preKeys[DIK_SPACE] && keys[DIK_SPACE]; // 押した瞬間のみ判定
	input_[ATTACK] = keys[DIK_SPACE];
}
