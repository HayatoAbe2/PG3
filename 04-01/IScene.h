#pragma once
#include "InputManager.h"

enum SCENE { // 全シーン
	TITLE,
	STAGE,
	CLEAR
};

class IScene {
public:
	virtual ~IScene() = default;
	virtual void Initialize(InputManager* inputManager) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	int GetSceneNum() { return sceneNum_; }
protected:
	static int sceneNum_;
};

