#include "Circle.h"
#include <iostream>
#include <numbers>

void Circle::Size() {
	size_ = static_cast<float>(std::numbers::pi) * radius_ * radius_;
}

void Circle::Draw() {
	std::cout << "Circleの面積: " << size_ << std::endl;
}