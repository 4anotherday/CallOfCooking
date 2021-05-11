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

GrenadeBulletBehaviorComponent::GrenadeBulletBehaviorComponent() : Component(UserComponentId::GrenadeBulletBehaviourComponent), _rigidbody(nullptr), _tr(nullptr)
{
}

GrenadeBulletBehaviorComponent::~GrenadeBulletBehaviorComponent()
{
}

void GrenadeBulletBehaviorComponent::awake(luabridge::LuaRef& data)
{
	_movementSpeed = data["MovementSpeed"].cast<float>();
	_damage = data["Damage"].cast<float>();
}

void GrenadeBulletBehaviorComponent::start()
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rigidbody = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_direction = Vector3(1, 0, 0);
}

void GrenadeBulletBehaviorComponent::update()
{
	Vector3 move = _direction * _movementSpeed;
	_rigidbody->addForce(move);
}

void GrenadeBulletBehaviorComponent::onCollision(GameObject* other)
{
	if (other->getName() == "Jugador") {
		PlayerHealthComponent* vida = static_cast<PlayerHealthComponent*>(other->getComponent(UserComponentId::Health));
		vida->loseLife(1);
		_tr->setPosition(Vector3(-150, -290, 100));
	}
	//Ponerse desactivado en la pool
}

void GrenadeBulletBehaviorComponent::beShot(Vector3 pos, Vector3 dir)
{
	_rigidbody->setLinearVelocity(Vector3(0, 0, 0));
	_rigidbody->setAngularVelocity(Vector3(0, 0, 0));
	Vector3 impulse = (dir * _movementSpeed);
	_rigidbody->addImpulse(impulse);
	_tr->setPosition(pos);
	_direction = dir;
}

void GrenadeBulletBehaviorComponent::deactivate()
{
	_timeToDie = _lifeTime;
	//_pool->setInactiveGO(_gameObject);
}