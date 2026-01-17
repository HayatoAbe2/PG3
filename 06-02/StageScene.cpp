#include "StageScene.h"
#include "Novice.h"
#include <thread>

StageScene::~StageScene() {
	condition_.notify_one();
	mapLoadThread_.join();
}

void StageScene::Initialize() {
	mapChip_ = std::make_unique<MapChip>();
	queue_.push("Map.csv");

	isLoading_ = true;
	mapLoadThread_ = std::thread(&StageScene::MapLoadThread, this);
}

void StageScene::Draw() {
	mapChip_->Draw();
}

void StageScene::MapLoadThread() {
	while (isLoading_) {
		{
			std::unique_lock<std::mutex> lock(mutex_);
			condition_.wait(lock, [&]() { return !queue_.empty(); }); 
			// キューが入っていれば実行
			std::string filePath = queue_.front();
			queue_.pop();
			mapChip_->LoadCSV(filePath);
		}
	}
}
