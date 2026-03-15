#pragma once
#include "stdafx.h"
#include "Scene.h"
#include <map>
#include <string>

class SceneManager
{
public:
	// 템플릿을 이용한 씬 생성 (기존 코드의 핵심 장점 유지)
	template <typename T>
	static Scene* CreateScene(const std::wstring& name)
	{
		T* scene = new T();
		scene->SetName(name);
		scene->Initialize();
		mScenes.insert(std::make_pair(name, scene));
		return scene;
	}

	static void Initialize();
	static Scene* LoadScene(const std::wstring& name);
	static void Update();
	static void Render();
	static void Release(); // 프로그램 종료 시 메모리 해제용

	static Scene* GetActiveScene() { return mActiveScene; }

private:
	static std::map<std::wstring, Scene*> mScenes;
	static Scene* mActiveScene;
};