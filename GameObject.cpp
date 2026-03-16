#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(int x, int y, char symbol)
    : coordX(x), coordY(y), Symbol(symbol)
{
}

GameObject::~GameObject()
{
}

void GameObject::Update(float dt)
{
    // 기본 구현 없음 — 필요시 자식에서 override
}

void GameObject::Render(std::vector<std::string>& grid) const
{
    int rows = static_cast<int>(grid.size());
    if (rows == 0) {
        return;
    }

    int cols = static_cast<int>(grid[0].size());

    if (coordY >= 0 && coordY < rows && coordX >= 0 && coordX < cols) {
        grid[coordY][coordX] = Symbol;
    }
}