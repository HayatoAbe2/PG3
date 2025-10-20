#include <stdio.h>
#include <Windows.h>
#include <iostream>
using namespace std;

int Recursive(int pay,int count) {
	if (count <= 0) {
		return pay;
	}

	return Recursive(pay * 2 - 50,--count);
}

int main() {
	SetConsoleOutputCP(65001);

	int totalA = 0;
	int totalB = 0;

	for (int i = 1; i < 10; ++i) {
		int a = 1226;
		totalA += a;
		int b = Recursive(100, i-1);
		totalB += b;

		cout << i << "時間時点: " << "通常:" << totalA;
		
		if (totalA > totalB) {
			cout << " > "; 
		} else if (totalA < totalB) {
			cout << " < ";
		} else {
			cout << " = ";
		}
		
		cout << "再帰:" << totalB << "(+" << b << ")" << "\n";
	}
	
	return 0;
}
