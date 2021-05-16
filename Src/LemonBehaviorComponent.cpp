#include "LemonBehaviorComponent.h"
#include "ParticleSystemComponent.h"
#include "UserComponentIDs.h"
#include "PlayerHealthComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include "includeLUA.h"
#include "Engine.h"
#include "EngineTime.h"
#include "includeLUA.h"
#include "RigidBodyComponent.h"

ADD_COMPONENT(LemonBehaviorComponent);

LemonBehaviorComponent::LemonBehaviorComponent() : EnemyBehaviorComponent(UserComponentId::LemonBehaviorComponent), _pSystem(nullptr)
{
}

LemonBehaviorComponent::~LemonBehaviorComponent()
{
}

void LemonBehaviorComponent::awake(luabridge::LuaRef& data)
{
	_range = data["Range"].cast<float>();
	_movementSpeed = data["MovementSpeed"].cast<float>();
}

void LemonBehaviorComponent::start()
{
	_pSystem = static_cast<ParticleSystemComponent*>(_gameObject->getComponent(ComponentId::ParticleSystem));
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_healthPlayer = static_cast<PlayerHealthComponent*>(_gameObject->getComponent(UserComponentId::Health));
	_playerPos = static_cast<Transform*>(Engine::getInstance()->findGameObject("Player")->getComponent(ComponentId::Transform));
	_rigidbody = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
}

void LemonBehaviorComponent::update()
{
	double distance = (_playerPos->getPosition() - _tr->getPosition()).magnitude();
	(distance <= _range) ? _isAttacking = true : _isAttacking = false;

	if (distance <= _range) {
		attack();
	}
	else {
		walk();
	}
}

void LemonBehaviorComponent::walk()
{
	float deltaTime = EngineTime::getInstance()->deltaTime();

	//Get the player position
	Vector3 playerPos = _playerPos->getPosition();
	Vector3 myPos = _tr->getPosition();

	//Move towards the player
	Vector3 dir = playerPos - _tr->getPosition();

	//Cinematic
	//Vector3 newPos = myPos + (dir * _movementSpeed * deltaTime);
	//_tr->setPosition(newPos);

	//With Physx
	dir = dir * _movementSpeed;
	_rigidbody->addForce(dir);
}

void LemonBehaviorComponent::attack()
{
	if (_pSystem)_pSystem->setEnabled(true);
	_healthPlayer->loseLife(_damagePerSecond);
}