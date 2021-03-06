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
#include "UIManagerComponent.h"
#include "ScoreManagerComponent.h"
#include "PlayerMovementComponent.h"
#include "PlayerHealthComponent.h"
#include "Buttons.h"
#include "CardSystemComponent.h"
#include "Exceptions.h"

ADD_COMPONENT(LevelManagerComponent);

LevelManagerComponent::LevelManagerComponent() : Component(UserComponentId::LevelManagerComponent),
_engineTime(EngineTime::getInstance()), _levelsInfo(), _respawnPositions(), _cardSystem(nullptr),
_granadePool(), _lemonPool(), _watermelonPool(), _uiManager(nullptr),_scoreManager(nullptr),
_currentRound(0), _waveStartTime(0.0f), _time(), _newWave(true), _howManyRounds(false), _infiniteRound(false), _gameOver(false)
{
}

LevelManagerComponent::~LevelManagerComponent()
{
}

void LevelManagerComponent::awake(luabridge::LuaRef& data)
{
	if (LUAFIELDEXIST(CurrentLevel)) _currentRound = GETLUAFIELD(CurrentLevel, int);

	std::string path = "";
	if (LUAFIELDEXIST(Path)) path = GETLUAFIELD(Path, std::string);

	luabridge::LuaRef configData = PrefabLoader::getInstance()->getDataPrefab(path);

	int howManyRespawns = configData[0]["HowManyRespawnPositions"].cast<int>();
	//if (LUASUBFIELDEXIST(0, HowManyRespawnPositions)) howManyRespawns = GETLUASUBFIELD(0, HowManyRespawnPositions, int);


	for (int j = 1; j <= howManyRespawns; ++j) {
		float x = configData[0]["RespawnPositions"][j]["X"].cast<float>();
		float y = configData[0]["RespawnPositions"][j]["Y"].cast<float>();
		float z = configData[0]["RespawnPositions"][j]["Z"].cast<float>();
		_respawnPositions.push_back(Vector3(x, y, z));
	}


	_howManyRounds = configData[0]["HowManyRounds"].cast<int>();

	for (int x = 1; x <= _howManyRounds; ++x) {
		Wave wave;
		wave.enemiesLeft = wave.totalEnemies = configData[x]["TotalEnemies"].cast<int>();
		wave.waveTime = configData[x]["WaveTime"].cast<float>();

		Enemy granade = Enemy();
		granade.type = EnemyType::GRANADE;
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

		_levelsInfo.push_back(wave);
	}
}

void LevelManagerComponent::start()
{

	_granadePool = static_cast<GranadePoolComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::GranadePoolComponent));
	_lemonPool = static_cast<LemonPoolComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::LemonPoolComponent));
	_watermelonPool = static_cast<WatermelonPoolComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::WatermelonPoolComponent));

	if (_granadePool != nullptr) _granadePool->setRespawnPositions(_respawnPositions);
	if (_lemonPool != nullptr) _lemonPool->setRespawnPositions(_respawnPositions);
	if (_watermelonPool != nullptr) _watermelonPool->setRespawnPositions(_respawnPositions);

	_cardSystem = static_cast<CardSystemComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::CardSystemComponent));
	_uiManager = static_cast<UIManagerComponent*>(Engine::getInstance()->findGameObject("UIManager")->getComponent(UserComponentId::UIManagerComponent));
	_uiManager->setRoundsText(_currentRound);

	_scoreManager = static_cast<ScoreManagerComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::ScoreManagerComponent));

	_quitButton = static_cast<QuitEndGameButtonComponent*>(Engine::getInstance()->findGameObject("QuitButton")->getComponent(UserComponentId::QuitEndgameButtonComponent));
	_restardButton = static_cast<RestartGameButtonComponent*>(Engine::getInstance()->findGameObject("RestartButton")->getComponent(UserComponentId::RestartGameButtonComponent));

	_playerMovementComponent = static_cast<PlayerMovementComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::PlayerMovementComponent));
	_playerHealthComponent = static_cast<PlayerHealthComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::PlayerHealthComponent));


	Engine::getInstance()->setViewportColour(0.4f, 0.2f, 0.5f);
	Engine::getInstance()->setShadowColour(0.8f, 0.75f, 0.75f);
	Engine::getInstance()->setAmbientLight(0.5f, 0.4f, 0.4f);
}

