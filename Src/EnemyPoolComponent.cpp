#include "EnemyPoolComponent.h"
#include "GameObject.h"
#include "EngineTime.h"
#include "Transform.h"
#include "UserComponentIDs.h"
#include "Engine.h"
#include "includeLUA.h"
#include <stdlib.h>
#include <time.h>       /* time -> ver si se puede cambiar el random por uno que use los delta times de EngineTime*/

EnemyPoolComponent::EnemyPoolComponent(UserComponentId::UserComponentId id) :PoolComponent(id),
_respawnsPositions(), _howManyEnemiesSpawn(0), _totalEnemiesSpawned(0()), _spawnEnemyTime(0.0f), _lastSpawnEnemyTime(0.0f), _infiniteRound(false), _time(0.0f)
{
	srand(time(NULL));
}

EnemyPoolComponent::~EnemyPoolComponent()
{
}

void EnemyPoolComponent::update()
{
	_time += EngineTime::getInstance()->deltaTime();

	if (!_infiniteRound && _totalEnemiesSpawned < _howManyEnemiesSpawn && isTimeToSpawn()) 
		enemySpawn();
	else if (_infiniteRound && isTimeToSpawn()) 
		enemySpawn();
}

void EnemyPoolComponent::wakeUpEnemies(int howMany, float spawnEnemyTime)
{
	_howManyEnemiesSpawn = howMany;
	_spawnEnemyTime = spawnEnemyTime;
	_totalEnemiesSpawned = 0;
}

void EnemyPoolComponent::setInfinityRound(bool iR)
{
	_infiniteRound = iR;
	_totalEnemiesSpawned = 0;
}

bool EnemyPoolComponent::isTimeToSpawn()
{	
	if (_lastSpawnEnemyTime + _spawnEnemyTime <= _time) {
		_lastSpawnEnemyTime = _time;
		return true;
	}
	return false;
}

void EnemyPoolComponent::enemySpawn()
{
	GameObject* go = getInactiveGO();

	if (go != nullptr) {
		Transform* tr = static_cast<Transform*>(Engine::getInstance()->findGameObject(go->getName())->getComponent(ComponentId::Transform));
		if (_respawnsPositions.size() == 1)
			tr->setPosition(_respawnsPositions[0]);
		else {
			int rnd = rand() % _respawnsPositions.size();
			tr->setPosition(_respawnsPositions[rnd]);
		}
		_totalEnemiesSpawned++;
	}
}
