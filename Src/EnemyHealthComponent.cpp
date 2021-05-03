#include "EnemyHealthComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "ScoreManagerComponent.h"
#include "LevelManagerComponent.h"
#include "Transform.h"
#include "Engine.h"
#include "includeLUA.h"

ADD_COMPONENT(EnemyHealthComponent);

EnemyHealthComponent::EnemyHealthComponent() : Component(UserComponentId::EnemyHealthComponent), _scoreManager(nullptr), _totalLives(), _remainingLives()
{
}

EnemyHealthComponent::~EnemyHealthComponent()
{
}

void EnemyHealthComponent::awake(luabridge::LuaRef& data)
{
	_totalLives = data["Points"].cast<int>();
	_remainingLives = data["HitPoints"].cast<int>();
	_deathComboPoints = data["DeathComboPoints"].cast<int>();
}

void EnemyHealthComponent::start()
{
	_scoreManager = static_cast<ScoreManagerComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::ScoreManagerComponent));
	_lvlManager = static_cast<LevelManagerComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::LevelManagerComponent));
}

void EnemyHealthComponent::reduceLivesPoints(int damage)
{
	_remainingLives -= damage;
	if (_remainingLives <= 0 && _gameObject->getEnabled()) {
		//TBD
		_scoreManager->addComboHitPoint();
		_gameObject->setEnabled(false);   //Esto debería de bastar
		Engine::getInstance()->remGameObject(_gameObject);
	}
	else if(_remainingLives == 0 && _gameObject->getEnabled()) {
		_scoreManager->addComboDeathPoint(_deathComboPoints);
		_lvlManager->enemyDeath(_gameObject, _enemyType, _poolId);
	}
}

void EnemyHealthComponent::restartLives()
{
	_remainingLives = _totalLives;
}
