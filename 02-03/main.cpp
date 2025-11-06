#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

void ShowResult(int roll, int userGuess);
void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess);

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
	void (*fn)(int, int) = ShowResult;
	DelayReveal(fn, 3000, roll, userGuess);

	return 0;
}

void ShowResult(int roll, int userGuess) {
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
}

void DelayReveal(void(*fn)(int, int), unsigned int delayMs, int roll, int userGuess) {
	Sleep(delayMs);
	fn(roll, userGuess);
}
