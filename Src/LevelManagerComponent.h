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

enum EnemyType{ GRANADE, LEMON, WATERMELON, UNKNOW };

struct Enemy {
	EnemyType type;
	int howManyEnemies;
};

struct Wave {
	int waveNumber;
	int enemiesLeft;
	int totalEnemies;
	// Time between the end of one waveand the beginning of the next
	float waveTime;
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

	void enemyDeath(GameObject* go, EnemyType type);

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