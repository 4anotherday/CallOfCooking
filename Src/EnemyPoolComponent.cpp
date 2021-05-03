#include "EnemyPoolComponent.h"
#include "GameObject.h"
#include "EngineTime.h"
#include "Transform.h"
#include "UserComponentIDs.h"
#include "Engine.h"
#include "includeLUA.h"
#include <stdlib.h> 
#include <time.h>       /* time -> ver si se puede cambiar el random por uno que use los delta times de EngineTime*/



EnemyPoolComponent::EnemyPoolComponent(UserComponentId::UserComponentId id):PoolComponent(id)
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

void EnemyPoolComponent::wakeUpEnemies(int howMany)
{
	_howManyEnemiesSpawn = howMany;
	_isSpawnTime = true;
	_totalEnemiesSpawned = 0;
}


bool EnemyPoolComponent::isTimeToSpawn()
{
	bool spawn = false;

	if (EngineTime::getInstance()->deltaTime() <= _lastSpawnEnemyTime + _spawnEnemyTime) {
		_lastSpawnEnemyTime = EngineTime::getInstance()->deltaTime();
		spawn = true;
	}
	return spawn;
}

void EnemyPoolComponent::createGos(int howMany)
{
}
