#include "SceneManager.h"
#include "Time.h"
#include "Input.h"
// 정적 멤버 변수 초기화
std::map<std::wstring, Scene*> SceneManager::mScenes;
Scene* SceneManager::mActiveScene = nullptr;

void SceneManager::Initialize()
{
	Time::Initialize();
	Input::Initialize();
}

Scene* SceneManager::LoadScene(const std::wstring& name)
{
	auto iter = mScenes.find(name);

	// 맵에 해당 이름의 씬이 존재한다면
	if (iter != mScenes.end())
	{
		mActiveScene = iter->second;
		return mActiveScene;
	}

	// 못 찾았을 경우 에러 처리 (필요에 따라 assert나 로그 추가)
	return nullptr;
}

void SceneManager::Update()
{
	Time::Update();
	Input::Update();
	if (mActiveScene != nullptr)
	{
		mActiveScene->Update(Time::DeltaTime());
		if (Input::GetKeyDown(eKeyCode::ESC))
		{
			Release(); // ESC 키를 누르면 씬 매니저 해제
			exit(0); // 프로그램 종료
		}
	}


}

void SceneManager::Render()
{
	if (mActiveScene != nullptr)
	{
		mActiveScene->Render();
	
	}
	std::cout << Time::DeltaTime() << std::endl;
}

void SceneManager::Release()
{
	// 생성된 모든 씬 메모리 해제
	for (auto& pair : mScenes)
	{
		pair.second->Release();
		delete pair.second;
	}
	mScenes.clear();
	mActiveScene = nullptr;
}