void LevelManagerComponent::update()
{
	_time += _engineTime->deltaTime();

	if (!_gameOver && _newWave && (_time >= _waveStartTime + _levelsInfo.at(_currentRound).waveTime)) {
		_cardSystem->setCardsUp(false);		
		_newWave = false;
		if (_infiniteRound) startInfiniteRound();
		else enemiesSpawn();
	}


	if (!_gameOver && !_infiniteRound && _levelsInfo.at(_currentRound).enemiesLeft == 0) {
		_scoreManager->addTotalComboScore();
		_cardSystem->setCardsUp(true);

		++_currentRound;
		_uiManager->setRoundsText(_currentRound);

		if (_currentRound >= _howManyRounds) {
			_infiniteRound = true;

			//One round is subtracted to use the wave time of the previous round
			--_currentRound;
		}

		_newWave = true;
		_waveStartTime = _time;
	}	
}

void LevelManagerComponent::enemyDeath(GameObject* go, EnemyType type)
{
	//Only remove one enemy from the remaining total if he is not in infinite round
	if(_currentRound < _howManyRounds)
		--_levelsInfo.at(_currentRound).enemiesLeft;


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
			throw ExcepcionTAD("Error: There is no existing that type of enemy");
			break;
		}
	}
		
	std::cout << "Enemigo muere " << _levelsInfo.at(_currentRound).enemiesLeft << std::endl;
}

void LevelManagerComponent::gameOver()
{
	_gameOver = true;
	_scoreManager->gameOver();
	

	_granadePool->setPause(true);
	_granadePool->reset();

	_lemonPool->setPause(true);
	_lemonPool->reset();

	_watermelonPool->setPause(true);
	_watermelonPool->reset();


	_quitButton->enableButton(true);
	_restardButton->enableButton(true);
	_playerMovementComponent->gameOver(true);

	_uiManager->showFinalPanel();
	std::cout << "GAME OVER" << std::endl;
	_uiManager->setGameOver(true);
}

void LevelManagerComponent::restartGame()
{
	_scoreManager->reset();
	_uiManager->hideFinalPanel();
	
	GameObject* player = Engine::getInstance()->findGameObject("Player");	
	_playerMovementComponent->gameOver(false);
	_playerMovementComponent->resetPosition();
	_playerHealthComponent->reset();
	_quitButton->enableButton(false);
	_restardButton->enableButton(false);

	for (int x = 0; x < _levelsInfo.size(); ++x) {
		_levelsInfo.at(x).enemiesLeft = _levelsInfo.at(x).totalEnemies;
	}

	_granadePool->setPause(false);
	_lemonPool->setPause(false);
	_watermelonPool->setPause(false);

	_currentRound = 0;
	_uiManager->setRoundsText(_currentRound);
	_infiniteRound = false;
	_newWave = true;
	_waveStartTime = _time;
	_cardSystem->setCardsUp(true);
}

void LevelManagerComponent::enemiesSpawn()
{
	for (int x = EnemyType::GRANADE; x != EnemyType::UNKNOW; x++) {
		if (_levelsInfo.at(_currentRound).enemies.at(x).type == EnemyType::GRANADE)
			_granadePool->wakeUpEnemies(_levelsInfo.at(_currentRound).enemies.at(x).howManyEnemies, _levelsInfo.at(_currentRound).enemies.at(x).spawnEnemyTime);
		else if (_levelsInfo.at(_currentRound).enemies.at(x).type == EnemyType::LEMON)
			_lemonPool->wakeUpEnemies(_levelsInfo.at(_currentRound).enemies.at(x).howManyEnemies, _levelsInfo.at(_currentRound).enemies.at(x).spawnEnemyTime);
		else if (_levelsInfo.at(_currentRound).enemies.at(x).type == EnemyType::WATERMELON)
			_watermelonPool->wakeUpEnemies(_levelsInfo.at(_currentRound).enemies.at(x).howManyEnemies, _levelsInfo.at(_currentRound).enemies.at(x).spawnEnemyTime);
	}
}

void LevelManagerComponent::startInfiniteRound()
{
	_granadePool->setInfinityRound(true);
	_lemonPool->setInfinityRound(true);
	_watermelonPool->setInfinityRound(true);
}
