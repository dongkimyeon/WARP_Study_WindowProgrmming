#include "TestScene.h"
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Time.h"
#include <windows.h>

TestScene::TestScene()
{
}

TestScene::~TestScene()
{
    Release();
}

void TestScene::Initialize()
{
    // 예시 객체 배치
    mObjects.push_back(new Player(10, 10)); // 중앙 근처 플레이어
    mObjects.push_back(new Monster(5, 5));
    mObjects.push_back(new Monster(15, 3));
    mObjects.push_back(new Monster(12, 14));

    std::cout << "[" << std::string(GetName().begin(), GetName().end()) << "] Initialized!" << std::endl;
}

void TestScene::Update(float dt)
{
    // 모든 게임 오브젝트의 Update 호출
    for (GameObject* obj : mObjects) {
        if (obj) obj->Update(Time::DeltaTime());
    }
    // 필요 시 씬 전환 등 처리
}

void TestScene::Render()
{
   
    // 20x20 그리드 생성 ('.'으로 빈칸)
    std::vector<std::string> grid(mRows, std::string(mCols, '.'));

    // 각 객체가 그리드에 자신의 심볼을 찍음
    for (GameObject* obj : mObjects) {
        if (obj) obj->Render(grid);
    }

    // 콘솔에 출력 (행 단위)
    for (int r = 0; r < mRows; ++r) {
        std::cout << grid[r] << std::endl;
    }

	system("cls"); // 콘솔 화면 지우기 (Windows 전용)

}

void TestScene::Release()
{
    // 객체 메모리 해제
    for (GameObject* obj : mObjects) {
        delete obj;
    }
    mObjects.clear();

    std::cout << "[" << std::string(GetName().begin(), GetName().end()) << "] Released!" << std::endl;
}