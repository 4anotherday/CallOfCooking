#pragma once
#include "F:\CS UNIVERSIDAD\z.PROYECTOS\3 Ingenieria\P3\COC\Motor\Src\MotorUnitario\Component.h"
#include "Vector3.h"

//Consultar si ponerlo con ints para evitar hacer conversiones en el awake
enum class EnemyType{ A, B, C};

struct Enemy {
	EnemyType type;
	int howManyEnemies;
	Vector3 respawnPosition;
};

struct Wave {
	int waveNumber;	
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
	std::vector<Wave>*_levelsInfo;
	int _currentLevel;
	float _waveControlTime;
};

