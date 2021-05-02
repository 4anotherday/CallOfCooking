#include "PlayerBulletBehaviorComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "Transform.h"
#include "RigidBodyComponent.h"
#include "Engine.h"
#include "includeLUA.h"
#include "EnemyHealthComponent.h"
#include "EngineTime.h"

ADD_COMPONENT(PlayerBulletBehaviorComponent);

PlayerBulletBehaviorComponent::PlayerBulletBehaviorComponent() : Component(UserComponentId::PlayerBulletBehaviorComponent), _rigidbody(nullptr), _position(nullptr), _damage()
{
}

PlayerBulletBehaviorComponent::~PlayerBulletBehaviorComponent()
{
}

void PlayerBulletBehaviorComponent::awake(luabridge::LuaRef& data)
{
	_movementSpeed = data["MovementSpeed"].cast<float>();
	_damage = data["Damage"].cast<float>();
}

void PlayerBulletBehaviorComponent::start()
{
	_position = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rigidbody = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_direction = Vector3(0, 0, 1);
}

void PlayerBulletBehaviorComponent::update()
{
	float deltaTime = EngineTime::getInstance()->deltaTime();

	Vector3 dir = _direction * _movementSpeed;
	_rigidbody->addForce(dir);
}

void PlayerBulletBehaviorComponent::onCollision(GameObject* other)
{
	//Buscar el componente de vida de enemigo, y en caso de que lo tenga es un enemigo
	EnemyHealthComponent* health = dynamic_cast<EnemyHealthComponent*>(other->getComponent(UserComponentId::EnemyHealthComponent));
	if (health != nullptr) {
		health->reduceHitPoints(_damage);
	}
	//Ponerse desactivado en la pool
}