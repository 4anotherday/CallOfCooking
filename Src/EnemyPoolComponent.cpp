#include "EnemyPoolComponent.h"
#include "GameObject.h"
#include "EngineTime.h"
#include "Transform.h"
#include "UserComponentIDs.h"
#include "Engine.h"
#include "includeLUA.h"
#include <stdlib.h> 
#include <time.h>       /* time -> ver si se puede cambiar el random por uno que use los delta times de EngineTime*/

EnemyPoolComponent::EnemyPoolComponent(UserComponentId::UserComponentId id):PoolComponent(id),
_respawnsPositions(), _isSpawnTime(false), _howManyEnemiesSpawn(0), _totalEnemiesSpawned(0()), _spawnEnemyTime(0.0f), _lastSpawnEnemyTime(0.0f)
{
	srand(time(NULL));
}

EnemyPoolComponent::~EnemyPoolComponent()
{
}

void EnemyPoolComponent::update()
{
	if (_isSpawnTime && _totalEnemiesSpawned <= _howManyEnemiesSpawn && isTimeToSpawn()) {
		GameObject* go = getInactiveGO();

		Transform* tr = static_cast<Transform*>(Engine::getInstance()->findGameObject(go->getName())->getComponent(ComponentId::Transform));
		int rnd = rand() % (_respawnsPositions.size() - 1) + 0;
		tr->setPosition(_respawnsPositions[rnd]);
	}
}

void EnemyPoolComponent::wakeUpEnemies(int howMany, float spawnEnemyTime)
{
	_howManyEnemiesSpawn = howMany;
	_spawnEnemyTime = spawnEnemyTime;
	_isSpawnTime = true;
	_totalEnemiesSpawned = 0;
}


bool EnemyPoolComponent::isTimeToSpawn()
{
	if (EngineTime::getInstance()->deltaTime() <= _lastSpawnEnemyTime + _spawnEnemyTime) {
		_lastSpawnEnemyTime = EngineTime::getInstance()->deltaTime();
		return true;
	}
	return false;
}