#include "Enemy.h"
#include <iostream>
#include <Windows.h>

// テーブル
void (Enemy::* Enemy::pFuncTable[])() = {
    &Enemy::Approach,
    &Enemy::Attack,
    &Enemy::Away,
};

void Enemy::Update() {
    (this->*pFuncTable[static_cast<size_t>(phase_)])();
    phase_++;
    Sleep(1000);
}

void Enemy::Approach() {
    std::cout << "接近" << std::endl;
}

void Enemy::Attack() {
    std::cout << "攻撃!" << std::endl;
}

void Enemy::Away() {
    std::cout << "離脱" << std::endl;
}
