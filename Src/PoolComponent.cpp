#include "GameObject.h"
#include "Engine.h"
#include "EngineTime.h"
#include "includeLUA.h"
#include "PoolComponent.h"
#include "Transform.h"
#include "LevelManagerComponent.h"

PoolComponent::PoolComponent(UserComponentId::UserComponentId id): Component(id)
{
	srand(time(NULL));
}

PoolComponent::~PoolComponent()
{
	for (auto go : _mainPool) {
		delete go;
		go = nullptr;

		//PREGUNTAR SI HAY QUE CAMBIAR ESTO POR ALGUNA LLAMADA A LA LINEA DE ABAJO 
		//Engine::getInstance()->remGameObject(_gameObject);
	}
	_mainPool.clear();
	_inactivePool.clear();
}

void PoolComponent::start()
{
	_lvlManager = static_cast<LevelManagerComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::LevelManagerComponent));
}

void PoolComponent::update()
{
	if (_isSpawnTime && _totalEnemiesSpawned <= _howManyEnemiesSpawn && isTimeToSpawn()) {
		GameObject* go = getInactiveGO();

		Transform* tr = static_cast<Transform*>(Engine::getInstance()->findGameObject(go->getName())->getComponent(ComponentId::Transform));
		int rnd = rand() % (_respawnsPositions.size() - 1) + 0;
		tr->setPosition(_respawnsPositions[rnd]);
	}
}

GameObject* PoolComponent::getInactiveGO()
{
	if (_inactivePool.empty()) {
		createGos(10);
	}
	GameObject* go = _inactivePool.back();
	_inactivePool.pop_back();
	go->setEnabled(true);
	return go;
}

void PoolComponent::setInactiveGO(GameObject* go)
{
	go->setEnabled(false);
	_inactivePool.push_back(go);
}

void PoolComponent::wakeUpEnemies(int howMany)
{
	_howManyEnemiesSpawn = howMany;
	_isSpawnTime = true;
	_totalEnemiesSpawned = 0;
}

bool PoolComponent::isTimeToSpawn()
{
	bool spawn = false;
	
	if (EngineTime::getInstance()->deltaTime() <= _lastSpawnEnemyTime + _spawnEnemyTime) {
		_lastSpawnEnemyTime = EngineTime::getInstance()->deltaTime();
		spawn = true;
	}
	return spawn;
}
