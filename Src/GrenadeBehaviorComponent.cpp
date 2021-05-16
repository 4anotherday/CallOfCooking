#include "GrenadeBehaviorComponent.h"
#include "ParticleSystemComponent.h"
#include "UserComponentIDs.h"
#include "PlayerHealthComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include "Engine.h"
#include "EngineTime.h"
#include "includeLUA.h"
#include "GranadeBulletPoolComponent.h"
#include "GrenadeBulletBehaviorComponent.h"
#include "RigidBodyComponent.h"

ADD_COMPONENT(GrenadeBehaviorComponent);

GrenadeBehaviorComponent::GrenadeBehaviorComponent() : EnemyBehaviorComponent(UserComponentId::GrenadeBehaviorComponent)
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
	_healthPlayer = static_cast<PlayerHealthComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::Health));
	_playerPos = static_cast<Transform*>(Engine::getInstance()->findGameObject("Player")->getComponent(ComponentId::Transform));
	_rigidbody = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));

	_gameManager = Engine::getInstance()->findGameObject("GameManager");
	_bulletsManager = static_cast<GranadeBulletPoolComponent*>(_gameManager->getComponent(UserComponentId::GranadeBulletPoolComponent));
}

void GrenadeBehaviorComponent::update()
{
	double distance = (_playerPos->getPosition() - _tr->getPosition()).magnitude();
	//(distance <= _range) ? _isAttacking = true : _isAttacking = false;

	float deltaTime = EngineTime::getInstance()->deltaTime();
	_timeToShoot -= deltaTime;

	if (distance <= _range) {
		if (_timeToShoot <= 0) {
			attack();
			_timeToShoot = _attackSpeed;
		}
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

	//Cinematic
	//Vector3 newPos = myPos + (dir * _movementSpeed * deltaTime);
	//_tr->setPosition(newPos);

	//With Physx
	dir = dir * _movementSpeed;
	_rigidbody->setLinearVelocity(dir);
}

void GrenadeBehaviorComponent::attack()
{
	//Shoot an enemy bullet
	Vector3 playerPos = _playerPos->getPosition();
	Vector3 dir = playerPos - _tr->getPosition();
	dir = dir.normalize();
	_rigidbody->setLinearVelocity(Vector3(0, 0, 0));

	GameObject* newBullet = _bulletsManager->getInactiveGO();
	if (newBullet != nullptr) {
		GrenadeBulletBehaviorComponent* c = static_cast<GrenadeBulletBehaviorComponent*>(newBullet->getComponent(UserComponentId::GrenadeBulletBehaviourComponent));
		Vector3 myPos = _tr->getPosition();
		Vector3 bulletPos = myPos + (dir * 4);
		c->beShot(bulletPos, dir);
	}
}