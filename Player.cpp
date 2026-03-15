#include "Player.h"

Player::Player(int x, int y)
    : GameObject(x, y, 'P')
{
}

Player::~Player()
{
}

void Player::Update()
{
    // 현재 정적 위치. 이동 로직 추가 가능
}

void Player::Render(std::vector<std::string>& grid) const
{
    int rows = static_cast<int>(grid.size());
    if (rows == 0) return;
    int cols = static_cast<int>(grid[0].size());

    if (coordY >= 0 && coordY < rows && coordX >= 0 && coordX < cols) {
        grid[coordY][coordX] = Symbol;
    }
}