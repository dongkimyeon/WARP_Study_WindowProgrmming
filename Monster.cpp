#include "Monster.h"
#include <iostream>

Monster::Monster(int x, int y)
    : GameObject(x, y, 'M')
{
}

Monster::~Monster()
{
}

void Monster::Update()
{
    std::cout << "Monster at (" << GetX() << ", " << GetY() << ") is updating..." << std::endl;
}

void Monster::Render(std::vector<std::string>& grid) const
{
    int rows = static_cast<int>(grid.size());
    if (rows == 0) return;
    int cols = static_cast<int>(grid[0].size());

    if (coordY >= 0 && coordY < rows && coordX >= 0 && coordX < cols) {
        grid[coordY][coordX] = Symbol;
    }
}