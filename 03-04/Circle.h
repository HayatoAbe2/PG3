#pragma once
#include "IShape.h"
class Circle : public IShape {
public:
	void Size() override;
	void Draw() override;

private:
	float radius_ = 3.0f;
	float size_{};
};

