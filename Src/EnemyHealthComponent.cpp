#include "EnemyHealthComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "ScoreManagerComponent.h"
#include "Transform.h"
#include "Engine.h"
#include "includeLUA.h"

ADD_COMPONENT(EnemyHealthComponent);

EnemyHealthComponent::EnemyHealthComponent() : Component(UserComponentId::EnemyHealthComponent),
_scoreManager(nullptr),_lvlManager(nullptr), _enemyType(EnemyType::UNKNOW), _totalLives(0), _remainingLives(0), _deathComboPoints(0)
{
}

EnemyHealthComponent::~EnemyHealthComponent()
{
}

void EnemyHealthComponent::awake(luabridge::LuaRef& data)
{
	_deathComboPoints = _totalLives = data["Points"].cast<int>();
	_remainingLives = data["HitPoints"].cast<int>();
}

void EnemyHealthComponent::start()
{
	//_scoreManager = static_cast<ScoreManagerComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::ScoreManagerComponent));
	//_lvlManager = static_cast<LevelManagerComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::LevelManagerComponent));
}

void EnemyHealthComponent::reduceLivesPoints(int damage)
{
	_remainingLives -= damage;
	_scoreManager->addComboHitPoint();

	if (_remainingLives <= 0 && _gameObject->getEnabled()) {
		_scoreManager->addComboDeathPoint(_deathComboPoints);
		_lvlManager->enemyDeath(_gameObject, _enemyType);

		//Lives are reset so they are ready when the enemy reactivates
		restartLives(); 
	}
}

void EnemyHealthComponent::restartLives()
{
	_remainingLives = _totalLives;
}
