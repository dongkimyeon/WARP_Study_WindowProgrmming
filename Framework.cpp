#include "Framework.h"
#include "SceneManager.h"
#include "LoadScene.h" // 추가: 씬 생성/로딩 유틸

Framework::Framework() : windowWidth(800), windowHeight(600)
{
}

void Framework::Run()
{
    if (!isInitialized) {
        Initialize();
    }

    while (isRunning)
    {
        Update(); // 데이터 갱신
        Render(); // 화면 그리기
	
		
    }

    Release(); // 루프 종료 후 메모리 정리
}

void Framework::Initialize()
{
    isInitialized = true;
    isRunning = true;

    // 씬 매니저 초기화 및 씬 생성/로드
    SceneManager::Initialize();

    LoadScenes(); // 수정: 씬을 생성하고 활성화
}

void Framework::Update()
{
    // 활성화된 씬의 Update 호출
    SceneManager::Update();
}

void Framework::Render()
{
    // 활성화된 씬의 Render 호출
    SceneManager::Render();
}

void Framework::Release()
{
    // 프레임워크 종료 시 씬 매니저도 해제하여 메모리 누수 방지
    SceneManager::Release();
}