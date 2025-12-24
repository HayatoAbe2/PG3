#include <Windows.h>
#include <memory>
#include "Character.h"
#include "Warrior.h"
#include "Mage.h"
#include "Slime.h"

using namespace std;

int main() {
    SetConsoleOutputCP(65001);

    std::unique_ptr<Character> characters[3];
    characters[0] = std::make_unique<Warrior>(); // 戦士
    characters[1] = std::make_unique<Mage>(); // 魔法使い
    characters[2] = std::make_unique<Slime>(); // スライム

    for (int i = 0; i < 3; ++i) {
        characters[i]->Attack();
    }

    return 0;
}