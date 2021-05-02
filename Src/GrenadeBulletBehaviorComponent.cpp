#include "GrenadeBulletBehaviorComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "Transform.h"
#include "RigidBodyComponent.h"
#include "Engine.h"
#include "includeLUA.h"
#include "EnemyHealthComponent.h"
#include "PlayerHealthComponent.h"

ADD_COMPONENT(GrenadeBulletBehaviorComponent);

GrenadeBulletBehaviorComponent::GrenadeBulletBehaviorComponent() : Component(UserComponentId::PlayerBulletBehaviorComponent), _rigidbody(nullptr), _playerPos(nullptr)
{
}

GrenadeBulletBehaviorComponent::~GrenadeBulletBehaviorComponent()
{
}

void GrenadeBulletBehaviorComponent::awake(luabridge::LuaRef& data)
{
}

void GrenadeBulletBehaviorComponent::start()
{
	_playerPos = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rigidbody = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
}

void GrenadeBulletBehaviorComponent::update()
{
	Vector3 move = _direction * _movementSpeed;
	_rigidbody->moveTo(move);
}

void GrenadeBulletBehaviorComponent::onCollision(GameObject* other)
{
	if (other->getName() == "Player") {
		PlayerHealthComponent* vida = static_cast<PlayerHealthComponent*>(other->getComponent(UserComponentId::Health));
		vida->loseLife(1);
	}
	//Ponerse desactivado en la pool
}