#include <Windows.h>
#include <memory>
#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

int main() {
    SetConsoleOutputCP(65001);

    std::unique_ptr<IShape> shapes[2];
    shapes[0] = std::make_unique<Circle>();
    shapes[1] = std::make_unique<Rectangle>();

    for (int i = 0; i < 2; ++i) {
        shapes[i]->Size();
        shapes[i]->Draw();
    }

    return 0;
}