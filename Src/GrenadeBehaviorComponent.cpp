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
#include "EnemyHealthComponent.h"

ADD_COMPONENT(GrenadeBehaviorComponent);

GrenadeBehaviorComponent::GrenadeBehaviorComponent() : EnemyBehaviorComponent(UserComponentId::GrenadeBehaviorComponent),_timeToShoot(0.0f),_bulletsManager(nullptr),
_gameManager(nullptr),_healthPlayer(nullptr),_myHealth(nullptr),_tr(nullptr)
{
}

GrenadeBehaviorComponent::~GrenadeBehaviorComponent()
{
}

void GrenadeBehaviorComponent::awake(luabridge::LuaRef& data)
{
	if(LUAFIELDEXIST(Range)) _range = data["Range"].cast<float>();
	if (LUAFIELDEXIST(AttackSpeed)) _attackSpeed = data["AttackSpeed"].cast<float>();
	if (LUAFIELDEXIST(MovementSpeed)) _movementSpeed = data["MovementSpeed"].cast<float>();
}

void GrenadeBehaviorComponent::start()
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_healthPlayer = static_cast<PlayerHealthComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::PlayerHealthComponent));
	_playerPos = static_cast<Transform*>(Engine::getInstance()->findGameObject("Player")->getComponent(ComponentId::Transform));
	_rigidbody = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));

	_gameManager = Engine::getInstance()->findGameObject("GameManager");
	_bulletsManager = static_cast<GranadeBulletPoolComponent*>(_gameManager->getComponent(UserComponentId::GranadeBulletPoolComponent));
	_myHealth = static_cast<EnemyHealthComponent*>(_gameObject->getComponent(UserComponentId::EnemyHealthComponent));
	_myHealth->setMyEnemyType(0);
}

void GrenadeBehaviorComponent::update()
{
	double distance = (_playerPos->getPosition() - _tr->getPosition()).magnitude();
	//(distance <= _range) ? _isAttacking = true : _isAttacking = false;

	_timeToShoot -= EngineTime::getInstance()->deltaTime();

	//Rotation to face the player
	Vector3 dir1 = Vector3(_playerPos->getPosition().getX()-_tr->getPosition().getX(), 0.0f, _playerPos->getPosition().getZ()-_tr->getPosition().getZ());
	float angle = -atan2(dir1.getZ(), dir1.getX()) * 180.0f;
	_tr->setRotation(Vector3(0.0f, angle , 0.0f) * 0.005f);

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
	Vector3 newPos = myPos + (dir * _movementSpeed * deltaTime);
	_tr->setPosition(newPos);

	//With Physx
	//dir = dir * _movementSpeed;
	//_rigidbody->setLinearVelocity(dir);
}

void GrenadeBehaviorComponent::attack()
{
	//Shoot an enemy bullet
	Vector3 playerPos = _playerPos->getPosition();
	Vector3 dir = playerPos - _tr->getPosition();

	dir = dir.normalize();

	GameObject* newBullet = _bulletsManager->getInactiveGO();
	if (newBullet != nullptr) {
		GrenadeBulletBehaviorComponent* c = static_cast<GrenadeBulletBehaviorComponent*>(newBullet->getComponent(UserComponentId::GrenadeBulletBehaviourComponent));
		Vector3 myPos = _tr->getPosition();
		Vector3 bulletPos = myPos + (dir * 0.25f);
		c->beShot(bulletPos, dir);
	}
}