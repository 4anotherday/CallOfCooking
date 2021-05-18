#include "PlayerBulletBehaviorComponent.h"
#include "PlayerBulletPoolComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "Transform.h"
#include "RigidBodyComponent.h"
#include "Engine.h"
#include "includeLUA.h"
#include "EnemyHealthComponent.h"
#include "EngineTime.h"
#include "ColliderComponent.h"

ADD_COMPONENT(PlayerBulletBehaviorComponent);

PlayerBulletBehaviorComponent::PlayerBulletBehaviorComponent() : Component(UserComponentId::PlayerBulletBehaviorComponent), _rigidbody(nullptr), _tr(nullptr), _damage(5.0f),
_movementSpeed(3.0f),_lifeTime(0.5f),_timeToDie(0.5f),_collider(nullptr),_pool(nullptr)
{
}

PlayerBulletBehaviorComponent::~PlayerBulletBehaviorComponent()
{
}

void PlayerBulletBehaviorComponent::awake(luabridge::LuaRef& data)
{
	if(LUAFIELDEXIST(MovementSpeed)) _movementSpeed = data["MovementSpeed"].cast<float>();
	if(LUAFIELDEXIST(Damage)) _damage = data["Damage"].cast<float>();
	if(LUAFIELDEXIST(LifeTime)) _lifeTime = data["LifeTime"].cast<float>();
	_timeToDie = _lifeTime;
}

void PlayerBulletBehaviorComponent::start()
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	//_rigidbody = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_collider = static_cast<BoxColliderComponent*>(_gameObject->getComponent(ComponentId::BoxCollider));

	_pool = static_cast<PlayerBulletPoolComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::PlayerBulletPoolComponent));
	_direction = Vector3(0, 0, 1);
}

void PlayerBulletBehaviorComponent::update()
{
	float deltaTime = EngineTime::getInstance()->deltaTime();

	Vector3 dir = _direction * _movementSpeed * deltaTime;
	_tr->setPosition(_tr->getPosition() + dir);
	_timeToDie -= deltaTime;

	if (_timeToDie <= 0) {
		deactivate();
	}
}

void PlayerBulletBehaviorComponent::onTrigger(GameObject* other)
{
	//Find the EnemyHealthComponent
	EnemyHealthComponent* health = dynamic_cast<EnemyHealthComponent*>(other->getComponent(UserComponentId::EnemyHealthComponent));
	if (health != nullptr) {
		health->reduceLivesPoints(_damage);
		std::cout << "OUCH" << std::endl;
	}

	//We deactivate the bullet if it collides with something that is not the player,his attackHitbox ot the ground
	if (other->getName() != "Player" || other->getName() != "PlayerAttackHitBox" || other->getName() != "Suelo")
	{
		deactivate();
	}
	
}

void PlayerBulletBehaviorComponent::beShot(Vector3 pos, Vector3 dir)
{
	//_rigidbody->setLinearVelocity(Vector3(0, 0, 0));
	//_rigidbody->setAngularVelocity(Vector3(0, 0, 0));
	Vector3 impulse = (dir * _movementSpeed);
	//_rigidbody->addImpulse(impulse);
	_tr->setPosition(pos);
	_direction = dir;
}

void PlayerBulletBehaviorComponent::deactivate()
{
	_timeToDie = _lifeTime;
	_pool->setInactiveGO(_gameObject);
}