#include "GrenadeBulletBehaviorComponent.h"
#include "GranadeBulletPoolComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "Transform.h"
#include "RigidBodyComponent.h"
#include "Engine.h"
#include "EngineTime.h"
#include "includeLUA.h"
#include "EnemyHealthComponent.h"
#include "PlayerHealthComponent.h"
#include "ColliderComponent.h"
#include "Exceptions.h"

ADD_COMPONENT(GrenadeBulletBehaviorComponent);

GrenadeBulletBehaviorComponent::GrenadeBulletBehaviorComponent() : Component(UserComponentId::GrenadeBulletBehaviourComponent), _rigidbody(nullptr), _tr(nullptr), _movementSpeed(3.0f),
_lifeTime(0.5f), _damage(1.0f),_timeToDie(0.5f),_myCollider(nullptr),_pool(nullptr)
{
}

GrenadeBulletBehaviorComponent::~GrenadeBulletBehaviorComponent()
{
}

void GrenadeBulletBehaviorComponent::awake(luabridge::LuaRef& data)
{
	if(LUAFIELDEXIST(MovementSpeed)) _movementSpeed = data["MovementSpeed"].cast<float>();
	if(LUAFIELDEXIST(Damage)) _damage = data["Damage"].cast<float>();
	if(LUAFIELDEXIST(LifeTime)) _lifeTime = data["LifeTime"].cast<float>();
	_timeToDie = _lifeTime;
}

void GrenadeBulletBehaviorComponent::start()
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	//_rigidbody = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_myCollider = static_cast<BoxColliderComponent*>(_gameObject->getComponent(ComponentId::BoxCollider));
	_direction = Vector3(1, 0, 0);
	_pool = static_cast<GranadeBulletPoolComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::GranadeBulletPoolComponent));
}

void GrenadeBulletBehaviorComponent::update()
{
	float deltaTime = EngineTime::getInstance()->deltaTime();
	Vector3 move = _direction * _movementSpeed * deltaTime;
	_tr->setPosition(_tr->getPosition() + move);

	_timeToDie -= deltaTime;
	if (_timeToDie <= 0) {
		deactivate();
	}
}

void GrenadeBulletBehaviorComponent::onTrigger(GameObject* other)
{
	if (other->getName() == "Player") {
		PlayerHealthComponent* playerHealth = static_cast<PlayerHealthComponent*>(other->getComponent(UserComponentId::PlayerHealthComponent));
		playerHealth->loseLife(_damage);
	}
	
	//Enemy bullet avoids collision with other enemies
	EnemyHealthComponent* enemyHealth = static_cast<EnemyHealthComponent*>(other->getComponent(UserComponentId::EnemyHealthComponent));	
	if (enemyHealth != nullptr)
	{
		EnemyType type = enemyHealth->getEnemyType();

		if (type != EnemyType::LEMON && type != EnemyType::WATERMELON && type != EnemyType::GRANADE)
		{
			deactivate();
		}
	}
	else
	{	
		//Enemy bullet deactivates if collides with something else
		deactivate();
	}
}

void GrenadeBulletBehaviorComponent::beShot(Vector3 pos, Vector3 dir)
{
	//_rigidbody->setLinearVelocity(Vector3(0, 0, 0));
	//_rigidbody->setAngularVelocity(Vector3(0, 0, 0));
	Vector3 impulse = (dir * _movementSpeed);
	//_rigidbody->addImpulse(impulse);
	_tr->setPosition(pos);
	_direction = dir;
}

void GrenadeBulletBehaviorComponent::deactivate()
{
	_timeToDie = _lifeTime;
	_pool->setInactiveGO(_gameObject);
}