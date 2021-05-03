#pragma once
#ifndef LEVELMANAGERCOMPONENT_H
#define LEVELMANAGERCOMPONENT_H
#include "Component.h"
#include "Vector3.h"
#include <vector>

class GranadePoolComponent;
class LemonPoolComponent;
class WatermelonPoolComponent;

class EngineTime;

enum enemyType{ Granade, Lemon, Watermelon };

struct Enemy {
	std::string type;
	int howManyEnemies;
	Vector3 respawnPosition;
};

struct Wave {
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

	virtual void awake(luabridge::LuaRef& data) override;

	virtual void update() override;

	virtual void start() override;

	inline std::vector<Wave>* getLevelInfo() const { return _levelsInfo; }

	inline int getCurrentLevel() const { return _currentLevel; }

private:
	void enemiesSpawn();

	EngineTime* _engineTime;
	std::vector<Wave>* _levelsInfo;
	GranadePoolComponent* _granadePool;
	LemonPoolComponent* _lemonPool;
	WatermelonPoolComponent* _watermelonPool;

	int _currentLevel;
	float _waveStartTime;
	bool _newWave;
};
#endif // !LEVELMANAGERCOMPONENT_H