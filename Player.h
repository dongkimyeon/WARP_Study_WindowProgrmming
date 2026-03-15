#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
    Player(int x = 0, int y = 0);
    virtual ~Player();

    void Update() override;
    void Render(std::vector<std::string>& grid) const override;
    // 부모의 위치/심볼은 protected로 접근 가능
};