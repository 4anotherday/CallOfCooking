#include "LevelManagerComponent.h"
#include "UserComponentIDs.h"
#include "GameObject.h"
#include "Engine.h"
#include "EngineTime.h"
#include "includeLUA.h"
#include "GranadePoolComponent.h"
#include "LemonPoolComponent.h"
#include "WatermelonPoolComponent.h"
#include "PrefabLoader.h"

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
	//bool loaded = true;

	if (LUAFIELDEXIST(CurrentLevel)) _currentLevel = GETLUAFIELD(CurrentLevel, int);

	std::string path = "";
	if (LUAFIELDEXIST(Path)) path = GETLUAFIELD(Path, std::string);


	luabridge::LuaRef configData = PrefabLoader::getInstance()->getDataPrefab(path);


	int howManyRespawns = configData[0]["HowManyRespawnPositions"].cast<int>();

	std::vector<Vector3> respawns;
	for (int j = 1; j <= howManyRespawns; ++j) {
		float x = configData[0]["RespawnPositions"][j]["X"].cast<float>();
		float y = configData[0]["RespawnPositions"][j]["Y"].cast<float>();
		float z = configData[0]["RespawnPositions"][j]["Z"].cast<float>();
		respawns.push_back(Vector3(x, y, z));
	}

	for (int x = 1; x <= configData.length(); ++x) {
		Wave wave;
		wave.enemiesLeft = wave.totalEnemies = configData[x]["TotalEnemies"].cast<int>();
		wave.waveTime = configData[x]["WaveTime"].cast<float>();
		
		Enemy granade;
		granade.type == EnemyType::GRANADE;
		granade.howManyEnemies = configData[x]["Granade"]["HowMany"].cast<int>();
		granade.spawnEnemyTime = configData[x]["Granade"]["RespawnTime"].cast<float>();
		wave.enemies.push_back(granade);

		Enemy lemon;
		lemon.type = EnemyType::LEMON;
		lemon.howManyEnemies = configData[x]["Lemon"]["HowMany"].cast<int>();
		lemon.spawnEnemyTime = configData[x]["Lemon"]["RespawnTime"].cast<float>();
		wave.enemies.push_back(lemon);
		
		Enemy watermelon;
		watermelon.type = EnemyType::WATERMELON;
		watermelon.howManyEnemies = configData[x]["Watermelon"]["HowMany"].cast<int>();
		watermelon.spawnEnemyTime = configData[x]["Watermelon"]["RespawnTime"].cast<float>();
		wave.enemies.push_back(watermelon);

		_levelsInfo->push_back(wave);
	}

}

void LevelManagerComponent::update()
{
	/*if (_newWave && _engineTime->deltaTime() >= _waveStartTime + _levelsInfo->at(_currentLevel).waveTime) {
		enemiesSpawn();
		_newWave = false;
	}

	if (_levelsInfo->at(_currentLevel).enemiesLeft == 0) {
		++_currentLevel;
		_newWave = true;
		_waveStartTime = _engineTime->deltaTime();
	}*/
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