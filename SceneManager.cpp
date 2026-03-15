#include "SceneManager.h"

// 정적 멤버 변수 초기화
std::map<std::wstring, Scene*> SceneManager::mScenes;
Scene* SceneManager::mActiveScene = nullptr;

void SceneManager::Initialize()
{
	// 씬 매니저 자체의 초기화가 필요하다면 여기에 작성
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
	if (mActiveScene != nullptr)
	{
		mActiveScene->Update();
	}
}

void SceneManager::Render()
{
	if (mActiveScene != nullptr)
	{
		mActiveScene->Render();
	}
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