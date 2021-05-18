#include "WatermelonBehaviorComponent.h"
#include "ParticleSystemComponent.h"
#include "UserComponentIDs.h"
#include "PlayerHealthComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include "includeLUA.h"
#include "Engine.h"
#include "includeLUA.h"
#include "RigidBodyComponent.h"
#include "EngineTime.h"
#include "WatermelonPoolComponent.h"
#include "EnemyHealthComponent.h"

ADD_COMPONENT(WatermelonBehaviorComponent);

WatermelonBehaviorComponent::WatermelonBehaviorComponent() : EnemyBehaviorComponent(UserComponentId::WatermelonBehaviorComponent), 
_pSystem(nullptr), _tr(nullptr), _healthPlayer(nullptr), _myHealth(nullptr), _timeToExplode(0.0f), _exploding(false), _explosionCountDown(0.0f)
{
}

WatermelonBehaviorComponent::~WatermelonBehaviorComponent()
{
}

void WatermelonBehaviorComponent::awake(luabridge::LuaRef& data)
{
	_range = data["Range"].cast<float>();
	_movementSpeed = data["MovementSpeed"].cast<float>();
	_explosionCountDown = _timeToExplode = data["TimeToExplode"].cast<float>(); 
}

void WatermelonBehaviorComponent::start()
{
	_playerPos = static_cast<Transform*>(Engine::getInstance()->findGameObject("Player")->getComponent(ComponentId::Transform));
	_pSystem = static_cast<ParticleSystemComponent*>(_gameObject->getComponent(ComponentId::ParticleSystem));
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_healthPlayer = static_cast<PlayerHealthComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::Health));
	_rigidbody = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_myHealth = static_cast<EnemyHealthComponent*>(_gameObject->getComponent(UserComponentId::EnemyHealthComponent));
	_myHealth->setMyEnemyType(2);
}

void WatermelonBehaviorComponent::update()
{
	double distance = (_playerPos->getPosition() - _tr->getPosition()).magnitude();

	//If player is far go for him, if not start exploding
	if (!_exploding) {
		if (_range <= distance) {
			walk();
		}
		else {
			if (_pSystem != nullptr)_pSystem->setEnabled(true);
			_exploding = true;
		}
	}
	else {
		_explosionCountDown -= EngineTime::getInstance()->deltaTime();;
		if (_explosionCountDown <= 0) {	
			//If player is reachable damage him
			if (distance <= _range) {
				_healthPlayer->loseLife(_damagePerSecond);
			}

			//Die or something like that
			resetBehavior();
			if (_pSystem != nullptr)_pSystem->setEnabled(false);
			_myHealth->reduceLivesPoints(_myHealth->getLives());
		}
	}
}

void WatermelonBehaviorComponent::walk()
{
	float deltaTime = EngineTime::getInstance()->deltaTime();

	//Get the player position
	Vector3 playerPos = _playerPos->getPosition();
	Vector3 myPos = _tr->getPosition();

	//Move towards the player
	Vector3 dir = playerPos - _tr->getPosition();

	//Cinematic
	Vector3 newPos = myPos + (dir * _movementSpeed * deltaTime);
	_tr->setPosition(newPos);

	//With Physx
	//dir = dir * _movementSpeed;
	//_rigidbody->setLinearVelocity(dir);
	//if (_pSystem != nullptr)_pSystem->setEnabled(false);
}

void WatermelonBehaviorComponent::resetBehavior()
{
	_exploding = false;
	_explosionCountDown = _timeToExplode;
}
