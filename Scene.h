#pragma once
#include "Entity.h"

class Scene : public Entity
{
public:
	Scene() {}
	virtual ~Scene() {}

	virtual void Initialize() = 0; // 순수 가상 함수: 자식 클래스에서 무조건 구현해야 함
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;
};