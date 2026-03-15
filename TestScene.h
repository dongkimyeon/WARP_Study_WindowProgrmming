#pragma once
#include "Scene.h"
#include <vector>
#include <string>
#include <memory>
#include "GameObject.h"

class TestScene : public Scene
{
public:
	TestScene();
	virtual ~TestScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
private:
	//¸â¹öº¯¼ö
	std::vector<GameObject*> mObjects;
	const int mRows = 20;
	const int mCols = 20;
};