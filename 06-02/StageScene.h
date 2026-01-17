#pragma once
#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include "MapChip.h"

class StageScene {
public:
	~StageScene();
	void Initialize();
	void Draw();
	void MapLoadThread();

private:
	std::thread mapLoadThread_;
	std::unique_ptr<MapChip> mapChip_ = nullptr;
	std::mutex mutex_;
	std::condition_variable condition_;
	std::queue<std::string> queue_;
	bool isLoading_ = false;
};

