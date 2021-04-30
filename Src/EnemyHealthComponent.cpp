#include "EnemyHealthComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "ScoreManagerComponent.h"
#include "Transform.h"
#include "Engine.h"
#include "includeLUA.h"



EnemyHealthComponent::EnemyHealthComponent() : Component(UserComponentId::EnemyHealthComponent), _scoreManager(nullptr), _points(), _hitPoints()
{
}

EnemyHealthComponent::~EnemyHealthComponent()
{
}

void EnemyHealthComponent::awake(luabridge::LuaRef& data)
{
	_points = data["Points"].cast<int>();
	_hitPoints = data["HitPoints"].cast<int>();
	//_deathComboPoints = data["DeathComboPoints"].cast<int>();
}

void EnemyHealthComponent::start()
{
	_scoreManager = static_cast<ScoreManagerComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::ScoreManagerComponent));
}

void EnemyHealthComponent::reduceHitPoints(int damage)
{
	_hitPoints-= damage;
	if (_hitPoints <= 0 && _gameObject->getEnabled()) {
		//TBD
		_scoreManager->addScore(_points);
		_gameObject->setEnabled(false);
	}
}
