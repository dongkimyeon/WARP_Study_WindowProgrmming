#pragma once

#include "stdafx.h"


class Framework {
public:
	Framework();

    void Run(); 
    virtual void Initialize();
protected: //자식 클래스에서만 접근 가능
    virtual void Update(); 
    virtual void Render();
    virtual void Release();

protected:
    int windowWidth;
    int windowHeight;
    bool isRunning = false;
    bool isInitialized = false;
};

