#include "PlayerBulletBehaviorComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "Transform.h"
#include "RigidBodyComponent.h"
#include "Engine.h"
#include "includeLUA.h"
#include "EnemyHealthComponent.h"

ADD_COMPONENT(PlayerBulletBehaviorComponent);

PlayerBulletBehaviorComponent::PlayerBulletBehaviorComponent() : Component(UserComponentId::PlayerBulletBehaviourComponent), _rigidbody(nullptr), _playerPos(nullptr)
{
}

PlayerBulletBehaviorComponent::~PlayerBulletBehaviorComponent()
{
}

void PlayerBulletBehaviorComponent::awake(luabridge::LuaRef& data)
{
}

void PlayerBulletBehaviorComponent::start()
{
	_playerPos = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rigidbody = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
}

void PlayerBulletBehaviorComponent::update()
{
	Vector3 move = _direction * _movementSpeed;
	_rigidbody->moveTo(move);
}

void PlayerBulletBehaviorComponent::onCollision(GameObject* other)
{
	//Buscar el componente de vida de enemigo, y en caso de que lo tenga es un enemigo
	EnemyHealthComponent* health = dynamic_cast<EnemyHealthComponent*>(other->getComponent(UserComponentId::EnemyHealthComponent));
	if (health != nullptr) {
		health->reduceHitPoints(damage);
	}
	//Ponerse desactivado en la pool
}