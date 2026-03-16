#include "Player.h"

Player::Player(int x, int y)
    : GameObject(x, y, 'P')
{
}

Player::~Player()
{
}

void Player::Update(float dt)
{
	std::cout << "Player delta time: " << dt << " seconds" << std::endl;    
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