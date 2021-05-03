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
}

void LevelManagerComponent::enemyDeath(GameObject* go, EnemyType type)
{
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

}