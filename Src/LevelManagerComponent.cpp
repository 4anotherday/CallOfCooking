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
_engineTime(EngineTime::getInstance()), _levelsInfo(), _currentLevel(0), _waveStartTime(0.0f), _newWave(false)
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

	if (_levelsInfo->at(_currentLevel).totalEnemiesLeft == 0) {
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

void LevelManagerComponent::enemyDeath(GameObject* go, EnemyType type, int id)
{
	switch (type) {
		case EnemyType::Granade:{

			break;
		}
		case EnemyType::Lemon: {
			break;
		}
		case EnemyType::Watermelon: {
			break;
		}
		default: {
			//TODO: EXCEPCIÓN DE TIPO DE ENEMIGO INVÁLIDO
			break;
		}
	}
	
}

void LevelManagerComponent::enemiesSpawn()
{
	for (auto x = 0; x < _levelsInfo->at(_currentLevel).enemies.size(); ++x) {
		if (_levelsInfo->at(_currentLevel).enemies.at(x).type == EnemyType::Granade) {
			//_granadePool.
		}
		else if (_levelsInfo->at(_currentLevel).enemies.at(x).type == EnemyType::Lemon) {
		}
		else if (_levelsInfo->at(_currentLevel).enemies.at(x).type == EnemyType::Watermelon) {}
	}
}