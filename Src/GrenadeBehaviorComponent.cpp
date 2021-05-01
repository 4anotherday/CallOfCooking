#include "GrenadeBehaviorComponent.h"
#include "ParticleSystemComponent.h"
#include "UserComponentIDs.h"
#include "PlayerHealthComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include "Engine.h"
#include "EngineTime.h"
#include "includeLUA.h"

GrenadeBehaviorComponent::GrenadeBehaviorComponent() : EnemyBehaviorComponent(), _range(), _cadence(), _movementSpeed()
{
}

GrenadeBehaviorComponent::~GrenadeBehaviorComponent()
{
}

void GrenadeBehaviorComponent::awake(luabridge::LuaRef& data)
{
	_range = data["Range"].cast<float>();
	_cadence = data["Cadence"].cast<float>();
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

	if (distance <= _range /* && cadence...*/)
		attack();
	else
		walk();
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
	//_lastShot = EngineTime::getInstance()->getDate  Get TimeStamp of the last time a shot was made
	//Shoot an enemy bullet
	Vector3 playerPos = _playerPos->getPosition();
	Vector3 dir = playerPos - _tr->getPosition();
}