#pragma once
#ifndef BULLETSMANAGERCOMPONENT_H
#define BULLETSMANAGERCOMPONENT_H
#include "Component.h"
#include "Vector3.h"
#include <vector>

class EngineTime;

class BulletsManagerComponent :public Component
{
public:
	BulletsManagerComponent();
	~BulletsManagerComponent();

	void awake(luabridge::LuaRef& data) override;

	void update() override;

	void spawnPlayerBullet();
	void spawnEnemyBullet();

private:

	EngineTime* _engineTime;
	std::vector<GameObject*> _playerBullets;
	std::vector<GameObject*> _enemyBullets;
};
#endif // !BULLETSMANAGERCOMPONENT_H