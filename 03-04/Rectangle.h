#pragma once
#include "IShape.h"
class Rectangle : public IShape {
public:
	void Size() override;
	void Draw() override;

private:
	float width_ = 5.0f;
	float height_ = 7.0f;
	float size_{};
};

