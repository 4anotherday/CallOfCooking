#include "LevelManagerComponent.h"
#include "UserComponentIDs.h"
#include "GameObject.h"
#include "Engine.h"
#include "EngineTime.h"
#include "includeLUA.h"
#include "GranadePoolComponent.h"
#include "LemonPoolComponent.h"
#include "WatermelonPoolComponent.h"

ADD_COMPONENT(LevelManagerComponent);

LevelManagerComponent::LevelManagerComponent() : Component(UserComponentId::LevelManagerComponent),
_engineTime(EngineTime::getInstance()), _levelsInfo(), _granadePool(), _lemonPool(), _watermelonPool(), _currentLevel(0), _waveStartTime(0.0f), _newWave(false)
{
}

LevelManagerComponent::~LevelManagerComponent()
{
}

void LevelManagerComponent::awake(luabridge::LuaRef& data)
{
	_currentLevel = data["CurrentLevel"].cast<int>();
}

void LevelManagerComponent::update()
{
	if (_newWave && _engineTime->deltaTime() >= _waveStartTime + _levelsInfo->at(_currentLevel).waveTime) {
		enemiesSpawn();
		_newWave = false;
	}

	if (_levelsInfo->at(_currentLevel).enemiesLeft == 0) {
		++_currentLevel;
		_newWave = true;
		_waveStartTime = _engineTime->deltaTime();
	}
}

void LevelManagerComponent::start()
{
	_granadePool = static_cast<GranadePoolComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::GranadePoolComponent));
	_lemonPool = static_cast<LemonPoolComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::LemonPoolComponent));
	_watermelonPool = static_cast<WatermelonPoolComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::WatermelonPoolComponent));
}

void LevelManagerComponent::enemyDeath(GameObject* go, EnemyType type)
{
	--_levelsInfo->at(_currentLevel).enemiesLeft;

	if (_levelsInfo->at(_currentLevel).enemiesLeft >= 0)
		switch (type) {
		case EnemyType::GRANADE: {
			_granadePool->setInactiveGO(go);
			break;
		}
		case EnemyType::LEMON: {
			_lemonPool->setInactiveGO(go);
			break;
		}
		case EnemyType::WATERMELON: {
			_watermelonPool->setInactiveGO(go);
			break;
		}
		default: {
			//LANZAR EXCEPCIÓN DE ENEMIGO DESCONOCIDO
			break;
		}
		}
}

void LevelManagerComponent::enemiesSpawn()
{
	for (int x = EnemyType::GRANADE; x != EnemyType::WATERMELON; x++) {
		if (_levelsInfo->at(_currentLevel).enemies.at(x).type == EnemyType::GRANADE)
			_granadePool->wakeUpEnemies(_levelsInfo->at(_currentLevel).enemies.at(x).howManyEnemies, _levelsInfo->at(_currentLevel).enemies.at(x).spawnEnemyTime);
		else if (_levelsInfo->at(_currentLevel).enemies.at(x).type == EnemyType::LEMON)
			_lemonPool->wakeUpEnemies(_levelsInfo->at(_currentLevel).enemies.at(x).howManyEnemies, _levelsInfo->at(_currentLevel).enemies.at(x).spawnEnemyTime);
		else if (_levelsInfo->at(_currentLevel).enemies.at(x).type == EnemyType::WATERMELON)
			_watermelonPool->wakeUpEnemies(_levelsInfo->at(_currentLevel).enemies.at(x).howManyEnemies, _levelsInfo->at(_currentLevel).enemies.at(x).spawnEnemyTime);
	}
}