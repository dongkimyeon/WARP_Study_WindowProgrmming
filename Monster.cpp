#include "Monster.h"
#include <iostream>


extern bool DebugMode;

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

    if(DebugMode) {
        // Debug 모드에서는 몬스터가 랜덤하게 이동하도록 구현할 수 있습니다.
        // 예시: 좌우로 이동
        int direction = rand() % 3 - 1; // -1, 0, 1 중 하나
        SetPosition(GetX() + direction, GetY());
	}
}

void Monster::Render(std::vector<std::string>& grid) const
{
    int rows = static_cast<int>(grid.size());
    if (rows == 0) return;
    int cols = static_cast<int>(grid[0].size());

    if (coordY >= 0 && coordY < rows && coordX >= 0 && coordX < cols) {
        grid[coordY][coordX] = Symbol;
    }

	std::cout << "Monster at (" << GetX() << ", " << GetY() << ") is rendering..." << std::endl;
}