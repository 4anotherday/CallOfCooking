#pragma once
#ifndef LEVELMANAGERCOMPONENT_H
#define LEVELMANAGERCOMPONENT_H
#include "Component.h"
#include "Vector3.h"
#include <vector>

class EngineTime;

struct Enemy {
	int type;
	int howManyEnemies;
	Vector3 respawnPosition;
};

struct Wave {
	int enemyTypes;
	int waveNumber;
	int enemiesLeft;
	float waveTime;
	float spawnEnemyTime;
	std::vector<Enemy> enemies;
};

class LevelManagerComponent :public Component
{
public:
	LevelManagerComponent();
	~LevelManagerComponent();

	void awake(luabridge::LuaRef& data) override;

	void update() override;

	inline std::vector<Wave>* getLevelInfo() const { return _levelsInfo; }

	inline int getCurrentLevel() const { return _currentLevel; }

private:
	void enemiesSpawn();

	EngineTime* _engineTime;
	std::vector<Wave>* _levelsInfo;
	int _currentLevel;
	float _waveStartTime;
	bool _newWave;
};
#endif // !LEVELMANAGERCOMPONENT_H