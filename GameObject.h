#pragma once
#include "stdafx.h"
#include <vector>
#include <string>

class GameObject
{
public:
    GameObject(int x = 0, int y = 0, char symbol = '?');
    virtual ~GameObject();

 
    virtual void Update() = 0;
    virtual void Render(std::vector<std::string>& grid) const = 0;

    int GetX() const { return coordX; }
    int GetY() const { return coordY; }
    void SetPosition(int x, int y) { coordX = x; coordY = y; }
    char GetSymbol() const { return Symbol; }

protected:
    int coordX;
    int coordY;
    char Symbol;
};