#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include "Enemy.h"
#include <memory>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);

    std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>();
    for (int i = 0; i < 3; ++i) {
        enemy->Update();
    }

    return 0;
}