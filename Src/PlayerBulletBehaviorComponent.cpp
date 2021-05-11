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

ADD_COMPONENT(PlayerBulletBehaviorComponent);

PlayerBulletBehaviorComponent::PlayerBulletBehaviorComponent() : Component(UserComponentId::PlayerBulletBehaviorComponent), _rigidbody(nullptr), _tr(nullptr), _damage()
{
}

PlayerBulletBehaviorComponent::~PlayerBulletBehaviorComponent()
{
}

void PlayerBulletBehaviorComponent::awake(luabridge::LuaRef& data)
{
	_movementSpeed = data["MovementSpeed"].cast<float>();
	_damage = data["Damage"].cast<float>();
	_lifeTime = data["LifeTime"].cast<float>();
	_timeToDie = _lifeTime;
}

void PlayerBulletBehaviorComponent::start()
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rigidbody = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_pool = static_cast<PlayerBulletPoolComponent*>(Engine::getInstance()->findGameObject("Jugador")->getComponent(UserComponentId::PlayerBulletPoolComponent));
	_direction = Vector3(0, 0, 1);
}

void PlayerBulletBehaviorComponent::update()
{
	float deltaTime = EngineTime::getInstance()->deltaTime();

	Vector3 dir = _direction * _movementSpeed;
	_rigidbody->addForce(dir);
	_timeToDie -= deltaTime;

	if (_timeToDie <= 0) {
		deactivate();
	}
}

void PlayerBulletBehaviorComponent::onCollision(GameObject* other)
{
	//Buscar el componente de vida de enemigo, y en caso de que lo tenga es un enemigo
	EnemyHealthComponent* health = dynamic_cast<EnemyHealthComponent*>(other->getComponent(UserComponentId::EnemyHealthComponent));
	if (health != nullptr) {
		health->reduceLivesPoints(_damage);
		deactivate();
	}
}

void PlayerBulletBehaviorComponent::beShot(Vector3 pos, Vector3 dir)
{
	_rigidbody->setLinearVelocity(Vector3(0, 0, 0));
	_rigidbody->setAngularVelocity(Vector3(0, 0, 0));
	Vector3 impulse = (dir * _movementSpeed);
	_rigidbody->addImpulse(impulse);
	_tr->setPosition(pos);
	_direction = dir;
}

void PlayerBulletBehaviorComponent::deactivate()
{
	_timeToDie = _lifeTime;
	_pool->setInactiveGO(_gameObject);
}