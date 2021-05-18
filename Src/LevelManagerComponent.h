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
class CardSystemComponent;
class UIManagerComponent;
class ScoreManagerComponent;

enum EnemyType{ GRANADE, LEMON, WATERMELON, UNKNOW };

struct Enemy {
	EnemyType type;
	int howManyEnemies;
	float spawnEnemyTime;
};

struct Wave {
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

	virtual void start() override;

	virtual void update() override;

	inline std::vector<Wave> getLevelInfo() const { return _levelsInfo; }

	inline int getCurrentLevel() const { return _currentRound; }

	void enemyDeath(GameObject* go, EnemyType type);

	void gameOver();

	void restartGame();

private:
	void enemiesSpawn();

	void startInfiniteRound();

	EngineTime* _engineTime;
	std::vector<Wave> _levelsInfo;
	std::vector<Vector3> _respawnPositions;
	CardSystemComponent* _cardSystem;
	GranadePoolComponent* _granadePool;
	LemonPoolComponent* _lemonPool;
	WatermelonPoolComponent* _watermelonPool;
	UIManagerComponent* _uiManager;
	ScoreManagerComponent* _scoreManager;

	int _howManyRounds;
	bool _infiniteRound;
	int _currentRound;
	float _waveStartTime;
	float _time;
	bool _newWave;
};
#endif // !LEVELMANAGERCOMPONENT_H