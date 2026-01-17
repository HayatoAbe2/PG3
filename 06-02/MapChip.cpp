#include "MapChip.h"
#include <Novice.h>
#include <cassert>
#include <fstream>
#include <sstream>
#include <memory>

void MapChip::LoadCSV(const std::string& filePath) {
	map_.clear();
	mapWidth_ = 0;
	mapHeight_ = 0;

	std::ifstream file(filePath);
	std::string line;

	if (!file.is_open()) {
		assert(false);
	}
	assert(file.is_open());

	// ファイル読む
	while (std::getline(file, line)) {
		std::vector<int> row;
		std::stringstream ss(line);
		std::string cell;

		while (std::getline(ss, cell, ',')) {
			int value = std::stoi(cell);
			row.push_back(value);
		}

		if (mapWidth_ == 0) { // 一度だけ
			mapWidth_ = static_cast<int>(row.size());
		}
		map_.push_back(row);
	}
	mapHeight_ = static_cast<int>(map_.size());
}

void MapChip::Draw() {
	for (int y = 0; y < mapHeight_; ++y) {
		for (int x = 0; x < mapWidth_; ++x) {
			int tileType = map_[y][x];
			int posX = x * tileSize_;
			int posY = y * tileSize_;
			switch (tileType) {
			case 0:
				Novice::DrawBox(space_ + posX - tileSize_ / 2, space_ + posY - tileSize_ / 2, tileSize_, tileSize_, 0.0f, WHITE, kFillModeSolid);
				break;
			case 1:
				Novice::DrawBox(space_ + posX - tileSize_ / 2, space_ + posY - tileSize_ / 2, tileSize_, tileSize_, 0.0f, RED, kFillModeSolid);
				break;
			case 2:
				Novice::DrawBox(space_ + posX - tileSize_ / 2, space_ + posY - tileSize_ / 2, tileSize_, tileSize_, 0.0f, 0x7F3F11FF, kFillModeSolid);
				break;
			case 3:
				Novice::DrawBox(space_ + posX - tileSize_ / 2, space_ + posY - tileSize_ / 2, tileSize_, tileSize_, 0.0f, 0xFFFF33FF, kFillModeSolid);
				break;
			case 4:
				Novice::DrawBox(space_ + posX - tileSize_ / 2, space_ + posY - tileSize_ / 2, tileSize_, tileSize_, 0.0f, GREEN, kFillModeSolid);
				break;
			}
		}
	}
}
