#include "LemonBehaviorComponent.h"
#include "ParticleSystemComponent.h"
#include "UserComponentIDs.h"
#include "PlayerHealthComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include "includeLUA.h"
#include "Engine.h"
#include "EngineTime.h"
#include "RigidBodyComponent.h"
#include "LemonPoolComponent.h"
#include "EnemyHealthComponent.h"
#include "Exceptions.h"

ADD_COMPONENT(LemonBehaviorComponent);

LemonBehaviorComponent::LemonBehaviorComponent() : EnemyBehaviorComponent(UserComponentId::LemonBehaviorComponent), _pSystem(nullptr),
_healthPlayer(nullptr),_myHealth(nullptr),_tr(nullptr),_lastAttack(0.0f),_attackRate(1.0f)
{
}

LemonBehaviorComponent::~LemonBehaviorComponent()
{
}

void LemonBehaviorComponent::awake(luabridge::LuaRef& data)
{
	if (LUAFIELDEXIST(Range))
		_range = data["Range"].cast<float>();
	if (LUAFIELDEXIST(MovementSpeed))
		_movementSpeed = data["MovementSpeed"].cast<float>();
	if(LUAFIELDEXIST(AttackRate))
		_attackRate = data["AttackRate"].cast<float>();
}

void LemonBehaviorComponent::start()
{
	_pSystem = static_cast<ParticleSystemComponent*>(_gameObject->getComponent(ComponentId::ParticleSystem));
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_healthPlayer = static_cast<PlayerHealthComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::PlayerHealthComponent));
	_playerPos = static_cast<Transform*>(Engine::getInstance()->findGameObject("Player")->getComponent(ComponentId::Transform));
	_rigidbody = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_myHealth = static_cast<EnemyHealthComponent*>(_gameObject->getComponent(UserComponentId::EnemyHealthComponent));
	_myHealth->setMyEnemyType(1);

}

void LemonBehaviorComponent::update()
{
	double distance = (_playerPos->getPosition() - _tr->getPosition()).magnitude();
	(distance <= _range) ? _isAttacking = true : _isAttacking = false;

	//Rotation to face the player
	Vector3 dir1 = Vector3(_playerPos->getPosition().getX() - _tr->getPosition().getX(), 0.0f, _playerPos->getPosition().getZ() - _tr->getPosition().getZ());
	float angle = -atan2(dir1.getZ(), dir1.getX()) * 180.0f;
	_tr->setRotation(Vector3(0.0f, angle+360, 0.0f) * 0.005f);

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
	Vector3 newPos = myPos + (dir * _movementSpeed * deltaTime);
	_tr->setPosition(newPos);

	////With Physx
	//dir = dir * _movementSpeed;
	//_rigidbody->setLinearVelocity(dir);
}

void LemonBehaviorComponent::attack()
{
	float deltaTime = EngineTime::getInstance()->deltaTime();

	_lastAttack -= deltaTime;
	if (_lastAttack <= 0)
	{
		if (_pSystem)_pSystem->setEnabled(true);
		_healthPlayer->loseLife(_damagePerSecond);
		_lastAttack = _attackRate;
	}
	
}