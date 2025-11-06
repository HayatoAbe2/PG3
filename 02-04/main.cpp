#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <ctime>
#include <functional>

using namespace std;

int main() {
	SetConsoleOutputCP(65001);

	// 乱数初期化
	srand((unsigned)time(NULL));

	bool ok = false;
	int userGuess = 0;

	// 予想
	while (ok == false) {
		cout << "奇数[1]か偶数[0]かを予想してください。" << "\n";

		scanf_s("%d", &userGuess);
		if (userGuess == 1 || userGuess == 0) {
			ok = true;
		} else {
			cout << "[1]か[0]のどちらかを入力してください。" << "\n";

		}
	}

	// 結果
	int roll = rand() % 6 + 1; // 1~6

	// ラムダ式 
	std::function<void(int, int)> ShowResult = [](int roll, int userGuess) {
		cout << "出目は" << roll << "でした。" << "\n";
		if (userGuess) {
			// 奇数
			if (roll % 2 == 1) {
				cout << "正解";
			} else {
				cout << "不正解";
			}
		} else {
			// 偶数
			if (roll % 2 == 1) {
				cout << "不正解";
			} else {
				cout << "正解";
			}
		}
		};

	std::function<void(std::function<void(int, int)>, unsigned int, int, int)>
		DelayReveal = [](std::function<void(int, int)> fn, unsigned int delayMs, int roll, int userGuess) {
		Sleep(delayMs);
		fn(roll, userGuess);
	};

	DelayReveal(ShowResult, 3000, roll, userGuess);

	return 0;
}