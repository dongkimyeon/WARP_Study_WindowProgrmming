#pragma once
#include "SceneManager.h"
#include "TestScene.h"

// 헤더에 정의된 함수이므로 inline으로 선언하여 다중 정의 문제 방지
void LoadScenes()
{
    // 씬을 생성하고 바로 활성화
    SceneManager::CreateScene<TestScene>(L"TestScene");
    SceneManager::LoadScene(L"TestScene");
}