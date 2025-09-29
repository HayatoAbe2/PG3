#include <iostream>
#include <Windows.h>
#include <list>
#include <vector>

int main() {
	SetConsoleOutputCP(65001);

	// 双方向リスト
	std::list<const char*> stations;

	// 値を追加
	stations.push_back("Tokyo");
	stations.push_back("Kanda");
	stations.push_back("Akihabara");
	stations.push_back("Okachimachi");
	stations.push_back("Ueno");
	stations.push_back("Uguisudani");
	stations.push_back("Nippori");
	// ここに西日暮里
	stations.push_back("Tabata");
	stations.push_back("Komagome");
	stations.push_back("Sugamo");
	stations.push_back("Otsuka");
	stations.push_back("Ikebukuro");
	stations.push_back("Mejiro");
	stations.push_back("Takadanobaba");
	stations.push_back("Shin-Okubo");
	stations.push_back("Shinjuku");
	stations.push_back("Yoyogi");
	stations.push_back("Harajuku");
	stations.push_back("Shibuya");
	stations.push_back("Ebisu");
	stations.push_back("Meguro");
	stations.push_back("Gotanda");
	stations.push_back("Osaki");
	stations.push_back("Shinagawa");
	// ここに高輪ゲートウェイ
	stations.push_back("Tamachi");
	stations.push_back("Hamamatsucho");
	stations.push_back("Shimbashi");
	stations.push_back("Yurakucho");
	
	// 1970年リスト
	std::cout << "1970 : \n";
	for (const auto& station : stations) { // list
		std::cout << station << "\n";
	}
	std::cout << "----------\n";

	// 1971 : 西日暮里追加
	stations.insert(std::next(stations.begin(), 7), "Nishi-Nippori"); // std::next(a,b)はaからb個進んだイテレータを返す

	// 2019年リスト
	std::cout << "2019 : \n";
	for (const auto& station : stations) { // list
		std::cout << station << "\n";
	}
	std::cout << "-----------\n";

	// 2020 : 高輪ゲートウェイ追加
	stations.insert(std::next(stations.begin(), 25), "Takanawa-Gateway");

	// 2022年リスト
	std::cout << "2022 : \n";
	for (const auto& station : stations) { // list
		std::cout << station << "\n";
	}
	std::cout << "----------\n";

	return 0;
}