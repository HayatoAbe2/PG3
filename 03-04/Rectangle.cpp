#include "Rectangle.h"
#include <iostream>

void Rectangle::Size() {
	size_ = width_ * height_;
}

void Rectangle::Draw() {
	std::cout << "Rectangleの面積: " << size_ << std::endl;
}
