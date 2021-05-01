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

LevelManagerComponent::LevelManagerComponent(): Component(UserComponentId::LevelManagerComponent), 
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
	_granadePool = static_cast<LevelManagerComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::LevelManagerComponent));
}

void LevelManagerComponent::enemiesSpawn()
{
	if (_currentLevel == 0) {
		for (auto x = 0; x <= _levelsInfo->at(_currentLevel).enemyTypes; ++x) {
			
		}
	}
	else {
		//TODO: RESETEAR Y ACTIVAR ENEMIGOS INACTIVOS DE LA POOL
	}

}
