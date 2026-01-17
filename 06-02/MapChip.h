#pragma once
#include <string>
#include <vector>

class MapChip {
public:
	void LoadCSV(const std::string& filePath);
	void Draw();

private:
	std::vector<std::vector<int>> map_;
	int space_ = 16;
	int tileSize_ = 32;
	int mapWidth_ = 0;
	int mapHeight_ = 0;
};

