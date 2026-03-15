#pragma once
#include "GameObject.h"

class Monster : public GameObject
{
public:
    Monster(int x = 0, int y = 0);
    virtual ~Monster();

    void Update() override;
    void Render(std::vector<std::string>& grid) const override;
};