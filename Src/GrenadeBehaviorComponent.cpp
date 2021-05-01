#include "GrenadeBehaviorComponent.h"
#include "ParticleSystemComponent.h"
#include "UserComponentIDs.h"
#include "PlayerHealthComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include "Engine.h"
#include "EngineTime.h"
#include "includeLUA.h"

ADD_COMPONENT(GrenadeBehaviorComponent);

GrenadeBehaviorComponent::GrenadeBehaviorComponent() : EnemyBehaviorComponent()
{
}

GrenadeBehaviorComponent::~GrenadeBehaviorComponent()
{
}

void GrenadeBehaviorComponent::awake(luabridge::LuaRef& data)
{
	_range = data["Range"].cast<float>();
	_attackSpeed = data["AttackSpeed"].cast<float>();
	_movementSpeed = data["MovementSpeed"].cast<float>();
}

void GrenadeBehaviorComponent::start()
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_healthPlayer = static_cast<PlayerHealthComponent*>(_gameObject->getComponent(UserComponentId::Health));
}

void GrenadeBehaviorComponent::update()
{
	double distance = (_playerPos->getPosition() - _tr->getPosition()).magnitude();
	//(distance <= _range) ? _isAttacking = true : _isAttacking = false;

	float deltaTime = EngineTime::getInstance()->deltaTime();
	_timeToShoot -= deltaTime;

	if (distance <= _range && _timeToShoot <= 0) {
		attack();
		_timeToShoot = _attackSpeed;
	}
	else {
		walk();
	}
}

void GrenadeBehaviorComponent::walk()
{
	float deltaTime = EngineTime::getInstance()->deltaTime();

	//Get the player position
	Vector3 playerPos = _playerPos->getPosition();
	Vector3 myPos = _tr->getPosition();

	//Move towards the player
	Vector3 dir = playerPos - _tr->getPosition();
	Vector3 newPos = myPos + (dir * _movementSpeed * deltaTime);
	_tr->setPosition(newPos);
}

void GrenadeBehaviorComponent::attack()
{
	//Shoot an enemy bullet
	Vector3 playerPos = _playerPos->getPosition();
	Vector3 dir = playerPos - _tr->getPosition();

	//Get pool of enemy bullets
	//Create a new Bullet
}